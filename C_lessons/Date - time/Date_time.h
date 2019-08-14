#ifndef Date_time
#define Date_time

typedef struct cTime_t{

	unsigned int* hour;
	unsigned int* minute;
	unsigned int* second;

}cTime_t;

typedef struct cDate_t{
	
	unsigned int* year;

}cDate_t;

/*
Time functions
*/

void destroyTime(cTime_t* time);
int printTimePM(cTime_t* time);
cTime_t* createTime(unsigned int hour, unsigned int minute, unsigned int second);
int printTimeAM(cTime_t* time)
#endif
