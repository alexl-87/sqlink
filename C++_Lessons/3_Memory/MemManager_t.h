#ifndef MemManager_t
#define MemManager_t

class memManager_t
{

public:
	memManager_t(){}
	virtual unsigned int getPosition() const {return 0;}
	virtual void setPosition(unsigned int position){}
	virtual bool isFull() const {return 0;}
	virtual unsigned int getDataSize() const {return 0;}
	virtual void write(const char* data, unsigned int dataSize){}
	virtual void write(const char* data, unsigned int dataSize, unsigned int position){}
	virtual char* read(unsigned int dataSize) {return 0;}
	virtual char* read(unsigned int dataSize, unsigned int position) {return 0;}

protected:
	virtual ~memManager_t(){}

	bool m_memoryFull;
	unsigned int m_position;
	unsigned int m_dataSize;
};

#endif 