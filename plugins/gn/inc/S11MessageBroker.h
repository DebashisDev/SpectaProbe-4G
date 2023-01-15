/*
 * S11MessageBroker.h
 *
 *  Created on: 02-Mar-2020
 *      Author: singh
 */

#ifndef PLUGINS_GN_INC_S11MESSAGEBROKER_H_
#define PLUGINS_GN_INC_S11MESSAGEBROKER_H_

#include <unistd.h>

#include "IPGlobal.h"
#include "BaseConfig.h"
#include "Log.h"
#include "GTPGlobal.h"

class S11MessageBroker  : BaseConfig{

private:
	int interfaceId = 0;
	int routerId = 0;

	std::map<uint32_t, int> mmeTeidMap;
	std::map<uint32_t, int> sgwTeidMap;

	VOID 	setLogLevel (int level) {_thisLogLevel = level;}

	int 	get_SMS11(MPacket *msgObj);
	VOID 	SMStoreS11Packet(MPacket *msgObj, int smId);

	VOID	SMStore_i_0(MPacket *msgObj, int smId, int idx);
	VOID	SMStore_i_1(MPacket *msgObj, int smId, int idx);
	VOID	SMStore_i_2(MPacket *msgObj, int smId, int idx);
	VOID	SMStore_i_3(MPacket *msgObj, int smId, int idx);
	VOID	SMStore_i_4(MPacket *msgObj, int smId, int idx);
	VOID	SMStore_i_5(MPacket *msgObj, int smId, int idx);
	VOID	SMStore_i_6(MPacket *msgObj, int smId, int idx);
	VOID	SMStore_i_7(MPacket *msgObj, int smId, int idx);

	VOID pushToQueue_i_0_r_0(MPacket *msgObj, int smId, int idx);
	VOID pushToQueue_i_0_r_1(MPacket *msgObj, int smId, int idx);
	VOID pushToQueue_i_0_r_2(MPacket *msgObj, int smId, int idx);
	VOID pushToQueue_i_0_r_3(MPacket *msgObj, int smId, int idx);
	VOID pushToQueue_i_0_r_4(MPacket *msgObj, int smId, int idx);
	VOID pushToQueue_i_0_r_5(MPacket *msgObj, int smId, int idx);
	VOID pushToQueue_i_0_r_6(MPacket *msgObj, int smId, int idx);
	VOID pushToQueue_i_0_r_7(MPacket *msgObj, int smId, int idx);

	VOID pushToQueue_i_1_r_0(MPacket *msgObj, int smId, int idx);
	VOID pushToQueue_i_1_r_1(MPacket *msgObj, int smId, int idx);
	VOID pushToQueue_i_1_r_2(MPacket *msgObj, int smId, int idx);
	VOID pushToQueue_i_1_r_3(MPacket *msgObj, int smId, int idx);
	VOID pushToQueue_i_1_r_4(MPacket *msgObj, int smId, int idx);
	VOID pushToQueue_i_1_r_5(MPacket *msgObj, int smId, int idx);
	VOID pushToQueue_i_1_r_6(MPacket *msgObj, int smId, int idx);
	VOID pushToQueue_i_1_r_7(MPacket *msgObj, int smId, int idx);

	VOID pushToQueue_i_2_r_0(MPacket *msgObj, int smId, int idx);
	VOID pushToQueue_i_2_r_1(MPacket *msgObj, int smId, int idx);
	VOID pushToQueue_i_2_r_2(MPacket *msgObj, int smId, int idx);
	VOID pushToQueue_i_2_r_3(MPacket *msgObj, int smId, int idx);
	VOID pushToQueue_i_2_r_4(MPacket *msgObj, int smId, int idx);
	VOID pushToQueue_i_2_r_5(MPacket *msgObj, int smId, int idx);
	VOID pushToQueue_i_2_r_6(MPacket *msgObj, int smId, int idx);
	VOID pushToQueue_i_2_r_7(MPacket *msgObj, int smId, int idx);

