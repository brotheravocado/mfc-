// project.cpp: 구현 파일
//

#include "stdafx.h"
#include "yunji.h"
#include "project.h"
#include "afxdialogex.h"


// project 대화 상자

IMPLEMENT_DYNAMIC(project, CDialog)

project::project(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_D, pParent)
{

}

project::~project()
{
}

void project::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(project, CDialog)
END_MESSAGE_MAP()


// project 메시지 처리기
