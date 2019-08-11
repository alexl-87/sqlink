#include <stdio.h>
#include <stdlib.h>
#include "DM_functions.h"

int main(){
	
	int capacity, index, number, bool_while = 1, choice;
	d_array* array;
	
	printf("Chose array size\n");
	scanf("%d", &capacity);
	array = array_builder(capacity);

	while(bool_while)
	{

		printf("Insert number - 1\nPrint array - 2\nExit - 3\n");
		scanf("%d", &choice);
		system("clear");		
	
		switch (choice)
		{
			case 1:
			printf("\nInsert index: ");
			scanf("%d", &index);
	
			printf("\nInsert number: ");
			scanf("%d", &number);
			insert(array, &index, number);
		
			print_array(array);
			break;
			
			case 2:
			print_array(array);
			break;

			default: bool_while = 0; break;
		}
	}
	destroy(array);
	return 0;
}
