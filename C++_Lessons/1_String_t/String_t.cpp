#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <iostream>
#include "String_t.h"

using namespace std;

string_t::string_t()
{
	buildStr(0);
}

string_t::string_t(const char* newStr)
{
	buildStr(newStr);
}

string_t::string_t(const string_t& str)
{
	buildStr(str.m_str);
}

string_t::~string_t()
{
	delete[] m_str;
}

int string_t::getLength() const
{
	return strlen(m_str);
}

const char* string_t::getString() const
{
	return m_str;
}

void string_t::setString(const char* str)
{
	delete[] m_str;
	buildStr(str);
}

int string_t::compare(const string_t& str) const
{
	int result = strcmp(m_str, str.m_str);

	if (result > 0)
	{
		result = 1;
	}

	else
	{
		result = 2;
	}

	return result;
}

string_t& string_t::operator=(const string_t& str)
{
	if(this != &str)
	{
		delete[] m_str;
		buildStr(str.m_str);
	}

	return *this;
}

void string_t::print() const
{
	printf("%s", m_str);
}

void string_t::buildStr(const char* str)
{
	if(str != 0)
	{
		m_str = new char[strlen(str)+1];
		strcpy(m_str, str);
	}
	else
	{
		m_str = new char[4];
		m_str[0] = '\0';
	}
}

void string_t::upperCase()
{
	int i = 0;

	while(m_str[i] != '\0')
	{
		m_str[i] = toupper(m_str[i]);
	}
}

void string_t::lowerCase()
{
	int i = 0;

	while(m_str[i] != '\0')
	{
		m_str[i] = tolower(m_str[i]);
	}
}

string_t& string_t::operator+=(const char* str)
{
	if(str != 0)
	{
		char* tempStr = new char[strlen(str)+strlen(m_str)+1];
		strcpy(tempStr, m_str);
		strcat(tempStr, str);
		delete[] m_str;
		m_str = tempStr;
	}
	return *this;
}

string_t& string_t::operator+=(const string_t& str_t)
{
	*this+=str_t.m_str;
	return *this;
}

string_t& string_t::prepend(const char* str)
{
	if(str != 0)
	{
		char* tempStr = new char[strlen(str)+strlen(m_str)+1];
		strcpy(tempStr, str);
		strcat(tempStr, m_str);
		delete[] m_str;
		m_str = tempStr;
	}
	return *this;
}

string_t& string_t::prepend(const string_t& str_t)
{
	this->prepend(str_t.m_str);
	return *this;
}

bool string_t::operator<(const string_t& str_t) const
{
	int result = this->compare(str_t);
	if(result == 2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool string_t::operator>(const string_t& str_t) const
{
	int result = this->compare(str_t);
	if(result == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool string_t::operator>=(const string_t& str_t) const
{
	int result = this->compare(str_t);
	if(result == 1 || result == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool string_t::operator<=(const string_t& str_t) const
{
	int result = this->compare(str_t);
	if(result == 2 || result == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool string_t::operator==(const string_t& str_t) const
{
	int result = this->compare(str_t);
	if(result == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool string_t::operator!=(const string_t& str_t) const
{
	int result = this->compare(str_t);
	if(result != 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool string_t::isContains(const string_t& str_t) const
{
	if(strstr(m_str, str_t.m_str) != 0)
	{
		return true;
	}

	else
	{
		return false;
	}
}

std::ostream& string_t::operator<<(std::ostream &out, string_t& str_t)
{
	out<<str_t.m_str;
	return out;
}

std::istream& string_t::operator>>(std::istream &in)
{
	char tempStr[1024];
	in>>tempStr;
	setString(tempStr);
	return in;
}