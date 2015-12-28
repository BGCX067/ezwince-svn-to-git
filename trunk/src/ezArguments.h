//////////////////////////////////////////////////////////////////////////
// 文件名称: ezArguments.h
// 文件表示: 处理系统消息的参数定义
// 摘    要: 该文件定义了处理所有Windows消息时的参数
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

#ifndef __EZ_WINDOWS_ARGUMENTS_H__
#define __EZ_WINDOWS_ARGUMENTS_H__

#include <windows.h>
#include "ezObject.h"

//=================================================================
//所有消息参数的基类
class ezEventArg : public ezObject
{

};

//=================================================================
//窗口创建参数
class ezWMCreateArg : public ezEventArg
{
public:
	//窗口创建时的CREATESTRUCT结构体,具体信息请参阅MSDN
	LPCREATESTRUCT		m_pCreateStruct;
	//是否取消此窗口的创建,如果要取消窗口的创建 m_bCancel= true;
	BOOL			m_bCancel;
	ezWMCreateArg();
};


//=================================================================
//命令参数
class ezWMCommandArg : public ezEventArg
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
class ezWMPaintArg : public ezEventArg
{
public:
	//窗口重绘时的设备环境
	HDC		m_hDC;
	//是否取消系统的绘制，如果是，则m_bCancel = true
	bool		m_bCancel;
	ezWMPaintArg();
};

#endif