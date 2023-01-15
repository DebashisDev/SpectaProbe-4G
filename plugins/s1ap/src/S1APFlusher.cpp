/*
 * S1APFlusher.cpp
 *
 *  Created on: 29-Jan-2020
 *      Author: Ishan
 */

#include "S1APFlusher.h"

S1APFlusher::S1APFlusher() {
	_thisLogLevel = 0;
	packetHdr[0] = 0;
	packetMMM[0] = 0;
	packetSMM[0] = 0;
	finalPacket[0] = 0;
	procedurevalue[0] = 0;
	procedureId[0] = 0;
	imsi = NULL;

	this->_name = "S1APFlusher    ";
	this->setLogLevel(Log::theLog().level());
}

S1APFlusher::~S1APFlusher()
{ }

VOID S1APFlusher::lockS1apMap()
{
	    pthread_mutex_lock(&s1mmeSessionLock::lockCount);
	    while (s1mmeSessionLock::count == 0)
	        pthread_cond_wait(&s1mmeSessionLock::nonzero, &s1mmeSessionLock::lockCount);
	    s1mmeSessionLock::count = s1mmeSessionLock::count - 1;
	    pthread_mutex_unlock(&s1mmeSessionLock::lockCount);
}

VOID S1APFlusher::unLockS1apMap()
{
    pthread_mutex_lock(&s1mmeSessionLock::lockCount);
    if (s1mmeSessionLock::count == 0)
        pthread_cond_signal(&s1mmeSessionLock::nonzero);
    s1mmeSessionLock::count = s1mmeSessionLock::count + 1;
    pthread_mutex_unlock(&s1mmeSessionLock::lockCount);
}

BOOL S1APFlusher::isRepositoryInitialized(){
	return repoInitStatus;
}

VOID S1APFlusher::run()
{
	int lastProcessedIndex = -1;
	int curIndex = -1;
	repoInitStatus = true;

	curIndex = PKT_READ_TIME_INDEX(IPGlobal::CURRENT_EPOCH_SEC, IPGlobal::PKT_TIME_INDEX);
	lastProcessedIndex = curIndex;

	while(IPGlobal::S1MME_FLUSHER_RUNNING_STATUS)
	{
		curIndex = PKT_READ_TIME_INDEX(IPGlobal::CURRENT_EPOCH_SEC, IPGlobal::PKT_TIME_INDEX);

		while(lastProcessedIndex != curIndex)
		{
			usleep(25000);
			strcpy(csvXdr, "");
			processS1apData(lastProcessedIndex);

			lastProcessedIndex = PKT_READ_NEXT_TIME_INDEX(lastProcessedIndex, IPGlobal::PKT_TIME_INDEX);
		}
	}
	printf("\nIP/S1AP Flusher Shutdown Completed \n");
}

VOID S1APFlusher::flushS1apData_t(std::unordered_map<int, s1mmeSession> &flushMap, int &s1apFlushMap_cnt)
{
	int cnt = s1apFlushMap_cnt;

	for(int i=0; i<cnt; i++)
	{
		buildS1apSession(&flushMap[i]);
		flushMap.erase(i);
		s1apFlushMap_cnt--;
	}
	flushMap.clear();
	s1apFlushMap_cnt = 0;
}

