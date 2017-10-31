#ifndef FactoryThreeShip_H
#define FactoryThreeShip_H

#include "Factory.h"
namespace BattleShip
{
    class FactoryThreeShip :
        public IFactory
    {
    public:

        std::shared_ptr<Ship>
            createShip(char field[STANDART_FIELD][STANDART_FIELD]) override;
        virtual ~FactoryThreeShip();
    };
}
#endif
