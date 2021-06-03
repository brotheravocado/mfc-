// CPowDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "CPowDlg.h"
#include "afxdialogex.h"
#include "DualDialog.h"
#include <ctime>

#pragma comment(lib, "msimg32.lib")
int gametime = 60;
int m_X;// 사람 좌표
int m_Y;
int m_X2 = 0; // 갈매기
int m_Y2 = 10000;
int m_X3 = 0; // 보물상자 좌표 
int m_Y3 = 400;
int m_X4;//무적상태 필요한 다른 색깔의 사람 좌표
int m_Y4;
int m_X5; //목숨깍이는 하트1
int m_Y5;
int m_X6; //목숨깍이는 하트2
int m_Y6;
int m_X7; //목숨깍이는 하트3
int m_Y7;
int ix; // 섬 커지는거
int iy;
int six; // 섬 작아지는거
int siy;
int m_x8;// 원래 섬 
int m_y8;

int count = 0;
int c = 0;
int c2 = 0;
int d = 0;
int countt = 300; // 무적상태 구현되는 시간  // 35
int num;
int location;
CRgn rgn;
int timercheck = 0;
int dontcare = 0; // 무적상태
int is1 = 260;
int is2 = 110;
int is3 = 480;
int is4 = 270;

//오른쪽 위

static int location1 = 0;
static int num1 = 0;
static int count1 = 0;
static CRgn rgn11;
static CRgn rgn12;

//왼쪽 위
static int location2 = 0;
static int num2 = 0;
static int count2 = 0;
static CRgn rgn21;
static CRgn rgn22;

//오른쪽 벽 위
static int location3 = 0;
static int num3 = 938;
static int count3 = 0;
static CRgn rgn31;
static CRgn rgn32;

//오른쪽  벽 밑
static int location4 = 0;
static int num4 = 938;
static int count4 = 0;
static CRgn rgn41;
static CRgn rgn42;

//오른쪽  밑
static int location5 = 688;
static int num5 = 0;
static int count5 = 0;
static CRgn rgn51;
static CRgn rgn52;

//왼쪽  밑
static int location6 = 688;
static int num6 = 0;
static int count6 = 0;
static CRgn rgn61;
static CRgn rgn62;

//왼쪽 벽 밑
static int location7 = 0;
static int num7 = 0;
static int count7 = 0;
static CRgn rgn71;
static CRgn rgn72;

//왼쪽  벽 위
static int location8 = 0;
static int num8 = 0;
static int count8 = 0;
static CRgn rgn81;
static CRgn rgn82;
//오른쪽 위

static int location9 = 0;
static int num9 = 0;
static int count9 = 0;
static CRgn rgn91;
static CRgn rgn92;

//왼쪽 위
static int location10 = 0;
static int num10 = 0;
static int count10 = 0;
static CRgn rgn101;
static CRgn rgn102;

//오른쪽 벽 위
static int location11 = 0;
static int num11 = 938;
static int count11 = 0;
static CRgn rgn111;
static CRgn rgn112;

//오른쪽  벽 밑
static int location12 = 0;
static int num12 = 938;
static int count12 = 0;
static CRgn rgn121;
static CRgn rgn122;

//오른쪽  밑
static int location13 = 688;
static int num13 = 0;
static int count13 = 0;
static CRgn rgn131;
static CRgn rgn132;

//왼쪽  밑
static int location14 = 688;
static int num14 = 0;
static int count14 = 0;
static CRgn rgn141;
static CRgn rgn142;

//왼쪽 벽 밑
static int location15 = 0;
static int num15 = 0;
static int count15 = 0;
static CRgn rgn151;
static CRgn rgn152;

//왼쪽  벽 위
static int location16 = 0;
static int num16 = 0;
static int count16 = 0;
static CRgn rgn161;
static CRgn rgn162;

// CPowDlg 대화 상자

IMPLEMENT_DYNAMIC(CPowDlg, CDialog)

CPowDlg::CPowDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_POWDLG, pParent)
{
	//m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_X = 0;
	m_Y = 0;
}

CPowDlg::~CPowDlg()
{
}

void CPowDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//  DDX_Text(pDX, IDC_INPUT, m_input);
}


BEGIN_MESSAGE_MAP(CPowDlg, CDialog)
//	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	//ON_WM_QUERYDRAGICON()
	//	ON_WM_KEYDOWN()
	ON_WM_KEYUP()
	ON_WM_TIMER()
	ON_WM_LBUTTONDOWN()
//	ON_BN_CLICKED(IDC_BRESULT, &CPowDlg::OnBnClickedBresult)
END_MESSAGE_MAP()


// CPowDlg 메시지 처리기


BOOL CPowDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	m_X = 350;
	m_Y = 200;
	m_X4 = 0;  // 무적상태
	m_Y4 = 10000; // 무적상태
	m_X5 = 0; // 목숨깍이는 하트 위치1
	m_Y5 = 10000;
	m_X6 = 0; // 목숨깍이는 하트 위치2
	m_Y6 = 10000;
	m_X7 = 0; // 목숨깍이는 하트 위치3
	m_Y7 = 10000;
	num = random();
	m_x8 = 240;
	m_y8 = 100;

	num1 = first_gap(num1, 0, 600, 800);
	SetTimer(10, 50, NULL);
	num2 = first_gap(num2, 0, 100, 250);
	SetTimer(11, 50, NULL);
	location3 = first_gap(location3, 0, 0, 100);
	SetTimer(12, 50, NULL);
	location4 = first_gap(location4, 0, 550, 688);
	SetTimer(13, 50, NULL);
	SetTimer(1, 100, NULL); // 보물상자
	SetTimer(2, 2500, NULL); //보물상자
	//SetTimer(3, 100, NULL);//갈매기
	SetTimer(5, 1000, NULL);
	SetTimer(9, 50, NULL); // 5초 후에 
	num9 = first_gap(num9, 0, 600, 800);
	num10 = first_gap(num10, 0, 100, 250);
	num13 = first_gap(num13, 0, 700, 800);
	num14 = first_gap(num14, 0, 0, 200);
	SetTimer(1, 100, NULL); // 보물상자
	SetTimer(2, 2500, NULL); //보물상자
	SetTimer(5, 1000, NULL);
	ix = 0;
	iy = 10000;;
	six = 0;
	siy = 10000;

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void CPowDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();

		CClientDC dc(this);
		CDC *CDC_Dlg;

		CDC MemDC;// 바다
		CDC memdc; // 섬
		CDC memDC; // 사람
		CDC heart_1;
		CDC heart_2;
		CDC heart_3;
		CDC Bird;
		CDC memDC2; // 무적상태 사람 
		CDC bheart_1;
		CDC bheart_2;
		CDC bheart_3;
		CDC bisland;
		CDC sisland;

		CBitmap bitmap;
		CBitmap bitmap2;
		CBitmap bitmap3;
		CBitmap heart1;
		CBitmap heart2;
		CBitmap heart3;
		CBitmap bird;
		CBitmap person2; // 무적상태 사람
		CBitmap bheart1;
		CBitmap bheart2;
		CBitmap bheart3;
		CBitmap bbisland;
		CBitmap ssisland;

		CDC_Dlg = GetDC();

		bitmap.LoadBitmap(IDB_SEA);
		bitmap2.LoadBitmap(IDB_ISLAND);
		bitmap3.LoadBitmap(IDB_PERSON);
		heart1.LoadBitmap(IDB_HEART1);
		heart2.LoadBitmap(IDB_HEART2);
		heart3.LoadBitmap(IDB_HEART3);
		bird.LoadBitmap(IDB_BIRD);
		person2.LoadBitmap(IDB_PERSON2);
		bheart1.LoadBitmap(IDB_BHEART1);
		bheart2.LoadBitmap(IDB_BHEART2);
		bheart3.LoadBitmap(IDB_BHEART3);
		bbisland.LoadBitmap(IDB_BIGISLAND);
		ssisland.LoadBitmap(IDB_SISLAND);

		MemDC.CreateCompatibleDC(CDC_Dlg);
		MemDC.SelectObject(bitmap);
		memdc.CreateCompatibleDC(CDC_Dlg);
		memdc.SelectObject(bitmap2);
		memDC.CreateCompatibleDC(CDC_Dlg);
		memDC.SelectObject(bitmap3);
		heart_1.CreateCompatibleDC(CDC_Dlg);
		heart_1.SelectObject(heart1);
		heart_2.CreateCompatibleDC(CDC_Dlg);
		heart_2.SelectObject(heart2);
		heart_3.CreateCompatibleDC(CDC_Dlg);
		heart_3.SelectObject(heart3);
		Bird.CreateCompatibleDC(CDC_Dlg);
		Bird.SelectObject(bird);
		memDC2.CreateCompatibleDC(CDC_Dlg);
		memDC2.SelectObject(person2);
		bheart_1.CreateCompatibleDC(CDC_Dlg);
		bheart_1.SelectObject(bheart1);
		bheart_2.CreateCompatibleDC(CDC_Dlg);
		bheart_2.SelectObject(bheart2);
		bheart_3.CreateCompatibleDC(CDC_Dlg);
		bheart_3.SelectObject(bheart3);
		bisland.CreateCompatibleDC(CDC_Dlg);
		bisland.SelectObject(bbisland);
		sisland.CreateCompatibleDC(CDC_Dlg);
		sisland.SelectObject(ssisland);

		//CDC *CDC_Dlg;
		CDC BOX;
		CBitmap box;
		box.LoadBitmap(IDB_BOX);
		BOX.CreateCompatibleDC(CDC_Dlg);
		BOX.SelectObject(box);


		BitBlt(*CDC_Dlg, 0, 0, 2500, 3000, MemDC, 0, 0, SRCCOPY);// 배경
		BitBlt(*CDC_Dlg, m_x8, m_y8, 280, 300, memdc, 0, 0, SRCCOPY); //섬 
		BitBlt(*CDC_Dlg, 10, 10, 70, 80, heart_1, 0, 0, SRCCOPY);// 하트1
		BitBlt(*CDC_Dlg, 80, 10, 70, 80, heart_2, 0, 0, SRCCOPY);// 하트2
		BitBlt(*CDC_Dlg, 150, 10, 70, 80, heart_3, 0, 0, SRCCOPY);// 하트3
		BitBlt(*CDC_Dlg, m_X5, m_Y5, 70, 80, bheart_1, 0, 0, SRCCOPY);// 목숨깍이는하트1
		BitBlt(*CDC_Dlg, m_X6, m_Y6, 70, 80, bheart_1, 0, 0, SRCCOPY);// 목숨깍이는하트2
		BitBlt(*CDC_Dlg, m_X7, m_Y7, 70, 80, bheart_1, 0, 0, SRCCOPY);// 목숨깍이는하트3
		BitBlt(*CDC_Dlg, ix, iy, 427, 413, bisland, 0, 0, SRCCOPY);// 섬 커지는거 
		BitBlt(*CDC_Dlg, six, siy, 403, 417, sisland, 0, 0, SRCCOPY);// 섬 작아지는거

		TransparentBlt(*CDC_Dlg, m_X2, m_Y2, 91, 89, Bird, 0, 0, 91, 89, RGB(255, 255, 255));// 갈매기
		TransparentBlt(*CDC_Dlg, m_X, m_Y, 69, 93, memDC, 0, 0, 69, 93, RGB(255, 255, 255));//사람
		TransparentBlt(*CDC_Dlg, m_X3, m_Y3, 68, 60, BOX, 0, 0, 68, 60, RGB(255, 255, 255));//보물상자
		TransparentBlt(*CDC_Dlg, m_X4, m_Y4, 69, 93,
			memDC2, 0, 0, 69, 93, RGB(255, 255, 255)); // 무적상태 사람
	}
}


