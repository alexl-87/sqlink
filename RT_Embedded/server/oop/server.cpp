#include "Reactor.h"
#include "Socket_handler.h"
#include "mq.h"
#include "Err.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <pthread.h>
#include <iostream>
using namespace std;
void* watchdog(void *r);
int main(int argc, char const *argv[])
{
	pthread_t reactor_watchdog;
	reactor r;
	pthread_create(&reactor_watchdog, NULL, watchdog, (void*)&r);
	socket_handler s(5050, 10, &r);
	r.start_reactor(100);
	pthread_join(reactor_watchdog, NULL);
	return 0;
}

void* watchdog(void *r){
	reactor* react = (reactor*)r;
	int fd = open("/dev/ipc_msgq0", O_RDWR);
	ERR::M1_ERR(fd == -1, "Failed to open message queue");

	char* message = new char[MESSAGE_SIZE];

	while(1){
		ioctl(fd, MSGQ_READER, message);
		cout<<"Message: " << message << endl;
		if(!strcmp(message, "terminate"))
		{
			react->stop_reactor();
			break;
		}
	}
	delete message;
	close(fd);
	return NULL;
}