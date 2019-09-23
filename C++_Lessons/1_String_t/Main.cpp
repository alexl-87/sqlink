#include "String_t.h"
#include <iostream>
#include <stdio.h>
using namespace std;

void printMenu()
{
	cout<< "1 - Get string\n"
		<< "2 - Set string\n"
		<< "3 - Get length\n"
		<< "4 - Compare strings 1 and 2\n"
		<< "5 - Prints string\n"
		<< "6 - Create third string using other constructors\n" << endl;
}

void printSubMenu()
{
	cout<< "1 - First string\n"
		<< "2 - Second string\n"
		<< "3 - Third string" << endl;
}

int main()
{
	int loop = 1;
	int switchCase = 0;
	int choise = 0;
	string_t* str3 = new string_t();
	cout << "Create first string:" << endl;
	char text1[64];
	cin.getline(text1, 64, '\n');
	string_t str1(text1);

	cout << "Create secont string:" << endl;
	char text2[64];
	cin.getline(text2, 64, '\n');
	string_t str2(text2);


	while(loop == 1)
	{

		printMenu();
		cin >> switchCase;

		switch(switchCase)
		{
			const char* text;
			char text2[64];
			case(1):
				printSubMenu();
				cin >> choise;
						
				switch(choise)
				{
					case(1):

						text = str1.getString();
						cout << text << endl;;
						break;
					case(2):

						text = str2.getString();
						cout << text << endl;
						break;
					case(3):

						text = str3->getString();
						cout << text << endl;
						break;
					default: break;
				}
			break;

			case(2):
				printSubMenu();
				cin >> choise;
				cout<< "Insert string" << endl;
				cin.getline(text2, 64, '\n');
				switch(choise)
				{
					case(1):
						str1.setString(text2);
						break;
					case(2):
						str2.setString(text2);
						break;
					case(3):
						str3->setString(text2);
						break;
					default: break;
				}
			break;	

			case(3):
				printSubMenu();
				cin >> choise;
				switch(choise)
				{
					case(1):
						str1.setString(text2);
						break;
					case(2):
						str2.setString(text2);
						break;
					case(3):
						str3->setString(text2);
						break;
					default: break;
				}
			break;

			case(4):
				cout << str1.compare(str2) << endl;
			break;

			case(5):

				printSubMenu();
				cin >> choise;
				switch(choise)
				{
					case(1):
						str1.print();
						break;
					case(2):
						str2.print();
						break;
					case(3):
						str3->print();
						break;
					default: break;
				}
			break;

			case(6):
				cout<< "1 - Default constructor\n"
					<< "2 - Constructor\n"
					<< "3 - Copy constructor\n" << endl;
				cin >> choise;
				str3->~string_t();
				delete str3;

				switch(choise)
				{
					case(1):
						str3 = new string_t();
						str3->print();
						break;

					case(2):
						cin.getline(text1, 64, '\n');
						str3 = new string_t(text1);
						str3->print();
						break;

					case(3):
						str3 = new string_t(str1);
						str3->print();
						break;

					default: break;
				}
			break;


			default:
			loop = 0;
			break;					
		}
	}

	return 0;
}