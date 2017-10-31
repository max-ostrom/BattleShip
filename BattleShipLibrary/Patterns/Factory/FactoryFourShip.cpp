#include "FactoryFourShip.h"
namespace BattleShip
{
    std::shared_ptr<Ship>
        FactoryFourShip::createShip(char field[STANDART_FIELD][STANDART_FIELD])
    {
        try
        {
            return std::shared_ptr<Ship>(new FourDeckShip(field));
        }
        catch (exception)
        {
            throw BattleShip::CreateShipException("FourDeck");
        }
    }
    FactoryFourShip::~FactoryFourShip() {}
}