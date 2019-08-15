#include <stdio.h>
#include "DateTimeFunctions.h"
#include <time.h>
int main(){

cDate_t* date;
system("clear");
date = createDate(25,8,2018);

printDate(date, 2);/*1 -american, 2 - month name, default - EU*/



return 0;
}
