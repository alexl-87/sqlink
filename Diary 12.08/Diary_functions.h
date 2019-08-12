#ifndef Diary_functions
#define Diary_functions

typedef double* doublePtr;
typedef int* intPtr;

/*Meeting*/
typedef struct Meeting{
doublePtr begin_hour;
doublePtr end_hour;
intPtr room;
}Meeting;

/*Diary*/
typedef struct Diary{
	Meeting** meetings;
	int capacity;
	intPtr num_of_meetings;
	
}Diary;

/*Diary functions*/
Diary* create_diary (int capacity);
int add_meeting(Diary* diary, Meeting* newMeeting);
int remove_meeting(Diary* diary);
int print_diary(Diary* diary);
void destroy_Diary(Diary* diary);
int check_avalibility(Meeting* newMeeting, Diary* diary);

/*Meeting functions*/
Meeting* create_meeting(doublePtr begin_hour, doublePtr end_hour, int *room);
void destroy_Meeting(Meeting* meeting);

#endif

