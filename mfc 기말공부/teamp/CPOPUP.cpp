// CPOPUP.cpp: 구현 파일
//

#include "stdafx.h"
#include "teamp.h"
#include "CPOPUP.h"
#include "afxdialogex.h"


// CPOPUP 대화 상자

IMPLEMENT_DYNAMIC(CPOPUP, CDialog)

CPOPUP::CPOPUP(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG1, pParent)
	, m_str(_T(""))
{

}

CPOPUP::~CPOPUP()
{
}

void CPOPUP::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_str);
}


BEGIN_MESSAGE_MAP(CPOPUP, CDialog)
END_MESSAGE_MAP()


// CPOPUP 메시지 처리기
