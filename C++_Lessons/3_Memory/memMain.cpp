#include "MemManager_t.h"
#include "MemPage_t.h"
#include <iostream>
using namespace std;

void writeTest();
void writePosTest();
void readTest();
void readPostest();
void setDefCapacityTest();
void getDefCapacityTest();
void getCapacityTest();
void getPosTest();
void setPosTest();
void getDataSizeTest();

void printMenu();
void writeMenu();
memPage_t page;
int sc = 0;
int main(int argc, char const *argv[])
{
	
	while(true)
	{
		printMenu();

		switch(sc)
		{
			case 1:
				writeTest();
				break;
			case 2:
				writePosTest();
				break;

			case 3:	
				readTest();
				break;

			case 4:
				readPostest();
				break;

			case 5:
				setDefCapacityTest();
				break;

			case 6:
				getDefCapacityTest();
				break;

			case 7:
				getCapacityTest();
				break;

			case 8:
				setPosTest();
				break;

			case 9:
				getPosTest();
				break;

			case 10:
				getDataSizeTest();
				break;

			default: goto END_TEST;


		}
	}
END_TEST:
	return 0;
}

void writeTest()
{
	writeMenu();
	switch(sc)
	{
		short sh; int in; long lon; float fl;
		double doub; char ch;

		case 1:
		cout<<"Insert value:"<<endl;
		cin>>sh;
		page.write((void*) &sh, sizeof(short));
		break;

		case 2:
		cout<<"Insert value:"<<endl;
		cin>>in;
		page.write((void*) &in, sizeof(int));
		break;

		case 3:
		cout<<"Insert value:"<<endl;
		cin>>lon;
		page.write((void*) &lon, sizeof(long));
		break;

		case 4:
		cout<<"Insert value:"<<endl;
		cin>>fl;
		page.write((void*) &fl, sizeof(float));
		break;

		case 5:
		cout<<"Insert value:"<<endl;
		cin>>doub;
		page.write((void*) &doub, sizeof(double));
		break;

		case 6:
		cout<<"Insert value:"<<endl;
		cin>>ch;
		page.write((void*) &ch, sizeof(char));
		break;

		default: break;
	}
}

void writePosTest()
{
	writeMenu();
	unsigned int position;
	cout<<"Insert position:"<<endl;
	cin>>position;

	switch(sc)
	{
		short sh; int in; long lon; float fl;
		double doub; char ch;

		case 1:
		cout<<"Insert value:"<<endl;
		cin>>sh;
		page.write((void*) &sh, sizeof(short), position);
		break;

		case 2:
		cout<<"Insert value:"<<endl;
		cin>>in;
		page.write((void*) &in, sizeof(int), position);
		break;

		case 3:
		cout<<"Insert value:"<<endl;
		cin>>lon;
		page.write((void*) &lon, sizeof(long), position);
		break;

		case 4:
		cout<<"Insert value:"<<endl;
		cin>>fl;
		page.write((void*) &fl, sizeof(float), position);
		break;

		case 5:
		cout<<"Insert value:"<<endl;
		cin>>doub;
		page.write((void*) &doub, sizeof(double), position);
		break;

		case 6:
		cout<<"Insert value:"<<endl;
		cin>>ch;
		page.write((void*) &ch, sizeof(char), position);
		break;

		default: break;
	}
}

void readTest()
{
	writeMenu();
	unsigned int position;
	cout<<"Insert position:"<<endl;
	cin>>position;

	switch(sc)
	{
		short sh; int in; long lon; float fl;
		double doub; char ch;

		case 1:
		page.read((void*) &sh, sizeof(short), position);
		cout<< sh<<endl;
		break;

		case 2:
		page.read((void*) &in, sizeof(int), position);
		cout<< in<<endl;
		break;

		case 3:
		page.read((void*) &lon, sizeof(long), position);
		cout<<lon <<endl;
		break;

		case 4:
		page.read((void*) &fl, sizeof(float), position);
		cout<<fl <<endl;
		break;

		case 5:
		page.read((void*) &doub, sizeof(double), position);
		cout<<doub <<endl;
		break;

		case 6:
		page.read((void*) &ch, sizeof(char), position);
		cout<<ch <<endl;
		break;

		default: break;
	}
}

void readPostest()
{
	writeMenu();

	switch(sc)
	{
		short sh; int in; long lon; float fl;
		double doub; char ch;

		case 1:
		page.read((void*) &sh, sizeof(short));
		cout<< sh<<endl;
		break;

		case 2:
		page.read((void*) &in, sizeof(int));
		cout<< in<<endl;
		break;

		case 3:
		page.read((void*) &lon, sizeof(long));
		cout<<lon <<endl;
		break;

		case 4:
		page.read((void*) &fl, sizeof(float));
		cout<<fl <<endl;
		break;

		case 5:
		page.read((void*) &doub, sizeof(double));
		cout<<doub <<endl;
		break;

		case 6:
		page.read((void*) &ch, sizeof(char));
		cout<<ch <<endl;
		break;

		default: break;
	}
}

void setDefCapacityTest()
{
	cout<<"Insert capacity:"<<endl;
	unsigned int num = 0;
	cin>>num;
	memPage_t::setDefCapacity(num);
}

void getDefCapacityTest()
{
	cout<<memPage_t::getDefCapacity()<<endl;
}

void getCapacityTest()
{
	cout<<page.getCapacity()<<endl;
}

void getPosTest()
{
	cout<<page.getPosition()<<endl;
}

void setPosTest()
{
	cout<<"Insert position:"<<endl;
	unsigned int num = 0;
	cin>>num;
	try
	{
		page.setPosition(num);
	}
	catch(...)
	{
		cout<<"Illegal position"<<endl;
	}
}

void getDataSizeTest()
{
	cout<<page.getDataSize()<<endl;
}

void printMenu()
{
	cout<<"1 - Write\t\t2 - Write in pos\t3 - Read\t\t4 - Read in pos\n"
		<<"5 - set def capacity\t6 - get def cpacity\t7 - Get capacity\n"
		<<"8 - Set position\t9 - Get position\t10 - Get data size"<<endl;
		cin>>sc;
}

void writeMenu()
{
	cout<<"1 - short\t2 - int\t\t3 - long\n"
		<<"4 - float\t5 - double\t6 - char"<<endl;
	cin>>sc;
}