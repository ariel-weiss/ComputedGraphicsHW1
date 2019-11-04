// CDlgMain.cpp : implementation file
//

#include "stdafx.h"
#include "CMainApp.h"
#include "CDlgMain.h"
#include "afxdialogex.h"


// CDlgMain dialog

IMPLEMENT_DYNAMIC(CDlgMain, CDialogEx)

CDlgMain::CDlgMain(CWnd* pParent /*=nullptr*/)
	: CDialogEx(dlgMainFrame, pParent)
{
	a_param = 1;
	b_param = 1;
	w_param = 1; 
	h_param = 1; 
	s_param = -1;
	isValues = false;
	c1_param = RGB(0, 0, 0);
	c2_param = RGB(255, 255, 255);

}

CDlgMain::~CDlgMain()
{
}

void CDlgMain::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);


}


BEGIN_MESSAGE_MAP(CDlgMain, CDialogEx)
	ON_BN_CLICKED(btnDraw, &CDlgMain::OnBnClickedbtndraw)
	ON_BN_CLICKED(btnClear, &CDlgMain::OnBnClickedbtnclear)
	ON_COMMAND(ID_MODE_VALUE, &CDlgMain::OnModeValue)
	ON_COMMAND(ID_MODE_ZEROS, &CDlgMain::OnModeZeros)
	ON_UPDATE_COMMAND_UI(ID_MODE_ZEROS, &CDlgMain::OnUpdateModeZeros)
	ON_UPDATE_COMMAND_UI(ID_MODE_VALUE, &CDlgMain::OnUpdateModeValue)
END_MESSAGE_MAP()


// CDlgMain message handlers


void CDlgMain::OnBnClickedbtndraw()
{
	// TODO: Add your control notification handler code here
	CClientDC* pDC = new CClientDC(this);	
	//RECT rect;
	CRect rect;
	GetClientRect(&rect);
	w_param = rect.right;
	h_param = rect.bottom;
	if (s_param < 0)
		s_param = w_param / 10;


	drawFunction(pDC);
	delete pDC;
	//UpdateWindow();
	
}


void CDlgMain::OnDraw() {


}


void CDlgMain::OnBnClickedbtnclear()
{
	// TODO: Add your control notification handler code here
	CRect r;
	GetClientRect(r);
	InvalidateRect(r);
	PostMessageW(WM_PAINT);
}


void CDlgMain::OnModeValue()
{
	// TODO: Add your command handler code here
	isValues = true;
}


void CDlgMain::OnModeZeros()
{
	// TODO: Add your command handler code here
	isValues = false;
}


void CDlgMain::OnUpdateModeZeros(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	CMenu *men = GetMenu();
	if (men != NULL) {
		men->CheckMenuItem(ID_MODE_VALUE, MF_UNCHECKED | MF_BYCOMMAND);
		men->CheckMenuItem(ID_MODE_ZEROS, MF_CHECKED | MF_BYCOMMAND);
	}
}


void CDlgMain::OnUpdateModeValue(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	CMenu *men = GetMenu();
	if (men != NULL) {
		men->CheckMenuItem(ID_MODE_VALUE, MF_CHECKED | MF_BYCOMMAND);
		men->CheckMenuItem(ID_MODE_ZEROS, MF_UNCHECKED | MF_BYCOMMAND);
	}
}
