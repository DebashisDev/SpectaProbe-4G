/*
 * S1APMessageBroker.cpp
 *
 *  Created on: 02-Mar-2020
 *      Author: singh
 */

#include "SctpMessageBroker.h"

SctpMessageBroker::SctpMessageBroker(int intfid, int rId) {
	_thisLogLevel = 0;
	this->_name = "S1APMessageBroker";
	this->setLogLevel(Log::theLog().level());

	this->interfaceId = intfid;
	this->routerId = rId;
}

SctpMessageBroker::~SctpMessageBroker() {
}

VOID SctpMessageBroker::store_S1MME_Packet(MPacket *msgObj)
{
	Sctp *pSctpPacket;
	int smId;

	for(auto elem : msgObj->SctpData)
	{
		smId = -1;
		bool smFlag = false;
		pSctpPacket = NULL;
		pSctpPacket = &elem.second;

		printf("[Broker] Pdu Type :: %d| Procedure Id:: %d\n", pSctpPacket->s1ap_pduType, pSctpPacket->s1ap_procCode);

		pSctpPacket->sourceIp = msgObj->sourceIpAddrLong;
		pSctpPacket->sourcePort = msgObj->sourcePort;
		pSctpPacket->destIp = msgObj->destIpAddrLong;
		pSctpPacket->destPort = msgObj->destPort;

		if(pSctpPacket->s1ap_eNodeBId > 0)
			smId = pSctpPacket->s1ap_eNodeBId % IPGlobal::S1MME_SESSION_MANAGER_INSTANCES;

		/*
		 * In case of Request  (Handover Preparation) we receive eNodeB and MMEId
		 * but in Response (Handover Requst) we only get MMEId
		 */

		switch(pSctpPacket->s1ap_pduType)
		{
			case 1: /* Initiating Message */
				switch(pSctpPacket->s1ap_procCode)
				{
					case 0:	/* Handover Preparation */
					{
						handoverMap[pSctpPacket->s1ap_mmeId].smId = smId;
						handoverMap[pSctpPacket->s1ap_mmeId].eNodeB = pSctpPacket->s1ap_eNodeBId;
					}
					break;

					case 1: /* Handover Request */
					{
						std::map<uint32_t, tmsi>::iterator it = handoverMap.find(pSctpPacket->s1ap_mmeId);

						if(it != handoverMap.end())
						{
							smId = it->second.smId;
							pSctpPacket->s1ap_eNodeBId = it->second.eNodeB;

							handoverMap.erase(pSctpPacket->s1ap_mmeId);
						}
					}
					break;
				}
				break;
		}

		if(smId > -1) SMStoreS1MMEPacket(pSctpPacket, smId);
	}
}

VOID SctpMessageBroker::SMStoreS1MMEPacket(Sctp *pSctp, int smid)
{
	int idx = PKT_WRITE_TIME_INDEX(IPGlobal::CURRENT_EPOCH_SEC, IPGlobal::PKT_TIME_INDEX);

	switch(this->interfaceId)
	{
		case 0:
			SMStore_i_0(pSctp, smid, idx);
			break;
		case 1:
			SMStore_i_1(pSctp, smid, idx);
			break;
		case 2:
			SMStore_i_2(pSctp, smid, idx);
			break;
		case 3:
			SMStore_i_3(pSctp, smid, idx);
			break;
		case 4:
			SMStore_i_4(pSctp, smid, idx);
			break;
		case 5:
			SMStore_i_5(pSctp, smid, idx);
			break;
		case 6:
			SMStore_i_6(pSctp, smid, idx);
			break;
		case 7:
			SMStore_i_7(pSctp, smid, idx);
			break;
	}
}

VOID SctpMessageBroker::SMStore_i_0(Sctp *pSctp, int smid, int idx)
{
	switch(this->routerId)
	{
		case 0:
			pushToQueue_i_0_r_0(pSctp, smid, idx);
			break;
		case 1:
			pushToQueue_i_0_r_1(pSctp, smid, idx);
			break;
		case 2:
			pushToQueue_i_0_r_2(pSctp, smid, idx);
			break;
		case 3:
			pushToQueue_i_0_r_3(pSctp, smid, idx);
			break;
		case 4:
			pushToQueue_i_0_r_4(pSctp, smid, idx);
			break;
		case 5:
			pushToQueue_i_0_r_5(pSctp, smid, idx);
			break;
		case 6:
			pushToQueue_i_0_r_6(pSctp, smid, idx);
			break;
		case 7:
			pushToQueue_i_0_r_7(pSctp, smid, idx);
			break;
	}
}

VOID SctpMessageBroker::SMStore_i_1(Sctp *pSctp, int smid, int idx)
{
	switch(this->routerId)
	{
		case 0:
			pushToQueue_i_1_r_0(pSctp, smid, idx);
			break;
		case 1:
			pushToQueue_i_1_r_1(pSctp, smid, idx);
			break;
		case 2:
			pushToQueue_i_1_r_2(pSctp, smid, idx);
			break;
		case 3:
			pushToQueue_i_1_r_3(pSctp, smid, idx);
			break;
		case 4:
			pushToQueue_i_1_r_4(pSctp, smid, idx);
			break;
		case 5:
			pushToQueue_i_1_r_5(pSctp, smid, idx);
			break;
		case 6:
			pushToQueue_i_1_r_6(pSctp, smid, idx);
			break;
		case 7:
			pushToQueue_i_1_r_7(pSctp, smid, idx);
			break;

	}
}

VOID SctpMessageBroker::SMStore_i_2(Sctp *pSctp, int smid, int idx)
{
	switch(this->routerId)
	{
		case 0:
			pushToQueue_i_2_r_0(pSctp, smid, idx);
			break;
		case 1:
			pushToQueue_i_2_r_1(pSctp, smid, idx);
			break;
		case 2:
			pushToQueue_i_2_r_2(pSctp, smid, idx);
			break;
		case 3:
			pushToQueue_i_2_r_3(pSctp, smid, idx);
			break;
		case 4:
			pushToQueue_i_2_r_4(pSctp, smid, idx);
			break;
		case 5:
			pushToQueue_i_2_r_5(pSctp, smid, idx);
			break;
		case 6:
			pushToQueue_i_2_r_6(pSctp, smid, idx);
			break;
		case 7:
			pushToQueue_i_2_r_7(pSctp, smid, idx);
			break;

	}
}

VOID SctpMessageBroker::SMStore_i_3(Sctp *pSctp, int smid, int idx)
{
	switch(this->routerId)
	{
		case 0:
			pushToQueue_i_3_r_0(pSctp, smid, idx);
			break;
		case 1:
			pushToQueue_i_3_r_1(pSctp, smid, idx);
			break;
		case 2:
			pushToQueue_i_3_r_2(pSctp, smid, idx);
			break;
		case 3:
			pushToQueue_i_3_r_3(pSctp, smid, idx);
			break;
		case 4:
			pushToQueue_i_3_r_4(pSctp, smid, idx);
			break;
		case 5:
			pushToQueue_i_3_r_5(pSctp, smid, idx);
			break;
		case 6:
			pushToQueue_i_3_r_6(pSctp, smid, idx);
			break;
		case 7:
			pushToQueue_i_3_r_7(pSctp, smid, idx);
			break;
	}
}

VOID SctpMessageBroker::SMStore_i_4(Sctp *pSctp, int smid, int idx)
{
	switch(this->routerId)
	{
		case 0:
			pushToQueue_i_4_r_0(pSctp, smid, idx);
			break;
		case 1:
			pushToQueue_i_4_r_1(pSctp, smid, idx);
			break;
		case 2:
			pushToQueue_i_4_r_2(pSctp, smid, idx);
			break;
		case 3:
			pushToQueue_i_4_r_3(pSctp, smid, idx);
			break;
		case 4:
			pushToQueue_i_4_r_4(pSctp, smid, idx);
			break;
		case 5:
			pushToQueue_i_4_r_5(pSctp, smid, idx);
			break;
		case 6:
			pushToQueue_i_4_r_6(pSctp, smid, idx);
			break;
		case 7:
			pushToQueue_i_4_r_7(pSctp, smid, idx);
			break;

	}
}

VOID SctpMessageBroker::SMStore_i_5(Sctp *pSctp, int smid, int idx)
{
	switch(this->routerId)
	{
		case 0:
			pushToQueue_i_5_r_0(pSctp, smid, idx);
			break;
		case 1:
			pushToQueue_i_5_r_1(pSctp, smid, idx);
			break;
		case 2:
			pushToQueue_i_5_r_2(pSctp, smid, idx);
			break;
		case 3:
			pushToQueue_i_5_r_3(pSctp, smid, idx);
			break;
		case 4:
			pushToQueue_i_5_r_4(pSctp, smid, idx);
			break;
		case 5:
			pushToQueue_i_5_r_5(pSctp, smid, idx);
			break;
		case 6:
			pushToQueue_i_5_r_6(pSctp, smid, idx);
			break;
		case 7:
			pushToQueue_i_5_r_7(pSctp, smid, idx);
			break;
	}
}

VOID SctpMessageBroker::SMStore_i_6(Sctp *pSctp, int smid, int idx)
{
	switch(this->routerId)
	{
		case 0:
			pushToQueue_i_6_r_0(pSctp, smid, idx);
			break;
		case 1:
			pushToQueue_i_6_r_1(pSctp, smid, idx);
			break;
		case 2:
			pushToQueue_i_6_r_2(pSctp, smid, idx);
			break;
		case 3:
			pushToQueue_i_6_r_3(pSctp, smid, idx);
			break;
		case 4:
			pushToQueue_i_6_r_4(pSctp, smid, idx);
			break;
		case 5:
			pushToQueue_i_6_r_5(pSctp, smid, idx);
			break;
		case 6:
			pushToQueue_i_6_r_6(pSctp, smid, idx);
			break;
		case 7:
			pushToQueue_i_6_r_7(pSctp, smid, idx);
			break;
	}
}

VOID SctpMessageBroker::SMStore_i_7(Sctp *pSctp, int smid, int idx)
{
	switch(this->routerId)
	{
		case 0:
			pushToQueue_i_7_r_0(pSctp, smid, idx);
			break;
		case 1:
			pushToQueue_i_7_r_1(pSctp, smid, idx);
			break;
		case 2:
			pushToQueue_i_7_r_2(pSctp, smid, idx);
			break;
		case 3:
			pushToQueue_i_7_r_3(pSctp, smid, idx);
			break;
		case 4:
			pushToQueue_i_7_r_4(pSctp, smid, idx);
			break;
		case 5:
			pushToQueue_i_7_r_5(pSctp, smid, idx);
			break;
		case 6:
			pushToQueue_i_7_r_6(pSctp, smid, idx);
			break;
		case 7:
			pushToQueue_i_7_r_7(pSctp, smid, idx);
			break;
	}
}

VOID SctpMessageBroker::pushToQueue_i_0_r_0(Sctp *pSctp, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_0_r_0_t_0_busy, S1MMEtore::msg_sm_0_i_0_r_0_t_0_cnt, S1MMEtore::msg_sm_0_i_0_r_0_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_0_r_0_t_1_busy, S1MMEtore::msg_sm_0_i_0_r_0_t_1_cnt, S1MMEtore::msg_sm_0_i_0_r_0_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_0_r_0_t_2_busy, S1MMEtore::msg_sm_0_i_0_r_0_t_2_cnt, S1MMEtore::msg_sm_0_i_0_r_0_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_0_r_0_t_3_busy, S1MMEtore::msg_sm_0_i_0_r_0_t_3_cnt, S1MMEtore::msg_sm_0_i_0_r_0_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_0_r_0_t_4_busy, S1MMEtore::msg_sm_0_i_0_r_0_t_4_cnt, S1MMEtore::msg_sm_0_i_0_r_0_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_0_r_0_t_5_busy, S1MMEtore::msg_sm_0_i_0_r_0_t_5_cnt, S1MMEtore::msg_sm_0_i_0_r_0_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_0_r_0_t_6_busy, S1MMEtore::msg_sm_0_i_0_r_0_t_6_cnt, S1MMEtore::msg_sm_0_i_0_r_0_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_0_r_0_t_7_busy, S1MMEtore::msg_sm_0_i_0_r_0_t_7_cnt, S1MMEtore::msg_sm_0_i_0_r_0_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_0_r_0_t_8_busy, S1MMEtore::msg_sm_0_i_0_r_0_t_8_cnt, S1MMEtore::msg_sm_0_i_0_r_0_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_0_r_0_t_9_busy, S1MMEtore::msg_sm_0_i_0_r_0_t_9_cnt, S1MMEtore::msg_sm_0_i_0_r_0_t_9, pSctp);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_0_r_0_t_0_busy, S1MMEtore::msg_sm_1_i_0_r_0_t_0_cnt, S1MMEtore::msg_sm_1_i_0_r_0_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_0_r_0_t_1_busy, S1MMEtore::msg_sm_1_i_0_r_0_t_1_cnt, S1MMEtore::msg_sm_1_i_0_r_0_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_0_r_0_t_2_busy, S1MMEtore::msg_sm_1_i_0_r_0_t_2_cnt, S1MMEtore::msg_sm_1_i_0_r_0_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_0_r_0_t_3_busy, S1MMEtore::msg_sm_1_i_0_r_0_t_3_cnt, S1MMEtore::msg_sm_1_i_0_r_0_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_0_r_0_t_4_busy, S1MMEtore::msg_sm_1_i_0_r_0_t_4_cnt, S1MMEtore::msg_sm_1_i_0_r_0_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_0_r_0_t_5_busy, S1MMEtore::msg_sm_1_i_0_r_0_t_5_cnt, S1MMEtore::msg_sm_1_i_0_r_0_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_0_r_0_t_6_busy, S1MMEtore::msg_sm_1_i_0_r_0_t_6_cnt, S1MMEtore::msg_sm_1_i_0_r_0_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_0_r_0_t_7_busy, S1MMEtore::msg_sm_1_i_0_r_0_t_7_cnt, S1MMEtore::msg_sm_1_i_0_r_0_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_0_r_0_t_8_busy, S1MMEtore::msg_sm_1_i_0_r_0_t_8_cnt, S1MMEtore::msg_sm_1_i_0_r_0_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_0_r_0_t_9_busy, S1MMEtore::msg_sm_1_i_0_r_0_t_9_cnt, S1MMEtore::msg_sm_1_i_0_r_0_t_9, pSctp);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_0_r_0_t_0_busy, S1MMEtore::msg_sm_2_i_0_r_0_t_0_cnt, S1MMEtore::msg_sm_2_i_0_r_0_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_0_r_0_t_1_busy, S1MMEtore::msg_sm_2_i_0_r_0_t_1_cnt, S1MMEtore::msg_sm_2_i_0_r_0_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_0_r_0_t_2_busy, S1MMEtore::msg_sm_2_i_0_r_0_t_2_cnt, S1MMEtore::msg_sm_2_i_0_r_0_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_0_r_0_t_3_busy, S1MMEtore::msg_sm_2_i_0_r_0_t_3_cnt, S1MMEtore::msg_sm_2_i_0_r_0_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_0_r_0_t_4_busy, S1MMEtore::msg_sm_2_i_0_r_0_t_4_cnt, S1MMEtore::msg_sm_2_i_0_r_0_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_0_r_0_t_5_busy, S1MMEtore::msg_sm_2_i_0_r_0_t_5_cnt, S1MMEtore::msg_sm_2_i_0_r_0_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_0_r_0_t_6_busy, S1MMEtore::msg_sm_2_i_0_r_0_t_6_cnt, S1MMEtore::msg_sm_2_i_0_r_0_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_0_r_0_t_7_busy, S1MMEtore::msg_sm_2_i_0_r_0_t_7_cnt, S1MMEtore::msg_sm_2_i_0_r_0_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_0_r_0_t_8_busy, S1MMEtore::msg_sm_2_i_0_r_0_t_8_cnt, S1MMEtore::msg_sm_2_i_0_r_0_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_0_r_0_t_9_busy, S1MMEtore::msg_sm_2_i_0_r_0_t_9_cnt, S1MMEtore::msg_sm_2_i_0_r_0_t_9, pSctp);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_0_r_0_t_0_busy, S1MMEtore::msg_sm_3_i_0_r_0_t_0_cnt, S1MMEtore::msg_sm_3_i_0_r_0_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_0_r_0_t_1_busy, S1MMEtore::msg_sm_3_i_0_r_0_t_1_cnt, S1MMEtore::msg_sm_3_i_0_r_0_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_0_r_0_t_2_busy, S1MMEtore::msg_sm_3_i_0_r_0_t_2_cnt, S1MMEtore::msg_sm_3_i_0_r_0_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_0_r_0_t_3_busy, S1MMEtore::msg_sm_3_i_0_r_0_t_3_cnt, S1MMEtore::msg_sm_3_i_0_r_0_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_0_r_0_t_4_busy, S1MMEtore::msg_sm_3_i_0_r_0_t_4_cnt, S1MMEtore::msg_sm_3_i_0_r_0_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_0_r_0_t_5_busy, S1MMEtore::msg_sm_3_i_0_r_0_t_5_cnt, S1MMEtore::msg_sm_3_i_0_r_0_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_0_r_0_t_6_busy, S1MMEtore::msg_sm_3_i_0_r_0_t_6_cnt, S1MMEtore::msg_sm_3_i_0_r_0_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_0_r_0_t_7_busy, S1MMEtore::msg_sm_3_i_0_r_0_t_7_cnt, S1MMEtore::msg_sm_3_i_0_r_0_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_0_r_0_t_8_busy, S1MMEtore::msg_sm_3_i_0_r_0_t_8_cnt, S1MMEtore::msg_sm_3_i_0_r_0_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_0_r_0_t_9_busy, S1MMEtore::msg_sm_3_i_0_r_0_t_9_cnt, S1MMEtore::msg_sm_3_i_0_r_0_t_9, pSctp);
				break;
			}
			break;
	}
}

VOID SctpMessageBroker::pushToQueue_i_0_r_1(Sctp *pSctp, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_0_r_1_t_0_busy, S1MMEtore::msg_sm_0_i_0_r_1_t_0_cnt, S1MMEtore::msg_sm_0_i_0_r_1_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_0_r_1_t_1_busy, S1MMEtore::msg_sm_0_i_0_r_1_t_1_cnt, S1MMEtore::msg_sm_0_i_0_r_1_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_0_r_1_t_2_busy, S1MMEtore::msg_sm_0_i_0_r_1_t_2_cnt, S1MMEtore::msg_sm_0_i_0_r_1_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_0_r_1_t_3_busy, S1MMEtore::msg_sm_0_i_0_r_1_t_3_cnt, S1MMEtore::msg_sm_0_i_0_r_1_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_0_r_1_t_4_busy, S1MMEtore::msg_sm_0_i_0_r_1_t_4_cnt, S1MMEtore::msg_sm_0_i_0_r_1_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_0_r_1_t_5_busy, S1MMEtore::msg_sm_0_i_0_r_1_t_5_cnt, S1MMEtore::msg_sm_0_i_0_r_1_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_0_r_1_t_6_busy, S1MMEtore::msg_sm_0_i_0_r_1_t_6_cnt, S1MMEtore::msg_sm_0_i_0_r_1_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_0_r_1_t_7_busy, S1MMEtore::msg_sm_0_i_0_r_1_t_7_cnt, S1MMEtore::msg_sm_0_i_0_r_1_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_0_r_1_t_8_busy, S1MMEtore::msg_sm_0_i_0_r_1_t_8_cnt, S1MMEtore::msg_sm_0_i_0_r_1_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_0_r_1_t_9_busy, S1MMEtore::msg_sm_0_i_0_r_1_t_9_cnt, S1MMEtore::msg_sm_0_i_0_r_1_t_9, pSctp);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_0_r_1_t_0_busy, S1MMEtore::msg_sm_1_i_0_r_1_t_0_cnt, S1MMEtore::msg_sm_1_i_0_r_1_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_0_r_1_t_1_busy, S1MMEtore::msg_sm_1_i_0_r_1_t_1_cnt, S1MMEtore::msg_sm_1_i_0_r_1_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_0_r_1_t_2_busy, S1MMEtore::msg_sm_1_i_0_r_1_t_2_cnt, S1MMEtore::msg_sm_1_i_0_r_1_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_0_r_1_t_3_busy, S1MMEtore::msg_sm_1_i_0_r_1_t_3_cnt, S1MMEtore::msg_sm_1_i_0_r_1_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_0_r_1_t_4_busy, S1MMEtore::msg_sm_1_i_0_r_1_t_4_cnt, S1MMEtore::msg_sm_1_i_0_r_1_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_0_r_1_t_5_busy, S1MMEtore::msg_sm_1_i_0_r_1_t_5_cnt, S1MMEtore::msg_sm_1_i_0_r_1_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_0_r_1_t_6_busy, S1MMEtore::msg_sm_1_i_0_r_1_t_6_cnt, S1MMEtore::msg_sm_1_i_0_r_1_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_0_r_1_t_7_busy, S1MMEtore::msg_sm_1_i_0_r_1_t_7_cnt, S1MMEtore::msg_sm_1_i_0_r_1_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_0_r_1_t_8_busy, S1MMEtore::msg_sm_1_i_0_r_1_t_8_cnt, S1MMEtore::msg_sm_1_i_0_r_1_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_0_r_1_t_9_busy, S1MMEtore::msg_sm_1_i_0_r_1_t_9_cnt, S1MMEtore::msg_sm_1_i_0_r_1_t_9, pSctp);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_0_r_1_t_0_busy, S1MMEtore::msg_sm_2_i_0_r_1_t_0_cnt, S1MMEtore::msg_sm_2_i_0_r_1_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_0_r_1_t_1_busy, S1MMEtore::msg_sm_2_i_0_r_1_t_1_cnt, S1MMEtore::msg_sm_2_i_0_r_1_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_0_r_1_t_2_busy, S1MMEtore::msg_sm_2_i_0_r_1_t_2_cnt, S1MMEtore::msg_sm_2_i_0_r_1_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_0_r_1_t_3_busy, S1MMEtore::msg_sm_2_i_0_r_1_t_3_cnt, S1MMEtore::msg_sm_2_i_0_r_1_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_0_r_1_t_4_busy, S1MMEtore::msg_sm_2_i_0_r_1_t_4_cnt, S1MMEtore::msg_sm_2_i_0_r_1_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_0_r_1_t_5_busy, S1MMEtore::msg_sm_2_i_0_r_1_t_5_cnt, S1MMEtore::msg_sm_2_i_0_r_1_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_0_r_1_t_6_busy, S1MMEtore::msg_sm_2_i_0_r_1_t_6_cnt, S1MMEtore::msg_sm_2_i_0_r_1_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_0_r_1_t_7_busy, S1MMEtore::msg_sm_2_i_0_r_1_t_7_cnt, S1MMEtore::msg_sm_2_i_0_r_1_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_0_r_1_t_8_busy, S1MMEtore::msg_sm_2_i_0_r_1_t_8_cnt, S1MMEtore::msg_sm_2_i_0_r_1_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_0_r_1_t_9_busy, S1MMEtore::msg_sm_2_i_0_r_1_t_9_cnt, S1MMEtore::msg_sm_2_i_0_r_1_t_9, pSctp);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_0_r_1_t_0_busy, S1MMEtore::msg_sm_3_i_0_r_1_t_0_cnt, S1MMEtore::msg_sm_3_i_0_r_1_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_0_r_1_t_1_busy, S1MMEtore::msg_sm_3_i_0_r_1_t_1_cnt, S1MMEtore::msg_sm_3_i_0_r_1_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_0_r_1_t_2_busy, S1MMEtore::msg_sm_3_i_0_r_1_t_2_cnt, S1MMEtore::msg_sm_3_i_0_r_1_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_0_r_1_t_3_busy, S1MMEtore::msg_sm_3_i_0_r_1_t_3_cnt, S1MMEtore::msg_sm_3_i_0_r_1_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_0_r_1_t_4_busy, S1MMEtore::msg_sm_3_i_0_r_1_t_4_cnt, S1MMEtore::msg_sm_3_i_0_r_1_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_0_r_1_t_5_busy, S1MMEtore::msg_sm_3_i_0_r_1_t_5_cnt, S1MMEtore::msg_sm_3_i_0_r_1_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_0_r_1_t_6_busy, S1MMEtore::msg_sm_3_i_0_r_1_t_6_cnt, S1MMEtore::msg_sm_3_i_0_r_1_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_0_r_1_t_7_busy, S1MMEtore::msg_sm_3_i_0_r_1_t_7_cnt, S1MMEtore::msg_sm_3_i_0_r_1_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_0_r_1_t_8_busy, S1MMEtore::msg_sm_3_i_0_r_1_t_8_cnt, S1MMEtore::msg_sm_3_i_0_r_1_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_0_r_1_t_9_busy, S1MMEtore::msg_sm_3_i_0_r_1_t_9_cnt, S1MMEtore::msg_sm_3_i_0_r_1_t_9, pSctp);
				break;
			}
			break;
	}
}

VOID SctpMessageBroker::pushToQueue_i_0_r_2(Sctp *pSctp, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_0_r_2_t_0_busy, S1MMEtore::msg_sm_0_i_0_r_2_t_0_cnt, S1MMEtore::msg_sm_0_i_0_r_2_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_0_r_2_t_1_busy, S1MMEtore::msg_sm_0_i_0_r_2_t_1_cnt, S1MMEtore::msg_sm_0_i_0_r_2_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_0_r_2_t_2_busy, S1MMEtore::msg_sm_0_i_0_r_2_t_2_cnt, S1MMEtore::msg_sm_0_i_0_r_2_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_0_r_2_t_3_busy, S1MMEtore::msg_sm_0_i_0_r_2_t_3_cnt, S1MMEtore::msg_sm_0_i_0_r_2_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_0_r_2_t_4_busy, S1MMEtore::msg_sm_0_i_0_r_2_t_4_cnt, S1MMEtore::msg_sm_0_i_0_r_2_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_0_r_2_t_5_busy, S1MMEtore::msg_sm_0_i_0_r_2_t_5_cnt, S1MMEtore::msg_sm_0_i_0_r_2_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_0_r_2_t_6_busy, S1MMEtore::msg_sm_0_i_0_r_2_t_6_cnt, S1MMEtore::msg_sm_0_i_0_r_2_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_0_r_2_t_7_busy, S1MMEtore::msg_sm_0_i_0_r_2_t_7_cnt, S1MMEtore::msg_sm_0_i_0_r_2_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_0_r_2_t_8_busy, S1MMEtore::msg_sm_0_i_0_r_2_t_8_cnt, S1MMEtore::msg_sm_0_i_0_r_2_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_0_r_2_t_9_busy, S1MMEtore::msg_sm_0_i_0_r_2_t_9_cnt, S1MMEtore::msg_sm_0_i_0_r_2_t_9, pSctp);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_0_r_2_t_0_busy, S1MMEtore::msg_sm_1_i_0_r_2_t_0_cnt, S1MMEtore::msg_sm_1_i_0_r_2_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_0_r_2_t_1_busy, S1MMEtore::msg_sm_1_i_0_r_2_t_1_cnt, S1MMEtore::msg_sm_1_i_0_r_2_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_0_r_2_t_2_busy, S1MMEtore::msg_sm_1_i_0_r_2_t_2_cnt, S1MMEtore::msg_sm_1_i_0_r_2_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_0_r_2_t_3_busy, S1MMEtore::msg_sm_1_i_0_r_2_t_3_cnt, S1MMEtore::msg_sm_1_i_0_r_2_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_0_r_2_t_4_busy, S1MMEtore::msg_sm_1_i_0_r_2_t_4_cnt, S1MMEtore::msg_sm_1_i_0_r_2_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_0_r_2_t_5_busy, S1MMEtore::msg_sm_1_i_0_r_2_t_5_cnt, S1MMEtore::msg_sm_1_i_0_r_2_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_0_r_2_t_6_busy, S1MMEtore::msg_sm_1_i_0_r_2_t_6_cnt, S1MMEtore::msg_sm_1_i_0_r_2_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_0_r_2_t_7_busy, S1MMEtore::msg_sm_1_i_0_r_2_t_7_cnt, S1MMEtore::msg_sm_1_i_0_r_2_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_0_r_2_t_8_busy, S1MMEtore::msg_sm_1_i_0_r_2_t_8_cnt, S1MMEtore::msg_sm_1_i_0_r_2_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_0_r_2_t_9_busy, S1MMEtore::msg_sm_1_i_0_r_2_t_9_cnt, S1MMEtore::msg_sm_1_i_0_r_2_t_9, pSctp);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_0_r_2_t_0_busy, S1MMEtore::msg_sm_2_i_0_r_2_t_0_cnt, S1MMEtore::msg_sm_2_i_0_r_2_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_0_r_2_t_1_busy, S1MMEtore::msg_sm_2_i_0_r_2_t_1_cnt, S1MMEtore::msg_sm_2_i_0_r_2_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_0_r_2_t_2_busy, S1MMEtore::msg_sm_2_i_0_r_2_t_2_cnt, S1MMEtore::msg_sm_2_i_0_r_2_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_0_r_2_t_3_busy, S1MMEtore::msg_sm_2_i_0_r_2_t_3_cnt, S1MMEtore::msg_sm_2_i_0_r_2_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_0_r_2_t_4_busy, S1MMEtore::msg_sm_2_i_0_r_2_t_4_cnt, S1MMEtore::msg_sm_2_i_0_r_2_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_0_r_2_t_5_busy, S1MMEtore::msg_sm_2_i_0_r_2_t_5_cnt, S1MMEtore::msg_sm_2_i_0_r_2_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_0_r_2_t_6_busy, S1MMEtore::msg_sm_2_i_0_r_2_t_6_cnt, S1MMEtore::msg_sm_2_i_0_r_2_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_0_r_2_t_7_busy, S1MMEtore::msg_sm_2_i_0_r_2_t_7_cnt, S1MMEtore::msg_sm_2_i_0_r_2_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_0_r_2_t_8_busy, S1MMEtore::msg_sm_2_i_0_r_2_t_8_cnt, S1MMEtore::msg_sm_2_i_0_r_2_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_0_r_2_t_9_busy, S1MMEtore::msg_sm_2_i_0_r_2_t_9_cnt, S1MMEtore::msg_sm_2_i_0_r_2_t_9, pSctp);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_0_r_2_t_0_busy, S1MMEtore::msg_sm_3_i_0_r_2_t_0_cnt, S1MMEtore::msg_sm_3_i_0_r_2_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_0_r_2_t_1_busy, S1MMEtore::msg_sm_3_i_0_r_2_t_1_cnt, S1MMEtore::msg_sm_3_i_0_r_2_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_0_r_2_t_2_busy, S1MMEtore::msg_sm_3_i_0_r_2_t_2_cnt, S1MMEtore::msg_sm_3_i_0_r_2_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_0_r_2_t_3_busy, S1MMEtore::msg_sm_3_i_0_r_2_t_3_cnt, S1MMEtore::msg_sm_3_i_0_r_2_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_0_r_2_t_4_busy, S1MMEtore::msg_sm_3_i_0_r_2_t_4_cnt, S1MMEtore::msg_sm_3_i_0_r_2_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_0_r_2_t_5_busy, S1MMEtore::msg_sm_3_i_0_r_2_t_5_cnt, S1MMEtore::msg_sm_3_i_0_r_2_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_0_r_2_t_6_busy, S1MMEtore::msg_sm_3_i_0_r_2_t_6_cnt, S1MMEtore::msg_sm_3_i_0_r_2_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_0_r_2_t_7_busy, S1MMEtore::msg_sm_3_i_0_r_2_t_7_cnt, S1MMEtore::msg_sm_3_i_0_r_2_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_0_r_2_t_8_busy, S1MMEtore::msg_sm_3_i_0_r_2_t_8_cnt, S1MMEtore::msg_sm_3_i_0_r_2_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_0_r_2_t_9_busy, S1MMEtore::msg_sm_3_i_0_r_2_t_9_cnt, S1MMEtore::msg_sm_3_i_0_r_2_t_9, pSctp);
				break;
			}
			break;
	}
}

VOID SctpMessageBroker::pushToQueue_i_0_r_3(Sctp *pSctp, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_0_r_3_t_0_busy, S1MMEtore::msg_sm_0_i_0_r_3_t_0_cnt, S1MMEtore::msg_sm_0_i_0_r_3_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_0_r_3_t_1_busy, S1MMEtore::msg_sm_0_i_0_r_3_t_1_cnt, S1MMEtore::msg_sm_0_i_0_r_3_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_0_r_3_t_2_busy, S1MMEtore::msg_sm_0_i_0_r_3_t_2_cnt, S1MMEtore::msg_sm_0_i_0_r_3_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_0_r_3_t_3_busy, S1MMEtore::msg_sm_0_i_0_r_3_t_3_cnt, S1MMEtore::msg_sm_0_i_0_r_3_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_0_r_3_t_4_busy, S1MMEtore::msg_sm_0_i_0_r_3_t_4_cnt, S1MMEtore::msg_sm_0_i_0_r_3_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_0_r_3_t_5_busy, S1MMEtore::msg_sm_0_i_0_r_3_t_5_cnt, S1MMEtore::msg_sm_0_i_0_r_3_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_0_r_3_t_6_busy, S1MMEtore::msg_sm_0_i_0_r_3_t_6_cnt, S1MMEtore::msg_sm_0_i_0_r_3_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_0_r_3_t_7_busy, S1MMEtore::msg_sm_0_i_0_r_3_t_7_cnt, S1MMEtore::msg_sm_0_i_0_r_3_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_0_r_3_t_8_busy, S1MMEtore::msg_sm_0_i_0_r_3_t_8_cnt, S1MMEtore::msg_sm_0_i_0_r_3_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_0_r_3_t_9_busy, S1MMEtore::msg_sm_0_i_0_r_3_t_9_cnt, S1MMEtore::msg_sm_0_i_0_r_3_t_9, pSctp);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_0_r_3_t_0_busy, S1MMEtore::msg_sm_1_i_0_r_3_t_0_cnt, S1MMEtore::msg_sm_1_i_0_r_3_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_0_r_3_t_1_busy, S1MMEtore::msg_sm_1_i_0_r_3_t_1_cnt, S1MMEtore::msg_sm_1_i_0_r_3_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_0_r_3_t_2_busy, S1MMEtore::msg_sm_1_i_0_r_3_t_2_cnt, S1MMEtore::msg_sm_1_i_0_r_3_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_0_r_3_t_3_busy, S1MMEtore::msg_sm_1_i_0_r_3_t_3_cnt, S1MMEtore::msg_sm_1_i_0_r_3_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_0_r_3_t_4_busy, S1MMEtore::msg_sm_1_i_0_r_3_t_4_cnt, S1MMEtore::msg_sm_1_i_0_r_3_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_0_r_3_t_5_busy, S1MMEtore::msg_sm_1_i_0_r_3_t_5_cnt, S1MMEtore::msg_sm_1_i_0_r_3_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_0_r_3_t_6_busy, S1MMEtore::msg_sm_1_i_0_r_3_t_6_cnt, S1MMEtore::msg_sm_1_i_0_r_3_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_0_r_3_t_7_busy, S1MMEtore::msg_sm_1_i_0_r_3_t_7_cnt, S1MMEtore::msg_sm_1_i_0_r_3_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_0_r_3_t_8_busy, S1MMEtore::msg_sm_1_i_0_r_3_t_8_cnt, S1MMEtore::msg_sm_1_i_0_r_3_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_0_r_3_t_9_busy, S1MMEtore::msg_sm_1_i_0_r_3_t_9_cnt, S1MMEtore::msg_sm_1_i_0_r_3_t_9, pSctp);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_0_r_3_t_0_busy, S1MMEtore::msg_sm_2_i_0_r_3_t_0_cnt, S1MMEtore::msg_sm_2_i_0_r_3_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_0_r_3_t_1_busy, S1MMEtore::msg_sm_2_i_0_r_3_t_1_cnt, S1MMEtore::msg_sm_2_i_0_r_3_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_0_r_3_t_2_busy, S1MMEtore::msg_sm_2_i_0_r_3_t_2_cnt, S1MMEtore::msg_sm_2_i_0_r_3_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_0_r_3_t_3_busy, S1MMEtore::msg_sm_2_i_0_r_3_t_3_cnt, S1MMEtore::msg_sm_2_i_0_r_3_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_0_r_3_t_4_busy, S1MMEtore::msg_sm_2_i_0_r_3_t_4_cnt, S1MMEtore::msg_sm_2_i_0_r_3_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_0_r_3_t_5_busy, S1MMEtore::msg_sm_2_i_0_r_3_t_5_cnt, S1MMEtore::msg_sm_2_i_0_r_3_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_0_r_3_t_6_busy, S1MMEtore::msg_sm_2_i_0_r_3_t_6_cnt, S1MMEtore::msg_sm_2_i_0_r_3_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_0_r_3_t_7_busy, S1MMEtore::msg_sm_2_i_0_r_3_t_7_cnt, S1MMEtore::msg_sm_2_i_0_r_3_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_0_r_3_t_8_busy, S1MMEtore::msg_sm_2_i_0_r_3_t_8_cnt, S1MMEtore::msg_sm_2_i_0_r_3_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_0_r_3_t_9_busy, S1MMEtore::msg_sm_2_i_0_r_3_t_9_cnt, S1MMEtore::msg_sm_2_i_0_r_3_t_9, pSctp);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_0_r_3_t_0_busy, S1MMEtore::msg_sm_3_i_0_r_3_t_0_cnt, S1MMEtore::msg_sm_3_i_0_r_3_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_0_r_3_t_1_busy, S1MMEtore::msg_sm_3_i_0_r_3_t_1_cnt, S1MMEtore::msg_sm_3_i_0_r_3_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_0_r_3_t_2_busy, S1MMEtore::msg_sm_3_i_0_r_3_t_2_cnt, S1MMEtore::msg_sm_3_i_0_r_3_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_0_r_3_t_3_busy, S1MMEtore::msg_sm_3_i_0_r_3_t_3_cnt, S1MMEtore::msg_sm_3_i_0_r_3_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_0_r_3_t_4_busy, S1MMEtore::msg_sm_3_i_0_r_3_t_4_cnt, S1MMEtore::msg_sm_3_i_0_r_3_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_0_r_3_t_5_busy, S1MMEtore::msg_sm_3_i_0_r_3_t_5_cnt, S1MMEtore::msg_sm_3_i_0_r_3_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_0_r_3_t_6_busy, S1MMEtore::msg_sm_3_i_0_r_3_t_6_cnt, S1MMEtore::msg_sm_3_i_0_r_3_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_0_r_3_t_7_busy, S1MMEtore::msg_sm_3_i_0_r_3_t_7_cnt, S1MMEtore::msg_sm_3_i_0_r_3_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_0_r_3_t_8_busy, S1MMEtore::msg_sm_3_i_0_r_3_t_8_cnt, S1MMEtore::msg_sm_3_i_0_r_3_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_0_r_3_t_9_busy, S1MMEtore::msg_sm_3_i_0_r_3_t_9_cnt, S1MMEtore::msg_sm_3_i_0_r_3_t_9, pSctp);
				break;
			}
			break;
	}
}

VOID SctpMessageBroker::pushToQueue_i_0_r_4(Sctp *pSctp, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_0_r_4_t_0_busy, S1MMEtore::msg_sm_0_i_0_r_4_t_0_cnt, S1MMEtore::msg_sm_0_i_0_r_4_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_0_r_4_t_1_busy, S1MMEtore::msg_sm_0_i_0_r_4_t_1_cnt, S1MMEtore::msg_sm_0_i_0_r_4_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_0_r_4_t_2_busy, S1MMEtore::msg_sm_0_i_0_r_4_t_2_cnt, S1MMEtore::msg_sm_0_i_0_r_4_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_0_r_4_t_3_busy, S1MMEtore::msg_sm_0_i_0_r_4_t_3_cnt, S1MMEtore::msg_sm_0_i_0_r_4_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_0_r_4_t_4_busy, S1MMEtore::msg_sm_0_i_0_r_4_t_4_cnt, S1MMEtore::msg_sm_0_i_0_r_4_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_0_r_4_t_5_busy, S1MMEtore::msg_sm_0_i_0_r_4_t_5_cnt, S1MMEtore::msg_sm_0_i_0_r_4_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_0_r_4_t_6_busy, S1MMEtore::msg_sm_0_i_0_r_4_t_6_cnt, S1MMEtore::msg_sm_0_i_0_r_4_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_0_r_4_t_7_busy, S1MMEtore::msg_sm_0_i_0_r_4_t_7_cnt, S1MMEtore::msg_sm_0_i_0_r_4_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_0_r_4_t_8_busy, S1MMEtore::msg_sm_0_i_0_r_4_t_8_cnt, S1MMEtore::msg_sm_0_i_0_r_4_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_0_r_4_t_9_busy, S1MMEtore::msg_sm_0_i_0_r_4_t_9_cnt, S1MMEtore::msg_sm_0_i_0_r_4_t_9, pSctp);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_0_r_4_t_0_busy, S1MMEtore::msg_sm_1_i_0_r_4_t_0_cnt, S1MMEtore::msg_sm_1_i_0_r_4_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_0_r_4_t_1_busy, S1MMEtore::msg_sm_1_i_0_r_4_t_1_cnt, S1MMEtore::msg_sm_1_i_0_r_4_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_0_r_4_t_2_busy, S1MMEtore::msg_sm_1_i_0_r_4_t_2_cnt, S1MMEtore::msg_sm_1_i_0_r_4_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_0_r_4_t_3_busy, S1MMEtore::msg_sm_1_i_0_r_4_t_3_cnt, S1MMEtore::msg_sm_1_i_0_r_4_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_0_r_4_t_4_busy, S1MMEtore::msg_sm_1_i_0_r_4_t_4_cnt, S1MMEtore::msg_sm_1_i_0_r_4_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_0_r_4_t_5_busy, S1MMEtore::msg_sm_1_i_0_r_4_t_5_cnt, S1MMEtore::msg_sm_1_i_0_r_4_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_0_r_4_t_6_busy, S1MMEtore::msg_sm_1_i_0_r_4_t_6_cnt, S1MMEtore::msg_sm_1_i_0_r_4_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_0_r_4_t_7_busy, S1MMEtore::msg_sm_1_i_0_r_4_t_7_cnt, S1MMEtore::msg_sm_1_i_0_r_4_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_0_r_4_t_8_busy, S1MMEtore::msg_sm_1_i_0_r_4_t_8_cnt, S1MMEtore::msg_sm_1_i_0_r_4_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_0_r_4_t_9_busy, S1MMEtore::msg_sm_1_i_0_r_4_t_9_cnt, S1MMEtore::msg_sm_1_i_0_r_4_t_9, pSctp);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_0_r_4_t_0_busy, S1MMEtore::msg_sm_2_i_0_r_4_t_0_cnt, S1MMEtore::msg_sm_2_i_0_r_4_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_0_r_4_t_1_busy, S1MMEtore::msg_sm_2_i_0_r_4_t_1_cnt, S1MMEtore::msg_sm_2_i_0_r_4_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_0_r_4_t_2_busy, S1MMEtore::msg_sm_2_i_0_r_4_t_2_cnt, S1MMEtore::msg_sm_2_i_0_r_4_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_0_r_4_t_3_busy, S1MMEtore::msg_sm_2_i_0_r_4_t_3_cnt, S1MMEtore::msg_sm_2_i_0_r_4_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_0_r_4_t_4_busy, S1MMEtore::msg_sm_2_i_0_r_4_t_4_cnt, S1MMEtore::msg_sm_2_i_0_r_4_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_0_r_4_t_5_busy, S1MMEtore::msg_sm_2_i_0_r_4_t_5_cnt, S1MMEtore::msg_sm_2_i_0_r_4_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_0_r_4_t_6_busy, S1MMEtore::msg_sm_2_i_0_r_4_t_6_cnt, S1MMEtore::msg_sm_2_i_0_r_4_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_0_r_4_t_7_busy, S1MMEtore::msg_sm_2_i_0_r_4_t_7_cnt, S1MMEtore::msg_sm_2_i_0_r_4_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_0_r_4_t_8_busy, S1MMEtore::msg_sm_2_i_0_r_4_t_8_cnt, S1MMEtore::msg_sm_2_i_0_r_4_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_0_r_4_t_9_busy, S1MMEtore::msg_sm_2_i_0_r_4_t_9_cnt, S1MMEtore::msg_sm_2_i_0_r_4_t_9, pSctp);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_0_r_4_t_0_busy, S1MMEtore::msg_sm_3_i_0_r_4_t_0_cnt, S1MMEtore::msg_sm_3_i_0_r_4_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_0_r_4_t_1_busy, S1MMEtore::msg_sm_3_i_0_r_4_t_1_cnt, S1MMEtore::msg_sm_3_i_0_r_4_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_0_r_4_t_2_busy, S1MMEtore::msg_sm_3_i_0_r_4_t_2_cnt, S1MMEtore::msg_sm_3_i_0_r_4_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_0_r_4_t_3_busy, S1MMEtore::msg_sm_3_i_0_r_4_t_3_cnt, S1MMEtore::msg_sm_3_i_0_r_4_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_0_r_4_t_4_busy, S1MMEtore::msg_sm_3_i_0_r_4_t_4_cnt, S1MMEtore::msg_sm_3_i_0_r_4_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_0_r_4_t_5_busy, S1MMEtore::msg_sm_3_i_0_r_4_t_5_cnt, S1MMEtore::msg_sm_3_i_0_r_4_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_0_r_4_t_6_busy, S1MMEtore::msg_sm_3_i_0_r_4_t_6_cnt, S1MMEtore::msg_sm_3_i_0_r_4_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_0_r_4_t_7_busy, S1MMEtore::msg_sm_3_i_0_r_4_t_7_cnt, S1MMEtore::msg_sm_3_i_0_r_4_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_0_r_4_t_8_busy, S1MMEtore::msg_sm_3_i_0_r_4_t_8_cnt, S1MMEtore::msg_sm_3_i_0_r_4_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_0_r_4_t_9_busy, S1MMEtore::msg_sm_3_i_0_r_4_t_9_cnt, S1MMEtore::msg_sm_3_i_0_r_4_t_9, pSctp);
				break;
			}
			break;
	}
}

VOID SctpMessageBroker::pushToQueue_i_0_r_5(Sctp *pSctp, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_0_r_5_t_0_busy, S1MMEtore::msg_sm_0_i_0_r_5_t_0_cnt, S1MMEtore::msg_sm_0_i_0_r_5_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_0_r_5_t_1_busy, S1MMEtore::msg_sm_0_i_0_r_5_t_1_cnt, S1MMEtore::msg_sm_0_i_0_r_5_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_0_r_5_t_2_busy, S1MMEtore::msg_sm_0_i_0_r_5_t_2_cnt, S1MMEtore::msg_sm_0_i_0_r_5_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_0_r_5_t_3_busy, S1MMEtore::msg_sm_0_i_0_r_5_t_3_cnt, S1MMEtore::msg_sm_0_i_0_r_5_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_0_r_5_t_4_busy, S1MMEtore::msg_sm_0_i_0_r_5_t_4_cnt, S1MMEtore::msg_sm_0_i_0_r_5_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_0_r_5_t_5_busy, S1MMEtore::msg_sm_0_i_0_r_5_t_5_cnt, S1MMEtore::msg_sm_0_i_0_r_5_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_0_r_5_t_6_busy, S1MMEtore::msg_sm_0_i_0_r_5_t_6_cnt, S1MMEtore::msg_sm_0_i_0_r_5_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_0_r_5_t_7_busy, S1MMEtore::msg_sm_0_i_0_r_5_t_7_cnt, S1MMEtore::msg_sm_0_i_0_r_5_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_0_r_5_t_8_busy, S1MMEtore::msg_sm_0_i_0_r_5_t_8_cnt, S1MMEtore::msg_sm_0_i_0_r_5_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_0_r_5_t_9_busy, S1MMEtore::msg_sm_0_i_0_r_5_t_9_cnt, S1MMEtore::msg_sm_0_i_0_r_5_t_9, pSctp);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_0_r_5_t_0_busy, S1MMEtore::msg_sm_1_i_0_r_5_t_0_cnt, S1MMEtore::msg_sm_1_i_0_r_5_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_0_r_5_t_1_busy, S1MMEtore::msg_sm_1_i_0_r_5_t_1_cnt, S1MMEtore::msg_sm_1_i_0_r_5_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_0_r_5_t_2_busy, S1MMEtore::msg_sm_1_i_0_r_5_t_2_cnt, S1MMEtore::msg_sm_1_i_0_r_5_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_0_r_5_t_3_busy, S1MMEtore::msg_sm_1_i_0_r_5_t_3_cnt, S1MMEtore::msg_sm_1_i_0_r_5_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_0_r_5_t_4_busy, S1MMEtore::msg_sm_1_i_0_r_5_t_4_cnt, S1MMEtore::msg_sm_1_i_0_r_5_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_0_r_5_t_5_busy, S1MMEtore::msg_sm_1_i_0_r_5_t_5_cnt, S1MMEtore::msg_sm_1_i_0_r_5_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_0_r_5_t_6_busy, S1MMEtore::msg_sm_1_i_0_r_5_t_6_cnt, S1MMEtore::msg_sm_1_i_0_r_5_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_0_r_5_t_7_busy, S1MMEtore::msg_sm_1_i_0_r_5_t_7_cnt, S1MMEtore::msg_sm_1_i_0_r_5_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_0_r_5_t_8_busy, S1MMEtore::msg_sm_1_i_0_r_5_t_8_cnt, S1MMEtore::msg_sm_1_i_0_r_5_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_0_r_5_t_9_busy, S1MMEtore::msg_sm_1_i_0_r_5_t_9_cnt, S1MMEtore::msg_sm_1_i_0_r_5_t_9, pSctp);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_0_r_5_t_0_busy, S1MMEtore::msg_sm_2_i_0_r_5_t_0_cnt, S1MMEtore::msg_sm_2_i_0_r_5_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_0_r_5_t_1_busy, S1MMEtore::msg_sm_2_i_0_r_5_t_1_cnt, S1MMEtore::msg_sm_2_i_0_r_5_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_0_r_5_t_2_busy, S1MMEtore::msg_sm_2_i_0_r_5_t_2_cnt, S1MMEtore::msg_sm_2_i_0_r_5_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_0_r_5_t_3_busy, S1MMEtore::msg_sm_2_i_0_r_5_t_3_cnt, S1MMEtore::msg_sm_2_i_0_r_5_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_0_r_5_t_4_busy, S1MMEtore::msg_sm_2_i_0_r_5_t_4_cnt, S1MMEtore::msg_sm_2_i_0_r_5_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_0_r_5_t_5_busy, S1MMEtore::msg_sm_2_i_0_r_5_t_5_cnt, S1MMEtore::msg_sm_2_i_0_r_5_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_0_r_5_t_6_busy, S1MMEtore::msg_sm_2_i_0_r_5_t_6_cnt, S1MMEtore::msg_sm_2_i_0_r_5_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_0_r_5_t_7_busy, S1MMEtore::msg_sm_2_i_0_r_5_t_7_cnt, S1MMEtore::msg_sm_2_i_0_r_5_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_0_r_5_t_8_busy, S1MMEtore::msg_sm_2_i_0_r_5_t_8_cnt, S1MMEtore::msg_sm_2_i_0_r_5_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_0_r_5_t_9_busy, S1MMEtore::msg_sm_2_i_0_r_5_t_9_cnt, S1MMEtore::msg_sm_2_i_0_r_5_t_9, pSctp);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_0_r_5_t_0_busy, S1MMEtore::msg_sm_3_i_0_r_5_t_0_cnt, S1MMEtore::msg_sm_3_i_0_r_5_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_0_r_5_t_1_busy, S1MMEtore::msg_sm_3_i_0_r_5_t_1_cnt, S1MMEtore::msg_sm_3_i_0_r_5_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_0_r_5_t_2_busy, S1MMEtore::msg_sm_3_i_0_r_5_t_2_cnt, S1MMEtore::msg_sm_3_i_0_r_5_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_0_r_5_t_3_busy, S1MMEtore::msg_sm_3_i_0_r_5_t_3_cnt, S1MMEtore::msg_sm_3_i_0_r_5_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_0_r_5_t_4_busy, S1MMEtore::msg_sm_3_i_0_r_5_t_4_cnt, S1MMEtore::msg_sm_3_i_0_r_5_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_0_r_5_t_5_busy, S1MMEtore::msg_sm_3_i_0_r_5_t_5_cnt, S1MMEtore::msg_sm_3_i_0_r_5_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_0_r_5_t_6_busy, S1MMEtore::msg_sm_3_i_0_r_5_t_6_cnt, S1MMEtore::msg_sm_3_i_0_r_5_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_0_r_5_t_7_busy, S1MMEtore::msg_sm_3_i_0_r_5_t_7_cnt, S1MMEtore::msg_sm_3_i_0_r_5_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_0_r_5_t_8_busy, S1MMEtore::msg_sm_3_i_0_r_5_t_8_cnt, S1MMEtore::msg_sm_3_i_0_r_5_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_0_r_5_t_9_busy, S1MMEtore::msg_sm_3_i_0_r_5_t_9_cnt, S1MMEtore::msg_sm_3_i_0_r_5_t_9, pSctp);
				break;
			}
			break;
	}
}

VOID SctpMessageBroker::pushToQueue_i_0_r_6(Sctp *pSctp, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_0_r_6_t_0_busy, S1MMEtore::msg_sm_0_i_0_r_6_t_0_cnt, S1MMEtore::msg_sm_0_i_0_r_6_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_0_r_6_t_1_busy, S1MMEtore::msg_sm_0_i_0_r_6_t_1_cnt, S1MMEtore::msg_sm_0_i_0_r_6_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_0_r_6_t_2_busy, S1MMEtore::msg_sm_0_i_0_r_6_t_2_cnt, S1MMEtore::msg_sm_0_i_0_r_6_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_0_r_6_t_3_busy, S1MMEtore::msg_sm_0_i_0_r_6_t_3_cnt, S1MMEtore::msg_sm_0_i_0_r_6_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_0_r_6_t_4_busy, S1MMEtore::msg_sm_0_i_0_r_6_t_4_cnt, S1MMEtore::msg_sm_0_i_0_r_6_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_0_r_6_t_5_busy, S1MMEtore::msg_sm_0_i_0_r_6_t_5_cnt, S1MMEtore::msg_sm_0_i_0_r_6_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_0_r_6_t_6_busy, S1MMEtore::msg_sm_0_i_0_r_6_t_6_cnt, S1MMEtore::msg_sm_0_i_0_r_6_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_0_r_6_t_7_busy, S1MMEtore::msg_sm_0_i_0_r_6_t_7_cnt, S1MMEtore::msg_sm_0_i_0_r_6_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_0_r_6_t_8_busy, S1MMEtore::msg_sm_0_i_0_r_6_t_8_cnt, S1MMEtore::msg_sm_0_i_0_r_6_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_0_r_6_t_9_busy, S1MMEtore::msg_sm_0_i_0_r_6_t_9_cnt, S1MMEtore::msg_sm_0_i_0_r_6_t_9, pSctp);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_0_r_6_t_0_busy, S1MMEtore::msg_sm_1_i_0_r_6_t_0_cnt, S1MMEtore::msg_sm_1_i_0_r_6_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_0_r_6_t_1_busy, S1MMEtore::msg_sm_1_i_0_r_6_t_1_cnt, S1MMEtore::msg_sm_1_i_0_r_6_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_0_r_6_t_2_busy, S1MMEtore::msg_sm_1_i_0_r_6_t_2_cnt, S1MMEtore::msg_sm_1_i_0_r_6_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_0_r_6_t_3_busy, S1MMEtore::msg_sm_1_i_0_r_6_t_3_cnt, S1MMEtore::msg_sm_1_i_0_r_6_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_0_r_6_t_4_busy, S1MMEtore::msg_sm_1_i_0_r_6_t_4_cnt, S1MMEtore::msg_sm_1_i_0_r_6_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_0_r_6_t_5_busy, S1MMEtore::msg_sm_1_i_0_r_6_t_5_cnt, S1MMEtore::msg_sm_1_i_0_r_6_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_0_r_6_t_6_busy, S1MMEtore::msg_sm_1_i_0_r_6_t_6_cnt, S1MMEtore::msg_sm_1_i_0_r_6_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_0_r_6_t_7_busy, S1MMEtore::msg_sm_1_i_0_r_6_t_7_cnt, S1MMEtore::msg_sm_1_i_0_r_6_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_0_r_6_t_8_busy, S1MMEtore::msg_sm_1_i_0_r_6_t_8_cnt, S1MMEtore::msg_sm_1_i_0_r_6_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_0_r_6_t_9_busy, S1MMEtore::msg_sm_1_i_0_r_6_t_9_cnt, S1MMEtore::msg_sm_1_i_0_r_6_t_9, pSctp);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_0_r_6_t_0_busy, S1MMEtore::msg_sm_2_i_0_r_6_t_0_cnt, S1MMEtore::msg_sm_2_i_0_r_6_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_0_r_6_t_1_busy, S1MMEtore::msg_sm_2_i_0_r_6_t_1_cnt, S1MMEtore::msg_sm_2_i_0_r_6_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_0_r_6_t_2_busy, S1MMEtore::msg_sm_2_i_0_r_6_t_2_cnt, S1MMEtore::msg_sm_2_i_0_r_6_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_0_r_6_t_3_busy, S1MMEtore::msg_sm_2_i_0_r_6_t_3_cnt, S1MMEtore::msg_sm_2_i_0_r_6_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_0_r_6_t_4_busy, S1MMEtore::msg_sm_2_i_0_r_6_t_4_cnt, S1MMEtore::msg_sm_2_i_0_r_6_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_0_r_6_t_5_busy, S1MMEtore::msg_sm_2_i_0_r_6_t_5_cnt, S1MMEtore::msg_sm_2_i_0_r_6_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_0_r_6_t_6_busy, S1MMEtore::msg_sm_2_i_0_r_6_t_6_cnt, S1MMEtore::msg_sm_2_i_0_r_6_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_0_r_6_t_7_busy, S1MMEtore::msg_sm_2_i_0_r_6_t_7_cnt, S1MMEtore::msg_sm_2_i_0_r_6_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_0_r_6_t_8_busy, S1MMEtore::msg_sm_2_i_0_r_6_t_8_cnt, S1MMEtore::msg_sm_2_i_0_r_6_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_0_r_6_t_9_busy, S1MMEtore::msg_sm_2_i_0_r_6_t_9_cnt, S1MMEtore::msg_sm_2_i_0_r_6_t_9, pSctp);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_0_r_6_t_0_busy, S1MMEtore::msg_sm_3_i_0_r_6_t_0_cnt, S1MMEtore::msg_sm_3_i_0_r_6_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_0_r_6_t_1_busy, S1MMEtore::msg_sm_3_i_0_r_6_t_1_cnt, S1MMEtore::msg_sm_3_i_0_r_6_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_0_r_6_t_2_busy, S1MMEtore::msg_sm_3_i_0_r_6_t_2_cnt, S1MMEtore::msg_sm_3_i_0_r_6_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_0_r_6_t_3_busy, S1MMEtore::msg_sm_3_i_0_r_6_t_3_cnt, S1MMEtore::msg_sm_3_i_0_r_6_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_0_r_6_t_4_busy, S1MMEtore::msg_sm_3_i_0_r_6_t_4_cnt, S1MMEtore::msg_sm_3_i_0_r_6_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_0_r_6_t_5_busy, S1MMEtore::msg_sm_3_i_0_r_6_t_5_cnt, S1MMEtore::msg_sm_3_i_0_r_6_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_0_r_6_t_6_busy, S1MMEtore::msg_sm_3_i_0_r_6_t_6_cnt, S1MMEtore::msg_sm_3_i_0_r_6_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_0_r_6_t_7_busy, S1MMEtore::msg_sm_3_i_0_r_6_t_7_cnt, S1MMEtore::msg_sm_3_i_0_r_6_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_0_r_6_t_8_busy, S1MMEtore::msg_sm_3_i_0_r_6_t_8_cnt, S1MMEtore::msg_sm_3_i_0_r_6_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_0_r_6_t_9_busy, S1MMEtore::msg_sm_3_i_0_r_6_t_9_cnt, S1MMEtore::msg_sm_3_i_0_r_6_t_9, pSctp);
				break;
			}
			break;
	}
}

VOID SctpMessageBroker::pushToQueue_i_0_r_7(Sctp *pSctp, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_0_r_7_t_0_busy, S1MMEtore::msg_sm_0_i_0_r_7_t_0_cnt, S1MMEtore::msg_sm_0_i_0_r_7_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_0_r_7_t_1_busy, S1MMEtore::msg_sm_0_i_0_r_7_t_1_cnt, S1MMEtore::msg_sm_0_i_0_r_7_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_0_r_7_t_2_busy, S1MMEtore::msg_sm_0_i_0_r_7_t_2_cnt, S1MMEtore::msg_sm_0_i_0_r_7_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_0_r_7_t_3_busy, S1MMEtore::msg_sm_0_i_0_r_7_t_3_cnt, S1MMEtore::msg_sm_0_i_0_r_7_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_0_r_7_t_4_busy, S1MMEtore::msg_sm_0_i_0_r_7_t_4_cnt, S1MMEtore::msg_sm_0_i_0_r_7_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_0_r_7_t_5_busy, S1MMEtore::msg_sm_0_i_0_r_7_t_5_cnt, S1MMEtore::msg_sm_0_i_0_r_7_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_0_r_7_t_6_busy, S1MMEtore::msg_sm_0_i_0_r_7_t_6_cnt, S1MMEtore::msg_sm_0_i_0_r_7_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_0_r_7_t_7_busy, S1MMEtore::msg_sm_0_i_0_r_7_t_7_cnt, S1MMEtore::msg_sm_0_i_0_r_7_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_0_r_7_t_8_busy, S1MMEtore::msg_sm_0_i_0_r_7_t_8_cnt, S1MMEtore::msg_sm_0_i_0_r_7_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_0_r_7_t_9_busy, S1MMEtore::msg_sm_0_i_0_r_7_t_9_cnt, S1MMEtore::msg_sm_0_i_0_r_7_t_9, pSctp);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_0_r_7_t_0_busy, S1MMEtore::msg_sm_1_i_0_r_7_t_0_cnt, S1MMEtore::msg_sm_1_i_0_r_7_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_0_r_7_t_1_busy, S1MMEtore::msg_sm_1_i_0_r_7_t_1_cnt, S1MMEtore::msg_sm_1_i_0_r_7_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_0_r_7_t_2_busy, S1MMEtore::msg_sm_1_i_0_r_7_t_2_cnt, S1MMEtore::msg_sm_1_i_0_r_7_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_0_r_7_t_3_busy, S1MMEtore::msg_sm_1_i_0_r_7_t_3_cnt, S1MMEtore::msg_sm_1_i_0_r_7_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_0_r_7_t_4_busy, S1MMEtore::msg_sm_1_i_0_r_7_t_4_cnt, S1MMEtore::msg_sm_1_i_0_r_7_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_0_r_7_t_5_busy, S1MMEtore::msg_sm_1_i_0_r_7_t_5_cnt, S1MMEtore::msg_sm_1_i_0_r_7_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_0_r_7_t_6_busy, S1MMEtore::msg_sm_1_i_0_r_7_t_6_cnt, S1MMEtore::msg_sm_1_i_0_r_7_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_0_r_7_t_7_busy, S1MMEtore::msg_sm_1_i_0_r_7_t_7_cnt, S1MMEtore::msg_sm_1_i_0_r_7_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_0_r_7_t_8_busy, S1MMEtore::msg_sm_1_i_0_r_7_t_8_cnt, S1MMEtore::msg_sm_1_i_0_r_7_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_0_r_7_t_9_busy, S1MMEtore::msg_sm_1_i_0_r_7_t_9_cnt, S1MMEtore::msg_sm_1_i_0_r_7_t_9, pSctp);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_0_r_7_t_0_busy, S1MMEtore::msg_sm_2_i_0_r_7_t_0_cnt, S1MMEtore::msg_sm_2_i_0_r_7_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_0_r_7_t_1_busy, S1MMEtore::msg_sm_2_i_0_r_7_t_1_cnt, S1MMEtore::msg_sm_2_i_0_r_7_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_0_r_7_t_2_busy, S1MMEtore::msg_sm_2_i_0_r_7_t_2_cnt, S1MMEtore::msg_sm_2_i_0_r_7_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_0_r_7_t_3_busy, S1MMEtore::msg_sm_2_i_0_r_7_t_3_cnt, S1MMEtore::msg_sm_2_i_0_r_7_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_0_r_7_t_4_busy, S1MMEtore::msg_sm_2_i_0_r_7_t_4_cnt, S1MMEtore::msg_sm_2_i_0_r_7_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_0_r_7_t_5_busy, S1MMEtore::msg_sm_2_i_0_r_7_t_5_cnt, S1MMEtore::msg_sm_2_i_0_r_7_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_0_r_7_t_6_busy, S1MMEtore::msg_sm_2_i_0_r_7_t_6_cnt, S1MMEtore::msg_sm_2_i_0_r_7_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_0_r_7_t_7_busy, S1MMEtore::msg_sm_2_i_0_r_7_t_7_cnt, S1MMEtore::msg_sm_2_i_0_r_7_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_0_r_7_t_8_busy, S1MMEtore::msg_sm_2_i_0_r_7_t_8_cnt, S1MMEtore::msg_sm_2_i_0_r_7_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_0_r_7_t_9_busy, S1MMEtore::msg_sm_2_i_0_r_7_t_9_cnt, S1MMEtore::msg_sm_2_i_0_r_7_t_9, pSctp);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_0_r_7_t_0_busy, S1MMEtore::msg_sm_3_i_0_r_7_t_0_cnt, S1MMEtore::msg_sm_3_i_0_r_7_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_0_r_7_t_1_busy, S1MMEtore::msg_sm_3_i_0_r_7_t_1_cnt, S1MMEtore::msg_sm_3_i_0_r_7_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_0_r_7_t_2_busy, S1MMEtore::msg_sm_3_i_0_r_7_t_2_cnt, S1MMEtore::msg_sm_3_i_0_r_7_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_0_r_7_t_3_busy, S1MMEtore::msg_sm_3_i_0_r_7_t_3_cnt, S1MMEtore::msg_sm_3_i_0_r_7_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_0_r_7_t_4_busy, S1MMEtore::msg_sm_3_i_0_r_7_t_4_cnt, S1MMEtore::msg_sm_3_i_0_r_7_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_0_r_7_t_5_busy, S1MMEtore::msg_sm_3_i_0_r_7_t_5_cnt, S1MMEtore::msg_sm_3_i_0_r_7_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_0_r_7_t_6_busy, S1MMEtore::msg_sm_3_i_0_r_7_t_6_cnt, S1MMEtore::msg_sm_3_i_0_r_7_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_0_r_7_t_7_busy, S1MMEtore::msg_sm_3_i_0_r_7_t_7_cnt, S1MMEtore::msg_sm_3_i_0_r_7_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_0_r_7_t_8_busy, S1MMEtore::msg_sm_3_i_0_r_7_t_8_cnt, S1MMEtore::msg_sm_3_i_0_r_7_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_0_r_7_t_9_busy, S1MMEtore::msg_sm_3_i_0_r_7_t_9_cnt, S1MMEtore::msg_sm_3_i_0_r_7_t_9, pSctp);
				break;
			}
			break;
	}
}


VOID SctpMessageBroker::pushToQueue_i_1_r_0(Sctp *pSctp, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_1_r_0_t_0_busy, S1MMEtore::msg_sm_0_i_1_r_0_t_0_cnt, S1MMEtore::msg_sm_0_i_1_r_0_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_1_r_0_t_1_busy, S1MMEtore::msg_sm_0_i_1_r_0_t_1_cnt, S1MMEtore::msg_sm_0_i_1_r_0_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_1_r_0_t_2_busy, S1MMEtore::msg_sm_0_i_1_r_0_t_2_cnt, S1MMEtore::msg_sm_0_i_1_r_0_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_1_r_0_t_3_busy, S1MMEtore::msg_sm_0_i_1_r_0_t_3_cnt, S1MMEtore::msg_sm_0_i_1_r_0_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_1_r_0_t_4_busy, S1MMEtore::msg_sm_0_i_1_r_0_t_4_cnt, S1MMEtore::msg_sm_0_i_1_r_0_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_1_r_0_t_5_busy, S1MMEtore::msg_sm_0_i_1_r_0_t_5_cnt, S1MMEtore::msg_sm_0_i_1_r_0_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_1_r_0_t_6_busy, S1MMEtore::msg_sm_0_i_1_r_0_t_6_cnt, S1MMEtore::msg_sm_0_i_1_r_0_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_1_r_0_t_7_busy, S1MMEtore::msg_sm_0_i_1_r_0_t_7_cnt, S1MMEtore::msg_sm_0_i_1_r_0_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_1_r_0_t_8_busy, S1MMEtore::msg_sm_0_i_1_r_0_t_8_cnt, S1MMEtore::msg_sm_0_i_1_r_0_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_1_r_0_t_9_busy, S1MMEtore::msg_sm_0_i_1_r_0_t_9_cnt, S1MMEtore::msg_sm_0_i_1_r_0_t_9, pSctp);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_1_r_0_t_0_busy, S1MMEtore::msg_sm_1_i_1_r_0_t_0_cnt, S1MMEtore::msg_sm_1_i_1_r_0_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_1_r_0_t_1_busy, S1MMEtore::msg_sm_1_i_1_r_0_t_1_cnt, S1MMEtore::msg_sm_1_i_1_r_0_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_1_r_0_t_2_busy, S1MMEtore::msg_sm_1_i_1_r_0_t_2_cnt, S1MMEtore::msg_sm_1_i_1_r_0_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_1_r_0_t_3_busy, S1MMEtore::msg_sm_1_i_1_r_0_t_3_cnt, S1MMEtore::msg_sm_1_i_1_r_0_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_1_r_0_t_4_busy, S1MMEtore::msg_sm_1_i_1_r_0_t_4_cnt, S1MMEtore::msg_sm_1_i_1_r_0_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_1_r_0_t_5_busy, S1MMEtore::msg_sm_1_i_1_r_0_t_5_cnt, S1MMEtore::msg_sm_1_i_1_r_0_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_1_r_0_t_6_busy, S1MMEtore::msg_sm_1_i_1_r_0_t_6_cnt, S1MMEtore::msg_sm_1_i_1_r_0_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_1_r_0_t_7_busy, S1MMEtore::msg_sm_1_i_1_r_0_t_7_cnt, S1MMEtore::msg_sm_1_i_1_r_0_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_1_r_0_t_8_busy, S1MMEtore::msg_sm_1_i_1_r_0_t_8_cnt, S1MMEtore::msg_sm_1_i_1_r_0_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_1_r_0_t_9_busy, S1MMEtore::msg_sm_1_i_1_r_0_t_9_cnt, S1MMEtore::msg_sm_1_i_1_r_0_t_9, pSctp);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_1_r_0_t_0_busy, S1MMEtore::msg_sm_2_i_1_r_0_t_0_cnt, S1MMEtore::msg_sm_2_i_1_r_0_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_1_r_0_t_1_busy, S1MMEtore::msg_sm_2_i_1_r_0_t_1_cnt, S1MMEtore::msg_sm_2_i_1_r_0_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_1_r_0_t_2_busy, S1MMEtore::msg_sm_2_i_1_r_0_t_2_cnt, S1MMEtore::msg_sm_2_i_1_r_0_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_1_r_0_t_3_busy, S1MMEtore::msg_sm_2_i_1_r_0_t_3_cnt, S1MMEtore::msg_sm_2_i_1_r_0_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_1_r_0_t_4_busy, S1MMEtore::msg_sm_2_i_1_r_0_t_4_cnt, S1MMEtore::msg_sm_2_i_1_r_0_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_1_r_0_t_5_busy, S1MMEtore::msg_sm_2_i_1_r_0_t_5_cnt, S1MMEtore::msg_sm_2_i_1_r_0_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_1_r_0_t_6_busy, S1MMEtore::msg_sm_2_i_1_r_0_t_6_cnt, S1MMEtore::msg_sm_2_i_1_r_0_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_1_r_0_t_7_busy, S1MMEtore::msg_sm_2_i_1_r_0_t_7_cnt, S1MMEtore::msg_sm_2_i_1_r_0_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_1_r_0_t_8_busy, S1MMEtore::msg_sm_2_i_1_r_0_t_8_cnt, S1MMEtore::msg_sm_2_i_1_r_0_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_1_r_0_t_9_busy, S1MMEtore::msg_sm_2_i_1_r_0_t_9_cnt, S1MMEtore::msg_sm_2_i_1_r_0_t_9, pSctp);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_1_r_0_t_0_busy, S1MMEtore::msg_sm_3_i_1_r_0_t_0_cnt, S1MMEtore::msg_sm_3_i_1_r_0_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_1_r_0_t_1_busy, S1MMEtore::msg_sm_3_i_1_r_0_t_1_cnt, S1MMEtore::msg_sm_3_i_1_r_0_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_1_r_0_t_2_busy, S1MMEtore::msg_sm_3_i_1_r_0_t_2_cnt, S1MMEtore::msg_sm_3_i_1_r_0_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_1_r_0_t_3_busy, S1MMEtore::msg_sm_3_i_1_r_0_t_3_cnt, S1MMEtore::msg_sm_3_i_1_r_0_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_1_r_0_t_4_busy, S1MMEtore::msg_sm_3_i_1_r_0_t_4_cnt, S1MMEtore::msg_sm_3_i_1_r_0_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_1_r_0_t_5_busy, S1MMEtore::msg_sm_3_i_1_r_0_t_5_cnt, S1MMEtore::msg_sm_3_i_1_r_0_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_1_r_0_t_6_busy, S1MMEtore::msg_sm_3_i_1_r_0_t_6_cnt, S1MMEtore::msg_sm_3_i_1_r_0_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_1_r_0_t_7_busy, S1MMEtore::msg_sm_3_i_1_r_0_t_7_cnt, S1MMEtore::msg_sm_3_i_1_r_0_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_1_r_0_t_8_busy, S1MMEtore::msg_sm_3_i_1_r_0_t_8_cnt, S1MMEtore::msg_sm_3_i_1_r_0_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_1_r_0_t_9_busy, S1MMEtore::msg_sm_3_i_1_r_0_t_9_cnt, S1MMEtore::msg_sm_3_i_1_r_0_t_9, pSctp);
				break;
			}
			break;
	}
}

VOID SctpMessageBroker::pushToQueue_i_1_r_1(Sctp *pSctp, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_1_r_1_t_0_busy, S1MMEtore::msg_sm_0_i_1_r_1_t_0_cnt, S1MMEtore::msg_sm_0_i_1_r_1_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_1_r_1_t_1_busy, S1MMEtore::msg_sm_0_i_1_r_1_t_1_cnt, S1MMEtore::msg_sm_0_i_1_r_1_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_1_r_1_t_2_busy, S1MMEtore::msg_sm_0_i_1_r_1_t_2_cnt, S1MMEtore::msg_sm_0_i_1_r_1_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_1_r_1_t_3_busy, S1MMEtore::msg_sm_0_i_1_r_1_t_3_cnt, S1MMEtore::msg_sm_0_i_1_r_1_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_1_r_1_t_4_busy, S1MMEtore::msg_sm_0_i_1_r_1_t_4_cnt, S1MMEtore::msg_sm_0_i_1_r_1_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_1_r_1_t_5_busy, S1MMEtore::msg_sm_0_i_1_r_1_t_5_cnt, S1MMEtore::msg_sm_0_i_1_r_1_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_1_r_1_t_6_busy, S1MMEtore::msg_sm_0_i_1_r_1_t_6_cnt, S1MMEtore::msg_sm_0_i_1_r_1_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_1_r_1_t_7_busy, S1MMEtore::msg_sm_0_i_1_r_1_t_7_cnt, S1MMEtore::msg_sm_0_i_1_r_1_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_1_r_1_t_8_busy, S1MMEtore::msg_sm_0_i_1_r_1_t_8_cnt, S1MMEtore::msg_sm_0_i_1_r_1_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_1_r_1_t_9_busy, S1MMEtore::msg_sm_0_i_1_r_1_t_9_cnt, S1MMEtore::msg_sm_0_i_1_r_1_t_9, pSctp);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_1_r_1_t_0_busy, S1MMEtore::msg_sm_1_i_1_r_1_t_0_cnt, S1MMEtore::msg_sm_1_i_1_r_1_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_1_r_1_t_1_busy, S1MMEtore::msg_sm_1_i_1_r_1_t_1_cnt, S1MMEtore::msg_sm_1_i_1_r_1_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_1_r_1_t_2_busy, S1MMEtore::msg_sm_1_i_1_r_1_t_2_cnt, S1MMEtore::msg_sm_1_i_1_r_1_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_1_r_1_t_3_busy, S1MMEtore::msg_sm_1_i_1_r_1_t_3_cnt, S1MMEtore::msg_sm_1_i_1_r_1_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_1_r_1_t_4_busy, S1MMEtore::msg_sm_1_i_1_r_1_t_4_cnt, S1MMEtore::msg_sm_1_i_1_r_1_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_1_r_1_t_5_busy, S1MMEtore::msg_sm_1_i_1_r_1_t_5_cnt, S1MMEtore::msg_sm_1_i_1_r_1_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_1_r_1_t_6_busy, S1MMEtore::msg_sm_1_i_1_r_1_t_6_cnt, S1MMEtore::msg_sm_1_i_1_r_1_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_1_r_1_t_7_busy, S1MMEtore::msg_sm_1_i_1_r_1_t_7_cnt, S1MMEtore::msg_sm_1_i_1_r_1_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_1_r_1_t_8_busy, S1MMEtore::msg_sm_1_i_1_r_1_t_8_cnt, S1MMEtore::msg_sm_1_i_1_r_1_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_1_r_1_t_9_busy, S1MMEtore::msg_sm_1_i_1_r_1_t_9_cnt, S1MMEtore::msg_sm_1_i_1_r_1_t_9, pSctp);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_1_r_1_t_0_busy, S1MMEtore::msg_sm_2_i_1_r_1_t_0_cnt, S1MMEtore::msg_sm_2_i_1_r_1_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_1_r_1_t_1_busy, S1MMEtore::msg_sm_2_i_1_r_1_t_1_cnt, S1MMEtore::msg_sm_2_i_1_r_1_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_1_r_1_t_2_busy, S1MMEtore::msg_sm_2_i_1_r_1_t_2_cnt, S1MMEtore::msg_sm_2_i_1_r_1_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_1_r_1_t_3_busy, S1MMEtore::msg_sm_2_i_1_r_1_t_3_cnt, S1MMEtore::msg_sm_2_i_1_r_1_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_1_r_1_t_4_busy, S1MMEtore::msg_sm_2_i_1_r_1_t_4_cnt, S1MMEtore::msg_sm_2_i_1_r_1_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_1_r_1_t_5_busy, S1MMEtore::msg_sm_2_i_1_r_1_t_5_cnt, S1MMEtore::msg_sm_2_i_1_r_1_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_1_r_1_t_6_busy, S1MMEtore::msg_sm_2_i_1_r_1_t_6_cnt, S1MMEtore::msg_sm_2_i_1_r_1_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_1_r_1_t_7_busy, S1MMEtore::msg_sm_2_i_1_r_1_t_7_cnt, S1MMEtore::msg_sm_2_i_1_r_1_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_1_r_1_t_8_busy, S1MMEtore::msg_sm_2_i_1_r_1_t_8_cnt, S1MMEtore::msg_sm_2_i_1_r_1_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_1_r_1_t_9_busy, S1MMEtore::msg_sm_2_i_1_r_1_t_9_cnt, S1MMEtore::msg_sm_2_i_1_r_1_t_9, pSctp);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_1_r_1_t_0_busy, S1MMEtore::msg_sm_3_i_1_r_1_t_0_cnt, S1MMEtore::msg_sm_3_i_1_r_1_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_1_r_1_t_1_busy, S1MMEtore::msg_sm_3_i_1_r_1_t_1_cnt, S1MMEtore::msg_sm_3_i_1_r_1_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_1_r_1_t_2_busy, S1MMEtore::msg_sm_3_i_1_r_1_t_2_cnt, S1MMEtore::msg_sm_3_i_1_r_1_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_1_r_1_t_3_busy, S1MMEtore::msg_sm_3_i_1_r_1_t_3_cnt, S1MMEtore::msg_sm_3_i_1_r_1_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_1_r_1_t_4_busy, S1MMEtore::msg_sm_3_i_1_r_1_t_4_cnt, S1MMEtore::msg_sm_3_i_1_r_1_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_1_r_1_t_5_busy, S1MMEtore::msg_sm_3_i_1_r_1_t_5_cnt, S1MMEtore::msg_sm_3_i_1_r_1_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_1_r_1_t_6_busy, S1MMEtore::msg_sm_3_i_1_r_1_t_6_cnt, S1MMEtore::msg_sm_3_i_1_r_1_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_1_r_1_t_7_busy, S1MMEtore::msg_sm_3_i_1_r_1_t_7_cnt, S1MMEtore::msg_sm_3_i_1_r_1_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_1_r_1_t_8_busy, S1MMEtore::msg_sm_3_i_1_r_1_t_8_cnt, S1MMEtore::msg_sm_3_i_1_r_1_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_1_r_1_t_9_busy, S1MMEtore::msg_sm_3_i_1_r_1_t_9_cnt, S1MMEtore::msg_sm_3_i_1_r_1_t_9, pSctp);
				break;
			}
			break;
	}
}

VOID SctpMessageBroker::pushToQueue_i_1_r_2(Sctp *pSctp, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_1_r_2_t_0_busy, S1MMEtore::msg_sm_0_i_1_r_2_t_0_cnt, S1MMEtore::msg_sm_0_i_1_r_2_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_1_r_2_t_1_busy, S1MMEtore::msg_sm_0_i_1_r_2_t_1_cnt, S1MMEtore::msg_sm_0_i_1_r_2_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_1_r_2_t_2_busy, S1MMEtore::msg_sm_0_i_1_r_2_t_2_cnt, S1MMEtore::msg_sm_0_i_1_r_2_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_1_r_2_t_3_busy, S1MMEtore::msg_sm_0_i_1_r_2_t_3_cnt, S1MMEtore::msg_sm_0_i_1_r_2_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_1_r_2_t_4_busy, S1MMEtore::msg_sm_0_i_1_r_2_t_4_cnt, S1MMEtore::msg_sm_0_i_1_r_2_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_1_r_2_t_5_busy, S1MMEtore::msg_sm_0_i_1_r_2_t_5_cnt, S1MMEtore::msg_sm_0_i_1_r_2_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_1_r_2_t_6_busy, S1MMEtore::msg_sm_0_i_1_r_2_t_6_cnt, S1MMEtore::msg_sm_0_i_1_r_2_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_1_r_2_t_7_busy, S1MMEtore::msg_sm_0_i_1_r_2_t_7_cnt, S1MMEtore::msg_sm_0_i_1_r_2_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_1_r_2_t_8_busy, S1MMEtore::msg_sm_0_i_1_r_2_t_8_cnt, S1MMEtore::msg_sm_0_i_1_r_2_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_1_r_2_t_9_busy, S1MMEtore::msg_sm_0_i_1_r_2_t_9_cnt, S1MMEtore::msg_sm_0_i_1_r_2_t_9, pSctp);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_1_r_2_t_0_busy, S1MMEtore::msg_sm_1_i_1_r_2_t_0_cnt, S1MMEtore::msg_sm_1_i_1_r_2_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_1_r_2_t_1_busy, S1MMEtore::msg_sm_1_i_1_r_2_t_1_cnt, S1MMEtore::msg_sm_1_i_1_r_2_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_1_r_2_t_2_busy, S1MMEtore::msg_sm_1_i_1_r_2_t_2_cnt, S1MMEtore::msg_sm_1_i_1_r_2_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_1_r_2_t_3_busy, S1MMEtore::msg_sm_1_i_1_r_2_t_3_cnt, S1MMEtore::msg_sm_1_i_1_r_2_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_1_r_2_t_4_busy, S1MMEtore::msg_sm_1_i_1_r_2_t_4_cnt, S1MMEtore::msg_sm_1_i_1_r_2_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_1_r_2_t_5_busy, S1MMEtore::msg_sm_1_i_1_r_2_t_5_cnt, S1MMEtore::msg_sm_1_i_1_r_2_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_1_r_2_t_6_busy, S1MMEtore::msg_sm_1_i_1_r_2_t_6_cnt, S1MMEtore::msg_sm_1_i_1_r_2_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_1_r_2_t_7_busy, S1MMEtore::msg_sm_1_i_1_r_2_t_7_cnt, S1MMEtore::msg_sm_1_i_1_r_2_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_1_r_2_t_8_busy, S1MMEtore::msg_sm_1_i_1_r_2_t_8_cnt, S1MMEtore::msg_sm_1_i_1_r_2_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_1_r_2_t_9_busy, S1MMEtore::msg_sm_1_i_1_r_2_t_9_cnt, S1MMEtore::msg_sm_1_i_1_r_2_t_9, pSctp);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_1_r_2_t_0_busy, S1MMEtore::msg_sm_2_i_1_r_2_t_0_cnt, S1MMEtore::msg_sm_2_i_1_r_2_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_1_r_2_t_1_busy, S1MMEtore::msg_sm_2_i_1_r_2_t_1_cnt, S1MMEtore::msg_sm_2_i_1_r_2_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_1_r_2_t_2_busy, S1MMEtore::msg_sm_2_i_1_r_2_t_2_cnt, S1MMEtore::msg_sm_2_i_1_r_2_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_1_r_2_t_3_busy, S1MMEtore::msg_sm_2_i_1_r_2_t_3_cnt, S1MMEtore::msg_sm_2_i_1_r_2_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_1_r_2_t_4_busy, S1MMEtore::msg_sm_2_i_1_r_2_t_4_cnt, S1MMEtore::msg_sm_2_i_1_r_2_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_1_r_2_t_5_busy, S1MMEtore::msg_sm_2_i_1_r_2_t_5_cnt, S1MMEtore::msg_sm_2_i_1_r_2_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_1_r_2_t_6_busy, S1MMEtore::msg_sm_2_i_1_r_2_t_6_cnt, S1MMEtore::msg_sm_2_i_1_r_2_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_1_r_2_t_7_busy, S1MMEtore::msg_sm_2_i_1_r_2_t_7_cnt, S1MMEtore::msg_sm_2_i_1_r_2_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_1_r_2_t_8_busy, S1MMEtore::msg_sm_2_i_1_r_2_t_8_cnt, S1MMEtore::msg_sm_2_i_1_r_2_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_1_r_2_t_9_busy, S1MMEtore::msg_sm_2_i_1_r_2_t_9_cnt, S1MMEtore::msg_sm_2_i_1_r_2_t_9, pSctp);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_1_r_2_t_0_busy, S1MMEtore::msg_sm_3_i_1_r_2_t_0_cnt, S1MMEtore::msg_sm_3_i_1_r_2_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_1_r_2_t_1_busy, S1MMEtore::msg_sm_3_i_1_r_2_t_1_cnt, S1MMEtore::msg_sm_3_i_1_r_2_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_1_r_2_t_2_busy, S1MMEtore::msg_sm_3_i_1_r_2_t_2_cnt, S1MMEtore::msg_sm_3_i_1_r_2_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_1_r_2_t_3_busy, S1MMEtore::msg_sm_3_i_1_r_2_t_3_cnt, S1MMEtore::msg_sm_3_i_1_r_2_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_1_r_2_t_4_busy, S1MMEtore::msg_sm_3_i_1_r_2_t_4_cnt, S1MMEtore::msg_sm_3_i_1_r_2_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_1_r_2_t_5_busy, S1MMEtore::msg_sm_3_i_1_r_2_t_5_cnt, S1MMEtore::msg_sm_3_i_1_r_2_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_1_r_2_t_6_busy, S1MMEtore::msg_sm_3_i_1_r_2_t_6_cnt, S1MMEtore::msg_sm_3_i_1_r_2_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_1_r_2_t_7_busy, S1MMEtore::msg_sm_3_i_1_r_2_t_7_cnt, S1MMEtore::msg_sm_3_i_1_r_2_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_1_r_2_t_8_busy, S1MMEtore::msg_sm_3_i_1_r_2_t_8_cnt, S1MMEtore::msg_sm_3_i_1_r_2_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_1_r_2_t_9_busy, S1MMEtore::msg_sm_3_i_1_r_2_t_9_cnt, S1MMEtore::msg_sm_3_i_1_r_2_t_9, pSctp);
				break;
			}
			break;
	}
}

VOID SctpMessageBroker::pushToQueue_i_1_r_3(Sctp *pSctp, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_1_r_3_t_0_busy, S1MMEtore::msg_sm_0_i_1_r_3_t_0_cnt, S1MMEtore::msg_sm_0_i_1_r_3_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_1_r_3_t_1_busy, S1MMEtore::msg_sm_0_i_1_r_3_t_1_cnt, S1MMEtore::msg_sm_0_i_1_r_3_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_1_r_3_t_2_busy, S1MMEtore::msg_sm_0_i_1_r_3_t_2_cnt, S1MMEtore::msg_sm_0_i_1_r_3_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_1_r_3_t_3_busy, S1MMEtore::msg_sm_0_i_1_r_3_t_3_cnt, S1MMEtore::msg_sm_0_i_1_r_3_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_1_r_3_t_4_busy, S1MMEtore::msg_sm_0_i_1_r_3_t_4_cnt, S1MMEtore::msg_sm_0_i_1_r_3_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_1_r_3_t_5_busy, S1MMEtore::msg_sm_0_i_1_r_3_t_5_cnt, S1MMEtore::msg_sm_0_i_1_r_3_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_1_r_3_t_6_busy, S1MMEtore::msg_sm_0_i_1_r_3_t_6_cnt, S1MMEtore::msg_sm_0_i_1_r_3_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_1_r_3_t_7_busy, S1MMEtore::msg_sm_0_i_1_r_3_t_7_cnt, S1MMEtore::msg_sm_0_i_1_r_3_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_1_r_3_t_8_busy, S1MMEtore::msg_sm_0_i_1_r_3_t_8_cnt, S1MMEtore::msg_sm_0_i_1_r_3_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_1_r_3_t_9_busy, S1MMEtore::msg_sm_0_i_1_r_3_t_9_cnt, S1MMEtore::msg_sm_0_i_1_r_3_t_9, pSctp);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_1_r_3_t_0_busy, S1MMEtore::msg_sm_1_i_1_r_3_t_0_cnt, S1MMEtore::msg_sm_1_i_1_r_3_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_1_r_3_t_1_busy, S1MMEtore::msg_sm_1_i_1_r_3_t_1_cnt, S1MMEtore::msg_sm_1_i_1_r_3_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_1_r_3_t_2_busy, S1MMEtore::msg_sm_1_i_1_r_3_t_2_cnt, S1MMEtore::msg_sm_1_i_1_r_3_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_1_r_3_t_3_busy, S1MMEtore::msg_sm_1_i_1_r_3_t_3_cnt, S1MMEtore::msg_sm_1_i_1_r_3_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_1_r_3_t_4_busy, S1MMEtore::msg_sm_1_i_1_r_3_t_4_cnt, S1MMEtore::msg_sm_1_i_1_r_3_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_1_r_3_t_5_busy, S1MMEtore::msg_sm_1_i_1_r_3_t_5_cnt, S1MMEtore::msg_sm_1_i_1_r_3_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_1_r_3_t_6_busy, S1MMEtore::msg_sm_1_i_1_r_3_t_6_cnt, S1MMEtore::msg_sm_1_i_1_r_3_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_1_r_3_t_7_busy, S1MMEtore::msg_sm_1_i_1_r_3_t_7_cnt, S1MMEtore::msg_sm_1_i_1_r_3_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_1_r_3_t_8_busy, S1MMEtore::msg_sm_1_i_1_r_3_t_8_cnt, S1MMEtore::msg_sm_1_i_1_r_3_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_1_r_3_t_9_busy, S1MMEtore::msg_sm_1_i_1_r_3_t_9_cnt, S1MMEtore::msg_sm_1_i_1_r_3_t_9, pSctp);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_1_r_3_t_0_busy, S1MMEtore::msg_sm_2_i_1_r_3_t_0_cnt, S1MMEtore::msg_sm_2_i_1_r_3_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_1_r_3_t_1_busy, S1MMEtore::msg_sm_2_i_1_r_3_t_1_cnt, S1MMEtore::msg_sm_2_i_1_r_3_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_1_r_3_t_2_busy, S1MMEtore::msg_sm_2_i_1_r_3_t_2_cnt, S1MMEtore::msg_sm_2_i_1_r_3_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_1_r_3_t_3_busy, S1MMEtore::msg_sm_2_i_1_r_3_t_3_cnt, S1MMEtore::msg_sm_2_i_1_r_3_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_1_r_3_t_4_busy, S1MMEtore::msg_sm_2_i_1_r_3_t_4_cnt, S1MMEtore::msg_sm_2_i_1_r_3_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_1_r_3_t_5_busy, S1MMEtore::msg_sm_2_i_1_r_3_t_5_cnt, S1MMEtore::msg_sm_2_i_1_r_3_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_1_r_3_t_6_busy, S1MMEtore::msg_sm_2_i_1_r_3_t_6_cnt, S1MMEtore::msg_sm_2_i_1_r_3_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_1_r_3_t_7_busy, S1MMEtore::msg_sm_2_i_1_r_3_t_7_cnt, S1MMEtore::msg_sm_2_i_1_r_3_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_1_r_3_t_8_busy, S1MMEtore::msg_sm_2_i_1_r_3_t_8_cnt, S1MMEtore::msg_sm_2_i_1_r_3_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_1_r_3_t_9_busy, S1MMEtore::msg_sm_2_i_1_r_3_t_9_cnt, S1MMEtore::msg_sm_2_i_1_r_3_t_9, pSctp);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_1_r_3_t_0_busy, S1MMEtore::msg_sm_3_i_1_r_3_t_0_cnt, S1MMEtore::msg_sm_3_i_1_r_3_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_1_r_3_t_1_busy, S1MMEtore::msg_sm_3_i_1_r_3_t_1_cnt, S1MMEtore::msg_sm_3_i_1_r_3_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_1_r_3_t_2_busy, S1MMEtore::msg_sm_3_i_1_r_3_t_2_cnt, S1MMEtore::msg_sm_3_i_1_r_3_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_1_r_3_t_3_busy, S1MMEtore::msg_sm_3_i_1_r_3_t_3_cnt, S1MMEtore::msg_sm_3_i_1_r_3_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_1_r_3_t_4_busy, S1MMEtore::msg_sm_3_i_1_r_3_t_4_cnt, S1MMEtore::msg_sm_3_i_1_r_3_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_1_r_3_t_5_busy, S1MMEtore::msg_sm_3_i_1_r_3_t_5_cnt, S1MMEtore::msg_sm_3_i_1_r_3_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_1_r_3_t_6_busy, S1MMEtore::msg_sm_3_i_1_r_3_t_6_cnt, S1MMEtore::msg_sm_3_i_1_r_3_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_1_r_3_t_7_busy, S1MMEtore::msg_sm_3_i_1_r_3_t_7_cnt, S1MMEtore::msg_sm_3_i_1_r_3_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_1_r_3_t_8_busy, S1MMEtore::msg_sm_3_i_1_r_3_t_8_cnt, S1MMEtore::msg_sm_3_i_1_r_3_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_1_r_3_t_9_busy, S1MMEtore::msg_sm_3_i_1_r_3_t_9_cnt, S1MMEtore::msg_sm_3_i_1_r_3_t_9, pSctp);
				break;
			}
			break;
	}
}

VOID SctpMessageBroker::pushToQueue_i_1_r_4(Sctp *pSctp, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_1_r_4_t_0_busy, S1MMEtore::msg_sm_0_i_1_r_4_t_0_cnt, S1MMEtore::msg_sm_0_i_1_r_4_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_1_r_4_t_1_busy, S1MMEtore::msg_sm_0_i_1_r_4_t_1_cnt, S1MMEtore::msg_sm_0_i_1_r_4_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_1_r_4_t_2_busy, S1MMEtore::msg_sm_0_i_1_r_4_t_2_cnt, S1MMEtore::msg_sm_0_i_1_r_4_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_1_r_4_t_3_busy, S1MMEtore::msg_sm_0_i_1_r_4_t_3_cnt, S1MMEtore::msg_sm_0_i_1_r_4_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_1_r_4_t_4_busy, S1MMEtore::msg_sm_0_i_1_r_4_t_4_cnt, S1MMEtore::msg_sm_0_i_1_r_4_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_1_r_4_t_5_busy, S1MMEtore::msg_sm_0_i_1_r_4_t_5_cnt, S1MMEtore::msg_sm_0_i_1_r_4_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_1_r_4_t_6_busy, S1MMEtore::msg_sm_0_i_1_r_4_t_6_cnt, S1MMEtore::msg_sm_0_i_1_r_4_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_1_r_4_t_7_busy, S1MMEtore::msg_sm_0_i_1_r_4_t_7_cnt, S1MMEtore::msg_sm_0_i_1_r_4_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_1_r_4_t_8_busy, S1MMEtore::msg_sm_0_i_1_r_4_t_8_cnt, S1MMEtore::msg_sm_0_i_1_r_4_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_1_r_4_t_9_busy, S1MMEtore::msg_sm_0_i_1_r_4_t_9_cnt, S1MMEtore::msg_sm_0_i_1_r_4_t_9, pSctp);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_1_r_4_t_0_busy, S1MMEtore::msg_sm_1_i_1_r_4_t_0_cnt, S1MMEtore::msg_sm_1_i_1_r_4_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_1_r_4_t_1_busy, S1MMEtore::msg_sm_1_i_1_r_4_t_1_cnt, S1MMEtore::msg_sm_1_i_1_r_4_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_1_r_4_t_2_busy, S1MMEtore::msg_sm_1_i_1_r_4_t_2_cnt, S1MMEtore::msg_sm_1_i_1_r_4_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_1_r_4_t_3_busy, S1MMEtore::msg_sm_1_i_1_r_4_t_3_cnt, S1MMEtore::msg_sm_1_i_1_r_4_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_1_r_4_t_4_busy, S1MMEtore::msg_sm_1_i_1_r_4_t_4_cnt, S1MMEtore::msg_sm_1_i_1_r_4_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_1_r_4_t_5_busy, S1MMEtore::msg_sm_1_i_1_r_4_t_5_cnt, S1MMEtore::msg_sm_1_i_1_r_4_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_1_r_4_t_6_busy, S1MMEtore::msg_sm_1_i_1_r_4_t_6_cnt, S1MMEtore::msg_sm_1_i_1_r_4_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_1_r_4_t_7_busy, S1MMEtore::msg_sm_1_i_1_r_4_t_7_cnt, S1MMEtore::msg_sm_1_i_1_r_4_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_1_r_4_t_8_busy, S1MMEtore::msg_sm_1_i_1_r_4_t_8_cnt, S1MMEtore::msg_sm_1_i_1_r_4_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_1_r_4_t_9_busy, S1MMEtore::msg_sm_1_i_1_r_4_t_9_cnt, S1MMEtore::msg_sm_1_i_1_r_4_t_9, pSctp);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_1_r_4_t_0_busy, S1MMEtore::msg_sm_2_i_1_r_4_t_0_cnt, S1MMEtore::msg_sm_2_i_1_r_4_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_1_r_4_t_1_busy, S1MMEtore::msg_sm_2_i_1_r_4_t_1_cnt, S1MMEtore::msg_sm_2_i_1_r_4_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_1_r_4_t_2_busy, S1MMEtore::msg_sm_2_i_1_r_4_t_2_cnt, S1MMEtore::msg_sm_2_i_1_r_4_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_1_r_4_t_3_busy, S1MMEtore::msg_sm_2_i_1_r_4_t_3_cnt, S1MMEtore::msg_sm_2_i_1_r_4_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_1_r_4_t_4_busy, S1MMEtore::msg_sm_2_i_1_r_4_t_4_cnt, S1MMEtore::msg_sm_2_i_1_r_4_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_1_r_4_t_5_busy, S1MMEtore::msg_sm_2_i_1_r_4_t_5_cnt, S1MMEtore::msg_sm_2_i_1_r_4_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_1_r_4_t_6_busy, S1MMEtore::msg_sm_2_i_1_r_4_t_6_cnt, S1MMEtore::msg_sm_2_i_1_r_4_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_1_r_4_t_7_busy, S1MMEtore::msg_sm_2_i_1_r_4_t_7_cnt, S1MMEtore::msg_sm_2_i_1_r_4_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_1_r_4_t_8_busy, S1MMEtore::msg_sm_2_i_1_r_4_t_8_cnt, S1MMEtore::msg_sm_2_i_1_r_4_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_1_r_4_t_9_busy, S1MMEtore::msg_sm_2_i_1_r_4_t_9_cnt, S1MMEtore::msg_sm_2_i_1_r_4_t_9, pSctp);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_1_r_4_t_0_busy, S1MMEtore::msg_sm_3_i_1_r_4_t_0_cnt, S1MMEtore::msg_sm_3_i_1_r_4_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_1_r_4_t_1_busy, S1MMEtore::msg_sm_3_i_1_r_4_t_1_cnt, S1MMEtore::msg_sm_3_i_1_r_4_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_1_r_4_t_2_busy, S1MMEtore::msg_sm_3_i_1_r_4_t_2_cnt, S1MMEtore::msg_sm_3_i_1_r_4_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_1_r_4_t_3_busy, S1MMEtore::msg_sm_3_i_1_r_4_t_3_cnt, S1MMEtore::msg_sm_3_i_1_r_4_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_1_r_4_t_4_busy, S1MMEtore::msg_sm_3_i_1_r_4_t_4_cnt, S1MMEtore::msg_sm_3_i_1_r_4_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_1_r_4_t_5_busy, S1MMEtore::msg_sm_3_i_1_r_4_t_5_cnt, S1MMEtore::msg_sm_3_i_1_r_4_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_1_r_4_t_6_busy, S1MMEtore::msg_sm_3_i_1_r_4_t_6_cnt, S1MMEtore::msg_sm_3_i_1_r_4_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_1_r_4_t_7_busy, S1MMEtore::msg_sm_3_i_1_r_4_t_7_cnt, S1MMEtore::msg_sm_3_i_1_r_4_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_1_r_4_t_8_busy, S1MMEtore::msg_sm_3_i_1_r_4_t_8_cnt, S1MMEtore::msg_sm_3_i_1_r_4_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_1_r_4_t_9_busy, S1MMEtore::msg_sm_3_i_1_r_4_t_9_cnt, S1MMEtore::msg_sm_3_i_1_r_4_t_9, pSctp);
				break;
			}
			break;
	}
}

VOID SctpMessageBroker::pushToQueue_i_1_r_5(Sctp *pSctp, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_1_r_5_t_0_busy, S1MMEtore::msg_sm_0_i_1_r_5_t_0_cnt, S1MMEtore::msg_sm_0_i_1_r_5_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_1_r_5_t_1_busy, S1MMEtore::msg_sm_0_i_1_r_5_t_1_cnt, S1MMEtore::msg_sm_0_i_1_r_5_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_1_r_5_t_2_busy, S1MMEtore::msg_sm_0_i_1_r_5_t_2_cnt, S1MMEtore::msg_sm_0_i_1_r_5_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_1_r_5_t_3_busy, S1MMEtore::msg_sm_0_i_1_r_5_t_3_cnt, S1MMEtore::msg_sm_0_i_1_r_5_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_1_r_5_t_4_busy, S1MMEtore::msg_sm_0_i_1_r_5_t_4_cnt, S1MMEtore::msg_sm_0_i_1_r_5_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_1_r_5_t_5_busy, S1MMEtore::msg_sm_0_i_1_r_5_t_5_cnt, S1MMEtore::msg_sm_0_i_1_r_5_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_1_r_5_t_6_busy, S1MMEtore::msg_sm_0_i_1_r_5_t_6_cnt, S1MMEtore::msg_sm_0_i_1_r_5_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_1_r_5_t_7_busy, S1MMEtore::msg_sm_0_i_1_r_5_t_7_cnt, S1MMEtore::msg_sm_0_i_1_r_5_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_1_r_5_t_8_busy, S1MMEtore::msg_sm_0_i_1_r_5_t_8_cnt, S1MMEtore::msg_sm_0_i_1_r_5_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_1_r_5_t_9_busy, S1MMEtore::msg_sm_0_i_1_r_5_t_9_cnt, S1MMEtore::msg_sm_0_i_1_r_5_t_9, pSctp);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_1_r_5_t_0_busy, S1MMEtore::msg_sm_1_i_1_r_5_t_0_cnt, S1MMEtore::msg_sm_1_i_1_r_5_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_1_r_5_t_1_busy, S1MMEtore::msg_sm_1_i_1_r_5_t_1_cnt, S1MMEtore::msg_sm_1_i_1_r_5_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_1_r_5_t_2_busy, S1MMEtore::msg_sm_1_i_1_r_5_t_2_cnt, S1MMEtore::msg_sm_1_i_1_r_5_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_1_r_5_t_3_busy, S1MMEtore::msg_sm_1_i_1_r_5_t_3_cnt, S1MMEtore::msg_sm_1_i_1_r_5_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_1_r_5_t_4_busy, S1MMEtore::msg_sm_1_i_1_r_5_t_4_cnt, S1MMEtore::msg_sm_1_i_1_r_5_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_1_r_5_t_5_busy, S1MMEtore::msg_sm_1_i_1_r_5_t_5_cnt, S1MMEtore::msg_sm_1_i_1_r_5_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_1_r_5_t_6_busy, S1MMEtore::msg_sm_1_i_1_r_5_t_6_cnt, S1MMEtore::msg_sm_1_i_1_r_5_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_1_r_5_t_7_busy, S1MMEtore::msg_sm_1_i_1_r_5_t_7_cnt, S1MMEtore::msg_sm_1_i_1_r_5_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_1_r_5_t_8_busy, S1MMEtore::msg_sm_1_i_1_r_5_t_8_cnt, S1MMEtore::msg_sm_1_i_1_r_5_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_1_r_5_t_9_busy, S1MMEtore::msg_sm_1_i_1_r_5_t_9_cnt, S1MMEtore::msg_sm_1_i_1_r_5_t_9, pSctp);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_1_r_5_t_0_busy, S1MMEtore::msg_sm_2_i_1_r_5_t_0_cnt, S1MMEtore::msg_sm_2_i_1_r_5_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_1_r_5_t_1_busy, S1MMEtore::msg_sm_2_i_1_r_5_t_1_cnt, S1MMEtore::msg_sm_2_i_1_r_5_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_1_r_5_t_2_busy, S1MMEtore::msg_sm_2_i_1_r_5_t_2_cnt, S1MMEtore::msg_sm_2_i_1_r_5_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_1_r_5_t_3_busy, S1MMEtore::msg_sm_2_i_1_r_5_t_3_cnt, S1MMEtore::msg_sm_2_i_1_r_5_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_1_r_5_t_4_busy, S1MMEtore::msg_sm_2_i_1_r_5_t_4_cnt, S1MMEtore::msg_sm_2_i_1_r_5_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_1_r_5_t_5_busy, S1MMEtore::msg_sm_2_i_1_r_5_t_5_cnt, S1MMEtore::msg_sm_2_i_1_r_5_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_1_r_5_t_6_busy, S1MMEtore::msg_sm_2_i_1_r_5_t_6_cnt, S1MMEtore::msg_sm_2_i_1_r_5_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_1_r_5_t_7_busy, S1MMEtore::msg_sm_2_i_1_r_5_t_7_cnt, S1MMEtore::msg_sm_2_i_1_r_5_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_1_r_5_t_8_busy, S1MMEtore::msg_sm_2_i_1_r_5_t_8_cnt, S1MMEtore::msg_sm_2_i_1_r_5_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_1_r_5_t_9_busy, S1MMEtore::msg_sm_2_i_1_r_5_t_9_cnt, S1MMEtore::msg_sm_2_i_1_r_5_t_9, pSctp);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_1_r_5_t_0_busy, S1MMEtore::msg_sm_3_i_1_r_5_t_0_cnt, S1MMEtore::msg_sm_3_i_1_r_5_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_1_r_5_t_1_busy, S1MMEtore::msg_sm_3_i_1_r_5_t_1_cnt, S1MMEtore::msg_sm_3_i_1_r_5_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_1_r_5_t_2_busy, S1MMEtore::msg_sm_3_i_1_r_5_t_2_cnt, S1MMEtore::msg_sm_3_i_1_r_5_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_1_r_5_t_3_busy, S1MMEtore::msg_sm_3_i_1_r_5_t_3_cnt, S1MMEtore::msg_sm_3_i_1_r_5_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_1_r_5_t_4_busy, S1MMEtore::msg_sm_3_i_1_r_5_t_4_cnt, S1MMEtore::msg_sm_3_i_1_r_5_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_1_r_5_t_5_busy, S1MMEtore::msg_sm_3_i_1_r_5_t_5_cnt, S1MMEtore::msg_sm_3_i_1_r_5_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_1_r_5_t_6_busy, S1MMEtore::msg_sm_3_i_1_r_5_t_6_cnt, S1MMEtore::msg_sm_3_i_1_r_5_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_1_r_5_t_7_busy, S1MMEtore::msg_sm_3_i_1_r_5_t_7_cnt, S1MMEtore::msg_sm_3_i_1_r_5_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_1_r_5_t_8_busy, S1MMEtore::msg_sm_3_i_1_r_5_t_8_cnt, S1MMEtore::msg_sm_3_i_1_r_5_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_1_r_5_t_9_busy, S1MMEtore::msg_sm_3_i_1_r_5_t_9_cnt, S1MMEtore::msg_sm_3_i_1_r_5_t_9, pSctp);
				break;
			}
			break;
	}
}

VOID SctpMessageBroker::pushToQueue_i_1_r_6(Sctp *pSctp, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_1_r_6_t_0_busy, S1MMEtore::msg_sm_0_i_1_r_6_t_0_cnt, S1MMEtore::msg_sm_0_i_1_r_6_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_1_r_6_t_1_busy, S1MMEtore::msg_sm_0_i_1_r_6_t_1_cnt, S1MMEtore::msg_sm_0_i_1_r_6_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_1_r_6_t_2_busy, S1MMEtore::msg_sm_0_i_1_r_6_t_2_cnt, S1MMEtore::msg_sm_0_i_1_r_6_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_1_r_6_t_3_busy, S1MMEtore::msg_sm_0_i_1_r_6_t_3_cnt, S1MMEtore::msg_sm_0_i_1_r_6_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_1_r_6_t_4_busy, S1MMEtore::msg_sm_0_i_1_r_6_t_4_cnt, S1MMEtore::msg_sm_0_i_1_r_6_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_1_r_6_t_5_busy, S1MMEtore::msg_sm_0_i_1_r_6_t_5_cnt, S1MMEtore::msg_sm_0_i_1_r_6_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_1_r_6_t_6_busy, S1MMEtore::msg_sm_0_i_1_r_6_t_6_cnt, S1MMEtore::msg_sm_0_i_1_r_6_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_1_r_6_t_7_busy, S1MMEtore::msg_sm_0_i_1_r_6_t_7_cnt, S1MMEtore::msg_sm_0_i_1_r_6_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_1_r_6_t_8_busy, S1MMEtore::msg_sm_0_i_1_r_6_t_8_cnt, S1MMEtore::msg_sm_0_i_1_r_6_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_1_r_6_t_9_busy, S1MMEtore::msg_sm_0_i_1_r_6_t_9_cnt, S1MMEtore::msg_sm_0_i_1_r_6_t_9, pSctp);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_1_r_6_t_0_busy, S1MMEtore::msg_sm_1_i_1_r_6_t_0_cnt, S1MMEtore::msg_sm_1_i_1_r_6_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_1_r_6_t_1_busy, S1MMEtore::msg_sm_1_i_1_r_6_t_1_cnt, S1MMEtore::msg_sm_1_i_1_r_6_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_1_r_6_t_2_busy, S1MMEtore::msg_sm_1_i_1_r_6_t_2_cnt, S1MMEtore::msg_sm_1_i_1_r_6_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_1_r_6_t_3_busy, S1MMEtore::msg_sm_1_i_1_r_6_t_3_cnt, S1MMEtore::msg_sm_1_i_1_r_6_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_1_r_6_t_4_busy, S1MMEtore::msg_sm_1_i_1_r_6_t_4_cnt, S1MMEtore::msg_sm_1_i_1_r_6_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_1_r_6_t_5_busy, S1MMEtore::msg_sm_1_i_1_r_6_t_5_cnt, S1MMEtore::msg_sm_1_i_1_r_6_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_1_r_6_t_6_busy, S1MMEtore::msg_sm_1_i_1_r_6_t_6_cnt, S1MMEtore::msg_sm_1_i_1_r_6_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_1_r_6_t_7_busy, S1MMEtore::msg_sm_1_i_1_r_6_t_7_cnt, S1MMEtore::msg_sm_1_i_1_r_6_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_1_r_6_t_8_busy, S1MMEtore::msg_sm_1_i_1_r_6_t_8_cnt, S1MMEtore::msg_sm_1_i_1_r_6_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_1_r_6_t_9_busy, S1MMEtore::msg_sm_1_i_1_r_6_t_9_cnt, S1MMEtore::msg_sm_1_i_1_r_6_t_9, pSctp);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_1_r_6_t_0_busy, S1MMEtore::msg_sm_2_i_1_r_6_t_0_cnt, S1MMEtore::msg_sm_2_i_1_r_6_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_1_r_6_t_1_busy, S1MMEtore::msg_sm_2_i_1_r_6_t_1_cnt, S1MMEtore::msg_sm_2_i_1_r_6_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_1_r_6_t_2_busy, S1MMEtore::msg_sm_2_i_1_r_6_t_2_cnt, S1MMEtore::msg_sm_2_i_1_r_6_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_1_r_6_t_3_busy, S1MMEtore::msg_sm_2_i_1_r_6_t_3_cnt, S1MMEtore::msg_sm_2_i_1_r_6_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_1_r_6_t_4_busy, S1MMEtore::msg_sm_2_i_1_r_6_t_4_cnt, S1MMEtore::msg_sm_2_i_1_r_6_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_1_r_6_t_5_busy, S1MMEtore::msg_sm_2_i_1_r_6_t_5_cnt, S1MMEtore::msg_sm_2_i_1_r_6_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_1_r_6_t_6_busy, S1MMEtore::msg_sm_2_i_1_r_6_t_6_cnt, S1MMEtore::msg_sm_2_i_1_r_6_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_1_r_6_t_7_busy, S1MMEtore::msg_sm_2_i_1_r_6_t_7_cnt, S1MMEtore::msg_sm_2_i_1_r_6_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_1_r_6_t_8_busy, S1MMEtore::msg_sm_2_i_1_r_6_t_8_cnt, S1MMEtore::msg_sm_2_i_1_r_6_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_1_r_6_t_9_busy, S1MMEtore::msg_sm_2_i_1_r_6_t_9_cnt, S1MMEtore::msg_sm_2_i_1_r_6_t_9, pSctp);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_1_r_6_t_0_busy, S1MMEtore::msg_sm_3_i_1_r_6_t_0_cnt, S1MMEtore::msg_sm_3_i_1_r_6_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_1_r_6_t_1_busy, S1MMEtore::msg_sm_3_i_1_r_6_t_1_cnt, S1MMEtore::msg_sm_3_i_1_r_6_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_1_r_6_t_2_busy, S1MMEtore::msg_sm_3_i_1_r_6_t_2_cnt, S1MMEtore::msg_sm_3_i_1_r_6_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_1_r_6_t_3_busy, S1MMEtore::msg_sm_3_i_1_r_6_t_3_cnt, S1MMEtore::msg_sm_3_i_1_r_6_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_1_r_6_t_4_busy, S1MMEtore::msg_sm_3_i_1_r_6_t_4_cnt, S1MMEtore::msg_sm_3_i_1_r_6_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_1_r_6_t_5_busy, S1MMEtore::msg_sm_3_i_1_r_6_t_5_cnt, S1MMEtore::msg_sm_3_i_1_r_6_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_1_r_6_t_6_busy, S1MMEtore::msg_sm_3_i_1_r_6_t_6_cnt, S1MMEtore::msg_sm_3_i_1_r_6_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_1_r_6_t_7_busy, S1MMEtore::msg_sm_3_i_1_r_6_t_7_cnt, S1MMEtore::msg_sm_3_i_1_r_6_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_1_r_6_t_8_busy, S1MMEtore::msg_sm_3_i_1_r_6_t_8_cnt, S1MMEtore::msg_sm_3_i_1_r_6_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_1_r_6_t_9_busy, S1MMEtore::msg_sm_3_i_1_r_6_t_9_cnt, S1MMEtore::msg_sm_3_i_1_r_6_t_9, pSctp);
				break;
			}
			break;
	}
}

VOID SctpMessageBroker::pushToQueue_i_1_r_7(Sctp *pSctp, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_1_r_7_t_0_busy, S1MMEtore::msg_sm_0_i_1_r_7_t_0_cnt, S1MMEtore::msg_sm_0_i_1_r_7_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_1_r_7_t_1_busy, S1MMEtore::msg_sm_0_i_1_r_7_t_1_cnt, S1MMEtore::msg_sm_0_i_1_r_7_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_1_r_7_t_2_busy, S1MMEtore::msg_sm_0_i_1_r_7_t_2_cnt, S1MMEtore::msg_sm_0_i_1_r_7_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_1_r_7_t_3_busy, S1MMEtore::msg_sm_0_i_1_r_7_t_3_cnt, S1MMEtore::msg_sm_0_i_1_r_7_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_1_r_7_t_4_busy, S1MMEtore::msg_sm_0_i_1_r_7_t_4_cnt, S1MMEtore::msg_sm_0_i_1_r_7_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_1_r_7_t_5_busy, S1MMEtore::msg_sm_0_i_1_r_7_t_5_cnt, S1MMEtore::msg_sm_0_i_1_r_7_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_1_r_7_t_6_busy, S1MMEtore::msg_sm_0_i_1_r_7_t_6_cnt, S1MMEtore::msg_sm_0_i_1_r_7_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_1_r_7_t_7_busy, S1MMEtore::msg_sm_0_i_1_r_7_t_7_cnt, S1MMEtore::msg_sm_0_i_1_r_7_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_1_r_7_t_8_busy, S1MMEtore::msg_sm_0_i_1_r_7_t_8_cnt, S1MMEtore::msg_sm_0_i_1_r_7_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_1_r_7_t_9_busy, S1MMEtore::msg_sm_0_i_1_r_7_t_9_cnt, S1MMEtore::msg_sm_0_i_1_r_7_t_9, pSctp);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_1_r_7_t_0_busy, S1MMEtore::msg_sm_1_i_1_r_7_t_0_cnt, S1MMEtore::msg_sm_1_i_1_r_7_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_1_r_7_t_1_busy, S1MMEtore::msg_sm_1_i_1_r_7_t_1_cnt, S1MMEtore::msg_sm_1_i_1_r_7_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_1_r_7_t_2_busy, S1MMEtore::msg_sm_1_i_1_r_7_t_2_cnt, S1MMEtore::msg_sm_1_i_1_r_7_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_1_r_7_t_3_busy, S1MMEtore::msg_sm_1_i_1_r_7_t_3_cnt, S1MMEtore::msg_sm_1_i_1_r_7_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_1_r_7_t_4_busy, S1MMEtore::msg_sm_1_i_1_r_7_t_4_cnt, S1MMEtore::msg_sm_1_i_1_r_7_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_1_r_7_t_5_busy, S1MMEtore::msg_sm_1_i_1_r_7_t_5_cnt, S1MMEtore::msg_sm_1_i_1_r_7_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_1_r_7_t_6_busy, S1MMEtore::msg_sm_1_i_1_r_7_t_6_cnt, S1MMEtore::msg_sm_1_i_1_r_7_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_1_r_7_t_7_busy, S1MMEtore::msg_sm_1_i_1_r_7_t_7_cnt, S1MMEtore::msg_sm_1_i_1_r_7_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_1_r_7_t_8_busy, S1MMEtore::msg_sm_1_i_1_r_7_t_8_cnt, S1MMEtore::msg_sm_1_i_1_r_7_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_1_r_7_t_9_busy, S1MMEtore::msg_sm_1_i_1_r_7_t_9_cnt, S1MMEtore::msg_sm_1_i_1_r_7_t_9, pSctp);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_1_r_7_t_0_busy, S1MMEtore::msg_sm_2_i_1_r_7_t_0_cnt, S1MMEtore::msg_sm_2_i_1_r_7_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_1_r_7_t_1_busy, S1MMEtore::msg_sm_2_i_1_r_7_t_1_cnt, S1MMEtore::msg_sm_2_i_1_r_7_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_1_r_7_t_2_busy, S1MMEtore::msg_sm_2_i_1_r_7_t_2_cnt, S1MMEtore::msg_sm_2_i_1_r_7_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_1_r_7_t_3_busy, S1MMEtore::msg_sm_2_i_1_r_7_t_3_cnt, S1MMEtore::msg_sm_2_i_1_r_7_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_1_r_7_t_4_busy, S1MMEtore::msg_sm_2_i_1_r_7_t_4_cnt, S1MMEtore::msg_sm_2_i_1_r_7_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_1_r_7_t_5_busy, S1MMEtore::msg_sm_2_i_1_r_7_t_5_cnt, S1MMEtore::msg_sm_2_i_1_r_7_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_1_r_7_t_6_busy, S1MMEtore::msg_sm_2_i_1_r_7_t_6_cnt, S1MMEtore::msg_sm_2_i_1_r_7_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_1_r_7_t_7_busy, S1MMEtore::msg_sm_2_i_1_r_7_t_7_cnt, S1MMEtore::msg_sm_2_i_1_r_7_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_1_r_7_t_8_busy, S1MMEtore::msg_sm_2_i_1_r_7_t_8_cnt, S1MMEtore::msg_sm_2_i_1_r_7_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_1_r_7_t_9_busy, S1MMEtore::msg_sm_2_i_1_r_7_t_9_cnt, S1MMEtore::msg_sm_2_i_1_r_7_t_9, pSctp);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_1_r_7_t_0_busy, S1MMEtore::msg_sm_3_i_1_r_7_t_0_cnt, S1MMEtore::msg_sm_3_i_1_r_7_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_1_r_7_t_1_busy, S1MMEtore::msg_sm_3_i_1_r_7_t_1_cnt, S1MMEtore::msg_sm_3_i_1_r_7_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_1_r_7_t_2_busy, S1MMEtore::msg_sm_3_i_1_r_7_t_2_cnt, S1MMEtore::msg_sm_3_i_1_r_7_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_1_r_7_t_3_busy, S1MMEtore::msg_sm_3_i_1_r_7_t_3_cnt, S1MMEtore::msg_sm_3_i_1_r_7_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_1_r_7_t_4_busy, S1MMEtore::msg_sm_3_i_1_r_7_t_4_cnt, S1MMEtore::msg_sm_3_i_1_r_7_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_1_r_7_t_5_busy, S1MMEtore::msg_sm_3_i_1_r_7_t_5_cnt, S1MMEtore::msg_sm_3_i_1_r_7_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_1_r_7_t_6_busy, S1MMEtore::msg_sm_3_i_1_r_7_t_6_cnt, S1MMEtore::msg_sm_3_i_1_r_7_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_1_r_7_t_7_busy, S1MMEtore::msg_sm_3_i_1_r_7_t_7_cnt, S1MMEtore::msg_sm_3_i_1_r_7_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_1_r_7_t_8_busy, S1MMEtore::msg_sm_3_i_1_r_7_t_8_cnt, S1MMEtore::msg_sm_3_i_1_r_7_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_1_r_7_t_9_busy, S1MMEtore::msg_sm_3_i_1_r_7_t_9_cnt, S1MMEtore::msg_sm_3_i_1_r_7_t_9, pSctp);
				break;
			}
			break;
	}
}


VOID SctpMessageBroker::pushToQueue_i_2_r_0(Sctp *pSctp, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_2_r_0_t_0_busy, S1MMEtore::msg_sm_0_i_2_r_0_t_0_cnt, S1MMEtore::msg_sm_0_i_2_r_0_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_2_r_0_t_1_busy, S1MMEtore::msg_sm_0_i_2_r_0_t_1_cnt, S1MMEtore::msg_sm_0_i_2_r_0_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_2_r_0_t_2_busy, S1MMEtore::msg_sm_0_i_2_r_0_t_2_cnt, S1MMEtore::msg_sm_0_i_2_r_0_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_2_r_0_t_3_busy, S1MMEtore::msg_sm_0_i_2_r_0_t_3_cnt, S1MMEtore::msg_sm_0_i_2_r_0_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_2_r_0_t_4_busy, S1MMEtore::msg_sm_0_i_2_r_0_t_4_cnt, S1MMEtore::msg_sm_0_i_2_r_0_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_2_r_0_t_5_busy, S1MMEtore::msg_sm_0_i_2_r_0_t_5_cnt, S1MMEtore::msg_sm_0_i_2_r_0_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_2_r_0_t_6_busy, S1MMEtore::msg_sm_0_i_2_r_0_t_6_cnt, S1MMEtore::msg_sm_0_i_2_r_0_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_2_r_0_t_7_busy, S1MMEtore::msg_sm_0_i_2_r_0_t_7_cnt, S1MMEtore::msg_sm_0_i_2_r_0_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_2_r_0_t_8_busy, S1MMEtore::msg_sm_0_i_2_r_0_t_8_cnt, S1MMEtore::msg_sm_0_i_2_r_0_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_2_r_0_t_9_busy, S1MMEtore::msg_sm_0_i_2_r_0_t_9_cnt, S1MMEtore::msg_sm_0_i_2_r_0_t_9, pSctp);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_2_r_0_t_0_busy, S1MMEtore::msg_sm_1_i_2_r_0_t_0_cnt, S1MMEtore::msg_sm_1_i_2_r_0_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_2_r_0_t_1_busy, S1MMEtore::msg_sm_1_i_2_r_0_t_1_cnt, S1MMEtore::msg_sm_1_i_2_r_0_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_2_r_0_t_2_busy, S1MMEtore::msg_sm_1_i_2_r_0_t_2_cnt, S1MMEtore::msg_sm_1_i_2_r_0_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_2_r_0_t_3_busy, S1MMEtore::msg_sm_1_i_2_r_0_t_3_cnt, S1MMEtore::msg_sm_1_i_2_r_0_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_2_r_0_t_4_busy, S1MMEtore::msg_sm_1_i_2_r_0_t_4_cnt, S1MMEtore::msg_sm_1_i_2_r_0_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_2_r_0_t_5_busy, S1MMEtore::msg_sm_1_i_2_r_0_t_5_cnt, S1MMEtore::msg_sm_1_i_2_r_0_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_2_r_0_t_6_busy, S1MMEtore::msg_sm_1_i_2_r_0_t_6_cnt, S1MMEtore::msg_sm_1_i_2_r_0_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_2_r_0_t_7_busy, S1MMEtore::msg_sm_1_i_2_r_0_t_7_cnt, S1MMEtore::msg_sm_1_i_2_r_0_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_2_r_0_t_8_busy, S1MMEtore::msg_sm_1_i_2_r_0_t_8_cnt, S1MMEtore::msg_sm_1_i_2_r_0_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_2_r_0_t_9_busy, S1MMEtore::msg_sm_1_i_2_r_0_t_9_cnt, S1MMEtore::msg_sm_1_i_2_r_0_t_9, pSctp);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_2_r_0_t_0_busy, S1MMEtore::msg_sm_2_i_2_r_0_t_0_cnt, S1MMEtore::msg_sm_2_i_2_r_0_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_2_r_0_t_1_busy, S1MMEtore::msg_sm_2_i_2_r_0_t_1_cnt, S1MMEtore::msg_sm_2_i_2_r_0_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_2_r_0_t_2_busy, S1MMEtore::msg_sm_2_i_2_r_0_t_2_cnt, S1MMEtore::msg_sm_2_i_2_r_0_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_2_r_0_t_3_busy, S1MMEtore::msg_sm_2_i_2_r_0_t_3_cnt, S1MMEtore::msg_sm_2_i_2_r_0_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_2_r_0_t_4_busy, S1MMEtore::msg_sm_2_i_2_r_0_t_4_cnt, S1MMEtore::msg_sm_2_i_2_r_0_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_2_r_0_t_5_busy, S1MMEtore::msg_sm_2_i_2_r_0_t_5_cnt, S1MMEtore::msg_sm_2_i_2_r_0_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_2_r_0_t_6_busy, S1MMEtore::msg_sm_2_i_2_r_0_t_6_cnt, S1MMEtore::msg_sm_2_i_2_r_0_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_2_r_0_t_7_busy, S1MMEtore::msg_sm_2_i_2_r_0_t_7_cnt, S1MMEtore::msg_sm_2_i_2_r_0_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_2_r_0_t_8_busy, S1MMEtore::msg_sm_2_i_2_r_0_t_8_cnt, S1MMEtore::msg_sm_2_i_2_r_0_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_2_r_0_t_9_busy, S1MMEtore::msg_sm_2_i_2_r_0_t_9_cnt, S1MMEtore::msg_sm_2_i_2_r_0_t_9, pSctp);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_2_r_0_t_0_busy, S1MMEtore::msg_sm_3_i_2_r_0_t_0_cnt, S1MMEtore::msg_sm_3_i_2_r_0_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_2_r_0_t_1_busy, S1MMEtore::msg_sm_3_i_2_r_0_t_1_cnt, S1MMEtore::msg_sm_3_i_2_r_0_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_2_r_0_t_2_busy, S1MMEtore::msg_sm_3_i_2_r_0_t_2_cnt, S1MMEtore::msg_sm_3_i_2_r_0_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_2_r_0_t_3_busy, S1MMEtore::msg_sm_3_i_2_r_0_t_3_cnt, S1MMEtore::msg_sm_3_i_2_r_0_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_2_r_0_t_4_busy, S1MMEtore::msg_sm_3_i_2_r_0_t_4_cnt, S1MMEtore::msg_sm_3_i_2_r_0_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_2_r_0_t_5_busy, S1MMEtore::msg_sm_3_i_2_r_0_t_5_cnt, S1MMEtore::msg_sm_3_i_2_r_0_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_2_r_0_t_6_busy, S1MMEtore::msg_sm_3_i_2_r_0_t_6_cnt, S1MMEtore::msg_sm_3_i_2_r_0_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_2_r_0_t_7_busy, S1MMEtore::msg_sm_3_i_2_r_0_t_7_cnt, S1MMEtore::msg_sm_3_i_2_r_0_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_2_r_0_t_8_busy, S1MMEtore::msg_sm_3_i_2_r_0_t_8_cnt, S1MMEtore::msg_sm_3_i_2_r_0_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_2_r_0_t_9_busy, S1MMEtore::msg_sm_3_i_2_r_0_t_9_cnt, S1MMEtore::msg_sm_3_i_2_r_0_t_9, pSctp);
				break;
			}
			break;
	}
}

VOID SctpMessageBroker::pushToQueue_i_2_r_1(Sctp *pSctp, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_2_r_1_t_0_busy, S1MMEtore::msg_sm_0_i_2_r_1_t_0_cnt, S1MMEtore::msg_sm_0_i_2_r_1_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_2_r_1_t_1_busy, S1MMEtore::msg_sm_0_i_2_r_1_t_1_cnt, S1MMEtore::msg_sm_0_i_2_r_1_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_2_r_1_t_2_busy, S1MMEtore::msg_sm_0_i_2_r_1_t_2_cnt, S1MMEtore::msg_sm_0_i_2_r_1_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_2_r_1_t_3_busy, S1MMEtore::msg_sm_0_i_2_r_1_t_3_cnt, S1MMEtore::msg_sm_0_i_2_r_1_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_2_r_1_t_4_busy, S1MMEtore::msg_sm_0_i_2_r_1_t_4_cnt, S1MMEtore::msg_sm_0_i_2_r_1_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_2_r_1_t_5_busy, S1MMEtore::msg_sm_0_i_2_r_1_t_5_cnt, S1MMEtore::msg_sm_0_i_2_r_1_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_2_r_1_t_6_busy, S1MMEtore::msg_sm_0_i_2_r_1_t_6_cnt, S1MMEtore::msg_sm_0_i_2_r_1_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_2_r_1_t_7_busy, S1MMEtore::msg_sm_0_i_2_r_1_t_7_cnt, S1MMEtore::msg_sm_0_i_2_r_1_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_2_r_1_t_8_busy, S1MMEtore::msg_sm_0_i_2_r_1_t_8_cnt, S1MMEtore::msg_sm_0_i_2_r_1_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_2_r_1_t_9_busy, S1MMEtore::msg_sm_0_i_2_r_1_t_9_cnt, S1MMEtore::msg_sm_0_i_2_r_1_t_9, pSctp);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_2_r_1_t_0_busy, S1MMEtore::msg_sm_1_i_2_r_1_t_0_cnt, S1MMEtore::msg_sm_1_i_2_r_1_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_2_r_1_t_1_busy, S1MMEtore::msg_sm_1_i_2_r_1_t_1_cnt, S1MMEtore::msg_sm_1_i_2_r_1_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_2_r_1_t_2_busy, S1MMEtore::msg_sm_1_i_2_r_1_t_2_cnt, S1MMEtore::msg_sm_1_i_2_r_1_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_2_r_1_t_3_busy, S1MMEtore::msg_sm_1_i_2_r_1_t_3_cnt, S1MMEtore::msg_sm_1_i_2_r_1_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_2_r_1_t_4_busy, S1MMEtore::msg_sm_1_i_2_r_1_t_4_cnt, S1MMEtore::msg_sm_1_i_2_r_1_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_2_r_1_t_5_busy, S1MMEtore::msg_sm_1_i_2_r_1_t_5_cnt, S1MMEtore::msg_sm_1_i_2_r_1_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_2_r_1_t_6_busy, S1MMEtore::msg_sm_1_i_2_r_1_t_6_cnt, S1MMEtore::msg_sm_1_i_2_r_1_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_2_r_1_t_7_busy, S1MMEtore::msg_sm_1_i_2_r_1_t_7_cnt, S1MMEtore::msg_sm_1_i_2_r_1_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_2_r_1_t_8_busy, S1MMEtore::msg_sm_1_i_2_r_1_t_8_cnt, S1MMEtore::msg_sm_1_i_2_r_1_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_2_r_1_t_9_busy, S1MMEtore::msg_sm_1_i_2_r_1_t_9_cnt, S1MMEtore::msg_sm_1_i_2_r_1_t_9, pSctp);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_2_r_1_t_0_busy, S1MMEtore::msg_sm_2_i_2_r_1_t_0_cnt, S1MMEtore::msg_sm_2_i_2_r_1_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_2_r_1_t_1_busy, S1MMEtore::msg_sm_2_i_2_r_1_t_1_cnt, S1MMEtore::msg_sm_2_i_2_r_1_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_2_r_1_t_2_busy, S1MMEtore::msg_sm_2_i_2_r_1_t_2_cnt, S1MMEtore::msg_sm_2_i_2_r_1_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_2_r_1_t_3_busy, S1MMEtore::msg_sm_2_i_2_r_1_t_3_cnt, S1MMEtore::msg_sm_2_i_2_r_1_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_2_r_1_t_4_busy, S1MMEtore::msg_sm_2_i_2_r_1_t_4_cnt, S1MMEtore::msg_sm_2_i_2_r_1_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_2_r_1_t_5_busy, S1MMEtore::msg_sm_2_i_2_r_1_t_5_cnt, S1MMEtore::msg_sm_2_i_2_r_1_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_2_r_1_t_6_busy, S1MMEtore::msg_sm_2_i_2_r_1_t_6_cnt, S1MMEtore::msg_sm_2_i_2_r_1_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_2_r_1_t_7_busy, S1MMEtore::msg_sm_2_i_2_r_1_t_7_cnt, S1MMEtore::msg_sm_2_i_2_r_1_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_2_r_1_t_8_busy, S1MMEtore::msg_sm_2_i_2_r_1_t_8_cnt, S1MMEtore::msg_sm_2_i_2_r_1_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_2_r_1_t_9_busy, S1MMEtore::msg_sm_2_i_2_r_1_t_9_cnt, S1MMEtore::msg_sm_2_i_2_r_1_t_9, pSctp);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_2_r_1_t_0_busy, S1MMEtore::msg_sm_3_i_2_r_1_t_0_cnt, S1MMEtore::msg_sm_3_i_2_r_1_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_2_r_1_t_1_busy, S1MMEtore::msg_sm_3_i_2_r_1_t_1_cnt, S1MMEtore::msg_sm_3_i_2_r_1_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_2_r_1_t_2_busy, S1MMEtore::msg_sm_3_i_2_r_1_t_2_cnt, S1MMEtore::msg_sm_3_i_2_r_1_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_2_r_1_t_3_busy, S1MMEtore::msg_sm_3_i_2_r_1_t_3_cnt, S1MMEtore::msg_sm_3_i_2_r_1_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_2_r_1_t_4_busy, S1MMEtore::msg_sm_3_i_2_r_1_t_4_cnt, S1MMEtore::msg_sm_3_i_2_r_1_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_2_r_1_t_5_busy, S1MMEtore::msg_sm_3_i_2_r_1_t_5_cnt, S1MMEtore::msg_sm_3_i_2_r_1_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_2_r_1_t_6_busy, S1MMEtore::msg_sm_3_i_2_r_1_t_6_cnt, S1MMEtore::msg_sm_3_i_2_r_1_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_2_r_1_t_7_busy, S1MMEtore::msg_sm_3_i_2_r_1_t_7_cnt, S1MMEtore::msg_sm_3_i_2_r_1_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_2_r_1_t_8_busy, S1MMEtore::msg_sm_3_i_2_r_1_t_8_cnt, S1MMEtore::msg_sm_3_i_2_r_1_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_2_r_1_t_9_busy, S1MMEtore::msg_sm_3_i_2_r_1_t_9_cnt, S1MMEtore::msg_sm_3_i_2_r_1_t_9, pSctp);
				break;
			}
			break;
	}
}

VOID SctpMessageBroker::pushToQueue_i_2_r_2(Sctp *pSctp, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_2_r_2_t_0_busy, S1MMEtore::msg_sm_0_i_2_r_2_t_0_cnt, S1MMEtore::msg_sm_0_i_2_r_2_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_2_r_2_t_1_busy, S1MMEtore::msg_sm_0_i_2_r_2_t_1_cnt, S1MMEtore::msg_sm_0_i_2_r_2_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_2_r_2_t_2_busy, S1MMEtore::msg_sm_0_i_2_r_2_t_2_cnt, S1MMEtore::msg_sm_0_i_2_r_2_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_2_r_2_t_3_busy, S1MMEtore::msg_sm_0_i_2_r_2_t_3_cnt, S1MMEtore::msg_sm_0_i_2_r_2_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_2_r_2_t_4_busy, S1MMEtore::msg_sm_0_i_2_r_2_t_4_cnt, S1MMEtore::msg_sm_0_i_2_r_2_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_2_r_2_t_5_busy, S1MMEtore::msg_sm_0_i_2_r_2_t_5_cnt, S1MMEtore::msg_sm_0_i_2_r_2_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_2_r_2_t_6_busy, S1MMEtore::msg_sm_0_i_2_r_2_t_6_cnt, S1MMEtore::msg_sm_0_i_2_r_2_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_2_r_2_t_7_busy, S1MMEtore::msg_sm_0_i_2_r_2_t_7_cnt, S1MMEtore::msg_sm_0_i_2_r_2_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_2_r_2_t_8_busy, S1MMEtore::msg_sm_0_i_2_r_2_t_8_cnt, S1MMEtore::msg_sm_0_i_2_r_2_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_2_r_2_t_9_busy, S1MMEtore::msg_sm_0_i_2_r_2_t_9_cnt, S1MMEtore::msg_sm_0_i_2_r_2_t_9, pSctp);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_2_r_2_t_0_busy, S1MMEtore::msg_sm_1_i_2_r_2_t_0_cnt, S1MMEtore::msg_sm_1_i_2_r_2_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_2_r_2_t_1_busy, S1MMEtore::msg_sm_1_i_2_r_2_t_1_cnt, S1MMEtore::msg_sm_1_i_2_r_2_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_2_r_2_t_2_busy, S1MMEtore::msg_sm_1_i_2_r_2_t_2_cnt, S1MMEtore::msg_sm_1_i_2_r_2_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_2_r_2_t_3_busy, S1MMEtore::msg_sm_1_i_2_r_2_t_3_cnt, S1MMEtore::msg_sm_1_i_2_r_2_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_2_r_2_t_4_busy, S1MMEtore::msg_sm_1_i_2_r_2_t_4_cnt, S1MMEtore::msg_sm_1_i_2_r_2_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_2_r_2_t_5_busy, S1MMEtore::msg_sm_1_i_2_r_2_t_5_cnt, S1MMEtore::msg_sm_1_i_2_r_2_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_2_r_2_t_6_busy, S1MMEtore::msg_sm_1_i_2_r_2_t_6_cnt, S1MMEtore::msg_sm_1_i_2_r_2_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_2_r_2_t_7_busy, S1MMEtore::msg_sm_1_i_2_r_2_t_7_cnt, S1MMEtore::msg_sm_1_i_2_r_2_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_2_r_2_t_8_busy, S1MMEtore::msg_sm_1_i_2_r_2_t_8_cnt, S1MMEtore::msg_sm_1_i_2_r_2_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_2_r_2_t_9_busy, S1MMEtore::msg_sm_1_i_2_r_2_t_9_cnt, S1MMEtore::msg_sm_1_i_2_r_2_t_9, pSctp);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_2_r_2_t_0_busy, S1MMEtore::msg_sm_2_i_2_r_2_t_0_cnt, S1MMEtore::msg_sm_2_i_2_r_2_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_2_r_2_t_1_busy, S1MMEtore::msg_sm_2_i_2_r_2_t_1_cnt, S1MMEtore::msg_sm_2_i_2_r_2_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_2_r_2_t_2_busy, S1MMEtore::msg_sm_2_i_2_r_2_t_2_cnt, S1MMEtore::msg_sm_2_i_2_r_2_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_2_r_2_t_3_busy, S1MMEtore::msg_sm_2_i_2_r_2_t_3_cnt, S1MMEtore::msg_sm_2_i_2_r_2_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_2_r_2_t_4_busy, S1MMEtore::msg_sm_2_i_2_r_2_t_4_cnt, S1MMEtore::msg_sm_2_i_2_r_2_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_2_r_2_t_5_busy, S1MMEtore::msg_sm_2_i_2_r_2_t_5_cnt, S1MMEtore::msg_sm_2_i_2_r_2_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_2_r_2_t_6_busy, S1MMEtore::msg_sm_2_i_2_r_2_t_6_cnt, S1MMEtore::msg_sm_2_i_2_r_2_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_2_r_2_t_7_busy, S1MMEtore::msg_sm_2_i_2_r_2_t_7_cnt, S1MMEtore::msg_sm_2_i_2_r_2_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_2_r_2_t_8_busy, S1MMEtore::msg_sm_2_i_2_r_2_t_8_cnt, S1MMEtore::msg_sm_2_i_2_r_2_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_2_r_2_t_9_busy, S1MMEtore::msg_sm_2_i_2_r_2_t_9_cnt, S1MMEtore::msg_sm_2_i_2_r_2_t_9, pSctp);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_2_r_2_t_0_busy, S1MMEtore::msg_sm_3_i_2_r_2_t_0_cnt, S1MMEtore::msg_sm_3_i_2_r_2_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_2_r_2_t_1_busy, S1MMEtore::msg_sm_3_i_2_r_2_t_1_cnt, S1MMEtore::msg_sm_3_i_2_r_2_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_2_r_2_t_2_busy, S1MMEtore::msg_sm_3_i_2_r_2_t_2_cnt, S1MMEtore::msg_sm_3_i_2_r_2_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_2_r_2_t_3_busy, S1MMEtore::msg_sm_3_i_2_r_2_t_3_cnt, S1MMEtore::msg_sm_3_i_2_r_2_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_2_r_2_t_4_busy, S1MMEtore::msg_sm_3_i_2_r_2_t_4_cnt, S1MMEtore::msg_sm_3_i_2_r_2_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_2_r_2_t_5_busy, S1MMEtore::msg_sm_3_i_2_r_2_t_5_cnt, S1MMEtore::msg_sm_3_i_2_r_2_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_2_r_2_t_6_busy, S1MMEtore::msg_sm_3_i_2_r_2_t_6_cnt, S1MMEtore::msg_sm_3_i_2_r_2_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_2_r_2_t_7_busy, S1MMEtore::msg_sm_3_i_2_r_2_t_7_cnt, S1MMEtore::msg_sm_3_i_2_r_2_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_2_r_2_t_8_busy, S1MMEtore::msg_sm_3_i_2_r_2_t_8_cnt, S1MMEtore::msg_sm_3_i_2_r_2_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_2_r_2_t_9_busy, S1MMEtore::msg_sm_3_i_2_r_2_t_9_cnt, S1MMEtore::msg_sm_3_i_2_r_2_t_9, pSctp);
				break;
			}
			break;
	}
}

VOID SctpMessageBroker::pushToQueue_i_2_r_3(Sctp *pSctp, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_2_r_3_t_0_busy, S1MMEtore::msg_sm_0_i_2_r_3_t_0_cnt, S1MMEtore::msg_sm_0_i_2_r_3_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_2_r_3_t_1_busy, S1MMEtore::msg_sm_0_i_2_r_3_t_1_cnt, S1MMEtore::msg_sm_0_i_2_r_3_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_2_r_3_t_2_busy, S1MMEtore::msg_sm_0_i_2_r_3_t_2_cnt, S1MMEtore::msg_sm_0_i_2_r_3_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_2_r_3_t_3_busy, S1MMEtore::msg_sm_0_i_2_r_3_t_3_cnt, S1MMEtore::msg_sm_0_i_2_r_3_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_2_r_3_t_4_busy, S1MMEtore::msg_sm_0_i_2_r_3_t_4_cnt, S1MMEtore::msg_sm_0_i_2_r_3_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_2_r_3_t_5_busy, S1MMEtore::msg_sm_0_i_2_r_3_t_5_cnt, S1MMEtore::msg_sm_0_i_2_r_3_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_2_r_3_t_6_busy, S1MMEtore::msg_sm_0_i_2_r_3_t_6_cnt, S1MMEtore::msg_sm_0_i_2_r_3_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_2_r_3_t_7_busy, S1MMEtore::msg_sm_0_i_2_r_3_t_7_cnt, S1MMEtore::msg_sm_0_i_2_r_3_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_2_r_3_t_8_busy, S1MMEtore::msg_sm_0_i_2_r_3_t_8_cnt, S1MMEtore::msg_sm_0_i_2_r_3_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_2_r_3_t_9_busy, S1MMEtore::msg_sm_0_i_2_r_3_t_9_cnt, S1MMEtore::msg_sm_0_i_2_r_3_t_9, pSctp);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_2_r_3_t_0_busy, S1MMEtore::msg_sm_1_i_2_r_3_t_0_cnt, S1MMEtore::msg_sm_1_i_2_r_3_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_2_r_3_t_1_busy, S1MMEtore::msg_sm_1_i_2_r_3_t_1_cnt, S1MMEtore::msg_sm_1_i_2_r_3_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_2_r_3_t_2_busy, S1MMEtore::msg_sm_1_i_2_r_3_t_2_cnt, S1MMEtore::msg_sm_1_i_2_r_3_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_2_r_3_t_3_busy, S1MMEtore::msg_sm_1_i_2_r_3_t_3_cnt, S1MMEtore::msg_sm_1_i_2_r_3_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_2_r_3_t_4_busy, S1MMEtore::msg_sm_1_i_2_r_3_t_4_cnt, S1MMEtore::msg_sm_1_i_2_r_3_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_2_r_3_t_5_busy, S1MMEtore::msg_sm_1_i_2_r_3_t_5_cnt, S1MMEtore::msg_sm_1_i_2_r_3_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_2_r_3_t_6_busy, S1MMEtore::msg_sm_1_i_2_r_3_t_6_cnt, S1MMEtore::msg_sm_1_i_2_r_3_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_2_r_3_t_7_busy, S1MMEtore::msg_sm_1_i_2_r_3_t_7_cnt, S1MMEtore::msg_sm_1_i_2_r_3_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_2_r_3_t_8_busy, S1MMEtore::msg_sm_1_i_2_r_3_t_8_cnt, S1MMEtore::msg_sm_1_i_2_r_3_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_2_r_3_t_9_busy, S1MMEtore::msg_sm_1_i_2_r_3_t_9_cnt, S1MMEtore::msg_sm_1_i_2_r_3_t_9, pSctp);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_2_r_3_t_0_busy, S1MMEtore::msg_sm_2_i_2_r_3_t_0_cnt, S1MMEtore::msg_sm_2_i_2_r_3_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_2_r_3_t_1_busy, S1MMEtore::msg_sm_2_i_2_r_3_t_1_cnt, S1MMEtore::msg_sm_2_i_2_r_3_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_2_r_3_t_2_busy, S1MMEtore::msg_sm_2_i_2_r_3_t_2_cnt, S1MMEtore::msg_sm_2_i_2_r_3_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_2_r_3_t_3_busy, S1MMEtore::msg_sm_2_i_2_r_3_t_3_cnt, S1MMEtore::msg_sm_2_i_2_r_3_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_2_r_3_t_4_busy, S1MMEtore::msg_sm_2_i_2_r_3_t_4_cnt, S1MMEtore::msg_sm_2_i_2_r_3_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_2_r_3_t_5_busy, S1MMEtore::msg_sm_2_i_2_r_3_t_5_cnt, S1MMEtore::msg_sm_2_i_2_r_3_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_2_r_3_t_6_busy, S1MMEtore::msg_sm_2_i_2_r_3_t_6_cnt, S1MMEtore::msg_sm_2_i_2_r_3_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_2_r_3_t_7_busy, S1MMEtore::msg_sm_2_i_2_r_3_t_7_cnt, S1MMEtore::msg_sm_2_i_2_r_3_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_2_r_3_t_8_busy, S1MMEtore::msg_sm_2_i_2_r_3_t_8_cnt, S1MMEtore::msg_sm_2_i_2_r_3_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_2_r_3_t_9_busy, S1MMEtore::msg_sm_2_i_2_r_3_t_9_cnt, S1MMEtore::msg_sm_2_i_2_r_3_t_9, pSctp);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_2_r_3_t_0_busy, S1MMEtore::msg_sm_3_i_2_r_3_t_0_cnt, S1MMEtore::msg_sm_3_i_2_r_3_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_2_r_3_t_1_busy, S1MMEtore::msg_sm_3_i_2_r_3_t_1_cnt, S1MMEtore::msg_sm_3_i_2_r_3_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_2_r_3_t_2_busy, S1MMEtore::msg_sm_3_i_2_r_3_t_2_cnt, S1MMEtore::msg_sm_3_i_2_r_3_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_2_r_3_t_3_busy, S1MMEtore::msg_sm_3_i_2_r_3_t_3_cnt, S1MMEtore::msg_sm_3_i_2_r_3_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_2_r_3_t_4_busy, S1MMEtore::msg_sm_3_i_2_r_3_t_4_cnt, S1MMEtore::msg_sm_3_i_2_r_3_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_2_r_3_t_5_busy, S1MMEtore::msg_sm_3_i_2_r_3_t_5_cnt, S1MMEtore::msg_sm_3_i_2_r_3_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_2_r_3_t_6_busy, S1MMEtore::msg_sm_3_i_2_r_3_t_6_cnt, S1MMEtore::msg_sm_3_i_2_r_3_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_2_r_3_t_7_busy, S1MMEtore::msg_sm_3_i_2_r_3_t_7_cnt, S1MMEtore::msg_sm_3_i_2_r_3_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_2_r_3_t_8_busy, S1MMEtore::msg_sm_3_i_2_r_3_t_8_cnt, S1MMEtore::msg_sm_3_i_2_r_3_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_2_r_3_t_9_busy, S1MMEtore::msg_sm_3_i_2_r_3_t_9_cnt, S1MMEtore::msg_sm_3_i_2_r_3_t_9, pSctp);
				break;
			}
			break;
	}
}

VOID SctpMessageBroker::pushToQueue_i_2_r_4(Sctp *pSctp, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_2_r_4_t_0_busy, S1MMEtore::msg_sm_0_i_2_r_4_t_0_cnt, S1MMEtore::msg_sm_0_i_2_r_4_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_2_r_4_t_1_busy, S1MMEtore::msg_sm_0_i_2_r_4_t_1_cnt, S1MMEtore::msg_sm_0_i_2_r_4_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_2_r_4_t_2_busy, S1MMEtore::msg_sm_0_i_2_r_4_t_2_cnt, S1MMEtore::msg_sm_0_i_2_r_4_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_2_r_4_t_3_busy, S1MMEtore::msg_sm_0_i_2_r_4_t_3_cnt, S1MMEtore::msg_sm_0_i_2_r_4_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_2_r_4_t_4_busy, S1MMEtore::msg_sm_0_i_2_r_4_t_4_cnt, S1MMEtore::msg_sm_0_i_2_r_4_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_2_r_4_t_5_busy, S1MMEtore::msg_sm_0_i_2_r_4_t_5_cnt, S1MMEtore::msg_sm_0_i_2_r_4_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_2_r_4_t_6_busy, S1MMEtore::msg_sm_0_i_2_r_4_t_6_cnt, S1MMEtore::msg_sm_0_i_2_r_4_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_2_r_4_t_7_busy, S1MMEtore::msg_sm_0_i_2_r_4_t_7_cnt, S1MMEtore::msg_sm_0_i_2_r_4_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_2_r_4_t_8_busy, S1MMEtore::msg_sm_0_i_2_r_4_t_8_cnt, S1MMEtore::msg_sm_0_i_2_r_4_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_2_r_4_t_9_busy, S1MMEtore::msg_sm_0_i_2_r_4_t_9_cnt, S1MMEtore::msg_sm_0_i_2_r_4_t_9, pSctp);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_2_r_4_t_0_busy, S1MMEtore::msg_sm_1_i_2_r_4_t_0_cnt, S1MMEtore::msg_sm_1_i_2_r_4_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_2_r_4_t_1_busy, S1MMEtore::msg_sm_1_i_2_r_4_t_1_cnt, S1MMEtore::msg_sm_1_i_2_r_4_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_2_r_4_t_2_busy, S1MMEtore::msg_sm_1_i_2_r_4_t_2_cnt, S1MMEtore::msg_sm_1_i_2_r_4_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_2_r_4_t_3_busy, S1MMEtore::msg_sm_1_i_2_r_4_t_3_cnt, S1MMEtore::msg_sm_1_i_2_r_4_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_2_r_4_t_4_busy, S1MMEtore::msg_sm_1_i_2_r_4_t_4_cnt, S1MMEtore::msg_sm_1_i_2_r_4_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_2_r_4_t_5_busy, S1MMEtore::msg_sm_1_i_2_r_4_t_5_cnt, S1MMEtore::msg_sm_1_i_2_r_4_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_2_r_4_t_6_busy, S1MMEtore::msg_sm_1_i_2_r_4_t_6_cnt, S1MMEtore::msg_sm_1_i_2_r_4_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_2_r_4_t_7_busy, S1MMEtore::msg_sm_1_i_2_r_4_t_7_cnt, S1MMEtore::msg_sm_1_i_2_r_4_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_2_r_4_t_8_busy, S1MMEtore::msg_sm_1_i_2_r_4_t_8_cnt, S1MMEtore::msg_sm_1_i_2_r_4_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_2_r_4_t_9_busy, S1MMEtore::msg_sm_1_i_2_r_4_t_9_cnt, S1MMEtore::msg_sm_1_i_2_r_4_t_9, pSctp);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_2_r_4_t_0_busy, S1MMEtore::msg_sm_2_i_2_r_4_t_0_cnt, S1MMEtore::msg_sm_2_i_2_r_4_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_2_r_4_t_1_busy, S1MMEtore::msg_sm_2_i_2_r_4_t_1_cnt, S1MMEtore::msg_sm_2_i_2_r_4_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_2_r_4_t_2_busy, S1MMEtore::msg_sm_2_i_2_r_4_t_2_cnt, S1MMEtore::msg_sm_2_i_2_r_4_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_2_r_4_t_3_busy, S1MMEtore::msg_sm_2_i_2_r_4_t_3_cnt, S1MMEtore::msg_sm_2_i_2_r_4_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_2_r_4_t_4_busy, S1MMEtore::msg_sm_2_i_2_r_4_t_4_cnt, S1MMEtore::msg_sm_2_i_2_r_4_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_2_r_4_t_5_busy, S1MMEtore::msg_sm_2_i_2_r_4_t_5_cnt, S1MMEtore::msg_sm_2_i_2_r_4_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_2_r_4_t_6_busy, S1MMEtore::msg_sm_2_i_2_r_4_t_6_cnt, S1MMEtore::msg_sm_2_i_2_r_4_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_2_r_4_t_7_busy, S1MMEtore::msg_sm_2_i_2_r_4_t_7_cnt, S1MMEtore::msg_sm_2_i_2_r_4_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_2_r_4_t_8_busy, S1MMEtore::msg_sm_2_i_2_r_4_t_8_cnt, S1MMEtore::msg_sm_2_i_2_r_4_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_2_r_4_t_9_busy, S1MMEtore::msg_sm_2_i_2_r_4_t_9_cnt, S1MMEtore::msg_sm_2_i_2_r_4_t_9, pSctp);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_2_r_4_t_0_busy, S1MMEtore::msg_sm_3_i_2_r_4_t_0_cnt, S1MMEtore::msg_sm_3_i_2_r_4_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_2_r_4_t_1_busy, S1MMEtore::msg_sm_3_i_2_r_4_t_1_cnt, S1MMEtore::msg_sm_3_i_2_r_4_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_2_r_4_t_2_busy, S1MMEtore::msg_sm_3_i_2_r_4_t_2_cnt, S1MMEtore::msg_sm_3_i_2_r_4_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_2_r_4_t_3_busy, S1MMEtore::msg_sm_3_i_2_r_4_t_3_cnt, S1MMEtore::msg_sm_3_i_2_r_4_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_2_r_4_t_4_busy, S1MMEtore::msg_sm_3_i_2_r_4_t_4_cnt, S1MMEtore::msg_sm_3_i_2_r_4_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_2_r_4_t_5_busy, S1MMEtore::msg_sm_3_i_2_r_4_t_5_cnt, S1MMEtore::msg_sm_3_i_2_r_4_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_2_r_4_t_6_busy, S1MMEtore::msg_sm_3_i_2_r_4_t_6_cnt, S1MMEtore::msg_sm_3_i_2_r_4_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_2_r_4_t_7_busy, S1MMEtore::msg_sm_3_i_2_r_4_t_7_cnt, S1MMEtore::msg_sm_3_i_2_r_4_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_2_r_4_t_8_busy, S1MMEtore::msg_sm_3_i_2_r_4_t_8_cnt, S1MMEtore::msg_sm_3_i_2_r_4_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_2_r_4_t_9_busy, S1MMEtore::msg_sm_3_i_2_r_4_t_9_cnt, S1MMEtore::msg_sm_3_i_2_r_4_t_9, pSctp);
				break;
			}
			break;
	}
}

VOID SctpMessageBroker::pushToQueue_i_2_r_5(Sctp *pSctp, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_2_r_5_t_0_busy, S1MMEtore::msg_sm_0_i_2_r_5_t_0_cnt, S1MMEtore::msg_sm_0_i_2_r_5_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_2_r_5_t_1_busy, S1MMEtore::msg_sm_0_i_2_r_5_t_1_cnt, S1MMEtore::msg_sm_0_i_2_r_5_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_2_r_5_t_2_busy, S1MMEtore::msg_sm_0_i_2_r_5_t_2_cnt, S1MMEtore::msg_sm_0_i_2_r_5_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_2_r_5_t_3_busy, S1MMEtore::msg_sm_0_i_2_r_5_t_3_cnt, S1MMEtore::msg_sm_0_i_2_r_5_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_2_r_5_t_4_busy, S1MMEtore::msg_sm_0_i_2_r_5_t_4_cnt, S1MMEtore::msg_sm_0_i_2_r_5_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_2_r_5_t_5_busy, S1MMEtore::msg_sm_0_i_2_r_5_t_5_cnt, S1MMEtore::msg_sm_0_i_2_r_5_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_2_r_5_t_6_busy, S1MMEtore::msg_sm_0_i_2_r_5_t_6_cnt, S1MMEtore::msg_sm_0_i_2_r_5_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_2_r_5_t_7_busy, S1MMEtore::msg_sm_0_i_2_r_5_t_7_cnt, S1MMEtore::msg_sm_0_i_2_r_5_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_2_r_5_t_8_busy, S1MMEtore::msg_sm_0_i_2_r_5_t_8_cnt, S1MMEtore::msg_sm_0_i_2_r_5_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_2_r_5_t_9_busy, S1MMEtore::msg_sm_0_i_2_r_5_t_9_cnt, S1MMEtore::msg_sm_0_i_2_r_5_t_9, pSctp);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_2_r_5_t_0_busy, S1MMEtore::msg_sm_1_i_2_r_5_t_0_cnt, S1MMEtore::msg_sm_1_i_2_r_5_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_2_r_5_t_1_busy, S1MMEtore::msg_sm_1_i_2_r_5_t_1_cnt, S1MMEtore::msg_sm_1_i_2_r_5_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_2_r_5_t_2_busy, S1MMEtore::msg_sm_1_i_2_r_5_t_2_cnt, S1MMEtore::msg_sm_1_i_2_r_5_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_2_r_5_t_3_busy, S1MMEtore::msg_sm_1_i_2_r_5_t_3_cnt, S1MMEtore::msg_sm_1_i_2_r_5_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_2_r_5_t_4_busy, S1MMEtore::msg_sm_1_i_2_r_5_t_4_cnt, S1MMEtore::msg_sm_1_i_2_r_5_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_2_r_5_t_5_busy, S1MMEtore::msg_sm_1_i_2_r_5_t_5_cnt, S1MMEtore::msg_sm_1_i_2_r_5_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_2_r_5_t_6_busy, S1MMEtore::msg_sm_1_i_2_r_5_t_6_cnt, S1MMEtore::msg_sm_1_i_2_r_5_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_2_r_5_t_7_busy, S1MMEtore::msg_sm_1_i_2_r_5_t_7_cnt, S1MMEtore::msg_sm_1_i_2_r_5_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_2_r_5_t_8_busy, S1MMEtore::msg_sm_1_i_2_r_5_t_8_cnt, S1MMEtore::msg_sm_1_i_2_r_5_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_2_r_5_t_9_busy, S1MMEtore::msg_sm_1_i_2_r_5_t_9_cnt, S1MMEtore::msg_sm_1_i_2_r_5_t_9, pSctp);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_2_r_5_t_0_busy, S1MMEtore::msg_sm_2_i_2_r_5_t_0_cnt, S1MMEtore::msg_sm_2_i_2_r_5_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_2_r_5_t_1_busy, S1MMEtore::msg_sm_2_i_2_r_5_t_1_cnt, S1MMEtore::msg_sm_2_i_2_r_5_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_2_r_5_t_2_busy, S1MMEtore::msg_sm_2_i_2_r_5_t_2_cnt, S1MMEtore::msg_sm_2_i_2_r_5_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_2_r_5_t_3_busy, S1MMEtore::msg_sm_2_i_2_r_5_t_3_cnt, S1MMEtore::msg_sm_2_i_2_r_5_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_2_r_5_t_4_busy, S1MMEtore::msg_sm_2_i_2_r_5_t_4_cnt, S1MMEtore::msg_sm_2_i_2_r_5_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_2_r_5_t_5_busy, S1MMEtore::msg_sm_2_i_2_r_5_t_5_cnt, S1MMEtore::msg_sm_2_i_2_r_5_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_2_r_5_t_6_busy, S1MMEtore::msg_sm_2_i_2_r_5_t_6_cnt, S1MMEtore::msg_sm_2_i_2_r_5_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_2_r_5_t_7_busy, S1MMEtore::msg_sm_2_i_2_r_5_t_7_cnt, S1MMEtore::msg_sm_2_i_2_r_5_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_2_r_5_t_8_busy, S1MMEtore::msg_sm_2_i_2_r_5_t_8_cnt, S1MMEtore::msg_sm_2_i_2_r_5_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_2_r_5_t_9_busy, S1MMEtore::msg_sm_2_i_2_r_5_t_9_cnt, S1MMEtore::msg_sm_2_i_2_r_5_t_9, pSctp);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_2_r_5_t_0_busy, S1MMEtore::msg_sm_3_i_2_r_5_t_0_cnt, S1MMEtore::msg_sm_3_i_2_r_5_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_2_r_5_t_1_busy, S1MMEtore::msg_sm_3_i_2_r_5_t_1_cnt, S1MMEtore::msg_sm_3_i_2_r_5_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_2_r_5_t_2_busy, S1MMEtore::msg_sm_3_i_2_r_5_t_2_cnt, S1MMEtore::msg_sm_3_i_2_r_5_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_2_r_5_t_3_busy, S1MMEtore::msg_sm_3_i_2_r_5_t_3_cnt, S1MMEtore::msg_sm_3_i_2_r_5_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_2_r_5_t_4_busy, S1MMEtore::msg_sm_3_i_2_r_5_t_4_cnt, S1MMEtore::msg_sm_3_i_2_r_5_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_2_r_5_t_5_busy, S1MMEtore::msg_sm_3_i_2_r_5_t_5_cnt, S1MMEtore::msg_sm_3_i_2_r_5_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_2_r_5_t_6_busy, S1MMEtore::msg_sm_3_i_2_r_5_t_6_cnt, S1MMEtore::msg_sm_3_i_2_r_5_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_2_r_5_t_7_busy, S1MMEtore::msg_sm_3_i_2_r_5_t_7_cnt, S1MMEtore::msg_sm_3_i_2_r_5_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_2_r_5_t_8_busy, S1MMEtore::msg_sm_3_i_2_r_5_t_8_cnt, S1MMEtore::msg_sm_3_i_2_r_5_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_2_r_5_t_9_busy, S1MMEtore::msg_sm_3_i_2_r_5_t_9_cnt, S1MMEtore::msg_sm_3_i_2_r_5_t_9, pSctp);
				break;
			}
			break;
	}
}

VOID SctpMessageBroker::pushToQueue_i_2_r_6(Sctp *pSctp, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_2_r_6_t_0_busy, S1MMEtore::msg_sm_0_i_2_r_6_t_0_cnt, S1MMEtore::msg_sm_0_i_2_r_6_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_2_r_6_t_1_busy, S1MMEtore::msg_sm_0_i_2_r_6_t_1_cnt, S1MMEtore::msg_sm_0_i_2_r_6_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_2_r_6_t_2_busy, S1MMEtore::msg_sm_0_i_2_r_6_t_2_cnt, S1MMEtore::msg_sm_0_i_2_r_6_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_2_r_6_t_3_busy, S1MMEtore::msg_sm_0_i_2_r_6_t_3_cnt, S1MMEtore::msg_sm_0_i_2_r_6_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_2_r_6_t_4_busy, S1MMEtore::msg_sm_0_i_2_r_6_t_4_cnt, S1MMEtore::msg_sm_0_i_2_r_6_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_2_r_6_t_5_busy, S1MMEtore::msg_sm_0_i_2_r_6_t_5_cnt, S1MMEtore::msg_sm_0_i_2_r_6_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_2_r_6_t_6_busy, S1MMEtore::msg_sm_0_i_2_r_6_t_6_cnt, S1MMEtore::msg_sm_0_i_2_r_6_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_2_r_6_t_7_busy, S1MMEtore::msg_sm_0_i_2_r_6_t_7_cnt, S1MMEtore::msg_sm_0_i_2_r_6_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_2_r_6_t_8_busy, S1MMEtore::msg_sm_0_i_2_r_6_t_8_cnt, S1MMEtore::msg_sm_0_i_2_r_6_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_2_r_6_t_9_busy, S1MMEtore::msg_sm_0_i_2_r_6_t_9_cnt, S1MMEtore::msg_sm_0_i_2_r_6_t_9, pSctp);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_2_r_6_t_0_busy, S1MMEtore::msg_sm_1_i_2_r_6_t_0_cnt, S1MMEtore::msg_sm_1_i_2_r_6_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_2_r_6_t_1_busy, S1MMEtore::msg_sm_1_i_2_r_6_t_1_cnt, S1MMEtore::msg_sm_1_i_2_r_6_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_2_r_6_t_2_busy, S1MMEtore::msg_sm_1_i_2_r_6_t_2_cnt, S1MMEtore::msg_sm_1_i_2_r_6_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_2_r_6_t_3_busy, S1MMEtore::msg_sm_1_i_2_r_6_t_3_cnt, S1MMEtore::msg_sm_1_i_2_r_6_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_2_r_6_t_4_busy, S1MMEtore::msg_sm_1_i_2_r_6_t_4_cnt, S1MMEtore::msg_sm_1_i_2_r_6_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_2_r_6_t_5_busy, S1MMEtore::msg_sm_1_i_2_r_6_t_5_cnt, S1MMEtore::msg_sm_1_i_2_r_6_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_2_r_6_t_6_busy, S1MMEtore::msg_sm_1_i_2_r_6_t_6_cnt, S1MMEtore::msg_sm_1_i_2_r_6_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_2_r_6_t_7_busy, S1MMEtore::msg_sm_1_i_2_r_6_t_7_cnt, S1MMEtore::msg_sm_1_i_2_r_6_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_2_r_6_t_8_busy, S1MMEtore::msg_sm_1_i_2_r_6_t_8_cnt, S1MMEtore::msg_sm_1_i_2_r_6_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_2_r_6_t_9_busy, S1MMEtore::msg_sm_1_i_2_r_6_t_9_cnt, S1MMEtore::msg_sm_1_i_2_r_6_t_9, pSctp);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_2_r_6_t_0_busy, S1MMEtore::msg_sm_2_i_2_r_6_t_0_cnt, S1MMEtore::msg_sm_2_i_2_r_6_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_2_r_6_t_1_busy, S1MMEtore::msg_sm_2_i_2_r_6_t_1_cnt, S1MMEtore::msg_sm_2_i_2_r_6_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_2_r_6_t_2_busy, S1MMEtore::msg_sm_2_i_2_r_6_t_2_cnt, S1MMEtore::msg_sm_2_i_2_r_6_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_2_r_6_t_3_busy, S1MMEtore::msg_sm_2_i_2_r_6_t_3_cnt, S1MMEtore::msg_sm_2_i_2_r_6_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_2_r_6_t_4_busy, S1MMEtore::msg_sm_2_i_2_r_6_t_4_cnt, S1MMEtore::msg_sm_2_i_2_r_6_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_2_r_6_t_5_busy, S1MMEtore::msg_sm_2_i_2_r_6_t_5_cnt, S1MMEtore::msg_sm_2_i_2_r_6_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_2_r_6_t_6_busy, S1MMEtore::msg_sm_2_i_2_r_6_t_6_cnt, S1MMEtore::msg_sm_2_i_2_r_6_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_2_r_6_t_7_busy, S1MMEtore::msg_sm_2_i_2_r_6_t_7_cnt, S1MMEtore::msg_sm_2_i_2_r_6_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_2_r_6_t_8_busy, S1MMEtore::msg_sm_2_i_2_r_6_t_8_cnt, S1MMEtore::msg_sm_2_i_2_r_6_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_2_r_6_t_9_busy, S1MMEtore::msg_sm_2_i_2_r_6_t_9_cnt, S1MMEtore::msg_sm_2_i_2_r_6_t_9, pSctp);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_2_r_6_t_0_busy, S1MMEtore::msg_sm_3_i_2_r_6_t_0_cnt, S1MMEtore::msg_sm_3_i_2_r_6_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_2_r_6_t_1_busy, S1MMEtore::msg_sm_3_i_2_r_6_t_1_cnt, S1MMEtore::msg_sm_3_i_2_r_6_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_2_r_6_t_2_busy, S1MMEtore::msg_sm_3_i_2_r_6_t_2_cnt, S1MMEtore::msg_sm_3_i_2_r_6_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_2_r_6_t_3_busy, S1MMEtore::msg_sm_3_i_2_r_6_t_3_cnt, S1MMEtore::msg_sm_3_i_2_r_6_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_2_r_6_t_4_busy, S1MMEtore::msg_sm_3_i_2_r_6_t_4_cnt, S1MMEtore::msg_sm_3_i_2_r_6_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_2_r_6_t_5_busy, S1MMEtore::msg_sm_3_i_2_r_6_t_5_cnt, S1MMEtore::msg_sm_3_i_2_r_6_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_2_r_6_t_6_busy, S1MMEtore::msg_sm_3_i_2_r_6_t_6_cnt, S1MMEtore::msg_sm_3_i_2_r_6_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_2_r_6_t_7_busy, S1MMEtore::msg_sm_3_i_2_r_6_t_7_cnt, S1MMEtore::msg_sm_3_i_2_r_6_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_2_r_6_t_8_busy, S1MMEtore::msg_sm_3_i_2_r_6_t_8_cnt, S1MMEtore::msg_sm_3_i_2_r_6_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_2_r_6_t_9_busy, S1MMEtore::msg_sm_3_i_2_r_6_t_9_cnt, S1MMEtore::msg_sm_3_i_2_r_6_t_9, pSctp);
				break;
			}
			break;
	}
}

VOID SctpMessageBroker::pushToQueue_i_2_r_7(Sctp *pSctp, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_2_r_7_t_0_busy, S1MMEtore::msg_sm_0_i_2_r_7_t_0_cnt, S1MMEtore::msg_sm_0_i_2_r_7_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_2_r_7_t_1_busy, S1MMEtore::msg_sm_0_i_2_r_7_t_1_cnt, S1MMEtore::msg_sm_0_i_2_r_7_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_2_r_7_t_2_busy, S1MMEtore::msg_sm_0_i_2_r_7_t_2_cnt, S1MMEtore::msg_sm_0_i_2_r_7_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_2_r_7_t_3_busy, S1MMEtore::msg_sm_0_i_2_r_7_t_3_cnt, S1MMEtore::msg_sm_0_i_2_r_7_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_2_r_7_t_4_busy, S1MMEtore::msg_sm_0_i_2_r_7_t_4_cnt, S1MMEtore::msg_sm_0_i_2_r_7_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_2_r_7_t_5_busy, S1MMEtore::msg_sm_0_i_2_r_7_t_5_cnt, S1MMEtore::msg_sm_0_i_2_r_7_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_2_r_7_t_6_busy, S1MMEtore::msg_sm_0_i_2_r_7_t_6_cnt, S1MMEtore::msg_sm_0_i_2_r_7_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_2_r_7_t_7_busy, S1MMEtore::msg_sm_0_i_2_r_7_t_7_cnt, S1MMEtore::msg_sm_0_i_2_r_7_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_2_r_7_t_8_busy, S1MMEtore::msg_sm_0_i_2_r_7_t_8_cnt, S1MMEtore::msg_sm_0_i_2_r_7_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_2_r_7_t_9_busy, S1MMEtore::msg_sm_0_i_2_r_7_t_9_cnt, S1MMEtore::msg_sm_0_i_2_r_7_t_9, pSctp);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_2_r_7_t_0_busy, S1MMEtore::msg_sm_1_i_2_r_7_t_0_cnt, S1MMEtore::msg_sm_1_i_2_r_7_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_2_r_7_t_1_busy, S1MMEtore::msg_sm_1_i_2_r_7_t_1_cnt, S1MMEtore::msg_sm_1_i_2_r_7_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_2_r_7_t_2_busy, S1MMEtore::msg_sm_1_i_2_r_7_t_2_cnt, S1MMEtore::msg_sm_1_i_2_r_7_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_2_r_7_t_3_busy, S1MMEtore::msg_sm_1_i_2_r_7_t_3_cnt, S1MMEtore::msg_sm_1_i_2_r_7_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_2_r_7_t_4_busy, S1MMEtore::msg_sm_1_i_2_r_7_t_4_cnt, S1MMEtore::msg_sm_1_i_2_r_7_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_2_r_7_t_5_busy, S1MMEtore::msg_sm_1_i_2_r_7_t_5_cnt, S1MMEtore::msg_sm_1_i_2_r_7_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_2_r_7_t_6_busy, S1MMEtore::msg_sm_1_i_2_r_7_t_6_cnt, S1MMEtore::msg_sm_1_i_2_r_7_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_2_r_7_t_7_busy, S1MMEtore::msg_sm_1_i_2_r_7_t_7_cnt, S1MMEtore::msg_sm_1_i_2_r_7_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_2_r_7_t_8_busy, S1MMEtore::msg_sm_1_i_2_r_7_t_8_cnt, S1MMEtore::msg_sm_1_i_2_r_7_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_2_r_7_t_9_busy, S1MMEtore::msg_sm_1_i_2_r_7_t_9_cnt, S1MMEtore::msg_sm_1_i_2_r_7_t_9, pSctp);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_2_r_7_t_0_busy, S1MMEtore::msg_sm_2_i_2_r_7_t_0_cnt, S1MMEtore::msg_sm_2_i_2_r_7_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_2_r_7_t_1_busy, S1MMEtore::msg_sm_2_i_2_r_7_t_1_cnt, S1MMEtore::msg_sm_2_i_2_r_7_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_2_r_7_t_2_busy, S1MMEtore::msg_sm_2_i_2_r_7_t_2_cnt, S1MMEtore::msg_sm_2_i_2_r_7_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_2_r_7_t_3_busy, S1MMEtore::msg_sm_2_i_2_r_7_t_3_cnt, S1MMEtore::msg_sm_2_i_2_r_7_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_2_r_7_t_4_busy, S1MMEtore::msg_sm_2_i_2_r_7_t_4_cnt, S1MMEtore::msg_sm_2_i_2_r_7_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_2_r_7_t_5_busy, S1MMEtore::msg_sm_2_i_2_r_7_t_5_cnt, S1MMEtore::msg_sm_2_i_2_r_7_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_2_r_7_t_6_busy, S1MMEtore::msg_sm_2_i_2_r_7_t_6_cnt, S1MMEtore::msg_sm_2_i_2_r_7_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_2_r_7_t_7_busy, S1MMEtore::msg_sm_2_i_2_r_7_t_7_cnt, S1MMEtore::msg_sm_2_i_2_r_7_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_2_r_7_t_8_busy, S1MMEtore::msg_sm_2_i_2_r_7_t_8_cnt, S1MMEtore::msg_sm_2_i_2_r_7_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_2_r_7_t_9_busy, S1MMEtore::msg_sm_2_i_2_r_7_t_9_cnt, S1MMEtore::msg_sm_2_i_2_r_7_t_9, pSctp);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_2_r_7_t_0_busy, S1MMEtore::msg_sm_3_i_2_r_7_t_0_cnt, S1MMEtore::msg_sm_3_i_2_r_7_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_2_r_7_t_1_busy, S1MMEtore::msg_sm_3_i_2_r_7_t_1_cnt, S1MMEtore::msg_sm_3_i_2_r_7_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_2_r_7_t_2_busy, S1MMEtore::msg_sm_3_i_2_r_7_t_2_cnt, S1MMEtore::msg_sm_3_i_2_r_7_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_2_r_7_t_3_busy, S1MMEtore::msg_sm_3_i_2_r_7_t_3_cnt, S1MMEtore::msg_sm_3_i_2_r_7_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_2_r_7_t_4_busy, S1MMEtore::msg_sm_3_i_2_r_7_t_4_cnt, S1MMEtore::msg_sm_3_i_2_r_7_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_2_r_7_t_5_busy, S1MMEtore::msg_sm_3_i_2_r_7_t_5_cnt, S1MMEtore::msg_sm_3_i_2_r_7_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_2_r_7_t_6_busy, S1MMEtore::msg_sm_3_i_2_r_7_t_6_cnt, S1MMEtore::msg_sm_3_i_2_r_7_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_2_r_7_t_7_busy, S1MMEtore::msg_sm_3_i_2_r_7_t_7_cnt, S1MMEtore::msg_sm_3_i_2_r_7_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_2_r_7_t_8_busy, S1MMEtore::msg_sm_3_i_2_r_7_t_8_cnt, S1MMEtore::msg_sm_3_i_2_r_7_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_2_r_7_t_9_busy, S1MMEtore::msg_sm_3_i_2_r_7_t_9_cnt, S1MMEtore::msg_sm_3_i_2_r_7_t_9, pSctp);
				break;
			}
			break;
	}
}


VOID SctpMessageBroker::pushToQueue_i_3_r_0(Sctp *pSctp, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_3_r_0_t_0_busy, S1MMEtore::msg_sm_0_i_3_r_0_t_0_cnt, S1MMEtore::msg_sm_0_i_3_r_0_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_3_r_0_t_1_busy, S1MMEtore::msg_sm_0_i_3_r_0_t_1_cnt, S1MMEtore::msg_sm_0_i_3_r_0_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_3_r_0_t_2_busy, S1MMEtore::msg_sm_0_i_3_r_0_t_2_cnt, S1MMEtore::msg_sm_0_i_3_r_0_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_3_r_0_t_3_busy, S1MMEtore::msg_sm_0_i_3_r_0_t_3_cnt, S1MMEtore::msg_sm_0_i_3_r_0_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_3_r_0_t_4_busy, S1MMEtore::msg_sm_0_i_3_r_0_t_4_cnt, S1MMEtore::msg_sm_0_i_3_r_0_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_3_r_0_t_5_busy, S1MMEtore::msg_sm_0_i_3_r_0_t_5_cnt, S1MMEtore::msg_sm_0_i_3_r_0_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_3_r_0_t_6_busy, S1MMEtore::msg_sm_0_i_3_r_0_t_6_cnt, S1MMEtore::msg_sm_0_i_3_r_0_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_3_r_0_t_7_busy, S1MMEtore::msg_sm_0_i_3_r_0_t_7_cnt, S1MMEtore::msg_sm_0_i_3_r_0_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_3_r_0_t_8_busy, S1MMEtore::msg_sm_0_i_3_r_0_t_8_cnt, S1MMEtore::msg_sm_0_i_3_r_0_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_3_r_0_t_9_busy, S1MMEtore::msg_sm_0_i_3_r_0_t_9_cnt, S1MMEtore::msg_sm_0_i_3_r_0_t_9, pSctp);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_3_r_0_t_0_busy, S1MMEtore::msg_sm_1_i_3_r_0_t_0_cnt, S1MMEtore::msg_sm_1_i_3_r_0_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_3_r_0_t_1_busy, S1MMEtore::msg_sm_1_i_3_r_0_t_1_cnt, S1MMEtore::msg_sm_1_i_3_r_0_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_3_r_0_t_2_busy, S1MMEtore::msg_sm_1_i_3_r_0_t_2_cnt, S1MMEtore::msg_sm_1_i_3_r_0_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_3_r_0_t_3_busy, S1MMEtore::msg_sm_1_i_3_r_0_t_3_cnt, S1MMEtore::msg_sm_1_i_3_r_0_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_3_r_0_t_4_busy, S1MMEtore::msg_sm_1_i_3_r_0_t_4_cnt, S1MMEtore::msg_sm_1_i_3_r_0_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_3_r_0_t_5_busy, S1MMEtore::msg_sm_1_i_3_r_0_t_5_cnt, S1MMEtore::msg_sm_1_i_3_r_0_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_3_r_0_t_6_busy, S1MMEtore::msg_sm_1_i_3_r_0_t_6_cnt, S1MMEtore::msg_sm_1_i_3_r_0_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_3_r_0_t_7_busy, S1MMEtore::msg_sm_1_i_3_r_0_t_7_cnt, S1MMEtore::msg_sm_1_i_3_r_0_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_3_r_0_t_8_busy, S1MMEtore::msg_sm_1_i_3_r_0_t_8_cnt, S1MMEtore::msg_sm_1_i_3_r_0_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_3_r_0_t_9_busy, S1MMEtore::msg_sm_1_i_3_r_0_t_9_cnt, S1MMEtore::msg_sm_1_i_3_r_0_t_9, pSctp);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_3_r_0_t_0_busy, S1MMEtore::msg_sm_2_i_3_r_0_t_0_cnt, S1MMEtore::msg_sm_2_i_3_r_0_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_3_r_0_t_1_busy, S1MMEtore::msg_sm_2_i_3_r_0_t_1_cnt, S1MMEtore::msg_sm_2_i_3_r_0_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_3_r_0_t_2_busy, S1MMEtore::msg_sm_2_i_3_r_0_t_2_cnt, S1MMEtore::msg_sm_2_i_3_r_0_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_3_r_0_t_3_busy, S1MMEtore::msg_sm_2_i_3_r_0_t_3_cnt, S1MMEtore::msg_sm_2_i_3_r_0_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_3_r_0_t_4_busy, S1MMEtore::msg_sm_2_i_3_r_0_t_4_cnt, S1MMEtore::msg_sm_2_i_3_r_0_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_3_r_0_t_5_busy, S1MMEtore::msg_sm_2_i_3_r_0_t_5_cnt, S1MMEtore::msg_sm_2_i_3_r_0_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_3_r_0_t_6_busy, S1MMEtore::msg_sm_2_i_3_r_0_t_6_cnt, S1MMEtore::msg_sm_2_i_3_r_0_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_3_r_0_t_7_busy, S1MMEtore::msg_sm_2_i_3_r_0_t_7_cnt, S1MMEtore::msg_sm_2_i_3_r_0_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_3_r_0_t_8_busy, S1MMEtore::msg_sm_2_i_3_r_0_t_8_cnt, S1MMEtore::msg_sm_2_i_3_r_0_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_3_r_0_t_9_busy, S1MMEtore::msg_sm_2_i_3_r_0_t_9_cnt, S1MMEtore::msg_sm_2_i_3_r_0_t_9, pSctp);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_3_r_0_t_0_busy, S1MMEtore::msg_sm_3_i_3_r_0_t_0_cnt, S1MMEtore::msg_sm_3_i_3_r_0_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_3_r_0_t_1_busy, S1MMEtore::msg_sm_3_i_3_r_0_t_1_cnt, S1MMEtore::msg_sm_3_i_3_r_0_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_3_r_0_t_2_busy, S1MMEtore::msg_sm_3_i_3_r_0_t_2_cnt, S1MMEtore::msg_sm_3_i_3_r_0_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_3_r_0_t_3_busy, S1MMEtore::msg_sm_3_i_3_r_0_t_3_cnt, S1MMEtore::msg_sm_3_i_3_r_0_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_3_r_0_t_4_busy, S1MMEtore::msg_sm_3_i_3_r_0_t_4_cnt, S1MMEtore::msg_sm_3_i_3_r_0_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_3_r_0_t_5_busy, S1MMEtore::msg_sm_3_i_3_r_0_t_5_cnt, S1MMEtore::msg_sm_3_i_3_r_0_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_3_r_0_t_6_busy, S1MMEtore::msg_sm_3_i_3_r_0_t_6_cnt, S1MMEtore::msg_sm_3_i_3_r_0_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_3_r_0_t_7_busy, S1MMEtore::msg_sm_3_i_3_r_0_t_7_cnt, S1MMEtore::msg_sm_3_i_3_r_0_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_3_r_0_t_8_busy, S1MMEtore::msg_sm_3_i_3_r_0_t_8_cnt, S1MMEtore::msg_sm_3_i_3_r_0_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_3_r_0_t_9_busy, S1MMEtore::msg_sm_3_i_3_r_0_t_9_cnt, S1MMEtore::msg_sm_3_i_3_r_0_t_9, pSctp);
				break;
			}
			break;
	}
}

VOID SctpMessageBroker::pushToQueue_i_3_r_1(Sctp *pSctp, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_3_r_1_t_0_busy, S1MMEtore::msg_sm_0_i_3_r_1_t_0_cnt, S1MMEtore::msg_sm_0_i_3_r_1_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_3_r_1_t_1_busy, S1MMEtore::msg_sm_0_i_3_r_1_t_1_cnt, S1MMEtore::msg_sm_0_i_3_r_1_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_3_r_1_t_2_busy, S1MMEtore::msg_sm_0_i_3_r_1_t_2_cnt, S1MMEtore::msg_sm_0_i_3_r_1_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_3_r_1_t_3_busy, S1MMEtore::msg_sm_0_i_3_r_1_t_3_cnt, S1MMEtore::msg_sm_0_i_3_r_1_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_3_r_1_t_4_busy, S1MMEtore::msg_sm_0_i_3_r_1_t_4_cnt, S1MMEtore::msg_sm_0_i_3_r_1_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_3_r_1_t_5_busy, S1MMEtore::msg_sm_0_i_3_r_1_t_5_cnt, S1MMEtore::msg_sm_0_i_3_r_1_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_3_r_1_t_6_busy, S1MMEtore::msg_sm_0_i_3_r_1_t_6_cnt, S1MMEtore::msg_sm_0_i_3_r_1_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_3_r_1_t_7_busy, S1MMEtore::msg_sm_0_i_3_r_1_t_7_cnt, S1MMEtore::msg_sm_0_i_3_r_1_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_3_r_1_t_8_busy, S1MMEtore::msg_sm_0_i_3_r_1_t_8_cnt, S1MMEtore::msg_sm_0_i_3_r_1_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_3_r_1_t_9_busy, S1MMEtore::msg_sm_0_i_3_r_1_t_9_cnt, S1MMEtore::msg_sm_0_i_3_r_1_t_9, pSctp);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_3_r_1_t_0_busy, S1MMEtore::msg_sm_1_i_3_r_1_t_0_cnt, S1MMEtore::msg_sm_1_i_3_r_1_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_3_r_1_t_1_busy, S1MMEtore::msg_sm_1_i_3_r_1_t_1_cnt, S1MMEtore::msg_sm_1_i_3_r_1_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_3_r_1_t_2_busy, S1MMEtore::msg_sm_1_i_3_r_1_t_2_cnt, S1MMEtore::msg_sm_1_i_3_r_1_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_3_r_1_t_3_busy, S1MMEtore::msg_sm_1_i_3_r_1_t_3_cnt, S1MMEtore::msg_sm_1_i_3_r_1_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_3_r_1_t_4_busy, S1MMEtore::msg_sm_1_i_3_r_1_t_4_cnt, S1MMEtore::msg_sm_1_i_3_r_1_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_3_r_1_t_5_busy, S1MMEtore::msg_sm_1_i_3_r_1_t_5_cnt, S1MMEtore::msg_sm_1_i_3_r_1_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_3_r_1_t_6_busy, S1MMEtore::msg_sm_1_i_3_r_1_t_6_cnt, S1MMEtore::msg_sm_1_i_3_r_1_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_3_r_1_t_7_busy, S1MMEtore::msg_sm_1_i_3_r_1_t_7_cnt, S1MMEtore::msg_sm_1_i_3_r_1_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_3_r_1_t_8_busy, S1MMEtore::msg_sm_1_i_3_r_1_t_8_cnt, S1MMEtore::msg_sm_1_i_3_r_1_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_3_r_1_t_9_busy, S1MMEtore::msg_sm_1_i_3_r_1_t_9_cnt, S1MMEtore::msg_sm_1_i_3_r_1_t_9, pSctp);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_3_r_1_t_0_busy, S1MMEtore::msg_sm_2_i_3_r_1_t_0_cnt, S1MMEtore::msg_sm_2_i_3_r_1_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_3_r_1_t_1_busy, S1MMEtore::msg_sm_2_i_3_r_1_t_1_cnt, S1MMEtore::msg_sm_2_i_3_r_1_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_3_r_1_t_2_busy, S1MMEtore::msg_sm_2_i_3_r_1_t_2_cnt, S1MMEtore::msg_sm_2_i_3_r_1_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_3_r_1_t_3_busy, S1MMEtore::msg_sm_2_i_3_r_1_t_3_cnt, S1MMEtore::msg_sm_2_i_3_r_1_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_3_r_1_t_4_busy, S1MMEtore::msg_sm_2_i_3_r_1_t_4_cnt, S1MMEtore::msg_sm_2_i_3_r_1_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_3_r_1_t_5_busy, S1MMEtore::msg_sm_2_i_3_r_1_t_5_cnt, S1MMEtore::msg_sm_2_i_3_r_1_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_3_r_1_t_6_busy, S1MMEtore::msg_sm_2_i_3_r_1_t_6_cnt, S1MMEtore::msg_sm_2_i_3_r_1_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_3_r_1_t_7_busy, S1MMEtore::msg_sm_2_i_3_r_1_t_7_cnt, S1MMEtore::msg_sm_2_i_3_r_1_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_3_r_1_t_8_busy, S1MMEtore::msg_sm_2_i_3_r_1_t_8_cnt, S1MMEtore::msg_sm_2_i_3_r_1_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_3_r_1_t_9_busy, S1MMEtore::msg_sm_2_i_3_r_1_t_9_cnt, S1MMEtore::msg_sm_2_i_3_r_1_t_9, pSctp);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_3_r_1_t_0_busy, S1MMEtore::msg_sm_3_i_3_r_1_t_0_cnt, S1MMEtore::msg_sm_3_i_3_r_1_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_3_r_1_t_1_busy, S1MMEtore::msg_sm_3_i_3_r_1_t_1_cnt, S1MMEtore::msg_sm_3_i_3_r_1_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_3_r_1_t_2_busy, S1MMEtore::msg_sm_3_i_3_r_1_t_2_cnt, S1MMEtore::msg_sm_3_i_3_r_1_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_3_r_1_t_3_busy, S1MMEtore::msg_sm_3_i_3_r_1_t_3_cnt, S1MMEtore::msg_sm_3_i_3_r_1_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_3_r_1_t_4_busy, S1MMEtore::msg_sm_3_i_3_r_1_t_4_cnt, S1MMEtore::msg_sm_3_i_3_r_1_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_3_r_1_t_5_busy, S1MMEtore::msg_sm_3_i_3_r_1_t_5_cnt, S1MMEtore::msg_sm_3_i_3_r_1_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_3_r_1_t_6_busy, S1MMEtore::msg_sm_3_i_3_r_1_t_6_cnt, S1MMEtore::msg_sm_3_i_3_r_1_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_3_r_1_t_7_busy, S1MMEtore::msg_sm_3_i_3_r_1_t_7_cnt, S1MMEtore::msg_sm_3_i_3_r_1_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_3_r_1_t_8_busy, S1MMEtore::msg_sm_3_i_3_r_1_t_8_cnt, S1MMEtore::msg_sm_3_i_3_r_1_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_3_r_1_t_9_busy, S1MMEtore::msg_sm_3_i_3_r_1_t_9_cnt, S1MMEtore::msg_sm_3_i_3_r_1_t_9, pSctp);
				break;
			}
			break;
	}
}

VOID SctpMessageBroker::pushToQueue_i_3_r_2(Sctp *pSctp, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_3_r_2_t_0_busy, S1MMEtore::msg_sm_0_i_3_r_2_t_0_cnt, S1MMEtore::msg_sm_0_i_3_r_2_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_3_r_2_t_1_busy, S1MMEtore::msg_sm_0_i_3_r_2_t_1_cnt, S1MMEtore::msg_sm_0_i_3_r_2_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_3_r_2_t_2_busy, S1MMEtore::msg_sm_0_i_3_r_2_t_2_cnt, S1MMEtore::msg_sm_0_i_3_r_2_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_3_r_2_t_3_busy, S1MMEtore::msg_sm_0_i_3_r_2_t_3_cnt, S1MMEtore::msg_sm_0_i_3_r_2_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_3_r_2_t_4_busy, S1MMEtore::msg_sm_0_i_3_r_2_t_4_cnt, S1MMEtore::msg_sm_0_i_3_r_2_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_3_r_2_t_5_busy, S1MMEtore::msg_sm_0_i_3_r_2_t_5_cnt, S1MMEtore::msg_sm_0_i_3_r_2_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_3_r_2_t_6_busy, S1MMEtore::msg_sm_0_i_3_r_2_t_6_cnt, S1MMEtore::msg_sm_0_i_3_r_2_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_3_r_2_t_7_busy, S1MMEtore::msg_sm_0_i_3_r_2_t_7_cnt, S1MMEtore::msg_sm_0_i_3_r_2_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_3_r_2_t_8_busy, S1MMEtore::msg_sm_0_i_3_r_2_t_8_cnt, S1MMEtore::msg_sm_0_i_3_r_2_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_3_r_2_t_9_busy, S1MMEtore::msg_sm_0_i_3_r_2_t_9_cnt, S1MMEtore::msg_sm_0_i_3_r_2_t_9, pSctp);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_3_r_2_t_0_busy, S1MMEtore::msg_sm_1_i_3_r_2_t_0_cnt, S1MMEtore::msg_sm_1_i_3_r_2_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_3_r_2_t_1_busy, S1MMEtore::msg_sm_1_i_3_r_2_t_1_cnt, S1MMEtore::msg_sm_1_i_3_r_2_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_3_r_2_t_2_busy, S1MMEtore::msg_sm_1_i_3_r_2_t_2_cnt, S1MMEtore::msg_sm_1_i_3_r_2_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_3_r_2_t_3_busy, S1MMEtore::msg_sm_1_i_3_r_2_t_3_cnt, S1MMEtore::msg_sm_1_i_3_r_2_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_3_r_2_t_4_busy, S1MMEtore::msg_sm_1_i_3_r_2_t_4_cnt, S1MMEtore::msg_sm_1_i_3_r_2_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_3_r_2_t_5_busy, S1MMEtore::msg_sm_1_i_3_r_2_t_5_cnt, S1MMEtore::msg_sm_1_i_3_r_2_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_3_r_2_t_6_busy, S1MMEtore::msg_sm_1_i_3_r_2_t_6_cnt, S1MMEtore::msg_sm_1_i_3_r_2_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_3_r_2_t_7_busy, S1MMEtore::msg_sm_1_i_3_r_2_t_7_cnt, S1MMEtore::msg_sm_1_i_3_r_2_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_3_r_2_t_8_busy, S1MMEtore::msg_sm_1_i_3_r_2_t_8_cnt, S1MMEtore::msg_sm_1_i_3_r_2_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_3_r_2_t_9_busy, S1MMEtore::msg_sm_1_i_3_r_2_t_9_cnt, S1MMEtore::msg_sm_1_i_3_r_2_t_9, pSctp);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_3_r_2_t_0_busy, S1MMEtore::msg_sm_2_i_3_r_2_t_0_cnt, S1MMEtore::msg_sm_2_i_3_r_2_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_3_r_2_t_1_busy, S1MMEtore::msg_sm_2_i_3_r_2_t_1_cnt, S1MMEtore::msg_sm_2_i_3_r_2_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_3_r_2_t_2_busy, S1MMEtore::msg_sm_2_i_3_r_2_t_2_cnt, S1MMEtore::msg_sm_2_i_3_r_2_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_3_r_2_t_3_busy, S1MMEtore::msg_sm_2_i_3_r_2_t_3_cnt, S1MMEtore::msg_sm_2_i_3_r_2_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_3_r_2_t_4_busy, S1MMEtore::msg_sm_2_i_3_r_2_t_4_cnt, S1MMEtore::msg_sm_2_i_3_r_2_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_3_r_2_t_5_busy, S1MMEtore::msg_sm_2_i_3_r_2_t_5_cnt, S1MMEtore::msg_sm_2_i_3_r_2_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_3_r_2_t_6_busy, S1MMEtore::msg_sm_2_i_3_r_2_t_6_cnt, S1MMEtore::msg_sm_2_i_3_r_2_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_3_r_2_t_7_busy, S1MMEtore::msg_sm_2_i_3_r_2_t_7_cnt, S1MMEtore::msg_sm_2_i_3_r_2_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_3_r_2_t_8_busy, S1MMEtore::msg_sm_2_i_3_r_2_t_8_cnt, S1MMEtore::msg_sm_2_i_3_r_2_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_3_r_2_t_9_busy, S1MMEtore::msg_sm_2_i_3_r_2_t_9_cnt, S1MMEtore::msg_sm_2_i_3_r_2_t_9, pSctp);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_3_r_2_t_0_busy, S1MMEtore::msg_sm_3_i_3_r_2_t_0_cnt, S1MMEtore::msg_sm_3_i_3_r_2_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_3_r_2_t_1_busy, S1MMEtore::msg_sm_3_i_3_r_2_t_1_cnt, S1MMEtore::msg_sm_3_i_3_r_2_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_3_r_2_t_2_busy, S1MMEtore::msg_sm_3_i_3_r_2_t_2_cnt, S1MMEtore::msg_sm_3_i_3_r_2_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_3_r_2_t_3_busy, S1MMEtore::msg_sm_3_i_3_r_2_t_3_cnt, S1MMEtore::msg_sm_3_i_3_r_2_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_3_r_2_t_4_busy, S1MMEtore::msg_sm_3_i_3_r_2_t_4_cnt, S1MMEtore::msg_sm_3_i_3_r_2_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_3_r_2_t_5_busy, S1MMEtore::msg_sm_3_i_3_r_2_t_5_cnt, S1MMEtore::msg_sm_3_i_3_r_2_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_3_r_2_t_6_busy, S1MMEtore::msg_sm_3_i_3_r_2_t_6_cnt, S1MMEtore::msg_sm_3_i_3_r_2_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_3_r_2_t_7_busy, S1MMEtore::msg_sm_3_i_3_r_2_t_7_cnt, S1MMEtore::msg_sm_3_i_3_r_2_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_3_r_2_t_8_busy, S1MMEtore::msg_sm_3_i_3_r_2_t_8_cnt, S1MMEtore::msg_sm_3_i_3_r_2_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_3_r_2_t_9_busy, S1MMEtore::msg_sm_3_i_3_r_2_t_9_cnt, S1MMEtore::msg_sm_3_i_3_r_2_t_9, pSctp);
				break;
			}
			break;
	}
}

VOID SctpMessageBroker::pushToQueue_i_3_r_3(Sctp *pSctp, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_3_r_3_t_0_busy, S1MMEtore::msg_sm_0_i_3_r_3_t_0_cnt, S1MMEtore::msg_sm_0_i_3_r_3_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_3_r_3_t_1_busy, S1MMEtore::msg_sm_0_i_3_r_3_t_1_cnt, S1MMEtore::msg_sm_0_i_3_r_3_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_3_r_3_t_2_busy, S1MMEtore::msg_sm_0_i_3_r_3_t_2_cnt, S1MMEtore::msg_sm_0_i_3_r_3_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_3_r_3_t_3_busy, S1MMEtore::msg_sm_0_i_3_r_3_t_3_cnt, S1MMEtore::msg_sm_0_i_3_r_3_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_3_r_3_t_4_busy, S1MMEtore::msg_sm_0_i_3_r_3_t_4_cnt, S1MMEtore::msg_sm_0_i_3_r_3_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_3_r_3_t_5_busy, S1MMEtore::msg_sm_0_i_3_r_3_t_5_cnt, S1MMEtore::msg_sm_0_i_3_r_3_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_3_r_3_t_6_busy, S1MMEtore::msg_sm_0_i_3_r_3_t_6_cnt, S1MMEtore::msg_sm_0_i_3_r_3_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_3_r_3_t_7_busy, S1MMEtore::msg_sm_0_i_3_r_3_t_7_cnt, S1MMEtore::msg_sm_0_i_3_r_3_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_3_r_3_t_8_busy, S1MMEtore::msg_sm_0_i_3_r_3_t_8_cnt, S1MMEtore::msg_sm_0_i_3_r_3_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_3_r_3_t_9_busy, S1MMEtore::msg_sm_0_i_3_r_3_t_9_cnt, S1MMEtore::msg_sm_0_i_3_r_3_t_9, pSctp);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_3_r_3_t_0_busy, S1MMEtore::msg_sm_1_i_3_r_3_t_0_cnt, S1MMEtore::msg_sm_1_i_3_r_3_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_3_r_3_t_1_busy, S1MMEtore::msg_sm_1_i_3_r_3_t_1_cnt, S1MMEtore::msg_sm_1_i_3_r_3_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_3_r_3_t_2_busy, S1MMEtore::msg_sm_1_i_3_r_3_t_2_cnt, S1MMEtore::msg_sm_1_i_3_r_3_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_3_r_3_t_3_busy, S1MMEtore::msg_sm_1_i_3_r_3_t_3_cnt, S1MMEtore::msg_sm_1_i_3_r_3_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_3_r_3_t_4_busy, S1MMEtore::msg_sm_1_i_3_r_3_t_4_cnt, S1MMEtore::msg_sm_1_i_3_r_3_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_3_r_3_t_5_busy, S1MMEtore::msg_sm_1_i_3_r_3_t_5_cnt, S1MMEtore::msg_sm_1_i_3_r_3_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_3_r_3_t_6_busy, S1MMEtore::msg_sm_1_i_3_r_3_t_6_cnt, S1MMEtore::msg_sm_1_i_3_r_3_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_3_r_3_t_7_busy, S1MMEtore::msg_sm_1_i_3_r_3_t_7_cnt, S1MMEtore::msg_sm_1_i_3_r_3_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_3_r_3_t_8_busy, S1MMEtore::msg_sm_1_i_3_r_3_t_8_cnt, S1MMEtore::msg_sm_1_i_3_r_3_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_3_r_3_t_9_busy, S1MMEtore::msg_sm_1_i_3_r_3_t_9_cnt, S1MMEtore::msg_sm_1_i_3_r_3_t_9, pSctp);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_3_r_3_t_0_busy, S1MMEtore::msg_sm_2_i_3_r_3_t_0_cnt, S1MMEtore::msg_sm_2_i_3_r_3_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_3_r_3_t_1_busy, S1MMEtore::msg_sm_2_i_3_r_3_t_1_cnt, S1MMEtore::msg_sm_2_i_3_r_3_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_3_r_3_t_2_busy, S1MMEtore::msg_sm_2_i_3_r_3_t_2_cnt, S1MMEtore::msg_sm_2_i_3_r_3_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_3_r_3_t_3_busy, S1MMEtore::msg_sm_2_i_3_r_3_t_3_cnt, S1MMEtore::msg_sm_2_i_3_r_3_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_3_r_3_t_4_busy, S1MMEtore::msg_sm_2_i_3_r_3_t_4_cnt, S1MMEtore::msg_sm_2_i_3_r_3_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_3_r_3_t_5_busy, S1MMEtore::msg_sm_2_i_3_r_3_t_5_cnt, S1MMEtore::msg_sm_2_i_3_r_3_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_3_r_3_t_6_busy, S1MMEtore::msg_sm_2_i_3_r_3_t_6_cnt, S1MMEtore::msg_sm_2_i_3_r_3_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_3_r_3_t_7_busy, S1MMEtore::msg_sm_2_i_3_r_3_t_7_cnt, S1MMEtore::msg_sm_2_i_3_r_3_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_3_r_3_t_8_busy, S1MMEtore::msg_sm_2_i_3_r_3_t_8_cnt, S1MMEtore::msg_sm_2_i_3_r_3_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_3_r_3_t_9_busy, S1MMEtore::msg_sm_2_i_3_r_3_t_9_cnt, S1MMEtore::msg_sm_2_i_3_r_3_t_9, pSctp);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_3_r_3_t_0_busy, S1MMEtore::msg_sm_3_i_3_r_3_t_0_cnt, S1MMEtore::msg_sm_3_i_3_r_3_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_3_r_3_t_1_busy, S1MMEtore::msg_sm_3_i_3_r_3_t_1_cnt, S1MMEtore::msg_sm_3_i_3_r_3_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_3_r_3_t_2_busy, S1MMEtore::msg_sm_3_i_3_r_3_t_2_cnt, S1MMEtore::msg_sm_3_i_3_r_3_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_3_r_3_t_3_busy, S1MMEtore::msg_sm_3_i_3_r_3_t_3_cnt, S1MMEtore::msg_sm_3_i_3_r_3_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_3_r_3_t_4_busy, S1MMEtore::msg_sm_3_i_3_r_3_t_4_cnt, S1MMEtore::msg_sm_3_i_3_r_3_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_3_r_3_t_5_busy, S1MMEtore::msg_sm_3_i_3_r_3_t_5_cnt, S1MMEtore::msg_sm_3_i_3_r_3_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_3_r_3_t_6_busy, S1MMEtore::msg_sm_3_i_3_r_3_t_6_cnt, S1MMEtore::msg_sm_3_i_3_r_3_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_3_r_3_t_7_busy, S1MMEtore::msg_sm_3_i_3_r_3_t_7_cnt, S1MMEtore::msg_sm_3_i_3_r_3_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_3_r_3_t_8_busy, S1MMEtore::msg_sm_3_i_3_r_3_t_8_cnt, S1MMEtore::msg_sm_3_i_3_r_3_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_3_r_3_t_9_busy, S1MMEtore::msg_sm_3_i_3_r_3_t_9_cnt, S1MMEtore::msg_sm_3_i_3_r_3_t_9, pSctp);
				break;
			}
			break;
	}
}

VOID SctpMessageBroker::pushToQueue_i_3_r_4(Sctp *pSctp, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_3_r_4_t_0_busy, S1MMEtore::msg_sm_0_i_3_r_4_t_0_cnt, S1MMEtore::msg_sm_0_i_3_r_4_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_3_r_4_t_1_busy, S1MMEtore::msg_sm_0_i_3_r_4_t_1_cnt, S1MMEtore::msg_sm_0_i_3_r_4_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_3_r_4_t_2_busy, S1MMEtore::msg_sm_0_i_3_r_4_t_2_cnt, S1MMEtore::msg_sm_0_i_3_r_4_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_3_r_4_t_3_busy, S1MMEtore::msg_sm_0_i_3_r_4_t_3_cnt, S1MMEtore::msg_sm_0_i_3_r_4_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_3_r_4_t_4_busy, S1MMEtore::msg_sm_0_i_3_r_4_t_4_cnt, S1MMEtore::msg_sm_0_i_3_r_4_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_3_r_4_t_5_busy, S1MMEtore::msg_sm_0_i_3_r_4_t_5_cnt, S1MMEtore::msg_sm_0_i_3_r_4_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_3_r_4_t_6_busy, S1MMEtore::msg_sm_0_i_3_r_4_t_6_cnt, S1MMEtore::msg_sm_0_i_3_r_4_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_3_r_4_t_7_busy, S1MMEtore::msg_sm_0_i_3_r_4_t_7_cnt, S1MMEtore::msg_sm_0_i_3_r_4_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_3_r_4_t_8_busy, S1MMEtore::msg_sm_0_i_3_r_4_t_8_cnt, S1MMEtore::msg_sm_0_i_3_r_4_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_3_r_4_t_9_busy, S1MMEtore::msg_sm_0_i_3_r_4_t_9_cnt, S1MMEtore::msg_sm_0_i_3_r_4_t_9, pSctp);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_3_r_4_t_0_busy, S1MMEtore::msg_sm_1_i_3_r_4_t_0_cnt, S1MMEtore::msg_sm_1_i_3_r_4_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_3_r_4_t_1_busy, S1MMEtore::msg_sm_1_i_3_r_4_t_1_cnt, S1MMEtore::msg_sm_1_i_3_r_4_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_3_r_4_t_2_busy, S1MMEtore::msg_sm_1_i_3_r_4_t_2_cnt, S1MMEtore::msg_sm_1_i_3_r_4_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_3_r_4_t_3_busy, S1MMEtore::msg_sm_1_i_3_r_4_t_3_cnt, S1MMEtore::msg_sm_1_i_3_r_4_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_3_r_4_t_4_busy, S1MMEtore::msg_sm_1_i_3_r_4_t_4_cnt, S1MMEtore::msg_sm_1_i_3_r_4_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_3_r_4_t_5_busy, S1MMEtore::msg_sm_1_i_3_r_4_t_5_cnt, S1MMEtore::msg_sm_1_i_3_r_4_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_3_r_4_t_6_busy, S1MMEtore::msg_sm_1_i_3_r_4_t_6_cnt, S1MMEtore::msg_sm_1_i_3_r_4_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_3_r_4_t_7_busy, S1MMEtore::msg_sm_1_i_3_r_4_t_7_cnt, S1MMEtore::msg_sm_1_i_3_r_4_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_3_r_4_t_8_busy, S1MMEtore::msg_sm_1_i_3_r_4_t_8_cnt, S1MMEtore::msg_sm_1_i_3_r_4_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_3_r_4_t_9_busy, S1MMEtore::msg_sm_1_i_3_r_4_t_9_cnt, S1MMEtore::msg_sm_1_i_3_r_4_t_9, pSctp);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_3_r_4_t_0_busy, S1MMEtore::msg_sm_2_i_3_r_4_t_0_cnt, S1MMEtore::msg_sm_2_i_3_r_4_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_3_r_4_t_1_busy, S1MMEtore::msg_sm_2_i_3_r_4_t_1_cnt, S1MMEtore::msg_sm_2_i_3_r_4_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_3_r_4_t_2_busy, S1MMEtore::msg_sm_2_i_3_r_4_t_2_cnt, S1MMEtore::msg_sm_2_i_3_r_4_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_3_r_4_t_3_busy, S1MMEtore::msg_sm_2_i_3_r_4_t_3_cnt, S1MMEtore::msg_sm_2_i_3_r_4_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_3_r_4_t_4_busy, S1MMEtore::msg_sm_2_i_3_r_4_t_4_cnt, S1MMEtore::msg_sm_2_i_3_r_4_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_3_r_4_t_5_busy, S1MMEtore::msg_sm_2_i_3_r_4_t_5_cnt, S1MMEtore::msg_sm_2_i_3_r_4_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_3_r_4_t_6_busy, S1MMEtore::msg_sm_2_i_3_r_4_t_6_cnt, S1MMEtore::msg_sm_2_i_3_r_4_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_3_r_4_t_7_busy, S1MMEtore::msg_sm_2_i_3_r_4_t_7_cnt, S1MMEtore::msg_sm_2_i_3_r_4_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_3_r_4_t_8_busy, S1MMEtore::msg_sm_2_i_3_r_4_t_8_cnt, S1MMEtore::msg_sm_2_i_3_r_4_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_3_r_4_t_9_busy, S1MMEtore::msg_sm_2_i_3_r_4_t_9_cnt, S1MMEtore::msg_sm_2_i_3_r_4_t_9, pSctp);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_3_r_4_t_0_busy, S1MMEtore::msg_sm_3_i_3_r_4_t_0_cnt, S1MMEtore::msg_sm_3_i_3_r_4_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_3_r_4_t_1_busy, S1MMEtore::msg_sm_3_i_3_r_4_t_1_cnt, S1MMEtore::msg_sm_3_i_3_r_4_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_3_r_4_t_2_busy, S1MMEtore::msg_sm_3_i_3_r_4_t_2_cnt, S1MMEtore::msg_sm_3_i_3_r_4_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_3_r_4_t_3_busy, S1MMEtore::msg_sm_3_i_3_r_4_t_3_cnt, S1MMEtore::msg_sm_3_i_3_r_4_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_3_r_4_t_4_busy, S1MMEtore::msg_sm_3_i_3_r_4_t_4_cnt, S1MMEtore::msg_sm_3_i_3_r_4_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_3_r_4_t_5_busy, S1MMEtore::msg_sm_3_i_3_r_4_t_5_cnt, S1MMEtore::msg_sm_3_i_3_r_4_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_3_r_4_t_6_busy, S1MMEtore::msg_sm_3_i_3_r_4_t_6_cnt, S1MMEtore::msg_sm_3_i_3_r_4_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_3_r_4_t_7_busy, S1MMEtore::msg_sm_3_i_3_r_4_t_7_cnt, S1MMEtore::msg_sm_3_i_3_r_4_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_3_r_4_t_8_busy, S1MMEtore::msg_sm_3_i_3_r_4_t_8_cnt, S1MMEtore::msg_sm_3_i_3_r_4_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_3_r_4_t_9_busy, S1MMEtore::msg_sm_3_i_3_r_4_t_9_cnt, S1MMEtore::msg_sm_3_i_3_r_4_t_9, pSctp);
				break;
			}
			break;
	}
}

VOID SctpMessageBroker::pushToQueue_i_3_r_5(Sctp *pSctp, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_3_r_5_t_0_busy, S1MMEtore::msg_sm_0_i_3_r_5_t_0_cnt, S1MMEtore::msg_sm_0_i_3_r_5_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_3_r_5_t_1_busy, S1MMEtore::msg_sm_0_i_3_r_5_t_1_cnt, S1MMEtore::msg_sm_0_i_3_r_5_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_3_r_5_t_2_busy, S1MMEtore::msg_sm_0_i_3_r_5_t_2_cnt, S1MMEtore::msg_sm_0_i_3_r_5_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_3_r_5_t_3_busy, S1MMEtore::msg_sm_0_i_3_r_5_t_3_cnt, S1MMEtore::msg_sm_0_i_3_r_5_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_3_r_5_t_4_busy, S1MMEtore::msg_sm_0_i_3_r_5_t_4_cnt, S1MMEtore::msg_sm_0_i_3_r_5_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_3_r_5_t_5_busy, S1MMEtore::msg_sm_0_i_3_r_5_t_5_cnt, S1MMEtore::msg_sm_0_i_3_r_5_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_3_r_5_t_6_busy, S1MMEtore::msg_sm_0_i_3_r_5_t_6_cnt, S1MMEtore::msg_sm_0_i_3_r_5_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_3_r_5_t_7_busy, S1MMEtore::msg_sm_0_i_3_r_5_t_7_cnt, S1MMEtore::msg_sm_0_i_3_r_5_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_3_r_5_t_8_busy, S1MMEtore::msg_sm_0_i_3_r_5_t_8_cnt, S1MMEtore::msg_sm_0_i_3_r_5_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_3_r_5_t_9_busy, S1MMEtore::msg_sm_0_i_3_r_5_t_9_cnt, S1MMEtore::msg_sm_0_i_3_r_5_t_9, pSctp);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_3_r_5_t_0_busy, S1MMEtore::msg_sm_1_i_3_r_5_t_0_cnt, S1MMEtore::msg_sm_1_i_3_r_5_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_3_r_5_t_1_busy, S1MMEtore::msg_sm_1_i_3_r_5_t_1_cnt, S1MMEtore::msg_sm_1_i_3_r_5_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_3_r_5_t_2_busy, S1MMEtore::msg_sm_1_i_3_r_5_t_2_cnt, S1MMEtore::msg_sm_1_i_3_r_5_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_3_r_5_t_3_busy, S1MMEtore::msg_sm_1_i_3_r_5_t_3_cnt, S1MMEtore::msg_sm_1_i_3_r_5_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_3_r_5_t_4_busy, S1MMEtore::msg_sm_1_i_3_r_5_t_4_cnt, S1MMEtore::msg_sm_1_i_3_r_5_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_3_r_5_t_5_busy, S1MMEtore::msg_sm_1_i_3_r_5_t_5_cnt, S1MMEtore::msg_sm_1_i_3_r_5_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_3_r_5_t_6_busy, S1MMEtore::msg_sm_1_i_3_r_5_t_6_cnt, S1MMEtore::msg_sm_1_i_3_r_5_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_3_r_5_t_7_busy, S1MMEtore::msg_sm_1_i_3_r_5_t_7_cnt, S1MMEtore::msg_sm_1_i_3_r_5_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_3_r_5_t_8_busy, S1MMEtore::msg_sm_1_i_3_r_5_t_8_cnt, S1MMEtore::msg_sm_1_i_3_r_5_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_3_r_5_t_9_busy, S1MMEtore::msg_sm_1_i_3_r_5_t_9_cnt, S1MMEtore::msg_sm_1_i_3_r_5_t_9, pSctp);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_3_r_5_t_0_busy, S1MMEtore::msg_sm_2_i_3_r_5_t_0_cnt, S1MMEtore::msg_sm_2_i_3_r_5_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_3_r_5_t_1_busy, S1MMEtore::msg_sm_2_i_3_r_5_t_1_cnt, S1MMEtore::msg_sm_2_i_3_r_5_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_3_r_5_t_2_busy, S1MMEtore::msg_sm_2_i_3_r_5_t_2_cnt, S1MMEtore::msg_sm_2_i_3_r_5_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_3_r_5_t_3_busy, S1MMEtore::msg_sm_2_i_3_r_5_t_3_cnt, S1MMEtore::msg_sm_2_i_3_r_5_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_3_r_5_t_4_busy, S1MMEtore::msg_sm_2_i_3_r_5_t_4_cnt, S1MMEtore::msg_sm_2_i_3_r_5_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_3_r_5_t_5_busy, S1MMEtore::msg_sm_2_i_3_r_5_t_5_cnt, S1MMEtore::msg_sm_2_i_3_r_5_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_3_r_5_t_6_busy, S1MMEtore::msg_sm_2_i_3_r_5_t_6_cnt, S1MMEtore::msg_sm_2_i_3_r_5_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_3_r_5_t_7_busy, S1MMEtore::msg_sm_2_i_3_r_5_t_7_cnt, S1MMEtore::msg_sm_2_i_3_r_5_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_3_r_5_t_8_busy, S1MMEtore::msg_sm_2_i_3_r_5_t_8_cnt, S1MMEtore::msg_sm_2_i_3_r_5_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_3_r_5_t_9_busy, S1MMEtore::msg_sm_2_i_3_r_5_t_9_cnt, S1MMEtore::msg_sm_2_i_3_r_5_t_9, pSctp);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_3_r_5_t_0_busy, S1MMEtore::msg_sm_3_i_3_r_5_t_0_cnt, S1MMEtore::msg_sm_3_i_3_r_5_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_3_r_5_t_1_busy, S1MMEtore::msg_sm_3_i_3_r_5_t_1_cnt, S1MMEtore::msg_sm_3_i_3_r_5_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_3_r_5_t_2_busy, S1MMEtore::msg_sm_3_i_3_r_5_t_2_cnt, S1MMEtore::msg_sm_3_i_3_r_5_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_3_r_5_t_3_busy, S1MMEtore::msg_sm_3_i_3_r_5_t_3_cnt, S1MMEtore::msg_sm_3_i_3_r_5_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_3_r_5_t_4_busy, S1MMEtore::msg_sm_3_i_3_r_5_t_4_cnt, S1MMEtore::msg_sm_3_i_3_r_5_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_3_r_5_t_5_busy, S1MMEtore::msg_sm_3_i_3_r_5_t_5_cnt, S1MMEtore::msg_sm_3_i_3_r_5_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_3_r_5_t_6_busy, S1MMEtore::msg_sm_3_i_3_r_5_t_6_cnt, S1MMEtore::msg_sm_3_i_3_r_5_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_3_r_5_t_7_busy, S1MMEtore::msg_sm_3_i_3_r_5_t_7_cnt, S1MMEtore::msg_sm_3_i_3_r_5_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_3_r_5_t_8_busy, S1MMEtore::msg_sm_3_i_3_r_5_t_8_cnt, S1MMEtore::msg_sm_3_i_3_r_5_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_3_r_5_t_9_busy, S1MMEtore::msg_sm_3_i_3_r_5_t_9_cnt, S1MMEtore::msg_sm_3_i_3_r_5_t_9, pSctp);
				break;
			}
			break;
	}
}

VOID SctpMessageBroker::pushToQueue_i_3_r_6(Sctp *pSctp, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_3_r_6_t_0_busy, S1MMEtore::msg_sm_0_i_3_r_6_t_0_cnt, S1MMEtore::msg_sm_0_i_3_r_6_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_3_r_6_t_1_busy, S1MMEtore::msg_sm_0_i_3_r_6_t_1_cnt, S1MMEtore::msg_sm_0_i_3_r_6_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_3_r_6_t_2_busy, S1MMEtore::msg_sm_0_i_3_r_6_t_2_cnt, S1MMEtore::msg_sm_0_i_3_r_6_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_3_r_6_t_3_busy, S1MMEtore::msg_sm_0_i_3_r_6_t_3_cnt, S1MMEtore::msg_sm_0_i_3_r_6_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_3_r_6_t_4_busy, S1MMEtore::msg_sm_0_i_3_r_6_t_4_cnt, S1MMEtore::msg_sm_0_i_3_r_6_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_3_r_6_t_5_busy, S1MMEtore::msg_sm_0_i_3_r_6_t_5_cnt, S1MMEtore::msg_sm_0_i_3_r_6_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_3_r_6_t_6_busy, S1MMEtore::msg_sm_0_i_3_r_6_t_6_cnt, S1MMEtore::msg_sm_0_i_3_r_6_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_3_r_6_t_7_busy, S1MMEtore::msg_sm_0_i_3_r_6_t_7_cnt, S1MMEtore::msg_sm_0_i_3_r_6_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_3_r_6_t_8_busy, S1MMEtore::msg_sm_0_i_3_r_6_t_8_cnt, S1MMEtore::msg_sm_0_i_3_r_6_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_3_r_6_t_9_busy, S1MMEtore::msg_sm_0_i_3_r_6_t_9_cnt, S1MMEtore::msg_sm_0_i_3_r_6_t_9, pSctp);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_3_r_6_t_0_busy, S1MMEtore::msg_sm_1_i_3_r_6_t_0_cnt, S1MMEtore::msg_sm_1_i_3_r_6_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_3_r_6_t_1_busy, S1MMEtore::msg_sm_1_i_3_r_6_t_1_cnt, S1MMEtore::msg_sm_1_i_3_r_6_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_3_r_6_t_2_busy, S1MMEtore::msg_sm_1_i_3_r_6_t_2_cnt, S1MMEtore::msg_sm_1_i_3_r_6_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_3_r_6_t_3_busy, S1MMEtore::msg_sm_1_i_3_r_6_t_3_cnt, S1MMEtore::msg_sm_1_i_3_r_6_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_3_r_6_t_4_busy, S1MMEtore::msg_sm_1_i_3_r_6_t_4_cnt, S1MMEtore::msg_sm_1_i_3_r_6_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_3_r_6_t_5_busy, S1MMEtore::msg_sm_1_i_3_r_6_t_5_cnt, S1MMEtore::msg_sm_1_i_3_r_6_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_3_r_6_t_6_busy, S1MMEtore::msg_sm_1_i_3_r_6_t_6_cnt, S1MMEtore::msg_sm_1_i_3_r_6_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_3_r_6_t_7_busy, S1MMEtore::msg_sm_1_i_3_r_6_t_7_cnt, S1MMEtore::msg_sm_1_i_3_r_6_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_3_r_6_t_8_busy, S1MMEtore::msg_sm_1_i_3_r_6_t_8_cnt, S1MMEtore::msg_sm_1_i_3_r_6_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_3_r_6_t_9_busy, S1MMEtore::msg_sm_1_i_3_r_6_t_9_cnt, S1MMEtore::msg_sm_1_i_3_r_6_t_9, pSctp);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_3_r_6_t_0_busy, S1MMEtore::msg_sm_2_i_3_r_6_t_0_cnt, S1MMEtore::msg_sm_2_i_3_r_6_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_3_r_6_t_1_busy, S1MMEtore::msg_sm_2_i_3_r_6_t_1_cnt, S1MMEtore::msg_sm_2_i_3_r_6_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_3_r_6_t_2_busy, S1MMEtore::msg_sm_2_i_3_r_6_t_2_cnt, S1MMEtore::msg_sm_2_i_3_r_6_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_3_r_6_t_3_busy, S1MMEtore::msg_sm_2_i_3_r_6_t_3_cnt, S1MMEtore::msg_sm_2_i_3_r_6_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_3_r_6_t_4_busy, S1MMEtore::msg_sm_2_i_3_r_6_t_4_cnt, S1MMEtore::msg_sm_2_i_3_r_6_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_3_r_6_t_5_busy, S1MMEtore::msg_sm_2_i_3_r_6_t_5_cnt, S1MMEtore::msg_sm_2_i_3_r_6_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_3_r_6_t_6_busy, S1MMEtore::msg_sm_2_i_3_r_6_t_6_cnt, S1MMEtore::msg_sm_2_i_3_r_6_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_3_r_6_t_7_busy, S1MMEtore::msg_sm_2_i_3_r_6_t_7_cnt, S1MMEtore::msg_sm_2_i_3_r_6_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_3_r_6_t_8_busy, S1MMEtore::msg_sm_2_i_3_r_6_t_8_cnt, S1MMEtore::msg_sm_2_i_3_r_6_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_3_r_6_t_9_busy, S1MMEtore::msg_sm_2_i_3_r_6_t_9_cnt, S1MMEtore::msg_sm_2_i_3_r_6_t_9, pSctp);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_3_r_6_t_0_busy, S1MMEtore::msg_sm_3_i_3_r_6_t_0_cnt, S1MMEtore::msg_sm_3_i_3_r_6_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_3_r_6_t_1_busy, S1MMEtore::msg_sm_3_i_3_r_6_t_1_cnt, S1MMEtore::msg_sm_3_i_3_r_6_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_3_r_6_t_2_busy, S1MMEtore::msg_sm_3_i_3_r_6_t_2_cnt, S1MMEtore::msg_sm_3_i_3_r_6_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_3_r_6_t_3_busy, S1MMEtore::msg_sm_3_i_3_r_6_t_3_cnt, S1MMEtore::msg_sm_3_i_3_r_6_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_3_r_6_t_4_busy, S1MMEtore::msg_sm_3_i_3_r_6_t_4_cnt, S1MMEtore::msg_sm_3_i_3_r_6_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_3_r_6_t_5_busy, S1MMEtore::msg_sm_3_i_3_r_6_t_5_cnt, S1MMEtore::msg_sm_3_i_3_r_6_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_3_r_6_t_6_busy, S1MMEtore::msg_sm_3_i_3_r_6_t_6_cnt, S1MMEtore::msg_sm_3_i_3_r_6_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_3_r_6_t_7_busy, S1MMEtore::msg_sm_3_i_3_r_6_t_7_cnt, S1MMEtore::msg_sm_3_i_3_r_6_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_3_r_6_t_8_busy, S1MMEtore::msg_sm_3_i_3_r_6_t_8_cnt, S1MMEtore::msg_sm_3_i_3_r_6_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_3_r_6_t_9_busy, S1MMEtore::msg_sm_3_i_3_r_6_t_9_cnt, S1MMEtore::msg_sm_3_i_3_r_6_t_9, pSctp);
				break;
			}
			break;
	}
}

VOID SctpMessageBroker::pushToQueue_i_3_r_7(Sctp *pSctp, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_3_r_7_t_0_busy, S1MMEtore::msg_sm_0_i_3_r_7_t_0_cnt, S1MMEtore::msg_sm_0_i_3_r_7_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_3_r_7_t_1_busy, S1MMEtore::msg_sm_0_i_3_r_7_t_1_cnt, S1MMEtore::msg_sm_0_i_3_r_7_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_3_r_7_t_2_busy, S1MMEtore::msg_sm_0_i_3_r_7_t_2_cnt, S1MMEtore::msg_sm_0_i_3_r_7_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_3_r_7_t_3_busy, S1MMEtore::msg_sm_0_i_3_r_7_t_3_cnt, S1MMEtore::msg_sm_0_i_3_r_7_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_3_r_7_t_4_busy, S1MMEtore::msg_sm_0_i_3_r_7_t_4_cnt, S1MMEtore::msg_sm_0_i_3_r_7_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_3_r_7_t_5_busy, S1MMEtore::msg_sm_0_i_3_r_7_t_5_cnt, S1MMEtore::msg_sm_0_i_3_r_7_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_3_r_7_t_6_busy, S1MMEtore::msg_sm_0_i_3_r_7_t_6_cnt, S1MMEtore::msg_sm_0_i_3_r_7_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_3_r_7_t_7_busy, S1MMEtore::msg_sm_0_i_3_r_7_t_7_cnt, S1MMEtore::msg_sm_0_i_3_r_7_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_3_r_7_t_8_busy, S1MMEtore::msg_sm_0_i_3_r_7_t_8_cnt, S1MMEtore::msg_sm_0_i_3_r_7_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_3_r_7_t_9_busy, S1MMEtore::msg_sm_0_i_3_r_7_t_9_cnt, S1MMEtore::msg_sm_0_i_3_r_7_t_9, pSctp);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_3_r_7_t_0_busy, S1MMEtore::msg_sm_1_i_3_r_7_t_0_cnt, S1MMEtore::msg_sm_1_i_3_r_7_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_3_r_7_t_1_busy, S1MMEtore::msg_sm_1_i_3_r_7_t_1_cnt, S1MMEtore::msg_sm_1_i_3_r_7_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_3_r_7_t_2_busy, S1MMEtore::msg_sm_1_i_3_r_7_t_2_cnt, S1MMEtore::msg_sm_1_i_3_r_7_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_3_r_7_t_3_busy, S1MMEtore::msg_sm_1_i_3_r_7_t_3_cnt, S1MMEtore::msg_sm_1_i_3_r_7_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_3_r_7_t_4_busy, S1MMEtore::msg_sm_1_i_3_r_7_t_4_cnt, S1MMEtore::msg_sm_1_i_3_r_7_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_3_r_7_t_5_busy, S1MMEtore::msg_sm_1_i_3_r_7_t_5_cnt, S1MMEtore::msg_sm_1_i_3_r_7_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_3_r_7_t_6_busy, S1MMEtore::msg_sm_1_i_3_r_7_t_6_cnt, S1MMEtore::msg_sm_1_i_3_r_7_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_3_r_7_t_7_busy, S1MMEtore::msg_sm_1_i_3_r_7_t_7_cnt, S1MMEtore::msg_sm_1_i_3_r_7_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_3_r_7_t_8_busy, S1MMEtore::msg_sm_1_i_3_r_7_t_8_cnt, S1MMEtore::msg_sm_1_i_3_r_7_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_3_r_7_t_9_busy, S1MMEtore::msg_sm_1_i_3_r_7_t_9_cnt, S1MMEtore::msg_sm_1_i_3_r_7_t_9, pSctp);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_3_r_7_t_0_busy, S1MMEtore::msg_sm_2_i_3_r_7_t_0_cnt, S1MMEtore::msg_sm_2_i_3_r_7_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_3_r_7_t_1_busy, S1MMEtore::msg_sm_2_i_3_r_7_t_1_cnt, S1MMEtore::msg_sm_2_i_3_r_7_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_3_r_7_t_2_busy, S1MMEtore::msg_sm_2_i_3_r_7_t_2_cnt, S1MMEtore::msg_sm_2_i_3_r_7_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_3_r_7_t_3_busy, S1MMEtore::msg_sm_2_i_3_r_7_t_3_cnt, S1MMEtore::msg_sm_2_i_3_r_7_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_3_r_7_t_4_busy, S1MMEtore::msg_sm_2_i_3_r_7_t_4_cnt, S1MMEtore::msg_sm_2_i_3_r_7_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_3_r_7_t_5_busy, S1MMEtore::msg_sm_2_i_3_r_7_t_5_cnt, S1MMEtore::msg_sm_2_i_3_r_7_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_3_r_7_t_6_busy, S1MMEtore::msg_sm_2_i_3_r_7_t_6_cnt, S1MMEtore::msg_sm_2_i_3_r_7_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_3_r_7_t_7_busy, S1MMEtore::msg_sm_2_i_3_r_7_t_7_cnt, S1MMEtore::msg_sm_2_i_3_r_7_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_3_r_7_t_8_busy, S1MMEtore::msg_sm_2_i_3_r_7_t_8_cnt, S1MMEtore::msg_sm_2_i_3_r_7_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_3_r_7_t_9_busy, S1MMEtore::msg_sm_2_i_3_r_7_t_9_cnt, S1MMEtore::msg_sm_2_i_3_r_7_t_9, pSctp);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_3_r_7_t_0_busy, S1MMEtore::msg_sm_3_i_3_r_7_t_0_cnt, S1MMEtore::msg_sm_3_i_3_r_7_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_3_r_7_t_1_busy, S1MMEtore::msg_sm_3_i_3_r_7_t_1_cnt, S1MMEtore::msg_sm_3_i_3_r_7_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_3_r_7_t_2_busy, S1MMEtore::msg_sm_3_i_3_r_7_t_2_cnt, S1MMEtore::msg_sm_3_i_3_r_7_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_3_r_7_t_3_busy, S1MMEtore::msg_sm_3_i_3_r_7_t_3_cnt, S1MMEtore::msg_sm_3_i_3_r_7_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_3_r_7_t_4_busy, S1MMEtore::msg_sm_3_i_3_r_7_t_4_cnt, S1MMEtore::msg_sm_3_i_3_r_7_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_3_r_7_t_5_busy, S1MMEtore::msg_sm_3_i_3_r_7_t_5_cnt, S1MMEtore::msg_sm_3_i_3_r_7_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_3_r_7_t_6_busy, S1MMEtore::msg_sm_3_i_3_r_7_t_6_cnt, S1MMEtore::msg_sm_3_i_3_r_7_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_3_r_7_t_7_busy, S1MMEtore::msg_sm_3_i_3_r_7_t_7_cnt, S1MMEtore::msg_sm_3_i_3_r_7_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_3_r_7_t_8_busy, S1MMEtore::msg_sm_3_i_3_r_7_t_8_cnt, S1MMEtore::msg_sm_3_i_3_r_7_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_3_r_7_t_9_busy, S1MMEtore::msg_sm_3_i_3_r_7_t_9_cnt, S1MMEtore::msg_sm_3_i_3_r_7_t_9, pSctp);
				break;
			}
			break;
	}
}


VOID SctpMessageBroker::pushToQueue_i_4_r_0(Sctp *pSctp, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_4_r_0_t_0_busy, S1MMEtore::msg_sm_0_i_4_r_0_t_0_cnt, S1MMEtore::msg_sm_0_i_4_r_0_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_4_r_0_t_1_busy, S1MMEtore::msg_sm_0_i_4_r_0_t_1_cnt, S1MMEtore::msg_sm_0_i_4_r_0_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_4_r_0_t_2_busy, S1MMEtore::msg_sm_0_i_4_r_0_t_2_cnt, S1MMEtore::msg_sm_0_i_4_r_0_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_4_r_0_t_3_busy, S1MMEtore::msg_sm_0_i_4_r_0_t_3_cnt, S1MMEtore::msg_sm_0_i_4_r_0_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_4_r_0_t_4_busy, S1MMEtore::msg_sm_0_i_4_r_0_t_4_cnt, S1MMEtore::msg_sm_0_i_4_r_0_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_4_r_0_t_5_busy, S1MMEtore::msg_sm_0_i_4_r_0_t_5_cnt, S1MMEtore::msg_sm_0_i_4_r_0_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_4_r_0_t_6_busy, S1MMEtore::msg_sm_0_i_4_r_0_t_6_cnt, S1MMEtore::msg_sm_0_i_4_r_0_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_4_r_0_t_7_busy, S1MMEtore::msg_sm_0_i_4_r_0_t_7_cnt, S1MMEtore::msg_sm_0_i_4_r_0_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_4_r_0_t_8_busy, S1MMEtore::msg_sm_0_i_4_r_0_t_8_cnt, S1MMEtore::msg_sm_0_i_4_r_0_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_4_r_0_t_9_busy, S1MMEtore::msg_sm_0_i_4_r_0_t_9_cnt, S1MMEtore::msg_sm_0_i_4_r_0_t_9, pSctp);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_4_r_0_t_0_busy, S1MMEtore::msg_sm_1_i_4_r_0_t_0_cnt, S1MMEtore::msg_sm_1_i_4_r_0_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_4_r_0_t_1_busy, S1MMEtore::msg_sm_1_i_4_r_0_t_1_cnt, S1MMEtore::msg_sm_1_i_4_r_0_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_4_r_0_t_2_busy, S1MMEtore::msg_sm_1_i_4_r_0_t_2_cnt, S1MMEtore::msg_sm_1_i_4_r_0_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_4_r_0_t_3_busy, S1MMEtore::msg_sm_1_i_4_r_0_t_3_cnt, S1MMEtore::msg_sm_1_i_4_r_0_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_4_r_0_t_4_busy, S1MMEtore::msg_sm_1_i_4_r_0_t_4_cnt, S1MMEtore::msg_sm_1_i_4_r_0_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_4_r_0_t_5_busy, S1MMEtore::msg_sm_1_i_4_r_0_t_5_cnt, S1MMEtore::msg_sm_1_i_4_r_0_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_4_r_0_t_6_busy, S1MMEtore::msg_sm_1_i_4_r_0_t_6_cnt, S1MMEtore::msg_sm_1_i_4_r_0_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_4_r_0_t_7_busy, S1MMEtore::msg_sm_1_i_4_r_0_t_7_cnt, S1MMEtore::msg_sm_1_i_4_r_0_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_4_r_0_t_8_busy, S1MMEtore::msg_sm_1_i_4_r_0_t_8_cnt, S1MMEtore::msg_sm_1_i_4_r_0_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_4_r_0_t_9_busy, S1MMEtore::msg_sm_1_i_4_r_0_t_9_cnt, S1MMEtore::msg_sm_1_i_4_r_0_t_9, pSctp);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_4_r_0_t_0_busy, S1MMEtore::msg_sm_2_i_4_r_0_t_0_cnt, S1MMEtore::msg_sm_2_i_4_r_0_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_4_r_0_t_1_busy, S1MMEtore::msg_sm_2_i_4_r_0_t_1_cnt, S1MMEtore::msg_sm_2_i_4_r_0_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_4_r_0_t_2_busy, S1MMEtore::msg_sm_2_i_4_r_0_t_2_cnt, S1MMEtore::msg_sm_2_i_4_r_0_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_4_r_0_t_3_busy, S1MMEtore::msg_sm_2_i_4_r_0_t_3_cnt, S1MMEtore::msg_sm_2_i_4_r_0_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_4_r_0_t_4_busy, S1MMEtore::msg_sm_2_i_4_r_0_t_4_cnt, S1MMEtore::msg_sm_2_i_4_r_0_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_4_r_0_t_5_busy, S1MMEtore::msg_sm_2_i_4_r_0_t_5_cnt, S1MMEtore::msg_sm_2_i_4_r_0_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_4_r_0_t_6_busy, S1MMEtore::msg_sm_2_i_4_r_0_t_6_cnt, S1MMEtore::msg_sm_2_i_4_r_0_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_4_r_0_t_7_busy, S1MMEtore::msg_sm_2_i_4_r_0_t_7_cnt, S1MMEtore::msg_sm_2_i_4_r_0_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_4_r_0_t_8_busy, S1MMEtore::msg_sm_2_i_4_r_0_t_8_cnt, S1MMEtore::msg_sm_2_i_4_r_0_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_4_r_0_t_9_busy, S1MMEtore::msg_sm_2_i_4_r_0_t_9_cnt, S1MMEtore::msg_sm_2_i_4_r_0_t_9, pSctp);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_4_r_0_t_0_busy, S1MMEtore::msg_sm_3_i_4_r_0_t_0_cnt, S1MMEtore::msg_sm_3_i_4_r_0_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_4_r_0_t_1_busy, S1MMEtore::msg_sm_3_i_4_r_0_t_1_cnt, S1MMEtore::msg_sm_3_i_4_r_0_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_4_r_0_t_2_busy, S1MMEtore::msg_sm_3_i_4_r_0_t_2_cnt, S1MMEtore::msg_sm_3_i_4_r_0_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_4_r_0_t_3_busy, S1MMEtore::msg_sm_3_i_4_r_0_t_3_cnt, S1MMEtore::msg_sm_3_i_4_r_0_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_4_r_0_t_4_busy, S1MMEtore::msg_sm_3_i_4_r_0_t_4_cnt, S1MMEtore::msg_sm_3_i_4_r_0_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_4_r_0_t_5_busy, S1MMEtore::msg_sm_3_i_4_r_0_t_5_cnt, S1MMEtore::msg_sm_3_i_4_r_0_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_4_r_0_t_6_busy, S1MMEtore::msg_sm_3_i_4_r_0_t_6_cnt, S1MMEtore::msg_sm_3_i_4_r_0_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_4_r_0_t_7_busy, S1MMEtore::msg_sm_3_i_4_r_0_t_7_cnt, S1MMEtore::msg_sm_3_i_4_r_0_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_4_r_0_t_8_busy, S1MMEtore::msg_sm_3_i_4_r_0_t_8_cnt, S1MMEtore::msg_sm_3_i_4_r_0_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_4_r_0_t_9_busy, S1MMEtore::msg_sm_3_i_4_r_0_t_9_cnt, S1MMEtore::msg_sm_3_i_4_r_0_t_9, pSctp);
				break;
			}
			break;
	}
}

VOID SctpMessageBroker::pushToQueue_i_4_r_1(Sctp *pSctp, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_4_r_1_t_0_busy, S1MMEtore::msg_sm_0_i_4_r_1_t_0_cnt, S1MMEtore::msg_sm_0_i_4_r_1_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_4_r_1_t_1_busy, S1MMEtore::msg_sm_0_i_4_r_1_t_1_cnt, S1MMEtore::msg_sm_0_i_4_r_1_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_4_r_1_t_2_busy, S1MMEtore::msg_sm_0_i_4_r_1_t_2_cnt, S1MMEtore::msg_sm_0_i_4_r_1_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_4_r_1_t_3_busy, S1MMEtore::msg_sm_0_i_4_r_1_t_3_cnt, S1MMEtore::msg_sm_0_i_4_r_1_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_4_r_1_t_4_busy, S1MMEtore::msg_sm_0_i_4_r_1_t_4_cnt, S1MMEtore::msg_sm_0_i_4_r_1_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_4_r_1_t_5_busy, S1MMEtore::msg_sm_0_i_4_r_1_t_5_cnt, S1MMEtore::msg_sm_0_i_4_r_1_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_4_r_1_t_6_busy, S1MMEtore::msg_sm_0_i_4_r_1_t_6_cnt, S1MMEtore::msg_sm_0_i_4_r_1_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_4_r_1_t_7_busy, S1MMEtore::msg_sm_0_i_4_r_1_t_7_cnt, S1MMEtore::msg_sm_0_i_4_r_1_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_4_r_1_t_8_busy, S1MMEtore::msg_sm_0_i_4_r_1_t_8_cnt, S1MMEtore::msg_sm_0_i_4_r_1_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_4_r_1_t_9_busy, S1MMEtore::msg_sm_0_i_4_r_1_t_9_cnt, S1MMEtore::msg_sm_0_i_4_r_1_t_9, pSctp);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_4_r_1_t_0_busy, S1MMEtore::msg_sm_1_i_4_r_1_t_0_cnt, S1MMEtore::msg_sm_1_i_4_r_1_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_4_r_1_t_1_busy, S1MMEtore::msg_sm_1_i_4_r_1_t_1_cnt, S1MMEtore::msg_sm_1_i_4_r_1_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_4_r_1_t_2_busy, S1MMEtore::msg_sm_1_i_4_r_1_t_2_cnt, S1MMEtore::msg_sm_1_i_4_r_1_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_4_r_1_t_3_busy, S1MMEtore::msg_sm_1_i_4_r_1_t_3_cnt, S1MMEtore::msg_sm_1_i_4_r_1_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_4_r_1_t_4_busy, S1MMEtore::msg_sm_1_i_4_r_1_t_4_cnt, S1MMEtore::msg_sm_1_i_4_r_1_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_4_r_1_t_5_busy, S1MMEtore::msg_sm_1_i_4_r_1_t_5_cnt, S1MMEtore::msg_sm_1_i_4_r_1_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_4_r_1_t_6_busy, S1MMEtore::msg_sm_1_i_4_r_1_t_6_cnt, S1MMEtore::msg_sm_1_i_4_r_1_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_4_r_1_t_7_busy, S1MMEtore::msg_sm_1_i_4_r_1_t_7_cnt, S1MMEtore::msg_sm_1_i_4_r_1_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_4_r_1_t_8_busy, S1MMEtore::msg_sm_1_i_4_r_1_t_8_cnt, S1MMEtore::msg_sm_1_i_4_r_1_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_4_r_1_t_9_busy, S1MMEtore::msg_sm_1_i_4_r_1_t_9_cnt, S1MMEtore::msg_sm_1_i_4_r_1_t_9, pSctp);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_4_r_1_t_0_busy, S1MMEtore::msg_sm_2_i_4_r_1_t_0_cnt, S1MMEtore::msg_sm_2_i_4_r_1_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_4_r_1_t_1_busy, S1MMEtore::msg_sm_2_i_4_r_1_t_1_cnt, S1MMEtore::msg_sm_2_i_4_r_1_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_4_r_1_t_2_busy, S1MMEtore::msg_sm_2_i_4_r_1_t_2_cnt, S1MMEtore::msg_sm_2_i_4_r_1_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_4_r_1_t_3_busy, S1MMEtore::msg_sm_2_i_4_r_1_t_3_cnt, S1MMEtore::msg_sm_2_i_4_r_1_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_4_r_1_t_4_busy, S1MMEtore::msg_sm_2_i_4_r_1_t_4_cnt, S1MMEtore::msg_sm_2_i_4_r_1_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_4_r_1_t_5_busy, S1MMEtore::msg_sm_2_i_4_r_1_t_5_cnt, S1MMEtore::msg_sm_2_i_4_r_1_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_4_r_1_t_6_busy, S1MMEtore::msg_sm_2_i_4_r_1_t_6_cnt, S1MMEtore::msg_sm_2_i_4_r_1_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_4_r_1_t_7_busy, S1MMEtore::msg_sm_2_i_4_r_1_t_7_cnt, S1MMEtore::msg_sm_2_i_4_r_1_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_4_r_1_t_8_busy, S1MMEtore::msg_sm_2_i_4_r_1_t_8_cnt, S1MMEtore::msg_sm_2_i_4_r_1_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_4_r_1_t_9_busy, S1MMEtore::msg_sm_2_i_4_r_1_t_9_cnt, S1MMEtore::msg_sm_2_i_4_r_1_t_9, pSctp);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_4_r_1_t_0_busy, S1MMEtore::msg_sm_3_i_4_r_1_t_0_cnt, S1MMEtore::msg_sm_3_i_4_r_1_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_4_r_1_t_1_busy, S1MMEtore::msg_sm_3_i_4_r_1_t_1_cnt, S1MMEtore::msg_sm_3_i_4_r_1_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_4_r_1_t_2_busy, S1MMEtore::msg_sm_3_i_4_r_1_t_2_cnt, S1MMEtore::msg_sm_3_i_4_r_1_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_4_r_1_t_3_busy, S1MMEtore::msg_sm_3_i_4_r_1_t_3_cnt, S1MMEtore::msg_sm_3_i_4_r_1_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_4_r_1_t_4_busy, S1MMEtore::msg_sm_3_i_4_r_1_t_4_cnt, S1MMEtore::msg_sm_3_i_4_r_1_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_4_r_1_t_5_busy, S1MMEtore::msg_sm_3_i_4_r_1_t_5_cnt, S1MMEtore::msg_sm_3_i_4_r_1_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_4_r_1_t_6_busy, S1MMEtore::msg_sm_3_i_4_r_1_t_6_cnt, S1MMEtore::msg_sm_3_i_4_r_1_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_4_r_1_t_7_busy, S1MMEtore::msg_sm_3_i_4_r_1_t_7_cnt, S1MMEtore::msg_sm_3_i_4_r_1_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_4_r_1_t_8_busy, S1MMEtore::msg_sm_3_i_4_r_1_t_8_cnt, S1MMEtore::msg_sm_3_i_4_r_1_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_4_r_1_t_9_busy, S1MMEtore::msg_sm_3_i_4_r_1_t_9_cnt, S1MMEtore::msg_sm_3_i_4_r_1_t_9, pSctp);
				break;
			}
			break;
	}
}

VOID SctpMessageBroker::pushToQueue_i_4_r_2(Sctp *pSctp, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_4_r_2_t_0_busy, S1MMEtore::msg_sm_0_i_4_r_2_t_0_cnt, S1MMEtore::msg_sm_0_i_4_r_2_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_4_r_2_t_1_busy, S1MMEtore::msg_sm_0_i_4_r_2_t_1_cnt, S1MMEtore::msg_sm_0_i_4_r_2_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_4_r_2_t_2_busy, S1MMEtore::msg_sm_0_i_4_r_2_t_2_cnt, S1MMEtore::msg_sm_0_i_4_r_2_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_4_r_2_t_3_busy, S1MMEtore::msg_sm_0_i_4_r_2_t_3_cnt, S1MMEtore::msg_sm_0_i_4_r_2_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_4_r_2_t_4_busy, S1MMEtore::msg_sm_0_i_4_r_2_t_4_cnt, S1MMEtore::msg_sm_0_i_4_r_2_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_4_r_2_t_5_busy, S1MMEtore::msg_sm_0_i_4_r_2_t_5_cnt, S1MMEtore::msg_sm_0_i_4_r_2_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_4_r_2_t_6_busy, S1MMEtore::msg_sm_0_i_4_r_2_t_6_cnt, S1MMEtore::msg_sm_0_i_4_r_2_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_4_r_2_t_7_busy, S1MMEtore::msg_sm_0_i_4_r_2_t_7_cnt, S1MMEtore::msg_sm_0_i_4_r_2_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_4_r_2_t_8_busy, S1MMEtore::msg_sm_0_i_4_r_2_t_8_cnt, S1MMEtore::msg_sm_0_i_4_r_2_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_4_r_2_t_9_busy, S1MMEtore::msg_sm_0_i_4_r_2_t_9_cnt, S1MMEtore::msg_sm_0_i_4_r_2_t_9, pSctp);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_4_r_2_t_0_busy, S1MMEtore::msg_sm_1_i_4_r_2_t_0_cnt, S1MMEtore::msg_sm_1_i_4_r_2_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_4_r_2_t_1_busy, S1MMEtore::msg_sm_1_i_4_r_2_t_1_cnt, S1MMEtore::msg_sm_1_i_4_r_2_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_4_r_2_t_2_busy, S1MMEtore::msg_sm_1_i_4_r_2_t_2_cnt, S1MMEtore::msg_sm_1_i_4_r_2_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_4_r_2_t_3_busy, S1MMEtore::msg_sm_1_i_4_r_2_t_3_cnt, S1MMEtore::msg_sm_1_i_4_r_2_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_4_r_2_t_4_busy, S1MMEtore::msg_sm_1_i_4_r_2_t_4_cnt, S1MMEtore::msg_sm_1_i_4_r_2_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_4_r_2_t_5_busy, S1MMEtore::msg_sm_1_i_4_r_2_t_5_cnt, S1MMEtore::msg_sm_1_i_4_r_2_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_4_r_2_t_6_busy, S1MMEtore::msg_sm_1_i_4_r_2_t_6_cnt, S1MMEtore::msg_sm_1_i_4_r_2_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_4_r_2_t_7_busy, S1MMEtore::msg_sm_1_i_4_r_2_t_7_cnt, S1MMEtore::msg_sm_1_i_4_r_2_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_4_r_2_t_8_busy, S1MMEtore::msg_sm_1_i_4_r_2_t_8_cnt, S1MMEtore::msg_sm_1_i_4_r_2_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_4_r_2_t_9_busy, S1MMEtore::msg_sm_1_i_4_r_2_t_9_cnt, S1MMEtore::msg_sm_1_i_4_r_2_t_9, pSctp);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_4_r_2_t_0_busy, S1MMEtore::msg_sm_2_i_4_r_2_t_0_cnt, S1MMEtore::msg_sm_2_i_4_r_2_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_4_r_2_t_1_busy, S1MMEtore::msg_sm_2_i_4_r_2_t_1_cnt, S1MMEtore::msg_sm_2_i_4_r_2_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_4_r_2_t_2_busy, S1MMEtore::msg_sm_2_i_4_r_2_t_2_cnt, S1MMEtore::msg_sm_2_i_4_r_2_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_4_r_2_t_3_busy, S1MMEtore::msg_sm_2_i_4_r_2_t_3_cnt, S1MMEtore::msg_sm_2_i_4_r_2_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_4_r_2_t_4_busy, S1MMEtore::msg_sm_2_i_4_r_2_t_4_cnt, S1MMEtore::msg_sm_2_i_4_r_2_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_4_r_2_t_5_busy, S1MMEtore::msg_sm_2_i_4_r_2_t_5_cnt, S1MMEtore::msg_sm_2_i_4_r_2_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_4_r_2_t_6_busy, S1MMEtore::msg_sm_2_i_4_r_2_t_6_cnt, S1MMEtore::msg_sm_2_i_4_r_2_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_4_r_2_t_7_busy, S1MMEtore::msg_sm_2_i_4_r_2_t_7_cnt, S1MMEtore::msg_sm_2_i_4_r_2_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_4_r_2_t_8_busy, S1MMEtore::msg_sm_2_i_4_r_2_t_8_cnt, S1MMEtore::msg_sm_2_i_4_r_2_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_4_r_2_t_9_busy, S1MMEtore::msg_sm_2_i_4_r_2_t_9_cnt, S1MMEtore::msg_sm_2_i_4_r_2_t_9, pSctp);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_4_r_2_t_0_busy, S1MMEtore::msg_sm_3_i_4_r_2_t_0_cnt, S1MMEtore::msg_sm_3_i_4_r_2_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_4_r_2_t_1_busy, S1MMEtore::msg_sm_3_i_4_r_2_t_1_cnt, S1MMEtore::msg_sm_3_i_4_r_2_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_4_r_2_t_2_busy, S1MMEtore::msg_sm_3_i_4_r_2_t_2_cnt, S1MMEtore::msg_sm_3_i_4_r_2_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_4_r_2_t_3_busy, S1MMEtore::msg_sm_3_i_4_r_2_t_3_cnt, S1MMEtore::msg_sm_3_i_4_r_2_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_4_r_2_t_4_busy, S1MMEtore::msg_sm_3_i_4_r_2_t_4_cnt, S1MMEtore::msg_sm_3_i_4_r_2_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_4_r_2_t_5_busy, S1MMEtore::msg_sm_3_i_4_r_2_t_5_cnt, S1MMEtore::msg_sm_3_i_4_r_2_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_4_r_2_t_6_busy, S1MMEtore::msg_sm_3_i_4_r_2_t_6_cnt, S1MMEtore::msg_sm_3_i_4_r_2_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_4_r_2_t_7_busy, S1MMEtore::msg_sm_3_i_4_r_2_t_7_cnt, S1MMEtore::msg_sm_3_i_4_r_2_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_4_r_2_t_8_busy, S1MMEtore::msg_sm_3_i_4_r_2_t_8_cnt, S1MMEtore::msg_sm_3_i_4_r_2_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_4_r_2_t_9_busy, S1MMEtore::msg_sm_3_i_4_r_2_t_9_cnt, S1MMEtore::msg_sm_3_i_4_r_2_t_9, pSctp);
				break;
			}
			break;
	}
}

VOID SctpMessageBroker::pushToQueue_i_4_r_3(Sctp *pSctp, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_4_r_3_t_0_busy, S1MMEtore::msg_sm_0_i_4_r_3_t_0_cnt, S1MMEtore::msg_sm_0_i_4_r_3_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_4_r_3_t_1_busy, S1MMEtore::msg_sm_0_i_4_r_3_t_1_cnt, S1MMEtore::msg_sm_0_i_4_r_3_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_4_r_3_t_2_busy, S1MMEtore::msg_sm_0_i_4_r_3_t_2_cnt, S1MMEtore::msg_sm_0_i_4_r_3_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_4_r_3_t_3_busy, S1MMEtore::msg_sm_0_i_4_r_3_t_3_cnt, S1MMEtore::msg_sm_0_i_4_r_3_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_4_r_3_t_4_busy, S1MMEtore::msg_sm_0_i_4_r_3_t_4_cnt, S1MMEtore::msg_sm_0_i_4_r_3_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_4_r_3_t_5_busy, S1MMEtore::msg_sm_0_i_4_r_3_t_5_cnt, S1MMEtore::msg_sm_0_i_4_r_3_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_4_r_3_t_6_busy, S1MMEtore::msg_sm_0_i_4_r_3_t_6_cnt, S1MMEtore::msg_sm_0_i_4_r_3_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_4_r_3_t_7_busy, S1MMEtore::msg_sm_0_i_4_r_3_t_7_cnt, S1MMEtore::msg_sm_0_i_4_r_3_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_4_r_3_t_8_busy, S1MMEtore::msg_sm_0_i_4_r_3_t_8_cnt, S1MMEtore::msg_sm_0_i_4_r_3_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_4_r_3_t_9_busy, S1MMEtore::msg_sm_0_i_4_r_3_t_9_cnt, S1MMEtore::msg_sm_0_i_4_r_3_t_9, pSctp);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_4_r_3_t_0_busy, S1MMEtore::msg_sm_1_i_4_r_3_t_0_cnt, S1MMEtore::msg_sm_1_i_4_r_3_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_4_r_3_t_1_busy, S1MMEtore::msg_sm_1_i_4_r_3_t_1_cnt, S1MMEtore::msg_sm_1_i_4_r_3_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_4_r_3_t_2_busy, S1MMEtore::msg_sm_1_i_4_r_3_t_2_cnt, S1MMEtore::msg_sm_1_i_4_r_3_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_4_r_3_t_3_busy, S1MMEtore::msg_sm_1_i_4_r_3_t_3_cnt, S1MMEtore::msg_sm_1_i_4_r_3_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_4_r_3_t_4_busy, S1MMEtore::msg_sm_1_i_4_r_3_t_4_cnt, S1MMEtore::msg_sm_1_i_4_r_3_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_4_r_3_t_5_busy, S1MMEtore::msg_sm_1_i_4_r_3_t_5_cnt, S1MMEtore::msg_sm_1_i_4_r_3_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_4_r_3_t_6_busy, S1MMEtore::msg_sm_1_i_4_r_3_t_6_cnt, S1MMEtore::msg_sm_1_i_4_r_3_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_4_r_3_t_7_busy, S1MMEtore::msg_sm_1_i_4_r_3_t_7_cnt, S1MMEtore::msg_sm_1_i_4_r_3_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_4_r_3_t_8_busy, S1MMEtore::msg_sm_1_i_4_r_3_t_8_cnt, S1MMEtore::msg_sm_1_i_4_r_3_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_4_r_3_t_9_busy, S1MMEtore::msg_sm_1_i_4_r_3_t_9_cnt, S1MMEtore::msg_sm_1_i_4_r_3_t_9, pSctp);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_4_r_3_t_0_busy, S1MMEtore::msg_sm_2_i_4_r_3_t_0_cnt, S1MMEtore::msg_sm_2_i_4_r_3_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_4_r_3_t_1_busy, S1MMEtore::msg_sm_2_i_4_r_3_t_1_cnt, S1MMEtore::msg_sm_2_i_4_r_3_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_4_r_3_t_2_busy, S1MMEtore::msg_sm_2_i_4_r_3_t_2_cnt, S1MMEtore::msg_sm_2_i_4_r_3_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_4_r_3_t_3_busy, S1MMEtore::msg_sm_2_i_4_r_3_t_3_cnt, S1MMEtore::msg_sm_2_i_4_r_3_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_4_r_3_t_4_busy, S1MMEtore::msg_sm_2_i_4_r_3_t_4_cnt, S1MMEtore::msg_sm_2_i_4_r_3_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_4_r_3_t_5_busy, S1MMEtore::msg_sm_2_i_4_r_3_t_5_cnt, S1MMEtore::msg_sm_2_i_4_r_3_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_4_r_3_t_6_busy, S1MMEtore::msg_sm_2_i_4_r_3_t_6_cnt, S1MMEtore::msg_sm_2_i_4_r_3_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_4_r_3_t_7_busy, S1MMEtore::msg_sm_2_i_4_r_3_t_7_cnt, S1MMEtore::msg_sm_2_i_4_r_3_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_4_r_3_t_8_busy, S1MMEtore::msg_sm_2_i_4_r_3_t_8_cnt, S1MMEtore::msg_sm_2_i_4_r_3_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_4_r_3_t_9_busy, S1MMEtore::msg_sm_2_i_4_r_3_t_9_cnt, S1MMEtore::msg_sm_2_i_4_r_3_t_9, pSctp);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_4_r_3_t_0_busy, S1MMEtore::msg_sm_3_i_4_r_3_t_0_cnt, S1MMEtore::msg_sm_3_i_4_r_3_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_4_r_3_t_1_busy, S1MMEtore::msg_sm_3_i_4_r_3_t_1_cnt, S1MMEtore::msg_sm_3_i_4_r_3_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_4_r_3_t_2_busy, S1MMEtore::msg_sm_3_i_4_r_3_t_2_cnt, S1MMEtore::msg_sm_3_i_4_r_3_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_4_r_3_t_3_busy, S1MMEtore::msg_sm_3_i_4_r_3_t_3_cnt, S1MMEtore::msg_sm_3_i_4_r_3_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_4_r_3_t_4_busy, S1MMEtore::msg_sm_3_i_4_r_3_t_4_cnt, S1MMEtore::msg_sm_3_i_4_r_3_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_4_r_3_t_5_busy, S1MMEtore::msg_sm_3_i_4_r_3_t_5_cnt, S1MMEtore::msg_sm_3_i_4_r_3_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_4_r_3_t_6_busy, S1MMEtore::msg_sm_3_i_4_r_3_t_6_cnt, S1MMEtore::msg_sm_3_i_4_r_3_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_4_r_3_t_7_busy, S1MMEtore::msg_sm_3_i_4_r_3_t_7_cnt, S1MMEtore::msg_sm_3_i_4_r_3_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_4_r_3_t_8_busy, S1MMEtore::msg_sm_3_i_4_r_3_t_8_cnt, S1MMEtore::msg_sm_3_i_4_r_3_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_4_r_3_t_9_busy, S1MMEtore::msg_sm_3_i_4_r_3_t_9_cnt, S1MMEtore::msg_sm_3_i_4_r_3_t_9, pSctp);
				break;
			}
			break;
	}
}

VOID SctpMessageBroker::pushToQueue_i_4_r_4(Sctp *pSctp, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_4_r_4_t_0_busy, S1MMEtore::msg_sm_0_i_4_r_4_t_0_cnt, S1MMEtore::msg_sm_0_i_4_r_4_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_4_r_4_t_1_busy, S1MMEtore::msg_sm_0_i_4_r_4_t_1_cnt, S1MMEtore::msg_sm_0_i_4_r_4_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_4_r_4_t_2_busy, S1MMEtore::msg_sm_0_i_4_r_4_t_2_cnt, S1MMEtore::msg_sm_0_i_4_r_4_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_4_r_4_t_3_busy, S1MMEtore::msg_sm_0_i_4_r_4_t_3_cnt, S1MMEtore::msg_sm_0_i_4_r_4_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_4_r_4_t_4_busy, S1MMEtore::msg_sm_0_i_4_r_4_t_4_cnt, S1MMEtore::msg_sm_0_i_4_r_4_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_4_r_4_t_5_busy, S1MMEtore::msg_sm_0_i_4_r_4_t_5_cnt, S1MMEtore::msg_sm_0_i_4_r_4_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_4_r_4_t_6_busy, S1MMEtore::msg_sm_0_i_4_r_4_t_6_cnt, S1MMEtore::msg_sm_0_i_4_r_4_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_4_r_4_t_7_busy, S1MMEtore::msg_sm_0_i_4_r_4_t_7_cnt, S1MMEtore::msg_sm_0_i_4_r_4_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_4_r_4_t_8_busy, S1MMEtore::msg_sm_0_i_4_r_4_t_8_cnt, S1MMEtore::msg_sm_0_i_4_r_4_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_4_r_4_t_9_busy, S1MMEtore::msg_sm_0_i_4_r_4_t_9_cnt, S1MMEtore::msg_sm_0_i_4_r_4_t_9, pSctp);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_4_r_4_t_0_busy, S1MMEtore::msg_sm_1_i_4_r_4_t_0_cnt, S1MMEtore::msg_sm_1_i_4_r_4_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_4_r_4_t_1_busy, S1MMEtore::msg_sm_1_i_4_r_4_t_1_cnt, S1MMEtore::msg_sm_1_i_4_r_4_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_4_r_4_t_2_busy, S1MMEtore::msg_sm_1_i_4_r_4_t_2_cnt, S1MMEtore::msg_sm_1_i_4_r_4_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_4_r_4_t_3_busy, S1MMEtore::msg_sm_1_i_4_r_4_t_3_cnt, S1MMEtore::msg_sm_1_i_4_r_4_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_4_r_4_t_4_busy, S1MMEtore::msg_sm_1_i_4_r_4_t_4_cnt, S1MMEtore::msg_sm_1_i_4_r_4_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_4_r_4_t_5_busy, S1MMEtore::msg_sm_1_i_4_r_4_t_5_cnt, S1MMEtore::msg_sm_1_i_4_r_4_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_4_r_4_t_6_busy, S1MMEtore::msg_sm_1_i_4_r_4_t_6_cnt, S1MMEtore::msg_sm_1_i_4_r_4_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_4_r_4_t_7_busy, S1MMEtore::msg_sm_1_i_4_r_4_t_7_cnt, S1MMEtore::msg_sm_1_i_4_r_4_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_4_r_4_t_8_busy, S1MMEtore::msg_sm_1_i_4_r_4_t_8_cnt, S1MMEtore::msg_sm_1_i_4_r_4_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_4_r_4_t_9_busy, S1MMEtore::msg_sm_1_i_4_r_4_t_9_cnt, S1MMEtore::msg_sm_1_i_4_r_4_t_9, pSctp);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_4_r_4_t_0_busy, S1MMEtore::msg_sm_2_i_4_r_4_t_0_cnt, S1MMEtore::msg_sm_2_i_4_r_4_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_4_r_4_t_1_busy, S1MMEtore::msg_sm_2_i_4_r_4_t_1_cnt, S1MMEtore::msg_sm_2_i_4_r_4_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_4_r_4_t_2_busy, S1MMEtore::msg_sm_2_i_4_r_4_t_2_cnt, S1MMEtore::msg_sm_2_i_4_r_4_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_4_r_4_t_3_busy, S1MMEtore::msg_sm_2_i_4_r_4_t_3_cnt, S1MMEtore::msg_sm_2_i_4_r_4_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_4_r_4_t_4_busy, S1MMEtore::msg_sm_2_i_4_r_4_t_4_cnt, S1MMEtore::msg_sm_2_i_4_r_4_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_4_r_4_t_5_busy, S1MMEtore::msg_sm_2_i_4_r_4_t_5_cnt, S1MMEtore::msg_sm_2_i_4_r_4_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_4_r_4_t_6_busy, S1MMEtore::msg_sm_2_i_4_r_4_t_6_cnt, S1MMEtore::msg_sm_2_i_4_r_4_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_4_r_4_t_7_busy, S1MMEtore::msg_sm_2_i_4_r_4_t_7_cnt, S1MMEtore::msg_sm_2_i_4_r_4_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_4_r_4_t_8_busy, S1MMEtore::msg_sm_2_i_4_r_4_t_8_cnt, S1MMEtore::msg_sm_2_i_4_r_4_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_4_r_4_t_9_busy, S1MMEtore::msg_sm_2_i_4_r_4_t_9_cnt, S1MMEtore::msg_sm_2_i_4_r_4_t_9, pSctp);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_4_r_4_t_0_busy, S1MMEtore::msg_sm_3_i_4_r_4_t_0_cnt, S1MMEtore::msg_sm_3_i_4_r_4_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_4_r_4_t_1_busy, S1MMEtore::msg_sm_3_i_4_r_4_t_1_cnt, S1MMEtore::msg_sm_3_i_4_r_4_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_4_r_4_t_2_busy, S1MMEtore::msg_sm_3_i_4_r_4_t_2_cnt, S1MMEtore::msg_sm_3_i_4_r_4_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_4_r_4_t_3_busy, S1MMEtore::msg_sm_3_i_4_r_4_t_3_cnt, S1MMEtore::msg_sm_3_i_4_r_4_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_4_r_4_t_4_busy, S1MMEtore::msg_sm_3_i_4_r_4_t_4_cnt, S1MMEtore::msg_sm_3_i_4_r_4_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_4_r_4_t_5_busy, S1MMEtore::msg_sm_3_i_4_r_4_t_5_cnt, S1MMEtore::msg_sm_3_i_4_r_4_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_4_r_4_t_6_busy, S1MMEtore::msg_sm_3_i_4_r_4_t_6_cnt, S1MMEtore::msg_sm_3_i_4_r_4_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_4_r_4_t_7_busy, S1MMEtore::msg_sm_3_i_4_r_4_t_7_cnt, S1MMEtore::msg_sm_3_i_4_r_4_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_4_r_4_t_8_busy, S1MMEtore::msg_sm_3_i_4_r_4_t_8_cnt, S1MMEtore::msg_sm_3_i_4_r_4_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_4_r_4_t_9_busy, S1MMEtore::msg_sm_3_i_4_r_4_t_9_cnt, S1MMEtore::msg_sm_3_i_4_r_4_t_9, pSctp);
				break;
			}
			break;
	}
}

VOID SctpMessageBroker::pushToQueue_i_4_r_5(Sctp *pSctp, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_4_r_5_t_0_busy, S1MMEtore::msg_sm_0_i_4_r_5_t_0_cnt, S1MMEtore::msg_sm_0_i_4_r_5_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_4_r_5_t_1_busy, S1MMEtore::msg_sm_0_i_4_r_5_t_1_cnt, S1MMEtore::msg_sm_0_i_4_r_5_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_4_r_5_t_2_busy, S1MMEtore::msg_sm_0_i_4_r_5_t_2_cnt, S1MMEtore::msg_sm_0_i_4_r_5_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_4_r_5_t_3_busy, S1MMEtore::msg_sm_0_i_4_r_5_t_3_cnt, S1MMEtore::msg_sm_0_i_4_r_5_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_4_r_5_t_4_busy, S1MMEtore::msg_sm_0_i_4_r_5_t_4_cnt, S1MMEtore::msg_sm_0_i_4_r_5_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_4_r_5_t_5_busy, S1MMEtore::msg_sm_0_i_4_r_5_t_5_cnt, S1MMEtore::msg_sm_0_i_4_r_5_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_4_r_5_t_6_busy, S1MMEtore::msg_sm_0_i_4_r_5_t_6_cnt, S1MMEtore::msg_sm_0_i_4_r_5_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_4_r_5_t_7_busy, S1MMEtore::msg_sm_0_i_4_r_5_t_7_cnt, S1MMEtore::msg_sm_0_i_4_r_5_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_4_r_5_t_8_busy, S1MMEtore::msg_sm_0_i_4_r_5_t_8_cnt, S1MMEtore::msg_sm_0_i_4_r_5_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_4_r_5_t_9_busy, S1MMEtore::msg_sm_0_i_4_r_5_t_9_cnt, S1MMEtore::msg_sm_0_i_4_r_5_t_9, pSctp);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_4_r_5_t_0_busy, S1MMEtore::msg_sm_1_i_4_r_5_t_0_cnt, S1MMEtore::msg_sm_1_i_4_r_5_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_4_r_5_t_1_busy, S1MMEtore::msg_sm_1_i_4_r_5_t_1_cnt, S1MMEtore::msg_sm_1_i_4_r_5_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_4_r_5_t_2_busy, S1MMEtore::msg_sm_1_i_4_r_5_t_2_cnt, S1MMEtore::msg_sm_1_i_4_r_5_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_4_r_5_t_3_busy, S1MMEtore::msg_sm_1_i_4_r_5_t_3_cnt, S1MMEtore::msg_sm_1_i_4_r_5_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_4_r_5_t_4_busy, S1MMEtore::msg_sm_1_i_4_r_5_t_4_cnt, S1MMEtore::msg_sm_1_i_4_r_5_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_4_r_5_t_5_busy, S1MMEtore::msg_sm_1_i_4_r_5_t_5_cnt, S1MMEtore::msg_sm_1_i_4_r_5_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_4_r_5_t_6_busy, S1MMEtore::msg_sm_1_i_4_r_5_t_6_cnt, S1MMEtore::msg_sm_1_i_4_r_5_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_4_r_5_t_7_busy, S1MMEtore::msg_sm_1_i_4_r_5_t_7_cnt, S1MMEtore::msg_sm_1_i_4_r_5_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_4_r_5_t_8_busy, S1MMEtore::msg_sm_1_i_4_r_5_t_8_cnt, S1MMEtore::msg_sm_1_i_4_r_5_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_4_r_5_t_9_busy, S1MMEtore::msg_sm_1_i_4_r_5_t_9_cnt, S1MMEtore::msg_sm_1_i_4_r_5_t_9, pSctp);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_4_r_5_t_0_busy, S1MMEtore::msg_sm_2_i_4_r_5_t_0_cnt, S1MMEtore::msg_sm_2_i_4_r_5_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_4_r_5_t_1_busy, S1MMEtore::msg_sm_2_i_4_r_5_t_1_cnt, S1MMEtore::msg_sm_2_i_4_r_5_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_4_r_5_t_2_busy, S1MMEtore::msg_sm_2_i_4_r_5_t_2_cnt, S1MMEtore::msg_sm_2_i_4_r_5_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_4_r_5_t_3_busy, S1MMEtore::msg_sm_2_i_4_r_5_t_3_cnt, S1MMEtore::msg_sm_2_i_4_r_5_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_4_r_5_t_4_busy, S1MMEtore::msg_sm_2_i_4_r_5_t_4_cnt, S1MMEtore::msg_sm_2_i_4_r_5_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_4_r_5_t_5_busy, S1MMEtore::msg_sm_2_i_4_r_5_t_5_cnt, S1MMEtore::msg_sm_2_i_4_r_5_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_4_r_5_t_6_busy, S1MMEtore::msg_sm_2_i_4_r_5_t_6_cnt, S1MMEtore::msg_sm_2_i_4_r_5_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_4_r_5_t_7_busy, S1MMEtore::msg_sm_2_i_4_r_5_t_7_cnt, S1MMEtore::msg_sm_2_i_4_r_5_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_4_r_5_t_8_busy, S1MMEtore::msg_sm_2_i_4_r_5_t_8_cnt, S1MMEtore::msg_sm_2_i_4_r_5_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_4_r_5_t_9_busy, S1MMEtore::msg_sm_2_i_4_r_5_t_9_cnt, S1MMEtore::msg_sm_2_i_4_r_5_t_9, pSctp);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_4_r_5_t_0_busy, S1MMEtore::msg_sm_3_i_4_r_5_t_0_cnt, S1MMEtore::msg_sm_3_i_4_r_5_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_4_r_5_t_1_busy, S1MMEtore::msg_sm_3_i_4_r_5_t_1_cnt, S1MMEtore::msg_sm_3_i_4_r_5_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_4_r_5_t_2_busy, S1MMEtore::msg_sm_3_i_4_r_5_t_2_cnt, S1MMEtore::msg_sm_3_i_4_r_5_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_4_r_5_t_3_busy, S1MMEtore::msg_sm_3_i_4_r_5_t_3_cnt, S1MMEtore::msg_sm_3_i_4_r_5_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_4_r_5_t_4_busy, S1MMEtore::msg_sm_3_i_4_r_5_t_4_cnt, S1MMEtore::msg_sm_3_i_4_r_5_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_4_r_5_t_5_busy, S1MMEtore::msg_sm_3_i_4_r_5_t_5_cnt, S1MMEtore::msg_sm_3_i_4_r_5_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_4_r_5_t_6_busy, S1MMEtore::msg_sm_3_i_4_r_5_t_6_cnt, S1MMEtore::msg_sm_3_i_4_r_5_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_4_r_5_t_7_busy, S1MMEtore::msg_sm_3_i_4_r_5_t_7_cnt, S1MMEtore::msg_sm_3_i_4_r_5_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_4_r_5_t_8_busy, S1MMEtore::msg_sm_3_i_4_r_5_t_8_cnt, S1MMEtore::msg_sm_3_i_4_r_5_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_4_r_5_t_9_busy, S1MMEtore::msg_sm_3_i_4_r_5_t_9_cnt, S1MMEtore::msg_sm_3_i_4_r_5_t_9, pSctp);
				break;
			}
			break;
	}
}

VOID SctpMessageBroker::pushToQueue_i_4_r_6(Sctp *pSctp, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_4_r_6_t_0_busy, S1MMEtore::msg_sm_0_i_4_r_6_t_0_cnt, S1MMEtore::msg_sm_0_i_4_r_6_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_4_r_6_t_1_busy, S1MMEtore::msg_sm_0_i_4_r_6_t_1_cnt, S1MMEtore::msg_sm_0_i_4_r_6_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_4_r_6_t_2_busy, S1MMEtore::msg_sm_0_i_4_r_6_t_2_cnt, S1MMEtore::msg_sm_0_i_4_r_6_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_4_r_6_t_3_busy, S1MMEtore::msg_sm_0_i_4_r_6_t_3_cnt, S1MMEtore::msg_sm_0_i_4_r_6_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_4_r_6_t_4_busy, S1MMEtore::msg_sm_0_i_4_r_6_t_4_cnt, S1MMEtore::msg_sm_0_i_4_r_6_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_4_r_6_t_5_busy, S1MMEtore::msg_sm_0_i_4_r_6_t_5_cnt, S1MMEtore::msg_sm_0_i_4_r_6_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_4_r_6_t_6_busy, S1MMEtore::msg_sm_0_i_4_r_6_t_6_cnt, S1MMEtore::msg_sm_0_i_4_r_6_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_4_r_6_t_7_busy, S1MMEtore::msg_sm_0_i_4_r_6_t_7_cnt, S1MMEtore::msg_sm_0_i_4_r_6_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_4_r_6_t_8_busy, S1MMEtore::msg_sm_0_i_4_r_6_t_8_cnt, S1MMEtore::msg_sm_0_i_4_r_6_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_4_r_6_t_9_busy, S1MMEtore::msg_sm_0_i_4_r_6_t_9_cnt, S1MMEtore::msg_sm_0_i_4_r_6_t_9, pSctp);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_4_r_6_t_0_busy, S1MMEtore::msg_sm_1_i_4_r_6_t_0_cnt, S1MMEtore::msg_sm_1_i_4_r_6_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_4_r_6_t_1_busy, S1MMEtore::msg_sm_1_i_4_r_6_t_1_cnt, S1MMEtore::msg_sm_1_i_4_r_6_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_4_r_6_t_2_busy, S1MMEtore::msg_sm_1_i_4_r_6_t_2_cnt, S1MMEtore::msg_sm_1_i_4_r_6_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_4_r_6_t_3_busy, S1MMEtore::msg_sm_1_i_4_r_6_t_3_cnt, S1MMEtore::msg_sm_1_i_4_r_6_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_4_r_6_t_4_busy, S1MMEtore::msg_sm_1_i_4_r_6_t_4_cnt, S1MMEtore::msg_sm_1_i_4_r_6_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_4_r_6_t_5_busy, S1MMEtore::msg_sm_1_i_4_r_6_t_5_cnt, S1MMEtore::msg_sm_1_i_4_r_6_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_4_r_6_t_6_busy, S1MMEtore::msg_sm_1_i_4_r_6_t_6_cnt, S1MMEtore::msg_sm_1_i_4_r_6_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_4_r_6_t_7_busy, S1MMEtore::msg_sm_1_i_4_r_6_t_7_cnt, S1MMEtore::msg_sm_1_i_4_r_6_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_4_r_6_t_8_busy, S1MMEtore::msg_sm_1_i_4_r_6_t_8_cnt, S1MMEtore::msg_sm_1_i_4_r_6_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_4_r_6_t_9_busy, S1MMEtore::msg_sm_1_i_4_r_6_t_9_cnt, S1MMEtore::msg_sm_1_i_4_r_6_t_9, pSctp);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_4_r_6_t_0_busy, S1MMEtore::msg_sm_2_i_4_r_6_t_0_cnt, S1MMEtore::msg_sm_2_i_4_r_6_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_4_r_6_t_1_busy, S1MMEtore::msg_sm_2_i_4_r_6_t_1_cnt, S1MMEtore::msg_sm_2_i_4_r_6_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_4_r_6_t_2_busy, S1MMEtore::msg_sm_2_i_4_r_6_t_2_cnt, S1MMEtore::msg_sm_2_i_4_r_6_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_4_r_6_t_3_busy, S1MMEtore::msg_sm_2_i_4_r_6_t_3_cnt, S1MMEtore::msg_sm_2_i_4_r_6_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_4_r_6_t_4_busy, S1MMEtore::msg_sm_2_i_4_r_6_t_4_cnt, S1MMEtore::msg_sm_2_i_4_r_6_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_4_r_6_t_5_busy, S1MMEtore::msg_sm_2_i_4_r_6_t_5_cnt, S1MMEtore::msg_sm_2_i_4_r_6_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_4_r_6_t_6_busy, S1MMEtore::msg_sm_2_i_4_r_6_t_6_cnt, S1MMEtore::msg_sm_2_i_4_r_6_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_4_r_6_t_7_busy, S1MMEtore::msg_sm_2_i_4_r_6_t_7_cnt, S1MMEtore::msg_sm_2_i_4_r_6_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_4_r_6_t_8_busy, S1MMEtore::msg_sm_2_i_4_r_6_t_8_cnt, S1MMEtore::msg_sm_2_i_4_r_6_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_4_r_6_t_9_busy, S1MMEtore::msg_sm_2_i_4_r_6_t_9_cnt, S1MMEtore::msg_sm_2_i_4_r_6_t_9, pSctp);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_4_r_6_t_0_busy, S1MMEtore::msg_sm_3_i_4_r_6_t_0_cnt, S1MMEtore::msg_sm_3_i_4_r_6_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_4_r_6_t_1_busy, S1MMEtore::msg_sm_3_i_4_r_6_t_1_cnt, S1MMEtore::msg_sm_3_i_4_r_6_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_4_r_6_t_2_busy, S1MMEtore::msg_sm_3_i_4_r_6_t_2_cnt, S1MMEtore::msg_sm_3_i_4_r_6_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_4_r_6_t_3_busy, S1MMEtore::msg_sm_3_i_4_r_6_t_3_cnt, S1MMEtore::msg_sm_3_i_4_r_6_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_4_r_6_t_4_busy, S1MMEtore::msg_sm_3_i_4_r_6_t_4_cnt, S1MMEtore::msg_sm_3_i_4_r_6_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_4_r_6_t_5_busy, S1MMEtore::msg_sm_3_i_4_r_6_t_5_cnt, S1MMEtore::msg_sm_3_i_4_r_6_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_4_r_6_t_6_busy, S1MMEtore::msg_sm_3_i_4_r_6_t_6_cnt, S1MMEtore::msg_sm_3_i_4_r_6_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_4_r_6_t_7_busy, S1MMEtore::msg_sm_3_i_4_r_6_t_7_cnt, S1MMEtore::msg_sm_3_i_4_r_6_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_4_r_6_t_8_busy, S1MMEtore::msg_sm_3_i_4_r_6_t_8_cnt, S1MMEtore::msg_sm_3_i_4_r_6_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_4_r_6_t_9_busy, S1MMEtore::msg_sm_3_i_4_r_6_t_9_cnt, S1MMEtore::msg_sm_3_i_4_r_6_t_9, pSctp);
				break;
			}
			break;
	}
}

VOID SctpMessageBroker::pushToQueue_i_4_r_7(Sctp *pSctp, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_4_r_7_t_0_busy, S1MMEtore::msg_sm_0_i_4_r_7_t_0_cnt, S1MMEtore::msg_sm_0_i_4_r_7_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_4_r_7_t_1_busy, S1MMEtore::msg_sm_0_i_4_r_7_t_1_cnt, S1MMEtore::msg_sm_0_i_4_r_7_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_4_r_7_t_2_busy, S1MMEtore::msg_sm_0_i_4_r_7_t_2_cnt, S1MMEtore::msg_sm_0_i_4_r_7_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_4_r_7_t_3_busy, S1MMEtore::msg_sm_0_i_4_r_7_t_3_cnt, S1MMEtore::msg_sm_0_i_4_r_7_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_4_r_7_t_4_busy, S1MMEtore::msg_sm_0_i_4_r_7_t_4_cnt, S1MMEtore::msg_sm_0_i_4_r_7_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_4_r_7_t_5_busy, S1MMEtore::msg_sm_0_i_4_r_7_t_5_cnt, S1MMEtore::msg_sm_0_i_4_r_7_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_4_r_7_t_6_busy, S1MMEtore::msg_sm_0_i_4_r_7_t_6_cnt, S1MMEtore::msg_sm_0_i_4_r_7_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_4_r_7_t_7_busy, S1MMEtore::msg_sm_0_i_4_r_7_t_7_cnt, S1MMEtore::msg_sm_0_i_4_r_7_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_4_r_7_t_8_busy, S1MMEtore::msg_sm_0_i_4_r_7_t_8_cnt, S1MMEtore::msg_sm_0_i_4_r_7_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_4_r_7_t_9_busy, S1MMEtore::msg_sm_0_i_4_r_7_t_9_cnt, S1MMEtore::msg_sm_0_i_4_r_7_t_9, pSctp);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_4_r_7_t_0_busy, S1MMEtore::msg_sm_1_i_4_r_7_t_0_cnt, S1MMEtore::msg_sm_1_i_4_r_7_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_4_r_7_t_1_busy, S1MMEtore::msg_sm_1_i_4_r_7_t_1_cnt, S1MMEtore::msg_sm_1_i_4_r_7_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_4_r_7_t_2_busy, S1MMEtore::msg_sm_1_i_4_r_7_t_2_cnt, S1MMEtore::msg_sm_1_i_4_r_7_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_4_r_7_t_3_busy, S1MMEtore::msg_sm_1_i_4_r_7_t_3_cnt, S1MMEtore::msg_sm_1_i_4_r_7_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_4_r_7_t_4_busy, S1MMEtore::msg_sm_1_i_4_r_7_t_4_cnt, S1MMEtore::msg_sm_1_i_4_r_7_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_4_r_7_t_5_busy, S1MMEtore::msg_sm_1_i_4_r_7_t_5_cnt, S1MMEtore::msg_sm_1_i_4_r_7_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_4_r_7_t_6_busy, S1MMEtore::msg_sm_1_i_4_r_7_t_6_cnt, S1MMEtore::msg_sm_1_i_4_r_7_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_4_r_7_t_7_busy, S1MMEtore::msg_sm_1_i_4_r_7_t_7_cnt, S1MMEtore::msg_sm_1_i_4_r_7_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_4_r_7_t_8_busy, S1MMEtore::msg_sm_1_i_4_r_7_t_8_cnt, S1MMEtore::msg_sm_1_i_4_r_7_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_4_r_7_t_9_busy, S1MMEtore::msg_sm_1_i_4_r_7_t_9_cnt, S1MMEtore::msg_sm_1_i_4_r_7_t_9, pSctp);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_4_r_7_t_0_busy, S1MMEtore::msg_sm_2_i_4_r_7_t_0_cnt, S1MMEtore::msg_sm_2_i_4_r_7_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_4_r_7_t_1_busy, S1MMEtore::msg_sm_2_i_4_r_7_t_1_cnt, S1MMEtore::msg_sm_2_i_4_r_7_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_4_r_7_t_2_busy, S1MMEtore::msg_sm_2_i_4_r_7_t_2_cnt, S1MMEtore::msg_sm_2_i_4_r_7_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_4_r_7_t_3_busy, S1MMEtore::msg_sm_2_i_4_r_7_t_3_cnt, S1MMEtore::msg_sm_2_i_4_r_7_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_4_r_7_t_4_busy, S1MMEtore::msg_sm_2_i_4_r_7_t_4_cnt, S1MMEtore::msg_sm_2_i_4_r_7_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_4_r_7_t_5_busy, S1MMEtore::msg_sm_2_i_4_r_7_t_5_cnt, S1MMEtore::msg_sm_2_i_4_r_7_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_4_r_7_t_6_busy, S1MMEtore::msg_sm_2_i_4_r_7_t_6_cnt, S1MMEtore::msg_sm_2_i_4_r_7_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_4_r_7_t_7_busy, S1MMEtore::msg_sm_2_i_4_r_7_t_7_cnt, S1MMEtore::msg_sm_2_i_4_r_7_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_4_r_7_t_8_busy, S1MMEtore::msg_sm_2_i_4_r_7_t_8_cnt, S1MMEtore::msg_sm_2_i_4_r_7_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_4_r_7_t_9_busy, S1MMEtore::msg_sm_2_i_4_r_7_t_9_cnt, S1MMEtore::msg_sm_2_i_4_r_7_t_9, pSctp);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_4_r_7_t_0_busy, S1MMEtore::msg_sm_3_i_4_r_7_t_0_cnt, S1MMEtore::msg_sm_3_i_4_r_7_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_4_r_7_t_1_busy, S1MMEtore::msg_sm_3_i_4_r_7_t_1_cnt, S1MMEtore::msg_sm_3_i_4_r_7_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_4_r_7_t_2_busy, S1MMEtore::msg_sm_3_i_4_r_7_t_2_cnt, S1MMEtore::msg_sm_3_i_4_r_7_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_4_r_7_t_3_busy, S1MMEtore::msg_sm_3_i_4_r_7_t_3_cnt, S1MMEtore::msg_sm_3_i_4_r_7_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_4_r_7_t_4_busy, S1MMEtore::msg_sm_3_i_4_r_7_t_4_cnt, S1MMEtore::msg_sm_3_i_4_r_7_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_4_r_7_t_5_busy, S1MMEtore::msg_sm_3_i_4_r_7_t_5_cnt, S1MMEtore::msg_sm_3_i_4_r_7_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_4_r_7_t_6_busy, S1MMEtore::msg_sm_3_i_4_r_7_t_6_cnt, S1MMEtore::msg_sm_3_i_4_r_7_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_4_r_7_t_7_busy, S1MMEtore::msg_sm_3_i_4_r_7_t_7_cnt, S1MMEtore::msg_sm_3_i_4_r_7_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_4_r_7_t_8_busy, S1MMEtore::msg_sm_3_i_4_r_7_t_8_cnt, S1MMEtore::msg_sm_3_i_4_r_7_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_4_r_7_t_9_busy, S1MMEtore::msg_sm_3_i_4_r_7_t_9_cnt, S1MMEtore::msg_sm_3_i_4_r_7_t_9, pSctp);
				break;
			}
			break;
	}
}


VOID SctpMessageBroker::pushToQueue_i_5_r_0(Sctp *pSctp, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_5_r_0_t_0_busy, S1MMEtore::msg_sm_0_i_5_r_0_t_0_cnt, S1MMEtore::msg_sm_0_i_5_r_0_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_5_r_0_t_1_busy, S1MMEtore::msg_sm_0_i_5_r_0_t_1_cnt, S1MMEtore::msg_sm_0_i_5_r_0_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_5_r_0_t_2_busy, S1MMEtore::msg_sm_0_i_5_r_0_t_2_cnt, S1MMEtore::msg_sm_0_i_5_r_0_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_5_r_0_t_3_busy, S1MMEtore::msg_sm_0_i_5_r_0_t_3_cnt, S1MMEtore::msg_sm_0_i_5_r_0_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_5_r_0_t_4_busy, S1MMEtore::msg_sm_0_i_5_r_0_t_4_cnt, S1MMEtore::msg_sm_0_i_5_r_0_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_5_r_0_t_5_busy, S1MMEtore::msg_sm_0_i_5_r_0_t_5_cnt, S1MMEtore::msg_sm_0_i_5_r_0_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_5_r_0_t_6_busy, S1MMEtore::msg_sm_0_i_5_r_0_t_6_cnt, S1MMEtore::msg_sm_0_i_5_r_0_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_5_r_0_t_7_busy, S1MMEtore::msg_sm_0_i_5_r_0_t_7_cnt, S1MMEtore::msg_sm_0_i_5_r_0_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_5_r_0_t_8_busy, S1MMEtore::msg_sm_0_i_5_r_0_t_8_cnt, S1MMEtore::msg_sm_0_i_5_r_0_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_5_r_0_t_9_busy, S1MMEtore::msg_sm_0_i_5_r_0_t_9_cnt, S1MMEtore::msg_sm_0_i_5_r_0_t_9, pSctp);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_5_r_0_t_0_busy, S1MMEtore::msg_sm_1_i_5_r_0_t_0_cnt, S1MMEtore::msg_sm_1_i_5_r_0_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_5_r_0_t_1_busy, S1MMEtore::msg_sm_1_i_5_r_0_t_1_cnt, S1MMEtore::msg_sm_1_i_5_r_0_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_5_r_0_t_2_busy, S1MMEtore::msg_sm_1_i_5_r_0_t_2_cnt, S1MMEtore::msg_sm_1_i_5_r_0_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_5_r_0_t_3_busy, S1MMEtore::msg_sm_1_i_5_r_0_t_3_cnt, S1MMEtore::msg_sm_1_i_5_r_0_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_5_r_0_t_4_busy, S1MMEtore::msg_sm_1_i_5_r_0_t_4_cnt, S1MMEtore::msg_sm_1_i_5_r_0_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_5_r_0_t_5_busy, S1MMEtore::msg_sm_1_i_5_r_0_t_5_cnt, S1MMEtore::msg_sm_1_i_5_r_0_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_5_r_0_t_6_busy, S1MMEtore::msg_sm_1_i_5_r_0_t_6_cnt, S1MMEtore::msg_sm_1_i_5_r_0_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_5_r_0_t_7_busy, S1MMEtore::msg_sm_1_i_5_r_0_t_7_cnt, S1MMEtore::msg_sm_1_i_5_r_0_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_5_r_0_t_8_busy, S1MMEtore::msg_sm_1_i_5_r_0_t_8_cnt, S1MMEtore::msg_sm_1_i_5_r_0_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_5_r_0_t_9_busy, S1MMEtore::msg_sm_1_i_5_r_0_t_9_cnt, S1MMEtore::msg_sm_1_i_5_r_0_t_9, pSctp);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_5_r_0_t_0_busy, S1MMEtore::msg_sm_2_i_5_r_0_t_0_cnt, S1MMEtore::msg_sm_2_i_5_r_0_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_5_r_0_t_1_busy, S1MMEtore::msg_sm_2_i_5_r_0_t_1_cnt, S1MMEtore::msg_sm_2_i_5_r_0_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_5_r_0_t_2_busy, S1MMEtore::msg_sm_2_i_5_r_0_t_2_cnt, S1MMEtore::msg_sm_2_i_5_r_0_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_5_r_0_t_3_busy, S1MMEtore::msg_sm_2_i_5_r_0_t_3_cnt, S1MMEtore::msg_sm_2_i_5_r_0_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_5_r_0_t_4_busy, S1MMEtore::msg_sm_2_i_5_r_0_t_4_cnt, S1MMEtore::msg_sm_2_i_5_r_0_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_5_r_0_t_5_busy, S1MMEtore::msg_sm_2_i_5_r_0_t_5_cnt, S1MMEtore::msg_sm_2_i_5_r_0_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_5_r_0_t_6_busy, S1MMEtore::msg_sm_2_i_5_r_0_t_6_cnt, S1MMEtore::msg_sm_2_i_5_r_0_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_5_r_0_t_7_busy, S1MMEtore::msg_sm_2_i_5_r_0_t_7_cnt, S1MMEtore::msg_sm_2_i_5_r_0_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_5_r_0_t_8_busy, S1MMEtore::msg_sm_2_i_5_r_0_t_8_cnt, S1MMEtore::msg_sm_2_i_5_r_0_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_5_r_0_t_9_busy, S1MMEtore::msg_sm_2_i_5_r_0_t_9_cnt, S1MMEtore::msg_sm_2_i_5_r_0_t_9, pSctp);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_5_r_0_t_0_busy, S1MMEtore::msg_sm_3_i_5_r_0_t_0_cnt, S1MMEtore::msg_sm_3_i_5_r_0_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_5_r_0_t_1_busy, S1MMEtore::msg_sm_3_i_5_r_0_t_1_cnt, S1MMEtore::msg_sm_3_i_5_r_0_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_5_r_0_t_2_busy, S1MMEtore::msg_sm_3_i_5_r_0_t_2_cnt, S1MMEtore::msg_sm_3_i_5_r_0_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_5_r_0_t_3_busy, S1MMEtore::msg_sm_3_i_5_r_0_t_3_cnt, S1MMEtore::msg_sm_3_i_5_r_0_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_5_r_0_t_4_busy, S1MMEtore::msg_sm_3_i_5_r_0_t_4_cnt, S1MMEtore::msg_sm_3_i_5_r_0_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_5_r_0_t_5_busy, S1MMEtore::msg_sm_3_i_5_r_0_t_5_cnt, S1MMEtore::msg_sm_3_i_5_r_0_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_5_r_0_t_6_busy, S1MMEtore::msg_sm_3_i_5_r_0_t_6_cnt, S1MMEtore::msg_sm_3_i_5_r_0_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_5_r_0_t_7_busy, S1MMEtore::msg_sm_3_i_5_r_0_t_7_cnt, S1MMEtore::msg_sm_3_i_5_r_0_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_5_r_0_t_8_busy, S1MMEtore::msg_sm_3_i_5_r_0_t_8_cnt, S1MMEtore::msg_sm_3_i_5_r_0_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_5_r_0_t_9_busy, S1MMEtore::msg_sm_3_i_5_r_0_t_9_cnt, S1MMEtore::msg_sm_3_i_5_r_0_t_9, pSctp);
				break;
			}
			break;
	}
}

VOID SctpMessageBroker::pushToQueue_i_5_r_1(Sctp *pSctp, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_5_r_1_t_0_busy, S1MMEtore::msg_sm_0_i_5_r_1_t_0_cnt, S1MMEtore::msg_sm_0_i_5_r_1_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_5_r_1_t_1_busy, S1MMEtore::msg_sm_0_i_5_r_1_t_1_cnt, S1MMEtore::msg_sm_0_i_5_r_1_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_5_r_1_t_2_busy, S1MMEtore::msg_sm_0_i_5_r_1_t_2_cnt, S1MMEtore::msg_sm_0_i_5_r_1_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_5_r_1_t_3_busy, S1MMEtore::msg_sm_0_i_5_r_1_t_3_cnt, S1MMEtore::msg_sm_0_i_5_r_1_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_5_r_1_t_4_busy, S1MMEtore::msg_sm_0_i_5_r_1_t_4_cnt, S1MMEtore::msg_sm_0_i_5_r_1_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_5_r_1_t_5_busy, S1MMEtore::msg_sm_0_i_5_r_1_t_5_cnt, S1MMEtore::msg_sm_0_i_5_r_1_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_5_r_1_t_6_busy, S1MMEtore::msg_sm_0_i_5_r_1_t_6_cnt, S1MMEtore::msg_sm_0_i_5_r_1_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_5_r_1_t_7_busy, S1MMEtore::msg_sm_0_i_5_r_1_t_7_cnt, S1MMEtore::msg_sm_0_i_5_r_1_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_5_r_1_t_8_busy, S1MMEtore::msg_sm_0_i_5_r_1_t_8_cnt, S1MMEtore::msg_sm_0_i_5_r_1_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_5_r_1_t_9_busy, S1MMEtore::msg_sm_0_i_5_r_1_t_9_cnt, S1MMEtore::msg_sm_0_i_5_r_1_t_9, pSctp);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_5_r_1_t_0_busy, S1MMEtore::msg_sm_1_i_5_r_1_t_0_cnt, S1MMEtore::msg_sm_1_i_5_r_1_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_5_r_1_t_1_busy, S1MMEtore::msg_sm_1_i_5_r_1_t_1_cnt, S1MMEtore::msg_sm_1_i_5_r_1_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_5_r_1_t_2_busy, S1MMEtore::msg_sm_1_i_5_r_1_t_2_cnt, S1MMEtore::msg_sm_1_i_5_r_1_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_5_r_1_t_3_busy, S1MMEtore::msg_sm_1_i_5_r_1_t_3_cnt, S1MMEtore::msg_sm_1_i_5_r_1_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_5_r_1_t_4_busy, S1MMEtore::msg_sm_1_i_5_r_1_t_4_cnt, S1MMEtore::msg_sm_1_i_5_r_1_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_5_r_1_t_5_busy, S1MMEtore::msg_sm_1_i_5_r_1_t_5_cnt, S1MMEtore::msg_sm_1_i_5_r_1_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_5_r_1_t_6_busy, S1MMEtore::msg_sm_1_i_5_r_1_t_6_cnt, S1MMEtore::msg_sm_1_i_5_r_1_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_5_r_1_t_7_busy, S1MMEtore::msg_sm_1_i_5_r_1_t_7_cnt, S1MMEtore::msg_sm_1_i_5_r_1_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_5_r_1_t_8_busy, S1MMEtore::msg_sm_1_i_5_r_1_t_8_cnt, S1MMEtore::msg_sm_1_i_5_r_1_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_5_r_1_t_9_busy, S1MMEtore::msg_sm_1_i_5_r_1_t_9_cnt, S1MMEtore::msg_sm_1_i_5_r_1_t_9, pSctp);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_5_r_1_t_0_busy, S1MMEtore::msg_sm_2_i_5_r_1_t_0_cnt, S1MMEtore::msg_sm_2_i_5_r_1_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_5_r_1_t_1_busy, S1MMEtore::msg_sm_2_i_5_r_1_t_1_cnt, S1MMEtore::msg_sm_2_i_5_r_1_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_5_r_1_t_2_busy, S1MMEtore::msg_sm_2_i_5_r_1_t_2_cnt, S1MMEtore::msg_sm_2_i_5_r_1_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_5_r_1_t_3_busy, S1MMEtore::msg_sm_2_i_5_r_1_t_3_cnt, S1MMEtore::msg_sm_2_i_5_r_1_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_5_r_1_t_4_busy, S1MMEtore::msg_sm_2_i_5_r_1_t_4_cnt, S1MMEtore::msg_sm_2_i_5_r_1_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_5_r_1_t_5_busy, S1MMEtore::msg_sm_2_i_5_r_1_t_5_cnt, S1MMEtore::msg_sm_2_i_5_r_1_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_5_r_1_t_6_busy, S1MMEtore::msg_sm_2_i_5_r_1_t_6_cnt, S1MMEtore::msg_sm_2_i_5_r_1_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_5_r_1_t_7_busy, S1MMEtore::msg_sm_2_i_5_r_1_t_7_cnt, S1MMEtore::msg_sm_2_i_5_r_1_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_5_r_1_t_8_busy, S1MMEtore::msg_sm_2_i_5_r_1_t_8_cnt, S1MMEtore::msg_sm_2_i_5_r_1_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_5_r_1_t_9_busy, S1MMEtore::msg_sm_2_i_5_r_1_t_9_cnt, S1MMEtore::msg_sm_2_i_5_r_1_t_9, pSctp);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_5_r_1_t_0_busy, S1MMEtore::msg_sm_3_i_5_r_1_t_0_cnt, S1MMEtore::msg_sm_3_i_5_r_1_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_5_r_1_t_1_busy, S1MMEtore::msg_sm_3_i_5_r_1_t_1_cnt, S1MMEtore::msg_sm_3_i_5_r_1_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_5_r_1_t_2_busy, S1MMEtore::msg_sm_3_i_5_r_1_t_2_cnt, S1MMEtore::msg_sm_3_i_5_r_1_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_5_r_1_t_3_busy, S1MMEtore::msg_sm_3_i_5_r_1_t_3_cnt, S1MMEtore::msg_sm_3_i_5_r_1_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_5_r_1_t_4_busy, S1MMEtore::msg_sm_3_i_5_r_1_t_4_cnt, S1MMEtore::msg_sm_3_i_5_r_1_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_5_r_1_t_5_busy, S1MMEtore::msg_sm_3_i_5_r_1_t_5_cnt, S1MMEtore::msg_sm_3_i_5_r_1_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_5_r_1_t_6_busy, S1MMEtore::msg_sm_3_i_5_r_1_t_6_cnt, S1MMEtore::msg_sm_3_i_5_r_1_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_5_r_1_t_7_busy, S1MMEtore::msg_sm_3_i_5_r_1_t_7_cnt, S1MMEtore::msg_sm_3_i_5_r_1_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_5_r_1_t_8_busy, S1MMEtore::msg_sm_3_i_5_r_1_t_8_cnt, S1MMEtore::msg_sm_3_i_5_r_1_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_5_r_1_t_9_busy, S1MMEtore::msg_sm_3_i_5_r_1_t_9_cnt, S1MMEtore::msg_sm_3_i_5_r_1_t_9, pSctp);
				break;
			}
			break;
	}
}

VOID SctpMessageBroker::pushToQueue_i_5_r_2(Sctp *pSctp, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_5_r_2_t_0_busy, S1MMEtore::msg_sm_0_i_5_r_2_t_0_cnt, S1MMEtore::msg_sm_0_i_5_r_2_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_5_r_2_t_1_busy, S1MMEtore::msg_sm_0_i_5_r_2_t_1_cnt, S1MMEtore::msg_sm_0_i_5_r_2_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_5_r_2_t_2_busy, S1MMEtore::msg_sm_0_i_5_r_2_t_2_cnt, S1MMEtore::msg_sm_0_i_5_r_2_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_5_r_2_t_3_busy, S1MMEtore::msg_sm_0_i_5_r_2_t_3_cnt, S1MMEtore::msg_sm_0_i_5_r_2_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_5_r_2_t_4_busy, S1MMEtore::msg_sm_0_i_5_r_2_t_4_cnt, S1MMEtore::msg_sm_0_i_5_r_2_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_5_r_2_t_5_busy, S1MMEtore::msg_sm_0_i_5_r_2_t_5_cnt, S1MMEtore::msg_sm_0_i_5_r_2_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_5_r_2_t_6_busy, S1MMEtore::msg_sm_0_i_5_r_2_t_6_cnt, S1MMEtore::msg_sm_0_i_5_r_2_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_5_r_2_t_7_busy, S1MMEtore::msg_sm_0_i_5_r_2_t_7_cnt, S1MMEtore::msg_sm_0_i_5_r_2_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_5_r_2_t_8_busy, S1MMEtore::msg_sm_0_i_5_r_2_t_8_cnt, S1MMEtore::msg_sm_0_i_5_r_2_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_5_r_2_t_9_busy, S1MMEtore::msg_sm_0_i_5_r_2_t_9_cnt, S1MMEtore::msg_sm_0_i_5_r_2_t_9, pSctp);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_5_r_2_t_0_busy, S1MMEtore::msg_sm_1_i_5_r_2_t_0_cnt, S1MMEtore::msg_sm_1_i_5_r_2_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_5_r_2_t_1_busy, S1MMEtore::msg_sm_1_i_5_r_2_t_1_cnt, S1MMEtore::msg_sm_1_i_5_r_2_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_5_r_2_t_2_busy, S1MMEtore::msg_sm_1_i_5_r_2_t_2_cnt, S1MMEtore::msg_sm_1_i_5_r_2_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_5_r_2_t_3_busy, S1MMEtore::msg_sm_1_i_5_r_2_t_3_cnt, S1MMEtore::msg_sm_1_i_5_r_2_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_5_r_2_t_4_busy, S1MMEtore::msg_sm_1_i_5_r_2_t_4_cnt, S1MMEtore::msg_sm_1_i_5_r_2_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_5_r_2_t_5_busy, S1MMEtore::msg_sm_1_i_5_r_2_t_5_cnt, S1MMEtore::msg_sm_1_i_5_r_2_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_5_r_2_t_6_busy, S1MMEtore::msg_sm_1_i_5_r_2_t_6_cnt, S1MMEtore::msg_sm_1_i_5_r_2_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_5_r_2_t_7_busy, S1MMEtore::msg_sm_1_i_5_r_2_t_7_cnt, S1MMEtore::msg_sm_1_i_5_r_2_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_5_r_2_t_8_busy, S1MMEtore::msg_sm_1_i_5_r_2_t_8_cnt, S1MMEtore::msg_sm_1_i_5_r_2_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_5_r_2_t_9_busy, S1MMEtore::msg_sm_1_i_5_r_2_t_9_cnt, S1MMEtore::msg_sm_1_i_5_r_2_t_9, pSctp);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_5_r_2_t_0_busy, S1MMEtore::msg_sm_2_i_5_r_2_t_0_cnt, S1MMEtore::msg_sm_2_i_5_r_2_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_5_r_2_t_1_busy, S1MMEtore::msg_sm_2_i_5_r_2_t_1_cnt, S1MMEtore::msg_sm_2_i_5_r_2_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_5_r_2_t_2_busy, S1MMEtore::msg_sm_2_i_5_r_2_t_2_cnt, S1MMEtore::msg_sm_2_i_5_r_2_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_5_r_2_t_3_busy, S1MMEtore::msg_sm_2_i_5_r_2_t_3_cnt, S1MMEtore::msg_sm_2_i_5_r_2_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_5_r_2_t_4_busy, S1MMEtore::msg_sm_2_i_5_r_2_t_4_cnt, S1MMEtore::msg_sm_2_i_5_r_2_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_5_r_2_t_5_busy, S1MMEtore::msg_sm_2_i_5_r_2_t_5_cnt, S1MMEtore::msg_sm_2_i_5_r_2_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_5_r_2_t_6_busy, S1MMEtore::msg_sm_2_i_5_r_2_t_6_cnt, S1MMEtore::msg_sm_2_i_5_r_2_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_5_r_2_t_7_busy, S1MMEtore::msg_sm_2_i_5_r_2_t_7_cnt, S1MMEtore::msg_sm_2_i_5_r_2_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_5_r_2_t_8_busy, S1MMEtore::msg_sm_2_i_5_r_2_t_8_cnt, S1MMEtore::msg_sm_2_i_5_r_2_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_5_r_2_t_9_busy, S1MMEtore::msg_sm_2_i_5_r_2_t_9_cnt, S1MMEtore::msg_sm_2_i_5_r_2_t_9, pSctp);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_5_r_2_t_0_busy, S1MMEtore::msg_sm_3_i_5_r_2_t_0_cnt, S1MMEtore::msg_sm_3_i_5_r_2_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_5_r_2_t_1_busy, S1MMEtore::msg_sm_3_i_5_r_2_t_1_cnt, S1MMEtore::msg_sm_3_i_5_r_2_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_5_r_2_t_2_busy, S1MMEtore::msg_sm_3_i_5_r_2_t_2_cnt, S1MMEtore::msg_sm_3_i_5_r_2_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_5_r_2_t_3_busy, S1MMEtore::msg_sm_3_i_5_r_2_t_3_cnt, S1MMEtore::msg_sm_3_i_5_r_2_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_5_r_2_t_4_busy, S1MMEtore::msg_sm_3_i_5_r_2_t_4_cnt, S1MMEtore::msg_sm_3_i_5_r_2_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_5_r_2_t_5_busy, S1MMEtore::msg_sm_3_i_5_r_2_t_5_cnt, S1MMEtore::msg_sm_3_i_5_r_2_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_5_r_2_t_6_busy, S1MMEtore::msg_sm_3_i_5_r_2_t_6_cnt, S1MMEtore::msg_sm_3_i_5_r_2_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_5_r_2_t_7_busy, S1MMEtore::msg_sm_3_i_5_r_2_t_7_cnt, S1MMEtore::msg_sm_3_i_5_r_2_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_5_r_2_t_8_busy, S1MMEtore::msg_sm_3_i_5_r_2_t_8_cnt, S1MMEtore::msg_sm_3_i_5_r_2_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_5_r_2_t_9_busy, S1MMEtore::msg_sm_3_i_5_r_2_t_9_cnt, S1MMEtore::msg_sm_3_i_5_r_2_t_9, pSctp);
				break;
			}
			break;
	}
}

VOID SctpMessageBroker::pushToQueue_i_5_r_3(Sctp *pSctp, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_5_r_3_t_0_busy, S1MMEtore::msg_sm_0_i_5_r_3_t_0_cnt, S1MMEtore::msg_sm_0_i_5_r_3_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_5_r_3_t_1_busy, S1MMEtore::msg_sm_0_i_5_r_3_t_1_cnt, S1MMEtore::msg_sm_0_i_5_r_3_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_5_r_3_t_2_busy, S1MMEtore::msg_sm_0_i_5_r_3_t_2_cnt, S1MMEtore::msg_sm_0_i_5_r_3_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_5_r_3_t_3_busy, S1MMEtore::msg_sm_0_i_5_r_3_t_3_cnt, S1MMEtore::msg_sm_0_i_5_r_3_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_5_r_3_t_4_busy, S1MMEtore::msg_sm_0_i_5_r_3_t_4_cnt, S1MMEtore::msg_sm_0_i_5_r_3_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_5_r_3_t_5_busy, S1MMEtore::msg_sm_0_i_5_r_3_t_5_cnt, S1MMEtore::msg_sm_0_i_5_r_3_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_5_r_3_t_6_busy, S1MMEtore::msg_sm_0_i_5_r_3_t_6_cnt, S1MMEtore::msg_sm_0_i_5_r_3_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_5_r_3_t_7_busy, S1MMEtore::msg_sm_0_i_5_r_3_t_7_cnt, S1MMEtore::msg_sm_0_i_5_r_3_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_5_r_3_t_8_busy, S1MMEtore::msg_sm_0_i_5_r_3_t_8_cnt, S1MMEtore::msg_sm_0_i_5_r_3_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_5_r_3_t_9_busy, S1MMEtore::msg_sm_0_i_5_r_3_t_9_cnt, S1MMEtore::msg_sm_0_i_5_r_3_t_9, pSctp);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_5_r_3_t_0_busy, S1MMEtore::msg_sm_1_i_5_r_3_t_0_cnt, S1MMEtore::msg_sm_1_i_5_r_3_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_5_r_3_t_1_busy, S1MMEtore::msg_sm_1_i_5_r_3_t_1_cnt, S1MMEtore::msg_sm_1_i_5_r_3_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_5_r_3_t_2_busy, S1MMEtore::msg_sm_1_i_5_r_3_t_2_cnt, S1MMEtore::msg_sm_1_i_5_r_3_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_5_r_3_t_3_busy, S1MMEtore::msg_sm_1_i_5_r_3_t_3_cnt, S1MMEtore::msg_sm_1_i_5_r_3_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_5_r_3_t_4_busy, S1MMEtore::msg_sm_1_i_5_r_3_t_4_cnt, S1MMEtore::msg_sm_1_i_5_r_3_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_5_r_3_t_5_busy, S1MMEtore::msg_sm_1_i_5_r_3_t_5_cnt, S1MMEtore::msg_sm_1_i_5_r_3_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_5_r_3_t_6_busy, S1MMEtore::msg_sm_1_i_5_r_3_t_6_cnt, S1MMEtore::msg_sm_1_i_5_r_3_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_5_r_3_t_7_busy, S1MMEtore::msg_sm_1_i_5_r_3_t_7_cnt, S1MMEtore::msg_sm_1_i_5_r_3_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_5_r_3_t_8_busy, S1MMEtore::msg_sm_1_i_5_r_3_t_8_cnt, S1MMEtore::msg_sm_1_i_5_r_3_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_5_r_3_t_9_busy, S1MMEtore::msg_sm_1_i_5_r_3_t_9_cnt, S1MMEtore::msg_sm_1_i_5_r_3_t_9, pSctp);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_5_r_3_t_0_busy, S1MMEtore::msg_sm_2_i_5_r_3_t_0_cnt, S1MMEtore::msg_sm_2_i_5_r_3_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_5_r_3_t_1_busy, S1MMEtore::msg_sm_2_i_5_r_3_t_1_cnt, S1MMEtore::msg_sm_2_i_5_r_3_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_5_r_3_t_2_busy, S1MMEtore::msg_sm_2_i_5_r_3_t_2_cnt, S1MMEtore::msg_sm_2_i_5_r_3_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_5_r_3_t_3_busy, S1MMEtore::msg_sm_2_i_5_r_3_t_3_cnt, S1MMEtore::msg_sm_2_i_5_r_3_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_5_r_3_t_4_busy, S1MMEtore::msg_sm_2_i_5_r_3_t_4_cnt, S1MMEtore::msg_sm_2_i_5_r_3_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_5_r_3_t_5_busy, S1MMEtore::msg_sm_2_i_5_r_3_t_5_cnt, S1MMEtore::msg_sm_2_i_5_r_3_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_5_r_3_t_6_busy, S1MMEtore::msg_sm_2_i_5_r_3_t_6_cnt, S1MMEtore::msg_sm_2_i_5_r_3_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_5_r_3_t_7_busy, S1MMEtore::msg_sm_2_i_5_r_3_t_7_cnt, S1MMEtore::msg_sm_2_i_5_r_3_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_5_r_3_t_8_busy, S1MMEtore::msg_sm_2_i_5_r_3_t_8_cnt, S1MMEtore::msg_sm_2_i_5_r_3_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_5_r_3_t_9_busy, S1MMEtore::msg_sm_2_i_5_r_3_t_9_cnt, S1MMEtore::msg_sm_2_i_5_r_3_t_9, pSctp);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_5_r_3_t_0_busy, S1MMEtore::msg_sm_3_i_5_r_3_t_0_cnt, S1MMEtore::msg_sm_3_i_5_r_3_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_5_r_3_t_1_busy, S1MMEtore::msg_sm_3_i_5_r_3_t_1_cnt, S1MMEtore::msg_sm_3_i_5_r_3_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_5_r_3_t_2_busy, S1MMEtore::msg_sm_3_i_5_r_3_t_2_cnt, S1MMEtore::msg_sm_3_i_5_r_3_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_5_r_3_t_3_busy, S1MMEtore::msg_sm_3_i_5_r_3_t_3_cnt, S1MMEtore::msg_sm_3_i_5_r_3_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_5_r_3_t_4_busy, S1MMEtore::msg_sm_3_i_5_r_3_t_4_cnt, S1MMEtore::msg_sm_3_i_5_r_3_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_5_r_3_t_5_busy, S1MMEtore::msg_sm_3_i_5_r_3_t_5_cnt, S1MMEtore::msg_sm_3_i_5_r_3_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_5_r_3_t_6_busy, S1MMEtore::msg_sm_3_i_5_r_3_t_6_cnt, S1MMEtore::msg_sm_3_i_5_r_3_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_5_r_3_t_7_busy, S1MMEtore::msg_sm_3_i_5_r_3_t_7_cnt, S1MMEtore::msg_sm_3_i_5_r_3_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_5_r_3_t_8_busy, S1MMEtore::msg_sm_3_i_5_r_3_t_8_cnt, S1MMEtore::msg_sm_3_i_5_r_3_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_5_r_3_t_9_busy, S1MMEtore::msg_sm_3_i_5_r_3_t_9_cnt, S1MMEtore::msg_sm_3_i_5_r_3_t_9, pSctp);
				break;
			}
			break;
	}
}

VOID SctpMessageBroker::pushToQueue_i_5_r_4(Sctp *pSctp, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_5_r_4_t_0_busy, S1MMEtore::msg_sm_0_i_5_r_4_t_0_cnt, S1MMEtore::msg_sm_0_i_5_r_4_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_5_r_4_t_1_busy, S1MMEtore::msg_sm_0_i_5_r_4_t_1_cnt, S1MMEtore::msg_sm_0_i_5_r_4_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_5_r_4_t_2_busy, S1MMEtore::msg_sm_0_i_5_r_4_t_2_cnt, S1MMEtore::msg_sm_0_i_5_r_4_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_5_r_4_t_3_busy, S1MMEtore::msg_sm_0_i_5_r_4_t_3_cnt, S1MMEtore::msg_sm_0_i_5_r_4_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_5_r_4_t_4_busy, S1MMEtore::msg_sm_0_i_5_r_4_t_4_cnt, S1MMEtore::msg_sm_0_i_5_r_4_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_5_r_4_t_5_busy, S1MMEtore::msg_sm_0_i_5_r_4_t_5_cnt, S1MMEtore::msg_sm_0_i_5_r_4_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_5_r_4_t_6_busy, S1MMEtore::msg_sm_0_i_5_r_4_t_6_cnt, S1MMEtore::msg_sm_0_i_5_r_4_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_5_r_4_t_7_busy, S1MMEtore::msg_sm_0_i_5_r_4_t_7_cnt, S1MMEtore::msg_sm_0_i_5_r_4_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_5_r_4_t_8_busy, S1MMEtore::msg_sm_0_i_5_r_4_t_8_cnt, S1MMEtore::msg_sm_0_i_5_r_4_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_5_r_4_t_9_busy, S1MMEtore::msg_sm_0_i_5_r_4_t_9_cnt, S1MMEtore::msg_sm_0_i_5_r_4_t_9, pSctp);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_5_r_4_t_0_busy, S1MMEtore::msg_sm_1_i_5_r_4_t_0_cnt, S1MMEtore::msg_sm_1_i_5_r_4_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_5_r_4_t_1_busy, S1MMEtore::msg_sm_1_i_5_r_4_t_1_cnt, S1MMEtore::msg_sm_1_i_5_r_4_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_5_r_4_t_2_busy, S1MMEtore::msg_sm_1_i_5_r_4_t_2_cnt, S1MMEtore::msg_sm_1_i_5_r_4_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_5_r_4_t_3_busy, S1MMEtore::msg_sm_1_i_5_r_4_t_3_cnt, S1MMEtore::msg_sm_1_i_5_r_4_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_5_r_4_t_4_busy, S1MMEtore::msg_sm_1_i_5_r_4_t_4_cnt, S1MMEtore::msg_sm_1_i_5_r_4_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_5_r_4_t_5_busy, S1MMEtore::msg_sm_1_i_5_r_4_t_5_cnt, S1MMEtore::msg_sm_1_i_5_r_4_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_5_r_4_t_6_busy, S1MMEtore::msg_sm_1_i_5_r_4_t_6_cnt, S1MMEtore::msg_sm_1_i_5_r_4_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_5_r_4_t_7_busy, S1MMEtore::msg_sm_1_i_5_r_4_t_7_cnt, S1MMEtore::msg_sm_1_i_5_r_4_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_5_r_4_t_8_busy, S1MMEtore::msg_sm_1_i_5_r_4_t_8_cnt, S1MMEtore::msg_sm_1_i_5_r_4_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_5_r_4_t_9_busy, S1MMEtore::msg_sm_1_i_5_r_4_t_9_cnt, S1MMEtore::msg_sm_1_i_5_r_4_t_9, pSctp);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_5_r_4_t_0_busy, S1MMEtore::msg_sm_2_i_5_r_4_t_0_cnt, S1MMEtore::msg_sm_2_i_5_r_4_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_5_r_4_t_1_busy, S1MMEtore::msg_sm_2_i_5_r_4_t_1_cnt, S1MMEtore::msg_sm_2_i_5_r_4_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_5_r_4_t_2_busy, S1MMEtore::msg_sm_2_i_5_r_4_t_2_cnt, S1MMEtore::msg_sm_2_i_5_r_4_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_5_r_4_t_3_busy, S1MMEtore::msg_sm_2_i_5_r_4_t_3_cnt, S1MMEtore::msg_sm_2_i_5_r_4_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_5_r_4_t_4_busy, S1MMEtore::msg_sm_2_i_5_r_4_t_4_cnt, S1MMEtore::msg_sm_2_i_5_r_4_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_5_r_4_t_5_busy, S1MMEtore::msg_sm_2_i_5_r_4_t_5_cnt, S1MMEtore::msg_sm_2_i_5_r_4_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_5_r_4_t_6_busy, S1MMEtore::msg_sm_2_i_5_r_4_t_6_cnt, S1MMEtore::msg_sm_2_i_5_r_4_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_5_r_4_t_7_busy, S1MMEtore::msg_sm_2_i_5_r_4_t_7_cnt, S1MMEtore::msg_sm_2_i_5_r_4_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_5_r_4_t_8_busy, S1MMEtore::msg_sm_2_i_5_r_4_t_8_cnt, S1MMEtore::msg_sm_2_i_5_r_4_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_5_r_4_t_9_busy, S1MMEtore::msg_sm_2_i_5_r_4_t_9_cnt, S1MMEtore::msg_sm_2_i_5_r_4_t_9, pSctp);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_5_r_4_t_0_busy, S1MMEtore::msg_sm_3_i_5_r_4_t_0_cnt, S1MMEtore::msg_sm_3_i_5_r_4_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_5_r_4_t_1_busy, S1MMEtore::msg_sm_3_i_5_r_4_t_1_cnt, S1MMEtore::msg_sm_3_i_5_r_4_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_5_r_4_t_2_busy, S1MMEtore::msg_sm_3_i_5_r_4_t_2_cnt, S1MMEtore::msg_sm_3_i_5_r_4_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_5_r_4_t_3_busy, S1MMEtore::msg_sm_3_i_5_r_4_t_3_cnt, S1MMEtore::msg_sm_3_i_5_r_4_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_5_r_4_t_4_busy, S1MMEtore::msg_sm_3_i_5_r_4_t_4_cnt, S1MMEtore::msg_sm_3_i_5_r_4_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_5_r_4_t_5_busy, S1MMEtore::msg_sm_3_i_5_r_4_t_5_cnt, S1MMEtore::msg_sm_3_i_5_r_4_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_5_r_4_t_6_busy, S1MMEtore::msg_sm_3_i_5_r_4_t_6_cnt, S1MMEtore::msg_sm_3_i_5_r_4_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_5_r_4_t_7_busy, S1MMEtore::msg_sm_3_i_5_r_4_t_7_cnt, S1MMEtore::msg_sm_3_i_5_r_4_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_5_r_4_t_8_busy, S1MMEtore::msg_sm_3_i_5_r_4_t_8_cnt, S1MMEtore::msg_sm_3_i_5_r_4_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_5_r_4_t_9_busy, S1MMEtore::msg_sm_3_i_5_r_4_t_9_cnt, S1MMEtore::msg_sm_3_i_5_r_4_t_9, pSctp);
				break;
			}
			break;
	}
}

VOID SctpMessageBroker::pushToQueue_i_5_r_5(Sctp *pSctp, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_5_r_5_t_0_busy, S1MMEtore::msg_sm_0_i_5_r_5_t_0_cnt, S1MMEtore::msg_sm_0_i_5_r_5_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_5_r_5_t_1_busy, S1MMEtore::msg_sm_0_i_5_r_5_t_1_cnt, S1MMEtore::msg_sm_0_i_5_r_5_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_5_r_5_t_2_busy, S1MMEtore::msg_sm_0_i_5_r_5_t_2_cnt, S1MMEtore::msg_sm_0_i_5_r_5_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_5_r_5_t_3_busy, S1MMEtore::msg_sm_0_i_5_r_5_t_3_cnt, S1MMEtore::msg_sm_0_i_5_r_5_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_5_r_5_t_4_busy, S1MMEtore::msg_sm_0_i_5_r_5_t_4_cnt, S1MMEtore::msg_sm_0_i_5_r_5_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_5_r_5_t_5_busy, S1MMEtore::msg_sm_0_i_5_r_5_t_5_cnt, S1MMEtore::msg_sm_0_i_5_r_5_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_5_r_5_t_6_busy, S1MMEtore::msg_sm_0_i_5_r_5_t_6_cnt, S1MMEtore::msg_sm_0_i_5_r_5_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_5_r_5_t_7_busy, S1MMEtore::msg_sm_0_i_5_r_5_t_7_cnt, S1MMEtore::msg_sm_0_i_5_r_5_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_5_r_5_t_8_busy, S1MMEtore::msg_sm_0_i_5_r_5_t_8_cnt, S1MMEtore::msg_sm_0_i_5_r_5_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_5_r_5_t_9_busy, S1MMEtore::msg_sm_0_i_5_r_5_t_9_cnt, S1MMEtore::msg_sm_0_i_5_r_5_t_9, pSctp);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_5_r_5_t_0_busy, S1MMEtore::msg_sm_1_i_5_r_5_t_0_cnt, S1MMEtore::msg_sm_1_i_5_r_5_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_5_r_5_t_1_busy, S1MMEtore::msg_sm_1_i_5_r_5_t_1_cnt, S1MMEtore::msg_sm_1_i_5_r_5_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_5_r_5_t_2_busy, S1MMEtore::msg_sm_1_i_5_r_5_t_2_cnt, S1MMEtore::msg_sm_1_i_5_r_5_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_5_r_5_t_3_busy, S1MMEtore::msg_sm_1_i_5_r_5_t_3_cnt, S1MMEtore::msg_sm_1_i_5_r_5_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_5_r_5_t_4_busy, S1MMEtore::msg_sm_1_i_5_r_5_t_4_cnt, S1MMEtore::msg_sm_1_i_5_r_5_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_5_r_5_t_5_busy, S1MMEtore::msg_sm_1_i_5_r_5_t_5_cnt, S1MMEtore::msg_sm_1_i_5_r_5_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_5_r_5_t_6_busy, S1MMEtore::msg_sm_1_i_5_r_5_t_6_cnt, S1MMEtore::msg_sm_1_i_5_r_5_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_5_r_5_t_7_busy, S1MMEtore::msg_sm_1_i_5_r_5_t_7_cnt, S1MMEtore::msg_sm_1_i_5_r_5_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_5_r_5_t_8_busy, S1MMEtore::msg_sm_1_i_5_r_5_t_8_cnt, S1MMEtore::msg_sm_1_i_5_r_5_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_5_r_5_t_9_busy, S1MMEtore::msg_sm_1_i_5_r_5_t_9_cnt, S1MMEtore::msg_sm_1_i_5_r_5_t_9, pSctp);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_5_r_5_t_0_busy, S1MMEtore::msg_sm_2_i_5_r_5_t_0_cnt, S1MMEtore::msg_sm_2_i_5_r_5_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_5_r_5_t_1_busy, S1MMEtore::msg_sm_2_i_5_r_5_t_1_cnt, S1MMEtore::msg_sm_2_i_5_r_5_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_5_r_5_t_2_busy, S1MMEtore::msg_sm_2_i_5_r_5_t_2_cnt, S1MMEtore::msg_sm_2_i_5_r_5_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_5_r_5_t_3_busy, S1MMEtore::msg_sm_2_i_5_r_5_t_3_cnt, S1MMEtore::msg_sm_2_i_5_r_5_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_5_r_5_t_4_busy, S1MMEtore::msg_sm_2_i_5_r_5_t_4_cnt, S1MMEtore::msg_sm_2_i_5_r_5_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_5_r_5_t_5_busy, S1MMEtore::msg_sm_2_i_5_r_5_t_5_cnt, S1MMEtore::msg_sm_2_i_5_r_5_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_5_r_5_t_6_busy, S1MMEtore::msg_sm_2_i_5_r_5_t_6_cnt, S1MMEtore::msg_sm_2_i_5_r_5_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_5_r_5_t_7_busy, S1MMEtore::msg_sm_2_i_5_r_5_t_7_cnt, S1MMEtore::msg_sm_2_i_5_r_5_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_5_r_5_t_8_busy, S1MMEtore::msg_sm_2_i_5_r_5_t_8_cnt, S1MMEtore::msg_sm_2_i_5_r_5_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_5_r_5_t_9_busy, S1MMEtore::msg_sm_2_i_5_r_5_t_9_cnt, S1MMEtore::msg_sm_2_i_5_r_5_t_9, pSctp);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_5_r_5_t_0_busy, S1MMEtore::msg_sm_3_i_5_r_5_t_0_cnt, S1MMEtore::msg_sm_3_i_5_r_5_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_5_r_5_t_1_busy, S1MMEtore::msg_sm_3_i_5_r_5_t_1_cnt, S1MMEtore::msg_sm_3_i_5_r_5_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_5_r_5_t_2_busy, S1MMEtore::msg_sm_3_i_5_r_5_t_2_cnt, S1MMEtore::msg_sm_3_i_5_r_5_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_5_r_5_t_3_busy, S1MMEtore::msg_sm_3_i_5_r_5_t_3_cnt, S1MMEtore::msg_sm_3_i_5_r_5_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_5_r_5_t_4_busy, S1MMEtore::msg_sm_3_i_5_r_5_t_4_cnt, S1MMEtore::msg_sm_3_i_5_r_5_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_5_r_5_t_5_busy, S1MMEtore::msg_sm_3_i_5_r_5_t_5_cnt, S1MMEtore::msg_sm_3_i_5_r_5_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_5_r_5_t_6_busy, S1MMEtore::msg_sm_3_i_5_r_5_t_6_cnt, S1MMEtore::msg_sm_3_i_5_r_5_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_5_r_5_t_7_busy, S1MMEtore::msg_sm_3_i_5_r_5_t_7_cnt, S1MMEtore::msg_sm_3_i_5_r_5_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_5_r_5_t_8_busy, S1MMEtore::msg_sm_3_i_5_r_5_t_8_cnt, S1MMEtore::msg_sm_3_i_5_r_5_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_5_r_5_t_9_busy, S1MMEtore::msg_sm_3_i_5_r_5_t_9_cnt, S1MMEtore::msg_sm_3_i_5_r_5_t_9, pSctp);
				break;
			}
			break;
	}
}

VOID SctpMessageBroker::pushToQueue_i_5_r_6(Sctp *pSctp, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_5_r_6_t_0_busy, S1MMEtore::msg_sm_0_i_5_r_6_t_0_cnt, S1MMEtore::msg_sm_0_i_5_r_6_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_5_r_6_t_1_busy, S1MMEtore::msg_sm_0_i_5_r_6_t_1_cnt, S1MMEtore::msg_sm_0_i_5_r_6_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_5_r_6_t_2_busy, S1MMEtore::msg_sm_0_i_5_r_6_t_2_cnt, S1MMEtore::msg_sm_0_i_5_r_6_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_5_r_6_t_3_busy, S1MMEtore::msg_sm_0_i_5_r_6_t_3_cnt, S1MMEtore::msg_sm_0_i_5_r_6_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_5_r_6_t_4_busy, S1MMEtore::msg_sm_0_i_5_r_6_t_4_cnt, S1MMEtore::msg_sm_0_i_5_r_6_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_5_r_6_t_5_busy, S1MMEtore::msg_sm_0_i_5_r_6_t_5_cnt, S1MMEtore::msg_sm_0_i_5_r_6_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_5_r_6_t_6_busy, S1MMEtore::msg_sm_0_i_5_r_6_t_6_cnt, S1MMEtore::msg_sm_0_i_5_r_6_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_5_r_6_t_7_busy, S1MMEtore::msg_sm_0_i_5_r_6_t_7_cnt, S1MMEtore::msg_sm_0_i_5_r_6_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_5_r_6_t_8_busy, S1MMEtore::msg_sm_0_i_5_r_6_t_8_cnt, S1MMEtore::msg_sm_0_i_5_r_6_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_5_r_6_t_9_busy, S1MMEtore::msg_sm_0_i_5_r_6_t_9_cnt, S1MMEtore::msg_sm_0_i_5_r_6_t_9, pSctp);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_5_r_6_t_0_busy, S1MMEtore::msg_sm_1_i_5_r_6_t_0_cnt, S1MMEtore::msg_sm_1_i_5_r_6_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_5_r_6_t_1_busy, S1MMEtore::msg_sm_1_i_5_r_6_t_1_cnt, S1MMEtore::msg_sm_1_i_5_r_6_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_5_r_6_t_2_busy, S1MMEtore::msg_sm_1_i_5_r_6_t_2_cnt, S1MMEtore::msg_sm_1_i_5_r_6_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_5_r_6_t_3_busy, S1MMEtore::msg_sm_1_i_5_r_6_t_3_cnt, S1MMEtore::msg_sm_1_i_5_r_6_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_5_r_6_t_4_busy, S1MMEtore::msg_sm_1_i_5_r_6_t_4_cnt, S1MMEtore::msg_sm_1_i_5_r_6_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_5_r_6_t_5_busy, S1MMEtore::msg_sm_1_i_5_r_6_t_5_cnt, S1MMEtore::msg_sm_1_i_5_r_6_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_5_r_6_t_6_busy, S1MMEtore::msg_sm_1_i_5_r_6_t_6_cnt, S1MMEtore::msg_sm_1_i_5_r_6_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_5_r_6_t_7_busy, S1MMEtore::msg_sm_1_i_5_r_6_t_7_cnt, S1MMEtore::msg_sm_1_i_5_r_6_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_5_r_6_t_8_busy, S1MMEtore::msg_sm_1_i_5_r_6_t_8_cnt, S1MMEtore::msg_sm_1_i_5_r_6_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_5_r_6_t_9_busy, S1MMEtore::msg_sm_1_i_5_r_6_t_9_cnt, S1MMEtore::msg_sm_1_i_5_r_6_t_9, pSctp);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_5_r_6_t_0_busy, S1MMEtore::msg_sm_2_i_5_r_6_t_0_cnt, S1MMEtore::msg_sm_2_i_5_r_6_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_5_r_6_t_1_busy, S1MMEtore::msg_sm_2_i_5_r_6_t_1_cnt, S1MMEtore::msg_sm_2_i_5_r_6_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_5_r_6_t_2_busy, S1MMEtore::msg_sm_2_i_5_r_6_t_2_cnt, S1MMEtore::msg_sm_2_i_5_r_6_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_5_r_6_t_3_busy, S1MMEtore::msg_sm_2_i_5_r_6_t_3_cnt, S1MMEtore::msg_sm_2_i_5_r_6_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_5_r_6_t_4_busy, S1MMEtore::msg_sm_2_i_5_r_6_t_4_cnt, S1MMEtore::msg_sm_2_i_5_r_6_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_5_r_6_t_5_busy, S1MMEtore::msg_sm_2_i_5_r_6_t_5_cnt, S1MMEtore::msg_sm_2_i_5_r_6_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_5_r_6_t_6_busy, S1MMEtore::msg_sm_2_i_5_r_6_t_6_cnt, S1MMEtore::msg_sm_2_i_5_r_6_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_5_r_6_t_7_busy, S1MMEtore::msg_sm_2_i_5_r_6_t_7_cnt, S1MMEtore::msg_sm_2_i_5_r_6_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_5_r_6_t_8_busy, S1MMEtore::msg_sm_2_i_5_r_6_t_8_cnt, S1MMEtore::msg_sm_2_i_5_r_6_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_5_r_6_t_9_busy, S1MMEtore::msg_sm_2_i_5_r_6_t_9_cnt, S1MMEtore::msg_sm_2_i_5_r_6_t_9, pSctp);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_5_r_6_t_0_busy, S1MMEtore::msg_sm_3_i_5_r_6_t_0_cnt, S1MMEtore::msg_sm_3_i_5_r_6_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_5_r_6_t_1_busy, S1MMEtore::msg_sm_3_i_5_r_6_t_1_cnt, S1MMEtore::msg_sm_3_i_5_r_6_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_5_r_6_t_2_busy, S1MMEtore::msg_sm_3_i_5_r_6_t_2_cnt, S1MMEtore::msg_sm_3_i_5_r_6_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_5_r_6_t_3_busy, S1MMEtore::msg_sm_3_i_5_r_6_t_3_cnt, S1MMEtore::msg_sm_3_i_5_r_6_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_5_r_6_t_4_busy, S1MMEtore::msg_sm_3_i_5_r_6_t_4_cnt, S1MMEtore::msg_sm_3_i_5_r_6_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_5_r_6_t_5_busy, S1MMEtore::msg_sm_3_i_5_r_6_t_5_cnt, S1MMEtore::msg_sm_3_i_5_r_6_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_5_r_6_t_6_busy, S1MMEtore::msg_sm_3_i_5_r_6_t_6_cnt, S1MMEtore::msg_sm_3_i_5_r_6_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_5_r_6_t_7_busy, S1MMEtore::msg_sm_3_i_5_r_6_t_7_cnt, S1MMEtore::msg_sm_3_i_5_r_6_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_5_r_6_t_8_busy, S1MMEtore::msg_sm_3_i_5_r_6_t_8_cnt, S1MMEtore::msg_sm_3_i_5_r_6_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_5_r_6_t_9_busy, S1MMEtore::msg_sm_3_i_5_r_6_t_9_cnt, S1MMEtore::msg_sm_3_i_5_r_6_t_9, pSctp);
				break;
			}
			break;
	}
}

VOID SctpMessageBroker::pushToQueue_i_5_r_7(Sctp *pSctp, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_5_r_7_t_0_busy, S1MMEtore::msg_sm_0_i_5_r_7_t_0_cnt, S1MMEtore::msg_sm_0_i_5_r_7_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_5_r_7_t_1_busy, S1MMEtore::msg_sm_0_i_5_r_7_t_1_cnt, S1MMEtore::msg_sm_0_i_5_r_7_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_5_r_7_t_2_busy, S1MMEtore::msg_sm_0_i_5_r_7_t_2_cnt, S1MMEtore::msg_sm_0_i_5_r_7_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_5_r_7_t_3_busy, S1MMEtore::msg_sm_0_i_5_r_7_t_3_cnt, S1MMEtore::msg_sm_0_i_5_r_7_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_5_r_7_t_4_busy, S1MMEtore::msg_sm_0_i_5_r_7_t_4_cnt, S1MMEtore::msg_sm_0_i_5_r_7_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_5_r_7_t_5_busy, S1MMEtore::msg_sm_0_i_5_r_7_t_5_cnt, S1MMEtore::msg_sm_0_i_5_r_7_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_5_r_7_t_6_busy, S1MMEtore::msg_sm_0_i_5_r_7_t_6_cnt, S1MMEtore::msg_sm_0_i_5_r_7_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_5_r_7_t_7_busy, S1MMEtore::msg_sm_0_i_5_r_7_t_7_cnt, S1MMEtore::msg_sm_0_i_5_r_7_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_5_r_7_t_8_busy, S1MMEtore::msg_sm_0_i_5_r_7_t_8_cnt, S1MMEtore::msg_sm_0_i_5_r_7_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_5_r_7_t_9_busy, S1MMEtore::msg_sm_0_i_5_r_7_t_9_cnt, S1MMEtore::msg_sm_0_i_5_r_7_t_9, pSctp);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_5_r_7_t_0_busy, S1MMEtore::msg_sm_1_i_5_r_7_t_0_cnt, S1MMEtore::msg_sm_1_i_5_r_7_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_5_r_7_t_1_busy, S1MMEtore::msg_sm_1_i_5_r_7_t_1_cnt, S1MMEtore::msg_sm_1_i_5_r_7_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_5_r_7_t_2_busy, S1MMEtore::msg_sm_1_i_5_r_7_t_2_cnt, S1MMEtore::msg_sm_1_i_5_r_7_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_5_r_7_t_3_busy, S1MMEtore::msg_sm_1_i_5_r_7_t_3_cnt, S1MMEtore::msg_sm_1_i_5_r_7_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_5_r_7_t_4_busy, S1MMEtore::msg_sm_1_i_5_r_7_t_4_cnt, S1MMEtore::msg_sm_1_i_5_r_7_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_5_r_7_t_5_busy, S1MMEtore::msg_sm_1_i_5_r_7_t_5_cnt, S1MMEtore::msg_sm_1_i_5_r_7_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_5_r_7_t_6_busy, S1MMEtore::msg_sm_1_i_5_r_7_t_6_cnt, S1MMEtore::msg_sm_1_i_5_r_7_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_5_r_7_t_7_busy, S1MMEtore::msg_sm_1_i_5_r_7_t_7_cnt, S1MMEtore::msg_sm_1_i_5_r_7_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_5_r_7_t_8_busy, S1MMEtore::msg_sm_1_i_5_r_7_t_8_cnt, S1MMEtore::msg_sm_1_i_5_r_7_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_5_r_7_t_9_busy, S1MMEtore::msg_sm_1_i_5_r_7_t_9_cnt, S1MMEtore::msg_sm_1_i_5_r_7_t_9, pSctp);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_5_r_7_t_0_busy, S1MMEtore::msg_sm_2_i_5_r_7_t_0_cnt, S1MMEtore::msg_sm_2_i_5_r_7_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_5_r_7_t_1_busy, S1MMEtore::msg_sm_2_i_5_r_7_t_1_cnt, S1MMEtore::msg_sm_2_i_5_r_7_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_5_r_7_t_2_busy, S1MMEtore::msg_sm_2_i_5_r_7_t_2_cnt, S1MMEtore::msg_sm_2_i_5_r_7_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_5_r_7_t_3_busy, S1MMEtore::msg_sm_2_i_5_r_7_t_3_cnt, S1MMEtore::msg_sm_2_i_5_r_7_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_5_r_7_t_4_busy, S1MMEtore::msg_sm_2_i_5_r_7_t_4_cnt, S1MMEtore::msg_sm_2_i_5_r_7_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_5_r_7_t_5_busy, S1MMEtore::msg_sm_2_i_5_r_7_t_5_cnt, S1MMEtore::msg_sm_2_i_5_r_7_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_5_r_7_t_6_busy, S1MMEtore::msg_sm_2_i_5_r_7_t_6_cnt, S1MMEtore::msg_sm_2_i_5_r_7_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_5_r_7_t_7_busy, S1MMEtore::msg_sm_2_i_5_r_7_t_7_cnt, S1MMEtore::msg_sm_2_i_5_r_7_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_5_r_7_t_8_busy, S1MMEtore::msg_sm_2_i_5_r_7_t_8_cnt, S1MMEtore::msg_sm_2_i_5_r_7_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_5_r_7_t_9_busy, S1MMEtore::msg_sm_2_i_5_r_7_t_9_cnt, S1MMEtore::msg_sm_2_i_5_r_7_t_9, pSctp);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_5_r_7_t_0_busy, S1MMEtore::msg_sm_3_i_5_r_7_t_0_cnt, S1MMEtore::msg_sm_3_i_5_r_7_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_5_r_7_t_1_busy, S1MMEtore::msg_sm_3_i_5_r_7_t_1_cnt, S1MMEtore::msg_sm_3_i_5_r_7_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_5_r_7_t_2_busy, S1MMEtore::msg_sm_3_i_5_r_7_t_2_cnt, S1MMEtore::msg_sm_3_i_5_r_7_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_5_r_7_t_3_busy, S1MMEtore::msg_sm_3_i_5_r_7_t_3_cnt, S1MMEtore::msg_sm_3_i_5_r_7_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_5_r_7_t_4_busy, S1MMEtore::msg_sm_3_i_5_r_7_t_4_cnt, S1MMEtore::msg_sm_3_i_5_r_7_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_5_r_7_t_5_busy, S1MMEtore::msg_sm_3_i_5_r_7_t_5_cnt, S1MMEtore::msg_sm_3_i_5_r_7_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_5_r_7_t_6_busy, S1MMEtore::msg_sm_3_i_5_r_7_t_6_cnt, S1MMEtore::msg_sm_3_i_5_r_7_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_5_r_7_t_7_busy, S1MMEtore::msg_sm_3_i_5_r_7_t_7_cnt, S1MMEtore::msg_sm_3_i_5_r_7_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_5_r_7_t_8_busy, S1MMEtore::msg_sm_3_i_5_r_7_t_8_cnt, S1MMEtore::msg_sm_3_i_5_r_7_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_5_r_7_t_9_busy, S1MMEtore::msg_sm_3_i_5_r_7_t_9_cnt, S1MMEtore::msg_sm_3_i_5_r_7_t_9, pSctp);
				break;
			}
			break;
	}
}


VOID SctpMessageBroker::pushToQueue_i_6_r_0(Sctp *pSctp, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_6_r_0_t_0_busy, S1MMEtore::msg_sm_0_i_6_r_0_t_0_cnt, S1MMEtore::msg_sm_0_i_6_r_0_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_6_r_0_t_1_busy, S1MMEtore::msg_sm_0_i_6_r_0_t_1_cnt, S1MMEtore::msg_sm_0_i_6_r_0_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_6_r_0_t_2_busy, S1MMEtore::msg_sm_0_i_6_r_0_t_2_cnt, S1MMEtore::msg_sm_0_i_6_r_0_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_6_r_0_t_3_busy, S1MMEtore::msg_sm_0_i_6_r_0_t_3_cnt, S1MMEtore::msg_sm_0_i_6_r_0_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_6_r_0_t_4_busy, S1MMEtore::msg_sm_0_i_6_r_0_t_4_cnt, S1MMEtore::msg_sm_0_i_6_r_0_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_6_r_0_t_5_busy, S1MMEtore::msg_sm_0_i_6_r_0_t_5_cnt, S1MMEtore::msg_sm_0_i_6_r_0_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_6_r_0_t_6_busy, S1MMEtore::msg_sm_0_i_6_r_0_t_6_cnt, S1MMEtore::msg_sm_0_i_6_r_0_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_6_r_0_t_7_busy, S1MMEtore::msg_sm_0_i_6_r_0_t_7_cnt, S1MMEtore::msg_sm_0_i_6_r_0_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_6_r_0_t_8_busy, S1MMEtore::msg_sm_0_i_6_r_0_t_8_cnt, S1MMEtore::msg_sm_0_i_6_r_0_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_6_r_0_t_9_busy, S1MMEtore::msg_sm_0_i_6_r_0_t_9_cnt, S1MMEtore::msg_sm_0_i_6_r_0_t_9, pSctp);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_6_r_0_t_0_busy, S1MMEtore::msg_sm_1_i_6_r_0_t_0_cnt, S1MMEtore::msg_sm_1_i_6_r_0_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_6_r_0_t_1_busy, S1MMEtore::msg_sm_1_i_6_r_0_t_1_cnt, S1MMEtore::msg_sm_1_i_6_r_0_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_6_r_0_t_2_busy, S1MMEtore::msg_sm_1_i_6_r_0_t_2_cnt, S1MMEtore::msg_sm_1_i_6_r_0_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_6_r_0_t_3_busy, S1MMEtore::msg_sm_1_i_6_r_0_t_3_cnt, S1MMEtore::msg_sm_1_i_6_r_0_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_6_r_0_t_4_busy, S1MMEtore::msg_sm_1_i_6_r_0_t_4_cnt, S1MMEtore::msg_sm_1_i_6_r_0_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_6_r_0_t_5_busy, S1MMEtore::msg_sm_1_i_6_r_0_t_5_cnt, S1MMEtore::msg_sm_1_i_6_r_0_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_6_r_0_t_6_busy, S1MMEtore::msg_sm_1_i_6_r_0_t_6_cnt, S1MMEtore::msg_sm_1_i_6_r_0_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_6_r_0_t_7_busy, S1MMEtore::msg_sm_1_i_6_r_0_t_7_cnt, S1MMEtore::msg_sm_1_i_6_r_0_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_6_r_0_t_8_busy, S1MMEtore::msg_sm_1_i_6_r_0_t_8_cnt, S1MMEtore::msg_sm_1_i_6_r_0_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_6_r_0_t_9_busy, S1MMEtore::msg_sm_1_i_6_r_0_t_9_cnt, S1MMEtore::msg_sm_1_i_6_r_0_t_9, pSctp);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_6_r_0_t_0_busy, S1MMEtore::msg_sm_2_i_6_r_0_t_0_cnt, S1MMEtore::msg_sm_2_i_6_r_0_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_6_r_0_t_1_busy, S1MMEtore::msg_sm_2_i_6_r_0_t_1_cnt, S1MMEtore::msg_sm_2_i_6_r_0_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_6_r_0_t_2_busy, S1MMEtore::msg_sm_2_i_6_r_0_t_2_cnt, S1MMEtore::msg_sm_2_i_6_r_0_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_6_r_0_t_3_busy, S1MMEtore::msg_sm_2_i_6_r_0_t_3_cnt, S1MMEtore::msg_sm_2_i_6_r_0_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_6_r_0_t_4_busy, S1MMEtore::msg_sm_2_i_6_r_0_t_4_cnt, S1MMEtore::msg_sm_2_i_6_r_0_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_6_r_0_t_5_busy, S1MMEtore::msg_sm_2_i_6_r_0_t_5_cnt, S1MMEtore::msg_sm_2_i_6_r_0_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_6_r_0_t_6_busy, S1MMEtore::msg_sm_2_i_6_r_0_t_6_cnt, S1MMEtore::msg_sm_2_i_6_r_0_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_6_r_0_t_7_busy, S1MMEtore::msg_sm_2_i_6_r_0_t_7_cnt, S1MMEtore::msg_sm_2_i_6_r_0_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_6_r_0_t_8_busy, S1MMEtore::msg_sm_2_i_6_r_0_t_8_cnt, S1MMEtore::msg_sm_2_i_6_r_0_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_6_r_0_t_9_busy, S1MMEtore::msg_sm_2_i_6_r_0_t_9_cnt, S1MMEtore::msg_sm_2_i_6_r_0_t_9, pSctp);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_6_r_0_t_0_busy, S1MMEtore::msg_sm_3_i_6_r_0_t_0_cnt, S1MMEtore::msg_sm_3_i_6_r_0_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_6_r_0_t_1_busy, S1MMEtore::msg_sm_3_i_6_r_0_t_1_cnt, S1MMEtore::msg_sm_3_i_6_r_0_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_6_r_0_t_2_busy, S1MMEtore::msg_sm_3_i_6_r_0_t_2_cnt, S1MMEtore::msg_sm_3_i_6_r_0_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_6_r_0_t_3_busy, S1MMEtore::msg_sm_3_i_6_r_0_t_3_cnt, S1MMEtore::msg_sm_3_i_6_r_0_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_6_r_0_t_4_busy, S1MMEtore::msg_sm_3_i_6_r_0_t_4_cnt, S1MMEtore::msg_sm_3_i_6_r_0_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_6_r_0_t_5_busy, S1MMEtore::msg_sm_3_i_6_r_0_t_5_cnt, S1MMEtore::msg_sm_3_i_6_r_0_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_6_r_0_t_6_busy, S1MMEtore::msg_sm_3_i_6_r_0_t_6_cnt, S1MMEtore::msg_sm_3_i_6_r_0_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_6_r_0_t_7_busy, S1MMEtore::msg_sm_3_i_6_r_0_t_7_cnt, S1MMEtore::msg_sm_3_i_6_r_0_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_6_r_0_t_8_busy, S1MMEtore::msg_sm_3_i_6_r_0_t_8_cnt, S1MMEtore::msg_sm_3_i_6_r_0_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_6_r_0_t_9_busy, S1MMEtore::msg_sm_3_i_6_r_0_t_9_cnt, S1MMEtore::msg_sm_3_i_6_r_0_t_9, pSctp);
				break;
			}
			break;
	}
}

VOID SctpMessageBroker::pushToQueue_i_6_r_1(Sctp *pSctp, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_6_r_1_t_0_busy, S1MMEtore::msg_sm_0_i_6_r_1_t_0_cnt, S1MMEtore::msg_sm_0_i_6_r_1_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_6_r_1_t_1_busy, S1MMEtore::msg_sm_0_i_6_r_1_t_1_cnt, S1MMEtore::msg_sm_0_i_6_r_1_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_6_r_1_t_2_busy, S1MMEtore::msg_sm_0_i_6_r_1_t_2_cnt, S1MMEtore::msg_sm_0_i_6_r_1_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_6_r_1_t_3_busy, S1MMEtore::msg_sm_0_i_6_r_1_t_3_cnt, S1MMEtore::msg_sm_0_i_6_r_1_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_6_r_1_t_4_busy, S1MMEtore::msg_sm_0_i_6_r_1_t_4_cnt, S1MMEtore::msg_sm_0_i_6_r_1_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_6_r_1_t_5_busy, S1MMEtore::msg_sm_0_i_6_r_1_t_5_cnt, S1MMEtore::msg_sm_0_i_6_r_1_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_6_r_1_t_6_busy, S1MMEtore::msg_sm_0_i_6_r_1_t_6_cnt, S1MMEtore::msg_sm_0_i_6_r_1_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_6_r_1_t_7_busy, S1MMEtore::msg_sm_0_i_6_r_1_t_7_cnt, S1MMEtore::msg_sm_0_i_6_r_1_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_6_r_1_t_8_busy, S1MMEtore::msg_sm_0_i_6_r_1_t_8_cnt, S1MMEtore::msg_sm_0_i_6_r_1_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_6_r_1_t_9_busy, S1MMEtore::msg_sm_0_i_6_r_1_t_9_cnt, S1MMEtore::msg_sm_0_i_6_r_1_t_9, pSctp);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_6_r_1_t_0_busy, S1MMEtore::msg_sm_1_i_6_r_1_t_0_cnt, S1MMEtore::msg_sm_1_i_6_r_1_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_6_r_1_t_1_busy, S1MMEtore::msg_sm_1_i_6_r_1_t_1_cnt, S1MMEtore::msg_sm_1_i_6_r_1_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_6_r_1_t_2_busy, S1MMEtore::msg_sm_1_i_6_r_1_t_2_cnt, S1MMEtore::msg_sm_1_i_6_r_1_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_6_r_1_t_3_busy, S1MMEtore::msg_sm_1_i_6_r_1_t_3_cnt, S1MMEtore::msg_sm_1_i_6_r_1_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_6_r_1_t_4_busy, S1MMEtore::msg_sm_1_i_6_r_1_t_4_cnt, S1MMEtore::msg_sm_1_i_6_r_1_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_6_r_1_t_5_busy, S1MMEtore::msg_sm_1_i_6_r_1_t_5_cnt, S1MMEtore::msg_sm_1_i_6_r_1_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_6_r_1_t_6_busy, S1MMEtore::msg_sm_1_i_6_r_1_t_6_cnt, S1MMEtore::msg_sm_1_i_6_r_1_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_6_r_1_t_7_busy, S1MMEtore::msg_sm_1_i_6_r_1_t_7_cnt, S1MMEtore::msg_sm_1_i_6_r_1_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_6_r_1_t_8_busy, S1MMEtore::msg_sm_1_i_6_r_1_t_8_cnt, S1MMEtore::msg_sm_1_i_6_r_1_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_6_r_1_t_9_busy, S1MMEtore::msg_sm_1_i_6_r_1_t_9_cnt, S1MMEtore::msg_sm_1_i_6_r_1_t_9, pSctp);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_6_r_1_t_0_busy, S1MMEtore::msg_sm_2_i_6_r_1_t_0_cnt, S1MMEtore::msg_sm_2_i_6_r_1_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_6_r_1_t_1_busy, S1MMEtore::msg_sm_2_i_6_r_1_t_1_cnt, S1MMEtore::msg_sm_2_i_6_r_1_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_6_r_1_t_2_busy, S1MMEtore::msg_sm_2_i_6_r_1_t_2_cnt, S1MMEtore::msg_sm_2_i_6_r_1_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_6_r_1_t_3_busy, S1MMEtore::msg_sm_2_i_6_r_1_t_3_cnt, S1MMEtore::msg_sm_2_i_6_r_1_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_6_r_1_t_4_busy, S1MMEtore::msg_sm_2_i_6_r_1_t_4_cnt, S1MMEtore::msg_sm_2_i_6_r_1_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_6_r_1_t_5_busy, S1MMEtore::msg_sm_2_i_6_r_1_t_5_cnt, S1MMEtore::msg_sm_2_i_6_r_1_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_6_r_1_t_6_busy, S1MMEtore::msg_sm_2_i_6_r_1_t_6_cnt, S1MMEtore::msg_sm_2_i_6_r_1_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_6_r_1_t_7_busy, S1MMEtore::msg_sm_2_i_6_r_1_t_7_cnt, S1MMEtore::msg_sm_2_i_6_r_1_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_6_r_1_t_8_busy, S1MMEtore::msg_sm_2_i_6_r_1_t_8_cnt, S1MMEtore::msg_sm_2_i_6_r_1_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_6_r_1_t_9_busy, S1MMEtore::msg_sm_2_i_6_r_1_t_9_cnt, S1MMEtore::msg_sm_2_i_6_r_1_t_9, pSctp);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_6_r_1_t_0_busy, S1MMEtore::msg_sm_3_i_6_r_1_t_0_cnt, S1MMEtore::msg_sm_3_i_6_r_1_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_6_r_1_t_1_busy, S1MMEtore::msg_sm_3_i_6_r_1_t_1_cnt, S1MMEtore::msg_sm_3_i_6_r_1_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_6_r_1_t_2_busy, S1MMEtore::msg_sm_3_i_6_r_1_t_2_cnt, S1MMEtore::msg_sm_3_i_6_r_1_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_6_r_1_t_3_busy, S1MMEtore::msg_sm_3_i_6_r_1_t_3_cnt, S1MMEtore::msg_sm_3_i_6_r_1_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_6_r_1_t_4_busy, S1MMEtore::msg_sm_3_i_6_r_1_t_4_cnt, S1MMEtore::msg_sm_3_i_6_r_1_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_6_r_1_t_5_busy, S1MMEtore::msg_sm_3_i_6_r_1_t_5_cnt, S1MMEtore::msg_sm_3_i_6_r_1_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_6_r_1_t_6_busy, S1MMEtore::msg_sm_3_i_6_r_1_t_6_cnt, S1MMEtore::msg_sm_3_i_6_r_1_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_6_r_1_t_7_busy, S1MMEtore::msg_sm_3_i_6_r_1_t_7_cnt, S1MMEtore::msg_sm_3_i_6_r_1_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_6_r_1_t_8_busy, S1MMEtore::msg_sm_3_i_6_r_1_t_8_cnt, S1MMEtore::msg_sm_3_i_6_r_1_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_6_r_1_t_9_busy, S1MMEtore::msg_sm_3_i_6_r_1_t_9_cnt, S1MMEtore::msg_sm_3_i_6_r_1_t_9, pSctp);
				break;
			}
			break;
	}
}

VOID SctpMessageBroker::pushToQueue_i_6_r_2(Sctp *pSctp, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_6_r_2_t_0_busy, S1MMEtore::msg_sm_0_i_6_r_2_t_0_cnt, S1MMEtore::msg_sm_0_i_6_r_2_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_6_r_2_t_1_busy, S1MMEtore::msg_sm_0_i_6_r_2_t_1_cnt, S1MMEtore::msg_sm_0_i_6_r_2_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_6_r_2_t_2_busy, S1MMEtore::msg_sm_0_i_6_r_2_t_2_cnt, S1MMEtore::msg_sm_0_i_6_r_2_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_6_r_2_t_3_busy, S1MMEtore::msg_sm_0_i_6_r_2_t_3_cnt, S1MMEtore::msg_sm_0_i_6_r_2_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_6_r_2_t_4_busy, S1MMEtore::msg_sm_0_i_6_r_2_t_4_cnt, S1MMEtore::msg_sm_0_i_6_r_2_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_6_r_2_t_5_busy, S1MMEtore::msg_sm_0_i_6_r_2_t_5_cnt, S1MMEtore::msg_sm_0_i_6_r_2_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_6_r_2_t_6_busy, S1MMEtore::msg_sm_0_i_6_r_2_t_6_cnt, S1MMEtore::msg_sm_0_i_6_r_2_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_6_r_2_t_7_busy, S1MMEtore::msg_sm_0_i_6_r_2_t_7_cnt, S1MMEtore::msg_sm_0_i_6_r_2_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_6_r_2_t_8_busy, S1MMEtore::msg_sm_0_i_6_r_2_t_8_cnt, S1MMEtore::msg_sm_0_i_6_r_2_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_6_r_2_t_9_busy, S1MMEtore::msg_sm_0_i_6_r_2_t_9_cnt, S1MMEtore::msg_sm_0_i_6_r_2_t_9, pSctp);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_6_r_2_t_0_busy, S1MMEtore::msg_sm_1_i_6_r_2_t_0_cnt, S1MMEtore::msg_sm_1_i_6_r_2_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_6_r_2_t_1_busy, S1MMEtore::msg_sm_1_i_6_r_2_t_1_cnt, S1MMEtore::msg_sm_1_i_6_r_2_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_6_r_2_t_2_busy, S1MMEtore::msg_sm_1_i_6_r_2_t_2_cnt, S1MMEtore::msg_sm_1_i_6_r_2_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_6_r_2_t_3_busy, S1MMEtore::msg_sm_1_i_6_r_2_t_3_cnt, S1MMEtore::msg_sm_1_i_6_r_2_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_6_r_2_t_4_busy, S1MMEtore::msg_sm_1_i_6_r_2_t_4_cnt, S1MMEtore::msg_sm_1_i_6_r_2_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_6_r_2_t_5_busy, S1MMEtore::msg_sm_1_i_6_r_2_t_5_cnt, S1MMEtore::msg_sm_1_i_6_r_2_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_6_r_2_t_6_busy, S1MMEtore::msg_sm_1_i_6_r_2_t_6_cnt, S1MMEtore::msg_sm_1_i_6_r_2_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_6_r_2_t_7_busy, S1MMEtore::msg_sm_1_i_6_r_2_t_7_cnt, S1MMEtore::msg_sm_1_i_6_r_2_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_6_r_2_t_8_busy, S1MMEtore::msg_sm_1_i_6_r_2_t_8_cnt, S1MMEtore::msg_sm_1_i_6_r_2_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_6_r_2_t_9_busy, S1MMEtore::msg_sm_1_i_6_r_2_t_9_cnt, S1MMEtore::msg_sm_1_i_6_r_2_t_9, pSctp);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_6_r_2_t_0_busy, S1MMEtore::msg_sm_2_i_6_r_2_t_0_cnt, S1MMEtore::msg_sm_2_i_6_r_2_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_6_r_2_t_1_busy, S1MMEtore::msg_sm_2_i_6_r_2_t_1_cnt, S1MMEtore::msg_sm_2_i_6_r_2_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_6_r_2_t_2_busy, S1MMEtore::msg_sm_2_i_6_r_2_t_2_cnt, S1MMEtore::msg_sm_2_i_6_r_2_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_6_r_2_t_3_busy, S1MMEtore::msg_sm_2_i_6_r_2_t_3_cnt, S1MMEtore::msg_sm_2_i_6_r_2_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_6_r_2_t_4_busy, S1MMEtore::msg_sm_2_i_6_r_2_t_4_cnt, S1MMEtore::msg_sm_2_i_6_r_2_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_6_r_2_t_5_busy, S1MMEtore::msg_sm_2_i_6_r_2_t_5_cnt, S1MMEtore::msg_sm_2_i_6_r_2_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_6_r_2_t_6_busy, S1MMEtore::msg_sm_2_i_6_r_2_t_6_cnt, S1MMEtore::msg_sm_2_i_6_r_2_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_6_r_2_t_7_busy, S1MMEtore::msg_sm_2_i_6_r_2_t_7_cnt, S1MMEtore::msg_sm_2_i_6_r_2_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_6_r_2_t_8_busy, S1MMEtore::msg_sm_2_i_6_r_2_t_8_cnt, S1MMEtore::msg_sm_2_i_6_r_2_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_6_r_2_t_9_busy, S1MMEtore::msg_sm_2_i_6_r_2_t_9_cnt, S1MMEtore::msg_sm_2_i_6_r_2_t_9, pSctp);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_6_r_2_t_0_busy, S1MMEtore::msg_sm_3_i_6_r_2_t_0_cnt, S1MMEtore::msg_sm_3_i_6_r_2_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_6_r_2_t_1_busy, S1MMEtore::msg_sm_3_i_6_r_2_t_1_cnt, S1MMEtore::msg_sm_3_i_6_r_2_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_6_r_2_t_2_busy, S1MMEtore::msg_sm_3_i_6_r_2_t_2_cnt, S1MMEtore::msg_sm_3_i_6_r_2_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_6_r_2_t_3_busy, S1MMEtore::msg_sm_3_i_6_r_2_t_3_cnt, S1MMEtore::msg_sm_3_i_6_r_2_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_6_r_2_t_4_busy, S1MMEtore::msg_sm_3_i_6_r_2_t_4_cnt, S1MMEtore::msg_sm_3_i_6_r_2_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_6_r_2_t_5_busy, S1MMEtore::msg_sm_3_i_6_r_2_t_5_cnt, S1MMEtore::msg_sm_3_i_6_r_2_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_6_r_2_t_6_busy, S1MMEtore::msg_sm_3_i_6_r_2_t_6_cnt, S1MMEtore::msg_sm_3_i_6_r_2_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_6_r_2_t_7_busy, S1MMEtore::msg_sm_3_i_6_r_2_t_7_cnt, S1MMEtore::msg_sm_3_i_6_r_2_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_6_r_2_t_8_busy, S1MMEtore::msg_sm_3_i_6_r_2_t_8_cnt, S1MMEtore::msg_sm_3_i_6_r_2_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_6_r_2_t_9_busy, S1MMEtore::msg_sm_3_i_6_r_2_t_9_cnt, S1MMEtore::msg_sm_3_i_6_r_2_t_9, pSctp);
				break;
			}
			break;
	}
}

VOID SctpMessageBroker::pushToQueue_i_6_r_3(Sctp *pSctp, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_6_r_3_t_0_busy, S1MMEtore::msg_sm_0_i_6_r_3_t_0_cnt, S1MMEtore::msg_sm_0_i_6_r_3_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_6_r_3_t_1_busy, S1MMEtore::msg_sm_0_i_6_r_3_t_1_cnt, S1MMEtore::msg_sm_0_i_6_r_3_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_6_r_3_t_2_busy, S1MMEtore::msg_sm_0_i_6_r_3_t_2_cnt, S1MMEtore::msg_sm_0_i_6_r_3_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_6_r_3_t_3_busy, S1MMEtore::msg_sm_0_i_6_r_3_t_3_cnt, S1MMEtore::msg_sm_0_i_6_r_3_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_6_r_3_t_4_busy, S1MMEtore::msg_sm_0_i_6_r_3_t_4_cnt, S1MMEtore::msg_sm_0_i_6_r_3_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_6_r_3_t_5_busy, S1MMEtore::msg_sm_0_i_6_r_3_t_5_cnt, S1MMEtore::msg_sm_0_i_6_r_3_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_6_r_3_t_6_busy, S1MMEtore::msg_sm_0_i_6_r_3_t_6_cnt, S1MMEtore::msg_sm_0_i_6_r_3_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_6_r_3_t_7_busy, S1MMEtore::msg_sm_0_i_6_r_3_t_7_cnt, S1MMEtore::msg_sm_0_i_6_r_3_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_6_r_3_t_8_busy, S1MMEtore::msg_sm_0_i_6_r_3_t_8_cnt, S1MMEtore::msg_sm_0_i_6_r_3_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_6_r_3_t_9_busy, S1MMEtore::msg_sm_0_i_6_r_3_t_9_cnt, S1MMEtore::msg_sm_0_i_6_r_3_t_9, pSctp);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_6_r_3_t_0_busy, S1MMEtore::msg_sm_1_i_6_r_3_t_0_cnt, S1MMEtore::msg_sm_1_i_6_r_3_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_6_r_3_t_1_busy, S1MMEtore::msg_sm_1_i_6_r_3_t_1_cnt, S1MMEtore::msg_sm_1_i_6_r_3_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_6_r_3_t_2_busy, S1MMEtore::msg_sm_1_i_6_r_3_t_2_cnt, S1MMEtore::msg_sm_1_i_6_r_3_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_6_r_3_t_3_busy, S1MMEtore::msg_sm_1_i_6_r_3_t_3_cnt, S1MMEtore::msg_sm_1_i_6_r_3_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_6_r_3_t_4_busy, S1MMEtore::msg_sm_1_i_6_r_3_t_4_cnt, S1MMEtore::msg_sm_1_i_6_r_3_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_6_r_3_t_5_busy, S1MMEtore::msg_sm_1_i_6_r_3_t_5_cnt, S1MMEtore::msg_sm_1_i_6_r_3_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_6_r_3_t_6_busy, S1MMEtore::msg_sm_1_i_6_r_3_t_6_cnt, S1MMEtore::msg_sm_1_i_6_r_3_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_6_r_3_t_7_busy, S1MMEtore::msg_sm_1_i_6_r_3_t_7_cnt, S1MMEtore::msg_sm_1_i_6_r_3_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_6_r_3_t_8_busy, S1MMEtore::msg_sm_1_i_6_r_3_t_8_cnt, S1MMEtore::msg_sm_1_i_6_r_3_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_6_r_3_t_9_busy, S1MMEtore::msg_sm_1_i_6_r_3_t_9_cnt, S1MMEtore::msg_sm_1_i_6_r_3_t_9, pSctp);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_6_r_3_t_0_busy, S1MMEtore::msg_sm_2_i_6_r_3_t_0_cnt, S1MMEtore::msg_sm_2_i_6_r_3_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_6_r_3_t_1_busy, S1MMEtore::msg_sm_2_i_6_r_3_t_1_cnt, S1MMEtore::msg_sm_2_i_6_r_3_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_6_r_3_t_2_busy, S1MMEtore::msg_sm_2_i_6_r_3_t_2_cnt, S1MMEtore::msg_sm_2_i_6_r_3_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_6_r_3_t_3_busy, S1MMEtore::msg_sm_2_i_6_r_3_t_3_cnt, S1MMEtore::msg_sm_2_i_6_r_3_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_6_r_3_t_4_busy, S1MMEtore::msg_sm_2_i_6_r_3_t_4_cnt, S1MMEtore::msg_sm_2_i_6_r_3_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_6_r_3_t_5_busy, S1MMEtore::msg_sm_2_i_6_r_3_t_5_cnt, S1MMEtore::msg_sm_2_i_6_r_3_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_6_r_3_t_6_busy, S1MMEtore::msg_sm_2_i_6_r_3_t_6_cnt, S1MMEtore::msg_sm_2_i_6_r_3_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_6_r_3_t_7_busy, S1MMEtore::msg_sm_2_i_6_r_3_t_7_cnt, S1MMEtore::msg_sm_2_i_6_r_3_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_6_r_3_t_8_busy, S1MMEtore::msg_sm_2_i_6_r_3_t_8_cnt, S1MMEtore::msg_sm_2_i_6_r_3_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_6_r_3_t_9_busy, S1MMEtore::msg_sm_2_i_6_r_3_t_9_cnt, S1MMEtore::msg_sm_2_i_6_r_3_t_9, pSctp);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_6_r_3_t_0_busy, S1MMEtore::msg_sm_3_i_6_r_3_t_0_cnt, S1MMEtore::msg_sm_3_i_6_r_3_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_6_r_3_t_1_busy, S1MMEtore::msg_sm_3_i_6_r_3_t_1_cnt, S1MMEtore::msg_sm_3_i_6_r_3_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_6_r_3_t_2_busy, S1MMEtore::msg_sm_3_i_6_r_3_t_2_cnt, S1MMEtore::msg_sm_3_i_6_r_3_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_6_r_3_t_3_busy, S1MMEtore::msg_sm_3_i_6_r_3_t_3_cnt, S1MMEtore::msg_sm_3_i_6_r_3_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_6_r_3_t_4_busy, S1MMEtore::msg_sm_3_i_6_r_3_t_4_cnt, S1MMEtore::msg_sm_3_i_6_r_3_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_6_r_3_t_5_busy, S1MMEtore::msg_sm_3_i_6_r_3_t_5_cnt, S1MMEtore::msg_sm_3_i_6_r_3_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_6_r_3_t_6_busy, S1MMEtore::msg_sm_3_i_6_r_3_t_6_cnt, S1MMEtore::msg_sm_3_i_6_r_3_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_6_r_3_t_7_busy, S1MMEtore::msg_sm_3_i_6_r_3_t_7_cnt, S1MMEtore::msg_sm_3_i_6_r_3_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_6_r_3_t_8_busy, S1MMEtore::msg_sm_3_i_6_r_3_t_8_cnt, S1MMEtore::msg_sm_3_i_6_r_3_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_6_r_3_t_9_busy, S1MMEtore::msg_sm_3_i_6_r_3_t_9_cnt, S1MMEtore::msg_sm_3_i_6_r_3_t_9, pSctp);
				break;
			}
			break;
	}
}

VOID SctpMessageBroker::pushToQueue_i_6_r_4(Sctp *pSctp, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_6_r_4_t_0_busy, S1MMEtore::msg_sm_0_i_6_r_4_t_0_cnt, S1MMEtore::msg_sm_0_i_6_r_4_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_6_r_4_t_1_busy, S1MMEtore::msg_sm_0_i_6_r_4_t_1_cnt, S1MMEtore::msg_sm_0_i_6_r_4_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_6_r_4_t_2_busy, S1MMEtore::msg_sm_0_i_6_r_4_t_2_cnt, S1MMEtore::msg_sm_0_i_6_r_4_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_6_r_4_t_3_busy, S1MMEtore::msg_sm_0_i_6_r_4_t_3_cnt, S1MMEtore::msg_sm_0_i_6_r_4_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_6_r_4_t_4_busy, S1MMEtore::msg_sm_0_i_6_r_4_t_4_cnt, S1MMEtore::msg_sm_0_i_6_r_4_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_6_r_4_t_5_busy, S1MMEtore::msg_sm_0_i_6_r_4_t_5_cnt, S1MMEtore::msg_sm_0_i_6_r_4_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_6_r_4_t_6_busy, S1MMEtore::msg_sm_0_i_6_r_4_t_6_cnt, S1MMEtore::msg_sm_0_i_6_r_4_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_6_r_4_t_7_busy, S1MMEtore::msg_sm_0_i_6_r_4_t_7_cnt, S1MMEtore::msg_sm_0_i_6_r_4_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_6_r_4_t_8_busy, S1MMEtore::msg_sm_0_i_6_r_4_t_8_cnt, S1MMEtore::msg_sm_0_i_6_r_4_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_6_r_4_t_9_busy, S1MMEtore::msg_sm_0_i_6_r_4_t_9_cnt, S1MMEtore::msg_sm_0_i_6_r_4_t_9, pSctp);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_6_r_4_t_0_busy, S1MMEtore::msg_sm_1_i_6_r_4_t_0_cnt, S1MMEtore::msg_sm_1_i_6_r_4_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_6_r_4_t_1_busy, S1MMEtore::msg_sm_1_i_6_r_4_t_1_cnt, S1MMEtore::msg_sm_1_i_6_r_4_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_6_r_4_t_2_busy, S1MMEtore::msg_sm_1_i_6_r_4_t_2_cnt, S1MMEtore::msg_sm_1_i_6_r_4_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_6_r_4_t_3_busy, S1MMEtore::msg_sm_1_i_6_r_4_t_3_cnt, S1MMEtore::msg_sm_1_i_6_r_4_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_6_r_4_t_4_busy, S1MMEtore::msg_sm_1_i_6_r_4_t_4_cnt, S1MMEtore::msg_sm_1_i_6_r_4_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_6_r_4_t_5_busy, S1MMEtore::msg_sm_1_i_6_r_4_t_5_cnt, S1MMEtore::msg_sm_1_i_6_r_4_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_6_r_4_t_6_busy, S1MMEtore::msg_sm_1_i_6_r_4_t_6_cnt, S1MMEtore::msg_sm_1_i_6_r_4_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_6_r_4_t_7_busy, S1MMEtore::msg_sm_1_i_6_r_4_t_7_cnt, S1MMEtore::msg_sm_1_i_6_r_4_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_6_r_4_t_8_busy, S1MMEtore::msg_sm_1_i_6_r_4_t_8_cnt, S1MMEtore::msg_sm_1_i_6_r_4_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_6_r_4_t_9_busy, S1MMEtore::msg_sm_1_i_6_r_4_t_9_cnt, S1MMEtore::msg_sm_1_i_6_r_4_t_9, pSctp);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_6_r_4_t_0_busy, S1MMEtore::msg_sm_2_i_6_r_4_t_0_cnt, S1MMEtore::msg_sm_2_i_6_r_4_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_6_r_4_t_1_busy, S1MMEtore::msg_sm_2_i_6_r_4_t_1_cnt, S1MMEtore::msg_sm_2_i_6_r_4_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_6_r_4_t_2_busy, S1MMEtore::msg_sm_2_i_6_r_4_t_2_cnt, S1MMEtore::msg_sm_2_i_6_r_4_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_6_r_4_t_3_busy, S1MMEtore::msg_sm_2_i_6_r_4_t_3_cnt, S1MMEtore::msg_sm_2_i_6_r_4_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_6_r_4_t_4_busy, S1MMEtore::msg_sm_2_i_6_r_4_t_4_cnt, S1MMEtore::msg_sm_2_i_6_r_4_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_6_r_4_t_5_busy, S1MMEtore::msg_sm_2_i_6_r_4_t_5_cnt, S1MMEtore::msg_sm_2_i_6_r_4_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_6_r_4_t_6_busy, S1MMEtore::msg_sm_2_i_6_r_4_t_6_cnt, S1MMEtore::msg_sm_2_i_6_r_4_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_6_r_4_t_7_busy, S1MMEtore::msg_sm_2_i_6_r_4_t_7_cnt, S1MMEtore::msg_sm_2_i_6_r_4_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_6_r_4_t_8_busy, S1MMEtore::msg_sm_2_i_6_r_4_t_8_cnt, S1MMEtore::msg_sm_2_i_6_r_4_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_6_r_4_t_9_busy, S1MMEtore::msg_sm_2_i_6_r_4_t_9_cnt, S1MMEtore::msg_sm_2_i_6_r_4_t_9, pSctp);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_6_r_4_t_0_busy, S1MMEtore::msg_sm_3_i_6_r_4_t_0_cnt, S1MMEtore::msg_sm_3_i_6_r_4_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_6_r_4_t_1_busy, S1MMEtore::msg_sm_3_i_6_r_4_t_1_cnt, S1MMEtore::msg_sm_3_i_6_r_4_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_6_r_4_t_2_busy, S1MMEtore::msg_sm_3_i_6_r_4_t_2_cnt, S1MMEtore::msg_sm_3_i_6_r_4_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_6_r_4_t_3_busy, S1MMEtore::msg_sm_3_i_6_r_4_t_3_cnt, S1MMEtore::msg_sm_3_i_6_r_4_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_6_r_4_t_4_busy, S1MMEtore::msg_sm_3_i_6_r_4_t_4_cnt, S1MMEtore::msg_sm_3_i_6_r_4_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_6_r_4_t_5_busy, S1MMEtore::msg_sm_3_i_6_r_4_t_5_cnt, S1MMEtore::msg_sm_3_i_6_r_4_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_6_r_4_t_6_busy, S1MMEtore::msg_sm_3_i_6_r_4_t_6_cnt, S1MMEtore::msg_sm_3_i_6_r_4_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_6_r_4_t_7_busy, S1MMEtore::msg_sm_3_i_6_r_4_t_7_cnt, S1MMEtore::msg_sm_3_i_6_r_4_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_6_r_4_t_8_busy, S1MMEtore::msg_sm_3_i_6_r_4_t_8_cnt, S1MMEtore::msg_sm_3_i_6_r_4_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_6_r_4_t_9_busy, S1MMEtore::msg_sm_3_i_6_r_4_t_9_cnt, S1MMEtore::msg_sm_3_i_6_r_4_t_9, pSctp);
				break;
			}
			break;
	}
}

VOID SctpMessageBroker::pushToQueue_i_6_r_5(Sctp *pSctp, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_6_r_5_t_0_busy, S1MMEtore::msg_sm_0_i_6_r_5_t_0_cnt, S1MMEtore::msg_sm_0_i_6_r_5_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_6_r_5_t_1_busy, S1MMEtore::msg_sm_0_i_6_r_5_t_1_cnt, S1MMEtore::msg_sm_0_i_6_r_5_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_6_r_5_t_2_busy, S1MMEtore::msg_sm_0_i_6_r_5_t_2_cnt, S1MMEtore::msg_sm_0_i_6_r_5_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_6_r_5_t_3_busy, S1MMEtore::msg_sm_0_i_6_r_5_t_3_cnt, S1MMEtore::msg_sm_0_i_6_r_5_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_6_r_5_t_4_busy, S1MMEtore::msg_sm_0_i_6_r_5_t_4_cnt, S1MMEtore::msg_sm_0_i_6_r_5_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_6_r_5_t_5_busy, S1MMEtore::msg_sm_0_i_6_r_5_t_5_cnt, S1MMEtore::msg_sm_0_i_6_r_5_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_6_r_5_t_6_busy, S1MMEtore::msg_sm_0_i_6_r_5_t_6_cnt, S1MMEtore::msg_sm_0_i_6_r_5_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_6_r_5_t_7_busy, S1MMEtore::msg_sm_0_i_6_r_5_t_7_cnt, S1MMEtore::msg_sm_0_i_6_r_5_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_6_r_5_t_8_busy, S1MMEtore::msg_sm_0_i_6_r_5_t_8_cnt, S1MMEtore::msg_sm_0_i_6_r_5_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_6_r_5_t_9_busy, S1MMEtore::msg_sm_0_i_6_r_5_t_9_cnt, S1MMEtore::msg_sm_0_i_6_r_5_t_9, pSctp);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_6_r_5_t_0_busy, S1MMEtore::msg_sm_1_i_6_r_5_t_0_cnt, S1MMEtore::msg_sm_1_i_6_r_5_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_6_r_5_t_1_busy, S1MMEtore::msg_sm_1_i_6_r_5_t_1_cnt, S1MMEtore::msg_sm_1_i_6_r_5_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_6_r_5_t_2_busy, S1MMEtore::msg_sm_1_i_6_r_5_t_2_cnt, S1MMEtore::msg_sm_1_i_6_r_5_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_6_r_5_t_3_busy, S1MMEtore::msg_sm_1_i_6_r_5_t_3_cnt, S1MMEtore::msg_sm_1_i_6_r_5_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_6_r_5_t_4_busy, S1MMEtore::msg_sm_1_i_6_r_5_t_4_cnt, S1MMEtore::msg_sm_1_i_6_r_5_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_6_r_5_t_5_busy, S1MMEtore::msg_sm_1_i_6_r_5_t_5_cnt, S1MMEtore::msg_sm_1_i_6_r_5_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_6_r_5_t_6_busy, S1MMEtore::msg_sm_1_i_6_r_5_t_6_cnt, S1MMEtore::msg_sm_1_i_6_r_5_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_6_r_5_t_7_busy, S1MMEtore::msg_sm_1_i_6_r_5_t_7_cnt, S1MMEtore::msg_sm_1_i_6_r_5_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_6_r_5_t_8_busy, S1MMEtore::msg_sm_1_i_6_r_5_t_8_cnt, S1MMEtore::msg_sm_1_i_6_r_5_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_6_r_5_t_9_busy, S1MMEtore::msg_sm_1_i_6_r_5_t_9_cnt, S1MMEtore::msg_sm_1_i_6_r_5_t_9, pSctp);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_6_r_5_t_0_busy, S1MMEtore::msg_sm_2_i_6_r_5_t_0_cnt, S1MMEtore::msg_sm_2_i_6_r_5_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_6_r_5_t_1_busy, S1MMEtore::msg_sm_2_i_6_r_5_t_1_cnt, S1MMEtore::msg_sm_2_i_6_r_5_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_6_r_5_t_2_busy, S1MMEtore::msg_sm_2_i_6_r_5_t_2_cnt, S1MMEtore::msg_sm_2_i_6_r_5_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_6_r_5_t_3_busy, S1MMEtore::msg_sm_2_i_6_r_5_t_3_cnt, S1MMEtore::msg_sm_2_i_6_r_5_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_6_r_5_t_4_busy, S1MMEtore::msg_sm_2_i_6_r_5_t_4_cnt, S1MMEtore::msg_sm_2_i_6_r_5_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_6_r_5_t_5_busy, S1MMEtore::msg_sm_2_i_6_r_5_t_5_cnt, S1MMEtore::msg_sm_2_i_6_r_5_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_6_r_5_t_6_busy, S1MMEtore::msg_sm_2_i_6_r_5_t_6_cnt, S1MMEtore::msg_sm_2_i_6_r_5_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_6_r_5_t_7_busy, S1MMEtore::msg_sm_2_i_6_r_5_t_7_cnt, S1MMEtore::msg_sm_2_i_6_r_5_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_6_r_5_t_8_busy, S1MMEtore::msg_sm_2_i_6_r_5_t_8_cnt, S1MMEtore::msg_sm_2_i_6_r_5_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_6_r_5_t_9_busy, S1MMEtore::msg_sm_2_i_6_r_5_t_9_cnt, S1MMEtore::msg_sm_2_i_6_r_5_t_9, pSctp);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_6_r_5_t_0_busy, S1MMEtore::msg_sm_3_i_6_r_5_t_0_cnt, S1MMEtore::msg_sm_3_i_6_r_5_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_6_r_5_t_1_busy, S1MMEtore::msg_sm_3_i_6_r_5_t_1_cnt, S1MMEtore::msg_sm_3_i_6_r_5_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_6_r_5_t_2_busy, S1MMEtore::msg_sm_3_i_6_r_5_t_2_cnt, S1MMEtore::msg_sm_3_i_6_r_5_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_6_r_5_t_3_busy, S1MMEtore::msg_sm_3_i_6_r_5_t_3_cnt, S1MMEtore::msg_sm_3_i_6_r_5_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_6_r_5_t_4_busy, S1MMEtore::msg_sm_3_i_6_r_5_t_4_cnt, S1MMEtore::msg_sm_3_i_6_r_5_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_6_r_5_t_5_busy, S1MMEtore::msg_sm_3_i_6_r_5_t_5_cnt, S1MMEtore::msg_sm_3_i_6_r_5_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_6_r_5_t_6_busy, S1MMEtore::msg_sm_3_i_6_r_5_t_6_cnt, S1MMEtore::msg_sm_3_i_6_r_5_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_6_r_5_t_7_busy, S1MMEtore::msg_sm_3_i_6_r_5_t_7_cnt, S1MMEtore::msg_sm_3_i_6_r_5_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_6_r_5_t_8_busy, S1MMEtore::msg_sm_3_i_6_r_5_t_8_cnt, S1MMEtore::msg_sm_3_i_6_r_5_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_6_r_5_t_9_busy, S1MMEtore::msg_sm_3_i_6_r_5_t_9_cnt, S1MMEtore::msg_sm_3_i_6_r_5_t_9, pSctp);
				break;
			}
			break;
	}
}

VOID SctpMessageBroker::pushToQueue_i_6_r_6(Sctp *pSctp, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_6_r_6_t_0_busy, S1MMEtore::msg_sm_0_i_6_r_6_t_0_cnt, S1MMEtore::msg_sm_0_i_6_r_6_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_6_r_6_t_1_busy, S1MMEtore::msg_sm_0_i_6_r_6_t_1_cnt, S1MMEtore::msg_sm_0_i_6_r_6_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_6_r_6_t_2_busy, S1MMEtore::msg_sm_0_i_6_r_6_t_2_cnt, S1MMEtore::msg_sm_0_i_6_r_6_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_6_r_6_t_3_busy, S1MMEtore::msg_sm_0_i_6_r_6_t_3_cnt, S1MMEtore::msg_sm_0_i_6_r_6_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_6_r_6_t_4_busy, S1MMEtore::msg_sm_0_i_6_r_6_t_4_cnt, S1MMEtore::msg_sm_0_i_6_r_6_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_6_r_6_t_5_busy, S1MMEtore::msg_sm_0_i_6_r_6_t_5_cnt, S1MMEtore::msg_sm_0_i_6_r_6_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_6_r_6_t_6_busy, S1MMEtore::msg_sm_0_i_6_r_6_t_6_cnt, S1MMEtore::msg_sm_0_i_6_r_6_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_6_r_6_t_7_busy, S1MMEtore::msg_sm_0_i_6_r_6_t_7_cnt, S1MMEtore::msg_sm_0_i_6_r_6_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_6_r_6_t_8_busy, S1MMEtore::msg_sm_0_i_6_r_6_t_8_cnt, S1MMEtore::msg_sm_0_i_6_r_6_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_6_r_6_t_9_busy, S1MMEtore::msg_sm_0_i_6_r_6_t_9_cnt, S1MMEtore::msg_sm_0_i_6_r_6_t_9, pSctp);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_6_r_6_t_0_busy, S1MMEtore::msg_sm_1_i_6_r_6_t_0_cnt, S1MMEtore::msg_sm_1_i_6_r_6_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_6_r_6_t_1_busy, S1MMEtore::msg_sm_1_i_6_r_6_t_1_cnt, S1MMEtore::msg_sm_1_i_6_r_6_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_6_r_6_t_2_busy, S1MMEtore::msg_sm_1_i_6_r_6_t_2_cnt, S1MMEtore::msg_sm_1_i_6_r_6_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_6_r_6_t_3_busy, S1MMEtore::msg_sm_1_i_6_r_6_t_3_cnt, S1MMEtore::msg_sm_1_i_6_r_6_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_6_r_6_t_4_busy, S1MMEtore::msg_sm_1_i_6_r_6_t_4_cnt, S1MMEtore::msg_sm_1_i_6_r_6_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_6_r_6_t_5_busy, S1MMEtore::msg_sm_1_i_6_r_6_t_5_cnt, S1MMEtore::msg_sm_1_i_6_r_6_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_6_r_6_t_6_busy, S1MMEtore::msg_sm_1_i_6_r_6_t_6_cnt, S1MMEtore::msg_sm_1_i_6_r_6_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_6_r_6_t_7_busy, S1MMEtore::msg_sm_1_i_6_r_6_t_7_cnt, S1MMEtore::msg_sm_1_i_6_r_6_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_6_r_6_t_8_busy, S1MMEtore::msg_sm_1_i_6_r_6_t_8_cnt, S1MMEtore::msg_sm_1_i_6_r_6_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_6_r_6_t_9_busy, S1MMEtore::msg_sm_1_i_6_r_6_t_9_cnt, S1MMEtore::msg_sm_1_i_6_r_6_t_9, pSctp);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_6_r_6_t_0_busy, S1MMEtore::msg_sm_2_i_6_r_6_t_0_cnt, S1MMEtore::msg_sm_2_i_6_r_6_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_6_r_6_t_1_busy, S1MMEtore::msg_sm_2_i_6_r_6_t_1_cnt, S1MMEtore::msg_sm_2_i_6_r_6_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_6_r_6_t_2_busy, S1MMEtore::msg_sm_2_i_6_r_6_t_2_cnt, S1MMEtore::msg_sm_2_i_6_r_6_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_6_r_6_t_3_busy, S1MMEtore::msg_sm_2_i_6_r_6_t_3_cnt, S1MMEtore::msg_sm_2_i_6_r_6_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_6_r_6_t_4_busy, S1MMEtore::msg_sm_2_i_6_r_6_t_4_cnt, S1MMEtore::msg_sm_2_i_6_r_6_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_6_r_6_t_5_busy, S1MMEtore::msg_sm_2_i_6_r_6_t_5_cnt, S1MMEtore::msg_sm_2_i_6_r_6_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_6_r_6_t_6_busy, S1MMEtore::msg_sm_2_i_6_r_6_t_6_cnt, S1MMEtore::msg_sm_2_i_6_r_6_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_6_r_6_t_7_busy, S1MMEtore::msg_sm_2_i_6_r_6_t_7_cnt, S1MMEtore::msg_sm_2_i_6_r_6_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_6_r_6_t_8_busy, S1MMEtore::msg_sm_2_i_6_r_6_t_8_cnt, S1MMEtore::msg_sm_2_i_6_r_6_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_6_r_6_t_9_busy, S1MMEtore::msg_sm_2_i_6_r_6_t_9_cnt, S1MMEtore::msg_sm_2_i_6_r_6_t_9, pSctp);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_6_r_6_t_0_busy, S1MMEtore::msg_sm_3_i_6_r_6_t_0_cnt, S1MMEtore::msg_sm_3_i_6_r_6_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_6_r_6_t_1_busy, S1MMEtore::msg_sm_3_i_6_r_6_t_1_cnt, S1MMEtore::msg_sm_3_i_6_r_6_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_6_r_6_t_2_busy, S1MMEtore::msg_sm_3_i_6_r_6_t_2_cnt, S1MMEtore::msg_sm_3_i_6_r_6_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_6_r_6_t_3_busy, S1MMEtore::msg_sm_3_i_6_r_6_t_3_cnt, S1MMEtore::msg_sm_3_i_6_r_6_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_6_r_6_t_4_busy, S1MMEtore::msg_sm_3_i_6_r_6_t_4_cnt, S1MMEtore::msg_sm_3_i_6_r_6_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_6_r_6_t_5_busy, S1MMEtore::msg_sm_3_i_6_r_6_t_5_cnt, S1MMEtore::msg_sm_3_i_6_r_6_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_6_r_6_t_6_busy, S1MMEtore::msg_sm_3_i_6_r_6_t_6_cnt, S1MMEtore::msg_sm_3_i_6_r_6_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_6_r_6_t_7_busy, S1MMEtore::msg_sm_3_i_6_r_6_t_7_cnt, S1MMEtore::msg_sm_3_i_6_r_6_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_6_r_6_t_8_busy, S1MMEtore::msg_sm_3_i_6_r_6_t_8_cnt, S1MMEtore::msg_sm_3_i_6_r_6_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_6_r_6_t_9_busy, S1MMEtore::msg_sm_3_i_6_r_6_t_9_cnt, S1MMEtore::msg_sm_3_i_6_r_6_t_9, pSctp);
				break;
			}
			break;
	}
}

VOID SctpMessageBroker::pushToQueue_i_6_r_7(Sctp *pSctp, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_6_r_7_t_0_busy, S1MMEtore::msg_sm_0_i_6_r_7_t_0_cnt, S1MMEtore::msg_sm_0_i_6_r_7_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_6_r_7_t_1_busy, S1MMEtore::msg_sm_0_i_6_r_7_t_1_cnt, S1MMEtore::msg_sm_0_i_6_r_7_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_6_r_7_t_2_busy, S1MMEtore::msg_sm_0_i_6_r_7_t_2_cnt, S1MMEtore::msg_sm_0_i_6_r_7_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_6_r_7_t_3_busy, S1MMEtore::msg_sm_0_i_6_r_7_t_3_cnt, S1MMEtore::msg_sm_0_i_6_r_7_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_6_r_7_t_4_busy, S1MMEtore::msg_sm_0_i_6_r_7_t_4_cnt, S1MMEtore::msg_sm_0_i_6_r_7_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_6_r_7_t_5_busy, S1MMEtore::msg_sm_0_i_6_r_7_t_5_cnt, S1MMEtore::msg_sm_0_i_6_r_7_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_6_r_7_t_6_busy, S1MMEtore::msg_sm_0_i_6_r_7_t_6_cnt, S1MMEtore::msg_sm_0_i_6_r_7_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_6_r_7_t_7_busy, S1MMEtore::msg_sm_0_i_6_r_7_t_7_cnt, S1MMEtore::msg_sm_0_i_6_r_7_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_6_r_7_t_8_busy, S1MMEtore::msg_sm_0_i_6_r_7_t_8_cnt, S1MMEtore::msg_sm_0_i_6_r_7_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_6_r_7_t_9_busy, S1MMEtore::msg_sm_0_i_6_r_7_t_9_cnt, S1MMEtore::msg_sm_0_i_6_r_7_t_9, pSctp);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_6_r_7_t_0_busy, S1MMEtore::msg_sm_1_i_6_r_7_t_0_cnt, S1MMEtore::msg_sm_1_i_6_r_7_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_6_r_7_t_1_busy, S1MMEtore::msg_sm_1_i_6_r_7_t_1_cnt, S1MMEtore::msg_sm_1_i_6_r_7_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_6_r_7_t_2_busy, S1MMEtore::msg_sm_1_i_6_r_7_t_2_cnt, S1MMEtore::msg_sm_1_i_6_r_7_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_6_r_7_t_3_busy, S1MMEtore::msg_sm_1_i_6_r_7_t_3_cnt, S1MMEtore::msg_sm_1_i_6_r_7_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_6_r_7_t_4_busy, S1MMEtore::msg_sm_1_i_6_r_7_t_4_cnt, S1MMEtore::msg_sm_1_i_6_r_7_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_6_r_7_t_5_busy, S1MMEtore::msg_sm_1_i_6_r_7_t_5_cnt, S1MMEtore::msg_sm_1_i_6_r_7_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_6_r_7_t_6_busy, S1MMEtore::msg_sm_1_i_6_r_7_t_6_cnt, S1MMEtore::msg_sm_1_i_6_r_7_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_6_r_7_t_7_busy, S1MMEtore::msg_sm_1_i_6_r_7_t_7_cnt, S1MMEtore::msg_sm_1_i_6_r_7_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_6_r_7_t_8_busy, S1MMEtore::msg_sm_1_i_6_r_7_t_8_cnt, S1MMEtore::msg_sm_1_i_6_r_7_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_6_r_7_t_9_busy, S1MMEtore::msg_sm_1_i_6_r_7_t_9_cnt, S1MMEtore::msg_sm_1_i_6_r_7_t_9, pSctp);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_6_r_7_t_0_busy, S1MMEtore::msg_sm_2_i_6_r_7_t_0_cnt, S1MMEtore::msg_sm_2_i_6_r_7_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_6_r_7_t_1_busy, S1MMEtore::msg_sm_2_i_6_r_7_t_1_cnt, S1MMEtore::msg_sm_2_i_6_r_7_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_6_r_7_t_2_busy, S1MMEtore::msg_sm_2_i_6_r_7_t_2_cnt, S1MMEtore::msg_sm_2_i_6_r_7_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_6_r_7_t_3_busy, S1MMEtore::msg_sm_2_i_6_r_7_t_3_cnt, S1MMEtore::msg_sm_2_i_6_r_7_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_6_r_7_t_4_busy, S1MMEtore::msg_sm_2_i_6_r_7_t_4_cnt, S1MMEtore::msg_sm_2_i_6_r_7_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_6_r_7_t_5_busy, S1MMEtore::msg_sm_2_i_6_r_7_t_5_cnt, S1MMEtore::msg_sm_2_i_6_r_7_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_6_r_7_t_6_busy, S1MMEtore::msg_sm_2_i_6_r_7_t_6_cnt, S1MMEtore::msg_sm_2_i_6_r_7_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_6_r_7_t_7_busy, S1MMEtore::msg_sm_2_i_6_r_7_t_7_cnt, S1MMEtore::msg_sm_2_i_6_r_7_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_6_r_7_t_8_busy, S1MMEtore::msg_sm_2_i_6_r_7_t_8_cnt, S1MMEtore::msg_sm_2_i_6_r_7_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_6_r_7_t_9_busy, S1MMEtore::msg_sm_2_i_6_r_7_t_9_cnt, S1MMEtore::msg_sm_2_i_6_r_7_t_9, pSctp);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_6_r_7_t_0_busy, S1MMEtore::msg_sm_3_i_6_r_7_t_0_cnt, S1MMEtore::msg_sm_3_i_6_r_7_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_6_r_7_t_1_busy, S1MMEtore::msg_sm_3_i_6_r_7_t_1_cnt, S1MMEtore::msg_sm_3_i_6_r_7_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_6_r_7_t_2_busy, S1MMEtore::msg_sm_3_i_6_r_7_t_2_cnt, S1MMEtore::msg_sm_3_i_6_r_7_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_6_r_7_t_3_busy, S1MMEtore::msg_sm_3_i_6_r_7_t_3_cnt, S1MMEtore::msg_sm_3_i_6_r_7_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_6_r_7_t_4_busy, S1MMEtore::msg_sm_3_i_6_r_7_t_4_cnt, S1MMEtore::msg_sm_3_i_6_r_7_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_6_r_7_t_5_busy, S1MMEtore::msg_sm_3_i_6_r_7_t_5_cnt, S1MMEtore::msg_sm_3_i_6_r_7_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_6_r_7_t_6_busy, S1MMEtore::msg_sm_3_i_6_r_7_t_6_cnt, S1MMEtore::msg_sm_3_i_6_r_7_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_6_r_7_t_7_busy, S1MMEtore::msg_sm_3_i_6_r_7_t_7_cnt, S1MMEtore::msg_sm_3_i_6_r_7_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_6_r_7_t_8_busy, S1MMEtore::msg_sm_3_i_6_r_7_t_8_cnt, S1MMEtore::msg_sm_3_i_6_r_7_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_6_r_7_t_9_busy, S1MMEtore::msg_sm_3_i_6_r_7_t_9_cnt, S1MMEtore::msg_sm_3_i_6_r_7_t_9, pSctp);
				break;
			}
			break;
	}
}


VOID SctpMessageBroker::pushToQueue_i_7_r_0(Sctp *pSctp, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_7_r_0_t_0_busy, S1MMEtore::msg_sm_0_i_7_r_0_t_0_cnt, S1MMEtore::msg_sm_0_i_7_r_0_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_7_r_0_t_1_busy, S1MMEtore::msg_sm_0_i_7_r_0_t_1_cnt, S1MMEtore::msg_sm_0_i_7_r_0_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_7_r_0_t_2_busy, S1MMEtore::msg_sm_0_i_7_r_0_t_2_cnt, S1MMEtore::msg_sm_0_i_7_r_0_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_7_r_0_t_3_busy, S1MMEtore::msg_sm_0_i_7_r_0_t_3_cnt, S1MMEtore::msg_sm_0_i_7_r_0_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_7_r_0_t_4_busy, S1MMEtore::msg_sm_0_i_7_r_0_t_4_cnt, S1MMEtore::msg_sm_0_i_7_r_0_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_7_r_0_t_5_busy, S1MMEtore::msg_sm_0_i_7_r_0_t_5_cnt, S1MMEtore::msg_sm_0_i_7_r_0_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_7_r_0_t_6_busy, S1MMEtore::msg_sm_0_i_7_r_0_t_6_cnt, S1MMEtore::msg_sm_0_i_7_r_0_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_7_r_0_t_7_busy, S1MMEtore::msg_sm_0_i_7_r_0_t_7_cnt, S1MMEtore::msg_sm_0_i_7_r_0_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_7_r_0_t_8_busy, S1MMEtore::msg_sm_0_i_7_r_0_t_8_cnt, S1MMEtore::msg_sm_0_i_7_r_0_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_7_r_0_t_9_busy, S1MMEtore::msg_sm_0_i_7_r_0_t_9_cnt, S1MMEtore::msg_sm_0_i_7_r_0_t_9, pSctp);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_7_r_0_t_0_busy, S1MMEtore::msg_sm_1_i_7_r_0_t_0_cnt, S1MMEtore::msg_sm_1_i_7_r_0_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_7_r_0_t_1_busy, S1MMEtore::msg_sm_1_i_7_r_0_t_1_cnt, S1MMEtore::msg_sm_1_i_7_r_0_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_7_r_0_t_2_busy, S1MMEtore::msg_sm_1_i_7_r_0_t_2_cnt, S1MMEtore::msg_sm_1_i_7_r_0_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_7_r_0_t_3_busy, S1MMEtore::msg_sm_1_i_7_r_0_t_3_cnt, S1MMEtore::msg_sm_1_i_7_r_0_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_7_r_0_t_4_busy, S1MMEtore::msg_sm_1_i_7_r_0_t_4_cnt, S1MMEtore::msg_sm_1_i_7_r_0_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_7_r_0_t_5_busy, S1MMEtore::msg_sm_1_i_7_r_0_t_5_cnt, S1MMEtore::msg_sm_1_i_7_r_0_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_7_r_0_t_6_busy, S1MMEtore::msg_sm_1_i_7_r_0_t_6_cnt, S1MMEtore::msg_sm_1_i_7_r_0_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_7_r_0_t_7_busy, S1MMEtore::msg_sm_1_i_7_r_0_t_7_cnt, S1MMEtore::msg_sm_1_i_7_r_0_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_7_r_0_t_8_busy, S1MMEtore::msg_sm_1_i_7_r_0_t_8_cnt, S1MMEtore::msg_sm_1_i_7_r_0_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_7_r_0_t_9_busy, S1MMEtore::msg_sm_1_i_7_r_0_t_9_cnt, S1MMEtore::msg_sm_1_i_7_r_0_t_9, pSctp);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_7_r_0_t_0_busy, S1MMEtore::msg_sm_2_i_7_r_0_t_0_cnt, S1MMEtore::msg_sm_2_i_7_r_0_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_7_r_0_t_1_busy, S1MMEtore::msg_sm_2_i_7_r_0_t_1_cnt, S1MMEtore::msg_sm_2_i_7_r_0_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_7_r_0_t_2_busy, S1MMEtore::msg_sm_2_i_7_r_0_t_2_cnt, S1MMEtore::msg_sm_2_i_7_r_0_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_7_r_0_t_3_busy, S1MMEtore::msg_sm_2_i_7_r_0_t_3_cnt, S1MMEtore::msg_sm_2_i_7_r_0_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_7_r_0_t_4_busy, S1MMEtore::msg_sm_2_i_7_r_0_t_4_cnt, S1MMEtore::msg_sm_2_i_7_r_0_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_7_r_0_t_5_busy, S1MMEtore::msg_sm_2_i_7_r_0_t_5_cnt, S1MMEtore::msg_sm_2_i_7_r_0_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_7_r_0_t_6_busy, S1MMEtore::msg_sm_2_i_7_r_0_t_6_cnt, S1MMEtore::msg_sm_2_i_7_r_0_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_7_r_0_t_7_busy, S1MMEtore::msg_sm_2_i_7_r_0_t_7_cnt, S1MMEtore::msg_sm_2_i_7_r_0_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_7_r_0_t_8_busy, S1MMEtore::msg_sm_2_i_7_r_0_t_8_cnt, S1MMEtore::msg_sm_2_i_7_r_0_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_7_r_0_t_9_busy, S1MMEtore::msg_sm_2_i_7_r_0_t_9_cnt, S1MMEtore::msg_sm_2_i_7_r_0_t_9, pSctp);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_7_r_0_t_0_busy, S1MMEtore::msg_sm_3_i_7_r_0_t_0_cnt, S1MMEtore::msg_sm_3_i_7_r_0_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_7_r_0_t_1_busy, S1MMEtore::msg_sm_3_i_7_r_0_t_1_cnt, S1MMEtore::msg_sm_3_i_7_r_0_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_7_r_0_t_2_busy, S1MMEtore::msg_sm_3_i_7_r_0_t_2_cnt, S1MMEtore::msg_sm_3_i_7_r_0_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_7_r_0_t_3_busy, S1MMEtore::msg_sm_3_i_7_r_0_t_3_cnt, S1MMEtore::msg_sm_3_i_7_r_0_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_7_r_0_t_4_busy, S1MMEtore::msg_sm_3_i_7_r_0_t_4_cnt, S1MMEtore::msg_sm_3_i_7_r_0_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_7_r_0_t_5_busy, S1MMEtore::msg_sm_3_i_7_r_0_t_5_cnt, S1MMEtore::msg_sm_3_i_7_r_0_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_7_r_0_t_6_busy, S1MMEtore::msg_sm_3_i_7_r_0_t_6_cnt, S1MMEtore::msg_sm_3_i_7_r_0_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_7_r_0_t_7_busy, S1MMEtore::msg_sm_3_i_7_r_0_t_7_cnt, S1MMEtore::msg_sm_3_i_7_r_0_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_7_r_0_t_8_busy, S1MMEtore::msg_sm_3_i_7_r_0_t_8_cnt, S1MMEtore::msg_sm_3_i_7_r_0_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_7_r_0_t_9_busy, S1MMEtore::msg_sm_3_i_7_r_0_t_9_cnt, S1MMEtore::msg_sm_3_i_7_r_0_t_9, pSctp);
				break;
			}
			break;
	}
}

VOID SctpMessageBroker::pushToQueue_i_7_r_1(Sctp *pSctp, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_7_r_1_t_0_busy, S1MMEtore::msg_sm_0_i_7_r_1_t_0_cnt, S1MMEtore::msg_sm_0_i_7_r_1_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_7_r_1_t_1_busy, S1MMEtore::msg_sm_0_i_7_r_1_t_1_cnt, S1MMEtore::msg_sm_0_i_7_r_1_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_7_r_1_t_2_busy, S1MMEtore::msg_sm_0_i_7_r_1_t_2_cnt, S1MMEtore::msg_sm_0_i_7_r_1_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_7_r_1_t_3_busy, S1MMEtore::msg_sm_0_i_7_r_1_t_3_cnt, S1MMEtore::msg_sm_0_i_7_r_1_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_7_r_1_t_4_busy, S1MMEtore::msg_sm_0_i_7_r_1_t_4_cnt, S1MMEtore::msg_sm_0_i_7_r_1_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_7_r_1_t_5_busy, S1MMEtore::msg_sm_0_i_7_r_1_t_5_cnt, S1MMEtore::msg_sm_0_i_7_r_1_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_7_r_1_t_6_busy, S1MMEtore::msg_sm_0_i_7_r_1_t_6_cnt, S1MMEtore::msg_sm_0_i_7_r_1_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_7_r_1_t_7_busy, S1MMEtore::msg_sm_0_i_7_r_1_t_7_cnt, S1MMEtore::msg_sm_0_i_7_r_1_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_7_r_1_t_8_busy, S1MMEtore::msg_sm_0_i_7_r_1_t_8_cnt, S1MMEtore::msg_sm_0_i_7_r_1_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_7_r_1_t_9_busy, S1MMEtore::msg_sm_0_i_7_r_1_t_9_cnt, S1MMEtore::msg_sm_0_i_7_r_1_t_9, pSctp);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_7_r_1_t_0_busy, S1MMEtore::msg_sm_1_i_7_r_1_t_0_cnt, S1MMEtore::msg_sm_1_i_7_r_1_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_7_r_1_t_1_busy, S1MMEtore::msg_sm_1_i_7_r_1_t_1_cnt, S1MMEtore::msg_sm_1_i_7_r_1_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_7_r_1_t_2_busy, S1MMEtore::msg_sm_1_i_7_r_1_t_2_cnt, S1MMEtore::msg_sm_1_i_7_r_1_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_7_r_1_t_3_busy, S1MMEtore::msg_sm_1_i_7_r_1_t_3_cnt, S1MMEtore::msg_sm_1_i_7_r_1_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_7_r_1_t_4_busy, S1MMEtore::msg_sm_1_i_7_r_1_t_4_cnt, S1MMEtore::msg_sm_1_i_7_r_1_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_7_r_1_t_5_busy, S1MMEtore::msg_sm_1_i_7_r_1_t_5_cnt, S1MMEtore::msg_sm_1_i_7_r_1_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_7_r_1_t_6_busy, S1MMEtore::msg_sm_1_i_7_r_1_t_6_cnt, S1MMEtore::msg_sm_1_i_7_r_1_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_7_r_1_t_7_busy, S1MMEtore::msg_sm_1_i_7_r_1_t_7_cnt, S1MMEtore::msg_sm_1_i_7_r_1_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_7_r_1_t_8_busy, S1MMEtore::msg_sm_1_i_7_r_1_t_8_cnt, S1MMEtore::msg_sm_1_i_7_r_1_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_7_r_1_t_9_busy, S1MMEtore::msg_sm_1_i_7_r_1_t_9_cnt, S1MMEtore::msg_sm_1_i_7_r_1_t_9, pSctp);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_7_r_1_t_0_busy, S1MMEtore::msg_sm_2_i_7_r_1_t_0_cnt, S1MMEtore::msg_sm_2_i_7_r_1_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_7_r_1_t_1_busy, S1MMEtore::msg_sm_2_i_7_r_1_t_1_cnt, S1MMEtore::msg_sm_2_i_7_r_1_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_7_r_1_t_2_busy, S1MMEtore::msg_sm_2_i_7_r_1_t_2_cnt, S1MMEtore::msg_sm_2_i_7_r_1_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_7_r_1_t_3_busy, S1MMEtore::msg_sm_2_i_7_r_1_t_3_cnt, S1MMEtore::msg_sm_2_i_7_r_1_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_7_r_1_t_4_busy, S1MMEtore::msg_sm_2_i_7_r_1_t_4_cnt, S1MMEtore::msg_sm_2_i_7_r_1_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_7_r_1_t_5_busy, S1MMEtore::msg_sm_2_i_7_r_1_t_5_cnt, S1MMEtore::msg_sm_2_i_7_r_1_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_7_r_1_t_6_busy, S1MMEtore::msg_sm_2_i_7_r_1_t_6_cnt, S1MMEtore::msg_sm_2_i_7_r_1_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_7_r_1_t_7_busy, S1MMEtore::msg_sm_2_i_7_r_1_t_7_cnt, S1MMEtore::msg_sm_2_i_7_r_1_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_7_r_1_t_8_busy, S1MMEtore::msg_sm_2_i_7_r_1_t_8_cnt, S1MMEtore::msg_sm_2_i_7_r_1_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_7_r_1_t_9_busy, S1MMEtore::msg_sm_2_i_7_r_1_t_9_cnt, S1MMEtore::msg_sm_2_i_7_r_1_t_9, pSctp);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_7_r_1_t_0_busy, S1MMEtore::msg_sm_3_i_7_r_1_t_0_cnt, S1MMEtore::msg_sm_3_i_7_r_1_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_7_r_1_t_1_busy, S1MMEtore::msg_sm_3_i_7_r_1_t_1_cnt, S1MMEtore::msg_sm_3_i_7_r_1_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_7_r_1_t_2_busy, S1MMEtore::msg_sm_3_i_7_r_1_t_2_cnt, S1MMEtore::msg_sm_3_i_7_r_1_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_7_r_1_t_3_busy, S1MMEtore::msg_sm_3_i_7_r_1_t_3_cnt, S1MMEtore::msg_sm_3_i_7_r_1_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_7_r_1_t_4_busy, S1MMEtore::msg_sm_3_i_7_r_1_t_4_cnt, S1MMEtore::msg_sm_3_i_7_r_1_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_7_r_1_t_5_busy, S1MMEtore::msg_sm_3_i_7_r_1_t_5_cnt, S1MMEtore::msg_sm_3_i_7_r_1_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_7_r_1_t_6_busy, S1MMEtore::msg_sm_3_i_7_r_1_t_6_cnt, S1MMEtore::msg_sm_3_i_7_r_1_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_7_r_1_t_7_busy, S1MMEtore::msg_sm_3_i_7_r_1_t_7_cnt, S1MMEtore::msg_sm_3_i_7_r_1_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_7_r_1_t_8_busy, S1MMEtore::msg_sm_3_i_7_r_1_t_8_cnt, S1MMEtore::msg_sm_3_i_7_r_1_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_7_r_1_t_9_busy, S1MMEtore::msg_sm_3_i_7_r_1_t_9_cnt, S1MMEtore::msg_sm_3_i_7_r_1_t_9, pSctp);
				break;
			}
			break;
	}
}

VOID SctpMessageBroker::pushToQueue_i_7_r_2(Sctp *pSctp, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_7_r_2_t_0_busy, S1MMEtore::msg_sm_0_i_7_r_2_t_0_cnt, S1MMEtore::msg_sm_0_i_7_r_2_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_7_r_2_t_1_busy, S1MMEtore::msg_sm_0_i_7_r_2_t_1_cnt, S1MMEtore::msg_sm_0_i_7_r_2_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_7_r_2_t_2_busy, S1MMEtore::msg_sm_0_i_7_r_2_t_2_cnt, S1MMEtore::msg_sm_0_i_7_r_2_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_7_r_2_t_3_busy, S1MMEtore::msg_sm_0_i_7_r_2_t_3_cnt, S1MMEtore::msg_sm_0_i_7_r_2_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_7_r_2_t_4_busy, S1MMEtore::msg_sm_0_i_7_r_2_t_4_cnt, S1MMEtore::msg_sm_0_i_7_r_2_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_7_r_2_t_5_busy, S1MMEtore::msg_sm_0_i_7_r_2_t_5_cnt, S1MMEtore::msg_sm_0_i_7_r_2_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_7_r_2_t_6_busy, S1MMEtore::msg_sm_0_i_7_r_2_t_6_cnt, S1MMEtore::msg_sm_0_i_7_r_2_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_7_r_2_t_7_busy, S1MMEtore::msg_sm_0_i_7_r_2_t_7_cnt, S1MMEtore::msg_sm_0_i_7_r_2_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_7_r_2_t_8_busy, S1MMEtore::msg_sm_0_i_7_r_2_t_8_cnt, S1MMEtore::msg_sm_0_i_7_r_2_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_7_r_2_t_9_busy, S1MMEtore::msg_sm_0_i_7_r_2_t_9_cnt, S1MMEtore::msg_sm_0_i_7_r_2_t_9, pSctp);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_7_r_2_t_0_busy, S1MMEtore::msg_sm_1_i_7_r_2_t_0_cnt, S1MMEtore::msg_sm_1_i_7_r_2_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_7_r_2_t_1_busy, S1MMEtore::msg_sm_1_i_7_r_2_t_1_cnt, S1MMEtore::msg_sm_1_i_7_r_2_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_7_r_2_t_2_busy, S1MMEtore::msg_sm_1_i_7_r_2_t_2_cnt, S1MMEtore::msg_sm_1_i_7_r_2_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_7_r_2_t_3_busy, S1MMEtore::msg_sm_1_i_7_r_2_t_3_cnt, S1MMEtore::msg_sm_1_i_7_r_2_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_7_r_2_t_4_busy, S1MMEtore::msg_sm_1_i_7_r_2_t_4_cnt, S1MMEtore::msg_sm_1_i_7_r_2_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_7_r_2_t_5_busy, S1MMEtore::msg_sm_1_i_7_r_2_t_5_cnt, S1MMEtore::msg_sm_1_i_7_r_2_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_7_r_2_t_6_busy, S1MMEtore::msg_sm_1_i_7_r_2_t_6_cnt, S1MMEtore::msg_sm_1_i_7_r_2_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_7_r_2_t_7_busy, S1MMEtore::msg_sm_1_i_7_r_2_t_7_cnt, S1MMEtore::msg_sm_1_i_7_r_2_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_7_r_2_t_8_busy, S1MMEtore::msg_sm_1_i_7_r_2_t_8_cnt, S1MMEtore::msg_sm_1_i_7_r_2_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_7_r_2_t_9_busy, S1MMEtore::msg_sm_1_i_7_r_2_t_9_cnt, S1MMEtore::msg_sm_1_i_7_r_2_t_9, pSctp);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_7_r_2_t_0_busy, S1MMEtore::msg_sm_2_i_7_r_2_t_0_cnt, S1MMEtore::msg_sm_2_i_7_r_2_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_7_r_2_t_1_busy, S1MMEtore::msg_sm_2_i_7_r_2_t_1_cnt, S1MMEtore::msg_sm_2_i_7_r_2_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_7_r_2_t_2_busy, S1MMEtore::msg_sm_2_i_7_r_2_t_2_cnt, S1MMEtore::msg_sm_2_i_7_r_2_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_7_r_2_t_3_busy, S1MMEtore::msg_sm_2_i_7_r_2_t_3_cnt, S1MMEtore::msg_sm_2_i_7_r_2_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_7_r_2_t_4_busy, S1MMEtore::msg_sm_2_i_7_r_2_t_4_cnt, S1MMEtore::msg_sm_2_i_7_r_2_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_7_r_2_t_5_busy, S1MMEtore::msg_sm_2_i_7_r_2_t_5_cnt, S1MMEtore::msg_sm_2_i_7_r_2_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_7_r_2_t_6_busy, S1MMEtore::msg_sm_2_i_7_r_2_t_6_cnt, S1MMEtore::msg_sm_2_i_7_r_2_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_7_r_2_t_7_busy, S1MMEtore::msg_sm_2_i_7_r_2_t_7_cnt, S1MMEtore::msg_sm_2_i_7_r_2_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_7_r_2_t_8_busy, S1MMEtore::msg_sm_2_i_7_r_2_t_8_cnt, S1MMEtore::msg_sm_2_i_7_r_2_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_7_r_2_t_9_busy, S1MMEtore::msg_sm_2_i_7_r_2_t_9_cnt, S1MMEtore::msg_sm_2_i_7_r_2_t_9, pSctp);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_7_r_2_t_0_busy, S1MMEtore::msg_sm_3_i_7_r_2_t_0_cnt, S1MMEtore::msg_sm_3_i_7_r_2_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_7_r_2_t_1_busy, S1MMEtore::msg_sm_3_i_7_r_2_t_1_cnt, S1MMEtore::msg_sm_3_i_7_r_2_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_7_r_2_t_2_busy, S1MMEtore::msg_sm_3_i_7_r_2_t_2_cnt, S1MMEtore::msg_sm_3_i_7_r_2_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_7_r_2_t_3_busy, S1MMEtore::msg_sm_3_i_7_r_2_t_3_cnt, S1MMEtore::msg_sm_3_i_7_r_2_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_7_r_2_t_4_busy, S1MMEtore::msg_sm_3_i_7_r_2_t_4_cnt, S1MMEtore::msg_sm_3_i_7_r_2_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_7_r_2_t_5_busy, S1MMEtore::msg_sm_3_i_7_r_2_t_5_cnt, S1MMEtore::msg_sm_3_i_7_r_2_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_7_r_2_t_6_busy, S1MMEtore::msg_sm_3_i_7_r_2_t_6_cnt, S1MMEtore::msg_sm_3_i_7_r_2_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_7_r_2_t_7_busy, S1MMEtore::msg_sm_3_i_7_r_2_t_7_cnt, S1MMEtore::msg_sm_3_i_7_r_2_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_7_r_2_t_8_busy, S1MMEtore::msg_sm_3_i_7_r_2_t_8_cnt, S1MMEtore::msg_sm_3_i_7_r_2_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_7_r_2_t_9_busy, S1MMEtore::msg_sm_3_i_7_r_2_t_9_cnt, S1MMEtore::msg_sm_3_i_7_r_2_t_9, pSctp);
				break;
			}
			break;
	}
}

VOID SctpMessageBroker::pushToQueue_i_7_r_3(Sctp *pSctp, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_7_r_3_t_0_busy, S1MMEtore::msg_sm_0_i_7_r_3_t_0_cnt, S1MMEtore::msg_sm_0_i_7_r_3_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_7_r_3_t_1_busy, S1MMEtore::msg_sm_0_i_7_r_3_t_1_cnt, S1MMEtore::msg_sm_0_i_7_r_3_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_7_r_3_t_2_busy, S1MMEtore::msg_sm_0_i_7_r_3_t_2_cnt, S1MMEtore::msg_sm_0_i_7_r_3_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_7_r_3_t_3_busy, S1MMEtore::msg_sm_0_i_7_r_3_t_3_cnt, S1MMEtore::msg_sm_0_i_7_r_3_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_7_r_3_t_4_busy, S1MMEtore::msg_sm_0_i_7_r_3_t_4_cnt, S1MMEtore::msg_sm_0_i_7_r_3_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_7_r_3_t_5_busy, S1MMEtore::msg_sm_0_i_7_r_3_t_5_cnt, S1MMEtore::msg_sm_0_i_7_r_3_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_7_r_3_t_6_busy, S1MMEtore::msg_sm_0_i_7_r_3_t_6_cnt, S1MMEtore::msg_sm_0_i_7_r_3_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_7_r_3_t_7_busy, S1MMEtore::msg_sm_0_i_7_r_3_t_7_cnt, S1MMEtore::msg_sm_0_i_7_r_3_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_7_r_3_t_8_busy, S1MMEtore::msg_sm_0_i_7_r_3_t_8_cnt, S1MMEtore::msg_sm_0_i_7_r_3_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_7_r_3_t_9_busy, S1MMEtore::msg_sm_0_i_7_r_3_t_9_cnt, S1MMEtore::msg_sm_0_i_7_r_3_t_9, pSctp);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_7_r_3_t_0_busy, S1MMEtore::msg_sm_1_i_7_r_3_t_0_cnt, S1MMEtore::msg_sm_1_i_7_r_3_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_7_r_3_t_1_busy, S1MMEtore::msg_sm_1_i_7_r_3_t_1_cnt, S1MMEtore::msg_sm_1_i_7_r_3_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_7_r_3_t_2_busy, S1MMEtore::msg_sm_1_i_7_r_3_t_2_cnt, S1MMEtore::msg_sm_1_i_7_r_3_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_7_r_3_t_3_busy, S1MMEtore::msg_sm_1_i_7_r_3_t_3_cnt, S1MMEtore::msg_sm_1_i_7_r_3_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_7_r_3_t_4_busy, S1MMEtore::msg_sm_1_i_7_r_3_t_4_cnt, S1MMEtore::msg_sm_1_i_7_r_3_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_7_r_3_t_5_busy, S1MMEtore::msg_sm_1_i_7_r_3_t_5_cnt, S1MMEtore::msg_sm_1_i_7_r_3_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_7_r_3_t_6_busy, S1MMEtore::msg_sm_1_i_7_r_3_t_6_cnt, S1MMEtore::msg_sm_1_i_7_r_3_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_7_r_3_t_7_busy, S1MMEtore::msg_sm_1_i_7_r_3_t_7_cnt, S1MMEtore::msg_sm_1_i_7_r_3_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_7_r_3_t_8_busy, S1MMEtore::msg_sm_1_i_7_r_3_t_8_cnt, S1MMEtore::msg_sm_1_i_7_r_3_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_7_r_3_t_9_busy, S1MMEtore::msg_sm_1_i_7_r_3_t_9_cnt, S1MMEtore::msg_sm_1_i_7_r_3_t_9, pSctp);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_7_r_3_t_0_busy, S1MMEtore::msg_sm_2_i_7_r_3_t_0_cnt, S1MMEtore::msg_sm_2_i_7_r_3_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_7_r_3_t_1_busy, S1MMEtore::msg_sm_2_i_7_r_3_t_1_cnt, S1MMEtore::msg_sm_2_i_7_r_3_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_7_r_3_t_2_busy, S1MMEtore::msg_sm_2_i_7_r_3_t_2_cnt, S1MMEtore::msg_sm_2_i_7_r_3_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_7_r_3_t_3_busy, S1MMEtore::msg_sm_2_i_7_r_3_t_3_cnt, S1MMEtore::msg_sm_2_i_7_r_3_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_7_r_3_t_4_busy, S1MMEtore::msg_sm_2_i_7_r_3_t_4_cnt, S1MMEtore::msg_sm_2_i_7_r_3_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_7_r_3_t_5_busy, S1MMEtore::msg_sm_2_i_7_r_3_t_5_cnt, S1MMEtore::msg_sm_2_i_7_r_3_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_7_r_3_t_6_busy, S1MMEtore::msg_sm_2_i_7_r_3_t_6_cnt, S1MMEtore::msg_sm_2_i_7_r_3_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_7_r_3_t_7_busy, S1MMEtore::msg_sm_2_i_7_r_3_t_7_cnt, S1MMEtore::msg_sm_2_i_7_r_3_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_7_r_3_t_8_busy, S1MMEtore::msg_sm_2_i_7_r_3_t_8_cnt, S1MMEtore::msg_sm_2_i_7_r_3_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_7_r_3_t_9_busy, S1MMEtore::msg_sm_2_i_7_r_3_t_9_cnt, S1MMEtore::msg_sm_2_i_7_r_3_t_9, pSctp);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_7_r_3_t_0_busy, S1MMEtore::msg_sm_3_i_7_r_3_t_0_cnt, S1MMEtore::msg_sm_3_i_7_r_3_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_7_r_3_t_1_busy, S1MMEtore::msg_sm_3_i_7_r_3_t_1_cnt, S1MMEtore::msg_sm_3_i_7_r_3_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_7_r_3_t_2_busy, S1MMEtore::msg_sm_3_i_7_r_3_t_2_cnt, S1MMEtore::msg_sm_3_i_7_r_3_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_7_r_3_t_3_busy, S1MMEtore::msg_sm_3_i_7_r_3_t_3_cnt, S1MMEtore::msg_sm_3_i_7_r_3_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_7_r_3_t_4_busy, S1MMEtore::msg_sm_3_i_7_r_3_t_4_cnt, S1MMEtore::msg_sm_3_i_7_r_3_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_7_r_3_t_5_busy, S1MMEtore::msg_sm_3_i_7_r_3_t_5_cnt, S1MMEtore::msg_sm_3_i_7_r_3_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_7_r_3_t_6_busy, S1MMEtore::msg_sm_3_i_7_r_3_t_6_cnt, S1MMEtore::msg_sm_3_i_7_r_3_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_7_r_3_t_7_busy, S1MMEtore::msg_sm_3_i_7_r_3_t_7_cnt, S1MMEtore::msg_sm_3_i_7_r_3_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_7_r_3_t_8_busy, S1MMEtore::msg_sm_3_i_7_r_3_t_8_cnt, S1MMEtore::msg_sm_3_i_7_r_3_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_7_r_3_t_9_busy, S1MMEtore::msg_sm_3_i_7_r_3_t_9_cnt, S1MMEtore::msg_sm_3_i_7_r_3_t_9, pSctp);
				break;
			}
			break;
	}
}

VOID SctpMessageBroker::pushToQueue_i_7_r_4(Sctp *pSctp, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_7_r_4_t_0_busy, S1MMEtore::msg_sm_0_i_7_r_4_t_0_cnt, S1MMEtore::msg_sm_0_i_7_r_4_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_7_r_4_t_1_busy, S1MMEtore::msg_sm_0_i_7_r_4_t_1_cnt, S1MMEtore::msg_sm_0_i_7_r_4_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_7_r_4_t_2_busy, S1MMEtore::msg_sm_0_i_7_r_4_t_2_cnt, S1MMEtore::msg_sm_0_i_7_r_4_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_7_r_4_t_3_busy, S1MMEtore::msg_sm_0_i_7_r_4_t_3_cnt, S1MMEtore::msg_sm_0_i_7_r_4_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_7_r_4_t_4_busy, S1MMEtore::msg_sm_0_i_7_r_4_t_4_cnt, S1MMEtore::msg_sm_0_i_7_r_4_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_7_r_4_t_5_busy, S1MMEtore::msg_sm_0_i_7_r_4_t_5_cnt, S1MMEtore::msg_sm_0_i_7_r_4_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_7_r_4_t_6_busy, S1MMEtore::msg_sm_0_i_7_r_4_t_6_cnt, S1MMEtore::msg_sm_0_i_7_r_4_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_7_r_4_t_7_busy, S1MMEtore::msg_sm_0_i_7_r_4_t_7_cnt, S1MMEtore::msg_sm_0_i_7_r_4_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_7_r_4_t_8_busy, S1MMEtore::msg_sm_0_i_7_r_4_t_8_cnt, S1MMEtore::msg_sm_0_i_7_r_4_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_7_r_4_t_9_busy, S1MMEtore::msg_sm_0_i_7_r_4_t_9_cnt, S1MMEtore::msg_sm_0_i_7_r_4_t_9, pSctp);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_7_r_4_t_0_busy, S1MMEtore::msg_sm_1_i_7_r_4_t_0_cnt, S1MMEtore::msg_sm_1_i_7_r_4_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_7_r_4_t_1_busy, S1MMEtore::msg_sm_1_i_7_r_4_t_1_cnt, S1MMEtore::msg_sm_1_i_7_r_4_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_7_r_4_t_2_busy, S1MMEtore::msg_sm_1_i_7_r_4_t_2_cnt, S1MMEtore::msg_sm_1_i_7_r_4_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_7_r_4_t_3_busy, S1MMEtore::msg_sm_1_i_7_r_4_t_3_cnt, S1MMEtore::msg_sm_1_i_7_r_4_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_7_r_4_t_4_busy, S1MMEtore::msg_sm_1_i_7_r_4_t_4_cnt, S1MMEtore::msg_sm_1_i_7_r_4_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_7_r_4_t_5_busy, S1MMEtore::msg_sm_1_i_7_r_4_t_5_cnt, S1MMEtore::msg_sm_1_i_7_r_4_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_7_r_4_t_6_busy, S1MMEtore::msg_sm_1_i_7_r_4_t_6_cnt, S1MMEtore::msg_sm_1_i_7_r_4_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_7_r_4_t_7_busy, S1MMEtore::msg_sm_1_i_7_r_4_t_7_cnt, S1MMEtore::msg_sm_1_i_7_r_4_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_7_r_4_t_8_busy, S1MMEtore::msg_sm_1_i_7_r_4_t_8_cnt, S1MMEtore::msg_sm_1_i_7_r_4_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_7_r_4_t_9_busy, S1MMEtore::msg_sm_1_i_7_r_4_t_9_cnt, S1MMEtore::msg_sm_1_i_7_r_4_t_9, pSctp);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_7_r_4_t_0_busy, S1MMEtore::msg_sm_2_i_7_r_4_t_0_cnt, S1MMEtore::msg_sm_2_i_7_r_4_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_7_r_4_t_1_busy, S1MMEtore::msg_sm_2_i_7_r_4_t_1_cnt, S1MMEtore::msg_sm_2_i_7_r_4_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_7_r_4_t_2_busy, S1MMEtore::msg_sm_2_i_7_r_4_t_2_cnt, S1MMEtore::msg_sm_2_i_7_r_4_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_7_r_4_t_3_busy, S1MMEtore::msg_sm_2_i_7_r_4_t_3_cnt, S1MMEtore::msg_sm_2_i_7_r_4_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_7_r_4_t_4_busy, S1MMEtore::msg_sm_2_i_7_r_4_t_4_cnt, S1MMEtore::msg_sm_2_i_7_r_4_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_7_r_4_t_5_busy, S1MMEtore::msg_sm_2_i_7_r_4_t_5_cnt, S1MMEtore::msg_sm_2_i_7_r_4_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_7_r_4_t_6_busy, S1MMEtore::msg_sm_2_i_7_r_4_t_6_cnt, S1MMEtore::msg_sm_2_i_7_r_4_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_7_r_4_t_7_busy, S1MMEtore::msg_sm_2_i_7_r_4_t_7_cnt, S1MMEtore::msg_sm_2_i_7_r_4_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_7_r_4_t_8_busy, S1MMEtore::msg_sm_2_i_7_r_4_t_8_cnt, S1MMEtore::msg_sm_2_i_7_r_4_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_7_r_4_t_9_busy, S1MMEtore::msg_sm_2_i_7_r_4_t_9_cnt, S1MMEtore::msg_sm_2_i_7_r_4_t_9, pSctp);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_7_r_4_t_0_busy, S1MMEtore::msg_sm_3_i_7_r_4_t_0_cnt, S1MMEtore::msg_sm_3_i_7_r_4_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_7_r_4_t_1_busy, S1MMEtore::msg_sm_3_i_7_r_4_t_1_cnt, S1MMEtore::msg_sm_3_i_7_r_4_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_7_r_4_t_2_busy, S1MMEtore::msg_sm_3_i_7_r_4_t_2_cnt, S1MMEtore::msg_sm_3_i_7_r_4_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_7_r_4_t_3_busy, S1MMEtore::msg_sm_3_i_7_r_4_t_3_cnt, S1MMEtore::msg_sm_3_i_7_r_4_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_7_r_4_t_4_busy, S1MMEtore::msg_sm_3_i_7_r_4_t_4_cnt, S1MMEtore::msg_sm_3_i_7_r_4_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_7_r_4_t_5_busy, S1MMEtore::msg_sm_3_i_7_r_4_t_5_cnt, S1MMEtore::msg_sm_3_i_7_r_4_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_7_r_4_t_6_busy, S1MMEtore::msg_sm_3_i_7_r_4_t_6_cnt, S1MMEtore::msg_sm_3_i_7_r_4_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_7_r_4_t_7_busy, S1MMEtore::msg_sm_3_i_7_r_4_t_7_cnt, S1MMEtore::msg_sm_3_i_7_r_4_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_7_r_4_t_8_busy, S1MMEtore::msg_sm_3_i_7_r_4_t_8_cnt, S1MMEtore::msg_sm_3_i_7_r_4_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_7_r_4_t_9_busy, S1MMEtore::msg_sm_3_i_7_r_4_t_9_cnt, S1MMEtore::msg_sm_3_i_7_r_4_t_9, pSctp);
				break;
			}
			break;
	}
}

VOID SctpMessageBroker::pushToQueue_i_7_r_5(Sctp *pSctp, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_7_r_5_t_0_busy, S1MMEtore::msg_sm_0_i_7_r_5_t_0_cnt, S1MMEtore::msg_sm_0_i_7_r_5_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_7_r_5_t_1_busy, S1MMEtore::msg_sm_0_i_7_r_5_t_1_cnt, S1MMEtore::msg_sm_0_i_7_r_5_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_7_r_5_t_2_busy, S1MMEtore::msg_sm_0_i_7_r_5_t_2_cnt, S1MMEtore::msg_sm_0_i_7_r_5_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_7_r_5_t_3_busy, S1MMEtore::msg_sm_0_i_7_r_5_t_3_cnt, S1MMEtore::msg_sm_0_i_7_r_5_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_7_r_5_t_4_busy, S1MMEtore::msg_sm_0_i_7_r_5_t_4_cnt, S1MMEtore::msg_sm_0_i_7_r_5_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_7_r_5_t_5_busy, S1MMEtore::msg_sm_0_i_7_r_5_t_5_cnt, S1MMEtore::msg_sm_0_i_7_r_5_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_7_r_5_t_6_busy, S1MMEtore::msg_sm_0_i_7_r_5_t_6_cnt, S1MMEtore::msg_sm_0_i_7_r_5_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_7_r_5_t_7_busy, S1MMEtore::msg_sm_0_i_7_r_5_t_7_cnt, S1MMEtore::msg_sm_0_i_7_r_5_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_7_r_5_t_8_busy, S1MMEtore::msg_sm_0_i_7_r_5_t_8_cnt, S1MMEtore::msg_sm_0_i_7_r_5_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_7_r_5_t_9_busy, S1MMEtore::msg_sm_0_i_7_r_5_t_9_cnt, S1MMEtore::msg_sm_0_i_7_r_5_t_9, pSctp);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_7_r_5_t_0_busy, S1MMEtore::msg_sm_1_i_7_r_5_t_0_cnt, S1MMEtore::msg_sm_1_i_7_r_5_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_7_r_5_t_1_busy, S1MMEtore::msg_sm_1_i_7_r_5_t_1_cnt, S1MMEtore::msg_sm_1_i_7_r_5_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_7_r_5_t_2_busy, S1MMEtore::msg_sm_1_i_7_r_5_t_2_cnt, S1MMEtore::msg_sm_1_i_7_r_5_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_7_r_5_t_3_busy, S1MMEtore::msg_sm_1_i_7_r_5_t_3_cnt, S1MMEtore::msg_sm_1_i_7_r_5_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_7_r_5_t_4_busy, S1MMEtore::msg_sm_1_i_7_r_5_t_4_cnt, S1MMEtore::msg_sm_1_i_7_r_5_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_7_r_5_t_5_busy, S1MMEtore::msg_sm_1_i_7_r_5_t_5_cnt, S1MMEtore::msg_sm_1_i_7_r_5_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_7_r_5_t_6_busy, S1MMEtore::msg_sm_1_i_7_r_5_t_6_cnt, S1MMEtore::msg_sm_1_i_7_r_5_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_7_r_5_t_7_busy, S1MMEtore::msg_sm_1_i_7_r_5_t_7_cnt, S1MMEtore::msg_sm_1_i_7_r_5_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_7_r_5_t_8_busy, S1MMEtore::msg_sm_1_i_7_r_5_t_8_cnt, S1MMEtore::msg_sm_1_i_7_r_5_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_7_r_5_t_9_busy, S1MMEtore::msg_sm_1_i_7_r_5_t_9_cnt, S1MMEtore::msg_sm_1_i_7_r_5_t_9, pSctp);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_7_r_5_t_0_busy, S1MMEtore::msg_sm_2_i_7_r_5_t_0_cnt, S1MMEtore::msg_sm_2_i_7_r_5_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_7_r_5_t_1_busy, S1MMEtore::msg_sm_2_i_7_r_5_t_1_cnt, S1MMEtore::msg_sm_2_i_7_r_5_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_7_r_5_t_2_busy, S1MMEtore::msg_sm_2_i_7_r_5_t_2_cnt, S1MMEtore::msg_sm_2_i_7_r_5_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_7_r_5_t_3_busy, S1MMEtore::msg_sm_2_i_7_r_5_t_3_cnt, S1MMEtore::msg_sm_2_i_7_r_5_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_7_r_5_t_4_busy, S1MMEtore::msg_sm_2_i_7_r_5_t_4_cnt, S1MMEtore::msg_sm_2_i_7_r_5_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_7_r_5_t_5_busy, S1MMEtore::msg_sm_2_i_7_r_5_t_5_cnt, S1MMEtore::msg_sm_2_i_7_r_5_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_7_r_5_t_6_busy, S1MMEtore::msg_sm_2_i_7_r_5_t_6_cnt, S1MMEtore::msg_sm_2_i_7_r_5_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_7_r_5_t_7_busy, S1MMEtore::msg_sm_2_i_7_r_5_t_7_cnt, S1MMEtore::msg_sm_2_i_7_r_5_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_7_r_5_t_8_busy, S1MMEtore::msg_sm_2_i_7_r_5_t_8_cnt, S1MMEtore::msg_sm_2_i_7_r_5_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_7_r_5_t_9_busy, S1MMEtore::msg_sm_2_i_7_r_5_t_9_cnt, S1MMEtore::msg_sm_2_i_7_r_5_t_9, pSctp);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_7_r_5_t_0_busy, S1MMEtore::msg_sm_3_i_7_r_5_t_0_cnt, S1MMEtore::msg_sm_3_i_7_r_5_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_7_r_5_t_1_busy, S1MMEtore::msg_sm_3_i_7_r_5_t_1_cnt, S1MMEtore::msg_sm_3_i_7_r_5_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_7_r_5_t_2_busy, S1MMEtore::msg_sm_3_i_7_r_5_t_2_cnt, S1MMEtore::msg_sm_3_i_7_r_5_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_7_r_5_t_3_busy, S1MMEtore::msg_sm_3_i_7_r_5_t_3_cnt, S1MMEtore::msg_sm_3_i_7_r_5_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_7_r_5_t_4_busy, S1MMEtore::msg_sm_3_i_7_r_5_t_4_cnt, S1MMEtore::msg_sm_3_i_7_r_5_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_7_r_5_t_5_busy, S1MMEtore::msg_sm_3_i_7_r_5_t_5_cnt, S1MMEtore::msg_sm_3_i_7_r_5_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_7_r_5_t_6_busy, S1MMEtore::msg_sm_3_i_7_r_5_t_6_cnt, S1MMEtore::msg_sm_3_i_7_r_5_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_7_r_5_t_7_busy, S1MMEtore::msg_sm_3_i_7_r_5_t_7_cnt, S1MMEtore::msg_sm_3_i_7_r_5_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_7_r_5_t_8_busy, S1MMEtore::msg_sm_3_i_7_r_5_t_8_cnt, S1MMEtore::msg_sm_3_i_7_r_5_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_7_r_5_t_9_busy, S1MMEtore::msg_sm_3_i_7_r_5_t_9_cnt, S1MMEtore::msg_sm_3_i_7_r_5_t_9, pSctp);
				break;
			}
			break;
	}
}

VOID SctpMessageBroker::pushToQueue_i_7_r_6(Sctp *pSctp, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_7_r_6_t_0_busy, S1MMEtore::msg_sm_0_i_7_r_6_t_0_cnt, S1MMEtore::msg_sm_0_i_7_r_6_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_7_r_6_t_1_busy, S1MMEtore::msg_sm_0_i_7_r_6_t_1_cnt, S1MMEtore::msg_sm_0_i_7_r_6_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_7_r_6_t_2_busy, S1MMEtore::msg_sm_0_i_7_r_6_t_2_cnt, S1MMEtore::msg_sm_0_i_7_r_6_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_7_r_6_t_3_busy, S1MMEtore::msg_sm_0_i_7_r_6_t_3_cnt, S1MMEtore::msg_sm_0_i_7_r_6_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_7_r_6_t_4_busy, S1MMEtore::msg_sm_0_i_7_r_6_t_4_cnt, S1MMEtore::msg_sm_0_i_7_r_6_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_7_r_6_t_5_busy, S1MMEtore::msg_sm_0_i_7_r_6_t_5_cnt, S1MMEtore::msg_sm_0_i_7_r_6_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_7_r_6_t_6_busy, S1MMEtore::msg_sm_0_i_7_r_6_t_6_cnt, S1MMEtore::msg_sm_0_i_7_r_6_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_7_r_6_t_7_busy, S1MMEtore::msg_sm_0_i_7_r_6_t_7_cnt, S1MMEtore::msg_sm_0_i_7_r_6_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_7_r_6_t_8_busy, S1MMEtore::msg_sm_0_i_7_r_6_t_8_cnt, S1MMEtore::msg_sm_0_i_7_r_6_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_7_r_6_t_9_busy, S1MMEtore::msg_sm_0_i_7_r_6_t_9_cnt, S1MMEtore::msg_sm_0_i_7_r_6_t_9, pSctp);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_7_r_6_t_0_busy, S1MMEtore::msg_sm_1_i_7_r_6_t_0_cnt, S1MMEtore::msg_sm_1_i_7_r_6_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_7_r_6_t_1_busy, S1MMEtore::msg_sm_1_i_7_r_6_t_1_cnt, S1MMEtore::msg_sm_1_i_7_r_6_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_7_r_6_t_2_busy, S1MMEtore::msg_sm_1_i_7_r_6_t_2_cnt, S1MMEtore::msg_sm_1_i_7_r_6_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_7_r_6_t_3_busy, S1MMEtore::msg_sm_1_i_7_r_6_t_3_cnt, S1MMEtore::msg_sm_1_i_7_r_6_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_7_r_6_t_4_busy, S1MMEtore::msg_sm_1_i_7_r_6_t_4_cnt, S1MMEtore::msg_sm_1_i_7_r_6_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_7_r_6_t_5_busy, S1MMEtore::msg_sm_1_i_7_r_6_t_5_cnt, S1MMEtore::msg_sm_1_i_7_r_6_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_7_r_6_t_6_busy, S1MMEtore::msg_sm_1_i_7_r_6_t_6_cnt, S1MMEtore::msg_sm_1_i_7_r_6_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_7_r_6_t_7_busy, S1MMEtore::msg_sm_1_i_7_r_6_t_7_cnt, S1MMEtore::msg_sm_1_i_7_r_6_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_7_r_6_t_8_busy, S1MMEtore::msg_sm_1_i_7_r_6_t_8_cnt, S1MMEtore::msg_sm_1_i_7_r_6_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_7_r_6_t_9_busy, S1MMEtore::msg_sm_1_i_7_r_6_t_9_cnt, S1MMEtore::msg_sm_1_i_7_r_6_t_9, pSctp);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_7_r_6_t_0_busy, S1MMEtore::msg_sm_2_i_7_r_6_t_0_cnt, S1MMEtore::msg_sm_2_i_7_r_6_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_7_r_6_t_1_busy, S1MMEtore::msg_sm_2_i_7_r_6_t_1_cnt, S1MMEtore::msg_sm_2_i_7_r_6_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_7_r_6_t_2_busy, S1MMEtore::msg_sm_2_i_7_r_6_t_2_cnt, S1MMEtore::msg_sm_2_i_7_r_6_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_7_r_6_t_3_busy, S1MMEtore::msg_sm_2_i_7_r_6_t_3_cnt, S1MMEtore::msg_sm_2_i_7_r_6_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_7_r_6_t_4_busy, S1MMEtore::msg_sm_2_i_7_r_6_t_4_cnt, S1MMEtore::msg_sm_2_i_7_r_6_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_7_r_6_t_5_busy, S1MMEtore::msg_sm_2_i_7_r_6_t_5_cnt, S1MMEtore::msg_sm_2_i_7_r_6_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_7_r_6_t_6_busy, S1MMEtore::msg_sm_2_i_7_r_6_t_6_cnt, S1MMEtore::msg_sm_2_i_7_r_6_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_7_r_6_t_7_busy, S1MMEtore::msg_sm_2_i_7_r_6_t_7_cnt, S1MMEtore::msg_sm_2_i_7_r_6_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_7_r_6_t_8_busy, S1MMEtore::msg_sm_2_i_7_r_6_t_8_cnt, S1MMEtore::msg_sm_2_i_7_r_6_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_7_r_6_t_9_busy, S1MMEtore::msg_sm_2_i_7_r_6_t_9_cnt, S1MMEtore::msg_sm_2_i_7_r_6_t_9, pSctp);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_7_r_6_t_0_busy, S1MMEtore::msg_sm_3_i_7_r_6_t_0_cnt, S1MMEtore::msg_sm_3_i_7_r_6_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_7_r_6_t_1_busy, S1MMEtore::msg_sm_3_i_7_r_6_t_1_cnt, S1MMEtore::msg_sm_3_i_7_r_6_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_7_r_6_t_2_busy, S1MMEtore::msg_sm_3_i_7_r_6_t_2_cnt, S1MMEtore::msg_sm_3_i_7_r_6_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_7_r_6_t_3_busy, S1MMEtore::msg_sm_3_i_7_r_6_t_3_cnt, S1MMEtore::msg_sm_3_i_7_r_6_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_7_r_6_t_4_busy, S1MMEtore::msg_sm_3_i_7_r_6_t_4_cnt, S1MMEtore::msg_sm_3_i_7_r_6_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_7_r_6_t_5_busy, S1MMEtore::msg_sm_3_i_7_r_6_t_5_cnt, S1MMEtore::msg_sm_3_i_7_r_6_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_7_r_6_t_6_busy, S1MMEtore::msg_sm_3_i_7_r_6_t_6_cnt, S1MMEtore::msg_sm_3_i_7_r_6_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_7_r_6_t_7_busy, S1MMEtore::msg_sm_3_i_7_r_6_t_7_cnt, S1MMEtore::msg_sm_3_i_7_r_6_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_7_r_6_t_8_busy, S1MMEtore::msg_sm_3_i_7_r_6_t_8_cnt, S1MMEtore::msg_sm_3_i_7_r_6_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_7_r_6_t_9_busy, S1MMEtore::msg_sm_3_i_7_r_6_t_9_cnt, S1MMEtore::msg_sm_3_i_7_r_6_t_9, pSctp);
				break;
			}
			break;
	}
}

VOID SctpMessageBroker::pushToQueue_i_7_r_7(Sctp *pSctp, int smId, int idx)
{
	switch(smId)
	{
		case 0:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_7_r_7_t_0_busy, S1MMEtore::msg_sm_0_i_7_r_7_t_0_cnt, S1MMEtore::msg_sm_0_i_7_r_7_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_7_r_7_t_1_busy, S1MMEtore::msg_sm_0_i_7_r_7_t_1_cnt, S1MMEtore::msg_sm_0_i_7_r_7_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_7_r_7_t_2_busy, S1MMEtore::msg_sm_0_i_7_r_7_t_2_cnt, S1MMEtore::msg_sm_0_i_7_r_7_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_7_r_7_t_3_busy, S1MMEtore::msg_sm_0_i_7_r_7_t_3_cnt, S1MMEtore::msg_sm_0_i_7_r_7_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_7_r_7_t_4_busy, S1MMEtore::msg_sm_0_i_7_r_7_t_4_cnt, S1MMEtore::msg_sm_0_i_7_r_7_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_7_r_7_t_5_busy, S1MMEtore::msg_sm_0_i_7_r_7_t_5_cnt, S1MMEtore::msg_sm_0_i_7_r_7_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_7_r_7_t_6_busy, S1MMEtore::msg_sm_0_i_7_r_7_t_6_cnt, S1MMEtore::msg_sm_0_i_7_r_7_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_7_r_7_t_7_busy, S1MMEtore::msg_sm_0_i_7_r_7_t_7_cnt, S1MMEtore::msg_sm_0_i_7_r_7_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_7_r_7_t_8_busy, S1MMEtore::msg_sm_0_i_7_r_7_t_8_cnt, S1MMEtore::msg_sm_0_i_7_r_7_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_0_i_7_r_7_t_9_busy, S1MMEtore::msg_sm_0_i_7_r_7_t_9_cnt, S1MMEtore::msg_sm_0_i_7_r_7_t_9, pSctp);
				break;
			}
			break;

		case 1:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_7_r_7_t_0_busy, S1MMEtore::msg_sm_1_i_7_r_7_t_0_cnt, S1MMEtore::msg_sm_1_i_7_r_7_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_7_r_7_t_1_busy, S1MMEtore::msg_sm_1_i_7_r_7_t_1_cnt, S1MMEtore::msg_sm_1_i_7_r_7_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_7_r_7_t_2_busy, S1MMEtore::msg_sm_1_i_7_r_7_t_2_cnt, S1MMEtore::msg_sm_1_i_7_r_7_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_7_r_7_t_3_busy, S1MMEtore::msg_sm_1_i_7_r_7_t_3_cnt, S1MMEtore::msg_sm_1_i_7_r_7_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_7_r_7_t_4_busy, S1MMEtore::msg_sm_1_i_7_r_7_t_4_cnt, S1MMEtore::msg_sm_1_i_7_r_7_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_7_r_7_t_5_busy, S1MMEtore::msg_sm_1_i_7_r_7_t_5_cnt, S1MMEtore::msg_sm_1_i_7_r_7_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_7_r_7_t_6_busy, S1MMEtore::msg_sm_1_i_7_r_7_t_6_cnt, S1MMEtore::msg_sm_1_i_7_r_7_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_7_r_7_t_7_busy, S1MMEtore::msg_sm_1_i_7_r_7_t_7_cnt, S1MMEtore::msg_sm_1_i_7_r_7_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_7_r_7_t_8_busy, S1MMEtore::msg_sm_1_i_7_r_7_t_8_cnt, S1MMEtore::msg_sm_1_i_7_r_7_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_1_i_7_r_7_t_9_busy, S1MMEtore::msg_sm_1_i_7_r_7_t_9_cnt, S1MMEtore::msg_sm_1_i_7_r_7_t_9, pSctp);
				break;
			}
			break;

		case 2:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_7_r_7_t_0_busy, S1MMEtore::msg_sm_2_i_7_r_7_t_0_cnt, S1MMEtore::msg_sm_2_i_7_r_7_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_7_r_7_t_1_busy, S1MMEtore::msg_sm_2_i_7_r_7_t_1_cnt, S1MMEtore::msg_sm_2_i_7_r_7_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_7_r_7_t_2_busy, S1MMEtore::msg_sm_2_i_7_r_7_t_2_cnt, S1MMEtore::msg_sm_2_i_7_r_7_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_7_r_7_t_3_busy, S1MMEtore::msg_sm_2_i_7_r_7_t_3_cnt, S1MMEtore::msg_sm_2_i_7_r_7_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_7_r_7_t_4_busy, S1MMEtore::msg_sm_2_i_7_r_7_t_4_cnt, S1MMEtore::msg_sm_2_i_7_r_7_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_7_r_7_t_5_busy, S1MMEtore::msg_sm_2_i_7_r_7_t_5_cnt, S1MMEtore::msg_sm_2_i_7_r_7_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_7_r_7_t_6_busy, S1MMEtore::msg_sm_2_i_7_r_7_t_6_cnt, S1MMEtore::msg_sm_2_i_7_r_7_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_7_r_7_t_7_busy, S1MMEtore::msg_sm_2_i_7_r_7_t_7_cnt, S1MMEtore::msg_sm_2_i_7_r_7_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_7_r_7_t_8_busy, S1MMEtore::msg_sm_2_i_7_r_7_t_8_cnt, S1MMEtore::msg_sm_2_i_7_r_7_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_2_i_7_r_7_t_9_busy, S1MMEtore::msg_sm_2_i_7_r_7_t_9_cnt, S1MMEtore::msg_sm_2_i_7_r_7_t_9, pSctp);
				break;
			}
			break;

		case 3:
			switch(idx)
			{
			case 0:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_7_r_7_t_0_busy, S1MMEtore::msg_sm_3_i_7_r_7_t_0_cnt, S1MMEtore::msg_sm_3_i_7_r_7_t_0, pSctp);
				break;
			case 1:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_7_r_7_t_1_busy, S1MMEtore::msg_sm_3_i_7_r_7_t_1_cnt, S1MMEtore::msg_sm_3_i_7_r_7_t_1, pSctp);
				break;
			case 2:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_7_r_7_t_2_busy, S1MMEtore::msg_sm_3_i_7_r_7_t_2_cnt, S1MMEtore::msg_sm_3_i_7_r_7_t_2, pSctp);
				break;
			case 3:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_7_r_7_t_3_busy, S1MMEtore::msg_sm_3_i_7_r_7_t_3_cnt, S1MMEtore::msg_sm_3_i_7_r_7_t_3, pSctp);
				break;
			case 4:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_7_r_7_t_4_busy, S1MMEtore::msg_sm_3_i_7_r_7_t_4_cnt, S1MMEtore::msg_sm_3_i_7_r_7_t_4, pSctp);
				break;
			case 5:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_7_r_7_t_5_busy, S1MMEtore::msg_sm_3_i_7_r_7_t_5_cnt, S1MMEtore::msg_sm_3_i_7_r_7_t_5, pSctp);
				break;
			case 6:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_7_r_7_t_6_busy, S1MMEtore::msg_sm_3_i_7_r_7_t_6_cnt, S1MMEtore::msg_sm_3_i_7_r_7_t_6, pSctp);
				break;
			case 7:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_7_r_7_t_7_busy, S1MMEtore::msg_sm_3_i_7_r_7_t_7_cnt, S1MMEtore::msg_sm_3_i_7_r_7_t_7, pSctp);
				break;
			case 8:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_7_r_7_t_8_busy, S1MMEtore::msg_sm_3_i_7_r_7_t_8_cnt, S1MMEtore::msg_sm_3_i_7_r_7_t_8, pSctp);
				break;
			case 9:
				copySctpMsgObj(S1MMEtore::msg_sm_3_i_7_r_7_t_9_busy, S1MMEtore::msg_sm_3_i_7_r_7_t_9_cnt, S1MMEtore::msg_sm_3_i_7_r_7_t_9, pSctp);
				break;
			}
			break;
	}
}


VOID SctpMessageBroker::copySctpMsgObj(bool &msg_sm_busy, int &msg_sm_cnt, std::unordered_map<int, Sctp> &msg_sm, Sctp *sctpObj)
{
	if(msg_sm_busy) return;

	msg_sm[msg_sm_cnt].copy(sctpObj);
	msg_sm_cnt++;
}
