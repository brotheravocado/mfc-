﻿
// network2Dlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "network2.h"
#include "network2Dlg.h"
#include "afxdialogex.h"
#include "CMySocket.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Cnetwork2Dlg 대화 상자



Cnetwork2Dlg::Cnetwork2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_NETWORK2_DIALOG, pParent)
	, m_iType(0)
	, m_strName(_T(""))
	, m_strMessage(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cnetwork2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_RSERVER, m_iType);
	DDX_Text(pDX, IDC_ESERVNAME, m_strName);
	DDX_Text(pDX, IDC_EMSG, m_strMessage);
	//  DDX_Control(pDX, IDC_LSENT, m_ctlSent);
	//  DDX_Control(pDX, IDC_LRECVD, m_ctlRecvd);
}

BEGIN_MESSAGE_MAP(Cnetwork2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BLINE, &Cnetwork2Dlg::OnBnClickedBline)
	ON_BN_CLICKED(IDC_BLISTEN, &Cnetwork2Dlg::OnBnClickedBlisten)
	ON_BN_CLICKED(IDC_BCONNECT, &Cnetwork2Dlg::OnBnClickedBconnect)
	ON_BN_CLICKED(IDC_BCIRCLE, &Cnetwork2Dlg::OnBnClickedBcircle)
	ON_BN_CLICKED(IDC_BRECT, &Cnetwork2Dlg::OnBnClickedBrect)
	ON_BN_CLICKED(IDC_BSEND, &Cnetwork2Dlg::OnBnClickedBsend)
	ON_BN_CLICKED(IDC_RSERVER, &Cnetwork2Dlg::OnRType)
	ON_BN_CLICKED(IDC_RCLIENT, &Cnetwork2Dlg::OnRType)
	ON_LBN_SELCHANGE(IDC_LSENT, &Cnetwork2Dlg::OnLbnSelchangeLsent)
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()


// Cnetwork2Dlg 메시지 처리기

BOOL Cnetwork2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	m_strName = "localhost"; // 자기자신 PC로 접속(Editor Control)
	m_iType = 0; // radio button
	UpdateData(FALSE);
	m_Csocket.SetParent(this);
	m_Ssocket.SetParent(this);	m_iPaintType = 0;
	m_X = 200;
	m_Y = 200;
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void Cnetwork2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void Cnetwork2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
			CClientDC dc(this);
			dc.TextOutW(m_X, m_Y, _T("P"));

	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR Cnetwork2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void Cnetwork2Dlg::OnAccept()
{
	m_Ssocket.Accept(m_Csocket);
	GetDlgItem(IDC_BCONNECT)->EnableWindow(FALSE);
	GetDlgItem(IDC_BLISTEN)->EnableWindow(FALSE);
	/*GetDlgItem(IDC_BCIRCLE)->EnableWindow(TRUE);
	GetDlgItem(IDC_BRECT)->EnableWindow(TRUE);
	GetDlgItem(IDC_BLINE)->EnableWindow(TRUE);*/

}void Cnetwork2Dlg::OnConnect()
{
	GetDlgItem(IDC_BCONNECT)->EnableWindow(FALSE);
	GetDlgItem(IDC_BLISTEN)->EnableWindow(FALSE);
	/*GetDlgItem(IDC_BCIRCLE)->EnableWindow(TRUE);
	GetDlgItem(IDC_BRECT)->EnableWindow(TRUE);
	GetDlgItem(IDC_BLINE)->EnableWindow(TRUE);*/
}void Cnetwork2Dlg::OnClose()
{
	m_Csocket.Close();
	/*GetDlgItem(IDC_BCIRCLE)->EnableWindow(FALSE);
	GetDlgItem(IDC_BRECT)->EnableWindow(FALSE);
	GetDlgItem(IDC_BLINE)->EnableWindow(FALSE);*/
	if (m_iType == 0)
	{
		GetDlgItem(IDC_BCONNECT)->EnableWindow(FALSE);
		GetDlgItem(IDC_BLISTEN)->EnableWindow(TRUE);
	}
	else
	{
		GetDlgItem(IDC_BCONNECT)->EnableWindow(TRUE);
		GetDlgItem(IDC_BLISTEN)->EnableWindow(FALSE);
	}
}void Cnetwork2Dlg::OnSend() { }

