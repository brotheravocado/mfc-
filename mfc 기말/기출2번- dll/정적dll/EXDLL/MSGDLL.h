// MSGDLL.h : MSGDLL DLL의 주 헤더 파일
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH에 대해 이 파일을 포함하기 전에 'stdafx.h'를 포함합니다."
#endif

#include "resource.h"		// 주 기호입니다.


// CMSGDLLApp
// 이 클래스 구현에 대해서는 MSGDLL.cpp를 참조하세요.
//

class CMSGDLLApp : public CWinApp
{
public:
	CMSGDLLApp();

// 재정의입니다.
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()


	                                 
};
extern "C" _declspec (dllimport) CString PowM();