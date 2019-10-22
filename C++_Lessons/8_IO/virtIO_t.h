#include <string>
#include <stdio.h>
using namespace std;
class virtIO_t
{
public:
	
	enum status{ok_e, cant_open_file_e, bad_access_e, writeErr_e, readErr_e};
	enum access{r, w, rw};


	~virtIO_t();
	virtIO_t();
	virtIO_t(const string& path, enum access _access);
	const string& getPath()const;
	enum access getAccess()const;
	enum status getStatus()const;
	void setStatus(enum status _status);
	enum status{ok_e, cant_open_file_e, bad_access_e, writeErr_e, readErr_e};
	enum access{r, w, rw};
	unsigned int getPosition()const;
	void setPosition(unsigned int position);
	virtIO_t& operator>>(int num);
	virtIO_t& operator<<(int num);

protected:
	enum status m_status;
	enum access m_access;
	unsigned int m_fileLeght;
	string m_path;
	FILE* m_file;

private:
	virtIO_t(virtIO_t& v);
	void operator=(virtIO_t& v);
};