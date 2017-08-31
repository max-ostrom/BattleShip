#pragma once
#include "Observer.h"
class IView :
	public Observer
{
public:
	virtual void update() const override = 0;
private:
	virtual void endOfGame() const = 0;
};