VOID S1APFlusher::processS1apData(int index)
{
	for(uint16_t smInstance = 0; smInstance < MAX_S1MME_SESSION_MANAGER_SUPPORT; smInstance)
		flushS1apData_t(S1apFlushRepository::s1apFlushMap[smInstance][index], S1apFlushRepository::s1apFlushMap_cnt[smInstance][index]);

/*
	switch(index)
	{
		case 0:
			flushS1apData_t(S1apFlushRepository::s1apFlushMap_sm_0_t_0, S1apFlushRepository::s1apFlushMap_sm_0_t_0_cnt);
			flushS1apData_t(S1apFlushRepository::s1apFlushMap_sm_1_t_0, S1apFlushRepository::s1apFlushMap_sm_1_t_0_cnt);
			flushS1apData_t(S1apFlushRepository::s1apFlushMap_sm_2_t_0, S1apFlushRepository::s1apFlushMap_sm_2_t_0_cnt);
			flushS1apData_t(S1apFlushRepository::s1apFlushMap_sm_3_t_0, S1apFlushRepository::s1apFlushMap_sm_3_t_0_cnt);
			break;

		case 1:
			flushS1apData_t(S1apFlushRepository::s1apFlushMap_sm_0_t_1, S1apFlushRepository::s1apFlushMap_sm_0_t_1_cnt);
			flushS1apData_t(S1apFlushRepository::s1apFlushMap_sm_1_t_1, S1apFlushRepository::s1apFlushMap_sm_1_t_1_cnt);
			flushS1apData_t(S1apFlushRepository::s1apFlushMap_sm_2_t_1, S1apFlushRepository::s1apFlushMap_sm_2_t_1_cnt);
			flushS1apData_t(S1apFlushRepository::s1apFlushMap_sm_3_t_1, S1apFlushRepository::s1apFlushMap_sm_3_t_1_cnt);
			break;

		case 2:
			flushS1apData_t(S1apFlushRepository::s1apFlushMap_sm_0_t_2, S1apFlushRepository::s1apFlushMap_sm_0_t_2_cnt);
			flushS1apData_t(S1apFlushRepository::s1apFlushMap_sm_1_t_2, S1apFlushRepository::s1apFlushMap_sm_1_t_2_cnt);
			flushS1apData_t(S1apFlushRepository::s1apFlushMap_sm_2_t_2, S1apFlushRepository::s1apFlushMap_sm_2_t_2_cnt);
			flushS1apData_t(S1apFlushRepository::s1apFlushMap_sm_3_t_2, S1apFlushRepository::s1apFlushMap_sm_3_t_2_cnt);
			break;

		case 3:
			flushS1apData_t(S1apFlushRepository::s1apFlushMap_sm_0_t_3, S1apFlushRepository::s1apFlushMap_sm_0_t_3_cnt);
			flushS1apData_t(S1apFlushRepository::s1apFlushMap_sm_1_t_3, S1apFlushRepository::s1apFlushMap_sm_1_t_3_cnt);
			flushS1apData_t(S1apFlushRepository::s1apFlushMap_sm_2_t_3, S1apFlushRepository::s1apFlushMap_sm_2_t_3_cnt);
			flushS1apData_t(S1apFlushRepository::s1apFlushMap_sm_3_t_3, S1apFlushRepository::s1apFlushMap_sm_3_t_3_cnt);
			break;

		case 4:
			flushS1apData_t(S1apFlushRepository::s1apFlushMap_sm_0_t_4, S1apFlushRepository::s1apFlushMap_sm_0_t_4_cnt);
			flushS1apData_t(S1apFlushRepository::s1apFlushMap_sm_1_t_4, S1apFlushRepository::s1apFlushMap_sm_1_t_4_cnt);
			flushS1apData_t(S1apFlushRepository::s1apFlushMap_sm_2_t_4, S1apFlushRepository::s1apFlushMap_sm_2_t_4_cnt);
			flushS1apData_t(S1apFlushRepository::s1apFlushMap_sm_3_t_4, S1apFlushRepository::s1apFlushMap_sm_3_t_4_cnt);
			break;

		case 5:
			flushS1apData_t(S1apFlushRepository::s1apFlushMap_sm_0_t_5, S1apFlushRepository::s1apFlushMap_sm_0_t_5_cnt);
			flushS1apData_t(S1apFlushRepository::s1apFlushMap_sm_1_t_5, S1apFlushRepository::s1apFlushMap_sm_1_t_5_cnt);
			flushS1apData_t(S1apFlushRepository::s1apFlushMap_sm_2_t_5, S1apFlushRepository::s1apFlushMap_sm_2_t_5_cnt);
			flushS1apData_t(S1apFlushRepository::s1apFlushMap_sm_3_t_5, S1apFlushRepository::s1apFlushMap_sm_3_t_5_cnt);
			break;

		case 6:
			flushS1apData_t(S1apFlushRepository::s1apFlushMap_sm_0_t_6, S1apFlushRepository::s1apFlushMap_sm_0_t_6_cnt);
			flushS1apData_t(S1apFlushRepository::s1apFlushMap_sm_1_t_6, S1apFlushRepository::s1apFlushMap_sm_1_t_6_cnt);
			flushS1apData_t(S1apFlushRepository::s1apFlushMap_sm_2_t_6, S1apFlushRepository::s1apFlushMap_sm_2_t_6_cnt);
			flushS1apData_t(S1apFlushRepository::s1apFlushMap_sm_3_t_6, S1apFlushRepository::s1apFlushMap_sm_3_t_6_cnt);
			break;

		case 7:
			flushS1apData_t(S1apFlushRepository::s1apFlushMap_sm_0_t_7, S1apFlushRepository::s1apFlushMap_sm_0_t_7_cnt);
			flushS1apData_t(S1apFlushRepository::s1apFlushMap_sm_1_t_7, S1apFlushRepository::s1apFlushMap_sm_1_t_7_cnt);
			flushS1apData_t(S1apFlushRepository::s1apFlushMap_sm_2_t_7, S1apFlushRepository::s1apFlushMap_sm_2_t_7_cnt);
			flushS1apData_t(S1apFlushRepository::s1apFlushMap_sm_3_t_7, S1apFlushRepository::s1apFlushMap_sm_3_t_7_cnt);
			break;

		case 8:
			flushS1apData_t(S1apFlushRepository::s1apFlushMap_sm_0_t_8, S1apFlushRepository::s1apFlushMap_sm_0_t_8_cnt);
			flushS1apData_t(S1apFlushRepository::s1apFlushMap_sm_1_t_8, S1apFlushRepository::s1apFlushMap_sm_1_t_8_cnt);
			flushS1apData_t(S1apFlushRepository::s1apFlushMap_sm_2_t_8, S1apFlushRepository::s1apFlushMap_sm_2_t_8_cnt);
			flushS1apData_t(S1apFlushRepository::s1apFlushMap_sm_3_t_8, S1apFlushRepository::s1apFlushMap_sm_3_t_8_cnt);
			break;

		case 9:
			flushS1apData_t(S1apFlushRepository::s1apFlushMap_sm_0_t_9, S1apFlushRepository::s1apFlushMap_sm_0_t_9_cnt);
			flushS1apData_t(S1apFlushRepository::s1apFlushMap_sm_1_t_9, S1apFlushRepository::s1apFlushMap_sm_1_t_9_cnt);
			flushS1apData_t(S1apFlushRepository::s1apFlushMap_sm_2_t_9, S1apFlushRepository::s1apFlushMap_sm_2_t_9_cnt);
			flushS1apData_t(S1apFlushRepository::s1apFlushMap_sm_3_t_9, S1apFlushRepository::s1apFlushMap_sm_3_t_9_cnt);
			break;
	}
*/
}


