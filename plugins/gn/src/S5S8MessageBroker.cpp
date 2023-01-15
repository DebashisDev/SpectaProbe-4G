/*
 * S5S8MessageBroker.cpp
 *
 *  Created on: 02-Mar-2020
 *      Author: singh
 */

#include "S5S8MessageBroker.h"

S5S8MessageBroker::S5S8MessageBroker(int intfid, int rId) {
	_thisLogLevel = 0;
	this->_name = "S5S8MessageBroker";
	this->setLogLevel(Log::theLog().level());

	this->interfaceId = intfid;
	this->routerId = rId;
}

S5S8MessageBroker::~S5S8MessageBroker() {
}

VOID S5S8MessageBroker::store_S5S8_Packet(MPacket *msgObj)
{
	int smId = -1;
	smId = msgObj->gtpcV2PktSeqNo % IPGlobal::S5S8_SESSION_MANAGER_INSTANCES;
	SMStoreS5S8Packet(msgObj, smId);
}

VOID S5S8MessageBroker::SMStoreS5S8Packet(MPacket *msgObj, int smid)
{
	int idx = PKT_WRITE_TIME_INDEX(IPGlobal::CURRENT_EPOCH_SEC, IPGlobal::PKT_TIME_INDEX);

	switch(this->interfaceId)
	{
		case 0:
			SMStore_i_0(msgObj, smid, idx);
			break;
		case 1:
			SMStore_i_1(msgObj, smid, idx);
			break;
		case 2:
			SMStore_i_2(msgObj, smid, idx);
			break;
		case 3:
			SMStore_i_3(msgObj, smid, idx);
			break;
		case 4:
			SMStore_i_4(msgObj, smid, idx);
			break;
		case 5:
			SMStore_i_5(msgObj, smid, idx);
			break;
		case 6:
			SMStore_i_6(msgObj, smid, idx);
			break;
		case 7:
			SMStore_i_7(msgObj, smid, idx);
			break;
	}
}


VOID S5S8MessageBroker::SMStore_i_0(MPacket *msgObj, int smid, int idx)
{
	switch(this->routerId)
	{
		case 0:
			pushToQueue_i_0_r_0(msgObj, smid, idx);
			break;
		case 1:
			pushToQueue_i_0_r_1(msgObj, smid, idx);
			break;
		case 2:
			pushToQueue_i_0_r_2(msgObj, smid, idx);
			break;
		case 3:
			pushToQueue_i_0_r_3(msgObj, smid, idx);
			break;
		case 4:
			pushToQueue_i_0_r_4(msgObj, smid, idx);
			break;
		case 5:
			pushToQueue_i_0_r_5(msgObj, smid, idx);
			break;
		case 6:
			pushToQueue_i_0_r_6(msgObj, smid, idx);
			break;
		case 7:
			pushToQueue_i_0_r_7(msgObj, smid, idx);
			break;
	}
}

VOID S5S8MessageBroker::SMStore_i_1(MPacket *msgObj, int smid, int idx)
{
	switch(this->routerId)
	{
		case 0:
			pushToQueue_i_1_r_0(msgObj, smid, idx);
			break;
		case 1:
			pushToQueue_i_1_r_1(msgObj, smid, idx);
			break;
		case 2:
			pushToQueue_i_1_r_2(msgObj, smid, idx);
			break;
		case 3:
			pushToQueue_i_1_r_3(msgObj, smid, idx);
			break;
		case 4:
			pushToQueue_i_1_r_4(msgObj, smid, idx);
			break;
		case 5:
			pushToQueue_i_1_r_5(msgObj, smid, idx);
			break;
		case 6:
			pushToQueue_i_1_r_6(msgObj, smid, idx);
			break;
		case 7:
			pushToQueue_i_1_r_7(msgObj, smid, idx);
			break;
	}
}

VOID S5S8MessageBroker::SMStore_i_2(MPacket *msgObj, int smid, int idx)
{
	switch(this->routerId)
	{
		case 0:
			pushToQueue_i_2_r_0(msgObj, smid, idx);
			break;
		case 1:
			pushToQueue_i_2_r_1(msgObj, smid, idx);
			break;
		case 2:
			pushToQueue_i_2_r_2(msgObj, smid, idx);
			break;
		case 3:
			pushToQueue_i_2_r_3(msgObj, smid, idx);
			break;
		case 4:
			pushToQueue_i_2_r_4(msgObj, smid, idx);
			break;
		case 5:
			pushToQueue_i_2_r_5(msgObj, smid, idx);
			break;
		case 6:
			pushToQueue_i_2_r_6(msgObj, smid, idx);
			break;
		case 7:
			pushToQueue_i_2_r_7(msgObj, smid, idx);
			break;
	}
}

VOID S5S8MessageBroker::SMStore_i_3(MPacket *msgObj, int smid, int idx)
{
	switch(this->routerId)
	{
		case 0:
			pushToQueue_i_3_r_0(msgObj, smid, idx);
			break;
		case 1:
			pushToQueue_i_3_r_1(msgObj, smid, idx);
			break;
		case 2:
			pushToQueue_i_3_r_2(msgObj, smid, idx);
			break;
		case 3:
			pushToQueue_i_3_r_3(msgObj, smid, idx);
			break;
		case 4:
			pushToQueue_i_3_r_4(msgObj, smid, idx);
			break;
		case 5:
			pushToQueue_i_3_r_5(msgObj, smid, idx);
			break;
		case 6:
			pushToQueue_i_3_r_6(msgObj, smid, idx);
			break;
		case 7:
			pushToQueue_i_3_r_7(msgObj, smid, idx);
			break;
	}
}

VOID S5S8MessageBroker::SMStore_i_4(MPacket *msgObj, int smid, int idx)
{
	switch(this->routerId)
	{
		case 0:
			pushToQueue_i_4_r_0(msgObj, smid, idx);
			break;
		case 1:
			pushToQueue_i_4_r_1(msgObj, smid, idx);
			break;
		case 2:
			pushToQueue_i_4_r_2(msgObj, smid, idx);
			break;
		case 3:
			pushToQueue_i_4_r_3(msgObj, smid, idx);
			break;
		case 4:
			pushToQueue_i_4_r_4(msgObj, smid, idx);
			break;
		case 5:
			pushToQueue_i_4_r_5(msgObj, smid, idx);
			break;
		case 6:
			pushToQueue_i_4_r_6(msgObj, smid, idx);
			break;
		case 7:
			pushToQueue_i_4_r_7(msgObj, smid, idx);
			break;
	}
}

VOID S5S8MessageBroker::SMStore_i_5(MPacket *msgObj, int smid, int idx)
{
	switch(this->routerId)
	{
		case 0:
			pushToQueue_i_5_r_0(msgObj, smid, idx);
			break;
		case 1:
			pushToQueue_i_5_r_1(msgObj, smid, idx);
			break;
		case 2:
			pushToQueue_i_5_r_2(msgObj, smid, idx);
			break;
		case 3:
			pushToQueue_i_5_r_3(msgObj, smid, idx);
			break;
		case 4:
			pushToQueue_i_5_r_4(msgObj, smid, idx);
			break;
		case 5:
			pushToQueue_i_5_r_5(msgObj, smid, idx);
			break;
		case 6:
			pushToQueue_i_5_r_6(msgObj, smid, idx);
			break;
		case 7:
			pushToQueue_i_5_r_7(msgObj, smid, idx);
			break;
	}
}

VOID S5S8MessageBroker::SMStore_i_6(MPacket *msgObj, int smid, int idx)
{
	switch(this->routerId)
	{
		case 0:
			pushToQueue_i_6_r_0(msgObj, smid, idx);
			break;
		case 1:
			pushToQueue_i_6_r_1(msgObj, smid, idx);
			break;
		case 2:
			pushToQueue_i_6_r_2(msgObj, smid, idx);
			break;
		case 3:
			pushToQueue_i_6_r_3(msgObj, smid, idx);
			break;
		case 4:
			pushToQueue_i_6_r_4(msgObj, smid, idx);
			break;
		case 5:
			pushToQueue_i_6_r_5(msgObj, smid, idx);
			break;
		case 6:
			pushToQueue_i_6_r_6(msgObj, smid, idx);
			break;
		case 7:
			pushToQueue_i_6_r_7(msgObj, smid, idx);
			break;
	}
}

VOID S5S8MessageBroker::SMStore_i_7(MPacket *msgObj, int smid, int idx)
{
	switch(this->routerId)
	{
		case 0:
			pushToQueue_i_7_r_0(msgObj, smid, idx);
			break;
		case 1:
			pushToQueue_i_7_r_1(msgObj, smid, idx);
			break;
		case 2:
			pushToQueue_i_7_r_2(msgObj, smid, idx);
			break;
		case 3:
			pushToQueue_i_7_r_3(msgObj, smid, idx);
			break;
		case 4:
			pushToQueue_i_7_r_4(msgObj, smid, idx);
			break;
		case 5:
			pushToQueue_i_7_r_5(msgObj, smid, idx);
			break;
		case 6:
			pushToQueue_i_7_r_6(msgObj, smid, idx);
			break;
		case 7:
			pushToQueue_i_7_r_7(msgObj, smid, idx);
			break;
	}
}

VOID S5S8MessageBroker::pushToQueue_i_0_r_0(MPacket *msgObj, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_0_r_0_t_0_busy, S5S8SMStore::mpacket_sm_0_i_0_r_0_t_0_cnt, S5S8SMStore::mpacket_sm_0_i_0_r_0_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_0_r_0_t_1_busy, S5S8SMStore::mpacket_sm_0_i_0_r_0_t_1_cnt, S5S8SMStore::mpacket_sm_0_i_0_r_0_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_0_r_0_t_2_busy, S5S8SMStore::mpacket_sm_0_i_0_r_0_t_2_cnt, S5S8SMStore::mpacket_sm_0_i_0_r_0_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_0_r_0_t_3_busy, S5S8SMStore::mpacket_sm_0_i_0_r_0_t_3_cnt, S5S8SMStore::mpacket_sm_0_i_0_r_0_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_0_r_0_t_4_busy, S5S8SMStore::mpacket_sm_0_i_0_r_0_t_4_cnt, S5S8SMStore::mpacket_sm_0_i_0_r_0_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_0_r_0_t_5_busy, S5S8SMStore::mpacket_sm_0_i_0_r_0_t_5_cnt, S5S8SMStore::mpacket_sm_0_i_0_r_0_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_0_r_0_t_6_busy, S5S8SMStore::mpacket_sm_0_i_0_r_0_t_6_cnt, S5S8SMStore::mpacket_sm_0_i_0_r_0_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_0_r_0_t_7_busy, S5S8SMStore::mpacket_sm_0_i_0_r_0_t_7_cnt, S5S8SMStore::mpacket_sm_0_i_0_r_0_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_0_r_0_t_8_busy, S5S8SMStore::mpacket_sm_0_i_0_r_0_t_8_cnt, S5S8SMStore::mpacket_sm_0_i_0_r_0_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_0_r_0_t_9_busy, S5S8SMStore::mpacket_sm_0_i_0_r_0_t_9_cnt, S5S8SMStore::mpacket_sm_0_i_0_r_0_t_9, msgObj);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_0_r_0_t_0_busy, S5S8SMStore::mpacket_sm_1_i_0_r_0_t_0_cnt, S5S8SMStore::mpacket_sm_1_i_0_r_0_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_0_r_0_t_1_busy, S5S8SMStore::mpacket_sm_1_i_0_r_0_t_1_cnt, S5S8SMStore::mpacket_sm_1_i_0_r_0_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_0_r_0_t_2_busy, S5S8SMStore::mpacket_sm_1_i_0_r_0_t_2_cnt, S5S8SMStore::mpacket_sm_1_i_0_r_0_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_0_r_0_t_3_busy, S5S8SMStore::mpacket_sm_1_i_0_r_0_t_3_cnt, S5S8SMStore::mpacket_sm_1_i_0_r_0_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_0_r_0_t_4_busy, S5S8SMStore::mpacket_sm_1_i_0_r_0_t_4_cnt, S5S8SMStore::mpacket_sm_1_i_0_r_0_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_0_r_0_t_5_busy, S5S8SMStore::mpacket_sm_1_i_0_r_0_t_5_cnt, S5S8SMStore::mpacket_sm_1_i_0_r_0_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_0_r_0_t_6_busy, S5S8SMStore::mpacket_sm_1_i_0_r_0_t_6_cnt, S5S8SMStore::mpacket_sm_1_i_0_r_0_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_0_r_0_t_7_busy, S5S8SMStore::mpacket_sm_1_i_0_r_0_t_7_cnt, S5S8SMStore::mpacket_sm_1_i_0_r_0_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_0_r_0_t_8_busy, S5S8SMStore::mpacket_sm_1_i_0_r_0_t_8_cnt, S5S8SMStore::mpacket_sm_1_i_0_r_0_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_0_r_0_t_9_busy, S5S8SMStore::mpacket_sm_1_i_0_r_0_t_9_cnt, S5S8SMStore::mpacket_sm_1_i_0_r_0_t_9, msgObj);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_0_r_0_t_0_busy, S5S8SMStore::mpacket_sm_2_i_0_r_0_t_0_cnt, S5S8SMStore::mpacket_sm_2_i_0_r_0_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_0_r_0_t_1_busy, S5S8SMStore::mpacket_sm_2_i_0_r_0_t_1_cnt, S5S8SMStore::mpacket_sm_2_i_0_r_0_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_0_r_0_t_2_busy, S5S8SMStore::mpacket_sm_2_i_0_r_0_t_2_cnt, S5S8SMStore::mpacket_sm_2_i_0_r_0_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_0_r_0_t_3_busy, S5S8SMStore::mpacket_sm_2_i_0_r_0_t_3_cnt, S5S8SMStore::mpacket_sm_2_i_0_r_0_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_0_r_0_t_4_busy, S5S8SMStore::mpacket_sm_2_i_0_r_0_t_4_cnt, S5S8SMStore::mpacket_sm_2_i_0_r_0_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_0_r_0_t_5_busy, S5S8SMStore::mpacket_sm_2_i_0_r_0_t_5_cnt, S5S8SMStore::mpacket_sm_2_i_0_r_0_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_0_r_0_t_6_busy, S5S8SMStore::mpacket_sm_2_i_0_r_0_t_6_cnt, S5S8SMStore::mpacket_sm_2_i_0_r_0_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_0_r_0_t_7_busy, S5S8SMStore::mpacket_sm_2_i_0_r_0_t_7_cnt, S5S8SMStore::mpacket_sm_2_i_0_r_0_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_0_r_0_t_8_busy, S5S8SMStore::mpacket_sm_2_i_0_r_0_t_8_cnt, S5S8SMStore::mpacket_sm_2_i_0_r_0_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_0_r_0_t_9_busy, S5S8SMStore::mpacket_sm_2_i_0_r_0_t_9_cnt, S5S8SMStore::mpacket_sm_2_i_0_r_0_t_9, msgObj);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_0_r_0_t_0_busy, S5S8SMStore::mpacket_sm_3_i_0_r_0_t_0_cnt, S5S8SMStore::mpacket_sm_3_i_0_r_0_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_0_r_0_t_1_busy, S5S8SMStore::mpacket_sm_3_i_0_r_0_t_1_cnt, S5S8SMStore::mpacket_sm_3_i_0_r_0_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_0_r_0_t_2_busy, S5S8SMStore::mpacket_sm_3_i_0_r_0_t_2_cnt, S5S8SMStore::mpacket_sm_3_i_0_r_0_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_0_r_0_t_3_busy, S5S8SMStore::mpacket_sm_3_i_0_r_0_t_3_cnt, S5S8SMStore::mpacket_sm_3_i_0_r_0_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_0_r_0_t_4_busy, S5S8SMStore::mpacket_sm_3_i_0_r_0_t_4_cnt, S5S8SMStore::mpacket_sm_3_i_0_r_0_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_0_r_0_t_5_busy, S5S8SMStore::mpacket_sm_3_i_0_r_0_t_5_cnt, S5S8SMStore::mpacket_sm_3_i_0_r_0_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_0_r_0_t_6_busy, S5S8SMStore::mpacket_sm_3_i_0_r_0_t_6_cnt, S5S8SMStore::mpacket_sm_3_i_0_r_0_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_0_r_0_t_7_busy, S5S8SMStore::mpacket_sm_3_i_0_r_0_t_7_cnt, S5S8SMStore::mpacket_sm_3_i_0_r_0_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_0_r_0_t_8_busy, S5S8SMStore::mpacket_sm_3_i_0_r_0_t_8_cnt, S5S8SMStore::mpacket_sm_3_i_0_r_0_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_0_r_0_t_9_busy, S5S8SMStore::mpacket_sm_3_i_0_r_0_t_9_cnt, S5S8SMStore::mpacket_sm_3_i_0_r_0_t_9, msgObj);
				break;
			}
			break;
	}
}

VOID S5S8MessageBroker::pushToQueue_i_0_r_1(MPacket *msgObj, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_0_r_1_t_0_busy, S5S8SMStore::mpacket_sm_0_i_0_r_1_t_0_cnt, S5S8SMStore::mpacket_sm_0_i_0_r_1_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_0_r_1_t_1_busy, S5S8SMStore::mpacket_sm_0_i_0_r_1_t_1_cnt, S5S8SMStore::mpacket_sm_0_i_0_r_1_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_0_r_1_t_2_busy, S5S8SMStore::mpacket_sm_0_i_0_r_1_t_2_cnt, S5S8SMStore::mpacket_sm_0_i_0_r_1_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_0_r_1_t_3_busy, S5S8SMStore::mpacket_sm_0_i_0_r_1_t_3_cnt, S5S8SMStore::mpacket_sm_0_i_0_r_1_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_0_r_1_t_4_busy, S5S8SMStore::mpacket_sm_0_i_0_r_1_t_4_cnt, S5S8SMStore::mpacket_sm_0_i_0_r_1_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_0_r_1_t_5_busy, S5S8SMStore::mpacket_sm_0_i_0_r_1_t_5_cnt, S5S8SMStore::mpacket_sm_0_i_0_r_1_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_0_r_1_t_6_busy, S5S8SMStore::mpacket_sm_0_i_0_r_1_t_6_cnt, S5S8SMStore::mpacket_sm_0_i_0_r_1_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_0_r_1_t_7_busy, S5S8SMStore::mpacket_sm_0_i_0_r_1_t_7_cnt, S5S8SMStore::mpacket_sm_0_i_0_r_1_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_0_r_1_t_8_busy, S5S8SMStore::mpacket_sm_0_i_0_r_1_t_8_cnt, S5S8SMStore::mpacket_sm_0_i_0_r_1_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_0_r_1_t_9_busy, S5S8SMStore::mpacket_sm_0_i_0_r_1_t_9_cnt, S5S8SMStore::mpacket_sm_0_i_0_r_1_t_9, msgObj);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_0_r_1_t_0_busy, S5S8SMStore::mpacket_sm_1_i_0_r_1_t_0_cnt, S5S8SMStore::mpacket_sm_1_i_0_r_1_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_0_r_1_t_1_busy, S5S8SMStore::mpacket_sm_1_i_0_r_1_t_1_cnt, S5S8SMStore::mpacket_sm_1_i_0_r_1_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_0_r_1_t_2_busy, S5S8SMStore::mpacket_sm_1_i_0_r_1_t_2_cnt, S5S8SMStore::mpacket_sm_1_i_0_r_1_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_0_r_1_t_3_busy, S5S8SMStore::mpacket_sm_1_i_0_r_1_t_3_cnt, S5S8SMStore::mpacket_sm_1_i_0_r_1_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_0_r_1_t_4_busy, S5S8SMStore::mpacket_sm_1_i_0_r_1_t_4_cnt, S5S8SMStore::mpacket_sm_1_i_0_r_1_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_0_r_1_t_5_busy, S5S8SMStore::mpacket_sm_1_i_0_r_1_t_5_cnt, S5S8SMStore::mpacket_sm_1_i_0_r_1_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_0_r_1_t_6_busy, S5S8SMStore::mpacket_sm_1_i_0_r_1_t_6_cnt, S5S8SMStore::mpacket_sm_1_i_0_r_1_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_0_r_1_t_7_busy, S5S8SMStore::mpacket_sm_1_i_0_r_1_t_7_cnt, S5S8SMStore::mpacket_sm_1_i_0_r_1_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_0_r_1_t_8_busy, S5S8SMStore::mpacket_sm_1_i_0_r_1_t_8_cnt, S5S8SMStore::mpacket_sm_1_i_0_r_1_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_0_r_1_t_9_busy, S5S8SMStore::mpacket_sm_1_i_0_r_1_t_9_cnt, S5S8SMStore::mpacket_sm_1_i_0_r_1_t_9, msgObj);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_0_r_1_t_0_busy, S5S8SMStore::mpacket_sm_2_i_0_r_1_t_0_cnt, S5S8SMStore::mpacket_sm_2_i_0_r_1_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_0_r_1_t_1_busy, S5S8SMStore::mpacket_sm_2_i_0_r_1_t_1_cnt, S5S8SMStore::mpacket_sm_2_i_0_r_1_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_0_r_1_t_2_busy, S5S8SMStore::mpacket_sm_2_i_0_r_1_t_2_cnt, S5S8SMStore::mpacket_sm_2_i_0_r_1_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_0_r_1_t_3_busy, S5S8SMStore::mpacket_sm_2_i_0_r_1_t_3_cnt, S5S8SMStore::mpacket_sm_2_i_0_r_1_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_0_r_1_t_4_busy, S5S8SMStore::mpacket_sm_2_i_0_r_1_t_4_cnt, S5S8SMStore::mpacket_sm_2_i_0_r_1_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_0_r_1_t_5_busy, S5S8SMStore::mpacket_sm_2_i_0_r_1_t_5_cnt, S5S8SMStore::mpacket_sm_2_i_0_r_1_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_0_r_1_t_6_busy, S5S8SMStore::mpacket_sm_2_i_0_r_1_t_6_cnt, S5S8SMStore::mpacket_sm_2_i_0_r_1_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_0_r_1_t_7_busy, S5S8SMStore::mpacket_sm_2_i_0_r_1_t_7_cnt, S5S8SMStore::mpacket_sm_2_i_0_r_1_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_0_r_1_t_8_busy, S5S8SMStore::mpacket_sm_2_i_0_r_1_t_8_cnt, S5S8SMStore::mpacket_sm_2_i_0_r_1_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_0_r_1_t_9_busy, S5S8SMStore::mpacket_sm_2_i_0_r_1_t_9_cnt, S5S8SMStore::mpacket_sm_2_i_0_r_1_t_9, msgObj);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_0_r_1_t_0_busy, S5S8SMStore::mpacket_sm_3_i_0_r_1_t_0_cnt, S5S8SMStore::mpacket_sm_3_i_0_r_1_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_0_r_1_t_1_busy, S5S8SMStore::mpacket_sm_3_i_0_r_1_t_1_cnt, S5S8SMStore::mpacket_sm_3_i_0_r_1_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_0_r_1_t_2_busy, S5S8SMStore::mpacket_sm_3_i_0_r_1_t_2_cnt, S5S8SMStore::mpacket_sm_3_i_0_r_1_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_0_r_1_t_3_busy, S5S8SMStore::mpacket_sm_3_i_0_r_1_t_3_cnt, S5S8SMStore::mpacket_sm_3_i_0_r_1_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_0_r_1_t_4_busy, S5S8SMStore::mpacket_sm_3_i_0_r_1_t_4_cnt, S5S8SMStore::mpacket_sm_3_i_0_r_1_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_0_r_1_t_5_busy, S5S8SMStore::mpacket_sm_3_i_0_r_1_t_5_cnt, S5S8SMStore::mpacket_sm_3_i_0_r_1_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_0_r_1_t_6_busy, S5S8SMStore::mpacket_sm_3_i_0_r_1_t_6_cnt, S5S8SMStore::mpacket_sm_3_i_0_r_1_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_0_r_1_t_7_busy, S5S8SMStore::mpacket_sm_3_i_0_r_1_t_7_cnt, S5S8SMStore::mpacket_sm_3_i_0_r_1_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_0_r_1_t_8_busy, S5S8SMStore::mpacket_sm_3_i_0_r_1_t_8_cnt, S5S8SMStore::mpacket_sm_3_i_0_r_1_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_0_r_1_t_9_busy, S5S8SMStore::mpacket_sm_3_i_0_r_1_t_9_cnt, S5S8SMStore::mpacket_sm_3_i_0_r_1_t_9, msgObj);
				break;
			}
			break;
	}
}

VOID S5S8MessageBroker::pushToQueue_i_0_r_2(MPacket *msgObj, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_0_r_2_t_0_busy, S5S8SMStore::mpacket_sm_0_i_0_r_2_t_0_cnt, S5S8SMStore::mpacket_sm_0_i_0_r_2_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_0_r_2_t_1_busy, S5S8SMStore::mpacket_sm_0_i_0_r_2_t_1_cnt, S5S8SMStore::mpacket_sm_0_i_0_r_2_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_0_r_2_t_2_busy, S5S8SMStore::mpacket_sm_0_i_0_r_2_t_2_cnt, S5S8SMStore::mpacket_sm_0_i_0_r_2_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_0_r_2_t_3_busy, S5S8SMStore::mpacket_sm_0_i_0_r_2_t_3_cnt, S5S8SMStore::mpacket_sm_0_i_0_r_2_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_0_r_2_t_4_busy, S5S8SMStore::mpacket_sm_0_i_0_r_2_t_4_cnt, S5S8SMStore::mpacket_sm_0_i_0_r_2_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_0_r_2_t_5_busy, S5S8SMStore::mpacket_sm_0_i_0_r_2_t_5_cnt, S5S8SMStore::mpacket_sm_0_i_0_r_2_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_0_r_2_t_6_busy, S5S8SMStore::mpacket_sm_0_i_0_r_2_t_6_cnt, S5S8SMStore::mpacket_sm_0_i_0_r_2_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_0_r_2_t_7_busy, S5S8SMStore::mpacket_sm_0_i_0_r_2_t_7_cnt, S5S8SMStore::mpacket_sm_0_i_0_r_2_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_0_r_2_t_8_busy, S5S8SMStore::mpacket_sm_0_i_0_r_2_t_8_cnt, S5S8SMStore::mpacket_sm_0_i_0_r_2_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_0_r_2_t_9_busy, S5S8SMStore::mpacket_sm_0_i_0_r_2_t_9_cnt, S5S8SMStore::mpacket_sm_0_i_0_r_2_t_9, msgObj);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_0_r_2_t_0_busy, S5S8SMStore::mpacket_sm_1_i_0_r_2_t_0_cnt, S5S8SMStore::mpacket_sm_1_i_0_r_2_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_0_r_2_t_1_busy, S5S8SMStore::mpacket_sm_1_i_0_r_2_t_1_cnt, S5S8SMStore::mpacket_sm_1_i_0_r_2_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_0_r_2_t_2_busy, S5S8SMStore::mpacket_sm_1_i_0_r_2_t_2_cnt, S5S8SMStore::mpacket_sm_1_i_0_r_2_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_0_r_2_t_3_busy, S5S8SMStore::mpacket_sm_1_i_0_r_2_t_3_cnt, S5S8SMStore::mpacket_sm_1_i_0_r_2_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_0_r_2_t_4_busy, S5S8SMStore::mpacket_sm_1_i_0_r_2_t_4_cnt, S5S8SMStore::mpacket_sm_1_i_0_r_2_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_0_r_2_t_5_busy, S5S8SMStore::mpacket_sm_1_i_0_r_2_t_5_cnt, S5S8SMStore::mpacket_sm_1_i_0_r_2_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_0_r_2_t_6_busy, S5S8SMStore::mpacket_sm_1_i_0_r_2_t_6_cnt, S5S8SMStore::mpacket_sm_1_i_0_r_2_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_0_r_2_t_7_busy, S5S8SMStore::mpacket_sm_1_i_0_r_2_t_7_cnt, S5S8SMStore::mpacket_sm_1_i_0_r_2_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_0_r_2_t_8_busy, S5S8SMStore::mpacket_sm_1_i_0_r_2_t_8_cnt, S5S8SMStore::mpacket_sm_1_i_0_r_2_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_0_r_2_t_9_busy, S5S8SMStore::mpacket_sm_1_i_0_r_2_t_9_cnt, S5S8SMStore::mpacket_sm_1_i_0_r_2_t_9, msgObj);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_0_r_2_t_0_busy, S5S8SMStore::mpacket_sm_2_i_0_r_2_t_0_cnt, S5S8SMStore::mpacket_sm_2_i_0_r_2_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_0_r_2_t_1_busy, S5S8SMStore::mpacket_sm_2_i_0_r_2_t_1_cnt, S5S8SMStore::mpacket_sm_2_i_0_r_2_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_0_r_2_t_2_busy, S5S8SMStore::mpacket_sm_2_i_0_r_2_t_2_cnt, S5S8SMStore::mpacket_sm_2_i_0_r_2_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_0_r_2_t_3_busy, S5S8SMStore::mpacket_sm_2_i_0_r_2_t_3_cnt, S5S8SMStore::mpacket_sm_2_i_0_r_2_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_0_r_2_t_4_busy, S5S8SMStore::mpacket_sm_2_i_0_r_2_t_4_cnt, S5S8SMStore::mpacket_sm_2_i_0_r_2_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_0_r_2_t_5_busy, S5S8SMStore::mpacket_sm_2_i_0_r_2_t_5_cnt, S5S8SMStore::mpacket_sm_2_i_0_r_2_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_0_r_2_t_6_busy, S5S8SMStore::mpacket_sm_2_i_0_r_2_t_6_cnt, S5S8SMStore::mpacket_sm_2_i_0_r_2_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_0_r_2_t_7_busy, S5S8SMStore::mpacket_sm_2_i_0_r_2_t_7_cnt, S5S8SMStore::mpacket_sm_2_i_0_r_2_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_0_r_2_t_8_busy, S5S8SMStore::mpacket_sm_2_i_0_r_2_t_8_cnt, S5S8SMStore::mpacket_sm_2_i_0_r_2_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_0_r_2_t_9_busy, S5S8SMStore::mpacket_sm_2_i_0_r_2_t_9_cnt, S5S8SMStore::mpacket_sm_2_i_0_r_2_t_9, msgObj);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_0_r_2_t_0_busy, S5S8SMStore::mpacket_sm_3_i_0_r_2_t_0_cnt, S5S8SMStore::mpacket_sm_3_i_0_r_2_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_0_r_2_t_1_busy, S5S8SMStore::mpacket_sm_3_i_0_r_2_t_1_cnt, S5S8SMStore::mpacket_sm_3_i_0_r_2_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_0_r_2_t_2_busy, S5S8SMStore::mpacket_sm_3_i_0_r_2_t_2_cnt, S5S8SMStore::mpacket_sm_3_i_0_r_2_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_0_r_2_t_3_busy, S5S8SMStore::mpacket_sm_3_i_0_r_2_t_3_cnt, S5S8SMStore::mpacket_sm_3_i_0_r_2_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_0_r_2_t_4_busy, S5S8SMStore::mpacket_sm_3_i_0_r_2_t_4_cnt, S5S8SMStore::mpacket_sm_3_i_0_r_2_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_0_r_2_t_5_busy, S5S8SMStore::mpacket_sm_3_i_0_r_2_t_5_cnt, S5S8SMStore::mpacket_sm_3_i_0_r_2_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_0_r_2_t_6_busy, S5S8SMStore::mpacket_sm_3_i_0_r_2_t_6_cnt, S5S8SMStore::mpacket_sm_3_i_0_r_2_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_0_r_2_t_7_busy, S5S8SMStore::mpacket_sm_3_i_0_r_2_t_7_cnt, S5S8SMStore::mpacket_sm_3_i_0_r_2_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_0_r_2_t_8_busy, S5S8SMStore::mpacket_sm_3_i_0_r_2_t_8_cnt, S5S8SMStore::mpacket_sm_3_i_0_r_2_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_0_r_2_t_9_busy, S5S8SMStore::mpacket_sm_3_i_0_r_2_t_9_cnt, S5S8SMStore::mpacket_sm_3_i_0_r_2_t_9, msgObj);
				break;
			}
			break;
	}
}

VOID S5S8MessageBroker::pushToQueue_i_0_r_3(MPacket *msgObj, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_0_r_3_t_0_busy, S5S8SMStore::mpacket_sm_0_i_0_r_3_t_0_cnt, S5S8SMStore::mpacket_sm_0_i_0_r_3_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_0_r_3_t_1_busy, S5S8SMStore::mpacket_sm_0_i_0_r_3_t_1_cnt, S5S8SMStore::mpacket_sm_0_i_0_r_3_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_0_r_3_t_2_busy, S5S8SMStore::mpacket_sm_0_i_0_r_3_t_2_cnt, S5S8SMStore::mpacket_sm_0_i_0_r_3_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_0_r_3_t_3_busy, S5S8SMStore::mpacket_sm_0_i_0_r_3_t_3_cnt, S5S8SMStore::mpacket_sm_0_i_0_r_3_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_0_r_3_t_4_busy, S5S8SMStore::mpacket_sm_0_i_0_r_3_t_4_cnt, S5S8SMStore::mpacket_sm_0_i_0_r_3_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_0_r_3_t_5_busy, S5S8SMStore::mpacket_sm_0_i_0_r_3_t_5_cnt, S5S8SMStore::mpacket_sm_0_i_0_r_3_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_0_r_3_t_6_busy, S5S8SMStore::mpacket_sm_0_i_0_r_3_t_6_cnt, S5S8SMStore::mpacket_sm_0_i_0_r_3_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_0_r_3_t_7_busy, S5S8SMStore::mpacket_sm_0_i_0_r_3_t_7_cnt, S5S8SMStore::mpacket_sm_0_i_0_r_3_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_0_r_3_t_8_busy, S5S8SMStore::mpacket_sm_0_i_0_r_3_t_8_cnt, S5S8SMStore::mpacket_sm_0_i_0_r_3_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_0_r_3_t_9_busy, S5S8SMStore::mpacket_sm_0_i_0_r_3_t_9_cnt, S5S8SMStore::mpacket_sm_0_i_0_r_3_t_9, msgObj);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_0_r_3_t_0_busy, S5S8SMStore::mpacket_sm_1_i_0_r_3_t_0_cnt, S5S8SMStore::mpacket_sm_1_i_0_r_3_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_0_r_3_t_1_busy, S5S8SMStore::mpacket_sm_1_i_0_r_3_t_1_cnt, S5S8SMStore::mpacket_sm_1_i_0_r_3_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_0_r_3_t_2_busy, S5S8SMStore::mpacket_sm_1_i_0_r_3_t_2_cnt, S5S8SMStore::mpacket_sm_1_i_0_r_3_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_0_r_3_t_3_busy, S5S8SMStore::mpacket_sm_1_i_0_r_3_t_3_cnt, S5S8SMStore::mpacket_sm_1_i_0_r_3_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_0_r_3_t_4_busy, S5S8SMStore::mpacket_sm_1_i_0_r_3_t_4_cnt, S5S8SMStore::mpacket_sm_1_i_0_r_3_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_0_r_3_t_5_busy, S5S8SMStore::mpacket_sm_1_i_0_r_3_t_5_cnt, S5S8SMStore::mpacket_sm_1_i_0_r_3_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_0_r_3_t_6_busy, S5S8SMStore::mpacket_sm_1_i_0_r_3_t_6_cnt, S5S8SMStore::mpacket_sm_1_i_0_r_3_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_0_r_3_t_7_busy, S5S8SMStore::mpacket_sm_1_i_0_r_3_t_7_cnt, S5S8SMStore::mpacket_sm_1_i_0_r_3_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_0_r_3_t_8_busy, S5S8SMStore::mpacket_sm_1_i_0_r_3_t_8_cnt, S5S8SMStore::mpacket_sm_1_i_0_r_3_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_0_r_3_t_9_busy, S5S8SMStore::mpacket_sm_1_i_0_r_3_t_9_cnt, S5S8SMStore::mpacket_sm_1_i_0_r_3_t_9, msgObj);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_0_r_3_t_0_busy, S5S8SMStore::mpacket_sm_2_i_0_r_3_t_0_cnt, S5S8SMStore::mpacket_sm_2_i_0_r_3_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_0_r_3_t_1_busy, S5S8SMStore::mpacket_sm_2_i_0_r_3_t_1_cnt, S5S8SMStore::mpacket_sm_2_i_0_r_3_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_0_r_3_t_2_busy, S5S8SMStore::mpacket_sm_2_i_0_r_3_t_2_cnt, S5S8SMStore::mpacket_sm_2_i_0_r_3_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_0_r_3_t_3_busy, S5S8SMStore::mpacket_sm_2_i_0_r_3_t_3_cnt, S5S8SMStore::mpacket_sm_2_i_0_r_3_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_0_r_3_t_4_busy, S5S8SMStore::mpacket_sm_2_i_0_r_3_t_4_cnt, S5S8SMStore::mpacket_sm_2_i_0_r_3_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_0_r_3_t_5_busy, S5S8SMStore::mpacket_sm_2_i_0_r_3_t_5_cnt, S5S8SMStore::mpacket_sm_2_i_0_r_3_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_0_r_3_t_6_busy, S5S8SMStore::mpacket_sm_2_i_0_r_3_t_6_cnt, S5S8SMStore::mpacket_sm_2_i_0_r_3_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_0_r_3_t_7_busy, S5S8SMStore::mpacket_sm_2_i_0_r_3_t_7_cnt, S5S8SMStore::mpacket_sm_2_i_0_r_3_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_0_r_3_t_8_busy, S5S8SMStore::mpacket_sm_2_i_0_r_3_t_8_cnt, S5S8SMStore::mpacket_sm_2_i_0_r_3_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_0_r_3_t_9_busy, S5S8SMStore::mpacket_sm_2_i_0_r_3_t_9_cnt, S5S8SMStore::mpacket_sm_2_i_0_r_3_t_9, msgObj);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_0_r_3_t_0_busy, S5S8SMStore::mpacket_sm_3_i_0_r_3_t_0_cnt, S5S8SMStore::mpacket_sm_3_i_0_r_3_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_0_r_3_t_1_busy, S5S8SMStore::mpacket_sm_3_i_0_r_3_t_1_cnt, S5S8SMStore::mpacket_sm_3_i_0_r_3_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_0_r_3_t_2_busy, S5S8SMStore::mpacket_sm_3_i_0_r_3_t_2_cnt, S5S8SMStore::mpacket_sm_3_i_0_r_3_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_0_r_3_t_3_busy, S5S8SMStore::mpacket_sm_3_i_0_r_3_t_3_cnt, S5S8SMStore::mpacket_sm_3_i_0_r_3_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_0_r_3_t_4_busy, S5S8SMStore::mpacket_sm_3_i_0_r_3_t_4_cnt, S5S8SMStore::mpacket_sm_3_i_0_r_3_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_0_r_3_t_5_busy, S5S8SMStore::mpacket_sm_3_i_0_r_3_t_5_cnt, S5S8SMStore::mpacket_sm_3_i_0_r_3_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_0_r_3_t_6_busy, S5S8SMStore::mpacket_sm_3_i_0_r_3_t_6_cnt, S5S8SMStore::mpacket_sm_3_i_0_r_3_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_0_r_3_t_7_busy, S5S8SMStore::mpacket_sm_3_i_0_r_3_t_7_cnt, S5S8SMStore::mpacket_sm_3_i_0_r_3_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_0_r_3_t_8_busy, S5S8SMStore::mpacket_sm_3_i_0_r_3_t_8_cnt, S5S8SMStore::mpacket_sm_3_i_0_r_3_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_0_r_3_t_9_busy, S5S8SMStore::mpacket_sm_3_i_0_r_3_t_9_cnt, S5S8SMStore::mpacket_sm_3_i_0_r_3_t_9, msgObj);
				break;
			}
			break;
	}
}

VOID S5S8MessageBroker::pushToQueue_i_0_r_4(MPacket *msgObj, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_0_r_4_t_0_busy, S5S8SMStore::mpacket_sm_0_i_0_r_4_t_0_cnt, S5S8SMStore::mpacket_sm_0_i_0_r_4_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_0_r_4_t_1_busy, S5S8SMStore::mpacket_sm_0_i_0_r_4_t_1_cnt, S5S8SMStore::mpacket_sm_0_i_0_r_4_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_0_r_4_t_2_busy, S5S8SMStore::mpacket_sm_0_i_0_r_4_t_2_cnt, S5S8SMStore::mpacket_sm_0_i_0_r_4_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_0_r_4_t_3_busy, S5S8SMStore::mpacket_sm_0_i_0_r_4_t_3_cnt, S5S8SMStore::mpacket_sm_0_i_0_r_4_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_0_r_4_t_4_busy, S5S8SMStore::mpacket_sm_0_i_0_r_4_t_4_cnt, S5S8SMStore::mpacket_sm_0_i_0_r_4_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_0_r_4_t_5_busy, S5S8SMStore::mpacket_sm_0_i_0_r_4_t_5_cnt, S5S8SMStore::mpacket_sm_0_i_0_r_4_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_0_r_4_t_6_busy, S5S8SMStore::mpacket_sm_0_i_0_r_4_t_6_cnt, S5S8SMStore::mpacket_sm_0_i_0_r_4_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_0_r_4_t_7_busy, S5S8SMStore::mpacket_sm_0_i_0_r_4_t_7_cnt, S5S8SMStore::mpacket_sm_0_i_0_r_4_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_0_r_4_t_8_busy, S5S8SMStore::mpacket_sm_0_i_0_r_4_t_8_cnt, S5S8SMStore::mpacket_sm_0_i_0_r_4_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_0_r_4_t_9_busy, S5S8SMStore::mpacket_sm_0_i_0_r_4_t_9_cnt, S5S8SMStore::mpacket_sm_0_i_0_r_4_t_9, msgObj);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_0_r_4_t_0_busy, S5S8SMStore::mpacket_sm_1_i_0_r_4_t_0_cnt, S5S8SMStore::mpacket_sm_1_i_0_r_4_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_0_r_4_t_1_busy, S5S8SMStore::mpacket_sm_1_i_0_r_4_t_1_cnt, S5S8SMStore::mpacket_sm_1_i_0_r_4_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_0_r_4_t_2_busy, S5S8SMStore::mpacket_sm_1_i_0_r_4_t_2_cnt, S5S8SMStore::mpacket_sm_1_i_0_r_4_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_0_r_4_t_3_busy, S5S8SMStore::mpacket_sm_1_i_0_r_4_t_3_cnt, S5S8SMStore::mpacket_sm_1_i_0_r_4_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_0_r_4_t_4_busy, S5S8SMStore::mpacket_sm_1_i_0_r_4_t_4_cnt, S5S8SMStore::mpacket_sm_1_i_0_r_4_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_0_r_4_t_5_busy, S5S8SMStore::mpacket_sm_1_i_0_r_4_t_5_cnt, S5S8SMStore::mpacket_sm_1_i_0_r_4_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_0_r_4_t_6_busy, S5S8SMStore::mpacket_sm_1_i_0_r_4_t_6_cnt, S5S8SMStore::mpacket_sm_1_i_0_r_4_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_0_r_4_t_7_busy, S5S8SMStore::mpacket_sm_1_i_0_r_4_t_7_cnt, S5S8SMStore::mpacket_sm_1_i_0_r_4_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_0_r_4_t_8_busy, S5S8SMStore::mpacket_sm_1_i_0_r_4_t_8_cnt, S5S8SMStore::mpacket_sm_1_i_0_r_4_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_0_r_4_t_9_busy, S5S8SMStore::mpacket_sm_1_i_0_r_4_t_9_cnt, S5S8SMStore::mpacket_sm_1_i_0_r_4_t_9, msgObj);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_0_r_4_t_0_busy, S5S8SMStore::mpacket_sm_2_i_0_r_4_t_0_cnt, S5S8SMStore::mpacket_sm_2_i_0_r_4_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_0_r_4_t_1_busy, S5S8SMStore::mpacket_sm_2_i_0_r_4_t_1_cnt, S5S8SMStore::mpacket_sm_2_i_0_r_4_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_0_r_4_t_2_busy, S5S8SMStore::mpacket_sm_2_i_0_r_4_t_2_cnt, S5S8SMStore::mpacket_sm_2_i_0_r_4_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_0_r_4_t_3_busy, S5S8SMStore::mpacket_sm_2_i_0_r_4_t_3_cnt, S5S8SMStore::mpacket_sm_2_i_0_r_4_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_0_r_4_t_4_busy, S5S8SMStore::mpacket_sm_2_i_0_r_4_t_4_cnt, S5S8SMStore::mpacket_sm_2_i_0_r_4_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_0_r_4_t_5_busy, S5S8SMStore::mpacket_sm_2_i_0_r_4_t_5_cnt, S5S8SMStore::mpacket_sm_2_i_0_r_4_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_0_r_4_t_6_busy, S5S8SMStore::mpacket_sm_2_i_0_r_4_t_6_cnt, S5S8SMStore::mpacket_sm_2_i_0_r_4_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_0_r_4_t_7_busy, S5S8SMStore::mpacket_sm_2_i_0_r_4_t_7_cnt, S5S8SMStore::mpacket_sm_2_i_0_r_4_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_0_r_4_t_8_busy, S5S8SMStore::mpacket_sm_2_i_0_r_4_t_8_cnt, S5S8SMStore::mpacket_sm_2_i_0_r_4_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_0_r_4_t_9_busy, S5S8SMStore::mpacket_sm_2_i_0_r_4_t_9_cnt, S5S8SMStore::mpacket_sm_2_i_0_r_4_t_9, msgObj);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_0_r_4_t_0_busy, S5S8SMStore::mpacket_sm_3_i_0_r_4_t_0_cnt, S5S8SMStore::mpacket_sm_3_i_0_r_4_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_0_r_4_t_1_busy, S5S8SMStore::mpacket_sm_3_i_0_r_4_t_1_cnt, S5S8SMStore::mpacket_sm_3_i_0_r_4_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_0_r_4_t_2_busy, S5S8SMStore::mpacket_sm_3_i_0_r_4_t_2_cnt, S5S8SMStore::mpacket_sm_3_i_0_r_4_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_0_r_4_t_3_busy, S5S8SMStore::mpacket_sm_3_i_0_r_4_t_3_cnt, S5S8SMStore::mpacket_sm_3_i_0_r_4_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_0_r_4_t_4_busy, S5S8SMStore::mpacket_sm_3_i_0_r_4_t_4_cnt, S5S8SMStore::mpacket_sm_3_i_0_r_4_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_0_r_4_t_5_busy, S5S8SMStore::mpacket_sm_3_i_0_r_4_t_5_cnt, S5S8SMStore::mpacket_sm_3_i_0_r_4_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_0_r_4_t_6_busy, S5S8SMStore::mpacket_sm_3_i_0_r_4_t_6_cnt, S5S8SMStore::mpacket_sm_3_i_0_r_4_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_0_r_4_t_7_busy, S5S8SMStore::mpacket_sm_3_i_0_r_4_t_7_cnt, S5S8SMStore::mpacket_sm_3_i_0_r_4_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_0_r_4_t_8_busy, S5S8SMStore::mpacket_sm_3_i_0_r_4_t_8_cnt, S5S8SMStore::mpacket_sm_3_i_0_r_4_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_0_r_4_t_9_busy, S5S8SMStore::mpacket_sm_3_i_0_r_4_t_9_cnt, S5S8SMStore::mpacket_sm_3_i_0_r_4_t_9, msgObj);
				break;
			}
			break;
	}
}

VOID S5S8MessageBroker::pushToQueue_i_0_r_5(MPacket *msgObj, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_0_r_5_t_0_busy, S5S8SMStore::mpacket_sm_0_i_0_r_5_t_0_cnt, S5S8SMStore::mpacket_sm_0_i_0_r_5_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_0_r_5_t_1_busy, S5S8SMStore::mpacket_sm_0_i_0_r_5_t_1_cnt, S5S8SMStore::mpacket_sm_0_i_0_r_5_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_0_r_5_t_2_busy, S5S8SMStore::mpacket_sm_0_i_0_r_5_t_2_cnt, S5S8SMStore::mpacket_sm_0_i_0_r_5_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_0_r_5_t_3_busy, S5S8SMStore::mpacket_sm_0_i_0_r_5_t_3_cnt, S5S8SMStore::mpacket_sm_0_i_0_r_5_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_0_r_5_t_4_busy, S5S8SMStore::mpacket_sm_0_i_0_r_5_t_4_cnt, S5S8SMStore::mpacket_sm_0_i_0_r_5_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_0_r_5_t_5_busy, S5S8SMStore::mpacket_sm_0_i_0_r_5_t_5_cnt, S5S8SMStore::mpacket_sm_0_i_0_r_5_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_0_r_5_t_6_busy, S5S8SMStore::mpacket_sm_0_i_0_r_5_t_6_cnt, S5S8SMStore::mpacket_sm_0_i_0_r_5_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_0_r_5_t_7_busy, S5S8SMStore::mpacket_sm_0_i_0_r_5_t_7_cnt, S5S8SMStore::mpacket_sm_0_i_0_r_5_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_0_r_5_t_8_busy, S5S8SMStore::mpacket_sm_0_i_0_r_5_t_8_cnt, S5S8SMStore::mpacket_sm_0_i_0_r_5_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_0_r_5_t_9_busy, S5S8SMStore::mpacket_sm_0_i_0_r_5_t_9_cnt, S5S8SMStore::mpacket_sm_0_i_0_r_5_t_9, msgObj);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_0_r_5_t_0_busy, S5S8SMStore::mpacket_sm_1_i_0_r_5_t_0_cnt, S5S8SMStore::mpacket_sm_1_i_0_r_5_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_0_r_5_t_1_busy, S5S8SMStore::mpacket_sm_1_i_0_r_5_t_1_cnt, S5S8SMStore::mpacket_sm_1_i_0_r_5_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_0_r_5_t_2_busy, S5S8SMStore::mpacket_sm_1_i_0_r_5_t_2_cnt, S5S8SMStore::mpacket_sm_1_i_0_r_5_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_0_r_5_t_3_busy, S5S8SMStore::mpacket_sm_1_i_0_r_5_t_3_cnt, S5S8SMStore::mpacket_sm_1_i_0_r_5_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_0_r_5_t_4_busy, S5S8SMStore::mpacket_sm_1_i_0_r_5_t_4_cnt, S5S8SMStore::mpacket_sm_1_i_0_r_5_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_0_r_5_t_5_busy, S5S8SMStore::mpacket_sm_1_i_0_r_5_t_5_cnt, S5S8SMStore::mpacket_sm_1_i_0_r_5_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_0_r_5_t_6_busy, S5S8SMStore::mpacket_sm_1_i_0_r_5_t_6_cnt, S5S8SMStore::mpacket_sm_1_i_0_r_5_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_0_r_5_t_7_busy, S5S8SMStore::mpacket_sm_1_i_0_r_5_t_7_cnt, S5S8SMStore::mpacket_sm_1_i_0_r_5_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_0_r_5_t_8_busy, S5S8SMStore::mpacket_sm_1_i_0_r_5_t_8_cnt, S5S8SMStore::mpacket_sm_1_i_0_r_5_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_0_r_5_t_9_busy, S5S8SMStore::mpacket_sm_1_i_0_r_5_t_9_cnt, S5S8SMStore::mpacket_sm_1_i_0_r_5_t_9, msgObj);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_0_r_5_t_0_busy, S5S8SMStore::mpacket_sm_2_i_0_r_5_t_0_cnt, S5S8SMStore::mpacket_sm_2_i_0_r_5_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_0_r_5_t_1_busy, S5S8SMStore::mpacket_sm_2_i_0_r_5_t_1_cnt, S5S8SMStore::mpacket_sm_2_i_0_r_5_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_0_r_5_t_2_busy, S5S8SMStore::mpacket_sm_2_i_0_r_5_t_2_cnt, S5S8SMStore::mpacket_sm_2_i_0_r_5_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_0_r_5_t_3_busy, S5S8SMStore::mpacket_sm_2_i_0_r_5_t_3_cnt, S5S8SMStore::mpacket_sm_2_i_0_r_5_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_0_r_5_t_4_busy, S5S8SMStore::mpacket_sm_2_i_0_r_5_t_4_cnt, S5S8SMStore::mpacket_sm_2_i_0_r_5_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_0_r_5_t_5_busy, S5S8SMStore::mpacket_sm_2_i_0_r_5_t_5_cnt, S5S8SMStore::mpacket_sm_2_i_0_r_5_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_0_r_5_t_6_busy, S5S8SMStore::mpacket_sm_2_i_0_r_5_t_6_cnt, S5S8SMStore::mpacket_sm_2_i_0_r_5_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_0_r_5_t_7_busy, S5S8SMStore::mpacket_sm_2_i_0_r_5_t_7_cnt, S5S8SMStore::mpacket_sm_2_i_0_r_5_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_0_r_5_t_8_busy, S5S8SMStore::mpacket_sm_2_i_0_r_5_t_8_cnt, S5S8SMStore::mpacket_sm_2_i_0_r_5_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_0_r_5_t_9_busy, S5S8SMStore::mpacket_sm_2_i_0_r_5_t_9_cnt, S5S8SMStore::mpacket_sm_2_i_0_r_5_t_9, msgObj);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_0_r_5_t_0_busy, S5S8SMStore::mpacket_sm_3_i_0_r_5_t_0_cnt, S5S8SMStore::mpacket_sm_3_i_0_r_5_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_0_r_5_t_1_busy, S5S8SMStore::mpacket_sm_3_i_0_r_5_t_1_cnt, S5S8SMStore::mpacket_sm_3_i_0_r_5_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_0_r_5_t_2_busy, S5S8SMStore::mpacket_sm_3_i_0_r_5_t_2_cnt, S5S8SMStore::mpacket_sm_3_i_0_r_5_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_0_r_5_t_3_busy, S5S8SMStore::mpacket_sm_3_i_0_r_5_t_3_cnt, S5S8SMStore::mpacket_sm_3_i_0_r_5_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_0_r_5_t_4_busy, S5S8SMStore::mpacket_sm_3_i_0_r_5_t_4_cnt, S5S8SMStore::mpacket_sm_3_i_0_r_5_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_0_r_5_t_5_busy, S5S8SMStore::mpacket_sm_3_i_0_r_5_t_5_cnt, S5S8SMStore::mpacket_sm_3_i_0_r_5_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_0_r_5_t_6_busy, S5S8SMStore::mpacket_sm_3_i_0_r_5_t_6_cnt, S5S8SMStore::mpacket_sm_3_i_0_r_5_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_0_r_5_t_7_busy, S5S8SMStore::mpacket_sm_3_i_0_r_5_t_7_cnt, S5S8SMStore::mpacket_sm_3_i_0_r_5_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_0_r_5_t_8_busy, S5S8SMStore::mpacket_sm_3_i_0_r_5_t_8_cnt, S5S8SMStore::mpacket_sm_3_i_0_r_5_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_0_r_5_t_9_busy, S5S8SMStore::mpacket_sm_3_i_0_r_5_t_9_cnt, S5S8SMStore::mpacket_sm_3_i_0_r_5_t_9, msgObj);
				break;
			}
			break;
	}
}

VOID S5S8MessageBroker::pushToQueue_i_0_r_6(MPacket *msgObj, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_0_r_6_t_0_busy, S5S8SMStore::mpacket_sm_0_i_0_r_6_t_0_cnt, S5S8SMStore::mpacket_sm_0_i_0_r_6_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_0_r_6_t_1_busy, S5S8SMStore::mpacket_sm_0_i_0_r_6_t_1_cnt, S5S8SMStore::mpacket_sm_0_i_0_r_6_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_0_r_6_t_2_busy, S5S8SMStore::mpacket_sm_0_i_0_r_6_t_2_cnt, S5S8SMStore::mpacket_sm_0_i_0_r_6_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_0_r_6_t_3_busy, S5S8SMStore::mpacket_sm_0_i_0_r_6_t_3_cnt, S5S8SMStore::mpacket_sm_0_i_0_r_6_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_0_r_6_t_4_busy, S5S8SMStore::mpacket_sm_0_i_0_r_6_t_4_cnt, S5S8SMStore::mpacket_sm_0_i_0_r_6_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_0_r_6_t_5_busy, S5S8SMStore::mpacket_sm_0_i_0_r_6_t_5_cnt, S5S8SMStore::mpacket_sm_0_i_0_r_6_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_0_r_6_t_6_busy, S5S8SMStore::mpacket_sm_0_i_0_r_6_t_6_cnt, S5S8SMStore::mpacket_sm_0_i_0_r_6_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_0_r_6_t_7_busy, S5S8SMStore::mpacket_sm_0_i_0_r_6_t_7_cnt, S5S8SMStore::mpacket_sm_0_i_0_r_6_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_0_r_6_t_8_busy, S5S8SMStore::mpacket_sm_0_i_0_r_6_t_8_cnt, S5S8SMStore::mpacket_sm_0_i_0_r_6_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_0_r_6_t_9_busy, S5S8SMStore::mpacket_sm_0_i_0_r_6_t_9_cnt, S5S8SMStore::mpacket_sm_0_i_0_r_6_t_9, msgObj);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_0_r_6_t_0_busy, S5S8SMStore::mpacket_sm_1_i_0_r_6_t_0_cnt, S5S8SMStore::mpacket_sm_1_i_0_r_6_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_0_r_6_t_1_busy, S5S8SMStore::mpacket_sm_1_i_0_r_6_t_1_cnt, S5S8SMStore::mpacket_sm_1_i_0_r_6_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_0_r_6_t_2_busy, S5S8SMStore::mpacket_sm_1_i_0_r_6_t_2_cnt, S5S8SMStore::mpacket_sm_1_i_0_r_6_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_0_r_6_t_3_busy, S5S8SMStore::mpacket_sm_1_i_0_r_6_t_3_cnt, S5S8SMStore::mpacket_sm_1_i_0_r_6_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_0_r_6_t_4_busy, S5S8SMStore::mpacket_sm_1_i_0_r_6_t_4_cnt, S5S8SMStore::mpacket_sm_1_i_0_r_6_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_0_r_6_t_5_busy, S5S8SMStore::mpacket_sm_1_i_0_r_6_t_5_cnt, S5S8SMStore::mpacket_sm_1_i_0_r_6_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_0_r_6_t_6_busy, S5S8SMStore::mpacket_sm_1_i_0_r_6_t_6_cnt, S5S8SMStore::mpacket_sm_1_i_0_r_6_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_0_r_6_t_7_busy, S5S8SMStore::mpacket_sm_1_i_0_r_6_t_7_cnt, S5S8SMStore::mpacket_sm_1_i_0_r_6_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_0_r_6_t_8_busy, S5S8SMStore::mpacket_sm_1_i_0_r_6_t_8_cnt, S5S8SMStore::mpacket_sm_1_i_0_r_6_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_0_r_6_t_9_busy, S5S8SMStore::mpacket_sm_1_i_0_r_6_t_9_cnt, S5S8SMStore::mpacket_sm_1_i_0_r_6_t_9, msgObj);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_0_r_6_t_0_busy, S5S8SMStore::mpacket_sm_2_i_0_r_6_t_0_cnt, S5S8SMStore::mpacket_sm_2_i_0_r_6_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_0_r_6_t_1_busy, S5S8SMStore::mpacket_sm_2_i_0_r_6_t_1_cnt, S5S8SMStore::mpacket_sm_2_i_0_r_6_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_0_r_6_t_2_busy, S5S8SMStore::mpacket_sm_2_i_0_r_6_t_2_cnt, S5S8SMStore::mpacket_sm_2_i_0_r_6_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_0_r_6_t_3_busy, S5S8SMStore::mpacket_sm_2_i_0_r_6_t_3_cnt, S5S8SMStore::mpacket_sm_2_i_0_r_6_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_0_r_6_t_4_busy, S5S8SMStore::mpacket_sm_2_i_0_r_6_t_4_cnt, S5S8SMStore::mpacket_sm_2_i_0_r_6_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_0_r_6_t_5_busy, S5S8SMStore::mpacket_sm_2_i_0_r_6_t_5_cnt, S5S8SMStore::mpacket_sm_2_i_0_r_6_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_0_r_6_t_6_busy, S5S8SMStore::mpacket_sm_2_i_0_r_6_t_6_cnt, S5S8SMStore::mpacket_sm_2_i_0_r_6_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_0_r_6_t_7_busy, S5S8SMStore::mpacket_sm_2_i_0_r_6_t_7_cnt, S5S8SMStore::mpacket_sm_2_i_0_r_6_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_0_r_6_t_8_busy, S5S8SMStore::mpacket_sm_2_i_0_r_6_t_8_cnt, S5S8SMStore::mpacket_sm_2_i_0_r_6_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_0_r_6_t_9_busy, S5S8SMStore::mpacket_sm_2_i_0_r_6_t_9_cnt, S5S8SMStore::mpacket_sm_2_i_0_r_6_t_9, msgObj);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_0_r_6_t_0_busy, S5S8SMStore::mpacket_sm_3_i_0_r_6_t_0_cnt, S5S8SMStore::mpacket_sm_3_i_0_r_6_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_0_r_6_t_1_busy, S5S8SMStore::mpacket_sm_3_i_0_r_6_t_1_cnt, S5S8SMStore::mpacket_sm_3_i_0_r_6_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_0_r_6_t_2_busy, S5S8SMStore::mpacket_sm_3_i_0_r_6_t_2_cnt, S5S8SMStore::mpacket_sm_3_i_0_r_6_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_0_r_6_t_3_busy, S5S8SMStore::mpacket_sm_3_i_0_r_6_t_3_cnt, S5S8SMStore::mpacket_sm_3_i_0_r_6_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_0_r_6_t_4_busy, S5S8SMStore::mpacket_sm_3_i_0_r_6_t_4_cnt, S5S8SMStore::mpacket_sm_3_i_0_r_6_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_0_r_6_t_5_busy, S5S8SMStore::mpacket_sm_3_i_0_r_6_t_5_cnt, S5S8SMStore::mpacket_sm_3_i_0_r_6_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_0_r_6_t_6_busy, S5S8SMStore::mpacket_sm_3_i_0_r_6_t_6_cnt, S5S8SMStore::mpacket_sm_3_i_0_r_6_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_0_r_6_t_7_busy, S5S8SMStore::mpacket_sm_3_i_0_r_6_t_7_cnt, S5S8SMStore::mpacket_sm_3_i_0_r_6_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_0_r_6_t_8_busy, S5S8SMStore::mpacket_sm_3_i_0_r_6_t_8_cnt, S5S8SMStore::mpacket_sm_3_i_0_r_6_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_0_r_6_t_9_busy, S5S8SMStore::mpacket_sm_3_i_0_r_6_t_9_cnt, S5S8SMStore::mpacket_sm_3_i_0_r_6_t_9, msgObj);
				break;
			}
			break;
	}
}

VOID S5S8MessageBroker::pushToQueue_i_0_r_7(MPacket *msgObj, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_0_r_7_t_0_busy, S5S8SMStore::mpacket_sm_0_i_0_r_7_t_0_cnt, S5S8SMStore::mpacket_sm_0_i_0_r_7_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_0_r_7_t_1_busy, S5S8SMStore::mpacket_sm_0_i_0_r_7_t_1_cnt, S5S8SMStore::mpacket_sm_0_i_0_r_7_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_0_r_7_t_2_busy, S5S8SMStore::mpacket_sm_0_i_0_r_7_t_2_cnt, S5S8SMStore::mpacket_sm_0_i_0_r_7_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_0_r_7_t_3_busy, S5S8SMStore::mpacket_sm_0_i_0_r_7_t_3_cnt, S5S8SMStore::mpacket_sm_0_i_0_r_7_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_0_r_7_t_4_busy, S5S8SMStore::mpacket_sm_0_i_0_r_7_t_4_cnt, S5S8SMStore::mpacket_sm_0_i_0_r_7_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_0_r_7_t_5_busy, S5S8SMStore::mpacket_sm_0_i_0_r_7_t_5_cnt, S5S8SMStore::mpacket_sm_0_i_0_r_7_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_0_r_7_t_6_busy, S5S8SMStore::mpacket_sm_0_i_0_r_7_t_6_cnt, S5S8SMStore::mpacket_sm_0_i_0_r_7_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_0_r_7_t_7_busy, S5S8SMStore::mpacket_sm_0_i_0_r_7_t_7_cnt, S5S8SMStore::mpacket_sm_0_i_0_r_7_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_0_r_7_t_8_busy, S5S8SMStore::mpacket_sm_0_i_0_r_7_t_8_cnt, S5S8SMStore::mpacket_sm_0_i_0_r_7_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_0_r_7_t_9_busy, S5S8SMStore::mpacket_sm_0_i_0_r_7_t_9_cnt, S5S8SMStore::mpacket_sm_0_i_0_r_7_t_9, msgObj);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_0_r_7_t_0_busy, S5S8SMStore::mpacket_sm_1_i_0_r_7_t_0_cnt, S5S8SMStore::mpacket_sm_1_i_0_r_7_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_0_r_7_t_1_busy, S5S8SMStore::mpacket_sm_1_i_0_r_7_t_1_cnt, S5S8SMStore::mpacket_sm_1_i_0_r_7_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_0_r_7_t_2_busy, S5S8SMStore::mpacket_sm_1_i_0_r_7_t_2_cnt, S5S8SMStore::mpacket_sm_1_i_0_r_7_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_0_r_7_t_3_busy, S5S8SMStore::mpacket_sm_1_i_0_r_7_t_3_cnt, S5S8SMStore::mpacket_sm_1_i_0_r_7_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_0_r_7_t_4_busy, S5S8SMStore::mpacket_sm_1_i_0_r_7_t_4_cnt, S5S8SMStore::mpacket_sm_1_i_0_r_7_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_0_r_7_t_5_busy, S5S8SMStore::mpacket_sm_1_i_0_r_7_t_5_cnt, S5S8SMStore::mpacket_sm_1_i_0_r_7_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_0_r_7_t_6_busy, S5S8SMStore::mpacket_sm_1_i_0_r_7_t_6_cnt, S5S8SMStore::mpacket_sm_1_i_0_r_7_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_0_r_7_t_7_busy, S5S8SMStore::mpacket_sm_1_i_0_r_7_t_7_cnt, S5S8SMStore::mpacket_sm_1_i_0_r_7_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_0_r_7_t_8_busy, S5S8SMStore::mpacket_sm_1_i_0_r_7_t_8_cnt, S5S8SMStore::mpacket_sm_1_i_0_r_7_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_0_r_7_t_9_busy, S5S8SMStore::mpacket_sm_1_i_0_r_7_t_9_cnt, S5S8SMStore::mpacket_sm_1_i_0_r_7_t_9, msgObj);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_0_r_7_t_0_busy, S5S8SMStore::mpacket_sm_2_i_0_r_7_t_0_cnt, S5S8SMStore::mpacket_sm_2_i_0_r_7_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_0_r_7_t_1_busy, S5S8SMStore::mpacket_sm_2_i_0_r_7_t_1_cnt, S5S8SMStore::mpacket_sm_2_i_0_r_7_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_0_r_7_t_2_busy, S5S8SMStore::mpacket_sm_2_i_0_r_7_t_2_cnt, S5S8SMStore::mpacket_sm_2_i_0_r_7_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_0_r_7_t_3_busy, S5S8SMStore::mpacket_sm_2_i_0_r_7_t_3_cnt, S5S8SMStore::mpacket_sm_2_i_0_r_7_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_0_r_7_t_4_busy, S5S8SMStore::mpacket_sm_2_i_0_r_7_t_4_cnt, S5S8SMStore::mpacket_sm_2_i_0_r_7_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_0_r_7_t_5_busy, S5S8SMStore::mpacket_sm_2_i_0_r_7_t_5_cnt, S5S8SMStore::mpacket_sm_2_i_0_r_7_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_0_r_7_t_6_busy, S5S8SMStore::mpacket_sm_2_i_0_r_7_t_6_cnt, S5S8SMStore::mpacket_sm_2_i_0_r_7_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_0_r_7_t_7_busy, S5S8SMStore::mpacket_sm_2_i_0_r_7_t_7_cnt, S5S8SMStore::mpacket_sm_2_i_0_r_7_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_0_r_7_t_8_busy, S5S8SMStore::mpacket_sm_2_i_0_r_7_t_8_cnt, S5S8SMStore::mpacket_sm_2_i_0_r_7_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_0_r_7_t_9_busy, S5S8SMStore::mpacket_sm_2_i_0_r_7_t_9_cnt, S5S8SMStore::mpacket_sm_2_i_0_r_7_t_9, msgObj);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_0_r_7_t_0_busy, S5S8SMStore::mpacket_sm_3_i_0_r_7_t_0_cnt, S5S8SMStore::mpacket_sm_3_i_0_r_7_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_0_r_7_t_1_busy, S5S8SMStore::mpacket_sm_3_i_0_r_7_t_1_cnt, S5S8SMStore::mpacket_sm_3_i_0_r_7_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_0_r_7_t_2_busy, S5S8SMStore::mpacket_sm_3_i_0_r_7_t_2_cnt, S5S8SMStore::mpacket_sm_3_i_0_r_7_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_0_r_7_t_3_busy, S5S8SMStore::mpacket_sm_3_i_0_r_7_t_3_cnt, S5S8SMStore::mpacket_sm_3_i_0_r_7_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_0_r_7_t_4_busy, S5S8SMStore::mpacket_sm_3_i_0_r_7_t_4_cnt, S5S8SMStore::mpacket_sm_3_i_0_r_7_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_0_r_7_t_5_busy, S5S8SMStore::mpacket_sm_3_i_0_r_7_t_5_cnt, S5S8SMStore::mpacket_sm_3_i_0_r_7_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_0_r_7_t_6_busy, S5S8SMStore::mpacket_sm_3_i_0_r_7_t_6_cnt, S5S8SMStore::mpacket_sm_3_i_0_r_7_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_0_r_7_t_7_busy, S5S8SMStore::mpacket_sm_3_i_0_r_7_t_7_cnt, S5S8SMStore::mpacket_sm_3_i_0_r_7_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_0_r_7_t_8_busy, S5S8SMStore::mpacket_sm_3_i_0_r_7_t_8_cnt, S5S8SMStore::mpacket_sm_3_i_0_r_7_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_0_r_7_t_9_busy, S5S8SMStore::mpacket_sm_3_i_0_r_7_t_9_cnt, S5S8SMStore::mpacket_sm_3_i_0_r_7_t_9, msgObj);
				break;
			}
			break;
	}
}


VOID S5S8MessageBroker::pushToQueue_i_1_r_0(MPacket *msgObj, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_1_r_0_t_0_busy, S5S8SMStore::mpacket_sm_0_i_1_r_0_t_0_cnt, S5S8SMStore::mpacket_sm_0_i_1_r_0_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_1_r_0_t_1_busy, S5S8SMStore::mpacket_sm_0_i_1_r_0_t_1_cnt, S5S8SMStore::mpacket_sm_0_i_1_r_0_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_1_r_0_t_2_busy, S5S8SMStore::mpacket_sm_0_i_1_r_0_t_2_cnt, S5S8SMStore::mpacket_sm_0_i_1_r_0_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_1_r_0_t_3_busy, S5S8SMStore::mpacket_sm_0_i_1_r_0_t_3_cnt, S5S8SMStore::mpacket_sm_0_i_1_r_0_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_1_r_0_t_4_busy, S5S8SMStore::mpacket_sm_0_i_1_r_0_t_4_cnt, S5S8SMStore::mpacket_sm_0_i_1_r_0_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_1_r_0_t_5_busy, S5S8SMStore::mpacket_sm_0_i_1_r_0_t_5_cnt, S5S8SMStore::mpacket_sm_0_i_1_r_0_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_1_r_0_t_6_busy, S5S8SMStore::mpacket_sm_0_i_1_r_0_t_6_cnt, S5S8SMStore::mpacket_sm_0_i_1_r_0_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_1_r_0_t_7_busy, S5S8SMStore::mpacket_sm_0_i_1_r_0_t_7_cnt, S5S8SMStore::mpacket_sm_0_i_1_r_0_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_1_r_0_t_8_busy, S5S8SMStore::mpacket_sm_0_i_1_r_0_t_8_cnt, S5S8SMStore::mpacket_sm_0_i_1_r_0_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_1_r_0_t_9_busy, S5S8SMStore::mpacket_sm_0_i_1_r_0_t_9_cnt, S5S8SMStore::mpacket_sm_0_i_1_r_0_t_9, msgObj);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_1_r_0_t_0_busy, S5S8SMStore::mpacket_sm_1_i_1_r_0_t_0_cnt, S5S8SMStore::mpacket_sm_1_i_1_r_0_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_1_r_0_t_1_busy, S5S8SMStore::mpacket_sm_1_i_1_r_0_t_1_cnt, S5S8SMStore::mpacket_sm_1_i_1_r_0_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_1_r_0_t_2_busy, S5S8SMStore::mpacket_sm_1_i_1_r_0_t_2_cnt, S5S8SMStore::mpacket_sm_1_i_1_r_0_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_1_r_0_t_3_busy, S5S8SMStore::mpacket_sm_1_i_1_r_0_t_3_cnt, S5S8SMStore::mpacket_sm_1_i_1_r_0_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_1_r_0_t_4_busy, S5S8SMStore::mpacket_sm_1_i_1_r_0_t_4_cnt, S5S8SMStore::mpacket_sm_1_i_1_r_0_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_1_r_0_t_5_busy, S5S8SMStore::mpacket_sm_1_i_1_r_0_t_5_cnt, S5S8SMStore::mpacket_sm_1_i_1_r_0_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_1_r_0_t_6_busy, S5S8SMStore::mpacket_sm_1_i_1_r_0_t_6_cnt, S5S8SMStore::mpacket_sm_1_i_1_r_0_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_1_r_0_t_7_busy, S5S8SMStore::mpacket_sm_1_i_1_r_0_t_7_cnt, S5S8SMStore::mpacket_sm_1_i_1_r_0_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_1_r_0_t_8_busy, S5S8SMStore::mpacket_sm_1_i_1_r_0_t_8_cnt, S5S8SMStore::mpacket_sm_1_i_1_r_0_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_1_r_0_t_9_busy, S5S8SMStore::mpacket_sm_1_i_1_r_0_t_9_cnt, S5S8SMStore::mpacket_sm_1_i_1_r_0_t_9, msgObj);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_1_r_0_t_0_busy, S5S8SMStore::mpacket_sm_2_i_1_r_0_t_0_cnt, S5S8SMStore::mpacket_sm_2_i_1_r_0_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_1_r_0_t_1_busy, S5S8SMStore::mpacket_sm_2_i_1_r_0_t_1_cnt, S5S8SMStore::mpacket_sm_2_i_1_r_0_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_1_r_0_t_2_busy, S5S8SMStore::mpacket_sm_2_i_1_r_0_t_2_cnt, S5S8SMStore::mpacket_sm_2_i_1_r_0_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_1_r_0_t_3_busy, S5S8SMStore::mpacket_sm_2_i_1_r_0_t_3_cnt, S5S8SMStore::mpacket_sm_2_i_1_r_0_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_1_r_0_t_4_busy, S5S8SMStore::mpacket_sm_2_i_1_r_0_t_4_cnt, S5S8SMStore::mpacket_sm_2_i_1_r_0_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_1_r_0_t_5_busy, S5S8SMStore::mpacket_sm_2_i_1_r_0_t_5_cnt, S5S8SMStore::mpacket_sm_2_i_1_r_0_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_1_r_0_t_6_busy, S5S8SMStore::mpacket_sm_2_i_1_r_0_t_6_cnt, S5S8SMStore::mpacket_sm_2_i_1_r_0_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_1_r_0_t_7_busy, S5S8SMStore::mpacket_sm_2_i_1_r_0_t_7_cnt, S5S8SMStore::mpacket_sm_2_i_1_r_0_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_1_r_0_t_8_busy, S5S8SMStore::mpacket_sm_2_i_1_r_0_t_8_cnt, S5S8SMStore::mpacket_sm_2_i_1_r_0_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_1_r_0_t_9_busy, S5S8SMStore::mpacket_sm_2_i_1_r_0_t_9_cnt, S5S8SMStore::mpacket_sm_2_i_1_r_0_t_9, msgObj);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_1_r_0_t_0_busy, S5S8SMStore::mpacket_sm_3_i_1_r_0_t_0_cnt, S5S8SMStore::mpacket_sm_3_i_1_r_0_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_1_r_0_t_1_busy, S5S8SMStore::mpacket_sm_3_i_1_r_0_t_1_cnt, S5S8SMStore::mpacket_sm_3_i_1_r_0_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_1_r_0_t_2_busy, S5S8SMStore::mpacket_sm_3_i_1_r_0_t_2_cnt, S5S8SMStore::mpacket_sm_3_i_1_r_0_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_1_r_0_t_3_busy, S5S8SMStore::mpacket_sm_3_i_1_r_0_t_3_cnt, S5S8SMStore::mpacket_sm_3_i_1_r_0_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_1_r_0_t_4_busy, S5S8SMStore::mpacket_sm_3_i_1_r_0_t_4_cnt, S5S8SMStore::mpacket_sm_3_i_1_r_0_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_1_r_0_t_5_busy, S5S8SMStore::mpacket_sm_3_i_1_r_0_t_5_cnt, S5S8SMStore::mpacket_sm_3_i_1_r_0_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_1_r_0_t_6_busy, S5S8SMStore::mpacket_sm_3_i_1_r_0_t_6_cnt, S5S8SMStore::mpacket_sm_3_i_1_r_0_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_1_r_0_t_7_busy, S5S8SMStore::mpacket_sm_3_i_1_r_0_t_7_cnt, S5S8SMStore::mpacket_sm_3_i_1_r_0_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_1_r_0_t_8_busy, S5S8SMStore::mpacket_sm_3_i_1_r_0_t_8_cnt, S5S8SMStore::mpacket_sm_3_i_1_r_0_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_1_r_0_t_9_busy, S5S8SMStore::mpacket_sm_3_i_1_r_0_t_9_cnt, S5S8SMStore::mpacket_sm_3_i_1_r_0_t_9, msgObj);
				break;
			}
			break;
	}
}

VOID S5S8MessageBroker::pushToQueue_i_1_r_1(MPacket *msgObj, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_1_r_1_t_0_busy, S5S8SMStore::mpacket_sm_0_i_1_r_1_t_0_cnt, S5S8SMStore::mpacket_sm_0_i_1_r_1_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_1_r_1_t_1_busy, S5S8SMStore::mpacket_sm_0_i_1_r_1_t_1_cnt, S5S8SMStore::mpacket_sm_0_i_1_r_1_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_1_r_1_t_2_busy, S5S8SMStore::mpacket_sm_0_i_1_r_1_t_2_cnt, S5S8SMStore::mpacket_sm_0_i_1_r_1_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_1_r_1_t_3_busy, S5S8SMStore::mpacket_sm_0_i_1_r_1_t_3_cnt, S5S8SMStore::mpacket_sm_0_i_1_r_1_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_1_r_1_t_4_busy, S5S8SMStore::mpacket_sm_0_i_1_r_1_t_4_cnt, S5S8SMStore::mpacket_sm_0_i_1_r_1_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_1_r_1_t_5_busy, S5S8SMStore::mpacket_sm_0_i_1_r_1_t_5_cnt, S5S8SMStore::mpacket_sm_0_i_1_r_1_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_1_r_1_t_6_busy, S5S8SMStore::mpacket_sm_0_i_1_r_1_t_6_cnt, S5S8SMStore::mpacket_sm_0_i_1_r_1_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_1_r_1_t_7_busy, S5S8SMStore::mpacket_sm_0_i_1_r_1_t_7_cnt, S5S8SMStore::mpacket_sm_0_i_1_r_1_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_1_r_1_t_8_busy, S5S8SMStore::mpacket_sm_0_i_1_r_1_t_8_cnt, S5S8SMStore::mpacket_sm_0_i_1_r_1_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_1_r_1_t_9_busy, S5S8SMStore::mpacket_sm_0_i_1_r_1_t_9_cnt, S5S8SMStore::mpacket_sm_0_i_1_r_1_t_9, msgObj);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_1_r_1_t_0_busy, S5S8SMStore::mpacket_sm_1_i_1_r_1_t_0_cnt, S5S8SMStore::mpacket_sm_1_i_1_r_1_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_1_r_1_t_1_busy, S5S8SMStore::mpacket_sm_1_i_1_r_1_t_1_cnt, S5S8SMStore::mpacket_sm_1_i_1_r_1_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_1_r_1_t_2_busy, S5S8SMStore::mpacket_sm_1_i_1_r_1_t_2_cnt, S5S8SMStore::mpacket_sm_1_i_1_r_1_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_1_r_1_t_3_busy, S5S8SMStore::mpacket_sm_1_i_1_r_1_t_3_cnt, S5S8SMStore::mpacket_sm_1_i_1_r_1_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_1_r_1_t_4_busy, S5S8SMStore::mpacket_sm_1_i_1_r_1_t_4_cnt, S5S8SMStore::mpacket_sm_1_i_1_r_1_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_1_r_1_t_5_busy, S5S8SMStore::mpacket_sm_1_i_1_r_1_t_5_cnt, S5S8SMStore::mpacket_sm_1_i_1_r_1_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_1_r_1_t_6_busy, S5S8SMStore::mpacket_sm_1_i_1_r_1_t_6_cnt, S5S8SMStore::mpacket_sm_1_i_1_r_1_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_1_r_1_t_7_busy, S5S8SMStore::mpacket_sm_1_i_1_r_1_t_7_cnt, S5S8SMStore::mpacket_sm_1_i_1_r_1_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_1_r_1_t_8_busy, S5S8SMStore::mpacket_sm_1_i_1_r_1_t_8_cnt, S5S8SMStore::mpacket_sm_1_i_1_r_1_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_1_r_1_t_9_busy, S5S8SMStore::mpacket_sm_1_i_1_r_1_t_9_cnt, S5S8SMStore::mpacket_sm_1_i_1_r_1_t_9, msgObj);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_1_r_1_t_0_busy, S5S8SMStore::mpacket_sm_2_i_1_r_1_t_0_cnt, S5S8SMStore::mpacket_sm_2_i_1_r_1_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_1_r_1_t_1_busy, S5S8SMStore::mpacket_sm_2_i_1_r_1_t_1_cnt, S5S8SMStore::mpacket_sm_2_i_1_r_1_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_1_r_1_t_2_busy, S5S8SMStore::mpacket_sm_2_i_1_r_1_t_2_cnt, S5S8SMStore::mpacket_sm_2_i_1_r_1_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_1_r_1_t_3_busy, S5S8SMStore::mpacket_sm_2_i_1_r_1_t_3_cnt, S5S8SMStore::mpacket_sm_2_i_1_r_1_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_1_r_1_t_4_busy, S5S8SMStore::mpacket_sm_2_i_1_r_1_t_4_cnt, S5S8SMStore::mpacket_sm_2_i_1_r_1_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_1_r_1_t_5_busy, S5S8SMStore::mpacket_sm_2_i_1_r_1_t_5_cnt, S5S8SMStore::mpacket_sm_2_i_1_r_1_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_1_r_1_t_6_busy, S5S8SMStore::mpacket_sm_2_i_1_r_1_t_6_cnt, S5S8SMStore::mpacket_sm_2_i_1_r_1_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_1_r_1_t_7_busy, S5S8SMStore::mpacket_sm_2_i_1_r_1_t_7_cnt, S5S8SMStore::mpacket_sm_2_i_1_r_1_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_1_r_1_t_8_busy, S5S8SMStore::mpacket_sm_2_i_1_r_1_t_8_cnt, S5S8SMStore::mpacket_sm_2_i_1_r_1_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_1_r_1_t_9_busy, S5S8SMStore::mpacket_sm_2_i_1_r_1_t_9_cnt, S5S8SMStore::mpacket_sm_2_i_1_r_1_t_9, msgObj);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_1_r_1_t_0_busy, S5S8SMStore::mpacket_sm_3_i_1_r_1_t_0_cnt, S5S8SMStore::mpacket_sm_3_i_1_r_1_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_1_r_1_t_1_busy, S5S8SMStore::mpacket_sm_3_i_1_r_1_t_1_cnt, S5S8SMStore::mpacket_sm_3_i_1_r_1_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_1_r_1_t_2_busy, S5S8SMStore::mpacket_sm_3_i_1_r_1_t_2_cnt, S5S8SMStore::mpacket_sm_3_i_1_r_1_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_1_r_1_t_3_busy, S5S8SMStore::mpacket_sm_3_i_1_r_1_t_3_cnt, S5S8SMStore::mpacket_sm_3_i_1_r_1_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_1_r_1_t_4_busy, S5S8SMStore::mpacket_sm_3_i_1_r_1_t_4_cnt, S5S8SMStore::mpacket_sm_3_i_1_r_1_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_1_r_1_t_5_busy, S5S8SMStore::mpacket_sm_3_i_1_r_1_t_5_cnt, S5S8SMStore::mpacket_sm_3_i_1_r_1_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_1_r_1_t_6_busy, S5S8SMStore::mpacket_sm_3_i_1_r_1_t_6_cnt, S5S8SMStore::mpacket_sm_3_i_1_r_1_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_1_r_1_t_7_busy, S5S8SMStore::mpacket_sm_3_i_1_r_1_t_7_cnt, S5S8SMStore::mpacket_sm_3_i_1_r_1_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_1_r_1_t_8_busy, S5S8SMStore::mpacket_sm_3_i_1_r_1_t_8_cnt, S5S8SMStore::mpacket_sm_3_i_1_r_1_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_1_r_1_t_9_busy, S5S8SMStore::mpacket_sm_3_i_1_r_1_t_9_cnt, S5S8SMStore::mpacket_sm_3_i_1_r_1_t_9, msgObj);
				break;
			}
			break;
	}
}

VOID S5S8MessageBroker::pushToQueue_i_1_r_2(MPacket *msgObj, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_1_r_2_t_0_busy, S5S8SMStore::mpacket_sm_0_i_1_r_2_t_0_cnt, S5S8SMStore::mpacket_sm_0_i_1_r_2_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_1_r_2_t_1_busy, S5S8SMStore::mpacket_sm_0_i_1_r_2_t_1_cnt, S5S8SMStore::mpacket_sm_0_i_1_r_2_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_1_r_2_t_2_busy, S5S8SMStore::mpacket_sm_0_i_1_r_2_t_2_cnt, S5S8SMStore::mpacket_sm_0_i_1_r_2_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_1_r_2_t_3_busy, S5S8SMStore::mpacket_sm_0_i_1_r_2_t_3_cnt, S5S8SMStore::mpacket_sm_0_i_1_r_2_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_1_r_2_t_4_busy, S5S8SMStore::mpacket_sm_0_i_1_r_2_t_4_cnt, S5S8SMStore::mpacket_sm_0_i_1_r_2_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_1_r_2_t_5_busy, S5S8SMStore::mpacket_sm_0_i_1_r_2_t_5_cnt, S5S8SMStore::mpacket_sm_0_i_1_r_2_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_1_r_2_t_6_busy, S5S8SMStore::mpacket_sm_0_i_1_r_2_t_6_cnt, S5S8SMStore::mpacket_sm_0_i_1_r_2_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_1_r_2_t_7_busy, S5S8SMStore::mpacket_sm_0_i_1_r_2_t_7_cnt, S5S8SMStore::mpacket_sm_0_i_1_r_2_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_1_r_2_t_8_busy, S5S8SMStore::mpacket_sm_0_i_1_r_2_t_8_cnt, S5S8SMStore::mpacket_sm_0_i_1_r_2_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_1_r_2_t_9_busy, S5S8SMStore::mpacket_sm_0_i_1_r_2_t_9_cnt, S5S8SMStore::mpacket_sm_0_i_1_r_2_t_9, msgObj);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_1_r_2_t_0_busy, S5S8SMStore::mpacket_sm_1_i_1_r_2_t_0_cnt, S5S8SMStore::mpacket_sm_1_i_1_r_2_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_1_r_2_t_1_busy, S5S8SMStore::mpacket_sm_1_i_1_r_2_t_1_cnt, S5S8SMStore::mpacket_sm_1_i_1_r_2_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_1_r_2_t_2_busy, S5S8SMStore::mpacket_sm_1_i_1_r_2_t_2_cnt, S5S8SMStore::mpacket_sm_1_i_1_r_2_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_1_r_2_t_3_busy, S5S8SMStore::mpacket_sm_1_i_1_r_2_t_3_cnt, S5S8SMStore::mpacket_sm_1_i_1_r_2_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_1_r_2_t_4_busy, S5S8SMStore::mpacket_sm_1_i_1_r_2_t_4_cnt, S5S8SMStore::mpacket_sm_1_i_1_r_2_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_1_r_2_t_5_busy, S5S8SMStore::mpacket_sm_1_i_1_r_2_t_5_cnt, S5S8SMStore::mpacket_sm_1_i_1_r_2_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_1_r_2_t_6_busy, S5S8SMStore::mpacket_sm_1_i_1_r_2_t_6_cnt, S5S8SMStore::mpacket_sm_1_i_1_r_2_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_1_r_2_t_7_busy, S5S8SMStore::mpacket_sm_1_i_1_r_2_t_7_cnt, S5S8SMStore::mpacket_sm_1_i_1_r_2_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_1_r_2_t_8_busy, S5S8SMStore::mpacket_sm_1_i_1_r_2_t_8_cnt, S5S8SMStore::mpacket_sm_1_i_1_r_2_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_1_r_2_t_9_busy, S5S8SMStore::mpacket_sm_1_i_1_r_2_t_9_cnt, S5S8SMStore::mpacket_sm_1_i_1_r_2_t_9, msgObj);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_1_r_2_t_0_busy, S5S8SMStore::mpacket_sm_2_i_1_r_2_t_0_cnt, S5S8SMStore::mpacket_sm_2_i_1_r_2_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_1_r_2_t_1_busy, S5S8SMStore::mpacket_sm_2_i_1_r_2_t_1_cnt, S5S8SMStore::mpacket_sm_2_i_1_r_2_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_1_r_2_t_2_busy, S5S8SMStore::mpacket_sm_2_i_1_r_2_t_2_cnt, S5S8SMStore::mpacket_sm_2_i_1_r_2_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_1_r_2_t_3_busy, S5S8SMStore::mpacket_sm_2_i_1_r_2_t_3_cnt, S5S8SMStore::mpacket_sm_2_i_1_r_2_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_1_r_2_t_4_busy, S5S8SMStore::mpacket_sm_2_i_1_r_2_t_4_cnt, S5S8SMStore::mpacket_sm_2_i_1_r_2_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_1_r_2_t_5_busy, S5S8SMStore::mpacket_sm_2_i_1_r_2_t_5_cnt, S5S8SMStore::mpacket_sm_2_i_1_r_2_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_1_r_2_t_6_busy, S5S8SMStore::mpacket_sm_2_i_1_r_2_t_6_cnt, S5S8SMStore::mpacket_sm_2_i_1_r_2_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_1_r_2_t_7_busy, S5S8SMStore::mpacket_sm_2_i_1_r_2_t_7_cnt, S5S8SMStore::mpacket_sm_2_i_1_r_2_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_1_r_2_t_8_busy, S5S8SMStore::mpacket_sm_2_i_1_r_2_t_8_cnt, S5S8SMStore::mpacket_sm_2_i_1_r_2_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_1_r_2_t_9_busy, S5S8SMStore::mpacket_sm_2_i_1_r_2_t_9_cnt, S5S8SMStore::mpacket_sm_2_i_1_r_2_t_9, msgObj);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_1_r_2_t_0_busy, S5S8SMStore::mpacket_sm_3_i_1_r_2_t_0_cnt, S5S8SMStore::mpacket_sm_3_i_1_r_2_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_1_r_2_t_1_busy, S5S8SMStore::mpacket_sm_3_i_1_r_2_t_1_cnt, S5S8SMStore::mpacket_sm_3_i_1_r_2_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_1_r_2_t_2_busy, S5S8SMStore::mpacket_sm_3_i_1_r_2_t_2_cnt, S5S8SMStore::mpacket_sm_3_i_1_r_2_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_1_r_2_t_3_busy, S5S8SMStore::mpacket_sm_3_i_1_r_2_t_3_cnt, S5S8SMStore::mpacket_sm_3_i_1_r_2_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_1_r_2_t_4_busy, S5S8SMStore::mpacket_sm_3_i_1_r_2_t_4_cnt, S5S8SMStore::mpacket_sm_3_i_1_r_2_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_1_r_2_t_5_busy, S5S8SMStore::mpacket_sm_3_i_1_r_2_t_5_cnt, S5S8SMStore::mpacket_sm_3_i_1_r_2_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_1_r_2_t_6_busy, S5S8SMStore::mpacket_sm_3_i_1_r_2_t_6_cnt, S5S8SMStore::mpacket_sm_3_i_1_r_2_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_1_r_2_t_7_busy, S5S8SMStore::mpacket_sm_3_i_1_r_2_t_7_cnt, S5S8SMStore::mpacket_sm_3_i_1_r_2_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_1_r_2_t_8_busy, S5S8SMStore::mpacket_sm_3_i_1_r_2_t_8_cnt, S5S8SMStore::mpacket_sm_3_i_1_r_2_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_1_r_2_t_9_busy, S5S8SMStore::mpacket_sm_3_i_1_r_2_t_9_cnt, S5S8SMStore::mpacket_sm_3_i_1_r_2_t_9, msgObj);
				break;
			}
			break;
	}
}

VOID S5S8MessageBroker::pushToQueue_i_1_r_3(MPacket *msgObj, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_1_r_3_t_0_busy, S5S8SMStore::mpacket_sm_0_i_1_r_3_t_0_cnt, S5S8SMStore::mpacket_sm_0_i_1_r_3_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_1_r_3_t_1_busy, S5S8SMStore::mpacket_sm_0_i_1_r_3_t_1_cnt, S5S8SMStore::mpacket_sm_0_i_1_r_3_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_1_r_3_t_2_busy, S5S8SMStore::mpacket_sm_0_i_1_r_3_t_2_cnt, S5S8SMStore::mpacket_sm_0_i_1_r_3_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_1_r_3_t_3_busy, S5S8SMStore::mpacket_sm_0_i_1_r_3_t_3_cnt, S5S8SMStore::mpacket_sm_0_i_1_r_3_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_1_r_3_t_4_busy, S5S8SMStore::mpacket_sm_0_i_1_r_3_t_4_cnt, S5S8SMStore::mpacket_sm_0_i_1_r_3_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_1_r_3_t_5_busy, S5S8SMStore::mpacket_sm_0_i_1_r_3_t_5_cnt, S5S8SMStore::mpacket_sm_0_i_1_r_3_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_1_r_3_t_6_busy, S5S8SMStore::mpacket_sm_0_i_1_r_3_t_6_cnt, S5S8SMStore::mpacket_sm_0_i_1_r_3_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_1_r_3_t_7_busy, S5S8SMStore::mpacket_sm_0_i_1_r_3_t_7_cnt, S5S8SMStore::mpacket_sm_0_i_1_r_3_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_1_r_3_t_8_busy, S5S8SMStore::mpacket_sm_0_i_1_r_3_t_8_cnt, S5S8SMStore::mpacket_sm_0_i_1_r_3_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_1_r_3_t_9_busy, S5S8SMStore::mpacket_sm_0_i_1_r_3_t_9_cnt, S5S8SMStore::mpacket_sm_0_i_1_r_3_t_9, msgObj);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_1_r_3_t_0_busy, S5S8SMStore::mpacket_sm_1_i_1_r_3_t_0_cnt, S5S8SMStore::mpacket_sm_1_i_1_r_3_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_1_r_3_t_1_busy, S5S8SMStore::mpacket_sm_1_i_1_r_3_t_1_cnt, S5S8SMStore::mpacket_sm_1_i_1_r_3_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_1_r_3_t_2_busy, S5S8SMStore::mpacket_sm_1_i_1_r_3_t_2_cnt, S5S8SMStore::mpacket_sm_1_i_1_r_3_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_1_r_3_t_3_busy, S5S8SMStore::mpacket_sm_1_i_1_r_3_t_3_cnt, S5S8SMStore::mpacket_sm_1_i_1_r_3_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_1_r_3_t_4_busy, S5S8SMStore::mpacket_sm_1_i_1_r_3_t_4_cnt, S5S8SMStore::mpacket_sm_1_i_1_r_3_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_1_r_3_t_5_busy, S5S8SMStore::mpacket_sm_1_i_1_r_3_t_5_cnt, S5S8SMStore::mpacket_sm_1_i_1_r_3_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_1_r_3_t_6_busy, S5S8SMStore::mpacket_sm_1_i_1_r_3_t_6_cnt, S5S8SMStore::mpacket_sm_1_i_1_r_3_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_1_r_3_t_7_busy, S5S8SMStore::mpacket_sm_1_i_1_r_3_t_7_cnt, S5S8SMStore::mpacket_sm_1_i_1_r_3_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_1_r_3_t_8_busy, S5S8SMStore::mpacket_sm_1_i_1_r_3_t_8_cnt, S5S8SMStore::mpacket_sm_1_i_1_r_3_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_1_r_3_t_9_busy, S5S8SMStore::mpacket_sm_1_i_1_r_3_t_9_cnt, S5S8SMStore::mpacket_sm_1_i_1_r_3_t_9, msgObj);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_1_r_3_t_0_busy, S5S8SMStore::mpacket_sm_2_i_1_r_3_t_0_cnt, S5S8SMStore::mpacket_sm_2_i_1_r_3_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_1_r_3_t_1_busy, S5S8SMStore::mpacket_sm_2_i_1_r_3_t_1_cnt, S5S8SMStore::mpacket_sm_2_i_1_r_3_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_1_r_3_t_2_busy, S5S8SMStore::mpacket_sm_2_i_1_r_3_t_2_cnt, S5S8SMStore::mpacket_sm_2_i_1_r_3_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_1_r_3_t_3_busy, S5S8SMStore::mpacket_sm_2_i_1_r_3_t_3_cnt, S5S8SMStore::mpacket_sm_2_i_1_r_3_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_1_r_3_t_4_busy, S5S8SMStore::mpacket_sm_2_i_1_r_3_t_4_cnt, S5S8SMStore::mpacket_sm_2_i_1_r_3_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_1_r_3_t_5_busy, S5S8SMStore::mpacket_sm_2_i_1_r_3_t_5_cnt, S5S8SMStore::mpacket_sm_2_i_1_r_3_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_1_r_3_t_6_busy, S5S8SMStore::mpacket_sm_2_i_1_r_3_t_6_cnt, S5S8SMStore::mpacket_sm_2_i_1_r_3_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_1_r_3_t_7_busy, S5S8SMStore::mpacket_sm_2_i_1_r_3_t_7_cnt, S5S8SMStore::mpacket_sm_2_i_1_r_3_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_1_r_3_t_8_busy, S5S8SMStore::mpacket_sm_2_i_1_r_3_t_8_cnt, S5S8SMStore::mpacket_sm_2_i_1_r_3_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_1_r_3_t_9_busy, S5S8SMStore::mpacket_sm_2_i_1_r_3_t_9_cnt, S5S8SMStore::mpacket_sm_2_i_1_r_3_t_9, msgObj);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_1_r_3_t_0_busy, S5S8SMStore::mpacket_sm_3_i_1_r_3_t_0_cnt, S5S8SMStore::mpacket_sm_3_i_1_r_3_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_1_r_3_t_1_busy, S5S8SMStore::mpacket_sm_3_i_1_r_3_t_1_cnt, S5S8SMStore::mpacket_sm_3_i_1_r_3_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_1_r_3_t_2_busy, S5S8SMStore::mpacket_sm_3_i_1_r_3_t_2_cnt, S5S8SMStore::mpacket_sm_3_i_1_r_3_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_1_r_3_t_3_busy, S5S8SMStore::mpacket_sm_3_i_1_r_3_t_3_cnt, S5S8SMStore::mpacket_sm_3_i_1_r_3_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_1_r_3_t_4_busy, S5S8SMStore::mpacket_sm_3_i_1_r_3_t_4_cnt, S5S8SMStore::mpacket_sm_3_i_1_r_3_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_1_r_3_t_5_busy, S5S8SMStore::mpacket_sm_3_i_1_r_3_t_5_cnt, S5S8SMStore::mpacket_sm_3_i_1_r_3_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_1_r_3_t_6_busy, S5S8SMStore::mpacket_sm_3_i_1_r_3_t_6_cnt, S5S8SMStore::mpacket_sm_3_i_1_r_3_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_1_r_3_t_7_busy, S5S8SMStore::mpacket_sm_3_i_1_r_3_t_7_cnt, S5S8SMStore::mpacket_sm_3_i_1_r_3_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_1_r_3_t_8_busy, S5S8SMStore::mpacket_sm_3_i_1_r_3_t_8_cnt, S5S8SMStore::mpacket_sm_3_i_1_r_3_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_1_r_3_t_9_busy, S5S8SMStore::mpacket_sm_3_i_1_r_3_t_9_cnt, S5S8SMStore::mpacket_sm_3_i_1_r_3_t_9, msgObj);
				break;
			}
			break;
	}
}

VOID S5S8MessageBroker::pushToQueue_i_1_r_4(MPacket *msgObj, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_1_r_4_t_0_busy, S5S8SMStore::mpacket_sm_0_i_1_r_4_t_0_cnt, S5S8SMStore::mpacket_sm_0_i_1_r_4_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_1_r_4_t_1_busy, S5S8SMStore::mpacket_sm_0_i_1_r_4_t_1_cnt, S5S8SMStore::mpacket_sm_0_i_1_r_4_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_1_r_4_t_2_busy, S5S8SMStore::mpacket_sm_0_i_1_r_4_t_2_cnt, S5S8SMStore::mpacket_sm_0_i_1_r_4_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_1_r_4_t_3_busy, S5S8SMStore::mpacket_sm_0_i_1_r_4_t_3_cnt, S5S8SMStore::mpacket_sm_0_i_1_r_4_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_1_r_4_t_4_busy, S5S8SMStore::mpacket_sm_0_i_1_r_4_t_4_cnt, S5S8SMStore::mpacket_sm_0_i_1_r_4_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_1_r_4_t_5_busy, S5S8SMStore::mpacket_sm_0_i_1_r_4_t_5_cnt, S5S8SMStore::mpacket_sm_0_i_1_r_4_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_1_r_4_t_6_busy, S5S8SMStore::mpacket_sm_0_i_1_r_4_t_6_cnt, S5S8SMStore::mpacket_sm_0_i_1_r_4_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_1_r_4_t_7_busy, S5S8SMStore::mpacket_sm_0_i_1_r_4_t_7_cnt, S5S8SMStore::mpacket_sm_0_i_1_r_4_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_1_r_4_t_8_busy, S5S8SMStore::mpacket_sm_0_i_1_r_4_t_8_cnt, S5S8SMStore::mpacket_sm_0_i_1_r_4_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_1_r_4_t_9_busy, S5S8SMStore::mpacket_sm_0_i_1_r_4_t_9_cnt, S5S8SMStore::mpacket_sm_0_i_1_r_4_t_9, msgObj);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_1_r_4_t_0_busy, S5S8SMStore::mpacket_sm_1_i_1_r_4_t_0_cnt, S5S8SMStore::mpacket_sm_1_i_1_r_4_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_1_r_4_t_1_busy, S5S8SMStore::mpacket_sm_1_i_1_r_4_t_1_cnt, S5S8SMStore::mpacket_sm_1_i_1_r_4_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_1_r_4_t_2_busy, S5S8SMStore::mpacket_sm_1_i_1_r_4_t_2_cnt, S5S8SMStore::mpacket_sm_1_i_1_r_4_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_1_r_4_t_3_busy, S5S8SMStore::mpacket_sm_1_i_1_r_4_t_3_cnt, S5S8SMStore::mpacket_sm_1_i_1_r_4_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_1_r_4_t_4_busy, S5S8SMStore::mpacket_sm_1_i_1_r_4_t_4_cnt, S5S8SMStore::mpacket_sm_1_i_1_r_4_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_1_r_4_t_5_busy, S5S8SMStore::mpacket_sm_1_i_1_r_4_t_5_cnt, S5S8SMStore::mpacket_sm_1_i_1_r_4_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_1_r_4_t_6_busy, S5S8SMStore::mpacket_sm_1_i_1_r_4_t_6_cnt, S5S8SMStore::mpacket_sm_1_i_1_r_4_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_1_r_4_t_7_busy, S5S8SMStore::mpacket_sm_1_i_1_r_4_t_7_cnt, S5S8SMStore::mpacket_sm_1_i_1_r_4_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_1_r_4_t_8_busy, S5S8SMStore::mpacket_sm_1_i_1_r_4_t_8_cnt, S5S8SMStore::mpacket_sm_1_i_1_r_4_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_1_r_4_t_9_busy, S5S8SMStore::mpacket_sm_1_i_1_r_4_t_9_cnt, S5S8SMStore::mpacket_sm_1_i_1_r_4_t_9, msgObj);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_1_r_4_t_0_busy, S5S8SMStore::mpacket_sm_2_i_1_r_4_t_0_cnt, S5S8SMStore::mpacket_sm_2_i_1_r_4_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_1_r_4_t_1_busy, S5S8SMStore::mpacket_sm_2_i_1_r_4_t_1_cnt, S5S8SMStore::mpacket_sm_2_i_1_r_4_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_1_r_4_t_2_busy, S5S8SMStore::mpacket_sm_2_i_1_r_4_t_2_cnt, S5S8SMStore::mpacket_sm_2_i_1_r_4_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_1_r_4_t_3_busy, S5S8SMStore::mpacket_sm_2_i_1_r_4_t_3_cnt, S5S8SMStore::mpacket_sm_2_i_1_r_4_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_1_r_4_t_4_busy, S5S8SMStore::mpacket_sm_2_i_1_r_4_t_4_cnt, S5S8SMStore::mpacket_sm_2_i_1_r_4_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_1_r_4_t_5_busy, S5S8SMStore::mpacket_sm_2_i_1_r_4_t_5_cnt, S5S8SMStore::mpacket_sm_2_i_1_r_4_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_1_r_4_t_6_busy, S5S8SMStore::mpacket_sm_2_i_1_r_4_t_6_cnt, S5S8SMStore::mpacket_sm_2_i_1_r_4_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_1_r_4_t_7_busy, S5S8SMStore::mpacket_sm_2_i_1_r_4_t_7_cnt, S5S8SMStore::mpacket_sm_2_i_1_r_4_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_1_r_4_t_8_busy, S5S8SMStore::mpacket_sm_2_i_1_r_4_t_8_cnt, S5S8SMStore::mpacket_sm_2_i_1_r_4_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_1_r_4_t_9_busy, S5S8SMStore::mpacket_sm_2_i_1_r_4_t_9_cnt, S5S8SMStore::mpacket_sm_2_i_1_r_4_t_9, msgObj);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_1_r_4_t_0_busy, S5S8SMStore::mpacket_sm_3_i_1_r_4_t_0_cnt, S5S8SMStore::mpacket_sm_3_i_1_r_4_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_1_r_4_t_1_busy, S5S8SMStore::mpacket_sm_3_i_1_r_4_t_1_cnt, S5S8SMStore::mpacket_sm_3_i_1_r_4_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_1_r_4_t_2_busy, S5S8SMStore::mpacket_sm_3_i_1_r_4_t_2_cnt, S5S8SMStore::mpacket_sm_3_i_1_r_4_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_1_r_4_t_3_busy, S5S8SMStore::mpacket_sm_3_i_1_r_4_t_3_cnt, S5S8SMStore::mpacket_sm_3_i_1_r_4_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_1_r_4_t_4_busy, S5S8SMStore::mpacket_sm_3_i_1_r_4_t_4_cnt, S5S8SMStore::mpacket_sm_3_i_1_r_4_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_1_r_4_t_5_busy, S5S8SMStore::mpacket_sm_3_i_1_r_4_t_5_cnt, S5S8SMStore::mpacket_sm_3_i_1_r_4_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_1_r_4_t_6_busy, S5S8SMStore::mpacket_sm_3_i_1_r_4_t_6_cnt, S5S8SMStore::mpacket_sm_3_i_1_r_4_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_1_r_4_t_7_busy, S5S8SMStore::mpacket_sm_3_i_1_r_4_t_7_cnt, S5S8SMStore::mpacket_sm_3_i_1_r_4_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_1_r_4_t_8_busy, S5S8SMStore::mpacket_sm_3_i_1_r_4_t_8_cnt, S5S8SMStore::mpacket_sm_3_i_1_r_4_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_1_r_4_t_9_busy, S5S8SMStore::mpacket_sm_3_i_1_r_4_t_9_cnt, S5S8SMStore::mpacket_sm_3_i_1_r_4_t_9, msgObj);
				break;
			}
			break;
	}
}

VOID S5S8MessageBroker::pushToQueue_i_1_r_5(MPacket *msgObj, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_1_r_5_t_0_busy, S5S8SMStore::mpacket_sm_0_i_1_r_5_t_0_cnt, S5S8SMStore::mpacket_sm_0_i_1_r_5_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_1_r_5_t_1_busy, S5S8SMStore::mpacket_sm_0_i_1_r_5_t_1_cnt, S5S8SMStore::mpacket_sm_0_i_1_r_5_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_1_r_5_t_2_busy, S5S8SMStore::mpacket_sm_0_i_1_r_5_t_2_cnt, S5S8SMStore::mpacket_sm_0_i_1_r_5_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_1_r_5_t_3_busy, S5S8SMStore::mpacket_sm_0_i_1_r_5_t_3_cnt, S5S8SMStore::mpacket_sm_0_i_1_r_5_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_1_r_5_t_4_busy, S5S8SMStore::mpacket_sm_0_i_1_r_5_t_4_cnt, S5S8SMStore::mpacket_sm_0_i_1_r_5_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_1_r_5_t_5_busy, S5S8SMStore::mpacket_sm_0_i_1_r_5_t_5_cnt, S5S8SMStore::mpacket_sm_0_i_1_r_5_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_1_r_5_t_6_busy, S5S8SMStore::mpacket_sm_0_i_1_r_5_t_6_cnt, S5S8SMStore::mpacket_sm_0_i_1_r_5_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_1_r_5_t_7_busy, S5S8SMStore::mpacket_sm_0_i_1_r_5_t_7_cnt, S5S8SMStore::mpacket_sm_0_i_1_r_5_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_1_r_5_t_8_busy, S5S8SMStore::mpacket_sm_0_i_1_r_5_t_8_cnt, S5S8SMStore::mpacket_sm_0_i_1_r_5_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_1_r_5_t_9_busy, S5S8SMStore::mpacket_sm_0_i_1_r_5_t_9_cnt, S5S8SMStore::mpacket_sm_0_i_1_r_5_t_9, msgObj);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_1_r_5_t_0_busy, S5S8SMStore::mpacket_sm_1_i_1_r_5_t_0_cnt, S5S8SMStore::mpacket_sm_1_i_1_r_5_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_1_r_5_t_1_busy, S5S8SMStore::mpacket_sm_1_i_1_r_5_t_1_cnt, S5S8SMStore::mpacket_sm_1_i_1_r_5_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_1_r_5_t_2_busy, S5S8SMStore::mpacket_sm_1_i_1_r_5_t_2_cnt, S5S8SMStore::mpacket_sm_1_i_1_r_5_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_1_r_5_t_3_busy, S5S8SMStore::mpacket_sm_1_i_1_r_5_t_3_cnt, S5S8SMStore::mpacket_sm_1_i_1_r_5_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_1_r_5_t_4_busy, S5S8SMStore::mpacket_sm_1_i_1_r_5_t_4_cnt, S5S8SMStore::mpacket_sm_1_i_1_r_5_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_1_r_5_t_5_busy, S5S8SMStore::mpacket_sm_1_i_1_r_5_t_5_cnt, S5S8SMStore::mpacket_sm_1_i_1_r_5_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_1_r_5_t_6_busy, S5S8SMStore::mpacket_sm_1_i_1_r_5_t_6_cnt, S5S8SMStore::mpacket_sm_1_i_1_r_5_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_1_r_5_t_7_busy, S5S8SMStore::mpacket_sm_1_i_1_r_5_t_7_cnt, S5S8SMStore::mpacket_sm_1_i_1_r_5_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_1_r_5_t_8_busy, S5S8SMStore::mpacket_sm_1_i_1_r_5_t_8_cnt, S5S8SMStore::mpacket_sm_1_i_1_r_5_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_1_r_5_t_9_busy, S5S8SMStore::mpacket_sm_1_i_1_r_5_t_9_cnt, S5S8SMStore::mpacket_sm_1_i_1_r_5_t_9, msgObj);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_1_r_5_t_0_busy, S5S8SMStore::mpacket_sm_2_i_1_r_5_t_0_cnt, S5S8SMStore::mpacket_sm_2_i_1_r_5_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_1_r_5_t_1_busy, S5S8SMStore::mpacket_sm_2_i_1_r_5_t_1_cnt, S5S8SMStore::mpacket_sm_2_i_1_r_5_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_1_r_5_t_2_busy, S5S8SMStore::mpacket_sm_2_i_1_r_5_t_2_cnt, S5S8SMStore::mpacket_sm_2_i_1_r_5_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_1_r_5_t_3_busy, S5S8SMStore::mpacket_sm_2_i_1_r_5_t_3_cnt, S5S8SMStore::mpacket_sm_2_i_1_r_5_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_1_r_5_t_4_busy, S5S8SMStore::mpacket_sm_2_i_1_r_5_t_4_cnt, S5S8SMStore::mpacket_sm_2_i_1_r_5_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_1_r_5_t_5_busy, S5S8SMStore::mpacket_sm_2_i_1_r_5_t_5_cnt, S5S8SMStore::mpacket_sm_2_i_1_r_5_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_1_r_5_t_6_busy, S5S8SMStore::mpacket_sm_2_i_1_r_5_t_6_cnt, S5S8SMStore::mpacket_sm_2_i_1_r_5_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_1_r_5_t_7_busy, S5S8SMStore::mpacket_sm_2_i_1_r_5_t_7_cnt, S5S8SMStore::mpacket_sm_2_i_1_r_5_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_1_r_5_t_8_busy, S5S8SMStore::mpacket_sm_2_i_1_r_5_t_8_cnt, S5S8SMStore::mpacket_sm_2_i_1_r_5_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_1_r_5_t_9_busy, S5S8SMStore::mpacket_sm_2_i_1_r_5_t_9_cnt, S5S8SMStore::mpacket_sm_2_i_1_r_5_t_9, msgObj);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_1_r_5_t_0_busy, S5S8SMStore::mpacket_sm_3_i_1_r_5_t_0_cnt, S5S8SMStore::mpacket_sm_3_i_1_r_5_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_1_r_5_t_1_busy, S5S8SMStore::mpacket_sm_3_i_1_r_5_t_1_cnt, S5S8SMStore::mpacket_sm_3_i_1_r_5_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_1_r_5_t_2_busy, S5S8SMStore::mpacket_sm_3_i_1_r_5_t_2_cnt, S5S8SMStore::mpacket_sm_3_i_1_r_5_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_1_r_5_t_3_busy, S5S8SMStore::mpacket_sm_3_i_1_r_5_t_3_cnt, S5S8SMStore::mpacket_sm_3_i_1_r_5_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_1_r_5_t_4_busy, S5S8SMStore::mpacket_sm_3_i_1_r_5_t_4_cnt, S5S8SMStore::mpacket_sm_3_i_1_r_5_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_1_r_5_t_5_busy, S5S8SMStore::mpacket_sm_3_i_1_r_5_t_5_cnt, S5S8SMStore::mpacket_sm_3_i_1_r_5_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_1_r_5_t_6_busy, S5S8SMStore::mpacket_sm_3_i_1_r_5_t_6_cnt, S5S8SMStore::mpacket_sm_3_i_1_r_5_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_1_r_5_t_7_busy, S5S8SMStore::mpacket_sm_3_i_1_r_5_t_7_cnt, S5S8SMStore::mpacket_sm_3_i_1_r_5_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_1_r_5_t_8_busy, S5S8SMStore::mpacket_sm_3_i_1_r_5_t_8_cnt, S5S8SMStore::mpacket_sm_3_i_1_r_5_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_1_r_5_t_9_busy, S5S8SMStore::mpacket_sm_3_i_1_r_5_t_9_cnt, S5S8SMStore::mpacket_sm_3_i_1_r_5_t_9, msgObj);
				break;
			}
			break;
	}
}

VOID S5S8MessageBroker::pushToQueue_i_1_r_6(MPacket *msgObj, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_1_r_6_t_0_busy, S5S8SMStore::mpacket_sm_0_i_1_r_6_t_0_cnt, S5S8SMStore::mpacket_sm_0_i_1_r_6_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_1_r_6_t_1_busy, S5S8SMStore::mpacket_sm_0_i_1_r_6_t_1_cnt, S5S8SMStore::mpacket_sm_0_i_1_r_6_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_1_r_6_t_2_busy, S5S8SMStore::mpacket_sm_0_i_1_r_6_t_2_cnt, S5S8SMStore::mpacket_sm_0_i_1_r_6_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_1_r_6_t_3_busy, S5S8SMStore::mpacket_sm_0_i_1_r_6_t_3_cnt, S5S8SMStore::mpacket_sm_0_i_1_r_6_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_1_r_6_t_4_busy, S5S8SMStore::mpacket_sm_0_i_1_r_6_t_4_cnt, S5S8SMStore::mpacket_sm_0_i_1_r_6_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_1_r_6_t_5_busy, S5S8SMStore::mpacket_sm_0_i_1_r_6_t_5_cnt, S5S8SMStore::mpacket_sm_0_i_1_r_6_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_1_r_6_t_6_busy, S5S8SMStore::mpacket_sm_0_i_1_r_6_t_6_cnt, S5S8SMStore::mpacket_sm_0_i_1_r_6_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_1_r_6_t_7_busy, S5S8SMStore::mpacket_sm_0_i_1_r_6_t_7_cnt, S5S8SMStore::mpacket_sm_0_i_1_r_6_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_1_r_6_t_8_busy, S5S8SMStore::mpacket_sm_0_i_1_r_6_t_8_cnt, S5S8SMStore::mpacket_sm_0_i_1_r_6_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_1_r_6_t_9_busy, S5S8SMStore::mpacket_sm_0_i_1_r_6_t_9_cnt, S5S8SMStore::mpacket_sm_0_i_1_r_6_t_9, msgObj);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_1_r_6_t_0_busy, S5S8SMStore::mpacket_sm_1_i_1_r_6_t_0_cnt, S5S8SMStore::mpacket_sm_1_i_1_r_6_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_1_r_6_t_1_busy, S5S8SMStore::mpacket_sm_1_i_1_r_6_t_1_cnt, S5S8SMStore::mpacket_sm_1_i_1_r_6_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_1_r_6_t_2_busy, S5S8SMStore::mpacket_sm_1_i_1_r_6_t_2_cnt, S5S8SMStore::mpacket_sm_1_i_1_r_6_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_1_r_6_t_3_busy, S5S8SMStore::mpacket_sm_1_i_1_r_6_t_3_cnt, S5S8SMStore::mpacket_sm_1_i_1_r_6_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_1_r_6_t_4_busy, S5S8SMStore::mpacket_sm_1_i_1_r_6_t_4_cnt, S5S8SMStore::mpacket_sm_1_i_1_r_6_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_1_r_6_t_5_busy, S5S8SMStore::mpacket_sm_1_i_1_r_6_t_5_cnt, S5S8SMStore::mpacket_sm_1_i_1_r_6_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_1_r_6_t_6_busy, S5S8SMStore::mpacket_sm_1_i_1_r_6_t_6_cnt, S5S8SMStore::mpacket_sm_1_i_1_r_6_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_1_r_6_t_7_busy, S5S8SMStore::mpacket_sm_1_i_1_r_6_t_7_cnt, S5S8SMStore::mpacket_sm_1_i_1_r_6_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_1_r_6_t_8_busy, S5S8SMStore::mpacket_sm_1_i_1_r_6_t_8_cnt, S5S8SMStore::mpacket_sm_1_i_1_r_6_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_1_r_6_t_9_busy, S5S8SMStore::mpacket_sm_1_i_1_r_6_t_9_cnt, S5S8SMStore::mpacket_sm_1_i_1_r_6_t_9, msgObj);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_1_r_6_t_0_busy, S5S8SMStore::mpacket_sm_2_i_1_r_6_t_0_cnt, S5S8SMStore::mpacket_sm_2_i_1_r_6_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_1_r_6_t_1_busy, S5S8SMStore::mpacket_sm_2_i_1_r_6_t_1_cnt, S5S8SMStore::mpacket_sm_2_i_1_r_6_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_1_r_6_t_2_busy, S5S8SMStore::mpacket_sm_2_i_1_r_6_t_2_cnt, S5S8SMStore::mpacket_sm_2_i_1_r_6_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_1_r_6_t_3_busy, S5S8SMStore::mpacket_sm_2_i_1_r_6_t_3_cnt, S5S8SMStore::mpacket_sm_2_i_1_r_6_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_1_r_6_t_4_busy, S5S8SMStore::mpacket_sm_2_i_1_r_6_t_4_cnt, S5S8SMStore::mpacket_sm_2_i_1_r_6_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_1_r_6_t_5_busy, S5S8SMStore::mpacket_sm_2_i_1_r_6_t_5_cnt, S5S8SMStore::mpacket_sm_2_i_1_r_6_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_1_r_6_t_6_busy, S5S8SMStore::mpacket_sm_2_i_1_r_6_t_6_cnt, S5S8SMStore::mpacket_sm_2_i_1_r_6_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_1_r_6_t_7_busy, S5S8SMStore::mpacket_sm_2_i_1_r_6_t_7_cnt, S5S8SMStore::mpacket_sm_2_i_1_r_6_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_1_r_6_t_8_busy, S5S8SMStore::mpacket_sm_2_i_1_r_6_t_8_cnt, S5S8SMStore::mpacket_sm_2_i_1_r_6_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_1_r_6_t_9_busy, S5S8SMStore::mpacket_sm_2_i_1_r_6_t_9_cnt, S5S8SMStore::mpacket_sm_2_i_1_r_6_t_9, msgObj);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_1_r_6_t_0_busy, S5S8SMStore::mpacket_sm_3_i_1_r_6_t_0_cnt, S5S8SMStore::mpacket_sm_3_i_1_r_6_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_1_r_6_t_1_busy, S5S8SMStore::mpacket_sm_3_i_1_r_6_t_1_cnt, S5S8SMStore::mpacket_sm_3_i_1_r_6_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_1_r_6_t_2_busy, S5S8SMStore::mpacket_sm_3_i_1_r_6_t_2_cnt, S5S8SMStore::mpacket_sm_3_i_1_r_6_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_1_r_6_t_3_busy, S5S8SMStore::mpacket_sm_3_i_1_r_6_t_3_cnt, S5S8SMStore::mpacket_sm_3_i_1_r_6_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_1_r_6_t_4_busy, S5S8SMStore::mpacket_sm_3_i_1_r_6_t_4_cnt, S5S8SMStore::mpacket_sm_3_i_1_r_6_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_1_r_6_t_5_busy, S5S8SMStore::mpacket_sm_3_i_1_r_6_t_5_cnt, S5S8SMStore::mpacket_sm_3_i_1_r_6_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_1_r_6_t_6_busy, S5S8SMStore::mpacket_sm_3_i_1_r_6_t_6_cnt, S5S8SMStore::mpacket_sm_3_i_1_r_6_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_1_r_6_t_7_busy, S5S8SMStore::mpacket_sm_3_i_1_r_6_t_7_cnt, S5S8SMStore::mpacket_sm_3_i_1_r_6_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_1_r_6_t_8_busy, S5S8SMStore::mpacket_sm_3_i_1_r_6_t_8_cnt, S5S8SMStore::mpacket_sm_3_i_1_r_6_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_1_r_6_t_9_busy, S5S8SMStore::mpacket_sm_3_i_1_r_6_t_9_cnt, S5S8SMStore::mpacket_sm_3_i_1_r_6_t_9, msgObj);
				break;
			}
			break;
	}
}

VOID S5S8MessageBroker::pushToQueue_i_1_r_7(MPacket *msgObj, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_1_r_7_t_0_busy, S5S8SMStore::mpacket_sm_0_i_1_r_7_t_0_cnt, S5S8SMStore::mpacket_sm_0_i_1_r_7_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_1_r_7_t_1_busy, S5S8SMStore::mpacket_sm_0_i_1_r_7_t_1_cnt, S5S8SMStore::mpacket_sm_0_i_1_r_7_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_1_r_7_t_2_busy, S5S8SMStore::mpacket_sm_0_i_1_r_7_t_2_cnt, S5S8SMStore::mpacket_sm_0_i_1_r_7_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_1_r_7_t_3_busy, S5S8SMStore::mpacket_sm_0_i_1_r_7_t_3_cnt, S5S8SMStore::mpacket_sm_0_i_1_r_7_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_1_r_7_t_4_busy, S5S8SMStore::mpacket_sm_0_i_1_r_7_t_4_cnt, S5S8SMStore::mpacket_sm_0_i_1_r_7_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_1_r_7_t_5_busy, S5S8SMStore::mpacket_sm_0_i_1_r_7_t_5_cnt, S5S8SMStore::mpacket_sm_0_i_1_r_7_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_1_r_7_t_6_busy, S5S8SMStore::mpacket_sm_0_i_1_r_7_t_6_cnt, S5S8SMStore::mpacket_sm_0_i_1_r_7_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_1_r_7_t_7_busy, S5S8SMStore::mpacket_sm_0_i_1_r_7_t_7_cnt, S5S8SMStore::mpacket_sm_0_i_1_r_7_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_1_r_7_t_8_busy, S5S8SMStore::mpacket_sm_0_i_1_r_7_t_8_cnt, S5S8SMStore::mpacket_sm_0_i_1_r_7_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_1_r_7_t_9_busy, S5S8SMStore::mpacket_sm_0_i_1_r_7_t_9_cnt, S5S8SMStore::mpacket_sm_0_i_1_r_7_t_9, msgObj);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_1_r_7_t_0_busy, S5S8SMStore::mpacket_sm_1_i_1_r_7_t_0_cnt, S5S8SMStore::mpacket_sm_1_i_1_r_7_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_1_r_7_t_1_busy, S5S8SMStore::mpacket_sm_1_i_1_r_7_t_1_cnt, S5S8SMStore::mpacket_sm_1_i_1_r_7_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_1_r_7_t_2_busy, S5S8SMStore::mpacket_sm_1_i_1_r_7_t_2_cnt, S5S8SMStore::mpacket_sm_1_i_1_r_7_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_1_r_7_t_3_busy, S5S8SMStore::mpacket_sm_1_i_1_r_7_t_3_cnt, S5S8SMStore::mpacket_sm_1_i_1_r_7_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_1_r_7_t_4_busy, S5S8SMStore::mpacket_sm_1_i_1_r_7_t_4_cnt, S5S8SMStore::mpacket_sm_1_i_1_r_7_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_1_r_7_t_5_busy, S5S8SMStore::mpacket_sm_1_i_1_r_7_t_5_cnt, S5S8SMStore::mpacket_sm_1_i_1_r_7_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_1_r_7_t_6_busy, S5S8SMStore::mpacket_sm_1_i_1_r_7_t_6_cnt, S5S8SMStore::mpacket_sm_1_i_1_r_7_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_1_r_7_t_7_busy, S5S8SMStore::mpacket_sm_1_i_1_r_7_t_7_cnt, S5S8SMStore::mpacket_sm_1_i_1_r_7_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_1_r_7_t_8_busy, S5S8SMStore::mpacket_sm_1_i_1_r_7_t_8_cnt, S5S8SMStore::mpacket_sm_1_i_1_r_7_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_1_r_7_t_9_busy, S5S8SMStore::mpacket_sm_1_i_1_r_7_t_9_cnt, S5S8SMStore::mpacket_sm_1_i_1_r_7_t_9, msgObj);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_1_r_7_t_0_busy, S5S8SMStore::mpacket_sm_2_i_1_r_7_t_0_cnt, S5S8SMStore::mpacket_sm_2_i_1_r_7_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_1_r_7_t_1_busy, S5S8SMStore::mpacket_sm_2_i_1_r_7_t_1_cnt, S5S8SMStore::mpacket_sm_2_i_1_r_7_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_1_r_7_t_2_busy, S5S8SMStore::mpacket_sm_2_i_1_r_7_t_2_cnt, S5S8SMStore::mpacket_sm_2_i_1_r_7_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_1_r_7_t_3_busy, S5S8SMStore::mpacket_sm_2_i_1_r_7_t_3_cnt, S5S8SMStore::mpacket_sm_2_i_1_r_7_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_1_r_7_t_4_busy, S5S8SMStore::mpacket_sm_2_i_1_r_7_t_4_cnt, S5S8SMStore::mpacket_sm_2_i_1_r_7_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_1_r_7_t_5_busy, S5S8SMStore::mpacket_sm_2_i_1_r_7_t_5_cnt, S5S8SMStore::mpacket_sm_2_i_1_r_7_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_1_r_7_t_6_busy, S5S8SMStore::mpacket_sm_2_i_1_r_7_t_6_cnt, S5S8SMStore::mpacket_sm_2_i_1_r_7_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_1_r_7_t_7_busy, S5S8SMStore::mpacket_sm_2_i_1_r_7_t_7_cnt, S5S8SMStore::mpacket_sm_2_i_1_r_7_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_1_r_7_t_8_busy, S5S8SMStore::mpacket_sm_2_i_1_r_7_t_8_cnt, S5S8SMStore::mpacket_sm_2_i_1_r_7_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_1_r_7_t_9_busy, S5S8SMStore::mpacket_sm_2_i_1_r_7_t_9_cnt, S5S8SMStore::mpacket_sm_2_i_1_r_7_t_9, msgObj);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_1_r_7_t_0_busy, S5S8SMStore::mpacket_sm_3_i_1_r_7_t_0_cnt, S5S8SMStore::mpacket_sm_3_i_1_r_7_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_1_r_7_t_1_busy, S5S8SMStore::mpacket_sm_3_i_1_r_7_t_1_cnt, S5S8SMStore::mpacket_sm_3_i_1_r_7_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_1_r_7_t_2_busy, S5S8SMStore::mpacket_sm_3_i_1_r_7_t_2_cnt, S5S8SMStore::mpacket_sm_3_i_1_r_7_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_1_r_7_t_3_busy, S5S8SMStore::mpacket_sm_3_i_1_r_7_t_3_cnt, S5S8SMStore::mpacket_sm_3_i_1_r_7_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_1_r_7_t_4_busy, S5S8SMStore::mpacket_sm_3_i_1_r_7_t_4_cnt, S5S8SMStore::mpacket_sm_3_i_1_r_7_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_1_r_7_t_5_busy, S5S8SMStore::mpacket_sm_3_i_1_r_7_t_5_cnt, S5S8SMStore::mpacket_sm_3_i_1_r_7_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_1_r_7_t_6_busy, S5S8SMStore::mpacket_sm_3_i_1_r_7_t_6_cnt, S5S8SMStore::mpacket_sm_3_i_1_r_7_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_1_r_7_t_7_busy, S5S8SMStore::mpacket_sm_3_i_1_r_7_t_7_cnt, S5S8SMStore::mpacket_sm_3_i_1_r_7_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_1_r_7_t_8_busy, S5S8SMStore::mpacket_sm_3_i_1_r_7_t_8_cnt, S5S8SMStore::mpacket_sm_3_i_1_r_7_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_1_r_7_t_9_busy, S5S8SMStore::mpacket_sm_3_i_1_r_7_t_9_cnt, S5S8SMStore::mpacket_sm_3_i_1_r_7_t_9, msgObj);
				break;
			}
			break;
	}
}


VOID S5S8MessageBroker::pushToQueue_i_2_r_0(MPacket *msgObj, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_2_r_0_t_0_busy, S5S8SMStore::mpacket_sm_0_i_2_r_0_t_0_cnt, S5S8SMStore::mpacket_sm_0_i_2_r_0_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_2_r_0_t_1_busy, S5S8SMStore::mpacket_sm_0_i_2_r_0_t_1_cnt, S5S8SMStore::mpacket_sm_0_i_2_r_0_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_2_r_0_t_2_busy, S5S8SMStore::mpacket_sm_0_i_2_r_0_t_2_cnt, S5S8SMStore::mpacket_sm_0_i_2_r_0_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_2_r_0_t_3_busy, S5S8SMStore::mpacket_sm_0_i_2_r_0_t_3_cnt, S5S8SMStore::mpacket_sm_0_i_2_r_0_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_2_r_0_t_4_busy, S5S8SMStore::mpacket_sm_0_i_2_r_0_t_4_cnt, S5S8SMStore::mpacket_sm_0_i_2_r_0_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_2_r_0_t_5_busy, S5S8SMStore::mpacket_sm_0_i_2_r_0_t_5_cnt, S5S8SMStore::mpacket_sm_0_i_2_r_0_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_2_r_0_t_6_busy, S5S8SMStore::mpacket_sm_0_i_2_r_0_t_6_cnt, S5S8SMStore::mpacket_sm_0_i_2_r_0_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_2_r_0_t_7_busy, S5S8SMStore::mpacket_sm_0_i_2_r_0_t_7_cnt, S5S8SMStore::mpacket_sm_0_i_2_r_0_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_2_r_0_t_8_busy, S5S8SMStore::mpacket_sm_0_i_2_r_0_t_8_cnt, S5S8SMStore::mpacket_sm_0_i_2_r_0_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_2_r_0_t_9_busy, S5S8SMStore::mpacket_sm_0_i_2_r_0_t_9_cnt, S5S8SMStore::mpacket_sm_0_i_2_r_0_t_9, msgObj);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_2_r_0_t_0_busy, S5S8SMStore::mpacket_sm_1_i_2_r_0_t_0_cnt, S5S8SMStore::mpacket_sm_1_i_2_r_0_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_2_r_0_t_1_busy, S5S8SMStore::mpacket_sm_1_i_2_r_0_t_1_cnt, S5S8SMStore::mpacket_sm_1_i_2_r_0_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_2_r_0_t_2_busy, S5S8SMStore::mpacket_sm_1_i_2_r_0_t_2_cnt, S5S8SMStore::mpacket_sm_1_i_2_r_0_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_2_r_0_t_3_busy, S5S8SMStore::mpacket_sm_1_i_2_r_0_t_3_cnt, S5S8SMStore::mpacket_sm_1_i_2_r_0_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_2_r_0_t_4_busy, S5S8SMStore::mpacket_sm_1_i_2_r_0_t_4_cnt, S5S8SMStore::mpacket_sm_1_i_2_r_0_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_2_r_0_t_5_busy, S5S8SMStore::mpacket_sm_1_i_2_r_0_t_5_cnt, S5S8SMStore::mpacket_sm_1_i_2_r_0_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_2_r_0_t_6_busy, S5S8SMStore::mpacket_sm_1_i_2_r_0_t_6_cnt, S5S8SMStore::mpacket_sm_1_i_2_r_0_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_2_r_0_t_7_busy, S5S8SMStore::mpacket_sm_1_i_2_r_0_t_7_cnt, S5S8SMStore::mpacket_sm_1_i_2_r_0_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_2_r_0_t_8_busy, S5S8SMStore::mpacket_sm_1_i_2_r_0_t_8_cnt, S5S8SMStore::mpacket_sm_1_i_2_r_0_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_2_r_0_t_9_busy, S5S8SMStore::mpacket_sm_1_i_2_r_0_t_9_cnt, S5S8SMStore::mpacket_sm_1_i_2_r_0_t_9, msgObj);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_2_r_0_t_0_busy, S5S8SMStore::mpacket_sm_2_i_2_r_0_t_0_cnt, S5S8SMStore::mpacket_sm_2_i_2_r_0_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_2_r_0_t_1_busy, S5S8SMStore::mpacket_sm_2_i_2_r_0_t_1_cnt, S5S8SMStore::mpacket_sm_2_i_2_r_0_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_2_r_0_t_2_busy, S5S8SMStore::mpacket_sm_2_i_2_r_0_t_2_cnt, S5S8SMStore::mpacket_sm_2_i_2_r_0_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_2_r_0_t_3_busy, S5S8SMStore::mpacket_sm_2_i_2_r_0_t_3_cnt, S5S8SMStore::mpacket_sm_2_i_2_r_0_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_2_r_0_t_4_busy, S5S8SMStore::mpacket_sm_2_i_2_r_0_t_4_cnt, S5S8SMStore::mpacket_sm_2_i_2_r_0_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_2_r_0_t_5_busy, S5S8SMStore::mpacket_sm_2_i_2_r_0_t_5_cnt, S5S8SMStore::mpacket_sm_2_i_2_r_0_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_2_r_0_t_6_busy, S5S8SMStore::mpacket_sm_2_i_2_r_0_t_6_cnt, S5S8SMStore::mpacket_sm_2_i_2_r_0_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_2_r_0_t_7_busy, S5S8SMStore::mpacket_sm_2_i_2_r_0_t_7_cnt, S5S8SMStore::mpacket_sm_2_i_2_r_0_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_2_r_0_t_8_busy, S5S8SMStore::mpacket_sm_2_i_2_r_0_t_8_cnt, S5S8SMStore::mpacket_sm_2_i_2_r_0_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_2_r_0_t_9_busy, S5S8SMStore::mpacket_sm_2_i_2_r_0_t_9_cnt, S5S8SMStore::mpacket_sm_2_i_2_r_0_t_9, msgObj);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_2_r_0_t_0_busy, S5S8SMStore::mpacket_sm_3_i_2_r_0_t_0_cnt, S5S8SMStore::mpacket_sm_3_i_2_r_0_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_2_r_0_t_1_busy, S5S8SMStore::mpacket_sm_3_i_2_r_0_t_1_cnt, S5S8SMStore::mpacket_sm_3_i_2_r_0_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_2_r_0_t_2_busy, S5S8SMStore::mpacket_sm_3_i_2_r_0_t_2_cnt, S5S8SMStore::mpacket_sm_3_i_2_r_0_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_2_r_0_t_3_busy, S5S8SMStore::mpacket_sm_3_i_2_r_0_t_3_cnt, S5S8SMStore::mpacket_sm_3_i_2_r_0_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_2_r_0_t_4_busy, S5S8SMStore::mpacket_sm_3_i_2_r_0_t_4_cnt, S5S8SMStore::mpacket_sm_3_i_2_r_0_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_2_r_0_t_5_busy, S5S8SMStore::mpacket_sm_3_i_2_r_0_t_5_cnt, S5S8SMStore::mpacket_sm_3_i_2_r_0_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_2_r_0_t_6_busy, S5S8SMStore::mpacket_sm_3_i_2_r_0_t_6_cnt, S5S8SMStore::mpacket_sm_3_i_2_r_0_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_2_r_0_t_7_busy, S5S8SMStore::mpacket_sm_3_i_2_r_0_t_7_cnt, S5S8SMStore::mpacket_sm_3_i_2_r_0_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_2_r_0_t_8_busy, S5S8SMStore::mpacket_sm_3_i_2_r_0_t_8_cnt, S5S8SMStore::mpacket_sm_3_i_2_r_0_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_2_r_0_t_9_busy, S5S8SMStore::mpacket_sm_3_i_2_r_0_t_9_cnt, S5S8SMStore::mpacket_sm_3_i_2_r_0_t_9, msgObj);
				break;
			}
			break;
	}
}

VOID S5S8MessageBroker::pushToQueue_i_2_r_1(MPacket *msgObj, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_2_r_1_t_0_busy, S5S8SMStore::mpacket_sm_0_i_2_r_1_t_0_cnt, S5S8SMStore::mpacket_sm_0_i_2_r_1_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_2_r_1_t_1_busy, S5S8SMStore::mpacket_sm_0_i_2_r_1_t_1_cnt, S5S8SMStore::mpacket_sm_0_i_2_r_1_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_2_r_1_t_2_busy, S5S8SMStore::mpacket_sm_0_i_2_r_1_t_2_cnt, S5S8SMStore::mpacket_sm_0_i_2_r_1_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_2_r_1_t_3_busy, S5S8SMStore::mpacket_sm_0_i_2_r_1_t_3_cnt, S5S8SMStore::mpacket_sm_0_i_2_r_1_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_2_r_1_t_4_busy, S5S8SMStore::mpacket_sm_0_i_2_r_1_t_4_cnt, S5S8SMStore::mpacket_sm_0_i_2_r_1_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_2_r_1_t_5_busy, S5S8SMStore::mpacket_sm_0_i_2_r_1_t_5_cnt, S5S8SMStore::mpacket_sm_0_i_2_r_1_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_2_r_1_t_6_busy, S5S8SMStore::mpacket_sm_0_i_2_r_1_t_6_cnt, S5S8SMStore::mpacket_sm_0_i_2_r_1_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_2_r_1_t_7_busy, S5S8SMStore::mpacket_sm_0_i_2_r_1_t_7_cnt, S5S8SMStore::mpacket_sm_0_i_2_r_1_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_2_r_1_t_8_busy, S5S8SMStore::mpacket_sm_0_i_2_r_1_t_8_cnt, S5S8SMStore::mpacket_sm_0_i_2_r_1_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_2_r_1_t_9_busy, S5S8SMStore::mpacket_sm_0_i_2_r_1_t_9_cnt, S5S8SMStore::mpacket_sm_0_i_2_r_1_t_9, msgObj);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_2_r_1_t_0_busy, S5S8SMStore::mpacket_sm_1_i_2_r_1_t_0_cnt, S5S8SMStore::mpacket_sm_1_i_2_r_1_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_2_r_1_t_1_busy, S5S8SMStore::mpacket_sm_1_i_2_r_1_t_1_cnt, S5S8SMStore::mpacket_sm_1_i_2_r_1_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_2_r_1_t_2_busy, S5S8SMStore::mpacket_sm_1_i_2_r_1_t_2_cnt, S5S8SMStore::mpacket_sm_1_i_2_r_1_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_2_r_1_t_3_busy, S5S8SMStore::mpacket_sm_1_i_2_r_1_t_3_cnt, S5S8SMStore::mpacket_sm_1_i_2_r_1_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_2_r_1_t_4_busy, S5S8SMStore::mpacket_sm_1_i_2_r_1_t_4_cnt, S5S8SMStore::mpacket_sm_1_i_2_r_1_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_2_r_1_t_5_busy, S5S8SMStore::mpacket_sm_1_i_2_r_1_t_5_cnt, S5S8SMStore::mpacket_sm_1_i_2_r_1_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_2_r_1_t_6_busy, S5S8SMStore::mpacket_sm_1_i_2_r_1_t_6_cnt, S5S8SMStore::mpacket_sm_1_i_2_r_1_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_2_r_1_t_7_busy, S5S8SMStore::mpacket_sm_1_i_2_r_1_t_7_cnt, S5S8SMStore::mpacket_sm_1_i_2_r_1_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_2_r_1_t_8_busy, S5S8SMStore::mpacket_sm_1_i_2_r_1_t_8_cnt, S5S8SMStore::mpacket_sm_1_i_2_r_1_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_2_r_1_t_9_busy, S5S8SMStore::mpacket_sm_1_i_2_r_1_t_9_cnt, S5S8SMStore::mpacket_sm_1_i_2_r_1_t_9, msgObj);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_2_r_1_t_0_busy, S5S8SMStore::mpacket_sm_2_i_2_r_1_t_0_cnt, S5S8SMStore::mpacket_sm_2_i_2_r_1_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_2_r_1_t_1_busy, S5S8SMStore::mpacket_sm_2_i_2_r_1_t_1_cnt, S5S8SMStore::mpacket_sm_2_i_2_r_1_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_2_r_1_t_2_busy, S5S8SMStore::mpacket_sm_2_i_2_r_1_t_2_cnt, S5S8SMStore::mpacket_sm_2_i_2_r_1_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_2_r_1_t_3_busy, S5S8SMStore::mpacket_sm_2_i_2_r_1_t_3_cnt, S5S8SMStore::mpacket_sm_2_i_2_r_1_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_2_r_1_t_4_busy, S5S8SMStore::mpacket_sm_2_i_2_r_1_t_4_cnt, S5S8SMStore::mpacket_sm_2_i_2_r_1_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_2_r_1_t_5_busy, S5S8SMStore::mpacket_sm_2_i_2_r_1_t_5_cnt, S5S8SMStore::mpacket_sm_2_i_2_r_1_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_2_r_1_t_6_busy, S5S8SMStore::mpacket_sm_2_i_2_r_1_t_6_cnt, S5S8SMStore::mpacket_sm_2_i_2_r_1_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_2_r_1_t_7_busy, S5S8SMStore::mpacket_sm_2_i_2_r_1_t_7_cnt, S5S8SMStore::mpacket_sm_2_i_2_r_1_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_2_r_1_t_8_busy, S5S8SMStore::mpacket_sm_2_i_2_r_1_t_8_cnt, S5S8SMStore::mpacket_sm_2_i_2_r_1_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_2_r_1_t_9_busy, S5S8SMStore::mpacket_sm_2_i_2_r_1_t_9_cnt, S5S8SMStore::mpacket_sm_2_i_2_r_1_t_9, msgObj);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_2_r_1_t_0_busy, S5S8SMStore::mpacket_sm_3_i_2_r_1_t_0_cnt, S5S8SMStore::mpacket_sm_3_i_2_r_1_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_2_r_1_t_1_busy, S5S8SMStore::mpacket_sm_3_i_2_r_1_t_1_cnt, S5S8SMStore::mpacket_sm_3_i_2_r_1_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_2_r_1_t_2_busy, S5S8SMStore::mpacket_sm_3_i_2_r_1_t_2_cnt, S5S8SMStore::mpacket_sm_3_i_2_r_1_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_2_r_1_t_3_busy, S5S8SMStore::mpacket_sm_3_i_2_r_1_t_3_cnt, S5S8SMStore::mpacket_sm_3_i_2_r_1_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_2_r_1_t_4_busy, S5S8SMStore::mpacket_sm_3_i_2_r_1_t_4_cnt, S5S8SMStore::mpacket_sm_3_i_2_r_1_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_2_r_1_t_5_busy, S5S8SMStore::mpacket_sm_3_i_2_r_1_t_5_cnt, S5S8SMStore::mpacket_sm_3_i_2_r_1_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_2_r_1_t_6_busy, S5S8SMStore::mpacket_sm_3_i_2_r_1_t_6_cnt, S5S8SMStore::mpacket_sm_3_i_2_r_1_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_2_r_1_t_7_busy, S5S8SMStore::mpacket_sm_3_i_2_r_1_t_7_cnt, S5S8SMStore::mpacket_sm_3_i_2_r_1_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_2_r_1_t_8_busy, S5S8SMStore::mpacket_sm_3_i_2_r_1_t_8_cnt, S5S8SMStore::mpacket_sm_3_i_2_r_1_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_2_r_1_t_9_busy, S5S8SMStore::mpacket_sm_3_i_2_r_1_t_9_cnt, S5S8SMStore::mpacket_sm_3_i_2_r_1_t_9, msgObj);
				break;
			}
			break;
	}
}

VOID S5S8MessageBroker::pushToQueue_i_2_r_2(MPacket *msgObj, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_2_r_2_t_0_busy, S5S8SMStore::mpacket_sm_0_i_2_r_2_t_0_cnt, S5S8SMStore::mpacket_sm_0_i_2_r_2_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_2_r_2_t_1_busy, S5S8SMStore::mpacket_sm_0_i_2_r_2_t_1_cnt, S5S8SMStore::mpacket_sm_0_i_2_r_2_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_2_r_2_t_2_busy, S5S8SMStore::mpacket_sm_0_i_2_r_2_t_2_cnt, S5S8SMStore::mpacket_sm_0_i_2_r_2_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_2_r_2_t_3_busy, S5S8SMStore::mpacket_sm_0_i_2_r_2_t_3_cnt, S5S8SMStore::mpacket_sm_0_i_2_r_2_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_2_r_2_t_4_busy, S5S8SMStore::mpacket_sm_0_i_2_r_2_t_4_cnt, S5S8SMStore::mpacket_sm_0_i_2_r_2_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_2_r_2_t_5_busy, S5S8SMStore::mpacket_sm_0_i_2_r_2_t_5_cnt, S5S8SMStore::mpacket_sm_0_i_2_r_2_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_2_r_2_t_6_busy, S5S8SMStore::mpacket_sm_0_i_2_r_2_t_6_cnt, S5S8SMStore::mpacket_sm_0_i_2_r_2_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_2_r_2_t_7_busy, S5S8SMStore::mpacket_sm_0_i_2_r_2_t_7_cnt, S5S8SMStore::mpacket_sm_0_i_2_r_2_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_2_r_2_t_8_busy, S5S8SMStore::mpacket_sm_0_i_2_r_2_t_8_cnt, S5S8SMStore::mpacket_sm_0_i_2_r_2_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_2_r_2_t_9_busy, S5S8SMStore::mpacket_sm_0_i_2_r_2_t_9_cnt, S5S8SMStore::mpacket_sm_0_i_2_r_2_t_9, msgObj);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_2_r_2_t_0_busy, S5S8SMStore::mpacket_sm_1_i_2_r_2_t_0_cnt, S5S8SMStore::mpacket_sm_1_i_2_r_2_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_2_r_2_t_1_busy, S5S8SMStore::mpacket_sm_1_i_2_r_2_t_1_cnt, S5S8SMStore::mpacket_sm_1_i_2_r_2_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_2_r_2_t_2_busy, S5S8SMStore::mpacket_sm_1_i_2_r_2_t_2_cnt, S5S8SMStore::mpacket_sm_1_i_2_r_2_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_2_r_2_t_3_busy, S5S8SMStore::mpacket_sm_1_i_2_r_2_t_3_cnt, S5S8SMStore::mpacket_sm_1_i_2_r_2_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_2_r_2_t_4_busy, S5S8SMStore::mpacket_sm_1_i_2_r_2_t_4_cnt, S5S8SMStore::mpacket_sm_1_i_2_r_2_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_2_r_2_t_5_busy, S5S8SMStore::mpacket_sm_1_i_2_r_2_t_5_cnt, S5S8SMStore::mpacket_sm_1_i_2_r_2_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_2_r_2_t_6_busy, S5S8SMStore::mpacket_sm_1_i_2_r_2_t_6_cnt, S5S8SMStore::mpacket_sm_1_i_2_r_2_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_2_r_2_t_7_busy, S5S8SMStore::mpacket_sm_1_i_2_r_2_t_7_cnt, S5S8SMStore::mpacket_sm_1_i_2_r_2_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_2_r_2_t_8_busy, S5S8SMStore::mpacket_sm_1_i_2_r_2_t_8_cnt, S5S8SMStore::mpacket_sm_1_i_2_r_2_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_2_r_2_t_9_busy, S5S8SMStore::mpacket_sm_1_i_2_r_2_t_9_cnt, S5S8SMStore::mpacket_sm_1_i_2_r_2_t_9, msgObj);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_2_r_2_t_0_busy, S5S8SMStore::mpacket_sm_2_i_2_r_2_t_0_cnt, S5S8SMStore::mpacket_sm_2_i_2_r_2_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_2_r_2_t_1_busy, S5S8SMStore::mpacket_sm_2_i_2_r_2_t_1_cnt, S5S8SMStore::mpacket_sm_2_i_2_r_2_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_2_r_2_t_2_busy, S5S8SMStore::mpacket_sm_2_i_2_r_2_t_2_cnt, S5S8SMStore::mpacket_sm_2_i_2_r_2_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_2_r_2_t_3_busy, S5S8SMStore::mpacket_sm_2_i_2_r_2_t_3_cnt, S5S8SMStore::mpacket_sm_2_i_2_r_2_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_2_r_2_t_4_busy, S5S8SMStore::mpacket_sm_2_i_2_r_2_t_4_cnt, S5S8SMStore::mpacket_sm_2_i_2_r_2_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_2_r_2_t_5_busy, S5S8SMStore::mpacket_sm_2_i_2_r_2_t_5_cnt, S5S8SMStore::mpacket_sm_2_i_2_r_2_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_2_r_2_t_6_busy, S5S8SMStore::mpacket_sm_2_i_2_r_2_t_6_cnt, S5S8SMStore::mpacket_sm_2_i_2_r_2_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_2_r_2_t_7_busy, S5S8SMStore::mpacket_sm_2_i_2_r_2_t_7_cnt, S5S8SMStore::mpacket_sm_2_i_2_r_2_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_2_r_2_t_8_busy, S5S8SMStore::mpacket_sm_2_i_2_r_2_t_8_cnt, S5S8SMStore::mpacket_sm_2_i_2_r_2_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_2_r_2_t_9_busy, S5S8SMStore::mpacket_sm_2_i_2_r_2_t_9_cnt, S5S8SMStore::mpacket_sm_2_i_2_r_2_t_9, msgObj);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_2_r_2_t_0_busy, S5S8SMStore::mpacket_sm_3_i_2_r_2_t_0_cnt, S5S8SMStore::mpacket_sm_3_i_2_r_2_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_2_r_2_t_1_busy, S5S8SMStore::mpacket_sm_3_i_2_r_2_t_1_cnt, S5S8SMStore::mpacket_sm_3_i_2_r_2_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_2_r_2_t_2_busy, S5S8SMStore::mpacket_sm_3_i_2_r_2_t_2_cnt, S5S8SMStore::mpacket_sm_3_i_2_r_2_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_2_r_2_t_3_busy, S5S8SMStore::mpacket_sm_3_i_2_r_2_t_3_cnt, S5S8SMStore::mpacket_sm_3_i_2_r_2_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_2_r_2_t_4_busy, S5S8SMStore::mpacket_sm_3_i_2_r_2_t_4_cnt, S5S8SMStore::mpacket_sm_3_i_2_r_2_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_2_r_2_t_5_busy, S5S8SMStore::mpacket_sm_3_i_2_r_2_t_5_cnt, S5S8SMStore::mpacket_sm_3_i_2_r_2_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_2_r_2_t_6_busy, S5S8SMStore::mpacket_sm_3_i_2_r_2_t_6_cnt, S5S8SMStore::mpacket_sm_3_i_2_r_2_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_2_r_2_t_7_busy, S5S8SMStore::mpacket_sm_3_i_2_r_2_t_7_cnt, S5S8SMStore::mpacket_sm_3_i_2_r_2_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_2_r_2_t_8_busy, S5S8SMStore::mpacket_sm_3_i_2_r_2_t_8_cnt, S5S8SMStore::mpacket_sm_3_i_2_r_2_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_2_r_2_t_9_busy, S5S8SMStore::mpacket_sm_3_i_2_r_2_t_9_cnt, S5S8SMStore::mpacket_sm_3_i_2_r_2_t_9, msgObj);
				break;
			}
			break;
	}
}

VOID S5S8MessageBroker::pushToQueue_i_2_r_3(MPacket *msgObj, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_2_r_3_t_0_busy, S5S8SMStore::mpacket_sm_0_i_2_r_3_t_0_cnt, S5S8SMStore::mpacket_sm_0_i_2_r_3_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_2_r_3_t_1_busy, S5S8SMStore::mpacket_sm_0_i_2_r_3_t_1_cnt, S5S8SMStore::mpacket_sm_0_i_2_r_3_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_2_r_3_t_2_busy, S5S8SMStore::mpacket_sm_0_i_2_r_3_t_2_cnt, S5S8SMStore::mpacket_sm_0_i_2_r_3_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_2_r_3_t_3_busy, S5S8SMStore::mpacket_sm_0_i_2_r_3_t_3_cnt, S5S8SMStore::mpacket_sm_0_i_2_r_3_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_2_r_3_t_4_busy, S5S8SMStore::mpacket_sm_0_i_2_r_3_t_4_cnt, S5S8SMStore::mpacket_sm_0_i_2_r_3_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_2_r_3_t_5_busy, S5S8SMStore::mpacket_sm_0_i_2_r_3_t_5_cnt, S5S8SMStore::mpacket_sm_0_i_2_r_3_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_2_r_3_t_6_busy, S5S8SMStore::mpacket_sm_0_i_2_r_3_t_6_cnt, S5S8SMStore::mpacket_sm_0_i_2_r_3_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_2_r_3_t_7_busy, S5S8SMStore::mpacket_sm_0_i_2_r_3_t_7_cnt, S5S8SMStore::mpacket_sm_0_i_2_r_3_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_2_r_3_t_8_busy, S5S8SMStore::mpacket_sm_0_i_2_r_3_t_8_cnt, S5S8SMStore::mpacket_sm_0_i_2_r_3_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_2_r_3_t_9_busy, S5S8SMStore::mpacket_sm_0_i_2_r_3_t_9_cnt, S5S8SMStore::mpacket_sm_0_i_2_r_3_t_9, msgObj);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_2_r_3_t_0_busy, S5S8SMStore::mpacket_sm_1_i_2_r_3_t_0_cnt, S5S8SMStore::mpacket_sm_1_i_2_r_3_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_2_r_3_t_1_busy, S5S8SMStore::mpacket_sm_1_i_2_r_3_t_1_cnt, S5S8SMStore::mpacket_sm_1_i_2_r_3_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_2_r_3_t_2_busy, S5S8SMStore::mpacket_sm_1_i_2_r_3_t_2_cnt, S5S8SMStore::mpacket_sm_1_i_2_r_3_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_2_r_3_t_3_busy, S5S8SMStore::mpacket_sm_1_i_2_r_3_t_3_cnt, S5S8SMStore::mpacket_sm_1_i_2_r_3_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_2_r_3_t_4_busy, S5S8SMStore::mpacket_sm_1_i_2_r_3_t_4_cnt, S5S8SMStore::mpacket_sm_1_i_2_r_3_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_2_r_3_t_5_busy, S5S8SMStore::mpacket_sm_1_i_2_r_3_t_5_cnt, S5S8SMStore::mpacket_sm_1_i_2_r_3_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_2_r_3_t_6_busy, S5S8SMStore::mpacket_sm_1_i_2_r_3_t_6_cnt, S5S8SMStore::mpacket_sm_1_i_2_r_3_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_2_r_3_t_7_busy, S5S8SMStore::mpacket_sm_1_i_2_r_3_t_7_cnt, S5S8SMStore::mpacket_sm_1_i_2_r_3_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_2_r_3_t_8_busy, S5S8SMStore::mpacket_sm_1_i_2_r_3_t_8_cnt, S5S8SMStore::mpacket_sm_1_i_2_r_3_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_2_r_3_t_9_busy, S5S8SMStore::mpacket_sm_1_i_2_r_3_t_9_cnt, S5S8SMStore::mpacket_sm_1_i_2_r_3_t_9, msgObj);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_2_r_3_t_0_busy, S5S8SMStore::mpacket_sm_2_i_2_r_3_t_0_cnt, S5S8SMStore::mpacket_sm_2_i_2_r_3_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_2_r_3_t_1_busy, S5S8SMStore::mpacket_sm_2_i_2_r_3_t_1_cnt, S5S8SMStore::mpacket_sm_2_i_2_r_3_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_2_r_3_t_2_busy, S5S8SMStore::mpacket_sm_2_i_2_r_3_t_2_cnt, S5S8SMStore::mpacket_sm_2_i_2_r_3_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_2_r_3_t_3_busy, S5S8SMStore::mpacket_sm_2_i_2_r_3_t_3_cnt, S5S8SMStore::mpacket_sm_2_i_2_r_3_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_2_r_3_t_4_busy, S5S8SMStore::mpacket_sm_2_i_2_r_3_t_4_cnt, S5S8SMStore::mpacket_sm_2_i_2_r_3_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_2_r_3_t_5_busy, S5S8SMStore::mpacket_sm_2_i_2_r_3_t_5_cnt, S5S8SMStore::mpacket_sm_2_i_2_r_3_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_2_r_3_t_6_busy, S5S8SMStore::mpacket_sm_2_i_2_r_3_t_6_cnt, S5S8SMStore::mpacket_sm_2_i_2_r_3_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_2_r_3_t_7_busy, S5S8SMStore::mpacket_sm_2_i_2_r_3_t_7_cnt, S5S8SMStore::mpacket_sm_2_i_2_r_3_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_2_r_3_t_8_busy, S5S8SMStore::mpacket_sm_2_i_2_r_3_t_8_cnt, S5S8SMStore::mpacket_sm_2_i_2_r_3_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_2_r_3_t_9_busy, S5S8SMStore::mpacket_sm_2_i_2_r_3_t_9_cnt, S5S8SMStore::mpacket_sm_2_i_2_r_3_t_9, msgObj);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_2_r_3_t_0_busy, S5S8SMStore::mpacket_sm_3_i_2_r_3_t_0_cnt, S5S8SMStore::mpacket_sm_3_i_2_r_3_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_2_r_3_t_1_busy, S5S8SMStore::mpacket_sm_3_i_2_r_3_t_1_cnt, S5S8SMStore::mpacket_sm_3_i_2_r_3_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_2_r_3_t_2_busy, S5S8SMStore::mpacket_sm_3_i_2_r_3_t_2_cnt, S5S8SMStore::mpacket_sm_3_i_2_r_3_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_2_r_3_t_3_busy, S5S8SMStore::mpacket_sm_3_i_2_r_3_t_3_cnt, S5S8SMStore::mpacket_sm_3_i_2_r_3_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_2_r_3_t_4_busy, S5S8SMStore::mpacket_sm_3_i_2_r_3_t_4_cnt, S5S8SMStore::mpacket_sm_3_i_2_r_3_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_2_r_3_t_5_busy, S5S8SMStore::mpacket_sm_3_i_2_r_3_t_5_cnt, S5S8SMStore::mpacket_sm_3_i_2_r_3_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_2_r_3_t_6_busy, S5S8SMStore::mpacket_sm_3_i_2_r_3_t_6_cnt, S5S8SMStore::mpacket_sm_3_i_2_r_3_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_2_r_3_t_7_busy, S5S8SMStore::mpacket_sm_3_i_2_r_3_t_7_cnt, S5S8SMStore::mpacket_sm_3_i_2_r_3_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_2_r_3_t_8_busy, S5S8SMStore::mpacket_sm_3_i_2_r_3_t_8_cnt, S5S8SMStore::mpacket_sm_3_i_2_r_3_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_2_r_3_t_9_busy, S5S8SMStore::mpacket_sm_3_i_2_r_3_t_9_cnt, S5S8SMStore::mpacket_sm_3_i_2_r_3_t_9, msgObj);
				break;
			}
			break;
	}
}

VOID S5S8MessageBroker::pushToQueue_i_2_r_4(MPacket *msgObj, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_2_r_4_t_0_busy, S5S8SMStore::mpacket_sm_0_i_2_r_4_t_0_cnt, S5S8SMStore::mpacket_sm_0_i_2_r_4_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_2_r_4_t_1_busy, S5S8SMStore::mpacket_sm_0_i_2_r_4_t_1_cnt, S5S8SMStore::mpacket_sm_0_i_2_r_4_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_2_r_4_t_2_busy, S5S8SMStore::mpacket_sm_0_i_2_r_4_t_2_cnt, S5S8SMStore::mpacket_sm_0_i_2_r_4_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_2_r_4_t_3_busy, S5S8SMStore::mpacket_sm_0_i_2_r_4_t_3_cnt, S5S8SMStore::mpacket_sm_0_i_2_r_4_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_2_r_4_t_4_busy, S5S8SMStore::mpacket_sm_0_i_2_r_4_t_4_cnt, S5S8SMStore::mpacket_sm_0_i_2_r_4_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_2_r_4_t_5_busy, S5S8SMStore::mpacket_sm_0_i_2_r_4_t_5_cnt, S5S8SMStore::mpacket_sm_0_i_2_r_4_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_2_r_4_t_6_busy, S5S8SMStore::mpacket_sm_0_i_2_r_4_t_6_cnt, S5S8SMStore::mpacket_sm_0_i_2_r_4_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_2_r_4_t_7_busy, S5S8SMStore::mpacket_sm_0_i_2_r_4_t_7_cnt, S5S8SMStore::mpacket_sm_0_i_2_r_4_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_2_r_4_t_8_busy, S5S8SMStore::mpacket_sm_0_i_2_r_4_t_8_cnt, S5S8SMStore::mpacket_sm_0_i_2_r_4_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_2_r_4_t_9_busy, S5S8SMStore::mpacket_sm_0_i_2_r_4_t_9_cnt, S5S8SMStore::mpacket_sm_0_i_2_r_4_t_9, msgObj);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_2_r_4_t_0_busy, S5S8SMStore::mpacket_sm_1_i_2_r_4_t_0_cnt, S5S8SMStore::mpacket_sm_1_i_2_r_4_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_2_r_4_t_1_busy, S5S8SMStore::mpacket_sm_1_i_2_r_4_t_1_cnt, S5S8SMStore::mpacket_sm_1_i_2_r_4_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_2_r_4_t_2_busy, S5S8SMStore::mpacket_sm_1_i_2_r_4_t_2_cnt, S5S8SMStore::mpacket_sm_1_i_2_r_4_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_2_r_4_t_3_busy, S5S8SMStore::mpacket_sm_1_i_2_r_4_t_3_cnt, S5S8SMStore::mpacket_sm_1_i_2_r_4_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_2_r_4_t_4_busy, S5S8SMStore::mpacket_sm_1_i_2_r_4_t_4_cnt, S5S8SMStore::mpacket_sm_1_i_2_r_4_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_2_r_4_t_5_busy, S5S8SMStore::mpacket_sm_1_i_2_r_4_t_5_cnt, S5S8SMStore::mpacket_sm_1_i_2_r_4_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_2_r_4_t_6_busy, S5S8SMStore::mpacket_sm_1_i_2_r_4_t_6_cnt, S5S8SMStore::mpacket_sm_1_i_2_r_4_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_2_r_4_t_7_busy, S5S8SMStore::mpacket_sm_1_i_2_r_4_t_7_cnt, S5S8SMStore::mpacket_sm_1_i_2_r_4_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_2_r_4_t_8_busy, S5S8SMStore::mpacket_sm_1_i_2_r_4_t_8_cnt, S5S8SMStore::mpacket_sm_1_i_2_r_4_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_2_r_4_t_9_busy, S5S8SMStore::mpacket_sm_1_i_2_r_4_t_9_cnt, S5S8SMStore::mpacket_sm_1_i_2_r_4_t_9, msgObj);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_2_r_4_t_0_busy, S5S8SMStore::mpacket_sm_2_i_2_r_4_t_0_cnt, S5S8SMStore::mpacket_sm_2_i_2_r_4_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_2_r_4_t_1_busy, S5S8SMStore::mpacket_sm_2_i_2_r_4_t_1_cnt, S5S8SMStore::mpacket_sm_2_i_2_r_4_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_2_r_4_t_2_busy, S5S8SMStore::mpacket_sm_2_i_2_r_4_t_2_cnt, S5S8SMStore::mpacket_sm_2_i_2_r_4_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_2_r_4_t_3_busy, S5S8SMStore::mpacket_sm_2_i_2_r_4_t_3_cnt, S5S8SMStore::mpacket_sm_2_i_2_r_4_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_2_r_4_t_4_busy, S5S8SMStore::mpacket_sm_2_i_2_r_4_t_4_cnt, S5S8SMStore::mpacket_sm_2_i_2_r_4_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_2_r_4_t_5_busy, S5S8SMStore::mpacket_sm_2_i_2_r_4_t_5_cnt, S5S8SMStore::mpacket_sm_2_i_2_r_4_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_2_r_4_t_6_busy, S5S8SMStore::mpacket_sm_2_i_2_r_4_t_6_cnt, S5S8SMStore::mpacket_sm_2_i_2_r_4_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_2_r_4_t_7_busy, S5S8SMStore::mpacket_sm_2_i_2_r_4_t_7_cnt, S5S8SMStore::mpacket_sm_2_i_2_r_4_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_2_r_4_t_8_busy, S5S8SMStore::mpacket_sm_2_i_2_r_4_t_8_cnt, S5S8SMStore::mpacket_sm_2_i_2_r_4_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_2_r_4_t_9_busy, S5S8SMStore::mpacket_sm_2_i_2_r_4_t_9_cnt, S5S8SMStore::mpacket_sm_2_i_2_r_4_t_9, msgObj);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_2_r_4_t_0_busy, S5S8SMStore::mpacket_sm_3_i_2_r_4_t_0_cnt, S5S8SMStore::mpacket_sm_3_i_2_r_4_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_2_r_4_t_1_busy, S5S8SMStore::mpacket_sm_3_i_2_r_4_t_1_cnt, S5S8SMStore::mpacket_sm_3_i_2_r_4_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_2_r_4_t_2_busy, S5S8SMStore::mpacket_sm_3_i_2_r_4_t_2_cnt, S5S8SMStore::mpacket_sm_3_i_2_r_4_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_2_r_4_t_3_busy, S5S8SMStore::mpacket_sm_3_i_2_r_4_t_3_cnt, S5S8SMStore::mpacket_sm_3_i_2_r_4_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_2_r_4_t_4_busy, S5S8SMStore::mpacket_sm_3_i_2_r_4_t_4_cnt, S5S8SMStore::mpacket_sm_3_i_2_r_4_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_2_r_4_t_5_busy, S5S8SMStore::mpacket_sm_3_i_2_r_4_t_5_cnt, S5S8SMStore::mpacket_sm_3_i_2_r_4_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_2_r_4_t_6_busy, S5S8SMStore::mpacket_sm_3_i_2_r_4_t_6_cnt, S5S8SMStore::mpacket_sm_3_i_2_r_4_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_2_r_4_t_7_busy, S5S8SMStore::mpacket_sm_3_i_2_r_4_t_7_cnt, S5S8SMStore::mpacket_sm_3_i_2_r_4_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_2_r_4_t_8_busy, S5S8SMStore::mpacket_sm_3_i_2_r_4_t_8_cnt, S5S8SMStore::mpacket_sm_3_i_2_r_4_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_2_r_4_t_9_busy, S5S8SMStore::mpacket_sm_3_i_2_r_4_t_9_cnt, S5S8SMStore::mpacket_sm_3_i_2_r_4_t_9, msgObj);
				break;
			}
			break;
	}
}

VOID S5S8MessageBroker::pushToQueue_i_2_r_5(MPacket *msgObj, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_2_r_5_t_0_busy, S5S8SMStore::mpacket_sm_0_i_2_r_5_t_0_cnt, S5S8SMStore::mpacket_sm_0_i_2_r_5_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_2_r_5_t_1_busy, S5S8SMStore::mpacket_sm_0_i_2_r_5_t_1_cnt, S5S8SMStore::mpacket_sm_0_i_2_r_5_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_2_r_5_t_2_busy, S5S8SMStore::mpacket_sm_0_i_2_r_5_t_2_cnt, S5S8SMStore::mpacket_sm_0_i_2_r_5_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_2_r_5_t_3_busy, S5S8SMStore::mpacket_sm_0_i_2_r_5_t_3_cnt, S5S8SMStore::mpacket_sm_0_i_2_r_5_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_2_r_5_t_4_busy, S5S8SMStore::mpacket_sm_0_i_2_r_5_t_4_cnt, S5S8SMStore::mpacket_sm_0_i_2_r_5_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_2_r_5_t_5_busy, S5S8SMStore::mpacket_sm_0_i_2_r_5_t_5_cnt, S5S8SMStore::mpacket_sm_0_i_2_r_5_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_2_r_5_t_6_busy, S5S8SMStore::mpacket_sm_0_i_2_r_5_t_6_cnt, S5S8SMStore::mpacket_sm_0_i_2_r_5_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_2_r_5_t_7_busy, S5S8SMStore::mpacket_sm_0_i_2_r_5_t_7_cnt, S5S8SMStore::mpacket_sm_0_i_2_r_5_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_2_r_5_t_8_busy, S5S8SMStore::mpacket_sm_0_i_2_r_5_t_8_cnt, S5S8SMStore::mpacket_sm_0_i_2_r_5_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_2_r_5_t_9_busy, S5S8SMStore::mpacket_sm_0_i_2_r_5_t_9_cnt, S5S8SMStore::mpacket_sm_0_i_2_r_5_t_9, msgObj);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_2_r_5_t_0_busy, S5S8SMStore::mpacket_sm_1_i_2_r_5_t_0_cnt, S5S8SMStore::mpacket_sm_1_i_2_r_5_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_2_r_5_t_1_busy, S5S8SMStore::mpacket_sm_1_i_2_r_5_t_1_cnt, S5S8SMStore::mpacket_sm_1_i_2_r_5_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_2_r_5_t_2_busy, S5S8SMStore::mpacket_sm_1_i_2_r_5_t_2_cnt, S5S8SMStore::mpacket_sm_1_i_2_r_5_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_2_r_5_t_3_busy, S5S8SMStore::mpacket_sm_1_i_2_r_5_t_3_cnt, S5S8SMStore::mpacket_sm_1_i_2_r_5_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_2_r_5_t_4_busy, S5S8SMStore::mpacket_sm_1_i_2_r_5_t_4_cnt, S5S8SMStore::mpacket_sm_1_i_2_r_5_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_2_r_5_t_5_busy, S5S8SMStore::mpacket_sm_1_i_2_r_5_t_5_cnt, S5S8SMStore::mpacket_sm_1_i_2_r_5_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_2_r_5_t_6_busy, S5S8SMStore::mpacket_sm_1_i_2_r_5_t_6_cnt, S5S8SMStore::mpacket_sm_1_i_2_r_5_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_2_r_5_t_7_busy, S5S8SMStore::mpacket_sm_1_i_2_r_5_t_7_cnt, S5S8SMStore::mpacket_sm_1_i_2_r_5_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_2_r_5_t_8_busy, S5S8SMStore::mpacket_sm_1_i_2_r_5_t_8_cnt, S5S8SMStore::mpacket_sm_1_i_2_r_5_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_2_r_5_t_9_busy, S5S8SMStore::mpacket_sm_1_i_2_r_5_t_9_cnt, S5S8SMStore::mpacket_sm_1_i_2_r_5_t_9, msgObj);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_2_r_5_t_0_busy, S5S8SMStore::mpacket_sm_2_i_2_r_5_t_0_cnt, S5S8SMStore::mpacket_sm_2_i_2_r_5_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_2_r_5_t_1_busy, S5S8SMStore::mpacket_sm_2_i_2_r_5_t_1_cnt, S5S8SMStore::mpacket_sm_2_i_2_r_5_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_2_r_5_t_2_busy, S5S8SMStore::mpacket_sm_2_i_2_r_5_t_2_cnt, S5S8SMStore::mpacket_sm_2_i_2_r_5_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_2_r_5_t_3_busy, S5S8SMStore::mpacket_sm_2_i_2_r_5_t_3_cnt, S5S8SMStore::mpacket_sm_2_i_2_r_5_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_2_r_5_t_4_busy, S5S8SMStore::mpacket_sm_2_i_2_r_5_t_4_cnt, S5S8SMStore::mpacket_sm_2_i_2_r_5_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_2_r_5_t_5_busy, S5S8SMStore::mpacket_sm_2_i_2_r_5_t_5_cnt, S5S8SMStore::mpacket_sm_2_i_2_r_5_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_2_r_5_t_6_busy, S5S8SMStore::mpacket_sm_2_i_2_r_5_t_6_cnt, S5S8SMStore::mpacket_sm_2_i_2_r_5_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_2_r_5_t_7_busy, S5S8SMStore::mpacket_sm_2_i_2_r_5_t_7_cnt, S5S8SMStore::mpacket_sm_2_i_2_r_5_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_2_r_5_t_8_busy, S5S8SMStore::mpacket_sm_2_i_2_r_5_t_8_cnt, S5S8SMStore::mpacket_sm_2_i_2_r_5_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_2_r_5_t_9_busy, S5S8SMStore::mpacket_sm_2_i_2_r_5_t_9_cnt, S5S8SMStore::mpacket_sm_2_i_2_r_5_t_9, msgObj);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_2_r_5_t_0_busy, S5S8SMStore::mpacket_sm_3_i_2_r_5_t_0_cnt, S5S8SMStore::mpacket_sm_3_i_2_r_5_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_2_r_5_t_1_busy, S5S8SMStore::mpacket_sm_3_i_2_r_5_t_1_cnt, S5S8SMStore::mpacket_sm_3_i_2_r_5_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_2_r_5_t_2_busy, S5S8SMStore::mpacket_sm_3_i_2_r_5_t_2_cnt, S5S8SMStore::mpacket_sm_3_i_2_r_5_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_2_r_5_t_3_busy, S5S8SMStore::mpacket_sm_3_i_2_r_5_t_3_cnt, S5S8SMStore::mpacket_sm_3_i_2_r_5_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_2_r_5_t_4_busy, S5S8SMStore::mpacket_sm_3_i_2_r_5_t_4_cnt, S5S8SMStore::mpacket_sm_3_i_2_r_5_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_2_r_5_t_5_busy, S5S8SMStore::mpacket_sm_3_i_2_r_5_t_5_cnt, S5S8SMStore::mpacket_sm_3_i_2_r_5_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_2_r_5_t_6_busy, S5S8SMStore::mpacket_sm_3_i_2_r_5_t_6_cnt, S5S8SMStore::mpacket_sm_3_i_2_r_5_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_2_r_5_t_7_busy, S5S8SMStore::mpacket_sm_3_i_2_r_5_t_7_cnt, S5S8SMStore::mpacket_sm_3_i_2_r_5_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_2_r_5_t_8_busy, S5S8SMStore::mpacket_sm_3_i_2_r_5_t_8_cnt, S5S8SMStore::mpacket_sm_3_i_2_r_5_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_2_r_5_t_9_busy, S5S8SMStore::mpacket_sm_3_i_2_r_5_t_9_cnt, S5S8SMStore::mpacket_sm_3_i_2_r_5_t_9, msgObj);
				break;
			}
			break;
	}
}

VOID S5S8MessageBroker::pushToQueue_i_2_r_6(MPacket *msgObj, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_2_r_6_t_0_busy, S5S8SMStore::mpacket_sm_0_i_2_r_6_t_0_cnt, S5S8SMStore::mpacket_sm_0_i_2_r_6_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_2_r_6_t_1_busy, S5S8SMStore::mpacket_sm_0_i_2_r_6_t_1_cnt, S5S8SMStore::mpacket_sm_0_i_2_r_6_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_2_r_6_t_2_busy, S5S8SMStore::mpacket_sm_0_i_2_r_6_t_2_cnt, S5S8SMStore::mpacket_sm_0_i_2_r_6_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_2_r_6_t_3_busy, S5S8SMStore::mpacket_sm_0_i_2_r_6_t_3_cnt, S5S8SMStore::mpacket_sm_0_i_2_r_6_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_2_r_6_t_4_busy, S5S8SMStore::mpacket_sm_0_i_2_r_6_t_4_cnt, S5S8SMStore::mpacket_sm_0_i_2_r_6_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_2_r_6_t_5_busy, S5S8SMStore::mpacket_sm_0_i_2_r_6_t_5_cnt, S5S8SMStore::mpacket_sm_0_i_2_r_6_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_2_r_6_t_6_busy, S5S8SMStore::mpacket_sm_0_i_2_r_6_t_6_cnt, S5S8SMStore::mpacket_sm_0_i_2_r_6_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_2_r_6_t_7_busy, S5S8SMStore::mpacket_sm_0_i_2_r_6_t_7_cnt, S5S8SMStore::mpacket_sm_0_i_2_r_6_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_2_r_6_t_8_busy, S5S8SMStore::mpacket_sm_0_i_2_r_6_t_8_cnt, S5S8SMStore::mpacket_sm_0_i_2_r_6_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_2_r_6_t_9_busy, S5S8SMStore::mpacket_sm_0_i_2_r_6_t_9_cnt, S5S8SMStore::mpacket_sm_0_i_2_r_6_t_9, msgObj);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_2_r_6_t_0_busy, S5S8SMStore::mpacket_sm_1_i_2_r_6_t_0_cnt, S5S8SMStore::mpacket_sm_1_i_2_r_6_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_2_r_6_t_1_busy, S5S8SMStore::mpacket_sm_1_i_2_r_6_t_1_cnt, S5S8SMStore::mpacket_sm_1_i_2_r_6_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_2_r_6_t_2_busy, S5S8SMStore::mpacket_sm_1_i_2_r_6_t_2_cnt, S5S8SMStore::mpacket_sm_1_i_2_r_6_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_2_r_6_t_3_busy, S5S8SMStore::mpacket_sm_1_i_2_r_6_t_3_cnt, S5S8SMStore::mpacket_sm_1_i_2_r_6_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_2_r_6_t_4_busy, S5S8SMStore::mpacket_sm_1_i_2_r_6_t_4_cnt, S5S8SMStore::mpacket_sm_1_i_2_r_6_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_2_r_6_t_5_busy, S5S8SMStore::mpacket_sm_1_i_2_r_6_t_5_cnt, S5S8SMStore::mpacket_sm_1_i_2_r_6_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_2_r_6_t_6_busy, S5S8SMStore::mpacket_sm_1_i_2_r_6_t_6_cnt, S5S8SMStore::mpacket_sm_1_i_2_r_6_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_2_r_6_t_7_busy, S5S8SMStore::mpacket_sm_1_i_2_r_6_t_7_cnt, S5S8SMStore::mpacket_sm_1_i_2_r_6_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_2_r_6_t_8_busy, S5S8SMStore::mpacket_sm_1_i_2_r_6_t_8_cnt, S5S8SMStore::mpacket_sm_1_i_2_r_6_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_2_r_6_t_9_busy, S5S8SMStore::mpacket_sm_1_i_2_r_6_t_9_cnt, S5S8SMStore::mpacket_sm_1_i_2_r_6_t_9, msgObj);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_2_r_6_t_0_busy, S5S8SMStore::mpacket_sm_2_i_2_r_6_t_0_cnt, S5S8SMStore::mpacket_sm_2_i_2_r_6_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_2_r_6_t_1_busy, S5S8SMStore::mpacket_sm_2_i_2_r_6_t_1_cnt, S5S8SMStore::mpacket_sm_2_i_2_r_6_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_2_r_6_t_2_busy, S5S8SMStore::mpacket_sm_2_i_2_r_6_t_2_cnt, S5S8SMStore::mpacket_sm_2_i_2_r_6_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_2_r_6_t_3_busy, S5S8SMStore::mpacket_sm_2_i_2_r_6_t_3_cnt, S5S8SMStore::mpacket_sm_2_i_2_r_6_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_2_r_6_t_4_busy, S5S8SMStore::mpacket_sm_2_i_2_r_6_t_4_cnt, S5S8SMStore::mpacket_sm_2_i_2_r_6_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_2_r_6_t_5_busy, S5S8SMStore::mpacket_sm_2_i_2_r_6_t_5_cnt, S5S8SMStore::mpacket_sm_2_i_2_r_6_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_2_r_6_t_6_busy, S5S8SMStore::mpacket_sm_2_i_2_r_6_t_6_cnt, S5S8SMStore::mpacket_sm_2_i_2_r_6_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_2_r_6_t_7_busy, S5S8SMStore::mpacket_sm_2_i_2_r_6_t_7_cnt, S5S8SMStore::mpacket_sm_2_i_2_r_6_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_2_r_6_t_8_busy, S5S8SMStore::mpacket_sm_2_i_2_r_6_t_8_cnt, S5S8SMStore::mpacket_sm_2_i_2_r_6_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_2_r_6_t_9_busy, S5S8SMStore::mpacket_sm_2_i_2_r_6_t_9_cnt, S5S8SMStore::mpacket_sm_2_i_2_r_6_t_9, msgObj);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_2_r_6_t_0_busy, S5S8SMStore::mpacket_sm_3_i_2_r_6_t_0_cnt, S5S8SMStore::mpacket_sm_3_i_2_r_6_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_2_r_6_t_1_busy, S5S8SMStore::mpacket_sm_3_i_2_r_6_t_1_cnt, S5S8SMStore::mpacket_sm_3_i_2_r_6_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_2_r_6_t_2_busy, S5S8SMStore::mpacket_sm_3_i_2_r_6_t_2_cnt, S5S8SMStore::mpacket_sm_3_i_2_r_6_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_2_r_6_t_3_busy, S5S8SMStore::mpacket_sm_3_i_2_r_6_t_3_cnt, S5S8SMStore::mpacket_sm_3_i_2_r_6_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_2_r_6_t_4_busy, S5S8SMStore::mpacket_sm_3_i_2_r_6_t_4_cnt, S5S8SMStore::mpacket_sm_3_i_2_r_6_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_2_r_6_t_5_busy, S5S8SMStore::mpacket_sm_3_i_2_r_6_t_5_cnt, S5S8SMStore::mpacket_sm_3_i_2_r_6_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_2_r_6_t_6_busy, S5S8SMStore::mpacket_sm_3_i_2_r_6_t_6_cnt, S5S8SMStore::mpacket_sm_3_i_2_r_6_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_2_r_6_t_7_busy, S5S8SMStore::mpacket_sm_3_i_2_r_6_t_7_cnt, S5S8SMStore::mpacket_sm_3_i_2_r_6_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_2_r_6_t_8_busy, S5S8SMStore::mpacket_sm_3_i_2_r_6_t_8_cnt, S5S8SMStore::mpacket_sm_3_i_2_r_6_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_2_r_6_t_9_busy, S5S8SMStore::mpacket_sm_3_i_2_r_6_t_9_cnt, S5S8SMStore::mpacket_sm_3_i_2_r_6_t_9, msgObj);
				break;
			}
			break;
	}
}

VOID S5S8MessageBroker::pushToQueue_i_2_r_7(MPacket *msgObj, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_2_r_7_t_0_busy, S5S8SMStore::mpacket_sm_0_i_2_r_7_t_0_cnt, S5S8SMStore::mpacket_sm_0_i_2_r_7_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_2_r_7_t_1_busy, S5S8SMStore::mpacket_sm_0_i_2_r_7_t_1_cnt, S5S8SMStore::mpacket_sm_0_i_2_r_7_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_2_r_7_t_2_busy, S5S8SMStore::mpacket_sm_0_i_2_r_7_t_2_cnt, S5S8SMStore::mpacket_sm_0_i_2_r_7_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_2_r_7_t_3_busy, S5S8SMStore::mpacket_sm_0_i_2_r_7_t_3_cnt, S5S8SMStore::mpacket_sm_0_i_2_r_7_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_2_r_7_t_4_busy, S5S8SMStore::mpacket_sm_0_i_2_r_7_t_4_cnt, S5S8SMStore::mpacket_sm_0_i_2_r_7_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_2_r_7_t_5_busy, S5S8SMStore::mpacket_sm_0_i_2_r_7_t_5_cnt, S5S8SMStore::mpacket_sm_0_i_2_r_7_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_2_r_7_t_6_busy, S5S8SMStore::mpacket_sm_0_i_2_r_7_t_6_cnt, S5S8SMStore::mpacket_sm_0_i_2_r_7_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_2_r_7_t_7_busy, S5S8SMStore::mpacket_sm_0_i_2_r_7_t_7_cnt, S5S8SMStore::mpacket_sm_0_i_2_r_7_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_2_r_7_t_8_busy, S5S8SMStore::mpacket_sm_0_i_2_r_7_t_8_cnt, S5S8SMStore::mpacket_sm_0_i_2_r_7_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_2_r_7_t_9_busy, S5S8SMStore::mpacket_sm_0_i_2_r_7_t_9_cnt, S5S8SMStore::mpacket_sm_0_i_2_r_7_t_9, msgObj);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_2_r_7_t_0_busy, S5S8SMStore::mpacket_sm_1_i_2_r_7_t_0_cnt, S5S8SMStore::mpacket_sm_1_i_2_r_7_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_2_r_7_t_1_busy, S5S8SMStore::mpacket_sm_1_i_2_r_7_t_1_cnt, S5S8SMStore::mpacket_sm_1_i_2_r_7_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_2_r_7_t_2_busy, S5S8SMStore::mpacket_sm_1_i_2_r_7_t_2_cnt, S5S8SMStore::mpacket_sm_1_i_2_r_7_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_2_r_7_t_3_busy, S5S8SMStore::mpacket_sm_1_i_2_r_7_t_3_cnt, S5S8SMStore::mpacket_sm_1_i_2_r_7_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_2_r_7_t_4_busy, S5S8SMStore::mpacket_sm_1_i_2_r_7_t_4_cnt, S5S8SMStore::mpacket_sm_1_i_2_r_7_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_2_r_7_t_5_busy, S5S8SMStore::mpacket_sm_1_i_2_r_7_t_5_cnt, S5S8SMStore::mpacket_sm_1_i_2_r_7_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_2_r_7_t_6_busy, S5S8SMStore::mpacket_sm_1_i_2_r_7_t_6_cnt, S5S8SMStore::mpacket_sm_1_i_2_r_7_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_2_r_7_t_7_busy, S5S8SMStore::mpacket_sm_1_i_2_r_7_t_7_cnt, S5S8SMStore::mpacket_sm_1_i_2_r_7_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_2_r_7_t_8_busy, S5S8SMStore::mpacket_sm_1_i_2_r_7_t_8_cnt, S5S8SMStore::mpacket_sm_1_i_2_r_7_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_2_r_7_t_9_busy, S5S8SMStore::mpacket_sm_1_i_2_r_7_t_9_cnt, S5S8SMStore::mpacket_sm_1_i_2_r_7_t_9, msgObj);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_2_r_7_t_0_busy, S5S8SMStore::mpacket_sm_2_i_2_r_7_t_0_cnt, S5S8SMStore::mpacket_sm_2_i_2_r_7_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_2_r_7_t_1_busy, S5S8SMStore::mpacket_sm_2_i_2_r_7_t_1_cnt, S5S8SMStore::mpacket_sm_2_i_2_r_7_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_2_r_7_t_2_busy, S5S8SMStore::mpacket_sm_2_i_2_r_7_t_2_cnt, S5S8SMStore::mpacket_sm_2_i_2_r_7_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_2_r_7_t_3_busy, S5S8SMStore::mpacket_sm_2_i_2_r_7_t_3_cnt, S5S8SMStore::mpacket_sm_2_i_2_r_7_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_2_r_7_t_4_busy, S5S8SMStore::mpacket_sm_2_i_2_r_7_t_4_cnt, S5S8SMStore::mpacket_sm_2_i_2_r_7_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_2_r_7_t_5_busy, S5S8SMStore::mpacket_sm_2_i_2_r_7_t_5_cnt, S5S8SMStore::mpacket_sm_2_i_2_r_7_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_2_r_7_t_6_busy, S5S8SMStore::mpacket_sm_2_i_2_r_7_t_6_cnt, S5S8SMStore::mpacket_sm_2_i_2_r_7_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_2_r_7_t_7_busy, S5S8SMStore::mpacket_sm_2_i_2_r_7_t_7_cnt, S5S8SMStore::mpacket_sm_2_i_2_r_7_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_2_r_7_t_8_busy, S5S8SMStore::mpacket_sm_2_i_2_r_7_t_8_cnt, S5S8SMStore::mpacket_sm_2_i_2_r_7_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_2_r_7_t_9_busy, S5S8SMStore::mpacket_sm_2_i_2_r_7_t_9_cnt, S5S8SMStore::mpacket_sm_2_i_2_r_7_t_9, msgObj);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_2_r_7_t_0_busy, S5S8SMStore::mpacket_sm_3_i_2_r_7_t_0_cnt, S5S8SMStore::mpacket_sm_3_i_2_r_7_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_2_r_7_t_1_busy, S5S8SMStore::mpacket_sm_3_i_2_r_7_t_1_cnt, S5S8SMStore::mpacket_sm_3_i_2_r_7_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_2_r_7_t_2_busy, S5S8SMStore::mpacket_sm_3_i_2_r_7_t_2_cnt, S5S8SMStore::mpacket_sm_3_i_2_r_7_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_2_r_7_t_3_busy, S5S8SMStore::mpacket_sm_3_i_2_r_7_t_3_cnt, S5S8SMStore::mpacket_sm_3_i_2_r_7_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_2_r_7_t_4_busy, S5S8SMStore::mpacket_sm_3_i_2_r_7_t_4_cnt, S5S8SMStore::mpacket_sm_3_i_2_r_7_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_2_r_7_t_5_busy, S5S8SMStore::mpacket_sm_3_i_2_r_7_t_5_cnt, S5S8SMStore::mpacket_sm_3_i_2_r_7_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_2_r_7_t_6_busy, S5S8SMStore::mpacket_sm_3_i_2_r_7_t_6_cnt, S5S8SMStore::mpacket_sm_3_i_2_r_7_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_2_r_7_t_7_busy, S5S8SMStore::mpacket_sm_3_i_2_r_7_t_7_cnt, S5S8SMStore::mpacket_sm_3_i_2_r_7_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_2_r_7_t_8_busy, S5S8SMStore::mpacket_sm_3_i_2_r_7_t_8_cnt, S5S8SMStore::mpacket_sm_3_i_2_r_7_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_2_r_7_t_9_busy, S5S8SMStore::mpacket_sm_3_i_2_r_7_t_9_cnt, S5S8SMStore::mpacket_sm_3_i_2_r_7_t_9, msgObj);
				break;
			}
			break;
	}
}


VOID S5S8MessageBroker::pushToQueue_i_3_r_0(MPacket *msgObj, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_3_r_0_t_0_busy, S5S8SMStore::mpacket_sm_0_i_3_r_0_t_0_cnt, S5S8SMStore::mpacket_sm_0_i_3_r_0_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_3_r_0_t_1_busy, S5S8SMStore::mpacket_sm_0_i_3_r_0_t_1_cnt, S5S8SMStore::mpacket_sm_0_i_3_r_0_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_3_r_0_t_2_busy, S5S8SMStore::mpacket_sm_0_i_3_r_0_t_2_cnt, S5S8SMStore::mpacket_sm_0_i_3_r_0_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_3_r_0_t_3_busy, S5S8SMStore::mpacket_sm_0_i_3_r_0_t_3_cnt, S5S8SMStore::mpacket_sm_0_i_3_r_0_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_3_r_0_t_4_busy, S5S8SMStore::mpacket_sm_0_i_3_r_0_t_4_cnt, S5S8SMStore::mpacket_sm_0_i_3_r_0_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_3_r_0_t_5_busy, S5S8SMStore::mpacket_sm_0_i_3_r_0_t_5_cnt, S5S8SMStore::mpacket_sm_0_i_3_r_0_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_3_r_0_t_6_busy, S5S8SMStore::mpacket_sm_0_i_3_r_0_t_6_cnt, S5S8SMStore::mpacket_sm_0_i_3_r_0_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_3_r_0_t_7_busy, S5S8SMStore::mpacket_sm_0_i_3_r_0_t_7_cnt, S5S8SMStore::mpacket_sm_0_i_3_r_0_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_3_r_0_t_8_busy, S5S8SMStore::mpacket_sm_0_i_3_r_0_t_8_cnt, S5S8SMStore::mpacket_sm_0_i_3_r_0_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_3_r_0_t_9_busy, S5S8SMStore::mpacket_sm_0_i_3_r_0_t_9_cnt, S5S8SMStore::mpacket_sm_0_i_3_r_0_t_9, msgObj);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_3_r_0_t_0_busy, S5S8SMStore::mpacket_sm_1_i_3_r_0_t_0_cnt, S5S8SMStore::mpacket_sm_1_i_3_r_0_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_3_r_0_t_1_busy, S5S8SMStore::mpacket_sm_1_i_3_r_0_t_1_cnt, S5S8SMStore::mpacket_sm_1_i_3_r_0_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_3_r_0_t_2_busy, S5S8SMStore::mpacket_sm_1_i_3_r_0_t_2_cnt, S5S8SMStore::mpacket_sm_1_i_3_r_0_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_3_r_0_t_3_busy, S5S8SMStore::mpacket_sm_1_i_3_r_0_t_3_cnt, S5S8SMStore::mpacket_sm_1_i_3_r_0_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_3_r_0_t_4_busy, S5S8SMStore::mpacket_sm_1_i_3_r_0_t_4_cnt, S5S8SMStore::mpacket_sm_1_i_3_r_0_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_3_r_0_t_5_busy, S5S8SMStore::mpacket_sm_1_i_3_r_0_t_5_cnt, S5S8SMStore::mpacket_sm_1_i_3_r_0_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_3_r_0_t_6_busy, S5S8SMStore::mpacket_sm_1_i_3_r_0_t_6_cnt, S5S8SMStore::mpacket_sm_1_i_3_r_0_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_3_r_0_t_7_busy, S5S8SMStore::mpacket_sm_1_i_3_r_0_t_7_cnt, S5S8SMStore::mpacket_sm_1_i_3_r_0_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_3_r_0_t_8_busy, S5S8SMStore::mpacket_sm_1_i_3_r_0_t_8_cnt, S5S8SMStore::mpacket_sm_1_i_3_r_0_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_3_r_0_t_9_busy, S5S8SMStore::mpacket_sm_1_i_3_r_0_t_9_cnt, S5S8SMStore::mpacket_sm_1_i_3_r_0_t_9, msgObj);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_3_r_0_t_0_busy, S5S8SMStore::mpacket_sm_2_i_3_r_0_t_0_cnt, S5S8SMStore::mpacket_sm_2_i_3_r_0_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_3_r_0_t_1_busy, S5S8SMStore::mpacket_sm_2_i_3_r_0_t_1_cnt, S5S8SMStore::mpacket_sm_2_i_3_r_0_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_3_r_0_t_2_busy, S5S8SMStore::mpacket_sm_2_i_3_r_0_t_2_cnt, S5S8SMStore::mpacket_sm_2_i_3_r_0_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_3_r_0_t_3_busy, S5S8SMStore::mpacket_sm_2_i_3_r_0_t_3_cnt, S5S8SMStore::mpacket_sm_2_i_3_r_0_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_3_r_0_t_4_busy, S5S8SMStore::mpacket_sm_2_i_3_r_0_t_4_cnt, S5S8SMStore::mpacket_sm_2_i_3_r_0_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_3_r_0_t_5_busy, S5S8SMStore::mpacket_sm_2_i_3_r_0_t_5_cnt, S5S8SMStore::mpacket_sm_2_i_3_r_0_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_3_r_0_t_6_busy, S5S8SMStore::mpacket_sm_2_i_3_r_0_t_6_cnt, S5S8SMStore::mpacket_sm_2_i_3_r_0_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_3_r_0_t_7_busy, S5S8SMStore::mpacket_sm_2_i_3_r_0_t_7_cnt, S5S8SMStore::mpacket_sm_2_i_3_r_0_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_3_r_0_t_8_busy, S5S8SMStore::mpacket_sm_2_i_3_r_0_t_8_cnt, S5S8SMStore::mpacket_sm_2_i_3_r_0_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_3_r_0_t_9_busy, S5S8SMStore::mpacket_sm_2_i_3_r_0_t_9_cnt, S5S8SMStore::mpacket_sm_2_i_3_r_0_t_9, msgObj);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_3_r_0_t_0_busy, S5S8SMStore::mpacket_sm_3_i_3_r_0_t_0_cnt, S5S8SMStore::mpacket_sm_3_i_3_r_0_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_3_r_0_t_1_busy, S5S8SMStore::mpacket_sm_3_i_3_r_0_t_1_cnt, S5S8SMStore::mpacket_sm_3_i_3_r_0_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_3_r_0_t_2_busy, S5S8SMStore::mpacket_sm_3_i_3_r_0_t_2_cnt, S5S8SMStore::mpacket_sm_3_i_3_r_0_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_3_r_0_t_3_busy, S5S8SMStore::mpacket_sm_3_i_3_r_0_t_3_cnt, S5S8SMStore::mpacket_sm_3_i_3_r_0_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_3_r_0_t_4_busy, S5S8SMStore::mpacket_sm_3_i_3_r_0_t_4_cnt, S5S8SMStore::mpacket_sm_3_i_3_r_0_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_3_r_0_t_5_busy, S5S8SMStore::mpacket_sm_3_i_3_r_0_t_5_cnt, S5S8SMStore::mpacket_sm_3_i_3_r_0_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_3_r_0_t_6_busy, S5S8SMStore::mpacket_sm_3_i_3_r_0_t_6_cnt, S5S8SMStore::mpacket_sm_3_i_3_r_0_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_3_r_0_t_7_busy, S5S8SMStore::mpacket_sm_3_i_3_r_0_t_7_cnt, S5S8SMStore::mpacket_sm_3_i_3_r_0_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_3_r_0_t_8_busy, S5S8SMStore::mpacket_sm_3_i_3_r_0_t_8_cnt, S5S8SMStore::mpacket_sm_3_i_3_r_0_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_3_r_0_t_9_busy, S5S8SMStore::mpacket_sm_3_i_3_r_0_t_9_cnt, S5S8SMStore::mpacket_sm_3_i_3_r_0_t_9, msgObj);
				break;
			}
			break;
	}
}

VOID S5S8MessageBroker::pushToQueue_i_3_r_1(MPacket *msgObj, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_3_r_1_t_0_busy, S5S8SMStore::mpacket_sm_0_i_3_r_1_t_0_cnt, S5S8SMStore::mpacket_sm_0_i_3_r_1_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_3_r_1_t_1_busy, S5S8SMStore::mpacket_sm_0_i_3_r_1_t_1_cnt, S5S8SMStore::mpacket_sm_0_i_3_r_1_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_3_r_1_t_2_busy, S5S8SMStore::mpacket_sm_0_i_3_r_1_t_2_cnt, S5S8SMStore::mpacket_sm_0_i_3_r_1_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_3_r_1_t_3_busy, S5S8SMStore::mpacket_sm_0_i_3_r_1_t_3_cnt, S5S8SMStore::mpacket_sm_0_i_3_r_1_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_3_r_1_t_4_busy, S5S8SMStore::mpacket_sm_0_i_3_r_1_t_4_cnt, S5S8SMStore::mpacket_sm_0_i_3_r_1_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_3_r_1_t_5_busy, S5S8SMStore::mpacket_sm_0_i_3_r_1_t_5_cnt, S5S8SMStore::mpacket_sm_0_i_3_r_1_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_3_r_1_t_6_busy, S5S8SMStore::mpacket_sm_0_i_3_r_1_t_6_cnt, S5S8SMStore::mpacket_sm_0_i_3_r_1_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_3_r_1_t_7_busy, S5S8SMStore::mpacket_sm_0_i_3_r_1_t_7_cnt, S5S8SMStore::mpacket_sm_0_i_3_r_1_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_3_r_1_t_8_busy, S5S8SMStore::mpacket_sm_0_i_3_r_1_t_8_cnt, S5S8SMStore::mpacket_sm_0_i_3_r_1_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_3_r_1_t_9_busy, S5S8SMStore::mpacket_sm_0_i_3_r_1_t_9_cnt, S5S8SMStore::mpacket_sm_0_i_3_r_1_t_9, msgObj);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_3_r_1_t_0_busy, S5S8SMStore::mpacket_sm_1_i_3_r_1_t_0_cnt, S5S8SMStore::mpacket_sm_1_i_3_r_1_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_3_r_1_t_1_busy, S5S8SMStore::mpacket_sm_1_i_3_r_1_t_1_cnt, S5S8SMStore::mpacket_sm_1_i_3_r_1_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_3_r_1_t_2_busy, S5S8SMStore::mpacket_sm_1_i_3_r_1_t_2_cnt, S5S8SMStore::mpacket_sm_1_i_3_r_1_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_3_r_1_t_3_busy, S5S8SMStore::mpacket_sm_1_i_3_r_1_t_3_cnt, S5S8SMStore::mpacket_sm_1_i_3_r_1_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_3_r_1_t_4_busy, S5S8SMStore::mpacket_sm_1_i_3_r_1_t_4_cnt, S5S8SMStore::mpacket_sm_1_i_3_r_1_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_3_r_1_t_5_busy, S5S8SMStore::mpacket_sm_1_i_3_r_1_t_5_cnt, S5S8SMStore::mpacket_sm_1_i_3_r_1_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_3_r_1_t_6_busy, S5S8SMStore::mpacket_sm_1_i_3_r_1_t_6_cnt, S5S8SMStore::mpacket_sm_1_i_3_r_1_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_3_r_1_t_7_busy, S5S8SMStore::mpacket_sm_1_i_3_r_1_t_7_cnt, S5S8SMStore::mpacket_sm_1_i_3_r_1_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_3_r_1_t_8_busy, S5S8SMStore::mpacket_sm_1_i_3_r_1_t_8_cnt, S5S8SMStore::mpacket_sm_1_i_3_r_1_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_3_r_1_t_9_busy, S5S8SMStore::mpacket_sm_1_i_3_r_1_t_9_cnt, S5S8SMStore::mpacket_sm_1_i_3_r_1_t_9, msgObj);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_3_r_1_t_0_busy, S5S8SMStore::mpacket_sm_2_i_3_r_1_t_0_cnt, S5S8SMStore::mpacket_sm_2_i_3_r_1_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_3_r_1_t_1_busy, S5S8SMStore::mpacket_sm_2_i_3_r_1_t_1_cnt, S5S8SMStore::mpacket_sm_2_i_3_r_1_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_3_r_1_t_2_busy, S5S8SMStore::mpacket_sm_2_i_3_r_1_t_2_cnt, S5S8SMStore::mpacket_sm_2_i_3_r_1_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_3_r_1_t_3_busy, S5S8SMStore::mpacket_sm_2_i_3_r_1_t_3_cnt, S5S8SMStore::mpacket_sm_2_i_3_r_1_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_3_r_1_t_4_busy, S5S8SMStore::mpacket_sm_2_i_3_r_1_t_4_cnt, S5S8SMStore::mpacket_sm_2_i_3_r_1_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_3_r_1_t_5_busy, S5S8SMStore::mpacket_sm_2_i_3_r_1_t_5_cnt, S5S8SMStore::mpacket_sm_2_i_3_r_1_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_3_r_1_t_6_busy, S5S8SMStore::mpacket_sm_2_i_3_r_1_t_6_cnt, S5S8SMStore::mpacket_sm_2_i_3_r_1_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_3_r_1_t_7_busy, S5S8SMStore::mpacket_sm_2_i_3_r_1_t_7_cnt, S5S8SMStore::mpacket_sm_2_i_3_r_1_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_3_r_1_t_8_busy, S5S8SMStore::mpacket_sm_2_i_3_r_1_t_8_cnt, S5S8SMStore::mpacket_sm_2_i_3_r_1_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_3_r_1_t_9_busy, S5S8SMStore::mpacket_sm_2_i_3_r_1_t_9_cnt, S5S8SMStore::mpacket_sm_2_i_3_r_1_t_9, msgObj);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_3_r_1_t_0_busy, S5S8SMStore::mpacket_sm_3_i_3_r_1_t_0_cnt, S5S8SMStore::mpacket_sm_3_i_3_r_1_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_3_r_1_t_1_busy, S5S8SMStore::mpacket_sm_3_i_3_r_1_t_1_cnt, S5S8SMStore::mpacket_sm_3_i_3_r_1_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_3_r_1_t_2_busy, S5S8SMStore::mpacket_sm_3_i_3_r_1_t_2_cnt, S5S8SMStore::mpacket_sm_3_i_3_r_1_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_3_r_1_t_3_busy, S5S8SMStore::mpacket_sm_3_i_3_r_1_t_3_cnt, S5S8SMStore::mpacket_sm_3_i_3_r_1_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_3_r_1_t_4_busy, S5S8SMStore::mpacket_sm_3_i_3_r_1_t_4_cnt, S5S8SMStore::mpacket_sm_3_i_3_r_1_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_3_r_1_t_5_busy, S5S8SMStore::mpacket_sm_3_i_3_r_1_t_5_cnt, S5S8SMStore::mpacket_sm_3_i_3_r_1_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_3_r_1_t_6_busy, S5S8SMStore::mpacket_sm_3_i_3_r_1_t_6_cnt, S5S8SMStore::mpacket_sm_3_i_3_r_1_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_3_r_1_t_7_busy, S5S8SMStore::mpacket_sm_3_i_3_r_1_t_7_cnt, S5S8SMStore::mpacket_sm_3_i_3_r_1_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_3_r_1_t_8_busy, S5S8SMStore::mpacket_sm_3_i_3_r_1_t_8_cnt, S5S8SMStore::mpacket_sm_3_i_3_r_1_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_3_r_1_t_9_busy, S5S8SMStore::mpacket_sm_3_i_3_r_1_t_9_cnt, S5S8SMStore::mpacket_sm_3_i_3_r_1_t_9, msgObj);
				break;
			}
			break;
	}
}

VOID S5S8MessageBroker::pushToQueue_i_3_r_2(MPacket *msgObj, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_3_r_2_t_0_busy, S5S8SMStore::mpacket_sm_0_i_3_r_2_t_0_cnt, S5S8SMStore::mpacket_sm_0_i_3_r_2_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_3_r_2_t_1_busy, S5S8SMStore::mpacket_sm_0_i_3_r_2_t_1_cnt, S5S8SMStore::mpacket_sm_0_i_3_r_2_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_3_r_2_t_2_busy, S5S8SMStore::mpacket_sm_0_i_3_r_2_t_2_cnt, S5S8SMStore::mpacket_sm_0_i_3_r_2_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_3_r_2_t_3_busy, S5S8SMStore::mpacket_sm_0_i_3_r_2_t_3_cnt, S5S8SMStore::mpacket_sm_0_i_3_r_2_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_3_r_2_t_4_busy, S5S8SMStore::mpacket_sm_0_i_3_r_2_t_4_cnt, S5S8SMStore::mpacket_sm_0_i_3_r_2_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_3_r_2_t_5_busy, S5S8SMStore::mpacket_sm_0_i_3_r_2_t_5_cnt, S5S8SMStore::mpacket_sm_0_i_3_r_2_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_3_r_2_t_6_busy, S5S8SMStore::mpacket_sm_0_i_3_r_2_t_6_cnt, S5S8SMStore::mpacket_sm_0_i_3_r_2_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_3_r_2_t_7_busy, S5S8SMStore::mpacket_sm_0_i_3_r_2_t_7_cnt, S5S8SMStore::mpacket_sm_0_i_3_r_2_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_3_r_2_t_8_busy, S5S8SMStore::mpacket_sm_0_i_3_r_2_t_8_cnt, S5S8SMStore::mpacket_sm_0_i_3_r_2_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_3_r_2_t_9_busy, S5S8SMStore::mpacket_sm_0_i_3_r_2_t_9_cnt, S5S8SMStore::mpacket_sm_0_i_3_r_2_t_9, msgObj);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_3_r_2_t_0_busy, S5S8SMStore::mpacket_sm_1_i_3_r_2_t_0_cnt, S5S8SMStore::mpacket_sm_1_i_3_r_2_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_3_r_2_t_1_busy, S5S8SMStore::mpacket_sm_1_i_3_r_2_t_1_cnt, S5S8SMStore::mpacket_sm_1_i_3_r_2_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_3_r_2_t_2_busy, S5S8SMStore::mpacket_sm_1_i_3_r_2_t_2_cnt, S5S8SMStore::mpacket_sm_1_i_3_r_2_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_3_r_2_t_3_busy, S5S8SMStore::mpacket_sm_1_i_3_r_2_t_3_cnt, S5S8SMStore::mpacket_sm_1_i_3_r_2_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_3_r_2_t_4_busy, S5S8SMStore::mpacket_sm_1_i_3_r_2_t_4_cnt, S5S8SMStore::mpacket_sm_1_i_3_r_2_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_3_r_2_t_5_busy, S5S8SMStore::mpacket_sm_1_i_3_r_2_t_5_cnt, S5S8SMStore::mpacket_sm_1_i_3_r_2_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_3_r_2_t_6_busy, S5S8SMStore::mpacket_sm_1_i_3_r_2_t_6_cnt, S5S8SMStore::mpacket_sm_1_i_3_r_2_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_3_r_2_t_7_busy, S5S8SMStore::mpacket_sm_1_i_3_r_2_t_7_cnt, S5S8SMStore::mpacket_sm_1_i_3_r_2_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_3_r_2_t_8_busy, S5S8SMStore::mpacket_sm_1_i_3_r_2_t_8_cnt, S5S8SMStore::mpacket_sm_1_i_3_r_2_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_3_r_2_t_9_busy, S5S8SMStore::mpacket_sm_1_i_3_r_2_t_9_cnt, S5S8SMStore::mpacket_sm_1_i_3_r_2_t_9, msgObj);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_3_r_2_t_0_busy, S5S8SMStore::mpacket_sm_2_i_3_r_2_t_0_cnt, S5S8SMStore::mpacket_sm_2_i_3_r_2_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_3_r_2_t_1_busy, S5S8SMStore::mpacket_sm_2_i_3_r_2_t_1_cnt, S5S8SMStore::mpacket_sm_2_i_3_r_2_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_3_r_2_t_2_busy, S5S8SMStore::mpacket_sm_2_i_3_r_2_t_2_cnt, S5S8SMStore::mpacket_sm_2_i_3_r_2_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_3_r_2_t_3_busy, S5S8SMStore::mpacket_sm_2_i_3_r_2_t_3_cnt, S5S8SMStore::mpacket_sm_2_i_3_r_2_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_3_r_2_t_4_busy, S5S8SMStore::mpacket_sm_2_i_3_r_2_t_4_cnt, S5S8SMStore::mpacket_sm_2_i_3_r_2_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_3_r_2_t_5_busy, S5S8SMStore::mpacket_sm_2_i_3_r_2_t_5_cnt, S5S8SMStore::mpacket_sm_2_i_3_r_2_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_3_r_2_t_6_busy, S5S8SMStore::mpacket_sm_2_i_3_r_2_t_6_cnt, S5S8SMStore::mpacket_sm_2_i_3_r_2_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_3_r_2_t_7_busy, S5S8SMStore::mpacket_sm_2_i_3_r_2_t_7_cnt, S5S8SMStore::mpacket_sm_2_i_3_r_2_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_3_r_2_t_8_busy, S5S8SMStore::mpacket_sm_2_i_3_r_2_t_8_cnt, S5S8SMStore::mpacket_sm_2_i_3_r_2_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_3_r_2_t_9_busy, S5S8SMStore::mpacket_sm_2_i_3_r_2_t_9_cnt, S5S8SMStore::mpacket_sm_2_i_3_r_2_t_9, msgObj);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_3_r_2_t_0_busy, S5S8SMStore::mpacket_sm_3_i_3_r_2_t_0_cnt, S5S8SMStore::mpacket_sm_3_i_3_r_2_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_3_r_2_t_1_busy, S5S8SMStore::mpacket_sm_3_i_3_r_2_t_1_cnt, S5S8SMStore::mpacket_sm_3_i_3_r_2_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_3_r_2_t_2_busy, S5S8SMStore::mpacket_sm_3_i_3_r_2_t_2_cnt, S5S8SMStore::mpacket_sm_3_i_3_r_2_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_3_r_2_t_3_busy, S5S8SMStore::mpacket_sm_3_i_3_r_2_t_3_cnt, S5S8SMStore::mpacket_sm_3_i_3_r_2_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_3_r_2_t_4_busy, S5S8SMStore::mpacket_sm_3_i_3_r_2_t_4_cnt, S5S8SMStore::mpacket_sm_3_i_3_r_2_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_3_r_2_t_5_busy, S5S8SMStore::mpacket_sm_3_i_3_r_2_t_5_cnt, S5S8SMStore::mpacket_sm_3_i_3_r_2_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_3_r_2_t_6_busy, S5S8SMStore::mpacket_sm_3_i_3_r_2_t_6_cnt, S5S8SMStore::mpacket_sm_3_i_3_r_2_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_3_r_2_t_7_busy, S5S8SMStore::mpacket_sm_3_i_3_r_2_t_7_cnt, S5S8SMStore::mpacket_sm_3_i_3_r_2_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_3_r_2_t_8_busy, S5S8SMStore::mpacket_sm_3_i_3_r_2_t_8_cnt, S5S8SMStore::mpacket_sm_3_i_3_r_2_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_3_r_2_t_9_busy, S5S8SMStore::mpacket_sm_3_i_3_r_2_t_9_cnt, S5S8SMStore::mpacket_sm_3_i_3_r_2_t_9, msgObj);
				break;
			}
			break;
	}
}

VOID S5S8MessageBroker::pushToQueue_i_3_r_3(MPacket *msgObj, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_3_r_3_t_0_busy, S5S8SMStore::mpacket_sm_0_i_3_r_3_t_0_cnt, S5S8SMStore::mpacket_sm_0_i_3_r_3_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_3_r_3_t_1_busy, S5S8SMStore::mpacket_sm_0_i_3_r_3_t_1_cnt, S5S8SMStore::mpacket_sm_0_i_3_r_3_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_3_r_3_t_2_busy, S5S8SMStore::mpacket_sm_0_i_3_r_3_t_2_cnt, S5S8SMStore::mpacket_sm_0_i_3_r_3_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_3_r_3_t_3_busy, S5S8SMStore::mpacket_sm_0_i_3_r_3_t_3_cnt, S5S8SMStore::mpacket_sm_0_i_3_r_3_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_3_r_3_t_4_busy, S5S8SMStore::mpacket_sm_0_i_3_r_3_t_4_cnt, S5S8SMStore::mpacket_sm_0_i_3_r_3_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_3_r_3_t_5_busy, S5S8SMStore::mpacket_sm_0_i_3_r_3_t_5_cnt, S5S8SMStore::mpacket_sm_0_i_3_r_3_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_3_r_3_t_6_busy, S5S8SMStore::mpacket_sm_0_i_3_r_3_t_6_cnt, S5S8SMStore::mpacket_sm_0_i_3_r_3_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_3_r_3_t_7_busy, S5S8SMStore::mpacket_sm_0_i_3_r_3_t_7_cnt, S5S8SMStore::mpacket_sm_0_i_3_r_3_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_3_r_3_t_8_busy, S5S8SMStore::mpacket_sm_0_i_3_r_3_t_8_cnt, S5S8SMStore::mpacket_sm_0_i_3_r_3_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_3_r_3_t_9_busy, S5S8SMStore::mpacket_sm_0_i_3_r_3_t_9_cnt, S5S8SMStore::mpacket_sm_0_i_3_r_3_t_9, msgObj);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_3_r_3_t_0_busy, S5S8SMStore::mpacket_sm_1_i_3_r_3_t_0_cnt, S5S8SMStore::mpacket_sm_1_i_3_r_3_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_3_r_3_t_1_busy, S5S8SMStore::mpacket_sm_1_i_3_r_3_t_1_cnt, S5S8SMStore::mpacket_sm_1_i_3_r_3_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_3_r_3_t_2_busy, S5S8SMStore::mpacket_sm_1_i_3_r_3_t_2_cnt, S5S8SMStore::mpacket_sm_1_i_3_r_3_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_3_r_3_t_3_busy, S5S8SMStore::mpacket_sm_1_i_3_r_3_t_3_cnt, S5S8SMStore::mpacket_sm_1_i_3_r_3_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_3_r_3_t_4_busy, S5S8SMStore::mpacket_sm_1_i_3_r_3_t_4_cnt, S5S8SMStore::mpacket_sm_1_i_3_r_3_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_3_r_3_t_5_busy, S5S8SMStore::mpacket_sm_1_i_3_r_3_t_5_cnt, S5S8SMStore::mpacket_sm_1_i_3_r_3_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_3_r_3_t_6_busy, S5S8SMStore::mpacket_sm_1_i_3_r_3_t_6_cnt, S5S8SMStore::mpacket_sm_1_i_3_r_3_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_3_r_3_t_7_busy, S5S8SMStore::mpacket_sm_1_i_3_r_3_t_7_cnt, S5S8SMStore::mpacket_sm_1_i_3_r_3_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_3_r_3_t_8_busy, S5S8SMStore::mpacket_sm_1_i_3_r_3_t_8_cnt, S5S8SMStore::mpacket_sm_1_i_3_r_3_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_3_r_3_t_9_busy, S5S8SMStore::mpacket_sm_1_i_3_r_3_t_9_cnt, S5S8SMStore::mpacket_sm_1_i_3_r_3_t_9, msgObj);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_3_r_3_t_0_busy, S5S8SMStore::mpacket_sm_2_i_3_r_3_t_0_cnt, S5S8SMStore::mpacket_sm_2_i_3_r_3_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_3_r_3_t_1_busy, S5S8SMStore::mpacket_sm_2_i_3_r_3_t_1_cnt, S5S8SMStore::mpacket_sm_2_i_3_r_3_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_3_r_3_t_2_busy, S5S8SMStore::mpacket_sm_2_i_3_r_3_t_2_cnt, S5S8SMStore::mpacket_sm_2_i_3_r_3_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_3_r_3_t_3_busy, S5S8SMStore::mpacket_sm_2_i_3_r_3_t_3_cnt, S5S8SMStore::mpacket_sm_2_i_3_r_3_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_3_r_3_t_4_busy, S5S8SMStore::mpacket_sm_2_i_3_r_3_t_4_cnt, S5S8SMStore::mpacket_sm_2_i_3_r_3_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_3_r_3_t_5_busy, S5S8SMStore::mpacket_sm_2_i_3_r_3_t_5_cnt, S5S8SMStore::mpacket_sm_2_i_3_r_3_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_3_r_3_t_6_busy, S5S8SMStore::mpacket_sm_2_i_3_r_3_t_6_cnt, S5S8SMStore::mpacket_sm_2_i_3_r_3_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_3_r_3_t_7_busy, S5S8SMStore::mpacket_sm_2_i_3_r_3_t_7_cnt, S5S8SMStore::mpacket_sm_2_i_3_r_3_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_3_r_3_t_8_busy, S5S8SMStore::mpacket_sm_2_i_3_r_3_t_8_cnt, S5S8SMStore::mpacket_sm_2_i_3_r_3_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_3_r_3_t_9_busy, S5S8SMStore::mpacket_sm_2_i_3_r_3_t_9_cnt, S5S8SMStore::mpacket_sm_2_i_3_r_3_t_9, msgObj);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_3_r_3_t_0_busy, S5S8SMStore::mpacket_sm_3_i_3_r_3_t_0_cnt, S5S8SMStore::mpacket_sm_3_i_3_r_3_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_3_r_3_t_1_busy, S5S8SMStore::mpacket_sm_3_i_3_r_3_t_1_cnt, S5S8SMStore::mpacket_sm_3_i_3_r_3_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_3_r_3_t_2_busy, S5S8SMStore::mpacket_sm_3_i_3_r_3_t_2_cnt, S5S8SMStore::mpacket_sm_3_i_3_r_3_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_3_r_3_t_3_busy, S5S8SMStore::mpacket_sm_3_i_3_r_3_t_3_cnt, S5S8SMStore::mpacket_sm_3_i_3_r_3_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_3_r_3_t_4_busy, S5S8SMStore::mpacket_sm_3_i_3_r_3_t_4_cnt, S5S8SMStore::mpacket_sm_3_i_3_r_3_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_3_r_3_t_5_busy, S5S8SMStore::mpacket_sm_3_i_3_r_3_t_5_cnt, S5S8SMStore::mpacket_sm_3_i_3_r_3_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_3_r_3_t_6_busy, S5S8SMStore::mpacket_sm_3_i_3_r_3_t_6_cnt, S5S8SMStore::mpacket_sm_3_i_3_r_3_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_3_r_3_t_7_busy, S5S8SMStore::mpacket_sm_3_i_3_r_3_t_7_cnt, S5S8SMStore::mpacket_sm_3_i_3_r_3_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_3_r_3_t_8_busy, S5S8SMStore::mpacket_sm_3_i_3_r_3_t_8_cnt, S5S8SMStore::mpacket_sm_3_i_3_r_3_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_3_r_3_t_9_busy, S5S8SMStore::mpacket_sm_3_i_3_r_3_t_9_cnt, S5S8SMStore::mpacket_sm_3_i_3_r_3_t_9, msgObj);
				break;
			}
			break;
	}
}

VOID S5S8MessageBroker::pushToQueue_i_3_r_4(MPacket *msgObj, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_3_r_4_t_0_busy, S5S8SMStore::mpacket_sm_0_i_3_r_4_t_0_cnt, S5S8SMStore::mpacket_sm_0_i_3_r_4_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_3_r_4_t_1_busy, S5S8SMStore::mpacket_sm_0_i_3_r_4_t_1_cnt, S5S8SMStore::mpacket_sm_0_i_3_r_4_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_3_r_4_t_2_busy, S5S8SMStore::mpacket_sm_0_i_3_r_4_t_2_cnt, S5S8SMStore::mpacket_sm_0_i_3_r_4_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_3_r_4_t_3_busy, S5S8SMStore::mpacket_sm_0_i_3_r_4_t_3_cnt, S5S8SMStore::mpacket_sm_0_i_3_r_4_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_3_r_4_t_4_busy, S5S8SMStore::mpacket_sm_0_i_3_r_4_t_4_cnt, S5S8SMStore::mpacket_sm_0_i_3_r_4_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_3_r_4_t_5_busy, S5S8SMStore::mpacket_sm_0_i_3_r_4_t_5_cnt, S5S8SMStore::mpacket_sm_0_i_3_r_4_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_3_r_4_t_6_busy, S5S8SMStore::mpacket_sm_0_i_3_r_4_t_6_cnt, S5S8SMStore::mpacket_sm_0_i_3_r_4_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_3_r_4_t_7_busy, S5S8SMStore::mpacket_sm_0_i_3_r_4_t_7_cnt, S5S8SMStore::mpacket_sm_0_i_3_r_4_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_3_r_4_t_8_busy, S5S8SMStore::mpacket_sm_0_i_3_r_4_t_8_cnt, S5S8SMStore::mpacket_sm_0_i_3_r_4_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_3_r_4_t_9_busy, S5S8SMStore::mpacket_sm_0_i_3_r_4_t_9_cnt, S5S8SMStore::mpacket_sm_0_i_3_r_4_t_9, msgObj);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_3_r_4_t_0_busy, S5S8SMStore::mpacket_sm_1_i_3_r_4_t_0_cnt, S5S8SMStore::mpacket_sm_1_i_3_r_4_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_3_r_4_t_1_busy, S5S8SMStore::mpacket_sm_1_i_3_r_4_t_1_cnt, S5S8SMStore::mpacket_sm_1_i_3_r_4_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_3_r_4_t_2_busy, S5S8SMStore::mpacket_sm_1_i_3_r_4_t_2_cnt, S5S8SMStore::mpacket_sm_1_i_3_r_4_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_3_r_4_t_3_busy, S5S8SMStore::mpacket_sm_1_i_3_r_4_t_3_cnt, S5S8SMStore::mpacket_sm_1_i_3_r_4_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_3_r_4_t_4_busy, S5S8SMStore::mpacket_sm_1_i_3_r_4_t_4_cnt, S5S8SMStore::mpacket_sm_1_i_3_r_4_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_3_r_4_t_5_busy, S5S8SMStore::mpacket_sm_1_i_3_r_4_t_5_cnt, S5S8SMStore::mpacket_sm_1_i_3_r_4_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_3_r_4_t_6_busy, S5S8SMStore::mpacket_sm_1_i_3_r_4_t_6_cnt, S5S8SMStore::mpacket_sm_1_i_3_r_4_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_3_r_4_t_7_busy, S5S8SMStore::mpacket_sm_1_i_3_r_4_t_7_cnt, S5S8SMStore::mpacket_sm_1_i_3_r_4_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_3_r_4_t_8_busy, S5S8SMStore::mpacket_sm_1_i_3_r_4_t_8_cnt, S5S8SMStore::mpacket_sm_1_i_3_r_4_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_3_r_4_t_9_busy, S5S8SMStore::mpacket_sm_1_i_3_r_4_t_9_cnt, S5S8SMStore::mpacket_sm_1_i_3_r_4_t_9, msgObj);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_3_r_4_t_0_busy, S5S8SMStore::mpacket_sm_2_i_3_r_4_t_0_cnt, S5S8SMStore::mpacket_sm_2_i_3_r_4_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_3_r_4_t_1_busy, S5S8SMStore::mpacket_sm_2_i_3_r_4_t_1_cnt, S5S8SMStore::mpacket_sm_2_i_3_r_4_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_3_r_4_t_2_busy, S5S8SMStore::mpacket_sm_2_i_3_r_4_t_2_cnt, S5S8SMStore::mpacket_sm_2_i_3_r_4_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_3_r_4_t_3_busy, S5S8SMStore::mpacket_sm_2_i_3_r_4_t_3_cnt, S5S8SMStore::mpacket_sm_2_i_3_r_4_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_3_r_4_t_4_busy, S5S8SMStore::mpacket_sm_2_i_3_r_4_t_4_cnt, S5S8SMStore::mpacket_sm_2_i_3_r_4_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_3_r_4_t_5_busy, S5S8SMStore::mpacket_sm_2_i_3_r_4_t_5_cnt, S5S8SMStore::mpacket_sm_2_i_3_r_4_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_3_r_4_t_6_busy, S5S8SMStore::mpacket_sm_2_i_3_r_4_t_6_cnt, S5S8SMStore::mpacket_sm_2_i_3_r_4_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_3_r_4_t_7_busy, S5S8SMStore::mpacket_sm_2_i_3_r_4_t_7_cnt, S5S8SMStore::mpacket_sm_2_i_3_r_4_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_3_r_4_t_8_busy, S5S8SMStore::mpacket_sm_2_i_3_r_4_t_8_cnt, S5S8SMStore::mpacket_sm_2_i_3_r_4_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_3_r_4_t_9_busy, S5S8SMStore::mpacket_sm_2_i_3_r_4_t_9_cnt, S5S8SMStore::mpacket_sm_2_i_3_r_4_t_9, msgObj);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_3_r_4_t_0_busy, S5S8SMStore::mpacket_sm_3_i_3_r_4_t_0_cnt, S5S8SMStore::mpacket_sm_3_i_3_r_4_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_3_r_4_t_1_busy, S5S8SMStore::mpacket_sm_3_i_3_r_4_t_1_cnt, S5S8SMStore::mpacket_sm_3_i_3_r_4_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_3_r_4_t_2_busy, S5S8SMStore::mpacket_sm_3_i_3_r_4_t_2_cnt, S5S8SMStore::mpacket_sm_3_i_3_r_4_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_3_r_4_t_3_busy, S5S8SMStore::mpacket_sm_3_i_3_r_4_t_3_cnt, S5S8SMStore::mpacket_sm_3_i_3_r_4_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_3_r_4_t_4_busy, S5S8SMStore::mpacket_sm_3_i_3_r_4_t_4_cnt, S5S8SMStore::mpacket_sm_3_i_3_r_4_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_3_r_4_t_5_busy, S5S8SMStore::mpacket_sm_3_i_3_r_4_t_5_cnt, S5S8SMStore::mpacket_sm_3_i_3_r_4_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_3_r_4_t_6_busy, S5S8SMStore::mpacket_sm_3_i_3_r_4_t_6_cnt, S5S8SMStore::mpacket_sm_3_i_3_r_4_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_3_r_4_t_7_busy, S5S8SMStore::mpacket_sm_3_i_3_r_4_t_7_cnt, S5S8SMStore::mpacket_sm_3_i_3_r_4_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_3_r_4_t_8_busy, S5S8SMStore::mpacket_sm_3_i_3_r_4_t_8_cnt, S5S8SMStore::mpacket_sm_3_i_3_r_4_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_3_r_4_t_9_busy, S5S8SMStore::mpacket_sm_3_i_3_r_4_t_9_cnt, S5S8SMStore::mpacket_sm_3_i_3_r_4_t_9, msgObj);
				break;
			}
			break;
	}
}

VOID S5S8MessageBroker::pushToQueue_i_3_r_5(MPacket *msgObj, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_3_r_5_t_0_busy, S5S8SMStore::mpacket_sm_0_i_3_r_5_t_0_cnt, S5S8SMStore::mpacket_sm_0_i_3_r_5_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_3_r_5_t_1_busy, S5S8SMStore::mpacket_sm_0_i_3_r_5_t_1_cnt, S5S8SMStore::mpacket_sm_0_i_3_r_5_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_3_r_5_t_2_busy, S5S8SMStore::mpacket_sm_0_i_3_r_5_t_2_cnt, S5S8SMStore::mpacket_sm_0_i_3_r_5_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_3_r_5_t_3_busy, S5S8SMStore::mpacket_sm_0_i_3_r_5_t_3_cnt, S5S8SMStore::mpacket_sm_0_i_3_r_5_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_3_r_5_t_4_busy, S5S8SMStore::mpacket_sm_0_i_3_r_5_t_4_cnt, S5S8SMStore::mpacket_sm_0_i_3_r_5_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_3_r_5_t_5_busy, S5S8SMStore::mpacket_sm_0_i_3_r_5_t_5_cnt, S5S8SMStore::mpacket_sm_0_i_3_r_5_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_3_r_5_t_6_busy, S5S8SMStore::mpacket_sm_0_i_3_r_5_t_6_cnt, S5S8SMStore::mpacket_sm_0_i_3_r_5_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_3_r_5_t_7_busy, S5S8SMStore::mpacket_sm_0_i_3_r_5_t_7_cnt, S5S8SMStore::mpacket_sm_0_i_3_r_5_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_3_r_5_t_8_busy, S5S8SMStore::mpacket_sm_0_i_3_r_5_t_8_cnt, S5S8SMStore::mpacket_sm_0_i_3_r_5_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_3_r_5_t_9_busy, S5S8SMStore::mpacket_sm_0_i_3_r_5_t_9_cnt, S5S8SMStore::mpacket_sm_0_i_3_r_5_t_9, msgObj);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_3_r_5_t_0_busy, S5S8SMStore::mpacket_sm_1_i_3_r_5_t_0_cnt, S5S8SMStore::mpacket_sm_1_i_3_r_5_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_3_r_5_t_1_busy, S5S8SMStore::mpacket_sm_1_i_3_r_5_t_1_cnt, S5S8SMStore::mpacket_sm_1_i_3_r_5_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_3_r_5_t_2_busy, S5S8SMStore::mpacket_sm_1_i_3_r_5_t_2_cnt, S5S8SMStore::mpacket_sm_1_i_3_r_5_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_3_r_5_t_3_busy, S5S8SMStore::mpacket_sm_1_i_3_r_5_t_3_cnt, S5S8SMStore::mpacket_sm_1_i_3_r_5_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_3_r_5_t_4_busy, S5S8SMStore::mpacket_sm_1_i_3_r_5_t_4_cnt, S5S8SMStore::mpacket_sm_1_i_3_r_5_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_3_r_5_t_5_busy, S5S8SMStore::mpacket_sm_1_i_3_r_5_t_5_cnt, S5S8SMStore::mpacket_sm_1_i_3_r_5_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_3_r_5_t_6_busy, S5S8SMStore::mpacket_sm_1_i_3_r_5_t_6_cnt, S5S8SMStore::mpacket_sm_1_i_3_r_5_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_3_r_5_t_7_busy, S5S8SMStore::mpacket_sm_1_i_3_r_5_t_7_cnt, S5S8SMStore::mpacket_sm_1_i_3_r_5_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_3_r_5_t_8_busy, S5S8SMStore::mpacket_sm_1_i_3_r_5_t_8_cnt, S5S8SMStore::mpacket_sm_1_i_3_r_5_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_3_r_5_t_9_busy, S5S8SMStore::mpacket_sm_1_i_3_r_5_t_9_cnt, S5S8SMStore::mpacket_sm_1_i_3_r_5_t_9, msgObj);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_3_r_5_t_0_busy, S5S8SMStore::mpacket_sm_2_i_3_r_5_t_0_cnt, S5S8SMStore::mpacket_sm_2_i_3_r_5_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_3_r_5_t_1_busy, S5S8SMStore::mpacket_sm_2_i_3_r_5_t_1_cnt, S5S8SMStore::mpacket_sm_2_i_3_r_5_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_3_r_5_t_2_busy, S5S8SMStore::mpacket_sm_2_i_3_r_5_t_2_cnt, S5S8SMStore::mpacket_sm_2_i_3_r_5_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_3_r_5_t_3_busy, S5S8SMStore::mpacket_sm_2_i_3_r_5_t_3_cnt, S5S8SMStore::mpacket_sm_2_i_3_r_5_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_3_r_5_t_4_busy, S5S8SMStore::mpacket_sm_2_i_3_r_5_t_4_cnt, S5S8SMStore::mpacket_sm_2_i_3_r_5_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_3_r_5_t_5_busy, S5S8SMStore::mpacket_sm_2_i_3_r_5_t_5_cnt, S5S8SMStore::mpacket_sm_2_i_3_r_5_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_3_r_5_t_6_busy, S5S8SMStore::mpacket_sm_2_i_3_r_5_t_6_cnt, S5S8SMStore::mpacket_sm_2_i_3_r_5_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_3_r_5_t_7_busy, S5S8SMStore::mpacket_sm_2_i_3_r_5_t_7_cnt, S5S8SMStore::mpacket_sm_2_i_3_r_5_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_3_r_5_t_8_busy, S5S8SMStore::mpacket_sm_2_i_3_r_5_t_8_cnt, S5S8SMStore::mpacket_sm_2_i_3_r_5_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_3_r_5_t_9_busy, S5S8SMStore::mpacket_sm_2_i_3_r_5_t_9_cnt, S5S8SMStore::mpacket_sm_2_i_3_r_5_t_9, msgObj);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_3_r_5_t_0_busy, S5S8SMStore::mpacket_sm_3_i_3_r_5_t_0_cnt, S5S8SMStore::mpacket_sm_3_i_3_r_5_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_3_r_5_t_1_busy, S5S8SMStore::mpacket_sm_3_i_3_r_5_t_1_cnt, S5S8SMStore::mpacket_sm_3_i_3_r_5_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_3_r_5_t_2_busy, S5S8SMStore::mpacket_sm_3_i_3_r_5_t_2_cnt, S5S8SMStore::mpacket_sm_3_i_3_r_5_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_3_r_5_t_3_busy, S5S8SMStore::mpacket_sm_3_i_3_r_5_t_3_cnt, S5S8SMStore::mpacket_sm_3_i_3_r_5_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_3_r_5_t_4_busy, S5S8SMStore::mpacket_sm_3_i_3_r_5_t_4_cnt, S5S8SMStore::mpacket_sm_3_i_3_r_5_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_3_r_5_t_5_busy, S5S8SMStore::mpacket_sm_3_i_3_r_5_t_5_cnt, S5S8SMStore::mpacket_sm_3_i_3_r_5_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_3_r_5_t_6_busy, S5S8SMStore::mpacket_sm_3_i_3_r_5_t_6_cnt, S5S8SMStore::mpacket_sm_3_i_3_r_5_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_3_r_5_t_7_busy, S5S8SMStore::mpacket_sm_3_i_3_r_5_t_7_cnt, S5S8SMStore::mpacket_sm_3_i_3_r_5_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_3_r_5_t_8_busy, S5S8SMStore::mpacket_sm_3_i_3_r_5_t_8_cnt, S5S8SMStore::mpacket_sm_3_i_3_r_5_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_3_r_5_t_9_busy, S5S8SMStore::mpacket_sm_3_i_3_r_5_t_9_cnt, S5S8SMStore::mpacket_sm_3_i_3_r_5_t_9, msgObj);
				break;
			}
			break;
	}
}

VOID S5S8MessageBroker::pushToQueue_i_3_r_6(MPacket *msgObj, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_3_r_6_t_0_busy, S5S8SMStore::mpacket_sm_0_i_3_r_6_t_0_cnt, S5S8SMStore::mpacket_sm_0_i_3_r_6_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_3_r_6_t_1_busy, S5S8SMStore::mpacket_sm_0_i_3_r_6_t_1_cnt, S5S8SMStore::mpacket_sm_0_i_3_r_6_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_3_r_6_t_2_busy, S5S8SMStore::mpacket_sm_0_i_3_r_6_t_2_cnt, S5S8SMStore::mpacket_sm_0_i_3_r_6_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_3_r_6_t_3_busy, S5S8SMStore::mpacket_sm_0_i_3_r_6_t_3_cnt, S5S8SMStore::mpacket_sm_0_i_3_r_6_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_3_r_6_t_4_busy, S5S8SMStore::mpacket_sm_0_i_3_r_6_t_4_cnt, S5S8SMStore::mpacket_sm_0_i_3_r_6_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_3_r_6_t_5_busy, S5S8SMStore::mpacket_sm_0_i_3_r_6_t_5_cnt, S5S8SMStore::mpacket_sm_0_i_3_r_6_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_3_r_6_t_6_busy, S5S8SMStore::mpacket_sm_0_i_3_r_6_t_6_cnt, S5S8SMStore::mpacket_sm_0_i_3_r_6_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_3_r_6_t_7_busy, S5S8SMStore::mpacket_sm_0_i_3_r_6_t_7_cnt, S5S8SMStore::mpacket_sm_0_i_3_r_6_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_3_r_6_t_8_busy, S5S8SMStore::mpacket_sm_0_i_3_r_6_t_8_cnt, S5S8SMStore::mpacket_sm_0_i_3_r_6_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_3_r_6_t_9_busy, S5S8SMStore::mpacket_sm_0_i_3_r_6_t_9_cnt, S5S8SMStore::mpacket_sm_0_i_3_r_6_t_9, msgObj);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_3_r_6_t_0_busy, S5S8SMStore::mpacket_sm_1_i_3_r_6_t_0_cnt, S5S8SMStore::mpacket_sm_1_i_3_r_6_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_3_r_6_t_1_busy, S5S8SMStore::mpacket_sm_1_i_3_r_6_t_1_cnt, S5S8SMStore::mpacket_sm_1_i_3_r_6_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_3_r_6_t_2_busy, S5S8SMStore::mpacket_sm_1_i_3_r_6_t_2_cnt, S5S8SMStore::mpacket_sm_1_i_3_r_6_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_3_r_6_t_3_busy, S5S8SMStore::mpacket_sm_1_i_3_r_6_t_3_cnt, S5S8SMStore::mpacket_sm_1_i_3_r_6_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_3_r_6_t_4_busy, S5S8SMStore::mpacket_sm_1_i_3_r_6_t_4_cnt, S5S8SMStore::mpacket_sm_1_i_3_r_6_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_3_r_6_t_5_busy, S5S8SMStore::mpacket_sm_1_i_3_r_6_t_5_cnt, S5S8SMStore::mpacket_sm_1_i_3_r_6_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_3_r_6_t_6_busy, S5S8SMStore::mpacket_sm_1_i_3_r_6_t_6_cnt, S5S8SMStore::mpacket_sm_1_i_3_r_6_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_3_r_6_t_7_busy, S5S8SMStore::mpacket_sm_1_i_3_r_6_t_7_cnt, S5S8SMStore::mpacket_sm_1_i_3_r_6_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_3_r_6_t_8_busy, S5S8SMStore::mpacket_sm_1_i_3_r_6_t_8_cnt, S5S8SMStore::mpacket_sm_1_i_3_r_6_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_3_r_6_t_9_busy, S5S8SMStore::mpacket_sm_1_i_3_r_6_t_9_cnt, S5S8SMStore::mpacket_sm_1_i_3_r_6_t_9, msgObj);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_3_r_6_t_0_busy, S5S8SMStore::mpacket_sm_2_i_3_r_6_t_0_cnt, S5S8SMStore::mpacket_sm_2_i_3_r_6_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_3_r_6_t_1_busy, S5S8SMStore::mpacket_sm_2_i_3_r_6_t_1_cnt, S5S8SMStore::mpacket_sm_2_i_3_r_6_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_3_r_6_t_2_busy, S5S8SMStore::mpacket_sm_2_i_3_r_6_t_2_cnt, S5S8SMStore::mpacket_sm_2_i_3_r_6_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_3_r_6_t_3_busy, S5S8SMStore::mpacket_sm_2_i_3_r_6_t_3_cnt, S5S8SMStore::mpacket_sm_2_i_3_r_6_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_3_r_6_t_4_busy, S5S8SMStore::mpacket_sm_2_i_3_r_6_t_4_cnt, S5S8SMStore::mpacket_sm_2_i_3_r_6_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_3_r_6_t_5_busy, S5S8SMStore::mpacket_sm_2_i_3_r_6_t_5_cnt, S5S8SMStore::mpacket_sm_2_i_3_r_6_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_3_r_6_t_6_busy, S5S8SMStore::mpacket_sm_2_i_3_r_6_t_6_cnt, S5S8SMStore::mpacket_sm_2_i_3_r_6_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_3_r_6_t_7_busy, S5S8SMStore::mpacket_sm_2_i_3_r_6_t_7_cnt, S5S8SMStore::mpacket_sm_2_i_3_r_6_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_3_r_6_t_8_busy, S5S8SMStore::mpacket_sm_2_i_3_r_6_t_8_cnt, S5S8SMStore::mpacket_sm_2_i_3_r_6_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_3_r_6_t_9_busy, S5S8SMStore::mpacket_sm_2_i_3_r_6_t_9_cnt, S5S8SMStore::mpacket_sm_2_i_3_r_6_t_9, msgObj);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_3_r_6_t_0_busy, S5S8SMStore::mpacket_sm_3_i_3_r_6_t_0_cnt, S5S8SMStore::mpacket_sm_3_i_3_r_6_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_3_r_6_t_1_busy, S5S8SMStore::mpacket_sm_3_i_3_r_6_t_1_cnt, S5S8SMStore::mpacket_sm_3_i_3_r_6_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_3_r_6_t_2_busy, S5S8SMStore::mpacket_sm_3_i_3_r_6_t_2_cnt, S5S8SMStore::mpacket_sm_3_i_3_r_6_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_3_r_6_t_3_busy, S5S8SMStore::mpacket_sm_3_i_3_r_6_t_3_cnt, S5S8SMStore::mpacket_sm_3_i_3_r_6_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_3_r_6_t_4_busy, S5S8SMStore::mpacket_sm_3_i_3_r_6_t_4_cnt, S5S8SMStore::mpacket_sm_3_i_3_r_6_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_3_r_6_t_5_busy, S5S8SMStore::mpacket_sm_3_i_3_r_6_t_5_cnt, S5S8SMStore::mpacket_sm_3_i_3_r_6_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_3_r_6_t_6_busy, S5S8SMStore::mpacket_sm_3_i_3_r_6_t_6_cnt, S5S8SMStore::mpacket_sm_3_i_3_r_6_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_3_r_6_t_7_busy, S5S8SMStore::mpacket_sm_3_i_3_r_6_t_7_cnt, S5S8SMStore::mpacket_sm_3_i_3_r_6_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_3_r_6_t_8_busy, S5S8SMStore::mpacket_sm_3_i_3_r_6_t_8_cnt, S5S8SMStore::mpacket_sm_3_i_3_r_6_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_3_r_6_t_9_busy, S5S8SMStore::mpacket_sm_3_i_3_r_6_t_9_cnt, S5S8SMStore::mpacket_sm_3_i_3_r_6_t_9, msgObj);
				break;
			}
			break;
	}
}

VOID S5S8MessageBroker::pushToQueue_i_3_r_7(MPacket *msgObj, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_3_r_7_t_0_busy, S5S8SMStore::mpacket_sm_0_i_3_r_7_t_0_cnt, S5S8SMStore::mpacket_sm_0_i_3_r_7_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_3_r_7_t_1_busy, S5S8SMStore::mpacket_sm_0_i_3_r_7_t_1_cnt, S5S8SMStore::mpacket_sm_0_i_3_r_7_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_3_r_7_t_2_busy, S5S8SMStore::mpacket_sm_0_i_3_r_7_t_2_cnt, S5S8SMStore::mpacket_sm_0_i_3_r_7_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_3_r_7_t_3_busy, S5S8SMStore::mpacket_sm_0_i_3_r_7_t_3_cnt, S5S8SMStore::mpacket_sm_0_i_3_r_7_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_3_r_7_t_4_busy, S5S8SMStore::mpacket_sm_0_i_3_r_7_t_4_cnt, S5S8SMStore::mpacket_sm_0_i_3_r_7_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_3_r_7_t_5_busy, S5S8SMStore::mpacket_sm_0_i_3_r_7_t_5_cnt, S5S8SMStore::mpacket_sm_0_i_3_r_7_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_3_r_7_t_6_busy, S5S8SMStore::mpacket_sm_0_i_3_r_7_t_6_cnt, S5S8SMStore::mpacket_sm_0_i_3_r_7_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_3_r_7_t_7_busy, S5S8SMStore::mpacket_sm_0_i_3_r_7_t_7_cnt, S5S8SMStore::mpacket_sm_0_i_3_r_7_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_3_r_7_t_8_busy, S5S8SMStore::mpacket_sm_0_i_3_r_7_t_8_cnt, S5S8SMStore::mpacket_sm_0_i_3_r_7_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_3_r_7_t_9_busy, S5S8SMStore::mpacket_sm_0_i_3_r_7_t_9_cnt, S5S8SMStore::mpacket_sm_0_i_3_r_7_t_9, msgObj);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_3_r_7_t_0_busy, S5S8SMStore::mpacket_sm_1_i_3_r_7_t_0_cnt, S5S8SMStore::mpacket_sm_1_i_3_r_7_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_3_r_7_t_1_busy, S5S8SMStore::mpacket_sm_1_i_3_r_7_t_1_cnt, S5S8SMStore::mpacket_sm_1_i_3_r_7_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_3_r_7_t_2_busy, S5S8SMStore::mpacket_sm_1_i_3_r_7_t_2_cnt, S5S8SMStore::mpacket_sm_1_i_3_r_7_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_3_r_7_t_3_busy, S5S8SMStore::mpacket_sm_1_i_3_r_7_t_3_cnt, S5S8SMStore::mpacket_sm_1_i_3_r_7_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_3_r_7_t_4_busy, S5S8SMStore::mpacket_sm_1_i_3_r_7_t_4_cnt, S5S8SMStore::mpacket_sm_1_i_3_r_7_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_3_r_7_t_5_busy, S5S8SMStore::mpacket_sm_1_i_3_r_7_t_5_cnt, S5S8SMStore::mpacket_sm_1_i_3_r_7_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_3_r_7_t_6_busy, S5S8SMStore::mpacket_sm_1_i_3_r_7_t_6_cnt, S5S8SMStore::mpacket_sm_1_i_3_r_7_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_3_r_7_t_7_busy, S5S8SMStore::mpacket_sm_1_i_3_r_7_t_7_cnt, S5S8SMStore::mpacket_sm_1_i_3_r_7_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_3_r_7_t_8_busy, S5S8SMStore::mpacket_sm_1_i_3_r_7_t_8_cnt, S5S8SMStore::mpacket_sm_1_i_3_r_7_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_3_r_7_t_9_busy, S5S8SMStore::mpacket_sm_1_i_3_r_7_t_9_cnt, S5S8SMStore::mpacket_sm_1_i_3_r_7_t_9, msgObj);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_3_r_7_t_0_busy, S5S8SMStore::mpacket_sm_2_i_3_r_7_t_0_cnt, S5S8SMStore::mpacket_sm_2_i_3_r_7_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_3_r_7_t_1_busy, S5S8SMStore::mpacket_sm_2_i_3_r_7_t_1_cnt, S5S8SMStore::mpacket_sm_2_i_3_r_7_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_3_r_7_t_2_busy, S5S8SMStore::mpacket_sm_2_i_3_r_7_t_2_cnt, S5S8SMStore::mpacket_sm_2_i_3_r_7_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_3_r_7_t_3_busy, S5S8SMStore::mpacket_sm_2_i_3_r_7_t_3_cnt, S5S8SMStore::mpacket_sm_2_i_3_r_7_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_3_r_7_t_4_busy, S5S8SMStore::mpacket_sm_2_i_3_r_7_t_4_cnt, S5S8SMStore::mpacket_sm_2_i_3_r_7_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_3_r_7_t_5_busy, S5S8SMStore::mpacket_sm_2_i_3_r_7_t_5_cnt, S5S8SMStore::mpacket_sm_2_i_3_r_7_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_3_r_7_t_6_busy, S5S8SMStore::mpacket_sm_2_i_3_r_7_t_6_cnt, S5S8SMStore::mpacket_sm_2_i_3_r_7_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_3_r_7_t_7_busy, S5S8SMStore::mpacket_sm_2_i_3_r_7_t_7_cnt, S5S8SMStore::mpacket_sm_2_i_3_r_7_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_3_r_7_t_8_busy, S5S8SMStore::mpacket_sm_2_i_3_r_7_t_8_cnt, S5S8SMStore::mpacket_sm_2_i_3_r_7_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_3_r_7_t_9_busy, S5S8SMStore::mpacket_sm_2_i_3_r_7_t_9_cnt, S5S8SMStore::mpacket_sm_2_i_3_r_7_t_9, msgObj);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_3_r_7_t_0_busy, S5S8SMStore::mpacket_sm_3_i_3_r_7_t_0_cnt, S5S8SMStore::mpacket_sm_3_i_3_r_7_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_3_r_7_t_1_busy, S5S8SMStore::mpacket_sm_3_i_3_r_7_t_1_cnt, S5S8SMStore::mpacket_sm_3_i_3_r_7_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_3_r_7_t_2_busy, S5S8SMStore::mpacket_sm_3_i_3_r_7_t_2_cnt, S5S8SMStore::mpacket_sm_3_i_3_r_7_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_3_r_7_t_3_busy, S5S8SMStore::mpacket_sm_3_i_3_r_7_t_3_cnt, S5S8SMStore::mpacket_sm_3_i_3_r_7_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_3_r_7_t_4_busy, S5S8SMStore::mpacket_sm_3_i_3_r_7_t_4_cnt, S5S8SMStore::mpacket_sm_3_i_3_r_7_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_3_r_7_t_5_busy, S5S8SMStore::mpacket_sm_3_i_3_r_7_t_5_cnt, S5S8SMStore::mpacket_sm_3_i_3_r_7_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_3_r_7_t_6_busy, S5S8SMStore::mpacket_sm_3_i_3_r_7_t_6_cnt, S5S8SMStore::mpacket_sm_3_i_3_r_7_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_3_r_7_t_7_busy, S5S8SMStore::mpacket_sm_3_i_3_r_7_t_7_cnt, S5S8SMStore::mpacket_sm_3_i_3_r_7_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_3_r_7_t_8_busy, S5S8SMStore::mpacket_sm_3_i_3_r_7_t_8_cnt, S5S8SMStore::mpacket_sm_3_i_3_r_7_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_3_r_7_t_9_busy, S5S8SMStore::mpacket_sm_3_i_3_r_7_t_9_cnt, S5S8SMStore::mpacket_sm_3_i_3_r_7_t_9, msgObj);
				break;
			}
			break;
	}
}


VOID S5S8MessageBroker::pushToQueue_i_4_r_0(MPacket *msgObj, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_4_r_0_t_0_busy, S5S8SMStore::mpacket_sm_0_i_4_r_0_t_0_cnt, S5S8SMStore::mpacket_sm_0_i_4_r_0_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_4_r_0_t_1_busy, S5S8SMStore::mpacket_sm_0_i_4_r_0_t_1_cnt, S5S8SMStore::mpacket_sm_0_i_4_r_0_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_4_r_0_t_2_busy, S5S8SMStore::mpacket_sm_0_i_4_r_0_t_2_cnt, S5S8SMStore::mpacket_sm_0_i_4_r_0_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_4_r_0_t_3_busy, S5S8SMStore::mpacket_sm_0_i_4_r_0_t_3_cnt, S5S8SMStore::mpacket_sm_0_i_4_r_0_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_4_r_0_t_4_busy, S5S8SMStore::mpacket_sm_0_i_4_r_0_t_4_cnt, S5S8SMStore::mpacket_sm_0_i_4_r_0_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_4_r_0_t_5_busy, S5S8SMStore::mpacket_sm_0_i_4_r_0_t_5_cnt, S5S8SMStore::mpacket_sm_0_i_4_r_0_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_4_r_0_t_6_busy, S5S8SMStore::mpacket_sm_0_i_4_r_0_t_6_cnt, S5S8SMStore::mpacket_sm_0_i_4_r_0_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_4_r_0_t_7_busy, S5S8SMStore::mpacket_sm_0_i_4_r_0_t_7_cnt, S5S8SMStore::mpacket_sm_0_i_4_r_0_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_4_r_0_t_8_busy, S5S8SMStore::mpacket_sm_0_i_4_r_0_t_8_cnt, S5S8SMStore::mpacket_sm_0_i_4_r_0_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_4_r_0_t_9_busy, S5S8SMStore::mpacket_sm_0_i_4_r_0_t_9_cnt, S5S8SMStore::mpacket_sm_0_i_4_r_0_t_9, msgObj);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_4_r_0_t_0_busy, S5S8SMStore::mpacket_sm_1_i_4_r_0_t_0_cnt, S5S8SMStore::mpacket_sm_1_i_4_r_0_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_4_r_0_t_1_busy, S5S8SMStore::mpacket_sm_1_i_4_r_0_t_1_cnt, S5S8SMStore::mpacket_sm_1_i_4_r_0_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_4_r_0_t_2_busy, S5S8SMStore::mpacket_sm_1_i_4_r_0_t_2_cnt, S5S8SMStore::mpacket_sm_1_i_4_r_0_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_4_r_0_t_3_busy, S5S8SMStore::mpacket_sm_1_i_4_r_0_t_3_cnt, S5S8SMStore::mpacket_sm_1_i_4_r_0_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_4_r_0_t_4_busy, S5S8SMStore::mpacket_sm_1_i_4_r_0_t_4_cnt, S5S8SMStore::mpacket_sm_1_i_4_r_0_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_4_r_0_t_5_busy, S5S8SMStore::mpacket_sm_1_i_4_r_0_t_5_cnt, S5S8SMStore::mpacket_sm_1_i_4_r_0_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_4_r_0_t_6_busy, S5S8SMStore::mpacket_sm_1_i_4_r_0_t_6_cnt, S5S8SMStore::mpacket_sm_1_i_4_r_0_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_4_r_0_t_7_busy, S5S8SMStore::mpacket_sm_1_i_4_r_0_t_7_cnt, S5S8SMStore::mpacket_sm_1_i_4_r_0_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_4_r_0_t_8_busy, S5S8SMStore::mpacket_sm_1_i_4_r_0_t_8_cnt, S5S8SMStore::mpacket_sm_1_i_4_r_0_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_4_r_0_t_9_busy, S5S8SMStore::mpacket_sm_1_i_4_r_0_t_9_cnt, S5S8SMStore::mpacket_sm_1_i_4_r_0_t_9, msgObj);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_4_r_0_t_0_busy, S5S8SMStore::mpacket_sm_2_i_4_r_0_t_0_cnt, S5S8SMStore::mpacket_sm_2_i_4_r_0_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_4_r_0_t_1_busy, S5S8SMStore::mpacket_sm_2_i_4_r_0_t_1_cnt, S5S8SMStore::mpacket_sm_2_i_4_r_0_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_4_r_0_t_2_busy, S5S8SMStore::mpacket_sm_2_i_4_r_0_t_2_cnt, S5S8SMStore::mpacket_sm_2_i_4_r_0_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_4_r_0_t_3_busy, S5S8SMStore::mpacket_sm_2_i_4_r_0_t_3_cnt, S5S8SMStore::mpacket_sm_2_i_4_r_0_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_4_r_0_t_4_busy, S5S8SMStore::mpacket_sm_2_i_4_r_0_t_4_cnt, S5S8SMStore::mpacket_sm_2_i_4_r_0_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_4_r_0_t_5_busy, S5S8SMStore::mpacket_sm_2_i_4_r_0_t_5_cnt, S5S8SMStore::mpacket_sm_2_i_4_r_0_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_4_r_0_t_6_busy, S5S8SMStore::mpacket_sm_2_i_4_r_0_t_6_cnt, S5S8SMStore::mpacket_sm_2_i_4_r_0_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_4_r_0_t_7_busy, S5S8SMStore::mpacket_sm_2_i_4_r_0_t_7_cnt, S5S8SMStore::mpacket_sm_2_i_4_r_0_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_4_r_0_t_8_busy, S5S8SMStore::mpacket_sm_2_i_4_r_0_t_8_cnt, S5S8SMStore::mpacket_sm_2_i_4_r_0_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_4_r_0_t_9_busy, S5S8SMStore::mpacket_sm_2_i_4_r_0_t_9_cnt, S5S8SMStore::mpacket_sm_2_i_4_r_0_t_9, msgObj);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_4_r_0_t_0_busy, S5S8SMStore::mpacket_sm_3_i_4_r_0_t_0_cnt, S5S8SMStore::mpacket_sm_3_i_4_r_0_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_4_r_0_t_1_busy, S5S8SMStore::mpacket_sm_3_i_4_r_0_t_1_cnt, S5S8SMStore::mpacket_sm_3_i_4_r_0_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_4_r_0_t_2_busy, S5S8SMStore::mpacket_sm_3_i_4_r_0_t_2_cnt, S5S8SMStore::mpacket_sm_3_i_4_r_0_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_4_r_0_t_3_busy, S5S8SMStore::mpacket_sm_3_i_4_r_0_t_3_cnt, S5S8SMStore::mpacket_sm_3_i_4_r_0_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_4_r_0_t_4_busy, S5S8SMStore::mpacket_sm_3_i_4_r_0_t_4_cnt, S5S8SMStore::mpacket_sm_3_i_4_r_0_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_4_r_0_t_5_busy, S5S8SMStore::mpacket_sm_3_i_4_r_0_t_5_cnt, S5S8SMStore::mpacket_sm_3_i_4_r_0_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_4_r_0_t_6_busy, S5S8SMStore::mpacket_sm_3_i_4_r_0_t_6_cnt, S5S8SMStore::mpacket_sm_3_i_4_r_0_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_4_r_0_t_7_busy, S5S8SMStore::mpacket_sm_3_i_4_r_0_t_7_cnt, S5S8SMStore::mpacket_sm_3_i_4_r_0_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_4_r_0_t_8_busy, S5S8SMStore::mpacket_sm_3_i_4_r_0_t_8_cnt, S5S8SMStore::mpacket_sm_3_i_4_r_0_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_4_r_0_t_9_busy, S5S8SMStore::mpacket_sm_3_i_4_r_0_t_9_cnt, S5S8SMStore::mpacket_sm_3_i_4_r_0_t_9, msgObj);
				break;
			}
			break;
	}
}

VOID S5S8MessageBroker::pushToQueue_i_4_r_1(MPacket *msgObj, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_4_r_1_t_0_busy, S5S8SMStore::mpacket_sm_0_i_4_r_1_t_0_cnt, S5S8SMStore::mpacket_sm_0_i_4_r_1_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_4_r_1_t_1_busy, S5S8SMStore::mpacket_sm_0_i_4_r_1_t_1_cnt, S5S8SMStore::mpacket_sm_0_i_4_r_1_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_4_r_1_t_2_busy, S5S8SMStore::mpacket_sm_0_i_4_r_1_t_2_cnt, S5S8SMStore::mpacket_sm_0_i_4_r_1_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_4_r_1_t_3_busy, S5S8SMStore::mpacket_sm_0_i_4_r_1_t_3_cnt, S5S8SMStore::mpacket_sm_0_i_4_r_1_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_4_r_1_t_4_busy, S5S8SMStore::mpacket_sm_0_i_4_r_1_t_4_cnt, S5S8SMStore::mpacket_sm_0_i_4_r_1_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_4_r_1_t_5_busy, S5S8SMStore::mpacket_sm_0_i_4_r_1_t_5_cnt, S5S8SMStore::mpacket_sm_0_i_4_r_1_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_4_r_1_t_6_busy, S5S8SMStore::mpacket_sm_0_i_4_r_1_t_6_cnt, S5S8SMStore::mpacket_sm_0_i_4_r_1_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_4_r_1_t_7_busy, S5S8SMStore::mpacket_sm_0_i_4_r_1_t_7_cnt, S5S8SMStore::mpacket_sm_0_i_4_r_1_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_4_r_1_t_8_busy, S5S8SMStore::mpacket_sm_0_i_4_r_1_t_8_cnt, S5S8SMStore::mpacket_sm_0_i_4_r_1_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_4_r_1_t_9_busy, S5S8SMStore::mpacket_sm_0_i_4_r_1_t_9_cnt, S5S8SMStore::mpacket_sm_0_i_4_r_1_t_9, msgObj);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_4_r_1_t_0_busy, S5S8SMStore::mpacket_sm_1_i_4_r_1_t_0_cnt, S5S8SMStore::mpacket_sm_1_i_4_r_1_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_4_r_1_t_1_busy, S5S8SMStore::mpacket_sm_1_i_4_r_1_t_1_cnt, S5S8SMStore::mpacket_sm_1_i_4_r_1_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_4_r_1_t_2_busy, S5S8SMStore::mpacket_sm_1_i_4_r_1_t_2_cnt, S5S8SMStore::mpacket_sm_1_i_4_r_1_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_4_r_1_t_3_busy, S5S8SMStore::mpacket_sm_1_i_4_r_1_t_3_cnt, S5S8SMStore::mpacket_sm_1_i_4_r_1_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_4_r_1_t_4_busy, S5S8SMStore::mpacket_sm_1_i_4_r_1_t_4_cnt, S5S8SMStore::mpacket_sm_1_i_4_r_1_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_4_r_1_t_5_busy, S5S8SMStore::mpacket_sm_1_i_4_r_1_t_5_cnt, S5S8SMStore::mpacket_sm_1_i_4_r_1_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_4_r_1_t_6_busy, S5S8SMStore::mpacket_sm_1_i_4_r_1_t_6_cnt, S5S8SMStore::mpacket_sm_1_i_4_r_1_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_4_r_1_t_7_busy, S5S8SMStore::mpacket_sm_1_i_4_r_1_t_7_cnt, S5S8SMStore::mpacket_sm_1_i_4_r_1_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_4_r_1_t_8_busy, S5S8SMStore::mpacket_sm_1_i_4_r_1_t_8_cnt, S5S8SMStore::mpacket_sm_1_i_4_r_1_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_4_r_1_t_9_busy, S5S8SMStore::mpacket_sm_1_i_4_r_1_t_9_cnt, S5S8SMStore::mpacket_sm_1_i_4_r_1_t_9, msgObj);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_4_r_1_t_0_busy, S5S8SMStore::mpacket_sm_2_i_4_r_1_t_0_cnt, S5S8SMStore::mpacket_sm_2_i_4_r_1_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_4_r_1_t_1_busy, S5S8SMStore::mpacket_sm_2_i_4_r_1_t_1_cnt, S5S8SMStore::mpacket_sm_2_i_4_r_1_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_4_r_1_t_2_busy, S5S8SMStore::mpacket_sm_2_i_4_r_1_t_2_cnt, S5S8SMStore::mpacket_sm_2_i_4_r_1_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_4_r_1_t_3_busy, S5S8SMStore::mpacket_sm_2_i_4_r_1_t_3_cnt, S5S8SMStore::mpacket_sm_2_i_4_r_1_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_4_r_1_t_4_busy, S5S8SMStore::mpacket_sm_2_i_4_r_1_t_4_cnt, S5S8SMStore::mpacket_sm_2_i_4_r_1_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_4_r_1_t_5_busy, S5S8SMStore::mpacket_sm_2_i_4_r_1_t_5_cnt, S5S8SMStore::mpacket_sm_2_i_4_r_1_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_4_r_1_t_6_busy, S5S8SMStore::mpacket_sm_2_i_4_r_1_t_6_cnt, S5S8SMStore::mpacket_sm_2_i_4_r_1_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_4_r_1_t_7_busy, S5S8SMStore::mpacket_sm_2_i_4_r_1_t_7_cnt, S5S8SMStore::mpacket_sm_2_i_4_r_1_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_4_r_1_t_8_busy, S5S8SMStore::mpacket_sm_2_i_4_r_1_t_8_cnt, S5S8SMStore::mpacket_sm_2_i_4_r_1_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_4_r_1_t_9_busy, S5S8SMStore::mpacket_sm_2_i_4_r_1_t_9_cnt, S5S8SMStore::mpacket_sm_2_i_4_r_1_t_9, msgObj);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_4_r_1_t_0_busy, S5S8SMStore::mpacket_sm_3_i_4_r_1_t_0_cnt, S5S8SMStore::mpacket_sm_3_i_4_r_1_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_4_r_1_t_1_busy, S5S8SMStore::mpacket_sm_3_i_4_r_1_t_1_cnt, S5S8SMStore::mpacket_sm_3_i_4_r_1_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_4_r_1_t_2_busy, S5S8SMStore::mpacket_sm_3_i_4_r_1_t_2_cnt, S5S8SMStore::mpacket_sm_3_i_4_r_1_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_4_r_1_t_3_busy, S5S8SMStore::mpacket_sm_3_i_4_r_1_t_3_cnt, S5S8SMStore::mpacket_sm_3_i_4_r_1_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_4_r_1_t_4_busy, S5S8SMStore::mpacket_sm_3_i_4_r_1_t_4_cnt, S5S8SMStore::mpacket_sm_3_i_4_r_1_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_4_r_1_t_5_busy, S5S8SMStore::mpacket_sm_3_i_4_r_1_t_5_cnt, S5S8SMStore::mpacket_sm_3_i_4_r_1_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_4_r_1_t_6_busy, S5S8SMStore::mpacket_sm_3_i_4_r_1_t_6_cnt, S5S8SMStore::mpacket_sm_3_i_4_r_1_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_4_r_1_t_7_busy, S5S8SMStore::mpacket_sm_3_i_4_r_1_t_7_cnt, S5S8SMStore::mpacket_sm_3_i_4_r_1_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_4_r_1_t_8_busy, S5S8SMStore::mpacket_sm_3_i_4_r_1_t_8_cnt, S5S8SMStore::mpacket_sm_3_i_4_r_1_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_4_r_1_t_9_busy, S5S8SMStore::mpacket_sm_3_i_4_r_1_t_9_cnt, S5S8SMStore::mpacket_sm_3_i_4_r_1_t_9, msgObj);
				break;
			}
			break;
	}
}

VOID S5S8MessageBroker::pushToQueue_i_4_r_2(MPacket *msgObj, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_4_r_2_t_0_busy, S5S8SMStore::mpacket_sm_0_i_4_r_2_t_0_cnt, S5S8SMStore::mpacket_sm_0_i_4_r_2_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_4_r_2_t_1_busy, S5S8SMStore::mpacket_sm_0_i_4_r_2_t_1_cnt, S5S8SMStore::mpacket_sm_0_i_4_r_2_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_4_r_2_t_2_busy, S5S8SMStore::mpacket_sm_0_i_4_r_2_t_2_cnt, S5S8SMStore::mpacket_sm_0_i_4_r_2_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_4_r_2_t_3_busy, S5S8SMStore::mpacket_sm_0_i_4_r_2_t_3_cnt, S5S8SMStore::mpacket_sm_0_i_4_r_2_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_4_r_2_t_4_busy, S5S8SMStore::mpacket_sm_0_i_4_r_2_t_4_cnt, S5S8SMStore::mpacket_sm_0_i_4_r_2_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_4_r_2_t_5_busy, S5S8SMStore::mpacket_sm_0_i_4_r_2_t_5_cnt, S5S8SMStore::mpacket_sm_0_i_4_r_2_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_4_r_2_t_6_busy, S5S8SMStore::mpacket_sm_0_i_4_r_2_t_6_cnt, S5S8SMStore::mpacket_sm_0_i_4_r_2_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_4_r_2_t_7_busy, S5S8SMStore::mpacket_sm_0_i_4_r_2_t_7_cnt, S5S8SMStore::mpacket_sm_0_i_4_r_2_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_4_r_2_t_8_busy, S5S8SMStore::mpacket_sm_0_i_4_r_2_t_8_cnt, S5S8SMStore::mpacket_sm_0_i_4_r_2_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_4_r_2_t_9_busy, S5S8SMStore::mpacket_sm_0_i_4_r_2_t_9_cnt, S5S8SMStore::mpacket_sm_0_i_4_r_2_t_9, msgObj);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_4_r_2_t_0_busy, S5S8SMStore::mpacket_sm_1_i_4_r_2_t_0_cnt, S5S8SMStore::mpacket_sm_1_i_4_r_2_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_4_r_2_t_1_busy, S5S8SMStore::mpacket_sm_1_i_4_r_2_t_1_cnt, S5S8SMStore::mpacket_sm_1_i_4_r_2_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_4_r_2_t_2_busy, S5S8SMStore::mpacket_sm_1_i_4_r_2_t_2_cnt, S5S8SMStore::mpacket_sm_1_i_4_r_2_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_4_r_2_t_3_busy, S5S8SMStore::mpacket_sm_1_i_4_r_2_t_3_cnt, S5S8SMStore::mpacket_sm_1_i_4_r_2_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_4_r_2_t_4_busy, S5S8SMStore::mpacket_sm_1_i_4_r_2_t_4_cnt, S5S8SMStore::mpacket_sm_1_i_4_r_2_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_4_r_2_t_5_busy, S5S8SMStore::mpacket_sm_1_i_4_r_2_t_5_cnt, S5S8SMStore::mpacket_sm_1_i_4_r_2_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_4_r_2_t_6_busy, S5S8SMStore::mpacket_sm_1_i_4_r_2_t_6_cnt, S5S8SMStore::mpacket_sm_1_i_4_r_2_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_4_r_2_t_7_busy, S5S8SMStore::mpacket_sm_1_i_4_r_2_t_7_cnt, S5S8SMStore::mpacket_sm_1_i_4_r_2_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_4_r_2_t_8_busy, S5S8SMStore::mpacket_sm_1_i_4_r_2_t_8_cnt, S5S8SMStore::mpacket_sm_1_i_4_r_2_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_4_r_2_t_9_busy, S5S8SMStore::mpacket_sm_1_i_4_r_2_t_9_cnt, S5S8SMStore::mpacket_sm_1_i_4_r_2_t_9, msgObj);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_4_r_2_t_0_busy, S5S8SMStore::mpacket_sm_2_i_4_r_2_t_0_cnt, S5S8SMStore::mpacket_sm_2_i_4_r_2_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_4_r_2_t_1_busy, S5S8SMStore::mpacket_sm_2_i_4_r_2_t_1_cnt, S5S8SMStore::mpacket_sm_2_i_4_r_2_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_4_r_2_t_2_busy, S5S8SMStore::mpacket_sm_2_i_4_r_2_t_2_cnt, S5S8SMStore::mpacket_sm_2_i_4_r_2_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_4_r_2_t_3_busy, S5S8SMStore::mpacket_sm_2_i_4_r_2_t_3_cnt, S5S8SMStore::mpacket_sm_2_i_4_r_2_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_4_r_2_t_4_busy, S5S8SMStore::mpacket_sm_2_i_4_r_2_t_4_cnt, S5S8SMStore::mpacket_sm_2_i_4_r_2_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_4_r_2_t_5_busy, S5S8SMStore::mpacket_sm_2_i_4_r_2_t_5_cnt, S5S8SMStore::mpacket_sm_2_i_4_r_2_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_4_r_2_t_6_busy, S5S8SMStore::mpacket_sm_2_i_4_r_2_t_6_cnt, S5S8SMStore::mpacket_sm_2_i_4_r_2_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_4_r_2_t_7_busy, S5S8SMStore::mpacket_sm_2_i_4_r_2_t_7_cnt, S5S8SMStore::mpacket_sm_2_i_4_r_2_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_4_r_2_t_8_busy, S5S8SMStore::mpacket_sm_2_i_4_r_2_t_8_cnt, S5S8SMStore::mpacket_sm_2_i_4_r_2_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_4_r_2_t_9_busy, S5S8SMStore::mpacket_sm_2_i_4_r_2_t_9_cnt, S5S8SMStore::mpacket_sm_2_i_4_r_2_t_9, msgObj);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_4_r_2_t_0_busy, S5S8SMStore::mpacket_sm_3_i_4_r_2_t_0_cnt, S5S8SMStore::mpacket_sm_3_i_4_r_2_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_4_r_2_t_1_busy, S5S8SMStore::mpacket_sm_3_i_4_r_2_t_1_cnt, S5S8SMStore::mpacket_sm_3_i_4_r_2_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_4_r_2_t_2_busy, S5S8SMStore::mpacket_sm_3_i_4_r_2_t_2_cnt, S5S8SMStore::mpacket_sm_3_i_4_r_2_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_4_r_2_t_3_busy, S5S8SMStore::mpacket_sm_3_i_4_r_2_t_3_cnt, S5S8SMStore::mpacket_sm_3_i_4_r_2_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_4_r_2_t_4_busy, S5S8SMStore::mpacket_sm_3_i_4_r_2_t_4_cnt, S5S8SMStore::mpacket_sm_3_i_4_r_2_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_4_r_2_t_5_busy, S5S8SMStore::mpacket_sm_3_i_4_r_2_t_5_cnt, S5S8SMStore::mpacket_sm_3_i_4_r_2_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_4_r_2_t_6_busy, S5S8SMStore::mpacket_sm_3_i_4_r_2_t_6_cnt, S5S8SMStore::mpacket_sm_3_i_4_r_2_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_4_r_2_t_7_busy, S5S8SMStore::mpacket_sm_3_i_4_r_2_t_7_cnt, S5S8SMStore::mpacket_sm_3_i_4_r_2_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_4_r_2_t_8_busy, S5S8SMStore::mpacket_sm_3_i_4_r_2_t_8_cnt, S5S8SMStore::mpacket_sm_3_i_4_r_2_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_4_r_2_t_9_busy, S5S8SMStore::mpacket_sm_3_i_4_r_2_t_9_cnt, S5S8SMStore::mpacket_sm_3_i_4_r_2_t_9, msgObj);
				break;
			}
			break;
	}
}

VOID S5S8MessageBroker::pushToQueue_i_4_r_3(MPacket *msgObj, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_4_r_3_t_0_busy, S5S8SMStore::mpacket_sm_0_i_4_r_3_t_0_cnt, S5S8SMStore::mpacket_sm_0_i_4_r_3_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_4_r_3_t_1_busy, S5S8SMStore::mpacket_sm_0_i_4_r_3_t_1_cnt, S5S8SMStore::mpacket_sm_0_i_4_r_3_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_4_r_3_t_2_busy, S5S8SMStore::mpacket_sm_0_i_4_r_3_t_2_cnt, S5S8SMStore::mpacket_sm_0_i_4_r_3_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_4_r_3_t_3_busy, S5S8SMStore::mpacket_sm_0_i_4_r_3_t_3_cnt, S5S8SMStore::mpacket_sm_0_i_4_r_3_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_4_r_3_t_4_busy, S5S8SMStore::mpacket_sm_0_i_4_r_3_t_4_cnt, S5S8SMStore::mpacket_sm_0_i_4_r_3_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_4_r_3_t_5_busy, S5S8SMStore::mpacket_sm_0_i_4_r_3_t_5_cnt, S5S8SMStore::mpacket_sm_0_i_4_r_3_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_4_r_3_t_6_busy, S5S8SMStore::mpacket_sm_0_i_4_r_3_t_6_cnt, S5S8SMStore::mpacket_sm_0_i_4_r_3_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_4_r_3_t_7_busy, S5S8SMStore::mpacket_sm_0_i_4_r_3_t_7_cnt, S5S8SMStore::mpacket_sm_0_i_4_r_3_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_4_r_3_t_8_busy, S5S8SMStore::mpacket_sm_0_i_4_r_3_t_8_cnt, S5S8SMStore::mpacket_sm_0_i_4_r_3_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_4_r_3_t_9_busy, S5S8SMStore::mpacket_sm_0_i_4_r_3_t_9_cnt, S5S8SMStore::mpacket_sm_0_i_4_r_3_t_9, msgObj);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_4_r_3_t_0_busy, S5S8SMStore::mpacket_sm_1_i_4_r_3_t_0_cnt, S5S8SMStore::mpacket_sm_1_i_4_r_3_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_4_r_3_t_1_busy, S5S8SMStore::mpacket_sm_1_i_4_r_3_t_1_cnt, S5S8SMStore::mpacket_sm_1_i_4_r_3_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_4_r_3_t_2_busy, S5S8SMStore::mpacket_sm_1_i_4_r_3_t_2_cnt, S5S8SMStore::mpacket_sm_1_i_4_r_3_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_4_r_3_t_3_busy, S5S8SMStore::mpacket_sm_1_i_4_r_3_t_3_cnt, S5S8SMStore::mpacket_sm_1_i_4_r_3_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_4_r_3_t_4_busy, S5S8SMStore::mpacket_sm_1_i_4_r_3_t_4_cnt, S5S8SMStore::mpacket_sm_1_i_4_r_3_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_4_r_3_t_5_busy, S5S8SMStore::mpacket_sm_1_i_4_r_3_t_5_cnt, S5S8SMStore::mpacket_sm_1_i_4_r_3_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_4_r_3_t_6_busy, S5S8SMStore::mpacket_sm_1_i_4_r_3_t_6_cnt, S5S8SMStore::mpacket_sm_1_i_4_r_3_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_4_r_3_t_7_busy, S5S8SMStore::mpacket_sm_1_i_4_r_3_t_7_cnt, S5S8SMStore::mpacket_sm_1_i_4_r_3_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_4_r_3_t_8_busy, S5S8SMStore::mpacket_sm_1_i_4_r_3_t_8_cnt, S5S8SMStore::mpacket_sm_1_i_4_r_3_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_4_r_3_t_9_busy, S5S8SMStore::mpacket_sm_1_i_4_r_3_t_9_cnt, S5S8SMStore::mpacket_sm_1_i_4_r_3_t_9, msgObj);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_4_r_3_t_0_busy, S5S8SMStore::mpacket_sm_2_i_4_r_3_t_0_cnt, S5S8SMStore::mpacket_sm_2_i_4_r_3_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_4_r_3_t_1_busy, S5S8SMStore::mpacket_sm_2_i_4_r_3_t_1_cnt, S5S8SMStore::mpacket_sm_2_i_4_r_3_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_4_r_3_t_2_busy, S5S8SMStore::mpacket_sm_2_i_4_r_3_t_2_cnt, S5S8SMStore::mpacket_sm_2_i_4_r_3_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_4_r_3_t_3_busy, S5S8SMStore::mpacket_sm_2_i_4_r_3_t_3_cnt, S5S8SMStore::mpacket_sm_2_i_4_r_3_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_4_r_3_t_4_busy, S5S8SMStore::mpacket_sm_2_i_4_r_3_t_4_cnt, S5S8SMStore::mpacket_sm_2_i_4_r_3_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_4_r_3_t_5_busy, S5S8SMStore::mpacket_sm_2_i_4_r_3_t_5_cnt, S5S8SMStore::mpacket_sm_2_i_4_r_3_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_4_r_3_t_6_busy, S5S8SMStore::mpacket_sm_2_i_4_r_3_t_6_cnt, S5S8SMStore::mpacket_sm_2_i_4_r_3_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_4_r_3_t_7_busy, S5S8SMStore::mpacket_sm_2_i_4_r_3_t_7_cnt, S5S8SMStore::mpacket_sm_2_i_4_r_3_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_4_r_3_t_8_busy, S5S8SMStore::mpacket_sm_2_i_4_r_3_t_8_cnt, S5S8SMStore::mpacket_sm_2_i_4_r_3_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_4_r_3_t_9_busy, S5S8SMStore::mpacket_sm_2_i_4_r_3_t_9_cnt, S5S8SMStore::mpacket_sm_2_i_4_r_3_t_9, msgObj);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_4_r_3_t_0_busy, S5S8SMStore::mpacket_sm_3_i_4_r_3_t_0_cnt, S5S8SMStore::mpacket_sm_3_i_4_r_3_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_4_r_3_t_1_busy, S5S8SMStore::mpacket_sm_3_i_4_r_3_t_1_cnt, S5S8SMStore::mpacket_sm_3_i_4_r_3_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_4_r_3_t_2_busy, S5S8SMStore::mpacket_sm_3_i_4_r_3_t_2_cnt, S5S8SMStore::mpacket_sm_3_i_4_r_3_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_4_r_3_t_3_busy, S5S8SMStore::mpacket_sm_3_i_4_r_3_t_3_cnt, S5S8SMStore::mpacket_sm_3_i_4_r_3_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_4_r_3_t_4_busy, S5S8SMStore::mpacket_sm_3_i_4_r_3_t_4_cnt, S5S8SMStore::mpacket_sm_3_i_4_r_3_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_4_r_3_t_5_busy, S5S8SMStore::mpacket_sm_3_i_4_r_3_t_5_cnt, S5S8SMStore::mpacket_sm_3_i_4_r_3_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_4_r_3_t_6_busy, S5S8SMStore::mpacket_sm_3_i_4_r_3_t_6_cnt, S5S8SMStore::mpacket_sm_3_i_4_r_3_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_4_r_3_t_7_busy, S5S8SMStore::mpacket_sm_3_i_4_r_3_t_7_cnt, S5S8SMStore::mpacket_sm_3_i_4_r_3_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_4_r_3_t_8_busy, S5S8SMStore::mpacket_sm_3_i_4_r_3_t_8_cnt, S5S8SMStore::mpacket_sm_3_i_4_r_3_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_4_r_3_t_9_busy, S5S8SMStore::mpacket_sm_3_i_4_r_3_t_9_cnt, S5S8SMStore::mpacket_sm_3_i_4_r_3_t_9, msgObj);
				break;
			}
			break;
	}
}

VOID S5S8MessageBroker::pushToQueue_i_4_r_4(MPacket *msgObj, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_4_r_4_t_0_busy, S5S8SMStore::mpacket_sm_0_i_4_r_4_t_0_cnt, S5S8SMStore::mpacket_sm_0_i_4_r_4_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_4_r_4_t_1_busy, S5S8SMStore::mpacket_sm_0_i_4_r_4_t_1_cnt, S5S8SMStore::mpacket_sm_0_i_4_r_4_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_4_r_4_t_2_busy, S5S8SMStore::mpacket_sm_0_i_4_r_4_t_2_cnt, S5S8SMStore::mpacket_sm_0_i_4_r_4_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_4_r_4_t_3_busy, S5S8SMStore::mpacket_sm_0_i_4_r_4_t_3_cnt, S5S8SMStore::mpacket_sm_0_i_4_r_4_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_4_r_4_t_4_busy, S5S8SMStore::mpacket_sm_0_i_4_r_4_t_4_cnt, S5S8SMStore::mpacket_sm_0_i_4_r_4_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_4_r_4_t_5_busy, S5S8SMStore::mpacket_sm_0_i_4_r_4_t_5_cnt, S5S8SMStore::mpacket_sm_0_i_4_r_4_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_4_r_4_t_6_busy, S5S8SMStore::mpacket_sm_0_i_4_r_4_t_6_cnt, S5S8SMStore::mpacket_sm_0_i_4_r_4_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_4_r_4_t_7_busy, S5S8SMStore::mpacket_sm_0_i_4_r_4_t_7_cnt, S5S8SMStore::mpacket_sm_0_i_4_r_4_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_4_r_4_t_8_busy, S5S8SMStore::mpacket_sm_0_i_4_r_4_t_8_cnt, S5S8SMStore::mpacket_sm_0_i_4_r_4_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_4_r_4_t_9_busy, S5S8SMStore::mpacket_sm_0_i_4_r_4_t_9_cnt, S5S8SMStore::mpacket_sm_0_i_4_r_4_t_9, msgObj);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_4_r_4_t_0_busy, S5S8SMStore::mpacket_sm_1_i_4_r_4_t_0_cnt, S5S8SMStore::mpacket_sm_1_i_4_r_4_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_4_r_4_t_1_busy, S5S8SMStore::mpacket_sm_1_i_4_r_4_t_1_cnt, S5S8SMStore::mpacket_sm_1_i_4_r_4_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_4_r_4_t_2_busy, S5S8SMStore::mpacket_sm_1_i_4_r_4_t_2_cnt, S5S8SMStore::mpacket_sm_1_i_4_r_4_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_4_r_4_t_3_busy, S5S8SMStore::mpacket_sm_1_i_4_r_4_t_3_cnt, S5S8SMStore::mpacket_sm_1_i_4_r_4_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_4_r_4_t_4_busy, S5S8SMStore::mpacket_sm_1_i_4_r_4_t_4_cnt, S5S8SMStore::mpacket_sm_1_i_4_r_4_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_4_r_4_t_5_busy, S5S8SMStore::mpacket_sm_1_i_4_r_4_t_5_cnt, S5S8SMStore::mpacket_sm_1_i_4_r_4_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_4_r_4_t_6_busy, S5S8SMStore::mpacket_sm_1_i_4_r_4_t_6_cnt, S5S8SMStore::mpacket_sm_1_i_4_r_4_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_4_r_4_t_7_busy, S5S8SMStore::mpacket_sm_1_i_4_r_4_t_7_cnt, S5S8SMStore::mpacket_sm_1_i_4_r_4_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_4_r_4_t_8_busy, S5S8SMStore::mpacket_sm_1_i_4_r_4_t_8_cnt, S5S8SMStore::mpacket_sm_1_i_4_r_4_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_4_r_4_t_9_busy, S5S8SMStore::mpacket_sm_1_i_4_r_4_t_9_cnt, S5S8SMStore::mpacket_sm_1_i_4_r_4_t_9, msgObj);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_4_r_4_t_0_busy, S5S8SMStore::mpacket_sm_2_i_4_r_4_t_0_cnt, S5S8SMStore::mpacket_sm_2_i_4_r_4_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_4_r_4_t_1_busy, S5S8SMStore::mpacket_sm_2_i_4_r_4_t_1_cnt, S5S8SMStore::mpacket_sm_2_i_4_r_4_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_4_r_4_t_2_busy, S5S8SMStore::mpacket_sm_2_i_4_r_4_t_2_cnt, S5S8SMStore::mpacket_sm_2_i_4_r_4_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_4_r_4_t_3_busy, S5S8SMStore::mpacket_sm_2_i_4_r_4_t_3_cnt, S5S8SMStore::mpacket_sm_2_i_4_r_4_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_4_r_4_t_4_busy, S5S8SMStore::mpacket_sm_2_i_4_r_4_t_4_cnt, S5S8SMStore::mpacket_sm_2_i_4_r_4_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_4_r_4_t_5_busy, S5S8SMStore::mpacket_sm_2_i_4_r_4_t_5_cnt, S5S8SMStore::mpacket_sm_2_i_4_r_4_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_4_r_4_t_6_busy, S5S8SMStore::mpacket_sm_2_i_4_r_4_t_6_cnt, S5S8SMStore::mpacket_sm_2_i_4_r_4_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_4_r_4_t_7_busy, S5S8SMStore::mpacket_sm_2_i_4_r_4_t_7_cnt, S5S8SMStore::mpacket_sm_2_i_4_r_4_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_4_r_4_t_8_busy, S5S8SMStore::mpacket_sm_2_i_4_r_4_t_8_cnt, S5S8SMStore::mpacket_sm_2_i_4_r_4_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_4_r_4_t_9_busy, S5S8SMStore::mpacket_sm_2_i_4_r_4_t_9_cnt, S5S8SMStore::mpacket_sm_2_i_4_r_4_t_9, msgObj);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_4_r_4_t_0_busy, S5S8SMStore::mpacket_sm_3_i_4_r_4_t_0_cnt, S5S8SMStore::mpacket_sm_3_i_4_r_4_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_4_r_4_t_1_busy, S5S8SMStore::mpacket_sm_3_i_4_r_4_t_1_cnt, S5S8SMStore::mpacket_sm_3_i_4_r_4_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_4_r_4_t_2_busy, S5S8SMStore::mpacket_sm_3_i_4_r_4_t_2_cnt, S5S8SMStore::mpacket_sm_3_i_4_r_4_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_4_r_4_t_3_busy, S5S8SMStore::mpacket_sm_3_i_4_r_4_t_3_cnt, S5S8SMStore::mpacket_sm_3_i_4_r_4_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_4_r_4_t_4_busy, S5S8SMStore::mpacket_sm_3_i_4_r_4_t_4_cnt, S5S8SMStore::mpacket_sm_3_i_4_r_4_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_4_r_4_t_5_busy, S5S8SMStore::mpacket_sm_3_i_4_r_4_t_5_cnt, S5S8SMStore::mpacket_sm_3_i_4_r_4_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_4_r_4_t_6_busy, S5S8SMStore::mpacket_sm_3_i_4_r_4_t_6_cnt, S5S8SMStore::mpacket_sm_3_i_4_r_4_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_4_r_4_t_7_busy, S5S8SMStore::mpacket_sm_3_i_4_r_4_t_7_cnt, S5S8SMStore::mpacket_sm_3_i_4_r_4_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_4_r_4_t_8_busy, S5S8SMStore::mpacket_sm_3_i_4_r_4_t_8_cnt, S5S8SMStore::mpacket_sm_3_i_4_r_4_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_4_r_4_t_9_busy, S5S8SMStore::mpacket_sm_3_i_4_r_4_t_9_cnt, S5S8SMStore::mpacket_sm_3_i_4_r_4_t_9, msgObj);
				break;
			}
			break;
	}
}

VOID S5S8MessageBroker::pushToQueue_i_4_r_5(MPacket *msgObj, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_4_r_5_t_0_busy, S5S8SMStore::mpacket_sm_0_i_4_r_5_t_0_cnt, S5S8SMStore::mpacket_sm_0_i_4_r_5_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_4_r_5_t_1_busy, S5S8SMStore::mpacket_sm_0_i_4_r_5_t_1_cnt, S5S8SMStore::mpacket_sm_0_i_4_r_5_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_4_r_5_t_2_busy, S5S8SMStore::mpacket_sm_0_i_4_r_5_t_2_cnt, S5S8SMStore::mpacket_sm_0_i_4_r_5_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_4_r_5_t_3_busy, S5S8SMStore::mpacket_sm_0_i_4_r_5_t_3_cnt, S5S8SMStore::mpacket_sm_0_i_4_r_5_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_4_r_5_t_4_busy, S5S8SMStore::mpacket_sm_0_i_4_r_5_t_4_cnt, S5S8SMStore::mpacket_sm_0_i_4_r_5_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_4_r_5_t_5_busy, S5S8SMStore::mpacket_sm_0_i_4_r_5_t_5_cnt, S5S8SMStore::mpacket_sm_0_i_4_r_5_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_4_r_5_t_6_busy, S5S8SMStore::mpacket_sm_0_i_4_r_5_t_6_cnt, S5S8SMStore::mpacket_sm_0_i_4_r_5_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_4_r_5_t_7_busy, S5S8SMStore::mpacket_sm_0_i_4_r_5_t_7_cnt, S5S8SMStore::mpacket_sm_0_i_4_r_5_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_4_r_5_t_8_busy, S5S8SMStore::mpacket_sm_0_i_4_r_5_t_8_cnt, S5S8SMStore::mpacket_sm_0_i_4_r_5_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_4_r_5_t_9_busy, S5S8SMStore::mpacket_sm_0_i_4_r_5_t_9_cnt, S5S8SMStore::mpacket_sm_0_i_4_r_5_t_9, msgObj);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_4_r_5_t_0_busy, S5S8SMStore::mpacket_sm_1_i_4_r_5_t_0_cnt, S5S8SMStore::mpacket_sm_1_i_4_r_5_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_4_r_5_t_1_busy, S5S8SMStore::mpacket_sm_1_i_4_r_5_t_1_cnt, S5S8SMStore::mpacket_sm_1_i_4_r_5_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_4_r_5_t_2_busy, S5S8SMStore::mpacket_sm_1_i_4_r_5_t_2_cnt, S5S8SMStore::mpacket_sm_1_i_4_r_5_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_4_r_5_t_3_busy, S5S8SMStore::mpacket_sm_1_i_4_r_5_t_3_cnt, S5S8SMStore::mpacket_sm_1_i_4_r_5_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_4_r_5_t_4_busy, S5S8SMStore::mpacket_sm_1_i_4_r_5_t_4_cnt, S5S8SMStore::mpacket_sm_1_i_4_r_5_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_4_r_5_t_5_busy, S5S8SMStore::mpacket_sm_1_i_4_r_5_t_5_cnt, S5S8SMStore::mpacket_sm_1_i_4_r_5_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_4_r_5_t_6_busy, S5S8SMStore::mpacket_sm_1_i_4_r_5_t_6_cnt, S5S8SMStore::mpacket_sm_1_i_4_r_5_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_4_r_5_t_7_busy, S5S8SMStore::mpacket_sm_1_i_4_r_5_t_7_cnt, S5S8SMStore::mpacket_sm_1_i_4_r_5_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_4_r_5_t_8_busy, S5S8SMStore::mpacket_sm_1_i_4_r_5_t_8_cnt, S5S8SMStore::mpacket_sm_1_i_4_r_5_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_4_r_5_t_9_busy, S5S8SMStore::mpacket_sm_1_i_4_r_5_t_9_cnt, S5S8SMStore::mpacket_sm_1_i_4_r_5_t_9, msgObj);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_4_r_5_t_0_busy, S5S8SMStore::mpacket_sm_2_i_4_r_5_t_0_cnt, S5S8SMStore::mpacket_sm_2_i_4_r_5_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_4_r_5_t_1_busy, S5S8SMStore::mpacket_sm_2_i_4_r_5_t_1_cnt, S5S8SMStore::mpacket_sm_2_i_4_r_5_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_4_r_5_t_2_busy, S5S8SMStore::mpacket_sm_2_i_4_r_5_t_2_cnt, S5S8SMStore::mpacket_sm_2_i_4_r_5_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_4_r_5_t_3_busy, S5S8SMStore::mpacket_sm_2_i_4_r_5_t_3_cnt, S5S8SMStore::mpacket_sm_2_i_4_r_5_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_4_r_5_t_4_busy, S5S8SMStore::mpacket_sm_2_i_4_r_5_t_4_cnt, S5S8SMStore::mpacket_sm_2_i_4_r_5_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_4_r_5_t_5_busy, S5S8SMStore::mpacket_sm_2_i_4_r_5_t_5_cnt, S5S8SMStore::mpacket_sm_2_i_4_r_5_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_4_r_5_t_6_busy, S5S8SMStore::mpacket_sm_2_i_4_r_5_t_6_cnt, S5S8SMStore::mpacket_sm_2_i_4_r_5_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_4_r_5_t_7_busy, S5S8SMStore::mpacket_sm_2_i_4_r_5_t_7_cnt, S5S8SMStore::mpacket_sm_2_i_4_r_5_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_4_r_5_t_8_busy, S5S8SMStore::mpacket_sm_2_i_4_r_5_t_8_cnt, S5S8SMStore::mpacket_sm_2_i_4_r_5_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_4_r_5_t_9_busy, S5S8SMStore::mpacket_sm_2_i_4_r_5_t_9_cnt, S5S8SMStore::mpacket_sm_2_i_4_r_5_t_9, msgObj);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_4_r_5_t_0_busy, S5S8SMStore::mpacket_sm_3_i_4_r_5_t_0_cnt, S5S8SMStore::mpacket_sm_3_i_4_r_5_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_4_r_5_t_1_busy, S5S8SMStore::mpacket_sm_3_i_4_r_5_t_1_cnt, S5S8SMStore::mpacket_sm_3_i_4_r_5_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_4_r_5_t_2_busy, S5S8SMStore::mpacket_sm_3_i_4_r_5_t_2_cnt, S5S8SMStore::mpacket_sm_3_i_4_r_5_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_4_r_5_t_3_busy, S5S8SMStore::mpacket_sm_3_i_4_r_5_t_3_cnt, S5S8SMStore::mpacket_sm_3_i_4_r_5_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_4_r_5_t_4_busy, S5S8SMStore::mpacket_sm_3_i_4_r_5_t_4_cnt, S5S8SMStore::mpacket_sm_3_i_4_r_5_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_4_r_5_t_5_busy, S5S8SMStore::mpacket_sm_3_i_4_r_5_t_5_cnt, S5S8SMStore::mpacket_sm_3_i_4_r_5_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_4_r_5_t_6_busy, S5S8SMStore::mpacket_sm_3_i_4_r_5_t_6_cnt, S5S8SMStore::mpacket_sm_3_i_4_r_5_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_4_r_5_t_7_busy, S5S8SMStore::mpacket_sm_3_i_4_r_5_t_7_cnt, S5S8SMStore::mpacket_sm_3_i_4_r_5_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_4_r_5_t_8_busy, S5S8SMStore::mpacket_sm_3_i_4_r_5_t_8_cnt, S5S8SMStore::mpacket_sm_3_i_4_r_5_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_4_r_5_t_9_busy, S5S8SMStore::mpacket_sm_3_i_4_r_5_t_9_cnt, S5S8SMStore::mpacket_sm_3_i_4_r_5_t_9, msgObj);
				break;
			}
			break;
	}
}

VOID S5S8MessageBroker::pushToQueue_i_4_r_6(MPacket *msgObj, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_4_r_6_t_0_busy, S5S8SMStore::mpacket_sm_0_i_4_r_6_t_0_cnt, S5S8SMStore::mpacket_sm_0_i_4_r_6_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_4_r_6_t_1_busy, S5S8SMStore::mpacket_sm_0_i_4_r_6_t_1_cnt, S5S8SMStore::mpacket_sm_0_i_4_r_6_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_4_r_6_t_2_busy, S5S8SMStore::mpacket_sm_0_i_4_r_6_t_2_cnt, S5S8SMStore::mpacket_sm_0_i_4_r_6_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_4_r_6_t_3_busy, S5S8SMStore::mpacket_sm_0_i_4_r_6_t_3_cnt, S5S8SMStore::mpacket_sm_0_i_4_r_6_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_4_r_6_t_4_busy, S5S8SMStore::mpacket_sm_0_i_4_r_6_t_4_cnt, S5S8SMStore::mpacket_sm_0_i_4_r_6_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_4_r_6_t_5_busy, S5S8SMStore::mpacket_sm_0_i_4_r_6_t_5_cnt, S5S8SMStore::mpacket_sm_0_i_4_r_6_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_4_r_6_t_6_busy, S5S8SMStore::mpacket_sm_0_i_4_r_6_t_6_cnt, S5S8SMStore::mpacket_sm_0_i_4_r_6_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_4_r_6_t_7_busy, S5S8SMStore::mpacket_sm_0_i_4_r_6_t_7_cnt, S5S8SMStore::mpacket_sm_0_i_4_r_6_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_4_r_6_t_8_busy, S5S8SMStore::mpacket_sm_0_i_4_r_6_t_8_cnt, S5S8SMStore::mpacket_sm_0_i_4_r_6_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_4_r_6_t_9_busy, S5S8SMStore::mpacket_sm_0_i_4_r_6_t_9_cnt, S5S8SMStore::mpacket_sm_0_i_4_r_6_t_9, msgObj);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_4_r_6_t_0_busy, S5S8SMStore::mpacket_sm_1_i_4_r_6_t_0_cnt, S5S8SMStore::mpacket_sm_1_i_4_r_6_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_4_r_6_t_1_busy, S5S8SMStore::mpacket_sm_1_i_4_r_6_t_1_cnt, S5S8SMStore::mpacket_sm_1_i_4_r_6_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_4_r_6_t_2_busy, S5S8SMStore::mpacket_sm_1_i_4_r_6_t_2_cnt, S5S8SMStore::mpacket_sm_1_i_4_r_6_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_4_r_6_t_3_busy, S5S8SMStore::mpacket_sm_1_i_4_r_6_t_3_cnt, S5S8SMStore::mpacket_sm_1_i_4_r_6_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_4_r_6_t_4_busy, S5S8SMStore::mpacket_sm_1_i_4_r_6_t_4_cnt, S5S8SMStore::mpacket_sm_1_i_4_r_6_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_4_r_6_t_5_busy, S5S8SMStore::mpacket_sm_1_i_4_r_6_t_5_cnt, S5S8SMStore::mpacket_sm_1_i_4_r_6_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_4_r_6_t_6_busy, S5S8SMStore::mpacket_sm_1_i_4_r_6_t_6_cnt, S5S8SMStore::mpacket_sm_1_i_4_r_6_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_4_r_6_t_7_busy, S5S8SMStore::mpacket_sm_1_i_4_r_6_t_7_cnt, S5S8SMStore::mpacket_sm_1_i_4_r_6_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_4_r_6_t_8_busy, S5S8SMStore::mpacket_sm_1_i_4_r_6_t_8_cnt, S5S8SMStore::mpacket_sm_1_i_4_r_6_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_4_r_6_t_9_busy, S5S8SMStore::mpacket_sm_1_i_4_r_6_t_9_cnt, S5S8SMStore::mpacket_sm_1_i_4_r_6_t_9, msgObj);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_4_r_6_t_0_busy, S5S8SMStore::mpacket_sm_2_i_4_r_6_t_0_cnt, S5S8SMStore::mpacket_sm_2_i_4_r_6_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_4_r_6_t_1_busy, S5S8SMStore::mpacket_sm_2_i_4_r_6_t_1_cnt, S5S8SMStore::mpacket_sm_2_i_4_r_6_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_4_r_6_t_2_busy, S5S8SMStore::mpacket_sm_2_i_4_r_6_t_2_cnt, S5S8SMStore::mpacket_sm_2_i_4_r_6_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_4_r_6_t_3_busy, S5S8SMStore::mpacket_sm_2_i_4_r_6_t_3_cnt, S5S8SMStore::mpacket_sm_2_i_4_r_6_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_4_r_6_t_4_busy, S5S8SMStore::mpacket_sm_2_i_4_r_6_t_4_cnt, S5S8SMStore::mpacket_sm_2_i_4_r_6_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_4_r_6_t_5_busy, S5S8SMStore::mpacket_sm_2_i_4_r_6_t_5_cnt, S5S8SMStore::mpacket_sm_2_i_4_r_6_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_4_r_6_t_6_busy, S5S8SMStore::mpacket_sm_2_i_4_r_6_t_6_cnt, S5S8SMStore::mpacket_sm_2_i_4_r_6_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_4_r_6_t_7_busy, S5S8SMStore::mpacket_sm_2_i_4_r_6_t_7_cnt, S5S8SMStore::mpacket_sm_2_i_4_r_6_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_4_r_6_t_8_busy, S5S8SMStore::mpacket_sm_2_i_4_r_6_t_8_cnt, S5S8SMStore::mpacket_sm_2_i_4_r_6_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_4_r_6_t_9_busy, S5S8SMStore::mpacket_sm_2_i_4_r_6_t_9_cnt, S5S8SMStore::mpacket_sm_2_i_4_r_6_t_9, msgObj);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_4_r_6_t_0_busy, S5S8SMStore::mpacket_sm_3_i_4_r_6_t_0_cnt, S5S8SMStore::mpacket_sm_3_i_4_r_6_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_4_r_6_t_1_busy, S5S8SMStore::mpacket_sm_3_i_4_r_6_t_1_cnt, S5S8SMStore::mpacket_sm_3_i_4_r_6_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_4_r_6_t_2_busy, S5S8SMStore::mpacket_sm_3_i_4_r_6_t_2_cnt, S5S8SMStore::mpacket_sm_3_i_4_r_6_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_4_r_6_t_3_busy, S5S8SMStore::mpacket_sm_3_i_4_r_6_t_3_cnt, S5S8SMStore::mpacket_sm_3_i_4_r_6_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_4_r_6_t_4_busy, S5S8SMStore::mpacket_sm_3_i_4_r_6_t_4_cnt, S5S8SMStore::mpacket_sm_3_i_4_r_6_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_4_r_6_t_5_busy, S5S8SMStore::mpacket_sm_3_i_4_r_6_t_5_cnt, S5S8SMStore::mpacket_sm_3_i_4_r_6_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_4_r_6_t_6_busy, S5S8SMStore::mpacket_sm_3_i_4_r_6_t_6_cnt, S5S8SMStore::mpacket_sm_3_i_4_r_6_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_4_r_6_t_7_busy, S5S8SMStore::mpacket_sm_3_i_4_r_6_t_7_cnt, S5S8SMStore::mpacket_sm_3_i_4_r_6_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_4_r_6_t_8_busy, S5S8SMStore::mpacket_sm_3_i_4_r_6_t_8_cnt, S5S8SMStore::mpacket_sm_3_i_4_r_6_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_4_r_6_t_9_busy, S5S8SMStore::mpacket_sm_3_i_4_r_6_t_9_cnt, S5S8SMStore::mpacket_sm_3_i_4_r_6_t_9, msgObj);
				break;
			}
			break;
	}
}

VOID S5S8MessageBroker::pushToQueue_i_4_r_7(MPacket *msgObj, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_4_r_7_t_0_busy, S5S8SMStore::mpacket_sm_0_i_4_r_7_t_0_cnt, S5S8SMStore::mpacket_sm_0_i_4_r_7_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_4_r_7_t_1_busy, S5S8SMStore::mpacket_sm_0_i_4_r_7_t_1_cnt, S5S8SMStore::mpacket_sm_0_i_4_r_7_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_4_r_7_t_2_busy, S5S8SMStore::mpacket_sm_0_i_4_r_7_t_2_cnt, S5S8SMStore::mpacket_sm_0_i_4_r_7_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_4_r_7_t_3_busy, S5S8SMStore::mpacket_sm_0_i_4_r_7_t_3_cnt, S5S8SMStore::mpacket_sm_0_i_4_r_7_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_4_r_7_t_4_busy, S5S8SMStore::mpacket_sm_0_i_4_r_7_t_4_cnt, S5S8SMStore::mpacket_sm_0_i_4_r_7_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_4_r_7_t_5_busy, S5S8SMStore::mpacket_sm_0_i_4_r_7_t_5_cnt, S5S8SMStore::mpacket_sm_0_i_4_r_7_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_4_r_7_t_6_busy, S5S8SMStore::mpacket_sm_0_i_4_r_7_t_6_cnt, S5S8SMStore::mpacket_sm_0_i_4_r_7_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_4_r_7_t_7_busy, S5S8SMStore::mpacket_sm_0_i_4_r_7_t_7_cnt, S5S8SMStore::mpacket_sm_0_i_4_r_7_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_4_r_7_t_8_busy, S5S8SMStore::mpacket_sm_0_i_4_r_7_t_8_cnt, S5S8SMStore::mpacket_sm_0_i_4_r_7_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_4_r_7_t_9_busy, S5S8SMStore::mpacket_sm_0_i_4_r_7_t_9_cnt, S5S8SMStore::mpacket_sm_0_i_4_r_7_t_9, msgObj);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_4_r_7_t_0_busy, S5S8SMStore::mpacket_sm_1_i_4_r_7_t_0_cnt, S5S8SMStore::mpacket_sm_1_i_4_r_7_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_4_r_7_t_1_busy, S5S8SMStore::mpacket_sm_1_i_4_r_7_t_1_cnt, S5S8SMStore::mpacket_sm_1_i_4_r_7_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_4_r_7_t_2_busy, S5S8SMStore::mpacket_sm_1_i_4_r_7_t_2_cnt, S5S8SMStore::mpacket_sm_1_i_4_r_7_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_4_r_7_t_3_busy, S5S8SMStore::mpacket_sm_1_i_4_r_7_t_3_cnt, S5S8SMStore::mpacket_sm_1_i_4_r_7_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_4_r_7_t_4_busy, S5S8SMStore::mpacket_sm_1_i_4_r_7_t_4_cnt, S5S8SMStore::mpacket_sm_1_i_4_r_7_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_4_r_7_t_5_busy, S5S8SMStore::mpacket_sm_1_i_4_r_7_t_5_cnt, S5S8SMStore::mpacket_sm_1_i_4_r_7_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_4_r_7_t_6_busy, S5S8SMStore::mpacket_sm_1_i_4_r_7_t_6_cnt, S5S8SMStore::mpacket_sm_1_i_4_r_7_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_4_r_7_t_7_busy, S5S8SMStore::mpacket_sm_1_i_4_r_7_t_7_cnt, S5S8SMStore::mpacket_sm_1_i_4_r_7_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_4_r_7_t_8_busy, S5S8SMStore::mpacket_sm_1_i_4_r_7_t_8_cnt, S5S8SMStore::mpacket_sm_1_i_4_r_7_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_4_r_7_t_9_busy, S5S8SMStore::mpacket_sm_1_i_4_r_7_t_9_cnt, S5S8SMStore::mpacket_sm_1_i_4_r_7_t_9, msgObj);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_4_r_7_t_0_busy, S5S8SMStore::mpacket_sm_2_i_4_r_7_t_0_cnt, S5S8SMStore::mpacket_sm_2_i_4_r_7_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_4_r_7_t_1_busy, S5S8SMStore::mpacket_sm_2_i_4_r_7_t_1_cnt, S5S8SMStore::mpacket_sm_2_i_4_r_7_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_4_r_7_t_2_busy, S5S8SMStore::mpacket_sm_2_i_4_r_7_t_2_cnt, S5S8SMStore::mpacket_sm_2_i_4_r_7_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_4_r_7_t_3_busy, S5S8SMStore::mpacket_sm_2_i_4_r_7_t_3_cnt, S5S8SMStore::mpacket_sm_2_i_4_r_7_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_4_r_7_t_4_busy, S5S8SMStore::mpacket_sm_2_i_4_r_7_t_4_cnt, S5S8SMStore::mpacket_sm_2_i_4_r_7_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_4_r_7_t_5_busy, S5S8SMStore::mpacket_sm_2_i_4_r_7_t_5_cnt, S5S8SMStore::mpacket_sm_2_i_4_r_7_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_4_r_7_t_6_busy, S5S8SMStore::mpacket_sm_2_i_4_r_7_t_6_cnt, S5S8SMStore::mpacket_sm_2_i_4_r_7_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_4_r_7_t_7_busy, S5S8SMStore::mpacket_sm_2_i_4_r_7_t_7_cnt, S5S8SMStore::mpacket_sm_2_i_4_r_7_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_4_r_7_t_8_busy, S5S8SMStore::mpacket_sm_2_i_4_r_7_t_8_cnt, S5S8SMStore::mpacket_sm_2_i_4_r_7_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_4_r_7_t_9_busy, S5S8SMStore::mpacket_sm_2_i_4_r_7_t_9_cnt, S5S8SMStore::mpacket_sm_2_i_4_r_7_t_9, msgObj);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_4_r_7_t_0_busy, S5S8SMStore::mpacket_sm_3_i_4_r_7_t_0_cnt, S5S8SMStore::mpacket_sm_3_i_4_r_7_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_4_r_7_t_1_busy, S5S8SMStore::mpacket_sm_3_i_4_r_7_t_1_cnt, S5S8SMStore::mpacket_sm_3_i_4_r_7_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_4_r_7_t_2_busy, S5S8SMStore::mpacket_sm_3_i_4_r_7_t_2_cnt, S5S8SMStore::mpacket_sm_3_i_4_r_7_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_4_r_7_t_3_busy, S5S8SMStore::mpacket_sm_3_i_4_r_7_t_3_cnt, S5S8SMStore::mpacket_sm_3_i_4_r_7_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_4_r_7_t_4_busy, S5S8SMStore::mpacket_sm_3_i_4_r_7_t_4_cnt, S5S8SMStore::mpacket_sm_3_i_4_r_7_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_4_r_7_t_5_busy, S5S8SMStore::mpacket_sm_3_i_4_r_7_t_5_cnt, S5S8SMStore::mpacket_sm_3_i_4_r_7_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_4_r_7_t_6_busy, S5S8SMStore::mpacket_sm_3_i_4_r_7_t_6_cnt, S5S8SMStore::mpacket_sm_3_i_4_r_7_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_4_r_7_t_7_busy, S5S8SMStore::mpacket_sm_3_i_4_r_7_t_7_cnt, S5S8SMStore::mpacket_sm_3_i_4_r_7_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_4_r_7_t_8_busy, S5S8SMStore::mpacket_sm_3_i_4_r_7_t_8_cnt, S5S8SMStore::mpacket_sm_3_i_4_r_7_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_4_r_7_t_9_busy, S5S8SMStore::mpacket_sm_3_i_4_r_7_t_9_cnt, S5S8SMStore::mpacket_sm_3_i_4_r_7_t_9, msgObj);
				break;
			}
			break;
	}
}


VOID S5S8MessageBroker::pushToQueue_i_5_r_0(MPacket *msgObj, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_5_r_0_t_0_busy, S5S8SMStore::mpacket_sm_0_i_5_r_0_t_0_cnt, S5S8SMStore::mpacket_sm_0_i_5_r_0_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_5_r_0_t_1_busy, S5S8SMStore::mpacket_sm_0_i_5_r_0_t_1_cnt, S5S8SMStore::mpacket_sm_0_i_5_r_0_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_5_r_0_t_2_busy, S5S8SMStore::mpacket_sm_0_i_5_r_0_t_2_cnt, S5S8SMStore::mpacket_sm_0_i_5_r_0_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_5_r_0_t_3_busy, S5S8SMStore::mpacket_sm_0_i_5_r_0_t_3_cnt, S5S8SMStore::mpacket_sm_0_i_5_r_0_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_5_r_0_t_4_busy, S5S8SMStore::mpacket_sm_0_i_5_r_0_t_4_cnt, S5S8SMStore::mpacket_sm_0_i_5_r_0_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_5_r_0_t_5_busy, S5S8SMStore::mpacket_sm_0_i_5_r_0_t_5_cnt, S5S8SMStore::mpacket_sm_0_i_5_r_0_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_5_r_0_t_6_busy, S5S8SMStore::mpacket_sm_0_i_5_r_0_t_6_cnt, S5S8SMStore::mpacket_sm_0_i_5_r_0_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_5_r_0_t_7_busy, S5S8SMStore::mpacket_sm_0_i_5_r_0_t_7_cnt, S5S8SMStore::mpacket_sm_0_i_5_r_0_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_5_r_0_t_8_busy, S5S8SMStore::mpacket_sm_0_i_5_r_0_t_8_cnt, S5S8SMStore::mpacket_sm_0_i_5_r_0_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_5_r_0_t_9_busy, S5S8SMStore::mpacket_sm_0_i_5_r_0_t_9_cnt, S5S8SMStore::mpacket_sm_0_i_5_r_0_t_9, msgObj);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_5_r_0_t_0_busy, S5S8SMStore::mpacket_sm_1_i_5_r_0_t_0_cnt, S5S8SMStore::mpacket_sm_1_i_5_r_0_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_5_r_0_t_1_busy, S5S8SMStore::mpacket_sm_1_i_5_r_0_t_1_cnt, S5S8SMStore::mpacket_sm_1_i_5_r_0_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_5_r_0_t_2_busy, S5S8SMStore::mpacket_sm_1_i_5_r_0_t_2_cnt, S5S8SMStore::mpacket_sm_1_i_5_r_0_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_5_r_0_t_3_busy, S5S8SMStore::mpacket_sm_1_i_5_r_0_t_3_cnt, S5S8SMStore::mpacket_sm_1_i_5_r_0_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_5_r_0_t_4_busy, S5S8SMStore::mpacket_sm_1_i_5_r_0_t_4_cnt, S5S8SMStore::mpacket_sm_1_i_5_r_0_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_5_r_0_t_5_busy, S5S8SMStore::mpacket_sm_1_i_5_r_0_t_5_cnt, S5S8SMStore::mpacket_sm_1_i_5_r_0_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_5_r_0_t_6_busy, S5S8SMStore::mpacket_sm_1_i_5_r_0_t_6_cnt, S5S8SMStore::mpacket_sm_1_i_5_r_0_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_5_r_0_t_7_busy, S5S8SMStore::mpacket_sm_1_i_5_r_0_t_7_cnt, S5S8SMStore::mpacket_sm_1_i_5_r_0_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_5_r_0_t_8_busy, S5S8SMStore::mpacket_sm_1_i_5_r_0_t_8_cnt, S5S8SMStore::mpacket_sm_1_i_5_r_0_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_5_r_0_t_9_busy, S5S8SMStore::mpacket_sm_1_i_5_r_0_t_9_cnt, S5S8SMStore::mpacket_sm_1_i_5_r_0_t_9, msgObj);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_5_r_0_t_0_busy, S5S8SMStore::mpacket_sm_2_i_5_r_0_t_0_cnt, S5S8SMStore::mpacket_sm_2_i_5_r_0_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_5_r_0_t_1_busy, S5S8SMStore::mpacket_sm_2_i_5_r_0_t_1_cnt, S5S8SMStore::mpacket_sm_2_i_5_r_0_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_5_r_0_t_2_busy, S5S8SMStore::mpacket_sm_2_i_5_r_0_t_2_cnt, S5S8SMStore::mpacket_sm_2_i_5_r_0_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_5_r_0_t_3_busy, S5S8SMStore::mpacket_sm_2_i_5_r_0_t_3_cnt, S5S8SMStore::mpacket_sm_2_i_5_r_0_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_5_r_0_t_4_busy, S5S8SMStore::mpacket_sm_2_i_5_r_0_t_4_cnt, S5S8SMStore::mpacket_sm_2_i_5_r_0_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_5_r_0_t_5_busy, S5S8SMStore::mpacket_sm_2_i_5_r_0_t_5_cnt, S5S8SMStore::mpacket_sm_2_i_5_r_0_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_5_r_0_t_6_busy, S5S8SMStore::mpacket_sm_2_i_5_r_0_t_6_cnt, S5S8SMStore::mpacket_sm_2_i_5_r_0_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_5_r_0_t_7_busy, S5S8SMStore::mpacket_sm_2_i_5_r_0_t_7_cnt, S5S8SMStore::mpacket_sm_2_i_5_r_0_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_5_r_0_t_8_busy, S5S8SMStore::mpacket_sm_2_i_5_r_0_t_8_cnt, S5S8SMStore::mpacket_sm_2_i_5_r_0_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_5_r_0_t_9_busy, S5S8SMStore::mpacket_sm_2_i_5_r_0_t_9_cnt, S5S8SMStore::mpacket_sm_2_i_5_r_0_t_9, msgObj);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_5_r_0_t_0_busy, S5S8SMStore::mpacket_sm_3_i_5_r_0_t_0_cnt, S5S8SMStore::mpacket_sm_3_i_5_r_0_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_5_r_0_t_1_busy, S5S8SMStore::mpacket_sm_3_i_5_r_0_t_1_cnt, S5S8SMStore::mpacket_sm_3_i_5_r_0_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_5_r_0_t_2_busy, S5S8SMStore::mpacket_sm_3_i_5_r_0_t_2_cnt, S5S8SMStore::mpacket_sm_3_i_5_r_0_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_5_r_0_t_3_busy, S5S8SMStore::mpacket_sm_3_i_5_r_0_t_3_cnt, S5S8SMStore::mpacket_sm_3_i_5_r_0_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_5_r_0_t_4_busy, S5S8SMStore::mpacket_sm_3_i_5_r_0_t_4_cnt, S5S8SMStore::mpacket_sm_3_i_5_r_0_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_5_r_0_t_5_busy, S5S8SMStore::mpacket_sm_3_i_5_r_0_t_5_cnt, S5S8SMStore::mpacket_sm_3_i_5_r_0_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_5_r_0_t_6_busy, S5S8SMStore::mpacket_sm_3_i_5_r_0_t_6_cnt, S5S8SMStore::mpacket_sm_3_i_5_r_0_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_5_r_0_t_7_busy, S5S8SMStore::mpacket_sm_3_i_5_r_0_t_7_cnt, S5S8SMStore::mpacket_sm_3_i_5_r_0_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_5_r_0_t_8_busy, S5S8SMStore::mpacket_sm_3_i_5_r_0_t_8_cnt, S5S8SMStore::mpacket_sm_3_i_5_r_0_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_5_r_0_t_9_busy, S5S8SMStore::mpacket_sm_3_i_5_r_0_t_9_cnt, S5S8SMStore::mpacket_sm_3_i_5_r_0_t_9, msgObj);
				break;
			}
			break;
	}
}

VOID S5S8MessageBroker::pushToQueue_i_5_r_1(MPacket *msgObj, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_5_r_1_t_0_busy, S5S8SMStore::mpacket_sm_0_i_5_r_1_t_0_cnt, S5S8SMStore::mpacket_sm_0_i_5_r_1_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_5_r_1_t_1_busy, S5S8SMStore::mpacket_sm_0_i_5_r_1_t_1_cnt, S5S8SMStore::mpacket_sm_0_i_5_r_1_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_5_r_1_t_2_busy, S5S8SMStore::mpacket_sm_0_i_5_r_1_t_2_cnt, S5S8SMStore::mpacket_sm_0_i_5_r_1_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_5_r_1_t_3_busy, S5S8SMStore::mpacket_sm_0_i_5_r_1_t_3_cnt, S5S8SMStore::mpacket_sm_0_i_5_r_1_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_5_r_1_t_4_busy, S5S8SMStore::mpacket_sm_0_i_5_r_1_t_4_cnt, S5S8SMStore::mpacket_sm_0_i_5_r_1_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_5_r_1_t_5_busy, S5S8SMStore::mpacket_sm_0_i_5_r_1_t_5_cnt, S5S8SMStore::mpacket_sm_0_i_5_r_1_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_5_r_1_t_6_busy, S5S8SMStore::mpacket_sm_0_i_5_r_1_t_6_cnt, S5S8SMStore::mpacket_sm_0_i_5_r_1_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_5_r_1_t_7_busy, S5S8SMStore::mpacket_sm_0_i_5_r_1_t_7_cnt, S5S8SMStore::mpacket_sm_0_i_5_r_1_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_5_r_1_t_8_busy, S5S8SMStore::mpacket_sm_0_i_5_r_1_t_8_cnt, S5S8SMStore::mpacket_sm_0_i_5_r_1_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_5_r_1_t_9_busy, S5S8SMStore::mpacket_sm_0_i_5_r_1_t_9_cnt, S5S8SMStore::mpacket_sm_0_i_5_r_1_t_9, msgObj);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_5_r_1_t_0_busy, S5S8SMStore::mpacket_sm_1_i_5_r_1_t_0_cnt, S5S8SMStore::mpacket_sm_1_i_5_r_1_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_5_r_1_t_1_busy, S5S8SMStore::mpacket_sm_1_i_5_r_1_t_1_cnt, S5S8SMStore::mpacket_sm_1_i_5_r_1_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_5_r_1_t_2_busy, S5S8SMStore::mpacket_sm_1_i_5_r_1_t_2_cnt, S5S8SMStore::mpacket_sm_1_i_5_r_1_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_5_r_1_t_3_busy, S5S8SMStore::mpacket_sm_1_i_5_r_1_t_3_cnt, S5S8SMStore::mpacket_sm_1_i_5_r_1_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_5_r_1_t_4_busy, S5S8SMStore::mpacket_sm_1_i_5_r_1_t_4_cnt, S5S8SMStore::mpacket_sm_1_i_5_r_1_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_5_r_1_t_5_busy, S5S8SMStore::mpacket_sm_1_i_5_r_1_t_5_cnt, S5S8SMStore::mpacket_sm_1_i_5_r_1_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_5_r_1_t_6_busy, S5S8SMStore::mpacket_sm_1_i_5_r_1_t_6_cnt, S5S8SMStore::mpacket_sm_1_i_5_r_1_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_5_r_1_t_7_busy, S5S8SMStore::mpacket_sm_1_i_5_r_1_t_7_cnt, S5S8SMStore::mpacket_sm_1_i_5_r_1_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_5_r_1_t_8_busy, S5S8SMStore::mpacket_sm_1_i_5_r_1_t_8_cnt, S5S8SMStore::mpacket_sm_1_i_5_r_1_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_5_r_1_t_9_busy, S5S8SMStore::mpacket_sm_1_i_5_r_1_t_9_cnt, S5S8SMStore::mpacket_sm_1_i_5_r_1_t_9, msgObj);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_5_r_1_t_0_busy, S5S8SMStore::mpacket_sm_2_i_5_r_1_t_0_cnt, S5S8SMStore::mpacket_sm_2_i_5_r_1_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_5_r_1_t_1_busy, S5S8SMStore::mpacket_sm_2_i_5_r_1_t_1_cnt, S5S8SMStore::mpacket_sm_2_i_5_r_1_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_5_r_1_t_2_busy, S5S8SMStore::mpacket_sm_2_i_5_r_1_t_2_cnt, S5S8SMStore::mpacket_sm_2_i_5_r_1_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_5_r_1_t_3_busy, S5S8SMStore::mpacket_sm_2_i_5_r_1_t_3_cnt, S5S8SMStore::mpacket_sm_2_i_5_r_1_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_5_r_1_t_4_busy, S5S8SMStore::mpacket_sm_2_i_5_r_1_t_4_cnt, S5S8SMStore::mpacket_sm_2_i_5_r_1_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_5_r_1_t_5_busy, S5S8SMStore::mpacket_sm_2_i_5_r_1_t_5_cnt, S5S8SMStore::mpacket_sm_2_i_5_r_1_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_5_r_1_t_6_busy, S5S8SMStore::mpacket_sm_2_i_5_r_1_t_6_cnt, S5S8SMStore::mpacket_sm_2_i_5_r_1_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_5_r_1_t_7_busy, S5S8SMStore::mpacket_sm_2_i_5_r_1_t_7_cnt, S5S8SMStore::mpacket_sm_2_i_5_r_1_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_5_r_1_t_8_busy, S5S8SMStore::mpacket_sm_2_i_5_r_1_t_8_cnt, S5S8SMStore::mpacket_sm_2_i_5_r_1_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_5_r_1_t_9_busy, S5S8SMStore::mpacket_sm_2_i_5_r_1_t_9_cnt, S5S8SMStore::mpacket_sm_2_i_5_r_1_t_9, msgObj);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_5_r_1_t_0_busy, S5S8SMStore::mpacket_sm_3_i_5_r_1_t_0_cnt, S5S8SMStore::mpacket_sm_3_i_5_r_1_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_5_r_1_t_1_busy, S5S8SMStore::mpacket_sm_3_i_5_r_1_t_1_cnt, S5S8SMStore::mpacket_sm_3_i_5_r_1_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_5_r_1_t_2_busy, S5S8SMStore::mpacket_sm_3_i_5_r_1_t_2_cnt, S5S8SMStore::mpacket_sm_3_i_5_r_1_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_5_r_1_t_3_busy, S5S8SMStore::mpacket_sm_3_i_5_r_1_t_3_cnt, S5S8SMStore::mpacket_sm_3_i_5_r_1_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_5_r_1_t_4_busy, S5S8SMStore::mpacket_sm_3_i_5_r_1_t_4_cnt, S5S8SMStore::mpacket_sm_3_i_5_r_1_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_5_r_1_t_5_busy, S5S8SMStore::mpacket_sm_3_i_5_r_1_t_5_cnt, S5S8SMStore::mpacket_sm_3_i_5_r_1_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_5_r_1_t_6_busy, S5S8SMStore::mpacket_sm_3_i_5_r_1_t_6_cnt, S5S8SMStore::mpacket_sm_3_i_5_r_1_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_5_r_1_t_7_busy, S5S8SMStore::mpacket_sm_3_i_5_r_1_t_7_cnt, S5S8SMStore::mpacket_sm_3_i_5_r_1_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_5_r_1_t_8_busy, S5S8SMStore::mpacket_sm_3_i_5_r_1_t_8_cnt, S5S8SMStore::mpacket_sm_3_i_5_r_1_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_5_r_1_t_9_busy, S5S8SMStore::mpacket_sm_3_i_5_r_1_t_9_cnt, S5S8SMStore::mpacket_sm_3_i_5_r_1_t_9, msgObj);
				break;
			}
			break;
	}
}

VOID S5S8MessageBroker::pushToQueue_i_5_r_2(MPacket *msgObj, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_5_r_2_t_0_busy, S5S8SMStore::mpacket_sm_0_i_5_r_2_t_0_cnt, S5S8SMStore::mpacket_sm_0_i_5_r_2_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_5_r_2_t_1_busy, S5S8SMStore::mpacket_sm_0_i_5_r_2_t_1_cnt, S5S8SMStore::mpacket_sm_0_i_5_r_2_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_5_r_2_t_2_busy, S5S8SMStore::mpacket_sm_0_i_5_r_2_t_2_cnt, S5S8SMStore::mpacket_sm_0_i_5_r_2_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_5_r_2_t_3_busy, S5S8SMStore::mpacket_sm_0_i_5_r_2_t_3_cnt, S5S8SMStore::mpacket_sm_0_i_5_r_2_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_5_r_2_t_4_busy, S5S8SMStore::mpacket_sm_0_i_5_r_2_t_4_cnt, S5S8SMStore::mpacket_sm_0_i_5_r_2_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_5_r_2_t_5_busy, S5S8SMStore::mpacket_sm_0_i_5_r_2_t_5_cnt, S5S8SMStore::mpacket_sm_0_i_5_r_2_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_5_r_2_t_6_busy, S5S8SMStore::mpacket_sm_0_i_5_r_2_t_6_cnt, S5S8SMStore::mpacket_sm_0_i_5_r_2_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_5_r_2_t_7_busy, S5S8SMStore::mpacket_sm_0_i_5_r_2_t_7_cnt, S5S8SMStore::mpacket_sm_0_i_5_r_2_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_5_r_2_t_8_busy, S5S8SMStore::mpacket_sm_0_i_5_r_2_t_8_cnt, S5S8SMStore::mpacket_sm_0_i_5_r_2_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_5_r_2_t_9_busy, S5S8SMStore::mpacket_sm_0_i_5_r_2_t_9_cnt, S5S8SMStore::mpacket_sm_0_i_5_r_2_t_9, msgObj);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_5_r_2_t_0_busy, S5S8SMStore::mpacket_sm_1_i_5_r_2_t_0_cnt, S5S8SMStore::mpacket_sm_1_i_5_r_2_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_5_r_2_t_1_busy, S5S8SMStore::mpacket_sm_1_i_5_r_2_t_1_cnt, S5S8SMStore::mpacket_sm_1_i_5_r_2_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_5_r_2_t_2_busy, S5S8SMStore::mpacket_sm_1_i_5_r_2_t_2_cnt, S5S8SMStore::mpacket_sm_1_i_5_r_2_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_5_r_2_t_3_busy, S5S8SMStore::mpacket_sm_1_i_5_r_2_t_3_cnt, S5S8SMStore::mpacket_sm_1_i_5_r_2_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_5_r_2_t_4_busy, S5S8SMStore::mpacket_sm_1_i_5_r_2_t_4_cnt, S5S8SMStore::mpacket_sm_1_i_5_r_2_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_5_r_2_t_5_busy, S5S8SMStore::mpacket_sm_1_i_5_r_2_t_5_cnt, S5S8SMStore::mpacket_sm_1_i_5_r_2_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_5_r_2_t_6_busy, S5S8SMStore::mpacket_sm_1_i_5_r_2_t_6_cnt, S5S8SMStore::mpacket_sm_1_i_5_r_2_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_5_r_2_t_7_busy, S5S8SMStore::mpacket_sm_1_i_5_r_2_t_7_cnt, S5S8SMStore::mpacket_sm_1_i_5_r_2_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_5_r_2_t_8_busy, S5S8SMStore::mpacket_sm_1_i_5_r_2_t_8_cnt, S5S8SMStore::mpacket_sm_1_i_5_r_2_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_5_r_2_t_9_busy, S5S8SMStore::mpacket_sm_1_i_5_r_2_t_9_cnt, S5S8SMStore::mpacket_sm_1_i_5_r_2_t_9, msgObj);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_5_r_2_t_0_busy, S5S8SMStore::mpacket_sm_2_i_5_r_2_t_0_cnt, S5S8SMStore::mpacket_sm_2_i_5_r_2_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_5_r_2_t_1_busy, S5S8SMStore::mpacket_sm_2_i_5_r_2_t_1_cnt, S5S8SMStore::mpacket_sm_2_i_5_r_2_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_5_r_2_t_2_busy, S5S8SMStore::mpacket_sm_2_i_5_r_2_t_2_cnt, S5S8SMStore::mpacket_sm_2_i_5_r_2_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_5_r_2_t_3_busy, S5S8SMStore::mpacket_sm_2_i_5_r_2_t_3_cnt, S5S8SMStore::mpacket_sm_2_i_5_r_2_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_5_r_2_t_4_busy, S5S8SMStore::mpacket_sm_2_i_5_r_2_t_4_cnt, S5S8SMStore::mpacket_sm_2_i_5_r_2_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_5_r_2_t_5_busy, S5S8SMStore::mpacket_sm_2_i_5_r_2_t_5_cnt, S5S8SMStore::mpacket_sm_2_i_5_r_2_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_5_r_2_t_6_busy, S5S8SMStore::mpacket_sm_2_i_5_r_2_t_6_cnt, S5S8SMStore::mpacket_sm_2_i_5_r_2_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_5_r_2_t_7_busy, S5S8SMStore::mpacket_sm_2_i_5_r_2_t_7_cnt, S5S8SMStore::mpacket_sm_2_i_5_r_2_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_5_r_2_t_8_busy, S5S8SMStore::mpacket_sm_2_i_5_r_2_t_8_cnt, S5S8SMStore::mpacket_sm_2_i_5_r_2_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_5_r_2_t_9_busy, S5S8SMStore::mpacket_sm_2_i_5_r_2_t_9_cnt, S5S8SMStore::mpacket_sm_2_i_5_r_2_t_9, msgObj);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_5_r_2_t_0_busy, S5S8SMStore::mpacket_sm_3_i_5_r_2_t_0_cnt, S5S8SMStore::mpacket_sm_3_i_5_r_2_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_5_r_2_t_1_busy, S5S8SMStore::mpacket_sm_3_i_5_r_2_t_1_cnt, S5S8SMStore::mpacket_sm_3_i_5_r_2_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_5_r_2_t_2_busy, S5S8SMStore::mpacket_sm_3_i_5_r_2_t_2_cnt, S5S8SMStore::mpacket_sm_3_i_5_r_2_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_5_r_2_t_3_busy, S5S8SMStore::mpacket_sm_3_i_5_r_2_t_3_cnt, S5S8SMStore::mpacket_sm_3_i_5_r_2_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_5_r_2_t_4_busy, S5S8SMStore::mpacket_sm_3_i_5_r_2_t_4_cnt, S5S8SMStore::mpacket_sm_3_i_5_r_2_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_5_r_2_t_5_busy, S5S8SMStore::mpacket_sm_3_i_5_r_2_t_5_cnt, S5S8SMStore::mpacket_sm_3_i_5_r_2_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_5_r_2_t_6_busy, S5S8SMStore::mpacket_sm_3_i_5_r_2_t_6_cnt, S5S8SMStore::mpacket_sm_3_i_5_r_2_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_5_r_2_t_7_busy, S5S8SMStore::mpacket_sm_3_i_5_r_2_t_7_cnt, S5S8SMStore::mpacket_sm_3_i_5_r_2_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_5_r_2_t_8_busy, S5S8SMStore::mpacket_sm_3_i_5_r_2_t_8_cnt, S5S8SMStore::mpacket_sm_3_i_5_r_2_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_5_r_2_t_9_busy, S5S8SMStore::mpacket_sm_3_i_5_r_2_t_9_cnt, S5S8SMStore::mpacket_sm_3_i_5_r_2_t_9, msgObj);
				break;
			}
			break;
	}
}

VOID S5S8MessageBroker::pushToQueue_i_5_r_3(MPacket *msgObj, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_5_r_3_t_0_busy, S5S8SMStore::mpacket_sm_0_i_5_r_3_t_0_cnt, S5S8SMStore::mpacket_sm_0_i_5_r_3_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_5_r_3_t_1_busy, S5S8SMStore::mpacket_sm_0_i_5_r_3_t_1_cnt, S5S8SMStore::mpacket_sm_0_i_5_r_3_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_5_r_3_t_2_busy, S5S8SMStore::mpacket_sm_0_i_5_r_3_t_2_cnt, S5S8SMStore::mpacket_sm_0_i_5_r_3_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_5_r_3_t_3_busy, S5S8SMStore::mpacket_sm_0_i_5_r_3_t_3_cnt, S5S8SMStore::mpacket_sm_0_i_5_r_3_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_5_r_3_t_4_busy, S5S8SMStore::mpacket_sm_0_i_5_r_3_t_4_cnt, S5S8SMStore::mpacket_sm_0_i_5_r_3_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_5_r_3_t_5_busy, S5S8SMStore::mpacket_sm_0_i_5_r_3_t_5_cnt, S5S8SMStore::mpacket_sm_0_i_5_r_3_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_5_r_3_t_6_busy, S5S8SMStore::mpacket_sm_0_i_5_r_3_t_6_cnt, S5S8SMStore::mpacket_sm_0_i_5_r_3_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_5_r_3_t_7_busy, S5S8SMStore::mpacket_sm_0_i_5_r_3_t_7_cnt, S5S8SMStore::mpacket_sm_0_i_5_r_3_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_5_r_3_t_8_busy, S5S8SMStore::mpacket_sm_0_i_5_r_3_t_8_cnt, S5S8SMStore::mpacket_sm_0_i_5_r_3_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_5_r_3_t_9_busy, S5S8SMStore::mpacket_sm_0_i_5_r_3_t_9_cnt, S5S8SMStore::mpacket_sm_0_i_5_r_3_t_9, msgObj);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_5_r_3_t_0_busy, S5S8SMStore::mpacket_sm_1_i_5_r_3_t_0_cnt, S5S8SMStore::mpacket_sm_1_i_5_r_3_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_5_r_3_t_1_busy, S5S8SMStore::mpacket_sm_1_i_5_r_3_t_1_cnt, S5S8SMStore::mpacket_sm_1_i_5_r_3_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_5_r_3_t_2_busy, S5S8SMStore::mpacket_sm_1_i_5_r_3_t_2_cnt, S5S8SMStore::mpacket_sm_1_i_5_r_3_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_5_r_3_t_3_busy, S5S8SMStore::mpacket_sm_1_i_5_r_3_t_3_cnt, S5S8SMStore::mpacket_sm_1_i_5_r_3_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_5_r_3_t_4_busy, S5S8SMStore::mpacket_sm_1_i_5_r_3_t_4_cnt, S5S8SMStore::mpacket_sm_1_i_5_r_3_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_5_r_3_t_5_busy, S5S8SMStore::mpacket_sm_1_i_5_r_3_t_5_cnt, S5S8SMStore::mpacket_sm_1_i_5_r_3_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_5_r_3_t_6_busy, S5S8SMStore::mpacket_sm_1_i_5_r_3_t_6_cnt, S5S8SMStore::mpacket_sm_1_i_5_r_3_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_5_r_3_t_7_busy, S5S8SMStore::mpacket_sm_1_i_5_r_3_t_7_cnt, S5S8SMStore::mpacket_sm_1_i_5_r_3_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_5_r_3_t_8_busy, S5S8SMStore::mpacket_sm_1_i_5_r_3_t_8_cnt, S5S8SMStore::mpacket_sm_1_i_5_r_3_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_5_r_3_t_9_busy, S5S8SMStore::mpacket_sm_1_i_5_r_3_t_9_cnt, S5S8SMStore::mpacket_sm_1_i_5_r_3_t_9, msgObj);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_5_r_3_t_0_busy, S5S8SMStore::mpacket_sm_2_i_5_r_3_t_0_cnt, S5S8SMStore::mpacket_sm_2_i_5_r_3_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_5_r_3_t_1_busy, S5S8SMStore::mpacket_sm_2_i_5_r_3_t_1_cnt, S5S8SMStore::mpacket_sm_2_i_5_r_3_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_5_r_3_t_2_busy, S5S8SMStore::mpacket_sm_2_i_5_r_3_t_2_cnt, S5S8SMStore::mpacket_sm_2_i_5_r_3_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_5_r_3_t_3_busy, S5S8SMStore::mpacket_sm_2_i_5_r_3_t_3_cnt, S5S8SMStore::mpacket_sm_2_i_5_r_3_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_5_r_3_t_4_busy, S5S8SMStore::mpacket_sm_2_i_5_r_3_t_4_cnt, S5S8SMStore::mpacket_sm_2_i_5_r_3_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_5_r_3_t_5_busy, S5S8SMStore::mpacket_sm_2_i_5_r_3_t_5_cnt, S5S8SMStore::mpacket_sm_2_i_5_r_3_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_5_r_3_t_6_busy, S5S8SMStore::mpacket_sm_2_i_5_r_3_t_6_cnt, S5S8SMStore::mpacket_sm_2_i_5_r_3_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_5_r_3_t_7_busy, S5S8SMStore::mpacket_sm_2_i_5_r_3_t_7_cnt, S5S8SMStore::mpacket_sm_2_i_5_r_3_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_5_r_3_t_8_busy, S5S8SMStore::mpacket_sm_2_i_5_r_3_t_8_cnt, S5S8SMStore::mpacket_sm_2_i_5_r_3_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_5_r_3_t_9_busy, S5S8SMStore::mpacket_sm_2_i_5_r_3_t_9_cnt, S5S8SMStore::mpacket_sm_2_i_5_r_3_t_9, msgObj);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_5_r_3_t_0_busy, S5S8SMStore::mpacket_sm_3_i_5_r_3_t_0_cnt, S5S8SMStore::mpacket_sm_3_i_5_r_3_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_5_r_3_t_1_busy, S5S8SMStore::mpacket_sm_3_i_5_r_3_t_1_cnt, S5S8SMStore::mpacket_sm_3_i_5_r_3_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_5_r_3_t_2_busy, S5S8SMStore::mpacket_sm_3_i_5_r_3_t_2_cnt, S5S8SMStore::mpacket_sm_3_i_5_r_3_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_5_r_3_t_3_busy, S5S8SMStore::mpacket_sm_3_i_5_r_3_t_3_cnt, S5S8SMStore::mpacket_sm_3_i_5_r_3_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_5_r_3_t_4_busy, S5S8SMStore::mpacket_sm_3_i_5_r_3_t_4_cnt, S5S8SMStore::mpacket_sm_3_i_5_r_3_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_5_r_3_t_5_busy, S5S8SMStore::mpacket_sm_3_i_5_r_3_t_5_cnt, S5S8SMStore::mpacket_sm_3_i_5_r_3_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_5_r_3_t_6_busy, S5S8SMStore::mpacket_sm_3_i_5_r_3_t_6_cnt, S5S8SMStore::mpacket_sm_3_i_5_r_3_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_5_r_3_t_7_busy, S5S8SMStore::mpacket_sm_3_i_5_r_3_t_7_cnt, S5S8SMStore::mpacket_sm_3_i_5_r_3_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_5_r_3_t_8_busy, S5S8SMStore::mpacket_sm_3_i_5_r_3_t_8_cnt, S5S8SMStore::mpacket_sm_3_i_5_r_3_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_5_r_3_t_9_busy, S5S8SMStore::mpacket_sm_3_i_5_r_3_t_9_cnt, S5S8SMStore::mpacket_sm_3_i_5_r_3_t_9, msgObj);
				break;
			}
			break;
	}
}

VOID S5S8MessageBroker::pushToQueue_i_5_r_4(MPacket *msgObj, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_5_r_4_t_0_busy, S5S8SMStore::mpacket_sm_0_i_5_r_4_t_0_cnt, S5S8SMStore::mpacket_sm_0_i_5_r_4_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_5_r_4_t_1_busy, S5S8SMStore::mpacket_sm_0_i_5_r_4_t_1_cnt, S5S8SMStore::mpacket_sm_0_i_5_r_4_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_5_r_4_t_2_busy, S5S8SMStore::mpacket_sm_0_i_5_r_4_t_2_cnt, S5S8SMStore::mpacket_sm_0_i_5_r_4_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_5_r_4_t_3_busy, S5S8SMStore::mpacket_sm_0_i_5_r_4_t_3_cnt, S5S8SMStore::mpacket_sm_0_i_5_r_4_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_5_r_4_t_4_busy, S5S8SMStore::mpacket_sm_0_i_5_r_4_t_4_cnt, S5S8SMStore::mpacket_sm_0_i_5_r_4_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_5_r_4_t_5_busy, S5S8SMStore::mpacket_sm_0_i_5_r_4_t_5_cnt, S5S8SMStore::mpacket_sm_0_i_5_r_4_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_5_r_4_t_6_busy, S5S8SMStore::mpacket_sm_0_i_5_r_4_t_6_cnt, S5S8SMStore::mpacket_sm_0_i_5_r_4_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_5_r_4_t_7_busy, S5S8SMStore::mpacket_sm_0_i_5_r_4_t_7_cnt, S5S8SMStore::mpacket_sm_0_i_5_r_4_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_5_r_4_t_8_busy, S5S8SMStore::mpacket_sm_0_i_5_r_4_t_8_cnt, S5S8SMStore::mpacket_sm_0_i_5_r_4_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_5_r_4_t_9_busy, S5S8SMStore::mpacket_sm_0_i_5_r_4_t_9_cnt, S5S8SMStore::mpacket_sm_0_i_5_r_4_t_9, msgObj);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_5_r_4_t_0_busy, S5S8SMStore::mpacket_sm_1_i_5_r_4_t_0_cnt, S5S8SMStore::mpacket_sm_1_i_5_r_4_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_5_r_4_t_1_busy, S5S8SMStore::mpacket_sm_1_i_5_r_4_t_1_cnt, S5S8SMStore::mpacket_sm_1_i_5_r_4_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_5_r_4_t_2_busy, S5S8SMStore::mpacket_sm_1_i_5_r_4_t_2_cnt, S5S8SMStore::mpacket_sm_1_i_5_r_4_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_5_r_4_t_3_busy, S5S8SMStore::mpacket_sm_1_i_5_r_4_t_3_cnt, S5S8SMStore::mpacket_sm_1_i_5_r_4_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_5_r_4_t_4_busy, S5S8SMStore::mpacket_sm_1_i_5_r_4_t_4_cnt, S5S8SMStore::mpacket_sm_1_i_5_r_4_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_5_r_4_t_5_busy, S5S8SMStore::mpacket_sm_1_i_5_r_4_t_5_cnt, S5S8SMStore::mpacket_sm_1_i_5_r_4_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_5_r_4_t_6_busy, S5S8SMStore::mpacket_sm_1_i_5_r_4_t_6_cnt, S5S8SMStore::mpacket_sm_1_i_5_r_4_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_5_r_4_t_7_busy, S5S8SMStore::mpacket_sm_1_i_5_r_4_t_7_cnt, S5S8SMStore::mpacket_sm_1_i_5_r_4_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_5_r_4_t_8_busy, S5S8SMStore::mpacket_sm_1_i_5_r_4_t_8_cnt, S5S8SMStore::mpacket_sm_1_i_5_r_4_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_5_r_4_t_9_busy, S5S8SMStore::mpacket_sm_1_i_5_r_4_t_9_cnt, S5S8SMStore::mpacket_sm_1_i_5_r_4_t_9, msgObj);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_5_r_4_t_0_busy, S5S8SMStore::mpacket_sm_2_i_5_r_4_t_0_cnt, S5S8SMStore::mpacket_sm_2_i_5_r_4_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_5_r_4_t_1_busy, S5S8SMStore::mpacket_sm_2_i_5_r_4_t_1_cnt, S5S8SMStore::mpacket_sm_2_i_5_r_4_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_5_r_4_t_2_busy, S5S8SMStore::mpacket_sm_2_i_5_r_4_t_2_cnt, S5S8SMStore::mpacket_sm_2_i_5_r_4_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_5_r_4_t_3_busy, S5S8SMStore::mpacket_sm_2_i_5_r_4_t_3_cnt, S5S8SMStore::mpacket_sm_2_i_5_r_4_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_5_r_4_t_4_busy, S5S8SMStore::mpacket_sm_2_i_5_r_4_t_4_cnt, S5S8SMStore::mpacket_sm_2_i_5_r_4_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_5_r_4_t_5_busy, S5S8SMStore::mpacket_sm_2_i_5_r_4_t_5_cnt, S5S8SMStore::mpacket_sm_2_i_5_r_4_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_5_r_4_t_6_busy, S5S8SMStore::mpacket_sm_2_i_5_r_4_t_6_cnt, S5S8SMStore::mpacket_sm_2_i_5_r_4_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_5_r_4_t_7_busy, S5S8SMStore::mpacket_sm_2_i_5_r_4_t_7_cnt, S5S8SMStore::mpacket_sm_2_i_5_r_4_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_5_r_4_t_8_busy, S5S8SMStore::mpacket_sm_2_i_5_r_4_t_8_cnt, S5S8SMStore::mpacket_sm_2_i_5_r_4_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_5_r_4_t_9_busy, S5S8SMStore::mpacket_sm_2_i_5_r_4_t_9_cnt, S5S8SMStore::mpacket_sm_2_i_5_r_4_t_9, msgObj);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_5_r_4_t_0_busy, S5S8SMStore::mpacket_sm_3_i_5_r_4_t_0_cnt, S5S8SMStore::mpacket_sm_3_i_5_r_4_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_5_r_4_t_1_busy, S5S8SMStore::mpacket_sm_3_i_5_r_4_t_1_cnt, S5S8SMStore::mpacket_sm_3_i_5_r_4_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_5_r_4_t_2_busy, S5S8SMStore::mpacket_sm_3_i_5_r_4_t_2_cnt, S5S8SMStore::mpacket_sm_3_i_5_r_4_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_5_r_4_t_3_busy, S5S8SMStore::mpacket_sm_3_i_5_r_4_t_3_cnt, S5S8SMStore::mpacket_sm_3_i_5_r_4_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_5_r_4_t_4_busy, S5S8SMStore::mpacket_sm_3_i_5_r_4_t_4_cnt, S5S8SMStore::mpacket_sm_3_i_5_r_4_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_5_r_4_t_5_busy, S5S8SMStore::mpacket_sm_3_i_5_r_4_t_5_cnt, S5S8SMStore::mpacket_sm_3_i_5_r_4_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_5_r_4_t_6_busy, S5S8SMStore::mpacket_sm_3_i_5_r_4_t_6_cnt, S5S8SMStore::mpacket_sm_3_i_5_r_4_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_5_r_4_t_7_busy, S5S8SMStore::mpacket_sm_3_i_5_r_4_t_7_cnt, S5S8SMStore::mpacket_sm_3_i_5_r_4_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_5_r_4_t_8_busy, S5S8SMStore::mpacket_sm_3_i_5_r_4_t_8_cnt, S5S8SMStore::mpacket_sm_3_i_5_r_4_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_5_r_4_t_9_busy, S5S8SMStore::mpacket_sm_3_i_5_r_4_t_9_cnt, S5S8SMStore::mpacket_sm_3_i_5_r_4_t_9, msgObj);
				break;
			}
			break;
	}
}

VOID S5S8MessageBroker::pushToQueue_i_5_r_5(MPacket *msgObj, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_5_r_5_t_0_busy, S5S8SMStore::mpacket_sm_0_i_5_r_5_t_0_cnt, S5S8SMStore::mpacket_sm_0_i_5_r_5_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_5_r_5_t_1_busy, S5S8SMStore::mpacket_sm_0_i_5_r_5_t_1_cnt, S5S8SMStore::mpacket_sm_0_i_5_r_5_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_5_r_5_t_2_busy, S5S8SMStore::mpacket_sm_0_i_5_r_5_t_2_cnt, S5S8SMStore::mpacket_sm_0_i_5_r_5_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_5_r_5_t_3_busy, S5S8SMStore::mpacket_sm_0_i_5_r_5_t_3_cnt, S5S8SMStore::mpacket_sm_0_i_5_r_5_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_5_r_5_t_4_busy, S5S8SMStore::mpacket_sm_0_i_5_r_5_t_4_cnt, S5S8SMStore::mpacket_sm_0_i_5_r_5_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_5_r_5_t_5_busy, S5S8SMStore::mpacket_sm_0_i_5_r_5_t_5_cnt, S5S8SMStore::mpacket_sm_0_i_5_r_5_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_5_r_5_t_6_busy, S5S8SMStore::mpacket_sm_0_i_5_r_5_t_6_cnt, S5S8SMStore::mpacket_sm_0_i_5_r_5_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_5_r_5_t_7_busy, S5S8SMStore::mpacket_sm_0_i_5_r_5_t_7_cnt, S5S8SMStore::mpacket_sm_0_i_5_r_5_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_5_r_5_t_8_busy, S5S8SMStore::mpacket_sm_0_i_5_r_5_t_8_cnt, S5S8SMStore::mpacket_sm_0_i_5_r_5_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_5_r_5_t_9_busy, S5S8SMStore::mpacket_sm_0_i_5_r_5_t_9_cnt, S5S8SMStore::mpacket_sm_0_i_5_r_5_t_9, msgObj);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_5_r_5_t_0_busy, S5S8SMStore::mpacket_sm_1_i_5_r_5_t_0_cnt, S5S8SMStore::mpacket_sm_1_i_5_r_5_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_5_r_5_t_1_busy, S5S8SMStore::mpacket_sm_1_i_5_r_5_t_1_cnt, S5S8SMStore::mpacket_sm_1_i_5_r_5_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_5_r_5_t_2_busy, S5S8SMStore::mpacket_sm_1_i_5_r_5_t_2_cnt, S5S8SMStore::mpacket_sm_1_i_5_r_5_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_5_r_5_t_3_busy, S5S8SMStore::mpacket_sm_1_i_5_r_5_t_3_cnt, S5S8SMStore::mpacket_sm_1_i_5_r_5_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_5_r_5_t_4_busy, S5S8SMStore::mpacket_sm_1_i_5_r_5_t_4_cnt, S5S8SMStore::mpacket_sm_1_i_5_r_5_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_5_r_5_t_5_busy, S5S8SMStore::mpacket_sm_1_i_5_r_5_t_5_cnt, S5S8SMStore::mpacket_sm_1_i_5_r_5_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_5_r_5_t_6_busy, S5S8SMStore::mpacket_sm_1_i_5_r_5_t_6_cnt, S5S8SMStore::mpacket_sm_1_i_5_r_5_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_5_r_5_t_7_busy, S5S8SMStore::mpacket_sm_1_i_5_r_5_t_7_cnt, S5S8SMStore::mpacket_sm_1_i_5_r_5_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_5_r_5_t_8_busy, S5S8SMStore::mpacket_sm_1_i_5_r_5_t_8_cnt, S5S8SMStore::mpacket_sm_1_i_5_r_5_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_5_r_5_t_9_busy, S5S8SMStore::mpacket_sm_1_i_5_r_5_t_9_cnt, S5S8SMStore::mpacket_sm_1_i_5_r_5_t_9, msgObj);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_5_r_5_t_0_busy, S5S8SMStore::mpacket_sm_2_i_5_r_5_t_0_cnt, S5S8SMStore::mpacket_sm_2_i_5_r_5_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_5_r_5_t_1_busy, S5S8SMStore::mpacket_sm_2_i_5_r_5_t_1_cnt, S5S8SMStore::mpacket_sm_2_i_5_r_5_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_5_r_5_t_2_busy, S5S8SMStore::mpacket_sm_2_i_5_r_5_t_2_cnt, S5S8SMStore::mpacket_sm_2_i_5_r_5_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_5_r_5_t_3_busy, S5S8SMStore::mpacket_sm_2_i_5_r_5_t_3_cnt, S5S8SMStore::mpacket_sm_2_i_5_r_5_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_5_r_5_t_4_busy, S5S8SMStore::mpacket_sm_2_i_5_r_5_t_4_cnt, S5S8SMStore::mpacket_sm_2_i_5_r_5_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_5_r_5_t_5_busy, S5S8SMStore::mpacket_sm_2_i_5_r_5_t_5_cnt, S5S8SMStore::mpacket_sm_2_i_5_r_5_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_5_r_5_t_6_busy, S5S8SMStore::mpacket_sm_2_i_5_r_5_t_6_cnt, S5S8SMStore::mpacket_sm_2_i_5_r_5_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_5_r_5_t_7_busy, S5S8SMStore::mpacket_sm_2_i_5_r_5_t_7_cnt, S5S8SMStore::mpacket_sm_2_i_5_r_5_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_5_r_5_t_8_busy, S5S8SMStore::mpacket_sm_2_i_5_r_5_t_8_cnt, S5S8SMStore::mpacket_sm_2_i_5_r_5_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_5_r_5_t_9_busy, S5S8SMStore::mpacket_sm_2_i_5_r_5_t_9_cnt, S5S8SMStore::mpacket_sm_2_i_5_r_5_t_9, msgObj);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_5_r_5_t_0_busy, S5S8SMStore::mpacket_sm_3_i_5_r_5_t_0_cnt, S5S8SMStore::mpacket_sm_3_i_5_r_5_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_5_r_5_t_1_busy, S5S8SMStore::mpacket_sm_3_i_5_r_5_t_1_cnt, S5S8SMStore::mpacket_sm_3_i_5_r_5_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_5_r_5_t_2_busy, S5S8SMStore::mpacket_sm_3_i_5_r_5_t_2_cnt, S5S8SMStore::mpacket_sm_3_i_5_r_5_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_5_r_5_t_3_busy, S5S8SMStore::mpacket_sm_3_i_5_r_5_t_3_cnt, S5S8SMStore::mpacket_sm_3_i_5_r_5_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_5_r_5_t_4_busy, S5S8SMStore::mpacket_sm_3_i_5_r_5_t_4_cnt, S5S8SMStore::mpacket_sm_3_i_5_r_5_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_5_r_5_t_5_busy, S5S8SMStore::mpacket_sm_3_i_5_r_5_t_5_cnt, S5S8SMStore::mpacket_sm_3_i_5_r_5_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_5_r_5_t_6_busy, S5S8SMStore::mpacket_sm_3_i_5_r_5_t_6_cnt, S5S8SMStore::mpacket_sm_3_i_5_r_5_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_5_r_5_t_7_busy, S5S8SMStore::mpacket_sm_3_i_5_r_5_t_7_cnt, S5S8SMStore::mpacket_sm_3_i_5_r_5_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_5_r_5_t_8_busy, S5S8SMStore::mpacket_sm_3_i_5_r_5_t_8_cnt, S5S8SMStore::mpacket_sm_3_i_5_r_5_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_5_r_5_t_9_busy, S5S8SMStore::mpacket_sm_3_i_5_r_5_t_9_cnt, S5S8SMStore::mpacket_sm_3_i_5_r_5_t_9, msgObj);
				break;
			}
			break;
	}
}

VOID S5S8MessageBroker::pushToQueue_i_5_r_6(MPacket *msgObj, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_5_r_6_t_0_busy, S5S8SMStore::mpacket_sm_0_i_5_r_6_t_0_cnt, S5S8SMStore::mpacket_sm_0_i_5_r_6_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_5_r_6_t_1_busy, S5S8SMStore::mpacket_sm_0_i_5_r_6_t_1_cnt, S5S8SMStore::mpacket_sm_0_i_5_r_6_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_5_r_6_t_2_busy, S5S8SMStore::mpacket_sm_0_i_5_r_6_t_2_cnt, S5S8SMStore::mpacket_sm_0_i_5_r_6_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_5_r_6_t_3_busy, S5S8SMStore::mpacket_sm_0_i_5_r_6_t_3_cnt, S5S8SMStore::mpacket_sm_0_i_5_r_6_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_5_r_6_t_4_busy, S5S8SMStore::mpacket_sm_0_i_5_r_6_t_4_cnt, S5S8SMStore::mpacket_sm_0_i_5_r_6_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_5_r_6_t_5_busy, S5S8SMStore::mpacket_sm_0_i_5_r_6_t_5_cnt, S5S8SMStore::mpacket_sm_0_i_5_r_6_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_5_r_6_t_6_busy, S5S8SMStore::mpacket_sm_0_i_5_r_6_t_6_cnt, S5S8SMStore::mpacket_sm_0_i_5_r_6_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_5_r_6_t_7_busy, S5S8SMStore::mpacket_sm_0_i_5_r_6_t_7_cnt, S5S8SMStore::mpacket_sm_0_i_5_r_6_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_5_r_6_t_8_busy, S5S8SMStore::mpacket_sm_0_i_5_r_6_t_8_cnt, S5S8SMStore::mpacket_sm_0_i_5_r_6_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_5_r_6_t_9_busy, S5S8SMStore::mpacket_sm_0_i_5_r_6_t_9_cnt, S5S8SMStore::mpacket_sm_0_i_5_r_6_t_9, msgObj);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_5_r_6_t_0_busy, S5S8SMStore::mpacket_sm_1_i_5_r_6_t_0_cnt, S5S8SMStore::mpacket_sm_1_i_5_r_6_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_5_r_6_t_1_busy, S5S8SMStore::mpacket_sm_1_i_5_r_6_t_1_cnt, S5S8SMStore::mpacket_sm_1_i_5_r_6_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_5_r_6_t_2_busy, S5S8SMStore::mpacket_sm_1_i_5_r_6_t_2_cnt, S5S8SMStore::mpacket_sm_1_i_5_r_6_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_5_r_6_t_3_busy, S5S8SMStore::mpacket_sm_1_i_5_r_6_t_3_cnt, S5S8SMStore::mpacket_sm_1_i_5_r_6_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_5_r_6_t_4_busy, S5S8SMStore::mpacket_sm_1_i_5_r_6_t_4_cnt, S5S8SMStore::mpacket_sm_1_i_5_r_6_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_5_r_6_t_5_busy, S5S8SMStore::mpacket_sm_1_i_5_r_6_t_5_cnt, S5S8SMStore::mpacket_sm_1_i_5_r_6_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_5_r_6_t_6_busy, S5S8SMStore::mpacket_sm_1_i_5_r_6_t_6_cnt, S5S8SMStore::mpacket_sm_1_i_5_r_6_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_5_r_6_t_7_busy, S5S8SMStore::mpacket_sm_1_i_5_r_6_t_7_cnt, S5S8SMStore::mpacket_sm_1_i_5_r_6_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_5_r_6_t_8_busy, S5S8SMStore::mpacket_sm_1_i_5_r_6_t_8_cnt, S5S8SMStore::mpacket_sm_1_i_5_r_6_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_5_r_6_t_9_busy, S5S8SMStore::mpacket_sm_1_i_5_r_6_t_9_cnt, S5S8SMStore::mpacket_sm_1_i_5_r_6_t_9, msgObj);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_5_r_6_t_0_busy, S5S8SMStore::mpacket_sm_2_i_5_r_6_t_0_cnt, S5S8SMStore::mpacket_sm_2_i_5_r_6_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_5_r_6_t_1_busy, S5S8SMStore::mpacket_sm_2_i_5_r_6_t_1_cnt, S5S8SMStore::mpacket_sm_2_i_5_r_6_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_5_r_6_t_2_busy, S5S8SMStore::mpacket_sm_2_i_5_r_6_t_2_cnt, S5S8SMStore::mpacket_sm_2_i_5_r_6_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_5_r_6_t_3_busy, S5S8SMStore::mpacket_sm_2_i_5_r_6_t_3_cnt, S5S8SMStore::mpacket_sm_2_i_5_r_6_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_5_r_6_t_4_busy, S5S8SMStore::mpacket_sm_2_i_5_r_6_t_4_cnt, S5S8SMStore::mpacket_sm_2_i_5_r_6_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_5_r_6_t_5_busy, S5S8SMStore::mpacket_sm_2_i_5_r_6_t_5_cnt, S5S8SMStore::mpacket_sm_2_i_5_r_6_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_5_r_6_t_6_busy, S5S8SMStore::mpacket_sm_2_i_5_r_6_t_6_cnt, S5S8SMStore::mpacket_sm_2_i_5_r_6_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_5_r_6_t_7_busy, S5S8SMStore::mpacket_sm_2_i_5_r_6_t_7_cnt, S5S8SMStore::mpacket_sm_2_i_5_r_6_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_5_r_6_t_8_busy, S5S8SMStore::mpacket_sm_2_i_5_r_6_t_8_cnt, S5S8SMStore::mpacket_sm_2_i_5_r_6_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_5_r_6_t_9_busy, S5S8SMStore::mpacket_sm_2_i_5_r_6_t_9_cnt, S5S8SMStore::mpacket_sm_2_i_5_r_6_t_9, msgObj);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_5_r_6_t_0_busy, S5S8SMStore::mpacket_sm_3_i_5_r_6_t_0_cnt, S5S8SMStore::mpacket_sm_3_i_5_r_6_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_5_r_6_t_1_busy, S5S8SMStore::mpacket_sm_3_i_5_r_6_t_1_cnt, S5S8SMStore::mpacket_sm_3_i_5_r_6_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_5_r_6_t_2_busy, S5S8SMStore::mpacket_sm_3_i_5_r_6_t_2_cnt, S5S8SMStore::mpacket_sm_3_i_5_r_6_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_5_r_6_t_3_busy, S5S8SMStore::mpacket_sm_3_i_5_r_6_t_3_cnt, S5S8SMStore::mpacket_sm_3_i_5_r_6_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_5_r_6_t_4_busy, S5S8SMStore::mpacket_sm_3_i_5_r_6_t_4_cnt, S5S8SMStore::mpacket_sm_3_i_5_r_6_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_5_r_6_t_5_busy, S5S8SMStore::mpacket_sm_3_i_5_r_6_t_5_cnt, S5S8SMStore::mpacket_sm_3_i_5_r_6_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_5_r_6_t_6_busy, S5S8SMStore::mpacket_sm_3_i_5_r_6_t_6_cnt, S5S8SMStore::mpacket_sm_3_i_5_r_6_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_5_r_6_t_7_busy, S5S8SMStore::mpacket_sm_3_i_5_r_6_t_7_cnt, S5S8SMStore::mpacket_sm_3_i_5_r_6_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_5_r_6_t_8_busy, S5S8SMStore::mpacket_sm_3_i_5_r_6_t_8_cnt, S5S8SMStore::mpacket_sm_3_i_5_r_6_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_5_r_6_t_9_busy, S5S8SMStore::mpacket_sm_3_i_5_r_6_t_9_cnt, S5S8SMStore::mpacket_sm_3_i_5_r_6_t_9, msgObj);
				break;
			}
			break;
	}
}

VOID S5S8MessageBroker::pushToQueue_i_5_r_7(MPacket *msgObj, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_5_r_7_t_0_busy, S5S8SMStore::mpacket_sm_0_i_5_r_7_t_0_cnt, S5S8SMStore::mpacket_sm_0_i_5_r_7_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_5_r_7_t_1_busy, S5S8SMStore::mpacket_sm_0_i_5_r_7_t_1_cnt, S5S8SMStore::mpacket_sm_0_i_5_r_7_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_5_r_7_t_2_busy, S5S8SMStore::mpacket_sm_0_i_5_r_7_t_2_cnt, S5S8SMStore::mpacket_sm_0_i_5_r_7_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_5_r_7_t_3_busy, S5S8SMStore::mpacket_sm_0_i_5_r_7_t_3_cnt, S5S8SMStore::mpacket_sm_0_i_5_r_7_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_5_r_7_t_4_busy, S5S8SMStore::mpacket_sm_0_i_5_r_7_t_4_cnt, S5S8SMStore::mpacket_sm_0_i_5_r_7_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_5_r_7_t_5_busy, S5S8SMStore::mpacket_sm_0_i_5_r_7_t_5_cnt, S5S8SMStore::mpacket_sm_0_i_5_r_7_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_5_r_7_t_6_busy, S5S8SMStore::mpacket_sm_0_i_5_r_7_t_6_cnt, S5S8SMStore::mpacket_sm_0_i_5_r_7_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_5_r_7_t_7_busy, S5S8SMStore::mpacket_sm_0_i_5_r_7_t_7_cnt, S5S8SMStore::mpacket_sm_0_i_5_r_7_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_5_r_7_t_8_busy, S5S8SMStore::mpacket_sm_0_i_5_r_7_t_8_cnt, S5S8SMStore::mpacket_sm_0_i_5_r_7_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_5_r_7_t_9_busy, S5S8SMStore::mpacket_sm_0_i_5_r_7_t_9_cnt, S5S8SMStore::mpacket_sm_0_i_5_r_7_t_9, msgObj);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_5_r_7_t_0_busy, S5S8SMStore::mpacket_sm_1_i_5_r_7_t_0_cnt, S5S8SMStore::mpacket_sm_1_i_5_r_7_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_5_r_7_t_1_busy, S5S8SMStore::mpacket_sm_1_i_5_r_7_t_1_cnt, S5S8SMStore::mpacket_sm_1_i_5_r_7_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_5_r_7_t_2_busy, S5S8SMStore::mpacket_sm_1_i_5_r_7_t_2_cnt, S5S8SMStore::mpacket_sm_1_i_5_r_7_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_5_r_7_t_3_busy, S5S8SMStore::mpacket_sm_1_i_5_r_7_t_3_cnt, S5S8SMStore::mpacket_sm_1_i_5_r_7_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_5_r_7_t_4_busy, S5S8SMStore::mpacket_sm_1_i_5_r_7_t_4_cnt, S5S8SMStore::mpacket_sm_1_i_5_r_7_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_5_r_7_t_5_busy, S5S8SMStore::mpacket_sm_1_i_5_r_7_t_5_cnt, S5S8SMStore::mpacket_sm_1_i_5_r_7_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_5_r_7_t_6_busy, S5S8SMStore::mpacket_sm_1_i_5_r_7_t_6_cnt, S5S8SMStore::mpacket_sm_1_i_5_r_7_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_5_r_7_t_7_busy, S5S8SMStore::mpacket_sm_1_i_5_r_7_t_7_cnt, S5S8SMStore::mpacket_sm_1_i_5_r_7_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_5_r_7_t_8_busy, S5S8SMStore::mpacket_sm_1_i_5_r_7_t_8_cnt, S5S8SMStore::mpacket_sm_1_i_5_r_7_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_5_r_7_t_9_busy, S5S8SMStore::mpacket_sm_1_i_5_r_7_t_9_cnt, S5S8SMStore::mpacket_sm_1_i_5_r_7_t_9, msgObj);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_5_r_7_t_0_busy, S5S8SMStore::mpacket_sm_2_i_5_r_7_t_0_cnt, S5S8SMStore::mpacket_sm_2_i_5_r_7_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_5_r_7_t_1_busy, S5S8SMStore::mpacket_sm_2_i_5_r_7_t_1_cnt, S5S8SMStore::mpacket_sm_2_i_5_r_7_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_5_r_7_t_2_busy, S5S8SMStore::mpacket_sm_2_i_5_r_7_t_2_cnt, S5S8SMStore::mpacket_sm_2_i_5_r_7_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_5_r_7_t_3_busy, S5S8SMStore::mpacket_sm_2_i_5_r_7_t_3_cnt, S5S8SMStore::mpacket_sm_2_i_5_r_7_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_5_r_7_t_4_busy, S5S8SMStore::mpacket_sm_2_i_5_r_7_t_4_cnt, S5S8SMStore::mpacket_sm_2_i_5_r_7_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_5_r_7_t_5_busy, S5S8SMStore::mpacket_sm_2_i_5_r_7_t_5_cnt, S5S8SMStore::mpacket_sm_2_i_5_r_7_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_5_r_7_t_6_busy, S5S8SMStore::mpacket_sm_2_i_5_r_7_t_6_cnt, S5S8SMStore::mpacket_sm_2_i_5_r_7_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_5_r_7_t_7_busy, S5S8SMStore::mpacket_sm_2_i_5_r_7_t_7_cnt, S5S8SMStore::mpacket_sm_2_i_5_r_7_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_5_r_7_t_8_busy, S5S8SMStore::mpacket_sm_2_i_5_r_7_t_8_cnt, S5S8SMStore::mpacket_sm_2_i_5_r_7_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_5_r_7_t_9_busy, S5S8SMStore::mpacket_sm_2_i_5_r_7_t_9_cnt, S5S8SMStore::mpacket_sm_2_i_5_r_7_t_9, msgObj);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_5_r_7_t_0_busy, S5S8SMStore::mpacket_sm_3_i_5_r_7_t_0_cnt, S5S8SMStore::mpacket_sm_3_i_5_r_7_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_5_r_7_t_1_busy, S5S8SMStore::mpacket_sm_3_i_5_r_7_t_1_cnt, S5S8SMStore::mpacket_sm_3_i_5_r_7_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_5_r_7_t_2_busy, S5S8SMStore::mpacket_sm_3_i_5_r_7_t_2_cnt, S5S8SMStore::mpacket_sm_3_i_5_r_7_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_5_r_7_t_3_busy, S5S8SMStore::mpacket_sm_3_i_5_r_7_t_3_cnt, S5S8SMStore::mpacket_sm_3_i_5_r_7_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_5_r_7_t_4_busy, S5S8SMStore::mpacket_sm_3_i_5_r_7_t_4_cnt, S5S8SMStore::mpacket_sm_3_i_5_r_7_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_5_r_7_t_5_busy, S5S8SMStore::mpacket_sm_3_i_5_r_7_t_5_cnt, S5S8SMStore::mpacket_sm_3_i_5_r_7_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_5_r_7_t_6_busy, S5S8SMStore::mpacket_sm_3_i_5_r_7_t_6_cnt, S5S8SMStore::mpacket_sm_3_i_5_r_7_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_5_r_7_t_7_busy, S5S8SMStore::mpacket_sm_3_i_5_r_7_t_7_cnt, S5S8SMStore::mpacket_sm_3_i_5_r_7_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_5_r_7_t_8_busy, S5S8SMStore::mpacket_sm_3_i_5_r_7_t_8_cnt, S5S8SMStore::mpacket_sm_3_i_5_r_7_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_5_r_7_t_9_busy, S5S8SMStore::mpacket_sm_3_i_5_r_7_t_9_cnt, S5S8SMStore::mpacket_sm_3_i_5_r_7_t_9, msgObj);
				break;
			}
			break;
	}
}


VOID S5S8MessageBroker::pushToQueue_i_6_r_0(MPacket *msgObj, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_6_r_0_t_0_busy, S5S8SMStore::mpacket_sm_0_i_6_r_0_t_0_cnt, S5S8SMStore::mpacket_sm_0_i_6_r_0_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_6_r_0_t_1_busy, S5S8SMStore::mpacket_sm_0_i_6_r_0_t_1_cnt, S5S8SMStore::mpacket_sm_0_i_6_r_0_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_6_r_0_t_2_busy, S5S8SMStore::mpacket_sm_0_i_6_r_0_t_2_cnt, S5S8SMStore::mpacket_sm_0_i_6_r_0_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_6_r_0_t_3_busy, S5S8SMStore::mpacket_sm_0_i_6_r_0_t_3_cnt, S5S8SMStore::mpacket_sm_0_i_6_r_0_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_6_r_0_t_4_busy, S5S8SMStore::mpacket_sm_0_i_6_r_0_t_4_cnt, S5S8SMStore::mpacket_sm_0_i_6_r_0_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_6_r_0_t_5_busy, S5S8SMStore::mpacket_sm_0_i_6_r_0_t_5_cnt, S5S8SMStore::mpacket_sm_0_i_6_r_0_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_6_r_0_t_6_busy, S5S8SMStore::mpacket_sm_0_i_6_r_0_t_6_cnt, S5S8SMStore::mpacket_sm_0_i_6_r_0_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_6_r_0_t_7_busy, S5S8SMStore::mpacket_sm_0_i_6_r_0_t_7_cnt, S5S8SMStore::mpacket_sm_0_i_6_r_0_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_6_r_0_t_8_busy, S5S8SMStore::mpacket_sm_0_i_6_r_0_t_8_cnt, S5S8SMStore::mpacket_sm_0_i_6_r_0_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_6_r_0_t_9_busy, S5S8SMStore::mpacket_sm_0_i_6_r_0_t_9_cnt, S5S8SMStore::mpacket_sm_0_i_6_r_0_t_9, msgObj);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_6_r_0_t_0_busy, S5S8SMStore::mpacket_sm_1_i_6_r_0_t_0_cnt, S5S8SMStore::mpacket_sm_1_i_6_r_0_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_6_r_0_t_1_busy, S5S8SMStore::mpacket_sm_1_i_6_r_0_t_1_cnt, S5S8SMStore::mpacket_sm_1_i_6_r_0_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_6_r_0_t_2_busy, S5S8SMStore::mpacket_sm_1_i_6_r_0_t_2_cnt, S5S8SMStore::mpacket_sm_1_i_6_r_0_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_6_r_0_t_3_busy, S5S8SMStore::mpacket_sm_1_i_6_r_0_t_3_cnt, S5S8SMStore::mpacket_sm_1_i_6_r_0_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_6_r_0_t_4_busy, S5S8SMStore::mpacket_sm_1_i_6_r_0_t_4_cnt, S5S8SMStore::mpacket_sm_1_i_6_r_0_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_6_r_0_t_5_busy, S5S8SMStore::mpacket_sm_1_i_6_r_0_t_5_cnt, S5S8SMStore::mpacket_sm_1_i_6_r_0_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_6_r_0_t_6_busy, S5S8SMStore::mpacket_sm_1_i_6_r_0_t_6_cnt, S5S8SMStore::mpacket_sm_1_i_6_r_0_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_6_r_0_t_7_busy, S5S8SMStore::mpacket_sm_1_i_6_r_0_t_7_cnt, S5S8SMStore::mpacket_sm_1_i_6_r_0_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_6_r_0_t_8_busy, S5S8SMStore::mpacket_sm_1_i_6_r_0_t_8_cnt, S5S8SMStore::mpacket_sm_1_i_6_r_0_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_6_r_0_t_9_busy, S5S8SMStore::mpacket_sm_1_i_6_r_0_t_9_cnt, S5S8SMStore::mpacket_sm_1_i_6_r_0_t_9, msgObj);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_6_r_0_t_0_busy, S5S8SMStore::mpacket_sm_2_i_6_r_0_t_0_cnt, S5S8SMStore::mpacket_sm_2_i_6_r_0_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_6_r_0_t_1_busy, S5S8SMStore::mpacket_sm_2_i_6_r_0_t_1_cnt, S5S8SMStore::mpacket_sm_2_i_6_r_0_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_6_r_0_t_2_busy, S5S8SMStore::mpacket_sm_2_i_6_r_0_t_2_cnt, S5S8SMStore::mpacket_sm_2_i_6_r_0_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_6_r_0_t_3_busy, S5S8SMStore::mpacket_sm_2_i_6_r_0_t_3_cnt, S5S8SMStore::mpacket_sm_2_i_6_r_0_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_6_r_0_t_4_busy, S5S8SMStore::mpacket_sm_2_i_6_r_0_t_4_cnt, S5S8SMStore::mpacket_sm_2_i_6_r_0_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_6_r_0_t_5_busy, S5S8SMStore::mpacket_sm_2_i_6_r_0_t_5_cnt, S5S8SMStore::mpacket_sm_2_i_6_r_0_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_6_r_0_t_6_busy, S5S8SMStore::mpacket_sm_2_i_6_r_0_t_6_cnt, S5S8SMStore::mpacket_sm_2_i_6_r_0_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_6_r_0_t_7_busy, S5S8SMStore::mpacket_sm_2_i_6_r_0_t_7_cnt, S5S8SMStore::mpacket_sm_2_i_6_r_0_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_6_r_0_t_8_busy, S5S8SMStore::mpacket_sm_2_i_6_r_0_t_8_cnt, S5S8SMStore::mpacket_sm_2_i_6_r_0_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_6_r_0_t_9_busy, S5S8SMStore::mpacket_sm_2_i_6_r_0_t_9_cnt, S5S8SMStore::mpacket_sm_2_i_6_r_0_t_9, msgObj);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_6_r_0_t_0_busy, S5S8SMStore::mpacket_sm_3_i_6_r_0_t_0_cnt, S5S8SMStore::mpacket_sm_3_i_6_r_0_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_6_r_0_t_1_busy, S5S8SMStore::mpacket_sm_3_i_6_r_0_t_1_cnt, S5S8SMStore::mpacket_sm_3_i_6_r_0_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_6_r_0_t_2_busy, S5S8SMStore::mpacket_sm_3_i_6_r_0_t_2_cnt, S5S8SMStore::mpacket_sm_3_i_6_r_0_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_6_r_0_t_3_busy, S5S8SMStore::mpacket_sm_3_i_6_r_0_t_3_cnt, S5S8SMStore::mpacket_sm_3_i_6_r_0_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_6_r_0_t_4_busy, S5S8SMStore::mpacket_sm_3_i_6_r_0_t_4_cnt, S5S8SMStore::mpacket_sm_3_i_6_r_0_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_6_r_0_t_5_busy, S5S8SMStore::mpacket_sm_3_i_6_r_0_t_5_cnt, S5S8SMStore::mpacket_sm_3_i_6_r_0_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_6_r_0_t_6_busy, S5S8SMStore::mpacket_sm_3_i_6_r_0_t_6_cnt, S5S8SMStore::mpacket_sm_3_i_6_r_0_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_6_r_0_t_7_busy, S5S8SMStore::mpacket_sm_3_i_6_r_0_t_7_cnt, S5S8SMStore::mpacket_sm_3_i_6_r_0_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_6_r_0_t_8_busy, S5S8SMStore::mpacket_sm_3_i_6_r_0_t_8_cnt, S5S8SMStore::mpacket_sm_3_i_6_r_0_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_6_r_0_t_9_busy, S5S8SMStore::mpacket_sm_3_i_6_r_0_t_9_cnt, S5S8SMStore::mpacket_sm_3_i_6_r_0_t_9, msgObj);
				break;
			}
			break;
	}
}

VOID S5S8MessageBroker::pushToQueue_i_6_r_1(MPacket *msgObj, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_6_r_1_t_0_busy, S5S8SMStore::mpacket_sm_0_i_6_r_1_t_0_cnt, S5S8SMStore::mpacket_sm_0_i_6_r_1_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_6_r_1_t_1_busy, S5S8SMStore::mpacket_sm_0_i_6_r_1_t_1_cnt, S5S8SMStore::mpacket_sm_0_i_6_r_1_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_6_r_1_t_2_busy, S5S8SMStore::mpacket_sm_0_i_6_r_1_t_2_cnt, S5S8SMStore::mpacket_sm_0_i_6_r_1_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_6_r_1_t_3_busy, S5S8SMStore::mpacket_sm_0_i_6_r_1_t_3_cnt, S5S8SMStore::mpacket_sm_0_i_6_r_1_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_6_r_1_t_4_busy, S5S8SMStore::mpacket_sm_0_i_6_r_1_t_4_cnt, S5S8SMStore::mpacket_sm_0_i_6_r_1_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_6_r_1_t_5_busy, S5S8SMStore::mpacket_sm_0_i_6_r_1_t_5_cnt, S5S8SMStore::mpacket_sm_0_i_6_r_1_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_6_r_1_t_6_busy, S5S8SMStore::mpacket_sm_0_i_6_r_1_t_6_cnt, S5S8SMStore::mpacket_sm_0_i_6_r_1_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_6_r_1_t_7_busy, S5S8SMStore::mpacket_sm_0_i_6_r_1_t_7_cnt, S5S8SMStore::mpacket_sm_0_i_6_r_1_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_6_r_1_t_8_busy, S5S8SMStore::mpacket_sm_0_i_6_r_1_t_8_cnt, S5S8SMStore::mpacket_sm_0_i_6_r_1_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_6_r_1_t_9_busy, S5S8SMStore::mpacket_sm_0_i_6_r_1_t_9_cnt, S5S8SMStore::mpacket_sm_0_i_6_r_1_t_9, msgObj);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_6_r_1_t_0_busy, S5S8SMStore::mpacket_sm_1_i_6_r_1_t_0_cnt, S5S8SMStore::mpacket_sm_1_i_6_r_1_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_6_r_1_t_1_busy, S5S8SMStore::mpacket_sm_1_i_6_r_1_t_1_cnt, S5S8SMStore::mpacket_sm_1_i_6_r_1_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_6_r_1_t_2_busy, S5S8SMStore::mpacket_sm_1_i_6_r_1_t_2_cnt, S5S8SMStore::mpacket_sm_1_i_6_r_1_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_6_r_1_t_3_busy, S5S8SMStore::mpacket_sm_1_i_6_r_1_t_3_cnt, S5S8SMStore::mpacket_sm_1_i_6_r_1_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_6_r_1_t_4_busy, S5S8SMStore::mpacket_sm_1_i_6_r_1_t_4_cnt, S5S8SMStore::mpacket_sm_1_i_6_r_1_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_6_r_1_t_5_busy, S5S8SMStore::mpacket_sm_1_i_6_r_1_t_5_cnt, S5S8SMStore::mpacket_sm_1_i_6_r_1_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_6_r_1_t_6_busy, S5S8SMStore::mpacket_sm_1_i_6_r_1_t_6_cnt, S5S8SMStore::mpacket_sm_1_i_6_r_1_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_6_r_1_t_7_busy, S5S8SMStore::mpacket_sm_1_i_6_r_1_t_7_cnt, S5S8SMStore::mpacket_sm_1_i_6_r_1_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_6_r_1_t_8_busy, S5S8SMStore::mpacket_sm_1_i_6_r_1_t_8_cnt, S5S8SMStore::mpacket_sm_1_i_6_r_1_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_6_r_1_t_9_busy, S5S8SMStore::mpacket_sm_1_i_6_r_1_t_9_cnt, S5S8SMStore::mpacket_sm_1_i_6_r_1_t_9, msgObj);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_6_r_1_t_0_busy, S5S8SMStore::mpacket_sm_2_i_6_r_1_t_0_cnt, S5S8SMStore::mpacket_sm_2_i_6_r_1_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_6_r_1_t_1_busy, S5S8SMStore::mpacket_sm_2_i_6_r_1_t_1_cnt, S5S8SMStore::mpacket_sm_2_i_6_r_1_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_6_r_1_t_2_busy, S5S8SMStore::mpacket_sm_2_i_6_r_1_t_2_cnt, S5S8SMStore::mpacket_sm_2_i_6_r_1_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_6_r_1_t_3_busy, S5S8SMStore::mpacket_sm_2_i_6_r_1_t_3_cnt, S5S8SMStore::mpacket_sm_2_i_6_r_1_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_6_r_1_t_4_busy, S5S8SMStore::mpacket_sm_2_i_6_r_1_t_4_cnt, S5S8SMStore::mpacket_sm_2_i_6_r_1_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_6_r_1_t_5_busy, S5S8SMStore::mpacket_sm_2_i_6_r_1_t_5_cnt, S5S8SMStore::mpacket_sm_2_i_6_r_1_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_6_r_1_t_6_busy, S5S8SMStore::mpacket_sm_2_i_6_r_1_t_6_cnt, S5S8SMStore::mpacket_sm_2_i_6_r_1_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_6_r_1_t_7_busy, S5S8SMStore::mpacket_sm_2_i_6_r_1_t_7_cnt, S5S8SMStore::mpacket_sm_2_i_6_r_1_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_6_r_1_t_8_busy, S5S8SMStore::mpacket_sm_2_i_6_r_1_t_8_cnt, S5S8SMStore::mpacket_sm_2_i_6_r_1_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_6_r_1_t_9_busy, S5S8SMStore::mpacket_sm_2_i_6_r_1_t_9_cnt, S5S8SMStore::mpacket_sm_2_i_6_r_1_t_9, msgObj);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_6_r_1_t_0_busy, S5S8SMStore::mpacket_sm_3_i_6_r_1_t_0_cnt, S5S8SMStore::mpacket_sm_3_i_6_r_1_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_6_r_1_t_1_busy, S5S8SMStore::mpacket_sm_3_i_6_r_1_t_1_cnt, S5S8SMStore::mpacket_sm_3_i_6_r_1_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_6_r_1_t_2_busy, S5S8SMStore::mpacket_sm_3_i_6_r_1_t_2_cnt, S5S8SMStore::mpacket_sm_3_i_6_r_1_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_6_r_1_t_3_busy, S5S8SMStore::mpacket_sm_3_i_6_r_1_t_3_cnt, S5S8SMStore::mpacket_sm_3_i_6_r_1_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_6_r_1_t_4_busy, S5S8SMStore::mpacket_sm_3_i_6_r_1_t_4_cnt, S5S8SMStore::mpacket_sm_3_i_6_r_1_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_6_r_1_t_5_busy, S5S8SMStore::mpacket_sm_3_i_6_r_1_t_5_cnt, S5S8SMStore::mpacket_sm_3_i_6_r_1_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_6_r_1_t_6_busy, S5S8SMStore::mpacket_sm_3_i_6_r_1_t_6_cnt, S5S8SMStore::mpacket_sm_3_i_6_r_1_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_6_r_1_t_7_busy, S5S8SMStore::mpacket_sm_3_i_6_r_1_t_7_cnt, S5S8SMStore::mpacket_sm_3_i_6_r_1_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_6_r_1_t_8_busy, S5S8SMStore::mpacket_sm_3_i_6_r_1_t_8_cnt, S5S8SMStore::mpacket_sm_3_i_6_r_1_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_6_r_1_t_9_busy, S5S8SMStore::mpacket_sm_3_i_6_r_1_t_9_cnt, S5S8SMStore::mpacket_sm_3_i_6_r_1_t_9, msgObj);
				break;
			}
			break;
	}
}

VOID S5S8MessageBroker::pushToQueue_i_6_r_2(MPacket *msgObj, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_6_r_2_t_0_busy, S5S8SMStore::mpacket_sm_0_i_6_r_2_t_0_cnt, S5S8SMStore::mpacket_sm_0_i_6_r_2_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_6_r_2_t_1_busy, S5S8SMStore::mpacket_sm_0_i_6_r_2_t_1_cnt, S5S8SMStore::mpacket_sm_0_i_6_r_2_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_6_r_2_t_2_busy, S5S8SMStore::mpacket_sm_0_i_6_r_2_t_2_cnt, S5S8SMStore::mpacket_sm_0_i_6_r_2_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_6_r_2_t_3_busy, S5S8SMStore::mpacket_sm_0_i_6_r_2_t_3_cnt, S5S8SMStore::mpacket_sm_0_i_6_r_2_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_6_r_2_t_4_busy, S5S8SMStore::mpacket_sm_0_i_6_r_2_t_4_cnt, S5S8SMStore::mpacket_sm_0_i_6_r_2_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_6_r_2_t_5_busy, S5S8SMStore::mpacket_sm_0_i_6_r_2_t_5_cnt, S5S8SMStore::mpacket_sm_0_i_6_r_2_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_6_r_2_t_6_busy, S5S8SMStore::mpacket_sm_0_i_6_r_2_t_6_cnt, S5S8SMStore::mpacket_sm_0_i_6_r_2_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_6_r_2_t_7_busy, S5S8SMStore::mpacket_sm_0_i_6_r_2_t_7_cnt, S5S8SMStore::mpacket_sm_0_i_6_r_2_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_6_r_2_t_8_busy, S5S8SMStore::mpacket_sm_0_i_6_r_2_t_8_cnt, S5S8SMStore::mpacket_sm_0_i_6_r_2_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_6_r_2_t_9_busy, S5S8SMStore::mpacket_sm_0_i_6_r_2_t_9_cnt, S5S8SMStore::mpacket_sm_0_i_6_r_2_t_9, msgObj);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_6_r_2_t_0_busy, S5S8SMStore::mpacket_sm_1_i_6_r_2_t_0_cnt, S5S8SMStore::mpacket_sm_1_i_6_r_2_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_6_r_2_t_1_busy, S5S8SMStore::mpacket_sm_1_i_6_r_2_t_1_cnt, S5S8SMStore::mpacket_sm_1_i_6_r_2_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_6_r_2_t_2_busy, S5S8SMStore::mpacket_sm_1_i_6_r_2_t_2_cnt, S5S8SMStore::mpacket_sm_1_i_6_r_2_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_6_r_2_t_3_busy, S5S8SMStore::mpacket_sm_1_i_6_r_2_t_3_cnt, S5S8SMStore::mpacket_sm_1_i_6_r_2_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_6_r_2_t_4_busy, S5S8SMStore::mpacket_sm_1_i_6_r_2_t_4_cnt, S5S8SMStore::mpacket_sm_1_i_6_r_2_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_6_r_2_t_5_busy, S5S8SMStore::mpacket_sm_1_i_6_r_2_t_5_cnt, S5S8SMStore::mpacket_sm_1_i_6_r_2_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_6_r_2_t_6_busy, S5S8SMStore::mpacket_sm_1_i_6_r_2_t_6_cnt, S5S8SMStore::mpacket_sm_1_i_6_r_2_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_6_r_2_t_7_busy, S5S8SMStore::mpacket_sm_1_i_6_r_2_t_7_cnt, S5S8SMStore::mpacket_sm_1_i_6_r_2_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_6_r_2_t_8_busy, S5S8SMStore::mpacket_sm_1_i_6_r_2_t_8_cnt, S5S8SMStore::mpacket_sm_1_i_6_r_2_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_6_r_2_t_9_busy, S5S8SMStore::mpacket_sm_1_i_6_r_2_t_9_cnt, S5S8SMStore::mpacket_sm_1_i_6_r_2_t_9, msgObj);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_6_r_2_t_0_busy, S5S8SMStore::mpacket_sm_2_i_6_r_2_t_0_cnt, S5S8SMStore::mpacket_sm_2_i_6_r_2_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_6_r_2_t_1_busy, S5S8SMStore::mpacket_sm_2_i_6_r_2_t_1_cnt, S5S8SMStore::mpacket_sm_2_i_6_r_2_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_6_r_2_t_2_busy, S5S8SMStore::mpacket_sm_2_i_6_r_2_t_2_cnt, S5S8SMStore::mpacket_sm_2_i_6_r_2_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_6_r_2_t_3_busy, S5S8SMStore::mpacket_sm_2_i_6_r_2_t_3_cnt, S5S8SMStore::mpacket_sm_2_i_6_r_2_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_6_r_2_t_4_busy, S5S8SMStore::mpacket_sm_2_i_6_r_2_t_4_cnt, S5S8SMStore::mpacket_sm_2_i_6_r_2_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_6_r_2_t_5_busy, S5S8SMStore::mpacket_sm_2_i_6_r_2_t_5_cnt, S5S8SMStore::mpacket_sm_2_i_6_r_2_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_6_r_2_t_6_busy, S5S8SMStore::mpacket_sm_2_i_6_r_2_t_6_cnt, S5S8SMStore::mpacket_sm_2_i_6_r_2_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_6_r_2_t_7_busy, S5S8SMStore::mpacket_sm_2_i_6_r_2_t_7_cnt, S5S8SMStore::mpacket_sm_2_i_6_r_2_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_6_r_2_t_8_busy, S5S8SMStore::mpacket_sm_2_i_6_r_2_t_8_cnt, S5S8SMStore::mpacket_sm_2_i_6_r_2_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_6_r_2_t_9_busy, S5S8SMStore::mpacket_sm_2_i_6_r_2_t_9_cnt, S5S8SMStore::mpacket_sm_2_i_6_r_2_t_9, msgObj);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_6_r_2_t_0_busy, S5S8SMStore::mpacket_sm_3_i_6_r_2_t_0_cnt, S5S8SMStore::mpacket_sm_3_i_6_r_2_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_6_r_2_t_1_busy, S5S8SMStore::mpacket_sm_3_i_6_r_2_t_1_cnt, S5S8SMStore::mpacket_sm_3_i_6_r_2_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_6_r_2_t_2_busy, S5S8SMStore::mpacket_sm_3_i_6_r_2_t_2_cnt, S5S8SMStore::mpacket_sm_3_i_6_r_2_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_6_r_2_t_3_busy, S5S8SMStore::mpacket_sm_3_i_6_r_2_t_3_cnt, S5S8SMStore::mpacket_sm_3_i_6_r_2_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_6_r_2_t_4_busy, S5S8SMStore::mpacket_sm_3_i_6_r_2_t_4_cnt, S5S8SMStore::mpacket_sm_3_i_6_r_2_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_6_r_2_t_5_busy, S5S8SMStore::mpacket_sm_3_i_6_r_2_t_5_cnt, S5S8SMStore::mpacket_sm_3_i_6_r_2_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_6_r_2_t_6_busy, S5S8SMStore::mpacket_sm_3_i_6_r_2_t_6_cnt, S5S8SMStore::mpacket_sm_3_i_6_r_2_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_6_r_2_t_7_busy, S5S8SMStore::mpacket_sm_3_i_6_r_2_t_7_cnt, S5S8SMStore::mpacket_sm_3_i_6_r_2_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_6_r_2_t_8_busy, S5S8SMStore::mpacket_sm_3_i_6_r_2_t_8_cnt, S5S8SMStore::mpacket_sm_3_i_6_r_2_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_6_r_2_t_9_busy, S5S8SMStore::mpacket_sm_3_i_6_r_2_t_9_cnt, S5S8SMStore::mpacket_sm_3_i_6_r_2_t_9, msgObj);
				break;
			}
			break;
	}
}

VOID S5S8MessageBroker::pushToQueue_i_6_r_3(MPacket *msgObj, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_6_r_3_t_0_busy, S5S8SMStore::mpacket_sm_0_i_6_r_3_t_0_cnt, S5S8SMStore::mpacket_sm_0_i_6_r_3_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_6_r_3_t_1_busy, S5S8SMStore::mpacket_sm_0_i_6_r_3_t_1_cnt, S5S8SMStore::mpacket_sm_0_i_6_r_3_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_6_r_3_t_2_busy, S5S8SMStore::mpacket_sm_0_i_6_r_3_t_2_cnt, S5S8SMStore::mpacket_sm_0_i_6_r_3_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_6_r_3_t_3_busy, S5S8SMStore::mpacket_sm_0_i_6_r_3_t_3_cnt, S5S8SMStore::mpacket_sm_0_i_6_r_3_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_6_r_3_t_4_busy, S5S8SMStore::mpacket_sm_0_i_6_r_3_t_4_cnt, S5S8SMStore::mpacket_sm_0_i_6_r_3_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_6_r_3_t_5_busy, S5S8SMStore::mpacket_sm_0_i_6_r_3_t_5_cnt, S5S8SMStore::mpacket_sm_0_i_6_r_3_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_6_r_3_t_6_busy, S5S8SMStore::mpacket_sm_0_i_6_r_3_t_6_cnt, S5S8SMStore::mpacket_sm_0_i_6_r_3_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_6_r_3_t_7_busy, S5S8SMStore::mpacket_sm_0_i_6_r_3_t_7_cnt, S5S8SMStore::mpacket_sm_0_i_6_r_3_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_6_r_3_t_8_busy, S5S8SMStore::mpacket_sm_0_i_6_r_3_t_8_cnt, S5S8SMStore::mpacket_sm_0_i_6_r_3_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_6_r_3_t_9_busy, S5S8SMStore::mpacket_sm_0_i_6_r_3_t_9_cnt, S5S8SMStore::mpacket_sm_0_i_6_r_3_t_9, msgObj);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_6_r_3_t_0_busy, S5S8SMStore::mpacket_sm_1_i_6_r_3_t_0_cnt, S5S8SMStore::mpacket_sm_1_i_6_r_3_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_6_r_3_t_1_busy, S5S8SMStore::mpacket_sm_1_i_6_r_3_t_1_cnt, S5S8SMStore::mpacket_sm_1_i_6_r_3_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_6_r_3_t_2_busy, S5S8SMStore::mpacket_sm_1_i_6_r_3_t_2_cnt, S5S8SMStore::mpacket_sm_1_i_6_r_3_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_6_r_3_t_3_busy, S5S8SMStore::mpacket_sm_1_i_6_r_3_t_3_cnt, S5S8SMStore::mpacket_sm_1_i_6_r_3_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_6_r_3_t_4_busy, S5S8SMStore::mpacket_sm_1_i_6_r_3_t_4_cnt, S5S8SMStore::mpacket_sm_1_i_6_r_3_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_6_r_3_t_5_busy, S5S8SMStore::mpacket_sm_1_i_6_r_3_t_5_cnt, S5S8SMStore::mpacket_sm_1_i_6_r_3_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_6_r_3_t_6_busy, S5S8SMStore::mpacket_sm_1_i_6_r_3_t_6_cnt, S5S8SMStore::mpacket_sm_1_i_6_r_3_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_6_r_3_t_7_busy, S5S8SMStore::mpacket_sm_1_i_6_r_3_t_7_cnt, S5S8SMStore::mpacket_sm_1_i_6_r_3_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_6_r_3_t_8_busy, S5S8SMStore::mpacket_sm_1_i_6_r_3_t_8_cnt, S5S8SMStore::mpacket_sm_1_i_6_r_3_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_6_r_3_t_9_busy, S5S8SMStore::mpacket_sm_1_i_6_r_3_t_9_cnt, S5S8SMStore::mpacket_sm_1_i_6_r_3_t_9, msgObj);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_6_r_3_t_0_busy, S5S8SMStore::mpacket_sm_2_i_6_r_3_t_0_cnt, S5S8SMStore::mpacket_sm_2_i_6_r_3_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_6_r_3_t_1_busy, S5S8SMStore::mpacket_sm_2_i_6_r_3_t_1_cnt, S5S8SMStore::mpacket_sm_2_i_6_r_3_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_6_r_3_t_2_busy, S5S8SMStore::mpacket_sm_2_i_6_r_3_t_2_cnt, S5S8SMStore::mpacket_sm_2_i_6_r_3_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_6_r_3_t_3_busy, S5S8SMStore::mpacket_sm_2_i_6_r_3_t_3_cnt, S5S8SMStore::mpacket_sm_2_i_6_r_3_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_6_r_3_t_4_busy, S5S8SMStore::mpacket_sm_2_i_6_r_3_t_4_cnt, S5S8SMStore::mpacket_sm_2_i_6_r_3_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_6_r_3_t_5_busy, S5S8SMStore::mpacket_sm_2_i_6_r_3_t_5_cnt, S5S8SMStore::mpacket_sm_2_i_6_r_3_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_6_r_3_t_6_busy, S5S8SMStore::mpacket_sm_2_i_6_r_3_t_6_cnt, S5S8SMStore::mpacket_sm_2_i_6_r_3_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_6_r_3_t_7_busy, S5S8SMStore::mpacket_sm_2_i_6_r_3_t_7_cnt, S5S8SMStore::mpacket_sm_2_i_6_r_3_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_6_r_3_t_8_busy, S5S8SMStore::mpacket_sm_2_i_6_r_3_t_8_cnt, S5S8SMStore::mpacket_sm_2_i_6_r_3_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_6_r_3_t_9_busy, S5S8SMStore::mpacket_sm_2_i_6_r_3_t_9_cnt, S5S8SMStore::mpacket_sm_2_i_6_r_3_t_9, msgObj);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_6_r_3_t_0_busy, S5S8SMStore::mpacket_sm_3_i_6_r_3_t_0_cnt, S5S8SMStore::mpacket_sm_3_i_6_r_3_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_6_r_3_t_1_busy, S5S8SMStore::mpacket_sm_3_i_6_r_3_t_1_cnt, S5S8SMStore::mpacket_sm_3_i_6_r_3_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_6_r_3_t_2_busy, S5S8SMStore::mpacket_sm_3_i_6_r_3_t_2_cnt, S5S8SMStore::mpacket_sm_3_i_6_r_3_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_6_r_3_t_3_busy, S5S8SMStore::mpacket_sm_3_i_6_r_3_t_3_cnt, S5S8SMStore::mpacket_sm_3_i_6_r_3_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_6_r_3_t_4_busy, S5S8SMStore::mpacket_sm_3_i_6_r_3_t_4_cnt, S5S8SMStore::mpacket_sm_3_i_6_r_3_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_6_r_3_t_5_busy, S5S8SMStore::mpacket_sm_3_i_6_r_3_t_5_cnt, S5S8SMStore::mpacket_sm_3_i_6_r_3_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_6_r_3_t_6_busy, S5S8SMStore::mpacket_sm_3_i_6_r_3_t_6_cnt, S5S8SMStore::mpacket_sm_3_i_6_r_3_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_6_r_3_t_7_busy, S5S8SMStore::mpacket_sm_3_i_6_r_3_t_7_cnt, S5S8SMStore::mpacket_sm_3_i_6_r_3_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_6_r_3_t_8_busy, S5S8SMStore::mpacket_sm_3_i_6_r_3_t_8_cnt, S5S8SMStore::mpacket_sm_3_i_6_r_3_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_6_r_3_t_9_busy, S5S8SMStore::mpacket_sm_3_i_6_r_3_t_9_cnt, S5S8SMStore::mpacket_sm_3_i_6_r_3_t_9, msgObj);
				break;
			}
			break;
	}
}

VOID S5S8MessageBroker::pushToQueue_i_6_r_4(MPacket *msgObj, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_6_r_4_t_0_busy, S5S8SMStore::mpacket_sm_0_i_6_r_4_t_0_cnt, S5S8SMStore::mpacket_sm_0_i_6_r_4_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_6_r_4_t_1_busy, S5S8SMStore::mpacket_sm_0_i_6_r_4_t_1_cnt, S5S8SMStore::mpacket_sm_0_i_6_r_4_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_6_r_4_t_2_busy, S5S8SMStore::mpacket_sm_0_i_6_r_4_t_2_cnt, S5S8SMStore::mpacket_sm_0_i_6_r_4_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_6_r_4_t_3_busy, S5S8SMStore::mpacket_sm_0_i_6_r_4_t_3_cnt, S5S8SMStore::mpacket_sm_0_i_6_r_4_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_6_r_4_t_4_busy, S5S8SMStore::mpacket_sm_0_i_6_r_4_t_4_cnt, S5S8SMStore::mpacket_sm_0_i_6_r_4_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_6_r_4_t_5_busy, S5S8SMStore::mpacket_sm_0_i_6_r_4_t_5_cnt, S5S8SMStore::mpacket_sm_0_i_6_r_4_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_6_r_4_t_6_busy, S5S8SMStore::mpacket_sm_0_i_6_r_4_t_6_cnt, S5S8SMStore::mpacket_sm_0_i_6_r_4_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_6_r_4_t_7_busy, S5S8SMStore::mpacket_sm_0_i_6_r_4_t_7_cnt, S5S8SMStore::mpacket_sm_0_i_6_r_4_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_6_r_4_t_8_busy, S5S8SMStore::mpacket_sm_0_i_6_r_4_t_8_cnt, S5S8SMStore::mpacket_sm_0_i_6_r_4_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_6_r_4_t_9_busy, S5S8SMStore::mpacket_sm_0_i_6_r_4_t_9_cnt, S5S8SMStore::mpacket_sm_0_i_6_r_4_t_9, msgObj);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_6_r_4_t_0_busy, S5S8SMStore::mpacket_sm_1_i_6_r_4_t_0_cnt, S5S8SMStore::mpacket_sm_1_i_6_r_4_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_6_r_4_t_1_busy, S5S8SMStore::mpacket_sm_1_i_6_r_4_t_1_cnt, S5S8SMStore::mpacket_sm_1_i_6_r_4_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_6_r_4_t_2_busy, S5S8SMStore::mpacket_sm_1_i_6_r_4_t_2_cnt, S5S8SMStore::mpacket_sm_1_i_6_r_4_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_6_r_4_t_3_busy, S5S8SMStore::mpacket_sm_1_i_6_r_4_t_3_cnt, S5S8SMStore::mpacket_sm_1_i_6_r_4_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_6_r_4_t_4_busy, S5S8SMStore::mpacket_sm_1_i_6_r_4_t_4_cnt, S5S8SMStore::mpacket_sm_1_i_6_r_4_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_6_r_4_t_5_busy, S5S8SMStore::mpacket_sm_1_i_6_r_4_t_5_cnt, S5S8SMStore::mpacket_sm_1_i_6_r_4_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_6_r_4_t_6_busy, S5S8SMStore::mpacket_sm_1_i_6_r_4_t_6_cnt, S5S8SMStore::mpacket_sm_1_i_6_r_4_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_6_r_4_t_7_busy, S5S8SMStore::mpacket_sm_1_i_6_r_4_t_7_cnt, S5S8SMStore::mpacket_sm_1_i_6_r_4_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_6_r_4_t_8_busy, S5S8SMStore::mpacket_sm_1_i_6_r_4_t_8_cnt, S5S8SMStore::mpacket_sm_1_i_6_r_4_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_6_r_4_t_9_busy, S5S8SMStore::mpacket_sm_1_i_6_r_4_t_9_cnt, S5S8SMStore::mpacket_sm_1_i_6_r_4_t_9, msgObj);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_6_r_4_t_0_busy, S5S8SMStore::mpacket_sm_2_i_6_r_4_t_0_cnt, S5S8SMStore::mpacket_sm_2_i_6_r_4_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_6_r_4_t_1_busy, S5S8SMStore::mpacket_sm_2_i_6_r_4_t_1_cnt, S5S8SMStore::mpacket_sm_2_i_6_r_4_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_6_r_4_t_2_busy, S5S8SMStore::mpacket_sm_2_i_6_r_4_t_2_cnt, S5S8SMStore::mpacket_sm_2_i_6_r_4_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_6_r_4_t_3_busy, S5S8SMStore::mpacket_sm_2_i_6_r_4_t_3_cnt, S5S8SMStore::mpacket_sm_2_i_6_r_4_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_6_r_4_t_4_busy, S5S8SMStore::mpacket_sm_2_i_6_r_4_t_4_cnt, S5S8SMStore::mpacket_sm_2_i_6_r_4_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_6_r_4_t_5_busy, S5S8SMStore::mpacket_sm_2_i_6_r_4_t_5_cnt, S5S8SMStore::mpacket_sm_2_i_6_r_4_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_6_r_4_t_6_busy, S5S8SMStore::mpacket_sm_2_i_6_r_4_t_6_cnt, S5S8SMStore::mpacket_sm_2_i_6_r_4_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_6_r_4_t_7_busy, S5S8SMStore::mpacket_sm_2_i_6_r_4_t_7_cnt, S5S8SMStore::mpacket_sm_2_i_6_r_4_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_6_r_4_t_8_busy, S5S8SMStore::mpacket_sm_2_i_6_r_4_t_8_cnt, S5S8SMStore::mpacket_sm_2_i_6_r_4_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_6_r_4_t_9_busy, S5S8SMStore::mpacket_sm_2_i_6_r_4_t_9_cnt, S5S8SMStore::mpacket_sm_2_i_6_r_4_t_9, msgObj);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_6_r_4_t_0_busy, S5S8SMStore::mpacket_sm_3_i_6_r_4_t_0_cnt, S5S8SMStore::mpacket_sm_3_i_6_r_4_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_6_r_4_t_1_busy, S5S8SMStore::mpacket_sm_3_i_6_r_4_t_1_cnt, S5S8SMStore::mpacket_sm_3_i_6_r_4_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_6_r_4_t_2_busy, S5S8SMStore::mpacket_sm_3_i_6_r_4_t_2_cnt, S5S8SMStore::mpacket_sm_3_i_6_r_4_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_6_r_4_t_3_busy, S5S8SMStore::mpacket_sm_3_i_6_r_4_t_3_cnt, S5S8SMStore::mpacket_sm_3_i_6_r_4_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_6_r_4_t_4_busy, S5S8SMStore::mpacket_sm_3_i_6_r_4_t_4_cnt, S5S8SMStore::mpacket_sm_3_i_6_r_4_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_6_r_4_t_5_busy, S5S8SMStore::mpacket_sm_3_i_6_r_4_t_5_cnt, S5S8SMStore::mpacket_sm_3_i_6_r_4_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_6_r_4_t_6_busy, S5S8SMStore::mpacket_sm_3_i_6_r_4_t_6_cnt, S5S8SMStore::mpacket_sm_3_i_6_r_4_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_6_r_4_t_7_busy, S5S8SMStore::mpacket_sm_3_i_6_r_4_t_7_cnt, S5S8SMStore::mpacket_sm_3_i_6_r_4_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_6_r_4_t_8_busy, S5S8SMStore::mpacket_sm_3_i_6_r_4_t_8_cnt, S5S8SMStore::mpacket_sm_3_i_6_r_4_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_6_r_4_t_9_busy, S5S8SMStore::mpacket_sm_3_i_6_r_4_t_9_cnt, S5S8SMStore::mpacket_sm_3_i_6_r_4_t_9, msgObj);
				break;
			}
			break;
	}
}

VOID S5S8MessageBroker::pushToQueue_i_6_r_5(MPacket *msgObj, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_6_r_5_t_0_busy, S5S8SMStore::mpacket_sm_0_i_6_r_5_t_0_cnt, S5S8SMStore::mpacket_sm_0_i_6_r_5_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_6_r_5_t_1_busy, S5S8SMStore::mpacket_sm_0_i_6_r_5_t_1_cnt, S5S8SMStore::mpacket_sm_0_i_6_r_5_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_6_r_5_t_2_busy, S5S8SMStore::mpacket_sm_0_i_6_r_5_t_2_cnt, S5S8SMStore::mpacket_sm_0_i_6_r_5_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_6_r_5_t_3_busy, S5S8SMStore::mpacket_sm_0_i_6_r_5_t_3_cnt, S5S8SMStore::mpacket_sm_0_i_6_r_5_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_6_r_5_t_4_busy, S5S8SMStore::mpacket_sm_0_i_6_r_5_t_4_cnt, S5S8SMStore::mpacket_sm_0_i_6_r_5_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_6_r_5_t_5_busy, S5S8SMStore::mpacket_sm_0_i_6_r_5_t_5_cnt, S5S8SMStore::mpacket_sm_0_i_6_r_5_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_6_r_5_t_6_busy, S5S8SMStore::mpacket_sm_0_i_6_r_5_t_6_cnt, S5S8SMStore::mpacket_sm_0_i_6_r_5_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_6_r_5_t_7_busy, S5S8SMStore::mpacket_sm_0_i_6_r_5_t_7_cnt, S5S8SMStore::mpacket_sm_0_i_6_r_5_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_6_r_5_t_8_busy, S5S8SMStore::mpacket_sm_0_i_6_r_5_t_8_cnt, S5S8SMStore::mpacket_sm_0_i_6_r_5_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_6_r_5_t_9_busy, S5S8SMStore::mpacket_sm_0_i_6_r_5_t_9_cnt, S5S8SMStore::mpacket_sm_0_i_6_r_5_t_9, msgObj);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_6_r_5_t_0_busy, S5S8SMStore::mpacket_sm_1_i_6_r_5_t_0_cnt, S5S8SMStore::mpacket_sm_1_i_6_r_5_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_6_r_5_t_1_busy, S5S8SMStore::mpacket_sm_1_i_6_r_5_t_1_cnt, S5S8SMStore::mpacket_sm_1_i_6_r_5_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_6_r_5_t_2_busy, S5S8SMStore::mpacket_sm_1_i_6_r_5_t_2_cnt, S5S8SMStore::mpacket_sm_1_i_6_r_5_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_6_r_5_t_3_busy, S5S8SMStore::mpacket_sm_1_i_6_r_5_t_3_cnt, S5S8SMStore::mpacket_sm_1_i_6_r_5_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_6_r_5_t_4_busy, S5S8SMStore::mpacket_sm_1_i_6_r_5_t_4_cnt, S5S8SMStore::mpacket_sm_1_i_6_r_5_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_6_r_5_t_5_busy, S5S8SMStore::mpacket_sm_1_i_6_r_5_t_5_cnt, S5S8SMStore::mpacket_sm_1_i_6_r_5_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_6_r_5_t_6_busy, S5S8SMStore::mpacket_sm_1_i_6_r_5_t_6_cnt, S5S8SMStore::mpacket_sm_1_i_6_r_5_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_6_r_5_t_7_busy, S5S8SMStore::mpacket_sm_1_i_6_r_5_t_7_cnt, S5S8SMStore::mpacket_sm_1_i_6_r_5_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_6_r_5_t_8_busy, S5S8SMStore::mpacket_sm_1_i_6_r_5_t_8_cnt, S5S8SMStore::mpacket_sm_1_i_6_r_5_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_6_r_5_t_9_busy, S5S8SMStore::mpacket_sm_1_i_6_r_5_t_9_cnt, S5S8SMStore::mpacket_sm_1_i_6_r_5_t_9, msgObj);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_6_r_5_t_0_busy, S5S8SMStore::mpacket_sm_2_i_6_r_5_t_0_cnt, S5S8SMStore::mpacket_sm_2_i_6_r_5_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_6_r_5_t_1_busy, S5S8SMStore::mpacket_sm_2_i_6_r_5_t_1_cnt, S5S8SMStore::mpacket_sm_2_i_6_r_5_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_6_r_5_t_2_busy, S5S8SMStore::mpacket_sm_2_i_6_r_5_t_2_cnt, S5S8SMStore::mpacket_sm_2_i_6_r_5_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_6_r_5_t_3_busy, S5S8SMStore::mpacket_sm_2_i_6_r_5_t_3_cnt, S5S8SMStore::mpacket_sm_2_i_6_r_5_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_6_r_5_t_4_busy, S5S8SMStore::mpacket_sm_2_i_6_r_5_t_4_cnt, S5S8SMStore::mpacket_sm_2_i_6_r_5_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_6_r_5_t_5_busy, S5S8SMStore::mpacket_sm_2_i_6_r_5_t_5_cnt, S5S8SMStore::mpacket_sm_2_i_6_r_5_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_6_r_5_t_6_busy, S5S8SMStore::mpacket_sm_2_i_6_r_5_t_6_cnt, S5S8SMStore::mpacket_sm_2_i_6_r_5_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_6_r_5_t_7_busy, S5S8SMStore::mpacket_sm_2_i_6_r_5_t_7_cnt, S5S8SMStore::mpacket_sm_2_i_6_r_5_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_6_r_5_t_8_busy, S5S8SMStore::mpacket_sm_2_i_6_r_5_t_8_cnt, S5S8SMStore::mpacket_sm_2_i_6_r_5_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_6_r_5_t_9_busy, S5S8SMStore::mpacket_sm_2_i_6_r_5_t_9_cnt, S5S8SMStore::mpacket_sm_2_i_6_r_5_t_9, msgObj);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_6_r_5_t_0_busy, S5S8SMStore::mpacket_sm_3_i_6_r_5_t_0_cnt, S5S8SMStore::mpacket_sm_3_i_6_r_5_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_6_r_5_t_1_busy, S5S8SMStore::mpacket_sm_3_i_6_r_5_t_1_cnt, S5S8SMStore::mpacket_sm_3_i_6_r_5_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_6_r_5_t_2_busy, S5S8SMStore::mpacket_sm_3_i_6_r_5_t_2_cnt, S5S8SMStore::mpacket_sm_3_i_6_r_5_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_6_r_5_t_3_busy, S5S8SMStore::mpacket_sm_3_i_6_r_5_t_3_cnt, S5S8SMStore::mpacket_sm_3_i_6_r_5_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_6_r_5_t_4_busy, S5S8SMStore::mpacket_sm_3_i_6_r_5_t_4_cnt, S5S8SMStore::mpacket_sm_3_i_6_r_5_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_6_r_5_t_5_busy, S5S8SMStore::mpacket_sm_3_i_6_r_5_t_5_cnt, S5S8SMStore::mpacket_sm_3_i_6_r_5_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_6_r_5_t_6_busy, S5S8SMStore::mpacket_sm_3_i_6_r_5_t_6_cnt, S5S8SMStore::mpacket_sm_3_i_6_r_5_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_6_r_5_t_7_busy, S5S8SMStore::mpacket_sm_3_i_6_r_5_t_7_cnt, S5S8SMStore::mpacket_sm_3_i_6_r_5_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_6_r_5_t_8_busy, S5S8SMStore::mpacket_sm_3_i_6_r_5_t_8_cnt, S5S8SMStore::mpacket_sm_3_i_6_r_5_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_6_r_5_t_9_busy, S5S8SMStore::mpacket_sm_3_i_6_r_5_t_9_cnt, S5S8SMStore::mpacket_sm_3_i_6_r_5_t_9, msgObj);
				break;
			}
			break;
	}
}

VOID S5S8MessageBroker::pushToQueue_i_6_r_6(MPacket *msgObj, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_6_r_6_t_0_busy, S5S8SMStore::mpacket_sm_0_i_6_r_6_t_0_cnt, S5S8SMStore::mpacket_sm_0_i_6_r_6_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_6_r_6_t_1_busy, S5S8SMStore::mpacket_sm_0_i_6_r_6_t_1_cnt, S5S8SMStore::mpacket_sm_0_i_6_r_6_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_6_r_6_t_2_busy, S5S8SMStore::mpacket_sm_0_i_6_r_6_t_2_cnt, S5S8SMStore::mpacket_sm_0_i_6_r_6_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_6_r_6_t_3_busy, S5S8SMStore::mpacket_sm_0_i_6_r_6_t_3_cnt, S5S8SMStore::mpacket_sm_0_i_6_r_6_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_6_r_6_t_4_busy, S5S8SMStore::mpacket_sm_0_i_6_r_6_t_4_cnt, S5S8SMStore::mpacket_sm_0_i_6_r_6_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_6_r_6_t_5_busy, S5S8SMStore::mpacket_sm_0_i_6_r_6_t_5_cnt, S5S8SMStore::mpacket_sm_0_i_6_r_6_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_6_r_6_t_6_busy, S5S8SMStore::mpacket_sm_0_i_6_r_6_t_6_cnt, S5S8SMStore::mpacket_sm_0_i_6_r_6_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_6_r_6_t_7_busy, S5S8SMStore::mpacket_sm_0_i_6_r_6_t_7_cnt, S5S8SMStore::mpacket_sm_0_i_6_r_6_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_6_r_6_t_8_busy, S5S8SMStore::mpacket_sm_0_i_6_r_6_t_8_cnt, S5S8SMStore::mpacket_sm_0_i_6_r_6_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_6_r_6_t_9_busy, S5S8SMStore::mpacket_sm_0_i_6_r_6_t_9_cnt, S5S8SMStore::mpacket_sm_0_i_6_r_6_t_9, msgObj);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_6_r_6_t_0_busy, S5S8SMStore::mpacket_sm_1_i_6_r_6_t_0_cnt, S5S8SMStore::mpacket_sm_1_i_6_r_6_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_6_r_6_t_1_busy, S5S8SMStore::mpacket_sm_1_i_6_r_6_t_1_cnt, S5S8SMStore::mpacket_sm_1_i_6_r_6_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_6_r_6_t_2_busy, S5S8SMStore::mpacket_sm_1_i_6_r_6_t_2_cnt, S5S8SMStore::mpacket_sm_1_i_6_r_6_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_6_r_6_t_3_busy, S5S8SMStore::mpacket_sm_1_i_6_r_6_t_3_cnt, S5S8SMStore::mpacket_sm_1_i_6_r_6_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_6_r_6_t_4_busy, S5S8SMStore::mpacket_sm_1_i_6_r_6_t_4_cnt, S5S8SMStore::mpacket_sm_1_i_6_r_6_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_6_r_6_t_5_busy, S5S8SMStore::mpacket_sm_1_i_6_r_6_t_5_cnt, S5S8SMStore::mpacket_sm_1_i_6_r_6_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_6_r_6_t_6_busy, S5S8SMStore::mpacket_sm_1_i_6_r_6_t_6_cnt, S5S8SMStore::mpacket_sm_1_i_6_r_6_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_6_r_6_t_7_busy, S5S8SMStore::mpacket_sm_1_i_6_r_6_t_7_cnt, S5S8SMStore::mpacket_sm_1_i_6_r_6_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_6_r_6_t_8_busy, S5S8SMStore::mpacket_sm_1_i_6_r_6_t_8_cnt, S5S8SMStore::mpacket_sm_1_i_6_r_6_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_6_r_6_t_9_busy, S5S8SMStore::mpacket_sm_1_i_6_r_6_t_9_cnt, S5S8SMStore::mpacket_sm_1_i_6_r_6_t_9, msgObj);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_6_r_6_t_0_busy, S5S8SMStore::mpacket_sm_2_i_6_r_6_t_0_cnt, S5S8SMStore::mpacket_sm_2_i_6_r_6_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_6_r_6_t_1_busy, S5S8SMStore::mpacket_sm_2_i_6_r_6_t_1_cnt, S5S8SMStore::mpacket_sm_2_i_6_r_6_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_6_r_6_t_2_busy, S5S8SMStore::mpacket_sm_2_i_6_r_6_t_2_cnt, S5S8SMStore::mpacket_sm_2_i_6_r_6_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_6_r_6_t_3_busy, S5S8SMStore::mpacket_sm_2_i_6_r_6_t_3_cnt, S5S8SMStore::mpacket_sm_2_i_6_r_6_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_6_r_6_t_4_busy, S5S8SMStore::mpacket_sm_2_i_6_r_6_t_4_cnt, S5S8SMStore::mpacket_sm_2_i_6_r_6_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_6_r_6_t_5_busy, S5S8SMStore::mpacket_sm_2_i_6_r_6_t_5_cnt, S5S8SMStore::mpacket_sm_2_i_6_r_6_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_6_r_6_t_6_busy, S5S8SMStore::mpacket_sm_2_i_6_r_6_t_6_cnt, S5S8SMStore::mpacket_sm_2_i_6_r_6_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_6_r_6_t_7_busy, S5S8SMStore::mpacket_sm_2_i_6_r_6_t_7_cnt, S5S8SMStore::mpacket_sm_2_i_6_r_6_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_6_r_6_t_8_busy, S5S8SMStore::mpacket_sm_2_i_6_r_6_t_8_cnt, S5S8SMStore::mpacket_sm_2_i_6_r_6_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_6_r_6_t_9_busy, S5S8SMStore::mpacket_sm_2_i_6_r_6_t_9_cnt, S5S8SMStore::mpacket_sm_2_i_6_r_6_t_9, msgObj);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_6_r_6_t_0_busy, S5S8SMStore::mpacket_sm_3_i_6_r_6_t_0_cnt, S5S8SMStore::mpacket_sm_3_i_6_r_6_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_6_r_6_t_1_busy, S5S8SMStore::mpacket_sm_3_i_6_r_6_t_1_cnt, S5S8SMStore::mpacket_sm_3_i_6_r_6_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_6_r_6_t_2_busy, S5S8SMStore::mpacket_sm_3_i_6_r_6_t_2_cnt, S5S8SMStore::mpacket_sm_3_i_6_r_6_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_6_r_6_t_3_busy, S5S8SMStore::mpacket_sm_3_i_6_r_6_t_3_cnt, S5S8SMStore::mpacket_sm_3_i_6_r_6_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_6_r_6_t_4_busy, S5S8SMStore::mpacket_sm_3_i_6_r_6_t_4_cnt, S5S8SMStore::mpacket_sm_3_i_6_r_6_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_6_r_6_t_5_busy, S5S8SMStore::mpacket_sm_3_i_6_r_6_t_5_cnt, S5S8SMStore::mpacket_sm_3_i_6_r_6_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_6_r_6_t_6_busy, S5S8SMStore::mpacket_sm_3_i_6_r_6_t_6_cnt, S5S8SMStore::mpacket_sm_3_i_6_r_6_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_6_r_6_t_7_busy, S5S8SMStore::mpacket_sm_3_i_6_r_6_t_7_cnt, S5S8SMStore::mpacket_sm_3_i_6_r_6_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_6_r_6_t_8_busy, S5S8SMStore::mpacket_sm_3_i_6_r_6_t_8_cnt, S5S8SMStore::mpacket_sm_3_i_6_r_6_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_6_r_6_t_9_busy, S5S8SMStore::mpacket_sm_3_i_6_r_6_t_9_cnt, S5S8SMStore::mpacket_sm_3_i_6_r_6_t_9, msgObj);
				break;
			}
			break;
	}
}

VOID S5S8MessageBroker::pushToQueue_i_6_r_7(MPacket *msgObj, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_6_r_7_t_0_busy, S5S8SMStore::mpacket_sm_0_i_6_r_7_t_0_cnt, S5S8SMStore::mpacket_sm_0_i_6_r_7_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_6_r_7_t_1_busy, S5S8SMStore::mpacket_sm_0_i_6_r_7_t_1_cnt, S5S8SMStore::mpacket_sm_0_i_6_r_7_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_6_r_7_t_2_busy, S5S8SMStore::mpacket_sm_0_i_6_r_7_t_2_cnt, S5S8SMStore::mpacket_sm_0_i_6_r_7_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_6_r_7_t_3_busy, S5S8SMStore::mpacket_sm_0_i_6_r_7_t_3_cnt, S5S8SMStore::mpacket_sm_0_i_6_r_7_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_6_r_7_t_4_busy, S5S8SMStore::mpacket_sm_0_i_6_r_7_t_4_cnt, S5S8SMStore::mpacket_sm_0_i_6_r_7_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_6_r_7_t_5_busy, S5S8SMStore::mpacket_sm_0_i_6_r_7_t_5_cnt, S5S8SMStore::mpacket_sm_0_i_6_r_7_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_6_r_7_t_6_busy, S5S8SMStore::mpacket_sm_0_i_6_r_7_t_6_cnt, S5S8SMStore::mpacket_sm_0_i_6_r_7_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_6_r_7_t_7_busy, S5S8SMStore::mpacket_sm_0_i_6_r_7_t_7_cnt, S5S8SMStore::mpacket_sm_0_i_6_r_7_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_6_r_7_t_8_busy, S5S8SMStore::mpacket_sm_0_i_6_r_7_t_8_cnt, S5S8SMStore::mpacket_sm_0_i_6_r_7_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_6_r_7_t_9_busy, S5S8SMStore::mpacket_sm_0_i_6_r_7_t_9_cnt, S5S8SMStore::mpacket_sm_0_i_6_r_7_t_9, msgObj);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_6_r_7_t_0_busy, S5S8SMStore::mpacket_sm_1_i_6_r_7_t_0_cnt, S5S8SMStore::mpacket_sm_1_i_6_r_7_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_6_r_7_t_1_busy, S5S8SMStore::mpacket_sm_1_i_6_r_7_t_1_cnt, S5S8SMStore::mpacket_sm_1_i_6_r_7_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_6_r_7_t_2_busy, S5S8SMStore::mpacket_sm_1_i_6_r_7_t_2_cnt, S5S8SMStore::mpacket_sm_1_i_6_r_7_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_6_r_7_t_3_busy, S5S8SMStore::mpacket_sm_1_i_6_r_7_t_3_cnt, S5S8SMStore::mpacket_sm_1_i_6_r_7_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_6_r_7_t_4_busy, S5S8SMStore::mpacket_sm_1_i_6_r_7_t_4_cnt, S5S8SMStore::mpacket_sm_1_i_6_r_7_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_6_r_7_t_5_busy, S5S8SMStore::mpacket_sm_1_i_6_r_7_t_5_cnt, S5S8SMStore::mpacket_sm_1_i_6_r_7_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_6_r_7_t_6_busy, S5S8SMStore::mpacket_sm_1_i_6_r_7_t_6_cnt, S5S8SMStore::mpacket_sm_1_i_6_r_7_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_6_r_7_t_7_busy, S5S8SMStore::mpacket_sm_1_i_6_r_7_t_7_cnt, S5S8SMStore::mpacket_sm_1_i_6_r_7_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_6_r_7_t_8_busy, S5S8SMStore::mpacket_sm_1_i_6_r_7_t_8_cnt, S5S8SMStore::mpacket_sm_1_i_6_r_7_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_6_r_7_t_9_busy, S5S8SMStore::mpacket_sm_1_i_6_r_7_t_9_cnt, S5S8SMStore::mpacket_sm_1_i_6_r_7_t_9, msgObj);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_6_r_7_t_0_busy, S5S8SMStore::mpacket_sm_2_i_6_r_7_t_0_cnt, S5S8SMStore::mpacket_sm_2_i_6_r_7_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_6_r_7_t_1_busy, S5S8SMStore::mpacket_sm_2_i_6_r_7_t_1_cnt, S5S8SMStore::mpacket_sm_2_i_6_r_7_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_6_r_7_t_2_busy, S5S8SMStore::mpacket_sm_2_i_6_r_7_t_2_cnt, S5S8SMStore::mpacket_sm_2_i_6_r_7_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_6_r_7_t_3_busy, S5S8SMStore::mpacket_sm_2_i_6_r_7_t_3_cnt, S5S8SMStore::mpacket_sm_2_i_6_r_7_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_6_r_7_t_4_busy, S5S8SMStore::mpacket_sm_2_i_6_r_7_t_4_cnt, S5S8SMStore::mpacket_sm_2_i_6_r_7_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_6_r_7_t_5_busy, S5S8SMStore::mpacket_sm_2_i_6_r_7_t_5_cnt, S5S8SMStore::mpacket_sm_2_i_6_r_7_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_6_r_7_t_6_busy, S5S8SMStore::mpacket_sm_2_i_6_r_7_t_6_cnt, S5S8SMStore::mpacket_sm_2_i_6_r_7_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_6_r_7_t_7_busy, S5S8SMStore::mpacket_sm_2_i_6_r_7_t_7_cnt, S5S8SMStore::mpacket_sm_2_i_6_r_7_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_6_r_7_t_8_busy, S5S8SMStore::mpacket_sm_2_i_6_r_7_t_8_cnt, S5S8SMStore::mpacket_sm_2_i_6_r_7_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_6_r_7_t_9_busy, S5S8SMStore::mpacket_sm_2_i_6_r_7_t_9_cnt, S5S8SMStore::mpacket_sm_2_i_6_r_7_t_9, msgObj);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_6_r_7_t_0_busy, S5S8SMStore::mpacket_sm_3_i_6_r_7_t_0_cnt, S5S8SMStore::mpacket_sm_3_i_6_r_7_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_6_r_7_t_1_busy, S5S8SMStore::mpacket_sm_3_i_6_r_7_t_1_cnt, S5S8SMStore::mpacket_sm_3_i_6_r_7_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_6_r_7_t_2_busy, S5S8SMStore::mpacket_sm_3_i_6_r_7_t_2_cnt, S5S8SMStore::mpacket_sm_3_i_6_r_7_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_6_r_7_t_3_busy, S5S8SMStore::mpacket_sm_3_i_6_r_7_t_3_cnt, S5S8SMStore::mpacket_sm_3_i_6_r_7_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_6_r_7_t_4_busy, S5S8SMStore::mpacket_sm_3_i_6_r_7_t_4_cnt, S5S8SMStore::mpacket_sm_3_i_6_r_7_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_6_r_7_t_5_busy, S5S8SMStore::mpacket_sm_3_i_6_r_7_t_5_cnt, S5S8SMStore::mpacket_sm_3_i_6_r_7_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_6_r_7_t_6_busy, S5S8SMStore::mpacket_sm_3_i_6_r_7_t_6_cnt, S5S8SMStore::mpacket_sm_3_i_6_r_7_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_6_r_7_t_7_busy, S5S8SMStore::mpacket_sm_3_i_6_r_7_t_7_cnt, S5S8SMStore::mpacket_sm_3_i_6_r_7_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_6_r_7_t_8_busy, S5S8SMStore::mpacket_sm_3_i_6_r_7_t_8_cnt, S5S8SMStore::mpacket_sm_3_i_6_r_7_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_6_r_7_t_9_busy, S5S8SMStore::mpacket_sm_3_i_6_r_7_t_9_cnt, S5S8SMStore::mpacket_sm_3_i_6_r_7_t_9, msgObj);
				break;
			}
			break;
	}
}


VOID S5S8MessageBroker::pushToQueue_i_7_r_0(MPacket *msgObj, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_7_r_0_t_0_busy, S5S8SMStore::mpacket_sm_0_i_7_r_0_t_0_cnt, S5S8SMStore::mpacket_sm_0_i_7_r_0_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_7_r_0_t_1_busy, S5S8SMStore::mpacket_sm_0_i_7_r_0_t_1_cnt, S5S8SMStore::mpacket_sm_0_i_7_r_0_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_7_r_0_t_2_busy, S5S8SMStore::mpacket_sm_0_i_7_r_0_t_2_cnt, S5S8SMStore::mpacket_sm_0_i_7_r_0_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_7_r_0_t_3_busy, S5S8SMStore::mpacket_sm_0_i_7_r_0_t_3_cnt, S5S8SMStore::mpacket_sm_0_i_7_r_0_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_7_r_0_t_4_busy, S5S8SMStore::mpacket_sm_0_i_7_r_0_t_4_cnt, S5S8SMStore::mpacket_sm_0_i_7_r_0_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_7_r_0_t_5_busy, S5S8SMStore::mpacket_sm_0_i_7_r_0_t_5_cnt, S5S8SMStore::mpacket_sm_0_i_7_r_0_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_7_r_0_t_6_busy, S5S8SMStore::mpacket_sm_0_i_7_r_0_t_6_cnt, S5S8SMStore::mpacket_sm_0_i_7_r_0_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_7_r_0_t_7_busy, S5S8SMStore::mpacket_sm_0_i_7_r_0_t_7_cnt, S5S8SMStore::mpacket_sm_0_i_7_r_0_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_7_r_0_t_8_busy, S5S8SMStore::mpacket_sm_0_i_7_r_0_t_8_cnt, S5S8SMStore::mpacket_sm_0_i_7_r_0_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_7_r_0_t_9_busy, S5S8SMStore::mpacket_sm_0_i_7_r_0_t_9_cnt, S5S8SMStore::mpacket_sm_0_i_7_r_0_t_9, msgObj);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_7_r_0_t_0_busy, S5S8SMStore::mpacket_sm_1_i_7_r_0_t_0_cnt, S5S8SMStore::mpacket_sm_1_i_7_r_0_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_7_r_0_t_1_busy, S5S8SMStore::mpacket_sm_1_i_7_r_0_t_1_cnt, S5S8SMStore::mpacket_sm_1_i_7_r_0_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_7_r_0_t_2_busy, S5S8SMStore::mpacket_sm_1_i_7_r_0_t_2_cnt, S5S8SMStore::mpacket_sm_1_i_7_r_0_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_7_r_0_t_3_busy, S5S8SMStore::mpacket_sm_1_i_7_r_0_t_3_cnt, S5S8SMStore::mpacket_sm_1_i_7_r_0_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_7_r_0_t_4_busy, S5S8SMStore::mpacket_sm_1_i_7_r_0_t_4_cnt, S5S8SMStore::mpacket_sm_1_i_7_r_0_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_7_r_0_t_5_busy, S5S8SMStore::mpacket_sm_1_i_7_r_0_t_5_cnt, S5S8SMStore::mpacket_sm_1_i_7_r_0_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_7_r_0_t_6_busy, S5S8SMStore::mpacket_sm_1_i_7_r_0_t_6_cnt, S5S8SMStore::mpacket_sm_1_i_7_r_0_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_7_r_0_t_7_busy, S5S8SMStore::mpacket_sm_1_i_7_r_0_t_7_cnt, S5S8SMStore::mpacket_sm_1_i_7_r_0_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_7_r_0_t_8_busy, S5S8SMStore::mpacket_sm_1_i_7_r_0_t_8_cnt, S5S8SMStore::mpacket_sm_1_i_7_r_0_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_7_r_0_t_9_busy, S5S8SMStore::mpacket_sm_1_i_7_r_0_t_9_cnt, S5S8SMStore::mpacket_sm_1_i_7_r_0_t_9, msgObj);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_7_r_0_t_0_busy, S5S8SMStore::mpacket_sm_2_i_7_r_0_t_0_cnt, S5S8SMStore::mpacket_sm_2_i_7_r_0_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_7_r_0_t_1_busy, S5S8SMStore::mpacket_sm_2_i_7_r_0_t_1_cnt, S5S8SMStore::mpacket_sm_2_i_7_r_0_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_7_r_0_t_2_busy, S5S8SMStore::mpacket_sm_2_i_7_r_0_t_2_cnt, S5S8SMStore::mpacket_sm_2_i_7_r_0_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_7_r_0_t_3_busy, S5S8SMStore::mpacket_sm_2_i_7_r_0_t_3_cnt, S5S8SMStore::mpacket_sm_2_i_7_r_0_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_7_r_0_t_4_busy, S5S8SMStore::mpacket_sm_2_i_7_r_0_t_4_cnt, S5S8SMStore::mpacket_sm_2_i_7_r_0_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_7_r_0_t_5_busy, S5S8SMStore::mpacket_sm_2_i_7_r_0_t_5_cnt, S5S8SMStore::mpacket_sm_2_i_7_r_0_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_7_r_0_t_6_busy, S5S8SMStore::mpacket_sm_2_i_7_r_0_t_6_cnt, S5S8SMStore::mpacket_sm_2_i_7_r_0_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_7_r_0_t_7_busy, S5S8SMStore::mpacket_sm_2_i_7_r_0_t_7_cnt, S5S8SMStore::mpacket_sm_2_i_7_r_0_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_7_r_0_t_8_busy, S5S8SMStore::mpacket_sm_2_i_7_r_0_t_8_cnt, S5S8SMStore::mpacket_sm_2_i_7_r_0_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_7_r_0_t_9_busy, S5S8SMStore::mpacket_sm_2_i_7_r_0_t_9_cnt, S5S8SMStore::mpacket_sm_2_i_7_r_0_t_9, msgObj);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_7_r_0_t_0_busy, S5S8SMStore::mpacket_sm_3_i_7_r_0_t_0_cnt, S5S8SMStore::mpacket_sm_3_i_7_r_0_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_7_r_0_t_1_busy, S5S8SMStore::mpacket_sm_3_i_7_r_0_t_1_cnt, S5S8SMStore::mpacket_sm_3_i_7_r_0_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_7_r_0_t_2_busy, S5S8SMStore::mpacket_sm_3_i_7_r_0_t_2_cnt, S5S8SMStore::mpacket_sm_3_i_7_r_0_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_7_r_0_t_3_busy, S5S8SMStore::mpacket_sm_3_i_7_r_0_t_3_cnt, S5S8SMStore::mpacket_sm_3_i_7_r_0_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_7_r_0_t_4_busy, S5S8SMStore::mpacket_sm_3_i_7_r_0_t_4_cnt, S5S8SMStore::mpacket_sm_3_i_7_r_0_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_7_r_0_t_5_busy, S5S8SMStore::mpacket_sm_3_i_7_r_0_t_5_cnt, S5S8SMStore::mpacket_sm_3_i_7_r_0_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_7_r_0_t_6_busy, S5S8SMStore::mpacket_sm_3_i_7_r_0_t_6_cnt, S5S8SMStore::mpacket_sm_3_i_7_r_0_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_7_r_0_t_7_busy, S5S8SMStore::mpacket_sm_3_i_7_r_0_t_7_cnt, S5S8SMStore::mpacket_sm_3_i_7_r_0_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_7_r_0_t_8_busy, S5S8SMStore::mpacket_sm_3_i_7_r_0_t_8_cnt, S5S8SMStore::mpacket_sm_3_i_7_r_0_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_7_r_0_t_9_busy, S5S8SMStore::mpacket_sm_3_i_7_r_0_t_9_cnt, S5S8SMStore::mpacket_sm_3_i_7_r_0_t_9, msgObj);
				break;
			}
			break;
	}
}

VOID S5S8MessageBroker::pushToQueue_i_7_r_1(MPacket *msgObj, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_7_r_1_t_0_busy, S5S8SMStore::mpacket_sm_0_i_7_r_1_t_0_cnt, S5S8SMStore::mpacket_sm_0_i_7_r_1_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_7_r_1_t_1_busy, S5S8SMStore::mpacket_sm_0_i_7_r_1_t_1_cnt, S5S8SMStore::mpacket_sm_0_i_7_r_1_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_7_r_1_t_2_busy, S5S8SMStore::mpacket_sm_0_i_7_r_1_t_2_cnt, S5S8SMStore::mpacket_sm_0_i_7_r_1_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_7_r_1_t_3_busy, S5S8SMStore::mpacket_sm_0_i_7_r_1_t_3_cnt, S5S8SMStore::mpacket_sm_0_i_7_r_1_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_7_r_1_t_4_busy, S5S8SMStore::mpacket_sm_0_i_7_r_1_t_4_cnt, S5S8SMStore::mpacket_sm_0_i_7_r_1_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_7_r_1_t_5_busy, S5S8SMStore::mpacket_sm_0_i_7_r_1_t_5_cnt, S5S8SMStore::mpacket_sm_0_i_7_r_1_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_7_r_1_t_6_busy, S5S8SMStore::mpacket_sm_0_i_7_r_1_t_6_cnt, S5S8SMStore::mpacket_sm_0_i_7_r_1_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_7_r_1_t_7_busy, S5S8SMStore::mpacket_sm_0_i_7_r_1_t_7_cnt, S5S8SMStore::mpacket_sm_0_i_7_r_1_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_7_r_1_t_8_busy, S5S8SMStore::mpacket_sm_0_i_7_r_1_t_8_cnt, S5S8SMStore::mpacket_sm_0_i_7_r_1_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_7_r_1_t_9_busy, S5S8SMStore::mpacket_sm_0_i_7_r_1_t_9_cnt, S5S8SMStore::mpacket_sm_0_i_7_r_1_t_9, msgObj);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_7_r_1_t_0_busy, S5S8SMStore::mpacket_sm_1_i_7_r_1_t_0_cnt, S5S8SMStore::mpacket_sm_1_i_7_r_1_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_7_r_1_t_1_busy, S5S8SMStore::mpacket_sm_1_i_7_r_1_t_1_cnt, S5S8SMStore::mpacket_sm_1_i_7_r_1_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_7_r_1_t_2_busy, S5S8SMStore::mpacket_sm_1_i_7_r_1_t_2_cnt, S5S8SMStore::mpacket_sm_1_i_7_r_1_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_7_r_1_t_3_busy, S5S8SMStore::mpacket_sm_1_i_7_r_1_t_3_cnt, S5S8SMStore::mpacket_sm_1_i_7_r_1_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_7_r_1_t_4_busy, S5S8SMStore::mpacket_sm_1_i_7_r_1_t_4_cnt, S5S8SMStore::mpacket_sm_1_i_7_r_1_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_7_r_1_t_5_busy, S5S8SMStore::mpacket_sm_1_i_7_r_1_t_5_cnt, S5S8SMStore::mpacket_sm_1_i_7_r_1_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_7_r_1_t_6_busy, S5S8SMStore::mpacket_sm_1_i_7_r_1_t_6_cnt, S5S8SMStore::mpacket_sm_1_i_7_r_1_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_7_r_1_t_7_busy, S5S8SMStore::mpacket_sm_1_i_7_r_1_t_7_cnt, S5S8SMStore::mpacket_sm_1_i_7_r_1_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_7_r_1_t_8_busy, S5S8SMStore::mpacket_sm_1_i_7_r_1_t_8_cnt, S5S8SMStore::mpacket_sm_1_i_7_r_1_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_7_r_1_t_9_busy, S5S8SMStore::mpacket_sm_1_i_7_r_1_t_9_cnt, S5S8SMStore::mpacket_sm_1_i_7_r_1_t_9, msgObj);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_7_r_1_t_0_busy, S5S8SMStore::mpacket_sm_2_i_7_r_1_t_0_cnt, S5S8SMStore::mpacket_sm_2_i_7_r_1_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_7_r_1_t_1_busy, S5S8SMStore::mpacket_sm_2_i_7_r_1_t_1_cnt, S5S8SMStore::mpacket_sm_2_i_7_r_1_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_7_r_1_t_2_busy, S5S8SMStore::mpacket_sm_2_i_7_r_1_t_2_cnt, S5S8SMStore::mpacket_sm_2_i_7_r_1_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_7_r_1_t_3_busy, S5S8SMStore::mpacket_sm_2_i_7_r_1_t_3_cnt, S5S8SMStore::mpacket_sm_2_i_7_r_1_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_7_r_1_t_4_busy, S5S8SMStore::mpacket_sm_2_i_7_r_1_t_4_cnt, S5S8SMStore::mpacket_sm_2_i_7_r_1_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_7_r_1_t_5_busy, S5S8SMStore::mpacket_sm_2_i_7_r_1_t_5_cnt, S5S8SMStore::mpacket_sm_2_i_7_r_1_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_7_r_1_t_6_busy, S5S8SMStore::mpacket_sm_2_i_7_r_1_t_6_cnt, S5S8SMStore::mpacket_sm_2_i_7_r_1_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_7_r_1_t_7_busy, S5S8SMStore::mpacket_sm_2_i_7_r_1_t_7_cnt, S5S8SMStore::mpacket_sm_2_i_7_r_1_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_7_r_1_t_8_busy, S5S8SMStore::mpacket_sm_2_i_7_r_1_t_8_cnt, S5S8SMStore::mpacket_sm_2_i_7_r_1_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_7_r_1_t_9_busy, S5S8SMStore::mpacket_sm_2_i_7_r_1_t_9_cnt, S5S8SMStore::mpacket_sm_2_i_7_r_1_t_9, msgObj);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_7_r_1_t_0_busy, S5S8SMStore::mpacket_sm_3_i_7_r_1_t_0_cnt, S5S8SMStore::mpacket_sm_3_i_7_r_1_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_7_r_1_t_1_busy, S5S8SMStore::mpacket_sm_3_i_7_r_1_t_1_cnt, S5S8SMStore::mpacket_sm_3_i_7_r_1_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_7_r_1_t_2_busy, S5S8SMStore::mpacket_sm_3_i_7_r_1_t_2_cnt, S5S8SMStore::mpacket_sm_3_i_7_r_1_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_7_r_1_t_3_busy, S5S8SMStore::mpacket_sm_3_i_7_r_1_t_3_cnt, S5S8SMStore::mpacket_sm_3_i_7_r_1_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_7_r_1_t_4_busy, S5S8SMStore::mpacket_sm_3_i_7_r_1_t_4_cnt, S5S8SMStore::mpacket_sm_3_i_7_r_1_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_7_r_1_t_5_busy, S5S8SMStore::mpacket_sm_3_i_7_r_1_t_5_cnt, S5S8SMStore::mpacket_sm_3_i_7_r_1_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_7_r_1_t_6_busy, S5S8SMStore::mpacket_sm_3_i_7_r_1_t_6_cnt, S5S8SMStore::mpacket_sm_3_i_7_r_1_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_7_r_1_t_7_busy, S5S8SMStore::mpacket_sm_3_i_7_r_1_t_7_cnt, S5S8SMStore::mpacket_sm_3_i_7_r_1_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_7_r_1_t_8_busy, S5S8SMStore::mpacket_sm_3_i_7_r_1_t_8_cnt, S5S8SMStore::mpacket_sm_3_i_7_r_1_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_7_r_1_t_9_busy, S5S8SMStore::mpacket_sm_3_i_7_r_1_t_9_cnt, S5S8SMStore::mpacket_sm_3_i_7_r_1_t_9, msgObj);
				break;
			}
			break;
	}
}

VOID S5S8MessageBroker::pushToQueue_i_7_r_2(MPacket *msgObj, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_7_r_2_t_0_busy, S5S8SMStore::mpacket_sm_0_i_7_r_2_t_0_cnt, S5S8SMStore::mpacket_sm_0_i_7_r_2_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_7_r_2_t_1_busy, S5S8SMStore::mpacket_sm_0_i_7_r_2_t_1_cnt, S5S8SMStore::mpacket_sm_0_i_7_r_2_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_7_r_2_t_2_busy, S5S8SMStore::mpacket_sm_0_i_7_r_2_t_2_cnt, S5S8SMStore::mpacket_sm_0_i_7_r_2_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_7_r_2_t_3_busy, S5S8SMStore::mpacket_sm_0_i_7_r_2_t_3_cnt, S5S8SMStore::mpacket_sm_0_i_7_r_2_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_7_r_2_t_4_busy, S5S8SMStore::mpacket_sm_0_i_7_r_2_t_4_cnt, S5S8SMStore::mpacket_sm_0_i_7_r_2_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_7_r_2_t_5_busy, S5S8SMStore::mpacket_sm_0_i_7_r_2_t_5_cnt, S5S8SMStore::mpacket_sm_0_i_7_r_2_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_7_r_2_t_6_busy, S5S8SMStore::mpacket_sm_0_i_7_r_2_t_6_cnt, S5S8SMStore::mpacket_sm_0_i_7_r_2_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_7_r_2_t_7_busy, S5S8SMStore::mpacket_sm_0_i_7_r_2_t_7_cnt, S5S8SMStore::mpacket_sm_0_i_7_r_2_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_7_r_2_t_8_busy, S5S8SMStore::mpacket_sm_0_i_7_r_2_t_8_cnt, S5S8SMStore::mpacket_sm_0_i_7_r_2_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_7_r_2_t_9_busy, S5S8SMStore::mpacket_sm_0_i_7_r_2_t_9_cnt, S5S8SMStore::mpacket_sm_0_i_7_r_2_t_9, msgObj);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_7_r_2_t_0_busy, S5S8SMStore::mpacket_sm_1_i_7_r_2_t_0_cnt, S5S8SMStore::mpacket_sm_1_i_7_r_2_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_7_r_2_t_1_busy, S5S8SMStore::mpacket_sm_1_i_7_r_2_t_1_cnt, S5S8SMStore::mpacket_sm_1_i_7_r_2_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_7_r_2_t_2_busy, S5S8SMStore::mpacket_sm_1_i_7_r_2_t_2_cnt, S5S8SMStore::mpacket_sm_1_i_7_r_2_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_7_r_2_t_3_busy, S5S8SMStore::mpacket_sm_1_i_7_r_2_t_3_cnt, S5S8SMStore::mpacket_sm_1_i_7_r_2_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_7_r_2_t_4_busy, S5S8SMStore::mpacket_sm_1_i_7_r_2_t_4_cnt, S5S8SMStore::mpacket_sm_1_i_7_r_2_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_7_r_2_t_5_busy, S5S8SMStore::mpacket_sm_1_i_7_r_2_t_5_cnt, S5S8SMStore::mpacket_sm_1_i_7_r_2_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_7_r_2_t_6_busy, S5S8SMStore::mpacket_sm_1_i_7_r_2_t_6_cnt, S5S8SMStore::mpacket_sm_1_i_7_r_2_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_7_r_2_t_7_busy, S5S8SMStore::mpacket_sm_1_i_7_r_2_t_7_cnt, S5S8SMStore::mpacket_sm_1_i_7_r_2_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_7_r_2_t_8_busy, S5S8SMStore::mpacket_sm_1_i_7_r_2_t_8_cnt, S5S8SMStore::mpacket_sm_1_i_7_r_2_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_7_r_2_t_9_busy, S5S8SMStore::mpacket_sm_1_i_7_r_2_t_9_cnt, S5S8SMStore::mpacket_sm_1_i_7_r_2_t_9, msgObj);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_7_r_2_t_0_busy, S5S8SMStore::mpacket_sm_2_i_7_r_2_t_0_cnt, S5S8SMStore::mpacket_sm_2_i_7_r_2_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_7_r_2_t_1_busy, S5S8SMStore::mpacket_sm_2_i_7_r_2_t_1_cnt, S5S8SMStore::mpacket_sm_2_i_7_r_2_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_7_r_2_t_2_busy, S5S8SMStore::mpacket_sm_2_i_7_r_2_t_2_cnt, S5S8SMStore::mpacket_sm_2_i_7_r_2_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_7_r_2_t_3_busy, S5S8SMStore::mpacket_sm_2_i_7_r_2_t_3_cnt, S5S8SMStore::mpacket_sm_2_i_7_r_2_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_7_r_2_t_4_busy, S5S8SMStore::mpacket_sm_2_i_7_r_2_t_4_cnt, S5S8SMStore::mpacket_sm_2_i_7_r_2_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_7_r_2_t_5_busy, S5S8SMStore::mpacket_sm_2_i_7_r_2_t_5_cnt, S5S8SMStore::mpacket_sm_2_i_7_r_2_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_7_r_2_t_6_busy, S5S8SMStore::mpacket_sm_2_i_7_r_2_t_6_cnt, S5S8SMStore::mpacket_sm_2_i_7_r_2_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_7_r_2_t_7_busy, S5S8SMStore::mpacket_sm_2_i_7_r_2_t_7_cnt, S5S8SMStore::mpacket_sm_2_i_7_r_2_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_7_r_2_t_8_busy, S5S8SMStore::mpacket_sm_2_i_7_r_2_t_8_cnt, S5S8SMStore::mpacket_sm_2_i_7_r_2_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_7_r_2_t_9_busy, S5S8SMStore::mpacket_sm_2_i_7_r_2_t_9_cnt, S5S8SMStore::mpacket_sm_2_i_7_r_2_t_9, msgObj);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_7_r_2_t_0_busy, S5S8SMStore::mpacket_sm_3_i_7_r_2_t_0_cnt, S5S8SMStore::mpacket_sm_3_i_7_r_2_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_7_r_2_t_1_busy, S5S8SMStore::mpacket_sm_3_i_7_r_2_t_1_cnt, S5S8SMStore::mpacket_sm_3_i_7_r_2_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_7_r_2_t_2_busy, S5S8SMStore::mpacket_sm_3_i_7_r_2_t_2_cnt, S5S8SMStore::mpacket_sm_3_i_7_r_2_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_7_r_2_t_3_busy, S5S8SMStore::mpacket_sm_3_i_7_r_2_t_3_cnt, S5S8SMStore::mpacket_sm_3_i_7_r_2_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_7_r_2_t_4_busy, S5S8SMStore::mpacket_sm_3_i_7_r_2_t_4_cnt, S5S8SMStore::mpacket_sm_3_i_7_r_2_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_7_r_2_t_5_busy, S5S8SMStore::mpacket_sm_3_i_7_r_2_t_5_cnt, S5S8SMStore::mpacket_sm_3_i_7_r_2_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_7_r_2_t_6_busy, S5S8SMStore::mpacket_sm_3_i_7_r_2_t_6_cnt, S5S8SMStore::mpacket_sm_3_i_7_r_2_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_7_r_2_t_7_busy, S5S8SMStore::mpacket_sm_3_i_7_r_2_t_7_cnt, S5S8SMStore::mpacket_sm_3_i_7_r_2_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_7_r_2_t_8_busy, S5S8SMStore::mpacket_sm_3_i_7_r_2_t_8_cnt, S5S8SMStore::mpacket_sm_3_i_7_r_2_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_7_r_2_t_9_busy, S5S8SMStore::mpacket_sm_3_i_7_r_2_t_9_cnt, S5S8SMStore::mpacket_sm_3_i_7_r_2_t_9, msgObj);
				break;
			}
			break;
	}
}

VOID S5S8MessageBroker::pushToQueue_i_7_r_3(MPacket *msgObj, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_7_r_3_t_0_busy, S5S8SMStore::mpacket_sm_0_i_7_r_3_t_0_cnt, S5S8SMStore::mpacket_sm_0_i_7_r_3_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_7_r_3_t_1_busy, S5S8SMStore::mpacket_sm_0_i_7_r_3_t_1_cnt, S5S8SMStore::mpacket_sm_0_i_7_r_3_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_7_r_3_t_2_busy, S5S8SMStore::mpacket_sm_0_i_7_r_3_t_2_cnt, S5S8SMStore::mpacket_sm_0_i_7_r_3_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_7_r_3_t_3_busy, S5S8SMStore::mpacket_sm_0_i_7_r_3_t_3_cnt, S5S8SMStore::mpacket_sm_0_i_7_r_3_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_7_r_3_t_4_busy, S5S8SMStore::mpacket_sm_0_i_7_r_3_t_4_cnt, S5S8SMStore::mpacket_sm_0_i_7_r_3_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_7_r_3_t_5_busy, S5S8SMStore::mpacket_sm_0_i_7_r_3_t_5_cnt, S5S8SMStore::mpacket_sm_0_i_7_r_3_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_7_r_3_t_6_busy, S5S8SMStore::mpacket_sm_0_i_7_r_3_t_6_cnt, S5S8SMStore::mpacket_sm_0_i_7_r_3_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_7_r_3_t_7_busy, S5S8SMStore::mpacket_sm_0_i_7_r_3_t_7_cnt, S5S8SMStore::mpacket_sm_0_i_7_r_3_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_7_r_3_t_8_busy, S5S8SMStore::mpacket_sm_0_i_7_r_3_t_8_cnt, S5S8SMStore::mpacket_sm_0_i_7_r_3_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_7_r_3_t_9_busy, S5S8SMStore::mpacket_sm_0_i_7_r_3_t_9_cnt, S5S8SMStore::mpacket_sm_0_i_7_r_3_t_9, msgObj);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_7_r_3_t_0_busy, S5S8SMStore::mpacket_sm_1_i_7_r_3_t_0_cnt, S5S8SMStore::mpacket_sm_1_i_7_r_3_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_7_r_3_t_1_busy, S5S8SMStore::mpacket_sm_1_i_7_r_3_t_1_cnt, S5S8SMStore::mpacket_sm_1_i_7_r_3_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_7_r_3_t_2_busy, S5S8SMStore::mpacket_sm_1_i_7_r_3_t_2_cnt, S5S8SMStore::mpacket_sm_1_i_7_r_3_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_7_r_3_t_3_busy, S5S8SMStore::mpacket_sm_1_i_7_r_3_t_3_cnt, S5S8SMStore::mpacket_sm_1_i_7_r_3_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_7_r_3_t_4_busy, S5S8SMStore::mpacket_sm_1_i_7_r_3_t_4_cnt, S5S8SMStore::mpacket_sm_1_i_7_r_3_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_7_r_3_t_5_busy, S5S8SMStore::mpacket_sm_1_i_7_r_3_t_5_cnt, S5S8SMStore::mpacket_sm_1_i_7_r_3_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_7_r_3_t_6_busy, S5S8SMStore::mpacket_sm_1_i_7_r_3_t_6_cnt, S5S8SMStore::mpacket_sm_1_i_7_r_3_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_7_r_3_t_7_busy, S5S8SMStore::mpacket_sm_1_i_7_r_3_t_7_cnt, S5S8SMStore::mpacket_sm_1_i_7_r_3_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_7_r_3_t_8_busy, S5S8SMStore::mpacket_sm_1_i_7_r_3_t_8_cnt, S5S8SMStore::mpacket_sm_1_i_7_r_3_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_7_r_3_t_9_busy, S5S8SMStore::mpacket_sm_1_i_7_r_3_t_9_cnt, S5S8SMStore::mpacket_sm_1_i_7_r_3_t_9, msgObj);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_7_r_3_t_0_busy, S5S8SMStore::mpacket_sm_2_i_7_r_3_t_0_cnt, S5S8SMStore::mpacket_sm_2_i_7_r_3_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_7_r_3_t_1_busy, S5S8SMStore::mpacket_sm_2_i_7_r_3_t_1_cnt, S5S8SMStore::mpacket_sm_2_i_7_r_3_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_7_r_3_t_2_busy, S5S8SMStore::mpacket_sm_2_i_7_r_3_t_2_cnt, S5S8SMStore::mpacket_sm_2_i_7_r_3_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_7_r_3_t_3_busy, S5S8SMStore::mpacket_sm_2_i_7_r_3_t_3_cnt, S5S8SMStore::mpacket_sm_2_i_7_r_3_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_7_r_3_t_4_busy, S5S8SMStore::mpacket_sm_2_i_7_r_3_t_4_cnt, S5S8SMStore::mpacket_sm_2_i_7_r_3_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_7_r_3_t_5_busy, S5S8SMStore::mpacket_sm_2_i_7_r_3_t_5_cnt, S5S8SMStore::mpacket_sm_2_i_7_r_3_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_7_r_3_t_6_busy, S5S8SMStore::mpacket_sm_2_i_7_r_3_t_6_cnt, S5S8SMStore::mpacket_sm_2_i_7_r_3_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_7_r_3_t_7_busy, S5S8SMStore::mpacket_sm_2_i_7_r_3_t_7_cnt, S5S8SMStore::mpacket_sm_2_i_7_r_3_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_7_r_3_t_8_busy, S5S8SMStore::mpacket_sm_2_i_7_r_3_t_8_cnt, S5S8SMStore::mpacket_sm_2_i_7_r_3_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_7_r_3_t_9_busy, S5S8SMStore::mpacket_sm_2_i_7_r_3_t_9_cnt, S5S8SMStore::mpacket_sm_2_i_7_r_3_t_9, msgObj);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_7_r_3_t_0_busy, S5S8SMStore::mpacket_sm_3_i_7_r_3_t_0_cnt, S5S8SMStore::mpacket_sm_3_i_7_r_3_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_7_r_3_t_1_busy, S5S8SMStore::mpacket_sm_3_i_7_r_3_t_1_cnt, S5S8SMStore::mpacket_sm_3_i_7_r_3_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_7_r_3_t_2_busy, S5S8SMStore::mpacket_sm_3_i_7_r_3_t_2_cnt, S5S8SMStore::mpacket_sm_3_i_7_r_3_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_7_r_3_t_3_busy, S5S8SMStore::mpacket_sm_3_i_7_r_3_t_3_cnt, S5S8SMStore::mpacket_sm_3_i_7_r_3_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_7_r_3_t_4_busy, S5S8SMStore::mpacket_sm_3_i_7_r_3_t_4_cnt, S5S8SMStore::mpacket_sm_3_i_7_r_3_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_7_r_3_t_5_busy, S5S8SMStore::mpacket_sm_3_i_7_r_3_t_5_cnt, S5S8SMStore::mpacket_sm_3_i_7_r_3_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_7_r_3_t_6_busy, S5S8SMStore::mpacket_sm_3_i_7_r_3_t_6_cnt, S5S8SMStore::mpacket_sm_3_i_7_r_3_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_7_r_3_t_7_busy, S5S8SMStore::mpacket_sm_3_i_7_r_3_t_7_cnt, S5S8SMStore::mpacket_sm_3_i_7_r_3_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_7_r_3_t_8_busy, S5S8SMStore::mpacket_sm_3_i_7_r_3_t_8_cnt, S5S8SMStore::mpacket_sm_3_i_7_r_3_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_7_r_3_t_9_busy, S5S8SMStore::mpacket_sm_3_i_7_r_3_t_9_cnt, S5S8SMStore::mpacket_sm_3_i_7_r_3_t_9, msgObj);
				break;
			}
			break;
	}
}

VOID S5S8MessageBroker::pushToQueue_i_7_r_4(MPacket *msgObj, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_7_r_4_t_0_busy, S5S8SMStore::mpacket_sm_0_i_7_r_4_t_0_cnt, S5S8SMStore::mpacket_sm_0_i_7_r_4_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_7_r_4_t_1_busy, S5S8SMStore::mpacket_sm_0_i_7_r_4_t_1_cnt, S5S8SMStore::mpacket_sm_0_i_7_r_4_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_7_r_4_t_2_busy, S5S8SMStore::mpacket_sm_0_i_7_r_4_t_2_cnt, S5S8SMStore::mpacket_sm_0_i_7_r_4_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_7_r_4_t_3_busy, S5S8SMStore::mpacket_sm_0_i_7_r_4_t_3_cnt, S5S8SMStore::mpacket_sm_0_i_7_r_4_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_7_r_4_t_4_busy, S5S8SMStore::mpacket_sm_0_i_7_r_4_t_4_cnt, S5S8SMStore::mpacket_sm_0_i_7_r_4_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_7_r_4_t_5_busy, S5S8SMStore::mpacket_sm_0_i_7_r_4_t_5_cnt, S5S8SMStore::mpacket_sm_0_i_7_r_4_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_7_r_4_t_6_busy, S5S8SMStore::mpacket_sm_0_i_7_r_4_t_6_cnt, S5S8SMStore::mpacket_sm_0_i_7_r_4_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_7_r_4_t_7_busy, S5S8SMStore::mpacket_sm_0_i_7_r_4_t_7_cnt, S5S8SMStore::mpacket_sm_0_i_7_r_4_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_7_r_4_t_8_busy, S5S8SMStore::mpacket_sm_0_i_7_r_4_t_8_cnt, S5S8SMStore::mpacket_sm_0_i_7_r_4_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_7_r_4_t_9_busy, S5S8SMStore::mpacket_sm_0_i_7_r_4_t_9_cnt, S5S8SMStore::mpacket_sm_0_i_7_r_4_t_9, msgObj);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_7_r_4_t_0_busy, S5S8SMStore::mpacket_sm_1_i_7_r_4_t_0_cnt, S5S8SMStore::mpacket_sm_1_i_7_r_4_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_7_r_4_t_1_busy, S5S8SMStore::mpacket_sm_1_i_7_r_4_t_1_cnt, S5S8SMStore::mpacket_sm_1_i_7_r_4_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_7_r_4_t_2_busy, S5S8SMStore::mpacket_sm_1_i_7_r_4_t_2_cnt, S5S8SMStore::mpacket_sm_1_i_7_r_4_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_7_r_4_t_3_busy, S5S8SMStore::mpacket_sm_1_i_7_r_4_t_3_cnt, S5S8SMStore::mpacket_sm_1_i_7_r_4_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_7_r_4_t_4_busy, S5S8SMStore::mpacket_sm_1_i_7_r_4_t_4_cnt, S5S8SMStore::mpacket_sm_1_i_7_r_4_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_7_r_4_t_5_busy, S5S8SMStore::mpacket_sm_1_i_7_r_4_t_5_cnt, S5S8SMStore::mpacket_sm_1_i_7_r_4_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_7_r_4_t_6_busy, S5S8SMStore::mpacket_sm_1_i_7_r_4_t_6_cnt, S5S8SMStore::mpacket_sm_1_i_7_r_4_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_7_r_4_t_7_busy, S5S8SMStore::mpacket_sm_1_i_7_r_4_t_7_cnt, S5S8SMStore::mpacket_sm_1_i_7_r_4_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_7_r_4_t_8_busy, S5S8SMStore::mpacket_sm_1_i_7_r_4_t_8_cnt, S5S8SMStore::mpacket_sm_1_i_7_r_4_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_7_r_4_t_9_busy, S5S8SMStore::mpacket_sm_1_i_7_r_4_t_9_cnt, S5S8SMStore::mpacket_sm_1_i_7_r_4_t_9, msgObj);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_7_r_4_t_0_busy, S5S8SMStore::mpacket_sm_2_i_7_r_4_t_0_cnt, S5S8SMStore::mpacket_sm_2_i_7_r_4_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_7_r_4_t_1_busy, S5S8SMStore::mpacket_sm_2_i_7_r_4_t_1_cnt, S5S8SMStore::mpacket_sm_2_i_7_r_4_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_7_r_4_t_2_busy, S5S8SMStore::mpacket_sm_2_i_7_r_4_t_2_cnt, S5S8SMStore::mpacket_sm_2_i_7_r_4_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_7_r_4_t_3_busy, S5S8SMStore::mpacket_sm_2_i_7_r_4_t_3_cnt, S5S8SMStore::mpacket_sm_2_i_7_r_4_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_7_r_4_t_4_busy, S5S8SMStore::mpacket_sm_2_i_7_r_4_t_4_cnt, S5S8SMStore::mpacket_sm_2_i_7_r_4_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_7_r_4_t_5_busy, S5S8SMStore::mpacket_sm_2_i_7_r_4_t_5_cnt, S5S8SMStore::mpacket_sm_2_i_7_r_4_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_7_r_4_t_6_busy, S5S8SMStore::mpacket_sm_2_i_7_r_4_t_6_cnt, S5S8SMStore::mpacket_sm_2_i_7_r_4_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_7_r_4_t_7_busy, S5S8SMStore::mpacket_sm_2_i_7_r_4_t_7_cnt, S5S8SMStore::mpacket_sm_2_i_7_r_4_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_7_r_4_t_8_busy, S5S8SMStore::mpacket_sm_2_i_7_r_4_t_8_cnt, S5S8SMStore::mpacket_sm_2_i_7_r_4_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_7_r_4_t_9_busy, S5S8SMStore::mpacket_sm_2_i_7_r_4_t_9_cnt, S5S8SMStore::mpacket_sm_2_i_7_r_4_t_9, msgObj);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_7_r_4_t_0_busy, S5S8SMStore::mpacket_sm_3_i_7_r_4_t_0_cnt, S5S8SMStore::mpacket_sm_3_i_7_r_4_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_7_r_4_t_1_busy, S5S8SMStore::mpacket_sm_3_i_7_r_4_t_1_cnt, S5S8SMStore::mpacket_sm_3_i_7_r_4_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_7_r_4_t_2_busy, S5S8SMStore::mpacket_sm_3_i_7_r_4_t_2_cnt, S5S8SMStore::mpacket_sm_3_i_7_r_4_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_7_r_4_t_3_busy, S5S8SMStore::mpacket_sm_3_i_7_r_4_t_3_cnt, S5S8SMStore::mpacket_sm_3_i_7_r_4_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_7_r_4_t_4_busy, S5S8SMStore::mpacket_sm_3_i_7_r_4_t_4_cnt, S5S8SMStore::mpacket_sm_3_i_7_r_4_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_7_r_4_t_5_busy, S5S8SMStore::mpacket_sm_3_i_7_r_4_t_5_cnt, S5S8SMStore::mpacket_sm_3_i_7_r_4_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_7_r_4_t_6_busy, S5S8SMStore::mpacket_sm_3_i_7_r_4_t_6_cnt, S5S8SMStore::mpacket_sm_3_i_7_r_4_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_7_r_4_t_7_busy, S5S8SMStore::mpacket_sm_3_i_7_r_4_t_7_cnt, S5S8SMStore::mpacket_sm_3_i_7_r_4_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_7_r_4_t_8_busy, S5S8SMStore::mpacket_sm_3_i_7_r_4_t_8_cnt, S5S8SMStore::mpacket_sm_3_i_7_r_4_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_7_r_4_t_9_busy, S5S8SMStore::mpacket_sm_3_i_7_r_4_t_9_cnt, S5S8SMStore::mpacket_sm_3_i_7_r_4_t_9, msgObj);
				break;
			}
			break;
	}
}

VOID S5S8MessageBroker::pushToQueue_i_7_r_5(MPacket *msgObj, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_7_r_5_t_0_busy, S5S8SMStore::mpacket_sm_0_i_7_r_5_t_0_cnt, S5S8SMStore::mpacket_sm_0_i_7_r_5_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_7_r_5_t_1_busy, S5S8SMStore::mpacket_sm_0_i_7_r_5_t_1_cnt, S5S8SMStore::mpacket_sm_0_i_7_r_5_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_7_r_5_t_2_busy, S5S8SMStore::mpacket_sm_0_i_7_r_5_t_2_cnt, S5S8SMStore::mpacket_sm_0_i_7_r_5_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_7_r_5_t_3_busy, S5S8SMStore::mpacket_sm_0_i_7_r_5_t_3_cnt, S5S8SMStore::mpacket_sm_0_i_7_r_5_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_7_r_5_t_4_busy, S5S8SMStore::mpacket_sm_0_i_7_r_5_t_4_cnt, S5S8SMStore::mpacket_sm_0_i_7_r_5_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_7_r_5_t_5_busy, S5S8SMStore::mpacket_sm_0_i_7_r_5_t_5_cnt, S5S8SMStore::mpacket_sm_0_i_7_r_5_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_7_r_5_t_6_busy, S5S8SMStore::mpacket_sm_0_i_7_r_5_t_6_cnt, S5S8SMStore::mpacket_sm_0_i_7_r_5_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_7_r_5_t_7_busy, S5S8SMStore::mpacket_sm_0_i_7_r_5_t_7_cnt, S5S8SMStore::mpacket_sm_0_i_7_r_5_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_7_r_5_t_8_busy, S5S8SMStore::mpacket_sm_0_i_7_r_5_t_8_cnt, S5S8SMStore::mpacket_sm_0_i_7_r_5_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_7_r_5_t_9_busy, S5S8SMStore::mpacket_sm_0_i_7_r_5_t_9_cnt, S5S8SMStore::mpacket_sm_0_i_7_r_5_t_9, msgObj);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_7_r_5_t_0_busy, S5S8SMStore::mpacket_sm_1_i_7_r_5_t_0_cnt, S5S8SMStore::mpacket_sm_1_i_7_r_5_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_7_r_5_t_1_busy, S5S8SMStore::mpacket_sm_1_i_7_r_5_t_1_cnt, S5S8SMStore::mpacket_sm_1_i_7_r_5_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_7_r_5_t_2_busy, S5S8SMStore::mpacket_sm_1_i_7_r_5_t_2_cnt, S5S8SMStore::mpacket_sm_1_i_7_r_5_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_7_r_5_t_3_busy, S5S8SMStore::mpacket_sm_1_i_7_r_5_t_3_cnt, S5S8SMStore::mpacket_sm_1_i_7_r_5_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_7_r_5_t_4_busy, S5S8SMStore::mpacket_sm_1_i_7_r_5_t_4_cnt, S5S8SMStore::mpacket_sm_1_i_7_r_5_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_7_r_5_t_5_busy, S5S8SMStore::mpacket_sm_1_i_7_r_5_t_5_cnt, S5S8SMStore::mpacket_sm_1_i_7_r_5_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_7_r_5_t_6_busy, S5S8SMStore::mpacket_sm_1_i_7_r_5_t_6_cnt, S5S8SMStore::mpacket_sm_1_i_7_r_5_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_7_r_5_t_7_busy, S5S8SMStore::mpacket_sm_1_i_7_r_5_t_7_cnt, S5S8SMStore::mpacket_sm_1_i_7_r_5_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_7_r_5_t_8_busy, S5S8SMStore::mpacket_sm_1_i_7_r_5_t_8_cnt, S5S8SMStore::mpacket_sm_1_i_7_r_5_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_7_r_5_t_9_busy, S5S8SMStore::mpacket_sm_1_i_7_r_5_t_9_cnt, S5S8SMStore::mpacket_sm_1_i_7_r_5_t_9, msgObj);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_7_r_5_t_0_busy, S5S8SMStore::mpacket_sm_2_i_7_r_5_t_0_cnt, S5S8SMStore::mpacket_sm_2_i_7_r_5_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_7_r_5_t_1_busy, S5S8SMStore::mpacket_sm_2_i_7_r_5_t_1_cnt, S5S8SMStore::mpacket_sm_2_i_7_r_5_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_7_r_5_t_2_busy, S5S8SMStore::mpacket_sm_2_i_7_r_5_t_2_cnt, S5S8SMStore::mpacket_sm_2_i_7_r_5_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_7_r_5_t_3_busy, S5S8SMStore::mpacket_sm_2_i_7_r_5_t_3_cnt, S5S8SMStore::mpacket_sm_2_i_7_r_5_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_7_r_5_t_4_busy, S5S8SMStore::mpacket_sm_2_i_7_r_5_t_4_cnt, S5S8SMStore::mpacket_sm_2_i_7_r_5_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_7_r_5_t_5_busy, S5S8SMStore::mpacket_sm_2_i_7_r_5_t_5_cnt, S5S8SMStore::mpacket_sm_2_i_7_r_5_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_7_r_5_t_6_busy, S5S8SMStore::mpacket_sm_2_i_7_r_5_t_6_cnt, S5S8SMStore::mpacket_sm_2_i_7_r_5_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_7_r_5_t_7_busy, S5S8SMStore::mpacket_sm_2_i_7_r_5_t_7_cnt, S5S8SMStore::mpacket_sm_2_i_7_r_5_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_7_r_5_t_8_busy, S5S8SMStore::mpacket_sm_2_i_7_r_5_t_8_cnt, S5S8SMStore::mpacket_sm_2_i_7_r_5_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_7_r_5_t_9_busy, S5S8SMStore::mpacket_sm_2_i_7_r_5_t_9_cnt, S5S8SMStore::mpacket_sm_2_i_7_r_5_t_9, msgObj);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_7_r_5_t_0_busy, S5S8SMStore::mpacket_sm_3_i_7_r_5_t_0_cnt, S5S8SMStore::mpacket_sm_3_i_7_r_5_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_7_r_5_t_1_busy, S5S8SMStore::mpacket_sm_3_i_7_r_5_t_1_cnt, S5S8SMStore::mpacket_sm_3_i_7_r_5_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_7_r_5_t_2_busy, S5S8SMStore::mpacket_sm_3_i_7_r_5_t_2_cnt, S5S8SMStore::mpacket_sm_3_i_7_r_5_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_7_r_5_t_3_busy, S5S8SMStore::mpacket_sm_3_i_7_r_5_t_3_cnt, S5S8SMStore::mpacket_sm_3_i_7_r_5_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_7_r_5_t_4_busy, S5S8SMStore::mpacket_sm_3_i_7_r_5_t_4_cnt, S5S8SMStore::mpacket_sm_3_i_7_r_5_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_7_r_5_t_5_busy, S5S8SMStore::mpacket_sm_3_i_7_r_5_t_5_cnt, S5S8SMStore::mpacket_sm_3_i_7_r_5_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_7_r_5_t_6_busy, S5S8SMStore::mpacket_sm_3_i_7_r_5_t_6_cnt, S5S8SMStore::mpacket_sm_3_i_7_r_5_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_7_r_5_t_7_busy, S5S8SMStore::mpacket_sm_3_i_7_r_5_t_7_cnt, S5S8SMStore::mpacket_sm_3_i_7_r_5_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_7_r_5_t_8_busy, S5S8SMStore::mpacket_sm_3_i_7_r_5_t_8_cnt, S5S8SMStore::mpacket_sm_3_i_7_r_5_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_7_r_5_t_9_busy, S5S8SMStore::mpacket_sm_3_i_7_r_5_t_9_cnt, S5S8SMStore::mpacket_sm_3_i_7_r_5_t_9, msgObj);
				break;
			}
			break;
	}
}

VOID S5S8MessageBroker::pushToQueue_i_7_r_6(MPacket *msgObj, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_7_r_6_t_0_busy, S5S8SMStore::mpacket_sm_0_i_7_r_6_t_0_cnt, S5S8SMStore::mpacket_sm_0_i_7_r_6_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_7_r_6_t_1_busy, S5S8SMStore::mpacket_sm_0_i_7_r_6_t_1_cnt, S5S8SMStore::mpacket_sm_0_i_7_r_6_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_7_r_6_t_2_busy, S5S8SMStore::mpacket_sm_0_i_7_r_6_t_2_cnt, S5S8SMStore::mpacket_sm_0_i_7_r_6_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_7_r_6_t_3_busy, S5S8SMStore::mpacket_sm_0_i_7_r_6_t_3_cnt, S5S8SMStore::mpacket_sm_0_i_7_r_6_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_7_r_6_t_4_busy, S5S8SMStore::mpacket_sm_0_i_7_r_6_t_4_cnt, S5S8SMStore::mpacket_sm_0_i_7_r_6_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_7_r_6_t_5_busy, S5S8SMStore::mpacket_sm_0_i_7_r_6_t_5_cnt, S5S8SMStore::mpacket_sm_0_i_7_r_6_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_7_r_6_t_6_busy, S5S8SMStore::mpacket_sm_0_i_7_r_6_t_6_cnt, S5S8SMStore::mpacket_sm_0_i_7_r_6_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_7_r_6_t_7_busy, S5S8SMStore::mpacket_sm_0_i_7_r_6_t_7_cnt, S5S8SMStore::mpacket_sm_0_i_7_r_6_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_7_r_6_t_8_busy, S5S8SMStore::mpacket_sm_0_i_7_r_6_t_8_cnt, S5S8SMStore::mpacket_sm_0_i_7_r_6_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_7_r_6_t_9_busy, S5S8SMStore::mpacket_sm_0_i_7_r_6_t_9_cnt, S5S8SMStore::mpacket_sm_0_i_7_r_6_t_9, msgObj);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_7_r_6_t_0_busy, S5S8SMStore::mpacket_sm_1_i_7_r_6_t_0_cnt, S5S8SMStore::mpacket_sm_1_i_7_r_6_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_7_r_6_t_1_busy, S5S8SMStore::mpacket_sm_1_i_7_r_6_t_1_cnt, S5S8SMStore::mpacket_sm_1_i_7_r_6_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_7_r_6_t_2_busy, S5S8SMStore::mpacket_sm_1_i_7_r_6_t_2_cnt, S5S8SMStore::mpacket_sm_1_i_7_r_6_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_7_r_6_t_3_busy, S5S8SMStore::mpacket_sm_1_i_7_r_6_t_3_cnt, S5S8SMStore::mpacket_sm_1_i_7_r_6_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_7_r_6_t_4_busy, S5S8SMStore::mpacket_sm_1_i_7_r_6_t_4_cnt, S5S8SMStore::mpacket_sm_1_i_7_r_6_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_7_r_6_t_5_busy, S5S8SMStore::mpacket_sm_1_i_7_r_6_t_5_cnt, S5S8SMStore::mpacket_sm_1_i_7_r_6_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_7_r_6_t_6_busy, S5S8SMStore::mpacket_sm_1_i_7_r_6_t_6_cnt, S5S8SMStore::mpacket_sm_1_i_7_r_6_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_7_r_6_t_7_busy, S5S8SMStore::mpacket_sm_1_i_7_r_6_t_7_cnt, S5S8SMStore::mpacket_sm_1_i_7_r_6_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_7_r_6_t_8_busy, S5S8SMStore::mpacket_sm_1_i_7_r_6_t_8_cnt, S5S8SMStore::mpacket_sm_1_i_7_r_6_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_7_r_6_t_9_busy, S5S8SMStore::mpacket_sm_1_i_7_r_6_t_9_cnt, S5S8SMStore::mpacket_sm_1_i_7_r_6_t_9, msgObj);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_7_r_6_t_0_busy, S5S8SMStore::mpacket_sm_2_i_7_r_6_t_0_cnt, S5S8SMStore::mpacket_sm_2_i_7_r_6_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_7_r_6_t_1_busy, S5S8SMStore::mpacket_sm_2_i_7_r_6_t_1_cnt, S5S8SMStore::mpacket_sm_2_i_7_r_6_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_7_r_6_t_2_busy, S5S8SMStore::mpacket_sm_2_i_7_r_6_t_2_cnt, S5S8SMStore::mpacket_sm_2_i_7_r_6_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_7_r_6_t_3_busy, S5S8SMStore::mpacket_sm_2_i_7_r_6_t_3_cnt, S5S8SMStore::mpacket_sm_2_i_7_r_6_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_7_r_6_t_4_busy, S5S8SMStore::mpacket_sm_2_i_7_r_6_t_4_cnt, S5S8SMStore::mpacket_sm_2_i_7_r_6_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_7_r_6_t_5_busy, S5S8SMStore::mpacket_sm_2_i_7_r_6_t_5_cnt, S5S8SMStore::mpacket_sm_2_i_7_r_6_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_7_r_6_t_6_busy, S5S8SMStore::mpacket_sm_2_i_7_r_6_t_6_cnt, S5S8SMStore::mpacket_sm_2_i_7_r_6_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_7_r_6_t_7_busy, S5S8SMStore::mpacket_sm_2_i_7_r_6_t_7_cnt, S5S8SMStore::mpacket_sm_2_i_7_r_6_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_7_r_6_t_8_busy, S5S8SMStore::mpacket_sm_2_i_7_r_6_t_8_cnt, S5S8SMStore::mpacket_sm_2_i_7_r_6_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_7_r_6_t_9_busy, S5S8SMStore::mpacket_sm_2_i_7_r_6_t_9_cnt, S5S8SMStore::mpacket_sm_2_i_7_r_6_t_9, msgObj);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_7_r_6_t_0_busy, S5S8SMStore::mpacket_sm_3_i_7_r_6_t_0_cnt, S5S8SMStore::mpacket_sm_3_i_7_r_6_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_7_r_6_t_1_busy, S5S8SMStore::mpacket_sm_3_i_7_r_6_t_1_cnt, S5S8SMStore::mpacket_sm_3_i_7_r_6_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_7_r_6_t_2_busy, S5S8SMStore::mpacket_sm_3_i_7_r_6_t_2_cnt, S5S8SMStore::mpacket_sm_3_i_7_r_6_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_7_r_6_t_3_busy, S5S8SMStore::mpacket_sm_3_i_7_r_6_t_3_cnt, S5S8SMStore::mpacket_sm_3_i_7_r_6_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_7_r_6_t_4_busy, S5S8SMStore::mpacket_sm_3_i_7_r_6_t_4_cnt, S5S8SMStore::mpacket_sm_3_i_7_r_6_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_7_r_6_t_5_busy, S5S8SMStore::mpacket_sm_3_i_7_r_6_t_5_cnt, S5S8SMStore::mpacket_sm_3_i_7_r_6_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_7_r_6_t_6_busy, S5S8SMStore::mpacket_sm_3_i_7_r_6_t_6_cnt, S5S8SMStore::mpacket_sm_3_i_7_r_6_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_7_r_6_t_7_busy, S5S8SMStore::mpacket_sm_3_i_7_r_6_t_7_cnt, S5S8SMStore::mpacket_sm_3_i_7_r_6_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_7_r_6_t_8_busy, S5S8SMStore::mpacket_sm_3_i_7_r_6_t_8_cnt, S5S8SMStore::mpacket_sm_3_i_7_r_6_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_7_r_6_t_9_busy, S5S8SMStore::mpacket_sm_3_i_7_r_6_t_9_cnt, S5S8SMStore::mpacket_sm_3_i_7_r_6_t_9, msgObj);
				break;
			}
			break;
	}
}

VOID S5S8MessageBroker::pushToQueue_i_7_r_7(MPacket *msgObj, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_7_r_7_t_0_busy, S5S8SMStore::mpacket_sm_0_i_7_r_7_t_0_cnt, S5S8SMStore::mpacket_sm_0_i_7_r_7_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_7_r_7_t_1_busy, S5S8SMStore::mpacket_sm_0_i_7_r_7_t_1_cnt, S5S8SMStore::mpacket_sm_0_i_7_r_7_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_7_r_7_t_2_busy, S5S8SMStore::mpacket_sm_0_i_7_r_7_t_2_cnt, S5S8SMStore::mpacket_sm_0_i_7_r_7_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_7_r_7_t_3_busy, S5S8SMStore::mpacket_sm_0_i_7_r_7_t_3_cnt, S5S8SMStore::mpacket_sm_0_i_7_r_7_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_7_r_7_t_4_busy, S5S8SMStore::mpacket_sm_0_i_7_r_7_t_4_cnt, S5S8SMStore::mpacket_sm_0_i_7_r_7_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_7_r_7_t_5_busy, S5S8SMStore::mpacket_sm_0_i_7_r_7_t_5_cnt, S5S8SMStore::mpacket_sm_0_i_7_r_7_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_7_r_7_t_6_busy, S5S8SMStore::mpacket_sm_0_i_7_r_7_t_6_cnt, S5S8SMStore::mpacket_sm_0_i_7_r_7_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_7_r_7_t_7_busy, S5S8SMStore::mpacket_sm_0_i_7_r_7_t_7_cnt, S5S8SMStore::mpacket_sm_0_i_7_r_7_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_7_r_7_t_8_busy, S5S8SMStore::mpacket_sm_0_i_7_r_7_t_8_cnt, S5S8SMStore::mpacket_sm_0_i_7_r_7_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_0_i_7_r_7_t_9_busy, S5S8SMStore::mpacket_sm_0_i_7_r_7_t_9_cnt, S5S8SMStore::mpacket_sm_0_i_7_r_7_t_9, msgObj);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_7_r_7_t_0_busy, S5S8SMStore::mpacket_sm_1_i_7_r_7_t_0_cnt, S5S8SMStore::mpacket_sm_1_i_7_r_7_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_7_r_7_t_1_busy, S5S8SMStore::mpacket_sm_1_i_7_r_7_t_1_cnt, S5S8SMStore::mpacket_sm_1_i_7_r_7_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_7_r_7_t_2_busy, S5S8SMStore::mpacket_sm_1_i_7_r_7_t_2_cnt, S5S8SMStore::mpacket_sm_1_i_7_r_7_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_7_r_7_t_3_busy, S5S8SMStore::mpacket_sm_1_i_7_r_7_t_3_cnt, S5S8SMStore::mpacket_sm_1_i_7_r_7_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_7_r_7_t_4_busy, S5S8SMStore::mpacket_sm_1_i_7_r_7_t_4_cnt, S5S8SMStore::mpacket_sm_1_i_7_r_7_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_7_r_7_t_5_busy, S5S8SMStore::mpacket_sm_1_i_7_r_7_t_5_cnt, S5S8SMStore::mpacket_sm_1_i_7_r_7_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_7_r_7_t_6_busy, S5S8SMStore::mpacket_sm_1_i_7_r_7_t_6_cnt, S5S8SMStore::mpacket_sm_1_i_7_r_7_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_7_r_7_t_7_busy, S5S8SMStore::mpacket_sm_1_i_7_r_7_t_7_cnt, S5S8SMStore::mpacket_sm_1_i_7_r_7_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_7_r_7_t_8_busy, S5S8SMStore::mpacket_sm_1_i_7_r_7_t_8_cnt, S5S8SMStore::mpacket_sm_1_i_7_r_7_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_1_i_7_r_7_t_9_busy, S5S8SMStore::mpacket_sm_1_i_7_r_7_t_9_cnt, S5S8SMStore::mpacket_sm_1_i_7_r_7_t_9, msgObj);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_7_r_7_t_0_busy, S5S8SMStore::mpacket_sm_2_i_7_r_7_t_0_cnt, S5S8SMStore::mpacket_sm_2_i_7_r_7_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_7_r_7_t_1_busy, S5S8SMStore::mpacket_sm_2_i_7_r_7_t_1_cnt, S5S8SMStore::mpacket_sm_2_i_7_r_7_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_7_r_7_t_2_busy, S5S8SMStore::mpacket_sm_2_i_7_r_7_t_2_cnt, S5S8SMStore::mpacket_sm_2_i_7_r_7_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_7_r_7_t_3_busy, S5S8SMStore::mpacket_sm_2_i_7_r_7_t_3_cnt, S5S8SMStore::mpacket_sm_2_i_7_r_7_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_7_r_7_t_4_busy, S5S8SMStore::mpacket_sm_2_i_7_r_7_t_4_cnt, S5S8SMStore::mpacket_sm_2_i_7_r_7_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_7_r_7_t_5_busy, S5S8SMStore::mpacket_sm_2_i_7_r_7_t_5_cnt, S5S8SMStore::mpacket_sm_2_i_7_r_7_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_7_r_7_t_6_busy, S5S8SMStore::mpacket_sm_2_i_7_r_7_t_6_cnt, S5S8SMStore::mpacket_sm_2_i_7_r_7_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_7_r_7_t_7_busy, S5S8SMStore::mpacket_sm_2_i_7_r_7_t_7_cnt, S5S8SMStore::mpacket_sm_2_i_7_r_7_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_7_r_7_t_8_busy, S5S8SMStore::mpacket_sm_2_i_7_r_7_t_8_cnt, S5S8SMStore::mpacket_sm_2_i_7_r_7_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_2_i_7_r_7_t_9_busy, S5S8SMStore::mpacket_sm_2_i_7_r_7_t_9_cnt, S5S8SMStore::mpacket_sm_2_i_7_r_7_t_9, msgObj);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_7_r_7_t_0_busy, S5S8SMStore::mpacket_sm_3_i_7_r_7_t_0_cnt, S5S8SMStore::mpacket_sm_3_i_7_r_7_t_0, msgObj);
				break;
			case 1:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_7_r_7_t_1_busy, S5S8SMStore::mpacket_sm_3_i_7_r_7_t_1_cnt, S5S8SMStore::mpacket_sm_3_i_7_r_7_t_1, msgObj);
				break;
			case 2:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_7_r_7_t_2_busy, S5S8SMStore::mpacket_sm_3_i_7_r_7_t_2_cnt, S5S8SMStore::mpacket_sm_3_i_7_r_7_t_2, msgObj);
				break;
			case 3:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_7_r_7_t_3_busy, S5S8SMStore::mpacket_sm_3_i_7_r_7_t_3_cnt, S5S8SMStore::mpacket_sm_3_i_7_r_7_t_3, msgObj);
				break;
			case 4:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_7_r_7_t_4_busy, S5S8SMStore::mpacket_sm_3_i_7_r_7_t_4_cnt, S5S8SMStore::mpacket_sm_3_i_7_r_7_t_4, msgObj);
				break;
			case 5:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_7_r_7_t_5_busy, S5S8SMStore::mpacket_sm_3_i_7_r_7_t_5_cnt, S5S8SMStore::mpacket_sm_3_i_7_r_7_t_5, msgObj);
				break;
			case 6:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_7_r_7_t_6_busy, S5S8SMStore::mpacket_sm_3_i_7_r_7_t_6_cnt, S5S8SMStore::mpacket_sm_3_i_7_r_7_t_6, msgObj);
				break;
			case 7:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_7_r_7_t_7_busy, S5S8SMStore::mpacket_sm_3_i_7_r_7_t_7_cnt, S5S8SMStore::mpacket_sm_3_i_7_r_7_t_7, msgObj);
				break;
			case 8:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_7_r_7_t_8_busy, S5S8SMStore::mpacket_sm_3_i_7_r_7_t_8_cnt, S5S8SMStore::mpacket_sm_3_i_7_r_7_t_8, msgObj);
				break;
			case 9:
				copyS5S8MsgObj(S5S8SMStore::mpacket_sm_3_i_7_r_7_t_9_busy, S5S8SMStore::mpacket_sm_3_i_7_r_7_t_9_cnt, S5S8SMStore::mpacket_sm_3_i_7_r_7_t_9, msgObj);
				break;
			}
			break;
	}
}


VOID S5S8MessageBroker::copyS5S8MsgObj(bool &ip_msg_sm_busy, int &ip_msg_sm_cnt, std::unordered_map<int, MPacket> &ip_msg_sm, MPacket *s5s8Obj)
{
	if(ip_msg_sm_busy) return;

	ip_msg_sm[ip_msg_sm_cnt].copy(s5s8Obj);
	ip_msg_sm_cnt++;
}
