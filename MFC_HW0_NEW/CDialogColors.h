
// MFC_HW0_NEWDlg.h : header file
//

#pragma once


// CMFCHW0NEWDlg dialog
class CDialogColors : public CDialogEx
{
	// Construction
public:
	CDialogColors(CWnd* pParent = nullptr);	// standard constructor

	BOOL OnInitDialog();

	void OnPaint();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_HW0_NEW_DIALOG };
#endif

protected:
	//virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//virtual BOOL OnInitDialog();
	//afx_msg void OnPaint();
	//afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:

	
};
