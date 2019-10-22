#include "VirtIO_t.h"
class asciiIO_t:public virtIO_t
{
public:
	asciiIO_t();
	~asciiIO_t();
	virtual ~virtIO_t();
	virtual void fOpen(const string& path, enum access _access);
	virtual void setPosition(unsigned int position);
	virtual virtIO_t& operator>>(int& num);
	virtual virtIO_t& operator<<(int num);

private:

	template <class P> 
	void m_fprintf(P p, string& arg);

	template <class S> 
	void m_fscanf(S& s, string& arg);
};