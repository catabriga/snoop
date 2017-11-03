#include <cstdio>
#include <unistd.h>
#include <cstdlib>

#include "SnoopRobot.h"
#include "WebInterface.h"

static void checkRoot(void)
{
    if(getuid() != 0)
    {
        printf("Must run as root! Aborting...\n");
        std::exit(EXIT_FAILURE);
    }
}

int main(void)
{
    checkRoot();

    WebInterface webInterface;
	SnoopRobot robot;
    
    robot.run();

    return 0;
}
