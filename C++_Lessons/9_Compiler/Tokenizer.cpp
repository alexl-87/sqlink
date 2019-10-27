#include "Tokenizer.h"
#include <iostream>
#include <queue>
#include <string>
using namespace std;


int tokenizer::parseLine(queue<string>& tokens, const string& line)
{	
	int counter = 0;
	int leftIndex = 0;
	int len = 0;
	for(int i = 0; i < line.length()-1; ++i)
	{
		while(isspace(line[i])){++i;}
		leftIndex = i;

		while(isalpha(line[i]) || isdigit(line[i])){++i;}

		len = i - leftIndex;

		if(len > 0)
		{
			tokens.push(line.substr(leftIndex, len));
			counter++;
		}

		if(!isalpha(line[i]) && !isspace(line[i]))
		{
			tokens.push(line.substr(i, 1));
			counter++;
		}
	}
	return counter;
}