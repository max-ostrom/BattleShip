#include "FactoryDoubleShip.h"
namespace BattleShip
{
    std::shared_ptr<Ship>
        FactoryDoubleShip::createShip(char field[STANDART_FIELD][STANDART_FIELD])
    {
        try
        {
            return std::shared_ptr<Ship>(new DoubleDeckShip(field));
        }
        catch (exception)
        {
            throw BattleShip::CreateShipException("DoubleDeck");
        }
    }
    FactoryDoubleShip::~FactoryDoubleShip() {}
}