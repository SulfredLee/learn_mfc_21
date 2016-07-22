
// 004_timerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "004_timer.h"
#include "004_timerDlg.h"
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


// CMy004_timerDlg dialog



CMy004_timerDlg::CMy004_timerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMy004_timerDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy004_timerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_STARTTIME, m_IDC_STATTIME);
	DDX_Control(pDX, IDC_STATICTIME, m_IDC_STATICTIME);
	//  DDX_Control(pDX, IDC_STATICCOUNT, IDC_STATICCOUNT);
	DDX_Control(pDX, IDC_STATICCOUNT, m_IDC_STATICCOUNT);
}

BEGIN_MESSAGE_MAP(CMy004_timerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_STARTTIME, &CMy004_timerDlg::OnBnClickedStarttime)
	ON_BN_CLICKED(IDC_STOPTIMER, &CMy004_timerDlg::OnBnClickedStoptimer)
END_MESSAGE_MAP()


// CMy004_timerDlg message handlers

BOOL CMy004_timerDlg::OnInitDialog()
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
	// Initialize the counter interval
	m_iInterval = 100;

	// Start the clock timer
	SetTimer(ID_CLOCK_TIMER, 1000, NULL);
	GetDlgItem(IDC_STOPTIMER)->EnableWindow(FALSE);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMy004_timerDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy004_timerDlg::OnPaint()
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
HCURSOR CMy004_timerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMy004_timerDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	// Get the current time
	CTime curTime = CTime::GetCurrentTime();

	CString m_sTime;
	// Which timer triggered this event
	switch (nIDEvent)
	{
	case ID_CLOCK_TIMER:
		// Display the current time		
		m_sTime.Format(TEXT("%d:%d:%d"), curTime.GetHour(),
			curTime.GetMinute(),
			curTime.GetSecond());
		m_IDC_STATICTIME.SetWindowText(m_sTime);
		break;
	case ID_COUNT_TIMER:
		// Increment the count
		m_iCount++;
		// Format and display the count
		m_sCount.Format(TEXT("%d"), m_iCount);
		m_IDC_STATICCOUNT.SetWindowText(m_sCount);
		break;
	default:
		break;
	}
	
	CDialogEx::OnTimer(nIDEvent);
}


void CMy004_timerDlg::OnBnClickedStarttime()
{
	// TODO: Add your control notification handler code here
	// Initialize the count
	m_iCount = 0;
	// Format the count for displaying
	m_sCount.Format(TEXT("%d"), m_iCount);

	// Start the timer
	SetTimer(ID_COUNT_TIMER, m_iInterval, NULL);
	GetDlgItem(IDC_STOPTIMER)->EnableWindow(TRUE);
}


void CMy004_timerDlg::OnBnClickedStoptimer()
{
	// TODO: Add your control notification handler code here
	// Stop the timer
	KillTimer(ID_COUNT_TIMER);
	GetDlgItem(IDC_STOPTIMER)->EnableWindow(FALSE);
}
