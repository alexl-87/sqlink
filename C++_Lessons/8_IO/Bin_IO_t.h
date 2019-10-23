#include "VirtIO_t.h"
#include <stdio.h>

class bin_IO_t:public virtIO_t
{
public:
	bin_IO_t();
	bin_IO_t(const string& path, const string& mode);
	~bin_IO_t();
	virtual bin_IO_t& operator>>(int& num);
	virtual bin_IO_t& operator<<(int num);

	bin_IO_t& operator>>(void* Buffer);
	bin_IO_t& operator<<(const void* Buffer);
	void operator,(unsigned int size);

private:
	bin_IO_t(const bin_IO_t& a);
	bin_IO_t& operator=(const bin_IO_t& a);

	template <class P> 
	bin_IO_t& Read(P& p, unsigned int size);

	template <class P> 
	bin_IO_t& Write(P p, unsigned int size);

	void* m_buffer;
	bool m_read;
	bool m_write;
};

template <class P> 
bin_IO_t& bin_IO_t::Read(P& p, unsigned int size)
{
	if (m_file == 0)
	{
		m_status = virtIO_t::cant_open_file_e;
		throw -1;
	}

	int retval = fread((void*)&p, size, 1, m_file);
	if (retval != 1)
	{
		m_status = virtIO_t::readErr_e;
		throw -1;
	}
	m_status = ok_e;
	return *this;
}

template <class P> 
bin_IO_t& bin_IO_t::Write(P p, unsigned int size)
{
	if (m_file == 0)
	{
		m_status = virtIO_t::cant_open_file_e;
		throw -1;
	}

	int retval = fwrite((void*)&p, size, 1, m_file);
	if (retval != 1)
	{
		m_status = virtIO_t::writeErr_e;
		throw -1;
	}
	m_status = ok_e;
	return *this;
}