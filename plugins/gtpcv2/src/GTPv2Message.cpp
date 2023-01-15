/*
 * GTPMessageV2.cpp
 *
 *  Created on: Jun 9, 2016
 *      Author: Debashis
 */
#include "GTPv2Message.h"

#include <malloc.h>
#include <string.h>
#include <Commondefs.h>
#include <IpAddress.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>

char* GTPv2Message::get_mnc_mcc_str(uint8_t* m_data, uint32_t offset)
{
	int mcc_mnc;
	uint8_t octet;
	uint16_t mcc, mnc;
	mcc = mnc = 0;

	uint8_t mcc1, mcc2, mcc3, mnc1, mnc2, mnc3;
	bool long_mnc;
	/* MCC + MNC */
	memcpy(&mcc_mnc, (m_data + offset), sizeof(uint8_t)*3);

	/* Mobile country code MCC */
	octet = (uint8_t)*(m_data + offset);
	mcc1 = octet & 0x0f;
	mcc2 = octet >> 4;
	offset++;
	octet = (uint8_t)*(m_data + offset);
	mcc3 = octet & 0x0f;
	/* MNC, Mobile network code (octet 3 bits 5 to 8, octet 4) */
	mnc3 = octet >> 4;
	offset++;
	octet = (uint8_t)*(m_data + offset);
	mnc1 = octet & 0x0f;
	mnc2 = octet >> 4;

	mcc = 100 * mcc1 + 10 * mcc2 + mcc3;
	mnc = 10 * mnc1 + mnc2;
	if ((mnc3 != 0xf) || (mcc_mnc == 0xffffff))
	{
		long_mnc = true;
#if BYTE_ORDER == LITTLE_ENDIAN
		mnc = 10 * mnc + mnc3;
#endif
#if BYTE_ORDER == BIG_ENDIAN
		mnc = 100 * mnc3 + mnc;
#endif
	}
	char* str = (char*)malloc(48);
	memset(str, 0x0, 48);
	sprintf(str, "%u-%u", mcc, mnc);

	return (str);
}

size_t GTPv2Message::get_cause_info(uint8_t* m_data, uint32_t offset, MPacket *msgObj)
{
	size_t ie_length = 0;
	uint16_t msg_ie_len; // = (uint16_t)*(m_data + offset);

	memcpy(&msg_ie_len, (m_data + offset), sizeof(uint16_t));
	uint16_t msg_ie_len_h = ntohs(msg_ie_len);

	if (msg_ie_len_h < 1)
		return 3;

	ie_length = msg_ie_len_h + 3;
	uint8_t cause_val = *(m_data + offset + 3);

	msgObj->gtpcCauseCode = cause_val;
	return (ie_length);
}

char* GTPv2Message::bcd_to_str(uint8_t* m_data, uint32_t offset, uint32_t e_usr_addr_ln)
{
	uint32_t length = 0;
	uint8_t octet;
	int iCount = 0;
	char *imsi_str = NULL;
	/*
	 *  0 1 2 3 4 5 6 7 8 9 a b c d e f
	 *  1 2 3 4 5 6 7 8 9 ? ? ? ? ? ? ?
	 * */
	const uint8_t out[16] = {'0','1','2','3','4','5','6','7','8','9','?','?','?','?','?','?'};
	uint32_t t_offset = 0;

	length = e_usr_addr_ln;
	imsi_str = (char *)malloc(((size_t)length)*2+1);
	while (length > t_offset)
	{
		octet = *(m_data + offset);
		offset++;
		imsi_str[iCount] = out[octet & 0x0f];
		iCount++;
	  /*
	   * unpack second value in byte
   	   */
		octet = octet >> 4;
		if (octet == 0x0f)
		{
			break;	/* odd number bytes - hit filler */
		}
		imsi_str[iCount] = out[octet & 0x0f];
		iCount++;
		t_offset++;
	}
	imsi_str[iCount]= '\0';

	return (imsi_str);
}

