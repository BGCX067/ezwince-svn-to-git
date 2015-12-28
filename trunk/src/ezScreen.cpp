// SScreen.cpp: implementation of the SScreen class.
//
//////////////////////////////////////////////////////////////////////

#include "ezScreen.h"


ezScreen Screen;

void 
ezScreen::LoadBusyCursor(void)
{
	SetCursor(LoadCursor(NULL, IDC_WAIT));
}
void 
ezScreen::LoadNormalCursor(void)
{
	SetCursor(LoadCursor(NULL, IDC_NO));
}

int 
ezScreen::SetScreenMode(DWORD dwMode)
{
	DEVMODE devmode = {0};
	devmode.dmSize = sizeof(DEVMODE);
	devmode.dmDisplayOrientation = dwMode;
	devmode.dmFields = DM_DISPLAYORIENTATION;
	return ChangeDisplaySettingsEx(NULL, &devmode, NULL, CDS_RESET, NULL);  
}

DWORD 
ezScreen::GetScreenMode()
{
	DEVMODE devmode = {0};
	devmode.dmSize = sizeof( DEVMODE );
	devmode.dmFields = DM_DISPLAYORIENTATION;
	ChangeDisplaySettingsEx(NULL, &devmode, NULL, CDS_TEST, NULL);   
	return devmode.dmDisplayOrientation;
}

ezSize 
ezScreen::GetScreenSize()
{
	return ezSize(GetSystemMetrics(SM_CXVIRTUALSCREEN),
		GetSystemMetrics(SM_CYVIRTUALSCREEN));
}

ezScreen::ezScreen()
{

}

ezScreen::~ezScreen()
{

}
