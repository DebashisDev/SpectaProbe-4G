/*
 * PUDP.cpp
 *
 *  Created on: Nov 14, 2015
 *      Author: Debashis
 */


#include <netinet/udp.h>
#include <netinet/in.h>
#include <sys/time.h>
#include <algorithm>

#include "UDPParser.h"

#define RAW_UDP false
#define RAW_DNS false
bool P_UDP_PACKETS = false;

using namespace std;
using namespace GContainer;

UDPParser::UDPParser()
{
	sourceInsideIp[0] 	= 0;
	sourceInsidePort 	= 0;
	sourceGlobalIp[0] 	= 0;
	sourceGlobalPort 	= 0;
	destinationIp[0] 	= 0;
	destinationPort 	= 0;
	protocol 			= 0;

	utility 			= new ProbeUtility();
	this->_name 		= "UDP";
	this->setLogLevel(Log::theLog().level());
}

UDPParser::~UDPParser()
{ delete (utility); }

VOID UDPParser::lockDnsMap()
{
	    pthread_mutex_lock(&dnsSessionLock::lockCount);
	    while (dnsSessionLock::count == 0)
	        pthread_cond_wait(&dnsSessionLock::nonzero, &dnsSessionLock::lockCount);
	    dnsSessionLock::count = dnsSessionLock::count - 1;
	    pthread_mutex_unlock(&dnsSessionLock::lockCount);
}

VOID UDPParser::unLockDnsMap()
{
    pthread_mutex_lock(&dnsSessionLock::lockCount);
    if (dnsSessionLock::count == 0)
        pthread_cond_signal(&dnsSessionLock::nonzero);
    dnsSessionLock::count = dnsSessionLock::count + 1;
    pthread_mutex_unlock(&dnsSessionLock::lockCount);
}

VOID UDPParser::parseUDPPacket(const BYTE packet, MPacket *msgObj)
{ 
	std::string URL, appProtocol;
	uint16_t ret = 0;
	ULONG sessionKey = 0;

	struct udphdr *udpHeader = (struct udphdr *)(packet);

 	msgObj->protoTLen = ntohs((unsigned short int)udpHeader->len);
	msgObj->protoSourcePort = ntohs((unsigned short int)udpHeader->source);
	msgObj->protoDestPort = ntohs((unsigned short int)udpHeader->dest);

	msgObj->protoPayload = msgObj->ipTLen - (msgObj->ipHLen + UDP_HDR_LEN);

    if((msgObj->protoSourcePort == DNS_PORT) || (msgObj->protoDestPort == DNS_PORT)) {
    	lockDnsMap();
   		parsePacketDNS(packet + UDP_HDR_LEN, msgObj); // Total Length of UDP message (8)
    	unLockDnsMap();
    }
    return;
}


VOID UDPParser::parsePacketDNS(const BYTE packet, MPacket *msgObj)
{
    uint32_t pos = 0, id_pos = 0, retPos = 0;

	if (msgObj->frSize - msgObj->protoTLen < 12)
	{ return; }

    msgObj->dnsTLen 			= msgObj->protoTLen - UDP_HDR_LEN;
    msgObj->dnsTransactionId 	= (packet[pos] << 8) + packet[pos+1];		// Transaction ID
    msgObj->dnsQRFlag 			= packet[pos+2] >> 7;					    // Query Response -> Question=0 and Answer=1

//    authoritative = (packet[pos+2] & 0x04) >> 2;
//    truncatedFlag = (packet[pos+2] & 0x02) >> 1;							// Truncated Message Flag

    /*
     * RCODE = 0 - No Error, 1- Format Error, 2- Server Error, 3- Name Error, 4- Not Implemented, 5- Refused.
     */

    switch(msgObj->dnsQRFlag)
    {
		case QUERY:
				qdcount = (packet[pos+4] << 8) + packet[pos+5];			// Query Count

				if(qdcount == 1)
					if(!parsePacketDNSQueries(pos + DNS_HDR_LEN, id_pos, msgObj, (const unsigned char *)packet, &retPos))
						return;
				break;

		case RESPONSE:
				ancount = (packet[pos+6] << 8) + packet[pos+7];			// Answer Count
				msgObj->dnsResponseCode = packet[pos + 3] & 0x0f;		// rcode will be there in case of Response (Answer = 1)

				if (msgObj->dnsResponseCode != 0) // Earlier 26
					return;

				if(qdcount == 1 && (ancount > 0 && ancount <= IPGlobal::S1U_DNS_ANSWER))
				{
					if(parsePacketDNSQueries((pos + DNS_HDR_LEN), id_pos, msgObj, (const unsigned char *)packet, &retPos))
					{
						if(msgObj->dnsResponseCode == 0)
							parsePacketDNSAnswers(retPos, msgObj, packet);
					}
					else
						return;
				}
				break;

		default:
				msgObj->dnsQRFlag 			= -1;		// Query Response -> Question=0 and Answer=1
				qdcount = ancount = 0;
				msgObj->dnsTLen 			= 0;
				msgObj->dnsTransactionId 	= 0;		// Transaction ID
				break;
    }
}

