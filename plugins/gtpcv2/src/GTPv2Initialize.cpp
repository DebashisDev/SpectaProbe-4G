/*
 * GTPcV2Initialize.cpp
 *
 *  Created on: Oct 17, 2017
 *      Author: Debashis
 */

#include "GTPv2Initialize.h"

GTPv2Initialize::GTPv2Initialize() {

}

GTPv2Initialize::~GTPv2Initialize() {
}

VOID GTPv2Initialize::GTPcV2_InitializeRatType()
{
	GTPAttr::ratTypeMap.insert(std::pair<int, std::string>(0, std::string("NA")));
	GTPAttr::ratTypeMap.insert(std::pair<int, std::string>(1, std::string("UTRAN")));
	GTPAttr::ratTypeMap.insert(std::pair<int, std::string>(2, std::string("GERAN")));
	GTPAttr::ratTypeMap.insert(std::pair<int, std::string>(3, std::string("WLAN")));
	GTPAttr::ratTypeMap.insert(std::pair<int, std::string>(4, std::string("GAN")));
	GTPAttr::ratTypeMap.insert(std::pair<int, std::string>(5, std::string("HSPA Evolution")));
	GTPAttr::ratTypeMap.insert(std::pair<int, std::string>(6, std::string("EUTRAN")));
	GTPAttr::ratTypeMap.insert(std::pair<int, std::string>(7, std::string("VIRTUAL")));
	GTPAttr::ratTypeMap.insert(std::pair<int, std::string>(8, std::string("SPARE")));
}

