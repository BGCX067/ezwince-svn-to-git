// SControl.cpp: implementation of the SControl class.
//
//////////////////////////////////////////////////////////////////////

#include <assert.h>
#include "ezWnd.h"
#include "ezApplication.h"


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ezWnd::ezWnd()
{
	m_hWnd			= NULL;
}

ezWnd::~ezWnd()
{
}

HWND 
ezWnd::GetHandle()
{
	return m_hWnd;
}

BOOL 
ezWnd::Show()
{
	if (NULL != m_hWnd)
		return ::ShowWindow(m_hWnd, SW_SHOW);
	else
		return FALSE;
}

BOOL 
ezWnd::Hide()
{
	if (NULL != m_hWnd)
		return ::ShowWindow(m_hWnd, SW_HIDE);
	else
		return FALSE;
}

BOOL 
ezWnd::Update()
{
	if (NULL != m_hWnd)
		return ::UpdateWindow(m_hWnd);
	else
		return FALSE;
}

BOOL 
ezWnd::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName,
		   DWORD dwStyle, const RECT& rect, ezWnd* pParentWnd, UINT nID)
{
	HWND hParent = (NULL != pParentWnd)?pParentWnd->GetHandle():NULL;
	return CreateEx(0, lpszClassName,lpszWindowName,dwStyle,rect.left,rect.top, 
		rect.right,rect.bottom, hParent, (HMENU)nID);
}

BOOL 
ezWnd::CreateEx(DWORD dwExStyle, LPCTSTR lpszClassName, LPCTSTR lpszWindowName,
		     DWORD dwStyle, const RECT& rect, ezWnd* pParentWnd, UINT nID)
{
	HWND hParent = (NULL != pParentWnd)?pParentWnd->GetHandle():NULL;
	return CreateEx(dwExStyle, lpszClassName,lpszWindowName,dwStyle,rect.left,rect.top, 
			rect.right, rect.bottom, hParent, (HMENU)nID);
}

BOOL 
ezWnd::CreateEx(DWORD dwExStyle, LPCTSTR lpszClassName,LPCTSTR lpszWindowName,
		     DWORD dwStyle, int x,int y, int nWidth, int nHeight, HWND hWndParent, HMENU nIDorHMenu)
{
	
	HWND hWnd = NULL;

	/*hWnd = FindWindow(lpszClassName, lpszWindowName);	
	if (hWnd){
		// 将焦点置于最前面的子窗口
		// “| 0x00000001”用于将所有附属窗口置于前台并
		// 激活这些窗口。
		SetForegroundWindow((HWND)((ULONG) hWnd | 0x00000001));
		return TRUE;
	} */

	if (NULL != m_hWnd)
	{
		SetForegroundWindow((HWND)((ULONG) m_hWnd | 0x00000001));
		return TRUE;
	}


	if ( !RegisterWndClass(lpszClassName, Application.GetInstance())){
		return false;
	}

	/*m_hWnd = CreateWindowEx(dwExStyle, lpszClass, lpszName, dwStyle, x, y,
	nWidth, nHeight, hParent, hMenu, hInst, this);*/
	//处理WM_CREATE消息在前，返回值在后，故m_hWnd可能在WM_CREATE中处理
	hWnd = ::CreateWindowEx(dwExStyle, lpszClassName, lpszWindowName, dwStyle, x, y,
		nWidth, nHeight, hWndParent, nIDorHMenu, Application.GetInstance(), this);
	if (NULL == m_hWnd)
		m_hWnd = hWnd;

	return m_hWnd != NULL;
}

void 
ezWnd::PreCreateWindow(WNDCLASS &wc)
{

}

void 
ezWnd::GetWndClass(WNDCLASS &wc)
{
	memset( &wc, 0, sizeof(wc));
	//wc.cbSize		=	sizeof(WNDCLASS);
	wc.style		=	CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc		=	DefaultWindowProc;
	wc.cbClsExtra		=	0;
	wc.cbWndExtra		=	0;
	wc.hInstance		=	NULL;
	wc.hIcon		=	NULL;
	wc.hCursor		=	0;
	wc.hbrBackground	=	(HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName		=	NULL;
	wc.lpszClassName	=	NULL;
	//wc.hIconSm		=	NULL;	

	PreCreateWindow( wc );
}

bool 
ezWnd::RegisterWndClass(LPCTSTR lpszClass, HINSTANCE hInst)
{
	WNDCLASS wc;
	if ( ! GetClassInfo(hInst, lpszClass, &wc)){		
		GetWndClass( wc );
		wc.hInstance = hInst;
		wc.lpszClassName = lpszClass;

		if ( ! RegisterClass( &wc )){
			return false;
		}
	}
	return true;
}

BOOL 
ezWnd::Destroy()
{
	/*if (NULL == m_hWnd)
		::SendMessage(m_hWnd,WM_DESTROY,0,0);*/
	return ::DestroyWindow(m_hWnd);
}


LRESULT CALLBACK 
ezWnd::DefaultWindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	ezWnd *pWnd;

	if ( WM_NCCREATE == uMsg ){
		assert( !IsBadReadPtr( (void*)lParam, sizeof(CREATESTRUCT)) );
		pWnd =  (ezWnd *)((LPCREATESTRUCT)lParam)->lpCreateParams;		
		assert( !IsBadReadPtr(pWnd, sizeof(ezWnd)));
		SetWindowLong(hWnd, GWL_USERDATA, (LONG)pWnd);		
	}else{
		pWnd = (ezWnd *)GetWindowLong(hWnd, GWL_USERDATA);
	}

	if (pWnd){
		return pWnd->WndProc(hWnd, uMsg, wParam, lParam); 
	}else{
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}
}
