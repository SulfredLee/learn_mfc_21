
// 007_font_text.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMy007_font_textApp:
// See 007_font_text.cpp for the implementation of this class
//

class CMy007_font_textApp : public CWinApp
{
public:
	CMy007_font_textApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CMy007_font_textApp theApp;