#ifndef Tokenizer
#define Tokenizer
#include <vector>
#include <set>
#include <string>
using namespace std;

class tokenizer
{
public:
	tokenizer(){};
	~tokenizer(){};
	void parseLine(vector<string>& tokens, const string& line);
};

#endif