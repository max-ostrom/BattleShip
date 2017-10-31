#include "FactoryDoubleShip.h"

std::shared_ptr<Ship>
FactoryDoubleShip::createShip(char field[STANDART_FIELD][STANDART_FIELD])
{
    try
    {
        return std::shared_ptr<Ship>(new DoubleDeckShip(field));
    }
    catch (exception)
    {
        throw CreateShipException("DoubleDeck");
    }
}
FactoryDoubleShip::~FactoryDoubleShip() {}