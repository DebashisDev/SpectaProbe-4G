/*
 * IPXdrFlusher.cpp
 *
 *  Created on: Apr 24, 2017
 *      Author: Debashis
 */

#include "../inc/S1UXdrWriter.h"


S1UXdrWriter::S1UXdrWriter() {
	this->_name = "IPXdrFlusher";
	this->setLogLevel(Log::theLog().level());
}

S1UXdrWriter::~S1UXdrWriter() {
}

BOOL S1UXdrWriter::isRepositoryInitialized() {
	return repoInitStatus;
}

VOID S1UXdrWriter::run()
{
	int currentMin, currentHour, currentDay, currentMonth, currentYear;
	int lastProcessedIndex = -1;
	int curIndex = -1;
	int prevMin = 0;
	repoInitStatus = true;

	lastProcessedIndex = 0;
	currentMin = currentHour = currentDay = currentMonth = currentYear = 0;

	currentMin = prevMin = IPGlobal::CURRENT_MIN;

	curIndex = PKT_READ_TIME_INDEX(IPGlobal::CURRENT_EPOCH_SEC, 10);

	lastProcessedIndex = curIndex;

	while(IPGlobal::S1U_XDR_FLUSHER_RUNNING_STATUS)
	{
		usleep(50000);
		curIndex = PKT_READ_TIME_INDEX(IPGlobal::CURRENT_EPOCH_SEC, 10);

		while(lastProcessedIndex != curIndex){

			usleep(25000);		// 100ms;	//Just to eliminate racing condition at 00 sec

//			IPGlobal::lastFlusherEpochTimeSec = IPGlobal::CURRENT_EPOCH_SEC;

			currentMin 		= IPGlobal::CURRENT_MIN;
			currentHour 	= IPGlobal::CURRENT_HOUR;
			currentDay 		= IPGlobal::CURRENT_DAY;
			currentMonth 	= IPGlobal::CURRENT_MONTH;
			currentYear 	= IPGlobal::CURRENT_YEAR;

			if(IPGlobal::S1U_WRITE_XDR)
			{
				strcpy(csvXdr, "");
				openIpCsvXdrFile(currentMin, currentHour, currentDay, currentMonth, currentYear);
				processIp(lastProcessedIndex);
				closeIpCsvXdrFile();
			}
			lastProcessedIndex = PKT_READ_NEXT_TIME_INDEX(lastProcessedIndex, 10);
		}
	}
	printf("\nS1UXdr Flusher Shutdown Completed\n");
}

VOID S1UXdrWriter::writeIpCsvData(std::unordered_map<int, xdrStore> &ip_flush_map, int &ip_xdr_flush_map_cnt)
{
//	int totalFlushCount = ip_xdr_flush_map_cnt;

	int totalFlushCount = ip_flush_map.size();

	if(totalFlushCount > 0)
	{
		for(int i=0; i<totalFlushCount; i++)
		{
			csvIpBatchCount++;
			csvIpDataGlb = csvIpDataGlb + std::string(ip_flush_map[i].xdr) + "\n";

			if((csvIpBatchCount >= XDR_RECORDS_BATCH_SIZE) || (i == (totalFlushCount  - 1)))
			{
				IpXdrHandler << csvIpDataGlb;
				csvIpDataGlb = "";
				csvIpBatchCount = 0;
			}
			ip_flush_map.erase(i);
			ip_xdr_flush_map_cnt--;
		}
		ip_flush_map.clear();
	}
	ip_xdr_flush_map_cnt = 0;
}

