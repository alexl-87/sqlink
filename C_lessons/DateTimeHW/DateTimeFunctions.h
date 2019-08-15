#ifndef DateTimeFunctions
#define DateTimeFunctions 

typedef struct cTime_t{

	unsigned int* hour;
	unsigned int* minute;
	unsigned int* second;

}cTime_t;

typedef struct cDate_t{
	
	unsigned int* year;
	unsigned int* month;
	unsigned int* day;

}cDate_t;

/*
Time functions
*/
cTime_t* createTime(unsigned int hour, unsigned int minute, unsigned int second);
void destroyTime(cTime_t* time);
int printTimeAMPM(cTime_t* time);
int printTime(cTime_t* time);
int addTime(cTime_t* time, unsigned int hour, unsigned int minute, unsigned int second);
int mergeTimes(cTime_t* resultTime, cTime_t* addedTime);

/*
Date functions
*/
cDate_t* createDate(unsigned int day, unsigned int month, unsigned int year);
void destroyDate(cDate_t* date);
int printDate(cDate_t* date, int typeOfPrint);/*1 -american, 2 - minth name, default - EU*/
int getDIY(cDate_t* date);


#endif
