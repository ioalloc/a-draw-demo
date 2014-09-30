// ProductionLine.cpp: implementation of the CProductionLine class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Demo8.h"
#include "ProductionLine.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CProductionLine::CProductionLine()
{

}

CProductionLine::~CProductionLine()
{

}

void CProductionLine::draw(CDC *pDC)
{
	CGlobalAgent::showMessageOnStatusBar("I am a great line");
	CPen pen;
	pen.CreatePen(PS_SOLID,1,color);
	pDC->SelectObject(pen);
	pDC->MoveTo(start);
	pDC->LineTo(end);
}
