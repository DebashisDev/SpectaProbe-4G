/*
 * S1APInit.cpp
 *
 *  Created on: Dec 17, 2019
 *      Author: Debashis
 */

#include "SpectaTypedef.h"
#include "S1APInit.h"


S1APInit::S1APInit()
{ }

S1APInit::~S1APInit()
{ }

VOID S1APInit::s1ap_procedureInit()
{
	printf("S1MME Procedure Type Initializing....\n");

	S1APInitialize::s1ap_procedureType.insert(std::pair<uint16_t, std::string>(0,  "id_HandoverPreparation"));
	S1APInitialize::s1ap_procedureType.insert(std::pair<uint16_t, std::string>(1,  "id_HandoverResourceAllocation"));
	S1APInitialize::s1ap_procedureType.insert(std::pair<uint16_t, std::string>(2,  "id_HandoverNotification"));
	S1APInitialize::s1ap_procedureType.insert(std::pair<uint16_t, std::string>(3,  "id_PathSwitchRequest"));
	S1APInitialize::s1ap_procedureType.insert(std::pair<uint16_t, std::string>(4,  "id_HandoverCancel"));
	S1APInitialize::s1ap_procedureType.insert(std::pair<uint16_t, std::string>(5,  "id_E_RABSetup"));
	S1APInitialize::s1ap_procedureType.insert(std::pair<uint16_t, std::string>(6,  "id_E_RABModify"));
	S1APInitialize::s1ap_procedureType.insert(std::pair<uint16_t, std::string>(7,  "id_E_RABRelease"));
	S1APInitialize::s1ap_procedureType.insert(std::pair<uint16_t, std::string>(8,  "id_E_RABReleaseIndication"));
	S1APInitialize::s1ap_procedureType.insert(std::pair<uint16_t, std::string>(9,  "id_InitialContextSetup"));
	S1APInitialize::s1ap_procedureType.insert(std::pair<uint16_t, std::string>(10, "id_Paging"));
	S1APInitialize::s1ap_procedureType.insert(std::pair<uint16_t, std::string>(11, "id_downlinkNASTransport"));
	S1APInitialize::s1ap_procedureType.insert(std::pair<uint16_t, std::string>(12, "id_initialUEMessage"));
	S1APInitialize::s1ap_procedureType.insert(std::pair<uint16_t, std::string>(13, "id_uplinkNASTransport"));
	S1APInitialize::s1ap_procedureType.insert(std::pair<uint16_t, std::string>(14, "id_Reset"));
	S1APInitialize::s1ap_procedureType.insert(std::pair<uint16_t, std::string>(15, "id_ErrorIndication"));
	S1APInitialize::s1ap_procedureType.insert(std::pair<uint16_t, std::string>(16, "id_NASNonDeliveryIndication"));
	S1APInitialize::s1ap_procedureType.insert(std::pair<uint16_t, std::string>(17, "id_S1Setup"));
	S1APInitialize::s1ap_procedureType.insert(std::pair<uint16_t, std::string>(18, "id_UEContextReleaseRequest"));
	S1APInitialize::s1ap_procedureType.insert(std::pair<uint16_t, std::string>(19, "id_DownlinkS1cdma2000tunnelling"));
	S1APInitialize::s1ap_procedureType.insert(std::pair<uint16_t, std::string>(20, "id_UplinkS1cdma2000tunnelling"));
	S1APInitialize::s1ap_procedureType.insert(std::pair<uint16_t, std::string>(21, "id_UEContextModification"));
	S1APInitialize::s1ap_procedureType.insert(std::pair<uint16_t, std::string>(22, "id_UECapabilityInfoIndication"));
	S1APInitialize::s1ap_procedureType.insert(std::pair<uint16_t, std::string>(23, "id_UEContextRelease"));
	S1APInitialize::s1ap_procedureType.insert(std::pair<uint16_t, std::string>(24, "id_eNBStatusTransfer"));
	S1APInitialize::s1ap_procedureType.insert(std::pair<uint16_t, std::string>(25, "id_MMEStatusTransfer"));
}

