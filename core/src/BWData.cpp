/*
 * BWData.cpp
 *
 *  Created on: 27-May-2016
 *      Author: Debashis
 */

#include "BWData.h"

BWData::BWData(int intfid, int rid)
{
	this->_name = "BWData         ";
	this->setLogLevel(Log::theLog().level());
	this->interfaceId = intfid;
	this->routerId = rid;

	printf("** BWData:: Initialized for Interface [%d]\n", this->interfaceId);
}

BWData::~BWData()
{}

VOID BWData::updateBWData(int curMin, MPacket *msgObj)
{
	volume = msgObj->frSize;
	isUpDir = msgObj->dirUserNetwork;
	curSec = msgObj->frTimeEpochSec % 100;

	/* 	Write in curMin index based on Odd or Even min
	**	if curMin = 3, write in _1 if curMin = 4 write in _0
	**	Reading will happen opposite
	*/

	int t_index = curMin % 2;
	processBw(t_index);
}

VOID BWData::setBWData(int curMin)
{
	int t_index = curMin % 2;
	if(t_index == 0) t_index = 1;
	else if(t_index == 1) t_index = 0;

	switch(interfaceId)
	{
		case 0:
			setBWData_i_0(t_index);
			break;

		case 1:
			setBWData_i_1(t_index);
			break;

		case 2:
			setBWData_i_2(t_index);
			break;

		case 3:
			setBWData_i_3(t_index);
			break;

		case 4:
			setBWData_i_4(t_index);
			break;

		case 5:
			setBWData_i_5(t_index);
			break;

		case 6:
			setBWData_i_6(t_index);
			break;

		case 7:
			setBWData_i_7(t_index);
			break;
	}
}

VOID BWData::setBWData_i_0(int t_index)
{
	bwData bw;

	switch(routerId)
	{
		case 0:
			{
				switch(t_index)
				{
					case 0:
						bw = calculateBwData(t_index, bw_i_0_r_0_0);
						break;

					case 1:
						bw = calculateBwData(t_index, bw_i_0_r_0_1);
						break;
				}
			}
			IPGlobal::BW_MBPS_i_0_r_0.Bw = bw.Bw;
			IPGlobal::BW_MBPS_i_0_r_0.upBw = bw.upBw;
			IPGlobal::BW_MBPS_i_0_r_0.dnBw = bw.dnBw;
			IPGlobal::BW_MBPS_i_0_r_0.totalVol = bw.totalVol;
			IPGlobal::BW_MBPS_i_0_r_0.upTotalVol = bw.upTotalVol;
			IPGlobal::BW_MBPS_i_0_r_0.dnTotalVol = bw.dnTotalVol;
			IPGlobal::BW_MBPS_i_0_r_0.peakTotalVol 	= bw.peakTotalVol;
			IPGlobal::BW_MBPS_i_0_r_0.peakUpTotalVol = bw.peakUpTotalVol;
			IPGlobal::BW_MBPS_i_0_r_0.peakDnTotalVol = bw.peakDnTotalVol;

			IPGlobal::BW_MBPS_i_0_r_0.avgTotalBw= bw.avgTotalBw;
			IPGlobal::BW_MBPS_i_0_r_0.avgUpBw 	= bw.avgUpBw;
			IPGlobal::BW_MBPS_i_0_r_0.avgDnBw 	= bw.avgDnBw;


			break;

		case 1:
			{
				switch(t_index)
				{
					case 0:
						bw = calculateBwData(t_index, bw_i_0_r_1_0);
						break;

					case 1:
						bw = calculateBwData(t_index, bw_i_0_r_1_1);
						break;
				}
			}
			IPGlobal::BW_MBPS_i_0_r_1.Bw = bw.Bw;
			IPGlobal::BW_MBPS_i_0_r_1.upBw = bw.upBw;
			IPGlobal::BW_MBPS_i_0_r_1.dnBw = bw.dnBw;
			IPGlobal::BW_MBPS_i_0_r_1.totalVol = bw.totalVol;
			IPGlobal::BW_MBPS_i_0_r_1.upTotalVol = bw.upTotalVol;
			IPGlobal::BW_MBPS_i_0_r_1.dnTotalVol = bw.dnTotalVol;
			IPGlobal::BW_MBPS_i_0_r_1.peakTotalVol 	= bw.peakTotalVol;
			IPGlobal::BW_MBPS_i_0_r_1.peakUpTotalVol = bw.peakUpTotalVol;
			IPGlobal::BW_MBPS_i_0_r_1.peakDnTotalVol = bw.peakDnTotalVol;
			IPGlobal::BW_MBPS_i_0_r_1.avgTotalBw = bw.avgTotalBw;
			IPGlobal::BW_MBPS_i_0_r_1.avgUpBw = bw.avgUpBw;
			IPGlobal::BW_MBPS_i_0_r_1.avgDnBw = bw.avgDnBw;


			break;

		case 2:
			{
				switch(t_index)
				{
					case 0:
						bw = calculateBwData(t_index, bw_i_0_r_2_0);
						break;

					case 1:
						bw = calculateBwData(t_index, bw_i_0_r_2_1);
						break;
				}
			}
			IPGlobal::BW_MBPS_i_0_r_2.Bw = bw.Bw;
			IPGlobal::BW_MBPS_i_0_r_2.upBw = bw.upBw;
			IPGlobal::BW_MBPS_i_0_r_2.dnBw = bw.dnBw;
			IPGlobal::BW_MBPS_i_0_r_2.totalVol = bw.totalVol;
			IPGlobal::BW_MBPS_i_0_r_2.upTotalVol = bw.upTotalVol;
			IPGlobal::BW_MBPS_i_0_r_2.dnTotalVol = bw.dnTotalVol;
			IPGlobal::BW_MBPS_i_0_r_2.peakTotalVol 	= bw.peakTotalVol;
			IPGlobal::BW_MBPS_i_0_r_2.peakUpTotalVol = bw.peakUpTotalVol;
			IPGlobal::BW_MBPS_i_0_r_2.peakDnTotalVol = bw.peakDnTotalVol;
			IPGlobal::BW_MBPS_i_0_r_2.avgTotalBw = bw.avgTotalBw;
			IPGlobal::BW_MBPS_i_0_r_2.avgUpBw = bw.avgUpBw;
			IPGlobal::BW_MBPS_i_0_r_2.avgDnBw = bw.avgDnBw;


			break;

		case 3:
			{
				switch(t_index)
				{
					case 0:
						bw = calculateBwData(t_index, bw_i_0_r_3_0);
						break;

					case 1:
						bw = calculateBwData(t_index, bw_i_0_r_3_1);
						break;
				}
			}
			IPGlobal::BW_MBPS_i_0_r_3.Bw = bw.Bw;
			IPGlobal::BW_MBPS_i_0_r_3.upBw = bw.upBw;
			IPGlobal::BW_MBPS_i_0_r_3.dnBw = bw.dnBw;
			IPGlobal::BW_MBPS_i_0_r_3.totalVol = bw.totalVol;
			IPGlobal::BW_MBPS_i_0_r_3.upTotalVol = bw.upTotalVol;
			IPGlobal::BW_MBPS_i_0_r_3.dnTotalVol = bw.dnTotalVol;
			IPGlobal::BW_MBPS_i_0_r_3.peakTotalVol 	= bw.peakTotalVol;
			IPGlobal::BW_MBPS_i_0_r_3.peakUpTotalVol = bw.peakUpTotalVol;
			IPGlobal::BW_MBPS_i_0_r_3.peakDnTotalVol = bw.peakDnTotalVol;
			IPGlobal::BW_MBPS_i_0_r_3.avgTotalBw = bw.avgTotalBw;
			IPGlobal::BW_MBPS_i_0_r_3.avgUpBw = bw.avgUpBw;
			IPGlobal::BW_MBPS_i_0_r_3.avgDnBw = bw.avgDnBw;
			break;

		case 4:
			{
				switch(t_index)
				{
					case 0:
						bw = calculateBwData(t_index, bw_i_0_r_4_0);
						break;

					case 1:
						bw = calculateBwData(t_index, bw_i_0_r_4_1);
						break;
				}
			}
			IPGlobal::BW_MBPS_i_0_r_4.Bw = bw.Bw;
			IPGlobal::BW_MBPS_i_0_r_4.upBw = bw.upBw;
			IPGlobal::BW_MBPS_i_0_r_4.dnBw = bw.dnBw;
			IPGlobal::BW_MBPS_i_0_r_4.totalVol = bw.totalVol;
			IPGlobal::BW_MBPS_i_0_r_4.upTotalVol = bw.upTotalVol;
			IPGlobal::BW_MBPS_i_0_r_4.dnTotalVol = bw.dnTotalVol;
			IPGlobal::BW_MBPS_i_0_r_4.peakTotalVol 	= bw.peakTotalVol;
			IPGlobal::BW_MBPS_i_0_r_4.peakUpTotalVol = bw.peakUpTotalVol;
			IPGlobal::BW_MBPS_i_0_r_4.peakDnTotalVol = bw.peakDnTotalVol;
			IPGlobal::BW_MBPS_i_0_r_4.avgTotalBw = bw.avgTotalBw;
			IPGlobal::BW_MBPS_i_0_r_4.avgUpBw = bw.avgUpBw;
			IPGlobal::BW_MBPS_i_0_r_4.avgDnBw = bw.avgDnBw;
			break;

		case 5:
			{
				switch(t_index)
				{
					case 0:
						bw = calculateBwData(t_index, bw_i_0_r_5_0);
						break;

					case 1:
						bw = calculateBwData(t_index, bw_i_0_r_5_1);
						break;
				}
			}
			IPGlobal::BW_MBPS_i_0_r_5.Bw = bw.Bw;
			IPGlobal::BW_MBPS_i_0_r_5.upBw = bw.upBw;
			IPGlobal::BW_MBPS_i_0_r_5.dnBw = bw.dnBw;
			IPGlobal::BW_MBPS_i_0_r_5.totalVol = bw.totalVol;
			IPGlobal::BW_MBPS_i_0_r_5.upTotalVol = bw.upTotalVol;
			IPGlobal::BW_MBPS_i_0_r_5.dnTotalVol = bw.dnTotalVol;
			IPGlobal::BW_MBPS_i_0_r_5.peakTotalVol 	= bw.peakTotalVol;
			IPGlobal::BW_MBPS_i_0_r_5.peakUpTotalVol = bw.peakUpTotalVol;
			IPGlobal::BW_MBPS_i_0_r_5.peakDnTotalVol = bw.peakDnTotalVol;
			IPGlobal::BW_MBPS_i_0_r_5.avgTotalBw = bw.avgTotalBw;
			IPGlobal::BW_MBPS_i_0_r_5.avgUpBw = bw.avgUpBw;
			IPGlobal::BW_MBPS_i_0_r_5.avgDnBw = bw.avgDnBw;
			break;

		case 6:
			{
				switch(t_index)
				{
					case 0:
						bw = calculateBwData(t_index, bw_i_0_r_6_0);
						break;

					case 1:
						bw = calculateBwData(t_index, bw_i_0_r_6_1);
						break;
				}
			}
			IPGlobal::BW_MBPS_i_0_r_6.Bw = bw.Bw;
			IPGlobal::BW_MBPS_i_0_r_6.upBw = bw.upBw;
			IPGlobal::BW_MBPS_i_0_r_6.dnBw = bw.dnBw;
			IPGlobal::BW_MBPS_i_0_r_6.totalVol = bw.totalVol;
			IPGlobal::BW_MBPS_i_0_r_6.upTotalVol = bw.upTotalVol;
			IPGlobal::BW_MBPS_i_0_r_6.dnTotalVol = bw.dnTotalVol;
			IPGlobal::BW_MBPS_i_0_r_6.peakTotalVol 	= bw.peakTotalVol;
			IPGlobal::BW_MBPS_i_0_r_6.peakUpTotalVol = bw.peakUpTotalVol;
			IPGlobal::BW_MBPS_i_0_r_6.peakDnTotalVol = bw.peakDnTotalVol;
			IPGlobal::BW_MBPS_i_0_r_6.avgTotalBw = bw.avgTotalBw;
			IPGlobal::BW_MBPS_i_0_r_6.avgUpBw = bw.avgUpBw;
			IPGlobal::BW_MBPS_i_0_r_6.avgDnBw = bw.avgDnBw;
			break;

		case 7:
			{
				switch(t_index)
				{
					case 0:
						bw = calculateBwData(t_index, bw_i_0_r_7_0);
						break;

					case 1:
						bw = calculateBwData(t_index, bw_i_0_r_7_1);
						break;
				}
			}
			IPGlobal::BW_MBPS_i_0_r_7.Bw = bw.Bw;
			IPGlobal::BW_MBPS_i_0_r_7.upBw = bw.upBw;
			IPGlobal::BW_MBPS_i_0_r_7.dnBw = bw.dnBw;
			IPGlobal::BW_MBPS_i_0_r_7.totalVol = bw.totalVol;
			IPGlobal::BW_MBPS_i_0_r_7.upTotalVol = bw.upTotalVol;
			IPGlobal::BW_MBPS_i_0_r_7.dnTotalVol = bw.dnTotalVol;
			IPGlobal::BW_MBPS_i_0_r_7.peakTotalVol 	= bw.peakTotalVol;
			IPGlobal::BW_MBPS_i_0_r_7.peakUpTotalVol = bw.peakUpTotalVol;
			IPGlobal::BW_MBPS_i_0_r_7.peakDnTotalVol = bw.peakDnTotalVol;
			IPGlobal::BW_MBPS_i_0_r_7.avgTotalBw = bw.avgTotalBw;
			IPGlobal::BW_MBPS_i_0_r_7.avgUpBw = bw.avgUpBw;
			IPGlobal::BW_MBPS_i_0_r_7.avgDnBw = bw.avgDnBw;
			break;
	}
}

