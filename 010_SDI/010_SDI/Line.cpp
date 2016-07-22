// Line.cpp : implementation file
//

#include "stdafx.h"
#include "010_SDI.h"
#include "Line.h"

IMPLEMENT_SERIAL(CLine, CObject, 1)
// CLine

CLine::CLine()
: m_ptFrom(0)
, m_ptTo(0)
{
}

CLine::~CLine()
{
}


// CLine member functions


CLine::CLine(CPoint ptFrom, CPoint ptTo)
{
	// Initialize the from and to points
	m_ptFrom = ptFrom;
	m_ptTo = ptTo;
}


void CLine::Draw(CDC* pDC)
{
	// Create a pen
	CPen lpen(PS_SOLID, 1, m_crColor);

	// Set the new pen as the drawing object
	CPen* pOldPen = pDC->SelectObject(&lpen);
	// Draw the line
	pDC->MoveTo(m_ptFrom);
	pDC->LineTo(m_ptTo);
	// Reset the previous pen
	pDC->SelectObject(pOldPen);
}


void CLine::Serialize(CArchive& ar)
{
	CObject::Serialize(ar);
	if (ar.IsStoring())
	{	// storing code
		ar << m_ptFrom << m_ptTo << (DWORD)m_crColor;
	}
	else
	{	// loading code
		ar >> m_ptFrom >> m_ptTo >> (DWORD)m_crColor;
	}
}


CLine::CLine(CPoint ptFrom, CPoint ptTo, COLORREF crColor)
{
	// Initialize the from and to points
	m_ptFrom = ptFrom;
	m_ptTo = ptTo;
	m_crColor = crColor;
}
