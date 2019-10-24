#include "Parser.h"
#include "Analyzer.h"
#include "Tokenizer.h"
#include <cstdlib>
using namespace std;

int main(int argc, char const *argv[])
{
	
	system("clear");
	parser p;
	while(--argc > 0)
	{
		p.parse(argv[argc]);
	}
	
	return 0;
}