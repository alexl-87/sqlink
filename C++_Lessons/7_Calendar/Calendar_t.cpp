#include "Calendar_t.h"

unsigned int calendar_t::numOfMeetings = 0;

calendar_t::calendar_t()
{

}

calendar_t::calendar_t(calendar_t& calendar)
{
	m_meetings = calendar_t.m_meetings;
}

calendar_t::~calendar_t()
{

}

