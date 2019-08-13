
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
	int bool_loop = 1, choice = 0;
	
	system("clear");
	printf("Insert capacity: \n");
	scanf("%d", &capacity);	
	newDiary = create_diary(capacity);
	while(bool_loop)
	{
		printf("Add meeting - 1\n"
				"Print diary - 2\n"
				"Exit - 3");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:

				start = malloc(sizeof(double));
				end	= malloc(sizeof(double));
				room = malloc(sizeof(int));
				
				if(start != NULL && end != NULL && room != NULL)
				{
					printf("Insert start hour: \n");
					scanf("%lf", start);

					printf("Insert end hour: \n");
					end	= malloc(sizeof(double));
					scanf("%lf", end);

					printf("Insert room number: \n");
					room = malloc(sizeof(int));
					scanf("%d", room);
					newMeeting = create_meeting(start, end, room);
					add_meeting(newDiary, newMeeting);
				{
				break;
			
			case 2:
				print_diary(newDiary);
				break;

			default: bool_loop = 0; break;
		}
	}

return 0;
}
