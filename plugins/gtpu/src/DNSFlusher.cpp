/*
 * DNSFlusher.cpp
 *
 *  Created on: 17-Sep-2019
 *      Author: singh
 */

#include "DNSFlusher.h"

DNSFlusher::DNSFlusher(int id) {
	_thisLogLevel = 0;
	this->_name = "DNSFlusher";
	this->setLogLevel(Log::theLog().level());
	this->InstanceId = id;
	tcpFlusherUtility = new TCPFlusherUtility(1);
}

DNSFlusher::~DNSFlusher() {
	delete(tcpFlusherUtility);
}

VOID DNSFlusher::run()
{
	int lastProcessedIndex = -1;
	int curIndex = -1;
	repoInitStatus = true;

	lastProcessedIndex = 0;

	curIndex = PKT_READ_TIME_INDEX(IPGlobal::CURRENT_EPOCH_SEC ,10);

	lastProcessedIndex = curIndex;

	while(IPGlobal::DNS_FLUSHER_RUNNING_STATUS)
	{
		usleep(50000);
		curIndex = PKT_READ_TIME_INDEX(IPGlobal::CURRENT_EPOCH_SEC, 10);

		while(lastProcessedIndex != curIndex)
		{
			usleep(25000);
//			IPGlobal::lastFlusherEpochTimeSec = IPGlobal::CURRENT_EPOCH_SEC;

			processStartEpochSec = IPGlobal::CURRENT_EPOCH_SEC;

			/* Flush DNS Data */
			strcpy(csvXdr, "");
			processDNSData(lastProcessedIndex);

			lastProcessedIndex = PKT_READ_NEXT_TIME_INDEX(lastProcessedIndex, 10);
		}
	}
	printf("\nTCP/DNS Flusher Shutdown Completed [%02d]\n", this->InstanceId);
}

VOID DNSFlusher::processDNSData(int index)
{
	switch(this->InstanceId)
	{
		case 0:
			processDNSData_f_0(index);
			break;
		case 1:
			processDNSData_f_1(index);
			break;
		case 2:
			processDNSData_f_2(index);
			break;
		case 3:
			processDNSData_f_3(index);
			break;

	}
}

VOID DNSFlusher::flushDNSData_sm_t(std::unordered_map<int, dnsSession> &flushMap, int &dnsFlushMap_sm_cnt)
{
//	int cnt = dnsFlushMap_sm_cnt;
	int cnt = flushMap.size();

	for(int i=0; i<cnt; i++)
	{
		buildCSVDataDns(&flushMap[i]);
		strcpy(objXdrStore.xdr, csvXdr);
		flushDNSCsvRecords();
//		flushMap[i].reset();
		flushMap.erase(i);
		dnsFlushMap_sm_cnt--;
	}
	flushMap.clear();
	dnsFlushMap_sm_cnt = 0;
}

VOID DNSFlusher::buildCSVDataDns(dnsSession *pDnsSession)
{
	csvXdr[0] = 0;
	tcpFlusherUtility->buildDnsCsvBuffer(pDnsSession, csvXdr);
}