BOOL S1APFlusher::accumulatePackets(s1mmeSession *ps1apSession, char *packetSeq)
{
	packetSeq[0] = 0;
	uint16_t 	packetNo = 0;
	char causeId[100];

	if(ps1apSession->procedureMap.size() <= 0) return false;

	for(auto elem = ps1apSession->procedureMap.begin(), next_elem = elem; elem != ps1apSession->procedureMap.end(); elem = next_elem)
	{
		++next_elem;
		causeId[0] = 0;
		procedureId[0] = procedurevalue[0] = packetHdr[0] = packetMMM[0] = packetSMM[0] = 0;

		packetNo++;

		switch(elem->second.pduType)
		{
			case INITIATING_MSG:
				strcpy(procedureId, S1APInitialize::s1ap_procedureType[elem->second.procedureId].c_str());
				strcpy(procedurevalue, S1APInitialize::s1ap_initiatingMsgValue[elem->second.procedureId].c_str());
				break;

			case SUCCESSFUL_OUTCOME:
				strcpy(procedureId, S1APInitialize::s1ap_procedureType[elem->second.procedureId].c_str());
				strcpy(procedurevalue, S1APInitialize::s1ap_successfulOutcomeMsgValue[elem->second.procedureId].c_str());
				break;
		}

		sprintf(packetHdr,
					"%s,%d,%u,%u,%llu," 		// 01. Separater	02. Packet No			03. eNodeB				04. mmeId			05. procTimeNanoSec
					"%d,%s,%s,%d,"				// 06. pduType 		07. ProcedureId			08. ProcedureValue		09. packetDirection
					"%s,%s,%s,%s,%s,"			// 10. pLMN			11. tac					12. cellId				13. pdnAddress 		14. APN
					"%lu,%lu,%d,%d,%d,"			// 15. mbrDL		16. mbrUL				17. estCause			18. rejectCause		19. failureCause
					"%d,%d,%d,%d,"				// 20. HO Type		21. HO Cause			22. relCauseType		23. relCauseId
					"%s,%s,%s,%s,"				// 24. targetCellId 25. targetPLMNIdentity	26. lastVisitedCellId	27. lastVisitedPLMNIdentity
					"%d,%d,%d,%d",				// 28. qCI			29. APN-AMBR-UP			30. APN-AMBR-DN			31. Time Spend
					"#", packetNo, ps1apSession->eNodeBId, ps1apSession->mmeId, elem->second.procedureTimeNanoSec,
					elem->second.pduType, procedureId, procedurevalue, elem->second.packetDirection,
					elem->second.pLMNIdentity,elem->second.tac, elem->second.cellId, elem->second.pdnAddress, elem->second.apn,
					elem->second.mbrDL, elem->second.mbrUL, elem->second.estCause, elem->second.rejectCause, elem->second.failureCause,
					elem->second.handoverType, elem->second.HandoverCauseId, elem->second.releaseCauseType, elem->second.releaseCauseId,
					elem->second.targetCellId, elem->second.targetPLMNIdentity, elem->second.lastVisitedCellId, elem->second.lastVisitedPLMNIdentity,
					elem->second.qCI, elem->second.apnAmbrUp, elem->second.apnAmbrDn, 0);

		finalPacket[0] = 0;

		/* Get the Mobility Management Messages */
		if(elem->second.mmmPresent)
		{
			findMMM(elem->second.mmmMap);
			sprintf(finalPacket, "%s,%s", packetHdr, packetMMM);
		}
		else
			sprintf(finalPacket, "%s,%s", packetHdr, "NA");

		/* Get the Service Management Messages */
		if(elem->second.smmPresent)
		{
			findSMM(elem->second.smmMap);
			sprintf(finalPacket, "%s,%s,", finalPacket, packetSMM);
		}
		else
			sprintf(finalPacket, "%s,%s,", finalPacket, "NA");

//		printf("-- %s\n", finalPacket);
		strcat(packetSeq, finalPacket);
	}
//	printf("\n");
	ps1apSession->procedureMap.clear();
	return true;
}

