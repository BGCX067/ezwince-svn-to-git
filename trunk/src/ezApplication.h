//////////////////////////////////////////////////////////////////////////
// 文件名称: ezApplication.h
// 文件表示: 应用程序类
// 摘    要: 此类负责应用程序公共的系统功能
// License:  GNU Lesser General Public License V 2.1
//	     http://www.opensource.org/licenses/lgpl-2.1.php
//
// 当前版本: 0.1
// 作    者: 尹曙光( kevdmx@sina.com )
// 完成日期: 2007-6-12
// 
// 修订版本: 0.1.1
// 作    者: 尹曙光( kevdmx@sina.com )
// 完成日期: 2008-05-05
// 修订原因: 按照ezWinCE整体规划 0.1版本改进
//////////////////////////////////////////////////////////////////////////

#ifndef __EZ_WINDOWS_APPLICATION_H__
#define __EZ_WINDOWS_APPLICATION_H__

#include "ezObject.h"
#include "ezWnd.h"
#include <windows.h>

class ezApplication  : public ezObject
{
private:
	ezWnd		*m_mainWnd;
protected:
	HINSTANCE	m_hInstance;
	HINSTANCE	m_hPrevInstance;
	LPTSTR		m_lpCmdLine;	
public:

	HINSTANCE	GetInstance();
	HINSTANCE	GetPrevInstance();
	LPTSTR		GetCmdLine();	
	ezWnd		*GetMainWindow();
	void		SetMainWindow(ezWnd &mainWnd);

	LPTSTR		MakeInterSource(UINT nResId);
	
	void AddPreTranslateMessageHandler(ezObject *object, EZ_PROCESS_WINDOW_MESSAGE_HANDLER event);	
	void RemovePreTranslateMessageHandler();	

	void SetLoadAccelerators(UINT accelTableId);

	//退出应用程序
	void Exit();

private:
	//创建事件的代理
	ezProcessWindowMessageHandler *m_pPreTranslateMessageHandler;
	HACCEL		m_hAccelTable;

public:

	ezApplication();
	void		Init(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine);
	virtual		~ezApplication();
	void		Run();
	void		Run(ezWnd &mainWnd);
};

extern ezApplication Application;

#endif  //__EZ_WINDOWS_APPLICATION_H__
