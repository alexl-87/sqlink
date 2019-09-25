#include "Bus_t.h"
string bus_t::bus_name = "Bus";

bus_t::bus_t()
{

}

bus_t(unsigned short engCapacity, unsigned short speed, unsigned short line)::car_t(bus_name, engCapacity, speed)
{
	m_line = line;
}


bus_t::~bus_t()
{

}

unsigned short getSeats() const
{
	return m_seats;
}

unsigned short getLine() const
{
	return m_line;
}

void setSeats(unsigned short seats)
{
	m_seats = seats;
}

void setLine(unsigned short line)
{
	m_line = line;
}
