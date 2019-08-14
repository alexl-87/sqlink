#include <stdio.h>
#include "Date_time.h"


cTime_t* createTime(unsigned int hour, unsigned int minute, unsigned int second){
	
	cTime_t* newTime;	
	


	if(hour > 24|| minute > 59 || second > 59)
	{
		return NULL;
	}

	newTime = malloc(sizeof(cTime_t));
	if(!newTime)
	{
		return NULL;
	}
	newTime->hour = malloc(sizeof(unsigned int));
	newTime->minute = malloc(sizeof(unsigned int));
	newTime->second = malloc(sizeof(unsigned int));
	
	if(!hour || !minute || !second)
	{
		destroy(newTime);
		free(newTime);
		return NULL;
	}

	*newTime->hour = hour;
	*newTime->minute = minute;
	*newTime->second = second;
	
	return newTime;
}

int printTimeAM(cTime_t* time){
	
	if(!time)
	{
		return 0;
	}
	
	printf("%u:%u:%u\n", *time->hour, *time->minute, time->second);
	
	return 1;
}

int printTimePM(cTime_t* time){
	
	if(!time)
	{
		return 0;
	}
	
	printf("%u:%u:%u\n", (*time->hour%12)+1, *time->minute, time->second);
	
	return 1;
}









void destroyTime(cTime_t* time){
	if(date != NULL)
	{
		free(time->hour);
		free(time->minute);
		free(time->second);
	}
}
