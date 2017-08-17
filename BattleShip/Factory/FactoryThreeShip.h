#ifndef FactoryThreeShip_H
#define FactoryThreeShip_H

#include "Factory.h"

class FactoryThreeShip :
	public IFactory
{
public:

	std::shared_ptr<Ship> createShip(char field[FIELD_SIZE][FIELD_SIZE]) override;
	virtual ~FactoryThreeShip();
};
#endif
