#include <stdio.h>
#include <stdlib.h>
#include "DM_functions.h"

int insert(d_array* array, int* index, int number){
	
	int* temp = array->arr;
	if (*index < 0)
	{
		printf("Index cant be negative");
		return -1;
	}

	if(*index >= array->capacity)
	{
		temp = (int*) realloc(array->arr, sizeof(int)*(*index+1));
		if(temp == NULL)
		{
			return -1;
		}
		else
		{
			array->arr = temp;
			array->capacity = sizeof(int)*(*index+1);
		}
	}
	
	array->arr[*index] = number;

	return 1;
}

void print_array(d_array* array){
	
	int i = 0;

	for(i; i < array->capacity; i++)
		printf("%d ", array->arr[i]);
	printf("\n");

}
d_array* array_builder(int _capacity){
	
	d_array* array;
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
	
	return array;
}

void destroy(d_array* array){
	free(array->arr);
	free(array);
}
