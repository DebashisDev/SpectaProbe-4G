/*
 * EthernetProbe.h
 *
 *  Created on: 30-Jan-2016
 *      Author: Debashis
 */

#ifndef CORE_SRC_ETHERNETPARSER_H_
#define CORE_SRC_ETHERNETPARSER_H_

#include <string.h>
#include <algorithm>
#include <stdlib.h>    //malloc

#include "GTPGlobal.h"

#include <netinet/ether.h>
#include <netinet/if_ether.h>
#include <pcap/vlan.h>
#include <netinet/udp.h>
#include <netinet/in.h>
#include <netinet/ip6.h>
#include <netinet/ip.h>

#include "GTPuParser.h"
#include "GTPcParser.h"
#include "Log.h"
#include "BaseConfig.h"
#include "IPGlobal.h"
#include "ProbeUtility.h"
#include "SctpParser.h"

//#define ETH_P_MPLS 			34887
#define MPLS_PACKET_SIZE 	4
#define IPV6_HEADER_LEN		40
#define IPV6_STRSIZE 		46
#define BASE 				16

class EthernetParser : public BaseConfig
{
	private:
#ifdef _S1MME
		SctpParser		*sctp;
#endif
#ifdef _S11
		GTPcParser		*gtpc;
#endif
#ifdef _S1U
		GTPuParser		*gtpu;
#endif
		struct vlan_tag *ptr_vlan_t;
		uint8_t packet_size;
		uint16_t vlan_id;
		uint16_t type;
		uint16_t vlan_tpid;
		uint16_t ethOffset = 12;

		struct iphdr*		ip4Header;
		struct udphdr*		udpHeader;

		VOID 		parse8021QPacket(const BYTE packet, MPacket *msgObj);
		VOID		parseIPV4Packet(const BYTE packet, MPacket *msgObj);
		VOID 		parseMPLSPacket(const BYTE packet, MPacket *msgObj);
		VOID 		parsePPPoEPacket(const BYTE packet, MPacket *msgObj);

		VOID   	 	hexDump(const void* pv, int len);
		VOID 		getProtocolType(const BYTE packet, MPacket *msgObj);
		uint16_t	getInterfaceType(uint32_t sourceIp, uint32_t destIp);

	public:
		EthernetParser(int intfid, int rId);
		~EthernetParser();

		VOID 	parsePacket(const BYTE packet, MPacket *msgObj);
};


#endif /* CORE_SRC_ETHERNETPARSER_H_ */
