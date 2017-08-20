#pragma once
#include <ctime>

#include "IGame.h"
class IGameWithTime :
	public IGame
{
public:
	virtual void setStartTime(clock_t start) = 0;
	virtual const clock_t& getStartTime() const = 0;
	virtual ~IGameWithTime()
	{
	}
};

