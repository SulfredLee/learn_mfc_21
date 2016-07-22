
// 005_dialogDlg.cpp : implementation file
//

#include "stdafx.h"
#include "005_dialog.h"
#include "005_dialogDlg.h"
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


// CMy005_dialogDlg dialog



CMy005_dialogDlg::CMy005_dialogDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMy005_dialogDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy005_dialogDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_RESULTS, m_IDC_RESULTS);
	DDX_Control(pDX, IDC_BWHICHOPTION, m_IDC_BWHICHOPTION);
}

BEGIN_MESSAGE_MAP(CMy005_dialogDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_YESNOCANCEL, &CMy005_dialogDlg::OnBnClickedYesnocancel)
	ON_BN_CLICKED(IDC_EXIT, &CMy005_dialogDlg::OnBnClickedExit)
	ON_BN_CLICKED(IDC_FILEOPEN, &CMy005_dialogDlg::OnBnClickedFileopen)
	ON_BN_CLICKED(IDC_BCUSTOMDIALOG, &CMy005_dialogDlg::OnBnClickedBcustomdialog)
	ON_BN_CLICKED(IDC_BWHICHOPTION, &CMy005_dialogDlg::OnBnClickedBwhichoption)
END_MESSAGE_MAP()


// CMy005_dialogDlg message handlers

BOOL CMy005_dialogDlg::OnInitDialog()
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

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMy005_dialogDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy005_dialogDlg::OnPaint()
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
HCURSOR CMy005_dialogDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMy005_dialogDlg::OnBnClickedYesnocancel()
{
	// TODO: Add your control notification handler code here
	int iResults; // This variable will capture the button selection

	// Ask the user
	iResults = MessageBox(TEXT("Press the Yes, No, or Cancel button"),
		TEXT("Yes, No, Cancel Dialog"),
		MB_YESNOCANCEL | MB_ICONINFORMATION);

	CString m_sResults;
	// Determine which button the user clicked
	// Give the user a message showing which button was clicked
	switch (iResults)
	{
	case IDYES: // The Yes button?
		m_sResults = TEXT("Yes!Yes!Yes!");
		m_IDC_RESULTS.SetWindowText(m_sResults);
		break;
	case IDNO: // The No button?
		m_sResults =TEXT("No, no, no, no, no.");
		m_IDC_RESULTS.SetWindowText(m_sResults);
		break;
	case IDCANCEL: // The Cancel button?
		m_sResults = TEXT("Sorry, canceled.");
		m_IDC_RESULTS.SetWindowText(m_sResults);
		break;
	default:
		break;
	}
}


void CMy005_dialogDlg::OnBnClickedExit()
{
	// TODO: Add your control notification handler code here
	OnOK();
}


void CMy005_dialogDlg::OnBnClickedFileopen()
{
	// TODO: Add your control notification handler code here
	CFileDialog m_ldFile(TRUE);

	// Show the File open dialog and capture the result
	if (m_ldFile.DoModal() == IDOK)
	{
		// Get the filename selected
		CString m_sResults;
		m_sResults = m_ldFile.GetFileName();
		m_IDC_RESULTS.SetWindowText(m_sResults);
	}
}


void CMy005_dialogDlg::OnBnClickedBcustomdialog()
{
	// TODO: Add your control notification handler code here
	if (m_dMsgDlg.DoModal() == IDOK)
	{
		// The user checked OK, display the message the
		// user typed in on the message dialog
		CString strTemp;
		strTemp = m_dMsgDlg.m_strTemp;
		m_IDC_RESULTS.SetWindowText(strTemp);

		//// Enable the Which Option button
		m_IDC_BWHICHOPTION.EnableWindow(TRUE);
	}
}


void CMy005_dialogDlg::OnBnClickedBwhichoption()
{
	// TODO: Add your control notification handler code here
	// Determine which radio button was selected, and display
	// a message for the user to show which one was selected.
	CString m_sResults;
	switch (m_dMsgDlg.m_IDC_OPTION1)
	{
	case 0: // Was it the first radio button?
		m_sResults = TEXT("The first option was selected.");
		break;
	case 1: // Was it the second radio button?
		m_sResults = TEXT("The second option was selected.");
		break;
	case 2: // Was it the third radio button?
		m_sResults = TEXT("The third option was selected.");
		break;
	case 3: // Was it the fourth radio button?
		m_sResults = TEXT("The fourth option was selected.");
		break;
	default: // Were none of the radio buttons selected?
		m_sResults = TEXT("No option was selected.");
		break;
	}
	m_IDC_RESULTS.SetWindowText(m_sResults);
}
