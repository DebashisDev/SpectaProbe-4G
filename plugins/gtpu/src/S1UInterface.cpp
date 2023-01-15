/*
 * IPSMInterface.cpp
 *
 *  Created on: 20-Jul-2016
 *      Author: Debashis
 */

#include "S1UInterface.h"

#include "sys/time.h"
#include <locale.h>

S1UInterface::S1UInterface(int id) {
	_thisLogLevel = 0;
	this->_name = "S1UInterface";
	this->setLogLevel(Log::theLog().level());
	this->instanceId = id;
	initializeIPSessionPool();
	initializeDnsSessionPool();
	ipSessionCleanUpMap_cnt = 0;
}

S1UInterface::~S1UInterface()
{ }

/*
 *  IP Function Session
 */

int S1UInterface::getMapIndexAndSessionKey(MPacket *msgObj)
{
//	msgObj->bothLocalIp = false;
    int mapIndex = -1;

	switch(msgObj->ipVer)
	{
		case IPVersion4:
				switch(msgObj->ipProtocol)
				{
					case PACKET_IPPROTO_TCP:
					case PACKET_IPPROTO_UDP:
							if(msgObj->dirUserNetwork == 1) {	// If Direction is UP -> True DN -> False
								msgObj->Key = (msgObj->ipProtocol^5) +
											  (msgObj->sourceIpAddrLong^4) +
											  (msgObj->protoSourcePort^3) +
											  (msgObj->destIpAddrLong^2) +
											  (msgObj->protoDestPort^1);

							mapIndex = (int) (msgObj->sourceIpAddrLong % IP_SESSION_POOL_ARRAY_ELEMENTS);
							}

							else if(msgObj->dirUserNetwork == 2) {
								msgObj->Key = (msgObj->ipProtocol^5) +
											  (msgObj->destIpAddrLong^4) +
											  (msgObj->protoDestPort^3) +
											  (msgObj->sourceIpAddrLong^2) +
											  (msgObj->protoSourcePort^1);

							mapIndex = (int) (msgObj->destIpAddrLong % IP_SESSION_POOL_ARRAY_ELEMENTS);
							}
						break;

					default:
						break;
				}
				break;
		default:
				break;
	}
	return mapIndex ;
}

int S1UInterface::getFreeIndexDns()
{
	freeBitPosDns++;
	if(freeBitPosDns >= freeBitPosDnsMax) freeBitPosDns = 0;
	int arrId = freeBitPosDns / DNS_SESSION_POOL_ARRAY_ELEMENTS;
	int bitId = freeBitPosDns % DNS_SESSION_POOL_ARRAY_ELEMENTS;

	while(bitFlagsDnsSession[arrId].test(bitId)){
		freeBitPosDns++;
		if(freeBitPosDns >= freeBitPosDnsMax) freeBitPosDns = 0;
		arrId = freeBitPosDns / DNS_SESSION_POOL_ARRAY_ELEMENTS;
		bitId = freeBitPosDns % DNS_SESSION_POOL_ARRAY_ELEMENTS;
	}
	if(freeBitPosDns >= freeBitPosDnsMax){
		printf("[%d] getFreeIndexDns freeBitPosDns [%d] >= freeBitPosDnsMax [%d]\n",instanceId, freeBitPosDns, freeBitPosDnsMax);
	}
	bitFlagsDnsSession[arrId].set(bitId);
	return freeBitPosDns;
}

VOID S1UInterface::releaseIndexDns(int idx)
{
	int arrId = idx / DNS_SESSION_POOL_ARRAY_ELEMENTS;
	int bitId = idx % DNS_SESSION_POOL_ARRAY_ELEMENTS;
	dnsSessionPoolMap[arrId][bitId]->reset();
	dnsSessionPoolMap[arrId][bitId]->poolIndex = idx;
	bitFlagsDnsSession[arrId].reset(bitId);
}

VOID S1UInterface::initializeDnsSessionPool()
{
	freeBitPosDnsMax = DNS_SESSION_POOL_ARRAY_ELEMENTS * DNS_SESSION_POOL_ARRAY_SIZE;

	printf("IPSMInterface [%02d]	Initializing [%d] DNS Session Pool... ", instanceId, freeBitPosDnsMax);
	TheLog_nc_v2(Log::Info, name(),"     [%d] Initializing [%d] DNS Session Pool...", instanceId,freeBitPosDnsMax);
	for(int i=0; i<DNS_SESSION_POOL_ARRAY_SIZE; i++)
	{
		bitFlagsDnsSession[i].reset();
		for(int j=0; j<DNS_SESSION_POOL_ARRAY_ELEMENTS; j++)
		{
			dnsSessionPoolMap[i][j] = new dnsSession();
			dnsSessionPoolMap[i][j]->poolIndex = (i*DNS_SESSION_POOL_ARRAY_ELEMENTS) + j;
		}
	}
	printf("Completed.\n");
	TheLog_nc_v2(Log::Info, name(),"     [%d] Initializing [%d] DNS Session Pool Completed.", instanceId,freeBitPosDnsMax);
}

dnsSession* S1UInterface::getDnsSessionFromPool(int idx)
{
	int arrId = idx / DNS_SESSION_POOL_ARRAY_ELEMENTS;
	int bitId = idx % DNS_SESSION_POOL_ARRAY_ELEMENTS;
	return dnsSessionPoolMap[arrId][bitId];
}

int S1UInterface::getFreeIndexIP()
{
	freeBitPosIp++;
	if(freeBitPosIp >= freeBitPosIpMax) freeBitPosIp = 0;
	int arrId = freeBitPosIp / IP_SESSION_POOL_ARRAY_ELEMENTS;
	int bitId = freeBitPosIp % IP_SESSION_POOL_ARRAY_ELEMENTS;

	while(bitFlagsIpSession[arrId].test(bitId)){
		freeBitPosIp++;
		if(freeBitPosIp >= freeBitPosIpMax) freeBitPosIp = 0;
		arrId = freeBitPosIp / IP_SESSION_POOL_ARRAY_ELEMENTS;
		bitId = freeBitPosIp % IP_SESSION_POOL_ARRAY_ELEMENTS;
	}
	if(freeBitPosIp >= freeBitPosIpMax){
		printf("[%d] getFreeIndexIp freeBitPosIp [%d] >= freeBitPosIpMax [%d]\n",instanceId, freeBitPosIp, freeBitPosIpMax);
	}
	bitFlagsIpSession[arrId].set(bitId);
	return freeBitPosIp;
}

VOID S1UInterface::releaseIndexIP(int idx)
{
	int arrId = idx / IP_SESSION_POOL_ARRAY_ELEMENTS;
	int bitId = idx % IP_SESSION_POOL_ARRAY_ELEMENTS;
	ipSessionPoolMap[arrId][bitId]->reset();
	ipSessionPoolMap[arrId][bitId]->poolIndex = idx;
	bitFlagsIpSession[arrId].reset(bitId);
}

VOID S1UInterface::initializeIPSessionPool()
{
	freeBitPosIpMax = IP_SESSION_POOL_ARRAY_ELEMENTS * IP_SESSION_POOL_ARRAY_SIZE;

	printf("IPSMInterface [%02d]	Initializing [%d]  IP Session Pool... ", instanceId, freeBitPosIpMax);
	TheLog_nc_v2(Log::Info, name(),"     [%d] Initializing [%d] IP Session Pool...", instanceId,freeBitPosIpMax);
	for(int i=0; i<IP_SESSION_POOL_ARRAY_SIZE; i++)
	{
		bitFlagsIpSession[i].reset();
		for(int j=0; j<IP_SESSION_POOL_ARRAY_ELEMENTS; j++)
		{
			ipSessionPoolMap[i][j] = new ipSession();
			ipSessionPoolMap[i][j]->poolIndex = (i*IP_SESSION_POOL_ARRAY_ELEMENTS) + j;
		}
	}
	printf("Completed.\n");
	TheLog_nc_v2(Log::Info, name(),"     [%d] Initializing [%d] IP Session Pool Completed.", instanceId,freeBitPosIpMax);
}

ipSession* S1UInterface::getIPSessionFromPool(int idx)
{
	int arrId = idx / IP_SESSION_POOL_ARRAY_ELEMENTS;
	int bitId = idx % IP_SESSION_POOL_ARRAY_ELEMENTS;
	return ipSessionPoolMap[arrId][bitId];
}

ipSession* S1UInterface::getIpSession(MPacket *msgObj, bool *found, bool create)
{
	long session_cnt = 0;
	ipSession *pIpSession = NULL;
	int mapIndex = -1;

	mapIndex = getMapIndexAndSessionKey(msgObj);

	std::map<uint64_t, int>::iterator it = ipSessionMap[mapIndex].find(msgObj->Key);

	if(it != ipSessionMap[mapIndex].end())
	{
		pIpSession = getIPSessionFromPool(it->second);
		*found = true;
	}
	else
	{
		if(create) {
			for(int i = 0; i < IP_SESSION_POOL_ARRAY_ELEMENTS; i++)
					session_cnt += ipSessionMap[i].size();

			IPGlobal::ACTIVE_S1U_IP_SESSIONS[instanceId] = session_cnt;

			if(session_cnt < freeBitPosIpMax) {
				int poolIndex = getFreeIndexIP();
				pIpSession = getIPSessionFromPool(poolIndex);
				pIpSession->reset();

				pIpSession->sessionKey = msgObj->Key ;
				pIpSession->smInstanceId = this->instanceId;
				pIpSession->mapIndex = mapIndex;
				pIpSession->poolIndex = poolIndex;
				ipSessionMap[pIpSession->mapIndex][pIpSession->sessionKey] = poolIndex;
			}
		}
		*found = false;
	}
	return pIpSession;
}

VOID S1UInterface::updateTime(ipSession *pIpSession, int id)
{
	switch(id)
	{
		case SYN_RCV:
				pIpSession->synRcv = true;
				pIpSession->synTimeEpochNanoSec = pIpSession->pckLastTimeEpochNanoSec;
				break;

		case SYN_ACK_RCV:
				pIpSession->synAckRcv = true;
				pIpSession->synAckTimeEpochNanoSec = pIpSession->pckLastTimeEpochNanoSec;
				break;

		case ACK_RCV:
				pIpSession->ackRcv = true;
				pIpSession->ackTimeEpochNanoSec = pIpSession->pckLastTimeEpochNanoSec;
				break;

		case DATA_RCV:
				pIpSession->dataRcv = true;
				pIpSession->firstDataTimeEpochNanoSec = pIpSession->pckLastTimeEpochNanoSec;
				pIpSession->firstDataFlag = true;
				break;

		case FIN_RCV:
				pIpSession->finRcv = true;
				pIpSession->finTimeEpochNanoSec = pIpSession->pckLastTimeEpochNanoSec;
				pIpSession->endTimeEpochNanoSec = pIpSession->pckLastTimeEpochNanoSec;
				pIpSession->causeCode = SESSION_TERM_TCP_FIN_RECEIVED;
				break;
	}
}

VOID S1UInterface::IP_TCPProcessPacket(MPacket *msgObj)
{
	bool found = false;
	ULONG latency = 0;
	ipSession *pIpSession;

	switch(msgObj->tcpFlags)
	{
		case  SYN_RCV:
				pIpSession = getIpSession(msgObj, &found, true);

				/* Couldn't Create Session */
				if(pIpSession == NULL) return;

				timeStampArrivalPacket(pIpSession, msgObj);

				/* Create New Session */
				if(!found) {
					updateTime(pIpSession, SYN_RCV);			/* Update Syn Time */
					initializeTcpSession(pIpSession, msgObj);	/* Initialize TCP Packet */
					updateTcpSession(pIpSession, msgObj);			/* Update TCP Packet */
					return;
				}

				if(pIpSession->synRcv) {
					updateTcpSession(pIpSession, msgObj);		/* Update TCP Packet */
					break;
				}
				else if(pIpSession->synAckRcv && pIpSession->ackRcv) {
					pIpSession->state = CONNECTED;
					updateTime(pIpSession, SYN_RCV);			/* Update Syn Time */
					updateTcpSession(pIpSession, msgObj);		/* Update TCP Packet */
				}
				else if(pIpSession->synAckRcv || pIpSession->ackRcv) {
					updateTime(pIpSession, SYN_RCV);			/* Update Syn Time */
					updateTcpSession(pIpSession, msgObj);			/* Update TCP Packet */
				}
				else
				{
					updateTime(pIpSession, SYN_RCV);
					updateTcpSession(pIpSession, msgObj);
				}

				break;

		case SYN_ACK_RCV:
				pIpSession = getIpSession(msgObj, &found, true);

				/* Couldn't Create Session */
				if(pIpSession == NULL) return;

				timeStampArrivalPacket(pIpSession, msgObj);

				/* Create New Session */
				if(!found) {
					updateTime(pIpSession, SYN_ACK_RCV);		/* Update Syn Ack Time */
					initializeTcpSession(pIpSession, msgObj);
					updateTcpSession(pIpSession, msgObj);
					return;
				}

				if(pIpSession->synAckRcv)
				{
					updateTcpSession(pIpSession, msgObj);
					break;
				}
				else if (pIpSession->synRcv && pIpSession->ackRcv) {
					pIpSession->state = CONNECTED;
					updateTime(pIpSession, SYN_ACK_RCV);			/* Update Syn Ack Time */
					updateTcpSession(pIpSession, msgObj);
				}
				else if (pIpSession->synRcv || pIpSession->ackRcv) 	{
					updateTime(pIpSession, SYN_ACK_RCV);			/* Update Syn Ack Time */
					updateTcpSession(pIpSession, msgObj);
				}
				else
				{
					updateTime(pIpSession, SYN_ACK_RCV);
					updateTcpSession(pIpSession, msgObj);
				}

				break;

		case ACK_RCV:
				/* Don't Process ACK Payload is Zero */
				if(msgObj->protoPayload == 0)
					return;
				else if(!IPGlobal::S1U_PROCESS_ACK)
					return;

				if(IPGlobal::S1U_ACK_CREATE_SESSION)
					pIpSession = getIpSession(msgObj, &found, true);
				else
					pIpSession = getIpSession(msgObj, &found, false);

				/* Couldn't Create Session */
				if(pIpSession == NULL) return;

				timeStampArrivalPacket(pIpSession, msgObj);

				/* Create New Session */
				if(!found) {
					updateTime(pIpSession, ACK_RCV);						/* Update Syn Ack Time */
					initializeTcpSession(pIpSession, msgObj);
					updateTcpSession(pIpSession, msgObj);
					return;
				}

				if(pIpSession->ackRcv)
				{
					updateTcpSession(pIpSession, msgObj);
					break;
				}

				else if (pIpSession->synRcv && pIpSession->synAckRcv)
				{
					pIpSession->state = CONNECTED;
					updateTime(pIpSession, ACK_RCV);			/* Update Syn Ack Time */
					updateTcpSession(pIpSession, msgObj);
				}
				else if(pIpSession->synRcv || pIpSession->synAckRcv)
				{
					updateTime(pIpSession, ACK_RCV);			/* Update Syn Ack Time */
					updateTcpSession(pIpSession, msgObj);
				}
				else
				{
					updateTime(pIpSession, ACK_RCV);
					updateTcpSession(pIpSession, msgObj);
				}
				break;

		case DATA_RCV:
				pIpSession = getIpSession(msgObj, &found, true);

				/* Couldn't Create Session */
				if(pIpSession == NULL) return;

				timeStampArrivalPacket(pIpSession, msgObj);

				if(!found)
				{
					updateTime(pIpSession, DATA_RCV);						/* Update Syn Ack Time */
					initializeTcpSession(pIpSession, msgObj);
					updateTcpSession(pIpSession, msgObj);
					return;
				}

				if(pIpSession->firstDataFlag == false)
					updateTime(pIpSession, DATA_RCV);						/* Update Syn Ack Time */

				updateTcpSession(pIpSession, msgObj);

				break;

		case FIN_RCV:
				pIpSession = getIpSession(msgObj, &found, false);

				/* Couldn't Create Session */
				if(pIpSession == NULL) return;

				timeStampArrivalPacket(pIpSession, msgObj);
				updateTime(pIpSession, FIN_RCV);						/* Update Syn Ack Time */
				updateTcpSession(pIpSession, msgObj);
				flushIpSession(3, pIpSession, true);

				break;

		default:
				break;

	}	// End of Main Switch
	pIpSession = NULL;
} // End Of updateTCPSession Function

VOID S1UInterface::initializeTcpSession(ipSession *pIpSession, MPacket *msgObj)
{
	pIpSession->ipVer = msgObj->ipVer;
	pIpSession->protocolType = PACKET_IPPROTO_TCP;
	pIpSession->TTL = msgObj->ipTtl;

	if(msgObj->dirUserNetwork == 1)
	{
		pIpSession->teid_up = msgObj->gtpuTeid;

		if(msgObj->ipVer == IPVersion4)
		{
			pIpSession->sourceIpAddrLong = msgObj->sourceIpAddrLong;
			pIpSession->destIpAddrLong = msgObj->destIpAddrLong;
		}

		pIpSession->sourcePort = msgObj->protoSourcePort;
		pIpSession->destPort = msgObj->protoDestPort;

		strcpy(pIpSession->sourceMacAddr, msgObj->ethSourceMACAddr);
		strcpy(pIpSession->destMacAddr, msgObj->ethDestMACAddr);

	}
	else if(msgObj->dirUserNetwork == 2)
	{
		pIpSession->teid_dn = msgObj->gtpuTeid;

		if(msgObj->ipVer == IPVersion4)
		{
			pIpSession->sourceIpAddrLong = msgObj->destIpAddrLong;
			pIpSession->destIpAddrLong = msgObj->sourceIpAddrLong;
		}

		pIpSession->sourcePort = msgObj->protoDestPort;
		pIpSession->destPort = msgObj->protoSourcePort;

		strcpy(pIpSession->sourceMacAddr, msgObj->ethDestMACAddr);
		strcpy(pIpSession->destMacAddr, msgObj->ethSourceMACAddr);

	}

	pIpSession->isUpDir = msgObj->dirUserNetwork;
	pIpSession->vLanId = msgObj->ethVLanId;

	pIpSession->sliceCounter = 0;

	if(IPGlobal::S1U_PROCESS_USER_AGENT)
		if(strlen(pIpSession->httpAgent) == 0)
			strcpy(pIpSession->httpAgent, msgObj->httpAgent);

	pIpSession->startTimeEpochSec = pIpSession->pckArivalTimeEpochSec;
	pIpSession->startTimeEpochNanoSec = pIpSession->pckLastTimeEpochNanoSec;

	pIpSession->endTimeEpochNanoSec = pIpSession->pckLastTimeEpochNanoSec;

}

BOOL S1UInterface::checkDuplicate(ipSession *pIpSession, MPacket *msgObj)
{
	uint16_t ipId  = 0;
	uint8_t ttl = 0, dir = 0;
	bool got = false;

	std::map<uint32_t, dupInfo>::iterator it = pIpSession->dupMap.find(msgObj->tcpSeqNo);

	pIpSession->totalFrameCount ++;

	if(it != pIpSession->dupMap.end())
	{
		ipId = it->second.ipId;
		ttl = it->second.ttl;
		dir = it->second.direction;
		got = true;
	}
	else
	{
		pIpSession->dupMap[msgObj->tcpSeqNo].ipId = msgObj->ipIdentification;
		pIpSession->dupMap[msgObj->tcpSeqNo].ttl = msgObj->ipTtl;
		pIpSession->dupMap[msgObj->tcpSeqNo].direction = msgObj->dirUserNetwork;
	}

	if(got)
	{
		if(dir == msgObj->dirUserNetwork)
		{
		/* Check for IP Identification */
			if(ipId != msgObj->ipIdentification)
			{
				/* It is a TCP Re-Transmission */
				pIpSession->reTransmissionCnt++;
			}
			else
			{
				if(ttl != msgObj->ipTtl )
				{	/* Its a Layer 3 Loop */
					pIpSession->layer3LoopCnt++;
				}
				else
				{ /* Layer 2 Duplicate packet */
					pIpSession->duplicateCnt++;
				}
			}
		}
	}
	return got;
}

BOOL S1UInterface::updateVPS(ipSession *pIpSession, MPacket *msgObj)
{
	fData *pFData = &pIpSession->packTimeMap[pIpSession->pckArivalTimeEpochSec];

	pFData->totalVolume += msgObj->protoPayload;

	if(msgObj->dirUserNetwork == 1)
	{
		pFData->upPackets += 1;
		pFData->upVolume += msgObj->protoPayload;
	}
	else if(msgObj->dirUserNetwork == 2)
	{
		if(pFData->dnPackets > IPGlobal::S1U_VPS_PACKET_PER_SEC)
			return false;

		pFData->dnPackets += 1;
		pFData->dnVolume += msgObj->protoPayload;
	}
	return true;
}

VOID S1UInterface::timeStampArrivalPacket(ipSession *pIpSession, MPacket *msgObj)
{
	pIpSession->pckArivalTimeEpochSec 	= IPGlobal::CURRENT_EPOCH_SEC;
	pIpSession->pckLastTimeEpochSec 	= IPGlobal::CURRENT_EPOCH_SEC;
	pIpSession->pckLastTimeEpochNanoSec = IPGlobal::CURRENT_EPOCH_NANO_SEC;
}

VOID S1UInterface::updateTcpSession(ipSession *pIpSession, MPacket *msgObj)
{
	uint64_t timeDiff = 0;

	if(IPGlobal::S1U_CHECK_DUPLICATE)
		if(checkDuplicate(pIpSession, msgObj)) return;

	if(msgObj->protoPayload > 0)
		vpsFlag = updateVPS(pIpSession, msgObj);

	if(!vpsFlag) return;

	pIpSession->endTimeEpochNanoSec = pIpSession->pckLastTimeEpochNanoSec;

	pIpSession->frameCount += 1;
	pIpSession->frameSize += msgObj->frSize;

	if(msgObj->dirUserNetwork == 1)
	{
		pIpSession->teid_up = msgObj->gtpuTeid;
		pIpSession->upFrameSize += msgObj->frSize;
		pIpSession->upFrameCount += 1;

		if(msgObj->protoPayload > 0)
		{
			pIpSession->payloadPacket += 1;
			pIpSession->payloadSize +=  msgObj->protoPayload;
			pIpSession->upPayloadPacket += 1;
			pIpSession->upPayloadSize += msgObj->protoPayload;
		}
	}
	else if(msgObj->dirUserNetwork == 2)
	{
		pIpSession->teid_dn = msgObj->gtpuTeid;

		pIpSession->dnFrameSize += msgObj->frSize;
		pIpSession->dnFrameCount += 1;

		if(msgObj->protoPayload > 0) {
			pIpSession->payloadPacket += 1;
			pIpSession->payloadSize +=  msgObj->protoPayload;
			pIpSession->dnPayloadPacket += 1;
			pIpSession->dnPayloadSize += msgObj->protoPayload;
		}
	}

	/*
	 * Don't flush the TCP Session which don't have connection
	 */
	if((pIpSession->frameCount >= IPGlobal::S1U_SESSION_PKT_LIMIT))
	{
		if(pIpSession->state == CONNECTED)
		{
			pIpSession->causeCode = SYSTEM_PKTLIMIT_TCP_CONN_DATA;
			flushIpSession(4, pIpSession, false);
		}
		pIpSession->reuse();
	}
	else
	{
		if(pIpSession->pckLastTimeEpochSec > pIpSession->startTimeEpochSec)
		{
			timeDiff = pIpSession->pckLastTimeEpochSec - pIpSession->startTimeEpochSec;

			if(timeDiff >= IPGlobal::S1U_SESSION_TIME_LIMIT)
			{
				if(pIpSession->state == CONNECTED)
				{
					pIpSession->causeCode = SYSTEM_TIMEOUT_TCP_CONN_DATA;
					flushIpSession(8, pIpSession, false);
				}
				pIpSession->reuse();
			}
		}
	}
}

VOID S1UInterface::IP_UdpProcessPacket(MPacket *msgObj)
{
	bool found = false;

	if(!IPGlobal::S1U_UDP_XDR_FOR_DNS)
	{
		if((msgObj->protoSourcePort == DNS_PORT) || (msgObj->protoDestPort == DNS_PORT)) return;
	}

	ipSession *pIpSession = getIpSession(msgObj, &found, true);

	/* Couldn't Create Session */
	if(pIpSession == NULL) return;

	timeStampArrivalPacket(pIpSession, msgObj);

	/* Create New Session */
	if(!found)
	{
		initializeUdpSession(pIpSession, msgObj);
		updateUdpSession(pIpSession, msgObj);
	}
	else
	{ updateUdpSession(pIpSession, msgObj); }

	pIpSession = NULL;
}

VOID S1UInterface::initializeUdpSession(ipSession *pIpSession, MPacket *msgObj)
{
	pIpSession->ipVer = msgObj->ipVer;
	pIpSession->protocolType = PACKET_IPPROTO_UDP;
	pIpSession->state = UD_UDP_DATA;
	pIpSession->TTL = msgObj->ipTtl;
	pIpSession->vLanId = msgObj->ethVLanId;
	pIpSession->sliceCounter = 0;

	if(msgObj->dirUserNetwork == 1)
	{
		pIpSession->teid_up = msgObj->gtpuTeid;

		if(msgObj->ipVer == IPVersion4)
		{
			pIpSession->sourceIpAddrLong = msgObj->sourceIpAddrLong;
			pIpSession->destIpAddrLong = msgObj->destIpAddrLong;
		}
		pIpSession->sourcePort = msgObj->protoSourcePort;
		pIpSession->destPort = msgObj->protoDestPort;

		strcpy(pIpSession->sourceMacAddr, msgObj->ethSourceMACAddr);
		strcpy(pIpSession->destMacAddr, msgObj->ethDestMACAddr);
	}
	else if(msgObj->dirUserNetwork == 2)
	{
		pIpSession->teid_dn = msgObj->gtpuTeid;

		if(msgObj->ipVer == IPVersion4)
		{
			pIpSession->sourceIpAddrLong = msgObj->destIpAddrLong;
			pIpSession->destIpAddrLong = msgObj->sourceIpAddrLong;
		}
		pIpSession->sourcePort = msgObj->protoDestPort;
		pIpSession->destPort = msgObj->protoSourcePort;

		strcpy(pIpSession->sourceMacAddr, msgObj->ethDestMACAddr);
		strcpy(pIpSession->destMacAddr, msgObj->ethSourceMACAddr);
	}

	pIpSession->isUpDir = msgObj->dirUserNetwork;

	pIpSession->startTimeEpochSec 		= pIpSession->pckArivalTimeEpochSec;
	pIpSession->startTimeEpochNanoSec 	= pIpSession->pckLastTimeEpochNanoSec;
	pIpSession->endTimeEpochNanoSec 	= pIpSession->pckLastTimeEpochNanoSec;
}

VOID S1UInterface::updateUdpSession(ipSession *pIpSession, MPacket *msgObj)
{
	uint64_t timeDiff = 0;

	if(msgObj->protoPayload > 0)
		vpsFlag = updateVPS(pIpSession, msgObj);

	if(!vpsFlag) return;

	pIpSession->endTimeEpochNanoSec = pIpSession->pckLastTimeEpochNanoSec;

	pIpSession->frameCount += 1;
	pIpSession->frameSize += msgObj->frSize;

	if(msgObj->dirUserNetwork == 1)
	{
		pIpSession->teid_up = msgObj->gtpuTeid;

		pIpSession->upFrameSize += msgObj->frSize;
		pIpSession->upFrameCount += 1;

		if(msgObj->protoPayload > 0) {
			pIpSession->payloadPacket += 1;
			pIpSession->payloadSize +=  msgObj->protoPayload;
			pIpSession->upPayloadPacket += 1;
			pIpSession->upPayloadSize += msgObj->protoPayload;
		}
	}
	else if(msgObj->dirUserNetwork == 2)
	{
		pIpSession->teid_dn = msgObj->gtpuTeid;

		pIpSession->dnFrameSize += msgObj->frSize;
		pIpSession->dnFrameCount += 1;

		if(msgObj->protoPayload > 0) {
			pIpSession->payloadPacket += 1;
			pIpSession->payloadSize +=  msgObj->protoPayload;
			pIpSession->dnPayloadPacket += 1;
			pIpSession->dnPayloadSize += msgObj->protoPayload;
		}
	}

	/** Check the Data Slicing **/
	if(pIpSession->frameCount >= IPGlobal::S1U_SESSION_PKT_LIMIT)
	{
		pIpSession->causeCode = SYSTEM_PKTLIMIT_UDP_DATA;

		flushIpSession(5, pIpSession, false);
		pIpSession->reuse();
	}
	else
	{
		if(pIpSession->pckLastTimeEpochSec > pIpSession->startTimeEpochSec){
			timeDiff = pIpSession->pckLastTimeEpochSec - pIpSession->startTimeEpochSec;

			if (timeDiff >= IPGlobal::S1U_SESSION_TIME_LIMIT) {
				pIpSession->causeCode = SYSTEM_TIMEOUT_UDP_DATA;

				flushIpSession(9, pIpSession, false);
				pIpSession->reuse();
			}
		}
	}
}

VOID S1UInterface::flushIpSession(int flushOrgId, ipSession *pIpSession, bool erase)
{
	long epochSecNow = IPGlobal::CURRENT_EPOCH_SEC;

	pIpSession->flushOrgId = flushOrgId;
	pIpSession->flushTime = epochSecNow;
	pIpSession->lastActivityTimeEpohSec = epochSecNow;

	int idx = PKT_WRITE_TIME_INDEX(epochSecNow, 10);

	/* If TCP Session Frame Count < 5 during clean up No XDR required */
	if(pIpSession->protocolType == PACKET_IPPROTO_TCP)
	{
		if(pIpSession->frameCount < 5 && flushOrgId == 7)
		{
			eraseIpSession(pIpSession);
			return;
		}
	}

	pIpSession->sliceCounter += 1;
	storeIpSession(idx, pIpSession);


	if(erase) {
		eraseIpSession(pIpSession);
	}
}

VOID S1UInterface::storeIpSession(int idx, ipSession *pIpSession)
{
	int flusherNo = -1 ;

	flusherNo = instanceId % IPGlobal::S1U_FLUSHER_NO;

	switch(flusherNo)
	{
	case 0:
		storeIpSession_f_0(idx, pIpSession);
		break;

	case 1:
		storeIpSession_f_1(idx, pIpSession);
		break;

	case 2:
		storeIpSession_f_2(idx, pIpSession);
		break;

	case 3:
		storeIpSession_f_3(idx, pIpSession);
		break;
	}
}

VOID S1UInterface::storeIpSession_f_0(int index1, ipSession *pIpSession)
{
	int index = PKT_WRITE_TIME_INDEX(IPGlobal::CURRENT_EPOCH_SEC, IPGlobal::PKT_TIME_INDEX);

	switch(instanceId)
	{
			case 0:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_0_sm_0_t_0[IPFlushRepository::ipFlushMap_f_0_sm_0_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_0_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_0_sm_0_t_1[IPFlushRepository::ipFlushMap_f_0_sm_0_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_0_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_0_sm_0_t_2[IPFlushRepository::ipFlushMap_f_0_sm_0_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_0_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_0_sm_0_t_3[IPFlushRepository::ipFlushMap_f_0_sm_0_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_0_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_0_sm_0_t_4[IPFlushRepository::ipFlushMap_f_0_sm_0_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_0_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_0_sm_0_t_5[IPFlushRepository::ipFlushMap_f_0_sm_0_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_0_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_0_sm_0_t_6[IPFlushRepository::ipFlushMap_f_0_sm_0_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_0_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_0_sm_0_t_7[IPFlushRepository::ipFlushMap_f_0_sm_0_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_0_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_0_sm_0_t_8[IPFlushRepository::ipFlushMap_f_0_sm_0_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_0_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_0_sm_0_t_9[IPFlushRepository::ipFlushMap_f_0_sm_0_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_0_t_9_cnt++;
						break;
					}
					break;

			case 1:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_0_sm_1_t_0[IPFlushRepository::ipFlushMap_f_0_sm_1_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_1_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_0_sm_1_t_1[IPFlushRepository::ipFlushMap_f_0_sm_1_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_1_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_0_sm_1_t_2[IPFlushRepository::ipFlushMap_f_0_sm_1_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_1_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_0_sm_1_t_3[IPFlushRepository::ipFlushMap_f_0_sm_1_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_1_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_0_sm_1_t_4[IPFlushRepository::ipFlushMap_f_0_sm_1_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_1_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_0_sm_1_t_5[IPFlushRepository::ipFlushMap_f_0_sm_1_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_1_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_0_sm_1_t_6[IPFlushRepository::ipFlushMap_f_0_sm_1_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_1_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_0_sm_1_t_7[IPFlushRepository::ipFlushMap_f_0_sm_1_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_1_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_0_sm_1_t_8[IPFlushRepository::ipFlushMap_f_0_sm_1_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_1_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_0_sm_1_t_9[IPFlushRepository::ipFlushMap_f_0_sm_1_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_1_t_9_cnt++;
						break;
					}
					break;
			case 2:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_0_sm_2_t_0[IPFlushRepository::ipFlushMap_f_0_sm_2_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_2_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_0_sm_2_t_1[IPFlushRepository::ipFlushMap_f_0_sm_2_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_2_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_0_sm_2_t_2[IPFlushRepository::ipFlushMap_f_0_sm_2_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_2_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_0_sm_2_t_3[IPFlushRepository::ipFlushMap_f_0_sm_2_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_2_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_0_sm_2_t_4[IPFlushRepository::ipFlushMap_f_0_sm_2_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_2_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_0_sm_2_t_5[IPFlushRepository::ipFlushMap_f_0_sm_2_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_2_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_0_sm_2_t_6[IPFlushRepository::ipFlushMap_f_0_sm_2_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_2_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_0_sm_2_t_7[IPFlushRepository::ipFlushMap_f_0_sm_2_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_2_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_0_sm_2_t_8[IPFlushRepository::ipFlushMap_f_0_sm_2_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_2_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_0_sm_2_t_9[IPFlushRepository::ipFlushMap_f_0_sm_2_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_2_t_9_cnt++;
						break;
					}
					break;

			case 3:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_0_sm_3_t_0[IPFlushRepository::ipFlushMap_f_0_sm_3_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_3_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_0_sm_3_t_1[IPFlushRepository::ipFlushMap_f_0_sm_3_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_3_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_0_sm_3_t_2[IPFlushRepository::ipFlushMap_f_0_sm_3_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_3_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_0_sm_3_t_3[IPFlushRepository::ipFlushMap_f_0_sm_3_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_3_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_0_sm_3_t_4[IPFlushRepository::ipFlushMap_f_0_sm_3_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_3_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_0_sm_3_t_5[IPFlushRepository::ipFlushMap_f_0_sm_3_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_3_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_0_sm_3_t_6[IPFlushRepository::ipFlushMap_f_0_sm_3_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_3_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_0_sm_3_t_7[IPFlushRepository::ipFlushMap_f_0_sm_3_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_3_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_0_sm_3_t_8[IPFlushRepository::ipFlushMap_f_0_sm_3_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_3_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_0_sm_3_t_9[IPFlushRepository::ipFlushMap_f_0_sm_3_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_3_t_9_cnt++;
						break;
					}
					break;

			case 4:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_0_sm_4_t_0[IPFlushRepository::ipFlushMap_f_0_sm_4_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_4_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_0_sm_4_t_1[IPFlushRepository::ipFlushMap_f_0_sm_4_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_4_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_0_sm_4_t_2[IPFlushRepository::ipFlushMap_f_0_sm_4_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_4_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_0_sm_4_t_3[IPFlushRepository::ipFlushMap_f_0_sm_4_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_4_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_0_sm_4_t_4[IPFlushRepository::ipFlushMap_f_0_sm_4_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_4_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_0_sm_4_t_5[IPFlushRepository::ipFlushMap_f_0_sm_4_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_4_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_0_sm_4_t_6[IPFlushRepository::ipFlushMap_f_0_sm_4_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_4_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_0_sm_4_t_7[IPFlushRepository::ipFlushMap_f_0_sm_4_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_4_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_0_sm_4_t_8[IPFlushRepository::ipFlushMap_f_0_sm_4_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_4_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_0_sm_4_t_9[IPFlushRepository::ipFlushMap_f_0_sm_4_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_4_t_9_cnt++;
						break;
					}
					break;

			case 5:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_0_sm_5_t_0[IPFlushRepository::ipFlushMap_f_0_sm_5_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_5_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_0_sm_5_t_1[IPFlushRepository::ipFlushMap_f_0_sm_5_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_5_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_0_sm_5_t_2[IPFlushRepository::ipFlushMap_f_0_sm_5_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_5_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_0_sm_5_t_3[IPFlushRepository::ipFlushMap_f_0_sm_5_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_5_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_0_sm_5_t_4[IPFlushRepository::ipFlushMap_f_0_sm_5_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_5_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_0_sm_5_t_5[IPFlushRepository::ipFlushMap_f_0_sm_5_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_5_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_0_sm_5_t_6[IPFlushRepository::ipFlushMap_f_0_sm_5_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_5_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_0_sm_5_t_7[IPFlushRepository::ipFlushMap_f_0_sm_5_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_5_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_0_sm_5_t_8[IPFlushRepository::ipFlushMap_f_0_sm_5_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_5_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_0_sm_5_t_9[IPFlushRepository::ipFlushMap_f_0_sm_5_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_5_t_9_cnt++;
						break;
					}
					break;

			case 6:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_0_sm_6_t_0[IPFlushRepository::ipFlushMap_f_0_sm_6_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_6_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_0_sm_6_t_1[IPFlushRepository::ipFlushMap_f_0_sm_6_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_6_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_0_sm_6_t_2[IPFlushRepository::ipFlushMap_f_0_sm_6_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_6_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_0_sm_6_t_3[IPFlushRepository::ipFlushMap_f_0_sm_6_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_6_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_0_sm_6_t_4[IPFlushRepository::ipFlushMap_f_0_sm_6_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_6_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_0_sm_6_t_5[IPFlushRepository::ipFlushMap_f_0_sm_6_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_6_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_0_sm_6_t_6[IPFlushRepository::ipFlushMap_f_0_sm_6_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_6_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_0_sm_6_t_7[IPFlushRepository::ipFlushMap_f_0_sm_6_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_6_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_0_sm_6_t_8[IPFlushRepository::ipFlushMap_f_0_sm_6_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_6_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_0_sm_6_t_9[IPFlushRepository::ipFlushMap_f_0_sm_6_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_6_t_9_cnt++;
						break;
					}
					break;
			case 7:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_0_sm_7_t_0[IPFlushRepository::ipFlushMap_f_0_sm_7_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_7_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_0_sm_7_t_1[IPFlushRepository::ipFlushMap_f_0_sm_7_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_7_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_0_sm_7_t_2[IPFlushRepository::ipFlushMap_f_0_sm_7_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_7_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_0_sm_7_t_3[IPFlushRepository::ipFlushMap_f_0_sm_7_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_7_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_0_sm_7_t_4[IPFlushRepository::ipFlushMap_f_0_sm_7_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_7_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_0_sm_7_t_5[IPFlushRepository::ipFlushMap_f_0_sm_7_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_7_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_0_sm_7_t_6[IPFlushRepository::ipFlushMap_f_0_sm_7_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_7_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_0_sm_7_t_7[IPFlushRepository::ipFlushMap_f_0_sm_7_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_7_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_0_sm_7_t_8[IPFlushRepository::ipFlushMap_f_0_sm_7_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_7_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_0_sm_7_t_9[IPFlushRepository::ipFlushMap_f_0_sm_7_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_7_t_9_cnt++;
						break;
					}
					break;
			case 8:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_0_sm_8_t_0[IPFlushRepository::ipFlushMap_f_0_sm_8_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_8_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_0_sm_8_t_1[IPFlushRepository::ipFlushMap_f_0_sm_8_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_8_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_0_sm_8_t_2[IPFlushRepository::ipFlushMap_f_0_sm_8_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_8_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_0_sm_8_t_3[IPFlushRepository::ipFlushMap_f_0_sm_8_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_8_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_0_sm_8_t_4[IPFlushRepository::ipFlushMap_f_0_sm_8_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_8_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_0_sm_8_t_5[IPFlushRepository::ipFlushMap_f_0_sm_8_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_8_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_0_sm_8_t_6[IPFlushRepository::ipFlushMap_f_0_sm_8_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_8_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_0_sm_8_t_7[IPFlushRepository::ipFlushMap_f_0_sm_8_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_8_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_0_sm_8_t_8[IPFlushRepository::ipFlushMap_f_0_sm_8_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_8_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_0_sm_8_t_9[IPFlushRepository::ipFlushMap_f_0_sm_8_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_8_t_9_cnt++;
						break;
					}
					break;
			case 9:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_0_sm_9_t_0[IPFlushRepository::ipFlushMap_f_0_sm_9_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_9_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_0_sm_9_t_1[IPFlushRepository::ipFlushMap_f_0_sm_9_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_9_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_0_sm_9_t_2[IPFlushRepository::ipFlushMap_f_0_sm_9_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_9_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_0_sm_9_t_3[IPFlushRepository::ipFlushMap_f_0_sm_9_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_9_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_0_sm_9_t_4[IPFlushRepository::ipFlushMap_f_0_sm_9_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_9_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_0_sm_9_t_5[IPFlushRepository::ipFlushMap_f_0_sm_9_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_9_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_0_sm_9_t_6[IPFlushRepository::ipFlushMap_f_0_sm_9_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_9_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_0_sm_9_t_7[IPFlushRepository::ipFlushMap_f_0_sm_9_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_9_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_0_sm_9_t_8[IPFlushRepository::ipFlushMap_f_0_sm_9_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_9_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_0_sm_9_t_9[IPFlushRepository::ipFlushMap_f_0_sm_9_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_9_t_9_cnt++;
						break;
					}
					break;
			case 10:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_0_sm_10_t_0[IPFlushRepository::ipFlushMap_f_0_sm_10_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_10_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_0_sm_10_t_1[IPFlushRepository::ipFlushMap_f_0_sm_10_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_10_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_0_sm_10_t_2[IPFlushRepository::ipFlushMap_f_0_sm_10_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_10_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_0_sm_10_t_3[IPFlushRepository::ipFlushMap_f_0_sm_10_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_10_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_0_sm_10_t_4[IPFlushRepository::ipFlushMap_f_0_sm_10_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_10_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_0_sm_10_t_5[IPFlushRepository::ipFlushMap_f_0_sm_10_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_10_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_0_sm_10_t_6[IPFlushRepository::ipFlushMap_f_0_sm_10_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_10_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_0_sm_10_t_7[IPFlushRepository::ipFlushMap_f_0_sm_10_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_10_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_0_sm_10_t_8[IPFlushRepository::ipFlushMap_f_0_sm_10_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_10_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_0_sm_10_t_9[IPFlushRepository::ipFlushMap_f_0_sm_10_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_10_t_9_cnt++;
						break;
					}
					break;
			case 11:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_0_sm_11_t_0[IPFlushRepository::ipFlushMap_f_0_sm_11_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_11_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_0_sm_11_t_1[IPFlushRepository::ipFlushMap_f_0_sm_11_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_11_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_0_sm_11_t_2[IPFlushRepository::ipFlushMap_f_0_sm_11_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_11_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_0_sm_11_t_3[IPFlushRepository::ipFlushMap_f_0_sm_11_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_11_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_0_sm_11_t_4[IPFlushRepository::ipFlushMap_f_0_sm_11_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_11_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_0_sm_11_t_5[IPFlushRepository::ipFlushMap_f_0_sm_11_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_11_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_0_sm_11_t_6[IPFlushRepository::ipFlushMap_f_0_sm_11_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_11_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_0_sm_11_t_7[IPFlushRepository::ipFlushMap_f_0_sm_11_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_11_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_0_sm_11_t_8[IPFlushRepository::ipFlushMap_f_0_sm_11_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_11_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_0_sm_11_t_9[IPFlushRepository::ipFlushMap_f_0_sm_11_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_11_t_9_cnt++;
						break;
					}
					break;
			case 12:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_0_sm_12_t_0[IPFlushRepository::ipFlushMap_f_0_sm_12_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_12_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_0_sm_12_t_1[IPFlushRepository::ipFlushMap_f_0_sm_12_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_12_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_0_sm_12_t_2[IPFlushRepository::ipFlushMap_f_0_sm_12_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_12_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_0_sm_12_t_3[IPFlushRepository::ipFlushMap_f_0_sm_12_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_12_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_0_sm_12_t_4[IPFlushRepository::ipFlushMap_f_0_sm_12_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_12_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_0_sm_12_t_5[IPFlushRepository::ipFlushMap_f_0_sm_12_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_12_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_0_sm_12_t_6[IPFlushRepository::ipFlushMap_f_0_sm_12_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_12_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_0_sm_12_t_7[IPFlushRepository::ipFlushMap_f_0_sm_12_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_12_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_0_sm_12_t_8[IPFlushRepository::ipFlushMap_f_0_sm_12_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_12_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_0_sm_12_t_9[IPFlushRepository::ipFlushMap_f_0_sm_12_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_12_t_9_cnt++;
						break;
					}
					break;
			case 13:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_0_sm_13_t_0[IPFlushRepository::ipFlushMap_f_0_sm_13_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_13_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_0_sm_13_t_1[IPFlushRepository::ipFlushMap_f_0_sm_13_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_13_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_0_sm_13_t_2[IPFlushRepository::ipFlushMap_f_0_sm_13_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_13_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_0_sm_13_t_3[IPFlushRepository::ipFlushMap_f_0_sm_13_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_13_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_0_sm_13_t_4[IPFlushRepository::ipFlushMap_f_0_sm_13_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_13_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_0_sm_13_t_5[IPFlushRepository::ipFlushMap_f_0_sm_13_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_13_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_0_sm_13_t_6[IPFlushRepository::ipFlushMap_f_0_sm_13_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_13_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_0_sm_13_t_7[IPFlushRepository::ipFlushMap_f_0_sm_13_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_13_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_0_sm_13_t_8[IPFlushRepository::ipFlushMap_f_0_sm_13_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_13_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_0_sm_13_t_9[IPFlushRepository::ipFlushMap_f_0_sm_13_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_13_t_9_cnt++;
						break;
					}
					break;
			case 14:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_0_sm_14_t_0[IPFlushRepository::ipFlushMap_f_0_sm_14_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_14_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_0_sm_14_t_1[IPFlushRepository::ipFlushMap_f_0_sm_14_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_14_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_0_sm_14_t_2[IPFlushRepository::ipFlushMap_f_0_sm_14_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_14_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_0_sm_14_t_3[IPFlushRepository::ipFlushMap_f_0_sm_14_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_14_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_0_sm_14_t_4[IPFlushRepository::ipFlushMap_f_0_sm_14_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_14_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_0_sm_14_t_5[IPFlushRepository::ipFlushMap_f_0_sm_14_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_14_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_0_sm_14_t_6[IPFlushRepository::ipFlushMap_f_0_sm_14_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_14_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_0_sm_14_t_7[IPFlushRepository::ipFlushMap_f_0_sm_14_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_14_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_0_sm_14_t_8[IPFlushRepository::ipFlushMap_f_0_sm_14_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_14_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_0_sm_14_t_9[IPFlushRepository::ipFlushMap_f_0_sm_14_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_14_t_9_cnt++;
						break;
					}
					break;
			case 15:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_0_sm_15_t_0[IPFlushRepository::ipFlushMap_f_0_sm_15_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_15_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_0_sm_15_t_1[IPFlushRepository::ipFlushMap_f_0_sm_15_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_15_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_0_sm_15_t_2[IPFlushRepository::ipFlushMap_f_0_sm_15_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_15_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_0_sm_15_t_3[IPFlushRepository::ipFlushMap_f_0_sm_15_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_15_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_0_sm_15_t_4[IPFlushRepository::ipFlushMap_f_0_sm_15_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_15_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_0_sm_15_t_5[IPFlushRepository::ipFlushMap_f_0_sm_15_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_15_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_0_sm_15_t_6[IPFlushRepository::ipFlushMap_f_0_sm_15_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_15_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_0_sm_15_t_7[IPFlushRepository::ipFlushMap_f_0_sm_15_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_15_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_0_sm_15_t_8[IPFlushRepository::ipFlushMap_f_0_sm_15_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_15_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_0_sm_15_t_9[IPFlushRepository::ipFlushMap_f_0_sm_15_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_15_t_9_cnt++;
						break;
					}
					break;
			case 16:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_0_sm_16_t_0[IPFlushRepository::ipFlushMap_f_0_sm_16_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_16_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_0_sm_16_t_1[IPFlushRepository::ipFlushMap_f_0_sm_16_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_16_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_0_sm_16_t_2[IPFlushRepository::ipFlushMap_f_0_sm_16_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_16_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_0_sm_16_t_3[IPFlushRepository::ipFlushMap_f_0_sm_16_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_16_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_0_sm_16_t_4[IPFlushRepository::ipFlushMap_f_0_sm_16_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_16_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_0_sm_16_t_5[IPFlushRepository::ipFlushMap_f_0_sm_16_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_16_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_0_sm_16_t_6[IPFlushRepository::ipFlushMap_f_0_sm_16_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_16_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_0_sm_16_t_7[IPFlushRepository::ipFlushMap_f_0_sm_16_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_16_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_0_sm_16_t_8[IPFlushRepository::ipFlushMap_f_0_sm_16_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_16_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_0_sm_16_t_9[IPFlushRepository::ipFlushMap_f_0_sm_16_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_16_t_9_cnt++;
						break;
					}
					break;
			case 17:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_0_sm_17_t_0[IPFlushRepository::ipFlushMap_f_0_sm_17_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_17_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_0_sm_17_t_1[IPFlushRepository::ipFlushMap_f_0_sm_17_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_17_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_0_sm_17_t_2[IPFlushRepository::ipFlushMap_f_0_sm_17_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_17_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_0_sm_17_t_3[IPFlushRepository::ipFlushMap_f_0_sm_17_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_17_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_0_sm_17_t_4[IPFlushRepository::ipFlushMap_f_0_sm_17_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_17_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_0_sm_17_t_5[IPFlushRepository::ipFlushMap_f_0_sm_17_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_17_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_0_sm_17_t_6[IPFlushRepository::ipFlushMap_f_0_sm_17_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_17_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_0_sm_17_t_7[IPFlushRepository::ipFlushMap_f_0_sm_17_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_17_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_0_sm_17_t_8[IPFlushRepository::ipFlushMap_f_0_sm_17_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_17_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_0_sm_17_t_9[IPFlushRepository::ipFlushMap_f_0_sm_17_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_17_t_9_cnt++;
						break;
					}
					break;
			case 18:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_0_sm_18_t_0[IPFlushRepository::ipFlushMap_f_0_sm_18_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_18_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_0_sm_18_t_1[IPFlushRepository::ipFlushMap_f_0_sm_18_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_18_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_0_sm_18_t_2[IPFlushRepository::ipFlushMap_f_0_sm_18_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_18_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_0_sm_18_t_3[IPFlushRepository::ipFlushMap_f_0_sm_18_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_18_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_0_sm_18_t_4[IPFlushRepository::ipFlushMap_f_0_sm_18_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_18_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_0_sm_18_t_5[IPFlushRepository::ipFlushMap_f_0_sm_18_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_18_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_0_sm_18_t_6[IPFlushRepository::ipFlushMap_f_0_sm_18_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_18_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_0_sm_18_t_7[IPFlushRepository::ipFlushMap_f_0_sm_18_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_18_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_0_sm_18_t_8[IPFlushRepository::ipFlushMap_f_0_sm_18_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_18_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_0_sm_18_t_9[IPFlushRepository::ipFlushMap_f_0_sm_18_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_18_t_9_cnt++;
						break;
					}
					break;
			case 19:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_0_sm_19_t_0[IPFlushRepository::ipFlushMap_f_0_sm_19_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_19_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_0_sm_19_t_1[IPFlushRepository::ipFlushMap_f_0_sm_19_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_19_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_0_sm_19_t_2[IPFlushRepository::ipFlushMap_f_0_sm_19_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_19_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_0_sm_19_t_3[IPFlushRepository::ipFlushMap_f_0_sm_19_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_19_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_0_sm_19_t_4[IPFlushRepository::ipFlushMap_f_0_sm_19_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_19_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_0_sm_19_t_5[IPFlushRepository::ipFlushMap_f_0_sm_19_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_19_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_0_sm_19_t_6[IPFlushRepository::ipFlushMap_f_0_sm_19_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_19_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_0_sm_19_t_7[IPFlushRepository::ipFlushMap_f_0_sm_19_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_19_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_0_sm_19_t_8[IPFlushRepository::ipFlushMap_f_0_sm_19_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_19_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_0_sm_19_t_9[IPFlushRepository::ipFlushMap_f_0_sm_19_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_19_t_9_cnt++;
						break;
					}
					break;
			case 20:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_0_sm_20_t_0[IPFlushRepository::ipFlushMap_f_0_sm_20_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_20_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_0_sm_20_t_1[IPFlushRepository::ipFlushMap_f_0_sm_20_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_20_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_0_sm_20_t_2[IPFlushRepository::ipFlushMap_f_0_sm_20_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_20_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_0_sm_20_t_3[IPFlushRepository::ipFlushMap_f_0_sm_20_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_20_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_0_sm_20_t_4[IPFlushRepository::ipFlushMap_f_0_sm_20_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_20_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_0_sm_20_t_5[IPFlushRepository::ipFlushMap_f_0_sm_20_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_20_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_0_sm_20_t_6[IPFlushRepository::ipFlushMap_f_0_sm_20_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_20_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_0_sm_20_t_7[IPFlushRepository::ipFlushMap_f_0_sm_20_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_20_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_0_sm_20_t_8[IPFlushRepository::ipFlushMap_f_0_sm_20_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_20_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_0_sm_20_t_9[IPFlushRepository::ipFlushMap_f_0_sm_20_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_20_t_9_cnt++;
						break;
					}
					break;
			case 21:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_0_sm_21_t_0[IPFlushRepository::ipFlushMap_f_0_sm_21_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_21_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_0_sm_21_t_1[IPFlushRepository::ipFlushMap_f_0_sm_21_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_21_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_0_sm_21_t_2[IPFlushRepository::ipFlushMap_f_0_sm_21_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_21_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_0_sm_21_t_3[IPFlushRepository::ipFlushMap_f_0_sm_21_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_21_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_0_sm_21_t_4[IPFlushRepository::ipFlushMap_f_0_sm_21_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_21_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_0_sm_21_t_5[IPFlushRepository::ipFlushMap_f_0_sm_21_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_21_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_0_sm_21_t_6[IPFlushRepository::ipFlushMap_f_0_sm_21_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_21_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_0_sm_21_t_7[IPFlushRepository::ipFlushMap_f_0_sm_21_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_21_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_0_sm_21_t_8[IPFlushRepository::ipFlushMap_f_0_sm_21_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_21_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_0_sm_21_t_9[IPFlushRepository::ipFlushMap_f_0_sm_21_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_21_t_9_cnt++;
						break;
					}
					break;
			case 22:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_0_sm_22_t_0[IPFlushRepository::ipFlushMap_f_0_sm_22_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_22_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_0_sm_22_t_1[IPFlushRepository::ipFlushMap_f_0_sm_22_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_22_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_0_sm_22_t_2[IPFlushRepository::ipFlushMap_f_0_sm_22_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_22_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_0_sm_22_t_3[IPFlushRepository::ipFlushMap_f_0_sm_22_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_22_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_0_sm_22_t_4[IPFlushRepository::ipFlushMap_f_0_sm_22_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_22_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_0_sm_22_t_5[IPFlushRepository::ipFlushMap_f_0_sm_22_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_22_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_0_sm_22_t_6[IPFlushRepository::ipFlushMap_f_0_sm_22_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_22_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_0_sm_22_t_7[IPFlushRepository::ipFlushMap_f_0_sm_22_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_22_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_0_sm_22_t_8[IPFlushRepository::ipFlushMap_f_0_sm_22_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_22_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_0_sm_22_t_9[IPFlushRepository::ipFlushMap_f_0_sm_22_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_22_t_9_cnt++;
						break;
					}
					break;
			case 23:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_0_sm_23_t_0[IPFlushRepository::ipFlushMap_f_0_sm_23_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_23_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_0_sm_23_t_1[IPFlushRepository::ipFlushMap_f_0_sm_23_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_23_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_0_sm_23_t_2[IPFlushRepository::ipFlushMap_f_0_sm_23_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_23_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_0_sm_23_t_3[IPFlushRepository::ipFlushMap_f_0_sm_23_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_23_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_0_sm_23_t_4[IPFlushRepository::ipFlushMap_f_0_sm_23_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_23_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_0_sm_23_t_5[IPFlushRepository::ipFlushMap_f_0_sm_23_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_23_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_0_sm_23_t_6[IPFlushRepository::ipFlushMap_f_0_sm_23_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_23_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_0_sm_23_t_7[IPFlushRepository::ipFlushMap_f_0_sm_23_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_23_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_0_sm_23_t_8[IPFlushRepository::ipFlushMap_f_0_sm_23_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_23_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_0_sm_23_t_9[IPFlushRepository::ipFlushMap_f_0_sm_23_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_23_t_9_cnt++;
						break;
					}
					break;
			case 24:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_0_sm_24_t_0[IPFlushRepository::ipFlushMap_f_0_sm_24_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_24_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_0_sm_24_t_1[IPFlushRepository::ipFlushMap_f_0_sm_24_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_24_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_0_sm_24_t_2[IPFlushRepository::ipFlushMap_f_0_sm_24_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_24_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_0_sm_24_t_3[IPFlushRepository::ipFlushMap_f_0_sm_24_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_24_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_0_sm_24_t_4[IPFlushRepository::ipFlushMap_f_0_sm_24_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_24_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_0_sm_24_t_5[IPFlushRepository::ipFlushMap_f_0_sm_24_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_24_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_0_sm_24_t_6[IPFlushRepository::ipFlushMap_f_0_sm_24_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_24_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_0_sm_24_t_7[IPFlushRepository::ipFlushMap_f_0_sm_24_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_24_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_0_sm_24_t_8[IPFlushRepository::ipFlushMap_f_0_sm_24_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_24_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_0_sm_24_t_9[IPFlushRepository::ipFlushMap_f_0_sm_24_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_24_t_9_cnt++;
						break;
					}
					break;
			case 25:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_0_sm_25_t_0[IPFlushRepository::ipFlushMap_f_0_sm_25_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_25_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_0_sm_25_t_1[IPFlushRepository::ipFlushMap_f_0_sm_25_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_25_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_0_sm_25_t_2[IPFlushRepository::ipFlushMap_f_0_sm_25_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_25_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_0_sm_25_t_3[IPFlushRepository::ipFlushMap_f_0_sm_25_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_25_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_0_sm_25_t_4[IPFlushRepository::ipFlushMap_f_0_sm_25_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_25_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_0_sm_25_t_5[IPFlushRepository::ipFlushMap_f_0_sm_25_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_25_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_0_sm_25_t_6[IPFlushRepository::ipFlushMap_f_0_sm_25_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_25_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_0_sm_25_t_7[IPFlushRepository::ipFlushMap_f_0_sm_25_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_25_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_0_sm_25_t_8[IPFlushRepository::ipFlushMap_f_0_sm_25_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_25_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_0_sm_25_t_9[IPFlushRepository::ipFlushMap_f_0_sm_25_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_25_t_9_cnt++;
						break;
					}
					break;
			case 26:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_0_sm_26_t_0[IPFlushRepository::ipFlushMap_f_0_sm_26_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_26_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_0_sm_26_t_1[IPFlushRepository::ipFlushMap_f_0_sm_26_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_26_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_0_sm_26_t_2[IPFlushRepository::ipFlushMap_f_0_sm_26_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_26_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_0_sm_26_t_3[IPFlushRepository::ipFlushMap_f_0_sm_26_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_26_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_0_sm_26_t_4[IPFlushRepository::ipFlushMap_f_0_sm_26_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_26_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_0_sm_26_t_5[IPFlushRepository::ipFlushMap_f_0_sm_26_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_26_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_0_sm_26_t_6[IPFlushRepository::ipFlushMap_f_0_sm_26_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_26_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_0_sm_26_t_7[IPFlushRepository::ipFlushMap_f_0_sm_26_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_26_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_0_sm_26_t_8[IPFlushRepository::ipFlushMap_f_0_sm_26_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_26_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_0_sm_26_t_9[IPFlushRepository::ipFlushMap_f_0_sm_26_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_26_t_9_cnt++;
						break;
					}
					break;
			case 27:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_0_sm_27_t_0[IPFlushRepository::ipFlushMap_f_0_sm_27_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_27_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_0_sm_27_t_1[IPFlushRepository::ipFlushMap_f_0_sm_27_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_27_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_0_sm_27_t_2[IPFlushRepository::ipFlushMap_f_0_sm_27_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_27_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_0_sm_27_t_3[IPFlushRepository::ipFlushMap_f_0_sm_27_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_27_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_0_sm_27_t_4[IPFlushRepository::ipFlushMap_f_0_sm_27_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_27_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_0_sm_27_t_5[IPFlushRepository::ipFlushMap_f_0_sm_27_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_27_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_0_sm_27_t_6[IPFlushRepository::ipFlushMap_f_0_sm_27_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_27_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_0_sm_27_t_7[IPFlushRepository::ipFlushMap_f_0_sm_27_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_27_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_0_sm_27_t_8[IPFlushRepository::ipFlushMap_f_0_sm_27_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_27_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_0_sm_27_t_9[IPFlushRepository::ipFlushMap_f_0_sm_27_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_27_t_9_cnt++;
						break;
					}
					break;
			case 28:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_0_sm_28_t_0[IPFlushRepository::ipFlushMap_f_0_sm_28_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_28_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_0_sm_28_t_1[IPFlushRepository::ipFlushMap_f_0_sm_28_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_28_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_0_sm_28_t_2[IPFlushRepository::ipFlushMap_f_0_sm_28_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_28_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_0_sm_28_t_3[IPFlushRepository::ipFlushMap_f_0_sm_28_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_28_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_0_sm_28_t_4[IPFlushRepository::ipFlushMap_f_0_sm_28_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_28_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_0_sm_28_t_5[IPFlushRepository::ipFlushMap_f_0_sm_28_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_28_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_0_sm_28_t_6[IPFlushRepository::ipFlushMap_f_0_sm_28_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_28_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_0_sm_28_t_7[IPFlushRepository::ipFlushMap_f_0_sm_28_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_28_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_0_sm_28_t_8[IPFlushRepository::ipFlushMap_f_0_sm_28_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_28_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_0_sm_28_t_9[IPFlushRepository::ipFlushMap_f_0_sm_28_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_28_t_9_cnt++;
						break;
					}
					break;
			case 29:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_0_sm_29_t_0[IPFlushRepository::ipFlushMap_f_0_sm_29_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_29_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_0_sm_29_t_1[IPFlushRepository::ipFlushMap_f_0_sm_29_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_29_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_0_sm_29_t_2[IPFlushRepository::ipFlushMap_f_0_sm_29_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_29_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_0_sm_29_t_3[IPFlushRepository::ipFlushMap_f_0_sm_29_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_29_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_0_sm_29_t_4[IPFlushRepository::ipFlushMap_f_0_sm_29_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_29_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_0_sm_29_t_5[IPFlushRepository::ipFlushMap_f_0_sm_29_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_29_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_0_sm_29_t_6[IPFlushRepository::ipFlushMap_f_0_sm_29_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_29_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_0_sm_29_t_7[IPFlushRepository::ipFlushMap_f_0_sm_29_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_29_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_0_sm_29_t_8[IPFlushRepository::ipFlushMap_f_0_sm_29_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_29_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_0_sm_29_t_9[IPFlushRepository::ipFlushMap_f_0_sm_29_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_0_sm_29_t_9_cnt++;
						break;
					}
					break;
	}
}

VOID S1UInterface::storeIpSession_f_1(int index1, ipSession *pIpSession)
{
	int index = PKT_WRITE_TIME_INDEX(IPGlobal::CURRENT_EPOCH_SEC, IPGlobal::PKT_TIME_INDEX);

	switch(instanceId)
	{
			case 0:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_1_sm_0_t_0[IPFlushRepository::ipFlushMap_f_1_sm_0_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_0_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_1_sm_0_t_1[IPFlushRepository::ipFlushMap_f_1_sm_0_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_0_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_1_sm_0_t_2[IPFlushRepository::ipFlushMap_f_1_sm_0_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_0_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_1_sm_0_t_3[IPFlushRepository::ipFlushMap_f_1_sm_0_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_0_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_1_sm_0_t_4[IPFlushRepository::ipFlushMap_f_1_sm_0_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_0_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_1_sm_0_t_5[IPFlushRepository::ipFlushMap_f_1_sm_0_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_0_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_1_sm_0_t_6[IPFlushRepository::ipFlushMap_f_1_sm_0_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_0_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_1_sm_0_t_7[IPFlushRepository::ipFlushMap_f_1_sm_0_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_0_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_1_sm_0_t_8[IPFlushRepository::ipFlushMap_f_1_sm_0_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_0_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_1_sm_0_t_9[IPFlushRepository::ipFlushMap_f_1_sm_0_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_0_t_9_cnt++;
						break;
					}
					break;

			case 1:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_1_sm_1_t_0[IPFlushRepository::ipFlushMap_f_1_sm_1_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_1_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_1_sm_1_t_1[IPFlushRepository::ipFlushMap_f_1_sm_1_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_1_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_1_sm_1_t_2[IPFlushRepository::ipFlushMap_f_1_sm_1_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_1_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_1_sm_1_t_3[IPFlushRepository::ipFlushMap_f_1_sm_1_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_1_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_1_sm_1_t_4[IPFlushRepository::ipFlushMap_f_1_sm_1_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_1_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_1_sm_1_t_5[IPFlushRepository::ipFlushMap_f_1_sm_1_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_1_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_1_sm_1_t_6[IPFlushRepository::ipFlushMap_f_1_sm_1_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_1_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_1_sm_1_t_7[IPFlushRepository::ipFlushMap_f_1_sm_1_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_1_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_1_sm_1_t_8[IPFlushRepository::ipFlushMap_f_1_sm_1_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_1_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_1_sm_1_t_9[IPFlushRepository::ipFlushMap_f_1_sm_1_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_1_t_9_cnt++;
						break;
					}
					break;
			case 2:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_1_sm_2_t_0[IPFlushRepository::ipFlushMap_f_1_sm_2_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_2_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_1_sm_2_t_1[IPFlushRepository::ipFlushMap_f_1_sm_2_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_2_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_1_sm_2_t_2[IPFlushRepository::ipFlushMap_f_1_sm_2_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_2_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_1_sm_2_t_3[IPFlushRepository::ipFlushMap_f_1_sm_2_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_2_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_1_sm_2_t_4[IPFlushRepository::ipFlushMap_f_1_sm_2_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_2_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_1_sm_2_t_5[IPFlushRepository::ipFlushMap_f_1_sm_2_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_2_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_1_sm_2_t_6[IPFlushRepository::ipFlushMap_f_1_sm_2_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_2_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_1_sm_2_t_7[IPFlushRepository::ipFlushMap_f_1_sm_2_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_2_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_1_sm_2_t_8[IPFlushRepository::ipFlushMap_f_1_sm_2_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_2_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_1_sm_2_t_9[IPFlushRepository::ipFlushMap_f_1_sm_2_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_2_t_9_cnt++;
						break;
					}
					break;

			case 3:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_1_sm_3_t_0[IPFlushRepository::ipFlushMap_f_1_sm_3_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_3_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_1_sm_3_t_1[IPFlushRepository::ipFlushMap_f_1_sm_3_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_3_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_1_sm_3_t_2[IPFlushRepository::ipFlushMap_f_1_sm_3_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_3_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_1_sm_3_t_3[IPFlushRepository::ipFlushMap_f_1_sm_3_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_3_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_1_sm_3_t_4[IPFlushRepository::ipFlushMap_f_1_sm_3_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_3_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_1_sm_3_t_5[IPFlushRepository::ipFlushMap_f_1_sm_3_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_3_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_1_sm_3_t_6[IPFlushRepository::ipFlushMap_f_1_sm_3_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_3_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_1_sm_3_t_7[IPFlushRepository::ipFlushMap_f_1_sm_3_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_3_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_1_sm_3_t_8[IPFlushRepository::ipFlushMap_f_1_sm_3_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_3_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_1_sm_3_t_9[IPFlushRepository::ipFlushMap_f_1_sm_3_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_3_t_9_cnt++;
						break;
					}
					break;

			case 4:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_1_sm_4_t_0[IPFlushRepository::ipFlushMap_f_1_sm_4_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_4_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_1_sm_4_t_1[IPFlushRepository::ipFlushMap_f_1_sm_4_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_4_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_1_sm_4_t_2[IPFlushRepository::ipFlushMap_f_1_sm_4_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_4_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_1_sm_4_t_3[IPFlushRepository::ipFlushMap_f_1_sm_4_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_4_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_1_sm_4_t_4[IPFlushRepository::ipFlushMap_f_1_sm_4_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_4_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_1_sm_4_t_5[IPFlushRepository::ipFlushMap_f_1_sm_4_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_4_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_1_sm_4_t_6[IPFlushRepository::ipFlushMap_f_1_sm_4_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_4_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_1_sm_4_t_7[IPFlushRepository::ipFlushMap_f_1_sm_4_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_4_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_1_sm_4_t_8[IPFlushRepository::ipFlushMap_f_1_sm_4_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_4_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_1_sm_4_t_9[IPFlushRepository::ipFlushMap_f_1_sm_4_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_4_t_9_cnt++;
						break;
					}
					break;

			case 5:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_1_sm_5_t_0[IPFlushRepository::ipFlushMap_f_1_sm_5_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_5_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_1_sm_5_t_1[IPFlushRepository::ipFlushMap_f_1_sm_5_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_5_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_1_sm_5_t_2[IPFlushRepository::ipFlushMap_f_1_sm_5_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_5_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_1_sm_5_t_3[IPFlushRepository::ipFlushMap_f_1_sm_5_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_5_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_1_sm_5_t_4[IPFlushRepository::ipFlushMap_f_1_sm_5_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_5_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_1_sm_5_t_5[IPFlushRepository::ipFlushMap_f_1_sm_5_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_5_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_1_sm_5_t_6[IPFlushRepository::ipFlushMap_f_1_sm_5_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_5_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_1_sm_5_t_7[IPFlushRepository::ipFlushMap_f_1_sm_5_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_5_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_1_sm_5_t_8[IPFlushRepository::ipFlushMap_f_1_sm_5_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_5_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_1_sm_5_t_9[IPFlushRepository::ipFlushMap_f_1_sm_5_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_5_t_9_cnt++;
						break;
					}
					break;

			case 6:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_1_sm_6_t_0[IPFlushRepository::ipFlushMap_f_1_sm_6_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_6_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_1_sm_6_t_1[IPFlushRepository::ipFlushMap_f_1_sm_6_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_6_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_1_sm_6_t_2[IPFlushRepository::ipFlushMap_f_1_sm_6_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_6_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_1_sm_6_t_3[IPFlushRepository::ipFlushMap_f_1_sm_6_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_6_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_1_sm_6_t_4[IPFlushRepository::ipFlushMap_f_1_sm_6_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_6_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_1_sm_6_t_5[IPFlushRepository::ipFlushMap_f_1_sm_6_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_6_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_1_sm_6_t_6[IPFlushRepository::ipFlushMap_f_1_sm_6_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_6_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_1_sm_6_t_7[IPFlushRepository::ipFlushMap_f_1_sm_6_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_6_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_1_sm_6_t_8[IPFlushRepository::ipFlushMap_f_1_sm_6_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_6_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_1_sm_6_t_9[IPFlushRepository::ipFlushMap_f_1_sm_6_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_6_t_9_cnt++;
						break;
					}
					break;
			case 7:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_1_sm_7_t_0[IPFlushRepository::ipFlushMap_f_1_sm_7_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_7_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_1_sm_7_t_1[IPFlushRepository::ipFlushMap_f_1_sm_7_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_7_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_1_sm_7_t_2[IPFlushRepository::ipFlushMap_f_1_sm_7_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_7_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_1_sm_7_t_3[IPFlushRepository::ipFlushMap_f_1_sm_7_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_7_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_1_sm_7_t_4[IPFlushRepository::ipFlushMap_f_1_sm_7_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_7_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_1_sm_7_t_5[IPFlushRepository::ipFlushMap_f_1_sm_7_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_7_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_1_sm_7_t_6[IPFlushRepository::ipFlushMap_f_1_sm_7_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_7_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_1_sm_7_t_7[IPFlushRepository::ipFlushMap_f_1_sm_7_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_7_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_1_sm_7_t_8[IPFlushRepository::ipFlushMap_f_1_sm_7_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_7_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_1_sm_7_t_9[IPFlushRepository::ipFlushMap_f_1_sm_7_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_7_t_9_cnt++;
						break;
					}
					break;
			case 8:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_1_sm_8_t_0[IPFlushRepository::ipFlushMap_f_1_sm_8_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_8_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_1_sm_8_t_1[IPFlushRepository::ipFlushMap_f_1_sm_8_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_8_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_1_sm_8_t_2[IPFlushRepository::ipFlushMap_f_1_sm_8_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_8_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_1_sm_8_t_3[IPFlushRepository::ipFlushMap_f_1_sm_8_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_8_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_1_sm_8_t_4[IPFlushRepository::ipFlushMap_f_1_sm_8_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_8_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_1_sm_8_t_5[IPFlushRepository::ipFlushMap_f_1_sm_8_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_8_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_1_sm_8_t_6[IPFlushRepository::ipFlushMap_f_1_sm_8_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_8_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_1_sm_8_t_7[IPFlushRepository::ipFlushMap_f_1_sm_8_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_8_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_1_sm_8_t_8[IPFlushRepository::ipFlushMap_f_1_sm_8_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_8_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_1_sm_8_t_9[IPFlushRepository::ipFlushMap_f_1_sm_8_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_8_t_9_cnt++;
						break;
					}
					break;
			case 9:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_1_sm_9_t_0[IPFlushRepository::ipFlushMap_f_1_sm_9_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_9_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_1_sm_9_t_1[IPFlushRepository::ipFlushMap_f_1_sm_9_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_9_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_1_sm_9_t_2[IPFlushRepository::ipFlushMap_f_1_sm_9_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_9_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_1_sm_9_t_3[IPFlushRepository::ipFlushMap_f_1_sm_9_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_9_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_1_sm_9_t_4[IPFlushRepository::ipFlushMap_f_1_sm_9_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_9_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_1_sm_9_t_5[IPFlushRepository::ipFlushMap_f_1_sm_9_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_9_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_1_sm_9_t_6[IPFlushRepository::ipFlushMap_f_1_sm_9_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_9_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_1_sm_9_t_7[IPFlushRepository::ipFlushMap_f_1_sm_9_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_9_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_1_sm_9_t_8[IPFlushRepository::ipFlushMap_f_1_sm_9_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_9_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_1_sm_9_t_9[IPFlushRepository::ipFlushMap_f_1_sm_9_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_9_t_9_cnt++;
						break;
					}
					break;
			case 10:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_1_sm_10_t_0[IPFlushRepository::ipFlushMap_f_1_sm_10_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_10_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_1_sm_10_t_1[IPFlushRepository::ipFlushMap_f_1_sm_10_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_10_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_1_sm_10_t_2[IPFlushRepository::ipFlushMap_f_1_sm_10_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_10_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_1_sm_10_t_3[IPFlushRepository::ipFlushMap_f_1_sm_10_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_10_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_1_sm_10_t_4[IPFlushRepository::ipFlushMap_f_1_sm_10_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_10_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_1_sm_10_t_5[IPFlushRepository::ipFlushMap_f_1_sm_10_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_10_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_1_sm_10_t_6[IPFlushRepository::ipFlushMap_f_1_sm_10_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_10_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_1_sm_10_t_7[IPFlushRepository::ipFlushMap_f_1_sm_10_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_10_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_1_sm_10_t_8[IPFlushRepository::ipFlushMap_f_1_sm_10_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_10_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_1_sm_10_t_9[IPFlushRepository::ipFlushMap_f_1_sm_10_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_10_t_9_cnt++;
						break;
					}
					break;
			case 11:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_1_sm_11_t_0[IPFlushRepository::ipFlushMap_f_1_sm_11_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_11_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_1_sm_11_t_1[IPFlushRepository::ipFlushMap_f_1_sm_11_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_11_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_1_sm_11_t_2[IPFlushRepository::ipFlushMap_f_1_sm_11_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_11_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_1_sm_11_t_3[IPFlushRepository::ipFlushMap_f_1_sm_11_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_11_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_1_sm_11_t_4[IPFlushRepository::ipFlushMap_f_1_sm_11_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_11_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_1_sm_11_t_5[IPFlushRepository::ipFlushMap_f_1_sm_11_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_11_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_1_sm_11_t_6[IPFlushRepository::ipFlushMap_f_1_sm_11_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_11_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_1_sm_11_t_7[IPFlushRepository::ipFlushMap_f_1_sm_11_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_11_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_1_sm_11_t_8[IPFlushRepository::ipFlushMap_f_1_sm_11_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_11_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_1_sm_11_t_9[IPFlushRepository::ipFlushMap_f_1_sm_11_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_11_t_9_cnt++;
						break;
					}
					break;
			case 12:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_1_sm_12_t_0[IPFlushRepository::ipFlushMap_f_1_sm_12_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_12_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_1_sm_12_t_1[IPFlushRepository::ipFlushMap_f_1_sm_12_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_12_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_1_sm_12_t_2[IPFlushRepository::ipFlushMap_f_1_sm_12_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_12_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_1_sm_12_t_3[IPFlushRepository::ipFlushMap_f_1_sm_12_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_12_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_1_sm_12_t_4[IPFlushRepository::ipFlushMap_f_1_sm_12_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_12_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_1_sm_12_t_5[IPFlushRepository::ipFlushMap_f_1_sm_12_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_12_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_1_sm_12_t_6[IPFlushRepository::ipFlushMap_f_1_sm_12_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_12_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_1_sm_12_t_7[IPFlushRepository::ipFlushMap_f_1_sm_12_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_12_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_1_sm_12_t_8[IPFlushRepository::ipFlushMap_f_1_sm_12_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_12_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_1_sm_12_t_9[IPFlushRepository::ipFlushMap_f_1_sm_12_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_12_t_9_cnt++;
						break;
					}
					break;
			case 13:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_1_sm_13_t_0[IPFlushRepository::ipFlushMap_f_1_sm_13_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_13_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_1_sm_13_t_1[IPFlushRepository::ipFlushMap_f_1_sm_13_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_13_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_1_sm_13_t_2[IPFlushRepository::ipFlushMap_f_1_sm_13_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_13_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_1_sm_13_t_3[IPFlushRepository::ipFlushMap_f_1_sm_13_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_13_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_1_sm_13_t_4[IPFlushRepository::ipFlushMap_f_1_sm_13_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_13_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_1_sm_13_t_5[IPFlushRepository::ipFlushMap_f_1_sm_13_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_13_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_1_sm_13_t_6[IPFlushRepository::ipFlushMap_f_1_sm_13_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_13_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_1_sm_13_t_7[IPFlushRepository::ipFlushMap_f_1_sm_13_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_13_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_1_sm_13_t_8[IPFlushRepository::ipFlushMap_f_1_sm_13_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_13_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_1_sm_13_t_9[IPFlushRepository::ipFlushMap_f_1_sm_13_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_13_t_9_cnt++;
						break;
					}
					break;
			case 14:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_1_sm_14_t_0[IPFlushRepository::ipFlushMap_f_1_sm_14_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_14_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_1_sm_14_t_1[IPFlushRepository::ipFlushMap_f_1_sm_14_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_14_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_1_sm_14_t_2[IPFlushRepository::ipFlushMap_f_1_sm_14_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_14_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_1_sm_14_t_3[IPFlushRepository::ipFlushMap_f_1_sm_14_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_14_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_1_sm_14_t_4[IPFlushRepository::ipFlushMap_f_1_sm_14_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_14_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_1_sm_14_t_5[IPFlushRepository::ipFlushMap_f_1_sm_14_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_14_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_1_sm_14_t_6[IPFlushRepository::ipFlushMap_f_1_sm_14_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_14_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_1_sm_14_t_7[IPFlushRepository::ipFlushMap_f_1_sm_14_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_14_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_1_sm_14_t_8[IPFlushRepository::ipFlushMap_f_1_sm_14_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_14_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_1_sm_14_t_9[IPFlushRepository::ipFlushMap_f_1_sm_14_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_14_t_9_cnt++;
						break;
					}
					break;
			case 15:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_1_sm_15_t_0[IPFlushRepository::ipFlushMap_f_1_sm_15_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_15_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_1_sm_15_t_1[IPFlushRepository::ipFlushMap_f_1_sm_15_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_15_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_1_sm_15_t_2[IPFlushRepository::ipFlushMap_f_1_sm_15_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_15_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_1_sm_15_t_3[IPFlushRepository::ipFlushMap_f_1_sm_15_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_15_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_1_sm_15_t_4[IPFlushRepository::ipFlushMap_f_1_sm_15_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_15_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_1_sm_15_t_5[IPFlushRepository::ipFlushMap_f_1_sm_15_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_15_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_1_sm_15_t_6[IPFlushRepository::ipFlushMap_f_1_sm_15_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_15_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_1_sm_15_t_7[IPFlushRepository::ipFlushMap_f_1_sm_15_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_15_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_1_sm_15_t_8[IPFlushRepository::ipFlushMap_f_1_sm_15_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_15_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_1_sm_15_t_9[IPFlushRepository::ipFlushMap_f_1_sm_15_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_15_t_9_cnt++;
						break;
					}
					break;
			case 16:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_1_sm_16_t_0[IPFlushRepository::ipFlushMap_f_1_sm_16_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_16_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_1_sm_16_t_1[IPFlushRepository::ipFlushMap_f_1_sm_16_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_16_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_1_sm_16_t_2[IPFlushRepository::ipFlushMap_f_1_sm_16_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_16_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_1_sm_16_t_3[IPFlushRepository::ipFlushMap_f_1_sm_16_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_16_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_1_sm_16_t_4[IPFlushRepository::ipFlushMap_f_1_sm_16_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_16_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_1_sm_16_t_5[IPFlushRepository::ipFlushMap_f_1_sm_16_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_16_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_1_sm_16_t_6[IPFlushRepository::ipFlushMap_f_1_sm_16_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_16_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_1_sm_16_t_7[IPFlushRepository::ipFlushMap_f_1_sm_16_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_16_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_1_sm_16_t_8[IPFlushRepository::ipFlushMap_f_1_sm_16_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_16_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_1_sm_16_t_9[IPFlushRepository::ipFlushMap_f_1_sm_16_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_16_t_9_cnt++;
						break;
					}
					break;
			case 17:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_1_sm_17_t_0[IPFlushRepository::ipFlushMap_f_1_sm_17_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_17_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_1_sm_17_t_1[IPFlushRepository::ipFlushMap_f_1_sm_17_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_17_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_1_sm_17_t_2[IPFlushRepository::ipFlushMap_f_1_sm_17_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_17_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_1_sm_17_t_3[IPFlushRepository::ipFlushMap_f_1_sm_17_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_17_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_1_sm_17_t_4[IPFlushRepository::ipFlushMap_f_1_sm_17_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_17_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_1_sm_17_t_5[IPFlushRepository::ipFlushMap_f_1_sm_17_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_17_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_1_sm_17_t_6[IPFlushRepository::ipFlushMap_f_1_sm_17_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_17_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_1_sm_17_t_7[IPFlushRepository::ipFlushMap_f_1_sm_17_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_17_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_1_sm_17_t_8[IPFlushRepository::ipFlushMap_f_1_sm_17_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_17_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_1_sm_17_t_9[IPFlushRepository::ipFlushMap_f_1_sm_17_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_17_t_9_cnt++;
						break;
					}
					break;
			case 18:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_1_sm_18_t_0[IPFlushRepository::ipFlushMap_f_1_sm_18_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_18_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_1_sm_18_t_1[IPFlushRepository::ipFlushMap_f_1_sm_18_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_18_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_1_sm_18_t_2[IPFlushRepository::ipFlushMap_f_1_sm_18_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_18_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_1_sm_18_t_3[IPFlushRepository::ipFlushMap_f_1_sm_18_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_18_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_1_sm_18_t_4[IPFlushRepository::ipFlushMap_f_1_sm_18_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_18_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_1_sm_18_t_5[IPFlushRepository::ipFlushMap_f_1_sm_18_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_18_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_1_sm_18_t_6[IPFlushRepository::ipFlushMap_f_1_sm_18_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_18_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_1_sm_18_t_7[IPFlushRepository::ipFlushMap_f_1_sm_18_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_18_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_1_sm_18_t_8[IPFlushRepository::ipFlushMap_f_1_sm_18_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_18_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_1_sm_18_t_9[IPFlushRepository::ipFlushMap_f_1_sm_18_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_18_t_9_cnt++;
						break;
					}
					break;
			case 19:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_1_sm_19_t_0[IPFlushRepository::ipFlushMap_f_1_sm_19_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_19_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_1_sm_19_t_1[IPFlushRepository::ipFlushMap_f_1_sm_19_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_19_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_1_sm_19_t_2[IPFlushRepository::ipFlushMap_f_1_sm_19_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_19_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_1_sm_19_t_3[IPFlushRepository::ipFlushMap_f_1_sm_19_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_19_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_1_sm_19_t_4[IPFlushRepository::ipFlushMap_f_1_sm_19_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_19_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_1_sm_19_t_5[IPFlushRepository::ipFlushMap_f_1_sm_19_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_19_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_1_sm_19_t_6[IPFlushRepository::ipFlushMap_f_1_sm_19_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_19_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_1_sm_19_t_7[IPFlushRepository::ipFlushMap_f_1_sm_19_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_19_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_1_sm_19_t_8[IPFlushRepository::ipFlushMap_f_1_sm_19_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_19_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_1_sm_19_t_9[IPFlushRepository::ipFlushMap_f_1_sm_19_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_19_t_9_cnt++;
						break;
					}
					break;
			case 20:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_1_sm_20_t_0[IPFlushRepository::ipFlushMap_f_1_sm_20_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_20_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_1_sm_20_t_1[IPFlushRepository::ipFlushMap_f_1_sm_20_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_20_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_1_sm_20_t_2[IPFlushRepository::ipFlushMap_f_1_sm_20_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_20_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_1_sm_20_t_3[IPFlushRepository::ipFlushMap_f_1_sm_20_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_20_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_1_sm_20_t_4[IPFlushRepository::ipFlushMap_f_1_sm_20_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_20_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_1_sm_20_t_5[IPFlushRepository::ipFlushMap_f_1_sm_20_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_20_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_1_sm_20_t_6[IPFlushRepository::ipFlushMap_f_1_sm_20_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_20_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_1_sm_20_t_7[IPFlushRepository::ipFlushMap_f_1_sm_20_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_20_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_1_sm_20_t_8[IPFlushRepository::ipFlushMap_f_1_sm_20_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_20_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_1_sm_20_t_9[IPFlushRepository::ipFlushMap_f_1_sm_20_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_20_t_9_cnt++;
						break;
					}
					break;
			case 21:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_1_sm_21_t_0[IPFlushRepository::ipFlushMap_f_1_sm_21_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_21_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_1_sm_21_t_1[IPFlushRepository::ipFlushMap_f_1_sm_21_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_21_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_1_sm_21_t_2[IPFlushRepository::ipFlushMap_f_1_sm_21_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_21_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_1_sm_21_t_3[IPFlushRepository::ipFlushMap_f_1_sm_21_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_21_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_1_sm_21_t_4[IPFlushRepository::ipFlushMap_f_1_sm_21_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_21_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_1_sm_21_t_5[IPFlushRepository::ipFlushMap_f_1_sm_21_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_21_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_1_sm_21_t_6[IPFlushRepository::ipFlushMap_f_1_sm_21_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_21_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_1_sm_21_t_7[IPFlushRepository::ipFlushMap_f_1_sm_21_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_21_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_1_sm_21_t_8[IPFlushRepository::ipFlushMap_f_1_sm_21_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_21_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_1_sm_21_t_9[IPFlushRepository::ipFlushMap_f_1_sm_21_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_21_t_9_cnt++;
						break;
					}
					break;
			case 22:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_1_sm_22_t_0[IPFlushRepository::ipFlushMap_f_1_sm_22_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_22_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_1_sm_22_t_1[IPFlushRepository::ipFlushMap_f_1_sm_22_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_22_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_1_sm_22_t_2[IPFlushRepository::ipFlushMap_f_1_sm_22_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_22_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_1_sm_22_t_3[IPFlushRepository::ipFlushMap_f_1_sm_22_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_22_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_1_sm_22_t_4[IPFlushRepository::ipFlushMap_f_1_sm_22_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_22_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_1_sm_22_t_5[IPFlushRepository::ipFlushMap_f_1_sm_22_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_22_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_1_sm_22_t_6[IPFlushRepository::ipFlushMap_f_1_sm_22_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_22_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_1_sm_22_t_7[IPFlushRepository::ipFlushMap_f_1_sm_22_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_22_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_1_sm_22_t_8[IPFlushRepository::ipFlushMap_f_1_sm_22_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_22_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_1_sm_22_t_9[IPFlushRepository::ipFlushMap_f_1_sm_22_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_22_t_9_cnt++;
						break;
					}
					break;
			case 23:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_1_sm_23_t_0[IPFlushRepository::ipFlushMap_f_1_sm_23_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_23_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_1_sm_23_t_1[IPFlushRepository::ipFlushMap_f_1_sm_23_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_23_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_1_sm_23_t_2[IPFlushRepository::ipFlushMap_f_1_sm_23_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_23_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_1_sm_23_t_3[IPFlushRepository::ipFlushMap_f_1_sm_23_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_23_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_1_sm_23_t_4[IPFlushRepository::ipFlushMap_f_1_sm_23_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_23_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_1_sm_23_t_5[IPFlushRepository::ipFlushMap_f_1_sm_23_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_23_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_1_sm_23_t_6[IPFlushRepository::ipFlushMap_f_1_sm_23_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_23_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_1_sm_23_t_7[IPFlushRepository::ipFlushMap_f_1_sm_23_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_23_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_1_sm_23_t_8[IPFlushRepository::ipFlushMap_f_1_sm_23_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_23_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_1_sm_23_t_9[IPFlushRepository::ipFlushMap_f_1_sm_23_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_23_t_9_cnt++;
						break;
					}
					break;
			case 24:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_1_sm_24_t_0[IPFlushRepository::ipFlushMap_f_1_sm_24_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_24_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_1_sm_24_t_1[IPFlushRepository::ipFlushMap_f_1_sm_24_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_24_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_1_sm_24_t_2[IPFlushRepository::ipFlushMap_f_1_sm_24_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_24_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_1_sm_24_t_3[IPFlushRepository::ipFlushMap_f_1_sm_24_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_24_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_1_sm_24_t_4[IPFlushRepository::ipFlushMap_f_1_sm_24_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_24_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_1_sm_24_t_5[IPFlushRepository::ipFlushMap_f_1_sm_24_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_24_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_1_sm_24_t_6[IPFlushRepository::ipFlushMap_f_1_sm_24_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_24_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_1_sm_24_t_7[IPFlushRepository::ipFlushMap_f_1_sm_24_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_24_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_1_sm_24_t_8[IPFlushRepository::ipFlushMap_f_1_sm_24_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_24_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_1_sm_24_t_9[IPFlushRepository::ipFlushMap_f_1_sm_24_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_24_t_9_cnt++;
						break;
					}
					break;
			case 25:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_1_sm_25_t_0[IPFlushRepository::ipFlushMap_f_1_sm_25_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_25_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_1_sm_25_t_1[IPFlushRepository::ipFlushMap_f_1_sm_25_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_25_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_1_sm_25_t_2[IPFlushRepository::ipFlushMap_f_1_sm_25_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_25_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_1_sm_25_t_3[IPFlushRepository::ipFlushMap_f_1_sm_25_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_25_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_1_sm_25_t_4[IPFlushRepository::ipFlushMap_f_1_sm_25_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_25_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_1_sm_25_t_5[IPFlushRepository::ipFlushMap_f_1_sm_25_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_25_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_1_sm_25_t_6[IPFlushRepository::ipFlushMap_f_1_sm_25_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_25_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_1_sm_25_t_7[IPFlushRepository::ipFlushMap_f_1_sm_25_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_25_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_1_sm_25_t_8[IPFlushRepository::ipFlushMap_f_1_sm_25_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_25_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_1_sm_25_t_9[IPFlushRepository::ipFlushMap_f_1_sm_25_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_25_t_9_cnt++;
						break;
					}
					break;
			case 26:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_1_sm_26_t_0[IPFlushRepository::ipFlushMap_f_1_sm_26_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_26_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_1_sm_26_t_1[IPFlushRepository::ipFlushMap_f_1_sm_26_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_26_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_1_sm_26_t_2[IPFlushRepository::ipFlushMap_f_1_sm_26_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_26_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_1_sm_26_t_3[IPFlushRepository::ipFlushMap_f_1_sm_26_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_26_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_1_sm_26_t_4[IPFlushRepository::ipFlushMap_f_1_sm_26_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_26_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_1_sm_26_t_5[IPFlushRepository::ipFlushMap_f_1_sm_26_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_26_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_1_sm_26_t_6[IPFlushRepository::ipFlushMap_f_1_sm_26_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_26_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_1_sm_26_t_7[IPFlushRepository::ipFlushMap_f_1_sm_26_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_26_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_1_sm_26_t_8[IPFlushRepository::ipFlushMap_f_1_sm_26_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_26_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_1_sm_26_t_9[IPFlushRepository::ipFlushMap_f_1_sm_26_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_26_t_9_cnt++;
						break;
					}
					break;
			case 27:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_1_sm_27_t_0[IPFlushRepository::ipFlushMap_f_1_sm_27_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_27_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_1_sm_27_t_1[IPFlushRepository::ipFlushMap_f_1_sm_27_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_27_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_1_sm_27_t_2[IPFlushRepository::ipFlushMap_f_1_sm_27_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_27_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_1_sm_27_t_3[IPFlushRepository::ipFlushMap_f_1_sm_27_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_27_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_1_sm_27_t_4[IPFlushRepository::ipFlushMap_f_1_sm_27_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_27_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_1_sm_27_t_5[IPFlushRepository::ipFlushMap_f_1_sm_27_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_27_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_1_sm_27_t_6[IPFlushRepository::ipFlushMap_f_1_sm_27_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_27_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_1_sm_27_t_7[IPFlushRepository::ipFlushMap_f_1_sm_27_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_27_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_1_sm_27_t_8[IPFlushRepository::ipFlushMap_f_1_sm_27_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_27_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_1_sm_27_t_9[IPFlushRepository::ipFlushMap_f_1_sm_27_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_27_t_9_cnt++;
						break;
					}
					break;
			case 28:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_1_sm_28_t_0[IPFlushRepository::ipFlushMap_f_1_sm_28_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_28_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_1_sm_28_t_1[IPFlushRepository::ipFlushMap_f_1_sm_28_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_28_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_1_sm_28_t_2[IPFlushRepository::ipFlushMap_f_1_sm_28_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_28_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_1_sm_28_t_3[IPFlushRepository::ipFlushMap_f_1_sm_28_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_28_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_1_sm_28_t_4[IPFlushRepository::ipFlushMap_f_1_sm_28_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_28_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_1_sm_28_t_5[IPFlushRepository::ipFlushMap_f_1_sm_28_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_28_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_1_sm_28_t_6[IPFlushRepository::ipFlushMap_f_1_sm_28_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_28_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_1_sm_28_t_7[IPFlushRepository::ipFlushMap_f_1_sm_28_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_28_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_1_sm_28_t_8[IPFlushRepository::ipFlushMap_f_1_sm_28_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_28_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_1_sm_28_t_9[IPFlushRepository::ipFlushMap_f_1_sm_28_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_28_t_9_cnt++;
						break;
					}
					break;
			case 29:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_1_sm_29_t_0[IPFlushRepository::ipFlushMap_f_1_sm_29_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_29_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_1_sm_29_t_1[IPFlushRepository::ipFlushMap_f_1_sm_29_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_29_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_1_sm_29_t_2[IPFlushRepository::ipFlushMap_f_1_sm_29_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_29_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_1_sm_29_t_3[IPFlushRepository::ipFlushMap_f_1_sm_29_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_29_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_1_sm_29_t_4[IPFlushRepository::ipFlushMap_f_1_sm_29_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_29_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_1_sm_29_t_5[IPFlushRepository::ipFlushMap_f_1_sm_29_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_29_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_1_sm_29_t_6[IPFlushRepository::ipFlushMap_f_1_sm_29_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_29_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_1_sm_29_t_7[IPFlushRepository::ipFlushMap_f_1_sm_29_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_29_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_1_sm_29_t_8[IPFlushRepository::ipFlushMap_f_1_sm_29_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_29_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_1_sm_29_t_9[IPFlushRepository::ipFlushMap_f_1_sm_29_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_1_sm_29_t_9_cnt++;
						break;
					}
					break;
	}
}

VOID S1UInterface::storeIpSession_f_2(int index1, ipSession *pIpSession)
{
	int index = PKT_WRITE_TIME_INDEX(IPGlobal::CURRENT_EPOCH_SEC, IPGlobal::PKT_TIME_INDEX);

	switch(instanceId)
	{
			case 0:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_2_sm_0_t_0[IPFlushRepository::ipFlushMap_f_2_sm_0_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_0_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_2_sm_0_t_1[IPFlushRepository::ipFlushMap_f_2_sm_0_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_0_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_2_sm_0_t_2[IPFlushRepository::ipFlushMap_f_2_sm_0_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_0_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_2_sm_0_t_3[IPFlushRepository::ipFlushMap_f_2_sm_0_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_0_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_2_sm_0_t_4[IPFlushRepository::ipFlushMap_f_2_sm_0_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_0_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_2_sm_0_t_5[IPFlushRepository::ipFlushMap_f_2_sm_0_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_0_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_2_sm_0_t_6[IPFlushRepository::ipFlushMap_f_2_sm_0_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_0_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_2_sm_0_t_7[IPFlushRepository::ipFlushMap_f_2_sm_0_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_0_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_2_sm_0_t_8[IPFlushRepository::ipFlushMap_f_2_sm_0_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_0_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_2_sm_0_t_9[IPFlushRepository::ipFlushMap_f_2_sm_0_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_0_t_9_cnt++;
						break;
					}
					break;

			case 1:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_2_sm_1_t_0[IPFlushRepository::ipFlushMap_f_2_sm_1_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_1_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_2_sm_1_t_1[IPFlushRepository::ipFlushMap_f_2_sm_1_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_1_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_2_sm_1_t_2[IPFlushRepository::ipFlushMap_f_2_sm_1_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_1_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_2_sm_1_t_3[IPFlushRepository::ipFlushMap_f_2_sm_1_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_1_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_2_sm_1_t_4[IPFlushRepository::ipFlushMap_f_2_sm_1_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_1_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_2_sm_1_t_5[IPFlushRepository::ipFlushMap_f_2_sm_1_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_1_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_2_sm_1_t_6[IPFlushRepository::ipFlushMap_f_2_sm_1_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_1_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_2_sm_1_t_7[IPFlushRepository::ipFlushMap_f_2_sm_1_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_1_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_2_sm_1_t_8[IPFlushRepository::ipFlushMap_f_2_sm_1_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_1_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_2_sm_1_t_9[IPFlushRepository::ipFlushMap_f_2_sm_1_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_1_t_9_cnt++;
						break;
					}
					break;
			case 2:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_2_sm_2_t_0[IPFlushRepository::ipFlushMap_f_2_sm_2_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_2_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_2_sm_2_t_1[IPFlushRepository::ipFlushMap_f_2_sm_2_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_2_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_2_sm_2_t_2[IPFlushRepository::ipFlushMap_f_2_sm_2_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_2_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_2_sm_2_t_3[IPFlushRepository::ipFlushMap_f_2_sm_2_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_2_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_2_sm_2_t_4[IPFlushRepository::ipFlushMap_f_2_sm_2_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_2_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_2_sm_2_t_5[IPFlushRepository::ipFlushMap_f_2_sm_2_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_2_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_2_sm_2_t_6[IPFlushRepository::ipFlushMap_f_2_sm_2_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_2_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_2_sm_2_t_7[IPFlushRepository::ipFlushMap_f_2_sm_2_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_2_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_2_sm_2_t_8[IPFlushRepository::ipFlushMap_f_2_sm_2_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_2_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_2_sm_2_t_9[IPFlushRepository::ipFlushMap_f_2_sm_2_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_2_t_9_cnt++;
						break;
					}
					break;

			case 3:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_2_sm_3_t_0[IPFlushRepository::ipFlushMap_f_2_sm_3_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_3_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_2_sm_3_t_1[IPFlushRepository::ipFlushMap_f_2_sm_3_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_3_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_2_sm_3_t_2[IPFlushRepository::ipFlushMap_f_2_sm_3_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_3_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_2_sm_3_t_3[IPFlushRepository::ipFlushMap_f_2_sm_3_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_3_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_2_sm_3_t_4[IPFlushRepository::ipFlushMap_f_2_sm_3_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_3_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_2_sm_3_t_5[IPFlushRepository::ipFlushMap_f_2_sm_3_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_3_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_2_sm_3_t_6[IPFlushRepository::ipFlushMap_f_2_sm_3_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_3_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_2_sm_3_t_7[IPFlushRepository::ipFlushMap_f_2_sm_3_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_3_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_2_sm_3_t_8[IPFlushRepository::ipFlushMap_f_2_sm_3_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_3_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_2_sm_3_t_9[IPFlushRepository::ipFlushMap_f_2_sm_3_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_3_t_9_cnt++;
						break;
					}
					break;

			case 4:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_2_sm_4_t_0[IPFlushRepository::ipFlushMap_f_2_sm_4_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_4_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_2_sm_4_t_1[IPFlushRepository::ipFlushMap_f_2_sm_4_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_4_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_2_sm_4_t_2[IPFlushRepository::ipFlushMap_f_2_sm_4_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_4_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_2_sm_4_t_3[IPFlushRepository::ipFlushMap_f_2_sm_4_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_4_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_2_sm_4_t_4[IPFlushRepository::ipFlushMap_f_2_sm_4_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_4_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_2_sm_4_t_5[IPFlushRepository::ipFlushMap_f_2_sm_4_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_4_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_2_sm_4_t_6[IPFlushRepository::ipFlushMap_f_2_sm_4_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_4_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_2_sm_4_t_7[IPFlushRepository::ipFlushMap_f_2_sm_4_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_4_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_2_sm_4_t_8[IPFlushRepository::ipFlushMap_f_2_sm_4_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_4_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_2_sm_4_t_9[IPFlushRepository::ipFlushMap_f_2_sm_4_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_4_t_9_cnt++;
						break;
					}
					break;

			case 5:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_2_sm_5_t_0[IPFlushRepository::ipFlushMap_f_2_sm_5_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_5_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_2_sm_5_t_1[IPFlushRepository::ipFlushMap_f_2_sm_5_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_5_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_2_sm_5_t_2[IPFlushRepository::ipFlushMap_f_2_sm_5_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_5_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_2_sm_5_t_3[IPFlushRepository::ipFlushMap_f_2_sm_5_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_5_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_2_sm_5_t_4[IPFlushRepository::ipFlushMap_f_2_sm_5_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_5_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_2_sm_5_t_5[IPFlushRepository::ipFlushMap_f_2_sm_5_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_5_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_2_sm_5_t_6[IPFlushRepository::ipFlushMap_f_2_sm_5_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_5_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_2_sm_5_t_7[IPFlushRepository::ipFlushMap_f_2_sm_5_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_5_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_2_sm_5_t_8[IPFlushRepository::ipFlushMap_f_2_sm_5_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_5_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_2_sm_5_t_9[IPFlushRepository::ipFlushMap_f_2_sm_5_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_5_t_9_cnt++;
						break;
					}
					break;

			case 6:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_2_sm_6_t_0[IPFlushRepository::ipFlushMap_f_2_sm_6_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_6_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_2_sm_6_t_1[IPFlushRepository::ipFlushMap_f_2_sm_6_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_6_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_2_sm_6_t_2[IPFlushRepository::ipFlushMap_f_2_sm_6_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_6_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_2_sm_6_t_3[IPFlushRepository::ipFlushMap_f_2_sm_6_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_6_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_2_sm_6_t_4[IPFlushRepository::ipFlushMap_f_2_sm_6_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_6_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_2_sm_6_t_5[IPFlushRepository::ipFlushMap_f_2_sm_6_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_6_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_2_sm_6_t_6[IPFlushRepository::ipFlushMap_f_2_sm_6_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_6_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_2_sm_6_t_7[IPFlushRepository::ipFlushMap_f_2_sm_6_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_6_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_2_sm_6_t_8[IPFlushRepository::ipFlushMap_f_2_sm_6_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_6_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_2_sm_6_t_9[IPFlushRepository::ipFlushMap_f_2_sm_6_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_6_t_9_cnt++;
						break;
					}
					break;
			case 7:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_2_sm_7_t_0[IPFlushRepository::ipFlushMap_f_2_sm_7_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_7_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_2_sm_7_t_1[IPFlushRepository::ipFlushMap_f_2_sm_7_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_7_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_2_sm_7_t_2[IPFlushRepository::ipFlushMap_f_2_sm_7_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_7_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_2_sm_7_t_3[IPFlushRepository::ipFlushMap_f_2_sm_7_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_7_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_2_sm_7_t_4[IPFlushRepository::ipFlushMap_f_2_sm_7_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_7_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_2_sm_7_t_5[IPFlushRepository::ipFlushMap_f_2_sm_7_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_7_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_2_sm_7_t_6[IPFlushRepository::ipFlushMap_f_2_sm_7_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_7_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_2_sm_7_t_7[IPFlushRepository::ipFlushMap_f_2_sm_7_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_7_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_2_sm_7_t_8[IPFlushRepository::ipFlushMap_f_2_sm_7_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_7_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_2_sm_7_t_9[IPFlushRepository::ipFlushMap_f_2_sm_7_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_7_t_9_cnt++;
						break;
					}
					break;
			case 8:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_2_sm_8_t_0[IPFlushRepository::ipFlushMap_f_2_sm_8_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_8_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_2_sm_8_t_1[IPFlushRepository::ipFlushMap_f_2_sm_8_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_8_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_2_sm_8_t_2[IPFlushRepository::ipFlushMap_f_2_sm_8_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_8_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_2_sm_8_t_3[IPFlushRepository::ipFlushMap_f_2_sm_8_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_8_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_2_sm_8_t_4[IPFlushRepository::ipFlushMap_f_2_sm_8_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_8_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_2_sm_8_t_5[IPFlushRepository::ipFlushMap_f_2_sm_8_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_8_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_2_sm_8_t_6[IPFlushRepository::ipFlushMap_f_2_sm_8_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_8_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_2_sm_8_t_7[IPFlushRepository::ipFlushMap_f_2_sm_8_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_8_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_2_sm_8_t_8[IPFlushRepository::ipFlushMap_f_2_sm_8_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_8_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_2_sm_8_t_9[IPFlushRepository::ipFlushMap_f_2_sm_8_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_8_t_9_cnt++;
						break;
					}
					break;
			case 9:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_2_sm_9_t_0[IPFlushRepository::ipFlushMap_f_2_sm_9_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_9_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_2_sm_9_t_1[IPFlushRepository::ipFlushMap_f_2_sm_9_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_9_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_2_sm_9_t_2[IPFlushRepository::ipFlushMap_f_2_sm_9_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_9_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_2_sm_9_t_3[IPFlushRepository::ipFlushMap_f_2_sm_9_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_9_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_2_sm_9_t_4[IPFlushRepository::ipFlushMap_f_2_sm_9_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_9_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_2_sm_9_t_5[IPFlushRepository::ipFlushMap_f_2_sm_9_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_9_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_2_sm_9_t_6[IPFlushRepository::ipFlushMap_f_2_sm_9_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_9_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_2_sm_9_t_7[IPFlushRepository::ipFlushMap_f_2_sm_9_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_9_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_2_sm_9_t_8[IPFlushRepository::ipFlushMap_f_2_sm_9_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_9_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_2_sm_9_t_9[IPFlushRepository::ipFlushMap_f_2_sm_9_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_9_t_9_cnt++;
						break;
					}
					break;
			case 10:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_2_sm_10_t_0[IPFlushRepository::ipFlushMap_f_2_sm_10_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_10_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_2_sm_10_t_1[IPFlushRepository::ipFlushMap_f_2_sm_10_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_10_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_2_sm_10_t_2[IPFlushRepository::ipFlushMap_f_2_sm_10_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_10_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_2_sm_10_t_3[IPFlushRepository::ipFlushMap_f_2_sm_10_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_10_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_2_sm_10_t_4[IPFlushRepository::ipFlushMap_f_2_sm_10_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_10_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_2_sm_10_t_5[IPFlushRepository::ipFlushMap_f_2_sm_10_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_10_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_2_sm_10_t_6[IPFlushRepository::ipFlushMap_f_2_sm_10_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_10_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_2_sm_10_t_7[IPFlushRepository::ipFlushMap_f_2_sm_10_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_10_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_2_sm_10_t_8[IPFlushRepository::ipFlushMap_f_2_sm_10_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_10_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_2_sm_10_t_9[IPFlushRepository::ipFlushMap_f_2_sm_10_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_10_t_9_cnt++;
						break;
					}
					break;
			case 11:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_2_sm_11_t_0[IPFlushRepository::ipFlushMap_f_2_sm_11_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_11_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_2_sm_11_t_1[IPFlushRepository::ipFlushMap_f_2_sm_11_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_11_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_2_sm_11_t_2[IPFlushRepository::ipFlushMap_f_2_sm_11_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_11_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_2_sm_11_t_3[IPFlushRepository::ipFlushMap_f_2_sm_11_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_11_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_2_sm_11_t_4[IPFlushRepository::ipFlushMap_f_2_sm_11_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_11_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_2_sm_11_t_5[IPFlushRepository::ipFlushMap_f_2_sm_11_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_11_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_2_sm_11_t_6[IPFlushRepository::ipFlushMap_f_2_sm_11_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_11_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_2_sm_11_t_7[IPFlushRepository::ipFlushMap_f_2_sm_11_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_11_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_2_sm_11_t_8[IPFlushRepository::ipFlushMap_f_2_sm_11_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_11_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_2_sm_11_t_9[IPFlushRepository::ipFlushMap_f_2_sm_11_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_11_t_9_cnt++;
						break;
					}
					break;
			case 12:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_2_sm_12_t_0[IPFlushRepository::ipFlushMap_f_2_sm_12_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_12_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_2_sm_12_t_1[IPFlushRepository::ipFlushMap_f_2_sm_12_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_12_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_2_sm_12_t_2[IPFlushRepository::ipFlushMap_f_2_sm_12_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_12_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_2_sm_12_t_3[IPFlushRepository::ipFlushMap_f_2_sm_12_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_12_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_2_sm_12_t_4[IPFlushRepository::ipFlushMap_f_2_sm_12_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_12_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_2_sm_12_t_5[IPFlushRepository::ipFlushMap_f_2_sm_12_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_12_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_2_sm_12_t_6[IPFlushRepository::ipFlushMap_f_2_sm_12_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_12_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_2_sm_12_t_7[IPFlushRepository::ipFlushMap_f_2_sm_12_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_12_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_2_sm_12_t_8[IPFlushRepository::ipFlushMap_f_2_sm_12_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_12_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_2_sm_12_t_9[IPFlushRepository::ipFlushMap_f_2_sm_12_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_12_t_9_cnt++;
						break;
					}
					break;
			case 13:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_2_sm_13_t_0[IPFlushRepository::ipFlushMap_f_2_sm_13_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_13_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_2_sm_13_t_1[IPFlushRepository::ipFlushMap_f_2_sm_13_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_13_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_2_sm_13_t_2[IPFlushRepository::ipFlushMap_f_2_sm_13_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_13_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_2_sm_13_t_3[IPFlushRepository::ipFlushMap_f_2_sm_13_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_13_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_2_sm_13_t_4[IPFlushRepository::ipFlushMap_f_2_sm_13_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_13_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_2_sm_13_t_5[IPFlushRepository::ipFlushMap_f_2_sm_13_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_13_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_2_sm_13_t_6[IPFlushRepository::ipFlushMap_f_2_sm_13_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_13_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_2_sm_13_t_7[IPFlushRepository::ipFlushMap_f_2_sm_13_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_13_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_2_sm_13_t_8[IPFlushRepository::ipFlushMap_f_2_sm_13_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_13_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_2_sm_13_t_9[IPFlushRepository::ipFlushMap_f_2_sm_13_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_13_t_9_cnt++;
						break;
					}
					break;
			case 14:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_2_sm_14_t_0[IPFlushRepository::ipFlushMap_f_2_sm_14_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_14_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_2_sm_14_t_1[IPFlushRepository::ipFlushMap_f_2_sm_14_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_14_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_2_sm_14_t_2[IPFlushRepository::ipFlushMap_f_2_sm_14_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_14_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_2_sm_14_t_3[IPFlushRepository::ipFlushMap_f_2_sm_14_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_14_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_2_sm_14_t_4[IPFlushRepository::ipFlushMap_f_2_sm_14_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_14_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_2_sm_14_t_5[IPFlushRepository::ipFlushMap_f_2_sm_14_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_14_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_2_sm_14_t_6[IPFlushRepository::ipFlushMap_f_2_sm_14_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_14_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_2_sm_14_t_7[IPFlushRepository::ipFlushMap_f_2_sm_14_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_14_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_2_sm_14_t_8[IPFlushRepository::ipFlushMap_f_2_sm_14_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_14_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_2_sm_14_t_9[IPFlushRepository::ipFlushMap_f_2_sm_14_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_14_t_9_cnt++;
						break;
					}
					break;
			case 15:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_2_sm_15_t_0[IPFlushRepository::ipFlushMap_f_2_sm_15_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_15_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_2_sm_15_t_1[IPFlushRepository::ipFlushMap_f_2_sm_15_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_15_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_2_sm_15_t_2[IPFlushRepository::ipFlushMap_f_2_sm_15_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_15_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_2_sm_15_t_3[IPFlushRepository::ipFlushMap_f_2_sm_15_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_15_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_2_sm_15_t_4[IPFlushRepository::ipFlushMap_f_2_sm_15_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_15_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_2_sm_15_t_5[IPFlushRepository::ipFlushMap_f_2_sm_15_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_15_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_2_sm_15_t_6[IPFlushRepository::ipFlushMap_f_2_sm_15_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_15_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_2_sm_15_t_7[IPFlushRepository::ipFlushMap_f_2_sm_15_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_15_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_2_sm_15_t_8[IPFlushRepository::ipFlushMap_f_2_sm_15_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_15_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_2_sm_15_t_9[IPFlushRepository::ipFlushMap_f_2_sm_15_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_15_t_9_cnt++;
						break;
					}
					break;
			case 16:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_2_sm_16_t_0[IPFlushRepository::ipFlushMap_f_2_sm_16_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_16_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_2_sm_16_t_1[IPFlushRepository::ipFlushMap_f_2_sm_16_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_16_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_2_sm_16_t_2[IPFlushRepository::ipFlushMap_f_2_sm_16_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_16_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_2_sm_16_t_3[IPFlushRepository::ipFlushMap_f_2_sm_16_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_16_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_2_sm_16_t_4[IPFlushRepository::ipFlushMap_f_2_sm_16_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_16_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_2_sm_16_t_5[IPFlushRepository::ipFlushMap_f_2_sm_16_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_16_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_2_sm_16_t_6[IPFlushRepository::ipFlushMap_f_2_sm_16_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_16_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_2_sm_16_t_7[IPFlushRepository::ipFlushMap_f_2_sm_16_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_16_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_2_sm_16_t_8[IPFlushRepository::ipFlushMap_f_2_sm_16_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_16_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_2_sm_16_t_9[IPFlushRepository::ipFlushMap_f_2_sm_16_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_16_t_9_cnt++;
						break;
					}
					break;
			case 17:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_2_sm_17_t_0[IPFlushRepository::ipFlushMap_f_2_sm_17_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_17_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_2_sm_17_t_1[IPFlushRepository::ipFlushMap_f_2_sm_17_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_17_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_2_sm_17_t_2[IPFlushRepository::ipFlushMap_f_2_sm_17_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_17_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_2_sm_17_t_3[IPFlushRepository::ipFlushMap_f_2_sm_17_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_17_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_2_sm_17_t_4[IPFlushRepository::ipFlushMap_f_2_sm_17_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_17_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_2_sm_17_t_5[IPFlushRepository::ipFlushMap_f_2_sm_17_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_17_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_2_sm_17_t_6[IPFlushRepository::ipFlushMap_f_2_sm_17_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_17_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_2_sm_17_t_7[IPFlushRepository::ipFlushMap_f_2_sm_17_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_17_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_2_sm_17_t_8[IPFlushRepository::ipFlushMap_f_2_sm_17_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_17_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_2_sm_17_t_9[IPFlushRepository::ipFlushMap_f_2_sm_17_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_17_t_9_cnt++;
						break;
					}
					break;
			case 18:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_2_sm_18_t_0[IPFlushRepository::ipFlushMap_f_2_sm_18_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_18_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_2_sm_18_t_1[IPFlushRepository::ipFlushMap_f_2_sm_18_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_18_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_2_sm_18_t_2[IPFlushRepository::ipFlushMap_f_2_sm_18_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_18_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_2_sm_18_t_3[IPFlushRepository::ipFlushMap_f_2_sm_18_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_18_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_2_sm_18_t_4[IPFlushRepository::ipFlushMap_f_2_sm_18_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_18_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_2_sm_18_t_5[IPFlushRepository::ipFlushMap_f_2_sm_18_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_18_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_2_sm_18_t_6[IPFlushRepository::ipFlushMap_f_2_sm_18_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_18_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_2_sm_18_t_7[IPFlushRepository::ipFlushMap_f_2_sm_18_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_18_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_2_sm_18_t_8[IPFlushRepository::ipFlushMap_f_2_sm_18_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_18_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_2_sm_18_t_9[IPFlushRepository::ipFlushMap_f_2_sm_18_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_18_t_9_cnt++;
						break;
					}
					break;
			case 19:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_2_sm_19_t_0[IPFlushRepository::ipFlushMap_f_2_sm_19_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_19_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_2_sm_19_t_1[IPFlushRepository::ipFlushMap_f_2_sm_19_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_19_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_2_sm_19_t_2[IPFlushRepository::ipFlushMap_f_2_sm_19_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_19_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_2_sm_19_t_3[IPFlushRepository::ipFlushMap_f_2_sm_19_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_19_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_2_sm_19_t_4[IPFlushRepository::ipFlushMap_f_2_sm_19_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_19_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_2_sm_19_t_5[IPFlushRepository::ipFlushMap_f_2_sm_19_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_19_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_2_sm_19_t_6[IPFlushRepository::ipFlushMap_f_2_sm_19_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_19_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_2_sm_19_t_7[IPFlushRepository::ipFlushMap_f_2_sm_19_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_19_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_2_sm_19_t_8[IPFlushRepository::ipFlushMap_f_2_sm_19_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_19_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_2_sm_19_t_9[IPFlushRepository::ipFlushMap_f_2_sm_19_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_19_t_9_cnt++;
						break;
					}
					break;
			case 20:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_2_sm_20_t_0[IPFlushRepository::ipFlushMap_f_2_sm_20_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_20_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_2_sm_20_t_1[IPFlushRepository::ipFlushMap_f_2_sm_20_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_20_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_2_sm_20_t_2[IPFlushRepository::ipFlushMap_f_2_sm_20_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_20_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_2_sm_20_t_3[IPFlushRepository::ipFlushMap_f_2_sm_20_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_20_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_2_sm_20_t_4[IPFlushRepository::ipFlushMap_f_2_sm_20_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_20_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_2_sm_20_t_5[IPFlushRepository::ipFlushMap_f_2_sm_20_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_20_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_2_sm_20_t_6[IPFlushRepository::ipFlushMap_f_2_sm_20_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_20_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_2_sm_20_t_7[IPFlushRepository::ipFlushMap_f_2_sm_20_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_20_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_2_sm_20_t_8[IPFlushRepository::ipFlushMap_f_2_sm_20_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_20_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_2_sm_20_t_9[IPFlushRepository::ipFlushMap_f_2_sm_20_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_20_t_9_cnt++;
						break;
					}
					break;
			case 21:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_2_sm_21_t_0[IPFlushRepository::ipFlushMap_f_2_sm_21_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_21_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_2_sm_21_t_1[IPFlushRepository::ipFlushMap_f_2_sm_21_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_21_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_2_sm_21_t_2[IPFlushRepository::ipFlushMap_f_2_sm_21_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_21_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_2_sm_21_t_3[IPFlushRepository::ipFlushMap_f_2_sm_21_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_21_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_2_sm_21_t_4[IPFlushRepository::ipFlushMap_f_2_sm_21_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_21_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_2_sm_21_t_5[IPFlushRepository::ipFlushMap_f_2_sm_21_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_21_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_2_sm_21_t_6[IPFlushRepository::ipFlushMap_f_2_sm_21_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_21_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_2_sm_21_t_7[IPFlushRepository::ipFlushMap_f_2_sm_21_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_21_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_2_sm_21_t_8[IPFlushRepository::ipFlushMap_f_2_sm_21_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_21_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_2_sm_21_t_9[IPFlushRepository::ipFlushMap_f_2_sm_21_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_21_t_9_cnt++;
						break;
					}
					break;
			case 22:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_2_sm_22_t_0[IPFlushRepository::ipFlushMap_f_2_sm_22_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_22_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_2_sm_22_t_1[IPFlushRepository::ipFlushMap_f_2_sm_22_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_22_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_2_sm_22_t_2[IPFlushRepository::ipFlushMap_f_2_sm_22_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_22_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_2_sm_22_t_3[IPFlushRepository::ipFlushMap_f_2_sm_22_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_22_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_2_sm_22_t_4[IPFlushRepository::ipFlushMap_f_2_sm_22_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_22_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_2_sm_22_t_5[IPFlushRepository::ipFlushMap_f_2_sm_22_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_22_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_2_sm_22_t_6[IPFlushRepository::ipFlushMap_f_2_sm_22_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_22_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_2_sm_22_t_7[IPFlushRepository::ipFlushMap_f_2_sm_22_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_22_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_2_sm_22_t_8[IPFlushRepository::ipFlushMap_f_2_sm_22_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_22_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_2_sm_22_t_9[IPFlushRepository::ipFlushMap_f_2_sm_22_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_22_t_9_cnt++;
						break;
					}
					break;
			case 23:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_2_sm_23_t_0[IPFlushRepository::ipFlushMap_f_2_sm_23_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_23_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_2_sm_23_t_1[IPFlushRepository::ipFlushMap_f_2_sm_23_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_23_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_2_sm_23_t_2[IPFlushRepository::ipFlushMap_f_2_sm_23_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_23_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_2_sm_23_t_3[IPFlushRepository::ipFlushMap_f_2_sm_23_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_23_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_2_sm_23_t_4[IPFlushRepository::ipFlushMap_f_2_sm_23_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_23_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_2_sm_23_t_5[IPFlushRepository::ipFlushMap_f_2_sm_23_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_23_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_2_sm_23_t_6[IPFlushRepository::ipFlushMap_f_2_sm_23_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_23_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_2_sm_23_t_7[IPFlushRepository::ipFlushMap_f_2_sm_23_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_23_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_2_sm_23_t_8[IPFlushRepository::ipFlushMap_f_2_sm_23_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_23_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_2_sm_23_t_9[IPFlushRepository::ipFlushMap_f_2_sm_23_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_23_t_9_cnt++;
						break;
					}
					break;
			case 24:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_2_sm_24_t_0[IPFlushRepository::ipFlushMap_f_2_sm_24_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_24_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_2_sm_24_t_1[IPFlushRepository::ipFlushMap_f_2_sm_24_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_24_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_2_sm_24_t_2[IPFlushRepository::ipFlushMap_f_2_sm_24_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_24_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_2_sm_24_t_3[IPFlushRepository::ipFlushMap_f_2_sm_24_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_24_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_2_sm_24_t_4[IPFlushRepository::ipFlushMap_f_2_sm_24_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_24_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_2_sm_24_t_5[IPFlushRepository::ipFlushMap_f_2_sm_24_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_24_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_2_sm_24_t_6[IPFlushRepository::ipFlushMap_f_2_sm_24_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_24_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_2_sm_24_t_7[IPFlushRepository::ipFlushMap_f_2_sm_24_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_24_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_2_sm_24_t_8[IPFlushRepository::ipFlushMap_f_2_sm_24_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_24_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_2_sm_24_t_9[IPFlushRepository::ipFlushMap_f_2_sm_24_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_24_t_9_cnt++;
						break;
					}
					break;
			case 25:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_2_sm_25_t_0[IPFlushRepository::ipFlushMap_f_2_sm_25_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_25_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_2_sm_25_t_1[IPFlushRepository::ipFlushMap_f_2_sm_25_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_25_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_2_sm_25_t_2[IPFlushRepository::ipFlushMap_f_2_sm_25_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_25_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_2_sm_25_t_3[IPFlushRepository::ipFlushMap_f_2_sm_25_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_25_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_2_sm_25_t_4[IPFlushRepository::ipFlushMap_f_2_sm_25_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_25_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_2_sm_25_t_5[IPFlushRepository::ipFlushMap_f_2_sm_25_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_25_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_2_sm_25_t_6[IPFlushRepository::ipFlushMap_f_2_sm_25_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_25_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_2_sm_25_t_7[IPFlushRepository::ipFlushMap_f_2_sm_25_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_25_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_2_sm_25_t_8[IPFlushRepository::ipFlushMap_f_2_sm_25_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_25_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_2_sm_25_t_9[IPFlushRepository::ipFlushMap_f_2_sm_25_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_25_t_9_cnt++;
						break;
					}
					break;
			case 26:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_2_sm_26_t_0[IPFlushRepository::ipFlushMap_f_2_sm_26_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_26_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_2_sm_26_t_1[IPFlushRepository::ipFlushMap_f_2_sm_26_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_26_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_2_sm_26_t_2[IPFlushRepository::ipFlushMap_f_2_sm_26_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_26_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_2_sm_26_t_3[IPFlushRepository::ipFlushMap_f_2_sm_26_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_26_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_2_sm_26_t_4[IPFlushRepository::ipFlushMap_f_2_sm_26_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_26_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_2_sm_26_t_5[IPFlushRepository::ipFlushMap_f_2_sm_26_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_26_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_2_sm_26_t_6[IPFlushRepository::ipFlushMap_f_2_sm_26_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_26_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_2_sm_26_t_7[IPFlushRepository::ipFlushMap_f_2_sm_26_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_26_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_2_sm_26_t_8[IPFlushRepository::ipFlushMap_f_2_sm_26_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_26_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_2_sm_26_t_9[IPFlushRepository::ipFlushMap_f_2_sm_26_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_26_t_9_cnt++;
						break;
					}
					break;
			case 27:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_2_sm_27_t_0[IPFlushRepository::ipFlushMap_f_2_sm_27_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_27_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_2_sm_27_t_1[IPFlushRepository::ipFlushMap_f_2_sm_27_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_27_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_2_sm_27_t_2[IPFlushRepository::ipFlushMap_f_2_sm_27_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_27_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_2_sm_27_t_3[IPFlushRepository::ipFlushMap_f_2_sm_27_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_27_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_2_sm_27_t_4[IPFlushRepository::ipFlushMap_f_2_sm_27_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_27_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_2_sm_27_t_5[IPFlushRepository::ipFlushMap_f_2_sm_27_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_27_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_2_sm_27_t_6[IPFlushRepository::ipFlushMap_f_2_sm_27_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_27_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_2_sm_27_t_7[IPFlushRepository::ipFlushMap_f_2_sm_27_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_27_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_2_sm_27_t_8[IPFlushRepository::ipFlushMap_f_2_sm_27_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_27_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_2_sm_27_t_9[IPFlushRepository::ipFlushMap_f_2_sm_27_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_27_t_9_cnt++;
						break;
					}
					break;
			case 28:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_2_sm_28_t_0[IPFlushRepository::ipFlushMap_f_2_sm_28_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_28_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_2_sm_28_t_1[IPFlushRepository::ipFlushMap_f_2_sm_28_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_28_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_2_sm_28_t_2[IPFlushRepository::ipFlushMap_f_2_sm_28_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_28_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_2_sm_28_t_3[IPFlushRepository::ipFlushMap_f_2_sm_28_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_28_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_2_sm_28_t_4[IPFlushRepository::ipFlushMap_f_2_sm_28_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_28_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_2_sm_28_t_5[IPFlushRepository::ipFlushMap_f_2_sm_28_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_28_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_2_sm_28_t_6[IPFlushRepository::ipFlushMap_f_2_sm_28_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_28_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_2_sm_28_t_7[IPFlushRepository::ipFlushMap_f_2_sm_28_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_28_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_2_sm_28_t_8[IPFlushRepository::ipFlushMap_f_2_sm_28_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_28_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_2_sm_28_t_9[IPFlushRepository::ipFlushMap_f_2_sm_28_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_28_t_9_cnt++;
						break;
					}
					break;
			case 29:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_2_sm_29_t_0[IPFlushRepository::ipFlushMap_f_2_sm_29_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_29_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_2_sm_29_t_1[IPFlushRepository::ipFlushMap_f_2_sm_29_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_29_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_2_sm_29_t_2[IPFlushRepository::ipFlushMap_f_2_sm_29_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_29_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_2_sm_29_t_3[IPFlushRepository::ipFlushMap_f_2_sm_29_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_29_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_2_sm_29_t_4[IPFlushRepository::ipFlushMap_f_2_sm_29_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_29_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_2_sm_29_t_5[IPFlushRepository::ipFlushMap_f_2_sm_29_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_29_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_2_sm_29_t_6[IPFlushRepository::ipFlushMap_f_2_sm_29_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_29_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_2_sm_29_t_7[IPFlushRepository::ipFlushMap_f_2_sm_29_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_29_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_2_sm_29_t_8[IPFlushRepository::ipFlushMap_f_2_sm_29_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_29_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_2_sm_29_t_9[IPFlushRepository::ipFlushMap_f_2_sm_29_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_2_sm_29_t_9_cnt++;
						break;
					}
					break;
	}
}

VOID S1UInterface::storeIpSession_f_3(int index1, ipSession *pIpSession)
{
	int index = PKT_WRITE_TIME_INDEX(IPGlobal::CURRENT_EPOCH_SEC, IPGlobal::PKT_TIME_INDEX);

	switch(instanceId)
	{
			case 0:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_3_sm_0_t_0[IPFlushRepository::ipFlushMap_f_3_sm_0_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_0_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_3_sm_0_t_1[IPFlushRepository::ipFlushMap_f_3_sm_0_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_0_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_3_sm_0_t_2[IPFlushRepository::ipFlushMap_f_3_sm_0_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_0_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_3_sm_0_t_3[IPFlushRepository::ipFlushMap_f_3_sm_0_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_0_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_3_sm_0_t_4[IPFlushRepository::ipFlushMap_f_3_sm_0_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_0_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_3_sm_0_t_5[IPFlushRepository::ipFlushMap_f_3_sm_0_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_0_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_3_sm_0_t_6[IPFlushRepository::ipFlushMap_f_3_sm_0_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_0_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_3_sm_0_t_7[IPFlushRepository::ipFlushMap_f_3_sm_0_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_0_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_3_sm_0_t_8[IPFlushRepository::ipFlushMap_f_3_sm_0_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_0_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_3_sm_0_t_9[IPFlushRepository::ipFlushMap_f_3_sm_0_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_0_t_9_cnt++;
						break;
					}
					break;

			case 1:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_3_sm_1_t_0[IPFlushRepository::ipFlushMap_f_3_sm_1_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_1_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_3_sm_1_t_1[IPFlushRepository::ipFlushMap_f_3_sm_1_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_1_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_3_sm_1_t_2[IPFlushRepository::ipFlushMap_f_3_sm_1_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_1_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_3_sm_1_t_3[IPFlushRepository::ipFlushMap_f_3_sm_1_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_1_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_3_sm_1_t_4[IPFlushRepository::ipFlushMap_f_3_sm_1_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_1_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_3_sm_1_t_5[IPFlushRepository::ipFlushMap_f_3_sm_1_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_1_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_3_sm_1_t_6[IPFlushRepository::ipFlushMap_f_3_sm_1_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_1_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_3_sm_1_t_7[IPFlushRepository::ipFlushMap_f_3_sm_1_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_1_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_3_sm_1_t_8[IPFlushRepository::ipFlushMap_f_3_sm_1_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_1_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_3_sm_1_t_9[IPFlushRepository::ipFlushMap_f_3_sm_1_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_1_t_9_cnt++;
						break;
					}
					break;
			case 2:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_3_sm_2_t_0[IPFlushRepository::ipFlushMap_f_3_sm_2_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_2_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_3_sm_2_t_1[IPFlushRepository::ipFlushMap_f_3_sm_2_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_2_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_3_sm_2_t_2[IPFlushRepository::ipFlushMap_f_3_sm_2_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_2_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_3_sm_2_t_3[IPFlushRepository::ipFlushMap_f_3_sm_2_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_2_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_3_sm_2_t_4[IPFlushRepository::ipFlushMap_f_3_sm_2_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_2_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_3_sm_2_t_5[IPFlushRepository::ipFlushMap_f_3_sm_2_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_2_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_3_sm_2_t_6[IPFlushRepository::ipFlushMap_f_3_sm_2_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_2_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_3_sm_2_t_7[IPFlushRepository::ipFlushMap_f_3_sm_2_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_2_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_3_sm_2_t_8[IPFlushRepository::ipFlushMap_f_3_sm_2_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_2_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_3_sm_2_t_9[IPFlushRepository::ipFlushMap_f_3_sm_2_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_2_t_9_cnt++;
						break;
					}
					break;

			case 3:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_3_sm_3_t_0[IPFlushRepository::ipFlushMap_f_3_sm_3_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_3_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_3_sm_3_t_1[IPFlushRepository::ipFlushMap_f_3_sm_3_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_3_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_3_sm_3_t_2[IPFlushRepository::ipFlushMap_f_3_sm_3_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_3_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_3_sm_3_t_3[IPFlushRepository::ipFlushMap_f_3_sm_3_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_3_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_3_sm_3_t_4[IPFlushRepository::ipFlushMap_f_3_sm_3_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_3_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_3_sm_3_t_5[IPFlushRepository::ipFlushMap_f_3_sm_3_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_3_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_3_sm_3_t_6[IPFlushRepository::ipFlushMap_f_3_sm_3_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_3_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_3_sm_3_t_7[IPFlushRepository::ipFlushMap_f_3_sm_3_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_3_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_3_sm_3_t_8[IPFlushRepository::ipFlushMap_f_3_sm_3_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_3_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_3_sm_3_t_9[IPFlushRepository::ipFlushMap_f_3_sm_3_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_3_t_9_cnt++;
						break;
					}
					break;

			case 4:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_3_sm_4_t_0[IPFlushRepository::ipFlushMap_f_3_sm_4_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_4_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_3_sm_4_t_1[IPFlushRepository::ipFlushMap_f_3_sm_4_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_4_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_3_sm_4_t_2[IPFlushRepository::ipFlushMap_f_3_sm_4_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_4_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_3_sm_4_t_3[IPFlushRepository::ipFlushMap_f_3_sm_4_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_4_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_3_sm_4_t_4[IPFlushRepository::ipFlushMap_f_3_sm_4_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_4_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_3_sm_4_t_5[IPFlushRepository::ipFlushMap_f_3_sm_4_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_4_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_3_sm_4_t_6[IPFlushRepository::ipFlushMap_f_3_sm_4_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_4_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_3_sm_4_t_7[IPFlushRepository::ipFlushMap_f_3_sm_4_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_4_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_3_sm_4_t_8[IPFlushRepository::ipFlushMap_f_3_sm_4_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_4_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_3_sm_4_t_9[IPFlushRepository::ipFlushMap_f_3_sm_4_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_4_t_9_cnt++;
						break;
					}
					break;

			case 5:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_3_sm_5_t_0[IPFlushRepository::ipFlushMap_f_3_sm_5_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_5_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_3_sm_5_t_1[IPFlushRepository::ipFlushMap_f_3_sm_5_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_5_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_3_sm_5_t_2[IPFlushRepository::ipFlushMap_f_3_sm_5_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_5_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_3_sm_5_t_3[IPFlushRepository::ipFlushMap_f_3_sm_5_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_5_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_3_sm_5_t_4[IPFlushRepository::ipFlushMap_f_3_sm_5_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_5_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_3_sm_5_t_5[IPFlushRepository::ipFlushMap_f_3_sm_5_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_5_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_3_sm_5_t_6[IPFlushRepository::ipFlushMap_f_3_sm_5_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_5_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_3_sm_5_t_7[IPFlushRepository::ipFlushMap_f_3_sm_5_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_5_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_3_sm_5_t_8[IPFlushRepository::ipFlushMap_f_3_sm_5_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_5_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_3_sm_5_t_9[IPFlushRepository::ipFlushMap_f_3_sm_5_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_5_t_9_cnt++;
						break;
					}
					break;

			case 6:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_3_sm_6_t_0[IPFlushRepository::ipFlushMap_f_3_sm_6_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_6_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_3_sm_6_t_1[IPFlushRepository::ipFlushMap_f_3_sm_6_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_6_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_3_sm_6_t_2[IPFlushRepository::ipFlushMap_f_3_sm_6_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_6_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_3_sm_6_t_3[IPFlushRepository::ipFlushMap_f_3_sm_6_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_6_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_3_sm_6_t_4[IPFlushRepository::ipFlushMap_f_3_sm_6_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_6_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_3_sm_6_t_5[IPFlushRepository::ipFlushMap_f_3_sm_6_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_6_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_3_sm_6_t_6[IPFlushRepository::ipFlushMap_f_3_sm_6_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_6_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_3_sm_6_t_7[IPFlushRepository::ipFlushMap_f_3_sm_6_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_6_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_3_sm_6_t_8[IPFlushRepository::ipFlushMap_f_3_sm_6_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_6_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_3_sm_6_t_9[IPFlushRepository::ipFlushMap_f_3_sm_6_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_6_t_9_cnt++;
						break;
					}
					break;
			case 7:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_3_sm_7_t_0[IPFlushRepository::ipFlushMap_f_3_sm_7_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_7_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_3_sm_7_t_1[IPFlushRepository::ipFlushMap_f_3_sm_7_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_7_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_3_sm_7_t_2[IPFlushRepository::ipFlushMap_f_3_sm_7_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_7_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_3_sm_7_t_3[IPFlushRepository::ipFlushMap_f_3_sm_7_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_7_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_3_sm_7_t_4[IPFlushRepository::ipFlushMap_f_3_sm_7_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_7_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_3_sm_7_t_5[IPFlushRepository::ipFlushMap_f_3_sm_7_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_7_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_3_sm_7_t_6[IPFlushRepository::ipFlushMap_f_3_sm_7_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_7_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_3_sm_7_t_7[IPFlushRepository::ipFlushMap_f_3_sm_7_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_7_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_3_sm_7_t_8[IPFlushRepository::ipFlushMap_f_3_sm_7_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_7_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_3_sm_7_t_9[IPFlushRepository::ipFlushMap_f_3_sm_7_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_7_t_9_cnt++;
						break;
					}
					break;
			case 8:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_3_sm_8_t_0[IPFlushRepository::ipFlushMap_f_3_sm_8_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_8_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_3_sm_8_t_1[IPFlushRepository::ipFlushMap_f_3_sm_8_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_8_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_3_sm_8_t_2[IPFlushRepository::ipFlushMap_f_3_sm_8_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_8_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_3_sm_8_t_3[IPFlushRepository::ipFlushMap_f_3_sm_8_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_8_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_3_sm_8_t_4[IPFlushRepository::ipFlushMap_f_3_sm_8_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_8_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_3_sm_8_t_5[IPFlushRepository::ipFlushMap_f_3_sm_8_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_8_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_3_sm_8_t_6[IPFlushRepository::ipFlushMap_f_3_sm_8_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_8_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_3_sm_8_t_7[IPFlushRepository::ipFlushMap_f_3_sm_8_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_8_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_3_sm_8_t_8[IPFlushRepository::ipFlushMap_f_3_sm_8_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_8_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_3_sm_8_t_9[IPFlushRepository::ipFlushMap_f_3_sm_8_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_8_t_9_cnt++;
						break;
					}
					break;
			case 9:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_3_sm_9_t_0[IPFlushRepository::ipFlushMap_f_3_sm_9_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_9_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_3_sm_9_t_1[IPFlushRepository::ipFlushMap_f_3_sm_9_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_9_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_3_sm_9_t_2[IPFlushRepository::ipFlushMap_f_3_sm_9_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_9_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_3_sm_9_t_3[IPFlushRepository::ipFlushMap_f_3_sm_9_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_9_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_3_sm_9_t_4[IPFlushRepository::ipFlushMap_f_3_sm_9_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_9_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_3_sm_9_t_5[IPFlushRepository::ipFlushMap_f_3_sm_9_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_9_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_3_sm_9_t_6[IPFlushRepository::ipFlushMap_f_3_sm_9_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_9_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_3_sm_9_t_7[IPFlushRepository::ipFlushMap_f_3_sm_9_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_9_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_3_sm_9_t_8[IPFlushRepository::ipFlushMap_f_3_sm_9_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_9_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_3_sm_9_t_9[IPFlushRepository::ipFlushMap_f_3_sm_9_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_9_t_9_cnt++;
						break;
					}
					break;
			case 10:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_3_sm_10_t_0[IPFlushRepository::ipFlushMap_f_3_sm_10_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_10_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_3_sm_10_t_1[IPFlushRepository::ipFlushMap_f_3_sm_10_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_10_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_3_sm_10_t_2[IPFlushRepository::ipFlushMap_f_3_sm_10_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_10_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_3_sm_10_t_3[IPFlushRepository::ipFlushMap_f_3_sm_10_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_10_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_3_sm_10_t_4[IPFlushRepository::ipFlushMap_f_3_sm_10_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_10_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_3_sm_10_t_5[IPFlushRepository::ipFlushMap_f_3_sm_10_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_10_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_3_sm_10_t_6[IPFlushRepository::ipFlushMap_f_3_sm_10_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_10_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_3_sm_10_t_7[IPFlushRepository::ipFlushMap_f_3_sm_10_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_10_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_3_sm_10_t_8[IPFlushRepository::ipFlushMap_f_3_sm_10_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_10_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_3_sm_10_t_9[IPFlushRepository::ipFlushMap_f_3_sm_10_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_10_t_9_cnt++;
						break;
					}
					break;
			case 11:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_3_sm_11_t_0[IPFlushRepository::ipFlushMap_f_3_sm_11_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_11_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_3_sm_11_t_1[IPFlushRepository::ipFlushMap_f_3_sm_11_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_11_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_3_sm_11_t_2[IPFlushRepository::ipFlushMap_f_3_sm_11_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_11_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_3_sm_11_t_3[IPFlushRepository::ipFlushMap_f_3_sm_11_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_11_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_3_sm_11_t_4[IPFlushRepository::ipFlushMap_f_3_sm_11_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_11_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_3_sm_11_t_5[IPFlushRepository::ipFlushMap_f_3_sm_11_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_11_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_3_sm_11_t_6[IPFlushRepository::ipFlushMap_f_3_sm_11_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_11_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_3_sm_11_t_7[IPFlushRepository::ipFlushMap_f_3_sm_11_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_11_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_3_sm_11_t_8[IPFlushRepository::ipFlushMap_f_3_sm_11_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_11_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_3_sm_11_t_9[IPFlushRepository::ipFlushMap_f_3_sm_11_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_11_t_9_cnt++;
						break;
					}
					break;
			case 12:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_3_sm_12_t_0[IPFlushRepository::ipFlushMap_f_3_sm_12_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_12_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_3_sm_12_t_1[IPFlushRepository::ipFlushMap_f_3_sm_12_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_12_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_3_sm_12_t_2[IPFlushRepository::ipFlushMap_f_3_sm_12_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_12_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_3_sm_12_t_3[IPFlushRepository::ipFlushMap_f_3_sm_12_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_12_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_3_sm_12_t_4[IPFlushRepository::ipFlushMap_f_3_sm_12_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_12_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_3_sm_12_t_5[IPFlushRepository::ipFlushMap_f_3_sm_12_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_12_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_3_sm_12_t_6[IPFlushRepository::ipFlushMap_f_3_sm_12_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_12_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_3_sm_12_t_7[IPFlushRepository::ipFlushMap_f_3_sm_12_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_12_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_3_sm_12_t_8[IPFlushRepository::ipFlushMap_f_3_sm_12_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_12_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_3_sm_12_t_9[IPFlushRepository::ipFlushMap_f_3_sm_12_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_12_t_9_cnt++;
						break;
					}
					break;
			case 13:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_3_sm_13_t_0[IPFlushRepository::ipFlushMap_f_3_sm_13_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_13_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_3_sm_13_t_1[IPFlushRepository::ipFlushMap_f_3_sm_13_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_13_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_3_sm_13_t_2[IPFlushRepository::ipFlushMap_f_3_sm_13_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_13_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_3_sm_13_t_3[IPFlushRepository::ipFlushMap_f_3_sm_13_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_13_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_3_sm_13_t_4[IPFlushRepository::ipFlushMap_f_3_sm_13_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_13_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_3_sm_13_t_5[IPFlushRepository::ipFlushMap_f_3_sm_13_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_13_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_3_sm_13_t_6[IPFlushRepository::ipFlushMap_f_3_sm_13_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_13_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_3_sm_13_t_7[IPFlushRepository::ipFlushMap_f_3_sm_13_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_13_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_3_sm_13_t_8[IPFlushRepository::ipFlushMap_f_3_sm_13_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_13_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_3_sm_13_t_9[IPFlushRepository::ipFlushMap_f_3_sm_13_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_13_t_9_cnt++;
						break;
					}
					break;
			case 14:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_3_sm_14_t_0[IPFlushRepository::ipFlushMap_f_3_sm_14_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_14_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_3_sm_14_t_1[IPFlushRepository::ipFlushMap_f_3_sm_14_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_14_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_3_sm_14_t_2[IPFlushRepository::ipFlushMap_f_3_sm_14_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_14_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_3_sm_14_t_3[IPFlushRepository::ipFlushMap_f_3_sm_14_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_14_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_3_sm_14_t_4[IPFlushRepository::ipFlushMap_f_3_sm_14_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_14_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_3_sm_14_t_5[IPFlushRepository::ipFlushMap_f_3_sm_14_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_14_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_3_sm_14_t_6[IPFlushRepository::ipFlushMap_f_3_sm_14_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_14_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_3_sm_14_t_7[IPFlushRepository::ipFlushMap_f_3_sm_14_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_14_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_3_sm_14_t_8[IPFlushRepository::ipFlushMap_f_3_sm_14_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_14_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_3_sm_14_t_9[IPFlushRepository::ipFlushMap_f_3_sm_14_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_14_t_9_cnt++;
						break;
					}
					break;
			case 15:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_3_sm_15_t_0[IPFlushRepository::ipFlushMap_f_3_sm_15_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_15_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_3_sm_15_t_1[IPFlushRepository::ipFlushMap_f_3_sm_15_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_15_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_3_sm_15_t_2[IPFlushRepository::ipFlushMap_f_3_sm_15_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_15_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_3_sm_15_t_3[IPFlushRepository::ipFlushMap_f_3_sm_15_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_15_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_3_sm_15_t_4[IPFlushRepository::ipFlushMap_f_3_sm_15_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_15_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_3_sm_15_t_5[IPFlushRepository::ipFlushMap_f_3_sm_15_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_15_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_3_sm_15_t_6[IPFlushRepository::ipFlushMap_f_3_sm_15_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_15_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_3_sm_15_t_7[IPFlushRepository::ipFlushMap_f_3_sm_15_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_15_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_3_sm_15_t_8[IPFlushRepository::ipFlushMap_f_3_sm_15_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_15_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_3_sm_15_t_9[IPFlushRepository::ipFlushMap_f_3_sm_15_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_15_t_9_cnt++;
						break;
					}
					break;
			case 16:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_3_sm_16_t_0[IPFlushRepository::ipFlushMap_f_3_sm_16_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_16_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_3_sm_16_t_1[IPFlushRepository::ipFlushMap_f_3_sm_16_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_16_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_3_sm_16_t_2[IPFlushRepository::ipFlushMap_f_3_sm_16_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_16_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_3_sm_16_t_3[IPFlushRepository::ipFlushMap_f_3_sm_16_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_16_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_3_sm_16_t_4[IPFlushRepository::ipFlushMap_f_3_sm_16_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_16_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_3_sm_16_t_5[IPFlushRepository::ipFlushMap_f_3_sm_16_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_16_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_3_sm_16_t_6[IPFlushRepository::ipFlushMap_f_3_sm_16_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_16_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_3_sm_16_t_7[IPFlushRepository::ipFlushMap_f_3_sm_16_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_16_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_3_sm_16_t_8[IPFlushRepository::ipFlushMap_f_3_sm_16_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_16_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_3_sm_16_t_9[IPFlushRepository::ipFlushMap_f_3_sm_16_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_16_t_9_cnt++;
						break;
					}
					break;
			case 17:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_3_sm_17_t_0[IPFlushRepository::ipFlushMap_f_3_sm_17_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_17_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_3_sm_17_t_1[IPFlushRepository::ipFlushMap_f_3_sm_17_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_17_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_3_sm_17_t_2[IPFlushRepository::ipFlushMap_f_3_sm_17_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_17_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_3_sm_17_t_3[IPFlushRepository::ipFlushMap_f_3_sm_17_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_17_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_3_sm_17_t_4[IPFlushRepository::ipFlushMap_f_3_sm_17_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_17_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_3_sm_17_t_5[IPFlushRepository::ipFlushMap_f_3_sm_17_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_17_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_3_sm_17_t_6[IPFlushRepository::ipFlushMap_f_3_sm_17_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_17_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_3_sm_17_t_7[IPFlushRepository::ipFlushMap_f_3_sm_17_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_17_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_3_sm_17_t_8[IPFlushRepository::ipFlushMap_f_3_sm_17_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_17_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_3_sm_17_t_9[IPFlushRepository::ipFlushMap_f_3_sm_17_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_17_t_9_cnt++;
						break;
					}
					break;
			case 18:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_3_sm_18_t_0[IPFlushRepository::ipFlushMap_f_3_sm_18_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_18_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_3_sm_18_t_1[IPFlushRepository::ipFlushMap_f_3_sm_18_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_18_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_3_sm_18_t_2[IPFlushRepository::ipFlushMap_f_3_sm_18_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_18_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_3_sm_18_t_3[IPFlushRepository::ipFlushMap_f_3_sm_18_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_18_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_3_sm_18_t_4[IPFlushRepository::ipFlushMap_f_3_sm_18_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_18_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_3_sm_18_t_5[IPFlushRepository::ipFlushMap_f_3_sm_18_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_18_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_3_sm_18_t_6[IPFlushRepository::ipFlushMap_f_3_sm_18_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_18_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_3_sm_18_t_7[IPFlushRepository::ipFlushMap_f_3_sm_18_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_18_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_3_sm_18_t_8[IPFlushRepository::ipFlushMap_f_3_sm_18_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_18_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_3_sm_18_t_9[IPFlushRepository::ipFlushMap_f_3_sm_18_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_18_t_9_cnt++;
						break;
					}
					break;
			case 19:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_3_sm_19_t_0[IPFlushRepository::ipFlushMap_f_3_sm_19_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_19_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_3_sm_19_t_1[IPFlushRepository::ipFlushMap_f_3_sm_19_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_19_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_3_sm_19_t_2[IPFlushRepository::ipFlushMap_f_3_sm_19_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_19_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_3_sm_19_t_3[IPFlushRepository::ipFlushMap_f_3_sm_19_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_19_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_3_sm_19_t_4[IPFlushRepository::ipFlushMap_f_3_sm_19_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_19_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_3_sm_19_t_5[IPFlushRepository::ipFlushMap_f_3_sm_19_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_19_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_3_sm_19_t_6[IPFlushRepository::ipFlushMap_f_3_sm_19_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_19_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_3_sm_19_t_7[IPFlushRepository::ipFlushMap_f_3_sm_19_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_19_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_3_sm_19_t_8[IPFlushRepository::ipFlushMap_f_3_sm_19_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_19_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_3_sm_19_t_9[IPFlushRepository::ipFlushMap_f_3_sm_19_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_19_t_9_cnt++;
						break;
					}
					break;
			case 20:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_3_sm_20_t_0[IPFlushRepository::ipFlushMap_f_3_sm_20_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_20_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_3_sm_20_t_1[IPFlushRepository::ipFlushMap_f_3_sm_20_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_20_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_3_sm_20_t_2[IPFlushRepository::ipFlushMap_f_3_sm_20_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_20_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_3_sm_20_t_3[IPFlushRepository::ipFlushMap_f_3_sm_20_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_20_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_3_sm_20_t_4[IPFlushRepository::ipFlushMap_f_3_sm_20_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_20_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_3_sm_20_t_5[IPFlushRepository::ipFlushMap_f_3_sm_20_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_20_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_3_sm_20_t_6[IPFlushRepository::ipFlushMap_f_3_sm_20_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_20_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_3_sm_20_t_7[IPFlushRepository::ipFlushMap_f_3_sm_20_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_20_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_3_sm_20_t_8[IPFlushRepository::ipFlushMap_f_3_sm_20_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_20_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_3_sm_20_t_9[IPFlushRepository::ipFlushMap_f_3_sm_20_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_20_t_9_cnt++;
						break;
					}
					break;
			case 21:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_3_sm_21_t_0[IPFlushRepository::ipFlushMap_f_3_sm_21_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_21_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_3_sm_21_t_1[IPFlushRepository::ipFlushMap_f_3_sm_21_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_21_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_3_sm_21_t_2[IPFlushRepository::ipFlushMap_f_3_sm_21_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_21_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_3_sm_21_t_3[IPFlushRepository::ipFlushMap_f_3_sm_21_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_21_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_3_sm_21_t_4[IPFlushRepository::ipFlushMap_f_3_sm_21_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_21_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_3_sm_21_t_5[IPFlushRepository::ipFlushMap_f_3_sm_21_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_21_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_3_sm_21_t_6[IPFlushRepository::ipFlushMap_f_3_sm_21_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_21_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_3_sm_21_t_7[IPFlushRepository::ipFlushMap_f_3_sm_21_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_21_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_3_sm_21_t_8[IPFlushRepository::ipFlushMap_f_3_sm_21_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_21_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_3_sm_21_t_9[IPFlushRepository::ipFlushMap_f_3_sm_21_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_21_t_9_cnt++;
						break;
					}
					break;
			case 22:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_3_sm_22_t_0[IPFlushRepository::ipFlushMap_f_3_sm_22_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_22_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_3_sm_22_t_1[IPFlushRepository::ipFlushMap_f_3_sm_22_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_22_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_3_sm_22_t_2[IPFlushRepository::ipFlushMap_f_3_sm_22_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_22_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_3_sm_22_t_3[IPFlushRepository::ipFlushMap_f_3_sm_22_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_22_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_3_sm_22_t_4[IPFlushRepository::ipFlushMap_f_3_sm_22_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_22_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_3_sm_22_t_5[IPFlushRepository::ipFlushMap_f_3_sm_22_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_22_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_3_sm_22_t_6[IPFlushRepository::ipFlushMap_f_3_sm_22_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_22_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_3_sm_22_t_7[IPFlushRepository::ipFlushMap_f_3_sm_22_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_22_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_3_sm_22_t_8[IPFlushRepository::ipFlushMap_f_3_sm_22_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_22_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_3_sm_22_t_9[IPFlushRepository::ipFlushMap_f_3_sm_22_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_22_t_9_cnt++;
						break;
					}
					break;
			case 23:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_3_sm_23_t_0[IPFlushRepository::ipFlushMap_f_3_sm_23_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_23_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_3_sm_23_t_1[IPFlushRepository::ipFlushMap_f_3_sm_23_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_23_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_3_sm_23_t_2[IPFlushRepository::ipFlushMap_f_3_sm_23_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_23_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_3_sm_23_t_3[IPFlushRepository::ipFlushMap_f_3_sm_23_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_23_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_3_sm_23_t_4[IPFlushRepository::ipFlushMap_f_3_sm_23_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_23_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_3_sm_23_t_5[IPFlushRepository::ipFlushMap_f_3_sm_23_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_23_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_3_sm_23_t_6[IPFlushRepository::ipFlushMap_f_3_sm_23_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_23_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_3_sm_23_t_7[IPFlushRepository::ipFlushMap_f_3_sm_23_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_23_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_3_sm_23_t_8[IPFlushRepository::ipFlushMap_f_3_sm_23_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_23_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_3_sm_23_t_9[IPFlushRepository::ipFlushMap_f_3_sm_23_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_23_t_9_cnt++;
						break;
					}
					break;
			case 24:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_3_sm_24_t_0[IPFlushRepository::ipFlushMap_f_3_sm_24_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_24_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_3_sm_24_t_1[IPFlushRepository::ipFlushMap_f_3_sm_24_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_24_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_3_sm_24_t_2[IPFlushRepository::ipFlushMap_f_3_sm_24_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_24_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_3_sm_24_t_3[IPFlushRepository::ipFlushMap_f_3_sm_24_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_24_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_3_sm_24_t_4[IPFlushRepository::ipFlushMap_f_3_sm_24_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_24_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_3_sm_24_t_5[IPFlushRepository::ipFlushMap_f_3_sm_24_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_24_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_3_sm_24_t_6[IPFlushRepository::ipFlushMap_f_3_sm_24_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_24_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_3_sm_24_t_7[IPFlushRepository::ipFlushMap_f_3_sm_24_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_24_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_3_sm_24_t_8[IPFlushRepository::ipFlushMap_f_3_sm_24_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_24_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_3_sm_24_t_9[IPFlushRepository::ipFlushMap_f_3_sm_24_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_24_t_9_cnt++;
						break;
					}
					break;
			case 25:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_3_sm_25_t_0[IPFlushRepository::ipFlushMap_f_3_sm_25_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_25_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_3_sm_25_t_1[IPFlushRepository::ipFlushMap_f_3_sm_25_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_25_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_3_sm_25_t_2[IPFlushRepository::ipFlushMap_f_3_sm_25_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_25_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_3_sm_25_t_3[IPFlushRepository::ipFlushMap_f_3_sm_25_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_25_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_3_sm_25_t_4[IPFlushRepository::ipFlushMap_f_3_sm_25_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_25_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_3_sm_25_t_5[IPFlushRepository::ipFlushMap_f_3_sm_25_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_25_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_3_sm_25_t_6[IPFlushRepository::ipFlushMap_f_3_sm_25_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_25_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_3_sm_25_t_7[IPFlushRepository::ipFlushMap_f_3_sm_25_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_25_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_3_sm_25_t_8[IPFlushRepository::ipFlushMap_f_3_sm_25_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_25_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_3_sm_25_t_9[IPFlushRepository::ipFlushMap_f_3_sm_25_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_25_t_9_cnt++;
						break;
					}
					break;
			case 26:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_3_sm_26_t_0[IPFlushRepository::ipFlushMap_f_3_sm_26_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_26_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_3_sm_26_t_1[IPFlushRepository::ipFlushMap_f_3_sm_26_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_26_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_3_sm_26_t_2[IPFlushRepository::ipFlushMap_f_3_sm_26_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_26_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_3_sm_26_t_3[IPFlushRepository::ipFlushMap_f_3_sm_26_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_26_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_3_sm_26_t_4[IPFlushRepository::ipFlushMap_f_3_sm_26_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_26_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_3_sm_26_t_5[IPFlushRepository::ipFlushMap_f_3_sm_26_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_26_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_3_sm_26_t_6[IPFlushRepository::ipFlushMap_f_3_sm_26_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_26_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_3_sm_26_t_7[IPFlushRepository::ipFlushMap_f_3_sm_26_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_26_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_3_sm_26_t_8[IPFlushRepository::ipFlushMap_f_3_sm_26_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_26_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_3_sm_26_t_9[IPFlushRepository::ipFlushMap_f_3_sm_26_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_26_t_9_cnt++;
						break;
					}
					break;
			case 27:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_3_sm_27_t_0[IPFlushRepository::ipFlushMap_f_3_sm_27_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_27_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_3_sm_27_t_1[IPFlushRepository::ipFlushMap_f_3_sm_27_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_27_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_3_sm_27_t_2[IPFlushRepository::ipFlushMap_f_3_sm_27_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_27_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_3_sm_27_t_3[IPFlushRepository::ipFlushMap_f_3_sm_27_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_27_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_3_sm_27_t_4[IPFlushRepository::ipFlushMap_f_3_sm_27_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_27_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_3_sm_27_t_5[IPFlushRepository::ipFlushMap_f_3_sm_27_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_27_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_3_sm_27_t_6[IPFlushRepository::ipFlushMap_f_3_sm_27_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_27_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_3_sm_27_t_7[IPFlushRepository::ipFlushMap_f_3_sm_27_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_27_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_3_sm_27_t_8[IPFlushRepository::ipFlushMap_f_3_sm_27_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_27_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_3_sm_27_t_9[IPFlushRepository::ipFlushMap_f_3_sm_27_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_27_t_9_cnt++;
						break;
					}
					break;
			case 28:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_3_sm_28_t_0[IPFlushRepository::ipFlushMap_f_3_sm_28_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_28_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_3_sm_28_t_1[IPFlushRepository::ipFlushMap_f_3_sm_28_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_28_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_3_sm_28_t_2[IPFlushRepository::ipFlushMap_f_3_sm_28_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_28_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_3_sm_28_t_3[IPFlushRepository::ipFlushMap_f_3_sm_28_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_28_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_3_sm_28_t_4[IPFlushRepository::ipFlushMap_f_3_sm_28_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_28_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_3_sm_28_t_5[IPFlushRepository::ipFlushMap_f_3_sm_28_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_28_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_3_sm_28_t_6[IPFlushRepository::ipFlushMap_f_3_sm_28_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_28_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_3_sm_28_t_7[IPFlushRepository::ipFlushMap_f_3_sm_28_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_28_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_3_sm_28_t_8[IPFlushRepository::ipFlushMap_f_3_sm_28_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_28_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_3_sm_28_t_9[IPFlushRepository::ipFlushMap_f_3_sm_28_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_28_t_9_cnt++;
						break;
					}
					break;
			case 29:
					switch(index)
					{
					case 0:
						IPFlushRepository::ipFlushMap_f_3_sm_29_t_0[IPFlushRepository::ipFlushMap_f_3_sm_29_t_0_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_29_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::ipFlushMap_f_3_sm_29_t_1[IPFlushRepository::ipFlushMap_f_3_sm_29_t_1_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_29_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::ipFlushMap_f_3_sm_29_t_2[IPFlushRepository::ipFlushMap_f_3_sm_29_t_2_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_29_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::ipFlushMap_f_3_sm_29_t_3[IPFlushRepository::ipFlushMap_f_3_sm_29_t_3_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_29_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::ipFlushMap_f_3_sm_29_t_4[IPFlushRepository::ipFlushMap_f_3_sm_29_t_4_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_29_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::ipFlushMap_f_3_sm_29_t_5[IPFlushRepository::ipFlushMap_f_3_sm_29_t_5_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_29_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::ipFlushMap_f_3_sm_29_t_6[IPFlushRepository::ipFlushMap_f_3_sm_29_t_6_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_29_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::ipFlushMap_f_3_sm_29_t_7[IPFlushRepository::ipFlushMap_f_3_sm_29_t_7_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_29_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::ipFlushMap_f_3_sm_29_t_8[IPFlushRepository::ipFlushMap_f_3_sm_29_t_8_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_29_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::ipFlushMap_f_3_sm_29_t_9[IPFlushRepository::ipFlushMap_f_3_sm_29_t_9_cnt].copy(pIpSession);
						IPFlushRepository::ipFlushMap_f_3_sm_29_t_9_cnt++;
						break;
					}
					break;
	}
}


VOID S1UInterface::IPv4_TimeOutCleanIpSession()
{
	ipSessionCleanUpMap_cnt = 0;

		switch(instanceId)
		{
			case 0:
				processTimedOutSessionsIP(IPStats::ip_session_scanned_sm_0_cnt,IPStats::ip_session_cleaned_tcp_sm_0_cnt,IPStats::ip_session_cleaned_udp_sm_0_cnt);
				break;
			case 1:
				processTimedOutSessionsIP(IPStats::ip_session_scanned_sm_1_cnt,IPStats::ip_session_cleaned_tcp_sm_1_cnt,IPStats::ip_session_cleaned_udp_sm_1_cnt);
				break;
			case 2:
				processTimedOutSessionsIP(IPStats::ip_session_scanned_sm_2_cnt,IPStats::ip_session_cleaned_tcp_sm_2_cnt,IPStats::ip_session_cleaned_udp_sm_2_cnt);
				break;
			case 3:
				processTimedOutSessionsIP(IPStats::ip_session_scanned_sm_3_cnt,IPStats::ip_session_cleaned_tcp_sm_3_cnt,IPStats::ip_session_cleaned_udp_sm_3_cnt);
				break;
			case 4:
				processTimedOutSessionsIP(IPStats::ip_session_scanned_sm_4_cnt,IPStats::ip_session_cleaned_tcp_sm_4_cnt,IPStats::ip_session_cleaned_udp_sm_4_cnt);
				break;
			case 5:
				processTimedOutSessionsIP(IPStats::ip_session_scanned_sm_5_cnt,IPStats::ip_session_cleaned_tcp_sm_5_cnt,IPStats::ip_session_cleaned_udp_sm_5_cnt);
				break;
			case 6:
				processTimedOutSessionsIP(IPStats::ip_session_scanned_sm_6_cnt,IPStats::ip_session_cleaned_tcp_sm_6_cnt,IPStats::ip_session_cleaned_udp_sm_6_cnt);
				break;
			case 7:
				processTimedOutSessionsIP(IPStats::ip_session_scanned_sm_7_cnt,IPStats::ip_session_cleaned_tcp_sm_7_cnt,IPStats::ip_session_cleaned_udp_sm_7_cnt);
				break;
			case 8:
				processTimedOutSessionsIP(IPStats::ip_session_scanned_sm_8_cnt,IPStats::ip_session_cleaned_tcp_sm_8_cnt,IPStats::ip_session_cleaned_udp_sm_8_cnt);
				break;
			case 9:
				processTimedOutSessionsIP(IPStats::ip_session_scanned_sm_9_cnt,IPStats::ip_session_cleaned_tcp_sm_9_cnt,IPStats::ip_session_cleaned_udp_sm_9_cnt);
				break;
			case 10:
				processTimedOutSessionsIP(IPStats::ip_session_scanned_sm_10_cnt,IPStats::ip_session_cleaned_tcp_sm_10_cnt,IPStats::ip_session_cleaned_udp_sm_10_cnt);
				break;
			case 11:
				processTimedOutSessionsIP(IPStats::ip_session_scanned_sm_11_cnt,IPStats::ip_session_cleaned_tcp_sm_11_cnt,IPStats::ip_session_cleaned_udp_sm_11_cnt);
				break;
			case 12:
				processTimedOutSessionsIP(IPStats::ip_session_scanned_sm_12_cnt,IPStats::ip_session_cleaned_tcp_sm_12_cnt,IPStats::ip_session_cleaned_udp_sm_12_cnt);
				break;
			case 13:
				processTimedOutSessionsIP(IPStats::ip_session_scanned_sm_13_cnt,IPStats::ip_session_cleaned_tcp_sm_13_cnt,IPStats::ip_session_cleaned_udp_sm_13_cnt);
				break;
			case 14:
				processTimedOutSessionsIP(IPStats::ip_session_scanned_sm_14_cnt,IPStats::ip_session_cleaned_tcp_sm_14_cnt,IPStats::ip_session_cleaned_udp_sm_14_cnt);
				break;
			case 15:
				processTimedOutSessionsIP(IPStats::ip_session_scanned_sm_15_cnt,IPStats::ip_session_cleaned_tcp_sm_15_cnt,IPStats::ip_session_cleaned_udp_sm_15_cnt);
				break;
			case 16:
				processTimedOutSessionsIP(IPStats::ip_session_scanned_sm_16_cnt,IPStats::ip_session_cleaned_tcp_sm_16_cnt,IPStats::ip_session_cleaned_udp_sm_16_cnt);
				break;
			case 17:
				processTimedOutSessionsIP(IPStats::ip_session_scanned_sm_17_cnt,IPStats::ip_session_cleaned_tcp_sm_17_cnt,IPStats::ip_session_cleaned_udp_sm_17_cnt);
				break;
			case 18:
				processTimedOutSessionsIP(IPStats::ip_session_scanned_sm_18_cnt,IPStats::ip_session_cleaned_tcp_sm_18_cnt,IPStats::ip_session_cleaned_udp_sm_18_cnt);
				break;
			case 19:
				processTimedOutSessionsIP(IPStats::ip_session_scanned_sm_19_cnt,IPStats::ip_session_cleaned_tcp_sm_19_cnt,IPStats::ip_session_cleaned_udp_sm_19_cnt);
				break;
			case 20:
				processTimedOutSessionsIP(IPStats::ip_session_scanned_sm_20_cnt,IPStats::ip_session_cleaned_tcp_sm_20_cnt,IPStats::ip_session_cleaned_udp_sm_20_cnt);
				break;
			case 21:
				processTimedOutSessionsIP(IPStats::ip_session_scanned_sm_21_cnt,IPStats::ip_session_cleaned_tcp_sm_21_cnt,IPStats::ip_session_cleaned_udp_sm_21_cnt);
				break;
			case 22:
				processTimedOutSessionsIP(IPStats::ip_session_scanned_sm_22_cnt,IPStats::ip_session_cleaned_tcp_sm_22_cnt,IPStats::ip_session_cleaned_udp_sm_22_cnt);
				break;
			case 23:
				processTimedOutSessionsIP(IPStats::ip_session_scanned_sm_23_cnt,IPStats::ip_session_cleaned_tcp_sm_23_cnt,IPStats::ip_session_cleaned_udp_sm_23_cnt);
				break;
			case 24:
				processTimedOutSessionsIP(IPStats::ip_session_scanned_sm_24_cnt,IPStats::ip_session_cleaned_tcp_sm_24_cnt,IPStats::ip_session_cleaned_udp_sm_24_cnt);
				break;
			case 25:
				processTimedOutSessionsIP(IPStats::ip_session_scanned_sm_25_cnt,IPStats::ip_session_cleaned_tcp_sm_25_cnt,IPStats::ip_session_cleaned_udp_sm_25_cnt);
				break;
			case 26:
				processTimedOutSessionsIP(IPStats::ip_session_scanned_sm_26_cnt,IPStats::ip_session_cleaned_tcp_sm_26_cnt,IPStats::ip_session_cleaned_udp_sm_26_cnt);
				break;
			case 27:
				processTimedOutSessionsIP(IPStats::ip_session_scanned_sm_27_cnt,IPStats::ip_session_cleaned_tcp_sm_27_cnt,IPStats::ip_session_cleaned_udp_sm_27_cnt);
				break;
			case 28:
				processTimedOutSessionsIP(IPStats::ip_session_scanned_sm_28_cnt,IPStats::ip_session_cleaned_tcp_sm_28_cnt,IPStats::ip_session_cleaned_udp_sm_28_cnt);
				break;
			case 29:
				processTimedOutSessionsIP(IPStats::ip_session_scanned_sm_29_cnt,IPStats::ip_session_cleaned_tcp_sm_29_cnt,IPStats::ip_session_cleaned_udp_sm_29_cnt);
				break;
		}
}

VOID S1UInterface::processTimedOutSessionsIP(int &ip_session_scanned_sm_cnt, int &ip_session_cleaned_tcp_sm_cnt, int &ip_session_cleaned_udp_sm_cnt)
{
		ip_session_scanned_sm_cnt 		= 0;
		ip_session_cleaned_tcp_sm_cnt 	= 0;
		ip_session_cleaned_udp_sm_cnt 	= 0;

		for(int i = 0; i < IP_SESSION_POOL_ARRAY_ELEMENTS; i++)
			ip_session_scanned_sm_cnt += ipSessionMap[i].size();

		for(int i = 0; i < IP_SESSION_POOL_ARRAY_ELEMENTS; i++)
		{
			if(ipSessionCleanUpMap_cnt >= IPGlobal::S1U_SESSION_CLEAN_UP_BATCH_LIMIT) break;		//Apply only for timeout
			for(auto elem = ipSessionMap[i].begin(), next_elem = elem; elem != ipSessionMap[i].end(); elem = next_elem) {
				++next_elem;
				if(ipSessionCleanUpMap_cnt >= IPGlobal::S1U_SESSION_CLEAN_UP_BATCH_LIMIT) break;	//Apply only for timeout
					flushCleanTimedOutSessionsIP(getIPSessionFromPool(elem->second));
			}
		}

		ipSessionCleanUpMap_cnt = 0;
}

VOID S1UInterface::flushCleanTimedOutSessionsIP(ipSession *pIpSession)
{
	uint64_t curEpochSec = IPGlobal::CURRENT_EPOCH_SEC;

	if((curEpochSec - pIpSession->pckLastTimeEpochSec) > IPGlobal::S1U_SESSION_CLEAN_UP_TIMEOUT_SEC)
	{
		if(pIpSession->protocolType == PACKET_IPPROTO_TCP)
			pIpSession->causeCode = SYSTEM_CLEANUP_TCP_DATA;
		else if (pIpSession->protocolType == PACKET_IPPROTO_UDP)
			pIpSession->causeCode = SYSTEM_CLEANUP_UDP_DATA;

		switch(instanceId)
		{
			case 0:
			{
				if(pIpSession->protocolType == PACKET_IPPROTO_TCP)
					IPStats::ip_session_cleaned_tcp_sm_0_cnt++;
				else if(pIpSession->protocolType == PACKET_IPPROTO_UDP)
					IPStats::ip_session_cleaned_udp_sm_0_cnt++;
				break;
			}
			case 1:
			{
				if(pIpSession->protocolType == PACKET_IPPROTO_TCP)
					IPStats::ip_session_cleaned_tcp_sm_1_cnt++;
				else if(pIpSession->protocolType == PACKET_IPPROTO_UDP)
					IPStats::ip_session_cleaned_udp_sm_1_cnt++;
				break;
			}
			case 2:
			{
				if(pIpSession->protocolType == PACKET_IPPROTO_TCP)
					IPStats::ip_session_cleaned_tcp_sm_2_cnt++;
				else if(pIpSession->protocolType == PACKET_IPPROTO_UDP)
					IPStats::ip_session_cleaned_udp_sm_2_cnt++;
				break;
			}
			case 3:
			{
				if(pIpSession->protocolType == PACKET_IPPROTO_TCP)
					IPStats::ip_session_cleaned_tcp_sm_3_cnt++;
				else if(pIpSession->protocolType == PACKET_IPPROTO_UDP)
					IPStats::ip_session_cleaned_udp_sm_3_cnt++;
				break;
			}
			case 4:
			{
				if(pIpSession->protocolType == PACKET_IPPROTO_TCP)
					IPStats::ip_session_cleaned_tcp_sm_4_cnt++;
				else if(pIpSession->protocolType == PACKET_IPPROTO_UDP)
					IPStats::ip_session_cleaned_udp_sm_4_cnt++;
				break;
			}
			case 5:
			{
				if(pIpSession->protocolType == PACKET_IPPROTO_TCP)
					IPStats::ip_session_cleaned_tcp_sm_5_cnt++;
				else if(pIpSession->protocolType == PACKET_IPPROTO_UDP)
					IPStats::ip_session_cleaned_udp_sm_5_cnt++;
				break;
			}
			case 6:
			{
				if(pIpSession->protocolType == PACKET_IPPROTO_TCP)
					IPStats::ip_session_cleaned_tcp_sm_6_cnt++;
				else if(pIpSession->protocolType == PACKET_IPPROTO_UDP)
					IPStats::ip_session_cleaned_udp_sm_6_cnt++;
				break;
			}
			case 7:
			{
				if(pIpSession->protocolType == PACKET_IPPROTO_TCP)
					IPStats::ip_session_cleaned_tcp_sm_7_cnt++;
				else if(pIpSession->protocolType == PACKET_IPPROTO_UDP)
					IPStats::ip_session_cleaned_udp_sm_7_cnt++;
				break;
			}
			case 8:
			{
				if(pIpSession->protocolType == PACKET_IPPROTO_TCP)
					IPStats::ip_session_cleaned_tcp_sm_8_cnt++;
				else if(pIpSession->protocolType == PACKET_IPPROTO_UDP)
					IPStats::ip_session_cleaned_udp_sm_8_cnt++;
				break;
			}
			case 9:
			{
				if(pIpSession->protocolType == PACKET_IPPROTO_TCP)
					IPStats::ip_session_cleaned_tcp_sm_9_cnt++;
				else if(pIpSession->protocolType == PACKET_IPPROTO_UDP)
					IPStats::ip_session_cleaned_udp_sm_9_cnt++;
				break;
			}
			case 10:
			{
				if(pIpSession->protocolType == PACKET_IPPROTO_TCP)
					IPStats::ip_session_cleaned_tcp_sm_10_cnt++;
				else if(pIpSession->protocolType == PACKET_IPPROTO_UDP)
					IPStats::ip_session_cleaned_udp_sm_10_cnt++;
				break;
			}
			case 11:
			{
				if(pIpSession->protocolType == PACKET_IPPROTO_TCP)
					IPStats::ip_session_cleaned_tcp_sm_11_cnt++;
				else if(pIpSession->protocolType == PACKET_IPPROTO_UDP)
					IPStats::ip_session_cleaned_udp_sm_11_cnt++;
				break;
			}
			case 12:
			{
				if(pIpSession->protocolType == PACKET_IPPROTO_TCP)
					IPStats::ip_session_cleaned_tcp_sm_12_cnt++;
				else if(pIpSession->protocolType == PACKET_IPPROTO_UDP)
					IPStats::ip_session_cleaned_udp_sm_12_cnt++;
				break;
			}
			case 13:
			{
				if(pIpSession->protocolType == PACKET_IPPROTO_TCP)
					IPStats::ip_session_cleaned_tcp_sm_13_cnt++;
				else if(pIpSession->protocolType == PACKET_IPPROTO_UDP)
					IPStats::ip_session_cleaned_udp_sm_13_cnt++;
				break;
			}
			case 14:
			{
				if(pIpSession->protocolType == PACKET_IPPROTO_TCP)
					IPStats::ip_session_cleaned_tcp_sm_14_cnt++;
				else if(pIpSession->protocolType == PACKET_IPPROTO_UDP)
					IPStats::ip_session_cleaned_udp_sm_14_cnt++;
				break;
			}
			case 15:
			{
				if(pIpSession->protocolType == PACKET_IPPROTO_TCP)
					IPStats::ip_session_cleaned_tcp_sm_15_cnt++;
				else if(pIpSession->protocolType == PACKET_IPPROTO_UDP)
					IPStats::ip_session_cleaned_udp_sm_15_cnt++;
				break;
			}
			case 16:
			{
				if(pIpSession->protocolType == PACKET_IPPROTO_TCP)
					IPStats::ip_session_cleaned_tcp_sm_16_cnt++;
				else if(pIpSession->protocolType == PACKET_IPPROTO_UDP)
					IPStats::ip_session_cleaned_udp_sm_16_cnt++;
				break;
			}
			case 17:
			{
				if(pIpSession->protocolType == PACKET_IPPROTO_TCP)
					IPStats::ip_session_cleaned_tcp_sm_17_cnt++;
				else if(pIpSession->protocolType == PACKET_IPPROTO_UDP)
					IPStats::ip_session_cleaned_udp_sm_17_cnt++;
				break;
			}
			case 18:
			{
				if(pIpSession->protocolType == PACKET_IPPROTO_TCP)
					IPStats::ip_session_cleaned_tcp_sm_18_cnt++;
				else if(pIpSession->protocolType == PACKET_IPPROTO_UDP)
					IPStats::ip_session_cleaned_udp_sm_18_cnt++;
				break;
			}
			case 19:
			{
				if(pIpSession->protocolType == PACKET_IPPROTO_TCP)
					IPStats::ip_session_cleaned_tcp_sm_19_cnt++;
				else if(pIpSession->protocolType == PACKET_IPPROTO_UDP)
					IPStats::ip_session_cleaned_udp_sm_19_cnt++;
				break;
			}
			case 20:
			{
				if(pIpSession->protocolType == PACKET_IPPROTO_TCP)
					IPStats::ip_session_cleaned_tcp_sm_20_cnt++;
				else if(pIpSession->protocolType == PACKET_IPPROTO_UDP)
					IPStats::ip_session_cleaned_udp_sm_20_cnt++;
				break;
			}
			case 21:
			{
				if(pIpSession->protocolType == PACKET_IPPROTO_TCP)
					IPStats::ip_session_cleaned_tcp_sm_21_cnt++;
				else if(pIpSession->protocolType == PACKET_IPPROTO_UDP)
					IPStats::ip_session_cleaned_udp_sm_21_cnt++;
				break;
			}
			case 22:
			{
				if(pIpSession->protocolType == PACKET_IPPROTO_TCP)
					IPStats::ip_session_cleaned_tcp_sm_22_cnt++;
				else if(pIpSession->protocolType == PACKET_IPPROTO_UDP)
					IPStats::ip_session_cleaned_udp_sm_22_cnt++;
				break;
			}
			case 23:
			{
				if(pIpSession->protocolType == PACKET_IPPROTO_TCP)
					IPStats::ip_session_cleaned_tcp_sm_23_cnt++;
				else if(pIpSession->protocolType == PACKET_IPPROTO_UDP)
					IPStats::ip_session_cleaned_udp_sm_23_cnt++;
				break;
			}
			case 24:
			{
				if(pIpSession->protocolType == PACKET_IPPROTO_TCP)
					IPStats::ip_session_cleaned_tcp_sm_24_cnt++;
				else if(pIpSession->protocolType == PACKET_IPPROTO_UDP)
					IPStats::ip_session_cleaned_udp_sm_24_cnt++;
				break;
			}
			case 25:
			{
				if(pIpSession->protocolType == PACKET_IPPROTO_TCP)
					IPStats::ip_session_cleaned_tcp_sm_25_cnt++;
				else if(pIpSession->protocolType == PACKET_IPPROTO_UDP)
					IPStats::ip_session_cleaned_udp_sm_25_cnt++;
				break;
			}
			case 26:
			{
				if(pIpSession->protocolType == PACKET_IPPROTO_TCP)
					IPStats::ip_session_cleaned_tcp_sm_26_cnt++;
				else if(pIpSession->protocolType == PACKET_IPPROTO_UDP)
					IPStats::ip_session_cleaned_udp_sm_26_cnt++;
				break;
			}
			case 27:
			{
				if(pIpSession->protocolType == PACKET_IPPROTO_TCP)
					IPStats::ip_session_cleaned_tcp_sm_27_cnt++;
				else if(pIpSession->protocolType == PACKET_IPPROTO_UDP)
					IPStats::ip_session_cleaned_udp_sm_27_cnt++;
				break;
			}
			case 28:
			{
				if(pIpSession->protocolType == PACKET_IPPROTO_TCP)
					IPStats::ip_session_cleaned_tcp_sm_28_cnt++;
				else if(pIpSession->protocolType == PACKET_IPPROTO_UDP)
					IPStats::ip_session_cleaned_udp_sm_28_cnt++;
				break;
			}
			case 29:
			{
				if(pIpSession->protocolType == PACKET_IPPROTO_TCP)
					IPStats::ip_session_cleaned_tcp_sm_29_cnt++;
				else if(pIpSession->protocolType == PACKET_IPPROTO_UDP)
					IPStats::ip_session_cleaned_udp_sm_29_cnt++;
				break;
			}
		}
		ipSessionCleanUpMap_cnt++;

		flushIpSession(7, pIpSession, true);
	}
}

VOID S1UInterface::eraseCleanedSessions()
{
	uint64_t key;
	int index = 0;
	int poolIndex = -1;

	for(int i = 0; i < ipSessionCleanUpMap_cnt; i++) {
		 key = ipSessionCleanUpMap[i].key;
		 index = ipSessionCleanUpMap[i].mapIndex;
		 poolIndex = ipSessionCleanUpMap[i].poolIndex;
		 ipSessionMap[index].erase(key);
		 releaseIndexIP(poolIndex);
	}

	for(int i = 0; i < ipSessionCleanUpMap_cnt; i++)
		ipSessionCleanUpMap.erase(i);

	ipSessionCleanUpMap.clear();
	ipSessionCleanUpMap_cnt = 0;
}

VOID S1UInterface::eraseIpSession(ipSession *pIpSession)
{
	uint64_t sKey = pIpSession->sessionKey;
	int index = pIpSession->mapIndex;
	int poolIndex = pIpSession->poolIndex;
//	eraseVpsMap(pIpSession);
	releaseIndexIP(poolIndex);
	ipSessionMap[index].erase(sKey);
}

//VOID S1UInterface::IPv4_IpSessionCount()
//{
//	int i = 0;
//	int poolCount = 0;
//
//	switch(instanceId)
//	{
//		case 0:
//			IPStats::ip_session_total_sm_0_cnt = 0;
//			for(i = 0; i < IP_SESSION_POOL_ARRAY_ELEMENTS; i++)
//				IPStats::ip_session_total_sm_0_cnt += ipSessionMap[i].size();
//			break;
//		case 1:
//			IPStats::ip_session_total_sm_1_cnt = 0;
//			for(i = 0; i < IP_SESSION_POOL_ARRAY_ELEMENTS; i++)
//				IPStats::ip_session_total_sm_1_cnt += ipSessionMap[i].size();
//			break;
//		case 2:
//			IPStats::ip_session_total_sm_2_cnt = 0;
//			for(i = 0; i < IP_SESSION_POOL_ARRAY_ELEMENTS; i++)
//				IPStats::ip_session_total_sm_2_cnt += ipSessionMap[i].size();
//			break;
//		case 3:
//			IPStats::ip_session_total_sm_3_cnt = 0;
//			for(i = 0; i < IP_SESSION_POOL_ARRAY_ELEMENTS; i++)
//				IPStats::ip_session_total_sm_3_cnt += ipSessionMap[i].size();
//			break;
//		case 4:
//			IPStats::ip_session_total_sm_4_cnt = 0;
//			for(i = 0; i < IP_SESSION_POOL_ARRAY_ELEMENTS; i++)
//				IPStats::ip_session_total_sm_4_cnt += ipSessionMap[i].size();
//			break;
//		case 5:
//			IPStats::ip_session_total_sm_5_cnt = 0;
//			for(i = 0; i < IP_SESSION_POOL_ARRAY_ELEMENTS; i++)
//				IPStats::ip_session_total_sm_5_cnt += ipSessionMap[i].size();
//			break;
//		case 6:
//			IPStats::ip_session_total_sm_6_cnt = 0;
//			for(i = 0; i < IP_SESSION_POOL_ARRAY_ELEMENTS; i++)
//				IPStats::ip_session_total_sm_6_cnt += ipSessionMap[i].size();
//			break;
//		case 7:
//			IPStats::ip_session_total_sm_7_cnt = 0;
//			for(i = 0; i < IP_SESSION_POOL_ARRAY_ELEMENTS; i++)
//				IPStats::ip_session_total_sm_7_cnt += ipSessionMap[i].size();
//			break;
//		case 8:
//			IPStats::ip_session_total_sm_8_cnt = 0;
//			for(i = 0; i < IP_SESSION_POOL_ARRAY_ELEMENTS; i++)
//				IPStats::ip_session_total_sm_8_cnt += ipSessionMap[i].size();
//			break;
//		case 9:
//			IPStats::ip_session_total_sm_9_cnt = 0;
//			for(i = 0; i < IP_SESSION_POOL_ARRAY_ELEMENTS; i++)
//				IPStats::ip_session_total_sm_9_cnt += ipSessionMap[i].size();
//			break;
//		case 10:
//			IPStats::ip_session_total_sm_10_cnt = 0;
//			for(i = 0; i < IP_SESSION_POOL_ARRAY_ELEMENTS; i++)
//				IPStats::ip_session_total_sm_10_cnt += ipSessionMap[i].size();
//			break;
//		case 11:
//			IPStats::ip_session_total_sm_11_cnt = 0;
//			for(i = 0; i < IP_SESSION_POOL_ARRAY_ELEMENTS; i++)
//				IPStats::ip_session_total_sm_11_cnt += ipSessionMap[i].size();
//			break;
//		case 12:
//			IPStats::ip_session_total_sm_12_cnt = 0;
//			for(i = 0; i < IP_SESSION_POOL_ARRAY_ELEMENTS; i++)
//				IPStats::ip_session_total_sm_12_cnt += ipSessionMap[i].size();
//			break;
//		case 13:
//			IPStats::ip_session_total_sm_13_cnt = 0;
//			for(i = 0; i < IP_SESSION_POOL_ARRAY_ELEMENTS; i++)
//				IPStats::ip_session_total_sm_13_cnt += ipSessionMap[i].size();
//			break;
//		case 14:
//			IPStats::ip_session_total_sm_14_cnt = 0;
//			for(i = 0; i < IP_SESSION_POOL_ARRAY_ELEMENTS; i++)
//				IPStats::ip_session_total_sm_14_cnt += ipSessionMap[i].size();
//			break;
//		case 15:
//			IPStats::ip_session_total_sm_15_cnt = 0;
//			for(i = 0; i < IP_SESSION_POOL_ARRAY_ELEMENTS; i++)
//				IPStats::ip_session_total_sm_15_cnt += ipSessionMap[i].size();
//			break;
//		case 16:
//			IPStats::ip_session_total_sm_16_cnt = 0;
//			for(i = 0; i < IP_SESSION_POOL_ARRAY_ELEMENTS; i++)
//				IPStats::ip_session_total_sm_16_cnt += ipSessionMap[i].size();
//			break;
//		case 17:
//			IPStats::ip_session_total_sm_17_cnt = 0;
//			for(i = 0; i < IP_SESSION_POOL_ARRAY_ELEMENTS; i++)
//				IPStats::ip_session_total_sm_17_cnt += ipSessionMap[i].size();
//			break;
//		case 18:
//			IPStats::ip_session_total_sm_18_cnt = 0;
//			for(i = 0; i < IP_SESSION_POOL_ARRAY_ELEMENTS; i++)
//				IPStats::ip_session_total_sm_18_cnt += ipSessionMap[i].size();
//			break;
//		case 19:
//			IPStats::ip_session_total_sm_19_cnt = 0;
//			for(i = 0; i < IP_SESSION_POOL_ARRAY_ELEMENTS; i++)
//				IPStats::ip_session_total_sm_19_cnt += ipSessionMap[i].size();
//			break;
//		case 20:
//			IPStats::ip_session_total_sm_20_cnt = 0;
//			for(i = 0; i < IP_SESSION_POOL_ARRAY_ELEMENTS; i++)
//				IPStats::ip_session_total_sm_20_cnt += ipSessionMap[i].size();
//			break;
//		case 21:
//			IPStats::ip_session_total_sm_21_cnt = 0;
//			for(i = 0; i < IP_SESSION_POOL_ARRAY_ELEMENTS; i++)
//				IPStats::ip_session_total_sm_21_cnt += ipSessionMap[i].size();
//			break;
//		case 22:
//			IPStats::ip_session_total_sm_22_cnt = 0;
//			for(i = 0; i < IP_SESSION_POOL_ARRAY_ELEMENTS; i++)
//				IPStats::ip_session_total_sm_22_cnt += ipSessionMap[i].size();
//			break;
//		case 23:
//			IPStats::ip_session_total_sm_23_cnt = 0;
//			for(i = 0; i < IP_SESSION_POOL_ARRAY_ELEMENTS; i++)
//				IPStats::ip_session_total_sm_23_cnt += ipSessionMap[i].size();
//			break;
//		case 24:
//			IPStats::ip_session_total_sm_24_cnt = 0;
//			for(i = 0; i < IP_SESSION_POOL_ARRAY_ELEMENTS; i++)
//				IPStats::ip_session_total_sm_24_cnt += ipSessionMap[i].size();
//			break;
//		case 25:
//			IPStats::ip_session_total_sm_25_cnt = 0;
//			for(i = 0; i < IP_SESSION_POOL_ARRAY_ELEMENTS; i++)
//				IPStats::ip_session_total_sm_25_cnt += ipSessionMap[i].size();
//			break;
//		case 26:
//			IPStats::ip_session_total_sm_26_cnt = 0;
//			for(i = 0; i < IP_SESSION_POOL_ARRAY_ELEMENTS; i++)
//				IPStats::ip_session_total_sm_26_cnt += ipSessionMap[i].size();
//			break;
//		case 27:
//			IPStats::ip_session_total_sm_27_cnt = 0;
//			for(i = 0; i < IP_SESSION_POOL_ARRAY_ELEMENTS; i++)
//				IPStats::ip_session_total_sm_27_cnt += ipSessionMap[i].size();
//			break;
//		case 28:
//			IPStats::ip_session_total_sm_28_cnt = 0;
//			for(i = 0; i < IP_SESSION_POOL_ARRAY_ELEMENTS; i++)
//				IPStats::ip_session_total_sm_28_cnt += ipSessionMap[i].size();
//			break;
//		case 29:
//			IPStats::ip_session_total_sm_29_cnt = 0;
//			for(i = 0; i < IP_SESSION_POOL_ARRAY_ELEMENTS; i++)
//				IPStats::ip_session_total_sm_29_cnt += ipSessionMap[i].size();
//			break;
//	}
//}
//
//VOID S1UInterface::IPv4_DnsSessionCount()
//{
//	int i = 0;
//	int poolCount = 0;
//
//	switch(instanceId)
//	{
//		case 0:
//			IPStats::dns_session_total_sm_0_cnt = 0;
//			IPStats::dns_session_total_sm_0_cnt = dnsSessionMap.size();
//			break;
//		case 1:
//			IPStats::dns_session_total_sm_1_cnt = 0;
//			IPStats::dns_session_total_sm_1_cnt = dnsSessionMap.size();
//			break;
//		case 2:
//			IPStats::dns_session_total_sm_2_cnt = 0;
//			IPStats::dns_session_total_sm_2_cnt = dnsSessionMap.size();
//			break;
//		case 3:
//			IPStats::dns_session_total_sm_3_cnt = 0;
//			IPStats::dns_session_total_sm_3_cnt = dnsSessionMap.size();
//			break;
//		case 4:
//			IPStats::dns_session_total_sm_4_cnt = 0;
//			IPStats::dns_session_total_sm_4_cnt = dnsSessionMap.size();
//			break;
//		case 5:
//			IPStats::dns_session_total_sm_5_cnt = 0;
//			IPStats::dns_session_total_sm_5_cnt = dnsSessionMap.size();
//			break;
//		case 6:
//			IPStats::dns_session_total_sm_6_cnt = 0;
//			IPStats::dns_session_total_sm_6_cnt = dnsSessionMap.size();
//			break;
//		case 7:
//			IPStats::dns_session_total_sm_7_cnt = 0;
//			IPStats::dns_session_total_sm_7_cnt = dnsSessionMap.size();
//			break;
//		case 8:
//			IPStats::dns_session_total_sm_8_cnt = 0;
//			IPStats::dns_session_total_sm_8_cnt = dnsSessionMap.size();
//			break;
//		case 9:
//			IPStats::dns_session_total_sm_9_cnt = 0;
//			IPStats::dns_session_total_sm_9_cnt = dnsSessionMap.size();
//			break;
//		case 10:
//			IPStats::dns_session_total_sm_10_cnt = 0;
//			IPStats::dns_session_total_sm_10_cnt = dnsSessionMap.size();
//			break;
//		case 11:
//			IPStats::dns_session_total_sm_11_cnt = 0;
//			IPStats::dns_session_total_sm_11_cnt = dnsSessionMap.size();
//			break;
//		case 12:
//			IPStats::dns_session_total_sm_12_cnt = 0;
//			IPStats::dns_session_total_sm_12_cnt = dnsSessionMap.size();
//			break;
//		case 13:
//			IPStats::dns_session_total_sm_13_cnt = 0;
//			IPStats::dns_session_total_sm_13_cnt = dnsSessionMap.size();
//			break;
//		case 14:
//			IPStats::dns_session_total_sm_14_cnt = 0;
//			IPStats::dns_session_total_sm_14_cnt = dnsSessionMap.size();
//			break;
//		case 15:
//			IPStats::dns_session_total_sm_15_cnt = 0;
//			IPStats::dns_session_total_sm_15_cnt = dnsSessionMap.size();
//			break;
//		case 16:
//			IPStats::dns_session_total_sm_16_cnt = 0;
//			IPStats::dns_session_total_sm_16_cnt = dnsSessionMap.size();
//			break;
//		case 17:
//			IPStats::dns_session_total_sm_17_cnt = 0;
//			IPStats::dns_session_total_sm_17_cnt = dnsSessionMap.size();
//			break;
//		case 18:
//			IPStats::dns_session_total_sm_18_cnt = 0;
//			IPStats::dns_session_total_sm_18_cnt = dnsSessionMap.size();
//			break;
//		case 19:
//			IPStats::dns_session_total_sm_19_cnt = 0;
//			IPStats::dns_session_total_sm_19_cnt = dnsSessionMap.size();
//			break;
//		case 20:
//			IPStats::dns_session_total_sm_20_cnt = 0;
//			IPStats::dns_session_total_sm_20_cnt = dnsSessionMap.size();
//			break;
//		case 21:
//			IPStats::dns_session_total_sm_21_cnt = 0;
//			IPStats::dns_session_total_sm_21_cnt = dnsSessionMap.size();
//			break;
//		case 22:
//			IPStats::dns_session_total_sm_22_cnt = 0;
//			IPStats::dns_session_total_sm_22_cnt = dnsSessionMap.size();
//			break;
//		case 23:
//			IPStats::dns_session_total_sm_23_cnt = 0;
//			IPStats::dns_session_total_sm_23_cnt = dnsSessionMap.size();
//			break;
//		case 24:
//			IPStats::dns_session_total_sm_24_cnt = 0;
//			IPStats::dns_session_total_sm_24_cnt = dnsSessionMap.size();
//			break;
//		case 25:
//			IPStats::dns_session_total_sm_25_cnt = 0;
//			IPStats::dns_session_total_sm_25_cnt = dnsSessionMap.size();
//			break;
//		case 26:
//			IPStats::dns_session_total_sm_26_cnt = 0;
//			IPStats::dns_session_total_sm_26_cnt = dnsSessionMap.size();
//			break;
//		case 27:
//			IPStats::dns_session_total_sm_27_cnt = 0;
//			IPStats::dns_session_total_sm_27_cnt = dnsSessionMap.size();
//			break;
//		case 28:
//			IPStats::dns_session_total_sm_28_cnt = 0;
//			IPStats::dns_session_total_sm_28_cnt = dnsSessionMap.size();
//			break;
//		case 29:
//			IPStats::dns_session_total_sm_29_cnt = 0;
//			IPStats::dns_session_total_sm_29_cnt = dnsSessionMap.size();
//			break;
//	}
//}

/*
 *  DNS Function Session
 */

VOID S1UInterface::IP_DnsProcessPacket(MPacket *msgObj)
{
	dnsSession *pDnsSession;
	uint64_t key;

	/*
	 * DNS Session Key = Subs Ip + Subs Port + DNS Server Ip + Transaction Id
	 */
	switch(msgObj->dnsQRFlag)
	{
		case QUERY:
			{
				switch(msgObj->ipVer)
				{
					case IPVersion4:
						getIpv4DNSSessionKey(key, msgObj->sourceIpAddrLong, msgObj->protoSourcePort, msgObj->destIpAddrLong, msgObj->dnsTransactionId);
						break;

//					case IPVersion6:
//						getIpv6DNSSessionKey(key, msgObj->sourceIpAddrChar, msgObj->dnsTransactionId, msgObj->protoSourcePort);
//						break;
					default:
						return;
						break;
				}


				std::map<uint64_t, int>::iterator it = dnsSessionMap.find(key);
				if(it != dnsSessionMap.end()) {

					pDnsSession = getDnsSessionFromPool(it->second);

					if(pDnsSession->state == RESPONSE)	{ //Response has arrieved before Req
						requestUpdateDnsSession(pDnsSession, msgObj);
						pDnsSession->state = SUCCESS;
						flushDnsSession(pDnsSession, DNS_FLUSH_RSP_REQ);
						releaseIndexDns(pDnsSession->poolIndex);
						dnsSessionMap.erase(key);
						return;
					}
					else {	//Duplicate DNS Request seems
						int poolIndex = pDnsSession->poolIndex;
						pDnsSession->reset();
						pDnsSession->poolIndex = poolIndex;
						pDnsSession->dnsSessionKey = key;
						requestUpdateDnsSession(pDnsSession, msgObj);
					}
				}
				else
				{
					if(dnsSessionMap.size() < freeBitPosDnsMax)
					{
						int poolIndex = getFreeIndexDns();
						pDnsSession = getDnsSessionFromPool(poolIndex);
						pDnsSession->reset();
						pDnsSession->poolIndex = poolIndex;
						requestUpdateDnsSession(pDnsSession, msgObj);
						pDnsSession->dnsSessionKey = key;
						dnsSessionMap[pDnsSession->dnsSessionKey] = poolIndex;
					}
				}
			}
			break;

		case RESPONSE:
			{
				switch(msgObj->ipVer)
				{
					case IPVersion4:
//								getIpv4DNSSessionKey(key, msgObj->destIpAddrLong, msgObj->dnsTransactionId, msgObj->protoDestPort);
								getIpv4DNSSessionKey(key, msgObj->destIpAddrLong, msgObj->protoDestPort, msgObj->sourceIpAddrLong, msgObj->dnsTransactionId);

								break;

//					case IPVersion6:
//								getIpv6DNSSessionKey(key, msgObj->destIpAddrChar, msgObj->dnsTransactionId, msgObj->protoDestPort);
//								break;
					default:
								return;
								break;
				}

				std::map<uint64_t, int>::iterator it = dnsSessionMap.find(key);

				if(it != dnsSessionMap.end())
				{
					pDnsSession = getDnsSessionFromPool(it->second);

					if(pDnsSession->state == QUERY) {
						responseUpdateDnsSession(pDnsSession, msgObj);
						pDnsSession->state = SUCCESS;
						flushDnsSession(pDnsSession, DNS_FLUSH_REQ_RSP);
						releaseIndexDns(pDnsSession->poolIndex);
						dnsSessionMap.erase(key);
					}
					else {	//Duplicate DNS Response seems
						int poolIndex = pDnsSession->poolIndex;
						pDnsSession->reset();
						pDnsSession->poolIndex = poolIndex;
						pDnsSession->dnsSessionKey = key;
						responseUpdateDnsSession(pDnsSession, msgObj);
					}
				}
				else
				{
					if(dnsSessionMap.size() < freeBitPosDnsMax)
					{
						int poolIndex = getFreeIndexDns();
						pDnsSession = getDnsSessionFromPool(poolIndex);
						pDnsSession->reset();
						pDnsSession->poolIndex = poolIndex;
						responseUpdateDnsSession(pDnsSession, msgObj);
						pDnsSession->dnsSessionKey = key;
						dnsSessionMap[pDnsSession->dnsSessionKey] = poolIndex;
					}
				}
			}
			break;

		default:
			break;
	}

	IPGlobal::ACTIVE_S1U_DNS_SESSIONS[instanceId] = dnsSessionMap.size();
}

VOID S1UInterface::requestUpdateDnsSession(dnsSession *pDnsSession, MPacket *msgObj)
{
	pDnsSession->ipVer					= msgObj->ipVer;
	pDnsSession->transactionId 			= msgObj->dnsTransactionId;
	pDnsSession->queryStartEpochSec 	= IPGlobal::CURRENT_EPOCH_SEC;
	pDnsSession->queryStartEpochNanoSec = IPGlobal::CURRENT_EPOCH_NANO_SEC;
	pDnsSession->queryEndEpochSec 		= IPGlobal::CURRENT_EPOCH_SEC;
	pDnsSession->queryEndEpochNanoSec 	= IPGlobal::CURRENT_EPOCH_NANO_SEC;

//	pDnsSession->queryStartEpochSec 	= msgObj->frTimeEpochSec;
//	pDnsSession->queryStartEpochNanoSec = msgObj->frTimeEpochNanoSec;
//	pDnsSession->queryEndEpochSec 		= msgObj->frTimeEpochSec;
//	pDnsSession->queryEndEpochNanoSec 	= msgObj->frTimeEpochNanoSec;

	switch(msgObj->ipVer)
	{
		case IPVersion4:
				pDnsSession->sourceIpAddrLong 	= msgObj->sourceIpAddrLong;
				pDnsSession->destIpAddrLong 	= msgObj->destIpAddrLong;
				break;

//		case IPVersion6:
//				strcpy(pDnsSession->sourceIpAddrChar, msgObj->sourceIpAddrChar);
//				strcpy(pDnsSession->destIpAddrChar, msgObj->destIpAddrChar);
//				break;
	}

	pDnsSession->sourcePort 			= msgObj->protoSourcePort;
	pDnsSession->destPort 				= msgObj->protoDestPort;
	pDnsSession->state 					= QUERY;

	strcpy(pDnsSession->sourceMacAddr, msgObj->ethSourceMACAddr);
	strcpy(pDnsSession->URL, msgObj->dnsName);
}

VOID S1UInterface::responseUpdateDnsSession(dnsSession *pDnsSession, MPacket *msgObj)
{
	pDnsSession->transactionId 			= msgObj->dnsTransactionId;
	pDnsSession->queryEndEpochSec 		= IPGlobal::CURRENT_EPOCH_SEC;
	pDnsSession->queryEndEpochNanoSec 	= IPGlobal::CURRENT_EPOCH_NANO_SEC;

	if(msgObj->dnsResponseCode <= 26)
		pDnsSession->errorCode 				= msgObj->dnsResponseCode;
	else
		pDnsSession->errorCode 				= 24;

	pDnsSession->state 					= RESPONSE;

	if(strlen(pDnsSession->URL) == 0 && strlen(msgObj->dnsName) != 0)
		strcpy(pDnsSession->URL, msgObj->dnsName);

	strcpy(pDnsSession->address, msgObj->dnsIpAddress);

	if(msgObj->dnsResponseCode <= 26)
		strcpy(pDnsSession->errorDesc, (const char *)errorCode::dnsErrorCode[msgObj->dnsResponseCode]);
}

VOID S1UInterface::getIpv4DNSSessionKey(uint64_t &key, uint32_t userAddrLong, uint16_t port, uint32_t destAddrLong, uint32_t dnsTransactionId)
{
	key = (userAddrLong^4) +
		  (port^3) +
		  (destAddrLong^2) +
		  (dnsTransactionId^1);
}

//VOID IPSMInterface::getIpv6DNSSessionKey(uint64_t &key, char* userAddrLong, uint32_t dnsTransactionId, uint16_t port)
//{
////	key[0] = 0;
////	sprintf(key,"%s-%u-%d", userAddrLong, dnsTransactionId, port);
//	key = userAddrLong + std::to_string(dnsTransactionId) + std::to_string(port);
//}

VOID S1UInterface::flushDnsSession(dnsSession *pDnsSession, int type)
{
	long epochSecNow = IPGlobal::CURRENT_EPOCH_SEC;

	int idx = PKT_WRITE_TIME_INDEX(epochSecNow, 10);

	pDnsSession->flushType = type;
//	pDnsSession->FlushTimeEpochMicroSec = (epochSecNow * 1000000);

	storeDnsSession(idx, pDnsSession);
}

VOID S1UInterface::storeDnsSession(int idx, dnsSession *pDnsSession)
{
	int flusherNo = -1 ;

	flusherNo = instanceId % IPGlobal::DNS_FLUSHER_NO ;

	switch(flusherNo)
	{
	case 0:
		storeDnsSession_f_0(idx, pDnsSession);
		break;

	case 1:
		storeDnsSession_f_1(idx, pDnsSession);
		break;

	case 2:
		storeDnsSession_f_2(idx, pDnsSession);
		break;

	case 3:
		storeDnsSession_f_3(idx, pDnsSession);
		break;
	}
}

VOID S1UInterface::storeDnsSession_f_0(int index, dnsSession *pDnsSession)
{
	switch(instanceId)
	{
			case 0:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_0_sm_0_t_0[IPFlushRepository::dnsFlushMap_f_0_sm_0_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_0_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_0_sm_0_t_1[IPFlushRepository::dnsFlushMap_f_0_sm_0_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_0_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_0_sm_0_t_2[IPFlushRepository::dnsFlushMap_f_0_sm_0_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_0_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_0_sm_0_t_3[IPFlushRepository::dnsFlushMap_f_0_sm_0_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_0_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_0_sm_0_t_4[IPFlushRepository::dnsFlushMap_f_0_sm_0_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_0_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_0_sm_0_t_5[IPFlushRepository::dnsFlushMap_f_0_sm_0_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_0_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_0_sm_0_t_6[IPFlushRepository::dnsFlushMap_f_0_sm_0_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_0_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_0_sm_0_t_7[IPFlushRepository::dnsFlushMap_f_0_sm_0_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_0_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_0_sm_0_t_8[IPFlushRepository::dnsFlushMap_f_0_sm_0_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_0_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_0_sm_0_t_9[IPFlushRepository::dnsFlushMap_f_0_sm_0_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_0_t_9_cnt++;
						break;
					}
					break;

			case 1:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_0_sm_1_t_0[IPFlushRepository::dnsFlushMap_f_0_sm_1_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_1_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_0_sm_1_t_1[IPFlushRepository::dnsFlushMap_f_0_sm_1_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_1_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_0_sm_1_t_2[IPFlushRepository::dnsFlushMap_f_0_sm_1_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_1_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_0_sm_1_t_3[IPFlushRepository::dnsFlushMap_f_0_sm_1_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_1_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_0_sm_1_t_4[IPFlushRepository::dnsFlushMap_f_0_sm_1_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_1_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_0_sm_1_t_5[IPFlushRepository::dnsFlushMap_f_0_sm_1_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_1_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_0_sm_1_t_6[IPFlushRepository::dnsFlushMap_f_0_sm_1_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_1_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_0_sm_1_t_7[IPFlushRepository::dnsFlushMap_f_0_sm_1_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_1_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_0_sm_1_t_8[IPFlushRepository::dnsFlushMap_f_0_sm_1_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_1_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_0_sm_1_t_9[IPFlushRepository::dnsFlushMap_f_0_sm_1_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_1_t_9_cnt++;
						break;
					}
					break;
			case 2:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_0_sm_2_t_0[IPFlushRepository::dnsFlushMap_f_0_sm_2_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_2_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_0_sm_2_t_1[IPFlushRepository::dnsFlushMap_f_0_sm_2_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_2_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_0_sm_2_t_2[IPFlushRepository::dnsFlushMap_f_0_sm_2_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_2_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_0_sm_2_t_3[IPFlushRepository::dnsFlushMap_f_0_sm_2_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_2_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_0_sm_2_t_4[IPFlushRepository::dnsFlushMap_f_0_sm_2_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_2_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_0_sm_2_t_5[IPFlushRepository::dnsFlushMap_f_0_sm_2_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_2_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_0_sm_2_t_6[IPFlushRepository::dnsFlushMap_f_0_sm_2_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_2_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_0_sm_2_t_7[IPFlushRepository::dnsFlushMap_f_0_sm_2_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_2_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_0_sm_2_t_8[IPFlushRepository::dnsFlushMap_f_0_sm_2_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_2_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_0_sm_2_t_9[IPFlushRepository::dnsFlushMap_f_0_sm_2_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_2_t_9_cnt++;
						break;
					}
					break;

			case 3:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_0_sm_3_t_0[IPFlushRepository::dnsFlushMap_f_0_sm_3_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_3_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_0_sm_3_t_1[IPFlushRepository::dnsFlushMap_f_0_sm_3_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_3_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_0_sm_3_t_2[IPFlushRepository::dnsFlushMap_f_0_sm_3_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_3_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_0_sm_3_t_3[IPFlushRepository::dnsFlushMap_f_0_sm_3_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_3_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_0_sm_3_t_4[IPFlushRepository::dnsFlushMap_f_0_sm_3_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_3_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_0_sm_3_t_5[IPFlushRepository::dnsFlushMap_f_0_sm_3_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_3_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_0_sm_3_t_6[IPFlushRepository::dnsFlushMap_f_0_sm_3_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_3_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_0_sm_3_t_7[IPFlushRepository::dnsFlushMap_f_0_sm_3_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_3_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_0_sm_3_t_8[IPFlushRepository::dnsFlushMap_f_0_sm_3_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_3_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_0_sm_3_t_9[IPFlushRepository::dnsFlushMap_f_0_sm_3_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_3_t_9_cnt++;
						break;
					}
					break;

			case 4:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_0_sm_4_t_0[IPFlushRepository::dnsFlushMap_f_0_sm_4_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_4_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_0_sm_4_t_1[IPFlushRepository::dnsFlushMap_f_0_sm_4_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_4_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_0_sm_4_t_2[IPFlushRepository::dnsFlushMap_f_0_sm_4_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_4_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_0_sm_4_t_3[IPFlushRepository::dnsFlushMap_f_0_sm_4_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_4_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_0_sm_4_t_4[IPFlushRepository::dnsFlushMap_f_0_sm_4_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_4_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_0_sm_4_t_5[IPFlushRepository::dnsFlushMap_f_0_sm_4_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_4_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_0_sm_4_t_6[IPFlushRepository::dnsFlushMap_f_0_sm_4_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_4_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_0_sm_4_t_7[IPFlushRepository::dnsFlushMap_f_0_sm_4_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_4_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_0_sm_4_t_8[IPFlushRepository::dnsFlushMap_f_0_sm_4_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_4_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_0_sm_4_t_9[IPFlushRepository::dnsFlushMap_f_0_sm_4_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_4_t_9_cnt++;
						break;
					}
					break;

			case 5:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_0_sm_5_t_0[IPFlushRepository::dnsFlushMap_f_0_sm_5_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_5_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_0_sm_5_t_1[IPFlushRepository::dnsFlushMap_f_0_sm_5_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_5_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_0_sm_5_t_2[IPFlushRepository::dnsFlushMap_f_0_sm_5_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_5_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_0_sm_5_t_3[IPFlushRepository::dnsFlushMap_f_0_sm_5_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_5_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_0_sm_5_t_4[IPFlushRepository::dnsFlushMap_f_0_sm_5_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_5_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_0_sm_5_t_5[IPFlushRepository::dnsFlushMap_f_0_sm_5_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_5_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_0_sm_5_t_6[IPFlushRepository::dnsFlushMap_f_0_sm_5_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_5_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_0_sm_5_t_7[IPFlushRepository::dnsFlushMap_f_0_sm_5_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_5_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_0_sm_5_t_8[IPFlushRepository::dnsFlushMap_f_0_sm_5_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_5_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_0_sm_5_t_9[IPFlushRepository::dnsFlushMap_f_0_sm_5_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_5_t_9_cnt++;
						break;
					}
					break;

			case 6:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_0_sm_6_t_0[IPFlushRepository::dnsFlushMap_f_0_sm_6_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_6_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_0_sm_6_t_1[IPFlushRepository::dnsFlushMap_f_0_sm_6_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_6_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_0_sm_6_t_2[IPFlushRepository::dnsFlushMap_f_0_sm_6_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_6_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_0_sm_6_t_3[IPFlushRepository::dnsFlushMap_f_0_sm_6_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_6_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_0_sm_6_t_4[IPFlushRepository::dnsFlushMap_f_0_sm_6_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_6_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_0_sm_6_t_5[IPFlushRepository::dnsFlushMap_f_0_sm_6_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_6_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_0_sm_6_t_6[IPFlushRepository::dnsFlushMap_f_0_sm_6_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_6_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_0_sm_6_t_7[IPFlushRepository::dnsFlushMap_f_0_sm_6_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_6_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_0_sm_6_t_8[IPFlushRepository::dnsFlushMap_f_0_sm_6_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_6_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_0_sm_6_t_9[IPFlushRepository::dnsFlushMap_f_0_sm_6_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_6_t_9_cnt++;
						break;
					}
					break;
			case 7:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_0_sm_7_t_0[IPFlushRepository::dnsFlushMap_f_0_sm_7_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_7_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_0_sm_7_t_1[IPFlushRepository::dnsFlushMap_f_0_sm_7_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_7_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_0_sm_7_t_2[IPFlushRepository::dnsFlushMap_f_0_sm_7_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_7_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_0_sm_7_t_3[IPFlushRepository::dnsFlushMap_f_0_sm_7_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_7_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_0_sm_7_t_4[IPFlushRepository::dnsFlushMap_f_0_sm_7_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_7_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_0_sm_7_t_5[IPFlushRepository::dnsFlushMap_f_0_sm_7_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_7_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_0_sm_7_t_6[IPFlushRepository::dnsFlushMap_f_0_sm_7_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_7_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_0_sm_7_t_7[IPFlushRepository::dnsFlushMap_f_0_sm_7_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_7_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_0_sm_7_t_8[IPFlushRepository::dnsFlushMap_f_0_sm_7_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_7_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_0_sm_7_t_9[IPFlushRepository::dnsFlushMap_f_0_sm_7_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_7_t_9_cnt++;
						break;
					}
					break;
			case 8:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_0_sm_8_t_0[IPFlushRepository::dnsFlushMap_f_0_sm_8_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_8_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_0_sm_8_t_1[IPFlushRepository::dnsFlushMap_f_0_sm_8_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_8_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_0_sm_8_t_2[IPFlushRepository::dnsFlushMap_f_0_sm_8_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_8_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_0_sm_8_t_3[IPFlushRepository::dnsFlushMap_f_0_sm_8_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_8_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_0_sm_8_t_4[IPFlushRepository::dnsFlushMap_f_0_sm_8_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_8_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_0_sm_8_t_5[IPFlushRepository::dnsFlushMap_f_0_sm_8_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_8_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_0_sm_8_t_6[IPFlushRepository::dnsFlushMap_f_0_sm_8_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_8_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_0_sm_8_t_7[IPFlushRepository::dnsFlushMap_f_0_sm_8_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_8_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_0_sm_8_t_8[IPFlushRepository::dnsFlushMap_f_0_sm_8_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_8_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_0_sm_8_t_9[IPFlushRepository::dnsFlushMap_f_0_sm_8_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_8_t_9_cnt++;
						break;
					}
					break;
			case 9:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_0_sm_9_t_0[IPFlushRepository::dnsFlushMap_f_0_sm_9_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_9_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_0_sm_9_t_1[IPFlushRepository::dnsFlushMap_f_0_sm_9_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_9_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_0_sm_9_t_2[IPFlushRepository::dnsFlushMap_f_0_sm_9_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_9_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_0_sm_9_t_3[IPFlushRepository::dnsFlushMap_f_0_sm_9_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_9_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_0_sm_9_t_4[IPFlushRepository::dnsFlushMap_f_0_sm_9_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_9_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_0_sm_9_t_5[IPFlushRepository::dnsFlushMap_f_0_sm_9_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_9_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_0_sm_9_t_6[IPFlushRepository::dnsFlushMap_f_0_sm_9_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_9_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_0_sm_9_t_7[IPFlushRepository::dnsFlushMap_f_0_sm_9_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_9_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_0_sm_9_t_8[IPFlushRepository::dnsFlushMap_f_0_sm_9_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_9_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_0_sm_9_t_9[IPFlushRepository::dnsFlushMap_f_0_sm_9_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_9_t_9_cnt++;
						break;
					}
					break;
			case 10:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_0_sm_10_t_0[IPFlushRepository::dnsFlushMap_f_0_sm_10_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_10_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_0_sm_10_t_1[IPFlushRepository::dnsFlushMap_f_0_sm_10_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_10_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_0_sm_10_t_2[IPFlushRepository::dnsFlushMap_f_0_sm_10_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_10_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_0_sm_10_t_3[IPFlushRepository::dnsFlushMap_f_0_sm_10_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_10_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_0_sm_10_t_4[IPFlushRepository::dnsFlushMap_f_0_sm_10_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_10_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_0_sm_10_t_5[IPFlushRepository::dnsFlushMap_f_0_sm_10_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_10_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_0_sm_10_t_6[IPFlushRepository::dnsFlushMap_f_0_sm_10_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_10_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_0_sm_10_t_7[IPFlushRepository::dnsFlushMap_f_0_sm_10_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_10_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_0_sm_10_t_8[IPFlushRepository::dnsFlushMap_f_0_sm_10_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_10_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_0_sm_10_t_9[IPFlushRepository::dnsFlushMap_f_0_sm_10_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_10_t_9_cnt++;
						break;
					}
					break;
			case 11:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_0_sm_11_t_0[IPFlushRepository::dnsFlushMap_f_0_sm_11_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_11_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_0_sm_11_t_1[IPFlushRepository::dnsFlushMap_f_0_sm_11_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_11_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_0_sm_11_t_2[IPFlushRepository::dnsFlushMap_f_0_sm_11_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_11_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_0_sm_11_t_3[IPFlushRepository::dnsFlushMap_f_0_sm_11_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_11_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_0_sm_11_t_4[IPFlushRepository::dnsFlushMap_f_0_sm_11_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_11_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_0_sm_11_t_5[IPFlushRepository::dnsFlushMap_f_0_sm_11_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_11_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_0_sm_11_t_6[IPFlushRepository::dnsFlushMap_f_0_sm_11_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_11_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_0_sm_11_t_7[IPFlushRepository::dnsFlushMap_f_0_sm_11_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_11_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_0_sm_11_t_8[IPFlushRepository::dnsFlushMap_f_0_sm_11_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_11_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_0_sm_11_t_9[IPFlushRepository::dnsFlushMap_f_0_sm_11_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_11_t_9_cnt++;
						break;
					}
					break;
			case 12:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_0_sm_12_t_0[IPFlushRepository::dnsFlushMap_f_0_sm_12_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_12_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_0_sm_12_t_1[IPFlushRepository::dnsFlushMap_f_0_sm_12_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_12_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_0_sm_12_t_2[IPFlushRepository::dnsFlushMap_f_0_sm_12_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_12_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_0_sm_12_t_3[IPFlushRepository::dnsFlushMap_f_0_sm_12_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_12_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_0_sm_12_t_4[IPFlushRepository::dnsFlushMap_f_0_sm_12_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_12_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_0_sm_12_t_5[IPFlushRepository::dnsFlushMap_f_0_sm_12_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_12_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_0_sm_12_t_6[IPFlushRepository::dnsFlushMap_f_0_sm_12_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_12_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_0_sm_12_t_7[IPFlushRepository::dnsFlushMap_f_0_sm_12_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_12_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_0_sm_12_t_8[IPFlushRepository::dnsFlushMap_f_0_sm_12_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_12_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_0_sm_12_t_9[IPFlushRepository::dnsFlushMap_f_0_sm_12_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_12_t_9_cnt++;
						break;
					}
					break;
			case 13:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_0_sm_13_t_0[IPFlushRepository::dnsFlushMap_f_0_sm_13_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_13_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_0_sm_13_t_1[IPFlushRepository::dnsFlushMap_f_0_sm_13_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_13_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_0_sm_13_t_2[IPFlushRepository::dnsFlushMap_f_0_sm_13_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_13_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_0_sm_13_t_3[IPFlushRepository::dnsFlushMap_f_0_sm_13_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_13_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_0_sm_13_t_4[IPFlushRepository::dnsFlushMap_f_0_sm_13_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_13_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_0_sm_13_t_5[IPFlushRepository::dnsFlushMap_f_0_sm_13_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_13_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_0_sm_13_t_6[IPFlushRepository::dnsFlushMap_f_0_sm_13_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_13_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_0_sm_13_t_7[IPFlushRepository::dnsFlushMap_f_0_sm_13_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_13_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_0_sm_13_t_8[IPFlushRepository::dnsFlushMap_f_0_sm_13_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_13_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_0_sm_13_t_9[IPFlushRepository::dnsFlushMap_f_0_sm_13_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_13_t_9_cnt++;
						break;
					}
					break;
			case 14:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_0_sm_14_t_0[IPFlushRepository::dnsFlushMap_f_0_sm_14_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_14_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_0_sm_14_t_1[IPFlushRepository::dnsFlushMap_f_0_sm_14_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_14_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_0_sm_14_t_2[IPFlushRepository::dnsFlushMap_f_0_sm_14_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_14_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_0_sm_14_t_3[IPFlushRepository::dnsFlushMap_f_0_sm_14_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_14_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_0_sm_14_t_4[IPFlushRepository::dnsFlushMap_f_0_sm_14_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_14_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_0_sm_14_t_5[IPFlushRepository::dnsFlushMap_f_0_sm_14_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_14_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_0_sm_14_t_6[IPFlushRepository::dnsFlushMap_f_0_sm_14_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_14_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_0_sm_14_t_7[IPFlushRepository::dnsFlushMap_f_0_sm_14_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_14_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_0_sm_14_t_8[IPFlushRepository::dnsFlushMap_f_0_sm_14_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_14_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_0_sm_14_t_9[IPFlushRepository::dnsFlushMap_f_0_sm_14_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_14_t_9_cnt++;
						break;
					}
					break;
			case 15:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_0_sm_15_t_0[IPFlushRepository::dnsFlushMap_f_0_sm_15_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_15_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_0_sm_15_t_1[IPFlushRepository::dnsFlushMap_f_0_sm_15_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_15_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_0_sm_15_t_2[IPFlushRepository::dnsFlushMap_f_0_sm_15_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_15_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_0_sm_15_t_3[IPFlushRepository::dnsFlushMap_f_0_sm_15_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_15_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_0_sm_15_t_4[IPFlushRepository::dnsFlushMap_f_0_sm_15_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_15_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_0_sm_15_t_5[IPFlushRepository::dnsFlushMap_f_0_sm_15_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_15_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_0_sm_15_t_6[IPFlushRepository::dnsFlushMap_f_0_sm_15_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_15_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_0_sm_15_t_7[IPFlushRepository::dnsFlushMap_f_0_sm_15_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_15_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_0_sm_15_t_8[IPFlushRepository::dnsFlushMap_f_0_sm_15_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_15_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_0_sm_15_t_9[IPFlushRepository::dnsFlushMap_f_0_sm_15_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_15_t_9_cnt++;
						break;
					}
					break;
			case 16:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_0_sm_16_t_0[IPFlushRepository::dnsFlushMap_f_0_sm_16_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_16_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_0_sm_16_t_1[IPFlushRepository::dnsFlushMap_f_0_sm_16_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_16_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_0_sm_16_t_2[IPFlushRepository::dnsFlushMap_f_0_sm_16_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_16_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_0_sm_16_t_3[IPFlushRepository::dnsFlushMap_f_0_sm_16_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_16_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_0_sm_16_t_4[IPFlushRepository::dnsFlushMap_f_0_sm_16_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_16_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_0_sm_16_t_5[IPFlushRepository::dnsFlushMap_f_0_sm_16_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_16_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_0_sm_16_t_6[IPFlushRepository::dnsFlushMap_f_0_sm_16_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_16_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_0_sm_16_t_7[IPFlushRepository::dnsFlushMap_f_0_sm_16_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_16_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_0_sm_16_t_8[IPFlushRepository::dnsFlushMap_f_0_sm_16_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_16_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_0_sm_16_t_9[IPFlushRepository::dnsFlushMap_f_0_sm_16_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_16_t_9_cnt++;
						break;
					}
					break;
			case 17:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_0_sm_17_t_0[IPFlushRepository::dnsFlushMap_f_0_sm_17_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_17_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_0_sm_17_t_1[IPFlushRepository::dnsFlushMap_f_0_sm_17_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_17_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_0_sm_17_t_2[IPFlushRepository::dnsFlushMap_f_0_sm_17_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_17_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_0_sm_17_t_3[IPFlushRepository::dnsFlushMap_f_0_sm_17_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_17_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_0_sm_17_t_4[IPFlushRepository::dnsFlushMap_f_0_sm_17_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_17_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_0_sm_17_t_5[IPFlushRepository::dnsFlushMap_f_0_sm_17_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_17_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_0_sm_17_t_6[IPFlushRepository::dnsFlushMap_f_0_sm_17_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_17_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_0_sm_17_t_7[IPFlushRepository::dnsFlushMap_f_0_sm_17_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_17_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_0_sm_17_t_8[IPFlushRepository::dnsFlushMap_f_0_sm_17_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_17_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_0_sm_17_t_9[IPFlushRepository::dnsFlushMap_f_0_sm_17_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_17_t_9_cnt++;
						break;
					}
					break;
			case 18:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_0_sm_18_t_0[IPFlushRepository::dnsFlushMap_f_0_sm_18_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_18_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_0_sm_18_t_1[IPFlushRepository::dnsFlushMap_f_0_sm_18_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_18_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_0_sm_18_t_2[IPFlushRepository::dnsFlushMap_f_0_sm_18_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_18_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_0_sm_18_t_3[IPFlushRepository::dnsFlushMap_f_0_sm_18_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_18_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_0_sm_18_t_4[IPFlushRepository::dnsFlushMap_f_0_sm_18_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_18_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_0_sm_18_t_5[IPFlushRepository::dnsFlushMap_f_0_sm_18_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_18_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_0_sm_18_t_6[IPFlushRepository::dnsFlushMap_f_0_sm_18_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_18_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_0_sm_18_t_7[IPFlushRepository::dnsFlushMap_f_0_sm_18_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_18_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_0_sm_18_t_8[IPFlushRepository::dnsFlushMap_f_0_sm_18_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_18_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_0_sm_18_t_9[IPFlushRepository::dnsFlushMap_f_0_sm_18_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_18_t_9_cnt++;
						break;
					}
					break;
			case 19:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_0_sm_19_t_0[IPFlushRepository::dnsFlushMap_f_0_sm_19_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_19_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_0_sm_19_t_1[IPFlushRepository::dnsFlushMap_f_0_sm_19_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_19_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_0_sm_19_t_2[IPFlushRepository::dnsFlushMap_f_0_sm_19_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_19_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_0_sm_19_t_3[IPFlushRepository::dnsFlushMap_f_0_sm_19_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_19_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_0_sm_19_t_4[IPFlushRepository::dnsFlushMap_f_0_sm_19_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_19_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_0_sm_19_t_5[IPFlushRepository::dnsFlushMap_f_0_sm_19_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_19_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_0_sm_19_t_6[IPFlushRepository::dnsFlushMap_f_0_sm_19_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_19_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_0_sm_19_t_7[IPFlushRepository::dnsFlushMap_f_0_sm_19_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_19_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_0_sm_19_t_8[IPFlushRepository::dnsFlushMap_f_0_sm_19_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_19_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_0_sm_19_t_9[IPFlushRepository::dnsFlushMap_f_0_sm_19_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_19_t_9_cnt++;
						break;
					}
					break;
			case 20:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_0_sm_20_t_0[IPFlushRepository::dnsFlushMap_f_0_sm_20_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_20_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_0_sm_20_t_1[IPFlushRepository::dnsFlushMap_f_0_sm_20_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_20_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_0_sm_20_t_2[IPFlushRepository::dnsFlushMap_f_0_sm_20_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_20_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_0_sm_20_t_3[IPFlushRepository::dnsFlushMap_f_0_sm_20_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_20_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_0_sm_20_t_4[IPFlushRepository::dnsFlushMap_f_0_sm_20_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_20_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_0_sm_20_t_5[IPFlushRepository::dnsFlushMap_f_0_sm_20_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_20_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_0_sm_20_t_6[IPFlushRepository::dnsFlushMap_f_0_sm_20_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_20_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_0_sm_20_t_7[IPFlushRepository::dnsFlushMap_f_0_sm_20_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_20_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_0_sm_20_t_8[IPFlushRepository::dnsFlushMap_f_0_sm_20_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_20_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_0_sm_20_t_9[IPFlushRepository::dnsFlushMap_f_0_sm_20_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_20_t_9_cnt++;
						break;
					}
					break;
			case 21:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_0_sm_21_t_0[IPFlushRepository::dnsFlushMap_f_0_sm_21_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_21_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_0_sm_21_t_1[IPFlushRepository::dnsFlushMap_f_0_sm_21_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_21_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_0_sm_21_t_2[IPFlushRepository::dnsFlushMap_f_0_sm_21_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_21_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_0_sm_21_t_3[IPFlushRepository::dnsFlushMap_f_0_sm_21_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_21_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_0_sm_21_t_4[IPFlushRepository::dnsFlushMap_f_0_sm_21_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_21_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_0_sm_21_t_5[IPFlushRepository::dnsFlushMap_f_0_sm_21_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_21_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_0_sm_21_t_6[IPFlushRepository::dnsFlushMap_f_0_sm_21_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_21_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_0_sm_21_t_7[IPFlushRepository::dnsFlushMap_f_0_sm_21_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_21_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_0_sm_21_t_8[IPFlushRepository::dnsFlushMap_f_0_sm_21_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_21_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_0_sm_21_t_9[IPFlushRepository::dnsFlushMap_f_0_sm_21_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_21_t_9_cnt++;
						break;
					}
					break;
			case 22:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_0_sm_22_t_0[IPFlushRepository::dnsFlushMap_f_0_sm_22_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_22_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_0_sm_22_t_1[IPFlushRepository::dnsFlushMap_f_0_sm_22_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_22_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_0_sm_22_t_2[IPFlushRepository::dnsFlushMap_f_0_sm_22_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_22_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_0_sm_22_t_3[IPFlushRepository::dnsFlushMap_f_0_sm_22_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_22_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_0_sm_22_t_4[IPFlushRepository::dnsFlushMap_f_0_sm_22_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_22_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_0_sm_22_t_5[IPFlushRepository::dnsFlushMap_f_0_sm_22_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_22_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_0_sm_22_t_6[IPFlushRepository::dnsFlushMap_f_0_sm_22_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_22_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_0_sm_22_t_7[IPFlushRepository::dnsFlushMap_f_0_sm_22_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_22_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_0_sm_22_t_8[IPFlushRepository::dnsFlushMap_f_0_sm_22_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_22_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_0_sm_22_t_9[IPFlushRepository::dnsFlushMap_f_0_sm_22_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_22_t_9_cnt++;
						break;
					}
					break;
			case 23:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_0_sm_23_t_0[IPFlushRepository::dnsFlushMap_f_0_sm_23_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_23_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_0_sm_23_t_1[IPFlushRepository::dnsFlushMap_f_0_sm_23_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_23_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_0_sm_23_t_2[IPFlushRepository::dnsFlushMap_f_0_sm_23_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_23_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_0_sm_23_t_3[IPFlushRepository::dnsFlushMap_f_0_sm_23_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_23_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_0_sm_23_t_4[IPFlushRepository::dnsFlushMap_f_0_sm_23_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_23_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_0_sm_23_t_5[IPFlushRepository::dnsFlushMap_f_0_sm_23_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_23_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_0_sm_23_t_6[IPFlushRepository::dnsFlushMap_f_0_sm_23_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_23_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_0_sm_23_t_7[IPFlushRepository::dnsFlushMap_f_0_sm_23_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_23_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_0_sm_23_t_8[IPFlushRepository::dnsFlushMap_f_0_sm_23_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_23_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_0_sm_23_t_9[IPFlushRepository::dnsFlushMap_f_0_sm_23_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_23_t_9_cnt++;
						break;
					}
					break;
			case 24:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_0_sm_24_t_0[IPFlushRepository::dnsFlushMap_f_0_sm_24_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_24_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_0_sm_24_t_1[IPFlushRepository::dnsFlushMap_f_0_sm_24_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_24_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_0_sm_24_t_2[IPFlushRepository::dnsFlushMap_f_0_sm_24_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_24_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_0_sm_24_t_3[IPFlushRepository::dnsFlushMap_f_0_sm_24_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_24_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_0_sm_24_t_4[IPFlushRepository::dnsFlushMap_f_0_sm_24_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_24_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_0_sm_24_t_5[IPFlushRepository::dnsFlushMap_f_0_sm_24_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_24_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_0_sm_24_t_6[IPFlushRepository::dnsFlushMap_f_0_sm_24_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_24_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_0_sm_24_t_7[IPFlushRepository::dnsFlushMap_f_0_sm_24_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_24_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_0_sm_24_t_8[IPFlushRepository::dnsFlushMap_f_0_sm_24_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_24_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_0_sm_24_t_9[IPFlushRepository::dnsFlushMap_f_0_sm_24_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_24_t_9_cnt++;
						break;
					}
					break;
			case 25:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_0_sm_25_t_0[IPFlushRepository::dnsFlushMap_f_0_sm_25_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_25_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_0_sm_25_t_1[IPFlushRepository::dnsFlushMap_f_0_sm_25_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_25_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_0_sm_25_t_2[IPFlushRepository::dnsFlushMap_f_0_sm_25_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_25_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_0_sm_25_t_3[IPFlushRepository::dnsFlushMap_f_0_sm_25_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_25_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_0_sm_25_t_4[IPFlushRepository::dnsFlushMap_f_0_sm_25_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_25_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_0_sm_25_t_5[IPFlushRepository::dnsFlushMap_f_0_sm_25_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_25_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_0_sm_25_t_6[IPFlushRepository::dnsFlushMap_f_0_sm_25_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_25_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_0_sm_25_t_7[IPFlushRepository::dnsFlushMap_f_0_sm_25_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_25_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_0_sm_25_t_8[IPFlushRepository::dnsFlushMap_f_0_sm_25_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_25_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_0_sm_25_t_9[IPFlushRepository::dnsFlushMap_f_0_sm_25_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_25_t_9_cnt++;
						break;
					}
					break;
			case 26:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_0_sm_26_t_0[IPFlushRepository::dnsFlushMap_f_0_sm_26_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_26_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_0_sm_26_t_1[IPFlushRepository::dnsFlushMap_f_0_sm_26_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_26_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_0_sm_26_t_2[IPFlushRepository::dnsFlushMap_f_0_sm_26_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_26_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_0_sm_26_t_3[IPFlushRepository::dnsFlushMap_f_0_sm_26_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_26_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_0_sm_26_t_4[IPFlushRepository::dnsFlushMap_f_0_sm_26_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_26_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_0_sm_26_t_5[IPFlushRepository::dnsFlushMap_f_0_sm_26_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_26_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_0_sm_26_t_6[IPFlushRepository::dnsFlushMap_f_0_sm_26_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_26_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_0_sm_26_t_7[IPFlushRepository::dnsFlushMap_f_0_sm_26_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_26_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_0_sm_26_t_8[IPFlushRepository::dnsFlushMap_f_0_sm_26_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_26_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_0_sm_26_t_9[IPFlushRepository::dnsFlushMap_f_0_sm_26_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_26_t_9_cnt++;
						break;
					}
					break;
			case 27:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_0_sm_27_t_0[IPFlushRepository::dnsFlushMap_f_0_sm_27_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_27_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_0_sm_27_t_1[IPFlushRepository::dnsFlushMap_f_0_sm_27_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_27_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_0_sm_27_t_2[IPFlushRepository::dnsFlushMap_f_0_sm_27_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_27_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_0_sm_27_t_3[IPFlushRepository::dnsFlushMap_f_0_sm_27_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_27_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_0_sm_27_t_4[IPFlushRepository::dnsFlushMap_f_0_sm_27_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_27_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_0_sm_27_t_5[IPFlushRepository::dnsFlushMap_f_0_sm_27_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_27_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_0_sm_27_t_6[IPFlushRepository::dnsFlushMap_f_0_sm_27_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_27_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_0_sm_27_t_7[IPFlushRepository::dnsFlushMap_f_0_sm_27_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_27_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_0_sm_27_t_8[IPFlushRepository::dnsFlushMap_f_0_sm_27_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_27_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_0_sm_27_t_9[IPFlushRepository::dnsFlushMap_f_0_sm_27_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_27_t_9_cnt++;
						break;
					}
					break;
			case 28:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_0_sm_28_t_0[IPFlushRepository::dnsFlushMap_f_0_sm_28_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_28_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_0_sm_28_t_1[IPFlushRepository::dnsFlushMap_f_0_sm_28_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_28_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_0_sm_28_t_2[IPFlushRepository::dnsFlushMap_f_0_sm_28_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_28_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_0_sm_28_t_3[IPFlushRepository::dnsFlushMap_f_0_sm_28_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_28_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_0_sm_28_t_4[IPFlushRepository::dnsFlushMap_f_0_sm_28_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_28_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_0_sm_28_t_5[IPFlushRepository::dnsFlushMap_f_0_sm_28_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_28_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_0_sm_28_t_6[IPFlushRepository::dnsFlushMap_f_0_sm_28_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_28_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_0_sm_28_t_7[IPFlushRepository::dnsFlushMap_f_0_sm_28_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_28_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_0_sm_28_t_8[IPFlushRepository::dnsFlushMap_f_0_sm_28_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_28_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_0_sm_28_t_9[IPFlushRepository::dnsFlushMap_f_0_sm_28_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_28_t_9_cnt++;
						break;
					}
					break;
			case 29:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_0_sm_29_t_0[IPFlushRepository::dnsFlushMap_f_0_sm_29_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_29_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_0_sm_29_t_1[IPFlushRepository::dnsFlushMap_f_0_sm_29_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_29_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_0_sm_29_t_2[IPFlushRepository::dnsFlushMap_f_0_sm_29_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_29_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_0_sm_29_t_3[IPFlushRepository::dnsFlushMap_f_0_sm_29_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_29_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_0_sm_29_t_4[IPFlushRepository::dnsFlushMap_f_0_sm_29_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_29_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_0_sm_29_t_5[IPFlushRepository::dnsFlushMap_f_0_sm_29_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_29_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_0_sm_29_t_6[IPFlushRepository::dnsFlushMap_f_0_sm_29_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_29_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_0_sm_29_t_7[IPFlushRepository::dnsFlushMap_f_0_sm_29_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_29_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_0_sm_29_t_8[IPFlushRepository::dnsFlushMap_f_0_sm_29_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_29_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_0_sm_29_t_9[IPFlushRepository::dnsFlushMap_f_0_sm_29_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_0_sm_29_t_9_cnt++;
						break;
					}
					break;

	}
}

VOID S1UInterface::storeDnsSession_f_1(int index, dnsSession *pDnsSession)
{
	switch(instanceId)
	{
			case 0:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_1_sm_0_t_0[IPFlushRepository::dnsFlushMap_f_1_sm_0_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_0_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_1_sm_0_t_1[IPFlushRepository::dnsFlushMap_f_1_sm_0_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_0_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_1_sm_0_t_2[IPFlushRepository::dnsFlushMap_f_1_sm_0_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_0_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_1_sm_0_t_3[IPFlushRepository::dnsFlushMap_f_1_sm_0_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_0_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_1_sm_0_t_4[IPFlushRepository::dnsFlushMap_f_1_sm_0_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_0_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_1_sm_0_t_5[IPFlushRepository::dnsFlushMap_f_1_sm_0_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_0_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_1_sm_0_t_6[IPFlushRepository::dnsFlushMap_f_1_sm_0_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_0_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_1_sm_0_t_7[IPFlushRepository::dnsFlushMap_f_1_sm_0_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_0_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_1_sm_0_t_8[IPFlushRepository::dnsFlushMap_f_1_sm_0_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_0_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_1_sm_0_t_9[IPFlushRepository::dnsFlushMap_f_1_sm_0_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_0_t_9_cnt++;
						break;
					}
					break;

			case 1:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_1_sm_1_t_0[IPFlushRepository::dnsFlushMap_f_1_sm_1_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_1_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_1_sm_1_t_1[IPFlushRepository::dnsFlushMap_f_1_sm_1_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_1_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_1_sm_1_t_2[IPFlushRepository::dnsFlushMap_f_1_sm_1_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_1_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_1_sm_1_t_3[IPFlushRepository::dnsFlushMap_f_1_sm_1_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_1_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_1_sm_1_t_4[IPFlushRepository::dnsFlushMap_f_1_sm_1_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_1_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_1_sm_1_t_5[IPFlushRepository::dnsFlushMap_f_1_sm_1_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_1_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_1_sm_1_t_6[IPFlushRepository::dnsFlushMap_f_1_sm_1_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_1_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_1_sm_1_t_7[IPFlushRepository::dnsFlushMap_f_1_sm_1_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_1_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_1_sm_1_t_8[IPFlushRepository::dnsFlushMap_f_1_sm_1_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_1_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_1_sm_1_t_9[IPFlushRepository::dnsFlushMap_f_1_sm_1_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_1_t_9_cnt++;
						break;
					}
					break;
			case 2:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_1_sm_2_t_0[IPFlushRepository::dnsFlushMap_f_1_sm_2_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_2_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_1_sm_2_t_1[IPFlushRepository::dnsFlushMap_f_1_sm_2_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_2_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_1_sm_2_t_2[IPFlushRepository::dnsFlushMap_f_1_sm_2_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_2_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_1_sm_2_t_3[IPFlushRepository::dnsFlushMap_f_1_sm_2_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_2_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_1_sm_2_t_4[IPFlushRepository::dnsFlushMap_f_1_sm_2_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_2_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_1_sm_2_t_5[IPFlushRepository::dnsFlushMap_f_1_sm_2_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_2_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_1_sm_2_t_6[IPFlushRepository::dnsFlushMap_f_1_sm_2_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_2_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_1_sm_2_t_7[IPFlushRepository::dnsFlushMap_f_1_sm_2_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_2_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_1_sm_2_t_8[IPFlushRepository::dnsFlushMap_f_1_sm_2_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_2_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_1_sm_2_t_9[IPFlushRepository::dnsFlushMap_f_1_sm_2_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_2_t_9_cnt++;
						break;
					}
					break;

			case 3:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_1_sm_3_t_0[IPFlushRepository::dnsFlushMap_f_1_sm_3_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_3_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_1_sm_3_t_1[IPFlushRepository::dnsFlushMap_f_1_sm_3_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_3_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_1_sm_3_t_2[IPFlushRepository::dnsFlushMap_f_1_sm_3_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_3_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_1_sm_3_t_3[IPFlushRepository::dnsFlushMap_f_1_sm_3_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_3_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_1_sm_3_t_4[IPFlushRepository::dnsFlushMap_f_1_sm_3_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_3_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_1_sm_3_t_5[IPFlushRepository::dnsFlushMap_f_1_sm_3_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_3_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_1_sm_3_t_6[IPFlushRepository::dnsFlushMap_f_1_sm_3_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_3_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_1_sm_3_t_7[IPFlushRepository::dnsFlushMap_f_1_sm_3_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_3_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_1_sm_3_t_8[IPFlushRepository::dnsFlushMap_f_1_sm_3_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_3_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_1_sm_3_t_9[IPFlushRepository::dnsFlushMap_f_1_sm_3_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_3_t_9_cnt++;
						break;
					}
					break;

			case 4:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_1_sm_4_t_0[IPFlushRepository::dnsFlushMap_f_1_sm_4_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_4_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_1_sm_4_t_1[IPFlushRepository::dnsFlushMap_f_1_sm_4_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_4_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_1_sm_4_t_2[IPFlushRepository::dnsFlushMap_f_1_sm_4_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_4_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_1_sm_4_t_3[IPFlushRepository::dnsFlushMap_f_1_sm_4_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_4_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_1_sm_4_t_4[IPFlushRepository::dnsFlushMap_f_1_sm_4_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_4_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_1_sm_4_t_5[IPFlushRepository::dnsFlushMap_f_1_sm_4_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_4_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_1_sm_4_t_6[IPFlushRepository::dnsFlushMap_f_1_sm_4_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_4_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_1_sm_4_t_7[IPFlushRepository::dnsFlushMap_f_1_sm_4_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_4_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_1_sm_4_t_8[IPFlushRepository::dnsFlushMap_f_1_sm_4_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_4_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_1_sm_4_t_9[IPFlushRepository::dnsFlushMap_f_1_sm_4_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_4_t_9_cnt++;
						break;
					}
					break;

			case 5:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_1_sm_5_t_0[IPFlushRepository::dnsFlushMap_f_1_sm_5_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_5_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_1_sm_5_t_1[IPFlushRepository::dnsFlushMap_f_1_sm_5_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_5_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_1_sm_5_t_2[IPFlushRepository::dnsFlushMap_f_1_sm_5_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_5_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_1_sm_5_t_3[IPFlushRepository::dnsFlushMap_f_1_sm_5_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_5_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_1_sm_5_t_4[IPFlushRepository::dnsFlushMap_f_1_sm_5_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_5_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_1_sm_5_t_5[IPFlushRepository::dnsFlushMap_f_1_sm_5_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_5_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_1_sm_5_t_6[IPFlushRepository::dnsFlushMap_f_1_sm_5_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_5_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_1_sm_5_t_7[IPFlushRepository::dnsFlushMap_f_1_sm_5_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_5_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_1_sm_5_t_8[IPFlushRepository::dnsFlushMap_f_1_sm_5_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_5_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_1_sm_5_t_9[IPFlushRepository::dnsFlushMap_f_1_sm_5_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_5_t_9_cnt++;
						break;
					}
					break;

			case 6:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_1_sm_6_t_0[IPFlushRepository::dnsFlushMap_f_1_sm_6_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_6_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_1_sm_6_t_1[IPFlushRepository::dnsFlushMap_f_1_sm_6_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_6_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_1_sm_6_t_2[IPFlushRepository::dnsFlushMap_f_1_sm_6_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_6_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_1_sm_6_t_3[IPFlushRepository::dnsFlushMap_f_1_sm_6_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_6_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_1_sm_6_t_4[IPFlushRepository::dnsFlushMap_f_1_sm_6_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_6_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_1_sm_6_t_5[IPFlushRepository::dnsFlushMap_f_1_sm_6_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_6_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_1_sm_6_t_6[IPFlushRepository::dnsFlushMap_f_1_sm_6_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_6_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_1_sm_6_t_7[IPFlushRepository::dnsFlushMap_f_1_sm_6_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_6_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_1_sm_6_t_8[IPFlushRepository::dnsFlushMap_f_1_sm_6_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_6_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_1_sm_6_t_9[IPFlushRepository::dnsFlushMap_f_1_sm_6_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_6_t_9_cnt++;
						break;
					}
					break;
			case 7:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_1_sm_7_t_0[IPFlushRepository::dnsFlushMap_f_1_sm_7_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_7_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_1_sm_7_t_1[IPFlushRepository::dnsFlushMap_f_1_sm_7_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_7_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_1_sm_7_t_2[IPFlushRepository::dnsFlushMap_f_1_sm_7_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_7_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_1_sm_7_t_3[IPFlushRepository::dnsFlushMap_f_1_sm_7_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_7_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_1_sm_7_t_4[IPFlushRepository::dnsFlushMap_f_1_sm_7_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_7_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_1_sm_7_t_5[IPFlushRepository::dnsFlushMap_f_1_sm_7_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_7_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_1_sm_7_t_6[IPFlushRepository::dnsFlushMap_f_1_sm_7_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_7_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_1_sm_7_t_7[IPFlushRepository::dnsFlushMap_f_1_sm_7_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_7_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_1_sm_7_t_8[IPFlushRepository::dnsFlushMap_f_1_sm_7_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_7_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_1_sm_7_t_9[IPFlushRepository::dnsFlushMap_f_1_sm_7_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_7_t_9_cnt++;
						break;
					}
					break;
			case 8:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_1_sm_8_t_0[IPFlushRepository::dnsFlushMap_f_1_sm_8_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_8_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_1_sm_8_t_1[IPFlushRepository::dnsFlushMap_f_1_sm_8_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_8_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_1_sm_8_t_2[IPFlushRepository::dnsFlushMap_f_1_sm_8_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_8_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_1_sm_8_t_3[IPFlushRepository::dnsFlushMap_f_1_sm_8_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_8_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_1_sm_8_t_4[IPFlushRepository::dnsFlushMap_f_1_sm_8_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_8_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_1_sm_8_t_5[IPFlushRepository::dnsFlushMap_f_1_sm_8_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_8_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_1_sm_8_t_6[IPFlushRepository::dnsFlushMap_f_1_sm_8_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_8_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_1_sm_8_t_7[IPFlushRepository::dnsFlushMap_f_1_sm_8_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_8_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_1_sm_8_t_8[IPFlushRepository::dnsFlushMap_f_1_sm_8_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_8_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_1_sm_8_t_9[IPFlushRepository::dnsFlushMap_f_1_sm_8_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_8_t_9_cnt++;
						break;
					}
					break;
			case 9:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_1_sm_9_t_0[IPFlushRepository::dnsFlushMap_f_1_sm_9_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_9_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_1_sm_9_t_1[IPFlushRepository::dnsFlushMap_f_1_sm_9_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_9_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_1_sm_9_t_2[IPFlushRepository::dnsFlushMap_f_1_sm_9_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_9_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_1_sm_9_t_3[IPFlushRepository::dnsFlushMap_f_1_sm_9_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_9_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_1_sm_9_t_4[IPFlushRepository::dnsFlushMap_f_1_sm_9_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_9_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_1_sm_9_t_5[IPFlushRepository::dnsFlushMap_f_1_sm_9_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_9_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_1_sm_9_t_6[IPFlushRepository::dnsFlushMap_f_1_sm_9_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_9_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_1_sm_9_t_7[IPFlushRepository::dnsFlushMap_f_1_sm_9_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_9_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_1_sm_9_t_8[IPFlushRepository::dnsFlushMap_f_1_sm_9_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_9_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_1_sm_9_t_9[IPFlushRepository::dnsFlushMap_f_1_sm_9_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_9_t_9_cnt++;
						break;
					}
					break;
			case 10:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_1_sm_10_t_0[IPFlushRepository::dnsFlushMap_f_1_sm_10_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_10_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_1_sm_10_t_1[IPFlushRepository::dnsFlushMap_f_1_sm_10_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_10_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_1_sm_10_t_2[IPFlushRepository::dnsFlushMap_f_1_sm_10_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_10_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_1_sm_10_t_3[IPFlushRepository::dnsFlushMap_f_1_sm_10_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_10_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_1_sm_10_t_4[IPFlushRepository::dnsFlushMap_f_1_sm_10_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_10_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_1_sm_10_t_5[IPFlushRepository::dnsFlushMap_f_1_sm_10_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_10_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_1_sm_10_t_6[IPFlushRepository::dnsFlushMap_f_1_sm_10_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_10_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_1_sm_10_t_7[IPFlushRepository::dnsFlushMap_f_1_sm_10_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_10_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_1_sm_10_t_8[IPFlushRepository::dnsFlushMap_f_1_sm_10_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_10_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_1_sm_10_t_9[IPFlushRepository::dnsFlushMap_f_1_sm_10_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_10_t_9_cnt++;
						break;
					}
					break;
			case 11:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_1_sm_11_t_0[IPFlushRepository::dnsFlushMap_f_1_sm_11_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_11_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_1_sm_11_t_1[IPFlushRepository::dnsFlushMap_f_1_sm_11_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_11_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_1_sm_11_t_2[IPFlushRepository::dnsFlushMap_f_1_sm_11_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_11_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_1_sm_11_t_3[IPFlushRepository::dnsFlushMap_f_1_sm_11_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_11_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_1_sm_11_t_4[IPFlushRepository::dnsFlushMap_f_1_sm_11_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_11_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_1_sm_11_t_5[IPFlushRepository::dnsFlushMap_f_1_sm_11_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_11_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_1_sm_11_t_6[IPFlushRepository::dnsFlushMap_f_1_sm_11_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_11_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_1_sm_11_t_7[IPFlushRepository::dnsFlushMap_f_1_sm_11_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_11_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_1_sm_11_t_8[IPFlushRepository::dnsFlushMap_f_1_sm_11_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_11_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_1_sm_11_t_9[IPFlushRepository::dnsFlushMap_f_1_sm_11_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_11_t_9_cnt++;
						break;
					}
					break;
			case 12:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_1_sm_12_t_0[IPFlushRepository::dnsFlushMap_f_1_sm_12_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_12_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_1_sm_12_t_1[IPFlushRepository::dnsFlushMap_f_1_sm_12_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_12_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_1_sm_12_t_2[IPFlushRepository::dnsFlushMap_f_1_sm_12_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_12_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_1_sm_12_t_3[IPFlushRepository::dnsFlushMap_f_1_sm_12_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_12_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_1_sm_12_t_4[IPFlushRepository::dnsFlushMap_f_1_sm_12_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_12_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_1_sm_12_t_5[IPFlushRepository::dnsFlushMap_f_1_sm_12_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_12_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_1_sm_12_t_6[IPFlushRepository::dnsFlushMap_f_1_sm_12_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_12_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_1_sm_12_t_7[IPFlushRepository::dnsFlushMap_f_1_sm_12_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_12_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_1_sm_12_t_8[IPFlushRepository::dnsFlushMap_f_1_sm_12_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_12_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_1_sm_12_t_9[IPFlushRepository::dnsFlushMap_f_1_sm_12_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_12_t_9_cnt++;
						break;
					}
					break;
			case 13:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_1_sm_13_t_0[IPFlushRepository::dnsFlushMap_f_1_sm_13_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_13_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_1_sm_13_t_1[IPFlushRepository::dnsFlushMap_f_1_sm_13_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_13_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_1_sm_13_t_2[IPFlushRepository::dnsFlushMap_f_1_sm_13_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_13_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_1_sm_13_t_3[IPFlushRepository::dnsFlushMap_f_1_sm_13_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_13_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_1_sm_13_t_4[IPFlushRepository::dnsFlushMap_f_1_sm_13_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_13_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_1_sm_13_t_5[IPFlushRepository::dnsFlushMap_f_1_sm_13_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_13_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_1_sm_13_t_6[IPFlushRepository::dnsFlushMap_f_1_sm_13_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_13_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_1_sm_13_t_7[IPFlushRepository::dnsFlushMap_f_1_sm_13_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_13_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_1_sm_13_t_8[IPFlushRepository::dnsFlushMap_f_1_sm_13_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_13_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_1_sm_13_t_9[IPFlushRepository::dnsFlushMap_f_1_sm_13_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_13_t_9_cnt++;
						break;
					}
					break;
			case 14:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_1_sm_14_t_0[IPFlushRepository::dnsFlushMap_f_1_sm_14_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_14_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_1_sm_14_t_1[IPFlushRepository::dnsFlushMap_f_1_sm_14_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_14_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_1_sm_14_t_2[IPFlushRepository::dnsFlushMap_f_1_sm_14_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_14_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_1_sm_14_t_3[IPFlushRepository::dnsFlushMap_f_1_sm_14_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_14_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_1_sm_14_t_4[IPFlushRepository::dnsFlushMap_f_1_sm_14_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_14_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_1_sm_14_t_5[IPFlushRepository::dnsFlushMap_f_1_sm_14_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_14_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_1_sm_14_t_6[IPFlushRepository::dnsFlushMap_f_1_sm_14_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_14_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_1_sm_14_t_7[IPFlushRepository::dnsFlushMap_f_1_sm_14_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_14_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_1_sm_14_t_8[IPFlushRepository::dnsFlushMap_f_1_sm_14_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_14_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_1_sm_14_t_9[IPFlushRepository::dnsFlushMap_f_1_sm_14_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_14_t_9_cnt++;
						break;
					}
					break;
			case 15:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_1_sm_15_t_0[IPFlushRepository::dnsFlushMap_f_1_sm_15_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_15_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_1_sm_15_t_1[IPFlushRepository::dnsFlushMap_f_1_sm_15_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_15_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_1_sm_15_t_2[IPFlushRepository::dnsFlushMap_f_1_sm_15_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_15_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_1_sm_15_t_3[IPFlushRepository::dnsFlushMap_f_1_sm_15_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_15_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_1_sm_15_t_4[IPFlushRepository::dnsFlushMap_f_1_sm_15_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_15_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_1_sm_15_t_5[IPFlushRepository::dnsFlushMap_f_1_sm_15_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_15_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_1_sm_15_t_6[IPFlushRepository::dnsFlushMap_f_1_sm_15_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_15_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_1_sm_15_t_7[IPFlushRepository::dnsFlushMap_f_1_sm_15_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_15_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_1_sm_15_t_8[IPFlushRepository::dnsFlushMap_f_1_sm_15_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_15_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_1_sm_15_t_9[IPFlushRepository::dnsFlushMap_f_1_sm_15_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_15_t_9_cnt++;
						break;
					}
					break;
			case 16:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_1_sm_16_t_0[IPFlushRepository::dnsFlushMap_f_1_sm_16_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_16_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_1_sm_16_t_1[IPFlushRepository::dnsFlushMap_f_1_sm_16_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_16_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_1_sm_16_t_2[IPFlushRepository::dnsFlushMap_f_1_sm_16_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_16_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_1_sm_16_t_3[IPFlushRepository::dnsFlushMap_f_1_sm_16_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_16_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_1_sm_16_t_4[IPFlushRepository::dnsFlushMap_f_1_sm_16_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_16_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_1_sm_16_t_5[IPFlushRepository::dnsFlushMap_f_1_sm_16_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_16_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_1_sm_16_t_6[IPFlushRepository::dnsFlushMap_f_1_sm_16_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_16_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_1_sm_16_t_7[IPFlushRepository::dnsFlushMap_f_1_sm_16_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_16_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_1_sm_16_t_8[IPFlushRepository::dnsFlushMap_f_1_sm_16_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_16_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_1_sm_16_t_9[IPFlushRepository::dnsFlushMap_f_1_sm_16_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_16_t_9_cnt++;
						break;
					}
					break;
			case 17:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_1_sm_17_t_0[IPFlushRepository::dnsFlushMap_f_1_sm_17_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_17_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_1_sm_17_t_1[IPFlushRepository::dnsFlushMap_f_1_sm_17_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_17_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_1_sm_17_t_2[IPFlushRepository::dnsFlushMap_f_1_sm_17_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_17_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_1_sm_17_t_3[IPFlushRepository::dnsFlushMap_f_1_sm_17_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_17_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_1_sm_17_t_4[IPFlushRepository::dnsFlushMap_f_1_sm_17_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_17_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_1_sm_17_t_5[IPFlushRepository::dnsFlushMap_f_1_sm_17_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_17_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_1_sm_17_t_6[IPFlushRepository::dnsFlushMap_f_1_sm_17_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_17_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_1_sm_17_t_7[IPFlushRepository::dnsFlushMap_f_1_sm_17_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_17_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_1_sm_17_t_8[IPFlushRepository::dnsFlushMap_f_1_sm_17_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_17_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_1_sm_17_t_9[IPFlushRepository::dnsFlushMap_f_1_sm_17_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_17_t_9_cnt++;
						break;
					}
					break;
			case 18:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_1_sm_18_t_0[IPFlushRepository::dnsFlushMap_f_1_sm_18_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_18_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_1_sm_18_t_1[IPFlushRepository::dnsFlushMap_f_1_sm_18_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_18_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_1_sm_18_t_2[IPFlushRepository::dnsFlushMap_f_1_sm_18_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_18_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_1_sm_18_t_3[IPFlushRepository::dnsFlushMap_f_1_sm_18_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_18_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_1_sm_18_t_4[IPFlushRepository::dnsFlushMap_f_1_sm_18_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_18_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_1_sm_18_t_5[IPFlushRepository::dnsFlushMap_f_1_sm_18_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_18_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_1_sm_18_t_6[IPFlushRepository::dnsFlushMap_f_1_sm_18_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_18_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_1_sm_18_t_7[IPFlushRepository::dnsFlushMap_f_1_sm_18_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_18_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_1_sm_18_t_8[IPFlushRepository::dnsFlushMap_f_1_sm_18_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_18_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_1_sm_18_t_9[IPFlushRepository::dnsFlushMap_f_1_sm_18_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_18_t_9_cnt++;
						break;
					}
					break;
			case 19:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_1_sm_19_t_0[IPFlushRepository::dnsFlushMap_f_1_sm_19_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_19_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_1_sm_19_t_1[IPFlushRepository::dnsFlushMap_f_1_sm_19_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_19_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_1_sm_19_t_2[IPFlushRepository::dnsFlushMap_f_1_sm_19_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_19_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_1_sm_19_t_3[IPFlushRepository::dnsFlushMap_f_1_sm_19_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_19_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_1_sm_19_t_4[IPFlushRepository::dnsFlushMap_f_1_sm_19_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_19_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_1_sm_19_t_5[IPFlushRepository::dnsFlushMap_f_1_sm_19_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_19_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_1_sm_19_t_6[IPFlushRepository::dnsFlushMap_f_1_sm_19_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_19_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_1_sm_19_t_7[IPFlushRepository::dnsFlushMap_f_1_sm_19_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_19_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_1_sm_19_t_8[IPFlushRepository::dnsFlushMap_f_1_sm_19_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_19_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_1_sm_19_t_9[IPFlushRepository::dnsFlushMap_f_1_sm_19_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_19_t_9_cnt++;
						break;
					}
					break;
			case 20:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_1_sm_20_t_0[IPFlushRepository::dnsFlushMap_f_1_sm_20_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_20_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_1_sm_20_t_1[IPFlushRepository::dnsFlushMap_f_1_sm_20_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_20_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_1_sm_20_t_2[IPFlushRepository::dnsFlushMap_f_1_sm_20_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_20_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_1_sm_20_t_3[IPFlushRepository::dnsFlushMap_f_1_sm_20_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_20_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_1_sm_20_t_4[IPFlushRepository::dnsFlushMap_f_1_sm_20_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_20_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_1_sm_20_t_5[IPFlushRepository::dnsFlushMap_f_1_sm_20_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_20_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_1_sm_20_t_6[IPFlushRepository::dnsFlushMap_f_1_sm_20_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_20_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_1_sm_20_t_7[IPFlushRepository::dnsFlushMap_f_1_sm_20_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_20_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_1_sm_20_t_8[IPFlushRepository::dnsFlushMap_f_1_sm_20_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_20_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_1_sm_20_t_9[IPFlushRepository::dnsFlushMap_f_1_sm_20_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_20_t_9_cnt++;
						break;
					}
					break;
			case 21:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_1_sm_21_t_0[IPFlushRepository::dnsFlushMap_f_1_sm_21_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_21_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_1_sm_21_t_1[IPFlushRepository::dnsFlushMap_f_1_sm_21_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_21_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_1_sm_21_t_2[IPFlushRepository::dnsFlushMap_f_1_sm_21_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_21_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_1_sm_21_t_3[IPFlushRepository::dnsFlushMap_f_1_sm_21_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_21_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_1_sm_21_t_4[IPFlushRepository::dnsFlushMap_f_1_sm_21_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_21_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_1_sm_21_t_5[IPFlushRepository::dnsFlushMap_f_1_sm_21_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_21_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_1_sm_21_t_6[IPFlushRepository::dnsFlushMap_f_1_sm_21_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_21_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_1_sm_21_t_7[IPFlushRepository::dnsFlushMap_f_1_sm_21_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_21_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_1_sm_21_t_8[IPFlushRepository::dnsFlushMap_f_1_sm_21_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_21_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_1_sm_21_t_9[IPFlushRepository::dnsFlushMap_f_1_sm_21_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_21_t_9_cnt++;
						break;
					}
					break;
			case 22:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_1_sm_22_t_0[IPFlushRepository::dnsFlushMap_f_1_sm_22_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_22_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_1_sm_22_t_1[IPFlushRepository::dnsFlushMap_f_1_sm_22_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_22_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_1_sm_22_t_2[IPFlushRepository::dnsFlushMap_f_1_sm_22_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_22_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_1_sm_22_t_3[IPFlushRepository::dnsFlushMap_f_1_sm_22_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_22_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_1_sm_22_t_4[IPFlushRepository::dnsFlushMap_f_1_sm_22_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_22_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_1_sm_22_t_5[IPFlushRepository::dnsFlushMap_f_1_sm_22_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_22_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_1_sm_22_t_6[IPFlushRepository::dnsFlushMap_f_1_sm_22_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_22_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_1_sm_22_t_7[IPFlushRepository::dnsFlushMap_f_1_sm_22_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_22_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_1_sm_22_t_8[IPFlushRepository::dnsFlushMap_f_1_sm_22_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_22_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_1_sm_22_t_9[IPFlushRepository::dnsFlushMap_f_1_sm_22_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_22_t_9_cnt++;
						break;
					}
					break;
			case 23:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_1_sm_23_t_0[IPFlushRepository::dnsFlushMap_f_1_sm_23_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_23_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_1_sm_23_t_1[IPFlushRepository::dnsFlushMap_f_1_sm_23_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_23_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_1_sm_23_t_2[IPFlushRepository::dnsFlushMap_f_1_sm_23_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_23_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_1_sm_23_t_3[IPFlushRepository::dnsFlushMap_f_1_sm_23_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_23_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_1_sm_23_t_4[IPFlushRepository::dnsFlushMap_f_1_sm_23_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_23_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_1_sm_23_t_5[IPFlushRepository::dnsFlushMap_f_1_sm_23_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_23_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_1_sm_23_t_6[IPFlushRepository::dnsFlushMap_f_1_sm_23_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_23_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_1_sm_23_t_7[IPFlushRepository::dnsFlushMap_f_1_sm_23_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_23_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_1_sm_23_t_8[IPFlushRepository::dnsFlushMap_f_1_sm_23_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_23_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_1_sm_23_t_9[IPFlushRepository::dnsFlushMap_f_1_sm_23_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_23_t_9_cnt++;
						break;
					}
					break;
			case 24:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_1_sm_24_t_0[IPFlushRepository::dnsFlushMap_f_1_sm_24_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_24_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_1_sm_24_t_1[IPFlushRepository::dnsFlushMap_f_1_sm_24_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_24_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_1_sm_24_t_2[IPFlushRepository::dnsFlushMap_f_1_sm_24_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_24_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_1_sm_24_t_3[IPFlushRepository::dnsFlushMap_f_1_sm_24_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_24_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_1_sm_24_t_4[IPFlushRepository::dnsFlushMap_f_1_sm_24_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_24_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_1_sm_24_t_5[IPFlushRepository::dnsFlushMap_f_1_sm_24_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_24_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_1_sm_24_t_6[IPFlushRepository::dnsFlushMap_f_1_sm_24_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_24_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_1_sm_24_t_7[IPFlushRepository::dnsFlushMap_f_1_sm_24_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_24_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_1_sm_24_t_8[IPFlushRepository::dnsFlushMap_f_1_sm_24_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_24_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_1_sm_24_t_9[IPFlushRepository::dnsFlushMap_f_1_sm_24_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_24_t_9_cnt++;
						break;
					}
					break;
			case 25:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_1_sm_25_t_0[IPFlushRepository::dnsFlushMap_f_1_sm_25_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_25_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_1_sm_25_t_1[IPFlushRepository::dnsFlushMap_f_1_sm_25_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_25_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_1_sm_25_t_2[IPFlushRepository::dnsFlushMap_f_1_sm_25_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_25_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_1_sm_25_t_3[IPFlushRepository::dnsFlushMap_f_1_sm_25_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_25_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_1_sm_25_t_4[IPFlushRepository::dnsFlushMap_f_1_sm_25_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_25_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_1_sm_25_t_5[IPFlushRepository::dnsFlushMap_f_1_sm_25_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_25_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_1_sm_25_t_6[IPFlushRepository::dnsFlushMap_f_1_sm_25_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_25_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_1_sm_25_t_7[IPFlushRepository::dnsFlushMap_f_1_sm_25_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_25_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_1_sm_25_t_8[IPFlushRepository::dnsFlushMap_f_1_sm_25_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_25_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_1_sm_25_t_9[IPFlushRepository::dnsFlushMap_f_1_sm_25_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_25_t_9_cnt++;
						break;
					}
					break;
			case 26:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_1_sm_26_t_0[IPFlushRepository::dnsFlushMap_f_1_sm_26_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_26_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_1_sm_26_t_1[IPFlushRepository::dnsFlushMap_f_1_sm_26_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_26_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_1_sm_26_t_2[IPFlushRepository::dnsFlushMap_f_1_sm_26_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_26_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_1_sm_26_t_3[IPFlushRepository::dnsFlushMap_f_1_sm_26_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_26_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_1_sm_26_t_4[IPFlushRepository::dnsFlushMap_f_1_sm_26_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_26_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_1_sm_26_t_5[IPFlushRepository::dnsFlushMap_f_1_sm_26_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_26_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_1_sm_26_t_6[IPFlushRepository::dnsFlushMap_f_1_sm_26_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_26_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_1_sm_26_t_7[IPFlushRepository::dnsFlushMap_f_1_sm_26_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_26_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_1_sm_26_t_8[IPFlushRepository::dnsFlushMap_f_1_sm_26_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_26_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_1_sm_26_t_9[IPFlushRepository::dnsFlushMap_f_1_sm_26_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_26_t_9_cnt++;
						break;
					}
					break;
			case 27:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_1_sm_27_t_0[IPFlushRepository::dnsFlushMap_f_1_sm_27_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_27_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_1_sm_27_t_1[IPFlushRepository::dnsFlushMap_f_1_sm_27_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_27_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_1_sm_27_t_2[IPFlushRepository::dnsFlushMap_f_1_sm_27_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_27_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_1_sm_27_t_3[IPFlushRepository::dnsFlushMap_f_1_sm_27_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_27_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_1_sm_27_t_4[IPFlushRepository::dnsFlushMap_f_1_sm_27_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_27_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_1_sm_27_t_5[IPFlushRepository::dnsFlushMap_f_1_sm_27_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_27_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_1_sm_27_t_6[IPFlushRepository::dnsFlushMap_f_1_sm_27_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_27_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_1_sm_27_t_7[IPFlushRepository::dnsFlushMap_f_1_sm_27_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_27_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_1_sm_27_t_8[IPFlushRepository::dnsFlushMap_f_1_sm_27_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_27_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_1_sm_27_t_9[IPFlushRepository::dnsFlushMap_f_1_sm_27_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_27_t_9_cnt++;
						break;
					}
					break;
			case 28:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_1_sm_28_t_0[IPFlushRepository::dnsFlushMap_f_1_sm_28_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_28_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_1_sm_28_t_1[IPFlushRepository::dnsFlushMap_f_1_sm_28_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_28_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_1_sm_28_t_2[IPFlushRepository::dnsFlushMap_f_1_sm_28_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_28_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_1_sm_28_t_3[IPFlushRepository::dnsFlushMap_f_1_sm_28_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_28_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_1_sm_28_t_4[IPFlushRepository::dnsFlushMap_f_1_sm_28_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_28_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_1_sm_28_t_5[IPFlushRepository::dnsFlushMap_f_1_sm_28_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_28_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_1_sm_28_t_6[IPFlushRepository::dnsFlushMap_f_1_sm_28_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_28_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_1_sm_28_t_7[IPFlushRepository::dnsFlushMap_f_1_sm_28_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_28_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_1_sm_28_t_8[IPFlushRepository::dnsFlushMap_f_1_sm_28_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_28_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_1_sm_28_t_9[IPFlushRepository::dnsFlushMap_f_1_sm_28_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_28_t_9_cnt++;
						break;
					}
					break;
			case 29:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_1_sm_29_t_0[IPFlushRepository::dnsFlushMap_f_1_sm_29_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_29_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_1_sm_29_t_1[IPFlushRepository::dnsFlushMap_f_1_sm_29_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_29_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_1_sm_29_t_2[IPFlushRepository::dnsFlushMap_f_1_sm_29_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_29_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_1_sm_29_t_3[IPFlushRepository::dnsFlushMap_f_1_sm_29_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_29_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_1_sm_29_t_4[IPFlushRepository::dnsFlushMap_f_1_sm_29_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_29_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_1_sm_29_t_5[IPFlushRepository::dnsFlushMap_f_1_sm_29_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_29_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_1_sm_29_t_6[IPFlushRepository::dnsFlushMap_f_1_sm_29_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_29_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_1_sm_29_t_7[IPFlushRepository::dnsFlushMap_f_1_sm_29_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_29_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_1_sm_29_t_8[IPFlushRepository::dnsFlushMap_f_1_sm_29_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_29_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_1_sm_29_t_9[IPFlushRepository::dnsFlushMap_f_1_sm_29_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_1_sm_29_t_9_cnt++;
						break;
					}
					break;

	}
}

VOID S1UInterface::storeDnsSession_f_2(int index, dnsSession *pDnsSession)
{
	switch(instanceId)
	{
			case 0:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_2_sm_0_t_0[IPFlushRepository::dnsFlushMap_f_2_sm_0_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_0_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_2_sm_0_t_1[IPFlushRepository::dnsFlushMap_f_2_sm_0_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_0_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_2_sm_0_t_2[IPFlushRepository::dnsFlushMap_f_2_sm_0_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_0_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_2_sm_0_t_3[IPFlushRepository::dnsFlushMap_f_2_sm_0_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_0_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_2_sm_0_t_4[IPFlushRepository::dnsFlushMap_f_2_sm_0_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_0_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_2_sm_0_t_5[IPFlushRepository::dnsFlushMap_f_2_sm_0_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_0_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_2_sm_0_t_6[IPFlushRepository::dnsFlushMap_f_2_sm_0_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_0_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_2_sm_0_t_7[IPFlushRepository::dnsFlushMap_f_2_sm_0_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_0_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_2_sm_0_t_8[IPFlushRepository::dnsFlushMap_f_2_sm_0_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_0_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_2_sm_0_t_9[IPFlushRepository::dnsFlushMap_f_2_sm_0_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_0_t_9_cnt++;
						break;
					}
					break;

			case 1:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_2_sm_1_t_0[IPFlushRepository::dnsFlushMap_f_2_sm_1_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_1_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_2_sm_1_t_1[IPFlushRepository::dnsFlushMap_f_2_sm_1_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_1_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_2_sm_1_t_2[IPFlushRepository::dnsFlushMap_f_2_sm_1_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_1_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_2_sm_1_t_3[IPFlushRepository::dnsFlushMap_f_2_sm_1_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_1_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_2_sm_1_t_4[IPFlushRepository::dnsFlushMap_f_2_sm_1_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_1_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_2_sm_1_t_5[IPFlushRepository::dnsFlushMap_f_2_sm_1_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_1_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_2_sm_1_t_6[IPFlushRepository::dnsFlushMap_f_2_sm_1_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_1_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_2_sm_1_t_7[IPFlushRepository::dnsFlushMap_f_2_sm_1_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_1_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_2_sm_1_t_8[IPFlushRepository::dnsFlushMap_f_2_sm_1_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_1_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_2_sm_1_t_9[IPFlushRepository::dnsFlushMap_f_2_sm_1_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_1_t_9_cnt++;
						break;
					}
					break;
			case 2:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_2_sm_2_t_0[IPFlushRepository::dnsFlushMap_f_2_sm_2_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_2_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_2_sm_2_t_1[IPFlushRepository::dnsFlushMap_f_2_sm_2_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_2_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_2_sm_2_t_2[IPFlushRepository::dnsFlushMap_f_2_sm_2_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_2_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_2_sm_2_t_3[IPFlushRepository::dnsFlushMap_f_2_sm_2_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_2_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_2_sm_2_t_4[IPFlushRepository::dnsFlushMap_f_2_sm_2_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_2_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_2_sm_2_t_5[IPFlushRepository::dnsFlushMap_f_2_sm_2_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_2_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_2_sm_2_t_6[IPFlushRepository::dnsFlushMap_f_2_sm_2_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_2_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_2_sm_2_t_7[IPFlushRepository::dnsFlushMap_f_2_sm_2_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_2_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_2_sm_2_t_8[IPFlushRepository::dnsFlushMap_f_2_sm_2_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_2_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_2_sm_2_t_9[IPFlushRepository::dnsFlushMap_f_2_sm_2_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_2_t_9_cnt++;
						break;
					}
					break;

			case 3:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_2_sm_3_t_0[IPFlushRepository::dnsFlushMap_f_2_sm_3_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_3_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_2_sm_3_t_1[IPFlushRepository::dnsFlushMap_f_2_sm_3_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_3_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_2_sm_3_t_2[IPFlushRepository::dnsFlushMap_f_2_sm_3_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_3_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_2_sm_3_t_3[IPFlushRepository::dnsFlushMap_f_2_sm_3_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_3_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_2_sm_3_t_4[IPFlushRepository::dnsFlushMap_f_2_sm_3_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_3_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_2_sm_3_t_5[IPFlushRepository::dnsFlushMap_f_2_sm_3_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_3_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_2_sm_3_t_6[IPFlushRepository::dnsFlushMap_f_2_sm_3_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_3_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_2_sm_3_t_7[IPFlushRepository::dnsFlushMap_f_2_sm_3_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_3_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_2_sm_3_t_8[IPFlushRepository::dnsFlushMap_f_2_sm_3_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_3_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_2_sm_3_t_9[IPFlushRepository::dnsFlushMap_f_2_sm_3_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_3_t_9_cnt++;
						break;
					}
					break;

			case 4:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_2_sm_4_t_0[IPFlushRepository::dnsFlushMap_f_2_sm_4_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_4_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_2_sm_4_t_1[IPFlushRepository::dnsFlushMap_f_2_sm_4_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_4_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_2_sm_4_t_2[IPFlushRepository::dnsFlushMap_f_2_sm_4_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_4_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_2_sm_4_t_3[IPFlushRepository::dnsFlushMap_f_2_sm_4_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_4_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_2_sm_4_t_4[IPFlushRepository::dnsFlushMap_f_2_sm_4_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_4_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_2_sm_4_t_5[IPFlushRepository::dnsFlushMap_f_2_sm_4_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_4_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_2_sm_4_t_6[IPFlushRepository::dnsFlushMap_f_2_sm_4_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_4_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_2_sm_4_t_7[IPFlushRepository::dnsFlushMap_f_2_sm_4_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_4_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_2_sm_4_t_8[IPFlushRepository::dnsFlushMap_f_2_sm_4_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_4_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_2_sm_4_t_9[IPFlushRepository::dnsFlushMap_f_2_sm_4_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_4_t_9_cnt++;
						break;
					}
					break;

			case 5:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_2_sm_5_t_0[IPFlushRepository::dnsFlushMap_f_2_sm_5_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_5_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_2_sm_5_t_1[IPFlushRepository::dnsFlushMap_f_2_sm_5_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_5_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_2_sm_5_t_2[IPFlushRepository::dnsFlushMap_f_2_sm_5_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_5_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_2_sm_5_t_3[IPFlushRepository::dnsFlushMap_f_2_sm_5_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_5_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_2_sm_5_t_4[IPFlushRepository::dnsFlushMap_f_2_sm_5_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_5_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_2_sm_5_t_5[IPFlushRepository::dnsFlushMap_f_2_sm_5_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_5_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_2_sm_5_t_6[IPFlushRepository::dnsFlushMap_f_2_sm_5_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_5_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_2_sm_5_t_7[IPFlushRepository::dnsFlushMap_f_2_sm_5_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_5_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_2_sm_5_t_8[IPFlushRepository::dnsFlushMap_f_2_sm_5_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_5_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_2_sm_5_t_9[IPFlushRepository::dnsFlushMap_f_2_sm_5_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_5_t_9_cnt++;
						break;
					}
					break;

			case 6:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_2_sm_6_t_0[IPFlushRepository::dnsFlushMap_f_2_sm_6_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_6_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_2_sm_6_t_1[IPFlushRepository::dnsFlushMap_f_2_sm_6_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_6_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_2_sm_6_t_2[IPFlushRepository::dnsFlushMap_f_2_sm_6_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_6_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_2_sm_6_t_3[IPFlushRepository::dnsFlushMap_f_2_sm_6_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_6_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_2_sm_6_t_4[IPFlushRepository::dnsFlushMap_f_2_sm_6_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_6_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_2_sm_6_t_5[IPFlushRepository::dnsFlushMap_f_2_sm_6_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_6_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_2_sm_6_t_6[IPFlushRepository::dnsFlushMap_f_2_sm_6_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_6_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_2_sm_6_t_7[IPFlushRepository::dnsFlushMap_f_2_sm_6_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_6_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_2_sm_6_t_8[IPFlushRepository::dnsFlushMap_f_2_sm_6_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_6_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_2_sm_6_t_9[IPFlushRepository::dnsFlushMap_f_2_sm_6_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_6_t_9_cnt++;
						break;
					}
					break;
			case 7:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_2_sm_7_t_0[IPFlushRepository::dnsFlushMap_f_2_sm_7_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_7_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_2_sm_7_t_1[IPFlushRepository::dnsFlushMap_f_2_sm_7_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_7_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_2_sm_7_t_2[IPFlushRepository::dnsFlushMap_f_2_sm_7_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_7_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_2_sm_7_t_3[IPFlushRepository::dnsFlushMap_f_2_sm_7_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_7_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_2_sm_7_t_4[IPFlushRepository::dnsFlushMap_f_2_sm_7_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_7_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_2_sm_7_t_5[IPFlushRepository::dnsFlushMap_f_2_sm_7_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_7_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_2_sm_7_t_6[IPFlushRepository::dnsFlushMap_f_2_sm_7_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_7_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_2_sm_7_t_7[IPFlushRepository::dnsFlushMap_f_2_sm_7_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_7_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_2_sm_7_t_8[IPFlushRepository::dnsFlushMap_f_2_sm_7_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_7_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_2_sm_7_t_9[IPFlushRepository::dnsFlushMap_f_2_sm_7_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_7_t_9_cnt++;
						break;
					}
					break;
			case 8:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_2_sm_8_t_0[IPFlushRepository::dnsFlushMap_f_2_sm_8_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_8_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_2_sm_8_t_1[IPFlushRepository::dnsFlushMap_f_2_sm_8_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_8_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_2_sm_8_t_2[IPFlushRepository::dnsFlushMap_f_2_sm_8_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_8_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_2_sm_8_t_3[IPFlushRepository::dnsFlushMap_f_2_sm_8_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_8_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_2_sm_8_t_4[IPFlushRepository::dnsFlushMap_f_2_sm_8_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_8_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_2_sm_8_t_5[IPFlushRepository::dnsFlushMap_f_2_sm_8_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_8_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_2_sm_8_t_6[IPFlushRepository::dnsFlushMap_f_2_sm_8_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_8_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_2_sm_8_t_7[IPFlushRepository::dnsFlushMap_f_2_sm_8_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_8_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_2_sm_8_t_8[IPFlushRepository::dnsFlushMap_f_2_sm_8_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_8_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_2_sm_8_t_9[IPFlushRepository::dnsFlushMap_f_2_sm_8_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_8_t_9_cnt++;
						break;
					}
					break;
			case 9:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_2_sm_9_t_0[IPFlushRepository::dnsFlushMap_f_2_sm_9_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_9_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_2_sm_9_t_1[IPFlushRepository::dnsFlushMap_f_2_sm_9_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_9_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_2_sm_9_t_2[IPFlushRepository::dnsFlushMap_f_2_sm_9_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_9_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_2_sm_9_t_3[IPFlushRepository::dnsFlushMap_f_2_sm_9_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_9_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_2_sm_9_t_4[IPFlushRepository::dnsFlushMap_f_2_sm_9_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_9_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_2_sm_9_t_5[IPFlushRepository::dnsFlushMap_f_2_sm_9_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_9_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_2_sm_9_t_6[IPFlushRepository::dnsFlushMap_f_2_sm_9_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_9_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_2_sm_9_t_7[IPFlushRepository::dnsFlushMap_f_2_sm_9_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_9_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_2_sm_9_t_8[IPFlushRepository::dnsFlushMap_f_2_sm_9_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_9_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_2_sm_9_t_9[IPFlushRepository::dnsFlushMap_f_2_sm_9_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_9_t_9_cnt++;
						break;
					}
					break;
			case 10:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_2_sm_10_t_0[IPFlushRepository::dnsFlushMap_f_2_sm_10_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_10_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_2_sm_10_t_1[IPFlushRepository::dnsFlushMap_f_2_sm_10_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_10_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_2_sm_10_t_2[IPFlushRepository::dnsFlushMap_f_2_sm_10_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_10_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_2_sm_10_t_3[IPFlushRepository::dnsFlushMap_f_2_sm_10_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_10_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_2_sm_10_t_4[IPFlushRepository::dnsFlushMap_f_2_sm_10_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_10_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_2_sm_10_t_5[IPFlushRepository::dnsFlushMap_f_2_sm_10_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_10_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_2_sm_10_t_6[IPFlushRepository::dnsFlushMap_f_2_sm_10_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_10_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_2_sm_10_t_7[IPFlushRepository::dnsFlushMap_f_2_sm_10_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_10_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_2_sm_10_t_8[IPFlushRepository::dnsFlushMap_f_2_sm_10_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_10_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_2_sm_10_t_9[IPFlushRepository::dnsFlushMap_f_2_sm_10_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_10_t_9_cnt++;
						break;
					}
					break;
			case 11:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_2_sm_11_t_0[IPFlushRepository::dnsFlushMap_f_2_sm_11_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_11_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_2_sm_11_t_1[IPFlushRepository::dnsFlushMap_f_2_sm_11_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_11_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_2_sm_11_t_2[IPFlushRepository::dnsFlushMap_f_2_sm_11_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_11_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_2_sm_11_t_3[IPFlushRepository::dnsFlushMap_f_2_sm_11_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_11_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_2_sm_11_t_4[IPFlushRepository::dnsFlushMap_f_2_sm_11_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_11_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_2_sm_11_t_5[IPFlushRepository::dnsFlushMap_f_2_sm_11_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_11_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_2_sm_11_t_6[IPFlushRepository::dnsFlushMap_f_2_sm_11_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_11_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_2_sm_11_t_7[IPFlushRepository::dnsFlushMap_f_2_sm_11_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_11_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_2_sm_11_t_8[IPFlushRepository::dnsFlushMap_f_2_sm_11_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_11_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_2_sm_11_t_9[IPFlushRepository::dnsFlushMap_f_2_sm_11_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_11_t_9_cnt++;
						break;
					}
					break;
			case 12:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_2_sm_12_t_0[IPFlushRepository::dnsFlushMap_f_2_sm_12_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_12_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_2_sm_12_t_1[IPFlushRepository::dnsFlushMap_f_2_sm_12_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_12_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_2_sm_12_t_2[IPFlushRepository::dnsFlushMap_f_2_sm_12_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_12_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_2_sm_12_t_3[IPFlushRepository::dnsFlushMap_f_2_sm_12_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_12_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_2_sm_12_t_4[IPFlushRepository::dnsFlushMap_f_2_sm_12_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_12_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_2_sm_12_t_5[IPFlushRepository::dnsFlushMap_f_2_sm_12_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_12_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_2_sm_12_t_6[IPFlushRepository::dnsFlushMap_f_2_sm_12_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_12_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_2_sm_12_t_7[IPFlushRepository::dnsFlushMap_f_2_sm_12_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_12_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_2_sm_12_t_8[IPFlushRepository::dnsFlushMap_f_2_sm_12_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_12_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_2_sm_12_t_9[IPFlushRepository::dnsFlushMap_f_2_sm_12_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_12_t_9_cnt++;
						break;
					}
					break;
			case 13:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_2_sm_13_t_0[IPFlushRepository::dnsFlushMap_f_2_sm_13_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_13_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_2_sm_13_t_1[IPFlushRepository::dnsFlushMap_f_2_sm_13_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_13_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_2_sm_13_t_2[IPFlushRepository::dnsFlushMap_f_2_sm_13_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_13_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_2_sm_13_t_3[IPFlushRepository::dnsFlushMap_f_2_sm_13_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_13_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_2_sm_13_t_4[IPFlushRepository::dnsFlushMap_f_2_sm_13_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_13_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_2_sm_13_t_5[IPFlushRepository::dnsFlushMap_f_2_sm_13_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_13_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_2_sm_13_t_6[IPFlushRepository::dnsFlushMap_f_2_sm_13_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_13_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_2_sm_13_t_7[IPFlushRepository::dnsFlushMap_f_2_sm_13_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_13_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_2_sm_13_t_8[IPFlushRepository::dnsFlushMap_f_2_sm_13_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_13_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_2_sm_13_t_9[IPFlushRepository::dnsFlushMap_f_2_sm_13_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_13_t_9_cnt++;
						break;
					}
					break;
			case 14:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_2_sm_14_t_0[IPFlushRepository::dnsFlushMap_f_2_sm_14_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_14_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_2_sm_14_t_1[IPFlushRepository::dnsFlushMap_f_2_sm_14_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_14_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_2_sm_14_t_2[IPFlushRepository::dnsFlushMap_f_2_sm_14_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_14_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_2_sm_14_t_3[IPFlushRepository::dnsFlushMap_f_2_sm_14_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_14_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_2_sm_14_t_4[IPFlushRepository::dnsFlushMap_f_2_sm_14_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_14_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_2_sm_14_t_5[IPFlushRepository::dnsFlushMap_f_2_sm_14_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_14_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_2_sm_14_t_6[IPFlushRepository::dnsFlushMap_f_2_sm_14_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_14_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_2_sm_14_t_7[IPFlushRepository::dnsFlushMap_f_2_sm_14_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_14_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_2_sm_14_t_8[IPFlushRepository::dnsFlushMap_f_2_sm_14_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_14_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_2_sm_14_t_9[IPFlushRepository::dnsFlushMap_f_2_sm_14_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_14_t_9_cnt++;
						break;
					}
					break;
			case 15:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_2_sm_15_t_0[IPFlushRepository::dnsFlushMap_f_2_sm_15_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_15_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_2_sm_15_t_1[IPFlushRepository::dnsFlushMap_f_2_sm_15_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_15_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_2_sm_15_t_2[IPFlushRepository::dnsFlushMap_f_2_sm_15_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_15_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_2_sm_15_t_3[IPFlushRepository::dnsFlushMap_f_2_sm_15_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_15_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_2_sm_15_t_4[IPFlushRepository::dnsFlushMap_f_2_sm_15_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_15_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_2_sm_15_t_5[IPFlushRepository::dnsFlushMap_f_2_sm_15_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_15_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_2_sm_15_t_6[IPFlushRepository::dnsFlushMap_f_2_sm_15_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_15_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_2_sm_15_t_7[IPFlushRepository::dnsFlushMap_f_2_sm_15_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_15_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_2_sm_15_t_8[IPFlushRepository::dnsFlushMap_f_2_sm_15_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_15_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_2_sm_15_t_9[IPFlushRepository::dnsFlushMap_f_2_sm_15_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_15_t_9_cnt++;
						break;
					}
					break;
			case 16:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_2_sm_16_t_0[IPFlushRepository::dnsFlushMap_f_2_sm_16_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_16_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_2_sm_16_t_1[IPFlushRepository::dnsFlushMap_f_2_sm_16_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_16_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_2_sm_16_t_2[IPFlushRepository::dnsFlushMap_f_2_sm_16_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_16_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_2_sm_16_t_3[IPFlushRepository::dnsFlushMap_f_2_sm_16_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_16_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_2_sm_16_t_4[IPFlushRepository::dnsFlushMap_f_2_sm_16_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_16_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_2_sm_16_t_5[IPFlushRepository::dnsFlushMap_f_2_sm_16_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_16_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_2_sm_16_t_6[IPFlushRepository::dnsFlushMap_f_2_sm_16_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_16_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_2_sm_16_t_7[IPFlushRepository::dnsFlushMap_f_2_sm_16_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_16_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_2_sm_16_t_8[IPFlushRepository::dnsFlushMap_f_2_sm_16_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_16_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_2_sm_16_t_9[IPFlushRepository::dnsFlushMap_f_2_sm_16_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_16_t_9_cnt++;
						break;
					}
					break;
			case 17:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_2_sm_17_t_0[IPFlushRepository::dnsFlushMap_f_2_sm_17_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_17_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_2_sm_17_t_1[IPFlushRepository::dnsFlushMap_f_2_sm_17_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_17_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_2_sm_17_t_2[IPFlushRepository::dnsFlushMap_f_2_sm_17_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_17_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_2_sm_17_t_3[IPFlushRepository::dnsFlushMap_f_2_sm_17_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_17_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_2_sm_17_t_4[IPFlushRepository::dnsFlushMap_f_2_sm_17_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_17_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_2_sm_17_t_5[IPFlushRepository::dnsFlushMap_f_2_sm_17_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_17_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_2_sm_17_t_6[IPFlushRepository::dnsFlushMap_f_2_sm_17_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_17_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_2_sm_17_t_7[IPFlushRepository::dnsFlushMap_f_2_sm_17_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_17_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_2_sm_17_t_8[IPFlushRepository::dnsFlushMap_f_2_sm_17_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_17_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_2_sm_17_t_9[IPFlushRepository::dnsFlushMap_f_2_sm_17_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_17_t_9_cnt++;
						break;
					}
					break;
			case 18:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_2_sm_18_t_0[IPFlushRepository::dnsFlushMap_f_2_sm_18_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_18_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_2_sm_18_t_1[IPFlushRepository::dnsFlushMap_f_2_sm_18_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_18_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_2_sm_18_t_2[IPFlushRepository::dnsFlushMap_f_2_sm_18_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_18_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_2_sm_18_t_3[IPFlushRepository::dnsFlushMap_f_2_sm_18_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_18_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_2_sm_18_t_4[IPFlushRepository::dnsFlushMap_f_2_sm_18_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_18_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_2_sm_18_t_5[IPFlushRepository::dnsFlushMap_f_2_sm_18_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_18_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_2_sm_18_t_6[IPFlushRepository::dnsFlushMap_f_2_sm_18_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_18_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_2_sm_18_t_7[IPFlushRepository::dnsFlushMap_f_2_sm_18_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_18_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_2_sm_18_t_8[IPFlushRepository::dnsFlushMap_f_2_sm_18_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_18_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_2_sm_18_t_9[IPFlushRepository::dnsFlushMap_f_2_sm_18_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_18_t_9_cnt++;
						break;
					}
					break;
			case 19:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_2_sm_19_t_0[IPFlushRepository::dnsFlushMap_f_2_sm_19_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_19_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_2_sm_19_t_1[IPFlushRepository::dnsFlushMap_f_2_sm_19_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_19_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_2_sm_19_t_2[IPFlushRepository::dnsFlushMap_f_2_sm_19_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_19_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_2_sm_19_t_3[IPFlushRepository::dnsFlushMap_f_2_sm_19_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_19_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_2_sm_19_t_4[IPFlushRepository::dnsFlushMap_f_2_sm_19_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_19_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_2_sm_19_t_5[IPFlushRepository::dnsFlushMap_f_2_sm_19_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_19_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_2_sm_19_t_6[IPFlushRepository::dnsFlushMap_f_2_sm_19_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_19_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_2_sm_19_t_7[IPFlushRepository::dnsFlushMap_f_2_sm_19_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_19_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_2_sm_19_t_8[IPFlushRepository::dnsFlushMap_f_2_sm_19_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_19_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_2_sm_19_t_9[IPFlushRepository::dnsFlushMap_f_2_sm_19_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_19_t_9_cnt++;
						break;
					}
					break;
			case 20:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_2_sm_20_t_0[IPFlushRepository::dnsFlushMap_f_2_sm_20_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_20_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_2_sm_20_t_1[IPFlushRepository::dnsFlushMap_f_2_sm_20_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_20_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_2_sm_20_t_2[IPFlushRepository::dnsFlushMap_f_2_sm_20_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_20_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_2_sm_20_t_3[IPFlushRepository::dnsFlushMap_f_2_sm_20_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_20_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_2_sm_20_t_4[IPFlushRepository::dnsFlushMap_f_2_sm_20_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_20_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_2_sm_20_t_5[IPFlushRepository::dnsFlushMap_f_2_sm_20_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_20_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_2_sm_20_t_6[IPFlushRepository::dnsFlushMap_f_2_sm_20_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_20_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_2_sm_20_t_7[IPFlushRepository::dnsFlushMap_f_2_sm_20_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_20_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_2_sm_20_t_8[IPFlushRepository::dnsFlushMap_f_2_sm_20_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_20_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_2_sm_20_t_9[IPFlushRepository::dnsFlushMap_f_2_sm_20_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_20_t_9_cnt++;
						break;
					}
					break;
			case 21:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_2_sm_21_t_0[IPFlushRepository::dnsFlushMap_f_2_sm_21_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_21_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_2_sm_21_t_1[IPFlushRepository::dnsFlushMap_f_2_sm_21_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_21_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_2_sm_21_t_2[IPFlushRepository::dnsFlushMap_f_2_sm_21_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_21_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_2_sm_21_t_3[IPFlushRepository::dnsFlushMap_f_2_sm_21_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_21_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_2_sm_21_t_4[IPFlushRepository::dnsFlushMap_f_2_sm_21_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_21_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_2_sm_21_t_5[IPFlushRepository::dnsFlushMap_f_2_sm_21_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_21_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_2_sm_21_t_6[IPFlushRepository::dnsFlushMap_f_2_sm_21_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_21_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_2_sm_21_t_7[IPFlushRepository::dnsFlushMap_f_2_sm_21_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_21_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_2_sm_21_t_8[IPFlushRepository::dnsFlushMap_f_2_sm_21_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_21_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_2_sm_21_t_9[IPFlushRepository::dnsFlushMap_f_2_sm_21_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_21_t_9_cnt++;
						break;
					}
					break;
			case 22:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_2_sm_22_t_0[IPFlushRepository::dnsFlushMap_f_2_sm_22_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_22_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_2_sm_22_t_1[IPFlushRepository::dnsFlushMap_f_2_sm_22_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_22_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_2_sm_22_t_2[IPFlushRepository::dnsFlushMap_f_2_sm_22_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_22_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_2_sm_22_t_3[IPFlushRepository::dnsFlushMap_f_2_sm_22_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_22_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_2_sm_22_t_4[IPFlushRepository::dnsFlushMap_f_2_sm_22_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_22_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_2_sm_22_t_5[IPFlushRepository::dnsFlushMap_f_2_sm_22_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_22_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_2_sm_22_t_6[IPFlushRepository::dnsFlushMap_f_2_sm_22_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_22_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_2_sm_22_t_7[IPFlushRepository::dnsFlushMap_f_2_sm_22_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_22_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_2_sm_22_t_8[IPFlushRepository::dnsFlushMap_f_2_sm_22_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_22_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_2_sm_22_t_9[IPFlushRepository::dnsFlushMap_f_2_sm_22_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_22_t_9_cnt++;
						break;
					}
					break;
			case 23:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_2_sm_23_t_0[IPFlushRepository::dnsFlushMap_f_2_sm_23_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_23_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_2_sm_23_t_1[IPFlushRepository::dnsFlushMap_f_2_sm_23_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_23_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_2_sm_23_t_2[IPFlushRepository::dnsFlushMap_f_2_sm_23_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_23_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_2_sm_23_t_3[IPFlushRepository::dnsFlushMap_f_2_sm_23_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_23_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_2_sm_23_t_4[IPFlushRepository::dnsFlushMap_f_2_sm_23_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_23_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_2_sm_23_t_5[IPFlushRepository::dnsFlushMap_f_2_sm_23_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_23_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_2_sm_23_t_6[IPFlushRepository::dnsFlushMap_f_2_sm_23_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_23_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_2_sm_23_t_7[IPFlushRepository::dnsFlushMap_f_2_sm_23_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_23_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_2_sm_23_t_8[IPFlushRepository::dnsFlushMap_f_2_sm_23_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_23_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_2_sm_23_t_9[IPFlushRepository::dnsFlushMap_f_2_sm_23_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_23_t_9_cnt++;
						break;
					}
					break;
			case 24:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_2_sm_24_t_0[IPFlushRepository::dnsFlushMap_f_2_sm_24_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_24_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_2_sm_24_t_1[IPFlushRepository::dnsFlushMap_f_2_sm_24_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_24_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_2_sm_24_t_2[IPFlushRepository::dnsFlushMap_f_2_sm_24_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_24_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_2_sm_24_t_3[IPFlushRepository::dnsFlushMap_f_2_sm_24_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_24_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_2_sm_24_t_4[IPFlushRepository::dnsFlushMap_f_2_sm_24_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_24_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_2_sm_24_t_5[IPFlushRepository::dnsFlushMap_f_2_sm_24_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_24_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_2_sm_24_t_6[IPFlushRepository::dnsFlushMap_f_2_sm_24_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_24_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_2_sm_24_t_7[IPFlushRepository::dnsFlushMap_f_2_sm_24_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_24_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_2_sm_24_t_8[IPFlushRepository::dnsFlushMap_f_2_sm_24_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_24_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_2_sm_24_t_9[IPFlushRepository::dnsFlushMap_f_2_sm_24_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_24_t_9_cnt++;
						break;
					}
					break;
			case 25:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_2_sm_25_t_0[IPFlushRepository::dnsFlushMap_f_2_sm_25_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_25_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_2_sm_25_t_1[IPFlushRepository::dnsFlushMap_f_2_sm_25_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_25_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_2_sm_25_t_2[IPFlushRepository::dnsFlushMap_f_2_sm_25_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_25_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_2_sm_25_t_3[IPFlushRepository::dnsFlushMap_f_2_sm_25_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_25_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_2_sm_25_t_4[IPFlushRepository::dnsFlushMap_f_2_sm_25_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_25_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_2_sm_25_t_5[IPFlushRepository::dnsFlushMap_f_2_sm_25_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_25_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_2_sm_25_t_6[IPFlushRepository::dnsFlushMap_f_2_sm_25_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_25_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_2_sm_25_t_7[IPFlushRepository::dnsFlushMap_f_2_sm_25_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_25_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_2_sm_25_t_8[IPFlushRepository::dnsFlushMap_f_2_sm_25_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_25_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_2_sm_25_t_9[IPFlushRepository::dnsFlushMap_f_2_sm_25_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_25_t_9_cnt++;
						break;
					}
					break;
			case 26:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_2_sm_26_t_0[IPFlushRepository::dnsFlushMap_f_2_sm_26_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_26_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_2_sm_26_t_1[IPFlushRepository::dnsFlushMap_f_2_sm_26_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_26_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_2_sm_26_t_2[IPFlushRepository::dnsFlushMap_f_2_sm_26_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_26_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_2_sm_26_t_3[IPFlushRepository::dnsFlushMap_f_2_sm_26_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_26_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_2_sm_26_t_4[IPFlushRepository::dnsFlushMap_f_2_sm_26_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_26_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_2_sm_26_t_5[IPFlushRepository::dnsFlushMap_f_2_sm_26_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_26_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_2_sm_26_t_6[IPFlushRepository::dnsFlushMap_f_2_sm_26_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_26_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_2_sm_26_t_7[IPFlushRepository::dnsFlushMap_f_2_sm_26_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_26_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_2_sm_26_t_8[IPFlushRepository::dnsFlushMap_f_2_sm_26_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_26_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_2_sm_26_t_9[IPFlushRepository::dnsFlushMap_f_2_sm_26_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_26_t_9_cnt++;
						break;
					}
					break;
			case 27:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_2_sm_27_t_0[IPFlushRepository::dnsFlushMap_f_2_sm_27_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_27_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_2_sm_27_t_1[IPFlushRepository::dnsFlushMap_f_2_sm_27_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_27_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_2_sm_27_t_2[IPFlushRepository::dnsFlushMap_f_2_sm_27_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_27_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_2_sm_27_t_3[IPFlushRepository::dnsFlushMap_f_2_sm_27_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_27_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_2_sm_27_t_4[IPFlushRepository::dnsFlushMap_f_2_sm_27_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_27_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_2_sm_27_t_5[IPFlushRepository::dnsFlushMap_f_2_sm_27_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_27_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_2_sm_27_t_6[IPFlushRepository::dnsFlushMap_f_2_sm_27_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_27_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_2_sm_27_t_7[IPFlushRepository::dnsFlushMap_f_2_sm_27_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_27_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_2_sm_27_t_8[IPFlushRepository::dnsFlushMap_f_2_sm_27_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_27_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_2_sm_27_t_9[IPFlushRepository::dnsFlushMap_f_2_sm_27_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_27_t_9_cnt++;
						break;
					}
					break;
			case 28:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_2_sm_28_t_0[IPFlushRepository::dnsFlushMap_f_2_sm_28_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_28_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_2_sm_28_t_1[IPFlushRepository::dnsFlushMap_f_2_sm_28_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_28_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_2_sm_28_t_2[IPFlushRepository::dnsFlushMap_f_2_sm_28_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_28_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_2_sm_28_t_3[IPFlushRepository::dnsFlushMap_f_2_sm_28_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_28_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_2_sm_28_t_4[IPFlushRepository::dnsFlushMap_f_2_sm_28_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_28_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_2_sm_28_t_5[IPFlushRepository::dnsFlushMap_f_2_sm_28_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_28_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_2_sm_28_t_6[IPFlushRepository::dnsFlushMap_f_2_sm_28_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_28_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_2_sm_28_t_7[IPFlushRepository::dnsFlushMap_f_2_sm_28_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_28_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_2_sm_28_t_8[IPFlushRepository::dnsFlushMap_f_2_sm_28_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_28_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_2_sm_28_t_9[IPFlushRepository::dnsFlushMap_f_2_sm_28_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_28_t_9_cnt++;
						break;
					}
					break;
			case 29:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_2_sm_29_t_0[IPFlushRepository::dnsFlushMap_f_2_sm_29_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_29_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_2_sm_29_t_1[IPFlushRepository::dnsFlushMap_f_2_sm_29_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_29_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_2_sm_29_t_2[IPFlushRepository::dnsFlushMap_f_2_sm_29_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_29_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_2_sm_29_t_3[IPFlushRepository::dnsFlushMap_f_2_sm_29_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_29_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_2_sm_29_t_4[IPFlushRepository::dnsFlushMap_f_2_sm_29_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_29_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_2_sm_29_t_5[IPFlushRepository::dnsFlushMap_f_2_sm_29_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_29_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_2_sm_29_t_6[IPFlushRepository::dnsFlushMap_f_2_sm_29_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_29_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_2_sm_29_t_7[IPFlushRepository::dnsFlushMap_f_2_sm_29_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_29_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_2_sm_29_t_8[IPFlushRepository::dnsFlushMap_f_2_sm_29_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_29_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_2_sm_29_t_9[IPFlushRepository::dnsFlushMap_f_2_sm_29_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_2_sm_29_t_9_cnt++;
						break;
					}
					break;

	}
}

VOID S1UInterface::storeDnsSession_f_3(int index, dnsSession *pDnsSession)
{
	switch(instanceId)
	{
			case 0:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_3_sm_0_t_0[IPFlushRepository::dnsFlushMap_f_3_sm_0_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_0_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_3_sm_0_t_1[IPFlushRepository::dnsFlushMap_f_3_sm_0_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_0_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_3_sm_0_t_2[IPFlushRepository::dnsFlushMap_f_3_sm_0_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_0_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_3_sm_0_t_3[IPFlushRepository::dnsFlushMap_f_3_sm_0_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_0_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_3_sm_0_t_4[IPFlushRepository::dnsFlushMap_f_3_sm_0_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_0_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_3_sm_0_t_5[IPFlushRepository::dnsFlushMap_f_3_sm_0_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_0_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_3_sm_0_t_6[IPFlushRepository::dnsFlushMap_f_3_sm_0_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_0_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_3_sm_0_t_7[IPFlushRepository::dnsFlushMap_f_3_sm_0_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_0_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_3_sm_0_t_8[IPFlushRepository::dnsFlushMap_f_3_sm_0_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_0_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_3_sm_0_t_9[IPFlushRepository::dnsFlushMap_f_3_sm_0_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_0_t_9_cnt++;
						break;
					}
					break;

			case 1:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_3_sm_1_t_0[IPFlushRepository::dnsFlushMap_f_3_sm_1_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_1_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_3_sm_1_t_1[IPFlushRepository::dnsFlushMap_f_3_sm_1_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_1_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_3_sm_1_t_2[IPFlushRepository::dnsFlushMap_f_3_sm_1_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_1_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_3_sm_1_t_3[IPFlushRepository::dnsFlushMap_f_3_sm_1_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_1_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_3_sm_1_t_4[IPFlushRepository::dnsFlushMap_f_3_sm_1_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_1_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_3_sm_1_t_5[IPFlushRepository::dnsFlushMap_f_3_sm_1_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_1_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_3_sm_1_t_6[IPFlushRepository::dnsFlushMap_f_3_sm_1_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_1_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_3_sm_1_t_7[IPFlushRepository::dnsFlushMap_f_3_sm_1_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_1_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_3_sm_1_t_8[IPFlushRepository::dnsFlushMap_f_3_sm_1_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_1_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_3_sm_1_t_9[IPFlushRepository::dnsFlushMap_f_3_sm_1_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_1_t_9_cnt++;
						break;
					}
					break;
			case 2:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_3_sm_2_t_0[IPFlushRepository::dnsFlushMap_f_3_sm_2_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_2_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_3_sm_2_t_1[IPFlushRepository::dnsFlushMap_f_3_sm_2_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_2_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_3_sm_2_t_2[IPFlushRepository::dnsFlushMap_f_3_sm_2_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_2_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_3_sm_2_t_3[IPFlushRepository::dnsFlushMap_f_3_sm_2_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_2_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_3_sm_2_t_4[IPFlushRepository::dnsFlushMap_f_3_sm_2_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_2_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_3_sm_2_t_5[IPFlushRepository::dnsFlushMap_f_3_sm_2_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_2_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_3_sm_2_t_6[IPFlushRepository::dnsFlushMap_f_3_sm_2_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_2_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_3_sm_2_t_7[IPFlushRepository::dnsFlushMap_f_3_sm_2_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_2_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_3_sm_2_t_8[IPFlushRepository::dnsFlushMap_f_3_sm_2_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_2_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_3_sm_2_t_9[IPFlushRepository::dnsFlushMap_f_3_sm_2_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_2_t_9_cnt++;
						break;
					}
					break;

			case 3:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_3_sm_3_t_0[IPFlushRepository::dnsFlushMap_f_3_sm_3_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_3_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_3_sm_3_t_1[IPFlushRepository::dnsFlushMap_f_3_sm_3_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_3_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_3_sm_3_t_2[IPFlushRepository::dnsFlushMap_f_3_sm_3_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_3_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_3_sm_3_t_3[IPFlushRepository::dnsFlushMap_f_3_sm_3_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_3_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_3_sm_3_t_4[IPFlushRepository::dnsFlushMap_f_3_sm_3_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_3_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_3_sm_3_t_5[IPFlushRepository::dnsFlushMap_f_3_sm_3_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_3_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_3_sm_3_t_6[IPFlushRepository::dnsFlushMap_f_3_sm_3_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_3_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_3_sm_3_t_7[IPFlushRepository::dnsFlushMap_f_3_sm_3_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_3_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_3_sm_3_t_8[IPFlushRepository::dnsFlushMap_f_3_sm_3_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_3_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_3_sm_3_t_9[IPFlushRepository::dnsFlushMap_f_3_sm_3_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_3_t_9_cnt++;
						break;
					}
					break;

			case 4:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_3_sm_4_t_0[IPFlushRepository::dnsFlushMap_f_3_sm_4_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_4_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_3_sm_4_t_1[IPFlushRepository::dnsFlushMap_f_3_sm_4_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_4_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_3_sm_4_t_2[IPFlushRepository::dnsFlushMap_f_3_sm_4_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_4_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_3_sm_4_t_3[IPFlushRepository::dnsFlushMap_f_3_sm_4_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_4_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_3_sm_4_t_4[IPFlushRepository::dnsFlushMap_f_3_sm_4_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_4_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_3_sm_4_t_5[IPFlushRepository::dnsFlushMap_f_3_sm_4_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_4_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_3_sm_4_t_6[IPFlushRepository::dnsFlushMap_f_3_sm_4_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_4_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_3_sm_4_t_7[IPFlushRepository::dnsFlushMap_f_3_sm_4_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_4_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_3_sm_4_t_8[IPFlushRepository::dnsFlushMap_f_3_sm_4_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_4_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_3_sm_4_t_9[IPFlushRepository::dnsFlushMap_f_3_sm_4_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_4_t_9_cnt++;
						break;
					}
					break;

			case 5:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_3_sm_5_t_0[IPFlushRepository::dnsFlushMap_f_3_sm_5_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_5_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_3_sm_5_t_1[IPFlushRepository::dnsFlushMap_f_3_sm_5_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_5_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_3_sm_5_t_2[IPFlushRepository::dnsFlushMap_f_3_sm_5_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_5_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_3_sm_5_t_3[IPFlushRepository::dnsFlushMap_f_3_sm_5_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_5_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_3_sm_5_t_4[IPFlushRepository::dnsFlushMap_f_3_sm_5_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_5_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_3_sm_5_t_5[IPFlushRepository::dnsFlushMap_f_3_sm_5_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_5_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_3_sm_5_t_6[IPFlushRepository::dnsFlushMap_f_3_sm_5_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_5_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_3_sm_5_t_7[IPFlushRepository::dnsFlushMap_f_3_sm_5_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_5_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_3_sm_5_t_8[IPFlushRepository::dnsFlushMap_f_3_sm_5_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_5_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_3_sm_5_t_9[IPFlushRepository::dnsFlushMap_f_3_sm_5_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_5_t_9_cnt++;
						break;
					}
					break;

			case 6:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_3_sm_6_t_0[IPFlushRepository::dnsFlushMap_f_3_sm_6_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_6_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_3_sm_6_t_1[IPFlushRepository::dnsFlushMap_f_3_sm_6_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_6_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_3_sm_6_t_2[IPFlushRepository::dnsFlushMap_f_3_sm_6_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_6_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_3_sm_6_t_3[IPFlushRepository::dnsFlushMap_f_3_sm_6_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_6_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_3_sm_6_t_4[IPFlushRepository::dnsFlushMap_f_3_sm_6_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_6_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_3_sm_6_t_5[IPFlushRepository::dnsFlushMap_f_3_sm_6_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_6_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_3_sm_6_t_6[IPFlushRepository::dnsFlushMap_f_3_sm_6_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_6_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_3_sm_6_t_7[IPFlushRepository::dnsFlushMap_f_3_sm_6_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_6_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_3_sm_6_t_8[IPFlushRepository::dnsFlushMap_f_3_sm_6_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_6_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_3_sm_6_t_9[IPFlushRepository::dnsFlushMap_f_3_sm_6_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_6_t_9_cnt++;
						break;
					}
					break;
			case 7:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_3_sm_7_t_0[IPFlushRepository::dnsFlushMap_f_3_sm_7_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_7_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_3_sm_7_t_1[IPFlushRepository::dnsFlushMap_f_3_sm_7_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_7_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_3_sm_7_t_2[IPFlushRepository::dnsFlushMap_f_3_sm_7_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_7_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_3_sm_7_t_3[IPFlushRepository::dnsFlushMap_f_3_sm_7_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_7_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_3_sm_7_t_4[IPFlushRepository::dnsFlushMap_f_3_sm_7_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_7_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_3_sm_7_t_5[IPFlushRepository::dnsFlushMap_f_3_sm_7_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_7_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_3_sm_7_t_6[IPFlushRepository::dnsFlushMap_f_3_sm_7_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_7_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_3_sm_7_t_7[IPFlushRepository::dnsFlushMap_f_3_sm_7_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_7_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_3_sm_7_t_8[IPFlushRepository::dnsFlushMap_f_3_sm_7_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_7_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_3_sm_7_t_9[IPFlushRepository::dnsFlushMap_f_3_sm_7_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_7_t_9_cnt++;
						break;
					}
					break;
			case 8:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_3_sm_8_t_0[IPFlushRepository::dnsFlushMap_f_3_sm_8_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_8_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_3_sm_8_t_1[IPFlushRepository::dnsFlushMap_f_3_sm_8_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_8_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_3_sm_8_t_2[IPFlushRepository::dnsFlushMap_f_3_sm_8_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_8_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_3_sm_8_t_3[IPFlushRepository::dnsFlushMap_f_3_sm_8_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_8_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_3_sm_8_t_4[IPFlushRepository::dnsFlushMap_f_3_sm_8_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_8_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_3_sm_8_t_5[IPFlushRepository::dnsFlushMap_f_3_sm_8_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_8_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_3_sm_8_t_6[IPFlushRepository::dnsFlushMap_f_3_sm_8_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_8_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_3_sm_8_t_7[IPFlushRepository::dnsFlushMap_f_3_sm_8_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_8_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_3_sm_8_t_8[IPFlushRepository::dnsFlushMap_f_3_sm_8_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_8_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_3_sm_8_t_9[IPFlushRepository::dnsFlushMap_f_3_sm_8_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_8_t_9_cnt++;
						break;
					}
					break;
			case 9:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_3_sm_9_t_0[IPFlushRepository::dnsFlushMap_f_3_sm_9_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_9_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_3_sm_9_t_1[IPFlushRepository::dnsFlushMap_f_3_sm_9_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_9_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_3_sm_9_t_2[IPFlushRepository::dnsFlushMap_f_3_sm_9_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_9_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_3_sm_9_t_3[IPFlushRepository::dnsFlushMap_f_3_sm_9_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_9_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_3_sm_9_t_4[IPFlushRepository::dnsFlushMap_f_3_sm_9_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_9_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_3_sm_9_t_5[IPFlushRepository::dnsFlushMap_f_3_sm_9_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_9_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_3_sm_9_t_6[IPFlushRepository::dnsFlushMap_f_3_sm_9_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_9_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_3_sm_9_t_7[IPFlushRepository::dnsFlushMap_f_3_sm_9_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_9_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_3_sm_9_t_8[IPFlushRepository::dnsFlushMap_f_3_sm_9_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_9_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_3_sm_9_t_9[IPFlushRepository::dnsFlushMap_f_3_sm_9_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_9_t_9_cnt++;
						break;
					}
					break;
			case 10:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_3_sm_10_t_0[IPFlushRepository::dnsFlushMap_f_3_sm_10_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_10_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_3_sm_10_t_1[IPFlushRepository::dnsFlushMap_f_3_sm_10_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_10_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_3_sm_10_t_2[IPFlushRepository::dnsFlushMap_f_3_sm_10_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_10_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_3_sm_10_t_3[IPFlushRepository::dnsFlushMap_f_3_sm_10_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_10_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_3_sm_10_t_4[IPFlushRepository::dnsFlushMap_f_3_sm_10_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_10_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_3_sm_10_t_5[IPFlushRepository::dnsFlushMap_f_3_sm_10_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_10_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_3_sm_10_t_6[IPFlushRepository::dnsFlushMap_f_3_sm_10_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_10_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_3_sm_10_t_7[IPFlushRepository::dnsFlushMap_f_3_sm_10_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_10_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_3_sm_10_t_8[IPFlushRepository::dnsFlushMap_f_3_sm_10_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_10_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_3_sm_10_t_9[IPFlushRepository::dnsFlushMap_f_3_sm_10_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_10_t_9_cnt++;
						break;
					}
					break;
			case 11:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_3_sm_11_t_0[IPFlushRepository::dnsFlushMap_f_3_sm_11_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_11_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_3_sm_11_t_1[IPFlushRepository::dnsFlushMap_f_3_sm_11_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_11_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_3_sm_11_t_2[IPFlushRepository::dnsFlushMap_f_3_sm_11_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_11_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_3_sm_11_t_3[IPFlushRepository::dnsFlushMap_f_3_sm_11_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_11_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_3_sm_11_t_4[IPFlushRepository::dnsFlushMap_f_3_sm_11_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_11_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_3_sm_11_t_5[IPFlushRepository::dnsFlushMap_f_3_sm_11_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_11_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_3_sm_11_t_6[IPFlushRepository::dnsFlushMap_f_3_sm_11_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_11_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_3_sm_11_t_7[IPFlushRepository::dnsFlushMap_f_3_sm_11_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_11_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_3_sm_11_t_8[IPFlushRepository::dnsFlushMap_f_3_sm_11_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_11_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_3_sm_11_t_9[IPFlushRepository::dnsFlushMap_f_3_sm_11_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_11_t_9_cnt++;
						break;
					}
					break;
			case 12:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_3_sm_12_t_0[IPFlushRepository::dnsFlushMap_f_3_sm_12_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_12_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_3_sm_12_t_1[IPFlushRepository::dnsFlushMap_f_3_sm_12_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_12_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_3_sm_12_t_2[IPFlushRepository::dnsFlushMap_f_3_sm_12_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_12_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_3_sm_12_t_3[IPFlushRepository::dnsFlushMap_f_3_sm_12_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_12_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_3_sm_12_t_4[IPFlushRepository::dnsFlushMap_f_3_sm_12_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_12_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_3_sm_12_t_5[IPFlushRepository::dnsFlushMap_f_3_sm_12_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_12_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_3_sm_12_t_6[IPFlushRepository::dnsFlushMap_f_3_sm_12_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_12_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_3_sm_12_t_7[IPFlushRepository::dnsFlushMap_f_3_sm_12_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_12_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_3_sm_12_t_8[IPFlushRepository::dnsFlushMap_f_3_sm_12_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_12_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_3_sm_12_t_9[IPFlushRepository::dnsFlushMap_f_3_sm_12_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_12_t_9_cnt++;
						break;
					}
					break;
			case 13:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_3_sm_13_t_0[IPFlushRepository::dnsFlushMap_f_3_sm_13_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_13_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_3_sm_13_t_1[IPFlushRepository::dnsFlushMap_f_3_sm_13_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_13_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_3_sm_13_t_2[IPFlushRepository::dnsFlushMap_f_3_sm_13_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_13_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_3_sm_13_t_3[IPFlushRepository::dnsFlushMap_f_3_sm_13_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_13_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_3_sm_13_t_4[IPFlushRepository::dnsFlushMap_f_3_sm_13_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_13_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_3_sm_13_t_5[IPFlushRepository::dnsFlushMap_f_3_sm_13_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_13_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_3_sm_13_t_6[IPFlushRepository::dnsFlushMap_f_3_sm_13_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_13_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_3_sm_13_t_7[IPFlushRepository::dnsFlushMap_f_3_sm_13_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_13_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_3_sm_13_t_8[IPFlushRepository::dnsFlushMap_f_3_sm_13_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_13_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_3_sm_13_t_9[IPFlushRepository::dnsFlushMap_f_3_sm_13_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_13_t_9_cnt++;
						break;
					}
					break;
			case 14:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_3_sm_14_t_0[IPFlushRepository::dnsFlushMap_f_3_sm_14_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_14_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_3_sm_14_t_1[IPFlushRepository::dnsFlushMap_f_3_sm_14_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_14_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_3_sm_14_t_2[IPFlushRepository::dnsFlushMap_f_3_sm_14_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_14_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_3_sm_14_t_3[IPFlushRepository::dnsFlushMap_f_3_sm_14_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_14_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_3_sm_14_t_4[IPFlushRepository::dnsFlushMap_f_3_sm_14_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_14_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_3_sm_14_t_5[IPFlushRepository::dnsFlushMap_f_3_sm_14_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_14_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_3_sm_14_t_6[IPFlushRepository::dnsFlushMap_f_3_sm_14_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_14_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_3_sm_14_t_7[IPFlushRepository::dnsFlushMap_f_3_sm_14_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_14_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_3_sm_14_t_8[IPFlushRepository::dnsFlushMap_f_3_sm_14_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_14_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_3_sm_14_t_9[IPFlushRepository::dnsFlushMap_f_3_sm_14_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_14_t_9_cnt++;
						break;
					}
					break;
			case 15:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_3_sm_15_t_0[IPFlushRepository::dnsFlushMap_f_3_sm_15_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_15_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_3_sm_15_t_1[IPFlushRepository::dnsFlushMap_f_3_sm_15_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_15_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_3_sm_15_t_2[IPFlushRepository::dnsFlushMap_f_3_sm_15_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_15_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_3_sm_15_t_3[IPFlushRepository::dnsFlushMap_f_3_sm_15_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_15_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_3_sm_15_t_4[IPFlushRepository::dnsFlushMap_f_3_sm_15_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_15_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_3_sm_15_t_5[IPFlushRepository::dnsFlushMap_f_3_sm_15_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_15_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_3_sm_15_t_6[IPFlushRepository::dnsFlushMap_f_3_sm_15_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_15_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_3_sm_15_t_7[IPFlushRepository::dnsFlushMap_f_3_sm_15_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_15_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_3_sm_15_t_8[IPFlushRepository::dnsFlushMap_f_3_sm_15_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_15_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_3_sm_15_t_9[IPFlushRepository::dnsFlushMap_f_3_sm_15_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_15_t_9_cnt++;
						break;
					}
					break;
			case 16:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_3_sm_16_t_0[IPFlushRepository::dnsFlushMap_f_3_sm_16_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_16_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_3_sm_16_t_1[IPFlushRepository::dnsFlushMap_f_3_sm_16_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_16_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_3_sm_16_t_2[IPFlushRepository::dnsFlushMap_f_3_sm_16_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_16_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_3_sm_16_t_3[IPFlushRepository::dnsFlushMap_f_3_sm_16_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_16_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_3_sm_16_t_4[IPFlushRepository::dnsFlushMap_f_3_sm_16_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_16_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_3_sm_16_t_5[IPFlushRepository::dnsFlushMap_f_3_sm_16_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_16_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_3_sm_16_t_6[IPFlushRepository::dnsFlushMap_f_3_sm_16_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_16_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_3_sm_16_t_7[IPFlushRepository::dnsFlushMap_f_3_sm_16_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_16_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_3_sm_16_t_8[IPFlushRepository::dnsFlushMap_f_3_sm_16_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_16_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_3_sm_16_t_9[IPFlushRepository::dnsFlushMap_f_3_sm_16_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_16_t_9_cnt++;
						break;
					}
					break;
			case 17:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_3_sm_17_t_0[IPFlushRepository::dnsFlushMap_f_3_sm_17_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_17_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_3_sm_17_t_1[IPFlushRepository::dnsFlushMap_f_3_sm_17_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_17_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_3_sm_17_t_2[IPFlushRepository::dnsFlushMap_f_3_sm_17_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_17_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_3_sm_17_t_3[IPFlushRepository::dnsFlushMap_f_3_sm_17_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_17_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_3_sm_17_t_4[IPFlushRepository::dnsFlushMap_f_3_sm_17_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_17_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_3_sm_17_t_5[IPFlushRepository::dnsFlushMap_f_3_sm_17_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_17_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_3_sm_17_t_6[IPFlushRepository::dnsFlushMap_f_3_sm_17_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_17_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_3_sm_17_t_7[IPFlushRepository::dnsFlushMap_f_3_sm_17_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_17_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_3_sm_17_t_8[IPFlushRepository::dnsFlushMap_f_3_sm_17_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_17_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_3_sm_17_t_9[IPFlushRepository::dnsFlushMap_f_3_sm_17_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_17_t_9_cnt++;
						break;
					}
					break;
			case 18:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_3_sm_18_t_0[IPFlushRepository::dnsFlushMap_f_3_sm_18_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_18_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_3_sm_18_t_1[IPFlushRepository::dnsFlushMap_f_3_sm_18_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_18_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_3_sm_18_t_2[IPFlushRepository::dnsFlushMap_f_3_sm_18_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_18_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_3_sm_18_t_3[IPFlushRepository::dnsFlushMap_f_3_sm_18_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_18_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_3_sm_18_t_4[IPFlushRepository::dnsFlushMap_f_3_sm_18_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_18_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_3_sm_18_t_5[IPFlushRepository::dnsFlushMap_f_3_sm_18_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_18_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_3_sm_18_t_6[IPFlushRepository::dnsFlushMap_f_3_sm_18_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_18_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_3_sm_18_t_7[IPFlushRepository::dnsFlushMap_f_3_sm_18_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_18_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_3_sm_18_t_8[IPFlushRepository::dnsFlushMap_f_3_sm_18_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_18_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_3_sm_18_t_9[IPFlushRepository::dnsFlushMap_f_3_sm_18_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_18_t_9_cnt++;
						break;
					}
					break;
			case 19:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_3_sm_19_t_0[IPFlushRepository::dnsFlushMap_f_3_sm_19_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_19_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_3_sm_19_t_1[IPFlushRepository::dnsFlushMap_f_3_sm_19_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_19_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_3_sm_19_t_2[IPFlushRepository::dnsFlushMap_f_3_sm_19_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_19_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_3_sm_19_t_3[IPFlushRepository::dnsFlushMap_f_3_sm_19_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_19_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_3_sm_19_t_4[IPFlushRepository::dnsFlushMap_f_3_sm_19_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_19_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_3_sm_19_t_5[IPFlushRepository::dnsFlushMap_f_3_sm_19_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_19_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_3_sm_19_t_6[IPFlushRepository::dnsFlushMap_f_3_sm_19_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_19_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_3_sm_19_t_7[IPFlushRepository::dnsFlushMap_f_3_sm_19_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_19_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_3_sm_19_t_8[IPFlushRepository::dnsFlushMap_f_3_sm_19_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_19_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_3_sm_19_t_9[IPFlushRepository::dnsFlushMap_f_3_sm_19_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_19_t_9_cnt++;
						break;
					}
					break;
			case 20:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_3_sm_20_t_0[IPFlushRepository::dnsFlushMap_f_3_sm_20_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_20_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_3_sm_20_t_1[IPFlushRepository::dnsFlushMap_f_3_sm_20_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_20_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_3_sm_20_t_2[IPFlushRepository::dnsFlushMap_f_3_sm_20_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_20_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_3_sm_20_t_3[IPFlushRepository::dnsFlushMap_f_3_sm_20_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_20_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_3_sm_20_t_4[IPFlushRepository::dnsFlushMap_f_3_sm_20_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_20_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_3_sm_20_t_5[IPFlushRepository::dnsFlushMap_f_3_sm_20_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_20_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_3_sm_20_t_6[IPFlushRepository::dnsFlushMap_f_3_sm_20_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_20_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_3_sm_20_t_7[IPFlushRepository::dnsFlushMap_f_3_sm_20_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_20_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_3_sm_20_t_8[IPFlushRepository::dnsFlushMap_f_3_sm_20_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_20_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_3_sm_20_t_9[IPFlushRepository::dnsFlushMap_f_3_sm_20_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_20_t_9_cnt++;
						break;
					}
					break;
			case 21:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_3_sm_21_t_0[IPFlushRepository::dnsFlushMap_f_3_sm_21_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_21_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_3_sm_21_t_1[IPFlushRepository::dnsFlushMap_f_3_sm_21_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_21_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_3_sm_21_t_2[IPFlushRepository::dnsFlushMap_f_3_sm_21_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_21_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_3_sm_21_t_3[IPFlushRepository::dnsFlushMap_f_3_sm_21_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_21_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_3_sm_21_t_4[IPFlushRepository::dnsFlushMap_f_3_sm_21_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_21_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_3_sm_21_t_5[IPFlushRepository::dnsFlushMap_f_3_sm_21_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_21_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_3_sm_21_t_6[IPFlushRepository::dnsFlushMap_f_3_sm_21_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_21_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_3_sm_21_t_7[IPFlushRepository::dnsFlushMap_f_3_sm_21_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_21_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_3_sm_21_t_8[IPFlushRepository::dnsFlushMap_f_3_sm_21_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_21_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_3_sm_21_t_9[IPFlushRepository::dnsFlushMap_f_3_sm_21_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_21_t_9_cnt++;
						break;
					}
					break;
			case 22:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_3_sm_22_t_0[IPFlushRepository::dnsFlushMap_f_3_sm_22_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_22_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_3_sm_22_t_1[IPFlushRepository::dnsFlushMap_f_3_sm_22_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_22_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_3_sm_22_t_2[IPFlushRepository::dnsFlushMap_f_3_sm_22_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_22_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_3_sm_22_t_3[IPFlushRepository::dnsFlushMap_f_3_sm_22_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_22_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_3_sm_22_t_4[IPFlushRepository::dnsFlushMap_f_3_sm_22_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_22_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_3_sm_22_t_5[IPFlushRepository::dnsFlushMap_f_3_sm_22_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_22_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_3_sm_22_t_6[IPFlushRepository::dnsFlushMap_f_3_sm_22_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_22_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_3_sm_22_t_7[IPFlushRepository::dnsFlushMap_f_3_sm_22_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_22_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_3_sm_22_t_8[IPFlushRepository::dnsFlushMap_f_3_sm_22_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_22_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_3_sm_22_t_9[IPFlushRepository::dnsFlushMap_f_3_sm_22_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_22_t_9_cnt++;
						break;
					}
					break;
			case 23:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_3_sm_23_t_0[IPFlushRepository::dnsFlushMap_f_3_sm_23_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_23_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_3_sm_23_t_1[IPFlushRepository::dnsFlushMap_f_3_sm_23_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_23_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_3_sm_23_t_2[IPFlushRepository::dnsFlushMap_f_3_sm_23_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_23_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_3_sm_23_t_3[IPFlushRepository::dnsFlushMap_f_3_sm_23_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_23_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_3_sm_23_t_4[IPFlushRepository::dnsFlushMap_f_3_sm_23_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_23_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_3_sm_23_t_5[IPFlushRepository::dnsFlushMap_f_3_sm_23_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_23_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_3_sm_23_t_6[IPFlushRepository::dnsFlushMap_f_3_sm_23_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_23_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_3_sm_23_t_7[IPFlushRepository::dnsFlushMap_f_3_sm_23_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_23_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_3_sm_23_t_8[IPFlushRepository::dnsFlushMap_f_3_sm_23_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_23_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_3_sm_23_t_9[IPFlushRepository::dnsFlushMap_f_3_sm_23_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_23_t_9_cnt++;
						break;
					}
					break;
			case 24:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_3_sm_24_t_0[IPFlushRepository::dnsFlushMap_f_3_sm_24_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_24_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_3_sm_24_t_1[IPFlushRepository::dnsFlushMap_f_3_sm_24_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_24_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_3_sm_24_t_2[IPFlushRepository::dnsFlushMap_f_3_sm_24_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_24_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_3_sm_24_t_3[IPFlushRepository::dnsFlushMap_f_3_sm_24_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_24_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_3_sm_24_t_4[IPFlushRepository::dnsFlushMap_f_3_sm_24_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_24_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_3_sm_24_t_5[IPFlushRepository::dnsFlushMap_f_3_sm_24_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_24_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_3_sm_24_t_6[IPFlushRepository::dnsFlushMap_f_3_sm_24_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_24_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_3_sm_24_t_7[IPFlushRepository::dnsFlushMap_f_3_sm_24_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_24_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_3_sm_24_t_8[IPFlushRepository::dnsFlushMap_f_3_sm_24_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_24_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_3_sm_24_t_9[IPFlushRepository::dnsFlushMap_f_3_sm_24_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_24_t_9_cnt++;
						break;
					}
					break;
			case 25:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_3_sm_25_t_0[IPFlushRepository::dnsFlushMap_f_3_sm_25_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_25_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_3_sm_25_t_1[IPFlushRepository::dnsFlushMap_f_3_sm_25_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_25_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_3_sm_25_t_2[IPFlushRepository::dnsFlushMap_f_3_sm_25_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_25_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_3_sm_25_t_3[IPFlushRepository::dnsFlushMap_f_3_sm_25_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_25_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_3_sm_25_t_4[IPFlushRepository::dnsFlushMap_f_3_sm_25_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_25_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_3_sm_25_t_5[IPFlushRepository::dnsFlushMap_f_3_sm_25_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_25_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_3_sm_25_t_6[IPFlushRepository::dnsFlushMap_f_3_sm_25_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_25_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_3_sm_25_t_7[IPFlushRepository::dnsFlushMap_f_3_sm_25_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_25_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_3_sm_25_t_8[IPFlushRepository::dnsFlushMap_f_3_sm_25_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_25_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_3_sm_25_t_9[IPFlushRepository::dnsFlushMap_f_3_sm_25_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_25_t_9_cnt++;
						break;
					}
					break;
			case 26:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_3_sm_26_t_0[IPFlushRepository::dnsFlushMap_f_3_sm_26_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_26_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_3_sm_26_t_1[IPFlushRepository::dnsFlushMap_f_3_sm_26_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_26_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_3_sm_26_t_2[IPFlushRepository::dnsFlushMap_f_3_sm_26_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_26_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_3_sm_26_t_3[IPFlushRepository::dnsFlushMap_f_3_sm_26_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_26_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_3_sm_26_t_4[IPFlushRepository::dnsFlushMap_f_3_sm_26_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_26_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_3_sm_26_t_5[IPFlushRepository::dnsFlushMap_f_3_sm_26_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_26_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_3_sm_26_t_6[IPFlushRepository::dnsFlushMap_f_3_sm_26_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_26_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_3_sm_26_t_7[IPFlushRepository::dnsFlushMap_f_3_sm_26_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_26_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_3_sm_26_t_8[IPFlushRepository::dnsFlushMap_f_3_sm_26_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_26_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_3_sm_26_t_9[IPFlushRepository::dnsFlushMap_f_3_sm_26_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_26_t_9_cnt++;
						break;
					}
					break;
			case 27:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_3_sm_27_t_0[IPFlushRepository::dnsFlushMap_f_3_sm_27_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_27_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_3_sm_27_t_1[IPFlushRepository::dnsFlushMap_f_3_sm_27_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_27_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_3_sm_27_t_2[IPFlushRepository::dnsFlushMap_f_3_sm_27_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_27_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_3_sm_27_t_3[IPFlushRepository::dnsFlushMap_f_3_sm_27_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_27_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_3_sm_27_t_4[IPFlushRepository::dnsFlushMap_f_3_sm_27_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_27_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_3_sm_27_t_5[IPFlushRepository::dnsFlushMap_f_3_sm_27_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_27_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_3_sm_27_t_6[IPFlushRepository::dnsFlushMap_f_3_sm_27_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_27_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_3_sm_27_t_7[IPFlushRepository::dnsFlushMap_f_3_sm_27_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_27_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_3_sm_27_t_8[IPFlushRepository::dnsFlushMap_f_3_sm_27_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_27_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_3_sm_27_t_9[IPFlushRepository::dnsFlushMap_f_3_sm_27_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_27_t_9_cnt++;
						break;
					}
					break;
			case 28:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_3_sm_28_t_0[IPFlushRepository::dnsFlushMap_f_3_sm_28_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_28_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_3_sm_28_t_1[IPFlushRepository::dnsFlushMap_f_3_sm_28_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_28_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_3_sm_28_t_2[IPFlushRepository::dnsFlushMap_f_3_sm_28_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_28_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_3_sm_28_t_3[IPFlushRepository::dnsFlushMap_f_3_sm_28_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_28_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_3_sm_28_t_4[IPFlushRepository::dnsFlushMap_f_3_sm_28_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_28_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_3_sm_28_t_5[IPFlushRepository::dnsFlushMap_f_3_sm_28_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_28_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_3_sm_28_t_6[IPFlushRepository::dnsFlushMap_f_3_sm_28_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_28_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_3_sm_28_t_7[IPFlushRepository::dnsFlushMap_f_3_sm_28_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_28_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_3_sm_28_t_8[IPFlushRepository::dnsFlushMap_f_3_sm_28_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_28_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_3_sm_28_t_9[IPFlushRepository::dnsFlushMap_f_3_sm_28_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_28_t_9_cnt++;
						break;
					}
					break;
			case 29:
					switch(index)
					{
					case 0:
						IPFlushRepository::dnsFlushMap_f_3_sm_29_t_0[IPFlushRepository::dnsFlushMap_f_3_sm_29_t_0_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_29_t_0_cnt++;
						break;
					case 1:
						IPFlushRepository::dnsFlushMap_f_3_sm_29_t_1[IPFlushRepository::dnsFlushMap_f_3_sm_29_t_1_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_29_t_1_cnt++;
						break;
					case 2:
						IPFlushRepository::dnsFlushMap_f_3_sm_29_t_2[IPFlushRepository::dnsFlushMap_f_3_sm_29_t_2_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_29_t_2_cnt++;
						break;
					case 3:
						IPFlushRepository::dnsFlushMap_f_3_sm_29_t_3[IPFlushRepository::dnsFlushMap_f_3_sm_29_t_3_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_29_t_3_cnt++;
						break;
					case 4:
						IPFlushRepository::dnsFlushMap_f_3_sm_29_t_4[IPFlushRepository::dnsFlushMap_f_3_sm_29_t_4_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_29_t_4_cnt++;
						break;
					case 5:
						IPFlushRepository::dnsFlushMap_f_3_sm_29_t_5[IPFlushRepository::dnsFlushMap_f_3_sm_29_t_5_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_29_t_5_cnt++;
						break;
					case 6:
						IPFlushRepository::dnsFlushMap_f_3_sm_29_t_6[IPFlushRepository::dnsFlushMap_f_3_sm_29_t_6_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_29_t_6_cnt++;
						break;
					case 7:
						IPFlushRepository::dnsFlushMap_f_3_sm_29_t_7[IPFlushRepository::dnsFlushMap_f_3_sm_29_t_7_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_29_t_7_cnt++;
						break;
					case 8:
						IPFlushRepository::dnsFlushMap_f_3_sm_29_t_8[IPFlushRepository::dnsFlushMap_f_3_sm_29_t_8_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_29_t_8_cnt++;
						break;
					case 9:
						IPFlushRepository::dnsFlushMap_f_3_sm_29_t_9[IPFlushRepository::dnsFlushMap_f_3_sm_29_t_9_cnt].copy(pDnsSession);
						IPFlushRepository::dnsFlushMap_f_3_sm_29_t_9_cnt++;
						break;
					}
					break;

	}
}

VOID S1UInterface::IPv4_DnsTimeOutCleanSession()
{
	int IdleTimeSec = IPGlobal::S1U_SESSION_CLEAN_UP_TIMEOUT_SEC;
//	uint64_t curEpochSec = (uint64_t) getCurrentEpochSeconds();
	uint64_t curEpochSec = IPGlobal::CURRENT_EPOCH_SEC;
	int flushType = 0;

	dnsSessionCleanUpMap_cnt = 0;

//	for(auto elem : dnsSessionMap)
	for(auto elem = dnsSessionMap.begin(), next_elem = elem; elem != dnsSessionMap.end(); elem = next_elem)
	{
			++next_elem;
			dnsSession *pDnsSession = getDnsSessionFromPool(elem->second);

			if(((pDnsSession->queryStartEpochSec > 0) && ((curEpochSec - pDnsSession->queryStartEpochSec) > IdleTimeSec)) ||
					((pDnsSession->queryEndEpochSec > 0) && ((curEpochSec - pDnsSession->queryEndEpochSec) > IdleTimeSec)))
			{
				if(pDnsSession->queryStartEpochSec == 0 && pDnsSession->queryEndEpochSec != 0) {
					pDnsSession->queryStartEpochSec = pDnsSession->queryEndEpochSec;
					pDnsSession->queryStartEpochNanoSec = pDnsSession->queryEndEpochNanoSec;
					flushType = DNS_FLUSH_CLEANUP_RSP_NOREQ;
				}
				else if(pDnsSession->queryEndEpochSec == 0 && pDnsSession->queryStartEpochSec != 0) {
					pDnsSession->queryEndEpochSec = pDnsSession->queryStartEpochSec;
					pDnsSession->queryEndEpochNanoSec = pDnsSession->queryStartEpochNanoSec;
					flushType = DNS_FLUSH_CLEANUP_REQ_NORSP;
				}
				else
				{ flushType = DNS_FLUSH_CLEANUP_REQ_RSP; }

				pDnsSession->causeCode = SYSTEM_CLEANUP_DNS_QUERY;
				strcpy(pDnsSession->address, "NULL");

				if(pDnsSession->state == QUERY) {
					pDnsSession->errorCode = SYSTEM_CLEANUP_DNS_QUERY;
						strcpy(pDnsSession->errorDesc, "No Response");
				}
				/* Flush only DNS Request Message (As No Response is onlly for Request) */
				if(strlen(pDnsSession->URL) != 0 && pDnsSession->state != RESPONSE) flushDnsSession(pDnsSession, flushType);
				releaseIndexDns(elem->second);
				dnsSessionMap.erase(elem->first);
//				dnsSessionCleanUpMap[dnsSessionCleanUpMap_cnt].key = elem.first;
//				dnsSessionCleanUpMap[dnsSessionCleanUpMap_cnt].poolIndex = elem.second;
				dnsSessionCleanUpMap_cnt++;
			}
	}

//	for(int i = 0; i < dnsSessionCleanUpMap_cnt; i++){
//		releaseIndexDns(dnsSessionCleanUpMap[i].poolIndex);
//		dnsSessionMap.erase(dnsSessionCleanUpMap[i].key);
//	}
//	dnsSessionCleanUpMap.clear();

	IPGlobal::CLEANED_S1U_DNS_SESSIONS[instanceId] = dnsSessionCleanUpMap_cnt;
	dnsSessionCleanUpMap_cnt = 0;

}

int S1UInterface::cleanDnsDBMap(int epochSec, std::map<std::string, dnsUrl> &dnsDBMap)
{
	dnsDatabaseCleanMap_cnt = 0;

	for(auto elem : dnsDBMap)
	{
		if((epochSec - elem.second.pckLastTimeEpcohSec) > IPGlobal::DNS_LOOKUPDB_CLEAN_UP_TIMEOUT_SEC)
		{
			dnsDatabaseCleanMap[dnsDatabaseCleanMap_cnt] = elem.first;
			dnsDatabaseCleanMap_cnt++;
		}
	}

	for(int i=0; i<dnsDatabaseCleanMap_cnt; i++){
		dnsDBMap.erase(dnsDatabaseCleanMap[i]);
	}

	for(int i=0; i<dnsDatabaseCleanMap_cnt; i++)
		dnsDatabaseCleanMap.erase(i);

	return(dnsDatabaseCleanMap_cnt);
}

VOID S1UInterface::eraseDnsDDBMap(std::map<std::string, dnsUrl> &dnsMap)
{
	std::map<std::string, dnsUrl>::iterator it = dnsMap.begin();
	dnsMap.erase(it, dnsMap.end());
	dnsMap.clear();
}

VOID S1UInterface::emptyDnsDataBaseMap()
{
	IPv4_DnsLookUpCount();
	eraseDnsDDBMap(DNSGlobal::dnsDatabaseMap_0);
	eraseDnsDDBMap(DNSGlobal::dnsDatabaseMap_1);
	eraseDnsDDBMap(DNSGlobal::dnsDatabaseMap_2);
	eraseDnsDDBMap(DNSGlobal::dnsDatabaseMap_3);
	eraseDnsDDBMap(DNSGlobal::dnsDatabaseMap_4);
	eraseDnsDDBMap(DNSGlobal::dnsDatabaseMap_5);
	eraseDnsDDBMap(DNSGlobal::dnsDatabaseMap_6);
	eraseDnsDDBMap(DNSGlobal::dnsDatabaseMap_7);
	eraseDnsDDBMap(DNSGlobal::dnsDatabaseMap_8);
	eraseDnsDDBMap(DNSGlobal::dnsDatabaseMap_9);
	TheLog_nc_v1(Log::Info, name(),"   DNS DB Initialized   Completed!!", "");

}

VOID S1UInterface::IPv4_DnsDBClean()
{
	int totalIpv4CleanCnt = 0;
	int totalIpv6CleanCnt = 0;

	int curEpochSec = (int) IPGlobal::CURRENT_EPOCH_SEC;

	totalIpv4CleanCnt += cleanDnsDBMap(curEpochSec, DNSGlobal::dnsDatabaseMap_0);
	totalIpv4CleanCnt += cleanDnsDBMap(curEpochSec, DNSGlobal::dnsDatabaseMap_1);
	totalIpv4CleanCnt += cleanDnsDBMap(curEpochSec, DNSGlobal::dnsDatabaseMap_2);
	totalIpv4CleanCnt += cleanDnsDBMap(curEpochSec, DNSGlobal::dnsDatabaseMap_3);
	totalIpv4CleanCnt += cleanDnsDBMap(curEpochSec, DNSGlobal::dnsDatabaseMap_4);
	totalIpv4CleanCnt += cleanDnsDBMap(curEpochSec, DNSGlobal::dnsDatabaseMap_5);
	totalIpv4CleanCnt += cleanDnsDBMap(curEpochSec, DNSGlobal::dnsDatabaseMap_6);
	totalIpv4CleanCnt += cleanDnsDBMap(curEpochSec, DNSGlobal::dnsDatabaseMap_7);
	totalIpv4CleanCnt += cleanDnsDBMap(curEpochSec, DNSGlobal::dnsDatabaseMap_8);
	totalIpv4CleanCnt += cleanDnsDBMap(curEpochSec, DNSGlobal::dnsDatabaseMap_9);

	/* --- IPV6 ----- */

	dnsDatabaseCleanMap.clear();
	dnsDatabaseCleanMap_cnt = 0;

	for(auto elem : DNSGlobal::dnsV6DatabaseMap)
	{
		if((curEpochSec - elem.second.pckLastTimeEpcohSec) > IPGlobal::DNS_LOOKUPDB_CLEAN_UP_TIMEOUT_SEC)
		{
			dnsDatabaseCleanMap[dnsDatabaseCleanMap_cnt] = elem.first;
			dnsDatabaseCleanMap_cnt++;
		}
	}
	totalIpv6CleanCnt += dnsDatabaseCleanMap_cnt;

	for(long i=0; i<dnsDatabaseCleanMap_cnt; i++){
		DNSGlobal::dnsV6DatabaseMap.erase(dnsDatabaseCleanMap[i]);
	}

	dnsDatabaseCleanMap.clear();
	dnsDatabaseCleanMap_cnt = 0;

	TheLog_nc_v2(Log::Info, name(),"   DNS DB Cleaned       IPv4: %08d | IPv6: %08d", totalIpv4CleanCnt, totalIpv6CleanCnt);
}

VOID S1UInterface::IPv4_DnsDumpLkuInfo(int day)
{
	char fileName[50];
	fileName[0] = 0;

	/* Dumping File Hourly */
	sprintf(fileName, "%s_%02d.csv", "dnsIpv4data", day);
	string filePath = GContainer::config->DATA_DIRECTORY + string(fileName);

	printf("IPSMInterface [%d] Dumping Daily IPv4 DNS Lookup Store to file [%s]...\n",instanceId, filePath.c_str());
	TheLog_nc_v2(Log::Info, name()," [%d] Dumping Daily IPv4 DNS Lookup Store to file [%s]...",instanceId,filePath.c_str());

	ofstream fileHandler;

	fileHandler.open(filePath.c_str(), ios :: out);

	if(fileHandler.fail())
	{
		printf("IPSMInterface [%d] Error in Dumping Daily IPv4 DNS Lookup Store File : %s\n",instanceId, filePath.c_str());
		TheLog_nc_v2(Log::Warn, name()," [%d] Error in Dumping Daily IPv4 DNS Lookup Store to file [%s]...",instanceId,filePath.c_str());
	}
	else
	{
		for(auto elem : DNSGlobal::dnsLookUpMap_0) {
			fileHandler << elem.first << "," << elem.second << endl;
		}
		for(auto elem : DNSGlobal::dnsLookUpMap_1) {
			fileHandler << elem.first << "," << elem.second << endl;
		}
		for(auto elem : DNSGlobal::dnsLookUpMap_2) {
			fileHandler << elem.first << "," << elem.second << endl;
		}
		for(auto elem : DNSGlobal::dnsLookUpMap_3) {
			fileHandler << elem.first << "," << elem.second << endl;
		}
		for(auto elem : DNSGlobal::dnsLookUpMap_4) {
			fileHandler << elem.first << "," << elem.second << endl;
		}
		for(auto elem : DNSGlobal::dnsLookUpMap_5) {
			fileHandler << elem.first << "," << elem.second << endl;
		}
		for(auto elem : DNSGlobal::dnsLookUpMap_6) {
			fileHandler << elem.first << "," << elem.second << endl;
		}
		for(auto elem : DNSGlobal::dnsLookUpMap_7) {
			fileHandler << elem.first << "," << elem.second << endl;
		}
		for(auto elem : DNSGlobal::dnsLookUpMap_8) {
			fileHandler << elem.first << "," << elem.second << endl;
		}
		for(auto elem : DNSGlobal::dnsLookUpMap_9) {
			fileHandler << elem.first << "," << elem.second << endl;
		}

		fileHandler.close();
		printf("IPSMInterface [%d] Dumping IPv4 Daily DNS Lookup Store to file [%s]...Completed\n",instanceId,filePath.c_str());
		TheLog_nc_v2(Log::Info, name()," [%d] Dumping Daily IPv4 DNS Lookup Store to file [%s]...Completed",instanceId,filePath.c_str());
		filePath.clear();
	}

	/* Current File */
	filePath = GContainer::config->DATA_DIRECTORY + "dnsIpv4data.csv";
	printf("IPSMInterface [%d] Dumping Current IPv4 DNS Lookup Store to file [%s]...\n",instanceId, filePath.c_str());
	TheLog_nc_v2(Log::Info, name()," [%d] Dumping Current IPv4 DNS Lookup Store to file [%s]...",instanceId,filePath.c_str());

	fileHandler.open(filePath.c_str(), ios :: out);

	if(fileHandler.fail())
	{
		printf("IPSMInterface [%d] Error in Dumping Current IPv4 DNS Lookup Store File : %s\n",instanceId, filePath.c_str());
		TheLog_nc_v2(Log::Warn, name()," [%d] Error in Dumping Current IPv4 DNS Lookup Store to file [%s]...",instanceId,filePath.c_str());
	}
	else
	{
		for(auto elem : DNSGlobal::dnsLookUpMap_0) {
			fileHandler << elem.first << "," << elem.second << endl;
		}
		for(auto elem : DNSGlobal::dnsLookUpMap_1) {
			fileHandler << elem.first << "," << elem.second << endl;
		}
		for(auto elem : DNSGlobal::dnsLookUpMap_2) {
			fileHandler << elem.first << "," << elem.second << endl;
		}
		for(auto elem : DNSGlobal::dnsLookUpMap_3) {
			fileHandler << elem.first << "," << elem.second << endl;
		}
		for(auto elem : DNSGlobal::dnsLookUpMap_4) {
			fileHandler << elem.first << "," << elem.second << endl;
		}
		for(auto elem : DNSGlobal::dnsLookUpMap_5) {
			fileHandler << elem.first << "," << elem.second << endl;
		}
		for(auto elem : DNSGlobal::dnsLookUpMap_6) {
			fileHandler << elem.first << "," << elem.second << endl;
		}
		for(auto elem : DNSGlobal::dnsLookUpMap_7) {
			fileHandler << elem.first << "," << elem.second << endl;
		}
		for(auto elem : DNSGlobal::dnsLookUpMap_8) {
			fileHandler << elem.first << "," << elem.second << endl;
		}
		for(auto elem : DNSGlobal::dnsLookUpMap_9) {
			fileHandler << elem.first << "," << elem.second << endl;
		}

		fileHandler.close();
		printf("IPSMInterface [%d] Dumping Current IPv4 DNS Lookup Store to file [%s]...Completed\n",instanceId,filePath.c_str());
		TheLog_nc_v2(Log::Info, name()," [%d] Dumping Current IPv4 DNS Lookup Store to file [%s]...Completed",instanceId,filePath.c_str());
		filePath.clear();
	}
}

VOID S1UInterface::IPv6_DnsDumpLkuInfo(int day)
{
	char fileName[50];
	fileName[0] = 0;

	/* Dumping File Hourly */
	sprintf(fileName, "%s_%02d.csv", "dnsIpv6data", day);
	string filePath = GContainer::config->DATA_DIRECTORY + string(fileName);

	printf("IPSMInterface [%d] Dumping Daily IPv6 DNS Lookup Store to file [%s]...\n", instanceId, filePath.c_str());
	TheLog_nc_v2(Log::Info, name()," [%d] Dumping Daily IPv6 DNS Lookup Store to file [%s]...", instanceId, filePath.c_str());

	ofstream fileHandler;

	fileHandler.open(filePath.c_str(), ios :: out);

	if(fileHandler.fail())
	{
		printf("IPSMInterface [%d] Error in Dumping Daily IPv6 DNS Lookup Store File : %s\n",instanceId, filePath.c_str());
		TheLog_nc_v2(Log::Warn, name()," [%d] Error in Dumping Daily IPv6 DNS Lookup Store to file [%s]...", instanceId, filePath.c_str());
	}
	else
	{
		for(auto elem : DNSGlobal::dnsV6LookUpMap)
			fileHandler << elem.first << "," << elem.second << endl;

		fileHandler.close();
		printf("IPSMInterface [%d] Dumping Daily IPv6 DNS Lookup Store to file [%s]...Completed\n", instanceId, filePath.c_str());
		TheLog_nc_v2(Log::Info, name()," [%d] Dumping Daily IPv6 DNS Lookup Store to file [%s]...Completed", instanceId, filePath.c_str());
		filePath.clear();
	}

	filePath = GContainer::config->DATA_DIRECTORY + "dnsIpv6data.csv";

	printf("IPSMInterface [%d] Dumping Current IPv6 DNS Lookup Store to file [%s]...\n", instanceId, filePath.c_str());
	TheLog_nc_v2(Log::Info, name()," [%d] Dumping Current IPv6 DNS Lookup Store to file [%s]...", instanceId, filePath.c_str());

	fileHandler.open(filePath.c_str(), ios :: out);

	if(fileHandler.fail())
	{
		printf("IPSMInterface [%d] Error in Dumping Current IPv6 DNS Lookup Store File : %s\n",instanceId, filePath.c_str());
		TheLog_nc_v2(Log::Warn, name()," [%d] Error in Dumping Current IPv6 DNS Lookup Store to file [%s]...", instanceId, filePath.c_str());
	}
	else
	{
		for(auto elem : DNSGlobal::dnsV6LookUpMap)
			fileHandler << elem.first << "," << elem.second << endl;

		fileHandler.close();
		printf("IPSMInterface [%d] Dumping Current IPv6 DNS Lookup Store to file [%s]...Completed\n", instanceId, filePath.c_str());
		TheLog_nc_v2(Log::Info, name()," [%d] Dumping Current IPv6 DNS Lookup Store to file [%s]...Completed", instanceId, filePath.c_str());
		filePath.clear();
	}
}

VOID S1UInterface::TimeOutCleanSysLog(int hour)
{
	char fileName[50];
	fileName[0] = 0;
	int noOfRecords = 0;
	bool openFlag = false;

	sysLogCleanMap_cnt = 0;

	/*
	 * Open File for Dump
	 */
	sprintf(fileName, "%s_%02d.csv", "cgNetDump", hour);
		string filePath = "/opt/pinnacle/SpectaProbe/" + string(fileName);

	printf("IPSMInterface [%d] Dumping Hourly CGNET Data [%s]...\n", instanceId, filePath.c_str());
	TheLog_nc_v2(Log::Info, name()," Dumping Hourly CGNET Data [%s]...", instanceId, filePath.c_str());

	ofstream fileHandler;

	fileHandler.open(filePath.c_str(), ios :: out);

	if(fileHandler.fail()) {
		printf("IPSMInterface [%d] Error in Dumping Hourly CGNET Log : %s\n", instanceId, filePath.c_str());
		TheLog_nc_v2(Log::Warn, name()," [%d] Error in Dumping Hourly CGNET Log : %s", instanceId, filePath.c_str());
	}
	else
		openFlag = true;

	for(auto elem : sysLogGlobal::sysLogDB)
	{
		if(openFlag) {
			noOfRecords ++;
			fileHandler << elem.second.sourceInsideIp << "," << elem.second.sourceGlobalIp << endl;
		}

		sysLog *pSysLog = &elem.second;
		if((pSysLog->lastAccessTimeEpochSec > 0) && (pSysLog->lastAccessTimeEpochSec > 3600))
		{
			sysLogCleanVector.insert(sysLogCleanVector.end(), elem.first);
			sysLogCleanMap_cnt++;
		}
	}

	TheLog_nc_v1(Log::Info, name()," CleanUp SysLog Count [%u]", sysLogCleanMap_cnt);

	for(long i = 0; i < sysLogCleanMap_cnt; i++){
		sysLogGlobal::sysLogDB.erase(sysLogCleanVector[i]);
	}
	sysLogCleanVector.clear();
	sysLogCleanMap_cnt = 0;

	fileHandler.close();
	printf("IPSMInterface [%d] Dumping [%d] Hourly GCNET Log... Completed\n", instanceId, noOfRecords, filePath.c_str());
	TheLog_nc_v3(Log::Info, name()," [%d] Dumping [%d] Hourly GCNET Log... Completed", instanceId, noOfRecords, filePath.c_str());

	filePath.clear();
}

VOID S1UInterface::IPv4_DnsLoadLookUp()
{
	string filePath = GContainer::config->DATA_DIRECTORY + "dnsIpv4data.csv";

	std::string line;
	std::string url;
	uint32_t ip;
	int lineCnt = 0, loadedCnt = 0;
	char * 		pch;

	ifstream fp;

	fp.open(filePath.c_str());

	if(fp.fail())
	{
		printf("IPSMInterface [%d] Error in Loading IPv4 DNS Lookup file [%s]\n", instanceId, filePath.c_str());
		TheLog_nc_v2(Log::Warn, name(),"     [%d] Error in Loading IPv4 DNS Lookup file [%s]", instanceId, filePath.c_str());
	}
	else
	{
		while(!fp.eof())
		{
			getline(fp,line);
			if(!line.empty() && line.length() > 0)
			{
				lineCnt++;
				pch = strtok ((char *)line.c_str(), ",");
				ip = atol(pch);

				pch = strtok (NULL, ",");
				url = std::string(pch);

				if(ip > 0)
				{
					loadedCnt++;
					int index = ip % 10;
					switch(index)
					{
						case 0:
							DNSGlobal::dnsLookUpMap_0[ip] = url;
							break;
						case 1:
							DNSGlobal::dnsLookUpMap_1[ip] = url;
							break;
						case 2:
							DNSGlobal::dnsLookUpMap_2[ip] = url;
							break;
						case 3:
							DNSGlobal::dnsLookUpMap_3[ip] = url;
							break;
						case 4:
							DNSGlobal::dnsLookUpMap_4[ip] = url;
							break;
						case 5:
							DNSGlobal::dnsLookUpMap_5[ip] = url;
							break;
						case 6:
							DNSGlobal::dnsLookUpMap_6[ip] = url;
							break;
						case 7:
							DNSGlobal::dnsLookUpMap_7[ip] = url;
							break;
						case 8:
							DNSGlobal::dnsLookUpMap_8[ip] = url;
							break;
						case 9:
							DNSGlobal::dnsLookUpMap_9[ip] = url;
							break;
					}
				}
			}
		}
		fp.close();
	}

	printf("IPSMInterface [%02d]       Loaded [%10d] records in Dns IPv4 Lookup Map from file [%s] reading [%10d] lines\n",instanceId, loadedCnt, filePath.c_str(), lineCnt);
	TheLog_nc_v4(Log::Info, name(),"     [%d] Loaded [%d] records in Dns IPv4 Lookup Map from file [%s] reading [%d] lines",instanceId, loadedCnt, filePath.c_str(), lineCnt);
}

VOID S1UInterface::IPv6_DnsLoadLoopUp()
{
	string filePath = GContainer::config->DATA_DIRECTORY + "dnsIpv6data.csv";

	std::string line;
	std::string url;
	std::string ip;

	int lineCnt = 0, loadedCnt = 0;
	char * 		pch;

	ifstream fp;

	fp.open(filePath.c_str());

	if(fp.fail())
	{
		printf("IPSMInterface [%d] Error in Loading IPv6 DNS Lookup file [%s]\n", instanceId, filePath.c_str());
		TheLog_nc_v2(Log::Warn, name(),"     [%d]Error in Loading IPv6 DNS Lookup file [%s]", instanceId, filePath.c_str());
	}
	else
	{
		while(!fp.eof())
		{
			getline(fp,line);

			if(!line.empty() && line.length() > 0)
			{
				lineCnt++;
				pch = strtok ((char *)line.c_str(), ",");
				ip = std::string(pch);

				pch = strtok (NULL, ",");
				url = std::string(pch);

				DNSGlobal::dnsV6LookUpMap[ip] = url;
				loadedCnt ++;
			}
		}
		fp.close();
	}

	printf("IPSMInterface [%02d]       Loaded [%10d] records in Dns IPv6 Lookup Map from file [%s] reading [%10d] lines\n",instanceId, loadedCnt, filePath.c_str(), lineCnt);
	TheLog_nc_v4(Log::Info, name(),"     [%d]Loaded [%d] records in Dns IPv6 Lookup Map from file [%s] reading [%d] lines", instanceId, loadedCnt, filePath.c_str(), lineCnt);
}

VOID S1UInterface::IPv4_DnsLookUpCount()
{
	IPStats::dns_lookup_map_size = 0;
	IPStats::dns_lookup_map_size += DNSGlobal::dnsLookUpMap_0.size();
	IPStats::dns_lookup_map_size += DNSGlobal::dnsLookUpMap_1.size();
	IPStats::dns_lookup_map_size += DNSGlobal::dnsLookUpMap_2.size();
	IPStats::dns_lookup_map_size += DNSGlobal::dnsLookUpMap_3.size();
	IPStats::dns_lookup_map_size += DNSGlobal::dnsLookUpMap_4.size();
	IPStats::dns_lookup_map_size += DNSGlobal::dnsLookUpMap_5.size();
	IPStats::dns_lookup_map_size += DNSGlobal::dnsLookUpMap_6.size();
	IPStats::dns_lookup_map_size += DNSGlobal::dnsLookUpMap_7.size();
	IPStats::dns_lookup_map_size += DNSGlobal::dnsLookUpMap_8.size();
	IPStats::dns_lookup_map_size += DNSGlobal::dnsLookUpMap_9.size();

	TheLog_nc_v2(Log::Info, name(),"   DnsLookUp Size       IPv4: %08u | IPv6: %08u", IPStats::dns_lookup_map_size, DNSGlobal::dnsV6LookUpMap.size());
}

VOID S1UInterface::logStunSysLogUserDnsMapSize()
{
	TheLog_nc_v3(Log::Info, name(),"   Map Size             Stun: %08d | SysL: %08d | UDns: %08d", STUNMAP::stunMap.size(), sysLogGlobal::sysLogDB.size(), userDNS::userDnsMap.size());
}

VOID S1UInterface::IPv4_DnsDBCount()
{
	uint64_t	dns_ipv6_database_map_size = 0;

	IPStats::dns_resolved_lookup_size = 0;
	IPStats::dns_resolved_lookup_size += DNSGlobal::dnsDatabaseMap_0.size();
	IPStats::dns_resolved_lookup_size += DNSGlobal::dnsDatabaseMap_1.size();
	IPStats::dns_resolved_lookup_size += DNSGlobal::dnsDatabaseMap_2.size();
	IPStats::dns_resolved_lookup_size += DNSGlobal::dnsDatabaseMap_3.size();
	IPStats::dns_resolved_lookup_size += DNSGlobal::dnsDatabaseMap_4.size();
	IPStats::dns_resolved_lookup_size += DNSGlobal::dnsDatabaseMap_5.size();
	IPStats::dns_resolved_lookup_size += DNSGlobal::dnsDatabaseMap_6.size();
	IPStats::dns_resolved_lookup_size += DNSGlobal::dnsDatabaseMap_7.size();
	IPStats::dns_resolved_lookup_size += DNSGlobal::dnsDatabaseMap_8.size();
	IPStats::dns_resolved_lookup_size += DNSGlobal::dnsDatabaseMap_9.size();

	dns_ipv6_database_map_size = DNSGlobal::dnsV6DatabaseMap.size();

	TheLog_nc_v2(Log::Info, name(),"   DnsDatabase Size     IPv4: %08u | IPv6: %08u", IPStats::dns_resolved_lookup_size, dns_ipv6_database_map_size);
}
