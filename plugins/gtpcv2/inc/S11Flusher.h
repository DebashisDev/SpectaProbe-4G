/*
 * S11Flusher.h
 *
 *  Created on: 24-Feb-2020
 *      Author: singh
 */

#ifndef PLUGINS_GTPCV2_INC_S11FLUSHER_H_
#define PLUGINS_GTPCV2_INC_S11FLUSHER_H_

#include "IPGlobal.h"
#include "Log.h"
#include "BaseConfig.h"
#include "GTPGlobal.h"

using namespace std;

class S11Flusher : BaseConfig {
	private:
		xdrStore objXdrStore;
		BOOL	repoInitStatus = false;
		char 	csvXdr[XDR_MAX_LEN];
		char 	endCause[100];
		char 	sourceIp[IP_ADDR_LEN], destIp[IP_ADDR_LEN];

		VOID 	processS11Data(int index);
		VOID 	flushS11Data_t(std::unordered_map<int, GTPSession> &flushMap, int &s11FlushMap_cnt);
		VOID 	buildS11Session(GTPSession *ps11Session);
		VOID	flushS11CsvRecords();

	public:
		S11Flusher();
		~S11Flusher();
		VOID 	run();
		BOOL 	isRepositoryInitialized();
};

#endif /* PLUGINS_GTPCV2_INC_S11FLUSHER_H_ */
