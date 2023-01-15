/*
 * S5S8SessionManager.h
 *
 *  Created on: 21 Feb 2020
 *      Author: Debashis
 */

#ifndef PLUGINS_GN_SRC_S5S8SESSIONMANAGER_H_
#define PLUGINS_GN_SRC_S5S8SESSIONMANAGER_H_

#include "IPGlobal.h"
#include "Log.h"
#include "BaseConfig.h"
#include "GTPGlobal.h"
#include "S5S8Interface.h"

using namespace std;

class S5S8SessionManager {
	private:

		uint16_t instanceId;
		BOOL 	ipSessionMgrReadyState = false;

		S5S8Interface	*s5s8Interface;

		VOID 	processQueue(int t_index);

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
		S5S8SessionManager(uint16_t id);
		~S5S8SessionManager();

		VOID run();
		BOOL isRepositoryInitialized();
};

#endif /* PLUGINS_GN_SRC_S5S8SESSIONMANAGER_H_ */
