#ifndef Handler
#define Handler
#include "Reactor.h"
#include "Err.h"
#include <iostream>
using namespace std;
class handler
{
public:
	handler(int my_fd, reactor* r){
		my_reactor = r;
		fd = my_fd;
	}

	handler(reactor* r){
		my_reactor = r;
	}

	virtual ~handler()
	{
		ERR::M1_ERR(close(fd), "Failed to close handler fd");
		cout << "File descriptor " << fd << " sclosed" << endl;
	}

	virtual void accept_request(int event)=0;

	unsigned int get_fd()const{
		return fd;
	}

protected:
	unsigned int fd;
	reactor* my_reactor;
};

#endif