void CPowDlg::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CDialog::OnKeyUp(nChar, nRepCnt, nFlags);
	CRgn rgn1;

	rgn1.CreateEllipticRgn(is1, is2, is3, is4); // 260 110 480 270
	switch (nChar) {
	case 'A':
	case 'a':
		if (rgn1.PtInRegion(m_X, m_Y)) {
			m_X -= 15;

		}
		if (!rgn1.PtInRegion(m_X, m_Y)) {
			m_X += 15;
		}
		if (countt >= 0) {
			if (d % 3 == 2) {
				m_X4 = m_X;
				m_Y4 = m_Y;
			}
		}
		break;
	case 'D':
	case 'd':
		if (rgn1.PtInRegion(m_X, m_Y)) {
			m_X += 15;
		}
		if (!rgn1.PtInRegion(m_X, m_Y)) {
			m_X -= 15;
		}
		if (countt >= 0) {
			if (d % 3 == 2) {
				m_X4 = m_X;
				m_Y4 = m_Y;
			}
		}
		break;
	case 'W':
	case 'w':
		if (rgn1.PtInRegion(m_X, m_Y)) {
			m_Y -= 15;
		}
		if (!rgn1.PtInRegion(m_X, m_Y)) {
			m_Y += 15;
		}
		if (countt >= 0) {
			if (d % 3 == 2) {
				m_X4 = m_X;
				m_Y4 = m_Y;
			}
		}
		break;
	case 'S':
	case 's':
		if (rgn1.PtInRegion(m_X, m_Y)) {
			m_Y += 15;
		}
		if (!rgn1.PtInRegion(m_X, m_Y)) {
			m_Y -= 15;
		}
		if (countt >= 0) {
			if (d % 3 == 2) {
				m_X4 = m_X;
				m_Y4 = m_Y;
			}
		}
		break;

		//CDialogEx::OnKeyUp(nChar, nRepCnt, nFlags);

	}
	rgn1.DeleteObject();
	Invalidate(FALSE);
}


int CPowDlg::random() {
	srand((size_t)time(NULL));
	int num1;
	for (int i = 0; i <= 10; i++) {
		num1 = rand() % 1000;
	}

	return num1;


}

