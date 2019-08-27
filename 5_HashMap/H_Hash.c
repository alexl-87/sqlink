#include "H_Hash.h"
#include <stdlib.h>

static exeStatus findValueIndex(HashMap* map, void* key, unsigned long* retIndex);
static exeStatus createHashNode(void* key, void* value, HashMapNode** newNode);

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

	int result = 0;
	unsigned long retIndex = 0;
	HashMapNode* newNode;
	HashMapNode* tempNode;

	result = findValueIndex(map, key, &retIndex);
	if(result == True)return False;

	result = createHashNode(key, value, &newNode);
	if(result)return result;

	if(!map->m_bucket[retIndex])
	{
		map->m_bucket[retIndex] = newNode;
	} 

	else
	{
		tempNode = map->m_bucket[retIndex];
		map->m_bucket[retIndex] = newNode;
		newNode->m_next = tempNode;
	}

	return OK;
}

exeStatus findValue(HashMap* map, void* key, void* value)
{
	unsigned long retIndex = 0;
	int result = -1;
	HashMapNode* tempNode;
	result = findValueIndex(map, key, &retIndex);

	tempNode = map->m_bucket[retIndex];

	while(tempNode)
	{
		result = map->m_compareFunc(key, tempNode->m_key);
		if(result == True)
		{
			value = tempNode->m_value;
			return result;
		}
		tempNode = tempNode->m_next;
	}
	return False;
}

exeStatus forEach(HashMap* map, userForEachFunction foreachFunc)
{
	int i = 0;
	HashMapNode* tempNode;
	if(!map)return paramE;

	for(i; i < map->m_capacity; i++)
	{
		tempNode = map->m_bucket[i];
		while(tempNode)
		{
			foreachFunc(tempNode->m_key, tempNode->m_value);
			tempNode = tempNode->m_next;
		}
	}

}

static exeStatus createHashNode(void* key, void* value, HashMapNode** newNode)
{

	*newNode = malloc(sizeof(HashMapNode));
	if(!*newNode)return mallocE;

	(*newNode)->m_key = key;
	(*newNode)->m_value = value;
	(*newNode)->m_next = NULL;

	return OK;
}

static exeStatus findValueIndex(HashMap* map, void* key, unsigned long* retIndex)
{
	int result = 0;

	result = map->m_hashFunc(key, retIndex);
	if(result)return hashingE;

	*retIndex = *retIndex%map->m_capacity;
	return OK;
}