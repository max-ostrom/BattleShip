#ifndef FourDeckShip_H
#define FourDeckShip_H

#include "SingleDeckShip.h"
namespace BattleShip
{
    class FourDeckShip :
        public Ship
    {
    public:
        FourDeckShip(char field[STANDART_FIELD][STANDART_FIELD]);
        virtual const int& getShipSize()const  override;
    private:
        virtual bool
            isCellFreeHorizontal
            (const char field[STANDART_FIELD][STANDART_FIELD], const int m, const int n)const override;

        virtual bool
            isCellFreeVertical
            (const char field[STANDART_FIELD][STANDART_FIELD], const int m, const int n)const override;

        const int SHIP_SIZE_ = 4;

    };
}
#endif
