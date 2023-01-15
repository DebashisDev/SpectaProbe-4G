/*
 * S1APSessionManager.cpp
 *
 *  Created on: 7 Jan 2020
 *      Author: Debashis
 */

#include "S1APInterface.h"

uint32_t 		S1APInterface::freeBitPos = 0;
uint32_t 		S1APInterface::freeBitPosMax = 0;

uint16_t 		S1APInterface::instanceId = 0;
BOOL 			S1APInterface::flushFlag = false;
char 			S1APInterface::old_tmsi[10];
uint32_t 		S1APInterface::old_eNodeBId;
sessionGlbData 	S1APInterface::pGlbData;
uint32_t		S1APInterface::sessionCleanCounter;
uint32_t 		S1APInterface::sessionCounter;

std::bitset<S1AP_POOL_ARRAY_ELEMENTS> S1APInterface::bitFlagsSession[S1AP_POOL_ARRAY_SIZE];
std::map<int, s1mmeSession*> S1APInterface::sessionPoolMap[S1AP_POOL_ARRAY_SIZE];
std::map<uint32_t, int> S1APInterface::eNodeBMap[S1AP_POOL_ARRAY_ELEMENTS];

S1APInterface::S1APInterface(uint32_t sessionId)
{
	this->_name = "S1APInterface";
	this->setLogLevel(Log::theLog().level());
	instanceId = sessionId;
	initializeSessionPool();
}

S1APInterface::~S1APInterface()
{}

VOID S1APInterface::lockS1apMap()
{
	    pthread_mutex_lock(&s1mmeSessionLock::lockCount);
	    while (s1mmeSessionLock::count == 0)
	        pthread_cond_wait(&s1mmeSessionLock::nonzero, &s1mmeSessionLock::lockCount);
	    s1mmeSessionLock::count = s1mmeSessionLock::count - 1;
	    pthread_mutex_unlock(&s1mmeSessionLock::lockCount);
}

VOID S1APInterface::unLockS1apMap()
{
    pthread_mutex_lock(&s1mmeSessionLock::lockCount);
    if (s1mmeSessionLock::count == 0)
        pthread_cond_signal(&s1mmeSessionLock::nonzero);
    s1mmeSessionLock::count = s1mmeSessionLock::count + 1;
    pthread_mutex_unlock(&s1mmeSessionLock::lockCount);
}

/*
 * Local Storage
 */

uint32_t S1APInterface::getFreeIndex()
{
	freeBitPos++;
	if(freeBitPos >= freeBitPosMax) freeBitPos = 0;
	int arrId = freeBitPos / S1AP_POOL_ARRAY_ELEMENTS;
	int bitId = freeBitPos % S1AP_POOL_ARRAY_ELEMENTS;

	while(bitFlagsSession[arrId].test(bitId)){
		freeBitPos++;
		if(freeBitPos >= freeBitPosMax) freeBitPos = 0;
		arrId = freeBitPos / S1AP_POOL_ARRAY_ELEMENTS;
		bitId = freeBitPos % S1AP_POOL_ARRAY_ELEMENTS;
	}
	if(freeBitPos >= freeBitPosMax){
		printf("[%d] getFreeIndex freeBitPos [%d] >= freeBitPosMax [%d]\n",instanceId, freeBitPos, freeBitPosMax);
	}
	bitFlagsSession[arrId].set(bitId);
	return freeBitPos;
}

VOID S1APInterface::releaseIndex(int idx)
{
	int arrId = idx / S1AP_POOL_ARRAY_ELEMENTS;
	int bitId = idx % S1AP_POOL_ARRAY_ELEMENTS;
	sessionPoolMap[arrId][bitId]->reset();
	bitFlagsSession[arrId].reset(bitId);
}

VOID S1APInterface::initializeSessionPool()
{
	freeBitPosMax = S1AP_POOL_ARRAY_ELEMENTS * S1AP_POOL_ARRAY_SIZE;

	printf("IPSMInterface [%02d]	Initializing [%d] S1AP Session Pool... ", instanceId, freeBitPosMax);
	TheLog_nc_v2(Log::Info, name(),"     [%d] Initializing [%d] S1AP Session Pool...", instanceId, freeBitPosMax);

	for(int i = 0; i < S1AP_POOL_ARRAY_SIZE; i++)
	{
		bitFlagsSession[i].reset();

		for(int j = 0; j < S1AP_POOL_ARRAY_ELEMENTS; j++)
			sessionPoolMap[i][j] = new s1mmeSession();
	}
	printf("Completed.\n");
	TheLog_nc_v2(Log::Info, name(),"     [%d] Initializing [%d] S1AP Session Pool Completed.", instanceId, freeBitPosMax);
}

s1mmeSession* S1APInterface::getSessionFromPool(uint32_t idx)
{
	int arrId = idx / S1AP_POOL_ARRAY_ELEMENTS;
	int bitId = idx % S1AP_POOL_ARRAY_ELEMENTS;
	return sessionPoolMap[arrId][bitId];
}

VOID S1APInterface::processPDUType(Sctp *pSctpPacket)
{
	std::map<uint16_t, pduType>::iterator it = S1AP_SMFunctions::pduTypeTable.find(pSctpPacket->s1ap_pduType);

	if(it != S1AP_SMFunctions::pduTypeTable.end())
		it->second(pSctpPacket);
}

VOID S1APInterface::process_InitiatingMsg(Sctp* pSctpPacket)
{
	s1mmeSession *pS1apSession;

	std::map<uint16_t, smFunctions>::iterator it = S1AP_SMFunctions::smInitiatingTable.find(pSctpPacket->s1ap_procCode);

	if(it != S1AP_SMFunctions::smInitiatingTable.end())
		it->second(pS1apSession, pSctpPacket);
}

VOID S1APInterface::process_SuccessfulOutcomeMsg(Sctp* pSctpPacket)
{
	s1mmeSession *pS1apSession;

	std::map<uint16_t, smFunctions>::iterator it = S1AP_SMFunctions::smSuccessfullTable.find(pSctpPacket->s1ap_procCode);

	if(it != S1AP_SMFunctions::smSuccessfullTable.end())
		it->second(pS1apSession, pSctpPacket);
}

VOID S1APInterface::process_UnSuccessfulOutcomeMsg(Sctp* pSctpPacket)
{
	s1mmeSession *pS1apSession;

	std::map<uint16_t, smFunctions>::iterator it = S1AP_SMFunctions::smUnSuccessfullTable.find(pSctpPacket->s1ap_procCode);

	if(it != S1AP_SMFunctions::smUnSuccessfullTable.end())
		it->second(pS1apSession, pSctpPacket);
}

/* ----------------------------------- Initiating Message ----------------------------------- */

