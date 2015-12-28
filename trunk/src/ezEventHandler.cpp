
#include "stdio.h"
#include "ezEventHandler.h"


//========================================================================
// ON WM_CREATE

ezWMCreateEventHandler::ezWMCreateEventHandler(ezObject *object, WM_CREATE_EVENT_HANDLER event)
{
	pObject = object;
	pOnEvent =  event;
}

ezWMCreateEventHandler::~ezWMCreateEventHandler()
{

}

void 
ezWMCreateEventHandler::Invoke(ezObject *sender, ezWMCreateArg *createArgs)
{
	if ( NULL != pOnEvent)
		(pObject->*(WM_CREATE_EVENT_HANDLER)pOnEvent)(sender, createArgs);
}

//========================================================================
// ON WM_DESTROY

ezWMDestroyEventHandler::ezWMDestroyEventHandler(ezObject *object, WM_DESTROY_EVENT_HANDLER event)
{
	pObject = object;
	pOnEvent =  event;
}

ezWMDestroyEventHandler::~ezWMDestroyEventHandler()
{

}

void
ezWMDestroyEventHandler::Invoke(ezObject *sender)
{
	if ( NULL != pOnEvent)
		(pObject->*(WM_DESTROY_EVENT_HANDLER)pOnEvent)(sender);
}


//========================================================================
// ON WM_COMMAND  窗口命令消息

ezWMCommandEventHandler::ezWMCommandEventHandler(ezObject *object, WM_COMMAND_EVENT_HANDLER event)
{
	pObject = object;
	pOnEvent =  event;
}

ezWMCommandEventHandler::~ezWMCommandEventHandler()
{

}

void 
ezWMCommandEventHandler::Invoke(ezObject *sender, ezWMCommandArg *commandArgs)
{
	if ( NULL != pOnEvent)
		(pObject->*(WM_COMMAND_EVENT_HANDLER)pOnEvent)(sender, commandArgs);
}


//========================================================================
// ON WM_PAINT

ezWMPaintEventHandler::ezWMPaintEventHandler(ezObject *object, WM_PAINT_EVENT_HANDLER event)
{
	pObject = object;
	pOnEvent =  event;
}

ezWMPaintEventHandler::~ezWMPaintEventHandler()
{

}

void
ezWMPaintEventHandler::Invoke(ezObject *sender, ezWMPaintArg *paintArgs)
{
	if ( NULL != pOnEvent)
		(pObject->*(WM_PAINT_EVENT_HANDLER)pOnEvent)(sender, paintArgs);
}


//========================================================================
// 处理Windows原始消息
ezProcessWindowMessageHandler::ezProcessWindowMessageHandler(ezObject *object,
							     EZ_PROCESS_WINDOW_MESSAGE_HANDLER event)
{
	pObject = object;
	pOnEvent =  event;
}

ezProcessWindowMessageHandler::~ezProcessWindowMessageHandler()
{
}

void
ezProcessWindowMessageHandler::Invoke(ezObject *sender, MSG &msg)
{
	if ( NULL != pOnEvent)
		(pObject->*(EZ_PROCESS_WINDOW_MESSAGE_HANDLER)pOnEvent)(sender, msg);
}