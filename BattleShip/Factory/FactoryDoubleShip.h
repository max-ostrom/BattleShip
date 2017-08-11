#ifndef FactoryDoubleShip_H
#define FactoryDoubleShip_H

#include "Factory.h"

class FactoryDoubleShip :
	public IFactory
{
public:

	Ship* createShip(char field[FIELDSIZE][FIELDSIZE])override
	{
		return new DoubleDeckShip(field);
	}
	virtual ~FactoryDoubleShip() {}
};
#endif
