/*
 * BWData.h
 *
 *  Created on: 27-may-2016
 *      Author: Debashis
 */

#ifndef SRC_BWDATA_H_
#define SRC_BWDATA_H_

#include <stdlib.h>    //malloc
#include <string.h>    //strlen
#include <ctime>
#include "Log.h"
#include "BaseConfig.h"
#include "IPGlobal.h"

#define BW_TIME_INDEX	100

class BWData : public BaseConfig {
	private:

		int interfaceId = 0;
		int routerId = 0;

		uint64_t	volume = 0;
		uint64_t bwval = 0;
		int	  curSec = 0;
		uint8_t  isUpDir = 0;

		bwData bw_i_0_r_0_0[BW_TIME_INDEX];
		bwData bw_i_0_r_0_1[BW_TIME_INDEX];
		bwData bw_i_0_r_1_0[BW_TIME_INDEX];
		bwData bw_i_0_r_1_1[BW_TIME_INDEX];
		bwData bw_i_0_r_2_0[BW_TIME_INDEX];
		bwData bw_i_0_r_2_1[BW_TIME_INDEX];
		bwData bw_i_0_r_3_0[BW_TIME_INDEX];
		bwData bw_i_0_r_3_1[BW_TIME_INDEX];
		bwData bw_i_0_r_4_0[BW_TIME_INDEX];
		bwData bw_i_0_r_4_1[BW_TIME_INDEX];
		bwData bw_i_0_r_5_0[BW_TIME_INDEX];
		bwData bw_i_0_r_5_1[BW_TIME_INDEX];
		bwData bw_i_0_r_6_0[BW_TIME_INDEX];
		bwData bw_i_0_r_6_1[BW_TIME_INDEX];
		bwData bw_i_0_r_7_0[BW_TIME_INDEX];
		bwData bw_i_0_r_7_1[BW_TIME_INDEX];

		bwData bw_i_1_r_0_0[BW_TIME_INDEX];
		bwData bw_i_1_r_0_1[BW_TIME_INDEX];
		bwData bw_i_1_r_1_0[BW_TIME_INDEX];
		bwData bw_i_1_r_1_1[BW_TIME_INDEX];
		bwData bw_i_1_r_2_0[BW_TIME_INDEX];
		bwData bw_i_1_r_2_1[BW_TIME_INDEX];
		bwData bw_i_1_r_3_0[BW_TIME_INDEX];
		bwData bw_i_1_r_3_1[BW_TIME_INDEX];
		bwData bw_i_1_r_4_0[BW_TIME_INDEX];
		bwData bw_i_1_r_4_1[BW_TIME_INDEX];
		bwData bw_i_1_r_5_0[BW_TIME_INDEX];
		bwData bw_i_1_r_5_1[BW_TIME_INDEX];
		bwData bw_i_1_r_6_0[BW_TIME_INDEX];
		bwData bw_i_1_r_6_1[BW_TIME_INDEX];
		bwData bw_i_1_r_7_0[BW_TIME_INDEX];
		bwData bw_i_1_r_7_1[BW_TIME_INDEX];

		bwData bw_i_2_r_0_0[BW_TIME_INDEX];
		bwData bw_i_2_r_0_1[BW_TIME_INDEX];
		bwData bw_i_2_r_1_0[BW_TIME_INDEX];
		bwData bw_i_2_r_1_1[BW_TIME_INDEX];
		bwData bw_i_2_r_2_0[BW_TIME_INDEX];
		bwData bw_i_2_r_2_1[BW_TIME_INDEX];
		bwData bw_i_2_r_3_0[BW_TIME_INDEX];
		bwData bw_i_2_r_3_1[BW_TIME_INDEX];
		bwData bw_i_2_r_4_0[BW_TIME_INDEX];
		bwData bw_i_2_r_4_1[BW_TIME_INDEX];
		bwData bw_i_2_r_5_0[BW_TIME_INDEX];
		bwData bw_i_2_r_5_1[BW_TIME_INDEX];
		bwData bw_i_2_r_6_0[BW_TIME_INDEX];
		bwData bw_i_2_r_6_1[BW_TIME_INDEX];
		bwData bw_i_2_r_7_0[BW_TIME_INDEX];
		bwData bw_i_2_r_7_1[BW_TIME_INDEX];

		bwData bw_i_3_r_0_0[BW_TIME_INDEX];
		bwData bw_i_3_r_0_1[BW_TIME_INDEX];
		bwData bw_i_3_r_1_0[BW_TIME_INDEX];
		bwData bw_i_3_r_1_1[BW_TIME_INDEX];
		bwData bw_i_3_r_2_0[BW_TIME_INDEX];
		bwData bw_i_3_r_2_1[BW_TIME_INDEX];
		bwData bw_i_3_r_3_0[BW_TIME_INDEX];
		bwData bw_i_3_r_3_1[BW_TIME_INDEX];
		bwData bw_i_3_r_4_0[BW_TIME_INDEX];
		bwData bw_i_3_r_4_1[BW_TIME_INDEX];
		bwData bw_i_3_r_5_0[BW_TIME_INDEX];
		bwData bw_i_3_r_5_1[BW_TIME_INDEX];
		bwData bw_i_3_r_6_0[BW_TIME_INDEX];
		bwData bw_i_3_r_6_1[BW_TIME_INDEX];
		bwData bw_i_3_r_7_0[BW_TIME_INDEX];
		bwData bw_i_3_r_7_1[BW_TIME_INDEX];

