// ProductionPolygon.cpp: implementation of the CProductionPolygon class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Demo8.h"
#include "ProductionPolygon.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CProductionPolygon::CProductionPolygon()
{
	point_num = 0;
}

CProductionPolygon::~CProductionPolygon()
{

}

void CProductionPolygon::draw(CDC *pDC)
{
	CPen pen;
	pen.CreatePen(PS_SOLID,1,color);
	pDC->SelectObject(pen);

	for(int i = 0;i<point_num;i++)
	{
		pDC->MoveTo(points[i].x,points[i].y);
		pDC->LineTo(points[(i+1)%point_num].x,points[(i+1)%point_num].y);
	}
}
