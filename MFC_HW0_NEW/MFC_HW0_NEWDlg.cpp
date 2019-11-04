
// MFC_HW0_NEWDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFC_HW0_NEW.h"
#include "MFC_HW0_NEWDlg.h"
#include "CDlgColors.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCHW0NEWDlg dialog



CMFCHW0NEWDlg::CMFCHW0NEWDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFC_HW0_NEW_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	_drawLine = false;
	}

void CMFCHW0NEWDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCHW0NEWDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(btnDraw, &CMFCHW0NEWDlg::OnBnClickedbtndraw)
	ON_COMMAND(ID_CHANGESETTINGS, &CMFCHW0NEWDlg::OnChangesettings)
END_MESSAGE_MAP()


// CMFCHW0NEWDlg message handlers

BOOL CMFCHW0NEWDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCHW0NEWDlg::OnPaint()
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
HCURSOR CMFCHW0NEWDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}





void CMFCHW0NEWDlg::OnBnClickedbtndraw()
{
	//GetClientRect();
	_drawLine = true;
	//CMFCHW0NEWDlg::OnPaint();
}


void CMFCHW0NEWDlg::OnChangesettings()
{
	// TODO: Add your command handler code here
	CDlgColors dlgColors;
	dlgColors.DoModal();
}
