// CPOPUP.cpp: 구현 파일
//

#include "stdafx.h"
#include "yunji.h"
#include "CPOPUP.h"
#include "afxdialogex.h"
#include "CSingle.h"
#include "NETWORK.h"
// CPOPUP 대화 상자

IMPLEMENT_DYNAMIC(CPOPUP, CDialog)

CPOPUP::CPOPUP(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG1, pParent)


	, m_radio(0)
{

}

CPOPUP::~CPOPUP()
{
}

void CPOPUP::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	//  DDX_Control(pDX, IDC_SINGLE, m_single);
	//  DDX_Control(pDX, IDOK, m_Btn_Test);
	//  DDX_Control(pDX, IDC_SINGLE, m_single);

	DDX_Radio(pDX, IDC_SINGLE, m_radio);
}


BEGIN_MESSAGE_MAP(CPOPUP, CDialog)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDOK, &CPOPUP::OnBnClickedOk)
END_MESSAGE_MAP()


// CPOPUP 메시지 처리기


BOOL CPOPUP::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	m_back.Load(_T("Mode.png"));

	SetWindowTheme(GetDlgItem(IDC_SINGLE)->m_hWnd, _T("L"), _T("L")); // 투명
	SetWindowTheme(GetDlgItem(IDC_DUAL)->m_hWnd, _T("L"), _T("L")); // 투명


	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CPOPUP::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CDialog::OnPaint()을(를) 호출하지 마십시오.
	CString str;
	m_back.Draw(dc, 0, 0);
}


HBRUSH CPOPUP::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) // 메세지에서 ctlcolor 추가 배경 투명
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  여기서 DC의 특성을 변경합니다.
	if (nCtlColor == CTLCOLOR_STATIC)	//STATIC 컨트롤만 배경색 변경
		pDC->SetBkColor(RGB(139, 215, 248));	//배경색 변경
	else	//그 외의 컨트롤은 배경을 투명하게
		pDC->SetBkMode(TRANSPARENT);		//배경 투명하게
	hbr = (HBRUSH)GetStockObject(NULL_BRUSH);
	return hbr;
	// TODO:  기본값이 적당하지 않으면 다른 브러시를 반환합니다.
}


void CPOPUP::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다
	UpdateData(true);
	CDialog::OnOK();
	if (m_radio == 0) {
		CSingle pop;
		if (pop.DoModal() == IDOK) {

		}
	}
	else {
		NETWORK pop;
		if (pop.DoModal() == IDOK) {

		}

	}
}