VOID DNSFlusher::processDNSData_f_0(int index)
{
	switch(index)
	{
		case 0:
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_0_t_0, IPFlushRepository::dnsFlushMap_f_0_sm_0_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_1_t_0, IPFlushRepository::dnsFlushMap_f_0_sm_1_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_2_t_0, IPFlushRepository::dnsFlushMap_f_0_sm_2_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_3_t_0, IPFlushRepository::dnsFlushMap_f_0_sm_3_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_4_t_0, IPFlushRepository::dnsFlushMap_f_0_sm_4_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_5_t_0, IPFlushRepository::dnsFlushMap_f_0_sm_5_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_6_t_0, IPFlushRepository::dnsFlushMap_f_0_sm_6_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_7_t_0, IPFlushRepository::dnsFlushMap_f_0_sm_7_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_8_t_0, IPFlushRepository::dnsFlushMap_f_0_sm_8_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_9_t_0, IPFlushRepository::dnsFlushMap_f_0_sm_9_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_10_t_0, IPFlushRepository::dnsFlushMap_f_0_sm_10_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_11_t_0, IPFlushRepository::dnsFlushMap_f_0_sm_11_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_12_t_0, IPFlushRepository::dnsFlushMap_f_0_sm_12_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_13_t_0, IPFlushRepository::dnsFlushMap_f_0_sm_13_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_14_t_0, IPFlushRepository::dnsFlushMap_f_0_sm_14_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_15_t_0, IPFlushRepository::dnsFlushMap_f_0_sm_15_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_16_t_0, IPFlushRepository::dnsFlushMap_f_0_sm_16_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_17_t_0, IPFlushRepository::dnsFlushMap_f_0_sm_17_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_18_t_0, IPFlushRepository::dnsFlushMap_f_0_sm_18_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_19_t_0, IPFlushRepository::dnsFlushMap_f_0_sm_19_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_20_t_0, IPFlushRepository::dnsFlushMap_f_0_sm_20_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_21_t_0, IPFlushRepository::dnsFlushMap_f_0_sm_21_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_22_t_0, IPFlushRepository::dnsFlushMap_f_0_sm_22_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_23_t_0, IPFlushRepository::dnsFlushMap_f_0_sm_23_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_24_t_0, IPFlushRepository::dnsFlushMap_f_0_sm_24_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_25_t_0, IPFlushRepository::dnsFlushMap_f_0_sm_25_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_26_t_0, IPFlushRepository::dnsFlushMap_f_0_sm_26_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_27_t_0, IPFlushRepository::dnsFlushMap_f_0_sm_27_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_28_t_0, IPFlushRepository::dnsFlushMap_f_0_sm_28_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_29_t_0, IPFlushRepository::dnsFlushMap_f_0_sm_29_t_0_cnt);

			break;

		case 1:
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_0_t_1, IPFlushRepository::dnsFlushMap_f_0_sm_0_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_1_t_1, IPFlushRepository::dnsFlushMap_f_0_sm_1_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_2_t_1, IPFlushRepository::dnsFlushMap_f_0_sm_2_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_3_t_1, IPFlushRepository::dnsFlushMap_f_0_sm_3_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_4_t_1, IPFlushRepository::dnsFlushMap_f_0_sm_4_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_5_t_1, IPFlushRepository::dnsFlushMap_f_0_sm_5_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_6_t_1, IPFlushRepository::dnsFlushMap_f_0_sm_6_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_7_t_1, IPFlushRepository::dnsFlushMap_f_0_sm_7_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_8_t_1, IPFlushRepository::dnsFlushMap_f_0_sm_8_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_9_t_1, IPFlushRepository::dnsFlushMap_f_0_sm_9_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_10_t_1, IPFlushRepository::dnsFlushMap_f_0_sm_10_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_11_t_1, IPFlushRepository::dnsFlushMap_f_0_sm_11_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_12_t_1, IPFlushRepository::dnsFlushMap_f_0_sm_12_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_13_t_1, IPFlushRepository::dnsFlushMap_f_0_sm_13_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_14_t_1, IPFlushRepository::dnsFlushMap_f_0_sm_14_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_15_t_1, IPFlushRepository::dnsFlushMap_f_0_sm_15_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_16_t_1, IPFlushRepository::dnsFlushMap_f_0_sm_16_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_17_t_1, IPFlushRepository::dnsFlushMap_f_0_sm_17_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_18_t_1, IPFlushRepository::dnsFlushMap_f_0_sm_18_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_19_t_1, IPFlushRepository::dnsFlushMap_f_0_sm_19_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_20_t_1, IPFlushRepository::dnsFlushMap_f_0_sm_20_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_21_t_1, IPFlushRepository::dnsFlushMap_f_0_sm_21_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_22_t_1, IPFlushRepository::dnsFlushMap_f_0_sm_22_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_23_t_1, IPFlushRepository::dnsFlushMap_f_0_sm_23_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_24_t_1, IPFlushRepository::dnsFlushMap_f_0_sm_24_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_25_t_1, IPFlushRepository::dnsFlushMap_f_0_sm_25_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_26_t_1, IPFlushRepository::dnsFlushMap_f_0_sm_26_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_27_t_1, IPFlushRepository::dnsFlushMap_f_0_sm_27_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_28_t_1, IPFlushRepository::dnsFlushMap_f_0_sm_28_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_29_t_1, IPFlushRepository::dnsFlushMap_f_0_sm_29_t_1_cnt);

			break;

		case 2:
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_0_t_2, IPFlushRepository::dnsFlushMap_f_0_sm_0_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_1_t_2, IPFlushRepository::dnsFlushMap_f_0_sm_1_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_2_t_2, IPFlushRepository::dnsFlushMap_f_0_sm_2_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_3_t_2, IPFlushRepository::dnsFlushMap_f_0_sm_3_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_4_t_2, IPFlushRepository::dnsFlushMap_f_0_sm_4_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_5_t_2, IPFlushRepository::dnsFlushMap_f_0_sm_5_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_6_t_2, IPFlushRepository::dnsFlushMap_f_0_sm_6_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_7_t_2, IPFlushRepository::dnsFlushMap_f_0_sm_7_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_8_t_2, IPFlushRepository::dnsFlushMap_f_0_sm_8_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_9_t_2, IPFlushRepository::dnsFlushMap_f_0_sm_9_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_10_t_2, IPFlushRepository::dnsFlushMap_f_0_sm_10_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_11_t_2, IPFlushRepository::dnsFlushMap_f_0_sm_11_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_12_t_2, IPFlushRepository::dnsFlushMap_f_0_sm_12_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_13_t_2, IPFlushRepository::dnsFlushMap_f_0_sm_13_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_14_t_2, IPFlushRepository::dnsFlushMap_f_0_sm_14_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_15_t_2, IPFlushRepository::dnsFlushMap_f_0_sm_15_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_16_t_2, IPFlushRepository::dnsFlushMap_f_0_sm_16_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_17_t_2, IPFlushRepository::dnsFlushMap_f_0_sm_17_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_18_t_2, IPFlushRepository::dnsFlushMap_f_0_sm_18_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_19_t_2, IPFlushRepository::dnsFlushMap_f_0_sm_19_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_20_t_2, IPFlushRepository::dnsFlushMap_f_0_sm_20_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_21_t_2, IPFlushRepository::dnsFlushMap_f_0_sm_21_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_22_t_2, IPFlushRepository::dnsFlushMap_f_0_sm_22_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_23_t_2, IPFlushRepository::dnsFlushMap_f_0_sm_23_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_24_t_2, IPFlushRepository::dnsFlushMap_f_0_sm_24_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_25_t_2, IPFlushRepository::dnsFlushMap_f_0_sm_25_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_26_t_2, IPFlushRepository::dnsFlushMap_f_0_sm_26_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_27_t_2, IPFlushRepository::dnsFlushMap_f_0_sm_27_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_28_t_2, IPFlushRepository::dnsFlushMap_f_0_sm_28_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_29_t_2, IPFlushRepository::dnsFlushMap_f_0_sm_29_t_2_cnt);

			break;

		case 3:
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_0_t_3, IPFlushRepository::dnsFlushMap_f_0_sm_0_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_1_t_3, IPFlushRepository::dnsFlushMap_f_0_sm_1_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_2_t_3, IPFlushRepository::dnsFlushMap_f_0_sm_2_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_3_t_3, IPFlushRepository::dnsFlushMap_f_0_sm_3_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_4_t_3, IPFlushRepository::dnsFlushMap_f_0_sm_4_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_5_t_3, IPFlushRepository::dnsFlushMap_f_0_sm_5_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_6_t_3, IPFlushRepository::dnsFlushMap_f_0_sm_6_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_7_t_3, IPFlushRepository::dnsFlushMap_f_0_sm_7_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_8_t_3, IPFlushRepository::dnsFlushMap_f_0_sm_8_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_9_t_3, IPFlushRepository::dnsFlushMap_f_0_sm_9_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_10_t_3, IPFlushRepository::dnsFlushMap_f_0_sm_10_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_11_t_3, IPFlushRepository::dnsFlushMap_f_0_sm_11_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_12_t_3, IPFlushRepository::dnsFlushMap_f_0_sm_12_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_13_t_3, IPFlushRepository::dnsFlushMap_f_0_sm_13_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_14_t_3, IPFlushRepository::dnsFlushMap_f_0_sm_14_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_15_t_3, IPFlushRepository::dnsFlushMap_f_0_sm_15_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_16_t_3, IPFlushRepository::dnsFlushMap_f_0_sm_16_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_17_t_3, IPFlushRepository::dnsFlushMap_f_0_sm_17_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_18_t_3, IPFlushRepository::dnsFlushMap_f_0_sm_18_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_19_t_3, IPFlushRepository::dnsFlushMap_f_0_sm_19_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_20_t_3, IPFlushRepository::dnsFlushMap_f_0_sm_20_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_21_t_3, IPFlushRepository::dnsFlushMap_f_0_sm_21_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_22_t_3, IPFlushRepository::dnsFlushMap_f_0_sm_22_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_23_t_3, IPFlushRepository::dnsFlushMap_f_0_sm_23_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_24_t_3, IPFlushRepository::dnsFlushMap_f_0_sm_24_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_25_t_3, IPFlushRepository::dnsFlushMap_f_0_sm_25_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_26_t_3, IPFlushRepository::dnsFlushMap_f_0_sm_26_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_27_t_3, IPFlushRepository::dnsFlushMap_f_0_sm_27_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_28_t_3, IPFlushRepository::dnsFlushMap_f_0_sm_28_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_29_t_3, IPFlushRepository::dnsFlushMap_f_0_sm_29_t_3_cnt);

			break;

		case 4:
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_0_t_4, IPFlushRepository::dnsFlushMap_f_0_sm_0_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_1_t_4, IPFlushRepository::dnsFlushMap_f_0_sm_1_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_2_t_4, IPFlushRepository::dnsFlushMap_f_0_sm_2_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_3_t_4, IPFlushRepository::dnsFlushMap_f_0_sm_3_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_4_t_4, IPFlushRepository::dnsFlushMap_f_0_sm_4_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_5_t_4, IPFlushRepository::dnsFlushMap_f_0_sm_5_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_6_t_4, IPFlushRepository::dnsFlushMap_f_0_sm_6_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_7_t_4, IPFlushRepository::dnsFlushMap_f_0_sm_7_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_8_t_4, IPFlushRepository::dnsFlushMap_f_0_sm_8_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_9_t_4, IPFlushRepository::dnsFlushMap_f_0_sm_9_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_10_t_4, IPFlushRepository::dnsFlushMap_f_0_sm_10_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_11_t_4, IPFlushRepository::dnsFlushMap_f_0_sm_11_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_12_t_4, IPFlushRepository::dnsFlushMap_f_0_sm_12_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_13_t_4, IPFlushRepository::dnsFlushMap_f_0_sm_13_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_14_t_4, IPFlushRepository::dnsFlushMap_f_0_sm_14_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_15_t_4, IPFlushRepository::dnsFlushMap_f_0_sm_15_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_16_t_4, IPFlushRepository::dnsFlushMap_f_0_sm_16_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_17_t_4, IPFlushRepository::dnsFlushMap_f_0_sm_17_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_18_t_4, IPFlushRepository::dnsFlushMap_f_0_sm_18_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_19_t_4, IPFlushRepository::dnsFlushMap_f_0_sm_19_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_20_t_4, IPFlushRepository::dnsFlushMap_f_0_sm_20_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_21_t_4, IPFlushRepository::dnsFlushMap_f_0_sm_21_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_22_t_4, IPFlushRepository::dnsFlushMap_f_0_sm_22_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_23_t_4, IPFlushRepository::dnsFlushMap_f_0_sm_23_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_24_t_4, IPFlushRepository::dnsFlushMap_f_0_sm_24_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_25_t_4, IPFlushRepository::dnsFlushMap_f_0_sm_25_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_26_t_4, IPFlushRepository::dnsFlushMap_f_0_sm_26_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_27_t_4, IPFlushRepository::dnsFlushMap_f_0_sm_27_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_28_t_4, IPFlushRepository::dnsFlushMap_f_0_sm_28_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_29_t_4, IPFlushRepository::dnsFlushMap_f_0_sm_29_t_4_cnt);

			break;

		case 5:
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_0_t_5, IPFlushRepository::dnsFlushMap_f_0_sm_0_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_1_t_5, IPFlushRepository::dnsFlushMap_f_0_sm_1_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_2_t_5, IPFlushRepository::dnsFlushMap_f_0_sm_2_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_3_t_5, IPFlushRepository::dnsFlushMap_f_0_sm_3_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_4_t_5, IPFlushRepository::dnsFlushMap_f_0_sm_4_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_5_t_5, IPFlushRepository::dnsFlushMap_f_0_sm_5_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_6_t_5, IPFlushRepository::dnsFlushMap_f_0_sm_6_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_7_t_5, IPFlushRepository::dnsFlushMap_f_0_sm_7_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_8_t_5, IPFlushRepository::dnsFlushMap_f_0_sm_8_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_9_t_5, IPFlushRepository::dnsFlushMap_f_0_sm_9_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_10_t_5, IPFlushRepository::dnsFlushMap_f_0_sm_10_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_11_t_5, IPFlushRepository::dnsFlushMap_f_0_sm_11_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_12_t_5, IPFlushRepository::dnsFlushMap_f_0_sm_12_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_13_t_5, IPFlushRepository::dnsFlushMap_f_0_sm_13_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_14_t_5, IPFlushRepository::dnsFlushMap_f_0_sm_14_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_15_t_5, IPFlushRepository::dnsFlushMap_f_0_sm_15_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_16_t_5, IPFlushRepository::dnsFlushMap_f_0_sm_16_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_17_t_5, IPFlushRepository::dnsFlushMap_f_0_sm_17_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_18_t_5, IPFlushRepository::dnsFlushMap_f_0_sm_18_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_19_t_5, IPFlushRepository::dnsFlushMap_f_0_sm_19_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_20_t_5, IPFlushRepository::dnsFlushMap_f_0_sm_20_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_21_t_5, IPFlushRepository::dnsFlushMap_f_0_sm_21_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_22_t_5, IPFlushRepository::dnsFlushMap_f_0_sm_22_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_23_t_5, IPFlushRepository::dnsFlushMap_f_0_sm_23_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_24_t_5, IPFlushRepository::dnsFlushMap_f_0_sm_24_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_25_t_5, IPFlushRepository::dnsFlushMap_f_0_sm_25_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_26_t_5, IPFlushRepository::dnsFlushMap_f_0_sm_26_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_27_t_5, IPFlushRepository::dnsFlushMap_f_0_sm_27_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_28_t_5, IPFlushRepository::dnsFlushMap_f_0_sm_28_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_29_t_5, IPFlushRepository::dnsFlushMap_f_0_sm_29_t_5_cnt);

			break;

		case 6:
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_0_t_6, IPFlushRepository::dnsFlushMap_f_0_sm_0_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_1_t_6, IPFlushRepository::dnsFlushMap_f_0_sm_1_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_2_t_6, IPFlushRepository::dnsFlushMap_f_0_sm_2_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_3_t_6, IPFlushRepository::dnsFlushMap_f_0_sm_3_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_4_t_6, IPFlushRepository::dnsFlushMap_f_0_sm_4_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_5_t_6, IPFlushRepository::dnsFlushMap_f_0_sm_5_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_6_t_6, IPFlushRepository::dnsFlushMap_f_0_sm_6_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_7_t_6, IPFlushRepository::dnsFlushMap_f_0_sm_7_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_8_t_6, IPFlushRepository::dnsFlushMap_f_0_sm_8_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_9_t_6, IPFlushRepository::dnsFlushMap_f_0_sm_9_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_10_t_6, IPFlushRepository::dnsFlushMap_f_0_sm_10_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_11_t_6, IPFlushRepository::dnsFlushMap_f_0_sm_11_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_12_t_6, IPFlushRepository::dnsFlushMap_f_0_sm_12_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_13_t_6, IPFlushRepository::dnsFlushMap_f_0_sm_13_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_14_t_6, IPFlushRepository::dnsFlushMap_f_0_sm_14_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_15_t_6, IPFlushRepository::dnsFlushMap_f_0_sm_15_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_16_t_6, IPFlushRepository::dnsFlushMap_f_0_sm_16_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_17_t_6, IPFlushRepository::dnsFlushMap_f_0_sm_17_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_18_t_6, IPFlushRepository::dnsFlushMap_f_0_sm_18_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_19_t_6, IPFlushRepository::dnsFlushMap_f_0_sm_19_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_20_t_6, IPFlushRepository::dnsFlushMap_f_0_sm_20_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_21_t_6, IPFlushRepository::dnsFlushMap_f_0_sm_21_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_22_t_6, IPFlushRepository::dnsFlushMap_f_0_sm_22_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_23_t_6, IPFlushRepository::dnsFlushMap_f_0_sm_23_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_24_t_6, IPFlushRepository::dnsFlushMap_f_0_sm_24_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_25_t_6, IPFlushRepository::dnsFlushMap_f_0_sm_25_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_26_t_6, IPFlushRepository::dnsFlushMap_f_0_sm_26_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_27_t_6, IPFlushRepository::dnsFlushMap_f_0_sm_27_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_28_t_6, IPFlushRepository::dnsFlushMap_f_0_sm_28_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_29_t_6, IPFlushRepository::dnsFlushMap_f_0_sm_29_t_6_cnt);

			break;

		case 7:
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_0_t_7, IPFlushRepository::dnsFlushMap_f_0_sm_0_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_1_t_7, IPFlushRepository::dnsFlushMap_f_0_sm_1_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_2_t_7, IPFlushRepository::dnsFlushMap_f_0_sm_2_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_3_t_7, IPFlushRepository::dnsFlushMap_f_0_sm_3_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_4_t_7, IPFlushRepository::dnsFlushMap_f_0_sm_4_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_5_t_7, IPFlushRepository::dnsFlushMap_f_0_sm_5_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_6_t_7, IPFlushRepository::dnsFlushMap_f_0_sm_6_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_7_t_7, IPFlushRepository::dnsFlushMap_f_0_sm_7_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_8_t_7, IPFlushRepository::dnsFlushMap_f_0_sm_8_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_9_t_7, IPFlushRepository::dnsFlushMap_f_0_sm_9_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_10_t_7, IPFlushRepository::dnsFlushMap_f_0_sm_10_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_11_t_7, IPFlushRepository::dnsFlushMap_f_0_sm_11_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_12_t_7, IPFlushRepository::dnsFlushMap_f_0_sm_12_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_13_t_7, IPFlushRepository::dnsFlushMap_f_0_sm_13_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_14_t_7, IPFlushRepository::dnsFlushMap_f_0_sm_14_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_15_t_7, IPFlushRepository::dnsFlushMap_f_0_sm_15_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_16_t_7, IPFlushRepository::dnsFlushMap_f_0_sm_16_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_17_t_7, IPFlushRepository::dnsFlushMap_f_0_sm_17_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_18_t_7, IPFlushRepository::dnsFlushMap_f_0_sm_18_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_19_t_7, IPFlushRepository::dnsFlushMap_f_0_sm_19_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_20_t_7, IPFlushRepository::dnsFlushMap_f_0_sm_20_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_21_t_7, IPFlushRepository::dnsFlushMap_f_0_sm_21_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_22_t_7, IPFlushRepository::dnsFlushMap_f_0_sm_22_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_23_t_7, IPFlushRepository::dnsFlushMap_f_0_sm_23_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_24_t_7, IPFlushRepository::dnsFlushMap_f_0_sm_24_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_25_t_7, IPFlushRepository::dnsFlushMap_f_0_sm_25_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_26_t_7, IPFlushRepository::dnsFlushMap_f_0_sm_26_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_27_t_7, IPFlushRepository::dnsFlushMap_f_0_sm_27_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_28_t_7, IPFlushRepository::dnsFlushMap_f_0_sm_28_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_29_t_7, IPFlushRepository::dnsFlushMap_f_0_sm_29_t_7_cnt);

			break;

		case 8:
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_0_t_8, IPFlushRepository::dnsFlushMap_f_0_sm_0_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_1_t_8, IPFlushRepository::dnsFlushMap_f_0_sm_1_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_2_t_8, IPFlushRepository::dnsFlushMap_f_0_sm_2_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_3_t_8, IPFlushRepository::dnsFlushMap_f_0_sm_3_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_4_t_8, IPFlushRepository::dnsFlushMap_f_0_sm_4_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_5_t_8, IPFlushRepository::dnsFlushMap_f_0_sm_5_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_6_t_8, IPFlushRepository::dnsFlushMap_f_0_sm_6_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_7_t_8, IPFlushRepository::dnsFlushMap_f_0_sm_7_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_8_t_8, IPFlushRepository::dnsFlushMap_f_0_sm_8_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_9_t_8, IPFlushRepository::dnsFlushMap_f_0_sm_9_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_10_t_8, IPFlushRepository::dnsFlushMap_f_0_sm_10_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_11_t_8, IPFlushRepository::dnsFlushMap_f_0_sm_11_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_12_t_8, IPFlushRepository::dnsFlushMap_f_0_sm_12_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_13_t_8, IPFlushRepository::dnsFlushMap_f_0_sm_13_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_14_t_8, IPFlushRepository::dnsFlushMap_f_0_sm_14_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_15_t_8, IPFlushRepository::dnsFlushMap_f_0_sm_15_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_16_t_8, IPFlushRepository::dnsFlushMap_f_0_sm_16_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_17_t_8, IPFlushRepository::dnsFlushMap_f_0_sm_17_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_18_t_8, IPFlushRepository::dnsFlushMap_f_0_sm_18_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_19_t_8, IPFlushRepository::dnsFlushMap_f_0_sm_19_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_20_t_8, IPFlushRepository::dnsFlushMap_f_0_sm_20_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_21_t_8, IPFlushRepository::dnsFlushMap_f_0_sm_21_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_22_t_8, IPFlushRepository::dnsFlushMap_f_0_sm_22_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_23_t_8, IPFlushRepository::dnsFlushMap_f_0_sm_23_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_24_t_8, IPFlushRepository::dnsFlushMap_f_0_sm_24_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_25_t_8, IPFlushRepository::dnsFlushMap_f_0_sm_25_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_26_t_8, IPFlushRepository::dnsFlushMap_f_0_sm_26_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_27_t_8, IPFlushRepository::dnsFlushMap_f_0_sm_27_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_28_t_8, IPFlushRepository::dnsFlushMap_f_0_sm_28_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_29_t_8, IPFlushRepository::dnsFlushMap_f_0_sm_29_t_8_cnt);

			break;

		case 9:
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_0_t_9, IPFlushRepository::dnsFlushMap_f_0_sm_0_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_1_t_9, IPFlushRepository::dnsFlushMap_f_0_sm_1_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_2_t_9, IPFlushRepository::dnsFlushMap_f_0_sm_2_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_3_t_9, IPFlushRepository::dnsFlushMap_f_0_sm_3_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_4_t_9, IPFlushRepository::dnsFlushMap_f_0_sm_4_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_5_t_9, IPFlushRepository::dnsFlushMap_f_0_sm_5_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_6_t_9, IPFlushRepository::dnsFlushMap_f_0_sm_6_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_7_t_9, IPFlushRepository::dnsFlushMap_f_0_sm_7_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_8_t_9, IPFlushRepository::dnsFlushMap_f_0_sm_8_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_9_t_9, IPFlushRepository::dnsFlushMap_f_0_sm_9_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_10_t_9, IPFlushRepository::dnsFlushMap_f_0_sm_10_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_11_t_9, IPFlushRepository::dnsFlushMap_f_0_sm_11_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_12_t_9, IPFlushRepository::dnsFlushMap_f_0_sm_12_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_13_t_9, IPFlushRepository::dnsFlushMap_f_0_sm_13_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_14_t_9, IPFlushRepository::dnsFlushMap_f_0_sm_14_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_15_t_9, IPFlushRepository::dnsFlushMap_f_0_sm_15_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_16_t_9, IPFlushRepository::dnsFlushMap_f_0_sm_16_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_17_t_9, IPFlushRepository::dnsFlushMap_f_0_sm_17_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_18_t_9, IPFlushRepository::dnsFlushMap_f_0_sm_18_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_19_t_9, IPFlushRepository::dnsFlushMap_f_0_sm_19_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_20_t_9, IPFlushRepository::dnsFlushMap_f_0_sm_20_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_21_t_9, IPFlushRepository::dnsFlushMap_f_0_sm_21_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_22_t_9, IPFlushRepository::dnsFlushMap_f_0_sm_22_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_23_t_9, IPFlushRepository::dnsFlushMap_f_0_sm_23_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_24_t_9, IPFlushRepository::dnsFlushMap_f_0_sm_24_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_25_t_9, IPFlushRepository::dnsFlushMap_f_0_sm_25_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_26_t_9, IPFlushRepository::dnsFlushMap_f_0_sm_26_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_27_t_9, IPFlushRepository::dnsFlushMap_f_0_sm_27_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_28_t_9, IPFlushRepository::dnsFlushMap_f_0_sm_28_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_0_sm_29_t_9, IPFlushRepository::dnsFlushMap_f_0_sm_29_t_9_cnt);

			break;
	}
}

