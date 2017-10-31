#include "FactoryThreeShip.h"
namespace BattleShip
{
    std::shared_ptr<Ship>
        FactoryThreeShip::createShip(char field[STANDART_FIELD][STANDART_FIELD])
    {
        try
        {
            return std::shared_ptr<Ship>(new ThreeDeckShip(field));
        }
        catch (exception)
        {
            throw BattleShip::CreateShipException("ThreeDeck");
        }
    }
    FactoryThreeShip::~FactoryThreeShip() {}
}