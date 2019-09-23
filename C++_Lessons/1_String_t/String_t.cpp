#include <string.h>
#include <stdio.h>
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
	buildStr(str);
}

int string_t::compare(const string_t& str) const
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
	if(this != &str)
	{
		buildStr(str.m_str);
	}

	return *this;
}

void string_t::print() const
{
	printf("%s\n", m_str);
}

void string_t::buildStr(const char* str)
{
	delete[] m_str;
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