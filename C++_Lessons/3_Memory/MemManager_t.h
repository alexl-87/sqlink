#ifndef MemManager_t
#define MemManager_t

class memManager_t
{

public:
	memManager_t(){}
	virtual ~memManager_t() = 0;
	virtual unsigned int write(const void* data, unsigned int dataSize) = 0;
	virtual unsigned int write(const void* data, unsigned int dataSize, unsigned int position) = 0;
	virtual unsigned int read(void* buffer, unsigned int dataSize) = 0;
	virtual unsigned int read(void* buffer, unsigned int dataSize, unsigned int position) = 0;
	virtual void setPosition(unsigned int position) = 0;

	unsigned int getPosition() const;
	unsigned int getDataSize() const;
	bool isFull() const;
	
protected:
	bool m_memoryFull;
	unsigned int m_position;
	unsigned int m_dataSize;
};

#endif 