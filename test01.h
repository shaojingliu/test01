
// test01.h : main header file for the test01 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// Ctest01App:
// See test01.cpp for the implementation of this class
//

class Ctest01App : public CWinApp
{
public:
	Ctest01App();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Ctest01App theApp;
