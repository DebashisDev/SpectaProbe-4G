/*
 * GConfig.cpp
 *
 *  Created on: 26-Jul-2016
 *      Author: Debashis
 */

#include "GConfig.h"
#include "IPGlobal.h"

GConfig::GConfig(char *fileName)
{ initialize(fileName); }

GConfig::~GConfig()
{}

VOID GConfig::initialize(char *fileName)
{
		printf("\n Loading Configurations...\n");
		openConfigFile(fileName);

		while(!fp.eof())
		{
			Key.clear();
			fp >> Key;

			get_S1UProbe(Key);								/* S1U_PROBE */
			get_S1MMEProbe(Key);							/* S1MME_PROBE */
			get_S11Probe(Key);								/* S11_PROBE */
			get_S5S8Probe(Key);								/* S5S8_PROBE */
			get_probeId(Key);								/* PROBE_ID */
			get_logLevel(Key);								/* LOG_LEVEL */
			get_printStats(Key);							/* PRINT_STATS */
			get_printStatsFrequency(Key);					/* PRINT_STATS_FREQ_SEC */
			get_logStatsFrequency(Key);						/* LOG_STATS_FREQ_SEC */
			get_xdrDir(Key);								/* XDR_DIR */
			get_logDir(Key);								/* LOG_DIR */
			get_dataDir(Key);								/* DATA_DIR */
			get_adminFlag(Key);								/* ADMIN_FLAG */
			get_adminPort(Key);								/* ADMIN_PORT */
			get_ethernetInterface(Key);						/* ETHERNET_INTERFACE */
			get_solarInterface(Key);						/* SOLAR_INTERFACE */
			get_solarTimeStamp(Key);						/* SOLARFLARE_HW_TIMESTAMP */
			get_packetLen(Key);								/* MAX_PKT_LEN_PER_INTERFACE */
			get_PPSPerInterface(Key);						/* PPS_PER_INTERFACE */
			get_PPSCap(Key);								/* PPS_CAP_PERCENTAGE */
			get_routerPerInterface(Key);					/* ROUTER_PER_INTERFACE */
			get_interfaceCPU(Key);							/* PKT_LISTENER_CPU_CORE */
			get_routerCPU(Key);								/* PKT_ROUTER_CPU_CORE */

			if(S1U_PROBE)
			{
				get_s1uProcessOutOfRange(Key);					/* S1U_PROCESS_OUT_OF_RANGE_IP */
				get_s1uProcessUserAgent(Key);					/* S1U_PROCESS_USER_AGENT */
				get_s1uCheckDuplicate(Key);						/* S1U_CHECK_DUPLICATE */
				get_s1uProcessAck(Key);							/* S1U_PROCESS_ACK */
				get_s1uProcessAckSession(Key);					/* S1U_ACK_CREATE_SESSION */
				get_s1uSessionTimeIndexPktLimit(Key);			/* S1U_SESSION_TIME_INDEX_PKT_LIMIT */
				get_s1uSessionPacketLimit(Key);					/* S1U_SESSION_PKT_LIMIT */
				get_s1uSessionTimeLimit(Key);					/* S1U_SESSION_TIME_LIMIT */
				get_s1uSessionCleanUpScanFreq(Key);				/* S1U_SESSION_CLEAN_UP_SCAN_FREQ_SEC */
				get_s1uSessionCleanUpBatchLimit(Key);			/* S1U_SESSION_CLEAN_UP_BATCH_LIMIT */
				get_s1uSessionCleanUpTimeOut(Key);				/* S1U_SESSION_CLEAN_UP_TIMEOUT_SEC */
				get_s1uDnsAnswerCount(Key);						/* S1U_DNS_ANSWER */
				get_s1uVpsPacketLimit(Key);						/* S1U_VPS_PACKET_PER_SEC */
				get_s1uUdpXdrForDnsFlag(Key);					/* S1U_UDP_XDR_FOR_DNS */
				get_s1uSessionInstance(Key);					/* S1U_SESSION_MANAGER_INSTANCES */
				get_s1uSessionInstanceCore(Key);				/* S1U_SESSION_MANAGER_CPU_CORE */
				get_s1uNoOfIpFlusher(Key);						/* S1U_FLUSHER_NO */
				get_s1uFlusherCore(Key);						/* S1U_FLUSHER_CPU_CORE */
				get_s1uWriteXdrFlag(Key);						/* S1U_WRITE_XDR */
				get_s1uWriteXdrCore(Key);						/* S1U_XDR_WRITE_CPU_CORE */
				get_s1uFilePrefix(Key);							/* S1U_FILE_PREFIX */

				get_noOfDnsFlusher(Key);						/* DNS_FLUSHER_NO */
				get_DnsFlusherCore(Key);						/* DNS_FLUSHER_CPU_CORE */
				get_DnsWriteXdrFlag(Key);						/* DNS_WRITE_XDR */
				get_DnsWriteXdrCore(Key);						/* DNS_XDR_WRITE_CPU_CORE */
				get_DnsFilePrefix(Key);							/* DNS_FILE_PREFIX */
			}

			if(S1MME_PROBE)
			{
				get_s1mmeIPRange(Key);							/* S1MME_RANGE */
				get_s1mmeSessionInstance(Key);					/* S1MME_SESSION_MANAGER_INSTANCES */
				get_s1mmeSessionInstanceCore(Key);				/* S1MME_SESSION_MANAGER_CPU_CORE */
				get_s1mmeNoOfFlusher(Key);						/* S1MME_FLUSHER_NO */
				get_s1mmeFlusherCore(Key);						/* S1MME_FLUSHER_CPU_CORE */
				get_s1mmeWriteXdrFlag(Key);						/* S1MME_WRITE_XDR */
				get_s1mmeWriteXdrCore(Key);						/* S1MME_XDR_WRITE_CPU_CORE */
				get_s1mmeFilePrefix(Key);						/* S1MME_FILE_PREFIX */
			}

			if(S11_PROBE)
			{
				get_s11SessionInstance(Key);					/* S11_SESSION_MANAGER_INSTANCES */
				get_s11SessionInstanceCore(Key);				/* S11_SESSION_MANAGER_CPU_CORE */
				get_s11NoOfFlusher(Key);						/* S11_FLUSHER_NO */
				get_s11FlusherCore(Key);						/* S11_FLUSHER_CPU_CORE */
				get_s11WriteXdrFlag(Key);						/* S11_WRITE_XDR */
				get_s11WriteXdrCore(Key);						/* S11_XDR_WRITE_CPU_CORE */
				get_s11FilePrefix(Key);							/* S11_FILE_PREFIX */
			}

			if(S5S8_PROBE)
			{
				get_s5s8PGWIPRange(Key);						/* PGW_RANGE */
				get_s5s8SessionInstance(Key);					/* S5S8_SESSION_MANAGER_INSTANCES */
				get_s5s8SessionInstanceCore(Key);				/* S5S8_SESSION_MANAGER_CPU_CORE */
				get_s5s8NoOfFlusher(Key);						/* S5S8_FLUSHER_NO */
				get_s5s8FlusherCore(Key);						/* S5S8_FLUSHER_CPU_CORE */
				get_s5s8WriteXdrFlag(Key);						/* S5S8_WRITE_XDR */
				get_s5s8WriteXdrCore(Key);						/* S5S8_XDR_WRITE_CPU_CORE */
				get_s5s8FilePrefix(Key);						/* S5S8_FILE_PREFIX */
			}
		}
		closeConfigFile();
}