int scorenum = 100; // 게임 점수
int birdtime = 18; // 새 왓다 갓다 하는 시간 
int keeptime = 5;
void CPowDlg::OnTimer(UINT_PTR nIDEvent) // 윤지 수정
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	int count2 = 0;
	//CClientDC dc(this);
	switch (nIDEvent) {
	case 0:
		if (count == 0) {
			count += 1;
			location += 10;
			CClientDC dc(this);
			dc.Ellipse(num - 20, location - 20, num + 20, location + 20);

		}
		else {
			CPoint p;
			p.x = num;
			p.y = location;

			CRect rgnn(m_X - 60, m_Y - 20, m_X + 60, m_Y + 20);
			int stop = 0;
			if (rgnn.PtInRect(p)) {
				//영역 맞으면
				if (dontcare) {
					stop++;
					if (stop == 1) {
						m_X5 = 150;
						m_Y5 = 10;
					}
					else if (stop == 2) {
						m_X6 = 80;
						m_Y6 = 10;
					}
					else if (stop == 3) {
						m_X7 = 10;
						m_Y7 = 10;
						KillTimer(0);
					}
				}


			}
			count = 0;
			CRgn rgn2;
			rgn2.CreateEllipticRgn(num - 22, location - 22, num + 22, location + 22);// 원 생기는거
			rgn.CreateEllipticRgn(num - 20, location - 20, num + 20, location + 20);// 원 없어지는거
			CClientDC dc(this);
			InvalidateRgn(&rgn2, FALSE);
			rgn.DeleteObject();
		}
		break;
	case 1: // 보물상자
	{
		m_X3 += 15;
		if (m_Y3 <= 510)
			m_Y3 += 20;
		else
			m_Y3 -= 10;
		nIDEvent = 2;
	}
		break;
	case 2: // 보물상자 
			m_X3 = 0;
			m_Y3 = 500;
			nIDEvent = 1;
		break;
	case 3: //갈매기 실행되는 시간  
		c++;
		UpdateData(TRUE);
		if (birdtime >= 0) {
			if (c % 3 == 2) {
				m_X2 = 140;
				m_Y2 = 80;
				Invalidate(FALSE);
				UpdateData(FALSE);

			}
			if (c % 3 == 1) {
				m_X2 = 570;
				m_Y2 = 100;
				Invalidate(FALSE);
				UpdateData(FALSE);
			}
			birdtime--;
			break;
		}
		else {
			//KillTimer(3);
			m_X2 = 0;
			m_Y2 = 10000;
		}
		UpdateData(FALSE);
		break;
	case 4:
		d++;
		UpdateData(TRUE);

		if (countt >= 0) {
			if (d % 3 == 2) {
				m_X4 = m_X;
				m_Y4 = m_Y;
				Invalidate(FALSE);
				UpdateData(FALSE);

			}
			if (d % 3 == 1) {
				m_X4 = 0;
				m_Y4 = 10000;
				Invalidate(FALSE);
				UpdateData(FALSE);
			}
			countt--;
			break;
		}
		else {
			KillTimer(3);
			m_X4 = 0;
			m_Y4 = 10000;
		}
		UpdateData(FALSE);
		break;

	case 5:
		//UpdateData(TRUE);
		//UpdateData(FALSE);
		if (gametime >= 0) {
			CClientDC dc(this);
			CString gametime2;
			gametime2.Format(_T("게임 시간 : %d"), gametime);
			dc.TextOut(500, 10, gametime2);
			gametime--;
		}
		if (gametime <= 55) { // 갈매기 시간 40초일떄 구현 되게끔 
			SetTimer(3, 200, NULL);
		}
		if (gametime == 0) {
			CClientDC dc(this);
			CString end;
			end.Format(_T("Time Over!"));
			dc.TextOut(250, 100, end);
			//CPopup PopupDialog;
			CString str;
			str.Format(_T("%d"), scorenum);
			//PopupDialog.gamescore = str;
			//PopupDialog.DoModal();

		}
		UpdateData(FALSE);
		break;
	case 6: // 일정시간 후에 섬 크기 다시 원래대로 돌아오는거 
		UpdateData(TRUE);

		if (keeptime >= 0) {
			keeptime--;
			break;
		}
		else {
			six = 0;
			siy = 10000;
			ix = 0;
			iy = 10000;
			m_x8 = 240;
			m_y8 = 100;
			turn(); // 경계 되돌리기
			Invalidate(FALSE);
			UpdateData(FALSE);
			KillTimer(6);
		}
		UpdateData(FALSE);
		break;
	case 9:
		if (timercheck == 300) {

			SetTimer(18, 50, NULL);
			SetTimer(19, 50, NULL);
			SetTimer(22, 50, NULL);
			SetTimer(23, 50, NULL);

		}
		timercheck++;
		break;
	case 10: // 위쪽 오른쪽

		if (!m_pWorkerThread1) {
			m_pWorkerThread1 = AfxBeginThread(ThreadWorker1, this);
		}
		break;
	case 11: // 위쪽 왼쪽

		if (!m_pWorkerThread2) {
			m_pWorkerThread2 = AfxBeginThread(ThreadWorker2, this);
		}
		break;
	case 12:  //오른쪽 벽 위
		if (!m_pWorkerThread3) {
			m_pWorkerThread3 = AfxBeginThread(ThreadWorker3, this);
		}
		break;
	case 13:  //오른쪽 벽 밑
		if (!m_pWorkerThread4) {
			m_pWorkerThread4 = AfxBeginThread(ThreadWorker4, this);
		}
		break;
	case 14:  //오른쪽 밑
		if (!m_pWorkerThread5) {
			m_pWorkerThread5 = AfxBeginThread(ThreadWorker5, this);
		}
		break;
	case 15:  //왼쪽 밑
		if (!m_pWorkerThread6) {
			m_pWorkerThread6 = AfxBeginThread(ThreadWorker6, this);
		}
		break;
	case 16:  //왼쪽 벽 밑
		if (!m_pWorkerThread7) {
			m_pWorkerThread7 = AfxBeginThread(ThreadWorker7, this);
		}
		break;
	case 17:  //왼쪽 벽 위
		if (!m_pWorkerThread8) {
			m_pWorkerThread8 = AfxBeginThread(ThreadWorker8, this);
		}
		break;
	case 18:
		if (!m_pWorkerThread9) {
			m_pWorkerThread9 = AfxBeginThread(ThreadWorker9, this);
		}
		break;
	case 19:
		if (!m_pWorkerThread10) {
			m_pWorkerThread10 = AfxBeginThread(ThreadWorker10, this);
		}
		break;

		/*case 20:
			if (!m_pWorkerThread11) {
				m_pWorkerThread11 = AfxBeginThread(ThreadWorker11, this);
			}
			break;
		case 21:
			if (!m_pWorkerThread12) {
				m_pWorkerThread12 = AfxBeginThread(ThreadWorker12, this);
			}
			break;*/
	case 22:
		if (!m_pWorkerThread13) {
			m_pWorkerThread13 = AfxBeginThread(ThreadWorker13, this);
		}
		break;
	case 23:
		if (!m_pWorkerThread14) {
			m_pWorkerThread14 = AfxBeginThread(ThreadWorker14, this);
		}

	}
	CDialog::OnTimer(nIDEvent);
}



void CPowDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CPoint p2 = point;
	CRect rgnn2(m_X2 - 70, m_Y2 - 70, m_X2 + 70, m_Y2 + 70);
	CClientDC dc(this);
	CString str;
	str.Format(_T("수직은 %d 수평은 %d 입니다."), point.x, point.y);
	dc.TextOutW(10, 10, str);
	if (rgnn2.PtInRect(p2)) {
		//게임 유저가 갈매기를 클릭하면 무적상태 구현 
		dontcare = 1; // 점수 안까지게
		SetTimer(4, 1, NULL); // 무적상태 시간 수정
		KillTimer(3);
		dontcare = 0; // 원상복구
		m_X2 = 0;
		m_Y2 = 10000;

	}

	CRect rt(m_X3, m_Y3, m_X3 + 68, m_Y3 + 60); // 보물상자 영역
	if (rt.PtInRect(point)) {
		m_X3 = 1000;
		m_Y3 = 500;
		KillTimer(2);
		//SetTimer(1, 100, NULL); // 상자가 위아래로 움직이는 속도
		SetTimer(2, 25000, NULL); // 상자가 나타나있는 시간
		/*int singlenum;
		CardDialog card;
		card.DoModal();
		singlenum = card.num;*/
		int dualnum;
		DualDialog dual;
		dual.DoModal();
		dualnum = dual.num;
		if (dualnum == 3) { // 상대방 화면 가리기
			//SetTimer(3, 2000, NULL);
		}
	}
	CDialog::OnLButtonDown(nFlags, point);
}

void CPowDlg::score() {
	if (dontcare == 1) {

	}
	else {
		scorenum--;
	}
	CClientDC dc(this);
	//UpdateData(FALSE);
	//Invalidate(FALSE);
	CString game;
	game.Format(_T("점수 : %d"), scorenum);
	dc.TextOut(400, 10, game);
	//UpdateData(FALSE);
	Invalidate(FALSE);
}


int stop = 0; // 목숨 개수 
void CPowDlg::life() {
	if (dontcare) {

	}
	stop++;
	if (stop == 1) { // 장애물 한번 맞았을때
		m_X5 = 150;
		m_Y5 = 10;
	}
	if (stop == 2) {
		m_X6 = 80;
		m_Y6 = 10;
	}
	if (stop == 3) {
		m_X7 = 10;
		m_Y7 = 10;
	}
	if (stop == 4) {
		// 모든 쓰레드 멈춤 
		EXIT();
	}
}


