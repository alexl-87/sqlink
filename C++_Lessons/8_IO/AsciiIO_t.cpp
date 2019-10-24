#include "AsciiIO_t.h"
#include <string>
using namespace std;
asciiIO_t::asciiIO_t(){}

asciiIO_t::asciiIO_t(const string& path, const string& mode)
:virtIO_t(path, mode){}

asciiIO_t::~asciiIO_t(){}


asciiIO_t& asciiIO_t::operator>>(short& num){return Read(num, "%hd");}
asciiIO_t& asciiIO_t::operator<<(short num){return Write(num, "%hd");}

asciiIO_t& asciiIO_t::operator>>(int& num){return Read(num, "%d");}
asciiIO_t& asciiIO_t::operator<<(int num){return Write(num, "%d");}

asciiIO_t& asciiIO_t::operator>>(long& num){return Read(num, "%u");}
asciiIO_t& asciiIO_t::operator<<(long num){return Write(num, "%u");}

asciiIO_t& asciiIO_t::operator>>(char& num){return Read(num, "%c");}
asciiIO_t& asciiIO_t::operator<<(char num){return Write(num, "%c");}

asciiIO_t& asciiIO_t::operator>>(float& num){return Read(num, "%f");}
asciiIO_t& asciiIO_t::operator<<(float num){return Write(num, "%f");}

asciiIO_t& asciiIO_t::operator>>(double& num){return Read(num, "%f");}
asciiIO_t& asciiIO_t::operator<<(double num){return Write(num, "%f");}

asciiIO_t& asciiIO_t::operator>>(unsigned short& num){return Read(num, "%d");}
asciiIO_t& asciiIO_t::operator<<(unsigned short num){return Write(num, "%d");}

asciiIO_t& asciiIO_t::operator>>(unsigned int& num){return Read(num, "%u");}
asciiIO_t& asciiIO_t::operator<<(unsigned int num){return Write(num, "%u");}

asciiIO_t& asciiIO_t::operator>>(unsigned long& num){return Read(num, "%lu");}
asciiIO_t& asciiIO_t::operator<<(unsigned long num){return Write(num, "%lu");}

asciiIO_t& asciiIO_t::operator>>(unsigned char& num){return Read(num, "%d");}
asciiIO_t& asciiIO_t::operator<<(unsigned char num){return Write(num, "%d");}
