/*
 * ProbeStatsLog.cpp
 *
 *  Created on: Jul 21, 2017
 *      Author: Debashis
 */

#include <ctime>
#include "ProbeStatsLog.h"

ProbeStatsLog::ProbeStatsLog() {
	this->_name = "ProbeStatsLog";
	this->setLogLevel(Log::theLog().level());
}

ProbeStatsLog::~ProbeStatsLog()
{}

void ProbeStatsLog::run()
{
	int		printloopCnt = 0, dd = 0, hh = 0, mm = 0, ss = 0;
	long 	startTime = 0, runTime = 0, currentHH = 0;
	char 	buffer[80];
	bool 	isStatsInitialized = false;

	struct tm *now_tm;

	gettimeofday(&curTime, NULL);
	startTime = curTime.tv_sec;

	for(nicCounter = 0; nicCounter < IPGlobal::NO_OF_NIC_INTERFACE; nicCounter++)
		INTERFACES_NAME[nicCounter] = IPGlobal::ETHERNET_INTERFACES[nicCounter];

	interfaceCounter = nicCounter;

	for(solCounter = 0; solCounter < IPGlobal::NO_OF_SOLAR_INTERFACE; solCounter++, interfaceCounter++)
		INTERFACES_NAME[interfaceCounter] = IPGlobal::SOLAR_INTERFACES[solCounter];

	while(IPGlobal::PROBE_STATS_RUNNING_STATUS)
	{
		  sleep(1);
		  printloopCnt++;

		  gettimeofday(&curTime, NULL);
		  runTime = curTime.tv_sec - startTime;

		  dd = (int)(runTime / 84600);
		  hh = (int)((runTime - (dd * 84600)) / 3600);
		  mm = (int)((runTime - ((dd * 84600) + (hh * 3600))) / 60);
		  ss = (int)(runTime - ((dd * 84600) + (hh * 3600) + (mm * 60)));
		  sprintf(buffer, "%03d:%03d:%03d:%03d", dd, hh, mm, ss);

		  if(printloopCnt >= IPGlobal::LOG_STATS_FREQ_SEC)
		  {
			  printloopCnt = 0;
			  printInterfaceStats(buffer);
		  }
	}
}

VOID ProbeStatsLog::printInterfaceStats(char *runTime)
{
	  TheLog_nc_v1(Log::Info, name(),"", "");

	  if(IPGlobal::NO_OF_INTERFACES > 0) {
		  TheLog_nc_v5(Log::Info, name(),"   Interface   [%6s] [%s] %08d PPS  %06d Mbps | Packet Rejected %011lu",
				  INTERFACES_NAME[0].c_str(), runTime, IPGlobal::PKT_RATE_INTF_0, IPGlobal::BW_MBPS_INTF_0, IPGlobal::ip_discarded_large_packets_i_0);
		  ProbeStatsLog::printPktStoreStats_i_0();
	  }
	  if(IPGlobal::NO_OF_INTERFACES > 1) {
		  TheLog_nc_v5(Log::Info, name(),"   Interface   [%6s] [%s] %08d PPS  %06d Mbps | Packet Rejected %011lu",
				  INTERFACES_NAME[1].c_str(), runTime, IPGlobal::PKT_RATE_INTF_1, IPGlobal::BW_MBPS_INTF_1, IPGlobal::ip_discarded_large_packets_i_1);
		  ProbeStatsLog::printPktStoreStats_i_1();
	  }
	  if(IPGlobal::NO_OF_INTERFACES > 2) {
		  TheLog_nc_v5(Log::Info, name(),"   Interface   [%6s] [%s] %08d PPS  %06d Mbps | Packet Rejected %011lu",
				  INTERFACES_NAME[2].c_str(), runTime, IPGlobal::PKT_RATE_INTF_2, IPGlobal::BW_MBPS_INTF_2, IPGlobal::ip_discarded_large_packets_i_2);
		  ProbeStatsLog::printPktStoreStats_i_2();
	  }
	  if(IPGlobal::NO_OF_INTERFACES > 3) {
		  TheLog_nc_v5(Log::Info, name(),"   Interface   [%6s] [%s] %08d PPS  %06d Mbps | Packet Rejected %011lu",
				  INTERFACES_NAME[3].c_str(), runTime, IPGlobal::PKT_RATE_INTF_3, IPGlobal::BW_MBPS_INTF_3, IPGlobal::ip_discarded_large_packets_i_3);
		  ProbeStatsLog::printPktStoreStats_i_3();
	  }
	  if(IPGlobal::NO_OF_INTERFACES > 4) {
		  TheLog_nc_v5(Log::Info, name(),"   Interface   [%6s] [%s] %08d PPS  %06d Mbps | Packet Rejected %011lu",
				  INTERFACES_NAME[4].c_str(), runTime, IPGlobal::PKT_RATE_INTF_4, IPGlobal::BW_MBPS_INTF_4, IPGlobal::ip_discarded_large_packets_i_4);
		  ProbeStatsLog::printPktStoreStats_i_4();
	  }
	  if(IPGlobal::NO_OF_INTERFACES > 5) {
		  TheLog_nc_v5(Log::Info, name(),"   Interface   [%6s] [%s] %08d PPS  %06d Mbps | Packet Rejected %011lu",
				  INTERFACES_NAME[5].c_str(), runTime, IPGlobal::PKT_RATE_INTF_5, IPGlobal::BW_MBPS_INTF_5, IPGlobal::ip_discarded_large_packets_i_5);
		  ProbeStatsLog::printPktStoreStats_i_5();
	  }
	  if(IPGlobal::NO_OF_INTERFACES > 6) {
		  TheLog_nc_v5(Log::Info, name(),"   Interface   [%6s] [%s] %08d PPS  %06d Mbps | Packet Rejected %011lu",
				  INTERFACES_NAME[6].c_str(), runTime, IPGlobal::PKT_RATE_INTF_6, IPGlobal::BW_MBPS_INTF_6, IPGlobal::ip_discarded_large_packets_i_6);
		  ProbeStatsLog::printPktStoreStats_i_6();
	  }
	  if(IPGlobal::NO_OF_INTERFACES > 7) {
		  TheLog_nc_v5(Log::Info, name(),"   Interface   [%6s] [%s] %08d PPS  %06d Mbps | Packet Rejected %011lu",
				  INTERFACES_NAME[7].c_str(), runTime, IPGlobal::PKT_RATE_INTF_7, IPGlobal::BW_MBPS_INTF_7, IPGlobal::ip_discarded_large_packets_i_7);
		  ProbeStatsLog::printPktStoreStats_i_7();
	  }

}

