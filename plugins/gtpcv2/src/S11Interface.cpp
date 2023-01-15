/*
 * GTPV2Interface.cpp
 *
 *  Created on: Dec 9, 2019
 *      Author: Debashis
 */

#include "S11Interface.h"

S11Interface::S11Interface(int id)
{
	this->_name = "S11Interface";
	this->setLogLevel(Log::theLog().level());
	this->instanceId = id;
	S11_InitializeSessionPool(id);

	if(this->instanceId == 0)
		S11_InitializeGlobalRepository();
}

S11Interface::~S11Interface()
{ }

VOID S11Interface::lockgSession()
{
	pthread_mutex_lock(&s11SessionLock::lockCount);
	while (s11SessionLock::count == 0){
		pthread_cond_wait(&s11SessionLock::nonzero, &s11SessionLock::lockCount);
	}
	s11SessionLock::count = s11SessionLock::count - 1;
	pthread_mutex_unlock(&s11SessionLock::lockCount);
}

VOID S11Interface::unLockgSession()
{
    pthread_mutex_lock(&s11SessionLock::lockCount);
    if (s11SessionLock::count == 0)
        pthread_cond_signal(&s11SessionLock::nonzero);
    s11SessionLock::count = s11SessionLock::count + 1;
    pthread_mutex_unlock(&s11SessionLock::lockCount);
}


VOID S11Interface::S11_InitializeSessionPool(int id)
{
	s11freeBitPosMax = S11_SESSION_POOL_ARRAY_ELEMENTS * S11_SESSION_POOL_ARRAY_SIZE;

	for(int i = 0; i < S11_SESSION_POOL_ARRAY_SIZE; i++)
	{
		s11SessionBitFlags[i].reset();

		for(int j = 0; j < S11_SESSION_POOL_ARRAY_ELEMENTS; j++)
			S11_SessionPool[i][j] = new GTPSession();
	}
	printf("S11Interface [%02d]	Initializing [%d] Session Pool Completed.\n", id, s11freeBitPosMax);
	TheLog_nc_v2(Log::Info, name(),"   S11Interface [%02d] Initializing [%d] Session Pool Completed.", id, s11freeBitPosMax);
}

VOID S11Interface::S11_InitializeGlobalRepository()
{
	GTPStore::S11FreeGlbBitPos = -1;
	GTPStore::S11FreeGlbBitPosMax = S11_SESSION_POOL_ARRAY_ELEMENTS * S11_SESSION_POOL_ARRAY_SIZE;

	for(int n = 0; n < S11_SESSION_POOL_ARRAY_SIZE; n++)
	{
		GTPStore::S11GlbBitFlags[n].reset();

		for(int i = 0; i < S11_SESSION_POOL_ARRAY_ELEMENTS; i++)
			GTPStore::S11_GlbSessionPool[n][i] = new GTPSession();
	}

	printf("GTPInterface Initializing [%08lu]  S11 Global Session Pool... Completed\n", S11_SESSION_POOL_ARRAY_ELEMENTS * S11_SESSION_POOL_ARRAY_SIZE);
	TheLog_nc_v1(Log::Info, name()," S11 Global Session Initializing for [%'08lu] entries...Completed", S11_SESSION_POOL_ARRAY_ELEMENTS * S11_SESSION_POOL_ARRAY_SIZE);
}

GTPSession* S11Interface::S11_GetSessionFromPool(int idx)
{
	int arrId = idx / S11_SESSION_POOL_ARRAY_ELEMENTS;
	int bitId = idx % S11_SESSION_POOL_ARRAY_ELEMENTS;
	return S11_SessionPool[arrId][bitId];
}

int S11Interface::S11_GetFreeIndex()
{
	S11FreeBitPos++;
	if(S11FreeBitPos >= s11freeBitPosMax) S11FreeBitPos = 0;
	int arrId = S11FreeBitPos / S11_SESSION_POOL_ARRAY_ELEMENTS;
	int bitId = S11FreeBitPos % S11_SESSION_POOL_ARRAY_ELEMENTS;

	while(s11SessionBitFlags[arrId].test(bitId)){
		S11FreeBitPos++;
		if(S11FreeBitPos >= s11freeBitPosMax) S11FreeBitPos = 0;
		arrId = S11FreeBitPos / S11_SESSION_POOL_ARRAY_ELEMENTS;
		bitId = S11FreeBitPos % S11_SESSION_POOL_ARRAY_ELEMENTS;
	}
	if(S11FreeBitPos >= s11freeBitPosMax){
		printf("S11 S11FreeBitPos [%d] >= S11freeBitPosMax [%d]\n", S11FreeBitPos, s11freeBitPosMax);
	}
	s11SessionBitFlags[arrId].set(bitId);
	return S11FreeBitPos;
}

VOID S11Interface::S11_ReleaseIndexFromSessionPool(int idx)
{
	int arrId = idx / S11_SESSION_POOL_ARRAY_ELEMENTS;
	int bitId = idx % S11_SESSION_POOL_ARRAY_ELEMENTS;
	S11_SessionPool[arrId][bitId]->reset();
	s11SessionBitFlags[arrId].reset(bitId);
}

uint32_t S11Interface::S11_GetGlbFreeIndex()
{
	GTPStore::S11FreeGlbBitPos++;
	if(GTPStore::S11FreeGlbBitPos >= GTPStore::S11FreeGlbBitPosMax) GTPStore::S11FreeGlbBitPos = 0;
	int arrId = GTPStore::S11FreeGlbBitPos / S11_SESSION_POOL_ARRAY_ELEMENTS;
	int bitId = GTPStore::S11FreeGlbBitPos % S11_SESSION_POOL_ARRAY_ELEMENTS;

	while(GTPStore::S11GlbBitFlags[arrId].test(bitId)){
		GTPStore::S11FreeGlbBitPos++;
		if(GTPStore::S11FreeGlbBitPos >= GTPStore::S11FreeGlbBitPosMax) GTPStore::S11FreeGlbBitPos = 0;
		arrId = GTPStore::S11FreeGlbBitPos / S11_SESSION_POOL_ARRAY_ELEMENTS;
		bitId = GTPStore::S11FreeGlbBitPos % S11_SESSION_POOL_ARRAY_ELEMENTS;
	}
	if(GTPStore::S11FreeGlbBitPos >= GTPStore::S11FreeGlbBitPosMax){
		printf(" getGlbFreeIndex GTPStore::S11FreeGlbBitPos [%lu] >= GTPStore::GTPcV2FreeGlbBitPosMax [%lu]\n",
				 GTPStore::S11FreeGlbBitPos, GTPStore::S11FreeGlbBitPosMax);
	}
	GTPStore::S11GlbBitFlags[arrId].set(bitId);
	GTPStats::gtp_glb_sessions_op_cr_cnt++;
	GTPStats::gtp_glb_sessions_bit_index = GTPStore::S11FreeGlbBitPos;
	return GTPStore::S11FreeGlbBitPos;
}

