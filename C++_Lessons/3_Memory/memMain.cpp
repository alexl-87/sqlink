#include "MemManager_t.h"
#include "MemPage_t.h"
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	memPage_t page;
	cout<<page.getDefCapacity()<<endl;
	cout<<page.getCapacity()<<endl;
	return 0;
}