//    nscount = (packet[pos+8] << 8) + packet[pos+9];			// Authority count
//    arcount = (packet[pos+10] << 8) + packet[pos+11];		// Additional Information Count


BOOL UDPParser::parsePacketDNSQueries(uint32_t pos, uint32_t id_pos, MPacket *msgObj, const UCHAR *packet, uint32_t *retPos)
{
    uint16_t type = 0;
    std::string url;

    url = read_rr_name(packet, &pos, id_pos, msgObj->dnsTLen);
    std::replace(url.begin(), url.end(), ',', '.');

    if (url.compare("NULL") == 0)
    { return false; }

    if(url.length() >= URL_LEN)
    {
    	url = url.substr(url.length() - (URL_LEN - 1));
    	strcpy(msgObj->dnsName, url.c_str());
    }
    else
    { strcpy(msgObj->dnsName, url.c_str()); }

    url.clear();

    type = VAL_USHORT(packet+pos);

    if(type == 255) return false;	// 255 is for Any Ip Address

    *retPos = pos + 4;
    return true;
}

VOID UDPParser::parsePacketDNSAnswers(uint32_t pos, MPacket *msgObj, const BYTE packet)
{
	uint16_t type, dataLen, ttl;
	char ipv6Address[INET6_ADDRSTRLEN];

	std::string innerUrl = "";
	std::string ipAddress = "";
	std::string addressList = "";
	std::string userIP_resolveIP_key = "";
	
	dataLen = ttl = 0;

	if(ancount == 0) {
//		msgObj->dnsResponseCode = 25;		// No Answer Count
		msgObj->dnsResponseCode = 0;		// No Answer Count
		strcpy(msgObj->dnsIpAddress, "No Answer");
		return;
	}

	try
	{
		for(uint16_t ansCounter = 0; ansCounter < ancount; ansCounter++)
		{
			while(packet[pos] != 192) { // Reference Question Name Start with '0xc0' locate it
				pos += 1;
			}

			pos = pos + 2;												// Reference Question Name (2 Bytes)
			type = (packet[pos] << 8) + packet[pos + 1];

			pos = pos + 2;												// Type
			pos = pos + 2;												// Class

//			for (uint16_t i=0; i<4; i++)								// TTL 4 Bytes
//				ttl = (ttl << 8) + packet[pos+4+i];						//

			pos = pos + 4;												// TTL

			dataLen = (packet[pos] << 8) + packet[pos + 1];
			pos = pos + 2;												// Data Length

			uint32_t longResolvedIp = 0;

			switch(type)
			{
				case A:	/* IP4 Address */
					msgObj->dnsResponseCode = 0;

					longResolvedIp=(longResolvedIp << 8) + (0xff & packet[pos]);
					longResolvedIp=(longResolvedIp << 8) + (0xff & packet[pos + 1]);
					longResolvedIp=(longResolvedIp << 8) + (0xff & packet[pos + 2]);
					longResolvedIp=(longResolvedIp << 8) + (0xff & packet[pos + 3]);

					/* If Resolved Ip is 1.0.0.0 ~ 255.255.255.255 */
					if((longResolvedIp >= 16777216 && longResolvedIp <= 4294967295) && strlen(msgObj->dnsName) > 0)
					{
//						userIP_resolveIP_key = getDNSKey(msgObj->destIpAddrLong, longResolvedIp);
						updateDns(userIP_resolveIP_key, msgObj->destIpAddrLong, longResolvedIp, std::string(msgObj->dnsName), msgObj->frTimeEpochSec);

//						printf("Ipv4 %u| %s\n", longResolvedIp, msgObj->dnsName);
						addressList = "";
						addressList.assign(std::to_string(longResolvedIp));
					}

					/* 	Increment the pos to next Answer location
					 **	Name		(2 Bytes)	 **	Type		(2 Bytes)	 **	Class		(2 Bytes)
					 **	TTL 		(4 Bytes)	 **	Data Length (2 Bytes)	 **	Address		(4 Bytes)
					 **	Total Bytes:: 16 Bytes
					 */

					/* 2 Bytes already increased in case of Name */
					pos = pos + dataLen;

					break;

//				case AAAA: /* IP6 Address */
//					msgObj->dnsResponseCode = 0;
//					if(IPGlobal::IPV6_PROCESSING) {
//						utility->ExtractIP6Address((const unsigned char *)packet, ipv6Address, pos);
//
//						if((strlen(ipv6Address) == 39) && (strlen(msgObj->dnsName)) > 0)
//						{
//							userIP_resolveIP_key = string(msgObj->destIpAddrChar) + string(ipv6Address);
//							updateDnsV6(userIP_resolveIP_key, std::string(msgObj->destIpAddrChar), std::string(ipv6Address), std::string(msgObj->dnsName), msgObj->frTimeEpochSec);
//							ipAddress.assign((char *)ipv6Address);
////							printf("IPv6 %s| %s\n", ipv6Address, msgObj->dnsName);
//
//							addressList = "";
//							addressList.assign(ipAddress);
//						}
//					}
//					/* 	Increment the pos to next Answer location
//					 **	Name		(2  Bytes)	**	Type		(2  Bytes)	 **	Class		(2  Bytes)
//					 **	TTL 		(4  Bytes)  **	Data Length (2  Bytes)	 **	Address		(16 Bytes)
//					 **	Total Bytes:: 28 Bytes
//					 */
//
//					/* 2 Bytes already increased in case of Name */
//					pos = pos + dataLen;
//					ipv6Address[0] = 0;
//					break;

				default:
					addressList = "";
					addressList.assign("No HostAddress");
					pos = pos + dataLen;
					break;
			}
		}

		ipv6Address[0] = 0;
		ipAddress.clear();

		msgObj->dnsIpAddress[0] = 0;

		/* Check for Valid IPv4 & Ipv6 Address */
		if(addressList.length() > 8 && addressList.length() < 40 )
		{
			strcpy(msgObj->dnsIpAddress, addressList.c_str());
//			if(addressList.compare("No HostAddress") == 0) printf("DNS:: URL::%s| IP::%s\n", msgObj->dnsName, msgObj->dnsIpAddress);
		}
	}
	catch(const std::exception& e)
	{
		std::cout << " a standard exception was caught, with message '" << e.what() << "'\n";
	}
}

