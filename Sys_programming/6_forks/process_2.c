#include <stdio.h>
int main(int argc, char **argv)
{

	printf("\nStart child process with argument: %s\n", argv[1]);
	sleep(1);
	printf("\nEnd child process\n");

	return 0;
}