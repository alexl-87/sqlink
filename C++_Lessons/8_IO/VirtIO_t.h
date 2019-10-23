#ifndef VirtIO_t
#define VirtIO_t

#include <string>
#include <stdio.h>
using namespace std;
class virtIO_t
{
public:

	typedef enum {ok_e, cant_open_file_e, bad_access_e, writeErr_e, readErr_e}status;
	
	virtIO_t();
	virtIO_t(const string& path, const string& mode);

	void 			Close();
	void 			setStatus(status _status);
	void 			setPosition(unsigned int position);
	void 			Open(const string& path, const char* mode);

	int 			getPosition();
	const string& 	getMode()const;
	status 			getStatus()const;
	const string& 	getPath()const;
	int 			getLen();

	virtual ~virtIO_t() = 0;
	virtual virtIO_t& operator>>(int& num)=0;
	virtual virtIO_t& operator<<(int num)=0;

protected:
	status m_status;
	string m_mode;
	string m_path;
	FILE* m_file;

private:
	virtIO_t(const virtIO_t& v);
	virtIO_t& operator=(const virtIO_t& v);
};

#endif