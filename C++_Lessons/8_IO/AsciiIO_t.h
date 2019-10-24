#include "VirtIO_t.h"
#include <stdio.h>
#include <typeinfo>
#include "TExeption_t.h"

class asciiIO_t:public virtIO_t
{
public:
	asciiIO_t();
	asciiIO_t(const string& path, const string& mode);
	~asciiIO_t();

	virtual asciiIO_t& operator>>(short& num);
	virtual asciiIO_t& operator<<(short num);

	virtual asciiIO_t& operator>>(int& num);
	virtual asciiIO_t& operator<<(int num);

	virtual asciiIO_t& operator>>(long& num);
	virtual asciiIO_t& operator<<(long num);

	virtual asciiIO_t& operator>>(char& num);
	virtual asciiIO_t& operator<<(char num);

	virtual asciiIO_t& operator>>(float& num);
	virtual asciiIO_t& operator<<(float num);

	virtual asciiIO_t& operator>>(double& num);
	virtual asciiIO_t& operator<<(double num);

	virtual asciiIO_t& operator>>(unsigned short& num);
	virtual asciiIO_t& operator<<(unsigned short num);

	virtual asciiIO_t& operator>>(unsigned int& num);
	virtual asciiIO_t& operator<<(unsigned int num);

	virtual asciiIO_t& operator>>(unsigned long& num);
	virtual asciiIO_t& operator<<(unsigned long num);

	virtual asciiIO_t& operator>>(unsigned char& num);
	virtual asciiIO_t& operator<<(unsigned char num);

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
		m_status = virtIO_t::cant_open_file_e;;
		throw tExeption_t<string,  string, int> 
		("*** m_file is NULL ***", __FILE__, __LINE__);
	}
	else
	{
		int retval = fscanf(m_file, mode, &p);
		if(retval<=0)
		{
			m_status = virtIO_t::readErr_e;
			throw tExeption_t<string,  string, int> 
			("*** fscanf failed ***", __FILE__, __LINE__);
		}
		else
		{
			m_status = virtIO_t::ok_e;
			return *this;
		}
	}
}

template <class P> 
asciiIO_t& asciiIO_t::Write(P p, const char* mode)
{
	if (m_file == 0)
	{
		m_status = virtIO_t::cant_open_file_e;
		throw tExeption_t<string,  string, int> 
		("*** m_file is NULL ***", __FILE__, __LINE__);
	}
	else if(fprintf(m_file, mode, p) <= 0)
	{
		m_status = virtIO_t::readErr_e;
		throw tExeption_t<string,  string, int> 
		("*** fprintf failed ***", __FILE__, __LINE__);
	}
	else
	{
		m_status = virtIO_t::ok_e;
		return *this;
	}
}