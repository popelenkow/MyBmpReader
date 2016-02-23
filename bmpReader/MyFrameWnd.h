#pragma once
#include "libbitmap.h"
#include "MyImage.h"

// CMyFrameWnd

class CMyFrameWnd : public CWnd
{
	DECLARE_DYNAMIC(CMyFrameWnd)

public:
	CMyFrameWnd();
	virtual ~CMyFrameWnd();

protected:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnPaint();

private:
	int pos_x, pos_y;
	int m_height, m_width;
	Image *image = nullptr;
public:
	int get_height()
	{
		return m_height;
	}
	int get_width()
	{
		return m_width;
	}
	void update_image(const Bitmap& bmp)
	{
		clean_image();
		if (bmp.m_buffer != nullptr)
		{
			image = new Image(bmp.m_width, bmp.m_height, (COLORREF*)bmp.m_buffer);
		}
	}
	void clean_image()
	{
		if (image != nullptr)
		{
			delete image;
			image = nullptr;
		}
	}
	void pos_update(int x, int y)
	{
		pos_x = x;
		pos_y = y;
	}
	Image* get_image()
	{
		return image;
	}
};


