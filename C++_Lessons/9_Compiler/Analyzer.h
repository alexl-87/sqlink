#ifndef Analyzer
#define Analyzer
#include <string>
#include <set>
#include <map>
#include <vector>
using namespace std;

class analyzer
{
public:
	analyzer();
	~analyzer(){};
	void analyze(vector<string>& tokens, int line);
	
private:
	set<string> m_variables;
	set<string> m_types;
	set<string> m_keywords;
	map<char, int> m_operators;
	vector<string>::iterator m_it;
	bool m_iteratorInit;
};
#endif