void CPowDlg::EXIT() {
	/*m_pWorkerThread1 = NULL;
	KillTimer(10);
	//m_pWorkerThread1->SuspendThread();


	m_pWorkerThread2 = NULL;
	KillTimer(11);
	//m_pWorkerThread2->SuspendThread();


	m_pWorkerThread3 = NULL;
	//m_pWorkerThread3->SuspendThread();
	KillTimer(12);

	m_pWorkerThread4 = NULL;
	KillTimer(13);
	//m_pWorkerThread4->SuspendThread();


	/*m_pWorkerThread5 = NULL;
	KillTimer(14);
	//m_pWorkerThread5->SuspendThread();


	m_pWorkerThread6 = NULL;
	KillTimer(15);
		//m_pWorkerThread6->SuspendThread();


	m_pWorkerThread7 = NULL;
	KillTimer(16);
		//m_pWorkerThread7->SuspendThread();


	m_pWorkerThread8 = NULL;
	KillTimer(17);
		//m_pWorkerThread8->SuspendThread();


	m_pWorkerThread9 = NULL;
	KillTimer(18);
		//m_pWorkerThread9->SuspendThread();


	m_pWorkerThread10 = NULL;
	KillTimer(19);
	//m_pWorkerThread10->SuspendThread();


	m_pWorkerThread13 = NULL;
	KillTimer(22);
		//m_pWorkerThread13->SuspendThread();


	m_pWorkerThread14 = NULL;
	KillTimer(23);
	KillTimer(9);
	CClientDC dc(this);
	CString end;
	end.Format(_T("Time Over!"));
	dc.TextOut(250, 100, end);
	Invalidate(false);*/
	//m_pWorkerThread14->SuspendThread();

/*if (m_pWorkerThread1)
{
	HANDLE hThread1 = m_pWorkerThread1->m_hThread;
	WaitForSingleObject(hThread1, 0);
	m_pWorkerThread1 = NULL;
	m_pWorkerThread1->SuspendThread();
	KillTimer(10);
}
if (m_pWorkerThread2)
{
	HANDLE hThread2 = m_pWorkerThread2->m_hThread;
	WaitForSingleObject(hThread2, 0);
	m_pWorkerThread2 = NULL;
	m_pWorkerThread2->SuspendThread();
	KillTimer(11);
}
if (m_pWorkerThread3)
{
	HANDLE hThread3 = m_pWorkerThread3->m_hThread;
	WaitForSingleObject(hThread3, 0);
	m_pWorkerThread3 = NULL;
	m_pWorkerThread3->SuspendThread();
	KillTimer(12);
}
if (m_pWorkerThread4)
{
	HANDLE hThread4 = m_pWorkerThread4->m_hThread;
	WaitForSingleObject(hThread4, 0);
	m_pWorkerThread4 = NULL;
	m_pWorkerThread4->SuspendThread();
	KillTimer(13);
}
if (m_pWorkerThread5)
{
	HANDLE hThread5 = m_pWorkerThread5->m_hThread;
	WaitForSingleObject(hThread5, 0);
	m_pWorkerThread5 = NULL;
	m_pWorkerThread5->SuspendThread();
	KillTimer(14);
}
if (m_pWorkerThread6)
{
	HANDLE hThread6 = m_pWorkerThread6->m_hThread;
	WaitForSingleObject(hThread6, 0);
	m_pWorkerThread6 = NULL;
	m_pWorkerThread6->SuspendThread();
	KillTimer(15);
}
if (m_pWorkerThread7)
{
	HANDLE hThread7 = m_pWorkerThread7->m_hThread;
	WaitForSingleObject(hThread7, 0);
	m_pWorkerThread7 = NULL;
	m_pWorkerThread7->SuspendThread();
	KillTimer(16);
}
if (m_pWorkerThread8)
{
	HANDLE hThread8 = m_pWorkerThread8->m_hThread;
	WaitForSingleObject(hThread8, 0);
	m_pWorkerThread8 = NULL;
	m_pWorkerThread8->SuspendThread();
	KillTimer(17);
}
if (m_pWorkerThread9)
{
	HANDLE hThread9 = m_pWorkerThread9->m_hThread;
	WaitForSingleObject(hThread9, 0);
	m_pWorkerThread9 = NULL;
	m_pWorkerThread9->SuspendThread();
	KillTimer(18);
}
if (m_pWorkerThread10)
{
	HANDLE hThread10 = m_pWorkerThread10->m_hThread;
	WaitForSingleObject(hThread10, 0);
	m_pWorkerThread10 = NULL;
	m_pWorkerThread10->SuspendThread();
	KillTimer(19);
}
if (m_pWorkerThread13)
{
	HANDLE hThread13 = m_pWorkerThread13->m_hThread;
	WaitForSingleObject(hThread13, 0);
	m_pWorkerThread13 = NULL;
	m_pWorkerThread13->SuspendThread();
	KillTimer(22);
}
if (m_pWorkerThread14)
{
	HANDLE hThread14 = m_pWorkerThread14->m_hThread;
	WaitForSingleObject(hThread14, 0);
	m_pWorkerThread14 = NULL;
	m_pWorkerThread14->SuspendThread();
	KillTimer(23);
}*/
}
void CPowDlg::Paint(int num, int location, int select) {

	CClientDC dc(this);
	CBrush brush;
	if (select == 0) // 검정
	{

		brush.CreateSolidBrush(RGB(0, 0, 0));
	}
	else if (select == 1) { // 노랑

		brush.CreateSolidBrush(RGB(255, 212, 0));
	}
	else { // 흰색

		brush.CreateSolidBrush(RGB(255, 255, 255));
	}

	CBrush *oldBrush = dc.SelectObject(&brush);
	dc.Ellipse(num - 20, location - 20, num + 20, location + 20);
	dc.SelectObject(oldBrush);
	brush.DeleteObject();

}

void CPowDlg::eraser(CRgn &rgn, BOOL tf) {
	CClientDC dc(this);
	InvalidateRgn(&rgn, FALSE);
}
int CPowDlg::first_gap(int num, int i, int x, int m) {
	if (i == 0) {
		while (1) {
			num = random();
			if (num >= x && num <= m)
				break;
		}
	}
	else {
		while (1) {
			num = random();
			if (num <= x && num >= m)
				break;
		}
	}
	return num;
}

// 위에 exit함수 부터 고쳐야 됨 ctrl f 검색해서 하기

void CPowDlg::smallisland() {
	six = 190; // 섬 크기 변경 
	siy = 100;
	m_x8 = 0;
	m_y8 = 10000;
	is1 = 308;
	is2 = 206;
	is3 = 480;
	is4 = 340;

}
void CPowDlg::bigisland() {
	ix = 240; // 섬 크기 변경 
	iy = 100;
	m_x8 = 0;
	m_y8 = 10000;
	is1 = 267;
	is2 = 215;
	is3 = 532;
	is4 = 380;
}
void CPowDlg::turn() {
	int is1 = 260;
	int is2 = 110;
	int is3 = 480;
	int is4 = 270;
}
UINT CPowDlg::ThreadWorker1(LPVOID pParam) {
	// 위쪽 오른쪽
	static int s1 = 2;
	CPowDlg *pWnd = (CPowDlg*)pParam;

	if (pWnd->m_pWorkerThread1 != NULL) {
		Sleep(100);
		if (count1 == 0) {
			count1++;
			num1 -= 15;//20
			location1 += 15; //20
			pWnd->Paint(num1, location1, s1);

			pWnd->m_pWorkerThread1 = NULL;
		}
		else if (count1 == 1) {
			count1++;
			pWnd->m_pWorkerThread1 = NULL;
		}
		else if (count1 == 2) {
			CPoint p;
			p.x = num1;
			p.y = location1;
			rgn12.CreateEllipticRgn(num1 - 22, location1 - 22, num1 + 22, location1 + 22);// 원 생기는거
			rgn11.CreateEllipticRgn(num1 - 22, location1 - 22, num1 + 22, location1 + 22);// 원 없어지는거
			CRect rgnn(m_X - 60, m_Y - 20, m_X + 60, m_Y + 20);
			if (rgnn.PtInRect(p)) {
				pWnd->eraser(rgn12, FALSE);
				location1 = 689;
				if (s1 == 0) {// 검정일때 -> 섬 작아져야 됨 
					//영역 맞으면
					six = 190; // 섬 크기 변경 
					siy = 100;
					m_x8 = 0;
					m_y8 = 10000;
					pWnd->SetTimer(6, 1000, NULL);// 이것은 섬이 4초동안 유지되게 하는거
				}
				else if (s1 == 1) {// 흰색일때 -> 섬 커져야 됨 
					//영역 맞으면
					ix = 240; // 섬 크기 변경 
					iy = 100;
					m_x8 = 0;
					m_y8 = 10000;
					pWnd->SetTimer(6, 1000, NULL);// 이것은 섬이 4초동안 유지되게 하는거
				}
				else {
					//영역 맞으면
					pWnd->life();
					pWnd->score();
				}
			}
			count1++;

			//if (rgn.PtInRegion(point)) {


			pWnd->eraser(rgn12, FALSE);

			rgn11.DeleteObject();
			rgn12.DeleteObject();

			if (location1 > 688) {

				//KillTimer(1);
				num1 = pWnd->first_gap(num1, 0, 600, 800);
				location1 = 0;
				count1 = 0;
				s1 = pWnd->random() % 10;
				//pWnd->SetTimer(10, 100, NULL);

				//pWnd->m_pWorkerThread1->SuspendThread();
				pWnd->m_pWorkerThread1->ResumeThread();
				Sleep(100);

			}
			pWnd->m_pWorkerThread1 = NULL;

			//rgnn.DeleteObject();
		}
		else {
			count1 = 0;
			pWnd->m_pWorkerThread1 = NULL;
		}

	}

	return 0;
}



