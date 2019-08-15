#include "BitF.h"
#include <stdio.h>
int main(){

	unsigned int choice = 0, boolLoop = 1, capacity = 0, numOfFic = 0 ;
	BitMap* map;
	bitf bitFunc[4] = {bitOn, bitOf, ifOn, printChar};
	printf("Inser features capacity\n");
	scanf("%u",&capacity);
	map = cteateBM(capacity);
	while(boolLoop && map)
	{	
		printf("1 - Turn on bit\n"
			"2 - Turn of bit\n"
			"3 - Check if on\n");
		scanf("%u",&choice);

		printf("Insert number of feature\n");
		scanf("%u",&numOfFic);
		switch(choice)
		{
			case 1:
			/*bitFunc[3](map, numOfFic);*/
			bitFunc[0](map, numOfFic);
			break;
				
			case 2:
			bitFunc[3](map, numOfFic);
			bitFunc[1](map, numOfFic);
			break;

			case 3:
			bitFunc[3](map, numOfFic);
			bitFunc[2](map, numOfFic);
			break;
			
			default: boolLoop = 0; break;

		}
		bitFunc[3](map, numOfFic);

	}

	destroyBM(map);
	return 0;
}