VOID BWData::setBWData_i_1(int t_index)
{
	bwData bw;

	switch(routerId)
	{
		case 0:
			{
				switch(t_index)
				{
					case 0:
						bw = calculateBwData(t_index, bw_i_1_r_0_0);
						break;

					case 1:
						bw = calculateBwData(t_index, bw_i_1_r_0_1);
						break;
				}
			}
			IPGlobal::BW_MBPS_i_1_r_0.Bw = bw.Bw;
			IPGlobal::BW_MBPS_i_1_r_0.upBw = bw.upBw;
			IPGlobal::BW_MBPS_i_1_r_0.dnBw = bw.dnBw;
			IPGlobal::BW_MBPS_i_1_r_0.totalVol = bw.totalVol;
			IPGlobal::BW_MBPS_i_1_r_0.upTotalVol = bw.upTotalVol;
			IPGlobal::BW_MBPS_i_1_r_0.dnTotalVol = bw.dnTotalVol;
			IPGlobal::BW_MBPS_i_1_r_0.peakTotalVol 	= bw.peakTotalVol;
			IPGlobal::BW_MBPS_i_1_r_0.peakUpTotalVol = bw.peakUpTotalVol;
			IPGlobal::BW_MBPS_i_1_r_0.peakDnTotalVol = bw.peakDnTotalVol;

			IPGlobal::BW_MBPS_i_1_r_0.avgTotalBw= bw.avgTotalBw;
			IPGlobal::BW_MBPS_i_1_r_0.avgUpBw 	= bw.avgUpBw;
			IPGlobal::BW_MBPS_i_1_r_0.avgDnBw 	= bw.avgDnBw;


			break;

		case 1:
			{
				switch(t_index)
				{
					case 0:
						bw = calculateBwData(t_index, bw_i_1_r_1_0);
						break;

					case 1:
						bw = calculateBwData(t_index, bw_i_1_r_1_1);
						break;
				}
			}
			IPGlobal::BW_MBPS_i_1_r_1.Bw = bw.Bw;
			IPGlobal::BW_MBPS_i_1_r_1.upBw = bw.upBw;
			IPGlobal::BW_MBPS_i_1_r_1.dnBw = bw.dnBw;
			IPGlobal::BW_MBPS_i_1_r_1.totalVol = bw.totalVol;
			IPGlobal::BW_MBPS_i_1_r_1.upTotalVol = bw.upTotalVol;
			IPGlobal::BW_MBPS_i_1_r_1.dnTotalVol = bw.dnTotalVol;
			IPGlobal::BW_MBPS_i_1_r_1.peakTotalVol 	= bw.peakTotalVol;
			IPGlobal::BW_MBPS_i_1_r_1.peakUpTotalVol = bw.peakUpTotalVol;
			IPGlobal::BW_MBPS_i_1_r_1.peakDnTotalVol = bw.peakDnTotalVol;
			IPGlobal::BW_MBPS_i_1_r_1.avgTotalBw = bw.avgTotalBw;
			IPGlobal::BW_MBPS_i_1_r_1.avgUpBw = bw.avgUpBw;
			IPGlobal::BW_MBPS_i_1_r_1.avgDnBw = bw.avgDnBw;


			break;

		case 2:
			{
				switch(t_index)
				{
					case 0:
						bw = calculateBwData(t_index, bw_i_1_r_2_0);
						break;

					case 1:
						bw = calculateBwData(t_index, bw_i_1_r_2_1);
						break;
				}
			}
			IPGlobal::BW_MBPS_i_1_r_2.Bw = bw.Bw;
			IPGlobal::BW_MBPS_i_1_r_2.upBw = bw.upBw;
			IPGlobal::BW_MBPS_i_1_r_2.dnBw = bw.dnBw;
			IPGlobal::BW_MBPS_i_1_r_2.totalVol = bw.totalVol;
			IPGlobal::BW_MBPS_i_1_r_2.upTotalVol = bw.upTotalVol;
			IPGlobal::BW_MBPS_i_1_r_2.dnTotalVol = bw.dnTotalVol;
			IPGlobal::BW_MBPS_i_1_r_2.peakTotalVol 	= bw.peakTotalVol;
			IPGlobal::BW_MBPS_i_1_r_2.peakUpTotalVol = bw.peakUpTotalVol;
			IPGlobal::BW_MBPS_i_1_r_2.peakDnTotalVol = bw.peakDnTotalVol;
			IPGlobal::BW_MBPS_i_1_r_2.avgTotalBw = bw.avgTotalBw;
			IPGlobal::BW_MBPS_i_1_r_2.avgUpBw = bw.avgUpBw;
			IPGlobal::BW_MBPS_i_1_r_2.avgDnBw = bw.avgDnBw;


			break;

		case 3:
			{
				switch(t_index)
				{
					case 0:
						bw = calculateBwData(t_index, bw_i_1_r_3_0);
						break;

					case 1:
						bw = calculateBwData(t_index, bw_i_1_r_3_1);
						break;
				}
			}
			IPGlobal::BW_MBPS_i_1_r_3.Bw = bw.Bw;
			IPGlobal::BW_MBPS_i_1_r_3.upBw = bw.upBw;
			IPGlobal::BW_MBPS_i_1_r_3.dnBw = bw.dnBw;
			IPGlobal::BW_MBPS_i_1_r_3.totalVol = bw.totalVol;
			IPGlobal::BW_MBPS_i_1_r_3.upTotalVol = bw.upTotalVol;
			IPGlobal::BW_MBPS_i_1_r_3.dnTotalVol = bw.dnTotalVol;
			IPGlobal::BW_MBPS_i_1_r_3.peakTotalVol 	= bw.peakTotalVol;
			IPGlobal::BW_MBPS_i_1_r_3.peakUpTotalVol = bw.peakUpTotalVol;
			IPGlobal::BW_MBPS_i_1_r_3.peakDnTotalVol = bw.peakDnTotalVol;
			IPGlobal::BW_MBPS_i_1_r_3.avgTotalBw = bw.avgTotalBw;
			IPGlobal::BW_MBPS_i_1_r_3.avgUpBw = bw.avgUpBw;
			IPGlobal::BW_MBPS_i_1_r_3.avgDnBw = bw.avgDnBw;
			break;

		case 4:
			{
				switch(t_index)
				{
					case 0:
						bw = calculateBwData(t_index, bw_i_1_r_4_0);
						break;

					case 1:
						bw = calculateBwData(t_index, bw_i_1_r_4_1);
						break;
				}
			}
			IPGlobal::BW_MBPS_i_1_r_4.Bw = bw.Bw;
			IPGlobal::BW_MBPS_i_1_r_4.upBw = bw.upBw;
			IPGlobal::BW_MBPS_i_1_r_4.dnBw = bw.dnBw;
			IPGlobal::BW_MBPS_i_1_r_4.totalVol = bw.totalVol;
			IPGlobal::BW_MBPS_i_1_r_4.upTotalVol = bw.upTotalVol;
			IPGlobal::BW_MBPS_i_1_r_4.dnTotalVol = bw.dnTotalVol;
			IPGlobal::BW_MBPS_i_1_r_4.peakTotalVol 	= bw.peakTotalVol;
			IPGlobal::BW_MBPS_i_1_r_4.peakUpTotalVol = bw.peakUpTotalVol;
			IPGlobal::BW_MBPS_i_1_r_4.peakDnTotalVol = bw.peakDnTotalVol;
			IPGlobal::BW_MBPS_i_1_r_4.avgTotalBw = bw.avgTotalBw;
			IPGlobal::BW_MBPS_i_1_r_4.avgUpBw = bw.avgUpBw;
			IPGlobal::BW_MBPS_i_1_r_4.avgDnBw = bw.avgDnBw;
			break;

		case 5:
			{
				switch(t_index)
				{
					case 0:
						bw = calculateBwData(t_index, bw_i_1_r_5_0);
						break;

					case 1:
						bw = calculateBwData(t_index, bw_i_1_r_5_1);
						break;
				}
			}
			IPGlobal::BW_MBPS_i_1_r_5.Bw = bw.Bw;
			IPGlobal::BW_MBPS_i_1_r_5.upBw = bw.upBw;
			IPGlobal::BW_MBPS_i_1_r_5.dnBw = bw.dnBw;
			IPGlobal::BW_MBPS_i_1_r_5.totalVol = bw.totalVol;
			IPGlobal::BW_MBPS_i_1_r_5.upTotalVol = bw.upTotalVol;
			IPGlobal::BW_MBPS_i_1_r_5.dnTotalVol = bw.dnTotalVol;
			IPGlobal::BW_MBPS_i_1_r_5.peakTotalVol 	= bw.peakTotalVol;
			IPGlobal::BW_MBPS_i_1_r_5.peakUpTotalVol = bw.peakUpTotalVol;
			IPGlobal::BW_MBPS_i_1_r_5.peakDnTotalVol = bw.peakDnTotalVol;
			IPGlobal::BW_MBPS_i_1_r_5.avgTotalBw = bw.avgTotalBw;
			IPGlobal::BW_MBPS_i_1_r_5.avgUpBw = bw.avgUpBw;
			IPGlobal::BW_MBPS_i_1_r_5.avgDnBw = bw.avgDnBw;
			break;

		case 6:
			{
				switch(t_index)
				{
					case 0:
						bw = calculateBwData(t_index, bw_i_1_r_6_0);
						break;

					case 1:
						bw = calculateBwData(t_index, bw_i_1_r_6_1);
						break;
				}
			}
			IPGlobal::BW_MBPS_i_1_r_6.Bw = bw.Bw;
			IPGlobal::BW_MBPS_i_1_r_6.upBw = bw.upBw;
			IPGlobal::BW_MBPS_i_1_r_6.dnBw = bw.dnBw;
			IPGlobal::BW_MBPS_i_1_r_6.totalVol = bw.totalVol;
			IPGlobal::BW_MBPS_i_1_r_6.upTotalVol = bw.upTotalVol;
			IPGlobal::BW_MBPS_i_1_r_6.dnTotalVol = bw.dnTotalVol;
			IPGlobal::BW_MBPS_i_1_r_6.peakTotalVol 	= bw.peakTotalVol;
			IPGlobal::BW_MBPS_i_1_r_6.peakUpTotalVol = bw.peakUpTotalVol;
			IPGlobal::BW_MBPS_i_1_r_6.peakDnTotalVol = bw.peakDnTotalVol;
			IPGlobal::BW_MBPS_i_1_r_6.avgTotalBw = bw.avgTotalBw;
			IPGlobal::BW_MBPS_i_1_r_6.avgUpBw = bw.avgUpBw;
			IPGlobal::BW_MBPS_i_1_r_6.avgDnBw = bw.avgDnBw;
			break;

		case 7:
			{
				switch(t_index)
				{
					case 0:
						bw = calculateBwData(t_index, bw_i_1_r_7_0);
						break;

					case 1:
						bw = calculateBwData(t_index, bw_i_1_r_7_1);
						break;
				}
			}
			IPGlobal::BW_MBPS_i_1_r_7.Bw = bw.Bw;
			IPGlobal::BW_MBPS_i_1_r_7.upBw = bw.upBw;
			IPGlobal::BW_MBPS_i_1_r_7.dnBw = bw.dnBw;
			IPGlobal::BW_MBPS_i_1_r_7.totalVol = bw.totalVol;
			IPGlobal::BW_MBPS_i_1_r_7.upTotalVol = bw.upTotalVol;
			IPGlobal::BW_MBPS_i_1_r_7.dnTotalVol = bw.dnTotalVol;
			IPGlobal::BW_MBPS_i_1_r_7.peakTotalVol 	= bw.peakTotalVol;
			IPGlobal::BW_MBPS_i_1_r_7.peakUpTotalVol = bw.peakUpTotalVol;
			IPGlobal::BW_MBPS_i_1_r_7.peakDnTotalVol = bw.peakDnTotalVol;
			IPGlobal::BW_MBPS_i_1_r_7.avgTotalBw = bw.avgTotalBw;
			IPGlobal::BW_MBPS_i_1_r_7.avgUpBw = bw.avgUpBw;
			IPGlobal::BW_MBPS_i_1_r_7.avgDnBw = bw.avgDnBw;
			break;
	}
}

