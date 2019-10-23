#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
#include <stdio.h>
using namespace std;

int main(int argc, char const *argv[])
{
	FILE* file = fopen("test.bin", "r");
	int num[] = {999, 888, 777};

	int retval = fwrite((void*)&num, sizeof(int), 3, file);
	cout<<retval<<endl;

	// fclose(file);

	// file = fopen("test.bin", "r");
	// int num2 = 123;

	// int retval2 = fread((void*)&num2, sizeof(int), 1, file);

	// cout << retval2 << " " << num2 << endl;

	return 0;

}