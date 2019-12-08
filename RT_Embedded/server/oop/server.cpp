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
			cerr << "-1 error" << endl;
			exit(1);
		}
	}

	static void NULL_ERR(void* ptr){
		if(!ptr){
			cerr << "NULL error" << endl;
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

	virtual ~handler(){}

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
		cout << "New reactor created with epoll_fd = " << epoll_fd << endl;
	}

	void add_handler(handler* curr_handler, int event){
		cout << "Adding handler with fd = " << curr_handler->get_fd() << endl;
		handler_op(curr_handler, event, EPOLL_CTL_ADD);
	}
	void update_handler(handler* curr_handler, int event){
		cout << "Updating existing handler with fd = " << curr_handler->get_fd() << endl;
		handler_op(curr_handler, event, EPOLL_CTL_MOD);
	}
	void remove_handler(unsigned int fd);

	void start_reactor(unsigned int num_of_events){
		if (num_of_events < 1 || handlers.size() < 1){
			cerr << "No events to handle" << endl;
			return;
		}
		cout << "Reactor started" << endl;
		while(1) {
			struct epoll_event* events_q = new struct epoll_event[num_of_events];
			int events_counter = epoll_wait(epoll_fd, events_q, num_of_events, -1);
			ERR::M1_ERR(events_counter);
			for(int i=0;i<events_counter;i++){
				int fd = events_q[i].data.fd;
				int events=events_q[i].events;
				cout << "Current events value = " << events << endl;
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
		int curr_fd = curr_handler->get_fd();
		handlers[curr_fd] = curr_handler;
		struct epoll_event new_event;
		new_event.events = event;
		new_event.data.fd = curr_fd;
		ERR::M1_ERR(epoll_ctl(epoll_fd, mod, curr_fd, &new_event));

		cout<< "Terminated operation on a handler:" << endl
			<< "fd = " << curr_handler->get_fd() << endl
			<< "mode = " << mod << endl;
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
		cout << "Internet handler created with fd = " << fd << endl;
	}

	virtual ~internet_handler(){}

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
		cout << "Reading internet request" << endl;
		const char* eom="\r\n\r\n";
		const int eom_len=4;

		int retval = read(fd, buffer+index, size-index);
		ERR::M1_ERR(retval);
		if (retval < eom_len)
		{
			cerr<< "Illegal request accepted" << endl
				<<"Returned value from read = " << retval << endl;
			return;
		}

		index += retval;

		if(!strncmp((buffer + (index - eom_len)), eom, eom_len)){
			cout << "Accpeted buffer from fd = "<< fd << " is:" << endl << buffer << endl;

			request_parser();
			index = 0;
			my_reactor->update_handler(this, EPOLLOUT);
		}
	}

	void write_response()
	{
		cout << "Inside write response" << endl;
		const char* response_msg=\
		"HTTP/1.1 200 OK\n" \
		"Date: Mon, 27 Jul 2009 12:28:53 GMT\n" \
		"Server: Apache/2.2.14 (Win32)\n" \
		"Last-Modified: Wed, 22 Jul 2009 19:15:56 GMT\n" \
		"Content-Type: text/html\n" \
		"Connection: Closed\n" \
		"\n" \
		"<html>\n" \
		"<body>\n" \
		"<h1>Welcome to my website</h1>\n" \
		"<p>my website is bla bla bla</p>\n" \
		"</body>\n" \
		"</html>\n";
		ERR::M1_ERR(write(fd, response_msg, strlen(response_msg)));
		my_reactor->update_handler(this, EPOLLIN);
	}

	void request_parser()
	{
		cout << "Inside request parser" << endl;
		int i = 0, j = 0;
		while(buffer[i++] != '/'){}

		while(buffer[i] != ' ')
		{
			filename[j] = buffer[i];
			++i;
			++j;
		}
		filename[j] = '\0';
		//int fd = open(filename, "r");
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
	socket_handler(const int port, const int queue_capacity, reactor* r):handler(r){
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
		cout << "Socket handler created with fd = " << this->fd << endl;
		my_reactor->add_handler(this, EPOLLIN);

	}

	virtual ~socket_handler(){}

	virtual void accept_request(int event){
		cout << "Accepting request from socket fd = " << fd << endl;
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
	cout<< "EPOLL_CTL_MOD = " << EPOLL_CTL_MOD << endl
		<< "EPOLL_CTL_ADD = " << EPOLL_CTL_ADD << endl;
	reactor r;
	socket_handler s(5050, 10, &r);
	r.start_reactor(100);
	return 0;
}