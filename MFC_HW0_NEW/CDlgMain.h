#pragma once

// CDlgMain dialog

class CDlgMain : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgMain)

public:
	CDlgMain(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CDlgMain();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = dlgMainFrame };
#endif


	

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedbtndraw();
	afx_msg void OnDraw();

	double a_param, b_param, s_param, w_param, h_param;
	COLORREF c1_param, c2_param;
	bool isValues;
	CString a_str, b_str, s_str;

	void ChangeParameters( int a, int b, int s) {
		a_param = a;
		b_param = b;
		s_param = s;
	}

	void drawFunction(CClientDC* pDC) {
		
		//Set origin:
		//pDC->SetViewportOrg(w_param / 2, h_param / 2);
		//pDC->SetMapMode(MM_ANISOTROPIC);//Normal oriantation.
		//pDC->SetWindowExt(w_param*2, h_param*2);
		//pDC->SetViewportExt(w_param*2.2, -h_param*2);
		//Set Pen:
		//CPen pen(PS_SOLID, 1, RGB(0, 0, 0));
		//CPen* pOldPen = pDC->SelectObject(&pen);
		
		//POINT points[2500];
		//int i = 0;

		//----------------------------------------------------------------//
		//----------------------------------------------------------------//
		//Function:
		
		
		for (int x_cord = 0; x_cord < w_param; x_cord++) {
			for (int y_cord = 0; y_cord < h_param; y_cord++) {
				double outp = Funcy(x_cord, y_cord, w_param, h_param, a_param, b_param, s_param);
				if(isValues)
					pDC->SetPixelV(x_cord, y_cord, funcyColorValues(c1_param, c2_param, outp));
				else
					pDC->SetPixelV(x_cord, y_cord, funcyColorZeros(c1_param, c2_param, outp));
				
			}
			
		}

		/*
		//SIN
		double PI = 3.14;
		for (double ii = -280; ii < 280; ii += 0.01)
		{
			double j = sin(PI / 50* ii) * 25;
			pDC->SetPixel(ii, j, RGB(255, 0, 0));
		}
		*/
		


		//----------------------------------------------------------------//
		//----------------------------------------------------------------//
		//Axis:
		//POINT x_up, x_down, y_up, y_down;
		//x_up = { (int)w_param / 2 , 0 };
		//x_down = { -(int)w_param / 2 , 0 };
		//y_up = { 0, (int)(h_param / 2) };
		//y_down = { 0 , -(int)(h_param / 2) };
		//POINT pnts[5] = {0,0 , 1,1 , 2,2 , 3,3 , 4,4} :O
		//CPoint p[5] = { CPoint(0,0) , CPoint(1,1) , ...}
		//pDC->MoveTo(x_down);
		//pDC->LineTo(x_up);
		//pDC->MoveTo(y_down);
		//pDC->LineTo(y_up);
		//----------------------------------------------------------------//
		//----------------------------------------------------------------//
		
		/*
		//COS:
		CPen pen2(PS_SOLID, 1, RGB(250, 0, 0));
		pDC->SelectObject(&pen2);
		for (int x = 0; x < 200; x++) {
			
			double y = -cos(x+b_param)*a_param;
			points[i++] = { x , y };
		}
		pDC->Polyline(points, 200);
		*/


		
		pDC->UpdateColors();


		//pDC->SelectObject(pOldPen);  


	}

	double Funcy(int x, int y, int w, int h, int a, int b, int scale) {
		//double PI = 3.14159265359;
		double a_phrase = (x - w / 2);
		double b_phrase = (y - h / 2);
		double mid_a = (a*a_phrase) * (a*a_phrase) * (a*a_phrase) * (a*a_phrase);
		double mid_b = (b*b_phrase) * (b*b_phrase) * (b*b_phrase) * (b*b_phrase);
		//return cos(PI/((mid_a + mid_b) / (scale * scale * scale)));
		return cos((mid_a + mid_b) / (scale * scale * scale));
	}
	
	COLORREF funcyColorValues(COLORREF c1, COLORREF c2,double f) {
		COLORREF res = c1 * (1 - FuncyT(f)) + c2 * FuncyT(f);
		return res;
	}

	COLORREF funcyColorZeros(COLORREF c1, COLORREF c2, double f) {
		return (f > 0) ? c1 : c2;
	}

	double FuncyT(double f) { return (f + 1) / 2; }

	afx_msg void OnBnClickedbtnclear();
	afx_msg void OnModeValue();
	afx_msg void OnModeZeros();
	afx_msg void OnUpdateModeZeros(CCmdUI *pCmdUI);
	afx_msg void OnUpdateModeValue(CCmdUI *pCmdUI);
	afx_msg void OnScreenDraw();
	afx_msg void OnScreenClear();
};
