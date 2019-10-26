#include "Tokenizer.h"
#include <iostream>
#include <experimental/vector>
#include <string>
using namespace std;

void tokenizer::parseLine(vector<string>& tokens, const string& line)
{
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
			tokens.push_back(line.substr(leftIndex, len));
		}

		if(!isalpha(line[i]) && !isspace(line[i]))
		{
			tokens.push_back(line.substr(i, 1));
		}
	}
}