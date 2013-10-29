
// test01View.h : interface of the Ctest01View class
//

#pragma once
#include "NtTerisBoard.h"


class Ctest01View : public CView
{
protected: // create from serialization only
	Ctest01View();
	DECLARE_DYNCREATE(Ctest01View)

// Attributes
public:
	Ctest01Doc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
    afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
    afx_msg void OnTimer(UINT_PTR nIDEvent);
    afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
    afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
    afx_msg void OnMouseMove(UINT nFlags, CPoint point);

// Implementation
public:
	virtual ~Ctest01View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
    NtTerisBoard board;
    NtTerisBoard boardView;
    NtPoint touchPoint;
// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in test01View.cpp
inline Ctest01Doc* Ctest01View::GetDocument() const
   { return reinterpret_cast<Ctest01Doc*>(m_pDocument); }
#endif

