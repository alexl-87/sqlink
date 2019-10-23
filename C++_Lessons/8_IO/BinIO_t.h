#include "VirtIO_t.h"
#include "TExeption_t.h"
#include <stdio.h>

class binIO_t:public virtIO_t
{
public:
	binIO_t();
	binIO_t(const string& path, const string& mode);
	~binIO_t();
	virtual binIO_t& operator>>(int& num);
	virtual binIO_t& operator<<(int num);

	binIO_t& operator>>(void* Buffer);
	binIO_t& operator<<(const void* Buffer);
	void operator,(unsigned int size);

private:
	binIO_t(const binIO_t& a);
	binIO_t& operator=(const binIO_t& a);

	template <class P> 
	binIO_t& Read(P& p, unsigned int size);

	template <class P> 
	binIO_t& Write(P p, unsigned int size);

	void* m_buffer;
	bool m_read;
	bool m_write;
};

template <class P> 
binIO_t& binIO_t::Read(P& p, unsigned int size)
{
	if (m_file == 0)
	{
		m_status = virtIO_t::cant_open_file_e;
		throw tExeption_t<string,  string, int> 
		("*** m_file is NULL ***", __FILE__, __LINE__);
	}

	int retval = fread((void*)&p, size, 1, m_file);
	if (retval != 1)
	{
		m_status = virtIO_t::readErr_e;
		throw tExeption_t<string,  string, int> 
		("*** fread failed ***", __FILE__, __LINE__);
	}
	m_status = ok_e;
	return *this;
}

template <class P> 
binIO_t& binIO_t::Write(P p, unsigned int size)
{
	if (m_file == 0)
	{
		m_status = virtIO_t::cant_open_file_e;
		throw tExeption_t<string,  string, int> 
		("*** m_file is NULL ***", __FILE__, __LINE__);
	}

	int retval = fwrite((void*)&p, size, 1, m_file);
	if (retval != 1)
	{
		m_status = virtIO_t::writeErr_e;
		throw tExeption_t<string,  string, int> 
		("*** fwrite failed ***", __FILE__, __LINE__);;
	}
	m_status = ok_e;
	return *this;
}