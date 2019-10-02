#include "MemManager_t.h"

memManager_t::~memManager_t(){}

unsigned int memManager_t::getPosition() const
{
	return m_position;
}

unsigned int memManager_t::getDataSize() const
{
	return m_dataSize;
}

bool memManager_t::isFull() const
{
	return m_memoryFull;
}

