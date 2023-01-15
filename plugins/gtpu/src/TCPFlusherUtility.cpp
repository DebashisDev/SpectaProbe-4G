/*
  * TCPFlusherUtility.cpp
 *
 *  Created on: Dec 21, 2016
 *      Author: Deb
 */

#include <netinet/in.h>
#include <netinet/ip6.h>
#include <arpa/inet.h>
#include <string.h>

#include "TCPFlusherUtility.h"

TCPFlusherUtility::TCPFlusherUtility(int instanceId) {

	if(instanceId == 0)
	{
		ipProtocol::ipProtocolMap.insert(std::pair<uint32_t, std::string>(6, "TCP"));
		ipProtocol::ipProtocolMap.insert(std::pair<uint32_t, std::string>(17, "UDP"));
		ipProtocol::ipProtocolMap.insert(std::pair<uint32_t, std::string>(1812, "RADIUS-AUTH"));
		ipProtocol::ipProtocolMap.insert(std::pair<uint32_t, std::string>(31812, "RADIUS-AUTH"));
		ipProtocol::ipProtocolMap.insert(std::pair<uint32_t, std::string>(1813, "RADIUS-ACCO"));
		ipProtocol::ipProtocolMap.insert(std::pair<uint32_t, std::string>(31813, "RADIUS-ACCO"));
	}
	this->_name = "PacketRouter";
	this->setLogLevel(Log::theLog().level());

}

TCPFlusherUtility::~TCPFlusherUtility()
{  }

VOID TCPFlusherUtility::lockDnsMap() {
	pthread_mutex_lock(&dnsSessionLock::lockCount);
	while (dnsSessionLock::count == 0)
		pthread_cond_wait(&dnsSessionLock::nonzero, &dnsSessionLock::lockCount);
	dnsSessionLock::count = dnsSessionLock::count - 1;
	pthread_mutex_unlock(&dnsSessionLock::lockCount);
}

VOID TCPFlusherUtility::unLockDnsMap() {
    pthread_mutex_lock(&dnsSessionLock::lockCount);
    if (dnsSessionLock::count == 0)
        pthread_cond_signal(&dnsSessionLock::nonzero);
    dnsSessionLock::count = dnsSessionLock::count + 1;
    pthread_mutex_unlock(&dnsSessionLock::lockCount);
}

VOID TCPFlusherUtility::lockS11Map()
{
	pthread_mutex_lock(&s11SessionLock::lockCount);
	while (s11SessionLock::count == 0){
		pthread_cond_wait(&s11SessionLock::nonzero, &s11SessionLock::lockCount);
	}
	s11SessionLock::count = s11SessionLock::count - 1;
	pthread_mutex_unlock(&s11SessionLock::lockCount);
}

VOID TCPFlusherUtility::unLockS11Map()
{
    pthread_mutex_lock(&s11SessionLock::lockCount);
    if (s11SessionLock::count == 0)
        pthread_cond_signal(&s11SessionLock::nonzero);
    s11SessionLock::count = s11SessionLock::count + 1;
    pthread_mutex_unlock(&s11SessionLock::lockCount);
}


