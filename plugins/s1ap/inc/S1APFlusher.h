/*
 * S1APFlusher.h
 *
 *  Created on: 29-Jan-2020
 *      Author: singh
 */

#ifndef PLUGINS_S1AP_INC_S1APFLUSHER_H_
#define PLUGINS_S1AP_INC_S1APFLUSHER_H_

#include "IPGlobal.h"
#include "Log.h"
#include "BaseConfig.h"
#include "S1APGlobal.h"

using namespace std;

class S1APFlusher: BaseConfig
{
	private:
		char		packetHdr[500];			/* Debashis: Need to be reduced the size TODO*/
		char		packetMMM[100];
		char		packetSMM[100];
		char		finalPacket[300];
		char		procedurevalue[50];
		char		procedureId[50];
		char 		*imsi, *imei;

		xdrStore objXdrStore;
		BOOL	repoInitStatus = false;
		char 	csvXdr[XDR_MAX_LEN];

		VOID 	lockS1apMap();
		VOID 	unLockS1apMap();

		VOID 	processS1apData(int index);
		VOID 	flushS1apData_t(std::unordered_map<int, s1mmeSession> &flushMap, int &s1apFlushMap_cnt);
		VOID 	buildS1apSession(s1mmeSession *ps1apSession);
		BOOL	accumulatePackets(s1mmeSession *ps1apSession, char *packerSeq);
		VOID	flushS1apCsvRecords();
		char* 	getImsi(char *tmsi, uint32_t eNodeB);
		char* 	getImei(char *tmsi, uint32_t eNodeB);

		VOID	findMMM(std::map<uint32_t, MMM> &mmmMap);
		VOID	findSMM(std::map<uint32_t, SMM> &smmMap);

	public:
		S1APFlusher();
		~S1APFlusher();
		VOID 	run();
		BOOL 	isRepositoryInitialized();
};

#endif /* PLUGINS_S1AP_INC_S1APFLUSHER_H_ */
