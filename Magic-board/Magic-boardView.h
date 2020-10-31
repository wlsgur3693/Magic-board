
// Magic-boardView.h: CMagicboardView 클래스의 인터페이스
//

#pragma once


class CMagicboardView : public CView
{
protected: // serialization에서만 만들어집니다.
	CMagicboardView() noexcept;
	DECLARE_DYNCREATE(CMagicboardView)

// 특성입니다.
public:
	CMagicboardDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CMagicboardView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	CPoint m_pt;
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	COLORREF m_PenColor;
};

#ifndef _DEBUG  // Magic-boardView.cpp의 디버그 버전
inline CMagicboardDoc* CMagicboardView::GetDocument() const
   { return reinterpret_cast<CMagicboardDoc*>(m_pDocument); }
#endif

