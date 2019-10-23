#include "VirtIO_t.h"
#include <stdio.h>
#include <typeinfo>

class asciiIO_t:public virtIO_t
{
public:
	asciiIO_t();
	asciiIO_t(const string& path, mode _mode);
	~asciiIO_t();
	virtual virtIO_t& operator>>(int& num)=0;
	virtual virtIO_t& operator<<(int num)=0;

private:
	asciiIO_t(const asciiIO_t& a);
	asciiIO_t& operator=(const asciiIO_t& a);

	template <class P> 
	virtIO_t& Read(P& p, char* mode);

	template <class P> 
	virtIO_t& Write(P p, char* mode);
};

template <class P> 
virtIO_t& asciiIO_t::Read(P& p, char* mode)
{

}

template <class P> 
virtIO_t& asciiIO_t::Write(P p, char* mode)
{

}