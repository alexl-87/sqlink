#include <stdio.h>
#include <stdlib.h>
#include "Diary_functions.h"
int add_meeting(Diary* diary, Meeting* newMeeting){
	Meeting** temp;
	int index = 0;
	if (diary == NULL || newMeeting == NULL) return 0;	
		
	if(*(newMeeting->begin_hour) < 0 || *(newMeeting->begin_hour) > 24 || *(newMeeting->end_hour) < 0 || *(newMeeting->end_hour) > 24 || *(newMeeting->room) < 0) return 2;
	
	if(diary->num_of_meetings>0)
	{
		index = check_avaliability(newMeeting, diary);
		if(index<0) return 3;
		
		else if(index < diary->num_of_meetings)
			shift(diary, index);

	}
	

	temp = diary->meetings;

	if(diary->num_of_meetings>= diary->capacity)
	{
		temp = (Meeting**) realloc(diary->meetings, sizeof(Meeting*)*(diary->capacity*2));

		if(temp == NULL) return 1;
	
		diary->meetings = temp;
		diary->capacity *= 2;
		
	}
	
	
	diary->meetings[index] = newMeeting;
	diary->num_of_meetings++;
	return 1;
}
/*
Check avaliability
*/
int check_avaliability(Meeting* Meeting, Diary* diary){
	
	int start = 0;
	int end = 0;
	int mid;

	if(Meeting == NULL || diary == NULL) return 0;
	
	end = diary->num_of_meetings-1;

	while(1)
	{
		mid = (start+end)/2;		

		if((end-start) <= 1) break;

		if(*Meeting->begin_hour >= *diary->meetings[mid]->end_hour)
			start = mid;

		else if(*Meeting->end_hour <= *diary->meetings[mid]->begin_hour)
			end = mid;	
	}

		if(*Meeting->begin_hour >= *diary->meetings[start]->end_hour && *Meeting->end_hour <= *diary->meetings[end]->begin_hour)
			return end;

		else if(*Meeting->begin_hour >= *diary->meetings[end]->end_hour && end == (diary->num_of_meetings-1))
			return diary->num_of_meetings;
		
		else if(*Meeting->end_hour <= *diary->meetings[start]->begin_hour && start == 0)
			return 0;


	return -1;

}
/*
Shift
*/
int shift(Diary* diary, int index){
	Meeting** temp;
	int i = diary->num_of_meetings;
	if(diary->num_of_meetings >= diary->capacity)
	{
		temp = (Meeting**) realloc(diary->meetings, sizeof(Meeting*)*(diary->capacity*2));

		if(temp == NULL) return 0;
	
		diary->meetings = temp;
		diary->capacity *= 2;
		
	}
	
	for(i; i > index; i--)
	{
		diary->meetings[i] = diary->meetings[i-1];
	}
	return 1;

}



/*
Print diary
*/
int print_diary(Diary* diary){
	
	int i = 0;
	for(i; i < diary->num_of_meetings; i++)
	{
		printf("Hour: %d:%d - %d:%d | Room %d\n",
		(int)*diary->meetings[i]->begin_hour,
		(int)(*diary->meetings[i]->begin_hour*100)%100,
		(int)*diary->meetings[i]->end_hour,
		(int)(*diary->meetings[i]->end_hour*100)%100, 
		*diary->meetings[i]->room);
	}

	return 1;

}

/*
Diary creating
*/

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
	
	diary->num_of_meetings = 0;
	
	return diary;
}
/*
Destroy diary
*/
void destroy(Diary* diary){
	
	int i = 0;
	if(diary==NULL)
		return;
	
	for(i; i < diary->num_of_meetings; i++)
		destroy_Meeting(diary->meetings[i]);
	
	free(diary);
}

/*
Create meeting
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
/*

destriy Meeting

*/
void destroy_Meeting(Meeting* meeting){

	if(meeting == NULL)
		return;

	free(meeting->begin_hour);
	free(meeting->end_hour);
	free(meeting->room);
}
