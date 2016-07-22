
// 006_menusDlg.cpp : implementation file
//

#include "stdafx.h"
#include "006_menus.h"
#include "006_menusDlg.h"
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


// CMy006_menusDlg dialog



CMy006_menusDlg::CMy006_menusDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMy006_menusDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy006_menusDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMy006_menusDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_EXIT, &CMy006_menusDlg::OnBnClickedExit)
	ON_COMMAND(ID_FILE_HELLO, &CMy006_menusDlg::OnFileHello)
	ON_COMMAND(ID_HELP_ABOUT, &CMy006_menusDlg::OnHelpAbout)
	ON_WM_CONTEXTMENU()
END_MESSAGE_MAP()


// CMy006_menusDlg message handlers

BOOL CMy006_menusDlg::OnInitDialog()
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

void CMy006_menusDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy006_menusDlg::OnPaint()
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
HCURSOR CMy006_menusDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMy006_menusDlg::OnBnClickedExit()
{
	// TODO: Add your control notification handler code here
	OnOK();
}


void CMy006_menusDlg::OnFileHello()
{
	// TODO: Add your command handler code here
	// Display a message for the user
	MessageBox(TEXT("Hello there"), TEXT("Hello"));
}


void CMy006_menusDlg::OnHelpAbout()
{
	// TODO: Add your command handler code here
	// Declare an instance of the About window
	CAboutDlg dlgAbout;

	// Show the About window
	dlgAbout.DoModal();
}


void CMy006_menusDlg::OnContextMenu(CWnd* pWnd, CPoint point)
{
	// TODO: Add your message handler code here
	// Declare local variables
	CMenu *m_lMenu; // A pointer to the menu
	CPoint m_pPoint; // A copy of the mouse position

	// Copy the mouse position to a local variable
	m_pPoint = point;
	// Convert the position to a screen position
	//ClientToScreen(&m_pPoint);
	// Get a pointer to the window menu
	m_lMenu = GetMenu();
	// Get a pointer to the first submenu
	m_lMenu = m_lMenu->GetSubMenu(0);
	// Show the Popup Menu
	m_lMenu->TrackPopupMenu(TPM_CENTERALIGN + TPM_LEFTBUTTON, m_pPoint.x, m_pPoint.y, this, NULL);
}
