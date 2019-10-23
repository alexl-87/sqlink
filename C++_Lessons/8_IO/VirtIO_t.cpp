#include "VirtIO_t.h"

virtIO_t::~virtIO_t()
{
	Close();
}

virtIO_t::virtIO_t()
{
	m_status = ok_e;
	m_file = 0;
}

virtIO_t::virtIO_t(const string& path, const string& mode):m_path(path), m_mode(mode)
{
	m_status = ok_e;
	m_file = 0;
	Open(path, mode.c_str());
}

void virtIO_t::Close()
{
	if (m_file != 0)
	{
		fclose(m_file);
		m_file =0;
	}
}

void virtIO_t::Open(const string& path, const char* mode)
{
	Close();
	m_file = fopen(path.c_str(), mode);
	if (m_file != 0)
	{
		m_path = path;
		m_mode = mode;
		m_status = ok_e;
	}
	else
	{
		m_status = cant_open_file_e;
		throw tExeption_t<string,  string, int> 
		("Failed to open file", __FILE__, __LINE__);
	}
}	

void virtIO_t::setStatus(status _status)
{
	m_status = _status;
}

void virtIO_t::setPosition(unsigned int position)
{
	if(m_file != 0)
	{
		fseek(m_file, position, SEEK_SET);
		m_status = ok_e;
	}
	else
	{
		m_status = bad_access_e;
	}
}


int virtIO_t::getPosition()
{
	int retval = -1;
	m_status = cant_open_file_e;
	if (m_file != 0)
	{	
		retval = ftell(m_file);
		m_status = ok_e;
	}
	return retval;
}

const string& virtIO_t::getPath()const
{
	return m_path;
}

const string& virtIO_t::getMode()const
{
	return m_mode;
}

virtIO_t::status virtIO_t::getStatus()const
{
	return m_status;
}

int virtIO_t::getLen()
{
	int retval = -1;
	m_status = cant_open_file_e;
	if (m_file != 0)
	{	
		int temp = ftell(m_file);
		fseek(m_file, 0, SEEK_END);
		retval = ftell(m_file);
		fseek(m_file, temp, SEEK_SET);
		m_status = ok_e;
	}
	return retval;
}
