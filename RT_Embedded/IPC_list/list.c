#include "list.h"
#include <stdlib.h>

node* create_node(void* data)
{
	node* newNode = 0;
	if(data)
	{
		newNode = (node*)malloc(sizeof(node));
	}
	return newNode;
}

void push(list* list, node* newNode)
{

	if(list && newNode)
	{
		if (list->m_length == 0)
		{
			list->head = newNode;
			list->tail = newNode;
			list->m_length = 1;
		}

		else
		{
			list->tail->m_next = newNode;
			list->tail = newNode;
			++list->m_length;
		}
	}

}

node* pop(list* list)
{
	node* retVal = 0;
	if(list && list->m_length > 0)
	{
		retVal = list->head;
		list->head = retVal->m_next;
		--list->m_length;
	}
	return retVal;
}