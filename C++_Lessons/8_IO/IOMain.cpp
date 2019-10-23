#include "VirtIO_t.h"
#include "AsciiIO_t.h"
#include <string>
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	asciiIO_t t;
	asciiIO_t::mode m = asciiIO_t::r;
	t.fOpen("test.txt", m);
	int num = 0;
	t>>num;
	cout << num << endl;
	return 0;
}