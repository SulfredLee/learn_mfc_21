
// 007_font_textDlg.h : header file
//

#pragma once
#include "afxwin.h"

int CALLBACK EnumFontFamProc(LPENUMLOGFONT lpelf,
	LPNEWTEXTMETRIC lpntm, DWORD nFontType, long lParam);
// CMy007_font_textDlg dialog
class CMy007_font_textDlg : public CDialogEx
{
// Construction
public:
	CMy007_font_textDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_MY007_FONT_TEXT_DIALOG };

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
	CStatic m_ctlDisplayText;
	CString m_strDisplayText;
	CListBox m_ctlFontList;
	CString m_strFontName;
	CString m_strSampText;
private:
	void FillFontList();
public:
	afx_msg void OnBnClickedExit();
	afx_msg void OnChangeEsamptext();
private:
	void SetMyFont();
	CFont m_fSampFont;
public:
	afx_msg void OnSelchangeLfonts();
};
