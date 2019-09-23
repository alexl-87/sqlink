#ifndef H_L_list
#define H_L_list
#include <stddef.h>

typedef struct Node Node;
typedef enum  {paramE, OK, mallocE, True, False} exeStatus;

exeStatus createList	(Node** node, size_t numOfNodes);
exeStatus flipList		(Node** list);
exeStatus findMiddle	(Node** list, Node** middle);
exeStatus ifLoop		(Node* list);
exeStatus getData		(Node* list, int* data);
exeStatus getNext		(Node** node, Node** next);
exeStatus setData		(Node* list, int data);
exeStatus setNext		(Node* node, Node* next);
exeStatus findCommin	(Node* list_1, Node* list_2, Node* commin);
exeStatus getNElement	(Node* list, Node* element, int N);
exeStatus destroyList	(Node* list);

#endif