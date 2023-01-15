/*
 * S5S8Interface.cpp
 *
 *  Created on: 21 Feb 2020
 *      Author: Debashis
 */

#include "S5S8Interface.h"

S5S8Interface::S5S8Interface(int id)
{
	this->_name = "S5S8Interface";
	this->setLogLevel(Log::theLog().level());
	this->instanceId = id;
	S5S8_InitializeSessionPool(id);

	if(this->instanceId == 0)
		S5S8_InitializeGlobalRepository();
}

S5S8Interface::~S5S8Interface()
{ }

VOID S5S8Interface::lockgSession()
{
	pthread_mutex_lock(&s5s8SessionLock::lockCount);
	while (s5s8SessionLock::count == 0){
		pthread_cond_wait(&s5s8SessionLock::nonzero, &s5s8SessionLock::lockCount);
	}
	s5s8SessionLock::count = s5s8SessionLock::count - 1;
	pthread_mutex_unlock(&s5s8SessionLock::lockCount);
}

VOID S5S8Interface::unLockgSession()
{
    pthread_mutex_lock(&s5s8SessionLock::lockCount);
    if (s5s8SessionLock::count == 0)
        pthread_cond_signal(&s5s8SessionLock::nonzero);
    s5s8SessionLock::count = s5s8SessionLock::count + 1;
    pthread_mutex_unlock(&s5s8SessionLock::lockCount);
}


VOID S5S8Interface::S5S8_InitializeSessionPool(int id)
{
	s5s8freeBitPosMax = S5S8_SESSION_POOL_ARRAY_ELEMENTS * S5S8_SESSION_POOL_ARRAY_SIZE;

	for(int i = 0; i < S5S8_SESSION_POOL_ARRAY_SIZE; i++)
	{
		s5s8SessionBitFlags[i].reset();

		for(int j = 0; j < S5S8_SESSION_POOL_ARRAY_ELEMENTS; j++)
			S5S8_SessionPool[i][j] = new GTPSession();
	}
	printf("S5S8Interface [%02d]	Initializing [%d] Session Pool Completed.\n", id, s5s8freeBitPosMax);
	TheLog_nc_v2(Log::Info, name(),"   S5S8Interface [%02d] Initializing [%d] Session Pool Completed.", id, s5s8freeBitPosMax);
}

VOID S5S8Interface::S5S8_InitializeGlobalRepository()
{
	GTPStore::S5S8FreeGlbBitPos = -1;
	GTPStore::S5S8FreeGlbBitPosMax = S5S8_SESSION_POOL_ARRAY_ELEMENTS * S5S8_SESSION_POOL_ARRAY_SIZE;

	for(int n = 0; n < S5S8_SESSION_POOL_ARRAY_SIZE; n++)
	{
		GTPStore::S5S8GlbBitFlags[n].reset();

		for(int i = 0; i < S5S8_SESSION_POOL_ARRAY_ELEMENTS; i++)
			GTPStore::S5S8_GlbSessionPool[n][i] = new GTPSession();
	}

	printf("GTPInterface Initializing [%08lu]  S5S8 Global Session Pool... Completed\n", S5S8_SESSION_POOL_ARRAY_ELEMENTS * S5S8_SESSION_POOL_ARRAY_SIZE);
	TheLog_nc_v1(Log::Info, name()," S5S8 Global Session Initializing for [%'08lu] entries...Completed", S5S8_SESSION_POOL_ARRAY_ELEMENTS * S5S8_SESSION_POOL_ARRAY_SIZE);
}

GTPSession* S5S8Interface::S5S8_GetSessionFromPool(int idx)
{
	int arrId = idx / S5S8_SESSION_POOL_ARRAY_ELEMENTS;
	int bitId = idx % S5S8_SESSION_POOL_ARRAY_ELEMENTS;
	return S5S8_SessionPool[arrId][bitId];
}

int S5S8Interface::S5S8_GetFreeIndex()
{
	S5S8FreeBitPos++;
	if(S5S8FreeBitPos >= s5s8freeBitPosMax) S5S8FreeBitPos = 0;
	int arrId = S5S8FreeBitPos / S5S8_SESSION_POOL_ARRAY_ELEMENTS;
	int bitId = S5S8FreeBitPos % S5S8_SESSION_POOL_ARRAY_ELEMENTS;

	while(s5s8SessionBitFlags[arrId].test(bitId)){
		S5S8FreeBitPos++;
		if(S5S8FreeBitPos >= s5s8freeBitPosMax) S5S8FreeBitPos = 0;
		arrId = S5S8FreeBitPos / S5S8_SESSION_POOL_ARRAY_ELEMENTS;
		bitId = S5S8FreeBitPos % S5S8_SESSION_POOL_ARRAY_ELEMENTS;
	}
	if(S5S8FreeBitPos >= s5s8freeBitPosMax){
		printf("S5S8 S5S8FreeBitPos [%d] >= S5S8freeBitPosMax [%d]\n", S5S8FreeBitPos, s5s8freeBitPosMax);
	}
	s5s8SessionBitFlags[arrId].set(bitId);
	return S5S8FreeBitPos;
}

VOID S5S8Interface::S5S8_ReleaseIndexFromSessionPool(int idx)
{
	int arrId = idx / S5S8_SESSION_POOL_ARRAY_ELEMENTS;
	int bitId = idx % S5S8_SESSION_POOL_ARRAY_ELEMENTS;
	S5S8_SessionPool[arrId][bitId]->reset();
	s5s8SessionBitFlags[arrId].reset(bitId);
}

uint32_t S5S8Interface::S5S8_GetGlbFreeIndex()
{
	GTPStore::S5S8FreeGlbBitPos++;
	if(GTPStore::S5S8FreeGlbBitPos >= GTPStore::S5S8FreeGlbBitPosMax) GTPStore::S5S8FreeGlbBitPos = 0;
	int arrId = GTPStore::S5S8FreeGlbBitPos / S5S8_SESSION_POOL_ARRAY_ELEMENTS;
	int bitId = GTPStore::S5S8FreeGlbBitPos % S5S8_SESSION_POOL_ARRAY_ELEMENTS;

	while(GTPStore::S5S8GlbBitFlags[arrId].test(bitId)){
		GTPStore::S5S8FreeGlbBitPos++;
		if(GTPStore::S5S8FreeGlbBitPos >= GTPStore::S5S8FreeGlbBitPosMax) GTPStore::S5S8FreeGlbBitPos = 0;
		arrId = GTPStore::S5S8FreeGlbBitPos / S5S8_SESSION_POOL_ARRAY_ELEMENTS;
		bitId = GTPStore::S5S8FreeGlbBitPos % S5S8_SESSION_POOL_ARRAY_ELEMENTS;
	}
	if(GTPStore::S5S8FreeGlbBitPos >= GTPStore::S5S8FreeGlbBitPosMax){
		printf(" getGlbFreeIndex GTPStore::S5S8FreeGlbBitPos [%lu] >= GTPStore::GTPcV2FreeGlbBitPosMax [%lu]\n",
				 GTPStore::S5S8FreeGlbBitPos, GTPStore::S5S8FreeGlbBitPosMax);
	}
	GTPStore::S5S8GlbBitFlags[arrId].set(bitId);
	GTPStats::gtp_glb_sessions_op_cr_cnt++;
	GTPStats::gtp_glb_sessions_bit_index = GTPStore::S5S8FreeGlbBitPos;
	return GTPStore::S5S8FreeGlbBitPos;
}

