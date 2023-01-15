/*
 * TCPGlobal.cpp
 *
 *  Created on: Nov 14, 2015
 *      Author: Debashis
 */

#include "IPGlobal.h"

using namespace std;

namespace GContainer
{
	GConfig *config;
}

namespace ipRange{
	int totalIps;
	_ipRange ipRange[100];
}

namespace Layer3Initialize
{
	std::map<uint16_t, decodeLayer> decodeLayerMap;
}

namespace ipProtocol{
	std::unordered_map<uint8_t, std::string> ipProtocolMap;
}

namespace S1APFlush
{
	std::unordered_map<int, xdrStore> s1ap_xdr_f_0_t_0;
	std::unordered_map<int, xdrStore> s1ap_xdr_f_0_t_1;
	std::unordered_map<int, xdrStore> s1ap_xdr_f_0_t_2;
	std::unordered_map<int, xdrStore> s1ap_xdr_f_0_t_3;
	std::unordered_map<int, xdrStore> s1ap_xdr_f_0_t_4;
	std::unordered_map<int, xdrStore> s1ap_xdr_f_0_t_5;
	std::unordered_map<int, xdrStore> s1ap_xdr_f_0_t_6;
	std::unordered_map<int, xdrStore> s1ap_xdr_f_0_t_7;
	std::unordered_map<int, xdrStore> s1ap_xdr_f_0_t_8;
	std::unordered_map<int, xdrStore> s1ap_xdr_f_0_t_9;

	int s1ap_xdr_f_0_t_0_cnt = 0;
	int s1ap_xdr_f_0_t_1_cnt = 0;
	int s1ap_xdr_f_0_t_2_cnt = 0;
	int s1ap_xdr_f_0_t_3_cnt = 0;
	int s1ap_xdr_f_0_t_4_cnt = 0;
	int s1ap_xdr_f_0_t_5_cnt = 0;
	int s1ap_xdr_f_0_t_6_cnt = 0;
	int s1ap_xdr_f_0_t_7_cnt = 0;
	int s1ap_xdr_f_0_t_8_cnt = 0;
	int s1ap_xdr_f_0_t_9_cnt = 0;
}

namespace GTPStats {
	int unique_imsi_cnt = 0;

	uint64_t gtp_cr_req_pkt_count = 0;
	uint64_t gtp_cr_rsp_pkt_count = 0;
	uint64_t gtp_mb_req_pkt_count = 0;
	uint64_t gtp_mb_rsp_pkt_count = 0;
	uint64_t gtp_dl_req_pkt_count = 0;
	uint64_t gtp_dl_rsp_pkt_count = 0;

	uint64_t gtp_cr_session_count = 0;
	uint64_t gtp_mb_session_count = 0;
	uint64_t gtp_dl_session_count = 0;

	uint32_t gtp_cr_session_cln_count = 0;
	uint32_t gtp_dl_session_cln_count = 0;
	uint32_t gtp_mb_session_cln_count = 0;

	uint32_t gtpv2_glb_sessions_active_count = 0;
	uint32_t gtpv2_glb_sessions_delete_count = 0;

	uint64_t gtpc_pkt_cnt_i_0_r_0 = 0;
	uint64_t gtpc_pkt_cnt_i_0_r_1 = 0;
	uint64_t gtpc_pkt_cnt_i_0_r_2 = 0;
	uint64_t gtpc_pkt_cnt_i_0_r_3 = 0;

	uint64_t gtpc_pkt_cnt_i_1_r_0 = 0;
	uint64_t gtpc_pkt_cnt_i_1_r_1 = 0;
	uint64_t gtpc_pkt_cnt_i_1_r_2 = 0;
	uint64_t gtpc_pkt_cnt_i_1_r_3 = 0;

	uint64_t gtpc_pkt_cnt_i_2_r_0 = 0;
	uint64_t gtpc_pkt_cnt_i_2_r_1 = 0;
	uint64_t gtpc_pkt_cnt_i_2_r_2 = 0;
	uint64_t gtpc_pkt_cnt_i_2_r_3 = 0;

	uint64_t gtpc_pkt_cnt_i_3_r_0 = 0;
	uint64_t gtpc_pkt_cnt_i_3_r_1 = 0;
	uint64_t gtpc_pkt_cnt_i_3_r_2 = 0;
	uint64_t gtpc_pkt_cnt_i_3_r_3 = 0;

	uint64_t gtpu_pkt_cnt_i_0_r_0 = 0;
	uint64_t gtpu_pkt_cnt_i_0_r_1 = 0;
	uint64_t gtpu_pkt_cnt_i_0_r_2 = 0;
	uint64_t gtpu_pkt_cnt_i_0_r_3 = 0;

	uint64_t gtpu_pkt_cnt_i_1_r_0 = 0;
	uint64_t gtpu_pkt_cnt_i_1_r_1 = 0;
	uint64_t gtpu_pkt_cnt_i_1_r_2 = 0;
	uint64_t gtpu_pkt_cnt_i_1_r_3 = 0;

	uint64_t gtpu_pkt_cnt_i_2_r_0 = 0;
	uint64_t gtpu_pkt_cnt_i_2_r_1 = 0;
	uint64_t gtpu_pkt_cnt_i_2_r_2 = 0;
	uint64_t gtpu_pkt_cnt_i_2_r_3 = 0;

	uint64_t gtpu_pkt_cnt_i_3_r_0 = 0;
	uint64_t gtpu_pkt_cnt_i_3_r_1 = 0;
	uint64_t gtpu_pkt_cnt_i_3_r_2 = 0;
	uint64_t gtpu_pkt_cnt_i_3_r_3 = 0;

	int gtpc_session_pool_cnt = 0;
	int gtp_session_pool_bit_index = 0;

	bool gtp_glb_sessions_cnt_process = false;

	int gtp_glb_lku_up_active_sessions_cnt = 0;
	int gtp_glb_lku_up_sessions_cnt = 0;
	int gtp_glb_lku_up_sessions_cln_cnt	= 0;

	int gtp_glb_lku_dn_active_sessions_cnt = 0;
	int gtp_glb_lku_dn_sessions_cnt = 0;
	int gtp_glb_lku_dn_sessions_cln_cnt	= 0;

	int gtp_glb_total_sessions_count = 0;
	int gtpv1_glb_sessions_active_count 	= 0;
	int gtpv1_glb_sessions_delete_count 	= 0;

	int gtpv2_glb_lku_up_active_sessions_cnt = 0;
	int gtpv2_glb_lku_up_sessions_cnt = 0;
	int gtpv2_glb_lku_up_sessions_cln_cnt = 0;

	int gtp_glb_utran_sessions_count = 0;
	int gtp_glb_geran_sessions_count = 0;
	int gtp_glb_eutran_sessions_count	= 0;
	int gtp_glb_active_sessions_count = 0;
	int gtp_glb_sessions_bit_index = 0;

	int gtp_glb_ctl_up_cnt = 0;
	int gtp_glb_data_up_cnt = 0;
	int gtp_glb_ctl_dn_cnt = 0;
	int gtp_glb_data_dn_cnt = 0;

	uint32_t gtp_glb_sessions_op_cr_cnt 		= 0;
	uint32_t gtp_glb_sessions_op_up_cnt 		= 0;
	uint32_t gtp_glb_sessions_op_dl_cnt 		= 0;

	uint32_t gtp_pdp_cr_flush_sm_0 = 0;
	uint32_t gtp_pdp_cr_flush_sm_1 = 0;
	uint32_t gtp_pdp_cr_flush_sm_2 = 0;
	uint32_t gtp_pdp_cr_flush_sm_3 = 0;

	uint32_t gtp_pdp_up_flush_sm_0 = 0;
	uint32_t gtp_pdp_up_flush_sm_1 = 0;
	uint32_t gtp_pdp_up_flush_sm_2 = 0;
	uint32_t gtp_pdp_up_flush_sm_3 = 0;

	uint32_t gtp_pdp_dl_flush_sm_0 = 0;
	uint32_t gtp_pdp_dl_flush_sm_1 = 0;
	uint32_t gtp_pdp_dl_flush_sm_2 = 0;
	uint32_t gtp_pdp_dl_flush_sm_3 = 0;

	uint32_t gtp_pdp_cr_session_count = 0;
	uint32_t gtp_pdp_cr_session_sm_1 = 0;
	uint32_t gtp_pdp_cr_session_sm_2 = 0;
	uint32_t gtp_pdp_cr_session_sm_3 = 0;
	uint32_t gtp_pdp_cr_cln_session_count = 0;

	uint32_t gtp_pdp_up_session_count = 0;
	uint32_t gtp_pdp_up_session_sm_1 = 0;
	uint32_t gtp_pdp_up_session_sm_2 = 0;
	uint32_t gtp_pdp_up_session_sm_3 = 0;
	uint32_t gtp_pdp_up_cln_session_count = 0;

	uint32_t gtp_pdp_dl_session_count = 0;
	uint32_t gtp_pdp_dl_session_sm_1 = 0;
	uint32_t gtp_pdp_dl_session_sm_2 = 0;
	uint32_t gtp_pdp_dl_session_sm_3 = 0;
	uint32_t gtp_pdp_dl_cln_session_count = 0;

	uint32_t gtpc_pdp_cr_req_sm_0 = 0;
	uint32_t gtpc_pdp_cr_req_sm_1 = 0;
	uint32_t gtpc_pdp_cr_req_sm_2 = 0;
	uint32_t gtpc_pdp_cr_req_sm_3 = 0;
	uint32_t gtpc_pdp_cr_res_sm_0 = 0;
	uint32_t gtpc_pdp_cr_res_sm_1 = 0;
	uint32_t gtpc_pdp_cr_res_sm_2 = 0;
	uint32_t gtpc_pdp_cr_res_sm_3 = 0;

	uint32_t gtpc_pdp_up_req_sm_0 = 0;
	uint32_t gtpc_pdp_up_req_sm_1 = 0;
	uint32_t gtpc_pdp_up_req_sm_2 = 0;
	uint32_t gtpc_pdp_up_req_sm_3 = 0;
	uint32_t gtpc_pdp_up_res_sm_0 = 0;
	uint32_t gtpc_pdp_up_res_sm_1 = 0;
	uint32_t gtpc_pdp_up_res_sm_2 = 0;
	uint32_t gtpc_pdp_up_res_sm_3 = 0;

	uint32_t gtpc_pdp_dl_req_sm_0 = 0;
	uint32_t gtpc_pdp_dl_req_sm_1 = 0;
	uint32_t gtpc_pdp_dl_req_sm_2 = 0;
	uint32_t gtpc_pdp_dl_req_sm_3 = 0;
	uint32_t gtpc_pdp_dl_res_sm_0 = 0;
	uint32_t gtpc_pdp_dl_res_sm_1 = 0;
	uint32_t gtpc_pdp_dl_res_sm_2 = 0;
	uint32_t gtpc_pdp_dl_res_sm_3 = 0;
}

namespace IPStats {
	uint64_t dns_resolved_lookup_size 	= 0;
	uint64_t dns_lookup_map_size 		= 0;

	int dns_session_total_sm_0_cnt = 0;
	int dns_session_total_sm_1_cnt = 0;
	int dns_session_total_sm_2_cnt = 0;
	int dns_session_total_sm_3_cnt = 0;
	int dns_session_total_sm_4_cnt = 0;
	int dns_session_total_sm_5_cnt = 0;
	int dns_session_total_sm_6_cnt = 0;
	int dns_session_total_sm_7_cnt = 0;
	int dns_session_total_sm_8_cnt = 0;
	int dns_session_total_sm_9_cnt = 0;
	int dns_session_total_sm_10_cnt = 0;
	int dns_session_total_sm_11_cnt = 0;
	int dns_session_total_sm_12_cnt = 0;
	int dns_session_total_sm_13_cnt = 0;
	int dns_session_total_sm_14_cnt = 0;
	int dns_session_total_sm_15_cnt = 0;
	int dns_session_total_sm_16_cnt = 0;
	int dns_session_total_sm_17_cnt = 0;
	int dns_session_total_sm_18_cnt = 0;
	int dns_session_total_sm_19_cnt = 0;
	int dns_session_total_sm_20_cnt = 0;
	int dns_session_total_sm_21_cnt = 0;
	int dns_session_total_sm_22_cnt = 0;
	int dns_session_total_sm_23_cnt = 0;
	int dns_session_total_sm_24_cnt = 0;
	int dns_session_total_sm_25_cnt = 0;
	int dns_session_total_sm_26_cnt = 0;
	int dns_session_total_sm_27_cnt = 0;
	int dns_session_total_sm_28_cnt = 0;
	int dns_session_total_sm_29_cnt = 0;

	int dns_session_pool_sm_0_cnt = 0;
	int dns_session_pool_sm_1_cnt = 0;
	int dns_session_pool_sm_2_cnt = 0;
	int dns_session_pool_sm_3_cnt = 0;
	int dns_session_pool_sm_4_cnt = 0;
	int dns_session_pool_sm_5_cnt = 0;
	int dns_session_pool_sm_6_cnt = 0;
	int dns_session_pool_sm_7_cnt = 0;
	int dns_session_pool_sm_8_cnt = 0;
	int dns_session_pool_sm_9_cnt = 0;
	int dns_session_pool_sm_10_cnt = 0;
	int dns_session_pool_sm_11_cnt = 0;
	int dns_session_pool_sm_12_cnt = 0;
	int dns_session_pool_sm_13_cnt = 0;
	int dns_session_pool_sm_14_cnt = 0;
	int dns_session_pool_sm_15_cnt = 0;
	int dns_session_pool_sm_16_cnt = 0;
	int dns_session_pool_sm_17_cnt = 0;
	int dns_session_pool_sm_18_cnt = 0;
	int dns_session_pool_sm_19_cnt = 0;

	uint64_t ip_session_fin_only_sm_0_cnt = 0;
	uint64_t ip_session_fin_only_sm_1_cnt = 0;
	uint64_t ip_session_fin_only_sm_2_cnt = 0;
	uint64_t ip_session_fin_only_sm_3_cnt = 0;
	uint64_t ip_session_fin_only_sm_4_cnt = 0;
	uint64_t ip_session_fin_only_sm_5_cnt = 0;
	uint64_t ip_session_fin_only_sm_6_cnt = 0;
	uint64_t ip_session_fin_only_sm_7_cnt = 0;
	uint64_t ip_session_fin_only_sm_8_cnt = 0;
	uint64_t ip_session_fin_only_sm_9_cnt = 0;
	uint64_t ip_session_fin_only_sm_10_cnt = 0;
	uint64_t ip_session_fin_only_sm_11_cnt = 0;
	uint64_t ip_session_fin_only_sm_12_cnt = 0;
	uint64_t ip_session_fin_only_sm_13_cnt = 0;
	uint64_t ip_session_fin_only_sm_14_cnt = 0;
	uint64_t ip_session_fin_only_sm_15_cnt = 0;
	uint64_t ip_session_fin_only_sm_16_cnt = 0;
	uint64_t ip_session_fin_only_sm_17_cnt = 0;
	uint64_t ip_session_fin_only_sm_18_cnt = 0;
	uint64_t ip_session_fin_only_sm_19_cnt = 0;

	int ip_session_pkt_total_sm_0_cnt = 0;
	int ip_session_pkt_total_sm_1_cnt = 0;
	int ip_session_pkt_total_sm_2_cnt = 0;
	int ip_session_pkt_total_sm_3_cnt = 0;
	int ip_session_pkt_total_sm_4_cnt = 0;
	int ip_session_pkt_total_sm_5_cnt = 0;
	int ip_session_pkt_total_sm_6_cnt = 0;
	int ip_session_pkt_total_sm_7_cnt = 0;
	int ip_session_pkt_total_sm_8_cnt = 0;
	int ip_session_pkt_total_sm_9_cnt = 0;
	int ip_session_pkt_total_sm_10_cnt = 0;
	int ip_session_pkt_total_sm_11_cnt = 0;
	int ip_session_pkt_total_sm_12_cnt = 0;
	int ip_session_pkt_total_sm_13_cnt = 0;
	int ip_session_pkt_total_sm_14_cnt = 0;
	int ip_session_pkt_total_sm_15_cnt = 0;
	int ip_session_pkt_total_sm_16_cnt = 0;
	int ip_session_pkt_total_sm_17_cnt = 0;
	int ip_session_pkt_total_sm_18_cnt = 0;
	int ip_session_pkt_total_sm_19_cnt = 0;

	int ip_session_pkt_sm_0_cnt[10] = {0,0,0,0,0,0,0,0,0,0};
	int ip_session_pkt_sm_1_cnt[10] = {0,0,0,0,0,0,0,0,0,0};
	int ip_session_pkt_sm_2_cnt[10] = {0,0,0,0,0,0,0,0,0,0};
	int ip_session_pkt_sm_3_cnt[10] = {0,0,0,0,0,0,0,0,0,0};
	int ip_session_pkt_sm_4_cnt[10] = {0,0,0,0,0,0,0,0,0,0};
	int ip_session_pkt_sm_5_cnt[10] = {0,0,0,0,0,0,0,0,0,0};
	int ip_session_pkt_sm_6_cnt[10] = {0,0,0,0,0,0,0,0,0,0};
	int ip_session_pkt_sm_7_cnt[10] = {0,0,0,0,0,0,0,0,0,0};
	int ip_session_pkt_sm_8_cnt[10] = {0,0,0,0,0,0,0,0,0,0};
	int ip_session_pkt_sm_9_cnt[10] = {0,0,0,0,0,0,0,0,0,0};
	int ip_session_pkt_sm_10_cnt[10] = {0,0,0,0,0,0,0,0,0,0};
	int ip_session_pkt_sm_11_cnt[10] = {0,0,0,0,0,0,0,0,0,0};
	int ip_session_pkt_sm_12_cnt[10] = {0,0,0,0,0,0,0,0,0,0};
	int ip_session_pkt_sm_13_cnt[10] = {0,0,0,0,0,0,0,0,0,0};
	int ip_session_pkt_sm_14_cnt[10] = {0,0,0,0,0,0,0,0,0,0};
	int ip_session_pkt_sm_15_cnt[10] = {0,0,0,0,0,0,0,0,0,0};
	int ip_session_pkt_sm_16_cnt[10] = {0,0,0,0,0,0,0,0,0,0};
	int ip_session_pkt_sm_17_cnt[10] = {0,0,0,0,0,0,0,0,0,0};
	int ip_session_pkt_sm_18_cnt[10] = {0,0,0,0,0,0,0,0,0,0};
	int ip_session_pkt_sm_19_cnt[10] = {0,0,0,0,0,0,0,0,0,0};

	int ip_session_total_sm_0_cnt = 0;
	int ip_session_total_sm_1_cnt = 0;
	int ip_session_total_sm_2_cnt = 0;
	int ip_session_total_sm_3_cnt = 0;
	int ip_session_total_sm_4_cnt = 0;
	int ip_session_total_sm_5_cnt = 0;
	int ip_session_total_sm_6_cnt = 0;
	int ip_session_total_sm_7_cnt = 0;
	int ip_session_total_sm_8_cnt = 0;
	int ip_session_total_sm_9_cnt = 0;
	int ip_session_total_sm_10_cnt = 0;
	int ip_session_total_sm_11_cnt = 0;
	int ip_session_total_sm_12_cnt = 0;
	int ip_session_total_sm_13_cnt = 0;
	int ip_session_total_sm_14_cnt = 0;
	int ip_session_total_sm_15_cnt = 0;
	int ip_session_total_sm_16_cnt = 0;
	int ip_session_total_sm_17_cnt = 0;
	int ip_session_total_sm_18_cnt = 0;
	int ip_session_total_sm_19_cnt = 0;
	int ip_session_total_sm_20_cnt = 0;
	int ip_session_total_sm_21_cnt = 0;
	int ip_session_total_sm_22_cnt = 0;
	int ip_session_total_sm_23_cnt = 0;
	int ip_session_total_sm_24_cnt = 0;
	int ip_session_total_sm_25_cnt = 0;
	int ip_session_total_sm_26_cnt = 0;
	int ip_session_total_sm_27_cnt = 0;
	int ip_session_total_sm_28_cnt = 0;
	int ip_session_total_sm_29_cnt = 0;

	int ip_session_scanned_sm_0_cnt = 0;
	int ip_session_scanned_sm_1_cnt = 0;
	int ip_session_scanned_sm_2_cnt = 0;
	int ip_session_scanned_sm_3_cnt = 0;
	int ip_session_scanned_sm_4_cnt = 0;
	int ip_session_scanned_sm_5_cnt = 0;
	int ip_session_scanned_sm_6_cnt = 0;
	int ip_session_scanned_sm_7_cnt = 0;
	int ip_session_scanned_sm_8_cnt = 0;
	int ip_session_scanned_sm_9_cnt = 0;
	int ip_session_scanned_sm_10_cnt = 0;
	int ip_session_scanned_sm_11_cnt = 0;
	int ip_session_scanned_sm_12_cnt = 0;
	int ip_session_scanned_sm_13_cnt = 0;
	int ip_session_scanned_sm_14_cnt = 0;
	int ip_session_scanned_sm_15_cnt = 0;
	int ip_session_scanned_sm_16_cnt = 0;
	int ip_session_scanned_sm_17_cnt = 0;
	int ip_session_scanned_sm_18_cnt = 0;
	int ip_session_scanned_sm_19_cnt = 0;
	int ip_session_scanned_sm_20_cnt = 0;
	int ip_session_scanned_sm_21_cnt = 0;
	int ip_session_scanned_sm_22_cnt = 0;
	int ip_session_scanned_sm_23_cnt = 0;
	int ip_session_scanned_sm_24_cnt = 0;
	int ip_session_scanned_sm_25_cnt = 0;
	int ip_session_scanned_sm_26_cnt = 0;
	int ip_session_scanned_sm_27_cnt = 0;
	int ip_session_scanned_sm_28_cnt = 0;
	int ip_session_scanned_sm_29_cnt = 0;

	int ip_session_cleaned_tcp_sm_0_cnt = 0;
	int ip_session_cleaned_tcp_sm_1_cnt = 0;
	int ip_session_cleaned_tcp_sm_2_cnt = 0;
	int ip_session_cleaned_tcp_sm_3_cnt = 0;
	int ip_session_cleaned_tcp_sm_4_cnt = 0;
	int ip_session_cleaned_tcp_sm_5_cnt = 0;
	int ip_session_cleaned_tcp_sm_6_cnt = 0;
	int ip_session_cleaned_tcp_sm_7_cnt = 0;
	int ip_session_cleaned_tcp_sm_8_cnt = 0;
	int ip_session_cleaned_tcp_sm_9_cnt = 0;
	int ip_session_cleaned_tcp_sm_10_cnt = 0;
	int ip_session_cleaned_tcp_sm_11_cnt = 0;
	int ip_session_cleaned_tcp_sm_12_cnt = 0;
	int ip_session_cleaned_tcp_sm_13_cnt = 0;
	int ip_session_cleaned_tcp_sm_14_cnt = 0;
	int ip_session_cleaned_tcp_sm_15_cnt = 0;
	int ip_session_cleaned_tcp_sm_16_cnt = 0;
	int ip_session_cleaned_tcp_sm_17_cnt = 0;
	int ip_session_cleaned_tcp_sm_18_cnt = 0;
	int ip_session_cleaned_tcp_sm_19_cnt = 0;
	int ip_session_cleaned_tcp_sm_20_cnt = 0;
	int ip_session_cleaned_tcp_sm_21_cnt = 0;
	int ip_session_cleaned_tcp_sm_22_cnt = 0;
	int ip_session_cleaned_tcp_sm_23_cnt = 0;
	int ip_session_cleaned_tcp_sm_24_cnt = 0;
	int ip_session_cleaned_tcp_sm_25_cnt = 0;
	int ip_session_cleaned_tcp_sm_26_cnt = 0;
	int ip_session_cleaned_tcp_sm_27_cnt = 0;
	int ip_session_cleaned_tcp_sm_28_cnt = 0;
	int ip_session_cleaned_tcp_sm_29_cnt = 0;

