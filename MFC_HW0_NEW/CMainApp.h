
// MFC_HW0_NEW.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols
#include "CDlgMain.h"


class CMainAppClass : public CWinApp
{
public:
	CMainAppClass();
	CDlgMain *dlg;
// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	protected:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnChangesettings();
	afx_msg void OnPaint();
};

extern CMainAppClass theApp;
