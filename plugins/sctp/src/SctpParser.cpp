/*
 * SctpParser.cpp
 *
 *  Created on: Jul 16, 2019
 *      Author: Debashis
 */

#include "SctpParser.h"

SctpParser::SctpParser()
{
	this->_name = "SctpParser     ";
	this->setLogLevel(Log::theLog().level());
	ps1ap = new S1APParser();
}

SctpParser::~SctpParser()
{
	delete(ps1ap);
}

VOID SctpParser::hexDump(const void* pv, int len)
{
  const unsigned char* p = (const unsigned char*) pv;
  int i;
  for( i = 0; i < len; ++i ) {
    const char* eos;
    switch( i & 15 ) {
    case 0:
      printf("%08x  ", i);
      eos = "";
      break;
    case 1:
      eos = " ";
      break;
    case 15:
      eos = "\n";
      break;
    default:
      eos = (i & 1) ? " " : "";
      break;
    }
    printf("%02x%s", (unsigned) p[i], eos);
  }
  printf(((len & 15) == 0) ? "\n" : "\n\n");
}


VOID SctpParser::parsePacket(const BYTE packet, MPacket *msgObj)
{
	uint16_t sctpHdrLen = sizeof(struct sctphdr);

	struct sctphdr *sh = (struct sctphdr *)(packet);

	msgObj->sourcePort = (uint16_t)sh->source_port;
	msgObj->destPort = (uint16_t)sh->dest_port;

	uint16_t chunkNo = 0;
	uint16_t sctp_chunk_offset = sctpHdrLen;
	uint16_t sctp_packet_length = msgObj->ipTLen - msgObj->ipHLen;

	while(sctp_chunk_offset < sctp_packet_length)
	{
		struct sctp_chunkhdr *sch = (struct sctp_chunkhdr *)(packet + sctp_chunk_offset);
		uint16_t chunk_type = sch->chunk_type;

		uint16_t chunk_length = ntohs(sch->chunk_length);

//		hexDump(packet + sctp_chunk_offset, chunk_length);

		if(chunk_length == 0) break;

		int chunk_data_length = 0;

		if(chunk_type == SCTP_DATA)
		{
			msgObj->SctpData[chunkNo].sctpLen = chunk_length + 12;
			chunk_data_length = chunk_length - (sctpHdrLen + 4); /* 4 = Chunk Header (Type, Flag, Length) */
			decodeSctpDataChunk(packet, sctp_chunk_offset, chunk_data_length, msgObj, chunkNo);
			chunkNo++;
		}
//		else
//		{ TheLog_nc_v2(Log::Trace, name(),"%s ** [SCTP] Attention!!! Not processing chunk of type [%d]", TAB, chunk_type); }

		sctp_chunk_offset += chunk_length;
	}
}

int SctpParser::decodeSctpDataChunk(const BYTE packet, int offset, int data_length, MPacket *msgObj, int chunkNo)
{
	offset += 4; // 4 = Chunk Header //sizeof(struct sctp_chunkhdr);

	msgObj->SctpData[chunkNo].sctp_reset();

//	TheLog_nc_v2(Log::Trace, name(), "%s Chunk Hdr(Bytes)  :%d", TAB, sizeof(struct sctp_chunkdata));
	struct sctp_chunkdata *pData = (struct sctp_chunkdata*)(packet+offset);
//	TheLog_nc_v2(Log::Trace, name(), "%s      TSN          : %u", TAB, ntohl(pData->tsn));
//	TheLog_nc_v2(Log::Trace, name(), "%s      Stream Id    : 0x%04x", TAB, ntohs(pData->stream_id));
//	TheLog_nc_v2(Log::Trace, name(), "%s      Sequence No. : %u", TAB, ntohs(pData->sequence_no));

	if(ntohl(pData->protocol_identifier) == IPPROTO_S1AP)
	{
//		TheLog_nc_v2(Log::Trace, name(), "%s      Protocol     : %u [S1AP]", TAB, ntohl(pData->protocol_identifier));
		offset += sizeof(struct sctp_chunkdata);

		ps1ap->parsePacket(packet + offset, msgObj, chunkNo, data_length);
	}
	return 0;
}
