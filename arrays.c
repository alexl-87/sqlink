#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void bubble_sort(int* array, int array_size);
void odd_even(int* array, int array_size);
void Swap(int* num1, int* num2);
void print_array(int* array, int array_size);
void numbers_counter (int* array, int array_size);
void play_loto();
void print_loto_card(char loto_card[6][11]);
void empty_loto_card(char loto_card[6][11]);
void set_array(int* array);

int main(){
	int choice = -1;

	int array[8];
	printf("Chose a function:\n 1 - ascending sort, 2 - odd-even sort, 3 - numbers counter, 4 - Play loto\n");
	scanf("%d", &choice);

	
	

	switch (choice)
	{
		case 1:
		set_array(array);
		bubble_sort(array, 8);
		print_array(array, 8);
		break;

		case 2:
		set_array(array);
		odd_even(array, 8);	
		print_array(array, 8);
		break;

		case 3:
		set_array(array);
		numbers_counter (array, 8);
		break;

		case 4:
		play_loto();
		
	}

	
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

void odd_even(int* array, int array_size){
	
	int last_even_index = -1,last_odd_index = -1, i = 0, unsorted_size = array_size;
	while(1)
	{
		for(i; i < unsorted_size; i++)
		{
			if (array[i]%2 != 0 && i !=unsorted_size-1 && i > last_even_index)
				last_even_index = i;
			else if (array[i]%2 == 0 && i > last_odd_index)
				last_odd_index = i;
		}

		if(last_even_index > last_odd_index || last_even_index == -1)
			break;

		else
		{
			for(last_even_index; last_even_index < last_odd_index; last_even_index++)
			{
				Swap(&array[last_even_index], &array[last_even_index+1]);
			}		
			unsorted_size = last_even_index;
			last_even_index = -1;
			last_odd_index = -1;
			i = 0;
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

		if (temp_counter > counter)
		{
			result = current_int;
			counter = temp_counter;
		}

	printf("The result is: %d, appears %d times\n", result, counter);
}

/*
Play loto
*/

void play_loto(){
	int chosen_numbers = 0, random_int = 0;
	char loto_card[6][11];
	srand(time(NULL));
	empty_loto_card(loto_card);
	printf("Numbers are: ");
	while (chosen_numbers < 6)
	{
		random_int = rand()%49+1;

		if(loto_card[random_int/10+1][random_int%10+1] != '+')
		{
			loto_card[random_int/10+1][random_int%10+1] = '+';
			printf("%d, ", random_int);
			chosen_numbers++;
		}	
	}
	
	print_loto_card(loto_card);

}


/* 
Empty loto card
*/

void empty_loto_card(char loto_card[6][11]){
	int raw = 0, col = 0, char_digits = 47;
	for(raw; raw < 6; raw++)
		for(col=0; col < 11; col++)
		{
			if(raw == 0 && col > 0)
				loto_card[raw][col] = (char) char_digits+col;

			else if(col ==0 && raw > 0)
				loto_card[raw][col] = (char) char_digits+raw;
			else
				loto_card[raw][col] = '-';
			
		}
}

/*
Print loto card
*/

void print_loto_card(char loto_card[6][11]){
	int raw = 0, col = 0;
	printf("\n");
	for(raw; raw < 6; raw++)
	{
		for(col=0; col < 11; col++)
		{
			printf("%c ", loto_card[raw][col]);
		}
		printf("\n");
	}
}


/* 
	Print array
*/

void print_array(int* array, int array_size){
	int i = 0;
	for(i; i<array_size; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

/*
Set array
*/

void set_array(int* array){
	int i = 0;
	printf("Enter array elements\n");
	for(i; i < 8; i++)
	{
		scanf("%d", &array[i]);
	}
}
