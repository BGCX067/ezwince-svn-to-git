#ifndef EZ_WINDOWS_SEVENT_H
#define EZ_WINDOWS_SEVENT_H

#include "ezObject.h"
#include "ezArguments.h"


//typedef void (SObject::*ONEVENT)();
//代理的基类
class ezDelegate : public ezObject
{

};

//========================================================================
// ON_WM_CREATE 窗口创建消息
typedef void (ezObject::*WM_CREATE_EVENT)(ezObject *sender, ezWMCreateArgs *createArgs);

class ezWMCreateEvent : public ezDelegate
{
public:
	ezWMCreateEvent(ezObject *object, WM_CREATE_EVENT event);
	virtual ~ezWMCreateEvent();		
	void Invoke(ezObject *sender, ezWMCreateArgs *createArgs);	

protected:
	WM_CREATE_EVENT pOnEvent;
	ezObject *pObject;
};

//========================================================================
// ON_WM_DESTROY 窗口销毁消息
typedef void (ezObject::*WM_DESTROY_EVENT)(ezObject *sender);

class ezWMDestroyEvent : public ezDelegate
{
public:
	ezWMDestroyEvent(ezObject *object, WM_DESTROY_EVENT event);
	virtual ~ezWMDestroyEvent();		
	void Invoke(ezObject *sender);	

protected:
	WM_DESTROY_EVENT pOnEvent;
	ezObject *pObject;
};

//========================================================================
// ON_WM_COMMAND  窗口命令消息
typedef void (ezObject::*WM_COMMAND_EVENT)(ezObject *sender, ezWMCommandArgs *commandArgs);

class ezWMCommandEvent : public ezDelegate
{
public:
	ezWMCommandEvent(ezObject *object, WM_COMMAND_EVENT event);
	virtual ~ezWMCommandEvent();		
	void Invoke(ezObject *sender, ezWMCommandArgs *commandArgs);	

protected:
	WM_COMMAND_EVENT pOnEvent;
	ezObject *pObject;
};

//========================================================================
// ON_WM_PAINT  窗口命令消息
typedef void (ezObject::*WM_PAINT_EVENT)(ezObject *sender, ezWMPaintArgs *paintArgs);

class ezWMPaintEvent : public ezDelegate
{
public:
	ezWMPaintEvent(ezObject *object, WM_PAINT_EVENT event);
	virtual ~ezWMPaintEvent();		
	void Invoke(ezObject *sender, ezWMPaintArgs *paintArgs);	

protected:
	WM_PAINT_EVENT pOnEvent;
	ezObject *pObject;
};

#endif //EZ_WINDOWS_SEVENT_H