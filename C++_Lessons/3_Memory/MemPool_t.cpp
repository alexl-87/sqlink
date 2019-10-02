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

void memPool_t::write(const char* data, unsigned int dataSize)
{

}

void memPool_t::write(const char* data, unsigned int dataSize, unsigned int position)
{

}

char* memPool_t::read(unsigned int dataSize)
{
	return 0;
}

char* memPool_t::read(unsigned int dataSize, unsigned int position)
{
	return 0;
}

unsigned int p_write(const void* data, unsigned int dataSize, unsigned int position)
{
	unsigned int retVal = 0;
	if (position <= m_position)
	{
		int index = getPageIndex(position);
		if (index >= 0)
		{
			position = position
		}
	}
}

unsigned int p_read(void* buffer, unsigned int dataSize, unsigned int position)
{

}