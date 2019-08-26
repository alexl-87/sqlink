#include "H_Hash.h"
#include <stdlib.h>

static exeStatus findNode(HashMap* map, void* key, HashMapNode* searchedNode);
static exeStatus createHashNode(void* key, void* vale);

struct HashMapNode
{
	void*		 m_value;
	void*		 m_key;
	HashMapNode* m_next;
};

struct HashMap
{
	unsigned long		 m_capacity;
	HashMapNode**		 m_bucket;
	userHashFunction 	 m_hashFunc;
	userCompareFunction	 m_compareFunc;
};

exeStatus createHashMap(unsigned long capacity, userHashFunction hashFunc, userCompareFunction compareFunc, HashMap** hMap)
{
	HashMap* newMap;
	newMap = malloc(sizeof(HashMap));

	if(!newMap) return mallocE;

	newMap->m_bucket = calloc(capacity*1.5, sizeof(HashMapNode*));
	if(!newMap->m_bucket)
	{
		free(newMap);
		return mallocE;
	}
	newMap->m_capacity = capacity*1.5;
	newMap->m_hashFunc = hashFunc;
	newMap->m_compareFunc = compareFunc;


	*hMap = newMap;
	return OK;
}

exeStatus insertValue(HashMap* map, void* key, void* value)
{
	HashMapNode* newNode;
	HashMapNode* searchedNode;
	int result;

	result = findNode(map, key, searchedNode);
	if(result == True)return Flase;

	result = createHashNode(key, value, newNode);
	if(result)return result;

	else newNode = searchedNode;

	return OK;
}

exeStatus findValue(HashMap* map, void* key, void* value)
{
	HashMapNode* searchedNode;
	int result = -1;
	result = findNode(map, key, searchedNode);

	if(result == True)
	{
		value = searchedNode->m_value;
	}

	return result;
}

exeStatus forEach(HashMap* map, userForEachFunction foreachFunc, void* value)
{
	int i = 0;
	HashMapNode* tempNode;
	if(!map)return paramE;

	for(i; i < map->m_capacity; i++)
	{
		tempNode = map->m_bucket[i];
		while(tempNode)
		{
			foreachFunc(tempNode->m_value);
			tempNode = tempNode->m_next;
		}
	}

}

static exeStatus* createHashNode(void* key, void* value, HashMapNode* newNode)
{
	newNode = malloc(sizeof(HashMapNode));
	if(!newNode)return mallocE;
	newNode->m_key = key;
	newNode->m_value = value;
	newNode->m_next = NULL;

	return OK;
}

static exeStatus findNode(HashMap* map, void* key, HashMapNode* searchedNode)
{

	unsigned long 	index = -1;
	int 			result = 0;
	int 			i = 0;

	result = map->m_hashFunc(key, &index);
	if(result)return hashingE;

	index = index%map->m_capacity;

	searchedNode = map->m_bucket[index];

	while(!searchedNode)
	{
		if(map->compareFunc(key, searchedNode->m_key)) return True;
		searchedNode = searchedNode->m_next;
	}

	return False;
}