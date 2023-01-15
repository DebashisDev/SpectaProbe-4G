/*
 * DNSXdrWriter.h
 *
 *  Created on: 19-Sep-2019
 *      Author: singh
 */

#ifndef PLUGINS_TCP_INC_DNSXDRWRITER_H_
#define PLUGINS_TCP_INC_DNSXDRWRITER_H_

#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <iostream>
#include <fstream>

#include "IPGlobal.h"
#include "Log.h"
#include "ProbeUtility.h"
#include "BaseConfig.h"
#include "TCPUDPGlobal.h"

class DNSXdrWriter :BaseConfig {
	private:
		fstream	DnsXdrHandler;
		string 	csvDNSDataGlb;
		int 	csvDNSBatchCount = 0;
		BOOL	repoInitStatus = false;
		char 	csvXdr[XDR_MAX_LEN];
		VOID	processDns(int index);
		VOID 	writeDnsCsvData(std::unordered_map<int, xdrStore> &dns_flush_map, int &dns_xdr_flush_map_cnt);
		VOID 	openDnsCsvXdrFile(int currentMin, int currentHour, int currentDay, int currentMonth, int currentYear);
		VOID 	closeDnsCsvXdrFile();

	public:
		DNSXdrWriter();
		~DNSXdrWriter();
		BOOL 	isRepositoryInitialized();
		VOID 	run();

};

#endif /* PLUGINS_TCP_INC_DNSXDRWRITER_H_ */
