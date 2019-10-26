#include "Parser.h"
#include <fstream>
#include <iostream>
using namespace std;

void parser::parse(char const *path)
{
	fstream file;

	file.open(path, fstream::in);

	if(file.fail())
	{
		cout << path << " Not founded" << endl;
	}

	
	else
	{
		int lineCounter = 1;
		int retVal = 0;
		string line;
		while(getline(file, line))
		{
			retVal = m_tok.parseLine(m_tokens, line);
			if (retVal > 0)
			{
				m_an.analyze(m_tokens, lineCounter);
			}
			
		}		
	}

	file.close();

}