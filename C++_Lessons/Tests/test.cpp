#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
#include <stdio.h>
using namespace std;

int main(int argc, char const *argv[])
{
	FILE* file = fopen("test.txt", "r");
	cout << file << endl;
	return 0;

}