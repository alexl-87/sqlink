#ifndef Car_t
#define Car_t
#include <iostream>
#include <string>
using namespace std;
class car_t
{
public:
	car_t();
	car_t(string name, unsigned short engCapacity);
	void setSpeed(unsigned short seed);
	unsigned short getSpeed();
	typedef enum Gear{ automatic, standart }Gear;

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
	void setName();
	void setGear();
	void setEngineCapacity();
};

#endif