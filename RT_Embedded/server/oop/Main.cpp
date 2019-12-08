#include <map>
#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <sys/epoll.h>
#include <strings.h>
#include <unistd.h>
#include <string.h>

using namespace std;
/* Error handler */
class ERR
{

public:
	ERR();
	~ERR();

	static void M1_ERR(const int val){
		if(val == -1){
			exit(1);
		}
	}

	static void NULL_ERR(void* ptr){
		if(!ptr){
			exit(1);
		}
	}
};
/*************/
class reactor;

/* Base class for handlers */
class handler
{
public:
	handler(reactor* r){
		ERR::NULL_ERR(r);
		my_reactor = r;
		fd = -1;
	}
	virtual ~handler();

	virtual void accept_request(int event)=0;

	unsigned int get_fd(){
		return fd;
	}

protected:
	unsigned int fd;
	reactor* my_reactor;
};

/* Reactor class */

class reactor
{
public:
	reactor(){
		epoll_fd = epoll_create1(0);
		ERR::M1_ERR(epoll_fd);
	}

	void add_handler(handler* new_handler, int event){

		handler_op(new_handler, event, EPOLL_CTL_ADD);
	}
	void update_handler(handler* curr_handler, int event){

		handler_op(curr_handler, event, EPOLL_CTL_MOD);
	}
	void remove_handler(unsigned int fd);

	void start_reactor(unsigned int num_of_events){
		if (num_of_events < 1 || handlers.size() < 1){
			cerr << "No events to handle" << endl;
			return;
		}

		while(1) {
			struct epoll_event events_q[num_of_events];
			int events_counter = epoll_wait(epoll_fd, events_q, num_of_events, -1);
			ERR::M1_ERR(events_counter);
			for(int i=0;i<events_counter;i++){

				int fd = events_q[i].data.fd;
				int events=events_q[i].events;
				handlers[fd]->accept_request(events);
			}
		}
	}
	virtual ~reactor(){

	}

protected:
	map<int, handler*> handlers;
	unsigned int epoll_fd;

	void handler_op(handler* curr_handler, int event, int mod)
	{
		int new_fd = curr_handler->get_fd();
		handlers[new_fd] = curr_handler;
		struct epoll_event new_event;
		new_event.events = event;
		new_event.data.fd = new_fd;
		epoll_ctl(epoll_fd, mod, new_fd, &new_event);
	}
};


/* Internet handler*/

class internet_handler:public handler
{
public:
	internet_handler(int fd, reactor* r):handler(r)
	{
		this->fd = fd;
		index = 0;
		size = 4096;
		buffer = new char[size];
		ERR::NULL_ERR(buffer);
		filename = new char[128];
		ERR::NULL_ERR(filename);
	}

	virtual ~internet_handler();

	void accept_request(int event)
	{
		if(event & EPOLLIN) {
			read_request();
		}

		if (event & EPOLLOUT){
			write_response();
		}
	}

protected:	
	void read_request()
	{
		const char* eom="\r\n\r\n";
		const int eom_len=4;

		int retval = read(fd, buffer+index, size-index);
		ERR::M1_ERR(retval);
		if (retval < eom_len)
		{
			cerr << "Illegal request accepted" << endl;
			return;
		}

		index += retval;

		if(!strncmp((buffer + (index - eom_len)), eom, eom_len)){
			request_parser();
			index = 0;
			my_reactor->update_handler(this, EPOLLOUT);
		}
	}

	void write_response()
	{

	}

	void request_parser()
	{
		//get filename

		//open file

		//get file content or set error response
	}



	char* buffer;
	char* filename;
	int index;
	int size;

};

/************/

class socket_handler:public handler
{
public:
	socket_handler(int port, int queue_capacity, reactor* r):handler(r){
		int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
		ERR::M1_ERR(socket_fd);
		this->fd = socket_fd;
		struct sockaddr_in serv_addr;
		bzero((void*) &serv_addr, sizeof(struct sockaddr_in));
		serv_addr.sin_family = AF_INET;
		serv_addr.sin_addr.s_addr= htonl(INADDR_ANY);
		serv_addr.sin_port = htons(port);
		ERR::M1_ERR(bind(fd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)));
		ERR::M1_ERR(listen(fd, queue_capacity));
		my_reactor->add_handler(this, EPOLLIN);
	}

	virtual ~socket_handler();

	virtual void accept_request(int event){
		struct sockaddr_in client_addr;
		unsigned int len = sizeof(client_addr);
		int accept_fd = accept(this->fd, (struct sockaddr*) &client_addr, &len);
		ERR::M1_ERR(accept_fd);
		internet_handler* new_internet_handler =new internet_handler(accept_fd, my_reactor);
		ERR::NULL_ERR(new_internet_handler);
		my_reactor->add_handler(new_internet_handler, EPOLLIN);
	}
};

int main(int argc, char const *argv[])
{
	reactor r;
	return 0;
}