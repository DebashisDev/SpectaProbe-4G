/*
 * S5S8XdrWriter.h
 *
 *  Created on: 24-Feb-2020
 *      Author: singh
 */

#ifndef PLUGINS_GTPCV2_INC_S5S8XDRWRITER_H_
#define PLUGINS_GTPCV2_INC_S5S8XDRWRITER_H_

#include "IPGlobal.h"
#include "GTPGlobal.h"
#include "Log.h"
#include "ProbeUtility.h"
#include "BaseConfig.h"
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <fstream>

class S5S8XdrWriter  : BaseConfig
{
	private:
		fstream		S5S8XdrHandler;
		BOOL		repoInitStatus 	= false;
		string 		csvIpDataGlb;
		int 		csvIpBatchCount = 0;
		xdrStore 	objXdrStore;
		int 		currentMin, currentHour, currentDay, currentMonth, currentYear;

		VOID 		processS5S8(int index);
		VOID 		writeXdrData(std::unordered_map<int, xdrStore> &s5s8_xdr_map, int &s5s8_xdr_map_cnt);
		VOID 		openXdrFile(int currentMin, int currentHour, int currentDay, int currentMonth, int currentYear);
		VOID		closeXdrFile();

	public:
		S5S8XdrWriter();
		~S5S8XdrWriter();
		VOID 	run();
		BOOL 	isRepositoryInitialized();
};

#endif /* PLUGINS_GTPCV2_INC_S5S8XDRWRITER_H_ */
