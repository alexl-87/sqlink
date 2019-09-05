#include "DirWalk.h"
#include <dirent.h>
#include <stdio.h>
#include <string.h>

typedef struct dirent dirent;

DirWalkStatus getFiles(char* dirPath)
{
	DIR *d;
	dirent *dir;
	char nextPath[512];

	if(!dirPath)return paramE;
	
	d = opendir(dirPath);

	while((dir = readdir(d)))
	{
		if(dir->d_name[0] != '.' && dir->d_type == 8)
		{
			printf("%s/%s\n",dirPath,dir->d_name);
		}

		else if(dir->d_name[0] != '.' && dir->d_type == 4)
		{
			strcpy(nextPath, dirPath);
			strcat(nextPath, "/");
			strcat(nextPath, dir->d_name);
			getFiles(nextPath);
		}
	}

	closedir(d);
	return OK;
}