#include "SnoopRobot.h"

#include <cstdio>

#ifdef __arm__
#include "MotorControllerWiringpi.h"
#else
#include "MotorControllerNopi.h"
#endif


SnoopRobot::SnoopRobot(void)
{
#ifdef __arm__
    motorController = MotorControllerWiringpi::getInstance();
#else
    motorController = MotorControllerNopi::getInstance();
#endif


}

SnoopRobot::~SnoopRobot(void)
{

}

void SnoopRobot::run(void)
{
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
}