VOID GConfig::openConfigFile(char *fileName)
{
	char probeConfigBaseDir[100];
	char *probeConfigDir;
	char *probeRootEnv;

	probeConfigDir = getenv("PROBE_CONF");
	probeRootEnv = getenv("PROBE_ROOT");

	if(probeConfigDir == NULL || probeRootEnv == NULL)
	{
		printf("\n\n\n  !!! ******* SpectaProbe Environment NOT Set ******* !!! \n\n\n");
		exit(1);
	}
	strcpy(GConstant::probeBaseDir, probeRootEnv);
	sprintf(probeConfigBaseDir, "%s/%s", probeConfigDir, fileName);
	fp.open(probeConfigBaseDir);


	if(fp.fail())
	{
		printf("  Error in Opening Configuration File : %s\n", probeConfigBaseDir);
		exit(1);
	}
}

VOID GConfig::closeConfigFile()
{ fp.close(); }

VOID GConfig::get_probeId(std::string& Key)
{
	Value.clear();

	if(Key.compare("PROBE_ID") == 0)
	{
		fp >> Value;
		IPGlobal::PROBE_ID = atol(Value.c_str());
		printf("\tPROBE_ID               			:: %d\n", IPGlobal::PROBE_ID);
	}
}

VOID GConfig::get_S1UProbe(std::string& Key)
{
	Value.clear();

	if(Key.compare("S1U_PROBE") == 0)
	{
		fp >> Value;
		S1U_PROBE = Value.compare("true") == 0 ? true : false;
		printf("	S1U_PROBE				:: %s\n", Value.c_str());
	}
}

VOID GConfig::get_S1MMEProbe(std::string& Key)
{
	Value.clear();

	if(Key.compare("S1MME_PROBE") == 0)
	{
		fp >> Value;
		S1MME_PROBE = Value.compare("true") == 0 ? true : false;
		if(S1MME_PROBE) printf("	S1MME_PROBE				:: %s\n", Value.c_str());
	}
}

VOID GConfig::get_S11Probe(std::string& Key)
{
	Value.clear();

	if(Key.compare("S11_PROBE") == 0)
	{
		fp >> Value;
		S11_PROBE = Value.compare("true") == 0 ? true : false;
		printf("	S11_PROBE				:: %s\n", Value.c_str());
	}
}

VOID GConfig::get_S5S8Probe(std::string& Key)
{
	Value.clear();

	if(Key.compare("S5S8_PROBE") == 0)
	{
		fp >> Value;
		S5S8_PROBE = Value.compare("true") == 0 ? true : false;
		printf("	S5S8_PROBE				:: %s\n", Value.c_str());
	}
}

VOID GConfig::get_logLevel(std::string& Key)
{
	Value.clear();

	if(Key.compare("LOG_LEVEL") == 0)
	{
		fp >> Value;
		LOG_LEVEL = atoi(Value.c_str());
		printf("\tLOG_LEVEL               		:: %d\n", LOG_LEVEL);

	}
}

VOID GConfig::get_printStats(std::string& Key)
{
	Value.clear();

	if(Key.compare("PRINT_STATS") == 0)
	{
		fp >> Value;
		IPGlobal::PRINT_STATS = Value.compare("true") == 0 ? true : false;
		printf("	PRINT_STATS				:: [%d] [%s]\n", IPGlobal::PRINT_STATS, Value.c_str());
	}
}

VOID GConfig::get_printStatsFrequency(std::string& Key)
{
	Value.clear();

	if(Key.compare("PRINT_STATS_FREQ_SEC") == 0)
	{
		fp >> Value;
		IPGlobal::PRINT_STATS_FREQ_SEC = atoi(Value.c_str());
		printf("	PRINT_STATS_FREQ_SEC			:: %d\n", IPGlobal::PRINT_STATS_FREQ_SEC);
	}
}

VOID GConfig::get_logStatsFrequency(std::string& Key)
{
	Value.clear();

	if(Key.compare("LOG_STATS_FREQ_SEC") == 0)
	{
		fp >> Value;
		IPGlobal::LOG_STATS_FREQ_SEC = atoi(Value.c_str());
		printf("	LOG_STATS_FREQ_SEC			:: %d\n", IPGlobal::LOG_STATS_FREQ_SEC);
	}
}

VOID GConfig::get_xdrDir(std::string& Key)
{
	Value.clear();

	if(Key.compare("XDR_DIR") == 0)
	{
		fp >> Value;
		XDR_DIR = Value;
		printf("\tXDR_DIR               			:: %s\n", XDR_DIR.c_str());
	}
}

VOID GConfig::get_logDir(std::string& Key)
{
	Value.clear();

	if(Key.compare("LOG_DIR") == 0)
	{
		fp >> Value;
		LOG_DIR = Value;
		printf("\tLOG_DIR               			:: %s\n", LOG_DIR.c_str());
	}
}

