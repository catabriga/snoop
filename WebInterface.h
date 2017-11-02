#ifndef WEBINTERFACE_H
#define WEBINTERFACE_H

struct WebInterfacePimplData;

class WebInterface
{
public:
    WebInterface(void);
	virtual ~WebInterface(void);

private:
	struct WebInterfacePimplData* pimplData;

};

#endif