VOID S11Interface::S11_DeleteGlbSession(GTPSession *pGtpGlobalSession, int index)
{
	if(pGtpGlobalSession->MME_ctl_teid != 0)
	{
		std::map<uint32_t, int>::iterator itr = GTPStore::S11_GlbMmeCtlIndexPool[INDEX_TEID(pGtpGlobalSession->MME_ctl_teid)].find(pGtpGlobalSession->MME_ctl_teid);

		if(itr != GTPStore::S11_GlbMmeCtlIndexPool[INDEX_TEID(pGtpGlobalSession->MME_ctl_teid)].end())
			GTPStore::S11_GlbMmeCtlIndexPool[INDEX_TEID(pGtpGlobalSession->MME_ctl_teid)].erase(itr->first);
	}
	if(pGtpGlobalSession->SGW_ctl_teid != 0)
	{
		std::map<uint32_t, int>::iterator itr = GTPStore::S11_GlbSgwCtlIndexPool[INDEX_TEID(pGtpGlobalSession->SGW_ctl_teid)].find(pGtpGlobalSession->SGW_ctl_teid);

		if(itr != GTPStore::S11_GlbSgwCtlIndexPool[INDEX_TEID(pGtpGlobalSession->SGW_ctl_teid)].end())
			GTPStore::S11_GlbSgwCtlIndexPool[INDEX_TEID(pGtpGlobalSession->SGW_ctl_teid)].erase(itr->first);
	}
	if(pGtpGlobalSession->SGW_s1u_teid != 0)
	{
		std::map<uint32_t, int>::iterator itr = GTPStore::S11_GlbSgwBeaIndexPool[INDEX_TEID(pGtpGlobalSession->SGW_s1u_teid)].find(pGtpGlobalSession->SGW_s1u_teid);

		if(itr != GTPStore::S11_GlbSgwBeaIndexPool[INDEX_TEID(pGtpGlobalSession->SGW_s1u_teid)].end())
			GTPStore::S11_GlbSgwBeaIndexPool[INDEX_TEID(pGtpGlobalSession->SGW_s1u_teid)].erase(itr->first);
	}
	if(pGtpGlobalSession->eNB_s1u_teid != 0)
	{
		std::map<uint32_t, int>::iterator itr = GTPStore::S11_GlbeNBBeaIndexPool[INDEX_TEID(pGtpGlobalSession->eNB_s1u_teid)].find(pGtpGlobalSession->eNB_s1u_teid);

		if(itr != GTPStore::S11_GlbeNBBeaIndexPool[INDEX_TEID(pGtpGlobalSession->eNB_s1u_teid)].end())
			GTPStore::S11_GlbeNBBeaIndexPool[INDEX_TEID(pGtpGlobalSession->eNB_s1u_teid)].erase(itr->first);
	}
	S11_ReleaseIndexFromGlbPool(index);
}

VOID S11Interface::S11_ReleaseIndexFromGlbPool(int glbIndex)
{
	int arrId = glbIndex / S11_SESSION_POOL_ARRAY_ELEMENTS;
	int bitId = glbIndex % S11_SESSION_POOL_ARRAY_ELEMENTS;

	GTPStore::S11_GlbSessionPool[arrId][bitId]->reset();
	GTPStore::S11GlbBitFlags[arrId].reset(bitId);
}

VOID S11Interface::S11_ProcessMsgType(MPacket *msgObj)
{
	switch(msgObj->gtpcMsgType)
	{
		case CREATE_SESSION_REQUEST:
					S11_CreateSessionReq(msgObj);
					break;

		case CREATE_SESSION_RESPONSE:
					S11_CreateSessionRsp(msgObj);
					break;

		case MODIFY_BEARER_REQUEST:
					S11_ModifyBearerReq(msgObj);
					break;

		case MODIFY_BEARER_RESPONSE:
					S11_ModifyBearerRsp(msgObj);
					break;

		case DELETE_SESSION_REQUEST:
					S11_DeleteSessionReq(msgObj);
					break;

		case DELETE_SESSION_RESPONSE:
					S11_DeleteSessionRsp(msgObj);
					break;

		case RELEASED_ACCESS_BEARER_REQUEST:
					S11_ReleaseAccessBearerReq(msgObj);
					break;

		case RELEASED_ACCESS_BEARER_RESPONSE:
					S11_ReleaseAccessBearerRsp(msgObj);
					break;

		case DOWNLINK_DATA_NOTIFICATION:
					S11_DownLinkDataNotification(msgObj);
					break;

		case DOWNLINK_DATA_ACK:
					S11_DownLinkDataAcknowledgement(msgObj);
					break;

		case DOWNLINK_DATA_NOTIFI_INDI:
					S11_DownLinkDataNotificationIndi(msgObj);
					break;
	}
}

VOID S11Interface::S11_CreateSessionReq(MPacket *msgObj)
{
	GTPSession *pGtpSession;

	std::map<uint32_t, int>::iterator it = S11_CSIndexPool.find(msgObj->MME_ctl_teid);

	if(it != S11_CSIndexPool.end())
	{
		pGtpSession = S11_GetSessionFromPool(it->second);

		if(pGtpSession->GTPRspMsgId == CREATE_SESSION_RESPONSE && pGtpSession->resSeqNo == msgObj->gtpcV2PktSeqNo)	//Response has arrieved before Req
		{
				S11_ProcessRequest(pGtpSession, msgObj);
				if(pGtpSession->EndCauseId == GTPv2_ACCEPT)
				{
					lockgSession();
					S11_CreateGlobalTable(pGtpSession);
					unLockgSession();
				}
				S11_FlushSession(pGtpSession, FLUSH_TYPE_CR_REQ_RESREQ);
				S11_ReleaseIndexFromSessionPool(pGtpSession->poolIndex);
				S11_CSIndexPool.erase(msgObj->MME_ctl_teid);
				return;
		}
	}
	else /* New Create Session */
	{
		int poolIndex = S11_GetFreeIndex();
		pGtpSession = S11_GetSessionFromPool(poolIndex);
		pGtpSession->poolIndex = poolIndex;
//		S11_CSIndexPool[msgObj->MME_ctl_teid] = pGtpSession->poolIndex;
		S11_CSIndexPool.insert(pair<uint32_t, int>(msgObj->MME_ctl_teid, pGtpSession->poolIndex));

		sprintf(pGtpSession->SessionId, "%07u-%07u",IPGlobal::CURRENT_EPOCH_SEC, msgObj->gtpcV2PktSeqNo);
		S11_ProcessRequest(pGtpSession, msgObj);
	}
}

VOID S11Interface::S11_CreateSessionRsp(MPacket *msgObj)
{
	GTPSession *pGtpSession;

	std::map<uint32_t, int>::iterator it = S11_CSIndexPool.find(msgObj->gtpc_PktTeid);

	if(it != S11_CSIndexPool.end())
	{
		pGtpSession = S11_GetSessionFromPool(it->second);

		if(pGtpSession->GTPReqMsgId == CREATE_SESSION_REQUEST && pGtpSession->reqSeqNo == msgObj->gtpcV2PktSeqNo)	//Response has arrieved after Req
		{
				S11_ProcessResponse(pGtpSession, msgObj);

				if(pGtpSession->EndCauseId == GTPv2_ACCEPT)
				{
					lockgSession();
					S11_CreateGlobalTable(pGtpSession);
					unLockgSession();
				}
				S11_FlushSession(pGtpSession, FLUSH_TYPE_CR_RES_REQRES);
				S11_ReleaseIndexFromSessionPool(pGtpSession->poolIndex);
				S11_CSIndexPool.erase(msgObj->gtpc_PktTeid);
				return;
		}
	}
	else
	{
		int poolIndex = S11_GetFreeIndex();
		pGtpSession = S11_GetSessionFromPool(poolIndex);
		pGtpSession->poolIndex = poolIndex;
//		S11_CSIndexPool[msgObj->gtpc_PktTeid] = pGtpSession->poolIndex;
		S11_CSIndexPool.insert(pair<uint32_t, int>(msgObj->gtpc_PktTeid, pGtpSession->poolIndex));

		sprintf(pGtpSession->SessionId, "%07u-%07u",IPGlobal::CURRENT_EPOCH_SEC, msgObj->gtpcV2PktSeqNo);
		S11_ProcessResponse(pGtpSession, msgObj);
	}
}