string UDPParser::read_rr_name(const uint8_t * packet, uint32_t * packet_p, uint32_t id_pos, uint16_t len)
{
    uint32_t i, next, pos=*packet_p;
    uint32_t end_pos = 0;
    uint32_t name_len=0;
    uint32_t steps = 0;
    //char *name;

    // Scan through the name, one character at a time. We need to look at
    // each character to look for values we can't print in order to allocate
    // extra space for escaping them.  'next' is the next position to look
    // for a compression jump or name end.
    // It's possible that there are endless loops in the name. Our protection
    // against this is to make sure we don't read more bytes in this process
    // than twice the length of the data.  Names that take that many steps to
    // read in should be impossible.
    next = pos;
    while (pos < len && !(next == pos && packet[pos] == 0) && steps < len*2) {
        uint8_t c = packet[pos];
        steps++;
        if (next == pos) {
            // Handle message compression.
            // If the length byte starts with the bits 11, then the rest of
            // this byte and the next form the offset from the dns proto start
            // to the start of the remainder of the name.
            if ((c & 0xc0) == 0xc0) {
                if (pos + 1 >= len){
                	return "NULL";
                }
                if (end_pos == 0) end_pos = pos + 1;
                pos = id_pos + ((c & 0x3f) << 8) + packet[pos+1];
                next = pos;
            } else {
                name_len++;
                pos++;
                next = next + c + 1;
            }
        } else {
            if (c >= '!' && c <= 'z' && c != '\\') name_len++;
            else name_len += 4;
            pos++;
        }
    }
    if (end_pos == 0) end_pos = pos;

    // Due to the nature of DNS name compression, it's possible to get a
    // name that is infinitely long. Return an error in that case.
    // We use the len of the packet as the limit, because it shouldn't
    // be possible for the name to be that long.
    if (steps >= 2*len || pos >= len)
    	return "NULL";

    name_len++;

    if(name_len > len *2)
    	return "NULL";

//    name = (char *)malloc(sizeof(char) * name_len);
    string name;
    pos = *packet_p;

    //Now actually assemble the name.
    //We've already made sure that we don't exceed the packet length, so
    // we don't need to make those checks anymore.
    // Non-printable and whitespace characters are replaced with a question
    // mark. They shouldn't be allowed under any circumstances anyway.
    // Other non-allowed characters are kept as is, as they appear sometimes
    // regardless.
    // This shouldn't interfere with IDNA (international
    // domain names), as those are ascii encoded.
    next = pos;
    i = 0;
    while (next != pos || packet[pos] != 0) {
        if (pos == next) {
            if ((packet[pos] & 0xc0) == 0xc0) {
                pos = id_pos + ((packet[pos] & 0x3f) << 8) + packet[pos+1];
                next = pos;
            } else {
                // Add a period except for the first time.
                if (i != 0) name.append(1,'.');i++;
                next = pos + packet[pos] + 1;
                pos++;
            }
        } else {
            uint8_t c = packet[pos];
            if (c >= '!' && c <= '~' && c != '\\') {
                name.append(1, (char) c);
                i++; pos++;
            } else {
            	return "NULL";
//                name.append(1,'\\')
//                	.append(1,'x');
//                uint8_t c1 = c/16 + 0x30;
//                uint8_t c2 = c%16 + 0x30;
//                if (c1 > 0x39) c1 += 0x27;
//                if (c2 > 0x39) c2 += 0x27;
//                name.append(1,c1)
//                	.append(1,c2);
//                i+=4;
//                pos++;
            }
        }
    }
    *packet_p = end_pos + 1;
    //printf("Name : %s\n", name.c_str());
    return name;
}

