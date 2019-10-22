#include "AsciiIO_t.h"

asciiIO_t::asciiIO_t(){}

asciiIO_t::asciiIO_t(const string& path, mode _mode)
:virtIO_t(path, _mode){}

asciiIO_t::~asciiIO_t()
{
	fClose();
}

void asciiIO_t::fOpen(const string& path, mode _mode)
{
	if (m_file != 0)
	{
		m_status = cant_open_file_e;
	}

	else
	{
		switch(_mode)
		{
			case r:
				open("r");
				break;

			case w:
				open("w");
				break;

			case rp:
				open("r+");
				break;

			case wp:
				open("w+");
				break;

			default: 
				m_status = bad_access_e;
				break;
		};
	}
}

void asciiIO_t::setPosition(unsigned int position)
{
	if (m_file != 0)
	{
		int retval = fseek(m_file, position, SEEK_SET);
		(retval > 0)?
		(m_status = bad_access_e):(m_status = ok_e);
	}
	else
	{
		m_status = bad_access_e;
	}
}

virtIO_t& asciiIO_t::operator>>(int& num)
{	
	int res = 0;
	if(m_file != 0)
	{
		string arg = "%d";
		m_fscanf(num, arg);
		if(res < 0)
		{
			throw res;
		}
	}
	return *this;

}

virtIO_t& asciiIO_t::operator<<(int num)
{
	return *this;
}


void asciiIO_t::open(const char* arg)
{
	m_file = fopen(m_path.c_str(), arg);
	if(m_file != 0)
	{
		m_status = ok_e;
	}
	else
	{
		m_status = cant_open_file_e;
		throw 0;
	}
}
