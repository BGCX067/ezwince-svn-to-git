
#ifndef EZ_WINDOWS_ARGUMENTS_H
#define EZ_WINDOWS_ARGUMENTS_H

#include "windows.h"
#include "ezObject.h"

//=================================================================
//�¼��Ļ���
class ezEventArgs : public ezObject
{

};

//=================================================================
//���ڴ�������
class ezWMCreateArgs : public ezEventArgs
{
public:
	//���ڴ���ʱ��CREATESTRUCT�ṹ��,������Ϣ�����MSDN
	LPCREATESTRUCT		m_pCreateStruct;
	//�Ƿ�ȡ���˴��ڵĴ���,���Ҫȡ�����ڵĴ��� m_bCancel= true;
	BOOL			m_bCancel;
	ezWMCreateArgs();
};


//=================================================================
//�������
class ezWMCommandArgs : public ezEventArgs
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
class ezWMPaintArgs : public ezEventArgs
{
public:
	//�����ػ�ʱ���豸����
	HDC		m_hDC;
	//�Ƿ�ȡ��ϵͳ�Ļ��ƣ�����ǣ���m_bCancel = true
	bool		m_bCancel;
	ezWMPaintArgs();
};

#endif