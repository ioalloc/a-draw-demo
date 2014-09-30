// GlobalAgent.h: interface for the CGlobalAgent class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GLOBALAGENT_H__889D43F3_DD97_41A6_9BA4_FF2ECEC4088D__INCLUDED_)
#define AFX_GLOBALAGENT_H__889D43F3_DD97_41A6_9BA4_FF2ECEC4088D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CGlobalAgent  
{
public:
	CGlobalAgent();
	virtual ~CGlobalAgent();

public:
	static void showMessageOnStatusBar(CString msg);
};

#endif // !defined(AFX_GLOBALAGENT_H__889D43F3_DD97_41A6_9BA4_FF2ECEC4088D__INCLUDED_)
