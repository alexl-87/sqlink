#include "WQueue.h"
#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
struct Queue
{
	void** m_array;
	unsigned int m_capacity;
	int m_index;
	sem_t m_readSem;
	sem_t m_writeSem;
	pthread_mutex_t m_mutex;
};


void createQueue(Queue** queue, unsigned int capacity)
{
	Queue* newQueue;
	int i = 0;
	if(!queue || capacity < 1)return;

	newQueue = malloc(sizeof(Queue));
	if(!newQueue) return;

	newQueue->m_array = malloc(sizeof(void*)*capacity);
	
	if (!newQueue->m_array)
	{
		free(newQueue);
		return;
	}

	newQueue->m_capacity = capacity;
	newQueue->m_index = 0;
	sem_init(&newQueue->m_readSem, 0, 0);
	sem_init(&newQueue->m_writeSem, 0, capacity);
	pthread_mutex_init(&newQueue->m_mutex, NULL);

	*queue = newQueue;

}

void writeQueue(Queue* queue, void* msg)
{
	if(!queue||!msg)return;
	sem_wait(&queue->m_writeSem);
	pthread_mutex_lock(&queue->m_mutex);

	queue->m_array[queue->m_index] = msg;
	queue->m_index++;
	sem_post(&queue->m_readSem);
	pthread_mutex_unlock(&queue->m_mutex);

}

void readQueue(Queue* queue, void** msg)
{
	if(!queue)return;
	sem_wait(&queue->m_readSem);
	pthread_mutex_lock(&queue->m_mutex);

	*msg = queue->m_array[queue->m_index];
	queue->m_index--;

	pthread_mutex_unlock(&queue->m_mutex);
	sem_post(&queue->m_writeSem);

}