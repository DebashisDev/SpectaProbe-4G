/*
 * S11Flusher.cpp
 *
 *  Created on: 24-Feb-2020
 *      Author: singh
 */

#include "S11Flusher.h"

S11Flusher::S11Flusher() {
	_thisLogLevel = 0;
	this->_name = "S11Flusher    ";
	this->setLogLevel(Log::theLog().level());
	sourceIp[0] 	= 0;
	destIp[0] 		= 0;
	endCause[0] 	= 0;
}

S11Flusher::~S11Flusher() {
}

BOOL S11Flusher::isRepositoryInitialized(){
	return repoInitStatus;
}

VOID S11Flusher::run()
{
	int lastProcessedIndex = -1;
	int curIndex = -1;
	repoInitStatus = true;

	curIndex = PKT_READ_TIME_INDEX(IPGlobal::CURRENT_EPOCH_SEC, IPGlobal::PKT_TIME_INDEX);
	lastProcessedIndex = curIndex;

	while(IPGlobal::S11_FLUSHER_RUNNING_STATUS)
	{
		curIndex = PKT_READ_TIME_INDEX(IPGlobal::CURRENT_EPOCH_SEC, IPGlobal::PKT_TIME_INDEX);

		while(lastProcessedIndex != curIndex)
		{
			usleep(25000);
			strcpy(csvXdr, "");
			processS11Data(lastProcessedIndex);

			lastProcessedIndex = PKT_READ_NEXT_TIME_INDEX(lastProcessedIndex, IPGlobal::PKT_TIME_INDEX);
		}
	}
	printf("\nIP/S11 Flusher Shutdown Completed \n");
}

