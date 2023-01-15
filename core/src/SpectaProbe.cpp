/*
 * SpectaProbe.cpp
 *
 *  Created on: 29-Jan-2016
 *      Author: Debashis
 */

#include <signal.h>
#include <unistd.h>
#include <locale.h>
#include <zmq.h>

#include "SpectaProbe.h"

VOID *startTimerThread(VOID *arg)
{
	glbTimer *ft = (glbTimer *)arg;
	ft->run();
	return NULL;
}

void* startPktRouterThread(void* arg)
{
	int s = pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
	PacketRouter *ft = (PacketRouter*)arg;
	ft->run();
	return NULL;
}

#ifdef _S1MME
void* smThread_S1MME_Interface(void* arg)
{
	SctpSessionManager *ft = (SctpSessionManager*)arg;
	ft->run();
	return NULL;
}

void* s1apFlusherThread(void* arg)
{
	S1APFlusher *ft = (S1APFlusher*)arg;
	ft->run();
	return NULL;
}

void* s1apXdrWriterThread(void* arg)
{
	S1APXdrWriter *ft = (S1APXdrWriter*)arg;
	ft->run();
	return NULL;
}
#endif

#ifdef _S11
void* smThread_S11_Interface(void* arg)
{
	S11SessionManager *ft = (S11SessionManager*)arg;
	ft->run();
	return NULL;
}

void* smThread_S5S8_Interface(void* arg)
{
	S5S8SessionManager *ft = (S5S8SessionManager*)arg;
	ft->run();
	return NULL;
}

void* s11FlusherThread(void* arg)
{
	S11Flusher *ft = (S11Flusher*)arg;
	ft->run();
	return NULL;
}

void* s11XdrWriterThread(void* arg)
{
	S11XdrWriter *ft = (S11XdrWriter*)arg;
	ft->run();
	return NULL;
}

void* s5s8FlusherThread(void* arg)
{
	S5S8Flusher *ft = (S5S8Flusher*)arg;
	ft->run();
	return NULL;
}

void* s5s8XdrWriterThread(void* arg)
{
	S5S8XdrWriter *ft = (S5S8XdrWriter*)arg;
	ft->run();
	return NULL;
}

#endif

#ifdef _S1U
void* smThread_S1U_Interface(void* arg)
{
	S1USessionManager *ft = (S1USessionManager*)arg;
	ft->run();
	return NULL;
}

void* ipZmqflusherThread(void* arg)
{
	zmqPush *ft = (zmqPush*)arg;
	ft->run();
	return NULL;
}

void* s1uFlusherThread(void* arg)
{
	S1UFlusher *ft = (S1UFlusher*)arg;
	ft->run();
	return NULL;
}

void* s1uXdrWriterThread(void* arg)
{
	S1UXdrWriter *ft = (S1UXdrWriter*)arg;
	ft->run();
	return NULL;
}
#endif

void* packetListenerThread(void* arg)
{
	PacketListener *ft = (PacketListener*)arg;
	ft->start();
	return NULL;
}

void* ethListenerThread(void* arg)
{
	EthernetSource *ft = (EthernetSource*)arg;
	ft->start();
	return NULL;
}

void* probeStatsThread(void* arg)
{
	ProbeStats *ft = (ProbeStats*)arg;
	ft->run();
	return NULL;
}

void* probeStatsLogThread(void* arg)
{
	ProbeStatsLog *ft = (ProbeStatsLog*)arg;
	ft->run();
	return NULL;
}

void* adminPortListenerThread(void* arg)
{
	AdminPortReader *ft = (AdminPortReader*)arg;
	ft->run();
	return NULL;
}

SpectaProbe::SpectaProbe(char *fileName) {
	this->_name = "SpectaProbe    ";

	GContainer::config = new GConfig(fileName);
	initializeLocks();
	initializeLog();

	this->setLogLevel(Log::theLog().level());
#ifdef _S11
	gtpcv2msg 	= new GTPv2Message();		/* Initialize GTPcV2 IE Functions Table */
	gtpcv2init 	= new GTPv2Initialize();	/* Initialize GTPcV2 IE Types */
#endif
}

SpectaProbe::~SpectaProbe()
{
	delete(GContainer::config);
#ifdef _S11
	delete(gtpcv2msg);
	delete(gtpcv2init);
#endif
}

VOID SpectaProbe::initializeLocks()
{
	s1mmeSessionLock::count = 1;
	s11SessionLock::count	= 1;
	s5s8SessionLock::count	= 1;
	dnsSessionLock::count 	= 1;
	s1apSessionLock::count	= 1;
}

VOID SpectaProbe::initializeLog()
{
	TCHAR logFile[200];
	TCHAR probeName[10];

	logFile[0] = 0;
	sprintf(logFile, "%s%s_%d.log", GContainer::config->LOG_DIR.c_str(), GConstant::logFilePrefix,IPGlobal::PROBE_ID);

	Log::theLog().open(logFile);
	Log::theLog().level(GContainer::config->LOG_LEVEL);

	if (GContainer::config->S1MME_PROBE && GContainer::config->S11_PROBE)
		strcpy(probeName, " S1MME - S11 ");
	else if(GContainer::config->S11_PROBE && GContainer::config->S5S8_PROBE)
		strcpy(probeName, " S11 - S5/S8 ");
	else if(GContainer::config->S1MME_PROBE)
		strcpy(probeName, " S1MME ");
	else if(GContainer::config->S11_PROBE)
		strcpy(probeName, " S11 ");
	else if(GContainer::config->S5S8_PROBE)
		strcpy(probeName, " S5/S8 ");
	else
	{
		printf("\n\n No Interface is defined....!!!\n\n");
		exit(1);
	}

	string ver = "4.1.0.0";
	/*
	 * 		4.0.0		20-Dec -2017		First release, combined Mobility + Fixed Line
	 */
	printf(" ############################################################\n");
	printf("                                                             \n");
	printf("              Starting SPECTA [%s] Probe Ver : %s            \n", probeName,ver.c_str());
	printf("                                                             \n");
	printf(" ############################################################\n");


	TheLog_nc_v1(Log::Info, name(),"  ############################################################%s","");
	TheLog_nc_v1(Log::Info, name(),"                                                              %s","");
	TheLog_nc_v2(Log::Info, name(),"                     Starting SPECTA [%s] Probe Ver : %s        ", probeName, ver.c_str());
	TheLog_nc_v1(Log::Info, name(),"                                                              %s","");
	TheLog_nc_v1(Log::Info, name(),"  ############################################################%s","");
	TheLog_nc_v1(Log::Info, name(),"  Log file initialized Level - %d", GContainer::config->LOG_LEVEL);
}

VOID SpectaProbe::start()
{
	IPGlobal::NO_OF_INTERFACES = IPGlobal::NO_OF_SOLAR_INTERFACE + IPGlobal::NO_OF_NIC_INTERFACE;

	/* [1] ---- Start Timer thread, which will broadcast epoch sec after every 1/2 a second ---- */
	startTimer();

#ifdef _S1MME
	/* [2] ---- Start S1MME Session Manager ---- */
	startS1MMESessionManager();

	/* [3] ---- Start S1MME Flusher Thread ---- */
	startS1MMEFlusher();

	/* [4] ---- Start S1MME XDR Write Thread ---- */
	startS1MMEXdrWriter();
#endif

#ifdef _S11
	/* [5] ---- Start S11 Session Manager ---- */
	startS11SessionManager();

	/* [6] ---- Start S11 Flusher Thread ---- */
	startS11Flusher();

	/* [7] ---- Start S11 XDR Write Thread ---- */
	startS11XdrWriter();

	/* [8] ---- Start S5S8 Session Manager ---- */
	startS5S8SessionManager();

	/* [9] ---- Start S5S8 Flusher Thread ---- */
	startS5S8Flusher();

	/* [10] ---- Start S5S8 XDR Write Thread ---- */
	startS5S8XdrWriter();

	/* [20] ---- initialize Gtp Values ---- */
	initializeGtpValues();

#endif

#ifdef _S1U
	/* [11] ---- Start S1U Session Manager ---- */
	startS1USessionManager();

	/* [12] ---- Start S1U Flusher Thread ---- */
	startS1UFlusher();

	/* [13] ---- Start S1U XDR Write Thread ---- */
	startS1UXdrWriter();
#endif

	sleep(2);

	/* [14] ---- Start Packet Router Threads ---- */
	startRouters();

	/* [15] ---- Start Packet Listener Threads ---- */
	startPacketListener();

	/* [16] ---- Initialize Packet Repository ---- */
	initializePktRepo();

	/* [17] ---- Start Admin Threads ---- */
	openAdminPort();

	/* [18] ---- Start Probe Log Threads ---- */
	openLogFile();

	/* [19] ---- Start Probe Statistic Threads ---- */
	writeStats();



	sleep(10); /* Start Processing the data after 10 seconds */

	printf("Specta Probe Started.\n");
	TheLog_nc_v1(Log::Info, name(),"  Started successfully.%s","");

	IPGlobal::PACKET_PROCESSING = true;

	int cnt = 0, today = 0, lastday = 0, sleepDur = 5;
	int minCheckCnt = 60 / sleepDur;

	gettimeofday(&curTime, NULL);
	now_tm = localtime(&curTime.tv_sec);
	lastday = today =  now_tm->tm_mday;

	while(IPGlobal::PROBE_RUNNING_STATUS)
	{
		sleep(sleepDur);
		gettimeofday(&curTime, NULL);

		if(cnt >= minCheckCnt){
			cnt = 0;
			gettimeofday(&curTime, NULL);
			now_tm = localtime(&curTime.tv_sec);
			today = now_tm->tm_mday;

			if(lastday != today)
			{
				lastday = today;
				TheLog_nc(Log::Info, name(),"  Day Changed .... !!! Initializing Counters....");
				IPGlobal::ip_discarded_large_packets_i_0 = 0;
				IPGlobal::ip_discarded_large_packets_i_1 = 0;
				IPGlobal::ip_discarded_large_packets_i_2 = 0;
				IPGlobal::ip_discarded_large_packets_i_3 = 0;
				IPGlobal::ip_discarded_large_packets_i_4 = 0;
				IPGlobal::ip_discarded_large_packets_i_5 = 0;
				IPGlobal::ip_discarded_large_packets_i_6 = 0;
				IPGlobal::ip_discarded_large_packets_i_7 = 0;

				for(int i=0; i<IPGlobal::NO_OF_INTERFACES; i++)
					IPGlobal::PKT_LISTENER_DAYCHANGE_INDICATION[i] = true;
			}
		}
		else
		{ cnt++; }
	}

	printf("\nShutdown SpectaProbe Complete.\n");
	TheLog_nc_v1(Log::Info, name(),"  Shutdown Completed.%s","");
	exit(0);
}

