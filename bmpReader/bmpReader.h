
// bmpReader.h : ������� ���� ��������� ��� ���������� PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"		// �������� �������


// CbmpReaderApp:
// � ���������� ������� ������ ��. bmpReader.cpp
//

class CbmpReaderApp : public CWinApp
{
public:
	CbmpReaderApp();

// ���������������
public:
	virtual BOOL InitInstance();

// ����������

	DECLARE_MESSAGE_MAP()
};

extern CbmpReaderApp theApp;