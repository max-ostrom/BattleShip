#ifndef FactoryDoubleShip_H
#define FactoryDoubleShip_H

#include "Factory.h"

class FactoryDoubleShip :
    public IFactory
{
public:

    std::shared_ptr<Ship>
        createShip(char field[STANDART_FIELD][STANDART_FIELD])override;
    virtual ~FactoryDoubleShip();
};
#endif
