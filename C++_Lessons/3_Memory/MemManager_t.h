#ifndef MemManager_t
#define MemManager_t

class memManager_t
{
public:
	memManager_t(){}
	virtual unsigned int getPosition() const{return 0}
	virtual void setPosition(unsigned int position){}
	virtual bool isFull() const{return 0}
	virtual unsigned int getSize() const{return 0}
	virtual void write(void* data, unsigned int dataSize){}
	virtual void write(void* data, unsigned int dataSize, unsigned int position){}
	virtual void* read(void* data, unsigned int dataSize) const{return 0}
	virtual void* read(void* data, unsigned int dataSize, unsigned int position) const{return 0}

protected:
	bool m_memoryStatus;
	unsigned int m_position;
	unsigned int m_dataSize;

private:
	~memManager_t(){}
	
};

#endif 