/*
 * ProbeStats.h
 *
 *  Created on: Feb 1, 2017
 *      Author: Debashis
 */

#ifndef CORE_SRC_PROBESTATS_H_
#define CORE_SRC_PROBESTATS_H_

#include <unistd.h>
#include <locale.h>
#include <time.h>
#include <sys/time.h>

#include "IPGlobal.h"
#include "SpectaTypedef.h"
#include "Log.h"

#include "S1APGlobal.h"
#include "GTPGlobal.h"
#include "TCPUDPGlobal.h"

class ProbeStats
{
	public:
		ProbeStats();
		~ProbeStats();

		VOID run();

	private:
		timeval curTime;
		struct tm *now_tm;

		void printInterfaceStats(char *runTime);
		VOID printPktStoreStats_i_0();
		VOID printPktStoreStats_i_1();
		VOID printPktStoreStats_i_2();
		VOID printPktStoreStats_i_3();
		VOID printPktStoreStats_i_4();
		VOID printPktStoreStats_i_5();
		VOID printPktStoreStats_i_6();
		VOID printPktStoreStats_i_7();

		VOID printS1MMESessionStoreStats();
		VOID printS1MME_XDRFlush();

		VOID printS11SessionStoreStats();
		VOID printS11_XDRFlush();

		VOID printS5S8SessionStoreStats();
		VOID printS5S8_XDRFlush();

		VOID printS1USessionStoreStats();
		VOID printS1U_XDRFlush();
		VOID printDNS_XDRFlush();
};

#endif /* CORE_SRC_PROBESTATS_H_ */
