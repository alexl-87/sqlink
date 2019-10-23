#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
#include <stdio.h>
using namespace std;

int main(int argc, char const *argv[])
{

	double num = 255.6;

	char c = *typeid(num).name();
	cout << c << endl;
	return 0;

}