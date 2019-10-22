#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
using namespace std;

template <class T>
void func(T t)
{
	cout << typeid(t).name() << endl;
}


int main(int argc, char const *argv[])
{
	short num = 99;
	func<short>(num);
	return 0;
}