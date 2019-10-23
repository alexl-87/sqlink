#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
#include <stdio.h>
using namespace std;

int main(int argc, char const *argv[])
{
	FILE* file = fopen("test.txt", "r");
	int num = 4343499;
	cout << fprintf(file, "%d", num) << endl << num << endl;
	return 0;

}