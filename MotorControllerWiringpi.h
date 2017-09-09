#ifndef MOTORCONTROLLERWIRINGPI_H
#define MOTORCONTROLLERWIRINGPI_H

#include <cstdint>

#include "MotorController.h"

class MotorControllerWiringpi: public MotorController
{
public:
    static MotorControllerWiringpi* getInstance(void);

    void setMotorA(int8_t power);
    void setMotorB(int8_t power);

protected:
    MotorControllerWiringpi(void);

};

#endif
