/*
 * S5S8Interface.h
 *
 *  Created on: 21 Feb 2020
 *      Author: Debashis
 */

#ifndef PLUGINS_GTPCV2_SRC_S5S8INTERFACE_H_
#define PLUGINS_GTPCV2_SRC_S5S8INTERFACE_H_

#include "Log.h"
#include "BaseConfig.h"
#include "GTPMsg.h"
#include "GTPGlobal.h"

using namespace std;

class S5S8Interface:BaseConfig
{
	public:
		S5S8Interface(int id);
		~S5S8Interface();

		VOID 	S5S8_InitializeSessionPool(int id);
		VOID 	S5S8_InitializeGlobalRepository();
		VOID	S5S8_ProcessMsgType(MPacket *msgObj);
		VOID	S5S8_TimeOutCleanGlbSession(long curTimeEpochSec);
		VOID	S5S8_TimeOutCleanSession(long curTimeEpochSec);

	private:
		VOID	lockgSession();
		VOID	unLockgSession();

		int instanceId;

		int cleanCounter;
		int glbIndex;

		std::string mcc_mnc, token;
		std::string delimiter;
		size_t pos = 0;

		std::map<int, GTPSession*> S5S8_SessionPool[S5S8_SESSION_POOL_ARRAY_SIZE];
		std::bitset<S5S8_SESSION_POOL_ARRAY_ELEMENTS> s5s8SessionBitFlags[S5S8_SESSION_POOL_ARRAY_SIZE];
		int S5S8FreeBitPos = 0;
		int s5s8freeBitPosMax = 0;

		std::map<uint32_t, int> S5S8_CSIndexPool;	/* Create Session */
		std::map<uint32_t, int> S5S8_MBIndexPool;	/* Modify Bearer */
		std::map<uint32_t, int> S5S8_DSIndexPool;	/* Delete Session */
		std::map<uint32_t, int> S5S8_UBIndexPool;	/* Update Bearer */

		pair <map<uint32_t, int>::iterator, bool> ptr;

		GTPSession* S5S8_GetSessionFromPool(int idx);
		int 		S5S8_GetFreeIndex();
		VOID		S5S8_ReleaseIndexFromSessionPool(int idx);

		uint32_t 	S5S8_GetGlbFreeIndex();
		VOID 		S5S8_DeleteGlbSession(GTPSession *pGtpGlobalSession, int index);
		VOID		S5S8_ReleaseIndexFromGlbPool(int glbIndex);

		VOID 		S5S8_CreateSessionReq(MPacket *msgObj);
		VOID 		S5S8_CreateSessionRsp(MPacket *msgObj);
		VOID		S5S8_ModifyBearerReq(MPacket *msgObj);
		VOID		S5S8_ModifyBearerRsp(MPacket *msgObj);
		VOID		S5S8_DeleteSessionReq(MPacket *msgObj);
		VOID		S5S8_DeleteSessionRsp(MPacket *msgObj);
		VOID		S5S8_UpdateBearerReq(MPacket *msgObj);
		VOID		S5S8_UpdateBearerRsp(MPacket *msgObj);

		VOID 		S5S8_ProcessResponse(bool cteateFlag, GTPSession *gtpSession, MPacket *msgObj);
		VOID 		S5S8_ProcessRequest(bool createFlag, GTPSession *gtpSession, MPacket *msgObj);
		VOID		S5S8_CreateGlobalTable(GTPSession *pGtpSession);
		VOID		S5S8_UpdateGlobalTable(GTPSession *pGtpSession, MPacket *msgObj, int msgType);
		int			S5S8_GetGlbIndex(const uint32_t tunnelId, TIED_TYPE_V2 type);
		VOID		S5S8_FlushSession(GTPSession *pGTPSession, int flushType);
};

#endif /* PLUGINS_GTPCV2_SRC_S5S8INTERFACE_H_ */
