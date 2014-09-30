// Demo8Doc.cpp : implementation of the CDemo8Doc class
//

#include "stdafx.h"
#include "Demo8.h"

#include "Demo8Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDemo8Doc

IMPLEMENT_DYNCREATE(CDemo8Doc, CDocument)

BEGIN_MESSAGE_MAP(CDemo8Doc, CDocument)
	//{{AFX_MSG_MAP(CDemo8Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDemo8Doc construction/destruction

CDemo8Doc::CDemo8Doc()
{
	// TODO: add one-time construction code here
	production_number = 0;
	worker = NULL;
	current_color = RGB(0,0,0);
}

CDemo8Doc::~CDemo8Doc()
{
	if (worker != NULL)
	{
		delete worker;
	}
}

BOOL CDemo8Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CDemo8Doc serialization

void CDemo8Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CDemo8Doc diagnostics

#ifdef _DEBUG
void CDemo8Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDemo8Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDemo8Doc commands

void CDemo8Doc::SetWorker(CWorker *w)
{
	if (worker != NULL)
	{
		delete[]worker;
	}
	worker = w;
}
