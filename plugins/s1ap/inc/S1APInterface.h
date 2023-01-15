/*
 * S1APSessionManager.h
 *
 *  Created on: 7 Jan 2020
 *      Author: Debashis
 */

#ifndef PLUGINS_S1AP_SRC_S1APSESSIONMANAGER_H_
#define PLUGINS_S1AP_SRC_S1APSESSIONMANAGER_H_

#include "IPGlobal.h"
#include "SpectaTypedef.h"
#include "BaseConfig.h"
#include "Log.h"
#include "S1APGlobal.h"
#include "s1ap.h"

class S1APInterface : BaseConfig
{
	public:
		S1APInterface(uint32_t sessionId);
		~S1APInterface();

		VOID 					processPDUType(Sctp *pSctpPacket);
		VOID					initializeSessionPool();

		VOID					S1AP_pduProcedure();
		VOID 					S1AP_TimeOutCleanSession(uint64_t sec);

		VOID					SM_ProcessPDUTypeMsg();
		VOID					SM_ProcessInitiatingMsg();
		VOID					SM_ProcessSuccessfulMsg();
		VOID					SM_ProcessUnSuccessfulMsg();

	private:
		static uint32_t		freeBitPos;
		static uint32_t 	freeBitPosMax;

		static uint16_t		instanceId;
		static BOOL			flushFlag;
		static char 		old_tmsi[10];
		static uint32_t 	old_eNodeBId;
		static sessionGlbData 	pGlbData;
		static uint32_t		sessionCleanCounter;
		static uint32_t 	sessionCounter;

		static std::bitset<S1AP_POOL_ARRAY_ELEMENTS> bitFlagsSession[S1AP_POOL_ARRAY_SIZE];
		static std::map<int, s1mmeSession*> sessionPoolMap[S1AP_POOL_ARRAY_SIZE];
		static std::map<uint32_t, int> eNodeBMap[S1AP_POOL_ARRAY_ELEMENTS];

		static VOID 					process_InitiatingMsg(Sctp *pSctpPacket);
		static VOID 					process_SuccessfulOutcomeMsg(Sctp *pSctpPacket);
		static VOID 					process_UnSuccessfulOutcomeMsg(Sctp *pSctpPacket);

		static VOID				lockS1apMap();
		static VOID				unLockS1apMap();

		static uint32_t			getFreeIndex();
		static VOID				releaseIndex(int idx);
		static s1mmeSession* 	getSessionFromPool(uint32_t idx);

		static VOID 			createGlobalData(s1mmeSession *pS1apSession);
		static VOID				updateGlobalData(Sctp *pSctpPacket);


		static VOID				process_initialUEMessage(s1mmeSession *pS1apSession, Sctp *pSctpPacket);

		static VOID				process_InitialContextSetupRequest(s1mmeSession *pS1apSession, Sctp *pSctpPacket);
		static VOID				process_initialContextSetupResponse(s1mmeSession *pS1apSession, Sctp *pSctpPacket);
		static VOID				process_initialContextSetupFailure(s1mmeSession *pS1apSession, Sctp *pSctpPacket);

		static VOID				process_handOverRequired(s1mmeSession *pS1apSession, Sctp *pSctpPacket);
		static VOID				process_handOverCommand(s1mmeSession *pS1apSession, Sctp *pSctpPacket);
		static VOID				process_handOverPreparationFailure(s1mmeSession *pS1apSession, Sctp *pSctpPacket);

		static VOID				process_handOverRequest(s1mmeSession *pS1apSession, Sctp *pSctpPacket);
		static VOID				process_handOverRequestAcknowledge(s1mmeSession *pS1apSession, Sctp *pSctpPacket);
		static VOID				process_handOverFailure(s1mmeSession *pS1apSession, Sctp *pSctpPacket);

		static VOID				process_handOverNotify(s1mmeSession *pS1apSession, Sctp *pSctpPacket);

		static VOID				process_handOverCancel(s1mmeSession *pS1apSession, Sctp *pSctpPacket);
		static VOID				process_handOverCancelAcknowledge(s1mmeSession *pS1apSession, Sctp *pSctpPacket);

		static VOID				process_downLinkNASTransport(s1mmeSession *pS1apSession, Sctp *pSctpPacket);
		static VOID				process_upLinkNASTransport(s1mmeSession *pS1apSession, Sctp *pSctpPacket);

		static VOID				process_contextReleaseRequest(s1mmeSession *pS1apSession, Sctp *pSctpPacket);

		static VOID				process_contextReleaseCommand(s1mmeSession *pS1apSession, Sctp *pSctpPacket);
		static VOID				process_contextReleaseComplete(s1mmeSession *pS1apSession, Sctp *pSctpPacket);

		static VOID 			process_UserInformation(s1mmeSession *pS1apSession, Sctp *pSctpPacket);

		static s1mmeSession* 	get_S1APSession(Sctp *pSctpPacket, BOOL *flag, BOOL create);

		static VOID				checkSMMType(procedureData *pData, uint32_t msgType, uint32_t enode);
		static VOID				checkMMMType(procedureData *pData, uint32_t msgType, uint32_t enode);

		static VOID				flushSession(s1mmeSession *pS1apSession, bool erase);
		static VOID				storeSession_sm_0(int index, s1mmeSession *pS1apSession);
		static VOID				storeSession_sm_1(int index, s1mmeSession *pS1apSession);
		static VOID				storeSession_sm_2(int index, s1mmeSession *pS1apSession);
		static VOID				storeSession_sm_3(int index, s1mmeSession *pS1apSession);

		VOID 					cleanTimedOutSessions(s1mmeSession *pS1apSession);
};

#endif /* PLUGINS_S1AP_SRC_S1APSESSIONMANAGER_H_ */
