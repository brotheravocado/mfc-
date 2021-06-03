// DualDialog.cpp: 구현 파일
//

#include "stdafx.h"
#include "CPowDlg.h"
#include "DualDialog.h"
#include "afxdialogex.h"
#include <stdlib.h>
#include <time.h>


// DualDialog 대화 상자

IMPLEMENT_DYNAMIC(DualDialog, CDialogEx)

DualDialog::DualDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DUAL_CARD, pParent)
{

}

DualDialog::~DualDialog()
{
}

void DualDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DualDialog, CDialogEx)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// DualDialog 메시지 처리기


BOOL DualDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	m_X = 5000;
	m_Y = 5000;
	m_X2 = 6000;
	m_Y2 = 6000;
	m_X3 = 7000;
	m_Y3 = 7000;
	m_X4 = 8000;
	m_Y4 = 8000;
	m_X5 = 9000;
	m_Y5 = 9000;
	srand((unsigned)time(NULL));

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void DualDialog::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CDialogEx::OnPaint()을(를) 호출하지 마십시오.
	CDC *CDC_Dlg;
	CDC BG; // 배경
	CDC CARD; // 카드 뒷면
	CDC SORRY; // 꽝
	CDC SPEED; // 속도+
	CDC TIME; // 시간+
	CDC OK; // 확인
	CDC DISABLED; // 상대방 화면 가리기
	CDC TIME2; // 상대방 시간-

	CBitmap bg;
	CBitmap card1;
	CBitmap card2;
	CBitmap card3;
	CBitmap sorry;
	CBitmap speed;
	CBitmap time;
	CBitmap ok;
	CBitmap disabled;
	CBitmap time2;

	CDC_Dlg = GetDC();

	bg.LoadBitmap(IDB_BG);
	BG.CreateCompatibleDC(CDC_Dlg);
	BG.SelectObject(bg);
	BitBlt(*CDC_Dlg, 0, 0, 2000, 2000, BG, 0, 0, SRCCOPY);

	card1.LoadBitmap(IDB_CARD); // 카드 뒷면
	CARD.CreateCompatibleDC(CDC_Dlg);
	CARD.SelectObject(card1);
	TransparentBlt(*CDC_Dlg, 60, 80, 147, 239, CARD, 0, 0, 147, 239, RGB(255, 255, 255));
	card2.LoadBitmap(IDB_CARD);
	CARD.CreateCompatibleDC(CDC_Dlg);
	CARD.SelectObject(card2);
	TransparentBlt(*CDC_Dlg, 295, 80, 147, 239, CARD, 0, 0, 147, 239, RGB(255, 255, 255));
	card3.LoadBitmap(IDB_CARD);
	CARD.CreateCompatibleDC(CDC_Dlg);
	CARD.SelectObject(card3);
	TransparentBlt(*CDC_Dlg, 525, 80, 147, 239, CARD, 0, 0, 147, 239, RGB(255, 255, 255));

	sorry.LoadBitmap(IDB_SORRY); // 꽝
	SORRY.CreateCompatibleDC(CDC_Dlg);
	SORRY.SelectObject(sorry);
	TransparentBlt(*CDC_Dlg, m_X, m_Y, 147, 239, SORRY, 0, 0, 147, 239, RGB(255, 255, 255));
	speed.LoadBitmap(IDB_SPEED); // 속도UP
	SPEED.CreateCompatibleDC(CDC_Dlg);
	SPEED.SelectObject(speed);
	TransparentBlt(*CDC_Dlg, m_X2, m_Y2, 147, 239, SPEED, 0, 0, 147, 239, RGB(255, 255, 255));
	time.LoadBitmap(IDB_TIME); // 시간추가
	TIME.CreateCompatibleDC(CDC_Dlg);
	TIME.SelectObject(time);
	TransparentBlt(*CDC_Dlg, m_X3, m_Y3, 147, 239, TIME, 0, 0, 147, 239, RGB(255, 255, 255));
	disabled.LoadBitmap(IDB_DISABLED); // 화면가리기
	DISABLED.CreateCompatibleDC(CDC_Dlg);
	DISABLED.SelectObject(disabled);
	TransparentBlt(*CDC_Dlg, m_X4, m_Y4, 147, 239, DISABLED, 0, 0, 147, 239, RGB(255, 255, 255));
	time2.LoadBitmap(IDB_TIME2); // 상대방 시간-
	TIME2.CreateCompatibleDC(CDC_Dlg);
	TIME2.SelectObject(time);
	TransparentBlt(*CDC_Dlg, m_X5, m_Y5, 147, 239, TIME2, 0, 0, 147, 239, RGB(255, 255, 255));

	ok.LoadBitmap(IDB_OK); // 확인
	OK.CreateCompatibleDC(CDC_Dlg);
	OK.SelectObject(ok);
	TransparentBlt(*CDC_Dlg, 320, 400, 100, 30, OK, 0, 0, 100, 30, RGB(255, 255, 255));

}