	int ip_session_cleaned_udp_sm_0_cnt = 0;
	int ip_session_cleaned_udp_sm_1_cnt = 0;
	int ip_session_cleaned_udp_sm_2_cnt = 0;
	int ip_session_cleaned_udp_sm_3_cnt = 0;
	int ip_session_cleaned_udp_sm_4_cnt = 0;
	int ip_session_cleaned_udp_sm_5_cnt = 0;
	int ip_session_cleaned_udp_sm_6_cnt = 0;
	int ip_session_cleaned_udp_sm_7_cnt = 0;
	int ip_session_cleaned_udp_sm_8_cnt = 0;
	int ip_session_cleaned_udp_sm_9_cnt = 0;
	int ip_session_cleaned_udp_sm_10_cnt = 0;
	int ip_session_cleaned_udp_sm_11_cnt = 0;
	int ip_session_cleaned_udp_sm_12_cnt = 0;
	int ip_session_cleaned_udp_sm_13_cnt = 0;
	int ip_session_cleaned_udp_sm_14_cnt = 0;
	int ip_session_cleaned_udp_sm_15_cnt = 0;
	int ip_session_cleaned_udp_sm_16_cnt = 0;
	int ip_session_cleaned_udp_sm_17_cnt = 0;
	int ip_session_cleaned_udp_sm_18_cnt = 0;
	int ip_session_cleaned_udp_sm_19_cnt = 0;
	int ip_session_cleaned_udp_sm_20_cnt = 0;
	int ip_session_cleaned_udp_sm_21_cnt = 0;
	int ip_session_cleaned_udp_sm_22_cnt = 0;
	int ip_session_cleaned_udp_sm_23_cnt = 0;
	int ip_session_cleaned_udp_sm_24_cnt = 0;
	int ip_session_cleaned_udp_sm_25_cnt = 0;
	int ip_session_cleaned_udp_sm_26_cnt = 0;
	int ip_session_cleaned_udp_sm_27_cnt = 0;
	int ip_session_cleaned_udp_sm_28_cnt = 0;
	int ip_session_cleaned_udp_sm_29_cnt = 0;

	int ip_session_pool_sm_0_cnt = 0;
	int ip_session_pool_sm_1_cnt = 0;
	int ip_session_pool_sm_2_cnt = 0;
	int ip_session_pool_sm_3_cnt = 0;
	int ip_session_pool_sm_4_cnt = 0;
	int ip_session_pool_sm_5_cnt = 0;
	int ip_session_pool_sm_6_cnt = 0;
	int ip_session_pool_sm_7_cnt = 0;
	int ip_session_pool_sm_8_cnt = 0;
	int ip_session_pool_sm_9_cnt = 0;
	int ip_session_pool_sm_10_cnt = 0;
	int ip_session_pool_sm_11_cnt = 0;
	int ip_session_pool_sm_12_cnt = 0;
	int ip_session_pool_sm_13_cnt = 0;
	int ip_session_pool_sm_14_cnt = 0;
	int ip_session_pool_sm_15_cnt = 0;
	int ip_session_pool_sm_16_cnt = 0;
	int ip_session_pool_sm_17_cnt = 0;
	int ip_session_pool_sm_18_cnt = 0;
	int ip_session_pool_sm_19_cnt = 0;
	int ip_session_pool_sm_20_cnt = 0;
	int ip_session_pool_sm_21_cnt = 0;
	int ip_session_pool_sm_22_cnt = 0;
	int ip_session_pool_sm_23_cnt = 0;
	int ip_session_pool_sm_24_cnt = 0;
	int ip_session_pool_sm_25_cnt = 0;
	int ip_session_pool_sm_26_cnt = 0;
	int ip_session_pool_sm_27_cnt = 0;
	int ip_session_pool_sm_28_cnt = 0;
	int ip_session_pool_sm_29_cnt = 0;

}

namespace IPGlobal
{
	uint32_t	SM_PKT_LIMIT			= 0;
	uint64_t	CURRENT_EPOCH_SEC 		= 0;
	uint64_t	CURRENT_EPOCH_MICRO_SEC = 0;
	uint16_t	CURRENT_SEC 			= 0;
	uint16_t	CURRENT_HOUR 			= 0;
	uint16_t	CURRENT_MIN 			= 0;
	uint16_t	CURRENT_DAY 			= 0;
	uint16_t	CURRENT_MONTH 			= 0;
	uint16_t	CURRENT_YEAR			= 0;
	uint128_t 	CURRENT_EPOCH_NANO_SEC 	= 0;
	uint64_t 	CURRENT_EPOCH_MILI_SEC 	= 0;

	BOOL	PROBE_RUNNING_STATUS = true;
	BOOL	PKT_LISTENER_RUNNING_STATUS[MAX_INTERFACE_SUPPORT];
	BOOL	PKT_LISTENER_INTF_MON_RUNNING_STATUS[MAX_INTERFACE_SUPPORT];
	BOOL	PKT_LISTENER_DAYCHANGE_INDICATION[MAX_INTERFACE_SUPPORT];
	BOOL	PKT_ROUTER_RUNNING_STATUS[MAX_INTERFACE_SUPPORT][MAX_ROUTER_PER_INTERFACE_SUPPORT];

	BOOL	S11_SESSION_MANAGER_RUNNING_STATUS[MAX_S11_SESSION_MANAGER_SUPPORT];
	int		S11_SESSION_MANAGER_INSTANCES = 0;
	int		S11_SESSION_MANAGER_CPU_CORE[MAX_S11_SESSION_MANAGER_SUPPORT] = {0,0,0,0};
	BOOL	S11_SESSION_MANAGER_SHUTDOWN_STATUS[MAX_S11_SESSION_MANAGER_SUPPORT] = {false, false, false, false};
	int		S11_FLUSHER_NO = 0;
	int		S11_FLUSHER_CPU_CORE = 0;
	BOOL	S11_WRITE_XDR = false;
	int 	S11_XDR_WRITE_CPU_CORE = 0;
	string  S11_FILE_PREFIX;
	BOOL	S11_FLUSHER_RUNNING_STATUS = true;
	BOOL	S11_XDR_FLUSHER_RUNNING_STATUS = true;
	int		S11_IDLE_SESSION_TIMEOUT_IN_SEC = 60;

	BOOL	S5S8_SESSION_MANAGER_RUNNING_STATUS[MAX_S5S8_SESSION_MANAGER_SUPPORT];
	int		S5S8_SESSION_MANAGER_INSTANCES = 0;
	int		S5S8_SESSION_MANAGER_CPU_CORE[MAX_S5S8_SESSION_MANAGER_SUPPORT] = {0,0,0,0};
	BOOL	S5S8_SESSION_MANAGER_SHUTDOWN_STATUS[MAX_S5S8_SESSION_MANAGER_SUPPORT] = {false, false, false, false};
	int		S5S8_FLUSHER_NO = 0;
	int		S5S8_FLUSHER_CPU_CORE = 0;
	BOOL	S5S8_WRITE_XDR = false;
	int 	S5S8_XDR_WRITE_CPU_CORE = 0;
	string  S5S8_FILE_PREFIX;
	BOOL	S5S8_FLUSHER_RUNNING_STATUS = true;
	BOOL	S5S8_XDR_FLUSHER_RUNNING_STATUS = true;
	int		S5S8_IDLE_SESSION_TIMEOUT_IN_SEC = 60;

	BOOL	S1MME_SESSION_MANAGER_RUNNING_STATUS[MAX_S1MME_SESSION_MANAGER_SUPPORT];
	int		S1MME_SESSION_MANAGER_INSTANCES = 0;
	int		S1MME_SESSION_MANAGER_CPU_CORE[MAX_S1MME_SESSION_MANAGER_SUPPORT] = {0,0,0,0};
	BOOL	S1MME_SESSION_MANAGER_SHUTDOWN_STATUS[MAX_S1MME_SESSION_MANAGER_SUPPORT] = {false, false, false, false};
	int		S1MME_FLUSHER_NO = 0;
	int		S1MME_FLUSHER_CPU_CORE = 0;
	BOOL	S1MME_WRITE_XDR = false;
	int 	S1MME_XDR_WRITE_CPU_CORE = 0;
	string  S1MME_FILE_PREFIX;
	BOOL	S1MME_FLUSHER_RUNNING_STATUS = true;
	BOOL	S1MME_XDR_FLUSHER_RUNNING_STATUS = true;
	int 	S1MME_ACTIVE_SESSIONS[MAX_S1MME_SESSION_MANAGER_SUPPORT] = {0,0,0,0};
	int 	S1MME_CLEANED_SESSIONS[MAX_S1MME_SESSION_MANAGER_SUPPORT] = {0,0,0,0};

	int 	S1AP_ATTACH_SESSIONS_TODAY[MAX_S1MME_SESSION_MANAGER_SUPPORT] = {0,0,0,0};
	int 	S1AP_TAU_SESSIONS_TODAY[MAX_S1MME_SESSION_MANAGER_SUPPORT] = {0,0,0,0};
	int 	S1AP_HANDOVERS_TODAY[MAX_S1MME_SESSION_MANAGER_SUPPORT] = {0,0,0,0};

	BOOL	S1U_SESSION_MANAGER_RUNNING_STATUS[MAX_IP_SESSION_MANAGER_SUPPORT];
	int		S1U_SESSION_MANAGER_INSTANCES = 0;
	int		S1U_SESSION_MANAGER_CPU_CORE[MAX_IP_SESSION_MANAGER_SUPPORT] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	BOOL	S1U_SESSION_MANAGER_SHUTDOWN_STATUS[MAX_IP_SESSION_MANAGER_SUPPORT] = {false, false, false, false,false, false, false, false,false, false,
																				   false, false,false, false, false, false,false, false, false, false,
																				   false, false,false, false, false, false,false, false, false, false};
	int		S1U_FLUSHER_NO = 0;
	int		S1U_FLUSHER_CPU_CORE[4] = {0,0,0,0};
	BOOL	S1U_WRITE_XDR = false;
	int 	S1U_XDR_WRITE_CPU_CORE = 0;
	string  S1U_FILE_PREFIX;
	BOOL	S1U_FLUSHER_RUNNING_STATUS = true;
	BOOL	S1U_XDR_FLUSHER_RUNNING_STATUS = true;
	int 	S1U_SESSION_TIME_INDEX_PKT_LIMIT	= 120000;
	int		S1U_SESSION_PKT_LIMIT 				= 5000;
	int 	S1U_SESSION_TIME_LIMIT 				= 900;
	int 	S1U_SESSION_CLEAN_UP_SCAN_FREQ_SEC 	= 15;
	int 	S1U_SESSION_CLEAN_UP_BATCH_LIMIT 	= 20000;
	int		S1U_SESSION_CLEAN_UP_TIMEOUT_SEC    = 120;

	int 	S1U_VPS_PACKET_PER_SEC					= 1000;
	BOOL 	S1U_UDP_XDR_FOR_DNS 					= false;
	int 	S1U_DNS_ANSWER 							= 2;
	int 	DNS_LOOKUPDB_CLEAN_UP_TIMEOUT_SEC	= 900;
	int 	DNS_KEY_TIME_LIMIT_SEC 				= 20;
	BOOL	DNS_FLUSHER_RUNNING_STATUS = true;
	BOOL	DNS_XDR_FLUSHER_RUNNING_STATUS = true;
	int		DNS_FLUSHER_NO = 0;
	int		DNS_FLUSHER_CPU_CORE[4] = {0,0,0,0};
	BOOL	DNS_WRITE_XDR = false;
	int 	DNS_XDR_WRITE_CPU_CORE = 0;
	string  DNS_FILE_PREFIX;

	ULONG	IPV4_RANGE[35][2]	= {{0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0}};
	int		IPV4_NO_OF_RANGE = 0;

	int		GN_GTPC_GLOBAL_SESSION_CLEANUP_TIMEOUT_SEC = 21600;

	BOOL	PROBE_STATS_RUNNING_STATUS = true;



	int 	ACTIVE_S1U_IP_SESSIONS[MAX_IP_SESSION_MANAGER_SUPPORT] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	int 	ACTIVE_S1U_DNS_SESSIONS[MAX_IP_SESSION_MANAGER_SUPPORT] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

	int 	CLEANED_S1U_IP_SESSIONS[MAX_IP_SESSION_MANAGER_SUPPORT] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	int 	CLEANED_S1U_DNS_SESSIONS[MAX_IP_SESSION_MANAGER_SUPPORT] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

	int 	PROBE_ID;
	bool 	PRINT_STATS = false;
	int 	PRINT_STATS_FREQ_SEC = 1;
	int		LOG_STATS_FREQ_SEC = 1;

	int		NO_OF_NIC_INTERFACE = 0;
	int		NO_OF_SOLAR_INTERFACE = 0;
	int 	NO_OF_INTERFACES = 0;

	BOOL	S1U_PROCESS_OUT_OF_RANGE_IP = false;
	BOOL	S1U_PROCESS_USER_AGENT = false;
	BOOL	S1U_CHECK_DUPLICATE = false;
	BOOL	S1U_PROCESS_ACK = false;
	BOOL	S1U_ACK_CREATE_SESSION = false;

	long	PACKET_COUNT = 0;

	string	PACKET_DISTRIBUTION_DESC[2] = {"IP Based", "Port Based"};
	string 	ETHERNET_INTERFACES[MAX_INTERFACE_SUPPORT] 		= {"","","","","","","",""};
	string 	SOLAR_INTERFACES[MAX_INTERFACE_SUPPORT] 		= {"","","","","","","",""};
	string 	PNAME[MAX_INTERFACE_SUPPORT] = {"","","","","","","",""};
	int 	ROUTER_PER_INTERFACE[MAX_INTERFACE_SUPPORT] 	= {0,0,0,0,0,0,0,0};
	int		PKT_LISTENER_CPU_CORE[MAX_INTERFACE_SUPPORT]	= {0,0,0,0,0,0,0,0};
	int		PKT_ROUTER_CPU_CORE[MAX_INTERFACE_SUPPORT][MAX_ROUTER_PER_INTERFACE_SUPPORT] = {
																			{0,0,0,0,0,0,0,0},
																			{0,0,0,0,0,0,0,0},
																			{0,0,0,0,0,0,0,0},
																			{0,0,0,0,0,0,0,0},
																			{0,0,0,0,0,0,0,0},
																			{0,0,0,0,0,0,0,0},
																			{0,0,0,0,0,0,0,0},
																			{0,0,0,0,0,0,0,0}};
	int		PKT_TIME_INDEX = 10;
	int 	PPS_PER_INTERFACE[MAX_INTERFACE_SUPPORT] 		= {500000,500000,500000,500000,500000,500000,500000,500000};
	int		PPS_CAP_PERCENTAGE[MAX_INTERFACE_SUPPORT]		= {50,50,50,50,50,50,50,50};
	int 	SGSN_PC[10]										= {0,0,0,0,0,0,0,0,0,0};
	int		NO_OF_SGSN = 0;
	int		SOLARFLARE_HW_TIMESTAMP = 0;
	int 	MAX_BW_INTERFACE[MAX_INTERFACE_SUPPORT]			= {0,0,0,0,0,0,0,0};

	uint32_t	MME_RANGE[15][2]	= {{0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0}};
	uint16_t	MME_NO_OF_RANGE = 0;

	uint32_t	PGW_RANGE[15][2]	= {{0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0}};
	uint16_t	PGW_NO_OF_RANGE = 0;

	bool	PROCESS_FLAG_i_0 = true;
	bool	PROCESS_FLAG_i_1 = true;
	bool	PROCESS_FLAG_i_2 = true;
	bool	PROCESS_FLAG_i_3 = true;
	bool	PROCESS_FLAG_i_4 = true;
	bool	PROCESS_FLAG_i_5 = true;
	bool	PROCESS_FLAG_i_6 = true;
	bool	PROCESS_FLAG_i_7 = true;

	bool	PACKET_PROCESSING = false;
	bool	ROUTER_PACKET_PROCESSING = true;

	uint32_t PKT_RATE_INTF_0 = 0;
	uint32_t PKT_RATE_INTF_1 = 0;
	uint32_t PKT_RATE_INTF_2 = 0;
	uint32_t PKT_RATE_INTF_3 = 0;
	uint32_t PKT_RATE_INTF_4 = 0;
	uint32_t PKT_RATE_INTF_5 = 0;
	uint32_t PKT_RATE_INTF_6 = 0;
	uint32_t PKT_RATE_INTF_7 = 0;

	uint128_t PKTS_TOTAL_INTF_0 = 0;
	uint128_t PKTS_TOTAL_INTF_1 = 0;
	uint128_t PKTS_TOTAL_INTF_2 = 0;
	uint128_t PKTS_TOTAL_INTF_3 = 0;
	uint128_t PKTS_TOTAL_INTF_4 = 0;
	uint128_t PKTS_TOTAL_INTF_5 = 0;
	uint128_t PKTS_TOTAL_INTF_6 = 0;
	uint128_t PKTS_TOTAL_INTF_7 = 0;

	uint64_t BW_MBPS_INTF_0 = 0;
	uint64_t BW_MBPS_INTF_1 = 0;
	uint64_t BW_MBPS_INTF_2 = 0;
	uint64_t BW_MBPS_INTF_3 = 0;
	uint64_t BW_MBPS_INTF_4 = 0;
	uint64_t BW_MBPS_INTF_5 = 0;
	uint64_t BW_MBPS_INTF_6 = 0;
	uint64_t BW_MBPS_INTF_7 = 0;

	bwData BW_MBPS_i_0_r_0;
	bwData BW_MBPS_i_0_r_1;
	bwData BW_MBPS_i_0_r_2;
	bwData BW_MBPS_i_0_r_3;
	bwData BW_MBPS_i_0_r_4;
	bwData BW_MBPS_i_0_r_5;
	bwData BW_MBPS_i_0_r_6;
	bwData BW_MBPS_i_0_r_7;

	bwData BW_MBPS_i_1_r_0;
	bwData BW_MBPS_i_1_r_1;
	bwData BW_MBPS_i_1_r_2;
	bwData BW_MBPS_i_1_r_3;
	bwData BW_MBPS_i_1_r_4;
	bwData BW_MBPS_i_1_r_5;
	bwData BW_MBPS_i_1_r_6;
	bwData BW_MBPS_i_1_r_7;

	bwData BW_MBPS_i_2_r_0;
	bwData BW_MBPS_i_2_r_1;
	bwData BW_MBPS_i_2_r_2;
	bwData BW_MBPS_i_2_r_3;
	bwData BW_MBPS_i_2_r_4;
	bwData BW_MBPS_i_2_r_5;
	bwData BW_MBPS_i_2_r_6;
	bwData BW_MBPS_i_2_r_7;

	bwData BW_MBPS_i_3_r_0;
	bwData BW_MBPS_i_3_r_1;
	bwData BW_MBPS_i_3_r_2;
	bwData BW_MBPS_i_3_r_3;
	bwData BW_MBPS_i_3_r_4;
	bwData BW_MBPS_i_3_r_5;
	bwData BW_MBPS_i_3_r_6;
	bwData BW_MBPS_i_3_r_7;

	bwData BW_MBPS_i_4_r_0;
	bwData BW_MBPS_i_4_r_1;
	bwData BW_MBPS_i_4_r_2;
	bwData BW_MBPS_i_4_r_3;
	bwData BW_MBPS_i_4_r_4;
	bwData BW_MBPS_i_4_r_5;
	bwData BW_MBPS_i_4_r_6;
	bwData BW_MBPS_i_4_r_7;

	bwData BW_MBPS_i_5_r_0;
	bwData BW_MBPS_i_5_r_1;
	bwData BW_MBPS_i_5_r_2;
	bwData BW_MBPS_i_5_r_3;
	bwData BW_MBPS_i_5_r_4;
	bwData BW_MBPS_i_5_r_5;
	bwData BW_MBPS_i_5_r_6;
	bwData BW_MBPS_i_5_r_7;

	bwData BW_MBPS_i_6_r_0;
	bwData BW_MBPS_i_6_r_1;
	bwData BW_MBPS_i_6_r_2;
	bwData BW_MBPS_i_6_r_3;
	bwData BW_MBPS_i_6_r_4;
	bwData BW_MBPS_i_6_r_5;
	bwData BW_MBPS_i_6_r_6;
	bwData BW_MBPS_i_6_r_7;

	bwData BW_MBPS_i_7_r_0;
	bwData BW_MBPS_i_7_r_1;
	bwData BW_MBPS_i_7_r_2;
	bwData BW_MBPS_i_7_r_3;
	bwData BW_MBPS_i_7_r_4;
	bwData BW_MBPS_i_7_r_5;
	bwData BW_MBPS_i_7_r_6;
	bwData BW_MBPS_i_7_r_7;

    ULONG	 	t_FrameCount = 0;
	fstream 	IPXdrHandler;
	fstream 	bwLogHandler;

    uint16_t	logLevel;

    uint64_t ip_discarded_large_packets_i_0;
    uint64_t ip_discarded_large_packets_i_1;
    uint64_t ip_discarded_large_packets_i_2;
    uint64_t ip_discarded_large_packets_i_3;
    uint64_t ip_discarded_large_packets_i_4;
    uint64_t ip_discarded_large_packets_i_5;
    uint64_t ip_discarded_large_packets_i_6;
    uint64_t ip_discarded_large_packets_i_7;

	string	ADMIN_PORT;
	BOOL	ADMIN_FLAG = false;
	BOOL	UPDATE_IP_RANGE = false;

	int		MAX_PKT_LEN_PER_INTERFACE[MAX_INTERFACE_SUPPORT];
	int		DNS_DUMP_HOUR = 4;

	/* Operator Name */
	string 	OPERATOR_NAME[MAX_OPERATOR] = {
						"OfficeLab",
						"Airtel",
						"Spectranet",
						"Link3",
						"Bsnl",
						"IndosatM2",
						"BhutanTelecom",
						"Subisu",
						"TataSkyBB",
						"NA",
						"NA",
						"NA",
						"NA",
						"NA",
						"NA"};
}

namespace PKTStore
{
	/* Interface_0 */
	std::unordered_map<long, RawPkt*> pktRepository_i_0_r_0_t_0;
	std::unordered_map<long, RawPkt*> pktRepository_i_0_r_0_t_1;
	std::unordered_map<long, RawPkt*> pktRepository_i_0_r_0_t_2;
	std::unordered_map<long, RawPkt*> pktRepository_i_0_r_0_t_3;
	std::unordered_map<long, RawPkt*> pktRepository_i_0_r_0_t_4;
	std::unordered_map<long, RawPkt*> pktRepository_i_0_r_0_t_5;
	std::unordered_map<long, RawPkt*> pktRepository_i_0_r_0_t_6;
	std::unordered_map<long, RawPkt*> pktRepository_i_0_r_0_t_7;
	std::unordered_map<long, RawPkt*> pktRepository_i_0_r_0_t_8;
	std::unordered_map<long, RawPkt*> pktRepository_i_0_r_0_t_9;

	long pktRepository_i_0_r_0_t_0_cnt = 0;
	long pktRepository_i_0_r_0_t_1_cnt = 0;
	long pktRepository_i_0_r_0_t_2_cnt = 0;
	long pktRepository_i_0_r_0_t_3_cnt = 0;
	long pktRepository_i_0_r_0_t_4_cnt = 0;
	long pktRepository_i_0_r_0_t_5_cnt = 0;
	long pktRepository_i_0_r_0_t_6_cnt = 0;
	long pktRepository_i_0_r_0_t_7_cnt = 0;
	long pktRepository_i_0_r_0_t_8_cnt = 0;
	long pktRepository_i_0_r_0_t_9_cnt = 0;

