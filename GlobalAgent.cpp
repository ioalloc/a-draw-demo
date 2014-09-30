// GlobalAgent.cpp: implementation of the CGlobalAgent class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Demo8.h"
#include "GlobalAgent.h"
#include "MainFrm.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CGlobalAgent::CGlobalAgent()
{

}

CGlobalAgent::~CGlobalAgent()
{

}

void CGlobalAgent::showMessageOnStatusBar(CString msg)
{
	CMainFrame *pFrame =(CMainFrame *) AfxGetMainWnd();	
	CStatusBar *sb = &pFrame->m_wndStatusBar;
	sb->SetPaneText(0,msg);
}
