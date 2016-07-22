
// 006_menusDlg.h : header file
//

#pragma once


// CMy006_menusDlg dialog
class CMy006_menusDlg : public CDialogEx
{
// Construction
public:
	CMy006_menusDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_MY006_MENUS_DIALOG };

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
	afx_msg void OnBnClickedExit();
	afx_msg void OnFileHello();
	afx_msg void OnHelpAbout();
	afx_msg void OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/);
};
