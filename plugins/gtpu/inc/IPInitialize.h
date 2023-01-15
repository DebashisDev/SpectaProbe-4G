/*
 * IPInitialize.h
 *
 *  Created on: 02-Dec-2017
 *      Author: Deb
 */

#ifndef PLUGINS_TCP_SRC_IPINITIALIZE_H_
#define PLUGINS_TCP_SRC_IPINITIALIZE_H_


#include "IPGlobal.h"
#include "SpectaTypedef.h"
#include "TCPUDPGlobal.h"

class IPInitialize {
	public:
		IPInitialize(int id);
		~IPInitialize();

		VOID initializeSessionRepo();

	private:

		int instanceId;

		VOID initializeSessionRepo_sm_0(int maxSize);
		VOID initializeSessionRepo_sm_1(int maxSize);
		VOID initializeSessionRepo_sm_2(int maxSize);
		VOID initializeSessionRepo_sm_3(int maxSize);
		VOID initializeSessionRepo_sm_4(int maxSize);
		VOID initializeSessionRepo_sm_5(int maxSize);
		VOID initializeSessionRepo_sm_6(int maxSize);
		VOID initializeSessionRepo_sm_7(int maxSize);
		VOID initializeSessionRepo_sm_8(int maxSize);
		VOID initializeSessionRepo_sm_9(int maxSize);
		VOID initializeSessionRepo_sm_10(int maxSize);
		VOID initializeSessionRepo_sm_11(int maxSize);
		VOID initializeSessionRepo_sm_12(int maxSize);
		VOID initializeSessionRepo_sm_13(int maxSize);
		VOID initializeSessionRepo_sm_14(int maxSize);
		VOID initializeSessionRepo_sm_15(int maxSize);
};

#endif /* PLUGINS_TCP_SRC_IPINITIALIZE_H_ */
