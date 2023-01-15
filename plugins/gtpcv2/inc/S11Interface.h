/*
 * GTPV2Interface.h
 *
 *  Created on: Dec 9, 2019
 *      Author: Debashis
 */

#ifndef PLUGINS_GN_SRC_GTPV2INTERFACE_H_
#define PLUGINS_GN_SRC_GTPV2INTERFACE_H_

#include "Log.h"
#include "BaseConfig.h"
#include "GTPMsg.h"
#include "GTPGlobal.h"

using namespace std;

class S11Interface:BaseConfig
{
	public:
		S11Interface(int id);
		~S11Interface();

		VOID 	S11_InitializeSessionPool(int id);
		VOID 	S11_InitializeGlobalRepository();
		VOID	S11_ProcessMsgType(MPacket *msgObj);
		VOID	S11_TimeOutCleanGlbSession(long curTimeEpochSec);
		VOID	S11_TimeOutCleanSession(long curTimeEpochSec);

	private:
		VOID	lockgSession();
		VOID	unLockgSession();

		int instanceId;

		std::string mcc_mnc, token;
		std::string delimiter;
		size_t pos = 0;


		std::map<int, GTPSession*> S11_SessionPool[S11_SESSION_POOL_ARRAY_SIZE];
		std::bitset<S11_SESSION_POOL_ARRAY_ELEMENTS> s11SessionBitFlags[S11_SESSION_POOL_ARRAY_SIZE];
		int S11FreeBitPos = 0;
		int s11freeBitPosMax = 0;

		std::map<uint32_t, int> S11_CSIndexPool;		/* Create Session */
		std::map<uint32_t, int> S11_MBIndexPool;		/* Modify Bearer */
		std::map<uint32_t, int> S11_DSIndexPool;		/* Delete Session */
		std::map<uint32_t, int> S11_RABIndexPool;	/* Release Access Bearer */
		std::map<uint32_t, int> S11_DLIndexPool;		/* Down Link Data */

		GTPSession* S11_GetSessionFromPool(int idx);
		int 		S11_GetFreeIndex();
		VOID		S11_ReleaseIndexFromSessionPool(int idx);

		uint32_t S11_GetGlbFreeIndex();
		VOID 	S11_DeleteGlbSession(GTPSession *pGtpGlobalSession, int index);
		VOID		S11_ReleaseIndexFromGlbPool(int glbIndex);

		VOID 	S11_CreateSessionReq(MPacket *msgObj);
		VOID 	S11_CreateSessionRsp(MPacket *msgObj);
		VOID		S11_ModifyBearerReq(MPacket *msgObj);
		VOID		S11_ModifyBearerRsp(MPacket *msgObj);
		VOID		S11_DeleteSessionReq(MPacket *msgObj);
		VOID		S11_DeleteSessionRsp(MPacket *msgObj);
		VOID		S11_ReleaseAccessBearerReq(MPacket *msgObj);
		VOID		S11_ReleaseAccessBearerRsp(MPacket *msgObj);
		VOID		S11_DownLinkDataNotification(MPacket *msgObj);
		VOID		S11_DownLinkDataAcknowledgement(MPacket *msgObj);
		VOID		S11_DownLinkDataNotificationIndi(MPacket *msgObj);

		VOID 	S11_ProcessResponse(GTPSession *gtpSession, MPacket *msgObj);
		VOID 	S11_ProcessRequest(GTPSession *gtpSession, MPacket *msgObj);
		VOID		S11_CreateGlobalTable(GTPSession *pGtpSession);
		VOID		S11_UpdateGlobalTable(GTPSession *pGtpSession, MPacket *msgObj, int msgType);
		int		S11_GetGlbIndex(const uint32_t tunnelId, TIED_TYPE_V2 type);
		VOID		S11_FlushSession(GTPSession *pGTPSession, int flushType);
		VOID		S11_getUserInfo(GTPSession *pGtpSession);
};

#endif /* PLUGINS_GN_SRC_GTPV2INTERFACE_H_ */
