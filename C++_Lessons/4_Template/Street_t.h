#ifndef Street_t
#define Street_t
#include "Building_t.h"
#include <vector>
using namespace std;

template <class S_ID, class B_ID>
class street_t
{

public:

	~street_t();
	street_t(S_ID id);
	street_t(street_t& street);
	void operator=(street_t& street);

	S_ID getId()const;
	void setId(S_ID id);
	void addBuilding(B_ID);
	building_t<B_ID> getBuilding()const;
	building_t<B_ID> getBuilding(unsigned int index)const;

private:
	S_ID m_id;
	vector< building_t<B_ID> > m_v;
};

template <class S_ID, class B_ID>
street_t <S_ID, B_ID>::~street_t(){}

template <class S_ID, class B_ID>
street_t <S_ID, B_ID>::street_t(S_ID id)
{

}

template <class S_ID, class B_ID>
street_t <S_ID, B_ID>::street_t(street_t& street)
{
	m_id = street.m_id;
}

template <class S_ID, class B_ID>
void street_t<S_ID, B_ID>::operator=(street_t& street)
{
	m_id = street.m_id;
}

template <class S_ID, class B_ID>
S_ID street_t<S_ID, B_ID>::getId()const
{
	return m_id;
}

template <class S_ID, class B_ID>
void street_t <S_ID, B_ID>::setId(S_ID id)
{
	m_id = id;
}

template <class S_ID, class B_ID>
void street_t <S_ID, B_ID>::addBuilding(B_ID)
{

}

template <class S_ID, class B_ID>
building_t<B_ID> street_t <S_ID, B_ID>::getBuilding()const
{

}

template <class S_ID, class B_ID>
building_t<B_ID> street_t <S_ID, B_ID>::getBuilding(unsigned int index)const
{

}


#endif