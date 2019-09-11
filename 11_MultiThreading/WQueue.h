#ifndef WQueue
#define WQueue

typedef struct Queue Queue;
void createQueue(Queue** queue, unsigned int capacity);
void writeQueue(Queue* queue, void* msg);
void readQueue(Queue* queue, void** msg);

#endif