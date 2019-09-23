/*
*** PULL TESTING ***
**** success ******
*/
#include <stdio.h>
void Strcopy(char* source, char* copy);
void Strcat(char* source, char* new_string);
int Strcmp(char* first_str, char* second_str);
int Strlen(char* str);
int main(){
	
	char str1[32];
	char str2[32];
	int function = -1, result = -1;
	printf("Chose a function\n" 
	"1 - Copy first string to second\n"
	"2 - Add second string to first\n"
	"3 - Compare two strings\n");
	scanf("%d", &function);

	printf("Enter first string\n");
	scanf("%s", str1);
	printf("Enter secomd string\n");
	scanf("%s", str2);


	
	switch (function)
	{
		case 1:
		Strcopy(str1, str2);
		printf("The second string is: %s\n", str2);
		break;

		case 2:
		Strcat(str1, str2);
		printf("The first string is: %s\n", str1);
		break;

		case 3:
		result = Strcmp(str1, str2);
		if(result)
			printf("Strings are equal\n");
		else
			printf("Strings are NOT equal\n");
		break;
	}
	
	
	return 0;	
}


void Strcopy(char* source, char* copy){
	int str_len =-1, i = 0;
	str_len = Strlen(source);
	for(i; i < str_len; i++)
		copy[i] = source[i];
	
}
void Strcat(char* source, char* new_string){
	
	int new_string_len = 0, source_str_len = 0, i = 0;
	new_string_len = Strlen(new_string);
	source_str_len = Strlen(source);
	for(i; i < new_string_len; i++, source_str_len++)
	{
		source[source_str_len] = new_string[i];
	}
	

}
int Strcmp(char* first_str, char* second_str){
	int result = 1, i = 0;
	
	while(1)
	{
		if(first_str[i] != second_str[i])	
		{
			result = 0;
			break;
		}
		if(first_str[i] ==0 && second_str[i] == 0)
			break;
		i++;
	}

	return result;
}

int Strlen(char* str){
	int result = 0;
	while(str[result] != 0)
	{
		result ++;
	}
	return result;
}
