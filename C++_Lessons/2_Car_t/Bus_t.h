#ifndef Bus_t
#define Bus_t
#include "Car_t.h"
#include <string>
using namespace std;

class bus_t : public car_t
{
public:
	bus_t();
	bus_t(unsigned short engCapacity, unsigned short speed, unsigned short line);
	bus_t(bus_t& bus);
	~bus_t();

	unsigned short getSeats() const;
	unsigned short getLine() const;
	void setSeats(unsigned short seats);
	void setLine(unsigned short line);

private:
	unsigned short m_seats;
	unsigned short m_line;
	static const string bus_name;
};

#endif