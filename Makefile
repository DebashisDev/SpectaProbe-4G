#########################################################################
#																		#
# SCRIPT NAME	: Makefile												#
# DESCRIPTION	: To build the SpectaProbe along with user librarys		#
# DATE 			: 19-02-2016										    #
# AUTHOR		: Debashis.											    #
#																		#
# To make GN probe : make gnclean; make gnprobe 						#
# To make FL probe : make flclean; make flprobe 						#
# Copyright (c) 2016, Pinnacle Digital (P) Ltd. New-Delhi.				# 
#########################################################################

# Include all the header directories.
include ${PROBE_ROOT}/probe.mk

ifeq ($(S1MME)$(S11)$(S1U), YESNONO)
	PROBE_TARGET = ${PROBE_BIN}/S1MME_PProbe
	PROBE_DIRS = 		\
		${CORE_SRC} 	\
		${LOG_SRC} 		\
		${SF_SRC} 		\
		${ETH_SRC} 		\
		${SCTP_SRC}		\
		${S1AP_SRC}		\
		${ZMQ_SRC}
		
else ifeq ($(S1MME)$(S11)$(S1U), NOYESNO)
	PROBE_TARGET = ${PROBE_BIN}/S11_PProbe
	PROBE_DIRS = 		\
		${CORE_SRC} 	\
		${LOG_SRC} 		\
		${SF_SRC} 		\
		${ETH_SRC} 		\
		${GN_SRC}		\
		${GTPCV2_SRC}	\
		${ZMQ_SRC}
		
else ifeq ($(S1MME)$(S11)$(S1U), YESYESNO)
	PROBE_TARGET = ${PROBE_BIN}/S1MME_S11_PProbe
	PROBE_DIRS = 		\
		${CORE_SRC} 	\
		${LOG_SRC} 		\
		${SF_SRC} 		\
		${ETH_SRC} 		\
		${GN_SRC}		\
		${GTPCV2_SRC}	\
		${SCTP_SRC}		\
		${S1AP_SRC}		\
		${ZMQ_SRC}
		
else ifeq ($(S1MME)$(S11)$(S1U), NOYESYES)
	PROBE_TARGET = ${PROBE_BIN}/S11_S1U_PProbe
	PROBE_DIRS = 		\
		${CORE_SRC} 	\
		${LOG_SRC} 		\
		${SF_SRC} 		\
		${ETH_SRC} 		\
		${GN_SRC}		\
		${GTPCV2_SRC}	\
		${GTPU_SRC}		\
		${ZMQ_SRC}
endif

#########################################################################
# SCP Platform and Platform Library File Name							#
#########################################################################

#System Library
PCAPLIB 	= pcap
THRLIB 		= pthread
ZMQLIB 		= zmq
SOLARLIB	= ${PROBE_ROOT}/lib/libciul.so

ASNLIB		= ${OSS_LIB}/libosscpp.so ${OSS_LIB}/libcpptoed.so

LIBS 		= $(ASNLIB) -lm -ldl -l$(PCAPLIB) -l$(THRLIB) -l$(ZMQLIB)

#########################################################################
# For SpectaProbe
#########################################################################
probe:
	echo ${PROBE_DIRS}
	for i in ${PROBE_DIRS}; \
	do \
		(cd $$i; \
		echo "*******" $$i; \
		${MAKE} all \
		); \
	done

ifeq ($(S1MME)$(S11)$(S1U), YESNONO)
	${GCC} -o ${PROBE_TARGET} ${SOLARLIB}	\
				${CORE_SRC}/*.o 	\
				${LOG_SRC}/*.o 		\
				${SF_SRC}/*.o 		\
				${ETH_SRC}/*.o 		\
				${SCTP_SRC}/*.o		\
				${S1AP_SRC}/*.o		\
				${ZMQ_SRC}/*.o		\
				${LIBS}

else ifeq ($(S1MME)$(S11)$(S1U), NOYESNO)
	${GCC} -o ${PROBE_TARGET} ${SOLARLIB}	\
				${CORE_SRC}/*.o 	\
				${LOG_SRC}/*.o 		\
				${SF_SRC}/*.o 		\
				${ETH_SRC}/*.o 		\
				${GN_SRC}/*.o		\
				${GTPCV2_SRC}/*.o	\
				${ZMQ_SRC}/*.o		\
				${LIBS}
				
else ifeq ($(S1MME)$(S11)$(S1U), YESYESNO)
	${GCC} -o ${PROBE_TARGET} ${SOLARLIB}	\
				${CORE_SRC}/*.o 	\
				${LOG_SRC}/*.o 		\
				${SF_SRC}/*.o 		\
				${ETH_SRC}/*.o 		\
				${GN_SRC}/*.o		\
				${GTPCV2_SRC}/*.o	\
				${SCTP_SRC}/*.o		\
				${S1AP_SRC}/*.o		\
				${ZMQ_SRC}/*.o		\
				${LIBS}

else ifeq ($(S1MME)$(S11)$(S1U), NOYESYES)
	${GCC} -o ${PROBE_TARGET} ${SOLARLIB}	\
				${CORE_SRC}/*.o 	\
				${LOG_SRC}/*.o 		\
				${SF_SRC}/*.o 		\
				${ETH_SRC}/*.o 		\
				${GN_SRC}/*.o		\
				${GTPCV2_SRC}/*.o	\
				${GTPU_SRC}/*.o		\
				${ZMQ_SRC}/*.o		\
				${LIBS}
endif

#########################################################################

clean:
	for i in ${PROBE_DIRS}; \
	do \
		(cd $$i; \
		echo $$i; \
		${MAKE} clean \
		); \
	done

	${RM} ${PROBE_TARGET}
	