VOID SpectaProbe::startTimer()
{
	glbTimer		*pGlbTimer;
	pthread_t		glbTimerThrId;
	uint16_t 		timerCpuCore = 0;

	pGlbTimer = new glbTimer;

	pthread_create(&glbTimerThrId, NULL, startTimerThread, pGlbTimer);
	pinThread(glbTimerThrId, timerCpuCore);

	while(!pGlbTimer->isGlbTimerInitialized())
		sleep(1);

	printf("  *** [1] Timer Thread Started Successfully. Pinned to CPU Core [%02d]\n", timerCpuCore);
	TheLog_nc_v1(Log::Info, name(),"  *** Timer Thread Started Successfully. Pinned to CPU Core [%02d]", timerCpuCore);
	printf("\n");
}

#ifdef _S1MME
VOID SpectaProbe::startS1MMESessionManager()
{
	uint16_t 			s1mme_Id;
	SctpSessionManager*	sessionManager_S1MME[MAX_S1MME_SESSION_MANAGER_SUPPORT];
	pthread_t 			smThrId_S1MME[MAX_S1MME_SESSION_MANAGER_SUPPORT];

	for(s1mme_Id = 0; s1mme_Id < IPGlobal::S1MME_SESSION_MANAGER_INSTANCES; s1mme_Id++)
	{
		IPGlobal::S1MME_SESSION_MANAGER_RUNNING_STATUS[s1mme_Id] = true;
		sessionManager_S1MME[s1mme_Id] = new SctpSessionManager(s1mme_Id);

		pthread_create(&smThrId_S1MME[s1mme_Id], NULL, smThread_S1MME_Interface, sessionManager_S1MME[s1mme_Id]);
		pinThread(smThrId_S1MME[s1mme_Id], IPGlobal::S1MME_SESSION_MANAGER_CPU_CORE[s1mme_Id]);

		printf("  *** [2] S1MME SM Id_%02d Pinned to CPU Core [%2d]\n", s1mme_Id, IPGlobal::S1MME_SESSION_MANAGER_CPU_CORE[s1mme_Id]);
		TheLog_nc_v2(Log::Info, name(),"  S1MME Session Manager Instance [%d] pinned to Core [%d]", s1mme_Id, IPGlobal::S1MME_SESSION_MANAGER_CPU_CORE[s1mme_Id]);

		while(!sessionManager_S1MME[s1mme_Id]->isRepositoryInitialized())
			sleep(1);
	}
	printf("\n");
}

VOID SpectaProbe::startS1MMEFlusher()
{
	S1APFlusher			*s1apFlusher;
	pthread_t 			s1apFlusherThr;

	IPGlobal::S1MME_FLUSHER_RUNNING_STATUS = true;

	s1apFlusher = new S1APFlusher;
	pthread_create(&s1apFlusherThr, NULL, s1apFlusherThread, s1apFlusher);
	pinThread(s1apFlusherThr, IPGlobal::S1MME_FLUSHER_CPU_CORE);

	printf("  *** [3] S1MME-Flusher Pinned to CPU Core [%2d]\n", IPGlobal::S1MME_FLUSHER_CPU_CORE);
	TheLog_nc_v1(Log::Info, name(),"  S1MME Flusher Instance pinned to Core [%d]", IPGlobal::S1MME_FLUSHER_CPU_CORE);

	while(!s1apFlusher->isRepositoryInitialized())
		sleep(1);

	printf("\n");
}

VOID SpectaProbe::startS1MMEXdrWriter()
{
	S1APXdrWriter		*s1apXdrWriter;
	pthread_t 			s1apXdrWriteThr;

	IPGlobal::S1MME_XDR_FLUSHER_RUNNING_STATUS = true;

	s1apXdrWriter = new S1APXdrWriter();			// Create Flusher Thread
	pthread_create(&s1apXdrWriteThr, NULL, s1apXdrWriterThread, s1apXdrWriter);
	pinThread(s1apXdrWriteThr, IPGlobal::S1MME_XDR_WRITE_CPU_CORE);

	printf("  *** [4] S1MME-XdrWriter Pinned to CPU Core [%2d]\n", IPGlobal::S1MME_XDR_WRITE_CPU_CORE);
	TheLog_nc_v1(Log::Info, name(),"  S1apXdrWriter pinned to Core [%d]", IPGlobal::S1MME_XDR_WRITE_CPU_CORE);

	while(!s1apXdrWriter->isRepositoryInitialized())
		sleep(1);

	printf("\n");
}
#endif

#ifdef _S11
VOID SpectaProbe::startS11SessionManager()
{
	uint16_t 			s11_Id;
	S11SessionManager*	sessionManager_S11[MAX_S11_SESSION_MANAGER_SUPPORT];
	pthread_t 			smThrId_S11[MAX_S11_SESSION_MANAGER_SUPPORT];

	for(s11_Id = 0; s11_Id < IPGlobal::S11_SESSION_MANAGER_INSTANCES; s11_Id++)
	{
		IPGlobal::S11_SESSION_MANAGER_RUNNING_STATUS[s11_Id] = true;
		sessionManager_S11[s11_Id] = new S11SessionManager(s11_Id);

		pthread_create(&smThrId_S11[s11_Id], NULL, smThread_S11_Interface, sessionManager_S11[s11_Id]);
		pinThread(smThrId_S11[s11_Id], IPGlobal::S11_SESSION_MANAGER_CPU_CORE[s11_Id]);

		printf("  *** [5] S11 SM Id_%02d Pinned to CPU Core [%2d]\n", s11_Id, IPGlobal::S11_SESSION_MANAGER_CPU_CORE[s11_Id]);
		TheLog_nc_v2(Log::Info, name(),"  S11 Session Manager Instance [%d] pinned to Core [%d]", s11_Id, IPGlobal::S11_SESSION_MANAGER_CPU_CORE[s11_Id]);

		while(!sessionManager_S11[s11_Id]->isRepositoryInitialized())
			sleep(1);
	}
	printf("\n");
}

VOID SpectaProbe::startS11Flusher()
{
	S11Flusher			*s11Flusher;
	pthread_t 			s11FlusherThr;

	IPGlobal::S11_FLUSHER_RUNNING_STATUS = true;

	s11Flusher = new S11Flusher;
	pthread_create(&s11FlusherThr, NULL, s11FlusherThread, s11Flusher);
	pinThread(s11FlusherThr, IPGlobal::S11_FLUSHER_CPU_CORE);

	printf("  *** [6] S11-Flusher Pinned to CPU Core [%2d]\n", IPGlobal::S11_FLUSHER_CPU_CORE);
	TheLog_nc_v1(Log::Info, name(),"  S11 Flusher Instance pinned to Core [%d]", IPGlobal::S11_FLUSHER_CPU_CORE);

	while(!s11Flusher->isRepositoryInitialized())
		sleep(1);

	printf("\n");
}

VOID SpectaProbe::startS11XdrWriter()
{
	S11XdrWriter		*s11XdrWriter;
	pthread_t 			s11XdrWriteThr;

	IPGlobal::S11_XDR_FLUSHER_RUNNING_STATUS = true;

	s11XdrWriter = new S11XdrWriter();			// Create Flusher Thread
	pthread_create(&s11XdrWriteThr, NULL, s11XdrWriterThread, s11XdrWriter);
	pinThread(s11XdrWriteThr, IPGlobal::S11_XDR_WRITE_CPU_CORE);

	printf("  *** [7] S11-XdrWriter Pinned to CPU Core [%2d]\n", IPGlobal::S11_XDR_WRITE_CPU_CORE);
	TheLog_nc_v1(Log::Info, name(),"  S11XdrWriter pinned to Core [%d]", IPGlobal::S11_XDR_WRITE_CPU_CORE);

	while(!s11XdrWriter->isRepositoryInitialized())
		sleep(1);

	printf("\n");
}