VOID UDPParser::decodeStunMsg(const BYTE packet, MPacket *msgObj)
{
	int offset = 0;
	struct stun_packet_header *h = (struct stun_packet_header*)packet;

	uint16_t msgType = ntohs((unsigned short int)h->msgType);

	if(msgType != ALLOCATION_RESP)
		return;

	uint16_t msgLen  = ntohs((unsigned short int)h->msgLen);

	offset += 4; /* Message Type (2 Bytes) +  Message Length (2 Bytes) */

	int p1 = VAL_BYTE(packet + offset); offset += 1;
	int p2 = VAL_BYTE(packet + offset); offset += 1;
	int p3 = VAL_BYTE(packet + offset); offset += 1;
	int p4 = VAL_BYTE(packet + offset); offset += 1;

	/*
	 * Stun Header (20 Bytes)
	 * =======================
	 * Message Type (2 Bytes)
	 * Message Length (2 Bytes)
	 * Message Cookie (4 Bytes)
	 * Message Transaction Id (12 Bytes)
	 */

	offset += STUN_PKT_HEADER - 8;

	while(offset < msgLen)
	{
		uint16_t  attribute = (uint16_t) VAL_USHORT(packet + offset);
		offset += 2;
		uint16_t  attributeLen = (uint16_t) VAL_USHORT(packet + offset);
		offset += 2;

		if((attribute == XOR_MAP_ADDRESS || attribute == XOR_OPT_MAP_ADDRESS) && attributeLen == 8)
		{
			offset += 1; /* Reserved */
			int pFamily = VAL_BYTE(packet + offset);
			offset += 1; /* Protocol Family */

			if(pFamily != 1) /* If not IPv4 Family Return */
				return;

			offset += 2;	/* Port */

			uint32_t appIp = 0;

//			appIp = (appIp << 8) + (p1 ^ packet[offset]);
//			appIp = (appIp << 8) + (p2 ^ packet[offset + 1]);
//			appIp = (appIp << 8) + (p3 ^ packet[offset + 2]);
//			appIp = (appIp << 8) + (p4 ^ packet[offset + 3]);

			/*
			 * Store Application Ip and User Port with User IP as Key
			 */

			/*
			if(appIp > 0)
				STUNMAP::stunMap[msgObj->destIpAddrLong].appIp = appIp;
			else
				STUNMAP::stunMap[msgObj->destIpAddrLong].appIp = msgObj->sourceIpAddrLong;

			STUNMAP::stunMap[msgObj->destIpAddrLong].userPort = msgObj->protoDestPort;
			 */

			STUNMAP::stunMap[msgObj->destIpAddrLong].appIp = msgObj->sourceIpAddrLong;
			STUNMAP::stunMap[msgObj->destIpAddrLong].destPort = msgObj->protoDestPort;
			STUNMAP::stunMap[msgObj->destIpAddrLong].sourcePort = msgObj->protoSourcePort;

//			printf("Dest IP::%u| App Ip::%u| Port::%d\n", msgObj->destIpAddrLong, appIp, port);

			break;
		}
		else
			offset += attributeLen;
	}
}

