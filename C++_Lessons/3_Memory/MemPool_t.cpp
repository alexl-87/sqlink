#include "MemPool_t.h"

memPool_t::memPool_t()
{
	memPage_t* page = new memPage_t;
	v.insert(v.end(), page);
	m_memoryFull = false;
	m_position = 0;
	m_dataSize = 0;
}

memPool_t::~memPool_t()
{
	for (unsigned long i = 0; i < v.size(); ++i)
	{
		delete v[i];
	}
}


unsigned int memPool_t::getPosition() const
{
	return m_position;
}

void memPool_t::setPosition(unsigned int position)
{
	m_position = position;
}

bool memPool_t::isFull() const
{
	return m_memoryFull;
}

unsigned int memPool_t::getDataSize() const
{
	return m_dataSize;
}

void memPool_t::write(const char* data, unsigned int dataSize)
{

}

void memPool_t::write(const char* data, unsigned int dataSize, unsigned int position)
{

}

char* memPool_t::read(unsigned int dataSize)
{

}

char* memPool_t::read(unsigned int dataSize, unsigned int position)
{
	
}