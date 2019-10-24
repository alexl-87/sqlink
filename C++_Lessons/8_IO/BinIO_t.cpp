#include "BinIO_t.h"
#include <string>
using namespace std;
binIO_t::binIO_t()
{
	m_buffer = 0;
	m_read = false;
	m_write = false;
}

binIO_t::binIO_t(const string& path, const string& mode)
:virtIO_t(path, mode)
{
	m_buffer = 0;
	m_read = false;
	m_write = false;
}

binIO_t::~binIO_t(){}

binIO_t& binIO_t::operator>>(short& num){return Read(num, sizeof(short));}
binIO_t& binIO_t::operator<<(short num){return Write(num, sizeof(short));}

binIO_t& binIO_t::operator>>(int& num){return Read(num, sizeof(int));}
binIO_t& binIO_t::operator<<(int num){return Write(num, sizeof(int));}

binIO_t& binIO_t::operator>>(long& num){return Read(num, sizeof(long));}
binIO_t& binIO_t::operator<<(long num){return Write(num, sizeof(long));}

binIO_t& binIO_t::operator>>(char& num){return Read(num, sizeof(char));}
binIO_t& binIO_t::operator<<(char num){return Write(num, sizeof(char));}

binIO_t& binIO_t::operator>>(float& num){return Read(num, sizeof(float));}
binIO_t& binIO_t::operator<<(float num){return Write(num, sizeof(float));}

binIO_t& binIO_t::operator>>(double& num){return Read(num, sizeof(double));}
binIO_t& binIO_t::operator<<(double num){return Write(num, sizeof(double));}

binIO_t& binIO_t::operator>>(unsigned short& num){return Read(num, sizeof(unsigned short));}
binIO_t& binIO_t::operator<<(unsigned short num){return Write(num, sizeof(unsigned short));}

binIO_t& binIO_t::operator>>(unsigned int& num){return Read(num, sizeof(unsigned int));}
binIO_t& binIO_t::operator<<(unsigned int num){return Write(num, sizeof(unsigned int));}

binIO_t& binIO_t::operator>>(unsigned long& num){return Read(num, sizeof(unsigned long));}
binIO_t& binIO_t::operator<<(unsigned long num){return Write(num, sizeof(unsigned long));}

binIO_t& binIO_t::operator>>(unsigned char& num){return Read(num, sizeof(unsigned char));}
binIO_t& binIO_t::operator<<(unsigned char num){return Write(num, sizeof(unsigned char));}

binIO_t& binIO_t::operator>>(void* Buffer)
{
	m_read = true;
	m_buffer = Buffer;
	return *this;
}

binIO_t& binIO_t::operator<<(const void* Buffer)
{
	m_write = true;
	m_buffer = (void*)Buffer;
	return *this;
}

void binIO_t::operator,(unsigned int size)
{
	if (m_buffer != 0 && m_file != 0)
	{
		int retval = 0;
		if(m_write)
		{
			retval = fwrite(m_buffer, 1, size, m_file);
			fflush(m_file);
		}
		
		else if(m_read)
		{
			retval = fread(m_buffer, 1, size, m_file);
		}

		if(retval <= 0)
		{
			m_status = bad_access_e;

			throw tExeption_t<string,  string, int> 
			("*** fread()/fwrite() failed ***", __FILE__, __LINE__);	

		}
		else{m_status = ok_e;}
	}

	else
	{
		m_status = bad_access_e;
		throw tExeption_t<string,  string, int> 
		("*** m_file or buffer is NULL ***", __FILE__, __LINE__);
	}
}


