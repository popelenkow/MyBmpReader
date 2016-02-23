#include "stdafx.h"
#include "MyImage.h"

Image::Image(unsigned width, unsigned height, COLORREF* _data = nullptr)
{
	if (_data == nullptr)
	{
		data = new COLORREF[width*height];
		is_my = true;
	}
	else
	{
		data = _data;
		is_my = false;
	}
	ZeroMemory(&m_bmpInfo, sizeof(m_bmpInfo));
	m_bmpInfo.bmiHeader.biSize = sizeof(m_bmpInfo);
	m_bmpInfo.bmiHeader.biPlanes = 1;
	m_bmpInfo.bmiHeader.biWidth = width;
	m_bmpInfo.bmiHeader.biHeight = height;
	m_bmpInfo.bmiHeader.biBitCount = 32;
}
Image::~Image()
{
	if (is_my) delete[] data;
}
void Image::fill_background(COLORREF c)
{
	BYTE red = (BYTE)(c >> 24);
	BYTE green = (BYTE)(c >> 16);
	BYTE blue = (BYTE)(c >> 8);
	BYTE weignt = (BYTE)(c);
	int h = m_bmpInfo.bmiHeader.biHeight;
	int w = m_bmpInfo.bmiHeader.biWidth;
	for (int y = 0; y < h*w; y++)
	{
		*(data + y) = c;
	}
}

void Image::flip_x()
{
	int w = m_bmpInfo.bmiHeader.biWidth;
	int h = m_bmpInfo.bmiHeader.biHeight;
	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w / 2; x++)
		{
			COLORREF tmp = data[y*w + x];
			data[y*w + x] = data[y*w + (w - x - 1)];
			data[y*w + (w - x - 1)] = tmp;
		}
	}
}
void Image::flip_y()
{
	const int w = m_bmpInfo.bmiHeader.biWidth;
	const int h = m_bmpInfo.bmiHeader.biHeight;
	COLORREF* tmp = new COLORREF[w];
	for (int y = 0; y < h / 2; y++)
	{
		memcpy(tmp, data + y*w, 4 * w);
		memcpy(data + y*w, data + (h - y - 1)*w, 4 * w);
		memcpy(data + (h - y - 1)*w, tmp, 4 * w);
	}
	delete[] tmp;
}
void Image::invert_color(COLORREF par)
{
	const int w = m_bmpInfo.bmiHeader.biWidth;
	const int h = m_bmpInfo.bmiHeader.biHeight;
	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			COLORREF tmp = par;
			tmp &= data[y*w + x];
			tmp = ~tmp;
			tmp &= par;
			data[y*w + x] &= ~par;
			data[y*w + x] |= tmp;

		}
	}
}


