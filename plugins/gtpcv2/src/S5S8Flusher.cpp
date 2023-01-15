/*
 * S5S8Flusher.cpp
 *
 *  Created on: 24-Feb-2020
 *      Author: singh
 */

#include "S5S8Flusher.h"

S5S8Flusher::S5S8Flusher() {
	_thisLogLevel = 0;
	this->_name = "S5S8Flusher    ";
	this->setLogLevel(Log::theLog().level());

	sourceIp[0] 	= 0;
	destIp[0] 		= 0;
	endCause[0] 	= 0;
}

S5S8Flusher::~S5S8Flusher() {
}

BOOL S5S8Flusher::isRepositoryInitialized(){
	return repoInitStatus;
}

VOID S5S8Flusher::run()
{
	int lastProcessedIndex = -1;
	int curIndex = -1;
	repoInitStatus = true;

	curIndex = PKT_READ_TIME_INDEX(IPGlobal::CURRENT_EPOCH_SEC, IPGlobal::PKT_TIME_INDEX);
	lastProcessedIndex = curIndex;

	while(IPGlobal::S5S8_FLUSHER_RUNNING_STATUS)
	{
		curIndex = PKT_READ_TIME_INDEX(IPGlobal::CURRENT_EPOCH_SEC, IPGlobal::PKT_TIME_INDEX);

		while(lastProcessedIndex != curIndex)
		{
			usleep(25000);
			strcpy(csvXdr, "");
			processS5S8Data(lastProcessedIndex);

			lastProcessedIndex = PKT_READ_NEXT_TIME_INDEX(lastProcessedIndex, IPGlobal::PKT_TIME_INDEX);
		}
	}
	printf("\nIP/S11 Flusher Shutdown Completed \n");
}