VOID BWData::setBWData_i_2(int t_index)
{
	bwData bw;

	switch(routerId)
	{
		case 0:
			{
				switch(t_index)
				{
					case 0:
						bw = calculateBwData(t_index, bw_i_2_r_0_0);
						break;

					case 1:
						bw = calculateBwData(t_index, bw_i_2_r_0_1);
						break;
				}
			}
			IPGlobal::BW_MBPS_i_2_r_0.Bw = bw.Bw;
			IPGlobal::BW_MBPS_i_2_r_0.upBw = bw.upBw;
			IPGlobal::BW_MBPS_i_2_r_0.dnBw = bw.dnBw;
			IPGlobal::BW_MBPS_i_2_r_0.totalVol = bw.totalVol;
			IPGlobal::BW_MBPS_i_2_r_0.upTotalVol = bw.upTotalVol;
			IPGlobal::BW_MBPS_i_2_r_0.dnTotalVol = bw.dnTotalVol;
			IPGlobal::BW_MBPS_i_2_r_0.peakTotalVol 	= bw.peakTotalVol;
			IPGlobal::BW_MBPS_i_2_r_0.peakUpTotalVol = bw.peakUpTotalVol;
			IPGlobal::BW_MBPS_i_2_r_0.peakDnTotalVol = bw.peakDnTotalVol;

			IPGlobal::BW_MBPS_i_2_r_0.avgTotalBw= bw.avgTotalBw;
			IPGlobal::BW_MBPS_i_2_r_0.avgUpBw 	= bw.avgUpBw;
			IPGlobal::BW_MBPS_i_2_r_0.avgDnBw 	= bw.avgDnBw;


			break;

		case 1:
			{
				switch(t_index)
				{
					case 0:
						bw = calculateBwData(t_index, bw_i_2_r_1_0);
						break;

					case 1:
						bw = calculateBwData(t_index, bw_i_2_r_1_1);
						break;
				}
			}
			IPGlobal::BW_MBPS_i_2_r_1.Bw = bw.Bw;
			IPGlobal::BW_MBPS_i_2_r_1.upBw = bw.upBw;
			IPGlobal::BW_MBPS_i_2_r_1.dnBw = bw.dnBw;
			IPGlobal::BW_MBPS_i_2_r_1.totalVol = bw.totalVol;
			IPGlobal::BW_MBPS_i_2_r_1.upTotalVol = bw.upTotalVol;
			IPGlobal::BW_MBPS_i_2_r_1.dnTotalVol = bw.dnTotalVol;
			IPGlobal::BW_MBPS_i_2_r_1.peakTotalVol 	= bw.peakTotalVol;
			IPGlobal::BW_MBPS_i_2_r_1.peakUpTotalVol = bw.peakUpTotalVol;
			IPGlobal::BW_MBPS_i_2_r_1.peakDnTotalVol = bw.peakDnTotalVol;
			IPGlobal::BW_MBPS_i_2_r_1.avgTotalBw = bw.avgTotalBw;
			IPGlobal::BW_MBPS_i_2_r_1.avgUpBw = bw.avgUpBw;
			IPGlobal::BW_MBPS_i_2_r_1.avgDnBw = bw.avgDnBw;


			break;

		case 2:
			{
				switch(t_index)
				{
					case 0:
						bw = calculateBwData(t_index, bw_i_2_r_2_0);
						break;

					case 1:
						bw = calculateBwData(t_index, bw_i_2_r_2_1);
						break;
				}
			}
			IPGlobal::BW_MBPS_i_2_r_2.Bw = bw.Bw;
			IPGlobal::BW_MBPS_i_2_r_2.upBw = bw.upBw;
			IPGlobal::BW_MBPS_i_2_r_2.dnBw = bw.dnBw;
			IPGlobal::BW_MBPS_i_2_r_2.totalVol = bw.totalVol;
			IPGlobal::BW_MBPS_i_2_r_2.upTotalVol = bw.upTotalVol;
			IPGlobal::BW_MBPS_i_2_r_2.dnTotalVol = bw.dnTotalVol;
			IPGlobal::BW_MBPS_i_2_r_2.peakTotalVol 	= bw.peakTotalVol;
			IPGlobal::BW_MBPS_i_2_r_2.peakUpTotalVol = bw.peakUpTotalVol;
			IPGlobal::BW_MBPS_i_2_r_2.peakDnTotalVol = bw.peakDnTotalVol;
			IPGlobal::BW_MBPS_i_2_r_2.avgTotalBw = bw.avgTotalBw;
			IPGlobal::BW_MBPS_i_2_r_2.avgUpBw = bw.avgUpBw;
			IPGlobal::BW_MBPS_i_2_r_2.avgDnBw = bw.avgDnBw;


			break;

		case 3:
			{
				switch(t_index)
				{
					case 0:
						bw = calculateBwData(t_index, bw_i_2_r_3_0);
						break;

					case 1:
						bw = calculateBwData(t_index, bw_i_2_r_3_1);
						break;
				}
			}
			IPGlobal::BW_MBPS_i_2_r_3.Bw = bw.Bw;
			IPGlobal::BW_MBPS_i_2_r_3.upBw = bw.upBw;
			IPGlobal::BW_MBPS_i_2_r_3.dnBw = bw.dnBw;
			IPGlobal::BW_MBPS_i_2_r_3.totalVol = bw.totalVol;
			IPGlobal::BW_MBPS_i_2_r_3.upTotalVol = bw.upTotalVol;
			IPGlobal::BW_MBPS_i_2_r_3.dnTotalVol = bw.dnTotalVol;
			IPGlobal::BW_MBPS_i_2_r_3.peakTotalVol 	= bw.peakTotalVol;
			IPGlobal::BW_MBPS_i_2_r_3.peakUpTotalVol = bw.peakUpTotalVol;
			IPGlobal::BW_MBPS_i_2_r_3.peakDnTotalVol = bw.peakDnTotalVol;
			IPGlobal::BW_MBPS_i_2_r_3.avgTotalBw = bw.avgTotalBw;
			IPGlobal::BW_MBPS_i_2_r_3.avgUpBw = bw.avgUpBw;
			IPGlobal::BW_MBPS_i_2_r_3.avgDnBw = bw.avgDnBw;
			break;

		case 4:
			{
				switch(t_index)
				{
					case 0:
						bw = calculateBwData(t_index, bw_i_2_r_4_0);
						break;

					case 1:
						bw = calculateBwData(t_index, bw_i_2_r_4_1);
						break;
				}
			}
			IPGlobal::BW_MBPS_i_2_r_4.Bw = bw.Bw;
			IPGlobal::BW_MBPS_i_2_r_4.upBw = bw.upBw;
			IPGlobal::BW_MBPS_i_2_r_4.dnBw = bw.dnBw;
			IPGlobal::BW_MBPS_i_2_r_4.totalVol = bw.totalVol;
			IPGlobal::BW_MBPS_i_2_r_4.upTotalVol = bw.upTotalVol;
			IPGlobal::BW_MBPS_i_2_r_4.dnTotalVol = bw.dnTotalVol;
			IPGlobal::BW_MBPS_i_2_r_4.peakTotalVol 	= bw.peakTotalVol;
			IPGlobal::BW_MBPS_i_2_r_4.peakUpTotalVol = bw.peakUpTotalVol;
			IPGlobal::BW_MBPS_i_2_r_4.peakDnTotalVol = bw.peakDnTotalVol;
			IPGlobal::BW_MBPS_i_2_r_4.avgTotalBw = bw.avgTotalBw;
			IPGlobal::BW_MBPS_i_2_r_4.avgUpBw = bw.avgUpBw;
			IPGlobal::BW_MBPS_i_2_r_4.avgDnBw = bw.avgDnBw;
			break;

		case 5:
			{
				switch(t_index)
				{
					case 0:
						bw = calculateBwData(t_index, bw_i_2_r_5_0);
						break;

					case 1:
						bw = calculateBwData(t_index, bw_i_2_r_5_1);
						break;
				}
			}
			IPGlobal::BW_MBPS_i_2_r_5.Bw = bw.Bw;
			IPGlobal::BW_MBPS_i_2_r_5.upBw = bw.upBw;
			IPGlobal::BW_MBPS_i_2_r_5.dnBw = bw.dnBw;
			IPGlobal::BW_MBPS_i_2_r_5.totalVol = bw.totalVol;
			IPGlobal::BW_MBPS_i_2_r_5.upTotalVol = bw.upTotalVol;
			IPGlobal::BW_MBPS_i_2_r_5.dnTotalVol = bw.dnTotalVol;
			IPGlobal::BW_MBPS_i_2_r_5.peakTotalVol 	= bw.peakTotalVol;
			IPGlobal::BW_MBPS_i_2_r_5.peakUpTotalVol = bw.peakUpTotalVol;
			IPGlobal::BW_MBPS_i_2_r_5.peakDnTotalVol = bw.peakDnTotalVol;
			IPGlobal::BW_MBPS_i_2_r_5.avgTotalBw = bw.avgTotalBw;
			IPGlobal::BW_MBPS_i_2_r_5.avgUpBw = bw.avgUpBw;
			IPGlobal::BW_MBPS_i_2_r_5.avgDnBw = bw.avgDnBw;
			break;

		case 6:
			{
				switch(t_index)
				{
					case 0:
						bw = calculateBwData(t_index, bw_i_2_r_6_0);
						break;

					case 1:
						bw = calculateBwData(t_index, bw_i_2_r_6_1);
						break;
				}
			}
			IPGlobal::BW_MBPS_i_2_r_6.Bw = bw.Bw;
			IPGlobal::BW_MBPS_i_2_r_6.upBw = bw.upBw;
			IPGlobal::BW_MBPS_i_2_r_6.dnBw = bw.dnBw;
			IPGlobal::BW_MBPS_i_2_r_6.totalVol = bw.totalVol;
			IPGlobal::BW_MBPS_i_2_r_6.upTotalVol = bw.upTotalVol;
			IPGlobal::BW_MBPS_i_2_r_6.dnTotalVol = bw.dnTotalVol;
			IPGlobal::BW_MBPS_i_2_r_6.peakTotalVol 	= bw.peakTotalVol;
			IPGlobal::BW_MBPS_i_2_r_6.peakUpTotalVol = bw.peakUpTotalVol;
			IPGlobal::BW_MBPS_i_2_r_6.peakDnTotalVol = bw.peakDnTotalVol;
			IPGlobal::BW_MBPS_i_2_r_6.avgTotalBw = bw.avgTotalBw;
			IPGlobal::BW_MBPS_i_2_r_6.avgUpBw = bw.avgUpBw;
			IPGlobal::BW_MBPS_i_2_r_6.avgDnBw = bw.avgDnBw;
			break;

		case 7:
			{
				switch(t_index)
				{
					case 0:
						bw = calculateBwData(t_index, bw_i_2_r_7_0);
						break;

					case 1:
						bw = calculateBwData(t_index, bw_i_2_r_7_1);
						break;
				}
			}
			IPGlobal::BW_MBPS_i_2_r_7.Bw = bw.Bw;
			IPGlobal::BW_MBPS_i_2_r_7.upBw = bw.upBw;
			IPGlobal::BW_MBPS_i_2_r_7.dnBw = bw.dnBw;
			IPGlobal::BW_MBPS_i_2_r_7.totalVol = bw.totalVol;
			IPGlobal::BW_MBPS_i_2_r_7.upTotalVol = bw.upTotalVol;
			IPGlobal::BW_MBPS_i_2_r_7.dnTotalVol = bw.dnTotalVol;
			IPGlobal::BW_MBPS_i_2_r_7.peakTotalVol 	= bw.peakTotalVol;
			IPGlobal::BW_MBPS_i_2_r_7.peakUpTotalVol = bw.peakUpTotalVol;
			IPGlobal::BW_MBPS_i_2_r_7.peakDnTotalVol = bw.peakDnTotalVol;
			IPGlobal::BW_MBPS_i_2_r_7.avgTotalBw = bw.avgTotalBw;
			IPGlobal::BW_MBPS_i_2_r_7.avgUpBw = bw.avgUpBw;
			IPGlobal::BW_MBPS_i_2_r_7.avgDnBw = bw.avgDnBw;
			break;
	}
}

