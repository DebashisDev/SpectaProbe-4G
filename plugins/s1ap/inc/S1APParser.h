/*
 * S1AP.h
 *
 *  Created on: Dec 11, 2019
 *      Author: Debashis
 */

#ifndef PLUGINS_S1AP_SRC_S1AP_H_
#define PLUGINS_S1AP_SRC_S1AP_H_

#include "IPGlobal.h"
#include "SpectaTypedef.h"
#include "BaseConfig.h"
#include "Log.h"
#include "ProbeUtility.h"
#include "s1ap.h"
#include "S1APGlobal.h"
#include "S1APInit.h"

#define PDU_TYPEDEF			S1AP_PDU			/* representation class */
#define PDU_CONTAINER		S1AP_PDU_PDU		/* coding class */

#define ENCODING_RULES		OSS_PER_ALIGNED 	/* encoding rules */
#define XML_ENCODING_RULES	OSS_XER 			/* encoding rules */


using namespace std;

class S1APParser  : BaseConfig, S1APGlobal {
	public:
		S1APParser();
		~S1APParser();
		VOID 	parsePacket(const BYTE packet, MPacket *msgObj, int chunkNo, int length);

	private:
		uint16_t index;

		EncodedBuffer *decodedData;

		VOID 	get_InitiatingMessage(S1AP_PDU *msg, MPacket *msgObj);
		VOID	get_SuccessfulOutcome(S1AP_PDU *msg, MPacket *msgObj);
		VOID	get_UnSuccessfulOutcome(S1AP_PDU *msg, MPacket *msgObj);
};

#endif /* PLUGINS_S1AP_SRC_S1AP_H_ */
