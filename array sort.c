#include <stdio.h>
void sort(int* array, int array_size);
void Swap(int* num1, int* num2);
void print(int* array, int array_size);
int main(){
	int i = 0;

	int array[8];
	printf("Enter array elements\n");
	for(i; i < 8; i++)
	{
		scanf("%d", &array[i]);
	}
	sort(array, 8);
	print(array, 8);

}


void sort(int* array, int array_size){
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

void Swap(int* num1, int* num2){

	int temp = 0;
	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

void print(int* array, int array_size){
	int i = 0;
	for(i; i<array_size; i++)
	{
		printf("%d, ", array[i]);
	}
	printf("\n");
}
