
// 008_graphic_drawing_bitmapDlg.cpp : implementation file
//

#include "stdafx.h"
#include "008_graphic_drawing_bitmap.h"
#include "008_graphic_drawing_bitmapDlg.h"
#include "afxdialogex.h"
#include "PaintDlg.h"

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


// CMy008_graphic_drawing_bitmapDlg dialog



CMy008_graphic_drawing_bitmapDlg::CMy008_graphic_drawing_bitmapDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMy008_graphic_drawing_bitmapDlg::IDD, pParent)
	, m_iTool(0)
	, m_iShape(0)
	, m_iColor(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy008_graphic_drawing_bitmapDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_RTPEN, m_iTool);
	DDX_Radio(pDX, IDC_RSLINE, m_iShape);
	DDX_Radio(pDX, IDC_RCBLACK, m_iColor);
}

BEGIN_MESSAGE_MAP(CMy008_graphic_drawing_bitmapDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_RTPEN, &CMy008_graphic_drawing_bitmapDlg::OnRSelection)
	ON_BN_CLICKED(IDC_RTBRUSH, &CMy008_graphic_drawing_bitmapDlg::OnRSelection)
	ON_BN_CLICKED(IDC_RTBITMAP, &CMy008_graphic_drawing_bitmapDlg::OnRSelection)
	ON_BN_CLICKED(IDC_RSLINE, &CMy008_graphic_drawing_bitmapDlg::OnRSelection)
	ON_BN_CLICKED(IDC_RSCIRCLE, &CMy008_graphic_drawing_bitmapDlg::OnRSelection)
	ON_BN_CLICKED(IDC_RSSQUARE, &CMy008_graphic_drawing_bitmapDlg::OnRSelection)
	ON_BN_CLICKED(IDC_RCBLACK, &CMy008_graphic_drawing_bitmapDlg::OnRSelection)
	ON_BN_CLICKED(IDC_RCBLUE, &CMy008_graphic_drawing_bitmapDlg::OnRSelection)
	ON_BN_CLICKED(IDC_RCGREEN, &CMy008_graphic_drawing_bitmapDlg::OnRSelection)
	ON_BN_CLICKED(IDC_RCCYAN, &CMy008_graphic_drawing_bitmapDlg::OnRSelection)
	ON_BN_CLICKED(IDC_RCRED, &CMy008_graphic_drawing_bitmapDlg::OnRSelection)
	ON_BN_CLICKED(IDC_RCMAGENTA, &CMy008_graphic_drawing_bitmapDlg::OnRSelection)
	ON_BN_CLICKED(IDC_RCYELLOW, &CMy008_graphic_drawing_bitmapDlg::OnRSelection)
	ON_BN_CLICKED(IDC_RCWHITE, &CMy008_graphic_drawing_bitmapDlg::OnRSelection)
	ON_BN_CLICKED(IDC_BEXIT, &CMy008_graphic_drawing_bitmapDlg::OnBnClickedBexit)
	ON_BN_CLICKED(IDC_BBITMAP, &CMy008_graphic_drawing_bitmapDlg::OnBnClickedBbitmap)
END_MESSAGE_MAP()


// CMy008_graphic_drawing_bitmapDlg message handlers

BOOL CMy008_graphic_drawing_bitmapDlg::OnInitDialog()
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
	m_iColor = 0;
	m_iShape = 0;
	m_iTool = 0;
	UpdateData(FALSE);

	m_dlgPaint = new CPaintDlg;
	// Create the second dialog window
	m_dlgPaint->Create(IDD_PAINT_DLG, this);
	// Show the second dialog window
	m_dlgPaint->ShowWindow(SW_SHOW);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMy008_graphic_drawing_bitmapDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy008_graphic_drawing_bitmapDlg::OnPaint()
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
HCURSOR CMy008_graphic_drawing_bitmapDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMy008_graphic_drawing_bitmapDlg::OnRSelection()
{
	// Synchronize the data
	UpdateData(TRUE);
	// Repaint the second dialog
	m_dlgPaint->Invalidate();
}



void CMy008_graphic_drawing_bitmapDlg::OnBnClickedBexit()
{
	// TODO: Add your control notification handler code here
	OnOK();
}


void CMy008_graphic_drawing_bitmapDlg::OnBnClickedBbitmap()
{
	// TODO: Add your control notification handler code here
	// TODO: Add your control notification handler code here

	// Build a filter for use in the File Open dialog
	// Create the File Open dialog
	CFileDialog m_ldFile(TRUE, TEXT("bmp"), TEXT("default_file"),
		OFN_HIDEREADONLY | OFN_FILEMUSTEXIST, TEXT("Bitmap Files(*.bmp)|*.bmp||"), this);

	// Show the File Open dialog and capture the result
	if (m_ldFile.DoModal() == IDOK)
	{
		// Get the filename selected
		m_sBitmap = m_ldFile.GetPathName();
		// Load the selected bitmap file
		HBITMAP hBitmap = (HBITMAP) ::LoadImage(AfxGetInstanceHandle(),
			m_sBitmap, IMAGE_BITMAP, 0, 0,
			LR_LOADFROMFILE | LR_CREATEDIBSECTION);

		// Do we have a valid handle for the loaded image?
		if (hBitmap)
		{
			// Delete the current bitmap
			if (m_bmpBitmap.DeleteObject())
				// If there was a bitmap, detach it
				m_bmpBitmap.Detach();
			// Attach the currently loaded bitmap to the bitmap object
			m_bmpBitmap.Attach(hBitmap);
		}
		// Invalidate the second dialog window
		m_dlgPaint->Invalidate();
	}
}
