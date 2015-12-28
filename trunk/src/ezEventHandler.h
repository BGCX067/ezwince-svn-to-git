//////////////////////////////////////////////////////////////////////////
// �ļ�����: ezEventHandler.h
// �ļ���ʾ: Windows��Ϣ����������
// ժ    Ҫ: ���ļ������˴�������Windows��Ϣʱ�Ĵ�����.
// License:  GNU Lesser General Public License V 2.1
//	     http://www.opensource.org/licenses/lgpl-2.1.php
//
// ��ǰ�汾: 0.1
// ��    ��: �����( kevdmx@sina.com )
// �������: 2007-9-5
// 
// �޶��汾: 0.1.1
// ��    ��: �����( kevdmx@sina.com )
// �������: 2008-05-05
// �޶�ԭ��: ����ezWinCE����滮 0.1�汾�Ľ�
//////////////////////////////////////////////////////////////////////////


#ifndef EZ_WINDOWS_EVENTHANDLER_H
#define EZ_WINDOWS_EVENTHANDLER_H

#include "ezObject.h"
#include "ezArguments.h"


//typedef void (SObject::*ONEVENT)();
//����Ļ���
class ezDelegate : public ezObject
{

};

//========================================================================
// ON WM_CREATE ���ڴ�����Ϣ
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
// ON WM_DESTROY ����������Ϣ
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
// ON WM_COMMAND  ����������Ϣ
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
// ON WM_PAINT  ����������Ϣ
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
// ����Windowsԭʼ��Ϣ
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