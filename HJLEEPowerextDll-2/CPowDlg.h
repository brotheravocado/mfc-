#pragma once
#include "resource.h"

// CPowDlg 대화 상자

class AFX_EXT_CLASS CPowDlg : public CDialog
{
	DECLARE_DYNAMIC(CPowDlg)

public:
	CPowDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CPowDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_POWDLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
	HICON m_hIcon; 

	// 생성된 메시지 맵 함수
//	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//DECLARE_MESSAGE_MAP()
	//	CImage m_img;
public:
	//	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	//	int x;
	//	int y;
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	int random();
	int first_gap(int num, int i, int x, int m);
	static UINT ThreadWorker1(LPVOID pParam);
	static UINT ThreadWorker2(LPVOID pParam);
	static UINT ThreadWorker3(LPVOID pParam);
	static UINT ThreadWorker4(LPVOID pParam);
	static UINT ThreadWorker5(LPVOID pParam);
	static UINT ThreadWorker6(LPVOID pParam);
	static UINT ThreadWorker7(LPVOID pParam);
	static UINT ThreadWorker8(LPVOID pParam);
	static UINT ThreadWorker9(LPVOID pParam);
	static UINT ThreadWorker10(LPVOID pParam);
	/*static UINT ThreadWorker11(LPVOID pParam);
	static UINT ThreadWorker12(LPVOID pParam);*/
	static UINT ThreadWorker13(LPVOID pParam);
	static UINT ThreadWorker14(LPVOID pParam);
	/*static UINT ThreadWorker15(LPVOID pParam);
	static UINT ThreadWorker16(LPVOID pParam);*/
	CWinThread *m_pWorkerThread1 = NULL;
	CWinThread *m_pWorkerThread2 = NULL;
	CWinThread *m_pWorkerThread3 = NULL;
	CWinThread *m_pWorkerThread4 = NULL;
	CWinThread *m_pWorkerThread5 = NULL;
	CWinThread *m_pWorkerThread6 = NULL;
	CWinThread *m_pWorkerThread7 = NULL;
	CWinThread *m_pWorkerThread8 = NULL;
	CWinThread *m_pWorkerThread9 = NULL;
	CWinThread *m_pWorkerThread10 = NULL;
	/*CWinThread *m_pWorkerThread11 = NULL;
	CWinThread *m_pWorkerThread12 = NULL;*/
	CWinThread *m_pWorkerThread13 = NULL;
	CWinThread *m_pWorkerThread14 = NULL;
	/*CWinThread *m_pWorkerThread15 = NULL;
	CWinThread *m_pWorkerThread16 = NULL;*/
	void Paint(int num, int location, int select);
	void life();
	void score();
	void eraser(CRgn &rgn, BOOL tf);
	void bigisland();
	void smallisland();
	void turn();
	void EXIT();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	virtual BOOL OnInitDialog();
};
