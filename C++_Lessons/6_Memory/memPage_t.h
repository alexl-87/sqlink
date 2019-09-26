#ifndef memPage_t
#define memPage_t

class memPage_t
{
public:
	memPage_t();
	~memPage_t();

private:
	memPage_t(memPage_t& page);
	char* m_memory;
	
};


#endif