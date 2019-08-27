#include "H_Hash.h"
#include <stdio.h>
#include <stdlib.h>


void createHashMapTest(HashMap** hMap);
void insertValueTest(HashMap** hMap);
void deleteValueTest(HashMap** hMap);
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
	/*deleteValueTest(&hMap);*/

	return 0;
}

void createHashMapTest(HashMap** hMap)
{
	userHashFunction hashFunc = perfectHash;
	userCompareFunction compareFunc = compareKeys;
	unsigned long capacity = 10;
	int result = 0;

	printf("*** CREATE TESTING ***\n");

	result = createHashMap(capacity, NULL, NULL, hMap);
	if(result != paramE) 
	{
		printf("*** NULL ARGUMENTS FAIL ***\n");
		return;
	}
	result = createHashMap(0, hashFunc, compareFunc, hMap);

	if(result != paramE) 
	{
		printf("*** CAPACITY < 0 FAIL ***\n");
		return;
	}

	result = createHashMap(capacity, hashFunc, compareFunc, NULL);
	if(result != paramE) 
	{
		printf("*** NULL MAP FAIL ***\n");
		return;
	}
	result = createHashMap(capacity, hashFunc, compareFunc, hMap);
	if(result != OK) 
	{
		printf("*** NULL MAP FAIL ***\n");
		return;
	}
	printf("*** PASS ***\n");
}

void insertValueTest(HashMap** hMap)
{

	char* key = NULL;
	int* value = NULL;
	int i = 0;
	int result;

	result =  insertValue(*hMap, (void*) key, (void*) value);
	if(result != paramE) 
	{
		printf("*** NULL ARGUMENTS FAIL ***\n");
		return;
	}

	for(i; i < 8; i++)
	{
		printf("Insert key\n");
		key = malloc(20);
		scanf("%s", key);
		printf("Insert value\n");
		value = malloc(sizeof(int));
		scanf("%d", value);
		result = insertValue(*hMap, (void*) key, (void*) value);
	}
		key = malloc(20);
		value = malloc(sizeof(int));
		key = "five";
		*value = 5;
		result = insertValue(*hMap, (void*) key, (void*) value);
		if(result != exist)
		{
			printf("*** ALREADY EXISTING ELEMENT FAIL ***\n");
			free(key);
			free(value);
			return;
		}

	forEachTest(hMap);
	printf("*** PASS ***\n");
}

void deleteValueTest(HashMap** hMap)
{	
	char* key = NULL;
	printf("Insert key\n");
	key = malloc(20);
	scanf("%s", key);
	deleteValue	(*hMap, key);
	forEachTest(hMap);
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
	int* valueAdress;
	int result;

	printf("Insert key:\n");
	scanf("%s", key);

	result = findValue(*hMap, (void*) key, (void**) &valueAdress);

	if(result == True)
	{
		printf("Key: %s\t Value: %d\n",key, *valueAdress);
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