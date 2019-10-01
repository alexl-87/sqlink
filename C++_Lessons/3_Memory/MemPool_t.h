#ifndef MemPool_t
#define MemPool_t

class memPool_t
{
public:
	memPool_t();
	~memPool_t();


	unsigned int getPosition() const;
	void setPosition(unsigned int position);

	bool isFull() const;

	unsigned int getSize() const;


	void write(void* data, unsigned int dataSize);
	void write(void* data, unsigned int dataSize, unsigned int position);
	void* read(void* data, unsigned int dataSize) const;
	void* read(void* data, unsigned int dataSize, unsigned int position) const;



private:
	memPool_t(memPool_t& pool){}
	void operator=(){}

	std::vector<Page_t*> vector;
};

#endif