size_t GTPv2Message::get_imsi_info(uint8_t* m_data, uint32_t offset, MPacket *msgObj)
{
	uint16_t imsi_len;
	memcpy(&imsi_len, (m_data + offset), sizeof(uint16_t));
	uint16_t imsi_len_h = ntohs(imsi_len);
	if (imsi_len_h < 1)
		return 3;
	char* imsi = NULL;
	offset = offset + 3;
	imsi = GTPv2Message::bcd_to_str(m_data, offset, imsi_len_h);
	strcpy(msgObj->IMSI, imsi);
//	printf("	IMSI :: %s\n", msgObj->IMSI);

	if (imsi != NULL)
		delete[] imsi;

	return (imsi_len_h + 3);
}

uint8_t* GTPv2Message::decode_apn(uint8_t * m_data, uint16_t length)
{
	 uint8_t* str = new uint8_t[MAX_APN_LENGTH+1];
	 uint32_t curr_len;

	 memset(str, 0, MAX_APN_LENGTH+1);
	 memcpy(str, m_data, length<MAX_APN_LENGTH?length:MAX_APN_LENGTH);
	 curr_len = 0;
	 while ((curr_len < length) && (curr_len < MAX_APN_LENGTH))
	 {
		 uint32_t step = str[curr_len];
		 str[curr_len] = '.';
		 curr_len += step+1;
	 }
	 return str;
}

size_t GTPv2Message::get_msisdn_info(uint8_t* m_data, uint32_t offset, MPacket *msgObj)
{
	uint16_t msisdn_len; // = (uint16_t)*(m_data + offset);
	memcpy(&msisdn_len, (m_data + offset), sizeof(uint16_t));
	uint16_t msisdn_len_h = ntohs(msisdn_len);
	if (msisdn_len_h < 1 || msisdn_len_h > 16)
		return 3;
	char* msisdn = NULL;
	offset = offset + 3;
	msisdn = GTPv2Message::bcd_to_str(m_data, offset, msisdn_len_h);
	strcpy(msgObj->MSISDN, msisdn);
	if (msisdn != NULL)
		delete[] msisdn;
	return (msisdn_len_h + 3);
}

size_t GTPv2Message::get_recovery_restr_counter(uint8_t* m_data, uint32_t offset, MPacket *msgObj)
{
	size_t ie_length = 0;
	uint16_t msg_ie_len; // = (uint16_t)*(m_data + offset);
	memcpy(&msg_ie_len, (m_data + offset), sizeof(uint16_t));
	uint16_t msg_ie_len_h = ntohs(msg_ie_len);
	if (msg_ie_len_h < 1 )
		return 3;
	ie_length = msg_ie_len_h + 3;
	offset = offset + 3;
	uint32_t counetr_value;
	memcpy(&counetr_value, (m_data + offset), sizeof(uint32_t));
	msgObj->counter_val = ntohl(counetr_value);
	return (ie_length);
}

size_t GTPv2Message::get_STN_SR_info(uint8_t* m_data, uint32_t offset, MPacket *msgObj)
{
	size_t ie_length = 0;
	uint16_t msg_ie_len; // = (uint16_t)*(m_data + offset);
	memcpy(&msg_ie_len, (m_data + offset), sizeof(uint16_t));
	uint16_t msg_ie_len_h = ntohs(msg_ie_len);
	if (msg_ie_len_h < 1 || msg_ie_len_h >16)
		return 3;
	ie_length = msg_ie_len_h + 3;
	char str[msg_ie_len_h];
	for(int i = 0; i < msg_ie_len_h; i++)
	  memcpy(&str[i], (m_data + offset + 3 + i), sizeof(uint8_t));
	strcpy(msgObj->STN_SR, str);
	return (ie_length);
}

size_t GTPv2Message::get_private_data_info(uint8_t* m_data, uint32_t offset, MPacket *msgObj)
{
	size_t ie_length = 0;
	uint16_t msg_ie_len; // = (uint16_t)*(m_data + offset);
	memcpy(&msg_ie_len, (m_data + offset), sizeof(uint16_t));
	uint16_t msg_ie_len_h = ntohs(msg_ie_len);
	if (msg_ie_len_h < 1)
		return 3;
	else
		ie_length = msg_ie_len_h + 3;
	// to do break CGI,SAI,RAI,TAI,ECGI,LAI
	return (ie_length);
}

