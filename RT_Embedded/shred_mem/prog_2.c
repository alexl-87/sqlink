#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
	int id = 189;
	int i = 0;
	key_t key = ftok("basa", id);
	int* mem_ptr;
	int memID = shmget(key, 64, IPC_CREAT|0666);
	mem_ptr = shmat(memID, NULL, 0);

	for (i; i < 999999; ++i)
	{
		printf("%d\n", mem_ptr[13]);
		sleep(1);
	}
	return 0;
}