VOID S1APFlusher::findMMM(std::map<uint32_t, MMM> &mmmMap)
{
	packetMMM[0] = 0;

	for(auto elem1 : mmmMap)
	{
		if(elem1.second.Service_Request) strcat(packetMMM, "Service Request;");

		if(elem1.second.Attach_Request) strcat(packetMMM, "Attach Request;");

		if(elem1.second.Attach_Accept) strcat(packetMMM, "Attach Accept;");

		if(elem1.second.Attach_Complete) strcat(packetMMM, "Attach Complete;");

		if(elem1.second.Attach_Reject) strcat(packetMMM, "Attach Reject;");

		if(elem1.second.Detach_Request) strcat(packetMMM, "Detach Request;");

		if(elem1.second.Detach_Accept) strcat(packetMMM, "Detach Accept;");

		if(elem1.second.Tracking_Area_Update_Request) strcat(packetMMM, "Tracking Area Update Request;");

		if(elem1.second.Tracking_Area_Update_Accept) strcat(packetMMM, "Tracking Area Update Accept;");

		if(elem1.second.Tracking_Area_Update_Complete) strcat(packetMMM, "Tracking Area Update Complete;");

		if(elem1.second.Tracking_Area_Update_Reject) strcat(packetMMM, "Tracking Area Update Reject;");

		if(elem1.second.Extended_service_Request) strcat(packetMMM, "Extended service Request;");

		if(elem1.second.Service_Reject)	strcat(packetMMM, "Service Reject;");

		if(elem1.second.GUTI_reallocation_command) strcat(packetMMM, "GUTI Reallocation Command;");

		if(elem1.second.GUTI_reallocation_Complete) strcat(packetMMM, "GUTI Reallocation Complete;");

		if(elem1.second.Authentication_Request) strcat(packetMMM, "Authentication Request;");

		if(elem1.second.Authentication_Response) strcat(packetMMM, "Authentication Response;");

		if(elem1.second.Authentication_Reject) strcat(packetMMM, "Authentication Reject;");

		if(elem1.second.Identity_Request) strcat(packetMMM, "Identity Request;");

		if(elem1.second.Identity_Response) strcat(packetMMM, "Identity Response;");

		if(elem1.second.Authentication_Failure)	strcat(packetMMM, "Authentication Failure;");

		if(elem1.second.Security_Mode_Command) strcat(packetMMM, "Security Mode Command;");

		if(elem1.second.Security_Mode_Complete)	strcat(packetMMM, "Security Mode Complete;");

		if(elem1.second.Security_Mode_Reject) strcat(packetMMM, "Security Mode Reject;");

		if(elem1.second.EMM_Status)	strcat(packetMMM, "EMM Status;");

		if(elem1.second.EMM_Information) strcat(packetMMM, "EMM Information;");

		if(elem1.second.DownLink_NAS_Transport)	strcat(packetMMM, "DownLink NAS Transport;");

		if(elem1.second.UpLink_NAS_Transport) strcat(packetMMM, "UpLink NAS Transport;");

		if(elem1.second.CS_Service_Notification) strcat(packetMMM, "CS Service Notification;");

		if(elem1.second.DownLink_Generic_NAS_Transport)	strcat(packetMMM, "DownLink Generic NAS Transport;");

		if(elem1.second.UpLink_Generic_NAS_Transport) strcat(packetMMM, "UpLink Generic NAS Transport;");
	}
	mmmMap.clear();
}