VOID S11Interface::S11_ModifyBearerReq(MPacket *msgObj)
{
	GTPSession *pGtpSession;

	std::map<uint32_t, int>::iterator it = S11_MBIndexPool.find(msgObj->gtpcV2PktSeqNo);
	if(it != S11_MBIndexPool.end())
	{
		pGtpSession = S11_GetSessionFromPool(it->second);

		if(pGtpSession->GTPRspMsgId == MODIFY_BEARER_RESPONSE)	//Response has arrieved before Req
		{
				S11_ProcessRequest(pGtpSession, msgObj);

				if(pGtpSession->EndCauseId == GTPv2_ACCEPT)
				{
					lockgSession();
					S11_UpdateGlobalTable(pGtpSession, msgObj, MODIFY_BEARER_RESPONSE);
					unLockgSession();
				}

				S11_FlushSession(pGtpSession, FLUSH_TYPE_CR_REQ_RESREQ);
				S11_ReleaseIndexFromSessionPool(pGtpSession->poolIndex);
				S11_MBIndexPool.erase(msgObj->gtpcV2PktSeqNo);
				return;
		}
	}
	else
	{
		int poolIndex = S11_GetFreeIndex();
		pGtpSession = S11_GetSessionFromPool(poolIndex);
		pGtpSession->poolIndex = poolIndex;
		S11_MBIndexPool.insert(pair<uint32_t, int>(msgObj->gtpcV2PktSeqNo, pGtpSession->poolIndex));

		sprintf(pGtpSession->SessionId, "%07u-%07u",IPGlobal::CURRENT_EPOCH_SEC, msgObj->gtpcV2PktSeqNo);
		S11_ProcessRequest(pGtpSession, msgObj);
	}
}

VOID S11Interface::S11_ModifyBearerRsp(MPacket *msgObj)
{
	GTPSession *pGtpSession;

	std::map<uint32_t, int>::iterator it = S11_MBIndexPool.find(msgObj->gtpcV2PktSeqNo);

	if(it != S11_MBIndexPool.end())
	{
		pGtpSession = S11_GetSessionFromPool(it->second);

		if(pGtpSession->GTPReqMsgId == MODIFY_BEARER_REQUEST)	//Response has arrieved after Req
		{
				S11_ProcessResponse(pGtpSession, msgObj);

				if(pGtpSession->EndCauseId == GTPv2_ACCEPT)
				{
					lockgSession();
					S11_UpdateGlobalTable(pGtpSession, msgObj, MODIFY_BEARER_RESPONSE);
					unLockgSession();
				}

				S11_FlushSession(pGtpSession, FLUSH_TYPE_CR_RES_REQRES);
				S11_ReleaseIndexFromSessionPool(pGtpSession->poolIndex);
				S11_MBIndexPool.erase(msgObj->gtpcV2PktSeqNo);
				return;
		}
	}
	else
	{
		int poolIndex = S11_GetFreeIndex();
		pGtpSession = S11_GetSessionFromPool(poolIndex);
		pGtpSession->poolIndex = poolIndex;
		S11_MBIndexPool.insert(pair<uint32_t, int>(msgObj->gtpcV2PktSeqNo, poolIndex));

		sprintf(pGtpSession->SessionId, "%07u-%07u",IPGlobal::CURRENT_EPOCH_SEC, msgObj->gtpcV2PktSeqNo);
		S11_ProcessResponse(pGtpSession, msgObj);
	}
}

VOID S11Interface::S11_DeleteSessionReq(MPacket *msgObj)
{
	GTPSession *pGtpSession;
	uint32_t key = msgObj->gtpcV2PktSeqNo;

	if(key == 0) return;

	std::map<uint32_t, int>::iterator it = S11_DSIndexPool.find(msgObj->gtpcV2PktSeqNo);
	if(it != S11_DSIndexPool.end())
	{
		pGtpSession = S11_GetSessionFromPool(it->second);

		if(pGtpSession->GTPRspMsgId == DELETE_SESSION_RESPONSE && pGtpSession->resSeqNo == msgObj->gtpcV2PktSeqNo)	//Response has arrieved before Req
		{
				S11_ProcessRequest(pGtpSession, msgObj);

				if(pGtpSession->EndCauseId == GTPv2_ACCEPT)
				{
					lockgSession();
					S11_UpdateGlobalTable(pGtpSession, msgObj, DELETE_SESSION_RESPONSE);
					unLockgSession();
				}
				S11_FlushSession(pGtpSession, FLUSH_TYPE_CR_REQ_RESREQ);
				S11_ReleaseIndexFromSessionPool(pGtpSession->poolIndex);
				S11_DSIndexPool.erase(msgObj->gtpcV2PktSeqNo);
				return;
		}
	}
	else
	{
		int poolIndex = S11_GetFreeIndex();
		pGtpSession = S11_GetSessionFromPool(poolIndex);
		pGtpSession->poolIndex = poolIndex;
		S11_DSIndexPool.insert(pair<uint32_t, int>(msgObj->gtpcV2PktSeqNo, poolIndex));

		sprintf(pGtpSession->SessionId, "%07u-%07u",IPGlobal::CURRENT_EPOCH_SEC, msgObj->gtpcV2PktSeqNo);
		S11_ProcessRequest(pGtpSession, msgObj);
	}
}

VOID S11Interface::S11_DeleteSessionRsp(MPacket *msgObj)
{
	GTPSession *pGtpSession;
	uint32_t key = msgObj->gtpcV2PktSeqNo;

	if (key == 0) return;

	std::map<uint32_t, int>::iterator it = S11_DSIndexPool.find(msgObj->gtpcV2PktSeqNo);

	if(it != S11_DSIndexPool.end())
	{
		pGtpSession = S11_GetSessionFromPool(it->second);

		if(pGtpSession->GTPReqMsgId == DELETE_SESSION_REQUEST && pGtpSession->reqSeqNo == msgObj->gtpcV2PktSeqNo)	//Response has arrieved after Req
		{
				S11_ProcessResponse(pGtpSession, msgObj);

				if(pGtpSession->EndCauseId == GTPv2_ACCEPT)
				{
					lockgSession();
					S11_UpdateGlobalTable(pGtpSession, msgObj, DELETE_SESSION_RESPONSE);
					unLockgSession();
				}

				S11_FlushSession(pGtpSession,FLUSH_TYPE_CR_RES_REQRES);
				S11_ReleaseIndexFromSessionPool(pGtpSession->poolIndex);
				S11_DSIndexPool.erase(msgObj->gtpcV2PktSeqNo);
				return;
		}
	}
	else
	{
		int poolIndex = S11_GetFreeIndex();
		pGtpSession = S11_GetSessionFromPool(poolIndex);
		pGtpSession->poolIndex = poolIndex;
		S11_DSIndexPool.insert(pair<uint32_t, int>(msgObj->gtpcV2PktSeqNo, poolIndex));

		sprintf(pGtpSession->SessionId, "%07u-%07u",IPGlobal::CURRENT_EPOCH_SEC, msgObj->gtpcV2PktSeqNo);
		S11_ProcessResponse(pGtpSession, msgObj);
	}
}

VOID S11Interface::S11_ReleaseAccessBearerReq(MPacket *msgObj)
{
	GTPSession *pGtpSession;
	uint32_t key = msgObj->gtpcV2PktSeqNo;

	if (key == 0) return;

	std::map<uint32_t, int>::iterator it = S11_RABIndexPool.find(msgObj->gtpcV2PktSeqNo);

	if(it != S11_RABIndexPool.end())
	{
		pGtpSession = S11_GetSessionFromPool(it->second);

		if(pGtpSession->GTPRspMsgId == RELEASED_ACCESS_BEARER_RESPONSE && pGtpSession->resSeqNo == msgObj->gtpcV2PktSeqNo)	//Response has arrieved before Req
		{
				S11_ProcessRequest(pGtpSession, msgObj);
				S11_FlushSession(pGtpSession, FLUSH_TYPE_CR_REQ_RESREQ);
				S11_ReleaseIndexFromSessionPool(pGtpSession->poolIndex);
				S11_RABIndexPool.erase(msgObj->gtpcV2PktSeqNo);
				return;
		}
	}
	else
	{
		int poolIndex = S11_GetFreeIndex();
		pGtpSession = S11_GetSessionFromPool(poolIndex);
		pGtpSession->poolIndex = poolIndex;
		S11_RABIndexPool.insert(pair<uint32_t, int>(msgObj->gtpcV2PktSeqNo, poolIndex));

		sprintf(pGtpSession->SessionId, "%07u-%07u",IPGlobal::CURRENT_EPOCH_SEC, msgObj->gtpcV2PktSeqNo);
		S11_ProcessRequest(pGtpSession, msgObj);

		lockgSession();
		S11_getUserInfo(pGtpSession);
		unLockgSession();
	}
}

