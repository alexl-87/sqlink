#include "MemManager_t.h"
#include "MemPage_t.h"
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	memPage_t page;
	int i = 10;
	int j = 8;
	cout<<page.getDefCapacity()<<endl;
	cout<<page.getCapacity()<<endl;
	page.write((void*)&i, sizeof(int));
	page.read((void*) &j, sizeof(int), 0);
	cout<<j<<endl;
	return 0;
}