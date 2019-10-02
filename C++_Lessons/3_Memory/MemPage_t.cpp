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


void memPage_t::setPosition(unsigned int position)
{
	if (position < m_capacity)
	{
		m_position = position;
	}
	else
	{
		throw -1;
	}
}

unsigned int memPage_t::getCapacity() const
{
	return m_capacity;
}

void memPage_t::write(const void* data, unsigned int dataSize)
{
	p_write(data, dataSize, m_position);
}

void memPage_t::write(const void* data, unsigned int dataSize, unsigned int position)
{
	p_write(data, dataSize, position);
}

unsigned int memPage_t::read(void* buffer, unsigned int dataSize)
{
	return p_read(dataSize, m_position);
}

unsigned int memPage_t::read(void* buffer, unsigned int dataSize, unsigned int position)
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
	
unsigned int memPage_t::p_read(void* buffer, unsigned int dataSize, unsigned int position)
{
	int retVal = 0;
	if (position < m_capacity)
	{
		int i = position, j = 0;
		while(i < dataSize && i < m_capacity)
		{
			*(char*)buffer[j] = *m_data[i];
			++retVal;
			++i;
			++j;
		}

	}
	m_dataSize += retVal;
	return retVal;
}
