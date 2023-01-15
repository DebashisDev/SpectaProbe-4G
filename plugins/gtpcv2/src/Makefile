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
	GTPv2Initialize.o 	\
	GTPv2Message.o		\
	GTPv2Parser.o		\
	S11Flusher.o		\
	S11Interface.o		\
	S11XdrWriter.o		\
	S5S8Flusher.o		\
	S5S8Interface.o		\
	S5S8XdrWriter.o

all:${OBJS}

.cpp.o:

	${GCC} ${CFLAGS} -I/usr/include ${PROBE_INCLUDE} -c $<

clean:
	${RM} ${OBJS}
