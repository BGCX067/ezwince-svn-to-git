
#include "ezArguments.h"


//=================================================================
//窗口创建参数
ezWMCreateArgs::ezWMCreateArgs()
{
	m_pCreateStruct = NULL;
	m_bCancel = FALSE;
}

//=================================================================
//命令参数

//=================================================================
//窗口绘制消息
ezWMPaintArgs::ezWMPaintArgs()
{
	m_hDC = NULL;
	m_bCancel = FALSE;
}