VOID S1APInit::s1ap_nasMobilityMsgInit()
{
	printf("NAS EPS-MMM Type Initializing....\n");

	S1APInitialize::s1ap_nasMobilityMgrMsg.insert(std::pair<uint16_t, std::string>(12, "Service Request"));
	S1APInitialize::s1ap_nasMobilityMgrMsg.insert(std::pair<uint16_t, std::string>(65, "Attach Request"));
	S1APInitialize::s1ap_nasMobilityMgrMsg.insert(std::pair<uint16_t, std::string>(66, "Attach Accept"));
	S1APInitialize::s1ap_nasMobilityMgrMsg.insert(std::pair<uint16_t, std::string>(67, "Attach Complete"));
	S1APInitialize::s1ap_nasMobilityMgrMsg.insert(std::pair<uint16_t, std::string>(68, "Attach Reject"));
	S1APInitialize::s1ap_nasMobilityMgrMsg.insert(std::pair<uint16_t, std::string>(69, "Detach Request"));
	S1APInitialize::s1ap_nasMobilityMgrMsg.insert(std::pair<uint16_t, std::string>(70, "Detach Accept"));
	S1APInitialize::s1ap_nasMobilityMgrMsg.insert(std::pair<uint16_t, std::string>(72, "Tracking Area Update Request"));
	S1APInitialize::s1ap_nasMobilityMgrMsg.insert(std::pair<uint16_t, std::string>(73, "Tracking Area Update Accept"));
	S1APInitialize::s1ap_nasMobilityMgrMsg.insert(std::pair<uint16_t, std::string>(74, "Tracking Area Update Complete"));
	S1APInitialize::s1ap_nasMobilityMgrMsg.insert(std::pair<uint16_t, std::string>(75, "Tracking Area Update Reject"));
	S1APInitialize::s1ap_nasMobilityMgrMsg.insert(std::pair<uint16_t, std::string>(76, "Extended service Request"));
	S1APInitialize::s1ap_nasMobilityMgrMsg.insert(std::pair<uint16_t, std::string>(77, "Service Reject"));
	S1APInitialize::s1ap_nasMobilityMgrMsg.insert(std::pair<uint16_t, std::string>(80, "GUTI reallocation command"));
	S1APInitialize::s1ap_nasMobilityMgrMsg.insert(std::pair<uint16_t, std::string>(81, "GUTI reallocation Complete"));
	S1APInitialize::s1ap_nasMobilityMgrMsg.insert(std::pair<uint16_t, std::string>(82, "Authentication Request"));
	S1APInitialize::s1ap_nasMobilityMgrMsg.insert(std::pair<uint16_t, std::string>(83, "Authentication Response"));
	S1APInitialize::s1ap_nasMobilityMgrMsg.insert(std::pair<uint16_t, std::string>(84, "Authentication Reject"));
	S1APInitialize::s1ap_nasMobilityMgrMsg.insert(std::pair<uint16_t, std::string>(85, "Identity Request"));
	S1APInitialize::s1ap_nasMobilityMgrMsg.insert(std::pair<uint16_t, std::string>(86, "Identity Response"));
	S1APInitialize::s1ap_nasMobilityMgrMsg.insert(std::pair<uint16_t, std::string>(92, "Authentication Failure"));
	S1APInitialize::s1ap_nasMobilityMgrMsg.insert(std::pair<uint16_t, std::string>(93, "Security Mode Command"));
	S1APInitialize::s1ap_nasMobilityMgrMsg.insert(std::pair<uint16_t, std::string>(94, "Security Mode Complete"));
	S1APInitialize::s1ap_nasMobilityMgrMsg.insert(std::pair<uint16_t, std::string>(95, "Security Mode Reject"));
	S1APInitialize::s1ap_nasMobilityMgrMsg.insert(std::pair<uint16_t, std::string>(96, "EMM Status"));
	S1APInitialize::s1ap_nasMobilityMgrMsg.insert(std::pair<uint16_t, std::string>(97, "EMM Information"));
	S1APInitialize::s1ap_nasMobilityMgrMsg.insert(std::pair<uint16_t, std::string>(98, "DownLink NAS Transport"));
	S1APInitialize::s1ap_nasMobilityMgrMsg.insert(std::pair<uint16_t, std::string>(99, "UpLink NAS Transport"));
	S1APInitialize::s1ap_nasMobilityMgrMsg.insert(std::pair<uint16_t, std::string>(100, "CS Service Notification"));
	S1APInitialize::s1ap_nasMobilityMgrMsg.insert(std::pair<uint16_t, std::string>(104, "DownLink Generic NAS Transport"));
	S1APInitialize::s1ap_nasMobilityMgrMsg.insert(std::pair<uint16_t, std::string>(105, "UpLink Generic NAS Transport"));
}

