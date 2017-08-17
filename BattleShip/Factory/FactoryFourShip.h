#ifndef FactoryFourShip_H
#define FactoryFourShip_H

#include "Factory.h"

class FactoryFourShip :
	public IFactory
{
public:

	std::shared_ptr<Ship> createShip(char field[FIELDSIZE][FIELDSIZE])override
	{
		try {
			return std::shared_ptr<Ship>(new FourDeckShip(field));
		}
		catch (exception& ex)
		{
			cout << ex.what() << endl;
			return std::shared_ptr<Ship>(new FourDeckShip(field));
		}
	}
	virtual ~FactoryFourShip() {}
};

#endif