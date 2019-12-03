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

#define PORT 5050
#define NUM_OF_RESPONDERS 10
#define BUFFER_SIZE 4096
#define FILENAME_LEN 128

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

void* response(void* arg)
{

	printf("Inside response function\n");
	int fd = *((int*)arg);
	char buffer[BUFFER_SIZE];
	char filename[FILENAME_LEN];
	char* file_content;
	FILE* file;
	int file_len;

	int retval = read(fd, buffer, BUFFER_SIZE);

	if (retval < 0)
	{
		return NULL;
	}

	get_file_name(buffer, filename);
	//printf("Buffer content is %s\n", buffer);
	//printf("***Filename is %s\n", filename);

	file = fopen(filename, "r");

	if (file)
	{
		fseek(file, 0, SEEK_END);
		file_len = ftell(file);
		fseek(file, 0, SEEK_SET);

		file_content = malloc(file_len);
		retval = fread((void*)file_content, 1, file_len, file);
		//printf("File content is : %s\n", file_content);

		retval = write(fd, file_content, strlen(file_content));
		fclose(file);
	}
	close(fd);
	return NULL;
}


int main(int argc, char const *argv[])
{

	int socket_fd = 0, accept_fd = 0;
	int retval = 0;
	struct sockaddr_in serv_addr, client_addr;

	socket_fd = socket(AF_INET, SOCK_STREAM, 0);

	if(socket_fd < 0)
	{
		fprintf(stderr, "Unable open socket\n");
		return socket_fd;
	}
	bzero((void*) &serv_addr, sizeof(struct sockaddr_in));

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr= htonl(INADDR_ANY);
	serv_addr.sin_port = htons(PORT);

	retval = bind(socket_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
	if (retval != 0)
	{
		fprintf(stderr, "Unable to bind: retval = %d\n", retval);
		return retval;
	}

	retval = listen(socket_fd, 5);
	if (retval != 0)
	{
		fprintf(stderr, "Unable to listen\n");
		return retval;
	}

	unsigned int len = sizeof(client_addr);

	int i = 20;
	while(i--)
	{
		accept_fd = accept(socket_fd, (struct sockaddr*)&client_addr, &len);

		if (accept_fd < 0)
		{
			fprintf(stderr, "accept_fd failed\n");
			exit(1);
		}

		pthread_t newThread;
		retval = pthread_create(&newThread, NULL, response, (void*) &accept_fd);

		if (retval)
		{
			fprintf(stderr, "Failed to create thread\n");
			exit(1);
		}
	}

	close(socket_fd);

	return 0;
}