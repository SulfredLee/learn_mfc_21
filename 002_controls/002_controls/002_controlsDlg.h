
// 002_controlsDlg.h : header file
//

#pragma once
#include "afxwin.h"


// CMy002_controlsDlg dialog
class CMy002_controlsDlg : public CDialogEx
{
// Construction
public:
	CMy002_controlsDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_MY002_CONTROLS_DIALOG };

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
//	CEdit m_IDC_EDIT_MSG;
	CComboBox m_strProgToRun;
protected:
	CEdit m_strMessage;
protected:
//	CButton m_bEnableMsg;
	CButton m_bEnablePgm;
	CButton m_bEnableMsg;
	CButton m_bShowMsg;
	CButton m_bShowPgm;
public:
	afx_msg void OnClickedButtonExit();
	afx_msg void OnClickedButtonShwmsg();
	afx_msg void OnClickedButtonClrmsg();
	afx_msg void OnClickedCheckCkenblmsg();
	afx_msg void OnBnClickedCheckCkshwmsg();
};
