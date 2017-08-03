#pragma once
#include "Factory.h"
class FactoryFourShip :
	public IFactory
{
public:

	IShip* createShip(char field[10][10])override
	{
		return new FourDeckShip(field);
	}
};

