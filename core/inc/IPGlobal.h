/*
 * TCPGlobal.h
 *
 *  Created on: Nov 14, 2015
 *      Author: Debashis
 */

#ifndef INC_IPGLOBAL_H_
#define INC_IPGLOBAL_H_

#include <pthread.h>
#include <fstream>
#include <iostream>
#include <string.h>
#include <map>
#include <unordered_map>
#include <vector>
#include <list>
#include <queue>
#include <array>
#include <bitset>

#include "SpectaTypedef.h"
#include "GConfig.h"

using namespace std;

#define	AIRTEL			1
#define SPECTRANET		2
#define	LINK3			3
#define BSNL			4
#define INDOSATIM2		5
#define BT				6
#define SUBISU			7
#define TATASKYBB		8

#define S1MME_INTERFACE	1
#define S11_INTERFACE	10
#define S5S8_INTERFACE	7
#define S1U_INTERFACE	11

#define UDP_HDR_LEN		8
#define PPPoE_HDR_LEN	6

#define ETH_IP        	0x0800          /* Internet Protocol packet     */
#define ETH_8021Q     	0x8100          /* 802.1Q VLAN Extended Header  */
#define ETH_IPV6    	0x86DD          /* IPv6 over bluebook           */
#define ETH_MPLS_UC   	0x8847          /* MPLS Unicast traffic         */
#define ETH_PPP_SES   	0x8864          /* PPPoE session messages       */

#define MAX_INTERFACE_SUPPORT				8
#define MAX_ROUTER_PER_INTERFACE_SUPPORT 	8

#define MAX_IP_SESSION_MANAGER_SUPPORT 		30
#define MAX_S1MME_SESSION_MANAGER_SUPPORT 	4
#define MAX_S11_SESSION_MANAGER_SUPPORT 	4
#define MAX_S5S8_SESSION_MANAGER_SUPPORT 	4

#define MAX_OPERATOR				15
#define MAX_FLUSHER_SUPPORT			4

#define XDR_MAX_LEN					32000
#define TDR_MAX_LEN					10000
#define XDR_RECORDS_BATCH_SIZE		1000
#define VPS_MAX_LEN					14000
#define VPS_SINGLE_ELEMENT_SIZE		30
#define MAX_CLEAN_COUNT				100000


#define ZMQ_FLUSHER_REPOSITORY_LIMIT	500000
#define TRACE_QUEUE_LIMIT				1000

#define SESSION_ID_LEN  	40		//sip_sp_dip_dp_appid
#define IMSI_LEN			20
#define MSISDN_LEN			16
#define IMEI_LEN			20
#define APN_LEN		 		50
#define URL_LEN		 		100
#define CONTENT_TYPE_LEN	20
#define HTTP_AGENT_LEN		200
#define DESC_LEN			100
#define RANAP_ID_LEN		5

#define DNS_MAX_IPS			10

#define RANAP_SESSION	1
#define GMM_SESSION		2
#define MME_SESSION		3
#define SCCP_SESSION	4

#define FLUSH_TYPE_NAS_NORMAL		10
#define FLUSH_TYPE_NAS_CLEAN		11
#define FLUSH_TYPE_NAS_SCCP_END		12

#define FLUSH_TYPE_RANAP_NORMAL		20
#define FLUSH_TYPE_RANAP_CLEAN		21
#define FLUSH_TYPE_RANAP_SCCP_END	22

#define FLUSH_TYPE_SCCP_NORMAL		30
#define FLUSH_TYPE_SCCP_CLEAN		31

#define MAX_VI_SUPPORT	10

#define IPV4_ADDRLEN		16
#define MAC_ADDR_LEN		18
#define IP_ADDR_LEN 		46
#define SESSION_KEY_LEN		100

#define MAX_ADDR_LENGTH  40
#define MAX_IMSI_LEN 17
#define MAX_APN_LENGTH 100

#define XDR_ID_IP_SESSION 			10
#define XDR_ID_IP_BW 				11
#define XDR_ID_IP_DNS_SESSION		12
#define XDR_PING					99

#define XDR_ID_GTPC_SESSION 		20
#define XDR_ID_GTPC_SESSION_CNT		21

#define XDR_ID_RADIUS_SESSION 		30

#define FLUSH_TYPE_CR_REQ_NO_TEID 	10
#define FLUSH_TYPE_CR_REQ_RESREQ 	11
#define FLUSH_TYPE_CR_REQ_DUP 		12
#define FLUSH_TYPE_CR_RES_NO_TEID 	13
#define FLUSH_TYPE_CR_RES_REQRES 	14
#define FLUSH_TYPE_CR_RES_DUP 		15
#define FLUSH_TYPE_CR_RES_NO_REQ	16

#define FLUSH_TYPE_UP_REQ_NO_TEID  	20
#define FLUSH_TYPE_UP_REQ_RESREQ 	21
#define FLUSH_TYPE_UP_REQ_DUP 		22
#define FLUSH_TYPE_UP_RES_NO_TEID 	23
#define FLUSH_TYPE_UP_RES_REQRES 	24
#define FLUSH_TYPE_UP_RES_DUP 		25
#define FLUSH_TYPE_UP_RES_NO_REQ	26

#define FLUSH_TYPE_DL_REQ_NO_TEID 	30
#define FLUSH_TYPE_DL_REQ_RESREQ 	31
#define FLUSH_TYPE_DL_REQ_DUP 		32
#define FLUSH_TYPE_DL_RES_NO_TEID 	33
#define FLUSH_TYPE_DL_RES_REQRES 	34
#define FLUSH_TYPE_DL_RES_DUP 		35
#define FLUSH_TYPE_DL_RES_NO_REQ 	36

#define FLUSH_TYPE_CLEANUP 			40

#define SESSION_POOL_ARRAY_ELEMENTS		100
#define SESSION_POOL_ARRAY_SIZE			1000

#define PACKET_NO							200000

#define IP_SESSION_POOL_ARRAY_ELEMENTS		100
#define IP_SESSION_POOL_ARRAY_SIZE			2000

#define DNS_SESSION_POOL_ARRAY_ELEMENTS		100
#define DNS_SESSION_POOL_ARRAY_SIZE			1000

#define RADIUS_USER_NAME_LEN	40
#define RADIUS_USER_ID_LEN		50
#define RADIUS_USER_OLT_LEN		100
#define RADIUS_USER_POLICY_LEN	50
#define RADIUS_USER_PLAN_LEN	50

#define THREAD_SLEEP_DUR_MICRO_SEC 100000		/* 100 ms */

#define PKT_WRITE_TIME_INDEX(epochsec,ti) ( ((epochsec % ti) + 1) >= ti ? 0 : ((epochsec % ti) + 1) )
#define PKT_READ_TIME_INDEX(epochsec,ti) ( epochsec % ti )
#define PKT_READ_NEXT_TIME_INDEX(idx,ti) ( (idx+1) >= ti ? 0 : (idx+1) )

#define NEXT_TIME_INDEX(idx) ( (idx+1) >= 10 ? 0 : (idx+1) )

namespace GContainer
{ extern GConfig *config; }

namespace ipProtocol{
	extern std::unordered_map<uint8_t, std::string> ipProtocolMap;
}

enum dnsResponse
{
	QUERY 		= 0,
	RESPONSE 	= 1,
	STATUS 		= 2,
	UNASSIGNED 	= 3,
	NOTIFY 		= 4,
	UPDATE 		= 5,
	SUCCESS		= 6
};

typedef enum
{
	PACKET_IPPROTO_IP 		= 0,	/** Dummy protocol for TCP		*/
	PACKET_IPPROTO_HOPOPTS 	= 0,	/** IPv6 Hop-by-Hop options		*/
	PACKET_IPPROTO_ICMP 	= 1,	/** Internet Control Message Protocol */
	PACKET_IPPROTO_IGMP 	= 2,	/** Internet Group management Protocol */
	PACKET_IPPROTO_IPIP 	= 4,	/** IPIP tunnels (older KA9Q tunnels use 94) */
	PACKET_IPPROTO_TCP		= 6,	/** Transmission Control Protocol	*/
	PACLET_IPPROTO_EGP 		= 8,	/** Exterior Gateway Protocol */
	PACKET_IPPROTO_PUP 		= 12,	/** PUP Protocol */
	PACKET_IPPROTO_UDP 		= 17,	/** User Datagram Protocol		*/
	PACKET_IPPROTO_DNS 		= 18,	/** DNS		*/
	PACKET_IPPROTO_IDP 		= 22,	/** XNS IDP protocol */
	PACKET_IPPROTO_TP 		= 29,	/** SO Transport Protocol Class 4. */
	PACKET_IPPROTO_DCCP 	= 33,	/** Datagram Congestion Control Protocol. */
	PACKET_IPPROTO_IPV6 	= 41,	/** IPv6 header */
	PACKET_IPPROTO_ROUTING 	= 43,	/** IPv6 Routing header */
	PACKET_IPPROTO_FRAGMENT = 44,	/** IPv6 fragmentation header */
	PACKET_IPPROTO_RSVP 	= 46,	/** Reservation Protocol */
	PACKET_IPPROTO_GRE 		= 47,	/** General Routing Encapsulation */
	PACKET_IPPROTO_GTPU 	= 48,	/** GTPU Protocol		*/
	PACKET_IPPROTO_GTPC 	= 49,	/** GTPC Protocol		*/
	PACKET_IPPROTO_ESP 		= 50,	/** encapsulating security Payload */
	PACKET_IPPROTO_AH 		= 51,	/** Authentication header */
	PACKET_IPPROTO_GX 		= 52,	/** GTPU Protocol		*/
	PACKET_IPPROTO_RADIUS 	= 53,	/** RADIUS Protocol		*/
	PACKET_IPPROTO_ICMPV6 	= 58,	/** ICMPV6 */
	PACKET_IPPROTO_NONE 	= 59,	/** IPv6 no next header */
	PACKET_IPPROTO_DSTOPTS 	= 60,	/** IPv6 destination options */
	PACKET_IPPROTO_MTP 		= 92,	/** Multicast Transport Protocol */
	PACKET_IPPROTO_ENCAP 	= 98,	/** Encapsulation Header */
	PACKET_IPPROTO_PIM 		= 103,	/** Protocol Independent Multicast */
	PACKET_IPPROTO_COMP 	= 108,	/** Compression Header Protocol */
	PACKET_IPPROTO_SCTP 	= 132,	/** SCTP Protocol		*/
	PACKET_IPPROTO_UDPLITE 	= 136,	/** UDP-Lite protocol */
	PACKET_IPPROTO_RAW 		= 255	/** Raw IP Packets */
}IPProtocolTypes;

typedef struct _xdrStore
{
	int idx;
	char xdr[XDR_MAX_LEN];

	_xdrStore()
	{
		reset();
	}
	_xdrStore(const _xdrStore& obj)
	{
		this->idx = obj.idx;
		strcpy(this->xdr, obj.xdr);
	}
	void set(const _xdrStore *obj)
	{
		this->idx = obj->idx;
		strcpy(this->xdr, obj->xdr);
	}
	void copy(const _xdrStore* obj)
	{
		this->idx = obj->idx;
		strcpy(this->xdr, obj->xdr);
	}
	void operator=(const _xdrStore& obj)
	{
		this->idx = obj.idx;
		strcpy(this->xdr, obj.xdr);
	}
	void reset()
	{
		this->idx = 0;
		strcpy(this->xdr, "");
	}
}xdrStore;

inline string getSessionId(string sessionKey, ULONG frEpochTimeNanoSec)
	{
		char buffer[40];
		sprintf(buffer, "%s_%ld", sessionKey.c_str(), frEpochTimeNanoSec);
		return string(buffer);
	}

typedef enum{
	HTTP 		= 2,
	BW 			= 3,
	IUPS		= 21,
	SCCP		= 22,
	NONTCPUDP	= 20
}protocolId;

typedef enum {
	DNS_PORT 		= 53,
	HTTP_PORT 		= 80,
	SYSLOG_PORT		= 514,
	HTTPS_PORT 		= 443,
	GTPU_PORT 		= 2152,
	GTPC_PORT 		= 2123,
	GTPC_PORT1 		= 3386,
	HTTP_PORT1 		= 8080,
	GX_PORT			= 3868,
	RADIUS_AUTH		= 1812,
	RADIUS_ACCO 	= 1813,
	RADIUS_AUTH1	= 31812,
	RADIUS_ACCO1 	= 31813
};

typedef struct {
  int startIp;
  int mask;
}_ipRange;

namespace ipRange{
	extern int totalIps;
	extern _ipRange ipRange[100];
}

typedef struct _RawPkt
{
	uint16_t	len;
	uint32_t 	tv_sec;
	uint32_t 	tv_nsec;
	BYTE		pkt;
	uint64_t 	pkt_no;

	_RawPkt(int rawPckSize) {
		reset();
		pkt = (BYTE) malloc(rawPckSize);
	}

	_RawPkt(const _RawPkt& rpkt) {
		len 	= rpkt.len;
		tv_sec 	= rpkt.tv_sec;
		tv_nsec = rpkt.tv_nsec;
		pkt 	= rpkt.pkt;
		pkt_no	= rpkt.pkt_no;
	}

	void copy(const _RawPkt* rpkt) {
		len 	= rpkt->len;
		tv_sec 	= rpkt->tv_sec;
		tv_nsec = rpkt->tv_nsec;
		pkt 	= rpkt->pkt;
		pkt_no	= rpkt->pkt_no;
	}

	void operator=(const _RawPkt& rpkt) {
		len 	= rpkt.len;
		tv_sec 	= rpkt.tv_sec;
		tv_nsec = rpkt.tv_nsec;
		pkt 	= rpkt.pkt;
		pkt_no	= rpkt.pkt_no;
	}

	void reset() {
		len = 0;
		tv_sec = 0;
		tv_nsec = 0;
		pkt_no = 0;
	}

}RawPkt;

typedef struct _Sctp
{
	/* --- SCTP --- */
	uint16_t 	sctpLen;
	uint16_t 	direction;
	uint16_t 	frSize;

	uint32_t	sourceIp;
	uint16_t	sourcePort;
	uint32_t	destIp;
	uint16_t	destPort;
	uint16_t	s1ap_pduType;
	uint16_t  	s1ap_procCode;
	uint16_t	s1ap_pdnAddrType;
	int16_t 	s1ap_handoverType;
	int16_t		s1ap_causeType;
	int16_t		s1ap_causeId;
	uint16_t	s1ap_rejectCause;
	uint16_t	s1ap_failureCause;
	uint16_t	s1ap_estCause;
	uint32_t	nas_EPSMobilityMgrMsgType;
	BOOL		nas_MMM_Present;
	uint32_t	nas_ESMSessionMgrMsgType;
	BOOL		nas_SMM_Present;
	uint32_t	nas_ESMMsgContainerMsgType;
	BOOL		nas_ESMMsgContainerMsg_Present;
	uint32_t	s1ap_eNodeBId;
	uint32_t	s1ap_mmeId;
	uint32_t	s1ap_rabId;
	uint128_t	s1ap_mbrDL;
	uint128_t	s1ap_mbrUL;
	uint16_t	s1ap_apnMbrUp;
	uint16_t	s1ap_apnMbrDown;
	uint16_t	s1ap_qCI;
	bool		s1ap_imsiPresent;
	bool		s1ap_imeiPresent;
	bool		s1ap_m_tmsi_Present;
	char		s1ap_m_tmsi[10];
	char		s1ap_imsi[IMSI_LEN];
	char		s1ap_imei[IMSI_LEN];
	char		s1ap_pdnAddr[IPV4_ADDRLEN];		/* IP Address Allocated to UE */
	char		s1ap_pLMNIdentity[10];
	char		s1ap_tac[10];
	char		s1ap_lac[10];
	char		s1ap_gTP_TEID[10];
	char		s1ap_cellId[20];
	char		s1ap_apn[MAX_APN_LENGTH];
	char		s1ap_targetCellId[20];
	char		s1ap_targetpLMNIdentity[10];
	char		s1ap_lastVisitedCellId[20];
	char		s1ap_lastVisitedpLMNIdentity[10];

    _Sctp()
    { reset(); }

    void reset()
    {
    	sctp_reset();
    	s1ap_reset();
    }

    void sctp_reset()
    {
		/* --- SCTP --- */
		sctpLen = 0;
		direction = 0;
		frSize = 0;
    }

    void s1ap_reset()
    {
    	sourceIp = 0;
    	sourcePort = 0;
    	destIp = 0;
    	destPort = 0;
    	s1ap_pduType = 0;
		s1ap_procCode = 0;
		s1ap_pdnAddrType = 0;
		s1ap_handoverType = -1;
		s1ap_causeType = -1;
		s1ap_causeId = -1;
		s1ap_rejectCause = 0;
		s1ap_failureCause = 0;
		s1ap_estCause = 0;
		nas_EPSMobilityMgrMsgType = 0;
		nas_MMM_Present = false;
		nas_ESMSessionMgrMsgType = 0;
		nas_SMM_Present = false;
		nas_ESMMsgContainerMsgType = 0;
		nas_ESMMsgContainerMsg_Present = false;
		s1ap_eNodeBId = 0;
		s1ap_mmeId = 0;
		s1ap_rabId = 0;
		s1ap_mbrDL = 0;
		s1ap_mbrUL = 0;
		s1ap_apnMbrUp = 0;
		s1ap_apnMbrDown = 0;
		s1ap_qCI = 0;
		s1ap_imsiPresent = false;
		s1ap_imeiPresent = false;
		s1ap_m_tmsi_Present = false;
		strcpy(s1ap_m_tmsi, "NA");
		strcpy(s1ap_imsi,"NA");
		strcpy(s1ap_imei,"NA");
		strcpy(s1ap_pdnAddr, "NA");
		strcpy(s1ap_pLMNIdentity, "NA");
		strcpy(s1ap_tac, "NA");
		strcpy(s1ap_lac, "NA");
		strcpy(s1ap_gTP_TEID, "NA");
		strcpy(s1ap_cellId, "0");
		strcpy(s1ap_apn, "NA");
		strcpy(s1ap_targetCellId, "NA");
		strcpy(s1ap_targetpLMNIdentity, "NA");
		strcpy(s1ap_lastVisitedCellId, "NA");
		strcpy(s1ap_lastVisitedpLMNIdentity, "NA");

    }

    _Sctp(const _Sctp& mpkt)
    {
		/* --- MTP3 --- */
		sctpLen = mpkt.sctpLen;
		direction = mpkt.direction;
		frSize = mpkt.frSize;

		sourceIp = mpkt.sourceIp;
		sourcePort = mpkt.sourcePort;
		destIp = mpkt.destIp;
		destPort = mpkt.destPort;
		s1ap_pduType = mpkt.s1ap_pduType;
		s1ap_procCode = mpkt.s1ap_procCode;
		s1ap_pdnAddrType = mpkt.s1ap_pdnAddrType;
		s1ap_handoverType = mpkt.s1ap_handoverType;
		s1ap_causeType = mpkt.s1ap_causeType;
		s1ap_causeId = mpkt.s1ap_causeId;
		s1ap_rejectCause = mpkt.s1ap_rejectCause;
		s1ap_failureCause = mpkt.s1ap_failureCause;
		s1ap_estCause = mpkt.s1ap_estCause;
		nas_EPSMobilityMgrMsgType = mpkt.nas_EPSMobilityMgrMsgType;
		nas_MMM_Present = mpkt.nas_MMM_Present;
		nas_ESMSessionMgrMsgType = mpkt.nas_ESMSessionMgrMsgType;
		nas_SMM_Present = mpkt.nas_SMM_Present;
		nas_ESMMsgContainerMsgType = mpkt.nas_ESMMsgContainerMsgType;
		nas_ESMMsgContainerMsg_Present = mpkt.nas_ESMMsgContainerMsg_Present;
		s1ap_eNodeBId = mpkt.s1ap_eNodeBId;
		s1ap_mmeId = mpkt.s1ap_mmeId;
		s1ap_rabId = mpkt.s1ap_rabId;
		s1ap_mbrDL = mpkt.s1ap_mbrDL;
		s1ap_mbrUL = mpkt.s1ap_mbrUL;
		s1ap_apnMbrUp = mpkt.s1ap_apnMbrUp;
		s1ap_apnMbrDown = mpkt.s1ap_apnMbrDown;
		s1ap_qCI = mpkt.s1ap_qCI;
		s1ap_imsiPresent = mpkt.s1ap_imsiPresent;
		s1ap_imeiPresent = mpkt.s1ap_imeiPresent;
		s1ap_m_tmsi_Present = mpkt.s1ap_m_tmsi_Present;
		strcpy(s1ap_m_tmsi, mpkt.s1ap_m_tmsi);
		strcpy(s1ap_imsi, mpkt.s1ap_imsi);
		strcpy(s1ap_imei, mpkt.s1ap_imei);
		strcpy(s1ap_pdnAddr, mpkt.s1ap_pdnAddr);
		strcpy(s1ap_pLMNIdentity, mpkt.s1ap_pLMNIdentity);
		strcpy(s1ap_tac, mpkt.s1ap_tac);
		strcpy(s1ap_lac, mpkt.s1ap_lac);
		strcpy(s1ap_gTP_TEID, mpkt.s1ap_gTP_TEID);
		strcpy(s1ap_cellId, mpkt.s1ap_cellId);
		strcpy(s1ap_apn, mpkt.s1ap_apn);
		strcpy(s1ap_targetCellId, mpkt.s1ap_targetCellId);
		strcpy(s1ap_targetpLMNIdentity, mpkt.s1ap_targetpLMNIdentity);
		strcpy(s1ap_lastVisitedCellId, mpkt.s1ap_lastVisitedCellId);
		strcpy(s1ap_lastVisitedpLMNIdentity, mpkt.s1ap_lastVisitedpLMNIdentity);
    }

    void copy(const _Sctp* mpkt)
    {
		/* --- MTP3 --- */
		sctpLen = mpkt->sctpLen;
		direction = mpkt->direction;
		frSize = mpkt->frSize;

		sourceIp = mpkt->sourceIp;
		sourcePort = mpkt->sourcePort;
		destIp = mpkt->destIp;
		destPort = mpkt->destPort;
		s1ap_pduType = mpkt->s1ap_pduType;
		s1ap_procCode = mpkt->s1ap_procCode;
		s1ap_pdnAddrType = mpkt->s1ap_pdnAddrType;
		s1ap_handoverType = mpkt->s1ap_handoverType;
		s1ap_causeType = mpkt->s1ap_causeType;
		s1ap_causeId = mpkt->s1ap_causeId;
		s1ap_rejectCause = mpkt->s1ap_rejectCause;
		s1ap_failureCause = mpkt->s1ap_failureCause;
		s1ap_estCause = mpkt->s1ap_estCause;
		nas_EPSMobilityMgrMsgType = mpkt->nas_EPSMobilityMgrMsgType;
		nas_MMM_Present = mpkt->nas_MMM_Present;
		nas_ESMSessionMgrMsgType = mpkt->nas_ESMSessionMgrMsgType;
		nas_SMM_Present = mpkt->nas_SMM_Present;
		nas_ESMMsgContainerMsgType = mpkt->nas_ESMMsgContainerMsgType;
		nas_ESMMsgContainerMsg_Present = mpkt->nas_ESMMsgContainerMsg_Present;
		s1ap_eNodeBId = mpkt->s1ap_eNodeBId;
		s1ap_mmeId = mpkt->s1ap_mmeId;
		s1ap_rabId = mpkt->s1ap_rabId;
		s1ap_mbrDL = mpkt->s1ap_mbrDL;
		s1ap_mbrUL = mpkt->s1ap_mbrUL;
		s1ap_apnMbrUp = mpkt->s1ap_apnMbrUp;
		s1ap_apnMbrDown = mpkt->s1ap_apnMbrDown;
		s1ap_qCI = mpkt->s1ap_qCI;
		s1ap_imsiPresent = mpkt->s1ap_imsiPresent;
		s1ap_imeiPresent = mpkt->s1ap_imeiPresent;
		s1ap_m_tmsi_Present = mpkt->s1ap_m_tmsi_Present;
		strcpy(s1ap_m_tmsi, mpkt->s1ap_m_tmsi);
		strcpy(s1ap_imsi, mpkt->s1ap_imsi);
		strcpy(s1ap_imei, mpkt->s1ap_imei);
		strcpy(s1ap_pdnAddr, mpkt->s1ap_pdnAddr);
		strcpy(s1ap_pLMNIdentity, mpkt->s1ap_pLMNIdentity);
		strcpy(s1ap_tac, mpkt->s1ap_tac);
		strcpy(s1ap_lac, mpkt->s1ap_lac);
		strcpy(s1ap_gTP_TEID, mpkt->s1ap_gTP_TEID);
		strcpy(s1ap_cellId, mpkt->s1ap_cellId);
		strcpy(s1ap_apn, mpkt->s1ap_apn);
		strcpy(s1ap_targetCellId, mpkt->s1ap_targetCellId);
		strcpy(s1ap_targetpLMNIdentity, mpkt->s1ap_targetpLMNIdentity);
		strcpy(s1ap_lastVisitedCellId, mpkt->s1ap_lastVisitedCellId);
		strcpy(s1ap_lastVisitedpLMNIdentity, mpkt->s1ap_lastVisitedpLMNIdentity);
    }

    void operator=(const _Sctp& mpkt)
    {
		/* --- MTP3 --- */
		sctpLen = mpkt.sctpLen;
		direction = mpkt.direction;
		frSize = mpkt.frSize;
		sourceIp = mpkt.sourceIp;
		sourcePort = mpkt.sourcePort;
		destIp = mpkt.destIp;
		destPort = mpkt.destPort;
		s1ap_pduType = mpkt.s1ap_pduType;
		s1ap_procCode = mpkt.s1ap_procCode;
		s1ap_pdnAddrType = mpkt.s1ap_pdnAddrType;
		s1ap_handoverType = mpkt.s1ap_handoverType;
		s1ap_causeType = mpkt.s1ap_causeType;
		s1ap_causeId = mpkt.s1ap_causeId;
		s1ap_rejectCause = mpkt.s1ap_rejectCause;
		s1ap_failureCause = mpkt.s1ap_failureCause;
		s1ap_estCause = mpkt.s1ap_estCause;
		nas_EPSMobilityMgrMsgType = mpkt.nas_EPSMobilityMgrMsgType;
		nas_MMM_Present = mpkt.nas_MMM_Present;
		nas_ESMSessionMgrMsgType = mpkt.nas_ESMSessionMgrMsgType;
		nas_SMM_Present = mpkt.nas_SMM_Present;
		nas_ESMMsgContainerMsgType = mpkt.nas_ESMMsgContainerMsgType;
		nas_ESMMsgContainerMsg_Present = mpkt.nas_ESMMsgContainerMsg_Present;
		s1ap_eNodeBId = mpkt.s1ap_eNodeBId;
		s1ap_mmeId = mpkt.s1ap_mmeId;
		s1ap_rabId = mpkt.s1ap_rabId;
		s1ap_mbrDL = mpkt.s1ap_mbrDL;
		s1ap_mbrUL = mpkt.s1ap_mbrUL;
		s1ap_apnMbrUp = mpkt.s1ap_apnMbrUp;
		s1ap_apnMbrDown = mpkt.s1ap_apnMbrDown;
		s1ap_qCI = mpkt.s1ap_qCI;
		s1ap_imsiPresent = mpkt.s1ap_imsiPresent;
		s1ap_imeiPresent = mpkt.s1ap_imeiPresent;
		s1ap_m_tmsi_Present = mpkt.s1ap_m_tmsi_Present;
		strcpy(s1ap_m_tmsi, mpkt.s1ap_m_tmsi);
		strcpy(s1ap_imsi, mpkt.s1ap_imsi);
		strcpy(s1ap_imei, mpkt.s1ap_imei);
		strcpy(s1ap_pdnAddr, mpkt.s1ap_pdnAddr);
		strcpy(s1ap_pLMNIdentity, mpkt.s1ap_pLMNIdentity);
		strcpy(s1ap_tac, mpkt.s1ap_tac);
		strcpy(s1ap_lac, mpkt.s1ap_lac);
		strcpy(s1ap_gTP_TEID, mpkt.s1ap_gTP_TEID);
		strcpy(s1ap_cellId, mpkt.s1ap_cellId);
		strcpy(s1ap_apn, mpkt.s1ap_apn);
		strcpy(s1ap_targetCellId, mpkt.s1ap_targetCellId);
		strcpy(s1ap_targetpLMNIdentity, mpkt.s1ap_targetpLMNIdentity);
		strcpy(s1ap_lastVisitedCellId, mpkt.s1ap_lastVisitedCellId);
		strcpy(s1ap_lastVisitedpLMNIdentity, mpkt.s1ap_lastVisitedpLMNIdentity);
    }
}Sctp;

