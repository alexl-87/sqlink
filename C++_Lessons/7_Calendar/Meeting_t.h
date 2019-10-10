#ifndef Meeting_t
#define Meeting_t
#include <string>
using namespace std;
class meeting_t
{
public:
	~meeting_t();
	meeting_t(unsigned float start, unsigned float end, const char* desctiption);
	meeting_t(unsigned float start, unsigned float end, const string& desctiption);

	bool operator==(const meeting_t& meeting) const;
	bool operator>(const meeting_t& meeting) const;
	bool operator<(const meeting_t& meeting) const;
	bool operator>=(const meeting_t& meeting) const;
	bool operator<=(const meeting_t& meeting) const;

	inline void setStart(unsigned float upperBound);
	inline void setEnd(unsigned float lowerBound);
	inline unsigned float getStart() const;
	inline unsigned float getEnd() const;
	inline void setDescription(const string& description);
	inline const string& getDescription() const;

	inline static void setUpperBound(unsigned float upperBound);
	inline static void setLowerBound(unsigned float lowerBound);
	inline static unsigned float getUpperBound();
	inline static unsigned float getLowerBound();

private:
	void operator=(const meeting_t& meeting){}
	unsigned float m_start;
	unsigned float m_end;
	string m_desctiption;

	static unsigned float m_upperBound;
	static unsigned float m_lowerBound;

	inline void createFrom(const char* desctiption);
	inline void createFrom(const string& description);
};



/*PRIVATE*/
inline void meeting_t::createFrom(const char* desctiption)
{
	(description)?(m_desctiption = desctiption):(m_desctiption="");
}

inline void meeting_t::createFrom(const string& description);
{
	m_desctiption = desctiption;
}

#endif