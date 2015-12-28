// SControl.h: interface for the SControl class.
//
//////////////////////////////////////////////////////////////////////

#ifndef EZ_WINDOWS_CONTROL_H
#define EZ_WINDOWS_CONTROL_H

//���� WM_MOUSEHOVER �� WM_MOUSELEAVE ����
/*#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0400
#endif*/

#ifndef WM_NCCREATE
#define WM_NCCREATE	1
#endif


#include "ezComponent.h"
#include "ezEvent.h"
#include "ezArguments.h"
#include <windows.h>
#include <Winuser.h>




//Windows����ɼ��ؼ��Ļ���,���еĿɼ��ؼ����ɴ�������
//�����Ǵ�����
class ezControl  : public  ezComponent
{
public:
	ezControl();
	virtual ~ezControl();

public:

	//ȡ�ÿؼ�/����ľ��
	HWND GetHandle();

	//��ʵ�ؼ�/����
	BOOL Show();

	//���ؿؼ�/����
	BOOL Hide();

	//���¿ؼ�/����
	BOOL Update();

public:	//Enent Delegate

	//��Ӵ����¼�������
	void AddCreateEvent(ezObject *object, WM_CREATE_EVENT event);

	//��������¼�������
	void AddDestroyEvent(ezObject *object, WM_DESTROY_EVENT event);	

	//��Ӵ��������¼�������
	void AddCommandEvent(ezObject *object, WM_COMMAND_EVENT event);	

	//��Ӵ�������¼�������
	void AddPaintEvent(ezObject *object, WM_PAINT_EVENT event);	


public:

	//�����¼��Ĵ���
	ezWMCreateEvent *m_pOnCreate;

	//�����¼��Ĵ���
	ezWMDestroyEvent *m_pOnDestroy;
	
	//���������¼��Ĵ���
	ezWMCommandEvent *m_pOnCommand;

	//���ڵĻ����¼�����
	ezWMPaintEvent	*m_pOnPaint;

	//�ؼ�/������
	HWND m_hWnd;

protected:

	//�ؼ�/�������Ϣ������,����������ﴦ���ض��������Ϣ
	//��������Ը�д�������,�Կ��ƴ��ڵ���Ϣ����
	//���е���Ϣ���������������õ�����.
	virtual LRESULT WndProc(HWND hWnd, UINT uMsg,
		WPARAM wParam, LPARAM lParam);
	
	///������ͨ�Ĵ����࣬WndProc�����ܹ��������Ƕ��ڿؼ��࣬
	//������Ҫ���䴰�ں��������⴦�������Ӵ˺�����
	//Ĭ������£�DefWndProc������::DefWindowProc(hWnd, uMsg, wParam, lParam)
	//���д����ڿؼ��Ĵ��ڴ������У����ԶԴ˺���������д���Դﵽ
	//�ض�������
	virtual LRESULT DefWndProc(HWND hWnd, UINT uMsg,
		WPARAM wParam, LPARAM lParam);

	//����/�ؼ��Ĵ�������,��������Ե�����������Դ�������/�ؼ�
	//�����༴���Ը�д�˺���(���Ƽ�,������ȷ֪����д��������������ĺ��)
	virtual bool Create(DWORD dwExStyle, LPCTSTR lpszClass, LPCTSTR lpszName, DWORD dwStyle,
			int x, int y, int nWidth, int nHeight, HWND hParent, HMENU hMenu, HINSTANCE hInst);

	//���ô˺������ٴ���/�ؼ�
	virtual void Destroy();

	//ע�ᴰ����,�˺����Զ���ⴰ�����Ƿ��Ѿ�ע��,����Ѿ�ע��,����ע��
	virtual bool RegisterWndClass(LPCTSTR lpszClass, HINSTANCE hInst);

	//�ڴ���ע�ᴰ����֮ǰ,����GetWndClass()ȡ�ô��������
	//GetWndClass�����PreCreateWindow().
	//���������дPreCreateWindow()��ȡ���ض��Ĵ�����
	virtual void PreCreateWindow(WNDCLASS &wc);

protected:

	//���д���/�ؼ���ͳһ�ص�����
	static LRESULT CALLBACK DefaultWindowProc(HWND hWnd,
		UINT uMsg,	WPARAM wParam, LPARAM lParam);

private:	
	//ȡ�ô���ע����
	void GetWndClass(WNDCLASS &wc);

};

#endif //EZ_WINDOWS_CONTROL_H