VOID GConfig::get_dataDir(std::string& Key)
{
	Value.clear();

	if(Key.compare("DATA_DIR") == 0)
	{
		fp >> Value;
		DATA_DIRECTORY = Value;
		printf("\tDATA_DIR               			:: %s\n", DATA_DIRECTORY.c_str());
	}
}

VOID GConfig::get_adminFlag(std::string& Key)
{
	Value.clear();

	if(Key.compare("ADMIN_FLAG") == 0)
	{
		fp >> Value;
		IPGlobal::ADMIN_FLAG = Value.compare("true") == 0 ? 1 : 0;
		printf("\tADMIN_FLAG\t\t\t\t:: %s\n", Value.c_str());
	}
}

VOID GConfig::get_adminPort(std::string& Key)
{
	Value.clear();

	if(Key.compare("ADMIN_PORT") == 0)
	{
			fp >> Value;
			IPGlobal::ADMIN_PORT = Value;
			printf("\tADMIN_PORT\t\t\t\t:: %s\n", IPGlobal::ADMIN_PORT.c_str());
	}
}

VOID GConfig::get_ethernetInterface(std::string& Key)
{
	Value.clear();

	if(Key.compare("ETHERNET_INTERFACE") == 0)
	{
		fp >> Value;
		int cnt = 0;

		char *pch = strtok((char *)Value.c_str(),",");

		while (pch != NULL)
		{
			IPGlobal::ETHERNET_INTERFACES[cnt] = std::string(pch);
			pch = strtok (NULL, ",");
			printf("\tETHERNET_INTERFACES[%d]     		:: %s\n", cnt, IPGlobal::ETHERNET_INTERFACES[cnt].c_str());
			cnt++;
		}
		IPGlobal::NO_OF_NIC_INTERFACE = cnt;
		printf("\tETHERNET_INTERFACE          		:: %d\n", IPGlobal::NO_OF_NIC_INTERFACE);
	}
}

VOID GConfig::get_solarInterface(std::string& Key)
{
	Value.clear();

	if(Key.compare("SOLAR_INTERFACE") == 0)
	{
		fp >> Value;
		int cnt = 0;
		char *pch = strtok((char *)Value.c_str(),",");

		while (pch != NULL)
		{
			IPGlobal::SOLAR_INTERFACES[cnt] = std::string(pch);
			pch = strtok (NULL, ",");
			printf("\tSOLAR_INTERFACES[%d] 			:: %s\n", cnt, IPGlobal::SOLAR_INTERFACES[cnt].c_str());
			cnt++;
		}
		IPGlobal::NO_OF_SOLAR_INTERFACE = cnt;
		printf("\tSOLAR_INTERFACES          		:: %d\n", IPGlobal::NO_OF_SOLAR_INTERFACE);
	}
}

VOID GConfig::get_solarTimeStamp(std::string& Key)
{
	Value.clear();

	if(Key.compare("SOLARFLARE_HW_TIMESTAMP") == 0)
	{
		fp >> Value;
		IPGlobal::SOLARFLARE_HW_TIMESTAMP = Value.compare("true") == 0 ? 1 : 0;
		printf("\tSOLARFLARE_HW_TIMESTAMP			:: %s\n", Value.c_str());
	}
}

VOID GConfig::get_packetLen(std::string& Key)
{
	Value.clear();

	if(Key.compare("MAX_PKT_LEN_PER_INTERFACE") == 0)
	{
		fp >> Value;
		int cnt = 0;
		char *pch1 = strtok((char *)Value.c_str(),",");

		while (pch1 != NULL)
		{
			IPGlobal::MAX_PKT_LEN_PER_INTERFACE[cnt] = atoi(pch1);
			printf("\tMAX_PKT_LEN_PER_INTERFACE[%d]     	:: %d\n", cnt, IPGlobal::MAX_PKT_LEN_PER_INTERFACE[cnt]);
			pch1 = strtok (NULL, ",");
			cnt++;
		}
	}
}

VOID GConfig::get_PPSPerInterface(std::string& Key)
{
	Value.clear();

	if(Key.compare("PPS_PER_INTERFACE") == 0)
	{
		fp >> Value;
		int cnt = 0;
		char *pch1 = strtok((char *)Value.c_str(),",");

		while (pch1 != NULL)
		{
			IPGlobal::PPS_PER_INTERFACE[cnt] = atoi(pch1);
			printf("\tPPS_PER_INTERFACE[%d]     		:: %d\n", cnt, IPGlobal::PPS_PER_INTERFACE[cnt]);
			pch1 = strtok (NULL, ",");
			cnt++;
		}
	}
}

VOID GConfig::get_PPSCap(std::string& Key)
{
	Value.clear();

	if(Key.compare("PPS_CAP_PERCENTAGE") == 0)
	{
		fp >> Value;
		int cnt = 0;
		char *pch1 = strtok((char *)Value.c_str(),",");

		while (pch1 != NULL)
		{
			IPGlobal::PPS_CAP_PERCENTAGE[cnt] = atoi(pch1);
			printf("\tPPS_CAP_PERCENTAGE[%d]     		:: %d\n", cnt, IPGlobal::PPS_CAP_PERCENTAGE[cnt]);
			pch1 = strtok (NULL, ",");
			cnt++;
		}
	}
}

VOID GConfig::get_routerPerInterface(std::string& Key)
{
	Value.clear();

	if(Key.compare("ROUTER_PER_INTERFACE") == 0)
	{
		fp >> Value;
		int cnt = 0;
		char *pch1 = strtok((char *)Value.c_str(),",");

		while (pch1 != NULL)
		{
			IPGlobal::ROUTER_PER_INTERFACE[cnt] = atoi(pch1);
			printf("\tROUTER_PER_INTERFACE[%d]			:: %d\n", cnt, IPGlobal::ROUTER_PER_INTERFACE[cnt]);

			if(IPGlobal::ROUTER_PER_INTERFACE[cnt] > MAX_ROUTER_PER_INTERFACE_SUPPORT)
			{
				printf("\tMaximum Router should be <= 8\n");
				exit(0);
			}
			pch1 = strtok (NULL, ",");
			cnt++;
		}
	}
}