typedef struct _MPacket
{
	/* Frame Data */
	uint16_t	frInterfaceId;
	uint16_t	frRouterId;
	uint16_t	frTimeIndex;
	uint16_t	frSize;
	uint16_t	frByteLen;
	uint32_t	frTimeEpochSec;				//Check size to optimize
	uint64_t    frTimeEpochMilliSec;
	uint64_t	frBufferWriteTimeEpochSec;
	uint128_t	frTimeEpochNanoSec;

	/* Ethernet Data */
	char		ethSourceMACAddr[MAC_ADDR_LEN];
	char		ethDestMACAddr[MAC_ADDR_LEN];
	uint16_t	ethVLanId;

	/* IPV4 Data */
	uint8_t 	ipVer;
	uint16_t	ipIdentification;
	uint32_t 	gtpuTeid;
	uint16_t 	ipTLen;
	uint16_t 	ipHLen;
	uint16_t	ipProtocol;
	uint16_t 	ipAppProtocol;
	uint8_t 	ipTtl;
	uint32_t 	sourceIpAddrLong;
	uint32_t	destIpAddrLong;
	uint16_t	sourcePort;
	uint16_t	destPort;
	uint64_t	Key;
	uint16_t	interfaceType;
	uint16_t	dirUserNetwork;

#ifdef _S1U
	/* L3-Protocol Data TCP/UDP etc */
	uint16_t 	protoTLen;
	uint16_t 	protoHLen;
	uint16_t 	protoSourcePort;
	uint16_t 	protoDestPort;
	uint16_t	protoPayload;

	uint32_t 	tcpSeqNo;
	uint16_t	tcpFlags;
	char		httpAgent[HTTP_AGENT_LEN];

	/* DNS Data */
	uint8_t		dnsQRFlag;
	uint8_t		dnsResponseCode;
	uint32_t	dnsTransactionId;
	uint16_t 	dnsTLen;
	char 		dnsName[URL_LEN];
	char 		dnsIpAddress[IP_ADDR_LEN];
#endif

#ifdef _S1MME
	std::map<int, Sctp> SctpData;
#endif

#ifdef _S11
	/* GTPcV2 data */
	uint8_t 	gtpcRAT;
	uint8_t		gtpcVersion;
	uint16_t	gtpcMsgType;
	uint8_t 	gtpcCauseCode;

	uint16_t 	gtpcMsgLen;
	uint32_t 	gtpc_PktTeid;

	uint32_t	gtpcMbrupl;
	uint32_t	gtpcMbrdnl;

	char 		IMSI[IMSI_LEN];
	char 		IMEI[IMEI_LEN];
	char 		MSISDN[MSISDN_LEN];
	char 		gtpcAPN[APN_LEN];

	uint32_t	TAC;
	uint32_t	eNodeB;
	uint32_t	cellId;
	uint32_t 	gtpcV2PktSeqNo;
	uint32_t 	counter_val;

	uint32_t	MME_ctl_teid;
	uint32_t	SGW_ctl_teid;
	uint32_t	PGW_ctl_teid;

	uint32_t	PGW_s1u_teid;
	uint32_t	eNodeB_s1u_teid;
	uint32_t	SGW_s1u_teid;

	char		STN_SR[100];
	char		pdnAddrAllocation[40];
	char		servingNetwork[25];
	char		pdnType[10];
	char 		PGWAddress[IP_ADDR_LEN];
	char 		MMEAddress[IP_ADDR_LEN];
	char 		SGWAddress[IP_ADDR_LEN];
	char 		MCCMNC[50];
#endif

	_MPacket()
	{ reset(); }

	_MPacket(const _MPacket& mpkt)
	{
		/* Frame Data */
		frInterfaceId 				= mpkt.frInterfaceId;
		frRouterId 					= mpkt.frRouterId;
		frTimeIndex 				= mpkt.frTimeIndex;
		frTimeEpochSec 				= mpkt.frTimeEpochSec;
		frTimeEpochNanoSec 			= mpkt.frTimeEpochNanoSec;
		frTimeEpochMilliSec 		= mpkt.frTimeEpochMilliSec;
		frSize 						= mpkt.frSize;
		frBufferWriteTimeEpochSec 	= mpkt.frBufferWriteTimeEpochSec;
		frByteLen					= mpkt.frByteLen;

		/* Ethernet Data */
		strcpy(ethSourceMACAddr, mpkt.ethSourceMACAddr);
		strcpy(ethDestMACAddr, mpkt.ethDestMACAddr);
		ethVLanId 					= mpkt.ethVLanId;

		/* IPV4 Data */
		ipVer						= mpkt.ipVer;
		ipIdentification			= mpkt.ipIdentification;
		gtpuTeid					= mpkt.gtpuTeid;
		ipTLen 						= mpkt.ipTLen;
		ipHLen 						= mpkt.ipHLen;
		ipProtocol					= mpkt.ipProtocol;
		ipAppProtocol 				= mpkt.ipAppProtocol;
		ipTtl 						= mpkt.ipTtl;
		sourceIpAddrLong 			= mpkt.sourceIpAddrLong;
		destIpAddrLong 				= mpkt.destIpAddrLong;
		sourcePort					= mpkt.sourcePort;
		destPort					= mpkt.destPort;
		Key 						= mpkt.Key;
		interfaceType 				= mpkt.interfaceType;
		dirUserNetwork 				= mpkt.dirUserNetwork;

#ifdef _S1U
		/* L3-Protocol Data TCP/UDP etc*/
		protoTLen		= mpkt.protoTLen;
		protoHLen 		= mpkt.protoHLen;
		protoSourcePort = mpkt.protoSourcePort;
		protoDestPort 	= mpkt.protoDestPort;
		protoPayload 	= mpkt.protoPayload;
		tcpSeqNo 		= mpkt.tcpSeqNo;
		tcpFlags 		= mpkt.tcpFlags;
		strcpy(httpAgent, mpkt.httpAgent);

		/* DNS Data */
		dnsResponseCode = mpkt.dnsResponseCode;
		dnsQRFlag		= mpkt.dnsQRFlag;
		dnsTransactionId= mpkt.dnsTransactionId;
		dnsTLen			= mpkt.dnsTLen;
		strcpy(dnsName, mpkt.dnsName);
		strcpy(dnsIpAddress, mpkt.dnsIpAddress);
#endif

#ifdef _S1MME
		SctpData = mpkt.SctpData;
#endif

#ifdef _S11
		gtpcRAT = mpkt.gtpcRAT;
		gtpcVersion = mpkt.gtpcVersion;
		gtpcMsgType = mpkt.gtpcMsgType;
		gtpcCauseCode = mpkt.gtpcCauseCode;
		gtpcMsgLen = mpkt.gtpcMsgLen;
		gtpc_PktTeid = mpkt.gtpc_PktTeid;

		gtpcMbrupl = mpkt.gtpcMbrupl;
		gtpcMbrdnl = mpkt.gtpcMbrdnl;

		strcpy(IMSI, mpkt.IMSI);
		strcpy(IMEI, mpkt.IMEI);
		strcpy(MSISDN, mpkt.MSISDN);
		strcpy(gtpcAPN, mpkt.gtpcAPN);

		TAC = mpkt.TAC;
		eNodeB = mpkt.eNodeB;
		cellId = mpkt.cellId;
		gtpcV2PktSeqNo = mpkt.gtpcV2PktSeqNo;
		counter_val = mpkt.counter_val;

		MME_ctl_teid	= mpkt.MME_ctl_teid;
		SGW_ctl_teid	= mpkt.SGW_ctl_teid;
		PGW_ctl_teid	= mpkt.PGW_ctl_teid;

		PGW_s1u_teid = mpkt.PGW_s1u_teid;
		eNodeB_s1u_teid = mpkt.eNodeB_s1u_teid;
		SGW_s1u_teid	= mpkt.SGW_s1u_teid;

		strcpy(STN_SR, mpkt.STN_SR);
		strcpy(pdnAddrAllocation, mpkt.pdnAddrAllocation);
		strcpy(servingNetwork, mpkt.servingNetwork);
		strcpy(pdnType, mpkt.pdnType);
		strcpy(PGWAddress, mpkt.PGWAddress);
		strcpy(MMEAddress, mpkt.MMEAddress);
		strcpy(SGWAddress, mpkt.SGWAddress);
		strcpy(MCCMNC, mpkt.MCCMNC);
#endif
	}

	void copy(const _MPacket* mpkt)
	{
		/* Frame Data */
		frInterfaceId 				= mpkt->frInterfaceId;
		frRouterId 					= mpkt->frRouterId;
		frTimeIndex 				= mpkt->frTimeIndex;
		frTimeEpochSec 				= mpkt->frTimeEpochSec;
		frTimeEpochNanoSec 			= mpkt->frTimeEpochNanoSec;
		frTimeEpochMilliSec 		= mpkt->frTimeEpochMilliSec;
		frSize 						= mpkt->frSize;
		frBufferWriteTimeEpochSec 	= mpkt->frBufferWriteTimeEpochSec;
		frByteLen					= mpkt->frByteLen;

		/* Ethernet Data */
		strcpy(ethSourceMACAddr, mpkt->ethSourceMACAddr);
		strcpy(ethDestMACAddr, mpkt->ethDestMACAddr);
		ethVLanId 					= mpkt->ethVLanId;
		dirUserNetwork 				= mpkt->dirUserNetwork;
		/* IPV4 Data */
		ipVer						= mpkt->ipVer;
		ipIdentification			= mpkt->ipIdentification;
		gtpuTeid					= mpkt->gtpuTeid;
		ipTLen 						= mpkt->ipTLen;
		ipHLen 						= mpkt->ipHLen;
		ipProtocol					= mpkt->ipProtocol;
		ipAppProtocol 				= mpkt->ipAppProtocol;
		ipTtl 						= mpkt->ipTtl;
		sourceIpAddrLong 			= mpkt->sourceIpAddrLong;
		destIpAddrLong 				= mpkt->destIpAddrLong;
		sourcePort					= mpkt->sourcePort;
		destPort					= mpkt->destPort;
		Key 						= mpkt->Key;
		interfaceType 				= mpkt->interfaceType;

#ifdef _S1U
		/* L3-Protocol Data TCP/UDP etc*/
		protoTLen		= mpkt->protoTLen;
		protoHLen 		= mpkt->protoHLen;
		protoSourcePort = mpkt->protoSourcePort;
		protoDestPort 	= mpkt->protoDestPort;
		protoPayload 	= mpkt->protoPayload;
		tcpSeqNo 		= mpkt->tcpSeqNo;
		tcpFlags 		= mpkt->tcpFlags;
		strcpy(httpAgent, mpkt->httpAgent);

		/* DNS Data */
		dnsQRFlag		= mpkt->dnsQRFlag;
		dnsResponseCode = mpkt->dnsResponseCode;
		dnsTransactionId= mpkt->dnsTransactionId;
		dnsTLen			= mpkt->dnsTLen;
		strcpy(dnsName, mpkt->dnsName);
		strcpy(dnsIpAddress, mpkt->dnsIpAddress);
#endif

#ifdef _S1MME
		SctpData 					= mpkt->SctpData;
#endif

#ifdef _S11
		gtpcRAT = mpkt->gtpcRAT;
		gtpcVersion = mpkt->gtpcVersion;
		gtpcMsgType = mpkt->gtpcMsgType;
		gtpcCauseCode = mpkt->gtpcCauseCode;
		gtpcMsgLen = mpkt->gtpcMsgLen;
		gtpc_PktTeid = mpkt->gtpc_PktTeid;

		gtpcMbrupl = mpkt->gtpcMbrupl;
		gtpcMbrdnl = mpkt->gtpcMbrdnl;

		strcpy(IMSI, mpkt->IMSI);
		strcpy(IMEI, mpkt->IMEI);
		strcpy(MSISDN, mpkt->MSISDN);
		strcpy(gtpcAPN, mpkt->gtpcAPN);

		TAC = mpkt->TAC;
		eNodeB = mpkt->eNodeB;
		cellId = mpkt->cellId;
		gtpcV2PktSeqNo = mpkt->gtpcV2PktSeqNo;
		counter_val = mpkt->counter_val;

		MME_ctl_teid	= mpkt->MME_ctl_teid;
		SGW_ctl_teid	= mpkt->SGW_ctl_teid;
		PGW_ctl_teid	= mpkt->PGW_ctl_teid;

		PGW_s1u_teid = mpkt->PGW_s1u_teid;
		eNodeB_s1u_teid = mpkt->eNodeB_s1u_teid;
		SGW_s1u_teid	= mpkt->SGW_s1u_teid;

		strcpy(STN_SR, mpkt->STN_SR);
		strcpy(pdnAddrAllocation, mpkt->pdnAddrAllocation);
		strcpy(servingNetwork, mpkt->servingNetwork);
		strcpy(pdnType, mpkt->pdnType);
		strcpy(PGWAddress, mpkt->PGWAddress);
		strcpy(MMEAddress, mpkt->MMEAddress);
		strcpy(SGWAddress, mpkt->SGWAddress);
		strcpy(MCCMNC, mpkt->MCCMNC);
#endif
	}
	void reset()
	{
		/* Frame Data */
		frInterfaceId 				= 0;
		frRouterId 					= 0;
		frTimeIndex 				= 0;
		frTimeEpochSec 				= 0;
		frTimeEpochNanoSec 			= 0;
		frTimeEpochMilliSec 		= 0;
		frSize 						= 0;
		frBufferWriteTimeEpochSec 	= 0;
		frByteLen 					= 0;

		/* Ethernet Data */
		ethSourceMACAddr[0]			= 0;
		ethDestMACAddr[0] 			= 0;
		ethVLanId 					= 0;

		/* IPV4 Data */
		ipVer						= 0;
		ipIdentification			= 0;
		gtpuTeid					= 0;
		ipTLen 						= 0;
		ipHLen 						= 0;
		ipProtocol					= 0;
		ipAppProtocol 				= 0;
		ipTtl 						= 0;
		sourceIpAddrLong 			= 0;
		destIpAddrLong 				= 0;
		sourcePort					= 0;
		destPort					= 0;
		Key 						= 0;
		interfaceType 				= 0;
		dirUserNetwork				= 0;

#ifdef _S1U
		/* L3-Protocol Data TCP/UDP etc*/
		protoTLen		= 0;
		protoHLen 		= 0;
		protoSourcePort	= 0;
		protoDestPort 	= 0;
		protoPayload 	= 0;

		tcpSeqNo 		= 0;
		tcpFlags 		= 0;
//		tcpCType[0] 	= 0;
		httpAgent[0]	= 0;

		/* DNS Data */
		dnsQRFlag		= -1;
		dnsResponseCode = -1;
		dnsTransactionId= 0;
		dnsTLen			= 0;
		dnsName[0]		= 0;
		dnsIpAddress[0]	= 0;
#endif

#ifdef _S1MME
		SctpData 					= std::map <int, Sctp>();
#endif

#ifdef _S11
		gtpcRAT 			= 0;
		gtpcVersion 		= 0;
		gtpcMsgType 		= 0;
		gtpcCauseCode 		= 0;
		gtpcMsgLen 			= 0;
		gtpc_PktTeid 		= 0;

		gtpcMbrupl 			= 0;
		gtpcMbrdnl 			= 0;

		strcpy(IMSI, "NA");
		strcpy(IMEI, "NA");
		strcpy(MSISDN, "NA");
		strcpy(gtpcAPN, "NA");

		TAC 				= 0;
		eNodeB 				= 0;
		cellId 				= 0;
		gtpcV2PktSeqNo 		= 0;
		counter_val 		= 0;
		MME_ctl_teid		= 0;
		SGW_ctl_teid		= 0;
		PGW_ctl_teid		= 0;

		PGW_s1u_teid 	= 0;
		eNodeB_s1u_teid 	= 0;
		SGW_s1u_teid		= 0;

		strcpy(STN_SR, "NA");
		strcpy(pdnAddrAllocation, "NA");
		strcpy(servingNetwork, "NA");
		strcpy(pdnType, "NA");
		strcpy(PGWAddress, "NA");
		strcpy(MMEAddress, "NA");
		strcpy(SGWAddress, "NA");
		strcpy(MCCMNC, "NA");
#endif
	}
}MPacket;

typedef enum{
	NOK = 0,
	OK
}retType;

typedef struct _bwData
{
	uint64_t Bw;
	uint64_t upBw;
	uint64_t dnBw;

	uint64_t totalVol;
	uint64_t upTotalVol;
	uint64_t dnTotalVol;
	uint64_t avgTotalBw;
	uint64_t avgUpBw;
	uint64_t avgDnBw;
	uint64_t peakTotalVol;
	uint64_t peakUpTotalVol;
	uint64_t peakDnTotalVol;

	_bwData()
	{
		Bw = 0;
		upBw = 0;
		dnBw = 0;
		totalVol = 0;
		upTotalVol = 0;
		dnTotalVol = 0;
		avgTotalBw = 0;
		avgUpBw = 0;
		avgDnBw = 0;
		peakTotalVol = 0;
		peakUpTotalVol = 0;
		peakDnTotalVol = 0;
	}
}bwData;

namespace S1APFlush
{
	extern std::unordered_map<int, xdrStore> s1ap_xdr_f_0_t_0;
	extern std::unordered_map<int, xdrStore> s1ap_xdr_f_0_t_1;
	extern std::unordered_map<int, xdrStore> s1ap_xdr_f_0_t_2;
	extern std::unordered_map<int, xdrStore> s1ap_xdr_f_0_t_3;
	extern std::unordered_map<int, xdrStore> s1ap_xdr_f_0_t_4;
	extern std::unordered_map<int, xdrStore> s1ap_xdr_f_0_t_5;
	extern std::unordered_map<int, xdrStore> s1ap_xdr_f_0_t_6;
	extern std::unordered_map<int, xdrStore> s1ap_xdr_f_0_t_7;
	extern std::unordered_map<int, xdrStore> s1ap_xdr_f_0_t_8;
	extern std::unordered_map<int, xdrStore> s1ap_xdr_f_0_t_9;

	extern int s1ap_xdr_f_0_t_0_cnt;
	extern int s1ap_xdr_f_0_t_1_cnt;
	extern int s1ap_xdr_f_0_t_2_cnt;
	extern int s1ap_xdr_f_0_t_3_cnt;
	extern int s1ap_xdr_f_0_t_4_cnt;
	extern int s1ap_xdr_f_0_t_5_cnt;
	extern int s1ap_xdr_f_0_t_6_cnt;
	extern int s1ap_xdr_f_0_t_7_cnt;
	extern int s1ap_xdr_f_0_t_8_cnt;
	extern int s1ap_xdr_f_0_t_9_cnt;
}

namespace GTPStats {

	extern int unique_imsi_cnt;

	extern uint64_t gtp_cr_req_pkt_count;
	extern uint64_t gtp_cr_rsp_pkt_count;
	extern uint64_t gtp_mb_req_pkt_count;
	extern uint64_t gtp_mb_rsp_pkt_count;
	extern uint64_t gtp_dl_req_pkt_count;
	extern uint64_t gtp_dl_rsp_pkt_count;

	extern uint64_t gtp_cr_session_count;
	extern uint64_t gtp_mb_session_count;
	extern uint64_t gtp_dl_session_count;

	extern uint32_t gtp_cr_session_cln_count;
	extern uint32_t gtp_dl_session_cln_count;
	extern uint32_t gtp_mb_session_cln_count;

	extern uint32_t gtpv2_glb_sessions_active_count;
	extern uint32_t gtpv2_glb_sessions_delete_count;

	extern uint64_t gtpc_pkt_cnt_i_0_r_0;
	extern uint64_t gtpc_pkt_cnt_i_0_r_1;
	extern uint64_t gtpc_pkt_cnt_i_0_r_2;
	extern uint64_t gtpc_pkt_cnt_i_0_r_3;

	extern uint64_t gtpc_pkt_cnt_i_1_r_0;
	extern uint64_t gtpc_pkt_cnt_i_1_r_1;
	extern uint64_t gtpc_pkt_cnt_i_1_r_2;
	extern uint64_t gtpc_pkt_cnt_i_1_r_3;

	extern uint64_t gtpc_pkt_cnt_i_2_r_0;
	extern uint64_t gtpc_pkt_cnt_i_2_r_1;
	extern uint64_t gtpc_pkt_cnt_i_2_r_2;
	extern uint64_t gtpc_pkt_cnt_i_2_r_3;

