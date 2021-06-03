
// projectDlg.h: 헤더 파일
//

#pragma once


// CprojectDlg 대화 상자
class CprojectDlg : public CDialogEx
{
// 생성입니다.
public:
	CprojectDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PROJECT_DIALOG };
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
//	CImage m_img;
public:
//	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
//	int x;
//	int y;
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	int m_X;
	int m_Y;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	int random();
	int count = 0;
	int num ;
	CRgn rgn;
	int x;
	int y;
	int gap;
	int location;
	CPoint point;
};