VOID ProbeStatsLog::printPktStoreStats_i_0()
{
	int r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11;
	char buffer[500];

	buffer[0] = 0;
	r0 = r1 = r2 = r3 = r4 = r5 = r6 = r7 = r8 = r9 = r10 = r11 = 0;

	r0 = PKTStore::pktRepository_i_0_r_0_t_0_cnt +
		 PKTStore::pktRepository_i_0_r_0_t_1_cnt +
		 PKTStore::pktRepository_i_0_r_0_t_2_cnt +
		 PKTStore::pktRepository_i_0_r_0_t_3_cnt +
		 PKTStore::pktRepository_i_0_r_0_t_4_cnt +
		 PKTStore::pktRepository_i_0_r_0_t_5_cnt +
		 PKTStore::pktRepository_i_0_r_0_t_6_cnt +
		 PKTStore::pktRepository_i_0_r_0_t_7_cnt +
		 PKTStore::pktRepository_i_0_r_0_t_8_cnt +
		 PKTStore::pktRepository_i_0_r_0_t_9_cnt;
	sprintf(buffer, "%07d", r0);

	if(IPGlobal::ROUTER_PER_INTERFACE[0] > 1) {
		r1 = PKTStore::pktRepository_i_0_r_1_t_0_cnt +
			 PKTStore::pktRepository_i_0_r_1_t_1_cnt +
			 PKTStore::pktRepository_i_0_r_1_t_2_cnt +
			 PKTStore::pktRepository_i_0_r_1_t_3_cnt +
			 PKTStore::pktRepository_i_0_r_1_t_4_cnt +
			 PKTStore::pktRepository_i_0_r_1_t_5_cnt +
			 PKTStore::pktRepository_i_0_r_1_t_6_cnt +
			 PKTStore::pktRepository_i_0_r_1_t_7_cnt +
			 PKTStore::pktRepository_i_0_r_1_t_8_cnt +
			 PKTStore::pktRepository_i_0_r_1_t_9_cnt;
		sprintf(buffer, "%07d  %07d", r0, r1);
	}

	if(IPGlobal::ROUTER_PER_INTERFACE[0] > 2) {
		r2 = PKTStore::pktRepository_i_0_r_2_t_0_cnt +
			 PKTStore::pktRepository_i_0_r_2_t_1_cnt +
			 PKTStore::pktRepository_i_0_r_2_t_2_cnt +
			 PKTStore::pktRepository_i_0_r_2_t_3_cnt +
			 PKTStore::pktRepository_i_0_r_2_t_4_cnt +
			 PKTStore::pktRepository_i_0_r_2_t_5_cnt +
			 PKTStore::pktRepository_i_0_r_2_t_6_cnt +
			 PKTStore::pktRepository_i_0_r_2_t_7_cnt +
			 PKTStore::pktRepository_i_0_r_2_t_8_cnt +
			 PKTStore::pktRepository_i_0_r_2_t_9_cnt;
		sprintf(buffer, "%07d  %07d  %07d", r0, r1, r2);
	}

	if(IPGlobal::ROUTER_PER_INTERFACE[0] > 3) {
		r3 = PKTStore::pktRepository_i_0_r_3_t_0_cnt +
			 PKTStore::pktRepository_i_0_r_3_t_1_cnt +
			 PKTStore::pktRepository_i_0_r_3_t_2_cnt +
			 PKTStore::pktRepository_i_0_r_3_t_3_cnt +
			 PKTStore::pktRepository_i_0_r_3_t_4_cnt +
			 PKTStore::pktRepository_i_0_r_3_t_5_cnt +
			 PKTStore::pktRepository_i_0_r_3_t_6_cnt +
			 PKTStore::pktRepository_i_0_r_3_t_7_cnt +
			 PKTStore::pktRepository_i_0_r_3_t_8_cnt +
			 PKTStore::pktRepository_i_0_r_3_t_9_cnt;
		sprintf(buffer, "%07d  %07d  %07d  %07d", r0, r1, r2, r3);
	}

	if(IPGlobal::ROUTER_PER_INTERFACE[0] > 4) {
		r4 = PKTStore::pktRepository_i_0_r_4_t_0_cnt +
			 PKTStore::pktRepository_i_0_r_4_t_1_cnt +
			 PKTStore::pktRepository_i_0_r_4_t_2_cnt +
			 PKTStore::pktRepository_i_0_r_4_t_3_cnt +
			 PKTStore::pktRepository_i_0_r_4_t_4_cnt +
			 PKTStore::pktRepository_i_0_r_4_t_5_cnt +
			 PKTStore::pktRepository_i_0_r_4_t_6_cnt +
			 PKTStore::pktRepository_i_0_r_4_t_7_cnt +
			 PKTStore::pktRepository_i_0_r_4_t_8_cnt +
			 PKTStore::pktRepository_i_0_r_4_t_9_cnt;
		sprintf(buffer, "%07d  %07d  %07d  %07d  %07d", r0, r1, r2, r3, r4);
	}

	if(IPGlobal::ROUTER_PER_INTERFACE[0] > 5) {
		r5 = PKTStore::pktRepository_i_0_r_5_t_0_cnt +
			 PKTStore::pktRepository_i_0_r_5_t_1_cnt +
			 PKTStore::pktRepository_i_0_r_5_t_2_cnt +
			 PKTStore::pktRepository_i_0_r_5_t_3_cnt +
			 PKTStore::pktRepository_i_0_r_5_t_4_cnt +
			 PKTStore::pktRepository_i_0_r_5_t_5_cnt +
			 PKTStore::pktRepository_i_0_r_5_t_6_cnt +
			 PKTStore::pktRepository_i_0_r_5_t_7_cnt +
			 PKTStore::pktRepository_i_0_r_5_t_8_cnt +
			 PKTStore::pktRepository_i_0_r_5_t_9_cnt;
		sprintf(buffer, "%07d  %07d  %07d  %07d  %07d  %07d", r0, r1, r2, r3, r4, r5);
	}

	if(IPGlobal::ROUTER_PER_INTERFACE[0] > 6) {
		r6 = PKTStore::pktRepository_i_0_r_6_t_0_cnt +
			 PKTStore::pktRepository_i_0_r_6_t_1_cnt +
			 PKTStore::pktRepository_i_0_r_6_t_2_cnt +
			 PKTStore::pktRepository_i_0_r_6_t_3_cnt +
			 PKTStore::pktRepository_i_0_r_6_t_4_cnt +
			 PKTStore::pktRepository_i_0_r_6_t_5_cnt +
			 PKTStore::pktRepository_i_0_r_6_t_6_cnt +
			 PKTStore::pktRepository_i_0_r_6_t_7_cnt +
			 PKTStore::pktRepository_i_0_r_6_t_8_cnt +
			 PKTStore::pktRepository_i_0_r_6_t_9_cnt;
		sprintf(buffer, "%07d  %07d  %07d  %07d  %07d  %07d  %07d", r0, r1, r2, r3, r4, r5, r6);
	}

	if(IPGlobal::ROUTER_PER_INTERFACE[0] > 7) {
		r7 = PKTStore::pktRepository_i_0_r_7_t_0_cnt +
			 PKTStore::pktRepository_i_0_r_7_t_1_cnt +
			 PKTStore::pktRepository_i_0_r_7_t_2_cnt +
			 PKTStore::pktRepository_i_0_r_7_t_3_cnt +
			 PKTStore::pktRepository_i_0_r_7_t_4_cnt +
			 PKTStore::pktRepository_i_0_r_7_t_5_cnt +
			 PKTStore::pktRepository_i_0_r_7_t_6_cnt +
			 PKTStore::pktRepository_i_0_r_7_t_7_cnt +
			 PKTStore::pktRepository_i_0_r_7_t_8_cnt +
			 PKTStore::pktRepository_i_0_r_7_t_9_cnt;
		sprintf(buffer, "%07d  %07d  %07d  %07d  %07d  %07d  %07d  %07d", r0, r1, r2, r3, r4, r5, r6, r7);

	}

	TheLog_nc_v2(Log::Info, name(), "   Interface(R)[%6s] %s", INTERFACES_NAME[0].c_str(), buffer);
	r0 = r1 = r2 = r3 = r4 = r5 = r6 = r7 = r8 = r9 = r10 = r11 = 0;
}

VOID ProbeStatsLog::printPktStoreStats_i_1()
{
	int r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11;
	char buffer[500];

	buffer[0] = 0;
	r0 = r1 = r2 = r3 = r4 = r5 = r6 = r7 = r8 = r9 = r10 = r11 = 0;

	r0 = PKTStore::pktRepository_i_1_r_0_t_0_cnt +
		 PKTStore::pktRepository_i_1_r_0_t_1_cnt +
		 PKTStore::pktRepository_i_1_r_0_t_2_cnt +
		 PKTStore::pktRepository_i_1_r_0_t_3_cnt +
		 PKTStore::pktRepository_i_1_r_0_t_4_cnt +
		 PKTStore::pktRepository_i_1_r_0_t_5_cnt +
		 PKTStore::pktRepository_i_1_r_0_t_6_cnt +
		 PKTStore::pktRepository_i_1_r_0_t_7_cnt +
		 PKTStore::pktRepository_i_1_r_0_t_8_cnt +
		 PKTStore::pktRepository_i_1_r_0_t_9_cnt;
	sprintf(buffer, "%07d", r0);

	if(IPGlobal::ROUTER_PER_INTERFACE[1] > 1) {
		r1 = PKTStore::pktRepository_i_1_r_1_t_0_cnt +
			 PKTStore::pktRepository_i_1_r_1_t_1_cnt +
			 PKTStore::pktRepository_i_1_r_1_t_2_cnt +
			 PKTStore::pktRepository_i_1_r_1_t_3_cnt +
			 PKTStore::pktRepository_i_1_r_1_t_4_cnt +
			 PKTStore::pktRepository_i_1_r_1_t_5_cnt +
			 PKTStore::pktRepository_i_1_r_1_t_6_cnt +
			 PKTStore::pktRepository_i_1_r_1_t_7_cnt +
			 PKTStore::pktRepository_i_1_r_1_t_8_cnt +
			 PKTStore::pktRepository_i_1_r_1_t_9_cnt;
		sprintf(buffer, "%07d  %07d", r0, r1);
	}

	if(IPGlobal::ROUTER_PER_INTERFACE[1] > 2) {
		r2 = PKTStore::pktRepository_i_1_r_2_t_0_cnt +
			 PKTStore::pktRepository_i_1_r_2_t_1_cnt +
			 PKTStore::pktRepository_i_1_r_2_t_2_cnt +
			 PKTStore::pktRepository_i_1_r_2_t_3_cnt +
			 PKTStore::pktRepository_i_1_r_2_t_4_cnt +
			 PKTStore::pktRepository_i_1_r_2_t_5_cnt +
			 PKTStore::pktRepository_i_1_r_2_t_6_cnt +
			 PKTStore::pktRepository_i_1_r_2_t_7_cnt +
			 PKTStore::pktRepository_i_1_r_2_t_8_cnt +
			 PKTStore::pktRepository_i_1_r_2_t_9_cnt;
		sprintf(buffer, "%07d  %07d  %07d", r0, r1, r2);
	}

	if(IPGlobal::ROUTER_PER_INTERFACE[1] > 3) {
		r3 = PKTStore::pktRepository_i_1_r_3_t_0_cnt +
			 PKTStore::pktRepository_i_1_r_3_t_1_cnt +
			 PKTStore::pktRepository_i_1_r_3_t_2_cnt +
			 PKTStore::pktRepository_i_1_r_3_t_3_cnt +
			 PKTStore::pktRepository_i_1_r_3_t_4_cnt +
			 PKTStore::pktRepository_i_1_r_3_t_5_cnt +
			 PKTStore::pktRepository_i_1_r_3_t_6_cnt +
			 PKTStore::pktRepository_i_1_r_3_t_7_cnt +
			 PKTStore::pktRepository_i_1_r_3_t_8_cnt +
			 PKTStore::pktRepository_i_1_r_3_t_9_cnt;
		sprintf(buffer, "%07d  %07d  %07d  %07d", r0, r1, r2, r3);
	}

	if(IPGlobal::ROUTER_PER_INTERFACE[1] > 4) {
		r4 = PKTStore::pktRepository_i_1_r_4_t_0_cnt +
			 PKTStore::pktRepository_i_1_r_4_t_1_cnt +
			 PKTStore::pktRepository_i_1_r_4_t_2_cnt +
			 PKTStore::pktRepository_i_1_r_4_t_3_cnt +
			 PKTStore::pktRepository_i_1_r_4_t_4_cnt +
			 PKTStore::pktRepository_i_1_r_4_t_5_cnt +
			 PKTStore::pktRepository_i_1_r_4_t_6_cnt +
			 PKTStore::pktRepository_i_1_r_4_t_7_cnt +
			 PKTStore::pktRepository_i_1_r_4_t_8_cnt +
			 PKTStore::pktRepository_i_1_r_4_t_9_cnt;
		sprintf(buffer, "%07d  %07d  %07d  %07d  %07d", r0, r1, r2, r3, r4);
	}

	if(IPGlobal::ROUTER_PER_INTERFACE[1] > 5) {
		r5 = PKTStore::pktRepository_i_1_r_5_t_0_cnt +
			 PKTStore::pktRepository_i_1_r_5_t_1_cnt +
			 PKTStore::pktRepository_i_1_r_5_t_2_cnt +
			 PKTStore::pktRepository_i_1_r_5_t_3_cnt +
			 PKTStore::pktRepository_i_1_r_5_t_4_cnt +
			 PKTStore::pktRepository_i_1_r_5_t_5_cnt +
			 PKTStore::pktRepository_i_1_r_5_t_6_cnt +
			 PKTStore::pktRepository_i_1_r_5_t_7_cnt +
			 PKTStore::pktRepository_i_1_r_5_t_8_cnt +
			 PKTStore::pktRepository_i_1_r_5_t_9_cnt;
		sprintf(buffer, "%07d  %07d  %07d  %07d  %07d  %07d", r0, r1, r2, r3, r4, r5);
	}

	if(IPGlobal::ROUTER_PER_INTERFACE[1] > 6) {
		r6 = PKTStore::pktRepository_i_1_r_6_t_0_cnt +
			 PKTStore::pktRepository_i_1_r_6_t_1_cnt +
			 PKTStore::pktRepository_i_1_r_6_t_2_cnt +
			 PKTStore::pktRepository_i_1_r_6_t_3_cnt +
			 PKTStore::pktRepository_i_1_r_6_t_4_cnt +
			 PKTStore::pktRepository_i_1_r_6_t_5_cnt +
			 PKTStore::pktRepository_i_1_r_6_t_6_cnt +
			 PKTStore::pktRepository_i_1_r_6_t_7_cnt +
			 PKTStore::pktRepository_i_1_r_6_t_8_cnt +
			 PKTStore::pktRepository_i_1_r_6_t_9_cnt;
		sprintf(buffer, "%07d  %07d  %07d  %07d  %07d  %07d  %07d", r0, r1, r2, r3, r4, r5, r6);
	}

	if(IPGlobal::ROUTER_PER_INTERFACE[1] > 7) {
		r7 = PKTStore::pktRepository_i_1_r_7_t_0_cnt +
			 PKTStore::pktRepository_i_1_r_7_t_1_cnt +
			 PKTStore::pktRepository_i_1_r_7_t_2_cnt +
			 PKTStore::pktRepository_i_1_r_7_t_3_cnt +
			 PKTStore::pktRepository_i_1_r_7_t_4_cnt +
			 PKTStore::pktRepository_i_1_r_7_t_5_cnt +
			 PKTStore::pktRepository_i_1_r_7_t_6_cnt +
			 PKTStore::pktRepository_i_1_r_7_t_7_cnt +
			 PKTStore::pktRepository_i_1_r_7_t_8_cnt +
			 PKTStore::pktRepository_i_1_r_7_t_9_cnt;
		sprintf(buffer, "%07d  %07d  %07d  %07d  %07d  %07d  %07d  %07d", r0, r1, r2, r3, r4, r5, r6, r7);

	}

	TheLog_nc_v2(Log::Info, name(), "   Interface(R)[%6s] %s", INTERFACES_NAME[1].c_str(), buffer);
	r0 = r1 = r2 = r3 = r4 = r5 = r6 = r7 = r8 = r9 = r10 = r11 = 0;
}

