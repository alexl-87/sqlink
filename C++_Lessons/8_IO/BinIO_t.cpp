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


binIO_t& binIO_t::operator>>(int& num){return Read(num, sizeof(int));}

binIO_t& binIO_t::operator<<(int num){return Write(num, sizeof(int));}

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
		}
		else if(m_read)
		{
			retval = fread(m_buffer, 1, size, m_file);
		}
		if(retval != size)
		{
			m_status = bad_access_e;
			throw -1;			
		}
		else{m_status = ok_e;}
	}
	else
	{
		m_status = bad_access_e;
		throw -1;
	}
}