	bool pktRepository_i_0_r_0_t_0_busy = false;
	bool pktRepository_i_0_r_0_t_1_busy = false;
	bool pktRepository_i_0_r_0_t_2_busy = false;
	bool pktRepository_i_0_r_0_t_3_busy = false;
	bool pktRepository_i_0_r_0_t_4_busy = false;
	bool pktRepository_i_0_r_0_t_5_busy = false;
	bool pktRepository_i_0_r_0_t_6_busy = false;
	bool pktRepository_i_0_r_0_t_7_busy = false;
	bool pktRepository_i_0_r_0_t_8_busy = false;
	bool pktRepository_i_0_r_0_t_9_busy = false;

	std::unordered_map<long, RawPkt*> pktRepository_i_0_r_1_t_0;
	std::unordered_map<long, RawPkt*> pktRepository_i_0_r_1_t_1;
	std::unordered_map<long, RawPkt*> pktRepository_i_0_r_1_t_2;
	std::unordered_map<long, RawPkt*> pktRepository_i_0_r_1_t_3;
	std::unordered_map<long, RawPkt*> pktRepository_i_0_r_1_t_4;
	std::unordered_map<long, RawPkt*> pktRepository_i_0_r_1_t_5;
	std::unordered_map<long, RawPkt*> pktRepository_i_0_r_1_t_6;
	std::unordered_map<long, RawPkt*> pktRepository_i_0_r_1_t_7;
	std::unordered_map<long, RawPkt*> pktRepository_i_0_r_1_t_8;
	std::unordered_map<long, RawPkt*> pktRepository_i_0_r_1_t_9;

	long pktRepository_i_0_r_1_t_0_cnt = 0;
	long pktRepository_i_0_r_1_t_1_cnt = 0;
	long pktRepository_i_0_r_1_t_2_cnt = 0;
	long pktRepository_i_0_r_1_t_3_cnt = 0;
	long pktRepository_i_0_r_1_t_4_cnt = 0;
	long pktRepository_i_0_r_1_t_5_cnt = 0;
	long pktRepository_i_0_r_1_t_6_cnt = 0;
	long pktRepository_i_0_r_1_t_7_cnt = 0;
	long pktRepository_i_0_r_1_t_8_cnt = 0;
	long pktRepository_i_0_r_1_t_9_cnt = 0;

	bool pktRepository_i_0_r_1_t_0_busy = false;
	bool pktRepository_i_0_r_1_t_1_busy = false;
	bool pktRepository_i_0_r_1_t_2_busy = false;
	bool pktRepository_i_0_r_1_t_3_busy = false;
	bool pktRepository_i_0_r_1_t_4_busy = false;
	bool pktRepository_i_0_r_1_t_5_busy = false;
	bool pktRepository_i_0_r_1_t_6_busy = false;
	bool pktRepository_i_0_r_1_t_7_busy = false;
	bool pktRepository_i_0_r_1_t_8_busy = false;
	bool pktRepository_i_0_r_1_t_9_busy = false;

	std::unordered_map<long, RawPkt*> pktRepository_i_0_r_2_t_0;
	std::unordered_map<long, RawPkt*> pktRepository_i_0_r_2_t_1;
	std::unordered_map<long, RawPkt*> pktRepository_i_0_r_2_t_2;
	std::unordered_map<long, RawPkt*> pktRepository_i_0_r_2_t_3;
	std::unordered_map<long, RawPkt*> pktRepository_i_0_r_2_t_4;
	std::unordered_map<long, RawPkt*> pktRepository_i_0_r_2_t_5;
	std::unordered_map<long, RawPkt*> pktRepository_i_0_r_2_t_6;
	std::unordered_map<long, RawPkt*> pktRepository_i_0_r_2_t_7;
	std::unordered_map<long, RawPkt*> pktRepository_i_0_r_2_t_8;
	std::unordered_map<long, RawPkt*> pktRepository_i_0_r_2_t_9;

	long pktRepository_i_0_r_2_t_0_cnt = 0;
	long pktRepository_i_0_r_2_t_1_cnt = 0;
	long pktRepository_i_0_r_2_t_2_cnt = 0;
	long pktRepository_i_0_r_2_t_3_cnt = 0;
	long pktRepository_i_0_r_2_t_4_cnt = 0;
	long pktRepository_i_0_r_2_t_5_cnt = 0;
	long pktRepository_i_0_r_2_t_6_cnt = 0;
	long pktRepository_i_0_r_2_t_7_cnt = 0;
	long pktRepository_i_0_r_2_t_8_cnt = 0;
	long pktRepository_i_0_r_2_t_9_cnt = 0;

	bool pktRepository_i_0_r_2_t_0_busy = false;
	bool pktRepository_i_0_r_2_t_1_busy = false;
	bool pktRepository_i_0_r_2_t_2_busy = false;
	bool pktRepository_i_0_r_2_t_3_busy = false;
	bool pktRepository_i_0_r_2_t_4_busy = false;
	bool pktRepository_i_0_r_2_t_5_busy = false;
	bool pktRepository_i_0_r_2_t_6_busy = false;
	bool pktRepository_i_0_r_2_t_7_busy = false;
	bool pktRepository_i_0_r_2_t_8_busy = false;
	bool pktRepository_i_0_r_2_t_9_busy = false;

	std::unordered_map<long, RawPkt*> pktRepository_i_0_r_3_t_0;
	std::unordered_map<long, RawPkt*> pktRepository_i_0_r_3_t_1;
	std::unordered_map<long, RawPkt*> pktRepository_i_0_r_3_t_2;
	std::unordered_map<long, RawPkt*> pktRepository_i_0_r_3_t_3;
	std::unordered_map<long, RawPkt*> pktRepository_i_0_r_3_t_4;
	std::unordered_map<long, RawPkt*> pktRepository_i_0_r_3_t_5;
	std::unordered_map<long, RawPkt*> pktRepository_i_0_r_3_t_6;
	std::unordered_map<long, RawPkt*> pktRepository_i_0_r_3_t_7;
	std::unordered_map<long, RawPkt*> pktRepository_i_0_r_3_t_8;
	std::unordered_map<long, RawPkt*> pktRepository_i_0_r_3_t_9;

	long pktRepository_i_0_r_3_t_0_cnt = 0;
	long pktRepository_i_0_r_3_t_1_cnt = 0;
	long pktRepository_i_0_r_3_t_2_cnt = 0;
	long pktRepository_i_0_r_3_t_3_cnt = 0;
	long pktRepository_i_0_r_3_t_4_cnt = 0;
	long pktRepository_i_0_r_3_t_5_cnt = 0;
	long pktRepository_i_0_r_3_t_6_cnt = 0;
	long pktRepository_i_0_r_3_t_7_cnt = 0;
	long pktRepository_i_0_r_3_t_8_cnt = 0;
	long pktRepository_i_0_r_3_t_9_cnt = 0;

	bool pktRepository_i_0_r_3_t_0_busy = false;
	bool pktRepository_i_0_r_3_t_1_busy = false;
	bool pktRepository_i_0_r_3_t_2_busy = false;
	bool pktRepository_i_0_r_3_t_3_busy = false;
	bool pktRepository_i_0_r_3_t_4_busy = false;
	bool pktRepository_i_0_r_3_t_5_busy = false;
	bool pktRepository_i_0_r_3_t_6_busy = false;
	bool pktRepository_i_0_r_3_t_7_busy = false;
	bool pktRepository_i_0_r_3_t_8_busy = false;
	bool pktRepository_i_0_r_3_t_9_busy = false;

	std::unordered_map<long, RawPkt*> pktRepository_i_0_r_4_t_0;
	std::unordered_map<long, RawPkt*> pktRepository_i_0_r_4_t_1;
	std::unordered_map<long, RawPkt*> pktRepository_i_0_r_4_t_2;
	std::unordered_map<long, RawPkt*> pktRepository_i_0_r_4_t_3;
	std::unordered_map<long, RawPkt*> pktRepository_i_0_r_4_t_4;
	std::unordered_map<long, RawPkt*> pktRepository_i_0_r_4_t_5;
	std::unordered_map<long, RawPkt*> pktRepository_i_0_r_4_t_6;
	std::unordered_map<long, RawPkt*> pktRepository_i_0_r_4_t_7;
	std::unordered_map<long, RawPkt*> pktRepository_i_0_r_4_t_8;
	std::unordered_map<long, RawPkt*> pktRepository_i_0_r_4_t_9;

	long pktRepository_i_0_r_4_t_0_cnt = 0;
	long pktRepository_i_0_r_4_t_1_cnt = 0;
	long pktRepository_i_0_r_4_t_2_cnt = 0;
	long pktRepository_i_0_r_4_t_3_cnt = 0;
	long pktRepository_i_0_r_4_t_4_cnt = 0;
	long pktRepository_i_0_r_4_t_5_cnt = 0;
	long pktRepository_i_0_r_4_t_6_cnt = 0;
	long pktRepository_i_0_r_4_t_7_cnt = 0;
	long pktRepository_i_0_r_4_t_8_cnt = 0;
	long pktRepository_i_0_r_4_t_9_cnt = 0;

	bool pktRepository_i_0_r_4_t_0_busy = false;
	bool pktRepository_i_0_r_4_t_1_busy = false;
	bool pktRepository_i_0_r_4_t_2_busy = false;
	bool pktRepository_i_0_r_4_t_3_busy = false;
	bool pktRepository_i_0_r_4_t_4_busy = false;
	bool pktRepository_i_0_r_4_t_5_busy = false;
	bool pktRepository_i_0_r_4_t_6_busy = false;
	bool pktRepository_i_0_r_4_t_7_busy = false;
	bool pktRepository_i_0_r_4_t_8_busy = false;
	bool pktRepository_i_0_r_4_t_9_busy = false;

	std::unordered_map<long, RawPkt*> pktRepository_i_0_r_5_t_0;
	std::unordered_map<long, RawPkt*> pktRepository_i_0_r_5_t_1;
	std::unordered_map<long, RawPkt*> pktRepository_i_0_r_5_t_2;
	std::unordered_map<long, RawPkt*> pktRepository_i_0_r_5_t_3;
	std::unordered_map<long, RawPkt*> pktRepository_i_0_r_5_t_4;
	std::unordered_map<long, RawPkt*> pktRepository_i_0_r_5_t_5;
	std::unordered_map<long, RawPkt*> pktRepository_i_0_r_5_t_6;
	std::unordered_map<long, RawPkt*> pktRepository_i_0_r_5_t_7;
	std::unordered_map<long, RawPkt*> pktRepository_i_0_r_5_t_8;
	std::unordered_map<long, RawPkt*> pktRepository_i_0_r_5_t_9;

	long pktRepository_i_0_r_5_t_0_cnt = 0;
	long pktRepository_i_0_r_5_t_1_cnt = 0;
	long pktRepository_i_0_r_5_t_2_cnt = 0;
	long pktRepository_i_0_r_5_t_3_cnt = 0;
	long pktRepository_i_0_r_5_t_4_cnt = 0;
	long pktRepository_i_0_r_5_t_5_cnt = 0;
	long pktRepository_i_0_r_5_t_6_cnt = 0;
	long pktRepository_i_0_r_5_t_7_cnt = 0;
	long pktRepository_i_0_r_5_t_8_cnt = 0;
	long pktRepository_i_0_r_5_t_9_cnt = 0;

	bool pktRepository_i_0_r_5_t_0_busy = false;
	bool pktRepository_i_0_r_5_t_1_busy = false;
	bool pktRepository_i_0_r_5_t_2_busy = false;
	bool pktRepository_i_0_r_5_t_3_busy = false;
	bool pktRepository_i_0_r_5_t_4_busy = false;
	bool pktRepository_i_0_r_5_t_5_busy = false;
	bool pktRepository_i_0_r_5_t_6_busy = false;
	bool pktRepository_i_0_r_5_t_7_busy = false;
	bool pktRepository_i_0_r_5_t_8_busy = false;
	bool pktRepository_i_0_r_5_t_9_busy = false;

	std::unordered_map<long, RawPkt*> pktRepository_i_0_r_6_t_0;
	std::unordered_map<long, RawPkt*> pktRepository_i_0_r_6_t_1;
	std::unordered_map<long, RawPkt*> pktRepository_i_0_r_6_t_2;
	std::unordered_map<long, RawPkt*> pktRepository_i_0_r_6_t_3;
	std::unordered_map<long, RawPkt*> pktRepository_i_0_r_6_t_4;
	std::unordered_map<long, RawPkt*> pktRepository_i_0_r_6_t_5;
	std::unordered_map<long, RawPkt*> pktRepository_i_0_r_6_t_6;
	std::unordered_map<long, RawPkt*> pktRepository_i_0_r_6_t_7;
	std::unordered_map<long, RawPkt*> pktRepository_i_0_r_6_t_8;
	std::unordered_map<long, RawPkt*> pktRepository_i_0_r_6_t_9;

	long pktRepository_i_0_r_6_t_0_cnt = 0;
	long pktRepository_i_0_r_6_t_1_cnt = 0;
	long pktRepository_i_0_r_6_t_2_cnt = 0;
	long pktRepository_i_0_r_6_t_3_cnt = 0;
	long pktRepository_i_0_r_6_t_4_cnt = 0;
	long pktRepository_i_0_r_6_t_5_cnt = 0;
	long pktRepository_i_0_r_6_t_6_cnt = 0;
	long pktRepository_i_0_r_6_t_7_cnt = 0;
	long pktRepository_i_0_r_6_t_8_cnt = 0;
	long pktRepository_i_0_r_6_t_9_cnt = 0;

	bool pktRepository_i_0_r_6_t_0_busy = false;
	bool pktRepository_i_0_r_6_t_1_busy = false;
	bool pktRepository_i_0_r_6_t_2_busy = false;
	bool pktRepository_i_0_r_6_t_3_busy = false;
	bool pktRepository_i_0_r_6_t_4_busy = false;
	bool pktRepository_i_0_r_6_t_5_busy = false;
	bool pktRepository_i_0_r_6_t_6_busy = false;
	bool pktRepository_i_0_r_6_t_7_busy = false;
	bool pktRepository_i_0_r_6_t_8_busy = false;
	bool pktRepository_i_0_r_6_t_9_busy = false;

	std::unordered_map<long, RawPkt*> pktRepository_i_0_r_7_t_0;
	std::unordered_map<long, RawPkt*> pktRepository_i_0_r_7_t_1;
	std::unordered_map<long, RawPkt*> pktRepository_i_0_r_7_t_2;
	std::unordered_map<long, RawPkt*> pktRepository_i_0_r_7_t_3;
	std::unordered_map<long, RawPkt*> pktRepository_i_0_r_7_t_4;
	std::unordered_map<long, RawPkt*> pktRepository_i_0_r_7_t_5;
	std::unordered_map<long, RawPkt*> pktRepository_i_0_r_7_t_6;
	std::unordered_map<long, RawPkt*> pktRepository_i_0_r_7_t_7;
	std::unordered_map<long, RawPkt*> pktRepository_i_0_r_7_t_8;
	std::unordered_map<long, RawPkt*> pktRepository_i_0_r_7_t_9;

	long pktRepository_i_0_r_7_t_0_cnt = 0;
	long pktRepository_i_0_r_7_t_1_cnt = 0;
	long pktRepository_i_0_r_7_t_2_cnt = 0;
	long pktRepository_i_0_r_7_t_3_cnt = 0;
	long pktRepository_i_0_r_7_t_4_cnt = 0;
	long pktRepository_i_0_r_7_t_5_cnt = 0;
	long pktRepository_i_0_r_7_t_6_cnt = 0;
	long pktRepository_i_0_r_7_t_7_cnt = 0;
	long pktRepository_i_0_r_7_t_8_cnt = 0;
	long pktRepository_i_0_r_7_t_9_cnt = 0;

	bool pktRepository_i_0_r_7_t_0_busy = false;
	bool pktRepository_i_0_r_7_t_1_busy = false;
	bool pktRepository_i_0_r_7_t_2_busy = false;
	bool pktRepository_i_0_r_7_t_3_busy = false;
	bool pktRepository_i_0_r_7_t_4_busy = false;
	bool pktRepository_i_0_r_7_t_5_busy = false;
	bool pktRepository_i_0_r_7_t_6_busy = false;
	bool pktRepository_i_0_r_7_t_7_busy = false;
	bool pktRepository_i_0_r_7_t_8_busy = false;
	bool pktRepository_i_0_r_7_t_9_busy = false;

	/* Interface_1 */

	std::unordered_map<long, RawPkt*> pktRepository_i_1_r_0_t_0;
	std::unordered_map<long, RawPkt*> pktRepository_i_1_r_0_t_1;
	std::unordered_map<long, RawPkt*> pktRepository_i_1_r_0_t_2;
	std::unordered_map<long, RawPkt*> pktRepository_i_1_r_0_t_3;
	std::unordered_map<long, RawPkt*> pktRepository_i_1_r_0_t_4;
	std::unordered_map<long, RawPkt*> pktRepository_i_1_r_0_t_5;
	std::unordered_map<long, RawPkt*> pktRepository_i_1_r_0_t_6;
	std::unordered_map<long, RawPkt*> pktRepository_i_1_r_0_t_7;
	std::unordered_map<long, RawPkt*> pktRepository_i_1_r_0_t_8;
	std::unordered_map<long, RawPkt*> pktRepository_i_1_r_0_t_9;

	long pktRepository_i_1_r_0_t_0_cnt = 0;
	long pktRepository_i_1_r_0_t_1_cnt = 0;
	long pktRepository_i_1_r_0_t_2_cnt = 0;
	long pktRepository_i_1_r_0_t_3_cnt = 0;
	long pktRepository_i_1_r_0_t_4_cnt = 0;
	long pktRepository_i_1_r_0_t_5_cnt = 0;
	long pktRepository_i_1_r_0_t_6_cnt = 0;
	long pktRepository_i_1_r_0_t_7_cnt = 0;
	long pktRepository_i_1_r_0_t_8_cnt = 0;
	long pktRepository_i_1_r_0_t_9_cnt = 0;

	bool pktRepository_i_1_r_0_t_0_busy = false;
	bool pktRepository_i_1_r_0_t_1_busy = false;
	bool pktRepository_i_1_r_0_t_2_busy = false;
	bool pktRepository_i_1_r_0_t_3_busy = false;
	bool pktRepository_i_1_r_0_t_4_busy = false;
	bool pktRepository_i_1_r_0_t_5_busy = false;
	bool pktRepository_i_1_r_0_t_6_busy = false;
	bool pktRepository_i_1_r_0_t_7_busy = false;
	bool pktRepository_i_1_r_0_t_8_busy = false;
	bool pktRepository_i_1_r_0_t_9_busy = false;

	std::unordered_map<long, RawPkt*> pktRepository_i_1_r_1_t_0;
	std::unordered_map<long, RawPkt*> pktRepository_i_1_r_1_t_1;
	std::unordered_map<long, RawPkt*> pktRepository_i_1_r_1_t_2;
	std::unordered_map<long, RawPkt*> pktRepository_i_1_r_1_t_3;
	std::unordered_map<long, RawPkt*> pktRepository_i_1_r_1_t_4;
	std::unordered_map<long, RawPkt*> pktRepository_i_1_r_1_t_5;
	std::unordered_map<long, RawPkt*> pktRepository_i_1_r_1_t_6;
	std::unordered_map<long, RawPkt*> pktRepository_i_1_r_1_t_7;
	std::unordered_map<long, RawPkt*> pktRepository_i_1_r_1_t_8;
	std::unordered_map<long, RawPkt*> pktRepository_i_1_r_1_t_9;

	long pktRepository_i_1_r_1_t_0_cnt = 0;
	long pktRepository_i_1_r_1_t_1_cnt = 0;
	long pktRepository_i_1_r_1_t_2_cnt = 0;
	long pktRepository_i_1_r_1_t_3_cnt = 0;
	long pktRepository_i_1_r_1_t_4_cnt = 0;
	long pktRepository_i_1_r_1_t_5_cnt = 0;
	long pktRepository_i_1_r_1_t_6_cnt = 0;
	long pktRepository_i_1_r_1_t_7_cnt = 0;
	long pktRepository_i_1_r_1_t_8_cnt = 0;
	long pktRepository_i_1_r_1_t_9_cnt = 0;

	bool pktRepository_i_1_r_1_t_0_busy = false;
	bool pktRepository_i_1_r_1_t_1_busy = false;
	bool pktRepository_i_1_r_1_t_2_busy = false;
	bool pktRepository_i_1_r_1_t_3_busy = false;
	bool pktRepository_i_1_r_1_t_4_busy = false;
	bool pktRepository_i_1_r_1_t_5_busy = false;
	bool pktRepository_i_1_r_1_t_6_busy = false;
	bool pktRepository_i_1_r_1_t_7_busy = false;
	bool pktRepository_i_1_r_1_t_8_busy = false;
	bool pktRepository_i_1_r_1_t_9_busy = false;

	std::unordered_map<long, RawPkt*> pktRepository_i_1_r_2_t_0;
	std::unordered_map<long, RawPkt*> pktRepository_i_1_r_2_t_1;
	std::unordered_map<long, RawPkt*> pktRepository_i_1_r_2_t_2;
	std::unordered_map<long, RawPkt*> pktRepository_i_1_r_2_t_3;
	std::unordered_map<long, RawPkt*> pktRepository_i_1_r_2_t_4;
	std::unordered_map<long, RawPkt*> pktRepository_i_1_r_2_t_5;
	std::unordered_map<long, RawPkt*> pktRepository_i_1_r_2_t_6;
	std::unordered_map<long, RawPkt*> pktRepository_i_1_r_2_t_7;
	std::unordered_map<long, RawPkt*> pktRepository_i_1_r_2_t_8;
	std::unordered_map<long, RawPkt*> pktRepository_i_1_r_2_t_9;

	long pktRepository_i_1_r_2_t_0_cnt = 0;
	long pktRepository_i_1_r_2_t_1_cnt = 0;
	long pktRepository_i_1_r_2_t_2_cnt = 0;
	long pktRepository_i_1_r_2_t_3_cnt = 0;
	long pktRepository_i_1_r_2_t_4_cnt = 0;
	long pktRepository_i_1_r_2_t_5_cnt = 0;
	long pktRepository_i_1_r_2_t_6_cnt = 0;
	long pktRepository_i_1_r_2_t_7_cnt = 0;
	long pktRepository_i_1_r_2_t_8_cnt = 0;
	long pktRepository_i_1_r_2_t_9_cnt = 0;

	bool pktRepository_i_1_r_2_t_0_busy = false;
	bool pktRepository_i_1_r_2_t_1_busy = false;
	bool pktRepository_i_1_r_2_t_2_busy = false;
	bool pktRepository_i_1_r_2_t_3_busy = false;
	bool pktRepository_i_1_r_2_t_4_busy = false;
	bool pktRepository_i_1_r_2_t_5_busy = false;
	bool pktRepository_i_1_r_2_t_6_busy = false;
	bool pktRepository_i_1_r_2_t_7_busy = false;
	bool pktRepository_i_1_r_2_t_8_busy = false;
	bool pktRepository_i_1_r_2_t_9_busy = false;

	std::unordered_map<long, RawPkt*> pktRepository_i_1_r_3_t_0;
	std::unordered_map<long, RawPkt*> pktRepository_i_1_r_3_t_1;
	std::unordered_map<long, RawPkt*> pktRepository_i_1_r_3_t_2;
	std::unordered_map<long, RawPkt*> pktRepository_i_1_r_3_t_3;
	std::unordered_map<long, RawPkt*> pktRepository_i_1_r_3_t_4;
	std::unordered_map<long, RawPkt*> pktRepository_i_1_r_3_t_5;
	std::unordered_map<long, RawPkt*> pktRepository_i_1_r_3_t_6;
	std::unordered_map<long, RawPkt*> pktRepository_i_1_r_3_t_7;
	std::unordered_map<long, RawPkt*> pktRepository_i_1_r_3_t_8;
	std::unordered_map<long, RawPkt*> pktRepository_i_1_r_3_t_9;

