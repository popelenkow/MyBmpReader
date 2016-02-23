#ifndef ___LIB_BITMAP_H___
#define ___LIB_BITMAP_H___

#include <cstdint>
#include <string>

enum Err
{
	ok = 0,
	open = 1,
	header = 2,
	mode = 3,
	memory = 4,
	write = 5
};

LPCTSTR Get_err_str(Err err);


class Bitmap
{
public:
	uint8_t * m_buffer;
	size_t    m_width, m_height;

public:
	Bitmap(void) : m_buffer(nullptr), m_width(0), m_height(0)
	{}
	virtual ~Bitmap(void)
	{
		clear();
	}

public:
	Err load(const char * file_name);
	inline Err load(const std::string & file_name)
	{
		return load(file_name.c_str());
	}
	Err save(const char * file_name) const;
	inline Err save(const std::string & file_name) const
	{
		return save(file_name.c_str());
	}

public:
	void clear(void)
	{
		m_width = m_height = 0;
		delete[] m_buffer;
		m_buffer = nullptr;
	}

private:
	Bitmap(const Bitmap &);
	Bitmap & operator = (const Bitmap &);
};

#endif // ___LIB_BITMAP_H___