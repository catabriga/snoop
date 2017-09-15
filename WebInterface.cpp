#include "WebInterface.h"

#include "civetweb/CivetServer.h"

struct WebInterfacePimplData
{
	CivetServer* webServer;
};

WebInterface::WebInterface(void)
{
	pimplData = new WebInterfacePimplData;

    const char *options[] = {
	    "document_root", "webRoot", "listening_ports", "80", 0};

	pimplData->webServer = new CivetServer(options);
}

WebInterface::~WebInterface(void)
{
	delete pimplData->webServer;
	delete pimplData;
}

