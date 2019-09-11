
mthreads : pThreading.o Producers.o Consumers.o WQueue.o
	gcc -o mthreads pThreading.o Producers.o Consumers.o WQueue.o -pthread

WQueue.o : WQueue.c WQueue.h
	gcc -c -ansi -pedantic -pthread -g WQueue.c

pThreading.o : pThreading.c WQueue.h Producers.h Consumers.h
	gcc -c -ansi -pedantic -pthread -g pThreading.c

Producers.o : Producers.c Producers.h
	gcc -c -ansi -pedantic -pthread -g Producers.c

Consumers.o : Consumers.c Consumers.h
	gcc -c -ansi -pedantic -pthread -g Consumers.c
