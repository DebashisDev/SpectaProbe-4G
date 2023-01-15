/*
 * S1APXdrWriter.cpp
 *
 *  Created on: 29-Jan-2020
 *      Author: Ishan
 */

#include "S1APXdrWriter.h"

S1APXdrWriter::S1APXdrWriter()
{
	currentMin = currentHour = currentDay = currentMonth = currentYear = 0;
}

S1APXdrWriter::~S1APXdrWriter() {
}

BOOL S1APXdrWriter::isRepositoryInitialized() {
	return repoInitStatus;
}

VOID S1APXdrWriter::run()
{
	int lastProcessedIndex = -1;
	int curIndex = -1;
	int prevMin = 0;
	repoInitStatus = true;

	lastProcessedIndex = 0;
	currentMin = currentHour = currentDay = currentMonth = currentYear = 0;

	currentMin = prevMin = IPGlobal::CURRENT_MIN;

	curIndex = PKT_READ_TIME_INDEX(IPGlobal::CURRENT_EPOCH_SEC, IPGlobal::PKT_TIME_INDEX);

	lastProcessedIndex = curIndex;

	while(IPGlobal::S1MME_XDR_FLUSHER_RUNNING_STATUS)
	{
		usleep(25000);
		curIndex = PKT_READ_TIME_INDEX(IPGlobal::CURRENT_EPOCH_SEC, IPGlobal::PKT_TIME_INDEX);

		while(lastProcessedIndex != curIndex){

			usleep(25000);		// 100ms;	//Just to eliminate racing condition at 00 sec

			currentMin 		= IPGlobal::CURRENT_MIN;
			currentHour 	= IPGlobal::CURRENT_HOUR;
			currentDay 		= IPGlobal::CURRENT_DAY;
			currentMonth 	= IPGlobal::CURRENT_MONTH;
			currentYear 	= IPGlobal::CURRENT_YEAR;

			if(IPGlobal::S1MME_WRITE_XDR)
				processS1ap(lastProcessedIndex);

			lastProcessedIndex = PKT_READ_NEXT_TIME_INDEX(lastProcessedIndex, IPGlobal::PKT_TIME_INDEX);
		}
	}
	printf("\n S1ap Xdr Flusher Shutdown Completed\n");
}

VOID S1APXdrWriter::openXdrFile(int currentMin, int currentHour, int currentDay, int currentMonth, int currentYear)
{
	TCHAR filePath[300];
	filePath[0] = 0;

	sprintf(filePath, "%s%s/%s_%d-%02d-%02d-%02d-%02d.csv",
					GContainer::config->XDR_DIR.c_str(),
					IPGlobal::S1MME_FILE_PREFIX.c_str(),
					IPGlobal::S1MME_FILE_PREFIX.c_str(),
					currentYear,
					currentMonth,
					currentDay,
					currentHour,
					currentMin);
	S1apXdrHandler.open((char *)filePath, ios :: out | ios :: app);

	if(S1apXdrHandler.fail()) {
//		TheLog_v1(Log::Warn, "IPFlusher.cpp", " [%s] GTPc Csv file Open failed. !!!", filePath);
	} else {
//		TheLog_v1(Log::Debug, "IPFlusher.cpp", " [%s] GTPc Csv file Open Success. !!!", filePath);
	}

	filePath[0] = 0;
}

VOID S1APXdrWriter::closeXdrFile()
{
	S1apXdrHandler.close();
}

VOID S1APXdrWriter::processS1ap(int index)
{
	switch(index)
	{
		case 0:
			writeXdrData(S1APFlush::s1ap_xdr_f_0_t_0, S1APFlush::s1ap_xdr_f_0_t_0_cnt);
			break;

		case 1:
			writeXdrData(S1APFlush::s1ap_xdr_f_0_t_1, S1APFlush::s1ap_xdr_f_0_t_1_cnt);
			break;

		case 2:
			writeXdrData(S1APFlush::s1ap_xdr_f_0_t_2, S1APFlush::s1ap_xdr_f_0_t_2_cnt);
			break;

		case 3:
			writeXdrData(S1APFlush::s1ap_xdr_f_0_t_3, S1APFlush::s1ap_xdr_f_0_t_3_cnt);
			break;

		case 4:
			writeXdrData(S1APFlush::s1ap_xdr_f_0_t_4, S1APFlush::s1ap_xdr_f_0_t_4_cnt);
			break;

		case 5:
			writeXdrData(S1APFlush::s1ap_xdr_f_0_t_5, S1APFlush::s1ap_xdr_f_0_t_5_cnt);
			break;

		case 6:
			writeXdrData(S1APFlush::s1ap_xdr_f_0_t_6, S1APFlush::s1ap_xdr_f_0_t_6_cnt);
			break;

		case 7:
			writeXdrData(S1APFlush::s1ap_xdr_f_0_t_7, S1APFlush::s1ap_xdr_f_0_t_7_cnt);
			break;

		case 8:
			writeXdrData(S1APFlush::s1ap_xdr_f_0_t_8, S1APFlush::s1ap_xdr_f_0_t_8_cnt);
			break;

		case 9:
			writeXdrData(S1APFlush::s1ap_xdr_f_0_t_9, S1APFlush::s1ap_xdr_f_0_t_9_cnt);
			break;
	}
}

VOID S1APXdrWriter::writeXdrData(std::unordered_map<int, xdrStore> &s1ap_xdr_map, int &s1ap_xdr_map_cnt)
{

	int totalFlushCount = s1ap_xdr_map_cnt;
	if(totalFlushCount > 0)
	{
		openXdrFile(currentMin, currentHour, currentDay, currentMonth, currentYear);
		for(int i=0; i<totalFlushCount; i++)
		{
			csvIpBatchCount++;
			csvIpDataGlb = csvIpDataGlb + std::string(s1ap_xdr_map[i].xdr) + "\n";

			if((csvIpBatchCount >= XDR_RECORDS_BATCH_SIZE) || (i == (totalFlushCount  - 1))){
				//Write to file
				S1apXdrHandler << csvIpDataGlb;
				csvIpDataGlb = "";
				csvIpBatchCount = 0;
			}
			s1ap_xdr_map.erase(i);
			s1ap_xdr_map_cnt--;
		}
		s1ap_xdr_map.clear();
		closeXdrFile();
	}
	s1ap_xdr_map_cnt = 0;
}



