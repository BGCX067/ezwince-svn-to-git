// SButton.h: interface for the SButton class.
//
//////////////////////////////////////////////////////////////////////

#ifndef EZ_WINDOWS_BUTTON_H
#define EZ_WINDOWS_BUTTON_H

#include "ezWinCtrl.h"

class ezButton  :  public ezWinCtrl
{
protected:
	WNDPROC		m_fnOldWndProc;
	LRESULT DefWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	
public:
	ezButton();
	virtual ~ezButton();

	BOOL Create(LPCTSTR lpszCaption, DWORD dwStyle,	const RECT& rect, ezControl *pParentWnd, UINT nID);

};

#endif //EZ_WINDOWS_BUTTON_H
