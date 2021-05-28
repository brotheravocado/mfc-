
// exam03Dlg.h: 헤더 파일
//

#pragma once


// Cexam03Dlg 대화 상자
class Cexam03Dlg : public CDialogEx
{
// 생성입니다.
public:
	Cexam03Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EXAM03_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();
	static UINT ThreadWorker1(LPVOID pParam);
	CWinThread *m_pWorkerThread1 =NULL;
	int line = 0 ;
	int gap = 1;
	BOOL incr = FALSE;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedCheck1();
	BOOL m_bWorkerPause1;
};
