//////////////////////////////////////////////////////////////////////////
// 文件名称: ezException.h
// 文件表示: ezWindow异常基类
// 摘    要: 该类为ezWindow所有异常类的基类
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

#ifndef __EZ_WINDOWS_EXCEPTION_H__
#define __EZ_WINDOWS_EXCEPTION_H__

#include "ezObject.h"

class ezException  : public  ezObject
{
public:
	ezException();
	virtual ~ezException();

};

#endif //__EZ_WINDOWS_EXCEPTION_H__
