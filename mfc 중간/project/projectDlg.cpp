
// projectDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "project.h"
#include "projectDlg.h"
#include "afxdialogex.h"
#include <ctime>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
//#pragma comment(lib, "msimg32.lib")

//#include <d2d1.h>
//#pragma comment(lib, "D2D1.lib")
//using namespace D2D1;

// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CprojectDlg 대화 상자



CprojectDlg::CprojectDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PROJECT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	//  x = 0;
	//  y = 0;
	m_X = 0;
	m_Y = 0;
}

void CprojectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CprojectDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
//	ON_WM_KEYDOWN()
ON_WM_KEYUP()
ON_WM_TIMER()
END_MESSAGE_MAP()


// CprojectDlg 메시지 처리기

BOOL CprojectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	//m_img.Load(_T("Person.png"));
	 m_X = 350;
	 m_Y = 200;
	 num = random();
	SetTimer(0, 400, NULL);
	 
	 




	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CprojectDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.



void CprojectDlg::OnPaint()
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
		CDialogEx::OnPaint();

		CClientDC dc(this);
		CDC *CDC_Dlg;

		CDC MemDC;// 바다
		CDC memdc; // 섬
		CDC memDC; // 사람
		CDC heart_1;
		CDC heart_2;
		CDC heart_3;


		CBitmap bitmap;
		CBitmap bitmap2;
		CBitmap bitmap3;
		CBitmap heart1;
		CBitmap heart2;
		CBitmap heart3;

		CDC_Dlg = GetDC();

		
		bitmap.LoadBitmap(IDB_SEA);
		bitmap2.LoadBitmap(IDB_ISLAND);
		bitmap3.LoadBitmap(IDB_PERSON);
		heart1.LoadBitmap(IDB_HEART1);
		heart2.LoadBitmap(IDB_HEART2);
		heart3.LoadBitmap(IDB_HEART3);
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



		BitBlt(*CDC_Dlg, 0, 0, 2500, 3000, MemDC, 0, 0, SRCCOPY);// 배경
		BitBlt(*CDC_Dlg, 240, 100, 280, 300, memdc, 0, 0, SRCCOPY); //섬 
		BitBlt(*CDC_Dlg, m_X, m_Y, 93, 120, memDC, 0, 0, SRCAND);//사람
		BitBlt(*CDC_Dlg, 10, 10, 70, 80, heart_1, 0, 0, SRCCOPY);// 하트
		BitBlt(*CDC_Dlg, 80, 10, 70, 80, heart_2, 0, 0, SRCCOPY);// 하트
		BitBlt(*CDC_Dlg, 150, 10, 70, 80, heart_3, 0, 0, SRCCOPY);// 하트



		//TransparentBlt(*CDC_Dlg, 350, 200, 93, 120,
			//memDC, 0, 0, 93, 120, RGB(255, 255, 255));
		
		//m_img.Draw(dc, 0, 0);
		//srand((size_t)time(NULL));
		//int num = rand() % 1000;
		//dc.Ellipse(num - 50, 50, num + 50, -50);
		

	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CprojectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



//void CprojectDlg::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
//{
//	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
//	
//
//	CDialogEx::OnKeyDown(nChar, nRepCnt, nFlags);
//}


void CprojectDlg::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CDialogEx::OnKeyUp(nChar, nRepCnt, nFlags);

	switch (nChar) {
	case 'A':
	case 'a':
		m_X -= 10;
		break;
	case 'D':
	case 'd':
		m_X += 10;
		break;
	case 'W':
	case 'w':
		m_Y -= 10;
		break;
	case 'S':
	case 's':
		m_Y += 10;
		break;

	CDialogEx::OnKeyUp(nChar, nRepCnt, nFlags);


	}
	Invalidate(FALSE);
	//OnKeyDown();
	//UpdateData(TRUE);
	CDialogEx::OnKeyUp(nChar, nRepCnt, nFlags);
}





int CprojectDlg::random() {
	srand((size_t)time(NULL));
	int num = rand() % 500;
	return num;
}

void CprojectDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.


	switch (nIDEvent) {
	case 0:
		CClientDC dc(this);
		if (count == 0) {

			rgn.CreateEllipticRgn(num - 20, location - 20, num + 20, location + 20);
			point.x = num;
			point.y = location;
			gap = 20;
			dc.Ellipse(num - gap, location - gap, num + gap, location + gap);
			count++;
		}
		else {

			if (rgn.PtInRegion(point)) {
				gap = 0;
				dc.Ellipse(point.x - gap, point.y - gap, point.x + gap, point.y + gap);
				rgn.DeleteObject();
				location = location + 20;
				count--;
			}
			
		}
		
		break;

	}

	CDialogEx::OnTimer(nIDEvent);
}

