
// MyKey.h : главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CMyKeyApp:
// О реализации данного класса см. MyKey.cpp
//

class CMyKeyApp : public CWinApp
{
public:
	CMyKeyApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CMyKeyApp theApp;