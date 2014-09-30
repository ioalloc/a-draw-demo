// Demo8Doc.h : interface of the CDemo8Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DEMO8DOC_H__6B21E6D9_A26F_4598_8F50_3B76321EEA18__INCLUDED_)
#define AFX_DEMO8DOC_H__6B21E6D9_A26F_4598_8F50_3B76321EEA18__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Production.h"
#include "Worker.h"

class CDemo8Doc : public CDocument
{
protected: // create from serialization only
	CDemo8Doc();
	DECLARE_DYNCREATE(CDemo8Doc)

// Attributes
public:
	CProduction *productions[1000];
	int production_number;

	COLORREF current_color;

	CWorker *worker;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDemo8Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	void SetWorker(CWorker *w);
	virtual ~CDemo8Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDemo8Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEMO8DOC_H__6B21E6D9_A26F_4598_8F50_3B76321EEA18__INCLUDED_)