VOID S11Interface::S11_ReleaseAccessBearerRsp(MPacket *msgObj)
{
	GTPSession *pGtpSession;
	uint32_t key = msgObj->gtpcV2PktSeqNo;

	if (key == 0) return;

	std::map<uint32_t, int>::iterator it = S11_RABIndexPool.find(msgObj->gtpcV2PktSeqNo);

	if(it != S11_RABIndexPool.end())
	{
		pGtpSession = S11_GetSessionFromPool(it->second);

		if(pGtpSession->GTPReqMsgId == RELEASED_ACCESS_BEARER_REQUEST && pGtpSession->reqSeqNo == msgObj->gtpcV2PktSeqNo)	//Response has arrieved after Req
		{
				S11_ProcessResponse(pGtpSession, msgObj);
				S11_FlushSession(pGtpSession,FLUSH_TYPE_CR_RES_REQRES);
				S11_ReleaseIndexFromSessionPool(pGtpSession->poolIndex);
				S11_RABIndexPool.erase(msgObj->gtpcV2PktSeqNo);
				return;
		}
	}
	else
	{
		int poolIndex = S11_GetFreeIndex();
		pGtpSession = S11_GetSessionFromPool(poolIndex);
		pGtpSession->poolIndex = poolIndex;
		S11_RABIndexPool.insert(pair<uint32_t, int>(msgObj->gtpcV2PktSeqNo, poolIndex));

		sprintf(pGtpSession->SessionId, "%07u-%07u",IPGlobal::CURRENT_EPOCH_SEC, msgObj->gtpcV2PktSeqNo);
		S11_ProcessResponse(pGtpSession, msgObj);
	}
}

VOID S11Interface::S11_DownLinkDataNotification(MPacket *msgObj)
{
	GTPSession *pGtpSession;
	uint32_t key = msgObj->gtpcV2PktSeqNo;

	if (key == 0) return;

	std::map<uint32_t, int>::iterator it = S11_DLIndexPool.find((msgObj->gtpcV2PktSeqNo));

	if(it != S11_DLIndexPool.end())
	{
		pGtpSession = S11_GetSessionFromPool(it->second);

		if(pGtpSession->GTPRspMsgId == DOWNLINK_DATA_ACK && pGtpSession->resSeqNo == msgObj->gtpcV2PktSeqNo)	//Response has arrieved before Req
		{
				S11_ProcessRequest(pGtpSession, msgObj);
				lockgSession();
				S11_getUserInfo(pGtpSession);
				unLockgSession();
				S11_FlushSession(pGtpSession, FLUSH_TYPE_CR_REQ_RESREQ);
				S11_ReleaseIndexFromSessionPool(pGtpSession->poolIndex);
				S11_DLIndexPool.erase((msgObj->gtpcV2PktSeqNo));
				return;
		}
	}
	else
	{
		int poolIndex = S11_GetFreeIndex();
		pGtpSession = S11_GetSessionFromPool(poolIndex);
		pGtpSession->poolIndex = poolIndex;
		S11_DLIndexPool.insert(pair<uint32_t, int>(msgObj->gtpcV2PktSeqNo, poolIndex));

		sprintf(pGtpSession->SessionId, "%07u-%07u",IPGlobal::CURRENT_EPOCH_SEC, msgObj->gtpcV2PktSeqNo);
		S11_ProcessRequest(pGtpSession, msgObj);
	}
}

VOID S11Interface::S11_DownLinkDataAcknowledgement(MPacket *msgObj)
{
	GTPSession *pGtpSession;
	uint32_t key = msgObj->gtpcV2PktSeqNo;

	if (key == 0) return;

	std::map<uint32_t, int>::iterator it = S11_DLIndexPool.find((msgObj->gtpcV2PktSeqNo));

	if(it != S11_DLIndexPool.end())
	{
		pGtpSession = S11_GetSessionFromPool(it->second);

		if(pGtpSession->GTPReqMsgId == DOWNLINK_DATA_NOTIFICATION && pGtpSession->reqSeqNo == msgObj->gtpcV2PktSeqNo)	//Response has arrieved after Req
		{
				S11_ProcessResponse(pGtpSession, msgObj);

				lockgSession();
				S11_getUserInfo(pGtpSession);
				unLockgSession();

				S11_FlushSession(pGtpSession, FLUSH_TYPE_CR_RES_REQRES);
				S11_ReleaseIndexFromSessionPool(pGtpSession->poolIndex);
				S11_DLIndexPool.erase((msgObj->gtpcV2PktSeqNo));
				return;
		}
	}
	else
	{
		int poolIndex = S11_GetFreeIndex();
		pGtpSession = S11_GetSessionFromPool(poolIndex);
		pGtpSession->poolIndex = poolIndex;
		S11_DLIndexPool.insert(pair<uint32_t, int>(msgObj->gtpcV2PktSeqNo, poolIndex));

		sprintf(pGtpSession->SessionId, "%07u-%07u",IPGlobal::CURRENT_EPOCH_SEC, msgObj->gtpcV2PktSeqNo);
		S11_ProcessResponse(pGtpSession, msgObj);
	}
}

VOID S11Interface::S11_DownLinkDataNotificationIndi(MPacket *msgObj)
{
	GTPSession *pGtpSession = new GTPSession();

	sprintf(pGtpSession->SessionId, "%07u-%07u",IPGlobal::CURRENT_EPOCH_SEC, msgObj->gtpcV2PktSeqNo);
	S11_ProcessResponse(pGtpSession, msgObj);
	lockgSession();
	S11_getUserInfo(pGtpSession);
	unLockgSession();
	S11_FlushSession(pGtpSession, FLUSH_TYPE_CR_REQ_RESREQ);
	delete(pGtpSession);
}


