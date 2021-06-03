
// network2Dlg.h: 헤더 파일
//

#pragma once
#include "CMySocket.h"

// Cnetwork2Dlg 대화 상자
class Cnetwork2Dlg : public CDialogEx
{
// 생성입니다.
public:
	Cnetwork2Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_NETWORK2_DIALOG };
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
	CMySocket m_Ssocket, m_Csocket;
	void OnAccept();
	void OnConnect();
	void OnClose();
	void OnReceive();
	void OnSend();
	int m_iType;
	int m_iPaintType;
	CString m_strName;
	afx_msg void OnBnClickedBline();
	afx_msg void OnBnClickedBlisten();
	afx_msg void OnBnClickedBconnect();
	afx_msg void OnBnClickedBcircle();
	afx_msg void OnBnClickedBrect();
	CString m_strMessage;
//	CListBox m_ctlSent;
//	CListBox m_ctlRecvd;
	afx_msg void OnBnClickedBsend();
	afx_msg void OnRType();
	afx_msg void OnLbnSelchangeLsent();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	int m_X;
	int m_Y;
};
