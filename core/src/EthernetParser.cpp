/*
 * EthernetProbe.cpp
 *
 *  Created on: 30-Jan-2016
 *      Author: Debashis
 */

#include <sys/time.h>
#include <arpa/inet.h>

#include "EthernetParser.h"

EthernetParser::EthernetParser(int intfid, int rId)
{
	this->_name = "EthernetParser ";
	this->setLogLevel(Log::theLog().level());

#ifdef _S1MME
	sctp = new SctpParser();
#endif
#ifdef _S11
	gtpc = new GTPcParser();
#endif
#ifdef _S1U
	gtpu = new GTPuParser();
#endif
	ip4Header = NULL;
	udpHeader = NULL;
	ptr_vlan_t = NULL;
	packet_size = vlan_id = type = vlan_tpid = 0;
}

EthernetParser::~EthernetParser()
{
#ifdef _S1MME
	delete (sctp);
#endif
#ifdef _S11
	delete (gtpc);
#endif
#ifdef _S1U
	delete (gtpu);
#endif
}

VOID EthernetParser::hexDump(const void* pv, int len)
{
  const unsigned char* p = (const unsigned char*) pv;
  int i;
  for( i = 0; i < len; ++i ) {
    const char* eos;
    switch( i & 15 ) {
    case 0:
      printf("%08x  ", i);
      eos = "";
      break;
    case 1:
      eos = " ";
      break;
    case 15:
      eos = "\n";
      break;
    default:
      eos = (i & 1) ? " " : "";
      break;
    }
    printf("%02x%s", (unsigned) p[i], eos);
  }
  printf(((len & 15) == 0) ? "\n" : "\n\n");
}

VOID EthernetParser::parsePacket(const BYTE packet, MPacket *msgObj)
{
    uint16_t type = packet[ethOffset] * 256 + packet[ethOffset+1];		/* Ethernet Containing Protocol */

    switch(type)
    {
    	case ETH_IP:
    			parseIPV4Packet(packet + sizeof(struct ether_header), msgObj);
    			break;

    	case ETH_8021Q:
    			parse8021QPacket(packet + sizeof(struct ether_header), msgObj);
    			break;

    	case ETH_MPLS_UC:
    			parseMPLSPacket(packet + sizeof(struct ether_header), msgObj);
    			break;

		default:
    		break;
    }
}

VOID EthernetParser::parseMPLSPacket(const BYTE packet, MPacket *msgObj)
{ parseIPV4Packet(packet + MPLS_PACKET_SIZE, msgObj); }

VOID EthernetParser::parse8021QPacket(const BYTE packet, MPacket *msgObj)
{
	ptr_vlan_t = (struct vlan_tag*)packet;
	packet_size = sizeof(struct vlan_tag);
	vlan_tpid = ntohs((unsigned short int)ptr_vlan_t->vlan_tpid);
	vlan_id = (uint16_t)(vlan_tpid & 0x0FFF);
	type = ntohs((unsigned short int)ptr_vlan_t->vlan_tci);

	msgObj->ethVLanId = vlan_id;

	switch(type)
	{
		case ETH_IP:
					parseIPV4Packet((const BYTE)(packet + packet_size), msgObj);
					break;

		case ETH_8021Q:
					parse8021QPacket((const BYTE)(packet + packet_size), msgObj);
					break;

		case ETH_PPP_SES:
					parsePPPoEPacket((const BYTE)packet + packet_size, msgObj);
					break;

		default:
					break;
	}
}


void EthernetParser::parsePPPoEPacket(const BYTE packet, MPacket *msgObj)
{ parseIPV4Packet((const BYTE)(packet + 8), msgObj); }


