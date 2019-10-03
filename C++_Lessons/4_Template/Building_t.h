#ifndef Building_t
#define Building_t

template <class ID>
class building_t
{
public:
	building_t(ID id);
	building_t(building_t& building);
	void operator=(building_t& building);
	~building_t();

	void setID(ID id);
	ID getID() const;


private:
	ID m_id;
};

template <class ID>
building_t<ID>::building_t(ID id)
{
	m_id = id;
}

template <class ID>
building_t<ID>::building_t(building_t& building)
{
	m_id = building.m_id;
}

template <class ID>
void building_t<ID>::operator=(building_t& building)
{
	m_id = building.m_id;
}

template <class ID>
building_t<ID>::~building_t(){}

template <class ID>
ID building_t<ID>::getID() const
{
	return m_id;
}

template <class ID>
void building_t<ID>::setID(ID id)
{
	m_id = id;
}

#endif