	long pktRepository_i_1_r_3_t_0_cnt = 0;
	long pktRepository_i_1_r_3_t_1_cnt = 0;
	long pktRepository_i_1_r_3_t_2_cnt = 0;
	long pktRepository_i_1_r_3_t_3_cnt = 0;
	long pktRepository_i_1_r_3_t_4_cnt = 0;
	long pktRepository_i_1_r_3_t_5_cnt = 0;
	long pktRepository_i_1_r_3_t_6_cnt = 0;
	long pktRepository_i_1_r_3_t_7_cnt = 0;
	long pktRepository_i_1_r_3_t_8_cnt = 0;
	long pktRepository_i_1_r_3_t_9_cnt = 0;

	bool pktRepository_i_1_r_3_t_0_busy = false;
	bool pktRepository_i_1_r_3_t_1_busy = false;
	bool pktRepository_i_1_r_3_t_2_busy = false;
	bool pktRepository_i_1_r_3_t_3_busy = false;
	bool pktRepository_i_1_r_3_t_4_busy = false;
	bool pktRepository_i_1_r_3_t_5_busy = false;
	bool pktRepository_i_1_r_3_t_6_busy = false;
	bool pktRepository_i_1_r_3_t_7_busy = false;
	bool pktRepository_i_1_r_3_t_8_busy = false;
	bool pktRepository_i_1_r_3_t_9_busy = false;

	std::unordered_map<long, RawPkt*> pktRepository_i_1_r_4_t_0;
	std::unordered_map<long, RawPkt*> pktRepository_i_1_r_4_t_1;
	std::unordered_map<long, RawPkt*> pktRepository_i_1_r_4_t_2;
	std::unordered_map<long, RawPkt*> pktRepository_i_1_r_4_t_3;
	std::unordered_map<long, RawPkt*> pktRepository_i_1_r_4_t_4;
	std::unordered_map<long, RawPkt*> pktRepository_i_1_r_4_t_5;
	std::unordered_map<long, RawPkt*> pktRepository_i_1_r_4_t_6;
	std::unordered_map<long, RawPkt*> pktRepository_i_1_r_4_t_7;
	std::unordered_map<long, RawPkt*> pktRepository_i_1_r_4_t_8;
	std::unordered_map<long, RawPkt*> pktRepository_i_1_r_4_t_9;

	long pktRepository_i_1_r_4_t_0_cnt = 0;
	long pktRepository_i_1_r_4_t_1_cnt = 0;
	long pktRepository_i_1_r_4_t_2_cnt = 0;
	long pktRepository_i_1_r_4_t_3_cnt = 0;
	long pktRepository_i_1_r_4_t_4_cnt = 0;
	long pktRepository_i_1_r_4_t_5_cnt = 0;
	long pktRepository_i_1_r_4_t_6_cnt = 0;
	long pktRepository_i_1_r_4_t_7_cnt = 0;
	long pktRepository_i_1_r_4_t_8_cnt = 0;
	long pktRepository_i_1_r_4_t_9_cnt = 0;

	bool pktRepository_i_1_r_4_t_0_busy = false;
	bool pktRepository_i_1_r_4_t_1_busy = false;
	bool pktRepository_i_1_r_4_t_2_busy = false;
	bool pktRepository_i_1_r_4_t_3_busy = false;
	bool pktRepository_i_1_r_4_t_4_busy = false;
	bool pktRepository_i_1_r_4_t_5_busy = false;
	bool pktRepository_i_1_r_4_t_6_busy = false;
	bool pktRepository_i_1_r_4_t_7_busy = false;
	bool pktRepository_i_1_r_4_t_8_busy = false;
	bool pktRepository_i_1_r_4_t_9_busy = false;

	std::unordered_map<long, RawPkt*> pktRepository_i_1_r_5_t_0;
	std::unordered_map<long, RawPkt*> pktRepository_i_1_r_5_t_1;
	std::unordered_map<long, RawPkt*> pktRepository_i_1_r_5_t_2;
	std::unordered_map<long, RawPkt*> pktRepository_i_1_r_5_t_3;
	std::unordered_map<long, RawPkt*> pktRepository_i_1_r_5_t_4;
	std::unordered_map<long, RawPkt*> pktRepository_i_1_r_5_t_5;
	std::unordered_map<long, RawPkt*> pktRepository_i_1_r_5_t_6;
	std::unordered_map<long, RawPkt*> pktRepository_i_1_r_5_t_7;
	std::unordered_map<long, RawPkt*> pktRepository_i_1_r_5_t_8;
	std::unordered_map<long, RawPkt*> pktRepository_i_1_r_5_t_9;

	long pktRepository_i_1_r_5_t_0_cnt = 0;
	long pktRepository_i_1_r_5_t_1_cnt = 0;
	long pktRepository_i_1_r_5_t_2_cnt = 0;
	long pktRepository_i_1_r_5_t_3_cnt = 0;
	long pktRepository_i_1_r_5_t_4_cnt = 0;
	long pktRepository_i_1_r_5_t_5_cnt = 0;
	long pktRepository_i_1_r_5_t_6_cnt = 0;
	long pktRepository_i_1_r_5_t_7_cnt = 0;
	long pktRepository_i_1_r_5_t_8_cnt = 0;
	long pktRepository_i_1_r_5_t_9_cnt = 0;

	bool pktRepository_i_1_r_5_t_0_busy = false;
	bool pktRepository_i_1_r_5_t_1_busy = false;
	bool pktRepository_i_1_r_5_t_2_busy = false;
	bool pktRepository_i_1_r_5_t_3_busy = false;
	bool pktRepository_i_1_r_5_t_4_busy = false;
	bool pktRepository_i_1_r_5_t_5_busy = false;
	bool pktRepository_i_1_r_5_t_6_busy = false;
	bool pktRepository_i_1_r_5_t_7_busy = false;
	bool pktRepository_i_1_r_5_t_8_busy = false;
	bool pktRepository_i_1_r_5_t_9_busy = false;

	std::unordered_map<long, RawPkt*> pktRepository_i_1_r_6_t_0;
	std::unordered_map<long, RawPkt*> pktRepository_i_1_r_6_t_1;
	std::unordered_map<long, RawPkt*> pktRepository_i_1_r_6_t_2;
	std::unordered_map<long, RawPkt*> pktRepository_i_1_r_6_t_3;
	std::unordered_map<long, RawPkt*> pktRepository_i_1_r_6_t_4;
	std::unordered_map<long, RawPkt*> pktRepository_i_1_r_6_t_5;
	std::unordered_map<long, RawPkt*> pktRepository_i_1_r_6_t_6;
	std::unordered_map<long, RawPkt*> pktRepository_i_1_r_6_t_7;
	std::unordered_map<long, RawPkt*> pktRepository_i_1_r_6_t_8;
	std::unordered_map<long, RawPkt*> pktRepository_i_1_r_6_t_9;

	long pktRepository_i_1_r_6_t_0_cnt = 0;
	long pktRepository_i_1_r_6_t_1_cnt = 0;
	long pktRepository_i_1_r_6_t_2_cnt = 0;
	long pktRepository_i_1_r_6_t_3_cnt = 0;
	long pktRepository_i_1_r_6_t_4_cnt = 0;
	long pktRepository_i_1_r_6_t_5_cnt = 0;
	long pktRepository_i_1_r_6_t_6_cnt = 0;
	long pktRepository_i_1_r_6_t_7_cnt = 0;
	long pktRepository_i_1_r_6_t_8_cnt = 0;
	long pktRepository_i_1_r_6_t_9_cnt = 0;

	bool pktRepository_i_1_r_6_t_0_busy = false;
	bool pktRepository_i_1_r_6_t_1_busy = false;
	bool pktRepository_i_1_r_6_t_2_busy = false;
	bool pktRepository_i_1_r_6_t_3_busy = false;
	bool pktRepository_i_1_r_6_t_4_busy = false;
	bool pktRepository_i_1_r_6_t_5_busy = false;
	bool pktRepository_i_1_r_6_t_6_busy = false;
	bool pktRepository_i_1_r_6_t_7_busy = false;
	bool pktRepository_i_1_r_6_t_8_busy = false;
	bool pktRepository_i_1_r_6_t_9_busy = false;

	std::unordered_map<long, RawPkt*> pktRepository_i_1_r_7_t_0;
	std::unordered_map<long, RawPkt*> pktRepository_i_1_r_7_t_1;
	std::unordered_map<long, RawPkt*> pktRepository_i_1_r_7_t_2;
	std::unordered_map<long, RawPkt*> pktRepository_i_1_r_7_t_3;
	std::unordered_map<long, RawPkt*> pktRepository_i_1_r_7_t_4;
	std::unordered_map<long, RawPkt*> pktRepository_i_1_r_7_t_5;
	std::unordered_map<long, RawPkt*> pktRepository_i_1_r_7_t_6;
	std::unordered_map<long, RawPkt*> pktRepository_i_1_r_7_t_7;
	std::unordered_map<long, RawPkt*> pktRepository_i_1_r_7_t_8;
	std::unordered_map<long, RawPkt*> pktRepository_i_1_r_7_t_9;

	long pktRepository_i_1_r_7_t_0_cnt = 0;
	long pktRepository_i_1_r_7_t_1_cnt = 0;
	long pktRepository_i_1_r_7_t_2_cnt = 0;
	long pktRepository_i_1_r_7_t_3_cnt = 0;
	long pktRepository_i_1_r_7_t_4_cnt = 0;
	long pktRepository_i_1_r_7_t_5_cnt = 0;
	long pktRepository_i_1_r_7_t_6_cnt = 0;
	long pktRepository_i_1_r_7_t_7_cnt = 0;
	long pktRepository_i_1_r_7_t_8_cnt = 0;
	long pktRepository_i_1_r_7_t_9_cnt = 0;

	bool pktRepository_i_1_r_7_t_0_busy = false;
	bool pktRepository_i_1_r_7_t_1_busy = false;
	bool pktRepository_i_1_r_7_t_2_busy = false;
	bool pktRepository_i_1_r_7_t_3_busy = false;
	bool pktRepository_i_1_r_7_t_4_busy = false;
	bool pktRepository_i_1_r_7_t_5_busy = false;
	bool pktRepository_i_1_r_7_t_6_busy = false;
	bool pktRepository_i_1_r_7_t_7_busy = false;
	bool pktRepository_i_1_r_7_t_8_busy = false;
	bool pktRepository_i_1_r_7_t_9_busy = false;

	/* Interface_2 */

	std::unordered_map<long, RawPkt*> pktRepository_i_2_r_0_t_0;
	std::unordered_map<long, RawPkt*> pktRepository_i_2_r_0_t_1;
	std::unordered_map<long, RawPkt*> pktRepository_i_2_r_0_t_2;
	std::unordered_map<long, RawPkt*> pktRepository_i_2_r_0_t_3;
	std::unordered_map<long, RawPkt*> pktRepository_i_2_r_0_t_4;
	std::unordered_map<long, RawPkt*> pktRepository_i_2_r_0_t_5;
	std::unordered_map<long, RawPkt*> pktRepository_i_2_r_0_t_6;
	std::unordered_map<long, RawPkt*> pktRepository_i_2_r_0_t_7;
	std::unordered_map<long, RawPkt*> pktRepository_i_2_r_0_t_8;
	std::unordered_map<long, RawPkt*> pktRepository_i_2_r_0_t_9;

	long pktRepository_i_2_r_0_t_0_cnt = 0;
	long pktRepository_i_2_r_0_t_1_cnt = 0;
	long pktRepository_i_2_r_0_t_2_cnt = 0;
	long pktRepository_i_2_r_0_t_3_cnt = 0;
	long pktRepository_i_2_r_0_t_4_cnt = 0;
	long pktRepository_i_2_r_0_t_5_cnt = 0;
	long pktRepository_i_2_r_0_t_6_cnt = 0;
	long pktRepository_i_2_r_0_t_7_cnt = 0;
	long pktRepository_i_2_r_0_t_8_cnt = 0;
	long pktRepository_i_2_r_0_t_9_cnt = 0;

	bool pktRepository_i_2_r_0_t_0_busy = false;
	bool pktRepository_i_2_r_0_t_1_busy = false;
	bool pktRepository_i_2_r_0_t_2_busy = false;
	bool pktRepository_i_2_r_0_t_3_busy = false;
	bool pktRepository_i_2_r_0_t_4_busy = false;
	bool pktRepository_i_2_r_0_t_5_busy = false;
	bool pktRepository_i_2_r_0_t_6_busy = false;
	bool pktRepository_i_2_r_0_t_7_busy = false;
	bool pktRepository_i_2_r_0_t_8_busy = false;
	bool pktRepository_i_2_r_0_t_9_busy = false;

	std::unordered_map<long, RawPkt*> pktRepository_i_2_r_1_t_0;
	std::unordered_map<long, RawPkt*> pktRepository_i_2_r_1_t_1;
	std::unordered_map<long, RawPkt*> pktRepository_i_2_r_1_t_2;
	std::unordered_map<long, RawPkt*> pktRepository_i_2_r_1_t_3;
	std::unordered_map<long, RawPkt*> pktRepository_i_2_r_1_t_4;
	std::unordered_map<long, RawPkt*> pktRepository_i_2_r_1_t_5;
	std::unordered_map<long, RawPkt*> pktRepository_i_2_r_1_t_6;
	std::unordered_map<long, RawPkt*> pktRepository_i_2_r_1_t_7;
	std::unordered_map<long, RawPkt*> pktRepository_i_2_r_1_t_8;
	std::unordered_map<long, RawPkt*> pktRepository_i_2_r_1_t_9;

	long pktRepository_i_2_r_1_t_0_cnt = 0;
	long pktRepository_i_2_r_1_t_1_cnt = 0;
	long pktRepository_i_2_r_1_t_2_cnt = 0;
	long pktRepository_i_2_r_1_t_3_cnt = 0;
	long pktRepository_i_2_r_1_t_4_cnt = 0;
	long pktRepository_i_2_r_1_t_5_cnt = 0;
	long pktRepository_i_2_r_1_t_6_cnt = 0;
	long pktRepository_i_2_r_1_t_7_cnt = 0;
	long pktRepository_i_2_r_1_t_8_cnt = 0;
	long pktRepository_i_2_r_1_t_9_cnt = 0;

	bool pktRepository_i_2_r_1_t_0_busy = false;
	bool pktRepository_i_2_r_1_t_1_busy = false;
	bool pktRepository_i_2_r_1_t_2_busy = false;
	bool pktRepository_i_2_r_1_t_3_busy = false;
	bool pktRepository_i_2_r_1_t_4_busy = false;
	bool pktRepository_i_2_r_1_t_5_busy = false;
	bool pktRepository_i_2_r_1_t_6_busy = false;
	bool pktRepository_i_2_r_1_t_7_busy = false;
	bool pktRepository_i_2_r_1_t_8_busy = false;
	bool pktRepository_i_2_r_1_t_9_busy = false;

	std::unordered_map<long, RawPkt*> pktRepository_i_2_r_2_t_0;
	std::unordered_map<long, RawPkt*> pktRepository_i_2_r_2_t_1;
	std::unordered_map<long, RawPkt*> pktRepository_i_2_r_2_t_2;
	std::unordered_map<long, RawPkt*> pktRepository_i_2_r_2_t_3;
	std::unordered_map<long, RawPkt*> pktRepository_i_2_r_2_t_4;
	std::unordered_map<long, RawPkt*> pktRepository_i_2_r_2_t_5;
	std::unordered_map<long, RawPkt*> pktRepository_i_2_r_2_t_6;
	std::unordered_map<long, RawPkt*> pktRepository_i_2_r_2_t_7;
	std::unordered_map<long, RawPkt*> pktRepository_i_2_r_2_t_8;
	std::unordered_map<long, RawPkt*> pktRepository_i_2_r_2_t_9;

	long pktRepository_i_2_r_2_t_0_cnt = 0;
	long pktRepository_i_2_r_2_t_1_cnt = 0;
	long pktRepository_i_2_r_2_t_2_cnt = 0;
	long pktRepository_i_2_r_2_t_3_cnt = 0;
	long pktRepository_i_2_r_2_t_4_cnt = 0;
	long pktRepository_i_2_r_2_t_5_cnt = 0;
	long pktRepository_i_2_r_2_t_6_cnt = 0;
	long pktRepository_i_2_r_2_t_7_cnt = 0;
	long pktRepository_i_2_r_2_t_8_cnt = 0;
	long pktRepository_i_2_r_2_t_9_cnt = 0;

	bool pktRepository_i_2_r_2_t_0_busy = false;
	bool pktRepository_i_2_r_2_t_1_busy = false;
	bool pktRepository_i_2_r_2_t_2_busy = false;
	bool pktRepository_i_2_r_2_t_3_busy = false;
	bool pktRepository_i_2_r_2_t_4_busy = false;
	bool pktRepository_i_2_r_2_t_5_busy = false;
	bool pktRepository_i_2_r_2_t_6_busy = false;
	bool pktRepository_i_2_r_2_t_7_busy = false;
	bool pktRepository_i_2_r_2_t_8_busy = false;
	bool pktRepository_i_2_r_2_t_9_busy = false;

	std::unordered_map<long, RawPkt*> pktRepository_i_2_r_3_t_0;
	std::unordered_map<long, RawPkt*> pktRepository_i_2_r_3_t_1;
	std::unordered_map<long, RawPkt*> pktRepository_i_2_r_3_t_2;
	std::unordered_map<long, RawPkt*> pktRepository_i_2_r_3_t_3;
	std::unordered_map<long, RawPkt*> pktRepository_i_2_r_3_t_4;
	std::unordered_map<long, RawPkt*> pktRepository_i_2_r_3_t_5;
	std::unordered_map<long, RawPkt*> pktRepository_i_2_r_3_t_6;
	std::unordered_map<long, RawPkt*> pktRepository_i_2_r_3_t_7;
	std::unordered_map<long, RawPkt*> pktRepository_i_2_r_3_t_8;
	std::unordered_map<long, RawPkt*> pktRepository_i_2_r_3_t_9;

	long pktRepository_i_2_r_3_t_0_cnt = 0;
	long pktRepository_i_2_r_3_t_1_cnt = 0;
	long pktRepository_i_2_r_3_t_2_cnt = 0;
	long pktRepository_i_2_r_3_t_3_cnt = 0;
	long pktRepository_i_2_r_3_t_4_cnt = 0;
	long pktRepository_i_2_r_3_t_5_cnt = 0;
	long pktRepository_i_2_r_3_t_6_cnt = 0;
	long pktRepository_i_2_r_3_t_7_cnt = 0;
	long pktRepository_i_2_r_3_t_8_cnt = 0;
	long pktRepository_i_2_r_3_t_9_cnt = 0;

	bool pktRepository_i_2_r_3_t_0_busy = false;
	bool pktRepository_i_2_r_3_t_1_busy = false;
	bool pktRepository_i_2_r_3_t_2_busy = false;
	bool pktRepository_i_2_r_3_t_3_busy = false;
	bool pktRepository_i_2_r_3_t_4_busy = false;
	bool pktRepository_i_2_r_3_t_5_busy = false;
	bool pktRepository_i_2_r_3_t_6_busy = false;
	bool pktRepository_i_2_r_3_t_7_busy = false;
	bool pktRepository_i_2_r_3_t_8_busy = false;
	bool pktRepository_i_2_r_3_t_9_busy = false;

	std::unordered_map<long, RawPkt*> pktRepository_i_2_r_4_t_0;
	std::unordered_map<long, RawPkt*> pktRepository_i_2_r_4_t_1;
	std::unordered_map<long, RawPkt*> pktRepository_i_2_r_4_t_2;
	std::unordered_map<long, RawPkt*> pktRepository_i_2_r_4_t_3;
	std::unordered_map<long, RawPkt*> pktRepository_i_2_r_4_t_4;
	std::unordered_map<long, RawPkt*> pktRepository_i_2_r_4_t_5;
	std::unordered_map<long, RawPkt*> pktRepository_i_2_r_4_t_6;
	std::unordered_map<long, RawPkt*> pktRepository_i_2_r_4_t_7;
	std::unordered_map<long, RawPkt*> pktRepository_i_2_r_4_t_8;
	std::unordered_map<long, RawPkt*> pktRepository_i_2_r_4_t_9;

	long pktRepository_i_2_r_4_t_0_cnt = 0;
	long pktRepository_i_2_r_4_t_1_cnt = 0;
	long pktRepository_i_2_r_4_t_2_cnt = 0;
	long pktRepository_i_2_r_4_t_3_cnt = 0;
	long pktRepository_i_2_r_4_t_4_cnt = 0;
	long pktRepository_i_2_r_4_t_5_cnt = 0;
	long pktRepository_i_2_r_4_t_6_cnt = 0;
	long pktRepository_i_2_r_4_t_7_cnt = 0;
	long pktRepository_i_2_r_4_t_8_cnt = 0;
	long pktRepository_i_2_r_4_t_9_cnt = 0;

	bool pktRepository_i_2_r_4_t_0_busy = false;
	bool pktRepository_i_2_r_4_t_1_busy = false;
	bool pktRepository_i_2_r_4_t_2_busy = false;
	bool pktRepository_i_2_r_4_t_3_busy = false;
	bool pktRepository_i_2_r_4_t_4_busy = false;
	bool pktRepository_i_2_r_4_t_5_busy = false;
	bool pktRepository_i_2_r_4_t_6_busy = false;
	bool pktRepository_i_2_r_4_t_7_busy = false;
	bool pktRepository_i_2_r_4_t_8_busy = false;
	bool pktRepository_i_2_r_4_t_9_busy = false;

	std::unordered_map<long, RawPkt*> pktRepository_i_2_r_5_t_0;
	std::unordered_map<long, RawPkt*> pktRepository_i_2_r_5_t_1;
	std::unordered_map<long, RawPkt*> pktRepository_i_2_r_5_t_2;
	std::unordered_map<long, RawPkt*> pktRepository_i_2_r_5_t_3;
	std::unordered_map<long, RawPkt*> pktRepository_i_2_r_5_t_4;
	std::unordered_map<long, RawPkt*> pktRepository_i_2_r_5_t_5;
	std::unordered_map<long, RawPkt*> pktRepository_i_2_r_5_t_6;
	std::unordered_map<long, RawPkt*> pktRepository_i_2_r_5_t_7;
	std::unordered_map<long, RawPkt*> pktRepository_i_2_r_5_t_8;
	std::unordered_map<long, RawPkt*> pktRepository_i_2_r_5_t_9;

	long pktRepository_i_2_r_5_t_0_cnt = 0;
	long pktRepository_i_2_r_5_t_1_cnt = 0;
	long pktRepository_i_2_r_5_t_2_cnt = 0;
	long pktRepository_i_2_r_5_t_3_cnt = 0;
	long pktRepository_i_2_r_5_t_4_cnt = 0;
	long pktRepository_i_2_r_5_t_5_cnt = 0;
	long pktRepository_i_2_r_5_t_6_cnt = 0;
	long pktRepository_i_2_r_5_t_7_cnt = 0;
	long pktRepository_i_2_r_5_t_8_cnt = 0;
	long pktRepository_i_2_r_5_t_9_cnt = 0;

	bool pktRepository_i_2_r_5_t_0_busy = false;
	bool pktRepository_i_2_r_5_t_1_busy = false;
	bool pktRepository_i_2_r_5_t_2_busy = false;
	bool pktRepository_i_2_r_5_t_3_busy = false;
	bool pktRepository_i_2_r_5_t_4_busy = false;
	bool pktRepository_i_2_r_5_t_5_busy = false;
	bool pktRepository_i_2_r_5_t_6_busy = false;
	bool pktRepository_i_2_r_5_t_7_busy = false;
	bool pktRepository_i_2_r_5_t_8_busy = false;
	bool pktRepository_i_2_r_5_t_9_busy = false;

