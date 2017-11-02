#ifndef MOTORCONTROLLERNOPI_H
#define MOTORCONTROLLERNOPI_H

#include <cstdint>

#include "MotorController.h"

class MotorControllerNopi: public MotorController
{
public:
    static MotorControllerNopi* getInstance(void);

    void setMotorA(int8_t power);
    void setMotorB(int8_t power);

protected:
    MotorControllerNopi(void);

};

#endif
