//////////////////////////////////////////////////////////////////////////
// �ļ�����: ezWndBase.h
// �ļ���ʾ: Window���ڶ���Ļ���,�����Ǵ�����
// ժ    Ҫ: ���ඨ��������Windows���ڶ����е����Ժ���Ϊ.
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

#ifndef __EZ_WINDOWS_WNDBASE_H__
#define __EZ_WINDOWS_WNDBASE_H__

//��WinCE��δ�������Ϣ,��ȷʵ����,�ڴ˶���
#ifndef WM_NCCREATE
#define WM_NCCREATE	1
#endif

#include "ezObject.h"
#include "ezEventHandler.h"
#include "ezArguments.h"
#include <windows.h>
#include <Winuser.h>

//Windows����ɼ��ؼ��Ļ���,���еĿɼ��ؼ����ɴ�������
//�����Ǵ�����
class ezWnd  : public  ezObject
{
public:
	ezWnd();
	virtual ~ezWnd();

public:

	//ȡ�ÿؼ�/����ľ��
	HWND GetHandle();

	//��ʵ�ؼ�/����
	BOOL Show();

	//���ؿؼ�/����
	BOOL Hide();

	//���¿ؼ�/����
	BOOL Update();

	//���ô˺������ٴ���/�ؼ�,�˺������򴰿ڷ���WM_DESTROY��Ϣ
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

	//�ؼ�/������
	HWND m_hWnd;

protected:

	//�ؼ�/�������Ϣ������,����������ﴦ���ض��������Ϣ
	//��������Ը�д�������,�Կ��ƴ��ڵ���Ϣ����
	//���е���Ϣ���������������õ�����.
	virtual LRESULT WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)=0;	
	
protected:
	//���д���/�ؼ���ͳһ�ص�����
	static LRESULT CALLBACK DefaultWindowProc(HWND hWnd,
		UINT uMsg,	WPARAM wParam, LPARAM lParam);

protected:
	//ע�ᴰ����,�˺����Զ���ⴰ�����Ƿ��Ѿ�ע��,����Ѿ�ע��,����ע��
	virtual bool RegisterWndClass(LPCTSTR lpszClass, HINSTANCE hInst);

	//�ڴ���ע�ᴰ����֮ǰ,����GetWndClass()ȡ�ô��������
	//GetWndClass�����PreCreateWindow().
	//���������дPreCreateWindow()��ȡ���ض��Ĵ�����
	virtual void PreCreateWindow(WNDCLASS &wc);

private:	
	//ȡ�ô���ע����
	void GetWndClass(WNDCLASS &wc);


};

#endif //__EZ_WINDOWS_WNDBASE_H__
