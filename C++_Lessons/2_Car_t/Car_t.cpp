#include "Car_t.h"
#include <iostream>
using namespace std;

size_t car_t::id_gen = 1;

car_t::car_t():id(id_gen++)
{

}

car_t::~car_t()
{

}