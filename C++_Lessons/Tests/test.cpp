#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
#include <set>
#include <fstream>
//#include <stdio.h>
using namespace std;

int main(int argc, char const *argv[])
{
	fstream f;
	f.open("test.txt", fstream::in);
	string line;

	while(!getline(f, line).fail())
	{
		cout<<line<<endl;
	}
	
}