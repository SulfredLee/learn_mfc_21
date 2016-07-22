
// 011_MDIDoc.h : interface of the CMy011_MDIDoc class
//


#pragma once

class CLine;
class CMy011_MDIDoc : public CDocument
{
protected: // create from serialization only
	CMy011_MDIDoc();
	DECLARE_DYNCREATE(CMy011_MDIDoc)

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
	virtual ~CMy011_MDIDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnColorCommand(UINT nID);
	afx_msg void OnUpdateColorUI(CCmdUI* pCmdUI);
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	CLine* AddLine(CPoint ptFrom, CPoint ptTo);
	int GetLineCount();
	CLine* GetLine(int nIndex);
	virtual void DeleteContents();
	static const COLORREF m_crColors[8];
	UINT GetColor();
private:
	UINT m_nColor;
	CObArray m_oaLines;
};
