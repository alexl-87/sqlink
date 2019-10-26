#include "Analyzer.h"
#include <string>
#include <set>
#include <map>
#include <vector>
#include <iostream>
using namespace std;

analyzer::analyzer()
{
	m_iteratorInit = false;

	string keyWords[] = {"if", "else", "for", "while", "class", "private",
						"public", "protected", "main", "const", "virtual"};
	m_keywords.insert(keyWords, keyWords+(sizeof(keyWords)/sizeof(string)));

	string types[] = {"char", "short", "int", "long", "float", "double", "void"};
	m_types.insert(types, types+(sizeof(types)/sizeof(string)));


	char operators[] = {'+', '-', '=', '>', '<', '*', '&', '(', ')', '[', ']', '{', '}'};
	for (int i = 0; i < sizeof(operators); ++i)
	{
		m_operators.insert(pair<char, int>(operators[i],0));
	}
}

void analyzer::analyze(vector<string>& tokens, int line)
{
	if(!m_iteratorInit)
	{
		m_it = tokens.begin();
		m_iteratorInit = true;
	}

	for (; m_it != tokens.end(); ++m_it)
	{
		cout << *m_it << endl;
	}
}