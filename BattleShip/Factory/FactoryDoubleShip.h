#ifndef FactoryDoubleShip_H
#define FactoryDoubleShip_H

#include "Factory.h"

class FactoryDoubleShip :
	public IFactory
{
public:

	std::shared_ptr<Ship> createShip(char field[FIELDSIZE][FIELDSIZE])override
	{
		return std::shared_ptr<Ship>(new DoubleDeckShip(field));
	}
	virtual ~FactoryDoubleShip() {}
};
#endif