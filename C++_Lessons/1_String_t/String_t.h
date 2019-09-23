#ifndef String_t
#define String_t
#include <iostream>
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
		void upperCase();
		void lowerCase();
		bool isContains(const string_t& str) const;
		string_t& prepend(const string_t& str_t);
		string_t& prepend(const char* str);
		string_t& operator+=(const string_t& str_t);
		string_t& operator+=(const char* str);
		bool operator<(const string_t& str) const;
		int operator>(const string_t& str) const;
		int operator>=(const string_t& str) const;
		int operator<=(const string_t& str) const;
		int operator==(const string_t& str) const;
		int operator!=(const string_t& str) const;
		ostream & operator<<(ostream &out, const string_t& str) const;
		isteam & operator>>(istream &in, const string_t& str);
		
	private:
		char* m_str;
		void buildStr(const char* str);
};

#endif