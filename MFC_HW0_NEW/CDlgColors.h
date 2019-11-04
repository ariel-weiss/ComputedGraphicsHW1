#pragma once


// CDlgColors dialog

class CDlgColors : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgColors)

public:
	CDlgColors(CDlgMain* pParent);   // standard constructor
	virtual ~CDlgColors();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = dlgColorsPicking };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	CButton btn_c1;
	CEdit txt_a,txt_b,txt_s;
	CString m_strTxtA;
	CString m_strTxtB;
	CString m_strTxtS;
	COLORREF c1_prev, c2_prev;
};
