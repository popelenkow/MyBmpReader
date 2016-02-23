#pragma once
#include "libbitmap.h"
#include "MyImage.h"

// CMyFrameWnd
class Point
{
public:
	int x;
	int y;
	Point(int _x = 0, int _y = 0) : x(_x), y(_y)
	{
	}
};
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
	Point pos;
	Point dimensions;
	Image *image = nullptr;
public:

	Point get_pos_image()
	{
		return pos;
	}
	void update_pos_image(Point p)
	{
		pos = p;
	}
	Point get_dimensions_image()
	{
		return dimensions;
	}
	void update_dimensions_image(Point d)
	{
		dimensions = d;
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
	Image* get_image()
	{
		return image;
	}
};


