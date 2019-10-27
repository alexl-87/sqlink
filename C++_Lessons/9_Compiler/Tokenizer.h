#ifndef Tokenizer
#define Tokenizer
#include <queue>
#include <set>
#include <string>
class tokenizer
{
public:
	tokenizer(){};
	~tokenizer(){};
	int parseLine(std::queue<std::string>& tokens, const std::string& line);
private:
	tokenizer(const tokenizer& t);
	const tokenizer& operator=(const tokenizer& t);
};

#endif