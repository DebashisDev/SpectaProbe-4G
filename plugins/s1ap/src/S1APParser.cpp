/*
 * S1AP.cpp
 *
 *  Created on: Dec 11, 2019
 *      Author: Debashis
 */

#include "S1APParser.h"

S1APParser::S1APParser()
{
	this->_name = "S1AP Parser     ";
	this->setLogLevel(Log::theLog().level());
	index = 0;
	decodedData = new EncodedBuffer();
}

S1APParser::~S1APParser()
{ delete(decodedData); }

VOID S1APParser::parsePacket(const BYTE packet, MPacket *msgObj, int chunkNo, int len)
{
	S1AP_PDU 		*msg;			/* decoded message */
	S1AP_PDU_PDU 	pdu;			/* coding container */

	int indent = 0;

	index = chunkNo;

	try
	{
		s1ap_Control ctl;
		ctl.setEncodingRules(OSS_PER_ALIGNED);
		ctl.setDecodingFlags(ctl.getDecodingFlags() | AUTOMATIC_ENCDEC);

		decodedData->set_buffer(len, (char *)packet);

		pdu.decode(ctl, *decodedData);

		msg = pdu.get_data();

		msgObj->SctpData[index].s1ap_pduType = msg->get_selection();

		switch(msgObj->SctpData[index].s1ap_pduType)
		{
			case INITIATING_MSG:
					get_InitiatingMessage(msg, msgObj);
					break;

			case SUCCESSFUL_OUTCOME:
					get_SuccessfulOutcome(msg, msgObj);
					break;

			case UNSUCCESSFUL_OUTCOME:
					get_UnSuccessfulOutcome(msg, msgObj);
					break;
		}
		pdu.free_data(ctl);
	}
	catch (...)
	{
		printf("An unexpected exception occurred While processing S1AP.\n");
    }
}

VOID S1APParser::get_InitiatingMessage(S1AP_PDU *msg, MPacket *msgObj)
{
	InitiatingMessage *initmsg = msg->get_initiatingMessage();

	printf("[Parser] Procedure Code :: %s\n", S1APInitialize::s1ap_procedureType[initmsg->get_procedureCode()].c_str());

	std::map<uint32_t, initiatingProc>::iterator it = S1AP_ProcedureMap::initiatingProcTable.find((uint32_t)initmsg->get_procedureCode());
	if(it != S1AP_ProcedureMap::initiatingProcTable.end())
	{
		msgObj->SctpData[index].s1ap_procCode = initmsg->get_procedureCode();
		it->second(initmsg, msgObj, index);
	}
}

VOID S1APParser::get_SuccessfulOutcome(S1AP_PDU *msg, MPacket *msgObj)
{
	SuccessfulOutcome *succOut = msg->get_successfulOutcome();

	printf("[Parser] SuccessfulOutcome:: Procedure Code :: %s\n", S1APInitialize::s1ap_procedureType[succOut->get_procedureCode()].c_str());

	std::map<uint32_t, successOutcomeProc>::iterator it = S1AP_ProcedureMap::successProcTable.find((uint32_t)succOut->get_procedureCode());

	if(it != S1AP_ProcedureMap::successProcTable.end())
	{
		msgObj->SctpData[index].s1ap_procCode = succOut->get_procedureCode();
		it->second(succOut, msgObj, index);
	}
}

VOID S1APParser::get_UnSuccessfulOutcome(S1AP_PDU *msg, MPacket *msgObj)
{
	UnsuccessfulOutcome *unSuOut = msg->get_unsuccessfulOutcome();

	printf("[Parser] UnsuccessfulOutcome:: Procedure Code :: %s\n", S1APInitialize::s1ap_procedureType[unSuOut->get_procedureCode()].c_str());

	std::map<uint32_t, unSuccessOutcomeProc>::iterator it = S1AP_ProcedureMap::unSuccessProcTable.find((uint32_t)unSuOut->get_procedureCode());

	if(it != S1AP_ProcedureMap::unSuccessProcTable.end())
	{
		msgObj->SctpData[index].s1ap_procCode = unSuOut->get_procedureCode();
		it->second(unSuOut, msgObj, index);
	}
}
