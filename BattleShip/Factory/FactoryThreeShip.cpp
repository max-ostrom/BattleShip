#include "FactoryThreeShip.h"

std::shared_ptr<Ship> FactoryThreeShip::createShip(char field[FIELD_SIZE][FIELD_SIZE])
{
	try
	{
		return std::shared_ptr<Ship>(new ThreeDeckShip(field));
	}
	catch (exception& ex)
	{
		cout << ex.what() << endl;
		return nullptr;
	}
}
FactoryThreeShip::~FactoryThreeShip() {}