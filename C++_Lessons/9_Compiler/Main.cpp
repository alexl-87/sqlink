#include "Parser.h"
#include "Analyzer.h"
#include "Tokenizer.h"
#include <cstdlib>
using namespace std;

int main(int argc, char const *argv[])
{
	
	system("clear");
	
	while(--argc > 0)
	{
		parser p(argv[argc]);
	}
	
	return 0;
}