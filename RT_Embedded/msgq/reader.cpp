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
	int ret;
	char* data;
	if(argc != 2)
	{
		return 1;
	}

	fd = open(argv[1], O_RDWR);
	if(fd == -1)
	{
		fprintf(stderr, "error file name\n");
		return 1;
	}
	ret = ioctl(fd, MQ_RECV_MSG, data);
	cout<< "Return value from get ioctl: " << ret << endl;

	if(close(fd) < 0)
	{
		fprintf(stderr, "error closing file\n");
		return 1;        
	}
     
	return 0;
}