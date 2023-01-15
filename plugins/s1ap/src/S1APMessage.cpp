/*
 * S1APMessage.cpp
 *
 *  Created on: 8 Jan 2020
 *      Author: Debashis
 */

#include "S1APMessage.h"


S1APMessage::S1APMessage()
{ }

S1APMessage::~S1APMessage()
{ }


char* S1APMessage::get_mnc_mcc_str(void* m_data, uint32_t offset)
{
	uint8_t* p = (uint8_t*) m_data;

	int mcc_mnc;
	uint8_t octet;
	uint16_t mcc, mnc;
	mcc = mnc = 0;

	uint8_t mcc1, mcc2, mcc3, mnc1, mnc2, mnc3;
	bool long_mnc;

	/* MCC + MNC */
	memcpy(&mcc_mnc, (p + offset), sizeof(uint8_t)*3);

	/* Mobile country code MCC */
	octet = (uint8_t)*(p + offset);
	mcc1 = octet & 0x0f;
	mcc2 = octet >> 4;
	offset++;

	octet = (uint8_t)*(p + offset);
	mcc3 = octet & 0x0f;

	/* MNC, Mobile network code (octet 3 bits 5 to 8, octet 4) */
	mnc3 = octet >> 4;
	offset++;
	octet = (uint8_t)*(p + offset);
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

VOID S1APMessage::get_OSSbuffer(const void* pv, int len, unsigned char *buffer)
{
	char x[2];
	buffer[0] = 0;

	const unsigned char* p = (const unsigned char*) pv;
	int i;
	for(i = 0; i < len; ++i )
	{
		x[0] = 0;
		sprintf(x, "%02x", (unsigned)p[i]);
		strcat((char *)buffer, x);
	}
}

VOID S1APMessage::get_OSSByteBuffer(const void* pv, int len, unsigned char *buffer)
{
	char x[2];
	buffer[0] = 0;

	const unsigned char* p = (const unsigned char*) pv;
	int i;
	for(i = 0; i < len; ++i )
	{
		x[0] = 0;
		sprintf(x, "%02x", (unsigned int)p[i]);
		strcat((char *)buffer, x);
	}
}

VOID S1APMessage::hexDump(const void* pv, int len)
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


VOID S1APMessage::decode_NAS_PDU(void *pBuffer, MPacket *msgObj, uint16_t index)
{
	uint16_t len = 0;
	uint16_t msgType = 0;
	const unsigned char	*pv;
	int header, sht, pd;	/* sht - Security Header Type, pd - Protocol Discriminator */
	uint16_t offset;

	pv = (const unsigned char*) pBuffer;
	offset = 0;

	header = VAL_BYTE(pv + offset);
	sht = header >> 4;
	pd = header & 0x0F;

	switch(sht)
	{
		case PLAN_NAS_MSG:		/* Plan NAS Message */
				switch(pd)
				{
					case EPS_MOBILITY_MGR_MSG:
						offset += 1;
						msgType = VAL_BYTE(pv + offset);

						 // printf("  ** NAS EPS-MMM:: %s\n", S1APInitialize::s1ap_nasMobilityMgrMsg[msgType].c_str());

						switch(msgType)
						{
							case AttachRequest: 			/* (0x41) */
								msgObj->SctpData[index].nas_EPSMobilityMgrMsgType = msgType;
								msgObj->SctpData[index].nas_MMM_Present = true;
								offset += 2;
								get_AttachRequestData(pBuffer, offset, msgObj, index);
								break;

							case AttachReject:				/* (0x44) */
								msgObj->SctpData[index].nas_EPSMobilityMgrMsgType = msgType;
								msgObj->SctpData[index].nas_MMM_Present = true;
								offset += 1;
								msgObj->SctpData[index].s1ap_rejectCause = VAL_BYTE(pv + offset);
								break;

							case AuthenticationRequest:		/* (0x52) */
								msgObj->SctpData[index].nas_EPSMobilityMgrMsgType = msgType;
								msgObj->SctpData[index].nas_MMM_Present = true;
								offset += 1;
								break;

							case AuthenticationResponse:	/* (0x53) */
								msgObj->SctpData[index].nas_EPSMobilityMgrMsgType = msgType;
								msgObj->SctpData[index].nas_MMM_Present = true;
								offset += 1;
								break;

							case AuthenticationReject:		/* (0x54) */
								msgObj->SctpData[index].nas_EPSMobilityMgrMsgType = msgType;
								msgObj->SctpData[index].nas_MMM_Present = true;
								offset += 1;
								msgObj->SctpData[index].s1ap_rejectCause = VAL_BYTE(pv + offset);
								break;

							case IdentityRequest:		/* (0x55) */
								msgObj->SctpData[index].nas_EPSMobilityMgrMsgType = msgType;
								msgObj->SctpData[index].nas_MMM_Present = true;
								offset += 1;
								break;

							case IdentityResponse:		/* (0x56) */
								msgObj->SctpData[index].nas_EPSMobilityMgrMsgType = msgType;
								msgObj->SctpData[index].nas_MMM_Present = true;
								offset += 1;
								len = get_EPSMobileIdentity(pBuffer, offset, msgObj, index);
								offset += (len + 1);
								break;

							case AuthenticationFailure:		/* (0x5c) */
								msgObj->SctpData[index].nas_EPSMobilityMgrMsgType = msgType;
								msgObj->SctpData[index].nas_MMM_Present = true;
								offset += 1;
								msgObj->SctpData[index].s1ap_failureCause = VAL_BYTE(pv + offset);
								offset += 1;
								break;
						}
						break;
				}
				break;

		case INTEGRITY_PROTECTED:								/* Integrity Protected */
		case INTEGRITY_PROTECTED_CIPHERED:						/* Integrity protected and ciphered */
		case INTEGRITY_PROTECTED_EPS_SECURITY_CONTEXT:			/* Integrity protected with new EPS security context */
		case INTEGRITY_PROTECTED_CIPHERED_EPS_SECURITY_CONTEXT:	/* Integrity protected and ciphered with new EPS security context */
		case RESERVED_10:
		case RESERCED_11:
				offset += 6;
				header = VAL_BYTE(pv + offset);
				sht = header >> 4;
				pd = header & 0x0F;

				switch(pd)
				{
					case EPS_SESSION_MGR_MSG:
							offset += 2;
							msgType = VAL_BYTE(pv + offset);
							msgObj->SctpData[index].nas_ESMSessionMgrMsgType = msgType;
							msgObj->SctpData[index].nas_SMM_Present = true;
							 // printf("  ** NAS EPS-SMM:: %s\n", S1APInitialize::s1ap_nasSessionMgrMsg[msgType].c_str());
							break;

					case EPS_MOBILITY_MGR_MSG:
							offset += 1;
							msgType = VAL_BYTE(pv + offset);
							// printf("  ** NAS EPS-MMM:: %s\n", S1APInitialize::s1ap_nasMobilityMgrMsg[msgType].c_str());

							switch(msgType)
							{
								case AttachAccept: 					/* (0x42) */
									msgObj->SctpData[index].nas_EPSMobilityMgrMsgType = msgType;
									msgObj->SctpData[index].nas_MMM_Present = true;
									offset += 1;			// Increase EPSMobilityManagementMsgType (1 Byte)
									get_AttachAcceptData(pBuffer, offset, msgObj, index);
									break;

								case AttachComplete:				/* (0x43) */
									msgObj->SctpData[index].nas_EPSMobilityMgrMsgType = msgType;
									msgObj->SctpData[index].nas_MMM_Present = true;
									offset += 1;
									get_AttachCompleteData(pBuffer, offset, msgObj, index);
									break;

								case DetachRequest:					/* (0x45) */
									msgObj->SctpData[index].nas_EPSMobilityMgrMsgType = msgType;
									msgObj->SctpData[index].nas_MMM_Present = true;
									offset += 1;
									get_DetachRequestData(pBuffer, offset, msgObj, index);
									break;

								case DetachAccept:					/* (0x46) */
									msgObj->SctpData[index].nas_EPSMobilityMgrMsgType = msgType;
									msgObj->SctpData[index].nas_MMM_Present = true;
									offset += 1;
									break;

								case TrackingAreaUpdateRequest:		/* (0x48) */
									msgObj->SctpData[index].nas_EPSMobilityMgrMsgType = msgType;
									msgObj->SctpData[index].nas_MMM_Present = true;
									offset += 1;
									get_TrackingAreaUpdateRequestData(pBuffer, offset, msgObj, index);
									break;

								case TrackingAreaUpdateAccept:		/* (0x49) */
									msgObj->SctpData[index].nas_EPSMobilityMgrMsgType = msgType;
									msgObj->SctpData[index].nas_MMM_Present = true;
									offset += 1;
									get_TrackingAreaUpdateAcceptData(pBuffer, offset, msgObj, index);
									break;

								case TrackingAreaUpdateComplete:	/* (0x4a) */
									msgObj->SctpData[index].nas_EPSMobilityMgrMsgType = msgType;
									msgObj->SctpData[index].nas_MMM_Present = true;
									offset += 1;
									break;

								case TrackingAreaUpdateReject:		/* (0x4b) */
									msgObj->SctpData[index].nas_EPSMobilityMgrMsgType = msgType;
									msgObj->SctpData[index].nas_MMM_Present = true;
									offset += 1;
									msgObj->SctpData[index].s1ap_rejectCause = VAL_BYTE(pv + offset);
									break;

								case ExtendedServiceRequest:		/* (0x4c) */
									msgObj->SctpData[index].nas_EPSMobilityMgrMsgType = msgType;
									msgObj->SctpData[index].nas_MMM_Present = true;
									offset += 1;
									break;

								case SecurityModeCommand:			/* (0x5d) */
									msgObj->SctpData[index].nas_EPSMobilityMgrMsgType = msgType;
									msgObj->SctpData[index].nas_MMM_Present = true;
									offset += 1;
									break;

								case SecurityModeComplete:			/* (0x5e) */
									msgObj->SctpData[index].nas_EPSMobilityMgrMsgType = msgType;
									msgObj->SctpData[index].nas_MMM_Present = true;
									offset += 1;
									get_IMEISV(pBuffer, offset, msgObj, index);
									break;

								case SecurityModeReject:			/* (0x5f) */
									msgObj->SctpData[index].nas_EPSMobilityMgrMsgType = msgType;
									msgObj->SctpData[index].nas_MMM_Present = true;
									offset += 1;
									msgObj->SctpData[index].s1ap_rejectCause = VAL_BYTE(pv + offset);
									break;
							}
							break;
				}
				break;

		case 12:	/* Security Header for SERVICE REQUEST */
			// printf("  ** NAS Service :: %s\n", S1APInitialize::s1ap_nasMobilityMgrMsg[12].c_str());
			msgObj->SctpData[index].nas_EPSMobilityMgrMsgType = 12;
			msgObj->SctpData[index].nas_MMM_Present = true;
			break;
	}
}

VOID S1APMessage::get_IMEISV(void *pBuffer, uint16_t offset, MPacket *msgObj, uint16_t index)
{
	const unsigned char	*pv = (const unsigned char*) pBuffer;
	char* imei = NULL;

	uint16_t elementID = VAL_BYTE(pv + offset);
	offset += 1;
	uint16_t length = VAL_BYTE(pv + offset);
	offset += 1;

	imei = get_IMEI((uint8_t*)pBuffer, offset, length);
	memcpy(msgObj->SctpData[index].s1ap_imei, imei, strlen(imei));
	msgObj->SctpData[index].s1ap_imeiPresent = true;
//	printf("  ** IMEI:: %s\n", msgObj->SctpData[index].s1ap_imei);
	delete[] imei;
}

VOID S1APMessage::get_AttachRequestData(void *pBuffer, uint16_t offset, MPacket *msgObj, uint16_t index)
{
	bool pdnFlag = false;
	uint16_t len = S1APMessage::get_EPSMobileIdentity(pBuffer, offset, msgObj, index);
	offset += (len + 1);

	len = get_UENetworkCapability(pBuffer, offset, msgObj, index);
	offset += (len + 1);

	len = S1APMessage::get_EMSMsgContainer(pBuffer, offset, msgObj, pdnFlag, index);
}

VOID S1APMessage::get_AttachAcceptData(void *pBuffer, uint16_t offset, MPacket *msgObj, uint16_t index)
{
	bool pdnFlag = true;
	const unsigned char	*pv = (const unsigned char*) pBuffer;

	offset += 2;										// Attach result (1 byte) + GPRS Timer (1 Byte)
	uint16_t taiLen = VAL_BYTE(pv + offset); 			// Get the Length of TAI
	offset += 1;										// Increase taiLen (1 byte)
	offset += taiLen;									// EMS Message Container

	uint16_t len = S1APMessage::get_EMSMsgContainer(pBuffer, offset, msgObj, pdnFlag, index);
	offset += (len + 2);								// Increase EMS Message Container Length (2 Bytes)

	uint16_t elementId = VAL_BYTE(pv + offset);
	offset += 1;

	len = S1APMessage::get_EPSMobileIdentity(pBuffer, offset, msgObj, index);
}

VOID S1APMessage::get_AttachCompleteData(void *pBuffer, uint16_t offset, MPacket *msgObj, uint16_t index)
{
	bool pdnFlag = false;
	uint16_t len = get_EMSMsgContainer(pBuffer, offset, msgObj, pdnFlag, index);
	offset += (len + 2);
}

VOID S1APMessage::get_DetachRequestData(void *pBuffer, uint16_t offset, MPacket *msgObj, uint16_t index)
{
	offset += 1;
	uint16_t len = S1APMessage::get_EPSMobileIdentity(pBuffer, offset, msgObj, index);
	offset += (len + 1);
}

VOID S1APMessage::get_TrackingAreaUpdateRequestData(void *pBuffer, uint16_t offset, MPacket *msgObj, uint16_t index)
{
	offset += 1;		// Native Security Context
	uint16_t len = get_EPSMobileIdentity(pBuffer, offset, msgObj, index);
	offset += (len + 1);
}

VOID S1APMessage::get_TrackingAreaUpdateAcceptData(void *pBuffer, uint16_t offset, MPacket *msgObj, uint16_t index)
{
	offset += 4;		// TA Update (1 byte) + GPRS Timer (2 byte)+ Element ID (1 byte)
	uint16_t len = get_EPSMobileIdentity(pBuffer, offset, msgObj, index);
	offset += (len + 1);
}

VOID S1APMessage::get_IPAddress(const void* pv, int len, unsigned char *buffer)
{
	const unsigned char* p = (const unsigned char*) pv;
	buffer[0] = 0;

	sprintf((char *)buffer, "%u.%u.%u.%u", (unsigned)p[0], (unsigned)p[1], (unsigned)p[2], (unsigned)p[3]);
}

VOID S1APMessage::get_RubToBeSetupRequest(E_RABSetupRequestIEs_Value & iedata, MPacket *msgObj, uint16_t index)
{
	unsigned char buffer[10];
	E_RABToBeSetupListBearerSUReq *setupReq = iedata.get_E_RABToBeSetupListBearerSUReq();
	E_RABToBeSetupListBearerSUReq::component *ie;

	for (OssIndex i = setupReq->first(); i != OSS_NOINDEX; i = setupReq->next(i))
	{
		ie = setupReq->at(i);
		E_RABToBeSetupItemBearerSUReqIEs_Value &data = ie->get_value();

		if(data.has_decoded())
		{
			switch (ie->get_id())
			{
				case id_E_RABToBeSetupItemBearerSUReq:
				{
					E_RABToBeSetupItemBearerSUReq *inner1 = data.get_E_RABToBeSetupItemBearerSUReq();
					msgObj->SctpData[index].s1ap_rabId = inner1->get_e_RAB_ID();
					S1APMessage::get_OSSbuffer(inner1->get_gTP_TEID().get_buffer(), inner1->get_gTP_TEID().length(), buffer);
			 	 }
			 	 break;
			 }
		 }
	 }
}

uint16_t S1APMessage::get_UENetworkCapability(void *pBuffer, uint16_t offset, MPacket *msgObj, uint16_t index)
{
	const unsigned char	*pv = (const unsigned char*) pBuffer;

	return (VAL_BYTE(pv + offset));	// Return UE Network Capability Length
}

uint16_t S1APMessage::get_EPSMobileIdentity(void *pBuffer, uint16_t offset, MPacket *msgObj, uint16_t index)
{
	unsigned char buffer[10];
	const unsigned char	*pv = (const unsigned char*) pBuffer;

	uint16_t epsMobileIdentityLen = VAL_BYTE(pv + offset);
	offset += 1;

	int header =  VAL_BYTE(pv + offset);
	int pd = header & 0x07;
	char* imsi = NULL;

	switch(pd)
	{
		case 1:	// IMSI
		{
			imsi = NULL;
			imsi = get_IMSI((uint8_t*)pBuffer, offset, epsMobileIdentityLen);
			memcpy(msgObj->SctpData[index].s1ap_imsi, imsi+1,strlen(imsi));
			msgObj->SctpData[index].s1ap_imsiPresent = true;
//			printf("  ** IMSI:: %s\n", msgObj->SctpData[index].s1ap_imsi);
			free(imsi);
		}
		break;

		case 4: // TMSI/ P_TMSI Type (1 byte)
		{
			offset += 1;
			S1APMessage::get_OSSbuffer((pv + offset), 4, buffer);
			strcpy(msgObj->SctpData[index].s1ap_m_tmsi, (const char *)buffer);
			msgObj->SctpData[index].s1ap_m_tmsi_Present = true;
			// printf("  ** TMSI/P_TMSI:: %s\n", msgObj->SctpData[index].s1ap_m_tmsi);
		}
		break;

		case 6:	// GUTI (In this case it will have Type (1 byte) + (MCC + MNC) (3 byte) + MME Group Id (2 byte) + MME Code (1 byte)
		{
			offset += 7;
			S1APMessage::get_OSSbuffer((pv + offset), 4, buffer);
			strcpy(msgObj->SctpData[index].s1ap_m_tmsi, (const char *)buffer);
			msgObj->SctpData[index].s1ap_m_tmsi_Present = true;
			// printf("  ** M_TMSI:: %s\n", msgObj->SctpData[index].s1ap_m_tmsi);
		}
		break;
	}
	return epsMobileIdentityLen;
}

uint16_t S1APMessage::get_EMSMsgContainer(void *pBuffer, uint16_t offset, MPacket *msgObj, bool flag, uint16_t index)
{
	unsigned char buffer[10];
	const unsigned char	*pv = (const unsigned char*) pBuffer;

	uint16_t emsMsgContainerLen = VAL_USHORT(pv + offset); 	// Get the Length of EMS Message Container

	offset += 2;										// Increase EMS Message Container Length (2 Bytes)

	int header = VAL_BYTE(pv + offset);
	int sht = header >> 4;
	int pd = header & 0x0F;
	offset += 2;										// Increase Identity (2 Bytes)

	if(pd != EPS_SESSION_MGR_MSG) return emsMsgContainerLen;

	msgObj->SctpData[index].nas_ESMMsgContainerMsgType = VAL_BYTE(pv + offset);
	msgObj->SctpData[index].nas_ESMMsgContainerMsg_Present = true;
	offset += 1;

	// printf("  ** NAS EPS-SMM:: %s\n", S1APInitialize::s1ap_nasSessionMgrMsg[msgObj->SctpData[index].nas_ESMSessionMgrMsgType].c_str());

	if(!flag) return emsMsgContainerLen;				// Return If No PDP Address decoding required

	uint16_t epsLen = VAL_BYTE(pv + offset); 				// Get the Length of EPS Quality of Service
	offset += 1;
	offset += epsLen;

	uint16_t apnLen = VAL_BYTE(pv + offset); 				// Get the Length of APN
	offset += 1;

	char* apn = get_APN((uint8_t*)(pBuffer + offset), apnLen);
	memcpy(msgObj->SctpData[index].s1ap_apn, apn+1,strlen(apn));
	// printf("  ** A P N :: %s\n", msgObj->SctpData[index].s1ap_apn);

	offset += apnLen;

	int pdnLen = VAL_BYTE(pv + offset); 				// Get the Length of PDN
	offset += 1;
	int pdnType = VAL_BYTE(pv + offset); 				// Get PDN type
	offset += 1;

	switch(pdnType)
	{
		case 1:	/* IPv4 */
			msgObj->SctpData[index].s1ap_pdnAddrType = pdnType;
			S1APMessage::get_IPAddress((pv + offset), 4, buffer);
			strcpy(msgObj->SctpData[index].s1ap_pdnAddr, (char*)buffer);
			offset += 4;	// Increase PDN Value
//			 printf("  ** P D N :: %s\n", msgObj->SctpData[index].s1ap_pdnAddr);
			break;
	}

	/* Transaction indentifier */

	uint16_t eId;

	while(offset <= (offset + emsMsgContainerLen))
	{
		eId = VAL_BYTE(pv + offset);

		if(eId == 94)	/* APN Aggregate Maximum Bit Rate */
		{
			offset += 2;
			msgObj->SctpData[index].s1ap_apnMbrDown = 34.01 * VAL_BYTE(pv + offset);
			offset += 1;
			msgObj->SctpData[index].s1ap_apnMbrUp = 34.01 * VAL_BYTE(pv + offset);
			break;
		}
		offset++;
	}
	return emsMsgContainerLen;
}

char* S1APMessage::get_APN(uint8_t *m_data, uint16_t length)
{
	 char* str = NULL;
//	 new uint8_t[MAX_APN_LENGTH+1];
	 str = (char *)malloc(MAX_APN_LENGTH+1);
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

char* S1APMessage::get_IMEI(uint8_t* m_data, uint32_t offset, uint32_t e_usr_addr_ln)
{
	uint16_t mei_len; // = (uint16_t)*(m_data + offset);
	uint8_t octet;
	int iCount = 0;

//	memcpy(&mei_len, (m_data + offset), sizeof(uint16_t));
	uint16_t mei_len_h = e_usr_addr_ln;

	if (mei_len_h < 1)
		return NULL;

	char* mei = NULL;

	const uint8_t out[16] = {'0','1','2','3','4','5','6','7','8','9','?','?','?','?','?','?'};
	uint32_t t_offset = 0;

	mei_len = e_usr_addr_ln;
	mei = (char *)malloc(((size_t)mei_len)*2+1);

	while (mei_len > t_offset)
	{
		octet = *(m_data + offset);
		offset++;
		mei[iCount] = out[octet & 0x0f];
		iCount++;

		octet = octet >> 4;
		if (octet == 0x0f)
		{
			break;	/* odd number bytes - hit filler */
		}

		mei[iCount] = out[octet & 0x0f];
		iCount++;
		t_offset++;
	}
	mei[iCount]= '\0';

//	if (mei != NULL)
//		delete[] mei;

	return (mei);
}

char* S1APMessage::get_IMSI(uint8_t* m_data, uint32_t offset, uint32_t e_usr_addr_ln)
{
	uint32_t length = 0;
	uint8_t octet;
	int iCount = 0;
	char *imsi_str = NULL;

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

VOID S1APMessage::fn_HandoverPreparation(InitiatingMessage *initmsg, MPacket *msgObj, uint16_t index)					/* 00  ** Completed */
{
	unsigned char buffer[200];
	HandoverRequired *handOver = initmsg->get_value().get_HandoverRequired();
	HandoverRequired::protocolIEs::component *ie;

	for (OssIndex i = handOver->get_protocolIEs().first(); i != OSS_NOINDEX; i = handOver->get_protocolIEs().next(i))
	{
		ie = handOver->get_protocolIEs().at(i);
		HandoverRequiredIEs_Value & iedata = ie->get_value();

		if(iedata.has_decoded())
		{
			switch (ie->get_id())
			{
				case id_MME_UE_S1AP_ID:
				{
					MME_UE_S1AP_ID 	*mmeId = iedata.get_MME_UE_S1AP_ID();
					msgObj->SctpData[index].s1ap_mmeId = *mmeId;
				}
				break;

				case id_eNB_UE_S1AP_ID:
				{
					ENB_UE_S1AP_ID *eNodeBId = iedata.get_ENB_UE_S1AP_ID();
					msgObj->SctpData[index].s1ap_eNodeBId = *eNodeBId;
				}
				break;

				case id_HandoverType:
				{
					HandoverType *type = iedata.get_HandoverType();
					msgObj->SctpData[index].s1ap_handoverType = *type;
				}
				break;

				case id_Cause:
				{
				    Cause *cause;
				    CauseRadioNetwork *cause_rnw;
				    CauseTransport *cause_trans;
				    CauseNas *cause_nas;
				    CauseProtocol *cause_proto;
				    CauseMisc *cause_misc;

				    cause = iedata.get_Cause();
				    int16_t	causeType = cause->get_selection();

				    switch(causeType)
				    {
			    	case 1:
			    		cause_rnw = cause->get_radioNetwork();
			    		msgObj->SctpData[index].s1ap_causeType = causeType;
			    		msgObj->SctpData[index].s1ap_causeId = *cause_rnw;
			    		break;

			    	case 2:
			    		cause_trans = cause->get_transport();
			    		msgObj->SctpData[index].s1ap_causeType = causeType;
			    		msgObj->SctpData[index].s1ap_causeId = *cause_trans;
			    		break;

			    	case 3:
			    		cause_nas = cause->get_nas();
			    		msgObj->SctpData[index].s1ap_causeType = causeType;
			    		msgObj->SctpData[index].s1ap_causeId = *cause_nas;
			    		break;

			    	case 4:
			    		cause_proto = cause->get_protocol();
			    		msgObj->SctpData[index].s1ap_causeType = causeType;
			    		msgObj->SctpData[index].s1ap_causeId = *cause_proto;
			    		break;

			    	case 5:
			    		cause_misc = cause->get_misc();
			    		msgObj->SctpData[index].s1ap_causeType = causeType;
			    		msgObj->SctpData[index].s1ap_causeId = *cause_misc;
			    		break;

			    	default:
			    		msgObj->SctpData[index].s1ap_causeType = -1;
			    		msgObj->SctpData[index].s1ap_causeId = -1;
			    		break;
				    }
				    // printf("  ** Cause : %d\n", msgObj->SctpData[index].s1ap_causeId);
				}
				break;

				case id_Source_ToTarget_TransparentContainer:
				{
					Source_ToTarget_TransparentContainer *target = iedata.get_Source_ToTarget_TransparentContainer();
					S1APMessage::decode_targetSource(target->get_buffer(), msgObj, index);
				}
				break;

			}
		}
	}
}

VOID S1APMessage::decode_targetSource(void *pBuffer, MPacket *msgObj, uint16_t index)
{
		const unsigned char	*pv;
		uint16_t offset, len;
		char plmn[10];
		char cellId[20];
		unsigned char buffer[10];

		pv = (const unsigned char*) pBuffer;

		len = VAL_BYTE(pv + 2);

		offset = len + 11;

		strcpy(msgObj->SctpData[index].s1ap_targetpLMNIdentity, (char*)S1APMessage::get_mnc_mcc_str((void *)(pv + offset), 0));
		offset += 3;

		S1APMessage::get_OSSByteBuffer((void *)(pv + offset), 4, buffer);
		msgObj->SctpData[index].s1ap_targetCellId[0] = 0;

		strncat(msgObj->SctpData[index].s1ap_targetCellId, (char*)buffer, strlen((char *)buffer)-1);

		offset += 5;

		strcpy(msgObj->SctpData[index].s1ap_lastVisitedpLMNIdentity, (char*)S1APMessage::get_mnc_mcc_str((void *)(pv + offset), 0));
		offset += 3;

		S1APMessage::get_OSSByteBuffer((void *)(pv + offset), 4, buffer);
		msgObj->SctpData[index].s1ap_lastVisitedCellId[0] = 0;
		strncat(msgObj->SctpData[index].s1ap_lastVisitedCellId, (char*)buffer, strlen((char *)buffer)-1);
}

VOID S1APMessage::fn_HandoverRequest(InitiatingMessage *initmsg, MPacket *msgObj, uint16_t index)						/* 01  ** Completed */
{
	HandoverRequest *handReq = initmsg->get_value().get_HandoverRequest();
	HandoverRequest::protocolIEs::component *ie;

	for (OssIndex i = handReq->get_protocolIEs().first(); i != OSS_NOINDEX; i = handReq->get_protocolIEs().next(i))
	{
		ie = handReq->get_protocolIEs().at(i);
		HandoverRequestIEs_Value & iedata = ie->get_value();

		if(iedata.has_decoded())
		{
			switch (ie->get_id())
			{
				case id_MME_UE_S1AP_ID:
				{
					MME_UE_S1AP_ID 	*mmeId = iedata.get_MME_UE_S1AP_ID();
					msgObj->SctpData[index].s1ap_mmeId = *mmeId;
					// printf("  ** MME_UE_S1AP_ID : %u\n", msgObj->SctpData[index].s1ap_mmeId);
				}
				break;

				case id_HandoverType:
				{
					HandoverType *type = iedata.get_HandoverType();
					msgObj->SctpData[index].s1ap_handoverType = *type;
					// printf("  ** Handover Type: %d\n", *type);
				}
				break;

				case id_Cause:
				{
				    Cause *cause;
				    CauseRadioNetwork *cause_rnw;
				    CauseTransport *cause_trans;
				    CauseNas *cause_nas;
				    CauseProtocol *cause_proto;
				    CauseMisc *cause_misc;

				    cause = iedata.get_Cause();
				    int16_t	causeType = cause->get_selection();

				    switch(causeType)
				    {
			    	case 1:
			    		cause_rnw = cause->get_radioNetwork();
			    		msgObj->SctpData[index].s1ap_causeType = causeType;
			    		msgObj->SctpData[index].s1ap_causeId = *cause_rnw;
			    		break;

			    	case 2:
			    		cause_trans = cause->get_transport();
			    		msgObj->SctpData[index].s1ap_causeType = causeType;
			    		msgObj->SctpData[index].s1ap_causeId = *cause_trans;
			    		break;

			    	case 3:
			    		cause_nas = cause->get_nas();
			    		msgObj->SctpData[index].s1ap_causeType = causeType;
			    		msgObj->SctpData[index].s1ap_causeId = *cause_nas;
			    		break;

			    	case 4:
			    		cause_proto = cause->get_protocol();
			    		msgObj->SctpData[index].s1ap_causeType = causeType;
			    		msgObj->SctpData[index].s1ap_causeId = *cause_proto;
			    		break;

			    	case 5:
			    		cause_misc = cause->get_misc();
			    		msgObj->SctpData[index].s1ap_causeType = causeType;
			    		msgObj->SctpData[index].s1ap_causeId = *cause_misc;
			    		break;

			    	default:
			    		msgObj->SctpData[index].s1ap_causeType = -1;
			    		msgObj->SctpData[index].s1ap_causeId = -1;
			    		break;
				    }
				    // printf("  ** Cause : %d\n", msgObj->SctpData[index].s1ap_causeId);
				}
				break;
			}
		}
	}
}

VOID S1APMessage::fn_HandoverNotification(InitiatingMessage *initmsg, MPacket *msgObj, uint16_t index)					/* 02  ** Completed */
{
	unsigned char buffer[10];
	HandoverNotify *notification = initmsg->get_value().get_HandoverNotify();
	HandoverNotify::protocolIEs::component *ie;

	for (OssIndex i = notification->get_protocolIEs().first(); i != OSS_NOINDEX; i = notification->get_protocolIEs().next(i))
	{
		ie = notification->get_protocolIEs().at(i);
		HandoverNotifyIEs_Value &iedata = ie->get_value();

		if(iedata.has_decoded())
		{
			switch (ie->get_id())
			{
				case id_MME_UE_S1AP_ID:
				{
					MME_UE_S1AP_ID 	*mmeId = iedata.get_MME_UE_S1AP_ID();
					msgObj->SctpData[index].s1ap_mmeId = *mmeId;
				}
				break;

				case id_eNB_UE_S1AP_ID:
				{
					ENB_UE_S1AP_ID *eNodeBId = iedata.get_ENB_UE_S1AP_ID();
					msgObj->SctpData[index].s1ap_eNodeBId = *eNodeBId;
					// printf("  ** MME_UE_S1AP_ID : %u| eNodeB_UE_S1AP_ID : %u\n", msgObj->SctpData[index].s1ap_mmeId, msgObj->SctpData[index].s1ap_eNodeBId);
				}
				break;

				case id_EUTRAN_CGI:
				{
					EUTRAN_CGI *cgi = iedata.get_EUTRAN_CGI();
					strcpy(msgObj->SctpData[index].s1ap_pLMNIdentity, (char*)S1APMessage::get_mnc_mcc_str(cgi->get_pLMNidentity().get_buffer(), 0));

					S1APMessage::get_OSSByteBuffer(cgi->get_cell_ID().get_buffer(), 4, buffer);
					strncat(msgObj->SctpData[index].s1ap_cellId, (char*)buffer, strlen((char *)buffer)-1);
				}
				break;

				case id_TAI:
				{
					TAI *tai = iedata.get_TAI();
					S1APMessage::get_OSSbuffer(tai->get_tAC().get_buffer(), tai->get_tAC().length(), buffer);
					strcpy(msgObj->SctpData[index].s1ap_tac, (char*)buffer);
				}
				break;
			}
		}
	}
}

VOID S1APMessage::fn_HandoverCancel(InitiatingMessage *initmsg, MPacket *msgObj, uint16_t index)
{
	__shared14 *hoCancel = initmsg->get_value().get_HandoverCancel();
	__shared14::protocolIEs::component *ie;

	for (OssIndex i = hoCancel->get_protocolIEs().first(); i != OSS_NOINDEX; i = hoCancel->get_protocolIEs().next(i))
	{
		ie = hoCancel->get_protocolIEs().at(i);
		HandoverCancelIEs_Value &iedata = ie->get_value();

		if(iedata.has_decoded())
		{
			switch (ie->get_id())
			{
				case id_MME_UE_S1AP_ID:
				{
					MME_UE_S1AP_ID 	*mmeId = iedata.get_MME_UE_S1AP_ID();
					msgObj->SctpData[index].s1ap_mmeId = *mmeId;
				}
				break;

				case id_eNB_UE_S1AP_ID:
				{
					ENB_UE_S1AP_ID *eNodeBId = iedata.get_ENB_UE_S1AP_ID();
					msgObj->SctpData[index].s1ap_eNodeBId = *eNodeBId;
				}
				break;

				case id_Cause:
				{
				    Cause *cause;
				    CauseRadioNetwork *cause_rnw;
				    CauseTransport *cause_trans;
				    CauseNas *cause_nas;
				    CauseProtocol *cause_proto;
				    CauseMisc *cause_misc;

				    cause = iedata.get_Cause();
				    int16_t	causeType = cause->get_selection();

				    switch(causeType)
				    {
			    		case 1:
			    			cause_rnw = cause->get_radioNetwork();
			    			msgObj->SctpData[index].s1ap_causeType = causeType;
			    			msgObj->SctpData[index].s1ap_causeId = *cause_rnw;
			    			break;

			    		case 2:
			    			cause_trans = cause->get_transport();
			    			msgObj->SctpData[index].s1ap_causeType = causeType;
			    			msgObj->SctpData[index].s1ap_causeId = *cause_trans;
			    			break;

			    		case 3:
			    			cause_nas = cause->get_nas();
			    			msgObj->SctpData[index].s1ap_causeType = causeType;
			    			msgObj->SctpData[index].s1ap_causeId = *cause_nas;
			    			break;

			    		case 4:
			    			cause_proto = cause->get_protocol();
			    			msgObj->SctpData[index].s1ap_causeType = causeType;
			    			msgObj->SctpData[index].s1ap_causeId = *cause_proto;
			    			break;

			    		case 5:
			    			cause_misc = cause->get_misc();
			    			msgObj->SctpData[index].s1ap_causeType = causeType;
			    			msgObj->SctpData[index].s1ap_causeId = *cause_misc;
			    			break;

			    		default:
			    			msgObj->SctpData[index].s1ap_causeType = -1;
			    			msgObj->SctpData[index].s1ap_causeId = -1;
			    			break;
				    }
				    	// printf("  ** Cause : %d\n", msgObj->SctpData[index].s1ap_causeId);
				}
				break;
			}
		}
	}
}

VOID S1APMessage::fn_RABSetupRequest(InitiatingMessage *initmsg, MPacket *msgObj, uint16_t index)						/* 05  ** Completed */
{
	E_RABSetupRequest *eRabReq = initmsg->get_value().get_E_RABSetupRequest();
	E_RABSetupRequest::protocolIEs::component *ie;

	for (OssIndex i = eRabReq->get_protocolIEs().first(); i != OSS_NOINDEX; i = eRabReq->get_protocolIEs().next(i))
	{
		ie = eRabReq->get_protocolIEs().at(i);
		E_RABSetupRequestIEs_Value & iedata = ie->get_value();

		if(iedata.has_decoded())
		{
			switch (ie->get_id())
			{
				case id_MME_UE_S1AP_ID:
				{
					MME_UE_S1AP_ID 	*mmeId = iedata.get_MME_UE_S1AP_ID();
					msgObj->SctpData[index].s1ap_mmeId = *mmeId;
				}
				break;

				case id_eNB_UE_S1AP_ID:
				{
					ENB_UE_S1AP_ID *eNodeBId = iedata.get_ENB_UE_S1AP_ID();
					msgObj->SctpData[index].s1ap_eNodeBId = *eNodeBId;
					// printf("  ** MME_UE_S1AP_ID : %u| eNodeB_UE_S1AP_ID : %u\n", msgObj->SctpData[index].s1ap_mmeId, msgObj->SctpData[index].s1ap_eNodeBId);
				}
				break;

				case id_uEaggregateMaximumBitrate:
				{
					UEAggregateMaximumBitrate *br = iedata.get_UEAggregateMaximumBitrate();
					msgObj->SctpData[index].s1ap_mbrDL = br->get_uEaggregateMaximumBitRateDL();
					msgObj->SctpData[index].s1ap_mbrUL = br->get_uEaggregateMaximumBitRateUL();
					// printf("  ** Bit Rate : %u| %u\n", msgObj->SctpData[index].s1ap_mbrDL, msgObj->SctpData[index].s1ap_mbrUL);
				}
				break;

				case id_E_RABToBeSetupListBearerSUReq:
				{
					S1APMessage::get_RubToBeSetupRequest(iedata, msgObj, index);
				}
				break;
			}
		}
	}
}

VOID S1APMessage::fn_RABModifyRequest(InitiatingMessage *initmsg, MPacket *msgObj, uint16_t index)						/* 06  ** Completed */
{
	E_RABModifyRequest *rubModifyReq = initmsg->get_value().get_E_RABModifyRequest();
	E_RABModifyRequest::protocolIEs::component *ie;

	for (OssIndex i = rubModifyReq->get_protocolIEs().first(); i != OSS_NOINDEX; i = rubModifyReq->get_protocolIEs().next(i))
	{
		ie = rubModifyReq->get_protocolIEs().at(i);
		E_RABModifyRequestIEs_Value & iedata = ie->get_value();

		if(iedata.has_decoded())
		{
			switch (ie->get_id())
			{
				case id_MME_UE_S1AP_ID:
				{
					MME_UE_S1AP_ID 	*mmeId = iedata.get_MME_UE_S1AP_ID();
					msgObj->SctpData[index].s1ap_mmeId = *mmeId;
				}
				break;

				case id_eNB_UE_S1AP_ID:
				{
					ENB_UE_S1AP_ID *eNodeBId = iedata.get_ENB_UE_S1AP_ID();
					msgObj->SctpData[index].s1ap_eNodeBId = *eNodeBId;
					// printf("  ** MME_UE_S1AP_ID : %u| eNodeB_UE_S1AP_ID : %u\n", msgObj->SctpData[index].s1ap_mmeId, msgObj->SctpData[index].s1ap_eNodeBId);
				}
				break;

				case id_uEaggregateMaximumBitrate:
				{
					UEAggregateMaximumBitrate *bitRate = iedata.get_UEAggregateMaximumBitrate();
					msgObj->SctpData[index].s1ap_mbrDL = bitRate->get_uEaggregateMaximumBitRateDL();
					msgObj->SctpData[index].s1ap_mbrUL = bitRate->get_uEaggregateMaximumBitRateUL();
					// printf("  ** Bit Rate : %u| %u\n", msgObj->SctpData[index].s1ap_mbrDL, msgObj->SctpData[index].s1ap_mbrUL);
				}
				break;

				case id_E_RABToBeModifiedListBearerModReq:
				{
//TODO				E_RABToBeModifiedListBearerModReq *rubModiBearReq = iedata.get_E_RABToBeModifiedListBearerModReq();
				}
				break;
			}
		}
	}
}

VOID S1APMessage::fn_RABRelease(InitiatingMessage *initmsg, MPacket *msgObj, uint16_t index)							/* 07  ** Completed */
{
	E_RABReleaseCommand *relCommand = initmsg->get_value().get_E_RABReleaseCommand();
	E_RABReleaseCommand::protocolIEs::component *ie;

	for (OssIndex i = relCommand->get_protocolIEs().first(); i != OSS_NOINDEX; i = relCommand->get_protocolIEs().next(i))
	{
		ie = relCommand->get_protocolIEs().at(i);
		E_RABReleaseCommandIEs_Value & iedata = ie->get_value();

		if(iedata.has_decoded())
		{
			switch (ie->get_id())
			{
				case id_MME_UE_S1AP_ID:
				{
					MME_UE_S1AP_ID 	*mmeId = iedata.get_MME_UE_S1AP_ID();
					msgObj->SctpData[index].s1ap_mmeId = *mmeId;
				}
				break;

				case id_eNB_UE_S1AP_ID:
				{
					ENB_UE_S1AP_ID *eNodeBId = iedata.get_ENB_UE_S1AP_ID();
					msgObj->SctpData[index].s1ap_eNodeBId = *eNodeBId;
					// printf("  ** MME_UE_S1AP_ID : %u| eNodeB_UE_S1AP_ID : %u\n", msgObj->SctpData[index].s1ap_mmeId, msgObj->SctpData[index].s1ap_eNodeBId);
				}
				break;

				case id_uEaggregateMaximumBitrate:
				{
					UEAggregateMaximumBitrate *bitRate = iedata.get_UEAggregateMaximumBitrate();
					msgObj->SctpData[index].s1ap_mbrDL = bitRate->get_uEaggregateMaximumBitRateDL();;
					msgObj->SctpData[index].s1ap_mbrUL = bitRate->get_uEaggregateMaximumBitRateUL();;
					// printf("  ** Bit Rate : %u| %u\n", msgObj->SctpData[index].s1ap_mbrDL, msgObj->SctpData[index].s1ap_mbrUL);
				}
				break;

				case id_E_RABReleasedList:
				{
// TODO
				}
				break;

				case id_NAS_PDU:
				{
// TODO
				}
				break;
			}
		}
	}
}

VOID S1APMessage::fn_InitialContextSetupRequest(InitiatingMessage *initmsg, MPacket *msgObj, uint16_t index)  			/* 09  ** Completed */
{
	unsigned char buffer[10];
	InitialContextSetupRequest *initCtxReq = initmsg->get_value().get_InitialContextSetupRequest();
	InitialContextSetupRequest::protocolIEs::component *ie;

	for (OssIndex i = initCtxReq->get_protocolIEs().first(); i != OSS_NOINDEX; i = initCtxReq->get_protocolIEs().next(i))
	{
		ie = initCtxReq->get_protocolIEs().at(i);
		InitialContextSetupRequestIEs_Value & iedata = ie->get_value();

		if(iedata.has_decoded())
		{
			switch (ie->get_id())
			{
				case id_MME_UE_S1AP_ID:
				{
					MME_UE_S1AP_ID 	*mmeId = iedata.get_MME_UE_S1AP_ID();
					msgObj->SctpData[index].s1ap_mmeId = *mmeId;
				}
				break;

				case id_eNB_UE_S1AP_ID:
				{
					ENB_UE_S1AP_ID *eNodeBId = iedata.get_ENB_UE_S1AP_ID();
					msgObj->SctpData[index].s1ap_eNodeBId = *eNodeBId;
					// printf("  ** MME_UE_S1AP_ID : %u| eNodeB_UE_S1AP_ID : %u\n", msgObj->SctpData[index].s1ap_mmeId, msgObj->SctpData[index].s1ap_eNodeBId);
				}
				break;

				case id_uEaggregateMaximumBitrate:
				{
					UEAggregateMaximumBitrate *bitRate = iedata.get_UEAggregateMaximumBitrate();
					msgObj->SctpData[index].s1ap_mbrDL = bitRate->get_uEaggregateMaximumBitRateDL();;
					msgObj->SctpData[index].s1ap_mbrUL = bitRate->get_uEaggregateMaximumBitRateUL();;
					// printf("  ** Bit Rate : %u| %u\n", msgObj->SctpData[index].s1ap_mbrDL, msgObj->SctpData[index].s1ap_mbrUL);
				}
				break;

				case id_E_RABToBeSetupListCtxtSUReq:
				{
					bool processedFlag = false;

					E_RABToBeSetupListCtxtSUReq *suReq = iedata.get_E_RABToBeSetupListCtxtSUReq();

					E_RABToBeSetupListCtxtSUReq::component *internalIE;

					for (OssIndex i = suReq->first(); i != OSS_NOINDEX; i = suReq->next(i))
					{
						internalIE = suReq->at(i);
						E_RABToBeSetupItemCtxtSUReqIEs_Value &internalIEdata = internalIE->get_value();

						switch(internalIE->get_id())
						{
							case id_E_RABToBeSetupItemCtxtSUReq:
							{
								if(!processedFlag) {
									processedFlag = true;
									E_RABToBeSetupItemCtxtSUReq *iei = internalIEdata.get_E_RABToBeSetupItemCtxtSUReq();

									msgObj->SctpData[index].s1ap_qCI = iei->get_e_RABlevelQoSParameters().get_qCI();

									S1APMessage::get_OSSbuffer(iei->get_gTP_TEID().get_buffer(), iei->get_gTP_TEID().length(), buffer);
									strcpy(msgObj->SctpData[index].s1ap_gTP_TEID, (char*)buffer);

									if(iei->nAS_PDU_is_present()) {
										NAS_PDU *nasPdu = iei->get_nAS_PDU();
										S1APMessage::decode_NAS_PDU(nasPdu->get_buffer(), msgObj, index);
									}
								}
							}
							break;
						}
					}
				}
				break;
			}
		}
	}
}

VOID S1APMessage::fn_Paging(InitiatingMessage *initmsg, MPacket *msgObj, uint16_t index)  								/* 10  ** Completed */
{
	unsigned char buffer[20];
	Paging *paging = initmsg->get_value().get_Paging();
	Paging::protocolIEs::component *ie;

	for (OssIndex i = paging->get_protocolIEs().first(); i != OSS_NOINDEX; i = paging->get_protocolIEs().next(i))
	{
		ie = paging->get_protocolIEs().at(i);
		PagingIEs_Value & iedata = ie->get_value();

		if(iedata.has_decoded())
		{
			switch (ie->get_id())
			{
				case id_UEPagingID:
				{
					UEPagingID *pageId = iedata.get_UEPagingID();

					switch(pageId->get_selection())
					{
						case 1:
							S1APMessage::get_OSSbuffer(pageId->get_s_TMSI()->get_m_TMSI().get_buffer(),pageId->get_s_TMSI()->get_m_TMSI().length(), buffer);
							strcpy(msgObj->SctpData[index].s1ap_m_tmsi, (const char *)buffer);
							msgObj->SctpData[index].s1ap_m_tmsi_Present = true;
							break;

						case 2:
							S1APMessage::get_OSSbuffer(pageId->get_iMSI()->get_buffer(),pageId->get_iMSI()->length(), buffer);
							strcpy(msgObj->SctpData[index].s1ap_imsi, (const char *)buffer);
							msgObj->SctpData[index].s1ap_imsiPresent = true;
							break;
					}
				}
				break;

				case id_TAIList:
				{
					TAIList *taiList = iedata.get_TAIList();

					TAIList::component *internalIE;

					for (OssIndex i = taiList->first(); i != OSS_NOINDEX; i = taiList->next(i))
					{
						internalIE = taiList->at(i);
						TAIItemIEs_Value &internalIEdata = internalIE->get_value();

						switch(internalIE->get_id())
						{
							case id_TAIItem:
							{
								TAIItem *taiItem = internalIEdata.get_TAIItem();
								S1APMessage::get_OSSbuffer(taiItem->get_tAI().get_pLMNidentity().get_buffer(),taiItem->get_tAI().get_pLMNidentity().length(), buffer);
								strcpy(msgObj->SctpData[index].s1ap_pLMNIdentity, (char*)buffer);

								S1APMessage::get_OSSbuffer(taiItem->get_tAI().get_tAC().get_buffer(),taiItem->get_tAI().get_tAC().length(), buffer);
								strcpy(msgObj->SctpData[index].s1ap_tac , (char*)buffer);
							}
							break;
						}
					}
				}
				break;
			}
		}
	}
}

VOID S1APMessage::fn_DownlinkNasTransport(InitiatingMessage *initmsg, MPacket *msgObj, uint16_t index)					/* 11  ** Completed */
{
	DownlinkNASTransport *downNasTpt = initmsg->get_value().get_DownlinkNASTransport();
	DownlinkNASTransport::protocolIEs::component *ie;

	for (OssIndex i = downNasTpt->get_protocolIEs().first(); i != OSS_NOINDEX; i = downNasTpt->get_protocolIEs().next(i))
	{
		ie = downNasTpt->get_protocolIEs().at(i);
		DownlinkNASTransport_IEs_Value & iedata = ie->get_value();

		if(iedata.has_decoded())
		{
			switch (ie->get_id())
			{
				case id_NAS_PDU:
				{
					NAS_PDU *nasPdu = iedata.get_NAS_PDU();
					S1APMessage::decode_NAS_PDU(nasPdu->get_buffer(), msgObj, index);
				}
				break;

				case id_MME_UE_S1AP_ID:
				{
					MME_UE_S1AP_ID 	*mmeId = iedata.get_MME_UE_S1AP_ID();
					msgObj->SctpData[index].s1ap_mmeId = *mmeId;
				}
				break;

				case id_eNB_UE_S1AP_ID:
				{
					ENB_UE_S1AP_ID *eNodeBId = iedata.get_ENB_UE_S1AP_ID();
					msgObj->SctpData[index].s1ap_eNodeBId = *eNodeBId;
					// printf("  ** MME_UE_S1AP_ID : %u| eNodeB_UE_S1AP_ID : %u\n", msgObj->SctpData[index].s1ap_mmeId, msgObj->SctpData[index].s1ap_eNodeBId);
				}
				break;
			}
		}
	}
}

VOID S1APMessage::fn_InitialUEMessage(InitiatingMessage *initmsg, MPacket *msgObj, uint16_t index)						/* 12  ** Completed */
{
	unsigned char buffer[10];

	InitialUEMessage *initUEMsg = initmsg->get_value().get_InitialUEMessage();
	InitialUEMessage::protocolIEs::component *ie;

	for (OssIndex i = initUEMsg->get_protocolIEs().first(); i != OSS_NOINDEX; i = initUEMsg->get_protocolIEs().next(i))
	{
		ie = initUEMsg->get_protocolIEs().at(i);
		InitialUEMessage_IEs_Value & iedata = ie->get_value();

		if(iedata.has_decoded())
		{
			switch (ie->get_id())
			{
				case id_NAS_PDU:
				{
					NAS_PDU *nasPdu = iedata.get_NAS_PDU();
					S1APMessage::decode_NAS_PDU(nasPdu->get_buffer(), msgObj, index);
				}
				break;

				case id_eNB_UE_S1AP_ID:
				{
					ENB_UE_S1AP_ID *eNodeBId = iedata.get_ENB_UE_S1AP_ID();
					msgObj->SctpData[index].s1ap_eNodeBId = *eNodeBId;
					// printf("  ** eNodeB_UE_S1AP_ID : %u\n", msgObj->SctpData[index].s1ap_eNodeBId);
				}
				break;

				case id_TAI:
				{
					TAI *tai = iedata.get_TAI();
					S1APMessage::get_OSSbuffer(tai->get_tAC().get_buffer(), tai->get_tAC().length(), buffer);
					strcpy(msgObj->SctpData[index].s1ap_tac, (char*)buffer);
					// printf("  ** TAI : %s\n", msgObj->SctpData[index].s1ap_tac);
				}
				break;

				case id_EUTRAN_CGI:
				{
					EUTRAN_CGI *cgi = iedata.get_EUTRAN_CGI();
					strcpy(msgObj->SctpData[index].s1ap_pLMNIdentity, (char*)S1APMessage::get_mnc_mcc_str(cgi->get_pLMNidentity().get_buffer(), 0));

					S1APMessage::get_OSSByteBuffer(cgi->get_cell_ID().get_buffer(), 4, buffer);
					strncat(msgObj->SctpData[index].s1ap_cellId, (char*)buffer, strlen((char *)buffer)-1);
				}
				break;

				case id_RRC_Establishment_Cause:
				{
					RRC_Establishment_Cause *rrc = iedata.get_RRC_Establishment_Cause();
					msgObj->SctpData[index].s1ap_estCause = *rrc ;
				}
				break;
			}
		}
	}
}

VOID S1APMessage::fn_uplinkNASTransport(InitiatingMessage *initmsg, MPacket *msgObj, uint16_t index)					/* 13  ** Completed */
{
	unsigned char buffer[10];
	UplinkNASTransport *UpNasTpt = initmsg->get_value().get_UplinkNASTransport();
	UplinkNASTransport::protocolIEs::component *ie;

	for (OssIndex i = UpNasTpt->get_protocolIEs().first(); i != OSS_NOINDEX; i = UpNasTpt->get_protocolIEs().next(i))
	{
		ie = UpNasTpt->get_protocolIEs().at(i);
		UplinkNASTransport_IEs_Value & iedata = ie->get_value();

		if(iedata.has_decoded())
		{
			switch (ie->get_id())
			{
				case id_NAS_PDU:
				{
					NAS_PDU *nasPdu = iedata.get_NAS_PDU();
					S1APMessage::decode_NAS_PDU(nasPdu->get_buffer(), msgObj, index);
				}
				break;

				case id_MME_UE_S1AP_ID:
				{
					MME_UE_S1AP_ID 	*mmeId = iedata.get_MME_UE_S1AP_ID();
					msgObj->SctpData[index].s1ap_mmeId = *mmeId;
				}
				break;

				case id_eNB_UE_S1AP_ID:
				{
					ENB_UE_S1AP_ID *eNodeBId = iedata.get_ENB_UE_S1AP_ID();
					msgObj->SctpData[index].s1ap_eNodeBId = *eNodeBId;
				}
				break;

				case id_EUTRAN_CGI:
				{
					EUTRAN_CGI *cgi = iedata.get_EUTRAN_CGI();
					strcpy(msgObj->SctpData[index].s1ap_pLMNIdentity , (char*)S1APMessage::get_mnc_mcc_str(cgi->get_pLMNidentity().get_buffer(), 0));

					S1APMessage::get_OSSByteBuffer(cgi->get_cell_ID().get_buffer(), 4, buffer);
					strncat(msgObj->SctpData[index].s1ap_cellId, (char*)buffer, strlen((char *)buffer)-1);
				}
				break;

				case id_TAI:
				{
					TAI *tai = iedata.get_TAI();
					S1APMessage::get_OSSbuffer(tai->get_tAC().get_buffer(), tai->get_tAC().length(), buffer);
					strcpy(msgObj->SctpData[index].s1ap_tac , (char*)buffer);
				}
				break;
			}
		}
	}
}

VOID S1APMessage::fn_UEContextReleaseRequest(InitiatingMessage *initmsg, MPacket *msgObj, uint16_t index) 				/* 18  ** Completed */
{
	UEContextReleaseRequest *ueCtxRelReq = initmsg->get_value().get_UEContextReleaseRequest();

	UEContextReleaseRequest::protocolIEs::component *ie;

	for (OssIndex i = ueCtxRelReq->get_protocolIEs().first(); i != OSS_NOINDEX; i = ueCtxRelReq->get_protocolIEs().next(i))
	{
		ie = ueCtxRelReq->get_protocolIEs().at(i);
		UEContextReleaseRequest_IEs_Value & iedata = ie->get_value();

		if(iedata.has_decoded())
		{
			switch (ie->get_id())
			{
				case id_MME_UE_S1AP_ID:
				{
					MME_UE_S1AP_ID 	*mmeId = iedata.get_MME_UE_S1AP_ID();
					msgObj->SctpData[index].s1ap_mmeId = *mmeId;
				}
				break;

				case id_eNB_UE_S1AP_ID:
				{
					ENB_UE_S1AP_ID *eNodeBId = iedata.get_ENB_UE_S1AP_ID();
					msgObj->SctpData[index].s1ap_eNodeBId = *eNodeBId;
					// printf("  ** MME_UE_S1AP_ID : %u| eNodeB_UE_S1AP_ID : %u\n", msgObj->SctpData[index].s1ap_mmeId, msgObj->SctpData[index].s1ap_eNodeBId);
				}
				break;

				case id_Cause:
				{
				    Cause *cause;
				    CauseRadioNetwork *cause_rnw;
				    CauseTransport *cause_trans;
				    CauseNas *cause_nas;
				    CauseProtocol *cause_proto;
				    CauseMisc *cause_misc;

				    cause = iedata.get_Cause();
				    int16_t	causeType = cause->get_selection();

				    switch(causeType)
				    {
			    	case 1:
			    		cause_rnw = cause->get_radioNetwork();
			    		msgObj->SctpData[index].s1ap_causeType = causeType;
			    		msgObj->SctpData[index].s1ap_causeId = *cause_rnw;
			    		break;

			    	case 2:
			    		cause_trans = cause->get_transport();
			    		msgObj->SctpData[index].s1ap_causeType = causeType;
			    		msgObj->SctpData[index].s1ap_causeId = *cause_trans;
			    		break;

			    	case 3:
			    		cause_nas = cause->get_nas();
			    		msgObj->SctpData[index].s1ap_causeType = causeType;
			    		msgObj->SctpData[index].s1ap_causeId = *cause_nas;
			    		break;

			    	case 4:
			    		cause_proto = cause->get_protocol();
			    		msgObj->SctpData[index].s1ap_causeType = causeType;
			    		msgObj->SctpData[index].s1ap_causeId = *cause_proto;
			    		break;

			    	case 5:
			    		cause_misc = cause->get_misc();
			    		msgObj->SctpData[index].s1ap_causeType = causeType;
			    		msgObj->SctpData[index].s1ap_causeId = *cause_misc;
			    		break;

			    	default:
			    		msgObj->SctpData[index].s1ap_causeType = -1;
			    		msgObj->SctpData[index].s1ap_causeId = -1;
			    		break;
				    }
				    // printf("  ** Cause : %d\n", msgObj->SctpData[index].s1ap_causeId);

				}
				break;
			}
		}
	}
}

VOID S1APMessage::fn_UEContextModificationRequest(InitiatingMessage *initmsg, MPacket *msgObj, uint16_t index)			/* 21 **  Completed */
{
	unsigned char buffer[10];
	UEContextModificationRequest *cmreq = initmsg->get_value().get_UEContextModificationRequest();
	UEContextModificationRequest::protocolIEs::component *ie;

	for (OssIndex i = cmreq->get_protocolIEs().first(); i != OSS_NOINDEX; i = cmreq->get_protocolIEs().next(i))
	{
		ie = cmreq->get_protocolIEs().at(i);
		UEContextModificationRequestIEs_Value &iedata = ie->get_value();

		if(iedata.has_decoded())
		{
			switch (ie->get_id())
			{
				case id_MME_UE_S1AP_ID:
				{
					MME_UE_S1AP_ID 	*mmeId = iedata.get_MME_UE_S1AP_ID();
					msgObj->SctpData[index].s1ap_mmeId = *mmeId;
				}
				break;

				case id_eNB_UE_S1AP_ID:
				{
					ENB_UE_S1AP_ID *eNodeBId = iedata.get_ENB_UE_S1AP_ID();
					msgObj->SctpData[index].s1ap_eNodeBId = *eNodeBId;
					// printf("  ** MME_UE_S1AP_ID : %u| eNodeB_UE_S1AP_ID : %u\n", msgObj->SctpData[index].s1ap_mmeId, msgObj->SctpData[index].s1ap_eNodeBId);
				}
				break;

				case id_uEaggregateMaximumBitrate:
				{
					UEAggregateMaximumBitrate *br = iedata.get_UEAggregateMaximumBitrate();
					msgObj->SctpData[index].s1ap_mbrDL = br->get_uEaggregateMaximumBitRateDL();
					msgObj->SctpData[index].s1ap_mbrUL = br->get_uEaggregateMaximumBitRateUL();
					// printf("  ** Bit Rate : %u| %u\n", msgObj->SctpData[index].s1ap_mbrDL, msgObj->SctpData[index].s1ap_mbrUL);
				}
				break;

				case id_RegisteredLAI:
				{
					LAI *lai = iedata.get_LAI();

//					strcpy(msgObj->SctpData[index].pLMNIdentity , (char*)S1APMessage::get_mnc_mcc_str(lai->get_pLMNidentity().get_buffer(), 0));
					S1APMessage::get_OSSbuffer(lai->get_lAC().get_buffer(),lai->get_lAC().length(), buffer);
					strcpy(msgObj->SctpData[index].s1ap_lac , (char*)buffer);
					// printf("  ** RegisteredLAI : %s\n", msgObj->SctpData[index].s1ap_lac);
				}
				break;
			}
		}
	}
}

VOID S1APMessage::fn_UECapabilityInfoIndication(InitiatingMessage *initmsg, MPacket *msgObj, uint16_t index)  			/* 22  ** Completed */
{
	UECapabilityInfoIndication *ueCpInfInd = initmsg->get_value().get_UECapabilityInfoIndication();
	UECapabilityInfoIndication::protocolIEs::component *ie;

	for (OssIndex i = ueCpInfInd->get_protocolIEs().first(); i != OSS_NOINDEX; i = ueCpInfInd->get_protocolIEs().next(i))
	{
		ie = ueCpInfInd->get_protocolIEs().at(i);
		UECapabilityInfoIndicationIEs_Value & iedata = ie->get_value();

		if(iedata.has_decoded())
		{
			switch (ie->get_id())
			{
				case id_MME_UE_S1AP_ID:
				{
					MME_UE_S1AP_ID 	*mmeId = iedata.get_MME_UE_S1AP_ID();
					msgObj->SctpData[index].s1ap_mmeId = *mmeId;
				}
				break;

				case id_eNB_UE_S1AP_ID:
				{
					ENB_UE_S1AP_ID *eNodeBId = iedata.get_ENB_UE_S1AP_ID();
					msgObj->SctpData[index].s1ap_eNodeBId = *eNodeBId;
					// printf("  ** MME_UE_S1AP_ID : %u| eNodeB_UE_S1AP_ID : %u\n", msgObj->SctpData[index].s1ap_mmeId, msgObj->SctpData[index].s1ap_eNodeBId);
				}
				break;

				case id_UERadioCapability:
				{
 					UERadioCapability *ueCapability = iedata.get_UERadioCapability();  /* TODO */

 					S1APMessage::hexDump((const void*) ueCapability->get_buffer(), 100);
//					S1APMessage::get_OSSbuffer(ueCapability->get_buffer(), ueCapability->length(), buffer);
//					// printf("%s UE Capability - %s\n", TAB, buffer);
				}
				break;
			}
		}
	}
}

VOID S1APMessage::fn_UEContextReleaseCommand(InitiatingMessage *initmsg, MPacket *msgObj, uint16_t index)   			/* 23  ** Completed */
{
	UEContextReleaseCommand *ueCtxRelCom = initmsg->get_value().get_UEContextReleaseCommand();
	UEContextReleaseCommand::protocolIEs::component *ie;

	for (OssIndex i = ueCtxRelCom->get_protocolIEs().first(); i != OSS_NOINDEX; i = ueCtxRelCom->get_protocolIEs().next(i))
	{
		ie = ueCtxRelCom->get_protocolIEs().at(i);
		UEContextReleaseCommand_IEs_Value & iedata = ie->get_value();

		if(iedata.has_decoded())
		{
			switch (ie->get_id())
			{
				case id_UE_S1AP_IDs:
				{
					UE_S1AP_IDs *ids = iedata.get_UE_S1AP_IDs();

					switch(ids->get_selection())
					{
						case 1:	/* uE_S1AP_ID_pair_chosen */
						{
							UE_S1AP_IDs::uE_S1AP_ID_pair *ueS1apId = ids->get_uE_S1AP_ID_pair();

							MME_UE_S1AP_ID 	mmeId = ueS1apId->get_mME_UE_S1AP_ID();
							msgObj->SctpData[index].s1ap_mmeId = mmeId;
							ENB_UE_S1AP_ID 	eNodeBId = ueS1apId->get_eNB_UE_S1AP_ID();
							msgObj->SctpData[index].s1ap_eNodeBId = eNodeBId;
							// printf("  ** ID Pair MME_UE_S1AP_ID : %u| eNodeB_UE_S1AP_ID : %u\n", msgObj->SctpData[index].s1ap_mmeId, msgObj->SctpData[index].s1ap_eNodeBId);
						}
						break;

						case 2:	/* mME_UE_S1AP_ID_chosen */
						{
							UE_S1AP_IDs::mME_UE_S1AP_ID *mmeUeS1apId = ids->get_mME_UE_S1AP_ID();
							msgObj->SctpData[index].s1ap_mmeId = *mmeUeS1apId;
							// printf("  ** MME_UE_S1AP_ID : %u\n", msgObj->SctpData[index].s1ap_mmeId);
						}
						break;
					}
				}
				break;

				case id_Cause:
				{
				    Cause *cause;
				    CauseRadioNetwork *cause_rnw;
				    CauseTransport *cause_trans;
				    CauseNas *cause_nas;
				    CauseProtocol *cause_proto;
				    CauseMisc *cause_misc;

				    cause = iedata.get_Cause();
				    int16_t	causeType = cause->get_selection();

				    switch(causeType)
				    {
			    	case 1:
			    		cause_rnw = cause->get_radioNetwork();
			    		msgObj->SctpData[index].s1ap_causeType = causeType;
			    		msgObj->SctpData[index].s1ap_causeId = *cause_rnw;
			    		break;

			    	case 2:
			    		cause_trans = cause->get_transport();
			    		msgObj->SctpData[index].s1ap_causeType = causeType;
			    		msgObj->SctpData[index].s1ap_causeId = *cause_trans;
			    		break;

			    	case 3:
			    		cause_nas = cause->get_nas();
			    		msgObj->SctpData[index].s1ap_causeType = causeType;
			    		msgObj->SctpData[index].s1ap_causeId = *cause_nas;
			    		break;

			    	case 4:
			    		cause_proto = cause->get_protocol();
			    		msgObj->SctpData[index].s1ap_causeType = causeType;
			    		msgObj->SctpData[index].s1ap_causeId = *cause_proto;
			    		break;

			    	case 5:
			    		cause_misc = cause->get_misc();
			    		msgObj->SctpData[index].s1ap_causeType = causeType;
			    		msgObj->SctpData[index].s1ap_causeId = *cause_misc;
			    		break;

			    	default:
			    		msgObj->SctpData[index].s1ap_causeType = -1;
			    		msgObj->SctpData[index].s1ap_causeId = -1;
			    		break;
				    }
				    // printf("  ** Cause : %d\n", msgObj->SctpData[index].s1ap_causeId);
				}
				break;
			}
		}
	}
}

VOID S1APMessage::fn_eNBStatusTransfer(InitiatingMessage *initmsg, MPacket *msgObj, uint16_t index)   					/* 24  ** Completed */
{
	__shared24 *eNodeBTransfer = initmsg->get_value().get_ENBStatusTransfer();
	__shared24::protocolIEs::component *ie;

	for (OssIndex i = eNodeBTransfer->get_protocolIEs().first(); i != OSS_NOINDEX; i = eNodeBTransfer->get_protocolIEs().next(i))
	{
		ie = eNodeBTransfer->get_protocolIEs().at(i);
		ENBStatusTransferIEs_Value & iedata = ie->get_value();

		if(iedata.has_decoded())
		{
			switch (ie->get_id())
			{
				case id_MME_UE_S1AP_ID:
				{
					MME_UE_S1AP_ID 	*mmeId = iedata.get_MME_UE_S1AP_ID();
					msgObj->SctpData[index].s1ap_mmeId = *mmeId;
				}
				break;

				case id_eNB_UE_S1AP_ID:
				{
					ENB_UE_S1AP_ID *eNodeBId = iedata.get_ENB_UE_S1AP_ID();
					msgObj->SctpData[index].s1ap_eNodeBId = *eNodeBId;
					// printf("  ** MME_UE_S1AP_ID : %u| eNodeB_UE_S1AP_ID : %u\n", msgObj->SctpData[index].s1ap_mmeId, msgObj->SctpData[index].s1ap_eNodeBId);
				}
				break;
			}
		}
	}
}

VOID S1APMessage::fn_MMEStatusTransfer(InitiatingMessage *initmsg, MPacket *msgObj, uint16_t index)   					/* 25  ** Completed */
{
	__shared24 *mmeTransfer = initmsg->get_value().get_MMEStatusTransfer();
	__shared24::protocolIEs::component *ie;

	for (OssIndex i = mmeTransfer->get_protocolIEs().first(); i != OSS_NOINDEX; i = mmeTransfer->get_protocolIEs().next(i))
	{
		ie = mmeTransfer->get_protocolIEs().at(i);
		ENBStatusTransferIEs_Value & iedata = ie->get_value();

		if(iedata.has_decoded())
		{
			switch (ie->get_id())
			{
				case id_MME_UE_S1AP_ID:
				{
					MME_UE_S1AP_ID 	*mmeId = iedata.get_MME_UE_S1AP_ID();
					msgObj->SctpData[index].s1ap_mmeId = *mmeId;
				}
				break;

				case id_eNB_UE_S1AP_ID:
				{
					ENB_UE_S1AP_ID *eNodeBId = iedata.get_ENB_UE_S1AP_ID();
					msgObj->SctpData[index].s1ap_eNodeBId = *eNodeBId;
					// printf("  ** MME_UE_S1AP_ID : %u| eNodeB_UE_S1AP_ID : %u\n", msgObj->SctpData[index].s1ap_mmeId, msgObj->SctpData[index].s1ap_eNodeBId);
				}
				break;
			}
		}
	}
}


/*
 * Successfull response
 */

VOID S1APMessage::fn_HandoverPreparationSuccess(SuccessfulOutcome *succOut, MPacket *msgObj, uint16_t index)
{
	HandoverCommand *handOverCommand = succOut->get_value().get_HandoverCommand();
	HandoverCommand::protocolIEs::component *ie;

	for (OssIndex i = handOverCommand->get_protocolIEs().first(); i != OSS_NOINDEX; i = handOverCommand->get_protocolIEs().next(i))
	{
		ie = handOverCommand->get_protocolIEs().at(i);
		HandoverCommandIEs_Value & iedata = ie->get_value();

		if(iedata.has_decoded())
		{
			switch (ie->get_id())
			{
				case id_MME_UE_S1AP_ID:
				{
					MME_UE_S1AP_ID 	*mmeId = iedata.get_MME_UE_S1AP_ID();
					msgObj->SctpData[index].s1ap_mmeId = *mmeId;
				}
				break;

				case id_eNB_UE_S1AP_ID:
				{
					ENB_UE_S1AP_ID *eNodeBId = iedata.get_ENB_UE_S1AP_ID();
					msgObj->SctpData[index].s1ap_eNodeBId = *eNodeBId;
					// printf("  ** MME_UE_S1AP_ID : %u| eNodeB_UE_S1AP_ID : %u\n", msgObj->SctpData[index].s1ap_mmeId, msgObj->SctpData[index].s1ap_eNodeBId);
				}
				break;

				case id_HandoverType:
				{
					HandoverType *type = iedata.get_HandoverType();
					msgObj->SctpData[index].s1ap_handoverType = *type;
					// printf("  ** Handover Type: %d\n", *type);
				}
				break;
			}
		}
	}

}

VOID S1APMessage::fn_HandoverRequestAck(SuccessfulOutcome *succOut, MPacket *msgObj, uint16_t index)
{
	HandoverRequestAcknowledge *ack = succOut->get_value().get_HandoverRequestAcknowledge();
	HandoverRequestAcknowledge::protocolIEs::component *ie;

	for (OssIndex i = ack->get_protocolIEs().first(); i != OSS_NOINDEX; i = ack->get_protocolIEs().next(i))
	{
		ie = ack->get_protocolIEs().at(i);
		HandoverRequestAcknowledgeIEs_Value & iedata = ie->get_value();

		if(iedata.has_decoded())
		{
			switch (ie->get_id())
			{
				case id_MME_UE_S1AP_ID:
				{
					MME_UE_S1AP_ID 	*mmeId = iedata.get_MME_UE_S1AP_ID();
					msgObj->SctpData[index].s1ap_mmeId = *mmeId;
				}
				break;

				case id_eNB_UE_S1AP_ID:
				{
					ENB_UE_S1AP_ID *eNodeBId = iedata.get_ENB_UE_S1AP_ID();
					msgObj->SctpData[index].s1ap_eNodeBId = *eNodeBId;
					// printf("  ** MME_UE_S1AP_ID : %u| eNodeB_UE_S1AP_ID : %u\n", msgObj->SctpData[index].s1ap_mmeId, msgObj->SctpData[index].s1ap_eNodeBId);
				}
				break;
			}
		}
	}
}

VOID S1APMessage::fn_HandoverCancelAck(SuccessfulOutcome *succOut, MPacket *msgObj, uint16_t index)
{
	__shared35 *hoAck = succOut->get_value().get_HandoverCancelAcknowledge();
	__shared35::protocolIEs::component *ie;

	for (OssIndex i = hoAck->get_protocolIEs().first(); i != OSS_NOINDEX; i = hoAck->get_protocolIEs().next(i))
	{
		ie = hoAck->get_protocolIEs().at(i);
		HandoverCancelAcknowledgeIEs_Value &iedata = ie->get_value();

		if(iedata.has_decoded())
		{
			switch (ie->get_id())
			{
				case id_MME_UE_S1AP_ID:
				{
					MME_UE_S1AP_ID 	*mmeId = iedata.get_MME_UE_S1AP_ID();
					msgObj->SctpData[index].s1ap_mmeId = *mmeId;
				}
				break;

				case id_eNB_UE_S1AP_ID:
				{
					ENB_UE_S1AP_ID *eNodeBId = iedata.get_ENB_UE_S1AP_ID();
					msgObj->SctpData[index].s1ap_eNodeBId = *eNodeBId;
					// printf("  ** MME_UE_S1AP_ID : %u| eNodeB_UE_S1AP_ID : %u\n", msgObj->SctpData[index].s1ap_mmeId, msgObj->SctpData[index].s1ap_eNodeBId);
				}
				break;
			}
		}
	}
}

VOID S1APMessage::fn_RABSetupResponse(SuccessfulOutcome *succOut, MPacket *msgObj, uint16_t index)						/* 5  ** Completed */
{
	unsigned char buffer[10];
	E_RABSetupResponse *eRabRes = succOut->get_value().get_E_RABSetupResponse();
	E_RABSetupResponse::protocolIEs::component *ie;

	for (OssIndex i = eRabRes->get_protocolIEs().first(); i != OSS_NOINDEX; i = eRabRes->get_protocolIEs().next(i))
	{
		ie = eRabRes->get_protocolIEs().at(i);
		E_RABSetupResponseIEs_Value & iedata = ie->get_value();

		if(iedata.has_decoded())
		{
			switch (ie->get_id())
			{
				case id_MME_UE_S1AP_ID:
				{
					MME_UE_S1AP_ID 	*mmeId = iedata.get_MME_UE_S1AP_ID();
					msgObj->SctpData[index].s1ap_mmeId = *mmeId;
				}
				break;

				case id_eNB_UE_S1AP_ID:
				{
					ENB_UE_S1AP_ID *eNodeBId = iedata.get_ENB_UE_S1AP_ID();
					msgObj->SctpData[index].s1ap_eNodeBId = *eNodeBId;
					// printf("  ** MME_UE_S1AP_ID : %u| eNodeB_UE_S1AP_ID : %u\n", msgObj->SctpData[index].s1ap_mmeId, msgObj->SctpData[index].s1ap_eNodeBId);
				}
				break;

				case id_E_RABSetupListBearerSURes:
				{
					E_RABSetupListBearerSURes *suRes = iedata.get_E_RABSetupListBearerSURes();
					E_RABSetupListBearerSURes::component *internalIE;

					for (OssIndex i = suRes->first(); i != OSS_NOINDEX; i = suRes->next(i))
					{
						internalIE = suRes->at(i);
						E_RABSetupItemBearerSUResIEs_Value &internalIEdata = internalIE->get_value();

						switch(internalIE->get_id())
						{
							case id_E_RABSetupItemBearerSURes:
							{
									E_RABSetupItemBearerSURes *iei = internalIEdata.get_E_RABSetupItemBearerSURes();
//									msgObj->SctpData[index].rabId = iei->get_e_RAB_ID();

									S1APMessage::get_OSSbuffer(iei->get_gTP_TEID().get_buffer(), iei->get_gTP_TEID().length(), buffer);
//									strcpy(msgObj->SctpData[index].gTP_TEID , (char*)buffer);

									S1APMessage::get_IPAddress(iei->get_transportLayerAddress().get_buffer(), 4, buffer);
//									strcpy(msgObj->SctpData[index].transLayerAdd , (char*)buffer);

							}
							break;
						}
					}
				}
				break;
			}
		}
	}
}

VOID S1APMessage::fn_RABModifyResponse(SuccessfulOutcome *succOut, MPacket *msgObj, uint16_t index)						/* 6  ** Completed */
{
	E_RABModifyResponse *rubModifyRsp = succOut->get_value().get_E_RABModifyResponse();
	E_RABModifyResponse::protocolIEs::component *ie;

	for (OssIndex i = rubModifyRsp->get_protocolIEs().first(); i != OSS_NOINDEX; i = rubModifyRsp->get_protocolIEs().next(i))
	{
		ie = rubModifyRsp->get_protocolIEs().at(i);
		E_RABModifyResponseIEs_Value & iedata = ie->get_value();

		if(iedata.has_decoded())
		{
			switch (ie->get_id())
			{
				case id_MME_UE_S1AP_ID:
				{
					MME_UE_S1AP_ID 	*mmeId = iedata.get_MME_UE_S1AP_ID();
					msgObj->SctpData[index].s1ap_mmeId = *mmeId;
				}
				break;

				case id_eNB_UE_S1AP_ID:
				{
					ENB_UE_S1AP_ID *eNodeBId = iedata.get_ENB_UE_S1AP_ID();
					msgObj->SctpData[index].s1ap_eNodeBId = *eNodeBId;
					// printf("  ** MME_UE_S1AP_ID : %u| eNodeB_UE_S1AP_ID : %u\n", msgObj->SctpData[index].s1ap_mmeId, msgObj->SctpData[index].s1ap_eNodeBId);
				}
				break;

				case id_E_RABModifyListBearerModRes:
				{
					 E_RABModifyListBearerModRes *modifyRsp = iedata.get_E_RABModifyListBearerModRes();
					 E_RABModifyListBearerModRes::component *internalIE;

					 for (OssIndex i = modifyRsp->first(); i != OSS_NOINDEX; i = modifyRsp->next(i))
					 {
						 internalIE = modifyRsp->at(i);
						 E_RABModifyItemBearerModResIEs_Value &internalIEdata = internalIE->get_value();

						 switch(internalIE->get_id())
						 {
							 case id_E_RABModifyItemBearerModRes:
							 {
								 __shared32 *berRsp = internalIEdata.get_E_RABModifyItemBearerModRes();
								 msgObj->SctpData[index].s1ap_rabId = berRsp->get_e_RAB_ID();
							 }
							break;
						 }
					 }
				}
			}
		}
	}
}

VOID S1APMessage::fn_RABReleaseResponse(SuccessfulOutcome *succOut, MPacket *msgObj, uint16_t index)					/* 7  ** Completed */
{
	E_RABReleaseResponse *rubRelRsp = succOut->get_value().get_E_RABReleaseResponse();
	E_RABReleaseResponse::protocolIEs::component *ie;

	for (OssIndex i = rubRelRsp->get_protocolIEs().first(); i != OSS_NOINDEX; i = rubRelRsp->get_protocolIEs().next(i))
	{
		ie = rubRelRsp->get_protocolIEs().at(i);
		E_RABReleaseResponseIEs_Value & iedata = ie->get_value();

		if(iedata.has_decoded())
		{
			switch(ie->get_id())
			{
				case id_MME_UE_S1AP_ID:
				{
					MME_UE_S1AP_ID 	*mmeId = iedata.get_MME_UE_S1AP_ID();
					msgObj->SctpData[index].s1ap_mmeId = *mmeId;
				}
				break;

				case id_eNB_UE_S1AP_ID:
				{
					ENB_UE_S1AP_ID *eNodeBId = iedata.get_ENB_UE_S1AP_ID();
					msgObj->SctpData[index].s1ap_eNodeBId = *eNodeBId;
					// printf("  ** MME_UE_S1AP_ID : %u| eNodeB_UE_S1AP_ID : %u\n", msgObj->SctpData[index].s1ap_mmeId, msgObj->SctpData[index].s1ap_eNodeBId);
				}
				break;

				case id_E_RABReleaseListBearerRelComp:
				{
// TODO
				}
				break;

				case id_E_RABReleasedList:
				{
// TODO
				}
				break;

				case id_UserLocationInformation:
				{
					UserLocationInformation *userLoc = iedata.get_UserLocationInformation();
					EUTRAN_CGI & cgi = userLoc->get_eutran_cgi();
//					strcpy(msgObj->SctpData[index].pLMNIdentity , (char*)S1APMessage::get_mnc_mcc_str(cgi.get_pLMNidentity().get_buffer(), 0));

					TAI & ptai = userLoc->get_tai();

//					S1APMessage::get_OSSbuffer(ptai.get_tAC().get_buffer(), ptai.get_tAC().length(), buffer);
//					strcpy(msgObj->SctpData[index].tac , (char*)buffer);
				}
				break;
			}
		}
	}
}

VOID S1APMessage::fn_InitialContextSetupResponse(SuccessfulOutcome *succOut, MPacket *msgObj, uint16_t index)			/* 9  ** Completed */
{
	unsigned char buffer[10];
	InitialContextSetupResponse *initCtxRes = succOut->get_value().get_InitialContextSetupResponse();
	InitialContextSetupResponse::protocolIEs::component *ie;

	for (OssIndex i = initCtxRes->get_protocolIEs().first(); i != OSS_NOINDEX; i = initCtxRes->get_protocolIEs().next(i))
	{
		ie = initCtxRes->get_protocolIEs().at(i);
		InitialContextSetupResponseIEs_Value & iedata = ie->get_value();

		if(iedata.has_decoded())
		{
			switch (ie->get_id())
			{
				case id_MME_UE_S1AP_ID:
				{
					MME_UE_S1AP_ID 	*mmeId = iedata.get_MME_UE_S1AP_ID();
					msgObj->SctpData[index].s1ap_mmeId = *mmeId;
				}
				break;

				case id_eNB_UE_S1AP_ID:
				{
					ENB_UE_S1AP_ID *eNodeBId = iedata.get_ENB_UE_S1AP_ID();
					msgObj->SctpData[index].s1ap_eNodeBId = *eNodeBId;
					// printf("  ** MME_UE_S1AP_ID : %u| eNodeB_UE_S1AP_ID : %u\n", msgObj->SctpData[index].s1ap_mmeId, msgObj->SctpData[index].s1ap_eNodeBId);
				}
				break;

				case id_E_RABSetupListCtxtSURes:
				{
					E_RABSetupListCtxtSURes *suRes = iedata.get_E_RABSetupListCtxtSURes();

					E_RABSetupListCtxtSURes::component *internalIE;

					for (OssIndex i = suRes->first(); i != OSS_NOINDEX; i = suRes->next(i))
					{
						internalIE = suRes->at(i);
						E_RABSetupItemCtxtSUResIEs_Value &internalIEdata = internalIE->get_value();

						switch(internalIE->get_id())
						{
							case id_E_RABSetupItemCtxtSURes:
								E_RABSetupItemCtxtSURes *iei = internalIEdata.get_E_RABSetupItemCtxtSURes();

								S1APMessage::get_OSSbuffer(iei->get_gTP_TEID().get_buffer(), iei->get_gTP_TEID().length(), buffer);
								strcpy(msgObj->SctpData[index].s1ap_gTP_TEID , (char*)buffer);
								// printf("  ** gTP_TEID : %s\n", msgObj->SctpData[index].s1ap_gTP_TEID);

								S1APMessage::get_IPAddress(iei->get_transportLayerAddress().get_buffer(), 4, buffer);
								strcpy(msgObj->SctpData[index].s1ap_pdnAddr , (char*)buffer);
								// printf("  ** IPAddress : %s\n", msgObj->SctpData[index].s1ap_pdnAddr);

								break;
						}
					}
				}
				break;
			}
		}
	}
}

VOID S1APMessage::fn_UEContextModificationResponse(SuccessfulOutcome *succOut, MPacket *msgObj, uint16_t index)			/* 21  ** Completed */
{
	__shared35 *ueCtxModiRes = succOut->get_value().get_UEContextModificationResponse();
	__shared35::protocolIEs::component *ie;

	for (OssIndex i = ueCtxModiRes->get_protocolIEs().first(); i != OSS_NOINDEX; i = ueCtxModiRes->get_protocolIEs().next(i))
	{
		ie = ueCtxModiRes->get_protocolIEs().at(i);
		HandoverCancelAcknowledgeIEs_Value &iedata = ie->get_value();

		if(iedata.has_decoded())
		{
			switch (ie->get_id())
			{
				case id_MME_UE_S1AP_ID:
				{
					MME_UE_S1AP_ID 	*mmeId = iedata.get_MME_UE_S1AP_ID();
					msgObj->SctpData[index].s1ap_mmeId = *mmeId;
				}
				break;

				case id_eNB_UE_S1AP_ID:
				{
					ENB_UE_S1AP_ID *eNodeBId = iedata.get_ENB_UE_S1AP_ID();
					msgObj->SctpData[index].s1ap_eNodeBId = *eNodeBId;
					// printf("  ** MME_UE_S1AP_ID : %u| eNodeB_UE_S1AP_ID : %u\n", msgObj->SctpData[index].s1ap_mmeId, msgObj->SctpData[index].s1ap_eNodeBId);
				}
				break;
			}
		}
	}
}

VOID S1APMessage::fn_UEContextReleaseComplete(SuccessfulOutcome *succOut, MPacket *msgObj, uint16_t index)				/* 23  ** Completed */
{
	UEContextReleaseComplete *ueCtxRelRes = succOut->get_value().get_UEContextReleaseComplete();
	UEContextReleaseComplete::protocolIEs::component *ie;

	for (OssIndex i = ueCtxRelRes->get_protocolIEs().first(); i != OSS_NOINDEX; i = ueCtxRelRes->get_protocolIEs().next(i))
	{
		ie = ueCtxRelRes->get_protocolIEs().at(i);
		UEContextReleaseComplete_IEs_Value & iedata = ie->get_value();

		if(iedata.has_decoded())
		{
			switch (ie->get_id())
			{
				case id_MME_UE_S1AP_ID:
				{
					MME_UE_S1AP_ID 	*mmeId = iedata.get_MME_UE_S1AP_ID();
					msgObj->SctpData[index].s1ap_mmeId = *mmeId;
				}
				break;

				case id_eNB_UE_S1AP_ID:
				{
					ENB_UE_S1AP_ID *eNodeBId = iedata.get_ENB_UE_S1AP_ID();
					msgObj->SctpData[index].s1ap_eNodeBId = *eNodeBId;
					// printf("  ** MME_UE_S1AP_ID : %u| eNodeB_UE_S1AP_ID : %u\n", msgObj->SctpData[index].s1ap_mmeId, msgObj->SctpData[index].s1ap_eNodeBId);
				}
				break;
			}
		}
	}
}

/*
 * unSuccessfull response
 */
VOID S1APMessage::fn_HandOverPreparationFailure(UnsuccessfulOutcome *unSuOut, MPacket *msgObj, uint16_t index)
{
	__shared21 *hoPreparationFailure = unSuOut->get_value().get_HandoverPreparationFailure();
	__shared21::protocolIEs::component *ie;

	for (OssIndex i = hoPreparationFailure->get_protocolIEs().first(); i != OSS_NOINDEX; i = hoPreparationFailure->get_protocolIEs().next(i))
	{
		ie = hoPreparationFailure->get_protocolIEs().at(i);
		HandoverPreparationFailureIEs_Value & iedata = ie->get_value();

		if(iedata.has_decoded())
		{
			switch (ie->get_id())
			{
				case id_MME_UE_S1AP_ID:
				{
					MME_UE_S1AP_ID 	*mmeId = iedata.get_MME_UE_S1AP_ID();
					msgObj->SctpData[index].s1ap_mmeId = *mmeId;
				}
				break;

				case id_eNB_UE_S1AP_ID:
				{
					ENB_UE_S1AP_ID *eNodeBId = iedata.get_ENB_UE_S1AP_ID();
					msgObj->SctpData[index].s1ap_eNodeBId = *eNodeBId;
					// printf("  ** MME_UE_S1AP_ID : %u| eNodeB_UE_S1AP_ID : %u\n", msgObj->SctpData[index].s1ap_mmeId, msgObj->SctpData[index].s1ap_eNodeBId);
				}
				break;

				case id_Cause:
				{
					Cause *cause;
					CauseRadioNetwork *cause_rnw;
					CauseTransport *cause_trans;
					CauseNas *cause_nas;
					CauseProtocol *cause_proto;
					CauseMisc *cause_misc;

					cause = iedata.get_Cause();
					int16_t	causeType = cause->get_selection();

					switch(causeType)
					{
						case 1:
							cause_rnw = cause->get_radioNetwork();
							msgObj->SctpData[index].s1ap_causeType = causeType;
							msgObj->SctpData[index].s1ap_causeId = *cause_rnw;
							break;

						case 2:
							cause_trans = cause->get_transport();
							msgObj->SctpData[index].s1ap_causeType = causeType;
							msgObj->SctpData[index].s1ap_causeId = *cause_trans;
							break;

						case 3:
							cause_nas = cause->get_nas();
							msgObj->SctpData[index].s1ap_causeType = causeType;
							msgObj->SctpData[index].s1ap_causeId = *cause_nas;
							break;

						case 4:
							cause_proto = cause->get_protocol();
							msgObj->SctpData[index].s1ap_causeType = causeType;
							msgObj->SctpData[index].s1ap_causeId = *cause_proto;
							break;

						case 5:
							cause_misc = cause->get_misc();
							msgObj->SctpData[index].s1ap_causeType = causeType;
							msgObj->SctpData[index].s1ap_causeId = *cause_misc;
							break;

						default:
							msgObj->SctpData[index].s1ap_causeType = -1;
							msgObj->SctpData[index].s1ap_causeId = -1;
							break;
					}
					// printf("  ** Cause : %d\n", msgObj->SctpData[index].s1ap_causeId);
				}
				break;
			}
		}
	}
}

VOID S1APMessage::fn_HandOverFailure(UnsuccessfulOutcome *unSuOut, MPacket *msgObj, uint16_t index)
{
	HandoverFailure *hofailure = unSuOut->get_value().get_HandoverFailure();
	HandoverFailure::protocolIEs::component *ie;

	for (OssIndex i = hofailure->get_protocolIEs().first(); i != OSS_NOINDEX; i = hofailure->get_protocolIEs().next(i))
	{
		ie = hofailure->get_protocolIEs().at(i);
		HandoverFailureIEs_Value & iedata = ie->get_value();

		if(iedata.has_decoded())
		{
			switch (ie->get_id())
			{
				case id_MME_UE_S1AP_ID:
				{
					MME_UE_S1AP_ID 	*mmeId = iedata.get_MME_UE_S1AP_ID();
					msgObj->SctpData[index].s1ap_mmeId = *mmeId;
				}
				break;

				case id_Cause:
				{
					Cause *cause;
					CauseRadioNetwork *cause_rnw;
					CauseTransport *cause_trans;
					CauseNas *cause_nas;
					CauseProtocol *cause_proto;
					CauseMisc *cause_misc;

					cause = iedata.get_Cause();
					int16_t	causeType = cause->get_selection();

					switch(causeType)
					{
						case 1:
							cause_rnw = cause->get_radioNetwork();
							msgObj->SctpData[index].s1ap_causeType = causeType;
							msgObj->SctpData[index].s1ap_causeId = *cause_rnw;
							break;

						case 2:
							cause_trans = cause->get_transport();
							msgObj->SctpData[index].s1ap_causeType = causeType;
							msgObj->SctpData[index].s1ap_causeId = *cause_trans;
							break;

						case 3:
							cause_nas = cause->get_nas();
							msgObj->SctpData[index].s1ap_causeType = causeType;
							msgObj->SctpData[index].s1ap_causeId = *cause_nas;
							break;

						case 4:
							cause_proto = cause->get_protocol();
							msgObj->SctpData[index].s1ap_causeType = causeType;
							msgObj->SctpData[index].s1ap_causeId = *cause_proto;
							break;

						case 5:
							cause_misc = cause->get_misc();
							msgObj->SctpData[index].s1ap_causeType = causeType;
							msgObj->SctpData[index].s1ap_causeId = *cause_misc;
							break;

						default:
							msgObj->SctpData[index].s1ap_causeType = -1;
							msgObj->SctpData[index].s1ap_causeId = -1;
							break;
					}
				}
				break;
			}
		}
	}
}

VOID S1APMessage::fn_InitialContextSetupFailure(UnsuccessfulOutcome *unSuOut, MPacket *msgObj, uint16_t index)			/* 9  ** Completed */
{
	UEContextModificationFailure *initCtxFail = unSuOut->get_value().get_InitialContextSetupFailure();
	UEContextModificationFailure::protocolIEs::component *ie;

	for (OssIndex i = initCtxFail->get_protocolIEs().first(); i != OSS_NOINDEX; i = initCtxFail->get_protocolIEs().next(i))
	{
		ie = initCtxFail->get_protocolIEs().at(i);
		HandoverPreparationFailureIEs_Value & iedata = ie->get_value();

		if(iedata.has_decoded())
		{
			switch (ie->get_id())
			{
				case id_MME_UE_S1AP_ID:
				{
					MME_UE_S1AP_ID 	*mmeId = iedata.get_MME_UE_S1AP_ID();
					msgObj->SctpData[index].s1ap_mmeId = *mmeId;
				}
				break;

				case id_eNB_UE_S1AP_ID:
				{
					ENB_UE_S1AP_ID *eNodeBId = iedata.get_ENB_UE_S1AP_ID();
					msgObj->SctpData[index].s1ap_eNodeBId = *eNodeBId;
					// printf("  ** MME_UE_S1AP_ID : %u| eNodeB_UE_S1AP_ID : %u\n", msgObj->SctpData[index].s1ap_mmeId, msgObj->SctpData[index].s1ap_eNodeBId);
				}
				break;

				case id_Cause:
				{
				    Cause *cause;
				    CauseRadioNetwork *cause_rnw;
				    CauseTransport *cause_trans;
				    CauseNas *cause_nas;
				    CauseProtocol *cause_proto;
				    CauseMisc *cause_misc;

				    cause = iedata.get_Cause();
				    int16_t	causeType = cause->get_selection();

				    switch(causeType)
				    {
			    	case 1:
			    		cause_rnw = cause->get_radioNetwork();
			    		msgObj->SctpData[index].s1ap_causeType = causeType;
			    		msgObj->SctpData[index].s1ap_causeId = *cause_rnw;
			    		break;

			    	case 2:
			    		cause_trans = cause->get_transport();
			    		msgObj->SctpData[index].s1ap_causeType = causeType;
			    		msgObj->SctpData[index].s1ap_causeId = *cause_trans;
			    		break;

			    	case 3:
			    		cause_nas = cause->get_nas();
			    		msgObj->SctpData[index].s1ap_causeType = causeType;
			    		msgObj->SctpData[index].s1ap_causeId = *cause_nas;
			    		break;

			    	case 4:
			    		cause_proto = cause->get_protocol();
			    		msgObj->SctpData[index].s1ap_causeType = causeType;
			    		msgObj->SctpData[index].s1ap_causeId = *cause_proto;
			    		break;

			    	case 5:
			    		cause_misc = cause->get_misc();
			    		msgObj->SctpData[index].s1ap_causeType = causeType;
			    		msgObj->SctpData[index].s1ap_causeId = *cause_misc;
			    		break;

			    	default:
			    		msgObj->SctpData[index].s1ap_causeType = -1;
			    		msgObj->SctpData[index].s1ap_causeId = -1;
			    		break;
				    }
				    // printf("  ** Cause : %d\n", msgObj->SctpData[index].s1ap_causeId);
				}
				break;
			}
		}
	}
}

VOID S1APMessage::fn_UEContextModificationFailure(UnsuccessfulOutcome *unSuOut, MPacket *msgObj, uint16_t index)		/* 21 **  Completed */
{
	__shared21 *ueCtxModiFailure = unSuOut->get_value().get_UEContextModificationFailure();
	__shared21::protocolIEs::component *ie;

	for (OssIndex i = ueCtxModiFailure->get_protocolIEs().first(); i != OSS_NOINDEX; i = ueCtxModiFailure->get_protocolIEs().next(i))
	{
		ie = ueCtxModiFailure->get_protocolIEs().at(i);
		HandoverPreparationFailureIEs_Value & iedata = ie->get_value();

		if(iedata.has_decoded())
		{
			switch (ie->get_id())
			{
				case id_MME_UE_S1AP_ID:
				{
					MME_UE_S1AP_ID 	*mmeId = iedata.get_MME_UE_S1AP_ID();
					msgObj->SctpData[index].s1ap_mmeId = *mmeId;
				}
				break;

				case id_eNB_UE_S1AP_ID:
				{
					ENB_UE_S1AP_ID *eNodeBId = iedata.get_ENB_UE_S1AP_ID();
					msgObj->SctpData[index].s1ap_eNodeBId = *eNodeBId;
					// printf("  ** MME_UE_S1AP_ID : %u| eNodeB_UE_S1AP_ID : %u\n", msgObj->SctpData[index].s1ap_mmeId, msgObj->SctpData[index].s1ap_eNodeBId);
				}
				break;

				case id_Cause:
				{
					Cause *cause;
					CauseRadioNetwork *cause_rnw;
					CauseTransport *cause_trans;
					CauseNas *cause_nas;
					CauseProtocol *cause_proto;
					CauseMisc *cause_misc;

					cause = iedata.get_Cause();
				    int16_t	causeType = cause->get_selection();

				    switch(causeType)
				    {
			    	case 1:
			    		cause_rnw = cause->get_radioNetwork();
			    		msgObj->SctpData[index].s1ap_causeType = causeType;
			    		msgObj->SctpData[index].s1ap_causeId = *cause_rnw;
			    		break;

			    	case 2:
			    		cause_trans = cause->get_transport();
			    		msgObj->SctpData[index].s1ap_causeType = causeType;
			    		msgObj->SctpData[index].s1ap_causeId = *cause_trans;
			    		break;

			    	case 3:
			    		cause_nas = cause->get_nas();
			    		msgObj->SctpData[index].s1ap_causeType = causeType;
			    		msgObj->SctpData[index].s1ap_causeId = *cause_nas;
			    		break;

			    	case 4:
			    		cause_proto = cause->get_protocol();
			    		msgObj->SctpData[index].s1ap_causeType = causeType;
			    		msgObj->SctpData[index].s1ap_causeId = *cause_proto;
			    		break;

			    	case 5:
			    		cause_misc = cause->get_misc();
			    		msgObj->SctpData[index].s1ap_causeType = causeType;
			    		msgObj->SctpData[index].s1ap_causeId = *cause_misc;
			    		break;

			    	default:
			    		msgObj->SctpData[index].s1ap_causeType = -1;
			    		msgObj->SctpData[index].s1ap_causeId = -1;
			    		break;
				    }
				    // printf("  ** Cause : %d\n", msgObj->SctpData[index].s1ap_causeId);
				}
				break;
			}
		}
	}
}

VOID S1APMessage::S1AP_InitiatingMessageParsingTable()
{
	S1AP_ProcedureMap::initiatingProcTable.insert(std::pair<uint32_t, initiatingProc>(id_HandoverPreparation, &fn_HandoverPreparation));				/* 00 */
	S1AP_ProcedureMap::initiatingProcTable.insert(std::pair<uint32_t, initiatingProc>(id_HandoverResourceAllocation, &fn_HandoverRequest));				/* 01 */
	S1AP_ProcedureMap::initiatingProcTable.insert(std::pair<uint32_t, initiatingProc>(id_HandoverNotification, &fn_HandoverNotification));				/* 02 */
	S1AP_ProcedureMap::initiatingProcTable.insert(std::pair<uint32_t, initiatingProc>(id_HandoverCancel, &fn_HandoverCancel));							/* 04 */
	S1AP_ProcedureMap::initiatingProcTable.insert(std::pair<uint32_t, initiatingProc>(id_E_RABSetup, &fn_RABSetupRequest));								/* 05 */
	S1AP_ProcedureMap::initiatingProcTable.insert(std::pair<uint32_t, initiatingProc>(id_E_RABModify, &fn_RABModifyRequest));							/* 06 */
	S1AP_ProcedureMap::initiatingProcTable.insert(std::pair<uint32_t, initiatingProc>(id_E_RABRelease, &fn_RABRelease));								/* 07 */
	S1AP_ProcedureMap::initiatingProcTable.insert(std::pair<uint32_t, initiatingProc>(id_InitialContextSetup, &fn_InitialContextSetupRequest));			/* 09 */
	S1AP_ProcedureMap::initiatingProcTable.insert(std::pair<uint32_t, initiatingProc>(id_Paging, &fn_Paging));											/* 10 */
	S1AP_ProcedureMap::initiatingProcTable.insert(std::pair<uint32_t, initiatingProc>(id_downlinkNASTransport, &fn_DownlinkNasTransport));				/* 11 */
	S1AP_ProcedureMap::initiatingProcTable.insert(std::pair<uint32_t, initiatingProc>(id_initialUEMessage, &fn_InitialUEMessage));						/* 12 */
	S1AP_ProcedureMap::initiatingProcTable.insert(std::pair<uint32_t, initiatingProc>(id_uplinkNASTransport, &fn_uplinkNASTransport));					/* 13 */
	S1AP_ProcedureMap::initiatingProcTable.insert(std::pair<uint32_t, initiatingProc>(id_UEContextReleaseRequest, &fn_UEContextReleaseRequest));		/* 18 */
	S1AP_ProcedureMap::initiatingProcTable.insert(std::pair<uint32_t, initiatingProc>(id_UEContextModification, &fn_UEContextModificationRequest));		/* 21 */
//	S1AP_ProcedureMap::initiatingProcTable.insert(std::pair<uint32_t, initiatingProc>(id_UECapabilityInfoIndication, &fn_UECapabilityInfoIndication));	/* 22 */
	S1AP_ProcedureMap::initiatingProcTable.insert(std::pair<uint32_t, initiatingProc>(id_UEContextRelease, &fn_UEContextReleaseCommand));				/* 23 */
	S1AP_ProcedureMap::initiatingProcTable.insert(std::pair<uint32_t, initiatingProc>(id_eNBStatusTransfer, &fn_eNBStatusTransfer));					/* 24 */
	S1AP_ProcedureMap::initiatingProcTable.insert(std::pair<uint32_t, initiatingProc>(id_MMEStatusTransfer, &fn_MMEStatusTransfer));					/* 25 */
}

VOID S1APMessage::S1AP_SuccessfulMessageParsingTable()
{
	S1AP_ProcedureMap::successProcTable.insert(std::pair<uint32_t, successOutcomeProc>(id_HandoverPreparation, &fn_HandoverPreparationSuccess));		/* 00 */
	S1AP_ProcedureMap::successProcTable.insert(std::pair<uint32_t, successOutcomeProc>(id_HandoverResourceAllocation, &fn_HandoverRequestAck));			/* 01 */
	S1AP_ProcedureMap::successProcTable.insert(std::pair<uint32_t, successOutcomeProc>(id_HandoverCancel, &fn_HandoverCancelAck));						/* 04 */
	S1AP_ProcedureMap::successProcTable.insert(std::pair<uint32_t, successOutcomeProc>(id_E_RABSetup, &fn_RABSetupResponse));							/* 05 */
	S1AP_ProcedureMap::successProcTable.insert(std::pair<uint32_t, successOutcomeProc>(id_E_RABModify, &fn_RABModifyResponse));							/* 06 */
	S1AP_ProcedureMap::successProcTable.insert(std::pair<uint32_t, successOutcomeProc>(id_E_RABRelease, &fn_RABReleaseResponse));						/* 07 */
	S1AP_ProcedureMap::successProcTable.insert(std::pair<uint32_t, successOutcomeProc>(id_InitialContextSetup, &fn_InitialContextSetupResponse));		/* 09 */
	S1AP_ProcedureMap::successProcTable.insert(std::pair<uint32_t, successOutcomeProc>(id_UEContextModification, &fn_UEContextModificationResponse));	/* 21 */
	S1AP_ProcedureMap::successProcTable.insert(std::pair<uint32_t, successOutcomeProc>(id_UEContextRelease, &fn_UEContextReleaseComplete));				/* 23 */
}

VOID S1APMessage::S1AP_UnSuccessfulMessageParsingTable()
{
	S1AP_ProcedureMap::unSuccessProcTable.insert(std::pair<uint32_t, unSuccessOutcomeProc>(id_HandoverPreparation, &fn_HandOverPreparationFailure));	/* 00 */
	S1AP_ProcedureMap::unSuccessProcTable.insert(std::pair<uint32_t, unSuccessOutcomeProc>(id_HandoverResourceAllocation, &fn_HandOverFailure));		/* 01 */
	S1AP_ProcedureMap::unSuccessProcTable.insert(std::pair<uint32_t, unSuccessOutcomeProc>(id_InitialContextSetup, &fn_InitialContextSetupFailure));	/* 09 */
	S1AP_ProcedureMap::unSuccessProcTable.insert(std::pair<uint32_t, unSuccessOutcomeProc>(id_UEContextModification, &fn_UEContextModificationFailure));/* 21 */
}