VOID DNSFlusher::processDNSData_f_1(int index)
{
	switch(index)
	{
		case 0:
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_0_t_0, IPFlushRepository::dnsFlushMap_f_1_sm_0_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_1_t_0, IPFlushRepository::dnsFlushMap_f_1_sm_1_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_2_t_0, IPFlushRepository::dnsFlushMap_f_1_sm_2_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_3_t_0, IPFlushRepository::dnsFlushMap_f_1_sm_3_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_4_t_0, IPFlushRepository::dnsFlushMap_f_1_sm_4_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_5_t_0, IPFlushRepository::dnsFlushMap_f_1_sm_5_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_6_t_0, IPFlushRepository::dnsFlushMap_f_1_sm_6_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_7_t_0, IPFlushRepository::dnsFlushMap_f_1_sm_7_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_8_t_0, IPFlushRepository::dnsFlushMap_f_1_sm_8_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_9_t_0, IPFlushRepository::dnsFlushMap_f_1_sm_9_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_10_t_0, IPFlushRepository::dnsFlushMap_f_1_sm_10_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_11_t_0, IPFlushRepository::dnsFlushMap_f_1_sm_11_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_12_t_0, IPFlushRepository::dnsFlushMap_f_1_sm_12_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_13_t_0, IPFlushRepository::dnsFlushMap_f_1_sm_13_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_14_t_0, IPFlushRepository::dnsFlushMap_f_1_sm_14_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_15_t_0, IPFlushRepository::dnsFlushMap_f_1_sm_15_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_16_t_0, IPFlushRepository::dnsFlushMap_f_1_sm_16_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_17_t_0, IPFlushRepository::dnsFlushMap_f_1_sm_17_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_18_t_0, IPFlushRepository::dnsFlushMap_f_1_sm_18_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_19_t_0, IPFlushRepository::dnsFlushMap_f_1_sm_19_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_20_t_0, IPFlushRepository::dnsFlushMap_f_1_sm_20_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_21_t_0, IPFlushRepository::dnsFlushMap_f_1_sm_21_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_22_t_0, IPFlushRepository::dnsFlushMap_f_1_sm_22_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_23_t_0, IPFlushRepository::dnsFlushMap_f_1_sm_23_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_24_t_0, IPFlushRepository::dnsFlushMap_f_1_sm_24_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_25_t_0, IPFlushRepository::dnsFlushMap_f_1_sm_25_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_26_t_0, IPFlushRepository::dnsFlushMap_f_1_sm_26_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_27_t_0, IPFlushRepository::dnsFlushMap_f_1_sm_27_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_28_t_0, IPFlushRepository::dnsFlushMap_f_1_sm_28_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_29_t_0, IPFlushRepository::dnsFlushMap_f_1_sm_29_t_0_cnt);

			break;

		case 1:
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_0_t_1, IPFlushRepository::dnsFlushMap_f_1_sm_0_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_1_t_1, IPFlushRepository::dnsFlushMap_f_1_sm_1_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_2_t_1, IPFlushRepository::dnsFlushMap_f_1_sm_2_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_3_t_1, IPFlushRepository::dnsFlushMap_f_1_sm_3_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_4_t_1, IPFlushRepository::dnsFlushMap_f_1_sm_4_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_5_t_1, IPFlushRepository::dnsFlushMap_f_1_sm_5_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_6_t_1, IPFlushRepository::dnsFlushMap_f_1_sm_6_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_7_t_1, IPFlushRepository::dnsFlushMap_f_1_sm_7_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_8_t_1, IPFlushRepository::dnsFlushMap_f_1_sm_8_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_9_t_1, IPFlushRepository::dnsFlushMap_f_1_sm_9_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_10_t_1, IPFlushRepository::dnsFlushMap_f_1_sm_10_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_11_t_1, IPFlushRepository::dnsFlushMap_f_1_sm_11_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_12_t_1, IPFlushRepository::dnsFlushMap_f_1_sm_12_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_13_t_1, IPFlushRepository::dnsFlushMap_f_1_sm_13_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_14_t_1, IPFlushRepository::dnsFlushMap_f_1_sm_14_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_15_t_1, IPFlushRepository::dnsFlushMap_f_1_sm_15_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_16_t_1, IPFlushRepository::dnsFlushMap_f_1_sm_16_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_17_t_1, IPFlushRepository::dnsFlushMap_f_1_sm_17_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_18_t_1, IPFlushRepository::dnsFlushMap_f_1_sm_18_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_19_t_1, IPFlushRepository::dnsFlushMap_f_1_sm_19_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_20_t_1, IPFlushRepository::dnsFlushMap_f_1_sm_20_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_21_t_1, IPFlushRepository::dnsFlushMap_f_1_sm_21_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_22_t_1, IPFlushRepository::dnsFlushMap_f_1_sm_22_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_23_t_1, IPFlushRepository::dnsFlushMap_f_1_sm_23_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_24_t_1, IPFlushRepository::dnsFlushMap_f_1_sm_24_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_25_t_1, IPFlushRepository::dnsFlushMap_f_1_sm_25_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_26_t_1, IPFlushRepository::dnsFlushMap_f_1_sm_26_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_27_t_1, IPFlushRepository::dnsFlushMap_f_1_sm_27_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_28_t_1, IPFlushRepository::dnsFlushMap_f_1_sm_28_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_29_t_1, IPFlushRepository::dnsFlushMap_f_1_sm_29_t_1_cnt);

			break;

		case 2:
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_0_t_2, IPFlushRepository::dnsFlushMap_f_1_sm_0_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_1_t_2, IPFlushRepository::dnsFlushMap_f_1_sm_1_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_2_t_2, IPFlushRepository::dnsFlushMap_f_1_sm_2_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_3_t_2, IPFlushRepository::dnsFlushMap_f_1_sm_3_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_4_t_2, IPFlushRepository::dnsFlushMap_f_1_sm_4_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_5_t_2, IPFlushRepository::dnsFlushMap_f_1_sm_5_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_6_t_2, IPFlushRepository::dnsFlushMap_f_1_sm_6_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_7_t_2, IPFlushRepository::dnsFlushMap_f_1_sm_7_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_8_t_2, IPFlushRepository::dnsFlushMap_f_1_sm_8_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_9_t_2, IPFlushRepository::dnsFlushMap_f_1_sm_9_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_10_t_2, IPFlushRepository::dnsFlushMap_f_1_sm_10_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_11_t_2, IPFlushRepository::dnsFlushMap_f_1_sm_11_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_12_t_2, IPFlushRepository::dnsFlushMap_f_1_sm_12_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_13_t_2, IPFlushRepository::dnsFlushMap_f_1_sm_13_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_14_t_2, IPFlushRepository::dnsFlushMap_f_1_sm_14_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_15_t_2, IPFlushRepository::dnsFlushMap_f_1_sm_15_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_16_t_2, IPFlushRepository::dnsFlushMap_f_1_sm_16_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_17_t_2, IPFlushRepository::dnsFlushMap_f_1_sm_17_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_18_t_2, IPFlushRepository::dnsFlushMap_f_1_sm_18_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_19_t_2, IPFlushRepository::dnsFlushMap_f_1_sm_19_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_20_t_2, IPFlushRepository::dnsFlushMap_f_1_sm_20_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_21_t_2, IPFlushRepository::dnsFlushMap_f_1_sm_21_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_22_t_2, IPFlushRepository::dnsFlushMap_f_1_sm_22_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_23_t_2, IPFlushRepository::dnsFlushMap_f_1_sm_23_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_24_t_2, IPFlushRepository::dnsFlushMap_f_1_sm_24_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_25_t_2, IPFlushRepository::dnsFlushMap_f_1_sm_25_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_26_t_2, IPFlushRepository::dnsFlushMap_f_1_sm_26_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_27_t_2, IPFlushRepository::dnsFlushMap_f_1_sm_27_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_28_t_2, IPFlushRepository::dnsFlushMap_f_1_sm_28_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_29_t_2, IPFlushRepository::dnsFlushMap_f_1_sm_29_t_2_cnt);

			break;

		case 3:
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_0_t_3, IPFlushRepository::dnsFlushMap_f_1_sm_0_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_1_t_3, IPFlushRepository::dnsFlushMap_f_1_sm_1_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_2_t_3, IPFlushRepository::dnsFlushMap_f_1_sm_2_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_3_t_3, IPFlushRepository::dnsFlushMap_f_1_sm_3_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_4_t_3, IPFlushRepository::dnsFlushMap_f_1_sm_4_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_5_t_3, IPFlushRepository::dnsFlushMap_f_1_sm_5_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_6_t_3, IPFlushRepository::dnsFlushMap_f_1_sm_6_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_7_t_3, IPFlushRepository::dnsFlushMap_f_1_sm_7_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_8_t_3, IPFlushRepository::dnsFlushMap_f_1_sm_8_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_9_t_3, IPFlushRepository::dnsFlushMap_f_1_sm_9_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_10_t_3, IPFlushRepository::dnsFlushMap_f_1_sm_10_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_11_t_3, IPFlushRepository::dnsFlushMap_f_1_sm_11_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_12_t_3, IPFlushRepository::dnsFlushMap_f_1_sm_12_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_13_t_3, IPFlushRepository::dnsFlushMap_f_1_sm_13_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_14_t_3, IPFlushRepository::dnsFlushMap_f_1_sm_14_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_15_t_3, IPFlushRepository::dnsFlushMap_f_1_sm_15_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_16_t_3, IPFlushRepository::dnsFlushMap_f_1_sm_16_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_17_t_3, IPFlushRepository::dnsFlushMap_f_1_sm_17_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_18_t_3, IPFlushRepository::dnsFlushMap_f_1_sm_18_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_19_t_3, IPFlushRepository::dnsFlushMap_f_1_sm_19_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_20_t_3, IPFlushRepository::dnsFlushMap_f_1_sm_20_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_21_t_3, IPFlushRepository::dnsFlushMap_f_1_sm_21_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_22_t_3, IPFlushRepository::dnsFlushMap_f_1_sm_22_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_23_t_3, IPFlushRepository::dnsFlushMap_f_1_sm_23_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_24_t_3, IPFlushRepository::dnsFlushMap_f_1_sm_24_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_25_t_3, IPFlushRepository::dnsFlushMap_f_1_sm_25_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_26_t_3, IPFlushRepository::dnsFlushMap_f_1_sm_26_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_27_t_3, IPFlushRepository::dnsFlushMap_f_1_sm_27_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_28_t_3, IPFlushRepository::dnsFlushMap_f_1_sm_28_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_29_t_3, IPFlushRepository::dnsFlushMap_f_1_sm_29_t_3_cnt);

			break;

		case 4:
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_0_t_4, IPFlushRepository::dnsFlushMap_f_1_sm_0_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_1_t_4, IPFlushRepository::dnsFlushMap_f_1_sm_1_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_2_t_4, IPFlushRepository::dnsFlushMap_f_1_sm_2_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_3_t_4, IPFlushRepository::dnsFlushMap_f_1_sm_3_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_4_t_4, IPFlushRepository::dnsFlushMap_f_1_sm_4_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_5_t_4, IPFlushRepository::dnsFlushMap_f_1_sm_5_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_6_t_4, IPFlushRepository::dnsFlushMap_f_1_sm_6_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_7_t_4, IPFlushRepository::dnsFlushMap_f_1_sm_7_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_8_t_4, IPFlushRepository::dnsFlushMap_f_1_sm_8_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_9_t_4, IPFlushRepository::dnsFlushMap_f_1_sm_9_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_10_t_4, IPFlushRepository::dnsFlushMap_f_1_sm_10_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_11_t_4, IPFlushRepository::dnsFlushMap_f_1_sm_11_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_12_t_4, IPFlushRepository::dnsFlushMap_f_1_sm_12_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_13_t_4, IPFlushRepository::dnsFlushMap_f_1_sm_13_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_14_t_4, IPFlushRepository::dnsFlushMap_f_1_sm_14_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_15_t_4, IPFlushRepository::dnsFlushMap_f_1_sm_15_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_16_t_4, IPFlushRepository::dnsFlushMap_f_1_sm_16_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_17_t_4, IPFlushRepository::dnsFlushMap_f_1_sm_17_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_18_t_4, IPFlushRepository::dnsFlushMap_f_1_sm_18_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_19_t_4, IPFlushRepository::dnsFlushMap_f_1_sm_19_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_20_t_4, IPFlushRepository::dnsFlushMap_f_1_sm_20_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_21_t_4, IPFlushRepository::dnsFlushMap_f_1_sm_21_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_22_t_4, IPFlushRepository::dnsFlushMap_f_1_sm_22_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_23_t_4, IPFlushRepository::dnsFlushMap_f_1_sm_23_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_24_t_4, IPFlushRepository::dnsFlushMap_f_1_sm_24_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_25_t_4, IPFlushRepository::dnsFlushMap_f_1_sm_25_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_26_t_4, IPFlushRepository::dnsFlushMap_f_1_sm_26_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_27_t_4, IPFlushRepository::dnsFlushMap_f_1_sm_27_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_28_t_4, IPFlushRepository::dnsFlushMap_f_1_sm_28_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_29_t_4, IPFlushRepository::dnsFlushMap_f_1_sm_29_t_4_cnt);

			break;

		case 5:
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_0_t_5, IPFlushRepository::dnsFlushMap_f_1_sm_0_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_1_t_5, IPFlushRepository::dnsFlushMap_f_1_sm_1_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_2_t_5, IPFlushRepository::dnsFlushMap_f_1_sm_2_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_3_t_5, IPFlushRepository::dnsFlushMap_f_1_sm_3_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_4_t_5, IPFlushRepository::dnsFlushMap_f_1_sm_4_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_5_t_5, IPFlushRepository::dnsFlushMap_f_1_sm_5_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_6_t_5, IPFlushRepository::dnsFlushMap_f_1_sm_6_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_7_t_5, IPFlushRepository::dnsFlushMap_f_1_sm_7_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_8_t_5, IPFlushRepository::dnsFlushMap_f_1_sm_8_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_9_t_5, IPFlushRepository::dnsFlushMap_f_1_sm_9_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_10_t_5, IPFlushRepository::dnsFlushMap_f_1_sm_10_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_11_t_5, IPFlushRepository::dnsFlushMap_f_1_sm_11_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_12_t_5, IPFlushRepository::dnsFlushMap_f_1_sm_12_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_13_t_5, IPFlushRepository::dnsFlushMap_f_1_sm_13_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_14_t_5, IPFlushRepository::dnsFlushMap_f_1_sm_14_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_15_t_5, IPFlushRepository::dnsFlushMap_f_1_sm_15_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_16_t_5, IPFlushRepository::dnsFlushMap_f_1_sm_16_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_17_t_5, IPFlushRepository::dnsFlushMap_f_1_sm_17_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_18_t_5, IPFlushRepository::dnsFlushMap_f_1_sm_18_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_19_t_5, IPFlushRepository::dnsFlushMap_f_1_sm_19_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_20_t_5, IPFlushRepository::dnsFlushMap_f_1_sm_20_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_21_t_5, IPFlushRepository::dnsFlushMap_f_1_sm_21_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_22_t_5, IPFlushRepository::dnsFlushMap_f_1_sm_22_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_23_t_5, IPFlushRepository::dnsFlushMap_f_1_sm_23_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_24_t_5, IPFlushRepository::dnsFlushMap_f_1_sm_24_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_25_t_5, IPFlushRepository::dnsFlushMap_f_1_sm_25_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_26_t_5, IPFlushRepository::dnsFlushMap_f_1_sm_26_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_27_t_5, IPFlushRepository::dnsFlushMap_f_1_sm_27_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_28_t_5, IPFlushRepository::dnsFlushMap_f_1_sm_28_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_29_t_5, IPFlushRepository::dnsFlushMap_f_1_sm_29_t_5_cnt);

			break;

		case 6:
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_0_t_6, IPFlushRepository::dnsFlushMap_f_1_sm_0_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_1_t_6, IPFlushRepository::dnsFlushMap_f_1_sm_1_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_2_t_6, IPFlushRepository::dnsFlushMap_f_1_sm_2_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_3_t_6, IPFlushRepository::dnsFlushMap_f_1_sm_3_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_4_t_6, IPFlushRepository::dnsFlushMap_f_1_sm_4_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_5_t_6, IPFlushRepository::dnsFlushMap_f_1_sm_5_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_6_t_6, IPFlushRepository::dnsFlushMap_f_1_sm_6_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_7_t_6, IPFlushRepository::dnsFlushMap_f_1_sm_7_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_8_t_6, IPFlushRepository::dnsFlushMap_f_1_sm_8_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_9_t_6, IPFlushRepository::dnsFlushMap_f_1_sm_9_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_10_t_6, IPFlushRepository::dnsFlushMap_f_1_sm_10_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_11_t_6, IPFlushRepository::dnsFlushMap_f_1_sm_11_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_12_t_6, IPFlushRepository::dnsFlushMap_f_1_sm_12_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_13_t_6, IPFlushRepository::dnsFlushMap_f_1_sm_13_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_14_t_6, IPFlushRepository::dnsFlushMap_f_1_sm_14_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_15_t_6, IPFlushRepository::dnsFlushMap_f_1_sm_15_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_16_t_6, IPFlushRepository::dnsFlushMap_f_1_sm_16_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_17_t_6, IPFlushRepository::dnsFlushMap_f_1_sm_17_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_18_t_6, IPFlushRepository::dnsFlushMap_f_1_sm_18_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_19_t_6, IPFlushRepository::dnsFlushMap_f_1_sm_19_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_20_t_6, IPFlushRepository::dnsFlushMap_f_1_sm_20_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_21_t_6, IPFlushRepository::dnsFlushMap_f_1_sm_21_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_22_t_6, IPFlushRepository::dnsFlushMap_f_1_sm_22_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_23_t_6, IPFlushRepository::dnsFlushMap_f_1_sm_23_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_24_t_6, IPFlushRepository::dnsFlushMap_f_1_sm_24_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_25_t_6, IPFlushRepository::dnsFlushMap_f_1_sm_25_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_26_t_6, IPFlushRepository::dnsFlushMap_f_1_sm_26_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_27_t_6, IPFlushRepository::dnsFlushMap_f_1_sm_27_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_28_t_6, IPFlushRepository::dnsFlushMap_f_1_sm_28_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_29_t_6, IPFlushRepository::dnsFlushMap_f_1_sm_29_t_6_cnt);

			break;

		case 7:
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_0_t_7, IPFlushRepository::dnsFlushMap_f_1_sm_0_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_1_t_7, IPFlushRepository::dnsFlushMap_f_1_sm_1_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_2_t_7, IPFlushRepository::dnsFlushMap_f_1_sm_2_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_3_t_7, IPFlushRepository::dnsFlushMap_f_1_sm_3_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_4_t_7, IPFlushRepository::dnsFlushMap_f_1_sm_4_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_5_t_7, IPFlushRepository::dnsFlushMap_f_1_sm_5_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_6_t_7, IPFlushRepository::dnsFlushMap_f_1_sm_6_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_7_t_7, IPFlushRepository::dnsFlushMap_f_1_sm_7_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_8_t_7, IPFlushRepository::dnsFlushMap_f_1_sm_8_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_9_t_7, IPFlushRepository::dnsFlushMap_f_1_sm_9_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_10_t_7, IPFlushRepository::dnsFlushMap_f_1_sm_10_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_11_t_7, IPFlushRepository::dnsFlushMap_f_1_sm_11_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_12_t_7, IPFlushRepository::dnsFlushMap_f_1_sm_12_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_13_t_7, IPFlushRepository::dnsFlushMap_f_1_sm_13_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_14_t_7, IPFlushRepository::dnsFlushMap_f_1_sm_14_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_15_t_7, IPFlushRepository::dnsFlushMap_f_1_sm_15_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_16_t_7, IPFlushRepository::dnsFlushMap_f_1_sm_16_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_17_t_7, IPFlushRepository::dnsFlushMap_f_1_sm_17_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_18_t_7, IPFlushRepository::dnsFlushMap_f_1_sm_18_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_19_t_7, IPFlushRepository::dnsFlushMap_f_1_sm_19_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_20_t_7, IPFlushRepository::dnsFlushMap_f_1_sm_20_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_21_t_7, IPFlushRepository::dnsFlushMap_f_1_sm_21_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_22_t_7, IPFlushRepository::dnsFlushMap_f_1_sm_22_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_23_t_7, IPFlushRepository::dnsFlushMap_f_1_sm_23_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_24_t_7, IPFlushRepository::dnsFlushMap_f_1_sm_24_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_25_t_7, IPFlushRepository::dnsFlushMap_f_1_sm_25_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_26_t_7, IPFlushRepository::dnsFlushMap_f_1_sm_26_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_27_t_7, IPFlushRepository::dnsFlushMap_f_1_sm_27_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_28_t_7, IPFlushRepository::dnsFlushMap_f_1_sm_28_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_29_t_7, IPFlushRepository::dnsFlushMap_f_1_sm_29_t_7_cnt);

			break;

		case 8:
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_0_t_8, IPFlushRepository::dnsFlushMap_f_1_sm_0_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_1_t_8, IPFlushRepository::dnsFlushMap_f_1_sm_1_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_2_t_8, IPFlushRepository::dnsFlushMap_f_1_sm_2_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_3_t_8, IPFlushRepository::dnsFlushMap_f_1_sm_3_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_4_t_8, IPFlushRepository::dnsFlushMap_f_1_sm_4_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_5_t_8, IPFlushRepository::dnsFlushMap_f_1_sm_5_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_6_t_8, IPFlushRepository::dnsFlushMap_f_1_sm_6_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_7_t_8, IPFlushRepository::dnsFlushMap_f_1_sm_7_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_8_t_8, IPFlushRepository::dnsFlushMap_f_1_sm_8_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_9_t_8, IPFlushRepository::dnsFlushMap_f_1_sm_9_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_10_t_8, IPFlushRepository::dnsFlushMap_f_1_sm_10_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_11_t_8, IPFlushRepository::dnsFlushMap_f_1_sm_11_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_12_t_8, IPFlushRepository::dnsFlushMap_f_1_sm_12_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_13_t_8, IPFlushRepository::dnsFlushMap_f_1_sm_13_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_14_t_8, IPFlushRepository::dnsFlushMap_f_1_sm_14_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_15_t_8, IPFlushRepository::dnsFlushMap_f_1_sm_15_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_16_t_8, IPFlushRepository::dnsFlushMap_f_1_sm_16_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_17_t_8, IPFlushRepository::dnsFlushMap_f_1_sm_17_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_18_t_8, IPFlushRepository::dnsFlushMap_f_1_sm_18_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_19_t_8, IPFlushRepository::dnsFlushMap_f_1_sm_19_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_20_t_8, IPFlushRepository::dnsFlushMap_f_1_sm_20_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_21_t_8, IPFlushRepository::dnsFlushMap_f_1_sm_21_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_22_t_8, IPFlushRepository::dnsFlushMap_f_1_sm_22_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_23_t_8, IPFlushRepository::dnsFlushMap_f_1_sm_23_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_24_t_8, IPFlushRepository::dnsFlushMap_f_1_sm_24_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_25_t_8, IPFlushRepository::dnsFlushMap_f_1_sm_25_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_26_t_8, IPFlushRepository::dnsFlushMap_f_1_sm_26_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_27_t_8, IPFlushRepository::dnsFlushMap_f_1_sm_27_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_28_t_8, IPFlushRepository::dnsFlushMap_f_1_sm_28_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_29_t_8, IPFlushRepository::dnsFlushMap_f_1_sm_29_t_8_cnt);

			break;

		case 9:
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_0_t_9, IPFlushRepository::dnsFlushMap_f_1_sm_0_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_1_t_9, IPFlushRepository::dnsFlushMap_f_1_sm_1_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_2_t_9, IPFlushRepository::dnsFlushMap_f_1_sm_2_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_3_t_9, IPFlushRepository::dnsFlushMap_f_1_sm_3_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_4_t_9, IPFlushRepository::dnsFlushMap_f_1_sm_4_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_5_t_9, IPFlushRepository::dnsFlushMap_f_1_sm_5_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_6_t_9, IPFlushRepository::dnsFlushMap_f_1_sm_6_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_7_t_9, IPFlushRepository::dnsFlushMap_f_1_sm_7_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_8_t_9, IPFlushRepository::dnsFlushMap_f_1_sm_8_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_9_t_9, IPFlushRepository::dnsFlushMap_f_1_sm_9_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_10_t_9, IPFlushRepository::dnsFlushMap_f_1_sm_10_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_11_t_9, IPFlushRepository::dnsFlushMap_f_1_sm_11_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_12_t_9, IPFlushRepository::dnsFlushMap_f_1_sm_12_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_13_t_9, IPFlushRepository::dnsFlushMap_f_1_sm_13_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_14_t_9, IPFlushRepository::dnsFlushMap_f_1_sm_14_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_15_t_9, IPFlushRepository::dnsFlushMap_f_1_sm_15_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_16_t_9, IPFlushRepository::dnsFlushMap_f_1_sm_16_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_17_t_9, IPFlushRepository::dnsFlushMap_f_1_sm_17_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_18_t_9, IPFlushRepository::dnsFlushMap_f_1_sm_18_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_19_t_9, IPFlushRepository::dnsFlushMap_f_1_sm_19_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_20_t_9, IPFlushRepository::dnsFlushMap_f_1_sm_20_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_21_t_9, IPFlushRepository::dnsFlushMap_f_1_sm_21_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_22_t_9, IPFlushRepository::dnsFlushMap_f_1_sm_22_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_23_t_9, IPFlushRepository::dnsFlushMap_f_1_sm_23_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_24_t_9, IPFlushRepository::dnsFlushMap_f_1_sm_24_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_25_t_9, IPFlushRepository::dnsFlushMap_f_1_sm_25_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_26_t_9, IPFlushRepository::dnsFlushMap_f_1_sm_26_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_27_t_9, IPFlushRepository::dnsFlushMap_f_1_sm_27_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_28_t_9, IPFlushRepository::dnsFlushMap_f_1_sm_28_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_1_sm_29_t_9, IPFlushRepository::dnsFlushMap_f_1_sm_29_t_9_cnt);

			break;
	}
}

