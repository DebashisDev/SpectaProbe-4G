/*
 * FLFlusherZmq.cpp
 *
 *  Created on: Apr 24, 2017
 *      Author: Debashis
 */

#include <zmq.h>

#include "zmqPush.h"

zmqPush::zmqPush() {
	this->_name = "zmqPush";
	this->setLogLevel(Log::theLog().level());
}

zmqPush::~zmqPush() {
}

BOOL zmqPush::isRepositoryInitialized() {
	return repoInitStatus;
}

VOID zmqPush::run()
{

//	struct tm *now_tm;
//	int lastProcessedIndex = -1;
//	int curIndex = -1;
//	int curMin = 0, prevMin = 0;
//	int zmqRCTestCnt = 0;
//	bool firstMin = true, firstBwData = true;
//
//	lastProcessedIndex = 0;
//
//	curMin = prevMin = IPGlobal::CURRENT_MIN;
//	curIndex = PKT_READ_TIME_INDEX(IPGlobal::CURRENT_EPOCH_SEC, 10);
//	lastProcessedIndex = curIndex;
//	repoInitStatus = true;
//
//	while(IPGlobal::IP_FLUSHER_ZMQ_RUNNING_STATUS)
//	{
//		usleep(100000);
//		curIndex = PKT_READ_TIME_INDEX(IPGlobal::CURRENT_EPOCH_SEC, 10);
//		curMin = IPGlobal::CURRENT_MIN;
//
//		/* Check ZMQ Queue's Status */
//
//		while(lastProcessedIndex != curIndex){
//			if(!IPGlobal::IP_FLUSHER_ZMQ_RUNNING_STATUS) break;
//			usleep(100000);
//			lastProcessedIndex = PKT_READ_NEXT_TIME_INDEX(lastProcessedIndex, 10);
//		}
//
//		if(curMin != prevMin){
//			if(!IPGlobal::PACKET_PROCESSING)
//			{
//				firstMin = true;
//				firstBwData = true;
//			}
//			else
//			{
//				if(firstMin){
//					firstMin = false;
//				}else{
//					if(firstBwData){
//						//Don't send the first one as it contains only zeros / less bw info
//						firstBwData = false;
//					}else{
//						sleep(5);
//						strcpy(csvXdr, "");
//						buildBwCSV(IPGlobal::CURRENT_EPOCH_MILI_SEC);
////						if(IPGlobal::IP_FLUSH_FLAG && IPGlobal::PACKET_PROCESSING && IPGlobal::PROBE_RUNNING_STATUS)
////							ipFlusherZmq->sendBWZmqData(csvXdr);
//					}
//				}
//			}
//			prevMin = curMin;
//		}
//
//		//Check for ZMQ Send Failure and take corrective action
////		if(ipFlusherZmq->ZmqTimeOutStatus) {
////			//ZMQ connection issue, reset the connection
////
////			int hbTryCnt = 0;
////			while(!ipFlusherZmq->testZmq(hbTryCnt,"FL", "HB"))
////			{
////				if(!IPGlobal::IP_FLUSHER_ZMQ_RUNNING_STATUS) break;
////
////				//To support EI restart situation, wait for 1 min before any re-connection
////				hbTryCnt++;
////				if(hbTryCnt >= 30000/ipFlusherZmq->ZMQ_TIME_OUT){
////
////					TheLog_nc_v1(Log::Error, name()," ZMQ %s", "ERROR!!! in Sending Heart Beat, Resetting Connection...");
////					ZMQReConnect();
////					sleep(1);
////
////					//After 1 min we keep trying to disconnect and connect
////					while(!ipFlusherZmq->testZmq(zmqRCTestCnt,"FL","RC"))
////					{
////						if(!IPGlobal::IP_FLUSHER_ZMQ_RUNNING_STATUS) break;
////						sleep(3);
////						zmqRCTestCnt++;
////						if(zmqRCTestCnt >= 5) {
////							zmqRCTestCnt = 0;
////							TheLog_nc_v1(Log::Error, name()," ZMQ %s", "ERROR!!! Reconnect PING Not yet succesful, Re-connecting...");
////							ZMQReConnect();
////						} /* End of If */
////					} /* End of While */
////					hbTryCnt = 0;
////				} /* End of If */
////			} /* End of While */
////
////			ipFlusherZmq->ZmqTimeOutCnt = 0;
////			ipFlusherZmq->ZmqTimeOutStatus = false;
////		}
//	}
//	printf("\nFLFlusherZmq Shutdown Completed\n");
}

VOID zmqPush::ZMQReConnect()
{
//	ipFlusherZmq->closeZmq("FL");
	TheLog_nc_v1(Log::Warn, name()," ZMQ %s", "Connections closed, waiting for 03 Sec...");
	sleep(3);
	TheLog_nc_v1(Log::Warn, name()," ZMQ %s", "Re-connecting...");
//	ipFlusherZmq->openZmq("FL");
}