VOID S1APFlusher::findSMM(std::map<uint32_t, SMM> &smmMap)
{
	packetSMM[0] = 0;

	for(auto elem2 : smmMap)
	{
		if(elem2.second.Activate_Default_EPS_Bearer_Context_Request) strcat(packetSMM, "Activate Default EPS Bearer Context Request;");

		if(elem2.second.Activate_Default_EPS_Bearer_Context_Accept) strcat(packetSMM, "Activate Default EPS Bearer Context Accept;");

		if(elem2.second.Activate_Default_EPS_Bearer_Context_Reject) strcat(packetSMM, "Activate Default EPS Bearer Context Reject;");

		if(elem2.second.Activate_Dedicated_EPS_Bearer_Context_Request) strcat(packetSMM, "Activate Dedicated EPS Bearer Context Request;");

		if(elem2.second.Activate_Dedicated_EPS_Bearer_Context_Accept) strcat(packetSMM, "Activate Dedicated EPS Bearer Context Accept;");

		if(elem2.second.Activate_Dedicated_EPS_Bearer_Context_Reject) strcat(packetSMM, "Activate Dedicated EPS Bearer Context Reject;");

		if(elem2.second.Modify_EPS_Bearer_Context_Request) strcat(packetSMM, "Modify EPS Bearer Context Request;");

		if(elem2.second.Modify_EPS_Bearer_Context_Accept) strcat(packetSMM, "Modify EPS Bearer Context Accept;");

		if(elem2.second.Modify_EPS_Bearer_Context_Reject) strcat(packetSMM, "Modify EPS Bearer Context Reject;");

		if(elem2.second.Deactivate_EPS_Bearer_Context_Request) strcat(packetSMM, "Deactivate EPS Bearer Context Request;");

		if(elem2.second.Deactivate_EPS_Bearer_Context_Accept) strcat(packetSMM, "Deactivate EPS Bearer Context Accept;");

		if(elem2.second.PDN_Connectivity_Request) strcat(packetSMM, "PDN Connectivity Request;");

		if(elem2.second.PDN_Connectivity_Reject) strcat(packetSMM, "PDN Connectivity Reject;");

		if(elem2.second.PDN_Disconnect_Request)	strcat(packetSMM, "PDN Disconnect Request;");

		if(elem2.second.PDN_Disconnect_Reject) strcat(packetSMM, "PDN Disconnect Reject;");

		if(elem2.second.Bearer_Resource_Allocation_Request)	strcat(packetSMM, "ESM Status;");

		if(elem2.second.Bearer_Resource_Allocation_Reject) strcat(packetSMM, "ESM Status;");

		if(elem2.second.Bearer_Resource_Modification_Request) strcat(packetSMM, "Bearer Resource Modification Request;");

		if(elem2.second.Bearer_Resource_Modification_Reject) strcat(packetSMM, "Bearer Resource Modification Reject;");

		if(elem2.second.ESM_Information_Request) strcat(packetSMM, "ESM Information Request;");

		if(elem2.second.ESM_Information_response) strcat(packetSMM, "ESM Information response;");

		if(elem2.second.Notification) strcat(packetSMM, "Notification;");

		if(elem2.second.ESM_Status)	strcat(packetSMM, "ESM Status;");
	}
	smmMap.clear();
}

