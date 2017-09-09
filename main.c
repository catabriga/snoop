#include <MotorController.h>
#include <MotorControllerWiringpi.h>

#include <wiringPi.h>

int main(void)
{
    MotorController* motorController;

    motorController = MotorControllerWiringpi::getInstance();

    while(1)
    {
        motorController->setMotorA(60);
        motorController->setMotorB(60);
        delay(2000);
        motorController->setMotorA(-60);
        motorController->setMotorB(-60);        
        delay(2000);
    }

    return 0;
}
