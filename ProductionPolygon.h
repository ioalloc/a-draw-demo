// ProductionPolygon.h: interface for the CProductionPolygon class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PRODUCTIONPOLYGON_H__552EC7A9_601C_4A30_957B_74A7F8BDB692__INCLUDED_)
#define AFX_PRODUCTIONPOLYGON_H__552EC7A9_601C_4A30_957B_74A7F8BDB692__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Production.h"

class CProductionPolygon : public CProduction  
{
public:
	CProductionPolygon();
	virtual ~CProductionPolygon();

public:
	int point_num;
	CPoint points[1000];

	void draw(CDC *pDC);


};

#endif // !defined(AFX_PRODUCTIONPOLYGON_H__552EC7A9_601C_4A30_957B_74A7F8BDB692__INCLUDED_)
