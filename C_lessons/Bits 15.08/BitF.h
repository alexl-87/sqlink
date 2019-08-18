#ifndef BitF
#define BitF

struct BitMap {
	unsigned int m_capacity;
	unsigned char* m_bitMap;
};
typedef struct BitMap BitMap;
typedef int(*bitf)(BitMap* map, unsigned int bit);

BitMap* cteateBM(unsigned int capacity);
void destroyBM(BitMap* map);
int changeCapacity(BitMap* map, unsigned int capacity);
int bitOn(BitMap* map, unsigned int numOfBit);
int bitOff(BitMap* map, unsigned int numOfBit);
int ifOn(BitMap* map, unsigned int numOfBit);
int printChar(BitMap* map, unsigned int numOfBit);


#endif
