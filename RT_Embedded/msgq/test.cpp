#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char const *argv[])
{
	fstream fs;
	fs.open("/dev/ipc_msgq0", fstream::in);

	if(fs.fail())
	{
		cout << "Fail" << endl;
	}
	return 0;
}