VOID S1APInterface::process_initialUEMessage(s1mmeSession *pS1apSession, Sctp* pSctpPacket)
{
	BOOL found = false;

	pS1apSession = get_S1APSession(pSctpPacket, &found, false);

	if(found && pS1apSession->active)
	{
		flushSession(pS1apSession, true);
		pS1apSession = get_S1APSession(pSctpPacket, &found, true);
	}
	else
	{
		pS1apSession = get_S1APSession(pSctpPacket, &found, false);
	}

	if(pS1apSession == NULL) { return; }

	pS1apSession->noOfPackets++;
	process_UserInformation(pS1apSession, pSctpPacket);

	/* Populate Procedure Map for the session */
	procedureData *pData = &pS1apSession->procedureMap[pS1apSession->noOfPackets];

	pData->reset();

	pData->procedureTimeNanoSec = IPGlobal::CURRENT_EPOCH_NANO_SEC;
	pData->pduType 				= pSctpPacket->s1ap_pduType;
	pData->procedureId 			= pSctpPacket->s1ap_procCode;

	if(pSctpPacket->nas_MMM_Present)
	{
		pData->mmmPresent = true;
		checkMMMType(pData, pSctpPacket->nas_EPSMobilityMgrMsgType, pSctpPacket->s1ap_eNodeBId);
	}

	if(pSctpPacket->nas_SMM_Present)
	{
		pData->smmPresent = true;
		checkSMMType(pData, pSctpPacket->nas_ESMSessionMgrMsgType, pSctpPacket->s1ap_eNodeBId);
	}

	if(pSctpPacket->nas_ESMMsgContainerMsg_Present)
	{
		pData->smmPresent = true;
		checkSMMType(pData, pSctpPacket->nas_ESMMsgContainerMsgType, pSctpPacket->s1ap_eNodeBId);
	}

	pData->packetDirection 	= 1;
	pData->estCause 		= pSctpPacket->s1ap_estCause;
	strcpy(pData->pLMNIdentity, pSctpPacket->s1ap_pLMNIdentity);
	strcpy(pData->tac, 		   pSctpPacket->s1ap_tac);
	strcpy(pData->cellId, 	   pSctpPacket->s1ap_cellId);

	lockS1apMap();
	updateGlobalData(pSctpPacket);
	unLockS1apMap();
}

VOID S1APInterface::process_InitialContextSetupRequest(s1mmeSession *pS1apSession, Sctp* pSctpPacket)
{
	BOOL found = false;

	pS1apSession = get_S1APSession(pSctpPacket, &found, false);

	if(!found && !pS1apSession->active)
		return;

	pS1apSession->state = STATE_INITIAL_CONTEXT_SETUP;

	if(pS1apSession->mmeId == 0)
		pS1apSession->mmeId  = pSctpPacket->s1ap_mmeId;

	pS1apSession->noOfPackets++;
	process_UserInformation(pS1apSession, pSctpPacket);

	/* Populate Procedure Map for the session */
	procedureData *pData = &pS1apSession->procedureMap[pS1apSession->noOfPackets];

	pData->reset();

	pData->procedureTimeNanoSec = IPGlobal::CURRENT_EPOCH_NANO_SEC;
	pData->pduType 				= pSctpPacket->s1ap_pduType;
	pData->procedureId 			= pSctpPacket->s1ap_procCode;

	if(pSctpPacket->nas_MMM_Present)
	{
		pData->mmmPresent = true;
		checkMMMType(pData, pSctpPacket->nas_EPSMobilityMgrMsgType, pSctpPacket->s1ap_eNodeBId);
	}

	if(pSctpPacket->nas_SMM_Present)
	{
		pData->smmPresent = true;
		checkSMMType(pData, pSctpPacket->nas_ESMSessionMgrMsgType, pSctpPacket->s1ap_eNodeBId);
	}

	if(pSctpPacket->nas_ESMMsgContainerMsg_Present)
	{
		pData->smmPresent = true;
		checkSMMType(pData, pSctpPacket->nas_ESMMsgContainerMsgType, pSctpPacket->s1ap_eNodeBId);
	}

	pData->packetDirection = 2;
	strcpy(pData->gtpTeid, pSctpPacket->s1ap_gTP_TEID);
	strcpy(pData->pdnAddress,  pSctpPacket->s1ap_pdnAddr);
	strcpy(pData->apn, 		  pSctpPacket->s1ap_apn);
	pData->mbrDL = pSctpPacket->s1ap_mbrDL;
	pData->mbrUL = pSctpPacket->s1ap_mbrUL;
	pData->qCI = pSctpPacket->s1ap_qCI;
	pData->apnAmbrUp = pSctpPacket->s1ap_apnMbrUp;
	pData->apnAmbrDn = pSctpPacket->s1ap_apnMbrDown;

	/*
	 * Create the Global session once we get both TMSI and IMSI
	 */

	lockS1apMap();
	if(pData->mmmMap[pSctpPacket->s1ap_eNodeBId].Attach_Accept && pS1apSession->imsi_present && pS1apSession->tmsi_present)
	{	createGlobalData(pS1apSession); }
	else
	{	updateGlobalData(pSctpPacket); }
	unLockS1apMap();
}

VOID S1APInterface::process_handOverRequired(s1mmeSession *pS1apSession, Sctp* pSctpPacket)
{
	BOOL found = false;
	pS1apSession = get_S1APSession(pSctpPacket, &found, false);

	if(!found && !pS1apSession->active)
		return;

	if(pS1apSession->mmeId == 0)
		pS1apSession->mmeId  = pSctpPacket->s1ap_mmeId;

	pS1apSession->state = STATE_HANDOVER_PREPARATION;

	pS1apSession->noOfPackets++;

	/* Populate Procedure Map for the session */
	procedureData *pData = &pS1apSession->procedureMap[pS1apSession->noOfPackets];

	pData->reset();

	pData->procedureTimeNanoSec = IPGlobal::CURRENT_EPOCH_NANO_SEC;
	pData->pduType 				= pSctpPacket->s1ap_pduType;
	pData->procedureId 			= pSctpPacket->s1ap_procCode;

	pData->packetDirection 		= 1;
	pData->handoverType 		= pSctpPacket->s1ap_handoverType;
	pData->HandoverCauseId 		= pSctpPacket->s1ap_causeId;
	strcpy(pData->targetPLMNIdentity, pSctpPacket->s1ap_targetpLMNIdentity);
	strcpy(pData->targetCellId, pSctpPacket->s1ap_targetCellId);
	strcpy(pData->lastVisitedPLMNIdentity, pSctpPacket->s1ap_lastVisitedpLMNIdentity);
	strcpy(pData->lastVisitedCellId, pSctpPacket->s1ap_lastVisitedCellId);
}

