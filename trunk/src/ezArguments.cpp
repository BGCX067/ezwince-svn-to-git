
#include "ezArguments.h"


//=================================================================
//窗口创建参数
ezWMCreateArg::ezWMCreateArg()
{
	m_pCreateStruct = NULL;
	m_bCancel = FALSE;
}

//=================================================================
//命令参数

//=================================================================
//窗口绘制消息
ezWMPaintArg::ezWMPaintArg()
{
	m_hDC = NULL;
	m_bCancel = FALSE;
}