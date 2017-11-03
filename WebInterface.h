#ifndef WEBINTERFACE_H
#define WEBINTERFACE_H

#include "SnoopRobot.h"

struct WebInterfacePimplData;

class WebInterface
{
public:
    WebInterface(SnoopRobot* robot);
	virtual ~WebInterface(void);

	struct WebInterfacePimplData* pimplData;
};

#endif
