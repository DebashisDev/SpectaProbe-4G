/*
 * IPXdrFlusher.h
 *
 *  Created on: Apr 24, 2017
 *      Author: Debashis
 */

#ifndef PLUGINS_TCP_SRC_IPXDRWRITER_H_
#define PLUGINS_TCP_SRC_IPXDRWRITER_H_

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

class S1UXdrWriter :BaseConfig {

	private:

			fstream	IpXdrHandler;
			string 	csvIpDataGlb;
			int 	csvIpBatchCount = 0;
			BOOL 	repoInitStatus = false;
			char 	csvXdr[XDR_MAX_LEN];
			VOID	processIp(int index);
			VOID 	writeIpCsvData(std::unordered_map<int, xdrStore> &ip_flush_map, int &ip_xdr_flush_map_cnt);
			VOID 	openIpCsvXdrFile(int currentMin, int currentHour, int currentDay, int currentMonth, int currentYear);
			VOID 	closeIpCsvXdrFile();

	public:
			S1UXdrWriter();
			~S1UXdrWriter();
			BOOL 	isRepositoryInitialized();
			VOID 	run();

};

#endif /* PLUGINS_TCP_SRC_IPXDRWRITER_H_ */
