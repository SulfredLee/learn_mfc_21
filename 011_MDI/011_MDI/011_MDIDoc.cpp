
// 011_MDIDoc.cpp : implementation of the CMy011_MDIDoc class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "011_MDI.h"
#endif

#include "011_MDIDoc.h"
#include "Line.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMy011_MDIDoc

IMPLEMENT_DYNCREATE(CMy011_MDIDoc, CDocument)

BEGIN_MESSAGE_MAP(CMy011_MDIDoc, CDocument)
	ON_COMMAND_RANGE(ID_COLOR_BLACK, ID_COLOR_WHITE, OnColorCommand)
	ON_UPDATE_COMMAND_UI_RANGE(ID_COLOR_BLACK, ID_COLOR_WHITE, OnUpdateColorUI)
END_MESSAGE_MAP()


// CMy011_MDIDoc construction/destruction

CMy011_MDIDoc::CMy011_MDIDoc()
{
	// TODO: add one-time construction code here
	m_nColor = ID_COLOR_BLACK - ID_COLOR_BLACK;
}

CMy011_MDIDoc::~CMy011_MDIDoc()
{
}

BOOL CMy011_MDIDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CMy011_MDIDoc serialization

void CMy011_MDIDoc::Serialize(CArchive& ar)
{
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
void CMy011_MDIDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
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
void CMy011_MDIDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data. 
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CMy011_MDIDoc::SetSearchContent(const CString& value)
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

// CMy011_MDIDoc diagnostics

#ifdef _DEBUG
void CMy011_MDIDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMy011_MDIDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMy011_MDIDoc commands

const COLORREF CMy011_MDIDoc::m_crColors[8] = {
	RGB(0, 0, 0), // Black
	RGB(0, 0, 255), // Blue
	RGB(0, 255, 0), // Green
	RGB(0, 255, 255), // Cyan
	RGB(255, 0, 0), // Red
	RGB(255, 0, 255), // Magenta
	RGB(255, 255, 0), // Yellow
	RGB(255, 255, 255) // White
};
CLine* CMy011_MDIDoc::AddLine(CPoint ptFrom, CPoint ptTo)
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


int CMy011_MDIDoc::GetLineCount()
{
	// Return the array count
	return m_oaLines.GetSize();
}


CLine* CMy011_MDIDoc::GetLine(int nIndex)
{
	// Return a pointer to the line object
	// at the specified point in the object array
	return (CLine*)m_oaLines[nIndex];
}


void CMy011_MDIDoc::DeleteContents()
{
	// TODO: Add your specialized code here and/or call the base class
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


UINT CMy011_MDIDoc::GetColor()
{
	// Return the current color
	return ID_COLOR_BLACK + m_nColor;
}

void CMy011_MDIDoc::OnColorCommand(UINT nID)
{
	// Set the current color
	m_nColor = nID - ID_COLOR_BLACK;
}

void CMy011_MDIDoc::OnUpdateColorUI(CCmdUI* pCmdUI)
{
	// Determine if the menu entry should be checked
	pCmdUI->SetCheck(GetColor() == pCmdUI->m_nID ? 1 : 0);
}