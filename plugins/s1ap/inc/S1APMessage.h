/*
 * S1APMessage.h
 *
 *  Created on: 8 Jan 2020
 *      Author: Debashis
 */

#ifndef PLUGINS_S1AP_SRC_S1APMESSAGE_H_
#define PLUGINS_S1AP_SRC_S1APMESSAGE_H_

#include "IPGlobal.h"
#include "S1APGlobal.h"
#include "SpectaTypedef.h"

using namespace std;

class S1APMessage : S1APGlobal
{
	public:
		S1APMessage();
		~S1APMessage();

		VOID 	S1AP_InitiatingMessageParsingTable();
		VOID	S1AP_SuccessfulMessageParsingTable();
		VOID	S1AP_UnSuccessfulMessageParsingTable();

		static VOID 	fn_HandoverPreparation(InitiatingMessage *initmsg, MPacket *msgObj, uint16_t index);
		static VOID 	fn_HandoverRequest(InitiatingMessage *initmsg, MPacket *msgObj, uint16_t index);
		static VOID 	fn_HandoverNotification(InitiatingMessage *initmsg, MPacket *msgObj, uint16_t index);
		static VOID 	fn_HandoverCancel(InitiatingMessage *initmsg, MPacket *msgObj, uint16_t index);
		static VOID 	fn_InitialUEMessage(InitiatingMessage *initmsg, MPacket *msgObj, uint16_t index);
		static VOID		fn_RABSetupRequest(InitiatingMessage *initmsg, MPacket *msgObj, uint16_t index);
		static VOID 	fn_RABModifyRequest(InitiatingMessage *initmsg, MPacket *msgObj, uint16_t index);
		static VOID 	fn_RABRelease(InitiatingMessage *initmsg, MPacket *msgObj, uint16_t index);
		static VOID 	fn_InitialContextSetupRequest(InitiatingMessage *initmsg, MPacket *msgObj, uint16_t index);
		static VOID 	fn_Paging(InitiatingMessage *initmsg, MPacket *msgObj, uint16_t index);
		static VOID		fn_DownlinkNasTransport(InitiatingMessage *initmsg, MPacket *msgObj, uint16_t index);
		static VOID 	fn_uplinkNASTransport(InitiatingMessage *initmsg, MPacket *msgObj, uint16_t index);
		static VOID 	fn_UEContextReleaseRequest(InitiatingMessage *initmsg, MPacket *msgObj, uint16_t index);
		static VOID 	fn_UEContextModificationRequest(InitiatingMessage *initmsg, MPacket *msgObj, uint16_t index);
		static VOID 	fn_UECapabilityInfoIndication(InitiatingMessage *initmsg, MPacket *msgObj, uint16_t index);
		static VOID 	fn_UEContextReleaseCommand(InitiatingMessage *initmsg, MPacket *msgObj, uint16_t index);
		static VOID 	fn_eNBStatusTransfer(InitiatingMessage *initmsg, MPacket *msgObj, uint16_t index);
		static VOID		fn_MMEStatusTransfer(InitiatingMessage *initmsg, MPacket *msgObj, uint16_t index);


		static VOID 	fn_HandoverPreparationSuccess(SuccessfulOutcome *succOut, MPacket *msgObj, uint16_t index);
		static VOID 	fn_HandoverRequestAck(SuccessfulOutcome *succOut, MPacket *msgObj, uint16_t index);
		static VOID 	fn_HandoverCancelAck(SuccessfulOutcome *succOut, MPacket *msgObj, uint16_t index);
		static VOID 	fn_RABSetupResponse(SuccessfulOutcome *succOut, MPacket *msgObj, uint16_t index);
		static VOID 	fn_RABModifyResponse(SuccessfulOutcome *succOut, MPacket *msgObj, uint16_t index);
		static VOID 	fn_RABReleaseResponse(SuccessfulOutcome *succOut, MPacket *msgObj, uint16_t index);
		static VOID		fn_InitialContextSetupResponse(SuccessfulOutcome *succOut, MPacket *msgObj, uint16_t index);
		static VOID 	fn_UEContextModificationResponse(SuccessfulOutcome *succOut, MPacket *msgObj, uint16_t index);
		static VOID 	fn_UEContextReleaseComplete(SuccessfulOutcome *succOut, MPacket *msgObj, uint16_t index);

		static VOID		fn_HandOverPreparationFailure(UnsuccessfulOutcome *unSuOut, MPacket *msgObj, uint16_t index);
		static VOID		fn_HandOverFailure(UnsuccessfulOutcome *unSuOut, MPacket *msgObj, uint16_t index);
		static VOID 	fn_InitialContextSetupFailure(UnsuccessfulOutcome *unSuOut, MPacket *msgObj, uint16_t index);
		static VOID		fn_UEContextModificationFailure(UnsuccessfulOutcome *unSuOut, MPacket *msgObj, uint16_t index);

		static char*	get_mnc_mcc_str(void* m_data, uint32_t offset);
		static VOID 	get_OSSbuffer(const void* pv, int len, unsigned char *buffer);
		static VOID 	get_OSSByteBuffer(const void* pv, int len, unsigned char *buffer);

		static VOID 	hexDump(const void* pv, int len);

		static VOID		decode_targetSource(void *pBuffer, MPacket *msgObj, uint16_t index);
		static VOID 	decode_NAS_PDU(void *pBuffer, MPacket *msgObj, uint16_t index);
		static VOID		get_IMEISV(void *pBuffer, uint16_t offset, MPacket *msgObj, uint16_t index);
		static VOID		get_AttachRequestData(void *pBuffer, uint16_t offset, MPacket *msgObj, uint16_t index);
		static VOID 	get_AttachAcceptData(void *pBuffer, uint16_t offset, MPacket *msgObj, uint16_t index);
		static VOID		get_AttachCompleteData(void *pBuffer, uint16_t offset, MPacket *msgObj, uint16_t index);
		static VOID		get_DetachRequestData(void *pBuffer, uint16_t offset, MPacket *msgObj, uint16_t index);
		static VOID		get_TrackingAreaUpdateRequestData(void *pBuffer, uint16_t offset, MPacket *msgObj, uint16_t index);
		static VOID		get_TrackingAreaUpdateAcceptData(void *pBuffer, uint16_t offset, MPacket *msgObj, uint16_t index);

		static uint16_t	get_UENetworkCapability(void *pBuffer, uint16_t offset, MPacket *msgObj, uint16_t index);
		static uint16_t get_EMSMsgContainer(void *pBuffer, uint16_t offset, MPacket *msgObj, bool flag, uint16_t index);
		static uint16_t	get_EPSMobileIdentity(void *pBuffer, uint16_t offset, MPacket *msgObj, uint16_t index);

		static char* 	get_IMSI(uint8_t* m_data, uint32_t offset, uint32_t e_usr_addr_ln);
		static char* 	get_IMEI(uint8_t* m_data, uint32_t offset, uint32_t e_usr_addr_ln);

		static char* 	get_APN(uint8_t * m_data, uint16_t length);
		static VOID 	get_IPAddress(const void* pv, int len, unsigned char *buffer);

		static VOID 	get_RubToBeSetupRequest(E_RABSetupRequestIEs_Value & iedata, MPacket *msgObj, uint16_t index);
};

#endif /* PLUGINS_S1AP_SRC_S1APMESSAGE_H_ */