VOID BWData::setBWData_i_3(int t_index)
{
	bwData bw;

	switch(routerId)
	{
		case 0:
			{
				switch(t_index)
				{
					case 0:
						bw = calculateBwData(t_index, bw_i_3_r_0_0);
						break;

					case 1:
						bw = calculateBwData(t_index, bw_i_3_r_0_1);
						break;
				}
			}
			IPGlobal::BW_MBPS_i_3_r_0.Bw = bw.Bw;
			IPGlobal::BW_MBPS_i_3_r_0.upBw = bw.upBw;
			IPGlobal::BW_MBPS_i_3_r_0.dnBw = bw.dnBw;
			IPGlobal::BW_MBPS_i_3_r_0.totalVol = bw.totalVol;
			IPGlobal::BW_MBPS_i_3_r_0.upTotalVol = bw.upTotalVol;
			IPGlobal::BW_MBPS_i_3_r_0.dnTotalVol = bw.dnTotalVol;
			IPGlobal::BW_MBPS_i_3_r_0.peakTotalVol 	= bw.peakTotalVol;
			IPGlobal::BW_MBPS_i_3_r_0.peakUpTotalVol = bw.peakUpTotalVol;
			IPGlobal::BW_MBPS_i_3_r_0.peakDnTotalVol = bw.peakDnTotalVol;

			IPGlobal::BW_MBPS_i_3_r_0.avgTotalBw= bw.avgTotalBw;
			IPGlobal::BW_MBPS_i_3_r_0.avgUpBw 	= bw.avgUpBw;
			IPGlobal::BW_MBPS_i_3_r_0.avgDnBw 	= bw.avgDnBw;


			break;

		case 1:
			{
				switch(t_index)
				{
					case 0:
						bw = calculateBwData(t_index, bw_i_3_r_1_0);
						break;

					case 1:
						bw = calculateBwData(t_index, bw_i_3_r_1_1);
						break;
				}
			}
			IPGlobal::BW_MBPS_i_3_r_1.Bw = bw.Bw;
			IPGlobal::BW_MBPS_i_3_r_1.upBw = bw.upBw;
			IPGlobal::BW_MBPS_i_3_r_1.dnBw = bw.dnBw;
			IPGlobal::BW_MBPS_i_3_r_1.totalVol = bw.totalVol;
			IPGlobal::BW_MBPS_i_3_r_1.upTotalVol = bw.upTotalVol;
			IPGlobal::BW_MBPS_i_3_r_1.dnTotalVol = bw.dnTotalVol;
			IPGlobal::BW_MBPS_i_3_r_1.peakTotalVol 	= bw.peakTotalVol;
			IPGlobal::BW_MBPS_i_3_r_1.peakUpTotalVol = bw.peakUpTotalVol;
			IPGlobal::BW_MBPS_i_3_r_1.peakDnTotalVol = bw.peakDnTotalVol;
			IPGlobal::BW_MBPS_i_3_r_1.avgTotalBw = bw.avgTotalBw;
			IPGlobal::BW_MBPS_i_3_r_1.avgUpBw = bw.avgUpBw;
			IPGlobal::BW_MBPS_i_3_r_1.avgDnBw = bw.avgDnBw;


			break;

		case 2:
			{
				switch(t_index)
				{
					case 0:
						bw = calculateBwData(t_index, bw_i_3_r_2_0);
						break;

					case 1:
						bw = calculateBwData(t_index, bw_i_3_r_2_1);
						break;
				}
			}
			IPGlobal::BW_MBPS_i_3_r_2.Bw = bw.Bw;
			IPGlobal::BW_MBPS_i_3_r_2.upBw = bw.upBw;
			IPGlobal::BW_MBPS_i_3_r_2.dnBw = bw.dnBw;
			IPGlobal::BW_MBPS_i_3_r_2.totalVol = bw.totalVol;
			IPGlobal::BW_MBPS_i_3_r_2.upTotalVol = bw.upTotalVol;
			IPGlobal::BW_MBPS_i_3_r_2.dnTotalVol = bw.dnTotalVol;
			IPGlobal::BW_MBPS_i_3_r_2.peakTotalVol 	= bw.peakTotalVol;
			IPGlobal::BW_MBPS_i_3_r_2.peakUpTotalVol = bw.peakUpTotalVol;
			IPGlobal::BW_MBPS_i_3_r_2.peakDnTotalVol = bw.peakDnTotalVol;
			IPGlobal::BW_MBPS_i_3_r_2.avgTotalBw = bw.avgTotalBw;
			IPGlobal::BW_MBPS_i_3_r_2.avgUpBw = bw.avgUpBw;
			IPGlobal::BW_MBPS_i_3_r_2.avgDnBw = bw.avgDnBw;


			break;

		case 3:
			{
				switch(t_index)
				{
					case 0:
						bw = calculateBwData(t_index, bw_i_3_r_3_0);
						break;

					case 1:
						bw = calculateBwData(t_index, bw_i_3_r_3_1);
						break;
				}
			}
			IPGlobal::BW_MBPS_i_3_r_3.Bw = bw.Bw;
			IPGlobal::BW_MBPS_i_3_r_3.upBw = bw.upBw;
			IPGlobal::BW_MBPS_i_3_r_3.dnBw = bw.dnBw;
			IPGlobal::BW_MBPS_i_3_r_3.totalVol = bw.totalVol;
			IPGlobal::BW_MBPS_i_3_r_3.upTotalVol = bw.upTotalVol;
			IPGlobal::BW_MBPS_i_3_r_3.dnTotalVol = bw.dnTotalVol;
			IPGlobal::BW_MBPS_i_3_r_3.peakTotalVol 	= bw.peakTotalVol;
			IPGlobal::BW_MBPS_i_3_r_3.peakUpTotalVol = bw.peakUpTotalVol;
			IPGlobal::BW_MBPS_i_3_r_3.peakDnTotalVol = bw.peakDnTotalVol;
			IPGlobal::BW_MBPS_i_3_r_3.avgTotalBw = bw.avgTotalBw;
			IPGlobal::BW_MBPS_i_3_r_3.avgUpBw = bw.avgUpBw;
			IPGlobal::BW_MBPS_i_3_r_3.avgDnBw = bw.avgDnBw;
			break;

		case 4:
			{
				switch(t_index)
				{
					case 0:
						bw = calculateBwData(t_index, bw_i_3_r_4_0);
						break;

					case 1:
						bw = calculateBwData(t_index, bw_i_3_r_4_1);
						break;
				}
			}
			IPGlobal::BW_MBPS_i_3_r_4.Bw = bw.Bw;
			IPGlobal::BW_MBPS_i_3_r_4.upBw = bw.upBw;
			IPGlobal::BW_MBPS_i_3_r_4.dnBw = bw.dnBw;
			IPGlobal::BW_MBPS_i_3_r_4.totalVol = bw.totalVol;
			IPGlobal::BW_MBPS_i_3_r_4.upTotalVol = bw.upTotalVol;
			IPGlobal::BW_MBPS_i_3_r_4.dnTotalVol = bw.dnTotalVol;
			IPGlobal::BW_MBPS_i_3_r_4.peakTotalVol 	= bw.peakTotalVol;
			IPGlobal::BW_MBPS_i_3_r_4.peakUpTotalVol = bw.peakUpTotalVol;
			IPGlobal::BW_MBPS_i_3_r_4.peakDnTotalVol = bw.peakDnTotalVol;
			IPGlobal::BW_MBPS_i_3_r_4.avgTotalBw = bw.avgTotalBw;
			IPGlobal::BW_MBPS_i_3_r_4.avgUpBw = bw.avgUpBw;
			IPGlobal::BW_MBPS_i_3_r_4.avgDnBw = bw.avgDnBw;
			break;

		case 5:
			{
				switch(t_index)
				{
					case 0:
						bw = calculateBwData(t_index, bw_i_3_r_5_0);
						break;

					case 1:
						bw = calculateBwData(t_index, bw_i_3_r_5_1);
						break;
				}
			}
			IPGlobal::BW_MBPS_i_3_r_5.Bw = bw.Bw;
			IPGlobal::BW_MBPS_i_3_r_5.upBw = bw.upBw;
			IPGlobal::BW_MBPS_i_3_r_5.dnBw = bw.dnBw;
			IPGlobal::BW_MBPS_i_3_r_5.totalVol = bw.totalVol;
			IPGlobal::BW_MBPS_i_3_r_5.upTotalVol = bw.upTotalVol;
			IPGlobal::BW_MBPS_i_3_r_5.dnTotalVol = bw.dnTotalVol;
			IPGlobal::BW_MBPS_i_3_r_5.peakTotalVol 	= bw.peakTotalVol;
			IPGlobal::BW_MBPS_i_3_r_5.peakUpTotalVol = bw.peakUpTotalVol;
			IPGlobal::BW_MBPS_i_3_r_5.peakDnTotalVol = bw.peakDnTotalVol;
			IPGlobal::BW_MBPS_i_3_r_5.avgTotalBw = bw.avgTotalBw;
			IPGlobal::BW_MBPS_i_3_r_5.avgUpBw = bw.avgUpBw;
			IPGlobal::BW_MBPS_i_3_r_5.avgDnBw = bw.avgDnBw;
			break;

		case 6:
			{
				switch(t_index)
				{
					case 0:
						bw = calculateBwData(t_index, bw_i_3_r_6_0);
						break;

					case 1:
						bw = calculateBwData(t_index, bw_i_3_r_6_1);
						break;
				}
			}
			IPGlobal::BW_MBPS_i_3_r_6.Bw = bw.Bw;
			IPGlobal::BW_MBPS_i_3_r_6.upBw = bw.upBw;
			IPGlobal::BW_MBPS_i_3_r_6.dnBw = bw.dnBw;
			IPGlobal::BW_MBPS_i_3_r_6.totalVol = bw.totalVol;
			IPGlobal::BW_MBPS_i_3_r_6.upTotalVol = bw.upTotalVol;
			IPGlobal::BW_MBPS_i_3_r_6.dnTotalVol = bw.dnTotalVol;
			IPGlobal::BW_MBPS_i_3_r_6.peakTotalVol 	= bw.peakTotalVol;
			IPGlobal::BW_MBPS_i_3_r_6.peakUpTotalVol = bw.peakUpTotalVol;
			IPGlobal::BW_MBPS_i_3_r_6.peakDnTotalVol = bw.peakDnTotalVol;
			IPGlobal::BW_MBPS_i_3_r_6.avgTotalBw = bw.avgTotalBw;
			IPGlobal::BW_MBPS_i_3_r_6.avgUpBw = bw.avgUpBw;
			IPGlobal::BW_MBPS_i_3_r_6.avgDnBw = bw.avgDnBw;
			break;

		case 7:
			{
				switch(t_index)
				{
					case 0:
						bw = calculateBwData(t_index, bw_i_3_r_7_0);
						break;

					case 1:
						bw = calculateBwData(t_index, bw_i_3_r_7_1);
						break;
				}
			}
			IPGlobal::BW_MBPS_i_3_r_7.Bw = bw.Bw;
			IPGlobal::BW_MBPS_i_3_r_7.upBw = bw.upBw;
			IPGlobal::BW_MBPS_i_3_r_7.dnBw = bw.dnBw;
			IPGlobal::BW_MBPS_i_3_r_7.totalVol = bw.totalVol;
			IPGlobal::BW_MBPS_i_3_r_7.upTotalVol = bw.upTotalVol;
			IPGlobal::BW_MBPS_i_3_r_7.dnTotalVol = bw.dnTotalVol;
			IPGlobal::BW_MBPS_i_3_r_7.peakTotalVol 	= bw.peakTotalVol;
			IPGlobal::BW_MBPS_i_3_r_7.peakUpTotalVol = bw.peakUpTotalVol;
			IPGlobal::BW_MBPS_i_3_r_7.peakDnTotalVol = bw.peakDnTotalVol;
			IPGlobal::BW_MBPS_i_3_r_7.avgTotalBw = bw.avgTotalBw;
			IPGlobal::BW_MBPS_i_3_r_7.avgUpBw = bw.avgUpBw;
			IPGlobal::BW_MBPS_i_3_r_7.avgDnBw = bw.avgDnBw;
			break;
	}
}

VOID BWData::setBWData_i_4(int t_index)
{
	bwData bw;

	switch(routerId)
	{
		case 0:
			{
				switch(t_index)
				{
					case 0:
						bw = calculateBwData(t_index, bw_i_4_r_0_0);
						break;

					case 1:
						bw = calculateBwData(t_index, bw_i_4_r_0_1);
						break;
				}
			}
			IPGlobal::BW_MBPS_i_4_r_0.Bw = bw.Bw;
			IPGlobal::BW_MBPS_i_4_r_0.upBw = bw.upBw;
			IPGlobal::BW_MBPS_i_4_r_0.dnBw = bw.dnBw;
			IPGlobal::BW_MBPS_i_4_r_0.totalVol = bw.totalVol;
			IPGlobal::BW_MBPS_i_4_r_0.upTotalVol = bw.upTotalVol;
			IPGlobal::BW_MBPS_i_4_r_0.dnTotalVol = bw.dnTotalVol;
			IPGlobal::BW_MBPS_i_4_r_0.peakTotalVol 	= bw.peakTotalVol;
			IPGlobal::BW_MBPS_i_4_r_0.peakUpTotalVol = bw.peakUpTotalVol;
			IPGlobal::BW_MBPS_i_4_r_0.peakDnTotalVol = bw.peakDnTotalVol;

			IPGlobal::BW_MBPS_i_4_r_0.avgTotalBw= bw.avgTotalBw;
			IPGlobal::BW_MBPS_i_4_r_0.avgUpBw 	= bw.avgUpBw;
			IPGlobal::BW_MBPS_i_4_r_0.avgDnBw 	= bw.avgDnBw;


			break;

		case 1:
			{
				switch(t_index)
				{
					case 0:
						bw = calculateBwData(t_index, bw_i_4_r_1_0);
						break;

					case 1:
						bw = calculateBwData(t_index, bw_i_4_r_1_1);
						break;
				}
			}
			IPGlobal::BW_MBPS_i_4_r_1.Bw = bw.Bw;
			IPGlobal::BW_MBPS_i_4_r_1.upBw = bw.upBw;
			IPGlobal::BW_MBPS_i_4_r_1.dnBw = bw.dnBw;
			IPGlobal::BW_MBPS_i_4_r_1.totalVol = bw.totalVol;
			IPGlobal::BW_MBPS_i_4_r_1.upTotalVol = bw.upTotalVol;
			IPGlobal::BW_MBPS_i_4_r_1.dnTotalVol = bw.dnTotalVol;
			IPGlobal::BW_MBPS_i_4_r_1.peakTotalVol 	= bw.peakTotalVol;
			IPGlobal::BW_MBPS_i_4_r_1.peakUpTotalVol = bw.peakUpTotalVol;
			IPGlobal::BW_MBPS_i_4_r_1.peakDnTotalVol = bw.peakDnTotalVol;
			IPGlobal::BW_MBPS_i_4_r_1.avgTotalBw = bw.avgTotalBw;
			IPGlobal::BW_MBPS_i_4_r_1.avgUpBw = bw.avgUpBw;
			IPGlobal::BW_MBPS_i_4_r_1.avgDnBw = bw.avgDnBw;


			break;

		case 2:
			{
				switch(t_index)
				{
					case 0:
						bw = calculateBwData(t_index, bw_i_4_r_2_0);
						break;

					case 1:
						bw = calculateBwData(t_index, bw_i_4_r_2_1);
						break;
				}
			}
			IPGlobal::BW_MBPS_i_4_r_2.Bw = bw.Bw;
			IPGlobal::BW_MBPS_i_4_r_2.upBw = bw.upBw;
			IPGlobal::BW_MBPS_i_4_r_2.dnBw = bw.dnBw;
			IPGlobal::BW_MBPS_i_4_r_2.totalVol = bw.totalVol;
			IPGlobal::BW_MBPS_i_4_r_2.upTotalVol = bw.upTotalVol;
			IPGlobal::BW_MBPS_i_4_r_2.dnTotalVol = bw.dnTotalVol;
			IPGlobal::BW_MBPS_i_4_r_2.peakTotalVol 	= bw.peakTotalVol;
			IPGlobal::BW_MBPS_i_4_r_2.peakUpTotalVol = bw.peakUpTotalVol;
			IPGlobal::BW_MBPS_i_4_r_2.peakDnTotalVol = bw.peakDnTotalVol;
			IPGlobal::BW_MBPS_i_4_r_2.avgTotalBw = bw.avgTotalBw;
			IPGlobal::BW_MBPS_i_4_r_2.avgUpBw = bw.avgUpBw;
			IPGlobal::BW_MBPS_i_4_r_2.avgDnBw = bw.avgDnBw;


			break;

		case 3:
			{
				switch(t_index)
				{
					case 0:
						bw = calculateBwData(t_index, bw_i_4_r_3_0);
						break;

					case 1:
						bw = calculateBwData(t_index, bw_i_4_r_3_1);
						break;
				}
			}
			IPGlobal::BW_MBPS_i_4_r_3.Bw = bw.Bw;
			IPGlobal::BW_MBPS_i_4_r_3.upBw = bw.upBw;
			IPGlobal::BW_MBPS_i_4_r_3.dnBw = bw.dnBw;
			IPGlobal::BW_MBPS_i_4_r_3.totalVol = bw.totalVol;
			IPGlobal::BW_MBPS_i_4_r_3.upTotalVol = bw.upTotalVol;
			IPGlobal::BW_MBPS_i_4_r_3.dnTotalVol = bw.dnTotalVol;
			IPGlobal::BW_MBPS_i_4_r_3.peakTotalVol 	= bw.peakTotalVol;
			IPGlobal::BW_MBPS_i_4_r_3.peakUpTotalVol = bw.peakUpTotalVol;
			IPGlobal::BW_MBPS_i_4_r_3.peakDnTotalVol = bw.peakDnTotalVol;
			IPGlobal::BW_MBPS_i_4_r_3.avgTotalBw = bw.avgTotalBw;
			IPGlobal::BW_MBPS_i_4_r_3.avgUpBw = bw.avgUpBw;
			IPGlobal::BW_MBPS_i_4_r_3.avgDnBw = bw.avgDnBw;
			break;

		case 4:
			{
				switch(t_index)
				{
					case 0:
						bw = calculateBwData(t_index, bw_i_4_r_4_0);
						break;

					case 1:
						bw = calculateBwData(t_index, bw_i_4_r_4_1);
						break;
				}
			}
			IPGlobal::BW_MBPS_i_4_r_4.Bw = bw.Bw;
			IPGlobal::BW_MBPS_i_4_r_4.upBw = bw.upBw;
			IPGlobal::BW_MBPS_i_4_r_4.dnBw = bw.dnBw;
			IPGlobal::BW_MBPS_i_4_r_4.totalVol = bw.totalVol;
			IPGlobal::BW_MBPS_i_4_r_4.upTotalVol = bw.upTotalVol;
			IPGlobal::BW_MBPS_i_4_r_4.dnTotalVol = bw.dnTotalVol;
			IPGlobal::BW_MBPS_i_4_r_4.peakTotalVol 	= bw.peakTotalVol;
			IPGlobal::BW_MBPS_i_4_r_4.peakUpTotalVol = bw.peakUpTotalVol;
			IPGlobal::BW_MBPS_i_4_r_4.peakDnTotalVol = bw.peakDnTotalVol;
			IPGlobal::BW_MBPS_i_4_r_4.avgTotalBw = bw.avgTotalBw;
			IPGlobal::BW_MBPS_i_4_r_4.avgUpBw = bw.avgUpBw;
			IPGlobal::BW_MBPS_i_4_r_4.avgDnBw = bw.avgDnBw;
			break;

		case 5:
			{
				switch(t_index)
				{
					case 0:
						bw = calculateBwData(t_index, bw_i_4_r_5_0);
						break;

					case 1:
						bw = calculateBwData(t_index, bw_i_4_r_5_1);
						break;
				}
			}
			IPGlobal::BW_MBPS_i_4_r_5.Bw = bw.Bw;
			IPGlobal::BW_MBPS_i_4_r_5.upBw = bw.upBw;
			IPGlobal::BW_MBPS_i_4_r_5.dnBw = bw.dnBw;
			IPGlobal::BW_MBPS_i_4_r_5.totalVol = bw.totalVol;
			IPGlobal::BW_MBPS_i_4_r_5.upTotalVol = bw.upTotalVol;
			IPGlobal::BW_MBPS_i_4_r_5.dnTotalVol = bw.dnTotalVol;
			IPGlobal::BW_MBPS_i_4_r_5.peakTotalVol 	= bw.peakTotalVol;
			IPGlobal::BW_MBPS_i_4_r_5.peakUpTotalVol = bw.peakUpTotalVol;
			IPGlobal::BW_MBPS_i_4_r_5.peakDnTotalVol = bw.peakDnTotalVol;
			IPGlobal::BW_MBPS_i_4_r_5.avgTotalBw = bw.avgTotalBw;
			IPGlobal::BW_MBPS_i_4_r_5.avgUpBw = bw.avgUpBw;
			IPGlobal::BW_MBPS_i_4_r_5.avgDnBw = bw.avgDnBw;
			break;

		case 6:
			{
				switch(t_index)
				{
					case 0:
						bw = calculateBwData(t_index, bw_i_4_r_6_0);
						break;

					case 1:
						bw = calculateBwData(t_index, bw_i_4_r_6_1);
						break;
				}
			}
			IPGlobal::BW_MBPS_i_4_r_6.Bw = bw.Bw;
			IPGlobal::BW_MBPS_i_4_r_6.upBw = bw.upBw;
			IPGlobal::BW_MBPS_i_4_r_6.dnBw = bw.dnBw;
			IPGlobal::BW_MBPS_i_4_r_6.totalVol = bw.totalVol;
			IPGlobal::BW_MBPS_i_4_r_6.upTotalVol = bw.upTotalVol;
			IPGlobal::BW_MBPS_i_4_r_6.dnTotalVol = bw.dnTotalVol;
			IPGlobal::BW_MBPS_i_4_r_6.peakTotalVol 	= bw.peakTotalVol;
			IPGlobal::BW_MBPS_i_4_r_6.peakUpTotalVol = bw.peakUpTotalVol;
			IPGlobal::BW_MBPS_i_4_r_6.peakDnTotalVol = bw.peakDnTotalVol;
			IPGlobal::BW_MBPS_i_4_r_6.avgTotalBw = bw.avgTotalBw;
			IPGlobal::BW_MBPS_i_4_r_6.avgUpBw = bw.avgUpBw;
			IPGlobal::BW_MBPS_i_4_r_6.avgDnBw = bw.avgDnBw;
			break;

		case 7:
			{
				switch(t_index)
				{
					case 0:
						bw = calculateBwData(t_index, bw_i_4_r_7_0);
						break;

					case 1:
						bw = calculateBwData(t_index, bw_i_4_r_7_1);
						break;
				}
			}
			IPGlobal::BW_MBPS_i_4_r_7.Bw = bw.Bw;
			IPGlobal::BW_MBPS_i_4_r_7.upBw = bw.upBw;
			IPGlobal::BW_MBPS_i_4_r_7.dnBw = bw.dnBw;
			IPGlobal::BW_MBPS_i_4_r_7.totalVol = bw.totalVol;
			IPGlobal::BW_MBPS_i_4_r_7.upTotalVol = bw.upTotalVol;
			IPGlobal::BW_MBPS_i_4_r_7.dnTotalVol = bw.dnTotalVol;
			IPGlobal::BW_MBPS_i_4_r_7.peakTotalVol 	= bw.peakTotalVol;
			IPGlobal::BW_MBPS_i_4_r_7.peakUpTotalVol = bw.peakUpTotalVol;
			IPGlobal::BW_MBPS_i_4_r_7.peakDnTotalVol = bw.peakDnTotalVol;
			IPGlobal::BW_MBPS_i_4_r_7.avgTotalBw = bw.avgTotalBw;
			IPGlobal::BW_MBPS_i_4_r_7.avgUpBw = bw.avgUpBw;
			IPGlobal::BW_MBPS_i_4_r_7.avgDnBw = bw.avgDnBw;
			break;
	}
}

