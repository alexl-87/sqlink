#include "Calendar_t.h"
#include "Meeting_t.h"
#define ABS(x) (x<0)?x*=(-1):x;
#define MINUTES(x) do{x = ((int)(x*100))%100;}while(false);

calendar_t::~calendar_t()
{
	for (std::map<float, meeting_t*>::iterator it = m_meetings.begin(); it != m_meetings.end(); ++it)
	{
		delete it->second;
	}
}

calendar_t::calendar_t()
{
	m_upperBound = 19.0;
	m_lowerBound = 8.0;
}

calendar_t::calendar_t(float upperBound, float lowerBound)
{
	m_upperBound = upperBound;
	m_lowerBound = lowerBound;
}

bool calendar_t::insertMeeting(float start, float end, string description)
{
	if(isValidInput(start, end, description) == false)
	{
		return false;
	}
	meeting_t* newMeeting = new meeting_t(start, end, description);
	m_meetings[start] = newMeeting;

	return true;
}

meeting_t* calendar_t::removeMeeting(float start)
{
	std::map<float, meeting_t*>::iterator it = m_meetings.find(start);
	if (it != m_meetings.end())
	{
		meeting_t* retval = it->second;
		m_meetings.erase(start);
		return retval;
	}

	return 0;
}

bool calendar_t::deleteMeeting(float start)
{
	std::map<float, meeting_t*>::iterator it = m_meetings.find(start);
	if (it != m_meetings.end())
	{
		delete it->second;
		m_meetings.erase(start);
		return true;
	}
	
	return false;
}

const meeting_t* calendar_t::findMeeting(float start) 
{
	std::map<float, meeting_t*>::iterator it = m_meetings.find(start);
	return (it != m_meetings.end())?m_meetings[start]:0;
}

void calendar_t::cleanCalendar()
{
	for (std::map<float, meeting_t*>::iterator it = m_meetings.begin(); it != m_meetings.end(); ++it)
	{
		m_meetings.erase(it->first);
	}
}

bool calendar_t::isValidInput(float start, float end, string description)
{
	ABS(start);
	ABS(end);
	float startMinutes = start;
	float endMinutes = end;
	MINUTES(startMinutes);
	MINUTES(endMinutes);

	if (start >= m_lowerBound && end <= m_upperBound && end > start)
	{
		if(endMinutes > 59 || startMinutes > 59)
		{
			return false;
		}

		if(m_meetings.empty())
		{
			return true;
		}

		std::map<float, meeting_t*>::iterator it_1 = m_meetings.begin();
		std::map<float, meeting_t*>::iterator it_2 = m_meetings.begin();
		std::map<float, meeting_t*>::iterator end_it = m_meetings.end();
		

		if (it_1->second->getStart() >= end)
		{
			return true;
		}

		++it_2;
		while(it_1 != end_it)
		{
			if(it_1->second->getEnd() <= start && it_2 == end_it)
			{
				return true;
			}

			else if(it_1->second->getEnd() <= start && it_2->second->getStart() >= end)
			{
				return true;
			}

			++it_1;
			++it_2;
		}
	}

	return false;
}

void calendar_t::print()
{
	for (std::map<float, meeting_t*>::iterator it = m_meetings.begin(); it != m_meetings.end(); ++it)
	{
		cout<<*it->second<<endl;;
	}
}