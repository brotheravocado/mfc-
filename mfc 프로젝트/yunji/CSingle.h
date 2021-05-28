#pragma once


// CSingle 대화 상자

class CSingle : public CDialog
{
	DECLARE_DYNAMIC(CSingle)

public:
	CSingle(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CSingle();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
