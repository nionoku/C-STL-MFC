
// MFC_8.h : главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CMFC_8App:
// О реализации данного класса см. MFC_8.cpp
//

class CMFC_8App : public CWinApp
{
public:
	CMFC_8App();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CMFC_8App theApp;