	std::unordered_map<long, RawPkt*> pktRepository_i_2_r_6_t_0;
	std::unordered_map<long, RawPkt*> pktRepository_i_2_r_6_t_1;
	std::unordered_map<long, RawPkt*> pktRepository_i_2_r_6_t_2;
	std::unordered_map<long, RawPkt*> pktRepository_i_2_r_6_t_3;
	std::unordered_map<long, RawPkt*> pktRepository_i_2_r_6_t_4;
	std::unordered_map<long, RawPkt*> pktRepository_i_2_r_6_t_5;
	std::unordered_map<long, RawPkt*> pktRepository_i_2_r_6_t_6;
	std::unordered_map<long, RawPkt*> pktRepository_i_2_r_6_t_7;
	std::unordered_map<long, RawPkt*> pktRepository_i_2_r_6_t_8;
	std::unordered_map<long, RawPkt*> pktRepository_i_2_r_6_t_9;

	long pktRepository_i_2_r_6_t_0_cnt = 0;
	long pktRepository_i_2_r_6_t_1_cnt = 0;
	long pktRepository_i_2_r_6_t_2_cnt = 0;
	long pktRepository_i_2_r_6_t_3_cnt = 0;
	long pktRepository_i_2_r_6_t_4_cnt = 0;
	long pktRepository_i_2_r_6_t_5_cnt = 0;
	long pktRepository_i_2_r_6_t_6_cnt = 0;
	long pktRepository_i_2_r_6_t_7_cnt = 0;
	long pktRepository_i_2_r_6_t_8_cnt = 0;
	long pktRepository_i_2_r_6_t_9_cnt = 0;

	bool pktRepository_i_2_r_6_t_0_busy = false;
	bool pktRepository_i_2_r_6_t_1_busy = false;
	bool pktRepository_i_2_r_6_t_2_busy = false;
	bool pktRepository_i_2_r_6_t_3_busy = false;
	bool pktRepository_i_2_r_6_t_4_busy = false;
	bool pktRepository_i_2_r_6_t_5_busy = false;
	bool pktRepository_i_2_r_6_t_6_busy = false;
	bool pktRepository_i_2_r_6_t_7_busy = false;
	bool pktRepository_i_2_r_6_t_8_busy = false;
	bool pktRepository_i_2_r_6_t_9_busy = false;

	std::unordered_map<long, RawPkt*> pktRepository_i_2_r_7_t_0;
	std::unordered_map<long, RawPkt*> pktRepository_i_2_r_7_t_1;
	std::unordered_map<long, RawPkt*> pktRepository_i_2_r_7_t_2;
	std::unordered_map<long, RawPkt*> pktRepository_i_2_r_7_t_3;
	std::unordered_map<long, RawPkt*> pktRepository_i_2_r_7_t_4;
	std::unordered_map<long, RawPkt*> pktRepository_i_2_r_7_t_5;
	std::unordered_map<long, RawPkt*> pktRepository_i_2_r_7_t_6;
	std::unordered_map<long, RawPkt*> pktRepository_i_2_r_7_t_7;
	std::unordered_map<long, RawPkt*> pktRepository_i_2_r_7_t_8;
	std::unordered_map<long, RawPkt*> pktRepository_i_2_r_7_t_9;

	long pktRepository_i_2_r_7_t_0_cnt = 0;
	long pktRepository_i_2_r_7_t_1_cnt = 0;
	long pktRepository_i_2_r_7_t_2_cnt = 0;
	long pktRepository_i_2_r_7_t_3_cnt = 0;
	long pktRepository_i_2_r_7_t_4_cnt = 0;
	long pktRepository_i_2_r_7_t_5_cnt = 0;
	long pktRepository_i_2_r_7_t_6_cnt = 0;
	long pktRepository_i_2_r_7_t_7_cnt = 0;
	long pktRepository_i_2_r_7_t_8_cnt = 0;
	long pktRepository_i_2_r_7_t_9_cnt = 0;

	bool pktRepository_i_2_r_7_t_0_busy = false;
	bool pktRepository_i_2_r_7_t_1_busy = false;
	bool pktRepository_i_2_r_7_t_2_busy = false;
	bool pktRepository_i_2_r_7_t_3_busy = false;
	bool pktRepository_i_2_r_7_t_4_busy = false;
	bool pktRepository_i_2_r_7_t_5_busy = false;
	bool pktRepository_i_2_r_7_t_6_busy = false;
	bool pktRepository_i_2_r_7_t_7_busy = false;
	bool pktRepository_i_2_r_7_t_8_busy = false;
	bool pktRepository_i_2_r_7_t_9_busy = false;

	/* Interface_3 */

	std::unordered_map<long, RawPkt*> pktRepository_i_3_r_0_t_0;
	std::unordered_map<long, RawPkt*> pktRepository_i_3_r_0_t_1;
	std::unordered_map<long, RawPkt*> pktRepository_i_3_r_0_t_2;
	std::unordered_map<long, RawPkt*> pktRepository_i_3_r_0_t_3;
	std::unordered_map<long, RawPkt*> pktRepository_i_3_r_0_t_4;
	std::unordered_map<long, RawPkt*> pktRepository_i_3_r_0_t_5;
	std::unordered_map<long, RawPkt*> pktRepository_i_3_r_0_t_6;
	std::unordered_map<long, RawPkt*> pktRepository_i_3_r_0_t_7;
	std::unordered_map<long, RawPkt*> pktRepository_i_3_r_0_t_8;
	std::unordered_map<long, RawPkt*> pktRepository_i_3_r_0_t_9;

	long pktRepository_i_3_r_0_t_0_cnt = 0;
	long pktRepository_i_3_r_0_t_1_cnt = 0;
	long pktRepository_i_3_r_0_t_2_cnt = 0;
	long pktRepository_i_3_r_0_t_3_cnt = 0;
	long pktRepository_i_3_r_0_t_4_cnt = 0;
	long pktRepository_i_3_r_0_t_5_cnt = 0;
	long pktRepository_i_3_r_0_t_6_cnt = 0;
	long pktRepository_i_3_r_0_t_7_cnt = 0;
	long pktRepository_i_3_r_0_t_8_cnt = 0;
	long pktRepository_i_3_r_0_t_9_cnt = 0;

	bool pktRepository_i_3_r_0_t_0_busy = false;
	bool pktRepository_i_3_r_0_t_1_busy = false;
	bool pktRepository_i_3_r_0_t_2_busy = false;
	bool pktRepository_i_3_r_0_t_3_busy = false;
	bool pktRepository_i_3_r_0_t_4_busy = false;
	bool pktRepository_i_3_r_0_t_5_busy = false;
	bool pktRepository_i_3_r_0_t_6_busy = false;
	bool pktRepository_i_3_r_0_t_7_busy = false;
	bool pktRepository_i_3_r_0_t_8_busy = false;
	bool pktRepository_i_3_r_0_t_9_busy = false;

	std::unordered_map<long, RawPkt*> pktRepository_i_3_r_1_t_0;
	std::unordered_map<long, RawPkt*> pktRepository_i_3_r_1_t_1;
	std::unordered_map<long, RawPkt*> pktRepository_i_3_r_1_t_2;
	std::unordered_map<long, RawPkt*> pktRepository_i_3_r_1_t_3;
	std::unordered_map<long, RawPkt*> pktRepository_i_3_r_1_t_4;
	std::unordered_map<long, RawPkt*> pktRepository_i_3_r_1_t_5;
	std::unordered_map<long, RawPkt*> pktRepository_i_3_r_1_t_6;
	std::unordered_map<long, RawPkt*> pktRepository_i_3_r_1_t_7;
	std::unordered_map<long, RawPkt*> pktRepository_i_3_r_1_t_8;
	std::unordered_map<long, RawPkt*> pktRepository_i_3_r_1_t_9;

	long pktRepository_i_3_r_1_t_0_cnt = 0;
	long pktRepository_i_3_r_1_t_1_cnt = 0;
	long pktRepository_i_3_r_1_t_2_cnt = 0;
	long pktRepository_i_3_r_1_t_3_cnt = 0;
	long pktRepository_i_3_r_1_t_4_cnt = 0;
	long pktRepository_i_3_r_1_t_5_cnt = 0;
	long pktRepository_i_3_r_1_t_6_cnt = 0;
	long pktRepository_i_3_r_1_t_7_cnt = 0;
	long pktRepository_i_3_r_1_t_8_cnt = 0;
	long pktRepository_i_3_r_1_t_9_cnt = 0;

	bool pktRepository_i_3_r_1_t_0_busy = false;
	bool pktRepository_i_3_r_1_t_1_busy = false;
	bool pktRepository_i_3_r_1_t_2_busy = false;
	bool pktRepository_i_3_r_1_t_3_busy = false;
	bool pktRepository_i_3_r_1_t_4_busy = false;
	bool pktRepository_i_3_r_1_t_5_busy = false;
	bool pktRepository_i_3_r_1_t_6_busy = false;
	bool pktRepository_i_3_r_1_t_7_busy = false;
	bool pktRepository_i_3_r_1_t_8_busy = false;
	bool pktRepository_i_3_r_1_t_9_busy = false;

	std::unordered_map<long, RawPkt*> pktRepository_i_3_r_2_t_0;
	std::unordered_map<long, RawPkt*> pktRepository_i_3_r_2_t_1;
	std::unordered_map<long, RawPkt*> pktRepository_i_3_r_2_t_2;
	std::unordered_map<long, RawPkt*> pktRepository_i_3_r_2_t_3;
	std::unordered_map<long, RawPkt*> pktRepository_i_3_r_2_t_4;
	std::unordered_map<long, RawPkt*> pktRepository_i_3_r_2_t_5;
	std::unordered_map<long, RawPkt*> pktRepository_i_3_r_2_t_6;
	std::unordered_map<long, RawPkt*> pktRepository_i_3_r_2_t_7;
	std::unordered_map<long, RawPkt*> pktRepository_i_3_r_2_t_8;
	std::unordered_map<long, RawPkt*> pktRepository_i_3_r_2_t_9;

	long pktRepository_i_3_r_2_t_0_cnt = 0;
	long pktRepository_i_3_r_2_t_1_cnt = 0;
	long pktRepository_i_3_r_2_t_2_cnt = 0;
	long pktRepository_i_3_r_2_t_3_cnt = 0;
	long pktRepository_i_3_r_2_t_4_cnt = 0;
	long pktRepository_i_3_r_2_t_5_cnt = 0;
	long pktRepository_i_3_r_2_t_6_cnt = 0;
	long pktRepository_i_3_r_2_t_7_cnt = 0;
	long pktRepository_i_3_r_2_t_8_cnt = 0;
	long pktRepository_i_3_r_2_t_9_cnt = 0;

	bool pktRepository_i_3_r_2_t_0_busy = false;
	bool pktRepository_i_3_r_2_t_1_busy = false;
	bool pktRepository_i_3_r_2_t_2_busy = false;
	bool pktRepository_i_3_r_2_t_3_busy = false;
	bool pktRepository_i_3_r_2_t_4_busy = false;
	bool pktRepository_i_3_r_2_t_5_busy = false;
	bool pktRepository_i_3_r_2_t_6_busy = false;
	bool pktRepository_i_3_r_2_t_7_busy = false;
	bool pktRepository_i_3_r_2_t_8_busy = false;
	bool pktRepository_i_3_r_2_t_9_busy = false;

	std::unordered_map<long, RawPkt*> pktRepository_i_3_r_3_t_0;
	std::unordered_map<long, RawPkt*> pktRepository_i_3_r_3_t_1;
	std::unordered_map<long, RawPkt*> pktRepository_i_3_r_3_t_2;
	std::unordered_map<long, RawPkt*> pktRepository_i_3_r_3_t_3;
	std::unordered_map<long, RawPkt*> pktRepository_i_3_r_3_t_4;
	std::unordered_map<long, RawPkt*> pktRepository_i_3_r_3_t_5;
	std::unordered_map<long, RawPkt*> pktRepository_i_3_r_3_t_6;
	std::unordered_map<long, RawPkt*> pktRepository_i_3_r_3_t_7;
	std::unordered_map<long, RawPkt*> pktRepository_i_3_r_3_t_8;
	std::unordered_map<long, RawPkt*> pktRepository_i_3_r_3_t_9;

	long pktRepository_i_3_r_3_t_0_cnt = 0;
	long pktRepository_i_3_r_3_t_1_cnt = 0;
	long pktRepository_i_3_r_3_t_2_cnt = 0;
	long pktRepository_i_3_r_3_t_3_cnt = 0;
	long pktRepository_i_3_r_3_t_4_cnt = 0;
	long pktRepository_i_3_r_3_t_5_cnt = 0;
	long pktRepository_i_3_r_3_t_6_cnt = 0;
	long pktRepository_i_3_r_3_t_7_cnt = 0;
	long pktRepository_i_3_r_3_t_8_cnt = 0;
	long pktRepository_i_3_r_3_t_9_cnt = 0;

	bool pktRepository_i_3_r_3_t_0_busy = false;
	bool pktRepository_i_3_r_3_t_1_busy = false;
	bool pktRepository_i_3_r_3_t_2_busy = false;
	bool pktRepository_i_3_r_3_t_3_busy = false;
	bool pktRepository_i_3_r_3_t_4_busy = false;
	bool pktRepository_i_3_r_3_t_5_busy = false;
	bool pktRepository_i_3_r_3_t_6_busy = false;
	bool pktRepository_i_3_r_3_t_7_busy = false;
	bool pktRepository_i_3_r_3_t_8_busy = false;
	bool pktRepository_i_3_r_3_t_9_busy = false;

	std::unordered_map<long, RawPkt*> pktRepository_i_3_r_4_t_0;
	std::unordered_map<long, RawPkt*> pktRepository_i_3_r_4_t_1;
	std::unordered_map<long, RawPkt*> pktRepository_i_3_r_4_t_2;
	std::unordered_map<long, RawPkt*> pktRepository_i_3_r_4_t_3;
	std::unordered_map<long, RawPkt*> pktRepository_i_3_r_4_t_4;
	std::unordered_map<long, RawPkt*> pktRepository_i_3_r_4_t_5;
	std::unordered_map<long, RawPkt*> pktRepository_i_3_r_4_t_6;
	std::unordered_map<long, RawPkt*> pktRepository_i_3_r_4_t_7;
	std::unordered_map<long, RawPkt*> pktRepository_i_3_r_4_t_8;
	std::unordered_map<long, RawPkt*> pktRepository_i_3_r_4_t_9;

	long pktRepository_i_3_r_4_t_0_cnt = 0;
	long pktRepository_i_3_r_4_t_1_cnt = 0;
	long pktRepository_i_3_r_4_t_2_cnt = 0;
	long pktRepository_i_3_r_4_t_3_cnt = 0;
	long pktRepository_i_3_r_4_t_4_cnt = 0;
	long pktRepository_i_3_r_4_t_5_cnt = 0;
	long pktRepository_i_3_r_4_t_6_cnt = 0;
	long pktRepository_i_3_r_4_t_7_cnt = 0;
	long pktRepository_i_3_r_4_t_8_cnt = 0;
	long pktRepository_i_3_r_4_t_9_cnt = 0;

	bool pktRepository_i_3_r_4_t_0_busy = false;
	bool pktRepository_i_3_r_4_t_1_busy = false;
	bool pktRepository_i_3_r_4_t_2_busy = false;
	bool pktRepository_i_3_r_4_t_3_busy = false;
	bool pktRepository_i_3_r_4_t_4_busy = false;
	bool pktRepository_i_3_r_4_t_5_busy = false;
	bool pktRepository_i_3_r_4_t_6_busy = false;
	bool pktRepository_i_3_r_4_t_7_busy = false;
	bool pktRepository_i_3_r_4_t_8_busy = false;
	bool pktRepository_i_3_r_4_t_9_busy = false;

	std::unordered_map<long, RawPkt*> pktRepository_i_3_r_5_t_0;
	std::unordered_map<long, RawPkt*> pktRepository_i_3_r_5_t_1;
	std::unordered_map<long, RawPkt*> pktRepository_i_3_r_5_t_2;
	std::unordered_map<long, RawPkt*> pktRepository_i_3_r_5_t_3;
	std::unordered_map<long, RawPkt*> pktRepository_i_3_r_5_t_4;
	std::unordered_map<long, RawPkt*> pktRepository_i_3_r_5_t_5;
	std::unordered_map<long, RawPkt*> pktRepository_i_3_r_5_t_6;
	std::unordered_map<long, RawPkt*> pktRepository_i_3_r_5_t_7;
	std::unordered_map<long, RawPkt*> pktRepository_i_3_r_5_t_8;
	std::unordered_map<long, RawPkt*> pktRepository_i_3_r_5_t_9;

	long pktRepository_i_3_r_5_t_0_cnt = 0;
	long pktRepository_i_3_r_5_t_1_cnt = 0;
	long pktRepository_i_3_r_5_t_2_cnt = 0;
	long pktRepository_i_3_r_5_t_3_cnt = 0;
	long pktRepository_i_3_r_5_t_4_cnt = 0;
	long pktRepository_i_3_r_5_t_5_cnt = 0;
	long pktRepository_i_3_r_5_t_6_cnt = 0;
	long pktRepository_i_3_r_5_t_7_cnt = 0;
	long pktRepository_i_3_r_5_t_8_cnt = 0;
	long pktRepository_i_3_r_5_t_9_cnt = 0;

	bool pktRepository_i_3_r_5_t_0_busy = false;
	bool pktRepository_i_3_r_5_t_1_busy = false;
	bool pktRepository_i_3_r_5_t_2_busy = false;
	bool pktRepository_i_3_r_5_t_3_busy = false;
	bool pktRepository_i_3_r_5_t_4_busy = false;
	bool pktRepository_i_3_r_5_t_5_busy = false;
	bool pktRepository_i_3_r_5_t_6_busy = false;
	bool pktRepository_i_3_r_5_t_7_busy = false;
	bool pktRepository_i_3_r_5_t_8_busy = false;
	bool pktRepository_i_3_r_5_t_9_busy = false;

	std::unordered_map<long, RawPkt*> pktRepository_i_3_r_6_t_0;
	std::unordered_map<long, RawPkt*> pktRepository_i_3_r_6_t_1;
	std::unordered_map<long, RawPkt*> pktRepository_i_3_r_6_t_2;
	std::unordered_map<long, RawPkt*> pktRepository_i_3_r_6_t_3;
	std::unordered_map<long, RawPkt*> pktRepository_i_3_r_6_t_4;
	std::unordered_map<long, RawPkt*> pktRepository_i_3_r_6_t_5;
	std::unordered_map<long, RawPkt*> pktRepository_i_3_r_6_t_6;
	std::unordered_map<long, RawPkt*> pktRepository_i_3_r_6_t_7;
	std::unordered_map<long, RawPkt*> pktRepository_i_3_r_6_t_8;
	std::unordered_map<long, RawPkt*> pktRepository_i_3_r_6_t_9;

	long pktRepository_i_3_r_6_t_0_cnt = 0;
	long pktRepository_i_3_r_6_t_1_cnt = 0;
	long pktRepository_i_3_r_6_t_2_cnt = 0;
	long pktRepository_i_3_r_6_t_3_cnt = 0;
	long pktRepository_i_3_r_6_t_4_cnt = 0;
	long pktRepository_i_3_r_6_t_5_cnt = 0;
	long pktRepository_i_3_r_6_t_6_cnt = 0;
	long pktRepository_i_3_r_6_t_7_cnt = 0;
	long pktRepository_i_3_r_6_t_8_cnt = 0;
	long pktRepository_i_3_r_6_t_9_cnt = 0;

	bool pktRepository_i_3_r_6_t_0_busy = false;
	bool pktRepository_i_3_r_6_t_1_busy = false;
	bool pktRepository_i_3_r_6_t_2_busy = false;
	bool pktRepository_i_3_r_6_t_3_busy = false;
	bool pktRepository_i_3_r_6_t_4_busy = false;
	bool pktRepository_i_3_r_6_t_5_busy = false;
	bool pktRepository_i_3_r_6_t_6_busy = false;
	bool pktRepository_i_3_r_6_t_7_busy = false;
	bool pktRepository_i_3_r_6_t_8_busy = false;
	bool pktRepository_i_3_r_6_t_9_busy = false;

	std::unordered_map<long, RawPkt*> pktRepository_i_3_r_7_t_0;
	std::unordered_map<long, RawPkt*> pktRepository_i_3_r_7_t_1;
	std::unordered_map<long, RawPkt*> pktRepository_i_3_r_7_t_2;
	std::unordered_map<long, RawPkt*> pktRepository_i_3_r_7_t_3;
	std::unordered_map<long, RawPkt*> pktRepository_i_3_r_7_t_4;
	std::unordered_map<long, RawPkt*> pktRepository_i_3_r_7_t_5;
	std::unordered_map<long, RawPkt*> pktRepository_i_3_r_7_t_6;
	std::unordered_map<long, RawPkt*> pktRepository_i_3_r_7_t_7;
	std::unordered_map<long, RawPkt*> pktRepository_i_3_r_7_t_8;
	std::unordered_map<long, RawPkt*> pktRepository_i_3_r_7_t_9;

	long pktRepository_i_3_r_7_t_0_cnt = 0;
	long pktRepository_i_3_r_7_t_1_cnt = 0;
	long pktRepository_i_3_r_7_t_2_cnt = 0;
	long pktRepository_i_3_r_7_t_3_cnt = 0;
	long pktRepository_i_3_r_7_t_4_cnt = 0;
	long pktRepository_i_3_r_7_t_5_cnt = 0;
	long pktRepository_i_3_r_7_t_6_cnt = 0;
	long pktRepository_i_3_r_7_t_7_cnt = 0;
	long pktRepository_i_3_r_7_t_8_cnt = 0;
	long pktRepository_i_3_r_7_t_9_cnt = 0;

	bool pktRepository_i_3_r_7_t_0_busy = false;
	bool pktRepository_i_3_r_7_t_1_busy = false;
	bool pktRepository_i_3_r_7_t_2_busy = false;
	bool pktRepository_i_3_r_7_t_3_busy = false;
	bool pktRepository_i_3_r_7_t_4_busy = false;
	bool pktRepository_i_3_r_7_t_5_busy = false;
	bool pktRepository_i_3_r_7_t_6_busy = false;
	bool pktRepository_i_3_r_7_t_7_busy = false;
	bool pktRepository_i_3_r_7_t_8_busy = false;
	bool pktRepository_i_3_r_7_t_9_busy = false;

	/* Interface_4 */
	std::unordered_map<long, RawPkt*> pktRepository_i_4_r_0_t_0;
	std::unordered_map<long, RawPkt*> pktRepository_i_4_r_0_t_1;
	std::unordered_map<long, RawPkt*> pktRepository_i_4_r_0_t_2;
	std::unordered_map<long, RawPkt*> pktRepository_i_4_r_0_t_3;
	std::unordered_map<long, RawPkt*> pktRepository_i_4_r_0_t_4;
	std::unordered_map<long, RawPkt*> pktRepository_i_4_r_0_t_5;
	std::unordered_map<long, RawPkt*> pktRepository_i_4_r_0_t_6;
	std::unordered_map<long, RawPkt*> pktRepository_i_4_r_0_t_7;
	std::unordered_map<long, RawPkt*> pktRepository_i_4_r_0_t_8;
	std::unordered_map<long, RawPkt*> pktRepository_i_4_r_0_t_9;

	long pktRepository_i_4_r_0_t_0_cnt = 0;
	long pktRepository_i_4_r_0_t_1_cnt = 0;
	long pktRepository_i_4_r_0_t_2_cnt = 0;
	long pktRepository_i_4_r_0_t_3_cnt = 0;
	long pktRepository_i_4_r_0_t_4_cnt = 0;
	long pktRepository_i_4_r_0_t_5_cnt = 0;
	long pktRepository_i_4_r_0_t_6_cnt = 0;
	long pktRepository_i_4_r_0_t_7_cnt = 0;
	long pktRepository_i_4_r_0_t_8_cnt = 0;
	long pktRepository_i_4_r_0_t_9_cnt = 0;

