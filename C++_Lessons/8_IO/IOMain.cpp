#include "VirtIO_t.h"
#include "AsciiIO_t.h"
#include "BinIO_t.h"
#include <string>
#include <iostream>
using namespace std;

void tryAscci();
void tryBinary();
int main(int argc, char const *argv[])
{
	char opt = ' ';
	cout << "Ascii or binary, that is the question - a/b?" << endl;
	cin>>opt;
	if(opt == 'a') tryAscci();
	if(opt == 'b') tryBinary();

	return 0;
}

void tryAscci()
{
	int opt = 0;
	int num = 0;
	asciiIO_t asc;
	asc.Open("test.txt", "r");
	while(true)
	{
		cout<<"1 - read\t2 - write"<<endl;
		cin>>opt;

		switch(opt)
		{
			case 1:
			asc>>num;
			cout<<num<<endl;
			break;

			case 2:
			cout << "Insert value" << endl;
			cin >> num;
			asc<<num;
			break;
		};
	}

}

void tryBinary()
{
	binIO_t bin;
}
