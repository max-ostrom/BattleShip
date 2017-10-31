#ifndef FactoryFourShip_H
#define FactoryFourShip_H

#include "Factory.h"

class FactoryFourShip :
    public IFactory
{
public:

    std::shared_ptr<Ship>
        createShip(char field[STANDART_FIELD][STANDART_FIELD])override;
    virtual ~FactoryFourShip();
};

#endif