VOID S11Interface::S11_ProcessRequest(GTPSession *pGtpSession, MPacket *msgObj)
{
	pGtpSession->StartTimeEpochSec 	= IPGlobal::CURRENT_EPOCH_SEC;
	pGtpSession->gtpcVersion		= msgObj->gtpcVersion;
	pGtpSession->GTPReqMsgId 		= msgObj->gtpcMsgType;
//	pGtpSession->dirMmeSgw 			= msgObj->dirUserNetwork;
	pGtpSession->VLanId 			= msgObj->ethVLanId;
	pGtpSession->ByteSizeUL 		= msgObj->gtpcMsgLen;
	pGtpSession->sourceIp			= msgObj->sourceIpAddrLong;
	pGtpSession->destIp				= msgObj->destIpAddrLong;

	switch(msgObj->gtpcMsgType)
	{
		case CREATE_SESSION_REQUEST:
				delimiter = "-";
				pGtpSession->MME_ctl_teid 	= msgObj->MME_ctl_teid;
				pGtpSession->RAT			= msgObj->gtpcRAT;
				pGtpSession->TAC 			= msgObj->TAC;
				pGtpSession->eNodeB 		= msgObj->eNodeB;
				pGtpSession->cellId 		= msgObj->cellId;
				pGtpSession->req_mbrupl 	= msgObj->gtpcMbrupl;
				pGtpSession->req_mbrdnl 	= msgObj->gtpcMbrdnl;
				strcpy(pGtpSession->IMSI, msgObj->IMSI);
				strcpy(pGtpSession->IMEI, msgObj->IMEI);
				strcpy(pGtpSession->MSISDN, msgObj->MSISDN);
				strcpy(pGtpSession->pdnAddress, msgObj->pdnAddrAllocation);
				strcpy(pGtpSession->PDNType, msgObj->pdnType);

//				strcpy(pGtpSession->mmeIPAddrChar, msgObj->MMEAddress);
//				strcpy(pGtpSession->pgwIPAddrChar, msgObj->PGWAddress);

				if(strlen(msgObj->gtpcAPN) > 2) strcpy(pGtpSession->APN, &msgObj->gtpcAPN[1]);
				else strcpy(pGtpSession->APN, &msgObj->gtpcAPN[0]);

				mcc_mnc.assign(msgObj->MCCMNC);

				pos = 0;

				while ((pos = mcc_mnc.find(delimiter)) != std::string::npos) {
				    token = mcc_mnc.substr(0, pos);
				    pGtpSession->MCC = atoi((const char *)token.c_str());
				    mcc_mnc.erase(0, pos + delimiter.length());
				}
				pGtpSession->MNC = atoi((const char *)mcc_mnc.c_str());

				break;

		case MODIFY_BEARER_REQUEST:
				pGtpSession->SGW_ctl_teid 	= msgObj->gtpc_PktTeid;
				pGtpSession->eNB_s1u_teid 	= msgObj->eNodeB_s1u_teid;
				pGtpSession->RAT			= msgObj->gtpcRAT;
				pGtpSession->eNodeB 		= msgObj->eNodeB;
				pGtpSession->cellId 		= msgObj->cellId;

//				mcc_mnc.assign(msgObj->MCCMNC);
//
//				pos = 0;
//
//				while ((pos = mcc_mnc.find(delimiter)) != std::string::npos) {
//				    token = mcc_mnc.substr(0, pos);
//				    pGtpSession->MCC = atoi((const char *)token.c_str());
//				    mcc_mnc.erase(0, pos + delimiter.length());
//				}
//				pGtpSession->MNC = atoi((const char *)mcc_mnc.c_str());
				break;

		case DELETE_SESSION_REQUEST:
		case RELEASED_ACCESS_BEARER_REQUEST:
				pGtpSession->SGW_ctl_teid = msgObj->gtpc_PktTeid;
				break;

		case DOWNLINK_DATA_NOTIFICATION:
				pGtpSession->MME_ctl_teid 	= msgObj->MME_ctl_teid;
				break;

		default:
				break;
	}

	pGtpSession->reqSeqNo	= msgObj->gtpcV2PktSeqNo;
}

VOID S11Interface::S11_ProcessResponse(GTPSession *pGtpSession, MPacket *msgObj)
{
	pGtpSession->GTPRspMsgId 		= msgObj->gtpcMsgType;
	pGtpSession->EndTimeEpochSec 	= IPGlobal::CURRENT_EPOCH_SEC;
	pGtpSession->ByteSizeDL 		= msgObj->gtpcMsgLen;
	pGtpSession->resSeqNo 			= msgObj->gtpcV2PktSeqNo;
	pGtpSession->EndCauseId 		= msgObj->gtpcCauseCode;

	switch(msgObj->gtpcMsgType)
	{
		case CREATE_SESSION_RESPONSE:
				pGtpSession->SGW_ctl_teid 	= msgObj->SGW_ctl_teid;
				pGtpSession->SGW_s1u_teid 	= msgObj->SGW_s1u_teid;

				pGtpSession->res_mbrupl 	= msgObj->gtpcMbrupl;
				pGtpSession->res_mbrdnl 	= msgObj->gtpcMbrdnl;
				strcpy(pGtpSession->pdnAddress, msgObj->pdnAddrAllocation);
				strcpy(pGtpSession->pgwIPAddrChar, msgObj->PGWAddress);
				strcpy(pGtpSession->sgwIPAddrChar, msgObj->SGWAddress);
				break;

		case MODIFY_BEARER_RESPONSE:
				pGtpSession->MME_ctl_teid 	= msgObj->gtpc_PktTeid;
				pGtpSession->SGW_s1u_teid 	= msgObj->SGW_s1u_teid;
				break;

		case DELETE_SESSION_RESPONSE:
		case RELEASED_ACCESS_BEARER_RESPONSE:
				pGtpSession->MME_ctl_teid 	= msgObj->gtpc_PktTeid;
				break;

		case DOWNLINK_DATA_ACK:
		case DOWNLINK_DATA_NOTIFI_INDI:
				pGtpSession->SGW_ctl_teid 	= msgObj->gtpc_PktTeid;
				break;

		default:
			break;
	}
}

VOID S11Interface::S11_getUserInfo(GTPSession *pGtpSession)
{
	int glbIndex = -1;
	GTPSession *pGlbSession = NULL;

	if(pGtpSession->SGW_ctl_teid > 0)
			glbIndex = S11_GetGlbIndex(pGtpSession->SGW_ctl_teid, SGW_CTL);

	if(glbIndex == -1)
	{
		strcpy(pGtpSession->IMSI, "NA");
		strcpy(pGtpSession->IMEI, "NA");
		strcpy(pGtpSession->MSISDN, "NA");
	}
	else
	{
		int arrid = glbIndex / S11_SESSION_POOL_ARRAY_ELEMENTS;
		int elemid = glbIndex % S11_SESSION_POOL_ARRAY_ELEMENTS;

		std::map<int, GTPSession*>::iterator itrGlb = GTPStore::S11_GlbSessionPool[arrid].find(elemid);

		if(itrGlb != GTPStore::S11_GlbSessionPool[arrid].end())
			pGlbSession = itrGlb->second;

		if(pGlbSession != NULL)
		{
			strcpy(pGtpSession->IMSI, pGlbSession->IMSI);
			strcpy(pGtpSession->IMEI, pGlbSession->IMEI);
			strcpy(pGtpSession->MSISDN, pGlbSession->MSISDN);
			pGtpSession->RAT = pGlbSession->RAT;
		}
	}
}

VOID S11Interface::S11_CreateGlobalTable(GTPSession *pGtpSession)
{
	int glbIndex 	= -1;
	int arrid 		= 0;
	int elemid 		= 0;

	if((pGtpSession->MME_ctl_teid == 0) || (pGtpSession->SGW_ctl_teid == 0)) {
//		TheLog_nc_v2(Log::Info, name()," !!! Can't Create Global Table MME Tid = %u| SWG Tid = %u", pGtpSession->MME_ctl_teid, pGtpSession->SGW_ctl_teid);
		return;
	}

	pGtpSession->lastActivityTime = pGtpSession->StartTimeEpochSec;

	glbIndex = S11_GetGlbFreeIndex();

	arrid 	= glbIndex / S11_SESSION_POOL_ARRAY_ELEMENTS;  	// 200
	elemid 	= glbIndex % S11_SESSION_POOL_ARRAY_ELEMENTS; 	// 200

	GTPStore::S11_GlbSessionPool[arrid][elemid]->copy(pGtpSession);

	/* Till Create Session Request & Response to get
	 * MME & SGW Control Tunnel Id and SGW Bearer Tunnel Id
	 * eNodeB Bearer Tunnel Id we get in Modify Bearer Request
	 */
	GTPStore::S11_GlbMmeCtlIndexPool[INDEX_TEID(pGtpSession->MME_ctl_teid)][pGtpSession->MME_ctl_teid] = glbIndex;
	GTPStore::S11_GlbSgwCtlIndexPool[INDEX_TEID(pGtpSession->SGW_ctl_teid)][pGtpSession->SGW_ctl_teid] = glbIndex;
	GTPStore::S11_GlbSgwBeaIndexPool[INDEX_TEID(pGtpSession->SGW_s1u_teid)][pGtpSession->SGW_s1u_teid] = glbIndex;
}

