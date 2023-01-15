/*
 * SpectaProbe.h
 *
 *  Created on: 29-Jan-2016
 *      Author: Debashis
 */

#ifndef SRC_SPECTAPROBE_H_
#define SRC_SPECTAPROBE_H_

#include <signal.h>
#include <string.h>
#include <string>
#include <time.h>
#include <sys/time.h>

#include "S11SessionManager.h"
#include "S5S8SessionManager.h"
#include "SctpSessionManager.h"
#include "S1USessionManager.h"
#include "GTPv2Message.h"
#include "GTPv2Initialize.h"

#include "PacketListener.h"
#include "EthernetSource.h"
#include "SpectaTypedef.h"
#include "BaseConfig.h"
#include "GConstant.h"
#include "ProbeStats.h"
#include "ProbeStatsLog.h"

#include "AdminPortReader.h"
#include "zmqPush.h"
#include "glbTimer.h"
#include "PacketRouter.h"
#include "Log.h"

#include "S1APFlusher.h"
#include "S1APXdrWriter.h"
#include "S11Flusher.h"
#include "S11XdrWriter.h"
#include "S5S8Flusher.h"
#include "S5S8XdrWriter.h"
#include "S1UFlusher.h"
#include "S1UXdrWriter.h"

class SpectaProbe : public BaseConfig
{
	private:

		timeval curTime;
		struct tm *now_tm;

#ifdef _S11
		GTPv2Message *gtpcv2msg;
		GTPv2Initialize	*gtpcv2init;
#endif
		VOID 	pinThread(pthread_t th,int i);

		VOID 	startInterface();
		VOID 	readIPRange();

		VOID 	initializePktRepo();

		VOID 	initialize_pkt_repo_i_0();
		VOID 	initialize_pkt_repo_i_1();
		VOID 	initialize_pkt_repo_i_2();
		VOID 	initialize_pkt_repo_i_3();
		VOID 	initialize_pkt_repo_i_4();
		VOID 	initialize_pkt_repo_i_5();
		VOID 	initialize_pkt_repo_i_6();
		VOID 	initialize_pkt_repo_i_7();

		VOID 	process();
		VOID 	initializeLog();
		VOID	initializeLocks();

		VOID 	initializeConfig();
		VOID 	readConfiguration();
		bool 	isRepositoryInitialized();

		VOID 	startTimer();
		VOID 	startS1MMESessionManager();
		VOID 	startS1MMEFlusher();
		VOID 	startS1MMEXdrWriter();
		VOID 	startS11SessionManager();
		VOID 	startS11Flusher();
		VOID 	startS11XdrWriter();
		VOID 	startS5S8SessionManager();
		VOID 	startS5S8Flusher();
		VOID 	startS5S8XdrWriter();
		VOID 	startS1USessionManager();
		VOID 	startS1UFlusher();
		VOID 	startS1UXdrWriter();
		VOID 	startRouters();
		VOID 	startPacketListener();
		VOID 	openAdminPort();
		VOID 	openLogFile();
		VOID 	writeStats();
		VOID 	initializeGtpValues();

	public:
		SpectaProbe(char *fileName);
		~SpectaProbe();

		VOID 	start();
};

#endif /* SRC_SPECTAPROBE_H_ */