size_t GTPv2Message::get_access_pt_name_info(uint8_t* m_data, uint32_t offset, MPacket *msgObj)
{
	size_t ie_length = 0;
	uint16_t apn_len ; //= (uint16_t)*(m_data + offset);
	memcpy(&apn_len, (m_data + offset), sizeof(uint16_t));
	uint16_t apn_len_h = ntohs(apn_len);
	offset += 3;
	uint8_t* apn = GTPv2Message::decode_apn((m_data + offset), apn_len_h);
	strcpy(msgObj->gtpcAPN, (const char *)apn);

	if (apn != NULL)
	  delete apn;
	ie_length = apn_len_h + 3;

//	printf("APN = %s\n", msgObj->gtpcAPN);

	return (ie_length);
}

size_t GTPv2Message::get_ambr_info(uint8_t* m_data, uint32_t offset, MPacket *msgObj)
{
	size_t ie_length = 0;
	uint16_t msg_ie_len; // = (uint16_t)*(m_data + offset);
	memcpy(&msg_ie_len, (m_data + offset), sizeof(uint16_t));
	uint16_t msg_ie_len_h = ntohs(msg_ie_len);
	if (msg_ie_len_h < 1)
		return 3;
	ie_length = msg_ie_len_h + 3;
	uint32_t ulink_bit_rate, dlink_bit_rate;
	memcpy(&ulink_bit_rate, (m_data + offset + 3), sizeof(uint32_t));
	memcpy(&dlink_bit_rate, (m_data + offset + 3 + 4), sizeof(uint32_t));
	msgObj->gtpcMbrupl = ntohl(ulink_bit_rate);
	msgObj->gtpcMbrdnl = ntohl(dlink_bit_rate);
	return (ie_length);
}

size_t GTPv2Message::get_ip_address_info(uint8_t* m_data, uint32_t offset, MPacket *msgObj)
{
	size_t ie_length = 0;
	uint16_t msg_ie_len; // = (uint16_t)*(m_data + offset);
	memcpy(&msg_ie_len, (m_data + offset), sizeof(uint16_t));
	uint16_t msg_ie_len_h = ntohs(msg_ie_len);
	if (msg_ie_len_h < 1)
		return 3;
	ie_length = msg_ie_len_h + 3;
	offset = offset + 3;
	if (msg_ie_len_h == 4)
	{
	  // ipv4 address
	  uint32_t ipv4addr;
	  memcpy(&ipv4addr, (m_data + offset), sizeof(uint32_t));
	  IPv4Address ip = IPv4Address(ipv4addr);
//	  if (ip.isValid())
//	  msgObj->gtpUserIpAddress = ip.toString();

	}
	else if (msg_ie_len_h == 16)
	{
	    // ipv6 address
	    char* ipv6	= new char[msg_ie_len_h];
	    for(int i = 0; i < msg_ie_len_h; i++)
	    ipv6[i] = *(m_data + offset + i);
	    IPv6Address ip = IPv6Address(ipv6);
//	    if (ip.isValid())
//		msgObj->gtpUserIpAddress = ip.toString();
	    delete[] ipv6;
	}
	return (ie_length);
}

size_t GTPv2Message::get_mei_info(uint8_t* m_data, uint32_t offset, MPacket *msgObj)
{
	uint16_t mei_len; // = (uint16_t)*(m_data + offset);
	memcpy(&mei_len, (m_data + offset), sizeof(uint16_t));
	uint16_t mei_len_h = ntohs(mei_len);
	if (mei_len_h < 1)
		return 3;
	char* mei = NULL;

	mei = GTPv2Message::bcd_to_str(m_data, (offset + 3), mei_len_h);
	strcpy(msgObj->IMEI, mei);

	if (mei != NULL)
		delete[] mei;
	return (mei_len_h + 3);
}