VOID S11Interface::S11_UpdateGlobalTable(GTPSession *pGtpSession, MPacket *msgObj, int msgType)
{
	int glbIndex = -1;

	/* No need to update as there is no eNodeB Bearer Tunnel Id in Modify Bearer Request */
	if(pGtpSession->eNB_s1u_teid == 0) return;

	GTPSession *pGlbSession = NULL;

	if(pGtpSession->SGW_ctl_teid > 0)
		glbIndex = S11_GetGlbIndex(pGtpSession->SGW_ctl_teid, SGW_CTL);

	if(glbIndex == -1)
	{
		return;
	}
	else if(glbIndex >= 0)
	{
		int arrid = glbIndex / S11_SESSION_POOL_ARRAY_ELEMENTS;
		int elemid = glbIndex % S11_SESSION_POOL_ARRAY_ELEMENTS;

		std::map<int, GTPSession*>::iterator itrGlb = GTPStore::S11_GlbSessionPool[arrid].find(elemid);

		if(itrGlb != GTPStore::S11_GlbSessionPool[arrid].end())
			pGlbSession = itrGlb->second;
	}

	if(pGlbSession == NULL) return;

	pGlbSession->lastActivityTime = IPGlobal::CURRENT_EPOCH_SEC;

	/* Check ULI Parameters
	 * ========================================
	 * -- Tracking Area Identifier (TAI)
	 * ----- MCC (Mobile Country Code)
	 * ----- NMC (Mobile Network Code)
	 * -- E-UTRAN Cell Global Identifier (ECGI)
	 * ----- MCC
	 * ----- NMC
	 * ----- E-URAN Cell identifier (ECI)
	 * -------- eNodeB Id
	 * -------- CellId
	 */

	switch(msgType)
	{
		case MODIFY_BEARER_REQUEST:
				if(!pGlbSession->expiredFlag)
				{
					pGlbSession->active_session = true;

					if(pGlbSession->eNB_s1u_teid == 0)	/* Got the eNodeB Bearer Teid id 1st time */
					{
//						printf(" Got 1st eNodeB Id = %u inserting...\n", pGtpSession->eNB_ber_tid);
						pGlbSession->eNB_s1u_teid = pGtpSession->eNB_s1u_teid;
						GTPStore::S11_GlbeNBBeaIndexPool[INDEX_TEID(pGtpSession->eNB_s1u_teid)][pGtpSession->eNB_s1u_teid] = glbIndex;
					}
					else if((pGlbSession->eNB_s1u_teid != 0) && (pGtpSession->eNB_s1u_teid != pGlbSession->eNB_s1u_teid)) /* eNodeB S1U teid is getting modified now */
					{
						/* Modify the eNodeB Global Map */
						int tIndex = INDEX_TEID(pGlbSession->eNB_s1u_teid);

						std::map<uint32_t, int>::iterator itr = GTPStore::S11_GlbeNBBeaIndexPool[tIndex].find(pGlbSession->eNB_s1u_teid);
						if(itr != GTPStore::S11_GlbeNBBeaIndexPool[tIndex].end()) {
//							printf("Delete Old eNodeB = %u\n", pGlbSession->eNB_ber_tid);
							GTPStore::S11_GlbeNBBeaIndexPool[tIndex].erase(itr->first);
//							printf("Deleted...\n");

//							printf("Insert New eNodeB = %u\n", pGtpSession->eNB_ber_tid);
							pGlbSession->eNB_s1u_teid = pGtpSession->eNB_s1u_teid;
							GTPStore::S11_GlbeNBBeaIndexPool[INDEX_TEID(pGtpSession->eNB_s1u_teid)][pGtpSession->eNB_s1u_teid] = glbIndex;
//							printf("Inserted... \n");
						}
					}

					/* Update Rest of the values */
					if(pGtpSession->MCC > 0) {
						if(pGtpSession->MCC != pGlbSession->MCC)
							pGlbSession->MCC = pGtpSession->MCC;
					}
					else
						pGtpSession->MCC = pGlbSession->MCC;

					if(pGtpSession->MNC > 0) {
						if(pGtpSession->MNC != pGlbSession->MNC)
							pGlbSession->MNC = pGtpSession->MNC;
					}
					else
						pGtpSession->MCC = pGlbSession->MCC;

					if(pGtpSession->cellId > 0) {
						if(pGtpSession->cellId != pGlbSession->cellId)
							pGlbSession->cellId = pGtpSession->cellId;
					}
					else
						pGtpSession->cellId = pGlbSession->cellId;

					/* Check Radio Access RAT (Radio Access Technology) */
					if((pGtpSession->RAT > 0) && (pGtpSession->RAT != pGlbSession->RAT)){
						pGlbSession->RATOld = pGlbSession->RAT;
						pGlbSession->RAT = pGtpSession->RAT;
					}
				}
				break;

		case DELETE_SESSION_RESPONSE:
				pGlbSession->active_session 	= false;
				pGlbSession->expiredFlag 		= true;
				break;
	}

	strcpy(pGtpSession->IMSI, pGlbSession->IMSI);
	strcpy(pGtpSession->IMEI, pGlbSession->IMEI);
	strcpy(pGtpSession->MSISDN, pGlbSession->MSISDN);
	pGtpSession->RAT 		= pGlbSession->RAT;
	pGtpSession->MCC 		= pGlbSession->MCC;
	pGtpSession->MNC 		= pGlbSession->MNC;
	pGtpSession->cellId 	= pGlbSession->cellId;
}

int S11Interface::S11_GetGlbIndex(const uint32_t tunnelId, TIED_TYPE_V2 type)
{
	uint32_t teidIndex = INDEX_TEID(tunnelId);

	std::map<uint32_t, int>::iterator itr;

	switch(type)
	{
		case MME_CTL:
		{
				itr = GTPStore::S11_GlbMmeCtlIndexPool[teidIndex].find(tunnelId);
				if (itr != GTPStore::S11_GlbMmeCtlIndexPool[teidIndex].end())
					return itr->second;
		}
		break;

		case SGW_CTL:
		{
				itr = GTPStore::S11_GlbSgwCtlIndexPool[teidIndex].find(tunnelId);

				if (itr != GTPStore::S11_GlbSgwCtlIndexPool[teidIndex].end())
					return itr->second;
		}
		break;
	}
	return -1;
}

