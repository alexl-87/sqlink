#ifndef Calendar_t
#define Calendar_t
#include <map>

template <class MEETING>
class calendar_t
{
public:
	~calendar_t();
	calendar_t();
	calendar_t(calendar_t& calendar);
	calendar_t& operator=(const calendar_t& calendar);

	bool insertMeeting(const MEETING* meeting);
	MEETING* removeMeeting(unsigned float startHour);
	bool deleteMeeting(unsigned float startHour);
	const MEETING* findMeeting(unsigned float startHour) ;
	void cleanCalendar();
	void eraseCalendar();

private:
	unsigned int m_numOfMeetings;
	map<float, MEETING*> m_meetings;
};

#endif