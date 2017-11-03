#include <cstdio>
#include <unistd.h>
#include <cstdlib>

#include "SnoopRobot.h"
#include "WebInterface.h"

static void checkRoot(void)
{
#ifdef __arm__
	if(getuid() != 0)
	{
		printf("Must run as root! Aborting...\n");
		std::exit(EXIT_FAILURE);
	}
#endif
}

int main(void)
{
    checkRoot();

	SnoopRobot robot;
    WebInterface webInterface(&robot);
    
    robot.run();

    return 0;
}
