/*
 * DnsData.cpp
 *
 *  Created on: 11-Jun-2016
 *      Author: debashis
 */

#include "DnsData.h"

using namespace std;

DnsData::DnsData()
{
	this->_name = "DnsData";
	this->setLogLevel(Log::theLog().level());
}

DnsData::~DnsData()
{}


void DnsData::storeDNSData(int idx, std::string key, uint32_t userip, uint32_t resolvedip, std::string url, int epochTimeSec, std::map<std::string, dnsUrl> &dnsMap)
{
	dnsUrl dnsurl;
	strcpy(dnsurl.URL, url.c_str());
	dnsurl.pckLastTimeEpcohSec = epochTimeSec;
	dnsMap[key] = dnsurl;
}

void DnsData::updateDns(std::string key, uint32_t userip, uint32_t resolvedip, std::string url, int epochTimeSec)
{
	std::string urlKey;
	int idx  = 0;

#if 0
	idx = userip % 10;

	switch(idx)
	{
		case 0:
				storeDNSData(idx, key, userip, resolvedip, url, epochTimeSec,  DNSGlobal::dnsDatabaseMap_0);
				break;

		case 1:
				storeDNSData(idx, key, userip, resolvedip, url, epochTimeSec, DNSGlobal::dnsDatabaseMap_1);
				break;

		case 2:
				storeDNSData(idx, key, userip, resolvedip, url, epochTimeSec, DNSGlobal::dnsDatabaseMap_2);
				break;

		case 3:
				storeDNSData(idx, key, userip, resolvedip, url, epochTimeSec, DNSGlobal::dnsDatabaseMap_3);
				break;

		case 4:
				storeDNSData(idx, key, userip, resolvedip, url, epochTimeSec, DNSGlobal::dnsDatabaseMap_4);
				break;

		case 5:
				storeDNSData(idx, key, userip, resolvedip, url, epochTimeSec, DNSGlobal::dnsDatabaseMap_5);
				break;

		case 6:
				storeDNSData(idx, key, userip, resolvedip, url, epochTimeSec, DNSGlobal::dnsDatabaseMap_6);
				break;

		case 7:
				storeDNSData(idx, key, userip, resolvedip, url, epochTimeSec, DNSGlobal::dnsDatabaseMap_7);
				break;

		case 8:
				storeDNSData(idx, key, userip, resolvedip, url, epochTimeSec, DNSGlobal::dnsDatabaseMap_8);
				break;

		case 9:
				storeDNSData(idx, key, userip, resolvedip, url, epochTimeSec, DNSGlobal::dnsDatabaseMap_9);
				break;
	}
#endif

	//Now update Dns Lookup Map
	idx = resolvedip % 10;
	switch(idx)
	{
		case 0:
				DNSGlobal::dnsLookUpMap_0[resolvedip] = std::string(url);
				break;

		case 1:
				DNSGlobal::dnsLookUpMap_1[resolvedip] = std::string(url);
				break;

		case 2:
				DNSGlobal::dnsLookUpMap_2[resolvedip] = std::string(url);
				break;

		case 3:
				DNSGlobal::dnsLookUpMap_3[resolvedip] = std::string(url);
				break;

		case 4:
				DNSGlobal::dnsLookUpMap_4[resolvedip] = std::string(url);
				break;

		case 5:
				DNSGlobal::dnsLookUpMap_5[resolvedip] = std::string(url);
				break;

		case 6:
				DNSGlobal::dnsLookUpMap_6[resolvedip] = std::string(url);
				break;

		case 7:
				DNSGlobal::dnsLookUpMap_7[resolvedip] = std::string(url);
				break;

		case 8:
				DNSGlobal::dnsLookUpMap_8[resolvedip] = std::string(url);
				break;

		case 9:
				DNSGlobal::dnsLookUpMap_9[resolvedip] = std::string(url);
				break;
	}
	/*Update User DNS only for Torrent */
	/* compare USER URL with Torrent Key word from Config */

#if 0
	for (int counter = 0; counter < IPGlobal::DnsKeyWord.size(); ++counter)
	{
		urlKey = IPGlobal::DnsKeyWord.at(counter);
		if (std::string(url).find(urlKey) != std::string::npos) {
			userDNS::userDnsMap[userip].urlInsertEpcohSec = epochTimeSec;
			strcpy(userDNS::userDnsMap[userip].URL, url.c_str());
			break;
		}
		urlKey.clear();
	}
#endif
}

string DnsData::getURL(string key, std::map<std::string, dnsUrl> &dnsMap)
{
	std::map<string, dnsUrl>::iterator itSp = dnsMap.find(key);

	if( itSp != dnsMap.end()) {
		dnsMap[itSp->first].pckLastTimeEpcohSec = (int)getCurrentEpochSeconds();
		return(itSp->second.URL);
	}
	return "";
}

