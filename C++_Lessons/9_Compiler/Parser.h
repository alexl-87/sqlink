#ifndef Parser
#define Parsere
#include "Tokenizer.h"
#include "Analyzer.h"
#include <queue>
#include <string>

using namespace std;

class parser
{
public:
	~parser(){};
	parser(){};
	void parse(char const *path);
	

private:
	tokenizer m_tok;
	analyzer m_an;
	queue<string> m_tokens;
};








#endif