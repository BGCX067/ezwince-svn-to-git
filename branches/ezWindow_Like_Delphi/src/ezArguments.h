
#ifndef EZ_WINDOWS_ARGUMENTS_H
#define EZ_WINDOWS_ARGUMENTS_H

#include "windows.h"
#include "ezObject.h"

//=================================================================
//事件的基类
class ezEventArgs : public ezObject
{

};

//=================================================================
//窗口创建参数
class ezWMCreateArgs : public ezEventArgs
{
public:
	//窗口创建时的CREATESTRUCT结构体,具体信息请参阅MSDN
	LPCREATESTRUCT		m_pCreateStruct;
	//是否取消此窗口的创建,如果要取消窗口的创建 m_bCancel= true;
	BOOL			m_bCancel;
	ezWMCreateArgs();
};


//=================================================================
//命令参数
class ezWMCommandArgs : public ezEventArgs
{
public:

	//命令ID
	UINT		m_nCommandId;

	//消息码: 如果消息来自于accelerator, m_nNotify=1
	//如果消息来自于菜单, m_nNotify=0
	//如果来自于控件,则为the notification code
	UINT		m_nNotify;

	//Handle to the control sending the message 
	//if the message is from a control. Otherwise, 
	//this parameter is NULL. 
	LONG		m_hControl;
};

//=================================================================
//窗口绘制消息
class ezWMPaintArgs : public ezEventArgs
{
public:
	//窗口重绘时的设备环境
	HDC		m_hDC;
	//是否取消系统的绘制，如果是，则m_bCancel = true
	bool		m_bCancel;
	ezWMPaintArgs();
};

#endif