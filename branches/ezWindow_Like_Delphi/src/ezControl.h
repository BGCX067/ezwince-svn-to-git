// SControl.h: interface for the SControl class.
//
//////////////////////////////////////////////////////////////////////

#ifndef EZ_WINDOWS_CONTROL_H
#define EZ_WINDOWS_CONTROL_H

//处理 WM_MOUSEHOVER 和 WM_MOUSELEAVE 所需
/*#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0400
#endif*/

#ifndef WM_NCCREATE
#define WM_NCCREATE	1
#endif


#include "ezComponent.h"
#include "ezEvent.h"
#include "ezArguments.h"
#include <windows.h>
#include <Winuser.h>




//Windows窗体可见控件的基类,所有的可见控件都由此类派生
//此类是纯虚类
class ezControl  : public  ezComponent
{
public:
	ezControl();
	virtual ~ezControl();

public:

	//取得控件/窗体的句柄
	HWND GetHandle();

	//现实控件/窗体
	BOOL Show();

	//隐藏控件/窗体
	BOOL Hide();

	//更新控件/窗体
	BOOL Update();

public:	//Enent Delegate

	//添加创建事件处理函数
	void AddCreateEvent(ezObject *object, WM_CREATE_EVENT event);

	//添加销毁事件处理函数
	void AddDestroyEvent(ezObject *object, WM_DESTROY_EVENT event);	

	//添加窗体命令事件处理函数
	void AddCommandEvent(ezObject *object, WM_COMMAND_EVENT event);	

	//添加窗体绘制事件处理函数
	void AddPaintEvent(ezObject *object, WM_PAINT_EVENT event);	


public:

	//创建事件的代理
	ezWMCreateEvent *m_pOnCreate;

	//销毁事件的代理
	ezWMDestroyEvent *m_pOnDestroy;
	
	//窗体命令事件的代理
	ezWMCommandEvent *m_pOnCommand;

	//窗口的绘制事件代理
	ezWMPaintEvent	*m_pOnPaint;

	//控件/窗体句柄
	HWND m_hWnd;

protected:

	//控件/窗体的消息处理函数,在这个函数里处理特定对象的消息
	//派生类可以改写这个函数,以控制窗口的消息处理
	//所有的消息处理代理句柄在这里得到处理.
	virtual LRESULT WndProc(HWND hWnd, UINT uMsg,
		WPARAM wParam, LPARAM lParam);
	
	///对于普通的窗口类，WndProc足以能够处理，但是对于控件类，
	//由于需要对其窗口函数做特殊处理，故增加此函数，
	//默认情况下，DefWndProc将调用::DefWindowProc(hWnd, uMsg, wParam, lParam)
	//进行处理，在控件的窗口处理函数中，可以对此函数进行重写，以达到
	//特定的需求．
	virtual LRESULT DefWndProc(HWND hWnd, UINT uMsg,
		WPARAM wParam, LPARAM lParam);

	//窗体/控件的创建函数,派生类可以调用这个函数以创建窗体/控件
	//派生类即可以改写此函数(不推荐,除非明确知道改写这个函数所带来的后果)
	virtual bool Create(DWORD dwExStyle, LPCTSTR lpszClass, LPCTSTR lpszName, DWORD dwStyle,
			int x, int y, int nWidth, int nHeight, HWND hParent, HMENU hMenu, HINSTANCE hInst);

	//调用此函数销毁窗体/控件
	virtual void Destroy();

	//注册窗体类,此函数自动检测窗口类是否已经注册,如果已经注册,则不再注册
	virtual bool RegisterWndClass(LPCTSTR lpszClass, HINSTANCE hInst);

	//在窗体注册窗口类之前,调用GetWndClass()取得窗体类参数
	//GetWndClass会调用PreCreateWindow().
	//子类可以重写PreCreateWindow()以取得特定的窗口类
	virtual void PreCreateWindow(WNDCLASS &wc);

protected:

	//所有窗体/控件的统一回调函数
	static LRESULT CALLBACK DefaultWindowProc(HWND hWnd,
		UINT uMsg,	WPARAM wParam, LPARAM lParam);

private:	
	//取得窗体注册类
	void GetWndClass(WNDCLASS &wc);

};

#endif //EZ_WINDOWS_CONTROL_H
