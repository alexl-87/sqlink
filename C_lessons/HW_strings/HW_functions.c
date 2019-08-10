#include <stdio.h>
#include <string.h>
#include <math.h>
#include "HW_functions.h"

/*
Location
*/
int Location(char* _string, char* substring){
	
	int string_len = strlen(_string);
	int substring_len = strlen(substring);
	int i = 0, j = 0;
	int sufpref[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};	

	sufpref_tab(substring, sufpref, substring_len);

	while(i != string_len )
	{
		if (j == (substring_len))
			return (i-j+1);

		if(_string[i] == substring[j])
		{
			i++; j++;
		}

		else if(j == 0)
			i++;

		else
			j = sufpref[j-1];	
	}

	return -1;
}

void sufpref(char* substring, int* sufpref, int substring_len){
	
	int i = 0, j = 1;
	sufpref[0] = 0;

	while(j < substring_len)
	{
		if(substring[j] == substring[i])
		{
			sufpref[j] = i+1;
			i++;
			j++;
		}
		else if(i==0)
		{
			sufpref[j] = 0;
			j++;	
		}
		else
			i = sufpref[i-1];
	}
}

/*
Squeeze string
*/

void squeeze(char* _string, char* chars){

	int num_of_chars = strlen(chars);
	int string_len = strlen(_string);
	int bool_shrink = 0, start_index = -1;
	int i = 0, j = string_len-1;

	for(i; i < num_of_chars; i++)
	{	
		for(j; j >=0 ; j--)
		{
			if(_string[j] == chars[i])
			{
				_string[j]='\0';
				bool_shrink = 1;
				start_index = j;
			}
			
			if(bool_shrink)
				shrink(_string, &string_len, start_index);
	
			bool_shrink = 0;
		}
		j=string_len-1;
	}
	printf("Start index: %d\n", start_index);
}

void shrink(char* _string, int* string_len, int start_index){
	
	int j = start_index+1;
	
	while(j != *string_len)
	{
		if(_string[j] == '\0')
			j++;
		
		else
		{
			_string[start_index] = _string[j];
			start_index++; j++;			
		}		
	}
	*string_len = start_index;
	_string [start_index] = '\0';
}

/*
Bin2Int
*/

int Bin2Int(char* Bin){

	int Int = 0;
	int Bin_len = strlen(Bin)-1;
	int Pow = 0;

	while(Bin_len >= 0)
	{
		if(Bin[Bin_len] == '1')
			Int += ((int) pow(2, Pow));
		if(Bin[Bin_len] != '1' && Bin[Bin_len] != '0')
		{
			printf("Incorrect input\n");
			return -1;
		}

		Pow++;
		Bin_len--;
	}

	return Int;
}

/*
Int2Bin
*/

int Int2Bin(long decimal, char result[65]){
	
	int i = 0;

	if(decimal < 0)
		decimal*=-1;

	while (decimal > 0)
	{
		(decimal%2 ==0)?(result[i] = '0'):(result[i] = '1');
		decimal /= 2;
		i++;
	}
	result[i] = '\0';

	reverse_binary(result, i-1);

	return 1;
}

void reverse_binary(char result[65], int end_of_binary){

	int i = 0, temp;
	while(i < end_of_binary)
	{
		temp = result[i];
		result[i] = result[end_of_binary];
		result[end_of_binary] = temp;
		i++;
		end_of_binary--;
	}
}
