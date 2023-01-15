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
	s1ap.o			\
	S1APFlusher.o	\
	S1APGlobal.o	\
	S1APInit.o		\
	S1APInterface.o \
	S1APMessage.o	\
	S1APParser.o	\
	S1APXdrWriter.o

all:${OBJS}

.cpp.o:

	${GCC} ${CFLAGS} -I/usr/include ${PROBE_INCLUDE} -c $<

clean:
	${RM} S1APFlusher.o S1APGlobal.o S1APInit.o S1APInterface.o S1APMessage.o S1APParser.o S1APXdrWriter.o
