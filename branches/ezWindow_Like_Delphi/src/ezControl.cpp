// SControl.cpp: implementation of the SControl class.
//
//////////////////////////////////////////////////////////////////////

#include <assert.h>
#include "ezControl.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ezControl::ezControl()
{
	m_hWnd		= NULL;
	m_pOnDestroy	= NULL;
	m_pOnCreate	= NULL;
	m_pOnCommand	= NULL;
	m_pOnPaint	= NULL;
}

ezControl::~ezControl()
{
	if (NULL != m_pOnCreate)
		delete m_pOnCreate;

	if (NULL != m_pOnDestroy)
		delete m_pOnDestroy;

	if (NULL != m_pOnCommand)
		delete m_pOnCommand;

	if (NULL != m_pOnPaint)
		delete m_pOnPaint;
}

HWND 
ezControl::GetHandle()
{
	return m_hWnd;
}

BOOL 
ezControl::Show()
{
	if (NULL != m_hWnd)
		return ::ShowWindow(m_hWnd, SW_SHOW);
	else
		return FALSE;
}

BOOL 
ezControl::Hide()
{
	if (NULL != m_hWnd)
		return ::ShowWindow(m_hWnd, SW_HIDE);
	else
		return FALSE;
}

BOOL 
ezControl::Update()
{
	if (NULL != m_hWnd)
		return ::UpdateWindow(m_hWnd);
	else
		return FALSE;
}

//=======================================================================
// Event Hander

void 
ezControl::AddCreateEvent(ezObject *object, WM_CREATE_EVENT event)
{
	if (NULL != m_pOnCreate)
		delete m_pOnCreate;

	m_pOnCreate = new ezWMCreateEvent(object, event);
}

void 
ezControl::AddDestroyEvent(ezObject *object, WM_DESTROY_EVENT event)
{
	if (NULL != m_pOnDestroy)
		delete m_pOnDestroy;

	m_pOnDestroy = new ezWMDestroyEvent(object, event);
}	


void 
ezControl::AddCommandEvent(ezObject *object, WM_COMMAND_EVENT event)
{
		if (NULL != m_pOnCommand)
			delete m_pOnCommand;

		m_pOnCommand = new ezWMCommandEvent(object, event);
}

void 
ezControl::AddPaintEvent(ezObject *object, WM_PAINT_EVENT event)
{
	if (NULL != m_pOnPaint)
		delete m_pOnPaint;

	m_pOnPaint = new ezWMPaintEvent(object, event);

}

//=====================================================================================
//Window CallBack Procedure 
LRESULT 
ezControl::WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch( uMsg ){
	case WM_PAINT:
		{
			if (NULL != m_pOnPaint)
			{
				PAINTSTRUCT ps;
				ezWMPaintArgs paintArgs;			
				paintArgs.m_hDC = BeginPaint(hWnd, &ps);  
				m_pOnPaint->Invoke(this,&paintArgs);
				EndPaint(hWnd, &ps);
				if (paintArgs.m_bCancel)
					return 0;
				else
					break;
			}
		}
//==================================================
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

//==================================================
//命令事件
	case WM_COMMAND: 
		{
			if (NULL != m_pOnCommand){
				
				ezWMCommandArgs cmdArgs;
				
				cmdArgs.m_nCommandId = LOWORD(wParam);
				cmdArgs.m_nNotify = HIWORD(wParam);
				cmdArgs.m_hControl = lParam;

				m_pOnCommand->Invoke(this, &cmdArgs);
			}
			return 0;
		}
		break;

//==================================================
//创建和销毁		
	case WM_CREATE:
		{
			m_hWnd = hWnd;
			ezWMCreateArgs createArgs;
			createArgs.m_pCreateStruct = (LPCREATESTRUCT) lParam;
			if (NULL != m_pOnCreate)
				m_pOnCreate->Invoke(this, &createArgs);

			if (createArgs.m_bCancel)
				return -1;	//取消窗口的创建
			else
				return 0;
		}

	case WM_DESTROY:
		{
			if ( NULL != m_pOnDestroy)
				m_pOnDestroy->Invoke(this);

			m_hWnd = NULL;
			return 0;
		}	
	}

	return DefWndProc(hWnd, uMsg, wParam, lParam);
}

LRESULT 
ezControl::DefWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

bool 
ezControl::Create(DWORD dwExStyle, LPCTSTR lpszClass, LPCTSTR lpszName, DWORD dwStyle,
			int x, int y, int nWidth, int nHeight, HWND hParent, HMENU hMenu, HINSTANCE hInst)
{

	if ( !RegisterWndClass(lpszClass, hInst)){
		return false;
	}
	
	/*m_hWnd = CreateWindowEx(dwExStyle, lpszClass, lpszName, dwStyle, x, y,
		nWidth, nHeight, hParent, hMenu, hInst, this);*/
	//发送Ｃｒｅａｔｅ消息在前，返回值在后，故m_hWnd可能在WM_CREATE中处理
	
	HWND hWnd = CreateWindowEx(dwExStyle, lpszClass, lpszName, dwStyle, x, y,
		nWidth, nHeight, hParent, hMenu, hInst, this);
	if (NULL == m_hWnd)
		m_hWnd = hWnd;

	return m_hWnd != NULL;
}

void 
ezControl::Destroy()
{
	if (NULL != m_hWnd){
		DestroyWindow(m_hWnd);
	}
}

bool 
ezControl::RegisterWndClass(LPCTSTR lpszClass, HINSTANCE hInst)
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


void 
ezControl::GetWndClass(WNDCLASS &wc)
{
	memset( &wc, 0, sizeof(wc));
	//wc.cbSize		=	sizeof(WNDCLASS);
	wc.style		=	0;
	wc.lpfnWndProc		=	DefaultWindowProc;
	wc.cbClsExtra		=	0;
	wc.cbWndExtra		=	0;
	wc.hInstance		=	NULL;
	wc.hIcon		=	NULL;
	wc.hCursor		=	LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground	=	(HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName		=	NULL;
	wc.lpszClassName	=	NULL;
	//wc.hIconSm		=	NULL;	

	PreCreateWindow( wc );
}

void 
ezControl::PreCreateWindow(WNDCLASS &wc)
{

}


LRESULT CALLBACK 
ezControl::DefaultWindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	ezControl *pCtrl;

	if ( WM_NCCREATE == uMsg ){
		assert( !IsBadReadPtr( (void*)lParam, sizeof(CREATESTRUCT)) );
		pCtrl =  (ezControl *)((LPCREATESTRUCT)lParam)->lpCreateParams;		
		assert( !IsBadReadPtr(pCtrl, sizeof(ezControl)));
		SetWindowLong(hWnd, GWL_USERDATA, (LONG)pCtrl);		
	}else{
		pCtrl = (ezControl *)GetWindowLong(hWnd, GWL_USERDATA);
	}

	if (pCtrl){
		return pCtrl->WndProc(hWnd, uMsg, wParam, lParam); 
	}else{
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}
}
