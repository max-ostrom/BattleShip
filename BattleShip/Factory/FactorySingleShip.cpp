#include "FactorySingleShip.h"

std::shared_ptr<Ship>
FactorySingleShip::createShip(char field[STANDART_FIELD][STANDART_FIELD])
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