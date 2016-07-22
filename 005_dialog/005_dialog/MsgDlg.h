#pragma once
#include "afxwin.h"


// CMsgDlg dialog

class CMsgDlg : public CDialog
{
	DECLARE_DYNAMIC(CMsgDlg)

public:
	CMsgDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CMsgDlg();

// Dialog Data
	enum { IDD = IDD_MESSAGEDLG };

	CString m_strTemp;
	CEdit m_IDC_MESSAGE;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
	
	
public:
//	afx_msg void OnInitMenuPopup(CMenu* pPopupMenu, UINT nIndex, BOOL bSysMenu);
//	afx_msg void OnUnInitMenuPopup(CMenu *pPopupMenu, UINT nFlags);
//	afx_msg void OnWinIniChange(LPCTSTR lpszSection);
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	int m_IDC_OPTION1;
};
