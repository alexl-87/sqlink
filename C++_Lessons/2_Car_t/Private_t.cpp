#include "Private_t.h"
#include <string>
using namespace std;

string private_t::priv_name = "Private";
private_t::private_t(){}

private_t::private_t(unsigned short engCapacity, unsigned short speed, unsigned short line):car_t(priv_name, engCapacity, speed){}

private_t::private_t(private_t& Private):car_t(private){}

private_t::~private_t(){}

void private_t::accelerate()
{
	m_speed += 10;
}

void private_t::reduce()
{
	m_speed -= 10;
}
