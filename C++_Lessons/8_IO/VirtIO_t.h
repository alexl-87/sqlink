#ifndef VirtIO_t
#define VirtIO_t

#include <string>
#include <stdio.h>
using namespace std;
class virtIO_t
{
public:
	
	enum status{ok_e, cant_open_file_e, bad_access_e, writeErr_e, readErr_e, def_e};
	enum access{r, w, rp, wp, def};
	
	virtual ~virtIO_t();
	virtIO_t();
	virtIO_t(const string& path, enum access _access);
	void fClose();
	const string& getPath()const;
	enum access getAccess()const;
	enum status getStatus()const;
	unsigned int getPosition()const;
	void setStatus(enum status _status);
	virtual ~virtIO_t() = 0;
	virtual void fOpen(const string& path, enum access _access) = 0;
	virtual void setPosition(unsigned int position)=0;
	virtual virtIO_t& operator>>(int& num)=0;
	virtual virtIO_t& operator<<(int num)=0;

protected:
	enum status m_status;
	enum access m_access;
	unsigned int m_fileLeght;
	unsigned int m_position;
	string m_path;
	FILE* m_file;

private:
	virtIO_t(const virtIO_t& v);
	virtIO_t& operator=(const virtIO_t& v);
};

#endif