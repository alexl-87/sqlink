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
	m_declare = false;
	m_closures = 0;
	m_brackets = 0;
	m_sbrackets = 0;

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

		if(m_declare){declaration(line);}

		else if(m_types.find(m_currentToken) != m_types.end())
		{
			m_declare = true;
			resetMinusPlus();
		}

		else if(m_currentToken == "if")
		{
			m_ifElse = true;
			resetMinusPlus();
		}

		else if(m_currentToken == "else")
		{
			if(m_ifElse){m_ifElse = false;}
			else{cout <<"Line: " << line <<" else without if" << endl;}
			resetMinusPlus();
		}

		else if(m_operators.find(m_currentToken[0]) != m_operators.end())
		{
			operatorsCounter(tokens, line);
		}
		else if (m_variables.find(m_currentToken) == m_variables.end()
				&&m_keywords.find(m_currentToken) == m_keywords.end())
		{
			cout<<"Line: " << line <<" undeclared variable: "
				<< m_currentToken <<  endl;
				resetMinusPlus();
		}

		// m_currentToken = tokens.front();
		// tokens.pop();
		// cout << m_currentToken << endl;
	}
}


void analyzer::declaration(int line)
{
	if(m_keywords.find(m_currentToken) != m_keywords.end())
	{
		cout <<"Line: " << line <<" illegal variable name " << m_currentToken << endl;
	}

	else if(m_types.find(m_currentToken)!= m_types.end())
	{
		cout <<"Line: " << line <<" multiple types" <<endl;
	}

	else if(m_variables.find(m_currentToken)!= m_variables.end())
	{
		cout <<"Line: " << line <<" variable " 
			<< m_currentToken << " already declared" <<endl;
	}

	else if(!isalpha(m_currentToken[0])&&m_currentToken[0]!='_'
			&&m_operators.find(m_currentToken[0]) == m_operators.end())
	{
		cout <<"Line: " << line <<" illegal variable name - " 
		<< m_currentToken << endl;
	}

	else
	{
		m_variables.insert(m_currentToken);
	}
	resetMinusPlus();
	m_declare = false;

}

void analyzer::operatorsCounter(queue<string>& tokens, int line)
{
	
	if(m_currentToken[0] == '+' || m_currentToken[0] == '-')
	{
		int retval = ++m_operators.find(m_currentToken[0])->second;
		if (retval>2)
		{
			cout <<"Line: " << line <<" illegal num of "
			<< m_currentToken[0] << endl;
		}
	}

	else if(isClosure())
	{
		int result = 0;
		++m_operators.find(m_currentToken[0])->second;
		checkClosures();
	}
}

void analyzer::checkClosures()
{

	if(m_currentToken[0] =='(' || m_currentToken[0] ==')')
	{
		
	}
	else if (m_currentToken[0] =='[' || m_currentToken[0] ==']')
	{
		/* code */
	}
	else if (m_currentToken[0] =='{' || m_currentToken[0] =='}')
	{

	}

}

void analyzer::resetMinusPlus()
{
	m_operators.find('+')->second = 0;
	m_operators.find('-')->second = 0;
}


bool analyzer::isClosure()
{
	bool p1 = (m_currentToken[0] = '(') || (m_currentToken[0] = ')');
	bool p2 = (m_currentToken[0] = '[') || (m_currentToken[0] = ']');
	bool p3 = (m_currentToken[0] = '{') || (m_currentToken[0] = '}');

	return p1||p2||p3;
}
