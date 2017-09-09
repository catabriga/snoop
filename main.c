#include "MotorController.h"
#include "MotorControllerWiringpi.h"

#include <cstdio>

int main(void)
{
    MotorController* motorController;

    motorController = MotorControllerWiringpi::getInstance();

    while(1)
    {
        motorController->setMotorA(60);
        motorController->setMotorB(60);

        scanf("Press something");
        getchar();

        motorController->setMotorA(-60);
        motorController->setMotorB(-60);

        scanf("Press something");
        getchar();

    }

    return 0;
}
