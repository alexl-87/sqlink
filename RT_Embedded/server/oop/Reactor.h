#ifndef Reactor
#define Reactor
#include "Handler.h"
#include "Err.h"
#include <map>
#include <iostream>
#include <sys/epoll.h>
using namespace std;

class reactor
{
public:

	virtual ~reactor();
	reactor();

	void add_handler(handler* curr_handler, int event);
	void update_handler(int curr_fd, int event);
	void remove_handler(int curr_fd);
	void start_reactor(unsigned int num_of_events);
	void stop_reactor(){loop = false;}

protected:
	map<int, handler*> handlers;
	unsigned int epoll_fd;
	volatile bool loop;

	void handler_op(int curr_fd, int event, int mod);
};


reactor::~reactor(){
	ERR::M1_ERR(close(epoll_fd), "failed to close epoll_fd");
	for (std::map<int, handler*>::iterator i = handlers.begin(); i != handlers.end(); ++i)
	{
		delete i->second;
	}
	handlers.clear();
}
reactor::reactor(){
	epoll_fd = epoll_create1(0);
	ERR::M1_ERR(epoll_fd, "Failed to get epoll_fd");
	cout << "New reactor created with epoll_fd = " << epoll_fd << endl;
	loop = true;
}

void reactor::add_handler(handler* curr_handler, int event){
	cout << "Adding handler with fd = " << curr_handler->get_fd() << endl;
	int curr_fd = curr_handler->get_fd();
	handlers[curr_fd] = curr_handler;
	handler_op(curr_fd, event, EPOLL_CTL_ADD);
	
}
void reactor::update_handler(int curr_fd, int event){
	cout << "Updating existing handler with fd = " << curr_fd << endl;
	handler_op(curr_fd, event, EPOLL_CTL_MOD);
}
void reactor::remove_handler(int curr_fd){
	cout << "Deleting existing handler with fd = " << curr_fd << endl;
	handler_op(curr_fd, 0, EPOLL_CTL_DEL);
	delete handlers[curr_fd];
	handlers.erase(curr_fd);
}

void reactor::start_reactor(unsigned int num_of_events){
	if (handlers.size() < 1){
		cerr << "No events to handle" << endl;
		return;
	}
	cout << "Reactor started" << endl;
	struct epoll_event* events_q = new struct epoll_event[num_of_events];
	while(loop) {
		int events_counter = epoll_wait(epoll_fd, events_q, num_of_events, -1);
		ERR::M1_ERR(events_counter, "Failed to get events counter");
		for(int i=0;i<events_counter;i++){
			int fd = events_q[i].data.fd;
			int events=events_q[i].events;
			handlers[fd]->accept_request(events);
		}
	}
	delete[] events_q;
}

void reactor::handler_op(int curr_fd, int event, int mod)
{
	struct epoll_event new_event;
	new_event.events = event;
	new_event.data.fd = curr_fd;
	ERR::M1_ERR(epoll_ctl(epoll_fd, mod, curr_fd, &new_event), "Failed epoll_ctl");
}

#endif