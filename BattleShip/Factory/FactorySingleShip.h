#ifndef FactorySignleShip_H
#define FactorySingleShip_H

#include"Factory.h"

class FactorySingleShip :
	public IFactory
{
public:

	std::shared_ptr<Ship> createShip(char field[FIELDSIZE][FIELDSIZE])override
	{
		return std::shared_ptr<Ship>(new SingleDeckShip(field));
	}
	virtual ~FactorySingleShip() {}
};

#endif