VOID BWData::setBWData_i_5(int t_index)
{
	bwData bw;

	switch(routerId)
	{
		case 0:
			{
				switch(t_index)
				{
					case 0:
						bw = calculateBwData(t_index, bw_i_5_r_0_0);
						break;

					case 1:
						bw = calculateBwData(t_index, bw_i_5_r_0_1);
						break;
				}
			}
			IPGlobal::BW_MBPS_i_5_r_0.Bw = bw.Bw;
			IPGlobal::BW_MBPS_i_5_r_0.upBw = bw.upBw;
			IPGlobal::BW_MBPS_i_5_r_0.dnBw = bw.dnBw;
			IPGlobal::BW_MBPS_i_5_r_0.totalVol = bw.totalVol;
			IPGlobal::BW_MBPS_i_5_r_0.upTotalVol = bw.upTotalVol;
			IPGlobal::BW_MBPS_i_5_r_0.dnTotalVol = bw.dnTotalVol;
			IPGlobal::BW_MBPS_i_5_r_0.peakTotalVol 	= bw.peakTotalVol;
			IPGlobal::BW_MBPS_i_5_r_0.peakUpTotalVol = bw.peakUpTotalVol;
			IPGlobal::BW_MBPS_i_5_r_0.peakDnTotalVol = bw.peakDnTotalVol;

			IPGlobal::BW_MBPS_i_5_r_0.avgTotalBw= bw.avgTotalBw;
			IPGlobal::BW_MBPS_i_5_r_0.avgUpBw 	= bw.avgUpBw;
			IPGlobal::BW_MBPS_i_5_r_0.avgDnBw 	= bw.avgDnBw;


			break;

		case 1:
			{
				switch(t_index)
				{
					case 0:
						bw = calculateBwData(t_index, bw_i_5_r_1_0);
						break;

					case 1:
						bw = calculateBwData(t_index, bw_i_5_r_1_1);
						break;
				}
			}
			IPGlobal::BW_MBPS_i_5_r_1.Bw = bw.Bw;
			IPGlobal::BW_MBPS_i_5_r_1.upBw = bw.upBw;
			IPGlobal::BW_MBPS_i_5_r_1.dnBw = bw.dnBw;
			IPGlobal::BW_MBPS_i_5_r_1.totalVol = bw.totalVol;
			IPGlobal::BW_MBPS_i_5_r_1.upTotalVol = bw.upTotalVol;
			IPGlobal::BW_MBPS_i_5_r_1.dnTotalVol = bw.dnTotalVol;
			IPGlobal::BW_MBPS_i_5_r_1.peakTotalVol 	= bw.peakTotalVol;
			IPGlobal::BW_MBPS_i_5_r_1.peakUpTotalVol = bw.peakUpTotalVol;
			IPGlobal::BW_MBPS_i_5_r_1.peakDnTotalVol = bw.peakDnTotalVol;
			IPGlobal::BW_MBPS_i_5_r_1.avgTotalBw = bw.avgTotalBw;
			IPGlobal::BW_MBPS_i_5_r_1.avgUpBw = bw.avgUpBw;
			IPGlobal::BW_MBPS_i_5_r_1.avgDnBw = bw.avgDnBw;


			break;

		case 2:
			{
				switch(t_index)
				{
					case 0:
						bw = calculateBwData(t_index, bw_i_5_r_2_0);
						break;

					case 1:
						bw = calculateBwData(t_index, bw_i_5_r_2_1);
						break;
				}
			}
			IPGlobal::BW_MBPS_i_5_r_2.Bw = bw.Bw;
			IPGlobal::BW_MBPS_i_5_r_2.upBw = bw.upBw;
			IPGlobal::BW_MBPS_i_5_r_2.dnBw = bw.dnBw;
			IPGlobal::BW_MBPS_i_5_r_2.totalVol = bw.totalVol;
			IPGlobal::BW_MBPS_i_5_r_2.upTotalVol = bw.upTotalVol;
			IPGlobal::BW_MBPS_i_5_r_2.dnTotalVol = bw.dnTotalVol;
			IPGlobal::BW_MBPS_i_5_r_2.peakTotalVol 	= bw.peakTotalVol;
			IPGlobal::BW_MBPS_i_5_r_2.peakUpTotalVol = bw.peakUpTotalVol;
			IPGlobal::BW_MBPS_i_5_r_2.peakDnTotalVol = bw.peakDnTotalVol;
			IPGlobal::BW_MBPS_i_5_r_2.avgTotalBw = bw.avgTotalBw;
			IPGlobal::BW_MBPS_i_5_r_2.avgUpBw = bw.avgUpBw;
			IPGlobal::BW_MBPS_i_5_r_2.avgDnBw = bw.avgDnBw;


			break;

		case 3:
			{
				switch(t_index)
				{
					case 0:
						bw = calculateBwData(t_index, bw_i_5_r_3_0);
						break;

					case 1:
						bw = calculateBwData(t_index, bw_i_5_r_3_1);
						break;
				}
			}
			IPGlobal::BW_MBPS_i_5_r_3.Bw = bw.Bw;
			IPGlobal::BW_MBPS_i_5_r_3.upBw = bw.upBw;
			IPGlobal::BW_MBPS_i_5_r_3.dnBw = bw.dnBw;
			IPGlobal::BW_MBPS_i_5_r_3.totalVol = bw.totalVol;
			IPGlobal::BW_MBPS_i_5_r_3.upTotalVol = bw.upTotalVol;
			IPGlobal::BW_MBPS_i_5_r_3.dnTotalVol = bw.dnTotalVol;
			IPGlobal::BW_MBPS_i_5_r_3.peakTotalVol 	= bw.peakTotalVol;
			IPGlobal::BW_MBPS_i_5_r_3.peakUpTotalVol = bw.peakUpTotalVol;
			IPGlobal::BW_MBPS_i_5_r_3.peakDnTotalVol = bw.peakDnTotalVol;
			IPGlobal::BW_MBPS_i_5_r_3.avgTotalBw = bw.avgTotalBw;
			IPGlobal::BW_MBPS_i_5_r_3.avgUpBw = bw.avgUpBw;
			IPGlobal::BW_MBPS_i_5_r_3.avgDnBw = bw.avgDnBw;
			break;

		case 4:
			{
				switch(t_index)
				{
					case 0:
						bw = calculateBwData(t_index, bw_i_5_r_4_0);
						break;

					case 1:
						bw = calculateBwData(t_index, bw_i_5_r_4_1);
						break;
				}
			}
			IPGlobal::BW_MBPS_i_5_r_4.Bw = bw.Bw;
			IPGlobal::BW_MBPS_i_5_r_4.upBw = bw.upBw;
			IPGlobal::BW_MBPS_i_5_r_4.dnBw = bw.dnBw;
			IPGlobal::BW_MBPS_i_5_r_4.totalVol = bw.totalVol;
			IPGlobal::BW_MBPS_i_5_r_4.upTotalVol = bw.upTotalVol;
			IPGlobal::BW_MBPS_i_5_r_4.dnTotalVol = bw.dnTotalVol;
			IPGlobal::BW_MBPS_i_5_r_4.peakTotalVol 	= bw.peakTotalVol;
			IPGlobal::BW_MBPS_i_5_r_4.peakUpTotalVol = bw.peakUpTotalVol;
			IPGlobal::BW_MBPS_i_5_r_4.peakDnTotalVol = bw.peakDnTotalVol;
			IPGlobal::BW_MBPS_i_5_r_4.avgTotalBw = bw.avgTotalBw;
			IPGlobal::BW_MBPS_i_5_r_4.avgUpBw = bw.avgUpBw;
			IPGlobal::BW_MBPS_i_5_r_4.avgDnBw = bw.avgDnBw;
			break;

		case 5:
			{
				switch(t_index)
				{
					case 0:
						bw = calculateBwData(t_index, bw_i_5_r_5_0);
						break;

					case 1:
						bw = calculateBwData(t_index, bw_i_5_r_5_1);
						break;
				}
			}
			IPGlobal::BW_MBPS_i_5_r_5.Bw = bw.Bw;
			IPGlobal::BW_MBPS_i_5_r_5.upBw = bw.upBw;
			IPGlobal::BW_MBPS_i_5_r_5.dnBw = bw.dnBw;
			IPGlobal::BW_MBPS_i_5_r_5.totalVol = bw.totalVol;
			IPGlobal::BW_MBPS_i_5_r_5.upTotalVol = bw.upTotalVol;
			IPGlobal::BW_MBPS_i_5_r_5.dnTotalVol = bw.dnTotalVol;
			IPGlobal::BW_MBPS_i_5_r_5.peakTotalVol 	= bw.peakTotalVol;
			IPGlobal::BW_MBPS_i_5_r_5.peakUpTotalVol = bw.peakUpTotalVol;
			IPGlobal::BW_MBPS_i_5_r_5.peakDnTotalVol = bw.peakDnTotalVol;
			IPGlobal::BW_MBPS_i_5_r_5.avgTotalBw = bw.avgTotalBw;
			IPGlobal::BW_MBPS_i_5_r_5.avgUpBw = bw.avgUpBw;
			IPGlobal::BW_MBPS_i_5_r_5.avgDnBw = bw.avgDnBw;
			break;

		case 6:
			{
				switch(t_index)
				{
					case 0:
						bw = calculateBwData(t_index, bw_i_5_r_6_0);
						break;

					case 1:
						bw = calculateBwData(t_index, bw_i_5_r_6_1);
						break;
				}
			}
			IPGlobal::BW_MBPS_i_5_r_6.Bw = bw.Bw;
			IPGlobal::BW_MBPS_i_5_r_6.upBw = bw.upBw;
			IPGlobal::BW_MBPS_i_5_r_6.dnBw = bw.dnBw;
			IPGlobal::BW_MBPS_i_5_r_6.totalVol = bw.totalVol;
			IPGlobal::BW_MBPS_i_5_r_6.upTotalVol = bw.upTotalVol;
			IPGlobal::BW_MBPS_i_5_r_6.dnTotalVol = bw.dnTotalVol;
			IPGlobal::BW_MBPS_i_5_r_6.peakTotalVol 	= bw.peakTotalVol;
			IPGlobal::BW_MBPS_i_5_r_6.peakUpTotalVol = bw.peakUpTotalVol;
			IPGlobal::BW_MBPS_i_5_r_6.peakDnTotalVol = bw.peakDnTotalVol;
			IPGlobal::BW_MBPS_i_5_r_6.avgTotalBw = bw.avgTotalBw;
			IPGlobal::BW_MBPS_i_5_r_6.avgUpBw = bw.avgUpBw;
			IPGlobal::BW_MBPS_i_5_r_6.avgDnBw = bw.avgDnBw;
			break;

		case 7:
			{
				switch(t_index)
				{
					case 0:
						bw = calculateBwData(t_index, bw_i_5_r_7_0);
						break;

					case 1:
						bw = calculateBwData(t_index, bw_i_5_r_7_1);
						break;
				}
			}
			IPGlobal::BW_MBPS_i_5_r_7.Bw = bw.Bw;
			IPGlobal::BW_MBPS_i_5_r_7.upBw = bw.upBw;
			IPGlobal::BW_MBPS_i_5_r_7.dnBw = bw.dnBw;
			IPGlobal::BW_MBPS_i_5_r_7.totalVol = bw.totalVol;
			IPGlobal::BW_MBPS_i_5_r_7.upTotalVol = bw.upTotalVol;
			IPGlobal::BW_MBPS_i_5_r_7.dnTotalVol = bw.dnTotalVol;
			IPGlobal::BW_MBPS_i_5_r_7.peakTotalVol 	= bw.peakTotalVol;
			IPGlobal::BW_MBPS_i_5_r_7.peakUpTotalVol = bw.peakUpTotalVol;
			IPGlobal::BW_MBPS_i_5_r_7.peakDnTotalVol = bw.peakDnTotalVol;
			IPGlobal::BW_MBPS_i_5_r_7.avgTotalBw = bw.avgTotalBw;
			IPGlobal::BW_MBPS_i_5_r_7.avgUpBw = bw.avgUpBw;
			IPGlobal::BW_MBPS_i_5_r_7.avgDnBw = bw.avgDnBw;
			break;
	}
}

