#include "Car_t.h"
#include <iostream>
#include <string>
using namespace std;

size_t car_t::id_gen = 1;
unsigned short car_t:def_eng_capacity = 1500;

car_t::car_t():m_id(id_gen++), m_gear(standart)
{

}

car_t::~car_t()
{

}