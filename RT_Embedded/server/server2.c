#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <sys/epoll.h>
#include <signal.h>

#define PORT 5050
#define BUFFER_SIZE 4096
#define FILENAME_LEN 128
#define NUM_OF_EVENTS 100
#define EPOLL EPOLLIN|EPOLLOUT

int loop = 1;

typedef struct respond
{
	char* m_buffer;
	unsigned int m_index;
	unsigned int m_buffsize;

}respond;

respond* buffer_manager[NUM_OF_EVENTS];

void ERR(int n, const char* msg);
void socket_init(struct sockaddr_in* serv_addr, int* socket_fd);
void epoll_init(int* epoll_fd, int* socket_fd, struct epoll_event* event);
void read_request(int* fd, int* epoll_fd, char* buffer);
void response(FILE* file, int* fd, int* file_len, char* file_content);
void get_file_name(char* buffer, char* filename);
void accept_request(int* socket_fd, int* epoll_fd, struct sockaddr_in* client_addr);
int get_file_len(FILE* file);

void SIGINT_handler(int signal)
{
	printf("\nSignal %d accepted\nNothing to do with this yet\n", signal);
	loop = 0;
}

/*
*TODO:
*	make sure read and write complete task
*	C^ siglnal handler
*	output to browser
*/

int main(int argc, char const *argv[])
{
	if(signal(SIGINT, SIGINT_handler) == SIG_ERR)
	printf("\ncan't catch SIGINT\n");

	int socket_fd = 0, epoll_fd = 0;
	struct sockaddr_in serv_addr, client_addr;

	socket_init(&serv_addr, &socket_fd);

	struct epoll_event event, events_q[NUM_OF_EVENTS];

	epoll_init(&epoll_fd, &socket_fd, &event);

	while(loop)
	{
		int events_counter = epoll_wait(epoll_fd, events_q, NUM_OF_EVENTS, -1);
		ERR(events_counter, "Failed epoll_wait()");
		int i = 0;
		for (;i < events_counter; ++i)
		{
			int fd = events_q[i].data.fd;
			if(fd == socket_fd)
			{	
				accept_request(&socket_fd, &epoll_fd, &client_addr);
			}

			else
			{

				char filename[FILENAME_LEN];
				char buffer[BUFFER_SIZE];
				char* file_content;

				if(events_q[i].events & EPOLLIN)
				{
					read_request(&fd, &epoll_fd, buffer);
					get_file_name(buffer, filename);
				}

				if(events_q[i].events & EPOLLOUT)
				{
					FILE* file = fopen(filename, "r");

					if (file)
					{
						int file_len = get_file_len(file);
						file_content = malloc(file_len);
						buffer_manager[fd] = (respond*) malloc(sizeof(respond));
						if (!file_content || !buffer_manager[fd])
						{
							printf("malloc error\n");
							free(file_content);
							free(buffer_manager[fd]);
						}
						else
						{
							buffer_manager[fd]->m_index = 0;
							buffer_manager[fd]->m_buffer = file_content;
							buffer_manager[fd]->m_buffsize = file_len;
							response(file, &fd, &file_len, file_content);
						}
						
					}

					struct epoll_event delete_event;
					delete_event.data.fd = fd;
					ERR(epoll_ctl(epoll_fd, EPOLL_CTL_DEL, fd, &delete_event),  "Failed epoll_ctl()");
				}
			}
		}
	}

	ERR(close(socket_fd), "Failed close()");
	ERR(close(epoll_fd), "Failed close()");

	return 0;
}


void ERR(int n, const char* msg)
{
	if (n < 0)
	{
		printf("%s\n", msg);
		exit(0);
	}
}

void socket_init(struct sockaddr_in* serv_addr, int* socket_fd)
{
	ERR(*socket_fd = socket(AF_INET, SOCK_STREAM, 0), "Failed socket()");
	bzero((void*) serv_addr, sizeof(struct sockaddr_in));
	serv_addr->sin_family = AF_INET;
	serv_addr->sin_addr.s_addr= htonl(INADDR_ANY);
	serv_addr->sin_port = htons(PORT);

	ERR(bind(*socket_fd, (struct sockaddr*) serv_addr, sizeof(*serv_addr)), "Failed bind()");

	ERR(listen(*socket_fd, 5), "Failed listen()");
}

void epoll_init(int* epoll_fd, int* socket_fd, struct epoll_event* event)
{
	*epoll_fd = epoll_create1(0);
	ERR(*epoll_fd, "Failed epoll_create1()");
	event->events = EPOLLIN;
	event->data.fd = *socket_fd;
	ERR(epoll_ctl(*epoll_fd, EPOLL_CTL_ADD, *socket_fd, event), "Failed epoll_ctl()");
}

void read_request(int* fd, int* epoll_fd, char* buffer)
{
	ERR(read(*fd, buffer, BUFFER_SIZE), "Failed read()");
	struct epoll_event updated_event;
	updated_event.events = EPOLLOUT;
	updated_event.data.fd = *fd;
	ERR(epoll_ctl(*epoll_fd, EPOLL_CTL_MOD, *fd, &updated_event),  "Failed epoll_ctl()");
}

void response(FILE* file, int* fd, int* file_len, char* file_content)
{
	int retval = fread((void*)file_content, 1, *file_len, file);//change to read()
	ERR(retval, "Failed fread()");
	retval = write(*fd, file_content, strlen(file_content));
	ERR(retval, "Faied write()");
	free(file_content);
	fclose(file);
}

void accept_request(int* socket_fd, int* epoll_fd, struct sockaddr_in* client_addr)
{
	unsigned int len = sizeof(client_addr);
	int accept_fd = accept(*socket_fd, (struct sockaddr*) client_addr, &len);
	ERR(accept_fd, "Failed accept()");
	struct epoll_event new_event;
	new_event.events = EPOLLIN;
	new_event.data.fd = accept_fd;
	ERR(epoll_ctl(*epoll_fd, EPOLL_CTL_ADD, accept_fd, &new_event),  "Failed epoll_ctl()");
}

void get_file_name(char* buffer, char* filename)
{
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

int get_file_len(FILE* file)
{
	fseek(file, 0, SEEK_END);
	int retval = ftell(file);
	fseek(file, 0, SEEK_SET);
	return retval;
}