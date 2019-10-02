#include "MemPage_t.h"

unsigned int memPage_t::m_defCapacity = 10;

memPage_t::memPage_t():m_capacity(m_defCapacity)
{
	m_data = new char[m_capacity];
	m_memoryFull = false;
	m_position = 0;
	m_dataSize = 0;
}

memPage_t::memPage_t(unsigned int capacity):m_capacity(capacity)
{
	m_data = new char[m_capacity];
	m_memoryFull = false;
	m_position = 0;
	m_dataSize = 0;
}

memPage_t::~memPage_t()
{
	delete[] m_data;
}

unsigned int memPage_t::getCapacity() const
{
	return m_capacity;
}

unsigned int memPage_t::write(const void* data, unsigned int dataSize)
{
	return p_write(data, dataSize, m_position);
}

unsigned int memPage_t::write(const void* data, unsigned int dataSize, unsigned int position)
{
	return p_write(data, dataSize, position);
}

unsigned int memPage_t::read(void* buffer, unsigned int dataSize)
{
	return p_read(buffer, dataSize, m_position);
}

unsigned int memPage_t::read(void* buffer, unsigned int dataSize, unsigned int position)
{
	return p_read(buffer, dataSize, position);
}

void memPage_t::setDefCapacity(unsigned int capacity)
{
	m_defCapacity = capacity;
}

unsigned int memPage_t::getDefCapacity()
{
	return m_defCapacity;
}

unsigned int memPage_t::p_write(const void* data, unsigned int dataSize, unsigned int position)
{
	int retVal = 0;
	if (position <= m_position)
	{
		m_position = position;
		int j = 0;
		while(m_position < position+dataSize && m_position < m_capacity)
		{
			m_data[m_position] = *((const char*)data+j);
			++retVal;
			++m_position;
			++j;
		}

	}
	m_dataSize += retVal;
	return retVal;
}
	
unsigned int memPage_t::p_read(void* buffer, unsigned int dataSize, unsigned int position)
{
	int retVal = 0;
	if (position <= m_position)
	{
		m_position = position;
		int j = 0;
		while(m_position < position+dataSize && m_position < m_capacity)
		{
			*((char*)buffer+j) = m_data[m_position];
			++retVal;
			++m_position;
			++j;
		}

	}
	return retVal;
}
