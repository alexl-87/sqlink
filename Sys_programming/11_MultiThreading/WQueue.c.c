#include "WQueue.h"
#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

struct Queue
{
	void** m_array;
	unsigned int m_capacity;
	pthread_mutex_t m_mutex;
	pthread_cond_t m_read_cv;
	pthread_cond_t m_write_cv;
	int m_index;
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
	pthread_mutex_init(&newQueue->m_mutex, NULL);
	pthread_cond_init(&newQueue->m_write_cv, NULL);
	pthread_cond_init(&newQueue->m_read_cv, NULL);

	*queue = newQueue;

}

void writeQueue(Queue* queue, void* msg)
{
	if(!queue||!msg)return;
	pthread_mutex_lock(&queue->m_mutex);

	while(queue->m_index>=queue->m_capacity)
	{
		pthread_cond_wait(&queue->m_write_cv, &queue->m_mutex); 
	}
	queue->m_array[queue->m_index] = msg;
	queue->m_index++;
	sleep(1);

	pthread_cond_signal(&queue->m_read_cv);
	pthread_mutex_unlock(&queue->m_mutex);

}

void readQueue(Queue* queue, void** msg)
{
	if(!queue)return;
	pthread_mutex_lock(&queue->m_mutex);

	while(queue->m_index < 0)
	{
		pthread_cond_wait(&queue->m_read_cv, &queue->m_mutex); 
	}
	*msg = queue->m_array[queue->m_index-1];
	queue->m_index--;
	sleep(1);
	
	pthread_cond_signal(&queue->m_write_cv);
	pthread_mutex_unlock(&queue->m_mutex);
}