VOID DNSFlusher::processDNSData_f_2(int index)
{
	switch(index)
	{
		case 0:
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_0_t_0, IPFlushRepository::dnsFlushMap_f_2_sm_0_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_1_t_0, IPFlushRepository::dnsFlushMap_f_2_sm_1_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_2_t_0, IPFlushRepository::dnsFlushMap_f_2_sm_2_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_3_t_0, IPFlushRepository::dnsFlushMap_f_2_sm_3_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_4_t_0, IPFlushRepository::dnsFlushMap_f_2_sm_4_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_5_t_0, IPFlushRepository::dnsFlushMap_f_2_sm_5_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_6_t_0, IPFlushRepository::dnsFlushMap_f_2_sm_6_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_7_t_0, IPFlushRepository::dnsFlushMap_f_2_sm_7_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_8_t_0, IPFlushRepository::dnsFlushMap_f_2_sm_8_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_9_t_0, IPFlushRepository::dnsFlushMap_f_2_sm_9_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_10_t_0, IPFlushRepository::dnsFlushMap_f_2_sm_10_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_11_t_0, IPFlushRepository::dnsFlushMap_f_2_sm_11_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_12_t_0, IPFlushRepository::dnsFlushMap_f_2_sm_12_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_13_t_0, IPFlushRepository::dnsFlushMap_f_2_sm_13_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_14_t_0, IPFlushRepository::dnsFlushMap_f_2_sm_14_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_15_t_0, IPFlushRepository::dnsFlushMap_f_2_sm_15_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_16_t_0, IPFlushRepository::dnsFlushMap_f_2_sm_16_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_17_t_0, IPFlushRepository::dnsFlushMap_f_2_sm_17_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_18_t_0, IPFlushRepository::dnsFlushMap_f_2_sm_18_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_19_t_0, IPFlushRepository::dnsFlushMap_f_2_sm_19_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_20_t_0, IPFlushRepository::dnsFlushMap_f_2_sm_20_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_21_t_0, IPFlushRepository::dnsFlushMap_f_2_sm_21_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_22_t_0, IPFlushRepository::dnsFlushMap_f_2_sm_22_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_23_t_0, IPFlushRepository::dnsFlushMap_f_2_sm_23_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_24_t_0, IPFlushRepository::dnsFlushMap_f_2_sm_24_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_25_t_0, IPFlushRepository::dnsFlushMap_f_2_sm_25_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_26_t_0, IPFlushRepository::dnsFlushMap_f_2_sm_26_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_27_t_0, IPFlushRepository::dnsFlushMap_f_2_sm_27_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_28_t_0, IPFlushRepository::dnsFlushMap_f_2_sm_28_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_29_t_0, IPFlushRepository::dnsFlushMap_f_2_sm_29_t_0_cnt);

			break;

		case 1:
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_0_t_1, IPFlushRepository::dnsFlushMap_f_2_sm_0_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_1_t_1, IPFlushRepository::dnsFlushMap_f_2_sm_1_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_2_t_1, IPFlushRepository::dnsFlushMap_f_2_sm_2_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_3_t_1, IPFlushRepository::dnsFlushMap_f_2_sm_3_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_4_t_1, IPFlushRepository::dnsFlushMap_f_2_sm_4_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_5_t_1, IPFlushRepository::dnsFlushMap_f_2_sm_5_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_6_t_1, IPFlushRepository::dnsFlushMap_f_2_sm_6_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_7_t_1, IPFlushRepository::dnsFlushMap_f_2_sm_7_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_8_t_1, IPFlushRepository::dnsFlushMap_f_2_sm_8_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_9_t_1, IPFlushRepository::dnsFlushMap_f_2_sm_9_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_10_t_1, IPFlushRepository::dnsFlushMap_f_2_sm_10_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_11_t_1, IPFlushRepository::dnsFlushMap_f_2_sm_11_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_12_t_1, IPFlushRepository::dnsFlushMap_f_2_sm_12_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_13_t_1, IPFlushRepository::dnsFlushMap_f_2_sm_13_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_14_t_1, IPFlushRepository::dnsFlushMap_f_2_sm_14_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_15_t_1, IPFlushRepository::dnsFlushMap_f_2_sm_15_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_16_t_1, IPFlushRepository::dnsFlushMap_f_2_sm_16_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_17_t_1, IPFlushRepository::dnsFlushMap_f_2_sm_17_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_18_t_1, IPFlushRepository::dnsFlushMap_f_2_sm_18_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_19_t_1, IPFlushRepository::dnsFlushMap_f_2_sm_19_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_20_t_1, IPFlushRepository::dnsFlushMap_f_2_sm_20_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_21_t_1, IPFlushRepository::dnsFlushMap_f_2_sm_21_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_22_t_1, IPFlushRepository::dnsFlushMap_f_2_sm_22_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_23_t_1, IPFlushRepository::dnsFlushMap_f_2_sm_23_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_24_t_1, IPFlushRepository::dnsFlushMap_f_2_sm_24_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_25_t_1, IPFlushRepository::dnsFlushMap_f_2_sm_25_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_26_t_1, IPFlushRepository::dnsFlushMap_f_2_sm_26_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_27_t_1, IPFlushRepository::dnsFlushMap_f_2_sm_27_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_28_t_1, IPFlushRepository::dnsFlushMap_f_2_sm_28_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_29_t_1, IPFlushRepository::dnsFlushMap_f_2_sm_29_t_1_cnt);

			break;

		case 2:
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_0_t_2, IPFlushRepository::dnsFlushMap_f_2_sm_0_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_1_t_2, IPFlushRepository::dnsFlushMap_f_2_sm_1_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_2_t_2, IPFlushRepository::dnsFlushMap_f_2_sm_2_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_3_t_2, IPFlushRepository::dnsFlushMap_f_2_sm_3_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_4_t_2, IPFlushRepository::dnsFlushMap_f_2_sm_4_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_5_t_2, IPFlushRepository::dnsFlushMap_f_2_sm_5_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_6_t_2, IPFlushRepository::dnsFlushMap_f_2_sm_6_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_7_t_2, IPFlushRepository::dnsFlushMap_f_2_sm_7_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_8_t_2, IPFlushRepository::dnsFlushMap_f_2_sm_8_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_9_t_2, IPFlushRepository::dnsFlushMap_f_2_sm_9_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_10_t_2, IPFlushRepository::dnsFlushMap_f_2_sm_10_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_11_t_2, IPFlushRepository::dnsFlushMap_f_2_sm_11_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_12_t_2, IPFlushRepository::dnsFlushMap_f_2_sm_12_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_13_t_2, IPFlushRepository::dnsFlushMap_f_2_sm_13_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_14_t_2, IPFlushRepository::dnsFlushMap_f_2_sm_14_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_15_t_2, IPFlushRepository::dnsFlushMap_f_2_sm_15_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_16_t_2, IPFlushRepository::dnsFlushMap_f_2_sm_16_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_17_t_2, IPFlushRepository::dnsFlushMap_f_2_sm_17_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_18_t_2, IPFlushRepository::dnsFlushMap_f_2_sm_18_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_19_t_2, IPFlushRepository::dnsFlushMap_f_2_sm_19_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_20_t_2, IPFlushRepository::dnsFlushMap_f_2_sm_20_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_21_t_2, IPFlushRepository::dnsFlushMap_f_2_sm_21_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_22_t_2, IPFlushRepository::dnsFlushMap_f_2_sm_22_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_23_t_2, IPFlushRepository::dnsFlushMap_f_2_sm_23_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_24_t_2, IPFlushRepository::dnsFlushMap_f_2_sm_24_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_25_t_2, IPFlushRepository::dnsFlushMap_f_2_sm_25_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_26_t_2, IPFlushRepository::dnsFlushMap_f_2_sm_26_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_27_t_2, IPFlushRepository::dnsFlushMap_f_2_sm_27_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_28_t_2, IPFlushRepository::dnsFlushMap_f_2_sm_28_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_29_t_2, IPFlushRepository::dnsFlushMap_f_2_sm_29_t_2_cnt);

			break;

		case 3:
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_0_t_3, IPFlushRepository::dnsFlushMap_f_2_sm_0_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_1_t_3, IPFlushRepository::dnsFlushMap_f_2_sm_1_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_2_t_3, IPFlushRepository::dnsFlushMap_f_2_sm_2_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_3_t_3, IPFlushRepository::dnsFlushMap_f_2_sm_3_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_4_t_3, IPFlushRepository::dnsFlushMap_f_2_sm_4_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_5_t_3, IPFlushRepository::dnsFlushMap_f_2_sm_5_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_6_t_3, IPFlushRepository::dnsFlushMap_f_2_sm_6_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_7_t_3, IPFlushRepository::dnsFlushMap_f_2_sm_7_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_8_t_3, IPFlushRepository::dnsFlushMap_f_2_sm_8_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_9_t_3, IPFlushRepository::dnsFlushMap_f_2_sm_9_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_10_t_3, IPFlushRepository::dnsFlushMap_f_2_sm_10_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_11_t_3, IPFlushRepository::dnsFlushMap_f_2_sm_11_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_12_t_3, IPFlushRepository::dnsFlushMap_f_2_sm_12_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_13_t_3, IPFlushRepository::dnsFlushMap_f_2_sm_13_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_14_t_3, IPFlushRepository::dnsFlushMap_f_2_sm_14_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_15_t_3, IPFlushRepository::dnsFlushMap_f_2_sm_15_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_16_t_3, IPFlushRepository::dnsFlushMap_f_2_sm_16_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_17_t_3, IPFlushRepository::dnsFlushMap_f_2_sm_17_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_18_t_3, IPFlushRepository::dnsFlushMap_f_2_sm_18_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_19_t_3, IPFlushRepository::dnsFlushMap_f_2_sm_19_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_20_t_3, IPFlushRepository::dnsFlushMap_f_2_sm_20_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_21_t_3, IPFlushRepository::dnsFlushMap_f_2_sm_21_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_22_t_3, IPFlushRepository::dnsFlushMap_f_2_sm_22_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_23_t_3, IPFlushRepository::dnsFlushMap_f_2_sm_23_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_24_t_3, IPFlushRepository::dnsFlushMap_f_2_sm_24_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_25_t_3, IPFlushRepository::dnsFlushMap_f_2_sm_25_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_26_t_3, IPFlushRepository::dnsFlushMap_f_2_sm_26_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_27_t_3, IPFlushRepository::dnsFlushMap_f_2_sm_27_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_28_t_3, IPFlushRepository::dnsFlushMap_f_2_sm_28_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_29_t_3, IPFlushRepository::dnsFlushMap_f_2_sm_29_t_3_cnt);

			break;

		case 4:
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_0_t_4, IPFlushRepository::dnsFlushMap_f_2_sm_0_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_1_t_4, IPFlushRepository::dnsFlushMap_f_2_sm_1_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_2_t_4, IPFlushRepository::dnsFlushMap_f_2_sm_2_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_3_t_4, IPFlushRepository::dnsFlushMap_f_2_sm_3_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_4_t_4, IPFlushRepository::dnsFlushMap_f_2_sm_4_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_5_t_4, IPFlushRepository::dnsFlushMap_f_2_sm_5_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_6_t_4, IPFlushRepository::dnsFlushMap_f_2_sm_6_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_7_t_4, IPFlushRepository::dnsFlushMap_f_2_sm_7_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_8_t_4, IPFlushRepository::dnsFlushMap_f_2_sm_8_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_9_t_4, IPFlushRepository::dnsFlushMap_f_2_sm_9_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_10_t_4, IPFlushRepository::dnsFlushMap_f_2_sm_10_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_11_t_4, IPFlushRepository::dnsFlushMap_f_2_sm_11_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_12_t_4, IPFlushRepository::dnsFlushMap_f_2_sm_12_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_13_t_4, IPFlushRepository::dnsFlushMap_f_2_sm_13_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_14_t_4, IPFlushRepository::dnsFlushMap_f_2_sm_14_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_15_t_4, IPFlushRepository::dnsFlushMap_f_2_sm_15_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_16_t_4, IPFlushRepository::dnsFlushMap_f_2_sm_16_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_17_t_4, IPFlushRepository::dnsFlushMap_f_2_sm_17_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_18_t_4, IPFlushRepository::dnsFlushMap_f_2_sm_18_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_19_t_4, IPFlushRepository::dnsFlushMap_f_2_sm_19_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_20_t_4, IPFlushRepository::dnsFlushMap_f_2_sm_20_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_21_t_4, IPFlushRepository::dnsFlushMap_f_2_sm_21_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_22_t_4, IPFlushRepository::dnsFlushMap_f_2_sm_22_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_23_t_4, IPFlushRepository::dnsFlushMap_f_2_sm_23_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_24_t_4, IPFlushRepository::dnsFlushMap_f_2_sm_24_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_25_t_4, IPFlushRepository::dnsFlushMap_f_2_sm_25_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_26_t_4, IPFlushRepository::dnsFlushMap_f_2_sm_26_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_27_t_4, IPFlushRepository::dnsFlushMap_f_2_sm_27_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_28_t_4, IPFlushRepository::dnsFlushMap_f_2_sm_28_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_29_t_4, IPFlushRepository::dnsFlushMap_f_2_sm_29_t_4_cnt);

			break;

		case 5:
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_0_t_5, IPFlushRepository::dnsFlushMap_f_2_sm_0_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_1_t_5, IPFlushRepository::dnsFlushMap_f_2_sm_1_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_2_t_5, IPFlushRepository::dnsFlushMap_f_2_sm_2_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_3_t_5, IPFlushRepository::dnsFlushMap_f_2_sm_3_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_4_t_5, IPFlushRepository::dnsFlushMap_f_2_sm_4_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_5_t_5, IPFlushRepository::dnsFlushMap_f_2_sm_5_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_6_t_5, IPFlushRepository::dnsFlushMap_f_2_sm_6_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_7_t_5, IPFlushRepository::dnsFlushMap_f_2_sm_7_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_8_t_5, IPFlushRepository::dnsFlushMap_f_2_sm_8_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_9_t_5, IPFlushRepository::dnsFlushMap_f_2_sm_9_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_10_t_5, IPFlushRepository::dnsFlushMap_f_2_sm_10_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_11_t_5, IPFlushRepository::dnsFlushMap_f_2_sm_11_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_12_t_5, IPFlushRepository::dnsFlushMap_f_2_sm_12_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_13_t_5, IPFlushRepository::dnsFlushMap_f_2_sm_13_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_14_t_5, IPFlushRepository::dnsFlushMap_f_2_sm_14_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_15_t_5, IPFlushRepository::dnsFlushMap_f_2_sm_15_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_16_t_5, IPFlushRepository::dnsFlushMap_f_2_sm_16_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_17_t_5, IPFlushRepository::dnsFlushMap_f_2_sm_17_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_18_t_5, IPFlushRepository::dnsFlushMap_f_2_sm_18_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_19_t_5, IPFlushRepository::dnsFlushMap_f_2_sm_19_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_20_t_5, IPFlushRepository::dnsFlushMap_f_2_sm_20_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_21_t_5, IPFlushRepository::dnsFlushMap_f_2_sm_21_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_22_t_5, IPFlushRepository::dnsFlushMap_f_2_sm_22_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_23_t_5, IPFlushRepository::dnsFlushMap_f_2_sm_23_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_24_t_5, IPFlushRepository::dnsFlushMap_f_2_sm_24_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_25_t_5, IPFlushRepository::dnsFlushMap_f_2_sm_25_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_26_t_5, IPFlushRepository::dnsFlushMap_f_2_sm_26_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_27_t_5, IPFlushRepository::dnsFlushMap_f_2_sm_27_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_28_t_5, IPFlushRepository::dnsFlushMap_f_2_sm_28_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_29_t_5, IPFlushRepository::dnsFlushMap_f_2_sm_29_t_5_cnt);

			break;

		case 6:
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_0_t_6, IPFlushRepository::dnsFlushMap_f_2_sm_0_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_1_t_6, IPFlushRepository::dnsFlushMap_f_2_sm_1_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_2_t_6, IPFlushRepository::dnsFlushMap_f_2_sm_2_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_3_t_6, IPFlushRepository::dnsFlushMap_f_2_sm_3_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_4_t_6, IPFlushRepository::dnsFlushMap_f_2_sm_4_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_5_t_6, IPFlushRepository::dnsFlushMap_f_2_sm_5_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_6_t_6, IPFlushRepository::dnsFlushMap_f_2_sm_6_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_7_t_6, IPFlushRepository::dnsFlushMap_f_2_sm_7_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_8_t_6, IPFlushRepository::dnsFlushMap_f_2_sm_8_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_9_t_6, IPFlushRepository::dnsFlushMap_f_2_sm_9_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_10_t_6, IPFlushRepository::dnsFlushMap_f_2_sm_10_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_11_t_6, IPFlushRepository::dnsFlushMap_f_2_sm_11_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_12_t_6, IPFlushRepository::dnsFlushMap_f_2_sm_12_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_13_t_6, IPFlushRepository::dnsFlushMap_f_2_sm_13_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_14_t_6, IPFlushRepository::dnsFlushMap_f_2_sm_14_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_15_t_6, IPFlushRepository::dnsFlushMap_f_2_sm_15_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_16_t_6, IPFlushRepository::dnsFlushMap_f_2_sm_16_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_17_t_6, IPFlushRepository::dnsFlushMap_f_2_sm_17_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_18_t_6, IPFlushRepository::dnsFlushMap_f_2_sm_18_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_19_t_6, IPFlushRepository::dnsFlushMap_f_2_sm_19_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_20_t_6, IPFlushRepository::dnsFlushMap_f_2_sm_20_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_21_t_6, IPFlushRepository::dnsFlushMap_f_2_sm_21_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_22_t_6, IPFlushRepository::dnsFlushMap_f_2_sm_22_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_23_t_6, IPFlushRepository::dnsFlushMap_f_2_sm_23_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_24_t_6, IPFlushRepository::dnsFlushMap_f_2_sm_24_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_25_t_6, IPFlushRepository::dnsFlushMap_f_2_sm_25_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_26_t_6, IPFlushRepository::dnsFlushMap_f_2_sm_26_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_27_t_6, IPFlushRepository::dnsFlushMap_f_2_sm_27_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_28_t_6, IPFlushRepository::dnsFlushMap_f_2_sm_28_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_29_t_6, IPFlushRepository::dnsFlushMap_f_2_sm_29_t_6_cnt);

			break;

		case 7:
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_0_t_7, IPFlushRepository::dnsFlushMap_f_2_sm_0_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_1_t_7, IPFlushRepository::dnsFlushMap_f_2_sm_1_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_2_t_7, IPFlushRepository::dnsFlushMap_f_2_sm_2_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_3_t_7, IPFlushRepository::dnsFlushMap_f_2_sm_3_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_4_t_7, IPFlushRepository::dnsFlushMap_f_2_sm_4_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_5_t_7, IPFlushRepository::dnsFlushMap_f_2_sm_5_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_6_t_7, IPFlushRepository::dnsFlushMap_f_2_sm_6_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_7_t_7, IPFlushRepository::dnsFlushMap_f_2_sm_7_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_8_t_7, IPFlushRepository::dnsFlushMap_f_2_sm_8_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_9_t_7, IPFlushRepository::dnsFlushMap_f_2_sm_9_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_10_t_7, IPFlushRepository::dnsFlushMap_f_2_sm_10_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_11_t_7, IPFlushRepository::dnsFlushMap_f_2_sm_11_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_12_t_7, IPFlushRepository::dnsFlushMap_f_2_sm_12_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_13_t_7, IPFlushRepository::dnsFlushMap_f_2_sm_13_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_14_t_7, IPFlushRepository::dnsFlushMap_f_2_sm_14_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_15_t_7, IPFlushRepository::dnsFlushMap_f_2_sm_15_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_16_t_7, IPFlushRepository::dnsFlushMap_f_2_sm_16_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_17_t_7, IPFlushRepository::dnsFlushMap_f_2_sm_17_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_18_t_7, IPFlushRepository::dnsFlushMap_f_2_sm_18_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_19_t_7, IPFlushRepository::dnsFlushMap_f_2_sm_19_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_20_t_7, IPFlushRepository::dnsFlushMap_f_2_sm_20_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_21_t_7, IPFlushRepository::dnsFlushMap_f_2_sm_21_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_22_t_7, IPFlushRepository::dnsFlushMap_f_2_sm_22_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_23_t_7, IPFlushRepository::dnsFlushMap_f_2_sm_23_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_24_t_7, IPFlushRepository::dnsFlushMap_f_2_sm_24_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_25_t_7, IPFlushRepository::dnsFlushMap_f_2_sm_25_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_26_t_7, IPFlushRepository::dnsFlushMap_f_2_sm_26_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_27_t_7, IPFlushRepository::dnsFlushMap_f_2_sm_27_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_28_t_7, IPFlushRepository::dnsFlushMap_f_2_sm_28_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_29_t_7, IPFlushRepository::dnsFlushMap_f_2_sm_29_t_7_cnt);

			break;

		case 8:
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_0_t_8, IPFlushRepository::dnsFlushMap_f_2_sm_0_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_1_t_8, IPFlushRepository::dnsFlushMap_f_2_sm_1_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_2_t_8, IPFlushRepository::dnsFlushMap_f_2_sm_2_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_3_t_8, IPFlushRepository::dnsFlushMap_f_2_sm_3_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_4_t_8, IPFlushRepository::dnsFlushMap_f_2_sm_4_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_5_t_8, IPFlushRepository::dnsFlushMap_f_2_sm_5_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_6_t_8, IPFlushRepository::dnsFlushMap_f_2_sm_6_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_7_t_8, IPFlushRepository::dnsFlushMap_f_2_sm_7_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_8_t_8, IPFlushRepository::dnsFlushMap_f_2_sm_8_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_9_t_8, IPFlushRepository::dnsFlushMap_f_2_sm_9_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_10_t_8, IPFlushRepository::dnsFlushMap_f_2_sm_10_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_11_t_8, IPFlushRepository::dnsFlushMap_f_2_sm_11_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_12_t_8, IPFlushRepository::dnsFlushMap_f_2_sm_12_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_13_t_8, IPFlushRepository::dnsFlushMap_f_2_sm_13_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_14_t_8, IPFlushRepository::dnsFlushMap_f_2_sm_14_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_15_t_8, IPFlushRepository::dnsFlushMap_f_2_sm_15_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_16_t_8, IPFlushRepository::dnsFlushMap_f_2_sm_16_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_17_t_8, IPFlushRepository::dnsFlushMap_f_2_sm_17_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_18_t_8, IPFlushRepository::dnsFlushMap_f_2_sm_18_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_19_t_8, IPFlushRepository::dnsFlushMap_f_2_sm_19_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_20_t_8, IPFlushRepository::dnsFlushMap_f_2_sm_20_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_21_t_8, IPFlushRepository::dnsFlushMap_f_2_sm_21_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_22_t_8, IPFlushRepository::dnsFlushMap_f_2_sm_22_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_23_t_8, IPFlushRepository::dnsFlushMap_f_2_sm_23_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_24_t_8, IPFlushRepository::dnsFlushMap_f_2_sm_24_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_25_t_8, IPFlushRepository::dnsFlushMap_f_2_sm_25_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_26_t_8, IPFlushRepository::dnsFlushMap_f_2_sm_26_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_27_t_8, IPFlushRepository::dnsFlushMap_f_2_sm_27_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_28_t_8, IPFlushRepository::dnsFlushMap_f_2_sm_28_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_29_t_8, IPFlushRepository::dnsFlushMap_f_2_sm_29_t_8_cnt);

			break;

		case 9:
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_0_t_9, IPFlushRepository::dnsFlushMap_f_2_sm_0_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_1_t_9, IPFlushRepository::dnsFlushMap_f_2_sm_1_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_2_t_9, IPFlushRepository::dnsFlushMap_f_2_sm_2_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_3_t_9, IPFlushRepository::dnsFlushMap_f_2_sm_3_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_4_t_9, IPFlushRepository::dnsFlushMap_f_2_sm_4_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_5_t_9, IPFlushRepository::dnsFlushMap_f_2_sm_5_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_6_t_9, IPFlushRepository::dnsFlushMap_f_2_sm_6_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_7_t_9, IPFlushRepository::dnsFlushMap_f_2_sm_7_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_8_t_9, IPFlushRepository::dnsFlushMap_f_2_sm_8_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_9_t_9, IPFlushRepository::dnsFlushMap_f_2_sm_9_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_10_t_9, IPFlushRepository::dnsFlushMap_f_2_sm_10_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_11_t_9, IPFlushRepository::dnsFlushMap_f_2_sm_11_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_12_t_9, IPFlushRepository::dnsFlushMap_f_2_sm_12_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_13_t_9, IPFlushRepository::dnsFlushMap_f_2_sm_13_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_14_t_9, IPFlushRepository::dnsFlushMap_f_2_sm_14_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_15_t_9, IPFlushRepository::dnsFlushMap_f_2_sm_15_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_16_t_9, IPFlushRepository::dnsFlushMap_f_2_sm_16_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_17_t_9, IPFlushRepository::dnsFlushMap_f_2_sm_17_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_18_t_9, IPFlushRepository::dnsFlushMap_f_2_sm_18_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_19_t_9, IPFlushRepository::dnsFlushMap_f_2_sm_19_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_20_t_9, IPFlushRepository::dnsFlushMap_f_2_sm_20_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_21_t_9, IPFlushRepository::dnsFlushMap_f_2_sm_21_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_22_t_9, IPFlushRepository::dnsFlushMap_f_2_sm_22_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_23_t_9, IPFlushRepository::dnsFlushMap_f_2_sm_23_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_24_t_9, IPFlushRepository::dnsFlushMap_f_2_sm_24_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_25_t_9, IPFlushRepository::dnsFlushMap_f_2_sm_25_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_26_t_9, IPFlushRepository::dnsFlushMap_f_2_sm_26_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_27_t_9, IPFlushRepository::dnsFlushMap_f_2_sm_27_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_28_t_9, IPFlushRepository::dnsFlushMap_f_2_sm_28_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_2_sm_29_t_9, IPFlushRepository::dnsFlushMap_f_2_sm_29_t_9_cnt);

			break;
	}
}

