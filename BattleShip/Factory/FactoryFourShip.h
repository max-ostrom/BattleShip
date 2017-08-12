#ifndef FactoryFourShip_H
#define FactoryFourShip_H

#include "Factory.h"

class FactoryFourShip :
	public IFactory
{
public:

	std::shared_ptr<Ship> createShip(char field[FIELDSIZE][FIELDSIZE])override
	{
		return std::shared_ptr<Ship>(new FourDeckShip(field));
	}
	virtual ~FactoryFourShip() {}
};

#endif