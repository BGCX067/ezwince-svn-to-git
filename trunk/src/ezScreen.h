//////////////////////////////////////////////////////////////////////////
// 文件名称: ezScreen.h
// 文件表示: 屏幕类
// 摘    要: 负责处理屏幕的所有事宜
// License:  GNU Lesser General Public License V 2.1
//	     http://www.opensource.org/licenses/lgpl-2.1.php
//
// 当前版本: 0.1
// 作    者: 尹曙光( kevdmx@sina.com )
// 完成日期: 2007-9-5
// 
// 修订版本: 0.1.1
// 作    者: 尹曙光( kevdmx@sina.com )
// 完成日期: 2008-05-05
// 修订原因: 按照ezWinCE整体规划 0.1版本改进
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
	// 显示“忙”的光标，提示用户等待
	void LoadBusyCursor(void);

	// 加载正常光标
	void LoadNormalCursor(void);

	//设置屏幕的显示模式        
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

	//取得屏幕的显示模式
	DWORD GetScreenMode();

	//取得屏幕的大小
	ezSize GetScreenSize();

public:
	ezScreen();
	virtual ~ezScreen();

};

extern ezScreen Screen;

#endif //__EZ_WINDOWS_SCREEN_H__