VOID TCPFlusherUtility::getVolPerSec(ipSession *pIpSession, char *dnVolPerSec, char *upVolPerSec) {
	char timeBuffer[100];
	bool printUpvps = false;
	bool printDnvps = false;
	uint32_t volume, c_pickThrPut, f_pickThrPut;
	uint32_t c_up_pickThrPut, f_up_pickThrPut, c_dn_pickThrPut, f_dn_pickThrPut;
	uint32_t upvolume, dnvolume;
	uint32_t tcpUpPacket, tcpDnPacket;
	uint16_t tcpUpCount, tcpDnCount;

	uint32_t timeDiff = 0;

	upvolume = dnvolume = 0;
	tcpUpPacket = tcpDnPacket = 0;
	tcpUpCount = tcpDnCount = 0;
	uint32_t firstSec = 0;

	int packetCount = 0;
	volume = c_pickThrPut = f_pickThrPut = 0;
	c_up_pickThrPut = f_up_pickThrPut = c_dn_pickThrPut = f_dn_pickThrPut = 0;

	for(int i = 0; i < 10000; i++)
		vpsTimeKeys[i] = 0;

	for(auto elem = pIpSession->packTimeMap.begin(), next_elem = elem; elem != pIpSession->packTimeMap.end(); elem = next_elem)
	{
		++next_elem;

		packetCount ++;
		vpsTimeKeys[packetCount] = elem->first;
		volume = elem->second.totalVolume;
		upvolume = elem->second.upVolume;
		dnvolume = elem->second.dnVolume;

		c_pickThrPut = volume;
		if (c_pickThrPut > f_pickThrPut)
			f_pickThrPut = c_pickThrPut;

		if(upvolume > 0) {
			tcpUpCount += 1;
			tcpUpPacket = elem->second.upPackets;
			upvolume = elem->second.upVolume;
			c_up_pickThrPut = upvolume;
			if (c_up_pickThrPut > f_up_pickThrPut)
				f_up_pickThrPut = c_up_pickThrPut;
		}

		if(dnvolume > 0){
			tcpDnCount += 1;
			tcpDnPacket = elem->second.dnPackets;
			dnvolume = elem->second.dnVolume;
			c_dn_pickThrPut = dnvolume;
			if (c_dn_pickThrPut > f_dn_pickThrPut)
				f_dn_pickThrPut = c_dn_pickThrPut;
		}

		if(packetCount == 1 ) {
			firstSec = elem->first;
			dnVolPerSec[0] = 0;
			upVolPerSec[0] = 0;

			sprintf(dnVolPerSec, "%u=", firstSec);
			sprintf(upVolPerSec, "%u=", firstSec);
		}

		if(dnvolume > 0)
		{
			if(strlen(dnVolPerSec) < (VPS_MAX_LEN - VPS_SINGLE_ELEMENT_SIZE))
			{
				timeDiff = elem->first - firstSec;
				if(timeDiff >= 0) { // Checking the TP
					timeBuffer[0] = 0;
					sprintf(timeBuffer, "%d#%u#%u;", timeDiff, tcpDnPacket, dnvolume);	//Volume only, keep in Bytes
					strcat(dnVolPerSec, timeBuffer);
					timeBuffer[0] = 0;
					printDnvps = true;
				}
			}
		}

		if(upvolume > 0)
		{
			if(strlen(upVolPerSec) < (VPS_MAX_LEN - VPS_SINGLE_ELEMENT_SIZE))
			{
				timeDiff = elem->first - firstSec;
				if(timeDiff >= 0)
				{
					timeBuffer[0] = 0;
					sprintf(timeBuffer, "%d#%u#%u;", timeDiff, tcpUpPacket, upvolume);	//Volume only, keep in Bytes
					strcat(upVolPerSec, timeBuffer);
					timeBuffer[0] = 0;
					printUpvps = true;
				}
			}
		}
		dnvolume = upvolume = 0;
		pIpSession->packTimeMap.erase(elem);
	}

	pIpSession->pckTotalTimeSec = tcpUpCount + tcpDnCount;

	for(int i=0; i <= packetCount; i++)
	{
		pIpSession->packTimeMap[vpsTimeKeys[i]].reset();
		pIpSession->packTimeMap.erase(vpsTimeKeys[i]);
		vpsTimeKeys[i] = 0;
	}

	pIpSession->packTimeMap.clear();

	if(tcpDnCount == 0 || printDnvps == false)
		strcpy(dnVolPerSec, "NULL");

	if(tcpUpCount == 0 || printUpvps == false)
		strcpy(upVolPerSec, "NULL");


	/* Pick Throughput / Sec */
	pIpSession->peakSessionTP 	= f_pickThrPut * 8;		//Converting to bits per second
	pIpSession->upPeakSessionTP = f_up_pickThrPut * 8;	//Converting to bits per second
	pIpSession->dnPeakSessionTP = f_dn_pickThrPut * 8;	//Converting to bits per second

	if(packetCount > 0 && pIpSession->frameSize > 0)
		pIpSession->sessionTP = (pIpSession->frameSize * 8) / packetCount;		//Converting to bps
	else
		pIpSession->sessionTP = 0;

	if(tcpUpPacket > 0 && pIpSession->upFrameSize > 0)
		pIpSession->upSessionTP = (pIpSession->upFrameSize * 8) / tcpUpCount;	//Converting to bps
	else
		pIpSession->upSessionTP = 0;

	if(tcpDnPacket > 0 && pIpSession->dnFrameSize > 0)
		pIpSession->dnSessionTP = (pIpSession->dnFrameSize * 8) / tcpDnCount;	//Converting to bps
	else
		pIpSession->dnSessionTP = 0;

	if(!f_dn_pickThrPut)
		pIpSession->dnPeakSessionTP = pIpSession->dnSessionTP;

	if(!f_up_pickThrPut)
		pIpSession->upPeakSessionTP = pIpSession->upSessionTP;

}