UINT CPowDlg::ThreadWorker2(LPVOID pParam) {
	// 위 왼쪽
	static int s2 = 2;

	CPowDlg *pWnd = (CPowDlg*)pParam;
	if (pWnd->m_pWorkerThread2 != NULL) {
		Sleep(100);
		if (count2 == 0) {
			count2++;
			num2 += 15; //20
			location2 += 15; //15
			pWnd->Paint(num2, location2, s2);

			pWnd->m_pWorkerThread2 = NULL;
		}
		else if (count2 == 1) {
			count2++;
			pWnd->m_pWorkerThread2 = NULL;
		}
		else if (count2 == 2) {
			CPoint p;
			p.x = num2;
			p.y = location2;
			rgn22.CreateEllipticRgn(num2 - 22, location2 - 22, num2 + 22, location2 + 22);// 원 생기는거
			rgn21.CreateEllipticRgn(num2 - 22, location2 - 22, num2 + 22, location2 + 22);// 원 없어지는거
			CRect rgnn(m_X - 60, m_Y - 20, m_X + 60, m_Y + 20);
			if (rgnn.PtInRect(p)) {
				pWnd->eraser(rgn22, FALSE);
				location2 = 689;
				if (s2 == 0) {// 검정일때 -> 섬 작아져야 됨 
					//영역 맞으면
					six = 190; // 섬 크기 변경 
					siy = 100;
					m_x8 = 0;
					m_y8 = 10000;
					pWnd->SetTimer(6, 1000, NULL);// 이것은 섬이 4초동안 유지되게 하는거
				}
				else if (s2 == 1) {// 흰색일때 -> 섬 커져야 됨 
					//영역 맞으면
					ix = 240; // 섬 크기 변경 
					iy = 100;
					m_x8 = 0;
					m_y8 = 10000;
					pWnd->SetTimer(6, 1000, NULL);// 이것은 섬이 4초동안 유지되게 하는거
				}
				else {
					//영역 맞으면
					pWnd->life();
					pWnd->score();
				}
			}
			count2++;

			pWnd->eraser(rgn22, FALSE);

			rgn21.DeleteObject();
			rgn22.DeleteObject();

			if (location2 > 688) {
				num2 = pWnd->first_gap(num2, 0, 100, 250);
				location2 = 0;
				count2 = 0;
				c2 = 0;
				s2 = pWnd->random() % 10;
				//pWnd->m_pWorkerThread2->SuspendThread();
				pWnd->m_pWorkerThread2->ResumeThread();
				Sleep(100);
				//pWnd->SetTimer(11, 50, NULL);
			}
			pWnd->m_pWorkerThread2 = NULL;
		}
		else {
			count2 = 0;
			pWnd->m_pWorkerThread2 = NULL;
		}

	}

	return 0;
}

UINT CPowDlg::ThreadWorker3(LPVOID pParam) {
	//오른쪽 벽 위
	static int s3 = 2;

	CPowDlg *pWnd = (CPowDlg*)pParam;

	if (pWnd->m_pWorkerThread3 != NULL) {
		Sleep(100);
		if (count3 == 0) {
			count3++;
			num3 -= 20; //20
			location3 += 10; //10
			pWnd->Paint(num3, location3, s3);

			pWnd->m_pWorkerThread3 = NULL;
		}
		else if (count3 == 1) {
			count3++;
			pWnd->m_pWorkerThread3 = NULL;
		}
		else if (count3 == 2) {
			CPoint p;
			p.x = num3;
			p.y = location3;
			rgn32.CreateEllipticRgn(num3 - 22, location3 - 22, num3 + 22, location3 + 22);// 원 생기는거
			rgn31.CreateEllipticRgn(num3 - 22, location3 - 22, num3 + 22, location3 + 22);// 원 없어지는거
			CRect rgnn(m_X - 60, m_Y - 20, m_X + 60, m_Y + 20);
			if (rgnn.PtInRect(p)) {
				pWnd->eraser(rgn32, FALSE);
				location3 = 689;
				if (s3 == 0) {// 검정일때 -> 섬 작아져야 됨 
					//영역 맞으면
					pWnd->smallisland();
					pWnd->SetTimer(6, 1000, NULL);// 이것은 섬이 4초동안 유지되게 하는거
				}
				else if (s3 == 1) {// 흰색일때 -> 섬 커져야 됨 
					//영역 맞으면
					ix = 240; // 섬 크기 변경 
					iy = 100;
					m_x8 = 0;
					m_y8 = 10000;
					pWnd->SetTimer(6, 1000, NULL);// 이것은 섬이 4초동안 유지되게 하는거
				}
				else {
					//영역 맞으면
					pWnd->life();
					pWnd->score();
				}
			}
			count3++;

			pWnd->eraser(rgn32, FALSE);

			rgn31.DeleteObject();
			rgn32.DeleteObject();

			if (location3 > 688) {
				location3 = pWnd->first_gap(location3, 0, 0, 100);
				num3 = 938;
				count3 = 0;
				s3 = pWnd->random() % 10;
				//pWnd->m_pWorkerThread3->SuspendThread();
				//pWnd->SetTimer(12, 50, NULL);
				pWnd->m_pWorkerThread3->ResumeThread();
				Sleep(100);
			}
			pWnd->m_pWorkerThread3 = NULL;
		}
		else {
			count3 = 0;
			pWnd->m_pWorkerThread3 = NULL;
		}
	}

	return 0;
}
UINT CPowDlg::ThreadWorker4(LPVOID pParam) {
	//오른쪽 벽 밑
	static int s4 = 2;

	CPowDlg *pWnd = (CPowDlg*)pParam;
	if (pWnd->m_pWorkerThread4 != NULL) {
		Sleep(100);
		if (count4 == 0) {
			count4++;
			num4 -= 20;//20
			location4 -= 15; //15
			pWnd->Paint(num4, location4, s4);

			pWnd->m_pWorkerThread4 = NULL;
		}
		else if (count4 == 1) {
			count4++;
			pWnd->m_pWorkerThread4 = NULL;

		}
		else if (count4 == 2) {
			CPoint p;
			p.x = num4;
			p.y = location4;
			rgn42.CreateEllipticRgn(num4 - 22, location4 - 22, num4 + 22, location4 + 22);// 원 생기는거
			rgn41.CreateEllipticRgn(num4 - 22, location4 - 22, num4 + 22, location4 + 22);// 원 없어지는거
			CRect rgnn(m_X - 60, m_Y - 20, m_X + 60, m_Y + 20);
			if (rgnn.PtInRect(p)) {
				pWnd->eraser(rgn42, FALSE);
				location4 = 1;
				if (s4 == 0) {// 검정일때 -> 섬 작아져야 됨 
					//영역 맞으면
					six = 190; // 섬 크기 변경 
					siy = 100;
					m_x8 = 0;
					m_y8 = 10000;
					pWnd->SetTimer(6, 1000, NULL);// 이것은 섬이 4초동안 유지되게 하는거
				}
				else if (s4 == 1) {// 흰색일때 -> 섬 커져야 됨 
					//영역 맞으면
					ix = 240; // 섬 크기 변경 
					iy = 100;
					m_x8 = 0;
					m_y8 = 10000;
					pWnd->SetTimer(6, 1000, NULL);// 이것은 섬이 4초동안 유지되게 하는거
				}
				else {
					//영역 맞으면
					pWnd->life();
					pWnd->score();
				}
			}
			count4++;

			pWnd->eraser(rgn42, FALSE);

			rgn41.DeleteObject();
			rgn42.DeleteObject();

			if (location4 >= 0 && location4 <= 15) {
				location4 = pWnd->first_gap(location4, 0, 550, 688);
				num4 = 938;
				count4 = 0;
				s4 = pWnd->random() % 10;
				//pWnd->m_pWorkerThread4->SuspendThread();
				//pWnd->SetTimer(13, 50, NULL);
				pWnd->m_pWorkerThread4->ResumeThread();
				Sleep(100);
			}
			pWnd->m_pWorkerThread4 = NULL;
		}
		else {
			count4 = 0;
			pWnd->m_pWorkerThread4 = NULL;
		}
	}

	return 0;
}
UINT CPowDlg::ThreadWorker5(LPVOID pParam) {
	// 밑 오른쪽
	static int s5 = 2;

	CPowDlg *pWnd = (CPowDlg*)pParam;
	if (pWnd->m_pWorkerThread5 != NULL) {
		Sleep(100);
		if (count5 == 0) {
			count5++;
			num5 -= 20; //20
			location5 -= 20; //20
			pWnd->Paint(num5, location5, s5);

			pWnd->m_pWorkerThread5 = NULL;
		}
		else if (count5 == 1) {
			count5++;
			pWnd->m_pWorkerThread5 = NULL;
		}
		else if (count5 == 2) {
			CPoint p;
			p.x = num5;
			p.y = location5;
			rgn52.CreateEllipticRgn(num5 - 22, location5 - 22, num5 + 22, location5 + 22);// 원 생기는거
			rgn51.CreateEllipticRgn(num5 - 22, location5 - 22, num5 + 22, location5 + 22);// 원 없어지는거
			CRect rgnn(m_X - 60, m_Y - 20, m_X + 60, m_Y + 20);
			if (rgnn.PtInRect(p)) {
				pWnd->eraser(rgn52, FALSE);
				location5 = 1;
				if (s5 == 0) {// 검정일때 -> 섬 작아져야 됨 
					//영역 맞으면
					six = 190; // 섬 크기 변경 
					siy = 100;
					m_x8 = 0;
					m_y8 = 10000;
					pWnd->SetTimer(6, 1000, NULL);// 이것은 섬이 4초동안 유지되게 하는거
				}
				else if (s5 == 1) {// 흰색일때 -> 섬 커져야 됨 
					//영역 맞으면
					ix = 240; // 섬 크기 변경 
					iy = 100;
					m_x8 = 0;
					m_y8 = 10000;
					pWnd->SetTimer(6, 1000, NULL);// 이것은 섬이 4초동안 유지되게 하는거
				}
				else {
					//영역 맞으면
					pWnd->life();
					pWnd->score();
				}
			}
			count5++;

			pWnd->eraser(rgn52, FALSE);

			rgn51.DeleteObject();
			rgn52.DeleteObject();

			if (location5 >= 0 && location5 <= 10) {
				num5 = pWnd->first_gap(num5, 0, 700, 800);
				location5 = 688;
				count5 = 0;
				s5 = pWnd->random() % 10;
				//pWnd->m_pWorkerThread5->SuspendThread();
				//pWnd->SetTimer(14, 50, NULL);
				pWnd->m_pWorkerThread5->ResumeThread();
			}
			pWnd->m_pWorkerThread5 = NULL;
		}
		else {
			count5 = 0;
			pWnd->m_pWorkerThread5 = NULL;
		}

	}

	return 0;
}

