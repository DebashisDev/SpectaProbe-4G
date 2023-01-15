/*
 * GTPV2Parser.cpp
 *
 *  Created on: Oct 26, 2016
 *      Author: Debashis
 */

#include "GTPv2Parser.h"
#include "GTPv2Message.h"

GTPv2Parser::GTPv2Parser() {
	hdrv2 = 0;
	header_size = 0;
	this->_name = "GTPv2";
	setLogLevel(Log::theLog().level());

	p_flag = 0;
	t_flag = 0;
}

GTPv2Parser::~GTPv2Parser() {
}

VOID GTPv2Parser::parseGtpV2Packet(const BYTE packet, MPacket *msgObj)
{
	TCHAR lchar[10];
	lchar[0] = 0;
	offset = 0;

	p_flag = (packet[offset] & 0x10) >> 4;		/* Piggybacking Flag */
	t_flag = (packet[offset] & 0x08) >> 3;		/* TEID Flag */

	offset += 1; 								/* Flag */

	msgObj->gtpcMsgType = VAL_BYTE(packet + offset); offset += 1; 		/* Message Type */
	msgObj->gtpcMsgLen 	= VAL_USHORT(packet + offset); offset += 2;		/* Message Length */

//	printf("Message Type| Interface %s| %d \n", GTPAttr::gtpcV2MsgType[msgObj->gtpcMsgType].c_str(), msgObj->interfaceType);

	if (t_flag)
	{ msgObj->gtpc_PktTeid = VAL_ULONG(packet + offset); offset += 4; }
	else
	{ return; }		// If there is no TEID will not decode the message

	sprintf(lchar, "%02x%02x%02x", packet[offset], packet[offset+1], packet[offset+2]);
	msgObj->gtpcV2PktSeqNo = ProbeUtility::HextoDigits(lchar);
	offset += 4; // SequenceNo (3 Bytes) + Spare (1 Byte)

	std::map<uint16_t, pGtpcMsgFunc>::iterator it = GTPv2MsgType::GtpMsgTypeParserTable.find((uint8_t)msgObj->gtpcMsgType);

	if(it != GTPv2MsgType::GtpMsgTypeParserTable.end())
		it->second(p_flag, offset, packet, msgObj);
}
