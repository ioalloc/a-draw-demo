// WorkerPoint.cpp: implementation of the CWorkerPoint class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Demo8.h"
#include "WorkerPoint.h"
#include "ProductionPoint.h"
#include "MainFrm.h"
#include "Demo8Doc.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CWorkerPoint::CWorkerPoint()
{
	type = TYPE_POINT;
}

CWorkerPoint::~CWorkerPoint()
{

}

void CWorkerPoint::OnLButtonDown(UINT nFlags, CPoint point)
{
	CGlobalAgent::showMessageOnStatusBar("CWorkerPoint::OnLButtonDown");
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CDemo8Doc *pDoc = (CDemo8Doc *)pFrame->GetActiveDocument();
	CProductionPoint *p = new CProductionPoint();
	p->x = point.x;
	p->y = point.y;
	p->color = pDoc->current_color;
	pDoc->productions[pDoc->production_number++] = p;
	pDoc->UpdateAllViews(NULL);
}

void CWorkerPoint::OnLButtonUp(UINT nFlags, CPoint point)
{
	CGlobalAgent::showMessageOnStatusBar("CWorkerPoint::OnLButtonUp");
}

void CWorkerPoint::OnMouseMove(UINT nFlags, CPoint point)
{
	CGlobalAgent::showMessageOnStatusBar("CWorkerPoint::OnMouseMove");
}
