/*
 * S11XdrWriter.h
 *
 *  Created on: 24-Feb-2020
 *      Author: Ishan
 */

#ifndef PLUGINS_GTPCV2_INC_S11XDRWRITER_H_
#define PLUGINS_GTPCV2_INC_S11XDRWRITER_H_

#include "IPGlobal.h"
#include "GTPGlobal.h"
#include "Log.h"
#include "ProbeUtility.h"
#include "BaseConfig.h"
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <fstream>

class S11XdrWriter : BaseConfig
{
	private:
		TCHAR 		filePath[300];
		fstream		S11XdrHandler;
		BOOL		repoInitStatus 	= false;
		string 		csvIpDataGlb;
		int 		csvIpBatchCount = 0;
		xdrStore 	objXdrStore;
		int 		currentMin, currentHour, currentDay, currentMonth, currentYear;

		VOID 		processS11(int index);
		VOID 		writeXdrData(std::unordered_map<int, xdrStore> &s11_xdr_map, int &s11_xdr_map_cnt);
		VOID 		openXdrFile(int currentMin, int currentHour, int currentDay, int currentMonth, int currentYear);
		VOID		closeXdrFile();

	public:
		S11XdrWriter();
		~S11XdrWriter();
		VOID 	run();
		BOOL 	isRepositoryInitialized();
};

#endif /* PLUGINS_GTPCV2_INC_S11XDRWRITER_H_ */
