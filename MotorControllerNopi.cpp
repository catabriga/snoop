#include "MotorControllerNopi.h"

MotorControllerNopi* MotorControllerNopi::getInstance(void)
{
    static MotorControllerNopi nopiController;

    return (&nopiController);
}

MotorControllerNopi::MotorControllerNopi(void)
{

}

void MotorControllerNopi::setMotorA(int8_t power)
{

}

void MotorControllerNopi::setMotorB(int8_t power)
{

}
