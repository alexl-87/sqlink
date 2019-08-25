#include "H_L_list.h"
#include <stdio.h>
#include <stdlib.h>
void createTest();
void flipTest();
void ifLoopTest();
static void printList(Node* list);
Node* list;
int main()
{
	createTest();
	return 0;
}

static void printList(Node* list)
{
	Node* temp;
	Node* tempNext;
	int data = 0;
	if(!list) return;
	temp = list;
	getNext(&temp, &tempNext);
	while(tempNext)
	{
		getData(temp, &data);
		printf("%d->", data);
		getNext(&tempNext, &tempNext);
		getNext(&temp, &temp);
	}
}

void createTest()
{
	createList(&list, 5);
	printList(list);
	("\n-------------------\n");
	destroyList(list);

}

void flipTest()
{
	createList(&list, 15);
	printList(list);
	flipList(&list);
	printList(list);
	("\n-------------------\n");
	destroyList(list);
}

void ifLoopTest()
{

}