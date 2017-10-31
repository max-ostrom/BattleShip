#pragma once //bad fix, but doesn't work without this

#include"Factory.h"
namespace BattleShip
{
    class FactorySingleShip :
        public IFactory
    {
    public:

        std::shared_ptr<Ship>
            createShip(char field[STANDART_FIELD][STANDART_FIELD])override;
        virtual ~FactorySingleShip();
    };
}
