#include "Meeting_t.h"
#include "Calendar_t.h"
#include <string>
#include <iostream>
#include <map>
using namespace std;
void printMenu();
void insertNewMeeting(calendar_t& calendar);
void findAppointment(calendar_t& calendar);
int main(int argc, char const *argv[])
{

	int _case = 0;
	float upper = 0;
	float lower = 0;
	float start = 0;
	calendar_t calendar;

	while(true)
	{
		printMenu();
		cin>>_case;
		switch(_case)
		{
			case 1:
			insertNewMeeting(calendar);
			break;

			case 2:
			findAppointment(calendar);
			break;

			case 3:
			cout<<"Insert start hour"<< endl;
			cin >> start;
			(calendar.removeMeeting(start))?
			cout<<"Success\n"<<endl:cout<<"Fail\n"<<endl;
			break;

			case 5:
			cout << calendar.getUpperBound()<< endl;
			break;

			case 6:
			cout << calendar.getLowerBound() << endl;
			break;

			case 7:
			cout<<"Upper bound: " << endl;
			cin >> upper;
			calendar.setUpperBound(upper);
			break;

			case 8:
			cout << "Lower bound: " << endl;
			cin >> lower;
			calendar.setLowerBound(lower);
			break;

			case 10:
			calendar.print();
			break;

			default: goto END;

		};
	}
END:
	return 0;
}

void printMenu()
{
	cout<<"1 - Insert new meeting\t2 - Find meeting"
		<<"\n3 - Remove meeting\t4 - Delete meeting"
		<<"\n5 - Get upper bound\t6 - Get lower bound"
		<<"\n7 - Set upper bound\t8 - Set lower bound"
		<<"\n9 - Clear calendar\t10 - Print calendar" << endl;
}

void insertNewMeeting(calendar_t& calendar)
{
	float start = 0;
	float end = 0;
	string description;
	cout<<"Insert start hour: " << endl;
	cin>>start;
	cout<<"Insert end hour:" << endl;
	cin>>end;
	cout<< "Insert description:"<<endl;
	cin>>description;

	bool retval = calendar.insertMeeting(start, end, description);

	(retval)?cout<<"Success\n":cout<<"Fail\n";
}

void findAppointment(calendar_t& calendar)
{
	float start = 0;
	cout<<"Insert start hour: " << endl;
	cin>>start;
	const meeting_t* m = calendar.findMeeting(start);
	if(m != 0)
	{
		cout << *m << endl;
	}

	else
	{
		cout <<"Not founded" << endl;
	}
}