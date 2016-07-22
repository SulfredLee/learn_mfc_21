
// 011_MDI.h : main header file for the 011_MDI application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMy011_MDIApp:
// See 011_MDI.cpp for the implementation of this class
//

class CMy011_MDIApp : public CWinAppEx
{
public:
	CMy011_MDIApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy011_MDIApp theApp;
