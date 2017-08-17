#include "FactoryDoubleShip.h"

std::shared_ptr<Ship> FactoryDoubleShip::createShip(char field[FIELD_SIZE][FIELD_SIZE])
{
	try
	{
		return std::shared_ptr<Ship>(new DoubleDeckShip(field));
	}
	catch (exception& ex)
	{
		cout << ex.what() << endl;
		return nullptr;
	}
}
FactoryDoubleShip::~FactoryDoubleShip() {}