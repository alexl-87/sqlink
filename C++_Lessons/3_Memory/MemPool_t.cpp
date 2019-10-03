#include "MemPool_t.h"

memPool_t::memPool_t()
{
	memPage_t* page = new memPage_t;
	v.insert(v.end(), page);
	m_memoryFull = false;
	m_position = 0;
	m_dataSize = 0;
	m_capacity = page->getCapacity();

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
		while(dataSize > 0 || result > 0)
		{
			data = (char*)data+result;
			if (index >= v.size())
			{
				memPage_t* page = new memPage_t;
				v.insert(v.end(), page);
			}
			
			result = v[index]->write(data, dataSize, position);

			dataSize -= result;
			retVal += result;
			m_position += result;
			++index;
			position = 0;
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