void DualDialog::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CRect rt1(60, 80, 147, 239);
	CRect rt2(295, 80, 442, 239);
	CRect rt3(525, 80, 672, 239);
	CRect button(320, 400, 420, 430);
	UpdateData(TRUE);
	if (num == 0) { // 꽝
		if (rt1.PtInRect(point)) {
			m_X = 60;
			m_Y = 80;
			Invalidate(FALSE);
			UpdateData(FALSE);
		}
		else if (rt2.PtInRect(point)) {
			m_X = 295;
			m_Y = 80;
			Invalidate(FALSE);
			UpdateData(FALSE);
		}
		else if (rt3.PtInRect(point)) {
			m_X = 525;
			m_Y = 80;
			Invalidate(FALSE);
			UpdateData(FALSE);
		}
		if (button.PtInRect(point)) {
			::SendMessage(this->m_hWnd, WM_CLOSE, NULL, NULL); // 창 닫기
		}
		Invalidate(FALSE);
		UpdateData(FALSE);
	}
	else if (num == 1) { // 속도+
		if (rt1.PtInRect(point)) {
			m_X2 = 60;
			m_Y2 = 80;
			Invalidate(FALSE);
			UpdateData(FALSE);
		}
		else if (rt2.PtInRect(point)) {
			m_X2 = 295;
			m_Y2 = 80;
			Invalidate(FALSE);
			UpdateData(FALSE);
		}
		else if (rt3.PtInRect(point)) {
			m_X2 = 525;
			m_Y2 = 80;
			Invalidate(FALSE);
			UpdateData(FALSE);
		}
		if (button.PtInRect(point)) {
			::SendMessage(this->m_hWnd, WM_CLOSE, NULL, NULL);
		}
		Invalidate(FALSE);
		UpdateData(FALSE);
	}
	else if (num == 2) { // 시간추가
		if (rt1.PtInRect(point)) {
			m_X3 = 60;
			m_Y3 = 80;
			Invalidate(FALSE);
			UpdateData(FALSE);
		}
		else if (rt2.PtInRect(point)) {
			m_X3 = 295;
			m_Y3 = 80;
			Invalidate(FALSE);
			UpdateData(FALSE);
		}
		else if (rt3.PtInRect(point)) {
			m_X3 = 525;
			m_Y3 = 80;
			Invalidate(FALSE);
			UpdateData(FALSE);
		}
		if (button.PtInRect(point)) {
			::SendMessage(this->m_hWnd, WM_CLOSE, NULL, NULL);
		}
		Invalidate(FALSE);
		UpdateData(FALSE);
	}
	else if (num == 3) { // 상대방 화면가리기
		if (rt1.PtInRect(point)) {
			m_X4 = 60;
			m_Y4 = 80;
			Invalidate(FALSE);
			UpdateData(FALSE);
		}
		else if (rt2.PtInRect(point)) {
			m_X4 = 295;
			m_Y4 = 80;
			Invalidate(FALSE);
			UpdateData(FALSE);
		}
		else if (rt3.PtInRect(point)) {
			m_X4 = 525;
			m_Y4 = 80;
			Invalidate(FALSE);
			UpdateData(FALSE);
		}
		if (button.PtInRect(point)) {

			::SendMessage(this->m_hWnd, WM_CLOSE, NULL, NULL);
		}
		Invalidate(FALSE);
		UpdateData(FALSE);
	}
	else if (num == 4) { // 상대방 시간-
		if (rt1.PtInRect(point)) {
			m_X5 = 60;
			m_Y5 = 80;
			Invalidate(FALSE);
			UpdateData(FALSE);
		}
		else if (rt2.PtInRect(point)) {
			m_X5 = 295;
			m_Y5 = 80;
			Invalidate(FALSE);
			UpdateData(FALSE);
		}
		else if (rt3.PtInRect(point)) {
			m_X5 = 525;
			m_Y5 = 80;
			Invalidate(FALSE);
			UpdateData(FALSE);
		}
		if (button.PtInRect(point)) {
			::SendMessage(this->m_hWnd, WM_CLOSE, NULL, NULL);
		}
		Invalidate(FALSE);
		UpdateData(FALSE);
	}
	UpdateData(FALSE);

	CDialogEx::OnLButtonDown(nFlags, point);
}
