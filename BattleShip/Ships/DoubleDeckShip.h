#ifndef DoubleDeckShip_H
#define DoubleDeckShip_H

#include "SingleDeckShip.h"

class DoubleDeckShip :
	public Ship
{
public:
	DoubleDeckShip(char field[FIELDSIZE][FIELDSIZE]);
	virtual const int& getShipSize()const  override;
private:
	virtual bool isCellFreeHorizontal(const char field[FIELDSIZE][FIELDSIZE], const int m, const int n)const override;
	virtual bool isCellFreeVertical(const char field[FIELDSIZE][FIELDSIZE], const int m, const int n)const override;
	const int SHIPSIZE = 2;
};
#endif
