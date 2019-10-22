#include <string>
using namespace std;
class virtIO_t
{
public:
	
	~virtIO_t();
	virtIO_t();


	enum status{ok_e, cant_open_file_e, bad_access_e, writeErr_e, readErr_e};
	enum access{r, w, rw};

protected:
	enum status stat;
	enum access acsessMode;
	string path;
	FILE* file;

private:
	virtIO_t(virtIO_t& v);
	void operator=(virtIO_t& v);
};