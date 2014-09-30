// ProductionPoint.cpp: implementation of the CProductionPoint class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Demo8.h"
#include "ProductionPoint.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CProductionPoint::CProductionPoint()
{
	x = 0;
	y = 0;
}

CProductionPoint::~CProductionPoint()
{

}

void CProductionPoint::draw(CDC *pDC)
{
	CGlobalAgent::showMessageOnStatusBar("I am a great point");
	CPen pen;
	pen.CreatePen(PS_SOLID,1,color);
	pDC->SelectObject(pen);

	pDC->Ellipse(x-5,y-5,x+5,y+5);
}