	extern uint64_t gtpc_pkt_cnt_i_3_r_0;
	extern uint64_t gtpc_pkt_cnt_i_3_r_1;
	extern uint64_t gtpc_pkt_cnt_i_3_r_2;
	extern uint64_t gtpc_pkt_cnt_i_3_r_3;

	extern uint64_t gtpu_pkt_cnt_i_0_r_0;
	extern uint64_t gtpu_pkt_cnt_i_0_r_1;
	extern uint64_t gtpu_pkt_cnt_i_0_r_2;
	extern uint64_t gtpu_pkt_cnt_i_0_r_3;

	extern uint64_t gtpu_pkt_cnt_i_1_r_0;
	extern uint64_t gtpu_pkt_cnt_i_1_r_1;
	extern uint64_t gtpu_pkt_cnt_i_1_r_2;
	extern uint64_t gtpu_pkt_cnt_i_1_r_3;

	extern uint64_t gtpu_pkt_cnt_i_2_r_0;
	extern uint64_t gtpu_pkt_cnt_i_2_r_1;
	extern uint64_t gtpu_pkt_cnt_i_2_r_2;
	extern uint64_t gtpu_pkt_cnt_i_2_r_3;

	extern uint64_t gtpu_pkt_cnt_i_3_r_0;
	extern uint64_t gtpu_pkt_cnt_i_3_r_1;
	extern uint64_t gtpu_pkt_cnt_i_3_r_2;
	extern uint64_t gtpu_pkt_cnt_i_3_r_3;

	extern int gtpc_session_pool_cnt;
	extern int gtp_session_pool_bit_index;

	extern bool gtp_glb_sessions_cnt_process;

	extern int gtp_glb_lku_up_active_sessions_cnt;
	extern int gtp_glb_lku_up_sessions_cnt;
	extern int gtp_glb_lku_up_sessions_cln_cnt;

	extern int gtp_glb_lku_dn_active_sessions_cnt;
	extern int gtp_glb_lku_dn_sessions_cnt;
	extern int gtp_glb_lku_dn_sessions_cln_cnt;

	extern int gtp_glb_total_sessions_count;
	extern int gtpv1_glb_sessions_active_count;
	extern int gtpv1_glb_sessions_delete_count;

	extern int gtpv2_glb_lku_up_active_sessions_cnt;
	extern int gtpv2_glb_lku_up_sessions_cnt;
	extern int gtpv2_glb_lku_up_sessions_cln_cnt;

	extern int gtp_glb_utran_sessions_count;
	extern int gtp_glb_geran_sessions_count;
	extern int gtp_glb_eutran_sessions_count;

	extern int gtp_glb_active_sessionsV2_cnt;
	extern int gtp_glb_active_sessions_count;
	extern int gtp_glb_sessions_bit_index;

	extern int gtp_glb_ctl_up_cnt;
	extern int gtp_glb_data_up_cnt;
	extern int gtp_glb_ctl_dn_cnt;
	extern int gtp_glb_data_dn_cnt;

	extern uint32_t gtp_glb_sessions_op_cr_cnt;
	extern uint32_t gtp_glb_sessions_op_up_cnt;
	extern uint32_t gtp_glb_sessions_op_dl_cnt;

	extern uint32_t gtp_pdp_cr_flush_sm_0;
	extern uint32_t gtp_pdp_cr_flush_sm_1;
	extern uint32_t gtp_pdp_cr_flush_sm_2;
	extern uint32_t gtp_pdp_cr_flush_sm_3;

	extern uint32_t gtp_pdp_up_flush_sm_0;
	extern uint32_t gtp_pdp_up_flush_sm_1;
	extern uint32_t gtp_pdp_up_flush_sm_2;
	extern uint32_t gtp_pdp_up_flush_sm_3;

	extern uint32_t gtp_pdp_dl_flush_sm_0;
	extern uint32_t gtp_pdp_dl_flush_sm_1;
	extern uint32_t gtp_pdp_dl_flush_sm_2;
	extern uint32_t gtp_pdp_dl_flush_sm_3;

	extern uint32_t gtp_pdp_cr_session_count;
	extern uint32_t gtp_pdp_cr_session_sm_1;
	extern uint32_t gtp_pdp_cr_session_sm_2;
	extern uint32_t gtp_pdp_cr_session_sm_3;
	extern uint32_t gtp_pdp_cr_cln_session_count;

	extern uint32_t gtp_pdp_up_session_count;
	extern uint32_t gtp_pdp_up_session_sm_1;
	extern uint32_t gtp_pdp_up_session_sm_2;
	extern uint32_t gtp_pdp_up_session_sm_3;
	extern uint32_t gtp_pdp_up_cln_session_count;

	extern uint32_t gtp_pdp_dl_session_count;
	extern uint32_t gtp_pdp_dl_session_sm_1;
	extern uint32_t gtp_pdp_dl_session_sm_2;
	extern uint32_t gtp_pdp_dl_session_sm_3;
	extern uint32_t gtp_pdp_dl_cln_session_count;
	extern uint32_t gtpc_pdp_cr_req_sm_0;
	extern uint32_t gtpc_pdp_cr_req_sm_1;
	extern uint32_t gtpc_pdp_cr_req_sm_2;
	extern uint32_t gtpc_pdp_cr_req_sm_3;
	extern uint32_t gtpc_pdp_cr_res_sm_0;
	extern uint32_t gtpc_pdp_cr_res_sm_1;
	extern uint32_t gtpc_pdp_cr_res_sm_2;
	extern uint32_t gtpc_pdp_cr_res_sm_3;

	extern uint32_t gtpc_pdp_up_req_sm_0;
	extern uint32_t gtpc_pdp_up_req_sm_1;
	extern uint32_t gtpc_pdp_up_req_sm_2;
	extern uint32_t gtpc_pdp_up_req_sm_3;
	extern uint32_t gtpc_pdp_up_res_sm_0;
	extern uint32_t gtpc_pdp_up_res_sm_1;
	extern uint32_t gtpc_pdp_up_res_sm_2;
	extern uint32_t gtpc_pdp_up_res_sm_3;

	extern uint32_t gtpc_pdp_dl_req_sm_0;
	extern uint32_t gtpc_pdp_dl_req_sm_1;
	extern uint32_t gtpc_pdp_dl_req_sm_2;
	extern uint32_t gtpc_pdp_dl_req_sm_3;
	extern uint32_t gtpc_pdp_dl_res_sm_0;
	extern uint32_t gtpc_pdp_dl_res_sm_1;
	extern uint32_t gtpc_pdp_dl_res_sm_2;
	extern uint32_t gtpc_pdp_dl_res_sm_3;

}

namespace IPGlobal
{
	extern uint32_t	SM_PKT_LIMIT;
	extern uint64_t	CURRENT_EPOCH_SEC;
	extern uint64_t	CURRENT_EPOCH_MICRO_SEC;
	extern uint16_t	CURRENT_SEC;
	extern uint16_t	CURRENT_HOUR;
	extern uint16_t	CURRENT_MIN;
	extern uint16_t	CURRENT_DAY;
	extern uint16_t	CURRENT_MONTH;
	extern uint16_t	CURRENT_YEAR;
	extern uint128_t CURRENT_EPOCH_NANO_SEC;
	extern uint64_t CURRENT_EPOCH_MILI_SEC;

	extern BOOL		PROBE_RUNNING_STATUS;
	extern BOOL		PKT_LISTENER_RUNNING_STATUS[MAX_INTERFACE_SUPPORT];
	extern BOOL		PKT_LISTENER_INTF_MON_RUNNING_STATUS[MAX_INTERFACE_SUPPORT];
	extern BOOL		PKT_LISTENER_DAYCHANGE_INDICATION[MAX_INTERFACE_SUPPORT];
	extern BOOL		PKT_ROUTER_RUNNING_STATUS[MAX_INTERFACE_SUPPORT][MAX_ROUTER_PER_INTERFACE_SUPPORT];

	extern BOOL		S11_SESSION_MANAGER_RUNNING_STATUS[MAX_S11_SESSION_MANAGER_SUPPORT];
	extern int 		S11_SESSION_MANAGER_INSTANCES;
	extern int 		S11_SESSION_MANAGER_CPU_CORE[MAX_S11_SESSION_MANAGER_SUPPORT];
	extern BOOL		S11_SESSION_MANAGER_SHUTDOWN_STATUS[MAX_S11_SESSION_MANAGER_SUPPORT];
	extern int		S11_FLUSHER_NO;
	extern int		S11_FLUSHER_CPU_CORE;
	extern BOOL		S11_WRITE_XDR;
	extern int 		S11_XDR_WRITE_CPU_CORE;
	extern string  	S11_FILE_PREFIX;
	extern BOOL		S11_FLUSHER_RUNNING_STATUS;
	extern BOOL		S11_XDR_FLUSHER_RUNNING_STATUS;
	extern int		S11_IDLE_SESSION_TIMEOUT_IN_SEC;

	extern BOOL		S5S8_SESSION_MANAGER_RUNNING_STATUS[MAX_S5S8_SESSION_MANAGER_SUPPORT];
	extern int 		S5S8_SESSION_MANAGER_INSTANCES;
	extern int 		S5S8_SESSION_MANAGER_CPU_CORE[MAX_S5S8_SESSION_MANAGER_SUPPORT];
	extern BOOL		S5S8_SESSION_MANAGER_SHUTDOWN_STATUS[MAX_S5S8_SESSION_MANAGER_SUPPORT];
	extern int		S5S8_FLUSHER_NO;
	extern int		S5S8_FLUSHER_CPU_CORE;
	extern BOOL		S5S8_WRITE_XDR;
	extern int 		S5S8_XDR_WRITE_CPU_CORE;
	extern string  	S5S8_FILE_PREFIX;
	extern BOOL		S5S8_FLUSHER_RUNNING_STATUS;
	extern BOOL		S5S8_XDR_FLUSHER_RUNNING_STATUS;
	extern int 		S5S8_IDLE_SESSION_TIMEOUT_IN_SEC;

	extern BOOL		S1MME_SESSION_MANAGER_RUNNING_STATUS[MAX_S1MME_SESSION_MANAGER_SUPPORT];
	extern int 		S1MME_SESSION_MANAGER_INSTANCES;
	extern int 		S1MME_SESSION_MANAGER_CPU_CORE[MAX_S1MME_SESSION_MANAGER_SUPPORT];
	extern BOOL		S1MME_SESSION_MANAGER_SHUTDOWN_STATUS[MAX_S1MME_SESSION_MANAGER_SUPPORT];
	extern int		S1MME_FLUSHER_NO;
	extern int		S1MME_FLUSHER_CPU_CORE;
	extern BOOL		S1MME_WRITE_XDR;
	extern int 		S1MME_XDR_WRITE_CPU_CORE;
	extern string  	S1MME_FILE_PREFIX;
	extern BOOL		S1MME_FLUSHER_RUNNING_STATUS;
	extern BOOL		S1MME_XDR_FLUSHER_RUNNING_STATUS;
	extern int 		S1MME_ACTIVE_SESSIONS[MAX_S1MME_SESSION_MANAGER_SUPPORT];
	extern int 		S1MME_CLEANED_SESSIONS[MAX_S1MME_SESSION_MANAGER_SUPPORT];

	extern BOOL		S1U_SESSION_MANAGER_RUNNING_STATUS[MAX_IP_SESSION_MANAGER_SUPPORT];
	extern int		S1U_SESSION_MANAGER_INSTANCES;
	extern int		S1U_SESSION_MANAGER_CPU_CORE[MAX_IP_SESSION_MANAGER_SUPPORT];
	extern BOOL		S1U_SESSION_MANAGER_SHUTDOWN_STATUS[MAX_IP_SESSION_MANAGER_SUPPORT];
	extern int		S1U_FLUSHER_NO;
	extern int		S1U_FLUSHER_CPU_CORE[4];
	extern BOOL		S1U_WRITE_XDR;
	extern int 		S1U_XDR_WRITE_CPU_CORE;
	extern string  	S1U_FILE_PREFIX;
	extern BOOL		S1U_FLUSHER_RUNNING_STATUS;
	extern BOOL		S1U_XDR_FLUSHER_RUNNING_STATUS;
	extern int 		S1U_SESSION_TIME_INDEX_PKT_LIMIT;
	extern int 		S1U_SESSION_PKT_LIMIT;
	extern int 		S1U_SESSION_TIME_LIMIT;
	extern int 		S1U_SESSION_CLEAN_UP_SCAN_FREQ_SEC;
	extern int 		S1U_SESSION_CLEAN_UP_BATCH_LIMIT;
	extern int 		S1U_SESSION_CLEAN_UP_TIMEOUT_SEC;

	extern int 		S1U_VPS_PACKET_PER_SEC;
	extern BOOL 	S1U_UDP_XDR_FOR_DNS;
	extern int 		S1U_DNS_ANSWER;
	extern int 		DNS_LOOKUPDB_CLEAN_UP_TIMEOUT_SEC;
    extern int 		DNS_KEY_TIME_LIMIT_SEC;
	extern BOOL		DNS_FLUSHER_RUNNING_STATUS;
	extern BOOL		DNS_XDR_FLUSHER_RUNNING_STATUS;
	extern int 		DNS_FLUSHER_NO;
	extern int 		DNS_FLUSHER_CPU_CORE[4];
	extern BOOL		DNS_WRITE_XDR;
	extern int 		DNS_XDR_WRITE_CPU_CORE;
	extern string  	DNS_FILE_PREFIX;

	extern ULONG	IPV4_RANGE[35][2];
	extern int		IPV4_NO_OF_RANGE;

	extern int		GN_GTPC_GLOBAL_SESSION_CLEANUP_TIMEOUT_SEC;

	extern BOOL		PROBE_STATS_RUNNING_STATUS;

	extern int 		S1AP_ATTACH_SESSIONS_TODAY[MAX_S1MME_SESSION_MANAGER_SUPPORT];
	extern int 		S1AP_TAU_SESSIONS_TODAY[MAX_S1MME_SESSION_MANAGER_SUPPORT];
	extern int 		S1AP_HANDOVERS_TODAY[MAX_S1MME_SESSION_MANAGER_SUPPORT];

	extern int 		ACTIVE_S1U_IP_SESSIONS[MAX_IP_SESSION_MANAGER_SUPPORT];
	extern int 		ACTIVE_S1U_DNS_SESSIONS[MAX_IP_SESSION_MANAGER_SUPPORT];

	extern int 		CLEANED_S1U_IP_SESSIONS[MAX_IP_SESSION_MANAGER_SUPPORT];
	extern int 		CLEANED_S1U_DNS_SESSIONS[MAX_IP_SESSION_MANAGER_SUPPORT];

	extern int 		PROBE_ID;
	extern bool 	PRINT_STATS;
	extern int 		PRINT_STATS_FREQ_SEC;
	extern int		LOG_STATS_FREQ_SEC;

	extern	int		NO_OF_NIC_INTERFACE;
	extern	int		NO_OF_SOLAR_INTERFACE;
	extern	int 	NO_OF_INTERFACES;

	extern 	BOOL	S1U_PROCESS_OUT_OF_RANGE_IP;
	extern 	BOOL	S1U_PROCESS_USER_AGENT;
	extern 	BOOL	S1U_CHECK_DUPLICATE;
	extern 	BOOL	S1U_PROCESS_ACK;
	extern 	BOOL	S1U_ACK_CREATE_SESSION;

	extern 	long 	PACKET_COUNT;

	extern	string 	ETHERNET_INTERFACES[MAX_INTERFACE_SUPPORT];
	extern	string 	SOLAR_INTERFACES[MAX_INTERFACE_SUPPORT];
	extern	string	PNAME[MAX_INTERFACE_SUPPORT];
	extern	int 	ROUTER_PER_INTERFACE[MAX_INTERFACE_SUPPORT];
	extern	int		PKT_LISTENER_CPU_CORE[MAX_INTERFACE_SUPPORT];
	extern	int 	PKT_ROUTER_CPU_CORE[MAX_INTERFACE_SUPPORT][MAX_ROUTER_PER_INTERFACE_SUPPORT];
	extern	int		PKT_TIME_INDEX;
	extern	int 	PPS_PER_INTERFACE[MAX_INTERFACE_SUPPORT];
	extern	int		PPS_CAP_PERCENTAGE[MAX_INTERFACE_SUPPORT];
	extern  int 	SGSN_PC[10];
	extern  int		NO_OF_SGSN;
	extern int		SOLARFLARE_HW_TIMESTAMP;
	extern	int		MAX_BW_INTERFACE[MAX_INTERFACE_SUPPORT];

	extern uint32_t	MME_RANGE[15][2];
	extern uint16_t	MME_NO_OF_RANGE;

	extern uint32_t	PGW_RANGE[15][2];
	extern uint16_t	PGW_NO_OF_RANGE;

	extern bool		PROCESS_FLAG_i_0;
	extern bool		PROCESS_FLAG_i_1;
	extern bool		PROCESS_FLAG_i_2;
	extern bool		PROCESS_FLAG_i_3;
	extern bool		PROCESS_FLAG_i_4;
	extern bool		PROCESS_FLAG_i_5;
	extern bool		PROCESS_FLAG_i_6;
	extern bool		PROCESS_FLAG_i_7;

	extern bool		PACKET_PROCESSING;
	extern bool		ROUTER_PACKET_PROCESSING;

	extern uint32_t PKT_RATE_INTF_0;
	extern uint32_t PKT_RATE_INTF_1;
	extern uint32_t PKT_RATE_INTF_2;
	extern uint32_t PKT_RATE_INTF_3;
	extern uint32_t PKT_RATE_INTF_4;
	extern uint32_t PKT_RATE_INTF_5;
	extern uint32_t PKT_RATE_INTF_6;
	extern uint32_t PKT_RATE_INTF_7;

	extern uint128_t PKTS_TOTAL_INTF_0;
	extern uint128_t PKTS_TOTAL_INTF_1;
	extern uint128_t PKTS_TOTAL_INTF_2;
	extern uint128_t PKTS_TOTAL_INTF_3;
	extern uint128_t PKTS_TOTAL_INTF_4;
	extern uint128_t PKTS_TOTAL_INTF_5;
	extern uint128_t PKTS_TOTAL_INTF_6;
	extern uint128_t PKTS_TOTAL_INTF_7;

	extern uint64_t BW_MBPS_INTF_0;
	extern uint64_t BW_MBPS_INTF_1;
	extern uint64_t BW_MBPS_INTF_2;
	extern uint64_t BW_MBPS_INTF_3;
	extern uint64_t BW_MBPS_INTF_4;
	extern uint64_t BW_MBPS_INTF_5;
	extern uint64_t BW_MBPS_INTF_6;
	extern uint64_t BW_MBPS_INTF_7;

	extern bwData 	BW_MBPS_i_0_r_0;
	extern bwData 	BW_MBPS_i_0_r_1;
	extern bwData 	BW_MBPS_i_0_r_2;
	extern bwData	BW_MBPS_i_0_r_3;
	extern bwData 	BW_MBPS_i_0_r_4;
	extern bwData 	BW_MBPS_i_0_r_5;
	extern bwData 	BW_MBPS_i_0_r_6;
	extern bwData 	BW_MBPS_i_0_r_7;

	extern bwData BW_MBPS_i_1_r_0;
	extern bwData BW_MBPS_i_1_r_1;
	extern bwData BW_MBPS_i_1_r_2;
	extern bwData BW_MBPS_i_1_r_3;
	extern bwData BW_MBPS_i_1_r_4;
	extern bwData BW_MBPS_i_1_r_5;
	extern bwData BW_MBPS_i_1_r_6;
	extern bwData BW_MBPS_i_1_r_7;

	extern bwData BW_MBPS_i_2_r_0;
	extern bwData BW_MBPS_i_2_r_1;
	extern bwData BW_MBPS_i_2_r_2;
	extern bwData BW_MBPS_i_2_r_3;
	extern bwData BW_MBPS_i_2_r_4;
	extern bwData BW_MBPS_i_2_r_5;
	extern bwData BW_MBPS_i_2_r_6;
	extern bwData BW_MBPS_i_2_r_7;

	extern bwData BW_MBPS_i_3_r_0;
	extern bwData BW_MBPS_i_3_r_1;
	extern bwData BW_MBPS_i_3_r_2;
	extern bwData BW_MBPS_i_3_r_3;
	extern bwData BW_MBPS_i_3_r_4;
	extern bwData BW_MBPS_i_3_r_5;
	extern bwData BW_MBPS_i_3_r_6;
	extern bwData BW_MBPS_i_3_r_7;

	extern bwData BW_MBPS_i_4_r_0;
	extern bwData BW_MBPS_i_4_r_1;
	extern bwData BW_MBPS_i_4_r_2;
	extern bwData BW_MBPS_i_4_r_3;
	extern bwData BW_MBPS_i_4_r_4;
	extern bwData BW_MBPS_i_4_r_5;
	extern bwData BW_MBPS_i_4_r_6;
	extern bwData BW_MBPS_i_4_r_7;

	extern bwData BW_MBPS_i_5_r_0;
	extern bwData BW_MBPS_i_5_r_1;
	extern bwData BW_MBPS_i_5_r_2;
	extern bwData BW_MBPS_i_5_r_3;
	extern bwData BW_MBPS_i_5_r_4;
	extern bwData BW_MBPS_i_5_r_5;
	extern bwData BW_MBPS_i_5_r_6;
	extern bwData BW_MBPS_i_5_r_7;

	extern bwData BW_MBPS_i_6_r_0;
	extern bwData BW_MBPS_i_6_r_1;
	extern bwData BW_MBPS_i_6_r_2;
	extern bwData BW_MBPS_i_6_r_3;
	extern bwData BW_MBPS_i_6_r_4;
	extern bwData BW_MBPS_i_6_r_5;
	extern bwData BW_MBPS_i_6_r_6;
	extern bwData BW_MBPS_i_6_r_7;

	extern bwData BW_MBPS_i_7_r_0;
	extern bwData BW_MBPS_i_7_r_1;
	extern bwData BW_MBPS_i_7_r_2;
	extern bwData BW_MBPS_i_7_r_3;
	extern bwData BW_MBPS_i_7_r_4;
	extern bwData BW_MBPS_i_7_r_5;
	extern bwData BW_MBPS_i_7_r_6;
	extern bwData BW_MBPS_i_7_r_7;

    extern ULONG	t_FrameCount;
    extern fstream IPXdrHandler;
    extern fstream bwLogHandler;

    extern uint16_t	logLevel;

    extern uint64_t ip_discarded_large_packets_i_0;
    extern uint64_t ip_discarded_large_packets_i_1;
    extern uint64_t ip_discarded_large_packets_i_2;
    extern uint64_t ip_discarded_large_packets_i_3;
    extern uint64_t ip_discarded_large_packets_i_4;
    extern uint64_t ip_discarded_large_packets_i_5;
    extern uint64_t ip_discarded_large_packets_i_6;
    extern uint64_t ip_discarded_large_packets_i_7;

	extern string	ADMIN_PORT;
	extern BOOL		ADMIN_FLAG;
	extern BOOL		UPDATE_IP_RANGE;

	extern int		MAX_PKT_LEN_PER_INTERFACE[MAX_INTERFACE_SUPPORT];
	extern int		DNS_DUMP_HOUR;

	/* Operator Name */
	extern string 	OPERATOR_NAME[MAX_OPERATOR];
}

namespace IPStats {
	extern uint64_t dns_resolved_lookup_size;
	extern uint64_t dns_lookup_map_size;

	extern int dns_session_total_sm_0_cnt;
	extern int dns_session_total_sm_1_cnt;
	extern int dns_session_total_sm_2_cnt;
	extern int dns_session_total_sm_3_cnt;
	extern int dns_session_total_sm_4_cnt;
	extern int dns_session_total_sm_5_cnt;
	extern int dns_session_total_sm_6_cnt;
	extern int dns_session_total_sm_7_cnt;
	extern int dns_session_total_sm_8_cnt;
	extern int dns_session_total_sm_9_cnt;
	extern int dns_session_total_sm_10_cnt;
	extern int dns_session_total_sm_11_cnt;
	extern int dns_session_total_sm_12_cnt;
	extern int dns_session_total_sm_13_cnt;
	extern int dns_session_total_sm_14_cnt;
	extern int dns_session_total_sm_15_cnt;
	extern int dns_session_total_sm_16_cnt;
	extern int dns_session_total_sm_17_cnt;
	extern int dns_session_total_sm_18_cnt;
	extern int dns_session_total_sm_19_cnt;
	extern int dns_session_total_sm_20_cnt;
	extern int dns_session_total_sm_21_cnt;
	extern int dns_session_total_sm_22_cnt;
	extern int dns_session_total_sm_23_cnt;
	extern int dns_session_total_sm_24_cnt;
	extern int dns_session_total_sm_25_cnt;
	extern int dns_session_total_sm_26_cnt;
	extern int dns_session_total_sm_27_cnt;
	extern int dns_session_total_sm_28_cnt;
	extern int dns_session_total_sm_29_cnt;


