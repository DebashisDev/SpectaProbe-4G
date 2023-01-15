/*
 * GTPcParser.cpp
 *
 *  Created on: Oct 27, 2016
 *      Author: Debashis
 */

#include "GTPcParser.h"

GTPcParser::GTPcParser()
{
	this->_name = "GTPc";
	setLogLevel(Log::theLog().level());

	packet = NULL;
	hdr = 0;
	pGtpv2Parser = new GTPv2Parser();
}

GTPcParser::~GTPcParser()
{
	delete(pGtpv2Parser);
}

void GTPcParser::parsePacket(const BYTE pkt, MPacket *msgObj)
{
	packet = pkt + 8;

	hdr = getGTPHeader(packet);

	switch(hdr->Version)
	{
		case 	GTPv2:
				msgObj->gtpcVersion = GTPv2;
				break;

		default:
				msgObj->ipAppProtocol = 0;
				return;
	}

	pGtpv2Parser->parseGtpV2Packet(packet, msgObj);
}
