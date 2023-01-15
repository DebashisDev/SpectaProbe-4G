/*
 * IPSessionManager.h
 *
 *  Created on: Apr 24, 2017
 *      Author: Debashis
 */

#ifndef PLUGINS_TCP_SRC_SESSIONMANAGER_H_
#define PLUGINS_TCP_SRC_SESSIONMANAGER_H_

#include <time.h>
#include <sys/time.h>
#include <sstream>
#include <locale.h>

#include "S1APInterface.h"
#include "S1APInit.h"

#include "IPGlobal.h"
#include "Log.h"
#include "S1APMessage.h"

using namespace std;

#define LOCAL_SESSION_ARRAY_SIZE 100000 				//Poosible values 10, 100, 1000, 10000, 100000....

class SctpSessionManager : BaseConfig
{
	public:
		SctpSessionManager(int id);
		~SctpSessionManager();

		VOID	run();
		BOOL  	isRepositoryInitialized();

	private:
		VOID	lockgSession();
		VOID	unLockgSession();

		int		instanceId;

		BOOL 	ipSessionMgrReadyState = false;
		long 	processStartEpochSec = 0;

		timeval curTime;

		S1APInterface	*pS1apInterface;
		S1APInit 		*pS1apInit;
		S1APMessage 	*pS1apInitFunction;

		VOID 	processQueue(int t_index);
		VOID 	processQueue_sm(bool &ip_msg_sm_busy, int &ip_msg_sm_cnt, std::unordered_map<int, Sctp> &ip_msg_sm);

		VOID 	processPacket(Sctp *pSctp);

		VOID	processQueue_sm_0_i_0_r_0(int t_index);
		VOID	processQueue_sm_0_i_0_r_1(int t_index);
		VOID	processQueue_sm_0_i_0_r_2(int t_index);
		VOID	processQueue_sm_0_i_0_r_3(int t_index);
		VOID	processQueue_sm_0_i_0_r_4(int t_index);
		VOID	processQueue_sm_0_i_0_r_5(int t_index);
		VOID	processQueue_sm_0_i_0_r_6(int t_index);
		VOID	processQueue_sm_0_i_0_r_7(int t_index);

		VOID	processQueue_sm_0_i_1_r_0(int t_index);
		VOID	processQueue_sm_0_i_1_r_1(int t_index);
		VOID	processQueue_sm_0_i_1_r_2(int t_index);
		VOID	processQueue_sm_0_i_1_r_3(int t_index);
		VOID	processQueue_sm_0_i_1_r_4(int t_index);
		VOID	processQueue_sm_0_i_1_r_5(int t_index);
		VOID	processQueue_sm_0_i_1_r_6(int t_index);
		VOID	processQueue_sm_0_i_1_r_7(int t_index);

		VOID	processQueue_sm_0_i_2_r_0(int t_index);
		VOID	processQueue_sm_0_i_2_r_1(int t_index);
		VOID	processQueue_sm_0_i_2_r_2(int t_index);
		VOID	processQueue_sm_0_i_2_r_3(int t_index);
		VOID	processQueue_sm_0_i_2_r_4(int t_index);
		VOID	processQueue_sm_0_i_2_r_5(int t_index);
		VOID	processQueue_sm_0_i_2_r_6(int t_index);
		VOID	processQueue_sm_0_i_2_r_7(int t_index);

		VOID	processQueue_sm_0_i_3_r_0(int t_index);
		VOID	processQueue_sm_0_i_3_r_1(int t_index);
		VOID	processQueue_sm_0_i_3_r_2(int t_index);
		VOID	processQueue_sm_0_i_3_r_3(int t_index);
		VOID	processQueue_sm_0_i_3_r_4(int t_index);
		VOID	processQueue_sm_0_i_3_r_5(int t_index);
		VOID	processQueue_sm_0_i_3_r_6(int t_index);
		VOID	processQueue_sm_0_i_3_r_7(int t_index);

