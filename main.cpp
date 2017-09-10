#include <cstdio>
#include <unistd.h>
#include <cstdlib>

#include "MotorController.h"
#include "MotorControllerWiringpi.h"

#include "civetweb/CivetServer.h"

static CivetServer* webServer;

static void checkRoot(void)
{
    if(getuid() != 0)
    {
        printf("Must run as root! Aborting...\n");
        std::exit(EXIT_FAILURE);
    }
}

static void startWebServer(void)
{
	const char *options[] = {
	    "document_root", "webRoot", 0};

	webServer = new CivetServer(options);
}

int main(void)
{
    checkRoot();

	startWebServer();

    MotorController* motorController;

    motorController = MotorControllerWiringpi::getInstance();

    while(1)
    {
        motorController->setMotorA(60);
        motorController->setMotorB(60);

        printf("Press something");
        getchar();

        motorController->setMotorA(-60);
        motorController->setMotorB(-60);

        printf("Press something");
        getchar();

    }

    return 0;
}
