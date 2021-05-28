
// YYJSDDIView.cpp: CYYJSDDIView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "YYJSDDI.h"
#endif

#include "YYJSDDIDoc.h"
#include "YYJSDDIView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CYYJSDDIView

IMPLEMENT_DYNCREATE(CYYJSDDIView, CView)

BEGIN_MESSAGE_MAP(CYYJSDDIView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONUP()
//	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CYYJSDDIView 생성/소멸

CYYJSDDIView::CYYJSDDIView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.
	isNewDots = TRUE;
}

CYYJSDDIView::~CYYJSDDIView()
{
}

BOOL CYYJSDDIView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CYYJSDDIView 그리기

void CYYJSDDIView::OnDraw(CDC* pDC) // view가 doc클래스를 보기위한 작업
{
	CYYJSDDIDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	int liCount = pDoc->GetDotsCount(); // 점의 쌍점이 몇개 있는가
	if (liCount) {
		CDots *ptDots;
		for (int i = 0; i < liCount; i++) {
			ptDots = pDoc->GetDots(i);
			ptDots->Draw(pDC);
		}
	}
	isNewDots = TRUE;
}


// CYYJSDDIView 인쇄

BOOL CYYJSDDIView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CYYJSDDIView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CYYJSDDIView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CYYJSDDIView 진단

#ifdef _DEBUG
void CYYJSDDIView::AssertValid() const
{
	CView::AssertValid();
}

void CYYJSDDIView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CYYJSDDIDoc* CYYJSDDIView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CYYJSDDIDoc)));
	return (CYYJSDDIDoc*)m_pDocument;
}
#endif //_DEBUG


// CYYJSDDIView 메시지 처리기


void CYYJSDDIView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

		ptF = point;
		CClientDC dc(this);
		CDots *pDots = GetDocument()->AddDots(ptF); // view가 doc보려고 하는 작업
		pDots->Draw(&dc);
		
	
	CView::OnLButtonUp(nFlags, point);
}



