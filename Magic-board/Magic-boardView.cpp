
// Magic-boardView.cpp: CMagicboardView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Magic-board.h"
#endif

#include "Magic-boardDoc.h"
#include "Magic-boardView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMagicboardView

IMPLEMENT_DYNCREATE(CMagicboardView, CView)

BEGIN_MESSAGE_MAP(CMagicboardView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_TIMER()
	ON_WM_CHAR()
END_MESSAGE_MAP()

// CMagicboardView 생성/소멸

CMagicboardView::CMagicboardView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMagicboardView::~CMagicboardView()
{
}

BOOL CMagicboardView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMagicboardView 그리기

void CMagicboardView::OnDraw(CDC* pDC)
{
	CMagicboardDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CBrush brush;
	CPen Pen;
	Pen.CreatePen(PS_NULL, 1, RGB(0, 0, 0));
	brush.CreateSolidBrush(m_PenColor);
	pDC->SelectObject(&brush);
	pDC->SelectObject(&Pen);
	pDC->Ellipse(m_pt.x-5, m_pt.y-5 , m_pt.x+5, m_pt.y+5 );


	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CMagicboardView 인쇄

BOOL CMagicboardView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMagicboardView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMagicboardView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CMagicboardView 진단

#ifdef _DEBUG
void CMagicboardView::AssertValid() const
{
	CView::AssertValid();
}

void CMagicboardView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMagicboardDoc* CMagicboardView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMagicboardDoc)));
	return (CMagicboardDoc*)m_pDocument;
}
#endif //_DEBUG


// CMagicboardView 메시지 처리기


void CMagicboardView::OnMouseMove(UINT nFlags, CPoint point)
{
	if (nFlags & MK_LBUTTON) {
		m_pt = point;
		Invalidate(FALSE);
	}
	
	CView::OnMouseMove(nFlags, point);
}



void CMagicboardView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	switch (nChar) {
	case 'q':
		m_PenColor = RGB(255, 0, 0);
		break;
	case 'w':
		m_PenColor = RGB(0, 255, 0);
		break;
	case 'e':
		m_PenColor = RGB(0, 0, 255);
		break;
	case 'r':
		m_PenColor = RGB(rand()%256, rand() % 256, rand() % 256);
		break;
	case 'a':
		m_PenColor = NULL_BRUSH;
		Invalidate();
		break;
	}

	CView::OnChar(nChar, nRepCnt, nFlags);
}