VOID S1UXdrWriter::processIp(int index)
{
	switch(index)
	{
		case 0:
			writeIpCsvData(IPFlushRepository::ip_xdr_flush_f_0_t_0, IPFlushRepository::ip_xdr_flush_f_0_t_0_cnt);
			writeIpCsvData(IPFlushRepository::ip_xdr_flush_f_1_t_0, IPFlushRepository::ip_xdr_flush_f_1_t_0_cnt);
			writeIpCsvData(IPFlushRepository::ip_xdr_flush_f_2_t_0, IPFlushRepository::ip_xdr_flush_f_2_t_0_cnt);
			writeIpCsvData(IPFlushRepository::ip_xdr_flush_f_3_t_0, IPFlushRepository::ip_xdr_flush_f_3_t_0_cnt);
			break;

		case 1:
			writeIpCsvData(IPFlushRepository::ip_xdr_flush_f_0_t_1, IPFlushRepository::ip_xdr_flush_f_0_t_1_cnt);
			writeIpCsvData(IPFlushRepository::ip_xdr_flush_f_1_t_1, IPFlushRepository::ip_xdr_flush_f_1_t_1_cnt);
			writeIpCsvData(IPFlushRepository::ip_xdr_flush_f_2_t_1, IPFlushRepository::ip_xdr_flush_f_2_t_1_cnt);
			writeIpCsvData(IPFlushRepository::ip_xdr_flush_f_3_t_1, IPFlushRepository::ip_xdr_flush_f_3_t_1_cnt);
			break;

		case 2:
			writeIpCsvData(IPFlushRepository::ip_xdr_flush_f_0_t_2, IPFlushRepository::ip_xdr_flush_f_0_t_2_cnt);
			writeIpCsvData(IPFlushRepository::ip_xdr_flush_f_1_t_2, IPFlushRepository::ip_xdr_flush_f_1_t_2_cnt);
			writeIpCsvData(IPFlushRepository::ip_xdr_flush_f_2_t_2, IPFlushRepository::ip_xdr_flush_f_2_t_2_cnt);
			writeIpCsvData(IPFlushRepository::ip_xdr_flush_f_3_t_2, IPFlushRepository::ip_xdr_flush_f_3_t_2_cnt);
			break;

		case 3:
			writeIpCsvData(IPFlushRepository::ip_xdr_flush_f_0_t_3, IPFlushRepository::ip_xdr_flush_f_0_t_3_cnt);
			writeIpCsvData(IPFlushRepository::ip_xdr_flush_f_1_t_3, IPFlushRepository::ip_xdr_flush_f_1_t_3_cnt);
			writeIpCsvData(IPFlushRepository::ip_xdr_flush_f_2_t_3, IPFlushRepository::ip_xdr_flush_f_2_t_3_cnt);
			writeIpCsvData(IPFlushRepository::ip_xdr_flush_f_3_t_3, IPFlushRepository::ip_xdr_flush_f_3_t_3_cnt);
			break;

		case 4:
			writeIpCsvData(IPFlushRepository::ip_xdr_flush_f_0_t_4, IPFlushRepository::ip_xdr_flush_f_0_t_4_cnt);
			writeIpCsvData(IPFlushRepository::ip_xdr_flush_f_1_t_4, IPFlushRepository::ip_xdr_flush_f_1_t_4_cnt);
			writeIpCsvData(IPFlushRepository::ip_xdr_flush_f_2_t_4, IPFlushRepository::ip_xdr_flush_f_2_t_4_cnt);
			writeIpCsvData(IPFlushRepository::ip_xdr_flush_f_3_t_4, IPFlushRepository::ip_xdr_flush_f_3_t_4_cnt);
			break;

		case 5:
			writeIpCsvData(IPFlushRepository::ip_xdr_flush_f_0_t_5, IPFlushRepository::ip_xdr_flush_f_0_t_5_cnt);
			writeIpCsvData(IPFlushRepository::ip_xdr_flush_f_1_t_5, IPFlushRepository::ip_xdr_flush_f_1_t_5_cnt);
			writeIpCsvData(IPFlushRepository::ip_xdr_flush_f_2_t_5, IPFlushRepository::ip_xdr_flush_f_2_t_5_cnt);
			writeIpCsvData(IPFlushRepository::ip_xdr_flush_f_3_t_5, IPFlushRepository::ip_xdr_flush_f_3_t_5_cnt);
			break;

		case 6:
			writeIpCsvData(IPFlushRepository::ip_xdr_flush_f_0_t_6, IPFlushRepository::ip_xdr_flush_f_0_t_6_cnt);
			writeIpCsvData(IPFlushRepository::ip_xdr_flush_f_1_t_6, IPFlushRepository::ip_xdr_flush_f_1_t_6_cnt);
			writeIpCsvData(IPFlushRepository::ip_xdr_flush_f_2_t_6, IPFlushRepository::ip_xdr_flush_f_2_t_6_cnt);
			writeIpCsvData(IPFlushRepository::ip_xdr_flush_f_3_t_6, IPFlushRepository::ip_xdr_flush_f_3_t_6_cnt);
			break;

		case 7:
			writeIpCsvData(IPFlushRepository::ip_xdr_flush_f_0_t_7, IPFlushRepository::ip_xdr_flush_f_0_t_7_cnt);
			writeIpCsvData(IPFlushRepository::ip_xdr_flush_f_1_t_7, IPFlushRepository::ip_xdr_flush_f_1_t_7_cnt);
			writeIpCsvData(IPFlushRepository::ip_xdr_flush_f_2_t_7, IPFlushRepository::ip_xdr_flush_f_2_t_7_cnt);
			writeIpCsvData(IPFlushRepository::ip_xdr_flush_f_3_t_7, IPFlushRepository::ip_xdr_flush_f_3_t_7_cnt);
			break;

		case 8:
			writeIpCsvData(IPFlushRepository::ip_xdr_flush_f_0_t_8, IPFlushRepository::ip_xdr_flush_f_0_t_8_cnt);
			writeIpCsvData(IPFlushRepository::ip_xdr_flush_f_1_t_8, IPFlushRepository::ip_xdr_flush_f_1_t_8_cnt);
			writeIpCsvData(IPFlushRepository::ip_xdr_flush_f_2_t_8, IPFlushRepository::ip_xdr_flush_f_2_t_8_cnt);
			writeIpCsvData(IPFlushRepository::ip_xdr_flush_f_3_t_8, IPFlushRepository::ip_xdr_flush_f_3_t_8_cnt);
			break;

		case 9:
			writeIpCsvData(IPFlushRepository::ip_xdr_flush_f_0_t_9, IPFlushRepository::ip_xdr_flush_f_0_t_9_cnt);
			writeIpCsvData(IPFlushRepository::ip_xdr_flush_f_1_t_9, IPFlushRepository::ip_xdr_flush_f_1_t_9_cnt);
			writeIpCsvData(IPFlushRepository::ip_xdr_flush_f_2_t_9, IPFlushRepository::ip_xdr_flush_f_2_t_9_cnt);
			writeIpCsvData(IPFlushRepository::ip_xdr_flush_f_3_t_9, IPFlushRepository::ip_xdr_flush_f_3_t_9_cnt);
			break;
	}
}

VOID S1UXdrWriter::openIpCsvXdrFile(int currentMin, int currentHour, int currentDay, int currentMonth, int currentYear)
{
	TCHAR filePath[300];
	filePath[0] = 0;

	sprintf(filePath, "%s%s/%s_%d-%02d-%02d-%02d-%02d.csv",
					GContainer::config->XDR_DIR.c_str(),
					IPGlobal::S1U_FILE_PREFIX.c_str(),
					IPGlobal::S1U_FILE_PREFIX.c_str(),
					currentYear,
					currentMonth,
					currentDay,
					currentHour,
					currentMin);
	IpXdrHandler.open((char *)filePath, ios :: out | ios :: app);

	if(IpXdrHandler.fail()) {
//		TheLog_v1(Log::Warn, "IPFlusher.cpp", " [%s] GTPc Csv file Open failed. !!!", filePath);
	} else {
//		TheLog_v1(Log::Debug, "IPFlusher.cpp", " [%s] GTPc Csv file Open Success. !!!", filePath);
	}

	filePath[0] = 0;
}

VOID S1UXdrWriter::closeIpCsvXdrFile()
{
	IpXdrHandler.close();
}
