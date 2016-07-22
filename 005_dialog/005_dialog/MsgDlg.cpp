// MsgDlg.cpp : implementation file
//

#include "stdafx.h"
#include "005_dialog.h"
#include "MsgDlg.h"
#include "afxdialogex.h"


// CMsgDlg dialog

IMPLEMENT_DYNAMIC(CMsgDlg, CDialog)

CMsgDlg::CMsgDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMsgDlg::IDD, pParent)
	, m_IDC_OPTION1(0)
{
}

CMsgDlg::~CMsgDlg()
{
}

void CMsgDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MESSAGE, m_IDC_MESSAGE);
	DDX_Radio(pDX, IDC_OPTION1, m_IDC_OPTION1);
}


BEGIN_MESSAGE_MAP(CMsgDlg, CDialog)
	ON_BN_CLICKED(IDOK, &CMsgDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CMsgDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CMsgDlg message handlers


BOOL CMsgDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here
	m_IDC_MESSAGE.SetWindowText(TEXT(""));
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void CMsgDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	m_IDC_MESSAGE.GetWindowText(m_strTemp);
	CDialog::OnOK();
}


void CMsgDlg::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	m_IDC_MESSAGE.GetWindowText(m_strTemp);
	CDialog::OnCancel();
}
