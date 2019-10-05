#ifndef City_t
#define City_t
#include <vector>
#include <string>
#include "Street_t.h"
using namespace std;

template <class C_ID, class S_ID=int>
class city_t
{

public:

	~city_t();
	city_t(const C_ID& id);
	city_t(const city_t& city);
	const city_t& operator=(const city_t& city);

	const C_ID& getId() const;
	void setId(const C_ID& id);
	void addStreet(street_t<S_ID>& street);
	street_t<S_ID>& getStreet();
	street_t<S_ID>& getStreet(unsigned int index);

private:
	C_ID m_id;
	vector<street_t<S_ID> > m_v;
};

template <class C_ID, class S_ID>
city_t<C_ID, S_ID>::~city_t(){}

template <class C_ID, class S_ID>
city_t<C_ID, S_ID>::city_t(const C_ID& id)
{
	m_id = id;
}

template <class C_ID, class S_ID>
city_t<C_ID, S_ID>::city_t(const city_t& city)
{
	m_id = city.m_id;
}

template <class C_ID, class S_ID>
const city_t<C_ID, S_ID>& city_t<C_ID, S_ID>::operator=(const city_t& city)
{
	if(this != city)
	{
		m_id = city.m_id;
	}
	return this;
}

template <class C_ID, class S_ID>
const C_ID& city_t<C_ID, S_ID>::getId() const 
{
	return m_id;
}

template <class C_ID, class S_ID>
void city_t<C_ID, S_ID>::setId(const C_ID& id)
{
	m_id = id;
}

template <class C_ID, class S_ID>
void city_t<C_ID, S_ID>::addStreet(street_t<S_ID>& street)
{
	m_v.insert(m_v.end(), street);
}

template <class C_ID, class S_ID>
street_t<S_ID>& city_t<C_ID, S_ID>::getStreet()
{
	if (m_v.size() > 0)
	{
		return m_v[m_v.size()-1];
	}
	else
	{
		throw 0;
	}
}

template <class C_ID, class S_ID>
street_t<S_ID>& city_t<C_ID, S_ID>::getStreet(unsigned int index)
{
	if(index < m_v.size())
	{
		return m_v[index];
	}

	else
	{
		throw 0;
	}
}



#endif