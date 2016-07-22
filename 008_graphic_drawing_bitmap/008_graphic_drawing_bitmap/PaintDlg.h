#pragma once


class CMy008_graphic_drawing_bitmapDlg;
class CPaintDlg : public CDialog
{
	DECLARE_DYNAMIC(CPaintDlg)

public:
	CPaintDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CPaintDlg();

// Dialog Data
	enum { IDD = IDD_PAINT_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	static const COLORREF m_crColors[8];
private:
	void DrawLine(CPaintDC* pdc, int iColor);
public:
	afx_msg void OnPaint();
	void DrawRegion(CPaintDC* pdc, int iColor, int iTool, int iShape);
private:
	void ShowBitmap(CPaintDC* pdc, CWnd* pWnd);
};
