#include "Parser.h"
#include "Tokenizer.h"
#include "Analyzer.h"
#include <fstream>
#include <iostream>
using namespace std;


parser::~parser()
{
	delete m_tok;
	delete m_an;
}

parser::parser()
{
	m_tok = new tokenizer();
	m_an = new analyzer();
}


void parser::parse(char const *path)
{
	fstream file;

	file.open(path, fstream::in);

	if(file.fail())
	{
		cout << path << " Not founded" << endl;
		return;
	}

	string str;
	file>>str;
	if(str != "main")
	{
		cout<<"***Illegal code before main***"<<endl;
	}


	int lineCounter = 1;
	int retVal = 0;
	string line;
	while(!getline(file, line).fail())
	{
		retVal = m_tok->parseLine(m_tokens, line);
		if (retVal > 0)
		{
			m_an->analyze(m_tokens, lineCounter);
		}
		++lineCounter;
	}
	m_an->terminate();

	file.close();
}