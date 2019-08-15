#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DateTimeFunctions.h"

static int dateValidation(unsigned int year, unsigned int month, unsigned int day);
static void monthName(unsigned int year, char* name);
/*
Create time
*/
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
		destroyTime(newTime);
		free(newTime);
		return NULL;
	}

	*newTime->hour = hour;
	*newTime->minute = minute;
	*newTime->second = second;
	
	return newTime;
}

/*
Print AM/PM time
*/
int printTimeAMPM(cTime_t* time){
	
	if(!time)
	{
		return 0;
	}
	
	printf("%u:%u:%u", (*time->hour%12), *time->minute, *time->second);
	if(*time->hour < 12)
	{
		printf("AM\n");	
	}
	else
	{
		printf("PM\n");		
	}
	return 1;
}
/*
Print 24 time
*/
int printTime(cTime_t* time){
	
	if(!time)
	{
		return 0;
	}
	
	printf("%u:%u:%u\n", *time->hour, *time->minute, *time->second);
	
	return 1;
}
/*
Add time
*/
int addTime(cTime_t* time, unsigned int hour, unsigned int minute, unsigned int second){
	unsigned int newHour;
	unsigned int newMinute;
	unsigned int newSecond;

	if(!time)
	{
		return 0;
	}
	newSecond = (second + *time->second)%60;
	newMinute = (minute + *time->minute)%60 + (second + *time->second)/60;
	newHour = (hour + *time->hour)%24+(minute + *time->minute)/60;

	*time->second = newSecond;
	*time->minute = newMinute;
	*time->hour	= newHour;

	return 1;
}

/*
Merge times
*/
int mergeTimes(cTime_t* resultTime, cTime_t* addedTime){
	
	int result = 0;
	if(!resultTime || !addedTime)
	{
		return result;
	}
	
	result = addTime(resultTime, *addedTime->hour, *addedTime->minute, *addedTime->second);

	return result;
}
/*
Destroy time
*/
void destroyTime(cTime_t* time){
	if(!time)
	{
		free(time->hour);
		free(time->minute);
		free(time->second);
	}
}
/******************Date**************/

/*
create date
*/
cDate_t* createDate(unsigned int day, unsigned int month, unsigned int year){

	cDate_t* newDate;
	int result = 0;
	result = dateValidation(year, month, day);

	if(!result)
	{
		return NULL;
	}

	newDate = malloc(sizeof(cDate_t));
	if(!newDate)
	{
		return NULL;
	}
	newDate->year = malloc(sizeof(unsigned int));
	newDate->month = malloc(sizeof(unsigned int));
	newDate->day = malloc(sizeof(unsigned int));
	
	if(!year || !month || !day)
	{
		destroyDate(newDate);
		free(newDate);
		return NULL;
	}
	
	*newDate->year = year;
	*newDate->month = month;
	*newDate->day = day;
	
	return newDate;
}


/*
Date validation
*/
static int dateValidation(unsigned int year, unsigned int month, unsigned int day){

	int result = 1;
	if(month > 12 || day > 31)
	{
		result = 0;
	}
	
	else if(month == 2)
	{
		if(day > 28 && year%2 != 0)
		{
			result = 0;
		}	
		else if(day > 29 && year%2 == 0)
		{
			result = 0;		
		}
	
	}
	
	else if(month >= 3 && month < 8)
	{
		if(month%2 == 0 && day == 31)
		{
			result = 0;		
		}
	}
	else if(month > 7 && month <= 12)
	{
		if(month%2 != 0 && day == 31)
		{
			result = 0;		
		}
	}

	return result;

}
/*
printDate
*/

int printDate(cDate_t* date, int typeOfPrint){
/*1 -american, 2 - minth name, default - EU*/

	char* name = malloc(sizeof(char)*10);

	if(!date) return 0;

	if(typeOfPrint == 1)
	{
		printf("%u / %u / %u\n", *date->month, *date->day, *date->year);
	}
	
	else if(typeOfPrint == 2)
	{
		monthName(*date->month, name);
		printf("%u / %s / %u\n", *date->day, name, *date->year);
	}
	
	else
	{
		printf("%u / %u / %u\n",*date->day, *date->month, *date->year);
	}

	free(name);
	return 1;
}

int getDIY(cDate_t* date){
	
	int mnth = 0;
	int result = 0;
	int leap = 0;

	if(!date) return 0;	

	mnth = *date->month;

	(daye->year%4 == 0)?(leap = 213):(leap = 212);
	
	if(mnth > 7)
	{
		if((mnth-8)%2 == 0)
		{
				result = leap + ((mnth-8)/2)*31 + ((mnth-8)/2)*30 + *date->day;
		}
	
		else
		{
				result = leap + (((mnth-8)/2)+1)*31 + ((mnth-8)/2)*30 + *date->day;
		} 
	}
	else
	{
		if(mnth == 1)
		{
			result = *date->day;
		}
		else if(mnth == 2)
		{
			result = *date->day+31;
		}
		else if((mnth-3)%2 == 0)
		{
			result = ((mnth-3)/2-1)*31 + ((mnth-3)/2-1)*30 + *date->day;
		}

		else
		{
			result = (((mnth-3)/2)+1)*31 + ((mnth-8)/2)*30 + *date->day;
		}
	}

	

return result;
}

/*
Month name
*/

static void monthName(unsigned int month, char* name){
	
	if(!name) return;	

	switch(month)
	{
		case 1:
		strcpy (name,"January");
		break;

		case 2:
		strcpy (name,"February");
		break;

		case 3:
		strcpy (name,"March");
		break;

		case 4:
		strcpy (name,"April");
		break;

		case 5:
		strcpy (name,"May");
		break;

		case 6:
		strcpy (name,"June");
		break;

		case 7:
		strcpy (name,"July");
		break;

		case 8:
		strcpy (name,"August");
		break;

		case 9:
		strcpy (name,"September");
		break;

		case 10:
		strcpy (name,"October");
		break;

		case 11:
		strcpy (name,"November");
		break;

		case 12:
		strcpy (name,"December");
		break;
	}

}

/*
Destroy date
*/
void destroyDate(cDate_t* date){
	if(!date)
	{
		free(date->year);
		free(date->month);
		free(date->day);
	}
}




