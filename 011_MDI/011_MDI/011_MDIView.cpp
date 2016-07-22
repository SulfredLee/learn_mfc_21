
// 011_MDIView.cpp : implementation of the CMy011_MDIView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "011_MDI.h"
#endif

#include "011_MDIDoc.h"
#include "011_MDIView.h"
#include "Line.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy011_MDIView

IMPLEMENT_DYNCREATE(CMy011_MDIView, CView)

BEGIN_MESSAGE_MAP(CMy011_MDIView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMy011_MDIView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMy011_MDIView construction/destruction

CMy011_MDIView::CMy011_MDIView()
{
	// TODO: add construction code here

}

CMy011_MDIView::~CMy011_MDIView()
{
}

BOOL CMy011_MDIView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMy011_MDIView drawing

void CMy011_MDIView::OnDraw(CDC* /*pDC*/)
{
	CMy011_MDIDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CMy011_MDIView printing


void CMy011_MDIView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMy011_MDIView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMy011_MDIView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMy011_MDIView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CMy011_MDIView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMy011_MDIView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
	CMenu menu;

	// Load the context menu
	menu.LoadMenu(IDR_CONTEXTMENU);
	// Get the first sub menu (the real menu)
	CMenu *pContextMenu = menu.GetSubMenu(0);

	// Display the context menu for the user
	pContextMenu->TrackPopupMenu(TPM_LEFTALIGN |
		TPM_LEFTBUTTON | TPM_RIGHTBUTTON,
		point.x, point.y, AfxGetMainWnd());
//#ifndef SHARED_HANDLERS
//	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
//#endif
}


// CMy011_MDIView diagnostics

#ifdef _DEBUG
void CMy011_MDIView::AssertValid() const
{
	CView::AssertValid();
}

void CMy011_MDIView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy011_MDIDoc* CMy011_MDIView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy011_MDIDoc)));
	return (CMy011_MDIDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy011_MDIView message handlers


void CMy011_MDIView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	// Capture the mouse, so no other application can
	// grab it if the mouse leaves the window area
	SetCapture();
	// Save the point
	m_ptPrevPos = point;

	CView::OnLButtonDown(nFlags, point);
}


void CMy011_MDIView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	// Have we captured the mouse?
	if (GetCapture() == this)
		// If so, release it so other applications can have it
		ReleaseCapture();

	CView::OnLButtonUp(nFlags, point);
}


void CMy011_MDIView::OnMouseMove(UINT nFlags, CPoint point)
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
