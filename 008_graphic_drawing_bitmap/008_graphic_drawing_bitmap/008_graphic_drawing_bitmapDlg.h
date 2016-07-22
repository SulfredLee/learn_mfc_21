
// 008_graphic_drawing_bitmapDlg.h : header file
//

#pragma once

class CPaintDlg;
// CMy008_graphic_drawing_bitmapDlg dialog
class CMy008_graphic_drawing_bitmapDlg : public CDialogEx
{
// Construction
public:
	CMy008_graphic_drawing_bitmapDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_MY008_GRAPHIC_DRAWING_BITMAP_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	int m_iTool;
	int m_iShape;
	int m_iColor;
	CPaintDlg* m_dlgPaint;
	CString m_sBitmap;
	CBitmap m_bmpBitmap;
	afx_msg void OnRSelection();
	afx_msg void OnBnClickedBexit();
	afx_msg void OnBnClickedBbitmap();
};
