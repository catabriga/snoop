#include "WebInterface.h"

#include "civetweb/CivetServer.h"

void decodeSocketData(WebInterface* wi, char* data, size_t dataLen);

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
		decodeSocketData(webInterface, data, data_len);
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
	SnoopRobot* robot;
};

WebInterface::WebInterface(SnoopRobot* robot)
{
	pimplData = new WebInterfacePimplData;
	pimplData->socketHandler.webInterface = this;
	pimplData->robot = robot;

    const char *options[] = {
	    "document_root", "webRoot", "listening_ports", "8080", 0};

	pimplData->webServer = new CivetServer(options);	
	pimplData->webServer->addWebSocketHandler("", &(pimplData->socketHandler));
}

WebInterface::~WebInterface(void)
{
	delete pimplData->webServer;
	delete pimplData;
}

#define KEEP_ALIVE 1
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
    printf("MsgCode: %d\n", msgCode);

    switch(msgCode)
    {
    	case KEEP_ALIVE:
    		break;
        case UP_DOWN:
        	wi->pimplData->robot->applyCommand(SnoopRobot::FORWARD);
            break;
        case UP_UP:
        	wi->pimplData->robot->applyCommand(SnoopRobot::STOP_MOVE);
            break;
        case DOWN_DOWN:
        	wi->pimplData->robot->applyCommand(SnoopRobot::BACKWARD);
            break;
        case DOWN_UP:
        	wi->pimplData->robot->applyCommand(SnoopRobot::STOP_MOVE);
            break;
        case LEFT_DOWN:
        	wi->pimplData->robot->applyCommand(SnoopRobot::LEFT);
            break;
        case LEFT_UP:
        	wi->pimplData->robot->applyCommand(SnoopRobot::STOP_CURVE);
            break;
        case RIGHT_DOWN:
        	wi->pimplData->robot->applyCommand(SnoopRobot::RIGHT);
            break;
        case RIGHT_UP:
        	wi->pimplData->robot->applyCommand(SnoopRobot::STOP_CURVE);
            break;
    }

}