VOID S1APFlusher::buildS1apSession(s1mmeSession *ps1apSession)
{
	csvXdr[0] = 0;
	char packetSeq[VPS_MAX_LEN];
	char sourceIp[16], destIp[16];

	sourceIp[0] = destIp[0] = 0;

	if(!accumulatePackets(ps1apSession, packetSeq)) return;

	lockS1apMap();
	imsi = getImsi(ps1apSession->tmsi, ps1apSession->eNodeBId);
	imei = getImei(ps1apSession->tmsi, ps1apSession->eNodeBId);
	unLockS1apMap();

	long2Ip(ps1apSession->sourceIp, sourceIp);
	long2Ip(ps1apSession->destIp, destIp);

	sprintf(csvXdr, "%s,%d,%s,%d,"
					"%s,%s,%s,%s",
					sourceIp, ps1apSession->sourcePort, destIp, ps1apSession->destPort, ps1apSession->tmsi, imsi, imei, packetSeq);

	strcpy(objXdrStore.xdr, csvXdr);
	flushS1apCsvRecords();
}

char* S1APFlusher::getImsi(char *tmsi, uint32_t eNodeB)
{
	std::map<std::string, sessionGlbData>::iterator tmsi_it = S1APStore::tmsiGlbData.find(std::string(tmsi));

	if(tmsi_it != S1APStore::tmsiGlbData.end())
	{ return (tmsi_it->second.imsi); }
	else
	{
		std::map<uint32_t, sessionGlbData>::iterator eNodeB_it = S1APStore::eNodeBGlbData.find(eNodeB);

		if(eNodeB_it != S1APStore::eNodeBGlbData.end())
		{
			strcpy(tmsi, eNodeB_it->second.tmsi);
			return (eNodeB_it->second.imsi);
		}
	}
	return "NA";
}

