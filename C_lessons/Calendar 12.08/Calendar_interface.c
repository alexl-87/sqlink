#include <stdio.h>
#include <stdlib.h>
#include "Calendar_functions.h"

int main(){
	
	Meeting* newMeeting;
	Calendar* newCalendar;
	doublePtr start;
	doublePtr end;
	intPtr room;
	int capacity;
	int bool_loop = 1, choice = 0;
	int result;
	system("clear");
	
	result = load_from_file(newCalendar);
	if(!result)
	{
		printf("Insert capacity: \n");
		scanf("%d", &capacity);	
		newCalendar = create_calendar(capacity);
	}
	while(bool_loop)
	{
		printf("Add meeting - 1\n"
				"Print calendar - 2\n"
				"Exit - 3\n");
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
					add_meeting(newCalendar, newMeeting);
				}
				break;
			
			case 2:
				print_calendar(newCalendar);
				break;

			default: bool_loop = 0; break;
		}
	}
	save_to_file(newCalendar);
	return 0;
}
