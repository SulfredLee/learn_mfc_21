
// 008_graphic_drawing_bitmap.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMy008_graphic_drawing_bitmapApp:
// See 008_graphic_drawing_bitmap.cpp for the implementation of this class
//

class CMy008_graphic_drawing_bitmapApp : public CWinApp
{
public:
	CMy008_graphic_drawing_bitmapApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CMy008_graphic_drawing_bitmapApp theApp;