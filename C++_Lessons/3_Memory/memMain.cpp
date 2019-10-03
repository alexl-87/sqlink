#include "MemManager_t.h"
#include "MemPage_t.h"
#include <iostream>
using namespace std;

void writeTest(memManager_t& manager);
void writePosTest(memManager_t& manager);
void readTest(memManager_t& manager);
void readPostest(memManager_t& manager);
void setDefCapacityTest(memManager_t& manager);
void getDefCapacityTest(memManager_t& manager);
void getCapacityTest(memManager_t& manager);
void getPosTest(memManager_t& manager);
void setPosTest(memManager_t& manager);
void getDataSizeTest(memManager_t& manager);

void printMenu();
void writeMenu();

int sc = 0;
int main(int argc, char const *argv[])
{
	memPage_t page;
	memPool_t pool;
	while(true)
	{
		printMenu();

		switch(sc)
		{
			case 1:
				writeTest(&page);
				break;
			case 2:
				writePosTest(&page);
				break;

			case 3:	
				readTest(&page);
				break;

			case 4:
				readPostest(&page);
				break;

			case 5:
				setDefCapacityTest(&page);
				break;

			case 6:
				getDefCapacityTest(&page);
				break;

			case 7:
				getCapacityTest(&page);
				break;

			case 8:
				setPosTest(&page);
				break;

			case 9:
				getPosTest(&page);
				break;

			case 10:
				getDataSizeTest(&page);
				break;

			default: goto END_TEST;


		}
	}
END_TEST:
	return 0;
}

void writeTest(&page)
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

void writePosTest(&page)
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

void readTest(&page)
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
		page->read((void*) &sh, sizeof(short), position);
		cout<< sh<<endl;
		break;

		case 2:
		page->read((void*) &in, sizeof(int), position);
		cout<< in<<endl;
		break;

		case 3:
		page->read((void*) &lon, sizeof(long), position);
		cout<<lon <<endl;
		break;

		case 4:
		page->read((void*) &fl, sizeof(float), position);
		cout<<fl <<endl;
		break;

		case 5:
		page->read((void*) &doub, sizeof(double), position);
		cout<<doub <<endl;
		break;

		case 6:
		page->read((void*) &ch, sizeof(char), position);
		cout<<ch <<endl;
		break;

		default: break;
	}
}

void readPostest(&page)
{
	writeMenu();

	switch(sc)
	{
		short sh; int in; long lon; float fl;
		double doub; char ch;

		case 1:
		page->read((void*) &sh, sizeof(short));
		cout<< sh<<endl;
		break;

		case 2:
		page->read((void*) &in, sizeof(int));
		cout<< in<<endl;
		break;

		case 3:
		page->read((void*) &lon, sizeof(long));
		cout<<lon <<endl;
		break;

		case 4:
		page->read((void*) &fl, sizeof(float));
		cout<<fl <<endl;
		break;

		case 5:
		page->read((void*) &doub, sizeof(double));
		cout<<doub <<endl;
		break;

		case 6:
		page->read((void*) &ch, sizeof(char));
		cout<<ch <<endl;
		break;

		default: break;
	}
}

void setDefCapacityTest(&page)
{
	cout<<"Insert capacity:"<<endl;
	unsigned int num = 0;
	cin>>num;
	memPage_t::setDefCapacity(num);
}

void getDefCapacityTest(&page)
{
	cout<<memPage_t::getDefCapacity()<<endl;
}

void getCapacityTest(&page)
{
	cout<<page->getCapacity()<<endl;
}

void getPosTest(&page)
{
	cout<<page->getPosition()<<endl;
}

void setPosTest(&page)
{
	cout<<"Insert position:"<<endl;
	unsigned int num = 0;
	cin>>num;
	try
	{
		page->setPosition(num);
	}
	catch(...)
	{
		cout<<"Illegal position"<<endl;
	}
}

void getDataSizeTest(&page)
{
	cout<<page->getDataSize()<<endl;
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