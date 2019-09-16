#include "Consumers.h"
#include "WQueue.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CONSUMERS 5
struct Consumer
{
	Queue* m_ptcQueue;
	Queue* m_ctpQueue;
	int m_id;
};

pthread_t* startConsumers(Queue* ptcQueue, Queue* ctpQueue)
{
	Consumer* consumer;
	pthread_t* tid;
	int i = 0;
	tid = malloc(sizeof(pthread_t)*CONSUMERS);

	for(i; i< CONSUMERS; i++)
	{
		consumer = malloc(sizeof(Consumer));
		if(!consumer)exit(1);

		consumer->m_ctpQueue = ctpQueue;
		consumer->m_ptcQueue = ptcQueue;
		consumer->m_id = rand()%9999;
		
		pthread_create(&tid[i], NULL, consumerThread, (void*)consumer);
	}
	return tid;
}

void* consumerThread(void* arg)
{
	Consumer* consumer = (Consumer*)arg;
	unsigned int* msg;
	while(1)
	{
		readQueue(consumer->m_ptcQueue, (void**) &msg);
		printf("Consumer id : %d recieved message from producer id : %d\n",consumer->m_id, *((unsigned int*)msg));
		free(msg);
		msg = malloc(sizeof(unsigned int));
		*msg = consumer->m_id;
		writeQueue(consumer->m_ctpQueue, (void*) msg);	
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