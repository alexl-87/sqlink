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
int bitOn(BitMap* map, unsigned int numOfBit);
int bitOf(BitMap* map, unsigned int numOfBit);
int ifOn(BitMap* map, unsigned int numOfBit);
int printChar(BitMap* map, unsigned int numOfBit);

#endif
