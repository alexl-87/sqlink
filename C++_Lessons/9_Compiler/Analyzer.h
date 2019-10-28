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
	virtual ~analyzer(){};
	virtual void analyze(std::queue<std::string>& tokens, int line);
	virtual void terminate();
	
private:
	analyzer(const analyzer& t);
	const analyzer& operator=(const analyzer& t);

	std::set<std::string> m_variables;
	std::set<std::string> m_types;
	std::set<std::string> m_keywords;
	std::map<char, int> m_operators;
	std::string m_currentToken;
	std::string m_previousToken;
	static std::string m_delimiters;

	int m_closures;
	int m_brackets;
	int m_sbrackets;
	int m_currentLine;

	/*FLAGS*/
	bool m_ifElse;
	bool m_declare;

	void isValidOperator(char operator1, char operator2, std::queue<std::string>& tokens);
	bool isClosure() const;
	void checkClosures();
	void declaration();
	void operatorsCounter(std::queue<std::string>& tokens);
	void resetMinusPlus();
	static void setDelimiters(const std::string& delimiters);
	static const std::string& getDelimiters();

};
#endif