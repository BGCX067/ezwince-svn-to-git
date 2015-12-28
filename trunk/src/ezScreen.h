//////////////////////////////////////////////////////////////////////////
// �ļ�����: ezScreen.h
// �ļ���ʾ: ��Ļ��
// ժ    Ҫ: ��������Ļ����������
// License:  GNU Lesser General Public License V 2.1
//	     http://www.opensource.org/licenses/lgpl-2.1.php
//
// ��ǰ�汾: 0.1
// ��    ��: �����( kevdmx@sina.com )
// �������: 2007-9-5
// 
// �޶��汾: 0.1.1
// ��    ��: �����( kevdmx@sina.com )
// �������: 2008-05-05
// �޶�ԭ��: ����ezWinCE����滮 0.1�汾�Ľ�
//////////////////////////////////////////////////////////////////////////

#ifndef __EZ_WINDOWS_SCREEN_H__
#define __EZ_WINDOWS_SCREEN_H__

#include "ezObject.h"
#include "ezTypes.h"
#include <windows.h>
#include <aygshell.h>
#include <sipapi.h>
#include <Winnls.h>

class ezScreen  : public  ezObject
{
public:
	// ��ʾ��æ���Ĺ�꣬��ʾ�û��ȴ�
	void LoadBusyCursor(void);

	// �����������
	void LoadNormalCursor(void);

	//������Ļ����ʾģʽ        
	//Value Meaning: 
	//      DMDO_DEFAULT 
	//              The display orientation is the natural orientation of the display device; it should be used as the default.  
	//      DMDO_90 
	//              The display orientation is rotated 90 degrees (measured clockwise) from DMDO_DEFAULT. 
	//      DMDO_180 
	//              The display orientation is rotated 180 degrees (measured clockwise) from DMDO_DEFAULT. 
	//      DMDO_270 
	//              The display orientation is rotated 270 degrees (measured clockwise) from DMDO_DEFAULT. 
	//Return Values:
	//      DISP_CHANGE_SUCCESSFUL T
	//              he settings change was successful. 
	//      DISP_CHANGE_BADDUALVIEW 
	//              Windows XP: The settings change was unsuccessful because the system is DualView capable. 
	//      DISP_CHANGE_BADFLAGS 
	//              An invalid set of flags was passed in. 
	//      DISP_CHANGE_BADMODE 
	//              The graphics mode is not supported. 
	//      DISP_CHANGE_BADPARAM 
	//              An invalid parameter was passed in. This can include an invalid flag or combination of flags. 
	//      DISP_CHANGE_FAILED 
	//              The display driver failed the specified graphics mode. 
	//      DISP_CHANGE_NOTUPDATED 
	//              Windows NT/2000/XP: Unable to write settings to the registry. 
	//      DISP_CHANGE_RESTART 
	//              The computer must be restarted for the graphics mode to work. 
	int SetScreenMode(DWORD dwMode);

	//ȡ����Ļ����ʾģʽ
	DWORD GetScreenMode();

	//ȡ����Ļ�Ĵ�С
	ezSize GetScreenSize();

public:
	ezScreen();
	virtual ~ezScreen();

};

extern ezScreen Screen;

#endif //__EZ_WINDOWS_SCREEN_H__
