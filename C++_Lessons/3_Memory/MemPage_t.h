#ifndef MemPage_t
#define MemPage_t
#include "MemManager_t.h"

class memPage_t : public memManager_t
{
public:
	memPage_t();
	memPage_t(unsigned int capacity);
	~memPage_t();

	virtual unsigned int write(const void* data, unsigned int dataSize);
	virtual unsigned int write(const void* data, unsigned int dataSize, unsigned int position);
	virtual unsigned int read(void* buffer, unsigned int dataSize);
	virtual unsigned int read(void* buffer, unsigned int dataSize, unsigned int position);

	unsigned int getCapacity() const;

	static void setDefCapacity(unsigned int capacity);
	static unsigned int getDefCapacity();

private:
	memPage_t(memPage_t& page){}
	void operator=(memPage_t& page){}

	unsigned int p_write(const void* data, unsigned int dataSize, unsigned int position);
	unsigned int p_read(void* buffer, unsigned int dataSize, unsigned int position);

	char* m_data;
	const unsigned int m_capacity;
	static unsigned int m_defCapacity;
};

#endif