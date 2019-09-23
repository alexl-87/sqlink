#ifndef strQueue
#define strQueue

typedef struct SQueue SQueue;
typedef struct SNode SNode;

void createSQueue(SQueue** sQueue);
void SQueuePush(SQueue* queue, char* path);
void SQueuePull(SQueue* queue, char** path);
void destroySQueue(SQueue* queue);

#endif