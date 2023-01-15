/*************************************************************/
/* Copyright (C) 2019 OSS Nokalva, Inc.  All rights reserved.*/
/*************************************************************/

/* THIS FILE IS PROPRIETARY MATERIAL OF OSS NOKALVA, INC.
 * AND MAY BE USED ONLY BY DIRECT LICENSEES OF OSS NOKALVA, INC.
 * THIS FILE MAY NOT BE DISTRIBUTED.
 * THIS COPYRIGHT STATEMENT MAY NOT BE REMOVED. */

/* Generated for: Pinnacle Digital Analytics Pvt Ltd, New Delhi, India - Project Start-up expiring 26 July 2020, License 17395 17395,
 * only for project "Development and support of Mobility Packet Decoder". */
/* Abstract syntax: s1ap */
/* Created: Thu Dec 12 10:51:20 2019 */
/* ASN.1/C++ compiler version: 6.7 */
/* Code generated for runtime version 6.7 or later */
/* Compiler operating system: Linux with 64-bit support */
/* Compiler machine type: Intel 64 or AMD64 */
/* Target operating system: Linux with 64-bit support */
/* Target machine type: Intel 64 or AMD64 */
/* C++ compiler options required: -m64 */
/* ASN.1 compiler options and file names specified:
 * -toedfile -output s1ap -per -ber -root -autoencdec
 * ../../../asn1dflt.cpp.linux-amd64 s1ap.asn
 */

#ifndef OSS_s1ap
#define OSS_s1ap

#include "oss.h"
#include "asn1.h"

/* Representation types */

enum Criticality {
    reject = 0,
    ignore = 1,
    notify = 2
};

enum BearerType {
    non_IP = 0
};

enum CellAccessMode {
    hybrid = 0
};

enum CE_mode_B_SupportIndicator {
    CE_mode_B_SupportIndicator_supported = 0
};

enum Cdma2000RATType {
    hRPD = 0,
    onexRTT = 1
};

enum Cdma2000HOStatus {
    hOSuccess = 0,
    hOFailure = 1
};

enum Cdma2000HORequiredIndication {
    Cdma2000HORequiredIndication_true = 0
};

enum CNDomain {
    ps = 0,
    cs = 1
};

enum ConcurrentWarningMessageIndicator {
    ConcurrentWarningMessageIndicator_true = 0
};

enum CSFallbackIndicator {
    cs_fallback_required = 0,
    cs_fallback_high_priority = 1
};

enum AdditionalCSFallbackIndicator {
    no_restriction = 0,
    restriction = 1
};

enum CSGMembershipStatus {
    member = 0,
    not_member = 1
};

enum Direct_Forwarding_Path_Availability {
    directPathAvailable = 0
};

enum Data_Forwarding_Not_Possible {
    data_Forwarding_not_Possible = 0
};

enum GUMMEIType {
    native = 0,
    mapped = 1
};

enum GWContextReleaseIndication {
    GWContextReleaseIndication_true = 0
};

enum HandoverType {
    intralte = 0,
    HandoverType_ltetoutran = 1,
    HandoverType_ltetogeran = 2,
    utrantolte = 3,
    gerantolte = 4
};

enum KillAllWarningMessages {
    KillAllWarningMessages_true = 0
};

enum ManagementBasedMDTAllowed {
    allowed = 0
};

enum PrivacyIndicator {
    immediate_MDT = 0,
    logged_MDT = 1
};

enum MMERelaySupportIndicator {
    MMERelaySupportIndicator_true = 0
};

enum MutingAvailabilityIndication {
    available = 0,
    unavailable = 1
};

enum NB_IoT_DefaultPagingDRX {
    NB_IoT_DefaultPagingDRX_v128 = 0,
    NB_IoT_DefaultPagingDRX_v256 = 1,
    v512 = 2,
    v1024 = 3
};

enum PagingDRX {
    v32 = 0,
    v64 = 1,
    PagingDRX_v128 = 2,
    PagingDRX_v256 = 3
};

enum PagingPriority {
    priolevel1 = 0,
    priolevel2 = 1,
    priolevel3 = 2,
    priolevel4 = 3,
    priolevel5 = 4,
    priolevel6 = 5,
    priolevel7 = 6,
    priolevel8 = 7
};

enum ProSeUEtoNetworkRelaying {
    ProSeUEtoNetworkRelaying_authorized = 0,
    ProSeUEtoNetworkRelaying_not_authorized = 1
};

enum PS_ServiceNotAvailable {
    ps_service_not_available = 0
};

enum RelayNode_Indicator {
    RelayNode_Indicator_true = 0
};

enum RAT_Type {
    nbiot = 0
};

enum RRC_Establishment_Cause {
    emergency = 0,
    highPriorityAccess = 1,
    mt_Access = 2,
    mo_Signalling = 3,
    mo_Data = 4,
    delay_TolerantAccess = 5,
    mo_VoiceCall = 6,
    mo_ExceptionData = 7
};

enum SRVCCOperationNotPossible {
    notPossible = 0
};

enum SRVCCOperationPossible {
    possible = 0
};

enum SRVCCHOIndication {
    pSandCS = 0,
    cSonly = 1
};

enum TimeToWait {
    v1s = 0,
    v2s = 1,
    v5s = 2,
    v10s = 3,
    v20s = 4,
    v60s = 5
};

enum UE_RetentionInformation {
    ues_retained = 0
};

enum UEUserPlaneCIoTSupportIndicator {
    UEUserPlaneCIoTSupportIndicator_supported = 0
};

enum VoiceSupportMatchIndicator {
    VoiceSupportMatchIndicator_supported = 0,
    not_supported = 1
};

enum SONtransferApplicationIdentity {
    cell_load_reporting = 0,
    multi_cell_load_reporting = 1,
    event_triggered_cell_load_reporting = 2,
    ho_reporting = 3,
    eutran_cell_activation = 4,
    energy_savings_indication = 5,
    failure_event_reporting = 6
};

enum Pre_emptionCapability {
    shall_not_trigger_pre_emption = 0,
    may_trigger_pre_emption = 1
};

enum Pre_emptionVulnerability {
    not_pre_emptable = 0,
    pre_emptable = 1
};

enum CauseRadioNetwork {
    CauseRadioNetwork_unspecified = 0,
    tx2relocoverall_expiry = 1,
    successful_handover = 2,
    release_due_to_eutran_generated_reason = 3,
    handover_cancelled = 4,
    partial_handover = 5,
    ho_failure_in_target_EPC_eNB_or_target_system = 6,
    ho_target_not_allowed = 7,
    tS1relocoverall_expiry = 8,
    tS1relocprep_expiry = 9,
    cell_not_available = 10,
    unknown_targetID = 11,
    no_radio_resources_available_in_target_cell = 12,
    unknown_mme_ue_s1ap_id = 13,
    unknown_enb_ue_s1ap_id = 14,
    unknown_pair_ue_s1ap_id = 15,
    handover_desirable_for_radio_reason = 16,
    time_critical_handover = 17,
    resource_optimisation_handover = 18,
    reduce_load_in_serving_cell = 19,
    user_inactivity = 20,
    radio_connection_with_ue_lost = 21,
    load_balancing_tau_required = 22,
    cs_fallback_triggered = 23,
    ue_not_available_for_ps_service = 24,
    radio_resources_not_available = 25,
    failure_in_radio_interface_procedure = 26,
    invalid_qos_combination = 27,
    interrat_redirection = 28,
    interaction_with_other_procedure = 29,
    unknown_E_RAB_ID = 30,
    multiple_E_RAB_ID_instances = 31,
    encryption_and_or_integrity_protection_algorithms_not_supported = 32,
    s1_intra_system_handover_triggered = 33,
    s1_inter_system_handover_triggered = 34,
    x2_handover_triggered = 35,
    redirection_towards_1xRTT = 36,
    not_supported_QCI_value = 37,
    invalid_CSG_Id = 38
};

enum CauseTransport {
    transport_resource_unavailable = 0,
    CauseTransport_unspecified = 1
};

enum CauseNas {
    normal_release = 0,
    authentication_failure = 1,
    detach = 2,
    CauseNas_unspecified = 3,
    csg_subscription_expiry = 4
};

enum CauseProtocol {
    transfer_syntax_error = 0,
    abstract_syntax_error_reject = 1,
    abstract_syntax_error_ignore_and_notify = 2,
    message_not_compatible_with_receiver_state = 3,
    semantic_error = 4,
    abstract_syntax_error_falsely_constructed_message = 5,
    CauseProtocol_unspecified = 6
};

enum CauseMisc {
    control_processing_overload = 0,
    not_enough_user_plane_processing_resources = 1,
    hardware_failure = 2,
    om_intervention = 3,
    CauseMisc_unspecified = 4,
    unknown_PLMN = 5
};

enum ResetAll {
    reset_all = 0
};

enum NextPagingAreaScope {
    same = 0,
    changed = 1
};

enum Cell_Size {
    verysmall = 0,
    Cell_Size_small = 1,
    Cell_Size_medium = 2,
    large = 3
};

enum TriggeringMessage {
    initiating_message = 0,
    successful_outcome = 1,
    unsuccessfull_outcome = 2
};

enum TypeOfError {
    not_understood = 0,
    missing = 1
};

enum DL_Forwarding {
    dL_Forwarding_proposed = 0
};

enum EventType {
    direct = 0,
    change_of_serve_cell = 1,
    stop_change_of_serve_cell = 2
};

enum SourceOfUEActivityBehaviourInformation {
    subscription_information = 0,
    statistics = 1
};

enum ExpectedHOInterval {
    sec15 = 0,
    sec30 = 1,
    sec60 = 2,
    sec90 = 3,
    sec120 = 4,
    sec180 = 5,
    long_time = 6
};

enum ForbiddenInterRATs {
    all = 0,
    geran = 1,
    utran = 2,
    cdma2000 = 3,
    geranandutran = 4,
    cdma2000andutran = 5
};

enum M1ReportingTrigger {
    periodic = 0,
    a2eventtriggered = 1,
    a2eventtriggered_periodic = 2
};

enum ReportIntervalMDT {
    ms120 = 0,
    ms240 = 1,
    ms480 = 2,
    ms640 = 3,
    ReportIntervalMDT_ms1024 = 4,
    ReportIntervalMDT_ms2048 = 5,
    ReportIntervalMDT_ms5120 = 6,
    ReportIntervalMDT_ms10240 = 7,
    ReportIntervalMDT_min1 = 8,
    min6 = 9,
    min12 = 10,
    min30 = 11,
    min60 = 12
};

enum ReportAmountMDT {
    r1 = 0,
    r2 = 1,
    r4 = 2,
    r8 = 3,
    r16 = 4,
    r32 = 5,
    r64 = 6,
    rinfinity = 7
};

enum Links_to_log {
    uplink = 0,
    downlink = 1,
    both_uplink_and_downlink = 2
};

enum _enum1 {
    pattern_period_ms1280 = 0,
    pattern_period_ms2560 = 1,
    pattern_period_ms5120 = 2,
    pattern_period_ms10240 = 3
};

enum LoggingInterval {
    ms128 = 0,
    ms256 = 1,
    ms512 = 2,
    LoggingInterval_ms1024 = 3,
    LoggingInterval_ms2048 = 4,
    ms3072 = 5,
    ms4096 = 6,
    ms6144 = 7
};

enum LoggingDuration {
    m10 = 0,
    m20 = 1,
    m40 = 2,
    m60 = 3,
    m90 = 4,
    m120 = 5
};

enum M3period {
    M3period_ms100 = 0,
    ms1000 = 1,
    ms10000 = 2
};

enum M4period {
    M4period_ms1024 = 0,
    M4period_ms2048 = 1,
    M4period_ms5120 = 2,
    M4period_ms10240 = 3,
    M4period_min1 = 4
};

enum M5period {
    M5period_ms1024 = 0,
    M5period_ms2048 = 1,
    M5period_ms5120 = 2,
    M5period_ms10240 = 3,
    M5period_min1 = 4
};

enum M6report_Interval {
    M6report_Interval_ms1024 = 0,
    M6report_Interval_ms2048 = 1,
    M6report_Interval_ms5120 = 2,
    M6report_Interval_ms10240 = 3
};

enum M6delay_threshold {
    ms30 = 0,
    ms40 = 1,
    ms50 = 2,
    ms60 = 3,
    ms70 = 4,
    ms80 = 5,
    ms90 = 6,
    M6delay_threshold_ms100 = 7,
    ms150 = 8,
    ms300 = 9,
    ms500 = 10,
    ms750 = 11
};

enum MDT_Activation {
    immediate_MDT_only = 0,
    immediate_MDT_and_Trace = 1,
    logged_MDT_only = 2,
    logged_MBSFN_MDT = 3
};

enum _enum2 {
    ms0 = 0,
    muting_pattern_period_ms1280 = 1,
    muting_pattern_period_ms2560 = 2,
    muting_pattern_period_ms5120 = 3,
    muting_pattern_period_ms10240 = 4
};

enum NB_IoT_Paging_eDRX_Cycle {
    NB_IoT_Paging_eDRX_Cycle_hf2 = 0,
    NB_IoT_Paging_eDRX_Cycle_hf4 = 1,
    NB_IoT_Paging_eDRX_Cycle_hf6 = 2,
    NB_IoT_Paging_eDRX_Cycle_hf8 = 3,
    NB_IoT_Paging_eDRX_Cycle_hf10 = 4,
    NB_IoT_Paging_eDRX_Cycle_hf12 = 5,
    NB_IoT_Paging_eDRX_Cycle_hf14 = 6,
    NB_IoT_Paging_eDRX_Cycle_hf16 = 7,
    NB_IoT_Paging_eDRX_Cycle_hf32 = 8,
    NB_IoT_Paging_eDRX_Cycle_hf64 = 9,
    NB_IoT_Paging_eDRX_Cycle_hf128 = 10,
    NB_IoT_Paging_eDRX_Cycle_hf256 = 11,
    hf512 = 12,
    hf1024 = 13
};

enum NB_IoT_PagingTimeWindow {
    NB_IoT_PagingTimeWindow_s1 = 0,
    NB_IoT_PagingTimeWindow_s2 = 1,
    NB_IoT_PagingTimeWindow_s3 = 2,
    NB_IoT_PagingTimeWindow_s4 = 3,
    NB_IoT_PagingTimeWindow_s5 = 4,
    NB_IoT_PagingTimeWindow_s6 = 5,
    NB_IoT_PagingTimeWindow_s7 = 6,
    NB_IoT_PagingTimeWindow_s8 = 7,
    NB_IoT_PagingTimeWindow_s9 = 8,
    NB_IoT_PagingTimeWindow_s10 = 9,
    NB_IoT_PagingTimeWindow_s11 = 10,
    NB_IoT_PagingTimeWindow_s12 = 11,
    NB_IoT_PagingTimeWindow_s13 = 12,
    NB_IoT_PagingTimeWindow_s14 = 13,
    NB_IoT_PagingTimeWindow_s15 = 14,
    NB_IoT_PagingTimeWindow_s16 = 15
};

enum OverloadAction {
    reject_non_emergency_mo_dt = 0,
    reject_rrc_cr_signalling = 1,
    permit_emergency_sessions_and_mobile_terminated_services_only = 2,
    permit_high_priority_sessions_and_mobile_terminated_services_only = 3,
    reject_delay_tolerant_access = 4,
    permit_high_priority_sessions_and_exception_reporting_and_mobile_terminated_services_only = 5
};

enum Paging_eDRX_Cycle {
    hfhalf = 0,
    hf1 = 1,
    Paging_eDRX_Cycle_hf2 = 2,
    Paging_eDRX_Cycle_hf4 = 3,
    Paging_eDRX_Cycle_hf6 = 4,
    Paging_eDRX_Cycle_hf8 = 5,
    Paging_eDRX_Cycle_hf10 = 6,
    Paging_eDRX_Cycle_hf12 = 7,
    Paging_eDRX_Cycle_hf14 = 8,
    Paging_eDRX_Cycle_hf16 = 9,
    Paging_eDRX_Cycle_hf32 = 10,
    Paging_eDRX_Cycle_hf64 = 11,
    Paging_eDRX_Cycle_hf128 = 12,
    Paging_eDRX_Cycle_hf256 = 13
};

enum PagingTimeWindow {
    PagingTimeWindow_s1 = 0,
    PagingTimeWindow_s2 = 1,
    PagingTimeWindow_s3 = 2,
    PagingTimeWindow_s4 = 3,
    PagingTimeWindow_s5 = 4,
    PagingTimeWindow_s6 = 5,
    PagingTimeWindow_s7 = 6,
    PagingTimeWindow_s8 = 7,
    PagingTimeWindow_s9 = 8,
    PagingTimeWindow_s10 = 9,
    PagingTimeWindow_s11 = 10,
    PagingTimeWindow_s12 = 11,
    PagingTimeWindow_s13 = 12,
    PagingTimeWindow_s14 = 13,
    PagingTimeWindow_s15 = 14,
    PagingTimeWindow_s16 = 15
};

enum ProSeDirectDiscovery {
    ProSeDirectDiscovery_authorized = 0,
    ProSeDirectDiscovery_not_authorized = 1
};

enum ProSeDirectCommunication {
    ProSeDirectCommunication_authorized = 0,
    ProSeDirectCommunication_not_authorized = 1
};

enum ReportArea {
    ecgi = 0
};

enum SONInformationRequest {
    x2TNL_Configuration_Info = 0,
    time_Synchronisation_Info = 1,
    activate_Muting = 2,
    deactivate_Muting = 3
};

enum SynchronisationStatus {
    synchronous = 0,
    asynchronous = 1
};

enum TraceDepth {
    minimum = 0,
    TraceDepth_medium = 1,
    maximum = 2,
    minimumWithoutVendorSpecificExtension = 3,
    mediumWithoutVendorSpecificExtension = 4,
    maximumWithoutVendorSpecificExtension = 5
};

enum Presence {
    optional = 0,
    conditional = 1,
    mandatory = 2
};

enum CellLoadReportingCause {
    CellLoadReportingCause_application_container_syntax_error = 0,
    CellLoadReportingCause_inconsistent_reporting_cell_identifier = 1,
    CellLoadReportingCause_unspecified = 2
};

enum HOReportingCause {
    HOReportingCause_application_container_syntax_error = 0,
    HOReportingCause_inconsistent_reporting_cell_identifier = 1,
    HOReportingCause_unspecified = 2
};

enum CellActivationCause {
    CellActivationCause_application_container_syntax_error = 0,
    CellActivationCause_inconsistent_reporting_cell_identifier = 1,
    CellActivationCause_unspecified = 2
};

enum CellStateIndicationCause {
    CellStateIndicationCause_application_container_syntax_error = 0,
    CellStateIndicationCause_inconsistent_reporting_cell_identifier = 1,
    CellStateIndicationCause_unspecified = 2
};

enum FailureEventReportingCause {
    FailureEventReportingCause_application_container_syntax_error = 0,
    FailureEventReportingCause_inconsistent_reporting_cell_identifier = 1,
    FailureEventReportingCause_unspecified = 2
};

enum NumberOfMeasurementReportingLevels {
    rl2 = 0,
    rl3 = 1,
    rl4 = 2,
    rl5 = 3,
    rl10 = 4
};

enum OverloadFlag {
    overload = 0
};

enum HoType {
    HoType_ltetoutran = 0,
    HoType_ltetogeran = 1
};

enum HoReportType {
    unnecessaryhotoanotherrat = 0,
    earlyirathandover = 1
};

enum NotifyFlag {
    activated = 0,
    deactivated = 1
};


const OSS_UINT32 spare = 0;
const OSS_UINT32 highest = 1;
const OSS_UINT32 lowest = 14;
const OSS_UINT32 no_priority = 15;
typedef OSS_UINT32 ProcedureCode;

class OSS_PUBLIC __seq1;

class OSS_PUBLIC __seqof1 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq1 component;

    __seqof1();
    __seqof1(const __seqof1 &);
    ~__seqof1();

    __seqof1 & operator = (const __seqof1 &);
    int operator == (const __seqof1 &) const;
    int operator != (const __seqof1 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof1 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof1 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof1 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC HandoverRequired   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __seqof1 protocolIEs;

    HandoverRequired();
    HandoverRequired(const HandoverRequired &);
    HandoverRequired(const protocolIEs &);

    HandoverRequired & operator = (const HandoverRequired &);
    int operator == (const HandoverRequired &) const;
    int operator != (const HandoverRequired &) const;

    protocolIEs & get_protocolIEs();
    const protocolIEs & get_protocolIEs() const;
    void set_protocolIEs(const protocolIEs &);
private:
    protocolIEs protocolIEs_field;
};

class OSS_PUBLIC __seq6;

class OSS_PUBLIC __seqof5 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq6 component;

    __seqof5();
    __seqof5(const __seqof5 &);
    ~__seqof5();

    __seqof5 & operator = (const __seqof5 &);
    int operator == (const __seqof5 &) const;
    int operator != (const __seqof5 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof5 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof5 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof5 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC HandoverRequest   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __seqof5 protocolIEs;

    HandoverRequest();
    HandoverRequest(const HandoverRequest &);
    HandoverRequest(const protocolIEs &);

    HandoverRequest & operator = (const HandoverRequest &);
    int operator == (const HandoverRequest &) const;
    int operator != (const HandoverRequest &) const;

    protocolIEs & get_protocolIEs();
    const protocolIEs & get_protocolIEs() const;
    void set_protocolIEs(const protocolIEs &);
private:
    protocolIEs protocolIEs_field;
};

class OSS_PUBLIC __seq19;

class OSS_PUBLIC __seqof15 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq19 component;

    __seqof15();
    __seqof15(const __seqof15 &);
    ~__seqof15();

    __seqof15 & operator = (const __seqof15 &);
    int operator == (const __seqof15 &) const;
    int operator != (const __seqof15 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof15 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof15 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof15 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC PathSwitchRequest   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __seqof15 protocolIEs;

    PathSwitchRequest();
    PathSwitchRequest(const PathSwitchRequest &);
    PathSwitchRequest(const protocolIEs &);

    PathSwitchRequest & operator = (const PathSwitchRequest &);
    int operator == (const PathSwitchRequest &) const;
    int operator != (const PathSwitchRequest &) const;

    protocolIEs & get_protocolIEs();
    const protocolIEs & get_protocolIEs() const;
    void set_protocolIEs(const protocolIEs &);
private:
    protocolIEs protocolIEs_field;
};

class OSS_PUBLIC __seq28;

class OSS_PUBLIC __seqof22 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq28 component;

    __seqof22();
    __seqof22(const __seqof22 &);
    ~__seqof22();

    __seqof22 & operator = (const __seqof22 &);
    int operator == (const __seqof22 &) const;
    int operator != (const __seqof22 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof22 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof22 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof22 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC E_RABSetupRequest   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __seqof22 protocolIEs;

    E_RABSetupRequest();
    E_RABSetupRequest(const E_RABSetupRequest &);
    E_RABSetupRequest(const protocolIEs &);

    E_RABSetupRequest & operator = (const E_RABSetupRequest &);
    int operator == (const E_RABSetupRequest &) const;
    int operator != (const E_RABSetupRequest &) const;

    protocolIEs & get_protocolIEs();
    const protocolIEs & get_protocolIEs() const;
    void set_protocolIEs(const protocolIEs &);
private:
    protocolIEs protocolIEs_field;
};

class OSS_PUBLIC __seq34;

class OSS_PUBLIC __seqof26 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq34 component;

    __seqof26();
    __seqof26(const __seqof26 &);
    ~__seqof26();

    __seqof26 & operator = (const __seqof26 &);
    int operator == (const __seqof26 &) const;
    int operator != (const __seqof26 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof26 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof26 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof26 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC E_RABModifyRequest   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __seqof26 protocolIEs;

    E_RABModifyRequest();
    E_RABModifyRequest(const E_RABModifyRequest &);
    E_RABModifyRequest(const protocolIEs &);

    E_RABModifyRequest & operator = (const E_RABModifyRequest &);
    int operator == (const E_RABModifyRequest &) const;
    int operator != (const E_RABModifyRequest &) const;

    protocolIEs & get_protocolIEs();
    const protocolIEs & get_protocolIEs() const;
    void set_protocolIEs(const protocolIEs &);
private:
    protocolIEs protocolIEs_field;
};

class OSS_PUBLIC __seq40;

class OSS_PUBLIC __seqof30 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq40 component;

    __seqof30();
    __seqof30(const __seqof30 &);
    ~__seqof30();

    __seqof30 & operator = (const __seqof30 &);
    int operator == (const __seqof30 &) const;
    int operator != (const __seqof30 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof30 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof30 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof30 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC E_RABReleaseCommand   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __seqof30 protocolIEs;

    E_RABReleaseCommand();
    E_RABReleaseCommand(const E_RABReleaseCommand &);
    E_RABReleaseCommand(const protocolIEs &);

    E_RABReleaseCommand & operator = (const E_RABReleaseCommand &);
    int operator == (const E_RABReleaseCommand &) const;
    int operator != (const E_RABReleaseCommand &) const;

    protocolIEs & get_protocolIEs();
    const protocolIEs & get_protocolIEs() const;
    void set_protocolIEs(const protocolIEs &);
private:
    protocolIEs protocolIEs_field;
};

class OSS_PUBLIC __seq45;

class OSS_PUBLIC __seqof34 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq45 component;

    __seqof34();
    __seqof34(const __seqof34 &);
    ~__seqof34();

    __seqof34 & operator = (const __seqof34 &);
    int operator == (const __seqof34 &) const;
    int operator != (const __seqof34 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof34 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof34 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof34 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC InitialContextSetupRequest   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __seqof34 protocolIEs;

    InitialContextSetupRequest();
    InitialContextSetupRequest(const InitialContextSetupRequest &);
    InitialContextSetupRequest(const protocolIEs &);

    InitialContextSetupRequest & operator = (const InitialContextSetupRequest &);
    int operator == (const InitialContextSetupRequest &) const;
    int operator != (const InitialContextSetupRequest &) const;

    protocolIEs & get_protocolIEs();
    const protocolIEs & get_protocolIEs() const;
    void set_protocolIEs(const protocolIEs &);
private:
    protocolIEs protocolIEs_field;
};

class OSS_PUBLIC __shared12;

class OSS_PUBLIC __shared13 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __shared12 component;

    __shared13();
    __shared13(const __shared13 &);
    ~__shared13();

    __shared13 & operator = (const __shared13 &);
    int operator == (const __shared13 &) const;
    int operator != (const __shared13 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__shared13 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __shared13 *);

    int remove_front();
    int remove_after(OssIndex);

    __shared13 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC __shared14   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __shared13 protocolIEs;

    __shared14();
    __shared14(const __shared14 &);
    __shared14(const protocolIEs &);

    __shared14 & operator = (const __shared14 &);
    int operator == (const __shared14 &) const;
    int operator != (const __shared14 &) const;

    protocolIEs & get_protocolIEs();
    const protocolIEs & get_protocolIEs() const;
    void set_protocolIEs(const protocolIEs &);
private:
    protocolIEs protocolIEs_field;
};

typedef __shared14 HandoverCancel;

class OSS_PUBLIC __seq103;

class OSS_PUBLIC __seqof88 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq103 component;

    __seqof88();
    __seqof88(const __seqof88 &);
    ~__seqof88();

    __seqof88 & operator = (const __seqof88 &);
    int operator == (const __seqof88 &) const;
    int operator != (const __seqof88 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof88 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof88 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof88 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC KillRequest   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __seqof88 protocolIEs;

    KillRequest();
    KillRequest(const KillRequest &);
    KillRequest(const protocolIEs &);

    KillRequest & operator = (const KillRequest &);
    int operator == (const KillRequest &) const;
    int operator != (const KillRequest &) const;

    protocolIEs & get_protocolIEs();
    const protocolIEs & get_protocolIEs() const;
    void set_protocolIEs(const protocolIEs &);
private:
    protocolIEs protocolIEs_field;
};

class OSS_PUBLIC __seq69;

class OSS_PUBLIC __seqof55 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq69 component;

    __seqof55();
    __seqof55(const __seqof55 &);
    ~__seqof55();

    __seqof55 & operator = (const __seqof55 &);
    int operator == (const __seqof55 &) const;
    int operator != (const __seqof55 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof55 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof55 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof55 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC Reset   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __seqof55 protocolIEs;

    Reset();
    Reset(const Reset &);
    Reset(const protocolIEs &);

    Reset & operator = (const Reset &);
    int operator == (const Reset &) const;
    int operator != (const Reset &) const;

    protocolIEs & get_protocolIEs();
    const protocolIEs & get_protocolIEs() const;
    void set_protocolIEs(const protocolIEs &);
private:
    protocolIEs protocolIEs_field;
};

class OSS_PUBLIC __seq74;

class OSS_PUBLIC __seqof58 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq74 component;

    __seqof58();
    __seqof58(const __seqof58 &);
    ~__seqof58();

    __seqof58 & operator = (const __seqof58 &);
    int operator == (const __seqof58 &) const;
    int operator != (const __seqof58 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof58 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof58 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof58 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC S1SetupRequest   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __seqof58 protocolIEs;

    S1SetupRequest();
    S1SetupRequest(const S1SetupRequest &);
    S1SetupRequest(const protocolIEs &);

    S1SetupRequest & operator = (const S1SetupRequest &);
    int operator == (const S1SetupRequest &) const;
    int operator != (const S1SetupRequest &) const;

    protocolIEs & get_protocolIEs();
    const protocolIEs & get_protocolIEs() const;
    void set_protocolIEs(const protocolIEs &);
private:
    protocolIEs protocolIEs_field;
};

class OSS_PUBLIC __seq59;

class OSS_PUBLIC __seqof45 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq59 component;

    __seqof45();
    __seqof45(const __seqof45 &);
    ~__seqof45();

    __seqof45 & operator = (const __seqof45 &);
    int operator == (const __seqof45 &) const;
    int operator != (const __seqof45 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof45 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof45 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof45 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC UEContextModificationRequest   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __seqof45 protocolIEs;

    UEContextModificationRequest();
    UEContextModificationRequest(const UEContextModificationRequest &);
    UEContextModificationRequest(const protocolIEs &);

    UEContextModificationRequest & operator = (const UEContextModificationRequest &);
    int operator == (const UEContextModificationRequest &) const;
    int operator != (const UEContextModificationRequest &) const;

    protocolIEs & get_protocolIEs();
    const protocolIEs & get_protocolIEs() const;
    void set_protocolIEs(const protocolIEs &);
private:
    protocolIEs protocolIEs_field;
};

class OSS_PUBLIC __seq57;

class OSS_PUBLIC __seqof43 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq57 component;

    __seqof43();
    __seqof43(const __seqof43 &);
    ~__seqof43();

    __seqof43 & operator = (const __seqof43 &);
    int operator == (const __seqof43 &) const;
    int operator != (const __seqof43 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof43 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof43 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof43 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC UEContextReleaseCommand   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __seqof43 protocolIEs;

    UEContextReleaseCommand();
    UEContextReleaseCommand(const UEContextReleaseCommand &);
    UEContextReleaseCommand(const protocolIEs &);

    UEContextReleaseCommand & operator = (const UEContextReleaseCommand &);
    int operator == (const UEContextReleaseCommand &) const;
    int operator != (const UEContextReleaseCommand &) const;

    protocolIEs & get_protocolIEs();
    const protocolIEs & get_protocolIEs() const;
    void set_protocolIEs(const protocolIEs &);
private:
    protocolIEs protocolIEs_field;
};

class OSS_PUBLIC __seq77;

class OSS_PUBLIC __seqof61 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq77 component;

    __seqof61();
    __seqof61(const __seqof61 &);
    ~__seqof61();

    __seqof61 & operator = (const __seqof61 &);
    int operator == (const __seqof61 &) const;
    int operator != (const __seqof61 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof61 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof61 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof61 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC ENBConfigurationUpdate   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __seqof61 protocolIEs;

    ENBConfigurationUpdate();
    ENBConfigurationUpdate(const ENBConfigurationUpdate &);
    ENBConfigurationUpdate(const protocolIEs &);

    ENBConfigurationUpdate & operator = (const ENBConfigurationUpdate &);
    int operator == (const ENBConfigurationUpdate &) const;
    int operator != (const ENBConfigurationUpdate &) const;

    protocolIEs & get_protocolIEs();
    const protocolIEs & get_protocolIEs() const;
    void set_protocolIEs(const protocolIEs &);
private:
    protocolIEs protocolIEs_field;
};

class OSS_PUBLIC __seq80;

class OSS_PUBLIC __seqof64 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq80 component;

    __seqof64();
    __seqof64(const __seqof64 &);
    ~__seqof64();

    __seqof64 & operator = (const __seqof64 &);
    int operator == (const __seqof64 &) const;
    int operator != (const __seqof64 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof64 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof64 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof64 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC MMEConfigurationUpdate   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __seqof64 protocolIEs;

    MMEConfigurationUpdate();
    MMEConfigurationUpdate(const MMEConfigurationUpdate &);
    MMEConfigurationUpdate(const protocolIEs &);

    MMEConfigurationUpdate & operator = (const MMEConfigurationUpdate &);
    int operator == (const MMEConfigurationUpdate &) const;
    int operator != (const MMEConfigurationUpdate &) const;

    protocolIEs & get_protocolIEs();
    const protocolIEs & get_protocolIEs() const;
    void set_protocolIEs(const protocolIEs &);
private:
    protocolIEs protocolIEs_field;
};

class OSS_PUBLIC __seq97;

class OSS_PUBLIC __seqof81 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq97 component;

    __seqof81();
    __seqof81(const __seqof81 &);
    ~__seqof81();

    __seqof81 & operator = (const __seqof81 &);
    int operator == (const __seqof81 &) const;
    int operator != (const __seqof81 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof81 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof81 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof81 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC WriteReplaceWarningRequest   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __seqof81 protocolIEs;

    WriteReplaceWarningRequest();
    WriteReplaceWarningRequest(const WriteReplaceWarningRequest &);
    WriteReplaceWarningRequest(const protocolIEs &);

    WriteReplaceWarningRequest & operator = (const WriteReplaceWarningRequest &);
    int operator == (const WriteReplaceWarningRequest &) const;
    int operator != (const WriteReplaceWarningRequest &) const;

    protocolIEs & get_protocolIEs();
    const protocolIEs & get_protocolIEs() const;
    void set_protocolIEs(const protocolIEs &);
private:
    protocolIEs protocolIEs_field;
};

class OSS_PUBLIC __seq18;

class OSS_PUBLIC __seqof14 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq18 component;

    __seqof14();
    __seqof14(const __seqof14 &);
    ~__seqof14();

    __seqof14 & operator = (const __seqof14 &);
    int operator == (const __seqof14 &) const;
    int operator != (const __seqof14 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof14 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof14 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof14 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC HandoverNotify   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __seqof14 protocolIEs;

    HandoverNotify();
    HandoverNotify(const HandoverNotify &);
    HandoverNotify(const protocolIEs &);

    HandoverNotify & operator = (const HandoverNotify &);
    int operator == (const HandoverNotify &) const;
    int operator != (const HandoverNotify &) const;

    protocolIEs & get_protocolIEs();
    const protocolIEs & get_protocolIEs() const;
    void set_protocolIEs(const protocolIEs &);
private:
    protocolIEs protocolIEs_field;
};

class OSS_PUBLIC __seq44;

class OSS_PUBLIC __seqof33 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq44 component;

    __seqof33();
    __seqof33(const __seqof33 &);
    ~__seqof33();

    __seqof33 & operator = (const __seqof33 &);
    int operator == (const __seqof33 &) const;
    int operator != (const __seqof33 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof33 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof33 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof33 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC E_RABReleaseIndication   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __seqof33 protocolIEs;

    E_RABReleaseIndication();
    E_RABReleaseIndication(const E_RABReleaseIndication &);
    E_RABReleaseIndication(const protocolIEs &);

    E_RABReleaseIndication & operator = (const E_RABReleaseIndication &);
    int operator == (const E_RABReleaseIndication &) const;
    int operator != (const E_RABReleaseIndication &) const;

    protocolIEs & get_protocolIEs();
    const protocolIEs & get_protocolIEs() const;
    void set_protocolIEs(const protocolIEs &);
private:
    protocolIEs protocolIEs_field;
};

class OSS_PUBLIC __seq52;

class OSS_PUBLIC __seqof39 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq52 component;

    __seqof39();
    __seqof39(const __seqof39 &);
    ~__seqof39();

    __seqof39 & operator = (const __seqof39 &);
    int operator == (const __seqof39 &) const;
    int operator != (const __seqof39 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof39 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof39 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof39 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC Paging   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __seqof39 protocolIEs;

    Paging();
    Paging(const Paging &);
    Paging(const protocolIEs &);

    Paging & operator = (const Paging &);
    int operator == (const Paging &) const;
    int operator != (const Paging &) const;

    protocolIEs & get_protocolIEs();
    const protocolIEs & get_protocolIEs() const;
    void set_protocolIEs(const protocolIEs &);
private:
    protocolIEs protocolIEs_field;
};

class OSS_PUBLIC __seq64;

class OSS_PUBLIC __seqof50 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq64 component;

    __seqof50();
    __seqof50(const __seqof50 &);
    ~__seqof50();

    __seqof50 & operator = (const __seqof50 &);
    int operator == (const __seqof50 &) const;
    int operator != (const __seqof50 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof50 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof50 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof50 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC DownlinkNASTransport   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __seqof50 protocolIEs;

    DownlinkNASTransport();
    DownlinkNASTransport(const DownlinkNASTransport &);
    DownlinkNASTransport(const protocolIEs &);

    DownlinkNASTransport & operator = (const DownlinkNASTransport &);
    int operator == (const DownlinkNASTransport &) const;
    int operator != (const DownlinkNASTransport &) const;

    protocolIEs & get_protocolIEs();
    const protocolIEs & get_protocolIEs() const;
    void set_protocolIEs(const protocolIEs &);
private:
    protocolIEs protocolIEs_field;
};

class OSS_PUBLIC __seq65;

class OSS_PUBLIC __seqof51 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq65 component;

    __seqof51();
    __seqof51(const __seqof51 &);
    ~__seqof51();

    __seqof51 & operator = (const __seqof51 &);
    int operator == (const __seqof51 &) const;
    int operator != (const __seqof51 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof51 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof51 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof51 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC InitialUEMessage   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __seqof51 protocolIEs;

    InitialUEMessage();
    InitialUEMessage(const InitialUEMessage &);
    InitialUEMessage(const protocolIEs &);

    InitialUEMessage & operator = (const InitialUEMessage &);
    int operator == (const InitialUEMessage &) const;
    int operator != (const InitialUEMessage &) const;

    protocolIEs & get_protocolIEs();
    const protocolIEs & get_protocolIEs() const;
    void set_protocolIEs(const protocolIEs &);
private:
    protocolIEs protocolIEs_field;
};

class OSS_PUBLIC __seq66;

class OSS_PUBLIC __seqof52 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq66 component;

    __seqof52();
    __seqof52(const __seqof52 &);
    ~__seqof52();

    __seqof52 & operator = (const __seqof52 &);
    int operator == (const __seqof52 &) const;
    int operator != (const __seqof52 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof52 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof52 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof52 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC UplinkNASTransport   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __seqof52 protocolIEs;

    UplinkNASTransport();
    UplinkNASTransport(const UplinkNASTransport &);
    UplinkNASTransport(const protocolIEs &);

    UplinkNASTransport & operator = (const UplinkNASTransport &);
    int operator == (const UplinkNASTransport &) const;
    int operator != (const UplinkNASTransport &) const;

    protocolIEs & get_protocolIEs();
    const protocolIEs & get_protocolIEs() const;
    void set_protocolIEs(const protocolIEs &);
private:
    protocolIEs protocolIEs_field;
};

class OSS_PUBLIC __shared19;

class OSS_PUBLIC __shared20 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __shared19 component;

    __shared20();
    __shared20(const __shared20 &);
    ~__shared20();

    __shared20 & operator = (const __shared20 &);
    int operator == (const __shared20 &) const;
    int operator != (const __shared20 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__shared20 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __shared20 *);

    int remove_front();
    int remove_after(OssIndex);

    __shared20 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC __shared21   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __shared20 protocolIEs;

    __shared21();
    __shared21(const __shared21 &);
    __shared21(const protocolIEs &);

    __shared21 & operator = (const __shared21 &);
    int operator == (const __shared21 &) const;
    int operator != (const __shared21 &) const;

    protocolIEs & get_protocolIEs();
    const protocolIEs & get_protocolIEs() const;
    void set_protocolIEs(const protocolIEs &);
private:
    protocolIEs protocolIEs_field;
};

typedef __shared21 ErrorIndication;

class OSS_PUBLIC __seq67;

class OSS_PUBLIC __seqof53 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq67 component;

    __seqof53();
    __seqof53(const __seqof53 &);
    ~__seqof53();

    __seqof53 & operator = (const __seqof53 &);
    int operator == (const __seqof53 &) const;
    int operator != (const __seqof53 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof53 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof53 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof53 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC NASNonDeliveryIndication   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __seqof53 protocolIEs;

    NASNonDeliveryIndication();
    NASNonDeliveryIndication(const NASNonDeliveryIndication &);
    NASNonDeliveryIndication(const protocolIEs &);

    NASNonDeliveryIndication & operator = (const NASNonDeliveryIndication &);
    int operator == (const NASNonDeliveryIndication &) const;
    int operator != (const NASNonDeliveryIndication &) const;

    protocolIEs & get_protocolIEs();
    const protocolIEs & get_protocolIEs() const;
    void set_protocolIEs(const protocolIEs &);
private:
    protocolIEs protocolIEs_field;
};

class OSS_PUBLIC __seq56;

class OSS_PUBLIC __seqof42 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq56 component;

    __seqof42();
    __seqof42(const __seqof42 &);
    ~__seqof42();

    __seqof42 & operator = (const __seqof42 &);
    int operator == (const __seqof42 &) const;
    int operator != (const __seqof42 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof42 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof42 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof42 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC UEContextReleaseRequest   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __seqof42 protocolIEs;

    UEContextReleaseRequest();
    UEContextReleaseRequest(const UEContextReleaseRequest &);
    UEContextReleaseRequest(const protocolIEs &);

    UEContextReleaseRequest & operator = (const UEContextReleaseRequest &);
    int operator == (const UEContextReleaseRequest &) const;
    int operator != (const UEContextReleaseRequest &) const;

    protocolIEs & get_protocolIEs();
    const protocolIEs & get_protocolIEs() const;
    void set_protocolIEs(const protocolIEs &);
private:
    protocolIEs protocolIEs_field;
};

class OSS_PUBLIC __seq83;

class OSS_PUBLIC __seqof67 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq83 component;

    __seqof67();
    __seqof67(const __seqof67 &);
    ~__seqof67();

    __seqof67 & operator = (const __seqof67 &);
    int operator == (const __seqof67 &) const;
    int operator != (const __seqof67 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof67 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof67 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof67 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC DownlinkS1cdma2000tunnelling   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __seqof67 protocolIEs;

    DownlinkS1cdma2000tunnelling();
    DownlinkS1cdma2000tunnelling(const DownlinkS1cdma2000tunnelling &);
    DownlinkS1cdma2000tunnelling(const protocolIEs &);

    DownlinkS1cdma2000tunnelling & operator = (const DownlinkS1cdma2000tunnelling &);
    int operator == (const DownlinkS1cdma2000tunnelling &) const;
    int operator != (const DownlinkS1cdma2000tunnelling &) const;

    protocolIEs & get_protocolIEs();
    const protocolIEs & get_protocolIEs() const;
    void set_protocolIEs(const protocolIEs &);
private:
    protocolIEs protocolIEs_field;
};

class OSS_PUBLIC __seq84;

class OSS_PUBLIC __seqof68 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq84 component;

    __seqof68();
    __seqof68(const __seqof68 &);
    ~__seqof68();

    __seqof68 & operator = (const __seqof68 &);
    int operator == (const __seqof68 &) const;
    int operator != (const __seqof68 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof68 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof68 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof68 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC UplinkS1cdma2000tunnelling   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __seqof68 protocolIEs;

    UplinkS1cdma2000tunnelling();
    UplinkS1cdma2000tunnelling(const UplinkS1cdma2000tunnelling &);
    UplinkS1cdma2000tunnelling(const protocolIEs &);

    UplinkS1cdma2000tunnelling & operator = (const UplinkS1cdma2000tunnelling &);
    int operator == (const UplinkS1cdma2000tunnelling &) const;
    int operator != (const UplinkS1cdma2000tunnelling &) const;

    protocolIEs & get_protocolIEs();
    const protocolIEs & get_protocolIEs() const;
    void set_protocolIEs(const protocolIEs &);
private:
    protocolIEs protocolIEs_field;
};

class OSS_PUBLIC __seq85;

class OSS_PUBLIC __seqof69 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq85 component;

    __seqof69();
    __seqof69(const __seqof69 &);
    ~__seqof69();

    __seqof69 & operator = (const __seqof69 &);
    int operator == (const __seqof69 &) const;
    int operator != (const __seqof69 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof69 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof69 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof69 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC UECapabilityInfoIndication   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __seqof69 protocolIEs;

    UECapabilityInfoIndication();
    UECapabilityInfoIndication(const UECapabilityInfoIndication &);
    UECapabilityInfoIndication(const protocolIEs &);

    UECapabilityInfoIndication & operator = (const UECapabilityInfoIndication &);
    int operator == (const UECapabilityInfoIndication &) const;
    int operator != (const UECapabilityInfoIndication &) const;

    protocolIEs & get_protocolIEs();
    const protocolIEs & get_protocolIEs() const;
    void set_protocolIEs(const protocolIEs &);
private:
    protocolIEs protocolIEs_field;
};

class OSS_PUBLIC __shared22;

class OSS_PUBLIC __shared23 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __shared22 component;

    __shared23();
    __shared23(const __shared23 &);
    ~__shared23();

    __shared23 & operator = (const __shared23 &);
    int operator == (const __shared23 &) const;
    int operator != (const __shared23 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__shared23 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __shared23 *);

    int remove_front();
    int remove_after(OssIndex);

    __shared23 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC __shared24   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __shared23 protocolIEs;

    __shared24();
    __shared24(const __shared24 &);
    __shared24(const protocolIEs &);

    __shared24 & operator = (const __shared24 &);
    int operator == (const __shared24 &) const;
    int operator != (const __shared24 &) const;

    protocolIEs & get_protocolIEs();
    const protocolIEs & get_protocolIEs() const;
    void set_protocolIEs(const protocolIEs &);
private:
    protocolIEs protocolIEs_field;
};

typedef __shared24 ENBStatusTransfer;

typedef __shared24 MMEStatusTransfer;

class OSS_PUBLIC __seq90;

class OSS_PUBLIC __seqof74 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq90 component;

    __seqof74();
    __seqof74(const __seqof74 &);
    ~__seqof74();

    __seqof74 & operator = (const __seqof74 &);
    int operator == (const __seqof74 &) const;
    int operator != (const __seqof74 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof74 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof74 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof74 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC DeactivateTrace   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __seqof74 protocolIEs;

    DeactivateTrace();
    DeactivateTrace(const DeactivateTrace &);
    DeactivateTrace(const protocolIEs &);

    DeactivateTrace & operator = (const DeactivateTrace &);
    int operator == (const DeactivateTrace &) const;
    int operator != (const DeactivateTrace &) const;

    protocolIEs & get_protocolIEs();
    const protocolIEs & get_protocolIEs() const;
    void set_protocolIEs(const protocolIEs &);
private:
    protocolIEs protocolIEs_field;
};

class OSS_PUBLIC __seq88;

class OSS_PUBLIC __seqof72 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq88 component;

    __seqof72();
    __seqof72(const __seqof72 &);
    ~__seqof72();

    __seqof72 & operator = (const __seqof72 &);
    int operator == (const __seqof72 &) const;
    int operator != (const __seqof72 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof72 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof72 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof72 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC TraceStart   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __seqof72 protocolIEs;

    TraceStart();
    TraceStart(const TraceStart &);
    TraceStart(const protocolIEs &);

    TraceStart & operator = (const TraceStart &);
    int operator == (const TraceStart &) const;
    int operator != (const TraceStart &) const;

    protocolIEs & get_protocolIEs();
    const protocolIEs & get_protocolIEs() const;
    void set_protocolIEs(const protocolIEs &);
private:
    protocolIEs protocolIEs_field;
};

class OSS_PUBLIC __seq89;

class OSS_PUBLIC __seqof73 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq89 component;

    __seqof73();
    __seqof73(const __seqof73 &);
    ~__seqof73();

    __seqof73 & operator = (const __seqof73 &);
    int operator == (const __seqof73 &) const;
    int operator != (const __seqof73 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof73 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof73 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof73 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC TraceFailureIndication   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __seqof73 protocolIEs;

    TraceFailureIndication();
    TraceFailureIndication(const TraceFailureIndication &);
    TraceFailureIndication(const protocolIEs &);

    TraceFailureIndication & operator = (const TraceFailureIndication &);
    int operator == (const TraceFailureIndication &) const;
    int operator != (const TraceFailureIndication &) const;

    protocolIEs & get_protocolIEs();
    const protocolIEs & get_protocolIEs() const;
    void set_protocolIEs(const protocolIEs &);
private:
    protocolIEs protocolIEs_field;
};

class OSS_PUBLIC __seq91;

class OSS_PUBLIC __seqof75 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq91 component;

    __seqof75();
    __seqof75(const __seqof75 &);
    ~__seqof75();

    __seqof75 & operator = (const __seqof75 &);
    int operator == (const __seqof75 &) const;
    int operator != (const __seqof75 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof75 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof75 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof75 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC CellTrafficTrace   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __seqof75 protocolIEs;

    CellTrafficTrace();
    CellTrafficTrace(const CellTrafficTrace &);
    CellTrafficTrace(const protocolIEs &);

    CellTrafficTrace & operator = (const CellTrafficTrace &);
    int operator == (const CellTrafficTrace &) const;
    int operator != (const CellTrafficTrace &) const;

    protocolIEs & get_protocolIEs();
    const protocolIEs & get_protocolIEs() const;
    void set_protocolIEs(const protocolIEs &);
private:
    protocolIEs protocolIEs_field;
};

class OSS_PUBLIC __seq92;

class OSS_PUBLIC __seqof76 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq92 component;

    __seqof76();
    __seqof76(const __seqof76 &);
    ~__seqof76();

    __seqof76 & operator = (const __seqof76 &);
    int operator == (const __seqof76 &) const;
    int operator != (const __seqof76 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof76 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof76 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof76 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC LocationReportingControl   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __seqof76 protocolIEs;

    LocationReportingControl();
    LocationReportingControl(const LocationReportingControl &);
    LocationReportingControl(const protocolIEs &);

    LocationReportingControl & operator = (const LocationReportingControl &);
    int operator == (const LocationReportingControl &) const;
    int operator != (const LocationReportingControl &) const;

    protocolIEs & get_protocolIEs();
    const protocolIEs & get_protocolIEs() const;
    void set_protocolIEs(const protocolIEs &);
private:
    protocolIEs protocolIEs_field;
};

typedef __shared14 LocationReportingFailureIndication;

class OSS_PUBLIC __seq94;

class OSS_PUBLIC __seqof78 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq94 component;

    __seqof78();
    __seqof78(const __seqof78 &);
    ~__seqof78();

    __seqof78 & operator = (const __seqof78 &);
    int operator == (const __seqof78 &) const;
    int operator != (const __seqof78 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof78 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof78 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof78 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC LocationReport   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __seqof78 protocolIEs;

    LocationReport();
    LocationReport(const LocationReport &);
    LocationReport(const protocolIEs &);

    LocationReport & operator = (const LocationReport &);
    int operator == (const LocationReport &) const;
    int operator != (const LocationReport &) const;

    protocolIEs & get_protocolIEs();
    const protocolIEs & get_protocolIEs() const;
    void set_protocolIEs(const protocolIEs &);
private:
    protocolIEs protocolIEs_field;
};

class OSS_PUBLIC __seq95;

class OSS_PUBLIC __seqof79 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq95 component;

    __seqof79();
    __seqof79(const __seqof79 &);
    ~__seqof79();

    __seqof79 & operator = (const __seqof79 &);
    int operator == (const __seqof79 &) const;
    int operator != (const __seqof79 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof79 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof79 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof79 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC OverloadStart   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __seqof79 protocolIEs;

    OverloadStart();
    OverloadStart(const OverloadStart &);
    OverloadStart(const protocolIEs &);

    OverloadStart & operator = (const OverloadStart &);
    int operator == (const OverloadStart &) const;
    int operator != (const OverloadStart &) const;

    protocolIEs & get_protocolIEs();
    const protocolIEs & get_protocolIEs() const;
    void set_protocolIEs(const protocolIEs &);
private:
    protocolIEs protocolIEs_field;
};

class OSS_PUBLIC __seq96;

class OSS_PUBLIC __seqof80 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq96 component;

    __seqof80();
    __seqof80(const __seqof80 &);
    ~__seqof80();

    __seqof80 & operator = (const __seqof80 &);
    int operator == (const __seqof80 &) const;
    int operator != (const __seqof80 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof80 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof80 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof80 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC OverloadStop   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __seqof80 protocolIEs;

    OverloadStop();
    OverloadStop(const OverloadStop &);
    OverloadStop(const protocolIEs &);

    OverloadStop & operator = (const OverloadStop &);
    int operator == (const OverloadStop &) const;
    int operator != (const OverloadStop &) const;

    protocolIEs & get_protocolIEs();
    const protocolIEs & get_protocolIEs() const;
    void set_protocolIEs(const protocolIEs &);
private:
    protocolIEs protocolIEs_field;
};

class OSS_PUBLIC __shared25;

class OSS_PUBLIC __shared26 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __shared25 component;

    __shared26();
    __shared26(const __shared26 &);
    ~__shared26();

    __shared26 & operator = (const __shared26 &);
    int operator == (const __shared26 &) const;
    int operator != (const __shared26 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__shared26 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __shared26 *);

    int remove_front();
    int remove_after(OssIndex);

    __shared26 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC __shared27   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __shared26 protocolIEs;

    __shared27();
    __shared27(const __shared27 &);
    __shared27(const protocolIEs &);

    __shared27 & operator = (const __shared27 &);
    int operator == (const __shared27 &) const;
    int operator != (const __shared27 &) const;

    protocolIEs & get_protocolIEs();
    const protocolIEs & get_protocolIEs() const;
    void set_protocolIEs(const protocolIEs &);
private:
    protocolIEs protocolIEs_field;
};

typedef __shared27 ENBDirectInformationTransfer;

typedef __shared27 MMEDirectInformationTransfer;

class OSS_PUBLIC __shared29;

class OSS_PUBLIC __shared30 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __shared29 component;

    __shared30();
    __shared30(const __shared30 &);
    ~__shared30();

    __shared30 & operator = (const __shared30 &);
    int operator == (const __shared30 &) const;
    int operator != (const __shared30 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__shared30 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __shared30 *);

    int remove_front();
    int remove_after(OssIndex);

    __shared30 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC __shared31   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __shared30 protocolIEs;

    __shared31();
    __shared31(const __shared31 &);
    __shared31(const protocolIEs &);

    __shared31 & operator = (const __shared31 &);
    int operator == (const __shared31 &) const;
    int operator != (const __shared31 &) const;

    protocolIEs & get_protocolIEs();
    const protocolIEs & get_protocolIEs() const;
    void set_protocolIEs(const protocolIEs &);
private:
    protocolIEs protocolIEs_field;
};

typedef __shared31 ENBConfigurationTransfer;

typedef __shared31 MMEConfigurationTransfer;

class OSS_PUBLIC PrivateIE_Field;

class OSS_PUBLIC __seqof87 : public OssList  /* SEQUENCE OF */
{
public:
    typedef PrivateIE_Field component;

    __seqof87();
    __seqof87(const __seqof87 &);
    ~__seqof87();

    __seqof87 & operator = (const __seqof87 &);
    int operator == (const __seqof87 &) const;
    int operator != (const __seqof87 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof87 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof87 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof87 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC PrivateMessage   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __seqof87 privateIEs;

    PrivateMessage();
    PrivateMessage(const PrivateMessage &);
    PrivateMessage(const privateIEs &);

    PrivateMessage & operator = (const PrivateMessage &);
    int operator == (const PrivateMessage &) const;
    int operator != (const PrivateMessage &) const;

    privateIEs & get_privateIEs();
    const privateIEs & get_privateIEs() const;
    void set_privateIEs(const privateIEs &);
private:
    privateIEs privateIEs_field;
};

class OSS_PUBLIC S1AP_ELEMENTARY_PROCEDURES_InitiatingMessage : public OssConstrainedOpenType
{
public:
    S1AP_ELEMENTARY_PROCEDURES_InitiatingMessage();
    S1AP_ELEMENTARY_PROCEDURES_InitiatingMessage(const S1AP_ELEMENTARY_PROCEDURES_InitiatingMessage &);
    ~S1AP_ELEMENTARY_PROCEDURES_InitiatingMessage();
    S1AP_ELEMENTARY_PROCEDURES_InitiatingMessage & operator = (const S1AP_ELEMENTARY_PROCEDURES_InitiatingMessage &);
    int operator == (const S1AP_ELEMENTARY_PROCEDURES_InitiatingMessage &) const;
    int operator != (const S1AP_ELEMENTARY_PROCEDURES_InitiatingMessage &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    HandoverRequired *get_HandoverRequired();
    const HandoverRequired *get_HandoverRequired() const;
    void set_HandoverRequired(const HandoverRequired &);
    HandoverRequired *release_HandoverRequired();
    void set_HandoverRequired(HandoverRequired *);

    HandoverRequest *get_HandoverRequest();
    const HandoverRequest *get_HandoverRequest() const;
    void set_HandoverRequest(const HandoverRequest &);
    HandoverRequest *release_HandoverRequest();
    void set_HandoverRequest(HandoverRequest *);

    PathSwitchRequest *get_PathSwitchRequest();
    const PathSwitchRequest *get_PathSwitchRequest() const;
    void set_PathSwitchRequest(const PathSwitchRequest &);
    PathSwitchRequest *release_PathSwitchRequest();
    void set_PathSwitchRequest(PathSwitchRequest *);

    E_RABSetupRequest *get_E_RABSetupRequest();
    const E_RABSetupRequest *get_E_RABSetupRequest() const;
    void set_E_RABSetupRequest(const E_RABSetupRequest &);
    E_RABSetupRequest *release_E_RABSetupRequest();
    void set_E_RABSetupRequest(E_RABSetupRequest *);

    E_RABModifyRequest *get_E_RABModifyRequest();
    const E_RABModifyRequest *get_E_RABModifyRequest() const;
    void set_E_RABModifyRequest(const E_RABModifyRequest &);
    E_RABModifyRequest *release_E_RABModifyRequest();
    void set_E_RABModifyRequest(E_RABModifyRequest *);

    E_RABReleaseCommand *get_E_RABReleaseCommand();
    const E_RABReleaseCommand *get_E_RABReleaseCommand() const;
    void set_E_RABReleaseCommand(const E_RABReleaseCommand &);
    E_RABReleaseCommand *release_E_RABReleaseCommand();
    void set_E_RABReleaseCommand(E_RABReleaseCommand *);

    InitialContextSetupRequest *get_InitialContextSetupRequest();
    const InitialContextSetupRequest *get_InitialContextSetupRequest() const;
    void set_InitialContextSetupRequest(const InitialContextSetupRequest &);
    InitialContextSetupRequest *release_InitialContextSetupRequest();
    void set_InitialContextSetupRequest(InitialContextSetupRequest *);

    __shared14 *get_HandoverCancel();
    const __shared14 *get_HandoverCancel() const;
    void set_HandoverCancel(const __shared14 &);
    __shared14 *release_HandoverCancel();
    void set_HandoverCancel(__shared14 *);

    KillRequest *get_KillRequest();
    const KillRequest *get_KillRequest() const;
    void set_KillRequest(const KillRequest &);
    KillRequest *release_KillRequest();
    void set_KillRequest(KillRequest *);

    Reset *get_Reset();
    const Reset *get_Reset() const;
    void set_Reset(const Reset &);
    Reset *release_Reset();
    void set_Reset(Reset *);

    S1SetupRequest *get_S1SetupRequest();
    const S1SetupRequest *get_S1SetupRequest() const;
    void set_S1SetupRequest(const S1SetupRequest &);
    S1SetupRequest *release_S1SetupRequest();
    void set_S1SetupRequest(S1SetupRequest *);

    UEContextModificationRequest *get_UEContextModificationRequest();
    const UEContextModificationRequest *get_UEContextModificationRequest() const;
    void set_UEContextModificationRequest(const UEContextModificationRequest &);
    UEContextModificationRequest *release_UEContextModificationRequest();
    void set_UEContextModificationRequest(UEContextModificationRequest *);

    UEContextReleaseCommand *get_UEContextReleaseCommand();
    const UEContextReleaseCommand *get_UEContextReleaseCommand() const;
    void set_UEContextReleaseCommand(const UEContextReleaseCommand &);
    UEContextReleaseCommand *release_UEContextReleaseCommand();
    void set_UEContextReleaseCommand(UEContextReleaseCommand *);

    ENBConfigurationUpdate *get_ENBConfigurationUpdate();
    const ENBConfigurationUpdate *get_ENBConfigurationUpdate() const;
    void set_ENBConfigurationUpdate(const ENBConfigurationUpdate &);
    ENBConfigurationUpdate *release_ENBConfigurationUpdate();
    void set_ENBConfigurationUpdate(ENBConfigurationUpdate *);

    MMEConfigurationUpdate *get_MMEConfigurationUpdate();
    const MMEConfigurationUpdate *get_MMEConfigurationUpdate() const;
    void set_MMEConfigurationUpdate(const MMEConfigurationUpdate &);
    MMEConfigurationUpdate *release_MMEConfigurationUpdate();
    void set_MMEConfigurationUpdate(MMEConfigurationUpdate *);

    WriteReplaceWarningRequest *get_WriteReplaceWarningRequest();
    const WriteReplaceWarningRequest *get_WriteReplaceWarningRequest() const;
    void set_WriteReplaceWarningRequest(const WriteReplaceWarningRequest &);
    WriteReplaceWarningRequest *release_WriteReplaceWarningRequest();
    void set_WriteReplaceWarningRequest(WriteReplaceWarningRequest *);

    HandoverNotify *get_HandoverNotify();
    const HandoverNotify *get_HandoverNotify() const;
    void set_HandoverNotify(const HandoverNotify &);
    HandoverNotify *release_HandoverNotify();
    void set_HandoverNotify(HandoverNotify *);

    E_RABReleaseIndication *get_E_RABReleaseIndication();
    const E_RABReleaseIndication *get_E_RABReleaseIndication() const;
    void set_E_RABReleaseIndication(const E_RABReleaseIndication &);
    E_RABReleaseIndication *release_E_RABReleaseIndication();
    void set_E_RABReleaseIndication(E_RABReleaseIndication *);

    Paging *get_Paging();
    const Paging *get_Paging() const;
    void set_Paging(const Paging &);
    Paging *release_Paging();
    void set_Paging(Paging *);

    DownlinkNASTransport *get_DownlinkNASTransport();
    const DownlinkNASTransport *get_DownlinkNASTransport() const;
    void set_DownlinkNASTransport(const DownlinkNASTransport &);
    DownlinkNASTransport *release_DownlinkNASTransport();
    void set_DownlinkNASTransport(DownlinkNASTransport *);

    InitialUEMessage *get_InitialUEMessage();
    const InitialUEMessage *get_InitialUEMessage() const;
    void set_InitialUEMessage(const InitialUEMessage &);
    InitialUEMessage *release_InitialUEMessage();
    void set_InitialUEMessage(InitialUEMessage *);

    UplinkNASTransport *get_UplinkNASTransport();
    const UplinkNASTransport *get_UplinkNASTransport() const;
    void set_UplinkNASTransport(const UplinkNASTransport &);
    UplinkNASTransport *release_UplinkNASTransport();
    void set_UplinkNASTransport(UplinkNASTransport *);

    __shared21 *get_ErrorIndication();
    const __shared21 *get_ErrorIndication() const;
    void set_ErrorIndication(const __shared21 &);
    __shared21 *release_ErrorIndication();
    void set_ErrorIndication(__shared21 *);

    NASNonDeliveryIndication *get_NASNonDeliveryIndication();
    const NASNonDeliveryIndication *get_NASNonDeliveryIndication() const;
    void set_NASNonDeliveryIndication(const NASNonDeliveryIndication &);
    NASNonDeliveryIndication *release_NASNonDeliveryIndication();
    void set_NASNonDeliveryIndication(NASNonDeliveryIndication *);

    UEContextReleaseRequest *get_UEContextReleaseRequest();
    const UEContextReleaseRequest *get_UEContextReleaseRequest() const;
    void set_UEContextReleaseRequest(const UEContextReleaseRequest &);
    UEContextReleaseRequest *release_UEContextReleaseRequest();
    void set_UEContextReleaseRequest(UEContextReleaseRequest *);

    DownlinkS1cdma2000tunnelling *get_DownlinkS1cdma2000tunnelling();
    const DownlinkS1cdma2000tunnelling *get_DownlinkS1cdma2000tunnelling() const;
    void set_DownlinkS1cdma2000tunnelling(const DownlinkS1cdma2000tunnelling &);
    DownlinkS1cdma2000tunnelling *release_DownlinkS1cdma2000tunnelling();
    void set_DownlinkS1cdma2000tunnelling(DownlinkS1cdma2000tunnelling *);

    UplinkS1cdma2000tunnelling *get_UplinkS1cdma2000tunnelling();
    const UplinkS1cdma2000tunnelling *get_UplinkS1cdma2000tunnelling() const;
    void set_UplinkS1cdma2000tunnelling(const UplinkS1cdma2000tunnelling &);
    UplinkS1cdma2000tunnelling *release_UplinkS1cdma2000tunnelling();
    void set_UplinkS1cdma2000tunnelling(UplinkS1cdma2000tunnelling *);

    UECapabilityInfoIndication *get_UECapabilityInfoIndication();
    const UECapabilityInfoIndication *get_UECapabilityInfoIndication() const;
    void set_UECapabilityInfoIndication(const UECapabilityInfoIndication &);
    UECapabilityInfoIndication *release_UECapabilityInfoIndication();
    void set_UECapabilityInfoIndication(UECapabilityInfoIndication *);

    __shared24 *get_ENBStatusTransfer();
    const __shared24 *get_ENBStatusTransfer() const;
    void set_ENBStatusTransfer(const __shared24 &);
    __shared24 *release_ENBStatusTransfer();
    void set_ENBStatusTransfer(__shared24 *);

    __shared24 *get_MMEStatusTransfer();
    const __shared24 *get_MMEStatusTransfer() const;
    void set_MMEStatusTransfer(const __shared24 &);
    __shared24 *release_MMEStatusTransfer();
    void set_MMEStatusTransfer(__shared24 *);

    DeactivateTrace *get_DeactivateTrace();
    const DeactivateTrace *get_DeactivateTrace() const;
    void set_DeactivateTrace(const DeactivateTrace &);
    DeactivateTrace *release_DeactivateTrace();
    void set_DeactivateTrace(DeactivateTrace *);

    TraceStart *get_TraceStart();
    const TraceStart *get_TraceStart() const;
    void set_TraceStart(const TraceStart &);
    TraceStart *release_TraceStart();
    void set_TraceStart(TraceStart *);

    TraceFailureIndication *get_TraceFailureIndication();
    const TraceFailureIndication *get_TraceFailureIndication() const;
    void set_TraceFailureIndication(const TraceFailureIndication &);
    TraceFailureIndication *release_TraceFailureIndication();
    void set_TraceFailureIndication(TraceFailureIndication *);

    CellTrafficTrace *get_CellTrafficTrace();
    const CellTrafficTrace *get_CellTrafficTrace() const;
    void set_CellTrafficTrace(const CellTrafficTrace &);
    CellTrafficTrace *release_CellTrafficTrace();
    void set_CellTrafficTrace(CellTrafficTrace *);

    LocationReportingControl *get_LocationReportingControl();
    const LocationReportingControl *get_LocationReportingControl() const;
    void set_LocationReportingControl(const LocationReportingControl &);
    LocationReportingControl *release_LocationReportingControl();
    void set_LocationReportingControl(LocationReportingControl *);

    __shared14 *get_LocationReportingFailureIndication();
    const __shared14 *get_LocationReportingFailureIndication() const;
    void set_LocationReportingFailureIndication(const __shared14 &);
    __shared14 *release_LocationReportingFailureIndication();
    void set_LocationReportingFailureIndication(__shared14 *);

    LocationReport *get_LocationReport();
    const LocationReport *get_LocationReport() const;
    void set_LocationReport(const LocationReport &);
    LocationReport *release_LocationReport();
    void set_LocationReport(LocationReport *);

    OverloadStart *get_OverloadStart();
    const OverloadStart *get_OverloadStart() const;
    void set_OverloadStart(const OverloadStart &);
    OverloadStart *release_OverloadStart();
    void set_OverloadStart(OverloadStart *);

    OverloadStop *get_OverloadStop();
    const OverloadStop *get_OverloadStop() const;
    void set_OverloadStop(const OverloadStop &);
    OverloadStop *release_OverloadStop();
    void set_OverloadStop(OverloadStop *);

    __shared27 *get_ENBDirectInformationTransfer();
    const __shared27 *get_ENBDirectInformationTransfer() const;
    void set_ENBDirectInformationTransfer(const __shared27 &);
    __shared27 *release_ENBDirectInformationTransfer();
    void set_ENBDirectInformationTransfer(__shared27 *);

    __shared27 *get_MMEDirectInformationTransfer();
    const __shared27 *get_MMEDirectInformationTransfer() const;
    void set_MMEDirectInformationTransfer(const __shared27 &);
    __shared27 *release_MMEDirectInformationTransfer();
    void set_MMEDirectInformationTransfer(__shared27 *);

    __shared31 *get_ENBConfigurationTransfer();
    const __shared31 *get_ENBConfigurationTransfer() const;
    void set_ENBConfigurationTransfer(const __shared31 &);
    __shared31 *release_ENBConfigurationTransfer();
    void set_ENBConfigurationTransfer(__shared31 *);

    __shared31 *get_MMEConfigurationTransfer();
    const __shared31 *get_MMEConfigurationTransfer() const;
    void set_MMEConfigurationTransfer(const __shared31 &);
    __shared31 *release_MMEConfigurationTransfer();
    void set_MMEConfigurationTransfer(__shared31 *);

    PrivateMessage *get_PrivateMessage();
    const PrivateMessage *get_PrivateMessage() const;
    void set_PrivateMessage(const PrivateMessage &);
    PrivateMessage *release_PrivateMessage();
    void set_PrivateMessage(PrivateMessage *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC InitiatingMessage   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 procedureCode;
    typedef enum Criticality criticality;
    typedef S1AP_ELEMENTARY_PROCEDURES_InitiatingMessage value;

    InitiatingMessage();
    InitiatingMessage(const InitiatingMessage &);
    InitiatingMessage(procedureCode, criticality, const value &);

    InitiatingMessage & operator = (const InitiatingMessage &);
    int operator == (const InitiatingMessage &) const;
    int operator != (const InitiatingMessage &) const;

    procedureCode & get_procedureCode();
    procedureCode get_procedureCode() const;
    void set_procedureCode(procedureCode);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    procedureCode procedureCode_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC __seq2;

class OSS_PUBLIC __seqof2 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq2 component;

    __seqof2();
    __seqof2(const __seqof2 &);
    ~__seqof2();

    __seqof2 & operator = (const __seqof2 &);
    int operator == (const __seqof2 &) const;
    int operator != (const __seqof2 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof2 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof2 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof2 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC HandoverCommand   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __seqof2 protocolIEs;

    HandoverCommand();
    HandoverCommand(const HandoverCommand &);
    HandoverCommand(const protocolIEs &);

    HandoverCommand & operator = (const HandoverCommand &);
    int operator == (const HandoverCommand &) const;
    int operator != (const HandoverCommand &) const;

    protocolIEs & get_protocolIEs();
    const protocolIEs & get_protocolIEs() const;
    void set_protocolIEs(const protocolIEs &);
private:
    protocolIEs protocolIEs_field;
};

class OSS_PUBLIC __seq12;

class OSS_PUBLIC __seqof10 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq12 component;

    __seqof10();
    __seqof10(const __seqof10 &);
    ~__seqof10();

    __seqof10 & operator = (const __seqof10 &);
    int operator == (const __seqof10 &) const;
    int operator != (const __seqof10 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof10 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof10 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof10 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC HandoverRequestAcknowledge   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __seqof10 protocolIEs;

    HandoverRequestAcknowledge();
    HandoverRequestAcknowledge(const HandoverRequestAcknowledge &);
    HandoverRequestAcknowledge(const protocolIEs &);

    HandoverRequestAcknowledge & operator = (const HandoverRequestAcknowledge &);
    int operator == (const HandoverRequestAcknowledge &) const;
    int operator != (const HandoverRequestAcknowledge &) const;

    protocolIEs & get_protocolIEs();
    const protocolIEs & get_protocolIEs() const;
    void set_protocolIEs(const protocolIEs &);
private:
    protocolIEs protocolIEs_field;
};

class OSS_PUBLIC __seq22;

class OSS_PUBLIC __seqof17 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq22 component;

    __seqof17();
    __seqof17(const __seqof17 &);
    ~__seqof17();

    __seqof17 & operator = (const __seqof17 &);
    int operator == (const __seqof17 &) const;
    int operator != (const __seqof17 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof17 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof17 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof17 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC PathSwitchRequestAcknowledge   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __seqof17 protocolIEs;

    PathSwitchRequestAcknowledge();
    PathSwitchRequestAcknowledge(const PathSwitchRequestAcknowledge &);
    PathSwitchRequestAcknowledge(const protocolIEs &);

    PathSwitchRequestAcknowledge & operator = (const PathSwitchRequestAcknowledge &);
    int operator == (const PathSwitchRequestAcknowledge &) const;
    int operator != (const PathSwitchRequestAcknowledge &) const;

    protocolIEs & get_protocolIEs();
    const protocolIEs & get_protocolIEs() const;
    void set_protocolIEs(const protocolIEs &);
private:
    protocolIEs protocolIEs_field;
};

class OSS_PUBLIC __seq31;

class OSS_PUBLIC __seqof24 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq31 component;

    __seqof24();
    __seqof24(const __seqof24 &);
    ~__seqof24();

    __seqof24 & operator = (const __seqof24 &);
    int operator == (const __seqof24 &) const;
    int operator != (const __seqof24 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof24 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof24 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof24 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC E_RABSetupResponse   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __seqof24 protocolIEs;

    E_RABSetupResponse();
    E_RABSetupResponse(const E_RABSetupResponse &);
    E_RABSetupResponse(const protocolIEs &);

    E_RABSetupResponse & operator = (const E_RABSetupResponse &);
    int operator == (const E_RABSetupResponse &) const;
    int operator != (const E_RABSetupResponse &) const;

    protocolIEs & get_protocolIEs();
    const protocolIEs & get_protocolIEs() const;
    void set_protocolIEs(const protocolIEs &);
private:
    protocolIEs protocolIEs_field;
};

class OSS_PUBLIC __seq37;

class OSS_PUBLIC __seqof28 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq37 component;

    __seqof28();
    __seqof28(const __seqof28 &);
    ~__seqof28();

    __seqof28 & operator = (const __seqof28 &);
    int operator == (const __seqof28 &) const;
    int operator != (const __seqof28 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof28 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof28 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof28 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC E_RABModifyResponse   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __seqof28 protocolIEs;

    E_RABModifyResponse();
    E_RABModifyResponse(const E_RABModifyResponse &);
    E_RABModifyResponse(const protocolIEs &);

    E_RABModifyResponse & operator = (const E_RABModifyResponse &);
    int operator == (const E_RABModifyResponse &) const;
    int operator != (const E_RABModifyResponse &) const;

    protocolIEs & get_protocolIEs();
    const protocolIEs & get_protocolIEs() const;
    void set_protocolIEs(const protocolIEs &);
private:
    protocolIEs protocolIEs_field;
};

class OSS_PUBLIC __seq41;

class OSS_PUBLIC __seqof31 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq41 component;

    __seqof31();
    __seqof31(const __seqof31 &);
    ~__seqof31();

    __seqof31 & operator = (const __seqof31 &);
    int operator == (const __seqof31 &) const;
    int operator != (const __seqof31 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof31 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof31 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof31 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC E_RABReleaseResponse   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __seqof31 protocolIEs;

    E_RABReleaseResponse();
    E_RABReleaseResponse(const E_RABReleaseResponse &);
    E_RABReleaseResponse(const protocolIEs &);

    E_RABReleaseResponse & operator = (const E_RABReleaseResponse &);
    int operator == (const E_RABReleaseResponse &) const;
    int operator != (const E_RABReleaseResponse &) const;

    protocolIEs & get_protocolIEs();
    const protocolIEs & get_protocolIEs() const;
    void set_protocolIEs(const protocolIEs &);
private:
    protocolIEs protocolIEs_field;
};

class OSS_PUBLIC __seq48;

class OSS_PUBLIC __seqof36 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq48 component;

    __seqof36();
    __seqof36(const __seqof36 &);
    ~__seqof36();

    __seqof36 & operator = (const __seqof36 &);
    int operator == (const __seqof36 &) const;
    int operator != (const __seqof36 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof36 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof36 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof36 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC InitialContextSetupResponse   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __seqof36 protocolIEs;

    InitialContextSetupResponse();
    InitialContextSetupResponse(const InitialContextSetupResponse &);
    InitialContextSetupResponse(const protocolIEs &);

    InitialContextSetupResponse & operator = (const InitialContextSetupResponse &);
    int operator == (const InitialContextSetupResponse &) const;
    int operator != (const InitialContextSetupResponse &) const;

    protocolIEs & get_protocolIEs();
    const protocolIEs & get_protocolIEs() const;
    void set_protocolIEs(const protocolIEs &);
private:
    protocolIEs protocolIEs_field;
};

class OSS_PUBLIC __shared33;

class OSS_PUBLIC __shared34 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __shared33 component;

    __shared34();
    __shared34(const __shared34 &);
    ~__shared34();

    __shared34 & operator = (const __shared34 &);
    int operator == (const __shared34 &) const;
    int operator != (const __shared34 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__shared34 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __shared34 *);

    int remove_front();
    int remove_after(OssIndex);

    __shared34 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC __shared35   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __shared34 protocolIEs;

    __shared35();
    __shared35(const __shared35 &);
    __shared35(const protocolIEs &);

    __shared35 & operator = (const __shared35 &);
    int operator == (const __shared35 &) const;
    int operator != (const __shared35 &) const;

    protocolIEs & get_protocolIEs();
    const protocolIEs & get_protocolIEs() const;
    void set_protocolIEs(const protocolIEs &);
private:
    protocolIEs protocolIEs_field;
};

typedef __shared35 HandoverCancelAcknowledge;

class OSS_PUBLIC __seq104;

class OSS_PUBLIC __seqof89 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq104 component;

    __seqof89();
    __seqof89(const __seqof89 &);
    ~__seqof89();

    __seqof89 & operator = (const __seqof89 &);
    int operator == (const __seqof89 &) const;
    int operator != (const __seqof89 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof89 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof89 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof89 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC KillResponse   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __seqof89 protocolIEs;

    KillResponse();
    KillResponse(const KillResponse &);
    KillResponse(const protocolIEs &);

    KillResponse & operator = (const KillResponse &);
    int operator == (const KillResponse &) const;
    int operator != (const KillResponse &) const;

    protocolIEs & get_protocolIEs();
    const protocolIEs & get_protocolIEs() const;
    void set_protocolIEs(const protocolIEs &);
private:
    protocolIEs protocolIEs_field;
};

class OSS_PUBLIC __seq71;

class OSS_PUBLIC __seqof56 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq71 component;

    __seqof56();
    __seqof56(const __seqof56 &);
    ~__seqof56();

    __seqof56 & operator = (const __seqof56 &);
    int operator == (const __seqof56 &) const;
    int operator != (const __seqof56 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof56 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof56 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof56 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC ResetAcknowledge   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __seqof56 protocolIEs;

    ResetAcknowledge();
    ResetAcknowledge(const ResetAcknowledge &);
    ResetAcknowledge(const protocolIEs &);

    ResetAcknowledge & operator = (const ResetAcknowledge &);
    int operator == (const ResetAcknowledge &) const;
    int operator != (const ResetAcknowledge &) const;

    protocolIEs & get_protocolIEs();
    const protocolIEs & get_protocolIEs() const;
    void set_protocolIEs(const protocolIEs &);
private:
    protocolIEs protocolIEs_field;
};

class OSS_PUBLIC __seq75;

class OSS_PUBLIC __seqof59 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq75 component;

    __seqof59();
    __seqof59(const __seqof59 &);
    ~__seqof59();

    __seqof59 & operator = (const __seqof59 &);
    int operator == (const __seqof59 &) const;
    int operator != (const __seqof59 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof59 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof59 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof59 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC S1SetupResponse   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __seqof59 protocolIEs;

    S1SetupResponse();
    S1SetupResponse(const S1SetupResponse &);
    S1SetupResponse(const protocolIEs &);

    S1SetupResponse & operator = (const S1SetupResponse &);
    int operator == (const S1SetupResponse &) const;
    int operator != (const S1SetupResponse &) const;

    protocolIEs & get_protocolIEs();
    const protocolIEs & get_protocolIEs() const;
    void set_protocolIEs(const protocolIEs &);
private:
    protocolIEs protocolIEs_field;
};

typedef __shared35 UEContextModificationResponse;

class OSS_PUBLIC __seq58;

class OSS_PUBLIC __seqof44 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq58 component;

    __seqof44();
    __seqof44(const __seqof44 &);
    ~__seqof44();

    __seqof44 & operator = (const __seqof44 &);
    int operator == (const __seqof44 &) const;
    int operator != (const __seqof44 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof44 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof44 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof44 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC UEContextReleaseComplete   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __seqof44 protocolIEs;

    UEContextReleaseComplete();
    UEContextReleaseComplete(const UEContextReleaseComplete &);
    UEContextReleaseComplete(const protocolIEs &);

    UEContextReleaseComplete & operator = (const UEContextReleaseComplete &);
    int operator == (const UEContextReleaseComplete &) const;
    int operator != (const UEContextReleaseComplete &) const;

    protocolIEs & get_protocolIEs();
    const protocolIEs & get_protocolIEs() const;
    void set_protocolIEs(const protocolIEs &);
private:
    protocolIEs protocolIEs_field;
};

class OSS_PUBLIC __shared41;

class OSS_PUBLIC __shared42 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __shared41 component;

    __shared42();
    __shared42(const __shared42 &);
    ~__shared42();

    __shared42 & operator = (const __shared42 &);
    int operator == (const __shared42 &) const;
    int operator != (const __shared42 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__shared42 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __shared42 *);

    int remove_front();
    int remove_after(OssIndex);

    __shared42 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC __shared43   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __shared42 protocolIEs;

    __shared43();
    __shared43(const __shared43 &);
    __shared43(const protocolIEs &);

    __shared43 & operator = (const __shared43 &);
    int operator == (const __shared43 &) const;
    int operator != (const __shared43 &) const;

    protocolIEs & get_protocolIEs();
    const protocolIEs & get_protocolIEs() const;
    void set_protocolIEs(const protocolIEs &);
private:
    protocolIEs protocolIEs_field;
};

typedef __shared43 ENBConfigurationUpdateAcknowledge;

typedef __shared43 MMEConfigurationUpdateAcknowledge;

class OSS_PUBLIC __seq98;

class OSS_PUBLIC __seqof82 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq98 component;

    __seqof82();
    __seqof82(const __seqof82 &);
    ~__seqof82();

    __seqof82 & operator = (const __seqof82 &);
    int operator == (const __seqof82 &) const;
    int operator != (const __seqof82 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof82 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof82 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof82 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC WriteReplaceWarningResponse   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __seqof82 protocolIEs;

    WriteReplaceWarningResponse();
    WriteReplaceWarningResponse(const WriteReplaceWarningResponse &);
    WriteReplaceWarningResponse(const protocolIEs &);

    WriteReplaceWarningResponse & operator = (const WriteReplaceWarningResponse &);
    int operator == (const WriteReplaceWarningResponse &) const;
    int operator != (const WriteReplaceWarningResponse &) const;

    protocolIEs & get_protocolIEs();
    const protocolIEs & get_protocolIEs() const;
    void set_protocolIEs(const protocolIEs &);
private:
    protocolIEs protocolIEs_field;
};

class OSS_PUBLIC S1AP_ELEMENTARY_PROCEDURES_SuccessfulOutcome : public OssConstrainedOpenType
{
public:
    S1AP_ELEMENTARY_PROCEDURES_SuccessfulOutcome();
    S1AP_ELEMENTARY_PROCEDURES_SuccessfulOutcome(const S1AP_ELEMENTARY_PROCEDURES_SuccessfulOutcome &);
    ~S1AP_ELEMENTARY_PROCEDURES_SuccessfulOutcome();
    S1AP_ELEMENTARY_PROCEDURES_SuccessfulOutcome & operator = (const S1AP_ELEMENTARY_PROCEDURES_SuccessfulOutcome &);
    int operator == (const S1AP_ELEMENTARY_PROCEDURES_SuccessfulOutcome &) const;
    int operator != (const S1AP_ELEMENTARY_PROCEDURES_SuccessfulOutcome &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    HandoverCommand *get_HandoverCommand();
    const HandoverCommand *get_HandoverCommand() const;
    void set_HandoverCommand(const HandoverCommand &);
    HandoverCommand *release_HandoverCommand();
    void set_HandoverCommand(HandoverCommand *);

    HandoverRequestAcknowledge *get_HandoverRequestAcknowledge();
    const HandoverRequestAcknowledge *get_HandoverRequestAcknowledge() const;
    void set_HandoverRequestAcknowledge(const HandoverRequestAcknowledge &);
    HandoverRequestAcknowledge *release_HandoverRequestAcknowledge();
    void set_HandoverRequestAcknowledge(HandoverRequestAcknowledge *);

    PathSwitchRequestAcknowledge *get_PathSwitchRequestAcknowledge();
    const PathSwitchRequestAcknowledge *get_PathSwitchRequestAcknowledge() const;
    void set_PathSwitchRequestAcknowledge(const PathSwitchRequestAcknowledge &);
    PathSwitchRequestAcknowledge *release_PathSwitchRequestAcknowledge();
    void set_PathSwitchRequestAcknowledge(PathSwitchRequestAcknowledge *);

    E_RABSetupResponse *get_E_RABSetupResponse();
    const E_RABSetupResponse *get_E_RABSetupResponse() const;
    void set_E_RABSetupResponse(const E_RABSetupResponse &);
    E_RABSetupResponse *release_E_RABSetupResponse();
    void set_E_RABSetupResponse(E_RABSetupResponse *);

    E_RABModifyResponse *get_E_RABModifyResponse();
    const E_RABModifyResponse *get_E_RABModifyResponse() const;
    void set_E_RABModifyResponse(const E_RABModifyResponse &);
    E_RABModifyResponse *release_E_RABModifyResponse();
    void set_E_RABModifyResponse(E_RABModifyResponse *);

    E_RABReleaseResponse *get_E_RABReleaseResponse();
    const E_RABReleaseResponse *get_E_RABReleaseResponse() const;
    void set_E_RABReleaseResponse(const E_RABReleaseResponse &);
    E_RABReleaseResponse *release_E_RABReleaseResponse();
    void set_E_RABReleaseResponse(E_RABReleaseResponse *);

    InitialContextSetupResponse *get_InitialContextSetupResponse();
    const InitialContextSetupResponse *get_InitialContextSetupResponse() const;
    void set_InitialContextSetupResponse(const InitialContextSetupResponse &);
    InitialContextSetupResponse *release_InitialContextSetupResponse();
    void set_InitialContextSetupResponse(InitialContextSetupResponse *);

    __shared35 *get_HandoverCancelAcknowledge();
    const __shared35 *get_HandoverCancelAcknowledge() const;
    void set_HandoverCancelAcknowledge(const __shared35 &);
    __shared35 *release_HandoverCancelAcknowledge();
    void set_HandoverCancelAcknowledge(__shared35 *);

    KillResponse *get_KillResponse();
    const KillResponse *get_KillResponse() const;
    void set_KillResponse(const KillResponse &);
    KillResponse *release_KillResponse();
    void set_KillResponse(KillResponse *);

    ResetAcknowledge *get_ResetAcknowledge();
    const ResetAcknowledge *get_ResetAcknowledge() const;
    void set_ResetAcknowledge(const ResetAcknowledge &);
    ResetAcknowledge *release_ResetAcknowledge();
    void set_ResetAcknowledge(ResetAcknowledge *);

    S1SetupResponse *get_S1SetupResponse();
    const S1SetupResponse *get_S1SetupResponse() const;
    void set_S1SetupResponse(const S1SetupResponse &);
    S1SetupResponse *release_S1SetupResponse();
    void set_S1SetupResponse(S1SetupResponse *);

    __shared35 *get_UEContextModificationResponse();
    const __shared35 *get_UEContextModificationResponse() const;
    void set_UEContextModificationResponse(const __shared35 &);
    __shared35 *release_UEContextModificationResponse();
    void set_UEContextModificationResponse(__shared35 *);

    UEContextReleaseComplete *get_UEContextReleaseComplete();
    const UEContextReleaseComplete *get_UEContextReleaseComplete() const;
    void set_UEContextReleaseComplete(const UEContextReleaseComplete &);
    UEContextReleaseComplete *release_UEContextReleaseComplete();
    void set_UEContextReleaseComplete(UEContextReleaseComplete *);

    __shared43 *get_ENBConfigurationUpdateAcknowledge();
    const __shared43 *get_ENBConfigurationUpdateAcknowledge() const;
    void set_ENBConfigurationUpdateAcknowledge(const __shared43 &);
    __shared43 *release_ENBConfigurationUpdateAcknowledge();
    void set_ENBConfigurationUpdateAcknowledge(__shared43 *);

    __shared43 *get_MMEConfigurationUpdateAcknowledge();
    const __shared43 *get_MMEConfigurationUpdateAcknowledge() const;
    void set_MMEConfigurationUpdateAcknowledge(const __shared43 &);
    __shared43 *release_MMEConfigurationUpdateAcknowledge();
    void set_MMEConfigurationUpdateAcknowledge(__shared43 *);

    WriteReplaceWarningResponse *get_WriteReplaceWarningResponse();
    const WriteReplaceWarningResponse *get_WriteReplaceWarningResponse() const;
    void set_WriteReplaceWarningResponse(const WriteReplaceWarningResponse &);
    WriteReplaceWarningResponse *release_WriteReplaceWarningResponse();
    void set_WriteReplaceWarningResponse(WriteReplaceWarningResponse *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC SuccessfulOutcome   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 procedureCode;
    typedef enum Criticality criticality;
    typedef S1AP_ELEMENTARY_PROCEDURES_SuccessfulOutcome value;

    SuccessfulOutcome();
    SuccessfulOutcome(const SuccessfulOutcome &);
    SuccessfulOutcome(procedureCode, criticality, const value &);

    SuccessfulOutcome & operator = (const SuccessfulOutcome &);
    int operator == (const SuccessfulOutcome &) const;
    int operator != (const SuccessfulOutcome &) const;

    procedureCode & get_procedureCode();
    procedureCode get_procedureCode() const;
    void set_procedureCode(procedureCode);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    procedureCode procedureCode_field;
    criticality criticality_field;
    value value_field;
};

typedef __shared21 HandoverPreparationFailure;

class OSS_PUBLIC __seq17;

class OSS_PUBLIC __seqof13 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq17 component;

    __seqof13();
    __seqof13(const __seqof13 &);
    ~__seqof13();

    __seqof13 & operator = (const __seqof13 &);
    int operator == (const __seqof13 &) const;
    int operator != (const __seqof13 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof13 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof13 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof13 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC HandoverFailure   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __seqof13 protocolIEs;

    HandoverFailure();
    HandoverFailure(const HandoverFailure &);
    HandoverFailure(const protocolIEs &);

    HandoverFailure & operator = (const HandoverFailure &);
    int operator == (const HandoverFailure &) const;
    int operator != (const HandoverFailure &) const;

    protocolIEs & get_protocolIEs();
    const protocolIEs & get_protocolIEs() const;
    void set_protocolIEs(const protocolIEs &);
private:
    protocolIEs protocolIEs_field;
};

typedef __shared21 PathSwitchRequestFailure;

typedef __shared21 InitialContextSetupFailure;

class OSS_PUBLIC __shared48;

class OSS_PUBLIC __shared49 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __shared48 component;

    __shared49();
    __shared49(const __shared49 &);
    ~__shared49();

    __shared49 & operator = (const __shared49 &);
    int operator == (const __shared49 &) const;
    int operator != (const __shared49 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__shared49 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __shared49 *);

    int remove_front();
    int remove_after(OssIndex);

    __shared49 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC __shared50   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __shared49 protocolIEs;

    __shared50();
    __shared50(const __shared50 &);
    __shared50(const protocolIEs &);

    __shared50 & operator = (const __shared50 &);
    int operator == (const __shared50 &) const;
    int operator != (const __shared50 &) const;

    protocolIEs & get_protocolIEs();
    const protocolIEs & get_protocolIEs() const;
    void set_protocolIEs(const protocolIEs &);
private:
    protocolIEs protocolIEs_field;
};

typedef __shared50 S1SetupFailure;

typedef __shared21 UEContextModificationFailure;

typedef __shared50 ENBConfigurationUpdateFailure;

typedef __shared50 MMEConfigurationUpdateFailure;

class OSS_PUBLIC S1AP_ELEMENTARY_PROCEDURES_UnsuccessfulOutcome : public OssConstrainedOpenType
{
public:
    S1AP_ELEMENTARY_PROCEDURES_UnsuccessfulOutcome();
    S1AP_ELEMENTARY_PROCEDURES_UnsuccessfulOutcome(const S1AP_ELEMENTARY_PROCEDURES_UnsuccessfulOutcome &);
    ~S1AP_ELEMENTARY_PROCEDURES_UnsuccessfulOutcome();
    S1AP_ELEMENTARY_PROCEDURES_UnsuccessfulOutcome & operator = (const S1AP_ELEMENTARY_PROCEDURES_UnsuccessfulOutcome &);
    int operator == (const S1AP_ELEMENTARY_PROCEDURES_UnsuccessfulOutcome &) const;
    int operator != (const S1AP_ELEMENTARY_PROCEDURES_UnsuccessfulOutcome &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    __shared21 *get_HandoverPreparationFailure();
    const __shared21 *get_HandoverPreparationFailure() const;
    void set_HandoverPreparationFailure(const __shared21 &);
    __shared21 *release_HandoverPreparationFailure();
    void set_HandoverPreparationFailure(__shared21 *);

    HandoverFailure *get_HandoverFailure();
    const HandoverFailure *get_HandoverFailure() const;
    void set_HandoverFailure(const HandoverFailure &);
    HandoverFailure *release_HandoverFailure();
    void set_HandoverFailure(HandoverFailure *);

    __shared21 *get_PathSwitchRequestFailure();
    const __shared21 *get_PathSwitchRequestFailure() const;
    void set_PathSwitchRequestFailure(const __shared21 &);
    __shared21 *release_PathSwitchRequestFailure();
    void set_PathSwitchRequestFailure(__shared21 *);

    __shared21 *get_InitialContextSetupFailure();
    const __shared21 *get_InitialContextSetupFailure() const;
    void set_InitialContextSetupFailure(const __shared21 &);
    __shared21 *release_InitialContextSetupFailure();
    void set_InitialContextSetupFailure(__shared21 *);

    __shared50 *get_S1SetupFailure();
    const __shared50 *get_S1SetupFailure() const;
    void set_S1SetupFailure(const __shared50 &);
    __shared50 *release_S1SetupFailure();
    void set_S1SetupFailure(__shared50 *);

    __shared21 *get_UEContextModificationFailure();
    const __shared21 *get_UEContextModificationFailure() const;
    void set_UEContextModificationFailure(const __shared21 &);
    __shared21 *release_UEContextModificationFailure();
    void set_UEContextModificationFailure(__shared21 *);

    __shared50 *get_ENBConfigurationUpdateFailure();
    const __shared50 *get_ENBConfigurationUpdateFailure() const;
    void set_ENBConfigurationUpdateFailure(const __shared50 &);
    __shared50 *release_ENBConfigurationUpdateFailure();
    void set_ENBConfigurationUpdateFailure(__shared50 *);

    __shared50 *get_MMEConfigurationUpdateFailure();
    const __shared50 *get_MMEConfigurationUpdateFailure() const;
    void set_MMEConfigurationUpdateFailure(const __shared50 &);
    __shared50 *release_MMEConfigurationUpdateFailure();
    void set_MMEConfigurationUpdateFailure(__shared50 *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC UnsuccessfulOutcome   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 procedureCode;
    typedef enum Criticality criticality;
    typedef S1AP_ELEMENTARY_PROCEDURES_UnsuccessfulOutcome value;

    UnsuccessfulOutcome();
    UnsuccessfulOutcome(const UnsuccessfulOutcome &);
    UnsuccessfulOutcome(procedureCode, criticality, const value &);

    UnsuccessfulOutcome & operator = (const UnsuccessfulOutcome &);
    int operator == (const UnsuccessfulOutcome &) const;
    int operator != (const UnsuccessfulOutcome &) const;

    procedureCode & get_procedureCode();
    procedureCode get_procedureCode() const;
    void set_procedureCode(procedureCode);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    procedureCode procedureCode_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC S1AP_PDU  : public OssChoice   /* CHOICE */
{
public:
    enum Id {
	unselected,
	initiatingMessage_chosen = 1,
	successfulOutcome_chosen = 2,
	unsuccessfulOutcome_chosen = 3
    };
    typedef InitiatingMessage initiatingMessage;
    typedef SuccessfulOutcome successfulOutcome;
    typedef UnsuccessfulOutcome unsuccessfulOutcome;

    S1AP_PDU();
    S1AP_PDU(const S1AP_PDU &);
    ~S1AP_PDU();

    S1AP_PDU & operator = (const S1AP_PDU &);
    int operator == (const S1AP_PDU &) const;
    int operator != (const S1AP_PDU &) const;

    initiatingMessage *get_initiatingMessage();
    const initiatingMessage *get_initiatingMessage() const;
    void set_initiatingMessage(const initiatingMessage &);

    successfulOutcome *get_successfulOutcome();
    const successfulOutcome *get_successfulOutcome() const;
    void set_successfulOutcome(const successfulOutcome &);

    unsuccessfulOutcome *get_unsuccessfulOutcome();
    const unsuccessfulOutcome *get_unsuccessfulOutcome() const;
    void set_unsuccessfulOutcome(const unsuccessfulOutcome &);
private:
    union {
	initiatingMessage *initiatingMessage_field;
	successfulOutcome *successfulOutcome_field;
	unsuccessfulOutcome *unsuccessfulOutcome_field;
    };
    void cleanup();
};

typedef OSS_UINT32 ENB_UE_S1AP_ID;

typedef OSS_UINT32 EUTRANRoundTripDelayEstimationInfo;

typedef OSS_UINT32 ExtendedRepetitionPeriod;

typedef OSS_UINT32 MME_UE_S1AP_ID;

typedef OSS_UINT32 NumberofBroadcastRequest;

typedef OSS_UINT32 RelativeMMECapacity;

typedef OSS_UINT32 RepetitionPeriod;

typedef OSS_UINT32 Routing_ID;

typedef OSS_UINT32 SubscriberProfileIDforRFP;

typedef OSS_UINT32 Time_UE_StayedInCell_EnhancedGranularity;

typedef OSS_UINT32 TrafficLoadReductionIndication;

typedef OSS_UINT32 UE_Usage_Type;

typedef OssString Cdma2000PDU;

typedef OssString Cdma2000SectorID;

typedef OssString Cdma2000OneXRAND;

typedef OssString Correlation_ID;

typedef OssBitString CSG_Id;

typedef OssBitString DataCodingScheme;

typedef OssString ENBname;

typedef OssBitString Extended_UEIdentityIndexValue;

typedef OssBitString Masked_IMEISV;

typedef OssString L3_Information;

typedef OssString LPPa_PDU;

typedef OssString LHN_ID;

typedef OssBitString MDT_Location_Info;

typedef OssBitString MessageIdentifier;

typedef OssBitString S1AP_IEs_MobilityInformation;

typedef OssString MMEname;

typedef OssString MME_Group_ID;

typedef OssString MSClassmark2;

typedef OssString MSClassmark3;

typedef OssString NAS_PDU;

typedef OssString NASSecurityParametersfromE_UTRAN;

typedef OssString NASSecurityParameterstoE_UTRAN;

typedef OssBitString NB_IoT_UEIdentityIndexValue;

typedef OssString OldBSS_ToNewBSS_Information;

typedef OssBitString ReceiveStatusOfULPDCPSDUsExtended;

typedef OssBitString ReceiveStatusOfULPDCPSDUsPDCP_SNlength18;

typedef OssBitString SecurityKey;

typedef OssBitString SerialNumber;

typedef OssString Source_ToTarget_TransparentContainer;

typedef OssString SourceBSS_ToTargetBSS_TransparentContainer;

typedef OssString SourceRNC_ToTargetRNC_TransparentContainer;

typedef OssString Target_ToSource_TransparentContainer;

typedef OssString TargetRNC_ToSourceRNC_TransparentContainer;

typedef OssString TargetBSS_ToSourceBSS_TransparentContainer;

typedef OssBitString TransportLayerAddress;

typedef OssString E_UTRAN_Trace_ID;

typedef OssBitString UEIdentityIndexValue;

typedef OssString UE_HistoryInformationFromTheUE;

typedef OssString UERadioCapability;

typedef OssString UERadioCapabilityForPaging;

typedef OssString WarningType;

typedef OssString WarningSecurityInfo;

typedef OssString WarningMessageContents;

typedef OssString RerouteNASRequest_IEs_TYPE;

typedef OSS_UINT32 ProtocolIE_ID;

class OSS_PUBLIC Cause  : public OssChoice   /* CHOICE */
{
public:
    enum Id {
	unselected,
	radioNetwork_chosen = 1,
	transport_chosen = 2,
	nas_chosen = 3,
	protocol_chosen = 4,
	misc_chosen = 5
    };
    typedef enum CauseRadioNetwork radioNetwork;
    typedef enum CauseTransport transport;
    typedef enum CauseNas nas;
    typedef enum CauseProtocol protocol;
    typedef enum CauseMisc misc;

    Cause();
    Cause(const Cause &);

    Cause & operator = (const Cause &);
    int operator == (const Cause &) const;
    int operator != (const Cause &) const;

    radioNetwork *get_radioNetwork();
    const radioNetwork *get_radioNetwork() const;
    void set_radioNetwork(radioNetwork);

    transport *get_transport();
    const transport *get_transport() const;
    void set_transport(transport);

    nas *get_nas();
    const nas *get_nas() const;
    void set_nas(nas);

    protocol *get_protocol();
    const protocol *get_protocol() const;
    void set_protocol(protocol);

    misc *get_misc();
    const misc *get_misc() const;
    void set_misc(misc);
private:
    union {
	radioNetwork radioNetwork_field;
	transport transport_field;
	nas nas_field;
	protocol protocol_field;
	misc misc_field;
    };
};

class OSS_PUBLIC ENB_ID  : public OssChoice   /* CHOICE */
{
public:
    enum Id {
	unselected,
	macroENB_ID_chosen = 1,
	homeENB_ID_chosen = 2
    };
    typedef OssBitString macroENB_ID;
    typedef OssBitString homeENB_ID;

    ENB_ID();
    ENB_ID(const ENB_ID &);
    ~ENB_ID();

    ENB_ID & operator = (const ENB_ID &);
    int operator == (const ENB_ID &) const;
    int operator != (const ENB_ID &) const;

    macroENB_ID *get_macroENB_ID();
    const macroENB_ID *get_macroENB_ID() const;
    void set_macroENB_ID(const macroENB_ID &);

    homeENB_ID *get_homeENB_ID();
    const homeENB_ID *get_homeENB_ID() const;
    void set_homeENB_ID(const homeENB_ID &);
private:
    union {
	OSSC::COssBitString macroENB_ID_field;
	OSSC::COssBitString homeENB_ID_field;
    };
    void cleanup();
};

class OSS_PUBLIC __shared1;

class OSS_PUBLIC __shared2 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __shared1 component;

    __shared2();
    __shared2(const __shared2 &);
    ~__shared2();

    __shared2 & operator = (const __shared2 &);
    int operator == (const __shared2 &) const;
    int operator != (const __shared2 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__shared2 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __shared2 *);

    int remove_front();
    int remove_after(OssIndex);

    __shared2 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC Global_ENB_ID   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OssString pLMNidentity;
    typedef ENB_ID eNB_ID;
    typedef __shared2 iE_Extensions;

    Global_ENB_ID();
    Global_ENB_ID(const Global_ENB_ID &);
    Global_ENB_ID(const pLMNidentity &, const eNB_ID &, const iE_Extensions &);
    Global_ENB_ID(const pLMNidentity &, const eNB_ID &);

    Global_ENB_ID & operator = (const Global_ENB_ID &);
    int operator == (const Global_ENB_ID &) const;
    int operator != (const Global_ENB_ID &) const;

    pLMNidentity & get_pLMNidentity();
    const pLMNidentity & get_pLMNidentity() const;
    void set_pLMNidentity(const pLMNidentity &);

    eNB_ID & get_eNB_ID();
    const eNB_ID & get_eNB_ID() const;
    void set_eNB_ID(const eNB_ID &);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    pLMNidentity pLMNidentity_field;
    eNB_ID eNB_ID_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC TAI   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OssString pLMNidentity;
    typedef OssString tAC;
    typedef __shared2 iE_Extensions;

    TAI();
    TAI(const TAI &);
    TAI(const pLMNidentity &, const tAC &, const iE_Extensions &);
    TAI(const pLMNidentity &, const tAC &);

    TAI & operator = (const TAI &);
    int operator == (const TAI &) const;
    int operator != (const TAI &) const;

    pLMNidentity & get_pLMNidentity();
    const pLMNidentity & get_pLMNidentity() const;
    void set_pLMNidentity(const pLMNidentity &);

    tAC & get_tAC();
    const tAC & get_tAC() const;
    void set_tAC(const tAC &);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    pLMNidentity pLMNidentity_field;
    tAC tAC_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC __shared3   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef Global_ENB_ID global_ENB_ID;
    typedef TAI selected_TAI;
    typedef __shared2 iE_Extensions;

    __shared3();
    __shared3(const __shared3 &);
    __shared3(const global_ENB_ID &, const selected_TAI &, const iE_Extensions &);
    __shared3(const global_ENB_ID &, const selected_TAI &);

    __shared3 & operator = (const __shared3 &);
    int operator == (const __shared3 &) const;
    int operator != (const __shared3 &) const;

    global_ENB_ID & get_global_ENB_ID();
    const global_ENB_ID & get_global_ENB_ID() const;
    void set_global_ENB_ID(const global_ENB_ID &);

    selected_TAI & get_selected_TAI();
    const selected_TAI & get_selected_TAI() const;
    void set_selected_TAI(const selected_TAI &);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    global_ENB_ID global_ENB_ID_field;
    selected_TAI selected_TAI_field;
    iE_Extensions iE_Extensions_field;
};

typedef __shared3 TargeteNB_ID;

class OSS_PUBLIC LAI   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OssString pLMNidentity;
    typedef OssString lAC;
    typedef __shared2 iE_Extensions;

    LAI();
    LAI(const LAI &);
    LAI(const pLMNidentity &, const lAC &, const iE_Extensions &);
    LAI(const pLMNidentity &, const lAC &);

    LAI & operator = (const LAI &);
    int operator == (const LAI &) const;
    int operator != (const LAI &) const;

    pLMNidentity & get_pLMNidentity();
    const pLMNidentity & get_pLMNidentity() const;
    void set_pLMNidentity(const pLMNidentity &);

    lAC & get_lAC();
    const lAC & get_lAC() const;
    void set_lAC(const lAC &);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    pLMNidentity pLMNidentity_field;
    lAC lAC_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC TargetRNC_ID   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef LAI lAI;
    typedef OssString rAC;
    typedef OSS_UINT32 rNC_ID;
    typedef OSS_UINT32 extendedRNC_ID;
    typedef __shared2 iE_Extensions;

    TargetRNC_ID();
    TargetRNC_ID(const TargetRNC_ID &);
    TargetRNC_ID(const lAI &, const rAC &, rNC_ID, extendedRNC_ID, const iE_Extensions &);
    TargetRNC_ID(const lAI &, rNC_ID);

    TargetRNC_ID & operator = (const TargetRNC_ID &);
    int operator == (const TargetRNC_ID &) const;
    int operator != (const TargetRNC_ID &) const;

    lAI & get_lAI();
    const lAI & get_lAI() const;
    void set_lAI(const lAI &);

    rAC *get_rAC();
    const rAC *get_rAC() const;
    void set_rAC(const rAC &);
    int rAC_is_present() const;
    void omit_rAC();

    rNC_ID & get_rNC_ID();
    rNC_ID get_rNC_ID() const;
    void set_rNC_ID(rNC_ID);

    extendedRNC_ID *get_extendedRNC_ID();
    const extendedRNC_ID *get_extendedRNC_ID() const;
    void set_extendedRNC_ID(extendedRNC_ID);
    int extendedRNC_ID_is_present() const;
    void omit_extendedRNC_ID();

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    lAI lAI_field;
    rAC rAC_field;
    rNC_ID rNC_ID_field;
    extendedRNC_ID extendedRNC_ID_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC CGI   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OssString pLMNidentity;
    typedef OssString lAC;
    typedef OssString cI;
    typedef OssString rAC;
    typedef __shared2 iE_Extensions;

    CGI();
    CGI(const CGI &);
    CGI(const pLMNidentity &, const lAC &, const cI &, const rAC &, const iE_Extensions &);
    CGI(const pLMNidentity &, const lAC &, const cI &);

    CGI & operator = (const CGI &);
    int operator == (const CGI &) const;
    int operator != (const CGI &) const;

    pLMNidentity & get_pLMNidentity();
    const pLMNidentity & get_pLMNidentity() const;
    void set_pLMNidentity(const pLMNidentity &);

    lAC & get_lAC();
    const lAC & get_lAC() const;
    void set_lAC(const lAC &);

    cI & get_cI();
    const cI & get_cI() const;
    void set_cI(const cI &);

    rAC *get_rAC();
    const rAC *get_rAC() const;
    void set_rAC(const rAC &);
    int rAC_is_present() const;
    void omit_rAC();

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    pLMNidentity pLMNidentity_field;
    lAC lAC_field;
    cI cI_field;
    rAC rAC_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC TargetID  : public OssChoice   /* CHOICE */
{
public:
    enum Id {
	unselected,
	targeteNB_ID_chosen = 1,
	targetRNC_ID_chosen = 2,
	cGI_chosen = 3
    };
    typedef __shared3 targeteNB_ID;
    typedef TargetRNC_ID targetRNC_ID;
    typedef CGI cGI;

    TargetID();
    TargetID(const TargetID &);
    ~TargetID();

    TargetID & operator = (const TargetID &);
    int operator == (const TargetID &) const;
    int operator != (const TargetID &) const;

    targeteNB_ID *get_targeteNB_ID();
    const targeteNB_ID *get_targeteNB_ID() const;
    void set_targeteNB_ID(const targeteNB_ID &);

    targetRNC_ID *get_targetRNC_ID();
    const targetRNC_ID *get_targetRNC_ID() const;
    void set_targetRNC_ID(const targetRNC_ID &);

    cGI *get_cGI();
    const cGI *get_cGI() const;
    void set_cGI(const cGI &);
private:
    union {
	targeteNB_ID *targeteNB_ID_field;
	targetRNC_ID *targetRNC_ID_field;
	cGI *cGI_field;
    };
    void cleanup();
};

class OSS_PUBLIC HandoverRequiredIEs_Value : public OssConstrainedOpenType
{
public:
    HandoverRequiredIEs_Value();
    HandoverRequiredIEs_Value(const HandoverRequiredIEs_Value &);
    ~HandoverRequiredIEs_Value();
    HandoverRequiredIEs_Value & operator = (const HandoverRequiredIEs_Value &);
    int operator == (const HandoverRequiredIEs_Value &) const;
    int operator != (const HandoverRequiredIEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    MME_UE_S1AP_ID *get_MME_UE_S1AP_ID();
    const MME_UE_S1AP_ID *get_MME_UE_S1AP_ID() const;
    void set_MME_UE_S1AP_ID(const MME_UE_S1AP_ID &);
    MME_UE_S1AP_ID *release_MME_UE_S1AP_ID();
    void set_MME_UE_S1AP_ID(MME_UE_S1AP_ID *);

    ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID();
    const ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID() const;
    void set_ENB_UE_S1AP_ID(const ENB_UE_S1AP_ID &);
    ENB_UE_S1AP_ID *release_ENB_UE_S1AP_ID();
    void set_ENB_UE_S1AP_ID(ENB_UE_S1AP_ID *);

    HandoverType *get_HandoverType();
    const HandoverType *get_HandoverType() const;
    void set_HandoverType(const HandoverType &);
    HandoverType *release_HandoverType();
    void set_HandoverType(HandoverType *);

    Cause *get_Cause();
    const Cause *get_Cause() const;
    void set_Cause(const Cause &);
    Cause *release_Cause();
    void set_Cause(Cause *);

    TargetID *get_TargetID();
    const TargetID *get_TargetID() const;
    void set_TargetID(const TargetID &);
    TargetID *release_TargetID();
    void set_TargetID(TargetID *);

    Direct_Forwarding_Path_Availability *get_Direct_Forwarding_Path_Availability();
    const Direct_Forwarding_Path_Availability *get_Direct_Forwarding_Path_Availability() const;
    void set_Direct_Forwarding_Path_Availability(const Direct_Forwarding_Path_Availability &);
    Direct_Forwarding_Path_Availability *release_Direct_Forwarding_Path_Availability();
    void set_Direct_Forwarding_Path_Availability(Direct_Forwarding_Path_Availability *);

    SRVCCHOIndication *get_SRVCCHOIndication();
    const SRVCCHOIndication *get_SRVCCHOIndication() const;
    void set_SRVCCHOIndication(const SRVCCHOIndication &);
    SRVCCHOIndication *release_SRVCCHOIndication();
    void set_SRVCCHOIndication(SRVCCHOIndication *);

    Source_ToTarget_TransparentContainer *get_Source_ToTarget_TransparentContainer();
    const Source_ToTarget_TransparentContainer *get_Source_ToTarget_TransparentContainer() const;
    void set_Source_ToTarget_TransparentContainer(const Source_ToTarget_TransparentContainer &);
    Source_ToTarget_TransparentContainer *release_Source_ToTarget_TransparentContainer();
    void set_Source_ToTarget_TransparentContainer(Source_ToTarget_TransparentContainer *);

    MSClassmark2 *get_MSClassmark2();
    const MSClassmark2 *get_MSClassmark2() const;
    void set_MSClassmark2(const MSClassmark2 &);
    MSClassmark2 *release_MSClassmark2();
    void set_MSClassmark2(MSClassmark2 *);

    MSClassmark3 *get_MSClassmark3();
    const MSClassmark3 *get_MSClassmark3() const;
    void set_MSClassmark3(const MSClassmark3 &);
    MSClassmark3 *release_MSClassmark3();
    void set_MSClassmark3(MSClassmark3 *);

    CSG_Id *get_CSG_Id();
    const CSG_Id *get_CSG_Id() const;
    void set_CSG_Id(const CSG_Id &);
    CSG_Id *release_CSG_Id();
    void set_CSG_Id(CSG_Id *);

    CellAccessMode *get_CellAccessMode();
    const CellAccessMode *get_CellAccessMode() const;
    void set_CellAccessMode(const CellAccessMode &);
    CellAccessMode *release_CellAccessMode();
    void set_CellAccessMode(CellAccessMode *);

    PS_ServiceNotAvailable *get_PS_ServiceNotAvailable();
    const PS_ServiceNotAvailable *get_PS_ServiceNotAvailable() const;
    void set_PS_ServiceNotAvailable(const PS_ServiceNotAvailable &);
    PS_ServiceNotAvailable *release_PS_ServiceNotAvailable();
    void set_PS_ServiceNotAvailable(PS_ServiceNotAvailable *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq1   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef HandoverRequiredIEs_Value value;

    __seq1();
    __seq1(const __seq1 &);
    __seq1(id, criticality, const value &);

    __seq1 & operator = (const __seq1 &);
    int operator == (const __seq1 &) const;
    int operator != (const __seq1 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC __seq3;

class OSS_PUBLIC E_RABSubjecttoDataForwardingList : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq3 component;

    E_RABSubjecttoDataForwardingList();
    E_RABSubjecttoDataForwardingList(const E_RABSubjecttoDataForwardingList &);
    ~E_RABSubjecttoDataForwardingList();

    E_RABSubjecttoDataForwardingList & operator = (const E_RABSubjecttoDataForwardingList &);
    int operator == (const E_RABSubjecttoDataForwardingList &) const;
    int operator != (const E_RABSubjecttoDataForwardingList &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(E_RABSubjecttoDataForwardingList *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, E_RABSubjecttoDataForwardingList *);

    int remove_front();
    int remove_after(OssIndex);

    E_RABSubjecttoDataForwardingList *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC __seq166;

class OSS_PUBLIC E_RABList : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq166 component;

    E_RABList();
    E_RABList(const E_RABList &);
    ~E_RABList();

    E_RABList & operator = (const E_RABList &);
    int operator == (const E_RABList &) const;
    int operator != (const E_RABList &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(E_RABList *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, E_RABList *);

    int remove_front();
    int remove_after(OssIndex);

    E_RABList *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC CriticalityDiagnostics_IE_Item;

class OSS_PUBLIC __shared18 : public OssList  /* SEQUENCE OF */
{
public:
    typedef CriticalityDiagnostics_IE_Item component;

    __shared18();
    __shared18(const __shared18 &);
    ~__shared18();

    __shared18 & operator = (const __shared18 &);
    int operator == (const __shared18 &) const;
    int operator != (const __shared18 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__shared18 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __shared18 *);

    int remove_front();
    int remove_after(OssIndex);

    __shared18 *extract_after(OssIndex, OssIndex);
};

typedef __shared18 CriticalityDiagnostics_IE_List;

class OSS_PUBLIC CriticalityDiagnostics   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 procedureCode;
    typedef enum TriggeringMessage triggeringMessage;
    typedef enum Criticality procedureCriticality;
    typedef __shared18 iEsCriticalityDiagnostics;
    typedef __shared2 iE_Extensions;

    CriticalityDiagnostics();
    CriticalityDiagnostics(const CriticalityDiagnostics &);
    CriticalityDiagnostics(procedureCode, triggeringMessage, procedureCriticality, 
	const iEsCriticalityDiagnostics &, const iE_Extensions &);

    CriticalityDiagnostics & operator = (const CriticalityDiagnostics &);
    int operator == (const CriticalityDiagnostics &) const;
    int operator != (const CriticalityDiagnostics &) const;

    procedureCode *get_procedureCode();
    const procedureCode *get_procedureCode() const;
    void set_procedureCode(procedureCode);
    int procedureCode_is_present() const;
    void omit_procedureCode();

    triggeringMessage *get_triggeringMessage();
    const triggeringMessage *get_triggeringMessage() const;
    void set_triggeringMessage(triggeringMessage);
    int triggeringMessage_is_present() const;
    void omit_triggeringMessage();

    procedureCriticality *get_procedureCriticality();
    const procedureCriticality *get_procedureCriticality() const;
    void set_procedureCriticality(procedureCriticality);
    int procedureCriticality_is_present() const;
    void omit_procedureCriticality();

    iEsCriticalityDiagnostics *get_iEsCriticalityDiagnostics();
    const iEsCriticalityDiagnostics *get_iEsCriticalityDiagnostics() const;
    void set_iEsCriticalityDiagnostics(const iEsCriticalityDiagnostics &);
    int iEsCriticalityDiagnostics_is_present() const;
    void omit_iEsCriticalityDiagnostics();

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    procedureCode procedureCode_field;
    triggeringMessage triggeringMessage_field;
    procedureCriticality procedureCriticality_field;
    iEsCriticalityDiagnostics iEsCriticalityDiagnostics_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC HandoverCommandIEs_Value : public OssConstrainedOpenType
{
public:
    HandoverCommandIEs_Value();
    HandoverCommandIEs_Value(const HandoverCommandIEs_Value &);
    ~HandoverCommandIEs_Value();
    HandoverCommandIEs_Value & operator = (const HandoverCommandIEs_Value &);
    int operator == (const HandoverCommandIEs_Value &) const;
    int operator != (const HandoverCommandIEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    MME_UE_S1AP_ID *get_MME_UE_S1AP_ID();
    const MME_UE_S1AP_ID *get_MME_UE_S1AP_ID() const;
    void set_MME_UE_S1AP_ID(const MME_UE_S1AP_ID &);
    MME_UE_S1AP_ID *release_MME_UE_S1AP_ID();
    void set_MME_UE_S1AP_ID(MME_UE_S1AP_ID *);

    ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID();
    const ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID() const;
    void set_ENB_UE_S1AP_ID(const ENB_UE_S1AP_ID &);
    ENB_UE_S1AP_ID *release_ENB_UE_S1AP_ID();
    void set_ENB_UE_S1AP_ID(ENB_UE_S1AP_ID *);

    HandoverType *get_HandoverType();
    const HandoverType *get_HandoverType() const;
    void set_HandoverType(const HandoverType &);
    HandoverType *release_HandoverType();
    void set_HandoverType(HandoverType *);

    NASSecurityParametersfromE_UTRAN *get_NASSecurityParametersfromE_UTRAN();
    const NASSecurityParametersfromE_UTRAN *get_NASSecurityParametersfromE_UTRAN() const;
    void set_NASSecurityParametersfromE_UTRAN(const NASSecurityParametersfromE_UTRAN &);
    NASSecurityParametersfromE_UTRAN *release_NASSecurityParametersfromE_UTRAN();
    void set_NASSecurityParametersfromE_UTRAN(NASSecurityParametersfromE_UTRAN *);

    E_RABSubjecttoDataForwardingList *get_E_RABSubjecttoDataForwardingList();
    const E_RABSubjecttoDataForwardingList *get_E_RABSubjecttoDataForwardingList() const;
    void set_E_RABSubjecttoDataForwardingList(const E_RABSubjecttoDataForwardingList &);
    E_RABSubjecttoDataForwardingList *release_E_RABSubjecttoDataForwardingList();
    void set_E_RABSubjecttoDataForwardingList(E_RABSubjecttoDataForwardingList *);

    E_RABList *get_E_RABList();
    const E_RABList *get_E_RABList() const;
    void set_E_RABList(const E_RABList &);
    E_RABList *release_E_RABList();
    void set_E_RABList(E_RABList *);

    Target_ToSource_TransparentContainer *get_Target_ToSource_TransparentContainer();
    const Target_ToSource_TransparentContainer *get_Target_ToSource_TransparentContainer() const;
    void set_Target_ToSource_TransparentContainer(const Target_ToSource_TransparentContainer &);
    Target_ToSource_TransparentContainer *release_Target_ToSource_TransparentContainer();
    void set_Target_ToSource_TransparentContainer(Target_ToSource_TransparentContainer *);

    CriticalityDiagnostics *get_CriticalityDiagnostics();
    const CriticalityDiagnostics *get_CriticalityDiagnostics() const;
    void set_CriticalityDiagnostics(const CriticalityDiagnostics &);
    CriticalityDiagnostics *release_CriticalityDiagnostics();
    void set_CriticalityDiagnostics(CriticalityDiagnostics *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq2   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef HandoverCommandIEs_Value value;

    __seq2();
    __seq2(const __seq2 &);
    __seq2(id, criticality, const value &);

    __seq2 & operator = (const __seq2 &);
    int operator == (const __seq2 &) const;
    int operator != (const __seq2 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC E_RABDataForwardingItem   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_INT32 e_RAB_ID;
    typedef OssBitString dL_transportLayerAddress;
    typedef OssString dL_gTP_TEID;
    typedef OssBitString uL_TransportLayerAddress;
    typedef OssString uL_GTP_TEID;
    typedef __shared2 iE_Extensions;

    E_RABDataForwardingItem();
    E_RABDataForwardingItem(const E_RABDataForwardingItem &);
    E_RABDataForwardingItem(e_RAB_ID, const dL_transportLayerAddress &, const dL_gTP_TEID &, 
	const uL_TransportLayerAddress &, const uL_GTP_TEID &, const iE_Extensions &);
    E_RABDataForwardingItem(e_RAB_ID);

    E_RABDataForwardingItem & operator = (const E_RABDataForwardingItem &);
    int operator == (const E_RABDataForwardingItem &) const;
    int operator != (const E_RABDataForwardingItem &) const;

    e_RAB_ID & get_e_RAB_ID();
    e_RAB_ID get_e_RAB_ID() const;
    void set_e_RAB_ID(e_RAB_ID);

    dL_transportLayerAddress *get_dL_transportLayerAddress();
    const dL_transportLayerAddress *get_dL_transportLayerAddress() const;
    void set_dL_transportLayerAddress(const dL_transportLayerAddress &);
    int dL_transportLayerAddress_is_present() const;
    void omit_dL_transportLayerAddress();

    dL_gTP_TEID *get_dL_gTP_TEID();
    const dL_gTP_TEID *get_dL_gTP_TEID() const;
    void set_dL_gTP_TEID(const dL_gTP_TEID &);
    int dL_gTP_TEID_is_present() const;
    void omit_dL_gTP_TEID();

    uL_TransportLayerAddress *get_uL_TransportLayerAddress();
    const uL_TransportLayerAddress *get_uL_TransportLayerAddress() const;
    void set_uL_TransportLayerAddress(const uL_TransportLayerAddress &);
    int uL_TransportLayerAddress_is_present() const;
    void omit_uL_TransportLayerAddress();

    uL_GTP_TEID *get_uL_GTP_TEID();
    const uL_GTP_TEID *get_uL_GTP_TEID() const;
    void set_uL_GTP_TEID(const uL_GTP_TEID &);
    int uL_GTP_TEID_is_present() const;
    void omit_uL_GTP_TEID();

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    e_RAB_ID e_RAB_ID_field;
    dL_transportLayerAddress dL_transportLayerAddress_field;
    dL_gTP_TEID dL_gTP_TEID_field;
    uL_TransportLayerAddress uL_TransportLayerAddress_field;
    uL_GTP_TEID uL_GTP_TEID_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC E_RABDataForwardingItemIEs_Value : public OssConstrainedOpenType
{
public:
    E_RABDataForwardingItemIEs_Value();
    E_RABDataForwardingItemIEs_Value(const E_RABDataForwardingItemIEs_Value &);
    ~E_RABDataForwardingItemIEs_Value();
    E_RABDataForwardingItemIEs_Value & operator = (const E_RABDataForwardingItemIEs_Value &);
    int operator == (const E_RABDataForwardingItemIEs_Value &) const;
    int operator != (const E_RABDataForwardingItemIEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    E_RABDataForwardingItem *get_E_RABDataForwardingItem();
    const E_RABDataForwardingItem *get_E_RABDataForwardingItem() const;
    void set_E_RABDataForwardingItem(const E_RABDataForwardingItem &);
    E_RABDataForwardingItem *release_E_RABDataForwardingItem();
    void set_E_RABDataForwardingItem(E_RABDataForwardingItem *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq3   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef E_RABDataForwardingItemIEs_Value value;

    __seq3();
    __seq3(const __seq3 &);
    __seq3(id, criticality, const value &);

    __seq3 & operator = (const __seq3 &);
    int operator == (const __seq3 &) const;
    int operator != (const __seq3 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

typedef OSS_INT32 E_RAB_ID;

typedef OssString GTP_TEID;

typedef OSS_UINT32 ProtocolExtensionID;

class OSS_PUBLIC E_RABDataForwardingItem_ExtIEs_Extension : public OssConstrainedOpenType
{
public:
    E_RABDataForwardingItem_ExtIEs_Extension();
    E_RABDataForwardingItem_ExtIEs_Extension(const E_RABDataForwardingItem_ExtIEs_Extension &);
    ~E_RABDataForwardingItem_ExtIEs_Extension();
    E_RABDataForwardingItem_ExtIEs_Extension & operator = (const E_RABDataForwardingItem_ExtIEs_Extension &);
    int operator == (const E_RABDataForwardingItem_ExtIEs_Extension &) const;
    int operator != (const E_RABDataForwardingItem_ExtIEs_Extension &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __shared1   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef E_RABDataForwardingItem_ExtIEs_Extension extensionValue;

    __shared1();
    __shared1(const __shared1 &);
    __shared1(id, criticality, const extensionValue &);

    __shared1 & operator = (const __shared1 &);
    int operator == (const __shared1 &) const;
    int operator != (const __shared1 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    extensionValue & get_extensionValue();
    const extensionValue & get_extensionValue() const;
    void set_extensionValue(const extensionValue &);
private:
    id id_field;
    criticality criticality_field;
    extensionValue extensionValue_field;
};

class OSS_PUBLIC HandoverPreparationFailureIEs_Value : public OssConstrainedOpenType
{
public:
    HandoverPreparationFailureIEs_Value();
    HandoverPreparationFailureIEs_Value(const HandoverPreparationFailureIEs_Value &);
    ~HandoverPreparationFailureIEs_Value();
    HandoverPreparationFailureIEs_Value & operator = (const HandoverPreparationFailureIEs_Value &);
    int operator == (const HandoverPreparationFailureIEs_Value &) const;
    int operator != (const HandoverPreparationFailureIEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    MME_UE_S1AP_ID *get_MME_UE_S1AP_ID();
    const MME_UE_S1AP_ID *get_MME_UE_S1AP_ID() const;
    void set_MME_UE_S1AP_ID(const MME_UE_S1AP_ID &);
    MME_UE_S1AP_ID *release_MME_UE_S1AP_ID();
    void set_MME_UE_S1AP_ID(MME_UE_S1AP_ID *);

    ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID();
    const ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID() const;
    void set_ENB_UE_S1AP_ID(const ENB_UE_S1AP_ID &);
    ENB_UE_S1AP_ID *release_ENB_UE_S1AP_ID();
    void set_ENB_UE_S1AP_ID(ENB_UE_S1AP_ID *);

    Cause *get_Cause();
    const Cause *get_Cause() const;
    void set_Cause(const Cause &);
    Cause *release_Cause();
    void set_Cause(Cause *);

    CriticalityDiagnostics *get_CriticalityDiagnostics();
    const CriticalityDiagnostics *get_CriticalityDiagnostics() const;
    void set_CriticalityDiagnostics(const CriticalityDiagnostics &);
    CriticalityDiagnostics *release_CriticalityDiagnostics();
    void set_CriticalityDiagnostics(CriticalityDiagnostics *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __shared19   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef HandoverPreparationFailureIEs_Value value;

    __shared19();
    __shared19(const __shared19 &);
    __shared19(id, criticality, const value &);

    __shared19 & operator = (const __shared19 &);
    int operator == (const __shared19 &) const;
    int operator != (const __shared19 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC UEAggregateMaximumBitrate   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT64 uEaggregateMaximumBitRateDL;
    typedef OSS_UINT64 uEaggregateMaximumBitRateUL;
    typedef __shared2 iE_Extensions;

    UEAggregateMaximumBitrate();
    UEAggregateMaximumBitrate(const UEAggregateMaximumBitrate &);
    UEAggregateMaximumBitrate(uEaggregateMaximumBitRateDL, uEaggregateMaximumBitRateUL, 
	const iE_Extensions &);
    UEAggregateMaximumBitrate(uEaggregateMaximumBitRateDL, uEaggregateMaximumBitRateUL);

    UEAggregateMaximumBitrate & operator = (const UEAggregateMaximumBitrate &);
    int operator == (const UEAggregateMaximumBitrate &) const;
    int operator != (const UEAggregateMaximumBitrate &) const;

    uEaggregateMaximumBitRateDL & get_uEaggregateMaximumBitRateDL();
    uEaggregateMaximumBitRateDL get_uEaggregateMaximumBitRateDL() const;
    void set_uEaggregateMaximumBitRateDL(uEaggregateMaximumBitRateDL);

    uEaggregateMaximumBitRateUL & get_uEaggregateMaximumBitRateUL();
    uEaggregateMaximumBitRateUL get_uEaggregateMaximumBitRateUL() const;
    void set_uEaggregateMaximumBitRateUL(uEaggregateMaximumBitRateUL);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    uEaggregateMaximumBitRateDL uEaggregateMaximumBitRateDL_field;
    uEaggregateMaximumBitRateUL uEaggregateMaximumBitRateUL_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC __seq7;

class OSS_PUBLIC E_RABToBeSetupListHOReq : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq7 component;

    E_RABToBeSetupListHOReq();
    E_RABToBeSetupListHOReq(const E_RABToBeSetupListHOReq &);
    ~E_RABToBeSetupListHOReq();

    E_RABToBeSetupListHOReq & operator = (const E_RABToBeSetupListHOReq &);
    int operator == (const E_RABToBeSetupListHOReq &) const;
    int operator != (const E_RABToBeSetupListHOReq &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(E_RABToBeSetupListHOReq *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, E_RABToBeSetupListHOReq *);

    int remove_front();
    int remove_after(OssIndex);

    E_RABToBeSetupListHOReq *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC UESecurityCapabilities   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OssBitString encryptionAlgorithms;
    typedef OssBitString integrityProtectionAlgorithms;
    typedef __shared2 iE_Extensions;

    UESecurityCapabilities();
    UESecurityCapabilities(const UESecurityCapabilities &);
    UESecurityCapabilities(const encryptionAlgorithms &, const integrityProtectionAlgorithms &, 
	const iE_Extensions &);
    UESecurityCapabilities(const encryptionAlgorithms &, const integrityProtectionAlgorithms &);

    UESecurityCapabilities & operator = (const UESecurityCapabilities &);
    int operator == (const UESecurityCapabilities &) const;
    int operator != (const UESecurityCapabilities &) const;

    encryptionAlgorithms & get_encryptionAlgorithms();
    const encryptionAlgorithms & get_encryptionAlgorithms() const;
    void set_encryptionAlgorithms(const encryptionAlgorithms &);

    integrityProtectionAlgorithms & get_integrityProtectionAlgorithms();
    const integrityProtectionAlgorithms & get_integrityProtectionAlgorithms() const;
    void set_integrityProtectionAlgorithms(const integrityProtectionAlgorithms &);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    encryptionAlgorithms encryptionAlgorithms_field;
    integrityProtectionAlgorithms integrityProtectionAlgorithms_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC __shared4 : public OssList  /* SEQUENCE OF */
{
public:
    typedef OssString component;

    __shared4();
    __shared4(const __shared4 &);
    ~__shared4();

    __shared4 & operator = (const __shared4 &);
    int operator == (const __shared4 &) const;
    int operator != (const __shared4 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__shared4 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __shared4 *);

    int remove_front();
    int remove_after(OssIndex);

    __shared4 *extract_after(OssIndex, OssIndex);
};

typedef __shared4 EPLMNs;

class OSS_PUBLIC ForbiddenTAs_Item;

class OSS_PUBLIC ForbiddenTAs : public OssList  /* SEQUENCE OF */
{
public:
    typedef ForbiddenTAs_Item component;

    ForbiddenTAs();
    ForbiddenTAs(const ForbiddenTAs &);
    ~ForbiddenTAs();

    ForbiddenTAs & operator = (const ForbiddenTAs &);
    int operator == (const ForbiddenTAs &) const;
    int operator != (const ForbiddenTAs &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(ForbiddenTAs *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, ForbiddenTAs *);

    int remove_front();
    int remove_after(OssIndex);

    ForbiddenTAs *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC ForbiddenLAs_Item;

class OSS_PUBLIC ForbiddenLAs : public OssList  /* SEQUENCE OF */
{
public:
    typedef ForbiddenLAs_Item component;

    ForbiddenLAs();
    ForbiddenLAs(const ForbiddenLAs &);
    ~ForbiddenLAs();

    ForbiddenLAs & operator = (const ForbiddenLAs &);
    int operator == (const ForbiddenLAs &) const;
    int operator != (const ForbiddenLAs &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(ForbiddenLAs *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, ForbiddenLAs *);

    int remove_front();
    int remove_after(OssIndex);

    ForbiddenLAs *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC HandoverRestrictionList   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OssString servingPLMN;
    typedef __shared4 equivalentPLMNs;
    typedef ForbiddenTAs forbiddenTAs;
    typedef ForbiddenLAs forbiddenLAs;
    typedef enum ForbiddenInterRATs forbiddenInterRATs;
    typedef __shared2 iE_Extensions;

    HandoverRestrictionList();
    HandoverRestrictionList(const HandoverRestrictionList &);
    HandoverRestrictionList(const servingPLMN &, const equivalentPLMNs &, const forbiddenTAs &, 
	const forbiddenLAs &, forbiddenInterRATs, const iE_Extensions &);
    HandoverRestrictionList(const servingPLMN &);

    HandoverRestrictionList & operator = (const HandoverRestrictionList &);
    int operator == (const HandoverRestrictionList &) const;
    int operator != (const HandoverRestrictionList &) const;

    servingPLMN & get_servingPLMN();
    const servingPLMN & get_servingPLMN() const;
    void set_servingPLMN(const servingPLMN &);

    equivalentPLMNs *get_equivalentPLMNs();
    const equivalentPLMNs *get_equivalentPLMNs() const;
    void set_equivalentPLMNs(const equivalentPLMNs &);
    int equivalentPLMNs_is_present() const;
    void omit_equivalentPLMNs();

    forbiddenTAs *get_forbiddenTAs();
    const forbiddenTAs *get_forbiddenTAs() const;
    void set_forbiddenTAs(const forbiddenTAs &);
    int forbiddenTAs_is_present() const;
    void omit_forbiddenTAs();

    forbiddenLAs *get_forbiddenLAs();
    const forbiddenLAs *get_forbiddenLAs() const;
    void set_forbiddenLAs(const forbiddenLAs &);
    int forbiddenLAs_is_present() const;
    void omit_forbiddenLAs();

    forbiddenInterRATs *get_forbiddenInterRATs();
    const forbiddenInterRATs *get_forbiddenInterRATs() const;
    void set_forbiddenInterRATs(forbiddenInterRATs);
    int forbiddenInterRATs_is_present() const;
    void omit_forbiddenInterRATs();

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    servingPLMN servingPLMN_field;
    equivalentPLMNs equivalentPLMNs_field;
    forbiddenTAs forbiddenTAs_field;
    forbiddenLAs forbiddenLAs_field;
    forbiddenInterRATs forbiddenInterRATs_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC __seq219;

class OSS_PUBLIC __seqof194 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq219 component;

    __seqof194();
    __seqof194(const __seqof194 &);
    ~__seqof194();

    __seqof194 & operator = (const __seqof194 &);
    int operator == (const __seqof194 &) const;
    int operator != (const __seqof194 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof194 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof194 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof194 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC TraceActivation   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OssString e_UTRAN_Trace_ID;
    typedef OssBitString interfacesToTrace;
    typedef enum TraceDepth traceDepth;
    typedef OssBitString traceCollectionEntityIPAddress;
    typedef __seqof194 iE_Extensions;

    TraceActivation();
    TraceActivation(const TraceActivation &);
    TraceActivation(const e_UTRAN_Trace_ID &, const interfacesToTrace &, traceDepth, 
	const traceCollectionEntityIPAddress &, const iE_Extensions &);
    TraceActivation(const e_UTRAN_Trace_ID &, const interfacesToTrace &, traceDepth, 
	const traceCollectionEntityIPAddress &);

    TraceActivation & operator = (const TraceActivation &);
    int operator == (const TraceActivation &) const;
    int operator != (const TraceActivation &) const;

    e_UTRAN_Trace_ID & get_e_UTRAN_Trace_ID();
    const e_UTRAN_Trace_ID & get_e_UTRAN_Trace_ID() const;
    void set_e_UTRAN_Trace_ID(const e_UTRAN_Trace_ID &);

    interfacesToTrace & get_interfacesToTrace();
    const interfacesToTrace & get_interfacesToTrace() const;
    void set_interfacesToTrace(const interfacesToTrace &);

    traceDepth & get_traceDepth();
    traceDepth get_traceDepth() const;
    void set_traceDepth(traceDepth);

    traceCollectionEntityIPAddress & get_traceCollectionEntityIPAddress();
    const traceCollectionEntityIPAddress & get_traceCollectionEntityIPAddress() const;
    void set_traceCollectionEntityIPAddress(const traceCollectionEntityIPAddress &);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    e_UTRAN_Trace_ID e_UTRAN_Trace_ID_field;
    interfacesToTrace interfacesToTrace_field;
    traceDepth traceDepth_field;
    traceCollectionEntityIPAddress traceCollectionEntityIPAddress_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC RequestType   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef enum EventType eventType;
    typedef enum ReportArea reportArea;
    typedef __shared2 iE_Extensions;

    RequestType();
    RequestType(const RequestType &);
    RequestType(eventType, reportArea, const iE_Extensions &);
    RequestType(eventType, reportArea);

    RequestType & operator = (const RequestType &);
    int operator == (const RequestType &) const;
    int operator != (const RequestType &) const;

    eventType & get_eventType();
    eventType get_eventType() const;
    void set_eventType(eventType);

    reportArea & get_reportArea();
    reportArea get_reportArea() const;
    void set_reportArea(reportArea);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    eventType eventType_field;
    reportArea reportArea_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC SecurityContext   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 nextHopChainingCount;
    typedef OssBitString nextHopParameter;
    typedef __shared2 iE_Extensions;

    SecurityContext();
    SecurityContext(const SecurityContext &);
    SecurityContext(nextHopChainingCount, const nextHopParameter &, const iE_Extensions &);
    SecurityContext(nextHopChainingCount, const nextHopParameter &);

    SecurityContext & operator = (const SecurityContext &);
    int operator == (const SecurityContext &) const;
    int operator != (const SecurityContext &) const;

    nextHopChainingCount & get_nextHopChainingCount();
    nextHopChainingCount get_nextHopChainingCount() const;
    void set_nextHopChainingCount(nextHopChainingCount);

    nextHopParameter & get_nextHopParameter();
    const nextHopParameter & get_nextHopParameter() const;
    void set_nextHopParameter(const nextHopParameter &);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    nextHopChainingCount nextHopChainingCount_field;
    nextHopParameter nextHopParameter_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC GUMMEI   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OssString pLMN_Identity;
    typedef OssString mME_Group_ID;
    typedef OssString mME_Code;
    typedef __shared2 iE_Extensions;

    GUMMEI();
    GUMMEI(const GUMMEI &);
    GUMMEI(const pLMN_Identity &, const mME_Group_ID &, const mME_Code &, const iE_Extensions &);
    GUMMEI(const pLMN_Identity &, const mME_Group_ID &, const mME_Code &);

    GUMMEI & operator = (const GUMMEI &);
    int operator == (const GUMMEI &) const;
    int operator != (const GUMMEI &) const;

    pLMN_Identity & get_pLMN_Identity();
    const pLMN_Identity & get_pLMN_Identity() const;
    void set_pLMN_Identity(const pLMN_Identity &);

    mME_Group_ID & get_mME_Group_ID();
    const mME_Group_ID & get_mME_Group_ID() const;
    void set_mME_Group_ID(const mME_Group_ID &);

    mME_Code & get_mME_Code();
    const mME_Code & get_mME_Code() const;
    void set_mME_Code(const mME_Code &);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    pLMN_Identity pLMN_Identity_field;
    mME_Group_ID mME_Group_ID_field;
    mME_Code mME_Code_field;
    iE_Extensions iE_Extensions_field;
};

typedef __shared4 MDTPLMNList;

class OSS_PUBLIC ExpectedUEActivityBehaviour   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_INT32 expectedActivityPeriod;
    typedef OSS_INT32 expectedIdlePeriod;
    typedef enum SourceOfUEActivityBehaviourInformation sourceofUEActivityBehaviourInformation;
    typedef __shared2 iE_Extensions;

    ExpectedUEActivityBehaviour();
    ExpectedUEActivityBehaviour(const ExpectedUEActivityBehaviour &);
    ExpectedUEActivityBehaviour(expectedActivityPeriod, expectedIdlePeriod, sourceofUEActivityBehaviourInformation, 
	const iE_Extensions &);

    ExpectedUEActivityBehaviour & operator = (const ExpectedUEActivityBehaviour &);
    int operator == (const ExpectedUEActivityBehaviour &) const;
    int operator != (const ExpectedUEActivityBehaviour &) const;

    expectedActivityPeriod *get_expectedActivityPeriod();
    const expectedActivityPeriod *get_expectedActivityPeriod() const;
    void set_expectedActivityPeriod(expectedActivityPeriod);
    int expectedActivityPeriod_is_present() const;
    void omit_expectedActivityPeriod();

    expectedIdlePeriod *get_expectedIdlePeriod();
    const expectedIdlePeriod *get_expectedIdlePeriod() const;
    void set_expectedIdlePeriod(expectedIdlePeriod);
    int expectedIdlePeriod_is_present() const;
    void omit_expectedIdlePeriod();

    sourceofUEActivityBehaviourInformation *get_sourceofUEActivityBehaviourInformation();
    const sourceofUEActivityBehaviourInformation *get_sourceofUEActivityBehaviourInformation() const;
    void set_sourceofUEActivityBehaviourInformation(sourceofUEActivityBehaviourInformation);
    int sourceofUEActivityBehaviourInformation_is_present() const;
    void omit_sourceofUEActivityBehaviourInformation();

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    expectedActivityPeriod expectedActivityPeriod_field;
    expectedIdlePeriod expectedIdlePeriod_field;
    sourceofUEActivityBehaviourInformation sourceofUEActivityBehaviourInformation_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC ExpectedUEBehaviour   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef ExpectedUEActivityBehaviour expectedActivity;
    typedef enum ExpectedHOInterval expectedHOInterval;
    typedef __shared2 iE_Extensions;

    ExpectedUEBehaviour();
    ExpectedUEBehaviour(const ExpectedUEBehaviour &);
    ExpectedUEBehaviour(const expectedActivity &, expectedHOInterval, const iE_Extensions &);

    ExpectedUEBehaviour & operator = (const ExpectedUEBehaviour &);
    int operator == (const ExpectedUEBehaviour &) const;
    int operator != (const ExpectedUEBehaviour &) const;

    expectedActivity *get_expectedActivity();
    const expectedActivity *get_expectedActivity() const;
    void set_expectedActivity(const expectedActivity &);
    int expectedActivity_is_present() const;
    void omit_expectedActivity();

    expectedHOInterval *get_expectedHOInterval();
    const expectedHOInterval *get_expectedHOInterval() const;
    void set_expectedHOInterval(expectedHOInterval);
    int expectedHOInterval_is_present() const;
    void omit_expectedHOInterval();

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    expectedActivity expectedActivity_field;
    expectedHOInterval expectedHOInterval_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC __seq192;

class OSS_PUBLIC __seqof169 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq192 component;

    __seqof169();
    __seqof169(const __seqof169 &);
    ~__seqof169();

    __seqof169 & operator = (const __seqof169 &);
    int operator == (const __seqof169 &) const;
    int operator != (const __seqof169 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof169 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof169 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof169 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC ProSeAuthorized   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef enum ProSeDirectDiscovery proSeDirectDiscovery;
    typedef enum ProSeDirectCommunication proSeDirectCommunication;
    typedef __seqof169 iE_Extensions;

    ProSeAuthorized();
    ProSeAuthorized(const ProSeAuthorized &);
    ProSeAuthorized(proSeDirectDiscovery, proSeDirectCommunication, const iE_Extensions &);

    ProSeAuthorized & operator = (const ProSeAuthorized &);
    int operator == (const ProSeAuthorized &) const;
    int operator != (const ProSeAuthorized &) const;

    proSeDirectDiscovery *get_proSeDirectDiscovery();
    const proSeDirectDiscovery *get_proSeDirectDiscovery() const;
    void set_proSeDirectDiscovery(proSeDirectDiscovery);
    int proSeDirectDiscovery_is_present() const;
    void omit_proSeDirectDiscovery();

    proSeDirectCommunication *get_proSeDirectCommunication();
    const proSeDirectCommunication *get_proSeDirectCommunication() const;
    void set_proSeDirectCommunication(proSeDirectCommunication);
    int proSeDirectCommunication_is_present() const;
    void omit_proSeDirectCommunication();

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    proSeDirectDiscovery proSeDirectDiscovery_field;
    proSeDirectCommunication proSeDirectCommunication_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC HandoverRequestIEs_Value : public OssConstrainedOpenType
{
public:
    HandoverRequestIEs_Value();
    HandoverRequestIEs_Value(const HandoverRequestIEs_Value &);
    ~HandoverRequestIEs_Value();
    HandoverRequestIEs_Value & operator = (const HandoverRequestIEs_Value &);
    int operator == (const HandoverRequestIEs_Value &) const;
    int operator != (const HandoverRequestIEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    MME_UE_S1AP_ID *get_MME_UE_S1AP_ID();
    const MME_UE_S1AP_ID *get_MME_UE_S1AP_ID() const;
    void set_MME_UE_S1AP_ID(const MME_UE_S1AP_ID &);
    MME_UE_S1AP_ID *release_MME_UE_S1AP_ID();
    void set_MME_UE_S1AP_ID(MME_UE_S1AP_ID *);

    HandoverType *get_HandoverType();
    const HandoverType *get_HandoverType() const;
    void set_HandoverType(const HandoverType &);
    HandoverType *release_HandoverType();
    void set_HandoverType(HandoverType *);

    Cause *get_Cause();
    const Cause *get_Cause() const;
    void set_Cause(const Cause &);
    Cause *release_Cause();
    void set_Cause(Cause *);

    UEAggregateMaximumBitrate *get_UEAggregateMaximumBitrate();
    const UEAggregateMaximumBitrate *get_UEAggregateMaximumBitrate() const;
    void set_UEAggregateMaximumBitrate(const UEAggregateMaximumBitrate &);
    UEAggregateMaximumBitrate *release_UEAggregateMaximumBitrate();
    void set_UEAggregateMaximumBitrate(UEAggregateMaximumBitrate *);

    E_RABToBeSetupListHOReq *get_E_RABToBeSetupListHOReq();
    const E_RABToBeSetupListHOReq *get_E_RABToBeSetupListHOReq() const;
    void set_E_RABToBeSetupListHOReq(const E_RABToBeSetupListHOReq &);
    E_RABToBeSetupListHOReq *release_E_RABToBeSetupListHOReq();
    void set_E_RABToBeSetupListHOReq(E_RABToBeSetupListHOReq *);

    Source_ToTarget_TransparentContainer *get_Source_ToTarget_TransparentContainer();
    const Source_ToTarget_TransparentContainer *get_Source_ToTarget_TransparentContainer() const;
    void set_Source_ToTarget_TransparentContainer(const Source_ToTarget_TransparentContainer &);
    Source_ToTarget_TransparentContainer *release_Source_ToTarget_TransparentContainer();
    void set_Source_ToTarget_TransparentContainer(Source_ToTarget_TransparentContainer *);

    UESecurityCapabilities *get_UESecurityCapabilities();
    const UESecurityCapabilities *get_UESecurityCapabilities() const;
    void set_UESecurityCapabilities(const UESecurityCapabilities &);
    UESecurityCapabilities *release_UESecurityCapabilities();
    void set_UESecurityCapabilities(UESecurityCapabilities *);

    HandoverRestrictionList *get_HandoverRestrictionList();
    const HandoverRestrictionList *get_HandoverRestrictionList() const;
    void set_HandoverRestrictionList(const HandoverRestrictionList &);
    HandoverRestrictionList *release_HandoverRestrictionList();
    void set_HandoverRestrictionList(HandoverRestrictionList *);

    TraceActivation *get_TraceActivation();
    const TraceActivation *get_TraceActivation() const;
    void set_TraceActivation(const TraceActivation &);
    TraceActivation *release_TraceActivation();
    void set_TraceActivation(TraceActivation *);

    RequestType *get_RequestType();
    const RequestType *get_RequestType() const;
    void set_RequestType(const RequestType &);
    RequestType *release_RequestType();
    void set_RequestType(RequestType *);

    SRVCCOperationPossible *get_SRVCCOperationPossible();
    const SRVCCOperationPossible *get_SRVCCOperationPossible() const;
    void set_SRVCCOperationPossible(const SRVCCOperationPossible &);
    SRVCCOperationPossible *release_SRVCCOperationPossible();
    void set_SRVCCOperationPossible(SRVCCOperationPossible *);

    SecurityContext *get_SecurityContext();
    const SecurityContext *get_SecurityContext() const;
    void set_SecurityContext(const SecurityContext &);
    SecurityContext *release_SecurityContext();
    void set_SecurityContext(SecurityContext *);

    NASSecurityParameterstoE_UTRAN *get_NASSecurityParameterstoE_UTRAN();
    const NASSecurityParameterstoE_UTRAN *get_NASSecurityParameterstoE_UTRAN() const;
    void set_NASSecurityParameterstoE_UTRAN(const NASSecurityParameterstoE_UTRAN &);
    NASSecurityParameterstoE_UTRAN *release_NASSecurityParameterstoE_UTRAN();
    void set_NASSecurityParameterstoE_UTRAN(NASSecurityParameterstoE_UTRAN *);

    CSG_Id *get_CSG_Id();
    const CSG_Id *get_CSG_Id() const;
    void set_CSG_Id(const CSG_Id &);
    CSG_Id *release_CSG_Id();
    void set_CSG_Id(CSG_Id *);

    CSGMembershipStatus *get_CSGMembershipStatus();
    const CSGMembershipStatus *get_CSGMembershipStatus() const;
    void set_CSGMembershipStatus(const CSGMembershipStatus &);
    CSGMembershipStatus *release_CSGMembershipStatus();
    void set_CSGMembershipStatus(CSGMembershipStatus *);

    GUMMEI *get_GUMMEI();
    const GUMMEI *get_GUMMEI() const;
    void set_GUMMEI(const GUMMEI &);
    GUMMEI *release_GUMMEI();
    void set_GUMMEI(GUMMEI *);

    ManagementBasedMDTAllowed *get_ManagementBasedMDTAllowed();
    const ManagementBasedMDTAllowed *get_ManagementBasedMDTAllowed() const;
    void set_ManagementBasedMDTAllowed(const ManagementBasedMDTAllowed &);
    ManagementBasedMDTAllowed *release_ManagementBasedMDTAllowed();
    void set_ManagementBasedMDTAllowed(ManagementBasedMDTAllowed *);

    __shared4 *get_MDTPLMNList();
    const __shared4 *get_MDTPLMNList() const;
    void set_MDTPLMNList(const __shared4 &);
    __shared4 *release_MDTPLMNList();
    void set_MDTPLMNList(__shared4 *);

    Masked_IMEISV *get_Masked_IMEISV();
    const Masked_IMEISV *get_Masked_IMEISV() const;
    void set_Masked_IMEISV(const Masked_IMEISV &);
    Masked_IMEISV *release_Masked_IMEISV();
    void set_Masked_IMEISV(Masked_IMEISV *);

    ExpectedUEBehaviour *get_ExpectedUEBehaviour();
    const ExpectedUEBehaviour *get_ExpectedUEBehaviour() const;
    void set_ExpectedUEBehaviour(const ExpectedUEBehaviour &);
    ExpectedUEBehaviour *release_ExpectedUEBehaviour();
    void set_ExpectedUEBehaviour(ExpectedUEBehaviour *);

    ProSeAuthorized *get_ProSeAuthorized();
    const ProSeAuthorized *get_ProSeAuthorized() const;
    void set_ProSeAuthorized(const ProSeAuthorized &);
    ProSeAuthorized *release_ProSeAuthorized();
    void set_ProSeAuthorized(ProSeAuthorized *);

    UEUserPlaneCIoTSupportIndicator *get_UEUserPlaneCIoTSupportIndicator();
    const UEUserPlaneCIoTSupportIndicator *get_UEUserPlaneCIoTSupportIndicator() const;
    void set_UEUserPlaneCIoTSupportIndicator(const UEUserPlaneCIoTSupportIndicator &);
    UEUserPlaneCIoTSupportIndicator *release_UEUserPlaneCIoTSupportIndicator();
    void set_UEUserPlaneCIoTSupportIndicator(UEUserPlaneCIoTSupportIndicator *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq6   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef HandoverRequestIEs_Value value;

    __seq6();
    __seq6(const __seq6 &);
    __seq6(id, criticality, const value &);

    __seq6 & operator = (const __seq6 &);
    int operator == (const __seq6 &) const;
    int operator != (const __seq6 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC AllocationAndRetentionPriority   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 priorityLevel;
    typedef enum Pre_emptionCapability pre_emptionCapability;
    typedef enum Pre_emptionVulnerability pre_emptionVulnerability;
    typedef __shared2 iE_Extensions;

    AllocationAndRetentionPriority();
    AllocationAndRetentionPriority(const AllocationAndRetentionPriority &);
    AllocationAndRetentionPriority(priorityLevel, pre_emptionCapability, pre_emptionVulnerability, 
	const iE_Extensions &);
    AllocationAndRetentionPriority(priorityLevel, pre_emptionCapability, pre_emptionVulnerability);

    AllocationAndRetentionPriority & operator = (const AllocationAndRetentionPriority &);
    int operator == (const AllocationAndRetentionPriority &) const;
    int operator != (const AllocationAndRetentionPriority &) const;

    priorityLevel & get_priorityLevel();
    priorityLevel get_priorityLevel() const;
    void set_priorityLevel(priorityLevel);

    pre_emptionCapability & get_pre_emptionCapability();
    pre_emptionCapability get_pre_emptionCapability() const;
    void set_pre_emptionCapability(pre_emptionCapability);

    pre_emptionVulnerability & get_pre_emptionVulnerability();
    pre_emptionVulnerability get_pre_emptionVulnerability() const;
    void set_pre_emptionVulnerability(pre_emptionVulnerability);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    priorityLevel priorityLevel_field;
    pre_emptionCapability pre_emptionCapability_field;
    pre_emptionVulnerability pre_emptionVulnerability_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC GBR_QosInformation   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT64 e_RAB_MaximumBitrateDL;
    typedef OSS_UINT64 e_RAB_MaximumBitrateUL;
    typedef OSS_UINT64 e_RAB_GuaranteedBitrateDL;
    typedef OSS_UINT64 e_RAB_GuaranteedBitrateUL;
    typedef __shared2 iE_Extensions;

    GBR_QosInformation();
    GBR_QosInformation(const GBR_QosInformation &);
    GBR_QosInformation(e_RAB_MaximumBitrateDL, e_RAB_MaximumBitrateUL, e_RAB_GuaranteedBitrateDL, 
	e_RAB_GuaranteedBitrateUL, const iE_Extensions &);
    GBR_QosInformation(e_RAB_MaximumBitrateDL, e_RAB_MaximumBitrateUL, e_RAB_GuaranteedBitrateDL, 
	e_RAB_GuaranteedBitrateUL);

    GBR_QosInformation & operator = (const GBR_QosInformation &);
    int operator == (const GBR_QosInformation &) const;
    int operator != (const GBR_QosInformation &) const;

    e_RAB_MaximumBitrateDL & get_e_RAB_MaximumBitrateDL();
    e_RAB_MaximumBitrateDL get_e_RAB_MaximumBitrateDL() const;
    void set_e_RAB_MaximumBitrateDL(e_RAB_MaximumBitrateDL);

    e_RAB_MaximumBitrateUL & get_e_RAB_MaximumBitrateUL();
    e_RAB_MaximumBitrateUL get_e_RAB_MaximumBitrateUL() const;
    void set_e_RAB_MaximumBitrateUL(e_RAB_MaximumBitrateUL);

    e_RAB_GuaranteedBitrateDL & get_e_RAB_GuaranteedBitrateDL();
    e_RAB_GuaranteedBitrateDL get_e_RAB_GuaranteedBitrateDL() const;
    void set_e_RAB_GuaranteedBitrateDL(e_RAB_GuaranteedBitrateDL);

    e_RAB_GuaranteedBitrateUL & get_e_RAB_GuaranteedBitrateUL();
    e_RAB_GuaranteedBitrateUL get_e_RAB_GuaranteedBitrateUL() const;
    void set_e_RAB_GuaranteedBitrateUL(e_RAB_GuaranteedBitrateUL);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    e_RAB_MaximumBitrateDL e_RAB_MaximumBitrateDL_field;
    e_RAB_MaximumBitrateUL e_RAB_MaximumBitrateUL_field;
    e_RAB_GuaranteedBitrateDL e_RAB_GuaranteedBitrateDL_field;
    e_RAB_GuaranteedBitrateUL e_RAB_GuaranteedBitrateUL_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC E_RABLevelQoSParameters   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 qCI;
    typedef AllocationAndRetentionPriority allocationRetentionPriority;
    typedef GBR_QosInformation gbrQosInformation;
    typedef __shared2 iE_Extensions;

    E_RABLevelQoSParameters();
    E_RABLevelQoSParameters(const E_RABLevelQoSParameters &);
    E_RABLevelQoSParameters(qCI, const allocationRetentionPriority &, const gbrQosInformation &, 
	const iE_Extensions &);
    E_RABLevelQoSParameters(qCI, const allocationRetentionPriority &);

    E_RABLevelQoSParameters & operator = (const E_RABLevelQoSParameters &);
    int operator == (const E_RABLevelQoSParameters &) const;
    int operator != (const E_RABLevelQoSParameters &) const;

    qCI & get_qCI();
    qCI get_qCI() const;
    void set_qCI(qCI);

    allocationRetentionPriority & get_allocationRetentionPriority();
    const allocationRetentionPriority & get_allocationRetentionPriority() const;
    void set_allocationRetentionPriority(const allocationRetentionPriority &);

    gbrQosInformation *get_gbrQosInformation();
    const gbrQosInformation *get_gbrQosInformation() const;
    void set_gbrQosInformation(const gbrQosInformation &);
    int gbrQosInformation_is_present() const;
    void omit_gbrQosInformation();

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    qCI qCI_field;
    allocationRetentionPriority allocationRetentionPriority_field;
    gbrQosInformation gbrQosInformation_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC __seq11;

class OSS_PUBLIC __seqof9 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq11 component;

    __seqof9();
    __seqof9(const __seqof9 &);
    ~__seqof9();

    __seqof9 & operator = (const __seqof9 &);
    int operator == (const __seqof9 &) const;
    int operator != (const __seqof9 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof9 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof9 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof9 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC E_RABToBeSetupItemHOReq   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_INT32 e_RAB_ID;
    typedef OssBitString transportLayerAddress;
    typedef OssString gTP_TEID;
    typedef E_RABLevelQoSParameters e_RABlevelQosParameters;
    typedef __seqof9 iE_Extensions;

    E_RABToBeSetupItemHOReq();
    E_RABToBeSetupItemHOReq(const E_RABToBeSetupItemHOReq &);
    E_RABToBeSetupItemHOReq(e_RAB_ID, const transportLayerAddress &, const gTP_TEID &, 
	const e_RABlevelQosParameters &, const iE_Extensions &);
    E_RABToBeSetupItemHOReq(e_RAB_ID, const transportLayerAddress &, const gTP_TEID &, 
	const e_RABlevelQosParameters &);

    E_RABToBeSetupItemHOReq & operator = (const E_RABToBeSetupItemHOReq &);
    int operator == (const E_RABToBeSetupItemHOReq &) const;
    int operator != (const E_RABToBeSetupItemHOReq &) const;

    e_RAB_ID & get_e_RAB_ID();
    e_RAB_ID get_e_RAB_ID() const;
    void set_e_RAB_ID(e_RAB_ID);

    transportLayerAddress & get_transportLayerAddress();
    const transportLayerAddress & get_transportLayerAddress() const;
    void set_transportLayerAddress(const transportLayerAddress &);

    gTP_TEID & get_gTP_TEID();
    const gTP_TEID & get_gTP_TEID() const;
    void set_gTP_TEID(const gTP_TEID &);

    e_RABlevelQosParameters & get_e_RABlevelQosParameters();
    const e_RABlevelQosParameters & get_e_RABlevelQosParameters() const;
    void set_e_RABlevelQosParameters(const e_RABlevelQosParameters &);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    e_RAB_ID e_RAB_ID_field;
    transportLayerAddress transportLayerAddress_field;
    gTP_TEID gTP_TEID_field;
    e_RABlevelQosParameters e_RABlevelQosParameters_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC E_RABToBeSetupItemHOReqIEs_Value : public OssConstrainedOpenType
{
public:
    E_RABToBeSetupItemHOReqIEs_Value();
    E_RABToBeSetupItemHOReqIEs_Value(const E_RABToBeSetupItemHOReqIEs_Value &);
    ~E_RABToBeSetupItemHOReqIEs_Value();
    E_RABToBeSetupItemHOReqIEs_Value & operator = (const E_RABToBeSetupItemHOReqIEs_Value &);
    int operator == (const E_RABToBeSetupItemHOReqIEs_Value &) const;
    int operator != (const E_RABToBeSetupItemHOReqIEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    E_RABToBeSetupItemHOReq *get_E_RABToBeSetupItemHOReq();
    const E_RABToBeSetupItemHOReq *get_E_RABToBeSetupItemHOReq() const;
    void set_E_RABToBeSetupItemHOReq(const E_RABToBeSetupItemHOReq &);
    E_RABToBeSetupItemHOReq *release_E_RABToBeSetupItemHOReq();
    void set_E_RABToBeSetupItemHOReq(E_RABToBeSetupItemHOReq *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq7   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef E_RABToBeSetupItemHOReqIEs_Value value;

    __seq7();
    __seq7(const __seq7 &);
    __seq7(id, criticality, const value &);

    __seq7 & operator = (const __seq7 &);
    int operator == (const __seq7 &) const;
    int operator != (const __seq7 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

typedef OSS_UINT32 QCI;

typedef OSS_UINT32 PriorityLevel;

typedef OSS_UINT64 BitRate;

class OSS_PUBLIC E_RABToBeSetupItemHOReq_ExtIEs_Extension : public OssConstrainedOpenType
{
public:
    E_RABToBeSetupItemHOReq_ExtIEs_Extension();
    E_RABToBeSetupItemHOReq_ExtIEs_Extension(const E_RABToBeSetupItemHOReq_ExtIEs_Extension &);
    ~E_RABToBeSetupItemHOReq_ExtIEs_Extension();
    E_RABToBeSetupItemHOReq_ExtIEs_Extension & operator = (const E_RABToBeSetupItemHOReq_ExtIEs_Extension &);
    int operator == (const E_RABToBeSetupItemHOReq_ExtIEs_Extension &) const;
    int operator != (const E_RABToBeSetupItemHOReq_ExtIEs_Extension &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    Data_Forwarding_Not_Possible *get_Data_Forwarding_Not_Possible();
    const Data_Forwarding_Not_Possible *get_Data_Forwarding_Not_Possible() const;
    void set_Data_Forwarding_Not_Possible(const Data_Forwarding_Not_Possible &);
    Data_Forwarding_Not_Possible *release_Data_Forwarding_Not_Possible();
    void set_Data_Forwarding_Not_Possible(Data_Forwarding_Not_Possible *);

    BearerType *get_BearerType();
    const BearerType *get_BearerType() const;
    void set_BearerType(const BearerType &);
    BearerType *release_BearerType();
    void set_BearerType(BearerType *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq11   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef E_RABToBeSetupItemHOReq_ExtIEs_Extension extensionValue;

    __seq11();
    __seq11(const __seq11 &);
    __seq11(id, criticality, const extensionValue &);

    __seq11 & operator = (const __seq11 &);
    int operator == (const __seq11 &) const;
    int operator != (const __seq11 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    extensionValue & get_extensionValue();
    const extensionValue & get_extensionValue() const;
    void set_extensionValue(const extensionValue &);
private:
    id id_field;
    criticality criticality_field;
    extensionValue extensionValue_field;
};

class OSS_PUBLIC __seq13;

class OSS_PUBLIC E_RABAdmittedList : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq13 component;

    E_RABAdmittedList();
    E_RABAdmittedList(const E_RABAdmittedList &);
    ~E_RABAdmittedList();

    E_RABAdmittedList & operator = (const E_RABAdmittedList &);
    int operator == (const E_RABAdmittedList &) const;
    int operator != (const E_RABAdmittedList &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(E_RABAdmittedList *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, E_RABAdmittedList *);

    int remove_front();
    int remove_after(OssIndex);

    E_RABAdmittedList *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC __seq15;

class OSS_PUBLIC E_RABFailedtoSetupListHOReqAck : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq15 component;

    E_RABFailedtoSetupListHOReqAck();
    E_RABFailedtoSetupListHOReqAck(const E_RABFailedtoSetupListHOReqAck &);
    ~E_RABFailedtoSetupListHOReqAck();

    E_RABFailedtoSetupListHOReqAck & operator = (const E_RABFailedtoSetupListHOReqAck &);
    int operator == (const E_RABFailedtoSetupListHOReqAck &) const;
    int operator != (const E_RABFailedtoSetupListHOReqAck &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(E_RABFailedtoSetupListHOReqAck *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, E_RABFailedtoSetupListHOReqAck *);

    int remove_front();
    int remove_after(OssIndex);

    E_RABFailedtoSetupListHOReqAck *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC HandoverRequestAcknowledgeIEs_Value : public OssConstrainedOpenType
{
public:
    HandoverRequestAcknowledgeIEs_Value();
    HandoverRequestAcknowledgeIEs_Value(const HandoverRequestAcknowledgeIEs_Value &);
    ~HandoverRequestAcknowledgeIEs_Value();
    HandoverRequestAcknowledgeIEs_Value & operator = (const HandoverRequestAcknowledgeIEs_Value &);
    int operator == (const HandoverRequestAcknowledgeIEs_Value &) const;
    int operator != (const HandoverRequestAcknowledgeIEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    MME_UE_S1AP_ID *get_MME_UE_S1AP_ID();
    const MME_UE_S1AP_ID *get_MME_UE_S1AP_ID() const;
    void set_MME_UE_S1AP_ID(const MME_UE_S1AP_ID &);
    MME_UE_S1AP_ID *release_MME_UE_S1AP_ID();
    void set_MME_UE_S1AP_ID(MME_UE_S1AP_ID *);

    ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID();
    const ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID() const;
    void set_ENB_UE_S1AP_ID(const ENB_UE_S1AP_ID &);
    ENB_UE_S1AP_ID *release_ENB_UE_S1AP_ID();
    void set_ENB_UE_S1AP_ID(ENB_UE_S1AP_ID *);

    E_RABAdmittedList *get_E_RABAdmittedList();
    const E_RABAdmittedList *get_E_RABAdmittedList() const;
    void set_E_RABAdmittedList(const E_RABAdmittedList &);
    E_RABAdmittedList *release_E_RABAdmittedList();
    void set_E_RABAdmittedList(E_RABAdmittedList *);

    E_RABFailedtoSetupListHOReqAck *get_E_RABFailedtoSetupListHOReqAck();
    const E_RABFailedtoSetupListHOReqAck *get_E_RABFailedtoSetupListHOReqAck() const;
    void set_E_RABFailedtoSetupListHOReqAck(const E_RABFailedtoSetupListHOReqAck &);
    E_RABFailedtoSetupListHOReqAck *release_E_RABFailedtoSetupListHOReqAck();
    void set_E_RABFailedtoSetupListHOReqAck(E_RABFailedtoSetupListHOReqAck *);

    Target_ToSource_TransparentContainer *get_Target_ToSource_TransparentContainer();
    const Target_ToSource_TransparentContainer *get_Target_ToSource_TransparentContainer() const;
    void set_Target_ToSource_TransparentContainer(const Target_ToSource_TransparentContainer &);
    Target_ToSource_TransparentContainer *release_Target_ToSource_TransparentContainer();
    void set_Target_ToSource_TransparentContainer(Target_ToSource_TransparentContainer *);

    CSG_Id *get_CSG_Id();
    const CSG_Id *get_CSG_Id() const;
    void set_CSG_Id(const CSG_Id &);
    CSG_Id *release_CSG_Id();
    void set_CSG_Id(CSG_Id *);

    CriticalityDiagnostics *get_CriticalityDiagnostics();
    const CriticalityDiagnostics *get_CriticalityDiagnostics() const;
    void set_CriticalityDiagnostics(const CriticalityDiagnostics &);
    CriticalityDiagnostics *release_CriticalityDiagnostics();
    void set_CriticalityDiagnostics(CriticalityDiagnostics *);

    CellAccessMode *get_CellAccessMode();
    const CellAccessMode *get_CellAccessMode() const;
    void set_CellAccessMode(const CellAccessMode &);
    CellAccessMode *release_CellAccessMode();
    void set_CellAccessMode(CellAccessMode *);

    CE_mode_B_SupportIndicator *get_CE_mode_B_SupportIndicator();
    const CE_mode_B_SupportIndicator *get_CE_mode_B_SupportIndicator() const;
    void set_CE_mode_B_SupportIndicator(const CE_mode_B_SupportIndicator &);
    CE_mode_B_SupportIndicator *release_CE_mode_B_SupportIndicator();
    void set_CE_mode_B_SupportIndicator(CE_mode_B_SupportIndicator *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq12   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef HandoverRequestAcknowledgeIEs_Value value;

    __seq12();
    __seq12(const __seq12 &);
    __seq12(id, criticality, const value &);

    __seq12 & operator = (const __seq12 &);
    int operator == (const __seq12 &) const;
    int operator != (const __seq12 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC E_RABAdmittedItem   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_INT32 e_RAB_ID;
    typedef OssBitString transportLayerAddress;
    typedef OssString gTP_TEID;
    typedef OssBitString dL_transportLayerAddress;
    typedef OssString dL_gTP_TEID;
    typedef OssBitString uL_TransportLayerAddress;
    typedef OssString uL_GTP_TEID;
    typedef __shared2 iE_Extensions;

    E_RABAdmittedItem();
    E_RABAdmittedItem(const E_RABAdmittedItem &);
    E_RABAdmittedItem(e_RAB_ID, const transportLayerAddress &, const gTP_TEID &, 
	const dL_transportLayerAddress &, const dL_gTP_TEID &, const uL_TransportLayerAddress &, 
	const uL_GTP_TEID &, const iE_Extensions &);
    E_RABAdmittedItem(e_RAB_ID, const transportLayerAddress &, const gTP_TEID &);

    E_RABAdmittedItem & operator = (const E_RABAdmittedItem &);
    int operator == (const E_RABAdmittedItem &) const;
    int operator != (const E_RABAdmittedItem &) const;

    e_RAB_ID & get_e_RAB_ID();
    e_RAB_ID get_e_RAB_ID() const;
    void set_e_RAB_ID(e_RAB_ID);

    transportLayerAddress & get_transportLayerAddress();
    const transportLayerAddress & get_transportLayerAddress() const;
    void set_transportLayerAddress(const transportLayerAddress &);

    gTP_TEID & get_gTP_TEID();
    const gTP_TEID & get_gTP_TEID() const;
    void set_gTP_TEID(const gTP_TEID &);

    dL_transportLayerAddress *get_dL_transportLayerAddress();
    const dL_transportLayerAddress *get_dL_transportLayerAddress() const;
    void set_dL_transportLayerAddress(const dL_transportLayerAddress &);
    int dL_transportLayerAddress_is_present() const;
    void omit_dL_transportLayerAddress();

    dL_gTP_TEID *get_dL_gTP_TEID();
    const dL_gTP_TEID *get_dL_gTP_TEID() const;
    void set_dL_gTP_TEID(const dL_gTP_TEID &);
    int dL_gTP_TEID_is_present() const;
    void omit_dL_gTP_TEID();

    uL_TransportLayerAddress *get_uL_TransportLayerAddress();
    const uL_TransportLayerAddress *get_uL_TransportLayerAddress() const;
    void set_uL_TransportLayerAddress(const uL_TransportLayerAddress &);
    int uL_TransportLayerAddress_is_present() const;
    void omit_uL_TransportLayerAddress();

    uL_GTP_TEID *get_uL_GTP_TEID();
    const uL_GTP_TEID *get_uL_GTP_TEID() const;
    void set_uL_GTP_TEID(const uL_GTP_TEID &);
    int uL_GTP_TEID_is_present() const;
    void omit_uL_GTP_TEID();

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    e_RAB_ID e_RAB_ID_field;
    transportLayerAddress transportLayerAddress_field;
    gTP_TEID gTP_TEID_field;
    dL_transportLayerAddress dL_transportLayerAddress_field;
    dL_gTP_TEID dL_gTP_TEID_field;
    uL_TransportLayerAddress uL_TransportLayerAddress_field;
    uL_GTP_TEID uL_GTP_TEID_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC E_RABAdmittedItemIEs_Value : public OssConstrainedOpenType
{
public:
    E_RABAdmittedItemIEs_Value();
    E_RABAdmittedItemIEs_Value(const E_RABAdmittedItemIEs_Value &);
    ~E_RABAdmittedItemIEs_Value();
    E_RABAdmittedItemIEs_Value & operator = (const E_RABAdmittedItemIEs_Value &);
    int operator == (const E_RABAdmittedItemIEs_Value &) const;
    int operator != (const E_RABAdmittedItemIEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    E_RABAdmittedItem *get_E_RABAdmittedItem();
    const E_RABAdmittedItem *get_E_RABAdmittedItem() const;
    void set_E_RABAdmittedItem(const E_RABAdmittedItem &);
    E_RABAdmittedItem *release_E_RABAdmittedItem();
    void set_E_RABAdmittedItem(E_RABAdmittedItem *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq13   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef E_RABAdmittedItemIEs_Value value;

    __seq13();
    __seq13(const __seq13 &);
    __seq13(id, criticality, const value &);

    __seq13 & operator = (const __seq13 &);
    int operator == (const __seq13 &) const;
    int operator != (const __seq13 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC __shared11   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_INT32 e_RAB_ID;
    typedef Cause cause;
    typedef __shared2 iE_Extensions;

    __shared11();
    __shared11(const __shared11 &);
    __shared11(e_RAB_ID, const cause &, const iE_Extensions &);
    __shared11(e_RAB_ID, const cause &);

    __shared11 & operator = (const __shared11 &);
    int operator == (const __shared11 &) const;
    int operator != (const __shared11 &) const;

    e_RAB_ID & get_e_RAB_ID();
    e_RAB_ID get_e_RAB_ID() const;
    void set_e_RAB_ID(e_RAB_ID);

    cause & get_cause();
    const cause & get_cause() const;
    void set_cause(const cause &);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    e_RAB_ID e_RAB_ID_field;
    cause cause_field;
    iE_Extensions iE_Extensions_field;
};

typedef __shared11 E_RABItem;

typedef __shared11 E_RABFailedToSetupItemHOReqAck;

class OSS_PUBLIC E_RABFailedtoSetupItemHOReqAckIEs_Value : public OssConstrainedOpenType
{
public:
    E_RABFailedtoSetupItemHOReqAckIEs_Value();
    E_RABFailedtoSetupItemHOReqAckIEs_Value(const E_RABFailedtoSetupItemHOReqAckIEs_Value &);
    ~E_RABFailedtoSetupItemHOReqAckIEs_Value();
    E_RABFailedtoSetupItemHOReqAckIEs_Value & operator = (const E_RABFailedtoSetupItemHOReqAckIEs_Value &);
    int operator == (const E_RABFailedtoSetupItemHOReqAckIEs_Value &) const;
    int operator != (const E_RABFailedtoSetupItemHOReqAckIEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    __shared11 *get_E_RABFailedToSetupItemHOReqAck();
    const __shared11 *get_E_RABFailedToSetupItemHOReqAck() const;
    void set_E_RABFailedToSetupItemHOReqAck(const __shared11 &);
    __shared11 *release_E_RABFailedToSetupItemHOReqAck();
    void set_E_RABFailedToSetupItemHOReqAck(__shared11 *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq15   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef E_RABFailedtoSetupItemHOReqAckIEs_Value value;

    __seq15();
    __seq15(const __seq15 &);
    __seq15(id, criticality, const value &);

    __seq15 & operator = (const __seq15 &);
    int operator == (const __seq15 &) const;
    int operator != (const __seq15 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC HandoverFailureIEs_Value : public OssConstrainedOpenType
{
public:
    HandoverFailureIEs_Value();
    HandoverFailureIEs_Value(const HandoverFailureIEs_Value &);
    ~HandoverFailureIEs_Value();
    HandoverFailureIEs_Value & operator = (const HandoverFailureIEs_Value &);
    int operator == (const HandoverFailureIEs_Value &) const;
    int operator != (const HandoverFailureIEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    MME_UE_S1AP_ID *get_MME_UE_S1AP_ID();
    const MME_UE_S1AP_ID *get_MME_UE_S1AP_ID() const;
    void set_MME_UE_S1AP_ID(const MME_UE_S1AP_ID &);
    MME_UE_S1AP_ID *release_MME_UE_S1AP_ID();
    void set_MME_UE_S1AP_ID(MME_UE_S1AP_ID *);

    Cause *get_Cause();
    const Cause *get_Cause() const;
    void set_Cause(const Cause &);
    Cause *release_Cause();
    void set_Cause(Cause *);

    CriticalityDiagnostics *get_CriticalityDiagnostics();
    const CriticalityDiagnostics *get_CriticalityDiagnostics() const;
    void set_CriticalityDiagnostics(const CriticalityDiagnostics &);
    CriticalityDiagnostics *release_CriticalityDiagnostics();
    void set_CriticalityDiagnostics(CriticalityDiagnostics *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq17   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef HandoverFailureIEs_Value value;

    __seq17();
    __seq17(const __seq17 &);
    __seq17(id, criticality, const value &);

    __seq17 & operator = (const __seq17 &);
    int operator == (const __seq17 &) const;
    int operator != (const __seq17 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC EUTRAN_CGI   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OssString pLMNidentity;
    typedef OssBitString cell_ID;
    typedef __shared2 iE_Extensions;

    EUTRAN_CGI();
    EUTRAN_CGI(const EUTRAN_CGI &);
    EUTRAN_CGI(const pLMNidentity &, const cell_ID &, const iE_Extensions &);
    EUTRAN_CGI(const pLMNidentity &, const cell_ID &);

    EUTRAN_CGI & operator = (const EUTRAN_CGI &);
    int operator == (const EUTRAN_CGI &) const;
    int operator != (const EUTRAN_CGI &) const;

    pLMNidentity & get_pLMNidentity();
    const pLMNidentity & get_pLMNidentity() const;
    void set_pLMNidentity(const pLMNidentity &);

    cell_ID & get_cell_ID();
    const cell_ID & get_cell_ID() const;
    void set_cell_ID(const cell_ID &);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    pLMNidentity pLMNidentity_field;
    cell_ID cell_ID_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC TunnelInformation   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OssBitString transportLayerAddress;
    typedef OssString uDP_Port_Number;
    typedef __shared2 iE_Extensions;

    TunnelInformation();
    TunnelInformation(const TunnelInformation &);
    TunnelInformation(const transportLayerAddress &, const uDP_Port_Number &, const iE_Extensions &);
    TunnelInformation(const transportLayerAddress &);

    TunnelInformation & operator = (const TunnelInformation &);
    int operator == (const TunnelInformation &) const;
    int operator != (const TunnelInformation &) const;

    transportLayerAddress & get_transportLayerAddress();
    const transportLayerAddress & get_transportLayerAddress() const;
    void set_transportLayerAddress(const transportLayerAddress &);

    uDP_Port_Number *get_uDP_Port_Number();
    const uDP_Port_Number *get_uDP_Port_Number() const;
    void set_uDP_Port_Number(const uDP_Port_Number &);
    int uDP_Port_Number_is_present() const;
    void omit_uDP_Port_Number();

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    transportLayerAddress transportLayerAddress_field;
    uDP_Port_Number uDP_Port_Number_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC HandoverNotifyIEs_Value : public OssConstrainedOpenType
{
public:
    HandoverNotifyIEs_Value();
    HandoverNotifyIEs_Value(const HandoverNotifyIEs_Value &);
    ~HandoverNotifyIEs_Value();
    HandoverNotifyIEs_Value & operator = (const HandoverNotifyIEs_Value &);
    int operator == (const HandoverNotifyIEs_Value &) const;
    int operator != (const HandoverNotifyIEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    MME_UE_S1AP_ID *get_MME_UE_S1AP_ID();
    const MME_UE_S1AP_ID *get_MME_UE_S1AP_ID() const;
    void set_MME_UE_S1AP_ID(const MME_UE_S1AP_ID &);
    MME_UE_S1AP_ID *release_MME_UE_S1AP_ID();
    void set_MME_UE_S1AP_ID(MME_UE_S1AP_ID *);

    ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID();
    const ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID() const;
    void set_ENB_UE_S1AP_ID(const ENB_UE_S1AP_ID &);
    ENB_UE_S1AP_ID *release_ENB_UE_S1AP_ID();
    void set_ENB_UE_S1AP_ID(ENB_UE_S1AP_ID *);

    EUTRAN_CGI *get_EUTRAN_CGI();
    const EUTRAN_CGI *get_EUTRAN_CGI() const;
    void set_EUTRAN_CGI(const EUTRAN_CGI &);
    EUTRAN_CGI *release_EUTRAN_CGI();
    void set_EUTRAN_CGI(EUTRAN_CGI *);

    TAI *get_TAI();
    const TAI *get_TAI() const;
    void set_TAI(const TAI &);
    TAI *release_TAI();
    void set_TAI(TAI *);

    TunnelInformation *get_TunnelInformation();
    const TunnelInformation *get_TunnelInformation() const;
    void set_TunnelInformation(const TunnelInformation &);
    TunnelInformation *release_TunnelInformation();
    void set_TunnelInformation(TunnelInformation *);

    LHN_ID *get_LHN_ID();
    const LHN_ID *get_LHN_ID() const;
    void set_LHN_ID(const LHN_ID &);
    LHN_ID *release_LHN_ID();
    void set_LHN_ID(LHN_ID *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq18   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef HandoverNotifyIEs_Value value;

    __seq18();
    __seq18(const __seq18 &);
    __seq18(id, criticality, const value &);

    __seq18 & operator = (const __seq18 &);
    int operator == (const __seq18 &) const;
    int operator != (const __seq18 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC __seq20;

class OSS_PUBLIC E_RABToBeSwitchedDLList : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq20 component;

    E_RABToBeSwitchedDLList();
    E_RABToBeSwitchedDLList(const E_RABToBeSwitchedDLList &);
    ~E_RABToBeSwitchedDLList();

    E_RABToBeSwitchedDLList & operator = (const E_RABToBeSwitchedDLList &);
    int operator == (const E_RABToBeSwitchedDLList &) const;
    int operator != (const E_RABToBeSwitchedDLList &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(E_RABToBeSwitchedDLList *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, E_RABToBeSwitchedDLList *);

    int remove_front();
    int remove_after(OssIndex);

    E_RABToBeSwitchedDLList *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC PathSwitchRequestIEs_Value : public OssConstrainedOpenType
{
public:
    PathSwitchRequestIEs_Value();
    PathSwitchRequestIEs_Value(const PathSwitchRequestIEs_Value &);
    ~PathSwitchRequestIEs_Value();
    PathSwitchRequestIEs_Value & operator = (const PathSwitchRequestIEs_Value &);
    int operator == (const PathSwitchRequestIEs_Value &) const;
    int operator != (const PathSwitchRequestIEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID();
    const ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID() const;
    void set_ENB_UE_S1AP_ID(const ENB_UE_S1AP_ID &);
    ENB_UE_S1AP_ID *release_ENB_UE_S1AP_ID();
    void set_ENB_UE_S1AP_ID(ENB_UE_S1AP_ID *);

    E_RABToBeSwitchedDLList *get_E_RABToBeSwitchedDLList();
    const E_RABToBeSwitchedDLList *get_E_RABToBeSwitchedDLList() const;
    void set_E_RABToBeSwitchedDLList(const E_RABToBeSwitchedDLList &);
    E_RABToBeSwitchedDLList *release_E_RABToBeSwitchedDLList();
    void set_E_RABToBeSwitchedDLList(E_RABToBeSwitchedDLList *);

    MME_UE_S1AP_ID *get_MME_UE_S1AP_ID();
    const MME_UE_S1AP_ID *get_MME_UE_S1AP_ID() const;
    void set_MME_UE_S1AP_ID(const MME_UE_S1AP_ID &);
    MME_UE_S1AP_ID *release_MME_UE_S1AP_ID();
    void set_MME_UE_S1AP_ID(MME_UE_S1AP_ID *);

    EUTRAN_CGI *get_EUTRAN_CGI();
    const EUTRAN_CGI *get_EUTRAN_CGI() const;
    void set_EUTRAN_CGI(const EUTRAN_CGI &);
    EUTRAN_CGI *release_EUTRAN_CGI();
    void set_EUTRAN_CGI(EUTRAN_CGI *);

    TAI *get_TAI();
    const TAI *get_TAI() const;
    void set_TAI(const TAI &);
    TAI *release_TAI();
    void set_TAI(TAI *);

    UESecurityCapabilities *get_UESecurityCapabilities();
    const UESecurityCapabilities *get_UESecurityCapabilities() const;
    void set_UESecurityCapabilities(const UESecurityCapabilities &);
    UESecurityCapabilities *release_UESecurityCapabilities();
    void set_UESecurityCapabilities(UESecurityCapabilities *);

    CSG_Id *get_CSG_Id();
    const CSG_Id *get_CSG_Id() const;
    void set_CSG_Id(const CSG_Id &);
    CSG_Id *release_CSG_Id();
    void set_CSG_Id(CSG_Id *);

    CellAccessMode *get_CellAccessMode();
    const CellAccessMode *get_CellAccessMode() const;
    void set_CellAccessMode(const CellAccessMode &);
    CellAccessMode *release_CellAccessMode();
    void set_CellAccessMode(CellAccessMode *);

    GUMMEI *get_GUMMEI();
    const GUMMEI *get_GUMMEI() const;
    void set_GUMMEI(const GUMMEI &);
    GUMMEI *release_GUMMEI();
    void set_GUMMEI(GUMMEI *);

    CSGMembershipStatus *get_CSGMembershipStatus();
    const CSGMembershipStatus *get_CSGMembershipStatus() const;
    void set_CSGMembershipStatus(const CSGMembershipStatus &);
    CSGMembershipStatus *release_CSGMembershipStatus();
    void set_CSGMembershipStatus(CSGMembershipStatus *);

    TunnelInformation *get_TunnelInformation();
    const TunnelInformation *get_TunnelInformation() const;
    void set_TunnelInformation(const TunnelInformation &);
    TunnelInformation *release_TunnelInformation();
    void set_TunnelInformation(TunnelInformation *);

    LHN_ID *get_LHN_ID();
    const LHN_ID *get_LHN_ID() const;
    void set_LHN_ID(const LHN_ID &);
    LHN_ID *release_LHN_ID();
    void set_LHN_ID(LHN_ID *);

    RRC_Establishment_Cause *get_RRC_Establishment_Cause();
    const RRC_Establishment_Cause *get_RRC_Establishment_Cause() const;
    void set_RRC_Establishment_Cause(const RRC_Establishment_Cause &);
    RRC_Establishment_Cause *release_RRC_Establishment_Cause();
    void set_RRC_Establishment_Cause(RRC_Establishment_Cause *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq19   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef PathSwitchRequestIEs_Value value;

    __seq19();
    __seq19(const __seq19 &);
    __seq19(id, criticality, const value &);

    __seq19 & operator = (const __seq19 &);
    int operator == (const __seq19 &) const;
    int operator != (const __seq19 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC __shared8   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_INT32 e_RAB_ID;
    typedef OssBitString transportLayerAddress;
    typedef OssString gTP_TEID;
    typedef __shared2 iE_Extensions;

    __shared8();
    __shared8(const __shared8 &);
    __shared8(e_RAB_ID, const transportLayerAddress &, const gTP_TEID &, const iE_Extensions &);
    __shared8(e_RAB_ID, const transportLayerAddress &, const gTP_TEID &);

    __shared8 & operator = (const __shared8 &);
    int operator == (const __shared8 &) const;
    int operator != (const __shared8 &) const;

    e_RAB_ID & get_e_RAB_ID();
    e_RAB_ID get_e_RAB_ID() const;
    void set_e_RAB_ID(e_RAB_ID);

    transportLayerAddress & get_transportLayerAddress();
    const transportLayerAddress & get_transportLayerAddress() const;
    void set_transportLayerAddress(const transportLayerAddress &);

    gTP_TEID & get_gTP_TEID();
    const gTP_TEID & get_gTP_TEID() const;
    void set_gTP_TEID(const gTP_TEID &);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    e_RAB_ID e_RAB_ID_field;
    transportLayerAddress transportLayerAddress_field;
    gTP_TEID gTP_TEID_field;
    iE_Extensions iE_Extensions_field;
};

typedef __shared8 E_RABToBeSwitchedDLItem;

class OSS_PUBLIC E_RABToBeSwitchedDLItemIEs_Value : public OssConstrainedOpenType
{
public:
    E_RABToBeSwitchedDLItemIEs_Value();
    E_RABToBeSwitchedDLItemIEs_Value(const E_RABToBeSwitchedDLItemIEs_Value &);
    ~E_RABToBeSwitchedDLItemIEs_Value();
    E_RABToBeSwitchedDLItemIEs_Value & operator = (const E_RABToBeSwitchedDLItemIEs_Value &);
    int operator == (const E_RABToBeSwitchedDLItemIEs_Value &) const;
    int operator != (const E_RABToBeSwitchedDLItemIEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    __shared8 *get_E_RABToBeSwitchedDLItem();
    const __shared8 *get_E_RABToBeSwitchedDLItem() const;
    void set_E_RABToBeSwitchedDLItem(const __shared8 &);
    __shared8 *release_E_RABToBeSwitchedDLItem();
    void set_E_RABToBeSwitchedDLItem(__shared8 *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq20   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef E_RABToBeSwitchedDLItemIEs_Value value;

    __seq20();
    __seq20(const __seq20 &);
    __seq20(id, criticality, const value &);

    __seq20 & operator = (const __seq20 &);
    int operator == (const __seq20 &) const;
    int operator != (const __seq20 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC __seq23;

class OSS_PUBLIC E_RABToBeSwitchedULList : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq23 component;

    E_RABToBeSwitchedULList();
    E_RABToBeSwitchedULList(const E_RABToBeSwitchedULList &);
    ~E_RABToBeSwitchedULList();

    E_RABToBeSwitchedULList & operator = (const E_RABToBeSwitchedULList &);
    int operator == (const E_RABToBeSwitchedULList &) const;
    int operator != (const E_RABToBeSwitchedULList &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(E_RABToBeSwitchedULList *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, E_RABToBeSwitchedULList *);

    int remove_front();
    int remove_after(OssIndex);

    E_RABToBeSwitchedULList *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC PathSwitchRequestAcknowledgeIEs_Value : public OssConstrainedOpenType
{
public:
    PathSwitchRequestAcknowledgeIEs_Value();
    PathSwitchRequestAcknowledgeIEs_Value(const PathSwitchRequestAcknowledgeIEs_Value &);
    ~PathSwitchRequestAcknowledgeIEs_Value();
    PathSwitchRequestAcknowledgeIEs_Value & operator = (const PathSwitchRequestAcknowledgeIEs_Value &);
    int operator == (const PathSwitchRequestAcknowledgeIEs_Value &) const;
    int operator != (const PathSwitchRequestAcknowledgeIEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    MME_UE_S1AP_ID *get_MME_UE_S1AP_ID();
    const MME_UE_S1AP_ID *get_MME_UE_S1AP_ID() const;
    void set_MME_UE_S1AP_ID(const MME_UE_S1AP_ID &);
    MME_UE_S1AP_ID *release_MME_UE_S1AP_ID();
    void set_MME_UE_S1AP_ID(MME_UE_S1AP_ID *);

    ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID();
    const ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID() const;
    void set_ENB_UE_S1AP_ID(const ENB_UE_S1AP_ID &);
    ENB_UE_S1AP_ID *release_ENB_UE_S1AP_ID();
    void set_ENB_UE_S1AP_ID(ENB_UE_S1AP_ID *);

    UEAggregateMaximumBitrate *get_UEAggregateMaximumBitrate();
    const UEAggregateMaximumBitrate *get_UEAggregateMaximumBitrate() const;
    void set_UEAggregateMaximumBitrate(const UEAggregateMaximumBitrate &);
    UEAggregateMaximumBitrate *release_UEAggregateMaximumBitrate();
    void set_UEAggregateMaximumBitrate(UEAggregateMaximumBitrate *);

    E_RABToBeSwitchedULList *get_E_RABToBeSwitchedULList();
    const E_RABToBeSwitchedULList *get_E_RABToBeSwitchedULList() const;
    void set_E_RABToBeSwitchedULList(const E_RABToBeSwitchedULList &);
    E_RABToBeSwitchedULList *release_E_RABToBeSwitchedULList();
    void set_E_RABToBeSwitchedULList(E_RABToBeSwitchedULList *);

    E_RABList *get_E_RABList();
    const E_RABList *get_E_RABList() const;
    void set_E_RABList(const E_RABList &);
    E_RABList *release_E_RABList();
    void set_E_RABList(E_RABList *);

    SecurityContext *get_SecurityContext();
    const SecurityContext *get_SecurityContext() const;
    void set_SecurityContext(const SecurityContext &);
    SecurityContext *release_SecurityContext();
    void set_SecurityContext(SecurityContext *);

    CriticalityDiagnostics *get_CriticalityDiagnostics();
    const CriticalityDiagnostics *get_CriticalityDiagnostics() const;
    void set_CriticalityDiagnostics(const CriticalityDiagnostics &);
    CriticalityDiagnostics *release_CriticalityDiagnostics();
    void set_CriticalityDiagnostics(CriticalityDiagnostics *);

    CSGMembershipStatus *get_CSGMembershipStatus();
    const CSGMembershipStatus *get_CSGMembershipStatus() const;
    void set_CSGMembershipStatus(const CSGMembershipStatus &);
    CSGMembershipStatus *release_CSGMembershipStatus();
    void set_CSGMembershipStatus(CSGMembershipStatus *);

    ProSeAuthorized *get_ProSeAuthorized();
    const ProSeAuthorized *get_ProSeAuthorized() const;
    void set_ProSeAuthorized(const ProSeAuthorized &);
    ProSeAuthorized *release_ProSeAuthorized();
    void set_ProSeAuthorized(ProSeAuthorized *);

    UEUserPlaneCIoTSupportIndicator *get_UEUserPlaneCIoTSupportIndicator();
    const UEUserPlaneCIoTSupportIndicator *get_UEUserPlaneCIoTSupportIndicator() const;
    void set_UEUserPlaneCIoTSupportIndicator(const UEUserPlaneCIoTSupportIndicator &);
    UEUserPlaneCIoTSupportIndicator *release_UEUserPlaneCIoTSupportIndicator();
    void set_UEUserPlaneCIoTSupportIndicator(UEUserPlaneCIoTSupportIndicator *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq22   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef PathSwitchRequestAcknowledgeIEs_Value value;

    __seq22();
    __seq22(const __seq22 &);
    __seq22(id, criticality, const value &);

    __seq22 & operator = (const __seq22 &);
    int operator == (const __seq22 &) const;
    int operator != (const __seq22 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

typedef __shared8 E_RABToBeSwitchedULItem;

class OSS_PUBLIC E_RABToBeSwitchedULItemIEs_Value : public OssConstrainedOpenType
{
public:
    E_RABToBeSwitchedULItemIEs_Value();
    E_RABToBeSwitchedULItemIEs_Value(const E_RABToBeSwitchedULItemIEs_Value &);
    ~E_RABToBeSwitchedULItemIEs_Value();
    E_RABToBeSwitchedULItemIEs_Value & operator = (const E_RABToBeSwitchedULItemIEs_Value &);
    int operator == (const E_RABToBeSwitchedULItemIEs_Value &) const;
    int operator != (const E_RABToBeSwitchedULItemIEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    __shared8 *get_E_RABToBeSwitchedULItem();
    const __shared8 *get_E_RABToBeSwitchedULItem() const;
    void set_E_RABToBeSwitchedULItem(const __shared8 &);
    __shared8 *release_E_RABToBeSwitchedULItem();
    void set_E_RABToBeSwitchedULItem(__shared8 *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq23   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef E_RABToBeSwitchedULItemIEs_Value value;

    __seq23();
    __seq23(const __seq23 &);
    __seq23(id, criticality, const value &);

    __seq23 & operator = (const __seq23 &);
    int operator == (const __seq23 &) const;
    int operator != (const __seq23 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC HandoverCancelIEs_Value : public OssConstrainedOpenType
{
public:
    HandoverCancelIEs_Value();
    HandoverCancelIEs_Value(const HandoverCancelIEs_Value &);
    ~HandoverCancelIEs_Value();
    HandoverCancelIEs_Value & operator = (const HandoverCancelIEs_Value &);
    int operator == (const HandoverCancelIEs_Value &) const;
    int operator != (const HandoverCancelIEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    MME_UE_S1AP_ID *get_MME_UE_S1AP_ID();
    const MME_UE_S1AP_ID *get_MME_UE_S1AP_ID() const;
    void set_MME_UE_S1AP_ID(const MME_UE_S1AP_ID &);
    MME_UE_S1AP_ID *release_MME_UE_S1AP_ID();
    void set_MME_UE_S1AP_ID(MME_UE_S1AP_ID *);

    ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID();
    const ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID() const;
    void set_ENB_UE_S1AP_ID(const ENB_UE_S1AP_ID &);
    ENB_UE_S1AP_ID *release_ENB_UE_S1AP_ID();
    void set_ENB_UE_S1AP_ID(ENB_UE_S1AP_ID *);

    Cause *get_Cause();
    const Cause *get_Cause() const;
    void set_Cause(const Cause &);
    Cause *release_Cause();
    void set_Cause(Cause *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __shared12   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef HandoverCancelIEs_Value value;

    __shared12();
    __shared12(const __shared12 &);
    __shared12(id, criticality, const value &);

    __shared12 & operator = (const __shared12 &);
    int operator == (const __shared12 &) const;
    int operator != (const __shared12 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC HandoverCancelAcknowledgeIEs_Value : public OssConstrainedOpenType
{
public:
    HandoverCancelAcknowledgeIEs_Value();
    HandoverCancelAcknowledgeIEs_Value(const HandoverCancelAcknowledgeIEs_Value &);
    ~HandoverCancelAcknowledgeIEs_Value();
    HandoverCancelAcknowledgeIEs_Value & operator = (const HandoverCancelAcknowledgeIEs_Value &);
    int operator == (const HandoverCancelAcknowledgeIEs_Value &) const;
    int operator != (const HandoverCancelAcknowledgeIEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    MME_UE_S1AP_ID *get_MME_UE_S1AP_ID();
    const MME_UE_S1AP_ID *get_MME_UE_S1AP_ID() const;
    void set_MME_UE_S1AP_ID(const MME_UE_S1AP_ID &);
    MME_UE_S1AP_ID *release_MME_UE_S1AP_ID();
    void set_MME_UE_S1AP_ID(MME_UE_S1AP_ID *);

    ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID();
    const ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID() const;
    void set_ENB_UE_S1AP_ID(const ENB_UE_S1AP_ID &);
    ENB_UE_S1AP_ID *release_ENB_UE_S1AP_ID();
    void set_ENB_UE_S1AP_ID(ENB_UE_S1AP_ID *);

    CriticalityDiagnostics *get_CriticalityDiagnostics();
    const CriticalityDiagnostics *get_CriticalityDiagnostics() const;
    void set_CriticalityDiagnostics(const CriticalityDiagnostics &);
    CriticalityDiagnostics *release_CriticalityDiagnostics();
    void set_CriticalityDiagnostics(CriticalityDiagnostics *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __shared33   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef HandoverCancelAcknowledgeIEs_Value value;

    __shared33();
    __shared33(const __shared33 &);
    __shared33(id, criticality, const value &);

    __shared33 & operator = (const __shared33 &);
    int operator == (const __shared33 &) const;
    int operator != (const __shared33 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC __seq29;

class OSS_PUBLIC E_RABToBeSetupListBearerSUReq : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq29 component;

    E_RABToBeSetupListBearerSUReq();
    E_RABToBeSetupListBearerSUReq(const E_RABToBeSetupListBearerSUReq &);
    ~E_RABToBeSetupListBearerSUReq();

    E_RABToBeSetupListBearerSUReq & operator = (const E_RABToBeSetupListBearerSUReq &);
    int operator == (const E_RABToBeSetupListBearerSUReq &) const;
    int operator != (const E_RABToBeSetupListBearerSUReq &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(E_RABToBeSetupListBearerSUReq *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, E_RABToBeSetupListBearerSUReq *);

    int remove_front();
    int remove_after(OssIndex);

    E_RABToBeSetupListBearerSUReq *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC E_RABSetupRequestIEs_Value : public OssConstrainedOpenType
{
public:
    E_RABSetupRequestIEs_Value();
    E_RABSetupRequestIEs_Value(const E_RABSetupRequestIEs_Value &);
    ~E_RABSetupRequestIEs_Value();
    E_RABSetupRequestIEs_Value & operator = (const E_RABSetupRequestIEs_Value &);
    int operator == (const E_RABSetupRequestIEs_Value &) const;
    int operator != (const E_RABSetupRequestIEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    MME_UE_S1AP_ID *get_MME_UE_S1AP_ID();
    const MME_UE_S1AP_ID *get_MME_UE_S1AP_ID() const;
    void set_MME_UE_S1AP_ID(const MME_UE_S1AP_ID &);
    MME_UE_S1AP_ID *release_MME_UE_S1AP_ID();
    void set_MME_UE_S1AP_ID(MME_UE_S1AP_ID *);

    ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID();
    const ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID() const;
    void set_ENB_UE_S1AP_ID(const ENB_UE_S1AP_ID &);
    ENB_UE_S1AP_ID *release_ENB_UE_S1AP_ID();
    void set_ENB_UE_S1AP_ID(ENB_UE_S1AP_ID *);

    UEAggregateMaximumBitrate *get_UEAggregateMaximumBitrate();
    const UEAggregateMaximumBitrate *get_UEAggregateMaximumBitrate() const;
    void set_UEAggregateMaximumBitrate(const UEAggregateMaximumBitrate &);
    UEAggregateMaximumBitrate *release_UEAggregateMaximumBitrate();
    void set_UEAggregateMaximumBitrate(UEAggregateMaximumBitrate *);

    E_RABToBeSetupListBearerSUReq *get_E_RABToBeSetupListBearerSUReq();
    const E_RABToBeSetupListBearerSUReq *get_E_RABToBeSetupListBearerSUReq() const;
    void set_E_RABToBeSetupListBearerSUReq(const E_RABToBeSetupListBearerSUReq &);
    E_RABToBeSetupListBearerSUReq *release_E_RABToBeSetupListBearerSUReq();
    void set_E_RABToBeSetupListBearerSUReq(E_RABToBeSetupListBearerSUReq *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq28   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef E_RABSetupRequestIEs_Value value;

    __seq28();
    __seq28(const __seq28 &);
    __seq28(id, criticality, const value &);

    __seq28 & operator = (const __seq28 &);
    int operator == (const __seq28 &) const;
    int operator != (const __seq28 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC __shared9;

class OSS_PUBLIC __shared10 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __shared9 component;

    __shared10();
    __shared10(const __shared10 &);
    ~__shared10();

    __shared10 & operator = (const __shared10 &);
    int operator == (const __shared10 &) const;
    int operator != (const __shared10 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__shared10 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __shared10 *);

    int remove_front();
    int remove_after(OssIndex);

    __shared10 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC E_RABToBeSetupItemBearerSUReq   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_INT32 e_RAB_ID;
    typedef E_RABLevelQoSParameters e_RABlevelQoSParameters;
    typedef OssBitString transportLayerAddress;
    typedef OssString gTP_TEID;
    typedef OssString nAS_PDU;
    typedef __shared10 iE_Extensions;

    E_RABToBeSetupItemBearerSUReq();
    E_RABToBeSetupItemBearerSUReq(const E_RABToBeSetupItemBearerSUReq &);
    E_RABToBeSetupItemBearerSUReq(e_RAB_ID, const e_RABlevelQoSParameters &, const transportLayerAddress &, 
	const gTP_TEID &, const nAS_PDU &, const iE_Extensions &);
    E_RABToBeSetupItemBearerSUReq(e_RAB_ID, const e_RABlevelQoSParameters &, const transportLayerAddress &, 
	const gTP_TEID &, const nAS_PDU &);

    E_RABToBeSetupItemBearerSUReq & operator = (const E_RABToBeSetupItemBearerSUReq &);
    int operator == (const E_RABToBeSetupItemBearerSUReq &) const;
    int operator != (const E_RABToBeSetupItemBearerSUReq &) const;

    e_RAB_ID & get_e_RAB_ID();
    e_RAB_ID get_e_RAB_ID() const;
    void set_e_RAB_ID(e_RAB_ID);

    e_RABlevelQoSParameters & get_e_RABlevelQoSParameters();
    const e_RABlevelQoSParameters & get_e_RABlevelQoSParameters() const;
    void set_e_RABlevelQoSParameters(const e_RABlevelQoSParameters &);

    transportLayerAddress & get_transportLayerAddress();
    const transportLayerAddress & get_transportLayerAddress() const;
    void set_transportLayerAddress(const transportLayerAddress &);

    gTP_TEID & get_gTP_TEID();
    const gTP_TEID & get_gTP_TEID() const;
    void set_gTP_TEID(const gTP_TEID &);

    nAS_PDU & get_nAS_PDU();
    const nAS_PDU & get_nAS_PDU() const;
    void set_nAS_PDU(const nAS_PDU &);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    e_RAB_ID e_RAB_ID_field;
    e_RABlevelQoSParameters e_RABlevelQoSParameters_field;
    transportLayerAddress transportLayerAddress_field;
    gTP_TEID gTP_TEID_field;
    nAS_PDU nAS_PDU_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC E_RABToBeSetupItemBearerSUReqIEs_Value : public OssConstrainedOpenType
{
public:
    E_RABToBeSetupItemBearerSUReqIEs_Value();
    E_RABToBeSetupItemBearerSUReqIEs_Value(const E_RABToBeSetupItemBearerSUReqIEs_Value &);
    ~E_RABToBeSetupItemBearerSUReqIEs_Value();
    E_RABToBeSetupItemBearerSUReqIEs_Value & operator = (const E_RABToBeSetupItemBearerSUReqIEs_Value &);
    int operator == (const E_RABToBeSetupItemBearerSUReqIEs_Value &) const;
    int operator != (const E_RABToBeSetupItemBearerSUReqIEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    E_RABToBeSetupItemBearerSUReq *get_E_RABToBeSetupItemBearerSUReq();
    const E_RABToBeSetupItemBearerSUReq *get_E_RABToBeSetupItemBearerSUReq() const;
    void set_E_RABToBeSetupItemBearerSUReq(const E_RABToBeSetupItemBearerSUReq &);
    E_RABToBeSetupItemBearerSUReq *release_E_RABToBeSetupItemBearerSUReq();
    void set_E_RABToBeSetupItemBearerSUReq(E_RABToBeSetupItemBearerSUReq *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq29   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef E_RABToBeSetupItemBearerSUReqIEs_Value value;

    __seq29();
    __seq29(const __seq29 &);
    __seq29(id, criticality, const value &);

    __seq29 & operator = (const __seq29 &);
    int operator == (const __seq29 &) const;
    int operator != (const __seq29 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC E_RABToBeSetupItemBearerSUReqExtIEs_Extension : public OssConstrainedOpenType
{
public:
    E_RABToBeSetupItemBearerSUReqExtIEs_Extension();
    E_RABToBeSetupItemBearerSUReqExtIEs_Extension(const E_RABToBeSetupItemBearerSUReqExtIEs_Extension &);
    ~E_RABToBeSetupItemBearerSUReqExtIEs_Extension();
    E_RABToBeSetupItemBearerSUReqExtIEs_Extension & operator = (const E_RABToBeSetupItemBearerSUReqExtIEs_Extension &);
    int operator == (const E_RABToBeSetupItemBearerSUReqExtIEs_Extension &) const;
    int operator != (const E_RABToBeSetupItemBearerSUReqExtIEs_Extension &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    Correlation_ID *get_Correlation_ID();
    const Correlation_ID *get_Correlation_ID() const;
    void set_Correlation_ID(const Correlation_ID &);
    Correlation_ID *release_Correlation_ID();
    void set_Correlation_ID(Correlation_ID *);

    BearerType *get_BearerType();
    const BearerType *get_BearerType() const;
    void set_BearerType(const BearerType &);
    BearerType *release_BearerType();
    void set_BearerType(BearerType *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __shared9   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef E_RABToBeSetupItemBearerSUReqExtIEs_Extension extensionValue;

    __shared9();
    __shared9(const __shared9 &);
    __shared9(id, criticality, const extensionValue &);

    __shared9 & operator = (const __shared9 &);
    int operator == (const __shared9 &) const;
    int operator != (const __shared9 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    extensionValue & get_extensionValue();
    const extensionValue & get_extensionValue() const;
    void set_extensionValue(const extensionValue &);
private:
    id id_field;
    criticality criticality_field;
    extensionValue extensionValue_field;
};

class OSS_PUBLIC __seq32;

class OSS_PUBLIC E_RABSetupListBearerSURes : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq32 component;

    E_RABSetupListBearerSURes();
    E_RABSetupListBearerSURes(const E_RABSetupListBearerSURes &);
    ~E_RABSetupListBearerSURes();

    E_RABSetupListBearerSURes & operator = (const E_RABSetupListBearerSURes &);
    int operator == (const E_RABSetupListBearerSURes &) const;
    int operator != (const E_RABSetupListBearerSURes &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(E_RABSetupListBearerSURes *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, E_RABSetupListBearerSURes *);

    int remove_front();
    int remove_after(OssIndex);

    E_RABSetupListBearerSURes *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC E_RABSetupResponseIEs_Value : public OssConstrainedOpenType
{
public:
    E_RABSetupResponseIEs_Value();
    E_RABSetupResponseIEs_Value(const E_RABSetupResponseIEs_Value &);
    ~E_RABSetupResponseIEs_Value();
    E_RABSetupResponseIEs_Value & operator = (const E_RABSetupResponseIEs_Value &);
    int operator == (const E_RABSetupResponseIEs_Value &) const;
    int operator != (const E_RABSetupResponseIEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    MME_UE_S1AP_ID *get_MME_UE_S1AP_ID();
    const MME_UE_S1AP_ID *get_MME_UE_S1AP_ID() const;
    void set_MME_UE_S1AP_ID(const MME_UE_S1AP_ID &);
    MME_UE_S1AP_ID *release_MME_UE_S1AP_ID();
    void set_MME_UE_S1AP_ID(MME_UE_S1AP_ID *);

    ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID();
    const ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID() const;
    void set_ENB_UE_S1AP_ID(const ENB_UE_S1AP_ID &);
    ENB_UE_S1AP_ID *release_ENB_UE_S1AP_ID();
    void set_ENB_UE_S1AP_ID(ENB_UE_S1AP_ID *);

    E_RABSetupListBearerSURes *get_E_RABSetupListBearerSURes();
    const E_RABSetupListBearerSURes *get_E_RABSetupListBearerSURes() const;
    void set_E_RABSetupListBearerSURes(const E_RABSetupListBearerSURes &);
    E_RABSetupListBearerSURes *release_E_RABSetupListBearerSURes();
    void set_E_RABSetupListBearerSURes(E_RABSetupListBearerSURes *);

    E_RABList *get_E_RABList();
    const E_RABList *get_E_RABList() const;
    void set_E_RABList(const E_RABList &);
    E_RABList *release_E_RABList();
    void set_E_RABList(E_RABList *);

    CriticalityDiagnostics *get_CriticalityDiagnostics();
    const CriticalityDiagnostics *get_CriticalityDiagnostics() const;
    void set_CriticalityDiagnostics(const CriticalityDiagnostics &);
    CriticalityDiagnostics *release_CriticalityDiagnostics();
    void set_CriticalityDiagnostics(CriticalityDiagnostics *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq31   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef E_RABSetupResponseIEs_Value value;

    __seq31();
    __seq31(const __seq31 &);
    __seq31(id, criticality, const value &);

    __seq31 & operator = (const __seq31 &);
    int operator == (const __seq31 &) const;
    int operator != (const __seq31 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

typedef __shared8 E_RABSetupItemBearerSURes;

class OSS_PUBLIC E_RABSetupItemBearerSUResIEs_Value : public OssConstrainedOpenType
{
public:
    E_RABSetupItemBearerSUResIEs_Value();
    E_RABSetupItemBearerSUResIEs_Value(const E_RABSetupItemBearerSUResIEs_Value &);
    ~E_RABSetupItemBearerSUResIEs_Value();
    E_RABSetupItemBearerSUResIEs_Value & operator = (const E_RABSetupItemBearerSUResIEs_Value &);
    int operator == (const E_RABSetupItemBearerSUResIEs_Value &) const;
    int operator != (const E_RABSetupItemBearerSUResIEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    __shared8 *get_E_RABSetupItemBearerSURes();
    const __shared8 *get_E_RABSetupItemBearerSURes() const;
    void set_E_RABSetupItemBearerSURes(const __shared8 &);
    __shared8 *release_E_RABSetupItemBearerSURes();
    void set_E_RABSetupItemBearerSURes(__shared8 *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq32   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef E_RABSetupItemBearerSUResIEs_Value value;

    __seq32();
    __seq32(const __seq32 &);
    __seq32(id, criticality, const value &);

    __seq32 & operator = (const __seq32 &);
    int operator == (const __seq32 &) const;
    int operator != (const __seq32 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC __seq35;

class OSS_PUBLIC E_RABToBeModifiedListBearerModReq : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq35 component;

    E_RABToBeModifiedListBearerModReq();
    E_RABToBeModifiedListBearerModReq(const E_RABToBeModifiedListBearerModReq &);
    ~E_RABToBeModifiedListBearerModReq();

    E_RABToBeModifiedListBearerModReq & operator = (const E_RABToBeModifiedListBearerModReq &);
    int operator == (const E_RABToBeModifiedListBearerModReq &) const;
    int operator != (const E_RABToBeModifiedListBearerModReq &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(E_RABToBeModifiedListBearerModReq *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, E_RABToBeModifiedListBearerModReq *);

    int remove_front();
    int remove_after(OssIndex);

    E_RABToBeModifiedListBearerModReq *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC E_RABModifyRequestIEs_Value : public OssConstrainedOpenType
{
public:
    E_RABModifyRequestIEs_Value();
    E_RABModifyRequestIEs_Value(const E_RABModifyRequestIEs_Value &);
    ~E_RABModifyRequestIEs_Value();
    E_RABModifyRequestIEs_Value & operator = (const E_RABModifyRequestIEs_Value &);
    int operator == (const E_RABModifyRequestIEs_Value &) const;
    int operator != (const E_RABModifyRequestIEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    MME_UE_S1AP_ID *get_MME_UE_S1AP_ID();
    const MME_UE_S1AP_ID *get_MME_UE_S1AP_ID() const;
    void set_MME_UE_S1AP_ID(const MME_UE_S1AP_ID &);
    MME_UE_S1AP_ID *release_MME_UE_S1AP_ID();
    void set_MME_UE_S1AP_ID(MME_UE_S1AP_ID *);

    ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID();
    const ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID() const;
    void set_ENB_UE_S1AP_ID(const ENB_UE_S1AP_ID &);
    ENB_UE_S1AP_ID *release_ENB_UE_S1AP_ID();
    void set_ENB_UE_S1AP_ID(ENB_UE_S1AP_ID *);

    UEAggregateMaximumBitrate *get_UEAggregateMaximumBitrate();
    const UEAggregateMaximumBitrate *get_UEAggregateMaximumBitrate() const;
    void set_UEAggregateMaximumBitrate(const UEAggregateMaximumBitrate &);
    UEAggregateMaximumBitrate *release_UEAggregateMaximumBitrate();
    void set_UEAggregateMaximumBitrate(UEAggregateMaximumBitrate *);

    E_RABToBeModifiedListBearerModReq *get_E_RABToBeModifiedListBearerModReq();
    const E_RABToBeModifiedListBearerModReq *get_E_RABToBeModifiedListBearerModReq() const;
    void set_E_RABToBeModifiedListBearerModReq(const E_RABToBeModifiedListBearerModReq &);
    E_RABToBeModifiedListBearerModReq *release_E_RABToBeModifiedListBearerModReq();
    void set_E_RABToBeModifiedListBearerModReq(E_RABToBeModifiedListBearerModReq *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq34   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef E_RABModifyRequestIEs_Value value;

    __seq34();
    __seq34(const __seq34 &);
    __seq34(id, criticality, const value &);

    __seq34 & operator = (const __seq34 &);
    int operator == (const __seq34 &) const;
    int operator != (const __seq34 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC __seq36;

class OSS_PUBLIC __seqof27 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq36 component;

    __seqof27();
    __seqof27(const __seqof27 &);
    ~__seqof27();

    __seqof27 & operator = (const __seqof27 &);
    int operator == (const __seqof27 &) const;
    int operator != (const __seqof27 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof27 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof27 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof27 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC E_RABToBeModifiedItemBearerModReq   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_INT32 e_RAB_ID;
    typedef E_RABLevelQoSParameters e_RABLevelQoSParameters;
    typedef OssString nAS_PDU;
    typedef __seqof27 iE_Extensions;

    E_RABToBeModifiedItemBearerModReq();
    E_RABToBeModifiedItemBearerModReq(const E_RABToBeModifiedItemBearerModReq &);
    E_RABToBeModifiedItemBearerModReq(e_RAB_ID, const e_RABLevelQoSParameters &, 
	const nAS_PDU &, const iE_Extensions &);
    E_RABToBeModifiedItemBearerModReq(e_RAB_ID, const e_RABLevelQoSParameters &, 
	const nAS_PDU &);

    E_RABToBeModifiedItemBearerModReq & operator = (const E_RABToBeModifiedItemBearerModReq &);
    int operator == (const E_RABToBeModifiedItemBearerModReq &) const;
    int operator != (const E_RABToBeModifiedItemBearerModReq &) const;

    e_RAB_ID & get_e_RAB_ID();
    e_RAB_ID get_e_RAB_ID() const;
    void set_e_RAB_ID(e_RAB_ID);

    e_RABLevelQoSParameters & get_e_RABLevelQoSParameters();
    const e_RABLevelQoSParameters & get_e_RABLevelQoSParameters() const;
    void set_e_RABLevelQoSParameters(const e_RABLevelQoSParameters &);

    nAS_PDU & get_nAS_PDU();
    const nAS_PDU & get_nAS_PDU() const;
    void set_nAS_PDU(const nAS_PDU &);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    e_RAB_ID e_RAB_ID_field;
    e_RABLevelQoSParameters e_RABLevelQoSParameters_field;
    nAS_PDU nAS_PDU_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC E_RABToBeModifiedItemBearerModReqIEs_Value : public OssConstrainedOpenType
{
public:
    E_RABToBeModifiedItemBearerModReqIEs_Value();
    E_RABToBeModifiedItemBearerModReqIEs_Value(const E_RABToBeModifiedItemBearerModReqIEs_Value &);
    ~E_RABToBeModifiedItemBearerModReqIEs_Value();
    E_RABToBeModifiedItemBearerModReqIEs_Value & operator = (const E_RABToBeModifiedItemBearerModReqIEs_Value &);
    int operator == (const E_RABToBeModifiedItemBearerModReqIEs_Value &) const;
    int operator != (const E_RABToBeModifiedItemBearerModReqIEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    E_RABToBeModifiedItemBearerModReq *get_E_RABToBeModifiedItemBearerModReq();
    const E_RABToBeModifiedItemBearerModReq *get_E_RABToBeModifiedItemBearerModReq() const;
    void set_E_RABToBeModifiedItemBearerModReq(const E_RABToBeModifiedItemBearerModReq &);
    E_RABToBeModifiedItemBearerModReq *release_E_RABToBeModifiedItemBearerModReq();
    void set_E_RABToBeModifiedItemBearerModReq(E_RABToBeModifiedItemBearerModReq *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq35   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef E_RABToBeModifiedItemBearerModReqIEs_Value value;

    __seq35();
    __seq35(const __seq35 &);
    __seq35(id, criticality, const value &);

    __seq35 & operator = (const __seq35 &);
    int operator == (const __seq35 &) const;
    int operator != (const __seq35 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC TransportInformation   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OssBitString transportLayerAddress;
    typedef OssString uL_GTP_TEID;

    TransportInformation();
    TransportInformation(const TransportInformation &);
    TransportInformation(const transportLayerAddress &, const uL_GTP_TEID &);

    TransportInformation & operator = (const TransportInformation &);
    int operator == (const TransportInformation &) const;
    int operator != (const TransportInformation &) const;

    transportLayerAddress & get_transportLayerAddress();
    const transportLayerAddress & get_transportLayerAddress() const;
    void set_transportLayerAddress(const transportLayerAddress &);

    uL_GTP_TEID & get_uL_GTP_TEID();
    const uL_GTP_TEID & get_uL_GTP_TEID() const;
    void set_uL_GTP_TEID(const uL_GTP_TEID &);
private:
    transportLayerAddress transportLayerAddress_field;
    uL_GTP_TEID uL_GTP_TEID_field;
};

class OSS_PUBLIC E_RABToBeModifyItemBearerModReqExtIEs_Extension : public OssConstrainedOpenType
{
public:
    E_RABToBeModifyItemBearerModReqExtIEs_Extension();
    E_RABToBeModifyItemBearerModReqExtIEs_Extension(const E_RABToBeModifyItemBearerModReqExtIEs_Extension &);
    ~E_RABToBeModifyItemBearerModReqExtIEs_Extension();
    E_RABToBeModifyItemBearerModReqExtIEs_Extension & operator = (const E_RABToBeModifyItemBearerModReqExtIEs_Extension &);
    int operator == (const E_RABToBeModifyItemBearerModReqExtIEs_Extension &) const;
    int operator != (const E_RABToBeModifyItemBearerModReqExtIEs_Extension &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    TransportInformation *get_TransportInformation();
    const TransportInformation *get_TransportInformation() const;
    void set_TransportInformation(const TransportInformation &);
    TransportInformation *release_TransportInformation();
    void set_TransportInformation(TransportInformation *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq36   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef E_RABToBeModifyItemBearerModReqExtIEs_Extension extensionValue;

    __seq36();
    __seq36(const __seq36 &);
    __seq36(id, criticality, const extensionValue &);

    __seq36 & operator = (const __seq36 &);
    int operator == (const __seq36 &) const;
    int operator != (const __seq36 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    extensionValue & get_extensionValue();
    const extensionValue & get_extensionValue() const;
    void set_extensionValue(const extensionValue &);
private:
    id id_field;
    criticality criticality_field;
    extensionValue extensionValue_field;
};

class OSS_PUBLIC __seq38;

class OSS_PUBLIC E_RABModifyListBearerModRes : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq38 component;

    E_RABModifyListBearerModRes();
    E_RABModifyListBearerModRes(const E_RABModifyListBearerModRes &);
    ~E_RABModifyListBearerModRes();

    E_RABModifyListBearerModRes & operator = (const E_RABModifyListBearerModRes &);
    int operator == (const E_RABModifyListBearerModRes &) const;
    int operator != (const E_RABModifyListBearerModRes &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(E_RABModifyListBearerModRes *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, E_RABModifyListBearerModRes *);

    int remove_front();
    int remove_after(OssIndex);

    E_RABModifyListBearerModRes *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC E_RABModifyResponseIEs_Value : public OssConstrainedOpenType
{
public:
    E_RABModifyResponseIEs_Value();
    E_RABModifyResponseIEs_Value(const E_RABModifyResponseIEs_Value &);
    ~E_RABModifyResponseIEs_Value();
    E_RABModifyResponseIEs_Value & operator = (const E_RABModifyResponseIEs_Value &);
    int operator == (const E_RABModifyResponseIEs_Value &) const;
    int operator != (const E_RABModifyResponseIEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    MME_UE_S1AP_ID *get_MME_UE_S1AP_ID();
    const MME_UE_S1AP_ID *get_MME_UE_S1AP_ID() const;
    void set_MME_UE_S1AP_ID(const MME_UE_S1AP_ID &);
    MME_UE_S1AP_ID *release_MME_UE_S1AP_ID();
    void set_MME_UE_S1AP_ID(MME_UE_S1AP_ID *);

    ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID();
    const ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID() const;
    void set_ENB_UE_S1AP_ID(const ENB_UE_S1AP_ID &);
    ENB_UE_S1AP_ID *release_ENB_UE_S1AP_ID();
    void set_ENB_UE_S1AP_ID(ENB_UE_S1AP_ID *);

    E_RABModifyListBearerModRes *get_E_RABModifyListBearerModRes();
    const E_RABModifyListBearerModRes *get_E_RABModifyListBearerModRes() const;
    void set_E_RABModifyListBearerModRes(const E_RABModifyListBearerModRes &);
    E_RABModifyListBearerModRes *release_E_RABModifyListBearerModRes();
    void set_E_RABModifyListBearerModRes(E_RABModifyListBearerModRes *);

    E_RABList *get_E_RABList();
    const E_RABList *get_E_RABList() const;
    void set_E_RABList(const E_RABList &);
    E_RABList *release_E_RABList();
    void set_E_RABList(E_RABList *);

    CriticalityDiagnostics *get_CriticalityDiagnostics();
    const CriticalityDiagnostics *get_CriticalityDiagnostics() const;
    void set_CriticalityDiagnostics(const CriticalityDiagnostics &);
    CriticalityDiagnostics *release_CriticalityDiagnostics();
    void set_CriticalityDiagnostics(CriticalityDiagnostics *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq37   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef E_RABModifyResponseIEs_Value value;

    __seq37();
    __seq37(const __seq37 &);
    __seq37(id, criticality, const value &);

    __seq37 & operator = (const __seq37 &);
    int operator == (const __seq37 &) const;
    int operator != (const __seq37 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC __shared32   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_INT32 e_RAB_ID;
    typedef __shared2 iE_Extensions;

    __shared32();
    __shared32(const __shared32 &);
    __shared32(e_RAB_ID, const iE_Extensions &);
    __shared32(e_RAB_ID);

    __shared32 & operator = (const __shared32 &);
    int operator == (const __shared32 &) const;
    int operator != (const __shared32 &) const;

    e_RAB_ID & get_e_RAB_ID();
    e_RAB_ID get_e_RAB_ID() const;
    void set_e_RAB_ID(e_RAB_ID);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    e_RAB_ID e_RAB_ID_field;
    iE_Extensions iE_Extensions_field;
};

typedef __shared32 E_RABModifyItemBearerModRes;

class OSS_PUBLIC E_RABModifyItemBearerModResIEs_Value : public OssConstrainedOpenType
{
public:
    E_RABModifyItemBearerModResIEs_Value();
    E_RABModifyItemBearerModResIEs_Value(const E_RABModifyItemBearerModResIEs_Value &);
    ~E_RABModifyItemBearerModResIEs_Value();
    E_RABModifyItemBearerModResIEs_Value & operator = (const E_RABModifyItemBearerModResIEs_Value &);
    int operator == (const E_RABModifyItemBearerModResIEs_Value &) const;
    int operator != (const E_RABModifyItemBearerModResIEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    __shared32 *get_E_RABModifyItemBearerModRes();
    const __shared32 *get_E_RABModifyItemBearerModRes() const;
    void set_E_RABModifyItemBearerModRes(const __shared32 &);
    __shared32 *release_E_RABModifyItemBearerModRes();
    void set_E_RABModifyItemBearerModRes(__shared32 *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq38   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef E_RABModifyItemBearerModResIEs_Value value;

    __seq38();
    __seq38(const __seq38 &);
    __seq38(id, criticality, const value &);

    __seq38 & operator = (const __seq38 &);
    int operator == (const __seq38 &) const;
    int operator != (const __seq38 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC E_RABReleaseCommandIEs_Value : public OssConstrainedOpenType
{
public:
    E_RABReleaseCommandIEs_Value();
    E_RABReleaseCommandIEs_Value(const E_RABReleaseCommandIEs_Value &);
    ~E_RABReleaseCommandIEs_Value();
    E_RABReleaseCommandIEs_Value & operator = (const E_RABReleaseCommandIEs_Value &);
    int operator == (const E_RABReleaseCommandIEs_Value &) const;
    int operator != (const E_RABReleaseCommandIEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    MME_UE_S1AP_ID *get_MME_UE_S1AP_ID();
    const MME_UE_S1AP_ID *get_MME_UE_S1AP_ID() const;
    void set_MME_UE_S1AP_ID(const MME_UE_S1AP_ID &);
    MME_UE_S1AP_ID *release_MME_UE_S1AP_ID();
    void set_MME_UE_S1AP_ID(MME_UE_S1AP_ID *);

    ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID();
    const ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID() const;
    void set_ENB_UE_S1AP_ID(const ENB_UE_S1AP_ID &);
    ENB_UE_S1AP_ID *release_ENB_UE_S1AP_ID();
    void set_ENB_UE_S1AP_ID(ENB_UE_S1AP_ID *);

    UEAggregateMaximumBitrate *get_UEAggregateMaximumBitrate();
    const UEAggregateMaximumBitrate *get_UEAggregateMaximumBitrate() const;
    void set_UEAggregateMaximumBitrate(const UEAggregateMaximumBitrate &);
    UEAggregateMaximumBitrate *release_UEAggregateMaximumBitrate();
    void set_UEAggregateMaximumBitrate(UEAggregateMaximumBitrate *);

    E_RABList *get_E_RABList();
    const E_RABList *get_E_RABList() const;
    void set_E_RABList(const E_RABList &);
    E_RABList *release_E_RABList();
    void set_E_RABList(E_RABList *);

    NAS_PDU *get_NAS_PDU();
    const NAS_PDU *get_NAS_PDU() const;
    void set_NAS_PDU(const NAS_PDU &);
    NAS_PDU *release_NAS_PDU();
    void set_NAS_PDU(NAS_PDU *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq40   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef E_RABReleaseCommandIEs_Value value;

    __seq40();
    __seq40(const __seq40 &);
    __seq40(id, criticality, const value &);

    __seq40 & operator = (const __seq40 &);
    int operator == (const __seq40 &) const;
    int operator != (const __seq40 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC __seq42;

class OSS_PUBLIC E_RABReleaseListBearerRelComp : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq42 component;

    E_RABReleaseListBearerRelComp();
    E_RABReleaseListBearerRelComp(const E_RABReleaseListBearerRelComp &);
    ~E_RABReleaseListBearerRelComp();

    E_RABReleaseListBearerRelComp & operator = (const E_RABReleaseListBearerRelComp &);
    int operator == (const E_RABReleaseListBearerRelComp &) const;
    int operator != (const E_RABReleaseListBearerRelComp &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(E_RABReleaseListBearerRelComp *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, E_RABReleaseListBearerRelComp *);

    int remove_front();
    int remove_after(OssIndex);

    E_RABReleaseListBearerRelComp *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC UserLocationInformation   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef EUTRAN_CGI eutran_cgi;
    typedef TAI tai;
    typedef __shared2 iE_Extensions;

    UserLocationInformation();
    UserLocationInformation(const UserLocationInformation &);
    UserLocationInformation(const eutran_cgi &, const tai &, const iE_Extensions &);
    UserLocationInformation(const eutran_cgi &, const tai &);

    UserLocationInformation & operator = (const UserLocationInformation &);
    int operator == (const UserLocationInformation &) const;
    int operator != (const UserLocationInformation &) const;

    eutran_cgi & get_eutran_cgi();
    const eutran_cgi & get_eutran_cgi() const;
    void set_eutran_cgi(const eutran_cgi &);

    tai & get_tai();
    const tai & get_tai() const;
    void set_tai(const tai &);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    eutran_cgi eutran_cgi_field;
    tai tai_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC E_RABReleaseResponseIEs_Value : public OssConstrainedOpenType
{
public:
    E_RABReleaseResponseIEs_Value();
    E_RABReleaseResponseIEs_Value(const E_RABReleaseResponseIEs_Value &);
    ~E_RABReleaseResponseIEs_Value();
    E_RABReleaseResponseIEs_Value & operator = (const E_RABReleaseResponseIEs_Value &);
    int operator == (const E_RABReleaseResponseIEs_Value &) const;
    int operator != (const E_RABReleaseResponseIEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    MME_UE_S1AP_ID *get_MME_UE_S1AP_ID();
    const MME_UE_S1AP_ID *get_MME_UE_S1AP_ID() const;
    void set_MME_UE_S1AP_ID(const MME_UE_S1AP_ID &);
    MME_UE_S1AP_ID *release_MME_UE_S1AP_ID();
    void set_MME_UE_S1AP_ID(MME_UE_S1AP_ID *);

    ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID();
    const ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID() const;
    void set_ENB_UE_S1AP_ID(const ENB_UE_S1AP_ID &);
    ENB_UE_S1AP_ID *release_ENB_UE_S1AP_ID();
    void set_ENB_UE_S1AP_ID(ENB_UE_S1AP_ID *);

    E_RABReleaseListBearerRelComp *get_E_RABReleaseListBearerRelComp();
    const E_RABReleaseListBearerRelComp *get_E_RABReleaseListBearerRelComp() const;
    void set_E_RABReleaseListBearerRelComp(const E_RABReleaseListBearerRelComp &);
    E_RABReleaseListBearerRelComp *release_E_RABReleaseListBearerRelComp();
    void set_E_RABReleaseListBearerRelComp(E_RABReleaseListBearerRelComp *);

    E_RABList *get_E_RABList();
    const E_RABList *get_E_RABList() const;
    void set_E_RABList(const E_RABList &);
    E_RABList *release_E_RABList();
    void set_E_RABList(E_RABList *);

    CriticalityDiagnostics *get_CriticalityDiagnostics();
    const CriticalityDiagnostics *get_CriticalityDiagnostics() const;
    void set_CriticalityDiagnostics(const CriticalityDiagnostics &);
    CriticalityDiagnostics *release_CriticalityDiagnostics();
    void set_CriticalityDiagnostics(CriticalityDiagnostics *);

    UserLocationInformation *get_UserLocationInformation();
    const UserLocationInformation *get_UserLocationInformation() const;
    void set_UserLocationInformation(const UserLocationInformation &);
    UserLocationInformation *release_UserLocationInformation();
    void set_UserLocationInformation(UserLocationInformation *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq41   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef E_RABReleaseResponseIEs_Value value;

    __seq41();
    __seq41(const __seq41 &);
    __seq41(id, criticality, const value &);

    __seq41 & operator = (const __seq41 &);
    int operator == (const __seq41 &) const;
    int operator != (const __seq41 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

typedef __shared32 E_RABReleaseItemBearerRelComp;

class OSS_PUBLIC E_RABReleaseItemBearerRelCompIEs_Value : public OssConstrainedOpenType
{
public:
    E_RABReleaseItemBearerRelCompIEs_Value();
    E_RABReleaseItemBearerRelCompIEs_Value(const E_RABReleaseItemBearerRelCompIEs_Value &);
    ~E_RABReleaseItemBearerRelCompIEs_Value();
    E_RABReleaseItemBearerRelCompIEs_Value & operator = (const E_RABReleaseItemBearerRelCompIEs_Value &);
    int operator == (const E_RABReleaseItemBearerRelCompIEs_Value &) const;
    int operator != (const E_RABReleaseItemBearerRelCompIEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    __shared32 *get_E_RABReleaseItemBearerRelComp();
    const __shared32 *get_E_RABReleaseItemBearerRelComp() const;
    void set_E_RABReleaseItemBearerRelComp(const __shared32 &);
    __shared32 *release_E_RABReleaseItemBearerRelComp();
    void set_E_RABReleaseItemBearerRelComp(__shared32 *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq42   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef E_RABReleaseItemBearerRelCompIEs_Value value;

    __seq42();
    __seq42(const __seq42 &);
    __seq42(id, criticality, const value &);

    __seq42 & operator = (const __seq42 &);
    int operator == (const __seq42 &) const;
    int operator != (const __seq42 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC E_RABReleaseIndicationIEs_Value : public OssConstrainedOpenType
{
public:
    E_RABReleaseIndicationIEs_Value();
    E_RABReleaseIndicationIEs_Value(const E_RABReleaseIndicationIEs_Value &);
    ~E_RABReleaseIndicationIEs_Value();
    E_RABReleaseIndicationIEs_Value & operator = (const E_RABReleaseIndicationIEs_Value &);
    int operator == (const E_RABReleaseIndicationIEs_Value &) const;
    int operator != (const E_RABReleaseIndicationIEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    MME_UE_S1AP_ID *get_MME_UE_S1AP_ID();
    const MME_UE_S1AP_ID *get_MME_UE_S1AP_ID() const;
    void set_MME_UE_S1AP_ID(const MME_UE_S1AP_ID &);
    MME_UE_S1AP_ID *release_MME_UE_S1AP_ID();
    void set_MME_UE_S1AP_ID(MME_UE_S1AP_ID *);

    ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID();
    const ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID() const;
    void set_ENB_UE_S1AP_ID(const ENB_UE_S1AP_ID &);
    ENB_UE_S1AP_ID *release_ENB_UE_S1AP_ID();
    void set_ENB_UE_S1AP_ID(ENB_UE_S1AP_ID *);

    E_RABList *get_E_RABList();
    const E_RABList *get_E_RABList() const;
    void set_E_RABList(const E_RABList &);
    E_RABList *release_E_RABList();
    void set_E_RABList(E_RABList *);

    UserLocationInformation *get_UserLocationInformation();
    const UserLocationInformation *get_UserLocationInformation() const;
    void set_UserLocationInformation(const UserLocationInformation &);
    UserLocationInformation *release_UserLocationInformation();
    void set_UserLocationInformation(UserLocationInformation *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq44   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef E_RABReleaseIndicationIEs_Value value;

    __seq44();
    __seq44(const __seq44 &);
    __seq44(id, criticality, const value &);

    __seq44 & operator = (const __seq44 &);
    int operator == (const __seq44 &) const;
    int operator != (const __seq44 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC __seq46;

class OSS_PUBLIC E_RABToBeSetupListCtxtSUReq : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq46 component;

    E_RABToBeSetupListCtxtSUReq();
    E_RABToBeSetupListCtxtSUReq(const E_RABToBeSetupListCtxtSUReq &);
    ~E_RABToBeSetupListCtxtSUReq();

    E_RABToBeSetupListCtxtSUReq & operator = (const E_RABToBeSetupListCtxtSUReq &);
    int operator == (const E_RABToBeSetupListCtxtSUReq &) const;
    int operator != (const E_RABToBeSetupListCtxtSUReq &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(E_RABToBeSetupListCtxtSUReq *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, E_RABToBeSetupListCtxtSUReq *);

    int remove_front();
    int remove_after(OssIndex);

    E_RABToBeSetupListCtxtSUReq *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC InitialContextSetupRequestIEs_Value : public OssConstrainedOpenType
{
public:
    InitialContextSetupRequestIEs_Value();
    InitialContextSetupRequestIEs_Value(const InitialContextSetupRequestIEs_Value &);
    ~InitialContextSetupRequestIEs_Value();
    InitialContextSetupRequestIEs_Value & operator = (const InitialContextSetupRequestIEs_Value &);
    int operator == (const InitialContextSetupRequestIEs_Value &) const;
    int operator != (const InitialContextSetupRequestIEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    MME_UE_S1AP_ID *get_MME_UE_S1AP_ID();
    const MME_UE_S1AP_ID *get_MME_UE_S1AP_ID() const;
    void set_MME_UE_S1AP_ID(const MME_UE_S1AP_ID &);
    MME_UE_S1AP_ID *release_MME_UE_S1AP_ID();
    void set_MME_UE_S1AP_ID(MME_UE_S1AP_ID *);

    ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID();
    const ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID() const;
    void set_ENB_UE_S1AP_ID(const ENB_UE_S1AP_ID &);
    ENB_UE_S1AP_ID *release_ENB_UE_S1AP_ID();
    void set_ENB_UE_S1AP_ID(ENB_UE_S1AP_ID *);

    UEAggregateMaximumBitrate *get_UEAggregateMaximumBitrate();
    const UEAggregateMaximumBitrate *get_UEAggregateMaximumBitrate() const;
    void set_UEAggregateMaximumBitrate(const UEAggregateMaximumBitrate &);
    UEAggregateMaximumBitrate *release_UEAggregateMaximumBitrate();
    void set_UEAggregateMaximumBitrate(UEAggregateMaximumBitrate *);

    E_RABToBeSetupListCtxtSUReq *get_E_RABToBeSetupListCtxtSUReq();
    const E_RABToBeSetupListCtxtSUReq *get_E_RABToBeSetupListCtxtSUReq() const;
    void set_E_RABToBeSetupListCtxtSUReq(const E_RABToBeSetupListCtxtSUReq &);
    E_RABToBeSetupListCtxtSUReq *release_E_RABToBeSetupListCtxtSUReq();
    void set_E_RABToBeSetupListCtxtSUReq(E_RABToBeSetupListCtxtSUReq *);

    UESecurityCapabilities *get_UESecurityCapabilities();
    const UESecurityCapabilities *get_UESecurityCapabilities() const;
    void set_UESecurityCapabilities(const UESecurityCapabilities &);
    UESecurityCapabilities *release_UESecurityCapabilities();
    void set_UESecurityCapabilities(UESecurityCapabilities *);

    SecurityKey *get_SecurityKey();
    const SecurityKey *get_SecurityKey() const;
    void set_SecurityKey(const SecurityKey &);
    SecurityKey *release_SecurityKey();
    void set_SecurityKey(SecurityKey *);

    TraceActivation *get_TraceActivation();
    const TraceActivation *get_TraceActivation() const;
    void set_TraceActivation(const TraceActivation &);
    TraceActivation *release_TraceActivation();
    void set_TraceActivation(TraceActivation *);

    HandoverRestrictionList *get_HandoverRestrictionList();
    const HandoverRestrictionList *get_HandoverRestrictionList() const;
    void set_HandoverRestrictionList(const HandoverRestrictionList &);
    HandoverRestrictionList *release_HandoverRestrictionList();
    void set_HandoverRestrictionList(HandoverRestrictionList *);

    UERadioCapability *get_UERadioCapability();
    const UERadioCapability *get_UERadioCapability() const;
    void set_UERadioCapability(const UERadioCapability &);
    UERadioCapability *release_UERadioCapability();
    void set_UERadioCapability(UERadioCapability *);

    SubscriberProfileIDforRFP *get_SubscriberProfileIDforRFP();
    const SubscriberProfileIDforRFP *get_SubscriberProfileIDforRFP() const;
    void set_SubscriberProfileIDforRFP(const SubscriberProfileIDforRFP &);
    SubscriberProfileIDforRFP *release_SubscriberProfileIDforRFP();
    void set_SubscriberProfileIDforRFP(SubscriberProfileIDforRFP *);

    CSFallbackIndicator *get_CSFallbackIndicator();
    const CSFallbackIndicator *get_CSFallbackIndicator() const;
    void set_CSFallbackIndicator(const CSFallbackIndicator &);
    CSFallbackIndicator *release_CSFallbackIndicator();
    void set_CSFallbackIndicator(CSFallbackIndicator *);

    SRVCCOperationPossible *get_SRVCCOperationPossible();
    const SRVCCOperationPossible *get_SRVCCOperationPossible() const;
    void set_SRVCCOperationPossible(const SRVCCOperationPossible &);
    SRVCCOperationPossible *release_SRVCCOperationPossible();
    void set_SRVCCOperationPossible(SRVCCOperationPossible *);

    CSGMembershipStatus *get_CSGMembershipStatus();
    const CSGMembershipStatus *get_CSGMembershipStatus() const;
    void set_CSGMembershipStatus(const CSGMembershipStatus &);
    CSGMembershipStatus *release_CSGMembershipStatus();
    void set_CSGMembershipStatus(CSGMembershipStatus *);

    LAI *get_LAI();
    const LAI *get_LAI() const;
    void set_LAI(const LAI &);
    LAI *release_LAI();
    void set_LAI(LAI *);

    GUMMEI *get_GUMMEI();
    const GUMMEI *get_GUMMEI() const;
    void set_GUMMEI(const GUMMEI &);
    GUMMEI *release_GUMMEI();
    void set_GUMMEI(GUMMEI *);

    ManagementBasedMDTAllowed *get_ManagementBasedMDTAllowed();
    const ManagementBasedMDTAllowed *get_ManagementBasedMDTAllowed() const;
    void set_ManagementBasedMDTAllowed(const ManagementBasedMDTAllowed &);
    ManagementBasedMDTAllowed *release_ManagementBasedMDTAllowed();
    void set_ManagementBasedMDTAllowed(ManagementBasedMDTAllowed *);

    __shared4 *get_MDTPLMNList();
    const __shared4 *get_MDTPLMNList() const;
    void set_MDTPLMNList(const __shared4 &);
    __shared4 *release_MDTPLMNList();
    void set_MDTPLMNList(__shared4 *);

    AdditionalCSFallbackIndicator *get_AdditionalCSFallbackIndicator();
    const AdditionalCSFallbackIndicator *get_AdditionalCSFallbackIndicator() const;
    void set_AdditionalCSFallbackIndicator(const AdditionalCSFallbackIndicator &);
    AdditionalCSFallbackIndicator *release_AdditionalCSFallbackIndicator();
    void set_AdditionalCSFallbackIndicator(AdditionalCSFallbackIndicator *);

    Masked_IMEISV *get_Masked_IMEISV();
    const Masked_IMEISV *get_Masked_IMEISV() const;
    void set_Masked_IMEISV(const Masked_IMEISV &);
    Masked_IMEISV *release_Masked_IMEISV();
    void set_Masked_IMEISV(Masked_IMEISV *);

    ExpectedUEBehaviour *get_ExpectedUEBehaviour();
    const ExpectedUEBehaviour *get_ExpectedUEBehaviour() const;
    void set_ExpectedUEBehaviour(const ExpectedUEBehaviour &);
    ExpectedUEBehaviour *release_ExpectedUEBehaviour();
    void set_ExpectedUEBehaviour(ExpectedUEBehaviour *);

    ProSeAuthorized *get_ProSeAuthorized();
    const ProSeAuthorized *get_ProSeAuthorized() const;
    void set_ProSeAuthorized(const ProSeAuthorized &);
    ProSeAuthorized *release_ProSeAuthorized();
    void set_ProSeAuthorized(ProSeAuthorized *);

    UEUserPlaneCIoTSupportIndicator *get_UEUserPlaneCIoTSupportIndicator();
    const UEUserPlaneCIoTSupportIndicator *get_UEUserPlaneCIoTSupportIndicator() const;
    void set_UEUserPlaneCIoTSupportIndicator(const UEUserPlaneCIoTSupportIndicator &);
    UEUserPlaneCIoTSupportIndicator *release_UEUserPlaneCIoTSupportIndicator();
    void set_UEUserPlaneCIoTSupportIndicator(UEUserPlaneCIoTSupportIndicator *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq45   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef InitialContextSetupRequestIEs_Value value;

    __seq45();
    __seq45(const __seq45 &);
    __seq45(id, criticality, const value &);

    __seq45 & operator = (const __seq45 &);
    int operator == (const __seq45 &) const;
    int operator != (const __seq45 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC E_RABToBeSetupItemCtxtSUReq   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_INT32 e_RAB_ID;
    typedef E_RABLevelQoSParameters e_RABlevelQoSParameters;
    typedef OssBitString transportLayerAddress;
    typedef OssString gTP_TEID;
    typedef OssString nAS_PDU;
    typedef __shared10 iE_Extensions;

    E_RABToBeSetupItemCtxtSUReq();
    E_RABToBeSetupItemCtxtSUReq(const E_RABToBeSetupItemCtxtSUReq &);
    E_RABToBeSetupItemCtxtSUReq(e_RAB_ID, const e_RABlevelQoSParameters &, const transportLayerAddress &, 
	const gTP_TEID &, const nAS_PDU &, const iE_Extensions &);
    E_RABToBeSetupItemCtxtSUReq(e_RAB_ID, const e_RABlevelQoSParameters &, const transportLayerAddress &, 
	const gTP_TEID &);

    E_RABToBeSetupItemCtxtSUReq & operator = (const E_RABToBeSetupItemCtxtSUReq &);
    int operator == (const E_RABToBeSetupItemCtxtSUReq &) const;
    int operator != (const E_RABToBeSetupItemCtxtSUReq &) const;

    e_RAB_ID & get_e_RAB_ID();
    e_RAB_ID get_e_RAB_ID() const;
    void set_e_RAB_ID(e_RAB_ID);

    e_RABlevelQoSParameters & get_e_RABlevelQoSParameters();
    const e_RABlevelQoSParameters & get_e_RABlevelQoSParameters() const;
    void set_e_RABlevelQoSParameters(const e_RABlevelQoSParameters &);

    transportLayerAddress & get_transportLayerAddress();
    const transportLayerAddress & get_transportLayerAddress() const;
    void set_transportLayerAddress(const transportLayerAddress &);

    gTP_TEID & get_gTP_TEID();
    const gTP_TEID & get_gTP_TEID() const;
    void set_gTP_TEID(const gTP_TEID &);

    nAS_PDU *get_nAS_PDU();
    const nAS_PDU *get_nAS_PDU() const;
    void set_nAS_PDU(const nAS_PDU &);
    int nAS_PDU_is_present() const;
    void omit_nAS_PDU();

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    e_RAB_ID e_RAB_ID_field;
    e_RABlevelQoSParameters e_RABlevelQoSParameters_field;
    transportLayerAddress transportLayerAddress_field;
    gTP_TEID gTP_TEID_field;
    nAS_PDU nAS_PDU_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC E_RABToBeSetupItemCtxtSUReqIEs_Value : public OssConstrainedOpenType
{
public:
    E_RABToBeSetupItemCtxtSUReqIEs_Value();
    E_RABToBeSetupItemCtxtSUReqIEs_Value(const E_RABToBeSetupItemCtxtSUReqIEs_Value &);
    ~E_RABToBeSetupItemCtxtSUReqIEs_Value();
    E_RABToBeSetupItemCtxtSUReqIEs_Value & operator = (const E_RABToBeSetupItemCtxtSUReqIEs_Value &);
    int operator == (const E_RABToBeSetupItemCtxtSUReqIEs_Value &) const;
    int operator != (const E_RABToBeSetupItemCtxtSUReqIEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    E_RABToBeSetupItemCtxtSUReq *get_E_RABToBeSetupItemCtxtSUReq();
    const E_RABToBeSetupItemCtxtSUReq *get_E_RABToBeSetupItemCtxtSUReq() const;
    void set_E_RABToBeSetupItemCtxtSUReq(const E_RABToBeSetupItemCtxtSUReq &);
    E_RABToBeSetupItemCtxtSUReq *release_E_RABToBeSetupItemCtxtSUReq();
    void set_E_RABToBeSetupItemCtxtSUReq(E_RABToBeSetupItemCtxtSUReq *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq46   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef E_RABToBeSetupItemCtxtSUReqIEs_Value value;

    __seq46();
    __seq46(const __seq46 &);
    __seq46(id, criticality, const value &);

    __seq46 & operator = (const __seq46 &);
    int operator == (const __seq46 &) const;
    int operator != (const __seq46 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC __seq49;

class OSS_PUBLIC E_RABSetupListCtxtSURes : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq49 component;

    E_RABSetupListCtxtSURes();
    E_RABSetupListCtxtSURes(const E_RABSetupListCtxtSURes &);
    ~E_RABSetupListCtxtSURes();

    E_RABSetupListCtxtSURes & operator = (const E_RABSetupListCtxtSURes &);
    int operator == (const E_RABSetupListCtxtSURes &) const;
    int operator != (const E_RABSetupListCtxtSURes &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(E_RABSetupListCtxtSURes *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, E_RABSetupListCtxtSURes *);

    int remove_front();
    int remove_after(OssIndex);

    E_RABSetupListCtxtSURes *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC InitialContextSetupResponseIEs_Value : public OssConstrainedOpenType
{
public:
    InitialContextSetupResponseIEs_Value();
    InitialContextSetupResponseIEs_Value(const InitialContextSetupResponseIEs_Value &);
    ~InitialContextSetupResponseIEs_Value();
    InitialContextSetupResponseIEs_Value & operator = (const InitialContextSetupResponseIEs_Value &);
    int operator == (const InitialContextSetupResponseIEs_Value &) const;
    int operator != (const InitialContextSetupResponseIEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    MME_UE_S1AP_ID *get_MME_UE_S1AP_ID();
    const MME_UE_S1AP_ID *get_MME_UE_S1AP_ID() const;
    void set_MME_UE_S1AP_ID(const MME_UE_S1AP_ID &);
    MME_UE_S1AP_ID *release_MME_UE_S1AP_ID();
    void set_MME_UE_S1AP_ID(MME_UE_S1AP_ID *);

    ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID();
    const ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID() const;
    void set_ENB_UE_S1AP_ID(const ENB_UE_S1AP_ID &);
    ENB_UE_S1AP_ID *release_ENB_UE_S1AP_ID();
    void set_ENB_UE_S1AP_ID(ENB_UE_S1AP_ID *);

    E_RABSetupListCtxtSURes *get_E_RABSetupListCtxtSURes();
    const E_RABSetupListCtxtSURes *get_E_RABSetupListCtxtSURes() const;
    void set_E_RABSetupListCtxtSURes(const E_RABSetupListCtxtSURes &);
    E_RABSetupListCtxtSURes *release_E_RABSetupListCtxtSURes();
    void set_E_RABSetupListCtxtSURes(E_RABSetupListCtxtSURes *);

    E_RABList *get_E_RABList();
    const E_RABList *get_E_RABList() const;
    void set_E_RABList(const E_RABList &);
    E_RABList *release_E_RABList();
    void set_E_RABList(E_RABList *);

    CriticalityDiagnostics *get_CriticalityDiagnostics();
    const CriticalityDiagnostics *get_CriticalityDiagnostics() const;
    void set_CriticalityDiagnostics(const CriticalityDiagnostics &);
    CriticalityDiagnostics *release_CriticalityDiagnostics();
    void set_CriticalityDiagnostics(CriticalityDiagnostics *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq48   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef InitialContextSetupResponseIEs_Value value;

    __seq48();
    __seq48(const __seq48 &);
    __seq48(id, criticality, const value &);

    __seq48 & operator = (const __seq48 &);
    int operator == (const __seq48 &) const;
    int operator != (const __seq48 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

typedef __shared8 E_RABSetupItemCtxtSURes;

class OSS_PUBLIC E_RABSetupItemCtxtSUResIEs_Value : public OssConstrainedOpenType
{
public:
    E_RABSetupItemCtxtSUResIEs_Value();
    E_RABSetupItemCtxtSUResIEs_Value(const E_RABSetupItemCtxtSUResIEs_Value &);
    ~E_RABSetupItemCtxtSUResIEs_Value();
    E_RABSetupItemCtxtSUResIEs_Value & operator = (const E_RABSetupItemCtxtSUResIEs_Value &);
    int operator == (const E_RABSetupItemCtxtSUResIEs_Value &) const;
    int operator != (const E_RABSetupItemCtxtSUResIEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    __shared8 *get_E_RABSetupItemCtxtSURes();
    const __shared8 *get_E_RABSetupItemCtxtSURes() const;
    void set_E_RABSetupItemCtxtSURes(const __shared8 &);
    __shared8 *release_E_RABSetupItemCtxtSURes();
    void set_E_RABSetupItemCtxtSURes(__shared8 *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq49   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef E_RABSetupItemCtxtSUResIEs_Value value;

    __seq49();
    __seq49(const __seq49 &);
    __seq49(id, criticality, const value &);

    __seq49 & operator = (const __seq49 &);
    int operator == (const __seq49 &) const;
    int operator != (const __seq49 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC S_TMSI   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OssString mMEC;
    typedef OssString m_TMSI;
    typedef __shared2 iE_Extensions;

    S_TMSI();
    S_TMSI(const S_TMSI &);
    S_TMSI(const mMEC &, const m_TMSI &, const iE_Extensions &);
    S_TMSI(const mMEC &, const m_TMSI &);

    S_TMSI & operator = (const S_TMSI &);
    int operator == (const S_TMSI &) const;
    int operator != (const S_TMSI &) const;

    mMEC & get_mMEC();
    const mMEC & get_mMEC() const;
    void set_mMEC(const mMEC &);

    m_TMSI & get_m_TMSI();
    const m_TMSI & get_m_TMSI() const;
    void set_m_TMSI(const m_TMSI &);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    mMEC mMEC_field;
    m_TMSI m_TMSI_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC UEPagingID  : public OssChoice   /* CHOICE */
{
public:
    enum Id {
	unselected,
	s_TMSI_chosen = 1,
	iMSI_chosen = 2
    };
    typedef S_TMSI s_TMSI;
    typedef OssString iMSI;

    UEPagingID();
    UEPagingID(const UEPagingID &);
    ~UEPagingID();

    UEPagingID & operator = (const UEPagingID &);
    int operator == (const UEPagingID &) const;
    int operator != (const UEPagingID &) const;

    s_TMSI *get_s_TMSI();
    const s_TMSI *get_s_TMSI() const;
    void set_s_TMSI(const s_TMSI &);

    iMSI *get_iMSI();
    const iMSI *get_iMSI() const;
    void set_iMSI(const iMSI &);
private:
    union {
	s_TMSI *s_TMSI_field;
	OSSC::COssString iMSI_field;
    };
    void cleanup();
};

class OSS_PUBLIC __seq53;

class OSS_PUBLIC TAIList : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq53 component;

    TAIList();
    TAIList(const TAIList &);
    ~TAIList();

    TAIList & operator = (const TAIList &);
    int operator == (const TAIList &) const;
    int operator != (const TAIList &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(TAIList *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, TAIList *);

    int remove_front();
    int remove_after(OssIndex);

    TAIList *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC CSG_IdList_Item;

class OSS_PUBLIC CSG_IdList : public OssList  /* SEQUENCE OF */
{
public:
    typedef CSG_IdList_Item component;

    CSG_IdList();
    CSG_IdList(const CSG_IdList &);
    ~CSG_IdList();

    CSG_IdList & operator = (const CSG_IdList &);
    int operator == (const CSG_IdList &) const;
    int operator != (const CSG_IdList &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(CSG_IdList *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, CSG_IdList *);

    int remove_front();
    int remove_after(OssIndex);

    CSG_IdList *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC __seq193;

class OSS_PUBLIC __shared17 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq193 component;

    __shared17();
    __shared17(const __shared17 &);
    ~__shared17();

    __shared17 & operator = (const __shared17 &);
    int operator == (const __shared17 &) const;
    int operator != (const __shared17 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__shared17 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __shared17 *);

    int remove_front();
    int remove_after(OssIndex);

    __shared17 *extract_after(OssIndex, OssIndex);
};

typedef __shared17 RecommendedCellList;

class OSS_PUBLIC RecommendedCellsForPaging   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __shared17 recommendedCellList;
    typedef __shared2 iE_Extensions;

    RecommendedCellsForPaging();
    RecommendedCellsForPaging(const RecommendedCellsForPaging &);
    RecommendedCellsForPaging(const recommendedCellList &, const iE_Extensions &);
    RecommendedCellsForPaging(const recommendedCellList &);

    RecommendedCellsForPaging & operator = (const RecommendedCellsForPaging &);
    int operator == (const RecommendedCellsForPaging &) const;
    int operator != (const RecommendedCellsForPaging &) const;

    recommendedCellList & get_recommendedCellList();
    const recommendedCellList & get_recommendedCellList() const;
    void set_recommendedCellList(const recommendedCellList &);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    recommendedCellList recommendedCellList_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC AssistanceDataForRecommendedCells   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef RecommendedCellsForPaging recommendedCellsForPaging;
    typedef __shared2 iE_Extensions;

    AssistanceDataForRecommendedCells();
    AssistanceDataForRecommendedCells(const AssistanceDataForRecommendedCells &);
    AssistanceDataForRecommendedCells(const recommendedCellsForPaging &, const iE_Extensions &);
    AssistanceDataForRecommendedCells(const recommendedCellsForPaging &);

    AssistanceDataForRecommendedCells & operator = (const AssistanceDataForRecommendedCells &);
    int operator == (const AssistanceDataForRecommendedCells &) const;
    int operator != (const AssistanceDataForRecommendedCells &) const;

    recommendedCellsForPaging & get_recommendedCellsForPaging();
    const recommendedCellsForPaging & get_recommendedCellsForPaging() const;
    void set_recommendedCellsForPaging(const recommendedCellsForPaging &);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    recommendedCellsForPaging recommendedCellsForPaging_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC CellIdentifierAndCELevelForCECapableUEs   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef EUTRAN_CGI global_Cell_ID;
    typedef OssString cELevel;
    typedef __shared2 iE_Extensions;

    CellIdentifierAndCELevelForCECapableUEs();
    CellIdentifierAndCELevelForCECapableUEs(const CellIdentifierAndCELevelForCECapableUEs &);
    CellIdentifierAndCELevelForCECapableUEs(const global_Cell_ID &, const cELevel &, 
	const iE_Extensions &);
    CellIdentifierAndCELevelForCECapableUEs(const global_Cell_ID &, const cELevel &);

    CellIdentifierAndCELevelForCECapableUEs & operator = (const CellIdentifierAndCELevelForCECapableUEs &);
    int operator == (const CellIdentifierAndCELevelForCECapableUEs &) const;
    int operator != (const CellIdentifierAndCELevelForCECapableUEs &) const;

    global_Cell_ID & get_global_Cell_ID();
    const global_Cell_ID & get_global_Cell_ID() const;
    void set_global_Cell_ID(const global_Cell_ID &);

    cELevel & get_cELevel();
    const cELevel & get_cELevel() const;
    void set_cELevel(const cELevel &);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    global_Cell_ID global_Cell_ID_field;
    cELevel cELevel_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC AssistanceDataForCECapableUEs   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef CellIdentifierAndCELevelForCECapableUEs cellIdentifierAndCELevelForCECapableUEs;
    typedef __shared2 iE_Extensions;

    AssistanceDataForCECapableUEs();
    AssistanceDataForCECapableUEs(const AssistanceDataForCECapableUEs &);
    AssistanceDataForCECapableUEs(const cellIdentifierAndCELevelForCECapableUEs &, 
	const iE_Extensions &);
    AssistanceDataForCECapableUEs(const cellIdentifierAndCELevelForCECapableUEs &);

    AssistanceDataForCECapableUEs & operator = (const AssistanceDataForCECapableUEs &);
    int operator == (const AssistanceDataForCECapableUEs &) const;
    int operator != (const AssistanceDataForCECapableUEs &) const;

    cellIdentifierAndCELevelForCECapableUEs & get_cellIdentifierAndCELevelForCECapableUEs();
    const cellIdentifierAndCELevelForCECapableUEs & get_cellIdentifierAndCELevelForCECapableUEs() const;
    void set_cellIdentifierAndCELevelForCECapableUEs(const cellIdentifierAndCELevelForCECapableUEs &);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    cellIdentifierAndCELevelForCECapableUEs cellIdentifierAndCELevelForCECapableUEs_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC PagingAttemptInformation   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_INT32 pagingAttemptCount;
    typedef OSS_INT32 intendedNumberOfPagingAttempts;
    typedef enum NextPagingAreaScope nextPagingAreaScope;
    typedef __shared2 iE_Extensions;

    PagingAttemptInformation();
    PagingAttemptInformation(const PagingAttemptInformation &);
    PagingAttemptInformation(pagingAttemptCount, intendedNumberOfPagingAttempts, 
	nextPagingAreaScope, const iE_Extensions &);
    PagingAttemptInformation(pagingAttemptCount, intendedNumberOfPagingAttempts);

    PagingAttemptInformation & operator = (const PagingAttemptInformation &);
    int operator == (const PagingAttemptInformation &) const;
    int operator != (const PagingAttemptInformation &) const;

    pagingAttemptCount & get_pagingAttemptCount();
    pagingAttemptCount get_pagingAttemptCount() const;
    void set_pagingAttemptCount(pagingAttemptCount);

    intendedNumberOfPagingAttempts & get_intendedNumberOfPagingAttempts();
    intendedNumberOfPagingAttempts get_intendedNumberOfPagingAttempts() const;
    void set_intendedNumberOfPagingAttempts(intendedNumberOfPagingAttempts);

    nextPagingAreaScope *get_nextPagingAreaScope();
    const nextPagingAreaScope *get_nextPagingAreaScope() const;
    void set_nextPagingAreaScope(nextPagingAreaScope);
    int nextPagingAreaScope_is_present() const;
    void omit_nextPagingAreaScope();

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    pagingAttemptCount pagingAttemptCount_field;
    intendedNumberOfPagingAttempts intendedNumberOfPagingAttempts_field;
    nextPagingAreaScope nextPagingAreaScope_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC AssistanceDataForPaging   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef AssistanceDataForRecommendedCells assistanceDataForRecommendedCells;
    typedef AssistanceDataForCECapableUEs assistanceDataForCECapableUEs;
    typedef PagingAttemptInformation pagingAttemptInformation;
    typedef __shared2 iE_Extensions;

    AssistanceDataForPaging();
    AssistanceDataForPaging(const AssistanceDataForPaging &);
    AssistanceDataForPaging(const assistanceDataForRecommendedCells &, const assistanceDataForCECapableUEs &, 
	const pagingAttemptInformation &, const iE_Extensions &);

    AssistanceDataForPaging & operator = (const AssistanceDataForPaging &);
    int operator == (const AssistanceDataForPaging &) const;
    int operator != (const AssistanceDataForPaging &) const;

    assistanceDataForRecommendedCells *get_assistanceDataForRecommendedCells();
    const assistanceDataForRecommendedCells *get_assistanceDataForRecommendedCells() const;
    void set_assistanceDataForRecommendedCells(const assistanceDataForRecommendedCells &);
    int assistanceDataForRecommendedCells_is_present() const;
    void omit_assistanceDataForRecommendedCells();

    assistanceDataForCECapableUEs *get_assistanceDataForCECapableUEs();
    const assistanceDataForCECapableUEs *get_assistanceDataForCECapableUEs() const;
    void set_assistanceDataForCECapableUEs(const assistanceDataForCECapableUEs &);
    int assistanceDataForCECapableUEs_is_present() const;
    void omit_assistanceDataForCECapableUEs();

    pagingAttemptInformation *get_pagingAttemptInformation();
    const pagingAttemptInformation *get_pagingAttemptInformation() const;
    void set_pagingAttemptInformation(const pagingAttemptInformation &);
    int pagingAttemptInformation_is_present() const;
    void omit_pagingAttemptInformation();

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    assistanceDataForRecommendedCells assistanceDataForRecommendedCells_field;
    assistanceDataForCECapableUEs assistanceDataForCECapableUEs_field;
    pagingAttemptInformation pagingAttemptInformation_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC Paging_eDRXInformation   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef enum Paging_eDRX_Cycle paging_eDRX_Cycle;
    typedef enum PagingTimeWindow pagingTimeWindow;
    typedef __shared2 iE_Extensions;

    Paging_eDRXInformation();
    Paging_eDRXInformation(const Paging_eDRXInformation &);
    Paging_eDRXInformation(paging_eDRX_Cycle, pagingTimeWindow, const iE_Extensions &);
    Paging_eDRXInformation(paging_eDRX_Cycle);

    Paging_eDRXInformation & operator = (const Paging_eDRXInformation &);
    int operator == (const Paging_eDRXInformation &) const;
    int operator != (const Paging_eDRXInformation &) const;

    paging_eDRX_Cycle & get_paging_eDRX_Cycle();
    paging_eDRX_Cycle get_paging_eDRX_Cycle() const;
    void set_paging_eDRX_Cycle(paging_eDRX_Cycle);

    pagingTimeWindow *get_pagingTimeWindow();
    const pagingTimeWindow *get_pagingTimeWindow() const;
    void set_pagingTimeWindow(pagingTimeWindow);
    int pagingTimeWindow_is_present() const;
    void omit_pagingTimeWindow();

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    paging_eDRX_Cycle paging_eDRX_Cycle_field;
    pagingTimeWindow pagingTimeWindow_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC NB_IoT_Paging_eDRXInformation   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef enum NB_IoT_Paging_eDRX_Cycle nB_IoT_paging_eDRX_Cycle;
    typedef enum NB_IoT_PagingTimeWindow nB_IoT_pagingTimeWindow;
    typedef __shared2 iE_Extensions;

    NB_IoT_Paging_eDRXInformation();
    NB_IoT_Paging_eDRXInformation(const NB_IoT_Paging_eDRXInformation &);
    NB_IoT_Paging_eDRXInformation(nB_IoT_paging_eDRX_Cycle, nB_IoT_pagingTimeWindow, 
	const iE_Extensions &);
    NB_IoT_Paging_eDRXInformation(nB_IoT_paging_eDRX_Cycle);

    NB_IoT_Paging_eDRXInformation & operator = (const NB_IoT_Paging_eDRXInformation &);
    int operator == (const NB_IoT_Paging_eDRXInformation &) const;
    int operator != (const NB_IoT_Paging_eDRXInformation &) const;

    nB_IoT_paging_eDRX_Cycle & get_nB_IoT_paging_eDRX_Cycle();
    nB_IoT_paging_eDRX_Cycle get_nB_IoT_paging_eDRX_Cycle() const;
    void set_nB_IoT_paging_eDRX_Cycle(nB_IoT_paging_eDRX_Cycle);

    nB_IoT_pagingTimeWindow *get_nB_IoT_pagingTimeWindow();
    const nB_IoT_pagingTimeWindow *get_nB_IoT_pagingTimeWindow() const;
    void set_nB_IoT_pagingTimeWindow(nB_IoT_pagingTimeWindow);
    int nB_IoT_pagingTimeWindow_is_present() const;
    void omit_nB_IoT_pagingTimeWindow();

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    nB_IoT_paging_eDRX_Cycle nB_IoT_paging_eDRX_Cycle_field;
    nB_IoT_pagingTimeWindow nB_IoT_pagingTimeWindow_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC PagingIEs_Value : public OssConstrainedOpenType
{
public:
    PagingIEs_Value();
    PagingIEs_Value(const PagingIEs_Value &);
    ~PagingIEs_Value();
    PagingIEs_Value & operator = (const PagingIEs_Value &);
    int operator == (const PagingIEs_Value &) const;
    int operator != (const PagingIEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    UEIdentityIndexValue *get_UEIdentityIndexValue();
    const UEIdentityIndexValue *get_UEIdentityIndexValue() const;
    void set_UEIdentityIndexValue(const UEIdentityIndexValue &);
    UEIdentityIndexValue *release_UEIdentityIndexValue();
    void set_UEIdentityIndexValue(UEIdentityIndexValue *);

    UEPagingID *get_UEPagingID();
    const UEPagingID *get_UEPagingID() const;
    void set_UEPagingID(const UEPagingID &);
    UEPagingID *release_UEPagingID();
    void set_UEPagingID(UEPagingID *);

    PagingDRX *get_PagingDRX();
    const PagingDRX *get_PagingDRX() const;
    void set_PagingDRX(const PagingDRX &);
    PagingDRX *release_PagingDRX();
    void set_PagingDRX(PagingDRX *);

    CNDomain *get_CNDomain();
    const CNDomain *get_CNDomain() const;
    void set_CNDomain(const CNDomain &);
    CNDomain *release_CNDomain();
    void set_CNDomain(CNDomain *);

    TAIList *get_TAIList();
    const TAIList *get_TAIList() const;
    void set_TAIList(const TAIList &);
    TAIList *release_TAIList();
    void set_TAIList(TAIList *);

    CSG_IdList *get_CSG_IdList();
    const CSG_IdList *get_CSG_IdList() const;
    void set_CSG_IdList(const CSG_IdList &);
    CSG_IdList *release_CSG_IdList();
    void set_CSG_IdList(CSG_IdList *);

    PagingPriority *get_PagingPriority();
    const PagingPriority *get_PagingPriority() const;
    void set_PagingPriority(const PagingPriority &);
    PagingPriority *release_PagingPriority();
    void set_PagingPriority(PagingPriority *);

    UERadioCapabilityForPaging *get_UERadioCapabilityForPaging();
    const UERadioCapabilityForPaging *get_UERadioCapabilityForPaging() const;
    void set_UERadioCapabilityForPaging(const UERadioCapabilityForPaging &);
    UERadioCapabilityForPaging *release_UERadioCapabilityForPaging();
    void set_UERadioCapabilityForPaging(UERadioCapabilityForPaging *);

    AssistanceDataForPaging *get_AssistanceDataForPaging();
    const AssistanceDataForPaging *get_AssistanceDataForPaging() const;
    void set_AssistanceDataForPaging(const AssistanceDataForPaging &);
    AssistanceDataForPaging *release_AssistanceDataForPaging();
    void set_AssistanceDataForPaging(AssistanceDataForPaging *);

    Paging_eDRXInformation *get_Paging_eDRXInformation();
    const Paging_eDRXInformation *get_Paging_eDRXInformation() const;
    void set_Paging_eDRXInformation(const Paging_eDRXInformation &);
    Paging_eDRXInformation *release_Paging_eDRXInformation();
    void set_Paging_eDRXInformation(Paging_eDRXInformation *);

    Extended_UEIdentityIndexValue *get_Extended_UEIdentityIndexValue();
    const Extended_UEIdentityIndexValue *get_Extended_UEIdentityIndexValue() const;
    void set_Extended_UEIdentityIndexValue(const Extended_UEIdentityIndexValue &);
    Extended_UEIdentityIndexValue *release_Extended_UEIdentityIndexValue();
    void set_Extended_UEIdentityIndexValue(Extended_UEIdentityIndexValue *);

    NB_IoT_Paging_eDRXInformation *get_NB_IoT_Paging_eDRXInformation();
    const NB_IoT_Paging_eDRXInformation *get_NB_IoT_Paging_eDRXInformation() const;
    void set_NB_IoT_Paging_eDRXInformation(const NB_IoT_Paging_eDRXInformation &);
    NB_IoT_Paging_eDRXInformation *release_NB_IoT_Paging_eDRXInformation();
    void set_NB_IoT_Paging_eDRXInformation(NB_IoT_Paging_eDRXInformation *);

    NB_IoT_UEIdentityIndexValue *get_NB_IoT_UEIdentityIndexValue();
    const NB_IoT_UEIdentityIndexValue *get_NB_IoT_UEIdentityIndexValue() const;
    void set_NB_IoT_UEIdentityIndexValue(const NB_IoT_UEIdentityIndexValue &);
    NB_IoT_UEIdentityIndexValue *release_NB_IoT_UEIdentityIndexValue();
    void set_NB_IoT_UEIdentityIndexValue(NB_IoT_UEIdentityIndexValue *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq52   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef PagingIEs_Value value;

    __seq52();
    __seq52(const __seq52 &);
    __seq52(id, criticality, const value &);

    __seq52 & operator = (const __seq52 &);
    int operator == (const __seq52 &) const;
    int operator != (const __seq52 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC TAIItem   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef TAI tAI;
    typedef __shared2 iE_Extensions;

    TAIItem();
    TAIItem(const TAIItem &);
    TAIItem(const tAI &, const iE_Extensions &);
    TAIItem(const tAI &);

    TAIItem & operator = (const TAIItem &);
    int operator == (const TAIItem &) const;
    int operator != (const TAIItem &) const;

    tAI & get_tAI();
    const tAI & get_tAI() const;
    void set_tAI(const tAI &);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    tAI tAI_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC TAIItemIEs_Value : public OssConstrainedOpenType
{
public:
    TAIItemIEs_Value();
    TAIItemIEs_Value(const TAIItemIEs_Value &);
    ~TAIItemIEs_Value();
    TAIItemIEs_Value & operator = (const TAIItemIEs_Value &);
    int operator == (const TAIItemIEs_Value &) const;
    int operator != (const TAIItemIEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    TAIItem *get_TAIItem();
    const TAIItem *get_TAIItem() const;
    void set_TAIItem(const TAIItem &);
    TAIItem *release_TAIItem();
    void set_TAIItem(TAIItem *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq53   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef TAIItemIEs_Value value;

    __seq53();
    __seq53(const __seq53 &);
    __seq53(id, criticality, const value &);

    __seq53 & operator = (const __seq53 &);
    int operator == (const __seq53 &) const;
    int operator != (const __seq53 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

typedef OssString TBCD_STRING;

typedef OssString PLMNidentity;

typedef OssString TAC;

class OSS_PUBLIC UEContextReleaseRequest_IEs_Value : public OssConstrainedOpenType
{
public:
    UEContextReleaseRequest_IEs_Value();
    UEContextReleaseRequest_IEs_Value(const UEContextReleaseRequest_IEs_Value &);
    ~UEContextReleaseRequest_IEs_Value();
    UEContextReleaseRequest_IEs_Value & operator = (const UEContextReleaseRequest_IEs_Value &);
    int operator == (const UEContextReleaseRequest_IEs_Value &) const;
    int operator != (const UEContextReleaseRequest_IEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    MME_UE_S1AP_ID *get_MME_UE_S1AP_ID();
    const MME_UE_S1AP_ID *get_MME_UE_S1AP_ID() const;
    void set_MME_UE_S1AP_ID(const MME_UE_S1AP_ID &);
    MME_UE_S1AP_ID *release_MME_UE_S1AP_ID();
    void set_MME_UE_S1AP_ID(MME_UE_S1AP_ID *);

    ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID();
    const ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID() const;
    void set_ENB_UE_S1AP_ID(const ENB_UE_S1AP_ID &);
    ENB_UE_S1AP_ID *release_ENB_UE_S1AP_ID();
    void set_ENB_UE_S1AP_ID(ENB_UE_S1AP_ID *);

    Cause *get_Cause();
    const Cause *get_Cause() const;
    void set_Cause(const Cause &);
    Cause *release_Cause();
    void set_Cause(Cause *);

    GWContextReleaseIndication *get_GWContextReleaseIndication();
    const GWContextReleaseIndication *get_GWContextReleaseIndication() const;
    void set_GWContextReleaseIndication(const GWContextReleaseIndication &);
    GWContextReleaseIndication *release_GWContextReleaseIndication();
    void set_GWContextReleaseIndication(GWContextReleaseIndication *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq56   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef UEContextReleaseRequest_IEs_Value value;

    __seq56();
    __seq56(const __seq56 &);
    __seq56(id, criticality, const value &);

    __seq56 & operator = (const __seq56 &);
    int operator == (const __seq56 &) const;
    int operator != (const __seq56 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC UE_S1AP_ID_pair   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 mME_UE_S1AP_ID;
    typedef OSS_UINT32 eNB_UE_S1AP_ID;
    typedef __shared2 iE_Extensions;

    UE_S1AP_ID_pair();
    UE_S1AP_ID_pair(const UE_S1AP_ID_pair &);
    UE_S1AP_ID_pair(mME_UE_S1AP_ID, eNB_UE_S1AP_ID, const iE_Extensions &);
    UE_S1AP_ID_pair(mME_UE_S1AP_ID, eNB_UE_S1AP_ID);

    UE_S1AP_ID_pair & operator = (const UE_S1AP_ID_pair &);
    int operator == (const UE_S1AP_ID_pair &) const;
    int operator != (const UE_S1AP_ID_pair &) const;

    mME_UE_S1AP_ID & get_mME_UE_S1AP_ID();
    mME_UE_S1AP_ID get_mME_UE_S1AP_ID() const;
    void set_mME_UE_S1AP_ID(mME_UE_S1AP_ID);

    eNB_UE_S1AP_ID & get_eNB_UE_S1AP_ID();
    eNB_UE_S1AP_ID get_eNB_UE_S1AP_ID() const;
    void set_eNB_UE_S1AP_ID(eNB_UE_S1AP_ID);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    mME_UE_S1AP_ID mME_UE_S1AP_ID_field;
    eNB_UE_S1AP_ID eNB_UE_S1AP_ID_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC UE_S1AP_IDs  : public OssChoice   /* CHOICE */
{
public:
    enum Id {
	unselected,
	uE_S1AP_ID_pair_chosen = 1,
	mME_UE_S1AP_ID_chosen = 2
    };
    typedef UE_S1AP_ID_pair uE_S1AP_ID_pair;
    typedef OSS_UINT32 mME_UE_S1AP_ID;

    UE_S1AP_IDs();
    UE_S1AP_IDs(const UE_S1AP_IDs &);
    ~UE_S1AP_IDs();

    UE_S1AP_IDs & operator = (const UE_S1AP_IDs &);
    int operator == (const UE_S1AP_IDs &) const;
    int operator != (const UE_S1AP_IDs &) const;

    uE_S1AP_ID_pair *get_uE_S1AP_ID_pair();
    const uE_S1AP_ID_pair *get_uE_S1AP_ID_pair() const;
    void set_uE_S1AP_ID_pair(const uE_S1AP_ID_pair &);

    mME_UE_S1AP_ID *get_mME_UE_S1AP_ID();
    const mME_UE_S1AP_ID *get_mME_UE_S1AP_ID() const;
    void set_mME_UE_S1AP_ID(mME_UE_S1AP_ID);
private:
    union {
	uE_S1AP_ID_pair *uE_S1AP_ID_pair_field;
	mME_UE_S1AP_ID mME_UE_S1AP_ID_field;
    };
    void cleanup();
};

class OSS_PUBLIC UEContextReleaseCommand_IEs_Value : public OssConstrainedOpenType
{
public:
    UEContextReleaseCommand_IEs_Value();
    UEContextReleaseCommand_IEs_Value(const UEContextReleaseCommand_IEs_Value &);
    ~UEContextReleaseCommand_IEs_Value();
    UEContextReleaseCommand_IEs_Value & operator = (const UEContextReleaseCommand_IEs_Value &);
    int operator == (const UEContextReleaseCommand_IEs_Value &) const;
    int operator != (const UEContextReleaseCommand_IEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    UE_S1AP_IDs *get_UE_S1AP_IDs();
    const UE_S1AP_IDs *get_UE_S1AP_IDs() const;
    void set_UE_S1AP_IDs(const UE_S1AP_IDs &);
    UE_S1AP_IDs *release_UE_S1AP_IDs();
    void set_UE_S1AP_IDs(UE_S1AP_IDs *);

    Cause *get_Cause();
    const Cause *get_Cause() const;
    void set_Cause(const Cause &);
    Cause *release_Cause();
    void set_Cause(Cause *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq57   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef UEContextReleaseCommand_IEs_Value value;

    __seq57();
    __seq57(const __seq57 &);
    __seq57(id, criticality, const value &);

    __seq57 & operator = (const __seq57 &);
    int operator == (const __seq57 &) const;
    int operator != (const __seq57 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC __seq195;

class OSS_PUBLIC __shared40 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq195 component;

    __shared40();
    __shared40(const __shared40 &);
    ~__shared40();

    __shared40 & operator = (const __shared40 &);
    int operator == (const __shared40 &) const;
    int operator != (const __shared40 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__shared40 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __shared40 *);

    int remove_front();
    int remove_after(OssIndex);

    __shared40 *extract_after(OssIndex, OssIndex);
};

typedef __shared40 RecommendedENBList;

class OSS_PUBLIC RecommendedENBsForPaging   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __shared40 recommendedENBList;
    typedef __shared2 iE_Extensions;

    RecommendedENBsForPaging();
    RecommendedENBsForPaging(const RecommendedENBsForPaging &);
    RecommendedENBsForPaging(const recommendedENBList &, const iE_Extensions &);
    RecommendedENBsForPaging(const recommendedENBList &);

    RecommendedENBsForPaging & operator = (const RecommendedENBsForPaging &);
    int operator == (const RecommendedENBsForPaging &) const;
    int operator != (const RecommendedENBsForPaging &) const;

    recommendedENBList & get_recommendedENBList();
    const recommendedENBList & get_recommendedENBList() const;
    void set_recommendedENBList(const recommendedENBList &);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    recommendedENBList recommendedENBList_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC InformationOnRecommendedCellsAndENBsForPaging   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef RecommendedCellsForPaging recommendedCellsForPaging;
    typedef RecommendedENBsForPaging recommendENBsForPaging;
    typedef __shared2 iE_Extensions;

    InformationOnRecommendedCellsAndENBsForPaging();
    InformationOnRecommendedCellsAndENBsForPaging(const InformationOnRecommendedCellsAndENBsForPaging &);
    InformationOnRecommendedCellsAndENBsForPaging(const recommendedCellsForPaging &, 
	const recommendENBsForPaging &, const iE_Extensions &);
    InformationOnRecommendedCellsAndENBsForPaging(const recommendedCellsForPaging &, 
	const recommendENBsForPaging &);

    InformationOnRecommendedCellsAndENBsForPaging & operator = (const InformationOnRecommendedCellsAndENBsForPaging &);
    int operator == (const InformationOnRecommendedCellsAndENBsForPaging &) const;
    int operator != (const InformationOnRecommendedCellsAndENBsForPaging &) const;

    recommendedCellsForPaging & get_recommendedCellsForPaging();
    const recommendedCellsForPaging & get_recommendedCellsForPaging() const;
    void set_recommendedCellsForPaging(const recommendedCellsForPaging &);

    recommendENBsForPaging & get_recommendENBsForPaging();
    const recommendENBsForPaging & get_recommendENBsForPaging() const;
    void set_recommendENBsForPaging(const recommendENBsForPaging &);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    recommendedCellsForPaging recommendedCellsForPaging_field;
    recommendENBsForPaging recommendENBsForPaging_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC UEContextReleaseComplete_IEs_Value : public OssConstrainedOpenType
{
public:
    UEContextReleaseComplete_IEs_Value();
    UEContextReleaseComplete_IEs_Value(const UEContextReleaseComplete_IEs_Value &);
    ~UEContextReleaseComplete_IEs_Value();
    UEContextReleaseComplete_IEs_Value & operator = (const UEContextReleaseComplete_IEs_Value &);
    int operator == (const UEContextReleaseComplete_IEs_Value &) const;
    int operator != (const UEContextReleaseComplete_IEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    MME_UE_S1AP_ID *get_MME_UE_S1AP_ID();
    const MME_UE_S1AP_ID *get_MME_UE_S1AP_ID() const;
    void set_MME_UE_S1AP_ID(const MME_UE_S1AP_ID &);
    MME_UE_S1AP_ID *release_MME_UE_S1AP_ID();
    void set_MME_UE_S1AP_ID(MME_UE_S1AP_ID *);

    ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID();
    const ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID() const;
    void set_ENB_UE_S1AP_ID(const ENB_UE_S1AP_ID &);
    ENB_UE_S1AP_ID *release_ENB_UE_S1AP_ID();
    void set_ENB_UE_S1AP_ID(ENB_UE_S1AP_ID *);

    CriticalityDiagnostics *get_CriticalityDiagnostics();
    const CriticalityDiagnostics *get_CriticalityDiagnostics() const;
    void set_CriticalityDiagnostics(const CriticalityDiagnostics &);
    CriticalityDiagnostics *release_CriticalityDiagnostics();
    void set_CriticalityDiagnostics(CriticalityDiagnostics *);

    UserLocationInformation *get_UserLocationInformation();
    const UserLocationInformation *get_UserLocationInformation() const;
    void set_UserLocationInformation(const UserLocationInformation &);
    UserLocationInformation *release_UserLocationInformation();
    void set_UserLocationInformation(UserLocationInformation *);

    InformationOnRecommendedCellsAndENBsForPaging *get_InformationOnRecommendedCellsAndENBsForPaging();
    const InformationOnRecommendedCellsAndENBsForPaging *get_InformationOnRecommendedCellsAndENBsForPaging() const;
    void set_InformationOnRecommendedCellsAndENBsForPaging(const InformationOnRecommendedCellsAndENBsForPaging &);
    InformationOnRecommendedCellsAndENBsForPaging *release_InformationOnRecommendedCellsAndENBsForPaging();
    void set_InformationOnRecommendedCellsAndENBsForPaging(InformationOnRecommendedCellsAndENBsForPaging *);

    CellIdentifierAndCELevelForCECapableUEs *get_CellIdentifierAndCELevelForCECapableUEs();
    const CellIdentifierAndCELevelForCECapableUEs *get_CellIdentifierAndCELevelForCECapableUEs() const;
    void set_CellIdentifierAndCELevelForCECapableUEs(const CellIdentifierAndCELevelForCECapableUEs &);
    CellIdentifierAndCELevelForCECapableUEs *release_CellIdentifierAndCELevelForCECapableUEs();
    void set_CellIdentifierAndCELevelForCECapableUEs(CellIdentifierAndCELevelForCECapableUEs *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq58   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef UEContextReleaseComplete_IEs_Value value;

    __seq58();
    __seq58(const __seq58 &);
    __seq58(id, criticality, const value &);

    __seq58 & operator = (const __seq58 &);
    int operator == (const __seq58 &) const;
    int operator != (const __seq58 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC UEContextModificationRequestIEs_Value : public OssConstrainedOpenType
{
public:
    UEContextModificationRequestIEs_Value();
    UEContextModificationRequestIEs_Value(const UEContextModificationRequestIEs_Value &);
    ~UEContextModificationRequestIEs_Value();
    UEContextModificationRequestIEs_Value & operator = (const UEContextModificationRequestIEs_Value &);
    int operator == (const UEContextModificationRequestIEs_Value &) const;
    int operator != (const UEContextModificationRequestIEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    MME_UE_S1AP_ID *get_MME_UE_S1AP_ID();
    const MME_UE_S1AP_ID *get_MME_UE_S1AP_ID() const;
    void set_MME_UE_S1AP_ID(const MME_UE_S1AP_ID &);
    MME_UE_S1AP_ID *release_MME_UE_S1AP_ID();
    void set_MME_UE_S1AP_ID(MME_UE_S1AP_ID *);

    ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID();
    const ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID() const;
    void set_ENB_UE_S1AP_ID(const ENB_UE_S1AP_ID &);
    ENB_UE_S1AP_ID *release_ENB_UE_S1AP_ID();
    void set_ENB_UE_S1AP_ID(ENB_UE_S1AP_ID *);

    SecurityKey *get_SecurityKey();
    const SecurityKey *get_SecurityKey() const;
    void set_SecurityKey(const SecurityKey &);
    SecurityKey *release_SecurityKey();
    void set_SecurityKey(SecurityKey *);

    SubscriberProfileIDforRFP *get_SubscriberProfileIDforRFP();
    const SubscriberProfileIDforRFP *get_SubscriberProfileIDforRFP() const;
    void set_SubscriberProfileIDforRFP(const SubscriberProfileIDforRFP &);
    SubscriberProfileIDforRFP *release_SubscriberProfileIDforRFP();
    void set_SubscriberProfileIDforRFP(SubscriberProfileIDforRFP *);

    UEAggregateMaximumBitrate *get_UEAggregateMaximumBitrate();
    const UEAggregateMaximumBitrate *get_UEAggregateMaximumBitrate() const;
    void set_UEAggregateMaximumBitrate(const UEAggregateMaximumBitrate &);
    UEAggregateMaximumBitrate *release_UEAggregateMaximumBitrate();
    void set_UEAggregateMaximumBitrate(UEAggregateMaximumBitrate *);

    CSFallbackIndicator *get_CSFallbackIndicator();
    const CSFallbackIndicator *get_CSFallbackIndicator() const;
    void set_CSFallbackIndicator(const CSFallbackIndicator &);
    CSFallbackIndicator *release_CSFallbackIndicator();
    void set_CSFallbackIndicator(CSFallbackIndicator *);

    UESecurityCapabilities *get_UESecurityCapabilities();
    const UESecurityCapabilities *get_UESecurityCapabilities() const;
    void set_UESecurityCapabilities(const UESecurityCapabilities &);
    UESecurityCapabilities *release_UESecurityCapabilities();
    void set_UESecurityCapabilities(UESecurityCapabilities *);

    CSGMembershipStatus *get_CSGMembershipStatus();
    const CSGMembershipStatus *get_CSGMembershipStatus() const;
    void set_CSGMembershipStatus(const CSGMembershipStatus &);
    CSGMembershipStatus *release_CSGMembershipStatus();
    void set_CSGMembershipStatus(CSGMembershipStatus *);

    LAI *get_LAI();
    const LAI *get_LAI() const;
    void set_LAI(const LAI &);
    LAI *release_LAI();
    void set_LAI(LAI *);

    AdditionalCSFallbackIndicator *get_AdditionalCSFallbackIndicator();
    const AdditionalCSFallbackIndicator *get_AdditionalCSFallbackIndicator() const;
    void set_AdditionalCSFallbackIndicator(const AdditionalCSFallbackIndicator &);
    AdditionalCSFallbackIndicator *release_AdditionalCSFallbackIndicator();
    void set_AdditionalCSFallbackIndicator(AdditionalCSFallbackIndicator *);

    ProSeAuthorized *get_ProSeAuthorized();
    const ProSeAuthorized *get_ProSeAuthorized() const;
    void set_ProSeAuthorized(const ProSeAuthorized &);
    ProSeAuthorized *release_ProSeAuthorized();
    void set_ProSeAuthorized(ProSeAuthorized *);

    SRVCCOperationPossible *get_SRVCCOperationPossible();
    const SRVCCOperationPossible *get_SRVCCOperationPossible() const;
    void set_SRVCCOperationPossible(const SRVCCOperationPossible &);
    SRVCCOperationPossible *release_SRVCCOperationPossible();
    void set_SRVCCOperationPossible(SRVCCOperationPossible *);

    SRVCCOperationNotPossible *get_SRVCCOperationNotPossible();
    const SRVCCOperationNotPossible *get_SRVCCOperationNotPossible() const;
    void set_SRVCCOperationNotPossible(const SRVCCOperationNotPossible &);
    SRVCCOperationNotPossible *release_SRVCCOperationNotPossible();
    void set_SRVCCOperationNotPossible(SRVCCOperationNotPossible *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq59   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef UEContextModificationRequestIEs_Value value;

    __seq59();
    __seq59(const __seq59 &);
    __seq59(id, criticality, const value &);

    __seq59 & operator = (const __seq59 &);
    int operator == (const __seq59 &) const;
    int operator != (const __seq59 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC UERadioCapabilityMatchRequestIEs_Value : public OssConstrainedOpenType
{
public:
    UERadioCapabilityMatchRequestIEs_Value();
    UERadioCapabilityMatchRequestIEs_Value(const UERadioCapabilityMatchRequestIEs_Value &);
    ~UERadioCapabilityMatchRequestIEs_Value();
    UERadioCapabilityMatchRequestIEs_Value & operator = (const UERadioCapabilityMatchRequestIEs_Value &);
    int operator == (const UERadioCapabilityMatchRequestIEs_Value &) const;
    int operator != (const UERadioCapabilityMatchRequestIEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    MME_UE_S1AP_ID *get_MME_UE_S1AP_ID();
    const MME_UE_S1AP_ID *get_MME_UE_S1AP_ID() const;
    void set_MME_UE_S1AP_ID(const MME_UE_S1AP_ID &);
    MME_UE_S1AP_ID *release_MME_UE_S1AP_ID();
    void set_MME_UE_S1AP_ID(MME_UE_S1AP_ID *);

    ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID();
    const ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID() const;
    void set_ENB_UE_S1AP_ID(const ENB_UE_S1AP_ID &);
    ENB_UE_S1AP_ID *release_ENB_UE_S1AP_ID();
    void set_ENB_UE_S1AP_ID(ENB_UE_S1AP_ID *);

    UERadioCapability *get_UERadioCapability();
    const UERadioCapability *get_UERadioCapability() const;
    void set_UERadioCapability(const UERadioCapability &);
    UERadioCapability *release_UERadioCapability();
    void set_UERadioCapability(UERadioCapability *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __shared51;

class OSS_PUBLIC __shared52 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __shared51 component;

    __shared52();
    __shared52(const __shared52 &);
    ~__shared52();

    __shared52 & operator = (const __shared52 &);
    int operator == (const __shared52 &) const;
    int operator != (const __shared52 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__shared52 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __shared52 *);

    int remove_front();
    int remove_after(OssIndex);

    __shared52 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC __shared53   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __shared52 protocolIEs;

    __shared53();
    __shared53(const __shared53 &);
    __shared53(const protocolIEs &);

    __shared53 & operator = (const __shared53 &);
    int operator == (const __shared53 &) const;
    int operator != (const __shared53 &) const;

    protocolIEs & get_protocolIEs();
    const protocolIEs & get_protocolIEs() const;
    void set_protocolIEs(const protocolIEs &);
private:
    protocolIEs protocolIEs_field;
};

typedef __shared53 UERadioCapabilityMatchRequest;

class OSS_PUBLIC __shared51   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef UERadioCapabilityMatchRequestIEs_Value value;

    __shared51();
    __shared51(const __shared51 &);
    __shared51(id, criticality, const value &);

    __shared51 & operator = (const __shared51 &);
    int operator == (const __shared51 &) const;
    int operator != (const __shared51 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC UERadioCapabilityMatchResponseIEs_Value : public OssConstrainedOpenType
{
public:
    UERadioCapabilityMatchResponseIEs_Value();
    UERadioCapabilityMatchResponseIEs_Value(const UERadioCapabilityMatchResponseIEs_Value &);
    ~UERadioCapabilityMatchResponseIEs_Value();
    UERadioCapabilityMatchResponseIEs_Value & operator = (const UERadioCapabilityMatchResponseIEs_Value &);
    int operator == (const UERadioCapabilityMatchResponseIEs_Value &) const;
    int operator != (const UERadioCapabilityMatchResponseIEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    MME_UE_S1AP_ID *get_MME_UE_S1AP_ID();
    const MME_UE_S1AP_ID *get_MME_UE_S1AP_ID() const;
    void set_MME_UE_S1AP_ID(const MME_UE_S1AP_ID &);
    MME_UE_S1AP_ID *release_MME_UE_S1AP_ID();
    void set_MME_UE_S1AP_ID(MME_UE_S1AP_ID *);

    ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID();
    const ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID() const;
    void set_ENB_UE_S1AP_ID(const ENB_UE_S1AP_ID &);
    ENB_UE_S1AP_ID *release_ENB_UE_S1AP_ID();
    void set_ENB_UE_S1AP_ID(ENB_UE_S1AP_ID *);

    VoiceSupportMatchIndicator *get_VoiceSupportMatchIndicator();
    const VoiceSupportMatchIndicator *get_VoiceSupportMatchIndicator() const;
    void set_VoiceSupportMatchIndicator(const VoiceSupportMatchIndicator &);
    VoiceSupportMatchIndicator *release_VoiceSupportMatchIndicator();
    void set_VoiceSupportMatchIndicator(VoiceSupportMatchIndicator *);

    CriticalityDiagnostics *get_CriticalityDiagnostics();
    const CriticalityDiagnostics *get_CriticalityDiagnostics() const;
    void set_CriticalityDiagnostics(const CriticalityDiagnostics &);
    CriticalityDiagnostics *release_CriticalityDiagnostics();
    void set_CriticalityDiagnostics(CriticalityDiagnostics *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq63;

class OSS_PUBLIC __seqof49 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq63 component;

    __seqof49();
    __seqof49(const __seqof49 &);
    ~__seqof49();

    __seqof49 & operator = (const __seqof49 &);
    int operator == (const __seqof49 &) const;
    int operator != (const __seqof49 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof49 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof49 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof49 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC UERadioCapabilityMatchResponse   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __seqof49 protocolIEs;

    UERadioCapabilityMatchResponse();
    UERadioCapabilityMatchResponse(const UERadioCapabilityMatchResponse &);
    UERadioCapabilityMatchResponse(const protocolIEs &);

    UERadioCapabilityMatchResponse & operator = (const UERadioCapabilityMatchResponse &);
    int operator == (const UERadioCapabilityMatchResponse &) const;
    int operator != (const UERadioCapabilityMatchResponse &) const;

    protocolIEs & get_protocolIEs();
    const protocolIEs & get_protocolIEs() const;
    void set_protocolIEs(const protocolIEs &);
private:
    protocolIEs protocolIEs_field;
};

class OSS_PUBLIC __seq63   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef UERadioCapabilityMatchResponseIEs_Value value;

    __seq63();
    __seq63(const __seq63 &);
    __seq63(id, criticality, const value &);

    __seq63 & operator = (const __seq63 &);
    int operator == (const __seq63 &) const;
    int operator != (const __seq63 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC DownlinkNASTransport_IEs_Value : public OssConstrainedOpenType
{
public:
    DownlinkNASTransport_IEs_Value();
    DownlinkNASTransport_IEs_Value(const DownlinkNASTransport_IEs_Value &);
    ~DownlinkNASTransport_IEs_Value();
    DownlinkNASTransport_IEs_Value & operator = (const DownlinkNASTransport_IEs_Value &);
    int operator == (const DownlinkNASTransport_IEs_Value &) const;
    int operator != (const DownlinkNASTransport_IEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    MME_UE_S1AP_ID *get_MME_UE_S1AP_ID();
    const MME_UE_S1AP_ID *get_MME_UE_S1AP_ID() const;
    void set_MME_UE_S1AP_ID(const MME_UE_S1AP_ID &);
    MME_UE_S1AP_ID *release_MME_UE_S1AP_ID();
    void set_MME_UE_S1AP_ID(MME_UE_S1AP_ID *);

    ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID();
    const ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID() const;
    void set_ENB_UE_S1AP_ID(const ENB_UE_S1AP_ID &);
    ENB_UE_S1AP_ID *release_ENB_UE_S1AP_ID();
    void set_ENB_UE_S1AP_ID(ENB_UE_S1AP_ID *);

    NAS_PDU *get_NAS_PDU();
    const NAS_PDU *get_NAS_PDU() const;
    void set_NAS_PDU(const NAS_PDU &);
    NAS_PDU *release_NAS_PDU();
    void set_NAS_PDU(NAS_PDU *);

    HandoverRestrictionList *get_HandoverRestrictionList();
    const HandoverRestrictionList *get_HandoverRestrictionList() const;
    void set_HandoverRestrictionList(const HandoverRestrictionList &);
    HandoverRestrictionList *release_HandoverRestrictionList();
    void set_HandoverRestrictionList(HandoverRestrictionList *);

    SubscriberProfileIDforRFP *get_SubscriberProfileIDforRFP();
    const SubscriberProfileIDforRFP *get_SubscriberProfileIDforRFP() const;
    void set_SubscriberProfileIDforRFP(const SubscriberProfileIDforRFP &);
    SubscriberProfileIDforRFP *release_SubscriberProfileIDforRFP();
    void set_SubscriberProfileIDforRFP(SubscriberProfileIDforRFP *);

    SRVCCOperationPossible *get_SRVCCOperationPossible();
    const SRVCCOperationPossible *get_SRVCCOperationPossible() const;
    void set_SRVCCOperationPossible(const SRVCCOperationPossible &);
    SRVCCOperationPossible *release_SRVCCOperationPossible();
    void set_SRVCCOperationPossible(SRVCCOperationPossible *);

    UERadioCapability *get_UERadioCapability();
    const UERadioCapability *get_UERadioCapability() const;
    void set_UERadioCapability(const UERadioCapability &);
    UERadioCapability *release_UERadioCapability();
    void set_UERadioCapability(UERadioCapability *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq64   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef DownlinkNASTransport_IEs_Value value;

    __seq64();
    __seq64(const __seq64 &);
    __seq64(id, criticality, const value &);

    __seq64 & operator = (const __seq64 &);
    int operator == (const __seq64 &) const;
    int operator != (const __seq64 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC InitialUEMessage_IEs_Value : public OssConstrainedOpenType
{
public:
    InitialUEMessage_IEs_Value();
    InitialUEMessage_IEs_Value(const InitialUEMessage_IEs_Value &);
    ~InitialUEMessage_IEs_Value();
    InitialUEMessage_IEs_Value & operator = (const InitialUEMessage_IEs_Value &);
    int operator == (const InitialUEMessage_IEs_Value &) const;
    int operator != (const InitialUEMessage_IEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID();
    const ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID() const;
    void set_ENB_UE_S1AP_ID(const ENB_UE_S1AP_ID &);
    ENB_UE_S1AP_ID *release_ENB_UE_S1AP_ID();
    void set_ENB_UE_S1AP_ID(ENB_UE_S1AP_ID *);

    NAS_PDU *get_NAS_PDU();
    const NAS_PDU *get_NAS_PDU() const;
    void set_NAS_PDU(const NAS_PDU &);
    NAS_PDU *release_NAS_PDU();
    void set_NAS_PDU(NAS_PDU *);

    TAI *get_TAI();
    const TAI *get_TAI() const;
    void set_TAI(const TAI &);
    TAI *release_TAI();
    void set_TAI(TAI *);

    EUTRAN_CGI *get_EUTRAN_CGI();
    const EUTRAN_CGI *get_EUTRAN_CGI() const;
    void set_EUTRAN_CGI(const EUTRAN_CGI &);
    EUTRAN_CGI *release_EUTRAN_CGI();
    void set_EUTRAN_CGI(EUTRAN_CGI *);

    RRC_Establishment_Cause *get_RRC_Establishment_Cause();
    const RRC_Establishment_Cause *get_RRC_Establishment_Cause() const;
    void set_RRC_Establishment_Cause(const RRC_Establishment_Cause &);
    RRC_Establishment_Cause *release_RRC_Establishment_Cause();
    void set_RRC_Establishment_Cause(RRC_Establishment_Cause *);

    S_TMSI *get_S_TMSI();
    const S_TMSI *get_S_TMSI() const;
    void set_S_TMSI(const S_TMSI &);
    S_TMSI *release_S_TMSI();
    void set_S_TMSI(S_TMSI *);

    CSG_Id *get_CSG_Id();
    const CSG_Id *get_CSG_Id() const;
    void set_CSG_Id(const CSG_Id &);
    CSG_Id *release_CSG_Id();
    void set_CSG_Id(CSG_Id *);

    GUMMEI *get_GUMMEI();
    const GUMMEI *get_GUMMEI() const;
    void set_GUMMEI(const GUMMEI &);
    GUMMEI *release_GUMMEI();
    void set_GUMMEI(GUMMEI *);

    CellAccessMode *get_CellAccessMode();
    const CellAccessMode *get_CellAccessMode() const;
    void set_CellAccessMode(const CellAccessMode &);
    CellAccessMode *release_CellAccessMode();
    void set_CellAccessMode(CellAccessMode *);

    TransportLayerAddress *get_TransportLayerAddress();
    const TransportLayerAddress *get_TransportLayerAddress() const;
    void set_TransportLayerAddress(const TransportLayerAddress &);
    TransportLayerAddress *release_TransportLayerAddress();
    void set_TransportLayerAddress(TransportLayerAddress *);

    RelayNode_Indicator *get_RelayNode_Indicator();
    const RelayNode_Indicator *get_RelayNode_Indicator() const;
    void set_RelayNode_Indicator(const RelayNode_Indicator &);
    RelayNode_Indicator *release_RelayNode_Indicator();
    void set_RelayNode_Indicator(RelayNode_Indicator *);

    GUMMEIType *get_GUMMEIType();
    const GUMMEIType *get_GUMMEIType() const;
    void set_GUMMEIType(const GUMMEIType &);
    GUMMEIType *release_GUMMEIType();
    void set_GUMMEIType(GUMMEIType *);

    TunnelInformation *get_TunnelInformation();
    const TunnelInformation *get_TunnelInformation() const;
    void set_TunnelInformation(const TunnelInformation &);
    TunnelInformation *release_TunnelInformation();
    void set_TunnelInformation(TunnelInformation *);

    LHN_ID *get_LHN_ID();
    const LHN_ID *get_LHN_ID() const;
    void set_LHN_ID(const LHN_ID &);
    LHN_ID *release_LHN_ID();
    void set_LHN_ID(LHN_ID *);

    MME_Group_ID *get_MME_Group_ID();
    const MME_Group_ID *get_MME_Group_ID() const;
    void set_MME_Group_ID(const MME_Group_ID &);
    MME_Group_ID *release_MME_Group_ID();
    void set_MME_Group_ID(MME_Group_ID *);

    UE_Usage_Type *get_UE_Usage_Type();
    const UE_Usage_Type *get_UE_Usage_Type() const;
    void set_UE_Usage_Type(const UE_Usage_Type &);
    UE_Usage_Type *release_UE_Usage_Type();
    void set_UE_Usage_Type(UE_Usage_Type *);

    CE_mode_B_SupportIndicator *get_CE_mode_B_SupportIndicator();
    const CE_mode_B_SupportIndicator *get_CE_mode_B_SupportIndicator() const;
    void set_CE_mode_B_SupportIndicator(const CE_mode_B_SupportIndicator &);
    CE_mode_B_SupportIndicator *release_CE_mode_B_SupportIndicator();
    void set_CE_mode_B_SupportIndicator(CE_mode_B_SupportIndicator *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq65   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef InitialUEMessage_IEs_Value value;

    __seq65();
    __seq65(const __seq65 &);
    __seq65(id, criticality, const value &);

    __seq65 & operator = (const __seq65 &);
    int operator == (const __seq65 &) const;
    int operator != (const __seq65 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC UplinkNASTransport_IEs_Value : public OssConstrainedOpenType
{
public:
    UplinkNASTransport_IEs_Value();
    UplinkNASTransport_IEs_Value(const UplinkNASTransport_IEs_Value &);
    ~UplinkNASTransport_IEs_Value();
    UplinkNASTransport_IEs_Value & operator = (const UplinkNASTransport_IEs_Value &);
    int operator == (const UplinkNASTransport_IEs_Value &) const;
    int operator != (const UplinkNASTransport_IEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    MME_UE_S1AP_ID *get_MME_UE_S1AP_ID();
    const MME_UE_S1AP_ID *get_MME_UE_S1AP_ID() const;
    void set_MME_UE_S1AP_ID(const MME_UE_S1AP_ID &);
    MME_UE_S1AP_ID *release_MME_UE_S1AP_ID();
    void set_MME_UE_S1AP_ID(MME_UE_S1AP_ID *);

    ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID();
    const ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID() const;
    void set_ENB_UE_S1AP_ID(const ENB_UE_S1AP_ID &);
    ENB_UE_S1AP_ID *release_ENB_UE_S1AP_ID();
    void set_ENB_UE_S1AP_ID(ENB_UE_S1AP_ID *);

    NAS_PDU *get_NAS_PDU();
    const NAS_PDU *get_NAS_PDU() const;
    void set_NAS_PDU(const NAS_PDU &);
    NAS_PDU *release_NAS_PDU();
    void set_NAS_PDU(NAS_PDU *);

    EUTRAN_CGI *get_EUTRAN_CGI();
    const EUTRAN_CGI *get_EUTRAN_CGI() const;
    void set_EUTRAN_CGI(const EUTRAN_CGI &);
    EUTRAN_CGI *release_EUTRAN_CGI();
    void set_EUTRAN_CGI(EUTRAN_CGI *);

    TAI *get_TAI();
    const TAI *get_TAI() const;
    void set_TAI(const TAI &);
    TAI *release_TAI();
    void set_TAI(TAI *);

    TransportLayerAddress *get_TransportLayerAddress();
    const TransportLayerAddress *get_TransportLayerAddress() const;
    void set_TransportLayerAddress(const TransportLayerAddress &);
    TransportLayerAddress *release_TransportLayerAddress();
    void set_TransportLayerAddress(TransportLayerAddress *);

    LHN_ID *get_LHN_ID();
    const LHN_ID *get_LHN_ID() const;
    void set_LHN_ID(const LHN_ID &);
    LHN_ID *release_LHN_ID();
    void set_LHN_ID(LHN_ID *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq66   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef UplinkNASTransport_IEs_Value value;

    __seq66();
    __seq66(const __seq66 &);
    __seq66(id, criticality, const value &);

    __seq66 & operator = (const __seq66 &);
    int operator == (const __seq66 &) const;
    int operator != (const __seq66 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC NASNonDeliveryIndication_IEs_Value : public OssConstrainedOpenType
{
public:
    NASNonDeliveryIndication_IEs_Value();
    NASNonDeliveryIndication_IEs_Value(const NASNonDeliveryIndication_IEs_Value &);
    ~NASNonDeliveryIndication_IEs_Value();
    NASNonDeliveryIndication_IEs_Value & operator = (const NASNonDeliveryIndication_IEs_Value &);
    int operator == (const NASNonDeliveryIndication_IEs_Value &) const;
    int operator != (const NASNonDeliveryIndication_IEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    MME_UE_S1AP_ID *get_MME_UE_S1AP_ID();
    const MME_UE_S1AP_ID *get_MME_UE_S1AP_ID() const;
    void set_MME_UE_S1AP_ID(const MME_UE_S1AP_ID &);
    MME_UE_S1AP_ID *release_MME_UE_S1AP_ID();
    void set_MME_UE_S1AP_ID(MME_UE_S1AP_ID *);

    ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID();
    const ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID() const;
    void set_ENB_UE_S1AP_ID(const ENB_UE_S1AP_ID &);
    ENB_UE_S1AP_ID *release_ENB_UE_S1AP_ID();
    void set_ENB_UE_S1AP_ID(ENB_UE_S1AP_ID *);

    NAS_PDU *get_NAS_PDU();
    const NAS_PDU *get_NAS_PDU() const;
    void set_NAS_PDU(const NAS_PDU &);
    NAS_PDU *release_NAS_PDU();
    void set_NAS_PDU(NAS_PDU *);

    Cause *get_Cause();
    const Cause *get_Cause() const;
    void set_Cause(const Cause &);
    Cause *release_Cause();
    void set_Cause(Cause *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq67   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef NASNonDeliveryIndication_IEs_Value value;

    __seq67();
    __seq67(const __seq67 &);
    __seq67(id, criticality, const value &);

    __seq67 & operator = (const __seq67 &);
    int operator == (const __seq67 &) const;
    int operator != (const __seq67 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC Additional_GUTI   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef GUMMEI gUMMEI;
    typedef OssString m_TMSI;
    typedef __shared2 iE_Extensions;

    Additional_GUTI();
    Additional_GUTI(const Additional_GUTI &);
    Additional_GUTI(const gUMMEI &, const m_TMSI &, const iE_Extensions &);
    Additional_GUTI(const gUMMEI &, const m_TMSI &);

    Additional_GUTI & operator = (const Additional_GUTI &);
    int operator == (const Additional_GUTI &) const;
    int operator != (const Additional_GUTI &) const;

    gUMMEI & get_gUMMEI();
    const gUMMEI & get_gUMMEI() const;
    void set_gUMMEI(const gUMMEI &);

    m_TMSI & get_m_TMSI();
    const m_TMSI & get_m_TMSI() const;
    void set_m_TMSI(const m_TMSI &);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    gUMMEI gUMMEI_field;
    m_TMSI m_TMSI_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC RerouteNASRequest_IEs_Value : public OssConstrainedOpenType
{
public:
    RerouteNASRequest_IEs_Value();
    RerouteNASRequest_IEs_Value(const RerouteNASRequest_IEs_Value &);
    ~RerouteNASRequest_IEs_Value();
    RerouteNASRequest_IEs_Value & operator = (const RerouteNASRequest_IEs_Value &);
    int operator == (const RerouteNASRequest_IEs_Value &) const;
    int operator != (const RerouteNASRequest_IEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID();
    const ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID() const;
    void set_ENB_UE_S1AP_ID(const ENB_UE_S1AP_ID &);
    ENB_UE_S1AP_ID *release_ENB_UE_S1AP_ID();
    void set_ENB_UE_S1AP_ID(ENB_UE_S1AP_ID *);

    MME_UE_S1AP_ID *get_MME_UE_S1AP_ID();
    const MME_UE_S1AP_ID *get_MME_UE_S1AP_ID() const;
    void set_MME_UE_S1AP_ID(const MME_UE_S1AP_ID &);
    MME_UE_S1AP_ID *release_MME_UE_S1AP_ID();
    void set_MME_UE_S1AP_ID(MME_UE_S1AP_ID *);

    RerouteNASRequest_IEs_TYPE *get_RerouteNASRequest_IEs_TYPE();
    const RerouteNASRequest_IEs_TYPE *get_RerouteNASRequest_IEs_TYPE() const;
    void set_RerouteNASRequest_IEs_TYPE(const RerouteNASRequest_IEs_TYPE &);
    RerouteNASRequest_IEs_TYPE *release_RerouteNASRequest_IEs_TYPE();
    void set_RerouteNASRequest_IEs_TYPE(RerouteNASRequest_IEs_TYPE *);

    MME_Group_ID *get_MME_Group_ID();
    const MME_Group_ID *get_MME_Group_ID() const;
    void set_MME_Group_ID(const MME_Group_ID &);
    MME_Group_ID *release_MME_Group_ID();
    void set_MME_Group_ID(MME_Group_ID *);

    Additional_GUTI *get_Additional_GUTI();
    const Additional_GUTI *get_Additional_GUTI() const;
    void set_Additional_GUTI(const Additional_GUTI &);
    Additional_GUTI *release_Additional_GUTI();
    void set_Additional_GUTI(Additional_GUTI *);

    UE_Usage_Type *get_UE_Usage_Type();
    const UE_Usage_Type *get_UE_Usage_Type() const;
    void set_UE_Usage_Type(const UE_Usage_Type &);
    UE_Usage_Type *release_UE_Usage_Type();
    void set_UE_Usage_Type(UE_Usage_Type *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq68;

class OSS_PUBLIC __seqof54 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq68 component;

    __seqof54();
    __seqof54(const __seqof54 &);
    ~__seqof54();

    __seqof54 & operator = (const __seqof54 &);
    int operator == (const __seqof54 &) const;
    int operator != (const __seqof54 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof54 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof54 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof54 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC RerouteNASRequest   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __seqof54 protocolIEs;

    RerouteNASRequest();
    RerouteNASRequest(const RerouteNASRequest &);
    RerouteNASRequest(const protocolIEs &);

    RerouteNASRequest & operator = (const RerouteNASRequest &);
    int operator == (const RerouteNASRequest &) const;
    int operator != (const RerouteNASRequest &) const;

    protocolIEs & get_protocolIEs();
    const protocolIEs & get_protocolIEs() const;
    void set_protocolIEs(const protocolIEs &);
private:
    protocolIEs protocolIEs_field;
};

class OSS_PUBLIC __seq68   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef RerouteNASRequest_IEs_Value value;

    __seq68();
    __seq68(const __seq68 &);
    __seq68(id, criticality, const value &);

    __seq68 & operator = (const __seq68 &);
    int operator == (const __seq68 &) const;
    int operator != (const __seq68 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC __shared15;

class OSS_PUBLIC __shared16 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __shared15 component;

    __shared16();
    __shared16(const __shared16 &);
    ~__shared16();

    __shared16 & operator = (const __shared16 &);
    int operator == (const __shared16 &) const;
    int operator != (const __shared16 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__shared16 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __shared16 *);

    int remove_front();
    int remove_after(OssIndex);

    __shared16 *extract_after(OssIndex, OssIndex);
};

typedef __shared16 UE_associatedLogicalS1_ConnectionListRes;

class OSS_PUBLIC ResetType  : public OssChoice   /* CHOICE */
{
public:
    enum Id {
	unselected,
	s1_Interface_chosen = 1,
	partOfS1_Interface_chosen = 2
    };
    typedef enum ResetAll s1_Interface;
    typedef __shared16 partOfS1_Interface;

    ResetType();
    ResetType(const ResetType &);
    ~ResetType();

    ResetType & operator = (const ResetType &);
    int operator == (const ResetType &) const;
    int operator != (const ResetType &) const;

    s1_Interface *get_s1_Interface();
    const s1_Interface *get_s1_Interface() const;
    void set_s1_Interface(s1_Interface);

    partOfS1_Interface *get_partOfS1_Interface();
    const partOfS1_Interface *get_partOfS1_Interface() const;
    void set_partOfS1_Interface(const partOfS1_Interface &);
private:
    union {
	s1_Interface s1_Interface_field;
	void *partOfS1_Interface_field;
    };
    void cleanup();
};

class OSS_PUBLIC ResetIEs_Value : public OssConstrainedOpenType
{
public:
    ResetIEs_Value();
    ResetIEs_Value(const ResetIEs_Value &);
    ~ResetIEs_Value();
    ResetIEs_Value & operator = (const ResetIEs_Value &);
    int operator == (const ResetIEs_Value &) const;
    int operator != (const ResetIEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    Cause *get_Cause();
    const Cause *get_Cause() const;
    void set_Cause(const Cause &);
    Cause *release_Cause();
    void set_Cause(Cause *);

    ResetType *get_ResetType();
    const ResetType *get_ResetType() const;
    void set_ResetType(const ResetType &);
    ResetType *release_ResetType();
    void set_ResetType(ResetType *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq69   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef ResetIEs_Value value;

    __seq69();
    __seq69(const __seq69 &);
    __seq69(id, criticality, const value &);

    __seq69 & operator = (const __seq69 &);
    int operator == (const __seq69 &) const;
    int operator != (const __seq69 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC UE_associatedLogicalS1_ConnectionItem   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 mME_UE_S1AP_ID;
    typedef OSS_UINT32 eNB_UE_S1AP_ID;
    typedef __shared2 iE_Extensions;

    UE_associatedLogicalS1_ConnectionItem();
    UE_associatedLogicalS1_ConnectionItem(const UE_associatedLogicalS1_ConnectionItem &);
    UE_associatedLogicalS1_ConnectionItem(mME_UE_S1AP_ID, eNB_UE_S1AP_ID, const iE_Extensions &);

    UE_associatedLogicalS1_ConnectionItem & operator = (const UE_associatedLogicalS1_ConnectionItem &);
    int operator == (const UE_associatedLogicalS1_ConnectionItem &) const;
    int operator != (const UE_associatedLogicalS1_ConnectionItem &) const;

    mME_UE_S1AP_ID *get_mME_UE_S1AP_ID();
    const mME_UE_S1AP_ID *get_mME_UE_S1AP_ID() const;
    void set_mME_UE_S1AP_ID(mME_UE_S1AP_ID);
    int mME_UE_S1AP_ID_is_present() const;
    void omit_mME_UE_S1AP_ID();

    eNB_UE_S1AP_ID *get_eNB_UE_S1AP_ID();
    const eNB_UE_S1AP_ID *get_eNB_UE_S1AP_ID() const;
    void set_eNB_UE_S1AP_ID(eNB_UE_S1AP_ID);
    int eNB_UE_S1AP_ID_is_present() const;
    void omit_eNB_UE_S1AP_ID();

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    mME_UE_S1AP_ID mME_UE_S1AP_ID_field;
    eNB_UE_S1AP_ID eNB_UE_S1AP_ID_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC UE_associatedLogicalS1_ConnectionItemRes_Value : public OssConstrainedOpenType
{
public:
    UE_associatedLogicalS1_ConnectionItemRes_Value();
    UE_associatedLogicalS1_ConnectionItemRes_Value(const UE_associatedLogicalS1_ConnectionItemRes_Value &);
    ~UE_associatedLogicalS1_ConnectionItemRes_Value();
    UE_associatedLogicalS1_ConnectionItemRes_Value & operator = (const UE_associatedLogicalS1_ConnectionItemRes_Value &);
    int operator == (const UE_associatedLogicalS1_ConnectionItemRes_Value &) const;
    int operator != (const UE_associatedLogicalS1_ConnectionItemRes_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    UE_associatedLogicalS1_ConnectionItem *get_UE_associatedLogicalS1_ConnectionItem();
    const UE_associatedLogicalS1_ConnectionItem *get_UE_associatedLogicalS1_ConnectionItem() const;
    void set_UE_associatedLogicalS1_ConnectionItem(const UE_associatedLogicalS1_ConnectionItem &);
    UE_associatedLogicalS1_ConnectionItem *release_UE_associatedLogicalS1_ConnectionItem();
    void set_UE_associatedLogicalS1_ConnectionItem(UE_associatedLogicalS1_ConnectionItem *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __shared15   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef UE_associatedLogicalS1_ConnectionItemRes_Value value;

    __shared15();
    __shared15(const __shared15 &);
    __shared15(id, criticality, const value &);

    __shared15 & operator = (const __shared15 &);
    int operator == (const __shared15 &) const;
    int operator != (const __shared15 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

typedef __shared16 UE_associatedLogicalS1_ConnectionListResAck;

class OSS_PUBLIC ResetAcknowledgeIEs_Value : public OssConstrainedOpenType
{
public:
    ResetAcknowledgeIEs_Value();
    ResetAcknowledgeIEs_Value(const ResetAcknowledgeIEs_Value &);
    ~ResetAcknowledgeIEs_Value();
    ResetAcknowledgeIEs_Value & operator = (const ResetAcknowledgeIEs_Value &);
    int operator == (const ResetAcknowledgeIEs_Value &) const;
    int operator != (const ResetAcknowledgeIEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    __shared16 *get_UE_associatedLogicalS1_ConnectionListResAck();
    const __shared16 *get_UE_associatedLogicalS1_ConnectionListResAck() const;
    void set_UE_associatedLogicalS1_ConnectionListResAck(const __shared16 &);
    __shared16 *release_UE_associatedLogicalS1_ConnectionListResAck();
    void set_UE_associatedLogicalS1_ConnectionListResAck(__shared16 *);

    CriticalityDiagnostics *get_CriticalityDiagnostics();
    const CriticalityDiagnostics *get_CriticalityDiagnostics() const;
    void set_CriticalityDiagnostics(const CriticalityDiagnostics &);
    CriticalityDiagnostics *release_CriticalityDiagnostics();
    void set_CriticalityDiagnostics(CriticalityDiagnostics *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq71   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef ResetAcknowledgeIEs_Value value;

    __seq71();
    __seq71(const __seq71 &);
    __seq71(id, criticality, const value &);

    __seq71 & operator = (const __seq71 &);
    int operator == (const __seq71 &) const;
    int operator != (const __seq71 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC SupportedTAs_Item;

class OSS_PUBLIC SupportedTAs : public OssList  /* SEQUENCE OF */
{
public:
    typedef SupportedTAs_Item component;

    SupportedTAs();
    SupportedTAs(const SupportedTAs &);
    ~SupportedTAs();

    SupportedTAs & operator = (const SupportedTAs &);
    int operator == (const SupportedTAs &) const;
    int operator != (const SupportedTAs &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(SupportedTAs *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, SupportedTAs *);

    int remove_front();
    int remove_after(OssIndex);

    SupportedTAs *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC S1SetupRequestIEs_Value : public OssConstrainedOpenType
{
public:
    S1SetupRequestIEs_Value();
    S1SetupRequestIEs_Value(const S1SetupRequestIEs_Value &);
    ~S1SetupRequestIEs_Value();
    S1SetupRequestIEs_Value & operator = (const S1SetupRequestIEs_Value &);
    int operator == (const S1SetupRequestIEs_Value &) const;
    int operator != (const S1SetupRequestIEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    Global_ENB_ID *get_Global_ENB_ID();
    const Global_ENB_ID *get_Global_ENB_ID() const;
    void set_Global_ENB_ID(const Global_ENB_ID &);
    Global_ENB_ID *release_Global_ENB_ID();
    void set_Global_ENB_ID(Global_ENB_ID *);

    ENBname *get_ENBname();
    const ENBname *get_ENBname() const;
    void set_ENBname(const ENBname &);
    ENBname *release_ENBname();
    void set_ENBname(ENBname *);

    SupportedTAs *get_SupportedTAs();
    const SupportedTAs *get_SupportedTAs() const;
    void set_SupportedTAs(const SupportedTAs &);
    SupportedTAs *release_SupportedTAs();
    void set_SupportedTAs(SupportedTAs *);

    PagingDRX *get_PagingDRX();
    const PagingDRX *get_PagingDRX() const;
    void set_PagingDRX(const PagingDRX &);
    PagingDRX *release_PagingDRX();
    void set_PagingDRX(PagingDRX *);

    CSG_IdList *get_CSG_IdList();
    const CSG_IdList *get_CSG_IdList() const;
    void set_CSG_IdList(const CSG_IdList &);
    CSG_IdList *release_CSG_IdList();
    void set_CSG_IdList(CSG_IdList *);

    UE_RetentionInformation *get_UE_RetentionInformation();
    const UE_RetentionInformation *get_UE_RetentionInformation() const;
    void set_UE_RetentionInformation(const UE_RetentionInformation &);
    UE_RetentionInformation *release_UE_RetentionInformation();
    void set_UE_RetentionInformation(UE_RetentionInformation *);

    NB_IoT_DefaultPagingDRX *get_NB_IoT_DefaultPagingDRX();
    const NB_IoT_DefaultPagingDRX *get_NB_IoT_DefaultPagingDRX() const;
    void set_NB_IoT_DefaultPagingDRX(const NB_IoT_DefaultPagingDRX &);
    NB_IoT_DefaultPagingDRX *release_NB_IoT_DefaultPagingDRX();
    void set_NB_IoT_DefaultPagingDRX(NB_IoT_DefaultPagingDRX *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq74   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef S1SetupRequestIEs_Value value;

    __seq74();
    __seq74(const __seq74 &);
    __seq74(id, criticality, const value &);

    __seq74 & operator = (const __seq74 &);
    int operator == (const __seq74 &) const;
    int operator != (const __seq74 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC ServedGUMMEIsItem;

class OSS_PUBLIC ServedGUMMEIs : public OssList  /* SEQUENCE OF */
{
public:
    typedef ServedGUMMEIsItem component;

    ServedGUMMEIs();
    ServedGUMMEIs(const ServedGUMMEIs &);
    ~ServedGUMMEIs();

    ServedGUMMEIs & operator = (const ServedGUMMEIs &);
    int operator == (const ServedGUMMEIs &) const;
    int operator != (const ServedGUMMEIs &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(ServedGUMMEIs *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, ServedGUMMEIs *);

    int remove_front();
    int remove_after(OssIndex);

    ServedGUMMEIs *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC S1SetupResponseIEs_Value : public OssConstrainedOpenType
{
public:
    S1SetupResponseIEs_Value();
    S1SetupResponseIEs_Value(const S1SetupResponseIEs_Value &);
    ~S1SetupResponseIEs_Value();
    S1SetupResponseIEs_Value & operator = (const S1SetupResponseIEs_Value &);
    int operator == (const S1SetupResponseIEs_Value &) const;
    int operator != (const S1SetupResponseIEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    MMEname *get_MMEname();
    const MMEname *get_MMEname() const;
    void set_MMEname(const MMEname &);
    MMEname *release_MMEname();
    void set_MMEname(MMEname *);

    ServedGUMMEIs *get_ServedGUMMEIs();
    const ServedGUMMEIs *get_ServedGUMMEIs() const;
    void set_ServedGUMMEIs(const ServedGUMMEIs &);
    ServedGUMMEIs *release_ServedGUMMEIs();
    void set_ServedGUMMEIs(ServedGUMMEIs *);

    RelativeMMECapacity *get_RelativeMMECapacity();
    const RelativeMMECapacity *get_RelativeMMECapacity() const;
    void set_RelativeMMECapacity(const RelativeMMECapacity &);
    RelativeMMECapacity *release_RelativeMMECapacity();
    void set_RelativeMMECapacity(RelativeMMECapacity *);

    MMERelaySupportIndicator *get_MMERelaySupportIndicator();
    const MMERelaySupportIndicator *get_MMERelaySupportIndicator() const;
    void set_MMERelaySupportIndicator(const MMERelaySupportIndicator &);
    MMERelaySupportIndicator *release_MMERelaySupportIndicator();
    void set_MMERelaySupportIndicator(MMERelaySupportIndicator *);

    CriticalityDiagnostics *get_CriticalityDiagnostics();
    const CriticalityDiagnostics *get_CriticalityDiagnostics() const;
    void set_CriticalityDiagnostics(const CriticalityDiagnostics &);
    CriticalityDiagnostics *release_CriticalityDiagnostics();
    void set_CriticalityDiagnostics(CriticalityDiagnostics *);

    UE_RetentionInformation *get_UE_RetentionInformation();
    const UE_RetentionInformation *get_UE_RetentionInformation() const;
    void set_UE_RetentionInformation(const UE_RetentionInformation &);
    UE_RetentionInformation *release_UE_RetentionInformation();
    void set_UE_RetentionInformation(UE_RetentionInformation *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq75   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef S1SetupResponseIEs_Value value;

    __seq75();
    __seq75(const __seq75 &);
    __seq75(id, criticality, const value &);

    __seq75 & operator = (const __seq75 &);
    int operator == (const __seq75 &) const;
    int operator != (const __seq75 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC S1SetupFailureIEs_Value : public OssConstrainedOpenType
{
public:
    S1SetupFailureIEs_Value();
    S1SetupFailureIEs_Value(const S1SetupFailureIEs_Value &);
    ~S1SetupFailureIEs_Value();
    S1SetupFailureIEs_Value & operator = (const S1SetupFailureIEs_Value &);
    int operator == (const S1SetupFailureIEs_Value &) const;
    int operator != (const S1SetupFailureIEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    Cause *get_Cause();
    const Cause *get_Cause() const;
    void set_Cause(const Cause &);
    Cause *release_Cause();
    void set_Cause(Cause *);

    TimeToWait *get_TimeToWait();
    const TimeToWait *get_TimeToWait() const;
    void set_TimeToWait(const TimeToWait &);
    TimeToWait *release_TimeToWait();
    void set_TimeToWait(TimeToWait *);

    CriticalityDiagnostics *get_CriticalityDiagnostics();
    const CriticalityDiagnostics *get_CriticalityDiagnostics() const;
    void set_CriticalityDiagnostics(const CriticalityDiagnostics &);
    CriticalityDiagnostics *release_CriticalityDiagnostics();
    void set_CriticalityDiagnostics(CriticalityDiagnostics *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __shared48   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef S1SetupFailureIEs_Value value;

    __shared48();
    __shared48(const __shared48 &);
    __shared48(id, criticality, const value &);

    __shared48 & operator = (const __shared48 &);
    int operator == (const __shared48 &) const;
    int operator != (const __shared48 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC ENBConfigurationUpdateIEs_Value : public OssConstrainedOpenType
{
public:
    ENBConfigurationUpdateIEs_Value();
    ENBConfigurationUpdateIEs_Value(const ENBConfigurationUpdateIEs_Value &);
    ~ENBConfigurationUpdateIEs_Value();
    ENBConfigurationUpdateIEs_Value & operator = (const ENBConfigurationUpdateIEs_Value &);
    int operator == (const ENBConfigurationUpdateIEs_Value &) const;
    int operator != (const ENBConfigurationUpdateIEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    ENBname *get_ENBname();
    const ENBname *get_ENBname() const;
    void set_ENBname(const ENBname &);
    ENBname *release_ENBname();
    void set_ENBname(ENBname *);

    SupportedTAs *get_SupportedTAs();
    const SupportedTAs *get_SupportedTAs() const;
    void set_SupportedTAs(const SupportedTAs &);
    SupportedTAs *release_SupportedTAs();
    void set_SupportedTAs(SupportedTAs *);

    CSG_IdList *get_CSG_IdList();
    const CSG_IdList *get_CSG_IdList() const;
    void set_CSG_IdList(const CSG_IdList &);
    CSG_IdList *release_CSG_IdList();
    void set_CSG_IdList(CSG_IdList *);

    PagingDRX *get_PagingDRX();
    const PagingDRX *get_PagingDRX() const;
    void set_PagingDRX(const PagingDRX &);
    PagingDRX *release_PagingDRX();
    void set_PagingDRX(PagingDRX *);

    NB_IoT_DefaultPagingDRX *get_NB_IoT_DefaultPagingDRX();
    const NB_IoT_DefaultPagingDRX *get_NB_IoT_DefaultPagingDRX() const;
    void set_NB_IoT_DefaultPagingDRX(const NB_IoT_DefaultPagingDRX &);
    NB_IoT_DefaultPagingDRX *release_NB_IoT_DefaultPagingDRX();
    void set_NB_IoT_DefaultPagingDRX(NB_IoT_DefaultPagingDRX *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq77   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef ENBConfigurationUpdateIEs_Value value;

    __seq77();
    __seq77(const __seq77 &);
    __seq77(id, criticality, const value &);

    __seq77 & operator = (const __seq77 &);
    int operator == (const __seq77 &) const;
    int operator != (const __seq77 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC ENBConfigurationUpdateAcknowledgeIEs_Value : public OssConstrainedOpenType
{
public:
    ENBConfigurationUpdateAcknowledgeIEs_Value();
    ENBConfigurationUpdateAcknowledgeIEs_Value(const ENBConfigurationUpdateAcknowledgeIEs_Value &);
    ~ENBConfigurationUpdateAcknowledgeIEs_Value();
    ENBConfigurationUpdateAcknowledgeIEs_Value & operator = (const ENBConfigurationUpdateAcknowledgeIEs_Value &);
    int operator == (const ENBConfigurationUpdateAcknowledgeIEs_Value &) const;
    int operator != (const ENBConfigurationUpdateAcknowledgeIEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    CriticalityDiagnostics *get_CriticalityDiagnostics();
    const CriticalityDiagnostics *get_CriticalityDiagnostics() const;
    void set_CriticalityDiagnostics(const CriticalityDiagnostics &);
    CriticalityDiagnostics *release_CriticalityDiagnostics();
    void set_CriticalityDiagnostics(CriticalityDiagnostics *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __shared41   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef ENBConfigurationUpdateAcknowledgeIEs_Value value;

    __shared41();
    __shared41(const __shared41 &);
    __shared41(id, criticality, const value &);

    __shared41 & operator = (const __shared41 &);
    int operator == (const __shared41 &) const;
    int operator != (const __shared41 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC MMEConfigurationUpdateIEs_Value : public OssConstrainedOpenType
{
public:
    MMEConfigurationUpdateIEs_Value();
    MMEConfigurationUpdateIEs_Value(const MMEConfigurationUpdateIEs_Value &);
    ~MMEConfigurationUpdateIEs_Value();
    MMEConfigurationUpdateIEs_Value & operator = (const MMEConfigurationUpdateIEs_Value &);
    int operator == (const MMEConfigurationUpdateIEs_Value &) const;
    int operator != (const MMEConfigurationUpdateIEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    MMEname *get_MMEname();
    const MMEname *get_MMEname() const;
    void set_MMEname(const MMEname &);
    MMEname *release_MMEname();
    void set_MMEname(MMEname *);

    ServedGUMMEIs *get_ServedGUMMEIs();
    const ServedGUMMEIs *get_ServedGUMMEIs() const;
    void set_ServedGUMMEIs(const ServedGUMMEIs &);
    ServedGUMMEIs *release_ServedGUMMEIs();
    void set_ServedGUMMEIs(ServedGUMMEIs *);

    RelativeMMECapacity *get_RelativeMMECapacity();
    const RelativeMMECapacity *get_RelativeMMECapacity() const;
    void set_RelativeMMECapacity(const RelativeMMECapacity &);
    RelativeMMECapacity *release_RelativeMMECapacity();
    void set_RelativeMMECapacity(RelativeMMECapacity *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq80   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef MMEConfigurationUpdateIEs_Value value;

    __seq80();
    __seq80(const __seq80 &);
    __seq80(id, criticality, const value &);

    __seq80 & operator = (const __seq80 &);
    int operator == (const __seq80 &) const;
    int operator != (const __seq80 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC DownlinkS1cdma2000tunnellingIEs_Value : public OssConstrainedOpenType
{
public:
    DownlinkS1cdma2000tunnellingIEs_Value();
    DownlinkS1cdma2000tunnellingIEs_Value(const DownlinkS1cdma2000tunnellingIEs_Value &);
    ~DownlinkS1cdma2000tunnellingIEs_Value();
    DownlinkS1cdma2000tunnellingIEs_Value & operator = (const DownlinkS1cdma2000tunnellingIEs_Value &);
    int operator == (const DownlinkS1cdma2000tunnellingIEs_Value &) const;
    int operator != (const DownlinkS1cdma2000tunnellingIEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    MME_UE_S1AP_ID *get_MME_UE_S1AP_ID();
    const MME_UE_S1AP_ID *get_MME_UE_S1AP_ID() const;
    void set_MME_UE_S1AP_ID(const MME_UE_S1AP_ID &);
    MME_UE_S1AP_ID *release_MME_UE_S1AP_ID();
    void set_MME_UE_S1AP_ID(MME_UE_S1AP_ID *);

    ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID();
    const ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID() const;
    void set_ENB_UE_S1AP_ID(const ENB_UE_S1AP_ID &);
    ENB_UE_S1AP_ID *release_ENB_UE_S1AP_ID();
    void set_ENB_UE_S1AP_ID(ENB_UE_S1AP_ID *);

    E_RABSubjecttoDataForwardingList *get_E_RABSubjecttoDataForwardingList();
    const E_RABSubjecttoDataForwardingList *get_E_RABSubjecttoDataForwardingList() const;
    void set_E_RABSubjecttoDataForwardingList(const E_RABSubjecttoDataForwardingList &);
    E_RABSubjecttoDataForwardingList *release_E_RABSubjecttoDataForwardingList();
    void set_E_RABSubjecttoDataForwardingList(E_RABSubjecttoDataForwardingList *);

    Cdma2000HOStatus *get_Cdma2000HOStatus();
    const Cdma2000HOStatus *get_Cdma2000HOStatus() const;
    void set_Cdma2000HOStatus(const Cdma2000HOStatus &);
    Cdma2000HOStatus *release_Cdma2000HOStatus();
    void set_Cdma2000HOStatus(Cdma2000HOStatus *);

    Cdma2000RATType *get_Cdma2000RATType();
    const Cdma2000RATType *get_Cdma2000RATType() const;
    void set_Cdma2000RATType(const Cdma2000RATType &);
    Cdma2000RATType *release_Cdma2000RATType();
    void set_Cdma2000RATType(Cdma2000RATType *);

    Cdma2000PDU *get_Cdma2000PDU();
    const Cdma2000PDU *get_Cdma2000PDU() const;
    void set_Cdma2000PDU(const Cdma2000PDU &);
    Cdma2000PDU *release_Cdma2000PDU();
    void set_Cdma2000PDU(Cdma2000PDU *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq83   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef DownlinkS1cdma2000tunnellingIEs_Value value;

    __seq83();
    __seq83(const __seq83 &);
    __seq83(id, criticality, const value &);

    __seq83 & operator = (const __seq83 &);
    int operator == (const __seq83 &) const;
    int operator != (const __seq83 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC Cdma2000OneXSRVCCInfo   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OssString cdma2000OneXMEID;
    typedef OssString cdma2000OneXMSI;
    typedef OssString cdma2000OneXPilot;
    typedef __shared2 iE_Extensions;

    Cdma2000OneXSRVCCInfo();
    Cdma2000OneXSRVCCInfo(const Cdma2000OneXSRVCCInfo &);
    Cdma2000OneXSRVCCInfo(const cdma2000OneXMEID &, const cdma2000OneXMSI &, const cdma2000OneXPilot &, 
	const iE_Extensions &);
    Cdma2000OneXSRVCCInfo(const cdma2000OneXMEID &, const cdma2000OneXMSI &, const cdma2000OneXPilot &);

    Cdma2000OneXSRVCCInfo & operator = (const Cdma2000OneXSRVCCInfo &);
    int operator == (const Cdma2000OneXSRVCCInfo &) const;
    int operator != (const Cdma2000OneXSRVCCInfo &) const;

    cdma2000OneXMEID & get_cdma2000OneXMEID();
    const cdma2000OneXMEID & get_cdma2000OneXMEID() const;
    void set_cdma2000OneXMEID(const cdma2000OneXMEID &);

    cdma2000OneXMSI & get_cdma2000OneXMSI();
    const cdma2000OneXMSI & get_cdma2000OneXMSI() const;
    void set_cdma2000OneXMSI(const cdma2000OneXMSI &);

    cdma2000OneXPilot & get_cdma2000OneXPilot();
    const cdma2000OneXPilot & get_cdma2000OneXPilot() const;
    void set_cdma2000OneXPilot(const cdma2000OneXPilot &);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    cdma2000OneXMEID cdma2000OneXMEID_field;
    cdma2000OneXMSI cdma2000OneXMSI_field;
    cdma2000OneXPilot cdma2000OneXPilot_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC UplinkS1cdma2000tunnellingIEs_Value : public OssConstrainedOpenType
{
public:
    UplinkS1cdma2000tunnellingIEs_Value();
    UplinkS1cdma2000tunnellingIEs_Value(const UplinkS1cdma2000tunnellingIEs_Value &);
    ~UplinkS1cdma2000tunnellingIEs_Value();
    UplinkS1cdma2000tunnellingIEs_Value & operator = (const UplinkS1cdma2000tunnellingIEs_Value &);
    int operator == (const UplinkS1cdma2000tunnellingIEs_Value &) const;
    int operator != (const UplinkS1cdma2000tunnellingIEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    MME_UE_S1AP_ID *get_MME_UE_S1AP_ID();
    const MME_UE_S1AP_ID *get_MME_UE_S1AP_ID() const;
    void set_MME_UE_S1AP_ID(const MME_UE_S1AP_ID &);
    MME_UE_S1AP_ID *release_MME_UE_S1AP_ID();
    void set_MME_UE_S1AP_ID(MME_UE_S1AP_ID *);

    ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID();
    const ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID() const;
    void set_ENB_UE_S1AP_ID(const ENB_UE_S1AP_ID &);
    ENB_UE_S1AP_ID *release_ENB_UE_S1AP_ID();
    void set_ENB_UE_S1AP_ID(ENB_UE_S1AP_ID *);

    Cdma2000RATType *get_Cdma2000RATType();
    const Cdma2000RATType *get_Cdma2000RATType() const;
    void set_Cdma2000RATType(const Cdma2000RATType &);
    Cdma2000RATType *release_Cdma2000RATType();
    void set_Cdma2000RATType(Cdma2000RATType *);

    Cdma2000SectorID *get_Cdma2000SectorID();
    const Cdma2000SectorID *get_Cdma2000SectorID() const;
    void set_Cdma2000SectorID(const Cdma2000SectorID &);
    Cdma2000SectorID *release_Cdma2000SectorID();
    void set_Cdma2000SectorID(Cdma2000SectorID *);

    Cdma2000HORequiredIndication *get_Cdma2000HORequiredIndication();
    const Cdma2000HORequiredIndication *get_Cdma2000HORequiredIndication() const;
    void set_Cdma2000HORequiredIndication(const Cdma2000HORequiredIndication &);
    Cdma2000HORequiredIndication *release_Cdma2000HORequiredIndication();
    void set_Cdma2000HORequiredIndication(Cdma2000HORequiredIndication *);

    Cdma2000OneXSRVCCInfo *get_Cdma2000OneXSRVCCInfo();
    const Cdma2000OneXSRVCCInfo *get_Cdma2000OneXSRVCCInfo() const;
    void set_Cdma2000OneXSRVCCInfo(const Cdma2000OneXSRVCCInfo &);
    Cdma2000OneXSRVCCInfo *release_Cdma2000OneXSRVCCInfo();
    void set_Cdma2000OneXSRVCCInfo(Cdma2000OneXSRVCCInfo *);

    Cdma2000OneXRAND *get_Cdma2000OneXRAND();
    const Cdma2000OneXRAND *get_Cdma2000OneXRAND() const;
    void set_Cdma2000OneXRAND(const Cdma2000OneXRAND &);
    Cdma2000OneXRAND *release_Cdma2000OneXRAND();
    void set_Cdma2000OneXRAND(Cdma2000OneXRAND *);

    Cdma2000PDU *get_Cdma2000PDU();
    const Cdma2000PDU *get_Cdma2000PDU() const;
    void set_Cdma2000PDU(const Cdma2000PDU &);
    Cdma2000PDU *release_Cdma2000PDU();
    void set_Cdma2000PDU(Cdma2000PDU *);

    EUTRANRoundTripDelayEstimationInfo *get_EUTRANRoundTripDelayEstimationInfo();
    const EUTRANRoundTripDelayEstimationInfo *get_EUTRANRoundTripDelayEstimationInfo() const;
    void set_EUTRANRoundTripDelayEstimationInfo(const EUTRANRoundTripDelayEstimationInfo &);
    EUTRANRoundTripDelayEstimationInfo *release_EUTRANRoundTripDelayEstimationInfo();
    void set_EUTRANRoundTripDelayEstimationInfo(EUTRANRoundTripDelayEstimationInfo *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq84   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef UplinkS1cdma2000tunnellingIEs_Value value;

    __seq84();
    __seq84(const __seq84 &);
    __seq84(id, criticality, const value &);

    __seq84 & operator = (const __seq84 &);
    int operator == (const __seq84 &) const;
    int operator != (const __seq84 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC UECapabilityInfoIndicationIEs_Value : public OssConstrainedOpenType
{
public:
    UECapabilityInfoIndicationIEs_Value();
    UECapabilityInfoIndicationIEs_Value(const UECapabilityInfoIndicationIEs_Value &);
    ~UECapabilityInfoIndicationIEs_Value();
    UECapabilityInfoIndicationIEs_Value & operator = (const UECapabilityInfoIndicationIEs_Value &);
    int operator == (const UECapabilityInfoIndicationIEs_Value &) const;
    int operator != (const UECapabilityInfoIndicationIEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    MME_UE_S1AP_ID *get_MME_UE_S1AP_ID();
    const MME_UE_S1AP_ID *get_MME_UE_S1AP_ID() const;
    void set_MME_UE_S1AP_ID(const MME_UE_S1AP_ID &);
    MME_UE_S1AP_ID *release_MME_UE_S1AP_ID();
    void set_MME_UE_S1AP_ID(MME_UE_S1AP_ID *);

    ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID();
    const ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID() const;
    void set_ENB_UE_S1AP_ID(const ENB_UE_S1AP_ID &);
    ENB_UE_S1AP_ID *release_ENB_UE_S1AP_ID();
    void set_ENB_UE_S1AP_ID(ENB_UE_S1AP_ID *);

    UERadioCapability *get_UERadioCapability();
    const UERadioCapability *get_UERadioCapability() const;
    void set_UERadioCapability(const UERadioCapability &);
    UERadioCapability *release_UERadioCapability();
    void set_UERadioCapability(UERadioCapability *);

    UERadioCapabilityForPaging *get_UERadioCapabilityForPaging();
    const UERadioCapabilityForPaging *get_UERadioCapabilityForPaging() const;
    void set_UERadioCapabilityForPaging(const UERadioCapabilityForPaging &);
    UERadioCapabilityForPaging *release_UERadioCapabilityForPaging();
    void set_UERadioCapabilityForPaging(UERadioCapabilityForPaging *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq85   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef UECapabilityInfoIndicationIEs_Value value;

    __seq85();
    __seq85(const __seq85 &);
    __seq85(id, criticality, const value &);

    __seq85 & operator = (const __seq85 &);
    int operator == (const __seq85 &) const;
    int operator != (const __seq85 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC __seq141;

class OSS_PUBLIC Bearers_SubjectToStatusTransferList : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq141 component;

    Bearers_SubjectToStatusTransferList();
    Bearers_SubjectToStatusTransferList(const Bearers_SubjectToStatusTransferList &);
    ~Bearers_SubjectToStatusTransferList();

    Bearers_SubjectToStatusTransferList & operator = (const Bearers_SubjectToStatusTransferList &);
    int operator == (const Bearers_SubjectToStatusTransferList &) const;
    int operator != (const Bearers_SubjectToStatusTransferList &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(Bearers_SubjectToStatusTransferList *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, Bearers_SubjectToStatusTransferList *);

    int remove_front();
    int remove_after(OssIndex);

    Bearers_SubjectToStatusTransferList *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC ENB_StatusTransfer_TransparentContainer   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef Bearers_SubjectToStatusTransferList bearers_SubjectToStatusTransferList;
    typedef __shared2 iE_Extensions;

    ENB_StatusTransfer_TransparentContainer();
    ENB_StatusTransfer_TransparentContainer(const ENB_StatusTransfer_TransparentContainer &);
    ENB_StatusTransfer_TransparentContainer(const bearers_SubjectToStatusTransferList &, 
	const iE_Extensions &);
    ENB_StatusTransfer_TransparentContainer(const bearers_SubjectToStatusTransferList &);

    ENB_StatusTransfer_TransparentContainer & operator = (const ENB_StatusTransfer_TransparentContainer &);
    int operator == (const ENB_StatusTransfer_TransparentContainer &) const;
    int operator != (const ENB_StatusTransfer_TransparentContainer &) const;

    bearers_SubjectToStatusTransferList & get_bearers_SubjectToStatusTransferList();
    const bearers_SubjectToStatusTransferList & get_bearers_SubjectToStatusTransferList() const;
    void set_bearers_SubjectToStatusTransferList(const bearers_SubjectToStatusTransferList &);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    bearers_SubjectToStatusTransferList bearers_SubjectToStatusTransferList_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC ENBStatusTransferIEs_Value : public OssConstrainedOpenType
{
public:
    ENBStatusTransferIEs_Value();
    ENBStatusTransferIEs_Value(const ENBStatusTransferIEs_Value &);
    ~ENBStatusTransferIEs_Value();
    ENBStatusTransferIEs_Value & operator = (const ENBStatusTransferIEs_Value &);
    int operator == (const ENBStatusTransferIEs_Value &) const;
    int operator != (const ENBStatusTransferIEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    MME_UE_S1AP_ID *get_MME_UE_S1AP_ID();
    const MME_UE_S1AP_ID *get_MME_UE_S1AP_ID() const;
    void set_MME_UE_S1AP_ID(const MME_UE_S1AP_ID &);
    MME_UE_S1AP_ID *release_MME_UE_S1AP_ID();
    void set_MME_UE_S1AP_ID(MME_UE_S1AP_ID *);

    ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID();
    const ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID() const;
    void set_ENB_UE_S1AP_ID(const ENB_UE_S1AP_ID &);
    ENB_UE_S1AP_ID *release_ENB_UE_S1AP_ID();
    void set_ENB_UE_S1AP_ID(ENB_UE_S1AP_ID *);

    ENB_StatusTransfer_TransparentContainer *get_ENB_StatusTransfer_TransparentContainer();
    const ENB_StatusTransfer_TransparentContainer *get_ENB_StatusTransfer_TransparentContainer() const;
    void set_ENB_StatusTransfer_TransparentContainer(const ENB_StatusTransfer_TransparentContainer &);
    ENB_StatusTransfer_TransparentContainer *release_ENB_StatusTransfer_TransparentContainer();
    void set_ENB_StatusTransfer_TransparentContainer(ENB_StatusTransfer_TransparentContainer *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __shared22   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef ENBStatusTransferIEs_Value value;

    __shared22();
    __shared22(const __shared22 &);
    __shared22(id, criticality, const value &);

    __shared22 & operator = (const __shared22 &);
    int operator == (const __shared22 &) const;
    int operator != (const __shared22 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC TraceStartIEs_Value : public OssConstrainedOpenType
{
public:
    TraceStartIEs_Value();
    TraceStartIEs_Value(const TraceStartIEs_Value &);
    ~TraceStartIEs_Value();
    TraceStartIEs_Value & operator = (const TraceStartIEs_Value &);
    int operator == (const TraceStartIEs_Value &) const;
    int operator != (const TraceStartIEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    MME_UE_S1AP_ID *get_MME_UE_S1AP_ID();
    const MME_UE_S1AP_ID *get_MME_UE_S1AP_ID() const;
    void set_MME_UE_S1AP_ID(const MME_UE_S1AP_ID &);
    MME_UE_S1AP_ID *release_MME_UE_S1AP_ID();
    void set_MME_UE_S1AP_ID(MME_UE_S1AP_ID *);

    ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID();
    const ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID() const;
    void set_ENB_UE_S1AP_ID(const ENB_UE_S1AP_ID &);
    ENB_UE_S1AP_ID *release_ENB_UE_S1AP_ID();
    void set_ENB_UE_S1AP_ID(ENB_UE_S1AP_ID *);

    TraceActivation *get_TraceActivation();
    const TraceActivation *get_TraceActivation() const;
    void set_TraceActivation(const TraceActivation &);
    TraceActivation *release_TraceActivation();
    void set_TraceActivation(TraceActivation *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq88   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef TraceStartIEs_Value value;

    __seq88();
    __seq88(const __seq88 &);
    __seq88(id, criticality, const value &);

    __seq88 & operator = (const __seq88 &);
    int operator == (const __seq88 &) const;
    int operator != (const __seq88 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC TraceFailureIndicationIEs_Value : public OssConstrainedOpenType
{
public:
    TraceFailureIndicationIEs_Value();
    TraceFailureIndicationIEs_Value(const TraceFailureIndicationIEs_Value &);
    ~TraceFailureIndicationIEs_Value();
    TraceFailureIndicationIEs_Value & operator = (const TraceFailureIndicationIEs_Value &);
    int operator == (const TraceFailureIndicationIEs_Value &) const;
    int operator != (const TraceFailureIndicationIEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    MME_UE_S1AP_ID *get_MME_UE_S1AP_ID();
    const MME_UE_S1AP_ID *get_MME_UE_S1AP_ID() const;
    void set_MME_UE_S1AP_ID(const MME_UE_S1AP_ID &);
    MME_UE_S1AP_ID *release_MME_UE_S1AP_ID();
    void set_MME_UE_S1AP_ID(MME_UE_S1AP_ID *);

    ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID();
    const ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID() const;
    void set_ENB_UE_S1AP_ID(const ENB_UE_S1AP_ID &);
    ENB_UE_S1AP_ID *release_ENB_UE_S1AP_ID();
    void set_ENB_UE_S1AP_ID(ENB_UE_S1AP_ID *);

    E_UTRAN_Trace_ID *get_E_UTRAN_Trace_ID();
    const E_UTRAN_Trace_ID *get_E_UTRAN_Trace_ID() const;
    void set_E_UTRAN_Trace_ID(const E_UTRAN_Trace_ID &);
    E_UTRAN_Trace_ID *release_E_UTRAN_Trace_ID();
    void set_E_UTRAN_Trace_ID(E_UTRAN_Trace_ID *);

    Cause *get_Cause();
    const Cause *get_Cause() const;
    void set_Cause(const Cause &);
    Cause *release_Cause();
    void set_Cause(Cause *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq89   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef TraceFailureIndicationIEs_Value value;

    __seq89();
    __seq89(const __seq89 &);
    __seq89(id, criticality, const value &);

    __seq89 & operator = (const __seq89 &);
    int operator == (const __seq89 &) const;
    int operator != (const __seq89 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC DeactivateTraceIEs_Value : public OssConstrainedOpenType
{
public:
    DeactivateTraceIEs_Value();
    DeactivateTraceIEs_Value(const DeactivateTraceIEs_Value &);
    ~DeactivateTraceIEs_Value();
    DeactivateTraceIEs_Value & operator = (const DeactivateTraceIEs_Value &);
    int operator == (const DeactivateTraceIEs_Value &) const;
    int operator != (const DeactivateTraceIEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    MME_UE_S1AP_ID *get_MME_UE_S1AP_ID();
    const MME_UE_S1AP_ID *get_MME_UE_S1AP_ID() const;
    void set_MME_UE_S1AP_ID(const MME_UE_S1AP_ID &);
    MME_UE_S1AP_ID *release_MME_UE_S1AP_ID();
    void set_MME_UE_S1AP_ID(MME_UE_S1AP_ID *);

    ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID();
    const ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID() const;
    void set_ENB_UE_S1AP_ID(const ENB_UE_S1AP_ID &);
    ENB_UE_S1AP_ID *release_ENB_UE_S1AP_ID();
    void set_ENB_UE_S1AP_ID(ENB_UE_S1AP_ID *);

    E_UTRAN_Trace_ID *get_E_UTRAN_Trace_ID();
    const E_UTRAN_Trace_ID *get_E_UTRAN_Trace_ID() const;
    void set_E_UTRAN_Trace_ID(const E_UTRAN_Trace_ID &);
    E_UTRAN_Trace_ID *release_E_UTRAN_Trace_ID();
    void set_E_UTRAN_Trace_ID(E_UTRAN_Trace_ID *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq90   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef DeactivateTraceIEs_Value value;

    __seq90();
    __seq90(const __seq90 &);
    __seq90(id, criticality, const value &);

    __seq90 & operator = (const __seq90 &);
    int operator == (const __seq90 &) const;
    int operator != (const __seq90 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC CellTrafficTraceIEs_Value : public OssConstrainedOpenType
{
public:
    CellTrafficTraceIEs_Value();
    CellTrafficTraceIEs_Value(const CellTrafficTraceIEs_Value &);
    ~CellTrafficTraceIEs_Value();
    CellTrafficTraceIEs_Value & operator = (const CellTrafficTraceIEs_Value &);
    int operator == (const CellTrafficTraceIEs_Value &) const;
    int operator != (const CellTrafficTraceIEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    MME_UE_S1AP_ID *get_MME_UE_S1AP_ID();
    const MME_UE_S1AP_ID *get_MME_UE_S1AP_ID() const;
    void set_MME_UE_S1AP_ID(const MME_UE_S1AP_ID &);
    MME_UE_S1AP_ID *release_MME_UE_S1AP_ID();
    void set_MME_UE_S1AP_ID(MME_UE_S1AP_ID *);

    ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID();
    const ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID() const;
    void set_ENB_UE_S1AP_ID(const ENB_UE_S1AP_ID &);
    ENB_UE_S1AP_ID *release_ENB_UE_S1AP_ID();
    void set_ENB_UE_S1AP_ID(ENB_UE_S1AP_ID *);

    E_UTRAN_Trace_ID *get_E_UTRAN_Trace_ID();
    const E_UTRAN_Trace_ID *get_E_UTRAN_Trace_ID() const;
    void set_E_UTRAN_Trace_ID(const E_UTRAN_Trace_ID &);
    E_UTRAN_Trace_ID *release_E_UTRAN_Trace_ID();
    void set_E_UTRAN_Trace_ID(E_UTRAN_Trace_ID *);

    EUTRAN_CGI *get_EUTRAN_CGI();
    const EUTRAN_CGI *get_EUTRAN_CGI() const;
    void set_EUTRAN_CGI(const EUTRAN_CGI &);
    EUTRAN_CGI *release_EUTRAN_CGI();
    void set_EUTRAN_CGI(EUTRAN_CGI *);

    TransportLayerAddress *get_TransportLayerAddress();
    const TransportLayerAddress *get_TransportLayerAddress() const;
    void set_TransportLayerAddress(const TransportLayerAddress &);
    TransportLayerAddress *release_TransportLayerAddress();
    void set_TransportLayerAddress(TransportLayerAddress *);

    PrivacyIndicator *get_PrivacyIndicator();
    const PrivacyIndicator *get_PrivacyIndicator() const;
    void set_PrivacyIndicator(const PrivacyIndicator &);
    PrivacyIndicator *release_PrivacyIndicator();
    void set_PrivacyIndicator(PrivacyIndicator *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq91   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef CellTrafficTraceIEs_Value value;

    __seq91();
    __seq91(const __seq91 &);
    __seq91(id, criticality, const value &);

    __seq91 & operator = (const __seq91 &);
    int operator == (const __seq91 &) const;
    int operator != (const __seq91 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC LocationReportingControlIEs_Value : public OssConstrainedOpenType
{
public:
    LocationReportingControlIEs_Value();
    LocationReportingControlIEs_Value(const LocationReportingControlIEs_Value &);
    ~LocationReportingControlIEs_Value();
    LocationReportingControlIEs_Value & operator = (const LocationReportingControlIEs_Value &);
    int operator == (const LocationReportingControlIEs_Value &) const;
    int operator != (const LocationReportingControlIEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    MME_UE_S1AP_ID *get_MME_UE_S1AP_ID();
    const MME_UE_S1AP_ID *get_MME_UE_S1AP_ID() const;
    void set_MME_UE_S1AP_ID(const MME_UE_S1AP_ID &);
    MME_UE_S1AP_ID *release_MME_UE_S1AP_ID();
    void set_MME_UE_S1AP_ID(MME_UE_S1AP_ID *);

    ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID();
    const ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID() const;
    void set_ENB_UE_S1AP_ID(const ENB_UE_S1AP_ID &);
    ENB_UE_S1AP_ID *release_ENB_UE_S1AP_ID();
    void set_ENB_UE_S1AP_ID(ENB_UE_S1AP_ID *);

    RequestType *get_RequestType();
    const RequestType *get_RequestType() const;
    void set_RequestType(const RequestType &);
    RequestType *release_RequestType();
    void set_RequestType(RequestType *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq92   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef LocationReportingControlIEs_Value value;

    __seq92();
    __seq92(const __seq92 &);
    __seq92(id, criticality, const value &);

    __seq92 & operator = (const __seq92 &);
    int operator == (const __seq92 &) const;
    int operator != (const __seq92 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC LocationReportIEs_Value : public OssConstrainedOpenType
{
public:
    LocationReportIEs_Value();
    LocationReportIEs_Value(const LocationReportIEs_Value &);
    ~LocationReportIEs_Value();
    LocationReportIEs_Value & operator = (const LocationReportIEs_Value &);
    int operator == (const LocationReportIEs_Value &) const;
    int operator != (const LocationReportIEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    MME_UE_S1AP_ID *get_MME_UE_S1AP_ID();
    const MME_UE_S1AP_ID *get_MME_UE_S1AP_ID() const;
    void set_MME_UE_S1AP_ID(const MME_UE_S1AP_ID &);
    MME_UE_S1AP_ID *release_MME_UE_S1AP_ID();
    void set_MME_UE_S1AP_ID(MME_UE_S1AP_ID *);

    ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID();
    const ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID() const;
    void set_ENB_UE_S1AP_ID(const ENB_UE_S1AP_ID &);
    ENB_UE_S1AP_ID *release_ENB_UE_S1AP_ID();
    void set_ENB_UE_S1AP_ID(ENB_UE_S1AP_ID *);

    EUTRAN_CGI *get_EUTRAN_CGI();
    const EUTRAN_CGI *get_EUTRAN_CGI() const;
    void set_EUTRAN_CGI(const EUTRAN_CGI &);
    EUTRAN_CGI *release_EUTRAN_CGI();
    void set_EUTRAN_CGI(EUTRAN_CGI *);

    TAI *get_TAI();
    const TAI *get_TAI() const;
    void set_TAI(const TAI &);
    TAI *release_TAI();
    void set_TAI(TAI *);

    RequestType *get_RequestType();
    const RequestType *get_RequestType() const;
    void set_RequestType(const RequestType &);
    RequestType *release_RequestType();
    void set_RequestType(RequestType *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq94   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef LocationReportIEs_Value value;

    __seq94();
    __seq94(const __seq94 &);
    __seq94(id, criticality, const value &);

    __seq94 & operator = (const __seq94 &);
    int operator == (const __seq94 &) const;
    int operator != (const __seq94 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC OverloadResponse  : public OssChoice   /* CHOICE */
{
public:
    enum Id {
	unselected,
	overloadAction_chosen = 1
    };
    typedef enum OverloadAction overloadAction;

    OverloadResponse();
    OverloadResponse(const OverloadResponse &);

    OverloadResponse & operator = (const OverloadResponse &);
    int operator == (const OverloadResponse &) const;
    int operator != (const OverloadResponse &) const;

    overloadAction *get_overloadAction();
    const overloadAction *get_overloadAction() const;
    void set_overloadAction(overloadAction);
private:
    union {
	overloadAction overloadAction_field;
    };
};

class OSS_PUBLIC GUMMEIList : public OssList  /* SEQUENCE OF */
{
public:
    typedef GUMMEI component;

    GUMMEIList();
    GUMMEIList(const GUMMEIList &);
    ~GUMMEIList();

    GUMMEIList & operator = (const GUMMEIList &);
    int operator == (const GUMMEIList &) const;
    int operator != (const GUMMEIList &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(GUMMEIList *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, GUMMEIList *);

    int remove_front();
    int remove_after(OssIndex);

    GUMMEIList *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC OverloadStartIEs_Value : public OssConstrainedOpenType
{
public:
    OverloadStartIEs_Value();
    OverloadStartIEs_Value(const OverloadStartIEs_Value &);
    ~OverloadStartIEs_Value();
    OverloadStartIEs_Value & operator = (const OverloadStartIEs_Value &);
    int operator == (const OverloadStartIEs_Value &) const;
    int operator != (const OverloadStartIEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    OverloadResponse *get_OverloadResponse();
    const OverloadResponse *get_OverloadResponse() const;
    void set_OverloadResponse(const OverloadResponse &);
    OverloadResponse *release_OverloadResponse();
    void set_OverloadResponse(OverloadResponse *);

    GUMMEIList *get_GUMMEIList();
    const GUMMEIList *get_GUMMEIList() const;
    void set_GUMMEIList(const GUMMEIList &);
    GUMMEIList *release_GUMMEIList();
    void set_GUMMEIList(GUMMEIList *);

    TrafficLoadReductionIndication *get_TrafficLoadReductionIndication();
    const TrafficLoadReductionIndication *get_TrafficLoadReductionIndication() const;
    void set_TrafficLoadReductionIndication(const TrafficLoadReductionIndication &);
    TrafficLoadReductionIndication *release_TrafficLoadReductionIndication();
    void set_TrafficLoadReductionIndication(TrafficLoadReductionIndication *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq95   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef OverloadStartIEs_Value value;

    __seq95();
    __seq95(const __seq95 &);
    __seq95(id, criticality, const value &);

    __seq95 & operator = (const __seq95 &);
    int operator == (const __seq95 &) const;
    int operator != (const __seq95 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC OverloadStopIEs_Value : public OssConstrainedOpenType
{
public:
    OverloadStopIEs_Value();
    OverloadStopIEs_Value(const OverloadStopIEs_Value &);
    ~OverloadStopIEs_Value();
    OverloadStopIEs_Value & operator = (const OverloadStopIEs_Value &);
    int operator == (const OverloadStopIEs_Value &) const;
    int operator != (const OverloadStopIEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    GUMMEIList *get_GUMMEIList();
    const GUMMEIList *get_GUMMEIList() const;
    void set_GUMMEIList(const GUMMEIList &);
    GUMMEIList *release_GUMMEIList();
    void set_GUMMEIList(GUMMEIList *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq96   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef OverloadStopIEs_Value value;

    __seq96();
    __seq96(const __seq96 &);
    __seq96(id, criticality, const value &);

    __seq96 & operator = (const __seq96 &);
    int operator == (const __seq96 &) const;
    int operator != (const __seq96 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC __shared5 : public OssList  /* SEQUENCE OF */
{
public:
    typedef EUTRAN_CGI component;

    __shared5();
    __shared5(const __shared5 &);
    ~__shared5();

    __shared5 & operator = (const __shared5 &);
    int operator == (const __shared5 &) const;
    int operator != (const __shared5 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__shared5 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __shared5 *);

    int remove_front();
    int remove_after(OssIndex);

    __shared5 *extract_after(OssIndex, OssIndex);
};

typedef __shared5 CellIdListforMDT;

typedef __shared5 ECGIList;

class OSS_PUBLIC __shared6 : public OssList  /* SEQUENCE OF */
{
public:
    typedef TAI component;

    __shared6();
    __shared6(const __shared6 &);
    ~__shared6();

    __shared6 & operator = (const __shared6 &);
    int operator == (const __shared6 &) const;
    int operator != (const __shared6 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__shared6 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __shared6 *);

    int remove_front();
    int remove_after(OssIndex);

    __shared6 *extract_after(OssIndex, OssIndex);
};

typedef __shared6 TAIListforMDT;

typedef __shared6 TAIListforWarning;

typedef __shared4 EmergencyAreaIDList;

class OSS_PUBLIC WarningAreaList  : public OssChoice   /* CHOICE */
{
public:
    enum Id {
	unselected,
	cellIDList_chosen = 1,
	trackingAreaListforWarning_chosen = 2,
	emergencyAreaIDList_chosen = 3
    };
    typedef __shared5 cellIDList;
    typedef __shared6 trackingAreaListforWarning;
    typedef __shared4 emergencyAreaIDList;

    WarningAreaList();
    WarningAreaList(const WarningAreaList &);
    ~WarningAreaList();

    WarningAreaList & operator = (const WarningAreaList &);
    int operator == (const WarningAreaList &) const;
    int operator != (const WarningAreaList &) const;

    cellIDList *get_cellIDList();
    const cellIDList *get_cellIDList() const;
    void set_cellIDList(const cellIDList &);

    trackingAreaListforWarning *get_trackingAreaListforWarning();
    const trackingAreaListforWarning *get_trackingAreaListforWarning() const;
    void set_trackingAreaListforWarning(const trackingAreaListforWarning &);

    emergencyAreaIDList *get_emergencyAreaIDList();
    const emergencyAreaIDList *get_emergencyAreaIDList() const;
    void set_emergencyAreaIDList(const emergencyAreaIDList &);
private:
    union {
	void *cellIDList_field;
	void *trackingAreaListforWarning_field;
	void *emergencyAreaIDList_field;
    };
    void cleanup();
};

class OSS_PUBLIC WriteReplaceWarningRequestIEs_Value : public OssConstrainedOpenType
{
public:
    WriteReplaceWarningRequestIEs_Value();
    WriteReplaceWarningRequestIEs_Value(const WriteReplaceWarningRequestIEs_Value &);
    ~WriteReplaceWarningRequestIEs_Value();
    WriteReplaceWarningRequestIEs_Value & operator = (const WriteReplaceWarningRequestIEs_Value &);
    int operator == (const WriteReplaceWarningRequestIEs_Value &) const;
    int operator != (const WriteReplaceWarningRequestIEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    MessageIdentifier *get_MessageIdentifier();
    const MessageIdentifier *get_MessageIdentifier() const;
    void set_MessageIdentifier(const MessageIdentifier &);
    MessageIdentifier *release_MessageIdentifier();
    void set_MessageIdentifier(MessageIdentifier *);

    SerialNumber *get_SerialNumber();
    const SerialNumber *get_SerialNumber() const;
    void set_SerialNumber(const SerialNumber &);
    SerialNumber *release_SerialNumber();
    void set_SerialNumber(SerialNumber *);

    WarningAreaList *get_WarningAreaList();
    const WarningAreaList *get_WarningAreaList() const;
    void set_WarningAreaList(const WarningAreaList &);
    WarningAreaList *release_WarningAreaList();
    void set_WarningAreaList(WarningAreaList *);

    RepetitionPeriod *get_RepetitionPeriod();
    const RepetitionPeriod *get_RepetitionPeriod() const;
    void set_RepetitionPeriod(const RepetitionPeriod &);
    RepetitionPeriod *release_RepetitionPeriod();
    void set_RepetitionPeriod(RepetitionPeriod *);

    ExtendedRepetitionPeriod *get_ExtendedRepetitionPeriod();
    const ExtendedRepetitionPeriod *get_ExtendedRepetitionPeriod() const;
    void set_ExtendedRepetitionPeriod(const ExtendedRepetitionPeriod &);
    ExtendedRepetitionPeriod *release_ExtendedRepetitionPeriod();
    void set_ExtendedRepetitionPeriod(ExtendedRepetitionPeriod *);

    NumberofBroadcastRequest *get_NumberofBroadcastRequest();
    const NumberofBroadcastRequest *get_NumberofBroadcastRequest() const;
    void set_NumberofBroadcastRequest(const NumberofBroadcastRequest &);
    NumberofBroadcastRequest *release_NumberofBroadcastRequest();
    void set_NumberofBroadcastRequest(NumberofBroadcastRequest *);

    WarningType *get_WarningType();
    const WarningType *get_WarningType() const;
    void set_WarningType(const WarningType &);
    WarningType *release_WarningType();
    void set_WarningType(WarningType *);

    WarningSecurityInfo *get_WarningSecurityInfo();
    const WarningSecurityInfo *get_WarningSecurityInfo() const;
    void set_WarningSecurityInfo(const WarningSecurityInfo &);
    WarningSecurityInfo *release_WarningSecurityInfo();
    void set_WarningSecurityInfo(WarningSecurityInfo *);

    DataCodingScheme *get_DataCodingScheme();
    const DataCodingScheme *get_DataCodingScheme() const;
    void set_DataCodingScheme(const DataCodingScheme &);
    DataCodingScheme *release_DataCodingScheme();
    void set_DataCodingScheme(DataCodingScheme *);

    WarningMessageContents *get_WarningMessageContents();
    const WarningMessageContents *get_WarningMessageContents() const;
    void set_WarningMessageContents(const WarningMessageContents &);
    WarningMessageContents *release_WarningMessageContents();
    void set_WarningMessageContents(WarningMessageContents *);

    ConcurrentWarningMessageIndicator *get_ConcurrentWarningMessageIndicator();
    const ConcurrentWarningMessageIndicator *get_ConcurrentWarningMessageIndicator() const;
    void set_ConcurrentWarningMessageIndicator(const ConcurrentWarningMessageIndicator &);
    ConcurrentWarningMessageIndicator *release_ConcurrentWarningMessageIndicator();
    void set_ConcurrentWarningMessageIndicator(ConcurrentWarningMessageIndicator *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq97   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef WriteReplaceWarningRequestIEs_Value value;

    __seq97();
    __seq97(const __seq97 &);
    __seq97(id, criticality, const value &);

    __seq97 & operator = (const __seq97 &);
    int operator == (const __seq97 &) const;
    int operator != (const __seq97 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC __shared44;

class OSS_PUBLIC __shared45 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __shared44 component;

    __shared45();
    __shared45(const __shared45 &);
    ~__shared45();

    __shared45 & operator = (const __shared45 &);
    int operator == (const __shared45 &) const;
    int operator != (const __shared45 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__shared45 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __shared45 *);

    int remove_front();
    int remove_after(OssIndex);

    __shared45 *extract_after(OssIndex, OssIndex);
};

typedef __shared45 CellID_Broadcast;

class OSS_PUBLIC TAI_Broadcast_Item;

class OSS_PUBLIC __shared46 : public OssList  /* SEQUENCE OF */
{
public:
    typedef TAI_Broadcast_Item component;

    __shared46();
    __shared46(const __shared46 &);
    ~__shared46();

    __shared46 & operator = (const __shared46 &);
    int operator == (const __shared46 &) const;
    int operator != (const __shared46 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__shared46 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __shared46 *);

    int remove_front();
    int remove_after(OssIndex);

    __shared46 *extract_after(OssIndex, OssIndex);
};

typedef __shared46 TAI_Broadcast;

class OSS_PUBLIC EmergencyAreaID_Broadcast_Item;

class OSS_PUBLIC __shared47 : public OssList  /* SEQUENCE OF */
{
public:
    typedef EmergencyAreaID_Broadcast_Item component;

    __shared47();
    __shared47(const __shared47 &);
    ~__shared47();

    __shared47 & operator = (const __shared47 &);
    int operator == (const __shared47 &) const;
    int operator != (const __shared47 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__shared47 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __shared47 *);

    int remove_front();
    int remove_after(OssIndex);

    __shared47 *extract_after(OssIndex, OssIndex);
};

typedef __shared47 EmergencyAreaID_Broadcast;

class OSS_PUBLIC BroadcastCompletedAreaList  : public OssChoice   /* CHOICE */
{
public:
    enum Id {
	unselected,
	cellID_Broadcast_chosen = 1,
	tAI_Broadcast_chosen = 2,
	emergencyAreaID_Broadcast_chosen = 3
    };
    typedef __shared45 cellID_Broadcast;
    typedef __shared46 tAI_Broadcast;
    typedef __shared47 emergencyAreaID_Broadcast;

    BroadcastCompletedAreaList();
    BroadcastCompletedAreaList(const BroadcastCompletedAreaList &);
    ~BroadcastCompletedAreaList();

    BroadcastCompletedAreaList & operator = (const BroadcastCompletedAreaList &);
    int operator == (const BroadcastCompletedAreaList &) const;
    int operator != (const BroadcastCompletedAreaList &) const;

    cellID_Broadcast *get_cellID_Broadcast();
    const cellID_Broadcast *get_cellID_Broadcast() const;
    void set_cellID_Broadcast(const cellID_Broadcast &);

    tAI_Broadcast *get_tAI_Broadcast();
    const tAI_Broadcast *get_tAI_Broadcast() const;
    void set_tAI_Broadcast(const tAI_Broadcast &);

    emergencyAreaID_Broadcast *get_emergencyAreaID_Broadcast();
    const emergencyAreaID_Broadcast *get_emergencyAreaID_Broadcast() const;
    void set_emergencyAreaID_Broadcast(const emergencyAreaID_Broadcast &);
private:
    union {
	void *cellID_Broadcast_field;
	void *tAI_Broadcast_field;
	void *emergencyAreaID_Broadcast_field;
    };
    void cleanup();
};

class OSS_PUBLIC WriteReplaceWarningResponseIEs_Value : public OssConstrainedOpenType
{
public:
    WriteReplaceWarningResponseIEs_Value();
    WriteReplaceWarningResponseIEs_Value(const WriteReplaceWarningResponseIEs_Value &);
    ~WriteReplaceWarningResponseIEs_Value();
    WriteReplaceWarningResponseIEs_Value & operator = (const WriteReplaceWarningResponseIEs_Value &);
    int operator == (const WriteReplaceWarningResponseIEs_Value &) const;
    int operator != (const WriteReplaceWarningResponseIEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    MessageIdentifier *get_MessageIdentifier();
    const MessageIdentifier *get_MessageIdentifier() const;
    void set_MessageIdentifier(const MessageIdentifier &);
    MessageIdentifier *release_MessageIdentifier();
    void set_MessageIdentifier(MessageIdentifier *);

    SerialNumber *get_SerialNumber();
    const SerialNumber *get_SerialNumber() const;
    void set_SerialNumber(const SerialNumber &);
    SerialNumber *release_SerialNumber();
    void set_SerialNumber(SerialNumber *);

    BroadcastCompletedAreaList *get_BroadcastCompletedAreaList();
    const BroadcastCompletedAreaList *get_BroadcastCompletedAreaList() const;
    void set_BroadcastCompletedAreaList(const BroadcastCompletedAreaList &);
    BroadcastCompletedAreaList *release_BroadcastCompletedAreaList();
    void set_BroadcastCompletedAreaList(BroadcastCompletedAreaList *);

    CriticalityDiagnostics *get_CriticalityDiagnostics();
    const CriticalityDiagnostics *get_CriticalityDiagnostics() const;
    void set_CriticalityDiagnostics(const CriticalityDiagnostics &);
    CriticalityDiagnostics *release_CriticalityDiagnostics();
    void set_CriticalityDiagnostics(CriticalityDiagnostics *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq98   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef WriteReplaceWarningResponseIEs_Value value;

    __seq98();
    __seq98(const __seq98 &);
    __seq98(id, criticality, const value &);

    __seq98 & operator = (const __seq98 &);
    int operator == (const __seq98 &) const;
    int operator != (const __seq98 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC GERAN_Cell_ID   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef LAI lAI;
    typedef OssString rAC;
    typedef OssString cI;
    typedef __shared2 iE_Extensions;

    GERAN_Cell_ID();
    GERAN_Cell_ID(const GERAN_Cell_ID &);
    GERAN_Cell_ID(const lAI &, const rAC &, const cI &, const iE_Extensions &);
    GERAN_Cell_ID(const lAI &, const rAC &, const cI &);

    GERAN_Cell_ID & operator = (const GERAN_Cell_ID &);
    int operator == (const GERAN_Cell_ID &) const;
    int operator != (const GERAN_Cell_ID &) const;

    lAI & get_lAI();
    const lAI & get_lAI() const;
    void set_lAI(const lAI &);

    rAC & get_rAC();
    const rAC & get_rAC() const;
    void set_rAC(const rAC &);

    cI & get_cI();
    const cI & get_cI() const;
    void set_cI(const cI &);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    lAI lAI_field;
    rAC rAC_field;
    cI cI_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC RIMRoutingAddress  : public OssChoice   /* CHOICE */
{
public:
    enum Id {
	unselected,
	gERAN_Cell_ID_chosen = 1,
	targetRNC_ID_chosen = 2,
	eHRPD_Sector_ID_chosen = 3
    };
    typedef GERAN_Cell_ID gERAN_Cell_ID;
    typedef TargetRNC_ID targetRNC_ID;
    typedef OssString eHRPD_Sector_ID;

    RIMRoutingAddress();
    RIMRoutingAddress(const RIMRoutingAddress &);
    ~RIMRoutingAddress();

    RIMRoutingAddress & operator = (const RIMRoutingAddress &);
    int operator == (const RIMRoutingAddress &) const;
    int operator != (const RIMRoutingAddress &) const;

    gERAN_Cell_ID *get_gERAN_Cell_ID();
    const gERAN_Cell_ID *get_gERAN_Cell_ID() const;
    void set_gERAN_Cell_ID(const gERAN_Cell_ID &);

    targetRNC_ID *get_targetRNC_ID();
    const targetRNC_ID *get_targetRNC_ID() const;
    void set_targetRNC_ID(const targetRNC_ID &);

    eHRPD_Sector_ID *get_eHRPD_Sector_ID();
    const eHRPD_Sector_ID *get_eHRPD_Sector_ID() const;
    void set_eHRPD_Sector_ID(const eHRPD_Sector_ID &);
private:
    union {
	gERAN_Cell_ID *gERAN_Cell_ID_field;
	targetRNC_ID *targetRNC_ID_field;
	OSSC::COssString eHRPD_Sector_ID_field;
    };
    void cleanup();
};

class OSS_PUBLIC RIMTransfer   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OssString rIMInformation;
    typedef RIMRoutingAddress rIMRoutingAddress;
    typedef __shared2 iE_Extensions;

    RIMTransfer();
    RIMTransfer(const RIMTransfer &);
    RIMTransfer(const rIMInformation &, const rIMRoutingAddress &, const iE_Extensions &);
    RIMTransfer(const rIMInformation &);

    RIMTransfer & operator = (const RIMTransfer &);
    int operator == (const RIMTransfer &) const;
    int operator != (const RIMTransfer &) const;

    rIMInformation & get_rIMInformation();
    const rIMInformation & get_rIMInformation() const;
    void set_rIMInformation(const rIMInformation &);

    rIMRoutingAddress *get_rIMRoutingAddress();
    const rIMRoutingAddress *get_rIMRoutingAddress() const;
    void set_rIMRoutingAddress(const rIMRoutingAddress &);
    int rIMRoutingAddress_is_present() const;
    void omit_rIMRoutingAddress();

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    rIMInformation rIMInformation_field;
    rIMRoutingAddress rIMRoutingAddress_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC Inter_SystemInformationTransferType  : public OssChoice   /* CHOICE */
{
public:
    enum Id {
	unselected,
	rIMTransfer_chosen = 1
    };
    typedef RIMTransfer rIMTransfer;

    Inter_SystemInformationTransferType();
    Inter_SystemInformationTransferType(const Inter_SystemInformationTransferType &);
    ~Inter_SystemInformationTransferType();

    Inter_SystemInformationTransferType & operator = (const Inter_SystemInformationTransferType &);
    int operator == (const Inter_SystemInformationTransferType &) const;
    int operator != (const Inter_SystemInformationTransferType &) const;

    rIMTransfer *get_rIMTransfer();
    const rIMTransfer *get_rIMTransfer() const;
    void set_rIMTransfer(const rIMTransfer &);
private:
    union {
	rIMTransfer *rIMTransfer_field;
    };
    void cleanup();
};

class OSS_PUBLIC ENBDirectInformationTransferIEs_Value : public OssConstrainedOpenType
{
public:
    ENBDirectInformationTransferIEs_Value();
    ENBDirectInformationTransferIEs_Value(const ENBDirectInformationTransferIEs_Value &);
    ~ENBDirectInformationTransferIEs_Value();
    ENBDirectInformationTransferIEs_Value & operator = (const ENBDirectInformationTransferIEs_Value &);
    int operator == (const ENBDirectInformationTransferIEs_Value &) const;
    int operator != (const ENBDirectInformationTransferIEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    Inter_SystemInformationTransferType *get_Inter_SystemInformationTransferType();
    const Inter_SystemInformationTransferType *get_Inter_SystemInformationTransferType() const;
    void set_Inter_SystemInformationTransferType(const Inter_SystemInformationTransferType &);
    Inter_SystemInformationTransferType *release_Inter_SystemInformationTransferType();
    void set_Inter_SystemInformationTransferType(Inter_SystemInformationTransferType *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __shared25   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef ENBDirectInformationTransferIEs_Value value;

    __shared25();
    __shared25(const __shared25 &);
    __shared25(id, criticality, const value &);

    __shared25 & operator = (const __shared25 &);
    int operator == (const __shared25 &) const;
    int operator != (const __shared25 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

typedef __shared3 SourceeNB_ID;

class OSS_PUBLIC __shared28 : public OssList  /* SEQUENCE OF */
{
public:
    typedef OssBitString component;

    __shared28();
    __shared28(const __shared28 &);
    ~__shared28();

    __shared28 & operator = (const __shared28 &);
    int operator == (const __shared28 &) const;
    int operator != (const __shared28 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__shared28 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __shared28 *);

    int remove_front();
    int remove_after(OssIndex);

    __shared28 *extract_after(OssIndex, OssIndex);
};

typedef __shared28 ENBX2TLAs;

class OSS_PUBLIC __seq201;

class OSS_PUBLIC __seqof176 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq201 component;

    __seqof176();
    __seqof176(const __seqof176 &);
    ~__seqof176();

    __seqof176 & operator = (const __seqof176 &);
    int operator == (const __seqof176 &) const;
    int operator != (const __seqof176 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof176 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof176 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof176 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC X2TNLConfigurationInfo   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __shared28 eNBX2TransportLayerAddresses;
    typedef __seqof176 iE_Extensions;

    X2TNLConfigurationInfo();
    X2TNLConfigurationInfo(const X2TNLConfigurationInfo &);
    X2TNLConfigurationInfo(const eNBX2TransportLayerAddresses &, const iE_Extensions &);
    X2TNLConfigurationInfo(const eNBX2TransportLayerAddresses &);

    X2TNLConfigurationInfo & operator = (const X2TNLConfigurationInfo &);
    int operator == (const X2TNLConfigurationInfo &) const;
    int operator != (const X2TNLConfigurationInfo &) const;

    eNBX2TransportLayerAddresses & get_eNBX2TransportLayerAddresses();
    const eNBX2TransportLayerAddresses & get_eNBX2TransportLayerAddresses() const;
    void set_eNBX2TransportLayerAddresses(const eNBX2TransportLayerAddresses &);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    eNBX2TransportLayerAddresses eNBX2TransportLayerAddresses_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC __seq202;

class OSS_PUBLIC __seqof177 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq202 component;

    __seqof177();
    __seqof177(const __seqof177 &);
    ~__seqof177();

    __seqof177 & operator = (const __seqof177 &);
    int operator == (const __seqof177 &) const;
    int operator != (const __seqof177 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof177 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof177 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof177 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC SONInformationReply   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef X2TNLConfigurationInfo x2TNLConfigurationInfo;
    typedef __seqof177 iE_Extensions;

    SONInformationReply();
    SONInformationReply(const SONInformationReply &);
    SONInformationReply(const x2TNLConfigurationInfo &, const iE_Extensions &);

    SONInformationReply & operator = (const SONInformationReply &);
    int operator == (const SONInformationReply &) const;
    int operator != (const SONInformationReply &) const;

    x2TNLConfigurationInfo *get_x2TNLConfigurationInfo();
    const x2TNLConfigurationInfo *get_x2TNLConfigurationInfo() const;
    void set_x2TNLConfigurationInfo(const x2TNLConfigurationInfo &);
    int x2TNLConfigurationInfo_is_present() const;
    void omit_x2TNLConfigurationInfo();

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    x2TNLConfigurationInfo x2TNLConfigurationInfo_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC RLFReportInformation   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OssString uE_RLF_Report_Container;
    typedef OssString uE_RLF_Report_Container_for_extended_bands;
    typedef __shared2 iE_Extensions;

    RLFReportInformation();
    RLFReportInformation(const RLFReportInformation &);
    RLFReportInformation(const uE_RLF_Report_Container &, const uE_RLF_Report_Container_for_extended_bands &, 
	const iE_Extensions &);
    RLFReportInformation(const uE_RLF_Report_Container &);

    RLFReportInformation & operator = (const RLFReportInformation &);
    int operator == (const RLFReportInformation &) const;
    int operator != (const RLFReportInformation &) const;

    uE_RLF_Report_Container & get_uE_RLF_Report_Container();
    const uE_RLF_Report_Container & get_uE_RLF_Report_Container() const;
    void set_uE_RLF_Report_Container(const uE_RLF_Report_Container &);

    uE_RLF_Report_Container_for_extended_bands *get_uE_RLF_Report_Container_for_extended_bands();
    const uE_RLF_Report_Container_for_extended_bands *get_uE_RLF_Report_Container_for_extended_bands() const;
    void set_uE_RLF_Report_Container_for_extended_bands(const uE_RLF_Report_Container_for_extended_bands &);
    int uE_RLF_Report_Container_for_extended_bands_is_present() const;
    void omit_uE_RLF_Report_Container_for_extended_bands();

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    uE_RLF_Report_Container uE_RLF_Report_Container_field;
    uE_RLF_Report_Container_for_extended_bands uE_RLF_Report_Container_for_extended_bands_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC SONInformationReport  : public OssChoice   /* CHOICE */
{
public:
    enum Id {
	unselected,
	rLFReportInformation_chosen = 1
    };
    typedef RLFReportInformation rLFReportInformation;

    SONInformationReport();
    SONInformationReport(const SONInformationReport &);
    ~SONInformationReport();

    SONInformationReport & operator = (const SONInformationReport &);
    int operator == (const SONInformationReport &) const;
    int operator != (const SONInformationReport &) const;

    rLFReportInformation *get_rLFReportInformation();
    const rLFReportInformation *get_rLFReportInformation() const;
    void set_rLFReportInformation(const rLFReportInformation &);
private:
    union {
	rLFReportInformation *rLFReportInformation_field;
    };
    void cleanup();
};

class OSS_PUBLIC SONInformation_ExtensionIE_Value : public OssConstrainedOpenType
{
public:
    SONInformation_ExtensionIE_Value();
    SONInformation_ExtensionIE_Value(const SONInformation_ExtensionIE_Value &);
    ~SONInformation_ExtensionIE_Value();
    SONInformation_ExtensionIE_Value & operator = (const SONInformation_ExtensionIE_Value &);
    int operator == (const SONInformation_ExtensionIE_Value &) const;
    int operator != (const SONInformation_ExtensionIE_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    SONInformationReport *get_SONInformationReport();
    const SONInformationReport *get_SONInformationReport() const;
    void set_SONInformationReport(const SONInformationReport &);
    SONInformationReport *release_SONInformationReport();
    void set_SONInformationReport(SONInformationReport *);
private:
    void cleanup_decoded();
    int check_type(OssTypeIndex);
};

class OSS_PUBLIC SONInformation_Extension   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef SONInformation_ExtensionIE_Value value;

    SONInformation_Extension();
    SONInformation_Extension(const SONInformation_Extension &);
    SONInformation_Extension(id, criticality, const value &);

    SONInformation_Extension & operator = (const SONInformation_Extension &);
    int operator == (const SONInformation_Extension &) const;
    int operator != (const SONInformation_Extension &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC SONInformation  : public OssChoice   /* CHOICE */
{
public:
    enum Id {
	unselected,
	sONInformationRequest_chosen = 1,
	sONInformationReply_chosen = 2,
	sONInformation_Extension_chosen = 3
    };
    typedef enum SONInformationRequest sONInformationRequest;
    typedef SONInformationReply sONInformationReply;
    typedef SONInformation_Extension sONInformation_Extension;

    SONInformation();
    SONInformation(const SONInformation &);
    ~SONInformation();

    SONInformation & operator = (const SONInformation &);
    int operator == (const SONInformation &) const;
    int operator != (const SONInformation &) const;

    sONInformationRequest *get_sONInformationRequest();
    const sONInformationRequest *get_sONInformationRequest() const;
    void set_sONInformationRequest(sONInformationRequest);

    sONInformationReply *get_sONInformationReply();
    const sONInformationReply *get_sONInformationReply() const;
    void set_sONInformationReply(const sONInformationReply &);

    sONInformation_Extension *get_sONInformation_Extension();
    const sONInformation_Extension *get_sONInformation_Extension() const;
    void set_sONInformation_Extension(const sONInformation_Extension &);
private:
    union {
	sONInformationRequest sONInformationRequest_field;
	sONInformationReply *sONInformationReply_field;
	sONInformation_Extension *sONInformation_Extension_field;
    };
    void cleanup();
};

class OSS_PUBLIC __seq205;

class OSS_PUBLIC __seqof180 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq205 component;

    __seqof180();
    __seqof180(const __seqof180 &);
    ~__seqof180();

    __seqof180 & operator = (const __seqof180 &);
    int operator == (const __seqof180 &) const;
    int operator != (const __seqof180 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof180 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof180 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof180 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC SONConfigurationTransfer   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __shared3 targeteNB_ID;
    typedef __shared3 sourceeNB_ID;
    typedef SONInformation sONInformation;
    typedef __seqof180 iE_Extensions;

    SONConfigurationTransfer();
    SONConfigurationTransfer(const SONConfigurationTransfer &);
    SONConfigurationTransfer(const targeteNB_ID &, const sourceeNB_ID &, const sONInformation &, 
	const iE_Extensions &);
    SONConfigurationTransfer(const targeteNB_ID &, const sourceeNB_ID &, const sONInformation &);

    SONConfigurationTransfer & operator = (const SONConfigurationTransfer &);
    int operator == (const SONConfigurationTransfer &) const;
    int operator != (const SONConfigurationTransfer &) const;

    targeteNB_ID & get_targeteNB_ID();
    const targeteNB_ID & get_targeteNB_ID() const;
    void set_targeteNB_ID(const targeteNB_ID &);

    sourceeNB_ID & get_sourceeNB_ID();
    const sourceeNB_ID & get_sourceeNB_ID() const;
    void set_sourceeNB_ID(const sourceeNB_ID &);

    sONInformation & get_sONInformation();
    const sONInformation & get_sONInformation() const;
    void set_sONInformation(const sONInformation &);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    targeteNB_ID targeteNB_ID_field;
    sourceeNB_ID sourceeNB_ID_field;
    sONInformation sONInformation_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC ENBConfigurationTransferIEs_Value : public OssConstrainedOpenType
{
public:
    ENBConfigurationTransferIEs_Value();
    ENBConfigurationTransferIEs_Value(const ENBConfigurationTransferIEs_Value &);
    ~ENBConfigurationTransferIEs_Value();
    ENBConfigurationTransferIEs_Value & operator = (const ENBConfigurationTransferIEs_Value &);
    int operator == (const ENBConfigurationTransferIEs_Value &) const;
    int operator != (const ENBConfigurationTransferIEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    SONConfigurationTransfer *get_SONConfigurationTransfer();
    const SONConfigurationTransfer *get_SONConfigurationTransfer() const;
    void set_SONConfigurationTransfer(const SONConfigurationTransfer &);
    SONConfigurationTransfer *release_SONConfigurationTransfer();
    void set_SONConfigurationTransfer(SONConfigurationTransfer *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __shared29   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef ENBConfigurationTransferIEs_Value value;

    __shared29();
    __shared29(const __shared29 &);
    __shared29(id, criticality, const value &);

    __shared29 & operator = (const __shared29 &);
    int operator == (const __shared29 &) const;
    int operator != (const __shared29 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC PrivateIE_ID  : public OssChoice   /* CHOICE */
{
public:
    enum Id {
	unselected,
	local_chosen = 1,
	global_chosen = 2
    };
    typedef OSS_UINT32 local;
    typedef OssEncOID global;

    PrivateIE_ID();
    PrivateIE_ID(const PrivateIE_ID &);
    ~PrivateIE_ID();

    PrivateIE_ID & operator = (const PrivateIE_ID &);
    int operator == (const PrivateIE_ID &) const;
    int operator != (const PrivateIE_ID &) const;

    local *get_local();
    const local *get_local() const;
    void set_local(local);

    global *get_global();
    const global *get_global() const;
    void set_global(const global &);
private:
    union {
	local local_field;
	OSSC::COssEncOID global_field;
    };
    void cleanup();
};

class OSS_PUBLIC PrivateIE_Field   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef PrivateIE_ID id;
    typedef enum Criticality criticality;
    typedef E_RABDataForwardingItem_ExtIEs_Extension value;

    PrivateIE_Field();
    PrivateIE_Field(const PrivateIE_Field &);
    PrivateIE_Field(const id &, criticality, const value &);

    PrivateIE_Field & operator = (const PrivateIE_Field &);
    int operator == (const PrivateIE_Field &) const;
    int operator != (const PrivateIE_Field &) const;

    id & get_id();
    const id & get_id() const;
    void set_id(const id &);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC KillRequestIEs_Value : public OssConstrainedOpenType
{
public:
    KillRequestIEs_Value();
    KillRequestIEs_Value(const KillRequestIEs_Value &);
    ~KillRequestIEs_Value();
    KillRequestIEs_Value & operator = (const KillRequestIEs_Value &);
    int operator == (const KillRequestIEs_Value &) const;
    int operator != (const KillRequestIEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    MessageIdentifier *get_MessageIdentifier();
    const MessageIdentifier *get_MessageIdentifier() const;
    void set_MessageIdentifier(const MessageIdentifier &);
    MessageIdentifier *release_MessageIdentifier();
    void set_MessageIdentifier(MessageIdentifier *);

    SerialNumber *get_SerialNumber();
    const SerialNumber *get_SerialNumber() const;
    void set_SerialNumber(const SerialNumber &);
    SerialNumber *release_SerialNumber();
    void set_SerialNumber(SerialNumber *);

    WarningAreaList *get_WarningAreaList();
    const WarningAreaList *get_WarningAreaList() const;
    void set_WarningAreaList(const WarningAreaList &);
    WarningAreaList *release_WarningAreaList();
    void set_WarningAreaList(WarningAreaList *);

    KillAllWarningMessages *get_KillAllWarningMessages();
    const KillAllWarningMessages *get_KillAllWarningMessages() const;
    void set_KillAllWarningMessages(const KillAllWarningMessages &);
    KillAllWarningMessages *release_KillAllWarningMessages();
    void set_KillAllWarningMessages(KillAllWarningMessages *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq103   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef KillRequestIEs_Value value;

    __seq103();
    __seq103(const __seq103 &);
    __seq103(id, criticality, const value &);

    __seq103 & operator = (const __seq103 &);
    int operator == (const __seq103 &) const;
    int operator != (const __seq103 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC __shared36;

class OSS_PUBLIC __shared37 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __shared36 component;

    __shared37();
    __shared37(const __shared37 &);
    ~__shared37();

    __shared37 & operator = (const __shared37 &);
    int operator == (const __shared37 &) const;
    int operator != (const __shared37 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__shared37 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __shared37 *);

    int remove_front();
    int remove_after(OssIndex);

    __shared37 *extract_after(OssIndex, OssIndex);
};

typedef __shared37 CellID_Cancelled;

class OSS_PUBLIC TAI_Cancelled_Item;

class OSS_PUBLIC __shared38 : public OssList  /* SEQUENCE OF */
{
public:
    typedef TAI_Cancelled_Item component;

    __shared38();
    __shared38(const __shared38 &);
    ~__shared38();

    __shared38 & operator = (const __shared38 &);
    int operator == (const __shared38 &) const;
    int operator != (const __shared38 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__shared38 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __shared38 *);

    int remove_front();
    int remove_after(OssIndex);

    __shared38 *extract_after(OssIndex, OssIndex);
};

typedef __shared38 TAI_Cancelled;

class OSS_PUBLIC EmergencyAreaID_Cancelled_Item;

class OSS_PUBLIC __shared39 : public OssList  /* SEQUENCE OF */
{
public:
    typedef EmergencyAreaID_Cancelled_Item component;

    __shared39();
    __shared39(const __shared39 &);
    ~__shared39();

    __shared39 & operator = (const __shared39 &);
    int operator == (const __shared39 &) const;
    int operator != (const __shared39 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__shared39 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __shared39 *);

    int remove_front();
    int remove_after(OssIndex);

    __shared39 *extract_after(OssIndex, OssIndex);
};

typedef __shared39 EmergencyAreaID_Cancelled;

class OSS_PUBLIC BroadcastCancelledAreaList  : public OssChoice   /* CHOICE */
{
public:
    enum Id {
	unselected,
	cellID_Cancelled_chosen = 1,
	tAI_Cancelled_chosen = 2,
	emergencyAreaID_Cancelled_chosen = 3
    };
    typedef __shared37 cellID_Cancelled;
    typedef __shared38 tAI_Cancelled;
    typedef __shared39 emergencyAreaID_Cancelled;

    BroadcastCancelledAreaList();
    BroadcastCancelledAreaList(const BroadcastCancelledAreaList &);
    ~BroadcastCancelledAreaList();

    BroadcastCancelledAreaList & operator = (const BroadcastCancelledAreaList &);
    int operator == (const BroadcastCancelledAreaList &) const;
    int operator != (const BroadcastCancelledAreaList &) const;

    cellID_Cancelled *get_cellID_Cancelled();
    const cellID_Cancelled *get_cellID_Cancelled() const;
    void set_cellID_Cancelled(const cellID_Cancelled &);

    tAI_Cancelled *get_tAI_Cancelled();
    const tAI_Cancelled *get_tAI_Cancelled() const;
    void set_tAI_Cancelled(const tAI_Cancelled &);

    emergencyAreaID_Cancelled *get_emergencyAreaID_Cancelled();
    const emergencyAreaID_Cancelled *get_emergencyAreaID_Cancelled() const;
    void set_emergencyAreaID_Cancelled(const emergencyAreaID_Cancelled &);
private:
    union {
	void *cellID_Cancelled_field;
	void *tAI_Cancelled_field;
	void *emergencyAreaID_Cancelled_field;
    };
    void cleanup();
};

class OSS_PUBLIC KillResponseIEs_Value : public OssConstrainedOpenType
{
public:
    KillResponseIEs_Value();
    KillResponseIEs_Value(const KillResponseIEs_Value &);
    ~KillResponseIEs_Value();
    KillResponseIEs_Value & operator = (const KillResponseIEs_Value &);
    int operator == (const KillResponseIEs_Value &) const;
    int operator != (const KillResponseIEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    MessageIdentifier *get_MessageIdentifier();
    const MessageIdentifier *get_MessageIdentifier() const;
    void set_MessageIdentifier(const MessageIdentifier &);
    MessageIdentifier *release_MessageIdentifier();
    void set_MessageIdentifier(MessageIdentifier *);

    SerialNumber *get_SerialNumber();
    const SerialNumber *get_SerialNumber() const;
    void set_SerialNumber(const SerialNumber &);
    SerialNumber *release_SerialNumber();
    void set_SerialNumber(SerialNumber *);

    BroadcastCancelledAreaList *get_BroadcastCancelledAreaList();
    const BroadcastCancelledAreaList *get_BroadcastCancelledAreaList() const;
    void set_BroadcastCancelledAreaList(const BroadcastCancelledAreaList &);
    BroadcastCancelledAreaList *release_BroadcastCancelledAreaList();
    void set_BroadcastCancelledAreaList(BroadcastCancelledAreaList *);

    CriticalityDiagnostics *get_CriticalityDiagnostics();
    const CriticalityDiagnostics *get_CriticalityDiagnostics() const;
    void set_CriticalityDiagnostics(const CriticalityDiagnostics &);
    CriticalityDiagnostics *release_CriticalityDiagnostics();
    void set_CriticalityDiagnostics(CriticalityDiagnostics *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq104   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef KillResponseIEs_Value value;

    __seq104();
    __seq104(const __seq104 &);
    __seq104(id, criticality, const value &);

    __seq104 & operator = (const __seq104 &);
    int operator == (const __seq104 &) const;
    int operator != (const __seq104 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

typedef __shared5 ECGIListForRestart;

typedef __shared6 TAIListForRestart;

typedef __shared4 EmergencyAreaIDListForRestart;

class OSS_PUBLIC PWSRestartIndicationIEs_Value : public OssConstrainedOpenType
{
public:
    PWSRestartIndicationIEs_Value();
    PWSRestartIndicationIEs_Value(const PWSRestartIndicationIEs_Value &);
    ~PWSRestartIndicationIEs_Value();
    PWSRestartIndicationIEs_Value & operator = (const PWSRestartIndicationIEs_Value &);
    int operator == (const PWSRestartIndicationIEs_Value &) const;
    int operator != (const PWSRestartIndicationIEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    __shared5 *get_ECGIListForRestart();
    const __shared5 *get_ECGIListForRestart() const;
    void set_ECGIListForRestart(const __shared5 &);
    __shared5 *release_ECGIListForRestart();
    void set_ECGIListForRestart(__shared5 *);

    Global_ENB_ID *get_Global_ENB_ID();
    const Global_ENB_ID *get_Global_ENB_ID() const;
    void set_Global_ENB_ID(const Global_ENB_ID &);
    Global_ENB_ID *release_Global_ENB_ID();
    void set_Global_ENB_ID(Global_ENB_ID *);

    __shared6 *get_TAIListForRestart();
    const __shared6 *get_TAIListForRestart() const;
    void set_TAIListForRestart(const __shared6 &);
    __shared6 *release_TAIListForRestart();
    void set_TAIListForRestart(__shared6 *);

    __shared4 *get_EmergencyAreaIDListForRestart();
    const __shared4 *get_EmergencyAreaIDListForRestart() const;
    void set_EmergencyAreaIDListForRestart(const __shared4 &);
    __shared4 *release_EmergencyAreaIDListForRestart();
    void set_EmergencyAreaIDListForRestart(__shared4 *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq105;

class OSS_PUBLIC __seqof90 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq105 component;

    __seqof90();
    __seqof90(const __seqof90 &);
    ~__seqof90();

    __seqof90 & operator = (const __seqof90 &);
    int operator == (const __seqof90 &) const;
    int operator != (const __seqof90 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof90 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof90 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof90 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC PWSRestartIndication   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __seqof90 protocolIEs;

    PWSRestartIndication();
    PWSRestartIndication(const PWSRestartIndication &);
    PWSRestartIndication(const protocolIEs &);

    PWSRestartIndication & operator = (const PWSRestartIndication &);
    int operator == (const PWSRestartIndication &) const;
    int operator != (const PWSRestartIndication &) const;

    protocolIEs & get_protocolIEs();
    const protocolIEs & get_protocolIEs() const;
    void set_protocolIEs(const protocolIEs &);
private:
    protocolIEs protocolIEs_field;
};

class OSS_PUBLIC __seq105   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef PWSRestartIndicationIEs_Value value;

    __seq105();
    __seq105(const __seq105 &);
    __seq105(id, criticality, const value &);

    __seq105 & operator = (const __seq105 &);
    int operator == (const __seq105 &) const;
    int operator != (const __seq105 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

typedef __shared5 PWSfailedECGIList;

class OSS_PUBLIC PWSFailureIndicationIEs_Value : public OssConstrainedOpenType
{
public:
    PWSFailureIndicationIEs_Value();
    PWSFailureIndicationIEs_Value(const PWSFailureIndicationIEs_Value &);
    ~PWSFailureIndicationIEs_Value();
    PWSFailureIndicationIEs_Value & operator = (const PWSFailureIndicationIEs_Value &);
    int operator == (const PWSFailureIndicationIEs_Value &) const;
    int operator != (const PWSFailureIndicationIEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    __shared5 *get_PWSfailedECGIList();
    const __shared5 *get_PWSfailedECGIList() const;
    void set_PWSfailedECGIList(const __shared5 &);
    __shared5 *release_PWSfailedECGIList();
    void set_PWSfailedECGIList(__shared5 *);

    Global_ENB_ID *get_Global_ENB_ID();
    const Global_ENB_ID *get_Global_ENB_ID() const;
    void set_Global_ENB_ID(const Global_ENB_ID &);
    Global_ENB_ID *release_Global_ENB_ID();
    void set_Global_ENB_ID(Global_ENB_ID *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq106;

class OSS_PUBLIC __seqof91 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq106 component;

    __seqof91();
    __seqof91(const __seqof91 &);
    ~__seqof91();

    __seqof91 & operator = (const __seqof91 &);
    int operator == (const __seqof91 &) const;
    int operator != (const __seqof91 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof91 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof91 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof91 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC PWSFailureIndication   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __seqof91 protocolIEs;

    PWSFailureIndication();
    PWSFailureIndication(const PWSFailureIndication &);
    PWSFailureIndication(const protocolIEs &);

    PWSFailureIndication & operator = (const PWSFailureIndication &);
    int operator == (const PWSFailureIndication &) const;
    int operator != (const PWSFailureIndication &) const;

    protocolIEs & get_protocolIEs();
    const protocolIEs & get_protocolIEs() const;
    void set_protocolIEs(const protocolIEs &);
private:
    protocolIEs protocolIEs_field;
};

class OSS_PUBLIC __seq106   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef PWSFailureIndicationIEs_Value value;

    __seq106();
    __seq106(const __seq106 &);
    __seq106(id, criticality, const value &);

    __seq106 & operator = (const __seq106 &);
    int operator == (const __seq106 &) const;
    int operator != (const __seq106 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC DownlinkUEAssociatedLPPaTransport_IEs_Value : public OssConstrainedOpenType
{
public:
    DownlinkUEAssociatedLPPaTransport_IEs_Value();
    DownlinkUEAssociatedLPPaTransport_IEs_Value(const DownlinkUEAssociatedLPPaTransport_IEs_Value &);
    ~DownlinkUEAssociatedLPPaTransport_IEs_Value();
    DownlinkUEAssociatedLPPaTransport_IEs_Value & operator = (const DownlinkUEAssociatedLPPaTransport_IEs_Value &);
    int operator == (const DownlinkUEAssociatedLPPaTransport_IEs_Value &) const;
    int operator != (const DownlinkUEAssociatedLPPaTransport_IEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    MME_UE_S1AP_ID *get_MME_UE_S1AP_ID();
    const MME_UE_S1AP_ID *get_MME_UE_S1AP_ID() const;
    void set_MME_UE_S1AP_ID(const MME_UE_S1AP_ID &);
    MME_UE_S1AP_ID *release_MME_UE_S1AP_ID();
    void set_MME_UE_S1AP_ID(MME_UE_S1AP_ID *);

    ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID();
    const ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID() const;
    void set_ENB_UE_S1AP_ID(const ENB_UE_S1AP_ID &);
    ENB_UE_S1AP_ID *release_ENB_UE_S1AP_ID();
    void set_ENB_UE_S1AP_ID(ENB_UE_S1AP_ID *);

    Routing_ID *get_Routing_ID();
    const Routing_ID *get_Routing_ID() const;
    void set_Routing_ID(const Routing_ID &);
    Routing_ID *release_Routing_ID();
    void set_Routing_ID(Routing_ID *);

    LPPa_PDU *get_LPPa_PDU();
    const LPPa_PDU *get_LPPa_PDU() const;
    void set_LPPa_PDU(const LPPa_PDU &);
    LPPa_PDU *release_LPPa_PDU();
    void set_LPPa_PDU(LPPa_PDU *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __shared54;

class OSS_PUBLIC __shared55 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __shared54 component;

    __shared55();
    __shared55(const __shared55 &);
    ~__shared55();

    __shared55 & operator = (const __shared55 &);
    int operator == (const __shared55 &) const;
    int operator != (const __shared55 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__shared55 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __shared55 *);

    int remove_front();
    int remove_after(OssIndex);

    __shared55 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC __shared56   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __shared55 protocolIEs;

    __shared56();
    __shared56(const __shared56 &);
    __shared56(const protocolIEs &);

    __shared56 & operator = (const __shared56 &);
    int operator == (const __shared56 &) const;
    int operator != (const __shared56 &) const;

    protocolIEs & get_protocolIEs();
    const protocolIEs & get_protocolIEs() const;
    void set_protocolIEs(const protocolIEs &);
private:
    protocolIEs protocolIEs_field;
};

typedef __shared56 DownlinkUEAssociatedLPPaTransport;

class OSS_PUBLIC __shared54   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef DownlinkUEAssociatedLPPaTransport_IEs_Value value;

    __shared54();
    __shared54(const __shared54 &);
    __shared54(id, criticality, const value &);

    __shared54 & operator = (const __shared54 &);
    int operator == (const __shared54 &) const;
    int operator != (const __shared54 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

typedef __shared56 UplinkUEAssociatedLPPaTransport;

class OSS_PUBLIC DownlinkNonUEAssociatedLPPaTransport_IEs_Value : public OssConstrainedOpenType
{
public:
    DownlinkNonUEAssociatedLPPaTransport_IEs_Value();
    DownlinkNonUEAssociatedLPPaTransport_IEs_Value(const DownlinkNonUEAssociatedLPPaTransport_IEs_Value &);
    ~DownlinkNonUEAssociatedLPPaTransport_IEs_Value();
    DownlinkNonUEAssociatedLPPaTransport_IEs_Value & operator = (const DownlinkNonUEAssociatedLPPaTransport_IEs_Value &);
    int operator == (const DownlinkNonUEAssociatedLPPaTransport_IEs_Value &) const;
    int operator != (const DownlinkNonUEAssociatedLPPaTransport_IEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    Routing_ID *get_Routing_ID();
    const Routing_ID *get_Routing_ID() const;
    void set_Routing_ID(const Routing_ID &);
    Routing_ID *release_Routing_ID();
    void set_Routing_ID(Routing_ID *);

    LPPa_PDU *get_LPPa_PDU();
    const LPPa_PDU *get_LPPa_PDU() const;
    void set_LPPa_PDU(const LPPa_PDU &);
    LPPa_PDU *release_LPPa_PDU();
    void set_LPPa_PDU(LPPa_PDU *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __shared57;

class OSS_PUBLIC __shared58 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __shared57 component;

    __shared58();
    __shared58(const __shared58 &);
    ~__shared58();

    __shared58 & operator = (const __shared58 &);
    int operator == (const __shared58 &) const;
    int operator != (const __shared58 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__shared58 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __shared58 *);

    int remove_front();
    int remove_after(OssIndex);

    __shared58 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC __shared59   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __shared58 protocolIEs;

    __shared59();
    __shared59(const __shared59 &);
    __shared59(const protocolIEs &);

    __shared59 & operator = (const __shared59 &);
    int operator == (const __shared59 &) const;
    int operator != (const __shared59 &) const;

    protocolIEs & get_protocolIEs();
    const protocolIEs & get_protocolIEs() const;
    void set_protocolIEs(const protocolIEs &);
private:
    protocolIEs protocolIEs_field;
};

typedef __shared59 DownlinkNonUEAssociatedLPPaTransport;

class OSS_PUBLIC __shared57   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef DownlinkNonUEAssociatedLPPaTransport_IEs_Value value;

    __shared57();
    __shared57(const __shared57 &);
    __shared57(id, criticality, const value &);

    __shared57 & operator = (const __shared57 &);
    int operator == (const __shared57 &) const;
    int operator != (const __shared57 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

typedef __shared59 UplinkNonUEAssociatedLPPaTransport;

class OSS_PUBLIC __seq112;

class OSS_PUBLIC E_RABToBeModifiedListBearerModInd : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq112 component;

    E_RABToBeModifiedListBearerModInd();
    E_RABToBeModifiedListBearerModInd(const E_RABToBeModifiedListBearerModInd &);
    ~E_RABToBeModifiedListBearerModInd();

    E_RABToBeModifiedListBearerModInd & operator = (const E_RABToBeModifiedListBearerModInd &);
    int operator == (const E_RABToBeModifiedListBearerModInd &) const;
    int operator != (const E_RABToBeModifiedListBearerModInd &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(E_RABToBeModifiedListBearerModInd *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, E_RABToBeModifiedListBearerModInd *);

    int remove_front();
    int remove_after(OssIndex);

    E_RABToBeModifiedListBearerModInd *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC __seq114;

class OSS_PUBLIC E_RABNotToBeModifiedListBearerModInd : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq114 component;

    E_RABNotToBeModifiedListBearerModInd();
    E_RABNotToBeModifiedListBearerModInd(const E_RABNotToBeModifiedListBearerModInd &);
    ~E_RABNotToBeModifiedListBearerModInd();

    E_RABNotToBeModifiedListBearerModInd & operator = (const E_RABNotToBeModifiedListBearerModInd &);
    int operator == (const E_RABNotToBeModifiedListBearerModInd &) const;
    int operator != (const E_RABNotToBeModifiedListBearerModInd &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(E_RABNotToBeModifiedListBearerModInd *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, E_RABNotToBeModifiedListBearerModInd *);

    int remove_front();
    int remove_after(OssIndex);

    E_RABNotToBeModifiedListBearerModInd *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC CSGMembershipInfo   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef enum CSGMembershipStatus cSGMembershipStatus;
    typedef OssBitString cSG_Id;
    typedef enum CellAccessMode cellAccessMode;
    typedef OssString pLMNidentity;
    typedef __shared2 iE_Extensions;

    CSGMembershipInfo();
    CSGMembershipInfo(const CSGMembershipInfo &);
    CSGMembershipInfo(cSGMembershipStatus, const cSG_Id &, cellAccessMode, const pLMNidentity &, 
	const iE_Extensions &);
    CSGMembershipInfo(cSGMembershipStatus, const cSG_Id &);

    CSGMembershipInfo & operator = (const CSGMembershipInfo &);
    int operator == (const CSGMembershipInfo &) const;
    int operator != (const CSGMembershipInfo &) const;

    cSGMembershipStatus & get_cSGMembershipStatus();
    cSGMembershipStatus get_cSGMembershipStatus() const;
    void set_cSGMembershipStatus(cSGMembershipStatus);

    cSG_Id & get_cSG_Id();
    const cSG_Id & get_cSG_Id() const;
    void set_cSG_Id(const cSG_Id &);

    cellAccessMode *get_cellAccessMode();
    const cellAccessMode *get_cellAccessMode() const;
    void set_cellAccessMode(cellAccessMode);
    int cellAccessMode_is_present() const;
    void omit_cellAccessMode();

    pLMNidentity *get_pLMNidentity();
    const pLMNidentity *get_pLMNidentity() const;
    void set_pLMNidentity(const pLMNidentity &);
    int pLMNidentity_is_present() const;
    void omit_pLMNidentity();

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    cSGMembershipStatus cSGMembershipStatus_field;
    cSG_Id cSG_Id_field;
    cellAccessMode cellAccessMode_field;
    pLMNidentity pLMNidentity_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC E_RABModificationIndicationIEs_Value : public OssConstrainedOpenType
{
public:
    E_RABModificationIndicationIEs_Value();
    E_RABModificationIndicationIEs_Value(const E_RABModificationIndicationIEs_Value &);
    ~E_RABModificationIndicationIEs_Value();
    E_RABModificationIndicationIEs_Value & operator = (const E_RABModificationIndicationIEs_Value &);
    int operator == (const E_RABModificationIndicationIEs_Value &) const;
    int operator != (const E_RABModificationIndicationIEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    MME_UE_S1AP_ID *get_MME_UE_S1AP_ID();
    const MME_UE_S1AP_ID *get_MME_UE_S1AP_ID() const;
    void set_MME_UE_S1AP_ID(const MME_UE_S1AP_ID &);
    MME_UE_S1AP_ID *release_MME_UE_S1AP_ID();
    void set_MME_UE_S1AP_ID(MME_UE_S1AP_ID *);

    ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID();
    const ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID() const;
    void set_ENB_UE_S1AP_ID(const ENB_UE_S1AP_ID &);
    ENB_UE_S1AP_ID *release_ENB_UE_S1AP_ID();
    void set_ENB_UE_S1AP_ID(ENB_UE_S1AP_ID *);

    E_RABToBeModifiedListBearerModInd *get_E_RABToBeModifiedListBearerModInd();
    const E_RABToBeModifiedListBearerModInd *get_E_RABToBeModifiedListBearerModInd() const;
    void set_E_RABToBeModifiedListBearerModInd(const E_RABToBeModifiedListBearerModInd &);
    E_RABToBeModifiedListBearerModInd *release_E_RABToBeModifiedListBearerModInd();
    void set_E_RABToBeModifiedListBearerModInd(E_RABToBeModifiedListBearerModInd *);

    E_RABNotToBeModifiedListBearerModInd *get_E_RABNotToBeModifiedListBearerModInd();
    const E_RABNotToBeModifiedListBearerModInd *get_E_RABNotToBeModifiedListBearerModInd() const;
    void set_E_RABNotToBeModifiedListBearerModInd(const E_RABNotToBeModifiedListBearerModInd &);
    E_RABNotToBeModifiedListBearerModInd *release_E_RABNotToBeModifiedListBearerModInd();
    void set_E_RABNotToBeModifiedListBearerModInd(E_RABNotToBeModifiedListBearerModInd *);

    CSGMembershipInfo *get_CSGMembershipInfo();
    const CSGMembershipInfo *get_CSGMembershipInfo() const;
    void set_CSGMembershipInfo(const CSGMembershipInfo &);
    CSGMembershipInfo *release_CSGMembershipInfo();
    void set_CSGMembershipInfo(CSGMembershipInfo *);

    TunnelInformation *get_TunnelInformation();
    const TunnelInformation *get_TunnelInformation() const;
    void set_TunnelInformation(const TunnelInformation &);
    TunnelInformation *release_TunnelInformation();
    void set_TunnelInformation(TunnelInformation *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq111;

class OSS_PUBLIC __seqof96 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq111 component;

    __seqof96();
    __seqof96(const __seqof96 &);
    ~__seqof96();

    __seqof96 & operator = (const __seqof96 &);
    int operator == (const __seqof96 &) const;
    int operator != (const __seqof96 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof96 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof96 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof96 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC E_RABModificationIndication   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __seqof96 protocolIEs;

    E_RABModificationIndication();
    E_RABModificationIndication(const E_RABModificationIndication &);
    E_RABModificationIndication(const protocolIEs &);

    E_RABModificationIndication & operator = (const E_RABModificationIndication &);
    int operator == (const E_RABModificationIndication &) const;
    int operator != (const E_RABModificationIndication &) const;

    protocolIEs & get_protocolIEs();
    const protocolIEs & get_protocolIEs() const;
    void set_protocolIEs(const protocolIEs &);
private:
    protocolIEs protocolIEs_field;
};

class OSS_PUBLIC __seq111   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef E_RABModificationIndicationIEs_Value value;

    __seq111();
    __seq111(const __seq111 &);
    __seq111(id, criticality, const value &);

    __seq111 & operator = (const __seq111 &);
    int operator == (const __seq111 &) const;
    int operator != (const __seq111 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC __shared60   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_INT32 e_RAB_ID;
    typedef OssBitString transportLayerAddress;
    typedef OssString dL_GTP_TEID;
    typedef __shared2 iE_Extensions;

    __shared60();
    __shared60(const __shared60 &);
    __shared60(e_RAB_ID, const transportLayerAddress &, const dL_GTP_TEID &, const iE_Extensions &);
    __shared60(e_RAB_ID, const transportLayerAddress &, const dL_GTP_TEID &);

    __shared60 & operator = (const __shared60 &);
    int operator == (const __shared60 &) const;
    int operator != (const __shared60 &) const;

    e_RAB_ID & get_e_RAB_ID();
    e_RAB_ID get_e_RAB_ID() const;
    void set_e_RAB_ID(e_RAB_ID);

    transportLayerAddress & get_transportLayerAddress();
    const transportLayerAddress & get_transportLayerAddress() const;
    void set_transportLayerAddress(const transportLayerAddress &);

    dL_GTP_TEID & get_dL_GTP_TEID();
    const dL_GTP_TEID & get_dL_GTP_TEID() const;
    void set_dL_GTP_TEID(const dL_GTP_TEID &);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    e_RAB_ID e_RAB_ID_field;
    transportLayerAddress transportLayerAddress_field;
    dL_GTP_TEID dL_GTP_TEID_field;
    iE_Extensions iE_Extensions_field;
};

typedef __shared60 E_RABToBeModifiedItemBearerModInd;

class OSS_PUBLIC E_RABToBeModifiedItemBearerModIndIEs_Value : public OssConstrainedOpenType
{
public:
    E_RABToBeModifiedItemBearerModIndIEs_Value();
    E_RABToBeModifiedItemBearerModIndIEs_Value(const E_RABToBeModifiedItemBearerModIndIEs_Value &);
    ~E_RABToBeModifiedItemBearerModIndIEs_Value();
    E_RABToBeModifiedItemBearerModIndIEs_Value & operator = (const E_RABToBeModifiedItemBearerModIndIEs_Value &);
    int operator == (const E_RABToBeModifiedItemBearerModIndIEs_Value &) const;
    int operator != (const E_RABToBeModifiedItemBearerModIndIEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    __shared60 *get_E_RABToBeModifiedItemBearerModInd();
    const __shared60 *get_E_RABToBeModifiedItemBearerModInd() const;
    void set_E_RABToBeModifiedItemBearerModInd(const __shared60 &);
    __shared60 *release_E_RABToBeModifiedItemBearerModInd();
    void set_E_RABToBeModifiedItemBearerModInd(__shared60 *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq112   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef E_RABToBeModifiedItemBearerModIndIEs_Value value;

    __seq112();
    __seq112(const __seq112 &);
    __seq112(id, criticality, const value &);

    __seq112 & operator = (const __seq112 &);
    int operator == (const __seq112 &) const;
    int operator != (const __seq112 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

typedef __shared60 E_RABNotToBeModifiedItemBearerModInd;

class OSS_PUBLIC E_RABNotToBeModifiedItemBearerModIndIEs_Value : public OssConstrainedOpenType
{
public:
    E_RABNotToBeModifiedItemBearerModIndIEs_Value();
    E_RABNotToBeModifiedItemBearerModIndIEs_Value(const E_RABNotToBeModifiedItemBearerModIndIEs_Value &);
    ~E_RABNotToBeModifiedItemBearerModIndIEs_Value();
    E_RABNotToBeModifiedItemBearerModIndIEs_Value & operator = (const E_RABNotToBeModifiedItemBearerModIndIEs_Value &);
    int operator == (const E_RABNotToBeModifiedItemBearerModIndIEs_Value &) const;
    int operator != (const E_RABNotToBeModifiedItemBearerModIndIEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    __shared60 *get_E_RABNotToBeModifiedItemBearerModInd();
    const __shared60 *get_E_RABNotToBeModifiedItemBearerModInd() const;
    void set_E_RABNotToBeModifiedItemBearerModInd(const __shared60 &);
    __shared60 *release_E_RABNotToBeModifiedItemBearerModInd();
    void set_E_RABNotToBeModifiedItemBearerModInd(__shared60 *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq114   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef E_RABNotToBeModifiedItemBearerModIndIEs_Value value;

    __seq114();
    __seq114(const __seq114 &);
    __seq114(id, criticality, const value &);

    __seq114 & operator = (const __seq114 &);
    int operator == (const __seq114 &) const;
    int operator != (const __seq114 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC __seq118;

class OSS_PUBLIC E_RABModifyListBearerModConf : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq118 component;

    E_RABModifyListBearerModConf();
    E_RABModifyListBearerModConf(const E_RABModifyListBearerModConf &);
    ~E_RABModifyListBearerModConf();

    E_RABModifyListBearerModConf & operator = (const E_RABModifyListBearerModConf &);
    int operator == (const E_RABModifyListBearerModConf &) const;
    int operator != (const E_RABModifyListBearerModConf &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(E_RABModifyListBearerModConf *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, E_RABModifyListBearerModConf *);

    int remove_front();
    int remove_after(OssIndex);

    E_RABModifyListBearerModConf *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC E_RABModificationConfirmIEs_Value : public OssConstrainedOpenType
{
public:
    E_RABModificationConfirmIEs_Value();
    E_RABModificationConfirmIEs_Value(const E_RABModificationConfirmIEs_Value &);
    ~E_RABModificationConfirmIEs_Value();
    E_RABModificationConfirmIEs_Value & operator = (const E_RABModificationConfirmIEs_Value &);
    int operator == (const E_RABModificationConfirmIEs_Value &) const;
    int operator != (const E_RABModificationConfirmIEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    MME_UE_S1AP_ID *get_MME_UE_S1AP_ID();
    const MME_UE_S1AP_ID *get_MME_UE_S1AP_ID() const;
    void set_MME_UE_S1AP_ID(const MME_UE_S1AP_ID &);
    MME_UE_S1AP_ID *release_MME_UE_S1AP_ID();
    void set_MME_UE_S1AP_ID(MME_UE_S1AP_ID *);

    ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID();
    const ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID() const;
    void set_ENB_UE_S1AP_ID(const ENB_UE_S1AP_ID &);
    ENB_UE_S1AP_ID *release_ENB_UE_S1AP_ID();
    void set_ENB_UE_S1AP_ID(ENB_UE_S1AP_ID *);

    E_RABModifyListBearerModConf *get_E_RABModifyListBearerModConf();
    const E_RABModifyListBearerModConf *get_E_RABModifyListBearerModConf() const;
    void set_E_RABModifyListBearerModConf(const E_RABModifyListBearerModConf &);
    E_RABModifyListBearerModConf *release_E_RABModifyListBearerModConf();
    void set_E_RABModifyListBearerModConf(E_RABModifyListBearerModConf *);

    E_RABList *get_E_RABList();
    const E_RABList *get_E_RABList() const;
    void set_E_RABList(const E_RABList &);
    E_RABList *release_E_RABList();
    void set_E_RABList(E_RABList *);

    CriticalityDiagnostics *get_CriticalityDiagnostics();
    const CriticalityDiagnostics *get_CriticalityDiagnostics() const;
    void set_CriticalityDiagnostics(const CriticalityDiagnostics &);
    CriticalityDiagnostics *release_CriticalityDiagnostics();
    void set_CriticalityDiagnostics(CriticalityDiagnostics *);

    CSGMembershipStatus *get_CSGMembershipStatus();
    const CSGMembershipStatus *get_CSGMembershipStatus() const;
    void set_CSGMembershipStatus(const CSGMembershipStatus &);
    CSGMembershipStatus *release_CSGMembershipStatus();
    void set_CSGMembershipStatus(CSGMembershipStatus *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq117;

class OSS_PUBLIC __seqof100 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq117 component;

    __seqof100();
    __seqof100(const __seqof100 &);
    ~__seqof100();

    __seqof100 & operator = (const __seqof100 &);
    int operator == (const __seqof100 &) const;
    int operator != (const __seqof100 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof100 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof100 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof100 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC E_RABModificationConfirm   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __seqof100 protocolIEs;

    E_RABModificationConfirm();
    E_RABModificationConfirm(const E_RABModificationConfirm &);
    E_RABModificationConfirm(const protocolIEs &);

    E_RABModificationConfirm & operator = (const E_RABModificationConfirm &);
    int operator == (const E_RABModificationConfirm &) const;
    int operator != (const E_RABModificationConfirm &) const;

    protocolIEs & get_protocolIEs();
    const protocolIEs & get_protocolIEs() const;
    void set_protocolIEs(const protocolIEs &);
private:
    protocolIEs protocolIEs_field;
};

class OSS_PUBLIC __seq117   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef E_RABModificationConfirmIEs_Value value;

    __seq117();
    __seq117(const __seq117 &);
    __seq117(id, criticality, const value &);

    __seq117 & operator = (const __seq117 &);
    int operator == (const __seq117 &) const;
    int operator != (const __seq117 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

typedef __shared32 E_RABModifyItemBearerModConf;

class OSS_PUBLIC E_RABModifyItemBearerModConfIEs_Value : public OssConstrainedOpenType
{
public:
    E_RABModifyItemBearerModConfIEs_Value();
    E_RABModifyItemBearerModConfIEs_Value(const E_RABModifyItemBearerModConfIEs_Value &);
    ~E_RABModifyItemBearerModConfIEs_Value();
    E_RABModifyItemBearerModConfIEs_Value & operator = (const E_RABModifyItemBearerModConfIEs_Value &);
    int operator == (const E_RABModifyItemBearerModConfIEs_Value &) const;
    int operator != (const E_RABModifyItemBearerModConfIEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    __shared32 *get_E_RABModifyItemBearerModConf();
    const __shared32 *get_E_RABModifyItemBearerModConf() const;
    void set_E_RABModifyItemBearerModConf(const __shared32 &);
    __shared32 *release_E_RABModifyItemBearerModConf();
    void set_E_RABModifyItemBearerModConf(__shared32 *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq118   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef E_RABModifyItemBearerModConfIEs_Value value;

    __seq118();
    __seq118(const __seq118 &);
    __seq118(id, criticality, const value &);

    __seq118 & operator = (const __seq118 &);
    int operator == (const __seq118 &) const;
    int operator != (const __seq118 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC UEContextModificationIndicationIEs_Value : public OssConstrainedOpenType
{
public:
    UEContextModificationIndicationIEs_Value();
    UEContextModificationIndicationIEs_Value(const UEContextModificationIndicationIEs_Value &);
    ~UEContextModificationIndicationIEs_Value();
    UEContextModificationIndicationIEs_Value & operator = (const UEContextModificationIndicationIEs_Value &);
    int operator == (const UEContextModificationIndicationIEs_Value &) const;
    int operator != (const UEContextModificationIndicationIEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    MME_UE_S1AP_ID *get_MME_UE_S1AP_ID();
    const MME_UE_S1AP_ID *get_MME_UE_S1AP_ID() const;
    void set_MME_UE_S1AP_ID(const MME_UE_S1AP_ID &);
    MME_UE_S1AP_ID *release_MME_UE_S1AP_ID();
    void set_MME_UE_S1AP_ID(MME_UE_S1AP_ID *);

    ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID();
    const ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID() const;
    void set_ENB_UE_S1AP_ID(const ENB_UE_S1AP_ID &);
    ENB_UE_S1AP_ID *release_ENB_UE_S1AP_ID();
    void set_ENB_UE_S1AP_ID(ENB_UE_S1AP_ID *);

    CSGMembershipInfo *get_CSGMembershipInfo();
    const CSGMembershipInfo *get_CSGMembershipInfo() const;
    void set_CSGMembershipInfo(const CSGMembershipInfo &);
    CSGMembershipInfo *release_CSGMembershipInfo();
    void set_CSGMembershipInfo(CSGMembershipInfo *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq120;

class OSS_PUBLIC __seqof102 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq120 component;

    __seqof102();
    __seqof102(const __seqof102 &);
    ~__seqof102();

    __seqof102 & operator = (const __seqof102 &);
    int operator == (const __seqof102 &) const;
    int operator != (const __seqof102 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof102 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof102 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof102 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC UEContextModificationIndication   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __seqof102 protocolIEs;

    UEContextModificationIndication();
    UEContextModificationIndication(const UEContextModificationIndication &);
    UEContextModificationIndication(const protocolIEs &);

    UEContextModificationIndication & operator = (const UEContextModificationIndication &);
    int operator == (const UEContextModificationIndication &) const;
    int operator != (const UEContextModificationIndication &) const;

    protocolIEs & get_protocolIEs();
    const protocolIEs & get_protocolIEs() const;
    void set_protocolIEs(const protocolIEs &);
private:
    protocolIEs protocolIEs_field;
};

class OSS_PUBLIC __seq120   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef UEContextModificationIndicationIEs_Value value;

    __seq120();
    __seq120(const __seq120 &);
    __seq120(id, criticality, const value &);

    __seq120 & operator = (const __seq120 &);
    int operator == (const __seq120 &) const;
    int operator != (const __seq120 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC UEContextModificationConfirmIEs_Value : public OssConstrainedOpenType
{
public:
    UEContextModificationConfirmIEs_Value();
    UEContextModificationConfirmIEs_Value(const UEContextModificationConfirmIEs_Value &);
    ~UEContextModificationConfirmIEs_Value();
    UEContextModificationConfirmIEs_Value & operator = (const UEContextModificationConfirmIEs_Value &);
    int operator == (const UEContextModificationConfirmIEs_Value &) const;
    int operator != (const UEContextModificationConfirmIEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    MME_UE_S1AP_ID *get_MME_UE_S1AP_ID();
    const MME_UE_S1AP_ID *get_MME_UE_S1AP_ID() const;
    void set_MME_UE_S1AP_ID(const MME_UE_S1AP_ID &);
    MME_UE_S1AP_ID *release_MME_UE_S1AP_ID();
    void set_MME_UE_S1AP_ID(MME_UE_S1AP_ID *);

    ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID();
    const ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID() const;
    void set_ENB_UE_S1AP_ID(const ENB_UE_S1AP_ID &);
    ENB_UE_S1AP_ID *release_ENB_UE_S1AP_ID();
    void set_ENB_UE_S1AP_ID(ENB_UE_S1AP_ID *);

    CSGMembershipStatus *get_CSGMembershipStatus();
    const CSGMembershipStatus *get_CSGMembershipStatus() const;
    void set_CSGMembershipStatus(const CSGMembershipStatus &);
    CSGMembershipStatus *release_CSGMembershipStatus();
    void set_CSGMembershipStatus(CSGMembershipStatus *);

    CriticalityDiagnostics *get_CriticalityDiagnostics();
    const CriticalityDiagnostics *get_CriticalityDiagnostics() const;
    void set_CriticalityDiagnostics(const CriticalityDiagnostics &);
    CriticalityDiagnostics *release_CriticalityDiagnostics();
    void set_CriticalityDiagnostics(CriticalityDiagnostics *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq121;

class OSS_PUBLIC __seqof103 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq121 component;

    __seqof103();
    __seqof103(const __seqof103 &);
    ~__seqof103();

    __seqof103 & operator = (const __seqof103 &);
    int operator == (const __seqof103 &) const;
    int operator != (const __seqof103 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof103 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof103 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof103 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC UEContextModificationConfirm   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __seqof103 protocolIEs;

    UEContextModificationConfirm();
    UEContextModificationConfirm(const UEContextModificationConfirm &);
    UEContextModificationConfirm(const protocolIEs &);

    UEContextModificationConfirm & operator = (const UEContextModificationConfirm &);
    int operator == (const UEContextModificationConfirm &) const;
    int operator != (const UEContextModificationConfirm &) const;

    protocolIEs & get_protocolIEs();
    const protocolIEs & get_protocolIEs() const;
    void set_protocolIEs(const protocolIEs &);
private:
    protocolIEs protocolIEs_field;
};

class OSS_PUBLIC __seq121   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef UEContextModificationConfirmIEs_Value value;

    __seq121();
    __seq121(const __seq121 &);
    __seq121(id, criticality, const value &);

    __seq121 & operator = (const __seq121 &);
    int operator == (const __seq121 &) const;
    int operator != (const __seq121 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC UEContextSuspendRequestIEs_Value : public OssConstrainedOpenType
{
public:
    UEContextSuspendRequestIEs_Value();
    UEContextSuspendRequestIEs_Value(const UEContextSuspendRequestIEs_Value &);
    ~UEContextSuspendRequestIEs_Value();
    UEContextSuspendRequestIEs_Value & operator = (const UEContextSuspendRequestIEs_Value &);
    int operator == (const UEContextSuspendRequestIEs_Value &) const;
    int operator != (const UEContextSuspendRequestIEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    MME_UE_S1AP_ID *get_MME_UE_S1AP_ID();
    const MME_UE_S1AP_ID *get_MME_UE_S1AP_ID() const;
    void set_MME_UE_S1AP_ID(const MME_UE_S1AP_ID &);
    MME_UE_S1AP_ID *release_MME_UE_S1AP_ID();
    void set_MME_UE_S1AP_ID(MME_UE_S1AP_ID *);

    ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID();
    const ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID() const;
    void set_ENB_UE_S1AP_ID(const ENB_UE_S1AP_ID &);
    ENB_UE_S1AP_ID *release_ENB_UE_S1AP_ID();
    void set_ENB_UE_S1AP_ID(ENB_UE_S1AP_ID *);

    InformationOnRecommendedCellsAndENBsForPaging *get_InformationOnRecommendedCellsAndENBsForPaging();
    const InformationOnRecommendedCellsAndENBsForPaging *get_InformationOnRecommendedCellsAndENBsForPaging() const;
    void set_InformationOnRecommendedCellsAndENBsForPaging(const InformationOnRecommendedCellsAndENBsForPaging &);
    InformationOnRecommendedCellsAndENBsForPaging *release_InformationOnRecommendedCellsAndENBsForPaging();
    void set_InformationOnRecommendedCellsAndENBsForPaging(InformationOnRecommendedCellsAndENBsForPaging *);

    CellIdentifierAndCELevelForCECapableUEs *get_CellIdentifierAndCELevelForCECapableUEs();
    const CellIdentifierAndCELevelForCECapableUEs *get_CellIdentifierAndCELevelForCECapableUEs() const;
    void set_CellIdentifierAndCELevelForCECapableUEs(const CellIdentifierAndCELevelForCECapableUEs &);
    CellIdentifierAndCELevelForCECapableUEs *release_CellIdentifierAndCELevelForCECapableUEs();
    void set_CellIdentifierAndCELevelForCECapableUEs(CellIdentifierAndCELevelForCECapableUEs *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq122;

class OSS_PUBLIC __seqof104 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq122 component;

    __seqof104();
    __seqof104(const __seqof104 &);
    ~__seqof104();

    __seqof104 & operator = (const __seqof104 &);
    int operator == (const __seqof104 &) const;
    int operator != (const __seqof104 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof104 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof104 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof104 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC UEContextSuspendRequest   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __seqof104 protocolIEs;

    UEContextSuspendRequest();
    UEContextSuspendRequest(const UEContextSuspendRequest &);
    UEContextSuspendRequest(const protocolIEs &);

    UEContextSuspendRequest & operator = (const UEContextSuspendRequest &);
    int operator == (const UEContextSuspendRequest &) const;
    int operator != (const UEContextSuspendRequest &) const;

    protocolIEs & get_protocolIEs();
    const protocolIEs & get_protocolIEs() const;
    void set_protocolIEs(const protocolIEs &);
private:
    protocolIEs protocolIEs_field;
};

class OSS_PUBLIC __seq122   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef UEContextSuspendRequestIEs_Value value;

    __seq122();
    __seq122(const __seq122 &);
    __seq122(id, criticality, const value &);

    __seq122 & operator = (const __seq122 &);
    int operator == (const __seq122 &) const;
    int operator != (const __seq122 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC UEContextSuspendResponseIEs_Value : public OssConstrainedOpenType
{
public:
    UEContextSuspendResponseIEs_Value();
    UEContextSuspendResponseIEs_Value(const UEContextSuspendResponseIEs_Value &);
    ~UEContextSuspendResponseIEs_Value();
    UEContextSuspendResponseIEs_Value & operator = (const UEContextSuspendResponseIEs_Value &);
    int operator == (const UEContextSuspendResponseIEs_Value &) const;
    int operator != (const UEContextSuspendResponseIEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    MME_UE_S1AP_ID *get_MME_UE_S1AP_ID();
    const MME_UE_S1AP_ID *get_MME_UE_S1AP_ID() const;
    void set_MME_UE_S1AP_ID(const MME_UE_S1AP_ID &);
    MME_UE_S1AP_ID *release_MME_UE_S1AP_ID();
    void set_MME_UE_S1AP_ID(MME_UE_S1AP_ID *);

    ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID();
    const ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID() const;
    void set_ENB_UE_S1AP_ID(const ENB_UE_S1AP_ID &);
    ENB_UE_S1AP_ID *release_ENB_UE_S1AP_ID();
    void set_ENB_UE_S1AP_ID(ENB_UE_S1AP_ID *);

    CriticalityDiagnostics *get_CriticalityDiagnostics();
    const CriticalityDiagnostics *get_CriticalityDiagnostics() const;
    void set_CriticalityDiagnostics(const CriticalityDiagnostics &);
    CriticalityDiagnostics *release_CriticalityDiagnostics();
    void set_CriticalityDiagnostics(CriticalityDiagnostics *);

    SecurityContext *get_SecurityContext();
    const SecurityContext *get_SecurityContext() const;
    void set_SecurityContext(const SecurityContext &);
    SecurityContext *release_SecurityContext();
    void set_SecurityContext(SecurityContext *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq123;

class OSS_PUBLIC __seqof105 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq123 component;

    __seqof105();
    __seqof105(const __seqof105 &);
    ~__seqof105();

    __seqof105 & operator = (const __seqof105 &);
    int operator == (const __seqof105 &) const;
    int operator != (const __seqof105 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof105 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof105 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof105 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC UEContextSuspendResponse   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __seqof105 protocolIEs;

    UEContextSuspendResponse();
    UEContextSuspendResponse(const UEContextSuspendResponse &);
    UEContextSuspendResponse(const protocolIEs &);

    UEContextSuspendResponse & operator = (const UEContextSuspendResponse &);
    int operator == (const UEContextSuspendResponse &) const;
    int operator != (const UEContextSuspendResponse &) const;

    protocolIEs & get_protocolIEs();
    const protocolIEs & get_protocolIEs() const;
    void set_protocolIEs(const protocolIEs &);
private:
    protocolIEs protocolIEs_field;
};

class OSS_PUBLIC __seq123   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef UEContextSuspendResponseIEs_Value value;

    __seq123();
    __seq123(const __seq123 &);
    __seq123(id, criticality, const value &);

    __seq123 & operator = (const __seq123 &);
    int operator == (const __seq123 &) const;
    int operator != (const __seq123 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC __seq125;

class OSS_PUBLIC E_RABFailedToResumeListResumeReq : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq125 component;

    E_RABFailedToResumeListResumeReq();
    E_RABFailedToResumeListResumeReq(const E_RABFailedToResumeListResumeReq &);
    ~E_RABFailedToResumeListResumeReq();

    E_RABFailedToResumeListResumeReq & operator = (const E_RABFailedToResumeListResumeReq &);
    int operator == (const E_RABFailedToResumeListResumeReq &) const;
    int operator != (const E_RABFailedToResumeListResumeReq &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(E_RABFailedToResumeListResumeReq *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, E_RABFailedToResumeListResumeReq *);

    int remove_front();
    int remove_after(OssIndex);

    E_RABFailedToResumeListResumeReq *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC UEContextResumeRequestIEs_Value : public OssConstrainedOpenType
{
public:
    UEContextResumeRequestIEs_Value();
    UEContextResumeRequestIEs_Value(const UEContextResumeRequestIEs_Value &);
    ~UEContextResumeRequestIEs_Value();
    UEContextResumeRequestIEs_Value & operator = (const UEContextResumeRequestIEs_Value &);
    int operator == (const UEContextResumeRequestIEs_Value &) const;
    int operator != (const UEContextResumeRequestIEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    MME_UE_S1AP_ID *get_MME_UE_S1AP_ID();
    const MME_UE_S1AP_ID *get_MME_UE_S1AP_ID() const;
    void set_MME_UE_S1AP_ID(const MME_UE_S1AP_ID &);
    MME_UE_S1AP_ID *release_MME_UE_S1AP_ID();
    void set_MME_UE_S1AP_ID(MME_UE_S1AP_ID *);

    ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID();
    const ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID() const;
    void set_ENB_UE_S1AP_ID(const ENB_UE_S1AP_ID &);
    ENB_UE_S1AP_ID *release_ENB_UE_S1AP_ID();
    void set_ENB_UE_S1AP_ID(ENB_UE_S1AP_ID *);

    E_RABFailedToResumeListResumeReq *get_E_RABFailedToResumeListResumeReq();
    const E_RABFailedToResumeListResumeReq *get_E_RABFailedToResumeListResumeReq() const;
    void set_E_RABFailedToResumeListResumeReq(const E_RABFailedToResumeListResumeReq &);
    E_RABFailedToResumeListResumeReq *release_E_RABFailedToResumeListResumeReq();
    void set_E_RABFailedToResumeListResumeReq(E_RABFailedToResumeListResumeReq *);

    RRC_Establishment_Cause *get_RRC_Establishment_Cause();
    const RRC_Establishment_Cause *get_RRC_Establishment_Cause() const;
    void set_RRC_Establishment_Cause(const RRC_Establishment_Cause &);
    RRC_Establishment_Cause *release_RRC_Establishment_Cause();
    void set_RRC_Establishment_Cause(RRC_Establishment_Cause *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq124;

class OSS_PUBLIC __seqof106 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq124 component;

    __seqof106();
    __seqof106(const __seqof106 &);
    ~__seqof106();

    __seqof106 & operator = (const __seqof106 &);
    int operator == (const __seqof106 &) const;
    int operator != (const __seqof106 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof106 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof106 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof106 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC UEContextResumeRequest   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __seqof106 protocolIEs;

    UEContextResumeRequest();
    UEContextResumeRequest(const UEContextResumeRequest &);
    UEContextResumeRequest(const protocolIEs &);

    UEContextResumeRequest & operator = (const UEContextResumeRequest &);
    int operator == (const UEContextResumeRequest &) const;
    int operator != (const UEContextResumeRequest &) const;

    protocolIEs & get_protocolIEs();
    const protocolIEs & get_protocolIEs() const;
    void set_protocolIEs(const protocolIEs &);
private:
    protocolIEs protocolIEs_field;
};

class OSS_PUBLIC __seq124   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef UEContextResumeRequestIEs_Value value;

    __seq124();
    __seq124(const __seq124 &);
    __seq124(id, criticality, const value &);

    __seq124 & operator = (const __seq124 &);
    int operator == (const __seq124 &) const;
    int operator != (const __seq124 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

typedef __shared11 E_RABFailedToResumeItemResumeReq;

class OSS_PUBLIC E_RABFailedToResumeItemResumeReqIEs_Value : public OssConstrainedOpenType
{
public:
    E_RABFailedToResumeItemResumeReqIEs_Value();
    E_RABFailedToResumeItemResumeReqIEs_Value(const E_RABFailedToResumeItemResumeReqIEs_Value &);
    ~E_RABFailedToResumeItemResumeReqIEs_Value();
    E_RABFailedToResumeItemResumeReqIEs_Value & operator = (const E_RABFailedToResumeItemResumeReqIEs_Value &);
    int operator == (const E_RABFailedToResumeItemResumeReqIEs_Value &) const;
    int operator != (const E_RABFailedToResumeItemResumeReqIEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    __shared11 *get_E_RABFailedToResumeItemResumeReq();
    const __shared11 *get_E_RABFailedToResumeItemResumeReq() const;
    void set_E_RABFailedToResumeItemResumeReq(const __shared11 &);
    __shared11 *release_E_RABFailedToResumeItemResumeReq();
    void set_E_RABFailedToResumeItemResumeReq(__shared11 *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq125   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef E_RABFailedToResumeItemResumeReqIEs_Value value;

    __seq125();
    __seq125(const __seq125 &);
    __seq125(id, criticality, const value &);

    __seq125 & operator = (const __seq125 &);
    int operator == (const __seq125 &) const;
    int operator != (const __seq125 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC __seq128;

class OSS_PUBLIC E_RABFailedToResumeListResumeRes : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq128 component;

    E_RABFailedToResumeListResumeRes();
    E_RABFailedToResumeListResumeRes(const E_RABFailedToResumeListResumeRes &);
    ~E_RABFailedToResumeListResumeRes();

    E_RABFailedToResumeListResumeRes & operator = (const E_RABFailedToResumeListResumeRes &);
    int operator == (const E_RABFailedToResumeListResumeRes &) const;
    int operator != (const E_RABFailedToResumeListResumeRes &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(E_RABFailedToResumeListResumeRes *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, E_RABFailedToResumeListResumeRes *);

    int remove_front();
    int remove_after(OssIndex);

    E_RABFailedToResumeListResumeRes *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC UEContextResumeResponseIEs_Value : public OssConstrainedOpenType
{
public:
    UEContextResumeResponseIEs_Value();
    UEContextResumeResponseIEs_Value(const UEContextResumeResponseIEs_Value &);
    ~UEContextResumeResponseIEs_Value();
    UEContextResumeResponseIEs_Value & operator = (const UEContextResumeResponseIEs_Value &);
    int operator == (const UEContextResumeResponseIEs_Value &) const;
    int operator != (const UEContextResumeResponseIEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    MME_UE_S1AP_ID *get_MME_UE_S1AP_ID();
    const MME_UE_S1AP_ID *get_MME_UE_S1AP_ID() const;
    void set_MME_UE_S1AP_ID(const MME_UE_S1AP_ID &);
    MME_UE_S1AP_ID *release_MME_UE_S1AP_ID();
    void set_MME_UE_S1AP_ID(MME_UE_S1AP_ID *);

    ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID();
    const ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID() const;
    void set_ENB_UE_S1AP_ID(const ENB_UE_S1AP_ID &);
    ENB_UE_S1AP_ID *release_ENB_UE_S1AP_ID();
    void set_ENB_UE_S1AP_ID(ENB_UE_S1AP_ID *);

    E_RABFailedToResumeListResumeRes *get_E_RABFailedToResumeListResumeRes();
    const E_RABFailedToResumeListResumeRes *get_E_RABFailedToResumeListResumeRes() const;
    void set_E_RABFailedToResumeListResumeRes(const E_RABFailedToResumeListResumeRes &);
    E_RABFailedToResumeListResumeRes *release_E_RABFailedToResumeListResumeRes();
    void set_E_RABFailedToResumeListResumeRes(E_RABFailedToResumeListResumeRes *);

    CriticalityDiagnostics *get_CriticalityDiagnostics();
    const CriticalityDiagnostics *get_CriticalityDiagnostics() const;
    void set_CriticalityDiagnostics(const CriticalityDiagnostics &);
    CriticalityDiagnostics *release_CriticalityDiagnostics();
    void set_CriticalityDiagnostics(CriticalityDiagnostics *);

    SecurityContext *get_SecurityContext();
    const SecurityContext *get_SecurityContext() const;
    void set_SecurityContext(const SecurityContext &);
    SecurityContext *release_SecurityContext();
    void set_SecurityContext(SecurityContext *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq127;

class OSS_PUBLIC __seqof108 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq127 component;

    __seqof108();
    __seqof108(const __seqof108 &);
    ~__seqof108();

    __seqof108 & operator = (const __seqof108 &);
    int operator == (const __seqof108 &) const;
    int operator != (const __seqof108 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof108 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof108 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof108 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC UEContextResumeResponse   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __seqof108 protocolIEs;

    UEContextResumeResponse();
    UEContextResumeResponse(const UEContextResumeResponse &);
    UEContextResumeResponse(const protocolIEs &);

    UEContextResumeResponse & operator = (const UEContextResumeResponse &);
    int operator == (const UEContextResumeResponse &) const;
    int operator != (const UEContextResumeResponse &) const;

    protocolIEs & get_protocolIEs();
    const protocolIEs & get_protocolIEs() const;
    void set_protocolIEs(const protocolIEs &);
private:
    protocolIEs protocolIEs_field;
};

class OSS_PUBLIC __seq127   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef UEContextResumeResponseIEs_Value value;

    __seq127();
    __seq127(const __seq127 &);
    __seq127(id, criticality, const value &);

    __seq127 & operator = (const __seq127 &);
    int operator == (const __seq127 &) const;
    int operator != (const __seq127 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

typedef __shared11 E_RABFailedToResumeItemResumeRes;

class OSS_PUBLIC E_RABFailedToResumeItemResumeResIEs_Value : public OssConstrainedOpenType
{
public:
    E_RABFailedToResumeItemResumeResIEs_Value();
    E_RABFailedToResumeItemResumeResIEs_Value(const E_RABFailedToResumeItemResumeResIEs_Value &);
    ~E_RABFailedToResumeItemResumeResIEs_Value();
    E_RABFailedToResumeItemResumeResIEs_Value & operator = (const E_RABFailedToResumeItemResumeResIEs_Value &);
    int operator == (const E_RABFailedToResumeItemResumeResIEs_Value &) const;
    int operator != (const E_RABFailedToResumeItemResumeResIEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    __shared11 *get_E_RABFailedToResumeItemResumeRes();
    const __shared11 *get_E_RABFailedToResumeItemResumeRes() const;
    void set_E_RABFailedToResumeItemResumeRes(const __shared11 &);
    __shared11 *release_E_RABFailedToResumeItemResumeRes();
    void set_E_RABFailedToResumeItemResumeRes(__shared11 *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq128   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef E_RABFailedToResumeItemResumeResIEs_Value value;

    __seq128();
    __seq128(const __seq128 &);
    __seq128(id, criticality, const value &);

    __seq128 & operator = (const __seq128 &);
    int operator == (const __seq128 &) const;
    int operator != (const __seq128 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

typedef __shared21 UEContextResumeFailure;

typedef __shared53 ConnectionEstablishmentIndication;

typedef OssString MME_Code;

typedef OssString M_TMSI;

class OSS_PUBLIC CellBasedMDT   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __shared5 cellIdListforMDT;
    typedef __shared2 iE_Extensions;

    CellBasedMDT();
    CellBasedMDT(const CellBasedMDT &);
    CellBasedMDT(const cellIdListforMDT &, const iE_Extensions &);
    CellBasedMDT(const cellIdListforMDT &);

    CellBasedMDT & operator = (const CellBasedMDT &);
    int operator == (const CellBasedMDT &) const;
    int operator != (const CellBasedMDT &) const;

    cellIdListforMDT & get_cellIdListforMDT();
    const cellIdListforMDT & get_cellIdListforMDT() const;
    void set_cellIdListforMDT(const cellIdListforMDT &);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    cellIdListforMDT cellIdListforMDT_field;
    iE_Extensions iE_Extensions_field;
};

typedef __shared4 TAListforMDT;

class OSS_PUBLIC TABasedMDT   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __shared4 tAListforMDT;
    typedef __shared2 iE_Extensions;

    TABasedMDT();
    TABasedMDT(const TABasedMDT &);
    TABasedMDT(const tAListforMDT &, const iE_Extensions &);
    TABasedMDT(const tAListforMDT &);

    TABasedMDT & operator = (const TABasedMDT &);
    int operator == (const TABasedMDT &) const;
    int operator != (const TABasedMDT &) const;

    tAListforMDT & get_tAListforMDT();
    const tAListforMDT & get_tAListforMDT() const;
    void set_tAListforMDT(const tAListforMDT &);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    tAListforMDT tAListforMDT_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC TAIBasedMDT   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __shared6 tAIListforMDT;
    typedef __shared2 iE_Extensions;

    TAIBasedMDT();
    TAIBasedMDT(const TAIBasedMDT &);
    TAIBasedMDT(const tAIListforMDT &, const iE_Extensions &);
    TAIBasedMDT(const tAIListforMDT &);

    TAIBasedMDT & operator = (const TAIBasedMDT &);
    int operator == (const TAIBasedMDT &) const;
    int operator != (const TAIBasedMDT &) const;

    tAIListforMDT & get_tAIListforMDT();
    const tAIListforMDT & get_tAIListforMDT() const;
    void set_tAIListforMDT(const tAIListforMDT &);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    tAIListforMDT tAIListforMDT_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC AreaScopeOfMDT  : public OssChoice   /* CHOICE */
{
public:
    enum Id {
	unselected,
	cellBased_chosen = 1,
	tABased_chosen = 2,
	pLMNWide_chosen = 3,
	tAIBased_chosen = 4
    };
    typedef CellBasedMDT cellBased;
    typedef TABasedMDT tABased;
    typedef Nulltype pLMNWide;
    typedef TAIBasedMDT tAIBased;

    AreaScopeOfMDT();
    AreaScopeOfMDT(const AreaScopeOfMDT &);
    ~AreaScopeOfMDT();

    AreaScopeOfMDT & operator = (const AreaScopeOfMDT &);
    int operator == (const AreaScopeOfMDT &) const;
    int operator != (const AreaScopeOfMDT &) const;

    cellBased *get_cellBased();
    const cellBased *get_cellBased() const;
    void set_cellBased(const cellBased &);

    tABased *get_tABased();
    const tABased *get_tABased() const;
    void set_tABased(const tABased &);

    pLMNWide *get_pLMNWide();
    const pLMNWide *get_pLMNWide() const;
    void set_pLMNWide(pLMNWide);

    tAIBased *get_tAIBased();
    const tAIBased *get_tAIBased() const;
    void set_tAIBased(const tAIBased &);
private:
    union {
	cellBased *cellBased_field;
	tABased *tABased_field;
	pLMNWide pLMNWide_field;
	tAIBased *tAIBased_field;
    };
    void cleanup();
};

typedef OssBitString CellIdentity;

typedef OssString CELevel;

typedef OSS_INT32 PagingAttemptCount;

typedef OSS_INT32 IntendedNumberOfPagingAttempts;

class OSS_PUBLIC COUNTvalue   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 pDCP_SN;
    typedef OSS_UINT32 hFN;
    typedef __shared2 iE_Extensions;

    COUNTvalue();
    COUNTvalue(const COUNTvalue &);
    COUNTvalue(pDCP_SN, hFN, const iE_Extensions &);
    COUNTvalue(pDCP_SN, hFN);

    COUNTvalue & operator = (const COUNTvalue &);
    int operator == (const COUNTvalue &) const;
    int operator != (const COUNTvalue &) const;

    pDCP_SN & get_pDCP_SN();
    pDCP_SN get_pDCP_SN() const;
    void set_pDCP_SN(pDCP_SN);

    hFN & get_hFN();
    hFN get_hFN() const;
    void set_hFN(hFN);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    pDCP_SN pDCP_SN_field;
    hFN hFN_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC __seq143;

class OSS_PUBLIC __seqof122 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq143 component;

    __seqof122();
    __seqof122(const __seqof122 &);
    ~__seqof122();

    __seqof122 & operator = (const __seqof122 &);
    int operator == (const __seqof122 &) const;
    int operator != (const __seqof122 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof122 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof122 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof122 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC Bearers_SubjectToStatusTransfer_Item   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_INT32 e_RAB_ID;
    typedef COUNTvalue uL_COUNTvalue;
    typedef COUNTvalue dL_COUNTvalue;
    typedef OssBitString receiveStatusofULPDCPSDUs;
    typedef __seqof122 iE_Extensions;

    Bearers_SubjectToStatusTransfer_Item();
    Bearers_SubjectToStatusTransfer_Item(const Bearers_SubjectToStatusTransfer_Item &);
    Bearers_SubjectToStatusTransfer_Item(e_RAB_ID, const uL_COUNTvalue &, const dL_COUNTvalue &, 
	const receiveStatusofULPDCPSDUs &, const iE_Extensions &);
    Bearers_SubjectToStatusTransfer_Item(e_RAB_ID, const uL_COUNTvalue &, const dL_COUNTvalue &);

    Bearers_SubjectToStatusTransfer_Item & operator = (const Bearers_SubjectToStatusTransfer_Item &);
    int operator == (const Bearers_SubjectToStatusTransfer_Item &) const;
    int operator != (const Bearers_SubjectToStatusTransfer_Item &) const;

    e_RAB_ID & get_e_RAB_ID();
    e_RAB_ID get_e_RAB_ID() const;
    void set_e_RAB_ID(e_RAB_ID);

    uL_COUNTvalue & get_uL_COUNTvalue();
    const uL_COUNTvalue & get_uL_COUNTvalue() const;
    void set_uL_COUNTvalue(const uL_COUNTvalue &);

    dL_COUNTvalue & get_dL_COUNTvalue();
    const dL_COUNTvalue & get_dL_COUNTvalue() const;
    void set_dL_COUNTvalue(const dL_COUNTvalue &);

    receiveStatusofULPDCPSDUs *get_receiveStatusofULPDCPSDUs();
    const receiveStatusofULPDCPSDUs *get_receiveStatusofULPDCPSDUs() const;
    void set_receiveStatusofULPDCPSDUs(const receiveStatusofULPDCPSDUs &);
    int receiveStatusofULPDCPSDUs_is_present() const;
    void omit_receiveStatusofULPDCPSDUs();

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    e_RAB_ID e_RAB_ID_field;
    uL_COUNTvalue uL_COUNTvalue_field;
    dL_COUNTvalue dL_COUNTvalue_field;
    receiveStatusofULPDCPSDUs receiveStatusofULPDCPSDUs_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC Bearers_SubjectToStatusTransfer_ItemIEs_Value : public OssConstrainedOpenType
{
public:
    Bearers_SubjectToStatusTransfer_ItemIEs_Value();
    Bearers_SubjectToStatusTransfer_ItemIEs_Value(const Bearers_SubjectToStatusTransfer_ItemIEs_Value &);
    ~Bearers_SubjectToStatusTransfer_ItemIEs_Value();
    Bearers_SubjectToStatusTransfer_ItemIEs_Value & operator = (const Bearers_SubjectToStatusTransfer_ItemIEs_Value &);
    int operator == (const Bearers_SubjectToStatusTransfer_ItemIEs_Value &) const;
    int operator != (const Bearers_SubjectToStatusTransfer_ItemIEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    Bearers_SubjectToStatusTransfer_Item *get_Bearers_SubjectToStatusTransfer_Item();
    const Bearers_SubjectToStatusTransfer_Item *get_Bearers_SubjectToStatusTransfer_Item() const;
    void set_Bearers_SubjectToStatusTransfer_Item(const Bearers_SubjectToStatusTransfer_Item &);
    Bearers_SubjectToStatusTransfer_Item *release_Bearers_SubjectToStatusTransfer_Item();
    void set_Bearers_SubjectToStatusTransfer_Item(Bearers_SubjectToStatusTransfer_Item *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq141   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef Bearers_SubjectToStatusTransfer_ItemIEs_Value value;

    __seq141();
    __seq141(const __seq141 &);
    __seq141(id, criticality, const value &);

    __seq141 & operator = (const __seq141 &);
    int operator == (const __seq141 &) const;
    int operator != (const __seq141 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

typedef OSS_UINT32 PDCP_SN;

typedef OSS_UINT32 HFN;

typedef OssBitString ReceiveStatusofULPDCPSDUs;

class OSS_PUBLIC COUNTValueExtended   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 pDCP_SNExtended;
    typedef OSS_UINT32 hFNModified;
    typedef __shared2 iE_Extensions;

    COUNTValueExtended();
    COUNTValueExtended(const COUNTValueExtended &);
    COUNTValueExtended(pDCP_SNExtended, hFNModified, const iE_Extensions &);
    COUNTValueExtended(pDCP_SNExtended, hFNModified);

    COUNTValueExtended & operator = (const COUNTValueExtended &);
    int operator == (const COUNTValueExtended &) const;
    int operator != (const COUNTValueExtended &) const;

    pDCP_SNExtended & get_pDCP_SNExtended();
    pDCP_SNExtended get_pDCP_SNExtended() const;
    void set_pDCP_SNExtended(pDCP_SNExtended);

    hFNModified & get_hFNModified();
    hFNModified get_hFNModified() const;
    void set_hFNModified(hFNModified);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    pDCP_SNExtended pDCP_SNExtended_field;
    hFNModified hFNModified_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC COUNTvaluePDCP_SNlength18   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 pDCP_SNlength18;
    typedef OSS_UINT32 hFNforPDCP_SNlength18;
    typedef __shared2 iE_Extensions;

    COUNTvaluePDCP_SNlength18();
    COUNTvaluePDCP_SNlength18(const COUNTvaluePDCP_SNlength18 &);
    COUNTvaluePDCP_SNlength18(pDCP_SNlength18, hFNforPDCP_SNlength18, const iE_Extensions &);
    COUNTvaluePDCP_SNlength18(pDCP_SNlength18, hFNforPDCP_SNlength18);

    COUNTvaluePDCP_SNlength18 & operator = (const COUNTvaluePDCP_SNlength18 &);
    int operator == (const COUNTvaluePDCP_SNlength18 &) const;
    int operator != (const COUNTvaluePDCP_SNlength18 &) const;

    pDCP_SNlength18 & get_pDCP_SNlength18();
    pDCP_SNlength18 get_pDCP_SNlength18() const;
    void set_pDCP_SNlength18(pDCP_SNlength18);

    hFNforPDCP_SNlength18 & get_hFNforPDCP_SNlength18();
    hFNforPDCP_SNlength18 get_hFNforPDCP_SNlength18() const;
    void set_hFNforPDCP_SNlength18(hFNforPDCP_SNlength18);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    pDCP_SNlength18 pDCP_SNlength18_field;
    hFNforPDCP_SNlength18 hFNforPDCP_SNlength18_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC Bearers_SubjectToStatusTransfer_ItemExtIEs_Extension : public OssConstrainedOpenType
{
public:
    Bearers_SubjectToStatusTransfer_ItemExtIEs_Extension();
    Bearers_SubjectToStatusTransfer_ItemExtIEs_Extension(const Bearers_SubjectToStatusTransfer_ItemExtIEs_Extension &);
    ~Bearers_SubjectToStatusTransfer_ItemExtIEs_Extension();
    Bearers_SubjectToStatusTransfer_ItemExtIEs_Extension & operator = (const Bearers_SubjectToStatusTransfer_ItemExtIEs_Extension &);
    int operator == (const Bearers_SubjectToStatusTransfer_ItemExtIEs_Extension &) const;
    int operator != (const Bearers_SubjectToStatusTransfer_ItemExtIEs_Extension &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    COUNTValueExtended *get_COUNTValueExtended();
    const COUNTValueExtended *get_COUNTValueExtended() const;
    void set_COUNTValueExtended(const COUNTValueExtended &);
    COUNTValueExtended *release_COUNTValueExtended();
    void set_COUNTValueExtended(COUNTValueExtended *);

    ReceiveStatusOfULPDCPSDUsExtended *get_ReceiveStatusOfULPDCPSDUsExtended();
    const ReceiveStatusOfULPDCPSDUsExtended *get_ReceiveStatusOfULPDCPSDUsExtended() const;
    void set_ReceiveStatusOfULPDCPSDUsExtended(const ReceiveStatusOfULPDCPSDUsExtended &);
    ReceiveStatusOfULPDCPSDUsExtended *release_ReceiveStatusOfULPDCPSDUsExtended();
    void set_ReceiveStatusOfULPDCPSDUsExtended(ReceiveStatusOfULPDCPSDUsExtended *);

    COUNTvaluePDCP_SNlength18 *get_COUNTvaluePDCP_SNlength18();
    const COUNTvaluePDCP_SNlength18 *get_COUNTvaluePDCP_SNlength18() const;
    void set_COUNTvaluePDCP_SNlength18(const COUNTvaluePDCP_SNlength18 &);
    COUNTvaluePDCP_SNlength18 *release_COUNTvaluePDCP_SNlength18();
    void set_COUNTvaluePDCP_SNlength18(COUNTvaluePDCP_SNlength18 *);

    ReceiveStatusOfULPDCPSDUsPDCP_SNlength18 *get_ReceiveStatusOfULPDCPSDUsPDCP_SNlength18();
    const ReceiveStatusOfULPDCPSDUsPDCP_SNlength18 *get_ReceiveStatusOfULPDCPSDUsPDCP_SNlength18() const;
    void set_ReceiveStatusOfULPDCPSDUsPDCP_SNlength18(const ReceiveStatusOfULPDCPSDUsPDCP_SNlength18 &);
    ReceiveStatusOfULPDCPSDUsPDCP_SNlength18 *release_ReceiveStatusOfULPDCPSDUsPDCP_SNlength18();
    void set_ReceiveStatusOfULPDCPSDUsPDCP_SNlength18(ReceiveStatusOfULPDCPSDUsPDCP_SNlength18 *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq143   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef Bearers_SubjectToStatusTransfer_ItemExtIEs_Extension extensionValue;

    __seq143();
    __seq143(const __seq143 &);
    __seq143(id, criticality, const extensionValue &);

    __seq143 & operator = (const __seq143 &);
    int operator == (const __seq143 &) const;
    int operator != (const __seq143 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    extensionValue & get_extensionValue();
    const extensionValue & get_extensionValue() const;
    void set_extensionValue(const extensionValue &);
private:
    id id_field;
    criticality criticality_field;
    extensionValue extensionValue_field;
};

typedef __shared4 BPLMNs;

typedef OSS_UINT32 NumberOfBroadcasts;

class OSS_PUBLIC __shared36   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef EUTRAN_CGI eCGI;
    typedef OSS_UINT32 numberOfBroadcasts;
    typedef __shared2 iE_Extensions;

    __shared36();
    __shared36(const __shared36 &);
    __shared36(const eCGI &, numberOfBroadcasts, const iE_Extensions &);
    __shared36(const eCGI &, numberOfBroadcasts);

    __shared36 & operator = (const __shared36 &);
    int operator == (const __shared36 &) const;
    int operator != (const __shared36 &) const;

    eCGI & get_eCGI();
    const eCGI & get_eCGI() const;
    void set_eCGI(const eCGI &);

    numberOfBroadcasts & get_numberOfBroadcasts();
    numberOfBroadcasts get_numberOfBroadcasts() const;
    void set_numberOfBroadcasts(numberOfBroadcasts);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    eCGI eCGI_field;
    numberOfBroadcasts numberOfBroadcasts_field;
    iE_Extensions iE_Extensions_field;
};

typedef __shared36 CellID_Cancelled_Item;

typedef __shared36 CancelledCellinEAI_Item;

typedef __shared37 CancelledCellinEAI;

typedef __shared36 CancelledCellinTAI_Item;

typedef __shared37 CancelledCellinTAI;

class OSS_PUBLIC __shared44   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef EUTRAN_CGI eCGI;
    typedef __shared2 iE_Extensions;

    __shared44();
    __shared44(const __shared44 &);
    __shared44(const eCGI &, const iE_Extensions &);
    __shared44(const eCGI &);

    __shared44 & operator = (const __shared44 &);
    int operator == (const __shared44 &) const;
    int operator != (const __shared44 &) const;

    eCGI & get_eCGI();
    const eCGI & get_eCGI() const;
    void set_eCGI(const eCGI &);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    eCGI eCGI_field;
    iE_Extensions iE_Extensions_field;
};

typedef __shared44 CellID_Broadcast_Item;

typedef OssString Cdma2000OneXMEID;

typedef OssString Cdma2000OneXMSI;

typedef OssString Cdma2000OneXPilot;

class OSS_PUBLIC CellType   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef enum Cell_Size cell_Size;
    typedef __shared2 iE_Extensions;

    CellType();
    CellType(const CellType &);
    CellType(cell_Size, const iE_Extensions &);
    CellType(cell_Size);

    CellType & operator = (const CellType &);
    int operator == (const CellType &) const;
    int operator != (const CellType &) const;

    cell_Size & get_cell_Size();
    cell_Size get_cell_Size() const;
    void set_cell_Size(cell_Size);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    cell_Size cell_Size_field;
    iE_Extensions iE_Extensions_field;
};

typedef OssString LAC;

typedef OssString CI;

typedef OssString RAC;

class OSS_PUBLIC CSG_IdList_Item   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OssBitString cSG_Id;
    typedef __shared2 iE_Extensions;

    CSG_IdList_Item();
    CSG_IdList_Item(const CSG_IdList_Item &);
    CSG_IdList_Item(const cSG_Id &, const iE_Extensions &);
    CSG_IdList_Item(const cSG_Id &);

    CSG_IdList_Item & operator = (const CSG_IdList_Item &);
    int operator == (const CSG_IdList_Item &) const;
    int operator != (const CSG_IdList_Item &) const;

    cSG_Id & get_cSG_Id();
    const cSG_Id & get_cSG_Id() const;
    void set_cSG_Id(const cSG_Id &);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    cSG_Id cSG_Id_field;
    iE_Extensions iE_Extensions_field;
};

typedef OSS_UINT32 PDCP_SNExtended;

typedef OSS_UINT32 HFNModified;

typedef OSS_UINT32 PDCP_SNlength18;

typedef OSS_UINT32 HFNforPDCP_SNlength18;

class OSS_PUBLIC CriticalityDiagnostics_IE_Item   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef enum Criticality iECriticality;
    typedef OSS_UINT32 iE_ID;
    typedef enum TypeOfError typeOfError;
    typedef __shared2 iE_Extensions;

    CriticalityDiagnostics_IE_Item();
    CriticalityDiagnostics_IE_Item(const CriticalityDiagnostics_IE_Item &);
    CriticalityDiagnostics_IE_Item(iECriticality, iE_ID, typeOfError, const iE_Extensions &);
    CriticalityDiagnostics_IE_Item(iECriticality, iE_ID, typeOfError);

    CriticalityDiagnostics_IE_Item & operator = (const CriticalityDiagnostics_IE_Item &);
    int operator == (const CriticalityDiagnostics_IE_Item &) const;
    int operator != (const CriticalityDiagnostics_IE_Item &) const;

    iECriticality & get_iECriticality();
    iECriticality get_iECriticality() const;
    void set_iECriticality(iECriticality);

    iE_ID & get_iE_ID();
    iE_ID get_iE_ID() const;
    void set_iE_ID(iE_ID);

    typeOfError & get_typeOfError();
    typeOfError get_typeOfError() const;
    void set_typeOfError(typeOfError);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    iECriticality iECriticality_field;
    iE_ID iE_ID_field;
    typeOfError typeOfError_field;
    iE_Extensions iE_Extensions_field;
};

typedef OSS_INT32 EARFCN;

typedef OssString EmergencyAreaID;

typedef __shared45 CompletedCellinEAI;

class OSS_PUBLIC EmergencyAreaID_Broadcast_Item   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OssString emergencyAreaID;
    typedef __shared45 completedCellinEAI;
    typedef __shared2 iE_Extensions;

    EmergencyAreaID_Broadcast_Item();
    EmergencyAreaID_Broadcast_Item(const EmergencyAreaID_Broadcast_Item &);
    EmergencyAreaID_Broadcast_Item(const emergencyAreaID &, const completedCellinEAI &, 
	const iE_Extensions &);
    EmergencyAreaID_Broadcast_Item(const emergencyAreaID &, const completedCellinEAI &);

    EmergencyAreaID_Broadcast_Item & operator = (const EmergencyAreaID_Broadcast_Item &);
    int operator == (const EmergencyAreaID_Broadcast_Item &) const;
    int operator != (const EmergencyAreaID_Broadcast_Item &) const;

    emergencyAreaID & get_emergencyAreaID();
    const emergencyAreaID & get_emergencyAreaID() const;
    void set_emergencyAreaID(const emergencyAreaID &);

    completedCellinEAI & get_completedCellinEAI();
    const completedCellinEAI & get_completedCellinEAI() const;
    void set_completedCellinEAI(const completedCellinEAI &);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    emergencyAreaID emergencyAreaID_field;
    completedCellinEAI completedCellinEAI_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC EmergencyAreaID_Cancelled_Item   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OssString emergencyAreaID;
    typedef __shared37 cancelledCellinEAI;
    typedef __shared2 iE_Extensions;

    EmergencyAreaID_Cancelled_Item();
    EmergencyAreaID_Cancelled_Item(const EmergencyAreaID_Cancelled_Item &);
    EmergencyAreaID_Cancelled_Item(const emergencyAreaID &, const cancelledCellinEAI &, 
	const iE_Extensions &);
    EmergencyAreaID_Cancelled_Item(const emergencyAreaID &, const cancelledCellinEAI &);

    EmergencyAreaID_Cancelled_Item & operator = (const EmergencyAreaID_Cancelled_Item &);
    int operator == (const EmergencyAreaID_Cancelled_Item &) const;
    int operator != (const EmergencyAreaID_Cancelled_Item &) const;

    emergencyAreaID & get_emergencyAreaID();
    const emergencyAreaID & get_emergencyAreaID() const;
    void set_emergencyAreaID(const emergencyAreaID &);

    cancelledCellinEAI & get_cancelledCellinEAI();
    const cancelledCellinEAI & get_cancelledCellinEAI() const;
    void set_cancelledCellinEAI(const cancelledCellinEAI &);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    emergencyAreaID emergencyAreaID_field;
    cancelledCellinEAI cancelledCellinEAI_field;
    iE_Extensions iE_Extensions_field;
};

typedef __shared44 CompletedCellinEAI_Item;

typedef __shared5 ECGI_List;

typedef OssBitString EncryptionAlgorithms;

class OSS_PUBLIC E_RABInformationListItem   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_INT32 e_RAB_ID;
    typedef enum DL_Forwarding dL_Forwarding;
    typedef __shared2 iE_Extensions;

    E_RABInformationListItem();
    E_RABInformationListItem(const E_RABInformationListItem &);
    E_RABInformationListItem(e_RAB_ID, dL_Forwarding, const iE_Extensions &);
    E_RABInformationListItem(e_RAB_ID);

    E_RABInformationListItem & operator = (const E_RABInformationListItem &);
    int operator == (const E_RABInformationListItem &) const;
    int operator != (const E_RABInformationListItem &) const;

    e_RAB_ID & get_e_RAB_ID();
    e_RAB_ID get_e_RAB_ID() const;
    void set_e_RAB_ID(e_RAB_ID);

    dL_Forwarding *get_dL_Forwarding();
    const dL_Forwarding *get_dL_Forwarding() const;
    void set_dL_Forwarding(dL_Forwarding);
    int dL_Forwarding_is_present() const;
    void omit_dL_Forwarding();

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    e_RAB_ID e_RAB_ID_field;
    dL_Forwarding dL_Forwarding_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC E_RABInformationListIEs_Value : public OssConstrainedOpenType
{
public:
    E_RABInformationListIEs_Value();
    E_RABInformationListIEs_Value(const E_RABInformationListIEs_Value &);
    ~E_RABInformationListIEs_Value();
    E_RABInformationListIEs_Value & operator = (const E_RABInformationListIEs_Value &);
    int operator == (const E_RABInformationListIEs_Value &) const;
    int operator != (const E_RABInformationListIEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    E_RABInformationListItem *get_E_RABInformationListItem();
    const E_RABInformationListItem *get_E_RABInformationListItem() const;
    void set_E_RABInformationListItem(const E_RABInformationListItem &);
    E_RABInformationListItem *release_E_RABInformationListItem();
    void set_E_RABInformationListItem(E_RABInformationListItem *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq164;

class OSS_PUBLIC E_RABInformationList : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq164 component;

    E_RABInformationList();
    E_RABInformationList(const E_RABInformationList &);
    ~E_RABInformationList();

    E_RABInformationList & operator = (const E_RABInformationList &);
    int operator == (const E_RABInformationList &) const;
    int operator != (const E_RABInformationList &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(E_RABInformationList *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, E_RABInformationList *);

    int remove_front();
    int remove_after(OssIndex);

    E_RABInformationList *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC __seq164   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef E_RABInformationListIEs_Value value;

    __seq164();
    __seq164(const __seq164 &);
    __seq164(id, criticality, const value &);

    __seq164 & operator = (const __seq164 &);
    int operator == (const __seq164 &) const;
    int operator != (const __seq164 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC E_RABItemIEs_Value : public OssConstrainedOpenType
{
public:
    E_RABItemIEs_Value();
    E_RABItemIEs_Value(const E_RABItemIEs_Value &);
    ~E_RABItemIEs_Value();
    E_RABItemIEs_Value & operator = (const E_RABItemIEs_Value &);
    int operator == (const E_RABItemIEs_Value &) const;
    int operator != (const E_RABItemIEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    __shared11 *get_E_RABItem();
    const __shared11 *get_E_RABItem() const;
    void set_E_RABItem(const __shared11 &);
    __shared11 *release_E_RABItem();
    void set_E_RABItem(__shared11 *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq166   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef E_RABItemIEs_Value value;

    __seq166();
    __seq166(const __seq166 &);
    __seq166(id, criticality, const value &);

    __seq166 & operator = (const __seq166 &);
    int operator == (const __seq166 &) const;
    int operator != (const __seq166 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

typedef OSS_INT32 ExpectedActivityPeriod;

typedef OSS_INT32 ExpectedIdlePeriod;

typedef OSS_UINT32 ExtendedRNC_ID;

typedef __shared4 ForbiddenTACs;

class OSS_PUBLIC ForbiddenTAs_Item   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OssString pLMN_Identity;
    typedef __shared4 forbiddenTACs;
    typedef __shared2 iE_Extensions;

    ForbiddenTAs_Item();
    ForbiddenTAs_Item(const ForbiddenTAs_Item &);
    ForbiddenTAs_Item(const pLMN_Identity &, const forbiddenTACs &, const iE_Extensions &);
    ForbiddenTAs_Item(const pLMN_Identity &, const forbiddenTACs &);

    ForbiddenTAs_Item & operator = (const ForbiddenTAs_Item &);
    int operator == (const ForbiddenTAs_Item &) const;
    int operator != (const ForbiddenTAs_Item &) const;

    pLMN_Identity & get_pLMN_Identity();
    const pLMN_Identity & get_pLMN_Identity() const;
    void set_pLMN_Identity(const pLMN_Identity &);

    forbiddenTACs & get_forbiddenTACs();
    const forbiddenTACs & get_forbiddenTACs() const;
    void set_forbiddenTACs(const forbiddenTACs &);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    pLMN_Identity pLMN_Identity_field;
    forbiddenTACs forbiddenTACs_field;
    iE_Extensions iE_Extensions_field;
};

typedef __shared4 ForbiddenLACs;

class OSS_PUBLIC ForbiddenLAs_Item   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OssString pLMN_Identity;
    typedef __shared4 forbiddenLACs;
    typedef __shared2 iE_Extensions;

    ForbiddenLAs_Item();
    ForbiddenLAs_Item(const ForbiddenLAs_Item &);
    ForbiddenLAs_Item(const pLMN_Identity &, const forbiddenLACs &, const iE_Extensions &);
    ForbiddenLAs_Item(const pLMN_Identity &, const forbiddenLACs &);

    ForbiddenLAs_Item & operator = (const ForbiddenLAs_Item &);
    int operator == (const ForbiddenLAs_Item &) const;
    int operator != (const ForbiddenLAs_Item &) const;

    pLMN_Identity & get_pLMN_Identity();
    const pLMN_Identity & get_pLMN_Identity() const;
    void set_pLMN_Identity(const pLMN_Identity &);

    forbiddenLACs & get_forbiddenLACs();
    const forbiddenLACs & get_forbiddenLACs() const;
    void set_forbiddenLACs(const forbiddenLACs &);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    pLMN_Identity pLMN_Identity_field;
    forbiddenLACs forbiddenLACs_field;
    iE_Extensions iE_Extensions_field;
};

typedef OssBitString MeasurementsToActivate;

typedef OSS_UINT32 Threshold_RSRP;

typedef OSS_UINT32 Threshold_RSRQ;

class OSS_PUBLIC MeasurementThresholdA2  : public OssChoice   /* CHOICE */
{
public:
    enum Id {
	unselected,
	threshold_RSRP_chosen = 1,
	threshold_RSRQ_chosen = 2
    };
    typedef OSS_UINT32 threshold_RSRP;
    typedef OSS_UINT32 threshold_RSRQ;

    MeasurementThresholdA2();
    MeasurementThresholdA2(const MeasurementThresholdA2 &);

    MeasurementThresholdA2 & operator = (const MeasurementThresholdA2 &);
    int operator == (const MeasurementThresholdA2 &) const;
    int operator != (const MeasurementThresholdA2 &) const;

    threshold_RSRP *get_threshold_RSRP();
    const threshold_RSRP *get_threshold_RSRP() const;
    void set_threshold_RSRP(threshold_RSRP);

    threshold_RSRQ *get_threshold_RSRQ();
    const threshold_RSRQ *get_threshold_RSRQ() const;
    void set_threshold_RSRQ(threshold_RSRQ);
private:
    union {
	threshold_RSRP threshold_RSRP_field;
	threshold_RSRQ threshold_RSRQ_field;
    };
};

class OSS_PUBLIC M1ThresholdEventA2   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef MeasurementThresholdA2 measurementThreshold;
    typedef __shared2 iE_Extensions;

    M1ThresholdEventA2();
    M1ThresholdEventA2(const M1ThresholdEventA2 &);
    M1ThresholdEventA2(const measurementThreshold &, const iE_Extensions &);
    M1ThresholdEventA2(const measurementThreshold &);

    M1ThresholdEventA2 & operator = (const M1ThresholdEventA2 &);
    int operator == (const M1ThresholdEventA2 &) const;
    int operator != (const M1ThresholdEventA2 &) const;

    measurementThreshold & get_measurementThreshold();
    const measurementThreshold & get_measurementThreshold() const;
    void set_measurementThreshold(const measurementThreshold &);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    measurementThreshold measurementThreshold_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC M1PeriodicReporting   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef enum ReportIntervalMDT reportInterval;
    typedef enum ReportAmountMDT reportAmount;
    typedef __shared2 iE_Extensions;

    M1PeriodicReporting();
    M1PeriodicReporting(const M1PeriodicReporting &);
    M1PeriodicReporting(reportInterval, reportAmount, const iE_Extensions &);
    M1PeriodicReporting(reportInterval, reportAmount);

    M1PeriodicReporting & operator = (const M1PeriodicReporting &);
    int operator == (const M1PeriodicReporting &) const;
    int operator != (const M1PeriodicReporting &) const;

    reportInterval & get_reportInterval();
    reportInterval get_reportInterval() const;
    void set_reportInterval(reportInterval);

    reportAmount & get_reportAmount();
    reportAmount get_reportAmount() const;
    void set_reportAmount(reportAmount);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    reportInterval reportInterval_field;
    reportAmount reportAmount_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC M3Configuration   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef enum M3period m3period;
    typedef __shared2 iE_Extensions;

    M3Configuration();
    M3Configuration(const M3Configuration &);
    M3Configuration(m3period, const iE_Extensions &);
    M3Configuration(m3period);

    M3Configuration & operator = (const M3Configuration &);
    int operator == (const M3Configuration &) const;
    int operator != (const M3Configuration &) const;

    m3period & get_m3period();
    m3period get_m3period() const;
    void set_m3period(m3period);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    m3period m3period_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC M4Configuration   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef enum M4period m4period;
    typedef enum Links_to_log m4_links_to_log;
    typedef __shared2 iE_Extensions;

    M4Configuration();
    M4Configuration(const M4Configuration &);
    M4Configuration(m4period, m4_links_to_log, const iE_Extensions &);
    M4Configuration(m4period, m4_links_to_log);

    M4Configuration & operator = (const M4Configuration &);
    int operator == (const M4Configuration &) const;
    int operator != (const M4Configuration &) const;

    m4period & get_m4period();
    m4period get_m4period() const;
    void set_m4period(m4period);

    m4_links_to_log & get_m4_links_to_log();
    m4_links_to_log get_m4_links_to_log() const;
    void set_m4_links_to_log(m4_links_to_log);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    m4period m4period_field;
    m4_links_to_log m4_links_to_log_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC M5Configuration   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef enum M5period m5period;
    typedef enum Links_to_log m5_links_to_log;
    typedef __shared2 iE_Extensions;

    M5Configuration();
    M5Configuration(const M5Configuration &);
    M5Configuration(m5period, m5_links_to_log, const iE_Extensions &);
    M5Configuration(m5period, m5_links_to_log);

    M5Configuration & operator = (const M5Configuration &);
    int operator == (const M5Configuration &) const;
    int operator != (const M5Configuration &) const;

    m5period & get_m5period();
    m5period get_m5period() const;
    void set_m5period(m5period);

    m5_links_to_log & get_m5_links_to_log();
    m5_links_to_log get_m5_links_to_log() const;
    void set_m5_links_to_log(m5_links_to_log);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    m5period m5period_field;
    m5_links_to_log m5_links_to_log_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC M6Configuration   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef enum M6report_Interval m6report_Interval;
    typedef enum M6delay_threshold m6delay_threshold;
    typedef enum Links_to_log m6_links_to_log;
    typedef __shared2 iE_Extensions;

    M6Configuration();
    M6Configuration(const M6Configuration &);
    M6Configuration(m6report_Interval, m6delay_threshold, m6_links_to_log, const iE_Extensions &);
    M6Configuration(m6report_Interval, m6_links_to_log);

    M6Configuration & operator = (const M6Configuration &);
    int operator == (const M6Configuration &) const;
    int operator != (const M6Configuration &) const;

    m6report_Interval & get_m6report_Interval();
    m6report_Interval get_m6report_Interval() const;
    void set_m6report_Interval(m6report_Interval);

    m6delay_threshold *get_m6delay_threshold();
    const m6delay_threshold *get_m6delay_threshold() const;
    void set_m6delay_threshold(m6delay_threshold);
    int m6delay_threshold_is_present() const;
    void omit_m6delay_threshold();

    m6_links_to_log & get_m6_links_to_log();
    m6_links_to_log get_m6_links_to_log() const;
    void set_m6_links_to_log(m6_links_to_log);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    m6report_Interval m6report_Interval_field;
    m6delay_threshold m6delay_threshold_field;
    m6_links_to_log m6_links_to_log_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC M7Configuration   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_INT32 m7period;
    typedef enum Links_to_log m7_links_to_log;
    typedef __shared2 iE_Extensions;

    M7Configuration();
    M7Configuration(const M7Configuration &);
    M7Configuration(m7period, m7_links_to_log, const iE_Extensions &);
    M7Configuration(m7period, m7_links_to_log);

    M7Configuration & operator = (const M7Configuration &);
    int operator == (const M7Configuration &) const;
    int operator != (const M7Configuration &) const;

    m7period & get_m7period();
    m7period get_m7period() const;
    void set_m7period(m7period);

    m7_links_to_log & get_m7_links_to_log();
    m7_links_to_log get_m7_links_to_log() const;
    void set_m7_links_to_log(m7_links_to_log);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    m7period m7period_field;
    m7_links_to_log m7_links_to_log_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC ImmediateMDT_ExtIEs_Extension : public OssConstrainedOpenType
{
public:
    ImmediateMDT_ExtIEs_Extension();
    ImmediateMDT_ExtIEs_Extension(const ImmediateMDT_ExtIEs_Extension &);
    ~ImmediateMDT_ExtIEs_Extension();
    ImmediateMDT_ExtIEs_Extension & operator = (const ImmediateMDT_ExtIEs_Extension &);
    int operator == (const ImmediateMDT_ExtIEs_Extension &) const;
    int operator != (const ImmediateMDT_ExtIEs_Extension &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    M3Configuration *get_M3Configuration();
    const M3Configuration *get_M3Configuration() const;
    void set_M3Configuration(const M3Configuration &);
    M3Configuration *release_M3Configuration();
    void set_M3Configuration(M3Configuration *);

    M4Configuration *get_M4Configuration();
    const M4Configuration *get_M4Configuration() const;
    void set_M4Configuration(const M4Configuration &);
    M4Configuration *release_M4Configuration();
    void set_M4Configuration(M4Configuration *);

    M5Configuration *get_M5Configuration();
    const M5Configuration *get_M5Configuration() const;
    void set_M5Configuration(const M5Configuration &);
    M5Configuration *release_M5Configuration();
    void set_M5Configuration(M5Configuration *);

    MDT_Location_Info *get_MDT_Location_Info();
    const MDT_Location_Info *get_MDT_Location_Info() const;
    void set_MDT_Location_Info(const MDT_Location_Info &);
    MDT_Location_Info *release_MDT_Location_Info();
    void set_MDT_Location_Info(MDT_Location_Info *);

    M6Configuration *get_M6Configuration();
    const M6Configuration *get_M6Configuration() const;
    void set_M6Configuration(const M6Configuration &);
    M6Configuration *release_M6Configuration();
    void set_M6Configuration(M6Configuration *);

    M7Configuration *get_M7Configuration();
    const M7Configuration *get_M7Configuration() const;
    void set_M7Configuration(const M7Configuration &);
    M7Configuration *release_M7Configuration();
    void set_M7Configuration(M7Configuration *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq175;

class OSS_PUBLIC __seqof152 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq175 component;

    __seqof152();
    __seqof152(const __seqof152 &);
    ~__seqof152();

    __seqof152 & operator = (const __seqof152 &);
    int operator == (const __seqof152 &) const;
    int operator != (const __seqof152 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof152 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof152 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof152 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC ImmediateMDT   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OssBitString measurementsToActivate;
    typedef enum M1ReportingTrigger m1reportingTrigger;
    typedef M1ThresholdEventA2 m1thresholdeventA2;
    typedef M1PeriodicReporting m1periodicReporting;
    typedef __seqof152 iE_Extensions;

    ImmediateMDT();
    ImmediateMDT(const ImmediateMDT &);
    ImmediateMDT(const measurementsToActivate &, m1reportingTrigger, const m1thresholdeventA2 &, 
	const m1periodicReporting &, const iE_Extensions &);
    ImmediateMDT(const measurementsToActivate &, m1reportingTrigger);

    ImmediateMDT & operator = (const ImmediateMDT &);
    int operator == (const ImmediateMDT &) const;
    int operator != (const ImmediateMDT &) const;

    measurementsToActivate & get_measurementsToActivate();
    const measurementsToActivate & get_measurementsToActivate() const;
    void set_measurementsToActivate(const measurementsToActivate &);

    m1reportingTrigger & get_m1reportingTrigger();
    m1reportingTrigger get_m1reportingTrigger() const;
    void set_m1reportingTrigger(m1reportingTrigger);

    m1thresholdeventA2 *get_m1thresholdeventA2();
    const m1thresholdeventA2 *get_m1thresholdeventA2() const;
    void set_m1thresholdeventA2(const m1thresholdeventA2 &);
    int m1thresholdeventA2_is_present() const;
    void omit_m1thresholdeventA2();

    m1periodicReporting *get_m1periodicReporting();
    const m1periodicReporting *get_m1periodicReporting() const;
    void set_m1periodicReporting(const m1periodicReporting &);
    int m1periodicReporting_is_present() const;
    void omit_m1periodicReporting();

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    measurementsToActivate measurementsToActivate_field;
    m1reportingTrigger m1reportingTrigger_field;
    m1thresholdeventA2 m1thresholdeventA2_field;
    m1periodicReporting m1periodicReporting_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC __seq175   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef ImmediateMDT_ExtIEs_Extension extensionValue;

    __seq175();
    __seq175(const __seq175 &);
    __seq175(id, criticality, const extensionValue &);

    __seq175 & operator = (const __seq175 &);
    int operator == (const __seq175 &) const;
    int operator != (const __seq175 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    extensionValue & get_extensionValue();
    const extensionValue & get_extensionValue() const;
    void set_extensionValue(const extensionValue &);
private:
    id id_field;
    criticality criticality_field;
    extensionValue extensionValue_field;
};

typedef OssString IMSI;

typedef OssBitString IntegrityProtectionAlgorithms;

typedef OssBitString InterfacesToTrace;

typedef OssString LastVisitedUTRANCellInformation;

class OSS_PUBLIC __seq178;

class OSS_PUBLIC __seqof155 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq178 component;

    __seqof155();
    __seqof155(const __seqof155 &);
    ~__seqof155();

    __seqof155 & operator = (const __seqof155 &);
    int operator == (const __seqof155 &) const;
    int operator != (const __seqof155 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof155 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof155 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof155 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC LastVisitedEUTRANCellInformation   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef EUTRAN_CGI global_Cell_ID;
    typedef CellType cellType;
    typedef OSS_UINT32 time_UE_StayedInCell;
    typedef __seqof155 iE_Extensions;

    LastVisitedEUTRANCellInformation();
    LastVisitedEUTRANCellInformation(const LastVisitedEUTRANCellInformation &);
    LastVisitedEUTRANCellInformation(const global_Cell_ID &, const cellType &, time_UE_StayedInCell, 
	const iE_Extensions &);
    LastVisitedEUTRANCellInformation(const global_Cell_ID &, const cellType &, time_UE_StayedInCell);

    LastVisitedEUTRANCellInformation & operator = (const LastVisitedEUTRANCellInformation &);
    int operator == (const LastVisitedEUTRANCellInformation &) const;
    int operator != (const LastVisitedEUTRANCellInformation &) const;

    global_Cell_ID & get_global_Cell_ID();
    const global_Cell_ID & get_global_Cell_ID() const;
    void set_global_Cell_ID(const global_Cell_ID &);

    cellType & get_cellType();
    const cellType & get_cellType() const;
    void set_cellType(const cellType &);

    time_UE_StayedInCell & get_time_UE_StayedInCell();
    time_UE_StayedInCell get_time_UE_StayedInCell() const;
    void set_time_UE_StayedInCell(time_UE_StayedInCell);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    global_Cell_ID global_Cell_ID_field;
    cellType cellType_field;
    time_UE_StayedInCell time_UE_StayedInCell_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC LastVisitedGERANCellInformation  : public OssChoice   /* CHOICE */
{
public:
    enum Id {
	unselected,
	undefined_chosen = 1
    };
    typedef Nulltype undefined;

    LastVisitedGERANCellInformation();
    LastVisitedGERANCellInformation(const LastVisitedGERANCellInformation &);

    LastVisitedGERANCellInformation & operator = (const LastVisitedGERANCellInformation &);
    int operator == (const LastVisitedGERANCellInformation &) const;
    int operator != (const LastVisitedGERANCellInformation &) const;

    undefined *get_undefined();
    const undefined *get_undefined() const;
    void set_undefined(undefined);
private:
    union {
	undefined undefined_field;
    };
};

class OSS_PUBLIC LastVisitedCell_Item  : public OssChoice   /* CHOICE */
{
public:
    enum Id {
	unselected,
	e_UTRAN_Cell_chosen = 1,
	uTRAN_Cell_chosen = 2,
	gERAN_Cell_chosen = 3
    };
    typedef LastVisitedEUTRANCellInformation e_UTRAN_Cell;
    typedef OssString uTRAN_Cell;
    typedef LastVisitedGERANCellInformation gERAN_Cell;

    LastVisitedCell_Item();
    LastVisitedCell_Item(const LastVisitedCell_Item &);
    ~LastVisitedCell_Item();

    LastVisitedCell_Item & operator = (const LastVisitedCell_Item &);
    int operator == (const LastVisitedCell_Item &) const;
    int operator != (const LastVisitedCell_Item &) const;

    e_UTRAN_Cell *get_e_UTRAN_Cell();
    const e_UTRAN_Cell *get_e_UTRAN_Cell() const;
    void set_e_UTRAN_Cell(const e_UTRAN_Cell &);

    uTRAN_Cell *get_uTRAN_Cell();
    const uTRAN_Cell *get_uTRAN_Cell() const;
    void set_uTRAN_Cell(const uTRAN_Cell &);

    gERAN_Cell *get_gERAN_Cell();
    const gERAN_Cell *get_gERAN_Cell() const;
    void set_gERAN_Cell(const gERAN_Cell &);
private:
    union {
	e_UTRAN_Cell *e_UTRAN_Cell_field;
	OSSC::COssString uTRAN_Cell_field;
	gERAN_Cell *gERAN_Cell_field;
    };
    void cleanup();
};

typedef OSS_UINT32 Time_UE_StayedInCell;

class OSS_PUBLIC LastVisitedEUTRANCellInformation_ExtIEs_Extension : public OssConstrainedOpenType
{
public:
    LastVisitedEUTRANCellInformation_ExtIEs_Extension();
    LastVisitedEUTRANCellInformation_ExtIEs_Extension(const LastVisitedEUTRANCellInformation_ExtIEs_Extension &);
    ~LastVisitedEUTRANCellInformation_ExtIEs_Extension();
    LastVisitedEUTRANCellInformation_ExtIEs_Extension & operator = (const LastVisitedEUTRANCellInformation_ExtIEs_Extension &);
    int operator == (const LastVisitedEUTRANCellInformation_ExtIEs_Extension &) const;
    int operator != (const LastVisitedEUTRANCellInformation_ExtIEs_Extension &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    Time_UE_StayedInCell_EnhancedGranularity *get_Time_UE_StayedInCell_EnhancedGranularity();
    const Time_UE_StayedInCell_EnhancedGranularity *get_Time_UE_StayedInCell_EnhancedGranularity() const;
    void set_Time_UE_StayedInCell_EnhancedGranularity(const Time_UE_StayedInCell_EnhancedGranularity &);
    Time_UE_StayedInCell_EnhancedGranularity *release_Time_UE_StayedInCell_EnhancedGranularity();
    void set_Time_UE_StayedInCell_EnhancedGranularity(Time_UE_StayedInCell_EnhancedGranularity *);

    Cause *get_Cause();
    const Cause *get_Cause() const;
    void set_Cause(const Cause &);
    Cause *release_Cause();
    void set_Cause(Cause *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq178   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef LastVisitedEUTRANCellInformation_ExtIEs_Extension extensionValue;

    __seq178();
    __seq178(const __seq178 &);
    __seq178(id, criticality, const extensionValue &);

    __seq178 & operator = (const __seq178 &);
    int operator == (const __seq178 &) const;
    int operator != (const __seq178 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    extensionValue & get_extensionValue();
    const extensionValue & get_extensionValue() const;
    void set_extensionValue(const extensionValue &);
private:
    id id_field;
    criticality criticality_field;
    extensionValue extensionValue_field;
};

class OSS_PUBLIC ListeningSubframePattern   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef enum _enum1 pattern_period;
    typedef OSS_INT32 pattern_offset;
    typedef __shared2 iE_Extensions;

    ListeningSubframePattern();
    ListeningSubframePattern(const ListeningSubframePattern &);
    ListeningSubframePattern(pattern_period, pattern_offset, const iE_Extensions &);
    ListeningSubframePattern(pattern_period, pattern_offset);

    ListeningSubframePattern & operator = (const ListeningSubframePattern &);
    int operator == (const ListeningSubframePattern &) const;
    int operator != (const ListeningSubframePattern &) const;

    pattern_period & get_pattern_period();
    pattern_period get_pattern_period() const;
    void set_pattern_period(pattern_period);

    pattern_offset & get_pattern_offset();
    pattern_offset get_pattern_offset() const;
    void set_pattern_offset(pattern_offset);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    pattern_period pattern_period_field;
    pattern_offset pattern_offset_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC LoggedMDT   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef enum LoggingInterval loggingInterval;
    typedef enum LoggingDuration loggingDuration;
    typedef __shared2 iE_Extensions;

    LoggedMDT();
    LoggedMDT(const LoggedMDT &);
    LoggedMDT(loggingInterval, loggingDuration, const iE_Extensions &);
    LoggedMDT(loggingInterval, loggingDuration);

    LoggedMDT & operator = (const LoggedMDT &);
    int operator == (const LoggedMDT &) const;
    int operator != (const LoggedMDT &) const;

    loggingInterval & get_loggingInterval();
    loggingInterval get_loggingInterval() const;
    void set_loggingInterval(loggingInterval);

    loggingDuration & get_loggingDuration();
    loggingDuration get_loggingDuration() const;
    void set_loggingDuration(loggingDuration);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    loggingInterval loggingInterval_field;
    loggingDuration loggingDuration_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC MBSFN_ResultToLogInfo;

class OSS_PUBLIC __shared7 : public OssList  /* SEQUENCE OF */
{
public:
    typedef MBSFN_ResultToLogInfo component;

    __shared7();
    __shared7(const __shared7 &);
    ~__shared7();

    __shared7 & operator = (const __shared7 &);
    int operator == (const __shared7 &) const;
    int operator != (const __shared7 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__shared7 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __shared7 *);

    int remove_front();
    int remove_after(OssIndex);

    __shared7 *extract_after(OssIndex, OssIndex);
};

typedef __shared7 MBSFN_ResultToLog;

class OSS_PUBLIC LoggedMBSFNMDT   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef enum LoggingInterval loggingInterval;
    typedef enum LoggingDuration loggingDuration;
    typedef __shared7 mBSFN_ResultToLog;
    typedef __shared2 iE_Extensions;

    LoggedMBSFNMDT();
    LoggedMBSFNMDT(const LoggedMBSFNMDT &);
    LoggedMBSFNMDT(loggingInterval, loggingDuration, const mBSFN_ResultToLog &, const iE_Extensions &);
    LoggedMBSFNMDT(loggingInterval, loggingDuration);

    LoggedMBSFNMDT & operator = (const LoggedMBSFNMDT &);
    int operator == (const LoggedMBSFNMDT &) const;
    int operator != (const LoggedMBSFNMDT &) const;

    loggingInterval & get_loggingInterval();
    loggingInterval get_loggingInterval() const;
    void set_loggingInterval(loggingInterval);

    loggingDuration & get_loggingDuration();
    loggingDuration get_loggingDuration() const;
    void set_loggingDuration(loggingDuration);

    mBSFN_ResultToLog *get_mBSFN_ResultToLog();
    const mBSFN_ResultToLog *get_mBSFN_ResultToLog() const;
    void set_mBSFN_ResultToLog(const mBSFN_ResultToLog &);
    int mBSFN_ResultToLog_is_present() const;
    void omit_mBSFN_ResultToLog();

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    loggingInterval loggingInterval_field;
    loggingDuration loggingDuration_field;
    mBSFN_ResultToLog mBSFN_ResultToLog_field;
    iE_Extensions iE_Extensions_field;
};

typedef OSS_INT32 M7period;

class OSS_PUBLIC MDTMode_ExtensionIE_Value : public OssConstrainedOpenType
{
public:
    MDTMode_ExtensionIE_Value();
    MDTMode_ExtensionIE_Value(const MDTMode_ExtensionIE_Value &);
    ~MDTMode_ExtensionIE_Value();
    MDTMode_ExtensionIE_Value & operator = (const MDTMode_ExtensionIE_Value &);
    int operator == (const MDTMode_ExtensionIE_Value &) const;
    int operator != (const MDTMode_ExtensionIE_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    LoggedMBSFNMDT *get_LoggedMBSFNMDT();
    const LoggedMBSFNMDT *get_LoggedMBSFNMDT() const;
    void set_LoggedMBSFNMDT(const LoggedMBSFNMDT &);
    LoggedMBSFNMDT *release_LoggedMBSFNMDT();
    void set_LoggedMBSFNMDT(LoggedMBSFNMDT *);
private:
    void cleanup_decoded();
    int check_type(OssTypeIndex);
};

class OSS_PUBLIC MDTMode_Extension   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef MDTMode_ExtensionIE_Value value;

    MDTMode_Extension();
    MDTMode_Extension(const MDTMode_Extension &);
    MDTMode_Extension(id, criticality, const value &);

    MDTMode_Extension & operator = (const MDTMode_Extension &);
    int operator == (const MDTMode_Extension &) const;
    int operator != (const MDTMode_Extension &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC MDTMode  : public OssChoice   /* CHOICE */
{
public:
    enum Id {
	unselected,
	immediateMDT_chosen = 1,
	loggedMDT_chosen = 2,
	mDTMode_Extension_chosen = 3
    };
    typedef ImmediateMDT immediateMDT;
    typedef LoggedMDT loggedMDT;
    typedef MDTMode_Extension mDTMode_Extension;

    MDTMode();
    MDTMode(const MDTMode &);
    ~MDTMode();

    MDTMode & operator = (const MDTMode &);
    int operator == (const MDTMode &) const;
    int operator != (const MDTMode &) const;

    immediateMDT *get_immediateMDT();
    const immediateMDT *get_immediateMDT() const;
    void set_immediateMDT(const immediateMDT &);

    loggedMDT *get_loggedMDT();
    const loggedMDT *get_loggedMDT() const;
    void set_loggedMDT(const loggedMDT &);

    mDTMode_Extension *get_mDTMode_Extension();
    const mDTMode_Extension *get_mDTMode_Extension() const;
    void set_mDTMode_Extension(const mDTMode_Extension &);
private:
    union {
	immediateMDT *immediateMDT_field;
	loggedMDT *loggedMDT_field;
	mDTMode_Extension *mDTMode_Extension_field;
    };
    void cleanup();
};

class OSS_PUBLIC MDT_Configuration_ExtIEs_Extension : public OssConstrainedOpenType
{
public:
    MDT_Configuration_ExtIEs_Extension();
    MDT_Configuration_ExtIEs_Extension(const MDT_Configuration_ExtIEs_Extension &);
    ~MDT_Configuration_ExtIEs_Extension();
    MDT_Configuration_ExtIEs_Extension & operator = (const MDT_Configuration_ExtIEs_Extension &);
    int operator == (const MDT_Configuration_ExtIEs_Extension &) const;
    int operator != (const MDT_Configuration_ExtIEs_Extension &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    __shared4 *get_MDTPLMNList();
    const __shared4 *get_MDTPLMNList() const;
    void set_MDTPLMNList(const __shared4 &);
    __shared4 *release_MDTPLMNList();
    void set_MDTPLMNList(__shared4 *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq187;

class OSS_PUBLIC __seqof164 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq187 component;

    __seqof164();
    __seqof164(const __seqof164 &);
    ~__seqof164();

    __seqof164 & operator = (const __seqof164 &);
    int operator == (const __seqof164 &) const;
    int operator != (const __seqof164 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof164 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof164 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof164 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC MDT_Configuration   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef enum MDT_Activation mdt_Activation;
    typedef AreaScopeOfMDT areaScopeOfMDT;
    typedef MDTMode mDTMode;
    typedef __seqof164 iE_Extensions;

    MDT_Configuration();
    MDT_Configuration(const MDT_Configuration &);
    MDT_Configuration(mdt_Activation, const areaScopeOfMDT &, const mDTMode &, const iE_Extensions &);
    MDT_Configuration(mdt_Activation, const areaScopeOfMDT &, const mDTMode &);

    MDT_Configuration & operator = (const MDT_Configuration &);
    int operator == (const MDT_Configuration &) const;
    int operator != (const MDT_Configuration &) const;

    mdt_Activation & get_mdt_Activation();
    mdt_Activation get_mdt_Activation() const;
    void set_mdt_Activation(mdt_Activation);

    areaScopeOfMDT & get_areaScopeOfMDT();
    const areaScopeOfMDT & get_areaScopeOfMDT() const;
    void set_areaScopeOfMDT(const areaScopeOfMDT &);

    mDTMode & get_mDTMode();
    const mDTMode & get_mDTMode() const;
    void set_mDTMode(const mDTMode &);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    mdt_Activation mdt_Activation_field;
    areaScopeOfMDT areaScopeOfMDT_field;
    mDTMode mDTMode_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC __seq187   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef MDT_Configuration_ExtIEs_Extension extensionValue;

    __seq187();
    __seq187(const __seq187 &);
    __seq187(id, criticality, const extensionValue &);

    __seq187 & operator = (const __seq187 &);
    int operator == (const __seq187 &) const;
    int operator != (const __seq187 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    extensionValue & get_extensionValue();
    const extensionValue & get_extensionValue() const;
    void set_extensionValue(const extensionValue &);
private:
    id id_field;
    criticality criticality_field;
    extensionValue extensionValue_field;
};

class OSS_PUBLIC MBSFN_ResultToLogInfo   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 mBSFN_AreaId;
    typedef OSS_INT32 carrierFreq;
    typedef __shared2 iE_Extensions;

    MBSFN_ResultToLogInfo();
    MBSFN_ResultToLogInfo(const MBSFN_ResultToLogInfo &);
    MBSFN_ResultToLogInfo(mBSFN_AreaId, carrierFreq, const iE_Extensions &);
    MBSFN_ResultToLogInfo(carrierFreq);

    MBSFN_ResultToLogInfo & operator = (const MBSFN_ResultToLogInfo &);
    int operator == (const MBSFN_ResultToLogInfo &) const;
    int operator != (const MBSFN_ResultToLogInfo &) const;

    mBSFN_AreaId *get_mBSFN_AreaId();
    const mBSFN_AreaId *get_mBSFN_AreaId() const;
    void set_mBSFN_AreaId(mBSFN_AreaId);
    int mBSFN_AreaId_is_present() const;
    void omit_mBSFN_AreaId();

    carrierFreq & get_carrierFreq();
    carrierFreq get_carrierFreq() const;
    void set_carrierFreq(carrierFreq);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    mBSFN_AreaId mBSFN_AreaId_field;
    carrierFreq carrierFreq_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC MMEPagingTarget  : public OssChoice   /* CHOICE */
{
public:
    enum Id {
	unselected,
	global_ENB_ID_chosen = 1,
	tAI_chosen = 2
    };
    typedef Global_ENB_ID global_ENB_ID;
    typedef TAI tAI;

    MMEPagingTarget();
    MMEPagingTarget(const MMEPagingTarget &);
    ~MMEPagingTarget();

    MMEPagingTarget & operator = (const MMEPagingTarget &);
    int operator == (const MMEPagingTarget &) const;
    int operator != (const MMEPagingTarget &) const;

    global_ENB_ID *get_global_ENB_ID();
    const global_ENB_ID *get_global_ENB_ID() const;
    void set_global_ENB_ID(const global_ENB_ID &);

    tAI *get_tAI();
    const tAI *get_tAI() const;
    void set_tAI(const tAI &);
private:
    union {
	global_ENB_ID *global_ENB_ID_field;
	tAI *tAI_field;
    };
    void cleanup();
};

class OSS_PUBLIC MutingPatternInformation   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef enum _enum2 muting_pattern_period;
    typedef OSS_INT32 muting_pattern_offset;
    typedef __shared2 iE_Extensions;

    MutingPatternInformation();
    MutingPatternInformation(const MutingPatternInformation &);
    MutingPatternInformation(muting_pattern_period, muting_pattern_offset, const iE_Extensions &);
    MutingPatternInformation(muting_pattern_period);

    MutingPatternInformation & operator = (const MutingPatternInformation &);
    int operator == (const MutingPatternInformation &) const;
    int operator != (const MutingPatternInformation &) const;

    muting_pattern_period & get_muting_pattern_period();
    muting_pattern_period get_muting_pattern_period() const;
    void set_muting_pattern_period(muting_pattern_period);

    muting_pattern_offset *get_muting_pattern_offset();
    const muting_pattern_offset *get_muting_pattern_offset() const;
    void set_muting_pattern_offset(muting_pattern_offset);
    int muting_pattern_offset_is_present() const;
    void omit_muting_pattern_offset();

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    muting_pattern_period muting_pattern_period_field;
    muting_pattern_offset muting_pattern_offset_field;
    iE_Extensions iE_Extensions_field;
};

typedef OssString Port_Number;

class OSS_PUBLIC ProSeAuthorized_ExtIEs_Extension : public OssConstrainedOpenType
{
public:
    ProSeAuthorized_ExtIEs_Extension();
    ProSeAuthorized_ExtIEs_Extension(const ProSeAuthorized_ExtIEs_Extension &);
    ~ProSeAuthorized_ExtIEs_Extension();
    ProSeAuthorized_ExtIEs_Extension & operator = (const ProSeAuthorized_ExtIEs_Extension &);
    int operator == (const ProSeAuthorized_ExtIEs_Extension &) const;
    int operator != (const ProSeAuthorized_ExtIEs_Extension &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    ProSeUEtoNetworkRelaying *get_ProSeUEtoNetworkRelaying();
    const ProSeUEtoNetworkRelaying *get_ProSeUEtoNetworkRelaying() const;
    void set_ProSeUEtoNetworkRelaying(const ProSeUEtoNetworkRelaying &);
    ProSeUEtoNetworkRelaying *release_ProSeUEtoNetworkRelaying();
    void set_ProSeUEtoNetworkRelaying(ProSeUEtoNetworkRelaying *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq192   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef ProSeAuthorized_ExtIEs_Extension extensionValue;

    __seq192();
    __seq192(const __seq192 &);
    __seq192(id, criticality, const extensionValue &);

    __seq192 & operator = (const __seq192 &);
    int operator == (const __seq192 &) const;
    int operator != (const __seq192 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    extensionValue & get_extensionValue();
    const extensionValue & get_extensionValue() const;
    void set_extensionValue(const extensionValue &);
private:
    id id_field;
    criticality criticality_field;
    extensionValue extensionValue_field;
};

class OSS_PUBLIC RecommendedCellItem   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef EUTRAN_CGI eUTRAN_CGI;
    typedef OSS_UINT32 timeStayedInCell;
    typedef __shared2 iE_Extensions;

    RecommendedCellItem();
    RecommendedCellItem(const RecommendedCellItem &);
    RecommendedCellItem(const eUTRAN_CGI &, timeStayedInCell, const iE_Extensions &);
    RecommendedCellItem(const eUTRAN_CGI &);

    RecommendedCellItem & operator = (const RecommendedCellItem &);
    int operator == (const RecommendedCellItem &) const;
    int operator != (const RecommendedCellItem &) const;

    eUTRAN_CGI & get_eUTRAN_CGI();
    const eUTRAN_CGI & get_eUTRAN_CGI() const;
    void set_eUTRAN_CGI(const eUTRAN_CGI &);

    timeStayedInCell *get_timeStayedInCell();
    const timeStayedInCell *get_timeStayedInCell() const;
    void set_timeStayedInCell(timeStayedInCell);
    int timeStayedInCell_is_present() const;
    void omit_timeStayedInCell();

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    eUTRAN_CGI eUTRAN_CGI_field;
    timeStayedInCell timeStayedInCell_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC RecommendedCellItemIEs_Value : public OssConstrainedOpenType
{
public:
    RecommendedCellItemIEs_Value();
    RecommendedCellItemIEs_Value(const RecommendedCellItemIEs_Value &);
    ~RecommendedCellItemIEs_Value();
    RecommendedCellItemIEs_Value & operator = (const RecommendedCellItemIEs_Value &);
    int operator == (const RecommendedCellItemIEs_Value &) const;
    int operator != (const RecommendedCellItemIEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    RecommendedCellItem *get_RecommendedCellItem();
    const RecommendedCellItem *get_RecommendedCellItem() const;
    void set_RecommendedCellItem(const RecommendedCellItem &);
    RecommendedCellItem *release_RecommendedCellItem();
    void set_RecommendedCellItem(RecommendedCellItem *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq193   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef RecommendedCellItemIEs_Value value;

    __seq193();
    __seq193(const __seq193 &);
    __seq193(id, criticality, const value &);

    __seq193 & operator = (const __seq193 &);
    int operator == (const __seq193 &) const;
    int operator != (const __seq193 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC RecommendedENBItem   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef MMEPagingTarget mMEPagingTarget;
    typedef __shared2 iE_Extensions;

    RecommendedENBItem();
    RecommendedENBItem(const RecommendedENBItem &);
    RecommendedENBItem(const mMEPagingTarget &, const iE_Extensions &);
    RecommendedENBItem(const mMEPagingTarget &);

    RecommendedENBItem & operator = (const RecommendedENBItem &);
    int operator == (const RecommendedENBItem &) const;
    int operator != (const RecommendedENBItem &) const;

    mMEPagingTarget & get_mMEPagingTarget();
    const mMEPagingTarget & get_mMEPagingTarget() const;
    void set_mMEPagingTarget(const mMEPagingTarget &);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    mMEPagingTarget mMEPagingTarget_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC RecommendedENBItemIEs_Value : public OssConstrainedOpenType
{
public:
    RecommendedENBItemIEs_Value();
    RecommendedENBItemIEs_Value(const RecommendedENBItemIEs_Value &);
    ~RecommendedENBItemIEs_Value();
    RecommendedENBItemIEs_Value & operator = (const RecommendedENBItemIEs_Value &);
    int operator == (const RecommendedENBItemIEs_Value &) const;
    int operator != (const RecommendedENBItemIEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    RecommendedENBItem *get_RecommendedENBItem();
    const RecommendedENBItem *get_RecommendedENBItem() const;
    void set_RecommendedENBItem(const RecommendedENBItem &);
    RecommendedENBItem *release_RecommendedENBItem();
    void set_RecommendedENBItem(RecommendedENBItem *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq195   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef RecommendedENBItemIEs_Value value;

    __seq195();
    __seq195(const __seq195 &);
    __seq195(id, criticality, const value &);

    __seq195 & operator = (const __seq195 &);
    int operator == (const __seq195 &) const;
    int operator != (const __seq195 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

typedef OssString RIMInformation;

typedef OssString UE_RLF_Report_Container;

typedef OssString UE_RLF_Report_Container_for_extended_bands;

typedef OSS_UINT32 RNC_ID;

typedef OssString RRC_Container;

class OSS_PUBLIC ENBX2ExtTLA;

class OSS_PUBLIC ENBX2ExtTLAs : public OssList  /* SEQUENCE OF */
{
public:
    typedef ENBX2ExtTLA component;

    ENBX2ExtTLAs();
    ENBX2ExtTLAs(const ENBX2ExtTLAs &);
    ~ENBX2ExtTLAs();

    ENBX2ExtTLAs & operator = (const ENBX2ExtTLAs &);
    int operator == (const ENBX2ExtTLAs &) const;
    int operator != (const ENBX2ExtTLAs &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(ENBX2ExtTLAs *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, ENBX2ExtTLAs *);

    int remove_front();
    int remove_after(OssIndex);

    ENBX2ExtTLAs *extract_after(OssIndex, OssIndex);
};

typedef __shared28 ENBIndirectX2TransportLayerAddresses;

class OSS_PUBLIC X2TNLConfigurationInfo_ExtIEs_Extension : public OssConstrainedOpenType
{
public:
    X2TNLConfigurationInfo_ExtIEs_Extension();
    X2TNLConfigurationInfo_ExtIEs_Extension(const X2TNLConfigurationInfo_ExtIEs_Extension &);
    ~X2TNLConfigurationInfo_ExtIEs_Extension();
    X2TNLConfigurationInfo_ExtIEs_Extension & operator = (const X2TNLConfigurationInfo_ExtIEs_Extension &);
    int operator == (const X2TNLConfigurationInfo_ExtIEs_Extension &) const;
    int operator != (const X2TNLConfigurationInfo_ExtIEs_Extension &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    ENBX2ExtTLAs *get_ENBX2ExtTLAs();
    const ENBX2ExtTLAs *get_ENBX2ExtTLAs() const;
    void set_ENBX2ExtTLAs(const ENBX2ExtTLAs &);
    ENBX2ExtTLAs *release_ENBX2ExtTLAs();
    void set_ENBX2ExtTLAs(ENBX2ExtTLAs *);

    __shared28 *get_ENBIndirectX2TransportLayerAddresses();
    const __shared28 *get_ENBIndirectX2TransportLayerAddresses() const;
    void set_ENBIndirectX2TransportLayerAddresses(const __shared28 &);
    __shared28 *release_ENBIndirectX2TransportLayerAddresses();
    void set_ENBIndirectX2TransportLayerAddresses(__shared28 *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq201   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef X2TNLConfigurationInfo_ExtIEs_Extension extensionValue;

    __seq201();
    __seq201(const __seq201 &);
    __seq201(id, criticality, const extensionValue &);

    __seq201 & operator = (const __seq201 &);
    int operator == (const __seq201 &) const;
    int operator != (const __seq201 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    extensionValue & get_extensionValue();
    const extensionValue & get_extensionValue() const;
    void set_extensionValue(const extensionValue &);
private:
    id id_field;
    criticality criticality_field;
    extensionValue extensionValue_field;
};

class OSS_PUBLIC __seq210;

class OSS_PUBLIC __seqof185 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq210 component;

    __seqof185();
    __seqof185(const __seqof185 &);
    ~__seqof185();

    __seqof185 & operator = (const __seqof185 &);
    int operator == (const __seqof185 &) const;
    int operator != (const __seqof185 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof185 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof185 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof185 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC TimeSynchronisationInfo   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_INT32 stratumLevel;
    typedef enum SynchronisationStatus synchronisationStatus;
    typedef __seqof185 iE_Extensions;

    TimeSynchronisationInfo();
    TimeSynchronisationInfo(const TimeSynchronisationInfo &);
    TimeSynchronisationInfo(stratumLevel, synchronisationStatus, const iE_Extensions &);
    TimeSynchronisationInfo(stratumLevel, synchronisationStatus);

    TimeSynchronisationInfo & operator = (const TimeSynchronisationInfo &);
    int operator == (const TimeSynchronisationInfo &) const;
    int operator != (const TimeSynchronisationInfo &) const;

    stratumLevel & get_stratumLevel();
    stratumLevel get_stratumLevel() const;
    void set_stratumLevel(stratumLevel);

    synchronisationStatus & get_synchronisationStatus();
    synchronisationStatus get_synchronisationStatus() const;
    void set_synchronisationStatus(synchronisationStatus);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    stratumLevel stratumLevel_field;
    synchronisationStatus synchronisationStatus_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC SONInformationReply_ExtIEs_Extension : public OssConstrainedOpenType
{
public:
    SONInformationReply_ExtIEs_Extension();
    SONInformationReply_ExtIEs_Extension(const SONInformationReply_ExtIEs_Extension &);
    ~SONInformationReply_ExtIEs_Extension();
    SONInformationReply_ExtIEs_Extension & operator = (const SONInformationReply_ExtIEs_Extension &);
    int operator == (const SONInformationReply_ExtIEs_Extension &) const;
    int operator != (const SONInformationReply_ExtIEs_Extension &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    TimeSynchronisationInfo *get_TimeSynchronisationInfo();
    const TimeSynchronisationInfo *get_TimeSynchronisationInfo() const;
    void set_TimeSynchronisationInfo(const TimeSynchronisationInfo &);
    TimeSynchronisationInfo *release_TimeSynchronisationInfo();
    void set_TimeSynchronisationInfo(TimeSynchronisationInfo *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq202   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef SONInformationReply_ExtIEs_Extension extensionValue;

    __seq202();
    __seq202(const __seq202 &);
    __seq202(id, criticality, const extensionValue &);

    __seq202 & operator = (const __seq202 &);
    int operator == (const __seq202 &) const;
    int operator != (const __seq202 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    extensionValue & get_extensionValue();
    const extensionValue & get_extensionValue() const;
    void set_extensionValue(const extensionValue &);
private:
    id id_field;
    criticality criticality_field;
    extensionValue extensionValue_field;
};

class OSS_PUBLIC SynchronisationInformation   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_INT32 sourceStratumLevel;
    typedef ListeningSubframePattern listeningSubframePattern;
    typedef __shared5 aggressoreCGI_List;
    typedef __shared2 iE_Extensions;

    SynchronisationInformation();
    SynchronisationInformation(const SynchronisationInformation &);
    SynchronisationInformation(sourceStratumLevel, const listeningSubframePattern &, 
	const aggressoreCGI_List &, const iE_Extensions &);

    SynchronisationInformation & operator = (const SynchronisationInformation &);
    int operator == (const SynchronisationInformation &) const;
    int operator != (const SynchronisationInformation &) const;

    sourceStratumLevel *get_sourceStratumLevel();
    const sourceStratumLevel *get_sourceStratumLevel() const;
    void set_sourceStratumLevel(sourceStratumLevel);
    int sourceStratumLevel_is_present() const;
    void omit_sourceStratumLevel();

    listeningSubframePattern *get_listeningSubframePattern();
    const listeningSubframePattern *get_listeningSubframePattern() const;
    void set_listeningSubframePattern(const listeningSubframePattern &);
    int listeningSubframePattern_is_present() const;
    void omit_listeningSubframePattern();

    aggressoreCGI_List *get_aggressoreCGI_List();
    const aggressoreCGI_List *get_aggressoreCGI_List() const;
    void set_aggressoreCGI_List(const aggressoreCGI_List &);
    int aggressoreCGI_List_is_present() const;
    void omit_aggressoreCGI_List();

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    sourceStratumLevel sourceStratumLevel_field;
    listeningSubframePattern listeningSubframePattern_field;
    aggressoreCGI_List aggressoreCGI_List_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC SONConfigurationTransfer_ExtIEs_Extension : public OssConstrainedOpenType
{
public:
    SONConfigurationTransfer_ExtIEs_Extension();
    SONConfigurationTransfer_ExtIEs_Extension(const SONConfigurationTransfer_ExtIEs_Extension &);
    ~SONConfigurationTransfer_ExtIEs_Extension();
    SONConfigurationTransfer_ExtIEs_Extension & operator = (const SONConfigurationTransfer_ExtIEs_Extension &);
    int operator == (const SONConfigurationTransfer_ExtIEs_Extension &) const;
    int operator != (const SONConfigurationTransfer_ExtIEs_Extension &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    X2TNLConfigurationInfo *get_X2TNLConfigurationInfo();
    const X2TNLConfigurationInfo *get_X2TNLConfigurationInfo() const;
    void set_X2TNLConfigurationInfo(const X2TNLConfigurationInfo &);
    X2TNLConfigurationInfo *release_X2TNLConfigurationInfo();
    void set_X2TNLConfigurationInfo(X2TNLConfigurationInfo *);

    SynchronisationInformation *get_SynchronisationInformation();
    const SynchronisationInformation *get_SynchronisationInformation() const;
    void set_SynchronisationInformation(const SynchronisationInformation &);
    SynchronisationInformation *release_SynchronisationInformation();
    void set_SynchronisationInformation(SynchronisationInformation *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq205   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef SONConfigurationTransfer_ExtIEs_Extension extensionValue;

    __seq205();
    __seq205(const __seq205 &);
    __seq205(id, criticality, const extensionValue &);

    __seq205 & operator = (const __seq205 &);
    int operator == (const __seq205 &) const;
    int operator != (const __seq205 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    extensionValue & get_extensionValue();
    const extensionValue & get_extensionValue() const;
    void set_extensionValue(const extensionValue &);
private:
    id id_field;
    criticality criticality_field;
    extensionValue extensionValue_field;
};

typedef OSS_INT32 StratumLevel;

class OSS_PUBLIC SourceeNB_ToTargeteNB_TransparentContainer_ExtIEs_Extension : public OssConstrainedOpenType
{
public:
    SourceeNB_ToTargeteNB_TransparentContainer_ExtIEs_Extension();
    SourceeNB_ToTargeteNB_TransparentContainer_ExtIEs_Extension(const SourceeNB_ToTargeteNB_TransparentContainer_ExtIEs_Extension &);
    ~SourceeNB_ToTargeteNB_TransparentContainer_ExtIEs_Extension();
    SourceeNB_ToTargeteNB_TransparentContainer_ExtIEs_Extension & operator = (const SourceeNB_ToTargeteNB_TransparentContainer_ExtIEs_Extension &);
    int operator == (const SourceeNB_ToTargeteNB_TransparentContainer_ExtIEs_Extension &) const;
    int operator != (const SourceeNB_ToTargeteNB_TransparentContainer_ExtIEs_Extension &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    S1AP_IEs_MobilityInformation *get_S1AP_IEs_MobilityInformation();
    const S1AP_IEs_MobilityInformation *get_S1AP_IEs_MobilityInformation() const;
    void set_S1AP_IEs_MobilityInformation(const S1AP_IEs_MobilityInformation &);
    S1AP_IEs_MobilityInformation *release_S1AP_IEs_MobilityInformation();
    void set_S1AP_IEs_MobilityInformation(S1AP_IEs_MobilityInformation *);

    UE_HistoryInformationFromTheUE *get_UE_HistoryInformationFromTheUE();
    const UE_HistoryInformationFromTheUE *get_UE_HistoryInformationFromTheUE() const;
    void set_UE_HistoryInformationFromTheUE(const UE_HistoryInformationFromTheUE &);
    UE_HistoryInformationFromTheUE *release_UE_HistoryInformationFromTheUE();
    void set_UE_HistoryInformationFromTheUE(UE_HistoryInformationFromTheUE *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __shared61 : public OssList  /* SEQUENCE OF */
{
public:
    typedef LastVisitedCell_Item component;

    __shared61();
    __shared61(const __shared61 &);
    ~__shared61();

    __shared61 & operator = (const __shared61 &);
    int operator == (const __shared61 &) const;
    int operator != (const __shared61 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__shared61 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __shared61 *);

    int remove_front();
    int remove_after(OssIndex);

    __shared61 *extract_after(OssIndex, OssIndex);
};

typedef __shared61 UE_HistoryInformation;

class OSS_PUBLIC __seq207;

class OSS_PUBLIC __seqof182 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq207 component;

    __seqof182();
    __seqof182(const __seqof182 &);
    ~__seqof182();

    __seqof182 & operator = (const __seqof182 &);
    int operator == (const __seqof182 &) const;
    int operator != (const __seqof182 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof182 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof182 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof182 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC SourceeNB_ToTargeteNB_TransparentContainer   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OssString rRC_Container;
    typedef E_RABInformationList e_RABInformationList;
    typedef EUTRAN_CGI targetCell_ID;
    typedef OSS_UINT32 subscriberProfileIDforRFP;
    typedef __shared61 uE_HistoryInformation;
    typedef __seqof182 iE_Extensions;

    SourceeNB_ToTargeteNB_TransparentContainer();
    SourceeNB_ToTargeteNB_TransparentContainer(const SourceeNB_ToTargeteNB_TransparentContainer &);
    SourceeNB_ToTargeteNB_TransparentContainer(const rRC_Container &, const e_RABInformationList &, 
	const targetCell_ID &, subscriberProfileIDforRFP, const uE_HistoryInformation &, 
	const iE_Extensions &);
    SourceeNB_ToTargeteNB_TransparentContainer(const rRC_Container &, const targetCell_ID &, 
	const uE_HistoryInformation &);

    SourceeNB_ToTargeteNB_TransparentContainer & operator = (const SourceeNB_ToTargeteNB_TransparentContainer &);
    int operator == (const SourceeNB_ToTargeteNB_TransparentContainer &) const;
    int operator != (const SourceeNB_ToTargeteNB_TransparentContainer &) const;

    rRC_Container & get_rRC_Container();
    const rRC_Container & get_rRC_Container() const;
    void set_rRC_Container(const rRC_Container &);

    e_RABInformationList *get_e_RABInformationList();
    const e_RABInformationList *get_e_RABInformationList() const;
    void set_e_RABInformationList(const e_RABInformationList &);
    int e_RABInformationList_is_present() const;
    void omit_e_RABInformationList();

    targetCell_ID & get_targetCell_ID();
    const targetCell_ID & get_targetCell_ID() const;
    void set_targetCell_ID(const targetCell_ID &);

    subscriberProfileIDforRFP *get_subscriberProfileIDforRFP();
    const subscriberProfileIDforRFP *get_subscriberProfileIDforRFP() const;
    void set_subscriberProfileIDforRFP(subscriberProfileIDforRFP);
    int subscriberProfileIDforRFP_is_present() const;
    void omit_subscriberProfileIDforRFP();

    uE_HistoryInformation & get_uE_HistoryInformation();
    const uE_HistoryInformation & get_uE_HistoryInformation() const;
    void set_uE_HistoryInformation(const uE_HistoryInformation &);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    rRC_Container rRC_Container_field;
    e_RABInformationList e_RABInformationList_field;
    targetCell_ID targetCell_ID_field;
    subscriberProfileIDforRFP subscriberProfileIDforRFP_field;
    uE_HistoryInformation uE_HistoryInformation_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC __seq207   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef SourceeNB_ToTargeteNB_TransparentContainer_ExtIEs_Extension extensionValue;

    __seq207();
    __seq207(const __seq207 &);
    __seq207(id, criticality, const extensionValue &);

    __seq207 & operator = (const __seq207 &);
    int operator == (const __seq207 &) const;
    int operator != (const __seq207 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    extensionValue & get_extensionValue();
    const extensionValue & get_extensionValue() const;
    void set_extensionValue(const extensionValue &);
private:
    id id_field;
    criticality criticality_field;
    extensionValue extensionValue_field;
};

typedef __shared4 ServedPLMNs;

typedef __shared4 ServedGroupIDs;

typedef __shared4 ServedMMECs;

class OSS_PUBLIC ServedGUMMEIsItem   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __shared4 servedPLMNs;
    typedef __shared4 servedGroupIDs;
    typedef __shared4 servedMMECs;
    typedef __shared2 iE_Extensions;

    ServedGUMMEIsItem();
    ServedGUMMEIsItem(const ServedGUMMEIsItem &);
    ServedGUMMEIsItem(const servedPLMNs &, const servedGroupIDs &, const servedMMECs &, 
	const iE_Extensions &);
    ServedGUMMEIsItem(const servedPLMNs &, const servedGroupIDs &, const servedMMECs &);

    ServedGUMMEIsItem & operator = (const ServedGUMMEIsItem &);
    int operator == (const ServedGUMMEIsItem &) const;
    int operator != (const ServedGUMMEIsItem &) const;

    servedPLMNs & get_servedPLMNs();
    const servedPLMNs & get_servedPLMNs() const;
    void set_servedPLMNs(const servedPLMNs &);

    servedGroupIDs & get_servedGroupIDs();
    const servedGroupIDs & get_servedGroupIDs() const;
    void set_servedGroupIDs(const servedGroupIDs &);

    servedMMECs & get_servedMMECs();
    const servedMMECs & get_servedMMECs() const;
    void set_servedMMECs(const servedMMECs &);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    servedPLMNs servedPLMNs_field;
    servedGroupIDs servedGroupIDs_field;
    servedMMECs servedMMECs_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC SupportedTAs_Item_ExtIEs_Extension : public OssConstrainedOpenType
{
public:
    SupportedTAs_Item_ExtIEs_Extension();
    SupportedTAs_Item_ExtIEs_Extension(const SupportedTAs_Item_ExtIEs_Extension &);
    ~SupportedTAs_Item_ExtIEs_Extension();
    SupportedTAs_Item_ExtIEs_Extension & operator = (const SupportedTAs_Item_ExtIEs_Extension &);
    int operator == (const SupportedTAs_Item_ExtIEs_Extension &) const;
    int operator != (const SupportedTAs_Item_ExtIEs_Extension &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    RAT_Type *get_RAT_Type();
    const RAT_Type *get_RAT_Type() const;
    void set_RAT_Type(const RAT_Type &);
    RAT_Type *release_RAT_Type();
    void set_RAT_Type(RAT_Type *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq209;

class OSS_PUBLIC __seqof184 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq209 component;

    __seqof184();
    __seqof184(const __seqof184 &);
    ~__seqof184();

    __seqof184 & operator = (const __seqof184 &);
    int operator == (const __seqof184 &) const;
    int operator != (const __seqof184 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof184 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof184 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof184 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC SupportedTAs_Item   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OssString tAC;
    typedef __shared4 broadcastPLMNs;
    typedef __seqof184 iE_Extensions;

    SupportedTAs_Item();
    SupportedTAs_Item(const SupportedTAs_Item &);
    SupportedTAs_Item(const tAC &, const broadcastPLMNs &, const iE_Extensions &);
    SupportedTAs_Item(const tAC &, const broadcastPLMNs &);

    SupportedTAs_Item & operator = (const SupportedTAs_Item &);
    int operator == (const SupportedTAs_Item &) const;
    int operator != (const SupportedTAs_Item &) const;

    tAC & get_tAC();
    const tAC & get_tAC() const;
    void set_tAC(const tAC &);

    broadcastPLMNs & get_broadcastPLMNs();
    const broadcastPLMNs & get_broadcastPLMNs() const;
    void set_broadcastPLMNs(const broadcastPLMNs &);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    tAC tAC_field;
    broadcastPLMNs broadcastPLMNs_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC __seq209   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef SupportedTAs_Item_ExtIEs_Extension extensionValue;

    __seq209();
    __seq209(const __seq209 &);
    __seq209(id, criticality, const extensionValue &);

    __seq209 & operator = (const __seq209 &);
    int operator == (const __seq209 &) const;
    int operator != (const __seq209 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    extensionValue & get_extensionValue();
    const extensionValue & get_extensionValue() const;
    void set_extensionValue(const extensionValue &);
private:
    id id_field;
    criticality criticality_field;
    extensionValue extensionValue_field;
};

class OSS_PUBLIC TimeSynchronisationInfo_ExtIEs_Extension : public OssConstrainedOpenType
{
public:
    TimeSynchronisationInfo_ExtIEs_Extension();
    TimeSynchronisationInfo_ExtIEs_Extension(const TimeSynchronisationInfo_ExtIEs_Extension &);
    ~TimeSynchronisationInfo_ExtIEs_Extension();
    TimeSynchronisationInfo_ExtIEs_Extension & operator = (const TimeSynchronisationInfo_ExtIEs_Extension &);
    int operator == (const TimeSynchronisationInfo_ExtIEs_Extension &) const;
    int operator != (const TimeSynchronisationInfo_ExtIEs_Extension &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    MutingAvailabilityIndication *get_MutingAvailabilityIndication();
    const MutingAvailabilityIndication *get_MutingAvailabilityIndication() const;
    void set_MutingAvailabilityIndication(const MutingAvailabilityIndication &);
    MutingAvailabilityIndication *release_MutingAvailabilityIndication();
    void set_MutingAvailabilityIndication(MutingAvailabilityIndication *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq210   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef TimeSynchronisationInfo_ExtIEs_Extension extensionValue;

    __seq210();
    __seq210(const __seq210 &);
    __seq210(id, criticality, const extensionValue &);

    __seq210 & operator = (const __seq210 &);
    int operator == (const __seq210 &) const;
    int operator != (const __seq210 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    extensionValue & get_extensionValue();
    const extensionValue & get_extensionValue() const;
    void set_extensionValue(const extensionValue &);
private:
    id id_field;
    criticality criticality_field;
    extensionValue extensionValue_field;
};

typedef __shared45 CompletedCellinTAI;

class OSS_PUBLIC TAI_Broadcast_Item   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef TAI tAI;
    typedef __shared45 completedCellinTAI;
    typedef __shared2 iE_Extensions;

    TAI_Broadcast_Item();
    TAI_Broadcast_Item(const TAI_Broadcast_Item &);
    TAI_Broadcast_Item(const tAI &, const completedCellinTAI &, const iE_Extensions &);
    TAI_Broadcast_Item(const tAI &, const completedCellinTAI &);

    TAI_Broadcast_Item & operator = (const TAI_Broadcast_Item &);
    int operator == (const TAI_Broadcast_Item &) const;
    int operator != (const TAI_Broadcast_Item &) const;

    tAI & get_tAI();
    const tAI & get_tAI() const;
    void set_tAI(const tAI &);

    completedCellinTAI & get_completedCellinTAI();
    const completedCellinTAI & get_completedCellinTAI() const;
    void set_completedCellinTAI(const completedCellinTAI &);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    tAI tAI_field;
    completedCellinTAI completedCellinTAI_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC TAI_Cancelled_Item   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef TAI tAI;
    typedef __shared37 cancelledCellinTAI;
    typedef __shared2 iE_Extensions;

    TAI_Cancelled_Item();
    TAI_Cancelled_Item(const TAI_Cancelled_Item &);
    TAI_Cancelled_Item(const tAI &, const cancelledCellinTAI &, const iE_Extensions &);
    TAI_Cancelled_Item(const tAI &, const cancelledCellinTAI &);

    TAI_Cancelled_Item & operator = (const TAI_Cancelled_Item &);
    int operator == (const TAI_Cancelled_Item &) const;
    int operator != (const TAI_Cancelled_Item &) const;

    tAI & get_tAI();
    const tAI & get_tAI() const;
    void set_tAI(const tAI &);

    cancelledCellinTAI & get_cancelledCellinTAI();
    const cancelledCellinTAI & get_cancelledCellinTAI() const;
    void set_cancelledCellinTAI(const cancelledCellinTAI &);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    tAI tAI_field;
    cancelledCellinTAI cancelledCellinTAI_field;
    iE_Extensions iE_Extensions_field;
};

typedef __shared44 CompletedCellinTAI_Item;

class OSS_PUBLIC TargeteNB_ToSourceeNB_TransparentContainer   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OssString rRC_Container;
    typedef __shared2 iE_Extensions;

    TargeteNB_ToSourceeNB_TransparentContainer();
    TargeteNB_ToSourceeNB_TransparentContainer(const TargeteNB_ToSourceeNB_TransparentContainer &);
    TargeteNB_ToSourceeNB_TransparentContainer(const rRC_Container &, const iE_Extensions &);
    TargeteNB_ToSourceeNB_TransparentContainer(const rRC_Container &);

    TargeteNB_ToSourceeNB_TransparentContainer & operator = (const TargeteNB_ToSourceeNB_TransparentContainer &);
    int operator == (const TargeteNB_ToSourceeNB_TransparentContainer &) const;
    int operator != (const TargeteNB_ToSourceeNB_TransparentContainer &) const;

    rRC_Container & get_rRC_Container();
    const rRC_Container & get_rRC_Container() const;
    void set_rRC_Container(const rRC_Container &);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    rRC_Container rRC_Container_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC TraceActivation_ExtIEs_Extension : public OssConstrainedOpenType
{
public:
    TraceActivation_ExtIEs_Extension();
    TraceActivation_ExtIEs_Extension(const TraceActivation_ExtIEs_Extension &);
    ~TraceActivation_ExtIEs_Extension();
    TraceActivation_ExtIEs_Extension & operator = (const TraceActivation_ExtIEs_Extension &);
    int operator == (const TraceActivation_ExtIEs_Extension &) const;
    int operator != (const TraceActivation_ExtIEs_Extension &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    MDT_Configuration *get_MDT_Configuration();
    const MDT_Configuration *get_MDT_Configuration() const;
    void set_MDT_Configuration(const MDT_Configuration &);
    MDT_Configuration *release_MDT_Configuration();
    void set_MDT_Configuration(MDT_Configuration *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq219   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef TraceActivation_ExtIEs_Extension extensionValue;

    __seq219();
    __seq219(const __seq219 &);
    __seq219(id, criticality, const extensionValue &);

    __seq219 & operator = (const __seq219 &);
    int operator == (const __seq219 &) const;
    int operator != (const __seq219 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    extensionValue & get_extensionValue();
    const extensionValue & get_extensionValue() const;
    void set_extensionValue(const extensionValue &);
private:
    id id_field;
    criticality criticality_field;
    extensionValue extensionValue_field;
};

typedef __shared28 ENBX2GTPTLAs;

class OSS_PUBLIC ENBX2ExtTLA   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OssBitString iPsecTLA;
    typedef __shared28 gTPTLAa;
    typedef __shared2 iE_Extensions;

    ENBX2ExtTLA();
    ENBX2ExtTLA(const ENBX2ExtTLA &);
    ENBX2ExtTLA(const iPsecTLA &, const gTPTLAa &, const iE_Extensions &);

    ENBX2ExtTLA & operator = (const ENBX2ExtTLA &);
    int operator == (const ENBX2ExtTLA &) const;
    int operator != (const ENBX2ExtTLA &) const;

    iPsecTLA *get_iPsecTLA();
    const iPsecTLA *get_iPsecTLA() const;
    void set_iPsecTLA(const iPsecTLA &);
    int iPsecTLA_is_present() const;
    void omit_iPsecTLA();

    gTPTLAa *get_gTPTLAa();
    const gTPTLAa *get_gTPTLAa() const;
    void set_gTPTLAa(const gTPTLAa &);
    int gTPTLAa_is_present() const;
    void omit_gTPTLAa();

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    iPsecTLA iPsecTLA_field;
    gTPTLAa gTPTLAa_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC IRAT_Cell_ID;

class OSS_PUBLIC __shared62 : public OssList  /* SEQUENCE OF */
{
public:
    typedef IRAT_Cell_ID component;

    __shared62();
    __shared62(const __shared62 &);
    ~__shared62();

    __shared62 & operator = (const __shared62 &);
    int operator == (const __shared62 &) const;
    int operator != (const __shared62 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__shared62 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __shared62 *);

    int remove_front();
    int remove_after(OssIndex);

    __shared62 *extract_after(OssIndex, OssIndex);
};

typedef __shared62 RequestedCellList;

class OSS_PUBLIC MultiCellLoadReportingRequest   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __shared62 requestedCellList;

    MultiCellLoadReportingRequest();
    MultiCellLoadReportingRequest(const MultiCellLoadReportingRequest &);
    MultiCellLoadReportingRequest(const requestedCellList &);

    MultiCellLoadReportingRequest & operator = (const MultiCellLoadReportingRequest &);
    int operator == (const MultiCellLoadReportingRequest &) const;
    int operator != (const MultiCellLoadReportingRequest &) const;

    requestedCellList & get_requestedCellList();
    const requestedCellList & get_requestedCellList() const;
    void set_requestedCellList(const requestedCellList &);
private:
    requestedCellList requestedCellList_field;
};

class OSS_PUBLIC EventTriggeredCellLoadReportingRequest   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef enum NumberOfMeasurementReportingLevels numberOfMeasurementReportingLevels;

    EventTriggeredCellLoadReportingRequest();
    EventTriggeredCellLoadReportingRequest(const EventTriggeredCellLoadReportingRequest &);
    EventTriggeredCellLoadReportingRequest(numberOfMeasurementReportingLevels);

    EventTriggeredCellLoadReportingRequest & operator = (const EventTriggeredCellLoadReportingRequest &);
    int operator == (const EventTriggeredCellLoadReportingRequest &) const;
    int operator != (const EventTriggeredCellLoadReportingRequest &) const;

    numberOfMeasurementReportingLevels & get_numberOfMeasurementReportingLevels();
    numberOfMeasurementReportingLevels get_numberOfMeasurementReportingLevels() const;
    void set_numberOfMeasurementReportingLevels(numberOfMeasurementReportingLevels);
private:
    numberOfMeasurementReportingLevels numberOfMeasurementReportingLevels_field;
};

class OSS_PUBLIC IRAT_Cell_ID  : public OssChoice   /* CHOICE */
{
public:
    enum Id {
	unselected,
	eUTRAN_chosen = 1,
	uTRAN_chosen = 2,
	gERAN_chosen = 3,
	eHRPD_chosen = 4
    };
    typedef OssString eUTRAN;
    typedef OssString uTRAN;
    typedef OssString gERAN;
    typedef OssString eHRPD;

    IRAT_Cell_ID();
    IRAT_Cell_ID(const IRAT_Cell_ID &);
    ~IRAT_Cell_ID();

    IRAT_Cell_ID & operator = (const IRAT_Cell_ID &);
    int operator == (const IRAT_Cell_ID &) const;
    int operator != (const IRAT_Cell_ID &) const;

    eUTRAN *get_eUTRAN();
    const eUTRAN *get_eUTRAN() const;
    void set_eUTRAN(const eUTRAN &);

    uTRAN *get_uTRAN();
    const uTRAN *get_uTRAN() const;
    void set_uTRAN(const uTRAN &);

    gERAN *get_gERAN();
    const gERAN *get_gERAN() const;
    void set_gERAN(const gERAN &);

    eHRPD *get_eHRPD();
    const eHRPD *get_eHRPD() const;
    void set_eHRPD(const eHRPD &);
private:
    union {
	OSSC::COssString eUTRAN_field;
	OSSC::COssString uTRAN_field;
	OSSC::COssString gERAN_field;
	OSSC::COssString eHRPD_field;
    };
    void cleanup();
};

typedef __shared62 CandidateCellList;

class OSS_PUBLIC CandidatePCI;

class OSS_PUBLIC __shared63 : public OssList  /* SEQUENCE OF */
{
public:
    typedef CandidatePCI component;

    __shared63();
    __shared63(const __shared63 &);
    ~__shared63();

    __shared63 & operator = (const __shared63 &);
    int operator == (const __shared63 &) const;
    int operator != (const __shared63 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__shared63 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __shared63 *);

    int remove_front();
    int remove_after(OssIndex);

    __shared63 *extract_after(OssIndex, OssIndex);
};

typedef __shared63 CandidatePCIList;

class OSS_PUBLIC HOReport   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef enum HoType hoType;
    typedef enum HoReportType hoReportType;
    typedef IRAT_Cell_ID hosourceID;
    typedef IRAT_Cell_ID hoTargetID;
    typedef __shared62 candidateCellList;
    typedef __shared63 candidatePCIList;

    HOReport();
    HOReport(const HOReport &);
    HOReport(hoType, hoReportType, const hosourceID &, const hoTargetID &, const candidateCellList &, 
	const candidatePCIList &);
    HOReport(hoType, hoReportType, const hosourceID &, const hoTargetID &, const candidateCellList &);

    HOReport & operator = (const HOReport &);
    int operator == (const HOReport &) const;
    int operator != (const HOReport &) const;

    hoType & get_hoType();
    hoType get_hoType() const;
    void set_hoType(hoType);

    hoReportType & get_hoReportType();
    hoReportType get_hoReportType() const;
    void set_hoReportType(hoReportType);

    hosourceID & get_hosourceID();
    const hosourceID & get_hosourceID() const;
    void set_hosourceID(const hosourceID &);

    hoTargetID & get_hoTargetID();
    const hoTargetID & get_hoTargetID() const;
    void set_hoTargetID(const hoTargetID &);

    candidateCellList & get_candidateCellList();
    const candidateCellList & get_candidateCellList() const;
    void set_candidateCellList(const candidateCellList &);

    candidatePCIList *get_candidatePCIList();
    const candidatePCIList *get_candidatePCIList() const;
    void set_candidatePCIList(const candidatePCIList &);
    int candidatePCIList_is_present() const;
    void omit_candidatePCIList();
private:
    OSS_UINT32 bit_mask;
    hoType hoType_field;
    hoReportType hoReportType_field;
    hosourceID hosourceID_field;
    hoTargetID hoTargetID_field;
    candidateCellList candidateCellList_field;
    candidatePCIList candidatePCIList_field;
};

class OSS_PUBLIC __shared64;

class OSS_PUBLIC __shared65 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __shared64 component;

    __shared65();
    __shared65(const __shared65 &);
    ~__shared65();

    __shared65 & operator = (const __shared65 &);
    int operator == (const __shared65 &) const;
    int operator != (const __shared65 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__shared65 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __shared65 *);

    int remove_front();
    int remove_after(OssIndex);

    __shared65 *extract_after(OssIndex, OssIndex);
};

typedef __shared65 CellsToActivateList;

class OSS_PUBLIC CellActivationRequest   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __shared65 cellsToActivateList;
    typedef OSS_UINT32 minimumActivationTime;

    CellActivationRequest();
    CellActivationRequest(const CellActivationRequest &);
    CellActivationRequest(const cellsToActivateList &, minimumActivationTime);
    CellActivationRequest(const cellsToActivateList &);

    CellActivationRequest & operator = (const CellActivationRequest &);
    int operator == (const CellActivationRequest &) const;
    int operator != (const CellActivationRequest &) const;

    cellsToActivateList & get_cellsToActivateList();
    const cellsToActivateList & get_cellsToActivateList() const;
    void set_cellsToActivateList(const cellsToActivateList &);

    minimumActivationTime *get_minimumActivationTime();
    const minimumActivationTime *get_minimumActivationTime() const;
    void set_minimumActivationTime(minimumActivationTime);
    int minimumActivationTime_is_present() const;
    void omit_minimumActivationTime();
private:
    OSS_UINT32 bit_mask;
    cellsToActivateList cellsToActivateList_field;
    minimumActivationTime minimumActivationTime_field;
};

class OSS_PUBLIC NotificationCellList_Item;

class OSS_PUBLIC __shared66 : public OssList  /* SEQUENCE OF */
{
public:
    typedef NotificationCellList_Item component;

    __shared66();
    __shared66(const __shared66 &);
    ~__shared66();

    __shared66 & operator = (const __shared66 &);
    int operator == (const __shared66 &) const;
    int operator != (const __shared66 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__shared66 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __shared66 *);

    int remove_front();
    int remove_after(OssIndex);

    __shared66 *extract_after(OssIndex, OssIndex);
};

typedef __shared66 NotificationCellList;

class OSS_PUBLIC CellStateIndication   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __shared66 notificationCellList;

    CellStateIndication();
    CellStateIndication(const CellStateIndication &);
    CellStateIndication(const notificationCellList &);

    CellStateIndication & operator = (const CellStateIndication &);
    int operator == (const CellStateIndication &) const;
    int operator != (const CellStateIndication &) const;

    notificationCellList & get_notificationCellList();
    const notificationCellList & get_notificationCellList() const;
    void set_notificationCellList(const notificationCellList &);
private:
    notificationCellList notificationCellList_field;
};

class OSS_PUBLIC TooEarlyInterRATHOReportReportFromEUTRAN   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OssString uERLFReportContainer;
    typedef OssBitString mobilityInformation;

    TooEarlyInterRATHOReportReportFromEUTRAN();
    TooEarlyInterRATHOReportReportFromEUTRAN(const TooEarlyInterRATHOReportReportFromEUTRAN &);
    TooEarlyInterRATHOReportReportFromEUTRAN(const uERLFReportContainer &, const mobilityInformation &);
    TooEarlyInterRATHOReportReportFromEUTRAN(const uERLFReportContainer &);

    TooEarlyInterRATHOReportReportFromEUTRAN & operator = (const TooEarlyInterRATHOReportReportFromEUTRAN &);
    int operator == (const TooEarlyInterRATHOReportReportFromEUTRAN &) const;
    int operator != (const TooEarlyInterRATHOReportReportFromEUTRAN &) const;

    uERLFReportContainer & get_uERLFReportContainer();
    const uERLFReportContainer & get_uERLFReportContainer() const;
    void set_uERLFReportContainer(const uERLFReportContainer &);

    mobilityInformation *get_mobilityInformation();
    const mobilityInformation *get_mobilityInformation() const;
    void set_mobilityInformation(const mobilityInformation &);
    int mobilityInformation_is_present() const;
    void omit_mobilityInformation();
private:
    OSS_UINT32 bit_mask;
    uERLFReportContainer uERLFReportContainer_field;
    mobilityInformation mobilityInformation_field;
};

class OSS_PUBLIC FailureEventReport  : public OssChoice   /* CHOICE */
{
public:
    enum Id {
	unselected,
	tooEarlyInterRATHOReportFromEUTRAN_chosen = 1
    };
    typedef TooEarlyInterRATHOReportReportFromEUTRAN tooEarlyInterRATHOReportFromEUTRAN;

    FailureEventReport();
    FailureEventReport(const FailureEventReport &);
    ~FailureEventReport();

    FailureEventReport & operator = (const FailureEventReport &);
    int operator == (const FailureEventReport &) const;
    int operator != (const FailureEventReport &) const;

    tooEarlyInterRATHOReportFromEUTRAN *get_tooEarlyInterRATHOReportFromEUTRAN();
    const tooEarlyInterRATHOReportFromEUTRAN *get_tooEarlyInterRATHOReportFromEUTRAN() const;
    void set_tooEarlyInterRATHOReportFromEUTRAN(const tooEarlyInterRATHOReportFromEUTRAN &);
private:
    union {
	tooEarlyInterRATHOReportFromEUTRAN *tooEarlyInterRATHOReportFromEUTRAN_field;
    };
    void cleanup();
};

class OSS_PUBLIC SONtransferRequestContainer  : public OssChoice   /* CHOICE */
{
public:
    enum Id {
	unselected,
	cellLoadReporting_chosen = 1,
	multiCellLoadReporting_chosen = 2,
	eventTriggeredCellLoadReporting_chosen = 3,
	hOReporting_chosen = 4,
	eutranCellActivation_chosen = 5,
	energySavingsIndication_chosen = 6,
	failureEventReporting_chosen = 7
    };
    typedef Nulltype cellLoadReporting;
    typedef MultiCellLoadReportingRequest multiCellLoadReporting;
    typedef EventTriggeredCellLoadReportingRequest eventTriggeredCellLoadReporting;
    typedef HOReport hOReporting;
    typedef CellActivationRequest eutranCellActivation;
    typedef CellStateIndication energySavingsIndication;
    typedef FailureEventReport failureEventReporting;

    SONtransferRequestContainer();
    SONtransferRequestContainer(const SONtransferRequestContainer &);
    ~SONtransferRequestContainer();

    SONtransferRequestContainer & operator = (const SONtransferRequestContainer &);
    int operator == (const SONtransferRequestContainer &) const;
    int operator != (const SONtransferRequestContainer &) const;

    cellLoadReporting *get_cellLoadReporting();
    const cellLoadReporting *get_cellLoadReporting() const;
    void set_cellLoadReporting(cellLoadReporting);

    multiCellLoadReporting *get_multiCellLoadReporting();
    const multiCellLoadReporting *get_multiCellLoadReporting() const;
    void set_multiCellLoadReporting(const multiCellLoadReporting &);

    eventTriggeredCellLoadReporting *get_eventTriggeredCellLoadReporting();
    const eventTriggeredCellLoadReporting *get_eventTriggeredCellLoadReporting() const;
    void set_eventTriggeredCellLoadReporting(const eventTriggeredCellLoadReporting &);

    hOReporting *get_hOReporting();
    const hOReporting *get_hOReporting() const;
    void set_hOReporting(const hOReporting &);

    eutranCellActivation *get_eutranCellActivation();
    const eutranCellActivation *get_eutranCellActivation() const;
    void set_eutranCellActivation(const eutranCellActivation &);

    energySavingsIndication *get_energySavingsIndication();
    const energySavingsIndication *get_energySavingsIndication() const;
    void set_energySavingsIndication(const energySavingsIndication &);

    failureEventReporting *get_failureEventReporting();
    const failureEventReporting *get_failureEventReporting() const;
    void set_failureEventReporting(const failureEventReporting &);
private:
    union {
	cellLoadReporting cellLoadReporting_field;
	multiCellLoadReporting *multiCellLoadReporting_field;
	eventTriggeredCellLoadReporting *eventTriggeredCellLoadReporting_field;
	hOReporting *hOReporting_field;
	eutranCellActivation *eutranCellActivation_field;
	energySavingsIndication *energySavingsIndication_field;
	failureEventReporting *failureEventReporting_field;
    };
    void cleanup();
};

class OSS_PUBLIC EUTRANcellLoadReportingResponse   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OssString compositeAvailableCapacityGroup;

    EUTRANcellLoadReportingResponse();
    EUTRANcellLoadReportingResponse(const EUTRANcellLoadReportingResponse &);
    EUTRANcellLoadReportingResponse(const compositeAvailableCapacityGroup &);

    EUTRANcellLoadReportingResponse & operator = (const EUTRANcellLoadReportingResponse &);
    int operator == (const EUTRANcellLoadReportingResponse &) const;
    int operator != (const EUTRANcellLoadReportingResponse &) const;

    compositeAvailableCapacityGroup & get_compositeAvailableCapacityGroup();
    const compositeAvailableCapacityGroup & get_compositeAvailableCapacityGroup() const;
    void set_compositeAvailableCapacityGroup(const compositeAvailableCapacityGroup &);
private:
    compositeAvailableCapacityGroup compositeAvailableCapacityGroup_field;
};

class OSS_PUBLIC EHRPDCompositeAvailableCapacity   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_INT32 eHRPDSectorCapacityClassValue;
    typedef OSS_UINT32 eHRPDCapacityValue;

    EHRPDCompositeAvailableCapacity();
    EHRPDCompositeAvailableCapacity(const EHRPDCompositeAvailableCapacity &);
    EHRPDCompositeAvailableCapacity(eHRPDSectorCapacityClassValue, eHRPDCapacityValue);

    EHRPDCompositeAvailableCapacity & operator = (const EHRPDCompositeAvailableCapacity &);
    int operator == (const EHRPDCompositeAvailableCapacity &) const;
    int operator != (const EHRPDCompositeAvailableCapacity &) const;

    eHRPDSectorCapacityClassValue & get_eHRPDSectorCapacityClassValue();
    eHRPDSectorCapacityClassValue get_eHRPDSectorCapacityClassValue() const;
    void set_eHRPDSectorCapacityClassValue(eHRPDSectorCapacityClassValue);

    eHRPDCapacityValue & get_eHRPDCapacityValue();
    eHRPDCapacityValue get_eHRPDCapacityValue() const;
    void set_eHRPDCapacityValue(eHRPDCapacityValue);
private:
    eHRPDSectorCapacityClassValue eHRPDSectorCapacityClassValue_field;
    eHRPDCapacityValue eHRPDCapacityValue_field;
};

class OSS_PUBLIC EHRPDSectorLoadReportingResponse   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef EHRPDCompositeAvailableCapacity dL_EHRPD_CompositeAvailableCapacity;
    typedef EHRPDCompositeAvailableCapacity uL_EHRPD_CompositeAvailableCapacity;

    EHRPDSectorLoadReportingResponse();
    EHRPDSectorLoadReportingResponse(const EHRPDSectorLoadReportingResponse &);
    EHRPDSectorLoadReportingResponse(const dL_EHRPD_CompositeAvailableCapacity &, 
	const uL_EHRPD_CompositeAvailableCapacity &);

    EHRPDSectorLoadReportingResponse & operator = (const EHRPDSectorLoadReportingResponse &);
    int operator == (const EHRPDSectorLoadReportingResponse &) const;
    int operator != (const EHRPDSectorLoadReportingResponse &) const;

    dL_EHRPD_CompositeAvailableCapacity & get_dL_EHRPD_CompositeAvailableCapacity();
    const dL_EHRPD_CompositeAvailableCapacity & get_dL_EHRPD_CompositeAvailableCapacity() const;
    void set_dL_EHRPD_CompositeAvailableCapacity(const dL_EHRPD_CompositeAvailableCapacity &);

    uL_EHRPD_CompositeAvailableCapacity & get_uL_EHRPD_CompositeAvailableCapacity();
    const uL_EHRPD_CompositeAvailableCapacity & get_uL_EHRPD_CompositeAvailableCapacity() const;
    void set_uL_EHRPD_CompositeAvailableCapacity(const uL_EHRPD_CompositeAvailableCapacity &);
private:
    dL_EHRPD_CompositeAvailableCapacity dL_EHRPD_CompositeAvailableCapacity_field;
    uL_EHRPD_CompositeAvailableCapacity uL_EHRPD_CompositeAvailableCapacity_field;
};

class OSS_PUBLIC CellLoadReportingResponse  : public OssChoice   /* CHOICE */
{
public:
    enum Id {
	unselected,
	eUTRAN_chosen = 1,
	uTRAN_chosen = 2,
	gERAN_chosen = 3,
	eHRPD_chosen = 4
    };
    typedef EUTRANcellLoadReportingResponse eUTRAN;
    typedef OssString uTRAN;
    typedef OssString gERAN;
    typedef EHRPDSectorLoadReportingResponse eHRPD;

    CellLoadReportingResponse();
    CellLoadReportingResponse(const CellLoadReportingResponse &);
    ~CellLoadReportingResponse();

    CellLoadReportingResponse & operator = (const CellLoadReportingResponse &);
    int operator == (const CellLoadReportingResponse &) const;
    int operator != (const CellLoadReportingResponse &) const;

    eUTRAN *get_eUTRAN();
    const eUTRAN *get_eUTRAN() const;
    void set_eUTRAN(const eUTRAN &);

    uTRAN *get_uTRAN();
    const uTRAN *get_uTRAN() const;
    void set_uTRAN(const uTRAN &);

    gERAN *get_gERAN();
    const gERAN *get_gERAN() const;
    void set_gERAN(const gERAN &);

    eHRPD *get_eHRPD();
    const eHRPD *get_eHRPD() const;
    void set_eHRPD(const eHRPD &);
private:
    union {
	eUTRAN *eUTRAN_field;
	OSSC::COssString uTRAN_field;
	OSSC::COssString gERAN_field;
	eHRPD *eHRPD_field;
    };
    void cleanup();
};

class OSS_PUBLIC MultiCellLoadReportingResponse_Item;

class OSS_PUBLIC __shared67 : public OssList  /* SEQUENCE OF */
{
public:
    typedef MultiCellLoadReportingResponse_Item component;

    __shared67();
    __shared67(const __shared67 &);
    ~__shared67();

    __shared67 & operator = (const __shared67 &);
    int operator == (const __shared67 &) const;
    int operator != (const __shared67 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__shared67 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __shared67 *);

    int remove_front();
    int remove_after(OssIndex);

    __shared67 *extract_after(OssIndex, OssIndex);
};

typedef __shared67 MultiCellLoadReportingResponse;

class OSS_PUBLIC EventTriggeredCellLoadReportingResponse   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef CellLoadReportingResponse cellLoadReportingResponse;
    typedef enum OverloadFlag overloadFlag;

    EventTriggeredCellLoadReportingResponse();
    EventTriggeredCellLoadReportingResponse(const EventTriggeredCellLoadReportingResponse &);
    EventTriggeredCellLoadReportingResponse(const cellLoadReportingResponse &, overloadFlag);
    EventTriggeredCellLoadReportingResponse(const cellLoadReportingResponse &);

    EventTriggeredCellLoadReportingResponse & operator = (const EventTriggeredCellLoadReportingResponse &);
    int operator == (const EventTriggeredCellLoadReportingResponse &) const;
    int operator != (const EventTriggeredCellLoadReportingResponse &) const;

    cellLoadReportingResponse & get_cellLoadReportingResponse();
    const cellLoadReportingResponse & get_cellLoadReportingResponse() const;
    void set_cellLoadReportingResponse(const cellLoadReportingResponse &);

    overloadFlag *get_overloadFlag();
    const overloadFlag *get_overloadFlag() const;
    void set_overloadFlag(overloadFlag);
    int overloadFlag_is_present() const;
    void omit_overloadFlag();
private:
    OSS_UINT32 bit_mask;
    cellLoadReportingResponse cellLoadReportingResponse_field;
    overloadFlag overloadFlag_field;
};

typedef __shared65 ActivatedCellsList;

class OSS_PUBLIC CellActivationResponse   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __shared65 activatedCellsList;

    CellActivationResponse();
    CellActivationResponse(const CellActivationResponse &);
    CellActivationResponse(const activatedCellsList &);

    CellActivationResponse & operator = (const CellActivationResponse &);
    int operator == (const CellActivationResponse &) const;
    int operator != (const CellActivationResponse &) const;

    activatedCellsList & get_activatedCellsList();
    const activatedCellsList & get_activatedCellsList() const;
    void set_activatedCellsList(const activatedCellsList &);
private:
    activatedCellsList activatedCellsList_field;
};

class OSS_PUBLIC SONtransferResponseContainer  : public OssChoice   /* CHOICE */
{
public:
    enum Id {
	unselected,
	cellLoadReporting_chosen = 1,
	multiCellLoadReporting_chosen = 2,
	eventTriggeredCellLoadReporting_chosen = 3,
	hOReporting_chosen = 4,
	eutranCellActivation_chosen = 5,
	energySavingsIndication_chosen = 6,
	failureEventReporting_chosen = 7
    };
    typedef CellLoadReportingResponse cellLoadReporting;
    typedef __shared67 multiCellLoadReporting;
    typedef EventTriggeredCellLoadReportingResponse eventTriggeredCellLoadReporting;
    typedef Nulltype hOReporting;
    typedef CellActivationResponse eutranCellActivation;
    typedef Nulltype energySavingsIndication;
    typedef Nulltype failureEventReporting;

    SONtransferResponseContainer();
    SONtransferResponseContainer(const SONtransferResponseContainer &);
    ~SONtransferResponseContainer();

    SONtransferResponseContainer & operator = (const SONtransferResponseContainer &);
    int operator == (const SONtransferResponseContainer &) const;
    int operator != (const SONtransferResponseContainer &) const;

    cellLoadReporting *get_cellLoadReporting();
    const cellLoadReporting *get_cellLoadReporting() const;
    void set_cellLoadReporting(const cellLoadReporting &);

    multiCellLoadReporting *get_multiCellLoadReporting();
    const multiCellLoadReporting *get_multiCellLoadReporting() const;
    void set_multiCellLoadReporting(const multiCellLoadReporting &);

    eventTriggeredCellLoadReporting *get_eventTriggeredCellLoadReporting();
    const eventTriggeredCellLoadReporting *get_eventTriggeredCellLoadReporting() const;
    void set_eventTriggeredCellLoadReporting(const eventTriggeredCellLoadReporting &);

    hOReporting *get_hOReporting();
    const hOReporting *get_hOReporting() const;
    void set_hOReporting(hOReporting);

    eutranCellActivation *get_eutranCellActivation();
    const eutranCellActivation *get_eutranCellActivation() const;
    void set_eutranCellActivation(const eutranCellActivation &);

    energySavingsIndication *get_energySavingsIndication();
    const energySavingsIndication *get_energySavingsIndication() const;
    void set_energySavingsIndication(energySavingsIndication);

    failureEventReporting *get_failureEventReporting();
    const failureEventReporting *get_failureEventReporting() const;
    void set_failureEventReporting(failureEventReporting);
private:
    union {
	cellLoadReporting *cellLoadReporting_field;
	void *multiCellLoadReporting_field;
	eventTriggeredCellLoadReporting *eventTriggeredCellLoadReporting_field;
	hOReporting hOReporting_field;
	eutranCellActivation *eutranCellActivation_field;
	energySavingsIndication energySavingsIndication_field;
	failureEventReporting failureEventReporting_field;
    };
    void cleanup();
};

class OSS_PUBLIC SONtransferCause  : public OssChoice   /* CHOICE */
{
public:
    enum Id {
	unselected,
	cellLoadReporting_chosen = 1,
	multiCellLoadReporting_chosen = 2,
	eventTriggeredCellLoadReporting_chosen = 3,
	hOReporting_chosen = 4,
	eutranCellActivation_chosen = 5,
	energySavingsIndication_chosen = 6,
	failureEventReporting_chosen = 7
    };
    typedef enum CellLoadReportingCause cellLoadReporting;
    typedef enum CellLoadReportingCause multiCellLoadReporting;
    typedef enum CellLoadReportingCause eventTriggeredCellLoadReporting;
    typedef enum HOReportingCause hOReporting;
    typedef enum CellActivationCause eutranCellActivation;
    typedef enum CellStateIndicationCause energySavingsIndication;
    typedef enum FailureEventReportingCause failureEventReporting;

    SONtransferCause();
    SONtransferCause(const SONtransferCause &);

    SONtransferCause & operator = (const SONtransferCause &);
    int operator == (const SONtransferCause &) const;
    int operator != (const SONtransferCause &) const;

    cellLoadReporting *get_cellLoadReporting();
    const cellLoadReporting *get_cellLoadReporting() const;
    void set_cellLoadReporting(cellLoadReporting);

    multiCellLoadReporting *get_multiCellLoadReporting();
    const multiCellLoadReporting *get_multiCellLoadReporting() const;
    void set_multiCellLoadReporting(multiCellLoadReporting);

    eventTriggeredCellLoadReporting *get_eventTriggeredCellLoadReporting();
    const eventTriggeredCellLoadReporting *get_eventTriggeredCellLoadReporting() const;
    void set_eventTriggeredCellLoadReporting(eventTriggeredCellLoadReporting);

    hOReporting *get_hOReporting();
    const hOReporting *get_hOReporting() const;
    void set_hOReporting(hOReporting);

    eutranCellActivation *get_eutranCellActivation();
    const eutranCellActivation *get_eutranCellActivation() const;
    void set_eutranCellActivation(eutranCellActivation);

    energySavingsIndication *get_energySavingsIndication();
    const energySavingsIndication *get_energySavingsIndication() const;
    void set_energySavingsIndication(energySavingsIndication);

    failureEventReporting *get_failureEventReporting();
    const failureEventReporting *get_failureEventReporting() const;
    void set_failureEventReporting(failureEventReporting);
private:
    union {
	cellLoadReporting cellLoadReporting_field;
	multiCellLoadReporting multiCellLoadReporting_field;
	eventTriggeredCellLoadReporting eventTriggeredCellLoadReporting_field;
	hOReporting hOReporting_field;
	eutranCellActivation eutranCellActivation_field;
	energySavingsIndication energySavingsIndication_field;
	failureEventReporting failureEventReporting_field;
    };
};

typedef OssString CompositeAvailableCapacityGroup;

class OSS_PUBLIC EUTRANResponse   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OssString cell_ID;
    typedef EUTRANcellLoadReportingResponse eUTRANcellLoadReportingResponse;

    EUTRANResponse();
    EUTRANResponse(const EUTRANResponse &);
    EUTRANResponse(const cell_ID &, const eUTRANcellLoadReportingResponse &);

    EUTRANResponse & operator = (const EUTRANResponse &);
    int operator == (const EUTRANResponse &) const;
    int operator != (const EUTRANResponse &) const;

    cell_ID & get_cell_ID();
    const cell_ID & get_cell_ID() const;
    void set_cell_ID(const cell_ID &);

    eUTRANcellLoadReportingResponse & get_eUTRANcellLoadReportingResponse();
    const eUTRANcellLoadReportingResponse & get_eUTRANcellLoadReportingResponse() const;
    void set_eUTRANcellLoadReportingResponse(const eUTRANcellLoadReportingResponse &);
private:
    cell_ID cell_ID_field;
    eUTRANcellLoadReportingResponse eUTRANcellLoadReportingResponse_field;
};

typedef OssString EHRPD_Sector_ID;

class OSS_PUBLIC ReportingCellList_Item   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef IRAT_Cell_ID cell_ID;

    ReportingCellList_Item();
    ReportingCellList_Item(const ReportingCellList_Item &);
    ReportingCellList_Item(const cell_ID &);

    ReportingCellList_Item & operator = (const ReportingCellList_Item &);
    int operator == (const ReportingCellList_Item &) const;
    int operator != (const ReportingCellList_Item &) const;

    cell_ID & get_cell_ID();
    const cell_ID & get_cell_ID() const;
    void set_cell_ID(const cell_ID &);
private:
    cell_ID cell_ID_field;
};

class OSS_PUBLIC ReportingCellList : public OssList  /* SEQUENCE OF */
{
public:
    typedef ReportingCellList_Item component;

    ReportingCellList();
    ReportingCellList(const ReportingCellList &);
    ~ReportingCellList();

    ReportingCellList & operator = (const ReportingCellList &);
    int operator == (const ReportingCellList &) const;
    int operator != (const ReportingCellList &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(ReportingCellList *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, ReportingCellList *);

    int remove_front();
    int remove_after(OssIndex);

    ReportingCellList *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC EHRPDMultiSectorLoadReportingResponseItem   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OssString eHRPD_Sector_ID;
    typedef EHRPDSectorLoadReportingResponse eHRPDSectorLoadReportingResponse;

    EHRPDMultiSectorLoadReportingResponseItem();
    EHRPDMultiSectorLoadReportingResponseItem(const EHRPDMultiSectorLoadReportingResponseItem &);
    EHRPDMultiSectorLoadReportingResponseItem(const eHRPD_Sector_ID &, const eHRPDSectorLoadReportingResponse &);

    EHRPDMultiSectorLoadReportingResponseItem & operator = (const EHRPDMultiSectorLoadReportingResponseItem &);
    int operator == (const EHRPDMultiSectorLoadReportingResponseItem &) const;
    int operator != (const EHRPDMultiSectorLoadReportingResponseItem &) const;

    eHRPD_Sector_ID & get_eHRPD_Sector_ID();
    const eHRPD_Sector_ID & get_eHRPD_Sector_ID() const;
    void set_eHRPD_Sector_ID(const eHRPD_Sector_ID &);

    eHRPDSectorLoadReportingResponse & get_eHRPDSectorLoadReportingResponse();
    const eHRPDSectorLoadReportingResponse & get_eHRPDSectorLoadReportingResponse() const;
    void set_eHRPDSectorLoadReportingResponse(const eHRPDSectorLoadReportingResponse &);
private:
    eHRPD_Sector_ID eHRPD_Sector_ID_field;
    eHRPDSectorLoadReportingResponse eHRPDSectorLoadReportingResponse_field;
};

class OSS_PUBLIC MultiCellLoadReportingResponse_Item  : public OssChoice   /* CHOICE */
{
public:
    enum Id {
	unselected,
	eUTRANResponse_chosen = 1,
	uTRANResponse_chosen = 2,
	gERANResponse_chosen = 3,
	eHRPD_chosen = 4
    };
    typedef EUTRANResponse eUTRANResponse;
    typedef OssString uTRANResponse;
    typedef OssString gERANResponse;
    typedef EHRPDMultiSectorLoadReportingResponseItem eHRPD;

    MultiCellLoadReportingResponse_Item();
    MultiCellLoadReportingResponse_Item(const MultiCellLoadReportingResponse_Item &);
    ~MultiCellLoadReportingResponse_Item();

    MultiCellLoadReportingResponse_Item & operator = (const MultiCellLoadReportingResponse_Item &);
    int operator == (const MultiCellLoadReportingResponse_Item &) const;
    int operator != (const MultiCellLoadReportingResponse_Item &) const;

    eUTRANResponse *get_eUTRANResponse();
    const eUTRANResponse *get_eUTRANResponse() const;
    void set_eUTRANResponse(const eUTRANResponse &);

    uTRANResponse *get_uTRANResponse();
    const uTRANResponse *get_uTRANResponse() const;
    void set_uTRANResponse(const uTRANResponse &);

    gERANResponse *get_gERANResponse();
    const gERANResponse *get_gERANResponse() const;
    void set_gERANResponse(const gERANResponse &);

    eHRPD *get_eHRPD();
    const eHRPD *get_eHRPD() const;
    void set_eHRPD(const eHRPD &);
private:
    union {
	eUTRANResponse *eUTRANResponse_field;
	OSSC::COssString uTRANResponse_field;
	OSSC::COssString gERANResponse_field;
	eHRPD *eHRPD_field;
    };
    void cleanup();
};

class OSS_PUBLIC CandidatePCI   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 pCI;
    typedef OssString eARFCN;

    CandidatePCI();
    CandidatePCI(const CandidatePCI &);
    CandidatePCI(pCI, const eARFCN &);

    CandidatePCI & operator = (const CandidatePCI &);
    int operator == (const CandidatePCI &) const;
    int operator != (const CandidatePCI &) const;

    pCI & get_pCI();
    pCI get_pCI() const;
    void set_pCI(pCI);

    eARFCN & get_eARFCN();
    const eARFCN & get_eARFCN() const;
    void set_eARFCN(const eARFCN &);
private:
    pCI pCI_field;
    eARFCN eARFCN_field;
};

class OSS_PUBLIC __shared64   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OssString cell_ID;

    __shared64();
    __shared64(const __shared64 &);
    __shared64(const cell_ID &);

    __shared64 & operator = (const __shared64 &);
    int operator == (const __shared64 &) const;
    int operator != (const __shared64 &) const;

    cell_ID & get_cell_ID();
    const cell_ID & get_cell_ID() const;
    void set_cell_ID(const cell_ID &);
private:
    cell_ID cell_ID_field;
};

typedef __shared64 CellsToActivateList_Item;

typedef __shared64 ActivatedCellsList_Item;

class OSS_PUBLIC NotificationCellList_Item   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OssString cell_ID;
    typedef enum NotifyFlag notifyFlag;

    NotificationCellList_Item();
    NotificationCellList_Item(const NotificationCellList_Item &);
    NotificationCellList_Item(const cell_ID &, notifyFlag);

    NotificationCellList_Item & operator = (const NotificationCellList_Item &);
    int operator == (const NotificationCellList_Item &) const;
    int operator != (const NotificationCellList_Item &) const;

    cell_ID & get_cell_ID();
    const cell_ID & get_cell_ID() const;
    void set_cell_ID(const cell_ID &);

    notifyFlag & get_notifyFlag();
    notifyFlag get_notifyFlag() const;
    void set_notifyFlag(notifyFlag);
private:
    cell_ID cell_ID_field;
    notifyFlag notifyFlag_field;
};

typedef OssBitString SonTransfer_IEs_MobilityInformation;

typedef OSS_UINT32 EHRPDCapacityValue;

typedef OSS_INT32 EHRPDSectorCapacityClassValue;

/* Universal PDU class */

class OSS_PUBLIC s1ap_PDU : public UniversalPDU {
public:
    s1ap_PDU();
    void set_S1AP_PDU(S1AP_PDU &);
    S1AP_PDU *get_S1AP_PDU() const;
    void set_HandoverRequired(HandoverRequired &);
    HandoverRequired *get_HandoverRequired() const;
    void set_HandoverCommand(HandoverCommand &);
    HandoverCommand *get_HandoverCommand() const;
    void set_E_RABSubjecttoDataForwardingList(E_RABSubjecttoDataForwardingList &);
    E_RABSubjecttoDataForwardingList *get_E_RABSubjecttoDataForwardingList() const;
    void set_E_RABDataForwardingItem(E_RABDataForwardingItem &);
    E_RABDataForwardingItem *get_E_RABDataForwardingItem() const;
    void set_HandoverPreparationFailure(HandoverPreparationFailure &);
    HandoverPreparationFailure *get_HandoverPreparationFailure() const;
    void set_HandoverRequest(HandoverRequest &);
    HandoverRequest *get_HandoverRequest() const;
    void set_E_RABToBeSetupListHOReq(E_RABToBeSetupListHOReq &);
    E_RABToBeSetupListHOReq *get_E_RABToBeSetupListHOReq() const;
    void set_E_RABToBeSetupItemHOReq(E_RABToBeSetupItemHOReq &);
    E_RABToBeSetupItemHOReq *get_E_RABToBeSetupItemHOReq() const;
    void set_HandoverRequestAcknowledge(HandoverRequestAcknowledge &);
    HandoverRequestAcknowledge *get_HandoverRequestAcknowledge() const;
    void set_E_RABAdmittedList(E_RABAdmittedList &);
    E_RABAdmittedList *get_E_RABAdmittedList() const;
    void set_E_RABAdmittedItem(E_RABAdmittedItem &);
    E_RABAdmittedItem *get_E_RABAdmittedItem() const;
    void set_E_RABFailedtoSetupListHOReqAck(E_RABFailedtoSetupListHOReqAck &);
    E_RABFailedtoSetupListHOReqAck *get_E_RABFailedtoSetupListHOReqAck() const;
    void set_E_RABFailedToSetupItemHOReqAck(E_RABFailedToSetupItemHOReqAck &);
    E_RABFailedToSetupItemHOReqAck *get_E_RABFailedToSetupItemHOReqAck() const;
    void set_HandoverFailure(HandoverFailure &);
    HandoverFailure *get_HandoverFailure() const;
    void set_HandoverNotify(HandoverNotify &);
    HandoverNotify *get_HandoverNotify() const;
    void set_PathSwitchRequest(PathSwitchRequest &);
    PathSwitchRequest *get_PathSwitchRequest() const;
    void set_E_RABToBeSwitchedDLList(E_RABToBeSwitchedDLList &);
    E_RABToBeSwitchedDLList *get_E_RABToBeSwitchedDLList() const;
    void set_E_RABToBeSwitchedDLItem(E_RABToBeSwitchedDLItem &);
    E_RABToBeSwitchedDLItem *get_E_RABToBeSwitchedDLItem() const;
    void set_PathSwitchRequestAcknowledge(PathSwitchRequestAcknowledge &);
    PathSwitchRequestAcknowledge *get_PathSwitchRequestAcknowledge() const;
    void set_E_RABToBeSwitchedULList(E_RABToBeSwitchedULList &);
    E_RABToBeSwitchedULList *get_E_RABToBeSwitchedULList() const;
    void set_E_RABToBeSwitchedULItem(E_RABToBeSwitchedULItem &);
    E_RABToBeSwitchedULItem *get_E_RABToBeSwitchedULItem() const;
    void set_PathSwitchRequestFailure(PathSwitchRequestFailure &);
    PathSwitchRequestFailure *get_PathSwitchRequestFailure() const;
    void set_HandoverCancel(HandoverCancel &);
    HandoverCancel *get_HandoverCancel() const;
    void set_HandoverCancelAcknowledge(HandoverCancelAcknowledge &);
    HandoverCancelAcknowledge *get_HandoverCancelAcknowledge() const;
    void set_E_RABSetupRequest(E_RABSetupRequest &);
    E_RABSetupRequest *get_E_RABSetupRequest() const;
    void set_E_RABToBeSetupListBearerSUReq(E_RABToBeSetupListBearerSUReq &);
    E_RABToBeSetupListBearerSUReq *get_E_RABToBeSetupListBearerSUReq() const;
    void set_E_RABToBeSetupItemBearerSUReq(E_RABToBeSetupItemBearerSUReq &);
    E_RABToBeSetupItemBearerSUReq *get_E_RABToBeSetupItemBearerSUReq() const;
    void set_E_RABSetupResponse(E_RABSetupResponse &);
    E_RABSetupResponse *get_E_RABSetupResponse() const;
    void set_E_RABSetupListBearerSURes(E_RABSetupListBearerSURes &);
    E_RABSetupListBearerSURes *get_E_RABSetupListBearerSURes() const;
    void set_E_RABSetupItemBearerSURes(E_RABSetupItemBearerSURes &);
    E_RABSetupItemBearerSURes *get_E_RABSetupItemBearerSURes() const;
    void set_E_RABModifyRequest(E_RABModifyRequest &);
    E_RABModifyRequest *get_E_RABModifyRequest() const;
    void set_E_RABToBeModifiedListBearerModReq(E_RABToBeModifiedListBearerModReq &);
    E_RABToBeModifiedListBearerModReq *get_E_RABToBeModifiedListBearerModReq() const;
    void set_E_RABToBeModifiedItemBearerModReq(E_RABToBeModifiedItemBearerModReq &);
    E_RABToBeModifiedItemBearerModReq *get_E_RABToBeModifiedItemBearerModReq() const;
    void set_E_RABModifyResponse(E_RABModifyResponse &);
    E_RABModifyResponse *get_E_RABModifyResponse() const;
    void set_E_RABModifyListBearerModRes(E_RABModifyListBearerModRes &);
    E_RABModifyListBearerModRes *get_E_RABModifyListBearerModRes() const;
    void set_E_RABModifyItemBearerModRes(E_RABModifyItemBearerModRes &);
    E_RABModifyItemBearerModRes *get_E_RABModifyItemBearerModRes() const;
    void set_E_RABReleaseCommand(E_RABReleaseCommand &);
    E_RABReleaseCommand *get_E_RABReleaseCommand() const;
    void set_E_RABReleaseResponse(E_RABReleaseResponse &);
    E_RABReleaseResponse *get_E_RABReleaseResponse() const;
    void set_E_RABReleaseListBearerRelComp(E_RABReleaseListBearerRelComp &);
    E_RABReleaseListBearerRelComp *get_E_RABReleaseListBearerRelComp() const;
    void set_E_RABReleaseItemBearerRelComp(E_RABReleaseItemBearerRelComp &);
    E_RABReleaseItemBearerRelComp *get_E_RABReleaseItemBearerRelComp() const;
    void set_E_RABReleaseIndication(E_RABReleaseIndication &);
    E_RABReleaseIndication *get_E_RABReleaseIndication() const;
    void set_InitialContextSetupRequest(InitialContextSetupRequest &);
    InitialContextSetupRequest *get_InitialContextSetupRequest() const;
    void set_E_RABToBeSetupListCtxtSUReq(E_RABToBeSetupListCtxtSUReq &);
    E_RABToBeSetupListCtxtSUReq *get_E_RABToBeSetupListCtxtSUReq() const;
    void set_E_RABToBeSetupItemCtxtSUReq(E_RABToBeSetupItemCtxtSUReq &);
    E_RABToBeSetupItemCtxtSUReq *get_E_RABToBeSetupItemCtxtSUReq() const;
    void set_InitialContextSetupResponse(InitialContextSetupResponse &);
    InitialContextSetupResponse *get_InitialContextSetupResponse() const;
    void set_E_RABSetupListCtxtSURes(E_RABSetupListCtxtSURes &);
    E_RABSetupListCtxtSURes *get_E_RABSetupListCtxtSURes() const;
    void set_E_RABSetupItemCtxtSURes(E_RABSetupItemCtxtSURes &);
    E_RABSetupItemCtxtSURes *get_E_RABSetupItemCtxtSURes() const;
    void set_InitialContextSetupFailure(InitialContextSetupFailure &);
    InitialContextSetupFailure *get_InitialContextSetupFailure() const;
    void set_Paging(Paging &);
    Paging *get_Paging() const;
    void set_TAIList(TAIList &);
    TAIList *get_TAIList() const;
    void set_TAIItem(TAIItem &);
    TAIItem *get_TAIItem() const;
    void set_UEContextReleaseRequest(UEContextReleaseRequest &);
    UEContextReleaseRequest *get_UEContextReleaseRequest() const;
    void set_UEContextReleaseCommand(UEContextReleaseCommand &);
    UEContextReleaseCommand *get_UEContextReleaseCommand() const;
    void set_UEContextReleaseComplete(UEContextReleaseComplete &);
    UEContextReleaseComplete *get_UEContextReleaseComplete() const;
    void set_UEContextModificationRequest(UEContextModificationRequest &);
    UEContextModificationRequest *get_UEContextModificationRequest() const;
    void set_UEContextModificationResponse(UEContextModificationResponse &);
    UEContextModificationResponse *get_UEContextModificationResponse() const;
    void set_UEContextModificationFailure(UEContextModificationFailure &);
    UEContextModificationFailure *get_UEContextModificationFailure() const;
    void set_UERadioCapabilityMatchRequest(UERadioCapabilityMatchRequest &);
    UERadioCapabilityMatchRequest *get_UERadioCapabilityMatchRequest() const;
    void set_UERadioCapabilityMatchResponse(UERadioCapabilityMatchResponse &);
    UERadioCapabilityMatchResponse *get_UERadioCapabilityMatchResponse() const;
    void set_DownlinkNASTransport(DownlinkNASTransport &);
    DownlinkNASTransport *get_DownlinkNASTransport() const;
    void set_InitialUEMessage(InitialUEMessage &);
    InitialUEMessage *get_InitialUEMessage() const;
    void set_UplinkNASTransport(UplinkNASTransport &);
    UplinkNASTransport *get_UplinkNASTransport() const;
    void set_NASNonDeliveryIndication(NASNonDeliveryIndication &);
    NASNonDeliveryIndication *get_NASNonDeliveryIndication() const;
    void set_RerouteNASRequest(RerouteNASRequest &);
    RerouteNASRequest *get_RerouteNASRequest() const;
    void set_Reset(Reset &);
    Reset *get_Reset() const;
    void set_ResetType(ResetType &);
    ResetType *get_ResetType() const;
    void set_ResetAcknowledge(ResetAcknowledge &);
    ResetAcknowledge *get_ResetAcknowledge() const;
    void set_UE_associatedLogicalS1_ConnectionListResAck(UE_associatedLogicalS1_ConnectionListResAck &);
    UE_associatedLogicalS1_ConnectionListResAck *get_UE_associatedLogicalS1_ConnectionListResAck() const;
    void set_ErrorIndication(ErrorIndication &);
    ErrorIndication *get_ErrorIndication() const;
    void set_S1SetupRequest(S1SetupRequest &);
    S1SetupRequest *get_S1SetupRequest() const;
    void set_S1SetupResponse(S1SetupResponse &);
    S1SetupResponse *get_S1SetupResponse() const;
    void set_S1SetupFailure(S1SetupFailure &);
    S1SetupFailure *get_S1SetupFailure() const;
    void set_ENBConfigurationUpdate(ENBConfigurationUpdate &);
    ENBConfigurationUpdate *get_ENBConfigurationUpdate() const;
    void set_ENBConfigurationUpdateAcknowledge(ENBConfigurationUpdateAcknowledge &);
    ENBConfigurationUpdateAcknowledge *get_ENBConfigurationUpdateAcknowledge() const;
    void set_ENBConfigurationUpdateFailure(ENBConfigurationUpdateFailure &);
    ENBConfigurationUpdateFailure *get_ENBConfigurationUpdateFailure() const;
    void set_MMEConfigurationUpdate(MMEConfigurationUpdate &);
    MMEConfigurationUpdate *get_MMEConfigurationUpdate() const;
    void set_MMEConfigurationUpdateAcknowledge(MMEConfigurationUpdateAcknowledge &);
    MMEConfigurationUpdateAcknowledge *get_MMEConfigurationUpdateAcknowledge() const;
    void set_MMEConfigurationUpdateFailure(MMEConfigurationUpdateFailure &);
    MMEConfigurationUpdateFailure *get_MMEConfigurationUpdateFailure() const;
    void set_DownlinkS1cdma2000tunnelling(DownlinkS1cdma2000tunnelling &);
    DownlinkS1cdma2000tunnelling *get_DownlinkS1cdma2000tunnelling() const;
    void set_UplinkS1cdma2000tunnelling(UplinkS1cdma2000tunnelling &);
    UplinkS1cdma2000tunnelling *get_UplinkS1cdma2000tunnelling() const;
    void set_UECapabilityInfoIndication(UECapabilityInfoIndication &);
    UECapabilityInfoIndication *get_UECapabilityInfoIndication() const;
    void set_ENBStatusTransfer(ENBStatusTransfer &);
    ENBStatusTransfer *get_ENBStatusTransfer() const;
    void set_MMEStatusTransfer(MMEStatusTransfer &);
    MMEStatusTransfer *get_MMEStatusTransfer() const;
    void set_TraceStart(TraceStart &);
    TraceStart *get_TraceStart() const;
    void set_TraceFailureIndication(TraceFailureIndication &);
    TraceFailureIndication *get_TraceFailureIndication() const;
    void set_DeactivateTrace(DeactivateTrace &);
    DeactivateTrace *get_DeactivateTrace() const;
    void set_CellTrafficTrace(CellTrafficTrace &);
    CellTrafficTrace *get_CellTrafficTrace() const;
    void set_LocationReportingControl(LocationReportingControl &);
    LocationReportingControl *get_LocationReportingControl() const;
    void set_LocationReportingFailureIndication(LocationReportingFailureIndication &);
    LocationReportingFailureIndication *get_LocationReportingFailureIndication() const;
    void set_LocationReport(LocationReport &);
    LocationReport *get_LocationReport() const;
    void set_OverloadStart(OverloadStart &);
    OverloadStart *get_OverloadStart() const;
    void set_OverloadStop(OverloadStop &);
    OverloadStop *get_OverloadStop() const;
    void set_WriteReplaceWarningRequest(WriteReplaceWarningRequest &);
    WriteReplaceWarningRequest *get_WriteReplaceWarningRequest() const;
    void set_WriteReplaceWarningResponse(WriteReplaceWarningResponse &);
    WriteReplaceWarningResponse *get_WriteReplaceWarningResponse() const;
    void set_ENBDirectInformationTransfer(ENBDirectInformationTransfer &);
    ENBDirectInformationTransfer *get_ENBDirectInformationTransfer() const;
    void set_Inter_SystemInformationTransferType(Inter_SystemInformationTransferType &);
    Inter_SystemInformationTransferType *get_Inter_SystemInformationTransferType() const;
    void set_MMEDirectInformationTransfer(MMEDirectInformationTransfer &);
    MMEDirectInformationTransfer *get_MMEDirectInformationTransfer() const;
    void set_ENBConfigurationTransfer(ENBConfigurationTransfer &);
    ENBConfigurationTransfer *get_ENBConfigurationTransfer() const;
    void set_MMEConfigurationTransfer(MMEConfigurationTransfer &);
    MMEConfigurationTransfer *get_MMEConfigurationTransfer() const;
    void set_PrivateMessage(PrivateMessage &);
    PrivateMessage *get_PrivateMessage() const;
    void set_KillRequest(KillRequest &);
    KillRequest *get_KillRequest() const;
    void set_KillResponse(KillResponse &);
    KillResponse *get_KillResponse() const;
    void set_PWSRestartIndication(PWSRestartIndication &);
    PWSRestartIndication *get_PWSRestartIndication() const;
    void set_PWSFailureIndication(PWSFailureIndication &);
    PWSFailureIndication *get_PWSFailureIndication() const;
    void set_DownlinkUEAssociatedLPPaTransport(DownlinkUEAssociatedLPPaTransport &);
    DownlinkUEAssociatedLPPaTransport *get_DownlinkUEAssociatedLPPaTransport() const;
    void set_UplinkUEAssociatedLPPaTransport(UplinkUEAssociatedLPPaTransport &);
    UplinkUEAssociatedLPPaTransport *get_UplinkUEAssociatedLPPaTransport() const;
    void set_DownlinkNonUEAssociatedLPPaTransport(DownlinkNonUEAssociatedLPPaTransport &);
    DownlinkNonUEAssociatedLPPaTransport *get_DownlinkNonUEAssociatedLPPaTransport() const;
    void set_UplinkNonUEAssociatedLPPaTransport(UplinkNonUEAssociatedLPPaTransport &);
    UplinkNonUEAssociatedLPPaTransport *get_UplinkNonUEAssociatedLPPaTransport() const;
    void set_E_RABModificationIndication(E_RABModificationIndication &);
    E_RABModificationIndication *get_E_RABModificationIndication() const;
    void set_E_RABToBeModifiedListBearerModInd(E_RABToBeModifiedListBearerModInd &);
    E_RABToBeModifiedListBearerModInd *get_E_RABToBeModifiedListBearerModInd() const;
    void set_E_RABToBeModifiedItemBearerModInd(E_RABToBeModifiedItemBearerModInd &);
    E_RABToBeModifiedItemBearerModInd *get_E_RABToBeModifiedItemBearerModInd() const;
    void set_E_RABNotToBeModifiedListBearerModInd(E_RABNotToBeModifiedListBearerModInd &);
    E_RABNotToBeModifiedListBearerModInd *get_E_RABNotToBeModifiedListBearerModInd() const;
    void set_E_RABNotToBeModifiedItemBearerModInd(E_RABNotToBeModifiedItemBearerModInd &);
    E_RABNotToBeModifiedItemBearerModInd *get_E_RABNotToBeModifiedItemBearerModInd() const;
    void set_CSGMembershipInfo(CSGMembershipInfo &);
    CSGMembershipInfo *get_CSGMembershipInfo() const;
    void set_E_RABModificationConfirm(E_RABModificationConfirm &);
    E_RABModificationConfirm *get_E_RABModificationConfirm() const;
    void set_E_RABModifyListBearerModConf(E_RABModifyListBearerModConf &);
    E_RABModifyListBearerModConf *get_E_RABModifyListBearerModConf() const;
    void set_E_RABModifyItemBearerModConf(E_RABModifyItemBearerModConf &);
    E_RABModifyItemBearerModConf *get_E_RABModifyItemBearerModConf() const;
    void set_UEContextModificationIndication(UEContextModificationIndication &);
    UEContextModificationIndication *get_UEContextModificationIndication() const;
    void set_UEContextModificationConfirm(UEContextModificationConfirm &);
    UEContextModificationConfirm *get_UEContextModificationConfirm() const;
    void set_UEContextSuspendRequest(UEContextSuspendRequest &);
    UEContextSuspendRequest *get_UEContextSuspendRequest() const;
    void set_UEContextSuspendResponse(UEContextSuspendResponse &);
    UEContextSuspendResponse *get_UEContextSuspendResponse() const;
    void set_UEContextResumeRequest(UEContextResumeRequest &);
    UEContextResumeRequest *get_UEContextResumeRequest() const;
    void set_E_RABFailedToResumeListResumeReq(E_RABFailedToResumeListResumeReq &);
    E_RABFailedToResumeListResumeReq *get_E_RABFailedToResumeListResumeReq() const;
    void set_E_RABFailedToResumeItemResumeReq(E_RABFailedToResumeItemResumeReq &);
    E_RABFailedToResumeItemResumeReq *get_E_RABFailedToResumeItemResumeReq() const;
    void set_UEContextResumeResponse(UEContextResumeResponse &);
    UEContextResumeResponse *get_UEContextResumeResponse() const;
    void set_E_RABFailedToResumeListResumeRes(E_RABFailedToResumeListResumeRes &);
    E_RABFailedToResumeListResumeRes *get_E_RABFailedToResumeListResumeRes() const;
    void set_E_RABFailedToResumeItemResumeRes(E_RABFailedToResumeItemResumeRes &);
    E_RABFailedToResumeItemResumeRes *get_E_RABFailedToResumeItemResumeRes() const;
    void set_UEContextResumeFailure(UEContextResumeFailure &);
    UEContextResumeFailure *get_UEContextResumeFailure() const;
    void set_ConnectionEstablishmentIndication(ConnectionEstablishmentIndication &);
    ConnectionEstablishmentIndication *get_ConnectionEstablishmentIndication() const;
    void set_Additional_GUTI(Additional_GUTI &);
    Additional_GUTI *get_Additional_GUTI() const;
    void set_AssistanceDataForPaging(AssistanceDataForPaging &);
    AssistanceDataForPaging *get_AssistanceDataForPaging() const;
    void set_Bearers_SubjectToStatusTransfer_Item(Bearers_SubjectToStatusTransfer_Item &);
    Bearers_SubjectToStatusTransfer_Item *get_Bearers_SubjectToStatusTransfer_Item() const;
    void set_BearerType(BearerType &);
    BearerType *get_BearerType() const;
    void set_BroadcastCancelledAreaList(BroadcastCancelledAreaList &);
    BroadcastCancelledAreaList *get_BroadcastCancelledAreaList() const;
    void set_BroadcastCompletedAreaList(BroadcastCompletedAreaList &);
    BroadcastCompletedAreaList *get_BroadcastCompletedAreaList() const;
    void set_Cause(Cause &);
    Cause *get_Cause() const;
    void set_CellAccessMode(CellAccessMode &);
    CellAccessMode *get_CellAccessMode() const;
    void set_CellIdentifierAndCELevelForCECapableUEs(CellIdentifierAndCELevelForCECapableUEs &);
    CellIdentifierAndCELevelForCECapableUEs *get_CellIdentifierAndCELevelForCECapableUEs() const;
    void set_CE_mode_B_SupportIndicator(CE_mode_B_SupportIndicator &);
    CE_mode_B_SupportIndicator *get_CE_mode_B_SupportIndicator() const;
    void set_Cdma2000PDU(Cdma2000PDU &);
    Cdma2000PDU *get_Cdma2000PDU() const;
    void set_Cdma2000RATType(Cdma2000RATType &);
    Cdma2000RATType *get_Cdma2000RATType() const;
    void set_Cdma2000SectorID(Cdma2000SectorID &);
    Cdma2000SectorID *get_Cdma2000SectorID() const;
    void set_Cdma2000HOStatus(Cdma2000HOStatus &);
    Cdma2000HOStatus *get_Cdma2000HOStatus() const;
    void set_Cdma2000HORequiredIndication(Cdma2000HORequiredIndication &);
    Cdma2000HORequiredIndication *get_Cdma2000HORequiredIndication() const;
    void set_Cdma2000OneXSRVCCInfo(Cdma2000OneXSRVCCInfo &);
    Cdma2000OneXSRVCCInfo *get_Cdma2000OneXSRVCCInfo() const;
    void set_Cdma2000OneXRAND(Cdma2000OneXRAND &);
    Cdma2000OneXRAND *get_Cdma2000OneXRAND() const;
    void set_CNDomain(CNDomain &);
    CNDomain *get_CNDomain() const;
    void set_ConcurrentWarningMessageIndicator(ConcurrentWarningMessageIndicator &);
    ConcurrentWarningMessageIndicator *get_ConcurrentWarningMessageIndicator() const;
    void set_Correlation_ID(Correlation_ID &);
    Correlation_ID *get_Correlation_ID() const;
    void set_CSFallbackIndicator(CSFallbackIndicator &);
    CSFallbackIndicator *get_CSFallbackIndicator() const;
    void set_AdditionalCSFallbackIndicator(AdditionalCSFallbackIndicator &);
    AdditionalCSFallbackIndicator *get_AdditionalCSFallbackIndicator() const;
    void set_CSG_Id(CSG_Id &);
    CSG_Id *get_CSG_Id() const;
    void set_CSG_IdList(CSG_IdList &);
    CSG_IdList *get_CSG_IdList() const;
    void set_CSGMembershipStatus(CSGMembershipStatus &);
    CSGMembershipStatus *get_CSGMembershipStatus() const;
    void set_COUNTValueExtended(COUNTValueExtended &);
    COUNTValueExtended *get_COUNTValueExtended() const;
    void set_COUNTvaluePDCP_SNlength18(COUNTvaluePDCP_SNlength18 &);
    COUNTvaluePDCP_SNlength18 *get_COUNTvaluePDCP_SNlength18() const;
    void set_CriticalityDiagnostics(CriticalityDiagnostics &);
    CriticalityDiagnostics *get_CriticalityDiagnostics() const;
    void set_DataCodingScheme(DataCodingScheme &);
    DataCodingScheme *get_DataCodingScheme() const;
    void set_Direct_Forwarding_Path_Availability(Direct_Forwarding_Path_Availability &);
    Direct_Forwarding_Path_Availability *get_Direct_Forwarding_Path_Availability() const;
    void set_Data_Forwarding_Not_Possible(Data_Forwarding_Not_Possible &);
    Data_Forwarding_Not_Possible *get_Data_Forwarding_Not_Possible() const;
    void set_PWSfailedECGIList(PWSfailedECGIList &);
    PWSfailedECGIList *get_PWSfailedECGIList() const;
    void set_EmergencyAreaIDListForRestart(EmergencyAreaIDListForRestart &);
    EmergencyAreaIDListForRestart *get_EmergencyAreaIDListForRestart() const;
    void set_Global_ENB_ID(Global_ENB_ID &);
    Global_ENB_ID *get_Global_ENB_ID() const;
    void set_GUMMEIList(GUMMEIList &);
    GUMMEIList *get_GUMMEIList() const;
    void set_ENB_StatusTransfer_TransparentContainer(ENB_StatusTransfer_TransparentContainer &);
    ENB_StatusTransfer_TransparentContainer *get_ENB_StatusTransfer_TransparentContainer() const;
    void set_ENB_UE_S1AP_ID(ENB_UE_S1AP_ID &);
    ENB_UE_S1AP_ID *get_ENB_UE_S1AP_ID() const;
    void set_ENBname(ENBname &);
    ENBname *get_ENBname() const;
    void set_E_RABInformationListItem(E_RABInformationListItem &);
    E_RABInformationListItem *get_E_RABInformationListItem() const;
    void set_E_RABList(E_RABList &);
    E_RABList *get_E_RABList() const;
    void set_E_RABItem(E_RABItem &);
    E_RABItem *get_E_RABItem() const;
    void set_EUTRAN_CGI(EUTRAN_CGI &);
    EUTRAN_CGI *get_EUTRAN_CGI() const;
    void set_EUTRANRoundTripDelayEstimationInfo(EUTRANRoundTripDelayEstimationInfo &);
    EUTRANRoundTripDelayEstimationInfo *get_EUTRANRoundTripDelayEstimationInfo() const;
    void set_ExpectedUEBehaviour(ExpectedUEBehaviour &);
    ExpectedUEBehaviour *get_ExpectedUEBehaviour() const;
    void set_ExtendedRepetitionPeriod(ExtendedRepetitionPeriod &);
    ExtendedRepetitionPeriod *get_ExtendedRepetitionPeriod() const;
    void set_Extended_UEIdentityIndexValue(Extended_UEIdentityIndexValue &);
    Extended_UEIdentityIndexValue *get_Extended_UEIdentityIndexValue() const;
    void set_GUMMEI(GUMMEI &);
    GUMMEI *get_GUMMEI() const;
    void set_GUMMEIType(GUMMEIType &);
    GUMMEIType *get_GUMMEIType() const;
    void set_GWContextReleaseIndication(GWContextReleaseIndication &);
    GWContextReleaseIndication *get_GWContextReleaseIndication() const;
    void set_HandoverRestrictionList(HandoverRestrictionList &);
    HandoverRestrictionList *get_HandoverRestrictionList() const;
    void set_HandoverType(HandoverType &);
    HandoverType *get_HandoverType() const;
    void set_Masked_IMEISV(Masked_IMEISV &);
    Masked_IMEISV *get_Masked_IMEISV() const;
    void set_InformationOnRecommendedCellsAndENBsForPaging(InformationOnRecommendedCellsAndENBsForPaging &);
    InformationOnRecommendedCellsAndENBsForPaging *get_InformationOnRecommendedCellsAndENBsForPaging() const;
    void set_KillAllWarningMessages(KillAllWarningMessages &);
    KillAllWarningMessages *get_KillAllWarningMessages() const;
    void set_LAI(LAI &);
    LAI *get_LAI() const;
    void set_L3_Information(L3_Information &);
    L3_Information *get_L3_Information() const;
    void set_LPPa_PDU(LPPa_PDU &);
    LPPa_PDU *get_LPPa_PDU() const;
    void set_LHN_ID(LHN_ID &);
    LHN_ID *get_LHN_ID() const;
    void set_LoggedMBSFNMDT(LoggedMBSFNMDT &);
    LoggedMBSFNMDT *get_LoggedMBSFNMDT() const;
    void set_M3Configuration(M3Configuration &);
    M3Configuration *get_M3Configuration() const;
    void set_M4Configuration(M4Configuration &);
    M4Configuration *get_M4Configuration() const;
    void set_M5Configuration(M5Configuration &);
    M5Configuration *get_M5Configuration() const;
    void set_M6Configuration(M6Configuration &);
    M6Configuration *get_M6Configuration() const;
    void set_M7Configuration(M7Configuration &);
    M7Configuration *get_M7Configuration() const;
    void set_MDT_Location_Info(MDT_Location_Info &);
    MDT_Location_Info *get_MDT_Location_Info() const;
    void set_MDT_Configuration(MDT_Configuration &);
    MDT_Configuration *get_MDT_Configuration() const;
    void set_ManagementBasedMDTAllowed(ManagementBasedMDTAllowed &);
    ManagementBasedMDTAllowed *get_ManagementBasedMDTAllowed() const;
    void set_MDTPLMNList(MDTPLMNList &);
    MDTPLMNList *get_MDTPLMNList() const;
    void set_PrivacyIndicator(PrivacyIndicator &);
    PrivacyIndicator *get_PrivacyIndicator() const;
    void set_MessageIdentifier(MessageIdentifier &);
    MessageIdentifier *get_MessageIdentifier() const;
    void set_S1AP_IEs_MobilityInformation(S1AP_IEs_MobilityInformation &);
    S1AP_IEs_MobilityInformation *get_S1AP_IEs_MobilityInformation() const;
    void set_MMEname(MMEname &);
    MMEname *get_MMEname() const;
    void set_MMERelaySupportIndicator(MMERelaySupportIndicator &);
    MMERelaySupportIndicator *get_MMERelaySupportIndicator() const;
    void set_MME_Group_ID(MME_Group_ID &);
    MME_Group_ID *get_MME_Group_ID() const;
    void set_MME_UE_S1AP_ID(MME_UE_S1AP_ID &);
    MME_UE_S1AP_ID *get_MME_UE_S1AP_ID() const;
    void set_MSClassmark2(MSClassmark2 &);
    MSClassmark2 *get_MSClassmark2() const;
    void set_MSClassmark3(MSClassmark3 &);
    MSClassmark3 *get_MSClassmark3() const;
    void set_MutingAvailabilityIndication(MutingAvailabilityIndication &);
    MutingAvailabilityIndication *get_MutingAvailabilityIndication() const;
    void set_MutingPatternInformation(MutingPatternInformation &);
    MutingPatternInformation *get_MutingPatternInformation() const;
    void set_NAS_PDU(NAS_PDU &);
    NAS_PDU *get_NAS_PDU() const;
    void set_NASSecurityParametersfromE_UTRAN(NASSecurityParametersfromE_UTRAN &);
    NASSecurityParametersfromE_UTRAN *get_NASSecurityParametersfromE_UTRAN() const;
    void set_NASSecurityParameterstoE_UTRAN(NASSecurityParameterstoE_UTRAN &);
    NASSecurityParameterstoE_UTRAN *get_NASSecurityParameterstoE_UTRAN() const;
    void set_NB_IoT_DefaultPagingDRX(NB_IoT_DefaultPagingDRX &);
    NB_IoT_DefaultPagingDRX *get_NB_IoT_DefaultPagingDRX() const;
    void set_NB_IoT_Paging_eDRXInformation(NB_IoT_Paging_eDRXInformation &);
    NB_IoT_Paging_eDRXInformation *get_NB_IoT_Paging_eDRXInformation() const;
    void set_NB_IoT_UEIdentityIndexValue(NB_IoT_UEIdentityIndexValue &);
    NB_IoT_UEIdentityIndexValue *get_NB_IoT_UEIdentityIndexValue() const;
    void set_NumberofBroadcastRequest(NumberofBroadcastRequest &);
    NumberofBroadcastRequest *get_NumberofBroadcastRequest() const;
    void set_OldBSS_ToNewBSS_Information(OldBSS_ToNewBSS_Information &);
    OldBSS_ToNewBSS_Information *get_OldBSS_ToNewBSS_Information() const;
    void set_OverloadResponse(OverloadResponse &);
    OverloadResponse *get_OverloadResponse() const;
    void set_Paging_eDRXInformation(Paging_eDRXInformation &);
    Paging_eDRXInformation *get_Paging_eDRXInformation() const;
    void set_PagingDRX(PagingDRX &);
    PagingDRX *get_PagingDRX() const;
    void set_PagingPriority(PagingPriority &);
    PagingPriority *get_PagingPriority() const;
    void set_ProSeAuthorized(ProSeAuthorized &);
    ProSeAuthorized *get_ProSeAuthorized() const;
    void set_ProSeUEtoNetworkRelaying(ProSeUEtoNetworkRelaying &);
    ProSeUEtoNetworkRelaying *get_ProSeUEtoNetworkRelaying() const;
    void set_PS_ServiceNotAvailable(PS_ServiceNotAvailable &);
    PS_ServiceNotAvailable *get_PS_ServiceNotAvailable() const;
    void set_ReceiveStatusOfULPDCPSDUsExtended(ReceiveStatusOfULPDCPSDUsExtended &);
    ReceiveStatusOfULPDCPSDUsExtended *get_ReceiveStatusOfULPDCPSDUsExtended() const;
    void set_ReceiveStatusOfULPDCPSDUsPDCP_SNlength18(ReceiveStatusOfULPDCPSDUsPDCP_SNlength18 &);
    ReceiveStatusOfULPDCPSDUsPDCP_SNlength18 *get_ReceiveStatusOfULPDCPSDUsPDCP_SNlength18() const;
    void set_RecommendedCellItem(RecommendedCellItem &);
    RecommendedCellItem *get_RecommendedCellItem() const;
    void set_RecommendedENBItem(RecommendedENBItem &);
    RecommendedENBItem *get_RecommendedENBItem() const;
    void set_RelativeMMECapacity(RelativeMMECapacity &);
    RelativeMMECapacity *get_RelativeMMECapacity() const;
    void set_RelayNode_Indicator(RelayNode_Indicator &);
    RelayNode_Indicator *get_RelayNode_Indicator() const;
    void set_RAT_Type(RAT_Type &);
    RAT_Type *get_RAT_Type() const;
    void set_RequestType(RequestType &);
    RequestType *get_RequestType() const;
    void set_RepetitionPeriod(RepetitionPeriod &);
    RepetitionPeriod *get_RepetitionPeriod() const;
    void set_RRC_Establishment_Cause(RRC_Establishment_Cause &);
    RRC_Establishment_Cause *get_RRC_Establishment_Cause() const;
    void set_ECGIListForRestart(ECGIListForRestart &);
    ECGIListForRestart *get_ECGIListForRestart() const;
    void set_Routing_ID(Routing_ID &);
    Routing_ID *get_Routing_ID() const;
    void set_SecurityKey(SecurityKey &);
    SecurityKey *get_SecurityKey() const;
    void set_SecurityContext(SecurityContext &);
    SecurityContext *get_SecurityContext() const;
    void set_SerialNumber(SerialNumber &);
    SerialNumber *get_SerialNumber() const;
    void set_SONInformationReport(SONInformationReport &);
    SONInformationReport *get_SONInformationReport() const;
    void set_SONConfigurationTransfer(SONConfigurationTransfer &);
    SONConfigurationTransfer *get_SONConfigurationTransfer() const;
    void set_SynchronisationInformation(SynchronisationInformation &);
    SynchronisationInformation *get_SynchronisationInformation() const;
    void set_Source_ToTarget_TransparentContainer(Source_ToTarget_TransparentContainer &);
    Source_ToTarget_TransparentContainer *get_Source_ToTarget_TransparentContainer() const;
    void set_SourceBSS_ToTargetBSS_TransparentContainer(SourceBSS_ToTargetBSS_TransparentContainer &);
    SourceBSS_ToTargetBSS_TransparentContainer *get_SourceBSS_ToTargetBSS_TransparentContainer() const;
    void set_SRVCCOperationNotPossible(SRVCCOperationNotPossible &);
    SRVCCOperationNotPossible *get_SRVCCOperationNotPossible() const;
    void set_SRVCCOperationPossible(SRVCCOperationPossible &);
    SRVCCOperationPossible *get_SRVCCOperationPossible() const;
    void set_SRVCCHOIndication(SRVCCHOIndication &);
    SRVCCHOIndication *get_SRVCCHOIndication() const;
    void set_SourceeNB_ToTargeteNB_TransparentContainer(SourceeNB_ToTargeteNB_TransparentContainer &);
    SourceeNB_ToTargeteNB_TransparentContainer *get_SourceeNB_ToTargeteNB_TransparentContainer() const;
    void set_SourceRNC_ToTargetRNC_TransparentContainer(SourceRNC_ToTargetRNC_TransparentContainer &);
    SourceRNC_ToTargetRNC_TransparentContainer *get_SourceRNC_ToTargetRNC_TransparentContainer() const;
    void set_ServedGUMMEIs(ServedGUMMEIs &);
    ServedGUMMEIs *get_ServedGUMMEIs() const;
    void set_SubscriberProfileIDforRFP(SubscriberProfileIDforRFP &);
    SubscriberProfileIDforRFP *get_SubscriberProfileIDforRFP() const;
    void set_SupportedTAs(SupportedTAs &);
    SupportedTAs *get_SupportedTAs() const;
    void set_TimeSynchronisationInfo(TimeSynchronisationInfo &);
    TimeSynchronisationInfo *get_TimeSynchronisationInfo() const;
    void set_S_TMSI(S_TMSI &);
    S_TMSI *get_S_TMSI() const;
    void set_TAI(TAI &);
    TAI *get_TAI() const;
    void set_TargetID(TargetID &);
    TargetID *get_TargetID() const;
    void set_TargeteNB_ToSourceeNB_TransparentContainer(TargeteNB_ToSourceeNB_TransparentContainer &);
    TargeteNB_ToSourceeNB_TransparentContainer *get_TargeteNB_ToSourceeNB_TransparentContainer() const;
    void set_Target_ToSource_TransparentContainer(Target_ToSource_TransparentContainer &);
    Target_ToSource_TransparentContainer *get_Target_ToSource_TransparentContainer() const;
    void set_TargetRNC_ToSourceRNC_TransparentContainer(TargetRNC_ToSourceRNC_TransparentContainer &);
    TargetRNC_ToSourceRNC_TransparentContainer *get_TargetRNC_ToSourceRNC_TransparentContainer() const;
    void set_TargetBSS_ToSourceBSS_TransparentContainer(TargetBSS_ToSourceBSS_TransparentContainer &);
    TargetBSS_ToSourceBSS_TransparentContainer *get_TargetBSS_ToSourceBSS_TransparentContainer() const;
    void set_TimeToWait(TimeToWait &);
    TimeToWait *get_TimeToWait() const;
    void set_Time_UE_StayedInCell_EnhancedGranularity(Time_UE_StayedInCell_EnhancedGranularity &);
    Time_UE_StayedInCell_EnhancedGranularity *get_Time_UE_StayedInCell_EnhancedGranularity() const;
    void set_TransportInformation(TransportInformation &);
    TransportInformation *get_TransportInformation() const;
    void set_TransportLayerAddress(TransportLayerAddress &);
    TransportLayerAddress *get_TransportLayerAddress() const;
    void set_TraceActivation(TraceActivation &);
    TraceActivation *get_TraceActivation() const;
    void set_E_UTRAN_Trace_ID(E_UTRAN_Trace_ID &);
    E_UTRAN_Trace_ID *get_E_UTRAN_Trace_ID() const;
    void set_TrafficLoadReductionIndication(TrafficLoadReductionIndication &);
    TrafficLoadReductionIndication *get_TrafficLoadReductionIndication() const;
    void set_TunnelInformation(TunnelInformation &);
    TunnelInformation *get_TunnelInformation() const;
    void set_TAIListForRestart(TAIListForRestart &);
    TAIListForRestart *get_TAIListForRestart() const;
    void set_UEAggregateMaximumBitrate(UEAggregateMaximumBitrate &);
    UEAggregateMaximumBitrate *get_UEAggregateMaximumBitrate() const;
    void set_UE_RetentionInformation(UE_RetentionInformation &);
    UE_RetentionInformation *get_UE_RetentionInformation() const;
    void set_UE_S1AP_IDs(UE_S1AP_IDs &);
    UE_S1AP_IDs *get_UE_S1AP_IDs() const;
    void set_UE_associatedLogicalS1_ConnectionItem(UE_associatedLogicalS1_ConnectionItem &);
    UE_associatedLogicalS1_ConnectionItem *get_UE_associatedLogicalS1_ConnectionItem() const;
    void set_UEIdentityIndexValue(UEIdentityIndexValue &);
    UEIdentityIndexValue *get_UEIdentityIndexValue() const;
    void set_UE_HistoryInformationFromTheUE(UE_HistoryInformationFromTheUE &);
    UE_HistoryInformationFromTheUE *get_UE_HistoryInformationFromTheUE() const;
    void set_UEPagingID(UEPagingID &);
    UEPagingID *get_UEPagingID() const;
    void set_UERadioCapability(UERadioCapability &);
    UERadioCapability *get_UERadioCapability() const;
    void set_UERadioCapabilityForPaging(UERadioCapabilityForPaging &);
    UERadioCapabilityForPaging *get_UERadioCapabilityForPaging() const;
    void set_UESecurityCapabilities(UESecurityCapabilities &);
    UESecurityCapabilities *get_UESecurityCapabilities() const;
    void set_UE_Usage_Type(UE_Usage_Type &);
    UE_Usage_Type *get_UE_Usage_Type() const;
    void set_UserLocationInformation(UserLocationInformation &);
    UserLocationInformation *get_UserLocationInformation() const;
    void set_UEUserPlaneCIoTSupportIndicator(UEUserPlaneCIoTSupportIndicator &);
    UEUserPlaneCIoTSupportIndicator *get_UEUserPlaneCIoTSupportIndicator() const;
    void set_VoiceSupportMatchIndicator(VoiceSupportMatchIndicator &);
    VoiceSupportMatchIndicator *get_VoiceSupportMatchIndicator() const;
    void set_WarningAreaList(WarningAreaList &);
    WarningAreaList *get_WarningAreaList() const;
    void set_WarningType(WarningType &);
    WarningType *get_WarningType() const;
    void set_WarningSecurityInfo(WarningSecurityInfo &);
    WarningSecurityInfo *get_WarningSecurityInfo() const;
    void set_WarningMessageContents(WarningMessageContents &);
    WarningMessageContents *get_WarningMessageContents() const;
    void set_X2TNLConfigurationInfo(X2TNLConfigurationInfo &);
    X2TNLConfigurationInfo *get_X2TNLConfigurationInfo() const;
    void set_ENBX2ExtTLAs(ENBX2ExtTLAs &);
    ENBX2ExtTLAs *get_ENBX2ExtTLAs() const;
    void set_ENBIndirectX2TransportLayerAddresses(ENBIndirectX2TransportLayerAddresses &);
    ENBIndirectX2TransportLayerAddresses *get_ENBIndirectX2TransportLayerAddresses() const;
    void set_SONtransferApplicationIdentity(SONtransferApplicationIdentity &);
    SONtransferApplicationIdentity *get_SONtransferApplicationIdentity() const;
    void set_SONtransferRequestContainer(SONtransferRequestContainer &);
    SONtransferRequestContainer *get_SONtransferRequestContainer() const;
    void set_SONtransferResponseContainer(SONtransferResponseContainer &);
    SONtransferResponseContainer *get_SONtransferResponseContainer() const;
    void set_SONtransferCause(SONtransferCause &);
    SONtransferCause *get_SONtransferCause() const;
    void set_ReportingCellList(ReportingCellList &);
    ReportingCellList *get_ReportingCellList() const;
    void set_RerouteNASRequest_IEs_TYPE(RerouteNASRequest_IEs_TYPE &);
    RerouteNASRequest_IEs_TYPE *get_RerouteNASRequest_IEs_TYPE() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_S1AP_PDU(const S1AP_PDU &);
    const S1AP_PDU *get_const_S1AP_PDU() const;
    void set_const_HandoverRequired(const HandoverRequired &);
    const HandoverRequired *get_const_HandoverRequired() const;
    void set_const_HandoverCommand(const HandoverCommand &);
    const HandoverCommand *get_const_HandoverCommand() const;
    void set_const_E_RABSubjecttoDataForwardingList(const E_RABSubjecttoDataForwardingList &);
    const E_RABSubjecttoDataForwardingList *get_const_E_RABSubjecttoDataForwardingList() const;
    void set_const_E_RABDataForwardingItem(const E_RABDataForwardingItem &);
    const E_RABDataForwardingItem *get_const_E_RABDataForwardingItem() const;
    void set_const_HandoverPreparationFailure(const HandoverPreparationFailure &);
    const HandoverPreparationFailure *get_const_HandoverPreparationFailure() const;
    void set_const_HandoverRequest(const HandoverRequest &);
    const HandoverRequest *get_const_HandoverRequest() const;
    void set_const_E_RABToBeSetupListHOReq(const E_RABToBeSetupListHOReq &);
    const E_RABToBeSetupListHOReq *get_const_E_RABToBeSetupListHOReq() const;
    void set_const_E_RABToBeSetupItemHOReq(const E_RABToBeSetupItemHOReq &);
    const E_RABToBeSetupItemHOReq *get_const_E_RABToBeSetupItemHOReq() const;
    void set_const_HandoverRequestAcknowledge(const HandoverRequestAcknowledge &);
    const HandoverRequestAcknowledge *get_const_HandoverRequestAcknowledge() const;
    void set_const_E_RABAdmittedList(const E_RABAdmittedList &);
    const E_RABAdmittedList *get_const_E_RABAdmittedList() const;
    void set_const_E_RABAdmittedItem(const E_RABAdmittedItem &);
    const E_RABAdmittedItem *get_const_E_RABAdmittedItem() const;
    void set_const_E_RABFailedtoSetupListHOReqAck(const E_RABFailedtoSetupListHOReqAck &);
    const E_RABFailedtoSetupListHOReqAck *get_const_E_RABFailedtoSetupListHOReqAck() const;
    void set_const_E_RABFailedToSetupItemHOReqAck(const E_RABFailedToSetupItemHOReqAck &);
    const E_RABFailedToSetupItemHOReqAck *get_const_E_RABFailedToSetupItemHOReqAck() const;
    void set_const_HandoverFailure(const HandoverFailure &);
    const HandoverFailure *get_const_HandoverFailure() const;
    void set_const_HandoverNotify(const HandoverNotify &);
    const HandoverNotify *get_const_HandoverNotify() const;
    void set_const_PathSwitchRequest(const PathSwitchRequest &);
    const PathSwitchRequest *get_const_PathSwitchRequest() const;
    void set_const_E_RABToBeSwitchedDLList(const E_RABToBeSwitchedDLList &);
    const E_RABToBeSwitchedDLList *get_const_E_RABToBeSwitchedDLList() const;
    void set_const_E_RABToBeSwitchedDLItem(const E_RABToBeSwitchedDLItem &);
    const E_RABToBeSwitchedDLItem *get_const_E_RABToBeSwitchedDLItem() const;
    void set_const_PathSwitchRequestAcknowledge(const PathSwitchRequestAcknowledge &);
    const PathSwitchRequestAcknowledge *get_const_PathSwitchRequestAcknowledge() const;
    void set_const_E_RABToBeSwitchedULList(const E_RABToBeSwitchedULList &);
    const E_RABToBeSwitchedULList *get_const_E_RABToBeSwitchedULList() const;
    void set_const_E_RABToBeSwitchedULItem(const E_RABToBeSwitchedULItem &);
    const E_RABToBeSwitchedULItem *get_const_E_RABToBeSwitchedULItem() const;
    void set_const_PathSwitchRequestFailure(const PathSwitchRequestFailure &);
    const PathSwitchRequestFailure *get_const_PathSwitchRequestFailure() const;
    void set_const_HandoverCancel(const HandoverCancel &);
    const HandoverCancel *get_const_HandoverCancel() const;
    void set_const_HandoverCancelAcknowledge(const HandoverCancelAcknowledge &);
    const HandoverCancelAcknowledge *get_const_HandoverCancelAcknowledge() const;
    void set_const_E_RABSetupRequest(const E_RABSetupRequest &);
    const E_RABSetupRequest *get_const_E_RABSetupRequest() const;
    void set_const_E_RABToBeSetupListBearerSUReq(const E_RABToBeSetupListBearerSUReq &);
    const E_RABToBeSetupListBearerSUReq *get_const_E_RABToBeSetupListBearerSUReq() const;
    void set_const_E_RABToBeSetupItemBearerSUReq(const E_RABToBeSetupItemBearerSUReq &);
    const E_RABToBeSetupItemBearerSUReq *get_const_E_RABToBeSetupItemBearerSUReq() const;
    void set_const_E_RABSetupResponse(const E_RABSetupResponse &);
    const E_RABSetupResponse *get_const_E_RABSetupResponse() const;
    void set_const_E_RABSetupListBearerSURes(const E_RABSetupListBearerSURes &);
    const E_RABSetupListBearerSURes *get_const_E_RABSetupListBearerSURes() const;
    void set_const_E_RABSetupItemBearerSURes(const E_RABSetupItemBearerSURes &);
    const E_RABSetupItemBearerSURes *get_const_E_RABSetupItemBearerSURes() const;
    void set_const_E_RABModifyRequest(const E_RABModifyRequest &);
    const E_RABModifyRequest *get_const_E_RABModifyRequest() const;
    void set_const_E_RABToBeModifiedListBearerModReq(const E_RABToBeModifiedListBearerModReq &);
    const E_RABToBeModifiedListBearerModReq *get_const_E_RABToBeModifiedListBearerModReq() const;
    void set_const_E_RABToBeModifiedItemBearerModReq(const E_RABToBeModifiedItemBearerModReq &);
    const E_RABToBeModifiedItemBearerModReq *get_const_E_RABToBeModifiedItemBearerModReq() const;
    void set_const_E_RABModifyResponse(const E_RABModifyResponse &);
    const E_RABModifyResponse *get_const_E_RABModifyResponse() const;
    void set_const_E_RABModifyListBearerModRes(const E_RABModifyListBearerModRes &);
    const E_RABModifyListBearerModRes *get_const_E_RABModifyListBearerModRes() const;
    void set_const_E_RABModifyItemBearerModRes(const E_RABModifyItemBearerModRes &);
    const E_RABModifyItemBearerModRes *get_const_E_RABModifyItemBearerModRes() const;
    void set_const_E_RABReleaseCommand(const E_RABReleaseCommand &);
    const E_RABReleaseCommand *get_const_E_RABReleaseCommand() const;
    void set_const_E_RABReleaseResponse(const E_RABReleaseResponse &);
    const E_RABReleaseResponse *get_const_E_RABReleaseResponse() const;
    void set_const_E_RABReleaseListBearerRelComp(const E_RABReleaseListBearerRelComp &);
    const E_RABReleaseListBearerRelComp *get_const_E_RABReleaseListBearerRelComp() const;
    void set_const_E_RABReleaseItemBearerRelComp(const E_RABReleaseItemBearerRelComp &);
    const E_RABReleaseItemBearerRelComp *get_const_E_RABReleaseItemBearerRelComp() const;
    void set_const_E_RABReleaseIndication(const E_RABReleaseIndication &);
    const E_RABReleaseIndication *get_const_E_RABReleaseIndication() const;
    void set_const_InitialContextSetupRequest(const InitialContextSetupRequest &);
    const InitialContextSetupRequest *get_const_InitialContextSetupRequest() const;
    void set_const_E_RABToBeSetupListCtxtSUReq(const E_RABToBeSetupListCtxtSUReq &);
    const E_RABToBeSetupListCtxtSUReq *get_const_E_RABToBeSetupListCtxtSUReq() const;
    void set_const_E_RABToBeSetupItemCtxtSUReq(const E_RABToBeSetupItemCtxtSUReq &);
    const E_RABToBeSetupItemCtxtSUReq *get_const_E_RABToBeSetupItemCtxtSUReq() const;
    void set_const_InitialContextSetupResponse(const InitialContextSetupResponse &);
    const InitialContextSetupResponse *get_const_InitialContextSetupResponse() const;
    void set_const_E_RABSetupListCtxtSURes(const E_RABSetupListCtxtSURes &);
    const E_RABSetupListCtxtSURes *get_const_E_RABSetupListCtxtSURes() const;
    void set_const_E_RABSetupItemCtxtSURes(const E_RABSetupItemCtxtSURes &);
    const E_RABSetupItemCtxtSURes *get_const_E_RABSetupItemCtxtSURes() const;
    void set_const_InitialContextSetupFailure(const InitialContextSetupFailure &);
    const InitialContextSetupFailure *get_const_InitialContextSetupFailure() const;
    void set_const_Paging(const Paging &);
    const Paging *get_const_Paging() const;
    void set_const_TAIList(const TAIList &);
    const TAIList *get_const_TAIList() const;
    void set_const_TAIItem(const TAIItem &);
    const TAIItem *get_const_TAIItem() const;
    void set_const_UEContextReleaseRequest(const UEContextReleaseRequest &);
    const UEContextReleaseRequest *get_const_UEContextReleaseRequest() const;
    void set_const_UEContextReleaseCommand(const UEContextReleaseCommand &);
    const UEContextReleaseCommand *get_const_UEContextReleaseCommand() const;
    void set_const_UEContextReleaseComplete(const UEContextReleaseComplete &);
    const UEContextReleaseComplete *get_const_UEContextReleaseComplete() const;
    void set_const_UEContextModificationRequest(const UEContextModificationRequest &);
    const UEContextModificationRequest *get_const_UEContextModificationRequest() const;
    void set_const_UEContextModificationResponse(const UEContextModificationResponse &);
    const UEContextModificationResponse *get_const_UEContextModificationResponse() const;
    void set_const_UEContextModificationFailure(const UEContextModificationFailure &);
    const UEContextModificationFailure *get_const_UEContextModificationFailure() const;
    void set_const_UERadioCapabilityMatchRequest(const UERadioCapabilityMatchRequest &);
    const UERadioCapabilityMatchRequest *get_const_UERadioCapabilityMatchRequest() const;
    void set_const_UERadioCapabilityMatchResponse(const UERadioCapabilityMatchResponse &);
    const UERadioCapabilityMatchResponse *get_const_UERadioCapabilityMatchResponse() const;
    void set_const_DownlinkNASTransport(const DownlinkNASTransport &);
    const DownlinkNASTransport *get_const_DownlinkNASTransport() const;
    void set_const_InitialUEMessage(const InitialUEMessage &);
    const InitialUEMessage *get_const_InitialUEMessage() const;
    void set_const_UplinkNASTransport(const UplinkNASTransport &);
    const UplinkNASTransport *get_const_UplinkNASTransport() const;
    void set_const_NASNonDeliveryIndication(const NASNonDeliveryIndication &);
    const NASNonDeliveryIndication *get_const_NASNonDeliveryIndication() const;
    void set_const_RerouteNASRequest(const RerouteNASRequest &);
    const RerouteNASRequest *get_const_RerouteNASRequest() const;
    void set_const_Reset(const Reset &);
    const Reset *get_const_Reset() const;
    void set_const_ResetType(const ResetType &);
    const ResetType *get_const_ResetType() const;
    void set_const_ResetAcknowledge(const ResetAcknowledge &);
    const ResetAcknowledge *get_const_ResetAcknowledge() const;
    void set_const_UE_associatedLogicalS1_ConnectionListResAck(const UE_associatedLogicalS1_ConnectionListResAck &);
    const UE_associatedLogicalS1_ConnectionListResAck *get_const_UE_associatedLogicalS1_ConnectionListResAck() const;
    void set_const_ErrorIndication(const ErrorIndication &);
    const ErrorIndication *get_const_ErrorIndication() const;
    void set_const_S1SetupRequest(const S1SetupRequest &);
    const S1SetupRequest *get_const_S1SetupRequest() const;
    void set_const_S1SetupResponse(const S1SetupResponse &);
    const S1SetupResponse *get_const_S1SetupResponse() const;
    void set_const_S1SetupFailure(const S1SetupFailure &);
    const S1SetupFailure *get_const_S1SetupFailure() const;
    void set_const_ENBConfigurationUpdate(const ENBConfigurationUpdate &);
    const ENBConfigurationUpdate *get_const_ENBConfigurationUpdate() const;
    void set_const_ENBConfigurationUpdateAcknowledge(const ENBConfigurationUpdateAcknowledge &);
    const ENBConfigurationUpdateAcknowledge *get_const_ENBConfigurationUpdateAcknowledge() const;
    void set_const_ENBConfigurationUpdateFailure(const ENBConfigurationUpdateFailure &);
    const ENBConfigurationUpdateFailure *get_const_ENBConfigurationUpdateFailure() const;
    void set_const_MMEConfigurationUpdate(const MMEConfigurationUpdate &);
    const MMEConfigurationUpdate *get_const_MMEConfigurationUpdate() const;
    void set_const_MMEConfigurationUpdateAcknowledge(const MMEConfigurationUpdateAcknowledge &);
    const MMEConfigurationUpdateAcknowledge *get_const_MMEConfigurationUpdateAcknowledge() const;
    void set_const_MMEConfigurationUpdateFailure(const MMEConfigurationUpdateFailure &);
    const MMEConfigurationUpdateFailure *get_const_MMEConfigurationUpdateFailure() const;
    void set_const_DownlinkS1cdma2000tunnelling(const DownlinkS1cdma2000tunnelling &);
    const DownlinkS1cdma2000tunnelling *get_const_DownlinkS1cdma2000tunnelling() const;
    void set_const_UplinkS1cdma2000tunnelling(const UplinkS1cdma2000tunnelling &);
    const UplinkS1cdma2000tunnelling *get_const_UplinkS1cdma2000tunnelling() const;
    void set_const_UECapabilityInfoIndication(const UECapabilityInfoIndication &);
    const UECapabilityInfoIndication *get_const_UECapabilityInfoIndication() const;
    void set_const_ENBStatusTransfer(const ENBStatusTransfer &);
    const ENBStatusTransfer *get_const_ENBStatusTransfer() const;
    void set_const_MMEStatusTransfer(const MMEStatusTransfer &);
    const MMEStatusTransfer *get_const_MMEStatusTransfer() const;
    void set_const_TraceStart(const TraceStart &);
    const TraceStart *get_const_TraceStart() const;
    void set_const_TraceFailureIndication(const TraceFailureIndication &);
    const TraceFailureIndication *get_const_TraceFailureIndication() const;
    void set_const_DeactivateTrace(const DeactivateTrace &);
    const DeactivateTrace *get_const_DeactivateTrace() const;
    void set_const_CellTrafficTrace(const CellTrafficTrace &);
    const CellTrafficTrace *get_const_CellTrafficTrace() const;
    void set_const_LocationReportingControl(const LocationReportingControl &);
    const LocationReportingControl *get_const_LocationReportingControl() const;
    void set_const_LocationReportingFailureIndication(const LocationReportingFailureIndication &);
    const LocationReportingFailureIndication *get_const_LocationReportingFailureIndication() const;
    void set_const_LocationReport(const LocationReport &);
    const LocationReport *get_const_LocationReport() const;
    void set_const_OverloadStart(const OverloadStart &);
    const OverloadStart *get_const_OverloadStart() const;
    void set_const_OverloadStop(const OverloadStop &);
    const OverloadStop *get_const_OverloadStop() const;
    void set_const_WriteReplaceWarningRequest(const WriteReplaceWarningRequest &);
    const WriteReplaceWarningRequest *get_const_WriteReplaceWarningRequest() const;
    void set_const_WriteReplaceWarningResponse(const WriteReplaceWarningResponse &);
    const WriteReplaceWarningResponse *get_const_WriteReplaceWarningResponse() const;
    void set_const_ENBDirectInformationTransfer(const ENBDirectInformationTransfer &);
    const ENBDirectInformationTransfer *get_const_ENBDirectInformationTransfer() const;
    void set_const_Inter_SystemInformationTransferType(const Inter_SystemInformationTransferType &);
    const Inter_SystemInformationTransferType *get_const_Inter_SystemInformationTransferType() const;
    void set_const_MMEDirectInformationTransfer(const MMEDirectInformationTransfer &);
    const MMEDirectInformationTransfer *get_const_MMEDirectInformationTransfer() const;
    void set_const_ENBConfigurationTransfer(const ENBConfigurationTransfer &);
    const ENBConfigurationTransfer *get_const_ENBConfigurationTransfer() const;
    void set_const_MMEConfigurationTransfer(const MMEConfigurationTransfer &);
    const MMEConfigurationTransfer *get_const_MMEConfigurationTransfer() const;
    void set_const_PrivateMessage(const PrivateMessage &);
    const PrivateMessage *get_const_PrivateMessage() const;
    void set_const_KillRequest(const KillRequest &);
    const KillRequest *get_const_KillRequest() const;
    void set_const_KillResponse(const KillResponse &);
    const KillResponse *get_const_KillResponse() const;
    void set_const_PWSRestartIndication(const PWSRestartIndication &);
    const PWSRestartIndication *get_const_PWSRestartIndication() const;
    void set_const_PWSFailureIndication(const PWSFailureIndication &);
    const PWSFailureIndication *get_const_PWSFailureIndication() const;
    void set_const_DownlinkUEAssociatedLPPaTransport(const DownlinkUEAssociatedLPPaTransport &);
    const DownlinkUEAssociatedLPPaTransport *get_const_DownlinkUEAssociatedLPPaTransport() const;
    void set_const_UplinkUEAssociatedLPPaTransport(const UplinkUEAssociatedLPPaTransport &);
    const UplinkUEAssociatedLPPaTransport *get_const_UplinkUEAssociatedLPPaTransport() const;
    void set_const_DownlinkNonUEAssociatedLPPaTransport(const DownlinkNonUEAssociatedLPPaTransport &);
    const DownlinkNonUEAssociatedLPPaTransport *get_const_DownlinkNonUEAssociatedLPPaTransport() const;
    void set_const_UplinkNonUEAssociatedLPPaTransport(const UplinkNonUEAssociatedLPPaTransport &);
    const UplinkNonUEAssociatedLPPaTransport *get_const_UplinkNonUEAssociatedLPPaTransport() const;
    void set_const_E_RABModificationIndication(const E_RABModificationIndication &);
    const E_RABModificationIndication *get_const_E_RABModificationIndication() const;
    void set_const_E_RABToBeModifiedListBearerModInd(const E_RABToBeModifiedListBearerModInd &);
    const E_RABToBeModifiedListBearerModInd *get_const_E_RABToBeModifiedListBearerModInd() const;
    void set_const_E_RABToBeModifiedItemBearerModInd(const E_RABToBeModifiedItemBearerModInd &);
    const E_RABToBeModifiedItemBearerModInd *get_const_E_RABToBeModifiedItemBearerModInd() const;
    void set_const_E_RABNotToBeModifiedListBearerModInd(const E_RABNotToBeModifiedListBearerModInd &);
    const E_RABNotToBeModifiedListBearerModInd *get_const_E_RABNotToBeModifiedListBearerModInd() const;
    void set_const_E_RABNotToBeModifiedItemBearerModInd(const E_RABNotToBeModifiedItemBearerModInd &);
    const E_RABNotToBeModifiedItemBearerModInd *get_const_E_RABNotToBeModifiedItemBearerModInd() const;
    void set_const_CSGMembershipInfo(const CSGMembershipInfo &);
    const CSGMembershipInfo *get_const_CSGMembershipInfo() const;
    void set_const_E_RABModificationConfirm(const E_RABModificationConfirm &);
    const E_RABModificationConfirm *get_const_E_RABModificationConfirm() const;
    void set_const_E_RABModifyListBearerModConf(const E_RABModifyListBearerModConf &);
    const E_RABModifyListBearerModConf *get_const_E_RABModifyListBearerModConf() const;
    void set_const_E_RABModifyItemBearerModConf(const E_RABModifyItemBearerModConf &);
    const E_RABModifyItemBearerModConf *get_const_E_RABModifyItemBearerModConf() const;
    void set_const_UEContextModificationIndication(const UEContextModificationIndication &);
    const UEContextModificationIndication *get_const_UEContextModificationIndication() const;
    void set_const_UEContextModificationConfirm(const UEContextModificationConfirm &);
    const UEContextModificationConfirm *get_const_UEContextModificationConfirm() const;
    void set_const_UEContextSuspendRequest(const UEContextSuspendRequest &);
    const UEContextSuspendRequest *get_const_UEContextSuspendRequest() const;
    void set_const_UEContextSuspendResponse(const UEContextSuspendResponse &);
    const UEContextSuspendResponse *get_const_UEContextSuspendResponse() const;
    void set_const_UEContextResumeRequest(const UEContextResumeRequest &);
    const UEContextResumeRequest *get_const_UEContextResumeRequest() const;
    void set_const_E_RABFailedToResumeListResumeReq(const E_RABFailedToResumeListResumeReq &);
    const E_RABFailedToResumeListResumeReq *get_const_E_RABFailedToResumeListResumeReq() const;
    void set_const_E_RABFailedToResumeItemResumeReq(const E_RABFailedToResumeItemResumeReq &);
    const E_RABFailedToResumeItemResumeReq *get_const_E_RABFailedToResumeItemResumeReq() const;
    void set_const_UEContextResumeResponse(const UEContextResumeResponse &);
    const UEContextResumeResponse *get_const_UEContextResumeResponse() const;
    void set_const_E_RABFailedToResumeListResumeRes(const E_RABFailedToResumeListResumeRes &);
    const E_RABFailedToResumeListResumeRes *get_const_E_RABFailedToResumeListResumeRes() const;
    void set_const_E_RABFailedToResumeItemResumeRes(const E_RABFailedToResumeItemResumeRes &);
    const E_RABFailedToResumeItemResumeRes *get_const_E_RABFailedToResumeItemResumeRes() const;
    void set_const_UEContextResumeFailure(const UEContextResumeFailure &);
    const UEContextResumeFailure *get_const_UEContextResumeFailure() const;
    void set_const_ConnectionEstablishmentIndication(const ConnectionEstablishmentIndication &);
    const ConnectionEstablishmentIndication *get_const_ConnectionEstablishmentIndication() const;
    void set_const_Additional_GUTI(const Additional_GUTI &);
    const Additional_GUTI *get_const_Additional_GUTI() const;
    void set_const_AssistanceDataForPaging(const AssistanceDataForPaging &);
    const AssistanceDataForPaging *get_const_AssistanceDataForPaging() const;
    void set_const_Bearers_SubjectToStatusTransfer_Item(const Bearers_SubjectToStatusTransfer_Item &);
    const Bearers_SubjectToStatusTransfer_Item *get_const_Bearers_SubjectToStatusTransfer_Item() const;
    void set_const_BearerType(const BearerType &);
    const BearerType *get_const_BearerType() const;
    void set_const_BroadcastCancelledAreaList(const BroadcastCancelledAreaList &);
    const BroadcastCancelledAreaList *get_const_BroadcastCancelledAreaList() const;
    void set_const_BroadcastCompletedAreaList(const BroadcastCompletedAreaList &);
    const BroadcastCompletedAreaList *get_const_BroadcastCompletedAreaList() const;
    void set_const_Cause(const Cause &);
    const Cause *get_const_Cause() const;
    void set_const_CellAccessMode(const CellAccessMode &);
    const CellAccessMode *get_const_CellAccessMode() const;
    void set_const_CellIdentifierAndCELevelForCECapableUEs(const CellIdentifierAndCELevelForCECapableUEs &);
    const CellIdentifierAndCELevelForCECapableUEs *get_const_CellIdentifierAndCELevelForCECapableUEs() const;
    void set_const_CE_mode_B_SupportIndicator(const CE_mode_B_SupportIndicator &);
    const CE_mode_B_SupportIndicator *get_const_CE_mode_B_SupportIndicator() const;
    void set_const_Cdma2000PDU(const Cdma2000PDU &);
    const Cdma2000PDU *get_const_Cdma2000PDU() const;
    void set_const_Cdma2000RATType(const Cdma2000RATType &);
    const Cdma2000RATType *get_const_Cdma2000RATType() const;
    void set_const_Cdma2000SectorID(const Cdma2000SectorID &);
    const Cdma2000SectorID *get_const_Cdma2000SectorID() const;
    void set_const_Cdma2000HOStatus(const Cdma2000HOStatus &);
    const Cdma2000HOStatus *get_const_Cdma2000HOStatus() const;
    void set_const_Cdma2000HORequiredIndication(const Cdma2000HORequiredIndication &);
    const Cdma2000HORequiredIndication *get_const_Cdma2000HORequiredIndication() const;
    void set_const_Cdma2000OneXSRVCCInfo(const Cdma2000OneXSRVCCInfo &);
    const Cdma2000OneXSRVCCInfo *get_const_Cdma2000OneXSRVCCInfo() const;
    void set_const_Cdma2000OneXRAND(const Cdma2000OneXRAND &);
    const Cdma2000OneXRAND *get_const_Cdma2000OneXRAND() const;
    void set_const_CNDomain(const CNDomain &);
    const CNDomain *get_const_CNDomain() const;
    void set_const_ConcurrentWarningMessageIndicator(const ConcurrentWarningMessageIndicator &);
    const ConcurrentWarningMessageIndicator *get_const_ConcurrentWarningMessageIndicator() const;
    void set_const_Correlation_ID(const Correlation_ID &);
    const Correlation_ID *get_const_Correlation_ID() const;
    void set_const_CSFallbackIndicator(const CSFallbackIndicator &);
    const CSFallbackIndicator *get_const_CSFallbackIndicator() const;
    void set_const_AdditionalCSFallbackIndicator(const AdditionalCSFallbackIndicator &);
    const AdditionalCSFallbackIndicator *get_const_AdditionalCSFallbackIndicator() const;
    void set_const_CSG_Id(const CSG_Id &);
    const CSG_Id *get_const_CSG_Id() const;
    void set_const_CSG_IdList(const CSG_IdList &);
    const CSG_IdList *get_const_CSG_IdList() const;
    void set_const_CSGMembershipStatus(const CSGMembershipStatus &);
    const CSGMembershipStatus *get_const_CSGMembershipStatus() const;
    void set_const_COUNTValueExtended(const COUNTValueExtended &);
    const COUNTValueExtended *get_const_COUNTValueExtended() const;
    void set_const_COUNTvaluePDCP_SNlength18(const COUNTvaluePDCP_SNlength18 &);
    const COUNTvaluePDCP_SNlength18 *get_const_COUNTvaluePDCP_SNlength18() const;
    void set_const_CriticalityDiagnostics(const CriticalityDiagnostics &);
    const CriticalityDiagnostics *get_const_CriticalityDiagnostics() const;
    void set_const_DataCodingScheme(const DataCodingScheme &);
    const DataCodingScheme *get_const_DataCodingScheme() const;
    void set_const_Direct_Forwarding_Path_Availability(const Direct_Forwarding_Path_Availability &);
    const Direct_Forwarding_Path_Availability *get_const_Direct_Forwarding_Path_Availability() const;
    void set_const_Data_Forwarding_Not_Possible(const Data_Forwarding_Not_Possible &);
    const Data_Forwarding_Not_Possible *get_const_Data_Forwarding_Not_Possible() const;
    void set_const_PWSfailedECGIList(const PWSfailedECGIList &);
    const PWSfailedECGIList *get_const_PWSfailedECGIList() const;
    void set_const_EmergencyAreaIDListForRestart(const EmergencyAreaIDListForRestart &);
    const EmergencyAreaIDListForRestart *get_const_EmergencyAreaIDListForRestart() const;
    void set_const_Global_ENB_ID(const Global_ENB_ID &);
    const Global_ENB_ID *get_const_Global_ENB_ID() const;
    void set_const_GUMMEIList(const GUMMEIList &);
    const GUMMEIList *get_const_GUMMEIList() const;
    void set_const_ENB_StatusTransfer_TransparentContainer(const ENB_StatusTransfer_TransparentContainer &);
    const ENB_StatusTransfer_TransparentContainer *get_const_ENB_StatusTransfer_TransparentContainer() const;
    void set_const_ENB_UE_S1AP_ID(const ENB_UE_S1AP_ID &);
    const ENB_UE_S1AP_ID *get_const_ENB_UE_S1AP_ID() const;
    void set_const_ENBname(const ENBname &);
    const ENBname *get_const_ENBname() const;
    void set_const_E_RABInformationListItem(const E_RABInformationListItem &);
    const E_RABInformationListItem *get_const_E_RABInformationListItem() const;
    void set_const_E_RABList(const E_RABList &);
    const E_RABList *get_const_E_RABList() const;
    void set_const_E_RABItem(const E_RABItem &);
    const E_RABItem *get_const_E_RABItem() const;
    void set_const_EUTRAN_CGI(const EUTRAN_CGI &);
    const EUTRAN_CGI *get_const_EUTRAN_CGI() const;
    void set_const_EUTRANRoundTripDelayEstimationInfo(const EUTRANRoundTripDelayEstimationInfo &);
    const EUTRANRoundTripDelayEstimationInfo *get_const_EUTRANRoundTripDelayEstimationInfo() const;
    void set_const_ExpectedUEBehaviour(const ExpectedUEBehaviour &);
    const ExpectedUEBehaviour *get_const_ExpectedUEBehaviour() const;
    void set_const_ExtendedRepetitionPeriod(const ExtendedRepetitionPeriod &);
    const ExtendedRepetitionPeriod *get_const_ExtendedRepetitionPeriod() const;
    void set_const_Extended_UEIdentityIndexValue(const Extended_UEIdentityIndexValue &);
    const Extended_UEIdentityIndexValue *get_const_Extended_UEIdentityIndexValue() const;
    void set_const_GUMMEI(const GUMMEI &);
    const GUMMEI *get_const_GUMMEI() const;
    void set_const_GUMMEIType(const GUMMEIType &);
    const GUMMEIType *get_const_GUMMEIType() const;
    void set_const_GWContextReleaseIndication(const GWContextReleaseIndication &);
    const GWContextReleaseIndication *get_const_GWContextReleaseIndication() const;
    void set_const_HandoverRestrictionList(const HandoverRestrictionList &);
    const HandoverRestrictionList *get_const_HandoverRestrictionList() const;
    void set_const_HandoverType(const HandoverType &);
    const HandoverType *get_const_HandoverType() const;
    void set_const_Masked_IMEISV(const Masked_IMEISV &);
    const Masked_IMEISV *get_const_Masked_IMEISV() const;
    void set_const_InformationOnRecommendedCellsAndENBsForPaging(const InformationOnRecommendedCellsAndENBsForPaging &);
    const InformationOnRecommendedCellsAndENBsForPaging *get_const_InformationOnRecommendedCellsAndENBsForPaging() const;
    void set_const_KillAllWarningMessages(const KillAllWarningMessages &);
    const KillAllWarningMessages *get_const_KillAllWarningMessages() const;
    void set_const_LAI(const LAI &);
    const LAI *get_const_LAI() const;
    void set_const_L3_Information(const L3_Information &);
    const L3_Information *get_const_L3_Information() const;
    void set_const_LPPa_PDU(const LPPa_PDU &);
    const LPPa_PDU *get_const_LPPa_PDU() const;
    void set_const_LHN_ID(const LHN_ID &);
    const LHN_ID *get_const_LHN_ID() const;
    void set_const_LoggedMBSFNMDT(const LoggedMBSFNMDT &);
    const LoggedMBSFNMDT *get_const_LoggedMBSFNMDT() const;
    void set_const_M3Configuration(const M3Configuration &);
    const M3Configuration *get_const_M3Configuration() const;
    void set_const_M4Configuration(const M4Configuration &);
    const M4Configuration *get_const_M4Configuration() const;
    void set_const_M5Configuration(const M5Configuration &);
    const M5Configuration *get_const_M5Configuration() const;
    void set_const_M6Configuration(const M6Configuration &);
    const M6Configuration *get_const_M6Configuration() const;
    void set_const_M7Configuration(const M7Configuration &);
    const M7Configuration *get_const_M7Configuration() const;
    void set_const_MDT_Location_Info(const MDT_Location_Info &);
    const MDT_Location_Info *get_const_MDT_Location_Info() const;
    void set_const_MDT_Configuration(const MDT_Configuration &);
    const MDT_Configuration *get_const_MDT_Configuration() const;
    void set_const_ManagementBasedMDTAllowed(const ManagementBasedMDTAllowed &);
    const ManagementBasedMDTAllowed *get_const_ManagementBasedMDTAllowed() const;
    void set_const_MDTPLMNList(const MDTPLMNList &);
    const MDTPLMNList *get_const_MDTPLMNList() const;
    void set_const_PrivacyIndicator(const PrivacyIndicator &);
    const PrivacyIndicator *get_const_PrivacyIndicator() const;
    void set_const_MessageIdentifier(const MessageIdentifier &);
    const MessageIdentifier *get_const_MessageIdentifier() const;
    void set_const_S1AP_IEs_MobilityInformation(const S1AP_IEs_MobilityInformation &);
    const S1AP_IEs_MobilityInformation *get_const_S1AP_IEs_MobilityInformation() const;
    void set_const_MMEname(const MMEname &);
    const MMEname *get_const_MMEname() const;
    void set_const_MMERelaySupportIndicator(const MMERelaySupportIndicator &);
    const MMERelaySupportIndicator *get_const_MMERelaySupportIndicator() const;
    void set_const_MME_Group_ID(const MME_Group_ID &);
    const MME_Group_ID *get_const_MME_Group_ID() const;
    void set_const_MME_UE_S1AP_ID(const MME_UE_S1AP_ID &);
    const MME_UE_S1AP_ID *get_const_MME_UE_S1AP_ID() const;
    void set_const_MSClassmark2(const MSClassmark2 &);
    const MSClassmark2 *get_const_MSClassmark2() const;
    void set_const_MSClassmark3(const MSClassmark3 &);
    const MSClassmark3 *get_const_MSClassmark3() const;
    void set_const_MutingAvailabilityIndication(const MutingAvailabilityIndication &);
    const MutingAvailabilityIndication *get_const_MutingAvailabilityIndication() const;
    void set_const_MutingPatternInformation(const MutingPatternInformation &);
    const MutingPatternInformation *get_const_MutingPatternInformation() const;
    void set_const_NAS_PDU(const NAS_PDU &);
    const NAS_PDU *get_const_NAS_PDU() const;
    void set_const_NASSecurityParametersfromE_UTRAN(const NASSecurityParametersfromE_UTRAN &);
    const NASSecurityParametersfromE_UTRAN *get_const_NASSecurityParametersfromE_UTRAN() const;
    void set_const_NASSecurityParameterstoE_UTRAN(const NASSecurityParameterstoE_UTRAN &);
    const NASSecurityParameterstoE_UTRAN *get_const_NASSecurityParameterstoE_UTRAN() const;
    void set_const_NB_IoT_DefaultPagingDRX(const NB_IoT_DefaultPagingDRX &);
    const NB_IoT_DefaultPagingDRX *get_const_NB_IoT_DefaultPagingDRX() const;
    void set_const_NB_IoT_Paging_eDRXInformation(const NB_IoT_Paging_eDRXInformation &);
    const NB_IoT_Paging_eDRXInformation *get_const_NB_IoT_Paging_eDRXInformation() const;
    void set_const_NB_IoT_UEIdentityIndexValue(const NB_IoT_UEIdentityIndexValue &);
    const NB_IoT_UEIdentityIndexValue *get_const_NB_IoT_UEIdentityIndexValue() const;
    void set_const_NumberofBroadcastRequest(const NumberofBroadcastRequest &);
    const NumberofBroadcastRequest *get_const_NumberofBroadcastRequest() const;
    void set_const_OldBSS_ToNewBSS_Information(const OldBSS_ToNewBSS_Information &);
    const OldBSS_ToNewBSS_Information *get_const_OldBSS_ToNewBSS_Information() const;
    void set_const_OverloadResponse(const OverloadResponse &);
    const OverloadResponse *get_const_OverloadResponse() const;
    void set_const_Paging_eDRXInformation(const Paging_eDRXInformation &);
    const Paging_eDRXInformation *get_const_Paging_eDRXInformation() const;
    void set_const_PagingDRX(const PagingDRX &);
    const PagingDRX *get_const_PagingDRX() const;
    void set_const_PagingPriority(const PagingPriority &);
    const PagingPriority *get_const_PagingPriority() const;
    void set_const_ProSeAuthorized(const ProSeAuthorized &);
    const ProSeAuthorized *get_const_ProSeAuthorized() const;
    void set_const_ProSeUEtoNetworkRelaying(const ProSeUEtoNetworkRelaying &);
    const ProSeUEtoNetworkRelaying *get_const_ProSeUEtoNetworkRelaying() const;
    void set_const_PS_ServiceNotAvailable(const PS_ServiceNotAvailable &);
    const PS_ServiceNotAvailable *get_const_PS_ServiceNotAvailable() const;
    void set_const_ReceiveStatusOfULPDCPSDUsExtended(const ReceiveStatusOfULPDCPSDUsExtended &);
    const ReceiveStatusOfULPDCPSDUsExtended *get_const_ReceiveStatusOfULPDCPSDUsExtended() const;
    void set_const_ReceiveStatusOfULPDCPSDUsPDCP_SNlength18(const ReceiveStatusOfULPDCPSDUsPDCP_SNlength18 &);
    const ReceiveStatusOfULPDCPSDUsPDCP_SNlength18 *get_const_ReceiveStatusOfULPDCPSDUsPDCP_SNlength18() const;
    void set_const_RecommendedCellItem(const RecommendedCellItem &);
    const RecommendedCellItem *get_const_RecommendedCellItem() const;
    void set_const_RecommendedENBItem(const RecommendedENBItem &);
    const RecommendedENBItem *get_const_RecommendedENBItem() const;
    void set_const_RelativeMMECapacity(const RelativeMMECapacity &);
    const RelativeMMECapacity *get_const_RelativeMMECapacity() const;
    void set_const_RelayNode_Indicator(const RelayNode_Indicator &);
    const RelayNode_Indicator *get_const_RelayNode_Indicator() const;
    void set_const_RAT_Type(const RAT_Type &);
    const RAT_Type *get_const_RAT_Type() const;
    void set_const_RequestType(const RequestType &);
    const RequestType *get_const_RequestType() const;
    void set_const_RepetitionPeriod(const RepetitionPeriod &);
    const RepetitionPeriod *get_const_RepetitionPeriod() const;
    void set_const_RRC_Establishment_Cause(const RRC_Establishment_Cause &);
    const RRC_Establishment_Cause *get_const_RRC_Establishment_Cause() const;
    void set_const_ECGIListForRestart(const ECGIListForRestart &);
    const ECGIListForRestart *get_const_ECGIListForRestart() const;
    void set_const_Routing_ID(const Routing_ID &);
    const Routing_ID *get_const_Routing_ID() const;
    void set_const_SecurityKey(const SecurityKey &);
    const SecurityKey *get_const_SecurityKey() const;
    void set_const_SecurityContext(const SecurityContext &);
    const SecurityContext *get_const_SecurityContext() const;
    void set_const_SerialNumber(const SerialNumber &);
    const SerialNumber *get_const_SerialNumber() const;
    void set_const_SONInformationReport(const SONInformationReport &);
    const SONInformationReport *get_const_SONInformationReport() const;
    void set_const_SONConfigurationTransfer(const SONConfigurationTransfer &);
    const SONConfigurationTransfer *get_const_SONConfigurationTransfer() const;
    void set_const_SynchronisationInformation(const SynchronisationInformation &);
    const SynchronisationInformation *get_const_SynchronisationInformation() const;
    void set_const_Source_ToTarget_TransparentContainer(const Source_ToTarget_TransparentContainer &);
    const Source_ToTarget_TransparentContainer *get_const_Source_ToTarget_TransparentContainer() const;
    void set_const_SourceBSS_ToTargetBSS_TransparentContainer(const SourceBSS_ToTargetBSS_TransparentContainer &);
    const SourceBSS_ToTargetBSS_TransparentContainer *get_const_SourceBSS_ToTargetBSS_TransparentContainer() const;
    void set_const_SRVCCOperationNotPossible(const SRVCCOperationNotPossible &);
    const SRVCCOperationNotPossible *get_const_SRVCCOperationNotPossible() const;
    void set_const_SRVCCOperationPossible(const SRVCCOperationPossible &);
    const SRVCCOperationPossible *get_const_SRVCCOperationPossible() const;
    void set_const_SRVCCHOIndication(const SRVCCHOIndication &);
    const SRVCCHOIndication *get_const_SRVCCHOIndication() const;
    void set_const_SourceeNB_ToTargeteNB_TransparentContainer(const SourceeNB_ToTargeteNB_TransparentContainer &);
    const SourceeNB_ToTargeteNB_TransparentContainer *get_const_SourceeNB_ToTargeteNB_TransparentContainer() const;
    void set_const_SourceRNC_ToTargetRNC_TransparentContainer(const SourceRNC_ToTargetRNC_TransparentContainer &);
    const SourceRNC_ToTargetRNC_TransparentContainer *get_const_SourceRNC_ToTargetRNC_TransparentContainer() const;
    void set_const_ServedGUMMEIs(const ServedGUMMEIs &);
    const ServedGUMMEIs *get_const_ServedGUMMEIs() const;
    void set_const_SubscriberProfileIDforRFP(const SubscriberProfileIDforRFP &);
    const SubscriberProfileIDforRFP *get_const_SubscriberProfileIDforRFP() const;
    void set_const_SupportedTAs(const SupportedTAs &);
    const SupportedTAs *get_const_SupportedTAs() const;
    void set_const_TimeSynchronisationInfo(const TimeSynchronisationInfo &);
    const TimeSynchronisationInfo *get_const_TimeSynchronisationInfo() const;
    void set_const_S_TMSI(const S_TMSI &);
    const S_TMSI *get_const_S_TMSI() const;
    void set_const_TAI(const TAI &);
    const TAI *get_const_TAI() const;
    void set_const_TargetID(const TargetID &);
    const TargetID *get_const_TargetID() const;
    void set_const_TargeteNB_ToSourceeNB_TransparentContainer(const TargeteNB_ToSourceeNB_TransparentContainer &);
    const TargeteNB_ToSourceeNB_TransparentContainer *get_const_TargeteNB_ToSourceeNB_TransparentContainer() const;
    void set_const_Target_ToSource_TransparentContainer(const Target_ToSource_TransparentContainer &);
    const Target_ToSource_TransparentContainer *get_const_Target_ToSource_TransparentContainer() const;
    void set_const_TargetRNC_ToSourceRNC_TransparentContainer(const TargetRNC_ToSourceRNC_TransparentContainer &);
    const TargetRNC_ToSourceRNC_TransparentContainer *get_const_TargetRNC_ToSourceRNC_TransparentContainer() const;
    void set_const_TargetBSS_ToSourceBSS_TransparentContainer(const TargetBSS_ToSourceBSS_TransparentContainer &);
    const TargetBSS_ToSourceBSS_TransparentContainer *get_const_TargetBSS_ToSourceBSS_TransparentContainer() const;
    void set_const_TimeToWait(const TimeToWait &);
    const TimeToWait *get_const_TimeToWait() const;
    void set_const_Time_UE_StayedInCell_EnhancedGranularity(const Time_UE_StayedInCell_EnhancedGranularity &);
    const Time_UE_StayedInCell_EnhancedGranularity *get_const_Time_UE_StayedInCell_EnhancedGranularity() const;
    void set_const_TransportInformation(const TransportInformation &);
    const TransportInformation *get_const_TransportInformation() const;
    void set_const_TransportLayerAddress(const TransportLayerAddress &);
    const TransportLayerAddress *get_const_TransportLayerAddress() const;
    void set_const_TraceActivation(const TraceActivation &);
    const TraceActivation *get_const_TraceActivation() const;
    void set_const_E_UTRAN_Trace_ID(const E_UTRAN_Trace_ID &);
    const E_UTRAN_Trace_ID *get_const_E_UTRAN_Trace_ID() const;
    void set_const_TrafficLoadReductionIndication(const TrafficLoadReductionIndication &);
    const TrafficLoadReductionIndication *get_const_TrafficLoadReductionIndication() const;
    void set_const_TunnelInformation(const TunnelInformation &);
    const TunnelInformation *get_const_TunnelInformation() const;
    void set_const_TAIListForRestart(const TAIListForRestart &);
    const TAIListForRestart *get_const_TAIListForRestart() const;
    void set_const_UEAggregateMaximumBitrate(const UEAggregateMaximumBitrate &);
    const UEAggregateMaximumBitrate *get_const_UEAggregateMaximumBitrate() const;
    void set_const_UE_RetentionInformation(const UE_RetentionInformation &);
    const UE_RetentionInformation *get_const_UE_RetentionInformation() const;
    void set_const_UE_S1AP_IDs(const UE_S1AP_IDs &);
    const UE_S1AP_IDs *get_const_UE_S1AP_IDs() const;
    void set_const_UE_associatedLogicalS1_ConnectionItem(const UE_associatedLogicalS1_ConnectionItem &);
    const UE_associatedLogicalS1_ConnectionItem *get_const_UE_associatedLogicalS1_ConnectionItem() const;
    void set_const_UEIdentityIndexValue(const UEIdentityIndexValue &);
    const UEIdentityIndexValue *get_const_UEIdentityIndexValue() const;
    void set_const_UE_HistoryInformationFromTheUE(const UE_HistoryInformationFromTheUE &);
    const UE_HistoryInformationFromTheUE *get_const_UE_HistoryInformationFromTheUE() const;
    void set_const_UEPagingID(const UEPagingID &);
    const UEPagingID *get_const_UEPagingID() const;
    void set_const_UERadioCapability(const UERadioCapability &);
    const UERadioCapability *get_const_UERadioCapability() const;
    void set_const_UERadioCapabilityForPaging(const UERadioCapabilityForPaging &);
    const UERadioCapabilityForPaging *get_const_UERadioCapabilityForPaging() const;
    void set_const_UESecurityCapabilities(const UESecurityCapabilities &);
    const UESecurityCapabilities *get_const_UESecurityCapabilities() const;
    void set_const_UE_Usage_Type(const UE_Usage_Type &);
    const UE_Usage_Type *get_const_UE_Usage_Type() const;
    void set_const_UserLocationInformation(const UserLocationInformation &);
    const UserLocationInformation *get_const_UserLocationInformation() const;
    void set_const_UEUserPlaneCIoTSupportIndicator(const UEUserPlaneCIoTSupportIndicator &);
    const UEUserPlaneCIoTSupportIndicator *get_const_UEUserPlaneCIoTSupportIndicator() const;
    void set_const_VoiceSupportMatchIndicator(const VoiceSupportMatchIndicator &);
    const VoiceSupportMatchIndicator *get_const_VoiceSupportMatchIndicator() const;
    void set_const_WarningAreaList(const WarningAreaList &);
    const WarningAreaList *get_const_WarningAreaList() const;
    void set_const_WarningType(const WarningType &);
    const WarningType *get_const_WarningType() const;
    void set_const_WarningSecurityInfo(const WarningSecurityInfo &);
    const WarningSecurityInfo *get_const_WarningSecurityInfo() const;
    void set_const_WarningMessageContents(const WarningMessageContents &);
    const WarningMessageContents *get_const_WarningMessageContents() const;
    void set_const_X2TNLConfigurationInfo(const X2TNLConfigurationInfo &);
    const X2TNLConfigurationInfo *get_const_X2TNLConfigurationInfo() const;
    void set_const_ENBX2ExtTLAs(const ENBX2ExtTLAs &);
    const ENBX2ExtTLAs *get_const_ENBX2ExtTLAs() const;
    void set_const_ENBIndirectX2TransportLayerAddresses(const ENBIndirectX2TransportLayerAddresses &);
    const ENBIndirectX2TransportLayerAddresses *get_const_ENBIndirectX2TransportLayerAddresses() const;
    void set_const_SONtransferApplicationIdentity(const SONtransferApplicationIdentity &);
    const SONtransferApplicationIdentity *get_const_SONtransferApplicationIdentity() const;
    void set_const_SONtransferRequestContainer(const SONtransferRequestContainer &);
    const SONtransferRequestContainer *get_const_SONtransferRequestContainer() const;
    void set_const_SONtransferResponseContainer(const SONtransferResponseContainer &);
    const SONtransferResponseContainer *get_const_SONtransferResponseContainer() const;
    void set_const_SONtransferCause(const SONtransferCause &);
    const SONtransferCause *get_const_SONtransferCause() const;
    void set_const_ReportingCellList(const ReportingCellList &);
    const ReportingCellList *get_const_ReportingCellList() const;
    void set_const_RerouteNASRequest_IEs_TYPE(const RerouteNASRequest_IEs_TYPE &);
    const RerouteNASRequest_IEs_TYPE *get_const_RerouteNASRequest_IEs_TYPE() const;
#endif
};

/* Specific PDU classes */

class OSS_PUBLIC S1AP_PDU_PDU : public ConcretePDU {
public:
    S1AP_PDU_PDU();
    void set_data(S1AP_PDU &);
    S1AP_PDU *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const S1AP_PDU & d);
    const S1AP_PDU *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC HandoverRequired_PDU : public ConcretePDU {
public:
    HandoverRequired_PDU();
    void set_data(HandoverRequired &);
    HandoverRequired *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const HandoverRequired & d);
    const HandoverRequired *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC HandoverCommand_PDU : public ConcretePDU {
public:
    HandoverCommand_PDU();
    void set_data(HandoverCommand &);
    HandoverCommand *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const HandoverCommand & d);
    const HandoverCommand *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC E_RABSubjecttoDataForwardingList_PDU : public ConcretePDU {
public:
    E_RABSubjecttoDataForwardingList_PDU();
    void set_data(E_RABSubjecttoDataForwardingList &);
    E_RABSubjecttoDataForwardingList *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const E_RABSubjecttoDataForwardingList & d);
    const E_RABSubjecttoDataForwardingList *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC E_RABDataForwardingItem_PDU : public ConcretePDU {
public:
    E_RABDataForwardingItem_PDU();
    void set_data(E_RABDataForwardingItem &);
    E_RABDataForwardingItem *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const E_RABDataForwardingItem & d);
    const E_RABDataForwardingItem *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC HandoverPreparationFailure_PDU : public ConcretePDU {
public:
    HandoverPreparationFailure_PDU();
    void set_data(HandoverPreparationFailure &);
    HandoverPreparationFailure *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const HandoverPreparationFailure & d);
    const HandoverPreparationFailure *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC HandoverRequest_PDU : public ConcretePDU {
public:
    HandoverRequest_PDU();
    void set_data(HandoverRequest &);
    HandoverRequest *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const HandoverRequest & d);
    const HandoverRequest *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC E_RABToBeSetupListHOReq_PDU : public ConcretePDU {
public:
    E_RABToBeSetupListHOReq_PDU();
    void set_data(E_RABToBeSetupListHOReq &);
    E_RABToBeSetupListHOReq *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const E_RABToBeSetupListHOReq & d);
    const E_RABToBeSetupListHOReq *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC E_RABToBeSetupItemHOReq_PDU : public ConcretePDU {
public:
    E_RABToBeSetupItemHOReq_PDU();
    void set_data(E_RABToBeSetupItemHOReq &);
    E_RABToBeSetupItemHOReq *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const E_RABToBeSetupItemHOReq & d);
    const E_RABToBeSetupItemHOReq *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC HandoverRequestAcknowledge_PDU : public ConcretePDU {
public:
    HandoverRequestAcknowledge_PDU();
    void set_data(HandoverRequestAcknowledge &);
    HandoverRequestAcknowledge *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const HandoverRequestAcknowledge & d);
    const HandoverRequestAcknowledge *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC E_RABAdmittedList_PDU : public ConcretePDU {
public:
    E_RABAdmittedList_PDU();
    void set_data(E_RABAdmittedList &);
    E_RABAdmittedList *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const E_RABAdmittedList & d);
    const E_RABAdmittedList *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC E_RABAdmittedItem_PDU : public ConcretePDU {
public:
    E_RABAdmittedItem_PDU();
    void set_data(E_RABAdmittedItem &);
    E_RABAdmittedItem *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const E_RABAdmittedItem & d);
    const E_RABAdmittedItem *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC E_RABFailedtoSetupListHOReqAck_PDU : public ConcretePDU {
public:
    E_RABFailedtoSetupListHOReqAck_PDU();
    void set_data(E_RABFailedtoSetupListHOReqAck &);
    E_RABFailedtoSetupListHOReqAck *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const E_RABFailedtoSetupListHOReqAck & d);
    const E_RABFailedtoSetupListHOReqAck *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC E_RABFailedToSetupItemHOReqAck_PDU : public ConcretePDU {
public:
    E_RABFailedToSetupItemHOReqAck_PDU();
    void set_data(E_RABFailedToSetupItemHOReqAck &);
    E_RABFailedToSetupItemHOReqAck *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const E_RABFailedToSetupItemHOReqAck & d);
    const E_RABFailedToSetupItemHOReqAck *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC HandoverFailure_PDU : public ConcretePDU {
public:
    HandoverFailure_PDU();
    void set_data(HandoverFailure &);
    HandoverFailure *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const HandoverFailure & d);
    const HandoverFailure *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC HandoverNotify_PDU : public ConcretePDU {
public:
    HandoverNotify_PDU();
    void set_data(HandoverNotify &);
    HandoverNotify *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const HandoverNotify & d);
    const HandoverNotify *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC PathSwitchRequest_PDU : public ConcretePDU {
public:
    PathSwitchRequest_PDU();
    void set_data(PathSwitchRequest &);
    PathSwitchRequest *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const PathSwitchRequest & d);
    const PathSwitchRequest *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC E_RABToBeSwitchedDLList_PDU : public ConcretePDU {
public:
    E_RABToBeSwitchedDLList_PDU();
    void set_data(E_RABToBeSwitchedDLList &);
    E_RABToBeSwitchedDLList *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const E_RABToBeSwitchedDLList & d);
    const E_RABToBeSwitchedDLList *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC E_RABToBeSwitchedDLItem_PDU : public ConcretePDU {
public:
    E_RABToBeSwitchedDLItem_PDU();
    void set_data(E_RABToBeSwitchedDLItem &);
    E_RABToBeSwitchedDLItem *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const E_RABToBeSwitchedDLItem & d);
    const E_RABToBeSwitchedDLItem *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC PathSwitchRequestAcknowledge_PDU : public ConcretePDU {
public:
    PathSwitchRequestAcknowledge_PDU();
    void set_data(PathSwitchRequestAcknowledge &);
    PathSwitchRequestAcknowledge *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const PathSwitchRequestAcknowledge & d);
    const PathSwitchRequestAcknowledge *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC E_RABToBeSwitchedULList_PDU : public ConcretePDU {
public:
    E_RABToBeSwitchedULList_PDU();
    void set_data(E_RABToBeSwitchedULList &);
    E_RABToBeSwitchedULList *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const E_RABToBeSwitchedULList & d);
    const E_RABToBeSwitchedULList *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC E_RABToBeSwitchedULItem_PDU : public ConcretePDU {
public:
    E_RABToBeSwitchedULItem_PDU();
    void set_data(E_RABToBeSwitchedULItem &);
    E_RABToBeSwitchedULItem *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const E_RABToBeSwitchedULItem & d);
    const E_RABToBeSwitchedULItem *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC PathSwitchRequestFailure_PDU : public ConcretePDU {
public:
    PathSwitchRequestFailure_PDU();
    void set_data(PathSwitchRequestFailure &);
    PathSwitchRequestFailure *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const PathSwitchRequestFailure & d);
    const PathSwitchRequestFailure *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC HandoverCancel_PDU : public ConcretePDU {
public:
    HandoverCancel_PDU();
    void set_data(HandoverCancel &);
    HandoverCancel *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const HandoverCancel & d);
    const HandoverCancel *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC HandoverCancelAcknowledge_PDU : public ConcretePDU {
public:
    HandoverCancelAcknowledge_PDU();
    void set_data(HandoverCancelAcknowledge &);
    HandoverCancelAcknowledge *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const HandoverCancelAcknowledge & d);
    const HandoverCancelAcknowledge *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC E_RABSetupRequest_PDU : public ConcretePDU {
public:
    E_RABSetupRequest_PDU();
    void set_data(E_RABSetupRequest &);
    E_RABSetupRequest *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const E_RABSetupRequest & d);
    const E_RABSetupRequest *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC E_RABToBeSetupListBearerSUReq_PDU : public ConcretePDU {
public:
    E_RABToBeSetupListBearerSUReq_PDU();
    void set_data(E_RABToBeSetupListBearerSUReq &);
    E_RABToBeSetupListBearerSUReq *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const E_RABToBeSetupListBearerSUReq & d);
    const E_RABToBeSetupListBearerSUReq *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC E_RABToBeSetupItemBearerSUReq_PDU : public ConcretePDU {
public:
    E_RABToBeSetupItemBearerSUReq_PDU();
    void set_data(E_RABToBeSetupItemBearerSUReq &);
    E_RABToBeSetupItemBearerSUReq *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const E_RABToBeSetupItemBearerSUReq & d);
    const E_RABToBeSetupItemBearerSUReq *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC E_RABSetupResponse_PDU : public ConcretePDU {
public:
    E_RABSetupResponse_PDU();
    void set_data(E_RABSetupResponse &);
    E_RABSetupResponse *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const E_RABSetupResponse & d);
    const E_RABSetupResponse *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC E_RABSetupListBearerSURes_PDU : public ConcretePDU {
public:
    E_RABSetupListBearerSURes_PDU();
    void set_data(E_RABSetupListBearerSURes &);
    E_RABSetupListBearerSURes *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const E_RABSetupListBearerSURes & d);
    const E_RABSetupListBearerSURes *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC E_RABSetupItemBearerSURes_PDU : public ConcretePDU {
public:
    E_RABSetupItemBearerSURes_PDU();
    void set_data(E_RABSetupItemBearerSURes &);
    E_RABSetupItemBearerSURes *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const E_RABSetupItemBearerSURes & d);
    const E_RABSetupItemBearerSURes *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC E_RABModifyRequest_PDU : public ConcretePDU {
public:
    E_RABModifyRequest_PDU();
    void set_data(E_RABModifyRequest &);
    E_RABModifyRequest *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const E_RABModifyRequest & d);
    const E_RABModifyRequest *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC E_RABToBeModifiedListBearerModReq_PDU : public ConcretePDU {
public:
    E_RABToBeModifiedListBearerModReq_PDU();
    void set_data(E_RABToBeModifiedListBearerModReq &);
    E_RABToBeModifiedListBearerModReq *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const E_RABToBeModifiedListBearerModReq & d);
    const E_RABToBeModifiedListBearerModReq *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC E_RABToBeModifiedItemBearerModReq_PDU : public ConcretePDU {
public:
    E_RABToBeModifiedItemBearerModReq_PDU();
    void set_data(E_RABToBeModifiedItemBearerModReq &);
    E_RABToBeModifiedItemBearerModReq *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const E_RABToBeModifiedItemBearerModReq & d);
    const E_RABToBeModifiedItemBearerModReq *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC E_RABModifyResponse_PDU : public ConcretePDU {
public:
    E_RABModifyResponse_PDU();
    void set_data(E_RABModifyResponse &);
    E_RABModifyResponse *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const E_RABModifyResponse & d);
    const E_RABModifyResponse *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC E_RABModifyListBearerModRes_PDU : public ConcretePDU {
public:
    E_RABModifyListBearerModRes_PDU();
    void set_data(E_RABModifyListBearerModRes &);
    E_RABModifyListBearerModRes *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const E_RABModifyListBearerModRes & d);
    const E_RABModifyListBearerModRes *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC E_RABModifyItemBearerModRes_PDU : public ConcretePDU {
public:
    E_RABModifyItemBearerModRes_PDU();
    void set_data(E_RABModifyItemBearerModRes &);
    E_RABModifyItemBearerModRes *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const E_RABModifyItemBearerModRes & d);
    const E_RABModifyItemBearerModRes *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC E_RABReleaseCommand_PDU : public ConcretePDU {
public:
    E_RABReleaseCommand_PDU();
    void set_data(E_RABReleaseCommand &);
    E_RABReleaseCommand *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const E_RABReleaseCommand & d);
    const E_RABReleaseCommand *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC E_RABReleaseResponse_PDU : public ConcretePDU {
public:
    E_RABReleaseResponse_PDU();
    void set_data(E_RABReleaseResponse &);
    E_RABReleaseResponse *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const E_RABReleaseResponse & d);
    const E_RABReleaseResponse *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC E_RABReleaseListBearerRelComp_PDU : public ConcretePDU {
public:
    E_RABReleaseListBearerRelComp_PDU();
    void set_data(E_RABReleaseListBearerRelComp &);
    E_RABReleaseListBearerRelComp *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const E_RABReleaseListBearerRelComp & d);
    const E_RABReleaseListBearerRelComp *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC E_RABReleaseItemBearerRelComp_PDU : public ConcretePDU {
public:
    E_RABReleaseItemBearerRelComp_PDU();
    void set_data(E_RABReleaseItemBearerRelComp &);
    E_RABReleaseItemBearerRelComp *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const E_RABReleaseItemBearerRelComp & d);
    const E_RABReleaseItemBearerRelComp *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC E_RABReleaseIndication_PDU : public ConcretePDU {
public:
    E_RABReleaseIndication_PDU();
    void set_data(E_RABReleaseIndication &);
    E_RABReleaseIndication *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const E_RABReleaseIndication & d);
    const E_RABReleaseIndication *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC InitialContextSetupRequest_PDU : public ConcretePDU {
public:
    InitialContextSetupRequest_PDU();
    void set_data(InitialContextSetupRequest &);
    InitialContextSetupRequest *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const InitialContextSetupRequest & d);
    const InitialContextSetupRequest *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC E_RABToBeSetupListCtxtSUReq_PDU : public ConcretePDU {
public:
    E_RABToBeSetupListCtxtSUReq_PDU();
    void set_data(E_RABToBeSetupListCtxtSUReq &);
    E_RABToBeSetupListCtxtSUReq *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const E_RABToBeSetupListCtxtSUReq & d);
    const E_RABToBeSetupListCtxtSUReq *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC E_RABToBeSetupItemCtxtSUReq_PDU : public ConcretePDU {
public:
    E_RABToBeSetupItemCtxtSUReq_PDU();
    void set_data(E_RABToBeSetupItemCtxtSUReq &);
    E_RABToBeSetupItemCtxtSUReq *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const E_RABToBeSetupItemCtxtSUReq & d);
    const E_RABToBeSetupItemCtxtSUReq *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC InitialContextSetupResponse_PDU : public ConcretePDU {
public:
    InitialContextSetupResponse_PDU();
    void set_data(InitialContextSetupResponse &);
    InitialContextSetupResponse *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const InitialContextSetupResponse & d);
    const InitialContextSetupResponse *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC E_RABSetupListCtxtSURes_PDU : public ConcretePDU {
public:
    E_RABSetupListCtxtSURes_PDU();
    void set_data(E_RABSetupListCtxtSURes &);
    E_RABSetupListCtxtSURes *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const E_RABSetupListCtxtSURes & d);
    const E_RABSetupListCtxtSURes *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC E_RABSetupItemCtxtSURes_PDU : public ConcretePDU {
public:
    E_RABSetupItemCtxtSURes_PDU();
    void set_data(E_RABSetupItemCtxtSURes &);
    E_RABSetupItemCtxtSURes *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const E_RABSetupItemCtxtSURes & d);
    const E_RABSetupItemCtxtSURes *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC InitialContextSetupFailure_PDU : public ConcretePDU {
public:
    InitialContextSetupFailure_PDU();
    void set_data(InitialContextSetupFailure &);
    InitialContextSetupFailure *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const InitialContextSetupFailure & d);
    const InitialContextSetupFailure *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC Paging_PDU : public ConcretePDU {
public:
    Paging_PDU();
    void set_data(Paging &);
    Paging *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const Paging & d);
    const Paging *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC TAIList_PDU : public ConcretePDU {
public:
    TAIList_PDU();
    void set_data(TAIList &);
    TAIList *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const TAIList & d);
    const TAIList *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC TAIItem_PDU : public ConcretePDU {
public:
    TAIItem_PDU();
    void set_data(TAIItem &);
    TAIItem *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const TAIItem & d);
    const TAIItem *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC UEContextReleaseRequest_PDU : public ConcretePDU {
public:
    UEContextReleaseRequest_PDU();
    void set_data(UEContextReleaseRequest &);
    UEContextReleaseRequest *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const UEContextReleaseRequest & d);
    const UEContextReleaseRequest *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC UEContextReleaseCommand_PDU : public ConcretePDU {
public:
    UEContextReleaseCommand_PDU();
    void set_data(UEContextReleaseCommand &);
    UEContextReleaseCommand *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const UEContextReleaseCommand & d);
    const UEContextReleaseCommand *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC UEContextReleaseComplete_PDU : public ConcretePDU {
public:
    UEContextReleaseComplete_PDU();
    void set_data(UEContextReleaseComplete &);
    UEContextReleaseComplete *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const UEContextReleaseComplete & d);
    const UEContextReleaseComplete *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC UEContextModificationRequest_PDU : public ConcretePDU {
public:
    UEContextModificationRequest_PDU();
    void set_data(UEContextModificationRequest &);
    UEContextModificationRequest *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const UEContextModificationRequest & d);
    const UEContextModificationRequest *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC UEContextModificationResponse_PDU : public ConcretePDU {
public:
    UEContextModificationResponse_PDU();
    void set_data(UEContextModificationResponse &);
    UEContextModificationResponse *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const UEContextModificationResponse & d);
    const UEContextModificationResponse *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC UEContextModificationFailure_PDU : public ConcretePDU {
public:
    UEContextModificationFailure_PDU();
    void set_data(UEContextModificationFailure &);
    UEContextModificationFailure *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const UEContextModificationFailure & d);
    const UEContextModificationFailure *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC UERadioCapabilityMatchRequest_PDU : public ConcretePDU {
public:
    UERadioCapabilityMatchRequest_PDU();
    void set_data(UERadioCapabilityMatchRequest &);
    UERadioCapabilityMatchRequest *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const UERadioCapabilityMatchRequest & d);
    const UERadioCapabilityMatchRequest *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC UERadioCapabilityMatchResponse_PDU : public ConcretePDU {
public:
    UERadioCapabilityMatchResponse_PDU();
    void set_data(UERadioCapabilityMatchResponse &);
    UERadioCapabilityMatchResponse *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const UERadioCapabilityMatchResponse & d);
    const UERadioCapabilityMatchResponse *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC DownlinkNASTransport_PDU : public ConcretePDU {
public:
    DownlinkNASTransport_PDU();
    void set_data(DownlinkNASTransport &);
    DownlinkNASTransport *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const DownlinkNASTransport & d);
    const DownlinkNASTransport *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC InitialUEMessage_PDU : public ConcretePDU {
public:
    InitialUEMessage_PDU();
    void set_data(InitialUEMessage &);
    InitialUEMessage *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const InitialUEMessage & d);
    const InitialUEMessage *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC UplinkNASTransport_PDU : public ConcretePDU {
public:
    UplinkNASTransport_PDU();
    void set_data(UplinkNASTransport &);
    UplinkNASTransport *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const UplinkNASTransport & d);
    const UplinkNASTransport *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC NASNonDeliveryIndication_PDU : public ConcretePDU {
public:
    NASNonDeliveryIndication_PDU();
    void set_data(NASNonDeliveryIndication &);
    NASNonDeliveryIndication *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const NASNonDeliveryIndication & d);
    const NASNonDeliveryIndication *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC RerouteNASRequest_PDU : public ConcretePDU {
public:
    RerouteNASRequest_PDU();
    void set_data(RerouteNASRequest &);
    RerouteNASRequest *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const RerouteNASRequest & d);
    const RerouteNASRequest *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC Reset_PDU : public ConcretePDU {
public:
    Reset_PDU();
    void set_data(Reset &);
    Reset *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const Reset & d);
    const Reset *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC ResetType_PDU : public ConcretePDU {
public:
    ResetType_PDU();
    void set_data(ResetType &);
    ResetType *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const ResetType & d);
    const ResetType *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC ResetAcknowledge_PDU : public ConcretePDU {
public:
    ResetAcknowledge_PDU();
    void set_data(ResetAcknowledge &);
    ResetAcknowledge *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const ResetAcknowledge & d);
    const ResetAcknowledge *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC UE_associatedLogicalS1_ConnectionListResAck_PDU : public ConcretePDU {
public:
    UE_associatedLogicalS1_ConnectionListResAck_PDU();
    void set_data(UE_associatedLogicalS1_ConnectionListResAck &);
    UE_associatedLogicalS1_ConnectionListResAck *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const UE_associatedLogicalS1_ConnectionListResAck & d);
    const UE_associatedLogicalS1_ConnectionListResAck *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC ErrorIndication_PDU : public ConcretePDU {
public:
    ErrorIndication_PDU();
    void set_data(ErrorIndication &);
    ErrorIndication *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const ErrorIndication & d);
    const ErrorIndication *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC S1SetupRequest_PDU : public ConcretePDU {
public:
    S1SetupRequest_PDU();
    void set_data(S1SetupRequest &);
    S1SetupRequest *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const S1SetupRequest & d);
    const S1SetupRequest *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC S1SetupResponse_PDU : public ConcretePDU {
public:
    S1SetupResponse_PDU();
    void set_data(S1SetupResponse &);
    S1SetupResponse *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const S1SetupResponse & d);
    const S1SetupResponse *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC S1SetupFailure_PDU : public ConcretePDU {
public:
    S1SetupFailure_PDU();
    void set_data(S1SetupFailure &);
    S1SetupFailure *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const S1SetupFailure & d);
    const S1SetupFailure *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC ENBConfigurationUpdate_PDU : public ConcretePDU {
public:
    ENBConfigurationUpdate_PDU();
    void set_data(ENBConfigurationUpdate &);
    ENBConfigurationUpdate *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const ENBConfigurationUpdate & d);
    const ENBConfigurationUpdate *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC ENBConfigurationUpdateAcknowledge_PDU : public ConcretePDU {
public:
    ENBConfigurationUpdateAcknowledge_PDU();
    void set_data(ENBConfigurationUpdateAcknowledge &);
    ENBConfigurationUpdateAcknowledge *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const ENBConfigurationUpdateAcknowledge & d);
    const ENBConfigurationUpdateAcknowledge *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC ENBConfigurationUpdateFailure_PDU : public ConcretePDU {
public:
    ENBConfigurationUpdateFailure_PDU();
    void set_data(ENBConfigurationUpdateFailure &);
    ENBConfigurationUpdateFailure *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const ENBConfigurationUpdateFailure & d);
    const ENBConfigurationUpdateFailure *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC MMEConfigurationUpdate_PDU : public ConcretePDU {
public:
    MMEConfigurationUpdate_PDU();
    void set_data(MMEConfigurationUpdate &);
    MMEConfigurationUpdate *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const MMEConfigurationUpdate & d);
    const MMEConfigurationUpdate *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC MMEConfigurationUpdateAcknowledge_PDU : public ConcretePDU {
public:
    MMEConfigurationUpdateAcknowledge_PDU();
    void set_data(MMEConfigurationUpdateAcknowledge &);
    MMEConfigurationUpdateAcknowledge *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const MMEConfigurationUpdateAcknowledge & d);
    const MMEConfigurationUpdateAcknowledge *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC MMEConfigurationUpdateFailure_PDU : public ConcretePDU {
public:
    MMEConfigurationUpdateFailure_PDU();
    void set_data(MMEConfigurationUpdateFailure &);
    MMEConfigurationUpdateFailure *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const MMEConfigurationUpdateFailure & d);
    const MMEConfigurationUpdateFailure *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC DownlinkS1cdma2000tunnelling_PDU : public ConcretePDU {
public:
    DownlinkS1cdma2000tunnelling_PDU();
    void set_data(DownlinkS1cdma2000tunnelling &);
    DownlinkS1cdma2000tunnelling *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const DownlinkS1cdma2000tunnelling & d);
    const DownlinkS1cdma2000tunnelling *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC UplinkS1cdma2000tunnelling_PDU : public ConcretePDU {
public:
    UplinkS1cdma2000tunnelling_PDU();
    void set_data(UplinkS1cdma2000tunnelling &);
    UplinkS1cdma2000tunnelling *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const UplinkS1cdma2000tunnelling & d);
    const UplinkS1cdma2000tunnelling *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC UECapabilityInfoIndication_PDU : public ConcretePDU {
public:
    UECapabilityInfoIndication_PDU();
    void set_data(UECapabilityInfoIndication &);
    UECapabilityInfoIndication *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const UECapabilityInfoIndication & d);
    const UECapabilityInfoIndication *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC ENBStatusTransfer_PDU : public ConcretePDU {
public:
    ENBStatusTransfer_PDU();
    void set_data(ENBStatusTransfer &);
    ENBStatusTransfer *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const ENBStatusTransfer & d);
    const ENBStatusTransfer *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC MMEStatusTransfer_PDU : public ConcretePDU {
public:
    MMEStatusTransfer_PDU();
    void set_data(MMEStatusTransfer &);
    MMEStatusTransfer *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const MMEStatusTransfer & d);
    const MMEStatusTransfer *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC TraceStart_PDU : public ConcretePDU {
public:
    TraceStart_PDU();
    void set_data(TraceStart &);
    TraceStart *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const TraceStart & d);
    const TraceStart *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC TraceFailureIndication_PDU : public ConcretePDU {
public:
    TraceFailureIndication_PDU();
    void set_data(TraceFailureIndication &);
    TraceFailureIndication *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const TraceFailureIndication & d);
    const TraceFailureIndication *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC DeactivateTrace_PDU : public ConcretePDU {
public:
    DeactivateTrace_PDU();
    void set_data(DeactivateTrace &);
    DeactivateTrace *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const DeactivateTrace & d);
    const DeactivateTrace *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC CellTrafficTrace_PDU : public ConcretePDU {
public:
    CellTrafficTrace_PDU();
    void set_data(CellTrafficTrace &);
    CellTrafficTrace *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const CellTrafficTrace & d);
    const CellTrafficTrace *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC LocationReportingControl_PDU : public ConcretePDU {
public:
    LocationReportingControl_PDU();
    void set_data(LocationReportingControl &);
    LocationReportingControl *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const LocationReportingControl & d);
    const LocationReportingControl *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC LocationReportingFailureIndication_PDU : public ConcretePDU {
public:
    LocationReportingFailureIndication_PDU();
    void set_data(LocationReportingFailureIndication &);
    LocationReportingFailureIndication *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const LocationReportingFailureIndication & d);
    const LocationReportingFailureIndication *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC LocationReport_PDU : public ConcretePDU {
public:
    LocationReport_PDU();
    void set_data(LocationReport &);
    LocationReport *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const LocationReport & d);
    const LocationReport *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC OverloadStart_PDU : public ConcretePDU {
public:
    OverloadStart_PDU();
    void set_data(OverloadStart &);
    OverloadStart *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const OverloadStart & d);
    const OverloadStart *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC OverloadStop_PDU : public ConcretePDU {
public:
    OverloadStop_PDU();
    void set_data(OverloadStop &);
    OverloadStop *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const OverloadStop & d);
    const OverloadStop *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC WriteReplaceWarningRequest_PDU : public ConcretePDU {
public:
    WriteReplaceWarningRequest_PDU();
    void set_data(WriteReplaceWarningRequest &);
    WriteReplaceWarningRequest *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const WriteReplaceWarningRequest & d);
    const WriteReplaceWarningRequest *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC WriteReplaceWarningResponse_PDU : public ConcretePDU {
public:
    WriteReplaceWarningResponse_PDU();
    void set_data(WriteReplaceWarningResponse &);
    WriteReplaceWarningResponse *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const WriteReplaceWarningResponse & d);
    const WriteReplaceWarningResponse *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC ENBDirectInformationTransfer_PDU : public ConcretePDU {
public:
    ENBDirectInformationTransfer_PDU();
    void set_data(ENBDirectInformationTransfer &);
    ENBDirectInformationTransfer *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const ENBDirectInformationTransfer & d);
    const ENBDirectInformationTransfer *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC Inter_SystemInformationTransferType_PDU : public ConcretePDU {
public:
    Inter_SystemInformationTransferType_PDU();
    void set_data(Inter_SystemInformationTransferType &);
    Inter_SystemInformationTransferType *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const Inter_SystemInformationTransferType & d);
    const Inter_SystemInformationTransferType *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC MMEDirectInformationTransfer_PDU : public ConcretePDU {
public:
    MMEDirectInformationTransfer_PDU();
    void set_data(MMEDirectInformationTransfer &);
    MMEDirectInformationTransfer *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const MMEDirectInformationTransfer & d);
    const MMEDirectInformationTransfer *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC ENBConfigurationTransfer_PDU : public ConcretePDU {
public:
    ENBConfigurationTransfer_PDU();
    void set_data(ENBConfigurationTransfer &);
    ENBConfigurationTransfer *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const ENBConfigurationTransfer & d);
    const ENBConfigurationTransfer *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC MMEConfigurationTransfer_PDU : public ConcretePDU {
public:
    MMEConfigurationTransfer_PDU();
    void set_data(MMEConfigurationTransfer &);
    MMEConfigurationTransfer *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const MMEConfigurationTransfer & d);
    const MMEConfigurationTransfer *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC PrivateMessage_PDU : public ConcretePDU {
public:
    PrivateMessage_PDU();
    void set_data(PrivateMessage &);
    PrivateMessage *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const PrivateMessage & d);
    const PrivateMessage *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC KillRequest_PDU : public ConcretePDU {
public:
    KillRequest_PDU();
    void set_data(KillRequest &);
    KillRequest *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const KillRequest & d);
    const KillRequest *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC KillResponse_PDU : public ConcretePDU {
public:
    KillResponse_PDU();
    void set_data(KillResponse &);
    KillResponse *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const KillResponse & d);
    const KillResponse *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC PWSRestartIndication_PDU : public ConcretePDU {
public:
    PWSRestartIndication_PDU();
    void set_data(PWSRestartIndication &);
    PWSRestartIndication *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const PWSRestartIndication & d);
    const PWSRestartIndication *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC PWSFailureIndication_PDU : public ConcretePDU {
public:
    PWSFailureIndication_PDU();
    void set_data(PWSFailureIndication &);
    PWSFailureIndication *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const PWSFailureIndication & d);
    const PWSFailureIndication *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC DownlinkUEAssociatedLPPaTransport_PDU : public ConcretePDU {
public:
    DownlinkUEAssociatedLPPaTransport_PDU();
    void set_data(DownlinkUEAssociatedLPPaTransport &);
    DownlinkUEAssociatedLPPaTransport *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const DownlinkUEAssociatedLPPaTransport & d);
    const DownlinkUEAssociatedLPPaTransport *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC UplinkUEAssociatedLPPaTransport_PDU : public ConcretePDU {
public:
    UplinkUEAssociatedLPPaTransport_PDU();
    void set_data(UplinkUEAssociatedLPPaTransport &);
    UplinkUEAssociatedLPPaTransport *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const UplinkUEAssociatedLPPaTransport & d);
    const UplinkUEAssociatedLPPaTransport *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC DownlinkNonUEAssociatedLPPaTransport_PDU : public ConcretePDU {
public:
    DownlinkNonUEAssociatedLPPaTransport_PDU();
    void set_data(DownlinkNonUEAssociatedLPPaTransport &);
    DownlinkNonUEAssociatedLPPaTransport *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const DownlinkNonUEAssociatedLPPaTransport & d);
    const DownlinkNonUEAssociatedLPPaTransport *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC UplinkNonUEAssociatedLPPaTransport_PDU : public ConcretePDU {
public:
    UplinkNonUEAssociatedLPPaTransport_PDU();
    void set_data(UplinkNonUEAssociatedLPPaTransport &);
    UplinkNonUEAssociatedLPPaTransport *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const UplinkNonUEAssociatedLPPaTransport & d);
    const UplinkNonUEAssociatedLPPaTransport *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC E_RABModificationIndication_PDU : public ConcretePDU {
public:
    E_RABModificationIndication_PDU();
    void set_data(E_RABModificationIndication &);
    E_RABModificationIndication *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const E_RABModificationIndication & d);
    const E_RABModificationIndication *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC E_RABToBeModifiedListBearerModInd_PDU : public ConcretePDU {
public:
    E_RABToBeModifiedListBearerModInd_PDU();
    void set_data(E_RABToBeModifiedListBearerModInd &);
    E_RABToBeModifiedListBearerModInd *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const E_RABToBeModifiedListBearerModInd & d);
    const E_RABToBeModifiedListBearerModInd *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC E_RABToBeModifiedItemBearerModInd_PDU : public ConcretePDU {
public:
    E_RABToBeModifiedItemBearerModInd_PDU();
    void set_data(E_RABToBeModifiedItemBearerModInd &);
    E_RABToBeModifiedItemBearerModInd *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const E_RABToBeModifiedItemBearerModInd & d);
    const E_RABToBeModifiedItemBearerModInd *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC E_RABNotToBeModifiedListBearerModInd_PDU : public ConcretePDU {
public:
    E_RABNotToBeModifiedListBearerModInd_PDU();
    void set_data(E_RABNotToBeModifiedListBearerModInd &);
    E_RABNotToBeModifiedListBearerModInd *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const E_RABNotToBeModifiedListBearerModInd & d);
    const E_RABNotToBeModifiedListBearerModInd *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC E_RABNotToBeModifiedItemBearerModInd_PDU : public ConcretePDU {
public:
    E_RABNotToBeModifiedItemBearerModInd_PDU();
    void set_data(E_RABNotToBeModifiedItemBearerModInd &);
    E_RABNotToBeModifiedItemBearerModInd *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const E_RABNotToBeModifiedItemBearerModInd & d);
    const E_RABNotToBeModifiedItemBearerModInd *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC CSGMembershipInfo_PDU : public ConcretePDU {
public:
    CSGMembershipInfo_PDU();
    void set_data(CSGMembershipInfo &);
    CSGMembershipInfo *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const CSGMembershipInfo & d);
    const CSGMembershipInfo *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC E_RABModificationConfirm_PDU : public ConcretePDU {
public:
    E_RABModificationConfirm_PDU();
    void set_data(E_RABModificationConfirm &);
    E_RABModificationConfirm *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const E_RABModificationConfirm & d);
    const E_RABModificationConfirm *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC E_RABModifyListBearerModConf_PDU : public ConcretePDU {
public:
    E_RABModifyListBearerModConf_PDU();
    void set_data(E_RABModifyListBearerModConf &);
    E_RABModifyListBearerModConf *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const E_RABModifyListBearerModConf & d);
    const E_RABModifyListBearerModConf *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC E_RABModifyItemBearerModConf_PDU : public ConcretePDU {
public:
    E_RABModifyItemBearerModConf_PDU();
    void set_data(E_RABModifyItemBearerModConf &);
    E_RABModifyItemBearerModConf *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const E_RABModifyItemBearerModConf & d);
    const E_RABModifyItemBearerModConf *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC UEContextModificationIndication_PDU : public ConcretePDU {
public:
    UEContextModificationIndication_PDU();
    void set_data(UEContextModificationIndication &);
    UEContextModificationIndication *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const UEContextModificationIndication & d);
    const UEContextModificationIndication *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC UEContextModificationConfirm_PDU : public ConcretePDU {
public:
    UEContextModificationConfirm_PDU();
    void set_data(UEContextModificationConfirm &);
    UEContextModificationConfirm *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const UEContextModificationConfirm & d);
    const UEContextModificationConfirm *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC UEContextSuspendRequest_PDU : public ConcretePDU {
public:
    UEContextSuspendRequest_PDU();
    void set_data(UEContextSuspendRequest &);
    UEContextSuspendRequest *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const UEContextSuspendRequest & d);
    const UEContextSuspendRequest *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC UEContextSuspendResponse_PDU : public ConcretePDU {
public:
    UEContextSuspendResponse_PDU();
    void set_data(UEContextSuspendResponse &);
    UEContextSuspendResponse *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const UEContextSuspendResponse & d);
    const UEContextSuspendResponse *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC UEContextResumeRequest_PDU : public ConcretePDU {
public:
    UEContextResumeRequest_PDU();
    void set_data(UEContextResumeRequest &);
    UEContextResumeRequest *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const UEContextResumeRequest & d);
    const UEContextResumeRequest *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC E_RABFailedToResumeListResumeReq_PDU : public ConcretePDU {
public:
    E_RABFailedToResumeListResumeReq_PDU();
    void set_data(E_RABFailedToResumeListResumeReq &);
    E_RABFailedToResumeListResumeReq *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const E_RABFailedToResumeListResumeReq & d);
    const E_RABFailedToResumeListResumeReq *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC E_RABFailedToResumeItemResumeReq_PDU : public ConcretePDU {
public:
    E_RABFailedToResumeItemResumeReq_PDU();
    void set_data(E_RABFailedToResumeItemResumeReq &);
    E_RABFailedToResumeItemResumeReq *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const E_RABFailedToResumeItemResumeReq & d);
    const E_RABFailedToResumeItemResumeReq *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC UEContextResumeResponse_PDU : public ConcretePDU {
public:
    UEContextResumeResponse_PDU();
    void set_data(UEContextResumeResponse &);
    UEContextResumeResponse *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const UEContextResumeResponse & d);
    const UEContextResumeResponse *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC E_RABFailedToResumeListResumeRes_PDU : public ConcretePDU {
public:
    E_RABFailedToResumeListResumeRes_PDU();
    void set_data(E_RABFailedToResumeListResumeRes &);
    E_RABFailedToResumeListResumeRes *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const E_RABFailedToResumeListResumeRes & d);
    const E_RABFailedToResumeListResumeRes *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC E_RABFailedToResumeItemResumeRes_PDU : public ConcretePDU {
public:
    E_RABFailedToResumeItemResumeRes_PDU();
    void set_data(E_RABFailedToResumeItemResumeRes &);
    E_RABFailedToResumeItemResumeRes *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const E_RABFailedToResumeItemResumeRes & d);
    const E_RABFailedToResumeItemResumeRes *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC UEContextResumeFailure_PDU : public ConcretePDU {
public:
    UEContextResumeFailure_PDU();
    void set_data(UEContextResumeFailure &);
    UEContextResumeFailure *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const UEContextResumeFailure & d);
    const UEContextResumeFailure *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC ConnectionEstablishmentIndication_PDU : public ConcretePDU {
public:
    ConnectionEstablishmentIndication_PDU();
    void set_data(ConnectionEstablishmentIndication &);
    ConnectionEstablishmentIndication *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const ConnectionEstablishmentIndication & d);
    const ConnectionEstablishmentIndication *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC Additional_GUTI_PDU : public ConcretePDU {
public:
    Additional_GUTI_PDU();
    void set_data(Additional_GUTI &);
    Additional_GUTI *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const Additional_GUTI & d);
    const Additional_GUTI *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC AssistanceDataForPaging_PDU : public ConcretePDU {
public:
    AssistanceDataForPaging_PDU();
    void set_data(AssistanceDataForPaging &);
    AssistanceDataForPaging *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const AssistanceDataForPaging & d);
    const AssistanceDataForPaging *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC Bearers_SubjectToStatusTransfer_Item_PDU : public ConcretePDU {
public:
    Bearers_SubjectToStatusTransfer_Item_PDU();
    void set_data(Bearers_SubjectToStatusTransfer_Item &);
    Bearers_SubjectToStatusTransfer_Item *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const Bearers_SubjectToStatusTransfer_Item & d);
    const Bearers_SubjectToStatusTransfer_Item *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC BearerType_PDU : public ConcretePDU {
public:
    BearerType_PDU();
    void set_data(BearerType &);
    BearerType *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const BearerType & d);
    const BearerType *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC BroadcastCancelledAreaList_PDU : public ConcretePDU {
public:
    BroadcastCancelledAreaList_PDU();
    void set_data(BroadcastCancelledAreaList &);
    BroadcastCancelledAreaList *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const BroadcastCancelledAreaList & d);
    const BroadcastCancelledAreaList *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC BroadcastCompletedAreaList_PDU : public ConcretePDU {
public:
    BroadcastCompletedAreaList_PDU();
    void set_data(BroadcastCompletedAreaList &);
    BroadcastCompletedAreaList *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const BroadcastCompletedAreaList & d);
    const BroadcastCompletedAreaList *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC Cause_PDU : public ConcretePDU {
public:
    Cause_PDU();
    void set_data(Cause &);
    Cause *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const Cause & d);
    const Cause *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC CellAccessMode_PDU : public ConcretePDU {
public:
    CellAccessMode_PDU();
    void set_data(CellAccessMode &);
    CellAccessMode *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const CellAccessMode & d);
    const CellAccessMode *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC CellIdentifierAndCELevelForCECapableUEs_PDU : public ConcretePDU {
public:
    CellIdentifierAndCELevelForCECapableUEs_PDU();
    void set_data(CellIdentifierAndCELevelForCECapableUEs &);
    CellIdentifierAndCELevelForCECapableUEs *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const CellIdentifierAndCELevelForCECapableUEs & d);
    const CellIdentifierAndCELevelForCECapableUEs *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC CE_mode_B_SupportIndicator_PDU : public ConcretePDU {
public:
    CE_mode_B_SupportIndicator_PDU();
    void set_data(CE_mode_B_SupportIndicator &);
    CE_mode_B_SupportIndicator *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const CE_mode_B_SupportIndicator & d);
    const CE_mode_B_SupportIndicator *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC Cdma2000PDU_PDU : public ConcretePDU {
public:
    Cdma2000PDU_PDU();
    void set_data(Cdma2000PDU &);
    Cdma2000PDU *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const Cdma2000PDU & d);
    const Cdma2000PDU *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC Cdma2000RATType_PDU : public ConcretePDU {
public:
    Cdma2000RATType_PDU();
    void set_data(Cdma2000RATType &);
    Cdma2000RATType *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const Cdma2000RATType & d);
    const Cdma2000RATType *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC Cdma2000SectorID_PDU : public ConcretePDU {
public:
    Cdma2000SectorID_PDU();
    void set_data(Cdma2000SectorID &);
    Cdma2000SectorID *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const Cdma2000SectorID & d);
    const Cdma2000SectorID *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC Cdma2000HOStatus_PDU : public ConcretePDU {
public:
    Cdma2000HOStatus_PDU();
    void set_data(Cdma2000HOStatus &);
    Cdma2000HOStatus *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const Cdma2000HOStatus & d);
    const Cdma2000HOStatus *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC Cdma2000HORequiredIndication_PDU : public ConcretePDU {
public:
    Cdma2000HORequiredIndication_PDU();
    void set_data(Cdma2000HORequiredIndication &);
    Cdma2000HORequiredIndication *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const Cdma2000HORequiredIndication & d);
    const Cdma2000HORequiredIndication *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC Cdma2000OneXSRVCCInfo_PDU : public ConcretePDU {
public:
    Cdma2000OneXSRVCCInfo_PDU();
    void set_data(Cdma2000OneXSRVCCInfo &);
    Cdma2000OneXSRVCCInfo *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const Cdma2000OneXSRVCCInfo & d);
    const Cdma2000OneXSRVCCInfo *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC Cdma2000OneXRAND_PDU : public ConcretePDU {
public:
    Cdma2000OneXRAND_PDU();
    void set_data(Cdma2000OneXRAND &);
    Cdma2000OneXRAND *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const Cdma2000OneXRAND & d);
    const Cdma2000OneXRAND *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC CNDomain_PDU : public ConcretePDU {
public:
    CNDomain_PDU();
    void set_data(CNDomain &);
    CNDomain *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const CNDomain & d);
    const CNDomain *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC ConcurrentWarningMessageIndicator_PDU : public ConcretePDU {
public:
    ConcurrentWarningMessageIndicator_PDU();
    void set_data(ConcurrentWarningMessageIndicator &);
    ConcurrentWarningMessageIndicator *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const ConcurrentWarningMessageIndicator & d);
    const ConcurrentWarningMessageIndicator *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC Correlation_ID_PDU : public ConcretePDU {
public:
    Correlation_ID_PDU();
    void set_data(Correlation_ID &);
    Correlation_ID *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const Correlation_ID & d);
    const Correlation_ID *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC CSFallbackIndicator_PDU : public ConcretePDU {
public:
    CSFallbackIndicator_PDU();
    void set_data(CSFallbackIndicator &);
    CSFallbackIndicator *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const CSFallbackIndicator & d);
    const CSFallbackIndicator *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC AdditionalCSFallbackIndicator_PDU : public ConcretePDU {
public:
    AdditionalCSFallbackIndicator_PDU();
    void set_data(AdditionalCSFallbackIndicator &);
    AdditionalCSFallbackIndicator *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const AdditionalCSFallbackIndicator & d);
    const AdditionalCSFallbackIndicator *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC CSG_Id_PDU : public ConcretePDU {
public:
    CSG_Id_PDU();
    void set_data(CSG_Id &);
    CSG_Id *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const CSG_Id & d);
    const CSG_Id *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC CSG_IdList_PDU : public ConcretePDU {
public:
    CSG_IdList_PDU();
    void set_data(CSG_IdList &);
    CSG_IdList *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const CSG_IdList & d);
    const CSG_IdList *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC CSGMembershipStatus_PDU : public ConcretePDU {
public:
    CSGMembershipStatus_PDU();
    void set_data(CSGMembershipStatus &);
    CSGMembershipStatus *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const CSGMembershipStatus & d);
    const CSGMembershipStatus *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC COUNTValueExtended_PDU : public ConcretePDU {
public:
    COUNTValueExtended_PDU();
    void set_data(COUNTValueExtended &);
    COUNTValueExtended *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const COUNTValueExtended & d);
    const COUNTValueExtended *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC COUNTvaluePDCP_SNlength18_PDU : public ConcretePDU {
public:
    COUNTvaluePDCP_SNlength18_PDU();
    void set_data(COUNTvaluePDCP_SNlength18 &);
    COUNTvaluePDCP_SNlength18 *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const COUNTvaluePDCP_SNlength18 & d);
    const COUNTvaluePDCP_SNlength18 *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC CriticalityDiagnostics_PDU : public ConcretePDU {
public:
    CriticalityDiagnostics_PDU();
    void set_data(CriticalityDiagnostics &);
    CriticalityDiagnostics *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const CriticalityDiagnostics & d);
    const CriticalityDiagnostics *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC DataCodingScheme_PDU : public ConcretePDU {
public:
    DataCodingScheme_PDU();
    void set_data(DataCodingScheme &);
    DataCodingScheme *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const DataCodingScheme & d);
    const DataCodingScheme *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC Direct_Forwarding_Path_Availability_PDU : public ConcretePDU {
public:
    Direct_Forwarding_Path_Availability_PDU();
    void set_data(Direct_Forwarding_Path_Availability &);
    Direct_Forwarding_Path_Availability *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const Direct_Forwarding_Path_Availability & d);
    const Direct_Forwarding_Path_Availability *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC Data_Forwarding_Not_Possible_PDU : public ConcretePDU {
public:
    Data_Forwarding_Not_Possible_PDU();
    void set_data(Data_Forwarding_Not_Possible &);
    Data_Forwarding_Not_Possible *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const Data_Forwarding_Not_Possible & d);
    const Data_Forwarding_Not_Possible *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC PWSfailedECGIList_PDU : public ConcretePDU {
public:
    PWSfailedECGIList_PDU();
    void set_data(PWSfailedECGIList &);
    PWSfailedECGIList *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const PWSfailedECGIList & d);
    const PWSfailedECGIList *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC EmergencyAreaIDListForRestart_PDU : public ConcretePDU {
public:
    EmergencyAreaIDListForRestart_PDU();
    void set_data(EmergencyAreaIDListForRestart &);
    EmergencyAreaIDListForRestart *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const EmergencyAreaIDListForRestart & d);
    const EmergencyAreaIDListForRestart *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC Global_ENB_ID_PDU : public ConcretePDU {
public:
    Global_ENB_ID_PDU();
    void set_data(Global_ENB_ID &);
    Global_ENB_ID *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const Global_ENB_ID & d);
    const Global_ENB_ID *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC GUMMEIList_PDU : public ConcretePDU {
public:
    GUMMEIList_PDU();
    void set_data(GUMMEIList &);
    GUMMEIList *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const GUMMEIList & d);
    const GUMMEIList *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC ENB_StatusTransfer_TransparentContainer_PDU : public ConcretePDU {
public:
    ENB_StatusTransfer_TransparentContainer_PDU();
    void set_data(ENB_StatusTransfer_TransparentContainer &);
    ENB_StatusTransfer_TransparentContainer *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const ENB_StatusTransfer_TransparentContainer & d);
    const ENB_StatusTransfer_TransparentContainer *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC ENB_UE_S1AP_ID_PDU : public ConcretePDU {
public:
    ENB_UE_S1AP_ID_PDU();
    void set_data(ENB_UE_S1AP_ID &);
    ENB_UE_S1AP_ID *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const ENB_UE_S1AP_ID & d);
    const ENB_UE_S1AP_ID *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC ENBname_PDU : public ConcretePDU {
public:
    ENBname_PDU();
    void set_data(ENBname &);
    ENBname *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const ENBname & d);
    const ENBname *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC E_RABInformationListItem_PDU : public ConcretePDU {
public:
    E_RABInformationListItem_PDU();
    void set_data(E_RABInformationListItem &);
    E_RABInformationListItem *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const E_RABInformationListItem & d);
    const E_RABInformationListItem *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC E_RABList_PDU : public ConcretePDU {
public:
    E_RABList_PDU();
    void set_data(E_RABList &);
    E_RABList *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const E_RABList & d);
    const E_RABList *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC E_RABItem_PDU : public ConcretePDU {
public:
    E_RABItem_PDU();
    void set_data(E_RABItem &);
    E_RABItem *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const E_RABItem & d);
    const E_RABItem *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC EUTRAN_CGI_PDU : public ConcretePDU {
public:
    EUTRAN_CGI_PDU();
    void set_data(EUTRAN_CGI &);
    EUTRAN_CGI *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const EUTRAN_CGI & d);
    const EUTRAN_CGI *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC EUTRANRoundTripDelayEstimationInfo_PDU : public ConcretePDU {
public:
    EUTRANRoundTripDelayEstimationInfo_PDU();
    void set_data(EUTRANRoundTripDelayEstimationInfo &);
    EUTRANRoundTripDelayEstimationInfo *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const EUTRANRoundTripDelayEstimationInfo & d);
    const EUTRANRoundTripDelayEstimationInfo *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC ExpectedUEBehaviour_PDU : public ConcretePDU {
public:
    ExpectedUEBehaviour_PDU();
    void set_data(ExpectedUEBehaviour &);
    ExpectedUEBehaviour *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const ExpectedUEBehaviour & d);
    const ExpectedUEBehaviour *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC ExtendedRepetitionPeriod_PDU : public ConcretePDU {
public:
    ExtendedRepetitionPeriod_PDU();
    void set_data(ExtendedRepetitionPeriod &);
    ExtendedRepetitionPeriod *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const ExtendedRepetitionPeriod & d);
    const ExtendedRepetitionPeriod *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC Extended_UEIdentityIndexValue_PDU : public ConcretePDU {
public:
    Extended_UEIdentityIndexValue_PDU();
    void set_data(Extended_UEIdentityIndexValue &);
    Extended_UEIdentityIndexValue *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const Extended_UEIdentityIndexValue & d);
    const Extended_UEIdentityIndexValue *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC GUMMEI_PDU : public ConcretePDU {
public:
    GUMMEI_PDU();
    void set_data(GUMMEI &);
    GUMMEI *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const GUMMEI & d);
    const GUMMEI *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC GUMMEIType_PDU : public ConcretePDU {
public:
    GUMMEIType_PDU();
    void set_data(GUMMEIType &);
    GUMMEIType *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const GUMMEIType & d);
    const GUMMEIType *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC GWContextReleaseIndication_PDU : public ConcretePDU {
public:
    GWContextReleaseIndication_PDU();
    void set_data(GWContextReleaseIndication &);
    GWContextReleaseIndication *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const GWContextReleaseIndication & d);
    const GWContextReleaseIndication *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC HandoverRestrictionList_PDU : public ConcretePDU {
public:
    HandoverRestrictionList_PDU();
    void set_data(HandoverRestrictionList &);
    HandoverRestrictionList *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const HandoverRestrictionList & d);
    const HandoverRestrictionList *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC HandoverType_PDU : public ConcretePDU {
public:
    HandoverType_PDU();
    void set_data(HandoverType &);
    HandoverType *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const HandoverType & d);
    const HandoverType *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC Masked_IMEISV_PDU : public ConcretePDU {
public:
    Masked_IMEISV_PDU();
    void set_data(Masked_IMEISV &);
    Masked_IMEISV *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const Masked_IMEISV & d);
    const Masked_IMEISV *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC InformationOnRecommendedCellsAndENBsForPaging_PDU : public ConcretePDU {
public:
    InformationOnRecommendedCellsAndENBsForPaging_PDU();
    void set_data(InformationOnRecommendedCellsAndENBsForPaging &);
    InformationOnRecommendedCellsAndENBsForPaging *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const InformationOnRecommendedCellsAndENBsForPaging & d);
    const InformationOnRecommendedCellsAndENBsForPaging *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC KillAllWarningMessages_PDU : public ConcretePDU {
public:
    KillAllWarningMessages_PDU();
    void set_data(KillAllWarningMessages &);
    KillAllWarningMessages *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const KillAllWarningMessages & d);
    const KillAllWarningMessages *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC LAI_PDU : public ConcretePDU {
public:
    LAI_PDU();
    void set_data(LAI &);
    LAI *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const LAI & d);
    const LAI *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC L3_Information_PDU : public ConcretePDU {
public:
    L3_Information_PDU();
    void set_data(L3_Information &);
    L3_Information *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const L3_Information & d);
    const L3_Information *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC LPPa_PDU_PDU : public ConcretePDU {
public:
    LPPa_PDU_PDU();
    void set_data(LPPa_PDU &);
    LPPa_PDU *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const LPPa_PDU & d);
    const LPPa_PDU *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC LHN_ID_PDU : public ConcretePDU {
public:
    LHN_ID_PDU();
    void set_data(LHN_ID &);
    LHN_ID *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const LHN_ID & d);
    const LHN_ID *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC LoggedMBSFNMDT_PDU : public ConcretePDU {
public:
    LoggedMBSFNMDT_PDU();
    void set_data(LoggedMBSFNMDT &);
    LoggedMBSFNMDT *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const LoggedMBSFNMDT & d);
    const LoggedMBSFNMDT *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC M3Configuration_PDU : public ConcretePDU {
public:
    M3Configuration_PDU();
    void set_data(M3Configuration &);
    M3Configuration *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const M3Configuration & d);
    const M3Configuration *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC M4Configuration_PDU : public ConcretePDU {
public:
    M4Configuration_PDU();
    void set_data(M4Configuration &);
    M4Configuration *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const M4Configuration & d);
    const M4Configuration *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC M5Configuration_PDU : public ConcretePDU {
public:
    M5Configuration_PDU();
    void set_data(M5Configuration &);
    M5Configuration *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const M5Configuration & d);
    const M5Configuration *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC M6Configuration_PDU : public ConcretePDU {
public:
    M6Configuration_PDU();
    void set_data(M6Configuration &);
    M6Configuration *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const M6Configuration & d);
    const M6Configuration *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC M7Configuration_PDU : public ConcretePDU {
public:
    M7Configuration_PDU();
    void set_data(M7Configuration &);
    M7Configuration *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const M7Configuration & d);
    const M7Configuration *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC MDT_Location_Info_PDU : public ConcretePDU {
public:
    MDT_Location_Info_PDU();
    void set_data(MDT_Location_Info &);
    MDT_Location_Info *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const MDT_Location_Info & d);
    const MDT_Location_Info *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC MDT_Configuration_PDU : public ConcretePDU {
public:
    MDT_Configuration_PDU();
    void set_data(MDT_Configuration &);
    MDT_Configuration *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const MDT_Configuration & d);
    const MDT_Configuration *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC ManagementBasedMDTAllowed_PDU : public ConcretePDU {
public:
    ManagementBasedMDTAllowed_PDU();
    void set_data(ManagementBasedMDTAllowed &);
    ManagementBasedMDTAllowed *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const ManagementBasedMDTAllowed & d);
    const ManagementBasedMDTAllowed *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC MDTPLMNList_PDU : public ConcretePDU {
public:
    MDTPLMNList_PDU();
    void set_data(MDTPLMNList &);
    MDTPLMNList *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const MDTPLMNList & d);
    const MDTPLMNList *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC PrivacyIndicator_PDU : public ConcretePDU {
public:
    PrivacyIndicator_PDU();
    void set_data(PrivacyIndicator &);
    PrivacyIndicator *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const PrivacyIndicator & d);
    const PrivacyIndicator *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC MessageIdentifier_PDU : public ConcretePDU {
public:
    MessageIdentifier_PDU();
    void set_data(MessageIdentifier &);
    MessageIdentifier *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const MessageIdentifier & d);
    const MessageIdentifier *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC S1AP_IEs_MobilityInformation_PDU : public ConcretePDU {
public:
    S1AP_IEs_MobilityInformation_PDU();
    void set_data(S1AP_IEs_MobilityInformation &);
    S1AP_IEs_MobilityInformation *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const S1AP_IEs_MobilityInformation & d);
    const S1AP_IEs_MobilityInformation *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC MMEname_PDU : public ConcretePDU {
public:
    MMEname_PDU();
    void set_data(MMEname &);
    MMEname *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const MMEname & d);
    const MMEname *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC MMERelaySupportIndicator_PDU : public ConcretePDU {
public:
    MMERelaySupportIndicator_PDU();
    void set_data(MMERelaySupportIndicator &);
    MMERelaySupportIndicator *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const MMERelaySupportIndicator & d);
    const MMERelaySupportIndicator *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC MME_Group_ID_PDU : public ConcretePDU {
public:
    MME_Group_ID_PDU();
    void set_data(MME_Group_ID &);
    MME_Group_ID *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const MME_Group_ID & d);
    const MME_Group_ID *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC MME_UE_S1AP_ID_PDU : public ConcretePDU {
public:
    MME_UE_S1AP_ID_PDU();
    void set_data(MME_UE_S1AP_ID &);
    MME_UE_S1AP_ID *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const MME_UE_S1AP_ID & d);
    const MME_UE_S1AP_ID *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC MSClassmark2_PDU : public ConcretePDU {
public:
    MSClassmark2_PDU();
    void set_data(MSClassmark2 &);
    MSClassmark2 *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const MSClassmark2 & d);
    const MSClassmark2 *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC MSClassmark3_PDU : public ConcretePDU {
public:
    MSClassmark3_PDU();
    void set_data(MSClassmark3 &);
    MSClassmark3 *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const MSClassmark3 & d);
    const MSClassmark3 *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC MutingAvailabilityIndication_PDU : public ConcretePDU {
public:
    MutingAvailabilityIndication_PDU();
    void set_data(MutingAvailabilityIndication &);
    MutingAvailabilityIndication *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const MutingAvailabilityIndication & d);
    const MutingAvailabilityIndication *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC MutingPatternInformation_PDU : public ConcretePDU {
public:
    MutingPatternInformation_PDU();
    void set_data(MutingPatternInformation &);
    MutingPatternInformation *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const MutingPatternInformation & d);
    const MutingPatternInformation *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC NAS_PDU_PDU : public ConcretePDU {
public:
    NAS_PDU_PDU();
    void set_data(NAS_PDU &);
    NAS_PDU *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const NAS_PDU & d);
    const NAS_PDU *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC NASSecurityParametersfromE_UTRAN_PDU : public ConcretePDU {
public:
    NASSecurityParametersfromE_UTRAN_PDU();
    void set_data(NASSecurityParametersfromE_UTRAN &);
    NASSecurityParametersfromE_UTRAN *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const NASSecurityParametersfromE_UTRAN & d);
    const NASSecurityParametersfromE_UTRAN *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC NASSecurityParameterstoE_UTRAN_PDU : public ConcretePDU {
public:
    NASSecurityParameterstoE_UTRAN_PDU();
    void set_data(NASSecurityParameterstoE_UTRAN &);
    NASSecurityParameterstoE_UTRAN *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const NASSecurityParameterstoE_UTRAN & d);
    const NASSecurityParameterstoE_UTRAN *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC NB_IoT_DefaultPagingDRX_PDU : public ConcretePDU {
public:
    NB_IoT_DefaultPagingDRX_PDU();
    void set_data(NB_IoT_DefaultPagingDRX &);
    NB_IoT_DefaultPagingDRX *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const NB_IoT_DefaultPagingDRX & d);
    const NB_IoT_DefaultPagingDRX *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC NB_IoT_Paging_eDRXInformation_PDU : public ConcretePDU {
public:
    NB_IoT_Paging_eDRXInformation_PDU();
    void set_data(NB_IoT_Paging_eDRXInformation &);
    NB_IoT_Paging_eDRXInformation *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const NB_IoT_Paging_eDRXInformation & d);
    const NB_IoT_Paging_eDRXInformation *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC NB_IoT_UEIdentityIndexValue_PDU : public ConcretePDU {
public:
    NB_IoT_UEIdentityIndexValue_PDU();
    void set_data(NB_IoT_UEIdentityIndexValue &);
    NB_IoT_UEIdentityIndexValue *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const NB_IoT_UEIdentityIndexValue & d);
    const NB_IoT_UEIdentityIndexValue *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC NumberofBroadcastRequest_PDU : public ConcretePDU {
public:
    NumberofBroadcastRequest_PDU();
    void set_data(NumberofBroadcastRequest &);
    NumberofBroadcastRequest *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const NumberofBroadcastRequest & d);
    const NumberofBroadcastRequest *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC OldBSS_ToNewBSS_Information_PDU : public ConcretePDU {
public:
    OldBSS_ToNewBSS_Information_PDU();
    void set_data(OldBSS_ToNewBSS_Information &);
    OldBSS_ToNewBSS_Information *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const OldBSS_ToNewBSS_Information & d);
    const OldBSS_ToNewBSS_Information *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC OverloadResponse_PDU : public ConcretePDU {
public:
    OverloadResponse_PDU();
    void set_data(OverloadResponse &);
    OverloadResponse *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const OverloadResponse & d);
    const OverloadResponse *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC Paging_eDRXInformation_PDU : public ConcretePDU {
public:
    Paging_eDRXInformation_PDU();
    void set_data(Paging_eDRXInformation &);
    Paging_eDRXInformation *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const Paging_eDRXInformation & d);
    const Paging_eDRXInformation *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC PagingDRX_PDU : public ConcretePDU {
public:
    PagingDRX_PDU();
    void set_data(PagingDRX &);
    PagingDRX *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const PagingDRX & d);
    const PagingDRX *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC PagingPriority_PDU : public ConcretePDU {
public:
    PagingPriority_PDU();
    void set_data(PagingPriority &);
    PagingPriority *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const PagingPriority & d);
    const PagingPriority *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC ProSeAuthorized_PDU : public ConcretePDU {
public:
    ProSeAuthorized_PDU();
    void set_data(ProSeAuthorized &);
    ProSeAuthorized *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const ProSeAuthorized & d);
    const ProSeAuthorized *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC ProSeUEtoNetworkRelaying_PDU : public ConcretePDU {
public:
    ProSeUEtoNetworkRelaying_PDU();
    void set_data(ProSeUEtoNetworkRelaying &);
    ProSeUEtoNetworkRelaying *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const ProSeUEtoNetworkRelaying & d);
    const ProSeUEtoNetworkRelaying *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC PS_ServiceNotAvailable_PDU : public ConcretePDU {
public:
    PS_ServiceNotAvailable_PDU();
    void set_data(PS_ServiceNotAvailable &);
    PS_ServiceNotAvailable *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const PS_ServiceNotAvailable & d);
    const PS_ServiceNotAvailable *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC ReceiveStatusOfULPDCPSDUsExtended_PDU : public ConcretePDU {
public:
    ReceiveStatusOfULPDCPSDUsExtended_PDU();
    void set_data(ReceiveStatusOfULPDCPSDUsExtended &);
    ReceiveStatusOfULPDCPSDUsExtended *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const ReceiveStatusOfULPDCPSDUsExtended & d);
    const ReceiveStatusOfULPDCPSDUsExtended *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC ReceiveStatusOfULPDCPSDUsPDCP_SNlength18_PDU : public ConcretePDU {
public:
    ReceiveStatusOfULPDCPSDUsPDCP_SNlength18_PDU();
    void set_data(ReceiveStatusOfULPDCPSDUsPDCP_SNlength18 &);
    ReceiveStatusOfULPDCPSDUsPDCP_SNlength18 *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const ReceiveStatusOfULPDCPSDUsPDCP_SNlength18 & d);
    const ReceiveStatusOfULPDCPSDUsPDCP_SNlength18 *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC RecommendedCellItem_PDU : public ConcretePDU {
public:
    RecommendedCellItem_PDU();
    void set_data(RecommendedCellItem &);
    RecommendedCellItem *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const RecommendedCellItem & d);
    const RecommendedCellItem *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC RecommendedENBItem_PDU : public ConcretePDU {
public:
    RecommendedENBItem_PDU();
    void set_data(RecommendedENBItem &);
    RecommendedENBItem *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const RecommendedENBItem & d);
    const RecommendedENBItem *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC RelativeMMECapacity_PDU : public ConcretePDU {
public:
    RelativeMMECapacity_PDU();
    void set_data(RelativeMMECapacity &);
    RelativeMMECapacity *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const RelativeMMECapacity & d);
    const RelativeMMECapacity *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC RelayNode_Indicator_PDU : public ConcretePDU {
public:
    RelayNode_Indicator_PDU();
    void set_data(RelayNode_Indicator &);
    RelayNode_Indicator *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const RelayNode_Indicator & d);
    const RelayNode_Indicator *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC RAT_Type_PDU : public ConcretePDU {
public:
    RAT_Type_PDU();
    void set_data(RAT_Type &);
    RAT_Type *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const RAT_Type & d);
    const RAT_Type *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC RequestType_PDU : public ConcretePDU {
public:
    RequestType_PDU();
    void set_data(RequestType &);
    RequestType *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const RequestType & d);
    const RequestType *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC RepetitionPeriod_PDU : public ConcretePDU {
public:
    RepetitionPeriod_PDU();
    void set_data(RepetitionPeriod &);
    RepetitionPeriod *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const RepetitionPeriod & d);
    const RepetitionPeriod *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC RRC_Establishment_Cause_PDU : public ConcretePDU {
public:
    RRC_Establishment_Cause_PDU();
    void set_data(RRC_Establishment_Cause &);
    RRC_Establishment_Cause *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const RRC_Establishment_Cause & d);
    const RRC_Establishment_Cause *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC ECGIListForRestart_PDU : public ConcretePDU {
public:
    ECGIListForRestart_PDU();
    void set_data(ECGIListForRestart &);
    ECGIListForRestart *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const ECGIListForRestart & d);
    const ECGIListForRestart *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC Routing_ID_PDU : public ConcretePDU {
public:
    Routing_ID_PDU();
    void set_data(Routing_ID &);
    Routing_ID *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const Routing_ID & d);
    const Routing_ID *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC SecurityKey_PDU : public ConcretePDU {
public:
    SecurityKey_PDU();
    void set_data(SecurityKey &);
    SecurityKey *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const SecurityKey & d);
    const SecurityKey *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC SecurityContext_PDU : public ConcretePDU {
public:
    SecurityContext_PDU();
    void set_data(SecurityContext &);
    SecurityContext *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const SecurityContext & d);
    const SecurityContext *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC SerialNumber_PDU : public ConcretePDU {
public:
    SerialNumber_PDU();
    void set_data(SerialNumber &);
    SerialNumber *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const SerialNumber & d);
    const SerialNumber *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC SONInformationReport_PDU : public ConcretePDU {
public:
    SONInformationReport_PDU();
    void set_data(SONInformationReport &);
    SONInformationReport *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const SONInformationReport & d);
    const SONInformationReport *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC SONConfigurationTransfer_PDU : public ConcretePDU {
public:
    SONConfigurationTransfer_PDU();
    void set_data(SONConfigurationTransfer &);
    SONConfigurationTransfer *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const SONConfigurationTransfer & d);
    const SONConfigurationTransfer *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC SynchronisationInformation_PDU : public ConcretePDU {
public:
    SynchronisationInformation_PDU();
    void set_data(SynchronisationInformation &);
    SynchronisationInformation *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const SynchronisationInformation & d);
    const SynchronisationInformation *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC Source_ToTarget_TransparentContainer_PDU : public ConcretePDU {
public:
    Source_ToTarget_TransparentContainer_PDU();
    void set_data(Source_ToTarget_TransparentContainer &);
    Source_ToTarget_TransparentContainer *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const Source_ToTarget_TransparentContainer & d);
    const Source_ToTarget_TransparentContainer *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC SourceBSS_ToTargetBSS_TransparentContainer_PDU : public ConcretePDU {
public:
    SourceBSS_ToTargetBSS_TransparentContainer_PDU();
    void set_data(SourceBSS_ToTargetBSS_TransparentContainer &);
    SourceBSS_ToTargetBSS_TransparentContainer *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const SourceBSS_ToTargetBSS_TransparentContainer & d);
    const SourceBSS_ToTargetBSS_TransparentContainer *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC SRVCCOperationNotPossible_PDU : public ConcretePDU {
public:
    SRVCCOperationNotPossible_PDU();
    void set_data(SRVCCOperationNotPossible &);
    SRVCCOperationNotPossible *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const SRVCCOperationNotPossible & d);
    const SRVCCOperationNotPossible *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC SRVCCOperationPossible_PDU : public ConcretePDU {
public:
    SRVCCOperationPossible_PDU();
    void set_data(SRVCCOperationPossible &);
    SRVCCOperationPossible *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const SRVCCOperationPossible & d);
    const SRVCCOperationPossible *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC SRVCCHOIndication_PDU : public ConcretePDU {
public:
    SRVCCHOIndication_PDU();
    void set_data(SRVCCHOIndication &);
    SRVCCHOIndication *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const SRVCCHOIndication & d);
    const SRVCCHOIndication *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC SourceeNB_ToTargeteNB_TransparentContainer_PDU : public ConcretePDU {
public:
    SourceeNB_ToTargeteNB_TransparentContainer_PDU();
    void set_data(SourceeNB_ToTargeteNB_TransparentContainer &);
    SourceeNB_ToTargeteNB_TransparentContainer *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const SourceeNB_ToTargeteNB_TransparentContainer & d);
    const SourceeNB_ToTargeteNB_TransparentContainer *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC SourceRNC_ToTargetRNC_TransparentContainer_PDU : public ConcretePDU {
public:
    SourceRNC_ToTargetRNC_TransparentContainer_PDU();
    void set_data(SourceRNC_ToTargetRNC_TransparentContainer &);
    SourceRNC_ToTargetRNC_TransparentContainer *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const SourceRNC_ToTargetRNC_TransparentContainer & d);
    const SourceRNC_ToTargetRNC_TransparentContainer *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC ServedGUMMEIs_PDU : public ConcretePDU {
public:
    ServedGUMMEIs_PDU();
    void set_data(ServedGUMMEIs &);
    ServedGUMMEIs *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const ServedGUMMEIs & d);
    const ServedGUMMEIs *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC SubscriberProfileIDforRFP_PDU : public ConcretePDU {
public:
    SubscriberProfileIDforRFP_PDU();
    void set_data(SubscriberProfileIDforRFP &);
    SubscriberProfileIDforRFP *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const SubscriberProfileIDforRFP & d);
    const SubscriberProfileIDforRFP *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC SupportedTAs_PDU : public ConcretePDU {
public:
    SupportedTAs_PDU();
    void set_data(SupportedTAs &);
    SupportedTAs *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const SupportedTAs & d);
    const SupportedTAs *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC TimeSynchronisationInfo_PDU : public ConcretePDU {
public:
    TimeSynchronisationInfo_PDU();
    void set_data(TimeSynchronisationInfo &);
    TimeSynchronisationInfo *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const TimeSynchronisationInfo & d);
    const TimeSynchronisationInfo *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC S_TMSI_PDU : public ConcretePDU {
public:
    S_TMSI_PDU();
    void set_data(S_TMSI &);
    S_TMSI *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const S_TMSI & d);
    const S_TMSI *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC TAI_PDU : public ConcretePDU {
public:
    TAI_PDU();
    void set_data(TAI &);
    TAI *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const TAI & d);
    const TAI *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC TargetID_PDU : public ConcretePDU {
public:
    TargetID_PDU();
    void set_data(TargetID &);
    TargetID *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const TargetID & d);
    const TargetID *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC TargeteNB_ToSourceeNB_TransparentContainer_PDU : public ConcretePDU {
public:
    TargeteNB_ToSourceeNB_TransparentContainer_PDU();
    void set_data(TargeteNB_ToSourceeNB_TransparentContainer &);
    TargeteNB_ToSourceeNB_TransparentContainer *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const TargeteNB_ToSourceeNB_TransparentContainer & d);
    const TargeteNB_ToSourceeNB_TransparentContainer *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC Target_ToSource_TransparentContainer_PDU : public ConcretePDU {
public:
    Target_ToSource_TransparentContainer_PDU();
    void set_data(Target_ToSource_TransparentContainer &);
    Target_ToSource_TransparentContainer *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const Target_ToSource_TransparentContainer & d);
    const Target_ToSource_TransparentContainer *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC TargetRNC_ToSourceRNC_TransparentContainer_PDU : public ConcretePDU {
public:
    TargetRNC_ToSourceRNC_TransparentContainer_PDU();
    void set_data(TargetRNC_ToSourceRNC_TransparentContainer &);
    TargetRNC_ToSourceRNC_TransparentContainer *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const TargetRNC_ToSourceRNC_TransparentContainer & d);
    const TargetRNC_ToSourceRNC_TransparentContainer *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC TargetBSS_ToSourceBSS_TransparentContainer_PDU : public ConcretePDU {
public:
    TargetBSS_ToSourceBSS_TransparentContainer_PDU();
    void set_data(TargetBSS_ToSourceBSS_TransparentContainer &);
    TargetBSS_ToSourceBSS_TransparentContainer *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const TargetBSS_ToSourceBSS_TransparentContainer & d);
    const TargetBSS_ToSourceBSS_TransparentContainer *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC TimeToWait_PDU : public ConcretePDU {
public:
    TimeToWait_PDU();
    void set_data(TimeToWait &);
    TimeToWait *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const TimeToWait & d);
    const TimeToWait *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC Time_UE_StayedInCell_EnhancedGranularity_PDU : public ConcretePDU {
public:
    Time_UE_StayedInCell_EnhancedGranularity_PDU();
    void set_data(Time_UE_StayedInCell_EnhancedGranularity &);
    Time_UE_StayedInCell_EnhancedGranularity *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const Time_UE_StayedInCell_EnhancedGranularity & d);
    const Time_UE_StayedInCell_EnhancedGranularity *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC TransportInformation_PDU : public ConcretePDU {
public:
    TransportInformation_PDU();
    void set_data(TransportInformation &);
    TransportInformation *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const TransportInformation & d);
    const TransportInformation *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC TransportLayerAddress_PDU : public ConcretePDU {
public:
    TransportLayerAddress_PDU();
    void set_data(TransportLayerAddress &);
    TransportLayerAddress *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const TransportLayerAddress & d);
    const TransportLayerAddress *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC TraceActivation_PDU : public ConcretePDU {
public:
    TraceActivation_PDU();
    void set_data(TraceActivation &);
    TraceActivation *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const TraceActivation & d);
    const TraceActivation *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC E_UTRAN_Trace_ID_PDU : public ConcretePDU {
public:
    E_UTRAN_Trace_ID_PDU();
    void set_data(E_UTRAN_Trace_ID &);
    E_UTRAN_Trace_ID *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const E_UTRAN_Trace_ID & d);
    const E_UTRAN_Trace_ID *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC TrafficLoadReductionIndication_PDU : public ConcretePDU {
public:
    TrafficLoadReductionIndication_PDU();
    void set_data(TrafficLoadReductionIndication &);
    TrafficLoadReductionIndication *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const TrafficLoadReductionIndication & d);
    const TrafficLoadReductionIndication *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC TunnelInformation_PDU : public ConcretePDU {
public:
    TunnelInformation_PDU();
    void set_data(TunnelInformation &);
    TunnelInformation *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const TunnelInformation & d);
    const TunnelInformation *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC TAIListForRestart_PDU : public ConcretePDU {
public:
    TAIListForRestart_PDU();
    void set_data(TAIListForRestart &);
    TAIListForRestart *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const TAIListForRestart & d);
    const TAIListForRestart *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC UEAggregateMaximumBitrate_PDU : public ConcretePDU {
public:
    UEAggregateMaximumBitrate_PDU();
    void set_data(UEAggregateMaximumBitrate &);
    UEAggregateMaximumBitrate *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const UEAggregateMaximumBitrate & d);
    const UEAggregateMaximumBitrate *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC UE_RetentionInformation_PDU : public ConcretePDU {
public:
    UE_RetentionInformation_PDU();
    void set_data(UE_RetentionInformation &);
    UE_RetentionInformation *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const UE_RetentionInformation & d);
    const UE_RetentionInformation *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC UE_S1AP_IDs_PDU : public ConcretePDU {
public:
    UE_S1AP_IDs_PDU();
    void set_data(UE_S1AP_IDs &);
    UE_S1AP_IDs *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const UE_S1AP_IDs & d);
    const UE_S1AP_IDs *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC UE_associatedLogicalS1_ConnectionItem_PDU : public ConcretePDU {
public:
    UE_associatedLogicalS1_ConnectionItem_PDU();
    void set_data(UE_associatedLogicalS1_ConnectionItem &);
    UE_associatedLogicalS1_ConnectionItem *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const UE_associatedLogicalS1_ConnectionItem & d);
    const UE_associatedLogicalS1_ConnectionItem *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC UEIdentityIndexValue_PDU : public ConcretePDU {
public:
    UEIdentityIndexValue_PDU();
    void set_data(UEIdentityIndexValue &);
    UEIdentityIndexValue *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const UEIdentityIndexValue & d);
    const UEIdentityIndexValue *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC UE_HistoryInformationFromTheUE_PDU : public ConcretePDU {
public:
    UE_HistoryInformationFromTheUE_PDU();
    void set_data(UE_HistoryInformationFromTheUE &);
    UE_HistoryInformationFromTheUE *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const UE_HistoryInformationFromTheUE & d);
    const UE_HistoryInformationFromTheUE *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC UEPagingID_PDU : public ConcretePDU {
public:
    UEPagingID_PDU();
    void set_data(UEPagingID &);
    UEPagingID *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const UEPagingID & d);
    const UEPagingID *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC UERadioCapability_PDU : public ConcretePDU {
public:
    UERadioCapability_PDU();
    void set_data(UERadioCapability &);
    UERadioCapability *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const UERadioCapability & d);
    const UERadioCapability *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC UERadioCapabilityForPaging_PDU : public ConcretePDU {
public:
    UERadioCapabilityForPaging_PDU();
    void set_data(UERadioCapabilityForPaging &);
    UERadioCapabilityForPaging *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const UERadioCapabilityForPaging & d);
    const UERadioCapabilityForPaging *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC UESecurityCapabilities_PDU : public ConcretePDU {
public:
    UESecurityCapabilities_PDU();
    void set_data(UESecurityCapabilities &);
    UESecurityCapabilities *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const UESecurityCapabilities & d);
    const UESecurityCapabilities *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC UE_Usage_Type_PDU : public ConcretePDU {
public:
    UE_Usage_Type_PDU();
    void set_data(UE_Usage_Type &);
    UE_Usage_Type *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const UE_Usage_Type & d);
    const UE_Usage_Type *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC UserLocationInformation_PDU : public ConcretePDU {
public:
    UserLocationInformation_PDU();
    void set_data(UserLocationInformation &);
    UserLocationInformation *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const UserLocationInformation & d);
    const UserLocationInformation *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC UEUserPlaneCIoTSupportIndicator_PDU : public ConcretePDU {
public:
    UEUserPlaneCIoTSupportIndicator_PDU();
    void set_data(UEUserPlaneCIoTSupportIndicator &);
    UEUserPlaneCIoTSupportIndicator *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const UEUserPlaneCIoTSupportIndicator & d);
    const UEUserPlaneCIoTSupportIndicator *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC VoiceSupportMatchIndicator_PDU : public ConcretePDU {
public:
    VoiceSupportMatchIndicator_PDU();
    void set_data(VoiceSupportMatchIndicator &);
    VoiceSupportMatchIndicator *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const VoiceSupportMatchIndicator & d);
    const VoiceSupportMatchIndicator *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC WarningAreaList_PDU : public ConcretePDU {
public:
    WarningAreaList_PDU();
    void set_data(WarningAreaList &);
    WarningAreaList *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const WarningAreaList & d);
    const WarningAreaList *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC WarningType_PDU : public ConcretePDU {
public:
    WarningType_PDU();
    void set_data(WarningType &);
    WarningType *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const WarningType & d);
    const WarningType *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC WarningSecurityInfo_PDU : public ConcretePDU {
public:
    WarningSecurityInfo_PDU();
    void set_data(WarningSecurityInfo &);
    WarningSecurityInfo *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const WarningSecurityInfo & d);
    const WarningSecurityInfo *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC WarningMessageContents_PDU : public ConcretePDU {
public:
    WarningMessageContents_PDU();
    void set_data(WarningMessageContents &);
    WarningMessageContents *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const WarningMessageContents & d);
    const WarningMessageContents *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC X2TNLConfigurationInfo_PDU : public ConcretePDU {
public:
    X2TNLConfigurationInfo_PDU();
    void set_data(X2TNLConfigurationInfo &);
    X2TNLConfigurationInfo *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const X2TNLConfigurationInfo & d);
    const X2TNLConfigurationInfo *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC ENBX2ExtTLAs_PDU : public ConcretePDU {
public:
    ENBX2ExtTLAs_PDU();
    void set_data(ENBX2ExtTLAs &);
    ENBX2ExtTLAs *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const ENBX2ExtTLAs & d);
    const ENBX2ExtTLAs *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC ENBIndirectX2TransportLayerAddresses_PDU : public ConcretePDU {
public:
    ENBIndirectX2TransportLayerAddresses_PDU();
    void set_data(ENBIndirectX2TransportLayerAddresses &);
    ENBIndirectX2TransportLayerAddresses *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const ENBIndirectX2TransportLayerAddresses & d);
    const ENBIndirectX2TransportLayerAddresses *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC SONtransferApplicationIdentity_PDU : public ConcretePDU {
public:
    SONtransferApplicationIdentity_PDU();
    void set_data(SONtransferApplicationIdentity &);
    SONtransferApplicationIdentity *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const SONtransferApplicationIdentity & d);
    const SONtransferApplicationIdentity *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC SONtransferRequestContainer_PDU : public ConcretePDU {
public:
    SONtransferRequestContainer_PDU();
    void set_data(SONtransferRequestContainer &);
    SONtransferRequestContainer *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const SONtransferRequestContainer & d);
    const SONtransferRequestContainer *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC SONtransferResponseContainer_PDU : public ConcretePDU {
public:
    SONtransferResponseContainer_PDU();
    void set_data(SONtransferResponseContainer &);
    SONtransferResponseContainer *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const SONtransferResponseContainer & d);
    const SONtransferResponseContainer *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC SONtransferCause_PDU : public ConcretePDU {
public:
    SONtransferCause_PDU();
    void set_data(SONtransferCause &);
    SONtransferCause *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const SONtransferCause & d);
    const SONtransferCause *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC ReportingCellList_PDU : public ConcretePDU {
public:
    ReportingCellList_PDU();
    void set_data(ReportingCellList &);
    ReportingCellList *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const ReportingCellList & d);
    const ReportingCellList *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC RerouteNASRequest_IEs_TYPE_PDU : public ConcretePDU {
public:
    RerouteNASRequest_IEs_TYPE_PDU();
    void set_data(RerouteNASRequest_IEs_TYPE &);
    RerouteNASRequest_IEs_TYPE *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const RerouteNASRequest_IEs_TYPE & d);
    const RerouteNASRequest_IEs_TYPE *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

/* Control object class */

class OSS_PUBLIC s1ap_Control : public OssControl {
public:
    s1ap_Control();
    s1ap_Control(const s1ap_Control &);
};


/* External definitions for named values */

const OSS_UINT32 id_HandoverPreparation = 0;

const OSS_UINT32 id_HandoverResourceAllocation = 1;

const OSS_UINT32 id_HandoverNotification = 2;

const OSS_UINT32 id_PathSwitchRequest = 3;

const OSS_UINT32 id_HandoverCancel = 4;

const OSS_UINT32 id_E_RABSetup = 5;

const OSS_UINT32 id_E_RABModify = 6;

const OSS_UINT32 id_E_RABRelease = 7;

const OSS_UINT32 id_E_RABReleaseIndication = 8;

const OSS_UINT32 id_InitialContextSetup = 9;

const OSS_UINT32 id_Paging = 10;

const OSS_UINT32 id_downlinkNASTransport = 11;

const OSS_UINT32 id_initialUEMessage = 12;

const OSS_UINT32 id_uplinkNASTransport = 13;

const OSS_UINT32 id_Reset = 14;

const OSS_UINT32 id_ErrorIndication = 15;

const OSS_UINT32 id_NASNonDeliveryIndication = 16;

const OSS_UINT32 id_S1Setup = 17;

const OSS_UINT32 id_UEContextReleaseRequest = 18;

const OSS_UINT32 id_DownlinkS1cdma2000tunnelling = 19;

const OSS_UINT32 id_UplinkS1cdma2000tunnelling = 20;

const OSS_UINT32 id_UEContextModification = 21;

const OSS_UINT32 id_UECapabilityInfoIndication = 22;

const OSS_UINT32 id_UEContextRelease = 23;

const OSS_UINT32 id_eNBStatusTransfer = 24;

const OSS_UINT32 id_MMEStatusTransfer = 25;

const OSS_UINT32 id_DeactivateTrace = 26;

const OSS_UINT32 id_TraceStart = 27;

const OSS_UINT32 id_TraceFailureIndication = 28;

const OSS_UINT32 id_ENBConfigurationUpdate = 29;

const OSS_UINT32 id_MMEConfigurationUpdate = 30;

const OSS_UINT32 id_LocationReportingControl = 31;

const OSS_UINT32 id_LocationReportingFailureIndication = 32;

const OSS_UINT32 id_LocationReport = 33;

const OSS_UINT32 id_OverloadStart = 34;

const OSS_UINT32 id_OverloadStop = 35;

const OSS_UINT32 id_WriteReplaceWarning = 36;

const OSS_UINT32 id_eNBDirectInformationTransfer = 37;

const OSS_UINT32 id_MMEDirectInformationTransfer = 38;

const OSS_UINT32 id_PrivateMessage = 39;

const OSS_UINT32 id_eNBConfigurationTransfer = 40;

const OSS_UINT32 id_MMEConfigurationTransfer = 41;

const OSS_UINT32 id_CellTrafficTrace = 42;

const OSS_UINT32 id_Kill = 43;

const OSS_UINT32 id_downlinkUEAssociatedLPPaTransport = 44;

const OSS_UINT32 id_uplinkUEAssociatedLPPaTransport = 45;

const OSS_UINT32 id_downlinkNonUEAssociatedLPPaTransport = 46;

const OSS_UINT32 id_uplinkNonUEAssociatedLPPaTransport = 47;

const OSS_UINT32 id_UERadioCapabilityMatch = 48;

const OSS_UINT32 id_PWSRestartIndication = 49;

const OSS_UINT32 id_E_RABModificationIndication = 50;

const OSS_UINT32 id_PWSFailureIndication = 51;

const OSS_UINT32 id_RerouteNASRequest = 52;

const OSS_UINT32 id_UEContextModificationIndication = 53;

const OSS_UINT32 id_ConnectionEstablishmentIndication = 54;

const OSS_UINT32 id_UEContextSuspend = 55;

const OSS_UINT32 id_UEContextResume = 56;

const OSS_INT32 maxPrivateIEs = USHRT_MAX;

const OSS_INT32 maxProtocolExtensions = USHRT_MAX;

const OSS_INT32 maxProtocolIEs = USHRT_MAX;

const OSS_INT32 maxnoofCSGs = 256;

const OSS_INT32 maxnoofE_RABs = 256;

const OSS_INT32 maxnoofTAIs = 256;

const OSS_INT32 maxnoofTACs = 256;

const OSS_INT32 maxnoofErrors = 256;

const OSS_INT32 maxnoofBPLMNs = 6;

const OSS_INT32 maxnoofPLMNsPerMME = 32;

const OSS_INT32 maxnoofEPLMNs = 15;

const OSS_INT32 maxnoofEPLMNsPlusOne = 16;

const OSS_INT32 maxnoofForbLACs = 4096;

const OSS_INT32 maxnoofForbTACs = 4096;

const OSS_INT32 maxnoofIndividualS1ConnectionsToReset = 256;

const OSS_INT32 maxnoofCells = 16;

const OSS_INT32 maxnoofCellsineNB = 256;

const OSS_INT32 maxnoofTAIforWarning = USHRT_MAX;

const OSS_INT32 maxnoofCellID = USHRT_MAX;

const OSS_INT32 maxnoofEmergencyAreaID = USHRT_MAX;

const OSS_INT32 maxnoofCellinTAI = USHRT_MAX;

const OSS_INT32 maxnoofCellinEAI = USHRT_MAX;

const OSS_INT32 maxnoofeNBX2TLAs = 2;

const OSS_INT32 maxnoofeNBX2ExtTLAs = 16;

const OSS_INT32 maxnoofeNBX2GTPTLAs = 16;

const OSS_INT32 maxnoofRATs = 8;

const OSS_INT32 maxnoofGroupIDs = USHRT_MAX;

const OSS_INT32 maxnoofMMECs = 256;

const OSS_INT32 maxnoofCellIDforMDT = 32;

const OSS_INT32 maxnoofTAforMDT = 8;

const OSS_INT32 maxnoofMDTPLMNs = 16;

const OSS_INT32 maxnoofCellsforRestart = 256;

const OSS_INT32 maxnoofRestartTAIs = 2048;

const OSS_INT32 maxnoofRestartEmergencyAreaIDs = 256;

const OSS_INT32 maxEARFCN = 262143;

const OSS_INT32 maxnoofMBSFNAreaMDT = 8;

const OSS_INT32 maxnoofRecommendedCells = 16;

const OSS_INT32 maxnoofRecommendedENBs = 16;

const OSS_UINT32 id_MME_UE_S1AP_ID = 0;

const OSS_UINT32 id_HandoverType = 1;

const OSS_UINT32 id_Cause = 2;

const OSS_UINT32 id_SourceID = 3;

const OSS_UINT32 id_TargetID = 4;

const OSS_UINT32 id_eNB_UE_S1AP_ID = 8;

const OSS_UINT32 id_E_RABSubjecttoDataForwardingList = 12;

const OSS_UINT32 id_E_RABtoReleaseListHOCmd = 13;

const OSS_UINT32 id_E_RABDataForwardingItem = 14;

const OSS_UINT32 id_E_RABReleaseItemBearerRelComp = 15;

const OSS_UINT32 id_E_RABToBeSetupListBearerSUReq = 16;

const OSS_UINT32 id_E_RABToBeSetupItemBearerSUReq = 17;

const OSS_UINT32 id_E_RABAdmittedList = 18;

const OSS_UINT32 id_E_RABFailedToSetupListHOReqAck = 19;

const OSS_UINT32 id_E_RABAdmittedItem = 20;

const OSS_UINT32 id_E_RABFailedtoSetupItemHOReqAck = 21;

const OSS_UINT32 id_E_RABToBeSwitchedDLList = 22;

const OSS_UINT32 id_E_RABToBeSwitchedDLItem = 23;

const OSS_UINT32 id_E_RABToBeSetupListCtxtSUReq = 24;

const OSS_UINT32 id_TraceActivation = 25;

const OSS_UINT32 id_NAS_PDU = 26;

const OSS_UINT32 id_E_RABToBeSetupItemHOReq = 27;

const OSS_UINT32 id_E_RABSetupListBearerSURes = 28;

const OSS_UINT32 id_E_RABFailedToSetupListBearerSURes = 29;

const OSS_UINT32 id_E_RABToBeModifiedListBearerModReq = 30;

const OSS_UINT32 id_E_RABModifyListBearerModRes = 31;

const OSS_UINT32 id_E_RABFailedToModifyList = 32;

const OSS_UINT32 id_E_RABToBeReleasedList = 33;

const OSS_UINT32 id_E_RABFailedToReleaseList = 34;

const OSS_UINT32 id_E_RABItem = 35;

const OSS_UINT32 id_E_RABToBeModifiedItemBearerModReq = 36;

const OSS_UINT32 id_E_RABModifyItemBearerModRes = 37;

const OSS_UINT32 id_E_RABReleaseItem = 38;

const OSS_UINT32 id_E_RABSetupItemBearerSURes = 39;

const OSS_UINT32 id_SecurityContext = 40;

const OSS_UINT32 id_HandoverRestrictionList = 41;

const OSS_UINT32 id_UEPagingID = 43;

const OSS_UINT32 id_pagingDRX = 44;

const OSS_UINT32 id_TAIList = 46;

const OSS_UINT32 id_TAIItem = 47;

const OSS_UINT32 id_E_RABFailedToSetupListCtxtSURes = 48;

const OSS_UINT32 id_E_RABReleaseItemHOCmd = 49;

const OSS_UINT32 id_E_RABSetupItemCtxtSURes = 50;

const OSS_UINT32 id_E_RABSetupListCtxtSURes = 51;

const OSS_UINT32 id_E_RABToBeSetupItemCtxtSUReq = 52;

const OSS_UINT32 id_E_RABToBeSetupListHOReq = 53;

const OSS_UINT32 id_GERANtoLTEHOInformationRes = 55;

const OSS_UINT32 id_UTRANtoLTEHOInformationRes = 57;

const OSS_UINT32 id_CriticalityDiagnostics = 58;

const OSS_UINT32 id_Global_ENB_ID = 59;

const OSS_UINT32 id_eNBname = 60;

const OSS_UINT32 id_MMEname = 61;

const OSS_UINT32 id_ServedPLMNs = 63;

const OSS_UINT32 id_SupportedTAs = 64;

const OSS_UINT32 id_TimeToWait = 65;

const OSS_UINT32 id_uEaggregateMaximumBitrate = 66;

const OSS_UINT32 id_TAI = 67;

const OSS_UINT32 id_E_RABReleaseListBearerRelComp = 69;

const OSS_UINT32 id_cdma2000PDU = 70;

const OSS_UINT32 id_cdma2000RATType = 71;

const OSS_UINT32 id_cdma2000SectorID = 72;

const OSS_UINT32 id_SecurityKey = 73;

const OSS_UINT32 id_UERadioCapability = 74;

const OSS_UINT32 id_GUMMEI_ID = 75;

const OSS_UINT32 id_E_RABInformationListItem = 78;

const OSS_UINT32 id_Direct_Forwarding_Path_Availability = 79;

const OSS_UINT32 id_UEIdentityIndexValue = 80;

const OSS_UINT32 id_cdma2000HOStatus = 83;

const OSS_UINT32 id_cdma2000HORequiredIndication = 84;

const OSS_UINT32 id_E_UTRAN_Trace_ID = 86;

const OSS_UINT32 id_RelativeMMECapacity = 87;

const OSS_UINT32 id_SourceMME_UE_S1AP_ID = 88;

const OSS_UINT32 id_Bearers_SubjectToStatusTransfer_Item = 89;

const OSS_UINT32 id_eNB_StatusTransfer_TransparentContainer = 90;

const OSS_UINT32 id_UE_associatedLogicalS1_ConnectionItem = 91;

const OSS_UINT32 id_ResetType = 92;

const OSS_UINT32 id_UE_associatedLogicalS1_ConnectionListResAck = 93;

const OSS_UINT32 id_E_RABToBeSwitchedULItem = 94;

const OSS_UINT32 id_E_RABToBeSwitchedULList = 95;

const OSS_UINT32 id_S_TMSI = 96;

const OSS_UINT32 id_cdma2000OneXRAND = 97;

const OSS_UINT32 id_RequestType = 98;

const OSS_UINT32 id_UE_S1AP_IDs = 99;

const OSS_UINT32 id_EUTRAN_CGI = 100;

const OSS_UINT32 id_OverloadResponse = 101;

const OSS_UINT32 id_cdma2000OneXSRVCCInfo = 102;

const OSS_UINT32 id_E_RABFailedToBeReleasedList = 103;

const OSS_UINT32 id_Source_ToTarget_TransparentContainer = 104;

const OSS_UINT32 id_ServedGUMMEIs = 105;

const OSS_UINT32 id_SubscriberProfileIDforRFP = 106;

const OSS_UINT32 id_UESecurityCapabilities = 107;

const OSS_UINT32 id_CSFallbackIndicator = 108;

const OSS_UINT32 id_CNDomain = 109;

const OSS_UINT32 id_E_RABReleasedList = 110;

const OSS_UINT32 id_MessageIdentifier = 111;

const OSS_UINT32 id_SerialNumber = 112;

const OSS_UINT32 id_WarningAreaList = 113;

const OSS_UINT32 id_RepetitionPeriod = 114;

const OSS_UINT32 id_NumberofBroadcastRequest = 115;

const OSS_UINT32 id_WarningType = 116;

const OSS_UINT32 id_WarningSecurityInfo = 117;

const OSS_UINT32 id_DataCodingScheme = 118;

const OSS_UINT32 id_WarningMessageContents = 119;

const OSS_UINT32 id_BroadcastCompletedAreaList = 120;

const OSS_UINT32 id_Inter_SystemInformationTransferTypeEDT = 121;

const OSS_UINT32 id_Inter_SystemInformationTransferTypeMDT = 122;

const OSS_UINT32 id_Target_ToSource_TransparentContainer = 123;

const OSS_UINT32 id_SRVCCOperationPossible = 124;

const OSS_UINT32 id_SRVCCHOIndication = 125;

const OSS_UINT32 id_NAS_DownlinkCount = 126;

const OSS_UINT32 id_CSG_Id = 127;

const OSS_UINT32 id_CSG_IdList = 128;

const OSS_UINT32 id_SONConfigurationTransferECT = 129;

const OSS_UINT32 id_SONConfigurationTransferMCT = 130;

const OSS_UINT32 id_TraceCollectionEntityIPAddress = 131;

const OSS_UINT32 id_MSClassmark2 = 132;

const OSS_UINT32 id_MSClassmark3 = 133;

const OSS_UINT32 id_RRC_Establishment_Cause = 134;

const OSS_UINT32 id_NASSecurityParametersfromE_UTRAN = 135;

const OSS_UINT32 id_NASSecurityParameterstoE_UTRAN = 136;

const OSS_UINT32 id_DefaultPagingDRX = 137;

const OSS_UINT32 id_Source_ToTarget_TransparentContainer_Secondary = 138;

const OSS_UINT32 id_Target_ToSource_TransparentContainer_Secondary = 139;

const OSS_UINT32 id_EUTRANRoundTripDelayEstimationInfo = 140;

const OSS_UINT32 id_BroadcastCancelledAreaList = 141;

const OSS_UINT32 id_ConcurrentWarningMessageIndicator = 142;

const OSS_UINT32 id_Data_Forwarding_Not_Possible = 143;

const OSS_UINT32 id_ExtendedRepetitionPeriod = 144;

const OSS_UINT32 id_CellAccessMode = 145;

const OSS_UINT32 id_CSGMembershipStatus = 146;

const OSS_UINT32 id_LPPa_PDU = 147;

const OSS_UINT32 id_Routing_ID = 148;

const OSS_UINT32 id_Time_Synchronisation_Info = 149;

const OSS_UINT32 id_PS_ServiceNotAvailable = 150;

const OSS_UINT32 id_PagingPriority = 151;

const OSS_UINT32 id_x2TNLConfigurationInfo = 152;

const OSS_UINT32 id_eNBX2ExtendedTransportLayerAddresses = 153;

const OSS_UINT32 id_GUMMEIList = 154;

const OSS_UINT32 id_GW_TransportLayerAddress = 155;

const OSS_UINT32 id_Correlation_ID = 156;

const OSS_UINT32 id_SourceMME_GUMMEI = 157;

const OSS_UINT32 id_MME_UE_S1AP_ID_2 = 158;

const OSS_UINT32 id_RegisteredLAI = 159;

const OSS_UINT32 id_RelayNode_Indicator = 160;

const OSS_UINT32 id_TrafficLoadReductionIndication = 161;

const OSS_UINT32 id_MDTConfiguration = 162;

const OSS_UINT32 id_MMERelaySupportIndicator = 163;

const OSS_UINT32 id_GWContextReleaseIndication = 164;

const OSS_UINT32 id_ManagementBasedMDTAllowed = 165;

const OSS_UINT32 id_PrivacyIndicator = 166;

const OSS_UINT32 id_Time_UE_StayedInCell_EnhancedGranularity = 167;

const OSS_UINT32 id_HO_Cause = 168;

const OSS_UINT32 id_VoiceSupportMatchIndicator = 169;

const OSS_UINT32 id_GUMMEIType = 170;

const OSS_UINT32 id_M3Configuration = 171;

const OSS_UINT32 id_M4Configuration = 172;

const OSS_UINT32 id_M5Configuration = 173;

const OSS_UINT32 id_MDT_Location_Info = 174;

const OSS_UINT32 id_MobilityInformation = 175;

const OSS_UINT32 id_Tunnel_Information_for_BBF = 176;

const OSS_UINT32 id_ManagementBasedMDTPLMNList = 177;

const OSS_UINT32 id_SignallingBasedMDTPLMNList = 178;

const OSS_UINT32 id_ULCOUNTValueExtended = 179;

const OSS_UINT32 id_DLCOUNTValueExtended = 180;

const OSS_UINT32 id_ReceiveStatusOfULPDCPSDUsExtended = 181;

const OSS_UINT32 id_ECGIListForRestart = 182;

const OSS_UINT32 id_SIPTO_Correlation_ID = 183;

const OSS_UINT32 id_SIPTO_L_GW_TransportLayerAddress = 184;

const OSS_UINT32 id_TransportInformation = 185;

const OSS_UINT32 id_LHN_ID = 186;

const OSS_UINT32 id_AdditionalCSFallbackIndicator = 187;

const OSS_UINT32 id_TAIListForRestart = 188;

const OSS_UINT32 id_UserLocationInformation = 189;

const OSS_UINT32 id_EmergencyAreaIDListForRestart = 190;

const OSS_UINT32 id_KillAllWarningMessages = 191;

const OSS_UINT32 id_Masked_IMEISV = 192;

const OSS_UINT32 id_eNBIndirectX2TransportLayerAddresses = 193;

const OSS_UINT32 id_uE_HistoryInformationFromTheUE = 194;

const OSS_UINT32 id_ProSeAuthorized = 195;

const OSS_UINT32 id_ExpectedUEBehaviour = 196;

const OSS_UINT32 id_LoggedMBSFNMDT = 197;

const OSS_UINT32 id_UERadioCapabilityForPaging = 198;

const OSS_UINT32 id_E_RABToBeModifiedListBearerModInd = 199;

const OSS_UINT32 id_E_RABToBeModifiedItemBearerModInd = 200;

const OSS_UINT32 id_E_RABNotToBeModifiedListBearerModInd = 201;

const OSS_UINT32 id_E_RABNotToBeModifiedItemBearerModInd = 202;

const OSS_UINT32 id_E_RABModifyListBearerModConf = 203;

const OSS_UINT32 id_E_RABModifyItemBearerModConf = 204;

const OSS_UINT32 id_E_RABFailedToModifyListBearerModConf = 205;

const OSS_UINT32 id_SON_Information_Report = 206;

const OSS_UINT32 id_Muting_Availability_Indication = 207;

const OSS_UINT32 id_Muting_Pattern_Information = 208;

const OSS_UINT32 id_Synchronisation_Information = 209;

const OSS_UINT32 id_E_RABToBeReleasedListBearerModConf = 210;

const OSS_UINT32 id_AssistanceDataForPaging = 211;

const OSS_UINT32 id_CellIdentifierAndCELevelForCECapableUEs = 212;

const OSS_UINT32 id_InformationOnRecommendedCellsAndENBsForPaging = 213;

const OSS_UINT32 id_RecommendedCellItem = 214;

const OSS_UINT32 id_RecommendedENBItem = 215;

const OSS_UINT32 id_ProSeUEtoNetworkRelaying = 216;

const OSS_UINT32 id_ULCOUNTValuePDCP_SNlength18 = 217;

const OSS_UINT32 id_DLCOUNTValuePDCP_SNlength18 = 218;

const OSS_UINT32 id_ReceiveStatusOfULPDCPSDUsPDCP_SNlength18 = 219;

const OSS_UINT32 id_M6Configuration = 220;

const OSS_UINT32 id_M7Configuration = 221;

const OSS_UINT32 id_PWSfailedECGIList = 222;

const OSS_UINT32 id_MME_Group_ID = 223;

const OSS_UINT32 id_Additional_GUTI = 224;

const OSS_UINT32 id_S1_Message = 225;

const OSS_UINT32 id_CSGMembershipInfo = 226;

const OSS_UINT32 id_Paging_eDRXInformation = 227;

const OSS_UINT32 id_UE_RetentionInformation = 228;

const OSS_UINT32 id_UE_Usage_Type = 230;

const OSS_UINT32 id_extended_UEIdentityIndexValue = 231;

const OSS_UINT32 id_RAT_Type = 232;

const OSS_UINT32 id_BearerType = 233;

const OSS_UINT32 id_NB_IoT_DefaultPagingDRX = 234;

const OSS_UINT32 id_E_RABFailedToResumeListResumeReq = 235;

const OSS_UINT32 id_E_RABFailedToResumeItemResumeReq = 236;

const OSS_UINT32 id_E_RABFailedToResumeListResumeRes = 237;

const OSS_UINT32 id_E_RABFailedToResumeItemResumeRes = 238;

const OSS_UINT32 id_NB_IoT_Paging_eDRXInformation = 239;

const OSS_UINT32 id_UEUserPlaneCIoTSupportIndicator = 241;

const OSS_UINT32 id_CE_mode_B_SupportIndicator = 242;

const OSS_UINT32 id_SRVCCOperationNotPossible = 243;

const OSS_UINT32 id_NB_IoT_UEIdentityIndexValue = 244;

const OSS_UINT32 id_RRC_Resume_Cause = 245;

const OSS_INT32 maxnoofIRATReportingCells = 128;

const OSS_INT32 maxnoofcandidateCells = 16;

const OSS_INT32 maxnoofCellineNB = 256;

#endif // OSS_s1ap