//VOID zmqPush::clearZMQ()
//{
//	IPFlushRepository::ip_zmq_flush_f_0_t_0.clear();
//	IPFlushRepository::ip_zmq_flush_f_0_t_1.clear();
//	IPFlushRepository::ip_zmq_flush_f_0_t_2.clear();
//	IPFlushRepository::ip_zmq_flush_f_0_t_3.clear();
//	IPFlushRepository::ip_zmq_flush_f_0_t_4.clear();
//	IPFlushRepository::ip_zmq_flush_f_0_t_5.clear();
//	IPFlushRepository::ip_zmq_flush_f_0_t_6.clear();
//	IPFlushRepository::ip_zmq_flush_f_0_t_7.clear();
//	IPFlushRepository::ip_zmq_flush_f_0_t_8.clear();
//	IPFlushRepository::ip_zmq_flush_f_0_t_9.clear();
//
//	IPFlushRepository::ip_zmq_flush_f_0_t_0_cnt = 0;
//	IPFlushRepository::ip_zmq_flush_f_0_t_1_cnt = 0;
//	IPFlushRepository::ip_zmq_flush_f_0_t_2_cnt = 0;
//	IPFlushRepository::ip_zmq_flush_f_0_t_3_cnt = 0;
//	IPFlushRepository::ip_zmq_flush_f_0_t_4_cnt = 0;
//	IPFlushRepository::ip_zmq_flush_f_0_t_5_cnt = 0;
//	IPFlushRepository::ip_zmq_flush_f_0_t_6_cnt = 0;
//	IPFlushRepository::ip_zmq_flush_f_0_t_7_cnt = 0;
//	IPFlushRepository::ip_zmq_flush_f_0_t_8_cnt = 0;
//	IPFlushRepository::ip_zmq_flush_f_0_t_9_cnt = 0;
//
//	IPFlushRepository::ip_zmq_flush_f_1_t_0.clear();
//	IPFlushRepository::ip_zmq_flush_f_1_t_1.clear();
//	IPFlushRepository::ip_zmq_flush_f_1_t_2.clear();
//	IPFlushRepository::ip_zmq_flush_f_1_t_3.clear();
//	IPFlushRepository::ip_zmq_flush_f_1_t_4.clear();
//	IPFlushRepository::ip_zmq_flush_f_1_t_5.clear();
//	IPFlushRepository::ip_zmq_flush_f_1_t_6.clear();
//	IPFlushRepository::ip_zmq_flush_f_1_t_7.clear();
//	IPFlushRepository::ip_zmq_flush_f_1_t_8.clear();
//	IPFlushRepository::ip_zmq_flush_f_1_t_9.clear();
//
//	IPFlushRepository::ip_zmq_flush_f_1_t_0_cnt = 0;
//	IPFlushRepository::ip_zmq_flush_f_1_t_1_cnt = 0;
//	IPFlushRepository::ip_zmq_flush_f_1_t_2_cnt = 0;
//	IPFlushRepository::ip_zmq_flush_f_1_t_3_cnt = 0;
//	IPFlushRepository::ip_zmq_flush_f_1_t_4_cnt = 0;
//	IPFlushRepository::ip_zmq_flush_f_1_t_5_cnt = 0;
//	IPFlushRepository::ip_zmq_flush_f_1_t_6_cnt = 0;
//	IPFlushRepository::ip_zmq_flush_f_1_t_7_cnt = 0;
//	IPFlushRepository::ip_zmq_flush_f_1_t_8_cnt = 0;
//	IPFlushRepository::ip_zmq_flush_f_1_t_9_cnt = 0;
//
//	IPFlushRepository::ip_zmq_flush_f_2_t_0.clear();
//	IPFlushRepository::ip_zmq_flush_f_2_t_1.clear();
//	IPFlushRepository::ip_zmq_flush_f_2_t_2.clear();
//	IPFlushRepository::ip_zmq_flush_f_2_t_3.clear();
//	IPFlushRepository::ip_zmq_flush_f_2_t_4.clear();
//	IPFlushRepository::ip_zmq_flush_f_2_t_5.clear();
//	IPFlushRepository::ip_zmq_flush_f_2_t_6.clear();
//	IPFlushRepository::ip_zmq_flush_f_2_t_7.clear();
//	IPFlushRepository::ip_zmq_flush_f_2_t_8.clear();
//	IPFlushRepository::ip_zmq_flush_f_2_t_9.clear();
//
//	IPFlushRepository::ip_zmq_flush_f_2_t_0_cnt = 0;
//	IPFlushRepository::ip_zmq_flush_f_2_t_1_cnt = 0;
//	IPFlushRepository::ip_zmq_flush_f_2_t_2_cnt = 0;
//	IPFlushRepository::ip_zmq_flush_f_2_t_3_cnt = 0;
//	IPFlushRepository::ip_zmq_flush_f_2_t_4_cnt = 0;
//	IPFlushRepository::ip_zmq_flush_f_2_t_5_cnt = 0;
//	IPFlushRepository::ip_zmq_flush_f_2_t_6_cnt = 0;
//	IPFlushRepository::ip_zmq_flush_f_2_t_7_cnt = 0;
//	IPFlushRepository::ip_zmq_flush_f_2_t_8_cnt = 0;
//	IPFlushRepository::ip_zmq_flush_f_2_t_9_cnt = 0;
//
//	IPFlushRepository::ip_zmq_flush_f_3_t_0.clear();
//	IPFlushRepository::ip_zmq_flush_f_3_t_1.clear();
//	IPFlushRepository::ip_zmq_flush_f_3_t_2.clear();
//	IPFlushRepository::ip_zmq_flush_f_3_t_3.clear();
//	IPFlushRepository::ip_zmq_flush_f_3_t_4.clear();
//	IPFlushRepository::ip_zmq_flush_f_3_t_5.clear();
//	IPFlushRepository::ip_zmq_flush_f_3_t_6.clear();
//	IPFlushRepository::ip_zmq_flush_f_3_t_7.clear();
//	IPFlushRepository::ip_zmq_flush_f_3_t_8.clear();
//	IPFlushRepository::ip_zmq_flush_f_3_t_9.clear();
//
//	IPFlushRepository::ip_zmq_flush_f_3_t_0_cnt = 0;
//	IPFlushRepository::ip_zmq_flush_f_3_t_1_cnt = 0;
//	IPFlushRepository::ip_zmq_flush_f_3_t_2_cnt = 0;
//	IPFlushRepository::ip_zmq_flush_f_3_t_3_cnt = 0;
//	IPFlushRepository::ip_zmq_flush_f_3_t_4_cnt = 0;
//	IPFlushRepository::ip_zmq_flush_f_3_t_5_cnt = 0;
//	IPFlushRepository::ip_zmq_flush_f_3_t_6_cnt = 0;
//	IPFlushRepository::ip_zmq_flush_f_3_t_7_cnt = 0;
//	IPFlushRepository::ip_zmq_flush_f_3_t_8_cnt = 0;
//	IPFlushRepository::ip_zmq_flush_f_3_t_9_cnt = 0;
//}
//
//VOID zmqPush::checkZMQStatus(long epochSec)
//{
//
//	if((IPFlushRepository::zmqBufferStatus_f_0.IP_ZMQ_FULL_FLAG == true) || (IPFlushRepository::zmqBufferStatus_f_1.IP_ZMQ_FULL_FLAG == true))
//	{
//		if((epochSec - IPFlushRepository::zmqBufferStatus_f_0.lastZmqResetTime > 300) ||
//				(epochSec - IPFlushRepository::zmqBufferStatus_f_1.lastZmqResetTime > 300) ) // 5 Mins
//		{
//			TheLog_nc_v1(Log::Error, name(),"    IP ZMQ        [%s]", "IP ZMQ BUFFER FULL, Resetting ZMQ Port ...");
//			clearZMQ();
//			ipFlusherZmq->closeZmq("FL");				/* Close ZMQ 	*/
//			sleep(10);
//			ipFlusherZmq->openZmq("FL");				/* Open ZMQ 	*/
//
//			IPFlushRepository::zmqBufferStatus_f_0.IP_ZMQ_FULL_FLAG = false;
//			IPFlushRepository::zmqBufferStatus_f_0.lastZmqResetTime = epochSec;
//
//			IPFlushRepository::zmqBufferStatus_f_1.IP_ZMQ_FULL_FLAG = false;
//			IPFlushRepository::zmqBufferStatus_f_1.lastZmqResetTime = epochSec;
//		}
//	}
//}