VOID S1APInit::s1ap_nasSessionMsgInit()
{
	printf("NAS EPS-SMM Type Initializing....\n");

	S1APInitialize::s1ap_nasSessionMgrMsg.insert(std::pair<uint16_t, std::string>(193, "Activate Default EPS Bearer Context Request"));
	S1APInitialize::s1ap_nasSessionMgrMsg.insert(std::pair<uint16_t, std::string>(194, "Activate Default EPS Bearer Context Accept"));
	S1APInitialize::s1ap_nasSessionMgrMsg.insert(std::pair<uint16_t, std::string>(195, "Activate Default EPS Bearer Context Reject"));
	S1APInitialize::s1ap_nasSessionMgrMsg.insert(std::pair<uint16_t, std::string>(197, "Activate Dedicated EPS Bearer Context Request"));
	S1APInitialize::s1ap_nasSessionMgrMsg.insert(std::pair<uint16_t, std::string>(198, "Activate Dedicated EPS Bearer Context Accept"));
	S1APInitialize::s1ap_nasSessionMgrMsg.insert(std::pair<uint16_t, std::string>(199, "Activate Dedicated EPS Bearer Context Reject"));
	S1APInitialize::s1ap_nasSessionMgrMsg.insert(std::pair<uint16_t, std::string>(201, "Modify EPS Bearer Context Request"));
	S1APInitialize::s1ap_nasSessionMgrMsg.insert(std::pair<uint16_t, std::string>(202, "Modify EPS Bearer Context Accept"));
	S1APInitialize::s1ap_nasSessionMgrMsg.insert(std::pair<uint16_t, std::string>(203, "Modify EPS Bearer Context Reject"));
	S1APInitialize::s1ap_nasSessionMgrMsg.insert(std::pair<uint16_t, std::string>(205, "Deactivate EPS Bearer Context Request"));
	S1APInitialize::s1ap_nasSessionMgrMsg.insert(std::pair<uint16_t, std::string>(206, "Deactivate EPS Bearer Context Accept"));
	S1APInitialize::s1ap_nasSessionMgrMsg.insert(std::pair<uint16_t, std::string>(208, "PDN Connectivity Request"));
	S1APInitialize::s1ap_nasSessionMgrMsg.insert(std::pair<uint16_t, std::string>(209, "PDN Connectivity Reject"));
	S1APInitialize::s1ap_nasSessionMgrMsg.insert(std::pair<uint16_t, std::string>(210, "PDN Disconnect Request"));
	S1APInitialize::s1ap_nasSessionMgrMsg.insert(std::pair<uint16_t, std::string>(211, "PDN Disconnect Reject"));
	S1APInitialize::s1ap_nasSessionMgrMsg.insert(std::pair<uint16_t, std::string>(212, "Bearer Resource Allocation Request"));
	S1APInitialize::s1ap_nasSessionMgrMsg.insert(std::pair<uint16_t, std::string>(213, "Bearer Resource Allocation Reject"));
	S1APInitialize::s1ap_nasSessionMgrMsg.insert(std::pair<uint16_t, std::string>(214, "Bearer Resource Modification Request"));
	S1APInitialize::s1ap_nasSessionMgrMsg.insert(std::pair<uint16_t, std::string>(215, "Bearer Resource Modification Reject"));
	S1APInitialize::s1ap_nasSessionMgrMsg.insert(std::pair<uint16_t, std::string>(217, "ESM Information Request"));
	S1APInitialize::s1ap_nasSessionMgrMsg.insert(std::pair<uint16_t, std::string>(218, "ESM Information response"));
	S1APInitialize::s1ap_nasSessionMgrMsg.insert(std::pair<uint16_t, std::string>(219, "Notification"));
	S1APInitialize::s1ap_nasSessionMgrMsg.insert(std::pair<uint16_t, std::string>(232, "ESM Status"));
}

