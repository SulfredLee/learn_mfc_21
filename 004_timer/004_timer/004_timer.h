
// 004_timer.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMy004_timerApp:
// See 004_timer.cpp for the implementation of this class
//

class CMy004_timerApp : public CWinApp
{
public:
	CMy004_timerApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CMy004_timerApp theApp;