VOID S11Flusher::processS11Data(int index)
{
	switch(index)
	{
		case 0:
			flushS11Data_t(S11FlushRepository::s11FlushMap_sm_0_t_0, S11FlushRepository::s11FlushMap_sm_0_t_0_cnt);
			flushS11Data_t(S11FlushRepository::s11FlushMap_sm_1_t_0, S11FlushRepository::s11FlushMap_sm_1_t_0_cnt);
			flushS11Data_t(S11FlushRepository::s11FlushMap_sm_2_t_0, S11FlushRepository::s11FlushMap_sm_2_t_0_cnt);
			flushS11Data_t(S11FlushRepository::s11FlushMap_sm_3_t_0, S11FlushRepository::s11FlushMap_sm_3_t_0_cnt);
			break;

		case 1:
			flushS11Data_t(S11FlushRepository::s11FlushMap_sm_0_t_1, S11FlushRepository::s11FlushMap_sm_0_t_1_cnt);
			flushS11Data_t(S11FlushRepository::s11FlushMap_sm_1_t_1, S11FlushRepository::s11FlushMap_sm_1_t_1_cnt);
			flushS11Data_t(S11FlushRepository::s11FlushMap_sm_2_t_1, S11FlushRepository::s11FlushMap_sm_2_t_1_cnt);
			flushS11Data_t(S11FlushRepository::s11FlushMap_sm_3_t_1, S11FlushRepository::s11FlushMap_sm_3_t_1_cnt);
			break;

		case 2:
			flushS11Data_t(S11FlushRepository::s11FlushMap_sm_0_t_2, S11FlushRepository::s11FlushMap_sm_0_t_2_cnt);
			flushS11Data_t(S11FlushRepository::s11FlushMap_sm_1_t_2, S11FlushRepository::s11FlushMap_sm_1_t_2_cnt);
			flushS11Data_t(S11FlushRepository::s11FlushMap_sm_2_t_2, S11FlushRepository::s11FlushMap_sm_2_t_2_cnt);
			flushS11Data_t(S11FlushRepository::s11FlushMap_sm_3_t_2, S11FlushRepository::s11FlushMap_sm_3_t_2_cnt);
			break;

		case 3:
			flushS11Data_t(S11FlushRepository::s11FlushMap_sm_0_t_3, S11FlushRepository::s11FlushMap_sm_0_t_3_cnt);
			flushS11Data_t(S11FlushRepository::s11FlushMap_sm_1_t_3, S11FlushRepository::s11FlushMap_sm_1_t_3_cnt);
			flushS11Data_t(S11FlushRepository::s11FlushMap_sm_2_t_3, S11FlushRepository::s11FlushMap_sm_2_t_3_cnt);
			flushS11Data_t(S11FlushRepository::s11FlushMap_sm_3_t_3, S11FlushRepository::s11FlushMap_sm_3_t_3_cnt);
			break;

		case 4:
			flushS11Data_t(S11FlushRepository::s11FlushMap_sm_0_t_4, S11FlushRepository::s11FlushMap_sm_0_t_4_cnt);
			flushS11Data_t(S11FlushRepository::s11FlushMap_sm_1_t_4, S11FlushRepository::s11FlushMap_sm_1_t_4_cnt);
			flushS11Data_t(S11FlushRepository::s11FlushMap_sm_2_t_4, S11FlushRepository::s11FlushMap_sm_2_t_4_cnt);
			flushS11Data_t(S11FlushRepository::s11FlushMap_sm_3_t_4, S11FlushRepository::s11FlushMap_sm_3_t_4_cnt);
			break;

		case 5:
			flushS11Data_t(S11FlushRepository::s11FlushMap_sm_0_t_5, S11FlushRepository::s11FlushMap_sm_0_t_5_cnt);
			flushS11Data_t(S11FlushRepository::s11FlushMap_sm_1_t_5, S11FlushRepository::s11FlushMap_sm_1_t_5_cnt);
			flushS11Data_t(S11FlushRepository::s11FlushMap_sm_2_t_5, S11FlushRepository::s11FlushMap_sm_2_t_5_cnt);
			flushS11Data_t(S11FlushRepository::s11FlushMap_sm_3_t_5, S11FlushRepository::s11FlushMap_sm_3_t_5_cnt);
			break;

		case 6:
			flushS11Data_t(S11FlushRepository::s11FlushMap_sm_0_t_6, S11FlushRepository::s11FlushMap_sm_0_t_6_cnt);
			flushS11Data_t(S11FlushRepository::s11FlushMap_sm_1_t_6, S11FlushRepository::s11FlushMap_sm_1_t_6_cnt);
			flushS11Data_t(S11FlushRepository::s11FlushMap_sm_2_t_6, S11FlushRepository::s11FlushMap_sm_2_t_6_cnt);
			flushS11Data_t(S11FlushRepository::s11FlushMap_sm_3_t_6, S11FlushRepository::s11FlushMap_sm_3_t_6_cnt);
			break;

		case 7:
			flushS11Data_t(S11FlushRepository::s11FlushMap_sm_0_t_7, S11FlushRepository::s11FlushMap_sm_0_t_7_cnt);
			flushS11Data_t(S11FlushRepository::s11FlushMap_sm_1_t_7, S11FlushRepository::s11FlushMap_sm_1_t_7_cnt);
			flushS11Data_t(S11FlushRepository::s11FlushMap_sm_2_t_7, S11FlushRepository::s11FlushMap_sm_2_t_7_cnt);
			flushS11Data_t(S11FlushRepository::s11FlushMap_sm_3_t_7, S11FlushRepository::s11FlushMap_sm_3_t_7_cnt);
			break;

		case 8:
			flushS11Data_t(S11FlushRepository::s11FlushMap_sm_0_t_8, S11FlushRepository::s11FlushMap_sm_0_t_8_cnt);
			flushS11Data_t(S11FlushRepository::s11FlushMap_sm_1_t_8, S11FlushRepository::s11FlushMap_sm_1_t_8_cnt);
			flushS11Data_t(S11FlushRepository::s11FlushMap_sm_2_t_8, S11FlushRepository::s11FlushMap_sm_2_t_8_cnt);
			flushS11Data_t(S11FlushRepository::s11FlushMap_sm_3_t_8, S11FlushRepository::s11FlushMap_sm_3_t_8_cnt);
			break;

		case 9:
			flushS11Data_t(S11FlushRepository::s11FlushMap_sm_0_t_9, S11FlushRepository::s11FlushMap_sm_0_t_9_cnt);
			flushS11Data_t(S11FlushRepository::s11FlushMap_sm_1_t_9, S11FlushRepository::s11FlushMap_sm_1_t_9_cnt);
			flushS11Data_t(S11FlushRepository::s11FlushMap_sm_2_t_9, S11FlushRepository::s11FlushMap_sm_2_t_9_cnt);
			flushS11Data_t(S11FlushRepository::s11FlushMap_sm_3_t_9, S11FlushRepository::s11FlushMap_sm_3_t_9_cnt);
			break;
	}
}

