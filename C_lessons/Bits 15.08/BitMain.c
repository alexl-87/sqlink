#include "BitF.h"
#include <stdio.h>
int main(){

	unsigned int choice = 0, boolLoop = 1, capacity = 0, numOfFic = 0 ;
	int result = 0;
	BitMap* map;
	bitf bitFunc[5] = {bitOn, bitOff, ifOn, printChar, changeCapacity};
	system("clear"); 
	printf("Inser features capacity\n");
	scanf("%u",&capacity);
	map = cteateBM(capacity);
	while(boolLoop)
	{	
		printf("1 - Turn on bit\n"
			"2 - Turn off bit\n"
			"3 - Check if on\n"
			"4 - change capacity\n");
		scanf("%u",&choice);

		switch(choice)
		{

			case 1:
			printf(	"\n---------------------------\n"
			"Insert number of feature\n");
			scanf("%u",&numOfFic);
			printf("Before:\t");
			bitFunc[3](map, numOfFic);
			bitFunc[0](map, numOfFic);
			break;
				
			case 2:
			printf(	"\n---------------------------\n"
			"Insert number of feature\n");
			scanf("%u",&numOfFic);
			printf("Before:\t");
			bitFunc[3](map, numOfFic);
			bitFunc[1](map, numOfFic);
			break;

			case 3:
			printf(	"\n---------------------------\n"
			"Insert number of feature\n");
			scanf("%u",&numOfFic);
			bitFunc[3](map, numOfFic);
			result = bitFunc[2](map, numOfFic);
			(result)?printf("Bit is on\n"):printf("Bit is off\n");
			break;

			case 4:	
			printf("Inser features capacity\n");
			scanf("%u",&capacity);
			bitFunc[4](map, capacity);
			break;
			
			default: boolLoop = 0; break;

		}
		printf("After:\t");
		bitFunc[3](map, numOfFic);

	}

	destroyBM(map);
	return 0;
}
