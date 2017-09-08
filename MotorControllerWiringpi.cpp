#include "MotorControllerWiringpi.h"

#include <wiringPi.h>

#define MOTOR_A_ENABLE_PIN 1
#define MOTOR_A_IN1_PIN 4
#define MOTOR_A_IN2_PIN 5

#define MOTOR_B_ENABLE_PIN 24
#define MOTOR_B_IN1_PIN 22
#define MOTOR_B_IN2_PIN 23

static MotorControllerWiringpi wiringpiController();

static MotorControllerWiringpi* getInstance(void)
{
    return (&wiringpiController);
}

MotorControllerWiringpi::MotorControllerWiringpi(void)
{
    wiringPiSetup();

    pinMode(MOTOR_A_ENABLE_PIN, OUTPUT);
    pinMode(MOTOR_A_IN1_PIN, OUTPUT);
    pinMode(MOTOR_A_IN2_PIN, OUTPUT);

    pinMode(MOTOR_B_ENABLE_PIN, OUTPUT);
    pinMode(MOTOR_B_IN1_PIN, OUTPUT);
    pinMode(MOTOR_B_IN2_PIN, OUTPUT);

    digitalWrite(MOTOR_A_ENABLE_PIN, LOW);
    digitalWrite(MOTOR_A_IN1_PIN, HIGH);
    digitalWrite(MOTOR_A_IN2_PIN, LOW);

    digitalWrite(MOTOR_B_ENABLE_PIN, LOW);
    digitalWrite(MOTOR_B_IN1_PIN, HIGH);
    digitalWrite(MOTOR_B_IN2_PIN, LOW);
}

void MotorControllerWiringpi::setMotorA(int8_t power)
{
    if(power < 0)
    {
        digitalWrite(MOTOR_A_IN1_PIN, HIGH);
        digitalWrite(MOTOR_A_IN2_PIN, LOW);
    }
    else
    {
        digitalWrite(MOTOR_A_IN1_PIN, LOW);
        digitalWrite(MOTOR_A_IN2_PIN, HIGH);
    }

    // wiringpi uses a 1024 range for its pwm
    // so our 128 range must be multiplied by 8
    int32_t pwmPower = 8 * abs(power);
    pwmWrite(MOTOR_A_ENABLE_PIN, pwmPower);
}

void MotorControllerWiringpi::setMotorB(int8_t power)
{
    if(power < 0)
    {
        digitalWrite(MOTOR_B_IN1_PIN, HIGH);
        digitalWrite(MOTOR_B_IN2_PIN, LOW);
    }
    else
    {
        digitalWrite(MOTOR_B_IN1_PIN, LOW);
        digitalWrite(MOTOR_B_IN2_PIN, HIGH);
    }

    // wiringpi uses a 1024 range for its pwm
    // so our 128 range must be multiplied by 8
    int32_t pwmPower = 8 * abs(power);
    pwmWrite(MOTOR_B_ENABLE_PIN, pwmPower);
}
