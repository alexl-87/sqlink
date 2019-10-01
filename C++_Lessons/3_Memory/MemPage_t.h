#ifndef MemPage_t
#define MemPage_t

class memPage_t
{
public:
	memPage_t();
	memPage_t(unsigned int size);
	~memPage_t();

	unsigned int getPosition() const;
	void setPosition(unsigned int position);

	bool isFull() const;

	unsigned int getSize() const;
	unsigned int getCapacity() const;

	void write(void* data, unsigned int dataSize);
	void write(void* data, unsigned int dataSize, unsigned int position);
	void* read(void* data, unsigned int dataSize) const;
	void* read(void* data, unsigned int dataSize, unsigned int position) const;

	static void setDefCapacity(unsigned int capacity);

private:
	memPage_t(memPage_t& page){}
	void operator=(){}

	char* m_memory;
	const unsigned int m_pageCapacity;
	static unsigned int m_defCapacity;
};


#endif