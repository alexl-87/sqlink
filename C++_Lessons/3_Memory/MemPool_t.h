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

	unsigned int getPosition() const;
	void setPosition(unsigned int position);

	bool isFull() const;

	unsigned int getSize() const;

	void write(const char* data, unsigned int dataSize);
	void write(const char* data, unsigned int dataSize, unsigned int position);
	char* read(unsigned int dataSize);
	char* read(unsigned int dataSize, unsigned int position);

private:
	memPool_t(memPool_t& pool){}
	void operator=(memPool_t& pool){}

	vector<memPage_t*> v;
};

#endif