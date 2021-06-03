#pragma once
#include "CPowDlg.h"

// DualDialog 대화 상자

class DualDialog : public CDialogEx
{
	DECLARE_DYNAMIC(DualDialog)

public:
	DualDialog(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~DualDialog();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DUAL_CARD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	int m_X;
	int m_Y;
	int m_X2;
	int m_Y2;
	int m_X3;
	int m_Y3;
	int m_X4;
	int m_Y4;
	int m_X5;
	int m_Y5;
	int num = rand() % 5;
};
