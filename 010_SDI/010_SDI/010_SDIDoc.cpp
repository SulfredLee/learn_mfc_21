
// 010_SDIDoc.cpp : implementation of the CMy010_SDIDoc class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "010_SDI.h"
#endif

#include "010_SDIDoc.h"
#include "Line.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMy010_SDIDoc

IMPLEMENT_DYNCREATE(CMy010_SDIDoc, CDocument)

BEGIN_MESSAGE_MAP(CMy010_SDIDoc, CDocument)
	ON_COMMAND(ID_COLOR_BLACK, &CMy010_SDIDoc::OnColorBlack)
	ON_UPDATE_COMMAND_UI(ID_COLOR_BLACK, &CMy010_SDIDoc::OnUpdateColorBlack)
	ON_COMMAND(ID_COLOR_BLUE, &CMy010_SDIDoc::OnColorBlue)
	ON_UPDATE_COMMAND_UI(ID_COLOR_BLUE, &CMy010_SDIDoc::OnUpdateColorBlue)
	ON_COMMAND(ID_COLOR_GREEN, &CMy010_SDIDoc::OnColorGreen)
	ON_UPDATE_COMMAND_UI(ID_COLOR_GREEN, &CMy010_SDIDoc::OnUpdateColorGreen)
	ON_COMMAND(ID_COLOR_CYAN, &CMy010_SDIDoc::OnColorCyan)
	ON_UPDATE_COMMAND_UI(ID_COLOR_CYAN, &CMy010_SDIDoc::OnUpdateColorCyan)
	ON_COMMAND(ID_COLOR_RED, &CMy010_SDIDoc::OnColorRed)
	ON_UPDATE_COMMAND_UI(ID_COLOR_RED, &CMy010_SDIDoc::OnUpdateColorRed)
	ON_COMMAND(ID_COLOR_MAGENTA, &CMy010_SDIDoc::OnColorMagenta)
	ON_UPDATE_COMMAND_UI(ID_COLOR_MAGENTA, &CMy010_SDIDoc::OnUpdateColorMagenta)
	ON_COMMAND(ID_COLOR_YELLOW, &CMy010_SDIDoc::OnColorYellow)
	ON_UPDATE_COMMAND_UI(ID_COLOR_YELLOW, &CMy010_SDIDoc::OnUpdateColorYellow)
	ON_COMMAND(ID_COLOR_WHITE, &CMy010_SDIDoc::OnColorWhite)
	ON_UPDATE_COMMAND_UI(ID_COLOR_WHITE, &CMy010_SDIDoc::OnUpdateColorWhite)
END_MESSAGE_MAP()


// CMy010_SDIDoc construction/destruction

CMy010_SDIDoc::CMy010_SDIDoc()
{
	// TODO: add one-time construction code here

}

CMy010_SDIDoc::~CMy010_SDIDoc()
{
}

BOOL CMy010_SDIDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	// Initialize the color to black
	m_nColor = ID_COLOR_BLACK - ID_COLOR_BLACK;

	return TRUE;
}




// CMy010_SDIDoc serialization

