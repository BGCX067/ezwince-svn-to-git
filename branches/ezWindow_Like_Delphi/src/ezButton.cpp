// SButton.cpp: implementation of the SButton class.
//
//////////////////////////////////////////////////////////////////////

#include "ezWindows.h"
#include "ezButton.h"


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ezButton::ezButton()
{
	m_fnOldWndProc		= NULL;
}

ezButton::~ezButton()
{

}

LRESULT 
ezButton::DefWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return ::CallWindowProc(m_fnOldWndProc, hWnd, uMsg, wParam, lParam);	
}

BOOL 
ezButton::Create(LPCTSTR lpszCaption, DWORD dwStyle,
		 const RECT& rect, ezControl *pParentWnd, UINT nID)
{
	m_hWnd = ::CreateWindow(TEXT("BUTTON"), 
			lpszCaption,
			dwStyle,
			rect.left,rect.top,
			rect.right-rect.left, rect.bottom-rect.top,
			pParentWnd->m_hWnd,
			(HMENU)nID,
			Application.GetInstance(),
			NULL
			);
	if (NULL == m_hWnd)
		return false;

	SetWindowLong(m_hWnd, GWL_USERDATA, (LONG)this);	
	m_fnOldWndProc = (WNDPROC)SetWindowLong(m_hWnd, GWL_WNDPROC, (LPARAM)(WNDPROC)ezControl::DefaultWindowProc);
	ShowWindow(m_hWnd,SW_SHOW);
	return (NULL != m_fnOldWndProc);		
	

}
