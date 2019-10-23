#include "VirtIO_t.h"

virtIO_t::~virtIO_t(){}

virtIO_t::virtIO_t()
{
	m_status = ok_e;
	m_mode = def;
	m_fileLeght = 0;
	string m_path = "";
	FILE* m_file = 0;
}

virtIO_t::virtIO_t(const string& path, mode _mode)
{
	m_status = ok_e;
	m_mode = _mode;
	m_fileLeght = 0;
	string m_path = path;
	FILE* m_file = 0;
}

void virtIO_t::fClose()
{
	if (m_file != 0)
	{
		fclose(m_file);
		m_file =0;
	}
}

const string& virtIO_t::getPath()const
{
	return m_path;
}

virtIO_t::mode virtIO_t::getMode()const
{
	return m_mode;
}

virtIO_t::status virtIO_t::getStatus()const
{
	return m_status;
}

int virtIO_t::getPosition()const
{

	return (m_file != 0)?
			ftell(m_file):-1;
}

void virtIO_t::setStatus(status _status)
{
	m_status = _status;
}
