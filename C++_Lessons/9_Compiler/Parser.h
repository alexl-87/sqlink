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
	parser(char const *path){openFiles(path);};
	

private:
	void openFiles(char const *path);
	tokenizer m_tok;
	analyzer m_an;
	queue<string> m_tokens;
};








#endif