UINT CPowDlg::ThreadWorker6(LPVOID pParam) {
	// 밑 왼쪽
	static int s6 = 2;

	CPowDlg *pWnd = (CPowDlg*)pParam;
	if (pWnd->m_pWorkerThread6 != NULL) {
		Sleep(100);
		if (count6 == 0) {
			count6++;
			/*num6 += 15;
			location6 -= 20;*/
			num6 += 10; //15
			location6 -= 20; // 20
			pWnd->Paint(num6, location6, s6);

			pWnd->m_pWorkerThread6 = NULL;
		}
		else if (count6 == 1) {
			count6++;
			pWnd->m_pWorkerThread6 = NULL;
		}
		else if (count6 == 2) {
			CPoint p;
			p.x = num6;
			p.y = location6;
			rgn62.CreateEllipticRgn(num6 - 22, location6 - 22, num6 + 22, location6 + 22);// 원 생기는거
			rgn61.CreateEllipticRgn(num6 - 22, location6 - 22, num6 + 22, location6 + 22);// 원 없어지는거
			CRect rgnn(m_X - 60, m_Y - 20, m_X + 60, m_Y + 20);
			if (rgnn.PtInRect(p)) {
				pWnd->eraser(rgn62, FALSE);
				location6 = 1;
				if (s6 == 0) {// 검정일때 -> 섬 작아져야 됨 
					//영역 맞으면
					six = 190; // 섬 크기 변경 
					siy = 100;
					m_x8 = 0;
					m_y8 = 10000;
					pWnd->SetTimer(6, 1000, NULL);// 이것은 섬이 4초동안 유지되게 하는거
				}
				else if (s6 == 1) {// 흰색일때 -> 섬 커져야 됨 
					//영역 맞으면
					ix = 240; // 섬 크기 변경 
					iy = 100;
					m_x8 = 0;
					m_y8 = 10000;
					pWnd->SetTimer(6, 1000, NULL);// 이것은 섬이 4초동안 유지되게 하는거
				}
				else {
					//영역 맞으면
					pWnd->life();
					pWnd->score();
				}
			}
			count6++;

			pWnd->eraser(rgn62, FALSE);

			rgn61.DeleteObject();
			rgn62.DeleteObject();

			if (location6 >= 0 && location6 <= 15) {
				num6 = pWnd->first_gap(num6, 0, 0, 200);
				location6 = 688;
				count6 = 0;
				s6 = pWnd->random() % 10;
				//pWnd->m_pWorkerThread6->SuspendThread();
				//pWnd->SetTimer(15, 50, NULL);
				pWnd->m_pWorkerThread6->ResumeThread();
			}
			pWnd->m_pWorkerThread6 = NULL;
		}
		else {
			count6 = 0;
			pWnd->m_pWorkerThread6 = NULL;
		}
	}

	return 0;
}

UINT CPowDlg::ThreadWorker7(LPVOID pParam) {
	//왼쪽 벽 밑
	static int s7 = 2;

	CPowDlg *pWnd = (CPowDlg*)pParam;

	if (pWnd->m_pWorkerThread7 != NULL) {
		Sleep(100);
		if (count7 == 0) {
			count7++;
			num7 += 15;
			location7 -= 15;
			pWnd->Paint(num7, location7, s7);

			pWnd->m_pWorkerThread7 = NULL;
		}
		else if (count7 == 1) {
			count7++;
			pWnd->m_pWorkerThread7 = NULL;
		}
		else if (count7 == 2) {
			CPoint p;
			p.x = num7;
			p.y = location7;
			rgn72.CreateEllipticRgn(num7 - 22, location7 - 22, num7 + 22, location7 + 22);// 원 생기는거
			rgn71.CreateEllipticRgn(num7 - 22, location7 - 22, num7 + 22, location7 + 22);// 원 없어지는거
			CRect rgnn(m_X - 60, m_Y - 20, m_X + 60, m_Y + 20);
			if (rgnn.PtInRect(p)) {
				pWnd->eraser(rgn72, FALSE);
				location7 = 1;
				if (s7 == 0) {// 검정일때 -> 섬 작아져야 됨 
					//영역 맞으면
					six = 190; // 섬 크기 변경 
					siy = 100;
					m_x8 = 0;
					m_y8 = 10000;
					pWnd->SetTimer(6, 1000, NULL);// 이것은 섬이 4초동안 유지되게 하는거
				}
				else if (s7 == 1) {// 흰색일때 -> 섬 커져야 됨 
					//영역 맞으면
					ix = 240; // 섬 크기 변경 
					iy = 100;
					m_x8 = 0;
					m_y8 = 10000;
					pWnd->SetTimer(6, 1000, NULL);// 이것은 섬이 4초동안 유지되게 하는거
				}
				else {
					//영역 맞으면
					pWnd->life();
					pWnd->score();
				}
			}
			count7++;

			pWnd->eraser(rgn72, FALSE);

			rgn71.DeleteObject();
			rgn72.DeleteObject();

			if (location7 >= 0 && location7 <= 15) {
				location7 = pWnd->first_gap(location7, 0, 550, 688);
				num7 = 0;
				count7 = 0;
				s7 = pWnd->random() % 10;
				//pWnd->m_pWorkerThread7->SuspendThread();
				//pWnd->SetTimer(16, 50, NULL);
				pWnd->m_pWorkerThread7->ResumeThread();
			}
			pWnd->m_pWorkerThread7 = NULL;
		}
		else {
			count7 = 0;
			pWnd->m_pWorkerThread7 = NULL;
		}


	}

	return 0;
}
UINT CPowDlg::ThreadWorker8(LPVOID pParam) {
	//왼쪽 벽 위
	static int s8 = 2;

	CPowDlg *pWnd = (CPowDlg*)pParam;
	if (pWnd->m_pWorkerThread8 != NULL) {
		Sleep(100);
		if (count8 == 0) {
			count8++;
			num8 += 20;
			location8 += 15;
			pWnd->Paint(num8, location8, s8);

			pWnd->m_pWorkerThread8 = NULL;
		}
		else if (count8 == 1) {
			count8++;
			pWnd->m_pWorkerThread8 = NULL;
		}
		else if (count8 == 2) {
			CPoint p;
			p.x = num8;
			p.y = location8;
			rgn82.CreateEllipticRgn(num8 - 22, location8 - 22, num8 + 22, location8 + 22);// 원 생기는거
			rgn81.CreateEllipticRgn(num8 - 22, location8 - 22, num8 + 22, location8 + 22);// 원 없어지는거
			CRect rgnn(m_X - 60, m_Y - 20, m_X + 60, m_Y + 20);
			if (rgnn.PtInRect(p)) {
				pWnd->eraser(rgn82, FALSE);
				location8 = 689;
				if (s8 == 0) {// 검정일때 -> 섬 작아져야 됨 
					//영역 맞으면
					six = 190; // 섬 크기 변경 
					siy = 100;
					m_x8 = 0;
					m_y8 = 10000;
					pWnd->SetTimer(6, 1000, NULL);// 이것은 섬이 4초동안 유지되게 하는거
				}
				else if (s8 == 1) {// 흰색일때 -> 섬 커져야 됨 
					//영역 맞으면
					ix = 240; // 섬 크기 변경 
					iy = 100;
					m_x8 = 0;
					m_y8 = 10000;
					pWnd->SetTimer(6, 1000, NULL);// 이것은 섬이 4초동안 유지되게 하는거
				}
				else {
					//영역 맞으면
					pWnd->life();
					pWnd->score();
				}
			}
			count8++;

			pWnd->eraser(rgn82, FALSE);

			rgn81.DeleteObject();
			rgn82.DeleteObject();

			if (location8 > 688) {
				location8 = pWnd->first_gap(location8, 0, 0, 150);
				num8 = 0;
				count8 = 0;
				s8 = pWnd->random() % 10;
				//pWnd->m_pWorkerThread8->SuspendThread();
				//pWnd->SetTimer(17, 50, NULL);
				pWnd->m_pWorkerThread8->ResumeThread();
			}
			pWnd->m_pWorkerThread8 = NULL;
		}
		else {
			count8 = 0;
			pWnd->m_pWorkerThread8 = NULL;
		}

	}

	return 0;
}
UINT CPowDlg::ThreadWorker9(LPVOID pParam) {
	// 위쪽 오른쪽
	static int s9 = 2;
	CPowDlg *pWnd = (CPowDlg*)pParam;

	if (pWnd->m_pWorkerThread9 != NULL) {
		Sleep(100);
		if (count9 == 0) {
			count9++;
			num9 -= 15;//20
			location9 += 15; //20
			pWnd->Paint(num9, location9, s9);

			pWnd->m_pWorkerThread9 = NULL;
		}
		else if (count9 == 1) {
			count9++;
			pWnd->m_pWorkerThread9 = NULL;
		}
		else if (count9 == 2) {
			CPoint p;
			p.x = num9;
			p.y = location9;
			rgn92.CreateEllipticRgn(num9 - 22, location9 - 22, num9 + 22, location9 + 22);// 원 생기는거
			rgn91.CreateEllipticRgn(num9 - 22, location9 - 22, num9 + 22, location9 + 22);// 원 없어지는거
			CRect rgnn(m_X - 60, m_Y - 20, m_X + 60, m_Y + 20);
			if (rgnn.PtInRect(p)) {
				pWnd->eraser(rgn92, FALSE);
				location9 = 689;
				if (s9 == 0) {// 검정일때 -> 섬 작아져야 됨 
					//영역 맞으면
					six = 190; // 섬 크기 변경 
					siy = 100;
					m_x8 = 0;
					m_y8 = 10000;
					pWnd->SetTimer(6, 1000, NULL);// 이것은 섬이 4초동안 유지되게 하는거
				}
				else if (s9 == 1) {// 흰색일때 -> 섬 커져야 됨 
					//영역 맞으면
					ix = 240; // 섬 크기 변경 
					iy = 100;
					m_x8 = 0;
					m_y8 = 10000;
					pWnd->SetTimer(6, 1000, NULL);// 이것은 섬이 4초동안 유지되게 하는거
				}
				else {
					//영역 맞으면
					pWnd->life();
					pWnd->score();
				}
			}
			count9++;

			//if (rgn.PtInRegion(point)) {


			pWnd->eraser(rgn92, FALSE);

			rgn91.DeleteObject();
			rgn92.DeleteObject();

			if (location9 > 688) {

				//KillTimer(1);
				num9 = pWnd->first_gap(num9, 0, 600, 800);
				location9 = 0;
				count9 = 0;
				s9 = pWnd->random() % 10;
				//pWnd->m_pWorkerThread9->SuspendThread();
				pWnd->m_pWorkerThread9->ResumeThread();
			}
			pWnd->m_pWorkerThread9 = NULL;
		}
		else {
			count9 = 0;
			pWnd->m_pWorkerThread9 = NULL;

		}

	}

	return 0;
}


