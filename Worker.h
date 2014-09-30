// Worker.h: interface for the CWorker class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_WORKER_H__C387EAE4_0BCA_4320_B32B_30173DD342E6__INCLUDED_)
#define AFX_WORKER_H__C387EAE4_0BCA_4320_B32B_30173DD342E6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

enum TYPE{TYPE_POINT,TYPE_LINE,TYPE_POLYGON};

class CWorker  
{
public:
	CWorker();
	virtual ~CWorker();

public:
	int type;

public:
	virtual void OnLButtonDown(UINT nFlags, CPoint point) = 0;
	virtual void OnLButtonUp(UINT nFlags, CPoint point) = 0;
	virtual void OnMouseMove(UINT nFlags, CPoint point) = 0;
	virtual void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags){};

};

#endif // !defined(AFX_WORKER_H__C387EAE4_0BCA_4320_B32B_30173DD342E6__INCLUDED_)
