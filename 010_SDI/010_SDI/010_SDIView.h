
// 010_SDIView.h : interface of the CMy010_SDIView class
//

#pragma once
#include "atltypes.h"


class CMy010_SDIView : public CView
{
protected: // create from serialization only
	CMy010_SDIView();
	DECLARE_DYNCREATE(CMy010_SDIView)

// Attributes
public:
	CMy010_SDIDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CMy010_SDIView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
private:
	CPoint m_ptPrevPos;
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // debug version in 010_SDIView.cpp
inline CMy010_SDIDoc* CMy010_SDIView::GetDocument() const
   { return reinterpret_cast<CMy010_SDIDoc*>(m_pDocument); }
#endif

