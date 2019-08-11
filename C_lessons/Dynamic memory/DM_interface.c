#include <stdio.h>
#include <stdlib.h>
#include "DM_functions.h"

int main(){

	int* array, i = 0, index = 4, num = 999;
	int array_size = 8;
	array =(int*) calloc(array_size, sizeof(int));
	
	insert(&array, &index, num, &array_size);

	for(i; i < array_size; i++)
	{
		printf("%d ", array[i]);
	}
	
	

	return 0;
}
