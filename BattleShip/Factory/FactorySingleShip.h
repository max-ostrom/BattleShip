#pragma once
#include"Factory.h"
class FactorySingleShip :
	public IFactory
{
public:

	Ship* createShip(char field[FIELDSIZE][FIELDSIZE])override
	{
		return new SingleDeckShip(field);
	}
	virtual ~FactorySingleShip() {}
};

