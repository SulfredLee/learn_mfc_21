
// 005_dialog.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMy005_dialogApp:
// See 005_dialog.cpp for the implementation of this class
//

class CMy005_dialogApp : public CWinApp
{
public:
	CMy005_dialogApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CMy005_dialogApp theApp;