VOID TCPFlusherUtility::buildIPXdr(ipSession *pIpSession, char *xdr)
{
	xdr[0] = 0;
	GTPInfo *gtpInfo = new GTPInfo();

	char dnVolPerSec[VPS_MAX_LEN];
	char upVolPerSec[VPS_MAX_LEN];
	char protoDesc[10];

	getVolPerSec(pIpSession, dnVolPerSec, upVolPerSec);

	if((strcmp(dnVolPerSec, "NULL") == 0) && (pIpSession->dnPayloadSize > 0)) return;
	if((strcmp(upVolPerSec, "NULL") == 0) && (pIpSession->upPayloadSize > 0)) return;

	switch(pIpSession->ipVer)
	{
		case IPVersion4:
					if(strlen(pIpSession->URL) == 0) getDnsData(pIpSession);

					long2Ip(pIpSession->sourceIpAddrLong, pIpSession->sourceIpAddrChar);
					long2Ip(pIpSession->destIpAddrLong, pIpSession->destIpAddrChar);

					if(pIpSession->protocolType == 6)
						strcpy(protoDesc, "TCP");
					else if(pIpSession->protocolType == 17)
						strcpy(protoDesc, "UDP");

					break;

		default:
				return;
				break;
	}

	lockS11Map();
	getGtpData(pIpSession, gtpInfo);
	unLockS11Map();

	if(!someChecks(pIpSession)) return;


	sprintf(xdr, 	 "%d,%d,%d,%s,"				// 01- Probe Id,       02- XDR Id, 		       03- Protocol Type,     04- Protocol Desc,
					 "%d,%lu-%d,"				// 05- Dest Port,      06- Session Key,
					 "%s,%s,"					// 07- Source Mac,     08- Dest Mac,
					 "%s,%d,%s,%d,"				// 09- Source Ip,      10- Source Port,        11- Dest Ip,           12- Dest Port,
					 "%d,%d,"					// 13- VLAN Id, 	   14- Slice Counter,
					 "%d,%d,%d,"				// 15- Frame Cnt,      16- Up Frame Cnt,       17- Dn Frame Cnt,
					 "%u,%u,%u,"				// 18- Frame Size,     19- Up Frame Size,      20- Dn Frame Size,
					 "%d,%d,%d,"				// 21- Payload Pkt,    22- Up Payload Pkt,     23- Dn Payload Pkt,
					 "%u,%u,%u,"				// 24- Payload Size,   25- Up Payload Size,    26- Dn Payload Size,
					 "%llu,%llu,%d,"			// 27- Start Time,     28- End Time,           29- Pkt Total Time,
					 "%s,%s,%s,%d,%d,%d,%d,"	// 30- IMEI			   31- IMSI,			   32- MSISDN			  33- Rat		34- MCC		35- NMC 	36- LAC
					 "%u,%u,"					// 37- Session TP,     38- Peak Session TP,
					 "%u,%u,%u,%u,"				// 39- Up Session TP,  40- Up Session Peak TP, 41- Dn Session TP,     42- Dn Session Peak TP,
					 "%u,%d,%s,%s,"				// 43- Syn Latency,	   44- Cause Code,         45- Content Type,      46- Dn Vol/Sec,
					 "%d,%llu,"					// 47- SynRcv,         48- SynRcv Nano Sec,
					 "%d,%llu,"					// 49- SynAckRcv,      50- SynAckRcv Nano Sec,
					 "%d,%llu,"					// 51- DataRcv,        52- DataRcv Nano Sec,
					 "%d,%llu,"					// 53- FinRcv,         54- FinRcv Nano Sec,
					 "%s,%u,%s,"				// 55- Up Vol/Sec,     56- App Ip, 				57- URL,
					 "%d,%u,%d,%d,"				// 58- Flush Id		   59- Flush time		    60- TTL			     61- Session Id
					 "%s,"						// 62- User-Agent
					 "%d,%d,%d,%d,"				// 63- ReTransmission  64- layer3LoopCnt		65- duplicateCnt	 66- totalFrameCount
					 "%d,%llu",		    		// 67- ackRcv          68- Ack Nano Sec

				IPGlobal::PROBE_ID, XDR_ID_IP_SESSION, pIpSession->protocolType, protoDesc,
				pIpSession->destPort, pIpSession->sessionKey, pIpSession->sliceCounter,
				pIpSession->sourceMacAddr, pIpSession->destMacAddr,
				pIpSession->sourceIpAddrChar, pIpSession->sourcePort, pIpSession->destIpAddrChar, pIpSession->destPort,
				pIpSession->vLanId, pIpSession->sliceCounter,
				pIpSession->frameCount, pIpSession->upFrameCount, pIpSession->dnFrameCount,
				pIpSession->frameSize, pIpSession->upFrameSize, pIpSession->dnFrameSize,
				pIpSession->payloadPacket, pIpSession->upPayloadPacket, pIpSession->dnPayloadPacket,
				pIpSession->payloadSize, pIpSession->upPayloadSize, pIpSession->dnPayloadSize,
				pIpSession->startTimeEpochNanoSec, pIpSession->endTimeEpochNanoSec, pIpSession->pckTotalTimeSec,
				gtpInfo->imei, gtpInfo->imsi, gtpInfo->msisdn, gtpInfo->rat, gtpInfo->mcc, gtpInfo->mnc, gtpInfo->lac,
				pIpSession->sessionTP, pIpSession->peakSessionTP,
				pIpSession->upSessionTP, pIpSession->upPeakSessionTP, pIpSession->dnSessionTP, pIpSession->dnPeakSessionTP,
				0, pIpSession->causeCode, "NULL", dnVolPerSec,
				pIpSession->synRcv, pIpSession->synTimeEpochNanoSec,
				pIpSession->synAckRcv, pIpSession->synAckTimeEpochNanoSec,
				pIpSession->dataRcv, pIpSession->firstDataTimeEpochNanoSec,
				pIpSession->finRcv, pIpSession->finTimeEpochNanoSec,
				upVolPerSec, pIpSession->appIp, pIpSession->URL,
				pIpSession->flushOrgId, pIpSession->flushTime, pIpSession->TTL, pIpSession->smInstanceId,
				pIpSession->httpAgent,
				pIpSession->reTransmissionCnt, pIpSession->layer3LoopCnt, pIpSession->duplicateCnt, pIpSession->totalFrameCount,
				pIpSession->ackRcv, pIpSession->ackTimeEpochNanoSec);

	delete(gtpInfo);
}

