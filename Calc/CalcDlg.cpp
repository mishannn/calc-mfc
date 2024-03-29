#include "stdafx.h"
#include "Calc.h"
#include "CalcDlg.h"
#include "CalcEngine.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CCalcEngine *g_calcEngine = NULL;

CCalcDlg::CCalcDlg(CWnd* pParent)
	: CDialog(IDD_CALC_DIALOG, pParent) {
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalcDlg::DoDataExchange(CDataExchange* pDX) {
	DDX_Control(pDX, IDC_EDIT1, m_textOut);
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCalcDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CCalcDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CCalcDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CCalcDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CCalcDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CCalcDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CCalcDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CCalcDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CCalcDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CCalcDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON11, &CCalcDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON12, &CCalcDlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON13, &CCalcDlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON10, &CCalcDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON16, &CCalcDlg::OnBnClickedButton16)
	ON_BN_CLICKED(IDC_BUTTON15, &CCalcDlg::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON14, &CCalcDlg::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON17, &CCalcDlg::OnBnClickedButton17)
END_MESSAGE_MAP()

BOOL CCalcDlg::OnInitDialog() {
	CDialog::OnInitDialog();

	g_calcEngine = new CCalcEngine(GetSafeHwnd());
	m_textOut.SetWindowTextW(g_calcEngine->TextOutW());

	SetIcon(m_hIcon, TRUE);
	SetIcon(m_hIcon, FALSE);

	return TRUE;
}

void CCalcDlg::OnSysCommand(UINT nID, LPARAM lParam) {
	CDialog::OnSysCommand(nID, lParam);
}

void CCalcDlg::OnPaint() {
	if (IsIconic()) {
		CPaintDC dc(this);

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		dc.DrawIcon(x, y, m_hIcon);
	} else {
		CDialog::OnPaint();
	}
}

HCURSOR CCalcDlg::OnQueryDragIcon() {
	return static_cast<HCURSOR>(m_hIcon);
}

void CCalcDlg::OnBnClickedButton1() {
	g_calcEngine->InsertDigit(1);
	m_textOut.SetWindowTextW(g_calcEngine->TextOutW());
}

void CCalcDlg::OnBnClickedButton2() {
	g_calcEngine->InsertDigit(2);
	m_textOut.SetWindowTextW(g_calcEngine->TextOutW());
}

void CCalcDlg::OnBnClickedButton3() {
	g_calcEngine->InsertDigit(3);
	m_textOut.SetWindowTextW(g_calcEngine->TextOutW());
}

void CCalcDlg::OnBnClickedButton4() {
	g_calcEngine->InsertDigit(4);
	m_textOut.SetWindowTextW(g_calcEngine->TextOutW());
}

void CCalcDlg::OnBnClickedButton5() {
	g_calcEngine->InsertDigit(5);
	m_textOut.SetWindowTextW(g_calcEngine->TextOutW());
}

void CCalcDlg::OnBnClickedButton6() {
	g_calcEngine->InsertDigit(6);
	m_textOut.SetWindowTextW(g_calcEngine->TextOutW());
}

void CCalcDlg::OnBnClickedButton7() {
	g_calcEngine->InsertDigit(7);
	m_textOut.SetWindowTextW(g_calcEngine->TextOutW());
}

void CCalcDlg::OnBnClickedButton8() {
	g_calcEngine->InsertDigit(8);
	m_textOut.SetWindowTextW(g_calcEngine->TextOutW());
}

void CCalcDlg::OnBnClickedButton9() {
	g_calcEngine->InsertDigit(9);
	m_textOut.SetWindowTextW(g_calcEngine->TextOutW());
}

void CCalcDlg::OnBnClickedButton10() {
	g_calcEngine->InsertDigit(0);
	m_textOut.SetWindowTextW(g_calcEngine->TextOutW());
}

void CCalcDlg::OnBnClickedButton11() {
	g_calcEngine->InsertOperation('C');
	m_textOut.SetWindowTextW(g_calcEngine->TextOutW());
}

void CCalcDlg::OnBnClickedButton12() {
	g_calcEngine->InsertOperation(',');
	m_textOut.SetWindowTextW(g_calcEngine->TextOutW());
}

void CCalcDlg::OnBnClickedButton13() {
	g_calcEngine->InsertOperation('+');
	m_textOut.SetWindowTextW(g_calcEngine->TextOutW());
}

void CCalcDlg::OnBnClickedButton16() {
	g_calcEngine->InsertOperation('/');
	m_textOut.SetWindowTextW(g_calcEngine->TextOutW());
}

void CCalcDlg::OnBnClickedButton15() {
	g_calcEngine->InsertOperation('*');
	m_textOut.SetWindowTextW(g_calcEngine->TextOutW());
}

void CCalcDlg::OnBnClickedButton14() {
	g_calcEngine->InsertOperation('-');
	m_textOut.SetWindowTextW(g_calcEngine->TextOutW());
}

void CCalcDlg::OnBnClickedButton17() {
	g_calcEngine->InsertOperation('=');
	m_textOut.SetWindowTextW(g_calcEngine->TextOutW());

	// g_calcEngine->Test();
}