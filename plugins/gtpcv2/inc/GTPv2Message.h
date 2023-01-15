/*
 * GTPMessageV2.h
 *
 *  Created on: Jun 9, 2016
 *      Author: soumen
 */

#ifndef INCLUDE_GTPMessageV2_H_
#define INCLUDE_GTPMessageV2_H_

#include "Commondefs.h"
#include "IPGlobal.h"
#include "GTPGlobal.h"

#include <string>
#include <map>
#include <unordered_map>

#define GTPv2_ULI_CGI_MASK 0x01
#define GTPv2_ULI_SAI_MASK 0x02
#define GTPv2_ULI_RAI_MASK 0x04
#define GTPv2_ULI_TAI_MASK 0x08
#define GTPv2_ULI_ECGI_MASK 0x10
#define GTPv2_ULI_LAI_MASK 0x20

class GTPv2Message {
public:

	GTPv2Message() { };
	~GTPv2Message() { };

	VOID 	GTPcV2_InitializeIETable();
	VOID	GTPcV2_MsgTypeParser();

	static char* get_ip_str(uint32_t inputStr);
	static char* get_ip6_str(char* inputStr);
	static uint8_t* decode_apn(uint8_t * m_data, uint16_t length);
	static char* decode_e164_msisdn(uint8_t *m_data, int offset);
	static char* get_mnc_mcc_str(uint8_t* m_data, uint32_t offset);
	static char* decode_uli(uint8_t* m_data, uint32_t offset, uint32_t length, uint8_t flags);
	static char* bcd_to_str(uint8_t* m_data, uint32_t offset, uint32_t len);

	static size_t get_message_type_length(uint8_t);
	static bool isvalid(uint8_t first)
	{
		bool bRet = true;
		if (first == 0)
			bRet = false;
		if (first >= 4 && first <= 50)
			bRet = false;
		if (first >= 52 && first <= 70)
			bRet = false;
		if (first >= 186 && first <= 254)
			bRet = false;
		return (bRet);
	}

	static void 	parsePacketBody(uint8_t pFlag, size_t offset, const BYTE packet, MPacket *msgObj);
	static void 	get_IE_Info(size_t offset, const BYTE packet, MPacket *msgObj);

	// information decoder methods
	static size_t get_cause_info(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_imsi_info(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_msisdn_info(uint8_t* m_data, uint32_t offset, MPacket *msgObj);

	static size_t get_recovery_info(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_selection_mode_info(uint8_t* m_data, uint32_t offset, MPacket *msgObj);

	static size_t get_gsn_addr_info(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	
	static size_t get_mei_info(uint8_t* m_data, uint32_t offset, MPacket *msgObj);


	static size_t get_user_location_info(uint8_t* m_data, uint32_t offset, MPacket *msgObj);

	static size_t get_recovery_restr_counter(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_STN_SR_info(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_ambr_info(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t eps_bearer_id(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_ip_address_info(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_indication_info(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_protocol_config_info(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_pdn_access_aloc_info(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_bearer_qos_info(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_flow_qos_info(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_rat_info(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_serving_network_info(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_ebs_bearer_TFT_info(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_TAD_info(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_f_tied_info(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_TMSI_info(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_global_cn_id(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t pdn_data_forwarding_info(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t S1_udf_data_ford_info(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_delay_value_info(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_bearer_context_info(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_charging_id_info(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_charging_charac_info(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_trace_info(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_bearer_flag_info(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_pdn_type_info(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_procedure_transact_id(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_mm_context(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_mm_context_utms_cq(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_mm_context_gsm_cq(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_mm_context_utms_q(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_mm_context_eps_qq(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_mm_context_utms_qq(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_pdn_connection_info(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_pdn_no(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_p_tmsi(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_p_tmsi_sig(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_hop_counter(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_ue_time_zone(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_trace_ref(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_complete_req_msg(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_GUTI_info(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_f_container(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_f_cause(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_plmn_id(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_target_id(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_pkt_flow_id(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_RAB_context(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_pdcp_ctx_info(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_udp_src_port(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_apn_restriction(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_selection_mode(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_src_identifc_info(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_chng_reporting_action(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_fully_qual_csid(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_chnl_needed_info(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_emlpp_pri(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_node_type(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_fqdn_name(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_transct_identifier(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_mbms_session_duration(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_mbms_service_area(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_mbms_session_id(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_mbms_flow_id(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_mbms_ip_multicast(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_mbms_distribution_ack(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_rsfp_index(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_UCI_info(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_csg_info_action(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_csg_id(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_csg_cmi(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_service_indicator(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_detatch_type(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_ldn_info(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_node_feature(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_mbms_time_to_data_transfer(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_throttling_info(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_arp_polocy(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_epc_timer(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_sig_priority_indc(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_tmgi_info(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_additional_mm_ctx_srvcc(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_additional_flags_for_srvcc(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_mmbr(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_mdt_config(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_apco_info(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_mbms_data_tf_time(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_henb_info(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_ipv4_profile(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_change_in_report(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_action_indication(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_twan_identifier(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_uli_timestamp(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_mbms_flag(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_run_nas_cause(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_cn_operation_sell_entity(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t wlan_mode_ind(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_node_no(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_presence_report_act(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_presence_report_inf(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_TWAN_id_ts(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_overload_ctl_inf(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_control_inf(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_metric(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_sequence_no(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_apn_rel_cap(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
	static size_t get_private_data_info(uint8_t* m_data, uint32_t offset, MPacket *msgObj);

	static size_t get_access_pt_name_info(uint8_t* m_data, uint32_t offset, MPacket *msgObj);

	static size_t reserved_info(uint8_t* m_data, uint32_t offset, MPacket *msgObj);
private:
	static char* tbcd_to_int(uint8_t imsi, uint32_t);
};

#endif /* INCLUDE_GTPMessageV2_H_ */