VOID TCPFlusherUtility::getGtpData(ipSession *pIpSession, GTPInfo *gtpInfo)
{
	GTPSession *pGlbSession = NULL;

	if(pGlbSession == NULL)
	{
		if(pIpSession->teid_up > 0)
			pGlbSession = S11_GlobalLookup(pIpSession->teid_up);

		if(pGlbSession == NULL)
		{
			if(pIpSession->teid_dn > 0)
				pGlbSession = S11_GlobalLookup(pIpSession->teid_dn);
		}

		if(pGlbSession != NULL)
		{
			strcpy(gtpInfo->imsi, pGlbSession->IMSI);
			strcpy(gtpInfo->msisdn, pGlbSession->MSISDN);
			strcpy(gtpInfo->imei, pGlbSession->IMEI);
			gtpInfo->rat = pGlbSession->RAT;
			gtpInfo->mcc = pGlbSession->MCC;
			gtpInfo->mnc = pGlbSession->MNC;
			gtpInfo->lac = pGlbSession->LAC;
			pIpSession->activeState = pGlbSession->active_session;
		}
	}
}

GTPSession* TCPFlusherUtility::S11_GlobalLookup(const uint32_t tunnelId)
{
	uint32_t teidIndex = INDEX_TEID(tunnelId);

	std::map<uint32_t, int>::iterator itr;

	itr = GTPStore::S11_GlbSgwBeaIndexPool[teidIndex].find(tunnelId);
	if (itr != GTPStore::S11_GlbSgwBeaIndexPool[teidIndex].end())
	{
		int arrid = itr->second / S11_SESSION_POOL_ARRAY_ELEMENTS;
		int elemid = itr->second % S11_SESSION_POOL_ARRAY_ELEMENTS;

		return GTPStore::S11_GlbSessionPool[arrid][elemid];
	}

	itr = GTPStore::S11_GlbeNBBeaIndexPool[teidIndex].find(tunnelId);
	if (itr != GTPStore::S11_GlbeNBBeaIndexPool[teidIndex].end())
	{
		int arrid = itr->second / S11_SESSION_POOL_ARRAY_ELEMENTS;
		int elemid = itr->second % S11_SESSION_POOL_ARRAY_ELEMENTS;

		return GTPStore::S11_GlbSessionPool[arrid][elemid];
	}
	return (NULL);
}


