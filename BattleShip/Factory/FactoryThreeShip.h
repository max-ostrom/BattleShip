#ifndef FactoryThreeShip_H
#define FactoryThreeShip_H

#include "Factory.h"

class FactoryThreeShip :
	public IFactory
{
public:

	Ship* createShip(char field[FIELDSIZE][FIELDSIZE]) override
	{
		return new ThreeDeckShip(field);
	}
	virtual ~FactoryThreeShip() {}
};
#endif