VOID ProbeStatsLog::printPktStoreStats_i_2()
{
	int r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11;
	char buffer[500];

	buffer[0] = 0;
	r0 = r1 = r2 = r3 = r4 = r5 = r6 = r7 = r8 = r9 = r10 = r11 = 0;

	r0 = PKTStore::pktRepository_i_2_r_0_t_0_cnt +
		 PKTStore::pktRepository_i_2_r_0_t_1_cnt +
		 PKTStore::pktRepository_i_2_r_0_t_2_cnt +
		 PKTStore::pktRepository_i_2_r_0_t_3_cnt +
		 PKTStore::pktRepository_i_2_r_0_t_4_cnt +
		 PKTStore::pktRepository_i_2_r_0_t_5_cnt +
		 PKTStore::pktRepository_i_2_r_0_t_6_cnt +
		 PKTStore::pktRepository_i_2_r_0_t_7_cnt +
		 PKTStore::pktRepository_i_2_r_0_t_8_cnt +
		 PKTStore::pktRepository_i_2_r_0_t_9_cnt;
	sprintf(buffer, "%07d", r0);

	if(IPGlobal::ROUTER_PER_INTERFACE[2] > 1) {
		r1 = PKTStore::pktRepository_i_2_r_1_t_0_cnt +
			 PKTStore::pktRepository_i_2_r_1_t_1_cnt +
			 PKTStore::pktRepository_i_2_r_1_t_2_cnt +
			 PKTStore::pktRepository_i_2_r_1_t_3_cnt +
			 PKTStore::pktRepository_i_2_r_1_t_4_cnt +
			 PKTStore::pktRepository_i_2_r_1_t_5_cnt +
			 PKTStore::pktRepository_i_2_r_1_t_6_cnt +
			 PKTStore::pktRepository_i_2_r_1_t_7_cnt +
			 PKTStore::pktRepository_i_2_r_1_t_8_cnt +
			 PKTStore::pktRepository_i_2_r_1_t_9_cnt;
		sprintf(buffer, "%07d  %07d", r0, r1);
	}

	if(IPGlobal::ROUTER_PER_INTERFACE[2] > 2) {
		r2 = PKTStore::pktRepository_i_2_r_2_t_0_cnt +
			 PKTStore::pktRepository_i_2_r_2_t_1_cnt +
			 PKTStore::pktRepository_i_2_r_2_t_2_cnt +
			 PKTStore::pktRepository_i_2_r_2_t_3_cnt +
			 PKTStore::pktRepository_i_2_r_2_t_4_cnt +
			 PKTStore::pktRepository_i_2_r_2_t_5_cnt +
			 PKTStore::pktRepository_i_2_r_2_t_6_cnt +
			 PKTStore::pktRepository_i_2_r_2_t_7_cnt +
			 PKTStore::pktRepository_i_2_r_2_t_8_cnt +
			 PKTStore::pktRepository_i_2_r_2_t_9_cnt;
		sprintf(buffer, "%07d  %07d  %07d", r0, r1, r2);
	}

	if(IPGlobal::ROUTER_PER_INTERFACE[2] > 3) {
		r3 = PKTStore::pktRepository_i_2_r_3_t_0_cnt +
			 PKTStore::pktRepository_i_2_r_3_t_1_cnt +
			 PKTStore::pktRepository_i_2_r_3_t_2_cnt +
			 PKTStore::pktRepository_i_2_r_3_t_3_cnt +
			 PKTStore::pktRepository_i_2_r_3_t_4_cnt +
			 PKTStore::pktRepository_i_2_r_3_t_5_cnt +
			 PKTStore::pktRepository_i_2_r_3_t_6_cnt +
			 PKTStore::pktRepository_i_2_r_3_t_7_cnt +
			 PKTStore::pktRepository_i_2_r_3_t_8_cnt +
			 PKTStore::pktRepository_i_2_r_3_t_9_cnt;
		sprintf(buffer, "%07d  %07d  %07d  %07d", r0, r1, r2, r3);
	}

	if(IPGlobal::ROUTER_PER_INTERFACE[2] > 4) {
		r4 = PKTStore::pktRepository_i_2_r_4_t_0_cnt +
			 PKTStore::pktRepository_i_2_r_4_t_1_cnt +
			 PKTStore::pktRepository_i_2_r_4_t_2_cnt +
			 PKTStore::pktRepository_i_2_r_4_t_3_cnt +
			 PKTStore::pktRepository_i_2_r_4_t_4_cnt +
			 PKTStore::pktRepository_i_2_r_4_t_5_cnt +
			 PKTStore::pktRepository_i_2_r_4_t_6_cnt +
			 PKTStore::pktRepository_i_2_r_4_t_7_cnt +
			 PKTStore::pktRepository_i_2_r_4_t_8_cnt +
			 PKTStore::pktRepository_i_2_r_4_t_9_cnt;
		sprintf(buffer, "%07d  %07d  %07d  %07d  %07d", r0, r1, r2, r3, r4);
	}

	if(IPGlobal::ROUTER_PER_INTERFACE[2] > 5) {
		r5 = PKTStore::pktRepository_i_2_r_5_t_0_cnt +
			 PKTStore::pktRepository_i_2_r_5_t_1_cnt +
			 PKTStore::pktRepository_i_2_r_5_t_2_cnt +
			 PKTStore::pktRepository_i_2_r_5_t_3_cnt +
			 PKTStore::pktRepository_i_2_r_5_t_4_cnt +
			 PKTStore::pktRepository_i_2_r_5_t_5_cnt +
			 PKTStore::pktRepository_i_2_r_5_t_6_cnt +
			 PKTStore::pktRepository_i_2_r_5_t_7_cnt +
			 PKTStore::pktRepository_i_2_r_5_t_8_cnt +
			 PKTStore::pktRepository_i_2_r_5_t_9_cnt;
		sprintf(buffer, "%07d  %07d  %07d  %07d  %07d  %07d", r0, r1, r2, r3, r4, r5);
	}

	if(IPGlobal::ROUTER_PER_INTERFACE[2] > 6) {
		r6 = PKTStore::pktRepository_i_2_r_6_t_0_cnt +
			 PKTStore::pktRepository_i_2_r_6_t_1_cnt +
			 PKTStore::pktRepository_i_2_r_6_t_2_cnt +
			 PKTStore::pktRepository_i_2_r_6_t_3_cnt +
			 PKTStore::pktRepository_i_2_r_6_t_4_cnt +
			 PKTStore::pktRepository_i_2_r_6_t_5_cnt +
			 PKTStore::pktRepository_i_2_r_6_t_6_cnt +
			 PKTStore::pktRepository_i_2_r_6_t_7_cnt +
			 PKTStore::pktRepository_i_2_r_6_t_8_cnt +
			 PKTStore::pktRepository_i_2_r_6_t_9_cnt;
		sprintf(buffer, "%07d  %07d  %07d  %07d  %07d  %07d  %07d", r0, r1, r2, r3, r4, r5, r6);
	}

	if(IPGlobal::ROUTER_PER_INTERFACE[2] > 7) {
		r7 = PKTStore::pktRepository_i_2_r_7_t_0_cnt +
			 PKTStore::pktRepository_i_2_r_7_t_1_cnt +
			 PKTStore::pktRepository_i_2_r_7_t_2_cnt +
			 PKTStore::pktRepository_i_2_r_7_t_3_cnt +
			 PKTStore::pktRepository_i_2_r_7_t_4_cnt +
			 PKTStore::pktRepository_i_2_r_7_t_5_cnt +
			 PKTStore::pktRepository_i_2_r_7_t_6_cnt +
			 PKTStore::pktRepository_i_2_r_7_t_7_cnt +
			 PKTStore::pktRepository_i_2_r_7_t_8_cnt +
			 PKTStore::pktRepository_i_2_r_7_t_9_cnt;
		sprintf(buffer, "%07d  %07d  %07d  %07d  %07d  %07d  %07d  %07d", r0, r1, r2, r3, r4, r5, r6, r7);

	}

	TheLog_nc_v2(Log::Info, name(), "   Interface(R)[%6s] %s", INTERFACES_NAME[2].c_str(), buffer);
	r0 = r1 = r2 = r3 = r4 = r5 = r6 = r7 = r8 = r9 = r10 = r11 = 0;
}

