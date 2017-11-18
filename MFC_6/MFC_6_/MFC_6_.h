
// MFC_6_.h : главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CMFC_6_App:
// О реализации данного класса см. MFC_6_.cpp
//

class CMFC_6_App : public CWinApp
{
public:
	CMFC_6_App();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CMFC_6_App theApp;