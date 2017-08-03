#pragma once
#include "Factory.h"
class FactoryDoubleShip :
	public IFactory
{
public:

	IShip* createShip(char field[10][10])override
	{
		return new DoubleDeckShip(field);
	}
};