VOID GConfig::get_routerCPU(std::string& Key)
{
	Value.clear();

	if(Key.compare("PKT_ROUTER_CPU_CORE") == 0)
	{
		fp >> Value;
		char *pchHash, *pchComma;
		int cnt, cnt1;

		cnt = cnt1 = 0;
		size_t pos = 0;
		std::string token;

		while ((pos = Value.find("-")) != std::string::npos)
		{
		    token = Value.substr(0, pos);
		    pchHash = strtok((char *)token.c_str(),",");

		    while (pchHash != NULL)
			{
				IPGlobal::PKT_ROUTER_CPU_CORE[cnt1][cnt] = atoi(pchHash);
				printf("\tPKT_ROUTER_CPU_CORE[%d][%d]		:: %d\n", cnt1, cnt, IPGlobal::PKT_ROUTER_CPU_CORE[cnt1][cnt]);
				pchHash = strtok (NULL, ",");
				cnt++;
			}
			cnt1++;
			cnt = 0;
		    Value.erase(0, pos + 1);
		}
		cnt = 0;
		pchComma = strtok((char *)Value.c_str(),",");

		while (pchComma != NULL)
		{
			IPGlobal::PKT_ROUTER_CPU_CORE[cnt1][cnt] = atoi(pchComma);
			printf("\tPKT_ROUTER_CPU_CORE[%d][%d]		:: %d\n", cnt1, cnt, IPGlobal::PKT_ROUTER_CPU_CORE[cnt1][cnt]);
			pchComma = strtok (NULL, ",");
			cnt++;
		}
	}
}

VOID GConfig::get_interfaceCPU(std::string& Key)
{
	Value.clear();

	if(Key.compare("PKT_LISTENER_CPU_CORE") == 0)
	{
		fp >> Value;
		int cnt = 0;
		char *pch1 = strtok((char *)Value.c_str(),",");

		while (pch1 != NULL)
		{
			IPGlobal::PKT_LISTENER_CPU_CORE[cnt] = atoi(pch1);
			printf("\tPKT_LISTENER_CPU_CORE[%d]		:: %d\n", cnt, IPGlobal::PKT_LISTENER_CPU_CORE[cnt]);
			pch1 = strtok (NULL, ",");
			cnt++;
		}
	}
}

VOID GConfig::get_s1mmeIPRange(std::string& Key)
{
	Value.clear();

	if(Key.compare("S1MME_RANGE") == 0)
	{
		fp >> Value;
		char *pchHash, *pchComma;
		int cnt, cnt1;
		ULONG x = 0;
		cnt = cnt1 = 0;
		size_t pos = 0;
		std::string token;

		while ((pos = Value.find(",")) != std::string::npos) {
			token = Value.substr(0, pos);
			pchHash = strtok((char *)token.c_str(),"-");
			while (pchHash != NULL)
			{
				IPGlobal::MME_RANGE[cnt1][cnt] = ipToLong(pchHash, &x);
				printf("\tMME_RANGE[%d][%d]			:: %lu\n", cnt1, cnt, IPGlobal::MME_RANGE[cnt1][cnt]);
				pchHash = strtok (NULL, "-");
				cnt++;
				x = 0;
			}
			cnt1++;
			cnt = 0;
			Value.erase(0, pos + 1);
		}
		cnt = 0;
		x = 0;
		pchComma = strtok((char *)Value.c_str(),"-");
		while (pchComma != NULL)
		{
			IPGlobal::MME_RANGE[cnt1][cnt] = ipToLong(pchComma, &x);
			printf("\tMME_RANGE[%d][%d]			:: %lu\n", cnt1, cnt, IPGlobal::MME_RANGE[cnt1][cnt]);
			pchComma = strtok (NULL, "-");
			cnt++;
			x = 0;
		}
		IPGlobal::MME_NO_OF_RANGE = cnt1;
	}
}

VOID GConfig::get_s5s8PGWIPRange(std::string& Key)
{
	Value.clear();

	if(Key.compare("PGW_RANGE") == 0)
	{
		fp >> Value;
		char *pchHash, *pchComma;
		int cnt, cnt1;
		ULONG x = 0;
		cnt = cnt1 = 0;
		size_t pos = 0;
		std::string token;

		while ((pos = Value.find(",")) != std::string::npos) {
			token = Value.substr(0, pos);
			pchHash = strtok((char *)token.c_str(),"-");
			while (pchHash != NULL)
			{
				IPGlobal::PGW_RANGE[cnt1][cnt] = ipToLong(pchHash, &x);
				printf("\tPGW_RANGE[%d][%d]			:: %lu\n", cnt1, cnt, IPGlobal::PGW_RANGE[cnt1][cnt]);
				pchHash = strtok (NULL, "-");
				cnt++;
				x = 0;
			}
			cnt1++;
			cnt = 0;
			Value.erase(0, pos + 1);
		}
		cnt = 0;
		x = 0;
		pchComma = strtok((char *)Value.c_str(),"-");
		while (pchComma != NULL)
		{
			IPGlobal::PGW_RANGE[cnt1][cnt] = ipToLong(pchComma, &x);
			printf("\tPGW_RANGE[%d][%d]			:: %lu\n", cnt1, cnt, IPGlobal::PGW_RANGE[cnt1][cnt]);
			pchComma = strtok (NULL, "-");
			cnt++;
			x = 0;
		}
		IPGlobal::PGW_NO_OF_RANGE = cnt1;
	}
}

VOID GConfig::get_s1uProcessOutOfRange(std::string& Key)
{
	Value.clear();

	if(Key.compare("S1U_PROCESS_OUT_OF_RANGE_IP") == 0)
	{
		fp >> Value;
		IPGlobal::S1U_PROCESS_OUT_OF_RANGE_IP = Value.compare("true") == 0 ? true : false;
		printf("	S1U_PROCESS_OUT_OF_RANGE_IP			:: %s\n", Value.c_str());
	}
}

