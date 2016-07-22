
// 003_mouse_keyboardDlg.cpp : implementation file
//

#include "stdafx.h"
#include "003_mouse_keyboard.h"
#include "003_mouse_keyboardDlg.h"
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
private:
	int m_iPrevY;
	int m_iPrevX;
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
, m_iPrevY(0)
, m_iPrevX(0)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMy003_mouse_keyboardDlg dialog



CMy003_mouse_keyboardDlg::CMy003_mouse_keyboardDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMy003_mouse_keyboardDlg::IDD, pParent)
	, m_iPrevX(0)
	, m_iPrevY(0)
	, m_bCursor(false)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy003_mouse_keyboardDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMy003_mouse_keyboardDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_KEYDOWN()
	ON_WM_SETCURSOR()
END_MESSAGE_MAP()


// CMy003_mouse_keyboardDlg message handlers

BOOL CMy003_mouse_keyboardDlg::OnInitDialog()
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

	// Initialize the cursor to the arrow
	m_bCursor = FALSE;

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMy003_mouse_keyboardDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy003_mouse_keyboardDlg::OnPaint()
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
HCURSOR CMy003_mouse_keyboardDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMy003_mouse_keyboardDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	// Check to see if the left mouse button is down
	if ((nFlags & MK_LBUTTON) == MK_LBUTTON)
	{
		// Get the Device Context
		CClientDC dc(this);

		// Draw the pixel
		//dc.SetPixel(point.x, point.y, RGB(0, 0, 0));
		dc.MoveTo(m_iPrevX, m_iPrevY);
		dc.LineTo(point.x, point.y);

		// Save the current point as the previous point
		m_iPrevX = point.x;
		m_iPrevY = point.y;
	}
	CDialogEx::OnMouseMove(nFlags, point);
}


void CMy003_mouse_keyboardDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	// Set the current point as the starting point
	m_iPrevX = point.x;
	m_iPrevY = point.y;
	CDialogEx::OnLButtonDown(nFlags, point);
}


void CMy003_mouse_keyboardDlg::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
	char lsChar; // The current character being pressed
	HCURSOR lhCursor; // The handle to the cursor to be displayed

	// Convert the key pressed to a character
	lsChar = char(nChar);

	// Is the character ¡§A¡¨
	if (lsChar == 'A')
	{
		// Load the arrow cursor
		lhCursor = AfxGetApp()->LoadStandardCursor(IDC_ARROW);
		// Set the cursor flag
		m_bCursor = TRUE;
		// Set the screen cursor
		SetCursor(lhCursor);
	}
	// Is the character ¡§B¡¨
	if (lsChar == 'B')
	{
	// Load the I beam cursor
		lhCursor = AfxGetApp()->LoadStandardCursor(IDC_IBEAM);
		// Set the cursor flag
		m_bCursor = TRUE;
		// Set the screen cursor
		SetCursor(lhCursor);
	}

	// Is the character ¡§C¡¨
	if (lsChar == 'C')
	{
		// Load the I beam cursor
		lhCursor = AfxGetApp()->LoadStandardCursor(IDC_WAIT);
		// Set the cursor flag
		m_bCursor = TRUE;
		// Set the screen cursor
		SetCursor(lhCursor);
	}

	// Is the character ¡§X¡¨
	if (lsChar == 'X')
	{
		// Load the I beam cursor
		lhCursor = AfxGetApp()->LoadStandardCursor(IDC_ARROW);
		// Set the cursor flag
		m_bCursor = TRUE;
		// Set the screen cursor
		SetCursor(lhCursor);
		OnOK();
	}
	CDialogEx::OnKeyDown(nChar, nRepCnt, nFlags);
}


BOOL CMy003_mouse_keyboardDlg::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: Add your message handler code here and/or call default
	if (m_bCursor)
		return TRUE;
	else
		return CDialogEx::OnSetCursor(pWnd, nHitTest, message);
}