VOID GTPv2Initialize::GTPcV2_InitializeCauseCode()
{
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(0, "Reserved"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(1, "Reserved"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(2, "Local Detach"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(3, "Complete Detach"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(4, "RAT changed from 3GPP to Non-3GPP"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(5, "ISR deactivation"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(6, "Error Indication received from RNC/eNodeB/S4-SGSN"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(7, "IMSI Detach Only"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(8, "Reactivation Requested"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(9, "PDN reconnection to this APN disallowed"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(10, "Access changed from Non-3GPP to 3GPP"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(11, "PDN connection inactivity timer expires"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(12, "PGW not responding"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(13, "Network Failure"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(14, "QoS parameter mismatch"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(16, "Request accepted"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(17, "Request accepted partially"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(18, "New PDN type due to network preference"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(19, "New PDN type due to single address bearer only")); /* charging */
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(64, "Context Not Found"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(65, "Invalid Message Format"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(66, "Version not supported by next peer"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(67, "Version not supported by next peer"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(68, "Service not supported"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(69, "Mandatory IE incorrect"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(70, "Mandatory IE missing"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(71, "Shall not be used"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(72, "System failure"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(73, "No resources available"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(74, "Semantic error in the TFT operation"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(75, "Syntactic error in the TFT operation"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(76, "Semantic errors in packet filter(s)"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(77, "Syntactic errors in packet filter(s)"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(78, "Missing or unknown APN"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(79, "Shall not be used"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(80, "GRE key not found"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(81, "Relocation failure"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(82, "Denied in RAT"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(83, "Preferred PDN type not supported"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(84, "All dynamic addresses are occupied"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(85, "UE context without TFT already activated"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(86, "Protocol type not supported"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(87, "UE not responding"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(88, "UE refuses"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(89, "Service denied"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(90, "Unable to page UE"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(91, "No memory available"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(92, "User authentication failed"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(93, "APN access denied – no subscription"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(94, "Request rejected (reason not specified)"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(95, "P-TMSI Signature mismatch"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(96, "IMSI/IMEI not known"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(97, "Semantic error in the TAD operation"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(98, "Syntactic error in the TAD operation"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(99, "Shall not be used"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(100, "Remote peer not responding"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(101, "Collision with network initiated request"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(102, "Unable to page UE due to Suspension"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(103, "Conditional IE missing"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(104, "APN Restriction type Incompatible with currently active PDN connection"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(106, "Data forwarding not supported"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(107, "Invalid reply from remote peer"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(108, "Fallback to GTPv1"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(109, "Invalid peer"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(110, "Temporarily rejected due to handover/TAU/RAU procedure in progress"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(111, "Modifications not limited to S1-U bearers"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(112, "Request rejected for a PMIPv6 reason"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(113, "APN Congestion"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(114, "Bearer handling not supported"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(115, "UE already re-attached"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(116, "Multiple PDN connections for a given APN not allowed"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(117, "Target access restricted for the subscriber"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(118, "Shall not be used"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(119, "MME/SGSN refuses due to VPLMN Policy"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(120, "GTP-C Entity Congestiony"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(121, "Late Overlapping Request"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(122, "Timed out Request"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(123, "UE is temporarily not reachable due to power saving"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(124, "Relocation failure due to NAS message redirection"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(125, "UE not Authorised by OCS or external AAA Server"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(126, "Multiple accesses to a PDN connection not allowed"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(127, "Request rejected due to UE capability"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(128, "Spare"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(192, "Non-existent"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(193, "Invalid message format"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(194, "IMSI/IMEI not known"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(195, "MS is GPRS Detached"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(196, "MS is not GPRS Responding"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(197, "MS Refuses"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(198, "Version not supported"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(199, "No resources available"));
	GTPAttr::causeCodeMap.insert(std::pair<int, std::string>(200, "Service not supported"));
}

VOID GTPv2Initialize::GTPcV2_InitializeMessageType()
{
	GTPAttr::gtpcV2MsgType.insert(std::pair<uint16_t, std::string>(0, "NA"));
	GTPAttr::gtpcV2MsgType.insert(std::pair<uint16_t, std::string>(32, "Create Session Request"));
	GTPAttr::gtpcV2MsgType.insert(std::pair<uint16_t, std::string>(33, "Create Session Response"));
	GTPAttr::gtpcV2MsgType.insert(std::pair<uint16_t, std::string>(34, "Modify Bearer Request"));
	GTPAttr::gtpcV2MsgType.insert(std::pair<uint16_t, std::string>(35, "Modify Bearer Response"));
	GTPAttr::gtpcV2MsgType.insert(std::pair<uint16_t, std::string>(36, "Delete Session Request"));
	GTPAttr::gtpcV2MsgType.insert(std::pair<uint16_t, std::string>(37, "Delete Session Response"));
	GTPAttr::gtpcV2MsgType.insert(std::pair<uint16_t, std::string>(70, "DownLink Data Notification Failure"));
	GTPAttr::gtpcV2MsgType.insert(std::pair<uint16_t, std::string>(95, "Create Bearer Request"));
	GTPAttr::gtpcV2MsgType.insert(std::pair<uint16_t, std::string>(96, "Create Bearer Response"));
	GTPAttr::gtpcV2MsgType.insert(std::pair<uint16_t, std::string>(97, "Update Bearer Request"));
	GTPAttr::gtpcV2MsgType.insert(std::pair<uint16_t, std::string>(98, "Update Bearer Response"));
	GTPAttr::gtpcV2MsgType.insert(std::pair<uint16_t, std::string>(99, "Delete Bearer Request"));
	GTPAttr::gtpcV2MsgType.insert(std::pair<uint16_t, std::string>(100, "Delete Bearer Response"));
	GTPAttr::gtpcV2MsgType.insert(std::pair<uint16_t, std::string>(170, "Release Access Bearers Request"));
	GTPAttr::gtpcV2MsgType.insert(std::pair<uint16_t, std::string>(171, "Release Access Bearers Response"));
	GTPAttr::gtpcV2MsgType.insert(std::pair<uint16_t, std::string>(176, "DownLink Data Notification"));
	GTPAttr::gtpcV2MsgType.insert(std::pair<uint16_t, std::string>(177, "DownLink Data Notification Ack"));
	GTPAttr::gtpcV2MsgType.insert(std::pair<uint16_t, std::string>(211, "Modify Access Bearers Request"));
	GTPAttr::gtpcV2MsgType.insert(std::pair<uint16_t, std::string>(212, "Modify Access Bearers Response"));
}