size_t GTPv2Message::get_pdn_access_aloc_info(uint8_t* m_data, uint32_t offset, MPacket *msgObj)
{
	char ipBuffer[40];
	size_t ie_length = 0;
	uint16_t msg_ie_len; // = (uint16_t)*(m_data + offset);
	memcpy(&msg_ie_len, (m_data + offset), sizeof(uint16_t));
	uint16_t msg_ie_len_h = ntohs(msg_ie_len);

	if (msg_ie_len_h < 1)
		return 3;

	ie_length = msg_ie_len_h + 3;
	uint8_t pdn_type = *(m_data + offset + 3) & 0x7;
	offset = offset + 4;

	switch(pdn_type)
	{
		case 1:		// IPv4
		{
			unsigned int address;
			ipBuffer[0] = 0;
			address = (m_data[offset] << 24) | (m_data[offset+1] << 16) | (m_data[offset+2] << 8) | (m_data[offset+3]);
			sprintf((char *)ipBuffer,"%d.%d.%d.%d",(address & 0xFF000000) >> 24,(address & 0x00FF0000) >> 16,(address & 0x0000FF00) >> 8, address & 0x000000FF);
			strcpy(msgObj->pdnAddrAllocation, ipBuffer);
		}
		break;

		case 2:		// IPv6
		{
			ipBuffer[0] = 0;
			sprintf(ipBuffer,"%02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x", m_data[offset], m_data[offset+1], \
					m_data[offset+2], m_data[offset+3], m_data[offset+4], m_data[offset+5], m_data[offset+6], m_data[offset+7], m_data[offset+8], m_data[offset+9], \
					m_data[offset+10], m_data[offset+11], m_data[offset+12], m_data[offset+13], m_data[offset+14], m_data[offset+15], m_data[offset+16]);
			strcpy(msgObj->pdnAddrAllocation, ipBuffer);
		}
	}
	return (ie_length);
}

size_t GTPv2Message::get_rat_info(uint8_t* m_data, uint32_t offset, MPacket *msgObj)
{
	size_t ie_length = 0;
	uint16_t mei_len; // = (uint16_t)*(m_data + offset);
	memcpy(&mei_len, (m_data + offset), sizeof(uint16_t));
	uint16_t mei_len_h = ntohs(mei_len);
	if (mei_len_h < 1)
	  return 3;
	ie_length = mei_len_h + 3;
	uint8_t ie_type = *(m_data + offset + 3);
	if ((uint32_t)ie_type > 8)
	  return (ie_length);

	msgObj->gtpcRAT = ie_type;
//	printf("RAT::%s\n", GTPAttr::ratTypeMap[msgObj->gtpcRAT].c_str());

	return (ie_length);

}

char* GTPv2Message::decode_uli(uint8_t* m_data, uint32_t offset, uint32_t length, uint8_t flags)
{
	char* uli = NULL;
//@to-do append flag info in uli based on flags
	// CGI
	if (flags & GTPv2_ULI_CGI_MASK)
	{
		uli = get_mnc_mcc_str(m_data, offset);
	}
	// SAI
	if (flags & GTPv2_ULI_SAI_MASK)
	{
		uli = get_mnc_mcc_str(m_data, offset);
	}
	// RAI
	if (flags & GTPv2_ULI_RAI_MASK)
	{
		uli = get_mnc_mcc_str(m_data, offset);
	}
	// TAI
	if (flags & GTPv2_ULI_TAI_MASK)
	{
		uli = get_mnc_mcc_str(m_data, offset);
	}
	// ECGI
	if (flags & GTPv2_ULI_ECGI_MASK)
	{
		uli = get_mnc_mcc_str(m_data, offset);
	}
	// LAI
	if (flags & GTPv2_ULI_LAI_MASK)
	{
		uli = get_mnc_mcc_str(m_data, offset);
	}
	return (uli);
}