VOID ProbeStatsLog::printPktStoreStats_i_3()
{
	int r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11;
	char buffer[500];

	buffer[0] = 0;
	r0 = r1 = r2 = r3 = r4 = r5 = r6 = r7 = r8 = r9 = r10 = r11 = 0;

	r0 = PKTStore::pktRepository_i_3_r_0_t_0_cnt +
		 PKTStore::pktRepository_i_3_r_0_t_1_cnt +
		 PKTStore::pktRepository_i_3_r_0_t_2_cnt +
		 PKTStore::pktRepository_i_3_r_0_t_3_cnt +
		 PKTStore::pktRepository_i_3_r_0_t_4_cnt +
		 PKTStore::pktRepository_i_3_r_0_t_5_cnt +
		 PKTStore::pktRepository_i_3_r_0_t_6_cnt +
		 PKTStore::pktRepository_i_3_r_0_t_7_cnt +
		 PKTStore::pktRepository_i_3_r_0_t_8_cnt +
		 PKTStore::pktRepository_i_3_r_0_t_9_cnt;
	sprintf(buffer, "%07d", r0);

	if(IPGlobal::ROUTER_PER_INTERFACE[3] > 1) {
		r1 = PKTStore::pktRepository_i_3_r_1_t_0_cnt +
			 PKTStore::pktRepository_i_3_r_1_t_1_cnt +
			 PKTStore::pktRepository_i_3_r_1_t_2_cnt +
			 PKTStore::pktRepository_i_3_r_1_t_3_cnt +
			 PKTStore::pktRepository_i_3_r_1_t_4_cnt +
			 PKTStore::pktRepository_i_3_r_1_t_5_cnt +
			 PKTStore::pktRepository_i_3_r_1_t_6_cnt +
			 PKTStore::pktRepository_i_3_r_1_t_7_cnt +
			 PKTStore::pktRepository_i_3_r_1_t_8_cnt +
			 PKTStore::pktRepository_i_3_r_1_t_9_cnt;
		sprintf(buffer, "%07d  %07d", r0, r1);
	}

	if(IPGlobal::ROUTER_PER_INTERFACE[3] > 2) {
		r2 = PKTStore::pktRepository_i_3_r_2_t_0_cnt +
			 PKTStore::pktRepository_i_3_r_2_t_1_cnt +
			 PKTStore::pktRepository_i_3_r_2_t_2_cnt +
			 PKTStore::pktRepository_i_3_r_2_t_3_cnt +
			 PKTStore::pktRepository_i_3_r_2_t_4_cnt +
			 PKTStore::pktRepository_i_3_r_2_t_5_cnt +
			 PKTStore::pktRepository_i_3_r_2_t_6_cnt +
			 PKTStore::pktRepository_i_3_r_2_t_7_cnt +
			 PKTStore::pktRepository_i_3_r_2_t_8_cnt +
			 PKTStore::pktRepository_i_3_r_2_t_9_cnt;
		sprintf(buffer, "%07d  %07d  %07d", r0, r1, r2);
	}

	if(IPGlobal::ROUTER_PER_INTERFACE[3] > 3) {
		r3 = PKTStore::pktRepository_i_3_r_3_t_0_cnt +
			 PKTStore::pktRepository_i_3_r_3_t_1_cnt +
			 PKTStore::pktRepository_i_3_r_3_t_2_cnt +
			 PKTStore::pktRepository_i_3_r_3_t_3_cnt +
			 PKTStore::pktRepository_i_3_r_3_t_4_cnt +
			 PKTStore::pktRepository_i_3_r_3_t_5_cnt +
			 PKTStore::pktRepository_i_3_r_3_t_6_cnt +
			 PKTStore::pktRepository_i_3_r_3_t_7_cnt +
			 PKTStore::pktRepository_i_3_r_3_t_8_cnt +
			 PKTStore::pktRepository_i_3_r_3_t_9_cnt;
		sprintf(buffer, "%07d  %07d  %07d  %07d", r0, r1, r2, r3);
	}

	if(IPGlobal::ROUTER_PER_INTERFACE[3] > 4) {
		r4 = PKTStore::pktRepository_i_3_r_4_t_0_cnt +
			 PKTStore::pktRepository_i_3_r_4_t_1_cnt +
			 PKTStore::pktRepository_i_3_r_4_t_2_cnt +
			 PKTStore::pktRepository_i_3_r_4_t_3_cnt +
			 PKTStore::pktRepository_i_3_r_4_t_4_cnt +
			 PKTStore::pktRepository_i_3_r_4_t_5_cnt +
			 PKTStore::pktRepository_i_3_r_4_t_6_cnt +
			 PKTStore::pktRepository_i_3_r_4_t_7_cnt +
			 PKTStore::pktRepository_i_3_r_4_t_8_cnt +
			 PKTStore::pktRepository_i_3_r_4_t_9_cnt;
		sprintf(buffer, "%07d  %07d  %07d  %07d  %07d", r0, r1, r2, r3, r4);
	}

	if(IPGlobal::ROUTER_PER_INTERFACE[3] > 5) {
		r5 = PKTStore::pktRepository_i_3_r_5_t_0_cnt +
			 PKTStore::pktRepository_i_3_r_5_t_1_cnt +
			 PKTStore::pktRepository_i_3_r_5_t_2_cnt +
			 PKTStore::pktRepository_i_3_r_5_t_3_cnt +
			 PKTStore::pktRepository_i_3_r_5_t_4_cnt +
			 PKTStore::pktRepository_i_3_r_5_t_5_cnt +
			 PKTStore::pktRepository_i_3_r_5_t_6_cnt +
			 PKTStore::pktRepository_i_3_r_5_t_7_cnt +
			 PKTStore::pktRepository_i_3_r_5_t_8_cnt +
			 PKTStore::pktRepository_i_3_r_5_t_9_cnt;
		sprintf(buffer, "%07d  %07d  %07d  %07d  %07d  %07d", r0, r1, r2, r3, r4, r5);
	}

	if(IPGlobal::ROUTER_PER_INTERFACE[3] > 6) {
		r6 = PKTStore::pktRepository_i_3_r_6_t_0_cnt +
			 PKTStore::pktRepository_i_3_r_6_t_1_cnt +
			 PKTStore::pktRepository_i_3_r_6_t_2_cnt +
			 PKTStore::pktRepository_i_3_r_6_t_3_cnt +
			 PKTStore::pktRepository_i_3_r_6_t_4_cnt +
			 PKTStore::pktRepository_i_3_r_6_t_5_cnt +
			 PKTStore::pktRepository_i_3_r_6_t_6_cnt +
			 PKTStore::pktRepository_i_3_r_6_t_7_cnt +
			 PKTStore::pktRepository_i_3_r_6_t_8_cnt +
			 PKTStore::pktRepository_i_3_r_6_t_9_cnt;
		sprintf(buffer, "%07d  %07d  %07d  %07d  %07d  %07d  %07d", r0, r1, r2, r3, r4, r5, r6);
	}

	if(IPGlobal::ROUTER_PER_INTERFACE[3] > 7) {
		r7 = PKTStore::pktRepository_i_3_r_7_t_0_cnt +
			 PKTStore::pktRepository_i_3_r_7_t_1_cnt +
			 PKTStore::pktRepository_i_3_r_7_t_2_cnt +
			 PKTStore::pktRepository_i_3_r_7_t_3_cnt +
			 PKTStore::pktRepository_i_3_r_7_t_4_cnt +
			 PKTStore::pktRepository_i_3_r_7_t_5_cnt +
			 PKTStore::pktRepository_i_3_r_7_t_6_cnt +
			 PKTStore::pktRepository_i_3_r_7_t_7_cnt +
			 PKTStore::pktRepository_i_3_r_7_t_8_cnt +
			 PKTStore::pktRepository_i_3_r_7_t_9_cnt;
		sprintf(buffer, "%07d  %07d  %07d  %07d  %07d  %07d  %07d  %07d", r0, r1, r2, r3, r4, r5, r6, r7);

	}

	TheLog_nc_v2(Log::Info, name(), "   Interface(R)[%6s] %s", INTERFACES_NAME[3].c_str(), buffer);
	r0 = r1 = r2 = r3 = r4 = r5 = r6 = r7 = r8 = r9 = r10 = r11 = 0;
}