UINT CPowDlg::ThreadWorker10(LPVOID pParam) {
	// 위 왼쪽
	static int s10 = 2;

	CPowDlg *pWnd = (CPowDlg*)pParam;
	if (pWnd->m_pWorkerThread10 != NULL) {
		Sleep(100);
		if (count10 == 0) {
			count10++;
			num10 += 15; //20
			location10 += 15; //15
			pWnd->Paint(num10, location10, s10);

			pWnd->m_pWorkerThread10 = NULL;
		}
		else if (count10 == 1) {
			count10++;
			pWnd->m_pWorkerThread10 = NULL;
		}
		else if (count10 == 2) {
			CPoint p;
			p.x = num10;
			p.y = location10;
			rgn102.CreateEllipticRgn(num10 - 22, location10 - 22, num10 + 22, location10 + 22);// 원 생기는거
			rgn101.CreateEllipticRgn(num10 - 22, location10 - 22, num10 + 22, location10 + 22);// 원 없어지는거
			CRect rgnn(m_X - 60, m_Y - 20, m_X + 60, m_Y + 20);
			if (rgnn.PtInRect(p)) {
				pWnd->eraser(rgn102, FALSE);
				location10 = 689;
				if (s10 == 0) {// 검정일때 -> 섬 작아져야 됨 
					//영역 맞으면
					six = 190; // 섬 크기 변경 
					siy = 100;
					m_x8 = 0;
					m_y8 = 10000;
					pWnd->SetTimer(6, 1000, NULL);// 이것은 섬이 4초동안 유지되게 하는거
				}
				else if (s10 == 1) {// 흰색일때 -> 섬 커져야 됨 
					//영역 맞으면
					ix = 240; // 섬 크기 변경 
					iy = 100;
					m_x8 = 0;
					m_y8 = 10000;
					pWnd->SetTimer(6, 1000, NULL);// 이것은 섬이 4초동안 유지되게 하는거
				}
				else {
					//영역 맞으면
					pWnd->life();
					pWnd->score();
				}
			}
			count10++;

			pWnd->eraser(rgn102, FALSE);

			rgn101.DeleteObject();
			rgn102.DeleteObject();

			if (location10 > 688) {
				num10 = pWnd->first_gap(num10, 0, 100, 250);
				location10 = 0;
				count10 = 0;
				s10 = pWnd->random() % 10;
				//pWnd->m_pWorkerThread10->SuspendThread();
				pWnd->m_pWorkerThread10->ResumeThread();
			}
			pWnd->m_pWorkerThread10 = NULL;
		}
		else {
			count10 = 0;
			pWnd->m_pWorkerThread10 = NULL;
		}


	}

	return 0;
}
/*UINT CprojectDlg::ThreadWorker11(LPVOID pParam) {
	//오른쪽 벽 위
	static int s11 = 2;

	CprojectDlg *pWnd = (CprojectDlg*)pParam;

	if (pWnd->m_pWorkerThread11 != NULL) {

		if (count11 == 0) {
			count11++;
			num11 -= 20; //20
			location11 += 10; //10
			pWnd->Paint(num11, location11, s11);

			pWnd->m_pWorkerThread11 = NULL;
		}
		else if (count11 == 1) {
			count11++;
			pWnd->m_pWorkerThread11 = NULL;
		}
		else if (count11 == 2) {
			count11++;
			rgn112.CreateEllipticRgn(num11 - 22, location11 - 22, num11 + 22, location11 + 22);// 원 생기는거
			rgn31.CreateEllipticRgn(num11 - 22, location11 - 22, num11 + 22, location11 + 22);// 원 없어지는거
			pWnd->eraser(rgn112, FALSE);

			rgn111.DeleteObject();
			rgn112.DeleteObject();

			if (location11 > 688) {
				location11 = pWnd->first_gap(location11, 0, 0, 100);
				num11 = 938;
				count11 = 0;
				s11 = pWnd->random() % 10;
			}
			pWnd->m_pWorkerThread11 = NULL;
		}
		else {
			count11 = 0;
			pWnd->m_pWorkerThread11 = NULL;
		}
	}

	return 0;
}
UINT CprojectDlg::ThreadWorker12(LPVOID pParam) {
	//오른쪽 벽 밑
	static int s12 = 2;

	CprojectDlg *pWnd = (CprojectDlg*)pParam;
	if (pWnd->m_pWorkerThread12 != NULL) {

		if (count12 == 0) {
			count12++;
			num12 -= 20;//20
			location12 -= 15; //15
			pWnd->Paint(num12, location12, s12);

			pWnd->m_pWorkerThread12 = NULL;
		}
		else if (count12 == 1) {
			count12++;
			pWnd->m_pWorkerThread12 = NULL;

		}
		else if (count12 == 2) {
			count12++;
			rgn122.CreateEllipticRgn(num12 - 22, location12 - 22, num12 + 22, location12 + 22);// 원 생기는거
			rgn121.CreateEllipticRgn(num12 - 22, location12 - 22, num12 + 22, location12 + 22);// 원 없어지는거
			pWnd->eraser(rgn122, FALSE);

			rgn121.DeleteObject();
			rgn122.DeleteObject();

			if (location12 >= 0 && location12 <= 15) {
				location12 = pWnd->first_gap(location12, 0, 550, 688);
				num12 = 938;
				count12 = 0;
				s12 = pWnd->random() % 10;
			}
			pWnd->m_pWorkerThread12 = NULL;
		}
		else {
			count12 = 0;
			pWnd->m_pWorkerThread12 = NULL;
		}
	}

	return 0;
}*/
UINT CPowDlg::ThreadWorker13(LPVOID pParam) {
	// 밑 오른쪽
	static int s13 = 2;

	CPowDlg *pWnd = (CPowDlg*)pParam;
	if (pWnd->m_pWorkerThread13 != NULL) {
		Sleep(100);
		if (count13 == 0) {
			count13++;
			num13 -= 20; //20
			location13 -= 20; //20
			pWnd->Paint(num13, location13, s13);

			pWnd->m_pWorkerThread13 = NULL;
		}
		else if (count13 == 1) {
			count13++;
			pWnd->m_pWorkerThread13 = NULL;
		}
		else if (count13 == 2) {
			CPoint p;
			p.x = num13;
			p.y = location13;
			rgn132.CreateEllipticRgn(num13 - 22, location13 - 22, num13 + 22, location13 + 22);// 원 생기는거
			rgn131.CreateEllipticRgn(num13 - 22, location13 - 22, num13 + 22, location13 + 22);// 원 없어지는거
			CRect rgnn(m_X - 60, m_Y - 20, m_X + 60, m_Y + 20);
			if (rgnn.PtInRect(p)) {
				pWnd->eraser(rgn132, FALSE);
				location13 = 1;
				if (s13 == 0) {// 검정일때 -> 섬 작아져야 됨 
					//영역 맞으면
					six = 190; // 섬 크기 변경 
					siy = 100;
					m_x8 = 0;
					m_y8 = 10000;
					pWnd->SetTimer(6, 1000, NULL);// 이것은 섬이 4초동안 유지되게 하는거
				}
				else if (s13 == 1) {// 흰색일때 -> 섬 커져야 됨 
					//영역 맞으면
					ix = 240; // 섬 크기 변경 
					iy = 100;
					m_x8 = 0;
					m_y8 = 10000;
					pWnd->SetTimer(6, 1000, NULL);// 이것은 섬이 4초동안 유지되게 하는거
				}
				else {
					//영역 맞으면
					pWnd->life();
					pWnd->score();
				}
			}
			count13++;

			pWnd->eraser(rgn132, FALSE);

			rgn131.DeleteObject();
			rgn132.DeleteObject();

			if (location13 >= 0 && location13 <= 10) {
				num13 = pWnd->first_gap(num13, 0, 700, 800);
				location13 = 688;
				count13 = 0;
				s13 = pWnd->random() % 10;
				//pWnd->m_pWorkerThread13->SuspendThread();
				pWnd->m_pWorkerThread13->ResumeThread();
			}
			pWnd->m_pWorkerThread13 = NULL;
		}
		else {
			count13 = 0;
			pWnd->m_pWorkerThread13 = NULL;
		}

	}

	return 0;
}

