#ifndef Calendar_t
#define Calendar_t
#include "Meeting_t.h"
#include <map>

class calendar_t
{
public:
	~calendar_t();
	calendar_t();
	calendar_t(float upperBound, float lowerBound);

	bool insertMeeting(float start, float end, string description);
	
	meeting_t* removeMeeting(float start);
	bool deleteMeeting(float start);
	const meeting_t* findMeeting(float start) ;
	void cleanCalendar();
	void print();

	inline void setUpperBound(float upperBound);
	inline void setLowerBound(float lowerBound);
	inline float getUpperBound();
	inline float getLowerBound();

private:
	calendar_t(const calendar_t& calendar){}
	void operator=(const calendar_t& calendar){}
	bool isValidInput(float start, float end, string description);

	map<float, meeting_t*> m_meetings;

	float m_upperBound;
	float m_lowerBound;
};


inline void calendar_t::setLowerBound(float lowerBound)
{
	if(lowerBound < 24 && lowerBound> 0 && m_upperBound > m_lowerBound)
	{
		m_lowerBound = lowerBound;
	}	
	
}

inline void calendar_t::setUpperBound(float upperBound)
{
	if(upperBound < 24 && upperBound > 0 && m_upperBound > m_lowerBound)
	{
		m_upperBound = upperBound;
	}	
	
}

inline float calendar_t::getUpperBound()
{
	return m_upperBound;
}

inline float calendar_t::getLowerBound()
{
	return m_lowerBound;
}

#endif