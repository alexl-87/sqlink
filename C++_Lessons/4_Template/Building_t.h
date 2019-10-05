#ifndef Building_t
#define Building_t

template <class B_ID>
class building_t
{
public:

	~building_t();
	building_t();
	building_t(B_ID id);//CTOR grom 
	building_t(building_t& building);//Copy CTOR
	building_t&  operator=(building_t& building);

	void setID(B_ID id);
	B_ID getID();

private:
	B_ID m_id;
};

template <class B_ID>
building_t<B_ID>::~building_t(){}

template <class B_ID>
building_t<B_ID>::building_t(){}

template <class B_ID>
building_t<B_ID>::building_t(B_ID id)//CTOR grom 
{
	m_id = id;
}

template <class B_ID>
building_t<B_ID>::building_t(building_t& building)//Copy CTOR
{
	m_id = building.m_id;
}

template <class B_ID>
building_t<B_ID>& building_t<B_ID>::operator=(building_t& building)
{
	if(this != building)
	{
		m_id = building.m_id;
	}
	return this;
}

template <class B_ID>
B_ID building_t<B_ID>::getID()
{
	return m_id;
}

template <class B_ID>
void building_t<B_ID>::setID(B_ID id)
{
	m_id = id;
}

#endif