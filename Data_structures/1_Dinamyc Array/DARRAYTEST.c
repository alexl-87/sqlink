#include "H_DARRAY.h"
#include <stdio.h>
#include <math.h>
static int result = 0;
void testCreate(darray** dArr);
void testAdd(darray** dArr);
void testItemsNum(darray** dArr);
void testDelete(darray** dArr);
void testGet(darray** dArr);
void testSet(darray** dArr);
void printDarray(darray** dArr);
void testSort(darray** dArr);
int main()
{
	
	darray* dArr;
	srand (time(0));
	system("clear");

	testCreate(&dArr);
	testAdd(&dArr);
	testItemsNum(&dArr);
	testGet(&dArr);
	testSort(&dArr);
	testSet(&dArr);
 	testDelete(&dArr);

return 0;
}


void testCreate(darray** dArr)
{
	result =  darrayCreate(dArr, 20);
	if(result != OK)
	{
		printf("-------------------------\n"
				"Create: **FAILED** \n"
				"-------------------------\n");
		return;
	}
		printf("-------------------------\n"
				"Create: **SUCCSSES**\n"
				"-------------------------\n");
}
void testAdd(darray** dArr)
{
	int i;
	int item;
	for(i = 0; i <= 30; i++)
	{
		item = rand()%100;
		result = darrayAdd(*dArr, item);
		if(result != OK)
		{
			printf("Add item: **FAILED**\n"
					"-------------------------\n");
			return;
		}
	}

	printf("Add item: **SUCCSSES**\n"
			"-------------------------\n");
}

void testItemsNum(darray** dArr)
{
	int num;
	result = darrayItemsNum(*dArr, &num);
	if(result != OK)
		{
			printf("Get num of elements: **FAILED**\n"
					"-------------------------\n");
			return;
		}
	printf("Get num of elements: **SUCCSSES**\n"
			"Num of elements: %d\n"
			"-------------------------\n", num);
}

void testGet(darray** dArr)
{
	int result2 = 0;
	int result3 = 0;
	int _item;
	result = darrayGet(*dArr, 16, &_item);
	result2 = darrayGet(*dArr, -7, &_item);
	result3 = darrayGet(*dArr, 89, &_item);

	if(result != 0 || result2 != 3 || result3 != 3)
	{
		printf("Get item: **FAILED**\n"
				"-------------------------\n");
		return;
	}

	printf("Get item: **SUCCSSES**\n"
			"Item: %d\tIndex: 16\n"
			"-------------------------\n", _item);

}

void testSort(darray** dArr)
{
	printf("Array:\n");
	printDarray(dArr);
	darraySort(*dArr);
	printf("Sorted rray:\n");
	printDarray(dArr);
	printf("-------------------------\n");
}
void printDarray(darray** dArr)
{
	int i = 0;
	int j = 0;
	int _item = 0;
	darrayItemsNum(*dArr, &j);
	for(i; i < j; i++)
	{
		darrayGet(*dArr, i, &_item);
		printf("%d ", _item);
	}
	printf("\n");
}
void testSet(darray** dArr)
{
	int _item = 999999;
	int result2 = 0;
	int result3 = 0;
	result = darraySet(*dArr, 7, _item);
	result2 = darraySet(*dArr, -17, _item);
	result3 = darraySet(*dArr, 99, _item);
	
	if(result != 0 || result2 != 3 || result3 != 3)
	{
		printf("Set item: **FAILED**\n"
				"-------------------------\n");
		return;
	}
	printDarray(dArr);
	printf("Get item: **SUCCSSES**\n"
			"Item: %d\tIndex: 7\n"
			"-------------------------\n", _item);
}

void testDelete(darray** dArr)
{
	int _item = 0;
	int i = 0;
	int num = 0;
	darrayItemsNum(*dArr, &num);;
	for(i; i < num-10; i++)
	{
		result = darrayDelete(*dArr, &_item);
		if(result != OK)
		{
			printf("Delete: **FAILED** \n"
					"-------------------------\n");
			return;
		}
	}
	darrayItemsNum(*dArr, &num);;
	printf("Delete: **SUCCSSES**\n"
			"Items number: %d\n" ,num);
	printDarray(dArr);
	printf("-------------------------\n");
}


