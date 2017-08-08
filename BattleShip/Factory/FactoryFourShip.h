#pragma once
#include "Factory.h"
class FactoryFourShip :
	public IFactory
{
public:

	Ship* createShip(char field[FIELDSIZE][FIELDSIZE])override
	{
		return new FourDeckShip(field);
	}
	virtual ~FactoryFourShip() {}
};

