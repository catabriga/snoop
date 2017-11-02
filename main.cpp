#include <cstdio>
#include <unistd.h>
#include <cstdlib>

#include "MotorController.h"

#ifdef __arm__
#include "MotorControllerWiringpi.h"
#else
#include "MotorControllerNopi.h"
#endif

#include "WebInterface.h"

static void checkRoot(void)
{
    if(getuid() != 0)
    {
        printf("Must run as root! Aborting...\n");
        std::exit(EXIT_FAILURE);
    }
}

int main(void)
{
    checkRoot();

	WebInterface webInterface;
	
    MotorController* motorController;

#ifdef __arm__
	motorController = MotorControllerWiringpi::getInstance();
#else
	motorController = MotorControllerNopi::getInstance();
#endif
    
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