VOID S5S8Interface::S5S8_DeleteGlbSession(GTPSession *pGtpGlobalSession, int index)
{
	if(pGtpGlobalSession->SGW_ctl_teid != 0)
	{
		std::map<uint32_t, int>::iterator itr = GTPStore::S5S8_GlbSgwCtlIndexPool[INDEX_TEID(pGtpGlobalSession->SGW_ctl_teid)].find(pGtpGlobalSession->SGW_ctl_teid);

		if(itr != GTPStore::S5S8_GlbSgwCtlIndexPool[INDEX_TEID(pGtpGlobalSession->SGW_ctl_teid)].end())
			GTPStore::S5S8_GlbSgwCtlIndexPool[INDEX_TEID(pGtpGlobalSession->SGW_ctl_teid)].erase(itr->first);
	}

	if(pGtpGlobalSession->PGW_ctl_teid != 0)
	{
		std::map<uint32_t, int>::iterator itr = GTPStore::S5S8_GlbPgwCtlIndexPool[INDEX_TEID(pGtpGlobalSession->PGW_ctl_teid)].find(pGtpGlobalSession->PGW_ctl_teid);

		if(itr != GTPStore::S5S8_GlbPgwCtlIndexPool[INDEX_TEID(pGtpGlobalSession->PGW_ctl_teid)].end())
			GTPStore::S5S8_GlbPgwCtlIndexPool[INDEX_TEID(pGtpGlobalSession->PGW_ctl_teid)].erase(itr->first);
	}
	S5S8_ReleaseIndexFromGlbPool(index);
}

VOID S5S8Interface::S5S8_ReleaseIndexFromGlbPool(int glbIndex)
{
	int arrId = glbIndex / S5S8_SESSION_POOL_ARRAY_ELEMENTS;
	int bitId = glbIndex % S5S8_SESSION_POOL_ARRAY_ELEMENTS;

	GTPStore::S5S8_GlbSessionPool[arrId][bitId]->reset();
	GTPStore::S5S8GlbBitFlags[arrId].reset(bitId);
}

VOID S5S8Interface::S5S8_ProcessMsgType(MPacket *msgObj)
{
	switch(msgObj->gtpcMsgType)
	{
		case CREATE_SESSION_REQUEST:
					S5S8_CreateSessionReq(msgObj);
					break;

		case CREATE_SESSION_RESPONSE:
				S5S8_CreateSessionRsp(msgObj);
				break;

		case MODIFY_BEARER_REQUEST:
				S5S8_ModifyBearerReq(msgObj);
				break;

		case MODIFY_BEARER_RESPONSE:
				S5S8_ModifyBearerRsp(msgObj);
			break;

		case DELETE_SESSION_REQUEST:
				S5S8_DeleteSessionReq(msgObj);
				break;

		case DELETE_SESSION_RESPONSE:
				S5S8_DeleteSessionRsp(msgObj);
				break;

		case UPDATE_BEARER_REQUEST:
				S5S8_UpdateBearerReq(msgObj);
				break;

		case UPDATE_BEARER_RESPONSE:
				S5S8_UpdateBearerRsp(msgObj);
				break;
	}
}

VOID S5S8Interface::S5S8_CreateSessionReq(MPacket *msgObj)
{
	GTPSession *pGtpSession;

	std::map<uint32_t, int>::iterator it = S5S8_CSIndexPool.find(msgObj->SGW_ctl_teid);

	if(it != S5S8_CSIndexPool.end())
	{
		pGtpSession = S5S8_GetSessionFromPool(it->second);

		if(pGtpSession->GTPRspMsgId == CREATE_SESSION_RESPONSE && pGtpSession->resSeqNo == msgObj->gtpcV2PktSeqNo)	//Response has arrieved before Req
		{
				S5S8_ProcessRequest(false, pGtpSession, msgObj);
				if(pGtpSession->EndCauseId == GTPv2_ACCEPT) {
					lockgSession();
					S5S8_CreateGlobalTable(pGtpSession);
					unLockgSession();
				}
				S5S8_FlushSession(pGtpSession, FLUSH_TYPE_CR_REQ_RESREQ);
				S5S8_ReleaseIndexFromSessionPool(pGtpSession->poolIndex);
				S5S8_CSIndexPool.erase(msgObj->SGW_ctl_teid);
				return;
		}
	}
	else /* New Create Session */
	{
		int poolIndex = S5S8_GetFreeIndex();
		pGtpSession = S5S8_GetSessionFromPool(poolIndex);
		pGtpSession->poolIndex = poolIndex;
		ptr = S5S8_CSIndexPool.insert(pair<uint32_t, int>(msgObj->SGW_ctl_teid, poolIndex));

		sprintf(pGtpSession->SessionId, "%07u-%07u",IPGlobal::CURRENT_EPOCH_SEC, msgObj->gtpcV2PktSeqNo);
		S5S8_ProcessRequest(true, pGtpSession, msgObj);
	}
}

VOID S5S8Interface::S5S8_CreateSessionRsp(MPacket *msgObj)
{
	GTPSession *pGtpSession;

	std::map<uint32_t, int>::iterator it = S5S8_CSIndexPool.find(msgObj->gtpc_PktTeid);

	if(it != S5S8_CSIndexPool.end())
	{
		pGtpSession = S5S8_GetSessionFromPool(it->second);

		if(pGtpSession->GTPReqMsgId == CREATE_SESSION_REQUEST && pGtpSession->reqSeqNo == msgObj->gtpcV2PktSeqNo)	//Response has arrieved after Req
		{
				S5S8_ProcessResponse(false, pGtpSession, msgObj);

				if(pGtpSession->EndCauseId == GTPv2_ACCEPT)
				{
					lockgSession();
					S5S8_CreateGlobalTable(pGtpSession);
					unLockgSession();
				}
				S5S8_FlushSession(pGtpSession, FLUSH_TYPE_CR_RES_REQRES);
				S5S8_ReleaseIndexFromSessionPool(pGtpSession->poolIndex);
				S5S8_CSIndexPool.erase(msgObj->gtpc_PktTeid);
				return;
		}
	}
	else
	{
		int poolIndex = S5S8_GetFreeIndex();
		pGtpSession = S5S8_GetSessionFromPool(poolIndex);
		pGtpSession->poolIndex = poolIndex;
		ptr = S5S8_CSIndexPool.insert(pair<uint32_t, int>(msgObj->gtpc_PktTeid, poolIndex));

		sprintf(pGtpSession->SessionId, "%07u-%07u",IPGlobal::CURRENT_EPOCH_SEC, msgObj->gtpcV2PktSeqNo);
		S5S8_ProcessResponse(true, pGtpSession, msgObj);
	}
}

