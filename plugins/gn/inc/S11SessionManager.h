/*
 * S11SessionManager.h
 *
 *  Created on: 19-Feb-2020
 *      Author: Ishan
 */

#ifndef PLUGINS_GN_INC_S11SESSIONMANAGER_H_
#define PLUGINS_GN_INC_S11SESSIONMANAGER_H_

#include "S11Interface.h"
#include "IPGlobal.h"
#include "Log.h"
#include "BaseConfig.h"
#include "GTPGlobal.h"

using namespace std;

class S11SessionManager  : BaseConfig
{
	private:
		int		instanceId;
		BOOL 	ipSessionMgrReadyState = false;

		S11Interface	*s11Interface;

		VOID 	IP_ProcessQueue(int t_index);

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

		VOID 	processQueue_sm(bool &ip_msg_sm_busy, int &ip_msg_sm_cnt, std::unordered_map<int, MPacket> &ip_msg_sm);
		VOID 	processPacket(MPacket *pSctp);

		VOID	lockgSession();
		VOID	unLockgSession();

	public:
		S11SessionManager(int id);
		~S11SessionManager();

		VOID	run();
		BOOL  	isRepositoryInitialized();
};

#endif /* PLUGINS_GN_INC_S11SESSIONMANAGER_H_ */
