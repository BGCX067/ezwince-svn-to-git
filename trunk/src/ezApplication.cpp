// SApplication.cpp: implementation of the SApplication class.
//
//////////////////////////////////////////////////////////////////////
#include "stdio.h"
#include "ezApplication.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ezApplication Application;

ezApplication::ezApplication()
{
	m_hInstance		= NULL;
	m_hPrevInstance		= NULL;
	m_lpCmdLine		= NULL;	
	m_mainWnd		= NULL;
	m_pPreTranslateMessageHandler	=	NULL;
	m_hAccelTable		=	NULL;
}

ezApplication::~ezApplication()
{
	RemovePreTranslateMessageHandler();
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

ezWnd *
ezApplication::GetMainWindow()
{
	return m_mainWnd;
}

void
ezApplication::SetMainWindow(ezWnd &mainWnd)
{
	m_mainWnd = &mainWnd;	
}

LPTSTR		
ezApplication::MakeInterSource(UINT nResId)
{
	return MAKEINTRESOURCE(nResId);
}

void 
ezApplication::AddPreTranslateMessageHandler(ezObject *object, EZ_PROCESS_WINDOW_MESSAGE_HANDLER event)
{
	RemovePreTranslateMessageHandler();
	m_pPreTranslateMessageHandler = new ezProcessWindowMessageHandler(object, event);
}

void 
ezApplication::RemovePreTranslateMessageHandler()
{
	if ( NULL != m_pPreTranslateMessageHandler)
		delete m_pPreTranslateMessageHandler;
}

void 
ezApplication::SetLoadAccelerators(UINT accelTableId)
{
	m_hAccelTable = ::LoadAccelerators(m_hInstance, MAKEINTRESOURCE(accelTableId));	
}

void 
ezApplication::Exit()
{
	PostQuitMessage(0);
}

void 
ezApplication::Run()
{
	MSG msg;

	while ( GetMessage(&msg, NULL, 0, 0 )){

		if ((NULL == m_hAccelTable) 
			|| (!TranslateAccelerator(msg.hwnd, m_hAccelTable, &msg)) )
		{
			if (NULL != m_pPreTranslateMessageHandler)
				m_pPreTranslateMessageHandler->Invoke(this,msg);

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	
	return;
}

void 
ezApplication::Run(ezWnd &mainWnd)
{
	m_mainWnd = &mainWnd;
	Run();
}

