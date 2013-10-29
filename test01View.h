
// test01View.h : interface of the Ctest01View class
//

#pragma once


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

// Implementation
public:
	virtual ~Ctest01View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in test01View.cpp
inline Ctest01Doc* Ctest01View::GetDocument() const
   { return reinterpret_cast<Ctest01Doc*>(m_pDocument); }
#endif