size_t GTPv2Message::get_user_location_info(uint8_t* m_data, uint32_t offset, MPacket *msgObj)
{
	size_t ie_length = 0;
	char* mcc_mnc = NULL;
	uint16_t mei_len; // = (uint16_t)*(m_data + offset);

	memcpy(&mei_len, (m_data + offset), sizeof(uint16_t));
	uint16_t mei_len_h = ntohs(mei_len);

	if (mei_len_h < 1)
		return 3;

	ie_length = mei_len_h + 3;
	uint8_t flags = (*(m_data + offset + 3)) & 0x3f;

	if (flags & GTPv2_ULI_TAI_MASK)
	{
		mcc_mnc = get_mnc_mcc_str(m_data, offset + 4);
		offset += 7; // 4 + 3 (MCC + MNC)

		int tracking_Code = VAL_USHORT(m_data + offset);
		offset += 2;
		msgObj->TAC = tracking_Code;
		strcpy(msgObj->MCCMNC, mcc_mnc);
	}

	if (flags & GTPv2_ULI_ECGI_MASK)
	{
		mcc_mnc = get_mnc_mcc_str(m_data, offset);
		offset += 4; // 4 + 3 + 1(MCC + MNC + Spare)

		int eNodeB = VAL_USHORT(m_data + offset);
		offset += 2;
		int cellId = VAL_BYTE(m_data + offset);

		msgObj->eNodeB  = eNodeB;
		msgObj->cellId = cellId;
	}

//	printf("TAI :: %s| CGI:: %s\n", msgObj->TAI, msgObj->ECGI);
	return (ie_length);
}

size_t GTPv2Message::get_serving_network_info(uint8_t* m_data, uint32_t offset, MPacket *msgObj)
{
	size_t ie_length = 0;
	char* serving_net = NULL;
	uint16_t mei_len; // = (uint16_t)*(m_data + offset);
	memcpy(&mei_len, (m_data + offset), sizeof(uint16_t));
	uint16_t mei_len_h = ntohs(mei_len);
	if (mei_len_h < 1)
		return 3;
	ie_length = mei_len_h + 3;
	serving_net = get_mnc_mcc_str(m_data, offset+3);
	strcpy(msgObj->servingNetwork, serving_net);

	if(serving_net != NULL)
	  delete serving_net;

	return (ie_length);
}

size_t GTPv2Message::get_f_tied_info(uint8_t* m_data, uint32_t offset, MPacket *msgObj)
{
	size_t ie_length = 0;
	char ipBuffer[40];
	uint16_t msg_ie_len; // = (uint16_t)*(m_data + offset);
	memcpy(&msg_ie_len, (m_data + offset), sizeof(uint16_t));
	uint16_t msg_ie_len_h = ntohs(msg_ie_len);
	if (msg_ie_len_h < 1)
		return 3;
	ie_length = msg_ie_len_h + 3;
	uint8_t flags = *(m_data + offset +3);
	offset = offset + 4;
	uint8_t ipv4, ipv6;
	ipv4 = flags & 0x80;
	ipv6 = flags & 0x40;

	uint32_t tied = 0;
	uint8_t interface_type = flags & 0x3f;

	memcpy(&tied, (m_data + offset), sizeof(uint32_t));
	ULONG tunnel_id = ntohl(tied);

	offset = offset + 4;

	if(ipv4)
	{
		unsigned int address;
		ipBuffer[0] = 0;
		address = (m_data[offset] << 24) | (m_data[offset+1] << 16) | (m_data[offset+2] << 8) | (m_data[offset+3]);
		sprintf((char *)ipBuffer,"%d.%d.%d.%d",(address & 0xFF000000) >> 24,(address & 0x00FF0000) >> 16,(address & 0x0000FF00) >> 8, address & 0x000000FF);
	}


	switch(interface_type)
	{
		case 0:		/* S1-U eNodeB GTPu */
				msgObj->eNodeB_s1u_teid = tunnel_id;
				break;

		case 1:		/* S1-U SGW GTPu */
				msgObj->SGW_s1u_teid = tunnel_id;
				strcpy(msgObj->SGWAddress, ipBuffer);
				break;

		case 4:		/* S5/S8 SGW GTP-U Interface */
				msgObj->SGW_s1u_teid = tunnel_id;
				strcpy(msgObj->SGWAddress, ipBuffer);
				break;

		case 5:		/* S5/S8 PGW GTPu Interface */
				msgObj->PGW_s1u_teid = tunnel_id;
				strcpy(msgObj->PGWAddress, ipBuffer);
				break;
		case 6:		/* S5/S8 SWG GTPc Interface */
				msgObj->SGW_ctl_teid = tunnel_id;
				strcpy(msgObj->SGWAddress, ipBuffer);
				break;

		case 7:		/* S5/S8 PGW GTPc Interface */
				msgObj->PGW_ctl_teid = tunnel_id;
				strcpy(msgObj->PGWAddress, ipBuffer);
				break;

		case 10:	/* S11 MME GTPc interface */
				msgObj->MME_ctl_teid = tunnel_id;
				strcpy(msgObj->MMEAddress, ipBuffer);
				break;

		case 11:	/* S11/S4 SGW GTPc Interface */
				msgObj->SGW_ctl_teid = tunnel_id;
				strcpy(msgObj->SGWAddress, ipBuffer);
				break;
	}

	return (ie_length);
}

