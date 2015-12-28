//////////////////////////////////////////////////////////////////////////
// 文件名称: ezFrameWnd.h
// 文件表示: 普通窗口类
// 摘    要: 
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

#ifndef __EZ_WINDOWS_FRAMEWND_H__
#define __EZ_WINDOWS_FRAMEWND_H__

#include "ezWnd.h"
#include "ezEventHandler.h"
#include "ezArguments.h"
#include <windows.h>



class ezFrameWnd  :  public ezWnd
{
public:
	ezFrameWnd();
	virtual ~ezFrameWnd();

public:	//Event Delegate

	//创建事件处理函数
	void AddCreateEventHandler(ezObject *object, WM_CREATE_EVENT_HANDLER event);
	void RemoveCreateEventHandler();

	//销毁事件处理函数
	void AddDestroyEventHandler(ezObject *object, WM_DESTROY_EVENT_HANDLER event);	
	void RemoveDestroyEventHandler();

	//窗体命令事件处理函数
	void AddCommandEventHandler(ezObject *object, WM_COMMAND_EVENT_HANDLER event);	
	void RemoveCommandEventHandler();	

	//窗体绘制事件处理函数
	void AddPaintEventHandler(ezObject *object, WM_PAINT_EVENT_HANDLER event);	
	void RemovePaintEventHandler();	

protected:

	//创建事件的代理
	ezWMCreateEventHandler *m_pCreateHandler;

	//销毁事件的代理
	ezWMDestroyEventHandler *m_pDestroyHandler;

	//窗体命令事件的代理
	ezWMCommandEventHandler *m_pCommandHandler;

	//窗口的绘制事件代理
	ezWMPaintEventHandler	*m_pPaintHandler;

protected:

	//窗口消息处理函数
	LRESULT WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
};

#endif //__EZ_WINDOWS_FRAMEWND_H__