		bwData bw_i_4_r_0_0[BW_TIME_INDEX];
		bwData bw_i_4_r_0_1[BW_TIME_INDEX];
		bwData bw_i_4_r_1_0[BW_TIME_INDEX];
		bwData bw_i_4_r_1_1[BW_TIME_INDEX];
		bwData bw_i_4_r_2_0[BW_TIME_INDEX];
		bwData bw_i_4_r_2_1[BW_TIME_INDEX];
		bwData bw_i_4_r_3_0[BW_TIME_INDEX];
		bwData bw_i_4_r_3_1[BW_TIME_INDEX];
		bwData bw_i_4_r_4_0[BW_TIME_INDEX];
		bwData bw_i_4_r_4_1[BW_TIME_INDEX];
		bwData bw_i_4_r_5_0[BW_TIME_INDEX];
		bwData bw_i_4_r_5_1[BW_TIME_INDEX];
		bwData bw_i_4_r_6_0[BW_TIME_INDEX];
		bwData bw_i_4_r_6_1[BW_TIME_INDEX];
		bwData bw_i_4_r_7_0[BW_TIME_INDEX];
		bwData bw_i_4_r_7_1[BW_TIME_INDEX];

		bwData bw_i_5_r_0_0[BW_TIME_INDEX];
		bwData bw_i_5_r_0_1[BW_TIME_INDEX];
		bwData bw_i_5_r_1_0[BW_TIME_INDEX];
		bwData bw_i_5_r_1_1[BW_TIME_INDEX];
		bwData bw_i_5_r_2_0[BW_TIME_INDEX];
		bwData bw_i_5_r_2_1[BW_TIME_INDEX];
		bwData bw_i_5_r_3_0[BW_TIME_INDEX];
		bwData bw_i_5_r_3_1[BW_TIME_INDEX];
		bwData bw_i_5_r_4_0[BW_TIME_INDEX];
		bwData bw_i_5_r_4_1[BW_TIME_INDEX];
		bwData bw_i_5_r_5_0[BW_TIME_INDEX];
		bwData bw_i_5_r_5_1[BW_TIME_INDEX];
		bwData bw_i_5_r_6_0[BW_TIME_INDEX];
		bwData bw_i_5_r_6_1[BW_TIME_INDEX];
		bwData bw_i_5_r_7_0[BW_TIME_INDEX];
		bwData bw_i_5_r_7_1[BW_TIME_INDEX];

		bwData bw_i_6_r_0_0[BW_TIME_INDEX];
		bwData bw_i_6_r_0_1[BW_TIME_INDEX];
		bwData bw_i_6_r_1_0[BW_TIME_INDEX];
		bwData bw_i_6_r_1_1[BW_TIME_INDEX];
		bwData bw_i_6_r_2_0[BW_TIME_INDEX];
		bwData bw_i_6_r_2_1[BW_TIME_INDEX];
		bwData bw_i_6_r_3_0[BW_TIME_INDEX];
		bwData bw_i_6_r_3_1[BW_TIME_INDEX];
		bwData bw_i_6_r_4_0[BW_TIME_INDEX];
		bwData bw_i_6_r_4_1[BW_TIME_INDEX];
		bwData bw_i_6_r_5_0[BW_TIME_INDEX];
		bwData bw_i_6_r_5_1[BW_TIME_INDEX];
		bwData bw_i_6_r_6_0[BW_TIME_INDEX];
		bwData bw_i_6_r_6_1[BW_TIME_INDEX];
		bwData bw_i_6_r_7_0[BW_TIME_INDEX];
		bwData bw_i_6_r_7_1[BW_TIME_INDEX];

		bwData bw_i_7_r_0_0[BW_TIME_INDEX];
		bwData bw_i_7_r_0_1[BW_TIME_INDEX];
		bwData bw_i_7_r_1_0[BW_TIME_INDEX];
		bwData bw_i_7_r_1_1[BW_TIME_INDEX];
		bwData bw_i_7_r_2_0[BW_TIME_INDEX];
		bwData bw_i_7_r_2_1[BW_TIME_INDEX];
		bwData bw_i_7_r_3_0[BW_TIME_INDEX];
		bwData bw_i_7_r_3_1[BW_TIME_INDEX];
		bwData bw_i_7_r_4_0[BW_TIME_INDEX];
		bwData bw_i_7_r_4_1[BW_TIME_INDEX];
		bwData bw_i_7_r_5_0[BW_TIME_INDEX];
		bwData bw_i_7_r_5_1[BW_TIME_INDEX];
		bwData bw_i_7_r_6_0[BW_TIME_INDEX];
		bwData bw_i_7_r_6_1[BW_TIME_INDEX];
		bwData bw_i_7_r_7_0[BW_TIME_INDEX];
		bwData bw_i_7_r_7_1[BW_TIME_INDEX];

		bwData calculateBwData(int t_index, bwData (&bw)[BW_TIME_INDEX]);

		VOID setBWData_i_0(int t_index);
		VOID setBWData_i_1(int t_index);
		VOID setBWData_i_2(int t_index);
		VOID setBWData_i_3(int t_index);
		VOID setBWData_i_4(int t_index);
		VOID setBWData_i_5(int t_index);
		VOID setBWData_i_6(int t_index);
		VOID setBWData_i_7(int t_index);

		VOID processBwData(bwData (&bw)[BW_TIME_INDEX]);

		VOID processBw(int t_index);
		VOID processBw_i_0(int t_index);
		VOID processBw_i_1(int t_index);
		VOID processBw_i_2(int t_index);
		VOID processBw_i_3(int t_index);
		VOID processBw_i_4(int t_index);
		VOID processBw_i_5(int t_index);
		VOID processBw_i_6(int t_index);
		VOID processBw_i_7(int t_index);

	public:
		BWData(int intfid, int rid);
		~BWData();

		VOID updateBWData(int curMin, MPacket *msgObj);
		VOID setBWData(int curMin);
};

#endif /* SRC_BWDATA_H_ */
