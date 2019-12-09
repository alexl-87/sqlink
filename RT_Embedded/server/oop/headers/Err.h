#ifndef Err
#define Err
#include <unistd.h>
#include <iostream>
using namespace std;
class ERR
{
public:
	ERR();
	~ERR();

	static void M1_ERR(const int val, const char* msg){
		if(val == -1){
			cerr << msg << endl;
			exit(1);
		}
	}

	static void NULL_ERR(void* ptr){
		if(!ptr){
			cerr << "NULL error" << endl;
			exit(1);
		}
	}
};

#endif