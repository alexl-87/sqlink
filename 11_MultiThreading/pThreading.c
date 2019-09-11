#include "Producers.h"
#include "Consumers.h"
#include "WQueue.h"
#include <pthread.h>

int main()
{
	Queue* ptcQueue;
	Queue* ctpQueue;
	pthread_t* prods;
	pthread_t* consums;
	createQueue(&ptcQueue, 5);
	createQueue(&ctpQueue, 5);
	prods = startProducers(ptcQueue, ctpQueue);
	consums = startConsumers(ptcQueue, ctpQueue);

	joinProducers(prods);
	joinConsumers(consums);

	return 0;
}
