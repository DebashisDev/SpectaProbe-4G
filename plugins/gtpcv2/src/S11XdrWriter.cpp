/*
 * S11XdrWriter.cpp
 *
 *  Created on: 24-Feb-2020
 *      Author: Ishan
 */

#include "S11XdrWriter.h"

S11XdrWriter::S11XdrWriter()
{ currentMin = currentHour = currentDay = currentMonth = currentYear = 0; }

S11XdrWriter::~S11XdrWriter()
{ }

BOOL S11XdrWriter::isRepositoryInitialized()
{ return repoInitStatus; }

VOID S11XdrWriter::run()
{
	int lastProcessedIndex 	= -1;
	int curIndex 			= -1;
	int prevMin 			= 0;
	repoInitStatus 			= true;
	lastProcessedIndex 		= 0;

	currentMin = currentHour = currentDay = currentMonth = currentYear = 0;

	currentMin = prevMin = IPGlobal::CURRENT_MIN;

	curIndex = PKT_READ_TIME_INDEX(IPGlobal::CURRENT_EPOCH_SEC, IPGlobal::PKT_TIME_INDEX);

	lastProcessedIndex = curIndex;

	while(IPGlobal::S11_XDR_FLUSHER_RUNNING_STATUS)
	{
		usleep(25000);
		curIndex = PKT_READ_TIME_INDEX(IPGlobal::CURRENT_EPOCH_SEC, IPGlobal::PKT_TIME_INDEX);

		while(lastProcessedIndex != curIndex)
		{
			usleep(25000);		// 100ms;	//Just to eliminate racing condition at 00 sec

			currentMin 		= IPGlobal::CURRENT_MIN;
			currentHour 	= IPGlobal::CURRENT_HOUR;
			currentDay 		= IPGlobal::CURRENT_DAY;
			currentMonth 	= IPGlobal::CURRENT_MONTH;
			currentYear 	= IPGlobal::CURRENT_YEAR;

			if(IPGlobal::S11_WRITE_XDR)
				processS11(lastProcessedIndex);

			lastProcessedIndex = PKT_READ_NEXT_TIME_INDEX(lastProcessedIndex, IPGlobal::PKT_TIME_INDEX);
		}
	}
	printf("\n S11 Xdr Flusher Shutdown Completed\n");
}

VOID S11XdrWriter::openXdrFile(int currentMin, int currentHour, int currentDay, int currentMonth, int currentYear)
{
	filePath[0] 		= 0;

	sprintf(filePath, "%s%s/%s_%d-%02d-%02d-%02d-%02d.csv",
					GContainer::config->XDR_DIR.c_str(),
					IPGlobal::S11_FILE_PREFIX.c_str(),
					IPGlobal::S11_FILE_PREFIX.c_str(),
					currentYear,
					currentMonth,
					currentDay,
					currentHour,
					currentMin);
	S11XdrHandler.open((char *)filePath, ios :: out | ios :: app);

	if(S11XdrHandler.fail()) {
//		TheLog_v1(Log::Warn, "IPFlusher.cpp", " [%s] GTPc Csv file Open failed. !!!", filePath);
	} else {
//		TheLog_v1(Log::Debug, "IPFlusher.cpp", " [%s] GTPc Csv file Open Success. !!!", filePath);
	}

	filePath[0] = 0;
}

VOID S11XdrWriter::closeXdrFile()
{
	S11XdrHandler.close();
}

VOID S11XdrWriter::processS11(int index)
{
	switch(index)
	{
		case 0:
			writeXdrData(S11XdrFlush::s11_xdr_flush_t_0, S11XdrFlush::s11_xdr_flush_t_0_cnt);
			break;

		case 1:
			writeXdrData(S11XdrFlush::s11_xdr_flush_t_1, S11XdrFlush::s11_xdr_flush_t_1_cnt);
			break;

		case 2:
			writeXdrData(S11XdrFlush::s11_xdr_flush_t_2, S11XdrFlush::s11_xdr_flush_t_2_cnt);
			break;

		case 3:
			writeXdrData(S11XdrFlush::s11_xdr_flush_t_3, S11XdrFlush::s11_xdr_flush_t_3_cnt);
			break;

		case 4:
			writeXdrData(S11XdrFlush::s11_xdr_flush_t_4, S11XdrFlush::s11_xdr_flush_t_4_cnt);
			break;

		case 5:
			writeXdrData(S11XdrFlush::s11_xdr_flush_t_5, S11XdrFlush::s11_xdr_flush_t_5_cnt);
			break;

		case 6:
			writeXdrData(S11XdrFlush::s11_xdr_flush_t_6, S11XdrFlush::s11_xdr_flush_t_6_cnt);
			break;

		case 7:
			writeXdrData(S11XdrFlush::s11_xdr_flush_t_7, S11XdrFlush::s11_xdr_flush_t_7_cnt);
			break;

		case 8:
			writeXdrData(S11XdrFlush::s11_xdr_flush_t_8, S11XdrFlush::s11_xdr_flush_t_8_cnt);
			break;

		case 9:
			writeXdrData(S11XdrFlush::s11_xdr_flush_t_9, S11XdrFlush::s11_xdr_flush_t_9_cnt);
			break;
	}
}

//VOID S11XdrWriter::writeXdrData(std::unordered_map<int, xdrStore> &s11_xdr_map, int &s11_xdr_map_cnt)
//{
//
//	int totalFlushCount = s11_xdr_map_cnt;
//	if(totalFlushCount > 0)
//	{
//		openXdrFile(currentMin, currentHour, currentDay, currentMonth, currentYear);
//
//		for(int i=0; i<totalFlushCount; i++)
//		{
//			csvIpBatchCount++;
//			csvIpDataGlb = csvIpDataGlb + std::string(s11_xdr_map[i].xdr) + "\n";
//
//			if((csvIpBatchCount >= XDR_RECORDS_BATCH_SIZE) || (i == (totalFlushCount  - 1))){
//				//Write to file
//				S11XdrHandler << csvIpDataGlb;
//				csvIpDataGlb = "";
//				csvIpBatchCount = 0;
//			}
//			s11_xdr_map.erase(i);
//			s11_xdr_map_cnt--;
//		}
//		s11_xdr_map.clear();
//		closeXdrFile();
//	}
//	s11_xdr_map_cnt = 0;
//}

VOID S11XdrWriter::writeXdrData(std::unordered_map<int, xdrStore> &s11_xdr_map, int &s11_xdr_map_cnt)
{

	int totalFlushCount = s11_xdr_map_cnt;

	if(totalFlushCount > 0)
	{
		openXdrFile(currentMin, currentHour, currentDay, currentMonth, currentYear);

		for(auto elem = s11_xdr_map.begin(), next_elem = elem; elem != s11_xdr_map.end(); elem = next_elem)
		{
			++next_elem;
			S11XdrHandler << std::string(elem->second.xdr) + "\n";
			s11_xdr_map.erase(elem->first);
			s11_xdr_map_cnt--;
		}
		s11_xdr_map.clear();
		closeXdrFile();
	}
	s11_xdr_map_cnt = 0;
}
