//////////////////////////////////////////////////////////////////////////
// 文件名称: ezWndBase.h
// 文件表示: Window窗口对象的基类,此类是纯虚类
// 摘    要: 该类定义了所有Windows窗口对象共有的属性和行为.
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

#ifndef __EZ_WINDOWS_WNDBASE_H__
#define __EZ_WINDOWS_WNDBASE_H__

//在WinCE上未定义此消息,但确实存在,在此定义
#ifndef WM_NCCREATE
#define WM_NCCREATE	1
#endif

#include "ezObject.h"
#include "ezEventHandler.h"
#include "ezArguments.h"
#include <windows.h>
#include <Winuser.h>

//Windows窗体可见控件的基类,所有的可见控件都由此类派生
//此类是纯虚类
class ezWnd  : public  ezObject
{
public:
	ezWnd();
	virtual ~ezWnd();

public:

	//取得控件/窗体的句柄
	HWND GetHandle();

	//现实控件/窗体
	BOOL Show();

	//隐藏控件/窗体
	BOOL Hide();

	//更新控件/窗体
	BOOL Update();

	//调用此函数销毁窗体/控件,此函数将向窗口发送WM_DESTROY消息
	BOOL Destroy();

public:
	/*
	Parameters:
		[in] lpszClassName
		A null-terminated character string that contains the name of the Windows class (a WNDCLASS structure). The class name can be any name registered with the global AfxRegisterWndClass function or any of the predefined control-class names. If null, uses the default CWnd attributes.

		[in] lpszWindowName
		A null-terminated character string that contains the window name.

		[in] dwStyle
		Specifies the window style attributes. WS_POPUP cannot be used. If you wish to create a pop-up window, use CWnd::CreateEx instead.

		[in] Rect
		The size and position of the window, in client coordinates of pParentWnd.

		[in] pParentWnd
		The parent window.

		[in] nID
		The ID of the child window.

	Return Value:
		Nonzero if successful; otherwise 0.
	*/
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName,
		DWORD dwStyle, const RECT& rect, ezWnd* pParentWnd, UINT nID);

	/*
	Parameters:
		dwExStyle
		Specifies the extended style of the CWnd being created. Apply any of the extended window styles to the window. 

		lpszClassName
		Points to a null-terminated character string that names the Windows class (a WNDCLASS structure). The class name can be any name registered with the global AfxRegisterWndClass function or any of the predefined control-class names.

		lpszWindowName
		Points to a null-terminated character string that contains the window name.

		dwStyle
		Specifies the window style attributes. See Window Styles and CWnd::Create for a description of the possible values. 		

		rect
		The size and position of the window, in client coordinates of pParentWnd.

		pParentWnd
		The parent window.

		nID
		The ID of the child window.

	Return Value:
		Nonzero if successful; otherwise 0.
	*/
	virtual BOOL CreateEx(DWORD dwExStyle, LPCTSTR lpszClassName, LPCTSTR lpszWindowName,
		DWORD dwStyle, const RECT& rect, ezWnd* pParentWnd, UINT nID);

	/*
	Parameters:
		dwExStyle
		Specifies the extended style of the CWnd being created. Apply any of the extended window styles to the window. 

		lpszClassName
		Points to a null-terminated character string that names the Windows class (a WNDCLASS structure). The class name can be any name registered with the global AfxRegisterWndClass function or any of the predefined control-class names.

		lpszWindowName
		Points to a null-terminated character string that contains the window name.

		dwStyle
		Specifies the window style attributes. See Window Styles and CWnd::Create for a description of the possible values. 

		x
		Specifies the initial x-position of the CWnd window.

		y
		Specifies the initial top position of the CWnd window.

		nWidth
		Specifies the width (in device units) of the CWnd window.

		nHeight
		Specifies the height (in device units) of the CWnd window.

		hwndParent
		Identifies the parent or owner window of the CWnd window being created. Use NULL for top-level windows.

		nIDorHMenu
		Identifies a menu or a child-window identifier. The meaning depends on the style of the window.

	Return Value:
		Nonzero if successful; otherwise 0.
	*/
	virtual BOOL CreateEx(DWORD dwExStyle, LPCTSTR lpszClassName,LPCTSTR lpszWindowName,
		DWORD dwStyle, int x,int y,	int nWidth,	int nHeight,
		HWND hWndParent, HMENU nIDorHMenu);

protected:

	//控件/窗体句柄
	HWND m_hWnd;

protected:

	//控件/窗体的消息处理函数,在这个函数里处理特定对象的消息
	//派生类可以改写这个函数,以控制窗口的消息处理
	//所有的消息处理代理句柄在这里得到处理.
	virtual LRESULT WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)=0;	
	
protected:
	//所有窗体/控件的统一回调函数
	static LRESULT CALLBACK DefaultWindowProc(HWND hWnd,
		UINT uMsg,	WPARAM wParam, LPARAM lParam);

protected:
	//注册窗体类,此函数自动检测窗口类是否已经注册,如果已经注册,则不再注册
	virtual bool RegisterWndClass(LPCTSTR lpszClass, HINSTANCE hInst);

	//在窗体注册窗口类之前,调用GetWndClass()取得窗体类参数
	//GetWndClass会调用PreCreateWindow().
	//子类可以重写PreCreateWindow()以取得特定的窗口类
	virtual void PreCreateWindow(WNDCLASS &wc);

private:	
	//取得窗体注册类
	void GetWndClass(WNDCLASS &wc);


};

#endif //__EZ_WINDOWS_WNDBASE_H__
