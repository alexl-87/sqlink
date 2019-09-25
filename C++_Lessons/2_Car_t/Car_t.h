#ifndef Car_t
#define Car_t
#include <iostream>
#include <string>
using namespace std;

class car_t
{
public:

	typedef enum Gear{ automatic, standart }Gear;

	car_t();
	car_t(string name, unsigned short engCapacity, unsigned short speed);
	car_t(car_t& car);

	void setSpeed(unsigned short speed);
	unsigned short getSpeed() const;
	string getName() const;
	unsigned short getId() const;
	string getGear() const;
	bool operator<(car_t& car) const;
	bool compare(car_t& car) const;

protected:
	~car_t();
	const size_t m_id;
	unsigned short m_speed;

private:
	static size_t id_gen;
	static unsigned short def_eng_capacity;
	Gear m_gear;
	string m_name;
	unsigned short m_engineCapacity;
};

#endif