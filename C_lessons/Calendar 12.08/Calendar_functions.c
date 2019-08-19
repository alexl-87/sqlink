#include <stdio.h>
#include <stdlib.h>
#include "Calendar_functions.h"

/*
Add meeting
*/
int add_meeting(Calendar* calendar, Meeting* newMeeting){

	Meeting** temp;
	int index = 0;
	if (calendar == NULL || newMeeting == NULL) return 0;	
		
	if(*(newMeeting->begin_hour) < 0 || *(newMeeting->begin_hour) > 24 || *(newMeeting->end_hour) < 0 || *(newMeeting->end_hour) > 24 || *(newMeeting->room) < 0) return 2;

	if((int) (*newMeeting->begin_hour*100)%100 > 59 || (int) (*newMeeting->end_hour*100)%100 > 59) return 2;
	
	
	
	if(calendar->num_of_meetings>0)
	{
		index = check_avaliability(newMeeting, calendar);
		if(index<0) return 3;
		
		else if(index < calendar->num_of_meetings)
			shift(calendar, index);

	}
	

	temp = calendar->meetings;

	if(calendar->num_of_meetings>= calendar->capacity)
	{
		temp = (Meeting**) realloc(calendar->meetings, sizeof(Meeting*)*(calendar->capacity*2));

		if(temp == NULL) return 1;
	
		calendar->meetings = temp;
		calendar->capacity *= 2;
		
	}
	
	
	calendar->meetings[index] = newMeeting;
	calendar->num_of_meetings++;
	return 1;
} 

/*
Check avaliability
*/

int check_avaliability(Meeting* Meeting, Calendar* calendar){
	
	int start = 0;
	int end = 0;
	int mid;

	if(Meeting == NULL || calendar == NULL) return 0;
	
	end = calendar->num_of_meetings-1;

	while(1)
	{
		mid = (start+end)/2;		

		if((end-start) <= 1) break;

		if(*Meeting->begin_hour >= *calendar->meetings[mid]->end_hour)
			start = mid;

		else if(*Meeting->end_hour <= *calendar->meetings[mid]->begin_hour)
			end = mid;	
	}

		if(*Meeting->begin_hour >= *calendar->meetings[start]->end_hour && *Meeting->end_hour <= *calendar->meetings[end]->begin_hour)
			return end;

		else if(*Meeting->begin_hour >= *calendar->meetings[end]->end_hour && end == (calendar->num_of_meetings-1))
			return calendar->num_of_meetings;
		
		else if(*Meeting->end_hour <= *calendar->meetings[start]->begin_hour && start == 0)
			return 0;


	return -1;

}
/*
Shift
*/
int shift(Calendar* calendar, int index){
	Meeting** temp;
	int i = calendar->num_of_meetings;
		
	if(calendar == NULL || index < 0)
		return 0; 

	if(calendar->num_of_meetings >= calendar->capacity)
	{
		temp = (Meeting**) realloc(calendar->meetings, sizeof(Meeting*)*(calendar->capacity*2));

		if(temp == NULL) return 0;
	
		calendar->meetings = temp;
		calendar->capacity *= 2;
		
	}
	
	for(i; i > index; i--)
	{
		calendar->meetings[i] = calendar->meetings[i-1];
	}
	return 1;

}
/*
Calendar creating
*/

Calendar* create_calendar (int capacity){
	
	Calendar* calendar;
	
	if(capacity < 1)return NULL;

	calendar = malloc(sizeof(Calendar));

	if(calendar ==NULL)return NULL;
	

	calendar->meetings = malloc(capacity*sizeof(Meeting*));
	if(calendar->meetings ==NULL)
	{
		free(calendar);
		return NULL;
	}

	calendar->capacity = capacity;	
	
	calendar->num_of_meetings = 0;
	
	return calendar;
}

/*
Remove meeting
*/

int remove_meeting(Calendar* calendar, doublePtr start_hour){

	int i, m_index;

	if(calendar == NULL) return 0;
	
	m_index = find_meeting(calendar, start_hour);
	
	if(m_index ==0) return 0;

	if(m_index == calendar->num_of_meetings-1)
		destroy_Meeting(calendar->meetings[m_index]);
	
	else
	{
		while(m_index < calendar->num_of_meetings-2)
		{
			calendar->meetings[m_index] = calendar->meetings[m_index+1];
			m_index++;
		}
		destroy_Meeting(calendar->meetings[m_index-1]);
	}
	
	calendar->num_of_meetings--;
			
	return 1;			
}

/*
Find meeting
*/

int find_meeting(Calendar* calendar, doublePtr begin_hour){

	int i;
	if(calendar == NULL || begin_hour == NULL)
		return 0;
	
	for(i = 0; i < calendar->num_of_meetings; i++)
		if(*calendar->meetings[i]->begin_hour == *begin_hour)
			return i;
	
	return 0;
}

int load_from_file(Calendar* calendar){
	Meeting* newMeeting;
	doublePtr begin_hour, end_hour;
	intPtr room;
	int capacity;
	FILE* fCalendar = fopen ("calendar.txt","r");
	if(fCalendar == 0)
		return 0;

	capacity = fscanf(fCalendar, "%d", &capacity);
	calendar = malloc(sizeof(Calendar));
	calendar = create_calendar(capacity);	
	while(1)
	{
		newMeeting = malloc(sizeof(Meeting));
		if(newMeeting != NULL)
		{
			end_hour = malloc(sizeof(double));
			begin_hour = malloc(sizeof(double));
			room = malloc(sizeof(int));
			if(end_hour != NULL && begin_hour != NULL && room != NULL);
				fscanf(fCalendar, "%lf %lf %d", begin_hour, end_hour, room);
		}
		if(feof(fCalendar))
			break;
	}
	
	return 1;
}

void save_to_file(Calendar* calendar){
	
	FILE* fCalendar;
	int i = 0;
	
	if(calendar == NULL)
		return;

	fCalendar = fopen ("calendar.txt","w");
	if (fCalendar!=NULL)
	{	
		fprintf(fCalendar, "%d\n", calendar->capacity);
		for(i; i < calendar->num_of_meetings; i++)
		{
			fprintf(fCalendar, "%f %f %d\n", *calendar->meetings[i]->begin_hour, *calendar->meetings[i]->end_hour, *calendar->meetings[i]->room);
		}
	
		fclose(fCalendar);
	}

}

/*
Print Calendar
*/

int print_calendar(Calendar* calendar){

		int i = 0;
	
	if(calendar == NULL)
		return 0;

	for(i; i < calendar->num_of_meetings; i++)
	{
		printf("Hour: %d:%d - %d:%d | Room %d\n",
		(int)*calendar->meetings[i]->begin_hour,
		(int)(*calendar->meetings[i]->begin_hour*100)%100,
		(int)*calendar->meetings[i]->end_hour,
		(int)(*calendar->meetings[i]->end_hour*100)%100, 
		*calendar->meetings[i]->room);
	}

	return 1;
}

/*
Create meeting
*/

Meeting* create_meeting(doublePtr begin_hour, doublePtr end_hour, intPtr room){

	Meeting* newMeeting;	

	if(begin_hour==NULL || end_hour == NULL || room == NULL)
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
Destroy Calendar
*/
void destroy_Calendar(Calendar* calendar){
	
	int i = 0;
	if(calendar==NULL)
		return;
	
	for(i; i < calendar->num_of_meetings; i++)
	{		
		destroy_Meeting(calendar->meetings[i]);
		free(calendar->meetings[i]);
	}
	free(calendar);
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
