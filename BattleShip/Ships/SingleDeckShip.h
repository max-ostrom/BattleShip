#ifndef SingleDeckShip_H
#define SingleDeckShip_H

#include "Ship.h"

#include <ctime>
#include <iostream>

using namespace std;

class SingleDeckShip :
    public Ship
{
public:
    SingleDeckShip(char field[STANDART_FIELD][STANDART_FIELD]);
    virtual const int& getShipSize()const override;
private:
    virtual bool
        isCellFreeHorizontal
        (const char field[STANDART_FIELD][STANDART_FIELD], const int m, const int n)const override;

    virtual bool
        isCellFreeVertical
        (const char field[STANDART_FIELD][STANDART_FIELD], const int m, const int n)const override;

    const int SHIP_SIZE_ = 1;
};

#endif