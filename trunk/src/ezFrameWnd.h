//////////////////////////////////////////////////////////////////////////
// �ļ�����: ezFrameWnd.h
// �ļ���ʾ: ��ͨ������
// ժ    Ҫ: 
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

#ifndef __EZ_WINDOWS_FRAMEWND_H__
#define __EZ_WINDOWS_FRAMEWND_H__

#include "ezWnd.h"
#include "ezEventHandler.h"
#include "ezArguments.h"
#include <windows.h>



class ezFrameWnd  :  public ezWnd
{
public:
	ezFrameWnd();
	virtual ~ezFrameWnd();

public:	//Event Delegate

	//�����¼�������
	void AddCreateEventHandler(ezObject *object, WM_CREATE_EVENT_HANDLER event);
	void RemoveCreateEventHandler();

	//�����¼�������
	void AddDestroyEventHandler(ezObject *object, WM_DESTROY_EVENT_HANDLER event);	
	void RemoveDestroyEventHandler();

	//���������¼�������
	void AddCommandEventHandler(ezObject *object, WM_COMMAND_EVENT_HANDLER event);	
	void RemoveCommandEventHandler();	

	//��������¼�������
	void AddPaintEventHandler(ezObject *object, WM_PAINT_EVENT_HANDLER event);	
	void RemovePaintEventHandler();	

protected:

	//�����¼��Ĵ���
	ezWMCreateEventHandler *m_pCreateHandler;

	//�����¼��Ĵ���
	ezWMDestroyEventHandler *m_pDestroyHandler;

	//���������¼��Ĵ���
	ezWMCommandEventHandler *m_pCommandHandler;

	//���ڵĻ����¼�����
	ezWMPaintEventHandler	*m_pPaintHandler;

protected:

	//������Ϣ������
	LRESULT WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
};

#endif //__EZ_WINDOWS_FRAMEWND_H__
