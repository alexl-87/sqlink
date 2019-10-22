#include "VirtIO_t.h"

virtIO_t::~virtIO_t()
{

}

virtIO_t::virtIO_t()
{
	m_status = def_e;
	m_access = def;
	m_fileLeght = 0;
	m_position = 0;
	string m_path = "";
	FILE* m_file = 0;
}

virtIO_t::virtIO_t(const string& path, enum access _access)
{
	try
	{

	}

	catch
	{
		
	}
}

void virtIO_t::fClose()
{

}

const string& virtIO_t::getPath()const
{

}

enum access virtIO_t::getAccess()const
{

}

enum status virtIO_t::getStatus()const
{

}

unsigned int virtIO_t::getPosition()const
{

}

void virtIO_t::setStatus(enum status _status)
{

}
