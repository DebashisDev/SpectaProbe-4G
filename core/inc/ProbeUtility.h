/*
 * ProbeUtility.h
 *
 *  Created on: 30-Jan-2016
 *      Author: Debashis
 */

#ifndef SRC_PROBEUTILITY_H_
#define SRC_PROBEUTILITY_H_


#include <netinet/tcp.h>
#include <netinet/in.h>
#include <pthread.h>
#include <string>
#include <stdlib.h>
#include <vector>
#include <sstream>

#include "IPGlobal.h"

#define BASE		10000000000


#define handle_error_en(en, msg) \
       do { perror(msg); exit(EXIT_FAILURE); } while (0)

class ProbeUtility {

	public:
		ProbeUtility();
		~ProbeUtility();

	uint32_t getCurrentSec();
	uint32_t getCurrentSecond();
	uint32_t getCurrentMinute();
	ULONG	 getCurrentMilliSec();
	TCHAR 	 *getCurrentTimeStamp();
	TCHAR	 *getSystemTimeStamp(TCHAR *currentTime);
	ULONG 	 getEpochTimeMicroSecond();
	TCHAR	 *getSystemTimeHM(TCHAR *currentTime);
	VOID 	 Append(uint8_t *original, const uint8_t *add);
	VOID 	 printBytes(const uint8_t *identifier, bool printflag, const uint8_t *packet, uint32_t size);
	static VOID	 getIPHex(uint8_t *address, uint8_t *hexaddress);
	VOID	 fillIP(uint8_t *address, uint8_t *fillInAddress);
	VOID	 ExtractIP4Address(const BYTE packet, char *ipBuffer, uint32_t loc);
//	VOID	 ExtractIP4AddressR(const BYTE packet, uint8_t *ipBuffer, uint32_t loc);
//	VOID	 ExtractIP6Address(const BYTE packet, char *ipBuffer, uint32_t loc);
	VOID	 ExtractIP6Address(const uint8_t *packet, char *ipBuffer, uint32_t loc);
	VOID	 ExtractIP6Prefix(const uint8_t *packet, char *ipBuffer, uint32_t loc, uint32_t end);
	static uint16_t parseTcpTimeStamp(struct tcphdr *tcp, ULONG *tsval, ULONG *tsecr);
//	VOID	 flushHTTPData(const uint8_t *sIP, const uint8_t * dIP, uint16_t sP, uint16_t dP, uint8_t *tokenBuf);
	static void pinThread(pthread_t th, int core_num);
	string convertToTimeStamp(ULONG currentTime);
//	static  string getKey(int, const TPacket *msgObj);
//	static string	getDNSKey(uint32_t destAddr, uint32_t sourceAddr);
	static vector<string> split(string str, char delimiter);

	uint16_t getMinToProcess(uint16_t);
	int16_t  getPreviousMin(uint16_t);
	uint16_t getHourToProcess(uint16_t);
	int16_t  getPreviousHour(uint16_t);

	void printPacketBytes(const BYTE packet, int size);

	uint8_t matchIPs(uint32_t src, uint32_t dst, uint32_t net, uint32_t num_bits);
	uint8_t matchIP(uint32_t ip_to_check, uint32_t net, uint32_t num_bits);
	ULONG HextoDigits(TCHAR *hexadecimal);
	ULONG getLength(const BYTE packet, size_t offset);

	int16_t getPreviousSecRange(uint16_t currentSec);
	uint16_t getSecRangeToProcess(uint16_t lastProcessedSec);
	uint16_t getCurrentSecRange(uint16_t currentSec);
	uint16_t getNextSecRange(uint16_t currentRange);
	uint16_t getProcessIndex(uint16_t prevIndex);
	uint16_t getPrevIndex(uint16_t currIndex);

	static VOID HEXDUMP(const void* pv, int len);
	static char* getByteToHex(const void* pv, int len);

	VOID writePcap(char *pcapFileName, const BYTE packet, uint64_t counter, int length, long tv_sec);
};

#endif /* SRC_PROBEUTILITY_H_ */
