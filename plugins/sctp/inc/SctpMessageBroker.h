/*
 * S1APMessageBroker.h
 *
 *  Created on: 02-Mar-2020
 *      Author: singh
 */

#ifndef PLUGINS_SCTP_INC_SCTPMESSAGEBROKER_H_
#define PLUGINS_SCTP_INC_SCTPMESSAGEBROKER_H_

#include <unistd.h>

#include "IPGlobal.h"
#include "BaseConfig.h"
#include "Log.h"
#include "S1APGlobal.h"

using namespace std;

class SctpMessageBroker  : BaseConfig{
private:
	int interfaceId = 0;
	int routerId = 0;

	VOID 	setLogLevel (int level) {_thisLogLevel = level;}

	typedef struct _eNodeB
	{
		uint16_t 	smId;
		char 		TMSI[10];
	}eNodeB;

	typedef struct _tmsi
	{
		uint16_t 	smId;
		uint32_t 	eNodeB;
	}tmsi;

	std::map<uint32_t, tmsi> handoverMap;

	VOID 	SMStoreS1MMEPacket(Sctp *pSctp, int smId);

	VOID	SMStore_i_0(Sctp *pSctp, int smId, int idx);
	VOID	SMStore_i_1(Sctp *pSctp, int smId, int idx);
	VOID	SMStore_i_2(Sctp *pSctp, int smId, int idx);
	VOID	SMStore_i_3(Sctp *pSctp, int smId, int idx);
	VOID	SMStore_i_4(Sctp *pSctp, int smId, int idx);
	VOID	SMStore_i_5(Sctp *pSctp, int smId, int idx);
	VOID	SMStore_i_6(Sctp *pSctp, int smId, int idx);
	VOID	SMStore_i_7(Sctp *pSctp, int smId, int idx);

	VOID pushToQueue_i_0_r_0(Sctp *pSctp, int smId, int idx);
	VOID pushToQueue_i_0_r_1(Sctp *pSctp, int smId, int idx);
	VOID pushToQueue_i_0_r_2(Sctp *pSctp, int smId, int idx);
	VOID pushToQueue_i_0_r_3(Sctp *pSctp, int smId, int idx);
	VOID pushToQueue_i_0_r_4(Sctp *pSctp, int smId, int idx);
	VOID pushToQueue_i_0_r_5(Sctp *pSctp, int smId, int idx);
	VOID pushToQueue_i_0_r_6(Sctp *pSctp, int smId, int idx);
	VOID pushToQueue_i_0_r_7(Sctp *pSctp, int smId, int idx);

	VOID pushToQueue_i_1_r_0(Sctp *pSctp, int smId, int idx);
	VOID pushToQueue_i_1_r_1(Sctp *pSctp, int smId, int idx);
	VOID pushToQueue_i_1_r_2(Sctp *pSctp, int smId, int idx);
	VOID pushToQueue_i_1_r_3(Sctp *pSctp, int smId, int idx);
	VOID pushToQueue_i_1_r_4(Sctp *pSctp, int smId, int idx);
	VOID pushToQueue_i_1_r_5(Sctp *pSctp, int smId, int idx);
	VOID pushToQueue_i_1_r_6(Sctp *pSctp, int smId, int idx);
	VOID pushToQueue_i_1_r_7(Sctp *pSctp, int smId, int idx);

	VOID pushToQueue_i_2_r_0(Sctp *pSctp, int smId, int idx);
	VOID pushToQueue_i_2_r_1(Sctp *pSctp, int smId, int idx);
	VOID pushToQueue_i_2_r_2(Sctp *pSctp, int smId, int idx);
	VOID pushToQueue_i_2_r_3(Sctp *pSctp, int smId, int idx);
	VOID pushToQueue_i_2_r_4(Sctp *pSctp, int smId, int idx);
	VOID pushToQueue_i_2_r_5(Sctp *pSctp, int smId, int idx);
	VOID pushToQueue_i_2_r_6(Sctp *pSctp, int smId, int idx);
	VOID pushToQueue_i_2_r_7(Sctp *pSctp, int smId, int idx);