void EthernetParser::parseIPV4Packet(const BYTE packet, MPacket *msgObj)
{
	uint16_t offset = 12;

	ip4Header = (struct iphdr *)(packet);

	msgObj->ipTLen 		= ntohs((uint16_t)ip4Header->tot_len);
	msgObj->ipHLen 		= ((unsigned int)ip4Header->ihl)*4;

	msgObj->ipVer 		= ip4Header->version;

	if(msgObj->ipVer != IPVersion4)
	{
		msgObj->ipProtocol   = 0;
		msgObj->ipAppProtocol 	= 0;
		return;
	}

	msgObj->ipProtocol 	= ip4Header->protocol;
	msgObj->ipAppProtocol 	= ip4Header->protocol; // TCP or UDP

	switch(msgObj->ipAppProtocol)
	{
		case PACKET_IPPROTO_UDP:
		case PACKET_IPPROTO_SCTP:
				break;

		default:
				msgObj->ipProtocol = 0;
				msgObj->ipAppProtocol = 0;
				return;
				break;
	}

	msgObj->sourceIpAddrLong=(msgObj->sourceIpAddrLong << 8) + (0xff & packet[offset]);
	msgObj->sourceIpAddrLong=(msgObj->sourceIpAddrLong << 8) + (0xff & packet[offset + 1]);
	msgObj->sourceIpAddrLong=(msgObj->sourceIpAddrLong << 8) + (0xff & packet[offset + 2]);
	msgObj->sourceIpAddrLong=(msgObj->sourceIpAddrLong << 8) + (0xff & packet[offset + 3]);

	offset += 4;
	msgObj->destIpAddrLong=(msgObj->destIpAddrLong << 8) + (0xff & packet[offset]);
	msgObj->destIpAddrLong=(msgObj->destIpAddrLong << 8) + (0xff & packet[offset + 1]);
	msgObj->destIpAddrLong=(msgObj->destIpAddrLong << 8) + (0xff & packet[offset + 2]);
	msgObj->destIpAddrLong=(msgObj->destIpAddrLong << 8) + (0xff & packet[offset + 3]);

	if(msgObj->ipAppProtocol == PACKET_IPPROTO_UDP)
		getProtocolType(packet, msgObj);

	switch(msgObj->ipAppProtocol)
	{
		case PACKET_IPPROTO_GTPC:

			if(GContainer::config->S11_PROBE && GContainer::config->S5S8_PROBE)
				msgObj->interfaceType = getInterfaceType(msgObj->sourceIpAddrLong, msgObj->destIpAddrLong);
			else if(GContainer::config->S11_PROBE)
				msgObj->interfaceType = S11_INTERFACE;
			else if(GContainer::config->S5S8_PROBE)
				msgObj->interfaceType = S5S8_INTERFACE;
#ifdef _S11
			gtpc->parsePacket(packet + msgObj->ipHLen, msgObj);
#endif
			break;

		case PACKET_IPPROTO_GTPU:
			msgObj->interfaceType = S1U_INTERFACE;
#ifdef _S1U
			gtpu->parsePacket(packet + msgObj->ipHLen, msgObj);
#endif
			break;

		case PACKET_IPPROTO_SCTP:
			msgObj->interfaceType = S1MME_INTERFACE;
#ifdef _S1MME
			sctp->parsePacket(packet + msgObj->ipHLen, msgObj);
#endif
			break;

		default:
			break;
	}
}

uint16_t EthernetParser::getInterfaceType(uint32_t sourceIp, uint32_t destIp)
{
	uint16_t interf = 0;

	for(int counter = 0; counter <= IPGlobal::MME_NO_OF_RANGE; counter++)
	{
		if((sourceIp >= IPGlobal::MME_RANGE[counter][0] && sourceIp <= IPGlobal::MME_RANGE[counter][1]))
		{
			interf = S11_INTERFACE;
			break;
		}
		else if(destIp >= IPGlobal::MME_RANGE[counter][0] && destIp <= IPGlobal::MME_RANGE[counter][1])
		{
			interf = S11_INTERFACE;
			break;
		}
	}

	if(interf != 0) return interf;

	for(int counter = 0; counter <= IPGlobal::PGW_NO_OF_RANGE; counter++)
	{
		if(sourceIp >= IPGlobal::PGW_RANGE[counter][0] && sourceIp <= IPGlobal::PGW_RANGE[counter][1])
		{
			interf = S5S8_INTERFACE;
			break;
		}
		else if(destIp >= IPGlobal::PGW_RANGE[counter][0] && destIp <= IPGlobal::PGW_RANGE[counter][1])
		{
			interf = S5S8_INTERFACE;
			break;
		}
	}
	return interf;
}

VOID EthernetParser::getProtocolType(const BYTE packet, MPacket *msgObj)
{
	uint16_t	s_port, d_port;
	s_port = d_port = 0;

	udpHeader = (struct udphdr *)(packet + msgObj->ipHLen);

	s_port = ntohs((unsigned short int)udpHeader->source);
	d_port = ntohs((unsigned short int)udpHeader->dest);

	if((s_port == GTPC_PORT) || (s_port == GTPC_PORT1))
	{ msgObj->ipAppProtocol = PACKET_IPPROTO_GTPC; }
	else if((d_port == GTPC_PORT) || (d_port == GTPC_PORT1))
	{ msgObj->ipAppProtocol = PACKET_IPPROTO_GTPC; }
	else if(s_port == GTPU_PORT)
	{ msgObj->ipAppProtocol = PACKET_IPPROTO_GTPU; }
	else if(d_port == GTPU_PORT)
	{ msgObj->ipAppProtocol = PACKET_IPPROTO_GTPU; }
}
