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
	m_currentLine = 0;

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
		m_currentLine = line;
		m_previousToken = m_currentToken;
		m_currentToken = tokens.front();
		tokens.pop();

		if(m_declare){declaration();}

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
			else{cout <<"Line: " << m_currentLine <<" else without if" << endl;}
			resetMinusPlus();
		}

		else if(m_operators.find(m_currentToken[0]) != m_operators.end())
		{
			operatorsCounter(tokens);
		}
		else if (m_variables.find(m_currentToken) == m_variables.end()
				&&m_keywords.find(m_currentToken) == m_keywords.end())
		{
			cout<<"Line: " << m_currentLine <<" undeclared variable: "
				<< m_currentToken <<  endl;
				resetMinusPlus();
		}
	}
}


void analyzer::declaration()
{
	if(m_keywords.find(m_currentToken) != m_keywords.end())
	{
		cout <<"Line: " << m_currentLine <<" illegal variable name " << m_currentToken << endl;
	}

	else if(m_types.find(m_currentToken)!= m_types.end())
	{
		cout <<"Line: " << m_currentLine <<" multiple types" <<endl;
	}

	else if(m_variables.find(m_currentToken)!= m_variables.end())
	{
		cout <<"Line: " << m_currentLine <<" variable " 
			<< m_currentToken << " already declared" <<endl;
	}

	else if(!isalpha(m_currentToken[0])&&m_currentToken[0]!='_'
			&&m_operators.find(m_currentToken[0]) == m_operators.end())
	{
		cout <<"Line: " << m_currentLine <<" illegal variable name - " 
		<< m_currentToken << endl;
	}

	else
	{
		m_variables.insert(m_currentToken);
	}
	resetMinusPlus();
	m_declare = false;

}

void analyzer::operatorsCounter(queue<string>& tokens)
{
	
	if(m_currentToken[0] == '+' || m_currentToken[0] == '-')
	{
		isValidOperator('+', '-', tokens);
	}

	else if(m_currentToken[0] == '<' || m_currentToken[0] == '>')
	{
		isValidOperator('<', '>', tokens);
	}

	else if(isClosure())
	{
		checkClosures();
	}
}

void analyzer::checkClosures()
{

	switch(m_currentToken[0])
	{
		case'(':
			++m_closures;
			break;

		case')':
			if(--m_closures < 0)
			{
				cout <<"Line: " << m_currentLine <<" "
				<<m_currentToken[0]<<" without '('"<<endl;
				m_closures = 0;
			}
			break;

		case'[':
			++m_sbrackets;
			break;

		case']':
			if(--m_sbrackets < 0)
			{
				cout <<"Line: " << m_currentLine <<" "
				<<m_currentToken[0]<<" without '['"<<endl;
				m_sbrackets = 0;
			}
			break;

		case'{':
			++m_brackets;
			break;

		case'}':
			if(--m_brackets < 0)
			{
				cout <<"Line: " << m_currentLine <<" "
				<<m_currentToken[0]<<" without '{'"<<endl;
				m_brackets = 0;
			}
			break;
	};

}

void analyzer::resetMinusPlus()
{
	m_operators.find('+')->second = 0;
	m_operators.find('-')->second = 0;
}


bool analyzer::isClosure() const
{
	bool p1 = (m_currentToken[0] == '(') || (m_currentToken[0] == ')');
	bool p2 = (m_currentToken[0] == '[') || (m_currentToken[0] == ']');
	bool p3 = (m_currentToken[0] == '{') || (m_currentToken[0] == '}');

	return p1||p2||p3;
}

void analyzer::isValidOperator(char operator1, char operator2, queue<string>& tokens)
{
	int retval = ++m_operators.find(m_currentToken[0])->second;
	if (retval>2 && m_currentToken != tokens.front())
	{
		cout <<"Line: " << m_currentLine <<" illegal num of "
		<< m_currentToken[0] << endl;
	}
	(m_currentToken[0] == operator1)?m_operators.find(operator2)->second = 0
									:m_operators.find(operator1)->second = 0;
}

void analyzer::terminate()
{

	if (m_closures > 0)
	{
		cout<<m_closures<<" : opened closures ()" << endl;
	}
	if(m_brackets > 0)
	{
		cout<<m_brackets<<" : opened brackets {}" << endl;
	}
	if(m_sbrackets > 0)
	{	
		cout<<m_sbrackets<<" : opened square brackets []" << endl;
	}
}

void analyzer::setDelimiters(const std::string& delimiters)
{
	m_delimiters = delimiters;
}
const string& analyzer::getDelimiters()
{
	return m_delimiters;
}

void analyzer::updateDelimiters()
{
	m_operators.clear();
	for (int i = 0; i < m_delimiters.length(); ++i)
	{
		m_operators.insert(pair<char, int>(m_delimiters[i],0));
	}
}