#include <cstdint>

#include "MotorController.h"

class MotorControllerWiringpi: MotorController
{
public:
    static MotorControllerWiringpi* getInstance(void);

    void setMotorA(int8_t power);
    void setMotorB(int8_t power);

protected:
    MotorControllerWiringpi(void);
}
