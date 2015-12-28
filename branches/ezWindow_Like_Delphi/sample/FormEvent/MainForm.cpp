#include "MainForm.h"

MainForm::MainForm(void)
{
	AddDestroyEvent(this, (WM_DESTROY_EVENT)&MainForm::OnDestroy);	
	AddPaintEvent(this,(WM_PAINT_EVENT)&MainForm::OnPaint);
	AddCreateEvent(this,(WM_CREATE_EVENT)&MainForm::OnCreate);
	button.AddClickEvent(this,(WM_CLICK_EVENT)&MainForm::OnButton1Click)
}

MainForm::~MainForm(void)
{
}

void 
MainForm::OnDestroy(ezObject *sender)
{		
	PostQuitMessage(0);
}
void 
MainForm::OnPaint(ezObject *sender, ezWMPaintArgs *paintArgs)
{
	RECT rect;
	rect.bottom = 200;
	rect.top = 10;
	rect.left = 10;
	rect.right = 200;
	::DrawText(paintArgs->m_hDC,TEXT("Hi, I'm here!\0"),13,&rect, 0);
}

void 
MainForm::OnButton1Click(...)
{

}

void 
MainForm::OnCreate(ezObject *sender, ezWMCreateArgs *createArgs)
{
	/*m_hButton = CreateWindow(
			TEXT("BUTTON"), 
			(LPCWSTR)(),
			,
			20,20,
			120,30,
			this->m_hWnd,
			NULL,
			Application.GetInstance(),
				NULL
			);*/
	/*m_hButton = CreateWindow(TEXT("EDIT"),NULL,
		WS_CHILD | WS_VISIBLE  | WS_VSCROLL | WS_BORDER | ES_LEFT | ES_MULTILINE 
		| ES_READONLY | ES_WANTRETURN |  ES_AUTOVSCROLL | WS_VISIBLE ,
		20,20,120,30,
		this->m_hWnd,NULL,Application.GetInstance(),NULL);	*/
	
	RECT rect;
	rect.left = 20;
	rect.right = 150;
	rect.top = 20;
	rect.bottom = 50;
	button.Create(TEXT("Open Window"),BS_PUSHBUTTON|WS_VISIBLE, rect,this, 222);
}
