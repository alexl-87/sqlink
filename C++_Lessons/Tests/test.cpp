#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
#include <stdio.h>
using namespace std;

int main(int argc, char const *argv[])
{
	FILE* file = fopen("test.txt", "r");
	int res = fprintf(file, "%s\n", "TEST" );
	cout << res << endl;
	// int num = 56;
	// int num2 = 87;
	// int res = fscanf(file, "%d", &num);
	// res = fscanf(file, "%d", &num2);
	// cout << num << "  " << num2 << "    " << res << "   " << feof(file) << endl;
	return 0;

}