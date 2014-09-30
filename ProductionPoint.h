// ProductionPoint.h: interface for the CProductionPoint class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PRODUCTIONPOINT_H__820A1E59_CF57_4031_8239_610D88AD8841__INCLUDED_)
#define AFX_PRODUCTIONPOINT_H__820A1E59_CF57_4031_8239_610D88AD8841__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Production.h"
#include "GlobalAgent.h"

class CProductionPoint : public CProduction  
{
public:
	CProductionPoint();
	virtual ~CProductionPoint();

public:
	int x;
	int y;

public:
	void draw(CDC *pDC);
};

#endif // !defined(AFX_PRODUCTIONPOINT_H__820A1E59_CF57_4031_8239_610D88AD8841__INCLUDED_)
