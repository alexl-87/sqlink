#include "AsciiIO_t.h"
#include <string>
using namespace std;
asciiIO_t::asciiIO_t(){}

asciiIO_t::asciiIO_t(const string& path, const string& mode)
:virtIO_t(path, mode){}

asciiIO_t::~asciiIO_t(){}


virtIO_t& asciiIO_t::operator>>(int& num)
{
	return Read(num, "%d");

}

virtIO_t& asciiIO_t::operator<<(int num)
{
	return Write(num, "%d");
}
