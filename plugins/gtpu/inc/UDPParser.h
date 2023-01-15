/*
 * PUDP.h
 *
 *  Created on: Nov 29, 2015
 *      Author: Debashis
 */

#ifndef INC_UDPPROBE_H_
#define INC_UDPPROBE_H_

#include "IPGlobal.h"
#include "ProbeUtility.h"
#include "TCPUDPGlobal.h"
#include "DnsData.h"
#include "Log.h"

using namespace std;

enum
{
  A 	= 1,				// IPv4 Address
  NS 	= 2,
  MD 	= 3,
  MF 	= 4,
  CNAME = 5,
  SOA	= 6,
  MB	= 7,
  MG	= 8,
  MR	= 9,
  null	= 10,
  WKS	= 11,
  PTR	= 12,
  HINFO	= 13,
  MINFO	= 14,
  MX	= 15,
  TXT	= 16,
  RP	= 17,
  AFSDB	= 18,
  X25	= 19,
  ISDN	= 20,
  RT	= 21,
  NSAP	= 22,
  NSAPPTR	= 23,
  SIG	= 24,
  KEY	= 25,
  PX	= 26,
  GPOS	= 27,
  AAAA 	= 28,				// IPv6 Address
  LOC	= 29,
  NXT	= 30,
  EID	= 31
}IPTYPE;

enum
{
	IPV4_DNS_RR_HEADER = 16,
	STUN_PKT_HEADER	   = 20,
	IPV6_DNS_RR_HEADER = 28
};

#define INDICATION      		0x0115
#define ALLOCATION_RESP      	0x0103

#define MAGIC_COOKIE            0x000f
#define REMOTE_ADDRESS        	0x0012
#define XOR_MAP_ADDRESS         0x0020
#define XOR_OPT_MAP_ADDRESS     0x8020

#define	SOURCE_INSIDE_IP	2
#define	SOURCE_GLOBAL_IP	3
#define	SOURCE_GLOBAL_PORT	4
#define	DESTINATION_IP		5
#define	DESTINATION_PORT	6
#define	PROTOCOL			7
#define	SOURCE_INSIDE_PORT	8

#define STUN_PKT_HEADER 20

struct stun_packet_header {
  uint16_t msgType, msgLen;
  uint32_t cookie;
  uint8_t  transactionId[8];
};


class UDPParser : public DnsData
{
	private:
		ProbeUtility 	*utility;

		timeval curTime;
		long beginEpochSec = 0;
		int beginSec = 0;

		int instanceId = 0;
		uint16_t qdcount = 0, ancount = 0;

		char	sourceInsideIp[IP_ADDR_LEN];
		int		sourceInsidePort;
		char	sourceGlobalIp[IP_ADDR_LEN];
		int		sourceGlobalPort;
		char	destinationIp[IP_ADDR_LEN];
		int		destinationPort;
		int		protocol;

		ULONG convIP2Long(char *ipAddress);
		VOID  insertStunData(string key, string addr, ULONG epochTimeSec);

	public:

		UDPParser();
		~UDPParser();

		VOID	parseUDPPacket(const BYTE packet, MPacket *tPacket);
		VOID	parsePacketDNS(const BYTE packet, MPacket *);
		BOOL	parsePacketDNSQueries(uint32_t, uint32_t, MPacket *msg, const UCHAR *, uint32_t *retPos);
		string 	read_rr_name(const uint8_t *packet, uint32_t *packet_p, uint32_t id_pos, uint16_t len);
		VOID	parsePacketDNSAnswers(uint32_t pos, MPacket *msgObj, const BYTE packet);
		VOID	lockDnsMap();
		VOID	unLockDnsMap();
		VOID	decodeStunMsg(const BYTE packet, MPacket *msgObj);
		VOID 	parsePacketSysLog(const BYTE packet,  MPacket *msgObj);
		vector<string> split(string str, char delimiter);
};

#endif	/* INC_UDPPROBE_H_ */