size_t GTPv2Message::get_pdn_type_info(uint8_t* m_data, uint32_t offset, MPacket *msgObj)
{
	size_t ie_length = 0;
	uint16_t msg_ie_len; // = (uint16_t)*(m_data + offset);
	memcpy(&msg_ie_len, (m_data + offset), sizeof(uint16_t));
	uint16_t msg_ie_len_h = ntohs(msg_ie_len);
	if (msg_ie_len_h < 1)
		return 3;
	ie_length = msg_ie_len_h + 3;
	uint8_t flag = *(m_data + offset + 3);
	flag = flag & 0x7;
	std::string pdn_type;
	if (flag == 1)
		pdn_type = std::string("IPV4");
	if (flag == 2)
		pdn_type = std::string("IPV6");
	if (flag == 3)
		pdn_type = std::string("TPV4IPV6");

	strcpy(msgObj->pdnType, pdn_type.c_str());
	return (ie_length);
}

size_t GTPv2Message::get_bearer_context_info(uint8_t* m_data, uint32_t offset, MPacket *msgObj)
{
	size_t ie_length = 0;
	uint16_t msg_ie_len; // = (uint16_t)*(m_data + offset);
	memcpy(&msg_ie_len, (m_data + offset), sizeof(uint16_t));
	uint16_t msg_ie_len_h = ntohs(msg_ie_len);
	if (msg_ie_len_h < 1 || ((msg_ie_len_h + offset) > strlen((char*)m_data)))
		return 3;
	ie_length = msg_ie_len_h + 3;

	int message_length = (int)msg_ie_len_h;
	offset = offset + 3;

	bool flag = 0;

	while(message_length > 0)
	{
		size_t len = 0;

		uint8_t first = *(m_data + offset);	// this is the information element type

		if (!isvalid(first))
		{ return (ie_length); }
		else
		{
			offset++;

			std::map<uint32_t, pfGtpc_V2>::iterator it = GTPv2IEMap::inf_table_V2.find((uint32_t)first);

			if(it != GTPv2IEMap::inf_table_V2.end())
			{
				len = it->second(m_data, offset, msgObj);
			}
			else
			{
				uint16_t mei_len;
				memcpy(&mei_len, (const void *)m_data + offset, sizeof(uint16_t));
				uint16_t mei_len_h = ntohs(mei_len);

				if (mei_len_h < 1)
				{ len = 3; }

				len = mei_len_h + 3;
			}
		}

		offset += len;
		if ((int)len < message_length)
			message_length = message_length - len;
		else
			message_length = 0;
	}
	return (ie_length);
}

void GTPv2Message::parsePacketBody(uint8_t pFlag, size_t offset, const BYTE packet, MPacket *msgObj)
{
	if (!pFlag)
		get_IE_Info(offset, packet, msgObj);
}

void GTPv2Message::get_IE_Info(size_t offset, const BYTE packet, MPacket *msgObj)
{
	uint8_t first = 0;
	bool flag = 0;

/*
 *  msgObj->gtpcMsgLen is increased to 4 as V2 Msg Len = Actual GTPc Message - (Flag(1 Byte) + MsgType(1 Byte) + MesgLen(2 Byte))
 */
	int message_length = ((int)msgObj->gtpcMsgLen + 4 ) - offset;

	while(message_length > 0)
	{
		size_t len = 0;

		first = *(packet + offset);		// this is the information element type

		if (!GTPv2Message::isvalid(first))
		{ return; }
		else
		{
			offset++;				/* Debashis:: Increment IE Type (1 Byte) */
			message_length -= 1;	/* Debashis:: Decrement message length by 1 Byte (IE Type) */

			std::map<uint32_t, pfGtpc_V2>::iterator it = GTPv2IEMap::inf_table_V2.find((uint32_t)first);

			if(it != GTPv2IEMap::inf_table_V2.end())
			{ len = it->second((uint8_t*)packet, (uint32_t)offset, msgObj); }
			else
			{
				uint16_t mei_len;
				memcpy(&mei_len, (const void *)packet + offset, sizeof(uint16_t));
				uint16_t mei_len_h = ntohs(mei_len);

				if (mei_len_h < 1)
				{ len = 3; }

				len = mei_len_h + 3;
			}
		}
		offset += len;

		if (len < message_length)
			message_length = message_length - len;
		else
			message_length = 0;
	}
}


