/*
 * DNSXdrWriter.cpp
 *
 *  Created on: 19-Sep-2019
 *      Author: singh
 */

#include "DNSXdrWriter.h"

DNSXdrWriter::DNSXdrWriter() {
	this->_name = "DNSXdrFlusher";
	this->setLogLevel(Log::theLog().level());
}

DNSXdrWriter::~DNSXdrWriter() {
}

BOOL DNSXdrWriter::isRepositoryInitialized() {
	return repoInitStatus;
}

VOID DNSXdrWriter::run()
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

	while(IPGlobal::DNS_XDR_FLUSHER_RUNNING_STATUS)
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

			strcpy(csvXdr, "");

			if(IPGlobal::DNS_WRITE_XDR)
			{
				openDnsCsvXdrFile(currentMin, currentHour, currentDay, currentMonth, currentYear);
				processDns(lastProcessedIndex);
				closeDnsCsvXdrFile();
			}
			lastProcessedIndex = PKT_READ_NEXT_TIME_INDEX(lastProcessedIndex, 10);
		}
	}
	printf("\nDNSXdr Flusher Shutdown Completed\n");
}

VOID DNSXdrWriter::writeDnsCsvData(std::unordered_map<int, xdrStore> &dns_flush_map, int &dns_xdr_flush_map_cnt)
{
//	int totalFlushCount = dns_xdr_flush_map_cnt;

	int totalFlushCount = dns_flush_map.size();

	if(totalFlushCount > 0)
	{
		for(int i=0; i<totalFlushCount; i++)
		{
			DnsXdrHandler << std::string(dns_flush_map[i].xdr) << endl;
			dns_flush_map.erase(i);
			dns_xdr_flush_map_cnt--;
		}
		dns_flush_map.clear();
	}
	dns_xdr_flush_map_cnt = 0;
}

