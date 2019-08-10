#include <stdio.h>
#include "HW_functions.h"
int main(){

	int result = 0;
	int function = -1;
	int loop = 1;
	char _string[100];
	char substring[100];
	long decimal = 0;
	char binary[65];
	system("clear");
	while(loop)
	{
		printf("\vChose a function:\nLocation - 1\n"
				"String squeez - 2\n"
				"Bin2Int - 3\n"
				"Int2Bin - 4\n"
				"Exit - 5\n");
		scanf("%d", &function);

		switch (function)
		{
			case 1:
		
				printf("\nInsert string\n");
				scanf("%s", _string);
				printf("\nInsert substring\n");
				scanf("%s", substring);
				result = Location(_string, substring);
				printf("\nResult: %d\n", result);
				break;

			case 2:
			
				printf("\nInsert string\n");
				scanf("%s", _string);
				printf("\nInsert set of chars\n");
				scanf("%s", substring);
				squeeze(_string, substring);
				printf("Result: %s\n", _string);
				break;
				
			case 3:
				printf("\nInsert binary number: ");
				scanf("%s", _string);
				printf("\vDecimal =  %d\n", Bin2Int(_string));
				break;

			case 4:
				printf("\nInsert decimal number: ");
				scanf("%ld", &decimal);
				result = Int2Bin(decimal, binary);
				printf("\vBinary = %s\n",binary);
				break;
			
			default: loop = 0; break;
		}

	}
	return 0;
}