VOID DNSFlusher::processDNSData_f_3(int index)
{
	switch(index)
	{
		case 0:
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_0_t_0, IPFlushRepository::dnsFlushMap_f_3_sm_0_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_1_t_0, IPFlushRepository::dnsFlushMap_f_3_sm_1_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_2_t_0, IPFlushRepository::dnsFlushMap_f_3_sm_2_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_3_t_0, IPFlushRepository::dnsFlushMap_f_3_sm_3_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_4_t_0, IPFlushRepository::dnsFlushMap_f_3_sm_4_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_5_t_0, IPFlushRepository::dnsFlushMap_f_3_sm_5_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_6_t_0, IPFlushRepository::dnsFlushMap_f_3_sm_6_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_7_t_0, IPFlushRepository::dnsFlushMap_f_3_sm_7_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_8_t_0, IPFlushRepository::dnsFlushMap_f_3_sm_8_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_9_t_0, IPFlushRepository::dnsFlushMap_f_3_sm_9_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_10_t_0, IPFlushRepository::dnsFlushMap_f_3_sm_10_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_11_t_0, IPFlushRepository::dnsFlushMap_f_3_sm_11_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_12_t_0, IPFlushRepository::dnsFlushMap_f_3_sm_12_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_13_t_0, IPFlushRepository::dnsFlushMap_f_3_sm_13_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_14_t_0, IPFlushRepository::dnsFlushMap_f_3_sm_14_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_15_t_0, IPFlushRepository::dnsFlushMap_f_3_sm_15_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_16_t_0, IPFlushRepository::dnsFlushMap_f_3_sm_16_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_17_t_0, IPFlushRepository::dnsFlushMap_f_3_sm_17_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_18_t_0, IPFlushRepository::dnsFlushMap_f_3_sm_18_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_19_t_0, IPFlushRepository::dnsFlushMap_f_3_sm_19_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_20_t_0, IPFlushRepository::dnsFlushMap_f_3_sm_20_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_21_t_0, IPFlushRepository::dnsFlushMap_f_3_sm_21_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_22_t_0, IPFlushRepository::dnsFlushMap_f_3_sm_22_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_23_t_0, IPFlushRepository::dnsFlushMap_f_3_sm_23_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_24_t_0, IPFlushRepository::dnsFlushMap_f_3_sm_24_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_25_t_0, IPFlushRepository::dnsFlushMap_f_3_sm_25_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_26_t_0, IPFlushRepository::dnsFlushMap_f_3_sm_26_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_27_t_0, IPFlushRepository::dnsFlushMap_f_3_sm_27_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_28_t_0, IPFlushRepository::dnsFlushMap_f_3_sm_28_t_0_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_29_t_0, IPFlushRepository::dnsFlushMap_f_3_sm_29_t_0_cnt);

			break;

		case 1:
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_0_t_1, IPFlushRepository::dnsFlushMap_f_3_sm_0_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_1_t_1, IPFlushRepository::dnsFlushMap_f_3_sm_1_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_2_t_1, IPFlushRepository::dnsFlushMap_f_3_sm_2_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_3_t_1, IPFlushRepository::dnsFlushMap_f_3_sm_3_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_4_t_1, IPFlushRepository::dnsFlushMap_f_3_sm_4_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_5_t_1, IPFlushRepository::dnsFlushMap_f_3_sm_5_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_6_t_1, IPFlushRepository::dnsFlushMap_f_3_sm_6_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_7_t_1, IPFlushRepository::dnsFlushMap_f_3_sm_7_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_8_t_1, IPFlushRepository::dnsFlushMap_f_3_sm_8_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_9_t_1, IPFlushRepository::dnsFlushMap_f_3_sm_9_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_10_t_1, IPFlushRepository::dnsFlushMap_f_3_sm_10_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_11_t_1, IPFlushRepository::dnsFlushMap_f_3_sm_11_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_12_t_1, IPFlushRepository::dnsFlushMap_f_3_sm_12_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_13_t_1, IPFlushRepository::dnsFlushMap_f_3_sm_13_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_14_t_1, IPFlushRepository::dnsFlushMap_f_3_sm_14_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_15_t_1, IPFlushRepository::dnsFlushMap_f_3_sm_15_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_16_t_1, IPFlushRepository::dnsFlushMap_f_3_sm_16_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_17_t_1, IPFlushRepository::dnsFlushMap_f_3_sm_17_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_18_t_1, IPFlushRepository::dnsFlushMap_f_3_sm_18_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_19_t_1, IPFlushRepository::dnsFlushMap_f_3_sm_19_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_20_t_1, IPFlushRepository::dnsFlushMap_f_3_sm_20_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_21_t_1, IPFlushRepository::dnsFlushMap_f_3_sm_21_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_22_t_1, IPFlushRepository::dnsFlushMap_f_3_sm_22_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_23_t_1, IPFlushRepository::dnsFlushMap_f_3_sm_23_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_24_t_1, IPFlushRepository::dnsFlushMap_f_3_sm_24_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_25_t_1, IPFlushRepository::dnsFlushMap_f_3_sm_25_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_26_t_1, IPFlushRepository::dnsFlushMap_f_3_sm_26_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_27_t_1, IPFlushRepository::dnsFlushMap_f_3_sm_27_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_28_t_1, IPFlushRepository::dnsFlushMap_f_3_sm_28_t_1_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_29_t_1, IPFlushRepository::dnsFlushMap_f_3_sm_29_t_1_cnt);

			break;

		case 2:
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_0_t_2, IPFlushRepository::dnsFlushMap_f_3_sm_0_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_1_t_2, IPFlushRepository::dnsFlushMap_f_3_sm_1_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_2_t_2, IPFlushRepository::dnsFlushMap_f_3_sm_2_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_3_t_2, IPFlushRepository::dnsFlushMap_f_3_sm_3_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_4_t_2, IPFlushRepository::dnsFlushMap_f_3_sm_4_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_5_t_2, IPFlushRepository::dnsFlushMap_f_3_sm_5_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_6_t_2, IPFlushRepository::dnsFlushMap_f_3_sm_6_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_7_t_2, IPFlushRepository::dnsFlushMap_f_3_sm_7_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_8_t_2, IPFlushRepository::dnsFlushMap_f_3_sm_8_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_9_t_2, IPFlushRepository::dnsFlushMap_f_3_sm_9_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_10_t_2, IPFlushRepository::dnsFlushMap_f_3_sm_10_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_11_t_2, IPFlushRepository::dnsFlushMap_f_3_sm_11_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_12_t_2, IPFlushRepository::dnsFlushMap_f_3_sm_12_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_13_t_2, IPFlushRepository::dnsFlushMap_f_3_sm_13_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_14_t_2, IPFlushRepository::dnsFlushMap_f_3_sm_14_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_15_t_2, IPFlushRepository::dnsFlushMap_f_3_sm_15_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_16_t_2, IPFlushRepository::dnsFlushMap_f_3_sm_16_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_17_t_2, IPFlushRepository::dnsFlushMap_f_3_sm_17_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_18_t_2, IPFlushRepository::dnsFlushMap_f_3_sm_18_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_19_t_2, IPFlushRepository::dnsFlushMap_f_3_sm_19_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_20_t_2, IPFlushRepository::dnsFlushMap_f_3_sm_20_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_21_t_2, IPFlushRepository::dnsFlushMap_f_3_sm_21_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_22_t_2, IPFlushRepository::dnsFlushMap_f_3_sm_22_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_23_t_2, IPFlushRepository::dnsFlushMap_f_3_sm_23_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_24_t_2, IPFlushRepository::dnsFlushMap_f_3_sm_24_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_25_t_2, IPFlushRepository::dnsFlushMap_f_3_sm_25_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_26_t_2, IPFlushRepository::dnsFlushMap_f_3_sm_26_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_27_t_2, IPFlushRepository::dnsFlushMap_f_3_sm_27_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_28_t_2, IPFlushRepository::dnsFlushMap_f_3_sm_28_t_2_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_29_t_2, IPFlushRepository::dnsFlushMap_f_3_sm_29_t_2_cnt);

			break;

		case 3:
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_0_t_3, IPFlushRepository::dnsFlushMap_f_3_sm_0_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_1_t_3, IPFlushRepository::dnsFlushMap_f_3_sm_1_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_2_t_3, IPFlushRepository::dnsFlushMap_f_3_sm_2_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_3_t_3, IPFlushRepository::dnsFlushMap_f_3_sm_3_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_4_t_3, IPFlushRepository::dnsFlushMap_f_3_sm_4_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_5_t_3, IPFlushRepository::dnsFlushMap_f_3_sm_5_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_6_t_3, IPFlushRepository::dnsFlushMap_f_3_sm_6_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_7_t_3, IPFlushRepository::dnsFlushMap_f_3_sm_7_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_8_t_3, IPFlushRepository::dnsFlushMap_f_3_sm_8_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_9_t_3, IPFlushRepository::dnsFlushMap_f_3_sm_9_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_10_t_3, IPFlushRepository::dnsFlushMap_f_3_sm_10_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_11_t_3, IPFlushRepository::dnsFlushMap_f_3_sm_11_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_12_t_3, IPFlushRepository::dnsFlushMap_f_3_sm_12_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_13_t_3, IPFlushRepository::dnsFlushMap_f_3_sm_13_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_14_t_3, IPFlushRepository::dnsFlushMap_f_3_sm_14_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_15_t_3, IPFlushRepository::dnsFlushMap_f_3_sm_15_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_16_t_3, IPFlushRepository::dnsFlushMap_f_3_sm_16_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_17_t_3, IPFlushRepository::dnsFlushMap_f_3_sm_17_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_18_t_3, IPFlushRepository::dnsFlushMap_f_3_sm_18_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_19_t_3, IPFlushRepository::dnsFlushMap_f_3_sm_19_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_20_t_3, IPFlushRepository::dnsFlushMap_f_3_sm_20_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_21_t_3, IPFlushRepository::dnsFlushMap_f_3_sm_21_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_22_t_3, IPFlushRepository::dnsFlushMap_f_3_sm_22_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_23_t_3, IPFlushRepository::dnsFlushMap_f_3_sm_23_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_24_t_3, IPFlushRepository::dnsFlushMap_f_3_sm_24_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_25_t_3, IPFlushRepository::dnsFlushMap_f_3_sm_25_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_26_t_3, IPFlushRepository::dnsFlushMap_f_3_sm_26_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_27_t_3, IPFlushRepository::dnsFlushMap_f_3_sm_27_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_28_t_3, IPFlushRepository::dnsFlushMap_f_3_sm_28_t_3_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_29_t_3, IPFlushRepository::dnsFlushMap_f_3_sm_29_t_3_cnt);

			break;

		case 4:
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_0_t_4, IPFlushRepository::dnsFlushMap_f_3_sm_0_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_1_t_4, IPFlushRepository::dnsFlushMap_f_3_sm_1_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_2_t_4, IPFlushRepository::dnsFlushMap_f_3_sm_2_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_3_t_4, IPFlushRepository::dnsFlushMap_f_3_sm_3_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_4_t_4, IPFlushRepository::dnsFlushMap_f_3_sm_4_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_5_t_4, IPFlushRepository::dnsFlushMap_f_3_sm_5_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_6_t_4, IPFlushRepository::dnsFlushMap_f_3_sm_6_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_7_t_4, IPFlushRepository::dnsFlushMap_f_3_sm_7_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_8_t_4, IPFlushRepository::dnsFlushMap_f_3_sm_8_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_9_t_4, IPFlushRepository::dnsFlushMap_f_3_sm_9_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_10_t_4, IPFlushRepository::dnsFlushMap_f_3_sm_10_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_11_t_4, IPFlushRepository::dnsFlushMap_f_3_sm_11_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_12_t_4, IPFlushRepository::dnsFlushMap_f_3_sm_12_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_13_t_4, IPFlushRepository::dnsFlushMap_f_3_sm_13_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_14_t_4, IPFlushRepository::dnsFlushMap_f_3_sm_14_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_15_t_4, IPFlushRepository::dnsFlushMap_f_3_sm_15_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_16_t_4, IPFlushRepository::dnsFlushMap_f_3_sm_16_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_17_t_4, IPFlushRepository::dnsFlushMap_f_3_sm_17_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_18_t_4, IPFlushRepository::dnsFlushMap_f_3_sm_18_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_19_t_4, IPFlushRepository::dnsFlushMap_f_3_sm_19_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_20_t_4, IPFlushRepository::dnsFlushMap_f_3_sm_20_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_21_t_4, IPFlushRepository::dnsFlushMap_f_3_sm_21_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_22_t_4, IPFlushRepository::dnsFlushMap_f_3_sm_22_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_23_t_4, IPFlushRepository::dnsFlushMap_f_3_sm_23_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_24_t_4, IPFlushRepository::dnsFlushMap_f_3_sm_24_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_25_t_4, IPFlushRepository::dnsFlushMap_f_3_sm_25_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_26_t_4, IPFlushRepository::dnsFlushMap_f_3_sm_26_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_27_t_4, IPFlushRepository::dnsFlushMap_f_3_sm_27_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_28_t_4, IPFlushRepository::dnsFlushMap_f_3_sm_28_t_4_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_29_t_4, IPFlushRepository::dnsFlushMap_f_3_sm_29_t_4_cnt);

			break;

		case 5:
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_0_t_5, IPFlushRepository::dnsFlushMap_f_3_sm_0_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_1_t_5, IPFlushRepository::dnsFlushMap_f_3_sm_1_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_2_t_5, IPFlushRepository::dnsFlushMap_f_3_sm_2_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_3_t_5, IPFlushRepository::dnsFlushMap_f_3_sm_3_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_4_t_5, IPFlushRepository::dnsFlushMap_f_3_sm_4_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_5_t_5, IPFlushRepository::dnsFlushMap_f_3_sm_5_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_6_t_5, IPFlushRepository::dnsFlushMap_f_3_sm_6_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_7_t_5, IPFlushRepository::dnsFlushMap_f_3_sm_7_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_8_t_5, IPFlushRepository::dnsFlushMap_f_3_sm_8_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_9_t_5, IPFlushRepository::dnsFlushMap_f_3_sm_9_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_10_t_5, IPFlushRepository::dnsFlushMap_f_3_sm_10_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_11_t_5, IPFlushRepository::dnsFlushMap_f_3_sm_11_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_12_t_5, IPFlushRepository::dnsFlushMap_f_3_sm_12_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_13_t_5, IPFlushRepository::dnsFlushMap_f_3_sm_13_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_14_t_5, IPFlushRepository::dnsFlushMap_f_3_sm_14_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_15_t_5, IPFlushRepository::dnsFlushMap_f_3_sm_15_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_16_t_5, IPFlushRepository::dnsFlushMap_f_3_sm_16_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_17_t_5, IPFlushRepository::dnsFlushMap_f_3_sm_17_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_18_t_5, IPFlushRepository::dnsFlushMap_f_3_sm_18_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_19_t_5, IPFlushRepository::dnsFlushMap_f_3_sm_19_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_20_t_5, IPFlushRepository::dnsFlushMap_f_3_sm_20_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_21_t_5, IPFlushRepository::dnsFlushMap_f_3_sm_21_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_22_t_5, IPFlushRepository::dnsFlushMap_f_3_sm_22_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_23_t_5, IPFlushRepository::dnsFlushMap_f_3_sm_23_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_24_t_5, IPFlushRepository::dnsFlushMap_f_3_sm_24_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_25_t_5, IPFlushRepository::dnsFlushMap_f_3_sm_25_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_26_t_5, IPFlushRepository::dnsFlushMap_f_3_sm_26_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_27_t_5, IPFlushRepository::dnsFlushMap_f_3_sm_27_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_28_t_5, IPFlushRepository::dnsFlushMap_f_3_sm_28_t_5_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_29_t_5, IPFlushRepository::dnsFlushMap_f_3_sm_29_t_5_cnt);

			break;

		case 6:
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_0_t_6, IPFlushRepository::dnsFlushMap_f_3_sm_0_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_1_t_6, IPFlushRepository::dnsFlushMap_f_3_sm_1_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_2_t_6, IPFlushRepository::dnsFlushMap_f_3_sm_2_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_3_t_6, IPFlushRepository::dnsFlushMap_f_3_sm_3_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_4_t_6, IPFlushRepository::dnsFlushMap_f_3_sm_4_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_5_t_6, IPFlushRepository::dnsFlushMap_f_3_sm_5_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_6_t_6, IPFlushRepository::dnsFlushMap_f_3_sm_6_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_7_t_6, IPFlushRepository::dnsFlushMap_f_3_sm_7_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_8_t_6, IPFlushRepository::dnsFlushMap_f_3_sm_8_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_9_t_6, IPFlushRepository::dnsFlushMap_f_3_sm_9_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_10_t_6, IPFlushRepository::dnsFlushMap_f_3_sm_10_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_11_t_6, IPFlushRepository::dnsFlushMap_f_3_sm_11_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_12_t_6, IPFlushRepository::dnsFlushMap_f_3_sm_12_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_13_t_6, IPFlushRepository::dnsFlushMap_f_3_sm_13_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_14_t_6, IPFlushRepository::dnsFlushMap_f_3_sm_14_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_15_t_6, IPFlushRepository::dnsFlushMap_f_3_sm_15_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_16_t_6, IPFlushRepository::dnsFlushMap_f_3_sm_16_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_17_t_6, IPFlushRepository::dnsFlushMap_f_3_sm_17_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_18_t_6, IPFlushRepository::dnsFlushMap_f_3_sm_18_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_19_t_6, IPFlushRepository::dnsFlushMap_f_3_sm_19_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_20_t_6, IPFlushRepository::dnsFlushMap_f_3_sm_20_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_21_t_6, IPFlushRepository::dnsFlushMap_f_3_sm_21_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_22_t_6, IPFlushRepository::dnsFlushMap_f_3_sm_22_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_23_t_6, IPFlushRepository::dnsFlushMap_f_3_sm_23_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_24_t_6, IPFlushRepository::dnsFlushMap_f_3_sm_24_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_25_t_6, IPFlushRepository::dnsFlushMap_f_3_sm_25_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_26_t_6, IPFlushRepository::dnsFlushMap_f_3_sm_26_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_27_t_6, IPFlushRepository::dnsFlushMap_f_3_sm_27_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_28_t_6, IPFlushRepository::dnsFlushMap_f_3_sm_28_t_6_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_29_t_6, IPFlushRepository::dnsFlushMap_f_3_sm_29_t_6_cnt);

			break;

		case 7:
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_0_t_7, IPFlushRepository::dnsFlushMap_f_3_sm_0_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_1_t_7, IPFlushRepository::dnsFlushMap_f_3_sm_1_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_2_t_7, IPFlushRepository::dnsFlushMap_f_3_sm_2_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_3_t_7, IPFlushRepository::dnsFlushMap_f_3_sm_3_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_4_t_7, IPFlushRepository::dnsFlushMap_f_3_sm_4_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_5_t_7, IPFlushRepository::dnsFlushMap_f_3_sm_5_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_6_t_7, IPFlushRepository::dnsFlushMap_f_3_sm_6_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_7_t_7, IPFlushRepository::dnsFlushMap_f_3_sm_7_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_8_t_7, IPFlushRepository::dnsFlushMap_f_3_sm_8_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_9_t_7, IPFlushRepository::dnsFlushMap_f_3_sm_9_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_10_t_7, IPFlushRepository::dnsFlushMap_f_3_sm_10_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_11_t_7, IPFlushRepository::dnsFlushMap_f_3_sm_11_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_12_t_7, IPFlushRepository::dnsFlushMap_f_3_sm_12_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_13_t_7, IPFlushRepository::dnsFlushMap_f_3_sm_13_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_14_t_7, IPFlushRepository::dnsFlushMap_f_3_sm_14_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_15_t_7, IPFlushRepository::dnsFlushMap_f_3_sm_15_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_16_t_7, IPFlushRepository::dnsFlushMap_f_3_sm_16_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_17_t_7, IPFlushRepository::dnsFlushMap_f_3_sm_17_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_18_t_7, IPFlushRepository::dnsFlushMap_f_3_sm_18_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_19_t_7, IPFlushRepository::dnsFlushMap_f_3_sm_19_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_20_t_7, IPFlushRepository::dnsFlushMap_f_3_sm_20_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_21_t_7, IPFlushRepository::dnsFlushMap_f_3_sm_21_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_22_t_7, IPFlushRepository::dnsFlushMap_f_3_sm_22_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_23_t_7, IPFlushRepository::dnsFlushMap_f_3_sm_23_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_24_t_7, IPFlushRepository::dnsFlushMap_f_3_sm_24_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_25_t_7, IPFlushRepository::dnsFlushMap_f_3_sm_25_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_26_t_7, IPFlushRepository::dnsFlushMap_f_3_sm_26_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_27_t_7, IPFlushRepository::dnsFlushMap_f_3_sm_27_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_28_t_7, IPFlushRepository::dnsFlushMap_f_3_sm_28_t_7_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_29_t_7, IPFlushRepository::dnsFlushMap_f_3_sm_29_t_7_cnt);

			break;

		case 8:
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_0_t_8, IPFlushRepository::dnsFlushMap_f_3_sm_0_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_1_t_8, IPFlushRepository::dnsFlushMap_f_3_sm_1_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_2_t_8, IPFlushRepository::dnsFlushMap_f_3_sm_2_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_3_t_8, IPFlushRepository::dnsFlushMap_f_3_sm_3_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_4_t_8, IPFlushRepository::dnsFlushMap_f_3_sm_4_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_5_t_8, IPFlushRepository::dnsFlushMap_f_3_sm_5_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_6_t_8, IPFlushRepository::dnsFlushMap_f_3_sm_6_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_7_t_8, IPFlushRepository::dnsFlushMap_f_3_sm_7_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_8_t_8, IPFlushRepository::dnsFlushMap_f_3_sm_8_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_9_t_8, IPFlushRepository::dnsFlushMap_f_3_sm_9_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_10_t_8, IPFlushRepository::dnsFlushMap_f_3_sm_10_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_11_t_8, IPFlushRepository::dnsFlushMap_f_3_sm_11_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_12_t_8, IPFlushRepository::dnsFlushMap_f_3_sm_12_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_13_t_8, IPFlushRepository::dnsFlushMap_f_3_sm_13_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_14_t_8, IPFlushRepository::dnsFlushMap_f_3_sm_14_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_15_t_8, IPFlushRepository::dnsFlushMap_f_3_sm_15_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_16_t_8, IPFlushRepository::dnsFlushMap_f_3_sm_16_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_17_t_8, IPFlushRepository::dnsFlushMap_f_3_sm_17_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_18_t_8, IPFlushRepository::dnsFlushMap_f_3_sm_18_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_19_t_8, IPFlushRepository::dnsFlushMap_f_3_sm_19_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_20_t_8, IPFlushRepository::dnsFlushMap_f_3_sm_20_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_21_t_8, IPFlushRepository::dnsFlushMap_f_3_sm_21_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_22_t_8, IPFlushRepository::dnsFlushMap_f_3_sm_22_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_23_t_8, IPFlushRepository::dnsFlushMap_f_3_sm_23_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_24_t_8, IPFlushRepository::dnsFlushMap_f_3_sm_24_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_25_t_8, IPFlushRepository::dnsFlushMap_f_3_sm_25_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_26_t_8, IPFlushRepository::dnsFlushMap_f_3_sm_26_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_27_t_8, IPFlushRepository::dnsFlushMap_f_3_sm_27_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_28_t_8, IPFlushRepository::dnsFlushMap_f_3_sm_28_t_8_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_29_t_8, IPFlushRepository::dnsFlushMap_f_3_sm_29_t_8_cnt);

			break;

		case 9:
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_0_t_9, IPFlushRepository::dnsFlushMap_f_3_sm_0_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_1_t_9, IPFlushRepository::dnsFlushMap_f_3_sm_1_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_2_t_9, IPFlushRepository::dnsFlushMap_f_3_sm_2_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_3_t_9, IPFlushRepository::dnsFlushMap_f_3_sm_3_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_4_t_9, IPFlushRepository::dnsFlushMap_f_3_sm_4_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_5_t_9, IPFlushRepository::dnsFlushMap_f_3_sm_5_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_6_t_9, IPFlushRepository::dnsFlushMap_f_3_sm_6_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_7_t_9, IPFlushRepository::dnsFlushMap_f_3_sm_7_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_8_t_9, IPFlushRepository::dnsFlushMap_f_3_sm_8_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_9_t_9, IPFlushRepository::dnsFlushMap_f_3_sm_9_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_10_t_9, IPFlushRepository::dnsFlushMap_f_3_sm_10_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_11_t_9, IPFlushRepository::dnsFlushMap_f_3_sm_11_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_12_t_9, IPFlushRepository::dnsFlushMap_f_3_sm_12_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_13_t_9, IPFlushRepository::dnsFlushMap_f_3_sm_13_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_14_t_9, IPFlushRepository::dnsFlushMap_f_3_sm_14_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_15_t_9, IPFlushRepository::dnsFlushMap_f_3_sm_15_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_16_t_9, IPFlushRepository::dnsFlushMap_f_3_sm_16_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_17_t_9, IPFlushRepository::dnsFlushMap_f_3_sm_17_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_18_t_9, IPFlushRepository::dnsFlushMap_f_3_sm_18_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_19_t_9, IPFlushRepository::dnsFlushMap_f_3_sm_19_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_20_t_9, IPFlushRepository::dnsFlushMap_f_3_sm_20_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_21_t_9, IPFlushRepository::dnsFlushMap_f_3_sm_21_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_22_t_9, IPFlushRepository::dnsFlushMap_f_3_sm_22_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_23_t_9, IPFlushRepository::dnsFlushMap_f_3_sm_23_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_24_t_9, IPFlushRepository::dnsFlushMap_f_3_sm_24_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_25_t_9, IPFlushRepository::dnsFlushMap_f_3_sm_25_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_26_t_9, IPFlushRepository::dnsFlushMap_f_3_sm_26_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_27_t_9, IPFlushRepository::dnsFlushMap_f_3_sm_27_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_28_t_9, IPFlushRepository::dnsFlushMap_f_3_sm_28_t_9_cnt);
			flushDNSData_sm_t(IPFlushRepository::dnsFlushMap_f_3_sm_29_t_9, IPFlushRepository::dnsFlushMap_f_3_sm_29_t_9_cnt);

			break;
	}
}

