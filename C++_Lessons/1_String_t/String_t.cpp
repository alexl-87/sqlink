#include <string.h>
#include <stdio.h>
#include <iostream>
#include "String_t.h"

using namespace std;

string_t::string_t()
{
	m_str = new char[20];
	strcpy(m_str, "***DEFAULT_STRING***");
}

string_t::string_t(const char* newStr)
{
	if(!newStr)
	{
		new (this) string_t();
	}

	else
	{
		int newStrLen = strlen(newStr);
		m_str = new char[newStrLen];
		strcpy(m_str, newStr);
	}
}

string_t::string_t(const string_t& str)
{
	new (this) string_t(str.m_str);
}

string_t::~string_t()
{
	delete[] m_str;
}

int string_t::getLength() const
{
	int retVal = 0;
	if(m_str)
	{
		retVal = strlen(m_str);
	}
	return retVal;
}

const char* string_t::getString() const
{
	return m_str;
}

void string_t::setString(const char* str)
{
	if(str)
	{
		delete[] m_str;
		//new (this) string_t(str);
		int newStrLen = strlen(str);
		m_str = new char[newStrLen];
		strcpy(m_str, str);
	}
}

int string_t::compare(string_t& str) const
{
	int result = strcmp(m_str, str.m_str);

	if (result != 0)
	{
		if(strlen(m_str) >=strlen(str.m_str))
		{
			result = 2;
		}
		else
		{
			result = 1;
		}
	}
	return result;
}

string_t& string_t::operator=(const string_t& str)
{
	(this)->~string_t();
	new (this) string_t(str.m_str);
	return *this;
}

void string_t::print() const
{
	printf("%s\n", m_str);
}