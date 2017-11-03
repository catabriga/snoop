#include "SnoopRobot.h"

#include <cstdio>
#include <unistd.h>

#include "MotorController.h"
#ifdef __arm__
#include "MotorControllerWiringpi.h"
#else
#include "MotorControllerNopi.h"
#endif

enum DirectionState
{
	STRAIGHT = 0,
	LEFT = 10,
	RIGHT = 20
};

enum SpeedState
{
	STOP = 0,
	FORWARD = 10,
	BACKWARD = 20
};

struct SnoopRobotPimplData
{
	MotorController* motorController;
	DirectionState directionState;
	SpeedState speedState;
};

SnoopRobot::SnoopRobot(void)
{
	pimplData = new SnoopRobotPimplData;
#ifdef __arm__
	pimplData->motorController = MotorControllerWiringpi::getInstance();
#else
	pimplData->motorController = MotorControllerNopi::getInstance();
#endif

	pimplData->directionState = STRAIGHT;
	pimplData->speedState = STOP;
}

SnoopRobot::~SnoopRobot(void)
{
	delete pimplData;
}

void SnoopRobot::applyCommand(SnoopRobot::Command command)
{
	printf("Command %d\n", command);

	switch(command)
	{
	case STOP_MOVE:
		pimplData->speedState = SpeedState::STOP;
		break;

	case FORWARD:
		pimplData->speedState = SpeedState::FORWARD;
		break;

	case BACKWARD:
		pimplData->speedState = SpeedState::BACKWARD;
		break;

	case STOP_CURVE:
		pimplData->directionState = DirectionState::STRAIGHT;
		break;

	case LEFT:
		pimplData->directionState = DirectionState::LEFT;
		break;

	case RIGHT:
		pimplData->directionState = DirectionState::RIGHT;
		break;
	}
}

void SnoopRobot::run(void)
{
    while(1)
    {
    	switch(pimplData->speedState)
    	{
    	case SpeedState::STOP:
    		pimplData->motorController->setMotorA(0);
    		break;

    	case SpeedState::FORWARD:
    		pimplData->motorController->setMotorA(60);
    		break;

    	case SpeedState::BACKWARD:
    		pimplData->motorController->setMotorA(-60);
    		break;
    	}

    	switch(pimplData->directionState)
		{
		case DirectionState::STRAIGHT:
			pimplData->motorController->setMotorB(0);
			break;

		case DirectionState::LEFT:
			pimplData->motorController->setMotorB(60);
			break;

		case DirectionState::RIGHT:
			pimplData->motorController->setMotorB(-60);
			break;
		}

    	usleep(10000);
    }
}

