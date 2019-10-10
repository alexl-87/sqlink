#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	vector<char> v(23);
	v[0] = 'c';

	for (vector<char>::iterator i = v.begin(); i != v.end(); ++i)
	{
		cout<<*i<<endl;
	}
	return 0;
}