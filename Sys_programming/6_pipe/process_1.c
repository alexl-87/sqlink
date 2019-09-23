#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main()
{
	pid_t pid;
	char buf[20];
	int descriptors[2];
	pipe(descriptors);
	write(descriptors[0], buf, sizeof(buf));
	pid = fork();

	if(pid == 0)
	{	
		write(descriptors[1], "HELLLLOOOOO", 12);
	}

	else
	{
		read(descriptors[0], buf, 20);
		write(1, buf, sizeof(buf));
	}
	
	return 0;
}