VOID GConfig::get_s1uProcessUserAgent(std::string& Key)
{
	Value.clear();

	if(Key.compare("S1U_PROCESS_USER_AGENT") == 0)
	{
		fp >> Value;
		IPGlobal::S1U_PROCESS_USER_AGENT = Value.compare("true") == 0 ? true : false;
		printf("	S1U_PROCESS_USER_AGENT			:: %s\n", Value.c_str());
	}
}

VOID GConfig::get_s1uCheckDuplicate(std::string& Key)
{
	Value.clear();
	if(Key.compare("S1U_CHECK_DUPLICATE") == 0)
	{
		fp >> Value;
		IPGlobal::S1U_CHECK_DUPLICATE = Value.compare("true") == 0 ? true : false;
		printf("	S1U_CHECK_DUPLICATE PKT			:: %s\n", Value.c_str());
	}
}

VOID GConfig::get_s1uProcessAck(std::string& Key)
{
	Value.clear();

	if(Key.compare("S1U_PROCESS_ACK") == 0)
	{
		fp >> Value;
		IPGlobal::S1U_PROCESS_ACK = Value.compare("true") == 0 ? true : false;
		printf("	S1U_PROCESS_ACK 				:: %s\n", Value.c_str());
	}
}

VOID GConfig::get_s1uProcessAckSession(std::string& Key)
{
	Value.clear();
	if(Key.compare("S1U_ACK_CREATE_SESSION") == 0)
	{
		fp >> Value;
		IPGlobal::S1U_ACK_CREATE_SESSION = Value.compare("true") == 0 ? true : false;
		printf("	S1U_ACK_CREATE_SESSION 			:: %s\n", Value.c_str());
	}
}

VOID GConfig::get_s1uSessionTimeIndexPktLimit(std::string& Key)
{
	Value.clear();

	if(Key.compare("S1U_SESSION_TIME_INDEX_PKT_LIMIT") == 0)
	{
		fp >> Value;
		IPGlobal::S1U_SESSION_TIME_INDEX_PKT_LIMIT = Value.compare("true") == 0 ? true : false;
		printf("	S1U_SESSION_TIME_INDEX_PKT_LIMIT		:: %s\n", Value.c_str());
	}
}

VOID GConfig::get_s1uSessionPacketLimit(std::string& Key)
{
	Value.clear();

	if(Key.compare("S1U_SESSION_PKT_LIMIT") == 0)
	{
		fp >> Value;
		IPGlobal::S1U_SESSION_PKT_LIMIT = atoi(Value.c_str());
		printf("	S1U_SESSION_PKT_LIMIT			:: %d\n", IPGlobal::S1U_SESSION_PKT_LIMIT);
	}
}

VOID GConfig::get_s1uSessionTimeLimit(std::string& Key)
{
	Value.clear();

	if(Key.compare("S1U_SESSION_TIME_LIMIT") == 0)
	{
		fp >> Value;
		IPGlobal::S1U_SESSION_TIME_LIMIT = atoi(Value.c_str());
		printf("	S1U_SESSION_TIME_LIMIT			:: %d\n", IPGlobal::S1U_SESSION_TIME_LIMIT);
	}
}

VOID GConfig::get_s1uSessionCleanUpScanFreq(std::string& Key)
{
	Value.clear();

	if(Key.compare("S1U_SESSION_CLEAN_UP_SCAN_FREQ_SEC") == 0)
	{
		fp >> Value;
		IPGlobal::S1U_SESSION_CLEAN_UP_SCAN_FREQ_SEC = atoi(Value.c_str());
		printf("	S1U_SESSION_CLEAN_UP_SCAN_FREQ_SEC	:: %d\n", IPGlobal::S1U_SESSION_CLEAN_UP_SCAN_FREQ_SEC);
	}
}

VOID GConfig::get_s1uSessionCleanUpBatchLimit(std::string& Key)
{
	Value.clear();

	if(Key.compare("S1U_SESSION_CLEAN_UP_BATCH_LIMIT") == 0)
	{
		fp >> Value;
		IPGlobal::S1U_SESSION_CLEAN_UP_BATCH_LIMIT = atoi(Value.c_str());
		printf("	S1U_SESSION_CLEAN_UP_BATCH_LIMIT		:: %d\n", IPGlobal::S1U_SESSION_CLEAN_UP_BATCH_LIMIT);
	}
}

VOID GConfig::get_s1uSessionCleanUpTimeOut(std::string& Key)
{
	Value.clear();

	if(Key.compare("S1U_SESSION_CLEAN_UP_TIMEOUT_SEC") == 0)
	{
		fp >> Value;
		IPGlobal::S1U_SESSION_CLEAN_UP_TIMEOUT_SEC = atoi(Value.c_str());
		printf("\tS1U_SESSION_CLEAN_UP_TIMEOUT_SEC\t\t:: %d\n", IPGlobal::S1U_SESSION_CLEAN_UP_TIMEOUT_SEC);
	}
}

VOID GConfig::get_s1uDnsAnswerCount(std::string& Key)
{
	Value.clear();

	if(Key.compare("S1U_DNS_ANSWER") == 0)
	{
		fp >> Value;
		IPGlobal::S1U_DNS_ANSWER = atoi(Value.c_str());
		printf("\tS1U_DNS_ANSWER               		:: %d\n", IPGlobal::S1U_DNS_ANSWER);
	}
}

VOID GConfig::get_s1uVpsPacketLimit(std::string& Key)
{
	Value.clear();

	if(Key.compare("S1U_VPS_PACKET_PER_SEC") == 0)
	{
		fp >> Value;
		IPGlobal::S1U_VPS_PACKET_PER_SEC = atoi(Value.c_str());
		printf("\tS1U_VPS_PACKET_PER_SEC               	:: %d\n", IPGlobal::S1U_VPS_PACKET_PER_SEC);
	}
}

VOID GConfig::get_s1uUdpXdrForDnsFlag(std::string& Key)
{
	Value.clear();

	if(Key.compare("S1U_UDP_XDR_FOR_DNS") == 0)
	{
		fp >> Value;
		IPGlobal::S1U_UDP_XDR_FOR_DNS = Value.compare("true") == 0 ? true : false;
		printf("	S1U_UDP_XDR_FOR_DNS 			:: %s\n", Value.c_str());
	}
}

