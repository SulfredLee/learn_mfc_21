
// 010_SDI.h : main header file for the 010_SDI application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMy010_SDIApp:
// See 010_SDI.cpp for the implementation of this class
//

class CMy010_SDIApp : public CWinAppEx
{
public:
	CMy010_SDIApp();


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy010_SDIApp theApp;
