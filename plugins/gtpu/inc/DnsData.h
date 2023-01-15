/*
 * DnsData.h
 *
 *  Created on: 11-Jun-2016
 *      Author: deb
 */

#ifndef INC_DNSDATA_H_
#define INC_DNSDATA_H_

#include <string.h>    //strlen
#include <string>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>

#include "IPGlobal.h"
#include "Log.h"

#include "GConfig.h"
#include "BaseConfig.h"
#include "TCPUDPGlobal.h"

class DnsData : public BaseConfig {
	private:
		VOID	lockDnsMap();
		VOID	unLockDnsMap();

	public:
		DnsData();
		~DnsData();

		void 		updateDns(std::string key, uint32_t userip, uint32_t resolvedip, std::string url, int epochTimeSec);
		VOID 		getDNSUrlForIP(std::string str, std::string& url, uint32_t sIp, uint32_t dIp);
		string 		getDNSKey(uint32_t destAddrLong, uint32_t sourceAddrLong);
		string 		getSysLogKey(uint32_t destAddrLong, int globalPort, int protocol);
		VOID 		updateDnsV6(std::string key, string userip, string resolvedip, string url, int epochTimeSec);
		void 		getDNSV6UrlForIP(std::string str, std::string& url, char* sIp, char* dIp);
		void 		storeDNSData(int idx, std::string key, uint32_t userip, uint32_t resolvedip, std::string url, int epochTimeSec, std::map<std::string, dnsUrl> &dnsMap);
		std::string	getURL(string key, std::map<std::string, dnsUrl> &dnsMap);
		string		getURLLookUp(uint32_t ip, std::map<uint32_t, std::string> &dnsMap);
};

#endif /* INC_DNSDATA_H_ */
