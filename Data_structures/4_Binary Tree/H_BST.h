#ifndef H_BST
#define H_BST

enum exeStatus	{OK, paramE, mallocE, True, False};
enum Order 		{in, pre, post};

typedef struct 	BTreeNode 	BTreeNode;
typedef enum 	exeStatus 	exeStatus;
typedef enum 	Order 		Order;

typedef exeStatus (*walkFunc)(BTreeNode* tree);

exeStatus createTree	(BTreeNode** tree, long val);
exeStatus insertElement	(BTreeNode* tree, long val);
exeStatus walk 			(BTreeNode* tree, walkFunc func, Order order, void* context);
exeStatus destoyTree	(BTreeNode* tree);
exeStatus getVal		(BTreeNode* tree, int* val);
exeStatus deleteNode	(BTreeNode* tree, int val);
exeStatus findNode		(BTreeNode** parentNode, BTreeNode** searchedNode , int val);


#endif