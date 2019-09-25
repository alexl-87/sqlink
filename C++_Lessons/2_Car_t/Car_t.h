#ifndef Car_t
#define Car_t
#include <iostream>
class car_t
{
public:
	car_t();
	
protected:
	~car_t();
	const size_t id;

private:
	static size_t id_gen;
	
};

#endif