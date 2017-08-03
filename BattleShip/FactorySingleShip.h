#pragma once
#include"Factory.h"
class FactorySingleShip :
	public IFactory
{
public:

	Ship* createShip(char field[10][10])override
	{
		return new SingleDeckShip(field);
	}
};

