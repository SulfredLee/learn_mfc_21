
// 004_timerDlg.h : header file
//

#pragma once
#include "afxwin.h"


// CMy004_timerDlg dialog
class CMy004_timerDlg : public CDialogEx
{
// Construction
public:
	CMy004_timerDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_MY004_TIMER_DIALOG };

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
//	CButton m_IDC_STATTIME;
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
protected:
	CStatic m_IDC_STATICTIME;
	int m_iCount;
	CString m_sCount;
	int m_iInterval;
public:
	afx_msg void OnBnClickedStarttime();
	afx_msg void OnBnClickedStoptimer();
protected:
	CStatic m_IDC_STATICCOUNT;
};
