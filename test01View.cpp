
// test01View.cpp : implementation of the Ctest01View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "test01.h"
#endif

#include "test01Doc.h"
#include "test01View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctest01View

IMPLEMENT_DYNCREATE(Ctest01View, CView)

BEGIN_MESSAGE_MAP(Ctest01View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
    ON_WM_KEYDOWN()
END_MESSAGE_MAP()

// Ctest01View construction/destruction

Ctest01View::Ctest01View()
{
	// TODO: add construction code here
    board.createRandomScene();
}

Ctest01View::~Ctest01View()
{
}

BOOL Ctest01View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// Ctest01View drawing

void Ctest01View::OnDraw(CDC* pDC)
{
	Ctest01Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

    const NtTerisBoardData& data = board.getBoardData();

    unsigned int GRID = 5;

    pDC->Draw3dRect(0, 0, data.getWidth() * GRID, 
        data.getHeight() * GRID, 0x0000FF, 0x0000FF);

    for(unsigned int r = 0; r < data.getHeight(); ++ r)
    {
        for(unsigned int c = 0; c < data.getWidth(); ++c)
        {
            boardDataType dt = data.at(NtPoint(c, r));

            if (isBlockTeris(dt))
            {
                pDC->Draw3dRect(c*GRID, r*GRID, GRID, GRID, dt, dt);
            }
        }
    }
	// TODO: add draw code for native data here
}


// Ctest01View printing

BOOL Ctest01View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void Ctest01View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void Ctest01View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// Ctest01View diagnostics

#ifdef _DEBUG
void Ctest01View::AssertValid() const
{
	CView::AssertValid();
}

void Ctest01View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ctest01Doc* Ctest01View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ctest01Doc)));
	return (Ctest01Doc*)m_pDocument;
}
#endif //_DEBUG


void Ctest01View::OnKeyDown( UINT nChar, UINT nRepCnt, UINT nFlags )
{
    board.insertNewBody();

    InvalidateRect(NULL);
}
// Ctest01View message handlers