VOID S5S8Interface::S5S8_ModifyBearerReq(MPacket *msgObj)
{
	GTPSession *pGtpSession;

	std::map<uint32_t, int>::iterator it = S5S8_MBIndexPool.find(msgObj->gtpcV2PktSeqNo);
	if(it != S5S8_MBIndexPool.end())
	{
		pGtpSession = S5S8_GetSessionFromPool(it->second);

		if(pGtpSession->GTPRspMsgId == MODIFY_BEARER_RESPONSE)	//Response has arrieved before Req
		{
				S5S8_ProcessRequest(false, pGtpSession, msgObj);
				S5S8_FlushSession(pGtpSession, FLUSH_TYPE_CR_REQ_RESREQ);
				S5S8_ReleaseIndexFromSessionPool(pGtpSession->poolIndex);
				S5S8_MBIndexPool.erase(msgObj->gtpcV2PktSeqNo);
				return;
		}
	}
	else
	{
		int poolIndex = S5S8_GetFreeIndex();
		pGtpSession = S5S8_GetSessionFromPool(poolIndex);
		pGtpSession->poolIndex = poolIndex;
		ptr = S5S8_MBIndexPool.insert(pair<uint32_t, int>(msgObj->gtpcV2PktSeqNo, poolIndex));

		sprintf(pGtpSession->SessionId, "%07u-%07u",IPGlobal::CURRENT_EPOCH_SEC, msgObj->gtpcV2PktSeqNo);
		S5S8_ProcessRequest(true, pGtpSession, msgObj);

		lockgSession();
		S5S8_UpdateGlobalTable(pGtpSession, msgObj, MODIFY_BEARER_REQUEST);
		unLockgSession();

	}
}

VOID S5S8Interface::S5S8_ModifyBearerRsp(MPacket *msgObj)
{
	GTPSession *pGtpSession;

	std::map<uint32_t, int>::iterator it = S5S8_MBIndexPool.find(msgObj->gtpcV2PktSeqNo);

	if(it != S5S8_MBIndexPool.end())
	{
		pGtpSession = S5S8_GetSessionFromPool(it->second);

		if(pGtpSession->GTPReqMsgId == MODIFY_BEARER_REQUEST)	//Response has arrieved after Req
		{
				S5S8_ProcessResponse(false, pGtpSession, msgObj);
				S5S8_FlushSession(pGtpSession, FLUSH_TYPE_CR_RES_REQRES);
				S5S8_ReleaseIndexFromSessionPool(pGtpSession->poolIndex);
				S5S8_MBIndexPool.erase(msgObj->gtpcV2PktSeqNo);
				return;
		}
	}
	else
	{
		int poolIndex = S5S8_GetFreeIndex();
		pGtpSession = S5S8_GetSessionFromPool(poolIndex);
		pGtpSession->poolIndex = poolIndex;
		ptr = S5S8_MBIndexPool.insert(pair<uint32_t, int>(msgObj->gtpcV2PktSeqNo, poolIndex));

		sprintf(pGtpSession->SessionId, "%07u-%07u",IPGlobal::CURRENT_EPOCH_SEC, msgObj->gtpcV2PktSeqNo);
		S5S8_ProcessResponse(true, pGtpSession, msgObj);
	}
}

VOID S5S8Interface::S5S8_DeleteSessionReq(MPacket *msgObj)
{
	GTPSession *pGtpSession;
	uint32_t key = msgObj->gtpcV2PktSeqNo;

	if(key == 0) return;

	std::map<uint32_t, int>::iterator it = S5S8_DSIndexPool.find(msgObj->gtpcV2PktSeqNo);
	if(it != S5S8_DSIndexPool.end())
	{
		pGtpSession = S5S8_GetSessionFromPool(it->second);

		if(pGtpSession->GTPRspMsgId == DELETE_SESSION_RESPONSE && pGtpSession->resSeqNo == msgObj->gtpcV2PktSeqNo)	//Response has arrieved before Req
		{
				S5S8_ProcessRequest(false, pGtpSession, msgObj);
				S5S8_FlushSession(pGtpSession, FLUSH_TYPE_CR_REQ_RESREQ);
				S5S8_ReleaseIndexFromSessionPool(pGtpSession->poolIndex);
				S5S8_DSIndexPool.erase(msgObj->gtpcV2PktSeqNo);
				return;
		}
	}
	else
	{
		int poolIndex = S5S8_GetFreeIndex();
		pGtpSession = S5S8_GetSessionFromPool(poolIndex);
		pGtpSession->poolIndex = poolIndex;
		ptr = S5S8_DSIndexPool.insert(pair<uint32_t, int>(msgObj->gtpcV2PktSeqNo, poolIndex));

		sprintf(pGtpSession->SessionId, "%07u-%07u",IPGlobal::CURRENT_EPOCH_SEC, msgObj->gtpcV2PktSeqNo);
		S5S8_ProcessRequest(true, pGtpSession, msgObj);

		lockgSession();
		S5S8_UpdateGlobalTable(pGtpSession, msgObj, DELETE_SESSION_REQUEST);
		unLockgSession();
	}
}

VOID S5S8Interface::S5S8_DeleteSessionRsp(MPacket *msgObj)
{
	GTPSession *pGtpSession;
	uint32_t key = msgObj->gtpcV2PktSeqNo;

	if (key == 0) return;

	std::map<uint32_t, int>::iterator it = S5S8_DSIndexPool.find(msgObj->gtpcV2PktSeqNo);

	if(it != S5S8_DSIndexPool.end())
	{
		pGtpSession = S5S8_GetSessionFromPool(it->second);

		if(pGtpSession->GTPReqMsgId == DELETE_SESSION_REQUEST && pGtpSession->reqSeqNo == msgObj->gtpcV2PktSeqNo)	//Response has arrieved after Req
		{
				S5S8_ProcessResponse(false, pGtpSession, msgObj);
				S5S8_FlushSession(pGtpSession, FLUSH_TYPE_CR_RES_REQRES);
				S5S8_ReleaseIndexFromSessionPool(pGtpSession->poolIndex);
				S5S8_DSIndexPool.erase(msgObj->gtpcV2PktSeqNo);
				return;
		}
	}
	else
	{
		int poolIndex = S5S8_GetFreeIndex();
		pGtpSession = S5S8_GetSessionFromPool(poolIndex);
		pGtpSession->poolIndex = poolIndex;
		ptr = S5S8_DSIndexPool.insert(pair<uint32_t, int>(msgObj->gtpcV2PktSeqNo, poolIndex));

		sprintf(pGtpSession->SessionId, "%07u-%07u",IPGlobal::CURRENT_EPOCH_SEC, msgObj->gtpcV2PktSeqNo);
		S5S8_ProcessResponse(true, pGtpSession, msgObj);
	}
}

