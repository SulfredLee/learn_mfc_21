
// 009_activexDlg.cpp : implementation file
//

#include "stdafx.h"
#include "009_activex.h"
#include "009_activexDlg.h"
#include "afxdialogex.h"
#include "CMSFlexGrid.h"

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


// CMy009_activexDlg dialog



CMy009_activexDlg::CMy009_activexDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMy009_activexDlg::IDD, pParent)
	, m_iMouseCol(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy009_activexDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MSFGRID, m_ctlFGrid);
}

BEGIN_MESSAGE_MAP(CMy009_activexDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_EXIT, &CMy009_activexDlg::OnBnClickedExit)
END_MESSAGE_MAP()


// CMy009_activexDlg message handlers

BOOL CMy009_activexDlg::OnInitDialog()
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
	//m_ctlFGrid = new CMSFlexGrid;
	LoadData();
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMy009_activexDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy009_activexDlg::OnPaint()
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
HCURSOR CMy009_activexDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMy009_activexDlg::OnBnClickedExit()
{
	// TODO: Add your control notification handler code here
	OnOK();
}


void CMy009_activexDlg::LoadData()
{
	int liCount; // The grid row count
	CString lsAmount; // The sales amount

	// Initialize the random number generator
	srand((unsigned)time(NULL));
	// Create Array in the control
	for (liCount = m_ctlFGrid.get_FixedRows();
		liCount < m_ctlFGrid.get_Rows(); liCount++)
	{
		// Generate the first column (region) values
		m_ctlFGrid.put_TextArray(GenID(liCount, 0), RandomStringValue(0));
		// Generate the second column (product) values
		m_ctlFGrid.put_TextArray(GenID(liCount, 1), RandomStringValue(1));
		// Generate the third column (employee) values
		m_ctlFGrid.put_TextArray(GenID(liCount, 2), RandomStringValue(2));
		// Generate the sales amount values
		lsAmount.Format(TEXT("%5d.00"), rand());
		// Populate the fourth column
		m_ctlFGrid.put_TextArray(GenID(liCount, 3), lsAmount);
	}

	// Merge the common subsequent rows in these columns
	m_ctlFGrid.put_MergeCol(0, TRUE);
	m_ctlFGrid.put_MergeCol(1, TRUE);
	m_ctlFGrid.put_MergeCol(2, TRUE);

	// Sort the grid
	DoSort();
}


int CMy009_activexDlg::GenID(int m_iRow, int m_iCol)
{
	// Get the number of columns
	int liCols = m_ctlFGrid.get_Cols();

	// Generate an ID based on the number of columns,
	// the current column, and the current row
	return (m_iCol + liCols * m_iRow);
}


CString CMy009_activexDlg::RandomStringValue(int m_iColumn)
{
	CString lsStr; // The return string
	int liCase; // A random value ID

	// Which column are we generating for?
	switch (m_iColumn)
	{
	case 0: // The first column (region)
		// Generate a random value between 0 and 4
		liCase = (rand() % 5);
		// What value was generated?
		switch (liCase)
		{
		case 0:
			// 0 - Northwest region
			lsStr = "Northwest";
			break;
		case 1:
			// 1 - Southwest region
			lsStr = "Southwest";
			break;
		case 2:
			// 2 - Midwest region
			lsStr = "Midwest";
			break;
		case 3:
			// 3 - Northeast region
			lsStr = "Northeast";
			break;
		default:
			// 4 - Southeast region
			lsStr = "Southeast";
			break;
		}
		break;
	case 1: // The second column (product)
		// Generate a random value between 0 and 4
		liCase = (rand() % 5);
		// What value was generated?
		switch (liCase)
		{
		case 0:
			// 0 - Dodads
			lsStr = "Dodads";
			break;
		case 1:
			// 1 - Thingamajigs
			lsStr = "Thingamajigs";
			break;
		case 2:
			// 2 - Whatchamacallits
			lsStr = "Whatchamacallits";
			break;
		case 3:
			// 3 - Round Tuits
			lsStr = "Round Tuits";
			break;
		default:
			// 4 - Widgets
			lsStr = "Widgets";
			break;
		}
		break;
	case 2: // The third column (employee)
		// Generate a random value between 0 and 3
		liCase = (rand() % 4);
		// What value was generated?
		switch (liCase)
		{
		case 0:
			// 0 - Dore
			lsStr = "Dore";
			break;
		case 1:
			// 1 - Harvey
			lsStr = "Harvey";
			break;
		case 2:
			// 2 - Pogo
			lsStr = "Pogo";
			break;
		default:
			// 3 - Nyra
			lsStr = "Nyra";
			break;
		}
		break;
	}
	// Return the generated string
	return lsStr;
}


void CMy009_activexDlg::DoSort()
{
	// Set the current column to column 0
	m_ctlFGrid.put_Col(0);
	// Set the column selection to all columns
	m_ctlFGrid.put_ColSel((m_ctlFGrid.get_Cols() - 1));
	// Generic Ascending Sort
	m_ctlFGrid.put_Sort(1);
}
BEGIN_EVENTSINK_MAP(CMy009_activexDlg, CDialogEx)
	ON_EVENT(CMy009_activexDlg, IDC_MSFGRID, DISPID_MOUSEDOWN, CMy009_activexDlg::MouseDownMsfgrid, VTS_I2 VTS_I2 VTS_I4 VTS_I4)
	ON_EVENT(CMy009_activexDlg, IDC_MSFGRID, DISPID_MOUSEUP, CMy009_activexDlg::MouseUpMsfgrid, VTS_I2 VTS_I2 VTS_I4 VTS_I4)
END_EVENTSINK_MAP()


void CMy009_activexDlg::MouseDownMsfgrid(short Button, short Shift, long x, long y)
{
	// TODO: Add your message handler code here
	// Did the user click on a data row and not the
	// header row?
	long temp = m_ctlFGrid.get_MouseRow();
	if (temp != 0)
	{
		// If so, then zero out the column variable
		// and exit
		m_iMouseCol = 0;
		return;
	}
	// Save the column clicked on
	m_iMouseCol = m_ctlFGrid.get_MouseCol();
}


void CMy009_activexDlg::MouseUpMsfgrid(short Button, short Shift, long x, long y)
{
	// TODO: Add your message handler code here
	// If the selected column was the first column,
	// there’s nothing to do
	if (m_iMouseCol == 0)
		return;
	// Turn the control redraw off
	m_ctlFGrid.SetRedraw(FALSE);
	// Change the selected column position
	m_ctlFGrid.put_ColPosition(m_iMouseCol, m_ctlFGrid.get_MouseCol());
	// Resort the grid
	DoSort();
	// Turn redraw back on
	m_ctlFGrid.SetRedraw(TRUE);
}
