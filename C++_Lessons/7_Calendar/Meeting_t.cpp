#include "Meeting_t.h"

meeting_t::meeting_t(float start,float end, char* desctiption)
{
	m_start = start;
	m_end = end;
	(desctiption != 0)?(m_description = desctiption):(m_description = "");
}

meeting_t::meeting_t(float start,float end, const string& desctiption):m_description(desctiption)
{
	m_start = start;
	m_end = end;
}

ostream& operator<<(ostream& sout, const meeting_t& meeting)
{
	sout<<"-------------------------------\n"
		<< "Start: " << meeting.getStart() << "\tEnd: " << meeting.getEnd() 
		<< "\nDescription: " << meeting.getDescription()
		<<"\n-------------------------------\n";
	return sout;
}
