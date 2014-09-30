// WorkerPolygon.h: interface for the CWorkerPolygon class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_WORKERPOLYGON_H__2DD8D19F_41F5_405D_87D6_308010018AE1__INCLUDED_)
#define AFX_WORKERPOLYGON_H__2DD8D19F_41F5_405D_87D6_308010018AE1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Worker.h"
#include "ProductionPolygon.h"

class CWorkerPolygon : public CWorker  
{
public:
	CWorkerPolygon();
	virtual ~CWorkerPolygon();

public:
	bool starting;
	CProductionPolygon *polygon;
	CPoint last_mouse_location;

public:
	void OnLButtonDown(UINT nFlags, CPoint point);
	void OnLButtonUp(UINT nFlags, CPoint point);
	void OnMouseMove(UINT nFlags, CPoint point);
	void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);


};

#endif // !defined(AFX_WORKERPOLYGON_H__2DD8D19F_41F5_405D_87D6_308010018AE1__INCLUDED_)
