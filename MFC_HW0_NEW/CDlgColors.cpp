// CDlgColors.cpp : implementation file
//

#include "stdafx.h"
#include "CMainApp.h"
#include "CDlgColors.h"
#include "afxdialogex.h"
#include "CDlgMain.h"


// CDlgColors dialog

IMPLEMENT_DYNAMIC(CDlgColors, CDialogEx)

CDlgColors::CDlgColors(CDlgMain* pParent /*=nullptr*/)
	: CDialogEx(dlgColorsPicking, pParent)
	, m_strTxtA(_T(""))
	, m_strTxtB(_T(""))
	, m_strTxtS(_T(""))
{	
	double a = pParent->a_param;
	double b = pParent->b_param;
	double s = pParent->s_param;
	m_strTxtA.Format(L"%g", a);
	m_strTxtB.Format(L"%g", b);
	m_strTxtS.Format(L"%g", s);
	c1_prev = pParent->c1_param;
	c2_prev = pParent->c2_param;
}

CDlgColors::~CDlgColors()
{
	
}

void CDlgColors::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, btn_c1);
	DDX_Control(pDX, txtBoxA, txt_a);
	DDX_Control(pDX, txtBoxB, txt_b);
	DDX_Control(pDX, txtBoxS, txt_s);


	DDX_Text(pDX, txtBoxA, m_strTxtA);
	DDX_Text(pDX, txtBoxB, m_strTxtB);
	DDX_Text(pDX, txtBoxS, m_strTxtS);
}


BEGIN_MESSAGE_MAP(CDlgColors, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON3, &CDlgColors::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlgColors::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDlgColors::OnBnClickedButton2)
END_MESSAGE_MAP()


// CDlgColors message handlers


void CDlgColors::OnBnClickedButton3()
{

	CDialog::OnOK();
}


void CDlgColors::OnBnClickedButton1()//C1
{
	// TODO: Add your control notification handler code here
	CColorDialog ccd(c1_prev);
	if (ccd.DoModal() == IDOK) {
		COLORREF selected_c1 = ccd.GetColor();
		((CDlgMain*)this->GetParent())->c1_param = selected_c1;
	}
}


void CDlgColors::OnBnClickedButton2()//C2
{
	// TODO: Add your control notification handler code here
	CColorDialog ccd(c2_prev);
	if (ccd.DoModal() == IDOK) {
		COLORREF selected_c2 = ccd.GetColor();
		((CDlgMain*)this->GetParent())->c2_param = selected_c2;
	}
}


