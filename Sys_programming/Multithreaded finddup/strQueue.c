#include "strQueue.h"
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

static void createNewNode(char* path, SNode** node);

struct SNode
{
	char* m_path;
	SNode* m_next;
};

struct SQueue
{
	SNode* m_tail;
	SNode* m_head;
	pthread_mutex_t	m_mutex;
};

void createSQueue(SQueue** sQueue)
{
	SQueue* newQueue;
	if (!sQueue)return;

	newQueue = malloc(sizeof(SQueue));

	if(!newQueue)return;

	newQueue->m_head = NULL;
	newQueue->m_tail = NULL;
	pthread_mutex_init(&newQueue->m_mutex, NULL);

	*sQueue = newQueue;
}


void SQueuePush(SQueue* queue, char* path)
{
	SNode* newNode;
	if(!path || !queue)return;

	createNewNode(path, &newNode);

	if(!queue->m_head)
	{
		queue->m_head = newNode;
		queue->m_tail = newNode;
	}

	else if(queue->m_head == queue->m_tail)
	{
		queue->m_head->m_next = newNode;
		queue->m_tail = queue->m_head->m_next;
	}

	else 
	{
		queue->m_tail->m_next = newNode;
		queue->m_tail = queue->m_tail->m_next;
	}
}


void SQueuePull(SQueue* queue, char** path)
{
	SNode* temp;
	if(!queue || !path)return;
	if(!queue->m_head)return;

	pthread_mutex_lock(&queue->m_mutex);
	*path = queue->m_head->m_path;
	temp = queue->m_head;
	queue->m_head = queue->m_head->m_next;
	pthread_mutex_unlock(&queue->m_mutex);
}

void destroySQueue(SQueue* queue)
{
	SNode* temp;
	if(!queue) return;

	while(queue->m_head)
	{
		temp = queue->m_head;
		queue->m_head = queue->m_head->m_next;
		free(temp);
	}
}

static void createNewNode(char* path, SNode** node)
{
	SNode* newNode;
	if(!path||!node)return;

	newNode = malloc(sizeof(SNode));

	if(!newNode)return;

	newNode->m_path = path;
	newNode->m_next = NULL;

	*node = newNode;
}