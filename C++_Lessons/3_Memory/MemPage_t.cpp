#include "MemPage_t.h"

memPage_t::memPage_t()
{

}

memPage_t::memPage_t(unsigned int size)
{

}

memPage_t::~memPage_t()
{

}

unsigned int memPage_t::getPosition() const
{

}

void memPage_t::setPosition(unsigned int position)
{

}

bool memPage_t::isFull() const
{

}

unsigned int memPage_t::getSize() const
{

}

unsigned int memPage_t::getCapacity() const
{

}

void memPage_t::write(void* data, unsigned int dataSize)
{

}

void memPage_t::write(void* data, unsigned int dataSize, unsigned int position)
{

}

void* memPage_t::read(void* data, unsigned int dataSize) const
{

}

void* memPage_t::read(void* data, unsigned int dataSize, unsigned int position) const
{

}

static void memPage_t::setDefCapacity(unsigned int capacity)
{
	
}