VOID S1APInit::s1ap_initiatingProcValue()
{
	printf("Initiating Message Value Initializing ....\n");

	S1APInitialize::s1ap_initiatingMsgValue.insert(std::pair<uint16_t, std::string>(0,  "HandoverRequired"));
	S1APInitialize::s1ap_initiatingMsgValue.insert(std::pair<uint16_t, std::string>(1,  "HandoverRequest"));
	S1APInitialize::s1ap_initiatingMsgValue.insert(std::pair<uint16_t, std::string>(2,  "HandoverNotify"));
	S1APInitialize::s1ap_initiatingMsgValue.insert(std::pair<uint16_t, std::string>(3,  "PathSwitchRequest"));
	S1APInitialize::s1ap_initiatingMsgValue.insert(std::pair<uint16_t, std::string>(4,  "HandoverCancel"));
	S1APInitialize::s1ap_initiatingMsgValue.insert(std::pair<uint16_t, std::string>(9,  "InitialContextSetupRequest"));
	S1APInitialize::s1ap_initiatingMsgValue.insert(std::pair<uint16_t, std::string>(10, "Paging"));
	S1APInitialize::s1ap_initiatingMsgValue.insert(std::pair<uint16_t, std::string>(11, "DownlinkNASTransport"));
	S1APInitialize::s1ap_initiatingMsgValue.insert(std::pair<uint16_t, std::string>(12, "InitialUEMessage"));
	S1APInitialize::s1ap_initiatingMsgValue.insert(std::pair<uint16_t, std::string>(13, "UplinkNASTransport"));
	S1APInitialize::s1ap_initiatingMsgValue.insert(std::pair<uint16_t, std::string>(15, "ErrorIndication"));
	S1APInitialize::s1ap_initiatingMsgValue.insert(std::pair<uint16_t, std::string>(18, "UEContextReleaseRequest"));
	S1APInitialize::s1ap_initiatingMsgValue.insert(std::pair<uint16_t, std::string>(22, "UECapabilityInfoIndication"));
	S1APInitialize::s1ap_initiatingMsgValue.insert(std::pair<uint16_t, std::string>(23, "UEContextReleaseCommand"));
	S1APInitialize::s1ap_initiatingMsgValue.insert(std::pair<uint16_t, std::string>(24, "ENBStatusTransfer"));
	S1APInitialize::s1ap_initiatingMsgValue.insert(std::pair<uint16_t, std::string>(25, "MMEStatusTransfer"));
}

VOID S1APInit::s1ap_successfulProcValue()
{
	printf("Successful Message Value Initializing ....\n");

	S1APInitialize::s1ap_successfulOutcomeMsgValue.insert(std::pair<uint16_t, std::string>(0,  "HandoverCommand"));
	S1APInitialize::s1ap_successfulOutcomeMsgValue.insert(std::pair<uint16_t, std::string>(1,  "HandoverRequestAcknowledge"));
	S1APInitialize::s1ap_successfulOutcomeMsgValue.insert(std::pair<uint16_t, std::string>(3,  "PathSwitchRequestAcknowledge"));
	S1APInitialize::s1ap_successfulOutcomeMsgValue.insert(std::pair<uint16_t, std::string>(9,  "InitialContextSetupResponse"));
	S1APInitialize::s1ap_successfulOutcomeMsgValue.insert(std::pair<uint16_t, std::string>(23, "UEContextReleaseComplete"));
}