VOID S5S8Flusher::processS5S8Data(int index)
{
	switch(index)
	{
		case 0:
			flushS5S8Data_t(S5S8FlushRepository::s5s8FlushMap_sm_0_t_0, S5S8FlushRepository::s5s8FlushMap_sm_0_t_0_cnt);
			flushS5S8Data_t(S5S8FlushRepository::s5s8FlushMap_sm_1_t_0, S5S8FlushRepository::s5s8FlushMap_sm_1_t_0_cnt);
			flushS5S8Data_t(S5S8FlushRepository::s5s8FlushMap_sm_2_t_0, S5S8FlushRepository::s5s8FlushMap_sm_2_t_0_cnt);
			flushS5S8Data_t(S5S8FlushRepository::s5s8FlushMap_sm_3_t_0, S5S8FlushRepository::s5s8FlushMap_sm_3_t_0_cnt);
			break;

		case 1:
			flushS5S8Data_t(S5S8FlushRepository::s5s8FlushMap_sm_0_t_1, S5S8FlushRepository::s5s8FlushMap_sm_0_t_1_cnt);
			flushS5S8Data_t(S5S8FlushRepository::s5s8FlushMap_sm_1_t_1, S5S8FlushRepository::s5s8FlushMap_sm_1_t_1_cnt);
			flushS5S8Data_t(S5S8FlushRepository::s5s8FlushMap_sm_2_t_1, S5S8FlushRepository::s5s8FlushMap_sm_2_t_1_cnt);
			flushS5S8Data_t(S5S8FlushRepository::s5s8FlushMap_sm_3_t_1, S5S8FlushRepository::s5s8FlushMap_sm_3_t_1_cnt);
			break;

		case 2:
			flushS5S8Data_t(S5S8FlushRepository::s5s8FlushMap_sm_0_t_2, S5S8FlushRepository::s5s8FlushMap_sm_0_t_2_cnt);
			flushS5S8Data_t(S5S8FlushRepository::s5s8FlushMap_sm_1_t_2, S5S8FlushRepository::s5s8FlushMap_sm_1_t_2_cnt);
			flushS5S8Data_t(S5S8FlushRepository::s5s8FlushMap_sm_2_t_2, S5S8FlushRepository::s5s8FlushMap_sm_2_t_2_cnt);
			flushS5S8Data_t(S5S8FlushRepository::s5s8FlushMap_sm_3_t_2, S5S8FlushRepository::s5s8FlushMap_sm_3_t_2_cnt);
			break;

		case 3:
			flushS5S8Data_t(S5S8FlushRepository::s5s8FlushMap_sm_0_t_3, S5S8FlushRepository::s5s8FlushMap_sm_0_t_3_cnt);
			flushS5S8Data_t(S5S8FlushRepository::s5s8FlushMap_sm_1_t_3, S5S8FlushRepository::s5s8FlushMap_sm_1_t_3_cnt);
			flushS5S8Data_t(S5S8FlushRepository::s5s8FlushMap_sm_2_t_3, S5S8FlushRepository::s5s8FlushMap_sm_2_t_3_cnt);
			flushS5S8Data_t(S5S8FlushRepository::s5s8FlushMap_sm_3_t_3, S5S8FlushRepository::s5s8FlushMap_sm_3_t_3_cnt);
			break;

		case 4:
			flushS5S8Data_t(S5S8FlushRepository::s5s8FlushMap_sm_0_t_4, S5S8FlushRepository::s5s8FlushMap_sm_0_t_4_cnt);
			flushS5S8Data_t(S5S8FlushRepository::s5s8FlushMap_sm_1_t_4, S5S8FlushRepository::s5s8FlushMap_sm_1_t_4_cnt);
			flushS5S8Data_t(S5S8FlushRepository::s5s8FlushMap_sm_2_t_4, S5S8FlushRepository::s5s8FlushMap_sm_2_t_4_cnt);
			flushS5S8Data_t(S5S8FlushRepository::s5s8FlushMap_sm_3_t_4, S5S8FlushRepository::s5s8FlushMap_sm_3_t_4_cnt);
			break;

		case 5:
			flushS5S8Data_t(S5S8FlushRepository::s5s8FlushMap_sm_0_t_5, S5S8FlushRepository::s5s8FlushMap_sm_0_t_5_cnt);
			flushS5S8Data_t(S5S8FlushRepository::s5s8FlushMap_sm_1_t_5, S5S8FlushRepository::s5s8FlushMap_sm_1_t_5_cnt);
			flushS5S8Data_t(S5S8FlushRepository::s5s8FlushMap_sm_2_t_5, S5S8FlushRepository::s5s8FlushMap_sm_2_t_5_cnt);
			flushS5S8Data_t(S5S8FlushRepository::s5s8FlushMap_sm_3_t_5, S5S8FlushRepository::s5s8FlushMap_sm_3_t_5_cnt);
			break;

		case 6:
			flushS5S8Data_t(S5S8FlushRepository::s5s8FlushMap_sm_0_t_6, S5S8FlushRepository::s5s8FlushMap_sm_0_t_6_cnt);
			flushS5S8Data_t(S5S8FlushRepository::s5s8FlushMap_sm_1_t_6, S5S8FlushRepository::s5s8FlushMap_sm_1_t_6_cnt);
			flushS5S8Data_t(S5S8FlushRepository::s5s8FlushMap_sm_2_t_6, S5S8FlushRepository::s5s8FlushMap_sm_2_t_6_cnt);
			flushS5S8Data_t(S5S8FlushRepository::s5s8FlushMap_sm_3_t_6, S5S8FlushRepository::s5s8FlushMap_sm_3_t_6_cnt);
			break;

		case 7:
			flushS5S8Data_t(S5S8FlushRepository::s5s8FlushMap_sm_0_t_7, S5S8FlushRepository::s5s8FlushMap_sm_0_t_7_cnt);
			flushS5S8Data_t(S5S8FlushRepository::s5s8FlushMap_sm_1_t_7, S5S8FlushRepository::s5s8FlushMap_sm_1_t_7_cnt);
			flushS5S8Data_t(S5S8FlushRepository::s5s8FlushMap_sm_2_t_7, S5S8FlushRepository::s5s8FlushMap_sm_2_t_7_cnt);
			flushS5S8Data_t(S5S8FlushRepository::s5s8FlushMap_sm_3_t_7, S5S8FlushRepository::s5s8FlushMap_sm_3_t_7_cnt);
			break;

		case 8:
			flushS5S8Data_t(S5S8FlushRepository::s5s8FlushMap_sm_0_t_8, S5S8FlushRepository::s5s8FlushMap_sm_0_t_8_cnt);
			flushS5S8Data_t(S5S8FlushRepository::s5s8FlushMap_sm_1_t_8, S5S8FlushRepository::s5s8FlushMap_sm_1_t_8_cnt);
			flushS5S8Data_t(S5S8FlushRepository::s5s8FlushMap_sm_2_t_8, S5S8FlushRepository::s5s8FlushMap_sm_2_t_8_cnt);
			flushS5S8Data_t(S5S8FlushRepository::s5s8FlushMap_sm_3_t_8, S5S8FlushRepository::s5s8FlushMap_sm_3_t_8_cnt);
			break;

		case 9:
			flushS5S8Data_t(S5S8FlushRepository::s5s8FlushMap_sm_0_t_9, S5S8FlushRepository::s5s8FlushMap_sm_0_t_9_cnt);
			flushS5S8Data_t(S5S8FlushRepository::s5s8FlushMap_sm_1_t_9, S5S8FlushRepository::s5s8FlushMap_sm_1_t_9_cnt);
			flushS5S8Data_t(S5S8FlushRepository::s5s8FlushMap_sm_2_t_9, S5S8FlushRepository::s5s8FlushMap_sm_2_t_9_cnt);
			flushS5S8Data_t(S5S8FlushRepository::s5s8FlushMap_sm_3_t_9, S5S8FlushRepository::s5s8FlushMap_sm_3_t_9_cnt);
			break;
	}
}

