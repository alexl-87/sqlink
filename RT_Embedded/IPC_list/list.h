#ifndef list
#define list
#include <stdlib.h>

typedef struct node node;
typedef struct list list;

struct node
{
	void* m_data;
	node* m_next;
};

struct list
{
	node* m_head;
	node* m_tail;
	size_t m_length;
};

node* create_node(void* data);
void push(list* list, node* newNode);
node* pop(list* list);

#endif