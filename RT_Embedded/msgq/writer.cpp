#include "mq.h"
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	int fd;
	char* data;
	if(argc != 2)
	{
		cerr << "Missing arguments" << endl;
		return 1;
	}

	//argv[1] = char dev path
	fd = open(argv[1], O_RDWR);
	if(fd == -1)
	{
		cerr << "error file name" << endl;
		return 1;
	}

	struct mq_r


	ret = ioctl(fd, MQ_RECV_MSG, data);
	cout<< "Return value from get ioctl: " << ret << endl;

	if(close(fd) < 0)
	{
		cerr << "error closing file" << endl;
		return 1;        
	}
     
	return 0;
}