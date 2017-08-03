#pragma once
#include "Factory.h"
class FactoryDoubleShip :
	public IFactory
{
public:

	Ship* createShip(char field[10][10])override
	{
		return new DoubleDeckShip(field);
	}
};