VOID S11Interface::S11_FlushSession(GTPSession *pGTPSession, int flushType)
{
	int idx = PKT_WRITE_TIME_INDEX(IPGlobal::CURRENT_EPOCH_SEC, IPGlobal::PKT_TIME_INDEX);

	pGTPSession->flushType = flushType;
	pGTPSession->FlushTimeEpochMicroSec = IPGlobal::CURRENT_EPOCH_MICRO_SEC;

	switch(instanceId)
	{
		case 0:
			switch(idx)
			{
				case 0:
					S11FlushRepository::s11FlushMap_sm_0_t_0[S11FlushRepository::s11FlushMap_sm_0_t_0_cnt].copy(pGTPSession);
					S11FlushRepository::s11FlushMap_sm_0_t_0_cnt++;
					break;
				case 1:
					S11FlushRepository::s11FlushMap_sm_0_t_1[S11FlushRepository::s11FlushMap_sm_0_t_1_cnt].copy(pGTPSession);
					S11FlushRepository::s11FlushMap_sm_0_t_1_cnt++;
					break;
				case 2:
					S11FlushRepository::s11FlushMap_sm_0_t_2[S11FlushRepository::s11FlushMap_sm_0_t_2_cnt].copy(pGTPSession);
					S11FlushRepository::s11FlushMap_sm_0_t_2_cnt++;
					break;
				case 3:
					S11FlushRepository::s11FlushMap_sm_0_t_3[S11FlushRepository::s11FlushMap_sm_0_t_3_cnt].copy(pGTPSession);
					S11FlushRepository::s11FlushMap_sm_0_t_3_cnt++;
					break;
				case 4:
					S11FlushRepository::s11FlushMap_sm_0_t_4[S11FlushRepository::s11FlushMap_sm_0_t_4_cnt].copy(pGTPSession);
					S11FlushRepository::s11FlushMap_sm_0_t_4_cnt++;
					break;
				case 5:
					S11FlushRepository::s11FlushMap_sm_0_t_5[S11FlushRepository::s11FlushMap_sm_0_t_5_cnt].copy(pGTPSession);
					S11FlushRepository::s11FlushMap_sm_0_t_5_cnt++;
					break;
				case 6:
					S11FlushRepository::s11FlushMap_sm_0_t_6[S11FlushRepository::s11FlushMap_sm_0_t_6_cnt].copy(pGTPSession);
					S11FlushRepository::s11FlushMap_sm_0_t_6_cnt++;
					break;
				case 7:
					S11FlushRepository::s11FlushMap_sm_0_t_7[S11FlushRepository::s11FlushMap_sm_0_t_7_cnt].copy(pGTPSession);
					S11FlushRepository::s11FlushMap_sm_0_t_7_cnt++;
					break;
				case 8:
					S11FlushRepository::s11FlushMap_sm_0_t_8[S11FlushRepository::s11FlushMap_sm_0_t_8_cnt].copy(pGTPSession);
					S11FlushRepository::s11FlushMap_sm_0_t_8_cnt++;
					break;
				case 9:
					S11FlushRepository::s11FlushMap_sm_0_t_9[S11FlushRepository::s11FlushMap_sm_0_t_9_cnt].copy(pGTPSession);
					S11FlushRepository::s11FlushMap_sm_0_t_9_cnt++;
					break;
			}
			break;

		case 1:
			switch(idx)
			{
				case 0:
					S11FlushRepository::s11FlushMap_sm_1_t_0[S11FlushRepository::s11FlushMap_sm_1_t_0_cnt].copy(pGTPSession);
					S11FlushRepository::s11FlushMap_sm_1_t_0_cnt++;
					break;
				case 1:
					S11FlushRepository::s11FlushMap_sm_1_t_1[S11FlushRepository::s11FlushMap_sm_1_t_1_cnt].copy(pGTPSession);
					S11FlushRepository::s11FlushMap_sm_1_t_1_cnt++;
					break;
				case 2:
					S11FlushRepository::s11FlushMap_sm_1_t_2[S11FlushRepository::s11FlushMap_sm_1_t_2_cnt].copy(pGTPSession);
					S11FlushRepository::s11FlushMap_sm_1_t_2_cnt++;
					break;
				case 3:
					S11FlushRepository::s11FlushMap_sm_1_t_3[S11FlushRepository::s11FlushMap_sm_1_t_3_cnt].copy(pGTPSession);
					S11FlushRepository::s11FlushMap_sm_1_t_3_cnt++;
					break;
				case 4:
					S11FlushRepository::s11FlushMap_sm_1_t_4[S11FlushRepository::s11FlushMap_sm_1_t_4_cnt].copy(pGTPSession);
					S11FlushRepository::s11FlushMap_sm_1_t_4_cnt++;
					break;
				case 5:
					S11FlushRepository::s11FlushMap_sm_1_t_5[S11FlushRepository::s11FlushMap_sm_1_t_5_cnt].copy(pGTPSession);
					S11FlushRepository::s11FlushMap_sm_1_t_5_cnt++;
					break;
				case 6:
					S11FlushRepository::s11FlushMap_sm_1_t_6[S11FlushRepository::s11FlushMap_sm_1_t_6_cnt].copy(pGTPSession);
					S11FlushRepository::s11FlushMap_sm_1_t_6_cnt++;
					break;
				case 7:
					S11FlushRepository::s11FlushMap_sm_1_t_7[S11FlushRepository::s11FlushMap_sm_1_t_7_cnt].copy(pGTPSession);
					S11FlushRepository::s11FlushMap_sm_1_t_7_cnt++;
					break;
				case 8:
					S11FlushRepository::s11FlushMap_sm_1_t_8[S11FlushRepository::s11FlushMap_sm_1_t_8_cnt].copy(pGTPSession);
					S11FlushRepository::s11FlushMap_sm_1_t_8_cnt++;
					break;
				case 9:
					S11FlushRepository::s11FlushMap_sm_1_t_9[S11FlushRepository::s11FlushMap_sm_1_t_9_cnt].copy(pGTPSession);
					S11FlushRepository::s11FlushMap_sm_1_t_9_cnt++;
					break;
			}
			break;

		case 2:
			switch(idx)
			{
				case 0:
					S11FlushRepository::s11FlushMap_sm_2_t_0[S11FlushRepository::s11FlushMap_sm_2_t_0_cnt].copy(pGTPSession);
					S11FlushRepository::s11FlushMap_sm_2_t_0_cnt++;
					break;
				case 1:
					S11FlushRepository::s11FlushMap_sm_2_t_1[S11FlushRepository::s11FlushMap_sm_2_t_1_cnt].copy(pGTPSession);
					S11FlushRepository::s11FlushMap_sm_2_t_1_cnt++;
					break;
				case 2:
					S11FlushRepository::s11FlushMap_sm_2_t_2[S11FlushRepository::s11FlushMap_sm_2_t_2_cnt].copy(pGTPSession);
					S11FlushRepository::s11FlushMap_sm_2_t_2_cnt++;
					break;
				case 3:
					S11FlushRepository::s11FlushMap_sm_2_t_3[S11FlushRepository::s11FlushMap_sm_2_t_3_cnt].copy(pGTPSession);
					S11FlushRepository::s11FlushMap_sm_2_t_3_cnt++;
					break;
				case 4:
					S11FlushRepository::s11FlushMap_sm_2_t_4[S11FlushRepository::s11FlushMap_sm_2_t_4_cnt].copy(pGTPSession);
					S11FlushRepository::s11FlushMap_sm_2_t_4_cnt++;
					break;
				case 5:
					S11FlushRepository::s11FlushMap_sm_2_t_5[S11FlushRepository::s11FlushMap_sm_2_t_5_cnt].copy(pGTPSession);
					S11FlushRepository::s11FlushMap_sm_2_t_5_cnt++;
					break;
				case 6:
					S11FlushRepository::s11FlushMap_sm_2_t_6[S11FlushRepository::s11FlushMap_sm_2_t_6_cnt].copy(pGTPSession);
					S11FlushRepository::s11FlushMap_sm_2_t_6_cnt++;
					break;
				case 7:
					S11FlushRepository::s11FlushMap_sm_2_t_7[S11FlushRepository::s11FlushMap_sm_2_t_7_cnt].copy(pGTPSession);
					S11FlushRepository::s11FlushMap_sm_2_t_7_cnt++;
					break;
				case 8:
					S11FlushRepository::s11FlushMap_sm_2_t_8[S11FlushRepository::s11FlushMap_sm_2_t_8_cnt].copy(pGTPSession);
					S11FlushRepository::s11FlushMap_sm_2_t_8_cnt++;
					break;
				case 9:
					S11FlushRepository::s11FlushMap_sm_2_t_9[S11FlushRepository::s11FlushMap_sm_2_t_9_cnt].copy(pGTPSession);
					S11FlushRepository::s11FlushMap_sm_2_t_9_cnt++;
					break;
			}
			break;

		case 3:
			switch(idx)
			{
				case 0:
					S11FlushRepository::s11FlushMap_sm_3_t_0[S11FlushRepository::s11FlushMap_sm_3_t_0_cnt].copy(pGTPSession);
					S11FlushRepository::s11FlushMap_sm_3_t_0_cnt++;
					break;
				case 1:
					S11FlushRepository::s11FlushMap_sm_3_t_1[S11FlushRepository::s11FlushMap_sm_3_t_1_cnt].copy(pGTPSession);
					S11FlushRepository::s11FlushMap_sm_3_t_1_cnt++;
					break;
				case 2:
					S11FlushRepository::s11FlushMap_sm_3_t_2[S11FlushRepository::s11FlushMap_sm_3_t_2_cnt].copy(pGTPSession);
					S11FlushRepository::s11FlushMap_sm_3_t_2_cnt++;
					break;
				case 3:
					S11FlushRepository::s11FlushMap_sm_3_t_3[S11FlushRepository::s11FlushMap_sm_3_t_3_cnt].copy(pGTPSession);
					S11FlushRepository::s11FlushMap_sm_3_t_3_cnt++;
					break;
				case 4:
					S11FlushRepository::s11FlushMap_sm_3_t_4[S11FlushRepository::s11FlushMap_sm_3_t_4_cnt].copy(pGTPSession);
					S11FlushRepository::s11FlushMap_sm_3_t_4_cnt++;
					break;
				case 5:
					S11FlushRepository::s11FlushMap_sm_3_t_5[S11FlushRepository::s11FlushMap_sm_3_t_5_cnt].copy(pGTPSession);
					S11FlushRepository::s11FlushMap_sm_3_t_5_cnt++;
					break;
				case 6:
					S11FlushRepository::s11FlushMap_sm_3_t_6[S11FlushRepository::s11FlushMap_sm_3_t_6_cnt].copy(pGTPSession);
					S11FlushRepository::s11FlushMap_sm_3_t_6_cnt++;
					break;
				case 7:
					S11FlushRepository::s11FlushMap_sm_3_t_7[S11FlushRepository::s11FlushMap_sm_3_t_7_cnt].copy(pGTPSession);
					S11FlushRepository::s11FlushMap_sm_3_t_7_cnt++;
					break;
				case 8:
					S11FlushRepository::s11FlushMap_sm_3_t_8[S11FlushRepository::s11FlushMap_sm_3_t_8_cnt].copy(pGTPSession);
					S11FlushRepository::s11FlushMap_sm_3_t_8_cnt++;
					break;
				case 9:
					S11FlushRepository::s11FlushMap_sm_3_t_9[S11FlushRepository::s11FlushMap_sm_3_t_9_cnt].copy(pGTPSession);
					S11FlushRepository::s11FlushMap_sm_3_t_9_cnt++;
					break;
			}
			break;
	}
}