VOID ProbeStatsLog::printPktStoreStats_i_4()
{
	int r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11;
	char buffer[500];

	buffer[0] = 0;
	r0 = r1 = r2 = r3 = r4 = r5 = r6 = r7 = r8 = r9 = r10 = r11 = 0;

	r0 = PKTStore::pktRepository_i_4_r_0_t_0_cnt +
		 PKTStore::pktRepository_i_4_r_0_t_1_cnt +
		 PKTStore::pktRepository_i_4_r_0_t_2_cnt +
		 PKTStore::pktRepository_i_4_r_0_t_3_cnt +
		 PKTStore::pktRepository_i_4_r_0_t_4_cnt +
		 PKTStore::pktRepository_i_4_r_0_t_5_cnt +
		 PKTStore::pktRepository_i_4_r_0_t_6_cnt +
		 PKTStore::pktRepository_i_4_r_0_t_7_cnt +
		 PKTStore::pktRepository_i_4_r_0_t_8_cnt +
		 PKTStore::pktRepository_i_4_r_0_t_9_cnt;
	sprintf(buffer, "%07d", r0);

	if(IPGlobal::ROUTER_PER_INTERFACE[4] > 1) {
		r1 = PKTStore::pktRepository_i_4_r_1_t_0_cnt +
			 PKTStore::pktRepository_i_4_r_1_t_1_cnt +
			 PKTStore::pktRepository_i_4_r_1_t_2_cnt +
			 PKTStore::pktRepository_i_4_r_1_t_3_cnt +
			 PKTStore::pktRepository_i_4_r_1_t_4_cnt +
			 PKTStore::pktRepository_i_4_r_1_t_5_cnt +
			 PKTStore::pktRepository_i_4_r_1_t_6_cnt +
			 PKTStore::pktRepository_i_4_r_1_t_7_cnt +
			 PKTStore::pktRepository_i_4_r_1_t_8_cnt +
			 PKTStore::pktRepository_i_4_r_1_t_9_cnt;
		sprintf(buffer, "%07d  %07d", r0, r1);
	}

	if(IPGlobal::ROUTER_PER_INTERFACE[4] > 2) {
		r2 = PKTStore::pktRepository_i_4_r_2_t_0_cnt +
			 PKTStore::pktRepository_i_4_r_2_t_1_cnt +
			 PKTStore::pktRepository_i_4_r_2_t_2_cnt +
			 PKTStore::pktRepository_i_4_r_2_t_3_cnt +
			 PKTStore::pktRepository_i_4_r_2_t_4_cnt +
			 PKTStore::pktRepository_i_4_r_2_t_5_cnt +
			 PKTStore::pktRepository_i_4_r_2_t_6_cnt +
			 PKTStore::pktRepository_i_4_r_2_t_7_cnt +
			 PKTStore::pktRepository_i_4_r_2_t_8_cnt +
			 PKTStore::pktRepository_i_4_r_2_t_9_cnt;
		sprintf(buffer, "%07d  %07d  %07d", r0, r1, r2);
	}

	if(IPGlobal::ROUTER_PER_INTERFACE[4] > 3) {
		r3 = PKTStore::pktRepository_i_4_r_3_t_0_cnt +
			 PKTStore::pktRepository_i_4_r_3_t_1_cnt +
			 PKTStore::pktRepository_i_4_r_3_t_2_cnt +
			 PKTStore::pktRepository_i_4_r_3_t_3_cnt +
			 PKTStore::pktRepository_i_4_r_3_t_4_cnt +
			 PKTStore::pktRepository_i_4_r_3_t_5_cnt +
			 PKTStore::pktRepository_i_4_r_3_t_6_cnt +
			 PKTStore::pktRepository_i_4_r_3_t_7_cnt +
			 PKTStore::pktRepository_i_4_r_3_t_8_cnt +
			 PKTStore::pktRepository_i_4_r_3_t_9_cnt;
		sprintf(buffer, "%07d  %07d  %07d  %07d", r0, r1, r2, r3);
	}

	if(IPGlobal::ROUTER_PER_INTERFACE[4] > 4) {
		r4 = PKTStore::pktRepository_i_4_r_4_t_0_cnt +
			 PKTStore::pktRepository_i_4_r_4_t_1_cnt +
			 PKTStore::pktRepository_i_4_r_4_t_2_cnt +
			 PKTStore::pktRepository_i_4_r_4_t_3_cnt +
			 PKTStore::pktRepository_i_4_r_4_t_4_cnt +
			 PKTStore::pktRepository_i_4_r_4_t_5_cnt +
			 PKTStore::pktRepository_i_4_r_4_t_6_cnt +
			 PKTStore::pktRepository_i_4_r_4_t_7_cnt +
			 PKTStore::pktRepository_i_4_r_4_t_8_cnt +
			 PKTStore::pktRepository_i_4_r_4_t_9_cnt;
		sprintf(buffer, "%07d  %07d  %07d  %07d  %07d", r0, r1, r2, r3, r4);
	}

	if(IPGlobal::ROUTER_PER_INTERFACE[4] > 5) {
		r5 = PKTStore::pktRepository_i_4_r_5_t_0_cnt +
			 PKTStore::pktRepository_i_4_r_5_t_1_cnt +
			 PKTStore::pktRepository_i_4_r_5_t_2_cnt +
			 PKTStore::pktRepository_i_4_r_5_t_3_cnt +
			 PKTStore::pktRepository_i_4_r_5_t_4_cnt +
			 PKTStore::pktRepository_i_4_r_5_t_5_cnt +
			 PKTStore::pktRepository_i_4_r_5_t_6_cnt +
			 PKTStore::pktRepository_i_4_r_5_t_7_cnt +
			 PKTStore::pktRepository_i_4_r_5_t_8_cnt +
			 PKTStore::pktRepository_i_4_r_5_t_9_cnt;
		sprintf(buffer, "%07d  %07d  %07d  %07d  %07d  %07d", r0, r1, r2, r3, r4, r5);
	}

	if(IPGlobal::ROUTER_PER_INTERFACE[4] > 6) {
		r6 = PKTStore::pktRepository_i_4_r_6_t_0_cnt +
			 PKTStore::pktRepository_i_4_r_6_t_1_cnt +
			 PKTStore::pktRepository_i_4_r_6_t_2_cnt +
			 PKTStore::pktRepository_i_4_r_6_t_3_cnt +
			 PKTStore::pktRepository_i_4_r_6_t_4_cnt +
			 PKTStore::pktRepository_i_4_r_6_t_5_cnt +
			 PKTStore::pktRepository_i_4_r_6_t_6_cnt +
			 PKTStore::pktRepository_i_4_r_6_t_7_cnt +
			 PKTStore::pktRepository_i_4_r_6_t_8_cnt +
			 PKTStore::pktRepository_i_4_r_6_t_9_cnt;
		sprintf(buffer, "%07d  %07d  %07d  %07d  %07d  %07d  %07d", r0, r1, r2, r3, r4, r5, r6);
	}

	if(IPGlobal::ROUTER_PER_INTERFACE[4] > 7) {
		r7 = PKTStore::pktRepository_i_4_r_7_t_0_cnt +
			 PKTStore::pktRepository_i_4_r_7_t_1_cnt +
			 PKTStore::pktRepository_i_4_r_7_t_2_cnt +
			 PKTStore::pktRepository_i_4_r_7_t_3_cnt +
			 PKTStore::pktRepository_i_4_r_7_t_4_cnt +
			 PKTStore::pktRepository_i_4_r_7_t_5_cnt +
			 PKTStore::pktRepository_i_4_r_7_t_6_cnt +
			 PKTStore::pktRepository_i_4_r_7_t_7_cnt +
			 PKTStore::pktRepository_i_4_r_7_t_8_cnt +
			 PKTStore::pktRepository_i_4_r_7_t_9_cnt;
		sprintf(buffer, "%07d  %07d  %07d  %07d  %07d  %07d  %07d  %07d", r0, r1, r2, r3, r4, r5, r6, r7);

	}

	TheLog_nc_v2(Log::Info, name(), "   Interface(R)[%6s] %s", INTERFACES_NAME[4].c_str(), buffer);
	r0 = r1 = r2 = r3 = r4 = r5 = r6 = r7 = r8 = r9 = r10 = r11 = 0;
}

