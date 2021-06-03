#pragma once
#pragma comment(lib, "UxTheme.lib")

// CPOPUP 대화 상자

class CPOPUP : public CDialog
{
	DECLARE_DYNAMIC(CPOPUP)

public:
	CPOPUP(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CPOPUP();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CImage m_back;
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
//	CButton m_single;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnClickedOk();
//	CButton m_Btn_Test;
//	BOOL m_single;
//	BOOL m_dual;
	int m_radio;
};
