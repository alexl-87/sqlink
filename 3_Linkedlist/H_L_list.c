#include "H_L_list.h"
#include <stdlib.h>
struct Node
{
	int m_data;
	Node* m_next;
};
/*
	Create list
*/

exeStatus createList(Node** node, size_t numOfNodes){
	Node* newNode;
	Node* newNext;
	newNode = malloc(sizeof(Node));
	if(!newNode) return paramE;
	newNode->m_data = 999;
	newNode->m_next = NULL;
	*node = newNode;
	while(numOfNodes != 0)
	{
		newNext = malloc(sizeof(Node));
		if(!newNext) return mallocE;
		newNext->m_data = rand()%200;
		newNext->m_next = NULL;
		newNode->m_next = newNext;
		newNode = newNext;
		numOfNodes--;
	}
	return OK;
}

/*
	Flip list
*/

exeStatus flipList(Node** list)
{
	Node* current;
	Node* currentN;
	Node* currentN_N;
	if(!*list) return paramE;

	current = *list;
	currentN = current->m_next;
	currentN_N = current->m_next->m_next;
	current->m_next = NULL;
	currentN->m_next = current;
	while(currentN_N->m_next)
	{
		current = currentN;
		currentN = currentN_N;
		currentN_N = currentN_N->m_next;
		currentN->m_next = current;
	}
	*list = currentN;
	return OK;
}

/*
	Find middle
*/

exeStatus findMiddle(Node** list, Node** middle )
{
	Node* tempMiddle;
	Node* tempList;
	if(!*list)return paramE;

	tempMiddle = *list;
	tempList = *list;

	while(tempList->m_next->m_next != NULL)
	{
		tempList = tempList->m_next->m_next;
		tempMiddle = tempMiddle->m_next;
	}
	*middle = tempMiddle;

	return OK;
}

/*
	If Loop
*/

exeStatus ifLoop(Node* list)
{
	Node* tail;
	Node* head;
	if(!list)return paramE;
	while(!head->m_next->m_next)
	{
		tail = tail->m_next;
		head = head->m_next->m_next;
		if(tail == head)return True;
	}
	return False;
}

/*
	*****Getters and Setters******
*/

exeStatus getData(Node* list, int* data)
{
	if(!list) return paramE;
	*data = list->m_data;
	return OK;
}

exeStatus setData(Node* list, int data)
{
	if(!list) return paramE;
	list->m_data = data;
	return OK;
}

exeStatus getNext(Node** node, Node** next)
{	
	Node* temp;
	if(!*node) return paramE;
	temp = *node;
	*next = temp->m_next;
	return OK;
}

exeStatus setNext(Node* node, Node* other)
{
	if(!node) return paramE;
	node->m_next = other;
	return OK;
}
/***************************************/

/*
	Find commin
*/

exeStatus findCommin(Node* list_1, Node* list_2, Node* commin)
{
/******************/
	int len_1 = 	0;
	int len_2 = 	0;
	int booLoop = 	0;
	int isLoop_1 = 	0;
	int isLoop_2 = 	0;
	Node* temp_1;
	Node* temp_2;
/******************/

	if(!list_1 || !list_2) return paramE;

	temp_1 = list_1;
	temp_2 = list_2;

	isLoop_1 = ifLoop(list_1);
	isLoop_2 = ifLoop(list_2);

	if(isLoop_1 == 3||isLoop_2 == 3) return False;

	while(booLoop < 2)
	{
		if(temp_1) len_1++;
		else booLoop++;

		if(temp_1) len_2++;
		else booLoop++;
		temp_1 = temp_1->m_next;
		temp_2 = temp_2->m_next;
	}

	if(len_1 < len_2)
	{
		getNElement(list_2, temp_2, len_1);
		getNElement(list_1, temp_1, (len_2-len_1));
	}

	else
	{	
		getNElement(list_1, temp_1, len_2);
		getNElement(list_2, temp_2, (len_1-len_2));
	}

	if(temp_1 == temp_2) commin = temp_1;
	else commin = NULL;

	return OK;
}

/*
	Get N element
*/

exeStatus getNElement(Node* list, Node* element, int N)
{
	int i = 1;
	if(!list) return paramE;
	element = list;

	while(element)
	{
		if(i == N) return True;
		element = element->m_next;
		i++;
	}
	return False;
}

exeStatus destroyList(Node* list)
{
	Node* tempNode_1;
	Node* tempNode_2;
	if(!list) return paramE;

	tempNode_1 = list;
	tempNode_2 = tempNode_1->m_next;

	while(tempNode_2)
	{
		free(tempNode_1);
		tempNode_2 = tempNode_2->m_next;
		tempNode_1 = tempNode_2;
	}

	return OK;
}
