#pragma once
#include "CMySocket.h"

// NETWORK 대화 상자

class NETWORK : public CDialog
{
	DECLARE_DYNAMIC(NETWORK)

public:
	NETWORK(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~NETWORK();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_NETWORK };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CMySocket m_Ssocket, m_Csocket;
	void OnAccept();
	void OnConnect();
	void OnClose();
	void OnReceive();
	void OnSend();
	int m_iType;
	CString m_strName;
	afx_msg void OnRType();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedBlisten();
	afx_msg void OnBnClickedBdiscon();
	afx_msg void OnBnClickedBconnect();
	int m_iPaintType;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	int count;
	CImage m_network;
	afx_msg void OnPaint();
//	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
