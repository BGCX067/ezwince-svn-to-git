//////////////////////////////////////////////////////////////////////////
// �ļ�����: ezApplication.h
// �ļ���ʾ: Ӧ�ó�����
// ժ    Ҫ: ���ฺ��Ӧ�ó��򹫹���ϵͳ����
// License:  GNU Lesser General Public License V 2.1
//	     http://www.opensource.org/licenses/lgpl-2.1.php
//
// ��ǰ�汾: 0.1
// ��    ��: �����( kevdmx@sina.com )
// �������: 2007-6-12
// 
// �޶��汾: 0.1.1
// ��    ��: �����( kevdmx@sina.com )
// �������: 2008-05-05
// �޶�ԭ��: ����ezWinCE����滮 0.1�汾�Ľ�
//////////////////////////////////////////////////////////////////////////

#ifndef __EZ_WINDOWS_APPLICATION_H__
#define __EZ_WINDOWS_APPLICATION_H__

#include "ezObject.h"
#include "ezWnd.h"
#include <windows.h>

class ezApplication  : public ezObject
{
private:
	ezWnd		*m_mainWnd;
protected:
	HINSTANCE	m_hInstance;
	HINSTANCE	m_hPrevInstance;
	LPTSTR		m_lpCmdLine;	
public:

	HINSTANCE	GetInstance();
	HINSTANCE	GetPrevInstance();
	LPTSTR		GetCmdLine();	
	ezWnd		*GetMainWindow();
	void		SetMainWindow(ezWnd &mainWnd);

	LPTSTR		MakeInterSource(UINT nResId);
	
	void AddPreTranslateMessageHandler(ezObject *object, EZ_PROCESS_WINDOW_MESSAGE_HANDLER event);	
	void RemovePreTranslateMessageHandler();	

	void SetLoadAccelerators(UINT accelTableId);

	//�˳�Ӧ�ó���
	void Exit();

private:
	//�����¼��Ĵ���
	ezProcessWindowMessageHandler *m_pPreTranslateMessageHandler;
	HACCEL		m_hAccelTable;

public:

	ezApplication();
	void		Init(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine);
	virtual		~ezApplication();
	void		Run();
	void		Run(ezWnd &mainWnd);
};

extern ezApplication Application;

#endif  //__EZ_WINDOWS_APPLICATION_H__
