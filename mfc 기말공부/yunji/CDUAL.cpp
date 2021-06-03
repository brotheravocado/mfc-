// CDUAL.cpp: 구현 파일
//

#include "stdafx.h"
#include "yunji.h"
#include "CDUAL.h"
#include "afxdialogex.h"


// CDUAL 대화 상자

IMPLEMENT_DYNAMIC(CDUAL, CDialog)

CDUAL::CDUAL(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DUAL, pParent)
{

}

CDUAL::~CDUAL()
{
}

void CDUAL::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDUAL, CDialog)
END_MESSAGE_MAP()


// CDUAL 메시지 처리기
