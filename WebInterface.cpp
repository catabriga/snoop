#include "WebInterface.h"

#include "civetweb/CivetServer.h"

class WebSocketHandler : public CivetWebSocketHandler
{
public:
	WebInterface* webInterface;

	bool handleConnection(CivetServer* server, const struct mg_connection* conn)
	{
		printf("\nhandleConnection\n");
		return true;
	}

	void handleReadyState(CivetServer* server, struct mg_connection* conn)
	{
		printf("\nhandleReadyState\n");
	}

	bool handleData(CivetServer* server, struct mg_connection* conn,
					int bits, char* data, size_t data_len)
	{
		printf("ws data:%s\n", data);
		return true;
	}

	void handleClose(CivetServer* server, const struct mg_connection* conn)
	{
		printf("\nhandleClose\n");
	}

};

struct WebInterfacePimplData
{
	CivetServer* webServer;
	WebSocketHandler socketHandler;
};

WebInterface::WebInterface(void)
{
	pimplData = new WebInterfacePimplData;
	pimplData->socketHandler.webInterface = this;

    const char *options[] = {
	    "document_root", "webRoot", "listening_ports", "80", 0};

	pimplData->webServer = new CivetServer(options);	
	pimplData->webServer->addWebSocketHandler("", &(pimplData->socketHandler));
}

WebInterface::~WebInterface(void)
{
	delete pimplData->webServer;
	delete pimplData;
}

#define UP_DOWN 10
#define UP_UP 11
#define DOWN_DOWN 12
#define DOWN_UP 13
#define LEFT_DOWN 14
#define LEFT_UP 15
#define RIGHT_DOWN 16
#define RIGHT_UP 17

void decodeSocketData(WebInterface* wi, char* data, size_t dataLen)
{
    if(dataLen <= 0)
    {
        return;
    }

    char msgCode = data[0];

    switch(msgCode)
    {
        case UP_DOWN:
            break;
        case UP_UP:
            break;
        case DOWN_DOWN:
            break;
        case DOWN_UP:
            break;
        case LEFT_DOWN:
            break;
        case LEFT_UP:
            break;
        case RIGHT_DOWN:
            break;
        case RIGHT_UP:
            break;
    }

}

