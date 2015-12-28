#pragma once

#include <ezWindows.h>

class MainForm : public ezForm
{
private:
	HWND m_hButton;
	ezButton button;
public:
	MainForm(void);
	~MainForm(void);
	void OnDestroy(ezObject *sender);	
	void OnPaint(ezObject *sender, ezWMPaintArgs *paintArgs);
	void OnCreate(ezObject *sender, ezWMCreateArgs *createArgs);
};
