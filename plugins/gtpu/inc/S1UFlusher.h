/*
 * IPFlusher.h
 *
 *  Created on: Apr 24, 2017
 *      Author: Debashis
 */

#ifndef PLUGINS_TCP_SRC_IPFLUSHER_H_
#define PLUGINS_TCP_SRC_IPFLUSHER_H_

#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <iostream>
#include <fstream>

#include "IPGlobal.h"
#include "Log.h"
#include "ProbeUtility.h"
#include "TCPFlusherUtility.h"
#include "BaseConfig.h"

class S1UFlusher : BaseConfig{

	private:
		int		InstanceId = 0;

		TCPFlusherUtility *tcpFlusherUtility;
		long processStartEpochSec = 0;

		BOOL	repoInitStatus = false;
		char 	csvXdr[XDR_MAX_LEN];
		char 	tdrXdr[TDR_MAX_LEN];

		xdrStore objXdrStore;

		VOID 	processIpData(int index);
		VOID 	processIpData_f_0(int index);
		VOID 	processIpData_f_1(int index);
		VOID 	processIpData_f_2(int index);
		VOID 	processIpData_f_3(int index);

		VOID 	flushIpData_sm_t(std::unordered_map<int, ipSession> &flushMap, int &ipFlushMap_sm_cnt);

		VOID 	flushIpCsvRecords();
		VOID 	flushIpCsvRecords_f_0();
		VOID 	flushIpCsvRecords_f_1();
		VOID 	flushIpCsvRecords_f_2();
		VOID 	flushIpCsvRecords_f_3();

		VOID 	storeIpZmqRecords(int index, int &ip_zmq_flush_map_cnt, std::unordered_map<int, xdrStore> &ip_zmq_flush_map);
		VOID 	buildCSVDataIp(ipSession *pIpSession);

	public:
			S1UFlusher(int id);
			~S1UFlusher();
			BOOL 	isRepositoryInitialized();
			VOID 	run();
};
#endif /* PLUGINS_TCP_SRC_IPFLUSHER_H_ */
