#include "Analyzer.h"
#include <string>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <cctype>
using namespace std;

analyzer::analyzer()
{

	m_index = 0;
	m_ifElse = false;

	string keyWords[] = {"if", "else", "for", "while", "class", "private",
						"public", "protected", "main", "const", "virtual"};
	m_keywords.insert(keyWords, keyWords+(sizeof(keyWords)/sizeof(string)));

	string types[] = {"char", "short", "int", "long", "float", "double", "void"};
	m_types.insert(types, types+(sizeof(types)/sizeof(string)));


	string operators[] = {"+", "-", "=", ">", "<", "*", "&",
							"(", ")", "[", "]", "{", "}", "()", "[]", "{}"};
	for (int i = 0; i < sizeof(operators)/sizeof(string); ++i)
	{
		m_operators.insert(pair<string, int>(operators[i],0));
	}
}

void analyzer::analyze(vector<string>& tokens, int line)
{
	for (; m_index<tokens.size(); ++m_index)
	{
		if(m_types.find(tokens[m_index]) != m_types.end())
		{
			declaration(tokens, line);
		}

		else if(tokens[m_index] == "if")
		{
			m_ifElse = true;
		}

		else if(tokens[m_index] == "else")
		{
			if(m_ifElse){m_ifElse = false;}
			else{cout <<"Line: " << line <<" else without if" << endl;}
		}

		else if(m_operators.find(tokens[m_index]) != m_operators.end())
		{
			operatorsCounter(tokens, line);
		}

	}
}


bool analyzer::declaration(vector<string>& tokens, int line)
{
	bool retval = false;
	++m_index;

	if(m_keywords.find(tokens[m_index]) != m_keywords.end())
	{
		cout <<"Line: " << line <<" multiple type declaration" << endl;
	}

	else if(m_types.find(tokens[m_index])!= m_types.end())
	{
		cout <<"Line: " << line <<" illegal variable name" << endl;
	}

	else if(m_variables.find(tokens[m_index])!= m_variables.end())
	{
		cout <<"Line: " << line <<" variable " 
			<< tokens[m_index] << " already declared" <<endl;

	}

	else if(!isalpha(tokens[m_index][0]))
	{
		cout <<"Line: " << line <<" illegal variable name - " 
		<< tokens[m_index] << endl;
	}

	else
	{
		m_variables.insert(tokens[m_index]);
	}

	return retval;
}

bool analyzer::operatorsCounter(vector<string>& tokens, int line)
{
	bool retval = false;



	return retval;
}