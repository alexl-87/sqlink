#include "VirtIO_t.h"
#include <stdio.h>
#include <typeinfo>

class asciiIO_t:public virtIO_t
{
public:
	asciiIO_t();
	asciiIO_t(const string& path, const string& mode);
	~asciiIO_t();
	virtual asciiIO_t& operator>>(int& num);
	virtual asciiIO_t& operator<<(int num);

private:
	asciiIO_t(const asciiIO_t& a);
	asciiIO_t& operator=(const asciiIO_t& a);

	template <class P> 
	asciiIO_t& Read(P& p, const char* mode);

	template <class P> 
	asciiIO_t& Write(P p, const char* mode);
};

template <class P> 
asciiIO_t& asciiIO_t::Read(P& p, const char* mode)
{
	if (m_file == 0)
	{
		m_status = virtIO_t::cant_open_file_e;
		throw -1;
	}
	else if(fscanf(m_file, mode, &p) <= 0)
	{
		m_status = virtIO_t::readErr_e;
		throw -1;
	}
	else
	{
		m_status = virtIO_t::ok_e;
		return *this;
	}
}

template <class P> 
asciiIO_t& asciiIO_t::Write(P p, const char* mode)
{
	if (m_file == 0)
	{
		m_status = virtIO_t::cant_open_file_e;
		throw -1;
	}
	else if(fprintf(m_file, mode, p) <= 0)
	{
		m_status = virtIO_t::readErr_e;
		throw -1;
	}
	else
	{
		m_status = virtIO_t::ok_e;
		return *this;
	}
}