VOID S1APInit::s1ap_unSuccessfulProcValue()
{
	printf("Un-Successful Message Value Initializing ....\n");

	S1APInitialize::s1ap_unSuccessfulOutcomeMsgValue.insert(std::pair<uint16_t, std::string>(0, "HandoverPreparationFailure"));
	S1APInitialize::s1ap_unSuccessfulOutcomeMsgValue.insert(std::pair<uint16_t, std::string>(1, "HandoverFailure"));

}


VOID S1APInit::s1ap_causeType()
{
	printf("Cause Type Initializing ....\n");

	S1APInitialize::s1ap_initiatingCauseType.insert(std::pair<uint16_t, std::string>(1, "RadioNetwork-Cause"));
	S1APInitialize::s1ap_initiatingCauseType.insert(std::pair<uint16_t, std::string>(2, "Transport-Cause"));
	S1APInitialize::s1ap_initiatingCauseType.insert(std::pair<uint16_t, std::string>(3, "NAS-Cause"));
	S1APInitialize::s1ap_initiatingCauseType.insert(std::pair<uint16_t, std::string>(4, "Protocol-Cause"));
	S1APInitialize::s1ap_initiatingCauseType.insert(std::pair<uint16_t, std::string>(5, "Misc-Cause"));
}

VOID S1APInit::s1ap_radioCauseId()
{
	printf("Cause Id Initializing ....\n");

	S1APInitialize::s1ap_initiatingRadioCauseId.insert(std::pair<uint16_t, std::string>(0, 	"CauseRadioNetwork_unspecified"));
	S1APInitialize::s1ap_initiatingRadioCauseId.insert(std::pair<uint16_t, std::string>(1, 	"Tx2relocoverall_expiry"));
	S1APInitialize::s1ap_initiatingRadioCauseId.insert(std::pair<uint16_t, std::string>(2, 	"Successful_handover"));
	S1APInitialize::s1ap_initiatingRadioCauseId.insert(std::pair<uint16_t, std::string>(3,  "Release_due_to_eutran_generated_reason"));
	S1APInitialize::s1ap_initiatingRadioCauseId.insert(std::pair<uint16_t, std::string>(4,  "Handover_cancelled"));
	S1APInitialize::s1ap_initiatingRadioCauseId.insert(std::pair<uint16_t, std::string>(5,  "Partial_handover"));
	S1APInitialize::s1ap_initiatingRadioCauseId.insert(std::pair<uint16_t, std::string>(6,  "Ho_failure_in_target_EPC_eNB_or_target_system"));
	S1APInitialize::s1ap_initiatingRadioCauseId.insert(std::pair<uint16_t, std::string>(7,  "Ho_target_not_allowed"));
	S1APInitialize::s1ap_initiatingRadioCauseId.insert(std::pair<uint16_t, std::string>(8,  "TS1relocoverall_expiry"));
	S1APInitialize::s1ap_initiatingRadioCauseId.insert(std::pair<uint16_t, std::string>(9,  "TS1relocprep_expiry"));
	S1APInitialize::s1ap_initiatingRadioCauseId.insert(std::pair<uint16_t, std::string>(10,  "Cell_not_available"));
	S1APInitialize::s1ap_initiatingRadioCauseId.insert(std::pair<uint16_t, std::string>(11,  "Unknown_targetID"));
	S1APInitialize::s1ap_initiatingRadioCauseId.insert(std::pair<uint16_t, std::string>(12,  "No_radio_resources_available_in_target_cell"));
	S1APInitialize::s1ap_initiatingRadioCauseId.insert(std::pair<uint16_t, std::string>(13,  "Unknown_mme_ue_s1ap_id"));
	S1APInitialize::s1ap_initiatingRadioCauseId.insert(std::pair<uint16_t, std::string>(14,  "Unknown_enb_ue_s1ap_id"));
	S1APInitialize::s1ap_initiatingRadioCauseId.insert(std::pair<uint16_t, std::string>(15,  "Unknown_pair_ue_s1ap_id"));
	S1APInitialize::s1ap_initiatingRadioCauseId.insert(std::pair<uint16_t, std::string>(16,  "Handover_desirable_for_radio_reason"));
	S1APInitialize::s1ap_initiatingRadioCauseId.insert(std::pair<uint16_t, std::string>(17,  "Time_critical_handover"));
	S1APInitialize::s1ap_initiatingRadioCauseId.insert(std::pair<uint16_t, std::string>(18,  "Resource_optimisation_handover"));
	S1APInitialize::s1ap_initiatingRadioCauseId.insert(std::pair<uint16_t, std::string>(19,  "Reduce_load_in_serving_cell"));
	S1APInitialize::s1ap_initiatingRadioCauseId.insert(std::pair<uint16_t, std::string>(20,  "User_inactivity"));
	S1APInitialize::s1ap_initiatingRadioCauseId.insert(std::pair<uint16_t, std::string>(21,  "Radio_connection_with_ue_lost"));
	S1APInitialize::s1ap_initiatingRadioCauseId.insert(std::pair<uint16_t, std::string>(22,  "Load_balancing_tau_required"));
	S1APInitialize::s1ap_initiatingRadioCauseId.insert(std::pair<uint16_t, std::string>(23,  "Cs_fallback_triggered"));
	S1APInitialize::s1ap_initiatingRadioCauseId.insert(std::pair<uint16_t, std::string>(24,  "Ue_not_available_for_ps_service"));
	S1APInitialize::s1ap_initiatingRadioCauseId.insert(std::pair<uint16_t, std::string>(25,  "Radio_resources_not_available"));
	S1APInitialize::s1ap_initiatingRadioCauseId.insert(std::pair<uint16_t, std::string>(26,  "Failure_in_radio_interface_procedure"));
	S1APInitialize::s1ap_initiatingRadioCauseId.insert(std::pair<uint16_t, std::string>(27,  "Invalid_qos_combination"));
	S1APInitialize::s1ap_initiatingRadioCauseId.insert(std::pair<uint16_t, std::string>(28,  "Interrat_redirection"));
	S1APInitialize::s1ap_initiatingRadioCauseId.insert(std::pair<uint16_t, std::string>(29,  "Interaction_with_other_procedure"));
	S1APInitialize::s1ap_initiatingRadioCauseId.insert(std::pair<uint16_t, std::string>(30,  "Unknown_E_RAB_ID"));
	S1APInitialize::s1ap_initiatingRadioCauseId.insert(std::pair<uint16_t, std::string>(31,  "Multiple_E_RAB_ID_instances"));
	S1APInitialize::s1ap_initiatingRadioCauseId.insert(std::pair<uint16_t, std::string>(32,  "Encryption_and_or_integrity_protection_algorithms_not_supported"));
	S1APInitialize::s1ap_initiatingRadioCauseId.insert(std::pair<uint16_t, std::string>(33,  "S1_intra_system_handover_triggered"));
	S1APInitialize::s1ap_initiatingRadioCauseId.insert(std::pair<uint16_t, std::string>(34,  "S1_inter_system_handover_triggered"));
	S1APInitialize::s1ap_initiatingRadioCauseId.insert(std::pair<uint16_t, std::string>(35,  "X2_handover_triggered"));
	S1APInitialize::s1ap_initiatingRadioCauseId.insert(std::pair<uint16_t, std::string>(36,  "Redirection_towards_1xRTT"));
	S1APInitialize::s1ap_initiatingRadioCauseId.insert(std::pair<uint16_t, std::string>(37,  "Not_supported_QCI_value"));
	S1APInitialize::s1ap_initiatingRadioCauseId.insert(std::pair<uint16_t, std::string>(38,  "Invalid_CSG_Id"));
}