ULONG UDPParser::convIP2Long(char *ipAddress)
{
	char lAddress[16];
    unsigned long int num=0,val;
    char *tok,*ptr;

    strcpy(lAddress, ipAddress);

    tok=strtok(lAddress,".");
    while( tok != NULL)
    {
        val=strtoul(tok,&ptr,0);
        num=(num << 8) + val;
        tok=strtok(NULL,".");
    }
    return(num);
}

vector<string> UDPParser::split(string str, char delimiter)
{
	vector<string> internal;
	stringstream ss(str);
	string token;

	while(getline(ss, token, delimiter)) {
	    internal.push_back(token);
	}
	return internal;
}

VOID UDPParser::parsePacketSysLog(const BYTE packet,  MPacket *msgObj)
{
	 const u_char *ch = NULL;
	 int sysLogLen = 0;
	 ch = packet;
	 std::size_t pos;
	 std::string key = ""; // Global Ip + Global port + Protocol
	 string data, str3, finalData;
	 data.clear(); str3.clear(); finalData.clear();

	 sysLogLen = (msgObj->protoTLen - UDP_HDR_LEN) - 5;	// Facility: LOCAL1 Reserved (5 Bytes)

	 for(int i = 0; i < sysLogLen; i++) {
		 data.append(1, *ch);
		 ch++;
	 }

	 pos = data.find("NAT444");
	 if(pos!=std::string::npos)
		 str3 = data.substr (pos);
	 else
		 return;

	 pos = str3.find("> ");
	 if(pos!=std::string::npos)
		 finalData = str3.substr(pos + 2);	// Increment 2 for "> "
	 else
		 return;

	 vector<string> splitVector;

	 pos = finalData.find("|");
	 if(pos != std::string::npos) {
		 splitVector = split(finalData, '|');
	 }

 	 strcpy(sourceInsideIp, splitVector[SOURCE_INSIDE_IP].c_str());
 	 strcpy(sourceGlobalIp, splitVector[SOURCE_GLOBAL_IP].c_str());
 	 sourceGlobalPort = atoi(splitVector[SOURCE_GLOBAL_PORT].c_str());
 	 strcpy(destinationIp, splitVector[DESTINATION_IP].c_str());
 	 destinationPort = atoi(splitVector[DESTINATION_PORT].c_str());
 	 protocol = atoi(splitVector[PROTOCOL].c_str());
 	 sourceInsidePort = atoi(splitVector[SOURCE_INSIDE_PORT].c_str());

	 uint32_t sourceGlobalIpLong = convIP2Long(sourceGlobalIp);
	 uint32_t destinationIpLong = convIP2Long(destinationIp);
	 uint32_t sourceInsideIpLong = convIP2Long(sourceInsideIp);

	 key = getSysLogKey(sourceGlobalIpLong, sourceGlobalPort, protocol);

	 std::unordered_map<string, sysLog>::iterator it = sysLogGlobal::sysLogDB.find(key);
	 if(it == sysLogGlobal::sysLogDB.end())
	 {
//		 printf("SysLog Insert Key:: %s Global Ip :: %15s Port :: %05d| Destination Ip :: %15s Port :: %05d| Protocol :: %d\n",
//				 key.c_str(), sourceGlobalIp, sourceGlobalPort, destinationIp, destinationPort, protocol);

		 /*
		  * Storing source Global and Destination Ip in long as we are storing Source and Destination ip in IP.
		  * Lookup will be on Long IP.
		  */
		 sysLogGlobal::sysLogDB[key].sourceInsideIp = sourceInsideIpLong;
		 sysLogGlobal::sysLogDB[key].sourceInsidePort = sourceInsidePort;

		 sysLogGlobal::sysLogDB[key].sourceGlobalIp = sourceGlobalIpLong;
		 sysLogGlobal::sysLogDB[key].sourceGlobalPort = sourceGlobalPort;

		 sysLogGlobal::sysLogDB[key].destinationIp = destinationIpLong;
		 sysLogGlobal::sysLogDB[key].destinationPort = destinationPort;

		 sysLogGlobal::sysLogDB[key].protocol = protocol;
		 sysLogGlobal::sysLogDB[key].lastAccessTimeEpochSec = msgObj->frTimeEpochSec;
	 }
	 else
	 {
//		 		 printf("SysLog Exist  Key:: %s Global Ip :: %15s Port :: %05d| Destination Ip :: %15s Port :: %05d| Protocol :: %d\n",
//		 				 key.c_str(), sourceGlobalIp, sourceGlobalPort, destinationIp, destinationPort, protocol);
	 }
	 splitVector.erase(splitVector.begin()+ splitVector.size());
}

