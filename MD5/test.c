#include <stdlib.h>
#include <string.h>

int main()
{
	unsigned char* MD5;
	char* filePath = malloc(64);
	strcpy(filePath, "test.c");
	calculateMD5(filePath, MD5);

    return(0);        
}