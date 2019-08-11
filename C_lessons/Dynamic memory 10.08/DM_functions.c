#include <stdio.h>
#include <stdlib.h>
#include "DM_functions.h"

int insert(d_array* array, int* index, int number){
	
	int* temp;
	if (array == NULL)
	{
		printf("E: array = NULL");
		return 0;
	}	
	
	if (*index < 0)
	{
		printf("Index cant be negative");
		return 0;
	}
	
	temp = array->arr;

	if(*index >= array->capacity)
	{
		temp = (int*) realloc(array->arr, sizeof(int)*(*index+1));
		if(temp == NULL)
		{
			return 0;
		}
		else
		{
			array->arr = temp;
			array->capacity = (*index)+1;
		}
	}
	
	array->arr[*index] = number;

	return 1;
}

int print_array(d_array* array){
	
	int i = 0;
	if (array == NULL)
	{
		printf("E: array = NULL");
		return 0;
	}	
	
	for(i; i < array->capacity; i++)
		printf("%d ", array->arr[i]);
	printf("\n");

}
d_array* array_builder(int _capacity){
	
	d_array* array;
	
	if(_capacity < 1)
	{
		printf("Array's capacity cant be < 0\n");
		return NULL;
	}	
	
	array = malloc(sizeof(d_array));
	if(array ==NULL)
	{
		printf("Unable to allocate memory for requested array\n");
		return NULL;
	}
	array->arr = malloc(_capacity*sizeof(int));
	if(array ==NULL)
	{
		printf("Unable to allocate memory for requested array\n");
		free(array);
		return NULL;
	}
	array->capacity = _capacity;
	array->index = 0;
	
	return array;
}

void destroy(d_array* array){
	free(array->arr);
	free(array);
}
