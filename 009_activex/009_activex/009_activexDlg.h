
// 009_activexDlg.h : header file
//

#pragma once
#include "CMSFlexGrid.h"

// CMy009_activexDlg dialog
class CMy009_activexDlg : public CDialogEx
{
// Construction
public:
	CMy009_activexDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_MY009_ACTIVEX_DIALOG };

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
	CMSFlexGrid m_ctlFGrid;
private:
	void LoadData();
	int GenID(int m_iRow, int m_iCol);
	CString RandomStringValue(int m_iColumn);
	void DoSort();
public:
	DECLARE_EVENTSINK_MAP()
	void MouseDownMsfgrid(short Button, short Shift, long x, long y);
private:
	int m_iMouseCol;
public:
	void MouseUpMsfgrid(short Button, short Shift, long x, long y);
};
