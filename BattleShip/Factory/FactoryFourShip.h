#ifndef FactoryFourShip_H
#define FactoryFourShip_H

#include "Factory.h"

class FactoryFourShip :
	public IFactory
{
public:

	std::shared_ptr<Ship> createShip(char field[FIELD_SIZE][FIELD_SIZE])override;
	virtual ~FactoryFourShip();
};

#endif