
// MFC_3_.h : главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CMFC_3_App:
// О реализации данного класса см. MFC_3_.cpp
//

class CMFC_3_App : public CWinApp
{
public:
	CMFC_3_App();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация



	DECLARE_MESSAGE_MAP()
};

extern CMFC_3_App theApp;