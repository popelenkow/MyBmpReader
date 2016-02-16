// MyFrameWnd.cpp: файл реализации
//

#include "stdafx.h"
#include "bmpReader.h"
#include "MyFrameWnd.h"


// CMyFrameWnd

IMPLEMENT_DYNAMIC(CMyFrameWnd, CWnd)
BEGIN_MESSAGE_MAP(CMyFrameWnd, CWnd)
ON_WM_PAINT()
ON_WM_ERASEBKGND()
END_MESSAGE_MAP()

CMyFrameWnd::CMyFrameWnd()
{
	m_height = 300;
	m_width = 350;
	pos_x = 0;
	pos_y = 0;
}

CMyFrameWnd::~CMyFrameWnd()
{
	clean_image();
}


// обработчики сообщений CMyFrameWnd


void CMyFrameWnd::OnPaint()
{
	CPaintDC dc(this); // контекст устройства для рисования
	if (image != nullptr)
	{
		BITMAPINFO info = image->get_bmp_info();
		COLORREF* data = image->get_data();
		data += info.bmiHeader.biWidth*pos_y + pos_x;
		::SetDIBitsToDevice(dc, 0, 0, m_width, m_height, 0, 0, 0, m_width, data, &info, 0);
	}
	
}