VOID S1APInterface::process_handOverRequest(s1mmeSession *pS1apSession, Sctp* pSctpPacket)
{
	BOOL found = false;
	pS1apSession = get_S1APSession(pSctpPacket, &found, false);

	if(!found && !pS1apSession->active)
		return;

	if(pS1apSession->mmeId == 0)
		pS1apSession->mmeId  = pSctpPacket->s1ap_mmeId;

	pS1apSession->state = STATE_HANDOVER_RESOURCE_ALLOC;

	pS1apSession->noOfPackets++;

	/* Populate Procedure Map for the session */
	procedureData *pData = &pS1apSession->procedureMap[pS1apSession->noOfPackets];

	pData->reset();

	pData->procedureTimeNanoSec = IPGlobal::CURRENT_EPOCH_NANO_SEC;
	pData->pduType 				= pSctpPacket->s1ap_pduType;
	pData->procedureId 			= pSctpPacket->s1ap_procCode;

	pData->packetDirection 		= 2;
	pData->handoverType 		= pSctpPacket->s1ap_handoverType;
	pData->HandoverCauseId 		= pSctpPacket->s1ap_causeId;
}

VOID S1APInterface::process_handOverNotify(s1mmeSession *pS1apSession, Sctp* pSctpPacket)
{
	BOOL found = false;
	pS1apSession = get_S1APSession(pSctpPacket, &found, false);

	if(!found && !pS1apSession->active)
		return;

	if(pS1apSession->mmeId == 0)
		pS1apSession->mmeId  = pSctpPacket->s1ap_mmeId;

	pS1apSession->noOfPackets++;

	/* Populate Procedure Map for the session */
	procedureData *pData = &pS1apSession->procedureMap[pS1apSession->noOfPackets];

	pData->reset();

	pData->procedureTimeNanoSec = IPGlobal::CURRENT_EPOCH_NANO_SEC;
	pData->pduType 				= pSctpPacket->s1ap_pduType;
	pData->procedureId 			= pSctpPacket->s1ap_procCode;

	pData->packetDirection 		= 1;
	strcpy(pData->pLMNIdentity, pSctpPacket->s1ap_pLMNIdentity);
	strcpy(pData->cellId, 	   pSctpPacket->s1ap_cellId);
	strcpy(pData->tac, 		   pSctpPacket->s1ap_tac);
}

VOID S1APInterface::process_handOverCancel(s1mmeSession *pS1apSession, Sctp* pSctpPacket)
{
	BOOL found = false;
	pS1apSession = get_S1APSession(pSctpPacket, &found, false);

	if(!found && !pS1apSession->active)
		return;

	if(pS1apSession->mmeId == 0)
		pS1apSession->mmeId  = pSctpPacket->s1ap_mmeId;

	pS1apSession->noOfPackets++;

	/* Populate Procedure Map for the session */
	procedureData *pData = &pS1apSession->procedureMap[pS1apSession->noOfPackets];

	pData->reset();

	pData->procedureTimeNanoSec = IPGlobal::CURRENT_EPOCH_NANO_SEC;
	pData->pduType 				= pSctpPacket->s1ap_pduType;
	pData->procedureId 			= pSctpPacket->s1ap_procCode;

	pS1apSession->state = STATE_HANDOVER_CANCELLATION;

	pData->packetDirection 		= 1;
	pData->HandoverCauseId 		= pSctpPacket->s1ap_causeId;
}

VOID S1APInterface::process_upLinkNASTransport(s1mmeSession *pS1apSession, Sctp* pSctpPacket)
{
	BOOL found = false;
	pS1apSession = get_S1APSession(pSctpPacket, &found, false);

	if(!found && !pS1apSession->active)
		return;

	if(pS1apSession->mmeId == 0)
		pS1apSession->mmeId  = pSctpPacket->s1ap_mmeId;

	pS1apSession->noOfPackets++;
	process_UserInformation(pS1apSession, pSctpPacket);

	/* Populate Procedure Map for the session */
	procedureData *pData = &pS1apSession->procedureMap[pS1apSession->noOfPackets];

	pData->reset();

	pData->procedureTimeNanoSec = IPGlobal::CURRENT_EPOCH_NANO_SEC;
	pData->pduType 				= pSctpPacket->s1ap_pduType;
	pData->procedureId 			= pSctpPacket->s1ap_procCode;

	if(pSctpPacket->nas_MMM_Present)
	{
		pData->mmmPresent = true;
		checkMMMType(pData, pSctpPacket->nas_EPSMobilityMgrMsgType, pSctpPacket->s1ap_eNodeBId);
	}

	if(pSctpPacket->nas_SMM_Present)
	{
		pData->smmPresent = true;
		checkSMMType(pData, pSctpPacket->nas_ESMSessionMgrMsgType, pSctpPacket->s1ap_eNodeBId);
	}

	if(pSctpPacket->nas_ESMMsgContainerMsg_Present)
	{
		pData->smmPresent = true;
		checkSMMType(pData, pSctpPacket->nas_ESMMsgContainerMsgType, pSctpPacket->s1ap_eNodeBId);
	}

	pData->packetDirection 	= 1;
	strcpy(pData->pLMNIdentity, pSctpPacket->s1ap_pLMNIdentity);
	strcpy(pData->tac, 		   pSctpPacket->s1ap_tac);
	strcpy(pData->cellId, 	   pSctpPacket->s1ap_cellId);
}

VOID S1APInterface::process_downLinkNASTransport(s1mmeSession *pS1apSession, Sctp* pSctpPacket)
{
	BOOL found = false;
	pS1apSession = get_S1APSession(pSctpPacket, &found, false);

	if(!found && !pS1apSession->active)
		return;

	if(pS1apSession->mmeId == 0)
		pS1apSession->mmeId  = pSctpPacket->s1ap_mmeId;

	pS1apSession->noOfPackets++;

	/* Populate Procedure Map for the session */
	procedureData *pData = &pS1apSession->procedureMap[pS1apSession->noOfPackets];

	pData->reset();

	pData->procedureTimeNanoSec = IPGlobal::CURRENT_EPOCH_NANO_SEC;
	pData->pduType 				= pSctpPacket->s1ap_pduType;
	pData->procedureId 			= pSctpPacket->s1ap_procCode;

	if(pSctpPacket->nas_MMM_Present)
	{
		pData->mmmPresent = true;
		checkMMMType(pData, pSctpPacket->nas_EPSMobilityMgrMsgType, pSctpPacket->s1ap_eNodeBId);
	}

	if(pSctpPacket->nas_SMM_Present)
	{
		pData->smmPresent = true;
		checkSMMType(pData, pSctpPacket->nas_ESMSessionMgrMsgType, pSctpPacket->s1ap_eNodeBId);
	}

	if(pSctpPacket->nas_ESMMsgContainerMsg_Present)
	{
		pData->smmPresent = true;
		checkSMMType(pData, pSctpPacket->nas_ESMMsgContainerMsgType, pSctpPacket->s1ap_eNodeBId);
	}
	pData->packetDirection 	= 2;
}