	extern int dns_session_pool_sm_0_cnt;
	extern int dns_session_pool_sm_1_cnt;
	extern int dns_session_pool_sm_2_cnt;
	extern int dns_session_pool_sm_3_cnt;
	extern int dns_session_pool_sm_4_cnt;
	extern int dns_session_pool_sm_5_cnt;
	extern int dns_session_pool_sm_6_cnt;
	extern int dns_session_pool_sm_7_cnt;
	extern int dns_session_pool_sm_8_cnt;
	extern int dns_session_pool_sm_9_cnt;
	extern int dns_session_pool_sm_10_cnt;
	extern int dns_session_pool_sm_11_cnt;
	extern int dns_session_pool_sm_12_cnt;
	extern int dns_session_pool_sm_13_cnt;
	extern int dns_session_pool_sm_14_cnt;
	extern int dns_session_pool_sm_15_cnt;
	extern int dns_session_pool_sm_16_cnt;
	extern int dns_session_pool_sm_17_cnt;
	extern int dns_session_pool_sm_18_cnt;
	extern int dns_session_pool_sm_19_cnt;

	extern uint64_t ip_session_fin_only_sm_0_cnt;
	extern uint64_t ip_session_fin_only_sm_1_cnt;
	extern uint64_t ip_session_fin_only_sm_2_cnt;
	extern uint64_t ip_session_fin_only_sm_3_cnt;
	extern uint64_t ip_session_fin_only_sm_4_cnt;
	extern uint64_t ip_session_fin_only_sm_5_cnt;
	extern uint64_t ip_session_fin_only_sm_6_cnt;
	extern uint64_t ip_session_fin_only_sm_7_cnt;
	extern uint64_t ip_session_fin_only_sm_8_cnt;
	extern uint64_t ip_session_fin_only_sm_9_cnt;
	extern uint64_t ip_session_fin_only_sm_10_cnt;
	extern uint64_t ip_session_fin_only_sm_11_cnt;
	extern uint64_t ip_session_fin_only_sm_12_cnt;
	extern uint64_t ip_session_fin_only_sm_13_cnt;
	extern uint64_t ip_session_fin_only_sm_14_cnt;
	extern uint64_t ip_session_fin_only_sm_15_cnt;
	extern uint64_t ip_session_fin_only_sm_16_cnt;
	extern uint64_t ip_session_fin_only_sm_17_cnt;
	extern uint64_t ip_session_fin_only_sm_18_cnt;
	extern uint64_t ip_session_fin_only_sm_19_cnt;

	extern int ip_session_pkt_total_sm_0_cnt;
	extern int ip_session_pkt_total_sm_1_cnt;
	extern int ip_session_pkt_total_sm_2_cnt;
	extern int ip_session_pkt_total_sm_3_cnt;
	extern int ip_session_pkt_total_sm_4_cnt;
	extern int ip_session_pkt_total_sm_5_cnt;
	extern int ip_session_pkt_total_sm_6_cnt;
	extern int ip_session_pkt_total_sm_7_cnt;
	extern int ip_session_pkt_total_sm_8_cnt;
	extern int ip_session_pkt_total_sm_9_cnt;
	extern int ip_session_pkt_total_sm_10_cnt;
	extern int ip_session_pkt_total_sm_11_cnt;
	extern int ip_session_pkt_total_sm_12_cnt;
	extern int ip_session_pkt_total_sm_13_cnt;
	extern int ip_session_pkt_total_sm_14_cnt;
	extern int ip_session_pkt_total_sm_15_cnt;
	extern int ip_session_pkt_total_sm_16_cnt;
	extern int ip_session_pkt_total_sm_17_cnt;
	extern int ip_session_pkt_total_sm_18_cnt;
	extern int ip_session_pkt_total_sm_19_cnt;

	extern int ip_session_pkt_sm_0_cnt[10];
	extern int ip_session_pkt_sm_1_cnt[10];
	extern int ip_session_pkt_sm_2_cnt[10];
	extern int ip_session_pkt_sm_3_cnt[10];
	extern int ip_session_pkt_sm_4_cnt[10];
	extern int ip_session_pkt_sm_5_cnt[10];
	extern int ip_session_pkt_sm_6_cnt[10];
	extern int ip_session_pkt_sm_7_cnt[10];
	extern int ip_session_pkt_sm_8_cnt[10];
	extern int ip_session_pkt_sm_9_cnt[10];
	extern int ip_session_pkt_sm_10_cnt[10];
	extern int ip_session_pkt_sm_11_cnt[10];
	extern int ip_session_pkt_sm_12_cnt[10];
	extern int ip_session_pkt_sm_13_cnt[10];
	extern int ip_session_pkt_sm_14_cnt[10];
	extern int ip_session_pkt_sm_15_cnt[10];
	extern int ip_session_pkt_sm_16_cnt[10];
	extern int ip_session_pkt_sm_17_cnt[10];
	extern int ip_session_pkt_sm_18_cnt[10];
	extern int ip_session_pkt_sm_19_cnt[10];

	extern int ip_session_total_sm_0_cnt;
	extern int ip_session_total_sm_1_cnt;
	extern int ip_session_total_sm_2_cnt;
	extern int ip_session_total_sm_3_cnt;
	extern int ip_session_total_sm_4_cnt;
	extern int ip_session_total_sm_5_cnt;
	extern int ip_session_total_sm_6_cnt;
	extern int ip_session_total_sm_7_cnt;
	extern int ip_session_total_sm_8_cnt;
	extern int ip_session_total_sm_9_cnt;
	extern int ip_session_total_sm_10_cnt;
	extern int ip_session_total_sm_11_cnt;
	extern int ip_session_total_sm_12_cnt;
	extern int ip_session_total_sm_13_cnt;
	extern int ip_session_total_sm_14_cnt;
	extern int ip_session_total_sm_15_cnt;
	extern int ip_session_total_sm_16_cnt;
	extern int ip_session_total_sm_17_cnt;
	extern int ip_session_total_sm_18_cnt;
	extern int ip_session_total_sm_19_cnt;
	extern int ip_session_total_sm_20_cnt;
	extern int ip_session_total_sm_21_cnt;
	extern int ip_session_total_sm_22_cnt;
	extern int ip_session_total_sm_23_cnt;
	extern int ip_session_total_sm_24_cnt;
	extern int ip_session_total_sm_25_cnt;
	extern int ip_session_total_sm_26_cnt;
	extern int ip_session_total_sm_27_cnt;
	extern int ip_session_total_sm_28_cnt;
	extern int ip_session_total_sm_29_cnt;

	extern int ip_session_scanned_sm_0_cnt;
	extern int ip_session_scanned_sm_1_cnt;
	extern int ip_session_scanned_sm_2_cnt;
	extern int ip_session_scanned_sm_3_cnt;
	extern int ip_session_scanned_sm_4_cnt;
	extern int ip_session_scanned_sm_5_cnt;
	extern int ip_session_scanned_sm_6_cnt;
	extern int ip_session_scanned_sm_7_cnt;
	extern int ip_session_scanned_sm_8_cnt;
	extern int ip_session_scanned_sm_9_cnt;
	extern int ip_session_scanned_sm_10_cnt;
	extern int ip_session_scanned_sm_11_cnt;
	extern int ip_session_scanned_sm_12_cnt;
	extern int ip_session_scanned_sm_13_cnt;
	extern int ip_session_scanned_sm_14_cnt;
	extern int ip_session_scanned_sm_15_cnt;
	extern int ip_session_scanned_sm_16_cnt;
	extern int ip_session_scanned_sm_17_cnt;
	extern int ip_session_scanned_sm_18_cnt;
	extern int ip_session_scanned_sm_19_cnt;
	extern int ip_session_scanned_sm_20_cnt;
	extern int ip_session_scanned_sm_21_cnt;
	extern int ip_session_scanned_sm_22_cnt;
	extern int ip_session_scanned_sm_23_cnt;
	extern int ip_session_scanned_sm_24_cnt;
	extern int ip_session_scanned_sm_25_cnt;
	extern int ip_session_scanned_sm_26_cnt;
	extern int ip_session_scanned_sm_27_cnt;
	extern int ip_session_scanned_sm_28_cnt;
	extern int ip_session_scanned_sm_29_cnt;

	extern int ip_session_cleaned_tcp_sm_0_cnt;
	extern int ip_session_cleaned_tcp_sm_1_cnt;
	extern int ip_session_cleaned_tcp_sm_2_cnt;
	extern int ip_session_cleaned_tcp_sm_3_cnt;
	extern int ip_session_cleaned_tcp_sm_4_cnt;
	extern int ip_session_cleaned_tcp_sm_5_cnt;
	extern int ip_session_cleaned_tcp_sm_6_cnt;
	extern int ip_session_cleaned_tcp_sm_7_cnt;
	extern int ip_session_cleaned_tcp_sm_8_cnt;
	extern int ip_session_cleaned_tcp_sm_9_cnt;
	extern int ip_session_cleaned_tcp_sm_10_cnt;
	extern int ip_session_cleaned_tcp_sm_11_cnt;
	extern int ip_session_cleaned_tcp_sm_12_cnt;
	extern int ip_session_cleaned_tcp_sm_13_cnt;
	extern int ip_session_cleaned_tcp_sm_14_cnt;
	extern int ip_session_cleaned_tcp_sm_15_cnt;
	extern int ip_session_cleaned_tcp_sm_16_cnt;
	extern int ip_session_cleaned_tcp_sm_17_cnt;
	extern int ip_session_cleaned_tcp_sm_18_cnt;
	extern int ip_session_cleaned_tcp_sm_19_cnt;
	extern int ip_session_cleaned_tcp_sm_20_cnt;
	extern int ip_session_cleaned_tcp_sm_21_cnt;
	extern int ip_session_cleaned_tcp_sm_22_cnt;
	extern int ip_session_cleaned_tcp_sm_23_cnt;
	extern int ip_session_cleaned_tcp_sm_24_cnt;
	extern int ip_session_cleaned_tcp_sm_25_cnt;
	extern int ip_session_cleaned_tcp_sm_26_cnt;
	extern int ip_session_cleaned_tcp_sm_27_cnt;
	extern int ip_session_cleaned_tcp_sm_28_cnt;
	extern int ip_session_cleaned_tcp_sm_29_cnt;

	extern int ip_session_cleaned_udp_sm_0_cnt;
	extern int ip_session_cleaned_udp_sm_1_cnt;
	extern int ip_session_cleaned_udp_sm_2_cnt;
	extern int ip_session_cleaned_udp_sm_3_cnt;
	extern int ip_session_cleaned_udp_sm_4_cnt;
	extern int ip_session_cleaned_udp_sm_5_cnt;
	extern int ip_session_cleaned_udp_sm_6_cnt;
	extern int ip_session_cleaned_udp_sm_7_cnt;
	extern int ip_session_cleaned_udp_sm_8_cnt;
	extern int ip_session_cleaned_udp_sm_9_cnt;
	extern int ip_session_cleaned_udp_sm_10_cnt;
	extern int ip_session_cleaned_udp_sm_11_cnt;
	extern int ip_session_cleaned_udp_sm_12_cnt;
	extern int ip_session_cleaned_udp_sm_13_cnt;
	extern int ip_session_cleaned_udp_sm_14_cnt;
	extern int ip_session_cleaned_udp_sm_15_cnt;
	extern int ip_session_cleaned_udp_sm_16_cnt;
	extern int ip_session_cleaned_udp_sm_17_cnt;
	extern int ip_session_cleaned_udp_sm_18_cnt;
	extern int ip_session_cleaned_udp_sm_19_cnt;
	extern int ip_session_cleaned_udp_sm_20_cnt;
	extern int ip_session_cleaned_udp_sm_21_cnt;
	extern int ip_session_cleaned_udp_sm_22_cnt;
	extern int ip_session_cleaned_udp_sm_23_cnt;
	extern int ip_session_cleaned_udp_sm_24_cnt;
	extern int ip_session_cleaned_udp_sm_25_cnt;
	extern int ip_session_cleaned_udp_sm_26_cnt;
	extern int ip_session_cleaned_udp_sm_27_cnt;
	extern int ip_session_cleaned_udp_sm_28_cnt;
	extern int ip_session_cleaned_udp_sm_29_cnt;

	extern int ip_session_pool_sm_0_cnt;
	extern int ip_session_pool_sm_1_cnt;
	extern int ip_session_pool_sm_2_cnt;
	extern int ip_session_pool_sm_3_cnt;
	extern int ip_session_pool_sm_4_cnt;
	extern int ip_session_pool_sm_5_cnt;
	extern int ip_session_pool_sm_6_cnt;
	extern int ip_session_pool_sm_7_cnt;
	extern int ip_session_pool_sm_8_cnt;
	extern int ip_session_pool_sm_9_cnt;
	extern int ip_session_pool_sm_10_cnt;
	extern int ip_session_pool_sm_11_cnt;
	extern int ip_session_pool_sm_12_cnt;
	extern int ip_session_pool_sm_13_cnt;
	extern int ip_session_pool_sm_14_cnt;
	extern int ip_session_pool_sm_15_cnt;
	extern int ip_session_pool_sm_16_cnt;
	extern int ip_session_pool_sm_17_cnt;
	extern int ip_session_pool_sm_18_cnt;
	extern int ip_session_pool_sm_19_cnt;
	extern int ip_session_pool_sm_20_cnt;
	extern int ip_session_pool_sm_21_cnt;
	extern int ip_session_pool_sm_22_cnt;
	extern int ip_session_pool_sm_23_cnt;
	extern int ip_session_pool_sm_24_cnt;
	extern int ip_session_pool_sm_25_cnt;
	extern int ip_session_pool_sm_26_cnt;
	extern int ip_session_pool_sm_27_cnt;
	extern int ip_session_pool_sm_28_cnt;
	extern int ip_session_pool_sm_29_cnt;

}

namespace PKTStore
{
	// Interface_0
	extern std::unordered_map<long, RawPkt*> pktRepository_i_0_r_0_t_0;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_0_r_0_t_1;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_0_r_0_t_2;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_0_r_0_t_3;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_0_r_0_t_4;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_0_r_0_t_5;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_0_r_0_t_6;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_0_r_0_t_7;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_0_r_0_t_8;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_0_r_0_t_9;

	extern long pktRepository_i_0_r_0_t_0_cnt;
	extern long pktRepository_i_0_r_0_t_1_cnt;
	extern long pktRepository_i_0_r_0_t_2_cnt;
	extern long pktRepository_i_0_r_0_t_3_cnt;
	extern long pktRepository_i_0_r_0_t_4_cnt;
	extern long pktRepository_i_0_r_0_t_5_cnt;
	extern long pktRepository_i_0_r_0_t_6_cnt;
	extern long pktRepository_i_0_r_0_t_7_cnt;
	extern long pktRepository_i_0_r_0_t_8_cnt;
	extern long pktRepository_i_0_r_0_t_9_cnt;

	extern bool pktRepository_i_0_r_0_t_0_busy;
	extern bool pktRepository_i_0_r_0_t_1_busy;
	extern bool pktRepository_i_0_r_0_t_2_busy;
	extern bool pktRepository_i_0_r_0_t_3_busy;
	extern bool pktRepository_i_0_r_0_t_4_busy;
	extern bool pktRepository_i_0_r_0_t_5_busy;
	extern bool pktRepository_i_0_r_0_t_6_busy;
	extern bool pktRepository_i_0_r_0_t_7_busy;
	extern bool pktRepository_i_0_r_0_t_8_busy;
	extern bool pktRepository_i_0_r_0_t_9_busy;

	extern std::unordered_map<long, RawPkt*> pktRepository_i_0_r_1_t_0;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_0_r_1_t_1;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_0_r_1_t_2;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_0_r_1_t_3;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_0_r_1_t_4;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_0_r_1_t_5;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_0_r_1_t_6;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_0_r_1_t_7;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_0_r_1_t_8;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_0_r_1_t_9;

	extern long pktRepository_i_0_r_1_t_0_cnt;
	extern long pktRepository_i_0_r_1_t_1_cnt;
	extern long pktRepository_i_0_r_1_t_2_cnt;
	extern long pktRepository_i_0_r_1_t_3_cnt;
	extern long pktRepository_i_0_r_1_t_4_cnt;
	extern long pktRepository_i_0_r_1_t_5_cnt;
	extern long pktRepository_i_0_r_1_t_6_cnt;
	extern long pktRepository_i_0_r_1_t_7_cnt;
	extern long pktRepository_i_0_r_1_t_8_cnt;
	extern long pktRepository_i_0_r_1_t_9_cnt;

	extern bool pktRepository_i_0_r_1_t_0_busy;
	extern bool pktRepository_i_0_r_1_t_1_busy;
	extern bool pktRepository_i_0_r_1_t_2_busy;
	extern bool pktRepository_i_0_r_1_t_3_busy;
	extern bool pktRepository_i_0_r_1_t_4_busy;
	extern bool pktRepository_i_0_r_1_t_5_busy;
	extern bool pktRepository_i_0_r_1_t_6_busy;
	extern bool pktRepository_i_0_r_1_t_7_busy;
	extern bool pktRepository_i_0_r_1_t_8_busy;
	extern bool pktRepository_i_0_r_1_t_9_busy;

	extern std::unordered_map<long, RawPkt*> pktRepository_i_0_r_2_t_0;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_0_r_2_t_1;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_0_r_2_t_2;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_0_r_2_t_3;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_0_r_2_t_4;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_0_r_2_t_5;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_0_r_2_t_6;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_0_r_2_t_7;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_0_r_2_t_8;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_0_r_2_t_9;

	extern long pktRepository_i_0_r_2_t_0_cnt;
	extern long pktRepository_i_0_r_2_t_1_cnt;
	extern long pktRepository_i_0_r_2_t_2_cnt;
	extern long pktRepository_i_0_r_2_t_3_cnt;
	extern long pktRepository_i_0_r_2_t_4_cnt;
	extern long pktRepository_i_0_r_2_t_5_cnt;
	extern long pktRepository_i_0_r_2_t_6_cnt;
	extern long pktRepository_i_0_r_2_t_7_cnt;
	extern long pktRepository_i_0_r_2_t_8_cnt;
	extern long pktRepository_i_0_r_2_t_9_cnt;

	extern bool pktRepository_i_0_r_2_t_0_busy;
	extern bool pktRepository_i_0_r_2_t_1_busy;
	extern bool pktRepository_i_0_r_2_t_2_busy;
	extern bool pktRepository_i_0_r_2_t_3_busy;
	extern bool pktRepository_i_0_r_2_t_4_busy;
	extern bool pktRepository_i_0_r_2_t_5_busy;
	extern bool pktRepository_i_0_r_2_t_6_busy;
	extern bool pktRepository_i_0_r_2_t_7_busy;
	extern bool pktRepository_i_0_r_2_t_8_busy;
	extern bool pktRepository_i_0_r_2_t_9_busy;

	extern std::unordered_map<long, RawPkt*> pktRepository_i_0_r_3_t_0;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_0_r_3_t_1;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_0_r_3_t_2;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_0_r_3_t_3;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_0_r_3_t_4;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_0_r_3_t_5;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_0_r_3_t_6;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_0_r_3_t_7;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_0_r_3_t_8;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_0_r_3_t_9;

	extern long pktRepository_i_0_r_3_t_0_cnt;
	extern long pktRepository_i_0_r_3_t_1_cnt;
	extern long pktRepository_i_0_r_3_t_2_cnt;
	extern long pktRepository_i_0_r_3_t_3_cnt;
	extern long pktRepository_i_0_r_3_t_4_cnt;
	extern long pktRepository_i_0_r_3_t_5_cnt;
	extern long pktRepository_i_0_r_3_t_6_cnt;
	extern long pktRepository_i_0_r_3_t_7_cnt;
	extern long pktRepository_i_0_r_3_t_8_cnt;
	extern long pktRepository_i_0_r_3_t_9_cnt;

	extern bool pktRepository_i_0_r_3_t_0_busy;
	extern bool pktRepository_i_0_r_3_t_1_busy;
	extern bool pktRepository_i_0_r_3_t_2_busy;
	extern bool pktRepository_i_0_r_3_t_3_busy;
	extern bool pktRepository_i_0_r_3_t_4_busy;
	extern bool pktRepository_i_0_r_3_t_5_busy;
	extern bool pktRepository_i_0_r_3_t_6_busy;
	extern bool pktRepository_i_0_r_3_t_7_busy;
	extern bool pktRepository_i_0_r_3_t_8_busy;
	extern bool pktRepository_i_0_r_3_t_9_busy;

	extern std::unordered_map<long, RawPkt*> pktRepository_i_0_r_4_t_0;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_0_r_4_t_1;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_0_r_4_t_2;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_0_r_4_t_3;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_0_r_4_t_4;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_0_r_4_t_5;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_0_r_4_t_6;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_0_r_4_t_7;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_0_r_4_t_8;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_0_r_4_t_9;

	extern long pktRepository_i_0_r_4_t_0_cnt;
	extern long pktRepository_i_0_r_4_t_1_cnt;
	extern long pktRepository_i_0_r_4_t_2_cnt;
	extern long pktRepository_i_0_r_4_t_3_cnt;
	extern long pktRepository_i_0_r_4_t_4_cnt;
	extern long pktRepository_i_0_r_4_t_5_cnt;
	extern long pktRepository_i_0_r_4_t_6_cnt;
	extern long pktRepository_i_0_r_4_t_7_cnt;
	extern long pktRepository_i_0_r_4_t_8_cnt;
	extern long pktRepository_i_0_r_4_t_9_cnt;

	extern bool pktRepository_i_0_r_4_t_0_busy;
	extern bool pktRepository_i_0_r_4_t_1_busy;
	extern bool pktRepository_i_0_r_4_t_2_busy;
	extern bool pktRepository_i_0_r_4_t_3_busy;
	extern bool pktRepository_i_0_r_4_t_4_busy;
	extern bool pktRepository_i_0_r_4_t_5_busy;
	extern bool pktRepository_i_0_r_4_t_6_busy;
	extern bool pktRepository_i_0_r_4_t_7_busy;
	extern bool pktRepository_i_0_r_4_t_8_busy;
	extern bool pktRepository_i_0_r_4_t_9_busy;

	extern std::unordered_map<long, RawPkt*> pktRepository_i_0_r_5_t_0;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_0_r_5_t_1;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_0_r_5_t_2;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_0_r_5_t_3;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_0_r_5_t_4;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_0_r_5_t_5;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_0_r_5_t_6;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_0_r_5_t_7;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_0_r_5_t_8;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_0_r_5_t_9;

	extern long pktRepository_i_0_r_5_t_0_cnt;
	extern long pktRepository_i_0_r_5_t_1_cnt;
	extern long pktRepository_i_0_r_5_t_2_cnt;
	extern long pktRepository_i_0_r_5_t_3_cnt;
	extern long pktRepository_i_0_r_5_t_4_cnt;
	extern long pktRepository_i_0_r_5_t_5_cnt;
	extern long pktRepository_i_0_r_5_t_6_cnt;
	extern long pktRepository_i_0_r_5_t_7_cnt;
	extern long pktRepository_i_0_r_5_t_8_cnt;
	extern long pktRepository_i_0_r_5_t_9_cnt;

	extern bool pktRepository_i_0_r_5_t_0_busy;
	extern bool pktRepository_i_0_r_5_t_1_busy;
	extern bool pktRepository_i_0_r_5_t_2_busy;
	extern bool pktRepository_i_0_r_5_t_3_busy;
	extern bool pktRepository_i_0_r_5_t_4_busy;
	extern bool pktRepository_i_0_r_5_t_5_busy;
	extern bool pktRepository_i_0_r_5_t_6_busy;
	extern bool pktRepository_i_0_r_5_t_7_busy;
	extern bool pktRepository_i_0_r_5_t_8_busy;
	extern bool pktRepository_i_0_r_5_t_9_busy;