char* S1APFlusher::getImei(char *tmsi, uint32_t eNodeB)
{
	std::map<std::string, sessionGlbData>::iterator tmsi_it = S1APStore::tmsiGlbData.find(std::string(tmsi));

	if(tmsi_it != S1APStore::tmsiGlbData.end())
	{ return (tmsi_it->second.imei); }
	else
	{
		std::map<uint32_t, sessionGlbData>::iterator eNodeB_it = S1APStore::eNodeBGlbData.find(eNodeB);

		if(eNodeB_it != S1APStore::eNodeBGlbData.end())
		{
			strcpy(tmsi, eNodeB_it->second.tmsi);
			return (eNodeB_it->second.imei);
		}
	}
	return "NA";
}


VOID S1APFlusher::flushS1apCsvRecords()
{
	if(strlen(csvXdr) <= 0)
		return;

	int index = PKT_WRITE_TIME_INDEX(IPGlobal::CURRENT_EPOCH_SEC, IPGlobal::PKT_TIME_INDEX);

	if(IPGlobal::S1MME_WRITE_XDR)
	{
		switch(index)
		{
			case 0:
				S1APFlush::s1ap_xdr_f_0_t_0[S1APFlush::s1ap_xdr_f_0_t_0_cnt] = objXdrStore;
				S1APFlush::s1ap_xdr_f_0_t_0_cnt++;
				break;
			case 1:
				S1APFlush::s1ap_xdr_f_0_t_1[S1APFlush::s1ap_xdr_f_0_t_1_cnt] = objXdrStore;
				S1APFlush::s1ap_xdr_f_0_t_1_cnt++;
				break;
			case 2:
				S1APFlush::s1ap_xdr_f_0_t_2[S1APFlush::s1ap_xdr_f_0_t_2_cnt] = objXdrStore;
				S1APFlush::s1ap_xdr_f_0_t_2_cnt++;
				break;
			case 3:
				S1APFlush::s1ap_xdr_f_0_t_3[S1APFlush::s1ap_xdr_f_0_t_3_cnt] = objXdrStore;
				S1APFlush::s1ap_xdr_f_0_t_3_cnt++;
				break;
			case 4:
				S1APFlush::s1ap_xdr_f_0_t_4[S1APFlush::s1ap_xdr_f_0_t_4_cnt] = objXdrStore;
				S1APFlush::s1ap_xdr_f_0_t_4_cnt++;
				break;
			case 5:
				S1APFlush::s1ap_xdr_f_0_t_5[S1APFlush::s1ap_xdr_f_0_t_5_cnt] = objXdrStore;
				S1APFlush::s1ap_xdr_f_0_t_5_cnt++;
				break;
			case 6:
				S1APFlush::s1ap_xdr_f_0_t_6[S1APFlush::s1ap_xdr_f_0_t_6_cnt] = objXdrStore;
				S1APFlush::s1ap_xdr_f_0_t_6_cnt++;
				break;
			case 7:
				S1APFlush::s1ap_xdr_f_0_t_7[S1APFlush::s1ap_xdr_f_0_t_7_cnt] = objXdrStore;
				S1APFlush::s1ap_xdr_f_0_t_7_cnt++;
				break;
			case 8:
				S1APFlush::s1ap_xdr_f_0_t_8[S1APFlush::s1ap_xdr_f_0_t_8_cnt] = objXdrStore;
				S1APFlush::s1ap_xdr_f_0_t_8_cnt++;
				break;
			case 9:
				S1APFlush::s1ap_xdr_f_0_t_9[S1APFlush::s1ap_xdr_f_0_t_9_cnt] = objXdrStore;
				S1APFlush::s1ap_xdr_f_0_t_9_cnt++;
				break;
		}
	}
}

