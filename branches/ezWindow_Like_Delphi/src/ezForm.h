// SForm.h: interface for the SForm class.
//
//////////////////////////////////////////////////////////////////////

#ifndef EZ_WINDOWS_FORM_H
#define EZ_WINDOWS_FORM_H

#include "ezScrollingWinCtrl.h"
#include "ezComponent.h"
#include "ezEvent.h"
#include "ezArguments.h"
#include <windows.h>



class ezForm  :  public ezScrollingWinCtrl
{
public:
	ezForm();
	virtual ~ezForm();
	bool Create(DWORD dwExStyle, LPCTSTR lpszClass, LPCTSTR lpszName, DWORD dwStyle,
			int x, int y, int nWidth, int nHeight, HWND hParent, HMENU hMenu, HINSTANCE hInst);

protected:
	void PreCreateWindow(WNDCLASS &wc);
	LRESULT WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

};

#endif //EZ_WINDOWS_FORM_H
