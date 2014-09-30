// WorkerPolygon.cpp: implementation of the CWorkerPolygon class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Demo8.h"
#include "WorkerPolygon.h"
#include "GlobalAgent.h"
#include "MainFrm.h"
#include "Demo8Doc.h"
#include "Demo8View.h"
#include "ProductionPolygon.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CWorkerPolygon::CWorkerPolygon()
{
	starting = FALSE;
	polygon = NULL;
	type = TYPE_POLYGON;
}

CWorkerPolygon::~CWorkerPolygon()
{

}

void CWorkerPolygon::OnLButtonDown(UINT nFlags, CPoint point)
{
	CGlobalAgent::showMessageOnStatusBar("CWorkerPolygon::OnLButtonDown");
	if(!starting)
	{
		polygon = new CProductionPolygon();
		starting = TRUE;
	}
	polygon->points[polygon->point_num++] = point;
	last_mouse_location = point;
}

void CWorkerPolygon::OnLButtonUp(UINT nFlags, CPoint point)
{
	CGlobalAgent::showMessageOnStatusBar("CWorkerPolygon::OnLButtonUp");
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CDemo8Doc *pDoc = (CDemo8Doc *)pFrame->GetActiveDocument();
}

void CWorkerPolygon::OnMouseMove(UINT nFlags, CPoint point)
{
	if (!starting)
	{
		return;
	}
	CGlobalAgent::showMessageOnStatusBar("CWorkerPolygon::OnMouseMove");
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CDemo8View *pView = (CDemo8View *)pFrame->GetActiveView();
	//CPaintDC dc(pView);
	//CPen pen;
	CDC *pDC = pView->GetDC();
	//pen.CreatePen(PS_SOLID,1,RGB(0,0,0));
	//pDC->SelectObject(pen);
	pDC->SetROP2(R2_NOTXORPEN);
	pDC->MoveTo(polygon->points[polygon->point_num-1]);
	pDC->LineTo(last_mouse_location);
	pDC->MoveTo(polygon->points[polygon->point_num-1]);
	pDC->LineTo(point);
	last_mouse_location = point;
}

void CWorkerPolygon::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if (nChar!=27)
	{
		return;
	}
	if (!starting)
	{
		return;
	}
	if (polygon->point_num<=2)
	{
		starting = FALSE;
		delete polygon;
		polygon = NULL;
		return;
	}
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CDemo8Doc *pDoc = (CDemo8Doc *)pFrame->GetActiveDocument();
	polygon->color = pDoc->current_color;
	pDoc->productions[pDoc->production_number++] = polygon;
	pDoc->UpdateAllViews(NULL);
	starting = FALSE;
	polygon = NULL;
}
