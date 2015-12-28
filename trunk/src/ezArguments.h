//////////////////////////////////////////////////////////////////////////
// �ļ�����: ezArguments.h
// �ļ���ʾ: ����ϵͳ��Ϣ�Ĳ�������
// ժ    Ҫ: ���ļ������˴�������Windows��Ϣʱ�Ĳ���
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

#ifndef __EZ_WINDOWS_ARGUMENTS_H__
#define __EZ_WINDOWS_ARGUMENTS_H__

#include <windows.h>
#include "ezObject.h"

//=================================================================
//������Ϣ�����Ļ���
class ezEventArg : public ezObject
{

};

//=================================================================
//���ڴ�������
class ezWMCreateArg : public ezEventArg
{
public:
	//���ڴ���ʱ��CREATESTRUCT�ṹ��,������Ϣ�����MSDN
	LPCREATESTRUCT		m_pCreateStruct;
	//�Ƿ�ȡ���˴��ڵĴ���,���Ҫȡ�����ڵĴ��� m_bCancel= true;
	BOOL			m_bCancel;
	ezWMCreateArg();
};


//=================================================================
//�������
class ezWMCommandArg : public ezEventArg
{
public:

	//����ID
	UINT		m_nCommandId;

	//��Ϣ��: �����Ϣ������accelerator, m_nNotify=1
	//�����Ϣ�����ڲ˵�, m_nNotify=0
	//��������ڿؼ�,��Ϊthe notification code
	UINT		m_nNotify;

	//Handle to the control sending the message 
	//if the message is from a control. Otherwise, 
	//this parameter is NULL. 
	LONG		m_hControl;
};

//=================================================================
//���ڻ�����Ϣ
class ezWMPaintArg : public ezEventArg
{
public:
	//�����ػ�ʱ���豸����
	HDC		m_hDC;
	//�Ƿ�ȡ��ϵͳ�Ļ��ƣ�����ǣ���m_bCancel = true
	bool		m_bCancel;
	ezWMPaintArg();
};

#endif