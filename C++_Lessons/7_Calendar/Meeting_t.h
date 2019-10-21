#ifndef Meeting_t
#define Meeting_t
#include <string>
#include <iostream>
using namespace std;

class meeting_t
{
public:
	~meeting_t(){}
	meeting_t(float start, float end, char* const desctiption);
	meeting_t(float start,float end, const string& desctiption);

	inline float getStart() const;
	inline float getEnd() const;
	inline const string& getDescription() const;

private:
	meeting_t(const meeting_t& meeting){}
	void operator=(const meeting_t& meeting){}

	float m_start;
	float m_end;
	string m_description;
};

ostream& operator<<(ostream& sout, const meeting_t& meeting);

inline float meeting_t::getStart() const
{
	return m_start;
}

inline float meeting_t::getEnd() const
{
	return m_end;
}

inline const string& meeting_t::getDescription() const
{
	return m_description;
}

#endif