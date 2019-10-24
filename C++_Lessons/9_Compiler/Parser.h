#ifndef Parser
#define Parsere
#include "Tokenizer.h"
#include "Analyzer.h"
#include <fstream>
#include <vector>
using namespace std;

class parser
{
public:
	~parser(){}
	parser(int argc, char const *argv[]){openFile(argc, argv);}
	void openFile(int argc, char const *argv[]);

private:

	tokenizer m_tok;
	analyzer m_an;
};








#endif