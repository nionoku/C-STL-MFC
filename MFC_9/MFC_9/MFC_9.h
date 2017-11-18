
// MFC_9.h : главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CMFC_9App:
// О реализации данного класса см. MFC_9.cpp
//

class CMFC_9App : public CWinApp
{
public:
	CMFC_9App();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CMFC_9App theApp;