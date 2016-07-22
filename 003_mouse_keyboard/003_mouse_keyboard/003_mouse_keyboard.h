
// 003_mouse_keyboard.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMy003_mouse_keyboardApp:
// See 003_mouse_keyboard.cpp for the implementation of this class
//

class CMy003_mouse_keyboardApp : public CWinApp
{
public:
	CMy003_mouse_keyboardApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CMy003_mouse_keyboardApp theApp;