VOID BWData::setBWData_i_6(int t_index)
{
	bwData bw;

	switch(routerId)
	{
		case 0:
			{
				switch(t_index)
				{
					case 0:
						bw = calculateBwData(t_index, bw_i_6_r_0_0);
						break;

					case 1:
						bw = calculateBwData(t_index, bw_i_6_r_0_1);
						break;
				}
			}
			IPGlobal::BW_MBPS_i_6_r_0.Bw = bw.Bw;
			IPGlobal::BW_MBPS_i_6_r_0.upBw = bw.upBw;
			IPGlobal::BW_MBPS_i_6_r_0.dnBw = bw.dnBw;
			IPGlobal::BW_MBPS_i_6_r_0.totalVol = bw.totalVol;
			IPGlobal::BW_MBPS_i_6_r_0.upTotalVol = bw.upTotalVol;
			IPGlobal::BW_MBPS_i_6_r_0.dnTotalVol = bw.dnTotalVol;
			IPGlobal::BW_MBPS_i_6_r_0.peakTotalVol 	= bw.peakTotalVol;
			IPGlobal::BW_MBPS_i_6_r_0.peakUpTotalVol = bw.peakUpTotalVol;
			IPGlobal::BW_MBPS_i_6_r_0.peakDnTotalVol = bw.peakDnTotalVol;

			IPGlobal::BW_MBPS_i_6_r_0.avgTotalBw= bw.avgTotalBw;
			IPGlobal::BW_MBPS_i_6_r_0.avgUpBw 	= bw.avgUpBw;
			IPGlobal::BW_MBPS_i_6_r_0.avgDnBw 	= bw.avgDnBw;


			break;

		case 1:
			{
				switch(t_index)
				{
					case 0:
						bw = calculateBwData(t_index, bw_i_6_r_1_0);
						break;

					case 1:
						bw = calculateBwData(t_index, bw_i_6_r_1_1);
						break;
				}
			}
			IPGlobal::BW_MBPS_i_6_r_1.Bw = bw.Bw;
			IPGlobal::BW_MBPS_i_6_r_1.upBw = bw.upBw;
			IPGlobal::BW_MBPS_i_6_r_1.dnBw = bw.dnBw;
			IPGlobal::BW_MBPS_i_6_r_1.totalVol = bw.totalVol;
			IPGlobal::BW_MBPS_i_6_r_1.upTotalVol = bw.upTotalVol;
			IPGlobal::BW_MBPS_i_6_r_1.dnTotalVol = bw.dnTotalVol;
			IPGlobal::BW_MBPS_i_6_r_1.peakTotalVol 	= bw.peakTotalVol;
			IPGlobal::BW_MBPS_i_6_r_1.peakUpTotalVol = bw.peakUpTotalVol;
			IPGlobal::BW_MBPS_i_6_r_1.peakDnTotalVol = bw.peakDnTotalVol;
			IPGlobal::BW_MBPS_i_6_r_1.avgTotalBw = bw.avgTotalBw;
			IPGlobal::BW_MBPS_i_6_r_1.avgUpBw = bw.avgUpBw;
			IPGlobal::BW_MBPS_i_6_r_1.avgDnBw = bw.avgDnBw;


			break;

		case 2:
			{
				switch(t_index)
				{
					case 0:
						bw = calculateBwData(t_index, bw_i_6_r_2_0);
						break;

					case 1:
						bw = calculateBwData(t_index, bw_i_6_r_2_1);
						break;
				}
			}
			IPGlobal::BW_MBPS_i_6_r_2.Bw = bw.Bw;
			IPGlobal::BW_MBPS_i_6_r_2.upBw = bw.upBw;
			IPGlobal::BW_MBPS_i_6_r_2.dnBw = bw.dnBw;
			IPGlobal::BW_MBPS_i_6_r_2.totalVol = bw.totalVol;
			IPGlobal::BW_MBPS_i_6_r_2.upTotalVol = bw.upTotalVol;
			IPGlobal::BW_MBPS_i_6_r_2.dnTotalVol = bw.dnTotalVol;
			IPGlobal::BW_MBPS_i_6_r_2.peakTotalVol 	= bw.peakTotalVol;
			IPGlobal::BW_MBPS_i_6_r_2.peakUpTotalVol = bw.peakUpTotalVol;
			IPGlobal::BW_MBPS_i_6_r_2.peakDnTotalVol = bw.peakDnTotalVol;
			IPGlobal::BW_MBPS_i_6_r_2.avgTotalBw = bw.avgTotalBw;
			IPGlobal::BW_MBPS_i_6_r_2.avgUpBw = bw.avgUpBw;
			IPGlobal::BW_MBPS_i_6_r_2.avgDnBw = bw.avgDnBw;


			break;

		case 3:
			{
				switch(t_index)
				{
					case 0:
						bw = calculateBwData(t_index, bw_i_6_r_3_0);
						break;

					case 1:
						bw = calculateBwData(t_index, bw_i_6_r_3_1);
						break;
				}
			}
			IPGlobal::BW_MBPS_i_6_r_3.Bw = bw.Bw;
			IPGlobal::BW_MBPS_i_6_r_3.upBw = bw.upBw;
			IPGlobal::BW_MBPS_i_6_r_3.dnBw = bw.dnBw;
			IPGlobal::BW_MBPS_i_6_r_3.totalVol = bw.totalVol;
			IPGlobal::BW_MBPS_i_6_r_3.upTotalVol = bw.upTotalVol;
			IPGlobal::BW_MBPS_i_6_r_3.dnTotalVol = bw.dnTotalVol;
			IPGlobal::BW_MBPS_i_6_r_3.peakTotalVol 	= bw.peakTotalVol;
			IPGlobal::BW_MBPS_i_6_r_3.peakUpTotalVol = bw.peakUpTotalVol;
			IPGlobal::BW_MBPS_i_6_r_3.peakDnTotalVol = bw.peakDnTotalVol;
			IPGlobal::BW_MBPS_i_6_r_3.avgTotalBw = bw.avgTotalBw;
			IPGlobal::BW_MBPS_i_6_r_3.avgUpBw = bw.avgUpBw;
			IPGlobal::BW_MBPS_i_6_r_3.avgDnBw = bw.avgDnBw;
			break;

		case 4:
			{
				switch(t_index)
				{
					case 0:
						bw = calculateBwData(t_index, bw_i_6_r_4_0);
						break;

					case 1:
						bw = calculateBwData(t_index, bw_i_6_r_4_1);
						break;
				}
			}
			IPGlobal::BW_MBPS_i_6_r_4.Bw = bw.Bw;
			IPGlobal::BW_MBPS_i_6_r_4.upBw = bw.upBw;
			IPGlobal::BW_MBPS_i_6_r_4.dnBw = bw.dnBw;
			IPGlobal::BW_MBPS_i_6_r_4.totalVol = bw.totalVol;
			IPGlobal::BW_MBPS_i_6_r_4.upTotalVol = bw.upTotalVol;
			IPGlobal::BW_MBPS_i_6_r_4.dnTotalVol = bw.dnTotalVol;
			IPGlobal::BW_MBPS_i_6_r_4.peakTotalVol 	= bw.peakTotalVol;
			IPGlobal::BW_MBPS_i_6_r_4.peakUpTotalVol = bw.peakUpTotalVol;
			IPGlobal::BW_MBPS_i_6_r_4.peakDnTotalVol = bw.peakDnTotalVol;
			IPGlobal::BW_MBPS_i_6_r_4.avgTotalBw = bw.avgTotalBw;
			IPGlobal::BW_MBPS_i_6_r_4.avgUpBw = bw.avgUpBw;
			IPGlobal::BW_MBPS_i_6_r_4.avgDnBw = bw.avgDnBw;
			break;

		case 5:
			{
				switch(t_index)
				{
					case 0:
						bw = calculateBwData(t_index, bw_i_6_r_5_0);
						break;

					case 1:
						bw = calculateBwData(t_index, bw_i_6_r_5_1);
						break;
				}
			}
			IPGlobal::BW_MBPS_i_6_r_5.Bw = bw.Bw;
			IPGlobal::BW_MBPS_i_6_r_5.upBw = bw.upBw;
			IPGlobal::BW_MBPS_i_6_r_5.dnBw = bw.dnBw;
			IPGlobal::BW_MBPS_i_6_r_5.totalVol = bw.totalVol;
			IPGlobal::BW_MBPS_i_6_r_5.upTotalVol = bw.upTotalVol;
			IPGlobal::BW_MBPS_i_6_r_5.dnTotalVol = bw.dnTotalVol;
			IPGlobal::BW_MBPS_i_6_r_5.peakTotalVol 	= bw.peakTotalVol;
			IPGlobal::BW_MBPS_i_6_r_5.peakUpTotalVol = bw.peakUpTotalVol;
			IPGlobal::BW_MBPS_i_6_r_5.peakDnTotalVol = bw.peakDnTotalVol;
			IPGlobal::BW_MBPS_i_6_r_5.avgTotalBw = bw.avgTotalBw;
			IPGlobal::BW_MBPS_i_6_r_5.avgUpBw = bw.avgUpBw;
			IPGlobal::BW_MBPS_i_6_r_5.avgDnBw = bw.avgDnBw;
			break;

		case 6:
			{
				switch(t_index)
				{
					case 0:
						bw = calculateBwData(t_index, bw_i_6_r_6_0);
						break;

					case 1:
						bw = calculateBwData(t_index, bw_i_6_r_6_1);
						break;
				}
			}
			IPGlobal::BW_MBPS_i_6_r_6.Bw = bw.Bw;
			IPGlobal::BW_MBPS_i_6_r_6.upBw = bw.upBw;
			IPGlobal::BW_MBPS_i_6_r_6.dnBw = bw.dnBw;
			IPGlobal::BW_MBPS_i_6_r_6.totalVol = bw.totalVol;
			IPGlobal::BW_MBPS_i_6_r_6.upTotalVol = bw.upTotalVol;
			IPGlobal::BW_MBPS_i_6_r_6.dnTotalVol = bw.dnTotalVol;
			IPGlobal::BW_MBPS_i_6_r_6.peakTotalVol 	= bw.peakTotalVol;
			IPGlobal::BW_MBPS_i_6_r_6.peakUpTotalVol = bw.peakUpTotalVol;
			IPGlobal::BW_MBPS_i_6_r_6.peakDnTotalVol = bw.peakDnTotalVol;
			IPGlobal::BW_MBPS_i_6_r_6.avgTotalBw = bw.avgTotalBw;
			IPGlobal::BW_MBPS_i_6_r_6.avgUpBw = bw.avgUpBw;
			IPGlobal::BW_MBPS_i_6_r_6.avgDnBw = bw.avgDnBw;
			break;

		case 7:
			{
				switch(t_index)
				{
					case 0:
						bw = calculateBwData(t_index, bw_i_6_r_7_0);
						break;

					case 1:
						bw = calculateBwData(t_index, bw_i_6_r_7_1);
						break;
				}
			}
			IPGlobal::BW_MBPS_i_6_r_7.Bw = bw.Bw;
			IPGlobal::BW_MBPS_i_6_r_7.upBw = bw.upBw;
			IPGlobal::BW_MBPS_i_6_r_7.dnBw = bw.dnBw;
			IPGlobal::BW_MBPS_i_6_r_7.totalVol = bw.totalVol;
			IPGlobal::BW_MBPS_i_6_r_7.upTotalVol = bw.upTotalVol;
			IPGlobal::BW_MBPS_i_6_r_7.dnTotalVol = bw.dnTotalVol;
			IPGlobal::BW_MBPS_i_6_r_7.peakTotalVol 	= bw.peakTotalVol;
			IPGlobal::BW_MBPS_i_6_r_7.peakUpTotalVol = bw.peakUpTotalVol;
			IPGlobal::BW_MBPS_i_6_r_7.peakDnTotalVol = bw.peakDnTotalVol;
			IPGlobal::BW_MBPS_i_6_r_7.avgTotalBw = bw.avgTotalBw;
			IPGlobal::BW_MBPS_i_6_r_7.avgUpBw = bw.avgUpBw;
			IPGlobal::BW_MBPS_i_6_r_7.avgDnBw = bw.avgDnBw;
			break;
	}
}

