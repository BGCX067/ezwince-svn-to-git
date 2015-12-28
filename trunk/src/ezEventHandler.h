//////////////////////////////////////////////////////////////////////////
// 文件名称: ezEventHandler.h
// 文件表示: Windows消息处理句柄定义
// 摘    要: 该文件定义了处理所有Windows消息时的处理句柄.
// License:  GNU Lesser General Public License V 2.1
//	     http://www.opensource.org/licenses/lgpl-2.1.php
//
// 当前版本: 0.1
// 作    者: 尹曙光( kevdmx@sina.com )
// 完成日期: 2007-9-5
// 
// 修订版本: 0.1.1
// 作    者: 尹曙光( kevdmx@sina.com )
// 完成日期: 2008-05-05
// 修订原因: 按照ezWinCE整体规划 0.1版本改进
//////////////////////////////////////////////////////////////////////////


#ifndef EZ_WINDOWS_EVENTHANDLER_H
#define EZ_WINDOWS_EVENTHANDLER_H

#include "ezObject.h"
#include "ezArguments.h"


//typedef void (SObject::*ONEVENT)();
//代理的基类
class ezDelegate : public ezObject
{

};

//========================================================================
// ON WM_CREATE 窗口创建消息
typedef void (ezObject::*WM_CREATE_EVENT_HANDLER)(ezObject *sender, ezWMCreateArg *createArgs);

class ezWMCreateEventHandler : public ezDelegate
{
public:
	ezWMCreateEventHandler(ezObject *object, WM_CREATE_EVENT_HANDLER event);
	virtual ~ezWMCreateEventHandler();		
	void Invoke(ezObject *sender, ezWMCreateArg *createArgs);	

protected:
	WM_CREATE_EVENT_HANDLER pOnEvent;
	ezObject *pObject;
};

//========================================================================
// ON WM_DESTROY 窗口销毁消息
typedef void (ezObject::*WM_DESTROY_EVENT_HANDLER)(ezObject *sender);

class ezWMDestroyEventHandler : public ezDelegate
{
public:
	ezWMDestroyEventHandler(ezObject *object, WM_DESTROY_EVENT_HANDLER event);
	virtual ~ezWMDestroyEventHandler();		
	void Invoke(ezObject *sender);	

protected:
	WM_DESTROY_EVENT_HANDLER pOnEvent;
	ezObject *pObject;
};

//========================================================================
// ON WM_COMMAND  窗口命令消息
typedef void (ezObject::*WM_COMMAND_EVENT_HANDLER)(ezObject *sender, ezWMCommandArg *commandArgs);

class ezWMCommandEventHandler : public ezDelegate
{
public:
	ezWMCommandEventHandler(ezObject *object, WM_COMMAND_EVENT_HANDLER event);
	virtual ~ezWMCommandEventHandler();		
	void Invoke(ezObject *sender, ezWMCommandArg *commandArgs);	

protected:
	WM_COMMAND_EVENT_HANDLER pOnEvent;
	ezObject *pObject;
};

//========================================================================
// ON WM_PAINT  窗口命令消息
typedef void (ezObject::*WM_PAINT_EVENT_HANDLER)(ezObject *sender, ezWMPaintArg *paintArgs);

class ezWMPaintEventHandler : public ezDelegate
{
public:
	ezWMPaintEventHandler(ezObject *object, WM_PAINT_EVENT_HANDLER event);
	virtual ~ezWMPaintEventHandler();		
	void Invoke(ezObject *sender, ezWMPaintArg *paintArgs);	

protected:
	WM_PAINT_EVENT_HANDLER pOnEvent;
	ezObject *pObject;
};











//========================================================================
// 处理Windows原始消息
typedef void (ezObject::*EZ_PROCESS_WINDOW_MESSAGE_HANDLER)(ezObject *sender, MSG &msg);

class ezProcessWindowMessageHandler : public ezDelegate
{
public:
	ezProcessWindowMessageHandler(ezObject *object, EZ_PROCESS_WINDOW_MESSAGE_HANDLER event);
	virtual ~ezProcessWindowMessageHandler();		
	void Invoke(ezObject *sender,  MSG &msg);	

protected:
	EZ_PROCESS_WINDOW_MESSAGE_HANDLER pOnEvent;
	ezObject *pObject;
};

#endif //EZ_WINDOWS_EVENTHANDLER_H