VOID S1APInterface::process_contextReleaseRequest(s1mmeSession *pS1apSession, Sctp* pSctpPacket)
{
	BOOL found = false;
	pS1apSession = get_S1APSession(pSctpPacket, &found, false);

	if(!found && !pS1apSession->active)
		return;

	if(pS1apSession->mmeId == 0)
		pS1apSession->mmeId  = pSctpPacket->s1ap_mmeId;

	pS1apSession->noOfPackets++;

	/* Populate Procedure Map for the session */
	procedureData *pData = &pS1apSession->procedureMap[pS1apSession->noOfPackets];

	pData->reset();

	pData->procedureTimeNanoSec = IPGlobal::CURRENT_EPOCH_NANO_SEC;
	pData->pduType 				= pSctpPacket->s1ap_pduType;
	pData->procedureId 			= pSctpPacket->s1ap_procCode;

	pData->packetDirection 		= 1;
	pData->releaseCauseId 		= pSctpPacket->s1ap_causeId;


}

VOID S1APInterface::process_contextReleaseCommand(s1mmeSession *pS1apSession, Sctp* pSctpPacket)
{
	BOOL found = false;
	pS1apSession = get_S1APSession(pSctpPacket, &found, false);

	if(!found && !pS1apSession->active)
		return;

	if(pS1apSession->mmeId == 0)
		pS1apSession->mmeId  = pSctpPacket->s1ap_mmeId;

	pS1apSession->noOfPackets++;

	pS1apSession->state = STATE_UE_CONTEXT_RELEASE;

	/* Populate Procedure Map for the session */
	procedureData *pData = &pS1apSession->procedureMap[pS1apSession->noOfPackets];

	pData->reset();

	pData->procedureTimeNanoSec = IPGlobal::CURRENT_EPOCH_NANO_SEC;
	pData->pduType 				= pSctpPacket->s1ap_pduType;
	pData->procedureId 			= pSctpPacket->s1ap_procCode;

	pData->packetDirection 		= 2;
	pData->releaseCauseId 		= pSctpPacket->s1ap_causeId;
}


/* ----------------------------------- SuccessfulOutcome Message ----------------------------------- */

VOID S1APInterface::process_initialContextSetupResponse(s1mmeSession *pS1apSession, Sctp* pSctpPacket)
{
	BOOL found = false;

	pS1apSession = get_S1APSession(pSctpPacket, &found, false);

	if(!found && !pS1apSession->active)
		return;

	if(pS1apSession->state == STATE_INITIAL_CONTEXT_SETUP)
	{
		if(pS1apSession->mmeId == 0)
			pS1apSession->mmeId  = pSctpPacket->s1ap_mmeId;

		pS1apSession->noOfPackets++;

		/* Populate Procedure Map for the session */
		procedureData *pData = &pS1apSession->procedureMap[pS1apSession->noOfPackets];

		pData->reset();

		pData->procedureTimeNanoSec = IPGlobal::CURRENT_EPOCH_NANO_SEC;
		pData->pduType 				= pSctpPacket->s1ap_pduType;
		pData->procedureId 			= pSctpPacket->s1ap_procCode;

		pData->packetDirection = 1;
		strcpy(pData->gtpTeid, pSctpPacket->s1ap_gTP_TEID);
	}
}

VOID S1APInterface::process_handOverCommand(s1mmeSession *pS1apSession, Sctp* pSctpPacket)
{
	BOOL found = false;

	pS1apSession = get_S1APSession(pSctpPacket, &found, false);

	if(!found && !pS1apSession->active)
		return;

	if(pS1apSession->state == STATE_HANDOVER_PREPARATION)
	{
		if(pS1apSession->mmeId == 0)
			pS1apSession->mmeId  = pSctpPacket->s1ap_mmeId;

		pS1apSession->noOfPackets++;

		/* Populate Procedure Map for the session */
		procedureData *pData = &pS1apSession->procedureMap[pS1apSession->noOfPackets];

		pData->reset();

		pData->procedureTimeNanoSec = IPGlobal::CURRENT_EPOCH_NANO_SEC;
		pData->pduType 				= pSctpPacket->s1ap_pduType;
		pData->procedureId 			= pSctpPacket->s1ap_procCode;

		pData->packetDirection 		= 2;
		pData->handoverType 		= pSctpPacket->s1ap_handoverType;
	}
}

VOID S1APInterface::process_handOverRequestAcknowledge(s1mmeSession *pS1apSession, Sctp* pSctpPacket)
{
	BOOL found = false;

	pS1apSession = get_S1APSession(pSctpPacket, &found, false);

	if(!found && !pS1apSession->active)
		return;

	if(pS1apSession->state == STATE_HANDOVER_RESOURCE_ALLOC)
	{
		if(pS1apSession->mmeId == 0)
			pS1apSession->mmeId  = pSctpPacket->s1ap_mmeId;

		pS1apSession->noOfPackets++;

		/* Populate Procedure Map for the session */
		procedureData *pData = &pS1apSession->procedureMap[pS1apSession->noOfPackets];

		pData->reset();

		pData->procedureTimeNanoSec = IPGlobal::CURRENT_EPOCH_NANO_SEC;
		pData->pduType 				= pSctpPacket->s1ap_pduType;
		pData->procedureId 			= pSctpPacket->s1ap_procCode;

		pData->packetDirection = 2;
	}
}

VOID S1APInterface::process_handOverCancelAcknowledge(s1mmeSession *pS1apSession, Sctp* pSctpPacket)
{
	BOOL found = false;

	pS1apSession = get_S1APSession(pSctpPacket, &found, false);

	if(!found && !pS1apSession->active)
		return;

	if(pS1apSession->state == STATE_HANDOVER_CANCELLATION)
	{
		if(pS1apSession->mmeId == 0)
			pS1apSession->mmeId  = pSctpPacket->s1ap_mmeId;

		pS1apSession->noOfPackets++;

		/* Populate Procedure Map for the session */
		procedureData *pData = &pS1apSession->procedureMap[pS1apSession->noOfPackets];

		pData->reset();

		pData->procedureTimeNanoSec = IPGlobal::CURRENT_EPOCH_NANO_SEC;
		pData->pduType 				= pSctpPacket->s1ap_pduType;
		pData->procedureId 			= pSctpPacket->s1ap_procCode;

		pData->packetDirection = 2;
	}
}

VOID S1APInterface::process_contextReleaseComplete(s1mmeSession *pS1apSession, Sctp* pSctpPacket)
{
	BOOL found = false;
	pS1apSession = get_S1APSession(pSctpPacket, &found, false);

	if(!found && !pS1apSession->active)
		return;

	if(pS1apSession->state == STATE_UE_CONTEXT_RELEASE)
	{
		if(pS1apSession->mmeId == 0)
			pS1apSession->mmeId  = pSctpPacket->s1ap_mmeId;

		pS1apSession->noOfPackets++;

		/* Populate Procedure Map for the session */
		procedureData *pData = &pS1apSession->procedureMap[pS1apSession->noOfPackets];

		pData->reset();

		pData->procedureTimeNanoSec = IPGlobal::CURRENT_EPOCH_NANO_SEC;
		pData->pduType 				= pSctpPacket->s1ap_pduType;
		pData->procedureId 			= pSctpPacket->s1ap_procCode;

		pData->packetDirection 		= 1;
		pS1apSession->active 		= false;

		flushSession(pS1apSession, true);
	}
}