	extern std::unordered_map<long, RawPkt*> pktRepository_i_0_r_6_t_0;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_0_r_6_t_1;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_0_r_6_t_2;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_0_r_6_t_3;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_0_r_6_t_4;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_0_r_6_t_5;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_0_r_6_t_6;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_0_r_6_t_7;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_0_r_6_t_8;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_0_r_6_t_9;

	extern long pktRepository_i_0_r_6_t_0_cnt;
	extern long pktRepository_i_0_r_6_t_1_cnt;
	extern long pktRepository_i_0_r_6_t_2_cnt;
	extern long pktRepository_i_0_r_6_t_3_cnt;
	extern long pktRepository_i_0_r_6_t_4_cnt;
	extern long pktRepository_i_0_r_6_t_5_cnt;
	extern long pktRepository_i_0_r_6_t_6_cnt;
	extern long pktRepository_i_0_r_6_t_7_cnt;
	extern long pktRepository_i_0_r_6_t_8_cnt;
	extern long pktRepository_i_0_r_6_t_9_cnt;

	extern bool pktRepository_i_0_r_6_t_0_busy;
	extern bool pktRepository_i_0_r_6_t_1_busy;
	extern bool pktRepository_i_0_r_6_t_2_busy;
	extern bool pktRepository_i_0_r_6_t_3_busy;
	extern bool pktRepository_i_0_r_6_t_4_busy;
	extern bool pktRepository_i_0_r_6_t_5_busy;
	extern bool pktRepository_i_0_r_6_t_6_busy;
	extern bool pktRepository_i_0_r_6_t_7_busy;
	extern bool pktRepository_i_0_r_6_t_8_busy;
	extern bool pktRepository_i_0_r_6_t_9_busy;

	extern std::unordered_map<long, RawPkt*> pktRepository_i_0_r_7_t_0;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_0_r_7_t_1;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_0_r_7_t_2;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_0_r_7_t_3;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_0_r_7_t_4;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_0_r_7_t_5;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_0_r_7_t_6;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_0_r_7_t_7;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_0_r_7_t_8;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_0_r_7_t_9;

	extern long pktRepository_i_0_r_7_t_0_cnt;
	extern long pktRepository_i_0_r_7_t_1_cnt;
	extern long pktRepository_i_0_r_7_t_2_cnt;
	extern long pktRepository_i_0_r_7_t_3_cnt;
	extern long pktRepository_i_0_r_7_t_4_cnt;
	extern long pktRepository_i_0_r_7_t_5_cnt;
	extern long pktRepository_i_0_r_7_t_6_cnt;
	extern long pktRepository_i_0_r_7_t_7_cnt;
	extern long pktRepository_i_0_r_7_t_8_cnt;
	extern long pktRepository_i_0_r_7_t_9_cnt;

	extern bool pktRepository_i_0_r_7_t_0_busy;
	extern bool pktRepository_i_0_r_7_t_1_busy;
	extern bool pktRepository_i_0_r_7_t_2_busy;
	extern bool pktRepository_i_0_r_7_t_3_busy;
	extern bool pktRepository_i_0_r_7_t_4_busy;
	extern bool pktRepository_i_0_r_7_t_5_busy;
	extern bool pktRepository_i_0_r_7_t_6_busy;
	extern bool pktRepository_i_0_r_7_t_7_busy;
	extern bool pktRepository_i_0_r_7_t_8_busy;
	extern bool pktRepository_i_0_r_7_t_9_busy;

	// Interface_1
	extern std::unordered_map<long, RawPkt*> pktRepository_i_1_r_0_t_0;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_1_r_0_t_1;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_1_r_0_t_2;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_1_r_0_t_3;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_1_r_0_t_4;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_1_r_0_t_5;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_1_r_0_t_6;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_1_r_0_t_7;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_1_r_0_t_8;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_1_r_0_t_9;

	extern long pktRepository_i_1_r_0_t_0_cnt;
	extern long pktRepository_i_1_r_0_t_1_cnt;
	extern long pktRepository_i_1_r_0_t_2_cnt;
	extern long pktRepository_i_1_r_0_t_3_cnt;
	extern long pktRepository_i_1_r_0_t_4_cnt;
	extern long pktRepository_i_1_r_0_t_5_cnt;
	extern long pktRepository_i_1_r_0_t_6_cnt;
	extern long pktRepository_i_1_r_0_t_7_cnt;
	extern long pktRepository_i_1_r_0_t_8_cnt;
	extern long pktRepository_i_1_r_0_t_9_cnt;

	extern bool pktRepository_i_1_r_0_t_0_busy;
	extern bool pktRepository_i_1_r_0_t_1_busy;
	extern bool pktRepository_i_1_r_0_t_2_busy;
	extern bool pktRepository_i_1_r_0_t_3_busy;
	extern bool pktRepository_i_1_r_0_t_4_busy;
	extern bool pktRepository_i_1_r_0_t_5_busy;
	extern bool pktRepository_i_1_r_0_t_6_busy;
	extern bool pktRepository_i_1_r_0_t_7_busy;
	extern bool pktRepository_i_1_r_0_t_8_busy;
	extern bool pktRepository_i_1_r_0_t_9_busy;

	extern std::unordered_map<long, RawPkt*> pktRepository_i_1_r_1_t_0;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_1_r_1_t_1;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_1_r_1_t_2;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_1_r_1_t_3;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_1_r_1_t_4;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_1_r_1_t_5;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_1_r_1_t_6;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_1_r_1_t_7;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_1_r_1_t_8;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_1_r_1_t_9;

	extern long pktRepository_i_1_r_1_t_0_cnt;
	extern long pktRepository_i_1_r_1_t_1_cnt;
	extern long pktRepository_i_1_r_1_t_2_cnt;
	extern long pktRepository_i_1_r_1_t_3_cnt;
	extern long pktRepository_i_1_r_1_t_4_cnt;
	extern long pktRepository_i_1_r_1_t_5_cnt;
	extern long pktRepository_i_1_r_1_t_6_cnt;
	extern long pktRepository_i_1_r_1_t_7_cnt;
	extern long pktRepository_i_1_r_1_t_8_cnt;
	extern long pktRepository_i_1_r_1_t_9_cnt;

	extern bool pktRepository_i_1_r_1_t_0_busy;
	extern bool pktRepository_i_1_r_1_t_1_busy;
	extern bool pktRepository_i_1_r_1_t_2_busy;
	extern bool pktRepository_i_1_r_1_t_3_busy;
	extern bool pktRepository_i_1_r_1_t_4_busy;
	extern bool pktRepository_i_1_r_1_t_5_busy;
	extern bool pktRepository_i_1_r_1_t_6_busy;
	extern bool pktRepository_i_1_r_1_t_7_busy;
	extern bool pktRepository_i_1_r_1_t_8_busy;
	extern bool pktRepository_i_1_r_1_t_9_busy;

	extern std::unordered_map<long, RawPkt*> pktRepository_i_1_r_2_t_0;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_1_r_2_t_1;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_1_r_2_t_2;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_1_r_2_t_3;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_1_r_2_t_4;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_1_r_2_t_5;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_1_r_2_t_6;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_1_r_2_t_7;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_1_r_2_t_8;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_1_r_2_t_9;

	extern long pktRepository_i_1_r_2_t_0_cnt;
	extern long pktRepository_i_1_r_2_t_1_cnt;
	extern long pktRepository_i_1_r_2_t_2_cnt;
	extern long pktRepository_i_1_r_2_t_3_cnt;
	extern long pktRepository_i_1_r_2_t_4_cnt;
	extern long pktRepository_i_1_r_2_t_5_cnt;
	extern long pktRepository_i_1_r_2_t_6_cnt;
	extern long pktRepository_i_1_r_2_t_7_cnt;
	extern long pktRepository_i_1_r_2_t_8_cnt;
	extern long pktRepository_i_1_r_2_t_9_cnt;

	extern bool pktRepository_i_1_r_2_t_0_busy;
	extern bool pktRepository_i_1_r_2_t_1_busy;
	extern bool pktRepository_i_1_r_2_t_2_busy;
	extern bool pktRepository_i_1_r_2_t_3_busy;
	extern bool pktRepository_i_1_r_2_t_4_busy;
	extern bool pktRepository_i_1_r_2_t_5_busy;
	extern bool pktRepository_i_1_r_2_t_6_busy;
	extern bool pktRepository_i_1_r_2_t_7_busy;
	extern bool pktRepository_i_1_r_2_t_8_busy;
	extern bool pktRepository_i_1_r_2_t_9_busy;

	extern std::unordered_map<long, RawPkt*> pktRepository_i_1_r_3_t_0;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_1_r_3_t_1;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_1_r_3_t_2;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_1_r_3_t_3;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_1_r_3_t_4;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_1_r_3_t_5;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_1_r_3_t_6;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_1_r_3_t_7;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_1_r_3_t_8;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_1_r_3_t_9;

	extern long pktRepository_i_1_r_3_t_0_cnt;
	extern long pktRepository_i_1_r_3_t_1_cnt;
	extern long pktRepository_i_1_r_3_t_2_cnt;
	extern long pktRepository_i_1_r_3_t_3_cnt;
	extern long pktRepository_i_1_r_3_t_4_cnt;
	extern long pktRepository_i_1_r_3_t_5_cnt;
	extern long pktRepository_i_1_r_3_t_6_cnt;
	extern long pktRepository_i_1_r_3_t_7_cnt;
	extern long pktRepository_i_1_r_3_t_8_cnt;
	extern long pktRepository_i_1_r_3_t_9_cnt;

	extern bool pktRepository_i_1_r_3_t_0_busy;
	extern bool pktRepository_i_1_r_3_t_1_busy;
	extern bool pktRepository_i_1_r_3_t_2_busy;
	extern bool pktRepository_i_1_r_3_t_3_busy;
	extern bool pktRepository_i_1_r_3_t_4_busy;
	extern bool pktRepository_i_1_r_3_t_5_busy;
	extern bool pktRepository_i_1_r_3_t_6_busy;
	extern bool pktRepository_i_1_r_3_t_7_busy;
	extern bool pktRepository_i_1_r_3_t_8_busy;
	extern bool pktRepository_i_1_r_3_t_9_busy;

	extern std::unordered_map<long, RawPkt*> pktRepository_i_1_r_4_t_0;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_1_r_4_t_1;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_1_r_4_t_2;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_1_r_4_t_3;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_1_r_4_t_4;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_1_r_4_t_5;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_1_r_4_t_6;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_1_r_4_t_7;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_1_r_4_t_8;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_1_r_4_t_9;

	extern long pktRepository_i_1_r_4_t_0_cnt;
	extern long pktRepository_i_1_r_4_t_1_cnt;
	extern long pktRepository_i_1_r_4_t_2_cnt;
	extern long pktRepository_i_1_r_4_t_3_cnt;
	extern long pktRepository_i_1_r_4_t_4_cnt;
	extern long pktRepository_i_1_r_4_t_5_cnt;
	extern long pktRepository_i_1_r_4_t_6_cnt;
	extern long pktRepository_i_1_r_4_t_7_cnt;
	extern long pktRepository_i_1_r_4_t_8_cnt;
	extern long pktRepository_i_1_r_4_t_9_cnt;

	extern bool pktRepository_i_1_r_4_t_0_busy;
	extern bool pktRepository_i_1_r_4_t_1_busy;
	extern bool pktRepository_i_1_r_4_t_2_busy;
	extern bool pktRepository_i_1_r_4_t_3_busy;
	extern bool pktRepository_i_1_r_4_t_4_busy;
	extern bool pktRepository_i_1_r_4_t_5_busy;
	extern bool pktRepository_i_1_r_4_t_6_busy;
	extern bool pktRepository_i_1_r_4_t_7_busy;
	extern bool pktRepository_i_1_r_4_t_8_busy;
	extern bool pktRepository_i_1_r_4_t_9_busy;

	extern std::unordered_map<long, RawPkt*> pktRepository_i_1_r_5_t_0;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_1_r_5_t_1;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_1_r_5_t_2;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_1_r_5_t_3;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_1_r_5_t_4;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_1_r_5_t_5;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_1_r_5_t_6;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_1_r_5_t_7;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_1_r_5_t_8;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_1_r_5_t_9;

	extern long pktRepository_i_1_r_5_t_0_cnt;
	extern long pktRepository_i_1_r_5_t_1_cnt;
	extern long pktRepository_i_1_r_5_t_2_cnt;
	extern long pktRepository_i_1_r_5_t_3_cnt;
	extern long pktRepository_i_1_r_5_t_4_cnt;
	extern long pktRepository_i_1_r_5_t_5_cnt;
	extern long pktRepository_i_1_r_5_t_6_cnt;
	extern long pktRepository_i_1_r_5_t_7_cnt;
	extern long pktRepository_i_1_r_5_t_8_cnt;
	extern long pktRepository_i_1_r_5_t_9_cnt;

	extern bool pktRepository_i_1_r_5_t_0_busy;
	extern bool pktRepository_i_1_r_5_t_1_busy;
	extern bool pktRepository_i_1_r_5_t_2_busy;
	extern bool pktRepository_i_1_r_5_t_3_busy;
	extern bool pktRepository_i_1_r_5_t_4_busy;
	extern bool pktRepository_i_1_r_5_t_5_busy;
	extern bool pktRepository_i_1_r_5_t_6_busy;
	extern bool pktRepository_i_1_r_5_t_7_busy;
	extern bool pktRepository_i_1_r_5_t_8_busy;
	extern bool pktRepository_i_1_r_5_t_9_busy;

	extern std::unordered_map<long, RawPkt*> pktRepository_i_1_r_6_t_0;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_1_r_6_t_1;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_1_r_6_t_2;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_1_r_6_t_3;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_1_r_6_t_4;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_1_r_6_t_5;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_1_r_6_t_6;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_1_r_6_t_7;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_1_r_6_t_8;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_1_r_6_t_9;

	extern long pktRepository_i_1_r_6_t_0_cnt;
	extern long pktRepository_i_1_r_6_t_1_cnt;
	extern long pktRepository_i_1_r_6_t_2_cnt;
	extern long pktRepository_i_1_r_6_t_3_cnt;
	extern long pktRepository_i_1_r_6_t_4_cnt;
	extern long pktRepository_i_1_r_6_t_5_cnt;
	extern long pktRepository_i_1_r_6_t_6_cnt;
	extern long pktRepository_i_1_r_6_t_7_cnt;
	extern long pktRepository_i_1_r_6_t_8_cnt;
	extern long pktRepository_i_1_r_6_t_9_cnt;

	extern bool pktRepository_i_1_r_6_t_0_busy;
	extern bool pktRepository_i_1_r_6_t_1_busy;
	extern bool pktRepository_i_1_r_6_t_2_busy;
	extern bool pktRepository_i_1_r_6_t_3_busy;
	extern bool pktRepository_i_1_r_6_t_4_busy;
	extern bool pktRepository_i_1_r_6_t_5_busy;
	extern bool pktRepository_i_1_r_6_t_6_busy;
	extern bool pktRepository_i_1_r_6_t_7_busy;
	extern bool pktRepository_i_1_r_6_t_8_busy;
	extern bool pktRepository_i_1_r_6_t_9_busy;

	extern std::unordered_map<long, RawPkt*> pktRepository_i_1_r_7_t_0;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_1_r_7_t_1;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_1_r_7_t_2;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_1_r_7_t_3;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_1_r_7_t_4;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_1_r_7_t_5;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_1_r_7_t_6;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_1_r_7_t_7;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_1_r_7_t_8;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_1_r_7_t_9;

	extern long pktRepository_i_1_r_7_t_0_cnt;
	extern long pktRepository_i_1_r_7_t_1_cnt;
	extern long pktRepository_i_1_r_7_t_2_cnt;
	extern long pktRepository_i_1_r_7_t_3_cnt;
	extern long pktRepository_i_1_r_7_t_4_cnt;
	extern long pktRepository_i_1_r_7_t_5_cnt;
	extern long pktRepository_i_1_r_7_t_6_cnt;
	extern long pktRepository_i_1_r_7_t_7_cnt;
	extern long pktRepository_i_1_r_7_t_8_cnt;
	extern long pktRepository_i_1_r_7_t_9_cnt;

	extern bool pktRepository_i_1_r_7_t_0_busy;
	extern bool pktRepository_i_1_r_7_t_1_busy;
	extern bool pktRepository_i_1_r_7_t_2_busy;
	extern bool pktRepository_i_1_r_7_t_3_busy;
	extern bool pktRepository_i_1_r_7_t_4_busy;
	extern bool pktRepository_i_1_r_7_t_5_busy;
	extern bool pktRepository_i_1_r_7_t_6_busy;
	extern bool pktRepository_i_1_r_7_t_7_busy;
	extern bool pktRepository_i_1_r_7_t_8_busy;
	extern bool pktRepository_i_1_r_7_t_9_busy;

	// Interface_2
	extern std::unordered_map<long, RawPkt*> pktRepository_i_2_r_0_t_0;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_2_r_0_t_1;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_2_r_0_t_2;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_2_r_0_t_3;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_2_r_0_t_4;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_2_r_0_t_5;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_2_r_0_t_6;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_2_r_0_t_7;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_2_r_0_t_8;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_2_r_0_t_9;

	extern long pktRepository_i_2_r_0_t_0_cnt;
	extern long pktRepository_i_2_r_0_t_1_cnt;
	extern long pktRepository_i_2_r_0_t_2_cnt;
	extern long pktRepository_i_2_r_0_t_3_cnt;
	extern long pktRepository_i_2_r_0_t_4_cnt;
	extern long pktRepository_i_2_r_0_t_5_cnt;
	extern long pktRepository_i_2_r_0_t_6_cnt;
	extern long pktRepository_i_2_r_0_t_7_cnt;
	extern long pktRepository_i_2_r_0_t_8_cnt;
	extern long pktRepository_i_2_r_0_t_9_cnt;

	extern bool pktRepository_i_2_r_0_t_0_busy;
	extern bool pktRepository_i_2_r_0_t_1_busy;
	extern bool pktRepository_i_2_r_0_t_2_busy;
	extern bool pktRepository_i_2_r_0_t_3_busy;
	extern bool pktRepository_i_2_r_0_t_4_busy;
	extern bool pktRepository_i_2_r_0_t_5_busy;
	extern bool pktRepository_i_2_r_0_t_6_busy;
	extern bool pktRepository_i_2_r_0_t_7_busy;
	extern bool pktRepository_i_2_r_0_t_8_busy;
	extern bool pktRepository_i_2_r_0_t_9_busy;

	extern std::unordered_map<long, RawPkt*> pktRepository_i_2_r_1_t_0;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_2_r_1_t_1;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_2_r_1_t_2;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_2_r_1_t_3;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_2_r_1_t_4;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_2_r_1_t_5;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_2_r_1_t_6;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_2_r_1_t_7;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_2_r_1_t_8;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_2_r_1_t_9;

	extern long pktRepository_i_2_r_1_t_0_cnt;
	extern long pktRepository_i_2_r_1_t_1_cnt;
	extern long pktRepository_i_2_r_1_t_2_cnt;
	extern long pktRepository_i_2_r_1_t_3_cnt;
	extern long pktRepository_i_2_r_1_t_4_cnt;
	extern long pktRepository_i_2_r_1_t_5_cnt;
	extern long pktRepository_i_2_r_1_t_6_cnt;
	extern long pktRepository_i_2_r_1_t_7_cnt;
	extern long pktRepository_i_2_r_1_t_8_cnt;
	extern long pktRepository_i_2_r_1_t_9_cnt;

	extern bool pktRepository_i_2_r_1_t_0_busy;
	extern bool pktRepository_i_2_r_1_t_1_busy;
	extern bool pktRepository_i_2_r_1_t_2_busy;
	extern bool pktRepository_i_2_r_1_t_3_busy;
	extern bool pktRepository_i_2_r_1_t_4_busy;
	extern bool pktRepository_i_2_r_1_t_5_busy;
	extern bool pktRepository_i_2_r_1_t_6_busy;
	extern bool pktRepository_i_2_r_1_t_7_busy;
	extern bool pktRepository_i_2_r_1_t_8_busy;
	extern bool pktRepository_i_2_r_1_t_9_busy;

	extern std::unordered_map<long, RawPkt*> pktRepository_i_2_r_2_t_0;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_2_r_2_t_1;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_2_r_2_t_2;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_2_r_2_t_3;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_2_r_2_t_4;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_2_r_2_t_5;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_2_r_2_t_6;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_2_r_2_t_7;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_2_r_2_t_8;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_2_r_2_t_9;

	extern long pktRepository_i_2_r_2_t_0_cnt;
	extern long pktRepository_i_2_r_2_t_1_cnt;
	extern long pktRepository_i_2_r_2_t_2_cnt;
	extern long pktRepository_i_2_r_2_t_3_cnt;
	extern long pktRepository_i_2_r_2_t_4_cnt;
	extern long pktRepository_i_2_r_2_t_5_cnt;
	extern long pktRepository_i_2_r_2_t_6_cnt;
	extern long pktRepository_i_2_r_2_t_7_cnt;
	extern long pktRepository_i_2_r_2_t_8_cnt;
	extern long pktRepository_i_2_r_2_t_9_cnt;

	extern bool pktRepository_i_2_r_2_t_0_busy;
	extern bool pktRepository_i_2_r_2_t_1_busy;
	extern bool pktRepository_i_2_r_2_t_2_busy;
	extern bool pktRepository_i_2_r_2_t_3_busy;
	extern bool pktRepository_i_2_r_2_t_4_busy;
	extern bool pktRepository_i_2_r_2_t_5_busy;
	extern bool pktRepository_i_2_r_2_t_6_busy;
	extern bool pktRepository_i_2_r_2_t_7_busy;
	extern bool pktRepository_i_2_r_2_t_8_busy;
	extern bool pktRepository_i_2_r_2_t_9_busy;

	extern std::unordered_map<long, RawPkt*> pktRepository_i_2_r_3_t_0;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_2_r_3_t_1;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_2_r_3_t_2;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_2_r_3_t_3;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_2_r_3_t_4;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_2_r_3_t_5;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_2_r_3_t_6;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_2_r_3_t_7;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_2_r_3_t_8;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_2_r_3_t_9;

	extern long pktRepository_i_2_r_3_t_0_cnt;
	extern long pktRepository_i_2_r_3_t_1_cnt;
	extern long pktRepository_i_2_r_3_t_2_cnt;
	extern long pktRepository_i_2_r_3_t_3_cnt;
	extern long pktRepository_i_2_r_3_t_4_cnt;
	extern long pktRepository_i_2_r_3_t_5_cnt;
	extern long pktRepository_i_2_r_3_t_6_cnt;
	extern long pktRepository_i_2_r_3_t_7_cnt;
	extern long pktRepository_i_2_r_3_t_8_cnt;
	extern long pktRepository_i_2_r_3_t_9_cnt;

	extern bool pktRepository_i_2_r_3_t_0_busy;
	extern bool pktRepository_i_2_r_3_t_1_busy;
	extern bool pktRepository_i_2_r_3_t_2_busy;
	extern bool pktRepository_i_2_r_3_t_3_busy;
	extern bool pktRepository_i_2_r_3_t_4_busy;
	extern bool pktRepository_i_2_r_3_t_5_busy;
	extern bool pktRepository_i_2_r_3_t_6_busy;
	extern bool pktRepository_i_2_r_3_t_7_busy;
	extern bool pktRepository_i_2_r_3_t_8_busy;
	extern bool pktRepository_i_2_r_3_t_9_busy;

	extern std::unordered_map<long, RawPkt*> pktRepository_i_2_r_4_t_0;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_2_r_4_t_1;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_2_r_4_t_2;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_2_r_4_t_3;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_2_r_4_t_4;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_2_r_4_t_5;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_2_r_4_t_6;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_2_r_4_t_7;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_2_r_4_t_8;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_2_r_4_t_9;

	extern long pktRepository_i_2_r_4_t_0_cnt;
	extern long pktRepository_i_2_r_4_t_1_cnt;
	extern long pktRepository_i_2_r_4_t_2_cnt;
	extern long pktRepository_i_2_r_4_t_3_cnt;
	extern long pktRepository_i_2_r_4_t_4_cnt;
	extern long pktRepository_i_2_r_4_t_5_cnt;
	extern long pktRepository_i_2_r_4_t_6_cnt;
	extern long pktRepository_i_2_r_4_t_7_cnt;
	extern long pktRepository_i_2_r_4_t_8_cnt;
	extern long pktRepository_i_2_r_4_t_9_cnt;

