#include "Bus_t.h"
#include <string>
using namespace std;

string bus_t::bus_name = "Bus";

bus_t::bus_t()
{

}

bus_t::bus_t(unsigned short engCapacity, unsigned short speed, unsigned short line):car_t(bus_name, engCapacity, speed)
{
	m_line = line;
}

bus_t::bus_t(bus_t& bus):car_t(bus)
{
	m_line = bus.m_line;
}

bus_t::~bus_t(){}




unsigned short bus_t::getSeats() const
{
	return m_seats;
}

unsigned short bus_t::getLine() const
{
	return m_line;
}

void bus_t::setSeats(unsigned short seats)
{
	m_seats = seats;
}

void bus_t::setLine(unsigned short line)
{
	m_line = line;
}