UINT CPowDlg::ThreadWorker14(LPVOID pParam) {
	// 밑 왼쪽
	static int s14 = 2;

	CPowDlg *pWnd = (CPowDlg*)pParam;
	if (pWnd->m_pWorkerThread14 != NULL) {
		Sleep(100);
		if (count14 == 0) {
			count14++;
			num14 += 10; //15
			location14 -= 20; // 20
			pWnd->Paint(num14, location14, s14);

			pWnd->m_pWorkerThread14 = NULL;
		}
		else if (count14 == 1) {
			count14++;
			pWnd->m_pWorkerThread14 = NULL;
		}
		else if (count14 == 2) {
			CPoint p;
			p.x = num14;
			p.y = location14;
			rgn142.CreateEllipticRgn(num14 - 22, location14 - 22, num14 + 22, location14 + 22);// 원 생기는거
			rgn141.CreateEllipticRgn(num14 - 22, location14 - 22, num14 + 22, location14 + 22);// 원 없어지는거
			CRect rgnn(m_X - 60, m_Y - 20, m_X + 60, m_Y + 20);
			if (rgnn.PtInRect(p)) {
				pWnd->eraser(rgn142, FALSE);
				location14 = 1;
				if (s14 == 0) {// 검정일때 -> 섬 작아져야 됨 
					//영역 맞으면
					six = 190; // 섬 크기 변경 
					siy = 100;
					m_x8 = 0;
					m_y8 = 10000;
					pWnd->SetTimer(6, 1000, NULL);// 이것은 섬이 4초동안 유지되게 하는거
				}
				else if (s14 == 1) {// 흰색일때 -> 섬 커져야 됨 
					//영역 맞으면
					ix = 240; // 섬 크기 변경 
					iy = 100;
					m_x8 = 0;
					m_y8 = 10000;
					pWnd->SetTimer(6, 1000, NULL);// 이것은 섬이 4초동안 유지되게 하는거
				}
				else {
					//영역 맞으면
					pWnd->life();
					pWnd->score();
				}
			}
			count14++;

			pWnd->eraser(rgn142, FALSE);

			rgn141.DeleteObject();
			rgn142.DeleteObject();

			if (location14 >= 0 && location14 <= 15) {
				num14 = pWnd->first_gap(num14, 0, 0, 200);
				location14 = 688;
				count14 = 0;
				s14 = pWnd->random() % 10;
				//pWnd->m_pWorkerThread14->SuspendThread();
				pWnd->m_pWorkerThread14->ResumeThread();
			}
			pWnd->m_pWorkerThread14 = NULL;
		}
		else {
			count14 = 0;
			pWnd->m_pWorkerThread14 = NULL;
		}
	}

	return 0;
}
/*UINT CprojectDlg::ThreadWorker15(LPVOID pParam) {
	//왼쪽 벽 밑
	static int s15 = 2;

	CprojectDlg *pWnd = (CprojectDlg*)pParam;

	if (pWnd->m_pWorkerThread15 != NULL) {

		if (count15 == 0) {
			count15++;
			num15 += 15;
			location15 -= 15;
			pWnd->Paint(num15, location15, s15);

			pWnd->m_pWorkerThread15 = NULL;
		}
		else if (count15 == 1) {
			count15++;
			pWnd->m_pWorkerThread15 = NULL;
		}
		else if (count15 == 2) {
			count15++;
			rgn152.CreateEllipticRgn(num15 - 22, location15 - 22, num15 + 22, location15 + 22);// 원 생기는거
			rgn151.CreateEllipticRgn(num15 - 22, location15 - 22, num15 + 22, location15 + 22);// 원 없어지는거
			pWnd->eraser(rgn152, FALSE);

			rgn151.DeleteObject();
			rgn152.DeleteObject();

			if (location15 >= 0 && location15 <= 15) {
				location15 = pWnd->first_gap(location15, 0, 550, 688);
				num15 = 0;
				count15 = 0;
				s15 = pWnd->random() % 10;
			}
			pWnd->m_pWorkerThread15 = NULL;
		}
		else {
			count15 = 0;
			pWnd->m_pWorkerThread15 = NULL;
		}


	}

	return 0;
}
UINT CprojectDlg::ThreadWorker16(LPVOID pParam) {
	//왼쪽 벽 위
	static int s16 = 2;

	CprojectDlg *pWnd = (CprojectDlg*)pParam;
	if (pWnd->m_pWorkerThread16 != NULL) {

		if (count16 == 0) {
			count16++;
			num16 += 20;
			location16 += 15;
			pWnd->Paint(num16, location16, s16);

			pWnd->m_pWorkerThread16 = NULL;
		}
		else if (count16 == 1) {
			count16++;
			pWnd->m_pWorkerThread16 = NULL;
		}
		else if (count16 == 2) {
			count16++;
			rgn162.CreateEllipticRgn(num16 - 22, location16 - 22, num16 + 22, location16 + 22);// 원 생기는거
			rgn161.CreateEllipticRgn(num16 - 22, location16 - 22, num16 + 22, location16 + 22);// 원 없어지는거
			pWnd->eraser(rgn162, FALSE);

			rgn161.DeleteObject();
			rgn162.DeleteObject();

			if (location16 > 688) {
				location16 = pWnd->first_gap(location16, 0, 0, 150);
				num16 = 0;
				count16 = 0;
				s16 = pWnd->random() % 10;
			}
			pWnd->m_pWorkerThread16 = NULL;
		}
		else {
			count16 = 0;
			pWnd->m_pWorkerThread16 = NULL;
		}

	}

	return 0;
}*/

