
// bmpReader.h : главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CbmpReaderApp:
// О реализации данного класса см. bmpReader.cpp
//

class CbmpReaderApp : public CWinApp
{
public:
	CbmpReaderApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CbmpReaderApp theApp;