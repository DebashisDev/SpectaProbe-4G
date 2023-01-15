#include <signal.h>

#include "SpectaProbe.h"

bool readLicenseFile();

void sig_handler(int signo)
{
	if (signo == SIGTERM || signo == SIGINT)
	{
		printf("\n Probe Shutdown Initiated....\n");
		IPGlobal::PROBE_RUNNING_STATUS = false;
		IPGlobal::PACKET_PROCESSING = false;
	}
}

int main(int argc, char *argv[])
{
	if(argc < 2)
	{
		printf("USAGE:: spectaProbe <<Config File Name>>\n");
		exit(1);
	}

	sleep(5);

	if (signal(SIGTERM, sig_handler) == SIG_ERR || signal(SIGINT, sig_handler) == SIG_ERR)
		printf(" SpectaProbe Can't Received Signal...\n");

	IPGlobal::PROBE_RUNNING_STATUS = true;
	SpectaProbe *spectaProbe = new SpectaProbe(argv[1]);
	spectaProbe->start();

	printf("  **** SpectaProbe Exiting...Please wait... ***** \n");
}

bool readLicenseFile()
{
	ifstream fp;
	char *probeLicenseEnv;
	std::string line;
	int cnt, cnt1;
	cnt = cnt1 = 0;
	bool status = true;

	probeLicenseEnv = getenv("LICENSE_PATH");

	string licensePath = probeLicenseEnv + string("/") + "license.txt";

	printf("\nLoading License File...\n");

	fp.open(licensePath.c_str());

	if(fp.fail())
	{
		printf("SpectaProbe :: Unable to Open License File [%s]\n", licensePath.c_str());
		exit(1);
	}
	else
	{
		while(!fp.eof())
		{
			getline(fp, line);
			if(!line.empty() && line.length() > 0)
			{
				printf("Key = %s\n", line.c_str());
			}
		}
	}
	return status;
}
