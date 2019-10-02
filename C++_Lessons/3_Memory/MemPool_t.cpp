#include "MemPool_t.h"

memPool_t::memPool_t()
{
	memPage_t* page = new memPage_t;
	v.insert(v.end(), page);
	m_memoryFull = false;
	m_position = 0;
	m_dataSize = 0;
	m_capacity = page->getCapacity();
	m_numOfPages = 1;

}

memPool_t::~memPool_t()
{
	for (unsigned long i = 0; i < v.size(); ++i)
	{
		delete v[i];
	}
}

unsigned int memPool_t::write(const void* data, unsigned int dataSize)
{
	return memCopyWrite(data, dataSize, m_position);
}

unsigned int memPool_t::write(const void* data, unsigned int dataSize, unsigned int position)
{
	return memCopyWrite(data, dataSize, position);
}


unsigned int memPool_t::read(void* buffer, unsigned int dataSize)
{
	return 0;
}


unsigned int memPool_t::read(void* buffer, unsigned int dataSize, unsigned int position)
{
	return 0;
}

unsigned int memPool_t::memCopyWrite(const void* data, unsigned int dataSize, unsigned int position)
{
	unsigned int retVal = 0, result = 0;

	if (position <= m_position)
	{
		int index = getPageIndex(&position);
		if (index < (int)v.size())
		{
			result = v[index]->write(data, dataSize, position);

			m_position += result;
			m_dataSize += result;
			retVal += result;
			dataSize -= result;
		}
		position = 0;
		while(dataSize > 0 || result > 0)
		{
			data = (char*)data+result;
			memPage_t* page = new memPage_t;
			v.insert(v.end(), page);
			result = v[v.size()-1]->write(data, dataSize, position);

			dataSize -= result;
			retVal += result;
			m_position += result;
			m_dataSize += result;
			++m_numOfPages;
		}
	}
	return retVal;
}

unsigned int memPool_t::memCopyRead(void* buffer, unsigned int dataSize, unsigned int position)
{
	return 0;
}

int memPool_t::getPageIndex(unsigned int* position)
{
	int i = 0;
	for (i = 0; i < (int)v.size(); ++i)
	{
		if(*position >= v[i]->getCapacity())
		{
			*position -= v[i]->getCapacity();
		}
		else
		{
			return i;
		}
	}

	return i;
}