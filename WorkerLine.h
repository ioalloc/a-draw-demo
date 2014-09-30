// WorkerLine.h: interface for the CWorkerLine class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_WORKERLINE_H__F0F459C8_B654_4F27_B327_69BB899A978F__INCLUDED_)
#define AFX_WORKERLINE_H__F0F459C8_B654_4F27_B327_69BB899A978F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Worker.h"
#include "GlobalAgent.h"

class CWorkerLine : public CWorker  
{
public:
	CWorkerLine();
	virtual ~CWorkerLine();

public:
	CPoint start;
	CPoint last_mouse_location;
	BOOL started;

public:
	void OnLButtonDown(UINT nFlags, CPoint point);
	void OnLButtonUp(UINT nFlags, CPoint point);
	void OnMouseMove(UINT nFlags, CPoint point);

};

#endif // !defined(AFX_WORKERLINE_H__F0F459C8_B654_4F27_B327_69BB899A978F__INCLUDED_)
