// SForm.cpp: implementation of the SForm class.
//
//////////////////////////////////////////////////////////////////////

#include "ezForm.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ezForm::ezForm()
{

}

ezForm::~ezForm()
{

}

bool 
ezForm::Create(DWORD dwExStyle, LPCTSTR lpszClass, LPCTSTR lpszName, DWORD dwStyle,
			int x, int y, int nWidth, int nHeight, HWND hParent, HMENU hMenu, HINSTANCE hInst)
{
	return ezControl::Create(dwExStyle, lpszClass, lpszName, dwStyle,
			x, y, nWidth, nHeight, hParent, hMenu, hInst);
}


void 
ezForm::PreCreateWindow(WNDCLASS &wc)
{
		wc.style	= CS_HREDRAW | CS_VREDRAW;
}

LRESULT 
ezForm::WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	
	switch (uMsg)
	{
	case WM_SHOWWINDOW:
		{
			
		}		
		break;
		
	case WM_CLOSE:
		{
		
		}
		break;		
	}	

	return ezControl::WndProc(hWnd, uMsg, wParam, lParam);

}