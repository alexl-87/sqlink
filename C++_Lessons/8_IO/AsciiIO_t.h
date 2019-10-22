#include "VirtIO_t.h"
#include <stdio.h>
class asciiIO_t:public virtIO_t
{
public:
	asciiIO_t();
	asciiIO_t(const string& path, mode _mode);
	~asciiIO_t();
	virtual void fOpen(const string& path, mode _mode);
	virtual void setPosition(unsigned int position);
	virtual virtIO_t& operator>>(int& num);
	virtual virtIO_t& operator<<(int num);
private:
	template <class P> 
	void m_fprintf(P p, string& arg);

	template <class S> 
	void m_fscanf(S& s, string& arg);

	void open(const char* arg);
};

template <class P> 
void asciiIO_t::m_fprintf(P p, string& arg)
{

}


template <class S> 
void asciiIO_t::m_fscanf(S& s, string& arg)
{

}