	extern bool pktRepository_i_2_r_4_t_0_busy;
	extern bool pktRepository_i_2_r_4_t_1_busy;
	extern bool pktRepository_i_2_r_4_t_2_busy;
	extern bool pktRepository_i_2_r_4_t_3_busy;
	extern bool pktRepository_i_2_r_4_t_4_busy;
	extern bool pktRepository_i_2_r_4_t_5_busy;
	extern bool pktRepository_i_2_r_4_t_6_busy;
	extern bool pktRepository_i_2_r_4_t_7_busy;
	extern bool pktRepository_i_2_r_4_t_8_busy;
	extern bool pktRepository_i_2_r_4_t_9_busy;

	extern std::unordered_map<long, RawPkt*> pktRepository_i_2_r_5_t_0;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_2_r_5_t_1;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_2_r_5_t_2;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_2_r_5_t_3;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_2_r_5_t_4;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_2_r_5_t_5;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_2_r_5_t_6;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_2_r_5_t_7;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_2_r_5_t_8;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_2_r_5_t_9;

	extern long pktRepository_i_2_r_5_t_0_cnt;
	extern long pktRepository_i_2_r_5_t_1_cnt;
	extern long pktRepository_i_2_r_5_t_2_cnt;
	extern long pktRepository_i_2_r_5_t_3_cnt;
	extern long pktRepository_i_2_r_5_t_4_cnt;
	extern long pktRepository_i_2_r_5_t_5_cnt;
	extern long pktRepository_i_2_r_5_t_6_cnt;
	extern long pktRepository_i_2_r_5_t_7_cnt;
	extern long pktRepository_i_2_r_5_t_8_cnt;
	extern long pktRepository_i_2_r_5_t_9_cnt;

	extern bool pktRepository_i_2_r_5_t_0_busy;
	extern bool pktRepository_i_2_r_5_t_1_busy;
	extern bool pktRepository_i_2_r_5_t_2_busy;
	extern bool pktRepository_i_2_r_5_t_3_busy;
	extern bool pktRepository_i_2_r_5_t_4_busy;
	extern bool pktRepository_i_2_r_5_t_5_busy;
	extern bool pktRepository_i_2_r_5_t_6_busy;
	extern bool pktRepository_i_2_r_5_t_7_busy;
	extern bool pktRepository_i_2_r_5_t_8_busy;
	extern bool pktRepository_i_2_r_5_t_9_busy;

	extern std::unordered_map<long, RawPkt*> pktRepository_i_2_r_6_t_0;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_2_r_6_t_1;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_2_r_6_t_2;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_2_r_6_t_3;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_2_r_6_t_4;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_2_r_6_t_5;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_2_r_6_t_6;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_2_r_6_t_7;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_2_r_6_t_8;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_2_r_6_t_9;

	extern long pktRepository_i_2_r_6_t_0_cnt;
	extern long pktRepository_i_2_r_6_t_1_cnt;
	extern long pktRepository_i_2_r_6_t_2_cnt;
	extern long pktRepository_i_2_r_6_t_3_cnt;
	extern long pktRepository_i_2_r_6_t_4_cnt;
	extern long pktRepository_i_2_r_6_t_5_cnt;
	extern long pktRepository_i_2_r_6_t_6_cnt;
	extern long pktRepository_i_2_r_6_t_7_cnt;
	extern long pktRepository_i_2_r_6_t_8_cnt;
	extern long pktRepository_i_2_r_6_t_9_cnt;

	extern bool pktRepository_i_2_r_6_t_0_busy;
	extern bool pktRepository_i_2_r_6_t_1_busy;
	extern bool pktRepository_i_2_r_6_t_2_busy;
	extern bool pktRepository_i_2_r_6_t_3_busy;
	extern bool pktRepository_i_2_r_6_t_4_busy;
	extern bool pktRepository_i_2_r_6_t_5_busy;
	extern bool pktRepository_i_2_r_6_t_6_busy;
	extern bool pktRepository_i_2_r_6_t_7_busy;
	extern bool pktRepository_i_2_r_6_t_8_busy;
	extern bool pktRepository_i_2_r_6_t_9_busy;

	extern std::unordered_map<long, RawPkt*> pktRepository_i_2_r_7_t_0;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_2_r_7_t_1;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_2_r_7_t_2;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_2_r_7_t_3;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_2_r_7_t_4;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_2_r_7_t_5;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_2_r_7_t_6;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_2_r_7_t_7;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_2_r_7_t_8;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_2_r_7_t_9;

	extern long pktRepository_i_2_r_7_t_0_cnt;
	extern long pktRepository_i_2_r_7_t_1_cnt;
	extern long pktRepository_i_2_r_7_t_2_cnt;
	extern long pktRepository_i_2_r_7_t_3_cnt;
	extern long pktRepository_i_2_r_7_t_4_cnt;
	extern long pktRepository_i_2_r_7_t_5_cnt;
	extern long pktRepository_i_2_r_7_t_6_cnt;
	extern long pktRepository_i_2_r_7_t_7_cnt;
	extern long pktRepository_i_2_r_7_t_8_cnt;
	extern long pktRepository_i_2_r_7_t_9_cnt;

	extern bool pktRepository_i_2_r_7_t_0_busy;
	extern bool pktRepository_i_2_r_7_t_1_busy;
	extern bool pktRepository_i_2_r_7_t_2_busy;
	extern bool pktRepository_i_2_r_7_t_3_busy;
	extern bool pktRepository_i_2_r_7_t_4_busy;
	extern bool pktRepository_i_2_r_7_t_5_busy;
	extern bool pktRepository_i_2_r_7_t_6_busy;
	extern bool pktRepository_i_2_r_7_t_7_busy;
	extern bool pktRepository_i_2_r_7_t_8_busy;
	extern bool pktRepository_i_2_r_7_t_9_busy;

	// Interface_3
	extern std::unordered_map<long, RawPkt*> pktRepository_i_3_r_0_t_0;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_3_r_0_t_1;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_3_r_0_t_2;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_3_r_0_t_3;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_3_r_0_t_4;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_3_r_0_t_5;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_3_r_0_t_6;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_3_r_0_t_7;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_3_r_0_t_8;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_3_r_0_t_9;

	extern long pktRepository_i_3_r_0_t_0_cnt;
	extern long pktRepository_i_3_r_0_t_1_cnt;
	extern long pktRepository_i_3_r_0_t_2_cnt;
	extern long pktRepository_i_3_r_0_t_3_cnt;
	extern long pktRepository_i_3_r_0_t_4_cnt;
	extern long pktRepository_i_3_r_0_t_5_cnt;
	extern long pktRepository_i_3_r_0_t_6_cnt;
	extern long pktRepository_i_3_r_0_t_7_cnt;
	extern long pktRepository_i_3_r_0_t_8_cnt;
	extern long pktRepository_i_3_r_0_t_9_cnt;

	extern bool pktRepository_i_3_r_0_t_0_busy;
	extern bool pktRepository_i_3_r_0_t_1_busy;
	extern bool pktRepository_i_3_r_0_t_2_busy;
	extern bool pktRepository_i_3_r_0_t_3_busy;
	extern bool pktRepository_i_3_r_0_t_4_busy;
	extern bool pktRepository_i_3_r_0_t_5_busy;
	extern bool pktRepository_i_3_r_0_t_6_busy;
	extern bool pktRepository_i_3_r_0_t_7_busy;
	extern bool pktRepository_i_3_r_0_t_8_busy;
	extern bool pktRepository_i_3_r_0_t_9_busy;

	extern std::unordered_map<long, RawPkt*> pktRepository_i_3_r_1_t_0;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_3_r_1_t_1;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_3_r_1_t_2;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_3_r_1_t_3;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_3_r_1_t_4;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_3_r_1_t_5;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_3_r_1_t_6;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_3_r_1_t_7;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_3_r_1_t_8;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_3_r_1_t_9;

	extern long pktRepository_i_3_r_1_t_0_cnt;
	extern long pktRepository_i_3_r_1_t_1_cnt;
	extern long pktRepository_i_3_r_1_t_2_cnt;
	extern long pktRepository_i_3_r_1_t_3_cnt;
	extern long pktRepository_i_3_r_1_t_4_cnt;
	extern long pktRepository_i_3_r_1_t_5_cnt;
	extern long pktRepository_i_3_r_1_t_6_cnt;
	extern long pktRepository_i_3_r_1_t_7_cnt;
	extern long pktRepository_i_3_r_1_t_8_cnt;
	extern long pktRepository_i_3_r_1_t_9_cnt;

	extern bool pktRepository_i_3_r_1_t_0_busy;
	extern bool pktRepository_i_3_r_1_t_1_busy;
	extern bool pktRepository_i_3_r_1_t_2_busy;
	extern bool pktRepository_i_3_r_1_t_3_busy;
	extern bool pktRepository_i_3_r_1_t_4_busy;
	extern bool pktRepository_i_3_r_1_t_5_busy;
	extern bool pktRepository_i_3_r_1_t_6_busy;
	extern bool pktRepository_i_3_r_1_t_7_busy;
	extern bool pktRepository_i_3_r_1_t_8_busy;
	extern bool pktRepository_i_3_r_1_t_9_busy;

	extern std::unordered_map<long, RawPkt*> pktRepository_i_3_r_2_t_0;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_3_r_2_t_1;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_3_r_2_t_2;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_3_r_2_t_3;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_3_r_2_t_4;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_3_r_2_t_5;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_3_r_2_t_6;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_3_r_2_t_7;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_3_r_2_t_8;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_3_r_2_t_9;

	extern long pktRepository_i_3_r_2_t_0_cnt;
	extern long pktRepository_i_3_r_2_t_1_cnt;
	extern long pktRepository_i_3_r_2_t_2_cnt;
	extern long pktRepository_i_3_r_2_t_3_cnt;
	extern long pktRepository_i_3_r_2_t_4_cnt;
	extern long pktRepository_i_3_r_2_t_5_cnt;
	extern long pktRepository_i_3_r_2_t_6_cnt;
	extern long pktRepository_i_3_r_2_t_7_cnt;
	extern long pktRepository_i_3_r_2_t_8_cnt;
	extern long pktRepository_i_3_r_2_t_9_cnt;

	extern bool pktRepository_i_3_r_2_t_0_busy;
	extern bool pktRepository_i_3_r_2_t_1_busy;
	extern bool pktRepository_i_3_r_2_t_2_busy;
	extern bool pktRepository_i_3_r_2_t_3_busy;
	extern bool pktRepository_i_3_r_2_t_4_busy;
	extern bool pktRepository_i_3_r_2_t_5_busy;
	extern bool pktRepository_i_3_r_2_t_6_busy;
	extern bool pktRepository_i_3_r_2_t_7_busy;
	extern bool pktRepository_i_3_r_2_t_8_busy;
	extern bool pktRepository_i_3_r_2_t_9_busy;

	extern std::unordered_map<long, RawPkt*> pktRepository_i_3_r_3_t_0;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_3_r_3_t_1;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_3_r_3_t_2;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_3_r_3_t_3;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_3_r_3_t_4;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_3_r_3_t_5;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_3_r_3_t_6;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_3_r_3_t_7;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_3_r_3_t_8;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_3_r_3_t_9;

	extern long pktRepository_i_3_r_3_t_0_cnt;
	extern long pktRepository_i_3_r_3_t_1_cnt;
	extern long pktRepository_i_3_r_3_t_2_cnt;
	extern long pktRepository_i_3_r_3_t_3_cnt;
	extern long pktRepository_i_3_r_3_t_4_cnt;
	extern long pktRepository_i_3_r_3_t_5_cnt;
	extern long pktRepository_i_3_r_3_t_6_cnt;
	extern long pktRepository_i_3_r_3_t_7_cnt;
	extern long pktRepository_i_3_r_3_t_8_cnt;
	extern long pktRepository_i_3_r_3_t_9_cnt;

	extern bool pktRepository_i_3_r_3_t_0_busy;
	extern bool pktRepository_i_3_r_3_t_1_busy;
	extern bool pktRepository_i_3_r_3_t_2_busy;
	extern bool pktRepository_i_3_r_3_t_3_busy;
	extern bool pktRepository_i_3_r_3_t_4_busy;
	extern bool pktRepository_i_3_r_3_t_5_busy;
	extern bool pktRepository_i_3_r_3_t_6_busy;
	extern bool pktRepository_i_3_r_3_t_7_busy;
	extern bool pktRepository_i_3_r_3_t_8_busy;
	extern bool pktRepository_i_3_r_3_t_9_busy;

	extern std::unordered_map<long, RawPkt*> pktRepository_i_3_r_4_t_0;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_3_r_4_t_1;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_3_r_4_t_2;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_3_r_4_t_3;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_3_r_4_t_4;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_3_r_4_t_5;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_3_r_4_t_6;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_3_r_4_t_7;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_3_r_4_t_8;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_3_r_4_t_9;

	extern long pktRepository_i_3_r_4_t_0_cnt;
	extern long pktRepository_i_3_r_4_t_1_cnt;
	extern long pktRepository_i_3_r_4_t_2_cnt;
	extern long pktRepository_i_3_r_4_t_3_cnt;
	extern long pktRepository_i_3_r_4_t_4_cnt;
	extern long pktRepository_i_3_r_4_t_5_cnt;
	extern long pktRepository_i_3_r_4_t_6_cnt;
	extern long pktRepository_i_3_r_4_t_7_cnt;
	extern long pktRepository_i_3_r_4_t_8_cnt;
	extern long pktRepository_i_3_r_4_t_9_cnt;

	extern bool pktRepository_i_3_r_4_t_0_busy;
	extern bool pktRepository_i_3_r_4_t_1_busy;
	extern bool pktRepository_i_3_r_4_t_2_busy;
	extern bool pktRepository_i_3_r_4_t_3_busy;
	extern bool pktRepository_i_3_r_4_t_4_busy;
	extern bool pktRepository_i_3_r_4_t_5_busy;
	extern bool pktRepository_i_3_r_4_t_6_busy;
	extern bool pktRepository_i_3_r_4_t_7_busy;
	extern bool pktRepository_i_3_r_4_t_8_busy;
	extern bool pktRepository_i_3_r_4_t_9_busy;

	extern std::unordered_map<long, RawPkt*> pktRepository_i_3_r_5_t_0;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_3_r_5_t_1;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_3_r_5_t_2;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_3_r_5_t_3;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_3_r_5_t_4;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_3_r_5_t_5;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_3_r_5_t_6;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_3_r_5_t_7;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_3_r_5_t_8;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_3_r_5_t_9;

	extern long pktRepository_i_3_r_5_t_0_cnt;
	extern long pktRepository_i_3_r_5_t_1_cnt;
	extern long pktRepository_i_3_r_5_t_2_cnt;
	extern long pktRepository_i_3_r_5_t_3_cnt;
	extern long pktRepository_i_3_r_5_t_4_cnt;
	extern long pktRepository_i_3_r_5_t_5_cnt;
	extern long pktRepository_i_3_r_5_t_6_cnt;
	extern long pktRepository_i_3_r_5_t_7_cnt;
	extern long pktRepository_i_3_r_5_t_8_cnt;
	extern long pktRepository_i_3_r_5_t_9_cnt;

	extern bool pktRepository_i_3_r_5_t_0_busy;
	extern bool pktRepository_i_3_r_5_t_1_busy;
	extern bool pktRepository_i_3_r_5_t_2_busy;
	extern bool pktRepository_i_3_r_5_t_3_busy;
	extern bool pktRepository_i_3_r_5_t_4_busy;
	extern bool pktRepository_i_3_r_5_t_5_busy;
	extern bool pktRepository_i_3_r_5_t_6_busy;
	extern bool pktRepository_i_3_r_5_t_7_busy;
	extern bool pktRepository_i_3_r_5_t_8_busy;
	extern bool pktRepository_i_3_r_5_t_9_busy;

	extern std::unordered_map<long, RawPkt*> pktRepository_i_3_r_6_t_0;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_3_r_6_t_1;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_3_r_6_t_2;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_3_r_6_t_3;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_3_r_6_t_4;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_3_r_6_t_5;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_3_r_6_t_6;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_3_r_6_t_7;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_3_r_6_t_8;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_3_r_6_t_9;

	extern long pktRepository_i_3_r_6_t_0_cnt;
	extern long pktRepository_i_3_r_6_t_1_cnt;
	extern long pktRepository_i_3_r_6_t_2_cnt;
	extern long pktRepository_i_3_r_6_t_3_cnt;
	extern long pktRepository_i_3_r_6_t_4_cnt;
	extern long pktRepository_i_3_r_6_t_5_cnt;
	extern long pktRepository_i_3_r_6_t_6_cnt;
	extern long pktRepository_i_3_r_6_t_7_cnt;
	extern long pktRepository_i_3_r_6_t_8_cnt;
	extern long pktRepository_i_3_r_6_t_9_cnt;

	extern bool pktRepository_i_3_r_6_t_0_busy;
	extern bool pktRepository_i_3_r_6_t_1_busy;
	extern bool pktRepository_i_3_r_6_t_2_busy;
	extern bool pktRepository_i_3_r_6_t_3_busy;
	extern bool pktRepository_i_3_r_6_t_4_busy;
	extern bool pktRepository_i_3_r_6_t_5_busy;
	extern bool pktRepository_i_3_r_6_t_6_busy;
	extern bool pktRepository_i_3_r_6_t_7_busy;
	extern bool pktRepository_i_3_r_6_t_8_busy;
	extern bool pktRepository_i_3_r_6_t_9_busy;

	extern std::unordered_map<long, RawPkt*> pktRepository_i_3_r_7_t_0;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_3_r_7_t_1;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_3_r_7_t_2;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_3_r_7_t_3;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_3_r_7_t_4;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_3_r_7_t_5;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_3_r_7_t_6;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_3_r_7_t_7;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_3_r_7_t_8;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_3_r_7_t_9;

	extern long pktRepository_i_3_r_7_t_0_cnt;
	extern long pktRepository_i_3_r_7_t_1_cnt;
	extern long pktRepository_i_3_r_7_t_2_cnt;
	extern long pktRepository_i_3_r_7_t_3_cnt;
	extern long pktRepository_i_3_r_7_t_4_cnt;
	extern long pktRepository_i_3_r_7_t_5_cnt;
	extern long pktRepository_i_3_r_7_t_6_cnt;
	extern long pktRepository_i_3_r_7_t_7_cnt;
	extern long pktRepository_i_3_r_7_t_8_cnt;
	extern long pktRepository_i_3_r_7_t_9_cnt;

	extern bool pktRepository_i_3_r_7_t_0_busy;
	extern bool pktRepository_i_3_r_7_t_1_busy;
	extern bool pktRepository_i_3_r_7_t_2_busy;
	extern bool pktRepository_i_3_r_7_t_3_busy;
	extern bool pktRepository_i_3_r_7_t_4_busy;
	extern bool pktRepository_i_3_r_7_t_5_busy;
	extern bool pktRepository_i_3_r_7_t_6_busy;
	extern bool pktRepository_i_3_r_7_t_7_busy;
	extern bool pktRepository_i_3_r_7_t_8_busy;
	extern bool pktRepository_i_3_r_7_t_9_busy;

	/* Interface_4 */
	extern std::unordered_map<long, RawPkt*> pktRepository_i_4_r_0_t_0;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_4_r_0_t_1;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_4_r_0_t_2;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_4_r_0_t_3;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_4_r_0_t_4;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_4_r_0_t_5;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_4_r_0_t_6;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_4_r_0_t_7;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_4_r_0_t_8;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_4_r_0_t_9;

	extern long pktRepository_i_4_r_0_t_0_cnt;
	extern long pktRepository_i_4_r_0_t_1_cnt;
	extern long pktRepository_i_4_r_0_t_2_cnt;
	extern long pktRepository_i_4_r_0_t_3_cnt;
	extern long pktRepository_i_4_r_0_t_4_cnt;
	extern long pktRepository_i_4_r_0_t_5_cnt;
	extern long pktRepository_i_4_r_0_t_6_cnt;
	extern long pktRepository_i_4_r_0_t_7_cnt;
	extern long pktRepository_i_4_r_0_t_8_cnt;
	extern long pktRepository_i_4_r_0_t_9_cnt;

	extern bool pktRepository_i_4_r_0_t_0_busy;
	extern bool pktRepository_i_4_r_0_t_1_busy;
	extern bool pktRepository_i_4_r_0_t_2_busy;
	extern bool pktRepository_i_4_r_0_t_3_busy;
	extern bool pktRepository_i_4_r_0_t_4_busy;
	extern bool pktRepository_i_4_r_0_t_5_busy;
	extern bool pktRepository_i_4_r_0_t_6_busy;
	extern bool pktRepository_i_4_r_0_t_7_busy;
	extern bool pktRepository_i_4_r_0_t_8_busy;
	extern bool pktRepository_i_4_r_0_t_9_busy;

	extern std::unordered_map<long, RawPkt*> pktRepository_i_4_r_1_t_0;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_4_r_1_t_1;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_4_r_1_t_2;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_4_r_1_t_3;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_4_r_1_t_4;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_4_r_1_t_5;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_4_r_1_t_6;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_4_r_1_t_7;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_4_r_1_t_8;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_4_r_1_t_9;

	extern long pktRepository_i_4_r_1_t_0_cnt;
	extern long pktRepository_i_4_r_1_t_1_cnt;
	extern long pktRepository_i_4_r_1_t_2_cnt;
	extern long pktRepository_i_4_r_1_t_3_cnt;
	extern long pktRepository_i_4_r_1_t_4_cnt;
	extern long pktRepository_i_4_r_1_t_5_cnt;
	extern long pktRepository_i_4_r_1_t_6_cnt;
	extern long pktRepository_i_4_r_1_t_7_cnt;
	extern long pktRepository_i_4_r_1_t_8_cnt;
	extern long pktRepository_i_4_r_1_t_9_cnt;

	extern bool pktRepository_i_4_r_1_t_0_busy;
	extern bool pktRepository_i_4_r_1_t_1_busy;
	extern bool pktRepository_i_4_r_1_t_2_busy;
	extern bool pktRepository_i_4_r_1_t_3_busy;
	extern bool pktRepository_i_4_r_1_t_4_busy;
	extern bool pktRepository_i_4_r_1_t_5_busy;
	extern bool pktRepository_i_4_r_1_t_6_busy;
	extern bool pktRepository_i_4_r_1_t_7_busy;
	extern bool pktRepository_i_4_r_1_t_8_busy;
	extern bool pktRepository_i_4_r_1_t_9_busy;

	extern std::unordered_map<long, RawPkt*> pktRepository_i_4_r_2_t_0;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_4_r_2_t_1;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_4_r_2_t_2;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_4_r_2_t_3;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_4_r_2_t_4;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_4_r_2_t_5;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_4_r_2_t_6;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_4_r_2_t_7;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_4_r_2_t_8;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_4_r_2_t_9;

	extern long pktRepository_i_4_r_2_t_0_cnt;
	extern long pktRepository_i_4_r_2_t_1_cnt;
	extern long pktRepository_i_4_r_2_t_2_cnt;
	extern long pktRepository_i_4_r_2_t_3_cnt;
	extern long pktRepository_i_4_r_2_t_4_cnt;
	extern long pktRepository_i_4_r_2_t_5_cnt;
	extern long pktRepository_i_4_r_2_t_6_cnt;
	extern long pktRepository_i_4_r_2_t_7_cnt;
	extern long pktRepository_i_4_r_2_t_8_cnt;
	extern long pktRepository_i_4_r_2_t_9_cnt;

	extern bool pktRepository_i_4_r_2_t_0_busy;
	extern bool pktRepository_i_4_r_2_t_1_busy;
	extern bool pktRepository_i_4_r_2_t_2_busy;
	extern bool pktRepository_i_4_r_2_t_3_busy;
	extern bool pktRepository_i_4_r_2_t_4_busy;
	extern bool pktRepository_i_4_r_2_t_5_busy;
	extern bool pktRepository_i_4_r_2_t_6_busy;
	extern bool pktRepository_i_4_r_2_t_7_busy;
	extern bool pktRepository_i_4_r_2_t_8_busy;
	extern bool pktRepository_i_4_r_2_t_9_busy;

	extern std::unordered_map<long, RawPkt*> pktRepository_i_4_r_3_t_0;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_4_r_3_t_1;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_4_r_3_t_2;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_4_r_3_t_3;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_4_r_3_t_4;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_4_r_3_t_5;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_4_r_3_t_6;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_4_r_3_t_7;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_4_r_3_t_8;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_4_r_3_t_9;

