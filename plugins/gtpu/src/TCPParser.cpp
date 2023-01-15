/*
 * TCPProbe.cpp
 *
 *  Created on: Nov 14, 2015
 *      Author: debashis
 */


#include "TCPParser.h"

#include <pthread.h>
#include <string.h>
#include <netinet/tcp.h>
#include <netinet/in.h>
#include <ctype.h>
#include <algorithm>
#include <string>

#include "Log.h"

using namespace std;

// --------------------------------------------------------------------
TCPParser::TCPParser()
{
	tsval = tsecr = 0;
	psh = rst = syn = fin = window = ack = urg = ackNo = check = urgPtr = 0;
	tcpHeader = 0;
}

// --------------------------------------------------------------------
TCPParser::~TCPParser()
{

}

// --------------------------------------------------------------------
VOID TCPParser::parseTCPPacket(const BYTE packet, MPacket *msgObj)
{ 
	uint16_t cType = 0;

	msgObj->protoPayload = 0;

	tcpHeader = (struct tcphdr *)(packet);

	msgObj->protoHLen = ((tcpHeader->doff) << 2);
	msgObj->protoSourcePort = ntohs((unsigned short int)tcpHeader->source);
	msgObj->protoDestPort = ntohs((unsigned short int)tcpHeader->dest);

	msgObj->tcpSeqNo = VAL_ULONG(packet + 4);

	urg = tcpHeader->urg;
	ack = tcpHeader->ack;
	psh = tcpHeader->psh;
	rst = tcpHeader->rst;
	syn = tcpHeader->syn;
	fin = tcpHeader->fin;

	msgObj->protoPayload = msgObj->ipTLen - (msgObj->ipHLen + msgObj->protoHLen);

	/* ** Connection Request ** */
	if((syn) && (!ack) && (!psh) && (!fin))
	{ msgObj->tcpFlags = SYN_RCV; msgObj->protoPayload = 0; }

	/* ** Connection Request with Response ** */
	else if((syn) && (ack) && (!psh) && (!fin))
	{ msgObj->tcpFlags = SYN_ACK_RCV; msgObj->protoPayload = 0; }

	/* ** Connection Complete ** */
   	else if((!syn) && (ack) && (!rst) && (!fin) && (!psh))
	{
   		msgObj->tcpFlags = ACK_RCV;
		/*msgObj->protoPayload = 0; */
	}

	/* ** Data Complete ** */
   	else if(psh)
	{ msgObj->tcpFlags = DATA_RCV; }

	/* ** Disconnect Request ** */
	else if(fin || rst)
	{ msgObj->tcpFlags = FIN_RCV; msgObj->protoPayload = 0; }

	/* This should never happen, but in case */
	else
	{ msgObj->tcpFlags = TCP_UNKNOWN_PACKET_TYPE; msgObj->protoPayload = 0; }

	if(msgObj->tcpFlags == DATA_RCV && (msgObj->protoPayload > 0))
	{
//		if(msgObj->protoSourcePort == 80 || msgObj->protoDestPort == 80)
//			checkContentType(packet + msgObj->protoHLen, msgObj);

		if(msgObj->protoDestPort == 80 && IPGlobal::S1U_PROCESS_USER_AGENT == true)
			checkAgentType(packet + msgObj->protoHLen, msgObj);

//		tsval = tsecr = 0;
//		if(msgObj->ipVer == IPVersion4) {
//			ProbeUtility::parseTcpTimeStamp(tcpHeader, &tsval, &tsecr);				// Fetch TSVAL and TSECR
//			msgObj->tcpTsVal = tsval;
//			msgObj->tcpTsEcr = tsecr;
//		}
	}

	/* ---------------- End of Session Management --------------------- */

	tcpHeader = NULL;
}

VOID TCPParser::checkContentType(BYTE packet, MPacket *msgObj)
{
#if 0
	int i, posIndex;
	const u_char *ch;
	std::string buffer, httpRspHdr;
	int length = 4;
	bool doFlag = false;

	string::iterator it;

	buffer.clear();
	httpRspHdr.clear();

	posIndex = 0;

	ch = packet;

	// Check for first 4 character as HTTP
	for(i = 0; i < length; i++) {
		httpRspHdr.append(1, *ch);
		ch++;
	}

	std::size_t pos = httpRspHdr.find("HTTP");

	if(pos != std::string::npos) {
		doFlag = true;
	}
	else {
		return;
	}

	int len = msgObj->protoPayload - length;

	if(doFlag) {
		for(i = 0; i < len; i++) {
			if(*ch != CR) {
				buffer.append(1, *ch);
				posIndex ++;
				ch++;

			}	// If
			else {
				std::size_t pos = buffer.find("Content-Type:");

				if(pos != std::string::npos) {
					vector<string> sep = split(buffer, ':'); //Content-Type: application/x-javascript; charset=utf-8-

					if(sep.size() > 1) {
						for (int n = 0; n != sep[1].length(); n++) {
							if(sep[1][n] == ';' || n == 50 || sep[1][n] == ',') {
								return;
							}

							if ((sep[1][n] >= 'a' && sep[1][n] <= 'z') || (sep[1][n] == '/')) {
								msgObj->tcpCType[n] = sep[1][n];
							}
						}
					}
					else {
						return;
					}
				}

				ch += 2;
				buffer.clear();
			} // Else
		}	// For Loop
	}	// End of If Condition
#endif
}

VOID TCPParser::checkAgentType(BYTE packet, MPacket *msgObj)
{
	int i, posIndex;
	const u_char *ch;
	std::string buffer, httpRspHdr;
	int length = 3;
	bool doFlag = false;

	string::iterator it;

	buffer.clear();
	httpRspHdr.clear();

	posIndex = 0;

	ch = packet;

	// Check for first 4 character as HTTP
	for(i = 0; i < length; i++) {
		httpRspHdr.append(1, *ch);
		ch++;
	}

	std::size_t pos = httpRspHdr.find("GET");

	if(pos != std::string::npos) {
		doFlag = true;
	}
	else {
		return;
	}

	int len = msgObj->protoPayload - length;

	if(doFlag) {
		for(i = 0; i < len; i++) {
			if(*ch != CR) {
				if(*ch == COMMA)
					buffer.append(1, ';');
				else
					buffer.append(1, *ch);
				posIndex ++;
				ch++;

			}	// If
			else {

				std::size_t pos = buffer.find("User-Agent:");

				if(pos != std::string::npos) {
					strncpy(msgObj->httpAgent, buffer.c_str(), (HTTP_AGENT_LEN - 1));
					//printf("%s\n", msgObj->httpAgent);
				}

				ch += 2;
				buffer.clear();
			} // Else
		}	// For Loop
	}	// End of If Condition
}


vector<string> TCPParser::split(string str, char delimiter)
{
	vector<string> internal;
	stringstream ss(str);
	string token;

	while(getline(ss, token, delimiter))
	    internal.push_back(token);

	return internal;
}