void Cnetwork2Dlg::OnBnClickedBline()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	/*int iSent;
	const char* strMsg("line");
	int iLen = strlen(strMsg) + 1;
	iSent = m_Csocket.Send(LPCTSTR(strMsg), iLen);
	if (iSent == SOCKET_ERROR)
	{
		MessageBox(_T("전송 실패. 다시 전송해주십시오"));
	}*/
}


void Cnetwork2Dlg::OnBnClickedBlisten()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	GetDlgItem(IDC_BCONNECT)->EnableWindow(FALSE);
	GetDlgItem(IDC_BLISTEN)->EnableWindow(FALSE);
	m_Ssocket.Create(4000);
	m_Ssocket.Listen();
}


void Cnetwork2Dlg::OnBnClickedBconnect()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	GetDlgItem(IDC_BCONNECT)->EnableWindow(FALSE);
	GetDlgItem(IDC_BLISTEN)->EnableWindow(FALSE);
	UpdateData(TRUE);
	m_Csocket.Create();
	m_Csocket.Connect(m_strName, 4000);
}


void Cnetwork2Dlg::OnBnClickedBcircle()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	/*int iSent;
	const char* strMsg("circle");
	int iLen = strlen(strMsg) + 1;
	iSent = m_Csocket.Send(LPCTSTR(strMsg), iLen);
	if (iSent == SOCKET_ERROR) {
		MessageBox(_T("error"));
	}	*/
}


void Cnetwork2Dlg::OnBnClickedBrect()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	/*int iSent;
	const char* strMsg("rect");
	int iLen = strlen(strMsg) + 1;
	iSent = m_Csocket.Send(LPCTSTR(strMsg), iLen);
	if (iSent == SOCKET_ERROR)
	{
		MessageBox(_T("전송 실패. 다시 전송해주십시오"));
	}*/
}
void Cnetwork2Dlg::OnReceive()
{
	char *pBuf = new char[1025];
	int iBufSize = 1024;
	int iRcvd;
	iRcvd = m_Csocket.Receive(pBuf, iBufSize);
	if (iRcvd == SOCKET_ERROR)
	{
	}
	else {
		pBuf[iRcvd] = NULL;
		//m_ctlRecvd.AddString(LPCWSTR(pBuf));
		if (*pBuf == 'W') {
			m_Y -= 10;
		}
		if (*pBuf == 'S') {
			m_Y += 10;
		}
		if (*pBuf == 'A') {
			m_X -= 10;
		}
		if (*pBuf == 'D') {
			m_X += 10;
		}
		Invalidate(true);
	}
}

void Cnetwork2Dlg::OnBnClickedBsend(){
		int iSent;
		int iLen;
		UpdateData(TRUE);
		if (m_strMessage != "")
		{
			iLen = m_strMessage.GetLength();
			iSent = m_Csocket.Send(LPCTSTR(m_strMessage), sizeof(TCHAR)*(iLen + 1));
			if (iSent == SOCKET_ERROR) {
				MessageBox(_T("error"));
			}
			else
			{
				//m_ctlSent.AddString(m_strMessage);
				/*if (m_strMessage == 'C') {
					m_iPaintType = 1;
				}
				if (m_strMessage == 'R') {
					m_iPaintType = 2;
				}
				if (m_strMessage == 'L') {
					m_iPaintType = 3;
				}*/
				//Invalidate(true);
				//UpdateData(FALSE);
			}
		}
}


void Cnetwork2Dlg::OnRType()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	if (m_iType == 0) {
		GetDlgItem(IDC_BCONNECT)->EnableWindow(FALSE);
		GetDlgItem(IDC_BLISTEN)->EnableWindow(TRUE);
	}
	else {
		GetDlgItem(IDC_BCONNECT)->EnableWindow(TRUE);
		GetDlgItem(IDC_BLISTEN)->EnableWindow(FALSE);
	}
}


void Cnetwork2Dlg::OnLbnSelchangeLsent()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void Cnetwork2Dlg::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CDialogEx::OnKeyDown(nChar, nRepCnt, nFlags);
}
