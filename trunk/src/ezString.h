//////////////////////////////////////////////////////////////////////////
// 文件名称: ezString.h
// 文件表示: 字符串处理类
// 摘    要: 
// License:  GNU Lesser General Public License V 2.1
//	     http://www.opensource.org/licenses/lgpl-2.1.php
//
// 当前版本: 0.1
// 作    者: 尹曙光( kevdmx@sina.com )
// 完成日期: 2008-05-07
// 修订原因: 按照ezWinCE整体规划 0.1版本改进
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