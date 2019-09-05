#include <openssl/md5.h> /* -c -lcrypto*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "MD5_calculator.h"


MD5Status calculateMD5(char* filePath, unsigned char* MD5)
{
	int i;
	MD5_CTX c;
	char buf[512];
	ssize_t bytes;
	FILE* file;

	if(!filePath)return paramE;

	MD5 = malloc(MD5_DIGEST_LENGTH);
	if(!MD5)return mallocE;

	file = fopen(filePath, "r");
	if(!file)return fopenE;

	MD5_Init(&c);
	bytes=read(3, buf, 512);

	while(bytes > 0)
	{
		MD5_Update(&c, buf, bytes);
		bytes=read(3, buf, 512);
	}

	MD5_Final(MD5, &c);

	for(i=0; i<MD5_DIGEST_LENGTH; i++)
	{
		printf("%02x ", MD5[i]);
	}
	fclose(file);
	return OK;
}

MD5Status convertMD5ToNum(unsigned long* hash, unsigned char* MD5)
{

}