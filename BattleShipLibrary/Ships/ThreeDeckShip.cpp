#include "ThreeDeckShip.h"


namespace BattleShip
{
    ThreeDeckShip::ThreeDeckShip(char field[STANDART_FIELD][STANDART_FIELD])
    {
        coordsX_ = shared_ptr<int>(new int[SHIP_SIZE_]);
        coordsY_ = shared_ptr<int>(new int[SHIP_SIZE_]);


        int n = static_cast<int>(rand()) % 2;

        switch (n) {

        case 0://vertical
        {
            int m = static_cast<int>(rand()) % (STANDART_FIELD - SHIP_SIZE_ + 1);
            int n = static_cast<int>(rand()) % STANDART_FIELD;


            while (isCellFreeVertical(field, m, n))
            {
                m = static_cast<int>(rand()) % (STANDART_FIELD - SHIP_SIZE_ + 1);
                n = static_cast<int>(rand()) % STANDART_FIELD;
            }


            field[m][n] = ShipInfo::ALIVE_SHIP;
            field[m + 1][n] = ShipInfo::ALIVE_SHIP;
            field[m + 2][n] = ShipInfo::ALIVE_SHIP;


            coordsX_.get()[0] = m;
            coordsX_.get()[1] = m + 1;
            coordsX_.get()[2] = m + 2;


            coordsY_.get()[0] = n;
            coordsY_.get()[1] = n;
            coordsY_.get()[2] = n;
            break; }
        case 1://horizontal
            int m = static_cast<int>(rand()) % STANDART_FIELD;
            int n = static_cast<int>(rand()) % (STANDART_FIELD - SHIP_SIZE_ + 1);


            while (isCellFreeHorizontal(field, m, n))
            {
                m = static_cast<int>(rand()) % STANDART_FIELD;
                n = static_cast<int>(rand()) % (STANDART_FIELD - SHIP_SIZE_ + 1);
            }


            field[m][n] = ShipInfo::ALIVE_SHIP;
            field[m][n + 1] = ShipInfo::ALIVE_SHIP;
            field[m][n + 2] = ShipInfo::ALIVE_SHIP;


            coordsX_.get()[0] = m;
            coordsX_.get()[1] = m;
            coordsX_.get()[2] = m;


            coordsY_.get()[0] = n;
            coordsY_.get()[1] = n + 1;
            coordsY_.get()[2] = n + 2;
            break;
        }//switch
    }

    const int& ThreeDeckShip::getShipSize() const
    {
        return SHIP_SIZE_;
    }

    bool ThreeDeckShip::isCellFreeHorizontal
    (const char field[STANDART_FIELD][STANDART_FIELD], const int m, const int n) const
    {
        return field[m][n] == ShipInfo::ALIVE_SHIP || field[m][n + 1] == ShipInfo::ALIVE_SHIP ||
            field[m][n + 2] == ShipInfo::ALIVE_SHIP || field[m - 1][n - 1] == ShipInfo::ALIVE_SHIP ||
            field[m - 1][n] == ShipInfo::ALIVE_SHIP || field[m - 1][n + 1] == ShipInfo::ALIVE_SHIP ||
            field[m - 1][n + 2] == ShipInfo::ALIVE_SHIP || field[m - 1][n + 3] == ShipInfo::ALIVE_SHIP ||
            field[m][n - 1] == ShipInfo::ALIVE_SHIP || field[m][n + 3] == ShipInfo::ALIVE_SHIP ||
            field[m + 1][n - 1] == ShipInfo::ALIVE_SHIP || field[m + 1][n] == ShipInfo::ALIVE_SHIP ||
            field[m + 1][n + 1] == ShipInfo::ALIVE_SHIP || field[m + 1][n + 2] == ShipInfo::ALIVE_SHIP ||
            field[m + 1][n + 3] == ShipInfo::ALIVE_SHIP;
    }

    bool ThreeDeckShip::isCellFreeVertical
    (const char field[STANDART_FIELD][STANDART_FIELD], const int m, const int n) const
    {
        return field[m][n] == ShipInfo::ALIVE_SHIP || field[m + 1][n] == ShipInfo::ALIVE_SHIP ||
            field[m + 2][n] == ShipInfo::ALIVE_SHIP || field[m - 1][n - 1] == ShipInfo::ALIVE_SHIP ||
            field[m - 1][n] == ShipInfo::ALIVE_SHIP || field[m - 1][n + 1] == ShipInfo::ALIVE_SHIP ||
            field[m][n - 1] == ShipInfo::ALIVE_SHIP || field[m][n + 1] == ShipInfo::ALIVE_SHIP ||
            field[m + 1][n - 1] == ShipInfo::ALIVE_SHIP || field[m + 1][n + 1] == ShipInfo::ALIVE_SHIP ||
            field[m + 2][n - 1] == ShipInfo::ALIVE_SHIP || field[m + 2][n + 1] == ShipInfo::ALIVE_SHIP ||
            field[m + 3][n - 1] == ShipInfo::ALIVE_SHIP || field[m + 3][n] == ShipInfo::ALIVE_SHIP ||
            field[m + 3][n + 1] == ShipInfo::ALIVE_SHIP;
    }

}
