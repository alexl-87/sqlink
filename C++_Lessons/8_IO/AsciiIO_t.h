#include "VirtIO_t.h"
#include <stdio.h>
#include <typeinfo>

class asciiIO_t:public virtIO_t
{
public:
	asciiIO_t();
	asciiIO_t(const string& path, mode _mode);
	~asciiIO_t();

	virtual void fOpen(const string& path, mode md);
	virtual void setPosition(unsigned int position);
	virtual virtIO_t& operator>>(int& num);
	virtual virtIO_t& operator<<(int num);

private:
	asciiIO_t(const asciiIO_t& a);
	asciiIO_t& operator=(const asciiIO_t& a);

	template <class P> 
	void m_IO(P p, int n);

	void open(const string& path, const char* md);
};

template <class P> 
void asciiIO_t::m_IO(P p, int num)
{

	if(m_mode != w && m_mode != wp)
	{
		m_status = bad_access_e;
		throw -1;
	}

	else if(m_file != 0)
	{
		char c = *typeid(p).name();
		string arg;

		switch(c)
		{

			case 'c': //char
			arg = "%c";
			break;

			case 'j': //unsigned int
			arg = "%u";
			break;

			case 'l': //long
			arg = "%ld";
			break;

			case 'm': // unsigned long
			arg = "%lu";
			break;

			case 'f': //float
			arg = "%f";
			break;

			case 'd': //double
			arg = "%f";
			break;

			default:
			arg = "%d";
			break;

		};

		if(num == 0)
		{
			int res = fprintf(m_file, arg.c_str() ,p);
			if(res < 0)
			{
				throw res;
			}
		}
		else if(num == 1)
		{
			int res = fscanf(m_file, arg.c_str() ,&p);
			if(res < 0)
			{
				throw res;
			}
		}
	}
}