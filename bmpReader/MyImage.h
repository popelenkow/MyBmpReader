class Image
{
protected:
	COLORREF* data;
	BITMAPINFO m_bmpInfo;
	bool is_my;
public:
	Image(unsigned width, unsigned height, COLORREF* _data = nullptr)
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
	~Image()
	{
		if (is_my) delete[] data;
	}
	virtual void fill_background(COLORREF c)
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

	COLORREF* get_data()
	{
		return data;
	}
	BITMAPINFO get_bmp_info()
	{
		return m_bmpInfo;
	}
	BITMAPINFOHEADER get_bmp_info_header()
	{
		return m_bmpInfo.bmiHeader;
	}
	void flip_x()
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
	void flip_y()
	{
		int w = m_bmpInfo.bmiHeader.biWidth;
		int h = m_bmpInfo.bmiHeader.biHeight;
		for (int y = 0; y < h / 2; y++)
		{
			for (int x = 0; x < w; x++)
			{
				COLORREF tmp = data[y*w + x];
				data[y*w + x] = data[(h - y - 1)*w + x];
				data[(h - y - 1)*w + x] = tmp;
			}
		}
		
	}
	void invert_color(COLORREF par)
	{
		int w = m_bmpInfo.bmiHeader.biWidth;
		int h = m_bmpInfo.bmiHeader.biHeight;
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
	void invert_red()
	{
		invert_color(0xFF0000);
	}
	void invert_green()
	{
		invert_color(0x00FF00);
	}
	void invert_blue()
	{
		invert_color(0x0000FF);
	}
	void rotate_counterclockwise()
	{
		int w = m_bmpInfo.bmiHeader.biWidth;
		int h = m_bmpInfo.bmiHeader.biHeight;
		for (int y = 0; y < (h+1) / 2; y++)
		{
			for (int x = 0; x < (w+1) / 2; x++)
			{
				COLORREF tmp = data[y*w + x];
				data[y*w + x] = data[y*w + (w - x - 1)];
				data[y*w + (w - x - 1)] = data[(h - y - 1)*w + (w - x - 1)];
				data[(h - y - 1)*w + (w - x - 1)] = data[(h - y - 1)*w + x];
				data[(h - y - 1)*w + x] = tmp;
			}
		}
	}
	void rotate_clockwise()
	{
		int w = m_bmpInfo.bmiHeader.biWidth;
		int h = m_bmpInfo.bmiHeader.biHeight;
		for (int y = 0; y < (h + 1) / 2; y++)
		{
			for (int x = 0; x < (w + 1) / 2; x++)
			{
				COLORREF tmp = data[y*w + x];
				data[y*w + x] = data[(h - y - 1)*w + x];
				data[(h - y - 1)*w + x] = data[(h - y - 1)*w + (w - x - 1)];
				data[(h - y - 1)*w + (w - x - 1)] = data[y*w + (w - x - 1)];
				data[y*w + (w - x - 1)] = tmp;
			}
		}
	}
};