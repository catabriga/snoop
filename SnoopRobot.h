#ifndef SNOOPROBOT_H
#define SNOOPROBOT_H

struct SnoopRobotPimplData;

class SnoopRobot
{
public:
	enum Command
	{
		STOP_MOVE = 0,
		FORWARD = 10,
		BACKWARD = 20,
		STOP_CURVE = 30,
		LEFT = 40,
		RIGHT = 50
	};


    SnoopRobot(void);
	virtual ~SnoopRobot(void);

	void applyCommand(Command command);

    void run(void);

private:
    struct SnoopRobotPimplData* pimplData;

};

#endif
