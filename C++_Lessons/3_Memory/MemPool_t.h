#ifndef MemPool_t
#define MemPool_t
#include <vector>
#include "MemPage_t.h"
#include "MemManager_t.h"
using namespace std;

class memPool_t : public memManager_t
{
public:

	memPool_t();
	~memPool_t();

	virtual unsigned int write(const void* data, unsigned int dataSize);
	virtual unsigned int write(const void* data, unsigned int dataSize, unsigned int position);
	virtual unsigned int read(void* buffer, unsigned int dataSize);
	virtual unsigned int read(void* buffer, unsigned int dataSize, unsigned int position);

	unsigned int getCapacity() const;

private:
	memPool_t(memPool_t& pool){}
	void operator=(memPool_t& pool){}

	unsigned int memCopyWrite(const void* data, unsigned int dataSize, unsigned int position);
	unsigned int memCopyRead(void* buffer, unsigned int dataSize, unsigned int position);
	int getPageIndex(unsigned int* position);

	vector<memPage_t*> v;
	unsigned int m_capacity;
};

#endif