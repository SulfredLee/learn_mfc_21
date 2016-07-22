
// 010_SDIDoc.h : interface of the CMy010_SDIDoc class
//


#pragma once
#include "afxcoll.h"

class CLine;
class CMy010_SDIDoc : public CDocument
{
protected: // create from serialization only
	CMy010_SDIDoc();
	DECLARE_DYNCREATE(CMy010_SDIDoc)

// Attributes
public:

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CMy010_SDIDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	CObArray m_oaLines;
	CLine* AddLine(CPoint ptFrom, CPoint ptTo);
	int GetLineCount();
	CLine* GetLine(int nIndex);
	// override
	void DeleteContents();
	static const COLORREF m_crColors[8];
private:
	UINT m_nColor;
public:
	UINT GetColor();
	afx_msg void OnColorBlack();
	afx_msg void OnUpdateColorBlack(CCmdUI *pCmdUI);
	afx_msg void OnColorBlue();
	afx_msg void OnUpdateColorBlue(CCmdUI *pCmdUI);
	afx_msg void OnColorGreen();
	afx_msg void OnUpdateColorGreen(CCmdUI *pCmdUI);
	afx_msg void OnColorCyan();
	afx_msg void OnUpdateColorCyan(CCmdUI *pCmdUI);
	afx_msg void OnColorRed();
	afx_msg void OnUpdateColorRed(CCmdUI *pCmdUI);
	afx_msg void OnColorMagenta();
	afx_msg void OnUpdateColorMagenta(CCmdUI *pCmdUI);
	afx_msg void OnColorYellow();
	afx_msg void OnUpdateColorYellow(CCmdUI *pCmdUI);
	afx_msg void OnColorWhite();
	afx_msg void OnUpdateColorWhite(CCmdUI *pCmdUI);
};