VOID GConfig::get_s1uSessionInstance(std::string& Key)
{
	Value.clear();

	if(Key.compare("S1U_SESSION_MANAGER_INSTANCES") == 0)
	{
		fp >> Value;
		IPGlobal::S1U_SESSION_MANAGER_INSTANCES = atoi(Value.c_str());
		printf("\tS1U_SESSION_MANAGER_INSTANCES         	:: %d\n", IPGlobal::S1U_SESSION_MANAGER_INSTANCES);
	}
}

VOID GConfig::get_s1uSessionInstanceCore(std::string& Key)
{
	Value.clear();

	if(Key.compare("S1U_SESSION_MANAGER_CPU_CORE") == 0)
	{
		fp >> Value;
		int cnt = 0;
		char *pch1 = strtok((char *)Value.c_str(),",");

		while (pch1 != NULL)
		{
			IPGlobal::S1U_SESSION_MANAGER_CPU_CORE[cnt] = atoi(pch1);
			printf("\tS1U_SESSION_MANAGER_CPU_CORE[%d]     	:: %d\n", cnt, IPGlobal::S1U_SESSION_MANAGER_CPU_CORE[cnt]);
			pch1 = strtok (NULL, ",");
			cnt++;
		}
	}
}

VOID GConfig::get_s1mmeSessionInstance(std::string& Key)
{
	Value.clear();

	if(Key.compare("S1MME_SESSION_MANAGER_INSTANCES") == 0)
	{
		fp >> Value;
		IPGlobal::S1MME_SESSION_MANAGER_INSTANCES = atoi(Value.c_str());
		printf("\tS1MME_SESSION_MANAGER_INSTANCES         :: %d\n", IPGlobal::S1MME_SESSION_MANAGER_INSTANCES);
	}

	if(IPGlobal::S1MME_SESSION_MANAGER_INSTANCES > MAX_S1MME_SESSION_MANAGER_SUPPORT) {
		printf("\n\n\t!! Oops S1MME Session Manager Instance can't be greater than %d !!\n\n", MAX_S1MME_SESSION_MANAGER_SUPPORT);
		exit(1);
	}

}

VOID GConfig::get_s1mmeSessionInstanceCore(std::string& Key)
{
	Value.clear();

	if(Key.compare("S1MME_SESSION_MANAGER_CPU_CORE") == 0)
	{
		fp >> Value;
		int cnt = 0;
		char *pch1 = strtok((char *)Value.c_str(),",");

		while (pch1 != NULL)
		{
			IPGlobal::S1MME_SESSION_MANAGER_CPU_CORE[cnt] = atoi(pch1);
			printf("\tS1MME_SESSION_MANAGER_CPU_CORE[%d]     	:: %d\n", cnt, IPGlobal::S1MME_SESSION_MANAGER_CPU_CORE[cnt]);
			pch1 = strtok (NULL, ",");
			cnt++;
		}
	}
}

VOID GConfig::get_s11SessionInstance(std::string& Key)
{
	Value.clear();

	if(Key.compare("S11_SESSION_MANAGER_INSTANCES") == 0)
	{
		fp >> Value;
		IPGlobal::S11_SESSION_MANAGER_INSTANCES = atoi(Value.c_str());
		printf("\tS11_SESSION_MANAGER_INSTANCES         	:: %d\n", IPGlobal::S11_SESSION_MANAGER_INSTANCES);
	}
}

VOID GConfig::get_s11SessionInstanceCore(std::string& Key)
{
	Value.clear();

	if(Key.compare("S11_SESSION_MANAGER_CPU_CORE") == 0)
	{
		fp >> Value;
		int cnt = 0;
		char *pch1 = strtok((char *)Value.c_str(),",");

		while (pch1 != NULL)
		{
			IPGlobal::S11_SESSION_MANAGER_CPU_CORE[cnt] = atoi(pch1);
			printf("\tS11_SESSION_MANAGER_CPU_CORE[%d]     	:: %d\n", cnt, IPGlobal::S11_SESSION_MANAGER_CPU_CORE[cnt]);
			pch1 = strtok (NULL, ",");
			cnt++;
		}
	}
}

VOID GConfig::get_s5s8SessionInstance(std::string& Key)
{
	Value.clear();

	if(Key.compare("S5S8_SESSION_MANAGER_INSTANCES") == 0)
	{
		fp >> Value;
		IPGlobal::S5S8_SESSION_MANAGER_INSTANCES = atoi(Value.c_str());
		printf("\tS5S8_SESSION_MANAGER_INSTANCES         	:: %d\n", IPGlobal::S5S8_SESSION_MANAGER_INSTANCES);
	}
}

VOID GConfig::get_s5s8SessionInstanceCore(std::string& Key)
{
	Value.clear();

	if(Key.compare("S5S8_SESSION_MANAGER_CPU_CORE") == 0)
	{
		fp >> Value;
		int cnt = 0;
		char *pch1 = strtok((char *)Value.c_str(),",");

		while (pch1 != NULL)
		{
			IPGlobal::S5S8_SESSION_MANAGER_CPU_CORE[cnt] = atoi(pch1);
			printf("\tS5S8_SESSION_MANAGER_CPU_CORE[%d]     	:: %d\n", cnt, IPGlobal::S5S8_SESSION_MANAGER_CPU_CORE[cnt]);
			pch1 = strtok (NULL, ",");
			cnt++;
		}
	}
}
//------------------------------------
VOID GConfig::get_s1uNoOfIpFlusher(std::string& Key)
{
	Value.clear();

	if(Key.compare("S1U_FLUSHER_NO") == 0)
	{
		fp >> Value;
		IPGlobal::S1U_FLUSHER_NO = atoi(Value.c_str());
		printf("\tS1U_FLUSHER_NO				:: %s\n", Value.c_str());
	}
}

