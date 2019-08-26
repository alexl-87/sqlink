#include "H_BST.h"
#include <stdlib.h>

static exeStatus insertion(BTreeNode* previous, BTreeNode** current, long val);
static exeStatus destoyTreeNode(BTreeNode* tree);
static exeStatus checkValue(BTreeNode* tree);
static int searchedVal;
static BTreeNode* tempNode;
struct BTreeNode{
	long m_val;
	BTreeNode* m_left;
	BTreeNode* m_right;
};

exeStatus createTree(BTreeNode** tree, long val)
{
	BTreeNode* newTree;
	if(!tree)return paramE;

	newTree = malloc(sizeof(BTreeNode));
	if(!newTree)return mallocE;

	newTree->m_left = NULL;
	newTree->m_right = NULL;
	newTree->m_val = val;
	*tree = newTree;

	return OK;
}

exeStatus insertElement(BTreeNode* tree, long val)
{
	int result = 0;

	if(!tree) return paramE;

	if(val > tree->m_val)
	{
		result = insertion(tree, &tree->m_right, val);
	}

	else
	{
		result = insertion(tree, &tree->m_left , val);
	}
	return result;
}

static exeStatus insertion(BTreeNode* previous, BTreeNode** current, long val)
{
	BTreeNode* newNode;
	
	if(!(*current))
	{
		createTree(&newNode, val);
		if(!newNode)return mallocE;
		*current = newNode;
		return OK;
	}

	else if(val > (*current)->m_val)
	{
		insertion(*current, &(*current)->m_right, val);
	}

	else
	{
		insertion(*current, &(*current)->m_left, val);
	}
}

exeStatus walk(BTreeNode* treeNode, walkFunc func, Order order, void* context)
{
	if(!treeNode) return OK;

	if(order == pre)func(treeNode);
	walk(treeNode->m_left, func, order, context);
	if(order == in)func(treeNode);
	walk(treeNode->m_right, func, order, context);
	if(order == post)func(treeNode);
}

exeStatus destoyTree(BTreeNode* treeNode)
{
	walkFunc freeFunc;
	freeFunc = destoyTreeNode;
	if(!treeNode) return paramE;
	walk(treeNode, freeFunc, in, NULL);
}

static exeStatus destoyTreeNode(BTreeNode* tree)
{
	if(!tree) return paramE;

	free(tree);

	return OK;
}

exeStatus getVal(BTreeNode* tree, int* val)
{
	if(!tree) return paramE;

	*val = tree->m_val;
	return OK;

}

exeStatus deleteNode(BTreeNode* tree, int val)
{
	if(!tree) return paramE;
	findNode(tree, val)
}

exeStatus findNode(BTreeNode* tree, int val)
{
	walkFunc searchNode;
	searchNode = checkValue;
	searchedVal = val;
	walk(tree, searchNode, in, NULL);
}

static exeStatus checkValue(BTreeNode* tree)
{
	if(!tree) return False;

	if(tree->m_right->m_val == searchedVal || tree->m_left->m_val == searchedVal)
	{
		tempNode = tree;
	}
	else tempNode = NULL;
	return OK;
}