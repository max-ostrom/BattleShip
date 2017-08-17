#ifndef FactorySignleShip_H
#define FactorySingleShip_H

#include"Factory.h"

class FactorySingleShip :
	public IFactory
{
public:

	std::shared_ptr<Ship> createShip(char field[FIELD_SIZE][FIELD_SIZE])override;
	virtual ~FactorySingleShip();
};

#endif