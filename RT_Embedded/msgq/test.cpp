#include <iostream>
#include <fstream>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

using namespace std;
int main(int argc, char const *argv[])
{
	int fd = open("/dev/ipc_msgq0", O_RDONLY);
	cout << fd << endl;
	return 0;
}