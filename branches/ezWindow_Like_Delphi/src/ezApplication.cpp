// SApplication.cpp: implementation of the SApplication class.
//
//////////////////////////////////////////////////////////////////////
#include "stdio.h"
#include "ezApplication.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ezApplication::ezApplication()
{
	m_hInstance		= NULL;
	m_hPrevInstance		= NULL;
	m_lpCmdLine		= NULL;	
	m_mainForm		= NULL;
}

ezApplication::~ezApplication()
{

}

void 
ezApplication::Init(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine)
{
	m_hInstance = hInstance;
	m_hPrevInstance = hPrevInstance;
	m_lpCmdLine = lpCmdLine;	
}

HINSTANCE 
ezApplication::GetInstance()
{
	return m_hInstance;
}

HINSTANCE 
ezApplication::GetPrevInstance()
{
	return m_hPrevInstance;
}

LPTSTR  
ezApplication::GetCmdLine()
{	
	return m_lpCmdLine;
}

ezForm *
ezApplication::GetMainWindow()
{
	return m_mainForm;
}

void
ezApplication::SetMainWindow(ezForm &mainForm)
{
	m_mainForm = &mainForm;	
}

void 
ezApplication::Run()
{
	MSG msg;

	while ( GetMessage(&msg, NULL, 0, 0 )){
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	
	return;
}

void 
ezApplication::Run(ezForm &mainForm)
{
	m_mainForm = &mainForm;
	Run();
}

