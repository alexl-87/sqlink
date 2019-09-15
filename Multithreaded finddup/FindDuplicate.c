#include "H_Hash.h"
#include "DirWalk.h"
#include "MD5_calculator.h"
#include "strQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#define CAPACITY 10000000

HashMap* 			hMap;
SQueue* 			squeue;
char* 				dirPath;
int 				result = 0;
int 				boolLoop = 1;
userHashFunction 	hashFunc;
userCompareFunction compareFunc;
onFileFoundedAction onFileAction;

void 		init();
void* 		HashInsertThread(void* arg);
void* 		DirWalkThread(void* arg);
void 		queuePush(char* dirWalkRetVal);
exeStatus 	perfectHash(void* key, unsigned long* index);
exeStatus 	compareKeys(void* key_1, void* key_2);

int main(int argc, char const* argv[])
{
	int i = 0;
	pthread_t dirWalkThread;
	pthread_t* hashInsertThread;
	hashInsertThread = malloc(sizeof(pthread_t)*5);
	if(!hashInsertThread)exit(1);

	system("clear");

	if(argc>1)dirPath = (char*)argv[1];
	else dirPath = ".";

	init();
	
	pthread_create(&dirWalkThread, NULL, DirWalkThread, NULL);
	for(i = 0; i < 5; ++i)
	{
		pthread_create(&hashInsertThread[i], NULL, HashInsertThread, NULL);
	}

	pthread_join(dirWalkThread, NULL);
	for(i = 0; i < 5; ++i)
	{
		pthread_join(hashInsertThread[i], NULL);
	}

	destroyHashMap(hMap);

	return 0;
}

/*
	Initialize programm
*/

void init()
{
	hashFunc = perfectHash;
	compareFunc = compareKeys;

	createSQueue(&squeue);

	result = createHashMap(CAPACITY, hashFunc, compareFunc, &hMap);
	if(result != OK) exit(result);
}

void* DirWalkThread(void* arg)
{
	char* terminate;
	onFileAction = queuePush;
	getFiles(dirPath, onFileAction);

	terminate = malloc(8);
	strcpy(terminate, "!@#$%");
	SQueuePush(squeue, terminate);
}

void queuePush(char* dirWalkRetVal)
{	
	int filePathLen;
	char* filePath;

	filePathLen = strlen(dirWalkRetVal);
	filePath = malloc(filePathLen+1);

	if(!filePath)
	{
		printf("malloc failed\n");
		exit(1);
	}

	strcpy(filePath, dirWalkRetVal);

	SQueuePush(squeue, filePath);
}

void* HashInsertThread(void* arg)
{
	char* filePath;
	unsigned char* MD5;
	char* originalValue;

	while(boolLoop)
	{
		SQueuePull(squeue, &filePath);

		if(!filePath)continue;
		if(!strcmp(filePath, "!@#$%"))
		{
			boolLoop = 0;
			break;
		}

		result = calculateMD5(filePath, &MD5);

		if(result)
		{
			printf("MD5 calculation failed\n");
			exit(result);
		}

		result =  insertValue(hMap, (void*) MD5, (void*) filePath);

		if(result == exist)
		{
			result = findValue(hMap, (void*) MD5, (void**) &originalValue);
			printf("**********************************************************************\n\n"
				"File:\t%s\n"
				"Exist in: %s\n\n"
				"**********************************************************************\n", 
				filePath, originalValue);
			free(filePath);
		}
	}	
}

/*
	Hash table functions
*/

exeStatus perfectHash(void* key, unsigned long* index)
{

	unsigned char* thisKey;
	int i = 0;
	int p = 31;
	unsigned long p_pow = 1;
	thisKey = (unsigned char*)key;

	for(i; i<16;i++)
	{
		*index = (*index + (thisKey[i]-'a'+1)*p_pow)%CAPACITY;
		p_pow = (p_pow*p)%CAPACITY;
	}

	return OK;
}

exeStatus compareKeys(void* key_1, void* key_2)
{
	char* thisKey_1;
	char* thisKey_2;

	thisKey_1 = (char*) key_1;
	thisKey_2 = (char*) key_2;
	result = strcmp(thisKey_1, thisKey_2);

	if(result) return False;

	return True;
}