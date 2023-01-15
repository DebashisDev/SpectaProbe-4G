/*
 * FLFlusherZmq.h
 *
 *  Created on: Apr 24, 2017
 *      Author: Debashis
 */

#ifndef PLUGINS_FIXEDLINE_SRC_FLFLUSHERZMQ_H_
#define PLUGINS_FIXEDLINE_SRC_FLFLUSHERZMQ_H_

#include <sys/time.h>
#include <stdlib.h>
#include <unistd.h>

#include "IPGlobal.h"
#include "Log.h"
#include "BaseConfig.h"

#define FLASH_TYPE_GTPU	1
#define FLASH_TYPE_GTPC	2
#define FLASH_TYPE_GTPU_DNS	3

class zmqPush : BaseConfig{

	public:
		zmqPush();
		~zmqPush();

		VOID run();
		BOOL  	isRepositoryInitialized();

	private:

		timeval curTime;
		int		TPS_PER_100MS = 1000;
		char 	csvXdr[XDR_MAX_LEN];
		BOOL repoInitStatus = false;

		VOID 	process(int index);
		VOID 	sendIpZmqData(std::unordered_map<int, xdrStore> &zmq_flush_map, int &zmq_flush_map_cnt);
		VOID 	sendDnsZmqData(std::unordered_map<int, xdrStore> &zmq_flush_map, int &zmq_flush_map_cnt);
		VOID 	openZmq();
		VOID	buildBwCSV(long timems);
		VOID	clearZMQ();
		VOID	ZMQReConnect();
		VOID	checkZMQStatus(long epochSec);
};
#endif /* PLUGINS_FIXEDLINE_SRC_FLFLUSHERZMQ_H_ */
