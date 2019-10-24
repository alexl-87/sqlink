#include "Parser.h"
#include <fstream>
#include <iostream>
using namespace std;

void parser::openFiles(char const *path)
{
	fstream file;

	file.open(path, fstream::in);

	if(file.fail())
	{
		cout << path << " Not founded" << endl;
	}

	else
	{
		string line;
		while(getline(file, line))
		{
			m_tok.parseLine(m_tokens, line);
		}
		
		//m_an.analyzeTokens(m_tokens);
	}

	file.close();

}