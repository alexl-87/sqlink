#include "Producers.h"
#include "WQueue.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PRODUCERS 5
struct Producer
{
	Queue* m_ptcQueue;
	Queue* m_ctpQueue;
	int m_id;
};



pthread_t* startProducers(Queue* ptcQueue, Queue* ctpQueue)
{
	Producer* producer;
	pthread_t* tid;
	int i = 0;
	tid = malloc(sizeof(pthread_t)*PRODUCERS);
	for(i; i< PRODUCERS; i++)
	{
		producer = malloc(sizeof(Producer));
		if(!producer)exit(1);

		producer->m_ctpQueue = ctpQueue;
		producer->m_ptcQueue = ptcQueue;
		producer->m_id = rand()%9999;

		pthread_create(&tid[i], NULL, producerThread, (void*)producer);
	}
	return tid;
}

void* producerThread(void* arg)
{
	Producer* producer = (Producer*)arg;
	unsigned int* msg;
	while(1)
	{
		msg = malloc(sizeof(unsigned int));
		*msg = producer->m_id;
		writeQueue(producer->m_ptcQueue, (void*) msg);
		readQueue(producer->m_ctpQueue, (void**) &msg);
		printf("Producer id : %d recieved message from consumer id : %d\n",producer->m_id, *msg);
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