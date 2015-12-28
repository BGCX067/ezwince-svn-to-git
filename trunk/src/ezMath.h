//////////////////////////////////////////////////////////////////////////
// �ļ�����: ezDefines.h
// �ļ���ʾ: Declarations/definitions of common math functions
// ժ    Ҫ: 
// License:  GNU Lesser General Public License V 2.1
//	     http://www.opensource.org/licenses/lgpl-2.1.php
//
// ��ǰ�汾: 0.1
// ��    ��: �����( kevdmx@sina.com )
// �������: 2008-05-06
//////////////////////////////////////////////////////////////////////////

#ifndef __EZ_WINDOWS_MATH_H__
#define __EZ_WINDOWS_MATH_H__

#include "ezDefines.h"

#ifndef M_PI
	#define M_PI 3.1415926535897932384626433832795
#endif

inline bool ezIsSameDouble(double x, double y) { return x == y; }

inline bool ezIsNullDouble(double x) { return ezIsSameDouble(x, 0.); }

inline int ezRound(double x)
{
	return (int)(x < 0 ? x - 0.5 : x + 0.5);
}

#endif //__EZ_WINDOWS_MATH_H__