VOID S1APInit::s1ap_transportCauseId()
{
	S1APInitialize::s1ap_initiatingTransportCauseId.insert(std::pair<uint16_t, std::string>(0, 	"Transport_resource_unavailable"));
	S1APInitialize::s1ap_initiatingTransportCauseId.insert(std::pair<uint16_t, std::string>(1, 	"CauseTransport_unspecified"));
}

VOID S1APInit::s1ap_nasCauseId()
{
	S1APInitialize::s1ap_initiatingNasCauseId.insert(std::pair<uint16_t, std::string>(0, 	"Normal_release"));
	S1APInitialize::s1ap_initiatingNasCauseId.insert(std::pair<uint16_t, std::string>(1, 	"Authentication_failure"));
	S1APInitialize::s1ap_initiatingNasCauseId.insert(std::pair<uint16_t, std::string>(2, 	"Detach"));
	S1APInitialize::s1ap_initiatingNasCauseId.insert(std::pair<uint16_t, std::string>(3, 	"CauseNas_unspecified"));
	S1APInitialize::s1ap_initiatingNasCauseId.insert(std::pair<uint16_t, std::string>(4, 	"Csg_subscription_expiry"));
}

VOID S1APInit::s1ap_ProtocolCauseId()
{
	S1APInitialize::s1ap_initiatingProtocolCauseId.insert(std::pair<uint16_t, std::string>(0, 	"Transfer_syntax_error"));
	S1APInitialize::s1ap_initiatingProtocolCauseId.insert(std::pair<uint16_t, std::string>(1, 	"Abstract_syntax_error_reject"));
	S1APInitialize::s1ap_initiatingProtocolCauseId.insert(std::pair<uint16_t, std::string>(2, 	"Abstract_syntax_error_ignore_and_notify"));
	S1APInitialize::s1ap_initiatingProtocolCauseId.insert(std::pair<uint16_t, std::string>(3, 	"Message_not_compatible_with_receiver_state"));
	S1APInitialize::s1ap_initiatingProtocolCauseId.insert(std::pair<uint16_t, std::string>(4, 	"Semantic_error"));
	S1APInitialize::s1ap_initiatingProtocolCauseId.insert(std::pair<uint16_t, std::string>(5, 	"Abstract_syntax_error_falsely_constructed_message"));
	S1APInitialize::s1ap_initiatingProtocolCauseId.insert(std::pair<uint16_t, std::string>(6, 	"CauseProtocol_unspecified"));
}

