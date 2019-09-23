#ifndef String_t
#define String_t
#include <iostream>
using namespace std;
class string_t
{


	public:
		string_t();
		string_t(const char* newStr);
		string_t(const string_t& str);
		~string_t();

		const char* getString() const;
		int getLength() const;
		int compare(const string_t& str) const;
		void setString(const char* str);
		void print() const;
		string_t& operator=(const string_t& str);
		string_t& prepend(const char* str);
		string_t& prepend(const string_t& str_t);
		string_t& operator+=(const char* str);
		string_t& operator+=(const string_t& str_t);
		bool operator<(const string_t& str) const;
		bool operator>(const string_t& str_t) const;
		bool operator>=(const string_t& str) const;
		bool operator<=(const string_t& str) const;
		bool operator==(const string_t& str) const;
		bool operator!=(const string_t& str) const;
		void upperCase();
		void lowerCase();
		bool isContains(const string_t& str) const;

		
	private:
		char* m_str;
		void buildStr(const char* str);
};
ostream& operator<<(ostream& sout, const string_t& str_t);
istream& operator>>(istream& sin, string_t& str_t);
#endif