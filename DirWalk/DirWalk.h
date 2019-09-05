#ifndef DirWalk
#define DirWalk

enum DirWalkStatus {OK, paramE};

typedef enum DirWalkStatus DirWalkStatus;

DirWalkStatus getFiles(char* dirPath);

#endif