	VOID pushToQueue_i_3_r_0(Sctp *pSctp, int smId, int idx);
	VOID pushToQueue_i_3_r_1(Sctp *pSctp, int smId, int idx);
	VOID pushToQueue_i_3_r_2(Sctp *pSctp, int smId, int idx);
	VOID pushToQueue_i_3_r_3(Sctp *pSctp, int smId, int idx);
	VOID pushToQueue_i_3_r_4(Sctp *pSctp, int smId, int idx);
	VOID pushToQueue_i_3_r_5(Sctp *pSctp, int smId, int idx);
	VOID pushToQueue_i_3_r_6(Sctp *pSctp, int smId, int idx);
	VOID pushToQueue_i_3_r_7(Sctp *pSctp, int smId, int idx);

	VOID pushToQueue_i_4_r_0(Sctp *pSctp, int smId, int idx);
	VOID pushToQueue_i_4_r_1(Sctp *pSctp, int smId, int idx);
	VOID pushToQueue_i_4_r_2(Sctp *pSctp, int smId, int idx);
	VOID pushToQueue_i_4_r_3(Sctp *pSctp, int smId, int idx);
	VOID pushToQueue_i_4_r_4(Sctp *pSctp, int smId, int idx);
	VOID pushToQueue_i_4_r_5(Sctp *pSctp, int smId, int idx);
	VOID pushToQueue_i_4_r_6(Sctp *pSctp, int smId, int idx);
	VOID pushToQueue_i_4_r_7(Sctp *pSctp, int smId, int idx);

	VOID pushToQueue_i_5_r_0(Sctp *pSctp, int smId, int idx);
	VOID pushToQueue_i_5_r_1(Sctp *pSctp, int smId, int idx);
	VOID pushToQueue_i_5_r_2(Sctp *pSctp, int smId, int idx);
	VOID pushToQueue_i_5_r_3(Sctp *pSctp, int smId, int idx);
	VOID pushToQueue_i_5_r_4(Sctp *pSctp, int smId, int idx);
	VOID pushToQueue_i_5_r_5(Sctp *pSctp, int smId, int idx);
	VOID pushToQueue_i_5_r_6(Sctp *pSctp, int smId, int idx);
	VOID pushToQueue_i_5_r_7(Sctp *pSctp, int smId, int idx);

	VOID pushToQueue_i_6_r_0(Sctp *pSctp, int smId, int idx);
	VOID pushToQueue_i_6_r_1(Sctp *pSctp, int smId, int idx);
	VOID pushToQueue_i_6_r_2(Sctp *pSctp, int smId, int idx);
	VOID pushToQueue_i_6_r_3(Sctp *pSctp, int smId, int idx);
	VOID pushToQueue_i_6_r_4(Sctp *pSctp, int smId, int idx);
	VOID pushToQueue_i_6_r_5(Sctp *pSctp, int smId, int idx);
	VOID pushToQueue_i_6_r_6(Sctp *pSctp, int smId, int idx);
	VOID pushToQueue_i_6_r_7(Sctp *pSctp, int smId, int idx);

	VOID pushToQueue_i_7_r_0(Sctp *pSctp, int smId, int idx);
	VOID pushToQueue_i_7_r_1(Sctp *pSctp, int smId, int idx);
	VOID pushToQueue_i_7_r_2(Sctp *pSctp, int smId, int idx);
	VOID pushToQueue_i_7_r_3(Sctp *pSctp, int smId, int idx);
	VOID pushToQueue_i_7_r_4(Sctp *pSctp, int smId, int idx);
	VOID pushToQueue_i_7_r_5(Sctp *pSctp, int smId, int idx);
	VOID pushToQueue_i_7_r_6(Sctp *pSctp, int smId, int idx);
	VOID pushToQueue_i_7_r_7(Sctp *pSctp, int smId, int idx);

	VOID 	copySctpMsgObj(bool &msg_sm_busy, int &msg_sm_cnt, std::unordered_map<int, Sctp> &msg_sm, Sctp *sctpObj);

public:
	SctpMessageBroker(int intfid, int rId);
	~SctpMessageBroker();
	VOID 	store_S1MME_Packet(MPacket *msgObj);
};

#endif /* PLUGINS_SCTP_INC_SCTPMESSAGEBROKER_H_ */