VOID DNSFlusher::flushDNSCsvRecords()
{
	switch(this->InstanceId)
	{
		case 0:
			flushDNSCsvRecords_f_0();
			break;
		case 1:
			flushDNSCsvRecords_f_1();
			break;
		case 2:
			flushDNSCsvRecords_f_2();
			break;
		case 3:
			flushDNSCsvRecords_f_3();
			break;

	}
}

VOID DNSFlusher::storeDNSZmqRecords(int index, int &dns_zmq_flush_map_cnt, std::unordered_map<int,xdrStore> &dns_zmq_flush_map)
{
	if(IPFlushRepository::dns_zmq_flush_t_index != index)
	{
		dns_zmq_flush_map[dns_zmq_flush_map_cnt] = objXdrStore;
		dns_zmq_flush_map_cnt++;
	}
}

//VOID DNSFlusher::storeDNSZmqRecords(int index, int &dns_zmq_flush_map_cnt, std::unordered_map<int,xdrStore> &dns_zmq_flush_map)
//{
//	switch(this->InstanceId)
//	{
//		case 0:
//				if(dns_zmq_flush_map_cnt >= IPGlobal::IP_SESSION_FLUSH_TIME_INDEX_REPO_SIZE)
//				{
//					if(!IPFlushRepository::zmqBufferStatus_f_0.IP_ZMQ_FULL_FLAG)
//						IPFlushRepository::zmqBufferStatus_f_0.bufferFullDetectionTime = processStartEpochSec;
//
//					IPFlushRepository::zmqBufferStatus_f_0.IP_ZMQ_FULL_FLAG = true;
//				}
//				else if(IPFlushRepository::zmq_flush_t_index != index)
//				{
//					dns_zmq_flush_map[dns_zmq_flush_map_cnt] = objXdrStore;
//					dns_zmq_flush_map_cnt++;
//				}
//				break;
//		case 1:
//				if(dns_zmq_flush_map_cnt >= IPGlobal::IP_SESSION_FLUSH_TIME_INDEX_REPO_SIZE)
//				{
//					if(!IPFlushRepository::zmqBufferStatus_f_1.IP_ZMQ_FULL_FLAG)
//						IPFlushRepository::zmqBufferStatus_f_1.bufferFullDetectionTime = processStartEpochSec;
//
//					IPFlushRepository::zmqBufferStatus_f_1.IP_ZMQ_FULL_FLAG = true;
//				}
//				else if(IPFlushRepository::zmq_flush_t_index != index)
//				{
//					dns_zmq_flush_map[dns_zmq_flush_map_cnt] = objXdrStore;
//					dns_zmq_flush_map_cnt++;
//				}
//				break;
//		case 2:
//				if(dns_zmq_flush_map_cnt >= IPGlobal::IP_SESSION_FLUSH_TIME_INDEX_REPO_SIZE)
//				{
//					if(!IPFlushRepository::zmqBufferStatus_f_2.IP_ZMQ_FULL_FLAG)
//						IPFlushRepository::zmqBufferStatus_f_2.bufferFullDetectionTime = processStartEpochSec;
//
//					IPFlushRepository::zmqBufferStatus_f_2.IP_ZMQ_FULL_FLAG = true;
//				}
//				else if(IPFlushRepository::zmq_flush_t_index != index)
//				{
//					dns_zmq_flush_map[dns_zmq_flush_map_cnt] = objXdrStore;
//					dns_zmq_flush_map_cnt++;
//				}
//				break;
//		case 3:
//				if(dns_zmq_flush_map_cnt >= IPGlobal::IP_SESSION_FLUSH_TIME_INDEX_REPO_SIZE)
//				{
//					if(!IPFlushRepository::zmqBufferStatus_f_3.IP_ZMQ_FULL_FLAG)
//						IPFlushRepository::zmqBufferStatus_f_3.bufferFullDetectionTime = processStartEpochSec;
//
//					IPFlushRepository::zmqBufferStatus_f_3.IP_ZMQ_FULL_FLAG = true;
//				}
//				else if(IPFlushRepository::zmq_flush_t_index != index)
//				{
//					dns_zmq_flush_map[dns_zmq_flush_map_cnt] = objXdrStore;
//					dns_zmq_flush_map_cnt++;
//				}
//				break;
//	}
//}

