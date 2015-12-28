// SApplication.h: interface for the SApplication class.
//
//////////////////////////////////////////////////////////////////////

#ifndef EZ_WINDOWS_APPLICATION_H
#define EZ_WINDOWS_APPLICATION_H

#include "ezComponent.h"
#include "ezForm.h"
#include <windows.h>

class ezApplication  : public ezComponent
{
private:
	ezForm		*m_mainForm;
protected:
	HINSTANCE	m_hInstance;
	HINSTANCE	m_hPrevInstance;
	LPTSTR		m_lpCmdLine;	
public:

	HINSTANCE	GetInstance();
	HINSTANCE	GetPrevInstance();
	LPTSTR		GetCmdLine();	
	ezForm		*GetMainWindow();
	void		SetMainWindow(ezForm &mainForm);

	ezApplication();
	void		Init(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
				LPTSTR lpCmdLine);
	virtual		~ezApplication();
	void		Run();
	void		Run(ezForm &mainForm);
};

#endif  //EZ_WINDOWS_APPLICATION_H
