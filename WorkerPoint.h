// WorkerPoint.h: interface for the CWorkerPoint class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_WORKERPOINT_H__58714E3B_E8E4_4890_8FC8_72732E70C2E0__INCLUDED_)
#define AFX_WORKERPOINT_H__58714E3B_E8E4_4890_8FC8_72732E70C2E0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Worker.h"
#include "GlobalAgent.h"

class CWorkerPoint : public CWorker  
{
public:
	CWorkerPoint();
	virtual ~CWorkerPoint();

public:

public:
	void OnLButtonDown(UINT nFlags, CPoint point);
	void OnLButtonUp(UINT nFlags, CPoint point);
	void OnMouseMove(UINT nFlags, CPoint point);

};

#endif // !defined(AFX_WORKERPOINT_H__58714E3B_E8E4_4890_8FC8_72732E70C2E0__INCLUDED_)
