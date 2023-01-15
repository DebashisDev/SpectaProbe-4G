/*
 * GTPConfig.h
 *
 *  Created on: 04-Aug-2016
 *      Author: deb
 */

#ifndef PLUGINS_GN_SRC_GTPCONFIG_H_
#define PLUGINS_GN_SRC_GTPCONFIG_H_

#include <fstream>
#include <iostream>

using namespace std;

class GTPConfig {
	private:

	public:
		GTPConfig();
		~GTPConfig();

		void 	loadGNConfig(ifstream& fp);
		void 	createGNZMQ();
};

#endif /* PLUGINS_GN_SRC_GTPCONFIG_H_ */