		VOID	processQueue_sm_0_i_4_r_0(int t_index);
		VOID	processQueue_sm_0_i_4_r_1(int t_index);
		VOID	processQueue_sm_0_i_4_r_2(int t_index);
		VOID	processQueue_sm_0_i_4_r_3(int t_index);
		VOID	processQueue_sm_0_i_4_r_4(int t_index);
		VOID	processQueue_sm_0_i_4_r_5(int t_index);
		VOID	processQueue_sm_0_i_4_r_6(int t_index);
		VOID	processQueue_sm_0_i_4_r_7(int t_index);

		VOID	processQueue_sm_0_i_5_r_0(int t_index);
		VOID	processQueue_sm_0_i_5_r_1(int t_index);
		VOID	processQueue_sm_0_i_5_r_2(int t_index);
		VOID	processQueue_sm_0_i_5_r_3(int t_index);
		VOID	processQueue_sm_0_i_5_r_4(int t_index);
		VOID	processQueue_sm_0_i_5_r_5(int t_index);
		VOID	processQueue_sm_0_i_5_r_6(int t_index);
		VOID	processQueue_sm_0_i_5_r_7(int t_index);

		VOID	processQueue_sm_0_i_6_r_0(int t_index);
		VOID	processQueue_sm_0_i_6_r_1(int t_index);
		VOID	processQueue_sm_0_i_6_r_2(int t_index);
		VOID	processQueue_sm_0_i_6_r_3(int t_index);
		VOID	processQueue_sm_0_i_6_r_4(int t_index);
		VOID	processQueue_sm_0_i_6_r_5(int t_index);
		VOID	processQueue_sm_0_i_6_r_6(int t_index);
		VOID	processQueue_sm_0_i_6_r_7(int t_index);

		VOID	processQueue_sm_0_i_7_r_0(int t_index);
		VOID	processQueue_sm_0_i_7_r_1(int t_index);
		VOID	processQueue_sm_0_i_7_r_2(int t_index);
		VOID	processQueue_sm_0_i_7_r_3(int t_index);
		VOID	processQueue_sm_0_i_7_r_4(int t_index);
		VOID	processQueue_sm_0_i_7_r_5(int t_index);
		VOID	processQueue_sm_0_i_7_r_6(int t_index);
		VOID	processQueue_sm_0_i_7_r_7(int t_index);

		VOID	processQueue_sm_1_i_0_r_0(int t_index);
		VOID	processQueue_sm_1_i_0_r_1(int t_index);
		VOID	processQueue_sm_1_i_0_r_2(int t_index);
		VOID	processQueue_sm_1_i_0_r_3(int t_index);
		VOID	processQueue_sm_1_i_0_r_4(int t_index);
		VOID	processQueue_sm_1_i_0_r_5(int t_index);
		VOID	processQueue_sm_1_i_0_r_6(int t_index);
		VOID	processQueue_sm_1_i_0_r_7(int t_index);

		VOID	processQueue_sm_1_i_1_r_0(int t_index);
		VOID	processQueue_sm_1_i_1_r_1(int t_index);
		VOID	processQueue_sm_1_i_1_r_2(int t_index);
		VOID	processQueue_sm_1_i_1_r_3(int t_index);
		VOID	processQueue_sm_1_i_1_r_4(int t_index);
		VOID	processQueue_sm_1_i_1_r_5(int t_index);
		VOID	processQueue_sm_1_i_1_r_6(int t_index);
		VOID	processQueue_sm_1_i_1_r_7(int t_index);

		VOID	processQueue_sm_1_i_2_r_0(int t_index);
		VOID	processQueue_sm_1_i_2_r_1(int t_index);
		VOID	processQueue_sm_1_i_2_r_2(int t_index);
		VOID	processQueue_sm_1_i_2_r_3(int t_index);
		VOID	processQueue_sm_1_i_2_r_4(int t_index);
		VOID	processQueue_sm_1_i_2_r_5(int t_index);
		VOID	processQueue_sm_1_i_2_r_6(int t_index);
		VOID	processQueue_sm_1_i_2_r_7(int t_index);

