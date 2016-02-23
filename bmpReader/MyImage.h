

class Image
{
protected:
	COLORREF* data;
	BITMAPINFO m_bmpInfo;
	bool is_my;
public:
	Image(unsigned width, unsigned height, COLORREF* _data);
	~Image();
	virtual void fill_background(COLORREF c);

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

	void flip_x();
	void flip_y();

	void invert_color(COLORREF par);

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
};