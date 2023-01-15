/*
 * PacketRouter.h
 *
 *  Created on: Nov 22, 2016
 *      Author: Debashis
 */

#ifndef CORE_SRC_PACKETROUTER_H_
#define CORE_SRC_PACKETROUTER_H_

#include <unistd.h>
#include <time.h>
#include <sys/time.h>

#include "SctpMessageBroker.h"
#include "SpectaTypedef.h"
#include "BWData.h"
#include "EthernetParser.h"
#include "BaseConfig.h"
#include "IPGlobal.h"
#include "Log.h"
#include "S11MessageBroker.h"
#include "S5S8MessageBroker.h"
#include "S1UMessageBroker.h"

struct pcapPkthdr {
	uint32_t tv_sec;
	uint32_t tv_usec;
	uint32_t caplen;
	uint32_t len;
};

class PacketRouter : public BaseConfig {
	public:

		PacketRouter(int intfid, int rid, int totrouters, int coreid);
		~PacketRouter();

		bool isRepositoryInitialized();

		VOID run();

	private:
		int interfaceId = 0;
		int routerId = 0;
		int routerTotal = 0;
		int coreId = 0;

		bool mem_init = true;

		timeval curTime;
		bool 	dayChanged = false;
		int		curMin = 0;
		int 	prevMin = 0;
		int 	curHour = 0;
		int 	prevHour = 0;

		uint64_t	bufferWriteEpocSec = 0;
		int printCnt = 0;

		int MAX_PKT_LEN;
		BOOL repoInitStatus = false;

		MPacket *msgObj;
		RawPkt *rawPkt;

		FILE *ptr_myfile;
		char fileName[100];
		bool pcapFileOpenFlag = false;

		BWData 				*bwData;
		EthernetParser 		*ethParser;
#ifdef _S1MME
		SctpMessageBroker		*sctpMsgBroker;
#endif
#ifdef _S11
		S11MessageBroker		*s11MsgBroker;
		S5S8MessageBroker		*s5s8MsgBroker;
#endif
#ifdef _S1U
		S1UMessageBroker		*s1uMsgBroker;
#endif
		char * ByteToString(const void* pv, int len);
		int getCurrentSec();

		VOID processQueue(int t_index);

		VOID processQueueDecode(bool &pktRepository_busy, long &pktRepository_cnt, std::unordered_map<long, RawPkt*> &pktRepository);

		VOID processQueue_i_0(int t_index);
		VOID processQueue_i_1(int t_index);
		VOID processQueue_i_2(int t_index);
		VOID processQueue_i_3(int t_index);
		VOID processQueue_i_4(int t_index);
		VOID processQueue_i_5(int t_index);
		VOID processQueue_i_6(int t_index);
		VOID processQueue_i_7(int t_index);

		VOID processQueue_i_0_r_0(int t_index);
		VOID processQueue_i_0_r_1(int t_index);
		VOID processQueue_i_0_r_2(int t_index);
		VOID processQueue_i_0_r_3(int t_index);
		VOID processQueue_i_0_r_4(int t_index);
		VOID processQueue_i_0_r_5(int t_index);
		VOID processQueue_i_0_r_6(int t_index);
		VOID processQueue_i_0_r_7(int t_index);

		VOID processQueue_i_1_r_0(int t_index);
		VOID processQueue_i_1_r_1(int t_index);
		VOID processQueue_i_1_r_2(int t_index);
		VOID processQueue_i_1_r_3(int t_index);
		VOID processQueue_i_1_r_4(int t_index);
		VOID processQueue_i_1_r_5(int t_index);
		VOID processQueue_i_1_r_6(int t_index);
		VOID processQueue_i_1_r_7(int t_index);

		VOID processQueue_i_2_r_0(int t_index);
		VOID processQueue_i_2_r_1(int t_index);
		VOID processQueue_i_2_r_2(int t_index);
		VOID processQueue_i_2_r_3(int t_index);
		VOID processQueue_i_2_r_4(int t_index);
		VOID processQueue_i_2_r_5(int t_index);
		VOID processQueue_i_2_r_6(int t_index);
		VOID processQueue_i_2_r_7(int t_index);

		VOID processQueue_i_3_r_0(int t_index);
		VOID processQueue_i_3_r_1(int t_index);
		VOID processQueue_i_3_r_2(int t_index);
		VOID processQueue_i_3_r_3(int t_index);
		VOID processQueue_i_3_r_4(int t_index);
		VOID processQueue_i_3_r_5(int t_index);
		VOID processQueue_i_3_r_6(int t_index);
		VOID processQueue_i_3_r_7(int t_index);

		VOID processQueue_i_4_r_0(int t_index);
		VOID processQueue_i_4_r_1(int t_index);
		VOID processQueue_i_4_r_2(int t_index);
		VOID processQueue_i_4_r_3(int t_index);
		VOID processQueue_i_4_r_4(int t_index);
		VOID processQueue_i_4_r_5(int t_index);
		VOID processQueue_i_4_r_6(int t_index);
		VOID processQueue_i_4_r_7(int t_index);

		VOID processQueue_i_5_r_0(int t_index);
		VOID processQueue_i_5_r_1(int t_index);
		VOID processQueue_i_5_r_2(int t_index);
		VOID processQueue_i_5_r_3(int t_index);
		VOID processQueue_i_5_r_4(int t_index);
		VOID processQueue_i_5_r_5(int t_index);
		VOID processQueue_i_5_r_6(int t_index);
		VOID processQueue_i_5_r_7(int t_index);

		VOID processQueue_i_6_r_0(int t_index);
		VOID processQueue_i_6_r_1(int t_index);
		VOID processQueue_i_6_r_2(int t_index);
		VOID processQueue_i_6_r_3(int t_index);
		VOID processQueue_i_6_r_4(int t_index);
		VOID processQueue_i_6_r_5(int t_index);
		VOID processQueue_i_6_r_6(int t_index);
		VOID processQueue_i_6_r_7(int t_index);

		VOID processQueue_i_7_r_0(int t_index);
		VOID processQueue_i_7_r_1(int t_index);
		VOID processQueue_i_7_r_2(int t_index);
		VOID processQueue_i_7_r_3(int t_index);
		VOID processQueue_i_7_r_4(int t_index);
		VOID processQueue_i_7_r_5(int t_index);
		VOID processQueue_i_7_r_6(int t_index);
		VOID processQueue_i_7_r_7(int t_index);

		VOID decodePacket();
};

#endif /* CORE_SRC_PACKETROUTER_H_ */
