#include <stdlib.h>
#include "H_DARRAY.h"

struct darray{
	int* array;
	size_t arrayCapacity;
	size_t noe;
};

/*
Create array
*/

AdtStatus darrayCreate(darray **dArr, size_t initial_capacity)
{
	darray* newArray;
	newArray = malloc(sizeof(darray));
	if(!newArray) return mallocE;

	newArray->array = malloc(sizeof(int)*initial_capacity);
	if(!newArray->array)
	{
		free(newArray);
		return mallocE;
	}
	
	newArray->arrayCapacity = initial_capacity;
	newArray->noe = 0;
	*dArr = newArray;
	
	return OK;

}

/*

Destroy array
*/

AdtStatus darrayDestroy(darray *dArr)
{
	if(dArr)
	{
		free(dArr->array);
	}

	free(dArr);

	return OK;
}

/*
Add item
*/

AdtStatus darrayAdd(darray *dArr,  int  _item)
{
	int* temp;
	if(!dArr) return paramE;

	if(dArr->noe >= dArr->arrayCapacity)
	{
		temp = realloc(dArr->array, sizeof(int)*dArr->arrayCapacity*2);
		if(!temp) return reallocE;
		dArr->array = temp;
		dArr->arrayCapacity *= 2;
	}

	dArr->array[dArr->noe] = _item;
	dArr->noe++;

	return OK;
}

/*
Delete
*/

AdtStatus   darrayDelete(darray *dArr,  int* _item)
{
	int* temp;
	if(!dArr) return paramE;

	*_item = dArr->array[dArr->noe-1];

	

	if(dArr->noe <= (dArr->arrayCapacity/2))
	{
		temp = realloc(dArr->array, sizeof(int)*((dArr->arrayCapacity*3)/4));
		if(!temp) return reallocE;
		dArr->array = temp;
		dArr->arrayCapacity = ((dArr->arrayCapacity*3)/4);
	} 

	dArr->noe--;
	return OK;
}

/*
Get item
*/

AdtStatus   darrayGet(darray *dArr, size_t _index, int *_item)
{
	if(!dArr) return paramE;

	if(dArr->noe < _index || _index < 0) return paramE;

	*(_item) = dArr->array[_index];

	return OK;
	
}

/*
Set item
*/

AdtStatus   darraySet(darray *dArr, size_t _index, int  _item)
{
	if(!dArr) return paramE;

	if(dArr->noe < _index || _index < 0) return paramE;

	dArr->array[_index] = _item;

	return OK;
}

/*
Num of items
*/

AdtStatus   darrayItemsNum(darray *dArr, int*  _numOfItems)
{
	if(!dArr) return paramE;

	*(_numOfItems) = dArr->noe;

	return OK;		
}

/*
Sorting
*/

AdtStatus darraySort(darray *dArr)
{
	int swap = 1;
	int j = 0;
	int i = 1;
	int endOfArr = 0;
	int temp;
	if(!dArr) return paramE;

	while(swap)
	{
		swap = 0;
		for(i = 0, j = 1; j < dArr->noe-endOfArr; i++, j++)
		{
			if(dArr->array[i]>dArr->array[j])
			{
				temp = dArr->array[i];
				dArr->array[i] = dArr->array[j];
				dArr->array[j] = temp;
				swap = 1;
			}
		}
		endOfArr++;
	}

	return OK;
}