VOID S5S8Flusher::flushS5S8Data_t(std::unordered_map<int, GTPSession> &flushMap, int &s5s8FlushMap_cnt)
{
	int cnt = s5s8FlushMap_cnt;

	for(int i=0; i<cnt; i++)
	{
		buildS5S8Session(&flushMap[i]);
		strcpy(objXdrStore.xdr, csvXdr);
		flushS5S8CsvRecords();
		flushMap.erase(i);
		s5s8FlushMap_cnt--;
	}
	flushMap.clear();
	s5s8FlushMap_cnt = 0;
}

VOID S5S8Flusher::buildS5S8Session(GTPSession *pS5S8Session)
{
	sourceIp[0] = 0;
	destIp[0] = 0;

	long2Ip(pS5S8Session->sourceIp, sourceIp);
	long2Ip(pS5S8Session->destIp, destIp);

	if(pS5S8Session->EndCauseId == -1)
		strcpy(endCause, "NA");
	else
		strcpy(endCause, (const char *)GTPAttr::causeCodeMap[pS5S8Session->EndCauseId].c_str());

	sprintf(csvXdr,
	"%d,S5S8,%s,"		// 01 - Probe Id		02 - S11			03 - SessionId
	"%llu,%llu,"		// 04 - Start Time		05 - End time
	"%s,%s,"			// 06 - Source IP		07 - Destination IP
	"%d,%d,"			// 08 - VLAN			09 - eNodeB
	"%s,%s,"			// 10 - APN 			11 - IMSI
	"%s,%s,"			// 12 - IMEI			13 - MSISDN
	"%d,%s,"			// 14 - Req Msg			15 - Req Msg Desc
	"%d,%s,"			// 16 - RAT				17 - RAT Desc
	"%u,%u,"			// 18 - MME CTRL		19 - SGW CTRL
	"%u,%u,%s,%s,"		// 20 - SWG BRE			21 - NODE BRE		22 - PDN Address	23 - PDN type
	"%d,%s,"			// 23 - Rsp Meg			24 - Rsp Msg Desc
	"%d,%s,"			// 25 - Cause Code		26 - Cause Desc
	"%d,%d,%d,%d,"		// 27 - MCC				28 - MNC			29 - TAC			30 - cellId
	"%d,%d,"			// 31 - ByteSize UP		32- ByteSize DW
	"%d,%lu,"			// 33 - Flush Type		34 - Flush Time MS
	"%u,%u,"			// 36 - Req MBR UP		37 - Req MBR DW
	"%u,%u",			// 38 - Rsp MBR UP		39 - Rsp MBR DW

	IPGlobal::PROBE_ID, pS5S8Session->SessionId,
	pS5S8Session->StartTimeEpochSec, pS5S8Session->EndTimeEpochSec,
	sourceIp, destIp,
	pS5S8Session->VLanId, pS5S8Session->eNodeB,
	pS5S8Session->APN, pS5S8Session->IMSI,
	pS5S8Session->IMEI, pS5S8Session->MSISDN,
	pS5S8Session->GTPReqMsgId, GTPAttr::gtpcV2MsgType[pS5S8Session->GTPReqMsgId].c_str(),
	pS5S8Session->RAT, GTPAttr::ratTypeMap[pS5S8Session->RAT].c_str(),
	pS5S8Session->SGW_ctl_teid, pS5S8Session->PGW_ctl_teid,
	pS5S8Session->SGW_s1u_teid, pS5S8Session->eNB_s1u_teid, pS5S8Session->pdnAddress, pS5S8Session->PDNType,
	pS5S8Session->GTPRspMsgId,GTPAttr::gtpcV2MsgType[pS5S8Session->GTPRspMsgId].c_str(),
	pS5S8Session->EndCauseId, endCause,
	pS5S8Session->MCC, pS5S8Session->MNC, pS5S8Session->TAC, pS5S8Session->cellId,
	pS5S8Session->ByteSizeUL, pS5S8Session->ByteSizeDL,
	pS5S8Session->flushType, pS5S8Session->FlushTimeEpochMicroSec,
	pS5S8Session->req_mbrupl, pS5S8Session->req_mbrdnl,
	pS5S8Session->res_mbrupl, pS5S8Session->res_mbrdnl);
}