	extern long pktRepository_i_4_r_3_t_0_cnt;
	extern long pktRepository_i_4_r_3_t_1_cnt;
	extern long pktRepository_i_4_r_3_t_2_cnt;
	extern long pktRepository_i_4_r_3_t_3_cnt;
	extern long pktRepository_i_4_r_3_t_4_cnt;
	extern long pktRepository_i_4_r_3_t_5_cnt;
	extern long pktRepository_i_4_r_3_t_6_cnt;
	extern long pktRepository_i_4_r_3_t_7_cnt;
	extern long pktRepository_i_4_r_3_t_8_cnt;
	extern long pktRepository_i_4_r_3_t_9_cnt;

	extern bool pktRepository_i_4_r_3_t_0_busy;
	extern bool pktRepository_i_4_r_3_t_1_busy;
	extern bool pktRepository_i_4_r_3_t_2_busy;
	extern bool pktRepository_i_4_r_3_t_3_busy;
	extern bool pktRepository_i_4_r_3_t_4_busy;
	extern bool pktRepository_i_4_r_3_t_5_busy;
	extern bool pktRepository_i_4_r_3_t_6_busy;
	extern bool pktRepository_i_4_r_3_t_7_busy;
	extern bool pktRepository_i_4_r_3_t_8_busy;
	extern bool pktRepository_i_4_r_3_t_9_busy;

	extern std::unordered_map<long, RawPkt*> pktRepository_i_4_r_4_t_0;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_4_r_4_t_1;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_4_r_4_t_2;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_4_r_4_t_3;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_4_r_4_t_4;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_4_r_4_t_5;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_4_r_4_t_6;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_4_r_4_t_7;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_4_r_4_t_8;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_4_r_4_t_9;

	extern long pktRepository_i_4_r_4_t_0_cnt;
	extern long pktRepository_i_4_r_4_t_1_cnt;
	extern long pktRepository_i_4_r_4_t_2_cnt;
	extern long pktRepository_i_4_r_4_t_3_cnt;
	extern long pktRepository_i_4_r_4_t_4_cnt;
	extern long pktRepository_i_4_r_4_t_5_cnt;
	extern long pktRepository_i_4_r_4_t_6_cnt;
	extern long pktRepository_i_4_r_4_t_7_cnt;
	extern long pktRepository_i_4_r_4_t_8_cnt;
	extern long pktRepository_i_4_r_4_t_9_cnt;

	extern bool pktRepository_i_4_r_4_t_0_busy;
	extern bool pktRepository_i_4_r_4_t_1_busy;
	extern bool pktRepository_i_4_r_4_t_2_busy;
	extern bool pktRepository_i_4_r_4_t_3_busy;
	extern bool pktRepository_i_4_r_4_t_4_busy;
	extern bool pktRepository_i_4_r_4_t_5_busy;
	extern bool pktRepository_i_4_r_4_t_6_busy;
	extern bool pktRepository_i_4_r_4_t_7_busy;
	extern bool pktRepository_i_4_r_4_t_8_busy;
	extern bool pktRepository_i_4_r_4_t_9_busy;

	extern std::unordered_map<long, RawPkt*> pktRepository_i_4_r_5_t_0;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_4_r_5_t_1;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_4_r_5_t_2;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_4_r_5_t_3;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_4_r_5_t_4;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_4_r_5_t_5;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_4_r_5_t_6;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_4_r_5_t_7;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_4_r_5_t_8;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_4_r_5_t_9;

	extern long pktRepository_i_4_r_5_t_0_cnt;
	extern long pktRepository_i_4_r_5_t_1_cnt;
	extern long pktRepository_i_4_r_5_t_2_cnt;
	extern long pktRepository_i_4_r_5_t_3_cnt;
	extern long pktRepository_i_4_r_5_t_4_cnt;
	extern long pktRepository_i_4_r_5_t_5_cnt;
	extern long pktRepository_i_4_r_5_t_6_cnt;
	extern long pktRepository_i_4_r_5_t_7_cnt;
	extern long pktRepository_i_4_r_5_t_8_cnt;
	extern long pktRepository_i_4_r_5_t_9_cnt;

	extern bool pktRepository_i_4_r_5_t_0_busy;
	extern bool pktRepository_i_4_r_5_t_1_busy;
	extern bool pktRepository_i_4_r_5_t_2_busy;
	extern bool pktRepository_i_4_r_5_t_3_busy;
	extern bool pktRepository_i_4_r_5_t_4_busy;
	extern bool pktRepository_i_4_r_5_t_5_busy;
	extern bool pktRepository_i_4_r_5_t_6_busy;
	extern bool pktRepository_i_4_r_5_t_7_busy;
	extern bool pktRepository_i_4_r_5_t_8_busy;
	extern bool pktRepository_i_4_r_5_t_9_busy;

	extern std::unordered_map<long, RawPkt*> pktRepository_i_4_r_6_t_0;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_4_r_6_t_1;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_4_r_6_t_2;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_4_r_6_t_3;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_4_r_6_t_4;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_4_r_6_t_5;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_4_r_6_t_6;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_4_r_6_t_7;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_4_r_6_t_8;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_4_r_6_t_9;

	extern long pktRepository_i_4_r_6_t_0_cnt;
	extern long pktRepository_i_4_r_6_t_1_cnt;
	extern long pktRepository_i_4_r_6_t_2_cnt;
	extern long pktRepository_i_4_r_6_t_3_cnt;
	extern long pktRepository_i_4_r_6_t_4_cnt;
	extern long pktRepository_i_4_r_6_t_5_cnt;
	extern long pktRepository_i_4_r_6_t_6_cnt;
	extern long pktRepository_i_4_r_6_t_7_cnt;
	extern long pktRepository_i_4_r_6_t_8_cnt;
	extern long pktRepository_i_4_r_6_t_9_cnt;

	extern bool pktRepository_i_4_r_6_t_0_busy;
	extern bool pktRepository_i_4_r_6_t_1_busy;
	extern bool pktRepository_i_4_r_6_t_2_busy;
	extern bool pktRepository_i_4_r_6_t_3_busy;
	extern bool pktRepository_i_4_r_6_t_4_busy;
	extern bool pktRepository_i_4_r_6_t_5_busy;
	extern bool pktRepository_i_4_r_6_t_6_busy;
	extern bool pktRepository_i_4_r_6_t_7_busy;
	extern bool pktRepository_i_4_r_6_t_8_busy;
	extern bool pktRepository_i_4_r_6_t_9_busy;

	extern std::unordered_map<long, RawPkt*> pktRepository_i_4_r_7_t_0;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_4_r_7_t_1;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_4_r_7_t_2;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_4_r_7_t_3;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_4_r_7_t_4;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_4_r_7_t_5;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_4_r_7_t_6;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_4_r_7_t_7;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_4_r_7_t_8;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_4_r_7_t_9;

	extern long pktRepository_i_4_r_7_t_0_cnt;
	extern long pktRepository_i_4_r_7_t_1_cnt;
	extern long pktRepository_i_4_r_7_t_2_cnt;
	extern long pktRepository_i_4_r_7_t_3_cnt;
	extern long pktRepository_i_4_r_7_t_4_cnt;
	extern long pktRepository_i_4_r_7_t_5_cnt;
	extern long pktRepository_i_4_r_7_t_6_cnt;
	extern long pktRepository_i_4_r_7_t_7_cnt;
	extern long pktRepository_i_4_r_7_t_8_cnt;
	extern long pktRepository_i_4_r_7_t_9_cnt;

	extern bool pktRepository_i_4_r_7_t_0_busy;
	extern bool pktRepository_i_4_r_7_t_1_busy;
	extern bool pktRepository_i_4_r_7_t_2_busy;
	extern bool pktRepository_i_4_r_7_t_3_busy;
	extern bool pktRepository_i_4_r_7_t_4_busy;
	extern bool pktRepository_i_4_r_7_t_5_busy;
	extern bool pktRepository_i_4_r_7_t_6_busy;
	extern bool pktRepository_i_4_r_7_t_7_busy;
	extern bool pktRepository_i_4_r_7_t_8_busy;
	extern bool pktRepository_i_4_r_7_t_9_busy;

	/* Interface_5 */
	extern std::unordered_map<long, RawPkt*> pktRepository_i_5_r_0_t_0;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_5_r_0_t_1;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_5_r_0_t_2;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_5_r_0_t_3;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_5_r_0_t_4;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_5_r_0_t_5;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_5_r_0_t_6;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_5_r_0_t_7;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_5_r_0_t_8;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_5_r_0_t_9;

	extern long pktRepository_i_5_r_0_t_0_cnt;
	extern long pktRepository_i_5_r_0_t_1_cnt;
	extern long pktRepository_i_5_r_0_t_2_cnt;
	extern long pktRepository_i_5_r_0_t_3_cnt;
	extern long pktRepository_i_5_r_0_t_4_cnt;
	extern long pktRepository_i_5_r_0_t_5_cnt;
	extern long pktRepository_i_5_r_0_t_6_cnt;
	extern long pktRepository_i_5_r_0_t_7_cnt;
	extern long pktRepository_i_5_r_0_t_8_cnt;
	extern long pktRepository_i_5_r_0_t_9_cnt;

	extern bool pktRepository_i_5_r_0_t_0_busy;
	extern bool pktRepository_i_5_r_0_t_1_busy;
	extern bool pktRepository_i_5_r_0_t_2_busy;
	extern bool pktRepository_i_5_r_0_t_3_busy;
	extern bool pktRepository_i_5_r_0_t_4_busy;
	extern bool pktRepository_i_5_r_0_t_5_busy;
	extern bool pktRepository_i_5_r_0_t_6_busy;
	extern bool pktRepository_i_5_r_0_t_7_busy;
	extern bool pktRepository_i_5_r_0_t_8_busy;
	extern bool pktRepository_i_5_r_0_t_9_busy;

	extern std::unordered_map<long, RawPkt*> pktRepository_i_5_r_1_t_0;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_5_r_1_t_1;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_5_r_1_t_2;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_5_r_1_t_3;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_5_r_1_t_4;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_5_r_1_t_5;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_5_r_1_t_6;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_5_r_1_t_7;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_5_r_1_t_8;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_5_r_1_t_9;

	extern long pktRepository_i_5_r_1_t_0_cnt;
	extern long pktRepository_i_5_r_1_t_1_cnt;
	extern long pktRepository_i_5_r_1_t_2_cnt;
	extern long pktRepository_i_5_r_1_t_3_cnt;
	extern long pktRepository_i_5_r_1_t_4_cnt;
	extern long pktRepository_i_5_r_1_t_5_cnt;
	extern long pktRepository_i_5_r_1_t_6_cnt;
	extern long pktRepository_i_5_r_1_t_7_cnt;
	extern long pktRepository_i_5_r_1_t_8_cnt;
	extern long pktRepository_i_5_r_1_t_9_cnt;

	extern bool pktRepository_i_5_r_1_t_0_busy;
	extern bool pktRepository_i_5_r_1_t_1_busy;
	extern bool pktRepository_i_5_r_1_t_2_busy;
	extern bool pktRepository_i_5_r_1_t_3_busy;
	extern bool pktRepository_i_5_r_1_t_4_busy;
	extern bool pktRepository_i_5_r_1_t_5_busy;
	extern bool pktRepository_i_5_r_1_t_6_busy;
	extern bool pktRepository_i_5_r_1_t_7_busy;
	extern bool pktRepository_i_5_r_1_t_8_busy;
	extern bool pktRepository_i_5_r_1_t_9_busy;

	extern std::unordered_map<long, RawPkt*> pktRepository_i_5_r_2_t_0;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_5_r_2_t_1;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_5_r_2_t_2;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_5_r_2_t_3;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_5_r_2_t_4;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_5_r_2_t_5;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_5_r_2_t_6;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_5_r_2_t_7;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_5_r_2_t_8;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_5_r_2_t_9;

	extern long pktRepository_i_5_r_2_t_0_cnt;
	extern long pktRepository_i_5_r_2_t_1_cnt;
	extern long pktRepository_i_5_r_2_t_2_cnt;
	extern long pktRepository_i_5_r_2_t_3_cnt;
	extern long pktRepository_i_5_r_2_t_4_cnt;
	extern long pktRepository_i_5_r_2_t_5_cnt;
	extern long pktRepository_i_5_r_2_t_6_cnt;
	extern long pktRepository_i_5_r_2_t_7_cnt;
	extern long pktRepository_i_5_r_2_t_8_cnt;
	extern long pktRepository_i_5_r_2_t_9_cnt;

	extern bool pktRepository_i_5_r_2_t_0_busy;
	extern bool pktRepository_i_5_r_2_t_1_busy;
	extern bool pktRepository_i_5_r_2_t_2_busy;
	extern bool pktRepository_i_5_r_2_t_3_busy;
	extern bool pktRepository_i_5_r_2_t_4_busy;
	extern bool pktRepository_i_5_r_2_t_5_busy;
	extern bool pktRepository_i_5_r_2_t_6_busy;
	extern bool pktRepository_i_5_r_2_t_7_busy;
	extern bool pktRepository_i_5_r_2_t_8_busy;
	extern bool pktRepository_i_5_r_2_t_9_busy;

	extern std::unordered_map<long, RawPkt*> pktRepository_i_5_r_3_t_0;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_5_r_3_t_1;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_5_r_3_t_2;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_5_r_3_t_3;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_5_r_3_t_4;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_5_r_3_t_5;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_5_r_3_t_6;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_5_r_3_t_7;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_5_r_3_t_8;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_5_r_3_t_9;

	extern long pktRepository_i_5_r_3_t_0_cnt;
	extern long pktRepository_i_5_r_3_t_1_cnt;
	extern long pktRepository_i_5_r_3_t_2_cnt;
	extern long pktRepository_i_5_r_3_t_3_cnt;
	extern long pktRepository_i_5_r_3_t_4_cnt;
	extern long pktRepository_i_5_r_3_t_5_cnt;
	extern long pktRepository_i_5_r_3_t_6_cnt;
	extern long pktRepository_i_5_r_3_t_7_cnt;
	extern long pktRepository_i_5_r_3_t_8_cnt;
	extern long pktRepository_i_5_r_3_t_9_cnt;

	extern bool pktRepository_i_5_r_3_t_0_busy;
	extern bool pktRepository_i_5_r_3_t_1_busy;
	extern bool pktRepository_i_5_r_3_t_2_busy;
	extern bool pktRepository_i_5_r_3_t_3_busy;
	extern bool pktRepository_i_5_r_3_t_4_busy;
	extern bool pktRepository_i_5_r_3_t_5_busy;
	extern bool pktRepository_i_5_r_3_t_6_busy;
	extern bool pktRepository_i_5_r_3_t_7_busy;
	extern bool pktRepository_i_5_r_3_t_8_busy;
	extern bool pktRepository_i_5_r_3_t_9_busy;

	extern std::unordered_map<long, RawPkt*> pktRepository_i_5_r_4_t_0;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_5_r_4_t_1;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_5_r_4_t_2;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_5_r_4_t_3;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_5_r_4_t_4;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_5_r_4_t_5;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_5_r_4_t_6;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_5_r_4_t_7;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_5_r_4_t_8;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_5_r_4_t_9;

	extern long pktRepository_i_5_r_4_t_0_cnt;
	extern long pktRepository_i_5_r_4_t_1_cnt;
	extern long pktRepository_i_5_r_4_t_2_cnt;
	extern long pktRepository_i_5_r_4_t_3_cnt;
	extern long pktRepository_i_5_r_4_t_4_cnt;
	extern long pktRepository_i_5_r_4_t_5_cnt;
	extern long pktRepository_i_5_r_4_t_6_cnt;
	extern long pktRepository_i_5_r_4_t_7_cnt;
	extern long pktRepository_i_5_r_4_t_8_cnt;
	extern long pktRepository_i_5_r_4_t_9_cnt;

	extern bool pktRepository_i_5_r_4_t_0_busy;
	extern bool pktRepository_i_5_r_4_t_1_busy;
	extern bool pktRepository_i_5_r_4_t_2_busy;
	extern bool pktRepository_i_5_r_4_t_3_busy;
	extern bool pktRepository_i_5_r_4_t_4_busy;
	extern bool pktRepository_i_5_r_4_t_5_busy;
	extern bool pktRepository_i_5_r_4_t_6_busy;
	extern bool pktRepository_i_5_r_4_t_7_busy;
	extern bool pktRepository_i_5_r_4_t_8_busy;
	extern bool pktRepository_i_5_r_4_t_9_busy;

	extern std::unordered_map<long, RawPkt*> pktRepository_i_5_r_5_t_0;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_5_r_5_t_1;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_5_r_5_t_2;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_5_r_5_t_3;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_5_r_5_t_4;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_5_r_5_t_5;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_5_r_5_t_6;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_5_r_5_t_7;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_5_r_5_t_8;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_5_r_5_t_9;

	extern long pktRepository_i_5_r_5_t_0_cnt;
	extern long pktRepository_i_5_r_5_t_1_cnt;
	extern long pktRepository_i_5_r_5_t_2_cnt;
	extern long pktRepository_i_5_r_5_t_3_cnt;
	extern long pktRepository_i_5_r_5_t_4_cnt;
	extern long pktRepository_i_5_r_5_t_5_cnt;
	extern long pktRepository_i_5_r_5_t_6_cnt;
	extern long pktRepository_i_5_r_5_t_7_cnt;
	extern long pktRepository_i_5_r_5_t_8_cnt;
	extern long pktRepository_i_5_r_5_t_9_cnt;

	extern bool pktRepository_i_5_r_5_t_0_busy;
	extern bool pktRepository_i_5_r_5_t_1_busy;
	extern bool pktRepository_i_5_r_5_t_2_busy;
	extern bool pktRepository_i_5_r_5_t_3_busy;
	extern bool pktRepository_i_5_r_5_t_4_busy;
	extern bool pktRepository_i_5_r_5_t_5_busy;
	extern bool pktRepository_i_5_r_5_t_6_busy;
	extern bool pktRepository_i_5_r_5_t_7_busy;
	extern bool pktRepository_i_5_r_5_t_8_busy;
	extern bool pktRepository_i_5_r_5_t_9_busy;

	extern std::unordered_map<long, RawPkt*> pktRepository_i_5_r_6_t_0;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_5_r_6_t_1;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_5_r_6_t_2;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_5_r_6_t_3;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_5_r_6_t_4;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_5_r_6_t_5;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_5_r_6_t_6;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_5_r_6_t_7;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_5_r_6_t_8;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_5_r_6_t_9;

	extern long pktRepository_i_5_r_6_t_0_cnt;
	extern long pktRepository_i_5_r_6_t_1_cnt;
	extern long pktRepository_i_5_r_6_t_2_cnt;
	extern long pktRepository_i_5_r_6_t_3_cnt;
	extern long pktRepository_i_5_r_6_t_4_cnt;
	extern long pktRepository_i_5_r_6_t_5_cnt;
	extern long pktRepository_i_5_r_6_t_6_cnt;
	extern long pktRepository_i_5_r_6_t_7_cnt;
	extern long pktRepository_i_5_r_6_t_8_cnt;
	extern long pktRepository_i_5_r_6_t_9_cnt;

	extern bool pktRepository_i_5_r_6_t_0_busy;
	extern bool pktRepository_i_5_r_6_t_1_busy;
	extern bool pktRepository_i_5_r_6_t_2_busy;
	extern bool pktRepository_i_5_r_6_t_3_busy;
	extern bool pktRepository_i_5_r_6_t_4_busy;
	extern bool pktRepository_i_5_r_6_t_5_busy;
	extern bool pktRepository_i_5_r_6_t_6_busy;
	extern bool pktRepository_i_5_r_6_t_7_busy;
	extern bool pktRepository_i_5_r_6_t_8_busy;
	extern bool pktRepository_i_5_r_6_t_9_busy;

	extern std::unordered_map<long, RawPkt*> pktRepository_i_5_r_7_t_0;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_5_r_7_t_1;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_5_r_7_t_2;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_5_r_7_t_3;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_5_r_7_t_4;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_5_r_7_t_5;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_5_r_7_t_6;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_5_r_7_t_7;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_5_r_7_t_8;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_5_r_7_t_9;

	extern long pktRepository_i_5_r_7_t_0_cnt;
	extern long pktRepository_i_5_r_7_t_1_cnt;
	extern long pktRepository_i_5_r_7_t_2_cnt;
	extern long pktRepository_i_5_r_7_t_3_cnt;
	extern long pktRepository_i_5_r_7_t_4_cnt;
	extern long pktRepository_i_5_r_7_t_5_cnt;
	extern long pktRepository_i_5_r_7_t_6_cnt;
	extern long pktRepository_i_5_r_7_t_7_cnt;
	extern long pktRepository_i_5_r_7_t_8_cnt;
	extern long pktRepository_i_5_r_7_t_9_cnt;

	extern bool pktRepository_i_5_r_7_t_0_busy;
	extern bool pktRepository_i_5_r_7_t_1_busy;
	extern bool pktRepository_i_5_r_7_t_2_busy;
	extern bool pktRepository_i_5_r_7_t_3_busy;
	extern bool pktRepository_i_5_r_7_t_4_busy;
	extern bool pktRepository_i_5_r_7_t_5_busy;
	extern bool pktRepository_i_5_r_7_t_6_busy;
	extern bool pktRepository_i_5_r_7_t_7_busy;
	extern bool pktRepository_i_5_r_7_t_8_busy;
	extern bool pktRepository_i_5_r_7_t_9_busy;

	/* Interface_6 */
	extern std::unordered_map<long, RawPkt*> pktRepository_i_6_r_0_t_0;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_6_r_0_t_1;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_6_r_0_t_2;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_6_r_0_t_3;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_6_r_0_t_4;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_6_r_0_t_5;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_6_r_0_t_6;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_6_r_0_t_7;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_6_r_0_t_8;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_6_r_0_t_9;

	extern long pktRepository_i_6_r_0_t_0_cnt;
	extern long pktRepository_i_6_r_0_t_1_cnt;
	extern long pktRepository_i_6_r_0_t_2_cnt;
	extern long pktRepository_i_6_r_0_t_3_cnt;
	extern long pktRepository_i_6_r_0_t_4_cnt;
	extern long pktRepository_i_6_r_0_t_5_cnt;
	extern long pktRepository_i_6_r_0_t_6_cnt;
	extern long pktRepository_i_6_r_0_t_7_cnt;
	extern long pktRepository_i_6_r_0_t_8_cnt;
	extern long pktRepository_i_6_r_0_t_9_cnt;

	extern bool pktRepository_i_6_r_0_t_0_busy;
	extern bool pktRepository_i_6_r_0_t_1_busy;
	extern bool pktRepository_i_6_r_0_t_2_busy;
	extern bool pktRepository_i_6_r_0_t_3_busy;
	extern bool pktRepository_i_6_r_0_t_4_busy;
	extern bool pktRepository_i_6_r_0_t_5_busy;
	extern bool pktRepository_i_6_r_0_t_6_busy;
	extern bool pktRepository_i_6_r_0_t_7_busy;
	extern bool pktRepository_i_6_r_0_t_8_busy;
	extern bool pktRepository_i_6_r_0_t_9_busy;

	extern std::unordered_map<long, RawPkt*> pktRepository_i_6_r_1_t_0;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_6_r_1_t_1;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_6_r_1_t_2;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_6_r_1_t_3;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_6_r_1_t_4;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_6_r_1_t_5;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_6_r_1_t_6;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_6_r_1_t_7;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_6_r_1_t_8;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_6_r_1_t_9;

	extern long pktRepository_i_6_r_1_t_0_cnt;
	extern long pktRepository_i_6_r_1_t_1_cnt;
	extern long pktRepository_i_6_r_1_t_2_cnt;
	extern long pktRepository_i_6_r_1_t_3_cnt;
	extern long pktRepository_i_6_r_1_t_4_cnt;
	extern long pktRepository_i_6_r_1_t_5_cnt;
	extern long pktRepository_i_6_r_1_t_6_cnt;
	extern long pktRepository_i_6_r_1_t_7_cnt;
	extern long pktRepository_i_6_r_1_t_8_cnt;
	extern long pktRepository_i_6_r_1_t_9_cnt;

	extern bool pktRepository_i_6_r_1_t_0_busy;
	extern bool pktRepository_i_6_r_1_t_1_busy;
	extern bool pktRepository_i_6_r_1_t_2_busy;
	extern bool pktRepository_i_6_r_1_t_3_busy;
	extern bool pktRepository_i_6_r_1_t_4_busy;
	extern bool pktRepository_i_6_r_1_t_5_busy;
	extern bool pktRepository_i_6_r_1_t_6_busy;
	extern bool pktRepository_i_6_r_1_t_7_busy;
	extern bool pktRepository_i_6_r_1_t_8_busy;
	extern bool pktRepository_i_6_r_1_t_9_busy;

