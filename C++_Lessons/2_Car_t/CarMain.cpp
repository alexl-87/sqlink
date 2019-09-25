#include "Car_t.h"
#include "Bus_t.h"
#include "Private_t.h"

int main(int argc, char const *argv[])
{
	bus_t bus(5500, 90, 240, 58);
	cout<<bus.getGear()<<endl;

	cout<<bus.getSpeed()<<endl;
	bus.setSpeed(120);
	cout<<bus.getSpeed()<<endl;

	cout<<bus.getLine()<<endl;
	bus.setLine(18);
	cout<<bus.getLine()<<endl;

	cout<<bus.getSeats()<<endl;
	bus.setSeats(120);
	cout<<bus.getSpeed()<<endl;

	return 0;
}