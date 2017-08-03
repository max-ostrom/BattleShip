#pragma once
#include "Factory.h"
class FactoryFourShip :
	public IFactory
{
public:

	Ship* createShip(char field[10][10])override
	{
		return new FourDeckShip(field);
	}
};

