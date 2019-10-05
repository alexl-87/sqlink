#ifndef Street_t
#define Street_t
#include <vector>
#include <string>
#include "Building_t.h"
using namespace std;

template <class S_ID, class B_ID=int>
class street_t
{

public:

	~street_t();
	street_t(S_ID id);
	street_t(const street_t& street);
	const street_t& operator=(const street_t& street);

	const S_ID& getId() const;
	void setId(const S_ID& id);
	void addBuilding(building_t<B_ID>& building);
	building_t<B_ID>& getBuilding();
	building_t<B_ID>& getBuilding(unsigned int index);

private:
	S_ID m_id;
	vector<building_t<B_ID> > m_v;
};

template <class S_ID, class B_ID>
street_t<S_ID, B_ID>::~street_t(){}

template <class S_ID, class B_ID>
street_t <S_ID, B_ID>::street_t(S_ID id)
{
	m_id = id;
}

template <class S_ID, class B_ID>
street_t<S_ID, B_ID>::street_t(const street_t& street)
{
	m_id = street.m_id;
}

template <class S_ID, class B_ID>
const street_t<S_ID, B_ID>& street_t<S_ID, B_ID>::operator=(const street_t& street)
{
	m_id = street.m_id;
}

template <class S_ID, class B_ID>
const S_ID& street_t<S_ID, B_ID>::getId() const 
{
	return m_id;
}

template <class S_ID, class B_ID>
void street_t<S_ID, B_ID>::setId(const S_ID& id)
{
	m_id = id;
}

template <class S_ID, class B_ID>
void street_t<S_ID, B_ID>::addBuilding(building_t<B_ID>& building)
{
	m_v.insert(m_v.end(), building);
}

template <class S_ID, class B_ID>
building_t<B_ID>& street_t<S_ID, B_ID>::getBuilding()
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

template <class S_ID, class B_ID>
building_t<B_ID>& street_t<S_ID, B_ID>::getBuilding(unsigned int index)
{
	if(index < m_v.size())
	{
		return m_v[index];
	}
}
#endif