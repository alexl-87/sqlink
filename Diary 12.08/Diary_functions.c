#include <stdio.h>
#include <stdlib.h>
#include "Diary_functions.h"
int add_meeting(Diary* diary, Meeting* newMeeting){
/*
0 - NULL pointer accepted
1 - cant allocate more memory
2 - unacceptable input
3 - unacceptable hours
*/	
	Meeting** temp;
	int bool_avalibility = 0;
	if (diary == NULL || newMeeting == NULL) return 0;	
		
	if(*(newMeeting->begin_hour) < 0 || *(newMeeting->begin_hour) > 24 || *(newMeeting->end_hour) < 0 || *(newMeeting->end_hour) > 24 || *(newMeeting->room) < 0) return 2;
	
	bool_avalibility = check_avalibility(newMeeting, diary);
	
	if(bool_avalibility == 0) return 3;

	temp = diary->meetings;

	if(*(diary->num_of_meetings)>= diary->capacity)
	{
		temp = (Meeting**) realloc(diary->meetings, sizeof(Meeting*)*(diary->capacity*2));

		if(temp == NULL) return 1;
	
		diary->meetings = temp;
		diary->capacity *= 2;
		
	}
	
	
	diary->meetings[*diary->num_of_meetings] = newMeeting;
	*diary->num_of_meetings++;
	return 1;
}

int check_avalibility(Meeting* newMeeting, Diary* diary){

	int hour;
	int minutes;

	return 1;

}

int print_diary(Diary* diary){
	
	int i = 0;
	for(i; i < *diary->num_of_meetings; i++)
	{
		printf("Hour: %d:%d - %d:%d | Room%d\n", (int)*diary->meetings[i]->begin_hour%1,(int)*diary->meetings[i]->begin_hour,(int)*diary->meetings[i]->end_hour%1,(int)*diary->meetings[i]->end_hour, *diary->meetings[i]->room);
	}

	return 1;

}
Diary* create_diary (int capacity){
	
	Diary* diary;
	
	if(capacity < 1)return NULL;

	diary = malloc(sizeof(Diary));

	if(diary ==NULL)return NULL;
	

	diary->meetings = malloc(capacity*sizeof(Meeting*));
	if(diary->meetings ==NULL)
	{
		free(diary);
		return NULL;
	}

	diary->capacity = capacity;	

	diary->num_of_meetings = malloc(sizeof(int));
	
	*diary->num_of_meetings = 0;
	
	return diary;
}

void destroy(Diary* diary){
	
	int i = 0;
	if(diary==NULL)
		return;
	
	for(i; i < *diary->num_of_meetings; i++)
		destroy_Meeting(diary->meetings[i]);
	
	free(diary);
}

/*
Meeting functions
*/

Meeting* create_meeting(doublePtr begin_hour, doublePtr end_hour, intPtr room){

	Meeting* newMeeting;	

	if(begin_hour==NULL || end_hour == NULL || room == NULL)
		return NULL;

	if(*begin_hour < 0 || *begin_hour > 24 || *end_hour < 0 || *end_hour > 24 || *room < 0)
		return NULL;
	
	newMeeting = malloc(sizeof(Meeting));
	if(newMeeting==NULL)
		return NULL;

	newMeeting->begin_hour = begin_hour;
	newMeeting->end_hour = end_hour;
	newMeeting->room = room;

	return newMeeting;
}

void destroy_Meeting(Meeting* meeting){

	if(meeting == NULL)
		return;

	free(meeting->begin_hour);
	free(meeting->end_hour);
	free(meeting->room);
}
