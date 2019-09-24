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
		int firstOccurance(const char c) const;
		int lastOccurance(const char c) const;
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
		bool isContains(const string_t& str) const;

		void upperCase();
		void lowerCase();

		static bool setCase(bool set);
		static bool getCase();
		static unsigned int setDefCapacity(unsigned int capacity);
		static unsigned int getDefCapacity();

	private:
		static bool caseSens;
		static unsigned int defCapacity;
		char* m_str;
		unsigned int capacity;
		
		void buildStr(const char* str);
		char* charsCat(const char* str_left, const char* str_right);
};

ostream& operator<<(ostream& sout, const string_t& str_t);
istream& operator>>(istream& sin, string_t& str_t);
#endif