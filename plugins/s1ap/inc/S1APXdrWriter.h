/*
 * S1APXdrWriter.h
 *
 *  Created on: 29-Jan-2020
 *      Author: singh
 */

#ifndef PLUGINS_S1AP_INC_S1APXDRWRITER_H_
#define PLUGINS_S1AP_INC_S1APXDRWRITER_H_

#include "IPGlobal.h"
#include "Log.h"
#include "ProbeUtility.h"
#include "BaseConfig.h"
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <fstream>


class S1APXdrWriter : BaseConfig
{
	private:
		fstream		S1apXdrHandler;
		BOOL		repoInitStatus 	= false;
		string 		csvIpDataGlb;
		int 		csvIpBatchCount = 0;
		xdrStore 	objXdrStore;
		int 		currentMin, currentHour, currentDay, currentMonth, currentYear;

		VOID 		processS1ap(int index);
		VOID 		writeXdrData(std::unordered_map<int, xdrStore> &s1ap_xdr_map, int &s1ap_xdr_map_cnt);
		VOID 		openXdrFile(int currentMin, int currentHour, int currentDay, int currentMonth, int currentYear);
		VOID		closeXdrFile();


	public:
		S1APXdrWriter();
		~S1APXdrWriter();

		VOID 	run();
		BOOL 	isRepositoryInitialized();
};

#endif /* PLUGINS_S1AP_INC_S1APXDRWRITER_H_ */