VOID GConfig::get_s1uFlusherCore(std::string& Key)
{
	Value.clear();

	if(Key.compare("IP_FLUSHER_CPU_CORE") == 0)
	{
		fp >> Value;
		int cnt = 0;
		char *pch1 = strtok((char *)Value.c_str(),",");

		while (pch1 != NULL)
		{
			IPGlobal::S1U_FLUSHER_CPU_CORE[cnt] = atoi(pch1);
			printf("\tS1U_FLUSHER_CPU_CORE[%d]     		:: %d\n", cnt, IPGlobal::S1U_FLUSHER_CPU_CORE[cnt]);
			pch1 = strtok (NULL, ",");
			cnt++;
		}
	}
}

VOID GConfig::get_s1uWriteXdrFlag(std::string& Key)
{
	Value.clear();

	if(Key.compare("S1U_WRITE_XDR") == 0)
	{
		fp >> Value;
		if(Value.compare("true") == 0)
			IPGlobal::S1U_WRITE_XDR = true;
		else
			IPGlobal::S1U_WRITE_XDR = false;
		printf("\tS1U_WRITE_XDR\t\t\t\t:: %s\n", Value.c_str());
	}

}

VOID GConfig::get_s1uWriteXdrCore(std::string& Key)
{
	Value.clear();

	if(Key.compare("S1U_XDR_WRITE_CPU_CORE") == 0)
	{
		fp >> Value;
		IPGlobal::S1U_XDR_WRITE_CPU_CORE = atoi(Value.c_str());
		printf("\tS1U_XDR_WRITE_CPU_CORE			:: %s\n", Value.c_str());
	}
}

VOID GConfig::get_s1uFilePrefix(std::string& Key)
{
	Value.clear();

	if(Key.compare("S1U_FILE_PREFIX") == 0)
	{
			fp >> Value;
			IPGlobal::S1U_FILE_PREFIX = Value;
			printf("\tS1U_FILE_PREFIX\t\t\t\t:: %s\n", IPGlobal::S1U_FILE_PREFIX.c_str());
	}
}

VOID GConfig::get_noOfDnsFlusher(std::string& Key)
{
	Value.clear();

	if(Key.compare("DNS_FLUSHER_NO") == 0)
	{
		fp >> Value;
		IPGlobal::DNS_FLUSHER_NO = atoi(Value.c_str());
		printf("\tDNS_FLUSHER_NO				:: %s\n", Value.c_str());
	}
}

VOID GConfig::get_DnsFlusherCore(std::string& Key)
{
	Value.clear();

	if(Key.compare("DNS_FLUSHER_CPU_CORE") == 0)
	{
		fp >> Value;
		int cnt = 0;
		char *pch1 = strtok((char *)Value.c_str(),",");

		while (pch1 != NULL)
		{
			IPGlobal::DNS_FLUSHER_CPU_CORE[cnt] = atoi(pch1);
			printf("\tDNS_FLUSHER_CPU_CORE[%d]     		:: %d\n", cnt, IPGlobal::DNS_FLUSHER_CPU_CORE[cnt]);
			pch1 = strtok (NULL, ",");
			cnt++;
		}
	}
}

VOID GConfig::get_DnsWriteXdrFlag(std::string& Key)
{
	Value.clear();

	if(Key.compare("DNS_WRITE_XDR") == 0)
	{
		fp >> Value;
		if(Value.compare("true") == 0)
			IPGlobal::DNS_WRITE_XDR = true;
		else
			IPGlobal::DNS_WRITE_XDR = false;
		printf("\tDNS_WRITE_XDR\t\t\t\t:: %s\n", Value.c_str());
	}

}

VOID GConfig::get_DnsWriteXdrCore(std::string& Key)
{
	Value.clear();

	if(Key.compare("DNS_XDR_WRITE_CPU_CORE") == 0)
	{
		fp >> Value;
		IPGlobal::DNS_XDR_WRITE_CPU_CORE = atoi(Value.c_str());
		printf("\tDNS_XDR_WRITE_CPU_CORE			:: %s\n", Value.c_str());
	}
}

VOID GConfig::get_DnsFilePrefix(std::string& Key)
{
	Value.clear();

	if(Key.compare("DNS_FILE_PREFIX") == 0)
	{
			fp >> Value;
			IPGlobal::DNS_FILE_PREFIX = Value;
			printf("\tDNS_FILE_PREFIX\t\t\t\t:: %s\n", IPGlobal::DNS_FILE_PREFIX.c_str());
	}
}
//-------------------- S1MME ----------------
VOID GConfig::get_s1mmeNoOfFlusher(std::string& Key)
{
	Value.clear();

	if(Key.compare("S1MME_FLUSHER_NO") == 0)
	{
		fp >> Value;
		IPGlobal::S1MME_FLUSHER_NO = atoi(Value.c_str());
		printf("\tS1MME_FLUSHER_NO				:: %s\n", Value.c_str());
	}
}

VOID GConfig::get_s1mmeFlusherCore(std::string& Key)
{
	Value.clear();

	if(Key.compare("S1MME_FLUSHER_CPU_CORE") == 0)
	{
		fp >> Value;
		int cnt = 0;
		char *pch1 = strtok((char *)Value.c_str(),",");

		while (pch1 != NULL)
		{
			IPGlobal::S1MME_FLUSHER_CPU_CORE = atoi(pch1);
			printf("\tS1MME_FLUSHER_CPU_CORE     		:: %d\n", IPGlobal::S1MME_FLUSHER_CPU_CORE);
			pch1 = strtok (NULL, ",");
			cnt++;
		}
	}
}

VOID GConfig::get_s1mmeWriteXdrFlag(std::string& Key)
{
	Value.clear();

	if(Key.compare("S1MME_WRITE_XDR") == 0)
	{
		fp >> Value;
		if(Value.compare("true") == 0)
			IPGlobal::S1MME_WRITE_XDR = true;
		else
			IPGlobal::S1MME_WRITE_XDR = false;
		printf("\tS1MME_WRITE_XDR\t\t\t\t:: %s\n", Value.c_str());
	}

}