		VOID	processQueue_sm_1_i_3_r_0(int t_index);
		VOID	processQueue_sm_1_i_3_r_1(int t_index);
		VOID	processQueue_sm_1_i_3_r_2(int t_index);
		VOID	processQueue_sm_1_i_3_r_3(int t_index);
		VOID	processQueue_sm_1_i_3_r_4(int t_index);
		VOID	processQueue_sm_1_i_3_r_5(int t_index);
		VOID	processQueue_sm_1_i_3_r_6(int t_index);
		VOID	processQueue_sm_1_i_3_r_7(int t_index);

		VOID	processQueue_sm_1_i_4_r_0(int t_index);
		VOID	processQueue_sm_1_i_4_r_1(int t_index);
		VOID	processQueue_sm_1_i_4_r_2(int t_index);
		VOID	processQueue_sm_1_i_4_r_3(int t_index);
		VOID	processQueue_sm_1_i_4_r_4(int t_index);
		VOID	processQueue_sm_1_i_4_r_5(int t_index);
		VOID	processQueue_sm_1_i_4_r_6(int t_index);
		VOID	processQueue_sm_1_i_4_r_7(int t_index);

		VOID	processQueue_sm_1_i_5_r_0(int t_index);
		VOID	processQueue_sm_1_i_5_r_1(int t_index);
		VOID	processQueue_sm_1_i_5_r_2(int t_index);
		VOID	processQueue_sm_1_i_5_r_3(int t_index);
		VOID	processQueue_sm_1_i_5_r_4(int t_index);
		VOID	processQueue_sm_1_i_5_r_5(int t_index);
		VOID	processQueue_sm_1_i_5_r_6(int t_index);
		VOID	processQueue_sm_1_i_5_r_7(int t_index);

		VOID	processQueue_sm_1_i_6_r_0(int t_index);
		VOID	processQueue_sm_1_i_6_r_1(int t_index);
		VOID	processQueue_sm_1_i_6_r_2(int t_index);
		VOID	processQueue_sm_1_i_6_r_3(int t_index);
		VOID	processQueue_sm_1_i_6_r_4(int t_index);
		VOID	processQueue_sm_1_i_6_r_5(int t_index);
		VOID	processQueue_sm_1_i_6_r_6(int t_index);
		VOID	processQueue_sm_1_i_6_r_7(int t_index);

		VOID	processQueue_sm_1_i_7_r_0(int t_index);
		VOID	processQueue_sm_1_i_7_r_1(int t_index);
		VOID	processQueue_sm_1_i_7_r_2(int t_index);
		VOID	processQueue_sm_1_i_7_r_3(int t_index);
		VOID	processQueue_sm_1_i_7_r_4(int t_index);
		VOID	processQueue_sm_1_i_7_r_5(int t_index);
		VOID	processQueue_sm_1_i_7_r_6(int t_index);
		VOID	processQueue_sm_1_i_7_r_7(int t_index);

		VOID	processQueue_sm_2_i_0_r_0(int t_index);
		VOID	processQueue_sm_2_i_0_r_1(int t_index);
		VOID	processQueue_sm_2_i_0_r_2(int t_index);
		VOID	processQueue_sm_2_i_0_r_3(int t_index);
		VOID	processQueue_sm_2_i_0_r_4(int t_index);
		VOID	processQueue_sm_2_i_0_r_5(int t_index);
		VOID	processQueue_sm_2_i_0_r_6(int t_index);
		VOID	processQueue_sm_2_i_0_r_7(int t_index);

		VOID	processQueue_sm_2_i_1_r_0(int t_index);
		VOID	processQueue_sm_2_i_1_r_1(int t_index);
		VOID	processQueue_sm_2_i_1_r_2(int t_index);
		VOID	processQueue_sm_2_i_1_r_3(int t_index);
		VOID	processQueue_sm_2_i_1_r_4(int t_index);
		VOID	processQueue_sm_2_i_1_r_5(int t_index);
		VOID	processQueue_sm_2_i_1_r_6(int t_index);
		VOID	processQueue_sm_2_i_1_r_7(int t_index);

