
#include <cstdint>

class MotorController
{
public:
    virtual void setMotorA(int8_t power) = 0;
    virtual void setMotorB(int8_t power) = 0;

    virtual ~MotorController(void){};

protected:
    // The contructor is protected because the motor controller will be a singleton
    // (as only a single motor can be connected to the raspberry)
    // The protected constructor will enable the creation of inherited singletons
    MotorController(void){};
}
