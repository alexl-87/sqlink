#ifndef Private_t
#define Private_t
#include "Car_t.h"

class private_t : public car_t
{
public:
	private_t();
	private_t();
	~private_t();

	void accelerate();
	void reduce();

private:
	static const string private_name;
	
};

#endif