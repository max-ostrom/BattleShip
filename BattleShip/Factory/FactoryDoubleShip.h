#ifndef FactoryDoubleShip_H
#define FactoryDoubleShip_H

#include "Factory.h"

class FactoryDoubleShip :
	public IFactory
{
public:
	
	std::shared_ptr<Ship> createShip(char field[FIELDSIZE][FIELDSIZE])override;
	virtual ~FactoryDoubleShip();
};
#endif
