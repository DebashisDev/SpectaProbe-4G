/*
 * IPSMCounters.h
 *
 *  Created on: 06-Dec-2017
 *      Author: Deb
 */

#ifndef PLUGINS_TCP_SRC_IPSMCOUNTERS_H_
#define PLUGINS_TCP_SRC_IPSMCOUNTERS_H_

#include "Log.h"
#include "BaseConfig.h"

class IPSMCounters : BaseConfig{
	public:
		IPSMCounters();
		~IPSMCounters();

		int getIPSessionPktCountForIndex(int smid, int idx);
		void checkPktLimitOfSM(int instanceId);

	private:
		int maxPktLimitPerSM = 0;
};

#endif /* PLUGINS_TCP_SRC_IPSMCOUNTERS_H_ */