VOID S11Flusher::flushS11Data_t(std::unordered_map<int, GTPSession> &flushMap, int &s11FlushMap_cnt)
{
	int cnt = s11FlushMap_cnt;

	for(int i=0; i<cnt; i++)
	{
		buildS11Session(&flushMap[i]);
		strcpy(objXdrStore.xdr, csvXdr);
		flushS11CsvRecords();
		flushMap.erase(i);
		s11FlushMap_cnt--;
	}
	flushMap.clear();
	s11FlushMap_cnt = 0;
}

VOID S11Flusher::buildS11Session(GTPSession *pS11Session)
{
	sourceIp[0] = destIp[0] = 0;

	long2Ip(pS11Session->sourceIp, sourceIp);
	long2Ip(pS11Session->destIp, destIp);

	if(pS11Session->EndCauseId == -1)
		strcpy(endCause, "NA");
	else
		strcpy(endCause, (const char *)GTPAttr::causeCodeMap[pS11Session->EndCauseId].c_str());

	sprintf(csvXdr,
	"%d,S11,%s,"		// 01 - Probe Id		02 - S11			03 - SessionId
	"%llu,%llu,"		// 04 - Start Time		05 - End time
	"%s,%s,"			// 06 - Source IP		07 - Destination IP
	"%d,%d,"			// 08 - VLAN			09 - eNodeB
	"%s,%s,"			// 10 - APN 			11 - IMSI
	"%s,%s,"			// 12 - IMEI			13 - MSISDN
	"%d,%s,"			// 14 - Req Msg			15 - Req Msg Desc
	"%d,%s,"			// 16 - RAT				17 - RAT Desc
	"%u,%u,"			// 18 - MME CTRL		19 - SGW CTRL
	"%u,%u,%s,%s,"		// 20 - SWG BRE			21 - NODE BRE		22 - PDN Address	23 - PDN Type
	"%d,%s,"			// 24 - Rsp Meg			25 - Rsp Msg Desc
	"%d,%s,"			// 26 - Cause Code		27 - Cause Desc
	"%d,%d,%d,%d,"		// 28 - MCC				29 - MNC			30 - TAC			31 - cellId
	"%d,%d,"			// 32 - ByteSize UP		33- ByteSize DW
	"%d,%lu,"			// 34 - Flush Type		35 - Flush Time MS
	"%u,%u,"			// 36 - Req MBR UP		37 - Req MBR DW
	"%u,%u",			// 38 - Rsp MBR UP		39 - Rsp MBR DW

	IPGlobal::PROBE_ID, pS11Session->SessionId,
	pS11Session->StartTimeEpochSec, pS11Session->EndTimeEpochSec,
	sourceIp, destIp,
	pS11Session->VLanId, pS11Session->eNodeB,
	pS11Session->APN, pS11Session->IMSI,
	pS11Session->IMEI, pS11Session->MSISDN,
	pS11Session->GTPReqMsgId, GTPAttr::gtpcV2MsgType[pS11Session->GTPReqMsgId].c_str(),
	pS11Session->RAT, GTPAttr::ratTypeMap[pS11Session->RAT].c_str(),
	pS11Session->MME_ctl_teid, pS11Session->SGW_ctl_teid,
	pS11Session->SGW_s1u_teid, pS11Session->eNB_s1u_teid, pS11Session->pdnAddress, pS11Session->PDNType,
	pS11Session->GTPRspMsgId,GTPAttr::gtpcV2MsgType[pS11Session->GTPRspMsgId].c_str(),
	pS11Session->EndCauseId, endCause,
	pS11Session->MCC, pS11Session->MNC, pS11Session->TAC, pS11Session->cellId,
	pS11Session->ByteSizeUL, pS11Session->ByteSizeDL,
	pS11Session->flushType, pS11Session->FlushTimeEpochMicroSec,
	pS11Session->req_mbrupl, pS11Session->req_mbrdnl,
	pS11Session->res_mbrupl, pS11Session->res_mbrdnl);
}

