/*
 * IPMessageBroker.h
 *
 *  Created on: Apr 24, 2017
 *      Author: Debashis
 */

#ifndef PLUGINS_TCP_SRC_IPMESSAGEBROKER_H_
#define PLUGINS_TCP_SRC_IPMESSAGEBROKER_H_

#include <unistd.h>

#include "IPGlobal.h"
#include "BaseConfig.h"
#include "TCPUDPGlobal.h"
#include "Log.h"

class S1UMessageBroker : BaseConfig{

public:
	S1UMessageBroker(int intfid, int rId);
	~S1UMessageBroker();

	VOID store_S1U_Packet(MPacket *msgObj);

private:
	int interfaceId = 0;
	int routerId = 0;

	int pktCheckBatchSize = 0;

	VOID 	setLogLevel (int level) {_thisLogLevel = level;}

	VOID getSessionManagerId(uint16_t lastDigit, int *startSmId);

	VOID pushMessageToQueue(int smid, MPacket *msgObj);

	VOID pushMessageToQueue_i_0(int smid, int idx, MPacket *msgObj);
	VOID pushMessageToQueue_i_1(int smid, int idx, MPacket *msgObj);
	VOID pushMessageToQueue_i_2(int smid, int idx, MPacket *msgObj);
	VOID pushMessageToQueue_i_3(int smid, int idx, MPacket *msgObj);
	VOID pushMessageToQueue_i_4(int smid, int idx, MPacket *msgObj);
	VOID pushMessageToQueue_i_5(int smid, int idx, MPacket *msgObj);
	VOID pushMessageToQueue_i_6(int smid, int idx, MPacket *msgObj);
	VOID pushMessageToQueue_i_7(int smid, int idx, MPacket *msgObj);

	VOID pushGTPCMessageToSmgr(MPacket *msgObj);
	VOID pushGTPUMessageToSmgr(MPacket *msgObj);

	VOID copyMsgObj(int smid, int idx, bool &ip_msg_sm_busy, int &ip_msg_sm_cnt, std::unordered_map<int, MPacket> &ip_msg_sm, MPacket *msgObj);
	VOID pushToQueue_i_0_r_0(int smid, int idx, MPacket *msgObj);
	VOID pushToQueue_i_0_r_1(int smid, int idx, MPacket *msgObj);
	VOID pushToQueue_i_0_r_2(int smid, int idx, MPacket *msgObj);
	VOID pushToQueue_i_0_r_3(int smid, int idx, MPacket *msgObj);
	VOID pushToQueue_i_0_r_4(int smid, int idx, MPacket *msgObj);
	VOID pushToQueue_i_0_r_5(int smid, int idx, MPacket *msgObj);
	VOID pushToQueue_i_0_r_6(int smid, int idx, MPacket *msgObj);
	VOID pushToQueue_i_0_r_7(int smid, int idx, MPacket *msgObj);

	VOID pushToQueue_i_1_r_0(int smid, int idx, MPacket *msgObj);
	VOID pushToQueue_i_1_r_1(int smid, int idx, MPacket *msgObj);
	VOID pushToQueue_i_1_r_2(int smid, int idx, MPacket *msgObj);
	VOID pushToQueue_i_1_r_3(int smid, int idx, MPacket *msgObj);
	VOID pushToQueue_i_1_r_4(int smid, int idx, MPacket *msgObj);
	VOID pushToQueue_i_1_r_5(int smid, int idx, MPacket *msgObj);
	VOID pushToQueue_i_1_r_6(int smid, int idx, MPacket *msgObj);
	VOID pushToQueue_i_1_r_7(int smid, int idx, MPacket *msgObj);

	VOID pushToQueue_i_2_r_0(int smid, int idx, MPacket *msgObj);
	VOID pushToQueue_i_2_r_1(int smid, int idx, MPacket *msgObj);
	VOID pushToQueue_i_2_r_2(int smid, int idx, MPacket *msgObj);
	VOID pushToQueue_i_2_r_3(int smid, int idx, MPacket *msgObj);
	VOID pushToQueue_i_2_r_4(int smid, int idx, MPacket *msgObj);
	VOID pushToQueue_i_2_r_5(int smid, int idx, MPacket *msgObj);
	VOID pushToQueue_i_2_r_6(int smid, int idx, MPacket *msgObj);
	VOID pushToQueue_i_2_r_7(int smid, int idx, MPacket *msgObj);

