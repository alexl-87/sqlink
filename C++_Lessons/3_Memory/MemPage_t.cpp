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

unsigned int memPage_t::getPosition() const
{
	return m_position;
}

void memPage_t::setPosition(unsigned int position)
{
	m_position = position;
}

bool memPage_t::isFull() const
{
	return m_memoryFull;
}

unsigned int memPage_t::getDataSize() const
{
	return m_dataSize;
}

unsigned int memPage_t::getCapacity() const
{
	return m_capacity;
}

void memPage_t::write(const char* data, unsigned int dataSize)
{
	p_write(data, dataSize, m_position);
}

void memPage_t::write(const char* data, unsigned int dataSize, unsigned int position)
{
	p_write(data, dataSize, position);
}

char* memPage_t::read(unsigned int dataSize)
{
	return p_read(dataSize, m_position);
}

char* memPage_t::read(unsigned int dataSize, unsigned int position)
{
	return p_read(dataSize, position);
}

void memPage_t::setDefCapacity(unsigned int capacity)
{
	m_defCapacity = capacity;
}

void memPage_t::p_write(const char* data, unsigned int dataSize, unsigned int position)
{
	if(m_capacity - position <= dataSize)
	{
		for (unsigned int i = m_position, j = 0; i < dataSize; ++i, ++j)
		{
			m_data[i] = data[j];
		}
		m_position += dataSize;
		m_dataSize += dataSize;

		m_memoryFull = (m_position == m_capacity)?true:false;
	}
}
	
char* memPage_t::p_read(unsigned int dataSize, unsigned int position)
{
	char* retVal = new char[dataSize];
	for (unsigned int i = m_position, j = 0; i < dataSize; ++i, ++j)
	{
		if (i < m_capacity)
		{
			retVal[j] = m_data[i];
		}

		else
		{
			retVal[j] = 0;
			m_memoryFull = false;
			m_position = 0;
			m_data = 0;
			return retVal;
		}
	}

	m_memoryFull = false;
	m_position -= dataSize;
	m_dataSize -= dataSize;
	return retVal;
}
