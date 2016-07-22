
// 006_menus.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMy006_menusApp:
// See 006_menus.cpp for the implementation of this class
//

class CMy006_menusApp : public CWinApp
{
public:
	CMy006_menusApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CMy006_menusApp theApp;