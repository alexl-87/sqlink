#include <stdio.h>
#include <stdlib.h>
#include "Diary_functions.h"

int main(){
	
	Meeting* newMeeting;
	Diary* newDiary;
	doublePtr start;
	doublePtr end;
	intPtr room;
	int capacity;
	
	start = malloc(sizeof(double));
	end	= malloc(sizeof(double));
	room = malloc(sizeof(int));
	system("clear");
	printf("Insert capacity: \n");
	scanf("%d", &capacity);	
	newDiary = create_diary(capacity);
	
	printf("Insert start hour: \n");
	scanf("%lf", start);

	printf("Insert end hour: \n");
	scanf("%lf", end);

	printf("Insert room number: \n");
	scanf("%d", room);
	newMeeting = create_meeting(start, end, room);

	add_meeting(newDiary, newMeeting);

	print_diary(newDiary);

return 0;
}
