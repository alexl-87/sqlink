#include "VirtIO_t.h"
#include "AsciiIO_t.h"
#include "BinIO_t.h"
#include "TExeption_t.h"
#include <string>
#include <iostream>
using namespace std;
void asciiTest(virtIO_t* file);
void binarytest(virtIO_t* file);
void open(virtIO_t* file);
int main(int argc, char const *argv[])
{

	virtIO_t* file;
	char fileType;
	while(true)
	{
		cout << "Binary or ascii, that is the question? a/b" << endl;
		cin>>fileType;
		if (fileType == 'a')
		{
			file = new asciiIO_t();
			asciiTest(file);
			delete file;
			cin.clear();
		}

		else if(fileType == 'b')
		{
			file = new binIO_t();
			binarytest(file);
			delete file;
			cin.clear();
		}
		else
		return 0;
	}
	return 0;
}

void asciiTest(virtIO_t* file)
{
	int opt;
	int var = 89;
	int loop = true;
	while(loop)
	{
		try
		{
			cout<<"1 - Open file\t\t2 - Close file\t3 - Read" << endl
			<<"4 - Write\t\t5 - Read/write\t6 - Get position" << endl
			<<"7 - Set position\t8 - get lenght"<<endl;
			
			cin>>opt;
			
			switch(opt)
			{
				case 1:
				open(file);
				break;

				case 2:
				file->Close();
				break;

				case 3:
				*file>>var;
				cout<<"result = "<<var<<endl;
				break;

				case 4:
				cout<<"Insert value for writing:" << endl;
				cin>>var;
				*file<<var;
				break;

				case 5:
				break;

				case 6:
				cout<<"Position: " <<file->getPosition()<<endl;
				break;

				case 7:
				cout<<"Insert position:"<<endl;
				cin>>var;
				file->setPosition((unsigned int)var);
				break;

				case 8:
				cout<<"Lenght: " << file->getPosition()<<endl;
				break;

				default:
				loop = false;
				break;
			};
		}

		catch(tExeption_t<string, string, int> exept)
		{
			cout << exept << endl;
		}
	}
}

void binarytest(virtIO_t* file)
{
	int opt;
	int var = 89;
	int loop = true;
	while(loop)
	{
		try
		{
			cout<<"1 - Open file\t\t2 - Close file\t3 - Read" << endl
				<<"4 - Write\t\t5 - Read/write\t6 - Get position" << endl
				<<"7 - Set position\t8 - get lenght\t9 - Buffer read"<<endl
				<<"10 - Buffer write"<<endl;
			
			cin>>opt;
			
			switch(opt)
			{
				case 1:
				open(file);
				break;

				case 2:
				file->Close();
				break;

				case 3:
				*file>>var;
				cout<<"result = "<<var<<endl;
				break;

				case 4:
				cout<<"Insert value for writing:" << endl;
				cin>>var;
				*file<<var;
				break;

				case 5:
				break;

				case 6:
				cout<<"Position: " <<file->getPosition()<<endl;
				break;

				case 7:
				cout<<"Insert position:"<<endl;
				cin>>var;
				file->setPosition((unsigned int)var);
				break;

				case 8:
				cout<<"Lenght: " << file->getPosition()<<endl;
				break;

				case 9:
				cout<<"Insert value to buffer"<<endl;
				cin>>var;
				*((binIO_t*)file)<<(const void*)&var,4;
				break;

				case 10:
				*((binIO_t*)file)>>(void*)&var,4;
				cout << var << endl;
				break;

				default:
				loop = false;
				break;
			};
		}

		catch(tExeption_t<string, string, int> exept)
		{
			cout << exept << endl;
		}
	}
}

void open(virtIO_t* file)
{	
	string path;
	string mode;

	cout<<"Insert path:"<<endl;
	cin>>path;

	cout<<"Insert mode:"<<endl;
	cin>>mode;

	file->Open(path, mode.c_str());

}