/* ----------------------------------- Un-SuccessfulOutcome Message ----------------------------------- */


VOID S1APInterface::process_initialContextSetupFailure(s1mmeSession *pS1apSession, Sctp* pSctpPacket)
{
	BOOL found = false;

	pS1apSession = get_S1APSession(pSctpPacket, &found, false);

	if(!found || !pS1apSession->active)
		return;

	if(pS1apSession->state == STATE_INITIAL_CONTEXT_SETUP)
	{
		if(pS1apSession->mmeId == 0)
			pS1apSession->mmeId  = pSctpPacket->s1ap_mmeId;

		pS1apSession->noOfPackets++;

		/* Populate Procedure Map for the session */
		procedureData *pData = &pS1apSession->procedureMap[pS1apSession->noOfPackets];

		pData->reset();

		pData->procedureTimeNanoSec = IPGlobal::CURRENT_EPOCH_NANO_SEC;
		pData->pduType 				= pSctpPacket->s1ap_pduType;
		pData->procedureId 			= pSctpPacket->s1ap_procCode;

		pData->packetDirection 		= 1;
		pData->failureCause 		= pSctpPacket->s1ap_causeId;
	}
}

VOID S1APInterface::process_handOverPreparationFailure(s1mmeSession *pS1apSession, Sctp* pSctpPacket)
{
	BOOL found = false;

	pS1apSession = get_S1APSession(pSctpPacket, &found, false);

	if(!found || !pS1apSession->active)
		return;

	if(pS1apSession->state == STATE_HANDOVER_PREPARATION)
	{
		if(pS1apSession->mmeId == 0)
			pS1apSession->mmeId  = pSctpPacket->s1ap_mmeId;

		pS1apSession->noOfPackets++;

		/* Populate Procedure Map for the session */
		procedureData *pData = &pS1apSession->procedureMap[pS1apSession->noOfPackets];

		pData->reset();

		pData->procedureTimeNanoSec = IPGlobal::CURRENT_EPOCH_NANO_SEC;
		pData->pduType 				= pSctpPacket->s1ap_pduType;
		pData->procedureId 			= pSctpPacket->s1ap_procCode;

		pData->packetDirection 		= 2;
		pData->handoverType 		= pSctpPacket->s1ap_handoverType;
		pData->HandoverCauseId 		= pSctpPacket->s1ap_causeId;
	}
}

VOID S1APInterface::process_handOverFailure(s1mmeSession *pS1apSession, Sctp* pSctpPacket)
{
	BOOL found = false;

	pS1apSession = get_S1APSession(pSctpPacket, &found, false);

	if(!found || !pS1apSession->active)
		return;

	if(pS1apSession->state == STATE_HANDOVER_RESOURCE_ALLOC)
	{
		if(pS1apSession->mmeId == 0)
			pS1apSession->mmeId  = pSctpPacket->s1ap_mmeId;

		pS1apSession->noOfPackets++;

		/* Populate Procedure Map for the session */
		procedureData *pData = &pS1apSession->procedureMap[pS1apSession->noOfPackets];

		pData->reset();

		pData->procedureTimeNanoSec = IPGlobal::CURRENT_EPOCH_NANO_SEC;
		pData->pduType 				= pSctpPacket->s1ap_pduType;
		pData->procedureId 			= pSctpPacket->s1ap_procCode;

		pData->packetDirection 		= 1;
		pData->handoverType 		= pSctpPacket->s1ap_handoverType;
		pData->HandoverCauseId 		= pSctpPacket->s1ap_causeId;
	}
}

/* ----------------------------------- Other functions ----------------------------------- */

s1mmeSession* S1APInterface::get_S1APSession(Sctp *pSctpPacket, BOOL *found, BOOL create)
{
	s1mmeSession *pS1apSession = NULL;
	int32_t mapIndex = -1;

	mapIndex = pSctpPacket->s1ap_eNodeBId % S1AP_POOL_ARRAY_ELEMENTS;

	std::map<uint32_t, int> ::iterator it = eNodeBMap[mapIndex].find(pSctpPacket->s1ap_eNodeBId);

	if(it != eNodeBMap[mapIndex].end())
	{
		pS1apSession = getSessionFromPool(it->second);
		*found = true;
	}
	else if(create)
	{
		sessionCounter = 0;

		for(int32_t i = 0; i < S1AP_POOL_ARRAY_ELEMENTS; i++)
			sessionCounter += eNodeBMap[i].size();

		IPGlobal::S1MME_ACTIVE_SESSIONS[instanceId] = sessionCounter;

		if(sessionCounter < freeBitPosMax)
		{
			int32_t poolIndex = getFreeIndex();
			pS1apSession = getSessionFromPool(poolIndex);

			pS1apSession->reset();
			pS1apSession->active 				= STATE_ACTIVE;

			pS1apSession->sourceIp 				= pSctpPacket->sourceIp;
			pS1apSession->sourcePort 			= pSctpPacket->sourcePort;

			pS1apSession->destIp 				= pSctpPacket->destIp;
			pS1apSession->destPort 				= pSctpPacket->destPort;

			pS1apSession->eNodeBId 				= pSctpPacket->s1ap_eNodeBId;
			pS1apSession->startSessionTimeSec 	= IPGlobal::CURRENT_EPOCH_SEC;

			pS1apSession->smInstanceId 			= instanceId;
			pS1apSession->poolIndex 			= poolIndex;
			pS1apSession->mapIndex 				= mapIndex;

			eNodeBMap[pS1apSession->mapIndex].insert(pair<uint32_t, int>(pS1apSession->eNodeBId, poolIndex));
		}
		*found = false;
	}
	return pS1apSession;
}

VOID S1APInterface::process_UserInformation(s1mmeSession *pS1apSession, Sctp *pSctpPacket)
{
	if(pSctpPacket->s1ap_m_tmsi_Present)
	{
		pS1apSession->tmsi_present = true;
		strcpy(pS1apSession->tmsi, pSctpPacket->s1ap_m_tmsi);
	}

	if(pSctpPacket->s1ap_imsiPresent)
	{
		pS1apSession->imsi_present = true;
		strcpy(pS1apSession->imsi, 	pSctpPacket->s1ap_imsi);
	}

	if(pSctpPacket->s1ap_imeiPresent)
	{
		pS1apSession->imei_present = true;
		strcpy(pS1apSession->imei, 	pSctpPacket->s1ap_imei);
	}
}


/*
 * createGlobalData is called for Procedure
 * 1: id_InitialContextSetup (When we get Attach Accept, if we get tmsi and IMSI both)
 */