VOID S11Flusher::flushS11CsvRecords()
{
	if(strlen(csvXdr) <= 0)
		return;

	int index = PKT_WRITE_TIME_INDEX(IPGlobal::CURRENT_EPOCH_SEC, IPGlobal::PKT_TIME_INDEX);

	if(IPGlobal::S11_WRITE_XDR)
	{
		switch(index)
		{
			case 0:
				S11XdrFlush::s11_xdr_flush_t_0[S11XdrFlush::s11_xdr_flush_t_0_cnt] = objXdrStore;
				S11XdrFlush::s11_xdr_flush_t_0_cnt++;
				break;
			case 1:
				S11XdrFlush::s11_xdr_flush_t_1[S11XdrFlush::s11_xdr_flush_t_1_cnt] = objXdrStore;
				S11XdrFlush::s11_xdr_flush_t_1_cnt++;
				break;
			case 2:
				S11XdrFlush::s11_xdr_flush_t_2[S11XdrFlush::s11_xdr_flush_t_2_cnt] = objXdrStore;
				S11XdrFlush::s11_xdr_flush_t_2_cnt++;
				break;
			case 3:
				S11XdrFlush::s11_xdr_flush_t_3[S11XdrFlush::s11_xdr_flush_t_3_cnt] = objXdrStore;
				S11XdrFlush::s11_xdr_flush_t_3_cnt++;
				break;
			case 4:
				S11XdrFlush::s11_xdr_flush_t_4[S11XdrFlush::s11_xdr_flush_t_4_cnt] = objXdrStore;
				S11XdrFlush::s11_xdr_flush_t_4_cnt++;
				break;
			case 5:
				S11XdrFlush::s11_xdr_flush_t_5[S11XdrFlush::s11_xdr_flush_t_5_cnt] = objXdrStore;
				S11XdrFlush::s11_xdr_flush_t_5_cnt++;
				break;
			case 6:
				S11XdrFlush::s11_xdr_flush_t_6[S11XdrFlush::s11_xdr_flush_t_6_cnt] = objXdrStore;
				S11XdrFlush::s11_xdr_flush_t_6_cnt++;
				break;
			case 7:
				S11XdrFlush::s11_xdr_flush_t_7[S11XdrFlush::s11_xdr_flush_t_7_cnt] = objXdrStore;
				S11XdrFlush::s11_xdr_flush_t_7_cnt++;
				break;
			case 8:
				S11XdrFlush::s11_xdr_flush_t_8[S11XdrFlush::s11_xdr_flush_t_8_cnt] = objXdrStore;
				S11XdrFlush::s11_xdr_flush_t_8_cnt++;
				break;
			case 9:
				S11XdrFlush::s11_xdr_flush_t_9[S11XdrFlush::s11_xdr_flush_t_9_cnt] = objXdrStore;
				S11XdrFlush::s11_xdr_flush_t_9_cnt++;
				break;
		}
	}
}

