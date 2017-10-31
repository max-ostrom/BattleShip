#include "FactoryFourShip.h"

std::shared_ptr<Ship>
FactoryFourShip::createShip(char field[STANDART_FIELD][STANDART_FIELD])
{
    try
    {
        return std::shared_ptr<Ship>(new FourDeckShip(field));
    }
    catch (exception)
    {
        throw CreateShipException("FourDeck");
    }
}
FactoryFourShip::~FactoryFourShip() {}