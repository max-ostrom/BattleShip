#include "SingleDeckShip.h"



SingleDeckShip::SingleDeckShip(char field[STANDART_FIELD][STANDART_FIELD])
{
    coordsX_ = shared_ptr<int>(new int[SHIP_SIZE_]);
    coordsY_ = shared_ptr<int>(new int[SHIP_SIZE_]);


    srand(time(0));



    int m = static_cast<int>(rand()) % STANDART_FIELD - SHIP_SIZE_ + 1;
    int n = static_cast<int>(rand()) % STANDART_FIELD - SHIP_SIZE_ + 1;


    while (isCellFreeHorizontal(field, m, n))
    {
        m = static_cast<int>(rand()) % STANDART_FIELD - SHIP_SIZE_ + 1;
        n = static_cast<int>(rand()) % STANDART_FIELD - SHIP_SIZE_ + 1;
    }


    field[m][n] = ShipInfo::ALIVE_SHIP;


    coordsX_.get()[0] = m;
    coordsY_.get()[0] = n;

}
const int& SingleDeckShip::getShipSize() const
{
    return SHIP_SIZE_;
}

bool SingleDeckShip::isCellFreeHorizontal
(const char field[STANDART_FIELD][STANDART_FIELD], const int m, const int n) const
{
    return field[m][n] == ShipInfo::ALIVE_SHIP || field[m][n + 1] == ShipInfo::ALIVE_SHIP ||
        field[m][n - 1] == ShipInfo::ALIVE_SHIP || field[m + 1][n] == ShipInfo::ALIVE_SHIP ||
        field[m - 1][n] == ShipInfo::ALIVE_SHIP || field[m + 1][n + 1] == ShipInfo::ALIVE_SHIP ||
        field[m + 1][n - 1] == ShipInfo::ALIVE_SHIP || field[m - 1][n + 1] == ShipInfo::ALIVE_SHIP ||
        field[m - 1][n - 1] == ShipInfo::ALIVE_SHIP;
}

bool SingleDeckShip::isCellFreeVertical
(const char field[STANDART_FIELD][STANDART_FIELD], const int m, const int n) const
{
    return field[m][n] == ShipInfo::ALIVE_SHIP || field[m][n + 1] == ShipInfo::ALIVE_SHIP ||
        field[m][n - 1] == ShipInfo::ALIVE_SHIP || field[m + 1][n] == ShipInfo::ALIVE_SHIP ||
        field[m - 1][n] == ShipInfo::ALIVE_SHIP || field[m + 1][n + 1] == ShipInfo::ALIVE_SHIP ||
        field[m + 1][n - 1] == ShipInfo::ALIVE_SHIP || field[m - 1][n + 1] == ShipInfo::ALIVE_SHIP ||
        field[m - 1][n - 1] == ShipInfo::ALIVE_SHIP;
}