VOID S5S8Interface::S5S8_UpdateBearerReq(MPacket *msgObj)
{
	GTPSession *pGtpSession;

	std::map<uint32_t, int>::iterator it = S5S8_UBIndexPool.find(msgObj->gtpcV2PktSeqNo);

	if(it != S5S8_UBIndexPool.end())
	{
		pGtpSession = S5S8_GetSessionFromPool(it->second);

		if(pGtpSession->GTPRspMsgId == UPDATE_BEARER_RESPONSE)	//Response has arrieved before Req
		{
				S5S8_ProcessRequest(false, pGtpSession, msgObj);
				S5S8_FlushSession(pGtpSession, FLUSH_TYPE_CR_REQ_RESREQ);
				S5S8_ReleaseIndexFromSessionPool(pGtpSession->poolIndex);
				S5S8_UBIndexPool.erase(msgObj->gtpcV2PktSeqNo);
				return;
		}
	}
	else /* New Create Session */
	{
		int poolIndex = S5S8_GetFreeIndex();
		pGtpSession = S5S8_GetSessionFromPool(poolIndex);
		pGtpSession->poolIndex = poolIndex;
		ptr = S5S8_UBIndexPool.insert(pair<uint32_t, int>(msgObj->gtpcV2PktSeqNo, poolIndex));

		sprintf(pGtpSession->SessionId, "%07u-%07u",IPGlobal::CURRENT_EPOCH_SEC, msgObj->gtpcV2PktSeqNo);
		S5S8_ProcessRequest(true, pGtpSession, msgObj);

		lockgSession();
		S5S8_UpdateGlobalTable(pGtpSession, msgObj, UPDATE_BEARER_RESPONSE);
		unLockgSession();
	}
}

VOID S5S8Interface::S5S8_UpdateBearerRsp(MPacket *msgObj)
{
	GTPSession *pGtpSession;

	std::map<uint32_t, int>::iterator it = S5S8_UBIndexPool.find(msgObj->gtpcV2PktSeqNo);

	if(it != S5S8_UBIndexPool.end())
	{
		pGtpSession = S5S8_GetSessionFromPool(it->second);

		if(pGtpSession->GTPReqMsgId == UPDATE_BEARER_REQUEST)	//Response has arrieved after Req
		{
				S5S8_ProcessResponse(false, pGtpSession, msgObj);
				S5S8_FlushSession(pGtpSession, FLUSH_TYPE_CR_RES_REQRES);
				S5S8_ReleaseIndexFromSessionPool(pGtpSession->poolIndex);
				S5S8_UBIndexPool.erase(msgObj->gtpcV2PktSeqNo);
				return;
		}
	}
	else
	{
		int poolIndex = S5S8_GetFreeIndex();
		pGtpSession = S5S8_GetSessionFromPool(poolIndex);
		pGtpSession->poolIndex = poolIndex;
		ptr = S5S8_UBIndexPool.insert(pair<uint32_t, int>(msgObj->gtpcV2PktSeqNo, poolIndex));

		sprintf(pGtpSession->SessionId, "%07u-%07u",IPGlobal::CURRENT_EPOCH_SEC, msgObj->gtpcV2PktSeqNo);
		S5S8_ProcessResponse(true, pGtpSession, msgObj);
	}
}

VOID S5S8Interface::S5S8_ProcessRequest(bool createFlag, GTPSession *gtpSession, MPacket *msgObj)
{
	gtpSession->StartTimeEpochSec 	= IPGlobal::CURRENT_EPOCH_SEC;
	gtpSession->gtpcVersion			= msgObj->gtpcVersion;
	gtpSession->GTPReqMsgId 		= msgObj->gtpcMsgType;
//	gtpSession->dirMmeSgw 			= msgObj->dirUserNetwork;
	gtpSession->VLanId 				= msgObj->ethVLanId;
	gtpSession->ByteSizeUL 			= msgObj->gtpcMsgLen;
	gtpSession->sourceIp			= msgObj->sourceIpAddrLong;
	gtpSession->destIp				= msgObj->destIpAddrLong;

	switch(msgObj->gtpcMsgType)
	{
		case CREATE_SESSION_REQUEST:
				delimiter = "-";
				gtpSession->SGW_ctl_teid 	= msgObj->SGW_ctl_teid;
				gtpSession->SGW_s1u_teid 	= msgObj->SGW_s1u_teid;
				gtpSession->RAT				= msgObj->gtpcRAT;
				gtpSession->TAC 			= msgObj->TAC;
				gtpSession->cellId 			= msgObj->cellId;
				gtpSession->req_mbrupl 		= msgObj->gtpcMbrupl;
				gtpSession->req_mbrdnl 		= msgObj->gtpcMbrdnl;

				strcpy(gtpSession->IMSI, msgObj->IMSI);
				strcpy(gtpSession->IMEI, msgObj->IMEI);
				strcpy(gtpSession->MSISDN, msgObj->MSISDN);
				strcpy(gtpSession->pdnAddress, msgObj->pdnAddrAllocation);
				strcpy(gtpSession->PDNType, msgObj->pdnType);
				strcpy(gtpSession->sgwIPAddrChar, msgObj->SGWAddress);

				if(strlen(msgObj->gtpcAPN) > 2) strcpy(gtpSession->APN, &msgObj->gtpcAPN[1]);
				else strcpy(gtpSession->APN, &msgObj->gtpcAPN[0]);

				mcc_mnc.assign(msgObj->MCCMNC);

				pos = 0;

				while ((pos = mcc_mnc.find(delimiter)) != std::string::npos) {
				    token = mcc_mnc.substr(0, pos);
				    gtpSession->MCC = atoi((const char *)token.c_str());
				    mcc_mnc.erase(0, pos + delimiter.length());
				}
				gtpSession->MNC = atoi((const char *)mcc_mnc.c_str());

				break;

		case MODIFY_BEARER_REQUEST:
				gtpSession->PGW_ctl_teid 	= msgObj->gtpc_PktTeid;
				gtpSession->RAT				= msgObj->gtpcRAT;
				gtpSession->eNodeB 			= msgObj->eNodeB;
				gtpSession->cellId 			= msgObj->cellId;

				mcc_mnc.assign(msgObj->MCCMNC);

				pos = 0;

				while ((pos = mcc_mnc.find(delimiter)) != std::string::npos) {
				    token = mcc_mnc.substr(0, pos);
				    gtpSession->MCC = atoi((const char *)token.c_str());
				    mcc_mnc.erase(0, pos + delimiter.length());
				}
				gtpSession->MNC = atoi((const char *)mcc_mnc.c_str());

				break;

		case DELETE_SESSION_REQUEST:
				gtpSession->PGW_ctl_teid = msgObj->gtpc_PktTeid;
				break;

		case UPDATE_BEARER_REQUEST:
				gtpSession->PGW_ctl_teid = msgObj->gtpc_PktTeid;
				gtpSession->req_mbrupl 		= msgObj->gtpcMbrupl;
				gtpSession->req_mbrdnl 		= msgObj->gtpcMbrdnl;
				break;

		default:
				break;
	}

	gtpSession->reqSeqNo	= msgObj->gtpcV2PktSeqNo;
}

