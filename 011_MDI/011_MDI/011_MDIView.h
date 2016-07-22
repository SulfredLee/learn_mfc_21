
// 011_MDIView.h : interface of the CMy011_MDIView class
//

#pragma once


class CMy011_MDIView : public CView
{
protected: // create from serialization only
	CMy011_MDIView();
	DECLARE_DYNCREATE(CMy011_MDIView)

// Attributes
public:
	CMy011_MDIDoc* GetDocument() const;

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
	virtual ~CMy011_MDIView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
private:
	CPoint m_ptPrevPos;
protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // debug version in 011_MDIView.cpp
inline CMy011_MDIDoc* CMy011_MDIView::GetDocument() const
   { return reinterpret_cast<CMy011_MDIDoc*>(m_pDocument); }
#endif

