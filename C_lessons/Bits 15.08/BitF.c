#include <stdio.h>
#include "BitF.h"
#include <stdlib.h>

static void charToBin(char* str, unsigned char c);

BitMap* cteateBM(unsigned int capacity){
	
	BitMap* map;
	
	map = malloc(sizeof(BitMap));
	
	if(!map) return NULL;

	map->m_bitMap = malloc(sizeof(char)*((capacity)/8+1));

	if(!map->m_bitMap)
	{
		free(map);
		return NULL;
	}
	
	map->m_capacity = capacity;
	
	return map;
}

int changeCapacity(BitMap* map, unsigned int capacity){

	int result = capacity;
	unsigned char* temp;
	if(!map) return 0;

	if((map->m_capacity/8)+1 < (capacity/8)+1)
	{
		temp = (unsigned char*) realloc(map->m_bitMap, sizeof(char)*((capacity)/8+1));
			
		if (!temp) 
		{
			result = 0;
		}
		else 
		{
			map->m_bitMap = temp;

		}
	}
	map->m_capacity = capacity;
	return result;
}



void destroyBM(BitMap* map){
	
	if(!map) return;
	free(map->m_bitMap);
	free(map);
}

int bitOn(BitMap* map, unsigned int numOfBit){
	
	int i = 0,bit = 0;
	char shift = 1;	

	if(!map) return 0;
	if(map->m_capacity < numOfBit) return -1;
	
	i = numOfBit/8;

	(!(numOfBit%8))?i--:i;

	bit = numOfBit%8;
	(bit == 0)?(bit+=8):bit;
	shift <<= bit%9-1;
	map->m_bitMap[i] = map->m_bitMap[i]|shift;

	return numOfBit;	
}
int bitOff(BitMap* map, unsigned int numOfBit){

	int i = 0,bit = 0;
	char shift = 1;	

	if(!map) return 0;
	if(map->m_capacity < numOfBit) return 1;
	
	i = numOfBit/8;

	(!(numOfBit%8))?i--:i;

	bit = numOfBit%8;
	(bit == 0)?(bit+=8):bit;
	shift <<= bit%9-1;
	shift =~ shift;
	map->m_bitMap[i] = map->m_bitMap[i]&shift;

	return numOfBit;	
}

int ifOn(BitMap* map, unsigned int numOfBit){

	int i = 0,bit = 0;
	char shift = 1;	

	if(!map) return 0;
	if(map->m_capacity < numOfBit) return -1;
	
	i = numOfBit/8;

	(!(numOfBit%8))?i--:i;

	bit = numOfBit%8;
	(bit == 0)?(bit+=8):bit;
	shift <<= bit%9-1;
	shift = map->m_bitMap[i]&shift;
	
	if(shift) return 1;

	return 2;
}

int printChar(BitMap* map, unsigned int numOfBit){
	int i = 0;
	char str[9];
	if(!map) return 0;
	
	i = numOfBit/8;

	(!(numOfBit%8))?i--:i;

	charToBin(str, map->m_bitMap[i]);
	printf("%s\n", str);
	return 1;
}
static void charToBin(char* str, unsigned char c){

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

