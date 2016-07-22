
// 010_SDIView.cpp : implementation of the CMy010_SDIView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "010_SDI.h"
#endif

#include "010_SDIDoc.h"
#include "010_SDIView.h"
#include "Line.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy010_SDIView

IMPLEMENT_DYNCREATE(CMy010_SDIView, CView)

BEGIN_MESSAGE_MAP(CMy010_SDIView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMy010_SDIView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMy010_SDIView construction/destruction

CMy010_SDIView::CMy010_SDIView()
: m_ptPrevPos(0)
{
	// TODO: add construction code here

}

CMy010_SDIView::~CMy010_SDIView()
{
}

BOOL CMy010_SDIView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMy010_SDIView drawing

void CMy010_SDIView::OnDraw(CDC* pDC)
{
	CMy010_SDIDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here

	// Get the number of lines in the document
	int liCount = pDoc->GetLineCount();

	// Are there any lines in the document?
	if (liCount)
	{
		int liPos;
		CLine *lptLine;

		// Loop through the lines in the document
		for (liPos = 0; liPos < liCount; liPos++)
		{
			// Get the from and to point for each line
			lptLine = pDoc->GetLine(liPos);
			// Draw the line
			lptLine->Draw(pDC);
		}
	}
}


// CMy010_SDIView printing


void CMy010_SDIView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMy010_SDIView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMy010_SDIView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMy010_SDIView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CMy010_SDIView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMy010_SDIView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMy010_SDIView diagnostics

#ifdef _DEBUG
void CMy010_SDIView::AssertValid() const
{
	CView::AssertValid();
}

void CMy010_SDIView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy010_SDIDoc* CMy010_SDIView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy010_SDIDoc)));
	return (CMy010_SDIDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy010_SDIView message handlers


void CMy010_SDIView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	// Capture the mouse, so no other application can
	// grab it if the mouse leaves the window area
	SetCapture();
	// Save the point
	m_ptPrevPos = point;

	CView::OnLButtonDown(nFlags, point);
}


void CMy010_SDIView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	// Have we captured the mouse?
	if (GetCapture() == this)
		// If so, release it so other applications can have it
		ReleaseCapture();

	CView::OnLButtonUp(nFlags, point);
}


void CMy010_SDIView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	// Check to see if the left mouse button is down
	if ((nFlags & MK_LBUTTON) == MK_LBUTTON)
	{
		// Have we captured the mouse?
		if (GetCapture() == this)
		{
			// Get the Device Context
			CClientDC dc(this);

			// Add the line to the document
			CLine *pLine = GetDocument()->AddLine(m_ptPrevPos, point);

			// Draw the current stretch of line
			pLine->Draw(&dc);

			// Save the current point as the previous point
			m_ptPrevPos = point;
		}
	}
	CView::OnMouseMove(nFlags, point);
}