	bool pktRepository_i_4_r_0_t_0_busy = false;
	bool pktRepository_i_4_r_0_t_1_busy = false;
	bool pktRepository_i_4_r_0_t_2_busy = false;
	bool pktRepository_i_4_r_0_t_3_busy = false;
	bool pktRepository_i_4_r_0_t_4_busy = false;
	bool pktRepository_i_4_r_0_t_5_busy = false;
	bool pktRepository_i_4_r_0_t_6_busy = false;
	bool pktRepository_i_4_r_0_t_7_busy = false;
	bool pktRepository_i_4_r_0_t_8_busy = false;
	bool pktRepository_i_4_r_0_t_9_busy = false;

	std::unordered_map<long, RawPkt*> pktRepository_i_4_r_1_t_0;
	std::unordered_map<long, RawPkt*> pktRepository_i_4_r_1_t_1;
	std::unordered_map<long, RawPkt*> pktRepository_i_4_r_1_t_2;
	std::unordered_map<long, RawPkt*> pktRepository_i_4_r_1_t_3;
	std::unordered_map<long, RawPkt*> pktRepository_i_4_r_1_t_4;
	std::unordered_map<long, RawPkt*> pktRepository_i_4_r_1_t_5;
	std::unordered_map<long, RawPkt*> pktRepository_i_4_r_1_t_6;
	std::unordered_map<long, RawPkt*> pktRepository_i_4_r_1_t_7;
	std::unordered_map<long, RawPkt*> pktRepository_i_4_r_1_t_8;
	std::unordered_map<long, RawPkt*> pktRepository_i_4_r_1_t_9;

	long pktRepository_i_4_r_1_t_0_cnt = 0;
	long pktRepository_i_4_r_1_t_1_cnt = 0;
	long pktRepository_i_4_r_1_t_2_cnt = 0;
	long pktRepository_i_4_r_1_t_3_cnt = 0;
	long pktRepository_i_4_r_1_t_4_cnt = 0;
	long pktRepository_i_4_r_1_t_5_cnt = 0;
	long pktRepository_i_4_r_1_t_6_cnt = 0;
	long pktRepository_i_4_r_1_t_7_cnt = 0;
	long pktRepository_i_4_r_1_t_8_cnt = 0;
	long pktRepository_i_4_r_1_t_9_cnt = 0;

	bool pktRepository_i_4_r_1_t_0_busy = false;
	bool pktRepository_i_4_r_1_t_1_busy = false;
	bool pktRepository_i_4_r_1_t_2_busy = false;
	bool pktRepository_i_4_r_1_t_3_busy = false;
	bool pktRepository_i_4_r_1_t_4_busy = false;
	bool pktRepository_i_4_r_1_t_5_busy = false;
	bool pktRepository_i_4_r_1_t_6_busy = false;
	bool pktRepository_i_4_r_1_t_7_busy = false;
	bool pktRepository_i_4_r_1_t_8_busy = false;
	bool pktRepository_i_4_r_1_t_9_busy = false;

	std::unordered_map<long, RawPkt*> pktRepository_i_4_r_2_t_0;
	std::unordered_map<long, RawPkt*> pktRepository_i_4_r_2_t_1;
	std::unordered_map<long, RawPkt*> pktRepository_i_4_r_2_t_2;
	std::unordered_map<long, RawPkt*> pktRepository_i_4_r_2_t_3;
	std::unordered_map<long, RawPkt*> pktRepository_i_4_r_2_t_4;
	std::unordered_map<long, RawPkt*> pktRepository_i_4_r_2_t_5;
	std::unordered_map<long, RawPkt*> pktRepository_i_4_r_2_t_6;
	std::unordered_map<long, RawPkt*> pktRepository_i_4_r_2_t_7;
	std::unordered_map<long, RawPkt*> pktRepository_i_4_r_2_t_8;
	std::unordered_map<long, RawPkt*> pktRepository_i_4_r_2_t_9;

	long pktRepository_i_4_r_2_t_0_cnt = 0;
	long pktRepository_i_4_r_2_t_1_cnt = 0;
	long pktRepository_i_4_r_2_t_2_cnt = 0;
	long pktRepository_i_4_r_2_t_3_cnt = 0;
	long pktRepository_i_4_r_2_t_4_cnt = 0;
	long pktRepository_i_4_r_2_t_5_cnt = 0;
	long pktRepository_i_4_r_2_t_6_cnt = 0;
	long pktRepository_i_4_r_2_t_7_cnt = 0;
	long pktRepository_i_4_r_2_t_8_cnt = 0;
	long pktRepository_i_4_r_2_t_9_cnt = 0;

	bool pktRepository_i_4_r_2_t_0_busy = false;
	bool pktRepository_i_4_r_2_t_1_busy = false;
	bool pktRepository_i_4_r_2_t_2_busy = false;
	bool pktRepository_i_4_r_2_t_3_busy = false;
	bool pktRepository_i_4_r_2_t_4_busy = false;
	bool pktRepository_i_4_r_2_t_5_busy = false;
	bool pktRepository_i_4_r_2_t_6_busy = false;
	bool pktRepository_i_4_r_2_t_7_busy = false;
	bool pktRepository_i_4_r_2_t_8_busy = false;
	bool pktRepository_i_4_r_2_t_9_busy = false;

	std::unordered_map<long, RawPkt*> pktRepository_i_4_r_3_t_0;
	std::unordered_map<long, RawPkt*> pktRepository_i_4_r_3_t_1;
	std::unordered_map<long, RawPkt*> pktRepository_i_4_r_3_t_2;
	std::unordered_map<long, RawPkt*> pktRepository_i_4_r_3_t_3;
	std::unordered_map<long, RawPkt*> pktRepository_i_4_r_3_t_4;
	std::unordered_map<long, RawPkt*> pktRepository_i_4_r_3_t_5;
	std::unordered_map<long, RawPkt*> pktRepository_i_4_r_3_t_6;
	std::unordered_map<long, RawPkt*> pktRepository_i_4_r_3_t_7;
	std::unordered_map<long, RawPkt*> pktRepository_i_4_r_3_t_8;
	std::unordered_map<long, RawPkt*> pktRepository_i_4_r_3_t_9;

	long pktRepository_i_4_r_3_t_0_cnt = 0;
	long pktRepository_i_4_r_3_t_1_cnt = 0;
	long pktRepository_i_4_r_3_t_2_cnt = 0;
	long pktRepository_i_4_r_3_t_3_cnt = 0;
	long pktRepository_i_4_r_3_t_4_cnt = 0;
	long pktRepository_i_4_r_3_t_5_cnt = 0;
	long pktRepository_i_4_r_3_t_6_cnt = 0;
	long pktRepository_i_4_r_3_t_7_cnt = 0;
	long pktRepository_i_4_r_3_t_8_cnt = 0;
	long pktRepository_i_4_r_3_t_9_cnt = 0;

	bool pktRepository_i_4_r_3_t_0_busy = false;
	bool pktRepository_i_4_r_3_t_1_busy = false;
	bool pktRepository_i_4_r_3_t_2_busy = false;
	bool pktRepository_i_4_r_3_t_3_busy = false;
	bool pktRepository_i_4_r_3_t_4_busy = false;
	bool pktRepository_i_4_r_3_t_5_busy = false;
	bool pktRepository_i_4_r_3_t_6_busy = false;
	bool pktRepository_i_4_r_3_t_7_busy = false;
	bool pktRepository_i_4_r_3_t_8_busy = false;
	bool pktRepository_i_4_r_3_t_9_busy = false;

	std::unordered_map<long, RawPkt*> pktRepository_i_4_r_4_t_0;
	std::unordered_map<long, RawPkt*> pktRepository_i_4_r_4_t_1;
	std::unordered_map<long, RawPkt*> pktRepository_i_4_r_4_t_2;
	std::unordered_map<long, RawPkt*> pktRepository_i_4_r_4_t_3;
	std::unordered_map<long, RawPkt*> pktRepository_i_4_r_4_t_4;
	std::unordered_map<long, RawPkt*> pktRepository_i_4_r_4_t_5;
	std::unordered_map<long, RawPkt*> pktRepository_i_4_r_4_t_6;
	std::unordered_map<long, RawPkt*> pktRepository_i_4_r_4_t_7;
	std::unordered_map<long, RawPkt*> pktRepository_i_4_r_4_t_8;
	std::unordered_map<long, RawPkt*> pktRepository_i_4_r_4_t_9;

	long pktRepository_i_4_r_4_t_0_cnt = 0;
	long pktRepository_i_4_r_4_t_1_cnt = 0;
	long pktRepository_i_4_r_4_t_2_cnt = 0;
	long pktRepository_i_4_r_4_t_3_cnt = 0;
	long pktRepository_i_4_r_4_t_4_cnt = 0;
	long pktRepository_i_4_r_4_t_5_cnt = 0;
	long pktRepository_i_4_r_4_t_6_cnt = 0;
	long pktRepository_i_4_r_4_t_7_cnt = 0;
	long pktRepository_i_4_r_4_t_8_cnt = 0;
	long pktRepository_i_4_r_4_t_9_cnt = 0;

	bool pktRepository_i_4_r_4_t_0_busy = false;
	bool pktRepository_i_4_r_4_t_1_busy = false;
	bool pktRepository_i_4_r_4_t_2_busy = false;
	bool pktRepository_i_4_r_4_t_3_busy = false;
	bool pktRepository_i_4_r_4_t_4_busy = false;
	bool pktRepository_i_4_r_4_t_5_busy = false;
	bool pktRepository_i_4_r_4_t_6_busy = false;
	bool pktRepository_i_4_r_4_t_7_busy = false;
	bool pktRepository_i_4_r_4_t_8_busy = false;
	bool pktRepository_i_4_r_4_t_9_busy = false;

	std::unordered_map<long, RawPkt*> pktRepository_i_4_r_5_t_0;
	std::unordered_map<long, RawPkt*> pktRepository_i_4_r_5_t_1;
	std::unordered_map<long, RawPkt*> pktRepository_i_4_r_5_t_2;
	std::unordered_map<long, RawPkt*> pktRepository_i_4_r_5_t_3;
	std::unordered_map<long, RawPkt*> pktRepository_i_4_r_5_t_4;
	std::unordered_map<long, RawPkt*> pktRepository_i_4_r_5_t_5;
	std::unordered_map<long, RawPkt*> pktRepository_i_4_r_5_t_6;
	std::unordered_map<long, RawPkt*> pktRepository_i_4_r_5_t_7;
	std::unordered_map<long, RawPkt*> pktRepository_i_4_r_5_t_8;
	std::unordered_map<long, RawPkt*> pktRepository_i_4_r_5_t_9;

	long pktRepository_i_4_r_5_t_0_cnt = 0;
	long pktRepository_i_4_r_5_t_1_cnt = 0;
	long pktRepository_i_4_r_5_t_2_cnt = 0;
	long pktRepository_i_4_r_5_t_3_cnt = 0;
	long pktRepository_i_4_r_5_t_4_cnt = 0;
	long pktRepository_i_4_r_5_t_5_cnt = 0;
	long pktRepository_i_4_r_5_t_6_cnt = 0;
	long pktRepository_i_4_r_5_t_7_cnt = 0;
	long pktRepository_i_4_r_5_t_8_cnt = 0;
	long pktRepository_i_4_r_5_t_9_cnt = 0;

	bool pktRepository_i_4_r_5_t_0_busy = false;
	bool pktRepository_i_4_r_5_t_1_busy = false;
	bool pktRepository_i_4_r_5_t_2_busy = false;
	bool pktRepository_i_4_r_5_t_3_busy = false;
	bool pktRepository_i_4_r_5_t_4_busy = false;
	bool pktRepository_i_4_r_5_t_5_busy = false;
	bool pktRepository_i_4_r_5_t_6_busy = false;
	bool pktRepository_i_4_r_5_t_7_busy = false;
	bool pktRepository_i_4_r_5_t_8_busy = false;
	bool pktRepository_i_4_r_5_t_9_busy = false;

	std::unordered_map<long, RawPkt*> pktRepository_i_4_r_6_t_0;
	std::unordered_map<long, RawPkt*> pktRepository_i_4_r_6_t_1;
	std::unordered_map<long, RawPkt*> pktRepository_i_4_r_6_t_2;
	std::unordered_map<long, RawPkt*> pktRepository_i_4_r_6_t_3;
	std::unordered_map<long, RawPkt*> pktRepository_i_4_r_6_t_4;
	std::unordered_map<long, RawPkt*> pktRepository_i_4_r_6_t_5;
	std::unordered_map<long, RawPkt*> pktRepository_i_4_r_6_t_6;
	std::unordered_map<long, RawPkt*> pktRepository_i_4_r_6_t_7;
	std::unordered_map<long, RawPkt*> pktRepository_i_4_r_6_t_8;
	std::unordered_map<long, RawPkt*> pktRepository_i_4_r_6_t_9;

	long pktRepository_i_4_r_6_t_0_cnt = 0;
	long pktRepository_i_4_r_6_t_1_cnt = 0;
	long pktRepository_i_4_r_6_t_2_cnt = 0;
	long pktRepository_i_4_r_6_t_3_cnt = 0;
	long pktRepository_i_4_r_6_t_4_cnt = 0;
	long pktRepository_i_4_r_6_t_5_cnt = 0;
	long pktRepository_i_4_r_6_t_6_cnt = 0;
	long pktRepository_i_4_r_6_t_7_cnt = 0;
	long pktRepository_i_4_r_6_t_8_cnt = 0;
	long pktRepository_i_4_r_6_t_9_cnt = 0;

	bool pktRepository_i_4_r_6_t_0_busy = false;
	bool pktRepository_i_4_r_6_t_1_busy = false;
	bool pktRepository_i_4_r_6_t_2_busy = false;
	bool pktRepository_i_4_r_6_t_3_busy = false;
	bool pktRepository_i_4_r_6_t_4_busy = false;
	bool pktRepository_i_4_r_6_t_5_busy = false;
	bool pktRepository_i_4_r_6_t_6_busy = false;
	bool pktRepository_i_4_r_6_t_7_busy = false;
	bool pktRepository_i_4_r_6_t_8_busy = false;
	bool pktRepository_i_4_r_6_t_9_busy = false;

	std::unordered_map<long, RawPkt*> pktRepository_i_4_r_7_t_0;
	std::unordered_map<long, RawPkt*> pktRepository_i_4_r_7_t_1;
	std::unordered_map<long, RawPkt*> pktRepository_i_4_r_7_t_2;
	std::unordered_map<long, RawPkt*> pktRepository_i_4_r_7_t_3;
	std::unordered_map<long, RawPkt*> pktRepository_i_4_r_7_t_4;
	std::unordered_map<long, RawPkt*> pktRepository_i_4_r_7_t_5;
	std::unordered_map<long, RawPkt*> pktRepository_i_4_r_7_t_6;
	std::unordered_map<long, RawPkt*> pktRepository_i_4_r_7_t_7;
	std::unordered_map<long, RawPkt*> pktRepository_i_4_r_7_t_8;
	std::unordered_map<long, RawPkt*> pktRepository_i_4_r_7_t_9;

	long pktRepository_i_4_r_7_t_0_cnt = 0;
	long pktRepository_i_4_r_7_t_1_cnt = 0;
	long pktRepository_i_4_r_7_t_2_cnt = 0;
	long pktRepository_i_4_r_7_t_3_cnt = 0;
	long pktRepository_i_4_r_7_t_4_cnt = 0;
	long pktRepository_i_4_r_7_t_5_cnt = 0;
	long pktRepository_i_4_r_7_t_6_cnt = 0;
	long pktRepository_i_4_r_7_t_7_cnt = 0;
	long pktRepository_i_4_r_7_t_8_cnt = 0;
	long pktRepository_i_4_r_7_t_9_cnt = 0;

	bool pktRepository_i_4_r_7_t_0_busy = false;
	bool pktRepository_i_4_r_7_t_1_busy = false;
	bool pktRepository_i_4_r_7_t_2_busy = false;
	bool pktRepository_i_4_r_7_t_3_busy = false;
	bool pktRepository_i_4_r_7_t_4_busy = false;
	bool pktRepository_i_4_r_7_t_5_busy = false;
	bool pktRepository_i_4_r_7_t_6_busy = false;
	bool pktRepository_i_4_r_7_t_7_busy = false;
	bool pktRepository_i_4_r_7_t_8_busy = false;
	bool pktRepository_i_4_r_7_t_9_busy = false;

	/* Interface_5 */
	std::unordered_map<long, RawPkt*> pktRepository_i_5_r_0_t_0;
	std::unordered_map<long, RawPkt*> pktRepository_i_5_r_0_t_1;
	std::unordered_map<long, RawPkt*> pktRepository_i_5_r_0_t_2;
	std::unordered_map<long, RawPkt*> pktRepository_i_5_r_0_t_3;
	std::unordered_map<long, RawPkt*> pktRepository_i_5_r_0_t_4;
	std::unordered_map<long, RawPkt*> pktRepository_i_5_r_0_t_5;
	std::unordered_map<long, RawPkt*> pktRepository_i_5_r_0_t_6;
	std::unordered_map<long, RawPkt*> pktRepository_i_5_r_0_t_7;
	std::unordered_map<long, RawPkt*> pktRepository_i_5_r_0_t_8;
	std::unordered_map<long, RawPkt*> pktRepository_i_5_r_0_t_9;

	long pktRepository_i_5_r_0_t_0_cnt = 0;
	long pktRepository_i_5_r_0_t_1_cnt = 0;
	long pktRepository_i_5_r_0_t_2_cnt = 0;
	long pktRepository_i_5_r_0_t_3_cnt = 0;
	long pktRepository_i_5_r_0_t_4_cnt = 0;
	long pktRepository_i_5_r_0_t_5_cnt = 0;
	long pktRepository_i_5_r_0_t_6_cnt = 0;
	long pktRepository_i_5_r_0_t_7_cnt = 0;
	long pktRepository_i_5_r_0_t_8_cnt = 0;
	long pktRepository_i_5_r_0_t_9_cnt = 0;

	bool pktRepository_i_5_r_0_t_0_busy = false;
	bool pktRepository_i_5_r_0_t_1_busy = false;
	bool pktRepository_i_5_r_0_t_2_busy = false;
	bool pktRepository_i_5_r_0_t_3_busy = false;
	bool pktRepository_i_5_r_0_t_4_busy = false;
	bool pktRepository_i_5_r_0_t_5_busy = false;
	bool pktRepository_i_5_r_0_t_6_busy = false;
	bool pktRepository_i_5_r_0_t_7_busy = false;
	bool pktRepository_i_5_r_0_t_8_busy = false;
	bool pktRepository_i_5_r_0_t_9_busy = false;

	std::unordered_map<long, RawPkt*> pktRepository_i_5_r_1_t_0;
	std::unordered_map<long, RawPkt*> pktRepository_i_5_r_1_t_1;
	std::unordered_map<long, RawPkt*> pktRepository_i_5_r_1_t_2;
	std::unordered_map<long, RawPkt*> pktRepository_i_5_r_1_t_3;
	std::unordered_map<long, RawPkt*> pktRepository_i_5_r_1_t_4;
	std::unordered_map<long, RawPkt*> pktRepository_i_5_r_1_t_5;
	std::unordered_map<long, RawPkt*> pktRepository_i_5_r_1_t_6;
	std::unordered_map<long, RawPkt*> pktRepository_i_5_r_1_t_7;
	std::unordered_map<long, RawPkt*> pktRepository_i_5_r_1_t_8;
	std::unordered_map<long, RawPkt*> pktRepository_i_5_r_1_t_9;

	long pktRepository_i_5_r_1_t_0_cnt = 0;
	long pktRepository_i_5_r_1_t_1_cnt = 0;
	long pktRepository_i_5_r_1_t_2_cnt = 0;
	long pktRepository_i_5_r_1_t_3_cnt = 0;
	long pktRepository_i_5_r_1_t_4_cnt = 0;
	long pktRepository_i_5_r_1_t_5_cnt = 0;
	long pktRepository_i_5_r_1_t_6_cnt = 0;
	long pktRepository_i_5_r_1_t_7_cnt = 0;
	long pktRepository_i_5_r_1_t_8_cnt = 0;
	long pktRepository_i_5_r_1_t_9_cnt = 0;

	bool pktRepository_i_5_r_1_t_0_busy = false;
	bool pktRepository_i_5_r_1_t_1_busy = false;
	bool pktRepository_i_5_r_1_t_2_busy = false;
	bool pktRepository_i_5_r_1_t_3_busy = false;
	bool pktRepository_i_5_r_1_t_4_busy = false;
	bool pktRepository_i_5_r_1_t_5_busy = false;
	bool pktRepository_i_5_r_1_t_6_busy = false;
	bool pktRepository_i_5_r_1_t_7_busy = false;
	bool pktRepository_i_5_r_1_t_8_busy = false;
	bool pktRepository_i_5_r_1_t_9_busy = false;

	std::unordered_map<long, RawPkt*> pktRepository_i_5_r_2_t_0;
	std::unordered_map<long, RawPkt*> pktRepository_i_5_r_2_t_1;
	std::unordered_map<long, RawPkt*> pktRepository_i_5_r_2_t_2;
	std::unordered_map<long, RawPkt*> pktRepository_i_5_r_2_t_3;
	std::unordered_map<long, RawPkt*> pktRepository_i_5_r_2_t_4;
	std::unordered_map<long, RawPkt*> pktRepository_i_5_r_2_t_5;
	std::unordered_map<long, RawPkt*> pktRepository_i_5_r_2_t_6;
	std::unordered_map<long, RawPkt*> pktRepository_i_5_r_2_t_7;
	std::unordered_map<long, RawPkt*> pktRepository_i_5_r_2_t_8;
	std::unordered_map<long, RawPkt*> pktRepository_i_5_r_2_t_9;

	long pktRepository_i_5_r_2_t_0_cnt = 0;
	long pktRepository_i_5_r_2_t_1_cnt = 0;
	long pktRepository_i_5_r_2_t_2_cnt = 0;
	long pktRepository_i_5_r_2_t_3_cnt = 0;
	long pktRepository_i_5_r_2_t_4_cnt = 0;
	long pktRepository_i_5_r_2_t_5_cnt = 0;
	long pktRepository_i_5_r_2_t_6_cnt = 0;
	long pktRepository_i_5_r_2_t_7_cnt = 0;
	long pktRepository_i_5_r_2_t_8_cnt = 0;
	long pktRepository_i_5_r_2_t_9_cnt = 0;

	bool pktRepository_i_5_r_2_t_0_busy = false;
	bool pktRepository_i_5_r_2_t_1_busy = false;
	bool pktRepository_i_5_r_2_t_2_busy = false;
	bool pktRepository_i_5_r_2_t_3_busy = false;
	bool pktRepository_i_5_r_2_t_4_busy = false;
	bool pktRepository_i_5_r_2_t_5_busy = false;
	bool pktRepository_i_5_r_2_t_6_busy = false;
	bool pktRepository_i_5_r_2_t_7_busy = false;
	bool pktRepository_i_5_r_2_t_8_busy = false;
	bool pktRepository_i_5_r_2_t_9_busy = false;

	std::unordered_map<long, RawPkt*> pktRepository_i_5_r_3_t_0;
	std::unordered_map<long, RawPkt*> pktRepository_i_5_r_3_t_1;
	std::unordered_map<long, RawPkt*> pktRepository_i_5_r_3_t_2;
	std::unordered_map<long, RawPkt*> pktRepository_i_5_r_3_t_3;
	std::unordered_map<long, RawPkt*> pktRepository_i_5_r_3_t_4;
	std::unordered_map<long, RawPkt*> pktRepository_i_5_r_3_t_5;
	std::unordered_map<long, RawPkt*> pktRepository_i_5_r_3_t_6;
	std::unordered_map<long, RawPkt*> pktRepository_i_5_r_3_t_7;
	std::unordered_map<long, RawPkt*> pktRepository_i_5_r_3_t_8;
	std::unordered_map<long, RawPkt*> pktRepository_i_5_r_3_t_9;

