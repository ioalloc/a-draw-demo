// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "Demo8.h"

#include "MainFrm.h"
#include "Worker.h"
#include "Demo8Doc.h"
#include "WorkerLine.h"
#include "WorkerPoint.h"
#include "WorkerPolygon.h"
#include "ProductionPolygon.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_UPDATE_COMMAND_UI(IDT_POINT, OnUpdatePoint)
	ON_UPDATE_COMMAND_UI(IDT_LINE, OnUpdateLine)
	ON_COMMAND(IDT_POINT, OnPoint)
	ON_COMMAND(IDT_LINE, OnLine)
	ON_COMMAND(IDT_COLOR, OnColor)
	ON_UPDATE_COMMAND_UI(IDT_COLOR, OnUpdateColor)
	ON_COMMAND(IDT_POLYGON, OnPolygon)
	ON_UPDATE_COMMAND_UI(IDT_POLYGON, OnUpdatePolygon)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);
	
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers


void CMainFrame::OnUpdatePoint(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	CDemo8Doc *pDoc = (CDemo8Doc*)GetActiveDocument();
	if(pDoc->worker == NULL) return;
	pCmdUI->SetCheck(pDoc->worker->type == TYPE_POINT);
}

void CMainFrame::OnUpdateLine(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	CDemo8Doc *pDoc = (CDemo8Doc*)GetActiveDocument();
	if(pDoc->worker == NULL) return;
	pCmdUI->SetCheck(pDoc->worker->type == TYPE_LINE);
	
}

void CMainFrame::OnPoint() 
{
	// TODO: Add your command handler code here
	CWorkerPoint *w = new CWorkerPoint();
	CDemo8Doc *pDoc = (CDemo8Doc*)GetActiveDocument();
	pDoc->SetWorker(w);
}

void CMainFrame::OnLine() 
{
	// TODO: Add your command handler code here
	CWorkerLine *w = new CWorkerLine();
	CDemo8Doc *pDoc = (CDemo8Doc*)GetActiveDocument();
	pDoc->SetWorker(w);
}

void CMainFrame::OnColor() 
{
	// TODO: Add your command handler code here
	CDemo8Doc *pDoc = (CDemo8Doc*)GetActiveDocument();
	CColorDialog dlg;
	if(dlg.DoModal() == IDOK)
	{
		pDoc->current_color = dlg.GetColor();
	}
	/*
	CWnd *pWnd = m_wndToolBar.GetDlgItem(IDT_COLOR);
	CDC *pDC = pWnd->GetDC();
	CBrush b;
	b.CreateSolidBrush(pDoc->current_color);
	pDC->SelectObject(b);
	pDC->Rectangle(0,0,1000,1000);
	pDC->ReleaseAttribDC();
	pDC->ReleaseOutputDC();
	
	CBitmap bmp;
	bmp.CreateBitmap(16,16,1,16,pDoc->current_color);
	CToolBarCtrl &toolctrl = m_wndToolBar.GetToolBarCtrl();
	int index_red = toolctrl.AddBitmap(1,IDB_COLOR_RED);
	int index = m_wndToolBar.CommandToIndex(IDT_COLOR);
	int iImage;
	UINT nID;
	UINT nStyle;
	m_wndToolBar.GetButtonInfo(index,nID,nStyle,iImage);
	m_wndToolBar.SetButtonInfo(index,nID,nStyle,index_red);*/
}

void CMainFrame::OnUpdateColor(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
}

void CMainFrame::OnPolygon() 
{
	// TODO: Add your command handler code here
	CWorkerPolygon *w = new CWorkerPolygon();
	CDemo8Doc *pDoc = (CDemo8Doc*)GetActiveDocument();
	pDoc->SetWorker(w);

}

void CMainFrame::OnUpdatePolygon(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	CDemo8Doc *pDoc = (CDemo8Doc*)GetActiveDocument();
	if(pDoc->worker == NULL) return;
	pCmdUI->SetCheck(pDoc->worker->type == TYPE_POLYGON);

}