VOID BWData::setBWData_i_7(int t_index)
{
	bwData bw;

	switch(routerId)
	{
		case 0:
			{
				switch(t_index)
				{
					case 0:
						bw = calculateBwData(t_index, bw_i_7_r_0_0);
						break;

					case 1:
						bw = calculateBwData(t_index, bw_i_7_r_0_1);
						break;
				}
			}
			IPGlobal::BW_MBPS_i_7_r_0.Bw = bw.Bw;
			IPGlobal::BW_MBPS_i_7_r_0.upBw = bw.upBw;
			IPGlobal::BW_MBPS_i_7_r_0.dnBw = bw.dnBw;
			IPGlobal::BW_MBPS_i_7_r_0.totalVol = bw.totalVol;
			IPGlobal::BW_MBPS_i_7_r_0.upTotalVol = bw.upTotalVol;
			IPGlobal::BW_MBPS_i_7_r_0.dnTotalVol = bw.dnTotalVol;
			IPGlobal::BW_MBPS_i_7_r_0.peakTotalVol 	= bw.peakTotalVol;
			IPGlobal::BW_MBPS_i_7_r_0.peakUpTotalVol = bw.peakUpTotalVol;
			IPGlobal::BW_MBPS_i_7_r_0.peakDnTotalVol = bw.peakDnTotalVol;

			IPGlobal::BW_MBPS_i_7_r_0.avgTotalBw= bw.avgTotalBw;
			IPGlobal::BW_MBPS_i_7_r_0.avgUpBw 	= bw.avgUpBw;
			IPGlobal::BW_MBPS_i_7_r_0.avgDnBw 	= bw.avgDnBw;


			break;

		case 1:
			{
				switch(t_index)
				{
					case 0:
						bw = calculateBwData(t_index, bw_i_7_r_1_0);
						break;

					case 1:
						bw = calculateBwData(t_index, bw_i_7_r_1_1);
						break;
				}
			}
			IPGlobal::BW_MBPS_i_7_r_1.Bw = bw.Bw;
			IPGlobal::BW_MBPS_i_7_r_1.upBw = bw.upBw;
			IPGlobal::BW_MBPS_i_7_r_1.dnBw = bw.dnBw;
			IPGlobal::BW_MBPS_i_7_r_1.totalVol = bw.totalVol;
			IPGlobal::BW_MBPS_i_7_r_1.upTotalVol = bw.upTotalVol;
			IPGlobal::BW_MBPS_i_7_r_1.dnTotalVol = bw.dnTotalVol;
			IPGlobal::BW_MBPS_i_7_r_1.peakTotalVol 	= bw.peakTotalVol;
			IPGlobal::BW_MBPS_i_7_r_1.peakUpTotalVol = bw.peakUpTotalVol;
			IPGlobal::BW_MBPS_i_7_r_1.peakDnTotalVol = bw.peakDnTotalVol;
			IPGlobal::BW_MBPS_i_7_r_1.avgTotalBw = bw.avgTotalBw;
			IPGlobal::BW_MBPS_i_7_r_1.avgUpBw = bw.avgUpBw;
			IPGlobal::BW_MBPS_i_7_r_1.avgDnBw = bw.avgDnBw;


			break;

		case 2:
			{
				switch(t_index)
				{
					case 0:
						bw = calculateBwData(t_index, bw_i_7_r_2_0);
						break;

					case 1:
						bw = calculateBwData(t_index, bw_i_7_r_2_1);
						break;
				}
			}
			IPGlobal::BW_MBPS_i_7_r_2.Bw = bw.Bw;
			IPGlobal::BW_MBPS_i_7_r_2.upBw = bw.upBw;
			IPGlobal::BW_MBPS_i_7_r_2.dnBw = bw.dnBw;
			IPGlobal::BW_MBPS_i_7_r_2.totalVol = bw.totalVol;
			IPGlobal::BW_MBPS_i_7_r_2.upTotalVol = bw.upTotalVol;
			IPGlobal::BW_MBPS_i_7_r_2.dnTotalVol = bw.dnTotalVol;
			IPGlobal::BW_MBPS_i_7_r_2.peakTotalVol 	= bw.peakTotalVol;
			IPGlobal::BW_MBPS_i_7_r_2.peakUpTotalVol = bw.peakUpTotalVol;
			IPGlobal::BW_MBPS_i_7_r_2.peakDnTotalVol = bw.peakDnTotalVol;
			IPGlobal::BW_MBPS_i_7_r_2.avgTotalBw = bw.avgTotalBw;
			IPGlobal::BW_MBPS_i_7_r_2.avgUpBw = bw.avgUpBw;
			IPGlobal::BW_MBPS_i_7_r_2.avgDnBw = bw.avgDnBw;


			break;

		case 3:
			{
				switch(t_index)
				{
					case 0:
						bw = calculateBwData(t_index, bw_i_7_r_3_0);
						break;

					case 1:
						bw = calculateBwData(t_index, bw_i_7_r_3_1);
						break;
				}
			}
			IPGlobal::BW_MBPS_i_7_r_3.Bw = bw.Bw;
			IPGlobal::BW_MBPS_i_7_r_3.upBw = bw.upBw;
			IPGlobal::BW_MBPS_i_7_r_3.dnBw = bw.dnBw;
			IPGlobal::BW_MBPS_i_7_r_3.totalVol = bw.totalVol;
			IPGlobal::BW_MBPS_i_7_r_3.upTotalVol = bw.upTotalVol;
			IPGlobal::BW_MBPS_i_7_r_3.dnTotalVol = bw.dnTotalVol;
			IPGlobal::BW_MBPS_i_7_r_3.peakTotalVol 	= bw.peakTotalVol;
			IPGlobal::BW_MBPS_i_7_r_3.peakUpTotalVol = bw.peakUpTotalVol;
			IPGlobal::BW_MBPS_i_7_r_3.peakDnTotalVol = bw.peakDnTotalVol;
			IPGlobal::BW_MBPS_i_7_r_3.avgTotalBw = bw.avgTotalBw;
			IPGlobal::BW_MBPS_i_7_r_3.avgUpBw = bw.avgUpBw;
			IPGlobal::BW_MBPS_i_7_r_3.avgDnBw = bw.avgDnBw;
			break;

		case 4:
			{
				switch(t_index)
				{
					case 0:
						bw = calculateBwData(t_index, bw_i_7_r_4_0);
						break;

					case 1:
						bw = calculateBwData(t_index, bw_i_7_r_4_1);
						break;
				}
			}
			IPGlobal::BW_MBPS_i_7_r_4.Bw = bw.Bw;
			IPGlobal::BW_MBPS_i_7_r_4.upBw = bw.upBw;
			IPGlobal::BW_MBPS_i_7_r_4.dnBw = bw.dnBw;
			IPGlobal::BW_MBPS_i_7_r_4.totalVol = bw.totalVol;
			IPGlobal::BW_MBPS_i_7_r_4.upTotalVol = bw.upTotalVol;
			IPGlobal::BW_MBPS_i_7_r_4.dnTotalVol = bw.dnTotalVol;
			IPGlobal::BW_MBPS_i_7_r_4.peakTotalVol 	= bw.peakTotalVol;
			IPGlobal::BW_MBPS_i_7_r_4.peakUpTotalVol = bw.peakUpTotalVol;
			IPGlobal::BW_MBPS_i_7_r_4.peakDnTotalVol = bw.peakDnTotalVol;
			IPGlobal::BW_MBPS_i_7_r_4.avgTotalBw = bw.avgTotalBw;
			IPGlobal::BW_MBPS_i_7_r_4.avgUpBw = bw.avgUpBw;
			IPGlobal::BW_MBPS_i_7_r_4.avgDnBw = bw.avgDnBw;
			break;

		case 5:
			{
				switch(t_index)
				{
					case 0:
						bw = calculateBwData(t_index, bw_i_7_r_5_0);
						break;

					case 1:
						bw = calculateBwData(t_index, bw_i_7_r_5_1);
						break;
				}
			}
			IPGlobal::BW_MBPS_i_7_r_5.Bw = bw.Bw;
			IPGlobal::BW_MBPS_i_7_r_5.upBw = bw.upBw;
			IPGlobal::BW_MBPS_i_7_r_5.dnBw = bw.dnBw;
			IPGlobal::BW_MBPS_i_7_r_5.totalVol = bw.totalVol;
			IPGlobal::BW_MBPS_i_7_r_5.upTotalVol = bw.upTotalVol;
			IPGlobal::BW_MBPS_i_7_r_5.dnTotalVol = bw.dnTotalVol;
			IPGlobal::BW_MBPS_i_7_r_5.peakTotalVol 	= bw.peakTotalVol;
			IPGlobal::BW_MBPS_i_7_r_5.peakUpTotalVol = bw.peakUpTotalVol;
			IPGlobal::BW_MBPS_i_7_r_5.peakDnTotalVol = bw.peakDnTotalVol;
			IPGlobal::BW_MBPS_i_7_r_5.avgTotalBw = bw.avgTotalBw;
			IPGlobal::BW_MBPS_i_7_r_5.avgUpBw = bw.avgUpBw;
			IPGlobal::BW_MBPS_i_7_r_5.avgDnBw = bw.avgDnBw;
			break;

		case 6:
			{
				switch(t_index)
				{
					case 0:
						bw = calculateBwData(t_index, bw_i_7_r_6_0);
						break;

					case 1:
						bw = calculateBwData(t_index, bw_i_7_r_6_1);
						break;
				}
			}
			IPGlobal::BW_MBPS_i_7_r_6.Bw = bw.Bw;
			IPGlobal::BW_MBPS_i_7_r_6.upBw = bw.upBw;
			IPGlobal::BW_MBPS_i_7_r_6.dnBw = bw.dnBw;
			IPGlobal::BW_MBPS_i_7_r_6.totalVol = bw.totalVol;
			IPGlobal::BW_MBPS_i_7_r_6.upTotalVol = bw.upTotalVol;
			IPGlobal::BW_MBPS_i_7_r_6.dnTotalVol = bw.dnTotalVol;
			IPGlobal::BW_MBPS_i_7_r_6.peakTotalVol 	= bw.peakTotalVol;
			IPGlobal::BW_MBPS_i_7_r_6.peakUpTotalVol = bw.peakUpTotalVol;
			IPGlobal::BW_MBPS_i_7_r_6.peakDnTotalVol = bw.peakDnTotalVol;
			IPGlobal::BW_MBPS_i_7_r_6.avgTotalBw = bw.avgTotalBw;
			IPGlobal::BW_MBPS_i_7_r_6.avgUpBw = bw.avgUpBw;
			IPGlobal::BW_MBPS_i_7_r_6.avgDnBw = bw.avgDnBw;
			break;

		case 7:
			{
				switch(t_index)
				{
					case 0:
						bw = calculateBwData(t_index, bw_i_7_r_7_0);
						break;

					case 1:
						bw = calculateBwData(t_index, bw_i_7_r_7_1);
						break;
				}
			}
			IPGlobal::BW_MBPS_i_7_r_7.Bw = bw.Bw;
			IPGlobal::BW_MBPS_i_7_r_7.upBw = bw.upBw;
			IPGlobal::BW_MBPS_i_7_r_7.dnBw = bw.dnBw;
			IPGlobal::BW_MBPS_i_7_r_7.totalVol = bw.totalVol;
			IPGlobal::BW_MBPS_i_7_r_7.upTotalVol = bw.upTotalVol;
			IPGlobal::BW_MBPS_i_7_r_7.dnTotalVol = bw.dnTotalVol;
			IPGlobal::BW_MBPS_i_7_r_7.peakTotalVol 	= bw.peakTotalVol;
			IPGlobal::BW_MBPS_i_7_r_7.peakUpTotalVol = bw.peakUpTotalVol;
			IPGlobal::BW_MBPS_i_7_r_7.peakDnTotalVol = bw.peakDnTotalVol;
			IPGlobal::BW_MBPS_i_7_r_7.avgTotalBw = bw.avgTotalBw;
			IPGlobal::BW_MBPS_i_7_r_7.avgUpBw = bw.avgUpBw;
			IPGlobal::BW_MBPS_i_7_r_7.avgDnBw = bw.avgDnBw;
			break;
	}
}

bwData BWData::calculateBwData(int t_index, bwData (&bw)[BW_TIME_INDEX])
{
	bwData bwdata;
	bwdata.Bw 	= 0;
	bwdata.upBw = 0;
	bwdata.dnBw = 0;

	bwdata.totalVol 	= 0;
	bwdata.upTotalVol 	= 0;
	bwdata.dnTotalVol 	= 0;
	bwdata.peakTotalVol = 0;
	bwdata.peakUpTotalVol = 0;
	bwdata.peakDnTotalVol = 0;
	bwdata.avgTotalBw 	= 0;
	bwdata.avgUpBw 		= 0;
	bwdata.avgDnBw 		= 0;

	int samplesTotal 	= 0;
	int samplesUp 		= 0;
	int samplesDn 		= 0;

	for(int i = 0; i < BW_TIME_INDEX; i++)
	{

		if(bw[i].totalVol > 0)
			samplesTotal++;

		bwdata.totalVol += bw[i].totalVol;

		if(bw[i].totalVol > bwdata.peakTotalVol)
			bwdata.peakTotalVol = bw[i].totalVol;
		bw[i].totalVol = 0;

		if(bw[i].upTotalVol > 0)
			samplesUp++;

		bwdata.upTotalVol += bw[i].upTotalVol;

		if(bw[i].upTotalVol > bwdata.peakUpTotalVol)
			bwdata.peakUpTotalVol = bw[i].upTotalVol;
		bw[i].upTotalVol = 0;

		if(bw[i].dnTotalVol > 0)
			samplesDn++;

		bwdata.dnTotalVol += bw[i].dnTotalVol;

		if(bw[i].dnTotalVol > bwdata.peakDnTotalVol)
			bwdata.peakDnTotalVol = bw[i].dnTotalVol;
		bw[i].dnTotalVol = 0;
	}

	if(samplesTotal > 0){
		bwdata.avgTotalBw 	= (bwdata.totalVol * 8) / samplesTotal;
		//TheLog_nc_v7(Log::Info, name(),"          BW [%02d] [%lu] [%lu] [%lu] [%d] [%lu]", this->routerId, (bwdata.peakTotalVol * 8), bwdata.totalVol, (bwdata.totalVol * 8), samplesTotal, bwdata.avgTotalBw);
		TheLog_nc_v6(Log::Info, name(),"            BW [%03d]           [%011lu] [%011lu] [%011lu] [%02d] [%011lu]", (this->interfaceId * 100 + this->routerId), (bwdata.peakTotalVol * 8), bwdata.totalVol, (bwdata.totalVol * 8), samplesTotal, bwdata.avgTotalBw);
	}

	if(samplesUp > 0)
		bwdata.avgUpBw 		= (bwdata.upTotalVol * 8) / samplesUp;
	if(samplesDn > 0)
		bwdata.avgDnBw 		= (bwdata.dnTotalVol * 8) / samplesDn;

	return bwdata;
}

VOID BWData::processBwData(bwData (&bw)[BW_TIME_INDEX])
{
	bw[curSec].totalVol += volume;
	if(isUpDir == 1)
		bw[curSec].upTotalVol += volume;
	else if(isUpDir == 2)
		bw[curSec].dnTotalVol += volume;
}

VOID BWData::processBw(int t_index)
{
	switch(interfaceId)
	{
		case 0:
			processBw_i_0(t_index);
			break;

		case 1:
			processBw_i_1(t_index);
			break;

		case 2:
			processBw_i_2(t_index);
			break;

		case 3:
			processBw_i_3(t_index);
			break;

		case 4:
			processBw_i_4(t_index);
			break;

		case 5:
			processBw_i_5(t_index);
			break;

		case 6:
			processBw_i_6(t_index);
			break;

		case 7:
			processBw_i_7(t_index);
			break;
	}
}

