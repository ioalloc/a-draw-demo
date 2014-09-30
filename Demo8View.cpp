// Demo8View.cpp : implementation of the CDemo8View class
//

#include "stdafx.h"
#include "Demo8.h"

#include "Demo8Doc.h"
#include "Demo8View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDemo8View

IMPLEMENT_DYNCREATE(CDemo8View, CView)

BEGIN_MESSAGE_MAP(CDemo8View, CView)
	//{{AFX_MSG_MAP(CDemo8View)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_CHAR()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDemo8View construction/destruction

CDemo8View::CDemo8View()
{
	// TODO: add construction code here

}

CDemo8View::~CDemo8View()
{
}

BOOL CDemo8View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDemo8View drawing

void CDemo8View::OnDraw(CDC* pDC)
{
	CDemo8Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	for (int i = 0;i < pDoc->production_number;i++)
	{
		pDoc->productions[i]->draw(pDC);
	}
}

/////////////////////////////////////////////////////////////////////////////
// CDemo8View printing

BOOL CDemo8View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDemo8View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDemo8View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CDemo8View diagnostics

#ifdef _DEBUG
void CDemo8View::AssertValid() const
{
	CView::AssertValid();
}

void CDemo8View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDemo8Doc* CDemo8View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDemo8Doc)));
	return (CDemo8Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDemo8View message handlers

void CDemo8View::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CDemo8Doc* pDoc = GetDocument();
	if (pDoc->worker != NULL)
	{
		pDoc->worker->OnLButtonDown(nFlags,point);
	}
	CView::OnLButtonDown(nFlags, point);
}

void CDemo8View::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CDemo8Doc* pDoc = GetDocument();
	if (pDoc->worker != NULL)
	{
		pDoc->worker->OnLButtonUp(nFlags,point);
	}	
	CView::OnLButtonUp(nFlags, point);
}

void CDemo8View::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CDemo8Doc* pDoc = GetDocument();
	if (pDoc->worker != NULL)
	{
		pDoc->worker->OnMouseMove(nFlags,point);
	}	
	CView::OnMouseMove(nFlags, point);
}

void CDemo8View::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	Invalidate();
}

//DEL void CDemo8View::OnPaint() 
//DEL {
//DEL 	CPaintDC dc(this); // device context for painting
//DEL 	
//DEL 	// TODO: Add your message handler code here
//DEL 	
//DEL 	// Do not call CView::OnPaint() for painting messages
//DEL }

void CDemo8View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	CDemo8Doc* pDoc = GetDocument();
	if (pDoc->worker != NULL)
	{
		pDoc->worker->OnChar(nChar,nRepCnt,nFlags);
	}
	// TODO: Add your message handler code here and/or call default
	CView::OnChar(nChar, nRepCnt, nFlags);
}
