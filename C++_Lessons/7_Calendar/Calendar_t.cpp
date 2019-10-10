#include "Calendar_t.h"

calendar_t::calendar_t()
{
	m_numOfMeetings = 0;
}

calendar_t::calendar_t(calendar_t& calendar)
{
	m_meetings = calendar_t.m_meetings;
	m_numOfMeetings = calendar.m_numOfMeetings;
}

calendar_t::~calendar_t()
{

}

