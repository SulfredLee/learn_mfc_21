#pragma once

// CLine command target

class CLine : public CObject
{
	DECLARE_SERIAL(CLine)
public:
	CLine();
	virtual ~CLine();
private:
	CPoint m_ptFrom;
	CPoint m_ptTo;
public:
	CLine(CPoint ptFrom, CPoint ptTo);
	void Draw(CDC* pDC);
	virtual void Serialize(CArchive& ar);
	CLine(CPoint ptFrom, CPoint ptTo, COLORREF crColor);
	COLORREF m_crColor;
};