	extern std::unordered_map<long, RawPkt*> pktRepository_i_6_r_2_t_0;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_6_r_2_t_1;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_6_r_2_t_2;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_6_r_2_t_3;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_6_r_2_t_4;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_6_r_2_t_5;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_6_r_2_t_6;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_6_r_2_t_7;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_6_r_2_t_8;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_6_r_2_t_9;

	extern long pktRepository_i_6_r_2_t_0_cnt;
	extern long pktRepository_i_6_r_2_t_1_cnt;
	extern long pktRepository_i_6_r_2_t_2_cnt;
	extern long pktRepository_i_6_r_2_t_3_cnt;
	extern long pktRepository_i_6_r_2_t_4_cnt;
	extern long pktRepository_i_6_r_2_t_5_cnt;
	extern long pktRepository_i_6_r_2_t_6_cnt;
	extern long pktRepository_i_6_r_2_t_7_cnt;
	extern long pktRepository_i_6_r_2_t_8_cnt;
	extern long pktRepository_i_6_r_2_t_9_cnt;

	extern bool pktRepository_i_6_r_2_t_0_busy;
	extern bool pktRepository_i_6_r_2_t_1_busy;
	extern bool pktRepository_i_6_r_2_t_2_busy;
	extern bool pktRepository_i_6_r_2_t_3_busy;
	extern bool pktRepository_i_6_r_2_t_4_busy;
	extern bool pktRepository_i_6_r_2_t_5_busy;
	extern bool pktRepository_i_6_r_2_t_6_busy;
	extern bool pktRepository_i_6_r_2_t_7_busy;
	extern bool pktRepository_i_6_r_2_t_8_busy;
	extern bool pktRepository_i_6_r_2_t_9_busy;

	extern std::unordered_map<long, RawPkt*> pktRepository_i_6_r_3_t_0;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_6_r_3_t_1;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_6_r_3_t_2;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_6_r_3_t_3;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_6_r_3_t_4;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_6_r_3_t_5;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_6_r_3_t_6;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_6_r_3_t_7;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_6_r_3_t_8;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_6_r_3_t_9;

	extern long pktRepository_i_6_r_3_t_0_cnt;
	extern long pktRepository_i_6_r_3_t_1_cnt;
	extern long pktRepository_i_6_r_3_t_2_cnt;
	extern long pktRepository_i_6_r_3_t_3_cnt;
	extern long pktRepository_i_6_r_3_t_4_cnt;
	extern long pktRepository_i_6_r_3_t_5_cnt;
	extern long pktRepository_i_6_r_3_t_6_cnt;
	extern long pktRepository_i_6_r_3_t_7_cnt;
	extern long pktRepository_i_6_r_3_t_8_cnt;
	extern long pktRepository_i_6_r_3_t_9_cnt;

	extern bool pktRepository_i_6_r_3_t_0_busy;
	extern bool pktRepository_i_6_r_3_t_1_busy;
	extern bool pktRepository_i_6_r_3_t_2_busy;
	extern bool pktRepository_i_6_r_3_t_3_busy;
	extern bool pktRepository_i_6_r_3_t_4_busy;
	extern bool pktRepository_i_6_r_3_t_5_busy;
	extern bool pktRepository_i_6_r_3_t_6_busy;
	extern bool pktRepository_i_6_r_3_t_7_busy;
	extern bool pktRepository_i_6_r_3_t_8_busy;
	extern bool pktRepository_i_6_r_3_t_9_busy;

	extern std::unordered_map<long, RawPkt*> pktRepository_i_6_r_4_t_0;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_6_r_4_t_1;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_6_r_4_t_2;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_6_r_4_t_3;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_6_r_4_t_4;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_6_r_4_t_5;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_6_r_4_t_6;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_6_r_4_t_7;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_6_r_4_t_8;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_6_r_4_t_9;

	extern long pktRepository_i_6_r_4_t_0_cnt;
	extern long pktRepository_i_6_r_4_t_1_cnt;
	extern long pktRepository_i_6_r_4_t_2_cnt;
	extern long pktRepository_i_6_r_4_t_3_cnt;
	extern long pktRepository_i_6_r_4_t_4_cnt;
	extern long pktRepository_i_6_r_4_t_5_cnt;
	extern long pktRepository_i_6_r_4_t_6_cnt;
	extern long pktRepository_i_6_r_4_t_7_cnt;
	extern long pktRepository_i_6_r_4_t_8_cnt;
	extern long pktRepository_i_6_r_4_t_9_cnt;

	extern bool pktRepository_i_6_r_4_t_0_busy;
	extern bool pktRepository_i_6_r_4_t_1_busy;
	extern bool pktRepository_i_6_r_4_t_2_busy;
	extern bool pktRepository_i_6_r_4_t_3_busy;
	extern bool pktRepository_i_6_r_4_t_4_busy;
	extern bool pktRepository_i_6_r_4_t_5_busy;
	extern bool pktRepository_i_6_r_4_t_6_busy;
	extern bool pktRepository_i_6_r_4_t_7_busy;
	extern bool pktRepository_i_6_r_4_t_8_busy;
	extern bool pktRepository_i_6_r_4_t_9_busy;

	extern std::unordered_map<long, RawPkt*> pktRepository_i_6_r_5_t_0;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_6_r_5_t_1;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_6_r_5_t_2;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_6_r_5_t_3;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_6_r_5_t_4;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_6_r_5_t_5;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_6_r_5_t_6;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_6_r_5_t_7;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_6_r_5_t_8;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_6_r_5_t_9;

	extern long pktRepository_i_6_r_5_t_0_cnt;
	extern long pktRepository_i_6_r_5_t_1_cnt;
	extern long pktRepository_i_6_r_5_t_2_cnt;
	extern long pktRepository_i_6_r_5_t_3_cnt;
	extern long pktRepository_i_6_r_5_t_4_cnt;
	extern long pktRepository_i_6_r_5_t_5_cnt;
	extern long pktRepository_i_6_r_5_t_6_cnt;
	extern long pktRepository_i_6_r_5_t_7_cnt;
	extern long pktRepository_i_6_r_5_t_8_cnt;
	extern long pktRepository_i_6_r_5_t_9_cnt;

	extern bool pktRepository_i_6_r_5_t_0_busy;
	extern bool pktRepository_i_6_r_5_t_1_busy;
	extern bool pktRepository_i_6_r_5_t_2_busy;
	extern bool pktRepository_i_6_r_5_t_3_busy;
	extern bool pktRepository_i_6_r_5_t_4_busy;
	extern bool pktRepository_i_6_r_5_t_5_busy;
	extern bool pktRepository_i_6_r_5_t_6_busy;
	extern bool pktRepository_i_6_r_5_t_7_busy;
	extern bool pktRepository_i_6_r_5_t_8_busy;
	extern bool pktRepository_i_6_r_5_t_9_busy;

	extern std::unordered_map<long, RawPkt*> pktRepository_i_6_r_6_t_0;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_6_r_6_t_1;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_6_r_6_t_2;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_6_r_6_t_3;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_6_r_6_t_4;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_6_r_6_t_5;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_6_r_6_t_6;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_6_r_6_t_7;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_6_r_6_t_8;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_6_r_6_t_9;

	extern long pktRepository_i_6_r_6_t_0_cnt;
	extern long pktRepository_i_6_r_6_t_1_cnt;
	extern long pktRepository_i_6_r_6_t_2_cnt;
	extern long pktRepository_i_6_r_6_t_3_cnt;
	extern long pktRepository_i_6_r_6_t_4_cnt;
	extern long pktRepository_i_6_r_6_t_5_cnt;
	extern long pktRepository_i_6_r_6_t_6_cnt;
	extern long pktRepository_i_6_r_6_t_7_cnt;
	extern long pktRepository_i_6_r_6_t_8_cnt;
	extern long pktRepository_i_6_r_6_t_9_cnt;

	extern bool pktRepository_i_6_r_6_t_0_busy;
	extern bool pktRepository_i_6_r_6_t_1_busy;
	extern bool pktRepository_i_6_r_6_t_2_busy;
	extern bool pktRepository_i_6_r_6_t_3_busy;
	extern bool pktRepository_i_6_r_6_t_4_busy;
	extern bool pktRepository_i_6_r_6_t_5_busy;
	extern bool pktRepository_i_6_r_6_t_6_busy;
	extern bool pktRepository_i_6_r_6_t_7_busy;
	extern bool pktRepository_i_6_r_6_t_8_busy;
	extern bool pktRepository_i_6_r_6_t_9_busy;

	extern std::unordered_map<long, RawPkt*> pktRepository_i_6_r_7_t_0;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_6_r_7_t_1;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_6_r_7_t_2;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_6_r_7_t_3;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_6_r_7_t_4;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_6_r_7_t_5;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_6_r_7_t_6;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_6_r_7_t_7;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_6_r_7_t_8;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_6_r_7_t_9;

	extern long pktRepository_i_6_r_7_t_0_cnt;
	extern long pktRepository_i_6_r_7_t_1_cnt;
	extern long pktRepository_i_6_r_7_t_2_cnt;
	extern long pktRepository_i_6_r_7_t_3_cnt;
	extern long pktRepository_i_6_r_7_t_4_cnt;
	extern long pktRepository_i_6_r_7_t_5_cnt;
	extern long pktRepository_i_6_r_7_t_6_cnt;
	extern long pktRepository_i_6_r_7_t_7_cnt;
	extern long pktRepository_i_6_r_7_t_8_cnt;
	extern long pktRepository_i_6_r_7_t_9_cnt;

	extern bool pktRepository_i_6_r_7_t_0_busy;
	extern bool pktRepository_i_6_r_7_t_1_busy;
	extern bool pktRepository_i_6_r_7_t_2_busy;
	extern bool pktRepository_i_6_r_7_t_3_busy;
	extern bool pktRepository_i_6_r_7_t_4_busy;
	extern bool pktRepository_i_6_r_7_t_5_busy;
	extern bool pktRepository_i_6_r_7_t_6_busy;
	extern bool pktRepository_i_6_r_7_t_7_busy;
	extern bool pktRepository_i_6_r_7_t_8_busy;
	extern bool pktRepository_i_6_r_7_t_9_busy;

	/* Interface_7 */
	extern std::unordered_map<long, RawPkt*> pktRepository_i_7_r_0_t_0;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_7_r_0_t_1;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_7_r_0_t_2;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_7_r_0_t_3;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_7_r_0_t_4;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_7_r_0_t_5;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_7_r_0_t_6;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_7_r_0_t_7;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_7_r_0_t_8;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_7_r_0_t_9;

	extern long pktRepository_i_7_r_0_t_0_cnt;
	extern long pktRepository_i_7_r_0_t_1_cnt;
	extern long pktRepository_i_7_r_0_t_2_cnt;
	extern long pktRepository_i_7_r_0_t_3_cnt;
	extern long pktRepository_i_7_r_0_t_4_cnt;
	extern long pktRepository_i_7_r_0_t_5_cnt;
	extern long pktRepository_i_7_r_0_t_6_cnt;
	extern long pktRepository_i_7_r_0_t_7_cnt;
	extern long pktRepository_i_7_r_0_t_8_cnt;
	extern long pktRepository_i_7_r_0_t_9_cnt;

	extern bool pktRepository_i_7_r_0_t_0_busy;
	extern bool pktRepository_i_7_r_0_t_1_busy;
	extern bool pktRepository_i_7_r_0_t_2_busy;
	extern bool pktRepository_i_7_r_0_t_3_busy;
	extern bool pktRepository_i_7_r_0_t_4_busy;
	extern bool pktRepository_i_7_r_0_t_5_busy;
	extern bool pktRepository_i_7_r_0_t_6_busy;
	extern bool pktRepository_i_7_r_0_t_7_busy;
	extern bool pktRepository_i_7_r_0_t_8_busy;
	extern bool pktRepository_i_7_r_0_t_9_busy;

	extern std::unordered_map<long, RawPkt*> pktRepository_i_7_r_1_t_0;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_7_r_1_t_1;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_7_r_1_t_2;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_7_r_1_t_3;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_7_r_1_t_4;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_7_r_1_t_5;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_7_r_1_t_6;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_7_r_1_t_7;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_7_r_1_t_8;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_7_r_1_t_9;

	extern long pktRepository_i_7_r_1_t_0_cnt;
	extern long pktRepository_i_7_r_1_t_1_cnt;
	extern long pktRepository_i_7_r_1_t_2_cnt;
	extern long pktRepository_i_7_r_1_t_3_cnt;
	extern long pktRepository_i_7_r_1_t_4_cnt;
	extern long pktRepository_i_7_r_1_t_5_cnt;
	extern long pktRepository_i_7_r_1_t_6_cnt;
	extern long pktRepository_i_7_r_1_t_7_cnt;
	extern long pktRepository_i_7_r_1_t_8_cnt;
	extern long pktRepository_i_7_r_1_t_9_cnt;

	extern bool pktRepository_i_7_r_1_t_0_busy;
	extern bool pktRepository_i_7_r_1_t_1_busy;
	extern bool pktRepository_i_7_r_1_t_2_busy;
	extern bool pktRepository_i_7_r_1_t_3_busy;
	extern bool pktRepository_i_7_r_1_t_4_busy;
	extern bool pktRepository_i_7_r_1_t_5_busy;
	extern bool pktRepository_i_7_r_1_t_6_busy;
	extern bool pktRepository_i_7_r_1_t_7_busy;
	extern bool pktRepository_i_7_r_1_t_8_busy;
	extern bool pktRepository_i_7_r_1_t_9_busy;

	extern std::unordered_map<long, RawPkt*> pktRepository_i_7_r_2_t_0;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_7_r_2_t_1;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_7_r_2_t_2;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_7_r_2_t_3;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_7_r_2_t_4;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_7_r_2_t_5;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_7_r_2_t_6;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_7_r_2_t_7;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_7_r_2_t_8;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_7_r_2_t_9;

	extern long pktRepository_i_7_r_2_t_0_cnt;
	extern long pktRepository_i_7_r_2_t_1_cnt;
	extern long pktRepository_i_7_r_2_t_2_cnt;
	extern long pktRepository_i_7_r_2_t_3_cnt;
	extern long pktRepository_i_7_r_2_t_4_cnt;
	extern long pktRepository_i_7_r_2_t_5_cnt;
	extern long pktRepository_i_7_r_2_t_6_cnt;
	extern long pktRepository_i_7_r_2_t_7_cnt;
	extern long pktRepository_i_7_r_2_t_8_cnt;
	extern long pktRepository_i_7_r_2_t_9_cnt;

	extern bool pktRepository_i_7_r_2_t_0_busy;
	extern bool pktRepository_i_7_r_2_t_1_busy;
	extern bool pktRepository_i_7_r_2_t_2_busy;
	extern bool pktRepository_i_7_r_2_t_3_busy;
	extern bool pktRepository_i_7_r_2_t_4_busy;
	extern bool pktRepository_i_7_r_2_t_5_busy;
	extern bool pktRepository_i_7_r_2_t_6_busy;
	extern bool pktRepository_i_7_r_2_t_7_busy;
	extern bool pktRepository_i_7_r_2_t_8_busy;
	extern bool pktRepository_i_7_r_2_t_9_busy;

	extern std::unordered_map<long, RawPkt*> pktRepository_i_7_r_3_t_0;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_7_r_3_t_1;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_7_r_3_t_2;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_7_r_3_t_3;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_7_r_3_t_4;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_7_r_3_t_5;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_7_r_3_t_6;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_7_r_3_t_7;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_7_r_3_t_8;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_7_r_3_t_9;

	extern long pktRepository_i_7_r_3_t_0_cnt;
	extern long pktRepository_i_7_r_3_t_1_cnt;
	extern long pktRepository_i_7_r_3_t_2_cnt;
	extern long pktRepository_i_7_r_3_t_3_cnt;
	extern long pktRepository_i_7_r_3_t_4_cnt;
	extern long pktRepository_i_7_r_3_t_5_cnt;
	extern long pktRepository_i_7_r_3_t_6_cnt;
	extern long pktRepository_i_7_r_3_t_7_cnt;
	extern long pktRepository_i_7_r_3_t_8_cnt;
	extern long pktRepository_i_7_r_3_t_9_cnt;

	extern bool pktRepository_i_7_r_3_t_0_busy;
	extern bool pktRepository_i_7_r_3_t_1_busy;
	extern bool pktRepository_i_7_r_3_t_2_busy;
	extern bool pktRepository_i_7_r_3_t_3_busy;
	extern bool pktRepository_i_7_r_3_t_4_busy;
	extern bool pktRepository_i_7_r_3_t_5_busy;
	extern bool pktRepository_i_7_r_3_t_6_busy;
	extern bool pktRepository_i_7_r_3_t_7_busy;
	extern bool pktRepository_i_7_r_3_t_8_busy;
	extern bool pktRepository_i_7_r_3_t_9_busy;

	extern std::unordered_map<long, RawPkt*> pktRepository_i_7_r_4_t_0;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_7_r_4_t_1;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_7_r_4_t_2;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_7_r_4_t_3;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_7_r_4_t_4;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_7_r_4_t_5;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_7_r_4_t_6;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_7_r_4_t_7;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_7_r_4_t_8;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_7_r_4_t_9;

	extern long pktRepository_i_7_r_4_t_0_cnt;
	extern long pktRepository_i_7_r_4_t_1_cnt;
	extern long pktRepository_i_7_r_4_t_2_cnt;
	extern long pktRepository_i_7_r_4_t_3_cnt;
	extern long pktRepository_i_7_r_4_t_4_cnt;
	extern long pktRepository_i_7_r_4_t_5_cnt;
	extern long pktRepository_i_7_r_4_t_6_cnt;
	extern long pktRepository_i_7_r_4_t_7_cnt;
	extern long pktRepository_i_7_r_4_t_8_cnt;
	extern long pktRepository_i_7_r_4_t_9_cnt;

	extern bool pktRepository_i_7_r_4_t_0_busy;
	extern bool pktRepository_i_7_r_4_t_1_busy;
	extern bool pktRepository_i_7_r_4_t_2_busy;
	extern bool pktRepository_i_7_r_4_t_3_busy;
	extern bool pktRepository_i_7_r_4_t_4_busy;
	extern bool pktRepository_i_7_r_4_t_5_busy;
	extern bool pktRepository_i_7_r_4_t_6_busy;
	extern bool pktRepository_i_7_r_4_t_7_busy;
	extern bool pktRepository_i_7_r_4_t_8_busy;
	extern bool pktRepository_i_7_r_4_t_9_busy;

	extern std::unordered_map<long, RawPkt*> pktRepository_i_7_r_5_t_0;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_7_r_5_t_1;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_7_r_5_t_2;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_7_r_5_t_3;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_7_r_5_t_4;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_7_r_5_t_5;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_7_r_5_t_6;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_7_r_5_t_7;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_7_r_5_t_8;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_7_r_5_t_9;

	extern long pktRepository_i_7_r_5_t_0_cnt;
	extern long pktRepository_i_7_r_5_t_1_cnt;
	extern long pktRepository_i_7_r_5_t_2_cnt;
	extern long pktRepository_i_7_r_5_t_3_cnt;
	extern long pktRepository_i_7_r_5_t_4_cnt;
	extern long pktRepository_i_7_r_5_t_5_cnt;
	extern long pktRepository_i_7_r_5_t_6_cnt;
	extern long pktRepository_i_7_r_5_t_7_cnt;
	extern long pktRepository_i_7_r_5_t_8_cnt;
	extern long pktRepository_i_7_r_5_t_9_cnt;

	extern bool pktRepository_i_7_r_5_t_0_busy;
	extern bool pktRepository_i_7_r_5_t_1_busy;
	extern bool pktRepository_i_7_r_5_t_2_busy;
	extern bool pktRepository_i_7_r_5_t_3_busy;
	extern bool pktRepository_i_7_r_5_t_4_busy;
	extern bool pktRepository_i_7_r_5_t_5_busy;
	extern bool pktRepository_i_7_r_5_t_6_busy;
	extern bool pktRepository_i_7_r_5_t_7_busy;
	extern bool pktRepository_i_7_r_5_t_8_busy;
	extern bool pktRepository_i_7_r_5_t_9_busy;

	extern std::unordered_map<long, RawPkt*> pktRepository_i_7_r_6_t_0;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_7_r_6_t_1;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_7_r_6_t_2;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_7_r_6_t_3;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_7_r_6_t_4;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_7_r_6_t_5;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_7_r_6_t_6;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_7_r_6_t_7;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_7_r_6_t_8;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_7_r_6_t_9;

	extern long pktRepository_i_7_r_6_t_0_cnt;
	extern long pktRepository_i_7_r_6_t_1_cnt;
	extern long pktRepository_i_7_r_6_t_2_cnt;
	extern long pktRepository_i_7_r_6_t_3_cnt;
	extern long pktRepository_i_7_r_6_t_4_cnt;
	extern long pktRepository_i_7_r_6_t_5_cnt;
	extern long pktRepository_i_7_r_6_t_6_cnt;
	extern long pktRepository_i_7_r_6_t_7_cnt;
	extern long pktRepository_i_7_r_6_t_8_cnt;
	extern long pktRepository_i_7_r_6_t_9_cnt;

	extern bool pktRepository_i_7_r_6_t_0_busy;
	extern bool pktRepository_i_7_r_6_t_1_busy;
	extern bool pktRepository_i_7_r_6_t_2_busy;
	extern bool pktRepository_i_7_r_6_t_3_busy;
	extern bool pktRepository_i_7_r_6_t_4_busy;
	extern bool pktRepository_i_7_r_6_t_5_busy;
	extern bool pktRepository_i_7_r_6_t_6_busy;
	extern bool pktRepository_i_7_r_6_t_7_busy;
	extern bool pktRepository_i_7_r_6_t_8_busy;
	extern bool pktRepository_i_7_r_6_t_9_busy;

	extern std::unordered_map<long, RawPkt*> pktRepository_i_7_r_7_t_0;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_7_r_7_t_1;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_7_r_7_t_2;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_7_r_7_t_3;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_7_r_7_t_4;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_7_r_7_t_5;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_7_r_7_t_6;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_7_r_7_t_7;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_7_r_7_t_8;
	extern std::unordered_map<long, RawPkt*> pktRepository_i_7_r_7_t_9;

	extern long pktRepository_i_7_r_7_t_0_cnt;
	extern long pktRepository_i_7_r_7_t_1_cnt;
	extern long pktRepository_i_7_r_7_t_2_cnt;
	extern long pktRepository_i_7_r_7_t_3_cnt;
	extern long pktRepository_i_7_r_7_t_4_cnt;
	extern long pktRepository_i_7_r_7_t_5_cnt;
	extern long pktRepository_i_7_r_7_t_6_cnt;
	extern long pktRepository_i_7_r_7_t_7_cnt;
	extern long pktRepository_i_7_r_7_t_8_cnt;
	extern long pktRepository_i_7_r_7_t_9_cnt;

	extern bool pktRepository_i_7_r_7_t_0_busy;
	extern bool pktRepository_i_7_r_7_t_1_busy;
	extern bool pktRepository_i_7_r_7_t_2_busy;
	extern bool pktRepository_i_7_r_7_t_3_busy;
	extern bool pktRepository_i_7_r_7_t_4_busy;
	extern bool pktRepository_i_7_r_7_t_5_busy;
	extern bool pktRepository_i_7_r_7_t_6_busy;
	extern bool pktRepository_i_7_r_7_t_7_busy;
	extern bool pktRepository_i_7_r_7_t_8_busy;
	extern bool pktRepository_i_7_r_7_t_9_busy;

}

namespace s1mmeSessionLock {
	extern pthread_mutex_t lockCount;
	extern pthread_cond_t nonzero;
	extern unsigned count;
}

namespace vInterfaceLock {
	extern pthread_mutex_t readyMutex;
	extern pthread_cond_t  readyCond;
	extern int             readyCount;
}

namespace s5s8SessionLock {
	extern pthread_mutex_t lockCount;
	extern pthread_cond_t nonzero;
	extern unsigned count;
}

namespace s11SessionLock {
	extern pthread_mutex_t lockCount;
	extern pthread_cond_t nonzero;
	extern unsigned count;
}

namespace dnsSessionLock {
	extern pthread_mutex_t lockCount;
	extern pthread_cond_t nonzero;
	extern unsigned count;
}

namespace s1apSessionLock {
	extern pthread_mutex_t lockCount;
	extern pthread_cond_t nonzero;
	extern unsigned count;
}

#endif /* INC_IPGLOBAL_H_ */
