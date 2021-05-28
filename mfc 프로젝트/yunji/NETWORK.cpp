// NETWORK.cpp: 구현 파일
//

#include "stdafx.h"
#include "yunji.h"
#include "NETWORK.h"
#include "afxdialogex.h"
#include "project.h"

// NETWORK 대화 상자

IMPLEMENT_DYNAMIC(NETWORK, CDialog)

NETWORK::NETWORK(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_NETWORK, pParent)
	, m_iType(0)
	, m_strName(_T(""))
{

}

NETWORK::~NETWORK()
{
}

void NETWORK::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_RSERVER, m_iType);
	DDX_Text(pDX, IDC_ESERVNAME, m_strName);
}


BEGIN_MESSAGE_MAP(NETWORK, CDialog)
	ON_BN_CLICKED(IDC_RSERVER, &NETWORK::OnRType)
	ON_BN_CLICKED(IDC_RCLIENT, &NETWORK::OnRType)
	ON_BN_CLICKED(IDC_BLISTEN, &NETWORK::OnBnClickedBlisten)
	ON_BN_CLICKED(IDC_BDISCON, &NETWORK::OnBnClickedBdiscon)
	ON_BN_CLICKED(IDC_BCONNECT, &NETWORK::OnBnClickedBconnect)
	ON_WM_TIMER()
	ON_WM_PAINT()
//	ON_WM_CTLCOLOR()
ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// NETWORK 메시지 처리기


void NETWORK::OnRType()
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


BOOL NETWORK::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	m_network.Load(_T("network.png"));
	m_strName = "localhost"; // 자기자신 PC로 접속(Editor Control)
	m_iType = 0; // radio button
	UpdateData(FALSE);
	m_Csocket.SetParent(this);
	m_Ssocket.SetParent(this);
	//m_iPaintType = 0;
	SetWindowTheme(GetDlgItem(IDC_RSERVER)->m_hWnd, _T("L"), _T("L")); // 투명
	SetWindowTheme(GetDlgItem(IDC_RCLIENT)->m_hWnd, _T("L"), _T("L")); // 투명
	SetWindowTheme(GetDlgItem(IDC_STATIC)->m_hWnd, _T("L"), _T("L")); // 투명
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
void NETWORK::OnAccept()
{
	m_Ssocket.Accept(m_Csocket);
	GetDlgItem(IDC_BCONNECT)->EnableWindow(FALSE);
	GetDlgItem(IDC_BLISTEN)->EnableWindow(FALSE);
	count = 3;
	SetTimer(1, 1000, NULL);

}
void NETWORK::OnConnect() 
{
	GetDlgItem(IDC_BCONNECT)->EnableWindow(FALSE);
	GetDlgItem(IDC_BLISTEN)->EnableWindow(FALSE);
	count = 3;
	SetTimer(1, 1000, NULL);

}
void NETWORK::OnClose()
{
	m_Csocket.Close();

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
}void NETWORK::OnSend() {}
void NETWORK::OnReceive() {

	
	
}
void NETWORK::OnBnClickedBlisten()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	GetDlgItem(IDC_BCONNECT)->EnableWindow(FALSE);
	GetDlgItem(IDC_BLISTEN)->EnableWindow(FALSE);

	m_Ssocket.Create(4000);
	m_Ssocket.Listen();
}


void NETWORK::OnBnClickedBdiscon()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void NETWORK::OnBnClickedBconnect()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	GetDlgItem(IDC_BCONNECT)->EnableWindow(FALSE);
	GetDlgItem(IDC_BLISTEN)->EnableWindow(FALSE);
	UpdateData(TRUE);
	m_Csocket.Create();
	m_Csocket.Connect(m_strName, 4000);
	

}


void NETWORK::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CClientDC dc(this);
	CString str;
	project pop;
	switch (nIDEvent)
	{
	case 1:
		if (count >= 0) {
			str.Format(_T("연결되었습니다. %d초 후에 게임이 시작됩니다."), count);
			dc.TextOutW(120, 200, str);
			count--;
			break;
		}
		else {
			KillTimer(1);
			CDialog::OnOK();
			if (pop.DoModal() == IDOK) {

			}
		}
	default:
		break;
	}
	CDialog::OnTimer(nIDEvent);
}


void NETWORK::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CDialog::OnPaint()을(를) 호출하지 마십시오.
	m_network.Draw(dc,0,0);
}


//HBRUSH NETWORK::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
//{
//	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

//	
//	return hbr;
//}


HBRUSH NETWORK::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  여기서 DC의 특성을 변경합니다.

	// TODO:  기본값이 적당하지 않으면 다른 브러시를 반환합니다.
	if (nCtlColor == CTLCOLOR_STATIC)	//STATIC 컨트롤만 배경색 변경
	{
		pDC->SetBkColor(RGB(151,201,242));	//배경색 변경
		hbr = (HBRUSH)GetStockObject(NULL_BRUSH);
	}

	//else	//그 외의 컨트롤은 배경을 투명하게
		//pDC->SetBkMode(TRANSPARENT);		//배경 투명하게

	// TODO:  기본값이 적당하지 않으면 다른 브러시를 반환합니다.
	return hbr;
}
