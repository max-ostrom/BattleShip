#include "FactorySingleShip.h"

std::shared_ptr<Ship> FactorySingleShip::createShip(char field[FIELDSIZE][FIELDSIZE])
{
	try
	{
		return std::shared_ptr<Ship>(new SingleDeckShip(field));
	}
	catch (exception& ex)
	{
		cout << ex.what() << endl;
		return nullptr;
	}
}
FactorySingleShip::~FactorySingleShip() {}