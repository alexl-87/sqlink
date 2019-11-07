#include "DirWalk.h"
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
static char month[12][12] = {"Jan","Feb","Mar","Apr",
							 "May","Jun","Jul","Aug",
							 "Sep","Oct","Nov","Dec"};

void printInfo(char* filePath);
void fileTypeCat(char* info, int mode);
void ownerGroupCat(struct stat* st, char* info);
void dateCat(struct timespec st_mtim, char* info);

int main(int argc, char const *argv[])
{
	getFiles(".", printInfo);
	return 0;
}

void printInfo(char* filePath)
{


	struct stat st;
	char* info = malloc(128);

	stat(filePath, &st);


	fileTypeCat(info, st.st_mode);
	sprintf(&info[strlen(info)], " | %ld", st.st_nlink);
	ownerGroupCat(&st, info);
	sprintf(&info[strlen(info)], " | %ld", st.st_size);
	dateCat(st.st_mtim, info);
	printf("%s\n", info);
	free(info);
}

void fileTypeCat(char* info, int mode)
{
	int i =0, j = 0, bits = 0;
	char rwx[] = {'x', 'w', 'r'};
	char fileType[16];

	if(mode/0100000 == 1)
	{
		strcat(info, "| regular file | ");
	}

	bits = mode%01000;

	for(i = j = 0; i<9; ++i, bits/=2, ++j)
	{
		if(bits%2 != 0)
		{
			fileType[8-i] = rwx[j%3];
		}

		else
		{
			fileType[8-i] = '-';
		}
	}

	fileType[i] = '\0';
	strcat(info, fileType);
}

void ownerGroupCat(struct stat* st, char* info)
{
	struct passwd *pw = getpwuid(st->st_uid);
    struct group  *gr = getgrgid(st->st_gid);
    sprintf(&info[strlen(info)], " | %s | %s", pw->pw_name, gr->gr_name);
}

void dateCat(struct timespec st_mtim, char* info)
{
	time_t t = (time_t)st_mtim.tv_sec;
	struct tm tm = *localtime(&t);

  	sprintf(&info[strlen(info)], " | %s", month[tm.tm_mon]);
  	sprintf(&info[strlen(info)], " | %d", tm.tm_mday);
  	sprintf(&info[strlen(info)], " | %02d:", tm.tm_hour);
  	sprintf(&info[strlen(info)], "%02d:", tm.tm_min);
  	sprintf(&info[strlen(info)], "%02d |", tm.tm_sec);
  	printf("%s\n", info);
}