#ifndef String_t
#define String_t

class string_t
{
	private:
		char* m_str;

	public:
		string_t(); 						//default constructor
		string_t(const char* newStr); 		//constructor
		string_t(const string_t& str); 		//copy constructor
		~string_t(); 						//destructor

		const char* getString() const; 		//get string
		int getLength() const; 				//get string length
		int compare(string_t& str) const; 	//compare two strings
		void setString(const char* str); 	//set string
		void print() const;					//print string
		string_t& operator=(const string_t& str);
		
};

#endif