VOID S5S8Interface::S5S8_ProcessResponse(bool cteateFlag, GTPSession *gtpSession, MPacket *msgObj)
{
	gtpSession->GTPRspMsgId 	= msgObj->gtpcMsgType;
	gtpSession->EndTimeEpochSec = IPGlobal::CURRENT_EPOCH_SEC;
	gtpSession->ByteSizeDL 		= msgObj->gtpcMsgLen;
	gtpSession->resSeqNo 		= msgObj->gtpcV2PktSeqNo;
	gtpSession->EndCauseId 		= msgObj->gtpcCauseCode;

	switch(msgObj->gtpcMsgType)
	{
		case CREATE_SESSION_RESPONSE:
				gtpSession->PGW_ctl_teid 	= msgObj->PGW_ctl_teid;
				gtpSession->PGW_s1u_teid 	= msgObj->PGW_s1u_teid;

				gtpSession->res_mbrupl 		= msgObj->gtpcMbrupl;
				gtpSession->res_mbrdnl 		= msgObj->gtpcMbrdnl;
				strcpy(gtpSession->pdnAddress, msgObj->pdnAddrAllocation);
				strcpy(gtpSession->pgwIPAddrChar, msgObj->PGWAddress);
				break;

		case MODIFY_BEARER_RESPONSE:
				gtpSession->SGW_ctl_teid 	= msgObj->gtpc_PktTeid;
				strcpy(gtpSession->IMSI, msgObj->IMSI);
				strcpy(gtpSession->IMEI, msgObj->IMEI);
				strcpy(gtpSession->MSISDN, msgObj->MSISDN);
				gtpSession->res_mbrupl 		= msgObj->gtpcMbrupl;
				gtpSession->res_mbrdnl 		= msgObj->gtpcMbrdnl;

				break;

		case DELETE_SESSION_RESPONSE:
				gtpSession->SGW_ctl_teid 	= msgObj->gtpc_PktTeid;
				break;

		case UPDATE_BEARER_RESPONSE:
				gtpSession->SGW_ctl_teid = msgObj->gtpc_PktTeid;
				gtpSession->res_mbrupl 		= msgObj->gtpcMbrupl;
				gtpSession->res_mbrdnl 		= msgObj->gtpcMbrdnl;

				mcc_mnc.assign(msgObj->MCCMNC);

				pos = 0;

				while ((pos = mcc_mnc.find(delimiter)) != std::string::npos) {
				    token = mcc_mnc.substr(0, pos);
				    gtpSession->MCC = atoi((const char *)token.c_str());
				    mcc_mnc.erase(0, pos + delimiter.length());
				}
				gtpSession->MNC = atoi((const char *)mcc_mnc.c_str());

				gtpSession->TAC 			= msgObj->TAC;
				gtpSession->cellId 			= msgObj->cellId;

				break;
		default:
			break;
	}
}

VOID S5S8Interface::S5S8_CreateGlobalTable(GTPSession *pGtpSession)
{
	int glbIndex 	= -1;
	int arrid 		= 0;
	int elemid 		= 0;

	if((pGtpSession->SGW_ctl_teid == 0) || (pGtpSession->PGW_ctl_teid == 0))
		return;

	pGtpSession->lastActivityTime = pGtpSession->StartTimeEpochSec;

	glbIndex = S5S8_GetGlbFreeIndex();

	arrid 	= glbIndex / S5S8_SESSION_POOL_ARRAY_ELEMENTS;  	// 200
	elemid 	= glbIndex % S5S8_SESSION_POOL_ARRAY_ELEMENTS; 	// 200

	GTPStore::S5S8_GlbSessionPool[arrid][elemid]->copy(pGtpSession);

	GTPStore::S5S8_GlbSessionPool[arrid][elemid]->active_session 	= true;
	GTPStore::S5S8_GlbSessionPool[arrid][elemid]->expiredFlag 		= false;

	/* Till Create Session Request & Response to get
	 * MME & SGW Control Tunnel Id and SGW Bearer Tunnel Id
	 * eNodeB Bearer Tunnel Id we get in Modify Bearer Request
	 */
	GTPStore::S5S8_GlbSgwCtlIndexPool[INDEX_TEID(pGtpSession->SGW_ctl_teid)][pGtpSession->SGW_ctl_teid] = glbIndex;
	GTPStore::S5S8_GlbPgwCtlIndexPool[INDEX_TEID(pGtpSession->PGW_ctl_teid)][pGtpSession->PGW_ctl_teid] = glbIndex;
}

int S5S8Interface::S5S8_GetGlbIndex(const uint32_t tunnelId, TIED_TYPE_V2 type)
{
	uint32_t teidIndex = INDEX_TEID(tunnelId);

	std::map<uint32_t, int>::iterator itr;

	switch(type)
	{
		case PGW_CTL:
		{
				itr = GTPStore::S5S8_GlbPgwCtlIndexPool[teidIndex].find(tunnelId);
				if (itr != GTPStore::S5S8_GlbPgwCtlIndexPool[teidIndex].end())
					return itr->second;
		}
		break;

		case SGW_CTL:
		{
				itr = GTPStore::S5S8_GlbSgwCtlIndexPool[teidIndex].find(tunnelId);

				if (itr != GTPStore::S5S8_GlbSgwCtlIndexPool[teidIndex].end())
					return itr->second;
		}
		break;
	}
	return -1;
}

