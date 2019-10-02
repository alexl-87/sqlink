#ifndef MemPage_t
#define MemPage_t
#include "MemManager_t.h"
class memPage_t : public memManager_t
{
public:
	memPage_t();
	memPage_t(unsigned int capacity);
	~memPage_t();

	unsigned int getPosition() const;
	void setPosition(unsigned int position);

	bool isFull() const;

	unsigned int getDataSize() const;
	unsigned int getCapacity() const;

	void write(const char* data, unsigned int dataSize);
	void write(const char* data, unsigned int dataSize, unsigned int position);
	char* read(unsigned int dataSize);
	char* read(unsigned int dataSize, unsigned int position);

	static void setDefCapacity(unsigned int capacity);

private:
	memPage_t(memPage_t& page);
	void operator=(memPage_t& page);
	void p_write(const char* data, unsigned int dataSize, unsigned int position);
	char* p_read(unsigned int dataSize, unsigned int position);

	char* m_data;
	const unsigned int m_capacity;
	static unsigned int m_defCapacity;
};


#endif