void CMy010_SDIDoc::Serialize(CArchive& ar)
{
	// Pass the serialization on to the object array
	m_oaLines.Serialize(ar);
	//if (ar.IsStoring())
	//{
	//	// TODO: add storing code here
	//}
	//else
	//{
	//	// TODO: add loading code here
	//}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CMy010_SDIDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CMy010_SDIDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data. 
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CMy010_SDIDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CMy010_SDIDoc diagnostics

#ifdef _DEBUG
void CMy010_SDIDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMy010_SDIDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMy010_SDIDoc commands


CLine* CMy010_SDIDoc::AddLine(CPoint ptFrom, CPoint ptTo)
{
	// Create a new CLine object
	CLine *pLine = new CLine(ptFrom, ptTo, m_crColors[m_nColor]);
	try
	{
		// Add the new line to the object array
		m_oaLines.Add(pLine);
		// Mark the document as dirty
		SetModifiedFlag();
	}
	// Did we run into a memory exception?
	catch (CMemoryException* perr)
	{
		// Display a message for the user, giving him or her the
		// bad news
		AfxMessageBox(TEXT("Out of memory"), MB_ICONSTOP | MB_OK);
		// Did we create a line object?
		if (pLine)
		{
			// Delete it
			delete pLine;
			pLine = NULL;
		}
		// Delete the exception object
		perr->Delete();
	}
	return pLine;
}


int CMy010_SDIDoc::GetLineCount()
{
	// Return the array count
	return m_oaLines.GetSize();
}


CLine* CMy010_SDIDoc::GetLine(int nIndex)
{
	// Return a pointer to the line object
	// at the specified point in the object array
	return (CLine*)m_oaLines[nIndex];
}


void CMy010_SDIDoc::DeleteContents()
{
	// Get the number of lines in the object array
	int liCount = m_oaLines.GetSize();
	int liPos;

	// Are there any objects in the array?
	if (liCount)
	{
		// Loop through the array, deleting each object
		for (liPos = 0; liPos < liCount; liPos++)
			delete m_oaLines[liPos];
		// Reset the array
		m_oaLines.RemoveAll();
	}
	CDocument::DeleteContents();
}

const COLORREF CMy010_SDIDoc::m_crColors[8] = {
	RGB(0, 0, 0), // Black
	RGB(0, 0, 255), // Blue
	RGB(0, 255, 0), // Green
	RGB(0, 255, 255), // Cyan
	RGB(255, 0, 0), // Red
	RGB(255, 0, 255), // Magenta
	RGB(255, 255, 0), // Yellow
	RGB(255, 255, 255) // White
};

UINT CMy010_SDIDoc::GetColor()
{
	// Return the current color
	return ID_COLOR_BLACK + m_nColor;
}


void CMy010_SDIDoc::OnColorBlack()
{
	// TODO: Add your command handler code here
	
	// Set the current color to black
	m_nColor = ID_COLOR_BLACK - ID_COLOR_BLACK;
}


void CMy010_SDIDoc::OnUpdateColorBlack(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	
	// Determine if the Black menu entry should be checked
	pCmdUI->SetCheck(GetColor() == ID_COLOR_BLACK ? 1 : 0);
}


void CMy010_SDIDoc::OnColorBlue()
{
	// TODO: Add your command handler code here

	// Set the current color to blue
	m_nColor = ID_COLOR_BLUE - ID_COLOR_BLACK;
}


void CMy010_SDIDoc::OnUpdateColorBlue(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here

	// Determine if the Blue menu entry should be checked
	pCmdUI->SetCheck(GetColor() == ID_COLOR_BLUE ? 1 : 0);
}


void CMy010_SDIDoc::OnColorGreen()
{
	// TODO: Add your command handler code here

	// Set the current color to blue
	m_nColor = ID_COLOR_GREEN - ID_COLOR_BLACK;
}


void CMy010_SDIDoc::OnUpdateColorGreen(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here

	// Determine if the Blue menu entry should be checked
	pCmdUI->SetCheck(GetColor() == ID_COLOR_GREEN ? 1 : 0);
}


void CMy010_SDIDoc::OnColorCyan()
{
	// TODO: Add your command handler code here

	// Set the current color to blue
	m_nColor = ID_COLOR_CYAN - ID_COLOR_BLACK;
}


void CMy010_SDIDoc::OnUpdateColorCyan(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here

	// Determine if the Blue menu entry should be checked
	pCmdUI->SetCheck(GetColor() == ID_COLOR_CYAN ? 1 : 0);
}


void CMy010_SDIDoc::OnColorRed()
{
	// TODO: Add your command handler code here

	// Set the current color to red
	m_nColor = ID_COLOR_RED - ID_COLOR_BLACK;
}


void CMy010_SDIDoc::OnUpdateColorRed(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here

	// Determine if the Red menu entry should be checked
	pCmdUI->SetCheck(GetColor() == ID_COLOR_RED ? 1 : 0);
}


void CMy010_SDIDoc::OnColorMagenta()
{
	// TODO: Add your command handler code here

	// Set the current color to magenta
	m_nColor = ID_COLOR_MAGENTA - ID_COLOR_BLACK;
}


void CMy010_SDIDoc::OnUpdateColorMagenta(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here

	// Determine if the Magenta menu entry should be checked
	pCmdUI->SetCheck(GetColor() == ID_COLOR_MAGENTA ? 1 : 0);
}


void CMy010_SDIDoc::OnColorYellow()
{
	// TODO: Add your command handler code here

	// Set the current color to yellow
	m_nColor = ID_COLOR_YELLOW - ID_COLOR_BLACK;
}


void CMy010_SDIDoc::OnUpdateColorYellow(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here

	// Determine if the Magenta menu entry should be checked
	pCmdUI->SetCheck(GetColor() == ID_COLOR_YELLOW ? 1 : 0);
}


void CMy010_SDIDoc::OnColorWhite()
{
	// TODO: Add your command handler code here

	// Set the current color to white
	m_nColor = ID_COLOR_WHITE - ID_COLOR_BLACK;
}


void CMy010_SDIDoc::OnUpdateColorWhite(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here

	// Determine if the Magenta menu entry should be checked
	pCmdUI->SetCheck(GetColor() == ID_COLOR_WHITE ? 1 : 0);
}
