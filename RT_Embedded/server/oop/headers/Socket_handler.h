#ifndef Socket_handler
#define Socket_handler
#include "Handler.h"
#include "Reactor.h"
#include "Internet_handler.h"
#include "Handler.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <iostream>
using namespace std;

class socket_handler:public handler
{
public:
	socket_handler(const int port, const int queue_capacity, reactor* r);

	virtual ~socket_handler(){}

	virtual void accept_request(int event);
};

socket_handler::socket_handler(const int port, const int queue_capacity, reactor* r):handler(r){

	int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
	ERR::M1_ERR(socket_fd, "Failed to get socket fd");
	this->fd = socket_fd;
	struct sockaddr_in serv_addr;
	bzero((void*) &serv_addr, sizeof(struct sockaddr_in));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr= htonl(INADDR_ANY);
	serv_addr.sin_port = htons(port);
	ERR::M1_ERR(bind(fd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)), "Failed bind");
	ERR::M1_ERR(listen(fd, queue_capacity), "Failed listen");
	cout << "Socket handler created with fd = " << this->fd << endl;
	my_reactor->add_handler(this, EPOLLIN);
}

void socket_handler::accept_request(int event){

	cout << "Accepting request from socket fd = " << fd << endl;
	struct sockaddr_in client_addr;
	unsigned int len = sizeof(client_addr);
	int accept_fd = accept(this->fd, (struct sockaddr*) &client_addr, &len);
	ERR::M1_ERR(accept_fd, "Failed to accept new connection");
	internet_handler* new_internet_handler =new internet_handler(accept_fd, my_reactor);
	ERR::NULL_ERR(new_internet_handler);
	my_reactor->add_handler(new_internet_handler, EPOLLIN);
}

#endif