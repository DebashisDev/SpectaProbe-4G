/*
 * SctpParser.h
 *
 *  Created on: Jul 16, 2019
 *      Author: Debashis
 */

#ifndef PLUGINS_SCTP_SRC_SCTPPARSER_H_
#define PLUGINS_SCTP_SRC_SCTPPARSER_H_

#include "IPGlobal.h"
#include "SpectaTypedef.h"
#include "BaseConfig.h"
#include "Log.h"

#include "S1APParser.h"

#define IPPROTO_M3UA (0x0003)
#define IPPROTO_S1AP (0x0012)

#define SCTP_DATA 0
#define SCTP_INIT 1
#define SCTP_INIT_ACK 2
#define SCTP_SACK 3
#define SCTP_HEARTBEAT 4
#define SCTP_HEARTBEAT_ACK 5
#define SCTP_ABORT 6
#define SCTP_SHUTDOWN 7
#define SCTP_SHUTDOWN_ACK 8
#define SCTP_ERROR 9
#define SCTP_COOKIE_ECHO 10
#define SCTP_COOKIE_ACK 11
#define SCTP_ECNE 12
#define SCTP_CWR 13
#define SCTP_SHUTDOWN_COMPLETE 14

struct sctphdr {
	unsigned short source_port;	// 2 bytes
	unsigned short dest_port;
	unsigned int verification_tag;
	unsigned int checksum;
	/* chunks follow */
}__attribute__((packed));

/*
** SCTP chunk
*/
struct sctp_chunk {
	unsigned int tsn_ack;
	unsigned int arwc;
	unsigned short ngab;
	unsigned short nd_tsn;
	/* optional params */
}__attribute__((packed));

/*
** SCTP chunk Header
*/
struct sctp_chunkhdr {
	unsigned char chunk_type;
	unsigned char chunk_flags;
	unsigned short chunk_length;
	/* optional params */
}__attribute__((packed));

/*
** sctp chunk data Type = zero
*/
struct sctp_chunkdata {
	unsigned int tsn;
	unsigned short stream_id;
	unsigned short sequence_no;
	unsigned int protocol_identifier;
	//unsigned char payload[0];
}__attribute__((packed));

/*
** SCTOP chunk optional/varibale length paramaters definiton
*/
struct sctp_paramhdr {
	unsigned short param_type;
	unsigned short param_length;
}__attribute__((packed));


class SctpParser : BaseConfig {
	public:
		SctpParser();
		~SctpParser();
		VOID parsePacket(const BYTE packet, MPacket *msgObj);

	private:
		S1APParser *ps1ap;

		void hexDump(const void* pv, int len);
		int  decodeSctpDataChunk(const BYTE packet, int offset, int data_length, MPacket *msgObj, int chunkNo);
};

#endif /* PLUGINS_SCTP_SRC_SCTPPARSER_H_ */
