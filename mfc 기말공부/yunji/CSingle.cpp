// CSingle.cpp: 구현 파일
//

#include "stdafx.h"
#include "yunji.h"
#include "CSingle.h"
#include "afxdialogex.h"


// CSingle 대화 상자

IMPLEMENT_DYNAMIC(CSingle, CDialog)

CSingle::CSingle(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_S, pParent)
{

}

CSingle::~CSingle()
{
}

void CSingle::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSingle, CDialog)
END_MESSAGE_MAP()


// CSingle 메시지 처리기