VOID DNSFlusher::flushDNSCsvRecords_f_0()
{
	if(strlen(csvXdr) <= 0)
		return;

	int index = PKT_WRITE_TIME_INDEX(IPGlobal::CURRENT_EPOCH_SEC, 10);

	if(IPGlobal::DNS_WRITE_XDR)
	{
		switch(index)
		{
			case 0:
				IPFlushRepository::dns_xdr_flush_f_0_t_0[IPFlushRepository::dns_xdr_flush_f_0_t_0_cnt] = objXdrStore;
				IPFlushRepository::dns_xdr_flush_f_0_t_0_cnt++;
				break;
			case 1:
				IPFlushRepository::dns_xdr_flush_f_0_t_1[IPFlushRepository::dns_xdr_flush_f_0_t_1_cnt] = objXdrStore;
				IPFlushRepository::dns_xdr_flush_f_0_t_1_cnt++;
				break;
			case 2:
				IPFlushRepository::dns_xdr_flush_f_0_t_2[IPFlushRepository::dns_xdr_flush_f_0_t_2_cnt] = objXdrStore;
				IPFlushRepository::dns_xdr_flush_f_0_t_2_cnt++;
				break;
			case 3:
				IPFlushRepository::dns_xdr_flush_f_0_t_3[IPFlushRepository::dns_xdr_flush_f_0_t_3_cnt] = objXdrStore;
				IPFlushRepository::dns_xdr_flush_f_0_t_3_cnt++;
				break;
			case 4:
				IPFlushRepository::dns_xdr_flush_f_0_t_4[IPFlushRepository::dns_xdr_flush_f_0_t_4_cnt] = objXdrStore;
				IPFlushRepository::dns_xdr_flush_f_0_t_4_cnt++;
				break;
			case 5:
				IPFlushRepository::dns_xdr_flush_f_0_t_5[IPFlushRepository::dns_xdr_flush_f_0_t_5_cnt] = objXdrStore;
				IPFlushRepository::dns_xdr_flush_f_0_t_5_cnt++;
				break;
			case 6:
				IPFlushRepository::dns_xdr_flush_f_0_t_6[IPFlushRepository::dns_xdr_flush_f_0_t_6_cnt] = objXdrStore;
				IPFlushRepository::dns_xdr_flush_f_0_t_6_cnt++;
				break;
			case 7:
				IPFlushRepository::dns_xdr_flush_f_0_t_7[IPFlushRepository::dns_xdr_flush_f_0_t_7_cnt] = objXdrStore;
				IPFlushRepository::dns_xdr_flush_f_0_t_7_cnt++;
				break;
			case 8:
				IPFlushRepository::dns_xdr_flush_f_0_t_8[IPFlushRepository::dns_xdr_flush_f_0_t_8_cnt] = objXdrStore;
				IPFlushRepository::dns_xdr_flush_f_0_t_8_cnt++;
				break;
			case 9:
				IPFlushRepository::dns_xdr_flush_f_0_t_9[IPFlushRepository::dns_xdr_flush_f_0_t_9_cnt] = objXdrStore;
				IPFlushRepository::dns_xdr_flush_f_0_t_9_cnt++;
				break;
		}
	}
}

