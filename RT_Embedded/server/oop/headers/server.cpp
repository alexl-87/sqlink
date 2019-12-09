// #include <map>
// #include <iostream>
// #include <sys/types.h>
// #include <sys/socket.h>
// #include <netinet/in.h>
// #include <netinet/ip.h>
// #include <sys/epoll.h>
// #include <strings.h>
// #include <unistd.h>
// #include <string.h>
// #include <sys/stat.h>
// #include <fstream>
// #include <fcntl.h>

#include "Reactor.h"
#include "Socket_handler.h"

using namespace std;

int main(int argc, char const *argv[])
{
	reactor r;
	socket_handler s(5050, 10, &r);
	r.start_reactor(100);
	return 0;
}