VOID S1APInterface::createGlobalData(s1mmeSession *pS1apSession)
{
	/* Check the Global eNodeB Map and its associated TMSI map, if found delete it */

	std::map<uint32_t, sessionGlbData> ::iterator eNodeB_it = S1APStore::eNodeBGlbData.find(pS1apSession->eNodeBId);

	if(eNodeB_it !=  S1APStore::eNodeBGlbData.end())
	{
		S1APStore::eNodeBGlbData.erase(pS1apSession->eNodeBId);
		S1APStore::tmsiGlbData.erase(std::string(eNodeB_it->second.imsi));
		S1APStore::tmsiGlbData.erase(std::string(eNodeB_it->second.imei));
		printf(" ** Deleting Existing eNodeBGlbData Global Map....\n");
	}

	/*
	 * Check the Global TMSI Map and its associated eNodeB map, if found delete it
	 * Note: This step is done for safer end
	 */
	std::map<std::string, sessionGlbData> ::iterator imsi_it = S1APStore::tmsiGlbData.find(std::string(pS1apSession->imsi));

	if(imsi_it !=  S1APStore::tmsiGlbData.end())
	{
		S1APStore::tmsiGlbData.erase(std::string(pS1apSession->imsi));
		S1APStore::tmsiGlbData.erase(std::string(pS1apSession->imei));
		S1APStore::eNodeBGlbData.erase(imsi_it->second.eNodeBId);
		printf(" ** Deleting Existing tmsiGlbData Global Map....\n");
	}

	/*
	 * Now created the new eNode B and TMSI maps
	 */

	sessionGlbData gData;
	gData.eNodeBId = pS1apSession->eNodeBId;
	strcpy(gData.imsi, pS1apSession->imsi);
	strcpy(gData.tmsi, pS1apSession->tmsi);
	strcpy(gData.imei, pS1apSession->imei);

	S1APStore::eNodeBGlbData.insert(pair<uint32_t, sessionGlbData>(pS1apSession->eNodeBId, gData));
	S1APStore::tmsiGlbData.insert(pair<std::string, sessionGlbData>(std::string(pS1apSession->tmsi), gData));

	printf("Global Session Created .. for Procedure :: %s\n", S1APInitialize::s1ap_procedureType[pS1apSession->procedureMap[pS1apSession->noOfPackets].procedureId].c_str());
}

/*
 * updateGlobalData is called for Procedure
 * 1: id_InitialContextSetup
 * 2: id_initialUEMessage
 */
VOID S1APInterface::updateGlobalData(Sctp *pSctpPacket)
{
	old_tmsi[0] 	= 0;
	old_eNodeBId 	= 0;

	pGlbData.reset();

	std::map<uint32_t, sessionGlbData> ::iterator eNodeB_it = S1APStore::eNodeBGlbData.find(pSctpPacket->s1ap_eNodeBId);

	if(eNodeB_it != S1APStore::eNodeBGlbData.end())
	{
		if((pSctpPacket->s1ap_m_tmsi_Present) && (strcmp(eNodeB_it->second.tmsi, pSctpPacket->s1ap_m_tmsi) != 0))
		{
			pGlbData.copy(&eNodeB_it->second);			/* Store Old Values */

			std::map<std::string, sessionGlbData>::iterator tmsi_it = S1APStore::tmsiGlbData.find(std::string(pGlbData.tmsi));

			if(tmsi_it != S1APStore::tmsiGlbData.end())
			{
				S1APStore::eNodeBGlbData.erase(pGlbData.eNodeBId);
				S1APStore::tmsiGlbData.erase(std::string(pGlbData.tmsi));

				printf("Global Session Update .. for Procedure :: %s\n", S1APInitialize::s1ap_procedureType[pSctpPacket->s1ap_procCode].c_str());
				printf("1. Updating --> Old:: eNodeB %u|tmsi %s     New:: eNodeB %u|tmsi %s\n", pGlbData.eNodeBId, pGlbData.tmsi, pSctpPacket->s1ap_eNodeBId, pSctpPacket->s1ap_m_tmsi);

				pGlbData.eNodeBId = pSctpPacket->s1ap_eNodeBId;			/* Update with New eNodeB 	*/
				strcpy(pGlbData.tmsi, pSctpPacket->s1ap_m_tmsi);		/* Update with New TMSI 	*/


				S1APStore::eNodeBGlbData.insert(pair<uint32_t, sessionGlbData>(pSctpPacket->s1ap_eNodeBId, pGlbData));
				S1APStore::tmsiGlbData.insert(pair<std::string, sessionGlbData>(std::string(pSctpPacket->s1ap_m_tmsi), pGlbData));
			}
			else
			{
				printf("Global Session Update .. for Procedure :: %s\n", S1APInitialize::s1ap_procedureType[pSctpPacket->s1ap_procCode].c_str());
				printf("2. Updating --> Old:: eNodeB %u     New:: eNodeB %u\n", pGlbData.eNodeBId, pSctpPacket->s1ap_eNodeBId);

				S1APStore::eNodeBGlbData.erase(pGlbData.eNodeBId);
				pGlbData.eNodeBId = pSctpPacket->s1ap_eNodeBId;
				S1APStore::eNodeBGlbData.insert(pair<uint32_t, sessionGlbData>(pSctpPacket->s1ap_eNodeBId, pGlbData));
			}
		}
	}
	else
	{
		std::map<std::string, sessionGlbData>::iterator tmsi_it = S1APStore::tmsiGlbData.find(std::string(pSctpPacket->s1ap_m_tmsi));

		if(tmsi_it != S1APStore::tmsiGlbData.end())
		{
			pGlbData.copy(&tmsi_it->second);			/* Store Old Values */

			if(pGlbData.eNodeBId != pSctpPacket->s1ap_eNodeBId)
			{
				std::map<uint32_t, sessionGlbData> ::iterator eNodeB_it = S1APStore::eNodeBGlbData.find(pGlbData.eNodeBId);

				if(eNodeB_it != S1APStore::eNodeBGlbData.end())
				{
					S1APStore::eNodeBGlbData.erase(pGlbData.eNodeBId);
					S1APStore::tmsiGlbData.erase(std::string(pGlbData.tmsi));

					printf("Global Session Update .. for Procedure :: %s\n", S1APInitialize::s1ap_procedureType[pSctpPacket->s1ap_procCode].c_str());
					printf("3. Global Updating --> Old:: eNodeB %u|tmsi %s     New:: eNodeB %u|tmsi %s\n", pGlbData.eNodeBId, pGlbData.tmsi, pSctpPacket->s1ap_eNodeBId, pSctpPacket->s1ap_m_tmsi);

					pGlbData.eNodeBId = pSctpPacket->s1ap_eNodeBId;			/* Update with New eNodeB 	*/
					strcpy(pGlbData.tmsi, pSctpPacket->s1ap_m_tmsi);		/* Update with New TMSI 	*/

					S1APStore::eNodeBGlbData.insert(pair<uint32_t, sessionGlbData>(pSctpPacket->s1ap_eNodeBId, pGlbData));
					S1APStore::tmsiGlbData.insert(pair<std::string, sessionGlbData>(std::string(pSctpPacket->s1ap_m_tmsi), pGlbData));
				}
			}
		}
	}
}

