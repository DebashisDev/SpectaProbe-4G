/*
 * S1APInit.h
 *
 *  Created on: Dec 17, 2019
 *      Author: Debashis
 */

#ifndef PLUGINS_S1AP_SRC_S1APINIT_H_
#define PLUGINS_S1AP_SRC_S1APINIT_H_

#include "SpectaTypedef.h"
#include "S1APGlobal.h"

using namespace std;

class S1APInit {
	public:
		S1APInit();
		~S1APInit();

		VOID	s1ap_procedureInit();
		VOID	s1ap_nasMobilityMsgInit();
		VOID	s1ap_nasSessionMsgInit();

		VOID 	s1ap_initiatingProcValue();
		VOID 	s1ap_successfulProcValue();
		VOID 	s1ap_unSuccessfulProcValue();

		VOID 	s1ap_causeType();
		VOID	s1ap_radioCauseId();
		VOID	s1ap_transportCauseId();
		VOID	s1ap_nasCauseId();
		VOID	s1ap_ProtocolCauseId();
		VOID	s1ap_miscCauseId();
		VOID	s1ap_MMECauseId();
};

#endif /* PLUGINS_S1AP_SRC_S1APINIT_H_ */