	VOID pushToQueue_i_3_r_0(int smid, int idx, MPacket *msgObj);
	VOID pushToQueue_i_3_r_1(int smid, int idx, MPacket *msgObj);
	VOID pushToQueue_i_3_r_2(int smid, int idx, MPacket *msgObj);
	VOID pushToQueue_i_3_r_3(int smid, int idx, MPacket *msgObj);
	VOID pushToQueue_i_3_r_4(int smid, int idx, MPacket *msgObj);
	VOID pushToQueue_i_3_r_5(int smid, int idx, MPacket *msgObj);
	VOID pushToQueue_i_3_r_6(int smid, int idx, MPacket *msgObj);
	VOID pushToQueue_i_3_r_7(int smid, int idx, MPacket *msgObj);

	VOID pushToQueue_i_4_r_0(int smid, int idx, MPacket *msgObj);
	VOID pushToQueue_i_4_r_1(int smid, int idx, MPacket *msgObj);
	VOID pushToQueue_i_4_r_2(int smid, int idx, MPacket *msgObj);
	VOID pushToQueue_i_4_r_3(int smid, int idx, MPacket *msgObj);
	VOID pushToQueue_i_4_r_4(int smid, int idx, MPacket *msgObj);
	VOID pushToQueue_i_4_r_5(int smid, int idx, MPacket *msgObj);
	VOID pushToQueue_i_4_r_6(int smid, int idx, MPacket *msgObj);
	VOID pushToQueue_i_4_r_7(int smid, int idx, MPacket *msgObj);

	VOID pushToQueue_i_5_r_0(int smid, int idx, MPacket *msgObj);
	VOID pushToQueue_i_5_r_1(int smid, int idx, MPacket *msgObj);
	VOID pushToQueue_i_5_r_2(int smid, int idx, MPacket *msgObj);
	VOID pushToQueue_i_5_r_3(int smid, int idx, MPacket *msgObj);
	VOID pushToQueue_i_5_r_4(int smid, int idx, MPacket *msgObj);
	VOID pushToQueue_i_5_r_5(int smid, int idx, MPacket *msgObj);
	VOID pushToQueue_i_5_r_6(int smid, int idx, MPacket *msgObj);
	VOID pushToQueue_i_5_r_7(int smid, int idx, MPacket *msgObj);

	VOID pushToQueue_i_6_r_0(int smid, int idx, MPacket *msgObj);
	VOID pushToQueue_i_6_r_1(int smid, int idx, MPacket *msgObj);
	VOID pushToQueue_i_6_r_2(int smid, int idx, MPacket *msgObj);
	VOID pushToQueue_i_6_r_3(int smid, int idx, MPacket *msgObj);
	VOID pushToQueue_i_6_r_4(int smid, int idx, MPacket *msgObj);
	VOID pushToQueue_i_6_r_5(int smid, int idx, MPacket *msgObj);
	VOID pushToQueue_i_6_r_6(int smid, int idx, MPacket *msgObj);
	VOID pushToQueue_i_6_r_7(int smid, int idx, MPacket *msgObj);

	VOID pushToQueue_i_7_r_0(int smid, int idx, MPacket *msgObj);
	VOID pushToQueue_i_7_r_1(int smid, int idx, MPacket *msgObj);
	VOID pushToQueue_i_7_r_2(int smid, int idx, MPacket *msgObj);
	VOID pushToQueue_i_7_r_3(int smid, int idx, MPacket *msgObj);
	VOID pushToQueue_i_7_r_4(int smid, int idx, MPacket *msgObj);
	VOID pushToQueue_i_7_r_5(int smid, int idx, MPacket *msgObj);
	VOID pushToQueue_i_7_r_6(int smid, int idx, MPacket *msgObj);
	VOID pushToQueue_i_7_r_7(int smid, int idx, MPacket *msgObj);
};

#endif /* PLUGINS_TCP_SRC_IPMESSAGEBROKER_H_ */
