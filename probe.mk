#########################################################################
# SCRIPT NAME	: probe.mk												#
# DESCRIPTION	: Include script for SpectaProbe						#
# DATE 			: 19-02-2016										    #
# AUTHOR		: Debashis.											    #
#																		#
# Copyright (c) 2016, Pinnacle Digital (P) Ltd. New-Delhi				# 
#########################################################################

#GCC = g++ -g -std=c++11 -Wall -Wno-deprecated -O1 -w

GCC = g++ -g -O0 -g3 -Wall -std=c++11 -fPIC -Wno-deprecated -w

ifeq ($(S1MME)$(S11)$(S1U), YESNONO)
	CFLAGS = -DOSSPRINT -DOSSDEBUG=2 -D_S1MME -D_MT_SAFE -D_REENTRANT -D_POSIX_THREAD_SAFE_FUNCTIONS -D_GNU_SOURCE -D_PTHREADS -D_POSIX_PTHREAD_SEMANTICS -D_POSIX_C_SOURCE=199506L -D__EXTENSIONS__	
else ifeq ($(S1MME)$(S11)$(S1U), NOYESNO)
	CFLAGS = -DOSSPRINT -DOSSDEBUG=2 -D_S11 -D_MT_SAFE -D_REENTRANT -D_POSIX_THREAD_SAFE_FUNCTIONS -D_GNU_SOURCE -D_PTHREADS -D_POSIX_PTHREAD_SEMANTICS -D_POSIX_C_SOURCE=199506L -D__EXTENSIONS__	
else ifeq ($(S1MME)$(S11)$(S1U), YESYESNO)
	CFLAGS = -DOSSPRINT -DOSSDEBUG=2 -D_S1MME -D_S11 -D_MT_SAFE -D_REENTRANT -D_POSIX_THREAD_SAFE_FUNCTIONS -D_GNU_SOURCE -D_PTHREADS -D_POSIX_PTHREAD_SEMANTICS -D_POSIX_C_SOURCE=199506L -D__EXTENSIONS__	
else ifeq ($(S1MME)$(S11)$(S1U), NOYESYES)
	CFLAGS = -DOSSPRINT -DOSSDEBUG=2 -D_S11 -D_S1U -D_MT_SAFE -D_REENTRANT -D_POSIX_THREAD_SAFE_FUNCTIONS -D_GNU_SOURCE -D_PTHREADS -D_POSIX_PTHREAD_SEMANTICS -D_POSIX_C_SOURCE=199506L -D__EXTENSIONS__	
endif

AR 			= ar
ARFLAGS 	= -r
RM 			= rm 
MAKE 		= make

PROBE_BIN	= ${PROBE_ROOT}/bin

# SpectaProbe Directory

CORE_ROOT		= ${PROBE_ROOT}/core
CORE_INC		= ${CORE_ROOT}/inc
CORE_SRC		= ${CORE_ROOT}/src

LOG_ROOT		= ${PROBE_ROOT}/utility/log
LOG_SRC			= ${LOG_ROOT}/src
LOG_INC			= ${LOG_ROOT}/inc

ETH_ROOT		= ${PROBE_ROOT}/packetsource/ethernet
ETH_SRC			= ${ETH_ROOT}/src
ETH_INC			= ${ETH_ROOT}/inc

SF_ROOT			= ${PROBE_ROOT}/packetsource/solarflare
SF_SRC			= ${SF_ROOT}/src
SF_INC			= ${SF_ROOT}/inc/solar
SFS_INC			= ${SF_ROOT}/inc/specta

ZMQ_ROOT		= ${PROBE_ROOT}/plugins/zmqPush
ZMQ_SRC			= ${ZMQ_ROOT}/src
ZMQ_INC			= ${ZMQ_ROOT}/inc

GN_ROOT			= ${PROBE_ROOT}/plugins/gn
GN_SRC			= ${GN_ROOT}/src
GN_INC			= ${GN_ROOT}/inc

GTPCV2_ROOT		= ${PROBE_ROOT}/plugins/gtpcv2
GTPCV2_SRC		= ${GTPCV2_ROOT}/src
GTPCV2_INC		= ${GTPCV2_ROOT}/inc

GTPU_ROOT		= ${PROBE_ROOT}/plugins/gtpu
GTPU_SRC		= ${GTPU_ROOT}/src
GTPU_INC		= ${GTPU_ROOT}/inc

SCTP_ROOT		= ${PROBE_ROOT}/plugins/sctp
SCTP_SRC		= ${SCTP_ROOT}/src
SCTP_INC		= ${SCTP_ROOT}/inc

S1AP_ROOT		= ${PROBE_ROOT}/plugins/s1ap
S1AP_SRC		= ${S1AP_ROOT}/src
S1AP_INC		= ${S1AP_ROOT}/inc

OSSASN1_ROOT    = /opt/pinnacle/Software/asn1cpp/linux-x86-64/6.7.0
OSS_BIN         = $(OSSASN1_ROOT)/bin
OSS_INC         = $(OSSASN1_ROOT)/include
OSS_LIB         = $(OSSASN1_ROOT)/lib
OSS_DFLT        = $(OSSASN1_ROOT)

PROBE_INCLUDE 	= \
				-I${CORE_INC} 	\
				-I${LOG_INC} 	\
				-I${ETH_INC} 	\
				-I${ZMQ_INC}	\
				-I${SF_INC}		\
				-I${SFS_INC}	\
				-I${GN_INC}		\
				-I${GTPCV2_INC}	\
				-I${GTPU_INC}	\
				-I${SCTP_INC}	\
				-I${S1AP_INC}	\
				-I${OSS_INC}
