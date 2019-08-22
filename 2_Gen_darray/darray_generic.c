#include "darray_generic.h"

struct darray{
	void** m_array;
	size_t m_arrayCapacity;
	size_t m_noe;
};
static void quickSort(darray *dArr, elementCompare compare, int left, int right);
static int swap(void* elemA, void* elemB);
/*
Create array--------
*/

AdtStatus darrayCreate(darray **dArr, size_t initial_capacity)
{
	darray* newArray;
	if(!*dArr || initial_capacity <=0) return paramE;
	
	newArray = malloc(sizeof(darray));
	if(!newArray) return mallocE;
	newArray->m_array = malloc(sizeof(void*)*initial_capacity);
	
	if(!newArray->m_array)
	{
		free(newArray);
		return mallocE;
	}
	newArray->m_arrayCapacity = initial_capacity;
	newArray->m_noe = 0;
	*dArr = newArray;
	
	return OK;
}

/*
Destroy array-------------
*/

AdtStatus darrayDestroy(darray *dArr, elementDestroy destroyFunc, void *context)
{
	int i = 0;
	if(!dArr)
	{
		return paramE;
	}
	
	for(i; i < dArr->m_noe; i++)
	{
		destroyFunc(dArr->m_array[i], context);
	}
	free(dArr);
	return OK;
}

/*
Add item ------------
*/

AdtStatus   darrayAdd(darray *dArr,  void  *_item)
{
	void** temp;
	if(!dArr) return paramE;

	if(dArr->m_noe >= dArr->m_arrayCapacity)
	{
		temp = realloc(dArr->m_array, sizeof(void*)*dArr->m_arrayCapacity*2);
		if(!temp) return reallocE;
		dArr->m_array = temp;
		dArr->m_arrayCapacity *= 2;
	}

	dArr->m_array[dArr->m_noe] = _item;
	dArr->m_noe++;

	return OK;
}

/*
Delete --------------------------
*/

AdtStatus   darrayDelete(darray *dArr,  void** _item)
{
	void** temp;
	if(!dArr) return paramE;
	if(dArr->m_noe < 1) return arrIsEmpty;

	*_item = dArr->m_array[dArr->m_noe-1];
	dArr->m_noe--;

	if(dArr->m_noe <= (dArr->m_arrayCapacity/2))
	{
		temp = realloc(dArr->m_array, sizeof(void*)*((dArr->m_arrayCapacity*3)/4));
		if(!temp) return reallocE;
		dArr->m_array = temp;
		dArr->m_arrayCapacity = ((dArr->m_arrayCapacity*3)/4);
	} 
	return OK;
}

/*
Get item ----------------
*/

AdtStatus darrayGet(darray *dArr, size_t _index, void **_item)
{
	if(!dArr) return paramE;
	if(dArr->m_noe < 1) return arrIsEmpty;
	
	if(dArr->m_noe <= _index || _index < 0) return paramE;

	*_item = dArr->m_array[_index];

	return OK;
}

/*
Set item--------------
*/

AdtStatus   darraySet(darray* dArr, size_t _index, void* _item)
{
	if(!dArr) return paramE;
	if(dArr->m_noe < 1) return arrIsEmpty;
	if(dArr->m_noe <= _index || _index < 0) return paramE;

	dArr->m_array[_index] = _item;

	return OK;
}

/*
Num of items------------
*/

AdtStatus   darrayItemsNum(darray *dArr, int*  _numOfItems)
{
	if(!dArr) return paramE;

	*_numOfItems = dArr->m_noe;

	return OK;		
}

/*
Sorting
*/

AdtStatus darraySort(darray *dArr, elementCompare compare)
{
	if(!dArr || !compare) return paramE;

	quickSort(dArr, compare, 0, dArr->m_noe-1);

	return OK;
}

/*
Quick sort
*/

static void quickSort(darray *dArr, elementCompare compare, int left, int right)
{	
	void* temp;
	int result = 0;
	int pivot = right;
	int originLeft = left;
	int originRight = right;
	if(left >= right) return;
	
	while(left < right)
	{
		while(1)
		{
			result = compare(dArr->m_array[right], dArr->m_array[pivot]);
			/*if right > pivot*/
			if(result == 1) right--;
			else break;
		}
		
		while(1)
		{
			/*If left > pivot*/
			result = compare(dArr->m_array[left], dArr->m_array[pivot]);
			if(result == 1) break;
			else left++;
			
		}
		
		result = swap(dArr->m_array[left], dArr->m_array[right]);
		if(result != OK) break;
	}
	
		result = swap(dArr->m_array[left], dArr->m_array[pivot]);
		if(result != OK) return;
		quickSort(dArr,compare, originLeft, left-1);
		quickSort(dArr,compare, right+1, originRight);
}

/*
Elements swap
*/

static int swap(void* elemA, void* elemB)
{
	void* temp;
	if(!elemA || !elemB) return paramE;
	
	temp = elemA;
	elemA = elemB;
	elemB = temp;
	
	return OK;
}