VOID BWData::processBw_i_0(int t_index)
{
	switch(routerId)
	{
		case 0:
			{
				switch(t_index)
				{
					case 0:
						processBwData(bw_i_0_r_0_0);
						break;

					case 1:
						processBwData(bw_i_0_r_0_1);
						break;
				}
			}
			break;

		case 1:
			{
				switch(t_index)
				{
					case 0:
						processBwData(bw_i_0_r_1_0);
						break;

					case 1:
						processBwData(bw_i_0_r_1_1);
						break;
				}
			}
			break;

		case 2:
			{
				switch(t_index)
				{
					case 0:
						processBwData(bw_i_0_r_2_0);
						break;

					case 1:
						processBwData(bw_i_0_r_2_1);
						break;
				}
			}
			break;

		case 3:
			{
				switch(t_index)
				{
					case 0:
						processBwData(bw_i_0_r_3_0);
						break;

					case 1:
						processBwData(bw_i_0_r_3_1);
						break;
				}
			}
			break;

		case 4:
			{
				switch(t_index)
				{
					case 0:
						processBwData(bw_i_0_r_4_0);
						break;

					case 1:
						processBwData(bw_i_0_r_4_1);
						break;
				}
			}
			break;

		case 5:
			{
				switch(t_index)
				{
					case 0:
						processBwData(bw_i_0_r_5_0);
						break;

					case 1:
						processBwData(bw_i_0_r_5_1);
						break;
				}
			}
			break;

		case 6:
			{
				switch(t_index)
				{
					case 0:
						processBwData(bw_i_0_r_6_0);
						break;

					case 1:
						processBwData(bw_i_0_r_6_1);
						break;
				}
			}
			break;

		case 7:
			{
				switch(t_index)
				{
					case 0:
						processBwData(bw_i_0_r_7_0);
						break;

					case 1:
						processBwData(bw_i_0_r_7_1);
						break;
				}
			}
			break;
	}
}

VOID BWData::processBw_i_1(int t_index)
{
	switch(routerId)
	{
		case 0:
			{
				switch(t_index)
				{
					case 0:
						processBwData(bw_i_1_r_0_0);
						break;

					case 1:
						processBwData(bw_i_1_r_0_1);
						break;
				}
			}
			break;

		case 1:
			{
				switch(t_index)
				{
					case 0:
						processBwData(bw_i_1_r_1_0);
						break;

					case 1:
						processBwData(bw_i_1_r_1_1);
						break;
				}
			}
			break;

		case 2:
			{
				switch(t_index)
				{
					case 0:
						processBwData(bw_i_1_r_2_0);
						break;

					case 1:
						processBwData(bw_i_1_r_2_1);
						break;
				}
			}
			break;

		case 3:
			{
				switch(t_index)
				{
					case 0:
						processBwData(bw_i_1_r_3_0);
						break;

					case 1:
						processBwData(bw_i_1_r_3_1);
						break;
				}
			}
			break;

		case 4:
			{
				switch(t_index)
				{
					case 0:
						processBwData(bw_i_1_r_4_0);
						break;

					case 1:
						processBwData(bw_i_1_r_4_1);
						break;
				}
			}
			break;

		case 5:
			{
				switch(t_index)
				{
					case 0:
						processBwData(bw_i_1_r_5_0);
						break;

					case 1:
						processBwData(bw_i_1_r_5_1);
						break;
				}
			}
			break;

		case 6:
			{
				switch(t_index)
				{
					case 0:
						processBwData(bw_i_1_r_6_0);
						break;

					case 1:
						processBwData(bw_i_1_r_6_1);
						break;
				}
			}
			break;

		case 7:
			{
				switch(t_index)
				{
					case 0:
						processBwData(bw_i_1_r_7_0);
						break;

					case 1:
						processBwData(bw_i_1_r_7_1);
						break;
				}
			}
			break;
	}
}

VOID BWData::processBw_i_2(int t_index)
{
	switch(routerId)
	{
		case 0:
			{
				switch(t_index)
				{
					case 0:
						processBwData(bw_i_2_r_0_0);
						break;

					case 1:
						processBwData(bw_i_2_r_0_1);
						break;
				}
			}
			break;

		case 1:
			{
				switch(t_index)
				{
					case 0:
						processBwData(bw_i_2_r_1_0);
						break;

					case 1:
						processBwData(bw_i_2_r_1_1);
						break;
				}
			}
			break;

		case 2:
			{
				switch(t_index)
				{
					case 0:
						processBwData(bw_i_2_r_2_0);
						break;

					case 1:
						processBwData(bw_i_2_r_2_1);
						break;
				}
			}
			break;

		case 3:
			{
				switch(t_index)
				{
					case 0:
						processBwData(bw_i_2_r_3_0);
						break;

					case 1:
						processBwData(bw_i_2_r_3_1);
						break;
				}
			}
			break;

		case 4:
			{
				switch(t_index)
				{
					case 0:
						processBwData(bw_i_2_r_4_0);
						break;

					case 1:
						processBwData(bw_i_2_r_4_1);
						break;
				}
			}
			break;

		case 5:
			{
				switch(t_index)
				{
					case 0:
						processBwData(bw_i_2_r_5_0);
						break;

					case 1:
						processBwData(bw_i_2_r_5_1);
						break;
				}
			}
			break;

		case 6:
			{
				switch(t_index)
				{
					case 0:
						processBwData(bw_i_2_r_6_0);
						break;

					case 1:
						processBwData(bw_i_2_r_6_1);
						break;
				}
			}
			break;

		case 7:
			{
				switch(t_index)
				{
					case 0:
						processBwData(bw_i_2_r_7_0);
						break;

					case 1:
						processBwData(bw_i_2_r_7_1);
						break;
				}
			}
			break;
	}
}

VOID BWData::processBw_i_3(int t_index)
{
	switch(routerId)
	{
		case 0:
			{
				switch(t_index)
				{
					case 0:
						processBwData(bw_i_3_r_0_0);
						break;

					case 1:
						processBwData(bw_i_3_r_0_1);
						break;
				}
			}
			break;

		case 1:
			{
				switch(t_index)
				{
					case 0:
						processBwData(bw_i_3_r_1_0);
						break;

					case 1:
						processBwData(bw_i_3_r_1_1);
						break;
				}
			}
			break;

		case 2:
			{
				switch(t_index)
				{
					case 0:
						processBwData(bw_i_3_r_2_0);
						break;

					case 1:
						processBwData(bw_i_3_r_2_1);
						break;
				}
			}
			break;

		case 3:
			{
				switch(t_index)
				{
					case 0:
						processBwData(bw_i_3_r_3_0);
						break;

					case 1:
						processBwData(bw_i_3_r_3_1);
						break;
				}
			}
			break;

		case 4:
			{
				switch(t_index)
				{
					case 0:
						processBwData(bw_i_3_r_4_0);
						break;

					case 1:
						processBwData(bw_i_3_r_4_1);
						break;
				}
			}
			break;

		case 5:
			{
				switch(t_index)
				{
					case 0:
						processBwData(bw_i_3_r_5_0);
						break;

					case 1:
						processBwData(bw_i_3_r_5_1);
						break;
				}
			}
			break;

		case 6:
			{
				switch(t_index)
				{
					case 0:
						processBwData(bw_i_3_r_6_0);
						break;

					case 1:
						processBwData(bw_i_3_r_6_1);
						break;
				}
			}
			break;

		case 7:
			{
				switch(t_index)
				{
					case 0:
						processBwData(bw_i_3_r_7_0);
						break;

					case 1:
						processBwData(bw_i_3_r_7_1);
						break;
				}
			}
			break;
	}
}

VOID BWData::processBw_i_4(int t_index)
{
	switch(routerId)
	{
		case 0:
			{
				switch(t_index)
				{
					case 0:
						processBwData(bw_i_4_r_0_0);
						break;

					case 1:
						processBwData(bw_i_4_r_0_1);
						break;
				}
			}
			break;

		case 1:
			{
				switch(t_index)
				{
					case 0:
						processBwData(bw_i_4_r_1_0);
						break;

					case 1:
						processBwData(bw_i_4_r_1_1);
						break;
				}
			}
			break;

		case 2:
			{
				switch(t_index)
				{
					case 0:
						processBwData(bw_i_4_r_2_0);
						break;

					case 1:
						processBwData(bw_i_4_r_2_1);
						break;
				}
			}
			break;

		case 3:
			{
				switch(t_index)
				{
					case 0:
						processBwData(bw_i_4_r_3_0);
						break;

					case 1:
						processBwData(bw_i_4_r_3_1);
						break;
				}
			}
			break;

		case 4:
			{
				switch(t_index)
				{
					case 0:
						processBwData(bw_i_4_r_4_0);
						break;

					case 1:
						processBwData(bw_i_4_r_4_1);
						break;
				}
			}
			break;

		case 5:
			{
				switch(t_index)
				{
					case 0:
						processBwData(bw_i_4_r_5_0);
						break;

					case 1:
						processBwData(bw_i_4_r_5_1);
						break;
				}
			}
			break;

		case 6:
			{
				switch(t_index)
				{
					case 0:
						processBwData(bw_i_4_r_6_0);
						break;

					case 1:
						processBwData(bw_i_4_r_6_1);
						break;
				}
			}
			break;

		case 7:
			{
				switch(t_index)
				{
					case 0:
						processBwData(bw_i_4_r_7_0);
						break;

					case 1:
						processBwData(bw_i_4_r_7_1);
						break;
				}
			}
			break;
	}
}

VOID BWData::processBw_i_5(int t_index)
{
	switch(routerId)
	{
		case 0:
			{
				switch(t_index)
				{
					case 0:
						processBwData(bw_i_5_r_0_0);
						break;

					case 1:
						processBwData(bw_i_5_r_0_1);
						break;
				}
			}
			break;

		case 1:
			{
				switch(t_index)
				{
					case 0:
						processBwData(bw_i_5_r_1_0);
						break;

					case 1:
						processBwData(bw_i_5_r_1_1);
						break;
				}
			}
			break;

		case 2:
			{
				switch(t_index)
				{
					case 0:
						processBwData(bw_i_5_r_2_0);
						break;

					case 1:
						processBwData(bw_i_5_r_2_1);
						break;
				}
			}
			break;

		case 3:
			{
				switch(t_index)
				{
					case 0:
						processBwData(bw_i_5_r_3_0);
						break;

					case 1:
						processBwData(bw_i_5_r_3_1);
						break;
				}
			}
			break;

		case 4:
			{
				switch(t_index)
				{
					case 0:
						processBwData(bw_i_5_r_4_0);
						break;

					case 1:
						processBwData(bw_i_5_r_4_1);
						break;
				}
			}
			break;

		case 5:
			{
				switch(t_index)
				{
					case 0:
						processBwData(bw_i_5_r_5_0);
						break;

					case 1:
						processBwData(bw_i_5_r_5_1);
						break;
				}
			}
			break;

		case 6:
			{
				switch(t_index)
				{
					case 0:
						processBwData(bw_i_5_r_6_0);
						break;

					case 1:
						processBwData(bw_i_5_r_6_1);
						break;
				}
			}
			break;

		case 7:
			{
				switch(t_index)
				{
					case 0:
						processBwData(bw_i_5_r_7_0);
						break;

					case 1:
						processBwData(bw_i_5_r_7_1);
						break;
				}
			}
			break;
	}
}

VOID BWData::processBw_i_6(int t_index)
{
	switch(routerId)
	{
		case 0:
			{
				switch(t_index)
				{
					case 0:
						processBwData(bw_i_6_r_0_0);
						break;

					case 1:
						processBwData(bw_i_6_r_0_1);
						break;
				}
			}
			break;

		case 1:
			{
				switch(t_index)
				{
					case 0:
						processBwData(bw_i_6_r_1_0);
						break;

					case 1:
						processBwData(bw_i_6_r_1_1);
						break;
				}
			}
			break;

		case 2:
			{
				switch(t_index)
				{
					case 0:
						processBwData(bw_i_6_r_2_0);
						break;

					case 1:
						processBwData(bw_i_6_r_2_1);
						break;
				}
			}
			break;

		case 3:
			{
				switch(t_index)
				{
					case 0:
						processBwData(bw_i_6_r_3_0);
						break;

					case 1:
						processBwData(bw_i_6_r_3_1);
						break;
				}
			}
			break;

		case 4:
			{
				switch(t_index)
				{
					case 0:
						processBwData(bw_i_6_r_4_0);
						break;

					case 1:
						processBwData(bw_i_6_r_4_1);
						break;
				}
			}
			break;

		case 5:
			{
				switch(t_index)
				{
					case 0:
						processBwData(bw_i_6_r_5_0);
						break;

					case 1:
						processBwData(bw_i_6_r_5_1);
						break;
				}
			}
			break;

		case 6:
			{
				switch(t_index)
				{
					case 0:
						processBwData(bw_i_6_r_6_0);
						break;

					case 1:
						processBwData(bw_i_6_r_6_1);
						break;
				}
			}
			break;

		case 7:
			{
				switch(t_index)
				{
					case 0:
						processBwData(bw_i_6_r_7_0);
						break;

					case 1:
						processBwData(bw_i_6_r_7_1);
						break;
				}
			}
			break;
	}
}

VOID BWData::processBw_i_7(int t_index)
{
	switch(routerId)
	{
		case 0:
			{
				switch(t_index)
				{
					case 0:
						processBwData(bw_i_7_r_0_0);
						break;

					case 1:
						processBwData(bw_i_7_r_0_1);
						break;
				}
			}
			break;

		case 1:
			{
				switch(t_index)
				{
					case 0:
						processBwData(bw_i_7_r_1_0);
						break;

					case 1:
						processBwData(bw_i_7_r_1_1);
						break;
				}
			}
			break;

		case 2:
			{
				switch(t_index)
				{
					case 0:
						processBwData(bw_i_7_r_2_0);
						break;

					case 1:
						processBwData(bw_i_7_r_2_1);
						break;
				}
			}
			break;

		case 3:
			{
				switch(t_index)
				{
					case 0:
						processBwData(bw_i_7_r_3_0);
						break;

					case 1:
						processBwData(bw_i_7_r_3_1);
						break;
				}
			}
			break;

		case 4:
			{
				switch(t_index)
				{
					case 0:
						processBwData(bw_i_7_r_4_0);
						break;

					case 1:
						processBwData(bw_i_7_r_4_1);
						break;
				}
			}
			break;

		case 5:
			{
				switch(t_index)
				{
					case 0:
						processBwData(bw_i_7_r_5_0);
						break;

					case 1:
						processBwData(bw_i_7_r_5_1);
						break;
				}
			}
			break;

		case 6:
			{
				switch(t_index)
				{
					case 0:
						processBwData(bw_i_7_r_6_0);
						break;

					case 1:
						processBwData(bw_i_7_r_6_1);
						break;
				}
			}
			break;

		case 7:
			{
				switch(t_index)
				{
					case 0:
						processBwData(bw_i_7_r_7_0);
						break;

					case 1:
						processBwData(bw_i_7_r_7_1);
						break;
				}
			}
			break;
	}
}