	long pktRepository_i_5_r_3_t_0_cnt = 0;
	long pktRepository_i_5_r_3_t_1_cnt = 0;
	long pktRepository_i_5_r_3_t_2_cnt = 0;
	long pktRepository_i_5_r_3_t_3_cnt = 0;
	long pktRepository_i_5_r_3_t_4_cnt = 0;
	long pktRepository_i_5_r_3_t_5_cnt = 0;
	long pktRepository_i_5_r_3_t_6_cnt = 0;
	long pktRepository_i_5_r_3_t_7_cnt = 0;
	long pktRepository_i_5_r_3_t_8_cnt = 0;
	long pktRepository_i_5_r_3_t_9_cnt = 0;

	bool pktRepository_i_5_r_3_t_0_busy = false;
	bool pktRepository_i_5_r_3_t_1_busy = false;
	bool pktRepository_i_5_r_3_t_2_busy = false;
	bool pktRepository_i_5_r_3_t_3_busy = false;
	bool pktRepository_i_5_r_3_t_4_busy = false;
	bool pktRepository_i_5_r_3_t_5_busy = false;
	bool pktRepository_i_5_r_3_t_6_busy = false;
	bool pktRepository_i_5_r_3_t_7_busy = false;
	bool pktRepository_i_5_r_3_t_8_busy = false;
	bool pktRepository_i_5_r_3_t_9_busy = false;

	std::unordered_map<long, RawPkt*> pktRepository_i_5_r_4_t_0;
	std::unordered_map<long, RawPkt*> pktRepository_i_5_r_4_t_1;
	std::unordered_map<long, RawPkt*> pktRepository_i_5_r_4_t_2;
	std::unordered_map<long, RawPkt*> pktRepository_i_5_r_4_t_3;
	std::unordered_map<long, RawPkt*> pktRepository_i_5_r_4_t_4;
	std::unordered_map<long, RawPkt*> pktRepository_i_5_r_4_t_5;
	std::unordered_map<long, RawPkt*> pktRepository_i_5_r_4_t_6;
	std::unordered_map<long, RawPkt*> pktRepository_i_5_r_4_t_7;
	std::unordered_map<long, RawPkt*> pktRepository_i_5_r_4_t_8;
	std::unordered_map<long, RawPkt*> pktRepository_i_5_r_4_t_9;

	long pktRepository_i_5_r_4_t_0_cnt = 0;
	long pktRepository_i_5_r_4_t_1_cnt = 0;
	long pktRepository_i_5_r_4_t_2_cnt = 0;
	long pktRepository_i_5_r_4_t_3_cnt = 0;
	long pktRepository_i_5_r_4_t_4_cnt = 0;
	long pktRepository_i_5_r_4_t_5_cnt = 0;
	long pktRepository_i_5_r_4_t_6_cnt = 0;
	long pktRepository_i_5_r_4_t_7_cnt = 0;
	long pktRepository_i_5_r_4_t_8_cnt = 0;
	long pktRepository_i_5_r_4_t_9_cnt = 0;

	bool pktRepository_i_5_r_4_t_0_busy = false;
	bool pktRepository_i_5_r_4_t_1_busy = false;
	bool pktRepository_i_5_r_4_t_2_busy = false;
	bool pktRepository_i_5_r_4_t_3_busy = false;
	bool pktRepository_i_5_r_4_t_4_busy = false;
	bool pktRepository_i_5_r_4_t_5_busy = false;
	bool pktRepository_i_5_r_4_t_6_busy = false;
	bool pktRepository_i_5_r_4_t_7_busy = false;
	bool pktRepository_i_5_r_4_t_8_busy = false;
	bool pktRepository_i_5_r_4_t_9_busy = false;

	std::unordered_map<long, RawPkt*> pktRepository_i_5_r_5_t_0;
	std::unordered_map<long, RawPkt*> pktRepository_i_5_r_5_t_1;
	std::unordered_map<long, RawPkt*> pktRepository_i_5_r_5_t_2;
	std::unordered_map<long, RawPkt*> pktRepository_i_5_r_5_t_3;
	std::unordered_map<long, RawPkt*> pktRepository_i_5_r_5_t_4;
	std::unordered_map<long, RawPkt*> pktRepository_i_5_r_5_t_5;
	std::unordered_map<long, RawPkt*> pktRepository_i_5_r_5_t_6;
	std::unordered_map<long, RawPkt*> pktRepository_i_5_r_5_t_7;
	std::unordered_map<long, RawPkt*> pktRepository_i_5_r_5_t_8;
	std::unordered_map<long, RawPkt*> pktRepository_i_5_r_5_t_9;

	long pktRepository_i_5_r_5_t_0_cnt = 0;
	long pktRepository_i_5_r_5_t_1_cnt = 0;
	long pktRepository_i_5_r_5_t_2_cnt = 0;
	long pktRepository_i_5_r_5_t_3_cnt = 0;
	long pktRepository_i_5_r_5_t_4_cnt = 0;
	long pktRepository_i_5_r_5_t_5_cnt = 0;
	long pktRepository_i_5_r_5_t_6_cnt = 0;
	long pktRepository_i_5_r_5_t_7_cnt = 0;
	long pktRepository_i_5_r_5_t_8_cnt = 0;
	long pktRepository_i_5_r_5_t_9_cnt = 0;

	bool pktRepository_i_5_r_5_t_0_busy = false;
	bool pktRepository_i_5_r_5_t_1_busy = false;
	bool pktRepository_i_5_r_5_t_2_busy = false;
	bool pktRepository_i_5_r_5_t_3_busy = false;
	bool pktRepository_i_5_r_5_t_4_busy = false;
	bool pktRepository_i_5_r_5_t_5_busy = false;
	bool pktRepository_i_5_r_5_t_6_busy = false;
	bool pktRepository_i_5_r_5_t_7_busy = false;
	bool pktRepository_i_5_r_5_t_8_busy = false;
	bool pktRepository_i_5_r_5_t_9_busy = false;

	std::unordered_map<long, RawPkt*> pktRepository_i_5_r_6_t_0;
	std::unordered_map<long, RawPkt*> pktRepository_i_5_r_6_t_1;
	std::unordered_map<long, RawPkt*> pktRepository_i_5_r_6_t_2;
	std::unordered_map<long, RawPkt*> pktRepository_i_5_r_6_t_3;
	std::unordered_map<long, RawPkt*> pktRepository_i_5_r_6_t_4;
	std::unordered_map<long, RawPkt*> pktRepository_i_5_r_6_t_5;
	std::unordered_map<long, RawPkt*> pktRepository_i_5_r_6_t_6;
	std::unordered_map<long, RawPkt*> pktRepository_i_5_r_6_t_7;
	std::unordered_map<long, RawPkt*> pktRepository_i_5_r_6_t_8;
	std::unordered_map<long, RawPkt*> pktRepository_i_5_r_6_t_9;

	long pktRepository_i_5_r_6_t_0_cnt = 0;
	long pktRepository_i_5_r_6_t_1_cnt = 0;
	long pktRepository_i_5_r_6_t_2_cnt = 0;
	long pktRepository_i_5_r_6_t_3_cnt = 0;
	long pktRepository_i_5_r_6_t_4_cnt = 0;
	long pktRepository_i_5_r_6_t_5_cnt = 0;
	long pktRepository_i_5_r_6_t_6_cnt = 0;
	long pktRepository_i_5_r_6_t_7_cnt = 0;
	long pktRepository_i_5_r_6_t_8_cnt = 0;
	long pktRepository_i_5_r_6_t_9_cnt = 0;

	bool pktRepository_i_5_r_6_t_0_busy = false;
	bool pktRepository_i_5_r_6_t_1_busy = false;
	bool pktRepository_i_5_r_6_t_2_busy = false;
	bool pktRepository_i_5_r_6_t_3_busy = false;
	bool pktRepository_i_5_r_6_t_4_busy = false;
	bool pktRepository_i_5_r_6_t_5_busy = false;
	bool pktRepository_i_5_r_6_t_6_busy = false;
	bool pktRepository_i_5_r_6_t_7_busy = false;
	bool pktRepository_i_5_r_6_t_8_busy = false;
	bool pktRepository_i_5_r_6_t_9_busy = false;

	std::unordered_map<long, RawPkt*> pktRepository_i_5_r_7_t_0;
	std::unordered_map<long, RawPkt*> pktRepository_i_5_r_7_t_1;
	std::unordered_map<long, RawPkt*> pktRepository_i_5_r_7_t_2;
	std::unordered_map<long, RawPkt*> pktRepository_i_5_r_7_t_3;
	std::unordered_map<long, RawPkt*> pktRepository_i_5_r_7_t_4;
	std::unordered_map<long, RawPkt*> pktRepository_i_5_r_7_t_5;
	std::unordered_map<long, RawPkt*> pktRepository_i_5_r_7_t_6;
	std::unordered_map<long, RawPkt*> pktRepository_i_5_r_7_t_7;
	std::unordered_map<long, RawPkt*> pktRepository_i_5_r_7_t_8;
	std::unordered_map<long, RawPkt*> pktRepository_i_5_r_7_t_9;

	long pktRepository_i_5_r_7_t_0_cnt = 0;
	long pktRepository_i_5_r_7_t_1_cnt = 0;
	long pktRepository_i_5_r_7_t_2_cnt = 0;
	long pktRepository_i_5_r_7_t_3_cnt = 0;
	long pktRepository_i_5_r_7_t_4_cnt = 0;
	long pktRepository_i_5_r_7_t_5_cnt = 0;
	long pktRepository_i_5_r_7_t_6_cnt = 0;
	long pktRepository_i_5_r_7_t_7_cnt = 0;
	long pktRepository_i_5_r_7_t_8_cnt = 0;
	long pktRepository_i_5_r_7_t_9_cnt = 0;

	bool pktRepository_i_5_r_7_t_0_busy = false;
	bool pktRepository_i_5_r_7_t_1_busy = false;
	bool pktRepository_i_5_r_7_t_2_busy = false;
	bool pktRepository_i_5_r_7_t_3_busy = false;
	bool pktRepository_i_5_r_7_t_4_busy = false;
	bool pktRepository_i_5_r_7_t_5_busy = false;
	bool pktRepository_i_5_r_7_t_6_busy = false;
	bool pktRepository_i_5_r_7_t_7_busy = false;
	bool pktRepository_i_5_r_7_t_8_busy = false;
	bool pktRepository_i_5_r_7_t_9_busy = false;

	/* Interface_6 */
	std::unordered_map<long, RawPkt*> pktRepository_i_6_r_0_t_0;
	std::unordered_map<long, RawPkt*> pktRepository_i_6_r_0_t_1;
	std::unordered_map<long, RawPkt*> pktRepository_i_6_r_0_t_2;
	std::unordered_map<long, RawPkt*> pktRepository_i_6_r_0_t_3;
	std::unordered_map<long, RawPkt*> pktRepository_i_6_r_0_t_4;
	std::unordered_map<long, RawPkt*> pktRepository_i_6_r_0_t_5;
	std::unordered_map<long, RawPkt*> pktRepository_i_6_r_0_t_6;
	std::unordered_map<long, RawPkt*> pktRepository_i_6_r_0_t_7;
	std::unordered_map<long, RawPkt*> pktRepository_i_6_r_0_t_8;
	std::unordered_map<long, RawPkt*> pktRepository_i_6_r_0_t_9;

	long pktRepository_i_6_r_0_t_0_cnt = 0;
	long pktRepository_i_6_r_0_t_1_cnt = 0;
	long pktRepository_i_6_r_0_t_2_cnt = 0;
	long pktRepository_i_6_r_0_t_3_cnt = 0;
	long pktRepository_i_6_r_0_t_4_cnt = 0;
	long pktRepository_i_6_r_0_t_5_cnt = 0;
	long pktRepository_i_6_r_0_t_6_cnt = 0;
	long pktRepository_i_6_r_0_t_7_cnt = 0;
	long pktRepository_i_6_r_0_t_8_cnt = 0;
	long pktRepository_i_6_r_0_t_9_cnt = 0;

	bool pktRepository_i_6_r_0_t_0_busy = false;
	bool pktRepository_i_6_r_0_t_1_busy = false;
	bool pktRepository_i_6_r_0_t_2_busy = false;
	bool pktRepository_i_6_r_0_t_3_busy = false;
	bool pktRepository_i_6_r_0_t_4_busy = false;
	bool pktRepository_i_6_r_0_t_5_busy = false;
	bool pktRepository_i_6_r_0_t_6_busy = false;
	bool pktRepository_i_6_r_0_t_7_busy = false;
	bool pktRepository_i_6_r_0_t_8_busy = false;
	bool pktRepository_i_6_r_0_t_9_busy = false;

	std::unordered_map<long, RawPkt*> pktRepository_i_6_r_1_t_0;
	std::unordered_map<long, RawPkt*> pktRepository_i_6_r_1_t_1;
	std::unordered_map<long, RawPkt*> pktRepository_i_6_r_1_t_2;
	std::unordered_map<long, RawPkt*> pktRepository_i_6_r_1_t_3;
	std::unordered_map<long, RawPkt*> pktRepository_i_6_r_1_t_4;
	std::unordered_map<long, RawPkt*> pktRepository_i_6_r_1_t_5;
	std::unordered_map<long, RawPkt*> pktRepository_i_6_r_1_t_6;
	std::unordered_map<long, RawPkt*> pktRepository_i_6_r_1_t_7;
	std::unordered_map<long, RawPkt*> pktRepository_i_6_r_1_t_8;
	std::unordered_map<long, RawPkt*> pktRepository_i_6_r_1_t_9;

	long pktRepository_i_6_r_1_t_0_cnt = 0;
	long pktRepository_i_6_r_1_t_1_cnt = 0;
	long pktRepository_i_6_r_1_t_2_cnt = 0;
	long pktRepository_i_6_r_1_t_3_cnt = 0;
	long pktRepository_i_6_r_1_t_4_cnt = 0;
	long pktRepository_i_6_r_1_t_5_cnt = 0;
	long pktRepository_i_6_r_1_t_6_cnt = 0;
	long pktRepository_i_6_r_1_t_7_cnt = 0;
	long pktRepository_i_6_r_1_t_8_cnt = 0;
	long pktRepository_i_6_r_1_t_9_cnt = 0;

	bool pktRepository_i_6_r_1_t_0_busy = false;
	bool pktRepository_i_6_r_1_t_1_busy = false;
	bool pktRepository_i_6_r_1_t_2_busy = false;
	bool pktRepository_i_6_r_1_t_3_busy = false;
	bool pktRepository_i_6_r_1_t_4_busy = false;
	bool pktRepository_i_6_r_1_t_5_busy = false;
	bool pktRepository_i_6_r_1_t_6_busy = false;
	bool pktRepository_i_6_r_1_t_7_busy = false;
	bool pktRepository_i_6_r_1_t_8_busy = false;
	bool pktRepository_i_6_r_1_t_9_busy = false;

	std::unordered_map<long, RawPkt*> pktRepository_i_6_r_2_t_0;
	std::unordered_map<long, RawPkt*> pktRepository_i_6_r_2_t_1;
	std::unordered_map<long, RawPkt*> pktRepository_i_6_r_2_t_2;
	std::unordered_map<long, RawPkt*> pktRepository_i_6_r_2_t_3;
	std::unordered_map<long, RawPkt*> pktRepository_i_6_r_2_t_4;
	std::unordered_map<long, RawPkt*> pktRepository_i_6_r_2_t_5;
	std::unordered_map<long, RawPkt*> pktRepository_i_6_r_2_t_6;
	std::unordered_map<long, RawPkt*> pktRepository_i_6_r_2_t_7;
	std::unordered_map<long, RawPkt*> pktRepository_i_6_r_2_t_8;
	std::unordered_map<long, RawPkt*> pktRepository_i_6_r_2_t_9;

	long pktRepository_i_6_r_2_t_0_cnt = 0;
	long pktRepository_i_6_r_2_t_1_cnt = 0;
	long pktRepository_i_6_r_2_t_2_cnt = 0;
	long pktRepository_i_6_r_2_t_3_cnt = 0;
	long pktRepository_i_6_r_2_t_4_cnt = 0;
	long pktRepository_i_6_r_2_t_5_cnt = 0;
	long pktRepository_i_6_r_2_t_6_cnt = 0;
	long pktRepository_i_6_r_2_t_7_cnt = 0;
	long pktRepository_i_6_r_2_t_8_cnt = 0;
	long pktRepository_i_6_r_2_t_9_cnt = 0;

	bool pktRepository_i_6_r_2_t_0_busy = false;
	bool pktRepository_i_6_r_2_t_1_busy = false;
	bool pktRepository_i_6_r_2_t_2_busy = false;
	bool pktRepository_i_6_r_2_t_3_busy = false;
	bool pktRepository_i_6_r_2_t_4_busy = false;
	bool pktRepository_i_6_r_2_t_5_busy = false;
	bool pktRepository_i_6_r_2_t_6_busy = false;
	bool pktRepository_i_6_r_2_t_7_busy = false;
	bool pktRepository_i_6_r_2_t_8_busy = false;
	bool pktRepository_i_6_r_2_t_9_busy = false;

	std::unordered_map<long, RawPkt*> pktRepository_i_6_r_3_t_0;
	std::unordered_map<long, RawPkt*> pktRepository_i_6_r_3_t_1;
	std::unordered_map<long, RawPkt*> pktRepository_i_6_r_3_t_2;
	std::unordered_map<long, RawPkt*> pktRepository_i_6_r_3_t_3;
	std::unordered_map<long, RawPkt*> pktRepository_i_6_r_3_t_4;
	std::unordered_map<long, RawPkt*> pktRepository_i_6_r_3_t_5;
	std::unordered_map<long, RawPkt*> pktRepository_i_6_r_3_t_6;
	std::unordered_map<long, RawPkt*> pktRepository_i_6_r_3_t_7;
	std::unordered_map<long, RawPkt*> pktRepository_i_6_r_3_t_8;
	std::unordered_map<long, RawPkt*> pktRepository_i_6_r_3_t_9;

	long pktRepository_i_6_r_3_t_0_cnt = 0;
	long pktRepository_i_6_r_3_t_1_cnt = 0;
	long pktRepository_i_6_r_3_t_2_cnt = 0;
	long pktRepository_i_6_r_3_t_3_cnt = 0;
	long pktRepository_i_6_r_3_t_4_cnt = 0;
	long pktRepository_i_6_r_3_t_5_cnt = 0;
	long pktRepository_i_6_r_3_t_6_cnt = 0;
	long pktRepository_i_6_r_3_t_7_cnt = 0;
	long pktRepository_i_6_r_3_t_8_cnt = 0;
	long pktRepository_i_6_r_3_t_9_cnt = 0;

	bool pktRepository_i_6_r_3_t_0_busy = false;
	bool pktRepository_i_6_r_3_t_1_busy = false;
	bool pktRepository_i_6_r_3_t_2_busy = false;
	bool pktRepository_i_6_r_3_t_3_busy = false;
	bool pktRepository_i_6_r_3_t_4_busy = false;
	bool pktRepository_i_6_r_3_t_5_busy = false;
	bool pktRepository_i_6_r_3_t_6_busy = false;
	bool pktRepository_i_6_r_3_t_7_busy = false;
	bool pktRepository_i_6_r_3_t_8_busy = false;
	bool pktRepository_i_6_r_3_t_9_busy = false;

	std::unordered_map<long, RawPkt*> pktRepository_i_6_r_4_t_0;
	std::unordered_map<long, RawPkt*> pktRepository_i_6_r_4_t_1;
	std::unordered_map<long, RawPkt*> pktRepository_i_6_r_4_t_2;
	std::unordered_map<long, RawPkt*> pktRepository_i_6_r_4_t_3;
	std::unordered_map<long, RawPkt*> pktRepository_i_6_r_4_t_4;
	std::unordered_map<long, RawPkt*> pktRepository_i_6_r_4_t_5;
	std::unordered_map<long, RawPkt*> pktRepository_i_6_r_4_t_6;
	std::unordered_map<long, RawPkt*> pktRepository_i_6_r_4_t_7;
	std::unordered_map<long, RawPkt*> pktRepository_i_6_r_4_t_8;
	std::unordered_map<long, RawPkt*> pktRepository_i_6_r_4_t_9;

	long pktRepository_i_6_r_4_t_0_cnt = 0;
	long pktRepository_i_6_r_4_t_1_cnt = 0;
	long pktRepository_i_6_r_4_t_2_cnt = 0;
	long pktRepository_i_6_r_4_t_3_cnt = 0;
	long pktRepository_i_6_r_4_t_4_cnt = 0;
	long pktRepository_i_6_r_4_t_5_cnt = 0;
	long pktRepository_i_6_r_4_t_6_cnt = 0;
	long pktRepository_i_6_r_4_t_7_cnt = 0;
	long pktRepository_i_6_r_4_t_8_cnt = 0;
	long pktRepository_i_6_r_4_t_9_cnt = 0;

	bool pktRepository_i_6_r_4_t_0_busy = false;
	bool pktRepository_i_6_r_4_t_1_busy = false;
	bool pktRepository_i_6_r_4_t_2_busy = false;
	bool pktRepository_i_6_r_4_t_3_busy = false;
	bool pktRepository_i_6_r_4_t_4_busy = false;
	bool pktRepository_i_6_r_4_t_5_busy = false;
	bool pktRepository_i_6_r_4_t_6_busy = false;
	bool pktRepository_i_6_r_4_t_7_busy = false;
	bool pktRepository_i_6_r_4_t_8_busy = false;
	bool pktRepository_i_6_r_4_t_9_busy = false;

	std::unordered_map<long, RawPkt*> pktRepository_i_6_r_5_t_0;
	std::unordered_map<long, RawPkt*> pktRepository_i_6_r_5_t_1;
	std::unordered_map<long, RawPkt*> pktRepository_i_6_r_5_t_2;
	std::unordered_map<long, RawPkt*> pktRepository_i_6_r_5_t_3;
	std::unordered_map<long, RawPkt*> pktRepository_i_6_r_5_t_4;
	std::unordered_map<long, RawPkt*> pktRepository_i_6_r_5_t_5;
	std::unordered_map<long, RawPkt*> pktRepository_i_6_r_5_t_6;
	std::unordered_map<long, RawPkt*> pktRepository_i_6_r_5_t_7;
	std::unordered_map<long, RawPkt*> pktRepository_i_6_r_5_t_8;
	std::unordered_map<long, RawPkt*> pktRepository_i_6_r_5_t_9;

	long pktRepository_i_6_r_5_t_0_cnt = 0;
	long pktRepository_i_6_r_5_t_1_cnt = 0;
	long pktRepository_i_6_r_5_t_2_cnt = 0;
	long pktRepository_i_6_r_5_t_3_cnt = 0;
	long pktRepository_i_6_r_5_t_4_cnt = 0;
	long pktRepository_i_6_r_5_t_5_cnt = 0;
	long pktRepository_i_6_r_5_t_6_cnt = 0;
	long pktRepository_i_6_r_5_t_7_cnt = 0;
	long pktRepository_i_6_r_5_t_8_cnt = 0;
	long pktRepository_i_6_r_5_t_9_cnt = 0;

	bool pktRepository_i_6_r_5_t_0_busy = false;
	bool pktRepository_i_6_r_5_t_1_busy = false;
	bool pktRepository_i_6_r_5_t_2_busy = false;
	bool pktRepository_i_6_r_5_t_3_busy = false;
	bool pktRepository_i_6_r_5_t_4_busy = false;
	bool pktRepository_i_6_r_5_t_5_busy = false;
	bool pktRepository_i_6_r_5_t_6_busy = false;
	bool pktRepository_i_6_r_5_t_7_busy = false;
	bool pktRepository_i_6_r_5_t_8_busy = false;
	bool pktRepository_i_6_r_5_t_9_busy = false;

