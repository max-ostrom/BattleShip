#ifndef FactorySignleShip_H
#define FactorySingleShip_H

#include"Factory.h"

class FactorySingleShip :
	public IFactory
{
public:

	std::shared_ptr<Ship> createShip(char field[FIELDSIZE][FIELDSIZE])override
	{
		try 
		{
			return std::shared_ptr<Ship>(new SingleDeckShip(field));
		}
		catch (exception& ex)
		{
			cout << ex.what() << endl;
		}
	}
	virtual ~FactorySingleShip() {}
};

#endif