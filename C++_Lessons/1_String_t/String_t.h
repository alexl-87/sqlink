#ifndef String_t
#define String_t

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
		int isContains(const string_t& str) const;
		void prepend(const string_t& str);
		void operator+=(const string_t& str);
		int operator<(const string_t& str) const;
		int operator>(const string_t& str) const;
		int operator>=(const string_t& str) const;
		int operator<=(const string_t& str) const;
		int operator==(const string_t& str) const;
		int operator!=(const string_t& str) const;
		//void operator<<(const string_t& str);
		//void operator>>(const string_t& str);
		
	private:
		char* m_str;
		void buildStr(const char* str);
};

#endif