VOID S1APInit::s1ap_miscCauseId()
{
	S1APInitialize::s1ap_initiatingMiscCauseId.insert(std::pair<uint16_t, std::string>(0, 	"Control_processing_overload"));
	S1APInitialize::s1ap_initiatingMiscCauseId.insert(std::pair<uint16_t, std::string>(1, 	"Not_enough_user_plane_processing_resources"));
	S1APInitialize::s1ap_initiatingMiscCauseId.insert(std::pair<uint16_t, std::string>(2, 	"Hardware_failure"));
	S1APInitialize::s1ap_initiatingMiscCauseId.insert(std::pair<uint16_t, std::string>(3, 	"Om_intervention"));
	S1APInitialize::s1ap_initiatingMiscCauseId.insert(std::pair<uint16_t, std::string>(4, 	"CauseMisc_unspecified"));
	S1APInitialize::s1ap_initiatingMiscCauseId.insert(std::pair<uint16_t, std::string>(5, 	"Unknown_PLMN"));
}

VOID S1APInit::s1ap_MMECauseId()
{
	S1APInitialize::s1ap_MMECauseId.insert(std::pair<uint16_t, std::string>(2, 	"IMSI unknown in HSS"));
	S1APInitialize::s1ap_MMECauseId.insert(std::pair<uint16_t, std::string>(3, 	"Illegal UE"));
	S1APInitialize::s1ap_MMECauseId.insert(std::pair<uint16_t, std::string>(6, 	"Illegal ME"));
	S1APInitialize::s1ap_MMECauseId.insert(std::pair<uint16_t, std::string>(7, 	"EPS services not allowed"));
	S1APInitialize::s1ap_MMECauseId.insert(std::pair<uint16_t, std::string>(8, 	"EPS services and non-EPS services not allowed"));
	S1APInitialize::s1ap_MMECauseId.insert(std::pair<uint16_t, std::string>(9, 	"UE identity cannot be derived by the network"));
	S1APInitialize::s1ap_MMECauseId.insert(std::pair<uint16_t, std::string>(10, "Implicitly detached"));
	S1APInitialize::s1ap_MMECauseId.insert(std::pair<uint16_t, std::string>(11, "PLMN not allowed"));
	S1APInitialize::s1ap_MMECauseId.insert(std::pair<uint16_t, std::string>(12, "Tracking Area not allowed"));
	S1APInitialize::s1ap_MMECauseId.insert(std::pair<uint16_t, std::string>(13, "Roaming not allowed in this tracking area"));
	S1APInitialize::s1ap_MMECauseId.insert(std::pair<uint16_t, std::string>(14, "EPS services not allowed in this PLMN"));
	S1APInitialize::s1ap_MMECauseId.insert(std::pair<uint16_t, std::string>(15, "No Suitable Cells In tracking area"));
	S1APInitialize::s1ap_MMECauseId.insert(std::pair<uint16_t, std::string>(16, "MSC temporarily not reachable"));
	S1APInitialize::s1ap_MMECauseId.insert(std::pair<uint16_t, std::string>(17, "Network failure"));
	S1APInitialize::s1ap_MMECauseId.insert(std::pair<uint16_t, std::string>(18, "CS domain not available"));
	S1APInitialize::s1ap_MMECauseId.insert(std::pair<uint16_t, std::string>(19, "ESM failure"));
	S1APInitialize::s1ap_MMECauseId.insert(std::pair<uint16_t, std::string>(20, "MAC failure"));
	S1APInitialize::s1ap_MMECauseId.insert(std::pair<uint16_t, std::string>(21, "Synch failure"));
	S1APInitialize::s1ap_MMECauseId.insert(std::pair<uint16_t, std::string>(22, "Congestion"));
	S1APInitialize::s1ap_MMECauseId.insert(std::pair<uint16_t, std::string>(23, "UE security capabilities mismatch"));
	S1APInitialize::s1ap_MMECauseId.insert(std::pair<uint16_t, std::string>(24, "Security mode rejected, unspecified"));
	S1APInitialize::s1ap_MMECauseId.insert(std::pair<uint16_t, std::string>(25, "Not authorized for this CSG"));
	S1APInitialize::s1ap_MMECauseId.insert(std::pair<uint16_t, std::string>(26, "Non-EPS authentication unacceptable"));
	S1APInitialize::s1ap_MMECauseId.insert(std::pair<uint16_t, std::string>(39, "CS domain temporarily not available"));
	S1APInitialize::s1ap_MMECauseId.insert(std::pair<uint16_t, std::string>(40, "No EPS bearer context activated"));
	S1APInitialize::s1ap_MMECauseId.insert(std::pair<uint16_t, std::string>(95, "Semantically incorrect message"));
	S1APInitialize::s1ap_MMECauseId.insert(std::pair<uint16_t, std::string>(96, "Invalid mandatory information"));
	S1APInitialize::s1ap_MMECauseId.insert(std::pair<uint16_t, std::string>(97, "Message type non-existent or not implemented"));
	S1APInitialize::s1ap_MMECauseId.insert(std::pair<uint16_t, std::string>(98, "Message type not compatible with the protocol state"));
	S1APInitialize::s1ap_MMECauseId.insert(std::pair<uint16_t, std::string>(99, "Information element non-existent or not implemented"));
	S1APInitialize::s1ap_MMECauseId.insert(std::pair<uint16_t, std::string>(100,"Conditional IE error"));
	S1APInitialize::s1ap_MMECauseId.insert(std::pair<uint16_t, std::string>(101,"Message not compatible with the protocol state"));
	S1APInitialize::s1ap_MMECauseId.insert(std::pair<uint16_t, std::string>(111,"Protocol error, unspecified"));
}
