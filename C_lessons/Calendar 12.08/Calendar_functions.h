#ifndef Calendar_functions
#define Calendar_functions

typedef double* doublePtr;
typedef int* intPtr;

/*Meeting*/
typedef struct Meeting{
doublePtr begin_hour;
doublePtr end_hour;
intPtr room;
}Meeting;

/*Calendar*/
typedef struct Diary{
	Meeting** meetings;
	int capacity;
	int num_of_meetings;
	
}Calendar;

/*Calendar functions

Add meeting errors
0 - NULL pointer accepted
1 - cant allocate more memory
2 - unacceptable input
3 - unacceptable hours
*/	
Calendar* create_calendar (int capacity);
int add_meeting(Calendar* calendar, Meeting* newMeeting);
int print_calendar(Calendar* calendar);
void destroy_Calendar(Calendar* calendar);
int check_avaliability(Meeting* newMeeting, Calendar* calendar);
int shift(Calendar* calendar, int index);
int remove_meeting(Calendar* calendar, doublePtr start_hour);
int find_meeting(Calendar* calendar, doublePtr start_hour);
int load_from_file(Calendar* calendar);
void save_to_file(Calendar* calendar);

/*Meeting functions*/
Meeting* create_meeting(doublePtr begin_hour, doublePtr end_hour, int *room);
void destroy_Meeting(Meeting* meeting);

#endif
