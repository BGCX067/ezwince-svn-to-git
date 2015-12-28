
#include "ezWindows.h"

//����һ��������
class MinimalMainWnd : public ezFrameWnd
{
public:
	MinimalMainWnd()
	{
		//��Ӵ�������ʱ���¼�����
		AddDestroyEventHandler(this, (WM_DESTROY_EVENT_HANDLER)&MinimalMainWnd::OnDestroy);	
		//���WM_PAINT���¼�����
		AddPaintEventHandler(this,(WM_PAINT_EVENT_HANDLER)&MinimalMainWnd::OnPaint);
	}

private:
	void OnDestroy(ezObject *sender)
	{		
		PostQuitMessage(0);
	}
	void OnPaint(ezObject *sender, ezWMPaintArg *paintArgs)
	{
		::DrawText(paintArgs->m_hDC,TEXT("Hi, I'm here!\0"),13,&ezRect(10,10,200,200), 0);
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
	
	mainForm.Create(TEXT("ezWindows MINIMAL"),TEXT("ezWindows MINIMAL"),
		WS_VISIBLE, ezRect(CW_USEDEFAULT, 0, CW_USEDEFAULT, 0), NULL, 0);
	
	mainForm.Show();	
	mainForm.Update();

	Application.Run(mainForm);

	return 0;
}
