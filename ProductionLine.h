// ProductionLine.h: interface for the CProductionLine class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PRODUCTIONLINE_H__10A86C56_5A4B_4566_8533_FC1672D826A3__INCLUDED_)
#define AFX_PRODUCTIONLINE_H__10A86C56_5A4B_4566_8533_FC1672D826A3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Production.h"
#include "GlobalAgent.h"

class CProductionLine : public CProduction  
{
public:
	CProductionLine();
	virtual ~CProductionLine();

public:
	CPoint start;
	CPoint end;
public:
	void draw(CDC *pDC);

};

#endif // !defined(AFX_PRODUCTIONLINE_H__10A86C56_5A4B_4566_8533_FC1672D826A3__INCLUDED_)