VOID ProbeStatsLog::printPktStoreStats_i_5()
{
	int r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11;
	char buffer[500];

	buffer[0] = 0;
	r0 = r1 = r2 = r3 = r4 = r5 = r6 = r7 = r8 = r9 = r10 = r11 = 0;

	r0 = PKTStore::pktRepository_i_5_r_0_t_0_cnt +
		 PKTStore::pktRepository_i_5_r_0_t_1_cnt +
		 PKTStore::pktRepository_i_5_r_0_t_2_cnt +
		 PKTStore::pktRepository_i_5_r_0_t_3_cnt +
		 PKTStore::pktRepository_i_5_r_0_t_4_cnt +
		 PKTStore::pktRepository_i_5_r_0_t_5_cnt +
		 PKTStore::pktRepository_i_5_r_0_t_6_cnt +
		 PKTStore::pktRepository_i_5_r_0_t_7_cnt +
		 PKTStore::pktRepository_i_5_r_0_t_8_cnt +
		 PKTStore::pktRepository_i_5_r_0_t_9_cnt;
	sprintf(buffer, "%07d", r0);

	if(IPGlobal::ROUTER_PER_INTERFACE[5] > 1) {
		r1 = PKTStore::pktRepository_i_5_r_1_t_0_cnt +
			 PKTStore::pktRepository_i_5_r_1_t_1_cnt +
			 PKTStore::pktRepository_i_5_r_1_t_2_cnt +
			 PKTStore::pktRepository_i_5_r_1_t_3_cnt +
			 PKTStore::pktRepository_i_5_r_1_t_4_cnt +
			 PKTStore::pktRepository_i_5_r_1_t_5_cnt +
			 PKTStore::pktRepository_i_5_r_1_t_6_cnt +
			 PKTStore::pktRepository_i_5_r_1_t_7_cnt +
			 PKTStore::pktRepository_i_5_r_1_t_8_cnt +
			 PKTStore::pktRepository_i_5_r_1_t_9_cnt;
		sprintf(buffer, "%07d  %07d", r0, r1);
	}

	if(IPGlobal::ROUTER_PER_INTERFACE[5] > 2) {
		r2 = PKTStore::pktRepository_i_5_r_2_t_0_cnt +
			 PKTStore::pktRepository_i_5_r_2_t_1_cnt +
			 PKTStore::pktRepository_i_5_r_2_t_2_cnt +
			 PKTStore::pktRepository_i_5_r_2_t_3_cnt +
			 PKTStore::pktRepository_i_5_r_2_t_4_cnt +
			 PKTStore::pktRepository_i_5_r_2_t_5_cnt +
			 PKTStore::pktRepository_i_5_r_2_t_6_cnt +
			 PKTStore::pktRepository_i_5_r_2_t_7_cnt +
			 PKTStore::pktRepository_i_5_r_2_t_8_cnt +
			 PKTStore::pktRepository_i_5_r_2_t_9_cnt;
		sprintf(buffer, "%07d  %07d  %07d", r0, r1, r2);
	}

	if(IPGlobal::ROUTER_PER_INTERFACE[5] > 3) {
		r3 = PKTStore::pktRepository_i_5_r_3_t_0_cnt +
			 PKTStore::pktRepository_i_5_r_3_t_1_cnt +
			 PKTStore::pktRepository_i_5_r_3_t_2_cnt +
			 PKTStore::pktRepository_i_5_r_3_t_3_cnt +
			 PKTStore::pktRepository_i_5_r_3_t_4_cnt +
			 PKTStore::pktRepository_i_5_r_3_t_5_cnt +
			 PKTStore::pktRepository_i_5_r_3_t_6_cnt +
			 PKTStore::pktRepository_i_5_r_3_t_7_cnt +
			 PKTStore::pktRepository_i_5_r_3_t_8_cnt +
			 PKTStore::pktRepository_i_5_r_3_t_9_cnt;
		sprintf(buffer, "%07d  %07d  %07d  %07d", r0, r1, r2, r3);
	}

	if(IPGlobal::ROUTER_PER_INTERFACE[5] > 4) {
		r4 = PKTStore::pktRepository_i_5_r_4_t_0_cnt +
			 PKTStore::pktRepository_i_5_r_4_t_1_cnt +
			 PKTStore::pktRepository_i_5_r_4_t_2_cnt +
			 PKTStore::pktRepository_i_5_r_4_t_3_cnt +
			 PKTStore::pktRepository_i_5_r_4_t_4_cnt +
			 PKTStore::pktRepository_i_5_r_4_t_5_cnt +
			 PKTStore::pktRepository_i_5_r_4_t_6_cnt +
			 PKTStore::pktRepository_i_5_r_4_t_7_cnt +
			 PKTStore::pktRepository_i_5_r_4_t_8_cnt +
			 PKTStore::pktRepository_i_5_r_4_t_9_cnt;
		sprintf(buffer, "%07d  %07d  %07d  %07d  %07d", r0, r1, r2, r3, r4);
	}

	if(IPGlobal::ROUTER_PER_INTERFACE[5] > 5) {
		r5 = PKTStore::pktRepository_i_5_r_5_t_0_cnt +
			 PKTStore::pktRepository_i_5_r_5_t_1_cnt +
			 PKTStore::pktRepository_i_5_r_5_t_2_cnt +
			 PKTStore::pktRepository_i_5_r_5_t_3_cnt +
			 PKTStore::pktRepository_i_5_r_5_t_4_cnt +
			 PKTStore::pktRepository_i_5_r_5_t_5_cnt +
			 PKTStore::pktRepository_i_5_r_5_t_6_cnt +
			 PKTStore::pktRepository_i_5_r_5_t_7_cnt +
			 PKTStore::pktRepository_i_5_r_5_t_8_cnt +
			 PKTStore::pktRepository_i_5_r_5_t_9_cnt;
		sprintf(buffer, "%07d  %07d  %07d  %07d  %07d  %07d", r0, r1, r2, r3, r4, r5);
	}

	if(IPGlobal::ROUTER_PER_INTERFACE[5] > 6) {
		r6 = PKTStore::pktRepository_i_5_r_6_t_0_cnt +
			 PKTStore::pktRepository_i_5_r_6_t_1_cnt +
			 PKTStore::pktRepository_i_5_r_6_t_2_cnt +
			 PKTStore::pktRepository_i_5_r_6_t_3_cnt +
			 PKTStore::pktRepository_i_5_r_6_t_4_cnt +
			 PKTStore::pktRepository_i_5_r_6_t_5_cnt +
			 PKTStore::pktRepository_i_5_r_6_t_6_cnt +
			 PKTStore::pktRepository_i_5_r_6_t_7_cnt +
			 PKTStore::pktRepository_i_5_r_6_t_8_cnt +
			 PKTStore::pktRepository_i_5_r_6_t_9_cnt;
		sprintf(buffer, "%07d  %07d  %07d  %07d  %07d  %07d  %07d", r0, r1, r2, r3, r4, r5, r6);
	}

	if(IPGlobal::ROUTER_PER_INTERFACE[5] > 7) {
		r7 = PKTStore::pktRepository_i_5_r_7_t_0_cnt +
			 PKTStore::pktRepository_i_5_r_7_t_1_cnt +
			 PKTStore::pktRepository_i_5_r_7_t_2_cnt +
			 PKTStore::pktRepository_i_5_r_7_t_3_cnt +
			 PKTStore::pktRepository_i_5_r_7_t_4_cnt +
			 PKTStore::pktRepository_i_5_r_7_t_5_cnt +
			 PKTStore::pktRepository_i_5_r_7_t_6_cnt +
			 PKTStore::pktRepository_i_5_r_7_t_7_cnt +
			 PKTStore::pktRepository_i_5_r_7_t_8_cnt +
			 PKTStore::pktRepository_i_5_r_7_t_9_cnt;
		sprintf(buffer, "%07d  %07d  %07d  %07d  %07d  %07d  %07d  %07d", r0, r1, r2, r3, r4, r5, r6, r7);

	}

	TheLog_nc_v2(Log::Info, name(), "   Interface(R)[%6s] %s", INTERFACES_NAME[5].c_str(), buffer);
	r0 = r1 = r2 = r3 = r4 = r5 = r6 = r7 = r8 = r9 = r10 = r11 = 0;
}

