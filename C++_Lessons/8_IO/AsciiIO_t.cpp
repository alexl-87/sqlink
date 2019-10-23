#include "AsciiIO_t.h"
#include <string>
using namespace std;
asciiIO_t::asciiIO_t(){}

asciiIO_t::asciiIO_t(const string& path, mode _mode)
:virtIO_t(path, _mode){}

asciiIO_t::~asciiIO_t()
{
	fClose();
}

void asciiIO_t::fOpen(const string& path, mode md)
{
	if (m_file != 0)
	{
		m_status = cant_open_file_e;
		throw -1;
	}
	
	switch(md)
	{
		case r:
		open(path, "r");
		m_mode = md;
		break;

		case w:
		open(path, "w");
		m_mode = md;
		break;

		case rp:
		open(path, "r+");
		m_mode = md;
		break;

		case wp:
		open(path, "w+");
		m_mode = md;
		break;

		default: break;

	}

}

void asciiIO_t::setPosition(unsigned int position)
{
	if (m_file != 0)
	{
		int retval = fseek(m_file, position, SEEK_SET);
		(retval != 0)?
		(m_status = bad_access_e):(m_status = ok_e);
	}
	else
	{
		m_status = bad_access_e;
	}
}

virtIO_t& asciiIO_t::operator>>(int& num)
{	
	m_IO(num, 1);
	return *this;

}

virtIO_t& asciiIO_t::operator<<(int& num)
{
	m_IO(num, 0);
	return *this;
}

void asciiIO_t::open(const string& path, const char* md)
{
	m_file = fopen(path.c_str(), md);
	if(m_file != 0)
	{
		m_status = ok_e;
		m_path = path;
	}
	else
	{
		m_status = cant_open_file_e;
		m_mode = def;
		m_path = "";
		throw 0;
	}
}