BOOL TCPFlusherUtility::someChecks(ipSession *pIpSession)
{
	BOOL xdrProcess = true;

	if(strlen(pIpSession->httpAgent) == 0) strcpy(pIpSession->httpAgent, "NA");

	/* These Checkes are for Spike in TP */
	if(pIpSession->frameSize < pIpSession->payloadSize)
	{
		xdrProcess = false;
		return xdrProcess;
	}

	if(pIpSession->protocolType == PACKET_IPPROTO_TCP)
	{
		if(!pIpSession->synRcv)
		{
			pIpSession->synRcv = true;
			pIpSession->synTimeEpochNanoSec = pIpSession->startTimeEpochNanoSec;
		}

		if((pIpSession->synAckRcv) && (!pIpSession->ackRcv))
		{
			pIpSession->ackRcv = true;
			pIpSession->ackTimeEpochNanoSec = pIpSession->synAckTimeEpochNanoSec + 10;
		}
		else if((!pIpSession->synAckRcv) && (pIpSession->ackRcv))
		{
			pIpSession->synAckRcv = true;
			pIpSession->synAckTimeEpochNanoSec = pIpSession->synTimeEpochNanoSec + 10;
		}
		else if((!pIpSession->synAckRcv) && (!pIpSession->ackRcv))
		{
			pIpSession->synAckRcv = true;
			pIpSession->synAckTimeEpochNanoSec = pIpSession->synTimeEpochNanoSec + 10;
			pIpSession->ackRcv = true;
			pIpSession->ackTimeEpochNanoSec = pIpSession->synAckTimeEpochNanoSec + 10;
		}

		if(pIpSession->dataRcv)
			swap4(&pIpSession->synTimeEpochNanoSec, &pIpSession->synAckTimeEpochNanoSec, &pIpSession->ackTimeEpochNanoSec, &pIpSession->firstDataTimeEpochNanoSec);
		else
			swap3(&pIpSession->synTimeEpochNanoSec, &pIpSession->synAckTimeEpochNanoSec, &pIpSession->ackTimeEpochNanoSec);

		}
	return xdrProcess;
}

VOID TCPFlusherUtility::swap3(uint128_t *a, uint128_t *b, uint128_t *c)
{
	uint128_t lr, mi, sm;

	if(*a > *b)
	{
		mi = *a;
		sm = *b;
	}
	else
	{
		mi = *b;
		sm = *a;
	}

	if(mi > *c)
	{
		lr = mi;
		if(sm > *c)
		{
			mi = sm;
			sm = *c;
		}
		else
		{
			mi = *c;
		}
	}
	else
		lr = *c;

	*a = sm;
	*b = mi;
	*c = lr;
}

VOID TCPFlusherUtility::swap4(uint128_t *a, uint128_t *b, uint128_t *c, uint128_t *d)
{
	uint128_t temp = 0; ;

	if(*a > *b)
	{
		temp = *a;
		*a = *b;
		*b = temp;
	}
	if(*c > *d)
	{
		temp = *c;
		*c = *d;
		*d = temp;
	}
	if(*a > *c)
	{
		temp = *a;
		*a = *c;
		*c = temp;
	}
	if(*b > *d)
	{
		temp = *b;
		*b = *d;
		*d = temp;
	}
	if(*b > *c)
	{
		temp = *b;
		*b = *c;
		*c = temp;
	}
}


VOID TCPFlusherUtility::getDnsData(ipSession *pIpSession)
{
	std::string URL;
	std::string userIP_resolveIP_key;

	lockDnsMap();
	getDNSUrlForIP(userIP_resolveIP_key, URL, pIpSession->sourceIpAddrLong, pIpSession->destIpAddrLong);
	unLockDnsMap();

	if(!URL.length())
		strcpy(pIpSession->URL, "NULL");
	else
		strcpy(pIpSession->URL, URL.c_str());

}