VOID SpectaProbe::startS5S8SessionManager()
{
	uint16_t 			s5s8_Id;
	S5S8SessionManager*	sessionManager_S5S8[MAX_S5S8_SESSION_MANAGER_SUPPORT];
	pthread_t 			smThrId_S5S8[MAX_S5S8_SESSION_MANAGER_SUPPORT];

	for(int s5s8_Id = 0; s5s8_Id < IPGlobal::S5S8_SESSION_MANAGER_INSTANCES; s5s8_Id++)
	{
		IPGlobal::S5S8_SESSION_MANAGER_RUNNING_STATUS[s5s8_Id] = true;
		sessionManager_S5S8[s5s8_Id] = new S5S8SessionManager(s5s8_Id);

		pthread_create(&smThrId_S5S8[s5s8_Id], NULL, smThread_S5S8_Interface, sessionManager_S5S8[s5s8_Id]);
		pinThread(smThrId_S5S8[s5s8_Id], IPGlobal::S5S8_SESSION_MANAGER_CPU_CORE[s5s8_Id]);

		printf("  *** [8] S5S8 SM Id_%02d Pinned to CPU Core [%2d]\n", s5s8_Id, IPGlobal::S5S8_SESSION_MANAGER_CPU_CORE[s5s8_Id]);
		TheLog_nc_v2(Log::Info, name(),"  S5/S8 Session Manager Instance [%d] pinned to Core [%d]", s5s8_Id, IPGlobal::S5S8_SESSION_MANAGER_CPU_CORE[s5s8_Id]);

		while(!sessionManager_S5S8[s5s8_Id]->isRepositoryInitialized())
			sleep(1);
	}
	printf("\n");
}

VOID SpectaProbe::startS5S8Flusher()
{
	S5S8Flusher			*s5s8Flusher;
	pthread_t 			s5s8FlusherThr;

	IPGlobal::S5S8_FLUSHER_RUNNING_STATUS = true;

	s5s8Flusher = new S5S8Flusher;
	pthread_create(&s5s8FlusherThr, NULL, s5s8FlusherThread, s5s8Flusher);
	pinThread(s5s8FlusherThr, IPGlobal::S5S8_FLUSHER_CPU_CORE);

	printf("  *** [9] S5S8-Flusher Pinned to CPU Core [%2d]\n", IPGlobal::S5S8_FLUSHER_CPU_CORE);
	TheLog_nc_v1(Log::Info, name(),"  S5S8 Flusher Instance pinned to Core [%d]", IPGlobal::S5S8_FLUSHER_CPU_CORE);

	while(!s5s8Flusher->isRepositoryInitialized())
		sleep(1);

	printf("\n");
}

VOID SpectaProbe::startS5S8XdrWriter()
{
	S5S8XdrWriter		*s5s8XdrWriter;
	pthread_t 			s5s8XdrWriteThr;

	IPGlobal::S5S8_XDR_FLUSHER_RUNNING_STATUS = true;

	s5s8XdrWriter = new S5S8XdrWriter();			// Create Flusher Thread
	pthread_create(&s5s8XdrWriteThr, NULL, s5s8XdrWriterThread, s5s8XdrWriter);
	pinThread(s5s8XdrWriteThr, IPGlobal::S5S8_XDR_WRITE_CPU_CORE);

	printf("  *** [10] S5S8-XdrWriter Pinned to CPU Core [%2d]\n", IPGlobal::S5S8_XDR_WRITE_CPU_CORE);
	TheLog_nc_v1(Log::Info, name(),"  S5S8XdrWriter pinned to Core [%d]", IPGlobal::S5S8_XDR_WRITE_CPU_CORE);

	while(!s5s8XdrWriter->isRepositoryInitialized())
		sleep(1);

	printf("\n");
}

VOID SpectaProbe::initializeGtpValues()
{
	gtpcv2init->GTPcV2_InitializeRatType();						/* Initialize GTPcV2 Rat Type */
	gtpcv2init->GTPcV2_InitializeCauseCode();
	gtpcv2init->GTPcV2_InitializeMessageType();					/* Initialize GTPcV2 Message Type */
	gtpcv2msg->GTPcV2_InitializeIETable();						/* Initialize GTPcV2 Information Element */
	gtpcv2msg->GTPcV2_MsgTypeParser();

	printf("  *** [17] initialize Gtp Values Completed,\n");
}

#endif

#ifdef _S1U
VOID SpectaProbe::startS1USessionManager()
{
	uint16_t 			s1u_Id;
	S1USessionManager*	sessionManager_S1U[MAX_IP_SESSION_MANAGER_SUPPORT];
	pthread_t 			smThrId_S1U[MAX_IP_SESSION_MANAGER_SUPPORT];

	for(int s1u_Id = 0; s1u_Id < IPGlobal::S1U_SESSION_MANAGER_INSTANCES; s1u_Id++)
	{
		IPGlobal::S1U_SESSION_MANAGER_RUNNING_STATUS[s1u_Id] = true;
		sessionManager_S1U[s1u_Id] = new S1USessionManager(s1u_Id);

		pthread_create(&smThrId_S1U[s1u_Id], NULL, smThread_S1U_Interface, sessionManager_S1U[s1u_Id]);
		pinThread(smThrId_S1U[s1u_Id], IPGlobal::S1U_SESSION_MANAGER_CPU_CORE[s1u_Id]);

		printf("  *** [11] S1U SM Id_%02d Pinned to CPU Core [%2d]\n", s1u_Id, IPGlobal::S1U_SESSION_MANAGER_CPU_CORE[s1u_Id]);
		TheLog_nc_v2(Log::Info, name(),"  S1U Session Manager Instance [%d] pinned to Core [%d]", s1u_Id, IPGlobal::S1U_SESSION_MANAGER_CPU_CORE[s1u_Id]);

		while(!sessionManager_S1U[s1u_Id]->isRepositoryInitialized())
		{
			printf("Return %d\n", sessionManager_S1U[s1u_Id]->isRepositoryInitialized());
			sleep(1);
		}
	}
	printf("\n");
}

VOID SpectaProbe::startS1UFlusher()
{
	S1UFlusher			*s1uFlusher;
	pthread_t 			s1uFlusherThr;

	IPGlobal::S1U_FLUSHER_RUNNING_STATUS = true;

	for(int i = 0; i < IPGlobal::S1U_FLUSHER_NO; i++)
	{
		s1uFlusher = new S1UFlusher(i);
		pthread_create(&s1uFlusherThr, NULL, s1uFlusherThread, s1uFlusher);
		pinThread(s1uFlusherThr, IPGlobal::S1U_FLUSHER_CPU_CORE[i]);

		printf("  *** [9] S1U-Flusher Pinned to CPU Core [%2d]\n", IPGlobal::S1U_FLUSHER_CPU_CORE[i]);
		TheLog_nc_v1(Log::Info, name(),"  S1U Flusher Instance pinned to Core [%d]", IPGlobal::S1U_FLUSHER_CPU_CORE[i]);

		while(!s1uFlusher->isRepositoryInitialized())
			sleep(1);
	}

	printf("\n");
}

VOID SpectaProbe::startS1UXdrWriter()
{
	S1UXdrWriter		*s1uXdrWriter;
	pthread_t 			s1uXdrWriteThr;

	IPGlobal::S1U_XDR_FLUSHER_RUNNING_STATUS = true;

	s1uXdrWriter = new S1UXdrWriter();			// Create Flusher Thread
	pthread_create(&s1uXdrWriteThr, NULL, s1uXdrWriterThread, s1uXdrWriter);
	pinThread(s1uXdrWriteThr, IPGlobal::S1U_XDR_WRITE_CPU_CORE);

	printf("  *** [10] S1U-XdrWriter Pinned to CPU Core [%2d]\n", IPGlobal::S1U_XDR_WRITE_CPU_CORE);
	TheLog_nc_v1(Log::Info, name(),"  S1UXdrWriter pinned to Core [%d]", IPGlobal::S1U_XDR_WRITE_CPU_CORE);

	while(!s1uXdrWriter->isRepositoryInitialized())
		sleep(1);

	printf("\n");
}
#endif

VOID SpectaProbe::startRouters()
{
	PacketRouter 	*pRouter[MAX_INTERFACE_SUPPORT][MAX_ROUTER_PER_INTERFACE_SUPPORT];
	pthread_t 		thPktRouter[MAX_INTERFACE_SUPPORT][MAX_ROUTER_PER_INTERFACE_SUPPORT];

	for(int infCounter = 0; infCounter < IPGlobal::NO_OF_INTERFACES; infCounter++)
	{
		for(int routeCounter = 0; routeCounter < IPGlobal::ROUTER_PER_INTERFACE[infCounter]; routeCounter++)
		{
			IPGlobal::PKT_ROUTER_RUNNING_STATUS[infCounter][routeCounter] = true;
			gettimeofday(&curTime, NULL);

			pRouter[infCounter][routeCounter] = new PacketRouter(infCounter, routeCounter, IPGlobal::ROUTER_PER_INTERFACE[infCounter], IPGlobal::PKT_ROUTER_CPU_CORE[infCounter][routeCounter]);
			pthread_create(&thPktRouter[infCounter][routeCounter], NULL, startPktRouterThread, pRouter[infCounter][routeCounter]);

			pinThread(thPktRouter[infCounter][routeCounter], IPGlobal::PKT_ROUTER_CPU_CORE[infCounter][routeCounter]);
			printf("  *** [11] PacketRouter [Interface]::[Router] [%02d]::[%02d] Pinned to CPU Core [%02d]\n", infCounter, routeCounter, IPGlobal::PKT_ROUTER_CPU_CORE[infCounter][routeCounter]);

			TheLog_nc_v3(Log::Info, name(),"  PacketRouter Instance [%d][%d] pinned to Core [%d]", infCounter, routeCounter, IPGlobal::PKT_ROUTER_CPU_CORE[infCounter][routeCounter]);

			while(!pRouter[infCounter][routeCounter]->isRepositoryInitialized())
				sleep(1);
		}
	}
	printf("\n");
}