VOID S1APInterface::checkMMMType(procedureData *pData, uint32_t msgType, uint32_t enode)
{
	switch(msgType)
	{
		case ServiceRequest:
			pData->mmmMap[enode].Service_Request = true;
			break;

		case AttachRequest:
			pData->mmmMap[enode].Attach_Request = true;
			break;

		case AttachAccept:
			pData->mmmMap[enode].Attach_Accept = true;
			break;

		case AttachComplete:
			pData->mmmMap[enode].Attach_Complete = true;
			IPGlobal::S1AP_ATTACH_SESSIONS_TODAY[instanceId]++;
			break;

		case AttachReject:
			pData->mmmMap[enode].Attach_Reject = true;
			flushFlag = true;
			break;

		case DetachRequest:
			pData->mmmMap[enode].Detach_Request = true;
			break;

		case DetachAccept:
			pData->mmmMap[enode].Detach_Accept = true;
			flushFlag = true;
			break;

		case TrackingAreaUpdateRequest:
			pData->mmmMap[enode].Tracking_Area_Update_Request = true;
			break;

		case TrackingAreaUpdateAccept:
			pData->mmmMap[enode].Tracking_Area_Update_Accept = true;
			break;

		case TrackingAreaUpdateComplete:
			pData->mmmMap[enode].Tracking_Area_Update_Complete = true;
			IPGlobal::S1AP_TAU_SESSIONS_TODAY[instanceId]++;
			break;

		case TrackingAreaUpdateReject:
			pData->mmmMap[enode].Tracking_Area_Update_Reject = true;
			flushFlag = true;
			break;

		case ExtendedServiceRequest:
			pData->mmmMap[enode].Extended_service_Request = true;
			break;

		case ServiceReject:
			pData->mmmMap[enode].Service_Reject = true;
			flushFlag = true;
			break;

		case GUTIReallocationCommand:
			pData->mmmMap[enode].GUTI_reallocation_command = true;
			break;

		case GUTIReallocationComplete:
			pData->mmmMap[enode].GUTI_reallocation_Complete = true;
			break;

		case AuthenticationRequest:
			pData->mmmMap[enode].Authentication_Request = true;
			break;

		case AuthenticationResponse:
			pData->mmmMap[enode].Authentication_Response = true;
			break;

		case AuthenticationReject:
			pData->mmmMap[enode].Authentication_Reject = true;
			flushFlag = true;
			break;

		case IdentityRequest:
			pData->mmmMap[enode].Identity_Request = true;
			break;

		case IdentityResponse:
			pData->mmmMap[enode].Identity_Response = true;
			break;

		case AuthenticationFailure:
			pData->mmmMap[enode].Authentication_Failure = true;
			break;

		case SecurityModeCommand:
			pData->mmmMap[enode].Security_Mode_Command = true;
			break;

		case SecurityModeComplete:
			pData->mmmMap[enode].Security_Mode_Complete = true;
			break;

		case SecurityModeReject:
			pData->mmmMap[enode].Security_Mode_Reject = true;
			flushFlag = true;
			break;

		case EMMStatus:
			pData->mmmMap[enode].EMM_Status = true;
			break;

		case EMMInformation:
			pData->mmmMap[enode].EMM_Information = true;
			break;

		case DownLinkNASTransport:
			pData->mmmMap[enode].DownLink_NAS_Transport = true;
			break;

		case UpLinkNASTransport:
			pData->mmmMap[enode].UpLink_NAS_Transport = true;
			break;

		case CSServiceNotification:
			pData->mmmMap[enode].CS_Service_Notification = true;
			break;

		case DownLinkGenericNASTransport:
			pData->mmmMap[enode].DownLink_Generic_NAS_Transport = true;
			break;

		case UpLinkGenericNASTransport:
			pData->mmmMap[enode].UpLink_Generic_NAS_Transport = true;
			break;
	}
}

VOID S1APInterface::checkSMMType(procedureData *pData, uint32_t msgType, uint32_t enode)
{
	switch(msgType) // SMM or ESM
	{
		case Activate_Default_EPS_Bearer_Context_Request:
			pData->smmMap[enode].Activate_Default_EPS_Bearer_Context_Request = true;
			break;

		case Activate_Default_EPS_Bearer_Context_Accept:
			pData->smmMap[enode].Activate_Default_EPS_Bearer_Context_Accept = true;
			break;

		case Activate_Default_EPS_Bearer_Context_Reject:
			pData->smmMap[enode].Activate_Default_EPS_Bearer_Context_Reject = true;
			flushFlag = true;
			break;

		case Activate_Dedicated_EPS_Bearer_Context_Request:
			pData->smmMap[enode].Activate_Dedicated_EPS_Bearer_Context_Request = true;
			break;

		case Activate_Dedicated_EPS_Bearer_Context_Accept:
			pData->smmMap[enode].Activate_Dedicated_EPS_Bearer_Context_Accept = true;
			break;

		case Activate_Dedicated_EPS_Bearer_Context_Reject:
			pData->smmMap[enode].Activate_Dedicated_EPS_Bearer_Context_Reject = true;
			flushFlag = true;
			break;

		case Modify_EPS_Bearer_Context_Request:
			pData->smmMap[enode].Modify_EPS_Bearer_Context_Request = true;
			break;

		case Modify_EPS_Bearer_Context_Accept:
			pData->smmMap[enode].Modify_EPS_Bearer_Context_Accept = true;
			break;

		case Modify_EPS_Bearer_Context_Reject:
			pData->smmMap[enode].Modify_EPS_Bearer_Context_Reject = true;
			flushFlag = true;
			break;

		case Deactivate_EPS_Bearer_Context_Request:
			pData->smmMap[enode].Deactivate_EPS_Bearer_Context_Request = true;
			break;

		case Deactivate_EPS_Bearer_Context_Accept:
			pData->smmMap[enode].Deactivate_EPS_Bearer_Context_Accept = true;
			break;

		case PDN_Connectivity_Request:
			pData->smmMap[enode].PDN_Connectivity_Request = true;
			break;

		case PDN_Connectivity_Reject:
			pData->smmMap[enode].PDN_Connectivity_Reject = true;
			flushFlag = true;
			break;

		case PDN_Disconnect_Request:
			pData->smmMap[enode].PDN_Disconnect_Request = true;
			break;

		case PDN_Disconnect_Reject:
			pData->smmMap[enode].PDN_Disconnect_Reject = true;
			flushFlag = true;
			break;

		case Bearer_Resource_Allocation_Request:
			pData->smmMap[enode].Bearer_Resource_Allocation_Request = true;
			break;

		case Bearer_Resource_Allocation_Reject:
			pData->smmMap[enode].Bearer_Resource_Allocation_Reject = true;
			flushFlag = true;
			break;

		case Bearer_Resource_Modification_Request:
			pData->smmMap[enode].Bearer_Resource_Modification_Request = true;
			break;

		case Bearer_Resource_Modification_Reject:
			pData->smmMap[enode].Bearer_Resource_Modification_Reject = true;
			flushFlag = true;
			break;

		case ESM_Information_Request:
			pData->smmMap[enode].ESM_Information_Request = true;
			break;

		case ESM_Information_response:
			pData->smmMap[enode].ESM_Information_response = true;
			break;

		case Notification:
			pData->smmMap[enode].Notification = true;
			break;

		case ESM_Status:
			pData->smmMap[enode].ESM_Status = true;
			break;
	}
}

