
#include "ezWindows.h"

class MinimalMainWnd : public ezForm
{
public:
	MinimalMainWnd()
	{
		AddDestroyEvent(this, (WM_DESTROY_EVENT)&MinimalMainWnd::OnDestroy);	
		AddPaintEvent(this,(WM_PAINT_EVENT)&MinimalMainWnd::OnPaint);
	}

private:
	void OnDestroy(ezObject *sender)
	{		
		PostQuitMessage(0);
	}
	void OnPaint(ezObject *sender, ezWMPaintArgs *paintArgs)
	{
		RECT rect;
		rect.bottom = 200;
		rect.top = 10;
		rect.left = 10;
		rect.right = 200;
		::DrawText(paintArgs->m_hDC,TEXT("Hi, I'm here!\0"),13,&rect, 0);
	}
};

int WINAPI WinMain(HINSTANCE hInstance,
	       HINSTANCE hPrevInstance,
	       LPTSTR    lpCmdLine,
	       int       nCmdShow)
{
 	// TODO: Place code here.
	
	Application.Init(hInstance, hPrevInstance, lpCmdLine);

	MinimalMainWnd mainForm;

	mainForm.Create(0, TEXT("ezWindows MINIMAL"),
		TEXT("ezWindows MINIMAL"), 
		WS_VISIBLE, CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, 
		NULL, NULL, hInstance);

	mainForm.Show();	
	mainForm.Update();

	Application.Run(mainForm);

	return 0;
}
