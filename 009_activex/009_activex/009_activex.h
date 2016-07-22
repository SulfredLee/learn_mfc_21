
// 009_activex.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMy009_activexApp:
// See 009_activex.cpp for the implementation of this class
//

class CMy009_activexApp : public CWinApp
{
public:
	CMy009_activexApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CMy009_activexApp theApp;