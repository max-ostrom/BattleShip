#pragma once
#include "Factory.h"
class FactoryThreeShip :
	public IFactory
{
public:

	Ship* createShip(char field[10][10]) override 
	{
		return new ThreeDeckShip(field);
	}
};

