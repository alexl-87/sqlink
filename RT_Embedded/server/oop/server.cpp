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
#include <sys/stat.h>
using namespace std;

const char* error_html=\
"HTTP/1.1 200 OK\n"
"Date: Mon, 27 Jul 2009 12:28:53 GMT\n"
"Server: Apache/2.2.14 (Win32)\n"
"Last-Modified: Wed, 22 Jul 2009 19:15:56 GMT\n"
"Content-Type: text/html\n"
"Connection: Closed\n"
"\n"
"<html>\n"
"<body>\n"
"<h1>ERROR 440044</h1>\n"
"<p>request page not found</p>\n"
"</body>\n"
"</html>\n";

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

/* Base abstract class for handlers */

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
		ERR::M1_ERR(close(fd));
	}

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
		int curr_fd = curr_handler->get_fd();
		handlers[curr_fd] = curr_handler;
		handler_op(curr_fd, event, EPOLL_CTL_ADD);
		
	}
	void update_handler(int curr_fd, int event){
		cout << "Updating existing handler with fd = " << curr_fd << endl;
		handler_op(curr_fd, event, EPOLL_CTL_MOD);
	}
	void remove_handler(int curr_fd){
		cout << "Updating existing handler with fd = " << curr_fd << endl;
		handler_op(curr_fd, 0, EPOLL_CTL_DEL);
		handlers.erase(curr_fd);
	}

	void start_reactor(unsigned int num_of_events){// delete num of events
		if (num_of_events < 1 || handlers.size() < 1){
			cerr << "No events to handle" << endl;
			return;
		}
		cout << "Reactor started" << endl;
		struct epoll_event* events_q = new struct epoll_event[num_of_events];
		while(1) {
			int events_counter = epoll_wait(epoll_fd, events_q, num_of_events, -1);
			ERR::M1_ERR(events_counter);
			for(int i=0;i<events_counter;i++){
				int fd = events_q[i].data.fd;
				int events=events_q[i].events;
				cout << "Current events value = " << events << endl
				<< "fd = " << fd << endl;
				handlers[fd]->accept_request(events);
			}
		}
		delete[] events_q;
	}
	virtual ~reactor(){
		ERR::M1_ERR(close(epoll_fd));
		handlers.clear();
	}

protected:
	map<int, handler*> handlers;
	unsigned int epoll_fd;

	void handler_op(int curr_fd, int event, int mod)
	{
		struct epoll_event new_event;
		new_event.events = event;
		new_event.data.fd = curr_fd;
		ERR::M1_ERR(epoll_ctl(epoll_fd, mod, curr_fd, &new_event));
		cout<< "Terminated operation on a handler:" << endl
			<< "fd = " << curr_fd << endl
			<< "mode = " << mod << endl;
	}
};


/* Internet handler*/

class internet_handler:public handler
{
public:
	internet_handler(int fd, reactor* r):handler(fd, r)
	{
		index = 0;
		size = 4096;
		buffer = new char[size];
		filename = new char[128];
		cout << "Internet handler created with fd = " << fd << endl;
	}

	virtual ~internet_handler()
	{
		delete[] buffer;
		delete[] filename;
	}

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
	bool message_is_complete() {
		const char* eom="\r\n\r\n";
		const int eom_len=4;

		if(index<4) return false;

		return memcmp(buffer+index-eom_len, eom, eom_len)==0;
	}
	void read_request()
	{
		cout << "Reading internet request" << endl;
		
		int retval = read(fd, buffer+index, size-index);
		ERR::M1_ERR(retval);
		if(retval == 0){
			my_reactor->remove_handler(this->fd);
		}else{

			index+=retval;
		
			if(message_is_complete()) {
				request_parser();
				cout << "File name is: " << filename << endl;
				index = 0;
				// struct stat statbuf;
				// check_error(stat(filename, &statbuf));
				// int file_size = statbuf.st_size;
				my_reactor->update_handler(this->fd, EPOLLOUT);
			}
		}

	}

	void write_response()
	{
		int fd  = open(filename, O_RDONLY);
		if(fd == -1){
			cout << "Inside write response" << endl;
			ERR::M1_ERR(write(fd, error_html, strlen(error_html)));
			my_reactor->remove_handler(fd);
		}else{
			
		}

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