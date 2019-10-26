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
	map<string, int> m_operators;
	int m_index;
	bool m_ifElse;

	bool declaration(vector<string>& tokens, int line);
	bool operatorsCounter(vector<string>& tokens, int line);

};
#endif