VOID GTPv2Message::GTPcV2_InitializeIETable()
{
	GTPv2IEMap::inf_table_V2.insert(std::pair<int, pfGtpc_V2>(GTPV2_IE_IMSI, 		&get_imsi_info));					/* 01 */
	GTPv2IEMap::inf_table_V2.insert(std::pair<int, pfGtpc_V2>(GTPV2_IE_CAUSE, 		&get_cause_info));					/* 02 */
	GTPv2IEMap::inf_table_V2.insert(std::pair<int, pfGtpc_V2>(GTPV2_REC_REST_CNT, 	&get_recovery_restr_counter));		/* 03 */
	GTPv2IEMap::inf_table_V2.insert(std::pair<int, pfGtpc_V2>(GTPV2_IE_STN_SR, 		&get_STN_SR_info));					/* 51 */
	GTPv2IEMap::inf_table_V2.insert(std::pair<int, pfGtpc_V2>(GTPV2_IE_SAI, 		&get_private_data_info));			/* 61 */
	GTPv2IEMap::inf_table_V2.insert(std::pair<int, pfGtpc_V2>(GTPV2_APN, 			&get_access_pt_name_info));			/* 71 */
	GTPv2IEMap::inf_table_V2.insert(std::pair<int, pfGtpc_V2>(GTPV2_AMBR, 			&get_ambr_info));					/* 72 */
	GTPv2IEMap::inf_table_V2.insert(std::pair<int, pfGtpc_V2>(GTPV2_IP_ADDRESS, 	&get_ip_address_info));				/* 74 */
	GTPv2IEMap::inf_table_V2.insert(std::pair<int, pfGtpc_V2>(GTPV2_MEI, 			&get_mei_info));					/* 75 */
	GTPv2IEMap::inf_table_V2.insert(std::pair<int, pfGtpc_V2>(GTPV2_IE_MSISDN, 		&get_msisdn_info));					/* 76 */
	GTPv2IEMap::inf_table_V2.insert(std::pair<int, pfGtpc_V2>(GTPV2_PAA, 			&get_pdn_access_aloc_info));		/* 79 */
	GTPv2IEMap::inf_table_V2.insert(std::pair<int, pfGtpc_V2>(GTPV2_IE_RAT_TYPE, 	&get_rat_info));					/* 82 */
	GTPv2IEMap::inf_table_V2.insert(std::pair<int, pfGtpc_V2>(GTPV2_IE_SERV_NET, 	&get_serving_network_info));		/* 83 */
	GTPv2IEMap::inf_table_V2.insert(std::pair<int, pfGtpc_V2>(GTPV2_IE_ULI, 		&get_user_location_info));			/* 86 */
	GTPv2IEMap::inf_table_V2.insert(std::pair<int, pfGtpc_V2>(GTPV2_IE_F_TEID, 		&get_f_tied_info));					/* 87 */
	GTPv2IEMap::inf_table_V2.insert(std::pair<int, pfGtpc_V2>(GTPV2_IE_BEARER_CTX, 	&get_bearer_context_info));			/* 93 */
	GTPv2IEMap::inf_table_V2.insert(std::pair<int, pfGtpc_V2>(GTPV2_IE_PDN_TYPE, 	&get_pdn_type_info));				/* 99 */
}

