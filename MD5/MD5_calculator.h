#ifndef MD5_calculator
#define MD5_calculator

enum MD5Status {OK, mallocE, paramE, fopenE};

typedef enum MD5Status MD5Status;

MD5Status calculateMD5(char* filePath, unsigned char* MD5);
MD5Status convertMD5ToNum(unsigned long* hash, unsigned char* MD5);

#endif