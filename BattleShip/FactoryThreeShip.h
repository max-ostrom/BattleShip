#pragma once
#include "Factory.h"
class FactoryThreeShip :
	public IFactory
{
public:

	IShip* createShip(char field[10][10]) override
	{
		return new ThreeDeckShip(field);
	}
};

