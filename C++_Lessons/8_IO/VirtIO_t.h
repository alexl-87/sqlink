#ifndef VirtIO_t
#define VirtIO_t

#include <string>
#include <stdio.h>
using namespace std;
class virtIO_t
{
public:

	typedef enum {ok_e, cant_open_file_e, bad_access_e, writeErr_e, readErr_e}status;
	typedef enum {r, w, rp, wp, def}mode;
	
	virtIO_t();
	virtIO_t(const string& path, mode _mode);

	void 			fClose();
	void 			setStatus(status _status);
	int 			getPosition()const;
	mode 			getMode()const;
	status 			getStatus()const;
	const string& 	getPath()const;

	virtual ~virtIO_t() = 0;
	virtual void fOpen(const string& path, mode md) = 0;
	virtual void setPosition(unsigned int position)=0;
	virtual virtIO_t& operator>>(int& num)=0;
	virtual virtIO_t& operator<<(int& num)=0;

protected:
	status m_status;
	mode m_mode;
	unsigned int m_fileLeght;
	string m_path;
	FILE* m_file;

private:
	virtIO_t(const virtIO_t& v);
	virtIO_t& operator=(const virtIO_t& v);
};

#endif