string DnsData::getURLLookUp(uint32_t ip, std::map<uint32_t, std::string> &dnsMap)
{
	std::map<uint32_t, std::string>::iterator itSp = dnsMap.find(ip);

	if(itSp != dnsMap.end()) {
		return(itSp->second);
	}
	return "";
}

VOID DnsData::getDNSUrlForIP(std::string key, std::string& url, uint32_t sIp, uint32_t dIp)
{
	int index = 0;
#if 0
	index = sIp % 10;

	switch(index)
	{
		case 0:
				url = getURL(key, DNSGlobal::dnsDatabaseMap_0);
				break;

		case 1:
				url = getURL(key, DNSGlobal::dnsDatabaseMap_1);
				break;

		case 2:
				url = getURL(key, DNSGlobal::dnsDatabaseMap_2);
				break;

		case 3:
				url = getURL(key, DNSGlobal::dnsDatabaseMap_3);
				break;

		case 4:
				url = getURL(key, DNSGlobal::dnsDatabaseMap_4);
				break;

		case 5:
				url = getURL(key, DNSGlobal::dnsDatabaseMap_5);
				break;

		case 6:
				url = getURL(key, DNSGlobal::dnsDatabaseMap_6);
				break;

		case 7:
				url = getURL(key, DNSGlobal::dnsDatabaseMap_7);
				break;

		case 8:
				url = getURL(key, DNSGlobal::dnsDatabaseMap_8);
				break;

		case 9:
				url = getURL(key, DNSGlobal::dnsDatabaseMap_9);
				break;
	}

#endif

	//If not found search in our global look up unordered_map
	index = dIp % 10;
	switch(index)
	{
		case 0:
				url = getURLLookUp(dIp, DNSGlobal::dnsLookUpMap_0);
				break;

		case 1:
				url = getURLLookUp(dIp, DNSGlobal::dnsLookUpMap_1);
				break;

		case 2:
				url = getURLLookUp(dIp, DNSGlobal::dnsLookUpMap_2);
				break;

		case 3:
				url = getURLLookUp(dIp, DNSGlobal::dnsLookUpMap_3);
				break;

		case 4:
				url = getURLLookUp(dIp, DNSGlobal::dnsLookUpMap_4);
				break;

		case 5:
				url = getURLLookUp(dIp, DNSGlobal::dnsLookUpMap_5);
				break;

		case 6:
				url = getURLLookUp(dIp, DNSGlobal::dnsLookUpMap_6);
				break;

		case 7:
				url = getURLLookUp(dIp, DNSGlobal::dnsLookUpMap_7);
				break;

		case 8:
				url = getURLLookUp(dIp, DNSGlobal::dnsLookUpMap_8);
				break;

		case 9:
				url = getURLLookUp(dIp, DNSGlobal::dnsLookUpMap_9);
				break;
	}
}

VOID DnsData::updateDnsV6(std::string key, string userip, string resolvedip, string url, int epochTimeSec)
{

	dnsV6Url dnsv6url;

	strcpy(dnsv6url.address, resolvedip.c_str());
	strcpy(dnsv6url.URL, url.c_str());
	dnsv6url.pckLastTimeEpcohSec = epochTimeSec;

	DNSGlobal::dnsV6DatabaseMap[key] = dnsv6url;
	return;

	//Now update Dns Lookup Map
	DNSGlobal::dnsV6LookUpMap[string(resolvedip)] = std::string(url);
}

void DnsData::getDNSV6UrlForIP(std::string key, std::string& url, char *sIp, char *dIp)
{
//	std::unordered_map<string, dnsV6Url>::iterator itSp = DNSGlobal::dnsV6DatabaseMap.find(key);
//	if( itSp != DNSGlobal::dnsV6DatabaseMap.end())
//	{
//		DNSGlobal::dnsV6DatabaseMap[itSp->first].pckLastTimeEpcohSec = getCurrentEpochSeconds();
//		url = itSp->second.URL;
//		return;
//	}

	//If not found search in our global look up unordered_map

	std::unordered_map<string, string>::iterator itSp1 = DNSGlobal::dnsV6LookUpMap.find(std::string(dIp));
	if( itSp1 != DNSGlobal::dnsV6LookUpMap.end())
	{
		url = itSp1->second;
		return;
	}
}

string DnsData::getDNSKey(uint32_t destAddrLong, uint32_t sourceAddrLong)
{
	char dnsKey[25];
	sprintf(dnsKey,"%010u-%010u", destAddrLong, sourceAddrLong);
	return std::string(dnsKey);
}

string DnsData::getSysLogKey(uint32_t globalIp, int globalPort, int protocol)
{
	char sysLogKey[25];
	sprintf(sysLogKey,"%010u%05d%02d", globalIp, globalPort, protocol);
	return std::string(sysLogKey);
}