VOID TCPFlusherUtility::buildDnsCsvBuffer(dnsSession *pDnsSession, char *csvXDR)
{
	uint32_t dnsResTimeMilliSec = 0;

	GTPInfo *gtpInfo = new GTPInfo();

	uint32_t userIp = 0;
	BOOL writeXDRFlag = true;
	std::size_t found;
	uint32_t resolvedIp = 0;

	uint128_t sTime = pDnsSession->queryStartEpochNanoSec;
	uint128_t eTime = pDnsSession->queryEndEpochNanoSec;

	csvXDR[0] = 0;

	if(eTime > 0 && sTime > 0 && (eTime > sTime))
	{
		if(sTime > 1000000) {
			sTime = sTime / (1000 * 1000);
			if(eTime > 1000000) {
				eTime = eTime / (1000 * 1000);
				dnsResTimeMilliSec = (uint32_t) (eTime - sTime);
			}
		}
	}

	lockS11Map();
	getGtpDnsData(pDnsSession, gtpInfo);
	unLockS11Map();

	switch(pDnsSession->ipVer)
	{
		case IPVersion4:
						/* Change Source and Destination IP Long to dotted IP */
						long2Ip(pDnsSession->sourceIpAddrLong, pDnsSession->sourceIpAddrChar);
						long2Ip(pDnsSession->destIpAddrLong, pDnsSession->destIpAddrChar);
						break;

		default:
						return;
						break;
	}

	if(strlen(pDnsSession->URL) == 0)
		strcpy(pDnsSession->URL, "NA");

	if(strstr(pDnsSession->errorDesc, "No Error") != NULL)
		pDnsSession->errorCode = 0;

	sprintf(csvXDR, "%d,%d,17,DNS,"			// 01- Probe Id			02- XDR Id			03- UDP				04- DNS
					"%s,%d,%s,%d,"			// 05- Source Ip		06- Source Port		07- Dest Ip			08- Dest Port
					"%s,%s,%s,%d,%d,%d,%d,"	// 09- IMEI				10- IMSI			11- MSISDN			12- MCC			13- MNC		14- RAT		15- LAC
					"%s,%d,%s,"				// 16- URL				17- Error Code		18- Error Desc
					"%u,%lu,%lu,"			// 19- Address			20- Start Time		21- End Time
					"%u,%u,%u",				// 22- Resolve Time		23- Flush Type		24- DNS Key
					IPGlobal::PROBE_ID, XDR_ID_IP_DNS_SESSION,
					pDnsSession->sourceIpAddrChar, pDnsSession->sourcePort, pDnsSession->destIpAddrChar, pDnsSession->destPort,
					gtpInfo->imei, gtpInfo->imsi, gtpInfo->msisdn, gtpInfo->mcc, gtpInfo->mnc, gtpInfo->rat, gtpInfo->lac,
					pDnsSession->URL, pDnsSession->errorCode, pDnsSession->errorDesc,
					pDnsSession->address, pDnsSession->queryStartEpochNanoSec, pDnsSession->queryEndEpochNanoSec,
					dnsResTimeMilliSec, pDnsSession->flushType, pDnsSession->dnsSessionKey);

	delete(gtpInfo);
}

VOID TCPFlusherUtility::getGtpDnsData(dnsSession *pDnsSession, GTPInfo *gtpInfo)
{
	GTPSession *pGlbSession = NULL;

	if(pGlbSession == NULL)
	{
		if(pDnsSession->teid_up > 0)
			pGlbSession = S11_GlobalLookup(pDnsSession->teid_up);

		if(pGlbSession == NULL)
		{
			if(pDnsSession->teid_dn > 0)
				pGlbSession = S11_GlobalLookup(pDnsSession->teid_dn);
		}

		if(pGlbSession != NULL)
		{
			strcpy(gtpInfo->imsi, pGlbSession->IMSI);
			strcpy(gtpInfo->msisdn, pGlbSession->MSISDN);
			strcpy(gtpInfo->imei, pGlbSession->IMEI);
			gtpInfo->rat = pGlbSession->RAT;
			gtpInfo->mcc = pGlbSession->MCC;
			gtpInfo->mnc = pGlbSession->MNC;
			gtpInfo->lac = pGlbSession->LAC;
		}
	}
}