VOID zmqPush::buildBwCSV(long timems)
{
	csvXdr[0] = 0;

	bwData bw_i_0;
	bwData bw_i_1;
	bwData bw_i_2;
	bwData bw_i_3;
	bwData bw_i_4;
	bwData bw_i_5;
	bwData bw_i_6;
	bwData bw_i_7;

	bw_i_0.peakTotalVol = IPGlobal::BW_MBPS_i_0_r_0.peakTotalVol + IPGlobal::BW_MBPS_i_0_r_1.peakTotalVol + IPGlobal::BW_MBPS_i_0_r_2.peakTotalVol + IPGlobal::BW_MBPS_i_0_r_3.peakTotalVol + IPGlobal::BW_MBPS_i_0_r_4.peakTotalVol + IPGlobal::BW_MBPS_i_0_r_5.peakTotalVol + IPGlobal::BW_MBPS_i_0_r_6.peakTotalVol + IPGlobal::BW_MBPS_i_0_r_7.peakTotalVol;
	bw_i_0.peakUpTotalVol = IPGlobal::BW_MBPS_i_0_r_0.peakUpTotalVol + IPGlobal::BW_MBPS_i_0_r_1.peakUpTotalVol + IPGlobal::BW_MBPS_i_0_r_2.peakUpTotalVol + IPGlobal::BW_MBPS_i_0_r_3.peakUpTotalVol + IPGlobal::BW_MBPS_i_0_r_4.peakUpTotalVol + IPGlobal::BW_MBPS_i_0_r_5.peakUpTotalVol + IPGlobal::BW_MBPS_i_0_r_6.peakUpTotalVol + IPGlobal::BW_MBPS_i_0_r_7.peakUpTotalVol;
	bw_i_0.peakDnTotalVol = IPGlobal::BW_MBPS_i_0_r_0.peakDnTotalVol + IPGlobal::BW_MBPS_i_0_r_1.peakDnTotalVol + IPGlobal::BW_MBPS_i_0_r_2.peakDnTotalVol + IPGlobal::BW_MBPS_i_0_r_3.peakDnTotalVol + IPGlobal::BW_MBPS_i_0_r_4.peakDnTotalVol + IPGlobal::BW_MBPS_i_0_r_5.peakDnTotalVol + IPGlobal::BW_MBPS_i_0_r_6.peakDnTotalVol + IPGlobal::BW_MBPS_i_0_r_7.peakDnTotalVol;
	bw_i_0.totalVol = IPGlobal::BW_MBPS_i_0_r_0.totalVol + IPGlobal::BW_MBPS_i_0_r_1.totalVol + IPGlobal::BW_MBPS_i_0_r_2.totalVol + IPGlobal::BW_MBPS_i_0_r_3.totalVol + IPGlobal::BW_MBPS_i_0_r_4.totalVol + IPGlobal::BW_MBPS_i_0_r_5.totalVol + IPGlobal::BW_MBPS_i_0_r_6.totalVol + IPGlobal::BW_MBPS_i_0_r_7.totalVol;
	bw_i_0.upTotalVol = IPGlobal::BW_MBPS_i_0_r_0.upTotalVol + IPGlobal::BW_MBPS_i_0_r_1.upTotalVol + IPGlobal::BW_MBPS_i_0_r_2.upTotalVol + IPGlobal::BW_MBPS_i_0_r_3.upTotalVol + IPGlobal::BW_MBPS_i_0_r_4.upTotalVol + IPGlobal::BW_MBPS_i_0_r_5.upTotalVol + IPGlobal::BW_MBPS_i_0_r_6.upTotalVol + IPGlobal::BW_MBPS_i_0_r_7.upTotalVol;
	bw_i_0.dnTotalVol = IPGlobal::BW_MBPS_i_0_r_0.dnTotalVol + IPGlobal::BW_MBPS_i_0_r_1.dnTotalVol + IPGlobal::BW_MBPS_i_0_r_2.dnTotalVol + IPGlobal::BW_MBPS_i_0_r_3.dnTotalVol + IPGlobal::BW_MBPS_i_0_r_4.dnTotalVol + IPGlobal::BW_MBPS_i_0_r_5.dnTotalVol + IPGlobal::BW_MBPS_i_0_r_6.dnTotalVol + IPGlobal::BW_MBPS_i_0_r_7.dnTotalVol;
	bw_i_0.avgTotalBw = IPGlobal::BW_MBPS_i_0_r_0.avgTotalBw + IPGlobal::BW_MBPS_i_0_r_1.avgTotalBw + IPGlobal::BW_MBPS_i_0_r_2.avgTotalBw + IPGlobal::BW_MBPS_i_0_r_3.avgTotalBw + IPGlobal::BW_MBPS_i_0_r_4.avgTotalBw + IPGlobal::BW_MBPS_i_0_r_5.avgTotalBw + IPGlobal::BW_MBPS_i_0_r_6.avgTotalBw + IPGlobal::BW_MBPS_i_0_r_7.avgTotalBw;
	bw_i_0.avgUpBw = IPGlobal::BW_MBPS_i_0_r_0.avgUpBw + IPGlobal::BW_MBPS_i_0_r_1.avgUpBw + IPGlobal::BW_MBPS_i_0_r_2.avgUpBw + IPGlobal::BW_MBPS_i_0_r_3.avgUpBw + IPGlobal::BW_MBPS_i_0_r_4.avgUpBw + IPGlobal::BW_MBPS_i_0_r_5.avgUpBw + IPGlobal::BW_MBPS_i_0_r_6.avgUpBw + IPGlobal::BW_MBPS_i_0_r_7.avgUpBw;
	bw_i_0.avgDnBw = IPGlobal::BW_MBPS_i_0_r_0.avgDnBw + IPGlobal::BW_MBPS_i_0_r_1.avgDnBw + IPGlobal::BW_MBPS_i_0_r_2.avgDnBw + IPGlobal::BW_MBPS_i_0_r_3.avgDnBw + IPGlobal::BW_MBPS_i_0_r_4.avgDnBw + IPGlobal::BW_MBPS_i_0_r_5.avgDnBw + IPGlobal::BW_MBPS_i_0_r_6.avgDnBw + IPGlobal::BW_MBPS_i_0_r_7.avgDnBw;


	bw_i_1.peakTotalVol = IPGlobal::BW_MBPS_i_1_r_0.peakTotalVol + IPGlobal::BW_MBPS_i_1_r_1.peakTotalVol + IPGlobal::BW_MBPS_i_1_r_2.peakTotalVol + IPGlobal::BW_MBPS_i_1_r_3.peakTotalVol + IPGlobal::BW_MBPS_i_1_r_4.peakTotalVol + IPGlobal::BW_MBPS_i_1_r_5.peakTotalVol + IPGlobal::BW_MBPS_i_1_r_6.peakTotalVol + IPGlobal::BW_MBPS_i_1_r_7.peakTotalVol;
	bw_i_1.peakUpTotalVol = IPGlobal::BW_MBPS_i_1_r_0.peakUpTotalVol + IPGlobal::BW_MBPS_i_1_r_1.peakUpTotalVol + IPGlobal::BW_MBPS_i_1_r_2.peakUpTotalVol + IPGlobal::BW_MBPS_i_1_r_3.peakUpTotalVol + IPGlobal::BW_MBPS_i_1_r_4.peakUpTotalVol + IPGlobal::BW_MBPS_i_1_r_5.peakUpTotalVol + IPGlobal::BW_MBPS_i_1_r_6.peakUpTotalVol + IPGlobal::BW_MBPS_i_1_r_7.peakUpTotalVol;
	bw_i_1.peakDnTotalVol = IPGlobal::BW_MBPS_i_1_r_0.peakDnTotalVol + IPGlobal::BW_MBPS_i_1_r_1.peakDnTotalVol + IPGlobal::BW_MBPS_i_1_r_2.peakDnTotalVol + IPGlobal::BW_MBPS_i_1_r_3.peakDnTotalVol + IPGlobal::BW_MBPS_i_1_r_4.peakDnTotalVol + IPGlobal::BW_MBPS_i_1_r_5.peakDnTotalVol + IPGlobal::BW_MBPS_i_1_r_6.peakDnTotalVol + IPGlobal::BW_MBPS_i_1_r_7.peakDnTotalVol;
	bw_i_1.totalVol = IPGlobal::BW_MBPS_i_1_r_0.totalVol + IPGlobal::BW_MBPS_i_1_r_1.totalVol + IPGlobal::BW_MBPS_i_1_r_2.totalVol + IPGlobal::BW_MBPS_i_1_r_3.totalVol + IPGlobal::BW_MBPS_i_1_r_4.totalVol + IPGlobal::BW_MBPS_i_1_r_5.totalVol + IPGlobal::BW_MBPS_i_1_r_6.totalVol + IPGlobal::BW_MBPS_i_1_r_7.totalVol;
	bw_i_1.upTotalVol = IPGlobal::BW_MBPS_i_1_r_0.upTotalVol + IPGlobal::BW_MBPS_i_1_r_1.upTotalVol + IPGlobal::BW_MBPS_i_1_r_2.upTotalVol + IPGlobal::BW_MBPS_i_1_r_3.upTotalVol + IPGlobal::BW_MBPS_i_1_r_4.upTotalVol + IPGlobal::BW_MBPS_i_1_r_5.upTotalVol + IPGlobal::BW_MBPS_i_1_r_6.upTotalVol + IPGlobal::BW_MBPS_i_1_r_7.upTotalVol;
	bw_i_1.dnTotalVol = IPGlobal::BW_MBPS_i_1_r_0.dnTotalVol + IPGlobal::BW_MBPS_i_1_r_1.dnTotalVol + IPGlobal::BW_MBPS_i_1_r_2.dnTotalVol + IPGlobal::BW_MBPS_i_1_r_3.dnTotalVol + IPGlobal::BW_MBPS_i_1_r_4.dnTotalVol + IPGlobal::BW_MBPS_i_1_r_5.dnTotalVol + IPGlobal::BW_MBPS_i_1_r_6.dnTotalVol + IPGlobal::BW_MBPS_i_1_r_7.dnTotalVol;
	bw_i_1.avgTotalBw = IPGlobal::BW_MBPS_i_1_r_0.avgTotalBw + IPGlobal::BW_MBPS_i_1_r_1.avgTotalBw + IPGlobal::BW_MBPS_i_1_r_2.avgTotalBw + IPGlobal::BW_MBPS_i_1_r_3.avgTotalBw + IPGlobal::BW_MBPS_i_1_r_4.avgTotalBw + IPGlobal::BW_MBPS_i_1_r_5.avgTotalBw + IPGlobal::BW_MBPS_i_1_r_6.avgTotalBw + IPGlobal::BW_MBPS_i_1_r_7.avgTotalBw;
	bw_i_1.avgUpBw = IPGlobal::BW_MBPS_i_1_r_0.avgUpBw + IPGlobal::BW_MBPS_i_1_r_1.avgUpBw + IPGlobal::BW_MBPS_i_1_r_2.avgUpBw + IPGlobal::BW_MBPS_i_1_r_3.avgUpBw + IPGlobal::BW_MBPS_i_1_r_4.avgUpBw + IPGlobal::BW_MBPS_i_1_r_5.avgUpBw + IPGlobal::BW_MBPS_i_1_r_6.avgUpBw + IPGlobal::BW_MBPS_i_1_r_7.avgUpBw;
	bw_i_1.avgDnBw = IPGlobal::BW_MBPS_i_1_r_0.avgDnBw + IPGlobal::BW_MBPS_i_1_r_1.avgDnBw + IPGlobal::BW_MBPS_i_1_r_2.avgDnBw + IPGlobal::BW_MBPS_i_1_r_3.avgDnBw + IPGlobal::BW_MBPS_i_1_r_4.avgDnBw + IPGlobal::BW_MBPS_i_1_r_5.avgDnBw + IPGlobal::BW_MBPS_i_1_r_6.avgDnBw + IPGlobal::BW_MBPS_i_1_r_7.avgDnBw;

	bw_i_2.peakTotalVol = IPGlobal::BW_MBPS_i_2_r_0.peakTotalVol + IPGlobal::BW_MBPS_i_2_r_1.peakTotalVol + IPGlobal::BW_MBPS_i_2_r_2.peakTotalVol + IPGlobal::BW_MBPS_i_2_r_3.peakTotalVol + IPGlobal::BW_MBPS_i_2_r_4.peakTotalVol + IPGlobal::BW_MBPS_i_2_r_5.peakTotalVol + IPGlobal::BW_MBPS_i_2_r_6.peakTotalVol + IPGlobal::BW_MBPS_i_2_r_7.peakTotalVol;
	bw_i_2.peakUpTotalVol = IPGlobal::BW_MBPS_i_2_r_0.peakUpTotalVol + IPGlobal::BW_MBPS_i_2_r_1.peakUpTotalVol + IPGlobal::BW_MBPS_i_2_r_2.peakUpTotalVol + IPGlobal::BW_MBPS_i_2_r_3.peakUpTotalVol + IPGlobal::BW_MBPS_i_2_r_4.peakUpTotalVol + IPGlobal::BW_MBPS_i_2_r_5.peakUpTotalVol + IPGlobal::BW_MBPS_i_2_r_6.peakUpTotalVol + IPGlobal::BW_MBPS_i_2_r_7.peakUpTotalVol;
	bw_i_2.peakDnTotalVol = IPGlobal::BW_MBPS_i_2_r_0.peakDnTotalVol + IPGlobal::BW_MBPS_i_2_r_1.peakDnTotalVol + IPGlobal::BW_MBPS_i_2_r_2.peakDnTotalVol + IPGlobal::BW_MBPS_i_2_r_3.peakDnTotalVol + IPGlobal::BW_MBPS_i_2_r_4.peakDnTotalVol + IPGlobal::BW_MBPS_i_2_r_5.peakDnTotalVol + IPGlobal::BW_MBPS_i_2_r_6.peakDnTotalVol + IPGlobal::BW_MBPS_i_2_r_7.peakDnTotalVol;
	bw_i_2.totalVol = IPGlobal::BW_MBPS_i_2_r_0.totalVol + IPGlobal::BW_MBPS_i_2_r_1.totalVol + IPGlobal::BW_MBPS_i_2_r_2.totalVol + IPGlobal::BW_MBPS_i_2_r_3.totalVol + IPGlobal::BW_MBPS_i_2_r_4.totalVol + IPGlobal::BW_MBPS_i_2_r_5.totalVol + IPGlobal::BW_MBPS_i_2_r_6.totalVol + IPGlobal::BW_MBPS_i_2_r_7.totalVol;
	bw_i_2.upTotalVol = IPGlobal::BW_MBPS_i_2_r_0.upTotalVol + IPGlobal::BW_MBPS_i_2_r_1.upTotalVol + IPGlobal::BW_MBPS_i_2_r_2.upTotalVol + IPGlobal::BW_MBPS_i_2_r_3.upTotalVol + IPGlobal::BW_MBPS_i_2_r_4.upTotalVol + IPGlobal::BW_MBPS_i_2_r_5.upTotalVol + IPGlobal::BW_MBPS_i_2_r_6.upTotalVol + IPGlobal::BW_MBPS_i_2_r_7.upTotalVol;
	bw_i_2.dnTotalVol = IPGlobal::BW_MBPS_i_2_r_0.dnTotalVol + IPGlobal::BW_MBPS_i_2_r_1.dnTotalVol + IPGlobal::BW_MBPS_i_2_r_2.dnTotalVol + IPGlobal::BW_MBPS_i_2_r_3.dnTotalVol + IPGlobal::BW_MBPS_i_2_r_4.dnTotalVol + IPGlobal::BW_MBPS_i_2_r_5.dnTotalVol + IPGlobal::BW_MBPS_i_2_r_6.dnTotalVol + IPGlobal::BW_MBPS_i_2_r_7.dnTotalVol;
	bw_i_2.avgTotalBw = IPGlobal::BW_MBPS_i_2_r_0.avgTotalBw + IPGlobal::BW_MBPS_i_2_r_1.avgTotalBw + IPGlobal::BW_MBPS_i_2_r_2.avgTotalBw + IPGlobal::BW_MBPS_i_2_r_3.avgTotalBw + IPGlobal::BW_MBPS_i_2_r_4.avgTotalBw + IPGlobal::BW_MBPS_i_2_r_5.avgTotalBw + IPGlobal::BW_MBPS_i_2_r_6.avgTotalBw + IPGlobal::BW_MBPS_i_2_r_7.avgTotalBw;
	bw_i_2.avgUpBw = IPGlobal::BW_MBPS_i_2_r_0.avgUpBw + IPGlobal::BW_MBPS_i_2_r_1.avgUpBw + IPGlobal::BW_MBPS_i_2_r_2.avgUpBw + IPGlobal::BW_MBPS_i_2_r_3.avgUpBw + IPGlobal::BW_MBPS_i_2_r_4.avgUpBw + IPGlobal::BW_MBPS_i_2_r_5.avgUpBw + IPGlobal::BW_MBPS_i_2_r_6.avgUpBw + IPGlobal::BW_MBPS_i_2_r_7.avgUpBw;
	bw_i_2.avgDnBw = IPGlobal::BW_MBPS_i_2_r_0.avgDnBw + IPGlobal::BW_MBPS_i_2_r_1.avgDnBw + IPGlobal::BW_MBPS_i_2_r_2.avgDnBw + IPGlobal::BW_MBPS_i_2_r_3.avgDnBw + IPGlobal::BW_MBPS_i_2_r_4.avgDnBw + IPGlobal::BW_MBPS_i_2_r_5.avgDnBw + IPGlobal::BW_MBPS_i_2_r_6.avgDnBw + IPGlobal::BW_MBPS_i_2_r_7.avgDnBw;

	bw_i_3.peakTotalVol = IPGlobal::BW_MBPS_i_3_r_0.peakTotalVol + IPGlobal::BW_MBPS_i_3_r_1.peakTotalVol + IPGlobal::BW_MBPS_i_3_r_2.peakTotalVol + IPGlobal::BW_MBPS_i_3_r_3.peakTotalVol + IPGlobal::BW_MBPS_i_3_r_4.peakTotalVol + IPGlobal::BW_MBPS_i_3_r_5.peakTotalVol + IPGlobal::BW_MBPS_i_3_r_6.peakTotalVol + IPGlobal::BW_MBPS_i_3_r_7.peakTotalVol;
	bw_i_3.peakUpTotalVol = IPGlobal::BW_MBPS_i_3_r_0.peakUpTotalVol + IPGlobal::BW_MBPS_i_3_r_1.peakUpTotalVol + IPGlobal::BW_MBPS_i_3_r_2.peakUpTotalVol + IPGlobal::BW_MBPS_i_3_r_3.peakUpTotalVol + IPGlobal::BW_MBPS_i_3_r_4.peakUpTotalVol + IPGlobal::BW_MBPS_i_3_r_5.peakUpTotalVol + IPGlobal::BW_MBPS_i_3_r_6.peakUpTotalVol + IPGlobal::BW_MBPS_i_3_r_7.peakUpTotalVol;
	bw_i_3.peakDnTotalVol = IPGlobal::BW_MBPS_i_3_r_0.peakDnTotalVol + IPGlobal::BW_MBPS_i_3_r_1.peakDnTotalVol + IPGlobal::BW_MBPS_i_3_r_2.peakDnTotalVol + IPGlobal::BW_MBPS_i_3_r_3.peakDnTotalVol + IPGlobal::BW_MBPS_i_3_r_4.peakDnTotalVol + IPGlobal::BW_MBPS_i_3_r_5.peakDnTotalVol + IPGlobal::BW_MBPS_i_3_r_6.peakDnTotalVol + IPGlobal::BW_MBPS_i_3_r_7.peakDnTotalVol;
	bw_i_3.totalVol = IPGlobal::BW_MBPS_i_3_r_0.totalVol + IPGlobal::BW_MBPS_i_3_r_1.totalVol + IPGlobal::BW_MBPS_i_3_r_2.totalVol + IPGlobal::BW_MBPS_i_3_r_3.totalVol + IPGlobal::BW_MBPS_i_3_r_4.totalVol + IPGlobal::BW_MBPS_i_3_r_5.totalVol + IPGlobal::BW_MBPS_i_3_r_6.totalVol + IPGlobal::BW_MBPS_i_3_r_7.totalVol;
	bw_i_3.upTotalVol = IPGlobal::BW_MBPS_i_3_r_0.upTotalVol + IPGlobal::BW_MBPS_i_3_r_1.upTotalVol + IPGlobal::BW_MBPS_i_3_r_2.upTotalVol + IPGlobal::BW_MBPS_i_3_r_3.upTotalVol + IPGlobal::BW_MBPS_i_3_r_4.upTotalVol + IPGlobal::BW_MBPS_i_3_r_5.upTotalVol + IPGlobal::BW_MBPS_i_3_r_6.upTotalVol + IPGlobal::BW_MBPS_i_3_r_7.upTotalVol;
	bw_i_3.dnTotalVol = IPGlobal::BW_MBPS_i_3_r_0.dnTotalVol + IPGlobal::BW_MBPS_i_3_r_1.dnTotalVol + IPGlobal::BW_MBPS_i_3_r_2.dnTotalVol + IPGlobal::BW_MBPS_i_3_r_3.dnTotalVol + IPGlobal::BW_MBPS_i_3_r_4.dnTotalVol + IPGlobal::BW_MBPS_i_3_r_5.dnTotalVol + IPGlobal::BW_MBPS_i_3_r_6.dnTotalVol + IPGlobal::BW_MBPS_i_3_r_7.dnTotalVol;
	bw_i_3.avgTotalBw = IPGlobal::BW_MBPS_i_3_r_0.avgTotalBw + IPGlobal::BW_MBPS_i_3_r_1.avgTotalBw + IPGlobal::BW_MBPS_i_3_r_2.avgTotalBw + IPGlobal::BW_MBPS_i_3_r_3.avgTotalBw + IPGlobal::BW_MBPS_i_3_r_4.avgTotalBw + IPGlobal::BW_MBPS_i_3_r_5.avgTotalBw + IPGlobal::BW_MBPS_i_3_r_6.avgTotalBw + IPGlobal::BW_MBPS_i_3_r_7.avgTotalBw;
	bw_i_3.avgUpBw = IPGlobal::BW_MBPS_i_3_r_0.avgUpBw + IPGlobal::BW_MBPS_i_3_r_1.avgUpBw + IPGlobal::BW_MBPS_i_3_r_2.avgUpBw + IPGlobal::BW_MBPS_i_3_r_3.avgUpBw + IPGlobal::BW_MBPS_i_3_r_4.avgUpBw + IPGlobal::BW_MBPS_i_3_r_5.avgUpBw + IPGlobal::BW_MBPS_i_3_r_6.avgUpBw + IPGlobal::BW_MBPS_i_3_r_7.avgUpBw;
	bw_i_3.avgDnBw = IPGlobal::BW_MBPS_i_3_r_0.avgDnBw + IPGlobal::BW_MBPS_i_3_r_1.avgDnBw + IPGlobal::BW_MBPS_i_3_r_2.avgDnBw + IPGlobal::BW_MBPS_i_3_r_3.avgDnBw + IPGlobal::BW_MBPS_i_3_r_4.avgDnBw + IPGlobal::BW_MBPS_i_3_r_5.avgDnBw + IPGlobal::BW_MBPS_i_3_r_6.avgDnBw + IPGlobal::BW_MBPS_i_3_r_7.avgDnBw;

	bw_i_4.peakTotalVol = IPGlobal::BW_MBPS_i_4_r_0.peakTotalVol + IPGlobal::BW_MBPS_i_4_r_1.peakTotalVol + IPGlobal::BW_MBPS_i_4_r_2.peakTotalVol + IPGlobal::BW_MBPS_i_4_r_3.peakTotalVol + IPGlobal::BW_MBPS_i_4_r_4.peakTotalVol + IPGlobal::BW_MBPS_i_4_r_5.peakTotalVol + IPGlobal::BW_MBPS_i_4_r_6.peakTotalVol + IPGlobal::BW_MBPS_i_4_r_7.peakTotalVol;
	bw_i_4.peakUpTotalVol = IPGlobal::BW_MBPS_i_4_r_0.peakUpTotalVol + IPGlobal::BW_MBPS_i_4_r_1.peakUpTotalVol + IPGlobal::BW_MBPS_i_4_r_2.peakUpTotalVol + IPGlobal::BW_MBPS_i_4_r_3.peakUpTotalVol + IPGlobal::BW_MBPS_i_4_r_4.peakUpTotalVol + IPGlobal::BW_MBPS_i_4_r_5.peakUpTotalVol + IPGlobal::BW_MBPS_i_4_r_6.peakUpTotalVol + IPGlobal::BW_MBPS_i_4_r_7.peakUpTotalVol;
	bw_i_4.peakDnTotalVol = IPGlobal::BW_MBPS_i_4_r_0.peakDnTotalVol + IPGlobal::BW_MBPS_i_4_r_1.peakDnTotalVol + IPGlobal::BW_MBPS_i_4_r_2.peakDnTotalVol + IPGlobal::BW_MBPS_i_4_r_3.peakDnTotalVol + IPGlobal::BW_MBPS_i_4_r_4.peakDnTotalVol + IPGlobal::BW_MBPS_i_4_r_5.peakDnTotalVol + IPGlobal::BW_MBPS_i_4_r_6.peakDnTotalVol + IPGlobal::BW_MBPS_i_4_r_7.peakDnTotalVol;
	bw_i_4.totalVol = IPGlobal::BW_MBPS_i_4_r_0.totalVol + IPGlobal::BW_MBPS_i_4_r_1.totalVol + IPGlobal::BW_MBPS_i_4_r_2.totalVol + IPGlobal::BW_MBPS_i_4_r_3.totalVol + IPGlobal::BW_MBPS_i_4_r_4.totalVol + IPGlobal::BW_MBPS_i_4_r_5.totalVol + IPGlobal::BW_MBPS_i_4_r_6.totalVol + IPGlobal::BW_MBPS_i_4_r_7.totalVol;
	bw_i_4.upTotalVol = IPGlobal::BW_MBPS_i_4_r_0.upTotalVol + IPGlobal::BW_MBPS_i_4_r_1.upTotalVol + IPGlobal::BW_MBPS_i_4_r_2.upTotalVol + IPGlobal::BW_MBPS_i_4_r_3.upTotalVol + IPGlobal::BW_MBPS_i_4_r_4.upTotalVol + IPGlobal::BW_MBPS_i_4_r_5.upTotalVol + IPGlobal::BW_MBPS_i_4_r_6.upTotalVol + IPGlobal::BW_MBPS_i_4_r_7.upTotalVol;
	bw_i_4.dnTotalVol = IPGlobal::BW_MBPS_i_4_r_0.dnTotalVol + IPGlobal::BW_MBPS_i_4_r_1.dnTotalVol + IPGlobal::BW_MBPS_i_4_r_2.dnTotalVol + IPGlobal::BW_MBPS_i_4_r_3.dnTotalVol + IPGlobal::BW_MBPS_i_4_r_4.dnTotalVol + IPGlobal::BW_MBPS_i_4_r_5.dnTotalVol + IPGlobal::BW_MBPS_i_4_r_6.dnTotalVol + IPGlobal::BW_MBPS_i_4_r_7.dnTotalVol;
	bw_i_4.avgTotalBw = IPGlobal::BW_MBPS_i_4_r_0.avgTotalBw + IPGlobal::BW_MBPS_i_4_r_1.avgTotalBw + IPGlobal::BW_MBPS_i_4_r_2.avgTotalBw + IPGlobal::BW_MBPS_i_4_r_3.avgTotalBw + IPGlobal::BW_MBPS_i_4_r_4.avgTotalBw + IPGlobal::BW_MBPS_i_4_r_5.avgTotalBw + IPGlobal::BW_MBPS_i_4_r_6.avgTotalBw + IPGlobal::BW_MBPS_i_4_r_7.avgTotalBw;
	bw_i_4.avgUpBw = IPGlobal::BW_MBPS_i_4_r_0.avgUpBw + IPGlobal::BW_MBPS_i_4_r_1.avgUpBw + IPGlobal::BW_MBPS_i_4_r_2.avgUpBw + IPGlobal::BW_MBPS_i_4_r_3.avgUpBw + IPGlobal::BW_MBPS_i_4_r_4.avgUpBw + IPGlobal::BW_MBPS_i_4_r_5.avgUpBw + IPGlobal::BW_MBPS_i_4_r_6.avgUpBw + IPGlobal::BW_MBPS_i_4_r_7.avgUpBw;
	bw_i_4.avgDnBw = IPGlobal::BW_MBPS_i_4_r_0.avgDnBw + IPGlobal::BW_MBPS_i_4_r_1.avgDnBw + IPGlobal::BW_MBPS_i_4_r_2.avgDnBw + IPGlobal::BW_MBPS_i_4_r_3.avgDnBw + IPGlobal::BW_MBPS_i_4_r_4.avgDnBw + IPGlobal::BW_MBPS_i_4_r_5.avgDnBw + IPGlobal::BW_MBPS_i_4_r_6.avgDnBw + IPGlobal::BW_MBPS_i_4_r_7.avgDnBw;

	bw_i_5.peakTotalVol = IPGlobal::BW_MBPS_i_5_r_0.peakTotalVol + IPGlobal::BW_MBPS_i_5_r_1.peakTotalVol + IPGlobal::BW_MBPS_i_5_r_2.peakTotalVol + IPGlobal::BW_MBPS_i_5_r_3.peakTotalVol + IPGlobal::BW_MBPS_i_5_r_4.peakTotalVol + IPGlobal::BW_MBPS_i_5_r_5.peakTotalVol + IPGlobal::BW_MBPS_i_5_r_6.peakTotalVol + IPGlobal::BW_MBPS_i_5_r_7.peakTotalVol;
	bw_i_5.peakUpTotalVol = IPGlobal::BW_MBPS_i_5_r_0.peakUpTotalVol + IPGlobal::BW_MBPS_i_5_r_1.peakUpTotalVol + IPGlobal::BW_MBPS_i_5_r_2.peakUpTotalVol + IPGlobal::BW_MBPS_i_5_r_3.peakUpTotalVol + IPGlobal::BW_MBPS_i_5_r_4.peakUpTotalVol + IPGlobal::BW_MBPS_i_5_r_5.peakUpTotalVol + IPGlobal::BW_MBPS_i_5_r_6.peakUpTotalVol + IPGlobal::BW_MBPS_i_5_r_7.peakUpTotalVol;
	bw_i_5.peakDnTotalVol = IPGlobal::BW_MBPS_i_5_r_0.peakDnTotalVol + IPGlobal::BW_MBPS_i_5_r_1.peakDnTotalVol + IPGlobal::BW_MBPS_i_5_r_2.peakDnTotalVol + IPGlobal::BW_MBPS_i_5_r_3.peakDnTotalVol + IPGlobal::BW_MBPS_i_5_r_4.peakDnTotalVol + IPGlobal::BW_MBPS_i_5_r_5.peakDnTotalVol + IPGlobal::BW_MBPS_i_5_r_6.peakDnTotalVol + IPGlobal::BW_MBPS_i_5_r_7.peakDnTotalVol;
	bw_i_5.totalVol = IPGlobal::BW_MBPS_i_5_r_0.totalVol + IPGlobal::BW_MBPS_i_5_r_1.totalVol + IPGlobal::BW_MBPS_i_5_r_2.totalVol + IPGlobal::BW_MBPS_i_5_r_3.totalVol + IPGlobal::BW_MBPS_i_5_r_4.totalVol + IPGlobal::BW_MBPS_i_5_r_5.totalVol + IPGlobal::BW_MBPS_i_5_r_6.totalVol + IPGlobal::BW_MBPS_i_5_r_7.totalVol;
	bw_i_5.upTotalVol = IPGlobal::BW_MBPS_i_5_r_0.upTotalVol + IPGlobal::BW_MBPS_i_5_r_1.upTotalVol + IPGlobal::BW_MBPS_i_5_r_2.upTotalVol + IPGlobal::BW_MBPS_i_5_r_3.upTotalVol + IPGlobal::BW_MBPS_i_5_r_4.upTotalVol + IPGlobal::BW_MBPS_i_5_r_5.upTotalVol + IPGlobal::BW_MBPS_i_5_r_6.upTotalVol + IPGlobal::BW_MBPS_i_5_r_7.upTotalVol;
	bw_i_5.dnTotalVol = IPGlobal::BW_MBPS_i_5_r_0.dnTotalVol + IPGlobal::BW_MBPS_i_5_r_1.dnTotalVol + IPGlobal::BW_MBPS_i_5_r_2.dnTotalVol + IPGlobal::BW_MBPS_i_5_r_3.dnTotalVol + IPGlobal::BW_MBPS_i_5_r_4.dnTotalVol + IPGlobal::BW_MBPS_i_5_r_5.dnTotalVol + IPGlobal::BW_MBPS_i_5_r_6.dnTotalVol + IPGlobal::BW_MBPS_i_5_r_7.dnTotalVol;
	bw_i_5.avgTotalBw = IPGlobal::BW_MBPS_i_5_r_0.avgTotalBw + IPGlobal::BW_MBPS_i_5_r_1.avgTotalBw + IPGlobal::BW_MBPS_i_5_r_2.avgTotalBw + IPGlobal::BW_MBPS_i_5_r_3.avgTotalBw + IPGlobal::BW_MBPS_i_5_r_4.avgTotalBw + IPGlobal::BW_MBPS_i_5_r_5.avgTotalBw + IPGlobal::BW_MBPS_i_5_r_6.avgTotalBw + IPGlobal::BW_MBPS_i_5_r_7.avgTotalBw;
	bw_i_5.avgUpBw = IPGlobal::BW_MBPS_i_5_r_0.avgUpBw + IPGlobal::BW_MBPS_i_5_r_1.avgUpBw + IPGlobal::BW_MBPS_i_5_r_2.avgUpBw + IPGlobal::BW_MBPS_i_5_r_3.avgUpBw + IPGlobal::BW_MBPS_i_5_r_4.avgUpBw + IPGlobal::BW_MBPS_i_5_r_5.avgUpBw + IPGlobal::BW_MBPS_i_5_r_6.avgUpBw + IPGlobal::BW_MBPS_i_5_r_7.avgUpBw;
	bw_i_5.avgDnBw = IPGlobal::BW_MBPS_i_5_r_0.avgDnBw + IPGlobal::BW_MBPS_i_5_r_1.avgDnBw + IPGlobal::BW_MBPS_i_5_r_2.avgDnBw + IPGlobal::BW_MBPS_i_5_r_3.avgDnBw + IPGlobal::BW_MBPS_i_5_r_4.avgDnBw + IPGlobal::BW_MBPS_i_5_r_5.avgDnBw + IPGlobal::BW_MBPS_i_5_r_6.avgDnBw + IPGlobal::BW_MBPS_i_5_r_7.avgDnBw;

	bw_i_6.peakTotalVol = IPGlobal::BW_MBPS_i_6_r_0.peakTotalVol + IPGlobal::BW_MBPS_i_6_r_1.peakTotalVol + IPGlobal::BW_MBPS_i_6_r_2.peakTotalVol + IPGlobal::BW_MBPS_i_6_r_3.peakTotalVol + IPGlobal::BW_MBPS_i_6_r_4.peakTotalVol + IPGlobal::BW_MBPS_i_6_r_5.peakTotalVol + IPGlobal::BW_MBPS_i_6_r_6.peakTotalVol + IPGlobal::BW_MBPS_i_6_r_7.peakTotalVol;
	bw_i_6.peakUpTotalVol = IPGlobal::BW_MBPS_i_6_r_0.peakUpTotalVol + IPGlobal::BW_MBPS_i_6_r_1.peakUpTotalVol + IPGlobal::BW_MBPS_i_6_r_2.peakUpTotalVol + IPGlobal::BW_MBPS_i_6_r_3.peakUpTotalVol + IPGlobal::BW_MBPS_i_6_r_4.peakUpTotalVol + IPGlobal::BW_MBPS_i_6_r_5.peakUpTotalVol + IPGlobal::BW_MBPS_i_6_r_6.peakUpTotalVol + IPGlobal::BW_MBPS_i_6_r_7.peakUpTotalVol;
	bw_i_6.peakDnTotalVol = IPGlobal::BW_MBPS_i_6_r_0.peakDnTotalVol + IPGlobal::BW_MBPS_i_6_r_1.peakDnTotalVol + IPGlobal::BW_MBPS_i_6_r_2.peakDnTotalVol + IPGlobal::BW_MBPS_i_6_r_3.peakDnTotalVol + IPGlobal::BW_MBPS_i_6_r_4.peakDnTotalVol + IPGlobal::BW_MBPS_i_6_r_5.peakDnTotalVol + IPGlobal::BW_MBPS_i_6_r_6.peakDnTotalVol + IPGlobal::BW_MBPS_i_6_r_7.peakDnTotalVol;
	bw_i_6.totalVol = IPGlobal::BW_MBPS_i_6_r_0.totalVol + IPGlobal::BW_MBPS_i_6_r_1.totalVol + IPGlobal::BW_MBPS_i_6_r_2.totalVol + IPGlobal::BW_MBPS_i_6_r_3.totalVol + IPGlobal::BW_MBPS_i_6_r_4.totalVol + IPGlobal::BW_MBPS_i_6_r_5.totalVol + IPGlobal::BW_MBPS_i_6_r_6.totalVol + IPGlobal::BW_MBPS_i_6_r_7.totalVol;
	bw_i_6.upTotalVol = IPGlobal::BW_MBPS_i_6_r_0.upTotalVol + IPGlobal::BW_MBPS_i_6_r_1.upTotalVol + IPGlobal::BW_MBPS_i_6_r_2.upTotalVol + IPGlobal::BW_MBPS_i_6_r_3.upTotalVol + IPGlobal::BW_MBPS_i_6_r_4.upTotalVol + IPGlobal::BW_MBPS_i_6_r_5.upTotalVol + IPGlobal::BW_MBPS_i_6_r_6.upTotalVol + IPGlobal::BW_MBPS_i_6_r_7.upTotalVol;
	bw_i_6.dnTotalVol = IPGlobal::BW_MBPS_i_6_r_0.dnTotalVol + IPGlobal::BW_MBPS_i_6_r_1.dnTotalVol + IPGlobal::BW_MBPS_i_6_r_2.dnTotalVol + IPGlobal::BW_MBPS_i_6_r_3.dnTotalVol + IPGlobal::BW_MBPS_i_6_r_4.dnTotalVol + IPGlobal::BW_MBPS_i_6_r_5.dnTotalVol + IPGlobal::BW_MBPS_i_6_r_6.dnTotalVol + IPGlobal::BW_MBPS_i_6_r_7.dnTotalVol;
	bw_i_6.avgTotalBw = IPGlobal::BW_MBPS_i_6_r_0.avgTotalBw + IPGlobal::BW_MBPS_i_6_r_1.avgTotalBw + IPGlobal::BW_MBPS_i_6_r_2.avgTotalBw + IPGlobal::BW_MBPS_i_6_r_3.avgTotalBw + IPGlobal::BW_MBPS_i_6_r_4.avgTotalBw + IPGlobal::BW_MBPS_i_6_r_5.avgTotalBw + IPGlobal::BW_MBPS_i_6_r_6.avgTotalBw + IPGlobal::BW_MBPS_i_6_r_7.avgTotalBw;
	bw_i_6.avgUpBw = IPGlobal::BW_MBPS_i_6_r_0.avgUpBw + IPGlobal::BW_MBPS_i_6_r_1.avgUpBw + IPGlobal::BW_MBPS_i_6_r_2.avgUpBw + IPGlobal::BW_MBPS_i_6_r_3.avgUpBw + IPGlobal::BW_MBPS_i_6_r_4.avgUpBw + IPGlobal::BW_MBPS_i_6_r_5.avgUpBw + IPGlobal::BW_MBPS_i_6_r_6.avgUpBw + IPGlobal::BW_MBPS_i_6_r_7.avgUpBw;
	bw_i_6.avgDnBw = IPGlobal::BW_MBPS_i_6_r_0.avgDnBw + IPGlobal::BW_MBPS_i_6_r_1.avgDnBw + IPGlobal::BW_MBPS_i_6_r_2.avgDnBw + IPGlobal::BW_MBPS_i_6_r_3.avgDnBw + IPGlobal::BW_MBPS_i_6_r_4.avgDnBw + IPGlobal::BW_MBPS_i_6_r_5.avgDnBw + IPGlobal::BW_MBPS_i_6_r_6.avgDnBw + IPGlobal::BW_MBPS_i_6_r_7.avgDnBw;

	bw_i_7.peakTotalVol = IPGlobal::BW_MBPS_i_7_r_0.peakTotalVol + IPGlobal::BW_MBPS_i_7_r_1.peakTotalVol + IPGlobal::BW_MBPS_i_7_r_2.peakTotalVol + IPGlobal::BW_MBPS_i_7_r_3.peakTotalVol + IPGlobal::BW_MBPS_i_7_r_4.peakTotalVol + IPGlobal::BW_MBPS_i_7_r_5.peakTotalVol + IPGlobal::BW_MBPS_i_7_r_6.peakTotalVol + IPGlobal::BW_MBPS_i_7_r_7.peakTotalVol;
	bw_i_7.peakUpTotalVol = IPGlobal::BW_MBPS_i_7_r_0.peakUpTotalVol + IPGlobal::BW_MBPS_i_7_r_1.peakUpTotalVol + IPGlobal::BW_MBPS_i_7_r_2.peakUpTotalVol + IPGlobal::BW_MBPS_i_7_r_3.peakUpTotalVol + IPGlobal::BW_MBPS_i_7_r_4.peakUpTotalVol + IPGlobal::BW_MBPS_i_7_r_5.peakUpTotalVol + IPGlobal::BW_MBPS_i_7_r_6.peakUpTotalVol + IPGlobal::BW_MBPS_i_7_r_7.peakUpTotalVol;
	bw_i_7.peakDnTotalVol = IPGlobal::BW_MBPS_i_7_r_0.peakDnTotalVol + IPGlobal::BW_MBPS_i_7_r_1.peakDnTotalVol + IPGlobal::BW_MBPS_i_7_r_2.peakDnTotalVol + IPGlobal::BW_MBPS_i_7_r_3.peakDnTotalVol + IPGlobal::BW_MBPS_i_7_r_4.peakDnTotalVol + IPGlobal::BW_MBPS_i_7_r_5.peakDnTotalVol + IPGlobal::BW_MBPS_i_7_r_6.peakDnTotalVol + IPGlobal::BW_MBPS_i_7_r_7.peakDnTotalVol;
	bw_i_7.totalVol = IPGlobal::BW_MBPS_i_7_r_0.totalVol + IPGlobal::BW_MBPS_i_7_r_1.totalVol + IPGlobal::BW_MBPS_i_7_r_2.totalVol + IPGlobal::BW_MBPS_i_7_r_3.totalVol + IPGlobal::BW_MBPS_i_7_r_4.totalVol + IPGlobal::BW_MBPS_i_7_r_5.totalVol + IPGlobal::BW_MBPS_i_7_r_6.totalVol + IPGlobal::BW_MBPS_i_7_r_7.totalVol;
	bw_i_7.upTotalVol = IPGlobal::BW_MBPS_i_7_r_0.upTotalVol + IPGlobal::BW_MBPS_i_7_r_1.upTotalVol + IPGlobal::BW_MBPS_i_7_r_2.upTotalVol + IPGlobal::BW_MBPS_i_7_r_3.upTotalVol + IPGlobal::BW_MBPS_i_7_r_4.upTotalVol + IPGlobal::BW_MBPS_i_7_r_5.upTotalVol + IPGlobal::BW_MBPS_i_7_r_6.upTotalVol + IPGlobal::BW_MBPS_i_7_r_7.upTotalVol;
	bw_i_7.dnTotalVol = IPGlobal::BW_MBPS_i_7_r_0.dnTotalVol + IPGlobal::BW_MBPS_i_7_r_1.dnTotalVol + IPGlobal::BW_MBPS_i_7_r_2.dnTotalVol + IPGlobal::BW_MBPS_i_7_r_3.dnTotalVol + IPGlobal::BW_MBPS_i_7_r_4.dnTotalVol + IPGlobal::BW_MBPS_i_7_r_5.dnTotalVol + IPGlobal::BW_MBPS_i_7_r_6.dnTotalVol + IPGlobal::BW_MBPS_i_7_r_7.dnTotalVol;
	bw_i_7.avgTotalBw = IPGlobal::BW_MBPS_i_7_r_0.avgTotalBw + IPGlobal::BW_MBPS_i_7_r_1.avgTotalBw + IPGlobal::BW_MBPS_i_7_r_2.avgTotalBw + IPGlobal::BW_MBPS_i_7_r_3.avgTotalBw + IPGlobal::BW_MBPS_i_7_r_4.avgTotalBw + IPGlobal::BW_MBPS_i_7_r_5.avgTotalBw + IPGlobal::BW_MBPS_i_7_r_6.avgTotalBw + IPGlobal::BW_MBPS_i_7_r_7.avgTotalBw;
	bw_i_7.avgUpBw = IPGlobal::BW_MBPS_i_7_r_0.avgUpBw + IPGlobal::BW_MBPS_i_7_r_1.avgUpBw + IPGlobal::BW_MBPS_i_7_r_2.avgUpBw + IPGlobal::BW_MBPS_i_7_r_3.avgUpBw + IPGlobal::BW_MBPS_i_7_r_4.avgUpBw + IPGlobal::BW_MBPS_i_7_r_5.avgUpBw + IPGlobal::BW_MBPS_i_7_r_6.avgUpBw + IPGlobal::BW_MBPS_i_7_r_7.avgUpBw;
	bw_i_7.avgDnBw = IPGlobal::BW_MBPS_i_7_r_0.avgDnBw + IPGlobal::BW_MBPS_i_7_r_1.avgDnBw + IPGlobal::BW_MBPS_i_7_r_2.avgDnBw + IPGlobal::BW_MBPS_i_7_r_3.avgDnBw + IPGlobal::BW_MBPS_i_7_r_4.avgDnBw + IPGlobal::BW_MBPS_i_7_r_5.avgDnBw + IPGlobal::BW_MBPS_i_7_r_6.avgDnBw + IPGlobal::BW_MBPS_i_7_r_7.avgDnBw;

	sprintf(csvXdr, "%d,%d,"
					"%ld,"
					"%lu,%lu,%lu,%lu,%lu,%lu,%lu,%lu,%lu,"
					"%lu,%lu,%lu,%lu,%lu,%lu,%lu,%lu,%lu,"
					"%lu,%lu,%lu,%lu,%lu,%lu,%lu,%lu,%lu,"
					"%lu,%lu,%lu,%lu,%lu,%lu,%lu,%lu,%lu,"
					"%lu,%lu,%lu,%lu,%lu,%lu,%lu,%lu,%lu,"
					"%lu,%lu,%lu,%lu,%lu,%lu,%lu,%lu,%lu,"
					"%lu,%lu,%lu,%lu,%lu,%lu,%lu,%lu,%lu,"
					"%lu,%lu,%lu,%lu,%lu,%lu,%lu,%lu,%lu",
			IPGlobal::PROBE_ID, XDR_ID_IP_BW,
			timems,
			bw_i_0.peakTotalVol*8, bw_i_0.peakUpTotalVol*8, bw_i_0.peakDnTotalVol*8,bw_i_0.totalVol, bw_i_0.upTotalVol, bw_i_0.dnTotalVol, bw_i_0.avgTotalBw, bw_i_0.avgUpBw, bw_i_0.avgDnBw,
			bw_i_1.peakTotalVol*8, bw_i_1.peakUpTotalVol*8, bw_i_1.peakDnTotalVol*8,bw_i_1.totalVol, bw_i_1.upTotalVol, bw_i_1.dnTotalVol, bw_i_1.avgTotalBw, bw_i_1.avgUpBw, bw_i_1.avgDnBw,
			bw_i_2.peakTotalVol*8, bw_i_2.peakUpTotalVol*8, bw_i_2.peakDnTotalVol*8,bw_i_2.totalVol, bw_i_2.upTotalVol, bw_i_2.dnTotalVol, bw_i_2.avgTotalBw, bw_i_2.avgUpBw, bw_i_2.avgDnBw,
			bw_i_3.peakTotalVol*8, bw_i_3.peakUpTotalVol*8, bw_i_3.peakDnTotalVol*8,bw_i_3.totalVol, bw_i_3.upTotalVol, bw_i_3.dnTotalVol, bw_i_3.avgTotalBw, bw_i_3.avgUpBw, bw_i_3.avgDnBw,
			bw_i_4.peakTotalVol*8, bw_i_4.peakUpTotalVol*8, bw_i_4.peakDnTotalVol*8,bw_i_4.totalVol, bw_i_4.upTotalVol, bw_i_4.dnTotalVol, bw_i_4.avgTotalBw, bw_i_4.avgUpBw, bw_i_4.avgDnBw,
			bw_i_5.peakTotalVol*8, bw_i_5.peakUpTotalVol*8, bw_i_5.peakDnTotalVol*8,bw_i_5.totalVol, bw_i_5.upTotalVol, bw_i_5.dnTotalVol, bw_i_5.avgTotalBw, bw_i_5.avgUpBw, bw_i_5.avgDnBw,
			bw_i_6.peakTotalVol*8, bw_i_6.peakUpTotalVol*8, bw_i_6.peakDnTotalVol*8,bw_i_6.totalVol, bw_i_6.upTotalVol, bw_i_6.dnTotalVol, bw_i_6.avgTotalBw, bw_i_6.avgUpBw, bw_i_6.avgDnBw,
			bw_i_7.peakTotalVol*8, bw_i_7.peakUpTotalVol*8, bw_i_7.peakDnTotalVol*8,bw_i_7.totalVol, bw_i_7.upTotalVol, bw_i_7.dnTotalVol, bw_i_7.avgTotalBw, bw_i_7.avgUpBw, bw_i_7.avgDnBw);

}