VOID ProbeStatsLog::printPktStoreStats_i_6()
{
	int r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11;
	char buffer[500];

	buffer[0] = 0;
	r0 = r1 = r2 = r3 = r4 = r5 = r6 = r7 = r8 = r9 = r10 = r11 = 0;

	r0 = PKTStore::pktRepository_i_6_r_0_t_0_cnt +
		 PKTStore::pktRepository_i_6_r_0_t_1_cnt +
		 PKTStore::pktRepository_i_6_r_0_t_2_cnt +
		 PKTStore::pktRepository_i_6_r_0_t_3_cnt +
		 PKTStore::pktRepository_i_6_r_0_t_4_cnt +
		 PKTStore::pktRepository_i_6_r_0_t_5_cnt +
		 PKTStore::pktRepository_i_6_r_0_t_6_cnt +
		 PKTStore::pktRepository_i_6_r_0_t_7_cnt +
		 PKTStore::pktRepository_i_6_r_0_t_8_cnt +
		 PKTStore::pktRepository_i_6_r_0_t_9_cnt;
	sprintf(buffer, "%07d", r0);

	if(IPGlobal::ROUTER_PER_INTERFACE[6] > 1) {
		r1 = PKTStore::pktRepository_i_6_r_1_t_0_cnt +
			 PKTStore::pktRepository_i_6_r_1_t_1_cnt +
			 PKTStore::pktRepository_i_6_r_1_t_2_cnt +
			 PKTStore::pktRepository_i_6_r_1_t_3_cnt +
			 PKTStore::pktRepository_i_6_r_1_t_4_cnt +
			 PKTStore::pktRepository_i_6_r_1_t_5_cnt +
			 PKTStore::pktRepository_i_6_r_1_t_6_cnt +
			 PKTStore::pktRepository_i_6_r_1_t_7_cnt +
			 PKTStore::pktRepository_i_6_r_1_t_8_cnt +
			 PKTStore::pktRepository_i_6_r_1_t_9_cnt;
		sprintf(buffer, "%07d  %07d", r0, r1);
	}

	if(IPGlobal::ROUTER_PER_INTERFACE[6] > 2) {
		r2 = PKTStore::pktRepository_i_6_r_2_t_0_cnt +
			 PKTStore::pktRepository_i_6_r_2_t_1_cnt +
			 PKTStore::pktRepository_i_6_r_2_t_2_cnt +
			 PKTStore::pktRepository_i_6_r_2_t_3_cnt +
			 PKTStore::pktRepository_i_6_r_2_t_4_cnt +
			 PKTStore::pktRepository_i_6_r_2_t_5_cnt +
			 PKTStore::pktRepository_i_6_r_2_t_6_cnt +
			 PKTStore::pktRepository_i_6_r_2_t_7_cnt +
			 PKTStore::pktRepository_i_6_r_2_t_8_cnt +
			 PKTStore::pktRepository_i_6_r_2_t_9_cnt;
		sprintf(buffer, "%07d  %07d  %07d", r0, r1, r2);
	}

	if(IPGlobal::ROUTER_PER_INTERFACE[6] > 3) {
		r3 = PKTStore::pktRepository_i_6_r_3_t_0_cnt +
			 PKTStore::pktRepository_i_6_r_3_t_1_cnt +
			 PKTStore::pktRepository_i_6_r_3_t_2_cnt +
			 PKTStore::pktRepository_i_6_r_3_t_3_cnt +
			 PKTStore::pktRepository_i_6_r_3_t_4_cnt +
			 PKTStore::pktRepository_i_6_r_3_t_5_cnt +
			 PKTStore::pktRepository_i_6_r_3_t_6_cnt +
			 PKTStore::pktRepository_i_6_r_3_t_7_cnt +
			 PKTStore::pktRepository_i_6_r_3_t_8_cnt +
			 PKTStore::pktRepository_i_6_r_3_t_9_cnt;
		sprintf(buffer, "%07d  %07d  %07d  %07d", r0, r1, r2, r3);
	}

	if(IPGlobal::ROUTER_PER_INTERFACE[6] > 4) {
		r4 = PKTStore::pktRepository_i_6_r_4_t_0_cnt +
			 PKTStore::pktRepository_i_6_r_4_t_1_cnt +
			 PKTStore::pktRepository_i_6_r_4_t_2_cnt +
			 PKTStore::pktRepository_i_6_r_4_t_3_cnt +
			 PKTStore::pktRepository_i_6_r_4_t_4_cnt +
			 PKTStore::pktRepository_i_6_r_4_t_5_cnt +
			 PKTStore::pktRepository_i_6_r_4_t_6_cnt +
			 PKTStore::pktRepository_i_6_r_4_t_7_cnt +
			 PKTStore::pktRepository_i_6_r_4_t_8_cnt +
			 PKTStore::pktRepository_i_6_r_4_t_9_cnt;
		sprintf(buffer, "%07d  %07d  %07d  %07d  %07d", r0, r1, r2, r3, r4);
	}

	if(IPGlobal::ROUTER_PER_INTERFACE[6] > 5) {
		r5 = PKTStore::pktRepository_i_6_r_5_t_0_cnt +
			 PKTStore::pktRepository_i_6_r_5_t_1_cnt +
			 PKTStore::pktRepository_i_6_r_5_t_2_cnt +
			 PKTStore::pktRepository_i_6_r_5_t_3_cnt +
			 PKTStore::pktRepository_i_6_r_5_t_4_cnt +
			 PKTStore::pktRepository_i_6_r_5_t_5_cnt +
			 PKTStore::pktRepository_i_6_r_5_t_6_cnt +
			 PKTStore::pktRepository_i_6_r_5_t_7_cnt +
			 PKTStore::pktRepository_i_6_r_5_t_8_cnt +
			 PKTStore::pktRepository_i_6_r_5_t_9_cnt;
		sprintf(buffer, "%07d  %07d  %07d  %07d  %07d  %07d", r0, r1, r2, r3, r4, r5);
	}

	if(IPGlobal::ROUTER_PER_INTERFACE[6] > 6) {
		r6 = PKTStore::pktRepository_i_6_r_6_t_0_cnt +
			 PKTStore::pktRepository_i_6_r_6_t_1_cnt +
			 PKTStore::pktRepository_i_6_r_6_t_2_cnt +
			 PKTStore::pktRepository_i_6_r_6_t_3_cnt +
			 PKTStore::pktRepository_i_6_r_6_t_4_cnt +
			 PKTStore::pktRepository_i_6_r_6_t_5_cnt +
			 PKTStore::pktRepository_i_6_r_6_t_6_cnt +
			 PKTStore::pktRepository_i_6_r_6_t_7_cnt +
			 PKTStore::pktRepository_i_6_r_6_t_8_cnt +
			 PKTStore::pktRepository_i_6_r_6_t_9_cnt;
		sprintf(buffer, "%07d  %07d  %07d  %07d  %07d  %07d  %07d", r0, r1, r2, r3, r4, r5, r6);
	}

	if(IPGlobal::ROUTER_PER_INTERFACE[6] > 7) {
		r7 = PKTStore::pktRepository_i_6_r_7_t_0_cnt +
			 PKTStore::pktRepository_i_6_r_7_t_1_cnt +
			 PKTStore::pktRepository_i_6_r_7_t_2_cnt +
			 PKTStore::pktRepository_i_6_r_7_t_3_cnt +
			 PKTStore::pktRepository_i_6_r_7_t_4_cnt +
			 PKTStore::pktRepository_i_6_r_7_t_5_cnt +
			 PKTStore::pktRepository_i_6_r_7_t_6_cnt +
			 PKTStore::pktRepository_i_6_r_7_t_7_cnt +
			 PKTStore::pktRepository_i_6_r_7_t_8_cnt +
			 PKTStore::pktRepository_i_6_r_7_t_9_cnt;
		sprintf(buffer, "%07d  %07d  %07d  %07d  %07d  %07d  %07d  %07d", r0, r1, r2, r3, r4, r5, r6, r7);

	}

	TheLog_nc_v2(Log::Info, name(), "   Interface(R)[%6s] %s", INTERFACES_NAME[6].c_str(), buffer);
	r0 = r1 = r2 = r3 = r4 = r5 = r6 = r7 = r8 = r9 = r10 = r11 = 0;
}

