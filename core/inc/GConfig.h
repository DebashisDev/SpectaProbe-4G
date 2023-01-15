/*
 * GConfig.h
 *
 *  Created on: 26-Jul-2016
 *      Author: Debashis
 */

#ifndef CORE_SRC_GCONFIG_H_
#define CORE_SRC_GCONFIG_H_

#include <string.h>
#include <fstream>

#include "GConstant.h"
#include "SpectaTypedef.h"

#define NUM_OCTETTS 4

using namespace std;

class GConfig
{
	private:
		ifstream fp;
		string Key, Value;

		VOID 	initialize(char *fileName);
		VOID 	openConfigFile(char *fileName);
		VOID 	closeConfigFile();

		unsigned long ipToLong(char *ip, unsigned long *plong);

		VOID 	get_probeId(std::string& Key);
		VOID 	get_S1UProbe(std::string& Key);
		VOID 	get_S1MMEProbe(std::string& Key);
		VOID 	get_S11Probe(std::string& Key);
		VOID 	get_S5S8Probe(std::string& Key);
		VOID	get_logLevel(std::string& Key);
		VOID	get_printStats(std::string& Key);
		VOID	get_printStatsFrequency(std::string& Key);
		VOID	get_logStatsFrequency(std::string& Key);
		VOID	get_xdrDir(std::string& Key);
		VOID	get_logDir(std::string& Key);
		VOID	get_dataDir(std::string& Key);
		VOID	get_adminFlag(std::string& Key);
		VOID	get_adminPort(std::string& Key);
		VOID	get_ethernetInterface(std::string& Key);
		VOID	get_solarInterface(std::string& Key);
		VOID	get_interfaceCPU(std::string& Key);
		VOID	get_solarTimeStamp(std::string& Key);
		VOID	get_packetLen(std::string& Key);
		VOID	get_PPSPerInterface(std::string& Key);
		VOID	get_PPSCap(std::string& Key);
		VOID	get_routerPerInterface(std::string& Key);
		VOID	get_routerCPU(std::string& Key);
		VOID	get_s1mmeIPRange(std::string& Key);
		VOID	get_s5s8PGWIPRange(std::string& Key);
		VOID	get_s1uProcessOutOfRange(std::string& Key);
		VOID	get_s1uProcessUserAgent(std::string& Key);
		VOID	get_s1uCheckDuplicate(std::string& Key);
		VOID	get_s1uProcessAck(std::string& Key);
		VOID	get_s1uProcessAckSession(std::string& Key);
		VOID	get_s1uSessionTimeIndexPktLimit(std::string& Key);
		VOID	get_s1uSessionPacketLimit(std::string& Key);
		VOID	get_s1uSessionTimeLimit(std::string& Key);
		VOID	get_s1uSessionCleanUpScanFreq(std::string& Key);
		VOID	get_s1uSessionCleanUpBatchLimit(std::string& Key);
		VOID	get_s1uSessionCleanUpTimeOut(std::string& Key);
		VOID	get_s1uDnsAnswerCount(std::string& Key);
		VOID	get_s1uVpsPacketLimit(std::string& Key);
		VOID	get_s1uSessionInstance(std::string& Key);
		VOID	get_s1uUdpXdrForDnsFlag(std::string& Key);
		VOID	get_s1uSessionInstanceCore(std::string& Key);

		VOID	get_s1mmeSessionInstance(std::string& Key);
		VOID	get_s1mmeSessionInstanceCore(std::string& Key);
		VOID	get_s11SessionInstance(std::string& Key);
		VOID	get_s11SessionInstanceCore(std::string& Key);
		VOID	get_s5s8SessionInstance(std::string& Key);
		VOID	get_s5s8SessionInstanceCore(std::string& Key);

		VOID	get_s1uNoOfIpFlusher(std::string& Key);
		VOID	get_s1uFlusherCore(std::string& Key);
		VOID	get_s1uWriteXdrFlag(std::string& Key);
		VOID	get_s1uWriteXdrCore(std::string& Key);
		VOID	get_s1uFilePrefix(std::string& Key);
		VOID	get_noOfDnsFlusher(std::string& Key);
		VOID	get_DnsFlusherCore(std::string& Key);
		VOID	get_DnsWriteXdrFlag(std::string& Key);
		VOID	get_DnsWriteXdrCore(std::string& Key);
		VOID	get_DnsFilePrefix(std::string& Key);

		VOID	get_s1mmeNoOfFlusher(std::string& Key);
		VOID	get_s1mmeFlusherCore(std::string& Key);
		VOID	get_s1mmeWriteXdrFlag(std::string& Key);
		VOID	get_s1mmeWriteXdrCore(std::string& Key);
		VOID	get_s1mmeFilePrefix(std::string& Key);

		VOID	get_s11NoOfFlusher(std::string& Key);
		VOID	get_s11FlusherCore(std::string& Key);
		VOID	get_s11WriteXdrFlag(std::string& Key);
		VOID	get_s11WriteXdrCore(std::string& Key);
		VOID	get_s11FilePrefix(std::string& Key);

		VOID	get_s5s8NoOfFlusher(std::string& Key);
		VOID	get_s5s8FlusherCore(std::string& Key);
		VOID	get_s5s8WriteXdrFlag(std::string& Key);
		VOID	get_s5s8WriteXdrCore(std::string& Key);
		VOID	get_s5s8FilePrefix(std::string& Key);

	public:
		GConfig(char *fileName);
		~GConfig();

		uint16_t 		LOG_LEVEL;
		uint16_t		OPERATOR_ID = 0;

		std::string 	XDR_DIR;
		std::string 	LOG_DIR;
		std::string 	DATA_DIRECTORY;
		std::string 	TRACE_DIR;

		BOOL			S1U_PROBE;
		BOOL			GX_PROBE;
		BOOL			S1MME_PROBE;
		BOOL			S11_PROBE;
		BOOL			S5S8_PROBE;
};
//		unsigned long ipToLong(char *ip, ULONG *plong);
#endif /* CORE_SRC_GCONFIG_H_ */