VOID S1APInterface::flushSession(s1mmeSession *pS1apSession, bool erase)
{
	long epochSecNow = IPGlobal::CURRENT_EPOCH_SEC;

	int idx = PKT_WRITE_TIME_INDEX(epochSecNow, IPGlobal::PKT_TIME_INDEX);

	S1apFlushRepository::s1apFlushMap[instanceId][idx][S1apFlushRepository::s1apFlushMap_cnt[instanceId][idx]].copy(pS1apSession);
	S1apFlushRepository::s1apFlushMap_cnt[instanceId][idx]++;

	if(erase)
	{
		eNodeBMap[pS1apSession->mapIndex].erase(pS1apSession->eNodeBId);
		releaseIndex(pS1apSession->poolIndex);
	}
}

VOID S1APInterface::S1AP_TimeOutCleanSession(uint64_t sec)
{
	sessionCounter = 0;
	sessionCleanCounter = 0;

	for(int32_t i = 0; i < S1AP_POOL_ARRAY_ELEMENTS; i++)
	{
		sessionCounter += eNodeBMap[i].size();
		IPGlobal::S1MME_ACTIVE_SESSIONS[instanceId] = sessionCounter;

		for(auto elem = eNodeBMap[i].begin(), next_elem = elem; elem != eNodeBMap[i].end(); elem = next_elem)
		{
			++next_elem;
			cleanTimedOutSessions(getSessionFromPool(elem->second));
		}
	}

	IPGlobal::S1MME_CLEANED_SESSIONS[instanceId] = sessionCleanCounter;
}

VOID S1APInterface::cleanTimedOutSessions(s1mmeSession *pSession)
{
	uint64_t curEpochSec = IPGlobal::CURRENT_EPOCH_SEC;

	if((curEpochSec - pSession->startSessionTimeSec) > 60)
	{
		printf("Flush 3\n");
		sessionCleanCounter++;
		flushSession(pSession, true);
	}
}

VOID S1APInterface::SM_ProcessPDUTypeMsg()
{
	S1AP_SMFunctions::pduTypeTable.insert(std::pair<uint16_t, pduType>(INITIATING_MSG, &process_InitiatingMsg));				// 0
	S1AP_SMFunctions::pduTypeTable.insert(std::pair<uint16_t, pduType>(SUCCESSFUL_OUTCOME, &process_SuccessfulOutcomeMsg));		// 1
	S1AP_SMFunctions::pduTypeTable.insert(std::pair<uint16_t, pduType>(UNSUCCESSFUL_OUTCOME, &process_UnSuccessfulOutcomeMsg)); // 2
}

VOID S1APInterface::SM_ProcessInitiatingMsg()
{
	S1AP_SMFunctions::smInitiatingTable.insert(std::pair<uint16_t, smFunctions>(id_HandoverPreparation, &process_handOverRequired));				/* 00 */
	S1AP_SMFunctions::smInitiatingTable.insert(std::pair<uint16_t, smFunctions>(id_HandoverResourceAllocation, &process_handOverRequest));			/* 01 */
	S1AP_SMFunctions::smInitiatingTable.insert(std::pair<uint16_t, smFunctions>(id_HandoverNotification, &process_handOverNotify));					/* 02 */
	S1AP_SMFunctions::smInitiatingTable.insert(std::pair<uint16_t, smFunctions>(id_HandoverCancel, &process_handOverCancel));						/* 04 */
	S1AP_SMFunctions::smInitiatingTable.insert(std::pair<uint16_t, smFunctions>(id_InitialContextSetup, &process_InitialContextSetupRequest));		/* 09 */
	S1AP_SMFunctions::smInitiatingTable.insert(std::pair<uint16_t, smFunctions>(id_downlinkNASTransport, &process_downLinkNASTransport));			/* 11 */
	S1AP_SMFunctions::smInitiatingTable.insert(std::pair<uint16_t, smFunctions>(id_initialUEMessage, &process_initialUEMessage));					/* 12 */
	S1AP_SMFunctions::smInitiatingTable.insert(std::pair<uint16_t, smFunctions>(id_uplinkNASTransport, &process_upLinkNASTransport));				/* 13 */
	S1AP_SMFunctions::smInitiatingTable.insert(std::pair<uint16_t, smFunctions>(id_UEContextReleaseRequest, &process_contextReleaseRequest));		/* 18 */
	S1AP_SMFunctions::smInitiatingTable.insert(std::pair<uint16_t, smFunctions>(id_UEContextRelease, &process_contextReleaseCommand));				/* 23 */
}

VOID S1APInterface::SM_ProcessSuccessfulMsg()
{
	S1AP_SMFunctions::smSuccessfullTable.insert(std::pair<uint16_t, smFunctions>(id_HandoverPreparation, &process_handOverCommand));					/* 00 */
	S1AP_SMFunctions::smSuccessfullTable.insert(std::pair<uint16_t, smFunctions>(id_HandoverResourceAllocation, &process_handOverRequestAcknowledge));	/* 01 */
	S1AP_SMFunctions::smSuccessfullTable.insert(std::pair<uint16_t, smFunctions>(id_HandoverCancel, &process_handOverCancelAcknowledge));				/* 04 */
	S1AP_SMFunctions::smSuccessfullTable.insert(std::pair<uint16_t, smFunctions>(id_InitialContextSetup, &process_initialContextSetupResponse));		/* 09 */
	S1AP_SMFunctions::smSuccessfullTable.insert(std::pair<uint16_t, smFunctions>(id_UEContextRelease, &process_contextReleaseComplete));				/* 23 */
}

VOID S1APInterface::SM_ProcessUnSuccessfulMsg()
{
	S1AP_SMFunctions::smUnSuccessfullTable.insert(std::pair<uint16_t, smFunctions>(id_HandoverPreparation, &process_handOverPreparationFailure));	/* 00 */
	S1AP_SMFunctions::smUnSuccessfullTable.insert(std::pair<uint16_t, smFunctions>(id_HandoverResourceAllocation, &process_handOverFailure));		/* 01 */
	S1AP_SMFunctions::smUnSuccessfullTable.insert(std::pair<uint16_t, smFunctions>(id_InitialContextSetup, &process_initialContextSetupFailure));	/* 09 */
}
