
#include "stdio.h"
#include "ezEvent.h"


//========================================================================
// ON_WM_CREATE

ezWMCreateEvent::ezWMCreateEvent(ezObject *object, WM_CREATE_EVENT event)
{
	pObject = object;
	pOnEvent =  event;
}

ezWMCreateEvent::~ezWMCreateEvent()
{

}

void 
ezWMCreateEvent::Invoke(ezObject *sender, ezWMCreateArgs *createArgs)
{
	if ( NULL != pOnEvent)
		(pObject->*(WM_CREATE_EVENT)pOnEvent)(sender, createArgs);
}

//========================================================================
// ON_WM_DESTROY

ezWMDestroyEvent::ezWMDestroyEvent(ezObject *object, WM_DESTROY_EVENT event)
{
	pObject = object;
	pOnEvent =  event;
}

ezWMDestroyEvent::~ezWMDestroyEvent()
{

}

void
ezWMDestroyEvent::Invoke(ezObject *sender)
{
	if ( NULL != pOnEvent)
		(pObject->*(WM_DESTROY_EVENT)pOnEvent)(sender);
}


//========================================================================
// ON_WM_COMMAND  ´°¿ÚÃüÁîÏûÏ¢

ezWMCommandEvent::ezWMCommandEvent(ezObject *object, WM_COMMAND_EVENT event)
{
	pObject = object;
	pOnEvent =  event;
}

ezWMCommandEvent::~ezWMCommandEvent()
{

}

void 
ezWMCommandEvent::Invoke(ezObject *sender, ezWMCommandArgs *commandArgs)
{
	if ( NULL != pOnEvent)
		(pObject->*(WM_COMMAND_EVENT)pOnEvent)(sender, commandArgs);
}


//========================================================================
// ON_WM_PAINT

ezWMPaintEvent::ezWMPaintEvent(ezObject *object, WM_PAINT_EVENT event)
{
	pObject = object;
	pOnEvent =  event;
}

ezWMPaintEvent::~ezWMPaintEvent()
{

}

void
ezWMPaintEvent::Invoke(ezObject *sender, ezWMPaintArgs *paintArgs)
{
	if ( NULL != pOnEvent)
		(pObject->*(WM_PAINT_EVENT)pOnEvent)(sender, paintArgs);
}