		VOID	processQueue_sm_2_i_2_r_0(int t_index);
		VOID	processQueue_sm_2_i_2_r_1(int t_index);
		VOID	processQueue_sm_2_i_2_r_2(int t_index);
		VOID	processQueue_sm_2_i_2_r_3(int t_index);
		VOID	processQueue_sm_2_i_2_r_4(int t_index);
		VOID	processQueue_sm_2_i_2_r_5(int t_index);
		VOID	processQueue_sm_2_i_2_r_6(int t_index);
		VOID	processQueue_sm_2_i_2_r_7(int t_index);

		VOID	processQueue_sm_2_i_3_r_0(int t_index);
		VOID	processQueue_sm_2_i_3_r_1(int t_index);
		VOID	processQueue_sm_2_i_3_r_2(int t_index);
		VOID	processQueue_sm_2_i_3_r_3(int t_index);
		VOID	processQueue_sm_2_i_3_r_4(int t_index);
		VOID	processQueue_sm_2_i_3_r_5(int t_index);
		VOID	processQueue_sm_2_i_3_r_6(int t_index);
		VOID	processQueue_sm_2_i_3_r_7(int t_index);

		VOID	processQueue_sm_2_i_4_r_0(int t_index);
		VOID	processQueue_sm_2_i_4_r_1(int t_index);
		VOID	processQueue_sm_2_i_4_r_2(int t_index);
		VOID	processQueue_sm_2_i_4_r_3(int t_index);
		VOID	processQueue_sm_2_i_4_r_4(int t_index);
		VOID	processQueue_sm_2_i_4_r_5(int t_index);
		VOID	processQueue_sm_2_i_4_r_6(int t_index);
		VOID	processQueue_sm_2_i_4_r_7(int t_index);

		VOID	processQueue_sm_2_i_5_r_0(int t_index);
		VOID	processQueue_sm_2_i_5_r_1(int t_index);
		VOID	processQueue_sm_2_i_5_r_2(int t_index);
		VOID	processQueue_sm_2_i_5_r_3(int t_index);
		VOID	processQueue_sm_2_i_5_r_4(int t_index);
		VOID	processQueue_sm_2_i_5_r_5(int t_index);
		VOID	processQueue_sm_2_i_5_r_6(int t_index);
		VOID	processQueue_sm_2_i_5_r_7(int t_index);

		VOID	processQueue_sm_2_i_6_r_0(int t_index);
		VOID	processQueue_sm_2_i_6_r_1(int t_index);
		VOID	processQueue_sm_2_i_6_r_2(int t_index);
		VOID	processQueue_sm_2_i_6_r_3(int t_index);
		VOID	processQueue_sm_2_i_6_r_4(int t_index);
		VOID	processQueue_sm_2_i_6_r_5(int t_index);
		VOID	processQueue_sm_2_i_6_r_6(int t_index);
		VOID	processQueue_sm_2_i_6_r_7(int t_index);

		VOID	processQueue_sm_2_i_7_r_0(int t_index);
		VOID	processQueue_sm_2_i_7_r_1(int t_index);
		VOID	processQueue_sm_2_i_7_r_2(int t_index);
		VOID	processQueue_sm_2_i_7_r_3(int t_index);
		VOID	processQueue_sm_2_i_7_r_4(int t_index);
		VOID	processQueue_sm_2_i_7_r_5(int t_index);
		VOID	processQueue_sm_2_i_7_r_6(int t_index);
		VOID	processQueue_sm_2_i_7_r_7(int t_index);

		VOID	processQueue_sm_3_i_0_r_0(int t_index);
		VOID	processQueue_sm_3_i_0_r_1(int t_index);
		VOID	processQueue_sm_3_i_0_r_2(int t_index);
		VOID	processQueue_sm_3_i_0_r_3(int t_index);
		VOID	processQueue_sm_3_i_0_r_4(int t_index);
		VOID	processQueue_sm_3_i_0_r_5(int t_index);
		VOID	processQueue_sm_3_i_0_r_6(int t_index);
		VOID	processQueue_sm_3_i_0_r_7(int t_index);