VOID S5S8Interface::S5S8_UpdateGlobalTable(GTPSession *pGtpSession, MPacket *msgObj, int msgType)
{
	int glbIndex = -1;

	GTPSession *pGlbSession = NULL;

	if(pGtpSession->SGW_ctl_teid > 0)
	{
		glbIndex = S5S8_GetGlbIndex(pGtpSession->SGW_ctl_teid, SGW_CTL);

		if(glbIndex == -1)
			glbIndex = S5S8_GetGlbIndex(pGtpSession->PGW_ctl_teid, PGW_CTL);
	}

	if(glbIndex == -1)
	{ return; }
	else if(glbIndex >= 0)
	{
		int arrid = glbIndex / S5S8_SESSION_POOL_ARRAY_ELEMENTS;
		int elemid = glbIndex % S5S8_SESSION_POOL_ARRAY_ELEMENTS;

		std::map<int, GTPSession*>::iterator itrGlb = GTPStore::S5S8_GlbSessionPool[arrid].find(elemid);
		if(itrGlb != GTPStore::S5S8_GlbSessionPool[arrid].end())
			pGlbSession = itrGlb->second;
	}

	if(pGlbSession == NULL) return;

	pGlbSession->lastActivityTime = IPGlobal::CURRENT_EPOCH_SEC;

	switch(msgType)
	{
		case DELETE_SESSION_RESPONSE:
				pGlbSession->active_session 	= false;
				pGlbSession->expiredFlag 		= true;
				break;
	}

	pGtpSession->RAT 				= pGlbSession->RAT;
	pGtpSession->MCC 				= pGlbSession->MCC;
	pGtpSession->MNC 				= pGlbSession->MNC;
	pGtpSession->cellId 			= pGlbSession->cellId;
	pGtpSession->RAT 				= pGlbSession->RAT;
	strcpy(pGtpSession->IMSI, pGlbSession->IMSI);
	strcpy(pGtpSession->IMEI, pGlbSession->IMEI);
	strcpy(pGtpSession->MSISDN, pGlbSession->MSISDN);
}

