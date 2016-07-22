
// 005_dialogDlg.h : header file
//

#pragma once
#include "afxwin.h"
#include "MsgDlg.h"


// CMy005_dialogDlg dialog
class CMy005_dialogDlg : public CDialogEx
{
// Construction
public:
	CMy005_dialogDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_MY005_DIALOG_DIALOG };

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
	CEdit m_IDC_RESULTS;
	CButton m_IDC_BWHICHOPTION;
	CMsgDlg m_dMsgDlg;
public:
	afx_msg void OnBnClickedYesnocancel();
	afx_msg void OnBnClickedExit();
	afx_msg void OnBnClickedFileopen();
	afx_msg void OnBnClickedBcustomdialog();
	afx_msg void OnBnClickedBwhichoption();
};
