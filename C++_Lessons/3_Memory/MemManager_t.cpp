#include "MemManager_t.h"

memManager_t::~memManager_t(){}

unsigned int memManager_t::getDataSize() const
{
	return m_position;
}

bool memManager_t::isFull() const
{
	return m_memoryFull;
}

unsigned int memManager_t::getPosition() const
{
	return m_position;
}

void memManager_t::setPosition(unsigned int position)
{
	if (position <= m_position)
	{
		m_position = position;
	}

	else
	{
		throw -1;
	}
}

