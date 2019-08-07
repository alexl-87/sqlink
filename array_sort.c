#include <stdio.h>
void bubble_sort(int* array, int array_size);
void odd_even(int* array, int array_size);
void Swap(int* num1, int* num2);
void print_array(int* array, int array_size);
void numbers_counter (int* array, int array_size);
int main(){
	int i = 0, choice = -1;

	int array[8];
	printf("Enter array elements\n");
	for(i; i < 8; i++)
	{
		scanf("%d", &array[i]);
	}
	
	printf("Chose a function:\n 1 - ascending sort, 2 - odd-even sort, 3 - numbers counter");
	scanf("%d", &choice);
	switch (choice)
	{
		case 1:
		bubble_sort(array, 8);
		break;

		case 2:
		odd_even(array, 8);	
		break;

		case 3:
		numbers_counter (array, 8);
		break;
		
	}

	print_array(array, 8);
	return 0;

}

/*
Sort array in ascending number
*/

void bubble_sort(int* array, int array_size){
	int swap = 1;
	int i = 0;
	while(swap)
	{
		swap = 0;
		i = 0;
		for(i; i < array_size-1; i++)
		{
			if(array[i] > array[i+1])
			{
				Swap(&array[i], &array[i+1]);
				swap = 1;
			}
		}
	}
	
}
/*
Sort array by odd and even numbers
*/
void odd_even(int* array, int array_size)
{
	int swap = 1;
	int i = 0;
	while(swap)
	{
		swap = 0;
		i = 0;
		for(i; i < array_size-1; i++)
		{
			if((array[i]%2 != 0) && (array[i+1]%2 == 0))
			{
				Swap(&array[i], &array[i+1]);
				swap = 1;
			}
		}
	}

}

/*
Swap between two integers
*/

void Swap(int* num1, int* num2){

	int temp = 0;
	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

/*
 Numbers counter
*/

void numbers_counter (int* array, int array_size){

	int counter = 0, temp_counter = 1, i = 1, result = 0, current_int = 0;
	bubble_sort(array, array_size);
	current_int = array[0];

	for(i; i < array_size; i++)
	{
		if(array[i]==current_int)
			temp_counter++;
		else if (temp_counter > counter)
		{
			result = current_int;
			counter = temp_counter;
			temp_counter = 1;
			current_int = array[i];
		}
		else
		{
			temp_counter = 1;
			current_int = array[i];
		}
	}
	printf("The result is: %d, appears %d times\n", result, counter);
}


/* 
Print array
*/

void print_array(int* array, int array_size){
	int i = 0;
	for(i; i<array_size; i++)
	{
		printf("%d, ", array[i]);
	}
	printf("\n");
}
