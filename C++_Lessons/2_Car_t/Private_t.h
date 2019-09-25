#ifndef Private_t
#define Private_t

#include "Car_t.h"
#include <string>
using namespace std;

class private_t : public car_t
{
public:
	private_t();
	private_t(unsigned short engCapacity, unsigned short speed, unsigned short line);
	private_t(private_t& Private);
	~private_t();

	void accelerate();
	void reduce();

private:
	static const string priv_name;
};

#endif