VOID S11Interface::S11_TimeOutCleanSession(long curTimeEpochSec)
{
	GTPSession *pGtpSession;

	GTPStats::gtp_cr_session_count = S11_CSIndexPool.size();
	GTPStats::gtp_mb_session_count = S11_MBIndexPool.size();
	GTPStats::gtp_dl_session_count = S11_DSIndexPool.size();

	GTPStats::gtp_cr_session_cln_count = 0;

	for(auto elem = S11_CSIndexPool.begin(), next_elem = elem; elem != S11_CSIndexPool.end(); elem = next_elem)
	{
		++next_elem;
		pGtpSession = S11_GetSessionFromPool(elem->second);

		if( (pGtpSession->StartTimeEpochSec > 0 && (curTimeEpochSec - pGtpSession->StartTimeEpochSec) > IPGlobal::S11_IDLE_SESSION_TIMEOUT_IN_SEC) ||
			(pGtpSession->EndTimeEpochSec > 0 && (curTimeEpochSec - pGtpSession->EndTimeEpochSec) > IPGlobal::S11_IDLE_SESSION_TIMEOUT_IN_SEC) )
		{
			if(pGtpSession->EndTimeEpochSec == 0)
				pGtpSession->EndTimeEpochSec 	= curTimeEpochSec;

			if(pGtpSession->StartTimeEpochSec == 0)
				pGtpSession->StartTimeEpochSec 	= curTimeEpochSec;

//			S11_FlushSession(pGtpSession, FLUSH_TYPE_CLEANUP);
			GTPStats::gtp_cr_session_cln_count++;
			S11_CSIndexPool.erase(elem->first);
		}
	}

	GTPStats::gtp_dl_session_cln_count = 0;
	for(auto elem = S11_DSIndexPool.begin(), next_elem = elem; elem != S11_DSIndexPool.end(); elem = next_elem)
	{
		++next_elem;
		pGtpSession = S11_GetSessionFromPool(elem->second);

		if( (pGtpSession->StartTimeEpochSec > 0 && (curTimeEpochSec - pGtpSession->StartTimeEpochSec) > IPGlobal::S11_IDLE_SESSION_TIMEOUT_IN_SEC) ||
			(pGtpSession->EndTimeEpochSec > 0 && (curTimeEpochSec - pGtpSession->EndTimeEpochSec) > IPGlobal::S11_IDLE_SESSION_TIMEOUT_IN_SEC) )
		{
			if(pGtpSession->EndTimeEpochSec == 0)
				pGtpSession->EndTimeEpochSec 	= curTimeEpochSec;

			if(pGtpSession->StartTimeEpochSec == 0)
				pGtpSession->StartTimeEpochSec 	= curTimeEpochSec;

//			S11_FlushSession(pGtpSession, FLUSH_TYPE_CLEANUP);
			GTPStats::gtp_dl_session_cln_count++;
			S11_DSIndexPool.erase(elem->first);
		}
	}

	GTPStats::gtp_mb_session_cln_count = 0;
	for(auto elem = S11_MBIndexPool.begin(), next_elem = elem; elem != S11_MBIndexPool.end(); elem = next_elem)
	{
		++next_elem;
		pGtpSession = S11_GetSessionFromPool(elem->second);

		if( (pGtpSession->StartTimeEpochSec > 0 && (curTimeEpochSec - pGtpSession->StartTimeEpochSec) > IPGlobal::S11_IDLE_SESSION_TIMEOUT_IN_SEC) ||
			(pGtpSession->EndTimeEpochSec > 0 && (curTimeEpochSec - pGtpSession->EndTimeEpochSec) > IPGlobal::S11_IDLE_SESSION_TIMEOUT_IN_SEC) )
		{
			if(pGtpSession->EndTimeEpochSec == 0)
				pGtpSession->EndTimeEpochSec 	= curTimeEpochSec;

			if(pGtpSession->StartTimeEpochSec == 0)
				pGtpSession->StartTimeEpochSec 	= curTimeEpochSec;

//			S11_FlushSession(pGtpSession, FLUSH_TYPE_CLEANUP);
			GTPStats::gtp_mb_session_cln_count++;
			S11_MBIndexPool.erase(elem->first);
		}
	}
}

VOID S11Interface::S11_TimeOutCleanGlbSession(long curTimeEpochSec)
{
	int cleanCounter = 0;
	int glbIndex = -1;
	GTPSession *pGtpGlobalSession 				= NULL;
	GTPStats::gtpv2_glb_sessions_delete_count 	= 0;
	GTPStats::gtpv2_glb_sessions_active_count 	= 0;

	for(int i = 0; i < S11_SESSION_POOL_ARRAY_SIZE; i++)
	{
		for(int n = 0; n < S11_SESSION_POOL_ARRAY_ELEMENTS; n++)
		{
			if(GTPStore::S11GlbBitFlags[i].test(n))
			{
				glbIndex  = i * S11_SESSION_POOL_ARRAY_ELEMENTS + n;

				pGtpGlobalSession = GTPStore::S11_GlbSessionPool[i][n];

				if(pGtpGlobalSession->lastActivityTime > 0) /* 6 Hours */
				{
					if(((curTimeEpochSec - pGtpGlobalSession->lastActivityTime) >= IPGlobal::GN_GTPC_GLOBAL_SESSION_CLEANUP_TIMEOUT_SEC)
					                        || (pGtpGlobalSession->expiredFlag))
					{
						S11_DeleteGlbSession(pGtpGlobalSession, glbIndex);
						cleanCounter++;
					}
					else
						GTPStats::gtpv2_glb_sessions_active_count ++;
				}
			}
		}
	}
	GTPStats::gtpv2_glb_sessions_delete_count = cleanCounter;
}