VOID S5S8Flusher::flushS5S8CsvRecords()
{
	if(strlen(csvXdr) <= 0)
		return;

	int index = PKT_WRITE_TIME_INDEX(IPGlobal::CURRENT_EPOCH_SEC, IPGlobal::PKT_TIME_INDEX);

	if(IPGlobal::S5S8_WRITE_XDR)
	{
		switch(index)
		{
			case 0:
				S5S8XdrFlush::s5s8_xdr_flush_t_0[S5S8XdrFlush::s5s8_xdr_flush_t_0_cnt] = objXdrStore;
				S5S8XdrFlush::s5s8_xdr_flush_t_0_cnt++;
				break;
			case 1:
				S5S8XdrFlush::s5s8_xdr_flush_t_1[S5S8XdrFlush::s5s8_xdr_flush_t_1_cnt] = objXdrStore;
				S5S8XdrFlush::s5s8_xdr_flush_t_1_cnt++;
				break;
			case 2:
				S5S8XdrFlush::s5s8_xdr_flush_t_2[S5S8XdrFlush::s5s8_xdr_flush_t_2_cnt] = objXdrStore;
				S5S8XdrFlush::s5s8_xdr_flush_t_2_cnt++;
				break;
			case 3:
				S5S8XdrFlush::s5s8_xdr_flush_t_3[S5S8XdrFlush::s5s8_xdr_flush_t_3_cnt] = objXdrStore;
				S5S8XdrFlush::s5s8_xdr_flush_t_3_cnt++;
				break;
			case 4:
				S5S8XdrFlush::s5s8_xdr_flush_t_4[S5S8XdrFlush::s5s8_xdr_flush_t_4_cnt] = objXdrStore;
				S5S8XdrFlush::s5s8_xdr_flush_t_4_cnt++;
				break;
			case 5:
				S5S8XdrFlush::s5s8_xdr_flush_t_5[S5S8XdrFlush::s5s8_xdr_flush_t_5_cnt] = objXdrStore;
				S5S8XdrFlush::s5s8_xdr_flush_t_5_cnt++;
				break;
			case 6:
				S5S8XdrFlush::s5s8_xdr_flush_t_6[S5S8XdrFlush::s5s8_xdr_flush_t_6_cnt] = objXdrStore;
				S5S8XdrFlush::s5s8_xdr_flush_t_6_cnt++;
				break;
			case 7:
				S5S8XdrFlush::s5s8_xdr_flush_t_7[S5S8XdrFlush::s5s8_xdr_flush_t_7_cnt] = objXdrStore;
				S5S8XdrFlush::s5s8_xdr_flush_t_7_cnt++;
				break;
			case 8:
				S5S8XdrFlush::s5s8_xdr_flush_t_8[S5S8XdrFlush::s5s8_xdr_flush_t_8_cnt] = objXdrStore;
				S5S8XdrFlush::s5s8_xdr_flush_t_8_cnt++;
				break;
			case 9:
				S5S8XdrFlush::s5s8_xdr_flush_t_9[S5S8XdrFlush::s5s8_xdr_flush_t_9_cnt] = objXdrStore;
				S5S8XdrFlush::s5s8_xdr_flush_t_9_cnt++;
				break;
		}
	}
}