VOID S5S8Interface::S5S8_FlushSession(GTPSession *pGTPSession, int flushType)
{
	int idx = PKT_WRITE_TIME_INDEX(IPGlobal::CURRENT_EPOCH_SEC, 10);

	pGTPSession->flushType = flushType;
	pGTPSession->FlushTimeEpochMicroSec = IPGlobal::CURRENT_EPOCH_MICRO_SEC;

	switch(instanceId)
	{
		case 0:
			switch(idx)
			{
				case 0:
					S5S8FlushRepository::s5s8FlushMap_sm_0_t_0[S5S8FlushRepository::s5s8FlushMap_sm_0_t_0_cnt].copy(pGTPSession);
					S5S8FlushRepository::s5s8FlushMap_sm_0_t_0_cnt++;
					break;
				case 1:
					S5S8FlushRepository::s5s8FlushMap_sm_0_t_1[S5S8FlushRepository::s5s8FlushMap_sm_0_t_1_cnt].copy(pGTPSession);
					S5S8FlushRepository::s5s8FlushMap_sm_0_t_1_cnt++;
					break;
				case 2:
					S5S8FlushRepository::s5s8FlushMap_sm_0_t_2[S5S8FlushRepository::s5s8FlushMap_sm_0_t_2_cnt].copy(pGTPSession);
					S5S8FlushRepository::s5s8FlushMap_sm_0_t_2_cnt++;
					break;
				case 3:
					S5S8FlushRepository::s5s8FlushMap_sm_0_t_3[S5S8FlushRepository::s5s8FlushMap_sm_0_t_3_cnt].copy(pGTPSession);
					S5S8FlushRepository::s5s8FlushMap_sm_0_t_3_cnt++;
					break;
				case 4:
					S5S8FlushRepository::s5s8FlushMap_sm_0_t_4[S5S8FlushRepository::s5s8FlushMap_sm_0_t_4_cnt].copy(pGTPSession);
					S5S8FlushRepository::s5s8FlushMap_sm_0_t_4_cnt++;
					break;
				case 5:
					S5S8FlushRepository::s5s8FlushMap_sm_0_t_5[S5S8FlushRepository::s5s8FlushMap_sm_0_t_5_cnt].copy(pGTPSession);
					S5S8FlushRepository::s5s8FlushMap_sm_0_t_5_cnt++;
					break;
				case 6:
					S5S8FlushRepository::s5s8FlushMap_sm_0_t_6[S5S8FlushRepository::s5s8FlushMap_sm_0_t_6_cnt].copy(pGTPSession);
					S5S8FlushRepository::s5s8FlushMap_sm_0_t_6_cnt++;
					break;
				case 7:
					S5S8FlushRepository::s5s8FlushMap_sm_0_t_7[S5S8FlushRepository::s5s8FlushMap_sm_0_t_7_cnt].copy(pGTPSession);
					S5S8FlushRepository::s5s8FlushMap_sm_0_t_7_cnt++;
					break;
				case 8:
					S5S8FlushRepository::s5s8FlushMap_sm_0_t_8[S5S8FlushRepository::s5s8FlushMap_sm_0_t_8_cnt].copy(pGTPSession);
					S5S8FlushRepository::s5s8FlushMap_sm_0_t_8_cnt++;
					break;
				case 9:
					S5S8FlushRepository::s5s8FlushMap_sm_0_t_9[S5S8FlushRepository::s5s8FlushMap_sm_0_t_9_cnt].copy(pGTPSession);
					S5S8FlushRepository::s5s8FlushMap_sm_0_t_9_cnt++;
					break;
			}
			break;

		case 1:
			switch(idx)
			{
				case 0:
					S5S8FlushRepository::s5s8FlushMap_sm_1_t_0[S5S8FlushRepository::s5s8FlushMap_sm_1_t_0_cnt].copy(pGTPSession);
					S5S8FlushRepository::s5s8FlushMap_sm_1_t_0_cnt++;
					break;
				case 1:
					S5S8FlushRepository::s5s8FlushMap_sm_1_t_1[S5S8FlushRepository::s5s8FlushMap_sm_1_t_1_cnt].copy(pGTPSession);
					S5S8FlushRepository::s5s8FlushMap_sm_1_t_1_cnt++;
					break;
				case 2:
					S5S8FlushRepository::s5s8FlushMap_sm_1_t_2[S5S8FlushRepository::s5s8FlushMap_sm_1_t_2_cnt].copy(pGTPSession);
					S5S8FlushRepository::s5s8FlushMap_sm_1_t_2_cnt++;
					break;
				case 3:
					S5S8FlushRepository::s5s8FlushMap_sm_1_t_3[S5S8FlushRepository::s5s8FlushMap_sm_1_t_3_cnt].copy(pGTPSession);
					S5S8FlushRepository::s5s8FlushMap_sm_1_t_3_cnt++;
					break;
				case 4:
					S5S8FlushRepository::s5s8FlushMap_sm_1_t_4[S5S8FlushRepository::s5s8FlushMap_sm_1_t_4_cnt].copy(pGTPSession);
					S5S8FlushRepository::s5s8FlushMap_sm_1_t_4_cnt++;
					break;
				case 5:
					S5S8FlushRepository::s5s8FlushMap_sm_1_t_5[S5S8FlushRepository::s5s8FlushMap_sm_1_t_5_cnt].copy(pGTPSession);
					S5S8FlushRepository::s5s8FlushMap_sm_1_t_5_cnt++;
					break;
				case 6:
					S5S8FlushRepository::s5s8FlushMap_sm_1_t_6[S5S8FlushRepository::s5s8FlushMap_sm_1_t_6_cnt].copy(pGTPSession);
					S5S8FlushRepository::s5s8FlushMap_sm_1_t_6_cnt++;
					break;
				case 7:
					S5S8FlushRepository::s5s8FlushMap_sm_1_t_7[S5S8FlushRepository::s5s8FlushMap_sm_1_t_7_cnt].copy(pGTPSession);
					S5S8FlushRepository::s5s8FlushMap_sm_1_t_7_cnt++;
					break;
				case 8:
					S5S8FlushRepository::s5s8FlushMap_sm_1_t_8[S5S8FlushRepository::s5s8FlushMap_sm_1_t_8_cnt].copy(pGTPSession);
					S5S8FlushRepository::s5s8FlushMap_sm_1_t_8_cnt++;
					break;
				case 9:
					S5S8FlushRepository::s5s8FlushMap_sm_1_t_9[S5S8FlushRepository::s5s8FlushMap_sm_1_t_9_cnt].copy(pGTPSession);
					S5S8FlushRepository::s5s8FlushMap_sm_1_t_9_cnt++;
					break;
			}
			break;

		case 2:
			switch(idx)
			{
				case 0:
					S5S8FlushRepository::s5s8FlushMap_sm_2_t_0[S5S8FlushRepository::s5s8FlushMap_sm_2_t_0_cnt].copy(pGTPSession);
					S5S8FlushRepository::s5s8FlushMap_sm_2_t_0_cnt++;
					break;
				case 1:
					S5S8FlushRepository::s5s8FlushMap_sm_2_t_1[S5S8FlushRepository::s5s8FlushMap_sm_2_t_1_cnt].copy(pGTPSession);
					S5S8FlushRepository::s5s8FlushMap_sm_2_t_1_cnt++;
					break;
				case 2:
					S5S8FlushRepository::s5s8FlushMap_sm_2_t_2[S5S8FlushRepository::s5s8FlushMap_sm_2_t_2_cnt].copy(pGTPSession);
					S5S8FlushRepository::s5s8FlushMap_sm_2_t_2_cnt++;
					break;
				case 3:
					S5S8FlushRepository::s5s8FlushMap_sm_2_t_3[S5S8FlushRepository::s5s8FlushMap_sm_2_t_3_cnt].copy(pGTPSession);
					S5S8FlushRepository::s5s8FlushMap_sm_2_t_3_cnt++;
					break;
				case 4:
					S5S8FlushRepository::s5s8FlushMap_sm_2_t_4[S5S8FlushRepository::s5s8FlushMap_sm_2_t_4_cnt].copy(pGTPSession);
					S5S8FlushRepository::s5s8FlushMap_sm_2_t_4_cnt++;
					break;
				case 5:
					S5S8FlushRepository::s5s8FlushMap_sm_2_t_5[S5S8FlushRepository::s5s8FlushMap_sm_2_t_5_cnt].copy(pGTPSession);
					S5S8FlushRepository::s5s8FlushMap_sm_2_t_5_cnt++;
					break;
				case 6:
					S5S8FlushRepository::s5s8FlushMap_sm_2_t_6[S5S8FlushRepository::s5s8FlushMap_sm_2_t_6_cnt].copy(pGTPSession);
					S5S8FlushRepository::s5s8FlushMap_sm_2_t_6_cnt++;
					break;
				case 7:
					S5S8FlushRepository::s5s8FlushMap_sm_2_t_7[S5S8FlushRepository::s5s8FlushMap_sm_2_t_7_cnt].copy(pGTPSession);
					S5S8FlushRepository::s5s8FlushMap_sm_2_t_7_cnt++;
					break;
				case 8:
					S5S8FlushRepository::s5s8FlushMap_sm_2_t_8[S5S8FlushRepository::s5s8FlushMap_sm_2_t_8_cnt].copy(pGTPSession);
					S5S8FlushRepository::s5s8FlushMap_sm_2_t_8_cnt++;
					break;
				case 9:
					S5S8FlushRepository::s5s8FlushMap_sm_2_t_9[S5S8FlushRepository::s5s8FlushMap_sm_2_t_9_cnt].copy(pGTPSession);
					S5S8FlushRepository::s5s8FlushMap_sm_2_t_9_cnt++;
					break;
			}
			break;

		case 3:
			switch(idx)
			{
				case 0:
					S5S8FlushRepository::s5s8FlushMap_sm_3_t_0[S5S8FlushRepository::s5s8FlushMap_sm_3_t_0_cnt].copy(pGTPSession);
					S5S8FlushRepository::s5s8FlushMap_sm_3_t_0_cnt++;
					break;
				case 1:
					S5S8FlushRepository::s5s8FlushMap_sm_3_t_1[S5S8FlushRepository::s5s8FlushMap_sm_3_t_1_cnt].copy(pGTPSession);
					S5S8FlushRepository::s5s8FlushMap_sm_3_t_1_cnt++;
					break;
				case 2:
					S5S8FlushRepository::s5s8FlushMap_sm_3_t_2[S5S8FlushRepository::s5s8FlushMap_sm_3_t_2_cnt].copy(pGTPSession);
					S5S8FlushRepository::s5s8FlushMap_sm_3_t_2_cnt++;
					break;
				case 3:
					S5S8FlushRepository::s5s8FlushMap_sm_3_t_3[S5S8FlushRepository::s5s8FlushMap_sm_3_t_3_cnt].copy(pGTPSession);
					S5S8FlushRepository::s5s8FlushMap_sm_3_t_3_cnt++;
					break;
				case 4:
					S5S8FlushRepository::s5s8FlushMap_sm_3_t_4[S5S8FlushRepository::s5s8FlushMap_sm_3_t_4_cnt].copy(pGTPSession);
					S5S8FlushRepository::s5s8FlushMap_sm_3_t_4_cnt++;
					break;
				case 5:
					S5S8FlushRepository::s5s8FlushMap_sm_3_t_5[S5S8FlushRepository::s5s8FlushMap_sm_3_t_5_cnt].copy(pGTPSession);
					S5S8FlushRepository::s5s8FlushMap_sm_3_t_5_cnt++;
					break;
				case 6:
					S5S8FlushRepository::s5s8FlushMap_sm_3_t_6[S5S8FlushRepository::s5s8FlushMap_sm_3_t_6_cnt].copy(pGTPSession);
					S5S8FlushRepository::s5s8FlushMap_sm_3_t_6_cnt++;
					break;
				case 7:
					S5S8FlushRepository::s5s8FlushMap_sm_3_t_7[S5S8FlushRepository::s5s8FlushMap_sm_3_t_7_cnt].copy(pGTPSession);
					S5S8FlushRepository::s5s8FlushMap_sm_3_t_7_cnt++;
					break;
				case 8:
					S5S8FlushRepository::s5s8FlushMap_sm_3_t_8[S5S8FlushRepository::s5s8FlushMap_sm_3_t_8_cnt].copy(pGTPSession);
					S5S8FlushRepository::s5s8FlushMap_sm_3_t_8_cnt++;
					break;
				case 9:
					S5S8FlushRepository::s5s8FlushMap_sm_3_t_9[S5S8FlushRepository::s5s8FlushMap_sm_3_t_9_cnt].copy(pGTPSession);
					S5S8FlushRepository::s5s8FlushMap_sm_3_t_9_cnt++;
					break;
			}
			break;
	}
}

