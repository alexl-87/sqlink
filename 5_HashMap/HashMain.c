  
#include "H_Hash.h"
#include <stdio.h>
#include <stdlib.h>


void createHashMapTest(HashMap** hMap);
void insertValueTest(HashMap** hMap);
void forEachTest(HashMap** hMap);
void findValueTest(HashMap** hMap);
exeStatus perfectHash(void* key, unsigned long* index);
exeStatus compareKeys(void* key_1, void* key_2);
exeStatus printMap(void* key, void* value);

int main()
{
	HashMap* hMap;
	system("clear");
	createHashMapTest(&hMap);
	insertValueTest(&hMap);
	forEachTest(&hMap);
	findValueTest(&hMap);
	return 0;
}

void createHashMapTest(HashMap** hMap)
{
	userHashFunction hashFunc;
	userCompareFunction compareFunc;
	unsigned long capacity = 10;

	hashFunc = perfectHash;
	compareFunc = compareKeys;

	createHashMap(capacity, hashFunc, compareFunc, hMap);
}

void insertValueTest(HashMap** hMap)
{

	char* key;
	int* value;
	int i = 0;
	for(i; i < 5; i++)
	{
		printf("Insert key\n");
		key = malloc(20);
		scanf("%s", key);
		printf("Insert value\n");
		value = malloc(sizeof(int));
		scanf("%d", value);
		insertValue	(*hMap, (void*) key, (void*) value);
	}
}

void forEachTest(HashMap** hMap)
{
	userForEachFunction forEachFunc;
	forEachFunc = printMap;
	forEach(*hMap, forEachFunc);
}


void findValueTest(HashMap** hMap)
{
	char key[20];
	int* value;
	int result;

	printf("Insert key:\n");
	scanf("%s", key);

	result = findValue(*hMap, (void*) key, (void*) value);

	if(result == True)
	{
		printf("Key: %s\t Value: %d\n",key, *value);
	}

	else
	{
		printf("Not founded\n");
	}
}

exeStatus printMap(void* key, void* value)
{
	char* _key;
	int* _value;
	_key = (char*)key;
	_value = (int*)value;
	printf("Key: %s\t Value: %d\n",_key, *_value);
}

exeStatus perfectHash(void* key, unsigned long* index)
{

	char* thisKey;
	int i = 0;
	int thisIndex = 0;
	thisKey = (char*)key;
	while(thisKey[i] != '\0')
	{
		*index+=thisKey[i];
		i++;
	}
	return OK;
}


exeStatus compareKeys(void* key_1, void* key_2)
{
	char* thisKey_1;
	char* thisKey_2;
	int result = 1;

	thisKey_1 = (char*) key_1;
	thisKey_2 = (char*) key_2;
	result = strcmp(thisKey_1, thisKey_2);

	if(result) return False;

	return True;
}