	VOID pushToQueue_i_3_r_0(MPacket *msgObj, int smId, int idx);
	VOID pushToQueue_i_3_r_1(MPacket *msgObj, int smId, int idx);
	VOID pushToQueue_i_3_r_2(MPacket *msgObj, int smId, int idx);
	VOID pushToQueue_i_3_r_3(MPacket *msgObj, int smId, int idx);
	VOID pushToQueue_i_3_r_4(MPacket *msgObj, int smId, int idx);
	VOID pushToQueue_i_3_r_5(MPacket *msgObj, int smId, int idx);
	VOID pushToQueue_i_3_r_6(MPacket *msgObj, int smId, int idx);
	VOID pushToQueue_i_3_r_7(MPacket *msgObj, int smId, int idx);

	VOID pushToQueue_i_4_r_0(MPacket *msgObj, int smId, int idx);
	VOID pushToQueue_i_4_r_1(MPacket *msgObj, int smId, int idx);
	VOID pushToQueue_i_4_r_2(MPacket *msgObj, int smId, int idx);
	VOID pushToQueue_i_4_r_3(MPacket *msgObj, int smId, int idx);
	VOID pushToQueue_i_4_r_4(MPacket *msgObj, int smId, int idx);
	VOID pushToQueue_i_4_r_5(MPacket *msgObj, int smId, int idx);
	VOID pushToQueue_i_4_r_6(MPacket *msgObj, int smId, int idx);
	VOID pushToQueue_i_4_r_7(MPacket *msgObj, int smId, int idx);

	VOID pushToQueue_i_5_r_0(MPacket *msgObj, int smId, int idx);
	VOID pushToQueue_i_5_r_1(MPacket *msgObj, int smId, int idx);
	VOID pushToQueue_i_5_r_2(MPacket *msgObj, int smId, int idx);
	VOID pushToQueue_i_5_r_3(MPacket *msgObj, int smId, int idx);
	VOID pushToQueue_i_5_r_4(MPacket *msgObj, int smId, int idx);
	VOID pushToQueue_i_5_r_5(MPacket *msgObj, int smId, int idx);
	VOID pushToQueue_i_5_r_6(MPacket *msgObj, int smId, int idx);
	VOID pushToQueue_i_5_r_7(MPacket *msgObj, int smId, int idx);

	VOID pushToQueue_i_6_r_0(MPacket *msgObj, int smId, int idx);
	VOID pushToQueue_i_6_r_1(MPacket *msgObj, int smId, int idx);
	VOID pushToQueue_i_6_r_2(MPacket *msgObj, int smId, int idx);
	VOID pushToQueue_i_6_r_3(MPacket *msgObj, int smId, int idx);
	VOID pushToQueue_i_6_r_4(MPacket *msgObj, int smId, int idx);
	VOID pushToQueue_i_6_r_5(MPacket *msgObj, int smId, int idx);
	VOID pushToQueue_i_6_r_6(MPacket *msgObj, int smId, int idx);
	VOID pushToQueue_i_6_r_7(MPacket *msgObj, int smId, int idx);

	VOID pushToQueue_i_7_r_0(MPacket *msgObj, int smId, int idx);
	VOID pushToQueue_i_7_r_1(MPacket *msgObj, int smId, int idx);
	VOID pushToQueue_i_7_r_2(MPacket *msgObj, int smId, int idx);
	VOID pushToQueue_i_7_r_3(MPacket *msgObj, int smId, int idx);
	VOID pushToQueue_i_7_r_4(MPacket *msgObj, int smId, int idx);
	VOID pushToQueue_i_7_r_5(MPacket *msgObj, int smId, int idx);
	VOID pushToQueue_i_7_r_6(MPacket *msgObj, int smId, int idx);
	VOID pushToQueue_i_7_r_7(MPacket *msgObj, int smId, int idx);

	VOID 	copyS11MsgObj(bool &msg_sm_busy, int &msg_sm_cnt, std::unordered_map<int, MPacket> &msg_sm, MPacket *msgObj);

public:
	S11MessageBroker(int intfid, int rId);
	~S11MessageBroker();
	VOID 	store_S11_Packet(MPacket *msgObj);
};

#endif /* PLUGINS_GN_INC_S11MESSAGEBROKER_H_ */
