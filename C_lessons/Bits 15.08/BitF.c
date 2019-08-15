#include <stdio.h>
#include "BitF.h"
#include <stdlib.h>
static int Int2Bin(int decimal, char result[65]);
BitMap* cteateBM(unsigned int capacity){
	
	BitMap* map;
	
	map = malloc(sizeof(BitMap));
	
	if(!map) return NULL;

	map->m_bitMap = malloc(sizeof(char)*((capacity)/8+1));

	if(!map->m_bitMap) destroyBM(map);
	
	map->m_capacity = (capacity%8+1)*8;
	
	return map;
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
	if(map->m_capacity < bit) return 0;
	
	i = numOfBit/8;
	bit = numOfBit%8;
	shift <<= bit;
	map->m_bitMap[i] = map->m_bitMap[i]|shift;

	return 1;	
}
int bitOf(BitMap* map, unsigned int numOfBit){

	int i = 0,bit = 0;
	char shift = 1;	

	if(!map) return 0;
	if(map->m_capacity < bit) return 0;
	
	i = numOfBit/8;
	bit = numOfBit%8;
	shift <<= bit;
	shift =~ shift;
	map->m_bitMap[i] = map->m_bitMap[i]&shift;

	return 1;	
}
int ifOn(BitMap* map, unsigned int numOfBit){

	int i = 0,bit = 0;
	char shift = 1;	

	if(!map) return -1;
	if(map->m_capacity < bit) return 0;
	
	i = numOfBit/8;
	bit = numOfBit%8;
	shift <<= bit;
	shift = map->m_bitMap[i]&shift;
	
	if(!shift) return 1;

	return 0;
}
int printChar(BitMap* map, unsigned int numOfBit){

	char Bin[65];
	if(!map) return 0;

	Int2Bin((int) map->m_bitMap[numOfBit/8], Bin);
	printf("%s\n", Bin);

	return 1;
}
static int Int2Bin(int decimal, char result[65]){
	
	int i = 64;

	if(decimal < 0)
		decimal*=-1;

	while (decimal > 0)
	{
		(decimal%2 ==0)?(result[i] = '0'):(result[i] = '1');
		decimal /= 2;
		i--;
	}
	result[i] = '\0';

	return 1;
}

