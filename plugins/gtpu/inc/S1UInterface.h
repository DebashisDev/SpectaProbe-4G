/*
 * IPSMInterface.h
 *
 *  Created on: 20-Jul-2016
 *      Author: deb
 */

#ifndef PLUGINS_TCP_SRC_IPSMINTERFACE_H_
#define PLUGINS_TCP_SRC_IPSMINTERFACE_H_

#include <netinet/ip.h>
#include <arpa/inet.h>
#include <time.h>
#include <sys/time.h>
#include <string>

#include "IPGlobal.h"
#include "SpectaTypedef.h"
#include "Log.h"
#include "TCPUDPGlobal.h"
#include "BaseConfig.h"

#define DNS_FLUSH_REQ_RSP		30
#define DNS_FLUSH_RSP_REQ		31
#define DNS_FLUSH_CLEANUP_REQ_RSP	32
#define DNS_FLUSH_CLEANUP_REQ_NORSP	33
#define DNS_FLUSH_CLEANUP_RSP_NOREQ	34

#define DNS_NO_ERROR			0

class S1UInterface : BaseConfig
{
	private:
			ULONG freeIndexTime = 0;
			timeval curTime;
			BOOL vpsFlag = true;

			typedef struct _cleanObj
			{
				uint64_t key;
				int mapIndex;
				int poolIndex;
			}cleanObj;

			int instanceId = 0;

			uint64_t		vpsTimeKeys[10000];

			int freeBitPosDns  = 0;
			int freeBitPosDnsMax = 0;
			std::bitset<DNS_SESSION_POOL_ARRAY_ELEMENTS> bitFlagsDnsSession[DNS_SESSION_POOL_ARRAY_SIZE];
			std::map<int, dnsSession*> dnsSessionPoolMap[DNS_SESSION_POOL_ARRAY_SIZE];
			int 	getFreeIndexDns();
			VOID 	releaseIndexDns(int idx);
			VOID 	initializeDnsSessionPool();
			dnsSession* getDnsSessionFromPool(int idx);
			std::map<int, cleanObj> dnsSessionCleanUpMap;
			int dnsSessionCleanUpMap_cnt = 0;
			std::map<uint64_t, int> dnsSessionMap;

			std::map<int, std::string> dnsDatabaseCleanMap;
			int dnsDatabaseCleanMap_cnt = 0;

			std::vector<string> sysLogCleanVector;
			int sysLogCleanMap_cnt = 0;

			VOID		requestUpdateDnsSession(dnsSession *pDnsSession, MPacket *msgObj);
			VOID 		responseUpdateDnsSession(dnsSession *pDnsSession, MPacket *msgObj);
			dnsSession* getDnsSession(MPacket *msgObj, bool *found);

//			VOID 		getIpv6DNSSessionKey(std::string &key, char* userAddrLong, uint32_t dnsTransactionId, uint16_t port);
			VOID		getIpv4DNSSessionKey(uint64_t &key, uint32_t userAddrLong, uint16_t port, uint32_t destAddrLong, uint32_t dnsTransactionId);

			VOID 		flushDnsSession(dnsSession *pDnsSession, int type);

			int freeBitPosIp  = 0;
			int freeBitPosIpMax;
			std::bitset<IP_SESSION_POOL_ARRAY_ELEMENTS> bitFlagsIpSession[IP_SESSION_POOL_ARRAY_SIZE];
			std::map<int, ipSession*> ipSessionPoolMap[IP_SESSION_POOL_ARRAY_SIZE];
			int 	getFreeIndexIP();
			VOID 	releaseIndexIP(int idx);
			VOID 	initializeIPSessionPool();
			ipSession* getIPSessionFromPool(int idx);
			std::map<int, cleanObj> ipSessionCleanUpMap;
			int ipSessionCleanUpMap_cnt;
			std::map<uint64_t, int> ipSessionMap[IP_SESSION_POOL_ARRAY_ELEMENTS];

			ipSession* 	getIpSession(MPacket *msgObj, bool *found, bool create);
			VOID 		eraseIpSession(ipSession *pIpSession);

			VOID 		initializeTcpSession(ipSession *pIpSession, MPacket *msgObj);
			VOID		updateTcpSession(ipSession *pIpSession, MPacket *msgObj);

			VOID 		initializeUdpSession(ipSession *pIpSession, MPacket *msgObj);
			VOID 		updateUdpSession(ipSession *pIpSession, MPacket *msgObj);

			VOID 		flushIpSession(int id, ipSession *pIpSession, bool erase);
			VOID 		storeIpSession(int index, ipSession *pIpSession);
			VOID 		storeIpSession_f_0(int index, ipSession *pIpSession);
			VOID 		storeIpSession_f_1(int index, ipSession *pIpSession);
			VOID 		storeIpSession_f_2(int index, ipSession *pIpSession);
			VOID 		storeIpSession_f_3(int index, ipSession *pIpSession);

			VOID 		storeDnsSession(int index, dnsSession *pDnsSession);
			VOID 		storeDnsSession_f_0(int index, dnsSession *pDnsSession);
			VOID 		storeDnsSession_f_1(int index, dnsSession *pDnsSession);
			VOID 		storeDnsSession_f_2(int index, dnsSession *pDnsSession);
			VOID 		storeDnsSession_f_3(int index, dnsSession *pDnsSession);

			VOID 		flushCleanTimedOutSessionsIP(ipSession *pIpSession);
			VOID 		processTimedOutSessionsIP(int &ip_session_scanned_sm_cnt, int &ip_session_cleaned_tcp_sm_cnt, int &ip_session_cleaned_udp_sm_cnt);
			VOID 		eraseCleanedSessions();

			BOOL		checkDuplicate(ipSession *pIpSession, MPacket *msgObj);
			BOOL		updateVPS(ipSession *pIpSession, MPacket *msgObj);
			VOID		timeStampArrivalPacket(ipSession *pIpSession, MPacket *msgObj);
			VOID		updateTime(ipSession *pIpSession, int id);

	public:
			S1UInterface(int id);
			~S1UInterface();

			VOID 	IP_TCPProcessPacket(MPacket *msgObj);
			VOID 	IP_UdpProcessPacket(MPacket *msgObj);
			VOID 	IP_DnsProcessPacket(MPacket *msgObj);
			int		getMapIndexAndSessionKey(MPacket *msgObj);
			VOID 	IPv4_TimeOutCleanIpSession();
			VOID 	IPv4_DnsTimeOutCleanSession();
			VOID 	IPv4_DnsDBClean();
			VOID	emptyDnsDataBaseMap();
			VOID	eraseDnsDDBMap(std::map<std::string, dnsUrl> &dnsMap);
//			VOID 	IPv4_IpSessionCount();
//			VOID 	IPv4_DnsSessionCount();
			VOID 	IPv4_DnsDumpLkuInfo(int day);
			VOID 	IPv4_DnsLoadLookUp();
			VOID 	IPv6_DnsDumpLkuInfo(int HR);
			VOID 	IPv6_DnsLoadLoopUp();
			VOID	IPv4_DnsLookUpCount();
			VOID 	IPv4_DnsDBCount();
			VOID	logStunSysLogUserDnsMapSize();
			VOID	TimeOutCleanSysLog(int hour);
			int 	cleanDnsDBMap(int epochSec, std::map<std::string, dnsUrl> &dnsDBMap);
};

#endif /* PLUGINS_TCP_SRC_IPSMINTERFACE_H_ */
