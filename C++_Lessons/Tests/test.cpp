#include <iostream>
using namespace std;

class base
{
public:

	virtual void foo2()
	{
		cout<<"BASE::FOO2"<<endl;
	}
	virtual void foo()
	{
		cout<<"BASE::FOO"<<endl;
	}
};

class drv:public base
{
public:
	void foo2()
	{
		cout<<"DRV::FOO2"<<endl;
	}
	void foo()
	{
		cout<<"DRV::FOO"<<endl;
	}

	virtual void foo3()
	{
		cout<<"DRV::FOO3"<<endl;
	}
};


class drv2:public drv
{
public:
	void foo2()
	{
		cout<<"DRV2::FOO2"<<endl;
	}
	void foo()
	{
		cout<<"DRV2::FOO"<<endl;
	}
	virtual void foo3()
	{
		cout<<"DRV2::FOO3"<<endl;
	}
};

int main(int argc, char const *argv[])
{
	drv2 d;
	base* b = &d;
	b->foo3();

	return 0;
}