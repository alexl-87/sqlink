#include "Meeting_t.h"

bool meeting_t::operator==(const meeting_t& meeting) const
{
	return (!(this < meeting) && !(this > meeting));
}

bool meeting_t::operator>(const meeting_t& meeting) const
{
	return m_start >= meeting.m_end;
}

bool meeting_t::operator<(const meeting_t& meeting) const
{
	return m_end <= meeting.m_start;
}
