#include "String_t.h"
#include <iostream>
#include <stdio.h>
using namespace std;
void printMenu();
void testGetLen();
void testGetString();
void testSetString();
void testCompare();
void testOpEq();
void printTest();
void testUppercase();
void testLowercase();

int main()
{
	int switchCase = 0;
	while(1)
	{
		printMenu();
		cin>>switchCase;
		switch(switchCase)
		{
			case 1:
				testGetLen();
				break;
			case 2:
				testGetString();
				break;
			case 3:
				testSetString();
				break;
			case 4:
				testCompare();
				break;
			case 5:
				testOpEq();
				break;
			case 6:
				printTest();
				break;
			case 7:
				testUppercase();
				break;
			case 8:
				testLowercase();
				break;
		}
	}
	return 0;
}

void printMenu()
{
	cout<<"\n1 - Get length\t\t12 - Prepend string\n"
		<<"2 - Get string\t\t13 - Operator <\n"
		<<"3 - Set string\t\t14 - Operator >\n"
		<<"4 - Compare\t\t15 - Operator >=\n"
		<<"5 - Operator =\t\t16 - Operator <=\n"
		<<"6 - Print string\t17 - Operator ==\n"
		<<"7 - Upper case\t\t18 - Operator !=\n"
		<<"8 - Lower case\t\t19 - Search substring\n"
		<<"9 - += char*\t\t20 - Operator >>\n"
		<<"10 - += string\t\t21 - Operator <<\n"
		<<"11 - Prepend char*\t" << endl;
}

void testGetLen()
{
	cout<<"Insert string"<<endl;
	char tempstr[1024];
	cin>>tempstr;
	string_t str_t(tempstr);
	cout<<"Length: "<<str_t.getLength()<<endl;
}

void testGetString()
{
	cout<<"Insert string_t"<<endl;
	char tempstr[1024];
	cin>>tempstr;
	string_t str_t(tempstr);
	cout<<str_t.getString()<<endl;
}

void testSetString()
{
	cout<<"Insert string"<<endl;
	char tempstr[1024];
	cin>>tempstr;
	string_t str_t;
	str_t.setString(tempstr);
	cout<<"New string is: " << str_t << endl;
}

void testCompare()
{
	cout<<"Insert first string:";
	char ch1[1024];
	cin>>ch1;

	cout<<"\nInsert second string:";
	char ch2[1024];
	cin>>ch2;

	string_t str_t1(ch1);
	string_t str_t2(ch2);

	cout<<"\nResult: "<<str_t1.compare(str_t2)<<endl;
}

void testOpEq()
{
	cout<<"Insert first string:";
	char ch1[1024];
	cin>>ch1;
	cout<<"\nInsert second string:";
	char ch2[1024];
	cin>>ch2;

	string_t str_t1(ch1);
	string_t str_t2(ch2);

	str_t1 = str_t2; 
	cout<<"First string = "<<str_t1<<endl;
}

void printTest()
{
	cout<<"Insert string_t"<<endl;
	char tempstr[1024];
	cin>>tempstr;
	string_t str_t(tempstr);
	str_t.print();
}

void testUppercase()
{
	cout<<"Insert string_t"<<endl;
	char tempstr[1024];
	cin>>tempstr;
	string_t str_t(tempstr);
	str_t.upperCase();
}

void testLowercase()
{
	cout<<"Insert string_t"<<endl;
	char tempstr[1024];
	cin>>tempstr;
	string_t str_t(tempstr);
	str_t.upperCase();
}