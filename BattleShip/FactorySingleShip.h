#pragma once
#include"Factory.h"
class FactorySingleShip :
	public IFactory
{
public:

	IShip* createShip(char field[10][10])override
	{
		return new SingleDeckShip(field);
	}
};

