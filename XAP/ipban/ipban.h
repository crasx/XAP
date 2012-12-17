// ipban.h : main header file for the ipban DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CipbanApp
// See ipban.cpp for the implementation of this class
//

class CipbanApp : public CWinApp
{
public:
	CipbanApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
