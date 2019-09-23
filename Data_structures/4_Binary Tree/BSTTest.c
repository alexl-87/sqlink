#include "H_BST.h"
#include <stdio.h>
#include <stdlib.h>
void createTreeTest();
void insertest();
void printTree();

exeStatus printVal(BTreeNode* tree);
int main()
{
	system("clear");
	srand(time(0));
	createTreeTest();
	insertest();
	return 0;
}

void createTreeTest()
{
	BTreeNode* tree;
	int result = 0;
	int val = 1;
	printf("\n\n****CREATE TEST****\n\n");

	result = createTree(&tree, val);
	if(result)
	{
		printf("****FAILED****\n");
		return;
	}
	destoyTree(tree);
	printf("****SUCCESS****\n");
}

void insertest()
{
	BTreeNode* tree;
	int val = 23;
	int result;
	int i = 0;
	printf("\n\n****INSERT TEST****\n\n");
	result = createTree(&tree, val);
	if(result)
	{
		printf("Creatintg tree FAILED\n");
	}
	
	for(i; i<10; i++)
	{
		val = rand()%78;
		result = insertElement(tree, val);
		if(result)
		{
			printf("****FAILED****\n");
			return;
		}
	}
	printTree(tree);
	destoyTree(tree);
	printf("****SUCCESS****\n");
}

void printTree(BTreeNode* tree)
{
	walkFunc func;
	func = printVal;
	walk(tree, func, in, NULL);
	printf("\n");
}

exeStatus printVal(BTreeNode* tree)
{
	int val;
	if(!tree) return paramE;
	getVal(tree, &val);
	printf("%d ", val);
}