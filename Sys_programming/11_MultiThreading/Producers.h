#ifndef Producers
#define Producers
#include "WQueue.h"
#include <pthread.h>

typedef struct Producer Producer;

pthread_t* startProducers(Queue* ptcQueue, Queue* ctpQueue);
void joinProducers(pthread_t* threads);
void* producerThread(void* arg);

#endif