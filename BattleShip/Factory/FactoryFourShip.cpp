#include "FactoryFourShip.h"

std::shared_ptr<Ship> FactoryFourShip::createShip(char field[FIELD_SIZE][FIELD_SIZE])
{
	try
	{
		return std::shared_ptr<Ship>(new FourDeckShip(field));
	}
	catch (exception& ex)
	{
		cout << ex.what() << endl;
		return nullptr;
	}
}
FactoryFourShip::~FactoryFourShip() {}