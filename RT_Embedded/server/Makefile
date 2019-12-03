server: server.c
	gcc -O2 -pedantic -Wall -Werror -o $@ $< -lpthread
	
.PHONY: clean
clean:
	rm -f server

.PHONY: server2
server2: server2.c
	gcc -O2 -pedantic -Wall -Werror -o $@ $< -lpthread