VOID DNSFlusher::flushDNSCsvRecords_f_1()
{

	if(strlen(csvXdr) <= 0)
		return;


	int index = PKT_WRITE_TIME_INDEX(IPGlobal::CURRENT_EPOCH_SEC, 10);

	if(IPGlobal::DNS_WRITE_XDR)
	{
		switch(index)
		{
			case 0:
				IPFlushRepository::dns_xdr_flush_f_1_t_0[IPFlushRepository::dns_xdr_flush_f_1_t_0_cnt] = objXdrStore;
				IPFlushRepository::dns_xdr_flush_f_1_t_0_cnt++;
				break;
			case 1:
				IPFlushRepository::dns_xdr_flush_f_1_t_1[IPFlushRepository::dns_xdr_flush_f_1_t_1_cnt] = objXdrStore;
				IPFlushRepository::dns_xdr_flush_f_1_t_1_cnt++;
				break;
			case 2:
				IPFlushRepository::dns_xdr_flush_f_1_t_2[IPFlushRepository::dns_xdr_flush_f_1_t_2_cnt] = objXdrStore;
				IPFlushRepository::dns_xdr_flush_f_1_t_2_cnt++;
				break;
			case 3:
				IPFlushRepository::dns_xdr_flush_f_1_t_3[IPFlushRepository::dns_xdr_flush_f_1_t_3_cnt] = objXdrStore;
				IPFlushRepository::dns_xdr_flush_f_1_t_3_cnt++;
				break;
			case 4:
				IPFlushRepository::dns_xdr_flush_f_1_t_4[IPFlushRepository::dns_xdr_flush_f_1_t_4_cnt] = objXdrStore;
				IPFlushRepository::dns_xdr_flush_f_1_t_4_cnt++;
				break;
			case 5:
				IPFlushRepository::dns_xdr_flush_f_1_t_5[IPFlushRepository::dns_xdr_flush_f_1_t_5_cnt] = objXdrStore;
				IPFlushRepository::dns_xdr_flush_f_1_t_5_cnt++;
				break;
			case 6:
				IPFlushRepository::dns_xdr_flush_f_1_t_6[IPFlushRepository::dns_xdr_flush_f_1_t_6_cnt] = objXdrStore;
				IPFlushRepository::dns_xdr_flush_f_1_t_6_cnt++;
				break;
			case 7:
				IPFlushRepository::dns_xdr_flush_f_1_t_7[IPFlushRepository::dns_xdr_flush_f_1_t_7_cnt] = objXdrStore;
				IPFlushRepository::dns_xdr_flush_f_1_t_7_cnt++;
				break;
			case 8:
				IPFlushRepository::dns_xdr_flush_f_1_t_8[IPFlushRepository::dns_xdr_flush_f_1_t_8_cnt] = objXdrStore;
				IPFlushRepository::dns_xdr_flush_f_1_t_8_cnt++;
				break;
			case 9:
				IPFlushRepository::dns_xdr_flush_f_1_t_9[IPFlushRepository::dns_xdr_flush_f_1_t_9_cnt] = objXdrStore;
				IPFlushRepository::dns_xdr_flush_f_1_t_9_cnt++;
				break;
		}
	}
}

VOID DNSFlusher::flushDNSCsvRecords_f_2()
{
	if(strlen(csvXdr) <= 0)
		return;

	int index = PKT_WRITE_TIME_INDEX(IPGlobal::CURRENT_EPOCH_SEC, 10);

	if(IPGlobal::DNS_WRITE_XDR)
	{
		switch(index)
		{
			case 0:
				IPFlushRepository::dns_xdr_flush_f_2_t_0[IPFlushRepository::dns_xdr_flush_f_2_t_0_cnt] = objXdrStore;
				IPFlushRepository::dns_xdr_flush_f_2_t_0_cnt++;
				break;
			case 1:
				IPFlushRepository::dns_xdr_flush_f_2_t_1[IPFlushRepository::dns_xdr_flush_f_2_t_1_cnt] = objXdrStore;
				IPFlushRepository::dns_xdr_flush_f_2_t_1_cnt++;
				break;
			case 2:
				IPFlushRepository::dns_xdr_flush_f_2_t_2[IPFlushRepository::dns_xdr_flush_f_2_t_2_cnt] = objXdrStore;
				IPFlushRepository::dns_xdr_flush_f_2_t_2_cnt++;
				break;
			case 3:
				IPFlushRepository::dns_xdr_flush_f_2_t_3[IPFlushRepository::dns_xdr_flush_f_2_t_3_cnt] = objXdrStore;
				IPFlushRepository::dns_xdr_flush_f_2_t_3_cnt++;
				break;
			case 4:
				IPFlushRepository::dns_xdr_flush_f_2_t_4[IPFlushRepository::dns_xdr_flush_f_2_t_4_cnt] = objXdrStore;
				IPFlushRepository::dns_xdr_flush_f_2_t_4_cnt++;
				break;
			case 5:
				IPFlushRepository::dns_xdr_flush_f_2_t_5[IPFlushRepository::dns_xdr_flush_f_2_t_5_cnt] = objXdrStore;
				IPFlushRepository::dns_xdr_flush_f_2_t_5_cnt++;
				break;
			case 6:
				IPFlushRepository::dns_xdr_flush_f_2_t_6[IPFlushRepository::dns_xdr_flush_f_2_t_6_cnt] = objXdrStore;
				IPFlushRepository::dns_xdr_flush_f_2_t_6_cnt++;
				break;
			case 7:
				IPFlushRepository::dns_xdr_flush_f_2_t_7[IPFlushRepository::dns_xdr_flush_f_2_t_7_cnt] = objXdrStore;
				IPFlushRepository::dns_xdr_flush_f_2_t_7_cnt++;
				break;
			case 8:
				IPFlushRepository::dns_xdr_flush_f_2_t_8[IPFlushRepository::dns_xdr_flush_f_2_t_8_cnt] = objXdrStore;
				IPFlushRepository::dns_xdr_flush_f_2_t_8_cnt++;
				break;
			case 9:
				IPFlushRepository::dns_xdr_flush_f_2_t_9[IPFlushRepository::dns_xdr_flush_f_2_t_9_cnt] = objXdrStore;
				IPFlushRepository::dns_xdr_flush_f_2_t_9_cnt++;
				break;
		}
	}
}

VOID DNSFlusher::flushDNSCsvRecords_f_3()
{
	if(strlen(csvXdr) <= 0)
		return;

	int index = PKT_WRITE_TIME_INDEX(IPGlobal::CURRENT_EPOCH_SEC, 10);

	if(IPGlobal::DNS_WRITE_XDR)
	{
		switch(index)
		{
			case 0:
				IPFlushRepository::dns_xdr_flush_f_3_t_0[IPFlushRepository::dns_xdr_flush_f_3_t_0_cnt] = objXdrStore;
				IPFlushRepository::dns_xdr_flush_f_3_t_0_cnt++;
				break;
			case 1:
				IPFlushRepository::dns_xdr_flush_f_3_t_1[IPFlushRepository::dns_xdr_flush_f_3_t_1_cnt] = objXdrStore;
				IPFlushRepository::dns_xdr_flush_f_3_t_1_cnt++;
				break;
			case 2:
				IPFlushRepository::dns_xdr_flush_f_3_t_2[IPFlushRepository::dns_xdr_flush_f_3_t_2_cnt] = objXdrStore;
				IPFlushRepository::dns_xdr_flush_f_3_t_2_cnt++;
				break;
			case 3:
				IPFlushRepository::dns_xdr_flush_f_3_t_3[IPFlushRepository::dns_xdr_flush_f_3_t_3_cnt] = objXdrStore;
				IPFlushRepository::dns_xdr_flush_f_3_t_3_cnt++;
				break;
			case 4:
				IPFlushRepository::dns_xdr_flush_f_3_t_4[IPFlushRepository::dns_xdr_flush_f_3_t_4_cnt] = objXdrStore;
				IPFlushRepository::dns_xdr_flush_f_3_t_4_cnt++;
				break;
			case 5:
				IPFlushRepository::dns_xdr_flush_f_3_t_5[IPFlushRepository::dns_xdr_flush_f_3_t_5_cnt] = objXdrStore;
				IPFlushRepository::dns_xdr_flush_f_3_t_5_cnt++;
				break;
			case 6:
				IPFlushRepository::dns_xdr_flush_f_3_t_6[IPFlushRepository::dns_xdr_flush_f_3_t_6_cnt] = objXdrStore;
				IPFlushRepository::dns_xdr_flush_f_3_t_6_cnt++;
				break;
			case 7:
				IPFlushRepository::dns_xdr_flush_f_3_t_7[IPFlushRepository::dns_xdr_flush_f_3_t_7_cnt] = objXdrStore;
				IPFlushRepository::dns_xdr_flush_f_3_t_7_cnt++;
				break;
			case 8:
				IPFlushRepository::dns_xdr_flush_f_3_t_8[IPFlushRepository::dns_xdr_flush_f_3_t_8_cnt] = objXdrStore;
				IPFlushRepository::dns_xdr_flush_f_3_t_8_cnt++;
				break;
			case 9:
				IPFlushRepository::dns_xdr_flush_f_3_t_9[IPFlushRepository::dns_xdr_flush_f_3_t_9_cnt] = objXdrStore;
				IPFlushRepository::dns_xdr_flush_f_3_t_9_cnt++;
				break;
		}
	}
}

BOOL DNSFlusher::isRepositoryInitialized(){
	return repoInitStatus;
}


