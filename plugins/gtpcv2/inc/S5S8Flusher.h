/*
 * S5S8Flusher.h
 *
 *  Created on: 24-Feb-2020
 *      Author: singh
 */

#ifndef PLUGINS_GTPCV2_INC_S5S8FLUSHER_H_
#define PLUGINS_GTPCV2_INC_S5S8FLUSHER_H_

#include "IPGlobal.h"
#include "Log.h"
#include "BaseConfig.h"
#include "GTPGlobal.h"

using namespace std;

class S5S8Flusher  : BaseConfig {
	private:
		xdrStore objXdrStore;
		BOOL	repoInitStatus = false;
		char 	sourceIp[IP_ADDR_LEN], destIp[IP_ADDR_LEN];
		char 	endCause[100];

		char 	csvXdr[XDR_MAX_LEN];
		VOID 	processS5S8Data(int index);
		VOID 	flushS5S8Data_t(std::unordered_map<int, GTPSession> &flushMap, int &s5s8FlushMap_cnt);
		VOID 	buildS5S8Session(GTPSession *ps5s8Session);
		VOID	flushS5S8CsvRecords();

	public:
		S5S8Flusher();
		~S5S8Flusher();
		VOID 	run();
		BOOL 	isRepositoryInitialized();
};

#endif /* PLUGINS_GTPCV2_INC_S5S8FLUSHER_H_ */
