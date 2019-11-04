
// MFC_HW0_NEW.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "CMainApp.h"
#include "CDlgMain.h"
#include "CDlgColors.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCHW0NEWApp

BEGIN_MESSAGE_MAP(CMainAppClass, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
	ON_COMMAND(ID_CHANGESETTINGS, &CMainAppClass::OnChangesettings)
END_MESSAGE_MAP()


// CMFCHW0NEWApp construction

CMainAppClass::CMainAppClass()
{
	// support Restart Manager
	//m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;
	//CreateDialog(NULL, _T(""));
	
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
	

}


// The one and only CMFCHW0NEWApp object

CMainAppClass theApp;


// CMFCHW0NEWApp initialization

BOOL CMainAppClass::InitInstance()
{
	// InitCommonControlsEx() is required on Windows XP if an application
	// manifest specifies use of ComCtl32.dll version 6 or later to enable
	// visual styles.  Otherwise, any window creation will fail.
	//INITCOMMONCONTROLSEX InitCtrls;
	//InitCtrls.dwSize = sizeof(InitCtrls);
	// Set this to include all the common control classes you want to use
	// in your application.
	//InitCtrls.dwICC = ICC_WIN95_CLASSES;
	//InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	AfxEnableControlContainer();
	// Activate "Windows Native" visual manager for enabling themes in MFC controls
	//CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));

	dlg = new CDlgMain(m_pMainWnd);
	m_pMainWnd = dlg;

	



	//Handle the "Results" from the main frame dialog here...
	INT_PTR nResponse = dlg->DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}
	else if (nResponse == -1)
	{
		TRACE(traceAppMsg, 0, "Warning: dialog creation failed, so application is terminating unexpectedly.\n");
		TRACE(traceAppMsg, 0, "Warning: if you are using MFC controls on the dialog, you cannot #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS.\n");
	}
	delete dlg;


#if !defined(_AFXDLL) && !defined(_AFX_NO_MFC_CONTROLS_IN_DIALOGS)
	ControlBarCleanUp();
#endif

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}



void CMainAppClass::OnChangesettings()
{
	// TODO: Add your command handler code here
	// Pop the dlgColorsPicking up
	CDlgColors dl(dlg);

	if (dl.DoModal() == IDOK) {
		//AfxMessageBox(_T("" + dl.m_strTxtA));
		
		int a = _ttoi(dl.m_strTxtA);
		int b = _ttoi(dl.m_strTxtB);
		int s = _ttoi(dl.m_strTxtS);
		//RECT rect;
		//GetClientRect(*m_pMainWnd, &rect);
		//int w = rect.right;
		//int h = rect.left;
		dlg->ChangeParameters( a, b, s);

	}
	else {

	}
}



void CMainAppClass::OnPaint()
{
	//CPaintDC dc(m_pMainWnd);
	//CRect rect;
	//GetClientRect(*m_pMainWnd,&rect);
	
	//dc.DrawText(_T("AAAAAAAAAAAAAHHHHHHHHHHH"), -1, &rect,
	//	DT_SINGLELINE | DT_CENTER | DT_VCENTER);

}
