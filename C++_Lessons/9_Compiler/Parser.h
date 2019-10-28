#ifndef Parser
#define Parser
#include <queue>
#include <string>

class analyzer;
class tokenizer;
class parser
{
public:
	virtual  ~parser();
	parser();
	virtual  void parse(char const *path);
	

private:
	parser(const parser& t);
	const parser& operator=(const parser& t);

	tokenizer* m_tok;
	analyzer* m_an;
	std::queue<std::string> m_tokens;
};
#endif