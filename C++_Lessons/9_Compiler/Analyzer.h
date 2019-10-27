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
	void checkClosures();
	
private:
	analyzer(const analyzer& t);
	const analyzer& operator=(const analyzer& t);

	std::set<std::string> m_variables;
	std::set<std::string> m_types;
	std::set<std::string> m_keywords;
	std::map<char, int> m_operators;
	std::string m_currentToken;
	static std::string m_delimiters;

	int m_closures;
	int m_brackets;
	int m_sbrackets;

	/*FLAGS*/
	bool m_ifElse;
	bool m_declare;

	bool isClosure();
	void declaration(int line);
	void operatorsCounter(std::queue<std::string>& tokens, int line);
	void resetMinusPlus();
	static void setDelimiters(const std::string& delimiters);
	static const std::string& getDelimiters();

};
#endif