VOID S5S8Interface::S5S8_TimeOutCleanSession(long curTimeEpochSec)
{
	GTPSession *gtpSession;

	GTPStats::gtp_cr_session_count = S5S8_CSIndexPool.size();
	GTPStats::gtp_mb_session_count = S5S8_MBIndexPool.size();
	GTPStats::gtp_dl_session_count = S5S8_DSIndexPool.size();

	GTPStats::gtp_cr_session_cln_count = 0;

	for(auto elem = S5S8_CSIndexPool.begin(), next_elem = elem; elem != S5S8_CSIndexPool.end(); elem = next_elem)
	{
		++next_elem;
		gtpSession = S5S8_GetSessionFromPool(elem->second);

		if( (gtpSession->StartTimeEpochSec > 0 && (curTimeEpochSec - gtpSession->StartTimeEpochSec) > IPGlobal::S5S8_IDLE_SESSION_TIMEOUT_IN_SEC) ||
			(gtpSession->EndTimeEpochSec > 0 && (curTimeEpochSec - gtpSession->EndTimeEpochSec) > IPGlobal::S5S8_IDLE_SESSION_TIMEOUT_IN_SEC) )
		{
			if(gtpSession->EndTimeEpochSec == 0)
				gtpSession->EndTimeEpochSec 	= curTimeEpochSec;

			if(gtpSession->StartTimeEpochSec == 0)
				gtpSession->StartTimeEpochSec 	= curTimeEpochSec;

//			S5S8_FlushSession(gtpSession, FLUSH_TYPE_CLEANUP);
			GTPStats::gtp_cr_session_cln_count++;
			S5S8_CSIndexPool.erase(elem->first);
		}
	}

	GTPStats::gtp_dl_session_cln_count = 0;
	for(auto elem = S5S8_DSIndexPool.begin(), next_elem = elem; elem != S5S8_DSIndexPool.end(); elem = next_elem)
	{
		++next_elem;

		gtpSession = S5S8_GetSessionFromPool(elem->second);

		if( (gtpSession->StartTimeEpochSec > 0 && (curTimeEpochSec - gtpSession->StartTimeEpochSec) > IPGlobal::S5S8_IDLE_SESSION_TIMEOUT_IN_SEC) ||
			(gtpSession->EndTimeEpochSec > 0 && (curTimeEpochSec - gtpSession->EndTimeEpochSec) > IPGlobal::S5S8_IDLE_SESSION_TIMEOUT_IN_SEC) )
		{
			if(gtpSession->EndTimeEpochSec == 0)
				gtpSession->EndTimeEpochSec 	= curTimeEpochSec;

			if(gtpSession->StartTimeEpochSec == 0)
				gtpSession->StartTimeEpochSec 	= curTimeEpochSec;

			GTPStats::gtp_dl_session_cln_count++;
			S5S8_DSIndexPool.erase(elem->first);
		}
	}

	GTPStats::gtp_mb_session_cln_count = 0;
	for(auto elem = S5S8_MBIndexPool.begin(), next_elem = elem; elem != S5S8_MBIndexPool.end(); elem = next_elem)
	{
		++next_elem;
		gtpSession = S5S8_GetSessionFromPool(elem->second);

		if( (gtpSession->StartTimeEpochSec > 0 && (curTimeEpochSec - gtpSession->StartTimeEpochSec) > IPGlobal::S5S8_IDLE_SESSION_TIMEOUT_IN_SEC) ||
			(gtpSession->EndTimeEpochSec > 0 && (curTimeEpochSec - gtpSession->EndTimeEpochSec) > IPGlobal::S5S8_IDLE_SESSION_TIMEOUT_IN_SEC) )
		{
			if(gtpSession->EndTimeEpochSec == 0)
				gtpSession->EndTimeEpochSec 	= curTimeEpochSec;

			if(gtpSession->StartTimeEpochSec == 0)
				gtpSession->StartTimeEpochSec 	= curTimeEpochSec;

			GTPStats::gtp_mb_session_cln_count++;
			S5S8_MBIndexPool.erase(elem->first);
		}
	}
}

VOID S5S8Interface::S5S8_TimeOutCleanGlbSession(long curTimeEpochSec)
{
	cleanCounter 								= 0;
	glbIndex 									= -1;

	GTPSession *pGtpGlobalSession 				= NULL;
	GTPStats::gtpv2_glb_sessions_delete_count 	= 0;
	GTPStats::gtpv2_glb_sessions_active_count 	= 0;

	for(int i = 0; i < S5S8_SESSION_POOL_ARRAY_SIZE; i++)
	{
		for(int n = 0; n < S5S8_SESSION_POOL_ARRAY_ELEMENTS; n++)
		{
			if(GTPStore::S5S8GlbBitFlags[i].test(n))
			{
				glbIndex  = i * S5S8_SESSION_POOL_ARRAY_ELEMENTS + n;

				pGtpGlobalSession = GTPStore::S5S8_GlbSessionPool[i][n];

				if(pGtpGlobalSession->lastActivityTime > 0) /* 6 Hours */
				{
					if(((curTimeEpochSec - pGtpGlobalSession->lastActivityTime) >= IPGlobal::GN_GTPC_GLOBAL_SESSION_CLEANUP_TIMEOUT_SEC) && (pGtpGlobalSession->expiredFlag))
					{
						S5S8_DeleteGlbSession(pGtpGlobalSession, glbIndex);
						cleanCounter++;
					}
					else
					{	GTPStats::gtpv2_glb_sessions_active_count ++; }
				}
			}
		}
	}
	GTPStats::gtpv2_glb_sessions_delete_count = cleanCounter;
}
