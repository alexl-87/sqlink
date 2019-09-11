#include "Consumers.h"
#include "WQueue.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define CONSUMERS 1

struct Consumer
{
	Queue* m_ptcQueue;
	Queue* m_ctpQueue;
};



pthread_t* startConsumers(Queue* ptcQueue, Queue* ctpQueue)
{
	Consumer* consumer;
	pthread_t* tid;
	tid = malloc(sizeof(pthread_t)*CONSUMERS);
	int i = 0;

	for(i; i< CONSUMERS; i++)
	{
		consumer = malloc(sizeof(Consumer));
		if(!consumer)exit(1);

		consumer->m_ctpQueue = ctpQueue;
		consumer->m_ptcQueue = ptcQueue;
		
		pthread_create(&tid[i], NULL, consumerThread, (void*)consumer);
	}
	return tid;
}

void* consumerThread(void* arg)
{
	Consumer* consumer = (Consumer*)arg;
	char* msg = malloc(64);
	while(1)
	{
		
		readQueue(consumer->m_ptcQueue, (void**) &msg);
		printf("Message from producer %s\n"
			"Enter response to producers\n",(char*)msg);
		scanf("%s", msg);
		writeQueue(consumer->m_ctpQueue, (void*) msg);

		
		free(msg);
	}
}

void joinConsumers(pthread_t* threads)
{	

	int i = 0;

	for(i; i< CONSUMERS; i++)
	{
		pthread_join(threads[i], NULL);
	}

}