	std::unordered_map<long, RawPkt*> pktRepository_i_6_r_6_t_0;
	std::unordered_map<long, RawPkt*> pktRepository_i_6_r_6_t_1;
	std::unordered_map<long, RawPkt*> pktRepository_i_6_r_6_t_2;
	std::unordered_map<long, RawPkt*> pktRepository_i_6_r_6_t_3;
	std::unordered_map<long, RawPkt*> pktRepository_i_6_r_6_t_4;
	std::unordered_map<long, RawPkt*> pktRepository_i_6_r_6_t_5;
	std::unordered_map<long, RawPkt*> pktRepository_i_6_r_6_t_6;
	std::unordered_map<long, RawPkt*> pktRepository_i_6_r_6_t_7;
	std::unordered_map<long, RawPkt*> pktRepository_i_6_r_6_t_8;
	std::unordered_map<long, RawPkt*> pktRepository_i_6_r_6_t_9;

	long pktRepository_i_6_r_6_t_0_cnt = 0;
	long pktRepository_i_6_r_6_t_1_cnt = 0;
	long pktRepository_i_6_r_6_t_2_cnt = 0;
	long pktRepository_i_6_r_6_t_3_cnt = 0;
	long pktRepository_i_6_r_6_t_4_cnt = 0;
	long pktRepository_i_6_r_6_t_5_cnt = 0;
	long pktRepository_i_6_r_6_t_6_cnt = 0;
	long pktRepository_i_6_r_6_t_7_cnt = 0;
	long pktRepository_i_6_r_6_t_8_cnt = 0;
	long pktRepository_i_6_r_6_t_9_cnt = 0;

	bool pktRepository_i_6_r_6_t_0_busy = false;
	bool pktRepository_i_6_r_6_t_1_busy = false;
	bool pktRepository_i_6_r_6_t_2_busy = false;
	bool pktRepository_i_6_r_6_t_3_busy = false;
	bool pktRepository_i_6_r_6_t_4_busy = false;
	bool pktRepository_i_6_r_6_t_5_busy = false;
	bool pktRepository_i_6_r_6_t_6_busy = false;
	bool pktRepository_i_6_r_6_t_7_busy = false;
	bool pktRepository_i_6_r_6_t_8_busy = false;
	bool pktRepository_i_6_r_6_t_9_busy = false;

	std::unordered_map<long, RawPkt*> pktRepository_i_6_r_7_t_0;
	std::unordered_map<long, RawPkt*> pktRepository_i_6_r_7_t_1;
	std::unordered_map<long, RawPkt*> pktRepository_i_6_r_7_t_2;
	std::unordered_map<long, RawPkt*> pktRepository_i_6_r_7_t_3;
	std::unordered_map<long, RawPkt*> pktRepository_i_6_r_7_t_4;
	std::unordered_map<long, RawPkt*> pktRepository_i_6_r_7_t_5;
	std::unordered_map<long, RawPkt*> pktRepository_i_6_r_7_t_6;
	std::unordered_map<long, RawPkt*> pktRepository_i_6_r_7_t_7;
	std::unordered_map<long, RawPkt*> pktRepository_i_6_r_7_t_8;
	std::unordered_map<long, RawPkt*> pktRepository_i_6_r_7_t_9;

	long pktRepository_i_6_r_7_t_0_cnt = 0;
	long pktRepository_i_6_r_7_t_1_cnt = 0;
	long pktRepository_i_6_r_7_t_2_cnt = 0;
	long pktRepository_i_6_r_7_t_3_cnt = 0;
	long pktRepository_i_6_r_7_t_4_cnt = 0;
	long pktRepository_i_6_r_7_t_5_cnt = 0;
	long pktRepository_i_6_r_7_t_6_cnt = 0;
	long pktRepository_i_6_r_7_t_7_cnt = 0;
	long pktRepository_i_6_r_7_t_8_cnt = 0;
	long pktRepository_i_6_r_7_t_9_cnt = 0;

	bool pktRepository_i_6_r_7_t_0_busy = false;
	bool pktRepository_i_6_r_7_t_1_busy = false;
	bool pktRepository_i_6_r_7_t_2_busy = false;
	bool pktRepository_i_6_r_7_t_3_busy = false;
	bool pktRepository_i_6_r_7_t_4_busy = false;
	bool pktRepository_i_6_r_7_t_5_busy = false;
	bool pktRepository_i_6_r_7_t_6_busy = false;
	bool pktRepository_i_6_r_7_t_7_busy = false;
	bool pktRepository_i_6_r_7_t_8_busy = false;
	bool pktRepository_i_6_r_7_t_9_busy = false;


	/* Interface_7 */
	std::unordered_map<long, RawPkt*> pktRepository_i_7_r_0_t_0;
	std::unordered_map<long, RawPkt*> pktRepository_i_7_r_0_t_1;
	std::unordered_map<long, RawPkt*> pktRepository_i_7_r_0_t_2;
	std::unordered_map<long, RawPkt*> pktRepository_i_7_r_0_t_3;
	std::unordered_map<long, RawPkt*> pktRepository_i_7_r_0_t_4;
	std::unordered_map<long, RawPkt*> pktRepository_i_7_r_0_t_5;
	std::unordered_map<long, RawPkt*> pktRepository_i_7_r_0_t_6;
	std::unordered_map<long, RawPkt*> pktRepository_i_7_r_0_t_7;
	std::unordered_map<long, RawPkt*> pktRepository_i_7_r_0_t_8;
	std::unordered_map<long, RawPkt*> pktRepository_i_7_r_0_t_9;

	long pktRepository_i_7_r_0_t_0_cnt = 0;
	long pktRepository_i_7_r_0_t_1_cnt = 0;
	long pktRepository_i_7_r_0_t_2_cnt = 0;
	long pktRepository_i_7_r_0_t_3_cnt = 0;
	long pktRepository_i_7_r_0_t_4_cnt = 0;
	long pktRepository_i_7_r_0_t_5_cnt = 0;
	long pktRepository_i_7_r_0_t_6_cnt = 0;
	long pktRepository_i_7_r_0_t_7_cnt = 0;
	long pktRepository_i_7_r_0_t_8_cnt = 0;
	long pktRepository_i_7_r_0_t_9_cnt = 0;

	bool pktRepository_i_7_r_0_t_0_busy = false;
	bool pktRepository_i_7_r_0_t_1_busy = false;
	bool pktRepository_i_7_r_0_t_2_busy = false;
	bool pktRepository_i_7_r_0_t_3_busy = false;
	bool pktRepository_i_7_r_0_t_4_busy = false;
	bool pktRepository_i_7_r_0_t_5_busy = false;
	bool pktRepository_i_7_r_0_t_6_busy = false;
	bool pktRepository_i_7_r_0_t_7_busy = false;
	bool pktRepository_i_7_r_0_t_8_busy = false;
	bool pktRepository_i_7_r_0_t_9_busy = false;

	std::unordered_map<long, RawPkt*> pktRepository_i_7_r_1_t_0;
	std::unordered_map<long, RawPkt*> pktRepository_i_7_r_1_t_1;
	std::unordered_map<long, RawPkt*> pktRepository_i_7_r_1_t_2;
	std::unordered_map<long, RawPkt*> pktRepository_i_7_r_1_t_3;
	std::unordered_map<long, RawPkt*> pktRepository_i_7_r_1_t_4;
	std::unordered_map<long, RawPkt*> pktRepository_i_7_r_1_t_5;
	std::unordered_map<long, RawPkt*> pktRepository_i_7_r_1_t_6;
	std::unordered_map<long, RawPkt*> pktRepository_i_7_r_1_t_7;
	std::unordered_map<long, RawPkt*> pktRepository_i_7_r_1_t_8;
	std::unordered_map<long, RawPkt*> pktRepository_i_7_r_1_t_9;

	long pktRepository_i_7_r_1_t_0_cnt = 0;
	long pktRepository_i_7_r_1_t_1_cnt = 0;
	long pktRepository_i_7_r_1_t_2_cnt = 0;
	long pktRepository_i_7_r_1_t_3_cnt = 0;
	long pktRepository_i_7_r_1_t_4_cnt = 0;
	long pktRepository_i_7_r_1_t_5_cnt = 0;
	long pktRepository_i_7_r_1_t_6_cnt = 0;
	long pktRepository_i_7_r_1_t_7_cnt = 0;
	long pktRepository_i_7_r_1_t_8_cnt = 0;
	long pktRepository_i_7_r_1_t_9_cnt = 0;

	bool pktRepository_i_7_r_1_t_0_busy = false;
	bool pktRepository_i_7_r_1_t_1_busy = false;
	bool pktRepository_i_7_r_1_t_2_busy = false;
	bool pktRepository_i_7_r_1_t_3_busy = false;
	bool pktRepository_i_7_r_1_t_4_busy = false;
	bool pktRepository_i_7_r_1_t_5_busy = false;
	bool pktRepository_i_7_r_1_t_6_busy = false;
	bool pktRepository_i_7_r_1_t_7_busy = false;
	bool pktRepository_i_7_r_1_t_8_busy = false;
	bool pktRepository_i_7_r_1_t_9_busy = false;

	std::unordered_map<long, RawPkt*> pktRepository_i_7_r_2_t_0;
	std::unordered_map<long, RawPkt*> pktRepository_i_7_r_2_t_1;
	std::unordered_map<long, RawPkt*> pktRepository_i_7_r_2_t_2;
	std::unordered_map<long, RawPkt*> pktRepository_i_7_r_2_t_3;
	std::unordered_map<long, RawPkt*> pktRepository_i_7_r_2_t_4;
	std::unordered_map<long, RawPkt*> pktRepository_i_7_r_2_t_5;
	std::unordered_map<long, RawPkt*> pktRepository_i_7_r_2_t_6;
	std::unordered_map<long, RawPkt*> pktRepository_i_7_r_2_t_7;
	std::unordered_map<long, RawPkt*> pktRepository_i_7_r_2_t_8;
	std::unordered_map<long, RawPkt*> pktRepository_i_7_r_2_t_9;

	long pktRepository_i_7_r_2_t_0_cnt = 0;
	long pktRepository_i_7_r_2_t_1_cnt = 0;
	long pktRepository_i_7_r_2_t_2_cnt = 0;
	long pktRepository_i_7_r_2_t_3_cnt = 0;
	long pktRepository_i_7_r_2_t_4_cnt = 0;
	long pktRepository_i_7_r_2_t_5_cnt = 0;
	long pktRepository_i_7_r_2_t_6_cnt = 0;
	long pktRepository_i_7_r_2_t_7_cnt = 0;
	long pktRepository_i_7_r_2_t_8_cnt = 0;
	long pktRepository_i_7_r_2_t_9_cnt = 0;

	bool pktRepository_i_7_r_2_t_0_busy = false;
	bool pktRepository_i_7_r_2_t_1_busy = false;
	bool pktRepository_i_7_r_2_t_2_busy = false;
	bool pktRepository_i_7_r_2_t_3_busy = false;
	bool pktRepository_i_7_r_2_t_4_busy = false;
	bool pktRepository_i_7_r_2_t_5_busy = false;
	bool pktRepository_i_7_r_2_t_6_busy = false;
	bool pktRepository_i_7_r_2_t_7_busy = false;
	bool pktRepository_i_7_r_2_t_8_busy = false;
	bool pktRepository_i_7_r_2_t_9_busy = false;

	std::unordered_map<long, RawPkt*> pktRepository_i_7_r_3_t_0;
	std::unordered_map<long, RawPkt*> pktRepository_i_7_r_3_t_1;
	std::unordered_map<long, RawPkt*> pktRepository_i_7_r_3_t_2;
	std::unordered_map<long, RawPkt*> pktRepository_i_7_r_3_t_3;
	std::unordered_map<long, RawPkt*> pktRepository_i_7_r_3_t_4;
	std::unordered_map<long, RawPkt*> pktRepository_i_7_r_3_t_5;
	std::unordered_map<long, RawPkt*> pktRepository_i_7_r_3_t_6;
	std::unordered_map<long, RawPkt*> pktRepository_i_7_r_3_t_7;
	std::unordered_map<long, RawPkt*> pktRepository_i_7_r_3_t_8;
	std::unordered_map<long, RawPkt*> pktRepository_i_7_r_3_t_9;

	long pktRepository_i_7_r_3_t_0_cnt = 0;
	long pktRepository_i_7_r_3_t_1_cnt = 0;
	long pktRepository_i_7_r_3_t_2_cnt = 0;
	long pktRepository_i_7_r_3_t_3_cnt = 0;
	long pktRepository_i_7_r_3_t_4_cnt = 0;
	long pktRepository_i_7_r_3_t_5_cnt = 0;
	long pktRepository_i_7_r_3_t_6_cnt = 0;
	long pktRepository_i_7_r_3_t_7_cnt = 0;
	long pktRepository_i_7_r_3_t_8_cnt = 0;
	long pktRepository_i_7_r_3_t_9_cnt = 0;

	bool pktRepository_i_7_r_3_t_0_busy = false;
	bool pktRepository_i_7_r_3_t_1_busy = false;
	bool pktRepository_i_7_r_3_t_2_busy = false;
	bool pktRepository_i_7_r_3_t_3_busy = false;
	bool pktRepository_i_7_r_3_t_4_busy = false;
	bool pktRepository_i_7_r_3_t_5_busy = false;
	bool pktRepository_i_7_r_3_t_6_busy = false;
	bool pktRepository_i_7_r_3_t_7_busy = false;
	bool pktRepository_i_7_r_3_t_8_busy = false;
	bool pktRepository_i_7_r_3_t_9_busy = false;

	std::unordered_map<long, RawPkt*> pktRepository_i_7_r_4_t_0;
	std::unordered_map<long, RawPkt*> pktRepository_i_7_r_4_t_1;
	std::unordered_map<long, RawPkt*> pktRepository_i_7_r_4_t_2;
	std::unordered_map<long, RawPkt*> pktRepository_i_7_r_4_t_3;
	std::unordered_map<long, RawPkt*> pktRepository_i_7_r_4_t_4;
	std::unordered_map<long, RawPkt*> pktRepository_i_7_r_4_t_5;
	std::unordered_map<long, RawPkt*> pktRepository_i_7_r_4_t_6;
	std::unordered_map<long, RawPkt*> pktRepository_i_7_r_4_t_7;
	std::unordered_map<long, RawPkt*> pktRepository_i_7_r_4_t_8;
	std::unordered_map<long, RawPkt*> pktRepository_i_7_r_4_t_9;

	long pktRepository_i_7_r_4_t_0_cnt = 0;
	long pktRepository_i_7_r_4_t_1_cnt = 0;
	long pktRepository_i_7_r_4_t_2_cnt = 0;
	long pktRepository_i_7_r_4_t_3_cnt = 0;
	long pktRepository_i_7_r_4_t_4_cnt = 0;
	long pktRepository_i_7_r_4_t_5_cnt = 0;
	long pktRepository_i_7_r_4_t_6_cnt = 0;
	long pktRepository_i_7_r_4_t_7_cnt = 0;
	long pktRepository_i_7_r_4_t_8_cnt = 0;
	long pktRepository_i_7_r_4_t_9_cnt = 0;

	bool pktRepository_i_7_r_4_t_0_busy = false;
	bool pktRepository_i_7_r_4_t_1_busy = false;
	bool pktRepository_i_7_r_4_t_2_busy = false;
	bool pktRepository_i_7_r_4_t_3_busy = false;
	bool pktRepository_i_7_r_4_t_4_busy = false;
	bool pktRepository_i_7_r_4_t_5_busy = false;
	bool pktRepository_i_7_r_4_t_6_busy = false;
	bool pktRepository_i_7_r_4_t_7_busy = false;
	bool pktRepository_i_7_r_4_t_8_busy = false;
	bool pktRepository_i_7_r_4_t_9_busy = false;

	std::unordered_map<long, RawPkt*> pktRepository_i_7_r_5_t_0;
	std::unordered_map<long, RawPkt*> pktRepository_i_7_r_5_t_1;
	std::unordered_map<long, RawPkt*> pktRepository_i_7_r_5_t_2;
	std::unordered_map<long, RawPkt*> pktRepository_i_7_r_5_t_3;
	std::unordered_map<long, RawPkt*> pktRepository_i_7_r_5_t_4;
	std::unordered_map<long, RawPkt*> pktRepository_i_7_r_5_t_5;
	std::unordered_map<long, RawPkt*> pktRepository_i_7_r_5_t_6;
	std::unordered_map<long, RawPkt*> pktRepository_i_7_r_5_t_7;
	std::unordered_map<long, RawPkt*> pktRepository_i_7_r_5_t_8;
	std::unordered_map<long, RawPkt*> pktRepository_i_7_r_5_t_9;

	long pktRepository_i_7_r_5_t_0_cnt = 0;
	long pktRepository_i_7_r_5_t_1_cnt = 0;
	long pktRepository_i_7_r_5_t_2_cnt = 0;
	long pktRepository_i_7_r_5_t_3_cnt = 0;
	long pktRepository_i_7_r_5_t_4_cnt = 0;
	long pktRepository_i_7_r_5_t_5_cnt = 0;
	long pktRepository_i_7_r_5_t_6_cnt = 0;
	long pktRepository_i_7_r_5_t_7_cnt = 0;
	long pktRepository_i_7_r_5_t_8_cnt = 0;
	long pktRepository_i_7_r_5_t_9_cnt = 0;

	bool pktRepository_i_7_r_5_t_0_busy = false;
	bool pktRepository_i_7_r_5_t_1_busy = false;
	bool pktRepository_i_7_r_5_t_2_busy = false;
	bool pktRepository_i_7_r_5_t_3_busy = false;
	bool pktRepository_i_7_r_5_t_4_busy = false;
	bool pktRepository_i_7_r_5_t_5_busy = false;
	bool pktRepository_i_7_r_5_t_6_busy = false;
	bool pktRepository_i_7_r_5_t_7_busy = false;
	bool pktRepository_i_7_r_5_t_8_busy = false;
	bool pktRepository_i_7_r_5_t_9_busy = false;

	std::unordered_map<long, RawPkt*> pktRepository_i_7_r_6_t_0;
	std::unordered_map<long, RawPkt*> pktRepository_i_7_r_6_t_1;
	std::unordered_map<long, RawPkt*> pktRepository_i_7_r_6_t_2;
	std::unordered_map<long, RawPkt*> pktRepository_i_7_r_6_t_3;
	std::unordered_map<long, RawPkt*> pktRepository_i_7_r_6_t_4;
	std::unordered_map<long, RawPkt*> pktRepository_i_7_r_6_t_5;
	std::unordered_map<long, RawPkt*> pktRepository_i_7_r_6_t_6;
	std::unordered_map<long, RawPkt*> pktRepository_i_7_r_6_t_7;
	std::unordered_map<long, RawPkt*> pktRepository_i_7_r_6_t_8;
	std::unordered_map<long, RawPkt*> pktRepository_i_7_r_6_t_9;

	long pktRepository_i_7_r_6_t_0_cnt = 0;
	long pktRepository_i_7_r_6_t_1_cnt = 0;
	long pktRepository_i_7_r_6_t_2_cnt = 0;
	long pktRepository_i_7_r_6_t_3_cnt = 0;
	long pktRepository_i_7_r_6_t_4_cnt = 0;
	long pktRepository_i_7_r_6_t_5_cnt = 0;
	long pktRepository_i_7_r_6_t_6_cnt = 0;
	long pktRepository_i_7_r_6_t_7_cnt = 0;
	long pktRepository_i_7_r_6_t_8_cnt = 0;
	long pktRepository_i_7_r_6_t_9_cnt = 0;

	bool pktRepository_i_7_r_6_t_0_busy = false;
	bool pktRepository_i_7_r_6_t_1_busy = false;
	bool pktRepository_i_7_r_6_t_2_busy = false;
	bool pktRepository_i_7_r_6_t_3_busy = false;
	bool pktRepository_i_7_r_6_t_4_busy = false;
	bool pktRepository_i_7_r_6_t_5_busy = false;
	bool pktRepository_i_7_r_6_t_6_busy = false;
	bool pktRepository_i_7_r_6_t_7_busy = false;
	bool pktRepository_i_7_r_6_t_8_busy = false;
	bool pktRepository_i_7_r_6_t_9_busy = false;

	std::unordered_map<long, RawPkt*> pktRepository_i_7_r_7_t_0;
	std::unordered_map<long, RawPkt*> pktRepository_i_7_r_7_t_1;
	std::unordered_map<long, RawPkt*> pktRepository_i_7_r_7_t_2;
	std::unordered_map<long, RawPkt*> pktRepository_i_7_r_7_t_3;
	std::unordered_map<long, RawPkt*> pktRepository_i_7_r_7_t_4;
	std::unordered_map<long, RawPkt*> pktRepository_i_7_r_7_t_5;
	std::unordered_map<long, RawPkt*> pktRepository_i_7_r_7_t_6;
	std::unordered_map<long, RawPkt*> pktRepository_i_7_r_7_t_7;
	std::unordered_map<long, RawPkt*> pktRepository_i_7_r_7_t_8;
	std::unordered_map<long, RawPkt*> pktRepository_i_7_r_7_t_9;

	long pktRepository_i_7_r_7_t_0_cnt = 0;
	long pktRepository_i_7_r_7_t_1_cnt = 0;
	long pktRepository_i_7_r_7_t_2_cnt = 0;
	long pktRepository_i_7_r_7_t_3_cnt = 0;
	long pktRepository_i_7_r_7_t_4_cnt = 0;
	long pktRepository_i_7_r_7_t_5_cnt = 0;
	long pktRepository_i_7_r_7_t_6_cnt = 0;
	long pktRepository_i_7_r_7_t_7_cnt = 0;
	long pktRepository_i_7_r_7_t_8_cnt = 0;
	long pktRepository_i_7_r_7_t_9_cnt = 0;

	bool pktRepository_i_7_r_7_t_0_busy = false;
	bool pktRepository_i_7_r_7_t_1_busy = false;
	bool pktRepository_i_7_r_7_t_2_busy = false;
	bool pktRepository_i_7_r_7_t_3_busy = false;
	bool pktRepository_i_7_r_7_t_4_busy = false;
	bool pktRepository_i_7_r_7_t_5_busy = false;
	bool pktRepository_i_7_r_7_t_6_busy = false;
	bool pktRepository_i_7_r_7_t_7_busy = false;
	bool pktRepository_i_7_r_7_t_8_busy = false;
	bool pktRepository_i_7_r_7_t_9_busy = false;

}

namespace s1mmeSessionLock {
	pthread_mutex_t lockCount = PTHREAD_MUTEX_INITIALIZER;
	pthread_cond_t nonzero = PTHREAD_COND_INITIALIZER;
	unsigned count;
}

namespace vInterfaceLock {
	pthread_mutex_t readyMutex 	= PTHREAD_MUTEX_INITIALIZER;
	pthread_cond_t  readyCond  	= PTHREAD_COND_INITIALIZER;
	int             readyCount;
}

namespace s5s8SessionLock {
	pthread_mutex_t lockCount 	= PTHREAD_MUTEX_INITIALIZER;
	pthread_cond_t nonzero  	= PTHREAD_COND_INITIALIZER;
	unsigned count;
}

namespace s11SessionLock {
	pthread_mutex_t lockCount 	= PTHREAD_MUTEX_INITIALIZER;
	pthread_cond_t nonzero  	= PTHREAD_COND_INITIALIZER;
	unsigned count;
}

namespace dnsSessionLock {
	pthread_mutex_t lockCount = PTHREAD_MUTEX_INITIALIZER;
	pthread_cond_t nonzero = PTHREAD_COND_INITIALIZER;
	unsigned count;
}

namespace s1apSessionLock {
	pthread_mutex_t lockCount 	= PTHREAD_MUTEX_INITIALIZER;
	pthread_cond_t nonzero 		= PTHREAD_COND_INITIALIZER;
	unsigned count;
}
