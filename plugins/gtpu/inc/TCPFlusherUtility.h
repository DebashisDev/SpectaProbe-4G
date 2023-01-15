/*
 * TCPFlusherUtility.h
 *
 *  Created on: Dec 21, 2016
 *      Author: Deb
 */

#ifndef PLUGINS_TCP_SRC_TCPFLUSHERUTILITY_H_
#define PLUGINS_TCP_SRC_TCPFLUSHERUTILITY_H_

#include <unistd.h>

#include "IPGlobal.h"
#include "TCPUDPGlobal.h"
#include "DnsData.h"
#include "ProbeUtility.h"
#include "GTPGlobal.h"

#define IPV6_PREFIX_LAN		19

using namespace std;

class TCPFlusherUtility : public DnsData {
	private:

			typedef struct _GTPInfo
			{
				char 		imsi[IMSI_LEN];
				char 		imei[IMEI_LEN];
				char 		msisdn[MSISDN_LEN];
				uint16_t	rat;
				uint16_t	mcc;
				uint16_t	mnc;
				uint16_t	lac;
			}GTPInfo;

			VOID 			getGtpData(ipSession *pIpSession, GTPInfo *gtpInfo);
			GTPSession* 	S11_GlobalLookup(const uint32_t tunnelId);

			VOID 			createTCPXdr(ipSession *pIpSession, char *xdr, string upVol, string dnVol);
			VOID 			createUDPXdr(ipSession *pIpSession, char *xdr, string upVol, string dnVol);
			VOID			getVolPerSec(ipSession *pIpSession, char *dnVolPerSec, char *upVolPerSec);

			VOID 			lockDnsMap();
			VOID 			unLockDnsMap();

			VOID 			lockS11Map();
			VOID 			unLockS11Map();

			VOID 			formateIPv6(char *buffer);

			uint32_t		vpsTimeKeys[10000];
			BOOL 			someChecks(ipSession *pIpSession);
			VOID			swap3(uint128_t *a, uint128_t *b, uint128_t *c);
			VOID			swap4(uint128_t *a, uint128_t *b, uint128_t *c,  uint128_t *d);

	public:
			TCPFlusherUtility(int instanceId);
			~TCPFlusherUtility();

			VOID 		buildIPXdr(ipSession *pIpSession, char *csvXDR);
			VOID 		getDnsData(ipSession *pIpSession);
			VOID 		buildDnsCsvBuffer(dnsSession *pDnsSession, char *csvXDR);
			VOID		getGtpDnsData(dnsSession *pDnsSession, GTPInfo *gtpInfo);
			static VOID	openDNSXdrFile(string prefix, int currentMin, int currentHour, int currentDay, int currentMonth, int currentYear);
			static VOID closeDNSXdrFile();
};

#endif /* PLUGINS_TCP_SRC_TCPFLUSHERUTILITY_H_ */