VOID SpectaProbe::startPacketListener()
{
	uint16_t 			nicCounter, solCounter, interfaceCounter;
	int 				caseNo = -1;
	EthernetSource 		*ethReader[MAX_INTERFACE_SUPPORT];
	PacketListener 		*sfReader[MAX_INTERFACE_SUPPORT];
	pthread_t 			pktLisThread[MAX_INTERFACE_SUPPORT];

	nicCounter = solCounter = interfaceCounter = 0;

	if(IPGlobal::NO_OF_NIC_INTERFACE > 0 && IPGlobal::NO_OF_SOLAR_INTERFACE > 0)
		caseNo = 0; /* Both NIC and Solarflare */
	else if(IPGlobal::NO_OF_NIC_INTERFACE > 0 && IPGlobal::NO_OF_SOLAR_INTERFACE == 0)
		caseNo = 1; /* Only NIC */
	else if(IPGlobal::NO_OF_NIC_INTERFACE == 0 && IPGlobal::NO_OF_SOLAR_INTERFACE > 0)
		caseNo = 2; /* Only Solarflare */

	switch(caseNo)
	{
		case 0:		/* Both NIC and Solarflare */
		{
			for(nicCounter = 0; nicCounter < IPGlobal::NO_OF_NIC_INTERFACE; nicCounter++)
			{
				printf("\n  *** [12] Started NIC   Listener for Interface [%d]->[%s] with No of Routers [%02d] Pinned to CPU Core [%02d] \n",
						nicCounter, IPGlobal::ETHERNET_INTERFACES[nicCounter].c_str(), IPGlobal::ROUTER_PER_INTERFACE[nicCounter], IPGlobal::PKT_LISTENER_CPU_CORE[nicCounter]);

			IPGlobal::PNAME[nicCounter] = IPGlobal::ETHERNET_INTERFACES[nicCounter];

			IPGlobal::PKT_LISTENER_RUNNING_STATUS[nicCounter] = true;
			IPGlobal::PKT_LISTENER_DAYCHANGE_INDICATION[nicCounter] = false;

			ethReader[nicCounter] = new EthernetSource(IPGlobal::ROUTER_PER_INTERFACE[nicCounter], nicCounter);
			pthread_create(&pktLisThread[nicCounter], NULL, ethListenerThread, ethReader[nicCounter]);
			pinThread(pktLisThread[nicCounter], IPGlobal::PKT_LISTENER_CPU_CORE[nicCounter]);

			TheLog_nc_v2(Log::Info, name(),"  EthernetListener Instance [%d] pinned to Core [%d]", nicCounter, IPGlobal::PKT_LISTENER_CPU_CORE[nicCounter]);

			while(!ethReader[nicCounter]->isRepositoryInitialized())
				sleep(1);
			}

			interfaceCounter = nicCounter;
			for(int solCounter = 0; solCounter < IPGlobal::NO_OF_SOLAR_INTERFACE; solCounter++, interfaceCounter++)
			{
				printf("\n  *** [12] Started SOLAR Listener for Interface [%d]->[%s] with No of Routers [%02d] Pinned to CPU Core [%02d] \n",
						interfaceCounter, IPGlobal::SOLAR_INTERFACES[solCounter].c_str(), IPGlobal::ROUTER_PER_INTERFACE[interfaceCounter], IPGlobal::PKT_LISTENER_CPU_CORE[interfaceCounter]);

				IPGlobal::PNAME[interfaceCounter] = IPGlobal::SOLAR_INTERFACES[solCounter];

				IPGlobal::PKT_LISTENER_RUNNING_STATUS[interfaceCounter] = true;
				IPGlobal::PKT_LISTENER_DAYCHANGE_INDICATION[interfaceCounter] = false;

				sfReader[interfaceCounter] = new PacketListener(IPGlobal::ROUTER_PER_INTERFACE[interfaceCounter], solCounter, interfaceCounter);
				pthread_create(&pktLisThread[interfaceCounter], NULL, packetListenerThread, sfReader[interfaceCounter]);
				pinThread(pktLisThread[interfaceCounter], IPGlobal::PKT_LISTENER_CPU_CORE[interfaceCounter]);

				TheLog_nc_v2(Log::Info, name(),"  SolarflareListener Instance [%d] pinned to Core [%d]", interfaceCounter, IPGlobal::PKT_LISTENER_CPU_CORE[interfaceCounter]);

				while(!sfReader[interfaceCounter]->isRepositoryInitialized())
					sleep(1);
			}
		}
		break;

		case 1:		/* Only NIC */
		{
			for(int infCounter = 0; infCounter < IPGlobal::NO_OF_INTERFACES; infCounter++)
			{
				printf("  *** [12] Started NIC   Listener for Interface [%d]->[%s] with No of Routers [%02d] Pinned to CPU Core [%02d] \n",
						infCounter, IPGlobal::ETHERNET_INTERFACES[infCounter].c_str(), IPGlobal::ROUTER_PER_INTERFACE[infCounter], IPGlobal::PKT_LISTENER_CPU_CORE[infCounter]);

				IPGlobal::PNAME[infCounter] = IPGlobal::ETHERNET_INTERFACES[infCounter];

				IPGlobal::PKT_LISTENER_RUNNING_STATUS[infCounter] = true;
				IPGlobal::PKT_LISTENER_DAYCHANGE_INDICATION[infCounter] = false;
				ethReader[infCounter] = new EthernetSource(IPGlobal::ROUTER_PER_INTERFACE[infCounter], infCounter);
				pthread_create(&pktLisThread[infCounter], NULL, ethListenerThread, ethReader[infCounter]);
				pinThread(pktLisThread[infCounter], IPGlobal::PKT_LISTENER_CPU_CORE[infCounter]);

				while(!ethReader[infCounter]->isRepositoryInitialized())
					sleep(1);
			}
		}
		break;

		case 2:		/* Only Solarflare */
		{
			for(int infCounter = 0; infCounter < IPGlobal::NO_OF_INTERFACES; infCounter++)
			{
				printf("  *** [12] Started SOLAR Listener for Interface [%d]->[%s] with No of Routers [%02d] Pinned to CPU Core [%02d] \n",
						infCounter, IPGlobal::SOLAR_INTERFACES[infCounter].c_str(), IPGlobal::ROUTER_PER_INTERFACE[infCounter], IPGlobal::PKT_LISTENER_CPU_CORE[infCounter]);

				IPGlobal::PNAME[infCounter] = IPGlobal::SOLAR_INTERFACES[infCounter];

				IPGlobal::PKT_LISTENER_RUNNING_STATUS[infCounter] = true;
				IPGlobal::PKT_LISTENER_DAYCHANGE_INDICATION[infCounter] = false;
				sfReader[infCounter] = new PacketListener(IPGlobal::ROUTER_PER_INTERFACE[infCounter], infCounter, infCounter);
				pthread_create(&pktLisThread[infCounter], NULL, packetListenerThread, sfReader[infCounter]);
				pinThread(pktLisThread[infCounter], IPGlobal::PKT_LISTENER_CPU_CORE[infCounter]);

				TheLog_nc_v2(Log::Info, name(),"  PacketListener Instance [%d] pinned to Core [%d]", infCounter, IPGlobal::PKT_LISTENER_CPU_CORE[infCounter]);

				while(!sfReader[infCounter]->isRepositoryInitialized())
					sleep(1);
			}
		}
		break;
	}
}

VOID SpectaProbe::openAdminPort()
{
	AdminPortReader		*adminPort;
	pthread_t adminPortThread;

	if(IPGlobal::ADMIN_FLAG)
	{
		adminPort = new AdminPortReader();
		pthread_create(&adminPortThread, NULL, adminPortListenerThread, adminPort);
		sleep(1);
	}
	printf("  *** [14] Started Admin Thread. \n");
}

VOID SpectaProbe::openLogFile()
{
	ProbeStatsLog		*psLog;
	pthread_t psLogThread;

	psLog = new ProbeStatsLog();
	pthread_create(&psLogThread, NULL, probeStatsLogThread, psLog);

	printf("  *** [15] Started Log Thread. \n");
}

VOID SpectaProbe::writeStats()
{
	ProbeStats 			*ps;
	pthread_t 			psThread ;

	if(IPGlobal::PRINT_STATS)
	{
		ps = new ProbeStats();
		pthread_create(&psThread, NULL, probeStatsThread, ps);
	}
	printf("  *** [16] Started Statistic Thread. \n");
}

void SpectaProbe::pinThread(pthread_t th, int i)
{
   /* Set affinity mask to include CPUs 0 to 7 */
	cpu_set_t cpuset;
	CPU_ZERO(&cpuset);
	CPU_SET(i,&cpuset);

	int s = pthread_setaffinity_np(th, sizeof(cpu_set_t), &cpuset);
	if (s != 0)
		handle_error_en(s, "ERROR!!! pthread_setaffinity_np");

	/* Check the actual affinity mask assigned to the thread */
	s = pthread_getaffinity_np(th, sizeof(cpu_set_t), &cpuset);
	if (s != 0)
		handle_error_en(s, "ERROR!!! pthread_getaffinity_np");

	if (!CPU_ISSET(i, &cpuset)){
		printf("CPU pinning failed at core :: %d\n", i);
		TheLog_nc_v1(Log::Info, name(),"  CPU pinning failed at core :: %d",i);
	}
}

