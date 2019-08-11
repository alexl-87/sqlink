#include <stdio.h>
#include <stdlib.h>
#include "DM_functions.h"

int* insert(int** array_address, int* index, int num, int* array_size){
	
	int* temp = *array_address;

	if(*index >= *array_size)
	{
		temp = (int*) realloc(*array_address, sizeof(num)*(*array_size)*2);
	}
	else \
		
	{
		printf("Cant allocate more memory");
		return *array_address;
	}
	else
	{
		array_address = &temp;
		*array_address[*index] = num;
		*array_size = sizeof(num)*(*array_size)*2;
		return *array_address;
	}

	return NULL;
}
