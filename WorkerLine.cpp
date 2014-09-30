// WorkerLine.cpp: implementation of the CWorkerLine class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Demo8.h"
#include "WorkerLine.h"
#include "MainFrm.h"
#include "Demo8View.h"
#include "ProductionLine.h"
#include "Demo8Doc.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CWorkerLine::CWorkerLine()
{
	type = TYPE_LINE;
	started = FALSE;

}

CWorkerLine::~CWorkerLine()
{
}

void CWorkerLine::OnLButtonDown(UINT nFlags, CPoint point)
{
	CGlobalAgent::showMessageOnStatusBar("CWorkerLine::OnLButtonDown");
	started = TRUE;
	start = point;
	last_mouse_location = point;

}

void CWorkerLine::OnLButtonUp(UINT nFlags, CPoint point)
{
	CGlobalAgent::showMessageOnStatusBar("CWorkerLine::OnLButtonUp");
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CDemo8Doc *pDoc = (CDemo8Doc *)pFrame->GetActiveDocument();
	CProductionLine *p = new CProductionLine();
	p->start = start;
	p->end = point;
	p->color = pDoc->current_color;
	pDoc->productions[pDoc->production_number++] = p;
	pDoc->UpdateAllViews(NULL);
	started = FALSE;
}

void CWorkerLine::OnMouseMove(UINT nFlags, CPoint point)
{
	CGlobalAgent::showMessageOnStatusBar("CWorkerLine::OnMouseMove");
	if (started == FALSE)
	{
		return;
	}

	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CDemo8View *pView = (CDemo8View *)pFrame->GetActiveView();
	//CPaintDC dc(pView);
	//CPen pen;
	CDC *pDC = pView->GetDC();
	//pen.CreatePen(PS_SOLID,1,RGB(0,0,0));
	//pDC->SelectObject(pen);
	pDC->SetROP2(R2_NOTXORPEN);
	pDC->MoveTo(start);
	pDC->LineTo(last_mouse_location);
	pDC->MoveTo(start);
	pDC->LineTo(point);
	last_mouse_location = point;
}
