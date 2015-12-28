// SForm.cpp: implementation of the SForm class.
//
//////////////////////////////////////////////////////////////////////

#include "ezApplication.h"
#include "ezFrameWnd.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ezFrameWnd::ezFrameWnd()
{
	m_pDestroyHandler	= NULL;
	m_pCreateHandler	= NULL;
	m_pCommandHandler	= NULL;
	m_pPaintHandler		= NULL;
}

ezFrameWnd::~ezFrameWnd()
{
	RemoveCreateEventHandler();
	RemoveDestroyEventHandler();
	RemoveCommandEventHandler();
	RemovePaintEventHandler();
}

//=======================================================================
// Event Hander

void 
ezFrameWnd::RemoveCreateEventHandler()
{
	if (NULL != m_pCreateHandler)
		delete m_pCreateHandler;
}
void 
ezFrameWnd::AddCreateEventHandler(ezObject *object, WM_CREATE_EVENT_HANDLER event)
{
	RemoveCreateEventHandler();
	m_pCreateHandler = new ezWMCreateEventHandler(object, event);
}

void 
ezFrameWnd::RemoveDestroyEventHandler()
{
	if (NULL != m_pDestroyHandler)
		delete m_pDestroyHandler;
}

void 
ezFrameWnd::AddDestroyEventHandler(ezObject *object, WM_DESTROY_EVENT_HANDLER event)
{
	RemoveDestroyEventHandler();
	m_pDestroyHandler = new ezWMDestroyEventHandler(object, event);
}	

void 
ezFrameWnd::RemoveCommandEventHandler()
{
	if (NULL != m_pCommandHandler)
		delete m_pCommandHandler;
}

void 
ezFrameWnd::AddCommandEventHandler(ezObject *object, WM_COMMAND_EVENT_HANDLER event)
{
	RemoveCommandEventHandler();
	m_pCommandHandler = new ezWMCommandEventHandler(object, event);
}


void 
ezFrameWnd::RemovePaintEventHandler()
{
	if (NULL != m_pPaintHandler)
		delete m_pPaintHandler;
}

void 
ezFrameWnd::AddPaintEventHandler(ezObject *object, WM_PAINT_EVENT_HANDLER event)
{
	RemovePaintEventHandler();
	m_pPaintHandler = new ezWMPaintEventHandler(object, event);
}

//=====================================================================================
//Window CallBack Procedure 
LRESULT 
ezFrameWnd::WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch( uMsg ){
	case WM_PAINT:
		{
			if (NULL != m_pPaintHandler)
			{
				PAINTSTRUCT ps;
				ezWMPaintArg paintArgs;			
				paintArgs.m_hDC = BeginPaint(hWnd, &ps);  
				m_pPaintHandler->Invoke(this,&paintArgs);
				EndPaint(hWnd, &ps);
				if (paintArgs.m_bCancel)
					return 0;
				else
					break;
			}
		}
/*	//==================================================
	//鼠标事件
	case WM_RBUTTONDOWN:
	case WM_MBUTTONDOWN:
	case WM_LBUTTONDOWN:		
		{

		}
		return 0;

	case WM_RBUTTONUP:
	case WM_MBUTTONUP:
	case WM_LBUTTONUP:
		{

		}
		return 0;
	case WM_RBUTTONDBLCLK:
	case WM_MBUTTONDBLCLK:
	case WM_LBUTTONDBLCLK:
		{

		}
		return 0;

	//==================================================
	//键盘事件
	case WM_KEYDOWN:
		{

		}
		return 0;

	case WM_KEYUP:
		{
		}
		return 0;
	//==================================================
	//活动事件
	case WM_ACTIVATE:
		{

		}
		return 0;

	case WM_MOVE:
		{

		}
		return 0;
*/
	//==================================================
	//命令事件
	case WM_COMMAND: 
		{
			if (NULL != m_pCommandHandler){

				ezWMCommandArg cmdArgs;

				cmdArgs.m_nCommandId = LOWORD(wParam);
				cmdArgs.m_nNotify = HIWORD(wParam);
				cmdArgs.m_hControl = lParam;

				m_pCommandHandler->Invoke(this, &cmdArgs);
			}
			return 0;
		}
		break;
	//==================================================
	//窗口事件	
	/*case WM_SHOWWINDOW:
		{

		}		
		break;

	case WM_CLOSE:
		{

		}
		break;
		*/
	case WM_CREATE:
		{
			m_hWnd = hWnd;
			ezWMCreateArg createArgs;
			createArgs.m_pCreateStruct = (LPCREATESTRUCT) lParam;
			if (NULL != m_pCreateHandler)
				m_pCreateHandler->Invoke(this, &createArgs);

			if (createArgs.m_bCancel)
				return -1;	//取消窗口的创建
			else
				return 0;
		}

	case WM_DESTROY:
		{
			if ( NULL != m_pDestroyHandler)
				m_pDestroyHandler->Invoke(this);

			m_hWnd = NULL;
			return 0;
		}	
	}

	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

/*virtual BOOL Create(
		    LPCTSTR lpszClassName,
		    LPCTSTR lpszWindowName,
		    DWORD dwStyle = WS_OVERLAPPEDWINDOW,
		    const RECT& rect = rectDefault,
		    CWnd* pParentWnd = NULL,
		    LPCTSTR lpszMenuName = NULL,
		    DWORD dwExStyle = 0,
		    CCreateContext* pContext = NULL 
		    );*/


