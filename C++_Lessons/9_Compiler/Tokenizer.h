#ifndef Tokenizer
#define Tokenizer
#include <queue>
#include <string>
using namespace std;

class tokenizer
{
public:
	tokenizer(){};
	~tokenizer(){};
	void parseLine(queue<string>& tokens, const string& line);
};

#endif