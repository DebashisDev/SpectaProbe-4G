/*
 * DNSFlusher.h
 *
 *  Created on: 17-Sep-2019
 *      Author: singh
 */

#ifndef PLUGINS_TCP_INC_DNSFLUSHER_H_
#define PLUGINS_TCP_INC_DNSFLUSHER_H_

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

class DNSFlusher : BaseConfig{
	private:
		int			InstanceId = 0;
		xdrStore	objXdrStore;
		BOOL		repoInitStatus = false;
		long	 	processStartEpochSec = 0;
		char 		csvXdr[XDR_MAX_LEN];

		TCPFlusherUtility *tcpFlusherUtility;

		VOID 	processDNSData(int index);
		VOID 	processDNSData_f_0(int index);
		VOID 	processDNSData_f_1(int index);
		VOID 	processDNSData_f_2(int index);
		VOID 	processDNSData_f_3(int index);

		VOID 	flushDNSData_sm_t(std::unordered_map<int, dnsSession> &flushMap, int &dnsFlushMap_sm_cnt);
		VOID 	flushDNSCsvRecords();
		VOID 	flushDNSCsvRecords_f_0();
		VOID 	flushDNSCsvRecords_f_1();
		VOID 	flushDNSCsvRecords_f_2();
		VOID 	flushDNSCsvRecords_f_3();

		VOID 	storeDNSZmqRecords(int index, int &dns_zmq_flush_map_cnt, std::unordered_map<int, xdrStore> &dns_zmq_flush_map);
		VOID 	buildCSVDataDns(dnsSession *pDnsSession);

	public:
		DNSFlusher(int id);
		~DNSFlusher();
		BOOL 	isRepositoryInitialized();
		VOID 	run();
};

#endif /* PLUGINS_TCP_INC_DNSFLUSHER_H_ */
