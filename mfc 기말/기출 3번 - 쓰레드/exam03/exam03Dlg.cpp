
// exam03Dlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "exam03.h"
#include "exam03Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


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


// Cexam03Dlg 대화 상자



Cexam03Dlg::Cexam03Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_EXAM03_DIALOG, pParent)
	, m_bWorkerPause1(FALSE)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cexam03Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_CHECK1, m_bWorkerPause1);
}

BEGIN_MESSAGE_MAP(Cexam03Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON2, &Cexam03Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &Cexam03Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_CHECK1, &Cexam03Dlg::OnBnClickedCheck1)
END_MESSAGE_MAP()


// Cexam03Dlg 메시지 처리기

BOOL Cexam03Dlg::OnInitDialog()
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

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void Cexam03Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void Cexam03Dlg::OnPaint()
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

		if (incr == TRUE) {
			for (int i = 1; i <= gap; i++) {
				line = 50 * i;
				dc.MoveTo(50, line);
				dc.LineTo(250, line);
		}

			
		}


	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR Cexam03Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

UINT Cexam03Dlg::ThreadWorker1(LPVOID pParam) {
	// 위쪽 오른쪽

	Cexam03Dlg *pWnd = (Cexam03Dlg*)pParam;
	BOOL tf = true;
		while (1) {
			pWnd->incr = TRUE;
			if (tf) {
				
				pWnd->Invalidate(TRUE);
				pWnd->gap++;
				
				Sleep(100);
				if (pWnd->gap == 10) {
					tf = false;
				}
			}
			else {
				pWnd->gap--;
				pWnd->Invalidate(TRUE);
				

				Sleep(100);
				if (pWnd->gap == 0) {
					tf = true;
				}
			}
		}


	return 0;
}


void Cexam03Dlg::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (!m_pWorkerThread1)
	{
		m_pWorkerThread1 = AfxBeginThread(ThreadWorker1, this);
	}
}


void Cexam03Dlg::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_pWorkerThread1) { 
	HANDLE hThread1 = m_pWorkerThread1->m_hThread;
	WaitForSingleObject(hThread1, 0);
	m_pWorkerThread1 = NULL; }
	OnOK();
}



void Cexam03Dlg::OnBnClickedCheck1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_bWorkerPause1 == FALSE) {
		m_bWorkerPause1 = TRUE;
		m_pWorkerThread1->SuspendThread();
	}
	else {
		m_bWorkerPause1 = FALSE;
		m_pWorkerThread1->ResumeThread();
	}
}
