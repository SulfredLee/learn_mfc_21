// PaintDlg.cpp : implementation file
//

#include "stdafx.h"
#include "008_graphic_drawing_bitmap.h"
#include "PaintDlg.h"
#include "afxdialogex.h"
#include "008_graphic_drawing_bitmapDlg.h"


// CPaintDlg dialog

IMPLEMENT_DYNAMIC(CPaintDlg, CDialog)

CPaintDlg::CPaintDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPaintDlg::IDD, pParent)
{

}

CPaintDlg::~CPaintDlg()
{
}

void CPaintDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CPaintDlg, CDialog)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CPaintDlg message handlers


BOOL CPaintDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

const COLORREF CPaintDlg:: m_crColors[8] = {
	RGB(0, 0, 0), // Black
	RGB(0, 0, 255), // Blue
	RGB(0, 255, 0), // Green
	RGB(0, 255, 255), // Cyan
	RGB(255, 0, 0), // Red
	RGB(255, 0, 255), // Magenta
	RGB(255, 255, 0), // Yellow
	RGB(255, 255, 255) // White
};

void CPaintDlg::DrawLine(CPaintDC* pdc, int iColor)
{
	// Declare and create the pens
	CPen lSolidPen(PS_SOLID, 1, m_crColors[iColor]);
	CPen lDotPen(PS_DOT, 1, m_crColors[iColor]);
	CPen lDashPen(PS_DASH, 1, m_crColors[iColor]);
	CPen lDashDotPen(PS_DASHDOT, 1, m_crColors[iColor]);
	CPen lDashDotDotPen(PS_DASHDOTDOT, 1, m_crColors[iColor]);
	CPen lNullPen(PS_NULL, 1, m_crColors[iColor]);
	 CPen lInsidePen(PS_INSIDEFRAME, 1, m_crColors[iColor]);
	
	// Get the drawing area
	CRect lRect;
	GetClientRect(lRect);
	lRect.NormalizeRect();
	
	// Calculate the distance between each of the lines
	CPoint pStart;
	CPoint pEnd;
	int liDist = lRect.Height() / 8;
	CPen *lOldPen;
	lOldPen = pdc->SelectObject(&lNullPen);
	// Specify the starting points
	pStart.y = lRect.top;
	pStart.x = lRect.left;
	pEnd.y = pStart.y;
	pEnd.x = lRect.right;
	int i;
	// Loop through the different pens
	for (i = 0; i < 7; i++)
	{
		// Which pen are we on?
		switch (i)
		{
		case 0: // Solid
			lOldPen = pdc->SelectObject(&lSolidPen);
			break;
		case 1: // Dot
			lOldPen = pdc->SelectObject(&lDotPen);
			break;
		case 2: // Dash
			lOldPen = pdc->SelectObject(&lDashPen);
			break;
		case 3: // Dash Dot
			lOldPen = pdc->SelectObject(&lDashDotPen);
			break;
		case 4: // Dash Dot Dot
			lOldPen = pdc->SelectObject(&lDashDotDotPen);
			break;
		case 5: // Null
			lOldPen = pdc->SelectObject(&lNullPen);
			break;
		case 6: // Inside
			lOldPen = pdc->SelectObject(&lInsidePen);
			break;
		default:
			break;
		}
		// Move down to the next position
		pStart.y = pStart.y + liDist;
		pEnd.y = pStart.y;
		// Draw the line
		pdc->MoveTo(pStart);
		pdc->LineTo(pEnd);
	}
	// Select the original pen
	pdc->SelectObject(lOldPen);
}


void CPaintDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: Add your message handler code here
	// Do not call CDialog::OnPaint() for painting messages

	// Get a pointer to the parent window
	CMy008_graphic_drawing_bitmapDlg *pWnd = (CMy008_graphic_drawing_bitmapDlg*)GetParent();
	// Do we have a valid pointer?
	if (pWnd)
	{
		// Is the tool a bitmap?
		if (pWnd->m_iTool == 2)
		{
			// Is there a bitmap selected and loaded?
			if (pWnd->m_sBitmap != "")
				// Display it
				ShowBitmap(&dc, pWnd);
		}
		else // No, we’re drawing a shape
		{
			// Are we drawing a line?
			if (pWnd->m_iShape == 0)
				DrawLine(&dc, pWnd->m_iColor);
			else // We're drawing a ellopse or rectangle
				DrawRegion(&dc, pWnd->m_iColor, pWnd->m_iTool, pWnd->m_iShape);
		}
	}
}