VOID GTPv2Message::GTPcV2_MsgTypeParser()
{
	GTPv2MsgType::GtpMsgTypeParserTable.insert(std::pair<uint16_t, pGtpcMsgFunc>(CREATE_SESSION_REQUEST,  &parsePacketBody));			/*  32 */
	GTPv2MsgType::GtpMsgTypeParserTable.insert(std::pair<uint16_t, pGtpcMsgFunc>(CREATE_SESSION_RESPONSE, &parsePacketBody));			/*  33 */
	GTPv2MsgType::GtpMsgTypeParserTable.insert(std::pair<uint16_t, pGtpcMsgFunc>(MODIFY_BEARER_REQUEST,   &parsePacketBody));			/*  34 */
	GTPv2MsgType::GtpMsgTypeParserTable.insert(std::pair<uint16_t, pGtpcMsgFunc>(MODIFY_BEARER_RESPONSE,  &parsePacketBody));			/*  35 */
	GTPv2MsgType::GtpMsgTypeParserTable.insert(std::pair<uint16_t, pGtpcMsgFunc>(DELETE_SESSION_REQUEST,  &parsePacketBody));			/*  36 */
	GTPv2MsgType::GtpMsgTypeParserTable.insert(std::pair<uint16_t, pGtpcMsgFunc>(DELETE_SESSION_RESPONSE, &parsePacketBody));			/*  37 */
	GTPv2MsgType::GtpMsgTypeParserTable.insert(std::pair<uint16_t, pGtpcMsgFunc>(DOWNLINK_DATA_NOTIFI_INDI, &parsePacketBody));			/*  70 */
	GTPv2MsgType::GtpMsgTypeParserTable.insert(std::pair<uint16_t, pGtpcMsgFunc>(CREATE_BEARER_REQUEST,   &parsePacketBody));			/*  95 */
	GTPv2MsgType::GtpMsgTypeParserTable.insert(std::pair<uint16_t, pGtpcMsgFunc>(CREATE_BEARER_RESPONSE,  &parsePacketBody));			/*  96 */
	GTPv2MsgType::GtpMsgTypeParserTable.insert(std::pair<uint16_t, pGtpcMsgFunc>(UPDATE_BEARER_REQUEST,   &parsePacketBody));			/*  97 */	/* S5/S8 */
	GTPv2MsgType::GtpMsgTypeParserTable.insert(std::pair<uint16_t, pGtpcMsgFunc>(UPDATE_BEARER_RESPONSE,  &parsePacketBody));			/*  98 */	/* S5/S8 */
	GTPv2MsgType::GtpMsgTypeParserTable.insert(std::pair<uint16_t, pGtpcMsgFunc>(DELETE_BEARER_REQUEST,   &parsePacketBody));			/*  99 */
	GTPv2MsgType::GtpMsgTypeParserTable.insert(std::pair<uint16_t, pGtpcMsgFunc>(DELETE_BEARER_RESPONSE,  &parsePacketBody));			/* 100 */
	GTPv2MsgType::GtpMsgTypeParserTable.insert(std::pair<uint16_t, pGtpcMsgFunc>(RELEASED_ACCESS_BEARER_REQUEST,   &parsePacketBody));/* 170 */
	GTPv2MsgType::GtpMsgTypeParserTable.insert(std::pair<uint16_t, pGtpcMsgFunc>(RELEASED_ACCESS_BEARER_RESPONSE,  &parsePacketBody));/* 171 */
	GTPv2MsgType::GtpMsgTypeParserTable.insert(std::pair<uint16_t, pGtpcMsgFunc>(DOWNLINK_DATA_NOTIFICATION,   		&parsePacketBody));/* 176 */
	GTPv2MsgType::GtpMsgTypeParserTable.insert(std::pair<uint16_t, pGtpcMsgFunc>(DOWNLINK_DATA_ACK,  				&parsePacketBody));/* 177 */
	GTPv2MsgType::GtpMsgTypeParserTable.insert(std::pair<uint16_t, pGtpcMsgFunc>(MODIFY_ACCESS_BEARER_REQUEST,   &parsePacketBody));	/* 211 */
	GTPv2MsgType::GtpMsgTypeParserTable.insert(std::pair<uint16_t, pGtpcMsgFunc>(MODIFY_ACCESS_BEARER_RESPONSE,  &parsePacketBody));	/* 212 */
}



