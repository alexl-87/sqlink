#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main()
{
	pid_t pid;
	char argument[] = {"Process_1"};
	char path[] = {"/home/alex/process_2"};
	char prog[] = {"process_2"};
	system("clear");
	fprintf(stdout, "Start parent process\n");
	pid = fork();

	if(pid == 0)
	{
		execl(path, prog, argument,(char*) NULL);
	}

	else
	{
		waitpid(pid, NULL, 0);
	}

	printf("\nEnd parent process \n\n");

	return 0;
}