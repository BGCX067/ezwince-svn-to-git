//////////////////////////////////////////////////////////////////////////
// �ļ�����: ezString.h
// �ļ���ʾ: �ַ���������
// ժ    Ҫ: 
// License:  GNU Lesser General Public License V 2.1
//	     http://www.opensource.org/licenses/lgpl-2.1.php
//
// ��ǰ�汾: 0.1
// ��    ��: �����( kevdmx@sina.com )
// �������: 2008-05-07
// �޶�ԭ��: ����ezWinCE����滮 0.1�汾�Ľ�
// 
//////////////////////////////////////////////////////////////////////////

#ifndef __EZ_WINDOWS_STRING_H__
#define __EZ_WINDOWS_STRING_H__

#include "ezObject.h"

class ezString : ezObject
{
public:
	ezString(void);
	/*ezString(LPCWSTR lpWStr = NULL);
	ezString(LPCSTR lpCStr = NULL);
	ezString(const ezString &src);*/

	~ezString(void);

	/*ezString &operate=(const ezString &src);
	ezString &operate=(LPCWSTR lpWStr);
	ezString &operate=(LPCSTR lpCStr);*/

/*private:
	LPWSTR m_data;*/
};

#endif