VOID GConfig::get_s1mmeWriteXdrCore(std::string& Key)
{
	Value.clear();

	if(Key.compare("S1MME_XDR_WRITE_CPU_CORE") == 0)
	{
		fp >> Value;
		IPGlobal::S1MME_XDR_WRITE_CPU_CORE = atoi(Value.c_str());
		printf("\tS1MME_XDR_WRITE_CPU_CORE			:: %s\n", Value.c_str());
	}
}

VOID GConfig::get_s1mmeFilePrefix(std::string& Key)
{
	Value.clear();

	if(Key.compare("S1MME_FILE_PREFIX") == 0)
	{
			fp >> Value;
			IPGlobal::S1MME_FILE_PREFIX = Value;
			printf("\tS1MME_FILE_PREFIX\t\t\t\t:: %s\n", IPGlobal::S1MME_FILE_PREFIX.c_str());
	}
}
//-------------------- S11 ----------------
VOID GConfig::get_s11NoOfFlusher(std::string& Key)
{
	Value.clear();

	if(Key.compare("S11_FLUSHER_NO") == 0)
	{
		fp >> Value;
		IPGlobal::S11_FLUSHER_NO = atoi(Value.c_str());
		printf("\tS11_FLUSHER_NO				:: %s\n", Value.c_str());
	}
}

VOID GConfig::get_s11FlusherCore(std::string& Key)
{
	Value.clear();

	if(Key.compare("S11_FLUSHER_CPU_CORE") == 0)
	{
		fp >> Value;
		int cnt = 0;
		char *pch1 = strtok((char *)Value.c_str(),",");

		while (pch1 != NULL)
		{
			IPGlobal::S11_FLUSHER_CPU_CORE = atoi(pch1);
			printf("\tS11_FLUSHER_CPU_CORE     		:: %d\n", IPGlobal::S11_FLUSHER_CPU_CORE);
			pch1 = strtok (NULL, ",");
			cnt++;
		}
	}
}

VOID GConfig::get_s11WriteXdrFlag(std::string& Key)
{
	Value.clear();

	if(Key.compare("S11_WRITE_XDR") == 0)
	{
		fp >> Value;
		if(Value.compare("true") == 0)
			IPGlobal::S11_WRITE_XDR = true;
		else
			IPGlobal::S11_WRITE_XDR = false;
		printf("\tS11_WRITE_XDR\t\t\t\t:: %s\n", Value.c_str());
	}

}

VOID GConfig::get_s11WriteXdrCore(std::string& Key)
{
	Value.clear();

	if(Key.compare("S11_XDR_WRITE_CPU_CORE") == 0)
	{
		fp >> Value;
		IPGlobal::S11_XDR_WRITE_CPU_CORE = atoi(Value.c_str());
		printf("\tS11_XDR_WRITE_CPU_CORE			:: %s\n", Value.c_str());
	}
}

VOID GConfig::get_s11FilePrefix(std::string& Key)
{
	Value.clear();

	if(Key.compare("S11_FILE_PREFIX") == 0)
	{
			fp >> Value;
			IPGlobal::S11_FILE_PREFIX = Value;
			printf("\tS11_FILE_PREFIX\t\t\t\t:: %s\n", IPGlobal::S11_FILE_PREFIX.c_str());
	}
}
//-------------------- S5S8 ----------------
VOID GConfig::get_s5s8NoOfFlusher(std::string& Key)
{
	Value.clear();

	if(Key.compare("S5S8_FLUSHER_NO") == 0)
	{
		fp >> Value;
		IPGlobal::S5S8_FLUSHER_NO = atoi(Value.c_str());
		printf("\tS5S8_FLUSHER_NO				:: %s\n", Value.c_str());
	}
}

VOID GConfig::get_s5s8FlusherCore(std::string& Key)
{
	Value.clear();

	if(Key.compare("S5S8_FLUSHER_CPU_CORE") == 0)
	{
		fp >> Value;
		int cnt = 0;
		char *pch1 = strtok((char *)Value.c_str(),",");

		while (pch1 != NULL)
		{
			IPGlobal::S5S8_FLUSHER_CPU_CORE = atoi(pch1);
			printf("\tS5S8_FLUSHER_CPU_CORE     		:: %d\n", IPGlobal::S5S8_FLUSHER_CPU_CORE);
			pch1 = strtok (NULL, ",");
			cnt++;
		}
	}
}

VOID GConfig::get_s5s8WriteXdrFlag(std::string& Key)
{
	Value.clear();

	if(Key.compare("S5S8_WRITE_XDR") == 0)
	{
		fp >> Value;
		if(Value.compare("true") == 0)
			IPGlobal::S5S8_WRITE_XDR = true;
		else
			IPGlobal::S5S8_WRITE_XDR = false;
		printf("\tS5S8_WRITE_XDR\t\t\t\t:: %s\n", Value.c_str());
	}

}

VOID GConfig::get_s5s8WriteXdrCore(std::string& Key)
{
	Value.clear();

	if(Key.compare("S5S8_XDR_WRITE_CPU_CORE") == 0)
	{
		fp >> Value;
		IPGlobal::S5S8_XDR_WRITE_CPU_CORE = atoi(Value.c_str());
		printf("\tS5S8_XDR_WRITE_CPU_CORE			:: %s\n", Value.c_str());
	}
}

VOID GConfig::get_s5s8FilePrefix(std::string& Key)
{
	Value.clear();

	if(Key.compare("S5S8_FILE_PREFIX") == 0)
	{
			fp >> Value;
			IPGlobal::S5S8_FILE_PREFIX = Value;
			printf("\tS5S8_FILE_PREFIX\t\t\t:: %s\n", IPGlobal::S5S8_FILE_PREFIX.c_str());
	}
}

unsigned long GConfig::ipToLong(char *ip, unsigned long *plong)
{
	char *next = NULL;
	const char *curr = ip;
	unsigned long tmp;
	int i, err = 0;

	*plong = 0;
	for (i = 0; i < NUM_OCTETTS; i++) {
		tmp = strtoul(curr, &next, 10);
		if (tmp >= 256 || (tmp == 0 && next == curr)) {
			err++;
			break;
		}
		*plong = (*plong << 8) + tmp;
		curr = next + 1;
	}

	if (err)
		return 1;
	else
		return *plong;
}
