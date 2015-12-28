
#include <ezWindows.h>
#include "MainForm.h"
#include "OtherForm.h"

int WINAPI WinMain(HINSTANCE hInstance,
		   HINSTANCE hPrevInstance,
		   LPTSTR    lpCmdLine,
		   int       nCmdShow)
{
	// TODO: Place code here.

	Application.Init(hInstance, hPrevInstance, lpCmdLine);

	MainForm mainForm;

	mainForm.Create(0, TEXT("Form Event Demo"),
		TEXT("Form Event Demo"), 
		WS_VISIBLE, CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, 
		NULL, NULL, hInstance);

	mainForm.Show();	
	mainForm.Update();

	Application.Run(mainForm);

	return 0;
}