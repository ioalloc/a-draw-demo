// Production.h: interface for the CProduction class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PRODUCTION_H__266545B1_0D2D_4477_BAC9_CAC71F58DCB9__INCLUDED_)
#define AFX_PRODUCTION_H__266545B1_0D2D_4477_BAC9_CAC71F58DCB9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CProduction  
{
public:
	CProduction();
	virtual ~CProduction();

public:
	COLORREF color;
	int size;

public:
	virtual void draw(CDC *pDC)=0;

};

#endif // !defined(AFX_PRODUCTION_H__266545B1_0D2D_4477_BAC9_CAC71F58DCB9__INCLUDED_)
