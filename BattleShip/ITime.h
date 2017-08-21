#ifndef ITime_H
#define ITime_H

#include <ctime>

class ITime 
{
public:
	virtual void setStartTime(clock_t start) = 0;
	virtual const clock_t& getStartTime() const = 0;
	virtual ~ITime()
	{
	}
};
#endif
