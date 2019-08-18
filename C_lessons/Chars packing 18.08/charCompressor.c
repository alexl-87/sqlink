#include "charCompressor.h"
#include <stdlib.h>
#include <math.h>
int compress1(unsigned char* str){
	unsigned char tempChar1;
	unsigned char tempChar2;
	unsigned int i = 0;
	unsigned int j = 0;
	if(!str) return 0;

	while(str[j] != '\0')
	{
		tempChar2 = str[j]-'a';
		tempChar1 = str[j+1]-'a';
		str[i] = '\0';
		tempChar2 <<= 4;
		str[i] = str[i]|tempChar1;
		str[i] = str[i]|tempChar2;
		i++;
		j+=2;
	}
	str[i] = '\0';

	return i;
}

int compress2(unsigned char* str){

	Union un;
	int size = 10;
	int i = 0;
	int j = 0;
	if(!str) return 0;

	while(str[j] != '\0')
	{
		un.m_chars.m_First = str[j+1]-'a';
		un.m_chars.m_Second = str[j]-'a';
		str[i] = un.m_char;
		i++;
		j+=2;
	}
	str[i] = '\0';
	
	return j;
}

unsigned char invert(unsigned char _char){
	
	return _char^255;
}

char rotate(unsigned char _char, unsigned int n){

	char temp1 = 0;
	char temp2 = 0;

	temp1 = _char/pow(2,n);
	temp2 = (_char%((char)pow(2,n)))*((char)pow(2,(8-n)));
	
	_char = temp1|temp2;
	return _char;
}

char setbits(unsigned char result, unsigned char source,unsigned int position,unsigned int sourceBits){

	char lastBits = 0;
	char left = 0;
	char right = 0;
	if(sourceBits > position) return 0;

	lastBits = source%((char)pow(2,sourceBits));
	left = result/((char)pow(2,position));
	right = result%((char)pow(2,position-sourceBits));
	left <<= position;
	lastBits <<= position-sourceBits;
	result = lastBits|left|right;
	
	return result;
}

char setbits2(unsigned char _char, unsigned int left,unsigned int right, unsigned int value ){

	unsigned char comp = 0;
	int i = 0;
	for(i; i <= (left-right); i++)
	{
		comp = (comp*2)+1;
	}
	comp <<= right;
	
	if(value == 0)
	{
		comp = ~comp;
		_char = _char&comp;
	}
	
	else
	{
		_char = _char|comp;
	}


	return _char;
}

void charToBin(char* str, unsigned char c){

	int i = 7;

	if(!str) return;

	str[8] = '\0';
	
	while(c != 0)
	{
		if(c%2 == 0)
			str[i] = '0';
		else
			str[i] = '1';
		c/=2;
		i--;
	}
	
	for(i; i >-1; i--)
	{
		str[i] = '0';
	}
}

