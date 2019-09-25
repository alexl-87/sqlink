#ifndef Car_t
#define Car_t
#include <iostream>
#include <string>
using namespace std;
class car_t
{

public:
	car_t();
	typedef enum Gear{ automatic, standart }Gear;

protected:
	~car_t();
	const size_t m_id;
	unsigned short m_seatsCapacity;
	unsigned short m_engineCapacity;
	Gear m_gear;
	string m_name;

private:
	static size_t id_gen;
};

#endif