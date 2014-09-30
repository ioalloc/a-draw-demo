// Demo8View.h : interface of the CDemo8View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DEMO8VIEW_H__7487FA2F_22A1_4BF1_A717_F5EA3E0C0BFC__INCLUDED_)
#define AFX_DEMO8VIEW_H__7487FA2F_22A1_4BF1_A717_F5EA3E0C0BFC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CDemo8Doc;

class CDemo8View : public CView
{
protected: // create from serialization only
	CDemo8View();
	DECLARE_DYNCREATE(CDemo8View)

// Attributes
public:
	CDemo8Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDemo8View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDemo8View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDemo8View)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Demo8View.cpp
inline CDemo8Doc* CDemo8View::GetDocument()
   { return (CDemo8Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEMO8VIEW_H__7487FA2F_22A1_4BF1_A717_F5EA3E0C0BFC__INCLUDED_)
