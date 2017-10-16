
// MFC_2_.h : главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CMFC_2_App:
// О реализации данного класса см. MFC_2_.cpp
//

class CMFC_2_App : public CWinApp
{
public:
	CMFC_2_App();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CMFC_2_App theApp;