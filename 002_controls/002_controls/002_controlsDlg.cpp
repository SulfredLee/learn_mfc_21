
// 002_controlsDlg.cpp : implementation file
//

#include "stdafx.h"
#include "002_controls.h"
#include "002_controlsDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMy002_controlsDlg dialog



CMy002_controlsDlg::CMy002_controlsDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMy002_controlsDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy002_controlsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_EDIT_MSG, m_IDC_EDIT_MSG);
	DDX_Control(pDX, IDC_COMBO_PROGTORUN, m_strProgToRun);
	DDX_Control(pDX, IDC_EDIT_MSG, m_strMessage);
	//  DDX_Control(pDX, IDC_CHECK_CKENBLPGM, m_bEnableMsg);
	DDX_Control(pDX, IDC_CHECK_CKENBLPGM, m_bEnablePgm);
	DDX_Control(pDX, IDC_CHECK_CKENBLMSG, m_bEnableMsg);
	DDX_Control(pDX, IDC_CHECK_CKSHWMSG, m_bShowMsg);
	DDX_Control(pDX, IDC_CHECK_CKSHWPGM, m_bShowPgm);
}

BEGIN_MESSAGE_MAP(CMy002_controlsDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_EXIT, &CMy002_controlsDlg::OnClickedButtonExit)
	ON_BN_CLICKED(IDC_BUTTON_SHWMSG, &CMy002_controlsDlg::OnClickedButtonShwmsg)
	ON_BN_CLICKED(IDC_BUTTON_CLRMSG, &CMy002_controlsDlg::OnClickedButtonClrmsg)
	ON_BN_CLICKED(IDC_CHECK_CKENBLMSG, &CMy002_controlsDlg::OnClickedCheckCkenblmsg)
	ON_BN_CLICKED(IDC_CHECK_CKSHWMSG, &CMy002_controlsDlg::OnBnClickedCheckCkshwmsg)
END_MESSAGE_MAP()


// CMy002_controlsDlg message handlers

BOOL CMy002_controlsDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	m_bEnableMsg.SetCheck(TRUE);
	m_bShowMsg.SetCheck(TRUE);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMy002_controlsDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMy002_controlsDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMy002_controlsDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMy002_controlsDlg::OnClickedButtonExit()
{
	// TODO: Add your control notification handler code here
	// Exit the program
	OnOK();
}


void CMy002_controlsDlg::OnClickedButtonShwmsg()
{
	// TODO: Add your control notification handler code here

	CString sWindowText;
	m_strMessage.GetWindowText(sWindowText);
	MessageBox(sWindowText);
}


void CMy002_controlsDlg::OnClickedButtonClrmsg()
{
	// TODO: Add your control notification handler code here
	m_strMessage.SetWindowText(TEXT(""));
}


void CMy002_controlsDlg::OnClickedCheckCkenblmsg()
{
	// TODO: Add your control notification handler code here
	if (m_bEnableMsg.GetCheck() == BST_CHECKED)
	{
		GetDlgItem(IDC_EDIT_MSG)->EnableWindow(TRUE);
	}
	else
	{
		GetDlgItem(IDC_EDIT_MSG)->EnableWindow(FALSE);
	}
}


void CMy002_controlsDlg::OnBnClickedCheckCkshwmsg()
{
	// TODO: Add your control notification handler code here
	if (m_bShowMsg.GetCheck() == BST_CHECKED)
	{
		GetDlgItem(IDC_EDIT_MSG)->ShowWindow(TRUE);
	}
	else
	{
		GetDlgItem(IDC_EDIT_MSG)->ShowWindow(FALSE);
	}
}
