#ifndef Parser
#define Parsere
#include "Tokenizer.h"
#include "Analyzer.h"
#include <vector>
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
	vector<string> m_tokens;
};








#endif