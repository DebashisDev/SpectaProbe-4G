/*
 * GTPConfig.cpp
 *
 *  Created on: 04-Aug-2016
 *      Author: Debashis
 */

#include "IPGlobal.h"
#include "GTPConfig.h"


GTPConfig::GTPConfig()
{}

GTPConfig::~GTPConfig()
{}

void GTPConfig::loadGNConfig(ifstream& fp)
{
	std::string Key, Value, channel;

	/* ** GN Configuration file ** */
	printf("\n  Loading GTP Configurations...\n");

	while(!fp.eof())
	{
		Key.clear();

		fp >> Key;
		Value.clear();

//		if(Key.compare("GTPC_FLUSH_MAP_REPO_SIZE") == 0)
//		{
//				fp >> Value;
//				IPGlobal::GTPC_FLUSH_MAP_REPO_SIZE = atoi(Value.c_str());;
//				printf("\tGTPC_FLUSH_MAP_REPO_SIZE\t\t:: %d\n", IPGlobal::GTPC_FLUSH_MAP_REPO_SIZE);
//		}
//
//		else if(Key.compare("GTPC_ZMQ_FLUSH_MAP_ARRAY_SIZE") == 0)
//		{
//				fp >> Value;
//				IPGlobal::GTPC_ZMQ_FLUSH_MAP_ARRAY_SIZE = atoi(Value.c_str());;
//				printf("\tGTPC_ZMQ_FLUSH_MAP_ARRAY_SIZE\t\t:: %d\n", IPGlobal::GTPC_ZMQ_FLUSH_MAP_ARRAY_SIZE);
//		}
//		else if(Key.compare("GN_GLB_CLEANUP_INTERVAL_MIN") == 0)
//		{
//			fp >> Value;
//			IPGlobal::GN_GLB_CLEANUP_INTERVAL_MIN = atoi(Value.c_str());;
//			printf("\tGN_GLB_CLEANUP_INTERVAL_MIN\t:: %d\n", IPGlobal::GN_GLB_CLEANUP_INTERVAL_MIN);
//		}
//		else if(Key.compare("GN_GTPC_GLOBAL_SESSION_CLEANUP_TIMEOUT_SEC") == 0)
//		{
//			fp >> Value;
//			IPGlobal::GN_GTPC_GLOBAL_SESSION_CLEANUP_TIMEOUT_SEC = atoi(Value.c_str());;
//			printf("\tGN_GTPC_GLOBAL_SESSION_CLEANUP_TIMEOUT_SEC\t:: %d\n", IPGlobal::GN_GTPC_GLOBAL_SESSION_CLEANUP_TIMEOUT_SEC);
//		}
//		/* ************ GTPC ************ */
//		else if(Key.compare("GTPC_FLUSH_FLAG") == 0)
//		{
//			fp >> Value;
//			if(Value.compare("true") == 0)
//				IPGlobal::GTPC_FLUSH_FLAG = true;
//			else
//				IPGlobal::GTPC_FLUSH_FLAG = false;
//			printf("\tGTPC_FLUSH_FLAG\t\t\t:: %s\n", Value.c_str());
//		}
//		else if(Key.compare("GTPC_WRITE_XDR") == 0)
//		{
//			fp >> Value;
//			if(Value.compare("true") == 0)
//				IPGlobal::GTPC_WRITE_XDR = true;
//			else
//				IPGlobal::GTPC_WRITE_XDR = false;
//			printf("\tGTPC_WRITE_XDR\t\t\t:: %s\n", Value.c_str());
//		}
//		else if(Key.compare("GTPC_FLUSH_PORT") == 0)
//		{
//				fp >> Value;
//				IPGlobal::GTPC_FLUSH_PORT = Value;
//				printf("\tGTPC_FLUSH_PORT\t\t\t:: %s\n", IPGlobal::GTPC_FLUSH_PORT.c_str());
//		}
//		else if(Key.compare("GTPC_FILE_PREFIX") == 0)
//		{
//				fp >> Value;
//				IPGlobal::GTPC_FILE_PREFIX = Value;
//				printf("\tGTPC_FILE_PREFIX\t\t\t:: %s\n", IPGlobal::GTPC_FILE_PREFIX.c_str());
//		}
//		else if(Key.compare("GTPC_ZMQ_FLUSHER_CPU_CORE") == 0)
//		{
//				fp >> Value;
//				IPGlobal::GTPC_ZMQ_FLUSHER_CPU_CORE = atoi(Value.c_str());
//				printf("\tGTPC_ZMQ_FLUSHER_CPU_CORE\t\t\t:: %s\n", Value.c_str());
//		}
//		else if(Key.compare("GTPC_FLUSHER_CPU_CORE") == 0)
//		{
//				fp >> Value;
//				IPGlobal::GTPC_FLUSHER_CPU_CORE = atoi(Value.c_str());
//				printf("\tGTPC_FLUSHER_CPU_CORE\t\t\t:: %s\n", Value.c_str());
//		}
//		else if(Key.compare("GTPC_XDR_FLUSHER_CPU_CORE") == 0)
//		{
//				fp >> Value;
//				IPGlobal::GTPC_XDR_FLUSHER_CPU_CORE = atoi(Value.c_str());
//				printf("\tGTPC_XDR_FLUSHER_CPU_CORE\t\t\t:: %s\n", Value.c_str());
//		}
		/* ************ GTPU ************ */
//		else if(Key.compare("GN_GTPU_FLUSH_FLAG") == 0)
//		{
//			fp >> Value;
//			if(Value.compare("true") == 0)
//				IPGlobal::IP_FLUSH_FLAG = true;
//			else
//				IPGlobal::IP_FLUSH_FLAG = false;
//			printf("\tGN_GTPU_FLUSH_FLAG\t\t\t:: %s\n", Value.c_str());
//		}
//		else if(Key.compare("GN_GTPU_WRITE_XDR") == 0)
//		{
//			fp >> Value;
//			if(Value.compare("true") == 0)
//				IPGlobal::IP_WRITE_XDR = true;
//			else
//				IPGlobal::IP_WRITE_XDR = false;
//			printf("\tGN_GTPU_WRITE_XDR\t\t\t:: %s\n", Value.c_str());
//		}
//		else if(Key.compare("GN_GTPU_FLUSH_PORT") == 0)
//		{
//				fp >> Value;
//				IPGlobal::IP_FLUSH_PORT = Value;
//				printf("\tGN_GTPU_FLUSH_PORT\t\t\t:: %s\n", IPGlobal::IP_FLUSH_PORT.c_str());
//		}
//		else if(Key.compare("GN_GTPU_FILE_PREFIX") == 0)
//		{
//				fp >> Value;
//				IPGlobal::IP_FILE_PREFIX = Value;
//				printf("\tGN_GTPU_FILE_PREFIX\t\t\t:: %s\n", IPGlobal::IP_FILE_PREFIX.c_str());
//		}
//
//		/* ************ DNS ************ */
//		else if(Key.compare("GN_DNS_WRITE_XDR") == 0)
//		{
//			fp >> Value;
//			if(Value.compare("true") == 0)
//				IPGlobal::DNS_WRITE_XDR = true;
//			else
//				IPGlobal::DNS_WRITE_XDR = false;
//			printf("\tGN_DNS_WRITE_XDR\t\t\t:: %s\n", Value.c_str());
//		}
//		else if(Key.compare("GN_DNS_FILE_PREFIX") == 0)
//		{
//				fp >> Value;
//				IPGlobal::DNS_FILE_PREFIX = Value;
//				printf("\tGN_DNS_FILE_PREFIX\t\t\t:: %s\n", IPGlobal::DNS_FILE_PREFIX.c_str());
//		}
//		else if(Key.compare("GN_DNS_FLUSH_FLAG") == 0)
//		{
//			fp >> Value;
//			if(Value.compare("true") == 0)
//				IPGlobal::DNS_FLUSH_FLAG = true;
//			else
//				IPGlobal::DNS_FLUSH_FLAG = false;
//			printf("\tGN_DNS_FLUSH_FLAG\t\t\t:: %s\n", Value.c_str());
//		}
//		else if(Key.compare("GN_DNS_FLUSH_PORT") == 0)
//		{
//				fp >> Value;
//				IPGlobal::DNS_FLUSH_PORT = Value;
//				printf("\tGN_DNS_FLUSH_PORT\t\t\t:: %s\n", IPGlobal::DNS_FLUSH_PORT.c_str());
//		}
//		else if(Key.compare("GTP_ZMQ_FLUSER_TPS") == 0)
//		{
//				fp >> Value;
//				IPGlobal::GTP_ZMQ_FLUSER_TPS = atoi(Value.c_str());
//				printf("\tGTP_ZMQ_FLUSER_TPS\t\t\t:: %d\n", IPGlobal::GTP_ZMQ_FLUSER_TPS);
//		}
//		else if(Key.compare("GN_GTPC_IDLE_SESSION_TIMEOUT_IN_SEC") == 0)
//		{
//			fp >> Value;
//			IPGlobal::GN_GTPC_IDLE_SESSION_TIMEOUT_IN_SEC = atoi(Value.c_str());
//			printf("\tGN_GTPC_IDLE_SESSION_TIMEOUT_IN_SEC\t:: %d Sec(s)\n", IPGlobal::GN_GTPC_IDLE_SESSION_TIMEOUT_IN_SEC);
//		}
//		else if(Key.compare("GN_GTPU_IDLE_SESSION_TIMEOUT_IN_SEC") == 0)
//		{
//			fp >> Value;
//			IPGlobal::IP_SESSION_CLEAN_UP_TIMEOUT_SEC = atoi(Value.c_str());
//			printf("\tGTPU_IDLE_SESSION_TIMEOUT_SEC\t\t:: %d Sec(s)\n", IPGlobal::IP_SESSION_CLEAN_UP_TIMEOUT_SEC);
//		}
	}
}