VOID SpectaProbe::initializePktRepo()
{
	if(IPGlobal::NO_OF_INTERFACES > 0)
		initialize_pkt_repo_i_0();

	if(IPGlobal::NO_OF_INTERFACES > 1)
		initialize_pkt_repo_i_1();

	if(IPGlobal::NO_OF_INTERFACES > 2)
		initialize_pkt_repo_i_2();

	if(IPGlobal::NO_OF_INTERFACES > 3)
		initialize_pkt_repo_i_3();

	if(IPGlobal::NO_OF_INTERFACES > 4)
		initialize_pkt_repo_i_4();

	if(IPGlobal::NO_OF_INTERFACES > 5)
		initialize_pkt_repo_i_5();

	if(IPGlobal::NO_OF_INTERFACES > 6)
		initialize_pkt_repo_i_6();

	if(IPGlobal::NO_OF_INTERFACES > 7)
		initialize_pkt_repo_i_7();
}

VOID SpectaProbe::initialize_pkt_repo_i_0()
{
	int intfId = 0;
	int maxLen = IPGlobal::PPS_PER_INTERFACE[intfId] / IPGlobal::ROUTER_PER_INTERFACE[intfId];

	printf("PKTStore Repository for Interface [%d] Initializing [%'d] per Router x 10 x %d Router RawPkt... ", intfId, maxLen, IPGlobal::ROUTER_PER_INTERFACE[intfId]);
	TheLog_nc_v3(Log::Info, name(),"  PKTStore Repository for Interface [%d] Initializing [%'d] per Router x 10 x %d Router RawPkt...", intfId, maxLen, IPGlobal::ROUTER_PER_INTERFACE[intfId]);

	for(long i=0; i<maxLen; i++)
	{
		if(IPGlobal::ROUTER_PER_INTERFACE[intfId] > 0){
			PKTStore::pktRepository_i_0_r_0_t_0[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_0_r_0_t_1[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_0_r_0_t_2[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_0_r_0_t_3[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_0_r_0_t_4[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_0_r_0_t_5[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_0_r_0_t_6[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_0_r_0_t_7[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_0_r_0_t_8[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_0_r_0_t_9[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
		}
		if(IPGlobal::ROUTER_PER_INTERFACE[intfId] > 1){
			PKTStore::pktRepository_i_0_r_1_t_0[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_0_r_1_t_1[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_0_r_1_t_2[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_0_r_1_t_3[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_0_r_1_t_4[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_0_r_1_t_5[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_0_r_1_t_6[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_0_r_1_t_7[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_0_r_1_t_8[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_0_r_1_t_9[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
		}
		if(IPGlobal::ROUTER_PER_INTERFACE[intfId] > 2){
			PKTStore::pktRepository_i_0_r_2_t_0[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_0_r_2_t_1[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_0_r_2_t_2[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_0_r_2_t_3[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_0_r_2_t_4[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_0_r_2_t_5[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_0_r_2_t_6[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_0_r_2_t_7[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_0_r_2_t_8[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_0_r_2_t_9[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
		}
		if(IPGlobal::ROUTER_PER_INTERFACE[intfId] > 3){
			PKTStore::pktRepository_i_0_r_3_t_0[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_0_r_3_t_1[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_0_r_3_t_2[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_0_r_3_t_3[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_0_r_3_t_4[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_0_r_3_t_5[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_0_r_3_t_6[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_0_r_3_t_7[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_0_r_3_t_8[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_0_r_3_t_9[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
		}
		if(IPGlobal::ROUTER_PER_INTERFACE[intfId] > 4){
			PKTStore::pktRepository_i_0_r_4_t_0[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_0_r_4_t_1[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_0_r_4_t_2[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_0_r_4_t_3[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_0_r_4_t_4[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_0_r_4_t_5[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_0_r_4_t_6[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_0_r_4_t_7[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_0_r_4_t_8[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_0_r_4_t_9[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
		}
		if(IPGlobal::ROUTER_PER_INTERFACE[intfId] > 5){
			PKTStore::pktRepository_i_0_r_5_t_0[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_0_r_5_t_1[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_0_r_5_t_2[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_0_r_5_t_3[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_0_r_5_t_4[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_0_r_5_t_5[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_0_r_5_t_6[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_0_r_5_t_7[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_0_r_5_t_8[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_0_r_5_t_9[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
		}
		if(IPGlobal::ROUTER_PER_INTERFACE[intfId] > 6){
			PKTStore::pktRepository_i_0_r_6_t_0[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_0_r_6_t_1[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_0_r_6_t_2[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_0_r_6_t_3[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_0_r_6_t_4[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_0_r_6_t_5[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_0_r_6_t_6[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_0_r_6_t_7[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_0_r_6_t_8[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_0_r_6_t_9[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
		}
		if(IPGlobal::ROUTER_PER_INTERFACE[intfId] > 7){
			PKTStore::pktRepository_i_0_r_7_t_0[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_0_r_7_t_1[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_0_r_7_t_2[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_0_r_7_t_3[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_0_r_7_t_4[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_0_r_7_t_5[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_0_r_7_t_6[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_0_r_7_t_7[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_0_r_7_t_8[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_0_r_7_t_9[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
		}
	}

	printf("Completed\n", intfId, maxLen, IPGlobal::ROUTER_PER_INTERFACE[intfId]);
	TheLog_nc_v3(Log::Info, name(),"  PKTStore Repository for Interface [%d] Initializing [%'d] per Router x 10 x %d Router RawPkt...Completed", intfId, maxLen, IPGlobal::ROUTER_PER_INTERFACE[intfId]);
}

VOID SpectaProbe::initialize_pkt_repo_i_1()
{
	int intfId = 1;
	int maxLen = IPGlobal::PPS_PER_INTERFACE[intfId] / IPGlobal::ROUTER_PER_INTERFACE[intfId];

	printf("PKTStore Repository for Interface [%d] Initializing [%'d] per Router x 10 x %d Router RawPkt... ", intfId, maxLen, IPGlobal::ROUTER_PER_INTERFACE[intfId]);
	TheLog_nc_v3(Log::Info, name(),"  PKTStore Repository for Interface [%d] Initializing [%'d] per Router x 10 x %d Router RawPkt...", intfId, maxLen, IPGlobal::ROUTER_PER_INTERFACE[intfId]);

	for(long i=0; i<maxLen; i++){
		if(IPGlobal::ROUTER_PER_INTERFACE[intfId] > 0){
			PKTStore::pktRepository_i_1_r_0_t_0[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_1_r_0_t_1[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_1_r_0_t_2[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_1_r_0_t_3[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_1_r_0_t_4[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_1_r_0_t_5[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_1_r_0_t_6[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_1_r_0_t_7[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_1_r_0_t_8[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_1_r_0_t_9[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
		}
		if(IPGlobal::ROUTER_PER_INTERFACE[intfId] > 1){
			PKTStore::pktRepository_i_1_r_1_t_0[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_1_r_1_t_1[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_1_r_1_t_2[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_1_r_1_t_3[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_1_r_1_t_4[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_1_r_1_t_5[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_1_r_1_t_6[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_1_r_1_t_7[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_1_r_1_t_8[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_1_r_1_t_9[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
		}
		if(IPGlobal::ROUTER_PER_INTERFACE[intfId] > 2){
			PKTStore::pktRepository_i_1_r_2_t_0[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_1_r_2_t_1[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_1_r_2_t_2[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_1_r_2_t_3[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_1_r_2_t_4[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_1_r_2_t_5[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_1_r_2_t_6[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_1_r_2_t_7[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_1_r_2_t_8[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_1_r_2_t_9[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
		}
		if(IPGlobal::ROUTER_PER_INTERFACE[intfId] > 3){
			PKTStore::pktRepository_i_1_r_3_t_0[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_1_r_3_t_1[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_1_r_3_t_2[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_1_r_3_t_3[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_1_r_3_t_4[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_1_r_3_t_5[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_1_r_3_t_6[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_1_r_3_t_7[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_1_r_3_t_8[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_1_r_3_t_9[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
		}
		if(IPGlobal::ROUTER_PER_INTERFACE[intfId] > 4){
			PKTStore::pktRepository_i_1_r_4_t_0[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_1_r_4_t_1[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_1_r_4_t_2[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_1_r_4_t_3[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_1_r_4_t_4[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_1_r_4_t_5[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_1_r_4_t_6[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_1_r_4_t_7[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_1_r_4_t_8[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_1_r_4_t_9[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
		}
		if(IPGlobal::ROUTER_PER_INTERFACE[intfId] > 5){
			PKTStore::pktRepository_i_1_r_5_t_0[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_1_r_5_t_1[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_1_r_5_t_2[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_1_r_5_t_3[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_1_r_5_t_4[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_1_r_5_t_5[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_1_r_5_t_6[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_1_r_5_t_7[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_1_r_5_t_8[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_1_r_5_t_9[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
		}
		if(IPGlobal::ROUTER_PER_INTERFACE[intfId] > 6){
			PKTStore::pktRepository_i_1_r_6_t_0[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_1_r_6_t_1[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_1_r_6_t_2[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_1_r_6_t_3[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_1_r_6_t_4[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_1_r_6_t_5[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_1_r_6_t_6[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_1_r_6_t_7[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_1_r_6_t_8[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_1_r_6_t_9[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
		}
		if(IPGlobal::ROUTER_PER_INTERFACE[intfId] > 7){
			PKTStore::pktRepository_i_1_r_7_t_0[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_1_r_7_t_1[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_1_r_7_t_2[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_1_r_7_t_3[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_1_r_7_t_4[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_1_r_7_t_5[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_1_r_7_t_6[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_1_r_7_t_7[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_1_r_7_t_8[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_1_r_7_t_9[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
		}
	}

	printf("Completed\n", intfId, maxLen, IPGlobal::ROUTER_PER_INTERFACE[intfId]);
	TheLog_nc_v3(Log::Info, name(),"  PKTStore Repository for Interface [%d] Initializing [%'d] per Router x 10 x %d Router RawPkt...Completed", intfId, maxLen, IPGlobal::ROUTER_PER_INTERFACE[intfId]);
}

VOID SpectaProbe::initialize_pkt_repo_i_2()
{
	int intfId = 2;
	int maxLen = IPGlobal::PPS_PER_INTERFACE[intfId] / IPGlobal::ROUTER_PER_INTERFACE[intfId];

	printf("PKTStore Repository for Interface [%d] Initializing [%'d] per Router x 10 x %d Router RawPkt... ", intfId, maxLen, IPGlobal::ROUTER_PER_INTERFACE[intfId]);
	TheLog_nc_v3(Log::Info, name(),"  PKTStore Repository for Interface [%d] Initializing [%'d] per Router x 10 x %d Router RawPkt...", intfId, maxLen, IPGlobal::ROUTER_PER_INTERFACE[intfId]);

	for(long i=0; i<maxLen; i++){
		if(IPGlobal::ROUTER_PER_INTERFACE[intfId] > 0){
			PKTStore::pktRepository_i_2_r_0_t_0[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_2_r_0_t_1[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_2_r_0_t_2[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_2_r_0_t_3[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_2_r_0_t_4[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_2_r_0_t_5[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_2_r_0_t_6[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_2_r_0_t_7[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_2_r_0_t_8[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_2_r_0_t_9[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
		}
		if(IPGlobal::ROUTER_PER_INTERFACE[intfId] > 1){
			PKTStore::pktRepository_i_2_r_1_t_0[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_2_r_1_t_1[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_2_r_1_t_2[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_2_r_1_t_3[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_2_r_1_t_4[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_2_r_1_t_5[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_2_r_1_t_6[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_2_r_1_t_7[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_2_r_1_t_8[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_2_r_1_t_9[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
		}
		if(IPGlobal::ROUTER_PER_INTERFACE[intfId] > 2){
			PKTStore::pktRepository_i_2_r_2_t_0[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_2_r_2_t_1[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_2_r_2_t_2[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_2_r_2_t_3[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_2_r_2_t_4[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_2_r_2_t_5[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_2_r_2_t_6[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_2_r_2_t_7[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_2_r_2_t_8[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_2_r_2_t_9[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
		}
		if(IPGlobal::ROUTER_PER_INTERFACE[intfId] > 3){
			PKTStore::pktRepository_i_2_r_3_t_0[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_2_r_3_t_1[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_2_r_3_t_2[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_2_r_3_t_3[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_2_r_3_t_4[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_2_r_3_t_5[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_2_r_3_t_6[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_2_r_3_t_7[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_2_r_3_t_8[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_2_r_3_t_9[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
		}
		if(IPGlobal::ROUTER_PER_INTERFACE[intfId] > 4){
			PKTStore::pktRepository_i_2_r_4_t_0[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_2_r_4_t_1[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_2_r_4_t_2[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_2_r_4_t_3[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_2_r_4_t_4[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_2_r_4_t_5[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_2_r_4_t_6[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_2_r_4_t_7[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_2_r_4_t_8[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_2_r_4_t_9[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
		}
		if(IPGlobal::ROUTER_PER_INTERFACE[intfId] > 5){
			PKTStore::pktRepository_i_2_r_5_t_0[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_2_r_5_t_1[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_2_r_5_t_2[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_2_r_5_t_3[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_2_r_5_t_4[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_2_r_5_t_5[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_2_r_5_t_6[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_2_r_5_t_7[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_2_r_5_t_8[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_2_r_5_t_9[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
		}
		if(IPGlobal::ROUTER_PER_INTERFACE[intfId] > 6){
			PKTStore::pktRepository_i_2_r_6_t_0[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_2_r_6_t_1[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_2_r_6_t_2[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_2_r_6_t_3[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_2_r_6_t_4[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_2_r_6_t_5[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_2_r_6_t_6[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_2_r_6_t_7[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_2_r_6_t_8[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_2_r_6_t_9[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
		}
		if(IPGlobal::ROUTER_PER_INTERFACE[intfId] > 7){
			PKTStore::pktRepository_i_2_r_7_t_0[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_2_r_7_t_1[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_2_r_7_t_2[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_2_r_7_t_3[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_2_r_7_t_4[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_2_r_7_t_5[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_2_r_7_t_6[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_2_r_7_t_7[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_2_r_7_t_8[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_2_r_7_t_9[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
		}
	}

	printf("Completed\n", intfId, maxLen, IPGlobal::ROUTER_PER_INTERFACE[intfId]);
	TheLog_nc_v3(Log::Info, name(),"  PKTStore Repository for Interface [%d] Initializing [%'d] per Router x 10 x %d Router RawPkt...Completed", intfId, maxLen, IPGlobal::ROUTER_PER_INTERFACE[intfId]);
}

VOID SpectaProbe::initialize_pkt_repo_i_3()
{
	int intfId = 3;
	int maxLen = IPGlobal::PPS_PER_INTERFACE[intfId] / IPGlobal::ROUTER_PER_INTERFACE[intfId];

	printf("PKTStore Repository for Interface [%d] Initializing [%'d] per Router x 10 x %d Router RawPkt... ", intfId, maxLen, IPGlobal::ROUTER_PER_INTERFACE[intfId]);
	TheLog_nc_v3(Log::Info, name(),"  PKTStore Repository for Interface [%d] Initializing [%'d] per Router x 10 x %d Router RawPkt...", intfId, maxLen, IPGlobal::ROUTER_PER_INTERFACE[intfId]);

	for(long i=0; i<maxLen; i++){
		if(IPGlobal::ROUTER_PER_INTERFACE[intfId] > 0){
			PKTStore::pktRepository_i_3_r_0_t_0[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_3_r_0_t_1[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_3_r_0_t_2[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_3_r_0_t_3[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_3_r_0_t_4[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_3_r_0_t_5[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_3_r_0_t_6[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_3_r_0_t_7[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_3_r_0_t_8[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_3_r_0_t_9[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
		}
		if(IPGlobal::ROUTER_PER_INTERFACE[intfId] > 1){
			PKTStore::pktRepository_i_3_r_1_t_0[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_3_r_1_t_1[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_3_r_1_t_2[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_3_r_1_t_3[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_3_r_1_t_4[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_3_r_1_t_5[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_3_r_1_t_6[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_3_r_1_t_7[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_3_r_1_t_8[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_3_r_1_t_9[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
		}
		if(IPGlobal::ROUTER_PER_INTERFACE[intfId] > 2){
			PKTStore::pktRepository_i_3_r_2_t_0[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_3_r_2_t_1[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_3_r_2_t_2[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_3_r_2_t_3[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_3_r_2_t_4[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_3_r_2_t_5[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_3_r_2_t_6[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_3_r_2_t_7[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_3_r_2_t_8[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_3_r_2_t_9[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
		}
		if(IPGlobal::ROUTER_PER_INTERFACE[intfId] > 3){
			PKTStore::pktRepository_i_3_r_3_t_0[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_3_r_3_t_1[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_3_r_3_t_2[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_3_r_3_t_3[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_3_r_3_t_4[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_3_r_3_t_5[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_3_r_3_t_6[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_3_r_3_t_7[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_3_r_3_t_8[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_3_r_3_t_9[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
		}
		if(IPGlobal::ROUTER_PER_INTERFACE[intfId] > 4){
			PKTStore::pktRepository_i_3_r_4_t_0[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_3_r_4_t_1[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_3_r_4_t_2[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_3_r_4_t_3[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_3_r_4_t_4[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_3_r_4_t_5[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_3_r_4_t_6[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_3_r_4_t_7[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_3_r_4_t_8[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_3_r_4_t_9[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
		}
		if(IPGlobal::ROUTER_PER_INTERFACE[intfId] > 5){
			PKTStore::pktRepository_i_3_r_5_t_0[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_3_r_5_t_1[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_3_r_5_t_2[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_3_r_5_t_3[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_3_r_5_t_4[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_3_r_5_t_5[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_3_r_5_t_6[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_3_r_5_t_7[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_3_r_5_t_8[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_3_r_5_t_9[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
		}
		if(IPGlobal::ROUTER_PER_INTERFACE[intfId] > 6){
			PKTStore::pktRepository_i_3_r_6_t_0[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_3_r_6_t_1[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_3_r_6_t_2[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_3_r_6_t_3[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_3_r_6_t_4[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_3_r_6_t_5[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_3_r_6_t_6[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_3_r_6_t_7[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_3_r_6_t_8[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_3_r_6_t_9[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
		}
		if(IPGlobal::ROUTER_PER_INTERFACE[intfId] > 7){
			PKTStore::pktRepository_i_3_r_7_t_0[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_3_r_7_t_1[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_3_r_7_t_2[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_3_r_7_t_3[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_3_r_7_t_4[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_3_r_7_t_5[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_3_r_7_t_6[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_3_r_7_t_7[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_3_r_7_t_8[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_3_r_7_t_9[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
		}
	}

	printf("Completed\n", intfId, maxLen, IPGlobal::ROUTER_PER_INTERFACE[intfId]);
	TheLog_nc_v3(Log::Info, name(),"  PKTStore Repository for Interface [%d] Initializing [%'d] per Router x 10 x %d Router RawPkt...Completed", intfId, maxLen, IPGlobal::ROUTER_PER_INTERFACE[intfId]);
}

VOID SpectaProbe::initialize_pkt_repo_i_4()
{
	int intfId = 4;
	int maxLen = IPGlobal::PPS_PER_INTERFACE[intfId] / IPGlobal::ROUTER_PER_INTERFACE[intfId];

	printf("PKTStore Repository for Interface [%d] Initializing [%'d] per Router x 10 x %d Router RawPkt... ", intfId, maxLen, IPGlobal::ROUTER_PER_INTERFACE[intfId]);
	TheLog_nc_v3(Log::Info, name(),"  PKTStore Repository for Interface [%d] Initializing [%'d] per Router x 10 x %d Router RawPkt...", intfId, maxLen, IPGlobal::ROUTER_PER_INTERFACE[intfId]);

	for(long i=0; i<maxLen; i++){
		if(IPGlobal::ROUTER_PER_INTERFACE[intfId] > 0){
			PKTStore::pktRepository_i_4_r_0_t_0[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_4_r_0_t_1[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_4_r_0_t_2[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_4_r_0_t_3[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_4_r_0_t_4[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_4_r_0_t_5[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_4_r_0_t_6[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_4_r_0_t_7[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_4_r_0_t_8[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_4_r_0_t_9[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
		}
		if(IPGlobal::ROUTER_PER_INTERFACE[intfId] > 1){
			PKTStore::pktRepository_i_4_r_1_t_0[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_4_r_1_t_1[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_4_r_1_t_2[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_4_r_1_t_3[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_4_r_1_t_4[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_4_r_1_t_5[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_4_r_1_t_6[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_4_r_1_t_7[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_4_r_1_t_8[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_4_r_1_t_9[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
		}
		if(IPGlobal::ROUTER_PER_INTERFACE[intfId] > 2){
			PKTStore::pktRepository_i_4_r_2_t_0[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_4_r_2_t_1[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_4_r_2_t_2[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_4_r_2_t_3[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_4_r_2_t_4[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_4_r_2_t_5[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_4_r_2_t_6[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_4_r_2_t_7[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_4_r_2_t_8[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_4_r_2_t_9[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
		}
		if(IPGlobal::ROUTER_PER_INTERFACE[intfId] > 3){
			PKTStore::pktRepository_i_4_r_3_t_0[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_4_r_3_t_1[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_4_r_3_t_2[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_4_r_3_t_3[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_4_r_3_t_4[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_4_r_3_t_5[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_4_r_3_t_6[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_4_r_3_t_7[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_4_r_3_t_8[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_4_r_3_t_9[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
		}
		if(IPGlobal::ROUTER_PER_INTERFACE[intfId] > 4){
			PKTStore::pktRepository_i_4_r_4_t_0[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_4_r_4_t_1[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_4_r_4_t_2[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_4_r_4_t_3[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_4_r_4_t_4[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_4_r_4_t_5[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_4_r_4_t_6[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_4_r_4_t_7[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_4_r_4_t_8[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_4_r_4_t_9[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
		}
		if(IPGlobal::ROUTER_PER_INTERFACE[intfId] > 5){
			PKTStore::pktRepository_i_4_r_5_t_0[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_4_r_5_t_1[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_4_r_5_t_2[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_4_r_5_t_3[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_4_r_5_t_4[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_4_r_5_t_5[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_4_r_5_t_6[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_4_r_5_t_7[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_4_r_5_t_8[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_4_r_5_t_9[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
		}
		if(IPGlobal::ROUTER_PER_INTERFACE[intfId] > 6){
			PKTStore::pktRepository_i_4_r_6_t_0[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_4_r_6_t_1[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_4_r_6_t_2[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_4_r_6_t_3[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_4_r_6_t_4[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_4_r_6_t_5[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_4_r_6_t_6[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_4_r_6_t_7[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_4_r_6_t_8[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_4_r_6_t_9[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
		}
		if(IPGlobal::ROUTER_PER_INTERFACE[intfId] > 7){
			PKTStore::pktRepository_i_4_r_7_t_0[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_4_r_7_t_1[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_4_r_7_t_2[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_4_r_7_t_3[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_4_r_7_t_4[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_4_r_7_t_5[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_4_r_7_t_6[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_4_r_7_t_7[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_4_r_7_t_8[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_4_r_7_t_9[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
		}
	}

	printf("Completed\n", intfId, maxLen, IPGlobal::ROUTER_PER_INTERFACE[intfId]);
	TheLog_nc_v3(Log::Info, name(),"  PKTStore Repository for Interface [%d] Initializing [%'d] per Router x 10 x %d Router RawPkt...Completed", intfId, maxLen, IPGlobal::ROUTER_PER_INTERFACE[intfId]);
}

VOID SpectaProbe::initialize_pkt_repo_i_5()
{
	int intfId = 5;
	int maxLen = IPGlobal::PPS_PER_INTERFACE[intfId] / IPGlobal::ROUTER_PER_INTERFACE[intfId];

	printf("PKTStore Repository for Interface [%d] Initializing [%'d] per Router x 10 x %d Router RawPkt... ", intfId, maxLen, IPGlobal::ROUTER_PER_INTERFACE[intfId]);
	TheLog_nc_v3(Log::Info, name(),"  PKTStore Repository for Interface [%d] Initializing [%'d] per Router x 10 x %d Router RawPkt...", intfId, maxLen, IPGlobal::ROUTER_PER_INTERFACE[intfId]);

	for(long i=0; i<maxLen; i++){
		if(IPGlobal::ROUTER_PER_INTERFACE[intfId] > 0){
			PKTStore::pktRepository_i_5_r_0_t_0[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_5_r_0_t_1[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_5_r_0_t_2[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_5_r_0_t_3[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_5_r_0_t_4[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_5_r_0_t_5[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_5_r_0_t_6[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_5_r_0_t_7[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_5_r_0_t_8[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_5_r_0_t_9[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
		}
		if(IPGlobal::ROUTER_PER_INTERFACE[intfId] > 1){
			PKTStore::pktRepository_i_5_r_1_t_0[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_5_r_1_t_1[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_5_r_1_t_2[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_5_r_1_t_3[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_5_r_1_t_4[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_5_r_1_t_5[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_5_r_1_t_6[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_5_r_1_t_7[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_5_r_1_t_8[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_5_r_1_t_9[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
		}
		if(IPGlobal::ROUTER_PER_INTERFACE[intfId] > 2){
			PKTStore::pktRepository_i_5_r_2_t_0[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_5_r_2_t_1[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_5_r_2_t_2[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_5_r_2_t_3[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_5_r_2_t_4[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_5_r_2_t_5[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_5_r_2_t_6[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_5_r_2_t_7[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_5_r_2_t_8[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_5_r_2_t_9[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
		}
		if(IPGlobal::ROUTER_PER_INTERFACE[intfId] > 3){
			PKTStore::pktRepository_i_5_r_3_t_0[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_5_r_3_t_1[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_5_r_3_t_2[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_5_r_3_t_3[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_5_r_3_t_4[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_5_r_3_t_5[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_5_r_3_t_6[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_5_r_3_t_7[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_5_r_3_t_8[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_5_r_3_t_9[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
		}
		if(IPGlobal::ROUTER_PER_INTERFACE[intfId] > 4){
			PKTStore::pktRepository_i_5_r_4_t_0[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_5_r_4_t_1[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_5_r_4_t_2[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_5_r_4_t_3[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_5_r_4_t_4[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_5_r_4_t_5[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_5_r_4_t_6[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_5_r_4_t_7[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_5_r_4_t_8[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_5_r_4_t_9[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
		}
		if(IPGlobal::ROUTER_PER_INTERFACE[intfId] > 5){
			PKTStore::pktRepository_i_5_r_5_t_0[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_5_r_5_t_1[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_5_r_5_t_2[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_5_r_5_t_3[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_5_r_5_t_4[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_5_r_5_t_5[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_5_r_5_t_6[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_5_r_5_t_7[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_5_r_5_t_8[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_5_r_5_t_9[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
		}
		if(IPGlobal::ROUTER_PER_INTERFACE[intfId] > 6){
			PKTStore::pktRepository_i_5_r_6_t_0[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_5_r_6_t_1[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_5_r_6_t_2[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_5_r_6_t_3[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_5_r_6_t_4[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_5_r_6_t_5[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_5_r_6_t_6[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_5_r_6_t_7[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_5_r_6_t_8[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_5_r_6_t_9[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
		}
		if(IPGlobal::ROUTER_PER_INTERFACE[intfId] > 7){
			PKTStore::pktRepository_i_5_r_7_t_0[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_5_r_7_t_1[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_5_r_7_t_2[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_5_r_7_t_3[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_5_r_7_t_4[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_5_r_7_t_5[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_5_r_7_t_6[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_5_r_7_t_7[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_5_r_7_t_8[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_5_r_7_t_9[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
		}
	}

	printf("Completed\n", intfId, maxLen, IPGlobal::ROUTER_PER_INTERFACE[intfId]);
	TheLog_nc_v3(Log::Info, name(),"  PKTStore Repository for Interface [%d] Initializing [%'d] per Router x 10 x %d Router RawPkt...Completed", intfId, maxLen, IPGlobal::ROUTER_PER_INTERFACE[intfId]);
}

VOID SpectaProbe::initialize_pkt_repo_i_6()
{
	int intfId = 6;
	int maxLen = IPGlobal::PPS_PER_INTERFACE[intfId] / IPGlobal::ROUTER_PER_INTERFACE[intfId];

	printf("PKTStore Repository for Interface [%d] Initializing [%'d] per Router x 10 x %d Router RawPkt... ", intfId, maxLen, IPGlobal::ROUTER_PER_INTERFACE[intfId]);
	TheLog_nc_v3(Log::Info, name(),"  PKTStore Repository for Interface [%d] Initializing [%'d] per Router x 10 x %d Router RawPkt...", intfId, maxLen, IPGlobal::ROUTER_PER_INTERFACE[intfId]);

	for(long i=0; i<maxLen; i++){
		if(IPGlobal::ROUTER_PER_INTERFACE[intfId] > 0){
			PKTStore::pktRepository_i_6_r_0_t_0[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_6_r_0_t_1[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_6_r_0_t_2[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_6_r_0_t_3[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_6_r_0_t_4[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_6_r_0_t_5[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_6_r_0_t_6[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_6_r_0_t_7[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_6_r_0_t_8[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_6_r_0_t_9[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
		}
		if(IPGlobal::ROUTER_PER_INTERFACE[intfId] > 1){
			PKTStore::pktRepository_i_6_r_1_t_0[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_6_r_1_t_1[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_6_r_1_t_2[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_6_r_1_t_3[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_6_r_1_t_4[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_6_r_1_t_5[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_6_r_1_t_6[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_6_r_1_t_7[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_6_r_1_t_8[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_6_r_1_t_9[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
		}
		if(IPGlobal::ROUTER_PER_INTERFACE[intfId] > 2){
			PKTStore::pktRepository_i_6_r_2_t_0[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_6_r_2_t_1[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_6_r_2_t_2[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_6_r_2_t_3[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_6_r_2_t_4[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_6_r_2_t_5[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_6_r_2_t_6[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_6_r_2_t_7[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_6_r_2_t_8[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_6_r_2_t_9[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
		}
		if(IPGlobal::ROUTER_PER_INTERFACE[intfId] > 3){
			PKTStore::pktRepository_i_6_r_3_t_0[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_6_r_3_t_1[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_6_r_3_t_2[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_6_r_3_t_3[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_6_r_3_t_4[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_6_r_3_t_5[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_6_r_3_t_6[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_6_r_3_t_7[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_6_r_3_t_8[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_6_r_3_t_9[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
		}
		if(IPGlobal::ROUTER_PER_INTERFACE[intfId] > 4){
			PKTStore::pktRepository_i_6_r_4_t_0[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_6_r_4_t_1[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_6_r_4_t_2[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_6_r_4_t_3[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_6_r_4_t_4[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_6_r_4_t_5[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_6_r_4_t_6[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_6_r_4_t_7[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_6_r_4_t_8[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_6_r_4_t_9[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
		}
		if(IPGlobal::ROUTER_PER_INTERFACE[intfId] > 5){
			PKTStore::pktRepository_i_6_r_5_t_0[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_6_r_5_t_1[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_6_r_5_t_2[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_6_r_5_t_3[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_6_r_5_t_4[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_6_r_5_t_5[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_6_r_5_t_6[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_6_r_5_t_7[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_6_r_5_t_8[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_6_r_5_t_9[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
		}
		if(IPGlobal::ROUTER_PER_INTERFACE[intfId] > 6){
			PKTStore::pktRepository_i_6_r_6_t_0[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_6_r_6_t_1[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_6_r_6_t_2[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_6_r_6_t_3[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_6_r_6_t_4[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_6_r_6_t_5[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_6_r_6_t_6[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_6_r_6_t_7[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_6_r_6_t_8[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_6_r_6_t_9[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
		}
		if(IPGlobal::ROUTER_PER_INTERFACE[intfId] > 7){
			PKTStore::pktRepository_i_6_r_7_t_0[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_6_r_7_t_1[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_6_r_7_t_2[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_6_r_7_t_3[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_6_r_7_t_4[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_6_r_7_t_5[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_6_r_7_t_6[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_6_r_7_t_7[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_6_r_7_t_8[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_6_r_7_t_9[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
		}
	}

	printf("Completed\n", intfId, maxLen, IPGlobal::ROUTER_PER_INTERFACE[intfId]);
	TheLog_nc_v3(Log::Info, name(),"  PKTStore Repository for Interface [%d] Initializing [%'d] per Router x 10 x %d Router RawPkt...Completed", intfId, maxLen, IPGlobal::ROUTER_PER_INTERFACE[intfId]);
}

VOID SpectaProbe::initialize_pkt_repo_i_7()
{
	int intfId = 7;
	int maxLen = IPGlobal::PPS_PER_INTERFACE[intfId] / IPGlobal::ROUTER_PER_INTERFACE[intfId];

	printf("PKTStore Repository for Interface [%d] Initializing [%'d] per Router x 10 x %d Router RawPkt... ", intfId, maxLen, IPGlobal::ROUTER_PER_INTERFACE[intfId]);
	TheLog_nc_v3(Log::Info, name(),"  PKTStore Repository for Interface [%d] Initializing [%'d] per Router x 10 x %d Router RawPkt...", intfId, maxLen, IPGlobal::ROUTER_PER_INTERFACE[intfId]);

	for(long i=0; i<maxLen; i++){
		if(IPGlobal::ROUTER_PER_INTERFACE[intfId] > 0){
			PKTStore::pktRepository_i_7_r_0_t_0[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_7_r_0_t_1[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_7_r_0_t_2[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_7_r_0_t_3[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_7_r_0_t_4[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_7_r_0_t_5[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_7_r_0_t_6[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_7_r_0_t_7[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_7_r_0_t_8[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_7_r_0_t_9[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
		}
		if(IPGlobal::ROUTER_PER_INTERFACE[intfId] > 1){
			PKTStore::pktRepository_i_7_r_1_t_0[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_7_r_1_t_1[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_7_r_1_t_2[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_7_r_1_t_3[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_7_r_1_t_4[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_7_r_1_t_5[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_7_r_1_t_6[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_7_r_1_t_7[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_7_r_1_t_8[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_7_r_1_t_9[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
		}
		if(IPGlobal::ROUTER_PER_INTERFACE[intfId] > 2){
			PKTStore::pktRepository_i_7_r_2_t_0[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_7_r_2_t_1[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_7_r_2_t_2[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_7_r_2_t_3[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_7_r_2_t_4[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_7_r_2_t_5[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_7_r_2_t_6[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_7_r_2_t_7[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_7_r_2_t_8[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_7_r_2_t_9[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
		}
		if(IPGlobal::ROUTER_PER_INTERFACE[intfId] > 3){
			PKTStore::pktRepository_i_7_r_3_t_0[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_7_r_3_t_1[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_7_r_3_t_2[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_7_r_3_t_3[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_7_r_3_t_4[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_7_r_3_t_5[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_7_r_3_t_6[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_7_r_3_t_7[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_7_r_3_t_8[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_7_r_3_t_9[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
		}
		if(IPGlobal::ROUTER_PER_INTERFACE[intfId] > 4){
			PKTStore::pktRepository_i_7_r_4_t_0[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_7_r_4_t_1[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_7_r_4_t_2[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_7_r_4_t_3[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_7_r_4_t_4[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_7_r_4_t_5[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_7_r_4_t_6[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_7_r_4_t_7[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_7_r_4_t_8[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_7_r_4_t_9[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
		}
		if(IPGlobal::ROUTER_PER_INTERFACE[intfId] > 5){
			PKTStore::pktRepository_i_7_r_5_t_0[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_7_r_5_t_1[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_7_r_5_t_2[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_7_r_5_t_3[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_7_r_5_t_4[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_7_r_5_t_5[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_7_r_5_t_6[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_7_r_5_t_7[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_7_r_5_t_8[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_7_r_5_t_9[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
		}
		if(IPGlobal::ROUTER_PER_INTERFACE[intfId] > 6){
			PKTStore::pktRepository_i_7_r_6_t_0[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_7_r_6_t_1[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_7_r_6_t_2[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_7_r_6_t_3[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_7_r_6_t_4[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_7_r_6_t_5[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_7_r_6_t_6[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_7_r_6_t_7[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_7_r_6_t_8[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_7_r_6_t_9[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
		}
		if(IPGlobal::ROUTER_PER_INTERFACE[intfId] > 7){
			PKTStore::pktRepository_i_7_r_7_t_0[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_7_r_7_t_1[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_7_r_7_t_2[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_7_r_7_t_3[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_7_r_7_t_4[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_7_r_7_t_5[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_7_r_7_t_6[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_7_r_7_t_7[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_7_r_7_t_8[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
			PKTStore::pktRepository_i_7_r_7_t_9[i] = new RawPkt(IPGlobal::MAX_PKT_LEN_PER_INTERFACE[intfId]);
		}
	}

	printf("Completed\n", intfId, maxLen, IPGlobal::ROUTER_PER_INTERFACE[intfId]);
	TheLog_nc_v3(Log::Info, name(),"  PKTStore Repository for Interface [%d] Initializing [%'d] per Router x 10 x %d Router RawPkt...Completed", intfId, maxLen, IPGlobal::ROUTER_PER_INTERFACE[intfId]);
}
