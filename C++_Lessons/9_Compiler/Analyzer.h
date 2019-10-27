#ifndef Analyzer
#define Analyzer
#include <string>
#include <set>
#include <map>
#include <queue>

class analyzer
{
public:
	analyzer();
	~analyzer(){};
	void analyze(std::queue<std::string>& tokens, int line);
	
private:
	analyzer(const analyzer& t);
	const analyzer& operator=(const analyzer& t);

	std::set<std::string> m_variables;
	std::set<std::string> m_types;
	std::set<std::string> m_keywords;
	std::map<char, int> m_operators;
	std::string m_currentToken;
	static std::string m_delimiters;
	bool m_ifElse;

	bool declaration(std::queue<std::string>& tokens, int line);
	bool operatorsCounter(std::queue<std::string>& tokens, int line);
	static void setDelimiters(const std::string& delimiters);
	static const std::string& getDelimiters();

};
#endif