void CPaintDlg::DrawRegion(CPaintDC *pdc, int iColor, int iTool, int iShape)
{
	// Declare and create the pens
	CPen lSolidPen(PS_SOLID, 1, m_crColors[iColor]);
	CPen lDotPen(PS_DOT, 1, m_crColors[iColor]);
	CPen lDashPen(PS_DASH, 1, m_crColors[iColor]);
	CPen lDashDotPen(PS_DASHDOT, 1, m_crColors[iColor]);
	CPen lDashDotDotPen(PS_DASHDOTDOT, 1, m_crColors[iColor]);
	CPen lNullPen(PS_NULL, 1, m_crColors[iColor]);
	CPen lInsidePen(PS_INSIDEFRAME, 1, m_crColors[iColor]);

	// Declare and create the brushes
	CBrush lSolidBrush(m_crColors[iColor]);
	CBrush lBDiagBrush(HS_BDIAGONAL, m_crColors[iColor]);
	CBrush lCrossBrush(HS_CROSS, m_crColors[iColor]);
	CBrush lDiagCrossBrush(HS_DIAGCROSS, m_crColors[iColor]);
	CBrush lFDiagBrush(HS_FDIAGONAL, m_crColors[iColor]);
	CBrush lHorizBrush(HS_HORIZONTAL, m_crColors[iColor]);
	CBrush lVertBrush(HS_VERTICAL, m_crColors[iColor]);
	CBrush lNullBrush(RGB(192, 192, 192));

	// Calculate the size of the drawing regions
	CRect lRect;
	GetClientRect(lRect);
	lRect.NormalizeRect();
	int liVert = lRect.Height() / 2;
	int liHeight = liVert - 10;
	int liHorz = lRect.Width() / 4;
	int liWidth = liHorz - 10;
	CRect lDrawRect;
	CPen *lOldPen;
	CBrush *lOldBrush;
	lOldPen = pdc->SelectObject(&lNullPen);
	lOldBrush = pdc->SelectObject(&lHorizBrush);
	int i;
	// Loop through all of the brushes and pens
	for (i = 0; i < 7; i++)
	{
		switch (i)
		{
		case 0: // Solid
			// Determine the location for this figure.
			// Start the first row
			lDrawRect.top = lRect.top + 5;
			lDrawRect.left = lRect.left + 5;
			lDrawRect.bottom = lDrawRect.top + liHeight;
			lDrawRect.right = lDrawRect.left + liWidth;
			// Select the appropriate pen and brush
			lOldPen = pdc->SelectObject(&lSolidPen);
			lOldBrush = pdc->SelectObject(&lSolidBrush);
			break;
		case 1: // Dot - Back Diagonal
			// Determine the location for this figure.
			lDrawRect.left = lDrawRect.left + liHorz;
			lDrawRect.right = lDrawRect.left + liWidth;
			// Select the appropriate pen and brush
			lOldPen = pdc->SelectObject(&lDotPen);
			lOldBrush = pdc->SelectObject(&lBDiagBrush);
			break;
		case 2: // Dash - Cross Brush
			// Determine the location for this figure.
			lDrawRect.left = lDrawRect.left + liHorz;
			lDrawRect.right = lDrawRect.left + liWidth;
			// Select the appropriate pen and brush
			lOldPen = pdc->SelectObject(&lDashPen);
			lOldBrush = pdc->SelectObject(&lCrossBrush);
			break;
		case 3: // Dash Dot - Diagonal Cross
			// Determine the location for this figure.
			lDrawRect.left = lDrawRect.left + liHorz;
			lDrawRect.right = lDrawRect.left + liWidth;
			// Select the appropriate pen and brush
			lOldPen = pdc->SelectObject(&lDashDotPen);
			lOldBrush = pdc->SelectObject(&lDiagCrossBrush);
			break;
		case 4: // Dash Dot Dot - Forward Diagonal
			// Determine the location for this figure.
			// Start the second row
			lDrawRect.top = lDrawRect.top + liVert;
			lDrawRect.left = lRect.left + 5;
			lDrawRect.bottom = lDrawRect.top + liHeight;
			lDrawRect.right = lDrawRect.left + liWidth;
			// Select the appropriate pen and brush
			lOldPen = pdc->SelectObject(&lDashDotDotPen);
			lOldBrush = pdc->SelectObject(&lFDiagBrush);
			break;
		case 5: // Null - Horizontal
			// Determine the location for this figure.
			lDrawRect.left = lDrawRect.left + liHorz;
			lDrawRect.right = lDrawRect.left + liWidth;
			// Select the appropriate pen and brush
			lOldPen = pdc->SelectObject(&lNullPen);
			lOldBrush = pdc->SelectObject(&lHorizBrush);
			break;
		case 6: // Inside - Vertical
			// Determine the location for this figure.
			lDrawRect.left = lDrawRect.left + liHorz;
			lDrawRect.right = lDrawRect.left + liWidth;
			// Select the appropriate pen and brush
			lOldPen = pdc->SelectObject(&lInsidePen);
			lOldBrush = pdc->SelectObject(&lVertBrush);
			break;
		}
		// Which tool are we using?
		if (iTool == 0)
			pdc->SelectObject(lNullBrush);
		else
			pdc->SelectObject(lNullPen);
		// Which shape are we drawing?
		if (iShape == 1)
			pdc->Ellipse(lDrawRect);
		else
			pdc->Rectangle(lDrawRect);
	}
	// Reset the original brush and pen
	pdc->SelectObject(lOldBrush);
	pdc->SelectObject(lOldPen);
}


void CPaintDlg::ShowBitmap(CPaintDC* pdc, CWnd* pWnd)
{
	// Convert the pointer to a pointer to the main dialog class
	CMy008_graphic_drawing_bitmapDlg *lpWnd = (CMy008_graphic_drawing_bitmapDlg*)pWnd;
	BITMAP bm;
	// Get the loaded bitmap
	lpWnd->m_bmpBitmap.GetBitmap(&bm);
	CDC dcMem;
	// Create a device context to load the bitmap into
	dcMem.CreateCompatibleDC(pdc);
	// Select the bitmap into the compatible device context
	CBitmap* pOldBitmap = (CBitmap*)dcMem.SelectObject(lpWnd->m_bmpBitmap);
	CRect lRect;
	// Get the display area available
	GetClientRect(lRect);
	lRect.NormalizeRect();
	// Copy and resize the bitmap to the dialog window
	pdc->StretchBlt(10, 10, (lRect.Width() - 20),
		(lRect.Height() - 20), &dcMem, 0, 0, bm.bmWidth, bm.bmHeight, SRCCOPY);
}
