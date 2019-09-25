#include "Car_t.h"
#include <iostream>
#include <string>
using namespace std;

size_t car_t::id_gen = 1;
unsigned short car_t::def_eng_capacity = 1500;

car_t::car_t():m_id(id_gen++), m_gear(standart)
{

}

car_t::car_t(string name, unsigned short engCapacity, unsigned short speed):m_id(id_gen++)
{
	if(name == "Private")
	{
		m_gear = standart;
	}

	else
	{
		m_gear = automatic;
	}

	m_engineCapacity = engCapacity;
	m_speed = speed;
}

car_t::car_t(car_t& car):m_id(id_gen++)
{
	m_gear = car.m_gear;
	m_speed = car.m_speed;
	m_name = car.m_name;
	m_engineCapacity = car.m_engineCapacity;
}

car_t::~car_t()
{

}

bool car_t::operator<(car_t& car) const
{
	return (m_engineCapacity < car.m_engineCapacity);
}

bool car_t::compare(car_t& car) const
{
	return (m_name == car.m_name);
}

void car_t::setSpeed(unsigned short speed)
{
	m_speed = speed;
}

unsigned short car_t::getSpeed() const
{
	return m_speed;
}

string car_t::getName() const
{
	return m_name;
}

unsigned short car_t::getId() const
{
	return m_id;
}

car_t::Gear car_t::getGear() const
{
	return m_gear;
}
