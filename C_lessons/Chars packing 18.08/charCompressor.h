  
#ifndef charCompressor
#define charCompressor

typedef struct Chars{

	unsigned int m_First	:4;
	unsigned int m_Second	:4;

}Chars;

typedef union Union {

	Chars m_chars;
	char m_char;

}Union;

int compress1(unsigned char* str);
int compress2(unsigned char* str);
void charToBin(char* str, unsigned char c);
unsigned char invert(unsigned char _char);
char rotate(unsigned char _char, unsigned int n);
char setbits(unsigned char result, unsigned char source,unsigned int position,unsigned int sourceBits);
char setbits2(unsigned char _char, unsigned int left,unsigned int right, unsigned int value );
void print(unsigned char* str);
#endif
