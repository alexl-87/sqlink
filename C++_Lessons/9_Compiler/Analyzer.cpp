#include "Analyzer.h"
#include <string>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <cctype>
using namespace std;

string analyzer::m_delimiters = "+-=><*&()[]{}";

analyzer::analyzer()
{
	m_ifElse = false;

	string keyWords[] = {"if", "else", "for", "while", "class", "private",
						"public", "protected", "main", "const", "virtual"};
	m_keywords.insert(keyWords, keyWords+(sizeof(keyWords)/sizeof(string)));

	string types[] = {"char", "short", "int", "long", "float", "double", "void"};
	m_types.insert(types, types+(sizeof(types)/sizeof(string)));

	for (int i = 0; i < m_delimiters.length(); ++i)
	{
		m_operators.insert(pair<char, int>(m_delimiters[i],0));
	}
}

void analyzer::analyze(queue<string>& tokens, int line)
{
	while (!tokens.empty())
	{
		m_currentToken = tokens.front();
		tokens.pop();
		if(m_types.find(m_currentToken) != m_types.end())
		{
			declaration(tokens, line);
		}

		else if(m_currentToken == "if")
		{
			m_ifElse = true;
		}

		else if(m_currentToken == "else")
		{
			if(m_ifElse){m_ifElse = false;}
			else{cout <<"Line: " << line <<" else without if" << endl;}
		}

		else if(m_operators.find(m_currentToken[0]) != m_operators.end())
		{
			operatorsCounter(tokens, line);
		}
		else if (m_variables.find(m_currentToken) == m_variables.end())
		{
			cout<<"Line: " << line <<" undeclared variable: "
				<< m_currentToken <<  endl;
		}

		// m_currentToken = tokens.front();
		// tokens.pop();
		// cout << m_currentToken << endl;

	}
}


bool analyzer::declaration(queue<string>& tokens, int line)
{
	bool retval = false;
	m_currentToken = tokens.front();
	tokens.pop();
	if(m_keywords.find(m_currentToken) != m_keywords.end())
	{
		cout <<"Line: " << line <<" multiple type declaration" << endl;
	}

	else if(m_types.find(m_currentToken)!= m_types.end())
	{
		cout <<"Line: " << line <<" illegal variable name" << endl;
	}

	else if(m_variables.find(m_currentToken)!= m_variables.end())
	{
		cout <<"Line: " << line <<" variable " 
			<< m_currentToken << " already declared" <<endl;
	}

	else if(!isalpha(m_currentToken[0])||m_currentToken[0]!='_')
	{
		cout <<"Line: " << line <<" illegal variable name - " 
		<< m_currentToken << endl;
	}

	else
	{
		m_variables.insert(m_currentToken);
	}

	return retval;
}

bool analyzer::operatorsCounter(queue<string>& tokens, int line)
{
	bool retval = false;



	return retval;
}