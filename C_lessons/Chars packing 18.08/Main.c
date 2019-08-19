#include <stdio.h>
#include "charCompressor.h"
#include <stdio.h>
int main(){

	
	unsigned char str[20];
	char str2[9];
	unsigned char _char = 0;
	unsigned char _char2 = 0;
	unsigned int _rotate = 0;
	unsigned int position = 0;
	unsigned int numOfBits = 0;
/*
	scanf("%s",str);
	compress1(str);
	print(str);*/

	/*scanf("%s",str);
	compress2(str);
	print(str);*/
	
	/*scanf("%c",&_char);
	_char = invert(_char);
	charToBin(str2, _char);
	printf("%s\n", str2);*/

	/*scanf("%c",&_char);
	scanf("%u",&_rotate);
	_char = rotate(_char, _rotate);
	charToBin(str2, _char);
	printf("%s\n", str2);*/
	
	scanf("%c",&_char);
	scanf("%c",&_char2);
	scanf("%u",&position);	
	scanf("%u",&numOfBits);	
	_char = setbits(_char, _char2, position, numOfBits);
	charToBin(str2, _char);
	printf("%s\n", str2);

return 0;
}