VOID ProbeStatsLog::printPktStoreStats_i_7()
{
	int r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11;
	char buffer[500];

	buffer[0] = 0;
	r0 = r1 = r2 = r3 = r4 = r5 = r6 = r7 = r8 = r9 = r10 = r11 = 0;

	r0 = PKTStore::pktRepository_i_7_r_0_t_0_cnt +
		 PKTStore::pktRepository_i_7_r_0_t_1_cnt +
		 PKTStore::pktRepository_i_7_r_0_t_2_cnt +
		 PKTStore::pktRepository_i_7_r_0_t_3_cnt +
		 PKTStore::pktRepository_i_7_r_0_t_4_cnt +
		 PKTStore::pktRepository_i_7_r_0_t_5_cnt +
		 PKTStore::pktRepository_i_7_r_0_t_6_cnt +
		 PKTStore::pktRepository_i_7_r_0_t_7_cnt +
		 PKTStore::pktRepository_i_7_r_0_t_8_cnt +
		 PKTStore::pktRepository_i_7_r_0_t_9_cnt;
	sprintf(buffer, "%07d", r0);

	if(IPGlobal::ROUTER_PER_INTERFACE[7] > 1) {
		r1 = PKTStore::pktRepository_i_7_r_1_t_0_cnt +
			 PKTStore::pktRepository_i_7_r_1_t_1_cnt +
			 PKTStore::pktRepository_i_7_r_1_t_2_cnt +
			 PKTStore::pktRepository_i_7_r_1_t_3_cnt +
			 PKTStore::pktRepository_i_7_r_1_t_4_cnt +
			 PKTStore::pktRepository_i_7_r_1_t_5_cnt +
			 PKTStore::pktRepository_i_7_r_1_t_6_cnt +
			 PKTStore::pktRepository_i_7_r_1_t_7_cnt +
			 PKTStore::pktRepository_i_7_r_1_t_8_cnt +
			 PKTStore::pktRepository_i_7_r_1_t_9_cnt;
		sprintf(buffer, "%07d  %07d", r0, r1);
	}

	if(IPGlobal::ROUTER_PER_INTERFACE[7] > 2) {
		r2 = PKTStore::pktRepository_i_7_r_2_t_0_cnt +
			 PKTStore::pktRepository_i_7_r_2_t_1_cnt +
			 PKTStore::pktRepository_i_7_r_2_t_2_cnt +
			 PKTStore::pktRepository_i_7_r_2_t_3_cnt +
			 PKTStore::pktRepository_i_7_r_2_t_4_cnt +
			 PKTStore::pktRepository_i_7_r_2_t_5_cnt +
			 PKTStore::pktRepository_i_7_r_2_t_6_cnt +
			 PKTStore::pktRepository_i_7_r_2_t_7_cnt +
			 PKTStore::pktRepository_i_7_r_2_t_8_cnt +
			 PKTStore::pktRepository_i_7_r_2_t_9_cnt;
		sprintf(buffer, "%07d  %07d  %07d", r0, r1, r2);
	}

	if(IPGlobal::ROUTER_PER_INTERFACE[7] > 3) {
		r3 = PKTStore::pktRepository_i_7_r_3_t_0_cnt +
			 PKTStore::pktRepository_i_7_r_3_t_1_cnt +
			 PKTStore::pktRepository_i_7_r_3_t_2_cnt +
			 PKTStore::pktRepository_i_7_r_3_t_3_cnt +
			 PKTStore::pktRepository_i_7_r_3_t_4_cnt +
			 PKTStore::pktRepository_i_7_r_3_t_5_cnt +
			 PKTStore::pktRepository_i_7_r_3_t_6_cnt +
			 PKTStore::pktRepository_i_7_r_3_t_7_cnt +
			 PKTStore::pktRepository_i_7_r_3_t_8_cnt +
			 PKTStore::pktRepository_i_7_r_3_t_9_cnt;
		sprintf(buffer, "%07d  %07d  %07d  %07d", r0, r1, r2, r3);
	}

	if(IPGlobal::ROUTER_PER_INTERFACE[7] > 4) {
		r4 = PKTStore::pktRepository_i_7_r_4_t_0_cnt +
			 PKTStore::pktRepository_i_7_r_4_t_1_cnt +
			 PKTStore::pktRepository_i_7_r_4_t_2_cnt +
			 PKTStore::pktRepository_i_7_r_4_t_3_cnt +
			 PKTStore::pktRepository_i_7_r_4_t_4_cnt +
			 PKTStore::pktRepository_i_7_r_4_t_5_cnt +
			 PKTStore::pktRepository_i_7_r_4_t_6_cnt +
			 PKTStore::pktRepository_i_7_r_4_t_7_cnt +
			 PKTStore::pktRepository_i_7_r_4_t_8_cnt +
			 PKTStore::pktRepository_i_7_r_4_t_9_cnt;
		sprintf(buffer, "%07d  %07d  %07d  %07d  %07d", r0, r1, r2, r3, r4);
	}

	if(IPGlobal::ROUTER_PER_INTERFACE[7] > 5) {
		r5 = PKTStore::pktRepository_i_7_r_5_t_0_cnt +
			 PKTStore::pktRepository_i_7_r_5_t_1_cnt +
			 PKTStore::pktRepository_i_7_r_5_t_2_cnt +
			 PKTStore::pktRepository_i_7_r_5_t_3_cnt +
			 PKTStore::pktRepository_i_7_r_5_t_4_cnt +
			 PKTStore::pktRepository_i_7_r_5_t_5_cnt +
			 PKTStore::pktRepository_i_7_r_5_t_6_cnt +
			 PKTStore::pktRepository_i_7_r_5_t_7_cnt +
			 PKTStore::pktRepository_i_7_r_5_t_8_cnt +
			 PKTStore::pktRepository_i_7_r_5_t_9_cnt;
		sprintf(buffer, "%07d  %07d  %07d  %07d  %07d  %07d", r0, r1, r2, r3, r4, r5);
	}

	if(IPGlobal::ROUTER_PER_INTERFACE[7] > 6) {
		r6 = PKTStore::pktRepository_i_7_r_6_t_0_cnt +
			 PKTStore::pktRepository_i_7_r_6_t_1_cnt +
			 PKTStore::pktRepository_i_7_r_6_t_2_cnt +
			 PKTStore::pktRepository_i_7_r_6_t_3_cnt +
			 PKTStore::pktRepository_i_7_r_6_t_4_cnt +
			 PKTStore::pktRepository_i_7_r_6_t_5_cnt +
			 PKTStore::pktRepository_i_7_r_6_t_6_cnt +
			 PKTStore::pktRepository_i_7_r_6_t_7_cnt +
			 PKTStore::pktRepository_i_7_r_6_t_8_cnt +
			 PKTStore::pktRepository_i_7_r_6_t_9_cnt;
		sprintf(buffer, "%07d  %07d  %07d  %07d  %07d  %07d  %07d", r0, r1, r2, r3, r4, r5, r6);
	}

	if(IPGlobal::ROUTER_PER_INTERFACE[7] > 7) {
		r7 = PKTStore::pktRepository_i_7_r_7_t_0_cnt +
			 PKTStore::pktRepository_i_7_r_7_t_1_cnt +
			 PKTStore::pktRepository_i_7_r_7_t_2_cnt +
			 PKTStore::pktRepository_i_7_r_7_t_3_cnt +
			 PKTStore::pktRepository_i_7_r_7_t_4_cnt +
			 PKTStore::pktRepository_i_7_r_7_t_5_cnt +
			 PKTStore::pktRepository_i_7_r_7_t_6_cnt +
			 PKTStore::pktRepository_i_7_r_7_t_7_cnt +
			 PKTStore::pktRepository_i_7_r_7_t_8_cnt +
			 PKTStore::pktRepository_i_7_r_7_t_9_cnt;
		sprintf(buffer, "%07d  %07d  %07d  %07d  %07d  %07d  %07d  %07d", r0, r1, r2, r3, r4, r5, r6, r7);

	}

	TheLog_nc_v2(Log::Info, name(), "   Interface(R)[%6s] %s", INTERFACES_NAME[7].c_str(), buffer);
	r0 = r1 = r2 = r3 = r4 = r5 = r6 = r7 = r8 = r9 = r10 = r11 = 0;
}

VOID ProbeStatsLog::eachSessionCount()
{
	int s0, s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11, s12, s13, s14, s15;
	char buffer[500];

	buffer[0] = 0;
	s0 = s1 = s2 = s3 = s4 = s5 = s6 = s7 = s8 = s9 = s10 = s11 = s12 = s13 = s14 = s15 = 0;

	s0 = IPStats::ip_session_total_sm_0_cnt;
	sprintf(buffer, "%07d", s0);

	if(IPGlobal::S11_SESSION_MANAGER_INSTANCES > 1) {
		s1 = IPStats::ip_session_total_sm_1_cnt;
		sprintf(buffer, "%07d  %07d", s0, s1);
	}

	if(IPGlobal::S11_SESSION_MANAGER_INSTANCES > 2) {
		s2 = IPStats::ip_session_total_sm_2_cnt;
		sprintf(buffer, "%07d  %07d  %07d", s0, s1, s2);
	}

	if(IPGlobal::S11_SESSION_MANAGER_INSTANCES > 3) {
		s3 = IPStats::ip_session_total_sm_3_cnt;
		sprintf(buffer, "%07d  %07d  %07d  %07d", s0, s1, s2, s3);
	}

	if(IPGlobal::S11_SESSION_MANAGER_INSTANCES > 4) {
		s4 = IPStats::ip_session_total_sm_4_cnt;
		sprintf(buffer, "%07d  %07d  %07d  %07d  %07d", s0, s1, s2, s3, s4);
	}

	if(IPGlobal::S11_SESSION_MANAGER_INSTANCES > 5) {
		s5 = IPStats::ip_session_total_sm_5_cnt;
		sprintf(buffer, "%07d  %07d  %07d  %07d  %07d  %07d", s0, s1, s2, s3, s4, s5);
	}

	if(IPGlobal::S11_SESSION_MANAGER_INSTANCES > 6) {
		s6 = IPStats::ip_session_total_sm_6_cnt;
		sprintf(buffer, "%07d  %07d  %07d  %07d  %07d  %07d  %07d", s0, s1, s2, s3, s4, s5, s6);
	}

	if(IPGlobal::S11_SESSION_MANAGER_INSTANCES > 7) {
		s7 = IPStats::ip_session_total_sm_7_cnt;
		sprintf(buffer, "%07d  %07d  %07d  %07d  %07d  %07d  %07d  %07d", s0, s1, s2, s3, s4, s5, s6, s7);
	}

	if(IPGlobal::S11_SESSION_MANAGER_INSTANCES > 8) {
		s8 = IPStats::ip_session_total_sm_8_cnt;
		sprintf(buffer, "%07d  %07d  %07d  %07d  %07d  %07d  %07d  %07d  %07d", s0, s1, s2, s3, s4, s5, s6, s7, s8);
	}

	if(IPGlobal::S11_SESSION_MANAGER_INSTANCES > 9) {
		s9 = IPStats::ip_session_total_sm_9_cnt;
		sprintf(buffer, "%07d  %07d  %07d  %07d  %07d  %07d  %07d  %07d  %07d  %07d", s0, s1, s2, s3, s4, s5, s6, s7, s8, s9);
	}

	if(IPGlobal::S11_SESSION_MANAGER_INSTANCES > 10) {
		s10 = IPStats::ip_session_total_sm_10_cnt;
		sprintf(buffer, "%07d  %07d  %07d  %07d  %07d  %07d  %07d  %07d  %07d  %07d  %07d", s0, s1, s2, s3, s4, s5, s6, s7, s8, s9, s10);
	}

	if(IPGlobal::S11_SESSION_MANAGER_INSTANCES > 11) {
		s11 = IPStats::ip_session_total_sm_11_cnt;
		sprintf(buffer, "%07d  %07d  %07d  %07d  %07d  %07d  %07d  %07d  %07d  %07d  %07d  %07d", s0, s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11);
	}

	if(IPGlobal::S11_SESSION_MANAGER_INSTANCES > 12) {
		s12 = IPStats::ip_session_total_sm_12_cnt;
		sprintf(buffer, "%07d  %07d  %07d  %07d  %07d  %07d  %07d  %07d  %07d  %07d  %07d  %07d  %07d", s0, s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11, s12);
	}

	if(IPGlobal::S11_SESSION_MANAGER_INSTANCES > 13) {
		s13 = IPStats::ip_session_total_sm_13_cnt;
		sprintf(buffer, "%07d  %07d  %07d  %07d  %07d  %07d  %07d  %07d  %07d  %07d  %07d  %07d  %07d  %07d", s0, s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11, s12, s13);
	}

	if(IPGlobal::S11_SESSION_MANAGER_INSTANCES > 14) {
		s14 = IPStats::ip_session_total_sm_14_cnt;
		sprintf(buffer, "%07d  %07d  %07d  %07d  %07d  %07d  %07d  %07d  %07d  %07d  %07d  %07d  %07d  %07d  %07d", s0, s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11, s12, s13, s14);
	}

	if(IPGlobal::S11_SESSION_MANAGER_INSTANCES > 15) {
		s15 = IPStats::ip_session_total_sm_15_cnt;
		sprintf(buffer, "%07d  %07d  %07d  %07d  %07d  %07d  %07d  %07d  %07d  %07d  %07d  %07d  %07d  %07d  %07d  %07d", s0, s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11, s12, s13, s14, s15);
	}

	TheLog_nc_v1(Log::Info, name(), "   IP Session / SM      %s", buffer);
	s0 = s1 = s2 = s3 = s4 = s5 = s6 = s7 = s8 = s9 = s10 = s11 = s12 = s13 = s14 = s15 = 0;
}
