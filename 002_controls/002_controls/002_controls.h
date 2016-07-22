
// 002_controls.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMy002_controlsApp:
// See 002_controls.cpp for the implementation of this class
//

class CMy002_controlsApp : public CWinApp
{
public:
	CMy002_controlsApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CMy002_controlsApp theApp;