VOID DNSXdrWriter::processDns(int index)
{
	switch(index)
	{
		case 0:
			writeDnsCsvData(IPFlushRepository::dns_xdr_flush_f_0_t_0, IPFlushRepository::dns_xdr_flush_f_0_t_0_cnt);
			writeDnsCsvData(IPFlushRepository::dns_xdr_flush_f_1_t_0, IPFlushRepository::dns_xdr_flush_f_1_t_0_cnt);
			writeDnsCsvData(IPFlushRepository::dns_xdr_flush_f_2_t_0, IPFlushRepository::dns_xdr_flush_f_2_t_0_cnt);
			writeDnsCsvData(IPFlushRepository::dns_xdr_flush_f_3_t_0, IPFlushRepository::dns_xdr_flush_f_3_t_0_cnt);
			break;

		case 1:
			writeDnsCsvData(IPFlushRepository::dns_xdr_flush_f_0_t_1, IPFlushRepository::dns_xdr_flush_f_0_t_1_cnt);
			writeDnsCsvData(IPFlushRepository::dns_xdr_flush_f_1_t_1, IPFlushRepository::dns_xdr_flush_f_1_t_1_cnt);
			writeDnsCsvData(IPFlushRepository::dns_xdr_flush_f_2_t_1, IPFlushRepository::dns_xdr_flush_f_2_t_1_cnt);
			writeDnsCsvData(IPFlushRepository::dns_xdr_flush_f_3_t_1, IPFlushRepository::dns_xdr_flush_f_3_t_1_cnt);
			break;

		case 2:
			writeDnsCsvData(IPFlushRepository::dns_xdr_flush_f_0_t_2, IPFlushRepository::dns_xdr_flush_f_0_t_2_cnt);
			writeDnsCsvData(IPFlushRepository::dns_xdr_flush_f_1_t_2, IPFlushRepository::dns_xdr_flush_f_1_t_2_cnt);
			writeDnsCsvData(IPFlushRepository::dns_xdr_flush_f_2_t_2, IPFlushRepository::dns_xdr_flush_f_2_t_2_cnt);
			writeDnsCsvData(IPFlushRepository::dns_xdr_flush_f_3_t_2, IPFlushRepository::dns_xdr_flush_f_3_t_2_cnt);
			break;

		case 3:
			writeDnsCsvData(IPFlushRepository::dns_xdr_flush_f_0_t_3, IPFlushRepository::dns_xdr_flush_f_0_t_3_cnt);
			writeDnsCsvData(IPFlushRepository::dns_xdr_flush_f_1_t_3, IPFlushRepository::dns_xdr_flush_f_1_t_3_cnt);
			writeDnsCsvData(IPFlushRepository::dns_xdr_flush_f_2_t_3, IPFlushRepository::dns_xdr_flush_f_2_t_3_cnt);
			writeDnsCsvData(IPFlushRepository::dns_xdr_flush_f_3_t_3, IPFlushRepository::dns_xdr_flush_f_3_t_3_cnt);
			break;

		case 4:
			writeDnsCsvData(IPFlushRepository::dns_xdr_flush_f_0_t_4, IPFlushRepository::dns_xdr_flush_f_0_t_4_cnt);
			writeDnsCsvData(IPFlushRepository::dns_xdr_flush_f_1_t_4, IPFlushRepository::dns_xdr_flush_f_1_t_4_cnt);
			writeDnsCsvData(IPFlushRepository::dns_xdr_flush_f_2_t_4, IPFlushRepository::dns_xdr_flush_f_2_t_4_cnt);
			writeDnsCsvData(IPFlushRepository::dns_xdr_flush_f_3_t_4, IPFlushRepository::dns_xdr_flush_f_3_t_4_cnt);
			break;

		case 5:
			writeDnsCsvData(IPFlushRepository::dns_xdr_flush_f_0_t_5, IPFlushRepository::dns_xdr_flush_f_0_t_5_cnt);
			writeDnsCsvData(IPFlushRepository::dns_xdr_flush_f_1_t_5, IPFlushRepository::dns_xdr_flush_f_1_t_5_cnt);
			writeDnsCsvData(IPFlushRepository::dns_xdr_flush_f_2_t_5, IPFlushRepository::dns_xdr_flush_f_2_t_5_cnt);
			writeDnsCsvData(IPFlushRepository::dns_xdr_flush_f_3_t_5, IPFlushRepository::dns_xdr_flush_f_3_t_5_cnt);
			break;

		case 6:
			writeDnsCsvData(IPFlushRepository::dns_xdr_flush_f_0_t_6, IPFlushRepository::dns_xdr_flush_f_0_t_6_cnt);
			writeDnsCsvData(IPFlushRepository::dns_xdr_flush_f_1_t_6, IPFlushRepository::dns_xdr_flush_f_1_t_6_cnt);
			writeDnsCsvData(IPFlushRepository::dns_xdr_flush_f_2_t_6, IPFlushRepository::dns_xdr_flush_f_2_t_6_cnt);
			writeDnsCsvData(IPFlushRepository::dns_xdr_flush_f_3_t_6, IPFlushRepository::dns_xdr_flush_f_3_t_6_cnt);
			break;

		case 7:
			writeDnsCsvData(IPFlushRepository::dns_xdr_flush_f_0_t_7, IPFlushRepository::dns_xdr_flush_f_0_t_7_cnt);
			writeDnsCsvData(IPFlushRepository::dns_xdr_flush_f_1_t_7, IPFlushRepository::dns_xdr_flush_f_1_t_7_cnt);
			writeDnsCsvData(IPFlushRepository::dns_xdr_flush_f_2_t_7, IPFlushRepository::dns_xdr_flush_f_2_t_7_cnt);
			writeDnsCsvData(IPFlushRepository::dns_xdr_flush_f_3_t_7, IPFlushRepository::dns_xdr_flush_f_3_t_7_cnt);
			break;

		case 8:
			writeDnsCsvData(IPFlushRepository::dns_xdr_flush_f_0_t_8, IPFlushRepository::dns_xdr_flush_f_0_t_8_cnt);
			writeDnsCsvData(IPFlushRepository::dns_xdr_flush_f_1_t_8, IPFlushRepository::dns_xdr_flush_f_1_t_8_cnt);
			writeDnsCsvData(IPFlushRepository::dns_xdr_flush_f_2_t_8, IPFlushRepository::dns_xdr_flush_f_2_t_8_cnt);
			writeDnsCsvData(IPFlushRepository::dns_xdr_flush_f_3_t_8, IPFlushRepository::dns_xdr_flush_f_3_t_8_cnt);
			break;

		case 9:
			writeDnsCsvData(IPFlushRepository::dns_xdr_flush_f_0_t_9, IPFlushRepository::dns_xdr_flush_f_0_t_9_cnt);
			writeDnsCsvData(IPFlushRepository::dns_xdr_flush_f_1_t_9, IPFlushRepository::dns_xdr_flush_f_1_t_9_cnt);
			writeDnsCsvData(IPFlushRepository::dns_xdr_flush_f_2_t_9, IPFlushRepository::dns_xdr_flush_f_2_t_9_cnt);
			writeDnsCsvData(IPFlushRepository::dns_xdr_flush_f_3_t_9, IPFlushRepository::dns_xdr_flush_f_3_t_9_cnt);
			break;
	}
}

VOID DNSXdrWriter::openDnsCsvXdrFile(int currentMin, int currentHour, int currentDay, int currentMonth, int currentYear)
{
	TCHAR filePath[300];
	filePath[0] = 0;

	sprintf(filePath, "%s%s/%s_%d-%02d-%02d-%02d-%02d.csv",
					GContainer::config->XDR_DIR.c_str(),
					IPGlobal::DNS_FILE_PREFIX.c_str(),
					IPGlobal::DNS_FILE_PREFIX.c_str(),
					currentYear,
					currentMonth,
					currentDay,
					currentHour,
					currentMin);
	DnsXdrHandler.open((char *)filePath, ios :: out | ios :: app);

	if(DnsXdrHandler.fail()) {
//		TheLog_v1(Log::Warn, "IPFlusher.cpp", " [%s] GTPc Csv file Open failed. !!!", filePath);
	} else {
//		TheLog_v1(Log::Debug, "IPFlusher.cpp", " [%s] GTPc Csv file Open Success. !!!", filePath);
	}

	filePath[0] = 0;
}

VOID DNSXdrWriter::closeDnsCsvXdrFile()
{
	DnsXdrHandler.close();
}
