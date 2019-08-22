#include "darray_generic.h"
#include <stdio.h>
FILE* carLog;
void destroyCar(void *_elem, void *context);
void compareCar(void *_elemA, void *_elemB);

/****TESTS****/
void CreateTest(darray** dArr);
void addTest(darray** dArr);
void itemsNumTest(darray** dArr);
void getTest(darray** dArr);
void setTest(darray** dArr);
void sortTest(darray** dArr);
void destroyTest(darray** dArr);
/************/

void elemDestroy(void *_elem, void *context);
int speedCompare (void* _elemA, void* _elemB);
typedef struct Car{

	int maxSpeed;
	int capacity;
	
}Car;

int main(){
	
	darray* dArr;
	system("clear");
	srand(time(0));
	CreateTest(&dArr);
	addTest(&dArr);
	itemsNumTest(&dArr);
	getTest(&dArr);
	sortTest(&dArr);
	destroyTest(&dArr);
	return 0;
}

/*
Create test
*/

void CreateTest(darray** dArr)
{
	int result = 1;
	printf("-----------Create test------------\n");

	result =  darrayCreate(dArr, 2);

	if(result) printf("**FAILED**\n");
	else printf("**SUCCESS**\n");
}

/*
Add test
*/

void addTest(darray** dArr){

	int i = 0;
	int result = 0;
	Car* newCar;
	printf("-----------Add test------------\n");
	for(i; i < 8; i++)
	{
		newCar = malloc(sizeof(Car));
		if(!newCar)
		{
			printf("Car malloc error\n");
			return;
		}
		newCar->capacity = (rand()%15)+2;
		newCar->maxSpeed = (rand()%200)+100;
		result = darrayAdd(*dArr,  (void*)  newCar);
		if(result)
		{
			printf("**FAILED**\n");
			return;
		}
	}

	printf("**SUCCESS**\n");

}

/*
Get num of items test
*/

void itemsNumTest(darray** dArr)
{
	int num = 0;
	int result = 0;
	printf("-----------Num of items test------------\n");
	result = darrayItemsNum(*dArr, &num);
	if(result)
	{
		printf("**FAILED**\n");
		return;
	}
	printf("**SUCCESS**\n"
			"Num of items: %d\n", num);
}
/*
Get test
*/
void getTest(darray** dArr)
{
	int negativeIndex = 0;
	int overflowIndex = 0;
	int validIndex = 0;
	Car* newCar = malloc(sizeof(Car));
	printf("-----------Get items test------------\n");
	if(!newCar)
	{
		printf("newCar allocation error\n");
		return;
	}
	negativeIndex = darrayGet(*dArr, -7, (void**) &newCar);
	overflowIndex = darrayGet(*dArr, 99, (void**) &newCar);
	validIndex = darrayGet(*dArr, 3, (void**) &newCar);

	if(negativeIndex != 4 || overflowIndex != 4 || validIndex != 0)
	{
		printf("**FAILED**\n");
		return;
	}

	printf("Index: 3\tMax speed %d\t Car capacity %d\n"
		"**SUCCESS**\n", newCar->maxSpeed, newCar->capacity);
}

/*
Sort test
*/

void sortTest(darray** dArr)
{	
	elementCompare sppedComp;
	sppedComp = speedCompare;
	darraySort(*dArr, sppedComp); 
}

/*
Destroy test
*/

void destroyTest(darray** dArr)
{
	int result = 0;
	elementDestroy destroy;
	destroy = elemDestroy;
	printf("-----------Destroy test------------\n");

	result = darrayDestroy(*dArr, destroy, stdout);

	if(result)
	{
		printf("**FAILED**\n");
		return;
	}
	printf("**SUCCESS**\n");
}


/*
Pointer function speed compare
*/

int speedCompare (void *_elemA, void *_elemB)
{
	Car* c1;
	Car* c2;
	if(!_elemA || !_elemB) return 0;
	c1 = (Car*) _elemA;
	c2 = (Car*) _elemB;
	if(c1->maxSpeed > c2->maxSpeed) return 1;
	else return 2;

}

/*
Pointer function element destroy
*/

void elemDestroy(void *_elem, void *context)
{
	Car* tempCar;
	FILE* tempFile;
	if(!_elem || !context) return;

	tempFile = (FILE*) context;
	tempCar = (Car*) _elem;

	fprintf(tempFile, "Destroyed car max speed: %d\tcapacity %d\n", tempCar->maxSpeed, tempCar->capacity);
	
	free(tempCar);
}

