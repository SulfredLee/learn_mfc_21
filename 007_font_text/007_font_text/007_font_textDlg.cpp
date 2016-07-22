
// 007_font_textDlg.cpp : implementation file
//

#include "stdafx.h"
#include "007_font_text.h"
#include "007_font_textDlg.h"
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
//	void FillFontList();
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


// CMy007_font_textDlg dialog



CMy007_font_textDlg::CMy007_font_textDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMy007_font_textDlg::IDD, pParent)
	, m_strDisplayText(_T(""))
	, m_strFontName(_T(""))
	, m_strSampText(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy007_font_textDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_DISPLAYTEXT, m_ctlDisplayText);
	DDX_Text(pDX, IDC_DISPLAYTEXT, m_strDisplayText);
	DDX_Control(pDX, IDC_LFONTS, m_ctlFontList);
	DDX_LBString(pDX, IDC_LFONTS, m_strFontName);
	DDX_Text(pDX, IDC_ESAMPTEXT, m_strSampText);
}

BEGIN_MESSAGE_MAP(CMy007_font_textDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_EXIT, &CMy007_font_textDlg::OnBnClickedExit)
	ON_EN_CHANGE(IDC_ESAMPTEXT, &CMy007_font_textDlg::OnChangeEsamptext)
	ON_LBN_SELCHANGE(IDC_LFONTS, &CMy007_font_textDlg::OnSelchangeLfonts)
END_MESSAGE_MAP()


// CMy007_font_textDlg message handlers

BOOL CMy007_font_textDlg::OnInitDialog()
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
	// Fill the font list box
	FillFontList();

	// Initialize the text to be entered
	m_strSampText = "Testing";
	// Copy the text to the font sample area
	m_strDisplayText = m_strSampText;
	// Update the dialog
	UpdateData(FALSE);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMy007_font_textDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy007_font_textDlg::OnPaint()
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
HCURSOR CMy007_font_textDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

int CALLBACK EnumFontFamProc(LPENUMLOGFONT lpelf,
	LPNEWTEXTMETRIC lpntm, DWORD nFontType, long lParam)
{
	// Create a pointer to the dialog window
	CMy007_font_textDlg* pWnd = (CMy007_font_textDlg*)lParam;

	// Add the font name to the list box
	pWnd->m_ctlFontList.AddString(lpelf->elfLogFont.lfFaceName);
	// Return 1 to continue font enumeration
	return 1;
}

void CMy007_font_textDlg::FillFontList()
{
	int iCount; // The number of fonts
	int iCurCount; // The current font
	CString strCurFont; // The current font name
	CString strPrevFont;
	strPrevFont = ""; // The previous font name
	LOGFONT lf;

	// Initialize the LOGFONT structure
	lf.lfCharSet = DEFAULT_CHARSET;
	wcscpy_s(lf.lfFaceName, TEXT(""));
	// Clear the list box
	m_ctlFontList.ResetContent();
	// Create a device context variable
	CClientDC dc(this);
	// Enumerate the font families
	::EnumFontFamiliesEx((HDC)dc, &lf, (FONTENUMPROC)EnumFontFamProc, (LPARAM)this, 0);
	// Get the number of fonts in the list box
	iCount = m_ctlFontList.GetCount();
	// Loop from the last entry in the list box to the first,
	// searching for and deleting the duplicate entries
	for (iCurCount = iCount; iCurCount > 0; iCurCount--)
	{
		// Get the current font name
		m_ctlFontList.GetText((iCurCount - 1), strCurFont);
		// Is it the same as the previous font name?
		if (strCurFont == strPrevFont)
		{
			// If yes, then delete it
			m_ctlFontList.DeleteString((iCurCount - 1));
		}
		// Set the previous font name to the current font name
		strPrevFont = strCurFont;
	}
}


void CMy007_font_textDlg::OnBnClickedExit()
{
	// TODO: Add your control notification handler code here
	OnOK();
}


void CMy007_font_textDlg::OnChangeEsamptext()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	// Update the variables with the dialog controls
	UpdateData(TRUE);

	// Copy the current text to the font sample
	m_strDisplayText = m_strSampText;

	// Update the dialog with the variables
	UpdateData(FALSE);
}


void CMy007_font_textDlg::SetMyFont()
{
	CRect rRect; // The rectangle of the display area
	int iHeight; // The height of the display area

	// Has a font been selected?
	if (m_strFontName != "")
	{
		// Get the dimensions of the font sample display area
		m_ctlDisplayText.GetWindowRect(&rRect);
		// Calculate the area height
		iHeight = rRect.top - rRect.bottom;
		// Make sure the height is positive
		if (iHeight < 0)
			iHeight = 0 - iHeight;
		// Release the current font
		m_fSampFont.Detach();
		// Create the font to be used
		m_fSampFont.CreateFont((iHeight - 5), 0, 0, 0, FW_NORMAL,
			0, 0, 0, DEFAULT_CHARSET, OUT_CHARACTER_PRECIS,
			CLIP_CHARACTER_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH |
			FF_DONTCARE, m_strFontName);

		// Set the font for the sample display area
		m_ctlDisplayText.SetFont(&m_fSampFont);
	}
}


void CMy007_font_textDlg::OnSelchangeLfonts()
{
	// TODO: Add your control notification handler code here
	// Update the variables with the dialog controls
	UpdateData(TRUE);

	// Set the font for the sample
	SetMyFont();
}
