#ifndef Internet_handler
#define Internet_handler
#include "Handler.h"
#include "Reactor.h"
#include "Err.h"
#include <sys/epoll.h>
#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
using namespace std;
class internet_handler:public handler
{
public:
	virtual ~internet_handler()
	{
		delete[] buffer;
		delete[] filename;
	}
	internet_handler(int fd, reactor* r);
	void accept_request(int event);

protected:	

	bool message_is_complete();
	void read_request();
	void write_response();
	void request_parser();

	char* buffer;
	char* filename;
	int read_index;
	int write_index;
	int size;
	int html_file_fd;
};

internet_handler::internet_handler(int fd, reactor* r):handler(fd, r)
{
	read_index = 0;
	size = 4096;
	buffer = new char[size];
	filename = new char[128];
	cout << "Internet handler created with fd = " << fd << endl;
}

void internet_handler::accept_request(int event)
{
	if(event & EPOLLIN) {
		read_request();
	}

	if (event & EPOLLOUT){
		write_response();
	}
}

bool internet_handler::message_is_complete() {
	const char* eom="\r\n\r\n";
	const int eom_len=4;

	if(read_index<4) return false;

	return memcmp(buffer+read_index-eom_len, eom, eom_len)==0;
}

void internet_handler::read_request()
{
	cout << "Reading internet request" << endl;
	
	int retval = read(fd, buffer+read_index, size-read_index);
	ERR::M1_ERR(retval, "Failed to read request from browser");
	if(retval == 0){
		cout <<"REmoooooving" << endl;
		my_reactor->remove_handler(this->fd);

	}else{

		read_index+=retval;
	
		if(message_is_complete()) {
			request_parser();
			cout << "File name is: " << filename << endl;
			read_index = 0;
			write_index = 0;
			int new_fd = open(filename, O_RDONLY);
			if (new_fd == -1){
				cerr << "Cant open file" << endl;
				my_reactor->remove_handler(this->fd);

			}else{
				html_file_fd = new_fd;
				struct stat file_stat;
				fstat(html_file_fd, &file_stat);
				int new_size = file_stat.st_size;
				if (size < new_size){
					delete[] buffer;
					buffer = new char[new_size];
				}
				cout << "New buffer size = " << new_size << endl;
				size = new_size;
				my_reactor->update_handler(this->fd, EPOLLOUT);
			}
			
		}
	}
}


void internet_handler::write_response()
{
	if(read_index < size){
		ERR::M1_ERR(lseek(html_file_fd, read_index, SEEK_SET), "Failed to seak");
		int retval = read(html_file_fd, buffer+read_index, size - read_index);
		ERR::M1_ERR(retval, "Failed to read from opened html file");
		read_index += retval;
	}else{
		cout << "Closing html file" << endl;
		ERR::M1_ERR(close(html_file_fd), "Failed to close html file");
	}

	if(write_index < size && write_index < read_index)
	{
		int retval = write(fd, buffer+write_index, read_index - write_index);
		ERR::M1_ERR(retval, "Failet to write to internet handler fd");
		write_index += retval;
	}

	if (write_index >= size)
	{
		my_reactor->remove_handler(this->fd);
	}
}

void internet_handler::request_parser()
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
#endif