		VOID	processQueue_sm_3_i_1_r_0(int t_index);
		VOID	processQueue_sm_3_i_1_r_1(int t_index);
		VOID	processQueue_sm_3_i_1_r_2(int t_index);
		VOID	processQueue_sm_3_i_1_r_3(int t_index);
		VOID	processQueue_sm_3_i_1_r_4(int t_index);
		VOID	processQueue_sm_3_i_1_r_5(int t_index);
		VOID	processQueue_sm_3_i_1_r_6(int t_index);
		VOID	processQueue_sm_3_i_1_r_7(int t_index);

		VOID	processQueue_sm_3_i_2_r_0(int t_index);
		VOID	processQueue_sm_3_i_2_r_1(int t_index);
		VOID	processQueue_sm_3_i_2_r_2(int t_index);
		VOID	processQueue_sm_3_i_2_r_3(int t_index);
		VOID	processQueue_sm_3_i_2_r_4(int t_index);
		VOID	processQueue_sm_3_i_2_r_5(int t_index);
		VOID	processQueue_sm_3_i_2_r_6(int t_index);
		VOID	processQueue_sm_3_i_2_r_7(int t_index);

		VOID	processQueue_sm_3_i_3_r_0(int t_index);
		VOID	processQueue_sm_3_i_3_r_1(int t_index);
		VOID	processQueue_sm_3_i_3_r_2(int t_index);
		VOID	processQueue_sm_3_i_3_r_3(int t_index);
		VOID	processQueue_sm_3_i_3_r_4(int t_index);
		VOID	processQueue_sm_3_i_3_r_5(int t_index);
		VOID	processQueue_sm_3_i_3_r_6(int t_index);
		VOID	processQueue_sm_3_i_3_r_7(int t_index);

		VOID	processQueue_sm_3_i_4_r_0(int t_index);
		VOID	processQueue_sm_3_i_4_r_1(int t_index);
		VOID	processQueue_sm_3_i_4_r_2(int t_index);
		VOID	processQueue_sm_3_i_4_r_3(int t_index);
		VOID	processQueue_sm_3_i_4_r_4(int t_index);
		VOID	processQueue_sm_3_i_4_r_5(int t_index);
		VOID	processQueue_sm_3_i_4_r_6(int t_index);
		VOID	processQueue_sm_3_i_4_r_7(int t_index);

		VOID	processQueue_sm_3_i_5_r_0(int t_index);
		VOID	processQueue_sm_3_i_5_r_1(int t_index);
		VOID	processQueue_sm_3_i_5_r_2(int t_index);
		VOID	processQueue_sm_3_i_5_r_3(int t_index);
		VOID	processQueue_sm_3_i_5_r_4(int t_index);
		VOID	processQueue_sm_3_i_5_r_5(int t_index);
		VOID	processQueue_sm_3_i_5_r_6(int t_index);
		VOID	processQueue_sm_3_i_5_r_7(int t_index);

		VOID	processQueue_sm_3_i_6_r_0(int t_index);
		VOID	processQueue_sm_3_i_6_r_1(int t_index);
		VOID	processQueue_sm_3_i_6_r_2(int t_index);
		VOID	processQueue_sm_3_i_6_r_3(int t_index);
		VOID	processQueue_sm_3_i_6_r_4(int t_index);
		VOID	processQueue_sm_3_i_6_r_5(int t_index);
		VOID	processQueue_sm_3_i_6_r_6(int t_index);
		VOID	processQueue_sm_3_i_6_r_7(int t_index);

		VOID	processQueue_sm_3_i_7_r_0(int t_index);
		VOID	processQueue_sm_3_i_7_r_1(int t_index);
		VOID	processQueue_sm_3_i_7_r_2(int t_index);
		VOID	processQueue_sm_3_i_7_r_3(int t_index);
		VOID	processQueue_sm_3_i_7_r_4(int t_index);
		VOID	processQueue_sm_3_i_7_r_5(int t_index);
		VOID	processQueue_sm_3_i_7_r_6(int t_index);
		VOID	processQueue_sm_3_i_7_r_7(int t_index);

};

#endif /* PLUGINS_TCP_SRC_SESSIONMANAGER_H_ */
