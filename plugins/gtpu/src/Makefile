#########################################################################
#																		#
# SCRIPT NAME	: Makefile												#
# DESCRIPTION	: To build all .cpp files								#
# DATE 			: 19-02-2016										    #
# AUTHOR		: Debashis.											    #
#																		#
# Copyright (c) 2016, Pinnacle Digital (P) Ltd. New-Delhi				# 
#########################################################################

include ${PROBE_ROOT}/probe.mk
OBJS= \
	DnsData.o \
	DNSFlusher.o \
	DNSXdrWriter.o \
	GTPuParser.o 		\
	PacketSSL.o \
	S1UFlusher.o \
	S1UInterface.o \
	S1UMessageBroker.o \
	S1USessionManager.o \
	S1UXdrWriter.o \
	TCPFlusherUtility.o \
	TCPParser.o \
	TCPUDPGlobal.o \
	UDPParser.o

all:${OBJS}

.cpp.o:

	${GCC} ${CFLAGS} -I/usr/include ${PROBE_INCLUDE} -c $<

clean:
	${RM} ${OBJS}
