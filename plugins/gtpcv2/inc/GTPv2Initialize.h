/*
 * GTPcV2Initialize.h
 *
 *  Created on: Oct 17, 2017
 *      Author: Debashis
 */

#ifndef PLUGINS_GN_SRC_GTPCV2INITIALIZE_H_
#define PLUGINS_GN_SRC_GTPCV2INITIALIZE_H_

#include "GTPGlobal.h"

class GTPv2Initialize {
public:
	GTPv2Initialize();
	~GTPv2Initialize();
	VOID GTPcV2_InitializeRatType();
	VOID GTPcV2_InitializeCauseCode();
	VOID GTPcV2_InitializeMessageType();

};


#endif /* PLUGINS_GN_SRC_GTPCV2INITIALIZE_H_ */
