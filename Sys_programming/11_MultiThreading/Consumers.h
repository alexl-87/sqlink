#ifndef Consumers
#define Consumers
#include "WQueue.h"
#include <pthread.h>

typedef struct Consumer Consumer;

pthread_t* startConsumers(Queue* ptcQueue, Queue* ctpQueue);
void joinConsumers(pthread_t* threads);
void* consumerThread(void* arg);

#endif