#include "Producers.h"
#include "WQueue.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define PRODUCERS 1

struct Producer
{
	Queue* m_ptcQueue;
	Queue* m_ctpQueue;
};



pthread_t* startProducers(Queue* ptcQueue, Queue* ctpQueue)
{
	Producer* producer;
	pthread_t* tid;
	tid = malloc(sizeof(pthread_t)*PRODUCERS);
	int i = 0;

	for(i; i< PRODUCERS; i++)
	{
		producer = malloc(sizeof(Producer));
		if(!producer)exit(1);

		producer->m_ctpQueue = ctpQueue;
		producer->m_ptcQueue = ptcQueue;

		pthread_create(&tid[i], NULL, producerThread, (void*)producer);
	}
	return tid;
}

void* producerThread(void* arg)
{
	Producer* producer = (Producer*)arg;
	char* msg = malloc(64);
	while(1)
	{
		printf("Enter message to consumers\n");
		scanf("%s", msg);
		writeQueue(producer->m_ptcQueue, (void*) msg);
		readQueue(producer->m_ctpQueue, (void**) &msg);
		printf("Response from consumer %s\n",msg);
		free(msg);
	}
}
void joinProducers(pthread_t* threads)
{
	int i =0;

	for(i; i< PRODUCERS; i++)
	{
		pthread_join(threads[i], NULL);
	}
}