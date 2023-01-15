/*
 * GTPV2Parser.h
 *
 *  Created on: Oct 26, 2016
 *      Author: Debashis
 */

#ifndef PLUGINS_GN_SRC_GTPV2PARSER_H_
#define PLUGINS_GN_SRC_GTPV2PARSER_H_

#include "Log.h"
#include "ProbeUtility.h"
#include "GTPGlobal.h"
#include "GTPMsg.h"
#include "GTPv2Message.h"
#include "SpectaTypedef.h"

struct GTP_V2_hdr
{
	  uint8_t 	flags; 			    /* GTP header flags */
	  uint8_t 	version; 			/* GTP header Version */
	  uint8_t 	p_flag; 			/* Piggybacking Flag */
	  uint8_t 	t_flag;				/* teid flag */

	  uint8_t 	MsgType; 			/* Message type */
	  size_t 	MsgLen; 			/* Length of header */
	  ULONG 	MsgTeid; 			/* Tunnel End-point ID */
	  ULONG 	sequenceNo;			/* Sequence No */
};

class GTPv2Parser : public ProbeUtility {
	private:
		GTP_V2_hdr* hdrv2;
//		GTPMessageV2 *gtpMessageV2;
		size_t offset = 0;

		size_t size_of_hdr;
		size_t header_size;
		int _thisLogLevel;
		string _name;

		uint8_t p_flag;
		uint8_t t_flag;

		inline int thisLogLevel () const {return _thisLogLevel;}
		inline string name() const {return _name;}

	public:
		GTPv2Parser();
		~GTPv2Parser();
		VOID 	setLogLevel (int level) {_thisLogLevel = level;}

		VOID 	parseGtpV2Packet(const BYTE packet, MPacket *msgObj);
		inline 	GTP_V2_hdr* getGTPHeader2(const BYTE packet) { return (GTP_V2_hdr*)packet; };
		void 	get_IE_Info(size_t offset, const BYTE packet, MPacket *msgObj);
		VOID	parsePacketBody(const BYTE packet, MPacket *msgObj);
		VOID 	parse_packet(const BYTE packet, MPacket *msgObj, size_t offset);
};

#endif /* PLUGINS_GN_SRC_GTPV2PARSER_H_ */
