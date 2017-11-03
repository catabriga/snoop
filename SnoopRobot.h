#ifndef SNOOPROBOT_H
#define SNOOPROBOT_H

#include "MotorController.h"

class SnoopRobot
{
public:
    SnoopRobot(void);
	virtual ~SnoopRobot(void);

    void run(void);

private:
	MotorController* motorController;

};

#endif
